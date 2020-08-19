---
title: Classe CStatusBarCtrl
ms.date: 11/04/2016
f1_keywords:
- CStatusBarCtrl
- AFXCMN/CStatusBarCtrl
- AFXCMN/CStatusBarCtrl::CStatusBarCtrl
- AFXCMN/CStatusBarCtrl::Create
- AFXCMN/CStatusBarCtrl::CreateEx
- AFXCMN/CStatusBarCtrl::DrawItem
- AFXCMN/CStatusBarCtrl::GetBorders
- AFXCMN/CStatusBarCtrl::GetIcon
- AFXCMN/CStatusBarCtrl::GetParts
- AFXCMN/CStatusBarCtrl::GetRect
- AFXCMN/CStatusBarCtrl::GetText
- AFXCMN/CStatusBarCtrl::GetTextLength
- AFXCMN/CStatusBarCtrl::GetTipText
- AFXCMN/CStatusBarCtrl::IsSimple
- AFXCMN/CStatusBarCtrl::SetBkColor
- AFXCMN/CStatusBarCtrl::SetIcon
- AFXCMN/CStatusBarCtrl::SetMinHeight
- AFXCMN/CStatusBarCtrl::SetParts
- AFXCMN/CStatusBarCtrl::SetSimple
- AFXCMN/CStatusBarCtrl::SetText
- AFXCMN/CStatusBarCtrl::SetTipText
helpviewer_keywords:
- CStatusBarCtrl [MFC], CStatusBarCtrl
- CStatusBarCtrl [MFC], Create
- CStatusBarCtrl [MFC], CreateEx
- CStatusBarCtrl [MFC], DrawItem
- CStatusBarCtrl [MFC], GetBorders
- CStatusBarCtrl [MFC], GetIcon
- CStatusBarCtrl [MFC], GetParts
- CStatusBarCtrl [MFC], GetRect
- CStatusBarCtrl [MFC], GetText
- CStatusBarCtrl [MFC], GetTextLength
- CStatusBarCtrl [MFC], GetTipText
- CStatusBarCtrl [MFC], IsSimple
- CStatusBarCtrl [MFC], SetBkColor
- CStatusBarCtrl [MFC], SetIcon
- CStatusBarCtrl [MFC], SetMinHeight
- CStatusBarCtrl [MFC], SetParts
- CStatusBarCtrl [MFC], SetSimple
- CStatusBarCtrl [MFC], SetText
- CStatusBarCtrl [MFC], SetTipText
ms.assetid: 8504ad38-7b91-4746-aede-ac98886eb47b
ms.openlocfilehash: d2440eb05a1367b7d4980494e3d7f5de646d5fd0
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88562643"
---
# <a name="cstatusbarctrl-class"></a>Classe CStatusBarCtrl

Fornece a funcionalidade do controle de barra de status comum do Windows.

## <a name="syntax"></a>Sintaxe

