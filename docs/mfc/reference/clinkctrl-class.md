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
ms.openlocfilehash: aa1f630b448c60a0eeb6a905ed6eef6f84a2ff8c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372250"
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
|[CLinkCtrl::Criar](#create)|Cria um controle de link `CLinkCtrl` e o anexa a um objeto.|
|[CLinkCtrl::CreateEx](#createex)|Cria um controle de link com estilos `CLinkCtrl` estendidos e o anexa a um objeto.|
|[CLinkCtrl::GetIdealHeight](#getidealheight)|Recupera a altura ideal do controle de link.|
|[CLinkCtrl::GetIdealSize](#getidealsize)|Calcula a altura preferida do texto de link para o controle de link atual, dependendo da largura especificada do link.|
|[CLinkCtrl::GetItem](#getitem)|Recupera os estados e atributos de um item de controle de link.|
|[CLinkCtrl::GetItemID](#getitemid)|Recupera o ID de um item de controle de link.|
|[CLinkCtrl::GetItemState](#getitemstate)|Recupera o estado do item de controle de link.|
|[CLinkCtrl::GetItemUrl](#getitemurl)|Recupera a URL representada pelo item de controle de link.|
|[CLinkCtrl::HitTest](#hittest)|Determina se o usuário clicou no link especificado.|
|[CLinkCtrl::SetItem](#setitem)|Define os estados e atributos de um item de controle de link.|
|[CLinkCtrl::SetItemID](#setitemid)|Define o ID de um item de controle de link.|
|[CLinkCtrl::SetItemState](#setitemstate)|Define o estado do item de controle de link.|
|[CLinkCtrl::SetItemUrl](#setitemurl)|Define a URL representada pelo item de controle de link.|

## <a name="remarks"></a>Comentários

Um "controle de link" fornece uma maneira conveniente de incorporar links de hipertexto em uma janela. O controle real é uma janela que renderiza texto marcado e lança aplicativos apropriados quando o usuário clica em um link incorporado. Vários links são suportados dentro de um controle e podem ser acessados por um índice baseado em zero.

Este controle (e, `CLinkCtrl` portanto, a classe) está disponível apenas para programas em execução no Windows XP e posteriormente.

Para obter mais informações, consulte [O Controle SysLink](/windows/win32/Controls/syslink-overview) no SDK do Windows.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CLinkCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn.h

## <a name="clinkctrlclinkctrl"></a><a name="clinkctrl"></a>CLinkCtrl::CLinkCtrl

Constrói um objeto `CLinkCtrl`.

```
CLinkCtrl();
```

## <a name="clinkctrlcreate"></a><a name="create"></a>CLinkCtrl::Criar

Cria um controle de link `CLinkCtrl` e o anexa a um objeto.

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
Ponteiro para uma seqüência de terminação zero que contém o texto marcado para exibição. Para obter mais informações, consulte a seção "Markup and Link Access" na visão geral do tópico [Controles SysLink](/windows/win32/Controls/syslink-overview).

*Dwstyle*<br/>
Especifica o estilo do controle de link. Aplique qualquer combinação de estilos de controle. Consulte [Common Control](/windows/win32/Controls/common-control-styles) `Windows SDK` Styles no for e para obter mais informações.

*Rect*<br/>
Especifica o tamanho e a posição do controle de link. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [RECT.](/windows/win32/api/windef/ns-windef-rect)

*Pparentwnd*<br/>
Especifica a janela pai do controle de link. Não deve ser NULO.

*nID*<br/>
Especifica o ID do controle de link.

### <a name="return-value"></a>Valor retornado

VERDADE se a inicialização foi bem sucedida; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Você constrói `CLinkCtrl` um objeto em dois passos. Primeiro, ligue para o `Create`construtor e depois chame, o que `CLinkCtrl` cria o controle de link e o anexa ao objeto. Se você quiser usar estilos de janelas estendidos com o controle, `Create`chame [CLinkCtrl::CreateEx](#createex) em vez de .

A segunda forma `Create` do método é preterida. Use o primeiro formulário que especifica o parâmetro *lpszLinkMarkup.*

### <a name="example"></a>Exemplo

O exemplo de código a seguir `m_Link1` `m_Link2`define duas variáveis, nomeadas e , que são usadas para acessar dois controles de link.

[!code-cpp[NVC_MFC_CLinkCtrl_s1#2](../../mfc/reference/codesnippet/cpp/clinkctrl-class_1.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir cria um controle de link com base na localização de outro controle de link. O carregador de recursos cria o primeiro controle de link quando o aplicativo é iniciado. Quando seu aplicativo entra no método OnInitDialog, você cria o segundo controle de link em relação à posição do primeiro controle de link. Em seguida, você redimensiona o segundo controle de link para se encaixar no texto que ele exibe.

[!code-cpp[NVC_MFC_CLinkCtrl_s1#1](../../mfc/reference/codesnippet/cpp/clinkctrl-class_2.cpp)]

## <a name="clinkctrlcreateex"></a><a name="createex"></a>CLinkCtrl::CreateEx

Cria um controle de link com estilos `CLinkCtrl` estendidos e o anexa a um objeto.

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
Ponteiro para uma seqüência de terminação zero que contém o texto marcado para exibição. Para obter mais informações, consulte a seção "Markup and Link Access" na visão geral do tópico [Controles SysLink](/windows/win32/Controls/syslink-overview).

*Dwexstyle*<br/>
Especifica o estilo estendido do controle de link. Para obter uma lista de estilos estendidos do Windows, consulte o parâmetro *dwExStyle* para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*Dwstyle*<br/>
Especifica o estilo do controle de link. Aplique qualquer combinação de estilos de controle. Para obter mais informações, consulte [Estilos de controle comuns](/windows/win32/Controls/common-control-styles) no SDK do Windows.

*Rect*<br/>
Especifica o tamanho e a posição do controle de link. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [RECT.](/windows/win32/api/windef/ns-windef-rect)

*Pparentwnd*<br/>
Especifica a janela pai do controle de link. Não deve ser NULO.

*nID*<br/>
Especifica o ID do controle de link.

### <a name="return-value"></a>Valor retornado

VERDADE se a inicialização foi bem sucedida; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de [Criar](#create) para aplicar constantes estendidas de estilo do Windows.

A segunda forma `CreateEx` do método é preterida. Use o primeiro formulário que especifica o parâmetro *lpszLinkMarkup.*

## <a name="clinkctrlgetidealheight"></a><a name="getidealheight"></a>CLinkCtrl::GetIdealHeight

Recupera a altura ideal do controle de link.

```
int GetIdealHeight() const;
```

### <a name="return-value"></a>Valor retornado

A altura ideal do controle, em pixels.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [LM_GETIDEALHEIGHT](/windows/win32/Controls/lm-getidealheight)de mensagem Win32, conforme descrito no SDK do Windows.

## <a name="clinkctrlgetidealsize"></a><a name="getidealsize"></a>CLinkCtrl::GetIdealSize

Calcula a altura preferida do texto de link para o controle de link atual, dependendo da largura especificada do link.

```
int GetIdealSize(
    int cxMaxWidth,
    SIZE* pSize) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*cxMaxWidth*|[em] A largura máxima do link, em pixels.|
|[fora] \* *pTamanho*|Um ponteiro para uma estrutura do Windows [SIZE.](/windows/win32/api/windef/ns-windef-size) Quando este método *cy* retorna, o `SIZE` membro cy da estrutura contém a altura ideal do texto de link para a largura do texto de link especificada por *cxMaxWidth*. O membro *cx* da estrutura contém a largura de texto de link que é realmente necessária.|

### <a name="return-value"></a>Valor retornado

A altura preferida do texto de link, em pixels. O valor de retorno é o *cy* mesmo que `SIZE` o valor do membro cy da estrutura.

### <a name="remarks"></a>Comentários

Para um exemplo `GetIdealSize` do método, consulte o exemplo em [CLinkCtrl::Create](#create).

Este método envia a mensagem [LM_GETIDEALSIZE,](/windows/win32/Controls/lm-getidealsize) que é descrita no SDK do Windows.

## <a name="clinkctrlgetitem"></a><a name="getitem"></a>CLinkCtrl::GetItem

Recupera os estados e atributos de um item de controle de link.

```
BOOL GetItem(PLITEM pItem) const;
```

### <a name="parameters"></a>Parâmetros

*Pitem*<br/>
Um ponteiro para uma estrutura [LITEM](/windows/win32/api/commctrl/ns-commctrl-litem) para receber informações do item.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/lm-getitem)Win32 LM_GETITEM , conforme descrito no SDK do Windows.

## <a name="clinkctrlgetitemid"></a><a name="getitemid"></a>CLinkCtrl::GetItemID

Recupera o ID de um item de controle de link.

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

*Ilink*<br/>
O índice de um item de controle de link.

*strID*<br/>
Um objeto [CStringT](../../atl-mfc-shared/reference/cstringt-class.md) contendo o ID do item especificado.

*Szid*<br/>
Uma seqüência de terminadas nula contendo o ID do item especificado.

*cchid*<br/>
O tamanho nos caracteres do buffer *szID.*

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

> [!NOTE]
> Esta função também retorna FALSE se o buffer de *szID ou strID* for menor do que MAX_LINKID_TEXT.

### <a name="remarks"></a>Comentários

Recupera o ID de um item de controle de link específico. Para obter mais informações, consulte a mensagem Win32 [LM_GETITEM](/windows/win32/Controls/lm-getitem) no SDK do Windows.

## <a name="clinkctrlgetitemstate"></a><a name="getitemstate"></a>CLinkCtrl::GetItemState

Recupera o estado do item de controle de link.

```
BOOL GetItemState(
    int iLink,
    UINT* pnState,
    UINT stateMask = LIS_FOCUSED | LIS_ENABLED | LIS_VISITED) const;
```

### <a name="parameters"></a>Parâmetros

*Ilink*<br/>
O índice de um item de controle de link.

*pnState*<br/>
O valor do item de estado especificado.

*Statemask*<br/>
Combinação de bandeiras descrevendo qual item de estado obter. Para obter uma lista de valores, consulte a descrição do `state` membro na estrutura [LITEM.](/windows/win32/api/commctrl/ns-commctrl-litem) Os itens permitidos são idênticos `state`aos permitidos em .

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Recupera o valor do item de estado especificado de um item de controle de link específico. Para obter mais informações, consulte a mensagem Win32 [LM_GETITEM](/windows/win32/Controls/lm-getitem) no SDK do Windows.

## <a name="clinkctrlgetitemurl"></a><a name="getitemurl"></a>CLinkCtrl::GetItemUrl

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

*Ilink*<br/>
O índice de um item de controle de link.

*Strurl*<br/>
Um objeto [CStringT](../../atl-mfc-shared/reference/cstringt-class.md) contendo a URL representada pelo item especificado

*Szurl*<br/>
Uma seqüência de terminação nula contendo a URL representada pelo item especificado

*cchUrl*<br/>
O tamanho nos caracteres do buffer *szURL.*

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

> [!NOTE]
> Esta função também retorna FALSE se o buffer *de szUrl ou strUrl* for menor do que MAX_LINKID_TEXT.

### <a name="remarks"></a>Comentários

Recupera a URL representada pelo item de controle de link especificado. Para obter mais informações, consulte a mensagem Win32 [LM_GETITEM](/windows/win32/Controls/lm-getitem) no SDK do Windows.

## <a name="clinkctrlhittest"></a><a name="hittest"></a>CLinkCtrl::HitTest

Determina se o usuário clicou no link especificado.

```
BOOL HitTest(PLHITTESTINFO phti) const;
```

### <a name="parameters"></a>Parâmetros

*phti*<br/>
Ponteiro para `LHITTESTINFO` uma estrutura contendo qualquer informação sobre o link que o usuário clicou.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [LM_HITTEST](/windows/win32/Controls/lm-hittest)de mensagem Win32 , conforme descrito no SDK do Windows.

## <a name="clinkctrlsetitem"></a><a name="setitem"></a>CLinkCtrl::SetItem

Define os estados e atributos de um item de controle de link.

```
BOOL SetItem(PLITEM pItem);
```

### <a name="parameters"></a>Parâmetros

*Pitem*<br/>
Um ponteiro para uma estrutura [LITEM](/windows/win32/api/commctrl/ns-commctrl-litem) contendo as informações a serem definidas.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/lm-setitem)LM_SETITEM do Win32 , conforme descrito no SDK do Windows.

## <a name="clinkctrlsetitemid"></a><a name="setitemid"></a>CLinkCtrl::SetItemID

Recupera o ID de um item de controle de link.

```
BOOL SetItemID(
    int iLink,
    LPCWSTR szID);
```

### <a name="parameters"></a>Parâmetros

*Ilink*<br/>
O índice de um item de controle de link.

*Szid*<br/>
Uma seqüência de terminadas nula contendo o ID do item especificado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Define o ID de um item de controle de link específico. Para obter mais informações, consulte a mensagem Win32 [LM_SETITEM](/windows/win32/Controls/lm-setitem) no SDK do Windows.

## <a name="clinkctrlsetitemstate"></a><a name="setitemstate"></a>CLinkCtrl::SetItemState

Recupera o estado do item de controle de link.

```
BOOL SetItemState(
    int iLink,
    UINT state,
    UINT stateMask = LIS_FOCUSED | LIS_ENABLED | LIS_VISITED);
```

### <a name="parameters"></a>Parâmetros

*Ilink*<br/>
O índice de um item de controle de link.

*pnState*<br/>
O valor do item de estado especificado a ser definido.

*Statemask*<br/>
Combinação de bandeiras descrevendo o item de estado que está sendo definido. Para obter uma lista de valores, consulte a descrição do `state` membro na estrutura [LITEM.](/windows/win32/api/commctrl/ns-commctrl-litem) Os itens permitidos são idênticos `state`aos permitidos em .

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Define o valor do item de estado especificado de um item de controle de link específico. Para obter mais informações, consulte a mensagem Win32 [LM_SETITEM](/windows/win32/Controls/lm-setitem) no SDK do Windows.

## <a name="clinkctrlsetitemurl"></a><a name="setitemurl"></a>CLinkCtrl::SetItemUrl

Define a URL representada pelo item de controle de link.

```
BOOL SetItemUrl(
    int iLink,
    LPCWSTR szUrl);
```

### <a name="parameters"></a>Parâmetros

*Ilink*<br/>
O índice de um item de controle de link.

*Szurl*<br/>
Uma seqüência de terminação nula contendo a URL representada pelo item especificado

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Define a URL representada pelo item de controle de link especificado. Para obter mais informações, consulte a mensagem Win32 [LM_SETITEM](/windows/win32/Controls/lm-setitem) no SDK do Windows.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)
