---
title: Usando um contexto de dispositivo não recortado | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC ActiveX controls [MFC], unclipped device context
ms.assetid: 9c020063-73da-4803-bf7b-2e1fd950c9ed
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8c76dc44993615e17ea3d99f9ac018a748e24d0a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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

