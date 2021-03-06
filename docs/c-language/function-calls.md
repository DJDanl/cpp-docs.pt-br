---
title: Chamadas de função
ms.date: 11/04/2016
helpviewer_keywords:
- function calls, C functions
- functions [C], calling
- function calls, about function calls
- function calls
ms.assetid: 2cfa897d-3874-4820-933c-e624f75d1712
ms.openlocfilehash: 495dc3cf77df79336af364eb80ea7edf17b54400
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227862"
---
# <a name="function-calls"></a>Chamadas de função

Uma *chamada de função* é uma expressão que passa o controle e os argumentos (se houver) para uma função e tem o formato:

*expressão* (<sub>opt</sub>*de lista de expressões*)

em que *expression* é um nome de função ou é avaliado em um endereço de função e *expression-list* é uma lista de expressões (separadas por vírgulas). Os valores dessas últimas expressões são os argumentos passados para a função. Se a função não retornar um valor, você o declarará como uma função que retorna **`void`** .

Se uma declaração existe antes da chamada de função, mas nenhuma informação é fornecida quanto aos parâmetros, os argumentos não declarados simplesmente passam pelas conversões aritméticas comuns.

> [!NOTE]
> As expressões na lista de argumentos da função podem ser avaliadas em qualquer ordem, portanto, os argumentos cujos valores podem ser alterados por efeitos colaterais de outro argumento têm valores indefinidos. O ponto de sequência definido pelo operador de chamada de função apenas garante que todos os efeitos colaterais na lista de argumentos sejam avaliados antes que o controle passe para a função chamada. (Observe que a ordem na qual os argumentos são enviados por push na pilha é uma questão separada.) Consulte [pontos de sequência](../c-language/c-sequence-points.md) para obter mais informações.

O único requisito em qualquer chamada de função é que a expressão antes dos parênteses devem ser avaliadas como um endereço de função. Isso significa que uma função pode ser chamada por qualquer expressão de ponteiro de função.

## <a name="example"></a>Exemplo

Este exemplo ilustra chamadas de função chamadas de uma **`switch`** instrução:

```
int main()
{
    /* Function prototypes */

    long lift( int ), step( int ), drop( int );
    void work( int number, long (*function)(int i) );

    int select, count;
    .
    .
    .
    select = 1;
    switch( select )
    {
        case 1: work( count, lift );
                break;

        case 2: work( count, step );
                break;

        case 3: work( count, drop );
                /* Fall through to next case */
        default:
                break;
    }
}

/* Function definition */

void work( int number, long (*function)(int i) )
{
    int i;
    long j;

    for ( i = j = 0; i < number; i++ )
            j += ( *function )( i );
}
```

Nesse exemplo, a chamada de função em `main`,

```
work( count, lift );
```

passa uma variável de inteiro, `count`, e o endereço da função `lift` para a função `work`. Observe que o endereço da função é passado simplesmente fornecendo o identificador de função, pois um identificador de função é avaliado em uma expressão de ponteiro. Para usar um identificador de função dessa forma, a função deve ser declarada ou definida antes que o identificador seja usado; caso contrário, o identificador não é reconhecido. Nesse caso, um protótipo para `work` é fornecido no início da função `main`.

O parâmetro `function` em `work` é declarado como um ponteiro para uma função que assume um **`int`** argumento e retorna um **`long`** valor. Os parênteses em volta do nome do parâmetro são obrigatórios; sem eles, a declaração especificaria uma função que retornasse um ponteiro para um **`long`** valor.

A função `work` chama a função selecionada de dentro do **`for`** loop usando a seguinte chamada de função:

```
( *function )( i );
```

Um argumento, `i`, é passado para a função chamada.

## <a name="see-also"></a>Confira também

[Funções](../c-language/functions-c.md)
