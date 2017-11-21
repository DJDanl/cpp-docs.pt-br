---
title: Estrutura CREATESTRUCT | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: CREATESTRUCT
dev_langs: C++
helpviewer_keywords: CREATESTRUCT structure [MFC]
ms.assetid: 028c7b5e-4fdc-48da-a550-d3e4f9e6cc85
caps.latest.revision: "14"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 67f04b70b47e980455c73550e56d92f4433ee31c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="createstruct-structure"></a>Estrutura CREATESTRUCT
O `CREATESTRUCT` estrutura define os parâmetros de inicialização passados para o procedimento de janela de um aplicativo.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `lpCreateParams`  
 Pontos de dados a ser usado para criar a janela.  
  
 `hInstance`  
 Identifica o identificador de instância de módulo do módulo que possui a nova janela.  
  
 `hMenu`  
 Identifica o menu a ser usado pela nova janela. Se uma janela filho, contém a ID de inteiro.  
  
 `hwndParent`  
 Identifica a janela que possui a nova janela. Esse membro é **nulo** se a nova janela é uma janela de nível superior.  
  
 `cy`  
 Especifica a altura da nova janela.  
  
 `cx`  
 Especifica a largura da nova janela.  
  
 `y`  
 Especifica a coordenada y do canto superior esquerdo da nova janela. As coordenadas são em relação a janela pai se a nova janela é uma janela filho; Caso contrário, as coordenadas são em relação à origem da tela.  
  
 `x`  
 Especifica a coordenada x do canto superior esquerdo da nova janela. As coordenadas são em relação a janela pai se a nova janela é uma janela filho; Caso contrário, as coordenadas são em relação à origem da tela.  
  
 `style`  
 Especifica a nova janela [estilo](../../mfc/reference/styles-used-by-mfc.md).  
  
 `lpszName`  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica o nome da nova janela.  
  
 `lpszClass`  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica o nome da classe a nova janela Windows (um [WNDCLASS](http://msdn.microsoft.com/library/windows/desktop/ms633576) estrutura; para obter mais informações, consulte o SDK do Windows).  
  
 `dwExStyle`  
 Especifica o [estilo estendido](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles) para a nova janela.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** WinUser  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnCreate](../../mfc/reference/cwnd-class.md#oncreate)


