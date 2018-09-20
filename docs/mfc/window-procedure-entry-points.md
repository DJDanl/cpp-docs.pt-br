---
title: Pontos de entrada do procedimento de janela | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- state management, window procedures
- MFC, managing state data
- window procedure entry points
- entry points, window procedures
ms.assetid: a6b46a7f-6e42-45f2-9ae6-82e19fc57148
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c3226df51d2a83484de78d0d76c9af67e150e8eb
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46403182"
---
# <a name="window-procedure-entry-points"></a>Pontos de entrada do procedimento de janela

Para proteger os procedimentos da janela MFC, links de estáticos um módulo com uma implementação do procedimento de janela especial. A vinculação ocorre automaticamente quando o módulo é vinculado com o MFC. Esse procedimento de janela usa a macro AFX_MANAGE_STATE para definir corretamente o estado do módulo eficaz, ele chama `AfxWndProc`, que por sua vez delega para o `WindowProc` função de membro de apropriado `CWnd`-objeto derivado.

## <a name="see-also"></a>Consulte também

[Gerenciando os dados de estado dos módulos MFC](../mfc/managing-the-state-data-of-mfc-modules.md)

