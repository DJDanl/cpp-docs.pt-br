---
title: Classe CLinkCtrl
ms.date: 11/04/2016
f1_keywords:
- CLinkCtrl
- AFXCMN/CLinkCtrl
- AFXCMN/CLinkCtrl::CLinkCtrl
- AFXCMN/CLinkCtrl::Create
- AFXCMN/CLinkCtrl::CreateEx
- AFXCMN/CLinkCtrl::GetIdealHeight
- AFXCMN/CLinkCtrl::GetIdealSize
- AFXCMN/CLinkCtrl::GetItem
- AFXCMN/CLinkCtrl::GetItemID
- AFXCMN/CLinkCtrl::GetItemState
- AFXCMN/CLinkCtrl::GetItemUrl
- AFXCMN/CLinkCtrl::HitTest
- AFXCMN/CLinkCtrl::SetItem
- AFXCMN/CLinkCtrl::SetItemID
- AFXCMN/CLinkCtrl::SetItemState
- AFXCMN/CLinkCtrl::SetItemUrl
helpviewer_keywords:
- CLinkCtrl [MFC], CLinkCtrl
- CLinkCtrl [MFC], Create
- CLinkCtrl [MFC], CreateEx
- CLinkCtrl [MFC], GetIdealHeight
- CLinkCtrl [MFC], GetIdealSize
- CLinkCtrl [MFC], GetItem
- CLinkCtrl [MFC], GetItemID
- CLinkCtrl [MFC], GetItemState
- CLinkCtrl [MFC], GetItemUrl
- CLinkCtrl [MFC], HitTest
- CLinkCtrl [MFC], SetItem
- CLinkCtrl [MFC], SetItemID
- CLinkCtrl [MFC], SetItemState
- CLinkCtrl [MFC], SetItemUrl
ms.assetid: d1cd876a-ecca-42db-8ac4-9cd327df0cd4
ms.openlocfilehash: 37d9e624c40f0d6aa7f3d3fa1ed3d97ffa478ee7
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505697"
---
# <a name="clinkctrl-class"></a>Classe CLinkCtrl

Fornece a funcionalidade do controle SysLink comum do Windows.

## <a name="syntax"></a>Sintaxe

