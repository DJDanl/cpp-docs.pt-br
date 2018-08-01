---
title: Especialização explícita de modelos de função | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- overriding, functions
- function templates, specialization
- explicit specialization of function templates
- declaring functions [C++], specialization of function template
- specialization of function templates
ms.assetid: eb0fcb73-eaed-42a1-9b83-14b055a34bf8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d8b6a56a0a1dce5d07007898dec486d0e3b080c4
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39407683"
---
# <a name="explicit-specialization-of-function-templates"></a>Especialização explícita de modelos de função
Com um modelo de função, você pode definir o comportamento especial para um tipo específico fornecendo uma especialização explícita (substituição) do modelo da função para esse tipo. Por exemplo:  
  
```cpp
template<> void MySwap(double a, double b);  
```  
  
 Esta declaração permite que você defina uma função diferente para **duplas** variáveis. Assim como as funções de não template, conversões de tipo padrão (como a promoção de uma variável do tipo **float** à **duplo**) são aplicadas.  
  
## <a name="example"></a>Exemplo  
  
```cpp
// explicit_specialization.cpp  
template<class T> void f(T t)  
{  
};  
  
// Explicit specialization of f with 'char' with the  
// template argument explicitly specified:  
//  
template<> void f<char>(char c)  
{  
}  
  
// Explicit specialization of f with 'double' with the  
// template argument deduced:  
//  
template<> void f(double d)  
{  
}  
int main()  
{  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de função](../cpp/function-templates.md)