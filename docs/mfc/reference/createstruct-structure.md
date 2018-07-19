---
title: Estrutura CREATESTRUCT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CREATESTRUCT
dev_langs:
- C++
helpviewer_keywords:
- CREATESTRUCT structure [MFC]
ms.assetid: 028c7b5e-4fdc-48da-a550-d3e4f9e6cc85
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6036490b21ccbd86dfed56ea90226cbb2db8d596
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37848464"
---
# <a name="createstruct-structure"></a>Estrutura CREATESTRUCT
O `CREATESTRUCT` estrutura define os parâmetros de inicialização passados ao procedimento de janela de um aplicativo.  
  
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
 *lpCreateParams*  
 Pontos de dados a ser usado para criar a janela.  
  
 *hInstance*  
 Identifica o identificador de instância de módulo do módulo que possui a nova janela.  
  
 *hMenu*  
 Identifica o menu a ser usado pela nova janela. Se uma janela filho, contém a ID de inteiro.  
  
 *hwndParent*  
 Identifica a janela que possui a nova janela. Esse membro é NULL se a nova janela é uma janela de nível superior.  
  
 *Cy*  
 Especifica a altura da nova janela.  
  
 *CX*  
 Especifica a largura da nova janela.  
  
 *y*  
 Especifica a coordenada y do canto superior esquerdo da nova janela. As coordenadas são em relação à janela pai se a nova janela é uma janela filho; Caso contrário, as coordenadas são em relação a origem da tela.  
  
 *x*  
 Especifica a coordenada x do canto superior esquerdo da nova janela. As coordenadas são em relação à janela pai se a nova janela é uma janela filho; Caso contrário, as coordenadas são em relação a origem da tela.  
  
 *style*  
 Especifica a nova janela [estilo](../../mfc/reference/styles-used-by-mfc.md).  
  
 *lpszName*  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica o novo nome da janela.  
  
 *lpszClass*  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica o nome da classe da janela novo Windows (um [WNDCLASS](http://msdn.microsoft.com/library/windows/desktop/ms633576) estrutura; para obter mais informações, consulte o SDK do Windows).  
  
 *dwExStyle*  
 Especifica o [estilo estendido](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles) para a nova janela.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** WinUser. h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnCreate](../../mfc/reference/cwnd-class.md#oncreate)


