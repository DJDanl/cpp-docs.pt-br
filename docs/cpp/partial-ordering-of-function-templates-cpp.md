---
title: "Ordena&#231;&#227;o parcial de modelos de fun&#231;&#227;o (C++) | Microsoft Docs"
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
  - "ordenação parcial de modelos de função"
ms.assetid: 0c17347d-0e80-47ad-b5ac-046462d9dc73
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Ordena&#231;&#227;o parcial de modelos de fun&#231;&#227;o (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Vários modelos de função que correspondem à lista de argumentos de uma chamada de função podem estar disponíveis.  O C\+\+ define a ordenação parcial dos modelos de função para especificar que função deve ser chamada.  A ordenação é parcial, pois pode haver alguns modelos que são considerados igualmente especializados.  
  
 O compilador escolhe a função de modelo mais especializada disponível nas correspondências possíveis.  Por exemplo, se um modelo de função usa um tipo **T** e outro modelo da função que utiliza **T\*** estiver disponível, a versão **T\*** será considerada mais especializada e preferível à versão **T** genérica sempre que o argumento for um tipo de ponteiro, mesmo que elas sejam correspondências permitidas.  
  
 Use o seguinte processo para determinar se um candidato a modelo de função é mais especializado:  
  
1.  Considere dois modelos de função, T1 e T2.  
  
2.  Substitua os parâmetros em T1 por um tipo hipotético exclusivo X.  
  
3.  Com a lista de parâmetros em T1, veja se T2 é um modelo válido para essa lista de parâmetros.  Ignore as conversões implícitas.  
  
4.  Repita o mesmo processo com T1 e T2 invertidos.  
  
5.  Se você tiver uma lista de argumentos de modelo válida para o outro modelo, mas o inverso não for verdadeiro, o modelo será considerado menos especializado que o outro modelo.  Se ambos os modelos que usam a etapa anterior formarem argumentos válidos para eles, eles serão considerados igualmente especializados, e uma chamada ambígua ocorrerá ao tentar usá\-los.  
  
6.  Usando estas regras:  
  
    1.  Uma especialização de modelo para um tipo específico é mais especializada do que a que usa um argumento de tipo genérico.  
  
    2.  Um modelo que usa apenas **T\*** é mais especializado que um que só usa **T**, pois um tipo hipotético **X\*** é um argumento válido para um argumento de modelo **T**, mas **X** não é um argumento válido para um argumento de modelo **T\***.  
  
    3.  **const T** é mais especializado que **T**, porque **const X** é um argumento válido para um argumento de modelo **T**, mas **X** não é um argumento válido para um argumento de modelo **const T**.  
  
    4.  **const T\*** é mais especializado que **T\***, porque **const X\*** é um argumento válido para um argumento de modelo **T\***, mas **X\*** não é um argumento válido para um argumento de modelo **const T\***.  
  
7.  O exemplo a seguir funciona no Visual C\+\+ .NET 2003 conforme especificado no padrão:  
  
```  
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
  
### Saída  
  
```  
Less specialized function called  
More specialized function called  
Even more specialized function for const T*  
```  
  
## Consulte também  
 [Modelos de função](../cpp/function-templates.md)