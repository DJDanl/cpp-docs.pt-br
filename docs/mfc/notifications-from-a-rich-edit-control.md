---
title: Notificações de uma edição avançada controle | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- messages [MFC], notification [MFC]
- CRichEditCtrl class [MFC], notifications
- rich edit controls [MFC], notifications
- notifications [MFC], from CRichEditCtrl
ms.assetid: eb5304fe-f4f3-4557-9ebf-3095dea383c4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8898ac9d5aabebef42877ff063aaf93ceee77fad
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46386777"
---
# <a name="notifications-from-a-rich-edit-control"></a>Notificações de um controle de edição avançada

Mensagens de notificação de eventos que afetam uma avançada de controle de edição de relatório ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)). Eles podem ser processados pela janela pai ou, usando a reflexão de mensagem, por sofisticada Editar controle em si. Controles de edição de rich dar suporte a todas as mensagens de notificação usadas com controles de edição, bem como vários outros adicionais. Você pode determinar quais mensagens de notificação um controle rich edit envia sua janela pai, definindo sua "máscara de evento".

Para definir a máscara de evento de controle de edição de um ricos, use o [SetEventMask](../mfc/reference/cricheditctrl-class.md#seteventmask) função de membro. Você pode recuperar a máscara de evento atual para o controle de edição de um avançado usando o [GetEventMask](../mfc/reference/cricheditctrl-class.md#geteventmask) função de membro.

Os parágrafos a seguir listam várias notificações específicas e seus usos:

- EN_MSGFILTER tratando a notificação EN_MSGFILTER permite que uma classe, ou o controle rich edit ou sua janela pai, todos os teclado e mouse ao controle de entrada de filtro. O manipulador pode impedir que a mensagem do teclado ou mouse que está sendo processado ou pode alterar a mensagem modificando especificado [filtro de mensagens](/windows/desktop/api/richedit/ns-richedit-_msgfilter) estrutura.

- EN_PROTECTED lidar com a mensagem de notificação EN_PROTECTED para detectar quando o usuário tenta modificar texto protegido. Para marcar um intervalo de texto como protegido, você pode definir o efeito de caractere protegido. Para obter mais informações, consulte [formatação de caracteres em controles de edição de Rich](../mfc/character-formatting-in-rich-edit-controls.md).

- EN_DROPFILES você pode habilitar o usuário soltar arquivos em um controle rich edit processando a mensagem de notificação EN_DROPFILES. Especificado [ENDROPFILES](/windows/desktop/api/richedit/ns-richedit-_endropfiles) estrutura contém informações sobre os arquivos que está sendo descartada.

- EN_SELCHANGE um aplicativo pode detectar quando a seleção atual é alterado pelo processamento da mensagem de notificação EN_SELCHANGE. Especifica a mensagem de notificação de um [SELCHANGE](/windows/desktop/api/richedit/ns-richedit-_selchange) estrutura que contém informações sobre a nova seleção.

## <a name="see-also"></a>Consulte também

[Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

