---
title: "Formata&#231;&#227;o de caractere em controles de edi&#231;&#227;o avan&#231;ada | Microsoft Docs"
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
  - "Classe CRichEditCtrl, formatação de caracteres em"
  - "formatação [C++], caracteres"
  - "controles de edição avançada, formatação de caracteres em"
ms.assetid: c80f4305-75ad-45f9-8d17-d83d0fe79be5
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Formata&#231;&#227;o de caractere em controles de edi&#231;&#227;o avan&#231;ada
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode usar as funções de membro de controle de edição avançado \([CRichEditCtrl](../Topic/CRichEditCtrl%20Class.md)2.147.483.647\) caracteres de formato e recuperar as informações de formatação.  Para caracteres, você pode especificar o caráter tipo, o tamanho, colori\-los, e os efeitos como negrito, em itálico, e protegidos.  
  
 Você pode aplicar formatação de caractere usando as funções de membro de [SetSelectionCharFormat](../Topic/CRichEditCtrl::SetSelectionCharFormat.md) e de [SetWordCharFormat](../Topic/CRichEditCtrl::SetWordCharFormat.md) .  Para determinar a formatação atual de caracteres para o texto selecionado, use a função de membro de [GetSelectionCharFormat](../Topic/CRichEditCtrl::GetSelectionCharFormat.md) .  A estrutura de [CHARFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb787881) é usada com essas funções de membro para especificar atributos de caractere.  Um dos membros importantes de **CHARFORMAT** é **dwMask**.  Em `SetSelectionCharFormat` e em `SetWordCharFormat`, **dwMask** especifica que os atributos de caracteres serão definidos por esta chamada de função.  `GetSelectionCharFormat` informa os atributos do primeiro caractere na seleção; **dwMask** especifica os atributos que são consistentes em toda a seleção.  
  
 Você também pode obter e definir “a formatação padrão de caractere”, que é a formatação aplicada a todos os caracteres subsequentemente inseridos.  Por exemplo, se um aplicativo definir o caractere padrão que formata ao usuário em negrito e então digite um caractere, o caractere é em negrito.  Para obter e definir a formatação padrão de caractere, use as funções de membro de [GetDefaultCharFormat](../Topic/CRichEditCtrl::GetDefaultCharFormat.md) e de [SetDefaultCharFormat](../Topic/CRichEditCtrl::SetDefaultCharFormat.md) .  
  
 O atributo “protegido” de caracteres não altera a aparência do texto.  Se o usuário tentar modificar o texto protegido, um controle de edição rico envia a janela pai uma notificação de **EN\_PROTECTED** , permitindo que a janela pai permitir ou impede a alteração.  Para receber essa notificação, você deve habilitá\-lo usando a função de membro de [SetEventMask](../Topic/CRichEditCtrl::SetEventMask.md) .  Para obter mais informações sobre a máscara de evento, consulte [Notificações de um controle de edição avançado](../mfc/notifications-from-a-rich-edit-control.md), mais adiante neste tópico.  
  
 A cor de primeiro plano é um atributo de caracteres, mas a cor do plano de fundo é uma propriedade do controle de edição sofisticado.  Para definir a cor do plano de fundo, use a função de membro de [SetBackgroundColor](../Topic/CRichEditCtrl::SetBackgroundColor.md) .  
  
## Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)