---
title: "Acessando o calendário mensal inserido controle | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- DateTimePicker control [MFC], accessing month calendar
- CDateTimeCtrl class [MFC], accessing embedded control
- month calendar controls [MFC], embedded in date/time picker
- CMonthCalCtrl class [MFC], changing the font
- month calendar controls [MFC], changing the font
- DateTimePicker control [MFC]
ms.assetid: 355e97ed-cf81-4df3-a2f8-9ddbbde93227
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e37d23a7d5d860d55e18f709c873a40d8f24f1c7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="accessing-the-embedded-month-calendar-control"></a>Acessando o controle de calendário mensal inserido
O objeto de controle de calendário mensal inserido pode ser acessado pelo `CDateTimeCtrl` objeto com uma chamada para o [GetMonthCalCtrl](../mfc/reference/cdatetimectrl-class.md#getmonthcalctrl) função de membro.  
  
> [!NOTE]
>  O controle de calendário mensal inserido é usado somente quando o controle de seletor de data e hora não tem o **DTS_UPDOWN** conjunto de estilos.  
  
 Isso é útil se você quiser modificar determinados atributos antes do controle inserido é exibido. Para fazer isso, tratar o **DTN_DROPDOWN** notificação, recuperar o controle de calendário mensal (usando [CDateTimeCtrl::GetMonthCalCtrl](../mfc/reference/cdatetimectrl-class.md#getmonthcalctrl)) e fazer as modificações. Infelizmente, o controle de calendário mensal não é persistente.  
  
 Em outras palavras, quando o usuário solicita a exibição do controle de calendário do mês, um controle de calendário do mês novo é criado (antes do **DTN_DROPDOWN** notificação). O controle é destruído (após o **DTN_CLOSEUP** notificação) quando ignorado pelo usuário. Isso significa que todos os atributos que modificar, antes do controle inserido é exibido, são perdidos quando o controle inserido é descartado.  
  
 O exemplo a seguir demonstra esse procedimento, usando um manipulador para o **DTN_DROPDOWN** notificação. O código altera a cor de plano de fundo do controle de calendário de mês, com uma chamada para [SetMonthCalColor](../mfc/reference/cdatetimectrl-class.md#setmonthcalcolor), em cinza. O código é da seguinte maneira:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#5](../mfc/codesnippet/cpp/accessing-the-embedded-month-calendar-control_1.cpp)]  
  
 Como mencionado anteriormente, todas as modificações às propriedades do controle de calendário de mês são perdidas, com duas exceções, quando o controle inserido é descartado. A primeira exceção, as cores do controle de calendário mensal, já foi discutida. A segunda exceção é a fonte usada pelo controle de calendário do mês. Você pode modificar a fonte padrão, fazendo uma chamada para [CDateTimeCtrl::SetMonthCalFont](../mfc/reference/cdatetimectrl-class.md#setmonthcalfont), passando o identificador de uma fonte existente. O exemplo a seguir (onde `m_dtPicker` é o objeto de controle de data e hora) demonstra um método possível:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#6](../mfc/codesnippet/cpp/accessing-the-embedded-month-calendar-control_2.cpp)]  
  
 Quando a fonte é alterada, com uma chamada para `CDateTimeCtrl::SetMonthCalFont`, a nova fonte é armazenada e usada na próxima vez em um calendário de mês é exibido.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CDateTimeCtrl](../mfc/using-cdatetimectrl.md)   
 [Controles](../mfc/controls-mfc.md)

