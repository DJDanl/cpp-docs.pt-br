---
title: Como usar um filtro de bloco de mensagens
ms.date: 11/04/2016
helpviewer_keywords:
- message-block filters, using [Concurrency Runtime]
- using message-block filters [Concurrency Runtime]
ms.assetid: db6b99fb-288d-4477-96dc-b9751772ebb2
ms.openlocfilehash: ac58ef2240d2ea6ba34b334106c08595e70b02e8
ms.sourcegitcommit: 43cee7a0d41a062661229043c2f7cbc6ace17fa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/13/2020
ms.locfileid: "92008638"
---
# <a name="how-to-use-a-message-block-filter"></a>Como usar um filtro de bloco de mensagens

Este documento demonstra como usar uma função de filtro para habilitar um bloco de mensagens assíncronas para aceitar ou rejeitar uma mensagem com base no conteúdo dessa mensagem.

Quando você cria um objeto de bloco de mensagem, como um [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md), um [Concurrency:: Call](../../parallel/concrt/reference/call-class.md)ou um [Concurrency:: Transformer](../../parallel/concrt/reference/transformer-class.md), você pode fornecer uma *função de filtro* que determina se o bloco de mensagem aceita ou rejeita uma mensagem. Uma função de filtro é uma maneira útil de garantir que um bloco de mensagens receba apenas determinados valores.

As funções de filtro são importantes porque permitem que você conecte os blocos de mensagem para formar *redes de fluxo*de mensagens. Em uma rede de Dataflow, os blocos de mensagens controlam o fluxo de dados processando somente as mensagens que atendem a critérios específicos. Compare isso com o modelo de fluxo de controle, no qual o fluxo de dados é regulamentado usando estruturas de controle, como instruções condicionais, loops e assim por diante.

Este documento fornece um exemplo básico de como usar um filtro de mensagem. Para obter exemplos adicionais que usam filtros de mensagem e o modelo de fluxo de mensagens para conectar blocos de mensagem, consulte [passo a passos: Criando um agente de fluxo](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md) de mensagens e [passo a passo: criando uma rede Image-Processing](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md).

## <a name="example-count_primes-function"></a>Exemplo: função count_primes

Considere a seguinte função, `count_primes` , que ilustra o uso básico de um bloco de mensagens que não filtra mensagens de entrada. O bloco de mensagens acrescenta números primos a um objeto [std:: vector](../../standard-library/vector-class.md) . A `count_primes` função envia vários números ao bloco de mensagens, recebe os valores de saída do bloco de mensagens e imprime esses números que são primos para o console.

[!code-cpp[concrt-primes-filter#1](../../parallel/concrt/codesnippet/cpp/how-to-use-a-message-block-filter_1.cpp)]

O `transformer` objeto processa todos os valores de entrada; no entanto, ele requer apenas os valores primos. Embora o aplicativo possa ser escrito para que o remetente da mensagem envie apenas números primos, os requisitos do receptor de mensagens nem sempre são conhecidos.

## <a name="example-count_primes_filter-function"></a>Exemplo: função count_primes_filter

A função a seguir, `count_primes_filter` , executa a mesma tarefa que a `count_primes` função. No entanto, o `transformer` objeto nesta versão usa uma função de filtro para aceitar somente os valores que são primos. A função que executa a ação só recebe números primos; Portanto, ele não precisa chamar a `is_prime` função.

Como o `transformer` objeto recebe apenas números primos, o `transformer` próprio objeto pode conter os números primos. Em outras palavras, o `transformer` objeto neste exemplo não é necessário para adicionar os números primos ao `vector` objeto.

[!code-cpp[concrt-primes-filter#2](../../parallel/concrt/codesnippet/cpp/how-to-use-a-message-block-filter_2.cpp)]

O `transformer` objeto agora processa apenas os valores que são primos. No exemplo anterior, o `transformer` objeto processa todas as mensagens. Portanto, o exemplo anterior deve receber o mesmo número de mensagens enviadas. Este exemplo usa o resultado da função [Concurrency:: send](reference/concurrency-namespace-functions.md#send) para determinar quantas mensagens receber do `transformer` objeto. A `send` função retorna **`true`** quando o buffer de mensagens aceita a mensagem e **`false`** quando o buffer de mensagens rejeita a mensagem. Portanto, o número de vezes que o buffer de mensagens aceita a mensagem corresponde à contagem de números primos.

## <a name="example-finished-message-block-filter-code-sample"></a>Exemplo: exemplo de código de filtro de bloco de mensagem concluído

O código a seguir mostra um exemplo completo. O exemplo chama a `count_primes` função e a `count_primes_filter` função.

[!code-cpp[concrt-primes-filter#3](../../parallel/concrt/codesnippet/cpp/how-to-use-a-message-block-filter_3.cpp)]

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `primes-filter.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **cl.exe/EHsc Primes-Filter. cpp**

## <a name="robust-programming"></a>Programação robusta

Uma função de filtro pode ser uma função lambda, um ponteiro de função ou um objeto de função. Cada função de filtro usa um dos seguintes formulários:

```Output
bool (T)
bool (T const &)
```

Para eliminar a cópia desnecessária de dados, use o segundo formulário quando você tiver um tipo de agregação transmitido por valor.

## <a name="see-also"></a>Veja também

[Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Walkthrough: Criando um agente de Dataflow](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md)<br/>
[Walkthrough: criando uma rede Image-Processing](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md)<br/>
[Classe de transformador](../../parallel/concrt/reference/transformer-class.md)
