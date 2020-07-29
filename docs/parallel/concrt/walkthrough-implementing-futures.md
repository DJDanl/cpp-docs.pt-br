---
title: 'Instruções passo a passo: implementando futuros'
ms.date: 04/25/2019
helpviewer_keywords:
- implementing futures [Concurrency Runtime]
- futures, implementing [Concurrency Runtime]
ms.assetid: 82ea75cc-aaec-4452-b10d-8abce0a87e5b
ms.openlocfilehash: 9bf46b7f2a761aaf0c07e1017524c8ddf533aca6
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230292"
---
# <a name="walkthrough-implementing-futures"></a>Instruções passo a passo: implementando futuros

Este tópico mostra como implementar futuros em seu aplicativo. O tópico demonstra como combinar a funcionalidade existente no Tempo de Execução de Simultaneidade em algo que faz mais.

> [!IMPORTANT]
> Este tópico ilustra o conceito de futuros para fins de demonstração. Recomendamos que você use [std:: futur](../../standard-library/future-class.md) ou [Concurrency:: Task](../../parallel/concrt/reference/task-class.md) quando precisar de uma tarefa assíncrona que calcule um valor para uso posterior.

Uma *tarefa* é uma computação que pode ser decomposta em cálculos adicionais e mais refinados. Um *futuro* é uma tarefa assíncrona que computa um valor para uso posterior.

Para implementar futuros, este tópico define a `async_future` classe. A `async_future` classe usa esses componentes do tempo de execução de simultaneidade: a classe [Concurrency:: task_group](reference/task-group-class.md) e a classe [Concurrency:: single_assignment](../../parallel/concrt/reference/single-assignment-class.md) . A `async_future` classe usa a `task_group` classe para computar um valor de forma assíncrona e a `single_assignment` classe para armazenar o resultado da computação. O construtor da `async_future` classe usa uma função de trabalho que computa o resultado, e o `get` método recupera o resultado.

### <a name="to-implement-the-async_future-class"></a>Para implementar a classe async_future

1. Declare uma classe de modelo denominada `async_future` que seja parametrizada no tipo de computação resultante. Adicione **`public`** **`private`** seções e a esta classe.

[!code-cpp[concrt-futures#2](../../parallel/concrt/codesnippet/cpp/walkthrough-implementing-futures_1.cpp)]

1. Na **`private`** seção da `async_future` classe, declare um membro de `task_group` dados e `single_assignment` .

[!code-cpp[concrt-futures#3](../../parallel/concrt/codesnippet/cpp/walkthrough-implementing-futures_2.cpp)]

1. Na **`public`** seção da `async_future` classe, implemente o construtor. O construtor é um modelo que é parametrizado na função de trabalho que computa o resultado. O construtor executa de forma assíncrona a função de trabalho no `task_group` membro de dados e usa a função [Concurrency:: send](reference/concurrency-namespace-functions.md#send) para gravar o resultado no `single_assignment` membro de dados.

[!code-cpp[concrt-futures#4](../../parallel/concrt/codesnippet/cpp/walkthrough-implementing-futures_3.cpp)]

1. Na **`public`** seção da `async_future` classe, implemente o destruidor. O destruidor aguarda a conclusão da tarefa.

[!code-cpp[concrt-futures#5](../../parallel/concrt/codesnippet/cpp/walkthrough-implementing-futures_4.cpp)]

1. Na **`public`** seção da `async_future` classe, implemente o `get` método. Esse método usa a função [Concurrency:: Receive](reference/concurrency-namespace-functions.md#receive) para recuperar o resultado da função de trabalho.

[!code-cpp[concrt-futures#6](../../parallel/concrt/codesnippet/cpp/walkthrough-implementing-futures_5.cpp)]

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

O exemplo a seguir mostra a `async_future` classe completa e um exemplo de seu uso. A `wmain` função cria um objeto std::[vector](../../standard-library/vector-class.md) que contém 10.000 valores inteiros aleatórios. Em seguida, ele usa `async_future` objetos para localizar os valores menores e maiores contidos no `vector` objeto.

### <a name="code"></a>Código

[!code-cpp[concrt-futures#1](../../parallel/concrt/codesnippet/cpp/walkthrough-implementing-futures_6.cpp)]

### <a name="comments"></a>Comentários

Esse exemplo gera a saída a seguir:

```Output
smallest: 0
largest:  9999
average:  4981
```

O exemplo usa o `async_future::get` método para recuperar os resultados da computação. O `async_future::get` método aguardará a conclusão da computação se a computação ainda estiver ativa.

## <a name="robust-programming"></a>Programação robusta

Para estender a `async_future` classe para tratar as exceções que são geradas pela função de trabalho, modifique o `async_future::get` método para chamar o método [concurrency:: task_group:: Wait](reference/task-group-class.md#wait) . O `task_group::wait` método gera quaisquer exceções que foram geradas pela função de trabalho.

O exemplo a seguir mostra a versão modificada da `async_future` classe. A `wmain` função usa um **`try`** - **`catch`** bloco para imprimir o resultado do `async_future` objeto ou para imprimir o valor da exceção gerada pela função de trabalho.

[!code-cpp[concrt-futures-with-eh#1](../../parallel/concrt/codesnippet/cpp/walkthrough-implementing-futures_7.cpp)]

Esse exemplo gera a saída a seguir:

```Output
caught exception: error
```

Para obter mais informações sobre o modelo de manipulação de exceções no Tempo de Execução de Simultaneidade, consulte [tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md).

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `futures.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

**cl.exe o/EHsc Futures. cpp**

## <a name="see-also"></a>Confira também

[Orientações Tempo de Execução de Simultaneidades](../../parallel/concrt/concurrency-runtime-walkthroughs.md)<br/>
[Tratamento de exceção](../../parallel/concrt/exception-handling-in-the-concurrency-runtime.md)<br/>
[Classe task_group](reference/task-group-class.md)<br/>
[Classe single_assignment](../../parallel/concrt/reference/single-assignment-class.md)
