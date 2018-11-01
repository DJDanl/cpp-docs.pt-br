---
title: Pontos de entrada do procedimento de janela
ms.date: 11/04/2016
helpviewer_keywords:
- state management, window procedures
- MFC, managing state data
- window procedure entry points
- entry points, window procedures
ms.assetid: a6b46a7f-6e42-45f2-9ae6-82e19fc57148
ms.openlocfilehash: 9e395ff96d27476bc2869e23139cb2d1233f02ee
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50500913"
---
# <a name="window-procedure-entry-points"></a>Pontos de entrada do procedimento de janela

Para proteger os procedimentos da janela MFC, links de estáticos um módulo com uma implementação do procedimento de janela especial. A vinculação ocorre automaticamente quando o módulo é vinculado com o MFC. Esse procedimento de janela usa a macro AFX_MANAGE_STATE para definir corretamente o estado do módulo eficaz, ele chama `AfxWndProc`, que por sua vez delega para o `WindowProc` função de membro de apropriado `CWnd`-objeto derivado.

## <a name="see-also"></a>Consulte também

[Gerenciando os dados de estado dos módulos MFC](../mfc/managing-the-state-data-of-mfc-modules.md)

