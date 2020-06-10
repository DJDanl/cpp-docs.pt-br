---
title: Gerenciando janelas filhos MDI
ms.date: 11/19/2018
f1_keywords:
- MDICLIENT
helpviewer_keywords:
- MDI [MFC], child windows
- child windows [MFC], and MDICLIENT window
- MDICLIENT window [MFC]
- windows [MFC], MDI
- frame windows [MFC], MDI child windows
- child windows [MFC]
- MDI [MFC], frame windows
ms.assetid: 1828d96e-a561-48ae-a661-ba9701de6bee
ms.openlocfilehash: 6e8e3d0aa51eeea112597485a9221dcba4feda87
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618368"
---
# <a name="managing-mdi-child-windows"></a>Gerenciando janelas filhos MDI

As janelas de quadro principal MDI (uma por aplicativo) contêm uma janela filho especial chamada de janela MDICLIENT. A janela MDICLIENT gerencia a área do cliente da janela principal do quadro, e ela própria tem janelas filhas: as janelas de documentos derivadas de `CMDIChildWnd` . Como as janelas de documentos são janelas de quadro (janelas filho MDI), elas também podem ter seus próprios filhos. Em todos esses casos, a janela pai gerencia suas janelas filhas e encaminha alguns comandos para elas.

Em uma janela de quadro MDI, a janela do quadro gerencia a janela MDICLIENT, reposicionando-a em conjunto com barras de controle. A janela MDICLIENT, por sua vez, gerencia todas as janelas de quadros filho MDI. A figura a seguir mostra a relação entre uma janela de quadro MDI, sua janela MDICLIENT e suas janelas de moldura de documento filho.

![Janelas filhas em uma janela de quadro MDI](../mfc/media/vc37gb1.gif "Janelas filhas em uma janela de quadro MDI") <br/>
Janelas de quadro MDI e filhos

Uma janela de quadro MDI também funciona em conjunto com a janela filho MDI atual, se houver uma. A janela de quadro MDI Delega mensagens de comando para o filho MDI antes de tentar tratá-las em si.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Criando janelas de quadro de documento](creating-document-frame-windows.md)

- [Estilos de janela de quadro](frame-window-styles-cpp.md)

## <a name="see-also"></a>Consulte também

[Usando janelas de quadros](using-frame-windows.md)
