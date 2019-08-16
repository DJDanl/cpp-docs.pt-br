---
title: Classe CClientDC
ms.date: 11/04/2016
f1_keywords:
- CClientDC
- AFXWIN/CClientDC
- AFXWIN/CClientDC::CClientDC
- AFXWIN/CClientDC::m_hWnd
helpviewer_keywords:
- CClientDC [MFC], CClientDC
- CClientDC [MFC], m_hWnd
ms.assetid: 8a871d6b-06f8-496e-9fa3-9a5780848369
ms.openlocfilehash: 46428740d052c70218d4443395777428cdf3c3b0
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69507333"
---
# <a name="cclientdc-class"></a>Classe CClientDC

Cuida da chamada das funções do Windows [GetDC](/windows/win32/api/winuser/nf-winuser-getdc) no momento da construção e [ReleaseDC](/windows/win32/api/winuser/nf-winuser-releasedc) no momento da destruição.

## <a name="syntax"></a>Sintaxe

```
class CClientDC : public CDC
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CClientDC::CClientDC](#cclientdc)|Constrói um `CClientDC` objeto conectado `CWnd`ao.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CClientDC::m_hWnd](#m_hwnd)|O HWND da janela para a qual isso `CClientDC` é válido.|

## <a name="remarks"></a>Comentários

Isso significa que o contexto do dispositivo associado a `CClientDC` um objeto é a área do cliente de uma janela.

Para obter mais informações `CClientDC`sobre o, consulte contextos de [dispositivo](../../mfc/device-contexts.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CDC](../../mfc/reference/cdc-class.md)

`CClientDC`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="cclientdc"></a>  CClientDC::CClientDC

Constrói um `CClientDC` objeto que acessa a área do cliente do [CWnd](../../mfc/reference/cwnd-class.md) apontado por *pWnd*.

```
explicit CClientDC(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
A janela cuja área do cliente o objeto de contexto do dispositivo acessará.

### <a name="remarks"></a>Comentários

O construtor chama a função do Windows [GetDC](/windows/win32/api/winuser/nf-winuser-getdc).

Uma exceção (do tipo `CResourceException`) será gerada se a chamada `GetDC` do Windows falhar. Um contexto de dispositivo pode não estar disponível se o Windows já tiver alocado todos os seus contextos de dispositivo disponíveis. Seu aplicativo compete nos cinco contextos de exibição comuns disponíveis em um determinado momento no Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#42](../../mfc/codesnippet/cpp/cclientdc-class_1.cpp)]

##  <a name="m_hwnd"></a>  CClientDC::m_hWnd

O `HWND` `CClientDC` do ponteirousadoparaconstruiroobjeto.`CWnd`

```
HWND m_hWnd;
```

### <a name="remarks"></a>Comentários

*m_hWnd* é uma variável protegida.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CClientDC:: CClientDC](#cclientdc).

## <a name="see-also"></a>Consulte também

[MDI de exemplo do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CDC](../../mfc/reference/cdc-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDC](../../mfc/reference/cdc-class.md)
