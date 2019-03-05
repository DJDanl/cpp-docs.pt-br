---
title: Métodos de criação de uma barra de status
ms.date: 11/04/2016
helpviewer_keywords:
- CStatusBar class [MFC], vs. CStatusBarCtrl
- methods [MFC], creating status bars
- CStatusBarCtrl class [MFC], vs. CStatusBar
- CStatusBarCtrl class [MFC], creating
- methods [MFC]
- status bars [MFC], creating
ms.assetid: 9aeaf290-7099-4762-a5ba-9c26705333c9
ms.openlocfilehash: a2301301d0012bd93ffedd0452dec140174402e0
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57276878"
---
# <a name="methods-of-creating-a-status-bar"></a>Métodos de criação de uma barra de status

MFC fornece classes para criar barras de status: [CStatusBar](../mfc/reference/cstatusbar-class.md) e [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md) (que encapsula a API de controle comum do Windows). `CStatusBar` fornece toda a funcionalidade de barra de status controle comum, ele automaticamente interage com os menus e barras de ferramentas, e trata muitas das configurações necessárias de controle comuns e estruturas para você. No entanto, o executável resultante geralmente será maior do que é criado usando `CStatusBarCtrl`.

`CStatusBarCtrl` geralmente resulta em um arquivo executável menor e você pode preferir usar `CStatusBarCtrl` se você não pretende integrar a barra de status na arquitetura do MFC. Se você planeja usar `CStatusBarCtrl` e integrar a barra de status na arquitetura do MFC, você deve ter cuidado adicional para comunicar o status da barra manipulações de controle ao MFC. Essa comunicação não é difícil; No entanto, ele é trabalho adicional é desnecessário quando você usar `CStatusBar`.

Visual C++ fornece duas maneiras de aproveitar o controle de barra de status comuns.

- Criar o uso da barra de status `CStatusBar`e, em seguida, chame [CStatusBar::GetStatusBarCtrl](../mfc/reference/cstatusbar-class.md#getstatusbarctrl) para obter acesso ao `CStatusBarCtrl` funções de membro.

- Criar o uso da barra de status [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md)do construtor.

Qualquer um dos métodos lhe dará acesso a funções de membro de controle de barra de status. Quando você chama `CStatusBar::GetStatusBarCtrl`, ele retorna uma referência a um `CStatusBarCtrl` , você pode usar o conjunto de funções de membro de objeto. Ver [CStatusBar](../mfc/reference/cstatusbar-class.md) para obter informações sobre como construir e criar um status de barras usando `CStatusBar`.

## <a name="see-also"></a>Consulte também

[Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
