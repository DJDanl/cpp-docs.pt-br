---
title: Criando a classe da caixa de diálogo
ms.date: 09/06/2019
helpviewer_keywords:
- dialog boxes [MFC], creating
- MFC dialog boxes [MFC], creating
- files [MFC], creating
- dialog classes [MFC], Add Class Wizard
- dialog classes [MFC], creating
ms.assetid: d5321741-da41-47a8-bb1c-6a0e8b28c4c1
ms.openlocfilehash: 424d18196063456245e2a4841b42e6e447bded17
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907323"
---
# <a name="creating-your-dialog-class"></a>Criando a classe da caixa de diálogo

Para cada caixa de diálogo em seu programa, crie uma nova classe de caixa de diálogo para trabalhar com o recurso de caixa de diálogo.

[A adição de uma classe](../ide/adding-a-class-visual-cpp.md) explica como criar uma nova classe de caixa de diálogo. Quando você cria uma classe de diálogo com o [Assistente de classe](reference/mfc-class-wizard.md), ela grava os seguintes itens nos arquivos. h e. cpp que você especificar:

No arquivo. h:

- Uma declaração de classe para a classe da caixa de diálogo. A classe é derivada de [CDialog](../mfc/reference/cdialog-class.md).

No arquivo. cpp:

- Um mapa de mensagens para a classe.

- Um construtor padrão para a caixa de diálogo.

- Uma substituição da função de membro [DoDataExchange](../mfc/reference/cwnd-class.md#dodataexchange) . Edite esta função. Ele é usado para recursos de validação e troca de dados, conforme descrito posteriormente em [troca e validação de dados de caixa de diálogo](../mfc/dialog-data-exchange-and-validation.md).

## <a name="see-also"></a>Consulte também

[Criando uma classe de caixa de diálogo com assistentes de código](../mfc/creating-a-dialog-class-with-code-wizards.md)<br/>
[Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)
