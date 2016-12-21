---
title: "Gerenciamento de mem&#243;ria: blocos de mem&#243;ria redimension&#225;veis | Microsoft Docs"
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
  - "blocos, alocação de memória"
  - "alocação de memória, tamanho do bloco de memória"
  - "blocos de memória, alocando"
  - "blocos de memória, redimensionável"
  - "memória, corrompimento"
  - "blocos de memória redimensionáveis"
ms.assetid: f0efe6f4-a3ed-4541-9195-51ec1291967a
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Gerenciamento de mem&#243;ria: blocos de mem&#243;ria redimension&#225;veis
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os operadores de **new** e de **delete** , descrito no artigo [Gerenciamento de memória: Exemplos](../mfc/memory-management-examples.md), são boas o aloque e desaloque blocos e objetos de memória de tamanho fixo.  Ocasionalmente, o aplicativo pode precisar blocos de memória redimensionável.  Você deve usar as funções da biblioteca padrão [malloc](../c-runtime-library/reference/malloc.md), [realloc](../c-runtime-library/reference/realloc.md), e [livre](../c-runtime-library/reference/free.md) de tempo de execução C para gerenciar blocos de memória redimensionável no heap.  
  
> [!IMPORTANT]
>  Misturar os operadores de **new** e de **delete** com as funções de alocação de memória redimensionável no mesmo bloco de memória resultará na memória corrompido na versão de depuração MFC.  Você não deve usar `realloc` em um bloco de memória alocado a **new**.  Também, você não deve atribuir um bloco de memória com o operador de **new** e exclua\-o com **free**, ou usar o operador de **delete** em um bloco de memória alocado a `malloc`.  
  
## Consulte também  
 [Gerenciamento de memória: alocação do heap](../mfc/memory-management-heap-allocation.md)