---
title: Criando caixas de diálogo modais
ms.date: 11/04/2016
helpviewer_keywords:
- modal dialog boxes [MFC], creating
- MFC dialog boxes [MFC], creating
- MFC dialog boxes [MFC], modal
ms.assetid: 26c7a68c-79f6-4862-a5a8-6024984644d2
ms.openlocfilehash: ed7cc94982a46e542a5174d4d46b8013cc84ffa4
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84622974"
---
# <a name="creating-modal-dialog-boxes"></a>Criando caixas de diálogo modais

Para criar uma caixa de diálogo modal, chame qualquer um dos dois construtores públicos declarados em [CDialog](reference/cdialog-class.md). Em seguida, chame a função de membro [DoModal](reference/cdialog-class.md#domodal) do objeto Dialog para exibir a caixa de diálogo e gerenciar a interação com ela até que o usuário escolha OK ou cancelar. Esse gerenciamento `DoModal` é o que torna a caixa de diálogo modal. Para caixas de diálogo modais, `DoModal` o carrega o recurso de caixa de diálogo.

## <a name="see-also"></a>Consulte também

[Trabalhar com caixas de diálogo no MFC](life-cycle-of-a-dialog-box.md)
