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
ms.openlocfilehash: b7bc510f0d0cfc88476c9e222f51bcfeb958e31a
ms.sourcegitcommit: be0e3457f2884551f18e183ef0ea65c3ded7f689
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/28/2018
ms.locfileid: "37078461"
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
 *lpCreateParams*  
 Pontos de dados a ser usado para criar a janela.  
  
 *hInstance*  
 Identifica o identificador de instância de módulo do módulo que possui a nova janela.  
  
 *hMenu*  
 Identifica o menu a ser usado pela nova janela. Se uma janela filho, contém a ID de inteiro.  
  
 *hwndParent*  
 Identifica a janela que possui a nova janela. Esse membro é **nulo** se a nova janela é uma janela de nível superior.  
  
 *Cy*  
 Especifica a altura da nova janela.  
  
 *CX*  
 Especifica a largura da nova janela.  
  
 *y*  
 Especifica a coordenada y do canto superior esquerdo da nova janela. As coordenadas são em relação a janela pai se a nova janela é uma janela filho; Caso contrário, as coordenadas são em relação à origem da tela.  
  
 *x*  
 Especifica a coordenada x do canto superior esquerdo da nova janela. As coordenadas são em relação a janela pai se a nova janela é uma janela filho; Caso contrário, as coordenadas são em relação à origem da tela.  
  
 *style*  
 Especifica a nova janela [estilo](../../mfc/reference/styles-used-by-mfc.md).  
  
 *lpszName*  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica o nome da nova janela.  
  
 *lpszClass*  
 Aponta para uma cadeia de caracteres terminada em nulo que especifica o nome da classe a nova janela Windows (um [WNDCLASS](http://msdn.microsoft.com/library/windows/desktop/ms633576) estrutura; para obter mais informações, consulte o SDK do Windows).  
  
 *dwExStyle*  
 Especifica o [estilo estendido](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles) para a nova janela.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** WinUser  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnCreate](../../mfc/reference/cwnd-class.md#oncreate)


