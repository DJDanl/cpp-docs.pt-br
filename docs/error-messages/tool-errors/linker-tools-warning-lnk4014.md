---
title: "Aviso LNK4014 (Ferramentas de Vinculador) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "LNK4014"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4014"
ms.assetid: 394903e9-3ded-4ea4-b7c0-a3535d4b4da4
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4014 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não é possível encontrar o objeto “objectname” do membro  
  
 O LIB não foi possível encontrar `objectname` na biblioteca.  
  
 As opções de **\/REMOVE** e de **\/EXTRACT** exigem o nome completo do objeto do membro que deve ser excluído ou copiado em um arquivo.  O nome completo inclui o caminho do arquivo de objeto original.  Para ver os nomes completos de objetos do membro em uma biblioteca, use o DUMPBIN [\/ARCHIVEMEMBERS](../Topic/-ARCHIVEMEMBERS.md) ou o LIB [\/LIST](../../build/reference/managing-a-library.md).