---
title: "Estrutura TOOLTIPTEXT | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "TOOLTIPTEXT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "dicas de ferramenta [C++], notificações"
  - "Estrutura TOOLTIPTEXT"
ms.assetid: 547591bf-80f5-400e-a2a7-0708cfffbb5d
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura TOOLTIPTEXT
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Ao escrever seu [manipulador de notificação da dica de ferramenta](../Topic/Handling%20TTN_NEEDTEXT%20Notification%20for%20Tool%20Tips.md), você precisa usar a estrutura de `TOOLTIPTEXT` .  Os membros da estruturade `TOOLTIPTEXT`são:  
  
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
 Identifica a ferramenta que precisa do texto.  O único membro dessa estrutura que você pode precisar é a ID de comando de controle  A ID de comando de controle será o membro de `idFrom` da estrutura de `NMHDR` , acessado com a sintaxe `hdr.idFrom`.  Consulte [NMHDR](http://msdn.microsoft.com/library/windows/desktop/bb775514) para uma discussão de membros da estrutura de `NMHDR` .  
  
 `lpszText`  
 Endereço de uma cadeia de caracteres para receber o texto para uma ferramenta.  
  
 `szText`  
 Armazenar em buffer que recebe o texto da dica de ferramenta.  Um aplicativo pode copiar o texto nesse buffer como uma alternativa para especificar um endereço de cadeia de caracteres.  
  
 `hinst`  
 Identificador de instância que contém uma cadeia de caracteres a ser usada como o texto da dica de ferramenta.  Se `lpszText` é o endereço do texto da dica de ferramenta, esse membro é NULL.  
  
 Quando você processa a notificação de `TTN_NEEDTEXT` , especifique a cadeia de caracteres a ser exibida em uma das seguintes maneiras:  
  
-   Copiar o texto no buffer especificado pelo membro de `szText` .  
  
-   Copie o endereço do buffer que contém o texto para o membro de `lpszText` .  
  
-   Copie o identificador de um recurso de cadeia de caracteres ao membro de `lpszText` , e copie o identificador da instância que contém o recurso ao membro de `hinst` .  
  
## Consulte também  
 [Dicas de ferramenta no Windows derivadas de CFrameWnd](../mfc/tool-tips-in-windows-not-derived-from-cframewnd.md)