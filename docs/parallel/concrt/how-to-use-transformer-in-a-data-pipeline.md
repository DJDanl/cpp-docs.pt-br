---
title: 'Como: Usar transformador em um Pipeline de dados'
ms.date: 11/04/2016
helpviewer_keywords:
- transformer class, example
- data pipelines, using transformer [Concurrency Runtime]
- using transformer in data pipelines [Concurrency Runtime]
ms.assetid: ca49cb3f-4dab-4b09-a9c9-d3a109ae4c29
ms.openlocfilehash: 59c4854eea985b3c91fad6e7dc6c47ca9b07d333
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62375581"
---
# <a name="how-to-use-transformer-in-a-data-pipeline"></a>Como: Usar transformador em um Pipeline de dados

Este tópico contém um exemplo básico que mostra como usar o [Concurrency:: Transformer](../../parallel/concrt/reference/transformer-class.md) classe em um pipeline de dados. Para obter um exemplo mais completo que usa um pipeline de dados para executar o processamento de imagens, consulte [passo a passo: Criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md).

*O pipelining dados* é um padrão comum na programação simultânea. Um pipeline de dados consiste em uma série de estágios, onde cada estágio executa o trabalho e, em seguida, passa o resultado desse trabalho para o próximo estágio. O `transformer` classe pipelines de um componente-chave nos dados, porque ele recebe um valor de entrada, executa o trabalho nesse valor e, em seguida, produz um resultado para outro componente para usar.

## <a name="example"></a>Exemplo

Este exemplo usa o pipeline de dados a seguir para executar uma série de transformações de receber um valor de entrada inicial:

1. O primeiro estágio calcula o valor absoluto de sua entrada.

1. O segundo estágio calcula a raiz quadrada de sua entrada.

1. O terceiro estágio calcula o quadrado de sua entrada.

1. O para trás estágio nega sua entrada.

1. O quinto estágio grava o resultado final em um buffer de mensagem.

Por fim, o exemplo imprime o resultado do pipeline para o console.

[!code-cpp[concrt-data-pipeline#1](../../parallel/concrt/codesnippet/cpp/how-to-use-transformer-in-a-data-pipeline_1.cpp)]

Este exemplo gera a seguinte saída:

```Output
The result is -42.
```

É comum para um estágio em um pipeline de dados para um valor cujo tipo é diferente de seu valor de entrada de saída. Neste exemplo, o segundo estágio usa um valor do tipo `int` como sua entrada e produz a raiz quadrada do valor (uma `double`) como sua saída.

> [!NOTE]
>  O pipeline de dados neste exemplo é para fins ilustrativos. Como cada operação de transformação realiza um pouco de trabalho, a sobrecarga que é necessário para executar a transmissão de mensagens pode superar os benefícios de usar um pipeline de dados.

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `data-pipeline.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.

**dados de /EHsc cl.exe-pipeline.cpp**

## <a name="see-also"></a>Consulte também

[Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Passo a passo: Criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md)
