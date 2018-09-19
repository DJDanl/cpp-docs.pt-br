---
title: Compilador aviso (nível 1) C4838 | Microsoft Docs
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
ms.openlocfilehash: 1335d9c36f6764b54689a8334a91f11275ee3265
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46025445"
---
# <a name="compiler-warning-level-1-c4838"></a>Compilador aviso (nível 1) C4838

conversão de 'type_1' em 'type_2' requer uma conversão redutora

Uma conversão de estreitamento implícita foi encontrada ao usar a inicialização de agregação ou lista.

A linguagem C permite conversões de estreitamento implícitas na inicialização e as atribuições e C++ segue o naipe, embora inesperado de redução é uma causa de muitos erros de código. Para tornar o código mais seguro, o padrão C++ requer que uma mensagem de diagnóstico quando uma conversão redutora ocorre em uma lista de inicialização. No Visual C++, o diagnóstico está [erro do compilador C2397](../../error-messages/compiler-errors-1/compiler-error-c2397.md) ao usar a sintaxe de inicialização uniforme com suporte a partir do Visual Studio 2015. O compilador gera o aviso C4838 ao usar a sintaxe de inicialização de agregação com suporte pelo Visual Studio 2013 ou lista.

Uma conversão de redução pode ser okey quando você sabe que o intervalo possível de valores convertidos pode se ajustar no destino. Nesse caso, você sabe mais do que o compilador faz. Se você fizer uma conversão redutora intencionalmente, faça suas intenções explícita, usando uma conversão estática. Caso contrário, essa mensagem de aviso quase sempre indica que você tem um bug em seu código. Você pode corrigi-lo, tornando-se de que os objetos que você inicializa têm tipos que são grandes o suficiente para lidar com as entradas.

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