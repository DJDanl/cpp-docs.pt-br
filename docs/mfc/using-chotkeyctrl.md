---
title: Usando CHotKeyCtrl
ms.date: 11/04/2016
f1_keywords:
- CHotKeyCtrl
helpviewer_keywords:
- keys, hot and CHotKeyCtrl
- CHotKeyCtrl class [MFC], using
- hot key controls
ms.assetid: 9b207117-d848-4224-8888-c3d197bb0c95
ms.openlocfilehash: f52d676f68718cdd4d16cf93bf0d7e3fd6b03822
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62349848"
---
# <a name="using-chotkeyctrl"></a>Usando CHotKeyCtrl

Um controle de tecla hot, representado pela classe [CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md), é uma janela que exibe uma representação de texto da combinação de chave, o usuário digita nele, como CTRL + SHIFT + Q. Ele também mantém uma representação interna dessa chave na forma de um código de tecla virtual e um conjunto de sinalizadores que representam o estado de deslocamento. O controle de chave de acesso não define a tecla de acesso — isso cabe em seu programa. (Para obter uma lista de códigos de tecla virtuais padrão, consulte WinUser. h).

Use um controle de acesso de chave para obter a entrada do usuário para o qual tecla de atalho a ser associado a um thread ou janela. Controles de tecla de acessados geralmente são usados nas caixas de diálogo, como você pode exibir ao usuário para atribuir uma tecla de acesso. É responsabilidade do programa para recuperar os valores que descrevem a tecla de atalho do controle de chave de acesso e chamar as funções apropriadas para associar a tecla de atalho um thread ou janela.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Usando um controle de tecla de acesso](../mfc/using-a-hot-key-control.md)

- [Configurando uma tecla de acesso](../mfc/setting-a-hot-key.md)

- [Teclas de acesso globais](../mfc/global-hot-keys.md)

- [Teclas de acesso específicas de thread](../mfc/thread-specific-hot-keys.md)

## <a name="see-also"></a>Consulte também

[Controles](../mfc/controls-mfc.md)
