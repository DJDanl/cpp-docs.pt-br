---
title: 'Como: Usar um filtro de bloco de mensagens'
ms.date: 11/04/2016
helpviewer_keywords:
- message-block filters, using [Concurrency Runtime]
- using message-block filters [Concurrency Runtime]
ms.assetid: db6b99fb-288d-4477-96dc-b9751772ebb2
ms.openlocfilehash: 1bfa11953d27dc7e013e715b3f58111f124caeaf
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62321930"
---
# <a name="how-to-use-a-message-block-filter"></a>Como: Usar um filtro de bloco de mensagens

Este documento demonstra como usar uma função de filtro para habilitar um bloco de mensagem assíncrona aceitar ou rejeitar uma mensagem com base na carga da mensagem.

Quando você cria um objeto de bloco de mensagem, como um [Concurrency:: unbounded_buffer](reference/unbounded-buffer-class.md), um [concurrency::call](../../parallel/concrt/reference/call-class.md), ou uma [Concurrency:: Transformer](../../parallel/concrt/reference/transformer-class.md), você pode fornecer um *função de filtro* que determina se o bloco de mensagens aceita ou rejeita uma mensagem. Uma função de filtro é uma maneira útil para garantir que um bloco de mensagem receba apenas determinados valores.

Funções de filtro são importantes porque permitem que você conectar blocos de mensagens para formar *redes de fluxo de dados*. Em uma rede de fluxo de dados, blocos de mensagens de controlam o fluxo de dados processando apenas as mensagens que atendam a critérios específicos. Compare isso com o modelo de fluxo de controle, em que o fluxo de dados regulado pelo uso de estruturas de controle, como instruções condicionais, loops e assim por diante.

Este documento fornece um exemplo básico de como usar um filtro de mensagem. Para obter exemplos adicionais que usam filtros de mensagem e o modelo de fluxo de dados para conectar blocos de mensagens, consulte [passo a passo: Criando um agente de fluxo de dados](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md) e [passo a passo: Criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md).

## <a name="example"></a>Exemplo

Considere a seguinte função, `count_primes`, que ilustra o uso básico de um bloco de mensagem que não filtra as mensagens de entrada. O bloco de mensagem acrescenta números primos para um [std:: Vector](../../standard-library/vector-class.md) objeto. O `count_primes` função envia vários números para o bloco de mensagens, recebe os valores de saída do bloco de mensagens e imprime esses números primos no console.

[!code-cpp[concrt-primes-filter#1](../../parallel/concrt/codesnippet/cpp/how-to-use-a-message-block-filter_1.cpp)]

O `transformer` objeto processa os valores de todas as entrada; no entanto, ele exige que apenas os valores que são primo. Embora o aplicativo poderia ser escrito para que o remetente da mensagem envia somente os números primos, os requisitos do receptor da mensagem não podem sempre ser conhecidos.

## <a name="example"></a>Exemplo

A seguinte função, `count_primes_filter`, executa a mesma tarefa que o `count_primes` função. No entanto, o `transformer` objeto nesta versão usa uma função de filtro para aceitar apenas os valores que são primo. A função que executa a ação recebe apenas os números primos; Portanto, não precisa chamar o `is_prime` função.

Porque o `transformer` objeto recebe apenas os números primos, a `transformer` objeto em si pode conter os números primos. Em outras palavras, o `transformer` objeto neste exemplo não é necessário para adicionar os números primos para o `vector` objeto.

[!code-cpp[concrt-primes-filter#2](../../parallel/concrt/codesnippet/cpp/how-to-use-a-message-block-filter_2.cpp)]

O `transformer` objeto agora processa apenas os valores que são primo. No exemplo anterior, `transformer` objeto processa todas as mensagens. Portanto, o exemplo anterior deve receber o mesmo número de mensagens que ele envia. Este exemplo usa o resultado do [Concurrency:: Send](reference/concurrency-namespace-functions.md#send) função para determinar quantas mensagens para receber o `transformer` objeto. O `send` retornos de função **verdadeira** quando o buffer de mensagem aceita a mensagem e **falso** quando o buffer de mensagem rejeitará a mensagem. Portanto, o número de vezes que o buffer de mensagem aceita a mensagem corresponde a contagem de números primos.

## <a name="example"></a>Exemplo

O código a seguir mostra um exemplo completo. O exemplo chama o `count_primes` função e o `count_primes_filter` função.

[!code-cpp[concrt-primes-filter#3](../../parallel/concrt/codesnippet/cpp/how-to-use-a-message-block-filter_3.cpp)]

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `primes-filter.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**cl.exe /EHsc primes-filter.cpp**

## <a name="robust-programming"></a>Programação robusta

Uma função de filtro pode ser uma função lambda, um ponteiro de função ou um objeto de função. Cada função de filtro usa uma das seguintes formas:

```Output
bool (T)
bool (T const &)
```

Para eliminar a cópia desnecessária de dados, use o segundo formulário quando você tem um tipo de agregação que é transmitido por valor.

## <a name="see-also"></a>Consulte também

[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Passo a passo: Criando um agente de fluxo de dados](../../parallel/concrt/walkthrough-creating-a-dataflow-agent.md)<br/>
[Passo a passo: Criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md)<br/>
[Classe transformer](../../parallel/concrt/reference/transformer-class.md)
