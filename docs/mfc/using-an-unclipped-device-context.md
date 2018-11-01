---
title: Usando um contexto de dispositivo não recortado
ms.date: 11/04/2016
helpviewer_keywords:
- MFC ActiveX controls [MFC], unclipped device context
ms.assetid: 9c020063-73da-4803-bf7b-2e1fd950c9ed
ms.openlocfilehash: 222a3fb60d07176b1ba8e586e142865164bc215f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50596502"
---
# <a name="using-an-unclipped-device-context"></a>Usando um contexto de dispositivo não recortado

Se você tiver certeza de que seu controle não pintado fora seu retângulo do cliente, você pode perceber um ganho de velocidade pequena, mas podem ser detectados desabilitando a chamada para `IntersectClipRect` que é feita por `COleControl`. Para fazer isso, remova os *clipPaintDC* sinalizador do conjunto de sinalizadores retornado por [COleControl::GetControlFlags](../mfc/reference/colecontrol-class.md#getcontrolflags). Por exemplo:

[!code-cpp[NVC_MFC_AxOpt#5](../mfc/codesnippet/cpp/using-an-unclipped-device-context_1.cpp)]
[!code-cpp[NVC_MFC_AxOpt#14](../mfc/codesnippet/cpp/using-an-unclipped-device-context_2.cpp)]
[!code-cpp[NVC_MFC_AxOpt#7](../mfc/codesnippet/cpp/using-an-unclipped-device-context_3.cpp)]

O código para remover esse sinalizador é gerado automaticamente se você selecionar o **contexto de dispositivo não recortado** opção a [configurações de controle](../mfc/reference/control-settings-mfc-activex-control-wizard.md) página, ao criar seu controle com o Assistente de controle de ActiveX do MFC.

Se você estiver usando a ativação sem janelas, essa otimização não tem nenhum efeito.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC: otimização](../mfc/mfc-activex-controls-optimization.md)

