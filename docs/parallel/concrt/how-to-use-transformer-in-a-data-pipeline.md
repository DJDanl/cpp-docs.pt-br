---
title: 'Como: usar transformador em um Pipeline de dados | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- transformer class, example
- data pipelines, using transformer [Concurrency Runtime]
- using transformer in data pipelines [Concurrency Runtime]
ms.assetid: ca49cb3f-4dab-4b09-a9c9-d3a109ae4c29
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 76c8a50bd5a58d9fe6e4a68f05d9732e50fd04e8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-use-transformer-in-a-data-pipeline"></a>Como usar transformador em um pipeline de dados
Este tópico contém um exemplo básico que mostra como usar o [concurrency::transformer](../../parallel/concrt/reference/transformer-class.md) classe em um pipeline de dados. Para obter um exemplo mais completo que usa um pipeline de dados para executar o processamento de imagens, consulte [passo a passo: Criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md).  
  
 *Processamento de dados* é um padrão comum na programação simultânea. Um pipeline de dados consiste em uma série de etapas, onde cada estágio executa o trabalho e, em seguida, passa o resultado desse trabalho para o próximo estágio. O `transformer` classe pipelines de um componente fundamental dados porque ele recebe um valor de entrada, executa um trabalho por esse valor e, em seguida, gera um resultado para outro componente para usar.  
  
## <a name="example"></a>Exemplo  
 Este exemplo usa o pipeline de dados a seguir para executar uma série de transformações que recebe um valor de entrada inicial:  
  
1.  O primeiro estágio calcula o valor absoluto de sua entrada.  
  
2.  O segundo estágio calcula a raiz quadrada de sua entrada.  
  
3.  A terceira etapa calcula o quadrado de sua entrada.  
  
4.  O sucessivamente estágio nega sua entrada.  
  
5.  O quinto estágio grava o resultado final em um buffer de mensagem.  
  
 Por fim, o exemplo imprime o resultado de pipeline para o console.  
  
 [!code-cpp[concrt-data-pipeline#1](../../parallel/concrt/codesnippet/cpp/how-to-use-transformer-in-a-data-pipeline_1.cpp)]  
  
 Este exemplo gera a seguinte saída:  
  
```Output  
The result is -42.  
```  
  
 É comum para um estágio em um pipeline de dados para um valor cujo tipo é diferente do valor de entrada de saída. Neste exemplo, o segundo estágio usa um valor do tipo `int` como entrada e produz a raiz quadrada do valor (uma `double`) como sua saída.  
  
> [!NOTE]
>  O pipeline de dados neste exemplo é para fins ilustrativos. Como cada operação de transformação realiza um pouco de trabalho, a sobrecarga que é necessário para executar a transmissão de mensagens pode superar os benefícios do uso de um pipeline de dados.  
  
## <a name="compiling-the-code"></a>Compilando o código  
 Copie o código de exemplo e cole-o em um projeto do Visual Studio ou colá-lo em um arquivo chamado `data-pipeline.cpp` e, em seguida, execute o seguinte comando em uma janela de Prompt de comando do Visual Studio.  
  
 **dados de /EHsc cl.exe-pipeline.cpp**  
  
## <a name="see-also"></a>Consulte também  
 [Biblioteca de agentes assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Instruções passo a passo: criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md)

