---
title: "Usando um contexto de dispositivo n&#227;o recortado | Microsoft Docs"
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
  - "Controles ActiveX MFC, contexto de dispositivo não recortado"
ms.assetid: 9c020063-73da-4803-bf7b-2e1fd950c9ed
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando um contexto de dispositivo n&#227;o recortado
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se você você tiver certeza de que o controle não pt fora do retângulo de cliente, você pode realizar um pequeno ganho mas detectável de velocidade desabilitando a chamada a `IntersectClipRect` que é feito por `COleControl`.  Para fazer isso, remova o sinalizador de **clipPaintDC** do conjunto de sinalizadores retornados por [COleControl::GetControlFlags](../Topic/COleControl::GetControlFlags.md).  Por exemplo:  
  
 [!code-cpp[NVC_MFC_AxOpt#5](../mfc/codesnippet/CPP/using-an-unclipped-device-context_1.cpp)]  
[!code-cpp[NVC_MFC_AxOpt#14](../mfc/codesnippet/CPP/using-an-unclipped-device-context_2.cpp)]  
[!code-cpp[NVC_MFC_AxOpt#7](../mfc/codesnippet/CPP/using-an-unclipped-device-context_3.cpp)]  
  
 O código para remover este sinalizador é gerado automaticamente se você selecionar a opção de **Unclipped Device Context** na página de [Controle configurações](../mfc/reference/control-settings-mfc-activex-control-wizard.md) , ao criar seu controle com o assistente de controle ActiveX de MFC.  
  
 Se você estiver usando a ativação sem o windows, essa otimização não tem nenhum efeito.  
  
## Consulte também  
 [Controles ActiveX MFC: otimização](../mfc/mfc-activex-controls-optimization.md)