```
class CStatusBarCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CStatusBarCtrl::CStatusBarCtrl](#cstatusbarctrl)|Constrói um objeto `CStatusBarCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CStatusBarCtrl:: criar](#create)|Cria um controle de barra de status e o anexa a um `CStatusBarCtrl` objeto.|
|[CStatusBarCtrl::CreateEx](#createex)|Cria um controle de barra de status com os estilos estendidos do Windows especificados e o anexa a um `CStatusBarCtrl` objeto.|
|[CStatusBarCtrl::D rawItem](#drawitem)|Chamado quando um aspecto visual de um controle de barra de status de desenho proprietário é alterado.|
|[CStatusBarCtrl:: GetBorders](#getborders)|Recupera as larguras atuais das bordas horizontais e verticais de um controle de barra de status.|
|[CStatusBarCtrl:: GetIcon](#geticon)|Recupera o ícone de uma parte (também conhecido como painel) no controle da barra de status atual.|
|[CStatusBarCtrl:: GetParts](#getparts)|Recupera uma contagem das partes em um controle de barra de status.|
|[CStatusBarCtrl:: GetRect](#getrect)|Recupera o retângulo delimitador de uma parte em um controle de barra de status.|
|[CStatusBarCtrl:: gettext](#gettext)|Recupera o texto da parte determinada de um controle da barra de status.|
|[CStatusBarCtrl::GetTextLength](#gettextlength)|Recupere o comprimento, em caracteres, do texto da parte especificada de um controle da barra de status.|
|[CStatusBarCtrl::GetTipText](#gettiptext)|Recupera o texto da dica de ferramenta de um painel em uma barra de status.|
|[CStatusBarCtrl:: IsSimple](#issimple)|Verifica um controle de janela de status para determinar se ele está no modo simples.|
|[CStatusBarCtrl::SetBkColor](#setbkcolor)|Define a cor do plano de fundo em uma barra de status.|
|[CStatusBarCtrl:: SetIcon](#seticon)|Define o ícone de um painel em uma barra de status.|
|[CStatusBarCtrl::SetMinHeight](#setminheight)|Define a altura mínima da área de desenho de um controle de barra de status.|
|[CStatusBarCtrl:: SetParts](#setparts)|Define o número de partes em um controle de barra de status e a coordenada da borda direita de cada parte.|
|[CStatusBarCtrl:: setsimples](#setsimple)|Especifica se um controle de barra de status exibe texto simples ou exibe todas as partes de controle definidas por uma chamada anterior para `SetParts` .|
|[CStatusBarCtrl:: SetText](#settext)|Define o texto na parte determinada de um controle de barra de status.|
|[CStatusBarCtrl::SetTipText](#settiptext)|Define o texto da dica de ferramenta para um painel em uma barra de status.|

## <a name="remarks"></a>Comentários

Um "controle da barra de status" é uma janela horizontal, geralmente exibida na parte inferior de uma janela pai, na qual um aplicativo pode exibir vários tipos de informações de status. O controle barra de status pode ser dividido em partes para exibir mais de um tipo de informação.

Esse controle (e, portanto, a `CStatusBarCtrl` classe) está disponível somente para programas em execução no windows 95/98 e no Windows NT versão 3,51 e posterior.

Para obter mais informações sobre como usar o `CStatusBarCtrl` , consulte [controles](../../mfc/controls-mfc.md) e [usando CStatusBarCtrl](../../mfc/using-cstatusbarctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CStatusBarCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn. h

## <a name="cstatusbarctrlcreate"></a><a name="create"></a> CStatusBarCtrl:: criar

Cria um controle de barra de status e o anexa a um `CStatusBarCtrl` objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica o estilo do controle da barra de status. Aplique qualquer combinação de estilos de controle da barra de status listada em [estilos de controle comuns](/windows/win32/Controls/common-control-styles) na SDK do Windows. Esse parâmetro deve incluir o estilo de WS_CHILD. Ele também deve incluir o estilo de WS_VISIBLE.

*Rect*<br/>
Especifica o tamanho e a posição do controle da barra de status. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) .

*pParentWnd*<br/>
Especifica a janela pai do controle da barra de status, geralmente um `CDialog` . Ele não deve ser nulo.

*nID*<br/>
Especifica a ID do controle da barra de status.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Você constrói um `CStatusBarCtrl` em duas etapas. Primeiro, chame o construtor e, em seguida, chame `Create` , que cria o controle da barra de status e o anexa ao `CStatusBarCtrl` objeto.

A posição padrão de uma janela de status é ao longo da parte inferior da janela pai, mas você pode especificar o estilo de CCS_TOP para que ele apareça na parte superior da área do cliente da janela pai. Você pode especificar o estilo de SBARS_SIZEGRIP para incluir uma alça de dimensionamento na extremidade direita da janela de status. Não é recomendável combinar os estilos de CCS_TOP e SBARS_SIZEGRIP, pois a alça de dimensionamento resultante não é funcional, mesmo que o sistema o desenhe na janela de status.

Para criar uma barra de status com estilos de janela estendidos, chame [CStatusBarCtrl:: CreateEx](#createex) em vez de `Create` .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#1](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_1.cpp)]

## <a name="cstatusbarctrlcreateex"></a><a name="createex"></a> CStatusBarCtrl::CreateEx

Cria um controle (uma janela filho) e o associa ao `CStatusBarCtrl` objeto.

```
virtual BOOL CreateEx(
    DWORD dwExStyle,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwExStyle*<br/>
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista de estilos estendidos do Windows, consulte o parâmetro *dwExStyle* para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*dwStyle*<br/>
Especifica o estilo do controle da barra de status. Aplique qualquer combinação de estilos de controle da barra de status listada em [estilos de controle comuns](/windows/win32/Controls/common-control-styles) na SDK do Windows. Esse parâmetro deve incluir o estilo de WS_CHILD. Ele também deve incluir o estilo de WS_VISIBLE.

*Rect*<br/>
Uma referência a uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) que descreve o tamanho e a posição da janela a ser criada, nas coordenadas de cliente de *pParentWnd*.

*pParentWnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
A ID da janela filho do controle.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de [Create](#create) para aplicar estilos estendidos do Windows, especificados pelo **WS_EX_** de prefácio de estilo estendido do Windows.

## <a name="cstatusbarctrlcstatusbarctrl"></a><a name="cstatusbarctrl"></a> CStatusBarCtrl::CStatusBarCtrl

Constrói um objeto `CStatusBarCtrl`.

```
CStatusBarCtrl();
```

## <a name="cstatusbarctrldrawitem"></a><a name="drawitem"></a> CStatusBarCtrl::D rawItem

Chamado pelo Framework quando um aspecto visual de um controle de barra de status de desenho proprietário é alterado.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpDrawItemStruct*<br/>
Um ponteiro longo para uma estrutura [DRAWITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-drawitemstruct) que contém informações sobre o tipo de desenho necessário.

### <a name="remarks"></a>Comentários

O `itemAction` membro da `DRAWITEMSTRUCT` estrutura define a ação de desenho a ser executada.

Por padrão, essa função de membro não faz nada. Substitua essa função de membro para implementar o desenho de um objeto de desenho proprietário `CStatusBarCtrl` .

O aplicativo deve restaurar todos os objetos da interface de dispositivo de gráficos (GDI) selecionados para o contexto de exibição fornecido em *lpDrawItemStruct* antes que essa função de membro seja encerrada.

## <a name="cstatusbarctrlgetborders"></a><a name="getborders"></a> CStatusBarCtrl:: GetBorders

Recupera as larguras atuais do controle da barra de status das bordas horizontais e verticais e do espaço entre os retângulos.

```
BOOL GetBorders(int* pBorders) const;

BOOL GetBorders(
    int& nHorz,
    int& nVert,
    int& nSpacing) const;
```

### <a name="parameters"></a>Parâmetros

*pBorders*<br/>
Endereço de uma matriz de inteiros com três elementos. O primeiro elemento recebe a largura da borda horizontal, a segunda recebe a largura da borda vertical e a terceira recebe a largura da borda entre retângulos.

*nHorz*<br/>
Referência a um inteiro que recebe a largura da borda horizontal.

*nverter*<br/>
Referência a um inteiro que recebe a largura da borda vertical.

*nSpacing*<br/>
Referência a um inteiro que recebe a largura da borda entre retângulos.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Essas bordas determinam o espaçamento entre a borda externa do controle e os retângulos dentro do controle que contêm texto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#2](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_2.cpp)]

## <a name="cstatusbarctrlgeticon"></a><a name="geticon"></a> CStatusBarCtrl:: GetIcon

Recupera o ícone de uma parte (também conhecido como painel) no controle da barra de status atual.

```
HICON GetIcon(int iPart) const;
```

### <a name="parameters"></a>Parâmetros

*iPart*\
no O índice de base zero da parte que contém o ícone a ser recuperado. Se esse parâmetro for-1, a barra de status será considerada uma barra de status de modo simples.

### <a name="return-value"></a>Valor retornado

O identificador para o ícone se o método tiver êxito; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem de [SB_GETICON](/windows/win32/Controls/sb-geticon) , que é descrita na SDK do Windows.

Um controle de barra de status consiste em uma linha de painéis de saída de texto, que também são conhecidos como partes. Para obter mais informações sobre a barra de status, consulte a [implementação da barra de status no MFC](../../mfc/status-bar-implementation-in-mfc.md) e [definindo o modo de um objeto CStatusBarCtrl](../../mfc/setting-the-mode-of-a-cstatusbarctrl-object.md).

### <a name="example"></a>Exemplo

O exemplo de código a seguir define uma variável, `m_statusBar` , que é usada para acessar o controle da barra de status atual. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CStatusBarCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_3.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir copia um ícone para dois painéis do controle da barra de status atual. Em uma seção anterior do exemplo de código, criamos um controle de barra de status com três painéis e adicionamos um ícone ao primeiro painel. Este exemplo recupera o ícone do primeiro painel e, em seguida, o adiciona ao segundo e terceiro painel.

[!code-cpp[NVC_MFC_CStatusBarCtrl_s1#2](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_4.cpp)]

## <a name="cstatusbarctrlgetparts"></a><a name="getparts"></a> CStatusBarCtrl:: GetParts

Recupera uma contagem das partes em um controle de barra de status.

```
int GetParts(
    int nParts,
    int* pParts) const;
```

### <a name="parameters"></a>Parâmetros

*nParts*<br/>
Número de partes para as quais recuperar as coordenadas. Se esse parâmetro for maior que o número de partes no controle, a mensagem recuperará coordenadas somente para partes existentes.

*pParts*<br/>
Endereço de uma matriz de inteiros que tem o mesmo número de elementos que o número de partes especificado por *nParts*. Cada elemento na matriz recebe a coordenada do cliente da borda direita da parte correspondente. Se um elemento for definido como-1, a posição da borda direita dessa parte se estenderá para a borda direita da barra de status.

### <a name="return-value"></a>Valor retornado

O número de partes no controle se for bem-sucedido ou nenhum outro valor será zero.

### <a name="remarks"></a>Comentários

Essa função de membro também recupera a coordenada da borda direita do número determinado de partes.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#3](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_5.cpp)]

## <a name="cstatusbarctrlgetrect"></a><a name="getrect"></a> CStatusBarCtrl:: GetRect

Recupera o retângulo delimitador de uma parte em um controle de barra de status.

```
BOOL GetRect(
    int nPane,
    LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*nPane*<br/>
Índice de base zero da parte cujo retângulo delimitador deve ser recuperado.

*lpRect*<br/>
Endereço de uma estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) que recebe o retângulo delimitador.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#4](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_6.cpp)]

## <a name="cstatusbarctrlgettext"></a><a name="gettext"></a> CStatusBarCtrl:: gettext

Recupera o texto da parte determinada de um controle da barra de status.

```
CString GetText(
    int nPane,
    int* pType = NULL) const;

int GetText(
    LPCTSTR lpszText,
    int nPane,
    int* pType = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
Endereço do buffer que recebe o texto. Esse parâmetro é uma cadeia de caracteres terminada em nulo.

*nPane*<br/>
Índice de base zero da parte da qual recuperar o texto.

*pType*<br/>
Ponteiro para um inteiro que recebe as informações de tipo. O tipo pode ser um destes valores:

- **0** o texto é desenhado com uma borda para aparecer menor do que o plano da barra de status.

- SBT_NOBORDERS o texto é desenhado sem bordas.

- SBT_POPOUT o texto é desenhado com uma borda para aparecer maior do que o plano da barra de status.

- SBT_OWNERDRAW se o texto tiver o tipo de desenho SBT_OWNERDRAW, *pType* receberá essa mensagem e retornará o valor de 32 bits associado ao texto em vez do comprimento e do tipo de operação.

### <a name="return-value"></a>Valor retornado

O comprimento, em caracteres, do texto ou de uma [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém o texto atual.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#5](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_7.cpp)]

## <a name="cstatusbarctrlgettextlength"></a><a name="gettextlength"></a> CStatusBarCtrl::GetTextLength

Recupera o comprimento, em caracteres, do texto da parte especificada de um controle da barra de status.

```
int GetTextLength(
    int nPane,
    int* pType = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*nPane*<br/>
Índice de base zero da parte da qual recuperar o texto.

*pType*<br/>
Ponteiro para um inteiro que recebe as informações de tipo. O tipo pode ser um destes valores:

- **0** o texto é desenhado com uma borda para aparecer menor do que o plano da barra de status.

- SBT_NOBORDERS o texto é desenhado sem bordas.

- SBT_OWNERDRAW o texto é desenhado pela janela pai.

- SBT_POPOUT o texto é desenhado com uma borda para aparecer maior do que o plano da barra de status.

### <a name="return-value"></a>Valor retornado

O comprimento, em caracteres, do texto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#6](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_8.cpp)]

## <a name="cstatusbarctrlgettiptext"></a><a name="gettiptext"></a> CStatusBarCtrl::GetTipText

Recupera o texto da dica de ferramenta de um painel em uma barra de status.

```
CString GetTipText(int nPane) const;
```

### <a name="parameters"></a>Parâmetros

*nPane*<br/>
O índice de base zero do painel de barra de status para receber o texto da dica de ferramenta.

### <a name="return-value"></a>Valor retornado

Um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém o texto a ser usado na dica de ferramenta.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [SB_GETTIPTEXT](/windows/win32/Controls/sb-gettiptext)de mensagens Win32, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#7](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_9.cpp)]

## <a name="cstatusbarctrlissimple"></a><a name="issimple"></a> CStatusBarCtrl:: IsSimple

Verifica um controle de janela de status para determinar se ele está no modo simples.

```
BOOL IsSimple() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o controle de janela de status estiver no modo simples; caso contrário, zero.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [SB_ISSIMPLE](/windows/win32/Controls/sb-issimple)de mensagens Win32, conforme descrito no SDK do Windows.

## <a name="cstatusbarctrlsetbkcolor"></a><a name="setbkcolor"></a> CStatusBarCtrl::SetBkColor

Define a cor do plano de fundo em uma barra de status.

```
COLORREF SetBkColor(COLORREF cr);
```

### <a name="parameters"></a>Parâmetros

*CD*<br/>
Valor COLORREF que especifica a nova cor do plano de fundo. Especifique o valor de CLR_DEFAULT para fazer com que a barra de status Use sua cor de plano de fundo padrão.

### <a name="return-value"></a>Valor retornado

Um valor [COLORREF](/windows/win32/gdi/colorref) que representa a cor do plano de fundo padrão anterior.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [SB_SETBKCOLOR](/windows/win32/Controls/sb-setbkcolor)de mensagens Win32, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#8](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_10.cpp)]

## <a name="cstatusbarctrlseticon"></a><a name="seticon"></a> CStatusBarCtrl:: SetIcon

Define o ícone de um painel em uma barra de status.

```
BOOL SetIcon(
    int nPane,
    HICON hIcon);
```

### <a name="parameters"></a>Parâmetros

*nPane*<br/>
O índice de base zero do painel que receberá o ícone. Se esse parâmetro for-1, a barra de status será considerada uma barra de status simples.

*hIcon*<br/>
Identificador para o ícone a ser definido. Se esse valor for nulo, o ícone será removido da parte.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [SB_SETICON](/windows/win32/Controls/sb-seticon)de mensagens Win32, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CStatusBarCtrl:: SetBkColor](#setbkcolor).

## <a name="cstatusbarctrlsetminheight"></a><a name="setminheight"></a> CStatusBarCtrl::SetMinHeight

Define a altura mínima da área de desenho de um controle de barra de status.

```cpp
void SetMinHeight(int nMin);
```

### <a name="parameters"></a>Parâmetros

*Nmín*<br/>
Altura mínima, em pixels, do controle.

### <a name="remarks"></a>Comentários

A altura mínima é a soma de *nmín* e o dobro da largura, em pixels, da borda vertical do controle da barra de status.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#9](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_11.cpp)]

## <a name="cstatusbarctrlsetparts"></a><a name="setparts"></a> CStatusBarCtrl:: SetParts

Define o número de partes em um controle de barra de status e a coordenada da borda direita de cada parte.

```
BOOL SetParts(
    int nParts,
    int* pWidths);
```

### <a name="parameters"></a>Parâmetros

*nParts*<br/>
Número de partes a serem definidas. O número de partes não pode ser maior que 255.

*pWidths*<br/>
Endereço de uma matriz de inteiros com o mesmo número de elementos que as partes especificadas por *nParts*. Cada elemento na matriz Especifica a posição, nas coordenadas do cliente, da borda direita da parte correspondente. Se um elemento for-1, a posição da borda direita dessa parte se estenderá à borda direita do controle.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#10](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_12.cpp)]

## <a name="cstatusbarctrlsetsimple"></a><a name="setsimple"></a> CStatusBarCtrl:: setsimples

Especifica se um controle de barra de status exibe texto simples ou exibe todas as partes de controle definidas por uma chamada anterior para [SetParts](#setparts).

```
BOOL SetSimple(BOOL bSimple = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bSimple*<br/>
no Sinalizador de tipo de exibição. Se esse parâmetro for TRUE, o controle exibirá texto simples; Se for FALSE, exibirá várias partes.

### <a name="return-value"></a>Valor retornado

Sempre retorna 0.

### <a name="remarks"></a>Comentários

Se o seu aplicativo alterar o controle da barra de status de não simples para simples, ou vice-versa, o sistema redesenhará imediatamente o controle.

## <a name="cstatusbarctrlsettext"></a><a name="settext"></a> CStatusBarCtrl:: SetText

Define o texto na parte determinada de um controle de barra de status.

```
BOOL SetText(
    LPCTSTR lpszText,
    int nPane,
    int nType);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
Endereço de uma cadeia de caracteres terminada em nulo que especifica o texto a ser definido. Se *ndeclarações* for SBT_OWNERDRAW, *lpszText* representará 32 bits de dados.

*nPane*<br/>
Índice de base zero da parte a ser definida. Se esse valor for 255, o controle da barra de status será considerado um controle simples que tem apenas uma parte.

*nType*<br/>
Tipo de operação de desenho. Consulte [SB_SETTEXT mensagem](/windows/win32/Controls/sb-settext) para obter uma lista de valores possíveis.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

A mensagem invalida a parte do controle que foi alterada, fazendo com que ela exiba o novo texto quando o próximo controle receber a mensagem de WM_PAINT.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#11](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_13.cpp)]

## <a name="cstatusbarctrlsettiptext"></a><a name="settiptext"></a> CStatusBarCtrl::SetTipText

Define o texto da dica de ferramenta para um painel em uma barra de status.

```cpp
void SetTipText(
    int nPane,
    LPCTSTR pszTipText);
```

### <a name="parameters"></a>Parâmetros

*nPane*<br/>
O índice de base zero do painel de barra de status para receber o texto da dica de ferramenta.

*pszTipText*<br/>
Um ponteiro para uma cadeia de caracteres que contém o texto da dica de ferramenta.

### <a name="remarks"></a>Comentários

Essa função de membro implementa o comportamento do [SB_SETTIPTEXT](/windows/win32/Controls/sb-settiptext)de mensagens Win32, conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#12](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_14.cpp)]

## <a name="see-also"></a>Confira também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md)
