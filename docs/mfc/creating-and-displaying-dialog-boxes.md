---
title: Criando e exibindo caixas de diálogo
ms.date: 11/04/2016
helpviewer_keywords:
- modal dialog boxes [MFC], creating
- opening dialog boxes
- modeless dialog boxes [MFC], creating
- MFC dialog boxes [MFC], creating
- MFC dialog boxes [MFC], displaying
ms.assetid: 1c5219ee-8b46-44bc-9708-83705d4f248b
ms.openlocfilehash: 6d23e4d2c9249ce248eb8092963036f2ba5cacac
ms.sourcegitcommit: 1e6386be9084f70def7b3b8b4bab319a117102b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2019
ms.locfileid: "71685740"
---
# <a name="creating-and-displaying-dialog-boxes"></a>Criando e exibindo caixas de diálogo

A criação de um objeto de caixa de diálogo é uma operação de duas fases. Primeiro, construa o objeto da caixa de diálogo e crie a janela da caixa de diálogo. Caixas de diálogo modais e sem janela restrita diferem um pouco no processo usado para criá-las e exibi-las. A tabela a seguir lista como as caixas de diálogo modais e sem janela restrita são normalmente construídas e exibidas.

### <a name="dialog-creation"></a>Criação de diálogo

|Tipo de caixa de diálogo|Como criá-lo|
|-----------------|----------------------|
|[Sem janela restrita](../mfc/creating-modeless-dialog-boxes.md)|Construa `CDialog` e, em seguida, chame a função de membro `Create`.|
|[Janelas](../mfc/creating-modal-dialog-boxes.md)|Construa `CDialog` e, em seguida, chame a função de membro `DoModal`.|

Você pode, se desejar, criar sua caixa de diálogo de um [modelo de caixa de diálogo na memória](../mfc/using-a-dialog-template-in-memory.md) que você criou em vez de um recurso de modelo de caixa de diálogo. No entanto, esse é um tópico avançado.

## <a name="see-also"></a>Consulte também

[Trabalhando com caixas de diálogo no MFC](../mfc/life-cycle-of-a-dialog-box.md)
