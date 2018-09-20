---
title: Usando CHotKeyCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- CHotKeyCtrl
dev_langs:
- C++
helpviewer_keywords:
- keys, hot and CHotKeyCtrl
- CHotKeyCtrl class [MFC], using
- hot key controls
ms.assetid: 9b207117-d848-4224-8888-c3d197bb0c95
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bd966b74590d0e7641f2f789b5c45f901a3cf8c8
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46421499"
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

