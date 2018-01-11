---
title: Pontos de entrada do procedimento de janela | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- state management, window procedures
- MFC, managing state data
- window procedure entry points
- entry points, window procedures
ms.assetid: a6b46a7f-6e42-45f2-9ae6-82e19fc57148
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5f4e99ce38bd5ae472d688dc779bdd4ccf9fd4c5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="window-procedure-entry-points"></a>Pontos de entrada do procedimento de janela
Para proteger os procedimentos de janela MFC, links módulo estático com uma implementação do procedimento de janela especial. A ligação ocorre automaticamente quando o módulo é vinculado a MFC. Usa esse procedimento de janela a `AFX_MANAGE_STATE` macro para definir corretamente o estado do módulo efetivo, em seguida, ele chama **AfxWndProc**, que por sua vez delega para o `WindowProc` a função de membro do `CWnd`-derivado objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciando os dados de estado dos módulos MFC](../mfc/managing-the-state-data-of-mfc-modules.md)

