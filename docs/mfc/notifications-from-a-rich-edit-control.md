---
title: Notificações de um controle de edição avançada
ms.date: 11/04/2016
helpviewer_keywords:
- messages [MFC], notification [MFC]
- CRichEditCtrl class [MFC], notifications
- rich edit controls [MFC], notifications
- notifications [MFC], from CRichEditCtrl
ms.assetid: eb5304fe-f4f3-4557-9ebf-3095dea383c4
ms.openlocfilehash: 206fc02088f6531338bf2aa4cf272a1da096bae4
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84622221"
---
# <a name="notifications-from-a-rich-edit-control"></a>Notificações de um controle de edição avançada

Mensagens de notificação relatam eventos que afetam um[CRichEditCtrl](reference/cricheditctrl-class.md)(Rich Edit Control). Eles podem ser processados pela janela pai ou, usando a reflexão de mensagem, pelo próprio controle de edição. Os controles de edição avançados dão suporte a todas as mensagens de notificação usadas com controles de edição, bem como várias outras. Você pode determinar quais mensagens de notificação um controle de edição avançado envia sua janela pai definindo sua "máscara de evento".

Para definir a máscara de evento para um controle de edição rico, use a função de membro [SetEventMask](reference/cricheditctrl-class.md#seteventmask) . Você pode recuperar a máscara de evento atual para um controle de edição rico usando a função de membro [GetEventMask](reference/cricheditctrl-class.md#geteventmask) .

Os parágrafos a seguir listam várias notificações específicas e seus usos:

- EN_MSGFILTER manipular a notificação EN_MSGFILTER permite que uma classe, o controle de edição rico ou sua janela pai, filtre todas as entradas de teclado e mouse para o controle. O manipulador pode impedir que a mensagem de teclado ou mouse seja processada ou pode alterar a mensagem modificando a estrutura [MSGFILTER](/windows/win32/api/richedit/ns-richedit-msgfilter) especificada.

- EN_PROTECTED manipular a mensagem de notificação de EN_PROTECTED para detectar quando o usuário tenta modificar o texto protegido. Para marcar um intervalo de texto como protegido, você pode definir o efeito de caractere protegido. Para obter mais informações, consulte [formatação de caracteres em controles de edição avançados](character-formatting-in-rich-edit-controls.md).

- EN_DROPFILES você pode habilitar o usuário a soltar arquivos em um controle de edição rico processando a mensagem de notificação EN_DROPFILES. A estrutura [ENDROPFILES](/windows/win32/api/richedit/ns-richedit-endropfiles) especificada contém informações sobre os arquivos que estão sendo removidos.

- EN_SELCHANGE um aplicativo pode detectar quando a seleção atual muda processando a mensagem de notificação EN_SELCHANGE. A mensagem de notificação especifica uma estrutura [SELCHANGE](/windows/win32/api/richedit/ns-richedit-selchange) que contém informações sobre a nova seleção.

## <a name="see-also"></a>Consulte também

[Usando CRichEditCtrl](using-cricheditctrl.md)<br/>
[Controles](controls-mfc.md)
