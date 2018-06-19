---
title: Controles de edição avançada sem parte inferior | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- bottomless rich edit controls
- rich edit controls [MFC], bottomless
- CRichEditCtrl class [MFC], bottomless
ms.assetid: 2877dd32-1e9a-4fd1-98c0-66dcbbeef1de
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6f2b08f6c04d345b4ae3ab32c6d0f17a1d8a4647
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33343305"
---
# <a name="bottomless-rich-edit-controls"></a>Controles de edição avançada sem parte inferior
Seu aplicativo pode redimensionar um controle de edição avançada ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)) conforme necessário para que ele é sempre o mesmo tamanho que o seu conteúdo. Um controle de edição com formato dá suporte a essa funcionalidade de "sem parte inferior" chamada enviando sua janela pai um [EN_REQUESTRESIZE](http://msdn.microsoft.com/library/windows/desktop/bb787983) mensagem de notificação sempre que altera o tamanho do seu conteúdo.  
  
 Ao processar o **EN_REQUESTRESIZE** mensagem de notificação, um aplicativo deve redimensionar o controle para as dimensões do [REQRESIZE](http://msdn.microsoft.com/library/windows/desktop/bb787950) estrutura. Um aplicativo também pode mover quaisquer informações de perto o controle para acomodar a alteração do controle de altura. Para redimensionar o controle, você pode usar o `CWnd` função [SetWindowPos](../mfc/reference/cwnd-class.md#setwindowpos).  
  
 Você pode forçar um controle de edição avançada sem parte inferior para enviar um **EN_REQUESTRESIZE** mensagem de notificação usando o [RequestResize](../mfc/reference/cricheditctrl-class.md#requestresize) função de membro. Essa mensagem pode ser útil a [OnSize](../mfc/reference/cwnd-class.md#onsize) manipulador.  
  
 Para receber **EN_REQUESTRESIZE** mensagens de notificação, você deve habilitar a notificação usando o `SetEventMask` função de membro.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)

