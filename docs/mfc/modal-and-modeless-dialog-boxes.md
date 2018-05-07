---
title: Caixas de diálogo modais e sem janela restrita | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC dialog boxes [MFC], modeless
- modeless dialog boxes [MFC]
- MFC dialog boxes [MFC], modal
- modal dialog boxes [MFC]
ms.assetid: e83df336-5994-4b8f-8233-7942f997315b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c4f03d67e1eb9962f4303694db4850e800151404
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="modal-and-modeless-dialog-boxes"></a>Caixas de diálogo modais e sem janela restrita
Você pode usar a classe [CDialog](../mfc/reference/cdialog-class.md) para gerenciar dois tipos de caixas de diálogo:  
  
-   *Caixas de diálogo modais*, que exige que o usuário responda antes de continuar o programa  
  
-   *Caixas de diálogo sem janela restrita*, que permanecem na tela e estão disponíveis para uso a qualquer momento, mas permitir que outras atividades de usuário  
  
 A edição de recurso e os procedimentos para criar um modelo de caixa de diálogo são as mesmas para caixas de diálogo modais e sem janela restrita.  
  
 Criando uma caixa de diálogo para o programa exige as seguintes etapas:  
  
1.  Use o [editor de caixa de diálogo](../windows/dialog-editor.md) para criar a caixa de diálogo e criar o recurso de modelo de caixa de diálogo.  
  
2.  Crie uma classe de caixa de diálogo.  
  
3.  Conecte-se a [controles do recurso da caixa de diálogo para manipuladores de mensagens](../windows/adding-event-handlers-for-dialog-box-controls.md) na classe de caixa de diálogo.  
  
4.  Adicionar membros de dados associados com os controles da caixa de diálogo e especificar [troca de dados de caixa de diálogo](../mfc/dialog-data-exchange.md) e [validações de dados de caixa de diálogo](../mfc/dialog-data-validation.md) para os controles.  
  
## <a name="see-also"></a>Consulte também  
 [Caixas de diálogo](../mfc/dialog-boxes.md)   
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)

