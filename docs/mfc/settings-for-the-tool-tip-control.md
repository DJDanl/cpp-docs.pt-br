---
title: "Configura&#231;&#245;es para o controle da dica de ferramenta | Microsoft Docs"
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
  - "Classe CToolTipCtrl, configurações"
  - "dicas de ferramenta [C++], ativando"
ms.assetid: ff8c5c46-2047-403a-bd98-ffec3d21ee3a
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Configura&#231;&#245;es para o controle da dica de ferramenta
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode definir o controle da dica de ferramenta[CToolTipCtrl](../Topic/CToolTipCtrl%20Class.md)\(\) para ser ativo ou inativo.  Quando você defini\-lo como estar ativa, o controle da dica de ferramenta é exibida quando o cursor estiver em uma ferramenta.  Quando você defini\-lo a ser inativa, o controle da dica de ferramenta não aparecer, mesmo se o cursor estiver em uma ferramenta.  Chame [Ativar](../Topic/CToolTipCtrl::Activate.md) para ativar ou desativar um controle da dica de ferramenta.  
  
 Você pode definir uma dica de ferramenta ativas para exibir a dica de ferramenta quando o cursor estiver em uma ferramenta, mesmo se a janela do proprietário do controle da dica de ferramenta está ativo ou inativo, usando o estilo de **TTS\_ALWAYSTIP** .  Se você não usar esse estilo, o controle da dica de ferramenta é exibida quando a janela do proprietário de ferramenta está ativa, mas não quando está inativo.  
  
 A maioria dos aplicativos contêm barras de ferramentas com ferramentas que correspondem aos comandos de menu.  Para essas ferramentas, é conveniente para o controle da dica de ferramenta exibir o mesmo texto do item de menu correspondente.  O sistema retira automaticamente os caracteres de acelerador de E comercial \(&\) de todas as cadeias de caracteres transmitidas a um controle da dica de ferramenta, a menos que o controle tiver o estilo de **TTS\_NOPREFIX** .  
  
## Consulte também  
 [Usando CToolTipCtrl](../mfc/using-ctooltipctrl.md)   
 [Controles](../mfc/controls-mfc.md)