---
title: Estrutura CREATESTRUCT
ms.date: 11/04/2016
f1_keywords:
- CREATESTRUCT
helpviewer_keywords:
- CREATESTRUCT structure [MFC]
ms.assetid: 028c7b5e-4fdc-48da-a550-d3e4f9e6cc85
ms.openlocfilehash: 13f715dc914ccc052945790aeaff9c47bd34ed46
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50619642"
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

*lpCreateParams*<br/>
Pontos de dados a ser usado para criar a janela.

*hInstance*<br/>
Identifica o identificador de instância de módulo do módulo que possui a nova janela.

*hMenu*<br/>
Identifica o menu a ser usado pela nova janela. Se uma janela filho, contém a ID de inteiro.

*hwndParent*<br/>
Identifica a janela que possui a nova janela. Esse membro é NULL se a nova janela é uma janela de nível superior.

*Cy*<br/>
Especifica a altura da nova janela.

*CX*<br/>
Especifica a largura da nova janela.

*y*<br/>
Especifica a coordenada y do canto superior esquerdo da nova janela. As coordenadas são em relação à janela pai se a nova janela é uma janela filho; Caso contrário, as coordenadas são em relação a origem da tela.

*x*<br/>
Especifica a coordenada x do canto superior esquerdo da nova janela. As coordenadas são em relação à janela pai se a nova janela é uma janela filho; Caso contrário, as coordenadas são em relação a origem da tela.

*style*<br/>
Especifica a nova janela [estilo](../../mfc/reference/styles-used-by-mfc.md).

*lpszName*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que especifica o novo nome da janela.

*lpszClass*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que especifica o nome da classe da janela novo Windows (um [WNDCLASS](https://msdn.microsoft.com/library/windows/desktop/ms633576) estrutura; para obter mais informações, consulte o SDK do Windows).

*dwExStyle*<br/>
Especifica o [estilo estendido](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles) para a nova janela.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** WinUser. h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CWnd::OnCreate](../../mfc/reference/cwnd-class.md#oncreate)

