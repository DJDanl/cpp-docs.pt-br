---
title: Compilador (nível 1) de aviso C4838 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: error-reference
f1_keywords:
- C4838
dev_langs:
- C++
helpviewer_keywords:
- C4838
ms.assetid: fea07924-5feb-4ed4-99b5-1a8c41d28db6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1327ed8869c17701c6aa0a6ce2e3479b6109b8cd
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33283839"
---
# <a name="compiler-warning-level-1-c4838"></a>Compilador C4838 de aviso (nível 1)
conversão de 'type_1' em 'type_2' requer uma conversão de restrição  
  
 Uma conversão implícita de restrição foi encontrada ao usar a inicialização de agregação ou lista.  
  
 Linguagem C permite conversões de estreitamento implícitas na inicialização e atribuições e C++ segue o naipe, mesmo que inesperado de estreitamento é uma causa de muitos erros de código. Para tornar o código mais seguro, o C++ padrão requer uma mensagem de diagnóstico quando ocorre uma conversão de restrição em uma lista de inicialização. No Visual C++, o diagnóstico é [C2397 de erro do compilador](../../error-messages/compiler-errors-1/compiler-error-c2397.md) ao usar a sintaxe de inicialização uniforme com suporte a partir do Visual Studio 2015. O compilador gera o aviso C4838 ao usar a sintaxe de inicialização de agregação com suporte do Visual Studio 2013 ou lista.  
  
 Uma conversão de restrição pode ser okey quando você sabe que o intervalo de valores convertidos possível pode se ajustar no destino. Nesse caso, você sabe mais do que o compilador faz. Se você fizer uma conversão de restrição intencionalmente, faça sua intenção explícita, usando uma conversão estática. Caso contrário, essa mensagem de aviso quase sempre indica que há um bug no seu código. Você pode corrigi-lo, certificando-se os objetos que você inicializar têm tipos que são grandes o suficiente para lidar com as entradas.  
  
 O exemplo a seguir gera C4838 e mostra uma maneira de corrigir isso:  
  
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