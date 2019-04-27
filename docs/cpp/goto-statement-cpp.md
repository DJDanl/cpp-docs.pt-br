---
title: Instrução goto (C++)
ms.date: 11/04/2016
f1_keywords:
- goto_cpp
helpviewer_keywords:
- goto keyword [C++]
ms.assetid: 724c5deb-2de1-42d8-8ef1-23589d9bf5ed
ms.openlocfilehash: aac308905a01a52a4ce5ee0fa3be03f2f33ac1cd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62153691"
---
# <a name="goto-statement-c"></a>Instrução goto (C++)

O **goto** incondicionalmente transfere o controle para a instrução rotulada pelo identificador especificado.

## <a name="syntax"></a>Sintaxe

```
goto identifier;
```

## <a name="remarks"></a>Comentários

A instrução rotulada designada por `identifier` deve estar na função atual. Todos os nomes de `identifier` são membros de um namespace interno e, portanto, não interferem em outros identificadores.

Rótulo de uma instrução é significante somente para um **goto** instrução; caso contrário, os rótulos de instrução são ignorados. Os rótulos não podem ser redeclarados.

Um **goto** instrução não tem permissão para transferir o controle para um local que ignora a inicialização de qualquer variável que está no escopo nesse local. O exemplo a seguir gera C2362:

```cpp
int goto_fn(bool b)
{
    if (!b)
    {
        goto exit;  // C2362
    }
    else
    { /*...*/ }

    int error_code = 42;

exit:
    return error_code;
}
```

É um bom programação estilo a ser usado o **quebra**, **continuar**, e **retornar** instruções em vez do **goto** instrução sempre que é possível. No entanto, porque o **quebra** instrução sai de apenas um nível de um loop, você talvez precise usar um **goto** instrução para sair de um loop profundamente aninhado.

Para obter mais informações sobre rótulos e o **goto** instrução, consulte [instruções rotuladas](../cpp/labeled-statements.md).

## <a name="example"></a>Exemplo

Neste exemplo, uma **goto** transfere o controle para o ponto rotulado `stop` quando `i` é igual a 3.

```cpp
// goto_statement.cpp
#include <stdio.h>
int main()
{
    int i, j;

    for ( i = 0; i < 10; i++ )
    {
        printf_s( "Outer loop executing. i = %d\n", i );
        for ( j = 0; j < 2; j++ )
        {
            printf_s( " Inner loop executing. j = %d\n", j );
            if ( i == 3 )
                goto stop;
        }
    }

    // This message does not print:
    printf_s( "Loop exited. i = %d\n", i );

    stop:
    printf_s( "Jumped to stop. i = %d\n", i );
}
```

```Output
Outer loop executing. i = 0
Inner loop executing. j = 0
Inner loop executing. j = 1
Outer loop executing. i = 1
Inner loop executing. j = 0
Inner loop executing. j = 1
Outer loop executing. i = 2
Inner loop executing. j = 0
Inner loop executing. j = 1
Outer loop executing. i = 3
Inner loop executing. j = 0
Jumped to stop. i = 3
```

## <a name="see-also"></a>Consulte também

[Instruções de atalho](../cpp/jump-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
