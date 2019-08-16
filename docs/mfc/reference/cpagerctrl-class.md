---
title: Classe CPagerCtrl
ms.date: 11/04/2016
f1_keywords:
- CPagerCtrl
- AFXCMN/CPagerCtrl
- AFXCMN/CPagerCtrl::CPagerCtrl
- AFXCMN/CPagerCtrl::Create
- AFXCMN/CPagerCtrl::CreateEx
- AFXCMN/CPagerCtrl::ForwardMouse
- AFXCMN/CPagerCtrl::GetBkColor
- AFXCMN/CPagerCtrl::GetBorder
- AFXCMN/CPagerCtrl::GetButtonSize
- AFXCMN/CPagerCtrl::GetButtonState
- AFXCMN/CPagerCtrl::GetDropTarget
- AFXCMN/CPagerCtrl::GetScrollPos
- AFXCMN/CPagerCtrl::IsButtonDepressed
- AFXCMN/CPagerCtrl::IsButtonGrayed
- AFXCMN/CPagerCtrl::IsButtonHot
- AFXCMN/CPagerCtrl::IsButtonInvisible
- AFXCMN/CPagerCtrl::IsButtonNormal
- AFXCMN/CPagerCtrl::RecalcSize
- AFXCMN/CPagerCtrl::SetBkColor
- AFXCMN/CPagerCtrl::SetBorder
- AFXCMN/CPagerCtrl::SetButtonSize
- AFXCMN/CPagerCtrl::SetChild
- AFXCMN/CPagerCtrl::SetScrollPos
helpviewer_keywords:
- CPagerCtrl [MFC], CPagerCtrl
- CPagerCtrl [MFC], Create
- CPagerCtrl [MFC], CreateEx
- CPagerCtrl [MFC], ForwardMouse
- CPagerCtrl [MFC], GetBkColor
- CPagerCtrl [MFC], GetBorder
- CPagerCtrl [MFC], GetButtonSize
- CPagerCtrl [MFC], GetButtonState
- CPagerCtrl [MFC], GetDropTarget
- CPagerCtrl [MFC], GetScrollPos
- CPagerCtrl [MFC], IsButtonDepressed
- CPagerCtrl [MFC], IsButtonGrayed
- CPagerCtrl [MFC], IsButtonHot
- CPagerCtrl [MFC], IsButtonInvisible
- CPagerCtrl [MFC], IsButtonNormal
- CPagerCtrl [MFC], RecalcSize
- CPagerCtrl [MFC], SetBkColor
- CPagerCtrl [MFC], SetBorder
- CPagerCtrl [MFC], SetButtonSize
- CPagerCtrl [MFC], SetChild
- CPagerCtrl [MFC], SetScrollPos
ms.assetid: 65ac58dd-4f5e-4b7e-b15c-e0d435a7e884
ms.openlocfilehash: 519a376bdecc488a94eab65973e33d960ca50c8d
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69503022"
---
# <a name="cpagerctrl-class"></a>Classe CPagerCtrl

A `CPagerCtrl` classe encapsula o controle de pager do Windows, que pode rolar para a exibição de uma janela contida que não se ajusta à janela que a contém.

## <a name="syntax"></a>Sintaxe

