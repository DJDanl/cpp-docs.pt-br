---
title: "Como usar transformador em um pipeline de dados | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classe Transformer, por exemplo:"
  - "pipelines de dados, usando transformador [tempo de execução de simultaneidade]"
  - "usando transformador em pipelines de dados [Tempo de Execução de Simultaneidade]"
ms.assetid: ca49cb3f-4dab-4b09-a9c9-d3a109ae4c29
caps.latest.revision: 16
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como usar transformador em um pipeline de dados
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico contém um exemplo básico que mostra como usar a classe de [concurrency::transformer](../../parallel/concrt/reference/transformer-class.md) em um pipeline de dados.  Para um mais o exemplo completo que usa um pipeline de dados para executar o processamento de imagem, consulte [Instruções passo a passo: criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md).  
  
 *O indicação de dados* é um padrão comum em programação simultâneo.  Um pipeline de dados consiste em uma série de etapas, em que cada fase executa o trabalho e passar o resultado do trabalho para o estágio seguir.  A classe de `transformer` um componente fundamental nos dados canaliza como recebe um valor de entrada, execute o trabalho nesse valor, e gerenciado em um resultado para que outro componente usar.  
  
## Exemplo  
 Este exemplo usa a seguinte pipeline de dados para executar uma série de transformações fornecidas um valor de entrada inicial:  
  
1.  A primeira fase calcula o valor absoluto de sua entrada.  
  
2.  A segunda etapa calcula a raiz quadrada da entrada.  
  
3.  A terceira fase computa o quadrado de sua entrada.  
  
4.  Se a fase nega a entrada.  
  
5.  A quinta fase grava o resultado final para um buffer de mensagem.  
  
 Finalmente, o exemplo a seguir imprime o resultado de pipeline no console.  
  
 [!CODE [concrt-data-pipeline#1](../CodeSnippet/VS_Snippets_ConcRT/concrt-data-pipeline#1)]  
  
 Este exemplo gera a seguinte saída:  
  
  **O resultado é \-42.** É comum para uma fase em um pipeline de dados para gerar um o valor cujo tipo seja diferente do valor de entrada.  Neste exemplo, a segunda etapa usa um valor do tipo `int` como entrada e gerencie a raiz quadrada desse valor `double`\(\) como sua saída.  
  
> [!NOTE]
>  O pipeline de dados neste exemplo é para ilustração.  Como cada operação de transformação executa vez trabalho, a sobrecarga necessária para executar mensagem\- passar pode aumentar os benefícios de usar um pipeline de dados.  
  
## Compilando o código  
 Copie o código de exemplo e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `data-pipeline.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe \/EHsc data\-pipeline.cpp**  
  
## Consulte também  
 [Biblioteca de Agentes Assíncronos](../../parallel/concrt/asynchronous-agents-library.md)   
 [Blocos de mensagens assíncronos](../../parallel/concrt/asynchronous-message-blocks.md)   
 [Instruções passo a passo: criando uma rede de processamento de imagem](../../parallel/concrt/walkthrough-creating-an-image-processing-network.md)