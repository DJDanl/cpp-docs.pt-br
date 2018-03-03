---
title: Criando o seletor de data e hora controle | Microsoft Docs
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
- DateTimePicker control [MFC], creating
- CDateTimeCtrl class [MFC], creating
ms.assetid: 764ec2fb-98cd-478b-a5f2-d63f0bb12279
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e9c0b99f42bef162ed3c571e19630f9227a8504e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-the-date-and-time-picker-control"></a>Criando o controle de seletor de data e hora
Como o controle de seletor de data e hora é criado depende se você estiver usando o controle em uma caixa de diálogo ou criá-lo em uma janela nondialog.  
  
### <a name="to-use-cdatetimectrl-directly-in-a-dialog-box"></a>Para usar CDateTimeCtrl diretamente em uma caixa de diálogo  
  
1.  No editor de caixa de diálogo, adicione uma data e o controle de seletor de tempo para o recurso de modelo de caixa de diálogo. Especifique sua ID de controle.  
  
2.  Especifique todos os estilos necessários, usando a caixa de diálogo Propriedades do controle de seletor de data e hora.  
  
3.  Use o [Assistente para adição de variável de membro](../ide/adding-a-member-variable-visual-cpp.md) para adicionar uma variável de membro de tipo [CDateTimeCtrl](../mfc/reference/cdatetimectrl-class.md) com a propriedade de controle. Você pode usar este membro para chamar `CDateTimeCtrl` funções de membro.  
  
4.  Use a janela Propriedades para mapear as funções de manipulador na classe de caixa de diálogo de qualquer controle de seletor de data hora [notificação](../mfc/processing-notification-messages-in-date-and-time-picker-controls.md) mensagens, você precisa tratar (consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md)).  
  
5.  Em [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog), defina todos os estilos adicionais para o `CDateTimeCtrl` objeto.  
  
### <a name="to-use-cdatetimectrl-in-a-nondialog-window"></a>Para usar CDateTimeCtrl em uma janela de nondialog  
  
1.  Declare o controle nas classes de exibição ou janela.  
  
2.  O controle de chamada [criar](../mfc/reference/ctabctrl-class.md#create) função de membro, possivelmente em [OnInitialUpdate](../mfc/reference/cview-class.md#oninitialupdate), possivelmente como antecipado como a janela pai [OnCreate](../mfc/reference/cwnd-class.md#oncreate) (se você tiver a função do manipulador Subclassificação do controle). Defina estilos para o controle.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CDateTimeCtrl](../mfc/using-cdatetimectrl.md)   
 [Controles](../mfc/controls-mfc.md)

