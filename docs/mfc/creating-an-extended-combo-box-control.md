---
title: "Criando um controle de caixa de combinação estendido | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- extended combo boxes
- CComboBoxEx class [MFC], creating extended combo box controls
- extended combo boxes [MFC], creating
ms.assetid: a964267e-97b6-4e77-9f89-55bb5c68913f
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 96903fabd5ec0a0cff4d55eb97e7d06271b79990
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="creating-an-extended-combo-box-control"></a>Criando um controle de caixa de combinação estendido
Como o controle de caixa de combinação estendidas é criado depende se você estiver usando o controle em uma caixa de diálogo ou criá-lo em uma janela nondialog.  
  
### <a name="to-use-ccomboboxex-directly-in-a-dialog-box"></a>Para usar CComboBoxEx diretamente em uma caixa de diálogo  
  
1.  No editor de caixa de diálogo, adicione um controle de caixa de combinação estendido para o recurso de modelo de caixa de diálogo. Especifique sua ID de controle.  
  
2.  Especifique todos os estilos necessários, usando a caixa de diálogo Propriedades da caixa de combinação estendidas.  
  
3.  Use o [Assistente para adição de variável de membro](../ide/adding-a-member-variable-visual-cpp.md) para adicionar uma variável de membro de tipo [CComboBoxEx](../mfc/reference/ccomboboxex-class.md) com a propriedade de controle. Você pode usar este membro para chamar `CComboBoxEx` funções de membro.  
  
4.  Use a janela Propriedades para mapear as funções de manipulador na classe de caixa de diálogo de mensagens de notificação do controle qualquer combinação estendidas caixa você precisa tratar (consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md)).  
  
5.  Em [OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog), defina todos os estilos adicionais para o `CComboBoxEx` objeto.  
  
### <a name="to-use-ccomboboxex-in-a-nondialog-window"></a>Para usar CComboBoxEx em uma janela de nondialog  
  
1.  Defina o controle nas classes de exibição ou janela.  
  
2.  O controle de chamada [criar](../mfc/reference/ctabctrl-class.md#create) função de membro, possivelmente em [OnInitialUpdate](../mfc/reference/cview-class.md#oninitialupdate), possivelmente como antecipado como a janela pai [OnCreate](../mfc/reference/cwnd-class.md#oncreate) função do manipulador. Defina estilos para o controle.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CComboBoxEx](../mfc/using-ccomboboxex.md)   
 [Controles](../mfc/controls-mfc.md)

