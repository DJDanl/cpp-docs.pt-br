---
title: Criando a classe da caixa de diálogo
ms.date: 11/04/2016
helpviewer_keywords:
- dialog boxes [MFC], creating
- MFC dialog boxes [MFC], creating
- files [MFC], creating
- dialog classes [MFC], Add Class Wizard
- dialog classes [MFC], creating
ms.assetid: d5321741-da41-47a8-bb1c-6a0e8b28c4c1
ms.openlocfilehash: bacedc49fcdabdd5dc7fb0f392a66afd3baadd06
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62241751"
---
# <a name="creating-your-dialog-class"></a>Criando a classe da caixa de diálogo

Para cada caixa de diálogo em seu programa, crie uma nova classe de caixa de diálogo para trabalhar com o recurso de caixa de diálogo.

[Adicionando uma classe](../ide/adding-a-class-visual-cpp.md) explica como criar uma nova classe de caixa de diálogo. Quando você cria uma classe de caixa de diálogo com o Assistente para Adicionar classe, ele grava os seguintes itens na. H e. Arquivos CPP que você especificar:

Na. Arquivo do H:

- Uma declaração de classe para a classe de caixa de diálogo. A classe é derivada de [CDialog](../mfc/reference/cdialog-class.md).

Na. Arquivo CPP:

- Um mapa de mensagem para a classe.

- Um construtor padrão para a caixa de diálogo.

- Uma substituição do [DoDataExchange](../mfc/reference/cwnd-class.md#dodataexchange) função de membro. Edite essa função. Ele é usado para recursos de troca e validação de dados de caixa de diálogo, conforme descrito posteriormente no [troca de dados de caixa de diálogo e validação](../mfc/dialog-data-exchange-and-validation.md).

## <a name="see-also"></a>Consulte também

[Criando uma classe de caixa de diálogo com assistentes de código](../mfc/creating-a-dialog-class-with-code-wizards.md)<br/>
[Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)
