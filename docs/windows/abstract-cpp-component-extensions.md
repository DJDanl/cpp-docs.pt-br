---
title: "abstract  (C++ Component Extensions) | Microsoft Docs"
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
  - "abstract"
  - "abstract_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "abstract keyword [C++]"
ms.assetid: cbae3408-0378-4ac8-b70d-c016b381a6d5
caps.latest.revision: 21
caps.handback.revision: 21
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# abstract  (C++ Component Extensions)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O `abstract` palavra\-chave declara um:  
  
-   Um tipo pode ser usado como um tipo base, mas o próprio tipo não pode ser instanciado.  
  
-   Uma função de membro de tipo pode ser definida apenas em um tipo derivado.  
  
## Todas as Plataformas  
 **Sintaxe**  
  
```  
  
class-declaration class-identifier abstract {}  
virtual return-type member-function-identifier() abstract ;  
  
```  
  
 **Observações**  
  
 A primeira sintaxe de exemplo declara uma classe abstrata.  O *declaração de classe* componente pode ser uma declaração C\+\+ nativa \(`class` ou `struct`\), ou uma declaração de extensão do C\+\+ \(`ref class` ou `ref struct`\) se o **\/ZW** ou **\/clr** for especificada a opção de compilador.  
  
 A segunda sintaxe de exemplo declara uma função membro virtual fosse abstrato.  Declarando um resumo da função é o mesmo que declarar uma função virtual pura.  Declarando um resumo da função de membro também faz com que a classe delimitadora deve ser declarado abstrato.  
  
 O `abstract` palavra\-chave é suportada em código nativo e específicos da plataforma; ou seja, ele pode ser compilado com ou sem o **\/ZW** ou **\/clr** opção de compilador.  
  
 Você pode detectar no tempo de compilação se um tipo é abstrato com o `__is_abstract(``type``)` característica de tipo.  Para obter mais informações, consulte [Compiler Support for Type Traits](../windows/compiler-support-for-type-traits-cpp-component-extensions.md).  
  
 O `abstract` palavra\-chave é um especificador de substituição contextual.  Para obter mais informações sobre palavras\-chave contextuais, consulte [Palavras\-chave Contextuais](../windows/context-sensitive-keywords-cpp-component-extensions.md).  Para obter mais informações sobre especificadores de substituição, consulte [como: declarar especificadores de substituição em compilações nativas](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md).  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
 Para obter mais informações, consulte [classes e estruturas Ref](http://msdn.microsoft.com/library/windows/apps/hh699870.aspx).  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## [!INCLUDE[clr_for_headings](../dotnet/includes/clr_for_headings_md.md)]  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplos  
 **Exemplo**  
  
 O exemplo de código a seguir gera um erro porque classe `X` está marcado como `abstract`.  
  
```  
// abstract_keyword.cpp  
// compile with: /clr  
ref class X abstract {  
public:  
   virtual void f() {}  
};  
  
int main() {  
   X ^ MyX = gcnew X;   // C3622  
}  
```  
  
 **Exemplo**  
  
 O exemplo de código a seguir gera um erro porque ele instancia uma classe nativa que está marcado como `abstract`.  Este erro ocorrerá com ou sem o **\/clr** opção de compilador.  
  
```  
// abstract_keyword_2.cpp  
class X abstract {  
public:  
   virtual void f() {}  
};  
  
int main() {  
   X * MyX = new X; // C3622: 'X': a class declared as 'abstract'  
                    // cannot be instantiated. See declaration of 'X'}  
  
```  
  
 **Exemplo**  
  
 O exemplo de código a seguir gera um erro porque função `f` inclui uma definição, mas está marcado como `abstract`.  A instrução final no exemplo mostra que declarar uma função virtual abstract equivale ao declarar uma função virtual pura.  
  
```  
// abstract_keyword_3.cpp  
// compile with: /clr  
ref class X {  
public:  
   virtual void f() abstract {}   // C3634  
   virtual void g() = 0 {}   // C3634  
};  
```  
  
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)