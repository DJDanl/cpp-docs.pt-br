---
title: Estrutura CREATESTRUCT | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CREATESTRUCT
dev_langs:
- C++
helpviewer_keywords:
- CREATESTRUCT structure
ms.assetid: 028c7b5e-4fdc-48da-a550-d3e4f9e6cc85
caps.latest.revision: 14
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: ec72d4725cb7e5959369b24a6ff7f0e3e9da1ca7
ms.lasthandoff: 02/25/2017

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
 Identifica o menu a ser usado pela nova janela. Se uma janela filho, contém o ID de inteiro.  
  
 `hwndParent`  
 Identifica a janela que possui a nova janela. Esse membro é **nulo** se a nova janela é uma janela de nível superior.  
  
 `cy`  
 Especifica a altura da nova janela.  
  
 `cx`  
 Especifica a largura da nova janela.  
  
 `y`  
 Especifica a coordenada y do canto superior esquerdo da nova janela. Coordenadas são em relação a janela pai, se a nova janela é uma janela filho; Caso contrário, as coordenadas são em relação à origem da tela.  
  
 `x`  
 Especifica a coordenada x do canto superior esquerdo da nova janela. Coordenadas são em relação a janela pai, se a nova janela é uma janela filho; Caso contrário, as coordenadas são em relação à origem da tela.  
  
 `style`  
 Especifica a nova janela [estilo](../../mfc/reference/styles-used-by-mfc.md).  
  
 `lpszName`  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica o novo nome da janela.  
  
 `lpszClass`  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica o nome da classe a nova janela Windows (um [WNDCLASS](http://msdn.microsoft.com/library/windows/desktop/ms633576) estrutura; para obter mais informações, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]).  
  
 `dwExStyle`  
 Especifica o [estilo estendido](../../mfc/reference/extended-window-styles.md) para a nova janela.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** WinUser. h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnCreate](../../mfc/reference/cwnd-class.md#oncreate)



