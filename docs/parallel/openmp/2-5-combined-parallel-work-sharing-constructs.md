---
title: "2.5 combinados construções de compartilhamento de trabalho paralelas | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 45936e5a-c62a-4eea-a8f4-232210c9d0c8
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 8bacf3ebdf975c1065242b7f88e110c3b6c9c5c5
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="25-combined-parallel-work-sharing-constructs"></a>2.5 Constructos de compartilhamento de trabalho em paralelo combinado
Combinado construções de compartilhamento de trabalho paralelas são atalhos para especificar uma região parallel que contém somente uma construção de compartilhamento de trabalho. A semântica essas diretivas é idêntica de especificar explicitamente um **paralela** diretiva seguido por uma construção de compartilhamento em trabalho único.  
  
 As seções a seguir descrevem as construções de compartilhamento em trabalho paralelas combinadas:  
  
-   o **paralelo para** diretiva.  
  
-   o **paralelo seções** diretiva.