---
title: Caixas de diálogo modais e sem janela restrita
ms.date: 11/04/2016
helpviewer_keywords:
- MFC dialog boxes [MFC], modeless
- modeless dialog boxes [MFC]
- MFC dialog boxes [MFC], modal
- modal dialog boxes [MFC]
ms.assetid: e83df336-5994-4b8f-8233-7942f997315b
ms.openlocfilehash: 886229a2b66968bf76129ecb1da838bd36e66215
ms.sourcegitcommit: 1e6386be9084f70def7b3b8b4bab319a117102b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2019
ms.locfileid: "71685188"
---
# <a name="modal-and-modeless-dialog-boxes"></a>Caixas de diálogo modais e sem janela restrita

Você pode usar a classe [CDialog](../mfc/reference/cdialog-class.md) para gerenciar dois tipos de caixas de diálogo:

- *Caixas de diálogo modais*, que exigem que o usuário responda antes de continuar o programa

- *Caixas de diálogo sem janela restrita*, que permanecem na tela e estão disponíveis para uso a qualquer momento, mas permitem outras atividades do usuário

A edição de recursos e os procedimentos para criar um modelo de caixa de diálogo são os mesmos para caixas de diálogo modais e sem janela restrita.

A criação de uma caixa de diálogo para o programa requer as seguintes etapas:

1. Use o [Editor de diálogo](../windows/dialog-editor.md) para criar a caixa de diálogo e crie seu recurso de modelo de caixa de diálogo.

1. Crie uma classe de caixa de diálogo.

1. Conecte os [controles do recurso de caixa de diálogo aos manipuladores de mensagens](../windows/adding-event-handlers-for-dialog-box-controls.md) na classe da caixa de diálogo.

1. Adicione os membros de dados associados aos controles da caixa de diálogo e [especifique as](../mfc/dialog-data-exchange.md) [validações](../mfc/dialog-data-validation.md) de dados de caixas de diálogo e de dados para os controles.

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](../mfc/dialog-boxes.md)<br/>
[Trabalhando com caixas de diálogo no MFC](../mfc/life-cycle-of-a-dialog-box.md)
