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
ms.openlocfilehash: 6e355c3bcef9edb68e49903dafbf4719fe0aa925
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46417515"
---
# <a name="modal-and-modeless-dialog-boxes"></a>Caixas de diálogo modais e sem janela restrita

Você pode usar a classe [CDialog](../mfc/reference/cdialog-class.md) para gerenciar dois tipos de caixas de diálogo:

- *Caixas de diálogo modais*, que exigem que o usuário responder antes de continuar o programa

- *Caixas de diálogo sem janela restrita*, que permanecer na tela e estão disponíveis para uso a qualquer momento, mas permitir que outras atividades do usuário

A edição de recursos e os procedimentos para criar um modelo de caixa de diálogo são os mesmos para caixas de diálogo modais e sem janela restrita.

Criando uma caixa de diálogo para o seu programa requer as seguintes etapas:

1. Use o [editor de caixa de diálogo](../windows/dialog-editor.md) para criar a caixa de diálogo e criar seu recurso de modelo de caixa de diálogo.

1. Crie uma classe de caixa de diálogo.

1. Conectar-se a [controles do recurso da caixa de diálogo para manipuladores de mensagens](../windows/adding-event-handlers-for-dialog-box-controls.md) na classe de caixa de diálogo.

1. Adicionar membros de dados associados ao controles da caixa de diálogo e especifique [troca de dados de caixa de diálogo](../mfc/dialog-data-exchange.md) e [validações de dados de caixa de diálogo](../mfc/dialog-data-validation.md) para os controles.

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](../mfc/dialog-boxes.md)<br/>
[Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)

