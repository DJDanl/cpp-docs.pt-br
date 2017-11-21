---
title: "Fechar a caixa de diálogo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- MFC dialog boxes [MFC], closing
- dialog boxes [MFC], closing
ms.assetid: 946f5675-c482-46a4-a5dd-34fe138ffae5
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: d7cd57819c5ab462b0310162d3c043c5f39d2a69
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="closing-the-dialog-box"></a>Fechando a caixa de diálogo
Caixa de diálogo modal fecha quando o usuário escolhe um dos seus botões, geralmente o botão Okey ou o botão Cancelar. Escolha o botão Okey ou Cancelar faz com que o Windows enviar o objeto de caixa de diálogo um **BN_CLICKED** mensagem de notificação de controle com o botão da ID, ou **IDOK** ou **IDCANCEL**. `CDialog`fornece funções de manipulador de padrão para essas mensagens: `OnOK` e `OnCancel`. A chamada de manipuladores de padrão de `EndDialog` função de membro para fechar a janela da caixa de diálogo. Você também pode chamar `EndDialog` de seu próprio código. Para obter mais informações, consulte o [EndDialog](../mfc/reference/cdialog-class.md#enddialog) função de membro de classe `CDialog` no *referência MFC*.  
  
 Para organizar para fechar e excluir uma caixa de diálogo sem janela restrita, substituir `PostNcDestroy` e invocar o **excluir** operador o **isso** ponteiro. [Destruindo a caixa de diálogo](../mfc/destroying-the-dialog-box.md) explica o que acontece em seguida.  
  
## <a name="see-also"></a>Consulte também  
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)

