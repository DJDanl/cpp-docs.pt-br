---
title: Criando caixas de diálogo modais
ms.date: 11/04/2016
helpviewer_keywords:
- modal dialog boxes [MFC], creating
- MFC dialog boxes [MFC], creating
- MFC dialog boxes [MFC], modal
ms.assetid: 26c7a68c-79f6-4862-a5a8-6024984644d2
ms.openlocfilehash: ed0fe3b7ef8aeddea01f573bfe8e1c01a6b5b443
ms.sourcegitcommit: 1e6386be9084f70def7b3b8b4bab319a117102b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2019
ms.locfileid: "71685676"
---
# <a name="creating-modal-dialog-boxes"></a>Criando caixas de diálogo modais

Para criar uma caixa de diálogo modal, chame qualquer um dos dois construtores públicos declarados em [CDialog](../mfc/reference/cdialog-class.md). Em seguida, chame a função de membro [DoModal](../mfc/reference/cdialog-class.md#domodal) do objeto Dialog para exibir a caixa de diálogo e gerenciar a interação com ela até que o usuário escolha OK ou cancelar. Esse gerenciamento por `DoModal` é o que torna a caixa de diálogo modal. Para caixas de diálogo modais, `DoModal` carrega o recurso de caixa de diálogo.

## <a name="see-also"></a>Consulte também

[Trabalhando com caixas de diálogo no MFC](../mfc/life-cycle-of-a-dialog-box.md)
