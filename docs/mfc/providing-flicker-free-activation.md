---
title: "Fornecendo ativa&#231;&#227;o sem cintila&#231;&#227;o | Microsoft Docs"
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
  - "ativação [C++], sem cintilação"
  - "cintilação, Controles ActiveX MFC"
  - "Controles ActiveX MFC [C++], sem cintilação"
ms.assetid: bcb24b77-31d8-44a0-8c58-2ea6213b4c43
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fornecendo ativa&#231;&#227;o sem cintila&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se o controle é desenha idêntica no estado inativo e ativas \(e não usa a ativação sem windows\), você pode eliminar as operações de desenho e a cintilação visual de rastreamento que ocorrem normalmente ao fazer a transição entre os estados ativas e inativas.  Para fazer isso, inclua o sinalizador de **noFlickerActivate** no conjunto de sinalizadores retornados por [COleControl::GetControlFlags](../Topic/COleControl::GetControlFlags.md).  Por exemplo:  
  
 [!code-cpp[NVC_MFC_AxOpt#5](../mfc/codesnippet/CPP/providing-flicker-free-activation_1.cpp)]  
[!code-cpp[NVC_MFC_AxOpt#13](../mfc/codesnippet/CPP/providing-flicker-free-activation_2.cpp)]  
[!code-cpp[NVC_MFC_AxOpt#7](../mfc/codesnippet/CPP/providing-flicker-free-activation_3.cpp)]  
  
 O código para incluir esse sinalizador é gerado automaticamente se você selecionar a opção de **Flicker\-Free activation** na página de [Controle configurações](../mfc/reference/control-settings-mfc-activex-control-wizard.md) ao criar seu controle com o assistente de controle ActiveX de MFC.  
  
 Se você estiver usando a ativação sem o windows, essa otimização não tem nenhum efeito.  
  
## Consulte também  
 [Controles ActiveX MFC: otimização](../mfc/mfc-activex-controls-optimization.md)