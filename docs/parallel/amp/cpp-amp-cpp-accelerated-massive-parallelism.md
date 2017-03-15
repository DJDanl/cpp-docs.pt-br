---
title: "C++ AMP (C++ Accelerated Massive Parallelism) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
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
  - "C++ Accelerated Massive Parallelism, guia de introdução"
  - "C++ AMP (consulte C++ Accelerated Massive Parallelism)"
ms.assetid: e27824cb-3167-409b-8c3f-a0e476d8f349
caps.latest.revision: 22
caps.handback.revision: 21
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# C++ AMP (C++ Accelerated Massive Parallelism)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O C\+\+ AMP \(C\+\+ Accelerated Massive Parallelism\) acelera a execução do seu código C\+\+, tirando proveito do hardware de dados paralelos comumente apresentado como uma unidade de processamento gráfico \(GPU, Graphics Processing Unit\) em uma placa gráfica discreta.  O modelo de programação C\+\+ AMP inclui suporte para matrizes multidimensionais, indexação, transferência de memória e disposição lado a lado.  Também inclui uma biblioteca de funções matemáticas.  Você pode usar extensões de idioma do C\+\+ AMP para controlar como os dados são movidos da CPU para a GPU e vice\-versa.  
  
## Tópicos relacionados  
  
|Nome|Descrição|  
|----------|---------------|  
|[Visão geral do C\+\+ AMP](../../parallel/amp/cpp-amp-overview.md)|Descreve os principais recursos do C\+\+ AMP e a biblioteca matemática.|  
|[Usando lambdas, objetos de função e funções restritas](../../parallel/amp/using-lambdas-function-objects-and-restricted-functions.md)|Descreve como usar expressões lambda, objetos da função e funções restritas em chamadas para o método [parallel\_for\_each](../Topic/parallel_for_each%20Function%20\(C++%20AMP\).md).|  
|[Usando blocos](../../parallel/amp/using-tiles.md)|Descreve como usar tiles para acelerar seu código C\+\+ AMP.|  
|[Usando objetos accelerator e accelerator\_view](../../parallel/amp/using-accelerator-and-accelerator-view-objects.md)|Descreve como usar aceleradores para personalizar a execução do código na GPU.|  
|[Usando C\+\+ AMP em aplicativos da Windows Store](../../parallel/amp/using-cpp-amp-in-windows-store-apps.md)|Descreve como usar C\+\+ AMP em aplicativos [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] que usam tipos de Tempo de Execução do Windows.|  
|[Elementos gráficos \(C\+\+ AMP\)](../../parallel/amp/graphics-cpp-amp.md)|Descreve como usar a biblioteca de elementos gráficos do C\+\+ AMP.|  
|[Instruções passo a passo: multiplicação de matrizes](../../parallel/amp/walkthrough-matrix-multiplication.md)|Demonstra a multiplicação de matriz usando código de C\+\+ AMP e tiling.|  
|[Instruções passo a passo: depurando um aplicativo C\+\+ AMP](../../parallel/amp/walkthrough-debugging-a-cpp-amp-application.md)|Explica como criar e depurar um aplicativo que usa a redução paralela para somar uma grande matriz de inteiros.|  
  
## Referência  
 [Referência \(C\+\+ AMP\)](../../parallel/amp/reference/reference-cpp-amp.md)  
  
 [Palavra\-chave tile\_static](../Topic/tile_static%20Keyword.md)  
  
 [restrita \(C\+\+ AMP\)](../../cpp/restrict-cpp-amp.md)  
  
## Outros recursos  
 [Blog Programação Paralela no Código Nativo](http://go.microsoft.com/fwlink/p/?LinkId=238472)  
  
 [Projetos de exemplo do C\+\+ AMP para download](http://go.microsoft.com/fwlink/p/?LinkId=248508)  
  
 [Analisar o código AMP de C\+\+ com o Visualizador de Concorrência](http://go.microsoft.com/fwlink/?LinkID=253987&clcid=0x409)