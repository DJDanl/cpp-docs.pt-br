---
title: Usando CHotKeyCtrl
ms.date: 11/04/2016
helpviewer_keywords:
- keys, hot and CHotKeyCtrl
- CHotKeyCtrl class [MFC], using
- hot key controls
ms.assetid: 9b207117-d848-4224-8888-c3d197bb0c95
ms.openlocfilehash: e2002d96a1eba913e260fa92281f730355a83ca5
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447248"
---
# <a name="using-chotkeyctrl"></a>Usando CHotKeyCtrl

Um controle de tecla de atalho, representado pela classe [CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md), é uma janela que exibe uma representação de texto da combinação de teclas que o usuário digita para ele, como CTRL + SHIFT + Q. Ele também mantém uma representação interna dessa chave na forma de um código de chave virtual e um conjunto de sinalizadores que representam o estado de deslocamento. O controle de teclas de atalho não define realmente a tecla de atalho – fazer isso é até o programa. (Para obter uma lista de códigos de chave virtual padrão, consulte WinUser. h.)

Use um controle de tecla de atalho para obter a entrada de um usuário para a qual a chave de acesso será associada a uma janela ou thread. Os controles de tecla de atalho geralmente são usados em caixas de diálogo, como você pode exibir ao solicitar que o usuário atribua uma tecla de atalho. É responsabilidade do seu programa recuperar os valores que descrevem a tecla de acesso do controle de tecla quente e chamar as funções apropriadas para associar a tecla de acesso a uma janela ou thread.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Usando um controle de tecla de acesso](../mfc/using-a-hot-key-control.md)

- [Configurando uma tecla de acesso](../mfc/setting-a-hot-key.md)

- [Teclas de acesso globais](../mfc/global-hot-keys.md)

- [Teclas de acesso específicas de thread](../mfc/thread-specific-hot-keys.md)

## <a name="see-also"></a>Consulte também

[Controles](../mfc/controls-mfc.md)
