---
title: "Erro fatal U1056 (NMAKE) | Microsoft Docs"
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
  - "U1056"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "U1056"
ms.assetid: da855728-b69e-413c-83ed-df912126215e
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal U1056 (NMAKE)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não é possível encontrar o processador de comando  
  
 O processador de comando não estava no caminho especificado em variáveis de ambiente de **COMSPEC** ou de **CAMINHO** .  
  
 NMAKE usa COMMAND.COM ou CMD.EXE como um processador de comando para executar comandos.  Procurar o processador de comando primeiro no caminho definido em **COMSPEC**.  Se **COMSPEC** não existir, NMAKE pesquisa os diretórios especificados em **CAMINHO**.