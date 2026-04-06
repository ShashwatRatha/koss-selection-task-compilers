#include "lexer.h"
#include "parser.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

// default constructor for AST node
static ASTNode *astInit(void) {
  ASTNode *node = malloc(sizeof(ASTNode));

  node->type = NODE_NULL;
  node->ival = 0;
  node->left = node->right = NULL;
  node->name = NULL;
  node->stmts = NULL;
  node->stmt_count = 0;
  node->op = NULL_TYPE;

  return node;
}

// number node
ASTNode *astNum(int val) {
  ASTNode *node = astInit();

  node->type = NODE_NUM;
  node->ival = val;

  return node;
}

// variable node
ASTNode *astVar(const char *name) {
  ASTNode *node = astInit();

  node->type = NODE_VAR;
  node->name = strdup(name);

  return node;
}

// binary operation node
ASTNode *astBinOp(TokenType tp, ASTNode *left, ASTNode *right) {
  ASTNode *node = astInit();

  node->type = NODE_BINOP;
  node->op = tp;
  node->left = left;
  node->right = right;

  return node;
}

// unary operation node
ASTNode *astUnary(TokenType op, ASTNode *operand) {
  ASTNode *node = astInit();

  node->type = NODE_UNARY;
  node->op = op;
  node->left = operand;

  return node;
}

// pre-increment opearator node
ASTNode *astPreIncr(ASTNode *operand) {
  ASTNode *node = astInit();

  node->type = NODE_PRE_INC;
  node->left = operand;

  return node;
}

// pre-decrement operator node
ASTNode *astPreDecr(ASTNode *operand) {
  ASTNode *node = astInit();

  node->type = NODE_PRE_DEC;
  node->left = operand;

  return node;
}

// post-increment operator node
ASTNode *astPostIncr(ASTNode *operand) {
  ASTNode *node = astInit();

  node->type = NODE_POST_INC;
  node->left = operand;

  return node;
}

// post-decrement operator node
ASTNode *astPostDecr(ASTNode *operand) {
  ASTNode *node = astInit();

  node->type = NODE_POST_DEC;
  node->left = operand;

  return node;
}

// assignment statement node
ASTNode *astAssgn(TokenType op, const char *name, ASTNode *operand) {
  ASTNode *node = astInit();

  node->type = NODE_ASSIGN;
  node->name = strdup(name);
  node->op = op;
  node->right = operand;

  return node;
}

// node for show keyword
ASTNode *astShow(void) {
  ASTNode *node = astInit();

  node->type = NODE_SHOW;

  return node;
}

// expression node
ASTNode *astExprStmt(ASTNode *expr) {
  ASTNode *node = astInit();

  node->type = NODE_EXPR_STMT;
  node->left = expr;

  return node;
}

// complete program node
ASTNode *astProgram(ASTNode **stmts, size_t count) {
  ASTNode *node = astInit();

  node->type = NODE_PROGRAM;
  node->stmts = stmts;
  node->stmt_count = count;

  return node;
}

// free helper
void astFree(ASTNode *node) {
  if (!node)
    return;

  if (node->name)
    free(node->name);

  if (node->stmts) {
    for (size_t i = 0; i < node->stmt_count; i++) {
      astFree(node->stmts[i]);
    }
    free(node->stmts);
  }

  astFree(node->left);
  astFree(node->right);

  free(node);
}
