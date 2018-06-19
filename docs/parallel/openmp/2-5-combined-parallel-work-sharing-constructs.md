---
title: 2.5 combinados construções de compartilhamento de trabalho paralelas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 45936e5a-c62a-4eea-a8f4-232210c9d0c8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7aea758cbf43cd49affc01afda0e9f34c24b3331
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33689292"
---
# <a name="25-combined-parallel-work-sharing-constructs"></a>2.5 Constructos de compartilhamento de trabalho em paralelo combinado
Combinado construções de compartilhamento de trabalho paralelas são atalhos para especificar uma região parallel que contém somente uma construção de compartilhamento de trabalho. A semântica essas diretivas é idêntica de especificar explicitamente um **paralela** diretiva seguido por uma construção de compartilhamento em trabalho único.  
  
 As seções a seguir descrevem as construções de compartilhamento em trabalho paralelas combinadas:  
  
-   o **paralelo para** diretiva.  
  
-   o **paralelo seções** diretiva.