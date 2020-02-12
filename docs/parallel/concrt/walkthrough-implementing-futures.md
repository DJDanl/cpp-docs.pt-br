---
title: 'Instruções passo a passo: implementando futuros'
ms.date: 04/25/2019
helpviewer_keywords:
- implementing futures [Concurrency Runtime]
- futures, implementing [Concurrency Runtime]
ms.assetid: 82ea75cc-aaec-4452-b10d-8abce0a87e5b
ms.openlocfilehash: 2b9d889dac195bb60651cbb76110d54b6231a5fd
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77141985"
---
# <a name="walkthrough-implementing-futures"></a>Instruções passo a passo: implementando futuros

Este tópico mostra como implementar futuros em seu aplicativo. O tópico demonstra como combinar a funcionalidade existente no Tempo de Execução de Simultaneidade em algo que faz mais.

> [!IMPORTANT]
> Este tópico ilustra o conceito de futuros para fins de demonstração. Recomendamos que você use [std:: futur](../../standard-library/future-class.md) ou [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) quando precisar de uma tarefa assíncrona que calcule um valor para uso posterior.

Uma *tarefa* é uma computação que pode ser decomposta em cálculos adicionais e mais refinados. Um *futuro* é uma tarefa assíncrona que computa um valor para uso posterior.

Para implementar futuros, este tópico define a classe `async_future`. A classe `async_future` usa esses componentes do Tempo de Execução de Simultaneidade: a classe [Concurrency:: task_group](reference/task-group-class.md) e a classe [concurrency:: single_assignment](../../parallel/concrt/reference/single-assignment-class.md) . A classe `async_future` usa a classe `task_group` para calcular um valor de forma assíncrona e a classe `single_assignment` para armazenar o resultado da computação. O construtor da classe `async_future` usa uma função de trabalho que computa o resultado, e o método `get` recupera o resultado.

### <a name="to-implement-the-async_future-class"></a>Para implementar a classe async_future

1. Declare uma classe de modelo chamada `async_future` que é parametrizada no tipo de computação resultante. Adicione `public` e `private` seções a essa classe.

[!code-cpp[concrt-futures#2](../../parallel/concrt/codesnippet/cpp/walkthrough-implementing-futures_1.cpp)]

1. Na seção `private` da classe `async_future`, declare um `task_group` e um membro de dados `single_assignment`.

[!code-cpp[concrt-futures#3](../../parallel/concrt/codesnippet/cpp/walkthrough-implementing-futures_2.cpp)]

1. Na seção `public` da classe `async_future`, implemente o construtor. O construtor é um modelo que é parametrizado na função de trabalho que computa o resultado. O construtor executa de forma assíncrona a função de trabalho no membro de dados `task_group` e usa a função [Concurrency:: send](reference/concurrency-namespace-functions.md#send) para gravar o resultado no membro de dados de `single_assignment`.

[!code-cpp[concrt-futures#4](../../parallel/concrt/codesnippet/cpp/walkthrough-implementing-futures_3.cpp)]

1. Na seção `public` da classe `async_future`, implemente o destruidor. O destruidor aguarda a conclusão da tarefa.

[!code-cpp[concrt-futures#5](../../parallel/concrt/codesnippet/cpp/walkthrough-implementing-futures_4.cpp)]

1. Na seção `public` da classe `async_future`, implemente o método `get`. Esse método usa a função [Concurrency:: Receive](reference/concurrency-namespace-functions.md#receive) para recuperar o resultado da função de trabalho.

[!code-cpp[concrt-futures#6](../../parallel/concrt/codesnippet/cpp/walkthrough-implementing-futures_5.cpp)]

## <a name="example"></a>{1&gt;Exemplo&lt;1}

### <a name="description"></a>Descrição

O exemplo a seguir mostra a classe `async_future` completa e um exemplo de seu uso. A função `wmain` cria um objeto std::[vector](../../standard-library/vector-class.md) que contém 10.000 valores inteiros aleatórios. Em seguida, ele usa `async_future` objetos para localizar os valores menores e maiores contidos no objeto `vector`.

### <a name="code"></a>Código

[!code-cpp[concrt-futures#1](../../parallel/concrt/codesnippet/cpp/walkthrough-implementing-futures_6.cpp)]

### <a name="comments"></a>Comments

Esse exemplo gera a saída a seguir:

```Output
smallest: 0
largest:  9999
average:  4981
```

O exemplo usa o método `async_future::get` para recuperar os resultados da computação. O método `async_future::get` aguarda a conclusão da computação se a computação ainda estiver ativa.

## <a name="robust-programming"></a>Programação Robusta

Para estender a classe `async_future` para tratar as exceções que são geradas pela função Work, modifique o método `async_future::get` para chamar o método [Concurrency:: task_group:: Wait](reference/task-group-class.md#wait) . O método `task_group::wait` gera quaisquer exceções que foram geradas pela função de trabalho.

O exemplo a seguir mostra a versão modificada da classe `async_future`. A função `wmain` usa um bloco de `catch` -`try`para imprimir o resultado do objeto `async_future` ou imprimir o valor da exceção gerada pela função de trabalho.

[!code-cpp[concrt-futures-with-eh#1](../../parallel/concrt/codesnippet/cpp/walkthrough-implementing-futures_7.cpp)]

Esse exemplo gera a saída a seguir:

```Output
caught exception: error
```

Para obter mais informações sobre o modelo de manipulação de exceções no Tempo de Execução de Simultaneidade, consulte [tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

## <a name="compiling-the-code"></a>Compilando o Código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `futures.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

**CL. exe/EHsc Futures. cpp**

## <a name="see-also"></a>Consulte também

[Instruções passo a passo do runtime de simultaneidade](../../parallel/concrt/concurrency-runtime-walkthroughs.md)<br/>
[Tratamento de Exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)<br/>
[Classe task_group](reference/task-group-class.md)<br/>
[Classe single_assignment](../../parallel/concrt/reference/single-assignment-class.md)
