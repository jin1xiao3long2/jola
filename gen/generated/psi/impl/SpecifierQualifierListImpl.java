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

public class SpecifierQualifierListImpl extends ASTWrapperPsiElement implements SpecifierQualifierList {

  public SpecifierQualifierListImpl(@NotNull ASTNode node) {
    super(node);
  }

  public void accept(@NotNull Visitor visitor) {
    visitor.visitSpecifierQualifierList(this);
  }

  @Override
  public void accept(@NotNull PsiElementVisitor visitor) {
    if (visitor instanceof Visitor) accept((Visitor)visitor);
    else super.accept(visitor);
  }

  @Override
  @Nullable
  public SpecifierQualifierList getSpecifierQualifierList() {
    return findChildByClass(SpecifierQualifierList.class);
  }

  @Override
  @Nullable
  public TypeQualifier getTypeQualifier() {
    return findChildByClass(TypeQualifier.class);
  }

  @Override
  @Nullable
  public TypeSpecifier getTypeSpecifier() {
    return findChildByClass(TypeSpecifier.class);
  }

}
