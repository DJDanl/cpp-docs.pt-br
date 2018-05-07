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
ms.openlocfilehash: 1095061cce8ff8f189984aca99a06eb741a46e83
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="window-procedure-entry-points"></a>Pontos de entrada do procedimento de janela
Para proteger os procedimentos de janela MFC, links módulo estático com uma implementação do procedimento de janela especial. A ligação ocorre automaticamente quando o módulo é vinculado a MFC. Usa esse procedimento de janela a `AFX_MANAGE_STATE` macro para definir corretamente o estado do módulo efetivo, em seguida, ele chama **AfxWndProc**, que por sua vez delega para o `WindowProc` a função de membro do `CWnd`-derivado objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciando os dados de estado dos módulos MFC](../mfc/managing-the-state-data-of-mfc-modules.md)

