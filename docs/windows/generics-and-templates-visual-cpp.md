---
title: Genéricos e modelos (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- generics [C++], vs. templates
- templates, C++
ms.assetid: 63adec79-b1dc-4a1a-a21d-b8a72a8fce31
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5d6dc0a64c5d225f6e80a21dc008e5a2486ad3d9
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="generics-and-templates-visual-c"></a>Genéricos e modelos (Visual C++)
Genéricos e modelos são ambos os recursos de linguagem que oferecem suporte para tipos parametrizados. No entanto, eles são diferentes e têm usos diferentes. Este tópico fornece uma visão geral das diferenças de muitos.  
  
 Para obter mais informações, consulte [Windows Runtime e modelos gerenciados](../windows/windows-runtime-and-managed-templates-cpp-component-extensions.md).  
  
## <a name="comparing-templates-and-generics"></a>Comparando modelos e genéricos  
 Principais diferenças entre genéricos e modelos do C++:  
  
-   Genéricos são genéricos até que os tipos são substituídos por eles no tempo de execução. Modelos são especializados em tempo de compilação para que eles não são tipos ainda com parâmetros em tempo de execução  
  
-   O common language runtime especificamente dá suporte a genéricos em MSIL. Como o tempo de execução sabe sobre genéricos, tipos específicos podem ser substituídos por tipos genéricos ao fazer referência a um assembly que contém um tipo genérico. Modelos, por outro lado, resolver em tipos comuns em tempo de compilação e os tipos de resultantes não podem ser especializados em outros assemblies.  
  
-   Genéricos especializada em dois assemblies diferentes com o mesmo tipo argumentos são do mesmo tipo. Modelos especializada em dois assemblies diferentes com o mesmo tipo argumentos são considerados pelo tempo de execução diferentes tipos.  
  
-   Genéricos são gerados como um único elemento de código executável que é usado para todos os argumentos de tipo de referência (isso não é verdade para tipos de valor, que tem uma implementação exclusiva por tipo de valor). O compilador JIT sabe sobre genéricos e é capaz de otimizar o código para os tipos de referência ou valor que são usados como argumentos de tipo. Modelos de geram código de tempo de execução separado para cada especialização.  
  
-   Genéricos não permitem que parâmetros de modelo sem tipo, como `template <int i> C {}`. Os modelos permitem a eles.  
  
-   Genéricos não permitem a especialização explícita (ou seja, uma implementação personalizada de um modelo para um tipo específico). Modelos do.  
  
-   Genéricos não permitem especialização parcial (uma implementação personalizada para um subconjunto dos argumentos de tipo). Modelos do.  
  
-   Classes genéricas não permitem que o parâmetro de tipo a ser usado como a classe base para o tipo genérico. Modelos do.  
  
-   Modelos oferecem suporte a parâmetros de modelo de modelo (por exemplo, `template<template<class T> class X> class MyClass`), mas não genéricos.  
  
## <a name="combining-templates-and-generics"></a>Genéricos e modelos de combinação  
  
-   A diferença básica em genéricos tem implicações para a criação de aplicativos que combinam modelos e genéricos. Por exemplo, suponha que você tem uma classe de modelo que você deseja criar um wrapper genérico para expor esse modelo para outros idiomas como um genérico. Você não pode ter o genérico têm um parâmetro de tipo, em seguida, passar por modelo, desde que o modelo deve ter esse parâmetro de tipo em tempo de compilação, mas genérica não resolver o parâmetro de tipo até que o tempo de execução. Aninhar um modelo dentro de um genérico não funcionará porque não é possível expandir os modelos em tempo de compilação para tipos genéricos arbitrários que pode ser instanciada em tempo de execução.  
  
## <a name="example"></a>Exemplo  
  
### <a name="description"></a>Descrição  
 O exemplo a seguir mostra um exemplo simples de usar modelos e genéricos juntos. Neste exemplo, a classe de modelo passa seu parâmetro por meio de tipo genérico. O inverso não é possível.  
  
 Esse idioma pode ser usado quando você deseja criar em uma API genérica existente com o código de modelo que é local para um assembly do Visual C++, ou quando você precisa adicionar uma camada extra de parametrização para um tipo genérico, para aproveitar a determinados recursos de modelos não supporte d por genéricos.  
  
### <a name="code"></a>Código  
  
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
  
### <a name="output"></a>Saída  
  
```  
F  
```  
  
## <a name="see-also"></a>Consulte também  
 [Genéricos](../windows/generics-cpp-component-extensions.md)