---
title: Fornecendo interação do Mouse enquanto inativo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC ActiveX controls [MFC], mouse interaction
ms.assetid: b09106bf-44c7-4b9b-a6d9-0d624f16f5b3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: faf1ea1958d6a6381bbe1c6e7d3db26f5f5b7c17
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33349668"
---
# <a name="providing-mouse-interaction-while-inactive"></a>Fornecendo interação do mouse enquanto inativo
Se o controle não está ativado imediatamente, talvez seja melhor para processar `WM_SETCURSOR` e `WM_MOUSEMOVE` mensagens, mesmo que o controle não tem nenhuma janela de seu próprio. Isso pode ser feito Ativando `COleControl`da implementação do `IPointerInactive` interface, que é desabilitada por padrão. (Consulte o *ActiveX SDK* para obter uma descrição dessa interface.) Para habilitá-lo, incluem o `pointerInactive` sinalizador no conjunto de sinalizadores retornado por [COleControl::GetControlFlags](../mfc/reference/colecontrol-class.md#getcontrolflags):  
  
 [!code-cpp[NVC_MFC_AxOpt#5](../mfc/codesnippet/cpp/providing-mouse-interaction-while-inactive_1.cpp)]  
[!code-cpp[NVC_MFC_AxOpt#10](../mfc/codesnippet/cpp/providing-mouse-interaction-while-inactive_2.cpp)]  
[!code-cpp[NVC_MFC_AxOpt#7](../mfc/codesnippet/cpp/providing-mouse-interaction-while-inactive_3.cpp)]  
  
 O código para incluir esse sinalizador é gerado automaticamente se você selecionar o **Mouse ponteiro notificações quando inativo** opção o [configurações de controle](../mfc/reference/control-settings-mfc-activex-control-wizard.md) página ao criar o controle com o **Assistente de controle ActiveX MFC**.  
  
 Quando o `IPointerInactive` interface está habilitada, os delegados do contêiner `WM_SETCURSOR` e `WM_MOUSEMOVE` mensagens a ele. `COleControl`da implementação de `IPointerInactive` envia as mensagens pelo mapa de mensagem do controle depois de ajustar o mouse coordena adequadamente. Você pode processar as mensagens como mensagens de janela comuns adicionando as entradas correspondentes no mapa de mensagem. Em seus manipuladores para essas mensagens, evite usar o `m_hWnd` variável de membro (ou qualquer função de membro que utiliza) sem antes conferir que seu valor não é **nulo**.  
  
 Talvez também seja um controle inativo deve ser o destino de uma operação de arrastar e soltar OLE. Isso requer ativando o controle no momento em que o usuário arrasta um objeto, para que a janela do controle pode ser registrada como um destino de soltar. Para fazer com que ocorrem durante um arrastar a ativação, substituir [COleControl::GetActivationPolicy](../mfc/reference/colecontrol-class.md#getactivationpolicy)e retornar o **POINTERINACTIVE_ACTIVATEONDRAG** sinalizador:  
  
 [!code-cpp[NVC_MFC_AxOpt#11](../mfc/codesnippet/cpp/providing-mouse-interaction-while-inactive_4.cpp)]  
  
 Habilitando o `IPointerInactive` interface normalmente significa que você deseja que o controle seja capaz de processar mensagens do mouse em todos os momentos. Para obter esse comportamento em um contêiner que não oferece suporte a `IPointerInactive` interface, você precisa ter o controle sempre ativado quando visível, que significa que o controle deve incluir o **OLEMISC_ACTIVATEWHENVISIBLE** sinalizador entre seus diversos sinalizadores. No entanto, para evitar esse sinalizador de entrar em vigor em um contêiner que oferece suporte `IPointerInactive`, você também pode especificar o **OLEMISC_IGNOREACTIVATEWHENVISIBLE** sinalizador:  
  
 [!code-cpp[NVC_MFC_AxOpt#12](../mfc/codesnippet/cpp/providing-mouse-interaction-while-inactive_5.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC: otimização](../mfc/mfc-activex-controls-optimization.md)