```
class CLinkCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CLinkCtrl::CLinkCtrl](#clinkctrl)|Constrói um objeto `CLinkCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CLinkCtrl::Create](#create)|Cria um controle de link e o anexa a um `CLinkCtrl` objeto.|
|[CLinkCtrl::CreateEx](#createex)|Cria um controle de link com estilos estendidos e anexa-o `CLinkCtrl` a um objeto.|
|[CLinkCtrl::GetIdealHeight](#getidealheight)|Recupera a altura ideal do controle de link.|
|[CLinkCtrl::GetIdealSize](#getidealsize)|Calcula a altura preferida do texto do link para o controle de link atual, dependendo da largura especificada do link.|
|[CLinkCtrl::GetItem](#getitem)|Recupera os Estados e atributos de um item de controle de link.|
|[CLinkCtrl::GetItemID](#getitemid)|Recupera a ID de um item de controle de link.|
|[CLinkCtrl::GetItemState](#getitemstate)|Recupera o estado do item de controle de link.|
|[CLinkCtrl::GetItemUrl](#getitemurl)|Recupera a URL representada pelo item de controle de link.|
|[CLinkCtrl::HitTest](#hittest)|Determina se o usuário clicou no link especificado.|
|[CLinkCtrl::SetItem](#setitem)|Define os Estados e atributos de um item de controle de link.|
|[CLinkCtrl::SetItemID](#setitemid)|Define a ID de um item de controle de link.|
|[CLinkCtrl::SetItemState](#setitemstate)|Define o estado do item de controle de link.|
|[CLinkCtrl::SetItemUrl](#setitemurl)|Define a URL representada pelo item de controle de link.|

## <a name="remarks"></a>Comentários

Um "controle de link" fornece uma maneira conveniente de inserir links de hipertexto em uma janela. O controle real é uma janela que renderiza o texto marcado para cima e inicia os aplicativos apropriados quando o usuário clica em um link inserido. Há suporte para vários links em um controle e eles podem ser acessados por um índice baseado em zero.

Esse controle (e, portanto `CLinkCtrl` , a classe) está disponível somente para programas em execução no Windows XP e posterior.

Para obter mais informações, consulte [controle Syslink](/windows/win32/Controls/syslink-overview) na SDK do Windows.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CLinkCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn. h

##  <a name="clinkctrl"></a>  CLinkCtrl::CLinkCtrl

Constrói um objeto `CLinkCtrl`.

```
CLinkCtrl();
```

##  <a name="create"></a>  CLinkCtrl::Create

Cria um controle de link e o anexa a um `CLinkCtrl` objeto.

```
virtual BOOL Create(
    LPCTSTR lpszLinkMarkup,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);

virtual BOOL Create(DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*lpszLinkMarkup*<br/>
Ponteiro para uma cadeia de caracteres terminada em zero que contém o texto marcado para exibição. Para obter mais informações, consulte a seção "marcação e acesso ao link" no tópico [visão geral dos controles Syslink](/windows/win32/Controls/syslink-overview).

*dwStyle*<br/>
Especifica o estilo do controle de link. Aplique qualquer combinação de estilos de controle. Consulte [estilos de controle comuns](/windows/win32/Controls/common-control-styles) no `Windows SDK` para obter mais informações.

*rect*<br/>
Especifica o tamanho e a posição do controle de link. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) .

*pParentWnd*<br/>
Especifica a janela pai do controle de link. Ele não deve ser nulo.

*nID*<br/>
Especifica a ID do controle de link.

### <a name="return-value"></a>Valor de retorno

TRUE se a inicialização tiver sido bem-sucedida; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Você constrói um `CLinkCtrl` objeto em duas etapas. Primeiro, chame o construtor e, em `Create`seguida, chame, que cria o controle de link e o `CLinkCtrl` anexa ao objeto. Se você quiser usar estilos estendidos do Windows com seu controle, chame [CLinkCtrl:: CreateEx](#createex) em `Create`vez de.

A segunda forma do `Create` método é preterida. Use o primeiro formulário que especifica o parâmetro *lpszLinkMarkup* .

### <a name="example"></a>Exemplo

O exemplo de código a seguir define duas variáveis `m_Link1` , `m_Link2`chamadas e, que são usadas para acessar dois controles de link.

[!code-cpp[NVC_MFC_CLinkCtrl_s1#2](../../mfc/reference/codesnippet/cpp/clinkctrl-class_1.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir cria um controle de link com base no local de outro controle de link. O carregador de recursos cria o primeiro controle de link quando seu aplicativo é iniciado. Quando o aplicativo entra no método OnInitDialog, você cria o segundo controle de link relativo à posição do primeiro controle de link. Em seguida, redimensione o segundo controle de link para ajustar o texto que ele exibe.

[!code-cpp[NVC_MFC_CLinkCtrl_s1#1](../../mfc/reference/codesnippet/cpp/clinkctrl-class_2.cpp)]

##  <a name="createex"></a>  CLinkCtrl::CreateEx

Cria um controle de link com estilos estendidos e anexa-o `CLinkCtrl` a um objeto.

```
virtual BOOL CreateEx(
    LPCTSTR lpszLinkMarkup,
    DWORD dwExStyle,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);

virtual BOOL CreateEx(DWORD  dwExStyle,
    DWORD  dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT  nID);
```

### <a name="parameters"></a>Parâmetros

*lpszLinkMarkup*<br/>
Ponteiro para uma cadeia de caracteres terminada em zero que contém o texto marcado para exibição. Para obter mais informações, consulte a seção "marcação e acesso ao link" no tópico [visão geral dos controles Syslink](/windows/win32/Controls/syslink-overview).

*dwExStyle*<br/>
Especifica o estilo estendido do controle de link. Para obter uma lista de estilos estendidos do Windows, consulte o parâmetro *dwExStyle* para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*dwStyle*<br/>
Especifica o estilo do controle de link. Aplique qualquer combinação de estilos de controle. Para obter mais informações, consulte [estilos comuns de controle](/windows/win32/Controls/common-control-styles) na SDK do Windows.

*rect*<br/>
Especifica o tamanho e a posição do controle de link. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) .

*pParentWnd*<br/>
Especifica a janela pai do controle de link. Ele não deve ser nulo.

*nID*<br/>
Especifica a ID do controle de link.

### <a name="return-value"></a>Valor de retorno

TRUE se a inicialização tiver sido bem-sucedida; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de [Create](#create) para aplicar constantes de estilo do Windows estendidas.

A segunda forma do `CreateEx` método é preterida. Use o primeiro formulário que especifica o parâmetro *lpszLinkMarkup* .

##  <a name="getidealheight"></a>  CLinkCtrl::GetIdealHeight

Recupera a altura ideal do controle de link.

```
int GetIdealHeight() const;
```

### <a name="return-value"></a>Valor de retorno

A altura ideal do controle, em pixels.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento da mensagem [LM_GETIDEALHEIGHT](/windows/win32/Controls/lm-getidealheight)do Win32, conforme descrito na SDK do Windows.

##  <a name="getidealsize"></a>  CLinkCtrl::GetIdealSize

Calcula a altura preferida do texto do link para o controle de link atual, dependendo da largura especificada do link.

```
int GetIdealSize(
    int cxMaxWidth,
    SIZE* pSize) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*cxMaxWidth*|no A largura máxima do link, em pixels.|
|[out] \* *pSize*|Um ponteiro para uma estrutura de [tamanho](/windows/win32/api/windef/ns-windef-size) do Windows. Quando esse método retorna, o membro *CY* da `SIZE` estrutura contém a altura do texto do link ideal para a largura do texto do link que é especificada por *cxMaxWidth*. O membro *CX* da estrutura contém a largura do texto do link que é realmente necessária.|

### <a name="return-value"></a>Valor de retorno

A altura preferida do texto do link, em pixels. O valor de retorno é o mesmo que o valor do membro *CY* da `SIZE` estrutura.

### <a name="remarks"></a>Comentários

Para obter um exemplo do `GetIdealSize` método, consulte o exemplo em [CLinkCtrl:: Create](#create).

Esse método envia a mensagem [LM_GETIDEALSIZE](/windows/win32/Controls/lm-getidealsize) , que é descrita na SDK do Windows.

##  <a name="getitem"></a>  CLinkCtrl::GetItem

Recupera os Estados e atributos de um item de controle de link.

```
BOOL GetItem(PLITEM pItem) const;
```

### <a name="parameters"></a>Parâmetros

*pItem*<br/>
Um ponteiro para uma estrutura [litem](/windows/win32/api/commctrl/ns-commctrl-litem) para receber informações do item.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento da mensagem [LM_GETITEM](/windows/win32/Controls/lm-getitem)do Win32, conforme descrito na SDK do Windows.

##  <a name="getitemid"></a>  CLinkCtrl::GetItemID

Recupera a ID de um item de controle de link.

```
BOOL GetItemID(
    int iLink,
    CString& strID) const;

BOOL GetItemID(
    int iLink,
    LPWSTR szID,
    UINT cchID) const;
```

### <a name="parameters"></a>Parâmetros

*iLink*<br/>
O índice de um item de controle de link.

*strID*<br/>
Um objeto [CStringT](../../atl-mfc-shared/reference/cstringt-class.md) que contém a ID do item especificado.

*szID*<br/>
Uma cadeia de caracteres terminada em nulo que contém a ID do item especificado.

*cchID*<br/>
O tamanho em caracteres do buffer *szID* .

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

> [!NOTE]
>  Essa função também retornará FALSE se o buffer de *szID ou strID* for menor que MAX_LINKID_TEXT.

### <a name="remarks"></a>Comentários

Recupera a ID de um item de controle de link específico. Para obter mais informações, consulte a mensagem do Win32 [LM_GETITEM](/windows/win32/Controls/lm-getitem) no SDK do Windows.

##  <a name="getitemstate"></a>  CLinkCtrl::GetItemState

Recupera o estado do item de controle de link.

```
BOOL GetItemState(
    int iLink,
    UINT* pnState,
    UINT stateMask = LIS_FOCUSED | LIS_ENABLED | LIS_VISITED) const;
```

### <a name="parameters"></a>Parâmetros

*iLink*<br/>
O índice de um item de controle de link.

*pnState*<br/>
O valor do item de estado especificado.

*stateMask*<br/>
Combinação de sinalizadores que descreve qual item de Estado deve ser obtido. Para obter uma lista de valores, consulte a descrição do `state` membro na estrutura [litem](/windows/win32/api/commctrl/ns-commctrl-litem) . Os itens permitidos são idênticos aos permitidos no `state`.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Recupera o valor do item de estado especificado de um item de controle de link específico. Para obter mais informações, consulte a mensagem do Win32 [LM_GETITEM](/windows/win32/Controls/lm-getitem) no SDK do Windows.

##  <a name="getitemurl"></a>  CLinkCtrl::GetItemUrl

Recupera a URL representada pelo item de controle de link.

```
BOOL GetItemUrl(
    int iLink,
    CString& strUrl) const;

BOOL GetItemUrl(
    int iLink,
    LPWSTR szUrl,
    UINT cchUrl) const;
```

### <a name="parameters"></a>Parâmetros

*iLink*<br/>
O índice de um item de controle de link.

*strUrl*<br/>
Um objeto [CStringT](../../atl-mfc-shared/reference/cstringt-class.md) que contém a URL representada pelo item especificado

*szUrl*<br/>
Uma cadeia de caracteres terminada em nulo que contém a URL representada pelo item especificado

*cchUrl*<br/>
O tamanho em caracteres do buffer *szURL* .

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

> [!NOTE]
>  Essa função também retornará FALSE se o buffer de *szURL ou strURL* for menor que MAX_LINKID_TEXT.

### <a name="remarks"></a>Comentários

Recupera a URL representada pelo item de controle de link especificado. Para obter mais informações, consulte a mensagem do Win32 [LM_GETITEM](/windows/win32/Controls/lm-getitem) no SDK do Windows.

##  <a name="hittest"></a>  CLinkCtrl::HitTest

Determina se o usuário clicou no link especificado.

```
BOOL HitTest(PLHITTESTINFO phti) const;
```

### <a name="parameters"></a>Parâmetros

*phti*<br/>
Ponteiro para uma `LHITTESTINFO` estrutura que contém qualquer informação sobre o link no qual o usuário clicou.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento da mensagem [LM_HITTEST](/windows/win32/Controls/lm-hittest)do Win32, conforme descrito na SDK do Windows.

##  <a name="setitem"></a>  CLinkCtrl::SetItem

Define os Estados e atributos de um item de controle de link.

```
BOOL SetItem(PLITEM pItem);
```

### <a name="parameters"></a>Parâmetros

*pItem*<br/>
Um ponteiro para uma estrutura [litem](/windows/win32/api/commctrl/ns-commctrl-litem) que contém as informações a serem definidas.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento da mensagem [LM_SETITEM](/windows/win32/Controls/lm-setitem)do Win32, conforme descrito na SDK do Windows.

##  <a name="setitemid"></a>  CLinkCtrl::SetItemID

Recupera a ID de um item de controle de link.

```
BOOL SetItemID(
    int iLink,
    LPCWSTR szID);
```

### <a name="parameters"></a>Parâmetros

*iLink*<br/>
O índice de um item de controle de link.

*szID*<br/>
Uma cadeia de caracteres terminada em nulo que contém a ID do item especificado.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Define a ID de um item de controle de link específico. Para obter mais informações, consulte a mensagem do Win32 [LM_SETITEM](/windows/win32/Controls/lm-setitem) no SDK do Windows.

##  <a name="setitemstate"></a>  CLinkCtrl::SetItemState

Recupera o estado do item de controle de link.

```
BOOL SetItemState(
    int iLink,
    UINT state,
    UINT stateMask = LIS_FOCUSED | LIS_ENABLED | LIS_VISITED);
```

### <a name="parameters"></a>Parâmetros

*iLink*<br/>
O índice de um item de controle de link.

*pnState*<br/>
O valor do item de estado especificado que está sendo definido.

*stateMask*<br/>
Combinação de sinalizadores que descreve o item de estado que está sendo definido. Para obter uma lista de valores, consulte a descrição do `state` membro na estrutura [litem](/windows/win32/api/commctrl/ns-commctrl-litem) . Os itens permitidos são idênticos aos permitidos no `state`.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Define o valor do item de estado especificado de um item de controle de link específico. Para obter mais informações, consulte a mensagem do Win32 [LM_SETITEM](/windows/win32/Controls/lm-setitem) no SDK do Windows.

##  <a name="setitemurl"></a>  CLinkCtrl::SetItemUrl

Define a URL representada pelo item de controle de link.

```
BOOL SetItemUrl(
    int iLink,
    LPCWSTR szUrl);
```

### <a name="parameters"></a>Parâmetros

*iLink*<br/>
O índice de um item de controle de link.

*szUrl*<br/>
Uma cadeia de caracteres terminada em nulo que contém a URL representada pelo item especificado

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Define a URL representada pelo item de controle de link especificado. Para obter mais informações, consulte a mensagem do Win32 [LM_SETITEM](/windows/win32/Controls/lm-setitem) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)
