---
title: Funções Recursivas
ms.date: 11/04/2016
helpviewer_keywords:
- functions [C], recursive
- function calls, recursive
- functions [C], calling recursively
- recursive function calls
ms.assetid: 59739040-3081-4006-abbc-9d8423992bce
ms.openlocfilehash: 8979d386c6fc3415cd50159250db8488cb917cee
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87199510"
---
# <a name="recursive-functions"></a>Funções Recursivas

Qualquer função em um programa C pode ser chamada recursivamente, ou seja, pode chamar a si mesma. O número de chamadas recursivas está limitado ao tamanho da pilha. Consulte a opção de vinculador [ `/STACK` (alocações de pilha)](../build/reference/stack-stack-allocations.md) para obter informações sobre opções de vinculador que definem o tamanho da pilha. Cada vez que a função é chamada, o novo armazenamento é alocado para os parâmetros e para as **`auto`** variáveis e para **`register`** que seus valores nas chamadas anteriores, não concluídas, não sejam substituídas. Os parâmetros só são diretamente acessíveis para a instância da função na qual são criados. Os parâmetros anteriores não são diretamente acessíveis para instâncias resultantes da função.

Observe que as variáveis declaradas com **`static`** armazenamento não exigem um novo armazenamento com cada chamada recursiva. O armazenamento existe para todo o tempo de vida do programa. Cada referência a essa variável acessa a mesma área de armazenamento.

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

## <a name="see-also"></a>Confira também

[Chamadas de função](../c-language/function-calls.md)
