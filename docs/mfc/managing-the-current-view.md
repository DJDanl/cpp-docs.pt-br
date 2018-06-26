---
title: Gerenciando a exibição atual | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- views [MFC], and OnActivateView method [MFC]
- views [MFC], deactivating
- views [MFC], activating
- frame windows [MFC], current view
- OnActivateView method [MFC]
- views [MFC], current
- deactivating views [MFC]
- current view in frame window [MFC]
ms.assetid: 0a1cc22d-d646-4536-9ad2-3cb6d7092e4a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 09d29f4bc0b62e5824209759d45e63c1d9e2daa6
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36928734"
---
# <a name="managing-the-current-view"></a>Gerenciando a exibição atual
Como parte da implementação padrão do windows do quadro, uma janela do quadro mantém o controle de um modo de exibição ativo no momento. Se a janela do quadro contiver mais de uma exibição, como o exemplo em uma janela separadora, o modo de exibição atual é o modo de exibição mais recente em uso. O modo de exibição ativo é independente da janela ativa no Windows ou o foco de entrada atual.  
  
 Quando o modo de exibição ativo é alterado, o framework notifica o modo de exibição atual chamando o [OnActivateView](../mfc/reference/cview-class.md#onactivateview) função de membro. Você pode determinar se o modo de exibição está sendo ativada ou desativada examinando `OnActivateView`do *bActivate* parâmetro. Por padrão, `OnActivateView` define o foco para o modo de exibição atual na ativação. Você pode substituir `OnActivateView` para executar qualquer processamento especial quando o modo de exibição é desativado ou reativado. Por exemplo, você talvez queira fornecem indicações visuais especiais para distinguir o modo de exibição ativo de outras exibições inativas.  
  
 Uma janela do quadro encaminha os comandos para o modo de exibição atual (ativo), conforme descrito em [roteamento de comando](../mfc/command-routing.md), como parte de roteamento de comando padrão.  
  
## <a name="see-also"></a>Consulte também  
 [Usando janelas com moldura](../mfc/using-frame-windows.md)

