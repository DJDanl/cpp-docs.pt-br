---
title: Como usar um filtro de bloco de mensagens
ms.date: 11/04/2016
helpviewer_keywords:
- message-block filters, using [Concurrency Runtime]
- using message-block filters [Concurrency Runtime]
ms.assetid: db6b99fb-288d-4477-96dc-b9751772ebb2
ms.openlocfilehash: 074d3989ce48b0b6d69206e3f83c374a2ec65c93
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142812"
---
# <a name="how-to-use-a-message-block-filter"></a>Como usar um filtro de bloco de mensagens

Este documento demonstra como usar uma função de filtro para habilitar um bloco de mensagens assíncronas para aceitar ou rejeitar uma mensagem com base no conteúdo dessa mensagem.

Quando você cria um objeto de bloco de mensagem, como um [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md), um [Concurrency:: Call](../../parallel/concrt/reference/call-class.md)ou um [Concurrency:: Transformer](../../parallel/concrt/reference/transformer-class.md), você pode fornecer uma *função de filtro* que determina se o bloco de mensagem aceita ou rejeita uma mensagem. Uma função de filtro é uma maneira útil de garantir que um bloco de mensagens receba apenas determinados valores.

As funções de filtro são importantes porque permitem que você conecte os blocos de mensagem para formar *redes de fluxo*de mensagens. Em uma rede de Dataflow, os blocos de mensagens controlam o fluxo de dados processando somente as mensagens que atendem a critérios específicos. Compare isso com o modelo de fluxo de controle, no qual o fluxo de dados é regulamentado usando estruturas de controle, como instruções condicionais, loops e assim por diante.

Este documento fornece um exemplo básico de como usar um filtro de mensagem. Para obter exemplos adicionais que usam filtros de mensagem e o modelo de fluxo de imagens para conectar blocos de mensagens, consulte [passo a passos: Criando um agente de fluxo](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md) de [imagens e passo a passo: criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md).

## <a name="example"></a>{1&gt;Exemplo&lt;1}

Considere a seguinte função, `count_primes`, que ilustra o uso básico de um bloco de mensagens que não filtra mensagens de entrada. O bloco de mensagens acrescenta números primos a um objeto [std:: vector](../../standard-library/vector-class.md) . A função `count_primes` envia vários números ao bloco de mensagens, recebe os valores de saída do bloco de mensagens e imprime esses números que são primos para o console.

[!code-cpp[concrt-primes-filter#1](../../parallel/concrt/codesnippet/cpp/how-to-use-a-message-block-filter_1.cpp)]

O objeto `transformer` processa todos os valores de entrada; no entanto, ele requer apenas os valores primos. Embora o aplicativo possa ser escrito para que o remetente da mensagem envie apenas números primos, os requisitos do receptor de mensagens nem sempre são conhecidos.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

A função a seguir, `count_primes_filter`, executa a mesma tarefa que a função `count_primes`. No entanto, o objeto `transformer` nesta versão usa uma função de filtro para aceitar somente os valores que são primos. A função que executa a ação só recebe números primos; Portanto, ele não precisa chamar a função `is_prime`.

Como o objeto `transformer` recebe apenas números primos, o próprio objeto `transformer` pode conter os números primos. Em outras palavras, o objeto `transformer` neste exemplo não é necessário para adicionar os números primos ao objeto `vector`.

[!code-cpp[concrt-primes-filter#2](../../parallel/concrt/codesnippet/cpp/how-to-use-a-message-block-filter_2.cpp)]

O objeto `transformer` agora processa apenas os valores que são primos. No exemplo anterior, `transformer` objeto processa todas as mensagens. Portanto, o exemplo anterior deve receber o mesmo número de mensagens enviadas. Este exemplo usa o resultado da função [Concurrency:: send](reference/concurrency-namespace-functions.md#send) para determinar quantas mensagens receber do objeto `transformer`. A função `send` retorna **true** quando o buffer de mensagens aceita a mensagem e **false** quando o buffer de mensagens rejeita a mensagem. Portanto, o número de vezes que o buffer de mensagens aceita a mensagem corresponde à contagem de números primos.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O código a seguir mostra um exemplo completo. O exemplo chama a função `count_primes` e a função `count_primes_filter`.

[!code-cpp[concrt-primes-filter#3](../../parallel/concrt/codesnippet/cpp/how-to-use-a-message-block-filter_3.cpp)]

## <a name="compiling-the-code"></a>Compilando o Código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `primes-filter.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **CL. exe/EHsc Primes-Filter. cpp**

## <a name="robust-programming"></a>Programação Robusta

Uma função de filtro pode ser uma função lambda, um ponteiro de função ou um objeto de função. Cada função de filtro usa um dos seguintes formulários:

```Output
bool (T)
bool (T const &)
```

Para eliminar a cópia desnecessária de dados, use o segundo formulário quando você tiver um tipo de agregação transmitido por valor.

## <a name="see-also"></a>Consulte também

[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Instruções passo a passo: criando um agente de fluxo de dados](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md)<br/>
[Instruções passo a passo: criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md)<br/>
[Classe transformer](../../parallel/concrt/reference/transformer-class.md)
