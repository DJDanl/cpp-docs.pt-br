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
ms.openlocfilehash: 9bdaa76dc68467dce1021d9b5f54eaafa248c529
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84624265"
---
# <a name="methods-of-creating-a-status-bar"></a>Métodos de criação de uma barra de status

O MFC fornece duas classes para criar barras de status: [CStatusBar](reference/cstatusbar-class.md) e [CStatusBarCtrl](reference/cstatusbarctrl-class.md) (que encapsula a API de controle comum do Windows). `CStatusBar`fornece toda a funcionalidade do controle comum de barra de status, ele interage automaticamente com menus e barras de ferramentas e lida com muitas das configurações de controle comuns e estruturas necessárias para você; no entanto, o executável resultante geralmente será maior do que o criado usando o `CStatusBarCtrl` .

`CStatusBarCtrl`geralmente resulta em um executável menor, e você pode preferir usar `CStatusBarCtrl` se não pretende integrar a barra de status à arquitetura do MFC. Se você planeja usar `CStatusBarCtrl` e integrar a barra de status na arquitetura do MFC, você deve tomar cuidado adicional para comunicar as manipulações de controle da barra de status para o MFC. Essa comunicação não é difícil; no entanto, ele é um trabalho adicional que é desnecessário quando você usa o `CStatusBar` .

O Visual C++ fornece duas maneiras de aproveitar o controle comum da barra de status.

- Crie a barra de status usando `CStatusBar` e, em seguida, chame [CStatusBar:: GetStatusBarCtrl](reference/cstatusbar-class.md#getstatusbarctrl) para obter acesso às `CStatusBarCtrl` funções de membro.

- Crie a barra de status usando o construtor de [CStatusBarCtrl](reference/cstatusbarctrl-class.md).

Qualquer um dos métodos fornecerá acesso às funções de membro do controle da barra de status. Quando você chama `CStatusBar::GetStatusBarCtrl` , ele retorna uma referência a um `CStatusBarCtrl` objeto para que você possa usar qualquer conjunto de funções de membro. Consulte [CStatusBar](reference/cstatusbar-class.md) para obter informações sobre como construir e criar uma barra de status usando `CStatusBar` .

## <a name="see-also"></a>Consulte também

[Usando CStatusBarCtrl](using-cstatusbarctrl.md)<br/>
[Controles](controls-mfc.md)
