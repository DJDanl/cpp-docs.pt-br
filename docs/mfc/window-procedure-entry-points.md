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
ms.openlocfilehash: 315526a8f95a1d62ac89f3a76fab492c9b136715
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36956376"
---
# <a name="window-procedure-entry-points"></a>Pontos de entrada do procedimento de janela
Para proteger os procedimentos de janela MFC, links módulo estático com uma implementação do procedimento de janela especial. A ligação ocorre automaticamente quando o módulo é vinculado a MFC. Esse procedimento de janela usa a macro AFX_MANAGE_STATE para definir corretamente o estado do módulo efetivo, ele chama `AfxWndProc`, que por sua vez delega para o `WindowProc` a função de membro do `CWnd`-objeto derivado.  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciando os dados de estado dos módulos MFC](../mfc/managing-the-state-data-of-mfc-modules.md)

