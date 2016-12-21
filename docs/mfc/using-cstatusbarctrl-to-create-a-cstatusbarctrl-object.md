---
title: "Usando CStatusBarCtrl para criar um objeto CStatusBarCtrl | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CStatusBarCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CStatusBarCtrl, criando"
  - "controles da barra de status, criando"
ms.assetid: 365c2b65-12de-49e6-9a2e-416c6ee10d60
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando CStatusBarCtrl para criar um objeto CStatusBarCtrl
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Eis um exemplo de um uso típico de [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md):  
  
### Para usar um controle da barra de status com partes  
  
1.  Construir o objeto de `CStatusBarCtrl` .  
  
2.  Chame [SetMinHeight](../Topic/CStatusBarCtrl::SetMinHeight.md) se desejar definir a altura mínima da área de desenho do controle da barra de status.  
  
3.  Chame [SetBkColor](../Topic/CStatusBarCtrl::SetBkColor.md) para definir a cor do plano de fundo do controle da barra de status.  
  
4.  Chame [SetParts](../Topic/CStatusBarCtrl::SetParts.md) para definir o número de peças em um controle da barra de status e a coordenada da borda direita de cada parte.  
  
5.  Chame [SetText](../Topic/CStatusBarCtrl::SetText.md) para definir o texto em uma parte do controle da barra de status.  A mensagem invalida a parte de controle que foi alterada, fazendo com que exibe o novo texto quando o controle após receber a mensagem de `WM_PAINT` .  
  
 Em alguns casos, a barra de status somente de exibir uma linha de texto.  Nesse caso, chame um a [SetSimple](../Topic/CStatusBarCtrl::SetSimple.md).  Isso coloca o controle da barra de status no modo “simples”, que exibe uma única linha de texto.  
  
## Consulte também  
 [Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)