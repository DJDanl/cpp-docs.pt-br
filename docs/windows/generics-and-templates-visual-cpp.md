---
title: "Generics and Templates (Visual C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "generics [C++], vs. templates"
  - "templates, C++"
ms.assetid: 63adec79-b1dc-4a1a-a21d-b8a72a8fce31
caps.latest.revision: 19
caps.handback.revision: 19
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Generics and Templates (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os produtos genéricas e os modelos são ambos os recursos de idioma que fornecem suporte para tipos com parâmetros.  No entanto, eles são diferentes e usa diferentes.  Este tópico fornece uma visão geral das diferenças.  
  
 Para obter mais informações, consulte [Windows Runtime and Managed Templates](../windows/windows-runtime-and-managed-templates-cpp-component-extensions.md) e [Visão geral de modelos](../Topic/Templates%20Overview.md).  
  
## Comparando modelos e produtos genéricas  
 Principais diferenças entre modelos de produtos genéricas e C\+\+:  
  
-   Os produtos genéricas são os tipos genéricos até que sejam substituídos por eles no tempo de execução.  Os modelos são qualificados em tempo de compilação para que ainda não sejam tipos com parâmetros em tempo de execução  
  
-   Common Language Runtime suporte especificamente produtos genéricas em MSIL.  Como o tempo de execução sabe sobre produtos genéricos, os tipos específicos podem ser substituídos para tipos genéricos ao fazer referência a um assembly que contém um tipo genérico.  Os modelos, ao contrário, são resolvidas em tipos comuns em tempo de compilação e os tipos resultantes não podem ser habilidosos em outros assemblies.  
  
-   Os produtos genéricas especializados em dois assemblies diferentes com os mesmos argumentos de tipo são do mesmo tipo.  Os modelos especializados em dois assemblies diferentes com os mesmos argumentos de tipo são considerados no tempo de execução ser de tipos diferentes.  
  
-   Os produtos genéricas são gerados como uma única parte do código executável que é usado para todos os argumentos do tipo de referência \(isso não é válido para os tipos de valor, que têm uma implementação exclusivo pelo tipo de valor\).  O compilador JIT sabe sobre os produtos genéricas e pode otimizar o código para referência ou os tipos de valores que são usados como argumentos do tipo.  Os modelos gerenciem o código separado de tempo de execução para cada conhecimento.  
  
-   Os produtos genéricas não permitem parâmetros do modelo que não seja do tipo, como `template <int i> C {}`.  Os modelos permitem\-nos.  
  
-   Os produtos genéricas não permitem a especialização explícita \(ou seja, uma implementação personalizada de um modelo para um tipo específico\).  Os modelos oferecem.  
  
-   Os produtos genéricas não permitem a especialização parcial \(uma implementação personalizada para um subconjunto dos argumentos do tipo\).  Os modelos oferecem.  
  
-   Os produtos genéricas não permitem que o parâmetro de tipo é usado como a classe base para o tipo genérico.  Os modelos oferecem.  
  
-   Parâmetros de modelo modelo de suporte dos modelos \(por exemplo.  `template<template<class T> class X> class MyClass`\), mas os produtos genéricas não.  
  
## Combinando modelos e produtos genéricas  
  
-   A diferença básica em produtos genéricas tem implicações para criar aplicativos que combinam modelos e produtos genéricas.  Por exemplo, suponha que você tenha uma classe de modelo que você deseja criar um wrapper genérico para expor esse modelo a outros idiomas como um genérico.  Você não pode ter o genérico usar um parâmetro de tipo em que ele passa embora ao modelo, desde que o modelo precisa ter o parâmetro de tipo em tempo de compilação, mas o genérico não resolverá o parâmetro de tipo até o tempo de execução.  Aninhar um modelo em um genérico não funcionará porque não há como expanda em tempo de compilação os modelos para os tipos genéricos arbitrários que poderiam ser criada uma instância em tempo de execução.  
  
## Exemplo  
  
### Descrição  
 O exemplo a seguir mostra um exemplo simples de usar modelos e produtos genéricas juntos.  Neste exemplo, a classe do modelo passa o parâmetro no tipo genérico.  O contrário não é possível.  
  
 Esse idioma pode ser usado quando você quer criar na API genérico existente com o código do modelo que é local para um assembly do Visual C\+\+, ou quando precisar adicionar uma camada adicional de parametrização a um tipo genérico, para tirar proveito de determinados recursos dos modelos não suportados por produtos genéricas.  
  
### Código  
  
```  
// templates_and_generics.cpp  
// compile with: /clr  
using namespace System;  
  
generic <class ItemType>  
ref class MyGeneric {  
   ItemType m_item;  
  
public:  
   MyGeneric(ItemType item) : m_item(item) {}  
   void F() {   
      Console::WriteLine("F");   
   }  
};  
  
template <class T>  
public ref class MyRef {  
MyGeneric<T>^ ig;  
  
public:  
   MyRef(T t) {  
      ig = gcnew MyGeneric<T>(t);  
      ig->F();  
    }      
};  
  
int main() {  
   // instantiate the template  
   MyRef<int>^ mref = gcnew MyRef<int>(11);  
}  
```  
  
### Saída  
  
```  
F  
```  
  
## Consulte também  
 [Generics](../windows/generics-cpp-component-extensions.md)