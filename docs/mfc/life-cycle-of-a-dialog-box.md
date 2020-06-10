---
title: Trabalhar com caixas de diálogo no MFC
ms.date: 09/27/2019
helpviewer_keywords:
- dialog boxes [MFC], life cycle
- modal dialog boxes [MFC], life cycle
- modeless dialog boxes [MFC], life cycle
- MFC dialog boxes [MFC], life cycle
- life cycle of dialog boxes [MFC]
ms.assetid: e16fd78e-238d-4f31-8c9d-8564f3953bd9
ms.openlocfilehash: d365be21ef19a6779df649e9368fdc0cda4851df
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621442"
---
# <a name="working-with-dialog-boxes-in-mfc"></a>Trabalhar com caixas de diálogo no MFC

Durante o ciclo de vida de uma caixa de diálogo, o usuário invoca a caixa de diálogo, normalmente dentro de um manipulador de comandos que cria e inicializa o objeto de diálogo, o usuário interage com a caixa de diálogo e fecha a caixa de diálogo.

Para caixas de diálogo modais, seu manipulador reúne todos os dados inseridos pelo usuário quando a caixa de diálogo é fechada. Como o objeto de caixa de diálogo existe depois que sua janela de caixa de diálogo é fechada, você pode simplesmente usar as variáveis de membro da sua classe de caixa de diálogo para extrair os dados.

Para caixas de diálogo sem janela restrita, você geralmente pode extrair dados do objeto de diálogo, enquanto a caixa de diálogo ainda está visível. Em algum momento, o objeto da caixa de diálogo é destruído; Quando isso acontece depende do seu código.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Criando e exibindo caixas de diálogo](creating-and-displaying-dialog-boxes.md)

- [Criando caixas de diálogo restritas](creating-modal-dialog-boxes.md)

- [Criando caixas de diálogo sem janela restrita](creating-modeless-dialog-boxes.md)

- [Usando um modelo da caixa de diálogo na memória](using-a-dialog-template-in-memory.md)

- [Definindo a cor do plano de fundo da caixa de diálogo](setting-the-dialog-boxs-background-color.md)

- [Inicializando a caixa de diálogo](initializing-the-dialog-box.md)

- [Manipulando mensagens do Windows na caixa de diálogo](handling-windows-messages-in-your-dialog-box.md)

- [Recuperando dados do objeto da caixa de diálogo](retrieving-data-from-the-dialog-object.md)

- [Fechando a caixa de diálogo](closing-the-dialog-box.md)

- [Destruindo a caixa de diálogo](destroying-the-dialog-box.md)

- [Troca de dados de caixa de diálogo (campo DDX) e validação (DDV)](dialog-data-exchange-and-validation.md)

- [Caixas de diálogo da folha de propriedades](property-sheets-and-property-pages-mfc.md)

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](dialog-boxes.md)
