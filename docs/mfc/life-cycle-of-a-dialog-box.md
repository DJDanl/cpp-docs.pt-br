---
title: "Ciclo de vida de uma caixa de diálogo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- dialog boxes [MFC], life cycle
- modal dialog boxes [MFC], life cycle
- modeless dialog boxes [MFC], life cycle
- MFC dialog boxes [MFC], life cycle
- life cycle of dialog boxes [MFC]
ms.assetid: e16fd78e-238d-4f31-8c9d-8564f3953bd9
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 743aed312008d1908701933ec642dd52b0ac3ec8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="life-cycle-of-a-dialog-box"></a>Ciclo de vida de uma caixa de diálogo
Durante o ciclo de vida de uma caixa de diálogo, o usuário chama a caixa de diálogo, geralmente dentro de um manipulador de comando que cria e inicializa o objeto de caixa de diálogo, o usuário interage com a caixa de diálogo e fecha a caixa de diálogo.  
  
 Para caixas de diálogo modal, o manipulador reúne todos os dados inseridos depois que a caixa de diálogo é fechada pelo usuário. Como o objeto de caixa de diálogo existe após sua janela de diálogo foi fechada, você poderá simplesmente usar as variáveis de membro da sua classe de caixa de diálogo para extrair os dados.  
  
 Para caixas de diálogo sem janela restrita, geralmente você pode extrair dados do objeto de caixa de diálogo enquanto a caixa de diálogo ainda está visível. Em algum momento, o objeto de caixa de diálogo é destruído; Quando isso acontece, depende do seu código.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Criando e exibindo caixas de diálogo](../mfc/creating-and-displaying-dialog-boxes.md)  
  
-   [Criando caixas de diálogo modais](../mfc/creating-modal-dialog-boxes.md)  
  
-   [Criando caixas de diálogo sem janela restrita](../mfc/creating-modeless-dialog-boxes.md)  
  
-   [Usando um modelo de caixa de diálogo na memória](../mfc/using-a-dialog-template-in-memory.md)  
  
-   [Definir a cor de plano de fundo da caixa de diálogo](../mfc/setting-the-dialog-boxs-background-color.md)  
  
-   [Inicializando a caixa de diálogo](../mfc/initializing-the-dialog-box.md)  
  
-   [Tratamento de mensagens do Windows na caixa de diálogo](../mfc/handling-windows-messages-in-your-dialog-box.md)  
  
-   [Recuperando dados do objeto de caixa de diálogo](../mfc/retrieving-data-from-the-dialog-object.md)  
  
-   [Fechar a caixa de diálogo](../mfc/closing-the-dialog-box.md)  
  
-   [Destruindo a caixa de diálogo](../mfc/destroying-the-dialog-box.md)  
  
-   [Validação (DDV) e troca de dados de caixa de diálogo (DDX)](../mfc/dialog-data-exchange-and-validation.md)  
  
-   [Caixas de diálogo de folha de propriedade](../mfc/property-sheets-and-property-pages-mfc.md)  
  
## <a name="see-also"></a>Consulte também  
 [Caixas de diálogo](../mfc/dialog-boxes.md)

