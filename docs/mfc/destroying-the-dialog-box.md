---
title: Destruindo a caixa de diálogo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- dialog boxes [MFC], deleting
- destruction, dialog box
- dialog boxes [MFC], destroying
- dialog boxes [MFC], removing
- modeless dialog boxes [MFC], destroying
- MFC dialog boxes [MFC], destroying
- modal dialog boxes [MFC], destroying
ms.assetid: dabceee7-3639-4d85-bf34-73515441b3d0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 66a3ef9a72107ffb36a75834a6e197aba394c420
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="destroying-the-dialog-box"></a>Destruindo a caixa de diálogo
Caixas de diálogo modais normalmente são criadas no quadro de pilha e destruídas quando terminar a função que os criou. Destruidor do objeto de caixa de diálogo é chamado quando o objeto sai do escopo.  
  
 Caixas de diálogo sem janela restrita normalmente são criadas e pertencentes a uma janela de exibição ou quadro pai — janela do quadro principal do aplicativo ou em uma janela de quadro do documento. O padrão [OnClose](../mfc/reference/cwnd-class.md#onclose) chamadas de manipulador [DestroyWindow](../mfc/reference/cwnd-class.md#destroywindow), que destrói a janela da caixa de diálogo. Se a caixa de diálogo aparece sozinha, sem ponteiros para ele ou outras semânticas especiais de propriedade, você deve substituir [PostNcDestroy](../mfc/reference/cwnd-class.md#postncdestroy) para destruir o objeto de caixa de diálogo do C++. Você também deve substituir [OnCancel](../mfc/reference/cdialog-class.md#oncancel) e chame `DestroyWindow` de dentro dele. Caso contrário, o proprietário da caixa de diálogo deve destruir o objeto de C++ quando ele não é mais necessário.  
  
## <a name="see-also"></a>Consulte também  
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)

