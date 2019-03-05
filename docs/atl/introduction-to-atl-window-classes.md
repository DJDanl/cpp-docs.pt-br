---
title: Introdução às Classes de janela da ATL
ms.date: 11/04/2016
helpviewer_keywords:
- window classes
ms.assetid: 503efc2c-a269-495d-97cf-3fb300d52f3d
ms.openlocfilehash: 0c3bc70b5edfb089a6276003625b876d8c553dcb
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57301643"
---
# <a name="introduction-to-atl-window-classes"></a>Introdução às Classes de janela da ATL

As seguintes classes ATL são projetadas para implementar e manipular as janelas:

- [CWindow](../atl/reference/cwindow-class.md) permite que você anexe um identificador de janela para o `CWindow` objeto. Você, em seguida, chamar `CWindow` métodos para manipular a janela.

- [CWindowImpl](../atl/reference/cwindowimpl-class.md) permite implementar uma nova janela e processar mensagens com um mapa de mensagem. Você pode criar uma janela com base em um novo Windows classe, superclasse uma classe existente ou subclasse de uma janela existente.

- [CDialogImpl](../atl/reference/cdialogimpl-class.md) permite que você implemente uma modal ou mensagens de processo e a caixa de diálogo sem janela restrita com um mapa de mensagem.

- [CContainedWindowT](../atl/reference/ccontainedwindowt-class.md) é uma classe predefinida que implementa uma janela cujo mapa da mensagem está contido em outra classe. Usando `CContainedWindowT` permite que você centralize o processamento da mensagem em uma classe.

- [CAxDialogImpl](../atl/reference/caxdialogimpl-class.md) permite que você implemente uma caixa de diálogo (modal ou sem-modo) que hospeda controles ActiveX.

- [CSimpleDialog](../atl/reference/csimpledialog-class.md) permite que você implemente uma caixa de diálogo modal com funcionalidade básica.

- [CAxWindow](../atl/reference/caxwindow-class.md) permite que você implemente uma janela que hospeda um controle ActiveX.

- [CAxWindow2T](../atl/reference/caxwindow2t-class.md) permite que você implemente uma janela que hospeda um controle ActiveX licenciado.

Além das classes de janela específico, a ATL fornece várias classes projetadas para facilitar a implementação de um objeto de janela ATL. Elas são as seguintes:

- [CWndClassInfo](../atl/reference/cwndclassinfo-class.md) gerencia as informações de uma nova classe de janela.

- [CWinTraits](../atl/reference/cwintraits-class.md) e [CWinTraitsOR](../atl/reference/cwintraitsor-class.md) fornecem um método simples de padronizar as características de um objeto de janela ATL.

## <a name="see-also"></a>Consulte também

[Classes de janela](../atl/atl-window-classes.md)
