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
ms.openlocfilehash: fab75268e39d75b67db435ebb8d0af6c0b8371fd
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620513"
---
# <a name="creating-your-dialog-class"></a>Criando a classe da caixa de diálogo

Para cada caixa de diálogo em seu programa, crie uma nova classe de caixa de diálogo para trabalhar com o recurso de caixa de diálogo.

[A adição de uma classe](../ide/adding-a-class-visual-cpp.md) explica como criar uma nova classe de caixa de diálogo. Quando você cria uma classe de diálogo com o [Assistente de classe](reference/mfc-class-wizard.md), ela grava os seguintes itens nos arquivos. h e. cpp que você especificar:

No arquivo. h:

- Uma declaração de classe para a classe da caixa de diálogo. A classe é derivada de [CDialog](reference/cdialog-class.md).

No arquivo. cpp:

- Um mapa de mensagens para a classe.

- Um construtor padrão para a caixa de diálogo.

- Uma substituição da função de membro [DoDataExchange](reference/cwnd-class.md#dodataexchange) . Edite esta função. Ele é usado para recursos de validação e troca de dados, conforme descrito posteriormente em [troca e validação de dados de caixa de diálogo](dialog-data-exchange-and-validation.md).

## <a name="see-also"></a>Consulte também

[Criando uma classe de caixa de diálogo com assistentes de código](creating-a-dialog-class-with-code-wizards.md)<br/>
[Trabalhar com caixas de diálogo no MFC](life-cycle-of-a-dialog-box.md)
