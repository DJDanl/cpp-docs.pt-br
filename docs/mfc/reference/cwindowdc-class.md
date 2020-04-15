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
ms.openlocfilehash: 89a822280ddebca942016f9a3a334a7128d8456a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81371974"
---
# <a name="cwindowdc-class"></a>Classe CWindowDC

Derivada de `CDC`.

## <a name="syntax"></a>Sintaxe

```
class CWindowDC : public CDC
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CWindowDC::CWindowDC](#cwindowdc)|Constrói um objeto `CWindowDC`.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CWindowDC::m_hWnd](#m_hwnd)|O HWND ao `CWindowDC` qual este está ligado.|

## <a name="remarks"></a>Comentários

Chama a função do Windows [GetWindowDC](/windows/win32/api/winuser/nf-winuser-getwindowdc)na hora da construção e [ReleaseDC](/windows/win32/api/winuser/nf-winuser-releasedc) no momento da destruição. Isso significa `CWindowDC` que um objeto acessa toda a área de tela de um [CWnd](../../mfc/reference/cwnd-class.md) (áreas cliente e não cliente).

Para obter mais `CWindowDC`informações sobre como usar, consulte [Contextos do dispositivo](../../mfc/device-contexts.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CDC](../../mfc/reference/cdc-class.md)

`CWindowDC`

## <a name="requirements"></a>Requisitos

Cabeçalho: afxwin.h

## <a name="cwindowdccwindowdc"></a><a name="cwindowdc"></a>CWindowDC::CWindowDC

Constrói um `CWindowDC` objeto que acessa toda a área de `CWnd` tela (cliente e não cliente) do objeto apontado por *pWnd*.

```
explicit CWindowDC(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
A janela cuja área cliente o objeto de contexto do dispositivo será acessada.

### <a name="remarks"></a>Comentários

O construtor chama a função Do Windows [GetWindowDC](/windows/win32/api/winuser/nf-winuser-getwindowdc).

Uma exceção `CResourceException`(do tipo) `GetWindowDC` é lançada se a chamada do Windows falhar. Um contexto de dispositivo pode não estar disponível se o Windows já tiver alocado todos os seus contextos de dispositivo disponíveis. Seu aplicativo compete pelos cinco contextos de exibição comuns disponíveis a qualquer momento no Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#188](../../mfc/codesnippet/cpp/cwindowdc-class_1.cpp)]

## <a name="cwindowdcm_hwnd"></a><a name="m_hwnd"></a>CWindowDC::m_hWnd

O HWND `CWnd` do ponteiro é `CWindowDC` usado para construir o objeto.

```
HWND m_hWnd;
```

### <a name="remarks"></a>Comentários

`m_hWnd`é uma variável protegida do tipo HWND.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CWindowDC::CWindowDC](#cwindowdc).

## <a name="see-also"></a>Confira também

[Classe CDC](../../mfc/reference/cdc-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDC](../../mfc/reference/cdc-class.md)
