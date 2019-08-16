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
ms.openlocfilehash: d587f1cfa6ec38dd564da196da8130bffac11302
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69503145"
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
|[CPaintDC::CPaintDC](#cpaintdc)|Constrói um `CPaintDC` conectado ao [CWnd](../../mfc/reference/cwnd-class.md)especificado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPaintDC::m_ps](#m_ps)|Contém o [PAINTSTRUCT](/windows/win32/api/winuser/ns-winuser-paintstruct) usado para pintar a área do cliente.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CPaintDC::m_hWnd](#m_hwnd)|O HWND ao qual esse `CPaintDC` objeto está anexado.|

## <a name="remarks"></a>Comentários

Ele executa um [CWnd:: BeginPaint](../../mfc/reference/cwnd-class.md#beginpaint) no momento da construção e [CWnd:: EndPaint](../../mfc/reference/cwnd-class.md#endpaint) no momento da destruição.

Um `CPaintDC` objeto só pode ser usado ao responder a uma mensagem [WM_PAINT](/windows/win32/gdi/wm-paint) , geralmente em sua `OnPaint` função de membro do manipulador de mensagens.

Para obter mais informações sobre `CPaintDC`como usar o, consulte contextos de [dispositivo](../../mfc/device-contexts.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CDC](../../mfc/reference/cdc-class.md)

`CPaintDC`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="cpaintdc"></a>CPaintDC::CPaintDC

Constrói um `CPaintDC` objeto, prepara a janela do aplicativo para pintura e armazena a estrutura [PAINTSTRUCT](/windows/win32/api/winuser/ns-winuser-paintstruct) na variável de membro [m_ps](#m_ps) .

```
explicit CPaintDC(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Aponta para o `CWnd` objeto ao qual o `CPaintDC` objeto pertence.

### <a name="remarks"></a>Comentários

Uma exceção (do tipo `CResourceException`) será gerada se a chamada [GetDC](/windows/win32/api/winuser/nf-winuser-getdc) do Windows falhar. Um contexto de dispositivo pode não estar disponível se o Windows já tiver alocado todos os seus contextos de dispositivo disponíveis. Seu aplicativo compete nos cinco contextos de exibição comuns disponíveis em um determinado momento no Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#97](../../mfc/codesnippet/cpp/cpaintdc-class_1.cpp)]

##  <a name="m_hwnd"></a>  CPaintDC::m_hWnd

O `HWND` ao qual este `CPaintDC` objeto está anexado.

```
HWND m_hWnd;
```

### <a name="remarks"></a>Comentários

*m_hWnd* é uma variável protegida do tipo HWND.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#98](../../mfc/codesnippet/cpp/cpaintdc-class_2.cpp)]

##  <a name="m_ps"></a>  CPaintDC::m_ps

`m_ps`é uma variável de membro público do tipo [PAINTSTRUCT](/windows/win32/api/winuser/ns-winuser-paintstruct).

```
PAINTSTRUCT m_ps;
```

### <a name="remarks"></a>Comentários

É o `PAINTSTRUCT` que é passado para e preenchido por [CWnd:: BeginPaint](../../mfc/reference/cwnd-class.md#beginpaint).

O `PAINTSTRUCT` contém informações que o aplicativo usa para pintar a área do cliente da janela associada a um `CPaintDC` objeto.

Observe que você pode acessar o identificador de contexto do dispositivo por `PAINTSTRUCT`meio do. No entanto, você pode acessar o identificador mais diretamente `m_hDC` por meio da `CPaintDC` variável de membro que herda do CDC.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CPaintDC:: m_hWnd](#m_hwnd).

## <a name="see-also"></a>Consulte também

[MDI de exemplo do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CDC](../../mfc/reference/cdc-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
