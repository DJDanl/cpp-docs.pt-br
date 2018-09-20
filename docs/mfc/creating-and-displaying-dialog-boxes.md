---
title: Criando e exibindo caixas de diálogo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- modal dialog boxes [MFC], creating
- opening dialog boxes
- modeless dialog boxes [MFC], creating
- MFC dialog boxes [MFC], creating
- MFC dialog boxes [MFC], displaying
ms.assetid: 1c5219ee-8b46-44bc-9708-83705d4f248b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 437fb934e95ce527a77038d643e9cee86b6f1f2c
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46387738"
---
# <a name="creating-and-displaying-dialog-boxes"></a>Criando e exibindo caixas de diálogo

Criação de um objeto de caixa de diálogo é uma operação de duas fases. Primeiro, construa o objeto de caixa de diálogo e criar a janela da caixa de diálogo. Caixas de diálogo modais e sem janela restrita diferem um pouco o processo usado para criar e exibi-los. A tabela a seguir lista como modal e sem janela restrita diálogo caixas normalmente são construídas e exibidas.

### <a name="dialog-creation"></a>Criar caixa de diálogo

|Tipo de caixa de diálogo|Como criá-la|
|-----------------|----------------------|
|[Sem janela restrita](../mfc/creating-modeless-dialog-boxes.md)|Construir `CDialog`, em seguida, chame `Create` função de membro.|
|[Janela restrita](../mfc/creating-modal-dialog-boxes.md)|Construir `CDialog`, em seguida, chame `DoModal` função de membro.|

Você pode, se desejar, crie sua caixa de diálogo de um [modelo de caixa de diálogo na memória](../mfc/using-a-dialog-template-in-memory.md) que você construiu, em vez de um recurso de modelo de caixa de diálogo. Isso é um tópico avançado, no entanto.

## <a name="see-also"></a>Consulte também

[Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)

