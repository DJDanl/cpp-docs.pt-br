---
title: Funções Recursivas
ms.date: 11/04/2016
helpviewer_keywords:
- functions [C], recursive
- function calls, recursive
- functions [C], calling recursively
- recursive function calls
ms.assetid: 59739040-3081-4006-abbc-9d8423992bce
ms.openlocfilehash: 82f0c820ab75fda4bae83db78fa402d7a07cb7fe
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56152424"
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
