---
title: "Alocando memória zero | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- memory allocation, zero memory
- zero memory
ms.assetid: 768f2ab9-83a1-4887-8eb5-c094c18489a8
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: 9708f8939ff32f9320e7c8e803753e801ce9448f
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="allocating-zero-memory"></a>Alocando memória igual a zero
**ANSI 4.10.3** O comportamento da função `calloc`,`malloc` ou `realloc`, se o tamanho solicitado é zero  
  
 As funções `calloc`, `malloc` e `realloc` aceitam zero como argumento. Nenhuma memória real é alocada, mas um ponteiro válido é retornado e o bloco de memória pode ser modificado mais tarde por realloc.  
  
## <a name="see-also"></a>Consulte também  
 [Funções de biblioteca](../c-language/library-functions.md)
