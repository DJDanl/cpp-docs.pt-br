---
title: "Explicit Overrides  (C++ Component Extensions) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "overriding, override [C++]"
ms.assetid: 4ec3eaf5-163b-4df8-8f16-7a2ec04c3d0f
caps.latest.revision: 21
caps.handback.revision: 19
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Explicit Overrides  (C++ Component Extensions)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico discute como substituir explicitamente um membro de uma classe base ou de uma interface.  Uma substituição \(explícita\) nomeados só deve ser usada para substituir um método com um método derivada que tem um nome diferente.  
  
## Todos os Tempos de Execução  
 **Sintaxe**  
  
```  
  
        overriding-function-declarator = type::function [,type::function] { overriding-function-definition }  
overriding-function-declarator = function { overriding-function-definition }  
```  
  
 **Parâmetros**  
  
 *overriding\-function\-declarator*  
 O tipo de retorno, o nome, e a lista de argumentos da função substituindo.  Observe que a função substituindo não tem que ter o mesmo nome que a função que está sendo substituída.  
  
 *type*  
 O tipo de base que contém uma função para substituir.  
  
 *function*  
 Uma lista delimitada por vírgulas de um ou mais nomes de função a ser substituído.  
  
 *overriding\-function\-definition*  
 As instruções do corpo da função que definem a função substituindo.  
  
 **Comentários**  
  
 Substituições explícitas de uso para criar um alias para uma assinatura de método, ou para fornecer implementações diferentes para métodos com a mesma assinatura.  
  
 Para obter informações sobre como alterar o comportamento de tipos e herdados de membros herdados do tipo, consulte [Especificadores de Substituição](../windows/override-specifiers-cpp-component-extensions.md).  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## [!INCLUDE[clr_for_headings](../dotnet/includes/clr_for_headings_md.md)]  
 **Comentários**  
  
 Para obter informações sobre as substituições explícitas em código nativo ou no código compilado com **\/clr:oldSyntax**, consulte [Substituições Explícitas](../cpp/explicit-overrides-cpp.md).  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplos  
 **Exemplo**  
  
 O exemplo de código a seguir mostra uma substituição e uma implementação simples, implícitas de um membro em uma interface de base, não usando substituições explícitas.  
  
```  
// explicit_override_1.cpp  
// compile with: /clr  
interface struct I1 {  
   virtual void f();  
};  
  
ref class X : public I1 {  
public:  
   virtual void f() {  
      System::Console::WriteLine("X::f override of I1::f");  
   }  
};  
  
int main() {  
   I1 ^ MyI = gcnew X;  
   MyI -> f();  
}  
```  
  
 **Saída**  
  
  **X::f override of I1::f** **Exemplo**  
  
 O exemplo de código a seguir mostra como implementar todos os membros da interface com uma assinatura comum, usando a sintaxe explícita de substituição.  
  
```  
  
// explicit_override_2.cpp  
// compile with: /clr  
interface struct I1 {  
   virtual void f();  
};  
  
interface struct I2 {  
   virtual void f();  
};  
  
ref struct X : public I1, I2 {  
   virtual void f() = I1::f, I2::f {  
      System::Console::WriteLine("X::f override of I1::f and I2::f");  
   }  
};  
  
int main() {  
   I1 ^ MyI = gcnew X;  
   I2 ^ MyI2 = gcnew X;  
   MyI -> f();  
   MyI2 -> f();  
}  
```  
  
 **Saída**  
  
  **Substituição de X::f de I1::f e de I2::f**  
 **Substituição de X::f de I1::f e de I2::f** **Exemplo**  
  
 O exemplo de código a seguir mostra como uma substituição da função pode ter um nome diferente de função que está implementando.  
  
```  
// explicit_override_3.cpp  
// compile with: /clr  
interface struct I1 {  
   virtual void f();  
};  
  
ref class X : public I1 {  
public:  
   virtual void g() = I1::f {  
      System::Console::WriteLine("X::g");  
   }  
};  
  
int main() {  
   I1 ^ a = gcnew X;  
   a->f();  
}  
```  
  
 **Saída**  
  
  **X::g** **Exemplo**  
  
 O exemplo de código seguinte mostra uma implementação explícita da interface que implementa uma coleção do tipo seguro.  
  
```  
// explicit_override_4.cpp  
// compile with: /clr /LD  
using namespace System;  
ref class R : ICloneable {  
   int X;  
  
   virtual Object^ C() sealed = ICloneable::Clone {  
      return this->Clone();  
   }  
  
public:  
   R() : X(0) {}  
   R(int x) : X(x) {}  
  
   virtual R^ Clone() {  
      R^ r = gcnew R;  
      r->X = this->X;  
      return r;  
   }  
};  
```  
  
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)