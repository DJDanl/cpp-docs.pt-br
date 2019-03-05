---
title: Pontos de entrada do procedimento de janela
ms.date: 11/04/2016
helpviewer_keywords:
- state management, window procedures
- MFC, managing state data
- window procedure entry points
- entry points, window procedures
ms.assetid: a6b46a7f-6e42-45f2-9ae6-82e19fc57148
ms.openlocfilehash: 6d91e2c432588afc5a84f7189fa87a7fc2531b1a
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57288606"
---
# <a name="window-procedure-entry-points"></a>Pontos de entrada do procedimento de janela

Para proteger os procedimentos da janela MFC, links de estáticos um módulo com uma implementação do procedimento de janela especial. A vinculação ocorre automaticamente quando o módulo é vinculado com o MFC. Esse procedimento de janela usa a macro AFX_MANAGE_STATE para definir corretamente o estado do módulo eficaz, ele chama `AfxWndProc`, que por sua vez delega para o `WindowProc` função de membro de apropriado `CWnd`-objeto derivado.

## <a name="see-also"></a>Consulte também

[Gerenciando os dados de estado dos módulos MFC](../mfc/managing-the-state-data-of-mfc-modules.md)
