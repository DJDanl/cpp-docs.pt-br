---
title: "Quebras de palavra em controles de edi&#231;&#227;o avan&#231;ada | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "quebrando palavras em CRichEditCtrl"
  - "Classe CRichEditCtrl, quebras de palavras em"
  - "controles de edição avançada, quebras de palavras em"
  - "quebras de palavras"
ms.assetid: 641dcf9e-7b40-4dc0-85f7-575a8c142f73
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Quebras de palavra em controles de edi&#231;&#227;o avan&#231;ada
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um controle de edição avançado \([CRichEditCtrl](../Topic/CRichEditCtrl%20Class.md)\) chama uma função chamada de um procedimento “quebra de palavras” para localizar quebras entre palavras e para determinar onde pode linhas de interrupção.  O controle usa essas informações para executar operações de quebra automática de linha e processar as combinações de tecla de CTRL\+LEFT e de CTRL\+RIGHT.  Um aplicativo pode enviar mensagens a um controle de edição avançado para substituir o procedimento padrão de separação de palavras, para recuperar informações de separação de palavras, e para determinar qual linha um caractere dado falha.  
  
## Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)