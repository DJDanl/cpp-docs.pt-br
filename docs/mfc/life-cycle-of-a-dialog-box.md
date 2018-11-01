---
title: Ciclo de vida de uma caixa de diálogo
ms.date: 11/04/2016
helpviewer_keywords:
- dialog boxes [MFC], life cycle
- modal dialog boxes [MFC], life cycle
- modeless dialog boxes [MFC], life cycle
- MFC dialog boxes [MFC], life cycle
- life cycle of dialog boxes [MFC]
ms.assetid: e16fd78e-238d-4f31-8c9d-8564f3953bd9
ms.openlocfilehash: e92489499a3a5aaaf2fb97e8908cb30d5e168240
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50577613"
---
# <a name="life-cycle-of-a-dialog-box"></a>Ciclo de vida de uma caixa de diálogo

Durante o ciclo de vida de uma caixa de diálogo, o usuário invoca a caixa de diálogo, normalmente dentro de um manipulador de comando que cria e inicializa o objeto de caixa de diálogo, o usuário interage com a caixa de diálogo e a caixa de diálogo é fechada.

Para caixas de diálogo modal, seu manipulador reúne todos os dados inseridos depois que a caixa de diálogo é fechada pelo usuário. Como o objeto de caixa de diálogo existe depois que sua janela da caixa de diálogo foi fechada, você pode simplesmente usar as variáveis de membro da sua classe de caixa de diálogo para extrair os dados.

Para caixas de diálogo sem janela restrita, você geralmente pode extrair dados do objeto de caixa de diálogo enquanto a caixa de diálogo ainda está visível. Em algum momento, o objeto de caixa de diálogo é destruído; Quando isso acontece depende do seu código.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Criando e exibindo caixas de diálogo](../mfc/creating-and-displaying-dialog-boxes.md)

- [Criando caixas de diálogo modal](../mfc/creating-modal-dialog-boxes.md)

- [Criando caixas de diálogo sem janela restrita](../mfc/creating-modeless-dialog-boxes.md)

- [Usando um modelo de caixa de diálogo na memória](../mfc/using-a-dialog-template-in-memory.md)

- [Definir a cor do plano de fundo da caixa de diálogo](../mfc/setting-the-dialog-boxs-background-color.md)

- [Inicializando a caixa de diálogo](../mfc/initializing-the-dialog-box.md)

- [Tratamento de mensagens do Windows na caixa de diálogo](../mfc/handling-windows-messages-in-your-dialog-box.md)

- [Recuperando dados do objeto de caixa de diálogo](../mfc/retrieving-data-from-the-dialog-object.md)

- [Fechar a caixa de diálogo](../mfc/closing-the-dialog-box.md)

- [Destruindo a caixa de diálogo](../mfc/destroying-the-dialog-box.md)

- [Troca de dados de caixa de diálogo (DDX) e a validação (DDV)](../mfc/dialog-data-exchange-and-validation.md)

- [Caixas de diálogo de folha de propriedade](../mfc/property-sheets-and-property-pages-mfc.md)

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](../mfc/dialog-boxes.md)

