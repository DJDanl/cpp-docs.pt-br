---
title: Formatação de caractere em controles de edição avançada
ms.date: 11/04/2016
helpviewer_keywords:
- formatting [MFC], characters
- rich edit controls [MFC], character formatting in
- CRichEditCtrl class [MFC], character formatting in
ms.assetid: c80f4305-75ad-45f9-8d17-d83d0fe79be5
ms.openlocfilehash: 0b9d925b6ba3157177b7012d1e303ef7b7ddab46
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84624941"
---
# <a name="character-formatting-in-rich-edit-controls"></a>Formatação de caractere em controles de edição avançada

Você pode usar funções de membro do[CRichEditCtrl](reference/cricheditctrl-class.md)(controle de edição rico) para formatar caracteres e recuperar informações de formatação. Para caracteres, você pode especificar a face de tipos, o tamanho, a cor e os efeitos, como negrito, itálico e protegido.

Você pode aplicar a formatação de caracteres usando as funções de membro [SetSelectionCharFormat](reference/cricheditctrl-class.md#setselectioncharformat) e [SetWordCharFormat](reference/cricheditctrl-class.md#setwordcharformat) . Para determinar a formatação de caractere atual para o texto selecionado, use a função de membro [GetSelectionCharFormat](reference/cricheditctrl-class.md#getselectioncharformat) . A estrutura [CHARFORMAT](/windows/win32/api/richedit/ns-richedit-charformata) é usada com essas funções de membro para especificar atributos de caractere. Um dos membros importantes do **CHARFORMAT** é **dwMask**. Em `SetSelectionCharFormat` e `SetWordCharFormat` , **dwMask** especifica quais atributos de caractere serão definidos por essa chamada de função. `GetSelectionCharFormat`relata os atributos do primeiro caractere na seleção; **dwMask** especifica os atributos que são consistentes durante a seleção.

Você também pode obter e definir a "formatação de caractere padrão", que é a formatação aplicada a qualquer caractere inserido subsequentemente. Por exemplo, se um aplicativo definir a formatação de caractere padrão como negrito e o usuário digitar um caractere, esse caractere será negrito. Para obter e definir a formatação de caractere padrão, use as funções de membro [GetDefaultCharFormat](reference/cricheditctrl-class.md#getdefaultcharformat) e [SetDefaultCharFormat](reference/cricheditctrl-class.md#setdefaultcharformat) .

O atributo de caractere "protegido" não altera a aparência do texto. Se o usuário tentar modificar o texto protegido, um controle rich edit enviará a janela pai um **EN_PROTECTED** mensagem de notificação, permitindo que a janela pai permita ou impeça a alteração. Para receber essa mensagem de notificação, você deve habilitá-la usando a função de membro [SetEventMask](reference/cricheditctrl-class.md#seteventmask) . Para obter mais informações sobre a máscara de evento, consulte [notificações de um controle rich edit](notifications-from-a-rich-edit-control.md), mais adiante neste tópico.

A cor de primeiro plano é um atributo de caractere, mas a cor do plano de fundo é uma propriedade do controle rich edit. Para definir a cor do plano de fundo, use a função de membro [setBackgroundColor](reference/cricheditctrl-class.md#setbackgroundcolor) .

## <a name="see-also"></a>Consulte também

[Usando CRichEditCtrl](using-cricheditctrl.md)<br/>
[Controles](controls-mfc.md)
