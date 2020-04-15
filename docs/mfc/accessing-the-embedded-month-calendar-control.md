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
ms.openlocfilehash: 69270cc5663406f2c5d38ffccdbd35f39298a3d5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81354189"
---
# <a name="accessing-the-embedded-month-calendar-control"></a>Acessando o controle de calendário mensal inserido

O objeto de controle de calendário `CDateTimeCtrl` do mês incorporado pode ser acessado a partir do objeto com uma chamada para a função membro [GetMonthCalCtrl.](../mfc/reference/cdatetimectrl-class.md#getmonthcalctrl)

> [!NOTE]
> O controle de calendário do mês incorporado é usado somente quando o controle de data e hora do seletor não tiver o **DTS_UPDOWN** conjunto de estilos.

Isso é útil se você quiser modificar certos atributos antes que o controle incorporado seja exibido. Para isso, manuseie a notificação **DTN_DROPDOWN,** recupere o controle do calendário do mês (usando [CDateTimeCtrl::GetMonthCalCtrl)](../mfc/reference/cdatetimectrl-class.md#getmonthcalctrl)e faça suas modificações. Infelizmente, o controle do calendário do mês não é persistente.

Em outras palavras, quando o usuário solicita a exibição do controle do calendário do mês, um novo controle de calendário do mês é criado (antes da notificação **DTN_DROPDOWN).** O controle é destruído (após a **notificação DTN_CLOSEUP)** quando dispensado pelo usuário. Isso significa que todos os atributos que você modificar, antes do controle incorporado ser exibido, são perdidos quando o controle incorporado é descartado.

O exemplo a seguir demonstra este procedimento, usando um manipulador para a notificação **DTN_DROPDOWN.** O código altera a cor de fundo do controle do calendário do mês, com uma chamada para [SetMonthCalColor](../mfc/reference/cdatetimectrl-class.md#setmonthcalcolor), para cinza. O código é o seguinte:

[!code-cpp[NVC_MFCControlLadenDialog#5](../mfc/codesnippet/cpp/accessing-the-embedded-month-calendar-control_1.cpp)]

Como dito anteriormente, todas as modificações nas propriedades do controle do calendário do mês são perdidas, com duas exceções, quando o controle incorporado é descartado. A primeira exceção, as cores do controle do calendário do mês, já foi discutida. A segunda exceção é a fonte usada pelo controle do calendário do mês. Você pode modificar a fonte padrão fazendo uma chamada para [CDateTimeCtrl::SetMonthCalFont](../mfc/reference/cdatetimectrl-class.md#setmonthcalfont), passando a alça de uma fonte existente. O exemplo a `m_dtPicker` seguir (onde está o objeto de controle de data e hora) demonstra um método possível:

[!code-cpp[NVC_MFCControlLadenDialog#6](../mfc/codesnippet/cpp/accessing-the-embedded-month-calendar-control_2.cpp)]

Uma vez que a fonte tenha `CDateTimeCtrl::SetMonthCalFont`sido alterada, com uma chamada para , a nova fonte é armazenada e usada na próxima vez que um calendário de mês for exibido.

## <a name="see-also"></a>Confira também

[Usando CDateTimeCtrl](../mfc/using-cdatetimectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
