---
title: Trabalhando com caixas de diálogo no MFC
ms.date: 09/27/2019
helpviewer_keywords:
- dialog boxes [MFC], life cycle
- modal dialog boxes [MFC], life cycle
- modeless dialog boxes [MFC], life cycle
- MFC dialog boxes [MFC], life cycle
- life cycle of dialog boxes [MFC]
ms.assetid: e16fd78e-238d-4f31-8c9d-8564f3953bd9
ms.openlocfilehash: ad15250cf9a8dd663072cf9423263260bbb40a0e
ms.sourcegitcommit: 1e6386be9084f70def7b3b8b4bab319a117102b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2019
ms.locfileid: "71685727"
---
# <a name="working-with-dialog-boxes-in-mfc"></a>Trabalhando com caixas de diálogo no MFC

Durante o ciclo de vida de uma caixa de diálogo, o usuário invoca a caixa de diálogo, normalmente dentro de um manipulador de comandos que cria e inicializa o objeto de diálogo, o usuário interage com a caixa de diálogo e fecha a caixa de diálogo.

Para caixas de diálogo modais, seu manipulador reúne todos os dados inseridos pelo usuário quando a caixa de diálogo é fechada. Como o objeto de caixa de diálogo existe depois que sua janela de caixa de diálogo é fechada, você pode simplesmente usar as variáveis de membro da sua classe de caixa de diálogo para extrair os dados.

Para caixas de diálogo sem janela restrita, você geralmente pode extrair dados do objeto de diálogo, enquanto a caixa de diálogo ainda está visível. Em algum momento, o objeto da caixa de diálogo é destruído; Quando isso acontece depende do seu código.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Criando e exibindo caixas de diálogo](../mfc/creating-and-displaying-dialog-boxes.md)

- [Criando caixas de diálogo modais](../mfc/creating-modal-dialog-boxes.md)

- [Criando caixas de diálogo sem janela restrita](../mfc/creating-modeless-dialog-boxes.md)

- [Usando um modelo de caixa de diálogo na memória](../mfc/using-a-dialog-template-in-memory.md)

- [Definindo a cor do plano de fundo da caixa de diálogo](../mfc/setting-the-dialog-boxs-background-color.md)

- [Inicializando a caixa de diálogo](../mfc/initializing-the-dialog-box.md)

- [Manipulando mensagens do Windows na caixa de diálogo](../mfc/handling-windows-messages-in-your-dialog-box.md)

- [Recuperando dados do objeto da caixa de diálogo](../mfc/retrieving-data-from-the-dialog-object.md)

- [Fechando a caixa de diálogo](../mfc/closing-the-dialog-box.md)

- [Destruindo a caixa de diálogo](../mfc/destroying-the-dialog-box.md)

- [Troca de dados de caixa de diálogo (campo DDX) e validação (DDV)](../mfc/dialog-data-exchange-and-validation.md)

- [Caixas de diálogo da folha de propriedades](../mfc/property-sheets-and-property-pages-mfc.md)

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](../mfc/dialog-boxes.md)
