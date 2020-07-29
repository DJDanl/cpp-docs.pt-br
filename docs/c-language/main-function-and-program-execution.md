---
title: Função main e execução do programa
ms.date: 11/04/2016
helpviewer_keywords:
- program startup [C++]
- entry points, program
- main function, program execution
- startup code, main function
- main function
- programs [C++], terminating
ms.assetid: 5984f1bd-072d-4e06-8640-122fb1454401
ms.openlocfilehash: f2419820fb6018613fe3fae39194584076121898
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211782"
---
# <a name="main-function-and-program-execution"></a>Função main e execução do programa

Cada programa C tem uma função principal (main) que deve ser nomeada **main**. Se seu código obedece ao modelo de programação Unicode, você pode usar a versão de **main** para caracteres largos, **wmain**. A função **main** serve como o ponto de partida para a execução do programa. Em geral, ela controla a execução direcionando as chamadas para outras funções no programa. Normalmente, um programa para de ser executado no final de **main**, embora possa terminar em outros pontos no programa por diversos motivos. Às vezes, talvez quando um determinado erro é detectado, pode ser conveniente forçar o término de um programa. Para fazer isso, use a função **exit**. Consulte a *Referência da biblioteca em tempo de execução* para obter informações sobre como usar a função [exit](../c-runtime-library/reference/exit-exit-exit.md), juntamente com um exemplo.

## <a name="syntax"></a>Sintaxe

```
main( int argc, char *argv[ ], char *envp[ ] )
```

## <a name="remarks"></a>Comentários

As funções do programa de origem executam uma ou mais tarefas específicas. A função **main** pode chamar essas funções para executar as respectivas tarefas. Quando **main** chama outra função, passa para ela o controle da execução; assim, a execução começa na primeira instrução da função. Uma função retorna o controle para **Main** quando uma **`return`** instrução é executada ou quando o final da função é atingido.

Você pode declarar qualquer função, inclusive **main**, para ter parâmetros. O termo "parâmetro" ou "parâmetro formal" refere-se ao identificador que recebe um valor passado para uma função. Consulte [Parâmetros](../c-language/parameters.md) para obter informações sobre como passar argumentos para parâmetros. Quando uma função chama outra, a função chamada recebe valores para os respectivos parâmetros da função que chamou. Esses valores são chamados de "argumentos". É possível declarar parâmetros formais para **main** de modo que a função possa receber argumentos da linha de comando usando este formato:

Quando você quer passar informações para a função **main**, tradicionalmente os parâmetros são nomeados `argc` e `argv`, embora o compilador de C não exija esses nomes. Os tipos para `argc` e `argv` são definidos pela linguagem C. Tradicionalmente, se um terceiro parâmetro é passado para **main**, ele é nomeado `envp`. Exemplos posteriormente nesta seção mostram como usar esses três parâmetros para acessar argumentos de linha de comando. As seções a seguir explicam esses parâmetros.

Consulte [Usando wmain](../c-language/using-wmain.md) para obter uma descrição da versão de **main** para caracteres largos.

## <a name="see-also"></a>Confira também

[argumentos da função principal e da linha de comando (C++)](../cpp/main-function-command-line-args.md)\
[Analisando argumentos de linha de comando C](../c-language/parsing-c-command-line-arguments.md)
