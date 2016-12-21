---
title: "Opera&#231;&#245;es de fluxo em controles de edi&#231;&#227;o avan&#231;ada | Microsoft Docs"
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
  - "Classe CRichEditCtrl, operações no fluxo"
  - "Classe CRichEditCtrl, armazenamento de fluxo"
  - "controles de edição avançada, operações no fluxo"
  - "armazenamento, fluxo em CRichEditCtrl"
  - "operações de fluxo em CRichEditCtrl"
  - "armazenamento de fluxo e CRichEditCtrl"
ms.assetid: 110b4684-1e76-4ca6-9ef0-5bc8b2d93c78
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Opera&#231;&#245;es de fluxo em controles de edi&#231;&#227;o avan&#231;ada
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode usar fluxos para transferir dados dentro ou fora de um controle de edição avançado \([CRichEditCtrl](../Topic/CRichEditCtrl%20Class.md)\).  Um fluxo é definido por uma estrutura de [EDITSTREAM](http://msdn.microsoft.com/library/windows/desktop/bb787891) , que especifica um buffer e uma função de retorno de chamada definida pelo aplicativo.  
  
 Para ler dados em um controle de edição avançado \(ou seja, transmitir os dados no\), use a função de membro de [StreamIn](../Topic/CRichEditCtrl::StreamIn.md) .  O controle repetidamente chama a função de retorno de chamada definida pelo aplicativo, que transfere uma parte dos dados no buffer cada vez.  
  
 Para salvar o conteúdo de um controle de edição avançado \(ou seja, transmitir os dados para fora\), você pode usar a função de membro de [StreamOut](../Topic/CRichEditCtrl::StreamOut.md) .  Grava o controle repetidamente para o buffer e chame a função de retorno de chamada definida pelo aplicativo.  Para cada chamada, a função de retorno de chamada salva o conteúdo do buffer.  
  
## Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)