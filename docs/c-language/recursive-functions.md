---
title: Funções Recursivas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- functions [C], recursive
- function calls, recursive
- functions [C], calling recursively
- recursive function calls
ms.assetid: 59739040-3081-4006-abbc-9d8423992bce
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 187c176aa90997e4841bc22e468fab079f9e8b2a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46062755"
---
# <a name="recursive-functions"></a>Funções Recursivas

Qualquer função em um programa C pode ser chamada recursivamente, ou seja, pode chamar a si mesma. O número de chamadas recursivas está limitado ao tamanho da pilha. Consulte a opção de vinculador [/STACK (Stack Allocations)](../build/reference/stack-stack-allocations.md) (/STACK) para obter informações sobre as opções de vinculador que definem o tamanho da pilha. Cada vez que a função é chamada, um novo armazenamento é alocado para os parâmetros e para as variáveis **auto** e **register**, de modo que os respectivos valores em chamadas anteriores inacabadas não sejam substituídos. Os parâmetros só são diretamente acessíveis para a instância da função na qual são criados. Os parâmetros anteriores não são diretamente acessíveis para instâncias resultantes da função.

Observe que as variáveis declaradas com o armazenamento **static** não exigem um novo armazenamento com cada chamada recursiva. O armazenamento existe para todo o tempo de vida do programa. Cada referência a essa variável acessa a mesma área de armazenamento.

## <a name="example"></a>Exemplo

Este exemplo ilustra chamadas recursivas:

```C
int factorial( int num );      /* Function prototype */

int main()
{
    int result, number;
    .
    .
    .
    result = factorial( number );
}

int factorial( int num )      /* Function definition */
{
    .
    .
    .
    if ( ( num > 0 ) || ( num <= 10 ) )
        return( num * factorial( num - 1 ) );
}
```

## <a name="see-also"></a>Consulte também

[Chamadas de função](../c-language/function-calls.md)