---
title: Gerenciando janelas filhos MDI | Microsoft Docs
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
ms.openlocfilehash: 58ddef11e56da760bbecaa47f03dfa6c57dfa3ed
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36929475"
---
# <a name="managing-mdi-child-windows"></a>Gerenciando janelas filhos MDI
Janelas de quadro principal MDI (uma por aplicativo) contém uma janela filho especial denominada janela MDICLIENT. A janela MDICLIENT gerencia a área cliente da janela do quadro principal, e tem janelas filho: as janelas de documentos, derivadas de `CMDIChildWnd`. Como as janelas de documentos são janelas com moldura próprios (windows de filho MDI), eles também podem ter seus próprios filhos. Em todos esses casos, a janela pai gerencia suas janelas filho e encaminha alguns comandos para eles.  
  
 Em uma janela de quadro MDI, a janela do quadro gerencia janela MDICLIENT, reposicione em conjunto com barras de controle. Janela MDICLIENT, por sua vez, gerencia todas as janelas de quadro filho MDI. A figura a seguir mostra a relação entre uma janela de quadro MDI, sua janela MDICLIENT e janelas de quadro de documento filho.  
  
 ![Janelas filho em uma janela de quadro MDI](../mfc/media/vc37gb1.gif "vc37gb1")  
Filhos e janelas de quadro MDI  
  
 Uma janela de quadro MDI também funciona em conjunto com a janela filho MDI atual, se houver um. A janela do quadro MDI delega as mensagens de comando para o filho MDI antes de tentar tratá-los em si.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Criando janelas com moldura de documento](../mfc/creating-document-frame-windows.md)  
  
-   [Estilos de janela com moldura](../mfc/frame-window-styles-cpp.md)  
  
## <a name="see-also"></a>Consulte também  
 [Usando janelas com moldura](../mfc/using-frame-windows.md)

