---
title: "Estrutura CREATESTRUCT | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CREATESTRUCT"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura CREATESTRUCT"
ms.assetid: 028c7b5e-4fdc-48da-a550-d3e4f9e6cc85
caps.latest.revision: 14
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura CREATESTRUCT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A estrutura de `CREATESTRUCT` define os parâmetros de inicialização passados ao procedimento da janela de um aplicativo.  
  
## Sintaxe  
  
```  
  
      typedef struct tagCREATESTRUCT {  
   LPVOID lpCreateParams;  
   HANDLE hInstance;  
   HMENU hMenu;  
   HWND hwndParent;  
   int cy;  
   int cx;  
   int y;  
   int x;  
   LONG style;  
   LPCSTR lpszName;  
   LPCSTR lpszClass;  
   DWORD dwExStyle;  
} CREATESTRUCT;  
```  
  
#### Parâmetros  
 `lpCreateParams`  
 Aponta para os dados a serem usados para criar a janela.  
  
 `hInstance`  
 Identifica o identificador do instâncias do módulo que possui a nova janela.  
  
 `hMenu`  
 Identifica o menu a ser usado pela nova janela.  Se uma janela filho, contém a ID de inteiro  
  
 `hwndParent`  
 Identifica a janela que possui a nova janela.  Esse membro é **nulo** se a janela nova é uma janela de nível superior.  
  
 `cy`  
 Especifica a altitude de nova janela.  
  
 `cx`  
 Especifica a largura de nova janela.  
  
 `y`  
 Especifica a coordenada y do canto superior esquerdo da janela nova.  As coordenadas são relativos a janela pai se a janela nova é uma janela filho; se não as coordenadas são relativos à origem da tela.  
  
 `x`  
 Especifica a coordenada x do canto superior esquerdo da janela nova.  As coordenadas são relativos a janela pai se a janela nova é uma janela filho; se não as coordenadas são relativos à origem da tela.  
  
 `style`  
 Especifica [estilo](../../mfc/reference/styles-used-by-mfc.md)de nova janela.  
  
 `lpszName`  
 Aponta para uma cadeia de caracteres com terminação nula que especifica o nome da nova janela.  
  
 `lpszClass`  
 Aponta para uma cadeia de caracteres com terminação nula que especifica o nome da classe do windows da janela nova \(uma estrutura de [WNDCLASS](http://msdn.microsoft.com/library/windows/desktop/ms633576) ; para obter mais informações, consulte [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]\).  
  
 `dwExStyle`  
 Especifica [estilo estendido](../Topic/Extended%20Window%20Styles.md) para a nova janela.  
  
## Requisitos  
 **Header:** winuser.h  
  
## Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnCreate](../Topic/CWnd::OnCreate.md)