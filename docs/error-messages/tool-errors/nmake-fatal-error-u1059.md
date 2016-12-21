---
title: "Erro fatal U1059 (NMAKE) | Microsoft Docs"
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
  - "U1059"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "U1059"
ms.assetid: b21d9198-9c63-40d0-b589-80e17294ce24
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal U1059 (NMAKE)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

erro de sintaxe: “}” ausentes em dependente  
  
 Um caminho de pesquisa para um dependente tiver sido especificado incorretamente.  Um espaço ou existia no caminho ou a chave de fechamento \(**}**\) foi omitida.  
  
 A sintaxe para uma especificação do diretório para um é dependente  
  
 **{**   
 ***directories* }dependent**  
  
 onde `directories` especifica um ou mais caminhos, cada um separados por um ponto\-e\-vírgula \(**;**\).  Nenhum espaço é permitido.  
  
 Se a parte ou qualquer caminho de pesquisa são substituídos por uma macro, não se certifique de nenhum espaço existir em expansão macro.