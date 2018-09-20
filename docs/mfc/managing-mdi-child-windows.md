---
title: Gerenciando o Windows de filho MDI | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- MDICLIENT
dev_langs:
- C++
helpviewer_keywords:
- MDI [MFC], child windows
- child windows [MFC], and MDICLIENT window
- MDICLIENT window [MFC]
- windows [MFC], MDI
- frame windows [MFC], MDI child windows
- child windows [MFC]
- MDI [MFC], frame windows
ms.assetid: 1828d96e-a561-48ae-a661-ba9701de6bee
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 45989b7c07d27db1d7b2cda68751bd6165ee5382
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46428272"
---
# <a name="managing-mdi-child-windows"></a>Gerenciando janelas filhos MDI

Janelas de quadro principal de MDI (um por aplicativo) contêm uma janela filho especial chamada janela MDICLIENT. A janela MDICLIENT gerencia a área de cliente da janela do quadro principal e, em si tem janelas filho: as janelas de documentos, derivadas de `CMDIChildWnd`. Como as janelas de documentos são janelas de quadro em si (janelas MDI filho), eles também podem ter seus próprios filhos. Em todos esses casos, a janela pai gerencia suas janelas filho e encaminha alguns comandos para eles.

Em uma janela de quadro MDI, a janela do quadro gerencia a janela MDICLIENT, reposicionamento-lo em conjunto com barras de controle. Janela MDICLIENT, por sua vez, gerencia todas as janelas de quadro MDI filho. A figura a seguir mostra a relação entre uma janela de quadro MDI, sua janela MDICLIENT e suas janelas de quadro de documento filho.

![Janelas filho em uma janela de quadro MDI](../mfc/media/vc37gb1.gif "vc37gb1") Windows de quadro MDI e filhos

Uma janela de quadro MDI também funciona em conjunto com a janela filho MDI atual, se houver um. A janela de quadro MDI delega as mensagens de comando para o filho MDI antes de tentar tratá-las em si.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Criando janelas com moldura de documento](../mfc/creating-document-frame-windows.md)

- [Estilos de janela com moldura](../mfc/frame-window-styles-cpp.md)

## <a name="see-also"></a>Consulte também

[Usando janelas com moldura](../mfc/using-frame-windows.md)

