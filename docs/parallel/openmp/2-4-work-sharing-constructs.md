---
title: 2.4 construtos work-sharing | Microsoft Docs
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
ms.assetid: 25bb4ded-8466-4daa-a863-766b5a99b995
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 476e4e23b22527accaa095d80b827c95aed58c15
ms.sourcegitcommit: 9239c52c05e5cd19b6a72005372179587a47a8e4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2018
---
# <a name="24-work-sharing-constructs"></a>2.4 Construtos Work-sharing
Uma construção de compartilhamento em trabalho distribui a execução da instrução associada entre os membros da equipe que encontrou. As diretivas de compartilhamento de trabalho não iniciar novos threads e não há nenhum barreira implícita na entrada para uma construção de compartilhamento de trabalho.  
  
 A sequência de trabalho de compartilhamento Constrói e **barreira** diretivas encontradas devem ser o mesmo para todos os threads em uma equipe.  
  
 OpenMP define as seguintes construções de compartilhamento de trabalho, e elas são descritas nas seções a seguir:  
  
-   **para** diretiva  
  
-   **seções** diretiva  
  
-   **único** diretiva