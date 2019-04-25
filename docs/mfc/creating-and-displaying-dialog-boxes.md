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
ms.openlocfilehash: e0b7ff31576b345ac2911e62a6e10469845eecba
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62175024"
---
# <a name="creating-and-displaying-dialog-boxes"></a>Criando e exibindo caixas de diálogo

Criação de um objeto de caixa de diálogo é uma operação de duas fases. Primeiro, construa o objeto de caixa de diálogo e criar a janela da caixa de diálogo. Caixas de diálogo modais e sem janela restrita diferem um pouco o processo usado para criar e exibi-los. A tabela a seguir lista como modal e sem janela restrita diálogo caixas normalmente são construídas e exibidas.

### <a name="dialog-creation"></a>Criar caixa de diálogo

|Tipo de caixa de diálogo|Como criá-la|
|-----------------|----------------------|
|[Sem janela restrita](../mfc/creating-modeless-dialog-boxes.md)|Construir `CDialog`, em seguida, chame `Create` função de membro.|
|[Modal](../mfc/creating-modal-dialog-boxes.md)|Construir `CDialog`, em seguida, chame `DoModal` função de membro.|

Você pode, se desejar, crie sua caixa de diálogo de um [modelo de caixa de diálogo na memória](../mfc/using-a-dialog-template-in-memory.md) que você construiu, em vez de um recurso de modelo de caixa de diálogo. Isso é um tópico avançado, no entanto.

## <a name="see-also"></a>Consulte também

[Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)
