---
title: Estrutura TOOLTIPTEXT | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- TOOLTIPTEXT
dev_langs:
- C++
helpviewer_keywords:
- TOOLTIPTEXT structure [MFC]
- tool tips [MFC], notifications
ms.assetid: 547591bf-80f5-400e-a2a7-0708cfffbb5d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: becbdcfcc6dbd26ae3095de098d12dbc078530cc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tooltiptext-structure"></a>Estrutura TOOLTIPTEXT
Na gravação seu [manipulador de notificação de dica de ferramenta](../mfc/handling-ttn-needtext-notification-for-tool-tips.md), você precisa usar o `TOOLTIPTEXT` estrutura. Os membros de `TOOLTIPTEXT` estrutura são:  
  
 `typedef struct {`  
  
 `NMHDR     hdr;        // required for all WM_NOTIFY messages`  
  
 `LPTSTR    lpszText;   // see below`  
  
 `TCHAR     szText[80]; // buffer for tool tip text`  
  
 `HINSTANCE hinst;      // see below`  
  
 `UINT      uflags;     // flag indicating how to interpret the`  
  
 `// idFrom member of the NMHDR structure`  
  
 `// that is included in the structure`  
  
 `} TOOLTIPTEXT, FAR *LPTOOLTIPTEXT;`  
  
 `hdr`  
 Identifica a ferramenta que precisa de texto. O único membro desta estrutura que terá que é a ID de comando. do controle ID de comando do controle será no `idFrom` membro o `NMHDR` estrutura, acessada com a sintaxe `hdr.idFrom`. Consulte [NMHDR](http://msdn.microsoft.com/library/windows/desktop/bb775514) para obter uma discussão de membros a `NMHDR` estrutura.  
  
 `lpszText`  
 Endereço de uma cadeia de caracteres para receber o texto para uma ferramenta.  
  
 `szText`  
 Buffer que recebe o texto da dica de ferramenta. Um aplicativo pode copiar o texto para esse buffer como uma alternativa para especificar um endereço de cadeia de caracteres.  
  
 `hinst`  
 Identificador da instância que contém uma cadeia de caracteres a ser usado como o texto da dica de ferramenta. Se `lpszText` é o endereço do texto da dica de ferramenta, esse membro é nulo.  
  
 Quando você processa o `TTN_NEEDTEXT` notificação de mensagem, especifique a cadeia de caracteres a ser exibido em uma das seguintes maneiras:  
  
-   Copie o texto para o buffer especificado pelo `szText` membro.  
  
-   Copie o endereço do buffer que contém o texto para o `lpszText` membro.  
  
-   Copie o identificador de um recurso de cadeia de caracteres para o `lpszText` membro e o identificador da instância que contém o recurso de cópia de `hinst` membro.  
  
## <a name="see-also"></a>Consulte também  
 [Dicas de ferramenta no Windows não derivadas de CFrameWnd](../mfc/tool-tips-in-windows-not-derived-from-cframewnd.md)

