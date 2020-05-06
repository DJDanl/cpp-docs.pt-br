---
title: Argumentos
ms.date: 11/04/2016
helpviewer_keywords:
- arguments [C++], function
- function parameters
- functions [C], parameters
- function parameters, about function parameters
- function arguments
- function calls, arguments
ms.assetid: 14cf0389-2265-41f0-9a96-f2223eb406ca
ms.openlocfilehash: e60a7935cdddc116848b64461b064c5fd5cdd00a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62313502"
---
# <a name="arguments"></a>Argumentos

Os argumentos em uma chamada de função têm este formato:

> *expressão* **(** *opcional de expressão-lista de expressões*<SUB>opt</SUB> **)** /* chamada de função */

Em uma chamada de função, *expression-list* é uma lista de expressões (separadas por vírgula). Os valores dessas últimas expressões são os argumentos passados para a função. Se a função não utiliza argumentos, a *expression-list* deve conter a palavra-chave `void`.

Um argumento pode ser qualquer valor com fundamental, estrutura, união ou tipo de ponteiro. Todos os argumentos são passados por valor. Isso significa que uma cópia do argumento será atribuída ao parâmetro correspondente. A função não sabe o local real da memória do argumento passado. A função usará essa cópia sem afetar a variável da qual foi derivada originalmente.

Embora você não possa passar matrizes ou funções como argumentos, é possível passar ponteiros para esses itens. Os ponteiros permitem que uma função acesse um valor por referência. Como um ponteiro para uma variável contém o endereço da variável, a função pode usar esse endereço para acessar o valor da variável. Os argumentos de ponteiro permitem que uma função acesse matrizes e funções, mesmo que as matrizes e funções não possam ser passadas como argumentos.

A ordem em que os argumentos são avaliados pode variar nos compiladores diferentes e níveis diferentes de otimização. No entanto, os argumentos e os efeitos colaterais são avaliados completamente antes de a função ser inserida. Consulte [Efeitos colaterais](../c-language/side-effects.md) para obter informações sobre os efeitos colaterais.

A *expression-list* em uma chamada de função é avaliada e as conversões aritméticas comuns são executadas em cada argumento da chamada de função. Se um protótipo estiver disponível, o tipo de argumento resultante será comparado ao parâmetro correspondente do protótipo. Caso isso não aconteça, uma conversão será executada ou uma mensagem de diagnóstico será emitida. Os parâmetros também passam por conversões aritméticas comuns.

O número de expressões em *expression-list* deve corresponder ao número de parâmetros, a menos que o protótipo ou a definição da função especifique explicitamente um número variável de argumentos. Nesse caso, o compilador verifica quantos argumentos houver nos nomes de tipo na lista de parâmetros e os converte, se necessário, conforme descrito acima. Consulte [chamadas com um número variável de argumentos](../c-language/calls-with-a-variable-number-of-arguments.md) para obter mais informações.

Se a lista de parâmetros do protótipo contém apenas a palavra-chave `void`, o compilador espera zero argumentos na chamada de função e zero parâmetros na definição. Uma mensagem de diagnóstico será emitida se encontrar argumentos.

## <a name="example"></a>Exemplo

Este exemplo usa ponteiros como argumentos:

```C
int main()
{
    /* Function prototype */

    void swap( int *num1, int *num2 );
    int x, y;
    .
    .
    .
    swap( &x, &y );  /* Function call */
}

/* Function definition */

void swap( int *num1, int *num2 )
{
    int t;

    t = *num1;
    *num1 = *num2;
    *num2 = t;
}
```

Neste exemplo, a função `swap` é declarada em `main` como tendo dois argumentos, respectivamente representados pelos identificadores `num1` e `num2`, ambos são ponteiros para os valores `int`. Os parâmetros `num1` e `num2` na definição de estilo do protótipo também são declarados como ponteiros para os valores do tipo `int`.

Na chamada de função

```C
swap( &x, &y )
```

o endereço de `x` é armazenado em `num1`, e o endereço de `y` é armazenado em `num2`. Agora há dois nomes ou "aliases" para o mesmo local. As referências a `*num1` e a `*num2` em `swap` são efetivamente referências a `x` e a `y` em `main`. As atribuições de `swap` trocam realmente o conteúdo de `x` e `y`. Consequentemente, nenhuma instrução `return` é necessária.

O compilador executa a verificação de tipo nos argumentos para `swap` porque o protótipo de `swap` inclui tipos de argumento para cada parâmetro. Os identificadores entre parênteses do protótipo e a definição podem ser iguais ou diferentes. O importante aqui é que os tipos dos argumentos correspondam aos das listas de parâmetros no protótipo e na definição.

## <a name="see-also"></a>Confira também

[Chamadas de função](../c-language/function-calls.md)
