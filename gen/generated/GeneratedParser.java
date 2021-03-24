// This is a generated file. Not intended for manual editing.
package generated;

import com.intellij.lang.PsiBuilder;
import com.intellij.lang.PsiBuilder.Marker;
import static generated.GeneratedTypes.*;
import static com.intellij.lang.parser.GeneratedParserUtilBase.*;
import com.intellij.psi.tree.IElementType;
import com.intellij.lang.ASTNode;
import com.intellij.psi.tree.TokenSet;
import com.intellij.lang.PsiParser;
import com.intellij.lang.LightPsiParser;

@SuppressWarnings({"SimplifiableIfStatement", "UnusedAssignment"})
public class GeneratedParser implements PsiParser, LightPsiParser {

  public ASTNode parse(IElementType t, PsiBuilder b) {
    parseLight(t, b);
    return b.getTreeBuilt();
  }

  public void parseLight(IElementType t, PsiBuilder b) {
    boolean r;
    b = adapt_builder_(t, b, this, null);
    Marker m = enter_section_(b, 0, _COLLAPSE_, null);
    r = parse_root_(t, b);
    exit_section_(b, 0, m, t, r, true, TRUE_CONDITION);
  }

  protected boolean parse_root_(IElementType t, PsiBuilder b) {
    return parse_root_(t, b, 0);
  }

  static boolean parse_root_(IElementType t, PsiBuilder b, int l) {
    return program(b, l + 1);
  }

