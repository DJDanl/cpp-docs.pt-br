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
ms.openlocfilehash: 66a9ef7fd49ea81ddac4779aa6d1c3f12fbe4c55
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84617373"
---
# <a name="accessing-the-embedded-month-calendar-control"></a>Acessando o controle de calendário mensal inserido

O objeto de controle de calendário de mês incorporado pode ser acessado do `CDateTimeCtrl` objeto com uma chamada para a função de membro [GetMonthCalCtrl](reference/cdatetimectrl-class.md#getmonthcalctrl) .

> [!NOTE]
> O controle de calendário mensal inserido só é usado quando o controle seletor de data e hora não tem o estilo de **DTS_UPDOWN** definido.

Isso será útil se você quiser modificar determinados atributos antes que o controle inserido seja exibido. Para fazer isso, manipule a notificação de **DTN_DROPDOWN** , recupere o controle de calendário mensal (usando [CDateTimeCtrl:: GetMonthCalCtrl](reference/cdatetimectrl-class.md#getmonthcalctrl)) e faça suas modificações. Infelizmente, o controle de calendário mensal não é persistente.

Em outras palavras, quando o usuário solicita a exibição do controle de calendário mensal, um novo controle de calendário mensal é criado (antes da notificação de **DTN_DROPDOWN** ). O controle é destruído (após a notificação de **DTN_CLOSEUP** ) quando Descartado pelo usuário. Isso significa que todos os atributos que você modificar, antes de o controle inserido ser exibido, serão perdidos quando o controle inserido for descartado.

O exemplo a seguir demonstra esse procedimento, usando um manipulador para a notificação de **DTN_DROPDOWN** . O código altera a cor do plano de fundo do controle de calendário mensal, com uma chamada para [SetMonthCalColor](reference/cdatetimectrl-class.md#setmonthcalcolor), para cinza. O código é o seguinte:

[!code-cpp[NVC_MFCControlLadenDialog#5](codesnippet/cpp/accessing-the-embedded-month-calendar-control_1.cpp)]

Conforme mencionado anteriormente, todas as modificações nas propriedades do controle de calendário mensal são perdidas, com duas exceções, quando o controle inserido é Descartado. A primeira exceção, as cores do controle de calendário mensal, já foi discutida. A segunda exceção é a fonte usada pelo controle de calendário mensal. Você pode modificar a fonte padrão fazendo uma chamada para [CDateTimeCtrl:: SetMonthCalFont](reference/cdatetimectrl-class.md#setmonthcalfont), passando o identificador de uma fonte existente. O exemplo a seguir (em que `m_dtPicker` é o objeto de controle de data e hora) demonstra um possível método:

[!code-cpp[NVC_MFCControlLadenDialog#6](codesnippet/cpp/accessing-the-embedded-month-calendar-control_2.cpp)]

Depois que a fonte tiver sido alterada, com uma chamada para `CDateTimeCtrl::SetMonthCalFont` , a nova fonte será armazenada e usada na próxima vez que um calendário mensal for exibido.

## <a name="see-also"></a>Consulte também

[Usando CDateTimeCtrl](using-cdatetimectrl.md)<br/>
[Controles](controls-mfc.md)
