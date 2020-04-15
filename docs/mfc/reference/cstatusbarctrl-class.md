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
ms.openlocfilehash: 7a594fdb2d3a35ce905b7790026f7418b7435f3a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366027"
---
# <a name="cstatusbarctrl-class"></a>Classe CStatusBarCtrl

Fornece a funcionalidade do controle da barra de status comum do Windows.

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
|[CStatusBarCtrl::Criar](#create)|Cria um controle de barra de `CStatusBarCtrl` status e o anexa a um objeto.|
|[CStatusBarCtrl::CreateEx](#createex)|Cria um controle de barra de status com os `CStatusBarCtrl` estilos estendidos do Windows especificados e o anexa a um objeto.|
|[CStatusBarCtrl::DrawItem](#drawitem)|Chamado quando um aspecto visual de uma barra de status de proprietário-draw muda.|
|[CStatusBarCtrl::GetBorders](#getborders)|Recupera as larguras atuais das bordas horizontal e vertical de um controle da barra de status.|
|[CStatusBarCtrl::GetIcon](#geticon)|Recupera o ícone de uma peça (também conhecida como painel) no controle da barra de status atual.|
|[CStatusBarCtrl::GetParts](#getparts)|Recupera uma contagem das peças em um controle de barra de status.|
|[CStatusBarCtrl::GetRect](#getrect)|Recupera o retângulo delimitador de uma peça em um controle de barra de status.|
|[CStatusBarCtrl::GetText](#gettext)|Recupera o texto da parte dada de um controle da barra de status.|
|[CStatusBarCtrl::GetTextLength](#gettextlength)|Recupere o comprimento, em caracteres, do texto da parte dada de um controle de barra de status.|
|[CStatusBarCtrl::GetTipText](#gettiptext)|Recupera o texto da dica de ferramenta para um painel em uma barra de status.|
|[CStatusBarCtrl::IsSimple](#issimple)|Verifica um controle de janela de status para determinar se ele está no modo simples.|
|[CStatusBarCtrl::SetBkColor](#setbkcolor)|Define a cor de fundo em uma barra de status.|
|[CStatusBarCtrl::SetIcon](#seticon)|Define o ícone para um painel em uma barra de status.|
|[CStatusBarCtrl::SetMinHeight](#setminheight)|Define a altura mínima da área de desenho de um controle de barra de status.|
|[CStatusBarCtrl::SetParts](#setparts)|Define o número de peças em um controle de barra de status e a coordenada da borda direita de cada parte.|
|[CStatusBarCtrl::SetSimple](#setsimple)|Especifica se um controle da barra de status exibe texto simples `SetParts`ou exibe todas as partes de controle definidas por uma chamada anterior para .|
|[CStatusBarCtrl::SetText](#settext)|Define o texto na parte dada de um controle da barra de status.|
|[CStatusBarCtrl::SetTipText](#settiptext)|Define o texto da dica de ferramenta para um painel em uma barra de status.|

## <a name="remarks"></a>Comentários

Um "controle da barra de status" é uma janela horizontal, geralmente exibida na parte inferior de uma janela pai, na qual um aplicativo pode exibir vários tipos de informações de status. O controle da barra de status pode ser dividido em partes para exibir mais de um tipo de informação.

Este controle (e, `CStatusBarCtrl` portanto, a classe) está disponível apenas para programas em execução sob windows 95/98 e Windows NT versão 3.51 e posterior.

Para obter mais `CStatusBarCtrl`informações sobre como usar, consulte [Controles](../../mfc/controls-mfc.md) e [O uso de CStatusBarCtrl](../../mfc/using-cstatusbarctrl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CStatusBarCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn.h

## <a name="cstatusbarctrlcreate"></a><a name="create"></a>CStatusBarCtrl::Criar

Cria um controle de barra de `CStatusBarCtrl` status e o anexa a um objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
Especifica o estilo do controle da barra de status. Aplique qualquer combinação de estilos de controle de barra de status listados em [Estilos de Controle Comuns](/windows/win32/Controls/common-control-styles) no SDK do Windows. Este parâmetro deve incluir o estilo WS_CHILD. Também deve incluir o estilo WS_VISIBLE.

*Rect*<br/>
Especifica o tamanho e a posição do controle da barra de status. Pode ser um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) ou uma estrutura [RECT.](/previous-versions/dd162897\(v=vs.85\))

*Pparentwnd*<br/>
Especifica a janela pai do controle da `CDialog`barra de status, geralmente um . Não deve ser NULO.

*nID*<br/>
Especifica o ID do controle da barra de status.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Você constrói `CStatusBarCtrl` um em dois passos. Primeiro, ligue para o construtor `Create`e, em seguida, ligue, o `CStatusBarCtrl` que cria o controle da barra de status e o anexa ao objeto.

A posição padrão de uma janela de status está ao longo da parte inferior da janela pai, mas você pode especificar o estilo CCS_TOP para que ele apareça na parte superior da área cliente da janela pai. Você pode especificar o estilo SBARS_SIZEGRIP para incluir um aperto de tamanho na extremidade direita da janela de status. A combinação dos estilos CCS_TOP e SBARS_SIZEGRIP não é recomendada, pois o aperto de tamanho resultante não é funcional, mesmo que o sistema o desenre na janela de status.

Para criar uma barra de status com estilos de janela estendidos, `Create`chame [CStatusBarCtrl::CreateEx](#createex) em vez de .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#1](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_1.cpp)]

## <a name="cstatusbarctrlcreateex"></a><a name="createex"></a>CStatusBarCtrl::CreateEx

Cria um controle (uma janela filho) `CStatusBarCtrl` e o associa ao objeto.

```
virtual BOOL CreateEx(
    DWORD dwExStyle,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwexstyle*<br/>
Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista de estilos estendidos do Windows, consulte o parâmetro *dwExStyle* para [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) no SDK do Windows.

*Dwstyle*<br/>
Especifica o estilo do controle da barra de status. Aplique qualquer combinação de estilos de controle de barra de status listados em [Estilos de Controle Comuns](/windows/win32/Controls/common-control-styles) no SDK do Windows. Este parâmetro deve incluir o estilo WS_CHILD. Também deve incluir o estilo WS_VISIBLE.

*Rect*<br/>
Uma referência a uma estrutura [RECT](/previous-versions/dd162897\(v=vs.85\)) descrevendo o tamanho e a posição da janela a ser criada, em coordenadas de cliente de *pParentWnd*.

*Pparentwnd*<br/>
Um ponteiro para a janela que é o pai do controle.

*nID*<br/>
A id da janela infantil do controle.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Use `CreateEx` em vez de [Criar](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.

## <a name="cstatusbarctrlcstatusbarctrl"></a><a name="cstatusbarctrl"></a>CStatusBarCtrl::CStatusBarCtrl

Constrói um objeto `CStatusBarCtrl`.

```
CStatusBarCtrl();
```

## <a name="cstatusbarctrldrawitem"></a><a name="drawitem"></a>CStatusBarCtrl::DrawItem

Chamado pela estrutura quando um aspecto visual de uma barra de status de proprietário-draw muda.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>Parâmetros

*Lpdrawitemstruct*<br/>
Um ponteiro longo para uma estrutura [DRAWITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-drawitemstruct) que contém informações sobre o tipo de desenho necessário.

### <a name="remarks"></a>Comentários

O `itemAction` membro `DRAWITEMSTRUCT` da estrutura define a ação de desenho a ser realizada.

Por padrão, esta função de membro não faz nada. Substituir esta função de membro para implementar `CStatusBarCtrl` o desenho para um objeto de desenho do proprietário.

O aplicativo deve restaurar todos os objetos GDI (Graphics Device Interface, interface de dispositivo gráfico) selecionados para o contexto de exibição fornecido no *lpDrawItemStruct* antes que essa função de membro seja encerrada.

## <a name="cstatusbarctrlgetborders"></a><a name="getborders"></a>CStatusBarCtrl::GetBorders

Recupera as larguras atuais do controle da barra de status das bordas horizontais e verticais e do espaço entre os retângulos.

```
BOOL GetBorders(int* pBorders) const;

BOOL GetBorders(
    int& nHorz,
    int& nVert,
    int& nSpacing) const;
```

### <a name="parameters"></a>Parâmetros

*pFronteiras*<br/>
Endereço de uma matriz inteira com três elementos. O primeiro elemento recebe a largura da borda horizontal, o segundo recebe a largura da borda vertical, e o terceiro recebe a largura da borda entre os retângulos.

*nHorz*<br/>
Referência a um inteiro que recebe a largura da borda horizontal.

*nVert*<br/>
Referência a um inteiro que recebe a largura da borda vertical.

*nSpacing*<br/>
Referência a um inteiro que recebe a largura da borda entre retângulos.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Essas bordas determinam o espaçamento entre a borda externa do controle e os retângulos dentro do controle que contêm texto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#2](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_2.cpp)]

## <a name="cstatusbarctrlgeticon"></a><a name="geticon"></a>CStatusBarCtrl::GetIcon

Recupera o ícone de uma peça (também conhecida como painel) no controle da barra de status atual.

```
HICON GetIcon(int iPart) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*iPart*|[em] O índice baseado em zero da parte que contém o ícone a ser recuperado. Se este parâmetro for -1, a barra de status é assumida como uma barra de status de modo simples.|

### <a name="return-value"></a>Valor retornado

A alça para o ícone se o método for bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [SB_GETICON,](/windows/win32/Controls/sb-geticon) que é descrita no SDK do Windows.

Um controle de barra de status consiste em uma linha de painéis de saída de texto, que também são conhecidos como partes. Para obter mais informações sobre a barra de status, consulte [Implementação da barra de status no MFC](../../mfc/status-bar-implementation-in-mfc.md) e [configuração do modo de um objeto CStatusBarCtrl](../../mfc/setting-the-mode-of-a-cstatusbarctrl-object.md).

### <a name="example"></a>Exemplo

O exemplo de código a `m_statusBar`seguir define uma variável, que é usada para acessar o controle da barra de status atual. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CStatusBarCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_3.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir copia um ícone para dois painéis do controle atual da barra de status. Em uma seção anterior do exemplo de código, criamos um controle de barra de status com três painéis e, em seguida, adicionamos um ícone ao primeiro painel. Este exemplo recupera o ícone do primeiro painel e, em seguida, adiciona-o ao segundo e terceiro painel.

[!code-cpp[NVC_MFC_CStatusBarCtrl_s1#2](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_4.cpp)]

## <a name="cstatusbarctrlgetparts"></a><a name="getparts"></a>CStatusBarCtrl::GetParts

Recupera uma contagem das peças em um controle de barra de status.

```
int GetParts(
    int nParts,
    int* pParts) const;
```

### <a name="parameters"></a>Parâmetros

*Nparts*<br/>
Número de peças para recuperar coordenadas. Se esse parâmetro for maior do que o número de peças no controle, a mensagem recuperará coordenadas apenas para as partes existentes.

*pParts*<br/>
Endereço de uma matriz inteira com o mesmo número de elementos que o número de partes especificadas por *nParts*. Cada elemento na matriz recebe a coordenada do cliente da borda direita da parte correspondente. Se um elemento for definido como - 1, a posição da borda direita para essa parte estende-se até a borda direita da barra de status.

### <a name="return-value"></a>Valor retornado

O número de peças no controle se for bem sucedido, ou zero de outra forma.

### <a name="remarks"></a>Comentários

Esta função de membro também recupera a coordenada da borda direita do número dado de peças.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#3](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_5.cpp)]

## <a name="cstatusbarctrlgetrect"></a><a name="getrect"></a>CStatusBarCtrl::GetRect

Recupera o retângulo delimitador de uma peça em um controle de barra de status.

```
BOOL GetRect(
    int nPane,
    LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*nPane*<br/>
Índice baseado em zero da parte cujo retângulo delimitador deve ser recuperado.

*Lprect*<br/>
Endereço de uma estrutura [RECT](/previous-versions/dd162897\(v=vs.85\)) que recebe o retângulo delimitador.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#4](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_6.cpp)]

## <a name="cstatusbarctrlgettext"></a><a name="gettext"></a>CStatusBarCtrl::GetText

Recupera o texto da parte dada de um controle da barra de status.

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
Endereço do buffer que recebe o texto. Este parâmetro é uma seqüência de terminadas por nulo.

*nPane*<br/>
Índice baseado em zero da parte a partir da qual recuperar texto.

*Ptype*<br/>
Ponteiro para um inteiro que recebe as informações do tipo. O tipo pode ser um desses valores:

- **0** O texto é desenhado com uma borda para parecer inferior ao plano da barra de status.

- SBT_NOBORDERS O texto é elaborado sem fronteiras.

- SBT_POPOUT O texto é desenhado com uma borda para parecer mais alto que o plano da barra de status.

- SBT_OWNERDRAW Se o texto tiver o SBT_OWNERDRAW tipo de desenho, *pType* receberá esta mensagem e retorna o valor de 32 bits associado ao texto em vez do comprimento e do tipo de operação.

### <a name="return-value"></a>Valor retornado

O comprimento, em caracteres, do texto ou um [CString](../../atl-mfc-shared/reference/cstringt-class.md) contendo o texto atual.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#5](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_7.cpp)]

## <a name="cstatusbarctrlgettextlength"></a><a name="gettextlength"></a>CStatusBarCtrl::GetTextLength

Recupera o comprimento, em caracteres, do texto da parte dada de um controle de barra de status.

```
int GetTextLength(
    int nPane,
    int* pType = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*nPane*<br/>
Índice baseado em zero da parte a partir da qual recuperar texto.

*Ptype*<br/>
Ponteiro para um inteiro que recebe as informações do tipo. O tipo pode ser um desses valores:

- **0** O texto é desenhado com uma borda para parecer inferior ao plano da barra de status.

- SBT_NOBORDERS O texto é elaborado sem fronteiras.

- SBT_OWNERDRAW O texto é desenhado pela janela dos pais.

- SBT_POPOUT O texto é desenhado com uma borda para parecer mais alto que o plano da barra de status.

### <a name="return-value"></a>Valor retornado

O comprimento, nos caracteres, do texto.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#6](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_8.cpp)]

## <a name="cstatusbarctrlgettiptext"></a><a name="gettiptext"></a>CStatusBarCtrl::GetTipText

Recupera o texto da dica de ferramenta para um painel em uma barra de status.

```
CString GetTipText(int nPane) const;
```

### <a name="parameters"></a>Parâmetros

*nPane*<br/>
O índice baseado em zero do painel da barra de status para receber o texto da dica de ferramenta.

### <a name="return-value"></a>Valor retornado

Um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) contendo o texto a ser usado na dica de ferramenta.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [mensagem](/windows/win32/Controls/sb-gettiptext)Win32 SB_GETTIPTEXT , conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#7](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_9.cpp)]

## <a name="cstatusbarctrlissimple"></a><a name="issimple"></a>CStatusBarCtrl::IsSimple

Verifica um controle de janela de status para determinar se ele está no modo simples.

```
BOOL IsSimple() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o controle da janela de status estiver no modo simples; caso contrário, zero.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [SB_ISSIMPLE](/windows/win32/Controls/sb-issimple)de mensagem Win32 , conforme descrito no SDK do Windows.

## <a name="cstatusbarctrlsetbkcolor"></a><a name="setbkcolor"></a>CStatusBarCtrl::SetBkColor

Define a cor de fundo em uma barra de status.

```
COLORREF SetBkColor(COLORREF cr);
```

### <a name="parameters"></a>Parâmetros

*Cr*<br/>
Valor COLORREF que especifica a nova cor de fundo. Especifique o valor CLR_DEFAULT para fazer com que a barra de status use sua cor de fundo padrão.

### <a name="return-value"></a>Valor retornado

Um valor [COLORREF](/windows/win32/gdi/colorref) que representa a cor de fundo padrão anterior.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [SB_SETBKCOLOR](/windows/win32/Controls/sb-setbkcolor)de mensagem Win32 , conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#8](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_10.cpp)]

## <a name="cstatusbarctrlseticon"></a><a name="seticon"></a>CStatusBarCtrl::SetIcon

Define o ícone para um painel em uma barra de status.

```
BOOL SetIcon(
    int nPane,
    HICON hIcon);
```

### <a name="parameters"></a>Parâmetros

*nPane*<br/>
O índice baseado em zero do painel que receberá o ícone. Se este parâmetro for -1, a barra de status é assumida como uma barra de status simples.

*Hicon*<br/>
Manuseie o ícone a ser definido. Se esse valor for NULO, o ícone será removido da peça.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [SB_SETICON](/windows/win32/Controls/sb-seticon)de mensagem Win32 , conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CStatusBarCtrl::SetBkColor](#setbkcolor).

## <a name="cstatusbarctrlsetminheight"></a><a name="setminheight"></a>CStatusBarCtrl::SetMinHeight

Define a altura mínima da área de desenho de um controle de barra de status.

```
void SetMinHeight(int nMin);
```

### <a name="parameters"></a>Parâmetros

*Nmin*<br/>
Altura mínima, em pixels, do controle.

### <a name="remarks"></a>Comentários

A altura mínima é a soma de *nMin* e o dobro da largura, em pixels, da borda vertical do controle da barra de status.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#9](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_11.cpp)]

## <a name="cstatusbarctrlsetparts"></a><a name="setparts"></a>CStatusBarCtrl::SetParts

Define o número de peças em um controle de barra de status e a coordenada da borda direita de cada parte.

```
BOOL SetParts(
    int nParts,
    int* pWidths);
```

### <a name="parameters"></a>Parâmetros

*Nparts*<br/>
Número de peças para definir. O número de peças não pode ser maior que 255.

*larguras de largura*<br/>
Endereço de uma matriz inteira com o mesmo número de elementos que as partes especificadas por *nParts*. Cada elemento na matriz especifica a posição, nas coordenadas do cliente, da borda direita da parte correspondente. Se um elemento é - 1, a posição da borda direita para essa parte estende-se até a borda direita do controle.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#10](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_12.cpp)]

## <a name="cstatusbarctrlsetsimple"></a><a name="setsimple"></a>CStatusBarCtrl::SetSimple

Especifica se um controle da barra de status exibe texto simples ou exibe todas as partes de controle definidas por uma chamada anterior para [SetParts](#setparts).

```
BOOL SetSimple(BOOL bSimple = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bSimples*<br/>
[em] Sinalizador tipo exibição. Se este parâmetro for TRUE, o controle exibirá texto simples; se for FALSO, exibe várias partes.

### <a name="return-value"></a>Valor retornado

Sempre retorna 0.

### <a name="remarks"></a>Comentários

Se o aplicativo mudar o controle da barra de status de não simples para simples, ou vice-versa, o sistema redesenha imediatamente o controle.

## <a name="cstatusbarctrlsettext"></a><a name="settext"></a>CStatusBarCtrl::SetText

Define o texto na parte dada de um controle da barra de status.

```
BOOL SetText(
    LPCTSTR lpszText,
    int nPane,
    int nType);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
Endereço de uma seqüência de terminadas nula especificando o texto a definir. Se *nType* for SBT_OWNERDRAW, *lpszText* representará 32 bits de dados.

*nPane*<br/>
Índice baseado em zero da peça a ser definida. Se esse valor for de 255, o controle da barra de status é assumido como um controle simples com apenas uma parte.

*nType*<br/>
Tipo de operação de desenho. Consulte [SB_SETTEXT mensagem](/windows/win32/Controls/sb-settext) para uma lista de valores possíveis.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

A mensagem invalida a parte do controle que foi alterada, fazendo com que ela exiba o novo texto quando o controle em seguida receber a mensagem WM_PAINT.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#11](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_13.cpp)]

## <a name="cstatusbarctrlsettiptext"></a><a name="settiptext"></a>CStatusBarCtrl::SetTipText

Define o texto da dica de ferramenta para um painel em uma barra de status.

```
void SetTipText(
    int nPane,
    LPCTSTR pszTipText);
```

### <a name="parameters"></a>Parâmetros

*nPane*<br/>
O índice baseado em zero do painel da barra de status para receber o texto da dica de ferramenta.

*pszTipText*<br/>
Um ponteiro para uma seqüência contendo o texto da dica de ferramenta.

### <a name="remarks"></a>Comentários

Esta função de membro implementa o comportamento da [SB_SETTIPTEXT](/windows/win32/Controls/sb-settiptext)de mensagem Win32 , conforme descrito no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CStatusBarCtrl#12](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_14.cpp)]

## <a name="see-also"></a>Confira também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md)
