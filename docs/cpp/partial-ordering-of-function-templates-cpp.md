---
title: "Ordenação parcial de modelos de função (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords: partial ordering of function templates
ms.assetid: 0c17347d-0e80-47ad-b5ac-046462d9dc73
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: cddc0f1680a3354276a2135dd28c31a2037a8202
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="partial-ordering-of-function-templates-c"></a>Ordenação parcial de modelos de função (C++)

Vários modelos de função que correspondem à lista de argumentos de uma chamada de função podem estar disponíveis. O C++ define a ordenação parcial dos modelos de função para especificar que função deve ser chamada. A ordenação é parcial, pois pode haver alguns modelos que são considerados igualmente especializados.

O compilador escolhe a função de modelo mais especializada disponível nas correspondências possíveis. Por exemplo, se um modelo de função usa um tipo __T__e outro modelo de função levando __T\*__  estiver disponível, o __T\*__  versão diz para ser mais especializada e genérica é preferível __T__ versão sempre que o argumento for um tipo de ponteiro, embora ambos seria permitidas correspondências.

Use o seguinte processo para determinar se um candidato a modelo de função é mais especializado:

1. Considere dois modelos de função, T1 e T2.

2. Substitua os parâmetros em T1 por um tipo hipotético exclusivo X.

3. Com a lista de parâmetros em T1, veja se T2 é um modelo válido para essa lista de parâmetros. Ignore as conversões implícitas.

4. Repita o mesmo processo com T1 e T2 invertidos.

5. Se você tiver uma lista de argumentos de modelo válida para o outro modelo, mas o inverso não for verdadeiro, o modelo será considerado menos especializado que o outro modelo. Se ambos os modelos usando os anterior etapa formulário os argumentos válidos para o outro, em seguida, eles são considerados igualmente ser especializado e resultados de uma chamada ambígua quando você tentar usá-los.

6. Usando estas regras:

     1. Uma especialização de modelo para um tipo específico é mais especializada do que a que usa um argumento de tipo genérico.

     2. Um modelo de colocar somente __T\*__  é mais especializadas que fazer uma __T__, porque o tipo de um hipotético __X\*__  é um argumento válido para um __T__ argumento de modelo, mas __X__ não é um argumento válido para uma __T\*__  argumento de modelo.

     3. __Const T__ é mais especializadas que __T__, pois __X const__ é um argumento válido para uma __T__ argumento de modelo, mas __X__ não é um argumento válido para uma __const T__ argumento de modelo.

     4. __Const T\*__  é mais especializadas que __T\*__, pois __X const\*__  é um argumento válido para uma __T\*__  argumento de modelo, mas __X\*__  não é um argumento válido para uma __const T\*__  argumento de modelo.

## <a name="example"></a>Exemplo

O exemplo a seguir funciona conforme especificado no padrão:

```cpp
// partial_ordering_of_function_templates.cpp
// compile with: /EHsc
#include <iostream>

extern "C" int printf(const char*,...);
template <class T> void f(T) {
   printf_s("Less specialized function called\n");
}

template <class T> void f(T*) {
   printf_s("More specialized function called\n");
}

template <class T> void f(const T*) {
   printf_s("Even more specialized function for const T*\n");
}

int main() {
   int i =0;
   const int j = 0;
   int *pi = &i;
   const int *cpi = &j;

   f(i);   // Calls less specialized function.
   f(pi);  // Calls more specialized function.
   f(cpi); // Calls even more specialized function.
   // Without partial ordering, these calls would be ambiguous.
}
```  
  
### <a name="output"></a>Saída  
  
```  
Less specialized function called  
More specialized function called  
Even more specialized function for const T*  
```  
  
## <a name="see-also"></a>Consulte também

[Modelos de função](../cpp/function-templates.md)
