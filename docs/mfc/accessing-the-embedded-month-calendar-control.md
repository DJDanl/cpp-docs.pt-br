---
title: "Acessando o controle de calend&#225;rio mensal inserido | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CDateTimeCtrl, acessando controle inserido"
  - "Classe CMonthCalCtrl, alterando a fonte"
  - "Controle DateTimePicker [MFC]"
  - "Controle DateTimePicker [MFC], acessando o calendário mensal"
  - "controles de calendário mensal, alterando a fonte"
  - "controles de calendário mensal, inserido no seletor de data e hora"
ms.assetid: 355e97ed-cf81-4df3-a2f8-9ddbbde93227
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Acessando o controle de calend&#225;rio mensal inserido
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O objeto inserido de controle de calendário do mês pode ser acessado do objeto de `CDateTimeCtrl` com uma chamada à função de membro de [GetMonthCalCtrl](../Topic/CDateTimeCtrl::GetMonthCalCtrl.md) .  
  
> [!NOTE]
>  O controle inserido month calendar é usado somente quando o controle de seletor de data e hora não tiver o estilo de **DTS\_UPDOWN** definido.  
  
 Isso será útil se você quiser alterar alguns atributos antes que o controle inserido ser exibido.  Para fazer isso, tratar a notificação de **DTN\_DROPDOWN** , recupere o controle de calendário do mês \(usando [CDateTimeCtrl::GetMonthCalCtrl](../Topic/CDateTimeCtrl::GetMonthCalCtrl.md)\), e disponibilizará suas alterações.  Infelizmente, o controle de calendário do mês não é persistente.  
  
 Ou seja quando um usuário solicita a exibição do controle de calendário do mês, um novo controle de calendário do mês são criadas \(a notificação de **DTN\_DROPDOWN** \).  O controle é destruído \(depois da notificação de **DTN\_CLOSEUP** \) quando ignorado pelo usuário.  Isso significa que alguns atributos que você alterar, antes que o controle inserido é exibido, é perdido quando o controle inserido é ignorado.  
  
 O exemplo a seguir demonstra esse procedimento, usando um manipulador para a notificação de **DTN\_DROPDOWN** .  As alterações de código a cor do plano de fundo do controle de calendário do mês, com uma chamada a [SetMonthCalColor](../Topic/CDateTimeCtrl::SetMonthCalColor.md), em cinza.  O código é como segue:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#5](../mfc/codesnippet/CPP/accessing-the-embedded-month-calendar-control_1.cpp)]  
  
 Como mencionado anteriormente, todas as alterações às propriedades de controle de calendário do mês são perdidas, com duas exceções, quando o controle inserido é ignorado.  A primeira exceção, as cores de controle de calendário do mês, discutida já tiver sido.  A segunda exceção é a fonte usada pelo controle de calendário do mês.  Você pode alterar a fonte padrão para fazer uma chamada a [CDateTimeCtrl::SetMonthCalFont](../Topic/CDateTimeCtrl::SetMonthCalFont.md), passando o identificador de uma fonte existente.  O exemplo a seguir \(onde `m_dtPicker` é o objeto de controle de data e hora\) demonstra um método possível:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#6](../mfc/codesnippet/CPP/accessing-the-embedded-month-calendar-control_2.cpp)]  
  
 Uma vez que a fonte esteve alterada, com uma chamada a `CDateTimeCtrl::SetMonthCalFont`, a nova fonte seja armazenada e usada na próxima vez que um calendário do mês deve ser exibido.  
  
## Consulte também  
 [Usando CDateTimeCtrl](../mfc/using-cdatetimectrl.md)   
 [Controles](../mfc/controls-mfc.md)