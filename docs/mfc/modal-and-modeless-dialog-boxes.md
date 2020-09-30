---
title: Caixas de diálogo modais e sem janela restrita
ms.date: 11/04/2016
helpviewer_keywords:
- MFC dialog boxes [MFC], modeless
- modeless dialog boxes [MFC]
- MFC dialog boxes [MFC], modal
- modal dialog boxes [MFC]
ms.assetid: e83df336-5994-4b8f-8233-7942f997315b
ms.openlocfilehash: d3497a19ab14dcc9f14dc0419eb65ea033135b6e
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91508861"
---
# <a name="modal-and-modeless-dialog-boxes"></a>Caixas de diálogo modais e sem janela restrita

Você pode usar a classe [CDialog](reference/cdialog-class.md) para gerenciar dois tipos de caixas de diálogo:

- *Caixas de diálogo modais*, que exigem que o usuário responda antes de continuar o programa

- *Caixas de diálogo sem janela restrita*, que permanecem na tela e estão disponíveis para uso a qualquer momento, mas permitem outras atividades do usuário

A edição de recursos e os procedimentos para criar um modelo de caixa de diálogo são os mesmos para caixas de diálogo modais e sem janela restrita.

A criação de uma caixa de diálogo para o programa requer as seguintes etapas:

1. Use o [Editor de diálogo](../windows/dialog-editor.md) para criar a caixa de diálogo e crie seu recurso de modelo de caixa de diálogo.

1. Crie uma classe de caixa de diálogo.

1. Conecte os [controles do recurso de caixa de diálogo aos manipuladores de mensagens](../windows/adding-editing-or-deleting-controls.md) na classe da caixa de diálogo.

1. Adicione os membros de dados associados aos controles da caixa de diálogo e [especifique as](dialog-data-exchange.md) [validações](dialog-data-validation.md) de dados de caixas de diálogo e de dados para os controles.

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](dialog-boxes.md)<br/>
[Trabalhar com caixas de diálogo no MFC](life-cycle-of-a-dialog-box.md)
