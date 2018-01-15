---
title: "Controles de edição de área de transferência em Rich | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- pasting Clipboard data
- CRichEditCtrl class [MFC], paste operation
- cut operation in CRichEditCtrl class [MFC]
- CRichEditCtrl class [MFC], Clipboard operations
- copy operations in rich edit controls
- Clipboard, operations in CRichEditCtrl
- rich edit controls [MFC], Clipboard operations
ms.assetid: 15ce66bc-2636-4a35-a2ae-d52285dc1af6
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ec468b1f763e2f855f25fd8808d83605fb10673a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="clipboard-operations-in-rich-edit-controls"></a>Operações da Área de Transferência em controles de edição avançada
Seu aplicativo pode colar o conteúdo da área de transferência em um controle de edição avançada ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)) usando o formato de área de transferência melhor disponível ou em um formato específico de área de transferência. Você também pode determinar se um controle de edição é capaz de colar um formato de área de transferência.  
  
 Você pode copiar ou recortar o conteúdo da seleção atual usando o [cópia](../mfc/reference/cricheditctrl-class.md#copy) ou [Recortar](../mfc/reference/cricheditctrl-class.md#cut) função de membro. Da mesma forma, você pode colar o conteúdo da área de transferência em um controle de edição com formato usando o [colar](../mfc/reference/cricheditctrl-class.md#paste) função de membro. O controle cola o primeiro formato disponível que reconhece, que é provavelmente o formato mais descritivo.  
  
 Para colar um formato específico de área de transferência, você pode usar o [PasteSpecial](../mfc/reference/cricheditctrl-class.md#pastespecial) função de membro. Essa função é útil para aplicativos com um comando Colar especial que permite que o usuário selecionar o formato de área de transferência. Você pode usar o [CanPaste](../mfc/reference/cricheditctrl-class.md#canpaste) função de membro para determinar se um determinado formato é reconhecido pelo controle.  
  
 Você também pode usar `CanPaste` para determinar se qualquer formato de área de transferência disponível é reconhecido por um controle de edição. Essa função é útil para o `OnInitMenuPopup` manipulador. Um aplicativo pode habilitar ou cinza seu comando Colar dependendo se o controle pode colar qualquer formato disponível.  
  
 Formatos register área de transferência dois controles edição com formato: formato rich text e um formato chamado RichEdit texto e objetos. Um aplicativo pode registrar esses formatos, usando o [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) de função, especificando o **CF_RTF** e **CF_RETEXTOBJ** valores.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)

