---
title: Erro do compilador C2397
ms.date: 11/04/2016
f1_keywords:
- C2397
ms.assetid: b418cf5a-d50d-4a6c-98a7-994ae35046d1
ms.openlocfilehash: 02a8bb09e0b22619bd61e6c4675057263a62a9d5
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80206009"
---
# <a name="compiler-error-c2397"></a>Erro do compilador C2397

conversão de ' type_1 ' em ' type_2 ' requer uma conversão de restrição

Uma conversão de estreitamento implícita foi encontrada ao usar a inicialização uniforme.

A linguagem C permite conversões de estreitamento implícitas em atribuições e inicialização C++ , e segue o naipe, embora a restrição inesperada seja uma causa de muitos erros de código. Para tornar o código mais seguro, C++ o padrão requer uma mensagem de diagnóstico quando ocorre uma conversão de restrição em uma lista de inicialização. No Visual C++, o diagnóstico é o erro do compilador C2397 ao usar a sintaxe de inicialização uniforme com suporte a partir do Visual Studio 2015. O compilador gera o [aviso do compilador (nível 1) C4838](../../error-messages/compiler-warnings/compiler-warning-level-1-c4838.md) ao usar a sintaxe da lista ou da inicialização de agregação com suporte pelo Visual Studio 2013.

Uma conversão de restrição pode ser boa quando você sabe que o intervalo possível de valores convertidos pode caber no destino. Nesse caso, você sabe mais do que o compilador. Se você fizer uma conversão de restrição intencionalmente, torne suas intenções explícitas usando uma conversão estática. Caso contrário, essa mensagem de erro quase sempre indica que você tem um bug em seu código. Você pode corrigi-lo verificando se os objetos inicializados têm tipos que são grandes o suficiente para lidar com as entradas.

O exemplo a seguir gera C2397 e mostra uma maneira de corrigi-lo:

```
// C2397.cpp -- C++ narrowing conversion diagnostics
// Compile by using: cl /EHsc C2397.cpp
#include <vector>

struct S1 {
    int m1;
    double m2, m3;
};

void function_C2397(double d1) {
    char c1 { 127 };          // OK
    char c2 { 513 };          // error C2397

    std::vector<S1> vS1;
    vS1.push_back({ d1, 2, 3 }); // error C2397

    // Possible fix if you know d1 always fits in an int
    vS1.push_back({ static_cast<int>(d1), 2, 3 });
}
```
