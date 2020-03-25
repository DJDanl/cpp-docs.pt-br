---
title: Aviso do compilador (nível 1) C4838
ms.date: 11/04/2016
f1_keywords:
- C4838
helpviewer_keywords:
- C4838
ms.assetid: fea07924-5feb-4ed4-99b5-1a8c41d28db6
ms.openlocfilehash: c3ddc861e5da271903372eac1ef1e8f6916e06df
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80199362"
---
# <a name="compiler-warning-level-1-c4838"></a>Aviso do compilador (nível 1) C4838

conversão de ' type_1 ' em ' type_2 ' requer uma conversão de restrição

Uma conversão de estreitamento implícita foi encontrada ao usar a inicialização de agregação ou de lista.

A linguagem C permite conversões de estreitamento implícitas em atribuições e inicialização C++ , e segue o naipe, embora a restrição inesperada seja uma causa de muitos erros de código. Para tornar o código mais seguro, C++ o padrão requer uma mensagem de diagnóstico quando ocorre uma conversão de restrição em uma lista de inicialização. No Visual C++, o diagnóstico é o [erro do compilador C2397](../../error-messages/compiler-errors-1/compiler-error-c2397.md) ao usar a sintaxe de inicialização uniforme com suporte a partir do Visual Studio 2015. O compilador gera o aviso C4838 ao usar a sintaxe de inicialização de lista ou de agregação com suporte pelo Visual Studio 2013.

Uma conversão de restrição pode ser boa quando você sabe que o intervalo possível de valores convertidos pode caber no destino. Nesse caso, você sabe mais do que o compilador. Se você fizer uma conversão de restrição intencionalmente, torne suas intenções explícitas usando uma conversão estática. Caso contrário, essa mensagem de aviso quase sempre indica que você tem um bug em seu código. Você pode corrigi-lo verificando se os objetos inicializados têm tipos que são grandes o suficiente para lidar com as entradas.

O exemplo a seguir gera C4838 e mostra uma maneira de corrigi-lo:

```cpp
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
