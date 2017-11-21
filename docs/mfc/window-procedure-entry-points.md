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
ms.openlocfilehash: 99a4cf3fe356cf888101935aba5bec9a599135f9
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="window-procedure-entry-points"></a>Pontos de entrada do procedimento de janela
Para proteger os procedimentos de janela MFC, links módulo estático com uma implementação do procedimento de janela especial. A ligação ocorre automaticamente quando o módulo é vinculado a MFC. Usa esse procedimento de janela a `AFX_MANAGE_STATE` macro para definir corretamente o estado do módulo efetivo, em seguida, ele chama **AfxWndProc**, que por sua vez delega para o `WindowProc` a função de membro do `CWnd`-derivado objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciando os dados de estado dos módulos MFC](../mfc/managing-the-state-data-of-mfc-modules.md)

