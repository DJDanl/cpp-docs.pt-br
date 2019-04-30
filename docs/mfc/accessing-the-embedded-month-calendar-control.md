---
title: Acessando o controle de calendário mensal inserido
ms.date: 11/04/2016
helpviewer_keywords:
- DateTimePicker control [MFC], accessing month calendar
- CDateTimeCtrl class [MFC], accessing embedded control
- month calendar controls [MFC], embedded in date/time picker
- CMonthCalCtrl class [MFC], changing the font
- month calendar controls [MFC], changing the font
- DateTimePicker control [MFC]
ms.assetid: 355e97ed-cf81-4df3-a2f8-9ddbbde93227
ms.openlocfilehash: dfe6fa220e19deebd86e7c8b7bd25dab60165f73
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62392915"
---
# <a name="accessing-the-embedded-month-calendar-control"></a>Acessando o controle de calendário mensal inserido

O objeto de controle de calendário mensal inserido pode ser acessado a partir de `CDateTimeCtrl` objeto com uma chamada para o [GetMonthCalCtrl](../mfc/reference/cdatetimectrl-class.md#getmonthcalctrl) função de membro.

> [!NOTE]
>  O controle de calendário mensal inserido é usado somente quando o controle de seletor de data e hora não tem o **DTS_UPDOWN** conjunto de estilos.

Isso é útil se você quiser modificar determinados atributos antes do controle inserido é exibido. Para fazer isso, lidar com o **DTN_DROPDOWN** notificação, recuperar o controle de calendário mensal (usando [CDateTimeCtrl::GetMonthCalCtrl](../mfc/reference/cdatetimectrl-class.md#getmonthcalctrl)) e fazer as modificações. Infelizmente, o controle de calendário mensal não é persistente.

Em outras palavras, quando o usuário solicita a exibição de controle de calendário mensal, um controle de calendário do mês novo é criado (antes do **DTN_DROPDOWN** notificação). O controle é destruído (depois que o **DTN_CLOSEUP** notificação) quando ignorado pelo usuário. Isso significa que todos os atributos que modificar, antes do controle inserido é exibido, são perdidos quando o controle inserido é descartado.

O exemplo a seguir demonstra esse procedimento, usando um manipulador para o **DTN_DROPDOWN** notificação. O código altera a cor de plano de fundo do controle de calendário mensal, com uma chamada para [SetMonthCalColor](../mfc/reference/cdatetimectrl-class.md#setmonthcalcolor), em cinza. O código é da seguinte maneira:

[!code-cpp[NVC_MFCControlLadenDialog#5](../mfc/codesnippet/cpp/accessing-the-embedded-month-calendar-control_1.cpp)]

Conforme mencionado anteriormente, todas as modificações a propriedades de controle de calendário mensal são perdidas, com duas exceções, quando o controle inserido é descartado. A primeira exceção, as cores do controle de calendário mensal, já foi abordada. A segunda exceção é a fonte usada pelo controle de calendário mensal. Você pode modificar a fonte padrão, fazendo uma chamada para [CDateTimeCtrl::SetMonthCalFont](../mfc/reference/cdatetimectrl-class.md#setmonthcalfont), passando o identificador de uma fonte existente. O exemplo a seguir (onde `m_dtPicker` é o objeto de controle de data e hora) demonstra um método possível:

[!code-cpp[NVC_MFCControlLadenDialog#6](../mfc/codesnippet/cpp/accessing-the-embedded-month-calendar-control_2.cpp)]

Quando a fonte é alterada, com uma chamada para `CDateTimeCtrl::SetMonthCalFont`, a nova fonte é armazenada e usada na próxima vez em um calendário de mês deve ser exibido.

## <a name="see-also"></a>Consulte também

[Usando CDateTimeCtrl](../mfc/using-cdatetimectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
