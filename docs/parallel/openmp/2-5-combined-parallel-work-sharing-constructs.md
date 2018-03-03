---
title: "2.5 combinados construções de compartilhamento de trabalho paralelas | Microsoft Docs"
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
ms.assetid: 45936e5a-c62a-4eea-a8f4-232210c9d0c8
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 423524c407f829200684e55130df4472e70cbe5c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="25-combined-parallel-work-sharing-constructs"></a>2.5 Constructos de compartilhamento de trabalho em paralelo combinado
Combinado construções de compartilhamento de trabalho paralelas são atalhos para especificar uma região parallel que contém somente uma construção de compartilhamento de trabalho. A semântica essas diretivas é idêntica de especificar explicitamente um **paralela** diretiva seguido por uma construção de compartilhamento em trabalho único.  
  
 As seções a seguir descrevem as construções de compartilhamento em trabalho paralelas combinadas:  
  
-   o **paralelo para** diretiva.  
  
-   o **paralelo seções** diretiva.