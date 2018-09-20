---
title: Usando um controle comum como uma janela filho | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- controls [MFC], using as child windows
- windows [MFC], common controls as
- child windows [MFC], common controls as
- common controls [MFC], child windows
- Windows common controls [MFC], child windows
ms.assetid: 608f7d47-7854-4fce-bde9-856c51e76753
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 73ddb010aeb8190c063d2691806e3ebd89d0f744
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46417963"
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

