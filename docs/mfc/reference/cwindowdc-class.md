---
title: Classe CWindowDC
ms.date: 11/04/2016
f1_keywords:
- CWindowDC
- AFXWIN/CWindowDC
- AFXWIN/CWindowDC::CWindowDC
- AFXWIN/CWindowDC::m_hWnd
helpviewer_keywords:
- CWindowDC [MFC], CWindowDC
- CWindowDC [MFC], m_hWnd
ms.assetid: 876a3641-4cde-471c-b0d1-fe58b32af79c
ms.openlocfilehash: 0ef9b4917dc834eb8335690f9b0d171245f5c170
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502148"
---
# <a name="cwindowdc-class"></a>Classe CWindowDC

Derivado de `CDC`.

## <a name="syntax"></a>Sintaxe

```
class CWindowDC : public CDC
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CWindowDC::CWindowDC](#cwindowdc)|Constrói um objeto `CWindowDC`.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CWindowDC::m_hWnd](#m_hwnd)|O HWND ao qual `CWindowDC` está anexado.|

## <a name="remarks"></a>Comentários

Chama a função do Windows [GetWindowDC](/windows/win32/api/winuser/nf-winuser-getwindowdc)no momento da construção e [ReleaseDC](/windows/win32/api/winuser/nf-winuser-releasedc) no momento da destruição. Isso significa que um `CWindowDC` objeto acessa a área de tela inteira de um [CWnd](../../mfc/reference/cwnd-class.md) (áreas cliente e não cliente).

Para obter mais informações sobre `CWindowDC`como usar o, consulte contextos de [dispositivo](../../mfc/device-contexts.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CDC](../../mfc/reference/cdc-class.md)

`CWindowDC`

## <a name="requirements"></a>Requisitos

Cabeçalho: Afxwin. h

##  <a name="cwindowdc"></a>CWindowDC::CWindowDC

Constrói um `CWindowDC` objeto que acessa a área de tela inteira (cliente e não cliente) `CWnd` do objeto apontado por *pWnd*.

```
explicit CWindowDC(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
A janela cuja área de cliente o objeto de contexto de dispositivo será acessado.

### <a name="remarks"></a>Comentários

O construtor chama a função do Windows [GetWindowDC](/windows/win32/api/winuser/nf-winuser-getwindowdc).

Uma exceção (do tipo `CResourceException`) será gerada se a chamada `GetWindowDC` do Windows falhar. Um contexto de dispositivo pode não estar disponível se o Windows já tiver alocado todos os seus contextos de dispositivo disponíveis. Seu aplicativo compete nos cinco contextos de exibição comuns disponíveis em um determinado momento no Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#188](../../mfc/codesnippet/cpp/cwindowdc-class_1.cpp)]

##  <a name="m_hwnd"></a>  CWindowDC::m_hWnd

O HWND do `CWnd` ponteiro é usado para construir o `CWindowDC` objeto.

```
HWND m_hWnd;
```

### <a name="remarks"></a>Comentários

`m_hWnd`é uma variável protegida do tipo HWND.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CWindowDC:: CWindowDC](#cwindowdc).

## <a name="see-also"></a>Consulte também

[Classe CDC](../../mfc/reference/cdc-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDC](../../mfc/reference/cdc-class.md)