```
class CPagerCtrl : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPagerCtrl::CPagerCtrl](#cpagerctrl)|Constrói um objeto `CPagerCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPagerCtrl::Create](#create)|Cria um controle de pager com estilos especificados e anexa-o ao objeto `CPagerCtrl` atual.|
|[CPagerCtrl::CreateEx](#createex)|Cria um controle de pager com estilos estendidos especificados e anexa-o ao `CPagerCtrl` objeto atual.|
|[CPagerCtrl::ForwardMouse](#forwardmouse)|Habilita ou desabilita o encaminhamento de mensagens [WM_MOUSEMOVE](/windows/win32/inputdev/wm-mousemove) para a janela contida no controle de pager atual.|
|[CPagerCtrl::GetBkColor](#getbkcolor)|Recupera a cor do plano de fundo do controle do pager atual.|
|[CPagerCtrl::GetBorder](#getborder)|Recupera o tamanho da borda do controle de pager atual.|
|[CPagerCtrl::GetButtonSize](#getbuttonsize)|Recupera o tamanho do botão do controle do pager atual.|
|[CPagerCtrl::GetButtonState](#getbuttonstate)|Recupera o estado do botão especificado no controle do pager atual.|
|[CPagerCtrl::GetDropTarget](#getdroptarget)|Recupera a interface [IDropTarget](/windows/win32/api/oleidl/nn-oleidl-idroptarget) para o controle de pager atual.|
|[CPagerCtrl::GetScrollPos](#getscrollpos)|Recupera a posição de rolagem do controle de pager atual.|
|[CPagerCtrl::IsButtonDepressed](#isbuttondepressed)|Indica se o botão especificado do controle do pager atual está no `pressed` estado.|
|[CPagerCtrl::IsButtonGrayed](#isbuttongrayed)|Indica se o botão especificado do controle do pager atual está no `grayed` estado.|
|[CPagerCtrl::IsButtonHot](#isbuttonhot)|Indica se o botão especificado do controle do pager atual está no `hot` estado.|
|[CPagerCtrl::IsButtonInvisible](#isbuttoninvisible)|Indica se o botão especificado do controle do pager atual está no `invisible` estado.|
|[CPagerCtrl::IsButtonNormal](#isbuttonnormal)|Indica se o botão especificado do controle do pager atual está no `normal` estado.|
|[CPagerCtrl::RecalcSize](#recalcsize)|Faz com que o controle de pager atual recalcule o tamanho da janela contida.|
|[CPagerCtrl::SetBkColor](#setbkcolor)|Define a cor do plano de fundo do controle do pager atual.|
|[CPagerCtrl::SetBorder](#setborder)|Define o tamanho da borda do controle do pager atual.|
|[CPagerCtrl::SetButtonSize](#setbuttonsize)|Define o tamanho do botão do controle do pager atual.|
|[CPagerCtrl::SetChild](#setchild)|Define a janela contida para o controle de pager atual.|
|[CPagerCtrl::SetScrollPos](#setscrollpos)|Define a posição de rolagem do controle de pager atual.|

## <a name="remarks"></a>Comentários

Um controle de pager é uma janela que contém outra janela que é linear e maior do que a janela que a contém e permite que você role a janela contida para a exibição. O controle de pager exibe dois botões de rolagem que desaparecem automaticamente quando a janela contida é rolada para sua extensão mais distante e reaparece de outra forma. Você pode criar um controle de pager que rola horizontalmente ou verticalmente.

Por exemplo, se seu aplicativo tiver uma barra de ferramentas que não seja grande o suficiente para mostrar todos os seus itens, você poderá atribuir a barra de ferramentas a um controle de pager e os usuários poderão rolar a barra de ferramentas para a esquerda ou direita para acessar todos os itens. O Microsoft Internet Explorer versão 4,0 (commctrl. dll versão 4,71) apresenta o controle de pager.

A `CPagerCtrl` classe é derivada da classe [CWnd](../../mfc/reference/cwnd-class.md) . Para obter mais informações e uma ilustração de um controle de pager, consulte [controles de pager](/windows/win32/Controls/pager-controls).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CPagerCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn. h

##  <a name="cpagerctrl"></a>  CPagerCtrl::CPagerCtrl

Constrói um objeto `CPagerCtrl`.

```
CPagerCtrl();
```

### <a name="remarks"></a>Comentários

Use o método [CPagerCtrl:: Create](#create) ou [CPagerCtrl:: CreateEx](#createex) para criar um controle de pager e anexá `CPagerCtrl` -lo ao objeto.

##  <a name="create"></a>  CPagerCtrl::Create

Cria um controle de pager com estilos especificados e anexa-o ao objeto `CPagerCtrl` atual.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*dwStyle*|no Uma combinação de bits (ou) de [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) e estilos de controle de [pager](/windows/win32/Controls/pager-control-styles) a serem aplicados ao controle.|
|*rect*|no Uma referência a uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que contém a posição e o tamanho do controle nas coordenadas do cliente.|
|*pParentWnd*|no Um ponteiro para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é a janela pai do controle. Este parâmetro não pode ser nulo.|
|*nID*|no A ID do controle.|

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Para criar um controle de pager, declare `CPagerCtrl` uma variável e, em seguida, chame o método [CPagerCtrl:: Create](#create) ou [CPagerCtrl:: CreateEx](#createex) nessa variável.

### <a name="example"></a>Exemplo

O exemplo a seguir cria um controle de pager e, em seguida, usa o método [CPagerCtrl:: SetChild](#setchild) para associar um controle de botão muito longo com o controle de pager. Em seguida, o exemplo usa o método [CPagerCtrl:: SetButtons](#setbuttonsize) para definir a altura do controle de pager como 20 pixels e o método [CPagerCtrl:: SetBorder](#setborder) para definir a espessura da borda como 1 pixel.

[!code-cpp[NVC_MFC_CSplitButton_s2#1](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_1.cpp)]

##  <a name="createex"></a>  CPagerCtrl::CreateEx

Cria um controle de pager com estilos estendidos especificados e anexa-o ao `CPagerCtrl` objeto atual.

```
virtual BOOL CreateEx(
    DWORD dwExStyle,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*dwExStyle*|no Uma combinação de bits de bit que os estilos estendidos a serem aplicados ao controle. Para obter mais informações, consulte o parâmetro *dwExStyle* da função [CreateWindowEx](/windows/win32/api/winuser/nf-winuser-createwindowexw) .|
|*dwStyle*|no Uma combinação de bits (ou) de [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) e estilos de controle de [pager](/windows/win32/Controls/pager-control-styles) a serem aplicados ao controle.|
|*rect*|no Uma referência a uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que contém a posição e o tamanho do controle nas coordenadas do cliente.|
|*pParentWnd*|no Um ponteiro para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é a janela pai do controle. Este parâmetro não pode ser nulo.|
|*nID*|no A ID do controle.|

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Para criar um controle de pager, declare `CPagerCtrl` uma variável e, em seguida, chame o método [CPagerCtrl:: Create](#create) ou [CPagerCtrl:: CreateEx](#createex) nessa variável.

##  <a name="forwardmouse"></a>  CPagerCtrl::ForwardMouse

Habilita ou desabilita o encaminhamento de mensagens [WM_MOUSEMOVE](/windows/win32/inputdev/wm-mousemove) para a janela contida no controle de pager atual.

```
void ForwardMouse(BOOL bForward);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*bForward*|no TRUE para encaminhar mensagens do mouse ou FALSE para não encaminhar mensagens do mouse.|

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [PGM_FORWARDMOUSE](/windows/win32/Controls/pgm-forwardmouse) , que é descrita na SDK do Windows.

##  <a name="getborder"></a>  CPagerCtrl::GetBorder

Recupera o tamanho da borda do controle de pager atual.

```
int GetBorder() const;
```

### <a name="return-value"></a>Valor de retorno

O tamanho da borda atual, medido em pixels.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [PGM_GETBORDER](/windows/win32/Controls/pgm-getborder) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo a seguir usa o método [CPagerCtrl:: GetBorder](#getborder) para recuperar a espessura da borda do controle de pager.

[!code-cpp[NVC_MFC_CSplitButton_s2#5](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_2.cpp)]

##  <a name="getbkcolor"></a>  CPagerCtrl::GetBkColor

Recupera a cor do plano de fundo do controle do pager atual.

```
COLORREF GetBkColor() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor de [COLORREF](/windows/win32/gdi/colorref) que contém a cor de plano de fundo atual do controle de pager.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [PGM_GETBKCOLOR](/windows/win32/Controls/pgm-getbkcolor) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo a seguir usa o método [CPagerCtrl:: SetBkColor](#setbkcolor) para definir a cor do plano de fundo do controle de pager como vermelho e o método [CPagerCtrl:: GetBkColor](#getbkcolor) para confirmar que a alteração foi feita.

[!code-cpp[NVC_MFC_CSplitButton_s2#4](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_3.cpp)]

##  <a name="getbuttonsize"></a>  CPagerCtrl::GetButtonSize

Recupera o tamanho do botão do controle do pager atual.

```
int GetButtonSize() const;
```

### <a name="return-value"></a>Valor de retorno

O tamanho do botão atual, medido em pixels.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [PGM_GETBUTTONSIZE](/windows/win32/Controls/pgm-getbuttonsize) , que é descrita na SDK do Windows.

Se o controle de pager tiver o estilo PGS_HORZ, o tamanho do botão determinará a largura dos botões de pager e, se o controle de pager tiver o estilo PGS_VERT, o tamanho do botão determinará a altura dos botões da paginação. Para obter mais informações, consulte [estilos de controle de pager](/windows/win32/Controls/pager-control-styles).

##  <a name="getbuttonstate"></a>  CPagerCtrl::GetButtonState

Recupera o estado do botão de rolagem especificado no controle do pager atual.

```
DWORD GetButtonState(int iButton) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*iButton*|no Indica o botão para o qual o estado é recuperado. Se o estilo de controle do pager for PGS_HORZ, especifique PGB_TOPORLEFT para o botão esquerdo e PGB_BOTTOMORRIGHT para o botão direito. Se o estilo de controle do pager for PGS_VERT, especifique PGB_TOPORLEFT para o botão superior e PGB_BOTTOMORRIGHT para o botão inferior. Para obter mais informações, consulte [estilos de controle de pager](/windows/win32/Controls/pager-control-styles).|

### <a name="return-value"></a>Valor de retorno

O estado do botão especificado pelo parâmetro *iButton* . O estado é PGF_INVISIBLE, PGF_NORMAL, PGF_GRAYED, PGF_DEPRESSED ou PGF_HOT. Para obter mais informações, consulte a seção valor de retorno da mensagem [PGM_GETBUTTONSTATE](/windows/win32/Controls/pgm-getbuttonstate) .

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [PGM_GETBUTTONSTATE](/windows/win32/Controls/pgm-getbuttonstate) , que é descrita na SDK do Windows.

##  <a name="getdroptarget"></a>  CPagerCtrl::GetDropTarget

Recupera a interface [IDropTarget](/windows/win32/api/oleidl/nn-oleidl-idroptarget) para o controle de pager atual.

```
IDropTarget* GetDropTarget() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a `IDropTarget` interface do controle de pager atual.

### <a name="remarks"></a>Comentários

`IDropTarget`é uma das interfaces que você implementa para dar suporte a operações de arrastar e soltar em seu aplicativo.

Esse método envia a mensagem [PGM_GETDROPTARGET](/windows/win32/Controls/pgm-getdroptarget) , que é descrita na SDK do Windows. O chamador desse método é responsável por chamar o `Release` membro da interface [IDropTarget](/windows/win32/api/oleidl/nn-oleidl-idroptarget) quando a interface não é mais necessária.

##  <a name="getscrollpos"></a>  CPagerCtrl::GetScrollPos

Recupera a posição de rolagem do controle de pager atual.

```
int GetScrollPos() const;
```

### <a name="return-value"></a>Valor de retorno

A posição de rolagem atual, medida em pixels.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [PGM_GETPOS](/windows/win32/Controls/pgm-getpos) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo a seguir usa o método [CPagerCtrl:: GetScrollPos](#getscrollpos) para recuperar a posição de rolagem atual do controle de pager. Se o controle de pager ainda não estiver rolado para zero, a posição mais à esquerda, o exemplo usará o método [CPagerCtrl:: SetScrollPos](#setscrollpos) para definir a posição de rolagem como zero.

[!code-cpp[NVC_MFC_CSplitButton_s2#7](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_4.cpp)]

##  <a name="isbuttondepressed"></a>  CPagerCtrl::IsButtonDepressed

Indica se o botão de rolagem especificado do controle do pager atual está no estado pressionado.

```
BOOL IsButtonDepressed(int iButton) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*iButton*|no Indica o botão para o qual o estado é recuperado. Se o estilo de controle do pager for PGS_HORZ, especifique PGB_TOPORLEFT para o botão esquerdo e PGB_BOTTOMORRIGHT para o botão direito. Se o estilo de controle do pager for PGS_VERT, especifique PGB_TOPORLEFT para o botão superior e PGB_BOTTOMORRIGHT para o botão inferior. Para obter mais informações, consulte [estilos de controle de pager](/windows/win32/Controls/pager-control-styles).|

### <a name="return-value"></a>Valor de retorno

TRUE se o botão especificado estiver no estado pressionado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [PGM_GETBUTTONSTATE](/windows/win32/Controls/pgm-getbuttonstate) , que é descrita na SDK do Windows. Em seguida, ele testa se o estado retornado é PGF_DEPRESSED. Para obter mais informações, consulte a seção valor de retorno da mensagem [PGM_GETBUTTONSTATE](/windows/win32/Controls/pgm-getbuttonstate) .

##  <a name="isbuttongrayed"></a>  CPagerCtrl::IsButtonGrayed

Indica se o botão de rolagem especificado do controle do pager atual está em estado acinzentado.

```
BOOL IsButtonGrayed(int iButton) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*iButton*|no Indica o botão para o qual o estado é recuperado. Se o estilo de controle do pager for PGS_HORZ, especifique PGB_TOPORLEFT para o botão esquerdo e PGB_BOTTOMORRIGHT para o botão direito. Se o estilo de controle do pager for PGS_VERT, especifique PGB_TOPORLEFT para o botão superior e PGB_BOTTOMORRIGHT para o botão inferior. Para obter mais informações, consulte [estilos de controle de pager](/windows/win32/Controls/pager-control-styles).|

### <a name="return-value"></a>Valor de retorno

TRUE se o botão especificado estiver em um estado esmaecido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [PGM_GETBUTTONSTATE](/windows/win32/Controls/pgm-getbuttonstate) , que é descrita na SDK do Windows. Em seguida, ele testa se o estado retornado é PGF_GRAYED. Para obter mais informações, consulte a seção valor de retorno da mensagem [PGM_GETBUTTONSTATE](/windows/win32/Controls/pgm-getbuttonstate) .

##  <a name="isbuttonhot"></a>  CPagerCtrl::IsButtonHot

Indica se o botão de rolagem especificado do controle do pager atual está em estado ativo.

```
BOOL IsButtonHot(int iButton) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*iButton*|no Indica o botão para o qual o estado é recuperado. Se o estilo de controle do pager for PGS_HORZ, especifique PGB_TOPORLEFT para o botão esquerdo e PGB_BOTTOMORRIGHT para o botão direito. Se o estilo de controle do pager for PGS_VERT, especifique PGB_TOPORLEFT para o botão superior e PGB_BOTTOMORRIGHT para o botão inferior. Para obter mais informações, consulte [estilos de controle de pager](/windows/win32/Controls/pager-control-styles).|

### <a name="return-value"></a>Valor de retorno

TRUE se o botão especificado estiver em estado ativo; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [PGM_GETBUTTONSTATE](/windows/win32/Controls/pgm-getbuttonstate) , que é descrita na SDK do Windows. Em seguida, ele testa se o estado retornado é PGF_HOT. Para obter mais informações, consulte a seção valor de retorno da mensagem [PGM_GETBUTTONSTATE](/windows/win32/Controls/pgm-getbuttonstate) .

##  <a name="isbuttoninvisible"></a>  CPagerCtrl::IsButtonInvisible

Indica se o botão de rolagem especificado do controle do pager atual está no estado invisível.

```
BOOL IsButtonInvisible(int iButton) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*iButton*|no Indica o botão para o qual o estado é recuperado. Se o estilo de controle do pager for PGS_HORZ, especifique PGB_TOPORLEFT para o botão esquerdo e PGB_BOTTOMORRIGHT para o botão direito. Se o estilo de controle do pager for PGS_VERT, especifique PGB_TOPORLEFT para o botão superior e PGB_BOTTOMORRIGHT para o botão inferior. Para obter mais informações, consulte [estilos de controle de pager](/windows/win32/Controls/pager-control-styles).|

### <a name="return-value"></a>Valor de retorno

TRUE se o botão especificado estiver no estado invisível; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O Windows deixa o botão de rolagem em uma direção específica invisível quando a janela contida é rolada para sua extensão mais distante, pois clicar no botão ainda não pode colocar mais a janela contida na exibição.

Esse método envia a mensagem [PGM_GETBUTTONSTATE](/windows/win32/Controls/pgm-getbuttonstate) , que é descrita na SDK do Windows. Em seguida, ele testa se o estado retornado é PGF_INVISIBLE. Para obter mais informações, consulte a seção valor de retorno da mensagem [PGM_GETBUTTONSTATE](/windows/win32/Controls/pgm-getbuttonstate) .

### <a name="example"></a>Exemplo

O exemplo a seguir usa o método [CPagerCtrl:: IsButtonInvisible](#isbuttoninvisible) para determinar se os botões de rolagem esquerda e direita do controle de pager estão visíveis.

[!code-cpp[NVC_MFC_CSplitButton_s2#6](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_5.cpp)]

##  <a name="isbuttonnormal"></a>  CPagerCtrl::IsButtonNormal

Indica se o botão de rolagem especificado do controle do pager atual está em estado normal.

```
BOOL IsButtonNormal(int iButton) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*iButton*|no Indica o botão para o qual o estado é recuperado. Se o estilo de controle do pager for PGS_HORZ, especifique PGB_TOPORLEFT para o botão esquerdo e PGB_BOTTOMORRIGHT para o botão direito. Se o estilo de controle do pager for PGS_VERT, especifique PGB_TOPORLEFT para o botão superior e PGB_BOTTOMORRIGHT para o botão inferior. Para obter mais informações, consulte [estilos de controle de pager](/windows/win32/Controls/pager-control-styles).|

### <a name="return-value"></a>Valor de retorno

TRUE se o botão especificado estiver em estado normal; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [PGM_GETBUTTONSTATE](/windows/win32/Controls/pgm-getbuttonstate) , que é descrita na SDK do Windows. Em seguida, ele testa se o estado retornado é PGF_NORMAL. Para obter mais informações, consulte a seção valor de retorno da mensagem [PGM_GETBUTTONSTATE](/windows/win32/Controls/pgm-getbuttonstate) .

##  <a name="recalcsize"></a>  CPagerCtrl::RecalcSize

Faz com que o controle de pager atual recalcule o tamanho da janela contida.

```
void RecalcSize();
```

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [PGM_RECALCSIZE](/windows/win32/Controls/pgm-recalcsize) , que é descrita na SDK do Windows. Consequentemente, o controle de pager envia a notificação [PGN_CALCSIZE](/windows/win32/Controls/pgn-calcsize) para obter as dimensões roláveis da janela contida.

### <a name="example"></a>Exemplo

O exemplo a seguir usa o método [CPagerCtrl:: RecalcSize](#recalcsize) para solicitar que o controle de pager atual recalcule seu tamanho.

[!code-cpp[NVC_MFC_CSplitButton_s2#3](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_6.cpp)]

### <a name="example"></a>Exemplo

O exemplo a seguir usa a [reflexão de mensagem](../../mfc/tn062-message-reflection-for-windows-controls.md) para habilitar o controle de pager para recalcular seu próprio tamanho, em vez de exigir que a caixa de diálogo pai do controle execute o cálculo. O exemplo deriva `MyPagerCtrl` a classe da [classe CPagerCtrl](../../mfc/reference/cpagerctrl-class.md)e, em seguida, usa um mapa de mensagens para associar a notificação [PGN_CALCSIZE](/windows/win32/Controls/pgn-calcsize) ao manipulador de `OnCalcsize` notificação. Neste exemplo, o manipulador de notificação define a largura e a altura do controle de pager como valores fixos.

[!code-cpp[NVC_MFC_CSplitButton_s2#8](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_7.cpp)]

##  <a name="setbkcolor"></a>  CPagerCtrl::SetBkColor

Define a cor do plano de fundo do controle do pager atual.

```
COLORREF SetBkColor(COLORREF clrBk);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*clrBk*|no Um valor de [COLORREF](/windows/win32/gdi/colorref) que contém a nova cor de plano de fundo do controle de pager.|

### <a name="return-value"></a>Valor de retorno

Um valor [COLORREF](/windows/win32/gdi/colorref) que contém a cor do plano de fundo anterior do controle de pager.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [PGM_SETBKCOLOR](/windows/win32/Controls/pgm-setbkcolor) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo a seguir usa o método [CPagerCtrl:: SetBkColor](#setbkcolor) para definir a cor do plano de fundo do controle de pager como vermelho e o método [CPagerCtrl:: GetBkColor](#getbkcolor) para confirmar que a alteração foi feita.

[!code-cpp[NVC_MFC_CSplitButton_s2#4](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_3.cpp)]

##  <a name="setborder"></a>  CPagerCtrl::SetBorder

Define o tamanho da borda do controle do pager atual.

```
int SetBorder(int iBorder);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*iBorder*|no O novo tamanho da borda, medido em pixels. Se o parâmetro *iBorder* for negativo, o tamanho da borda será definido como zero.|

### <a name="return-value"></a>Valor de retorno

O tamanho da borda anterior, medido em pixels.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [PGM_SETBORDER](/windows/win32/Controls/pgm-setborder) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo a seguir cria um controle de pager e, em seguida, usa o método [CPagerCtrl:: SetChild](#setchild) para associar um controle de botão muito longo com o controle de pager. Em seguida, o exemplo usa o método [CPagerCtrl:: SetButtons](#setbuttonsize) para definir a altura do controle de pager como 20 pixels e o método [CPagerCtrl:: SetBorder](#setborder) para definir a espessura da borda como 1 pixel.

[!code-cpp[NVC_MFC_CSplitButton_s2#1](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_1.cpp)]

##  <a name="setbuttonsize"></a>  CPagerCtrl::SetButtonSize

Define o tamanho do botão do controle do pager atual.

```
int SetButtonSize(int iButtonSize);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*iButtonSize*|no O novo tamanho do botão, medido em pixels.|

### <a name="return-value"></a>Valor de retorno

O tamanho do botão anterior, medido em pixels.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [PGM_SETBUTTONSIZE](/windows/win32/Controls/pgm-setpos) , que é descrita na SDK do Windows.

Se o controle de pager tiver o estilo PGS_HORZ, o tamanho do botão determinará a largura dos botões de pager e, se o controle de pager tiver o estilo PGS_VERT, o tamanho do botão determinará a altura dos botões da paginação. O tamanho do botão padrão é de três quartos da largura da barra de rolagem e o tamanho mínimo do botão é 12 pixels. Para obter mais informações, consulte [estilos de controle de pager](/windows/win32/Controls/pager-control-styles).

### <a name="example"></a>Exemplo

O exemplo a seguir cria um controle de pager e, em seguida, usa o método [CPagerCtrl:: SetChild](#setchild) para associar um controle de botão muito longo com o controle de pager. Em seguida, o exemplo usa o método [CPagerCtrl:: SetButtons](#setbuttonsize) para definir a altura do controle de pager como 20 pixels e o método [CPagerCtrl:: SetBorder](#setborder) para definir a espessura da borda como 1 pixel.

[!code-cpp[NVC_MFC_CSplitButton_s2#1](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_1.cpp)]

##  <a name="setchild"></a>  CPagerCtrl::SetChild

Define a janela contida para o controle de pager atual.

```
void SetChild(HWND hwndChild);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*hwndChild*|no Identificador para a janela a ser contida.|

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [PGM_SETCHILD](/windows/win32/Controls/pgm-setchild) , que é descrita na SDK do Windows.

Esse método não altera o pai da janela contida; Ele atribui apenas um identificador de janela ao controle de pager para rolagem. Na maioria dos casos, a janela contida será uma janela filho do controle de pager.

### <a name="example"></a>Exemplo

O exemplo a seguir cria um controle de pager e, em seguida, usa o método [CPagerCtrl:: SetChild](#setchild) para associar um controle de botão muito longo com o controle de pager. Em seguida, o exemplo usa o método [CPagerCtrl:: SetButtons](#setbuttonsize) para definir a altura do controle de pager como 20 pixels e o método [CPagerCtrl:: SetBorder](#setborder) para definir a espessura da borda como 1 pixel.

[!code-cpp[NVC_MFC_CSplitButton_s2#1](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_1.cpp)]

##  <a name="setscrollpos"></a>  CPagerCtrl::SetScrollPos

Define a posição de rolagem do controle de pager atual.

```
void SetScrollPos(int iPos);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*iPos*|no A nova posição de rolagem, medida em pixels.|

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [PGM_SETPOS](/windows/win32/Controls/pgm-setpos) , que é descrita na SDK do Windows.

## <a name="see-also"></a>Consulte também

[Classe CPagerCtrl](../../mfc/reference/cpagerctrl-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Controles de pager](/windows/win32/Controls/pager-controls)
