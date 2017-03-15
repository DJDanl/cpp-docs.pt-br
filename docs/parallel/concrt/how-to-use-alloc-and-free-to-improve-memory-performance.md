---
title: "Como usar Alloc e Free para melhorar o desempenho da mem&#243;ria | Microsoft Docs"
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
  - "ALLOC e Free, usando [tempo de execução de simultaneidade]"
  - "Usando Alloc e Free [Tempo de Execução de Simultaneidade]"
ms.assetid: e1fab9e8-a97d-4104-bead-e95958db79f9
caps.latest.revision: 14
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como usar Alloc e Free para melhorar o desempenho da mem&#243;ria
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este documento mostra como usar as funções de [concurrency::Alloc](../Topic/Alloc%20Function.md) e de [concurrency::Free](../Topic/Free%20Function.md) para melhorar o desempenho de memória.  Compara o tempo necessário para inverter em paralelo os elementos de uma matriz para três tipos diferentes cada um que especifica os operadores de `new` e de `delete` .  
  
 As funções de `Alloc` e de `Free` são mais úteis quando vários threads chamam frequentemente `Alloc` e `Free`.  O tempo de execução contém um cachê de memória separado para cada thread; consequentemente, o tempo de execução gerencia a memória sem o uso de bloqueios ou de barreiras de memória.  
  
## Exemplo  
 O exemplo a seguir mostra três tipos que cada um especifica os operadores de `new` e de `delete` .  A classe de `new_delete` usa `new` e os operadores globais de `delete` , a classe de `malloc_free` usa o tempo de execução [malloc](../../c-runtime-library/reference/malloc.md) C e funções de [livre](../../c-runtime-library/reference/free.md) , e a classe de `Alloc_Free` usa o tempo de execução `Alloc` de simultaneidade e funções de `Free` .  
  
 [!CODE [concrt-allocators#1](../CodeSnippet/VS_Snippets_ConcRT/concrt-allocators#1)]  
  
## Exemplo  
 O exemplo a seguir mostra as funções `swap` e `reverse_array`.  A função de `swap` troca o conteúdo da matriz de índices especificados.  Aloca memória do heap para a variável temporário.  A função de `reverse_array` cria uma matriz e computa o tempo necessário para inverter em paralelo que matriz várias vezes.  
  
 [!CODE [concrt-allocators#2](../CodeSnippet/VS_Snippets_ConcRT/concrt-allocators#2)]  
  
## Exemplo  
 O exemplo a seguir mostra a função de `wmain` , que calcula o tempo necessário para que a função de `reverse_array` atue em `new_delete`, em `malloc_free`, e em tipos de `Alloc_Free` , que usa um esquema de alocação de memória diferente.  
  
 [!CODE [concrt-allocators#3](../CodeSnippet/VS_Snippets_ConcRT/concrt-allocators#3)]  
  
## Exemplo  
 O exemplo completo a seguir.  
  
 [!CODE [concrt-allocators#4](../CodeSnippet/VS_Snippets_ConcRT/concrt-allocators#4)]  
  
 Este exemplo gerencia a seguinte saída de exemplo para um computador que tem quatro processadores.  
  
  **Tomou a 2031 ms com novo\/exclusão.**  
**Tomou a 1672 ms com malloc\/livre.**  
**Tomou a 656 ms com alocação A ID\/livre.** Neste exemplo, o tipo usando as funções de `Alloc` e de `Free` fornece desempenho melhor de memória porque as funções de `Alloc` e de `Free` são otimizadas frequentemente atribuindo e liberando bloqueios de memória de vários threads.  
  
## Compilando o código  
 Copie o código de exemplo e cole\-o em um projeto do Visual Studio, ou cole\-o em um arquivo chamado `allocators.cpp` e execute o comando a seguir em uma janela de prompt de comando do Visual Studio.  
  
 **cl.exe \/EHsc allocators.cpp**  
  
## Consulte também  
 [Funções de gerenciamento da memória](../Topic/Memory%20Management%20Functions.md)   
 [Função Alloc](../Topic/Alloc%20Function.md)   
 [Função livre](../Topic/Free%20Function.md)