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
ms.openlocfilehash: abe8a3220fd37a0375fcf37504c715edf4c6962e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81352300"
---
# <a name="cclientdc-class"></a>Classe CClientDC

Cuida de chamar as funções do Windows [getDC](/windows/win32/api/winuser/nf-winuser-getdc) na hora da construção e [ReleaseDC](/windows/win32/api/winuser/nf-winuser-releasedc) na hora da destruição.

## <a name="syntax"></a>Sintaxe

```
class CClientDC : public CDC
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CClientDC::CClientDC](#cclientdc)|Constrói um `CClientDC` objeto conectado `CWnd`ao .|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CClientDC::m_hWnd](#m_hwnd)|O HWND da janela `CClientDC` para a qual isso é válido.|

## <a name="remarks"></a>Comentários

Isso significa que o contexto `CClientDC` do dispositivo associado a um objeto é a área cliente de uma janela.

Para obter `CClientDC`mais informações sobre , consulte [Contextos do dispositivo](../../mfc/device-contexts.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CDC](../../mfc/reference/cdc-class.md)

`CClientDC`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cclientdccclientdc"></a><a name="cclientdc"></a>CClientDC::CClientDC

Constrói um `CClientDC` objeto que acessa a área do cliente da [Wnd](../../mfc/reference/cwnd-class.md) apontada por *pWnd*.

```
explicit CClientDC(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
A janela cuja área cliente o objeto de contexto do dispositivo será acessada.

### <a name="remarks"></a>Comentários

O construtor chama a função Do Windows [GetDC](/windows/win32/api/winuser/nf-winuser-getdc).

Uma exceção `CResourceException`(do tipo) `GetDC` é lançada se a chamada do Windows falhar. Um contexto de dispositivo pode não estar disponível se o Windows já tiver alocado todos os seus contextos de dispositivo disponíveis. Seu aplicativo compete pelos cinco contextos de exibição comuns disponíveis a qualquer momento no Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#42](../../mfc/codesnippet/cpp/cclientdc-class_1.cpp)]

## <a name="cclientdcm_hwnd"></a><a name="m_hwnd"></a>CClientDC::m_hWnd

O `HWND` do `CWnd` ponteiro usado `CClientDC` para construir o objeto.

```
HWND m_hWnd;
```

### <a name="remarks"></a>Comentários

*m_hWnd* é uma variável protegida.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CClientDC::CClientDC](#cclientdc).

## <a name="see-also"></a>Confira também

[MDI amostra MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CDC](../../mfc/reference/cdc-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDC](../../mfc/reference/cdc-class.md)
