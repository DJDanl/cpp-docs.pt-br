---
title: Como usar transformador em um pipeline de dados
ms.date: 11/04/2016
helpviewer_keywords:
- transformer class, example
- data pipelines, using transformer [Concurrency Runtime]
- using transformer in data pipelines [Concurrency Runtime]
ms.assetid: ca49cb3f-4dab-4b09-a9c9-d3a109ae4c29
ms.openlocfilehash: 4eb490ecf51abea324f20395279bff2d74b7af77
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215849"
---
# <a name="how-to-use-transformer-in-a-data-pipeline"></a>Como usar transformador em um pipeline de dados

Este tópico contém um exemplo básico que mostra como usar a classe [Concurrency:: Transformer](../../parallel/concrt/reference/transformer-class.md) em um pipeline de dados. Para obter um exemplo mais completo que usa um pipeline de dados para executar o processamento de imagens, consulte [passo a passos: criando uma rede de processamento de imagens](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md).

O *pipeline de dados* é um padrão comum em programação simultânea. Um pipeline de dados consiste em uma série de estágios, onde cada estágio executa o trabalho e, em seguida, passa o resultado desse trabalho para o próximo estágio. A `transformer` classe a é um componente-chave em pipelines de dados porque recebe um valor de entrada, executa o trabalho nesse valor e, em seguida, produz um resultado para outro componente usar.

## <a name="example"></a>Exemplo

Este exemplo usa o pipeline de dados a seguir para executar uma série de transformações dadas um valor de entrada inicial:

1. O primeiro estágio calcula o valor absoluto de sua entrada.

1. O segundo estágio calcula a raiz quadrada de sua entrada.

1. O terceiro estágio calcula o quadrado de sua entrada.

1. O estágio em diante nega sua entrada.

1. O quinto estágio grava o resultado final em um buffer de mensagens.

Por fim, o exemplo imprime o resultado do pipeline para o console.

[!code-cpp[concrt-data-pipeline#1](../../parallel/concrt/codesnippet/cpp/how-to-use-transformer-in-a-data-pipeline_1.cpp)]

Esse exemplo gera a saída a seguir:

```Output
The result is -42.
```

É comum que um estágio em um pipeline de dados gere um valor cujo tipo difere do seu valor de entrada. Neste exemplo, o segundo estágio usa um valor do tipo **`int`** como sua entrada e produz a raiz quadrada desse valor (a **`double`** ) como sua saída.

> [!NOTE]
> O pipeline de dados neste exemplo é para ilustração. Como cada operação de transformação realiza pouco trabalho, a sobrecarga necessária para executar a passagem de mensagens pode superar os benefícios de usar um pipeline de dados.

## <a name="compiling-the-code"></a>Compilando o código

Copie o código de exemplo e cole-o em um projeto do Visual Studio ou cole-o em um arquivo chamado `data-pipeline.cpp` e, em seguida, execute o comando a seguir em uma janela de prompt de comando do Visual Studio.

> **cl.exe/EHsc data-pipeline. cpp**

## <a name="see-also"></a>Confira também

[Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)<br/>
[Blocos de mensagens assíncronas](../../parallel/concrt/asynchronous-message-blocks.md)<br/>
[Walkthrough: criando uma rede de processamento de imagens](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md)
