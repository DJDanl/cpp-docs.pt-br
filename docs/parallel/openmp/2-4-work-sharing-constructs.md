---
title: 2.4 construtos work-sharing | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 25bb4ded-8466-4daa-a863-766b5a99b995
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c00eb94055f26954a283a6172f69228804832ac4
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33689630"
---
# <a name="24-work-sharing-constructs"></a>2.4 Construtos Work-sharing
Uma construção de compartilhamento em trabalho distribui a execução da instrução associada entre os membros da equipe que encontrou. As diretivas de compartilhamento de trabalho não iniciar novos threads e não há nenhum barreira implícita na entrada para uma construção de compartilhamento de trabalho.  
  
 A sequência de trabalho de compartilhamento Constrói e **barreira** diretivas encontradas devem ser o mesmo para todos os threads em uma equipe.  
  
 OpenMP define as seguintes construções de compartilhamento de trabalho, e elas são descritas nas seções a seguir:  
  
-   **para** diretiva  
  
-   **seções** diretiva  
  
-   **único** diretiva