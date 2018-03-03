---
title: "Implementação da barra de status no MFC | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- COldStatusBar
dev_langs:
- C++
helpviewer_keywords:
- status bars [MFC], implementing in MFC
- CStatusBarCtrl class [MFC], and MFC status bars
- CStatusBar class [MFC], and CStatusBarCtrl class [MFC]
- CStatusBarCtrl class [MFC], and CStatusBar class [MFC]
- status bars [MFC], backward compatibility
- status bars [MFC], old with COldStatusBar class [MFC]
- COldStatusBar class [MFC]
- status bars [MFC], and CStatusBarCtrl class
- CStatusBar class [MFC], and MFC status bars
- status indicators
- status bars [MFC], Windows 95 implementation
ms.assetid: be5cd876-38e3-4d5c-b8cb-16d57a16a142
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4d81982e23f100fe75d6cc5769cd19359bfaa6f5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="status-bar-implementation-in-mfc"></a>Implementação da barra de status no MFC
Um [CStatusBar](../mfc/reference/cstatusbar-class.md) objeto é uma barra de controle com uma linha de texto de painéis de saída. Os painéis de saída são usados como linhas de mensagem e indicadores de status. Exemplos incluem as linhas de mensagem de Ajuda do menu que explicam rapidamente o comando de menu selecionado e os indicadores que mostram o status de SCROLL LOCK, NUM LOCK e outras chaves.  
  
 A partir da versão 4.0 do MFC, barras de status são implementadas usando a classe [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md), que encapsula uma barra de controle comum de status. Para compatibilidade com versões anteriores, MFC retém a implementação da barra de status mais antiga na classe **COldStatusBar**. Descreve a documentação de versões anteriores do MFC **COldStatusBar** em `CStatusBar`.  
  
 [CStatusBar::GetStatusBarCtrl](../mfc/reference/cstatusbar-class.md#getstatusbarctrl), uma função de membro novo MFC 4.0, permite aproveitar o suporte para personalização e funcionalidades adicionais da barra de status do controle comum do Windows. `CStatusBar`funções de membro lhe oferece a maioria da funcionalidade de controles comuns do Windows; No entanto, quando você chama `GetStatusBarCtrl`, você pode fornecer as barras de status ainda mais as características de uma barra de status. Quando você chama `GetStatusBarCtrl`, ela retornará uma referência a um `CStatusBarCtrl` objeto. Você pode usar essa referência para manipular o controle de barra de status.  
  
 A figura a seguir mostra uma barra de status que exibe vários indicadores.  
  
 ![Barra de status](../mfc/media/vc37dy1.gif "vc37dy1")  
Uma barra de Status  
  
 Como a barra de ferramentas, o objeto de barra de status é inserido na janela do quadro seu pai e é criado automaticamente quando a janela do quadro é construída. Barra de status, como todas as barras de controle é destruída automaticamente bem quando o quadro pai é destruído.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Atualizando o texto de um painel da barra de status](../mfc/updating-the-text-of-a-status-bar-pane.md)  
  
-   Classes MFC [CStatusBar](../mfc/reference/cstatusbar-class.md) e [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md)  
  
-   [Barras de controle](../mfc/control-bars.md)  
  
-   [Barras da caixa de diálogo](../mfc/dialog-bars.md)  
  
-   [Barras de ferramentas (implementação da barra de ferramentas MFC)](../mfc/mfc-toolbar-implementation.md)  
  
## <a name="see-also"></a>Consulte também  
 [Barras de status](../mfc/status-bars.md)

