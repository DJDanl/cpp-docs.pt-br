---
title: "Usando um contexto de dispositivo não recortado | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: MFC ActiveX controls [MFC], unclipped device context
ms.assetid: 9c020063-73da-4803-bf7b-2e1fd950c9ed
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ae095b59b07132bd7e4c6892b8e58d9e69fb39c9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-an-unclipped-device-context"></a>Usando um contexto de dispositivo não recortado
Se você tiver certeza de que o controle não pintado fora o retângulo de cliente, você pode obter um ganho de velocidade pequeno, mas podem ser detectados, desabilitando a chamada para `IntersectClipRect` feita por `COleControl`. Para fazer isso, remova o **clipPaintDC** sinalizador do conjunto de sinalizadores retornado por [COleControl::GetControlFlags](../mfc/reference/colecontrol-class.md#getcontrolflags). Por exemplo:  
  
 [!code-cpp[NVC_MFC_AxOpt#5](../mfc/codesnippet/cpp/using-an-unclipped-device-context_1.cpp)]  
[!code-cpp[NVC_MFC_AxOpt#14](../mfc/codesnippet/cpp/using-an-unclipped-device-context_2.cpp)]  
[!code-cpp[NVC_MFC_AxOpt#7](../mfc/codesnippet/cpp/using-an-unclipped-device-context_3.cpp)]  
  
 O código para remover esse sinalizador é gerado automaticamente se você selecionar o **o contexto de dispositivo não recortado** opção o [configurações de controle](../mfc/reference/control-settings-mfc-activex-control-wizard.md) página, ao criar o controle com o Assistente de controle ActiveX MFC.  
  
 Se você estiver usando a ativação sem janelas, essa otimização não tem nenhum efeito.  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC: otimização](../mfc/mfc-activex-controls-optimization.md)

