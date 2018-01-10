---
title: Usando CAnimateCtrl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: CAnimateCtrl
dev_langs: C++
helpviewer_keywords:
- animation controls [MFC], CAnimateCtrl class
- controls [MFC], animation
- CAnimateCtrl class [MFC], about CAnimateCtrl class [MFC]
ms.assetid: 696c0805-bef0-4e2e-a9e7-b37b9215b7f0
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f27fd24c3c4334476c78ba0b59c90cbbb0d51f5d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-canimatectrl"></a>Usando CAnimateCtrl
Um controle de animação, representado pela classe [CAnimateCtrl](../mfc/reference/canimatectrl-class.md), é uma janela que exibe um clipe no formato de áudio vídeo intercalados (AVI) — o formato de áudio/vídeo do Windows padrão. Um clipe AVI é uma série de quadros de bitmap, como um filme.  
  
 Como o thread continua executando enquanto o clipe AVI é exibido, um uso comum para um controle de animação é para indicar a atividade do sistema durante uma operação demorada. Por exemplo, a caixa de diálogo Localizar do Windows exibe uma lente de aumento móvel como o sistema procurará um arquivo.  
  
 Controles de animação só podem reproduzir clipes AVI simples, e eles não dão suporte a som. (Para obter uma lista completa de limitações, consulte [CAnimateCtrl](../mfc/reference/canimatectrl-class.md).) Como os recursos de um controle de animação são muito limitados e sujeitos a alterações, você deve usar uma alternativa, como o controle MCIWnd se precisar de um controle para fornecer a reprodução de multimídia e/ou recursos de gravação. Para obter mais informações sobre o controle MCIWnd, consulte a documentação de multimídia.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Usando um controle de animação](../mfc/using-an-animation-control.md)  
  
-   [Notificações enviadas por controles de animação](../mfc/notifications-sent-by-animation-controls.md)  
  
## <a name="see-also"></a>Consulte também  
 [Controles](../mfc/controls-mfc.md)

