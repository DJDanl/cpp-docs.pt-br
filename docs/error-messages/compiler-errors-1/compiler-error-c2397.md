---
title: Erro do compilador C2397
ms.date: 11/04/2016
f1_keywords:
- C2397
ms.assetid: b418cf5a-d50d-4a6c-98a7-994ae35046d1
ms.openlocfilehash: 61f23269e0b6ed65a485f11e49e492d2248b8a42
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50640382"
---
# <a name="compiler-error-c2397"></a>Erro do compilador C2397

conversão de 'type_1' em 'type_2' requer uma conversão redutora

Uma conversão de estreitamento implícita foi encontrada ao usar inicialização uniforme.

A linguagem C permite conversões de estreitamento implícitas na inicialização e as atribuições e C++ segue o naipe, embora inesperado de redução é uma causa de muitos erros de código. Para tornar o código mais seguro, o padrão C++ requer que uma mensagem de diagnóstico quando uma conversão redutora ocorre em uma lista de inicialização. No Visual C++, o diagnóstico é erro do compilador C2397 ao usar o início de sintaxe com suporte de inicialização uniforme no Visual Studio 2015. O compilador gera [aviso do compilador (nível 1) C4838](../../error-messages/compiler-warnings/compiler-warning-level-1-c4838.md) ao usar a sintaxe de inicialização de agregação com suporte pelo Visual Studio 2013 ou lista.

Uma conversão de redução pode ser okey quando você sabe que o intervalo possível de valores convertidos pode se ajustar no destino. Nesse caso, você sabe mais do que o compilador faz. Se você fizer uma conversão redutora intencionalmente, faça suas intenções explícita, usando uma conversão estática. Caso contrário, essa mensagem de erro indica quase sempre que haverá um bug em seu código. Você pode corrigi-lo, tornando-se de que os objetos que você inicializa têm tipos que são grandes o suficiente para lidar com as entradas.

O exemplo a seguir gera C2397 e mostra uma maneira de corrigir isso:

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