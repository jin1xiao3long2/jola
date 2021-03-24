// This is a generated file. Not intended for manual editing.
package generated.psi.impl;

import java.util.List;
import org.jetbrains.annotations.*;
import com.intellij.lang.ASTNode;
import com.intellij.psi.PsiElement;
import com.intellij.psi.PsiElementVisitor;
import com.intellij.psi.util.PsiTreeUtil;
import static generated.GeneratedTypes.*;
import com.intellij.extapi.psi.ASTWrapperPsiElement;
import generated.psi.*;

public class DirectAbstractDeclaratorImpl extends ASTWrapperPsiElement implements DirectAbstractDeclarator {

  public DirectAbstractDeclaratorImpl(@NotNull ASTNode node) {
    super(node);
  }

  public void accept(@NotNull Visitor visitor) {
    visitor.visitDirectAbstractDeclarator(this);
  }

  @Override
  public void accept(@NotNull PsiElementVisitor visitor) {
    if (visitor instanceof Visitor) accept((Visitor)visitor);
    else super.accept(visitor);
  }

  @Override
  @Nullable
  public AbstractDeclarator getAbstractDeclarator() {
    return findChildByClass(AbstractDeclarator.class);
  }

  @Override
  @Nullable
  public ConstantExpression getConstantExpression() {
    return findChildByClass(ConstantExpression.class);
  }

  @Override
  @Nullable
  public DirectAbstractDeclarator getDirectAbstractDeclarator() {
    return findChildByClass(DirectAbstractDeclarator.class);
  }

  @Override
  @Nullable
  public ParameterTypeList getParameterTypeList() {
    return findChildByClass(ParameterTypeList.class);
  }

}
