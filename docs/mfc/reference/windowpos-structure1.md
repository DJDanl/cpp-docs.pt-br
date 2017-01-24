---
title: "Estrutura WINDOWPOS | Microsoft Docs"
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
  - "WINDOWPOS"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura WINDOWPOS"
ms.assetid: a4ea7cd9-c4c2-4480-9c55-cbbff72195e1
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura WINDOWPOS
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `WINDOWPOS` contém informações sobre o tamanho e a posição de uma janela.  
  
## Sintaxe  
  
```  
  
      typedef struct tagWINDOWPOS { /* wp */  
   HWND hwnd;  
   HWND hwndInsertAfter;  
   int x;  
   int y;  
   int cx;  
   int cy;  
   UINT flags;  
} WINDOWPOS;  
```  
  
#### Parâmetros  
 *hwnd*  
 Identifica a janela.  
  
 *hwndInsertAfter*  
 Identifica a janela por trás de que essa janela é imposta.  
  
 *x*  
 Especifica a posição da borda esquerda da janela.  
  
 *y*  
 Especifica a posição da borda direita da janela.  
  
 `cx`  
 Especifica a largura da janela, em pixels.  
  
 `cy`  
 Especifica a altitude da janela, em pixels.  
  
 `flags`  
 Especifica opções no posicionamento.  Esse membro pode ser um dos seguintes valores:  
  
-   **SWP\_DRAWFRAME** desenha um quadro \(definido na descrição da classe para a janela\) em torno da janela.  A janela recebe uma mensagem de `WM_NCCALCSIZE` .  
  
-   **SWP\_FRAMECHANGED** envia uma mensagem de `WM_NCCALCSIZE` a janela, mesmo se o tamanho da janela não estiver sendo alterado.  Se esse sinalizador não for especificado, `WM_NCCALCSIZE` é enviada somente quando o tamanho da janela está sendo alterado.  
  
-   **SWP\_HIDEWINDOW** oculta a janela.  
  
-   `SWP_NOACTIVATE` não ativa a janela.  
  
-   Descarta**SWP\_NOCOPYBITS** todo o conteúdo da área do cliente.  Se esse sinalizador não for especificado, o conteúdo válidos da área do cliente são salvos e copiados de novo na área de cliente depois que a janela é feita dimensionar ou reposicionada.  
  
-   `SWP_NOMOVE` retém a posição atual \(ignora os membros de **x** e de **y** \).  
  
-   **SWP\_NOOWNERZORDER** não altera a posição da janela do proprietário em ordem z.  
  
-   `SWP_NOSIZE` retém o tamanho atual \(ignora os membros de **cx** e de **cy** \).  
  
-   **SWP\_NOREDRAW** não redesenha alterações.  
  
-   **SWP\_NOREPOSITION** mesmos que **SWP\_NOOWNERZORDER**.  
  
-   **SWP\_NOSENDCHANGING** impede que a janela recebe a mensagem de `WM_WINDOWPOSCHANGING` .  
  
-   `SWP_NOZORDER` retém a ordenação do atual \(ignora o membro de **hwndInsertAfter** \).  
  
-   **SWP\_SHOWWINDOW** exibe a janela.  
  
## Requisitos  
 **Header:** winuser.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnWindowPosChanging](../Topic/CWnd::OnWindowPosChanging.md)