---
title: "Expans&#227;o de curinga | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "_setargv"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função _setargv"
  - "curinga asterisco"
  - "linha de comando, processando argumentos"
  - "linha de comando, curingas"
  - "curingas de linha de comando"
  - "ponto de interrogação, curinga"
ms.assetid: 1a543398-607b-4404-93d1-45d290bde638
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Expans&#227;o de curinga
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 Você pode usar caracteres curinga — o ponto de interrogação \(?\) e o asterisco \(\*\) — para especificar argumentos de nome de arquivo e caminho na linha de comando.  
  
 Os argumentos de linha de comando são tratados por uma rotina chamada **\_setargv** \(ou **\_wsetargv** no ambiente de caractere largo\) que, por padrão, não expande curingas em cadeias de caracteres separadas na matriz de cadeia de caracteres `argv`.  Para obter mais informações sobre como habilitar a expansão de curingas, consulte [Expandindo argumentos de curinga](../Topic/Expanding%20Wildcard%20Arguments.md).  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [main: inicialização do programa](../Topic/main:%20Program%20Startup.md)