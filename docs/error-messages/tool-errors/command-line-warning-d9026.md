---
title: "Aviso D9026 (linha de comando) | Microsoft Docs"
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
  - "D9026"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "D9026"
ms.assetid: 149fe5e3-5329-4be8-b871-49dfd423aaba
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso D9026 (linha de comando)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

as opções se aplicam à linha de comando inteira  
  
 Uma opção tiver sido especificada em um comando depois que um nome de arquivo foi especificado.  A opção foi aplicada ao arquivo que precedeu a.  
  
 Por exemplo, no comando  
  
```  
CL verdi.c /G5 puccini.c  
```  
  
 o arquivo VERDI.c será criado com a opção \/G5, não a opção \/G4.  
  
 Esse comportamento é diferente de algumas versões anteriores, que foram aplicados somente as opções especificadas antes do nome de arquivo, resultando em VERDI.c que está sendo criado usando \/G4 e PUCCINI.c sendo compilados usando \/G5.