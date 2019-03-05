---
title: Criando caixas de diálogo modais
ms.date: 11/04/2016
helpviewer_keywords:
- modal dialog boxes [MFC], creating
- MFC dialog boxes [MFC], creating
- MFC dialog boxes [MFC], modal
ms.assetid: 26c7a68c-79f6-4862-a5a8-6024984644d2
ms.openlocfilehash: 5de6eeb616f32c7b8829d827988a972e41658530
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57304958"
---
# <a name="creating-modal-dialog-boxes"></a>Criando caixas de diálogo modais

Para criar uma caixa de diálogo modal, chamar qualquer um dos dois construtores públicos declarados no [CDialog](../mfc/reference/cdialog-class.md). Em seguida, chame o objeto de caixa de diálogo [DoModal](../mfc/reference/cdialog-class.md#domodal) função de membro para exibir a caixa de diálogo e gerenciar a interação com ele até que o usuário escolhe Okey ou Cancelar. Esse gerenciamento por `DoModal` faz com que a caixa de diálogo modal. Para caixas de diálogo modal, `DoModal` carrega o recurso de caixa de diálogo.

## <a name="see-also"></a>Consulte também

[Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)
