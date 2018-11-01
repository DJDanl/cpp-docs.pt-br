---
title: Usando um controle comum como uma janela filho
ms.date: 11/04/2016
helpviewer_keywords:
- controls [MFC], using as child windows
- windows [MFC], common controls as
- child windows [MFC], common controls as
- common controls [MFC], child windows
- Windows common controls [MFC], child windows
ms.assetid: 608f7d47-7854-4fce-bde9-856c51e76753
ms.openlocfilehash: 690b48cf50e95265aaf5bdd454e2881b8f5fab3f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50655124"
---
# <a name="using-a-common-control-as-a-child-window"></a>Usando um controle comum como uma janela filho

Qualquer um dos controles comuns do Windows pode ser usado como uma janela filho de qualquer outra janela. O procedimento a seguir descreve como criar um controle comum dinamicamente e, em seguida, trabalhar com ele.

### <a name="to-use-a-common-control-as-a-child-window"></a>Para usar um controle comum como uma janela filho

1. Defina o controle na classe relacionada ou manipulador.

1. Use a substituição do controle do [CWnd::Create](../mfc/reference/cwnd-class.md#create) método para criar o controle do Windows.

1. Depois que o controle foi criado (como antecipada como o `OnCreate` manipulador se subclasse o controle), você pode manipular o controle usando as funções de membro. Consulte as descrições dos controles individuais em [controles](../mfc/controls-mfc.md) para obter detalhes sobre métodos.

1. Quando tiver terminado com o controle, use [CWnd::DestroyWindow](../mfc/reference/cwnd-class.md#destroywindow) para destruir o controle.

## <a name="see-also"></a>Consulte também

[Criando e usando controles](../mfc/making-and-using-controls.md)<br/>
[Controles](../mfc/controls-mfc.md)

