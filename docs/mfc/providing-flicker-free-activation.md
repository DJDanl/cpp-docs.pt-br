---
title: Fornecendo ativação sem cintilação
ms.date: 11/04/2016
helpviewer_keywords:
- MFC ActiveX controls [MFC], flicker-free
- flicker, MFC ActiveX controls
- activation [MFC], flicker-free
ms.assetid: bcb24b77-31d8-44a0-8c58-2ea6213b4c43
ms.openlocfilehash: fad24d6201260e87ff32436752a9fbf035e822ae
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57287668"
---
# <a name="providing-flicker-free-activation"></a>Fornecendo ativação sem cintilação

Se o controle se desenha identicamente nos estados ativos e inativos (e não usa ativação sem janelas), você poderá eliminar as operações de desenho e a cintilação de visual que acompanha este artigo que normalmente ocorrem ao fazer a transição entre o inativo e estados ativos. Para fazer isso, inclua o **noFlickerActivate** sinalizador no conjunto de sinalizadores retornado por [COleControl::GetControlFlags](../mfc/reference/colecontrol-class.md#getcontrolflags). Por exemplo:

[!code-cpp[NVC_MFC_AxOpt#5](../mfc/codesnippet/cpp/providing-flicker-free-activation_1.cpp)]
[!code-cpp[NVC_MFC_AxOpt#13](../mfc/codesnippet/cpp/providing-flicker-free-activation_2.cpp)]
[!code-cpp[NVC_MFC_AxOpt#7](../mfc/codesnippet/cpp/providing-flicker-free-activation_3.cpp)]

O código para incluir esse sinalizador é gerado automaticamente se você selecionar o **ativação sem cintilação** opção a [configurações de controle](../mfc/reference/control-settings-mfc-activex-control-wizard.md) página durante a criação de seu controle com o Assistente de controle de ActiveX do MFC.

Se você estiver usando a ativação sem janelas, essa otimização não tem nenhum efeito.

## <a name="see-also"></a>Consulte também

[Controles ActiveX MFC: Otimização](../mfc/mfc-activex-controls-optimization.md)