  /* ********************************************************** */
  // pointer
  //                       | direct_abstract_declarator
  //                       | pointer direct_abstract_declarator
  public static boolean abstract_declarator(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "abstract_declarator")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, ABSTRACT_DECLARATOR, "<abstract declarator>");
    r = pointer(b, l + 1);
    if (!r) r = direct_abstract_declarator(b, l + 1);
    if (!r) r = abstract_declarator_2(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // pointer direct_abstract_declarator
  private static boolean abstract_declarator_2(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "abstract_declarator_2")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = pointer(b, l + 1);
    r = r && direct_abstract_declarator(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // multiplicative_expression
  //                       | additive_expression '+' multiplicative_expression
  //                       | additive_expression '-' multiplicative_expression
  public static boolean additive_expression(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "additive_expression")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, ADDITIVE_EXPRESSION, "<additive expression>");
    r = multiplicative_expression(b, l + 1);
    if (!r) r = additive_expression_1(b, l + 1);
    if (!r) r = additive_expression_2(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // additive_expression '+' multiplicative_expression
  private static boolean additive_expression_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "additive_expression_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = additive_expression(b, l + 1);
    r = r && consumeToken(b, "+");
    r = r && multiplicative_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  // additive_expression '-' multiplicative_expression
  private static boolean additive_expression_2(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "additive_expression_2")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = additive_expression(b, l + 1);
    r = r && consumeToken(b, "-");
    r = r && multiplicative_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // equality_expression
  //                  | and_expression '&' equality_expression
  public static boolean and_expression(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "and_expression")) return false;
    if (!nextTokenIs(b, RELATION_EXPRESSION)) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = equality_expression(b, l + 1);
    if (!r) r = and_expression_1(b, l + 1);
    exit_section_(b, m, AND_EXPRESSION, r);
    return r;
  }

  // and_expression '&' equality_expression
  private static boolean and_expression_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "and_expression_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = and_expression(b, l + 1);
    r = r && consumeToken(b, "&");
    r = r && equality_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // assignment_expression
  //                            | argument_expression_list ',' assignment_expression
  public static boolean argument_expression_list(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "argument_expression_list")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, ARGUMENT_EXPRESSION_LIST, "<argument expression list>");
    r = assignment_expression(b, l + 1);
    if (!r) r = argument_expression_list_1(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // argument_expression_list ',' assignment_expression
  private static boolean argument_expression_list_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "argument_expression_list_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = argument_expression_list(b, l + 1);
    r = r && consumeToken(b, ",");
    r = r && assignment_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // conditional_expression
  //                         | unaray_expression assignment_operator assignment_expression
  public static boolean assignment_expression(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "assignment_expression")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, ASSIGNMENT_EXPRESSION, "<assignment expression>");
    r = conditional_expression(b, l + 1);
    if (!r) r = assignment_expression_1(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // unaray_expression assignment_operator assignment_expression
  private static boolean assignment_expression_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "assignment_expression_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, UNARAY_EXPRESSION);
    r = r && assignment_operator(b, l + 1);
    r = r && assignment_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // '='
  //                       | MUL_ASSIGN
  //                       | DIV_ASSIGN
  //                       | MOD_ASSIGN
  //                       | ADD_ASSIGN
  //                       | SUB_ASSIGN
  //                       | LEFT_ASSIGN
  //                       | RIGHT_ASSIGN
  //                       | AND_ASSIGN
  //                       | XOR_ASSIGN
  //                       | OR_ASSIGN
  public static boolean assignment_operator(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "assignment_operator")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, ASSIGNMENT_OPERATOR, "<assignment operator>");
    r = consumeToken(b, "=");
    if (!r) r = consumeToken(b, MUL_ASSIGN);
    if (!r) r = consumeToken(b, DIV_ASSIGN);
    if (!r) r = consumeToken(b, MOD_ASSIGN);
    if (!r) r = consumeToken(b, ADD_ASSIGN);
    if (!r) r = consumeToken(b, SUB_ASSIGN);
    if (!r) r = consumeToken(b, LEFT_ASSIGN);
    if (!r) r = consumeToken(b, RIGHT_ASSIGN);
    if (!r) r = consumeToken(b, AND_ASSIGN);
    if (!r) r = consumeToken(b, XOR_ASSIGN);
    if (!r) r = consumeToken(b, OR_ASSIGN);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  /* ********************************************************** */
  // unary_expression
  //                   | '(' type_name ')' cast_expression
  public static boolean cast_expression(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "cast_expression")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, CAST_EXPRESSION, "<cast expression>");
    r = unary_expression(b, l + 1);
    if (!r) r = cast_expression_1(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // '(' type_name ')' cast_expression
  private static boolean cast_expression_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "cast_expression_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, "(");
    r = r && type_name(b, l + 1);
    r = r && consumeToken(b, ")");
    r = r && cast_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // '{' '}'
  //                      | '{' statement_list '}'
  //                      | '{' declaration_list statement_list '}'
  public static boolean compound_statement(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "compound_statement")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, COMPOUND_STATEMENT, "<compound statement>");
    r = compound_statement_0(b, l + 1);
    if (!r) r = compound_statement_1(b, l + 1);
    if (!r) r = compound_statement_2(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // '{' '}'
  private static boolean compound_statement_0(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "compound_statement_0")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, "{");
    r = r && consumeToken(b, "}");
    exit_section_(b, m, null, r);
    return r;
  }

  // '{' statement_list '}'
  private static boolean compound_statement_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "compound_statement_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, "{");
    r = r && statement_list(b, l + 1);
    r = r && consumeToken(b, "}");
    exit_section_(b, m, null, r);
    return r;
  }

  // '{' declaration_list statement_list '}'
  private static boolean compound_statement_2(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "compound_statement_2")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, "{");
    r = r && declaration_list(b, l + 1);
    r = r && statement_list(b, l + 1);
    r = r && consumeToken(b, "}");
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // logical_or_expression
  //                          | logical_or_expression '?' expression ':' conditional_expression
  public static boolean conditional_expression(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "conditional_expression")) return false;
    if (!nextTokenIs(b, "<conditional expression>", INCLUDESIVE_OR_EXPRESSION, RELATION_EXPRESSION)) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, CONDITIONAL_EXPRESSION, "<conditional expression>");
    r = logical_or_expression(b, l + 1);
    if (!r) r = conditional_expression_1(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // logical_or_expression '?' expression ':' conditional_expression
  private static boolean conditional_expression_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "conditional_expression_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = logical_or_expression(b, l + 1);
    r = r && consumeToken(b, "?");
    r = r && expression(b, l + 1);
    r = r && consumeToken(b, ":");
    r = r && conditional_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // conditional_expression
  public static boolean constant_expression(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "constant_expression")) return false;
    if (!nextTokenIs(b, "<constant expression>", INCLUDESIVE_OR_EXPRESSION, RELATION_EXPRESSION)) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, CONSTANT_EXPRESSION, "<constant expression>");
    r = conditional_expression(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  /* ********************************************************** */
  // init_declarator
  //               | init_declarator_list ',' init_declarator
  public static boolean declaration(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "declaration")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, DECLARATION, "<declaration>");
    r = init_declarator(b, l + 1);
    if (!r) r = declaration_1(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // init_declarator_list ',' init_declarator
  private static boolean declaration_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "declaration_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, INIT_DECLARATOR_LIST);
    r = r && consumeToken(b, ",");
    r = r && init_declarator(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // declaration
  //                    | declaration_list declaration
  public static boolean declaration_list(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "declaration_list")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, DECLARATION_LIST, "<declaration list>");
    r = declaration(b, l + 1);
    if (!r) r = declaration_list_1(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // declaration_list declaration
  private static boolean declaration_list_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "declaration_list_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = declaration_list(b, l + 1);
    r = r && declaration(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // pointer direct_declarator
  //              | direct_declarator
  public static boolean declarator(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "declarator")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, DECLARATOR, "<declarator>");
    r = declarator_0(b, l + 1);
    if (!r) r = direct_declarator(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // pointer direct_declarator
  private static boolean declarator_0(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "declarator_0")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = pointer(b, l + 1);
    r = r && direct_declarator(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // '(' abstract_declarator ')'
  //                              | '[' ']'
  //                              | '[' constant_expression ']'
  //                              | direct_abstract_declarator '[' ']'
  //                              | direct_abstract_declarator '[' constant_expression ']'
  //                              | '(' ')'
  //                              | '(' parameter_type_list ')'
  //                              | direct_abstract_declarator '(' ')'
  //                              | direct_abstract_declarator '(' parameter_type_list ')'
  public static boolean direct_abstract_declarator(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "direct_abstract_declarator")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, DIRECT_ABSTRACT_DECLARATOR, "<direct abstract declarator>");
    r = direct_abstract_declarator_0(b, l + 1);
    if (!r) r = direct_abstract_declarator_1(b, l + 1);
    if (!r) r = direct_abstract_declarator_2(b, l + 1);
    if (!r) r = direct_abstract_declarator_3(b, l + 1);
    if (!r) r = direct_abstract_declarator_4(b, l + 1);
    if (!r) r = direct_abstract_declarator_5(b, l + 1);
    if (!r) r = direct_abstract_declarator_6(b, l + 1);
    if (!r) r = direct_abstract_declarator_7(b, l + 1);
    if (!r) r = direct_abstract_declarator_8(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // '(' abstract_declarator ')'
  private static boolean direct_abstract_declarator_0(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "direct_abstract_declarator_0")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, "(");
    r = r && abstract_declarator(b, l + 1);
    r = r && consumeToken(b, ")");
    exit_section_(b, m, null, r);
    return r;
  }

  // '[' ']'
  private static boolean direct_abstract_declarator_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "direct_abstract_declarator_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, "[");
    r = r && consumeToken(b, "]");
    exit_section_(b, m, null, r);
    return r;
  }

  // '[' constant_expression ']'
  private static boolean direct_abstract_declarator_2(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "direct_abstract_declarator_2")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, "[");
    r = r && constant_expression(b, l + 1);
    r = r && consumeToken(b, "]");
    exit_section_(b, m, null, r);
    return r;
  }

  // direct_abstract_declarator '[' ']'
  private static boolean direct_abstract_declarator_3(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "direct_abstract_declarator_3")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = direct_abstract_declarator(b, l + 1);
    r = r && consumeToken(b, "[");
    r = r && consumeToken(b, "]");
    exit_section_(b, m, null, r);
    return r;
  }

  // direct_abstract_declarator '[' constant_expression ']'
  private static boolean direct_abstract_declarator_4(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "direct_abstract_declarator_4")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = direct_abstract_declarator(b, l + 1);
    r = r && consumeToken(b, "[");
    r = r && constant_expression(b, l + 1);
    r = r && consumeToken(b, "]");
    exit_section_(b, m, null, r);
    return r;
  }

  // '(' ')'
  private static boolean direct_abstract_declarator_5(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "direct_abstract_declarator_5")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, "(");
    r = r && consumeToken(b, ")");
    exit_section_(b, m, null, r);
    return r;
  }

  // '(' parameter_type_list ')'
  private static boolean direct_abstract_declarator_6(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "direct_abstract_declarator_6")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, "(");
    r = r && parameter_type_list(b, l + 1);
    r = r && consumeToken(b, ")");
    exit_section_(b, m, null, r);
    return r;
  }

  // direct_abstract_declarator '(' ')'
  private static boolean direct_abstract_declarator_7(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "direct_abstract_declarator_7")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = direct_abstract_declarator(b, l + 1);
    r = r && consumeToken(b, "(");
    r = r && consumeToken(b, ")");
    exit_section_(b, m, null, r);
    return r;
  }

  // direct_abstract_declarator '(' parameter_type_list ')'
  private static boolean direct_abstract_declarator_8(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "direct_abstract_declarator_8")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = direct_abstract_declarator(b, l + 1);
    r = r && consumeToken(b, "(");
    r = r && parameter_type_list(b, l + 1);
    r = r && consumeToken(b, ")");
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // identifier
  //                     | direct_declarator '[' ']'
  //                     | direct_declarator '[' constant_expression ']'
  //                     | identifier '(' parameter_list ')'
  //                     | identifier '(' ')'
  //                     | direct_declarator ',' identifier_list
  public static boolean direct_declarator(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "direct_declarator")) return false;
    if (!nextTokenIs(b, IDENTIFIER)) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, IDENTIFIER);
    if (!r) r = direct_declarator_1(b, l + 1);
    if (!r) r = direct_declarator_2(b, l + 1);
    if (!r) r = direct_declarator_3(b, l + 1);
    if (!r) r = direct_declarator_4(b, l + 1);
    if (!r) r = direct_declarator_5(b, l + 1);
    exit_section_(b, m, DIRECT_DECLARATOR, r);
    return r;
  }

  // direct_declarator '[' ']'
  private static boolean direct_declarator_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "direct_declarator_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = direct_declarator(b, l + 1);
    r = r && consumeToken(b, "[");
    r = r && consumeToken(b, "]");
    exit_section_(b, m, null, r);
    return r;
  }

  // direct_declarator '[' constant_expression ']'
  private static boolean direct_declarator_2(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "direct_declarator_2")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = direct_declarator(b, l + 1);
    r = r && consumeToken(b, "[");
    r = r && constant_expression(b, l + 1);
    r = r && consumeToken(b, "]");
    exit_section_(b, m, null, r);
    return r;
  }

  // identifier '(' parameter_list ')'
  private static boolean direct_declarator_3(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "direct_declarator_3")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, IDENTIFIER);
    r = r && consumeToken(b, "(");
    r = r && parameter_list(b, l + 1);
    r = r && consumeToken(b, ")");
    exit_section_(b, m, null, r);
    return r;
  }

  // identifier '(' ')'
  private static boolean direct_declarator_4(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "direct_declarator_4")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, IDENTIFIER);
    r = r && consumeToken(b, "(");
    r = r && consumeToken(b, ")");
    exit_section_(b, m, null, r);
    return r;
  }

  // direct_declarator ',' identifier_list
  private static boolean direct_declarator_5(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "direct_declarator_5")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = direct_declarator(b, l + 1);
    r = r && consumeToken(b, ",");
    r = r && identifier_list(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // ENUM '{' enumerator_list '}'
  //                 | ENUM identifier '{' enumerator_list '}'
  //                 | ENUM identifier
  public static boolean enum_epecifer(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "enum_epecifer")) return false;
    if (!nextTokenIs(b, ENUM)) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = enum_epecifer_0(b, l + 1);
    if (!r) r = enum_epecifer_1(b, l + 1);
    if (!r) r = parseTokens(b, 0, ENUM, IDENTIFIER);
    exit_section_(b, m, ENUM_EPECIFER, r);
    return r;
  }

  // ENUM '{' enumerator_list '}'
  private static boolean enum_epecifer_0(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "enum_epecifer_0")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, ENUM);
    r = r && consumeToken(b, "{");
    r = r && enumerator_list(b, l + 1);
    r = r && consumeToken(b, "}");
    exit_section_(b, m, null, r);
    return r;
  }

  // ENUM identifier '{' enumerator_list '}'
  private static boolean enum_epecifer_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "enum_epecifer_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeTokens(b, 0, ENUM, IDENTIFIER);
    r = r && consumeToken(b, "{");
    r = r && enumerator_list(b, l + 1);
    r = r && consumeToken(b, "}");
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // identifier
  //              | identifier '=' constant_expression
  public static boolean enumerator(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "enumerator")) return false;
    if (!nextTokenIs(b, IDENTIFIER)) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, IDENTIFIER);
    if (!r) r = enumerator_1(b, l + 1);
    exit_section_(b, m, ENUMERATOR, r);
    return r;
  }

  // identifier '=' constant_expression
  private static boolean enumerator_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "enumerator_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, IDENTIFIER);
    r = r && consumeToken(b, "=");
    r = r && constant_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // enumerator
  //                   | enumerator_list ',' enumberator
  public static boolean enumerator_list(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "enumerator_list")) return false;
    if (!nextTokenIs(b, IDENTIFIER)) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = enumerator(b, l + 1);
    if (!r) r = enumerator_list_1(b, l + 1);
    exit_section_(b, m, ENUMERATOR_LIST, r);
    return r;
  }

  // enumerator_list ',' enumberator
  private static boolean enumerator_list_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "enumerator_list_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = enumerator_list(b, l + 1);
    r = r && consumeToken(b, ",");
    r = r && consumeToken(b, ENUMBERATOR);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // relation_expression
  //                       | equality_expression EQ_OP relational_expression
  //                       | equality_expression NE_OP relational_expression
  public static boolean equality_expression(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "equality_expression")) return false;
    if (!nextTokenIs(b, RELATION_EXPRESSION)) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, RELATION_EXPRESSION);
    if (!r) r = equality_expression_1(b, l + 1);
    if (!r) r = equality_expression_2(b, l + 1);
    exit_section_(b, m, EQUALITY_EXPRESSION, r);
    return r;
  }

  // equality_expression EQ_OP relational_expression
  private static boolean equality_expression_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "equality_expression_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = equality_expression(b, l + 1);
    r = r && consumeToken(b, EQ_OP);
    r = r && relational_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  // equality_expression NE_OP relational_expression
  private static boolean equality_expression_2(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "equality_expression_2")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = equality_expression(b, l + 1);
    r = r && consumeToken(b, NE_OP);
    r = r && relational_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // and_expression
  //                           | exclusive_or_expression '^' and_exexpression
  public static boolean exclusive_or_expression(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "exclusive_or_expression")) return false;
    if (!nextTokenIs(b, RELATION_EXPRESSION)) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = and_expression(b, l + 1);
    if (!r) r = exclusive_or_expression_1(b, l + 1);
    exit_section_(b, m, EXCLUSIVE_OR_EXPRESSION, r);
    return r;
  }

  // exclusive_or_expression '^' and_exexpression
  private static boolean exclusive_or_expression_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "exclusive_or_expression_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = exclusive_or_expression(b, l + 1);
    r = r && consumeToken(b, "^");
    r = r && consumeToken(b, AND_EXEXPRESSION);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // assignment_expression
  //              | expression ',' assignment_expression
  public static boolean expression(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "expression")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, EXPRESSION, "<expression>");
    r = assignment_expression(b, l + 1);
    if (!r) r = expression_1(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // expression ',' assignment_expression
  private static boolean expression_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "expression_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = expression(b, l + 1);
    r = r && consumeToken(b, ",");
    r = r && assignment_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // ';'
  //                        | expression ';'
  public static boolean expression_statement(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "expression_statement")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, EXPRESSION_STATEMENT, "<expression statement>");
    r = consumeToken(b, ";");
    if (!r) r = expression_statement_1(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // expression ';'
  private static boolean expression_statement_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "expression_statement_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = expression(b, l + 1);
    r = r && consumeToken(b, ";");
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // function_definition
  //                        | declaration
  public static boolean external_declaration(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "external_declaration")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, EXTERNAL_DECLARATION, "<external declaration>");
    r = function_definition(b, l + 1);
    if (!r) r = declaration(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  /* ********************************************************** */
  // type_specifier declarator compound_statement
  public static boolean function_definition(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "function_definition")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, FUNCTION_DEFINITION, "<function definition>");
    r = type_specifier(b, l + 1);
    r = r && declarator(b, l + 1);
    r = r && compound_statement(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  /* ********************************************************** */
  // identifier
  //                   | identifier_list ',' identifier
  public static boolean identifier_list(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "identifier_list")) return false;
    if (!nextTokenIs(b, IDENTIFIER)) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, IDENTIFIER);
    if (!r) r = identifier_list_1(b, l + 1);
    exit_section_(b, m, IDENTIFIER_LIST, r);
    return r;
  }

  // identifier_list ',' identifier
  private static boolean identifier_list_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "identifier_list_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = identifier_list(b, l + 1);
    r = r && consumeToken(b, ",");
    r = r && consumeToken(b, IDENTIFIER);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // exclusive_or_expression
  //                              | includesive_or_expression '|' exclusive_or_expression
  public static boolean inclusive_or_expression(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "inclusive_or_expression")) return false;
    if (!nextTokenIs(b, "<inclusive or expression>", INCLUDESIVE_OR_EXPRESSION, RELATION_EXPRESSION)) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, INCLUSIVE_OR_EXPRESSION, "<inclusive or expression>");
    r = exclusive_or_expression(b, l + 1);
    if (!r) r = inclusive_or_expression_1(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // includesive_or_expression '|' exclusive_or_expression
  private static boolean inclusive_or_expression_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "inclusive_or_expression_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, INCLUDESIVE_OR_EXPRESSION);
    r = r && consumeToken(b, "|");
    r = r && exclusive_or_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // declarator
  //                   | declarator '=' initializer
  public static boolean init_declarator(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "init_declarator")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, INIT_DECLARATOR, "<init declarator>");
    r = declarator(b, l + 1);
    if (!r) r = init_declarator_1(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // declarator '=' initializer
  private static boolean init_declarator_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "init_declarator_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = declarator(b, l + 1);
    r = r && consumeToken(b, "=");
    r = r && initializer(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // assignment_expression
  //               | '{' initializer_list '}'
  //               | '{' initializer_list ',' '}'
  public static boolean initializer(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "initializer")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, INITIALIZER, "<initializer>");
    r = assignment_expression(b, l + 1);
    if (!r) r = initializer_1(b, l + 1);
    if (!r) r = initializer_2(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // '{' initializer_list '}'
  private static boolean initializer_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "initializer_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, "{");
    r = r && initializer_list(b, l + 1);
    r = r && consumeToken(b, "}");
    exit_section_(b, m, null, r);
    return r;
  }

  // '{' initializer_list ',' '}'
  private static boolean initializer_2(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "initializer_2")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, "{");
    r = r && initializer_list(b, l + 1);
    r = r && consumeToken(b, ",");
    r = r && consumeToken(b, "}");
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // initializer
  //                    | initializer_list ',' initializer
  public static boolean initializer_list(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "initializer_list")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, INITIALIZER_LIST, "<initializer list>");
    r = initializer(b, l + 1);
    if (!r) r = initializer_list_1(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // initializer_list ',' initializer
  private static boolean initializer_list_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "initializer_list_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = initializer_list(b, l + 1);
    r = r && consumeToken(b, ",");
    r = r && initializer(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // WHILE '(' expression ')' statement
  //                       | FOR '(' expression_statement expression_statement ')' statement
  //                       | FOR '(' expression_statement expression_statement expression ')' statement
  public static boolean iteration_statement(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "iteration_statement")) return false;
    if (!nextTokenIs(b, "<iteration statement>", FOR, WHILE)) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, ITERATION_STATEMENT, "<iteration statement>");
    r = iteration_statement_0(b, l + 1);
    if (!r) r = iteration_statement_1(b, l + 1);
    if (!r) r = iteration_statement_2(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // WHILE '(' expression ')' statement
  private static boolean iteration_statement_0(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "iteration_statement_0")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, WHILE);
    r = r && consumeToken(b, "(");
    r = r && expression(b, l + 1);
    r = r && consumeToken(b, ")");
    r = r && statement(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  // FOR '(' expression_statement expression_statement ')' statement
  private static boolean iteration_statement_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "iteration_statement_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, FOR);
    r = r && consumeToken(b, "(");
    r = r && expression_statement(b, l + 1);
    r = r && expression_statement(b, l + 1);
    r = r && consumeToken(b, ")");
    r = r && statement(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  // FOR '(' expression_statement expression_statement expression ')' statement
  private static boolean iteration_statement_2(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "iteration_statement_2")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, FOR);
    r = r && consumeToken(b, "(");
    r = r && expression_statement(b, l + 1);
    r = r && expression_statement(b, l + 1);
    r = r && expression(b, l + 1);
    r = r && consumeToken(b, ")");
    r = r && statement(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // CONTINUE ';'
  //                  | BREAK ';'
  //                  | RETURN ';'
  //                  | RETURN expression ';'
  public static boolean jump_statement(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "jump_statement")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, JUMP_STATEMENT, "<jump statement>");
    r = jump_statement_0(b, l + 1);
    if (!r) r = jump_statement_1(b, l + 1);
    if (!r) r = jump_statement_2(b, l + 1);
    if (!r) r = jump_statement_3(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // CONTINUE ';'
  private static boolean jump_statement_0(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "jump_statement_0")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, CONTINUE);
    r = r && consumeToken(b, ";");
    exit_section_(b, m, null, r);
    return r;
  }

  // BREAK ';'
  private static boolean jump_statement_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "jump_statement_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, BREAK);
    r = r && consumeToken(b, ";");
    exit_section_(b, m, null, r);
    return r;
  }

  // RETURN ';'
  private static boolean jump_statement_2(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "jump_statement_2")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, RETURN);
    r = r && consumeToken(b, ";");
    exit_section_(b, m, null, r);
    return r;
  }

  // RETURN expression ';'
  private static boolean jump_statement_3(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "jump_statement_3")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, RETURN);
    r = r && expression(b, l + 1);
    r = r && consumeToken(b, ";");
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // identifier ':' statement
  //                     | CASE constant_expression ':' statement
  //                     | DEFAULT ':' statement
  public static boolean labeled_statement(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "labeled_statement")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, LABELED_STATEMENT, "<labeled statement>");
    r = labeled_statement_0(b, l + 1);
    if (!r) r = labeled_statement_1(b, l + 1);
    if (!r) r = labeled_statement_2(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // identifier ':' statement
  private static boolean labeled_statement_0(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "labeled_statement_0")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, IDENTIFIER);
    r = r && consumeToken(b, ":");
    r = r && statement(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  // CASE constant_expression ':' statement
  private static boolean labeled_statement_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "labeled_statement_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, CASE);
    r = r && constant_expression(b, l + 1);
    r = r && consumeToken(b, ":");
    r = r && statement(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  // DEFAULT ':' statement
  private static boolean labeled_statement_2(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "labeled_statement_2")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, DEFAULT);
    r = r && consumeToken(b, ":");
    r = r && statement(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // inclusive_or_expression
  //                          | logical_and_expression AND_OP inclusive_or_expression
  public static boolean logical_and_expression(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "logical_and_expression")) return false;
    if (!nextTokenIs(b, "<logical and expression>", INCLUDESIVE_OR_EXPRESSION, RELATION_EXPRESSION)) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, LOGICAL_AND_EXPRESSION, "<logical and expression>");
    r = inclusive_or_expression(b, l + 1);
    if (!r) r = logical_and_expression_1(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // logical_and_expression AND_OP inclusive_or_expression
  private static boolean logical_and_expression_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "logical_and_expression_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = logical_and_expression(b, l + 1);
    r = r && consumeToken(b, AND_OP);
    r = r && inclusive_or_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // logical_and_expression
  //                         | logical_or_expression OR_OP logical_and_expression
  public static boolean logical_or_expression(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "logical_or_expression")) return false;
    if (!nextTokenIs(b, "<logical or expression>", INCLUDESIVE_OR_EXPRESSION, RELATION_EXPRESSION)) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, LOGICAL_OR_EXPRESSION, "<logical or expression>");
    r = logical_and_expression(b, l + 1);
    if (!r) r = logical_or_expression_1(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // logical_or_expression OR_OP logical_and_expression
  private static boolean logical_or_expression_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "logical_or_expression_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = logical_or_expression(b, l + 1);
    r = r && consumeToken(b, OR_OP);
    r = r && logical_and_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // cast_expression
  //                             | multiplicative_expression '*' cast_expression
  //                             | multiplicative_expression '/' cast_expression
  //                             | multiplicative_expression '%' cast_expression
  public static boolean multiplicative_expression(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "multiplicative_expression")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, MULTIPLICATIVE_EXPRESSION, "<multiplicative expression>");
    r = cast_expression(b, l + 1);
    if (!r) r = multiplicative_expression_1(b, l + 1);
    if (!r) r = multiplicative_expression_2(b, l + 1);
    if (!r) r = multiplicative_expression_3(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // multiplicative_expression '*' cast_expression
  private static boolean multiplicative_expression_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "multiplicative_expression_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = multiplicative_expression(b, l + 1);
    r = r && consumeToken(b, "*");
    r = r && cast_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  // multiplicative_expression '/' cast_expression
  private static boolean multiplicative_expression_2(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "multiplicative_expression_2")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = multiplicative_expression(b, l + 1);
    r = r && consumeToken(b, "/");
    r = r && cast_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  // multiplicative_expression '%' cast_expression
  private static boolean multiplicative_expression_3(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "multiplicative_expression_3")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = multiplicative_expression(b, l + 1);
    r = r && consumeToken(b, "%");
    r = r && cast_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // declaration_specifier identifier
  public static boolean parameter_declaration(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "parameter_declaration")) return false;
    if (!nextTokenIs(b, DECLARATION_SPECIFIER)) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeTokens(b, 0, DECLARATION_SPECIFIER, IDENTIFIER);
    exit_section_(b, m, PARAMETER_DECLARATION, r);
    return r;
  }

  /* ********************************************************** */
  // parameter_declaration
  //                  | parameter_list ',' parameter_declaration
  public static boolean parameter_list(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "parameter_list")) return false;
    if (!nextTokenIs(b, DECLARATION_SPECIFIER)) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = parameter_declaration(b, l + 1);
    if (!r) r = parameter_list_1(b, l + 1);
    exit_section_(b, m, PARAMETER_LIST, r);
    return r;
  }

  // parameter_list ',' parameter_declaration
  private static boolean parameter_list_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "parameter_list_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = parameter_list(b, l + 1);
    r = r && consumeToken(b, ",");
    r = r && parameter_declaration(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // parameter_list
  //                       | parameter_list ',' ELLIPSIS
  public static boolean parameter_type_list(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "parameter_type_list")) return false;
    if (!nextTokenIs(b, DECLARATION_SPECIFIER)) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = parameter_list(b, l + 1);
    if (!r) r = parameter_type_list_1(b, l + 1);
    exit_section_(b, m, PARAMETER_TYPE_LIST, r);
    return r;
  }

  // parameter_list ',' ELLIPSIS
  private static boolean parameter_type_list_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "parameter_type_list_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = parameter_list(b, l + 1);
    r = r && consumeToken(b, ",");
    r = r && consumeToken(b, ELLIPSIS);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // '*'
  //           | '*' pointer
  public static boolean pointer(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "pointer")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, POINTER, "<pointer>");
    r = consumeToken(b, "*");
    if (!r) r = pointer_1(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // '*' pointer
  private static boolean pointer_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "pointer_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, "*");
    r = r && pointer(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // primary_expression
  //                      | postfix_expression '[' expression ']'
  //                      | postfix_expression '(' ')'
  //                      | postfix_expression '(' argument_expression_list ')'
  //                      | postfix_expression '.' identifier
  //                      | postfix_expression PTR_OP identifier
  //                      | postfix_expression INC_OP
  //                      | postfix_expression DEC_OP
  public static boolean postfix_expression(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "postfix_expression")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, POSTFIX_EXPRESSION, "<postfix expression>");
    r = primary_expression(b, l + 1);
    if (!r) r = postfix_expression_1(b, l + 1);
    if (!r) r = postfix_expression_2(b, l + 1);
    if (!r) r = postfix_expression_3(b, l + 1);
    if (!r) r = postfix_expression_4(b, l + 1);
    if (!r) r = postfix_expression_5(b, l + 1);
    if (!r) r = postfix_expression_6(b, l + 1);
    if (!r) r = postfix_expression_7(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // postfix_expression '[' expression ']'
  private static boolean postfix_expression_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "postfix_expression_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = postfix_expression(b, l + 1);
    r = r && consumeToken(b, "[");
    r = r && expression(b, l + 1);
    r = r && consumeToken(b, "]");
    exit_section_(b, m, null, r);
    return r;
  }

  // postfix_expression '(' ')'
  private static boolean postfix_expression_2(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "postfix_expression_2")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = postfix_expression(b, l + 1);
    r = r && consumeToken(b, "(");
    r = r && consumeToken(b, ")");
    exit_section_(b, m, null, r);
    return r;
  }

  // postfix_expression '(' argument_expression_list ')'
  private static boolean postfix_expression_3(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "postfix_expression_3")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = postfix_expression(b, l + 1);
    r = r && consumeToken(b, "(");
    r = r && argument_expression_list(b, l + 1);
    r = r && consumeToken(b, ")");
    exit_section_(b, m, null, r);
    return r;
  }

  // postfix_expression '.' identifier
  private static boolean postfix_expression_4(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "postfix_expression_4")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = postfix_expression(b, l + 1);
    r = r && consumeToken(b, ".");
    r = r && consumeToken(b, IDENTIFIER);
    exit_section_(b, m, null, r);
    return r;
  }

  // postfix_expression PTR_OP identifier
  private static boolean postfix_expression_5(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "postfix_expression_5")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = postfix_expression(b, l + 1);
    r = r && consumeTokens(b, 0, PTR_OP, IDENTIFIER);
    exit_section_(b, m, null, r);
    return r;
  }

  // postfix_expression INC_OP
  private static boolean postfix_expression_6(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "postfix_expression_6")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = postfix_expression(b, l + 1);
    r = r && consumeToken(b, INC_OP);
    exit_section_(b, m, null, r);
    return r;
  }

  // postfix_expression DEC_OP
  private static boolean postfix_expression_7(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "postfix_expression_7")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = postfix_expression(b, l + 1);
    r = r && consumeToken(b, DEC_OP);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // identifier
  //                      | CONSTANT
  //                      | STRING_LITERAL
  //                      | '(' expression ')'
  public static boolean primary_expression(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "primary_expression")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, PRIMARY_EXPRESSION, "<primary expression>");
    r = consumeToken(b, IDENTIFIER);
    if (!r) r = consumeToken(b, CONSTANT);
    if (!r) r = consumeToken(b, STRING_LITERAL);
    if (!r) r = primary_expression_3(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // '(' expression ')'
  private static boolean primary_expression_3(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "primary_expression_3")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, "(");
    r = r && expression(b, l + 1);
    r = r && consumeToken(b, ")");
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // external_declaration
  //           | program external_declaration
  static boolean program(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "program")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = external_declaration(b, l + 1);
    if (!r) r = program_1(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  // program external_declaration
  private static boolean program_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "program_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = program(b, l + 1);
    r = r && external_declaration(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // shift_expression
  //                         | relational_expression '<' shift_expression
  //                         | relational_expression '>' shift_expression
  //                         | relational_expression LE_OP shift_expression
  //                         | relational_expression GE_OP shift_expression
  public static boolean relational_expression(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "relational_expression")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, RELATIONAL_EXPRESSION, "<relational expression>");
    r = shift_expression(b, l + 1);
    if (!r) r = relational_expression_1(b, l + 1);
    if (!r) r = relational_expression_2(b, l + 1);
    if (!r) r = relational_expression_3(b, l + 1);
    if (!r) r = relational_expression_4(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // relational_expression '<' shift_expression
  private static boolean relational_expression_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "relational_expression_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = relational_expression(b, l + 1);
    r = r && consumeToken(b, "<");
    r = r && shift_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  // relational_expression '>' shift_expression
  private static boolean relational_expression_2(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "relational_expression_2")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = relational_expression(b, l + 1);
    r = r && consumeToken(b, ">");
    r = r && shift_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  // relational_expression LE_OP shift_expression
  private static boolean relational_expression_3(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "relational_expression_3")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = relational_expression(b, l + 1);
    r = r && consumeToken(b, LE_OP);
    r = r && shift_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  // relational_expression GE_OP shift_expression
  private static boolean relational_expression_4(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "relational_expression_4")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = relational_expression(b, l + 1);
    r = r && consumeToken(b, GE_OP);
    r = r && shift_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // IF '(' expression ')' statement
  //                       | IF '(' expression ')' statement ELSE statement
  public static boolean selection_statement(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "selection_statement")) return false;
    if (!nextTokenIs(b, IF)) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = selection_statement_0(b, l + 1);
    if (!r) r = selection_statement_1(b, l + 1);
    exit_section_(b, m, SELECTION_STATEMENT, r);
    return r;
  }

  // IF '(' expression ')' statement
  private static boolean selection_statement_0(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "selection_statement_0")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, IF);
    r = r && consumeToken(b, "(");
    r = r && expression(b, l + 1);
    r = r && consumeToken(b, ")");
    r = r && statement(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  // IF '(' expression ')' statement ELSE statement
  private static boolean selection_statement_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "selection_statement_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, IF);
    r = r && consumeToken(b, "(");
    r = r && expression(b, l + 1);
    r = r && consumeToken(b, ")");
    r = r && statement(b, l + 1);
    r = r && consumeToken(b, ELSE);
    r = r && statement(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // additive_expression
  //                    | shift_expression LEFT_OP additive_expression
  //                    | shift_expression RIGHT_OP additive_expression
  public static boolean shift_expression(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "shift_expression")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, SHIFT_EXPRESSION, "<shift expression>");
    r = additive_expression(b, l + 1);
    if (!r) r = shift_expression_1(b, l + 1);
    if (!r) r = shift_expression_2(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // shift_expression LEFT_OP additive_expression
  private static boolean shift_expression_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "shift_expression_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = shift_expression(b, l + 1);
    r = r && consumeToken(b, LEFT_OP);
    r = r && additive_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  // shift_expression RIGHT_OP additive_expression
  private static boolean shift_expression_2(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "shift_expression_2")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = shift_expression(b, l + 1);
    r = r && consumeToken(b, RIGHT_OP);
    r = r && additive_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // type_specifier specifier_qualifier_list
  //                            | type_specifier
  //                            | type_qualifier specifier_qualifier_list
  //                            | type_qualifier
  public static boolean specifier_qualifier_list(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "specifier_qualifier_list")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, SPECIFIER_QUALIFIER_LIST, "<specifier qualifier list>");
    r = specifier_qualifier_list_0(b, l + 1);
    if (!r) r = type_specifier(b, l + 1);
    if (!r) r = specifier_qualifier_list_2(b, l + 1);
    if (!r) r = type_qualifier(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // type_specifier specifier_qualifier_list
  private static boolean specifier_qualifier_list_0(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "specifier_qualifier_list_0")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = type_specifier(b, l + 1);
    r = r && specifier_qualifier_list(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  // type_qualifier specifier_qualifier_list
  private static boolean specifier_qualifier_list_2(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "specifier_qualifier_list_2")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = type_qualifier(b, l + 1);
    r = r && specifier_qualifier_list(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // compound_statement
  //             | expression_statement
  //             | selection_statement
  //             | iteration_statement
  //             | jump_statement
  public static boolean statement(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "statement")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, STATEMENT, "<statement>");
    r = compound_statement(b, l + 1);
    if (!r) r = expression_statement(b, l + 1);
    if (!r) r = selection_statement(b, l + 1);
    if (!r) r = iteration_statement(b, l + 1);
    if (!r) r = jump_statement(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  /* ********************************************************** */
  // statement
  //                  | statement_list statement
  public static boolean statement_list(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "statement_list")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, STATEMENT_LIST, "<statement list>");
    r = statement(b, l + 1);
    if (!r) r = statement_list_1(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // statement_list statement
  private static boolean statement_list_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "statement_list_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = statement_list(b, l + 1);
    r = r && statement(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // TYPEDEF
  //                           | EXTERN
  //                           | STATIC
  //                           | AUTO
  //                           | REGISTER
  public static boolean storage_class_specifier(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "storage_class_specifier")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, STORAGE_CLASS_SPECIFIER, "<storage class specifier>");
    r = consumeToken(b, TYPEDEF);
    if (!r) r = consumeToken(b, EXTERN);
    if (!r) r = consumeToken(b, STATIC);
    if (!r) r = consumeToken(b, AUTO);
    if (!r) r = consumeToken(b, REGISTER);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  /* ********************************************************** */
  // specifier_qualifier_list struct_declarator_list ','
  public static boolean struct_declaration(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "struct_declaration")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, STRUCT_DECLARATION, "<struct declaration>");
    r = specifier_qualifier_list(b, l + 1);
    r = r && struct_declarator_list(b, l + 1);
    r = r && consumeToken(b, ",");
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  /* ********************************************************** */
  // struct_declaration
  //                           | struct_declaration_list struct_declaration
  public static boolean struct_declaration_list(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "struct_declaration_list")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, STRUCT_DECLARATION_LIST, "<struct declaration list>");
    r = struct_declaration(b, l + 1);
    if (!r) r = struct_declaration_list_1(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // struct_declaration_list struct_declaration
  private static boolean struct_declaration_list_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "struct_declaration_list_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = struct_declaration_list(b, l + 1);
    r = r && struct_declaration(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // declarator
  //                     | ':' constant_expression
  //                     | declarator ':' constant_expression
  public static boolean struct_declarator(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "struct_declarator")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, STRUCT_DECLARATOR, "<struct declarator>");
    r = declarator(b, l + 1);
    if (!r) r = struct_declarator_1(b, l + 1);
    if (!r) r = struct_declarator_2(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // ':' constant_expression
  private static boolean struct_declarator_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "struct_declarator_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, ":");
    r = r && constant_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  // declarator ':' constant_expression
  private static boolean struct_declarator_2(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "struct_declarator_2")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = declarator(b, l + 1);
    r = r && consumeToken(b, ":");
    r = r && constant_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // struct_declarator
  //                          | struct_declarator_list ',' struct_declarator
  public static boolean struct_declarator_list(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "struct_declarator_list")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, STRUCT_DECLARATOR_LIST, "<struct declarator list>");
    r = struct_declarator(b, l + 1);
    if (!r) r = struct_declarator_list_1(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // struct_declarator_list ',' struct_declarator
  private static boolean struct_declarator_list_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "struct_declarator_list_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = struct_declarator_list(b, l + 1);
    r = r && consumeToken(b, ",");
    r = r && struct_declarator(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // STRUCT
  //                   | UNION
  public static boolean struct_or_union(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "struct_or_union")) return false;
    if (!nextTokenIs(b, "<struct or union>", STRUCT, UNION)) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, STRUCT_OR_UNION, "<struct or union>");
    r = consumeToken(b, STRUCT);
    if (!r) r = consumeToken(b, UNION);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  /* ********************************************************** */
  // struct_or_union identifier '{' struct_declaration_list '}'
  //                             | struct_or_union '{' struct_declaration_list '}'
  //                             | struct_or_union identifier
  public static boolean struct_or_union_specifier(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "struct_or_union_specifier")) return false;
    if (!nextTokenIs(b, "<struct or union specifier>", STRUCT, UNION)) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, STRUCT_OR_UNION_SPECIFIER, "<struct or union specifier>");
    r = struct_or_union_specifier_0(b, l + 1);
    if (!r) r = struct_or_union_specifier_1(b, l + 1);
    if (!r) r = struct_or_union_specifier_2(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // struct_or_union identifier '{' struct_declaration_list '}'
  private static boolean struct_or_union_specifier_0(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "struct_or_union_specifier_0")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = struct_or_union(b, l + 1);
    r = r && consumeToken(b, IDENTIFIER);
    r = r && consumeToken(b, "{");
    r = r && struct_declaration_list(b, l + 1);
    r = r && consumeToken(b, "}");
    exit_section_(b, m, null, r);
    return r;
  }

  // struct_or_union '{' struct_declaration_list '}'
  private static boolean struct_or_union_specifier_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "struct_or_union_specifier_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = struct_or_union(b, l + 1);
    r = r && consumeToken(b, "{");
    r = r && struct_declaration_list(b, l + 1);
    r = r && consumeToken(b, "}");
    exit_section_(b, m, null, r);
    return r;
  }

  // struct_or_union identifier
  private static boolean struct_or_union_specifier_2(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "struct_or_union_specifier_2")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = struct_or_union(b, l + 1);
    r = r && consumeToken(b, IDENTIFIER);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // specifier_qualifier_list
  //             | specifier_qualifier_list abstract_declarator
  public static boolean type_name(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "type_name")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, TYPE_NAME, "<type name>");
    r = specifier_qualifier_list(b, l + 1);
    if (!r) r = type_name_1(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // specifier_qualifier_list abstract_declarator
  private static boolean type_name_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "type_name_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = specifier_qualifier_list(b, l + 1);
    r = r && abstract_declarator(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // CONST
  //                  | VOLATILE
  public static boolean type_qualifier(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "type_qualifier")) return false;
    if (!nextTokenIs(b, "<type qualifier>", CONST, VOLATILE)) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, TYPE_QUALIFIER, "<type qualifier>");
    r = consumeToken(b, CONST);
    if (!r) r = consumeToken(b, VOLATILE);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  /* ********************************************************** */
  // type_qualifier
  //                       | type_qualifier_list type_qualifier
  public static boolean type_qualifier_list(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "type_qualifier_list")) return false;
    if (!nextTokenIs(b, "<type qualifier list>", CONST, VOLATILE)) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, TYPE_QUALIFIER_LIST, "<type qualifier list>");
    r = type_qualifier(b, l + 1);
    if (!r) r = type_qualifier_list_1(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // type_qualifier_list type_qualifier
  private static boolean type_qualifier_list_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "type_qualifier_list_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = type_qualifier_list(b, l + 1);
    r = r && type_qualifier(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // VOID
  //                  | CHAR
  //                  | INT
  //                  | FLOAT
  public static boolean type_specifier(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "type_specifier")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, TYPE_SPECIFIER, "<type specifier>");
    r = consumeToken(b, VOID);
    if (!r) r = consumeToken(b, CHAR);
    if (!r) r = consumeToken(b, INT);
    if (!r) r = consumeToken(b, FLOAT);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  /* ********************************************************** */
  // postfix_expression
  //                    | INC_OP unary_expression
  //                    | DEC_OP unary_expression
  //                    | unary_operator cast_expression
  //                    | SIZEOF unary_expression
  //                    | SIZEOF '(' type_name ')'
  public static boolean unary_expression(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "unary_expression")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, UNARY_EXPRESSION, "<unary expression>");
    r = postfix_expression(b, l + 1);
    if (!r) r = unary_expression_1(b, l + 1);
    if (!r) r = unary_expression_2(b, l + 1);
    if (!r) r = unary_expression_3(b, l + 1);
    if (!r) r = unary_expression_4(b, l + 1);
    if (!r) r = unary_expression_5(b, l + 1);
    exit_section_(b, l, m, r, false, null);
    return r;
  }

  // INC_OP unary_expression
  private static boolean unary_expression_1(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "unary_expression_1")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, INC_OP);
    r = r && unary_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  // DEC_OP unary_expression
  private static boolean unary_expression_2(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "unary_expression_2")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, DEC_OP);
    r = r && unary_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  // unary_operator cast_expression
  private static boolean unary_expression_3(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "unary_expression_3")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, UNARY_OPERATOR);
    r = r && cast_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  // SIZEOF unary_expression
  private static boolean unary_expression_4(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "unary_expression_4")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, SIZEOF);
    r = r && unary_expression(b, l + 1);
    exit_section_(b, m, null, r);
    return r;
  }

  // SIZEOF '(' type_name ')'
  private static boolean unary_expression_5(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "unary_expression_5")) return false;
    boolean r;
    Marker m = enter_section_(b);
    r = consumeToken(b, SIZEOF);
    r = r && consumeToken(b, "(");
    r = r && type_name(b, l + 1);
    r = r && consumeToken(b, ")");
    exit_section_(b, m, null, r);
    return r;
  }

  /* ********************************************************** */
  // '&'
  //                 | '*'
  //                 | '+'
  //                 | '-'
  //                 | '~'
  //                 | '!'
  public static boolean unary_oprator(PsiBuilder b, int l) {
    if (!recursion_guard_(b, l, "unary_oprator")) return false;
    boolean r;
    Marker m = enter_section_(b, l, _NONE_, UNARY_OPRATOR, "<unary oprator>");
    r = consumeToken(b, "&");
    if (!r) r = consumeToken(b, "*");
    if (!r) r = consumeToken(b, "+");
    if (!r) r = consumeToken(b, "-");
    if (!r) r = consumeToken(b, "~");
    if (!r) r = consumeToken(b, "!");
    exit_section_(b, l, m, r, false, null);
    return r;
  }

}
