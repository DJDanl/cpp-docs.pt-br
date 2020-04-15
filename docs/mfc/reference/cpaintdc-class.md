---
title: Classe CPaintDC
ms.date: 11/04/2016
f1_keywords:
- CPaintDC
- AFXWIN/CPaintDC
- AFXWIN/CPaintDC::CPaintDC
- AFXWIN/CPaintDC::m_ps
- AFXWIN/CPaintDC::m_hWnd
helpviewer_keywords:
- CPaintDC [MFC], CPaintDC
- CPaintDC [MFC], m_ps
- CPaintDC [MFC], m_hWnd
ms.assetid: 7e245baa-bf9b-403e-a637-7218adf28fab
ms.openlocfilehash: 55342b03454a6dba07bc10ea5f0464c34e0e8db3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374770"
---
# <a name="cpaintdc-class"></a>Classe CPaintDC

Uma classe de contexto de dispositivo derivada do [CDC](../../mfc/reference/cdc-class.md).

## <a name="syntax"></a>Sintaxe

```
class CPaintDC : public CDC
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPaintDC::CPaintDC](#cpaintdc)|Constrói um `CPaintDC` conectado ao [CWnd](../../mfc/reference/cwnd-class.md)especificado .|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPaintDC::m_ps](#m_ps)|Contém o [PAINTSTRUCT](/windows/win32/api/winuser/ns-winuser-paintstruct) usado para pintar a área do cliente.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CPaintDC::m_hWnd](#m_hwnd)|O HWND ao `CPaintDC` qual este objeto está conectado.|

## <a name="remarks"></a>Comentários

Ele executa um [CWnd::BeginPaint](../../mfc/reference/cwnd-class.md#beginpaint) na hora da construção e [CWnd::EndPaint](../../mfc/reference/cwnd-class.md#endpaint) na hora da destruição.

Um `CPaintDC` objeto só pode ser usado ao responder `OnPaint` a uma mensagem [WM_PAINT,](/windows/win32/gdi/wm-paint) geralmente na função de membro do manipulador de mensagens.

Para obter mais `CPaintDC`informações sobre como usar, consulte [Contextos do dispositivo](../../mfc/device-contexts.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CDC](../../mfc/reference/cdc-class.md)

`CPaintDC`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cpaintdccpaintdc"></a><a name="cpaintdc"></a>CPaintDC::CPaintDC

Constrói um `CPaintDC` objeto, prepara a janela de aplicação para pintura e armazena a estrutura [PAINTSTRUCT](/windows/win32/api/winuser/ns-winuser-paintstruct) na variável [membro m_ps.](#m_ps)

```
explicit CPaintDC(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Aponta para `CWnd` o objeto `CPaintDC` ao qual o objeto pertence.

### <a name="remarks"></a>Comentários

Uma exceção `CResourceException`(do tipo) é lançada se a chamada do Windows [GetDC](/windows/win32/api/winuser/nf-winuser-getdc) falhar. Um contexto de dispositivo pode não estar disponível se o Windows já tiver alocado todos os seus contextos de dispositivo disponíveis. Seu aplicativo compete pelos cinco contextos de exibição comuns disponíveis a qualquer momento no Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#97](../../mfc/codesnippet/cpp/cpaintdc-class_1.cpp)]

## <a name="cpaintdcm_hwnd"></a><a name="m_hwnd"></a>CPaintDC::m_hWnd

Ao `HWND` qual `CPaintDC` este objeto está anexado.

```
HWND m_hWnd;
```

### <a name="remarks"></a>Comentários

*m_hWnd* é uma variável protegida do tipo HWND.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#98](../../mfc/codesnippet/cpp/cpaintdc-class_2.cpp)]

## <a name="cpaintdcm_ps"></a><a name="m_ps"></a>CPaintDC::m_ps

`m_ps`é uma variável de membro público do tipo [PAINTSTRUCT](/windows/win32/api/winuser/ns-winuser-paintstruct).

```
PAINTSTRUCT m_ps;
```

### <a name="remarks"></a>Comentários

É o `PAINTSTRUCT` que é passado e preenchido por [CWnd::BeginPaint](../../mfc/reference/cwnd-class.md#beginpaint).

O `PAINTSTRUCT` contém informações que o aplicativo usa para pintar `CPaintDC` a área cliente da janela associada a um objeto.

Observe que você pode acessar o `PAINTSTRUCT`cabo de contexto do dispositivo através do . No entanto, você pode acessar `m_hDC` a `CPaintDC` alça mais diretamente através da variável membro que herda do CDC.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CPaintDC::m_hWnd](#m_hwnd).

## <a name="see-also"></a>Confira também

[MDI amostra MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CDC](../../mfc/reference/cdc-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
