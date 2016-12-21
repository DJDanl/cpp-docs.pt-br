---
title: "sealed  (C++ Component Extensions) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "sealed_cpp"
  - "sealed"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "sealed keyword [C++]"
ms.assetid: 3d0d688a-41aa-45f5-a25a-65c44206521e
caps.latest.revision: 26
caps.handback.revision: 24
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# sealed  (C++ Component Extensions)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

`sealed` é uma palavra contextual para classes ref que indica que um membro virtual não pode ser substituído ou que um tipo não pode ser usado como um tipo base.  
  
> [!NOTE]
>  A ISO C \+ \+ 11 linguagem padrão tem o [final](../cpp/final-specifier.md) palavra\-chave, que tem suporte no Visual Studio.  Use `final` em classes padrão, e `sealed` em classes ref.  
  
## Todos os Tempos de Execução  
 **Sintaxe**  
  
```  
  
ref class identifier sealed {...};  
virtual return-type identifier() sealed {...};  
  
```  
  
 **Parâmetros**  
  
 *Identificador*  
 O nome da função ou classe.  
  
 *tipo de retorno*  
 O tipo retornado por uma função.  
  
 **Observações**  
  
 No primeiro exemplo de sintaxe, uma classe é fechada.  No segundo exemplo, uma função virtual está lacrada.  
  
 O `sealed` palavra\-chave é válido para destinos nativos e também para o [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] e o common language runtime \(CLR\).  Para obter mais informações, consulte [especificadores de substituição e compilações nativas](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md).  
  
 Você pode detectar no tempo de compilação se um tipo é lacrado usando o `__is_sealed (``type``)` característica de tipo.  Para obter mais informações, consulte [Compiler Support for Type Traits](../windows/compiler-support-for-type-traits-cpp-component-extensions.md).  
  
 `sealed` é uma palavra\-chave contextual.  Para obter mais informações, consulte [Palavras\-chave Contextuais](../windows/context-sensitive-keywords-cpp-component-extensions.md).  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
 Consulte [classes e estruturas Ref](http://msdn.microsoft.com/library/windows/apps/hh699870.aspx).  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## Common Language Runtime  
 \(Não há nenhum comentários para esse recurso de linguagem que se aplicam a apenas o common language runtime.\)  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplos  
 Este exemplo de código a seguir mostra o efeito de `sealed` em um membro virtual.  
  
```cpp  
// sealed_keyword.cpp  
// compile with: /clr  
interface struct I1 {  
   virtual void f();  
   virtual void g();  
};  
  
ref class X : I1 {  
public:  
   virtual void f() {  
      System::Console::WriteLine("X::f override of I1::f");  
   }  
  
   virtual void g() sealed {  
      System::Console::WriteLine("X::f override of I1::g");  
   }  
};  
  
ref class Y : public X {  
public:  
   virtual void f() override {  
      System::Console::WriteLine("Y::f override of I1::f");  
   }  
  
   /*  
   // the following override generates a compiler error  
   virtual void g() override {  
      System::Console::WriteLine("Y::g override of I1::g");  
   }    
   */  
};  
  
int main() {  
   I1 ^ MyI = gcnew X;  
   MyI -> f();  
   MyI -> g();  
  
   I1 ^ MyI2 = gcnew Y;  
   MyI2 -> f();  
}  
```  
  
 **Saída**  
  
  **Substituição de X::f de I1::f**  
 **Substituição de X::f de I1::g**  
 **Substituição de Y::f de I1::f** O exemplo de código a seguir mostra como marcar uma classe como sealed.  
  
```cpp  
// sealed_keyword_2.cpp  
// compile with: /clr  
interface struct I1 {  
   virtual void f();  
};  
  
ref class X sealed : I1 {  
public:  
   virtual void f() override {}  
};  
  
ref class Y : public X {   // C3246 base class X is sealed  
public:  
   virtual void f() override {}  
};  
```  
  
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)