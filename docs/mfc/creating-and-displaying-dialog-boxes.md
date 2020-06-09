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
ms.openlocfilehash: 649d64f8e8b894027b9d6850b62d357d79c1dafa
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84616267"
---
# <a name="creating-and-displaying-dialog-boxes"></a>Criando e exibindo caixas de diálogo

A criação de um objeto de caixa de diálogo é uma operação de duas fases. Primeiro, construa o objeto da caixa de diálogo e crie a janela da caixa de diálogo. Caixas de diálogo modais e sem janela restrita diferem um pouco no processo usado para criá-las e exibi-las. A tabela a seguir lista como as caixas de diálogo modais e sem janela restrita são normalmente construídas e exibidas.

### <a name="dialog-creation"></a>Criação de diálogo

|Tipo de diálogo|Como criá-lo|
|-----------------|----------------------|
|[Sem janela restrita](creating-modeless-dialog-boxes.md)|Construct `CDialog` e, em seguida, chame a `Create` função member.|
|[Janelas](creating-modal-dialog-boxes.md)|Construct `CDialog` e, em seguida, chame a `DoModal` função member.|

Você pode, se desejar, criar sua caixa de diálogo de um [modelo de caixa de diálogo na memória](using-a-dialog-template-in-memory.md) que você criou em vez de um recurso de modelo de caixa de diálogo. No entanto, esse é um tópico avançado.

## <a name="see-also"></a>Consulte também

[Trabalhar com caixas de diálogo no MFC](life-cycle-of-a-dialog-box.md)
