---
title: Métodos de criação de uma barra de ferramentas
ms.date: 11/04/2016
helpviewer_keywords:
- CToolBarCtrl class [MFC], and CToolBar class [MFC]
- CToolBar class [MFC], creating toolbars
- MFC toolbars
- toolbar controls [MFC]
- toolbar controls [MFC], creating
- CToolBarCtrl class [MFC], creating toolbars
ms.assetid: f19d8d65-d49f-445c-abe8-d47d3e4101c8
ms.openlocfilehash: b70e6f4dc15023b878bb58d6b7d0739eeb173d53
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84624261"
---
# <a name="methods-of-creating-a-toolbar"></a>Métodos de criação de uma barra de ferramentas

O MFC fornece duas classes para criar barras de ferramentas: [CToolBar](reference/ctoolbar-class.md) e [CToolBarCtrl](reference/ctoolbarctrl-class.md) (que encapsula a API de controle comum do Windows). `CToolBar`fornece toda a funcionalidade do controle comum da barra de ferramentas e trata de muitas das configurações de controle comuns e estruturas necessárias para você; no entanto, o executável resultante geralmente será maior do que o criado usando o `CToolBarCtrl` .

`CToolBarCtrl`geralmente resulta em um executável menor, e você pode preferir usar `CToolBarCtrl` se não pretende integrar a barra de ferramentas à arquitetura do MFC. Se você planeja usar `CToolBarCtrl` e integrar a barra de ferramentas à arquitetura do MFC, você deve tomar cuidado adicional para comunicar as manipulações de controle da barra de ferramentas ao MFC. Essa comunicação não é difícil; no entanto, ele é um trabalho adicional que é desnecessário quando você usa o `CToolBar` .

O Visual C++ fornece duas maneiras de aproveitar o controle comum da barra de ferramentas.

- Crie a barra de ferramentas usando `CToolBar` e, em seguida, chame [CToolBar:: GetToolBarCtrl](reference/ctoolbar-class.md#gettoolbarctrl) para obter acesso às `CToolBarCtrl` funções de membro.

- Crie a barra de ferramentas usando o construtor de [CToolBarCtrl](reference/ctoolbarctrl-class.md).

Qualquer um dos métodos fornecerá acesso às funções de membro do controle ToolBar. Quando você chama `CToolBar::GetToolBarCtrl` , ele retorna uma referência a um `CToolBarCtrl` objeto para que você possa usar qualquer conjunto de funções de membro. Consulte [CToolBar](reference/ctoolbar-class.md) para obter informações sobre como construir e criar uma barra de ferramentas usando o `CToolBar` .

## <a name="see-also"></a>Consulte também

[Usando CToolBarCtrl](using-ctoolbarctrl.md)<br/>
[Controles](controls-mfc.md)
