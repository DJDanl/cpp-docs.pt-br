---
title: Instrução return (C++)
ms.date: 11/04/2016
f1_keywords:
- return_cpp
helpviewer_keywords:
- return keyword [C++], syntax
- return keyword [C++]
ms.assetid: a498903a-056a-4df0-a6cf-72f633a62210
ms.openlocfilehash: 6a1ed4f374f133abd0233826d1b58896d49576cf
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225859"
---
# <a name="return-statement-c"></a>Instrução return (C++)

Finaliza a execução de uma função e retorna o controle para a função de chamada (ou para o sistema operacional, se o controle for transferido da função `main`). A execução é retomada na função de chamada no ponto imediatamente após a chamada.

## <a name="syntax"></a>Sintaxe

```
return [expression];
```

## <a name="remarks"></a>Comentários

A cláusula `expression`, caso exista, é convertida no tipo especificado na declaração da função, como se uma inicialização estivesse sendo executada. A conversão do tipo da expressão para o **`return`** tipo da função pode criar objetos temporários. Para obter mais informações sobre como e quando temporaries são criados, consulte [objetos temporários](../cpp/temporary-objects.md).

O valor da cláusula `expression` é retornado à função de chamada. Se a expressão for omitida, o valor de retorno da função será indefinido. Construtores e destruidores, e funções do tipo **`void`** , não podem especificar uma expressão na **`return`** instrução. As funções de todos os outros tipos devem especificar uma expressão na **`return`** instrução.

Quando o fluxo de controle sai do bloco que está delimitando a definição da função, o resultado é o mesmo que seria se uma **`return`** instrução sem uma expressão tivesse sido executada. Isso não é válido para funções que são declaradas como retornando um valor.

Uma função pode ter qualquer número de **`return`** instruções.

O exemplo a seguir usa uma expressão com uma **`return`** instrução para obter o maior de dois inteiros.

## <a name="example"></a>Exemplo

```cpp
// return_statement2.cpp
#include <stdio.h>

int max ( int a, int b )
{
   return ( a > b ? a : b );
}

int main()
{
    int nOne = 5;
    int nTwo = 7;

    printf_s("\n%d is bigger\n", max( nOne, nTwo ));
}
```

## <a name="see-also"></a>Confira também

[Instruções de atalho](../cpp/jump-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
