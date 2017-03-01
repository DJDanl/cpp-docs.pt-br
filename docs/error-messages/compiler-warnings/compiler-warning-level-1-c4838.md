---
title: "Compilador aviso (nível 1) C4838 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4838
dev_langs:
- C++
helpviewer_keywords:
- C4838
ms.assetid: fea07924-5feb-4ed4-99b5-1a8c41d28db6
caps.latest.revision: 4
author: corob-msft
ms.author: corob
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 227af1840fe5aee63545e35456fe09749f00de1d
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4838"></a>Compilador C4838 de aviso (nível 1)
conversão de 'type_1' em 'type_2' requer uma conversão de restrição  
  
 Uma conversão implícita de restrição foi encontrada ao usar a inicialização de agregação ou uma lista.  
  
 A linguagem C permite conversões de estreitamento implícitas na inicialização e atribuições e C++ segue o naipe, embora narrowing inesperada é uma causa de muitos erros de código. Para tornar o código mais seguro, o C++ padrão exige que uma mensagem de diagnóstico quando ocorre uma conversão de restrição em uma lista de inicialização. No Visual C++, o diagnóstico é [C2397 de erro do compilador](../../error-messages/compiler-errors-1/compiler-error-c2397.md) ao usar a sintaxe de inicialização uniforme com suporte a partir do Visual Studio 2015. O compilador gera o aviso C4838 ao usar a sintaxe de inicialização de agregação com suporte pelo Visual Studio 2013 ou lista.  
  
 Uma conversão de restrição pode ser okey quando você conhece que o possível intervalo de valores convertidos pode se ajustar no destino. Nesse caso, você sabe mais do que o compilador faz. Se você fizer uma conversão de restrição intencionalmente, fazer suas intenções explícita usando uma conversão estática. Caso contrário, essa mensagem de aviso quase sempre indica que você tem um bug no código. Você pode corrigi-lo, assegurando-se de que os objetos que você inicializar têm tipos que são grandes o suficiente para lidar com as entradas.  
  
 O exemplo a seguir gera C4838 e mostra uma maneira de corrigir:  
  
```  
// C4838.cpp -- C++ narrowing conversion diagnostics  
// Compile by using: cl /EHsc C4838.cpp  
  
struct S1 {  
    int m1;  
    double m2, m3;  
};  
  
void function_C4838(double d1) {  
    double ad[] = { 1, d1 }; // OK  
    int ai[] = { 1, d1 };    // warning C4838  
    S1 s11 = { 1, 2, d1 };   // OK  
    S1 s12 { d1, 2, 3 };     // warning C4838  
    S1 s13 { static_cast<int>(d1), 2, 3 }; // possible fix for C4838  
}  
```
