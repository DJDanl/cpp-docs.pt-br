---
title: Fechar a caixa de diálogo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC dialog boxes [MFC], closing
- dialog boxes [MFC], closing
ms.assetid: 946f5675-c482-46a4-a5dd-34fe138ffae5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c800c204fd09057585064397d459f92c9ded272d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="closing-the-dialog-box"></a>Fechando a caixa de diálogo
Caixa de diálogo modal fecha quando o usuário escolhe um dos seus botões, geralmente o botão Okey ou o botão Cancelar. Escolha o botão Okey ou Cancelar faz com que o Windows enviar o objeto de caixa de diálogo um **BN_CLICKED** mensagem de notificação de controle com o botão da ID, ou **IDOK** ou **IDCANCEL**. `CDialog` fornece funções de manipulador de padrão para essas mensagens: `OnOK` e `OnCancel`. A chamada de manipuladores de padrão de `EndDialog` função de membro para fechar a janela da caixa de diálogo. Você também pode chamar `EndDialog` de seu próprio código. Para obter mais informações, consulte o [EndDialog](../mfc/reference/cdialog-class.md#enddialog) função de membro de classe `CDialog` no *referência MFC*.  
  
 Para organizar para fechar e excluir uma caixa de diálogo sem janela restrita, substituir `PostNcDestroy` e invocar o **excluir** operador o **isso** ponteiro. [Destruindo a caixa de diálogo](../mfc/destroying-the-dialog-box.md) explica o que acontece em seguida.  
  
## <a name="see-also"></a>Consulte também  
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)

