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
ms.openlocfilehash: b2c4f1ac99735953f4832226b840ced4ea4c509a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376973"
---
# <a name="cpagerctrl-class"></a>Classe CPagerCtrl

A `CPagerCtrl` classe envolve o controle do pager do Windows, que pode rolar para a exibição de uma janela contida que não se encaixa na janela de contenção.

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
|[CPagerCtrl::Criar](#create)|Cria um controle de pager com estilos especificados e anexa-o ao objeto atual. `CPagerCtrl`|
|[CPagerCtrl::CreateEx](#createex)|Cria um controle de pager com estilos estendidos `CPagerCtrl` especificados e anexa-o ao objeto atual.|
|[CPagerCtrl::ForwardMouse](#forwardmouse)|Ativa ou desativa o encaminhamento [WM_MOUSEMOVE](/windows/win32/inputdev/wm-mousemove) mensagens para a janela contida no controle do pager atual.|
|[CPagerCtrl::GetBkColor](#getbkcolor)|Recupera a cor de fundo do controle do pager atual.|
|[CPagerCtrl::GetBorder](#getborder)|Recupera o tamanho da borda do controle de pager atual.|
|[CPagerCtrl::GetButtonSize](#getbuttonsize)|Recupera o tamanho do botão do controle do pager atual.|
|[CPagerCtrl::GetButtonState](#getbuttonstate)|Recupera o estado do botão especificado no controle do pager atual.|
|[CPagerCtrl::GetDropTarget](#getdroptarget)|Recupera a interface [IDropTarget](/windows/win32/api/oleidl/nn-oleidl-idroptarget) para o controle atual do pager.|
|[CPagerCtrl::GetScrollPos](#getscrollpos)|Recupera a posição de rolagem do controle atual do pager.|
|[CPagerCtrl::IsButtonDepressed](#isbuttondepressed)|Indica se o botão especificado do controle `pressed` do pager atual está no estado.|
|[CPagerCtrl::IsButtonGrayed](#isbuttongrayed)|Indica se o botão especificado do controle `grayed` do pager atual está no estado.|
|[CPagerCtrl::IsButtonHot](#isbuttonhot)|Indica se o botão especificado do controle `hot` do pager atual está no estado.|
|[CPagerCtrl::IsButtonInvisible](#isbuttoninvisible)|Indica se o botão especificado do controle `invisible` do pager atual está no estado.|
|[CPagerCtrl::IsButtonNormal](#isbuttonnormal)|Indica se o botão especificado do controle `normal` do pager atual está no estado.|
|[CPagerCtrl::RecalcSize](#recalcsize)|Faz com que o controle atual do pager recalcule o tamanho da janela contida.|
|[CPagerCtrl::SetBkColor](#setbkcolor)|Define a cor de fundo do controle do pager atual.|
|[CPagerCtrl::SetBorder](#setborder)|Define o tamanho da borda do controle de pager atual.|
|[CPagerCtrl::SetButtonSize](#setbuttonsize)|Define o tamanho do botão do controle do pager atual.|
|[CPagerCtrl::SetChild](#setchild)|Define a janela contida para o controle do pager atual.|
|[CPagerCtrl::SetScrollPos](#setscrollpos)|Define a posição de rolagem do controle do pager atual.|

## <a name="remarks"></a>Comentários

Um controle de pager é uma janela que contém outra janela que é linear e maior do que a janela de contenção, e permite que você role a janela contida para a exibição. O controle do pager exibe dois botões de rolagem que desaparecem automaticamente quando a janela contida é rolada até a sua extensão mais distante e reaparecem de outra forma. Você pode criar um controle de pager que rola horizontal ou verticalmente.

Por exemplo, se o aplicativo tiver uma barra de ferramentas que não seja larga o suficiente para mostrar todos os seus itens, você pode atribuir a barra de ferramentas a um controle de pager e os usuários poderão rolar a barra de ferramentas para a esquerda ou para a direita para acessar todos os itens. Microsoft Internet Explorer Versão 4.0 (commctrl.dll versão 4.71) introduz o controle do pager.

A `CPagerCtrl` classe é derivada da classe [CWnd.](../../mfc/reference/cwnd-class.md) Para obter mais informações e uma ilustração de um controle de pager, consulte [Controles do Pager](/windows/win32/Controls/pager-controls).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CPagerCtrl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcmn.h

## <a name="cpagerctrlcpagerctrl"></a><a name="cpagerctrl"></a>CPagerCtrl::CPagerCtrl

Constrói um objeto `CPagerCtrl`.

```
CPagerCtrl();
```

### <a name="remarks"></a>Comentários

Use o método [CPagerCtrl::Create](#create) ou [CPagerCtrl::CreateEx](#createex) para criar um `CPagerCtrl` controle de pager e anexá-lo ao objeto.

## <a name="cpagerctrlcreate"></a><a name="create"></a>CPagerCtrl::Criar

Cria um controle de pager com estilos especificados e anexa-o ao objeto atual. `CPagerCtrl`

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
|*Dwstyle*|[em] Uma combinação bitwise (OR) de estilos de [janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) e estilos de [controle de pager](/windows/win32/Controls/pager-control-styles) a serem aplicados ao controle.|
|*Rect*|[em] Uma referência a uma estrutura [RECT](/previous-versions/dd162897\(v=vs.85\)) que contenha a posição e o tamanho do controle nas coordenadas do cliente.|
|*Pparentwnd*|[em] Um ponteiro para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é a janela pai do controle. Esse parâmetro não pode ser NULL.|
|*nID*|[em] A id do controle.|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Para criar um controle de `CPagerCtrl` pager, declare uma variável e, em seguida, chame o [método CPagerCtrl::Create](#create) ou [CPagerCtrl::CreateEx](#createex) nessa variável.

### <a name="example"></a>Exemplo

O exemplo a seguir cria um controle de pager e, em seguida, usa o método [CPagerCtrl::SetChild](#setchild) para associar um controle de botão muito longo com o controle do pager. O exemplo usa então o método [CPagerCtrl::SetButtonSize](#setbuttonsize) para definir a altura do controle do pager para 20 pixels e o método [CPagerCtrl::SetBorder](#setborder) para definir a espessura da borda para 1 pixel.

[!code-cpp[NVC_MFC_CSplitButton_s2#1](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_1.cpp)]

## <a name="cpagerctrlcreateex"></a><a name="createex"></a>CPagerCtrl::CreateEx

Cria um controle de pager com estilos estendidos `CPagerCtrl` especificados e anexa-o ao objeto atual.

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
|*Dwexstyle*|[em] Uma combinação um pouco de estilos estendidos a serem aplicados ao controle. Para obter mais informações, consulte o parâmetro *dwExStyle* da função [CreateWindowEx.](/windows/win32/api/winuser/nf-winuser-createwindowexw)|
|*Dwstyle*|[em] Uma combinação bitwise (OR) de estilos de [janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) e estilos de [controle de pager](/windows/win32/Controls/pager-control-styles) a serem aplicados ao controle.|
|*Rect*|[em] Uma referência a uma estrutura [RECT](/previous-versions/dd162897\(v=vs.85\)) que contenha a posição e o tamanho do controle nas coordenadas do cliente.|
|*Pparentwnd*|[em] Um ponteiro para um objeto [CWnd](../../mfc/reference/cwnd-class.md) que é a janela pai do controle. Esse parâmetro não pode ser NULL.|
|*nID*|[em] A id do controle.|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Para criar um controle de `CPagerCtrl` pager, declare uma variável e, em seguida, chame o [método CPagerCtrl::Create](#create) ou [CPagerCtrl::CreateEx](#createex) nessa variável.

## <a name="cpagerctrlforwardmouse"></a><a name="forwardmouse"></a>CPagerCtrl::ForwardMouse

Ativa ou desativa o encaminhamento [WM_MOUSEMOVE](/windows/win32/inputdev/wm-mousemove) mensagens para a janela contida no controle do pager atual.

```
void ForwardMouse(BOOL bForward);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*bForward*|[em] TRUE para encaminhar mensagens de mouse, ou FALSE para não encaminhar mensagens de mouse.|

### <a name="remarks"></a>Comentários

Este método envia a mensagem [PGM_FORWARDMOUSE,](/windows/win32/Controls/pgm-forwardmouse) que é descrita no SDK do Windows.

## <a name="cpagerctrlgetborder"></a><a name="getborder"></a>CPagerCtrl::GetBorder

Recupera o tamanho da borda do controle de pager atual.

```
int GetBorder() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho da borda atual, medido em pixels.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [PGM_GETBORDER,](/windows/win32/Controls/pgm-getborder) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo a seguir usa o método [CPagerCtrl::GetBorder](#getborder) para recuperar a espessura da borda do controle do pager.

[!code-cpp[NVC_MFC_CSplitButton_s2#5](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_2.cpp)]

## <a name="cpagerctrlgetbkcolor"></a><a name="getbkcolor"></a>CPagerCtrl::GetBkColor

Recupera a cor de fundo do controle do pager atual.

```
COLORREF GetBkColor() const;
```

### <a name="return-value"></a>Valor retornado

Um valor [COLORREF](/windows/win32/gdi/colorref) que contém a cor de fundo atual do controle do pager.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [PGM_GETBKCOLOR,](/windows/win32/Controls/pgm-getbkcolor) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo a seguir usa o método [CPagerCtrl::SetBkColor](#setbkcolor) para definir a cor de fundo do controle do pager como vermelho e o método [CPagerCtrl::GetBkColor](#getbkcolor) para confirmar que a alteração foi feita.

[!code-cpp[NVC_MFC_CSplitButton_s2#4](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_3.cpp)]

## <a name="cpagerctrlgetbuttonsize"></a><a name="getbuttonsize"></a>CPagerCtrl::GetButtonSize

Recupera o tamanho do botão do controle do pager atual.

```
int GetButtonSize() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho atual do botão, medido em pixels.

### <a name="remarks"></a>Comentários

Este método envia a [mensagem PGM_GETBUTTONSIZE,](/windows/win32/Controls/pgm-getbuttonsize) que é descrita no SDK do Windows.

Se o controle do pager tiver o estilo PGS_HORZ, o tamanho do botão determinará a largura dos botões do pager e se o controle do pager tiver o estilo PGS_VERT, o tamanho do botão determinará a altura dos botões do pager. Para obter mais informações, consulte [Estilos de controle do Pager](/windows/win32/Controls/pager-control-styles).

## <a name="cpagerctrlgetbuttonstate"></a><a name="getbuttonstate"></a>CPagerCtrl::GetButtonState

Recupera o estado do botão de rolagem especificado no controle do pager atual.

```
DWORD GetButtonState(int iButton) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Ibutton*|[em] Indica o botão para o qual o estado é recuperado. Se o estilo de controle do pager estiver PGS_HORZ, especifique PGB_TOPORLEFT para o botão esquerdo e PGB_BOTTOMORRIGHT para o botão direito. Se o estilo de controle do pager estiver PGS_VERT, especifique PGB_TOPORLEFT para o botão superior e PGB_BOTTOMORRIGHT para o botão inferior. Para obter mais informações, consulte [Estilos de controle do Pager](/windows/win32/Controls/pager-control-styles).|

### <a name="return-value"></a>Valor retornado

O estado do botão especificado pelo parâmetro *iButton.* O Estado é PGF_INVISIBLE, PGF_NORMAL, PGF_GRAYED, PGF_DEPRESSED ou PGF_HOT. Para obter mais informações, consulte a seção Valor de retorno da mensagem [PGM_GETBUTTONSTATE.](/windows/win32/Controls/pgm-getbuttonstate)

### <a name="remarks"></a>Comentários

Este método envia a mensagem [PGM_GETBUTTONSTATE,](/windows/win32/Controls/pgm-getbuttonstate) que é descrita no SDK do Windows.

## <a name="cpagerctrlgetdroptarget"></a><a name="getdroptarget"></a>CPagerCtrl::GetDropTarget

Recupera a interface [IDropTarget](/windows/win32/api/oleidl/nn-oleidl-idroptarget) para o controle atual do pager.

```
IDropTarget* GetDropTarget() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro `IDropTarget` para a interface para o controle do pager atual.

### <a name="remarks"></a>Comentários

`IDropTarget`é uma das interfaces que você implementa para suportar operações de arrastar e soltar em seu aplicativo.

Este método envia a mensagem [PGM_GETDROPTARGET,](/windows/win32/Controls/pgm-getdroptarget) que é descrita no SDK do Windows. O chamador deste método é `Release` responsável por chamar o membro da interface [IDropTarget](/windows/win32/api/oleidl/nn-oleidl-idroptarget) quando a interface não é mais necessária.

## <a name="cpagerctrlgetscrollpos"></a><a name="getscrollpos"></a>CPagerCtrl::GetScrollPos

Recupera a posição de rolagem do controle atual do pager.

```
int GetScrollPos() const;
```

### <a name="return-value"></a>Valor retornado

A posição atual do pergaminho, medida em pixels.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [PGM_GETPOS,](/windows/win32/Controls/pgm-getpos) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo a seguir usa o método [CPagerCtrl::GetScrollPos](#getscrollpos) para recuperar a posição de rolagem atual do controle do pager. Se o controle do pager ainda não estiver rilhado para zero, na posição mais à esquerda, o exemplo usará o método [CPagerCtrl::SetScrollPos](#setscrollpos) para definir a posição de rolagem como zero.

[!code-cpp[NVC_MFC_CSplitButton_s2#7](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_4.cpp)]

## <a name="cpagerctrlisbuttondepressed"></a><a name="isbuttondepressed"></a>CPagerCtrl::IsButtonDepressed

Indica se o botão de rolagem especificado do controle atual do pager está em estado pressionado.

```
BOOL IsButtonDepressed(int iButton) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Ibutton*|[em] Indica o botão para o qual o estado é recuperado. Se o estilo de controle do pager estiver PGS_HORZ, especifique PGB_TOPORLEFT para o botão esquerdo e PGB_BOTTOMORRIGHT para o botão direito. Se o estilo de controle do pager estiver PGS_VERT, especifique PGB_TOPORLEFT para o botão superior e PGB_BOTTOMORRIGHT para o botão inferior. Para obter mais informações, consulte [Estilos de controle do Pager](/windows/win32/Controls/pager-control-styles).|

### <a name="return-value"></a>Valor retornado

TRUE se o botão especificado estiver em estado pressionado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [PGM_GETBUTTONSTATE,](/windows/win32/Controls/pgm-getbuttonstate) que é descrita no SDK do Windows. Em seguida, testa se o estado que é devolvido é PGF_DEPRESSED. Para obter mais informações, consulte a seção Valor de retorno da mensagem [PGM_GETBUTTONSTATE.](/windows/win32/Controls/pgm-getbuttonstate)

## <a name="cpagerctrlisbuttongrayed"></a><a name="isbuttongrayed"></a>CPagerCtrl::IsButtonGrayed

Indica se o botão de rolagem especificado do controle atual do pager está em estado cinza.

```
BOOL IsButtonGrayed(int iButton) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Ibutton*|[em] Indica o botão para o qual o estado é recuperado. Se o estilo de controle do pager estiver PGS_HORZ, especifique PGB_TOPORLEFT para o botão esquerdo e PGB_BOTTOMORRIGHT para o botão direito. Se o estilo de controle do pager estiver PGS_VERT, especifique PGB_TOPORLEFT para o botão superior e PGB_BOTTOMORRIGHT para o botão inferior. Para obter mais informações, consulte [Estilos de controle do Pager](/windows/win32/Controls/pager-control-styles).|

### <a name="return-value"></a>Valor retornado

TRUE se o botão especificado estiver em estado cinza; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [PGM_GETBUTTONSTATE,](/windows/win32/Controls/pgm-getbuttonstate) que é descrita no SDK do Windows. Em seguida, testa se o estado que é devolvido é PGF_GRAYED. Para obter mais informações, consulte a seção Valor de retorno da mensagem [PGM_GETBUTTONSTATE.](/windows/win32/Controls/pgm-getbuttonstate)

## <a name="cpagerctrlisbuttonhot"></a><a name="isbuttonhot"></a>CPagerCtrl::IsButtonHot

Indica se o botão de rolagem especificado do controle atual do pager está em estado quente.

```
BOOL IsButtonHot(int iButton) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Ibutton*|[em] Indica o botão para o qual o estado é recuperado. Se o estilo de controle do pager estiver PGS_HORZ, especifique PGB_TOPORLEFT para o botão esquerdo e PGB_BOTTOMORRIGHT para o botão direito. Se o estilo de controle do pager estiver PGS_VERT, especifique PGB_TOPORLEFT para o botão superior e PGB_BOTTOMORRIGHT para o botão inferior. Para obter mais informações, consulte [Estilos de controle do Pager](/windows/win32/Controls/pager-control-styles).|

### <a name="return-value"></a>Valor retornado

TRUE se o botão especificado estiver em estado quente; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [PGM_GETBUTTONSTATE,](/windows/win32/Controls/pgm-getbuttonstate) que é descrita no SDK do Windows. Em seguida, testa se o estado que é devolvido é PGF_HOT. Para obter mais informações, consulte a seção Valor de retorno da mensagem [PGM_GETBUTTONSTATE.](/windows/win32/Controls/pgm-getbuttonstate)

## <a name="cpagerctrlisbuttoninvisible"></a><a name="isbuttoninvisible"></a>CPagerCtrl::IsButtonInvisible

Indica se o botão de rolagem especificado do controle atual do pager está em estado invisível.

```
BOOL IsButtonInvisible(int iButton) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Ibutton*|[em] Indica o botão para o qual o estado é recuperado. Se o estilo de controle do pager estiver PGS_HORZ, especifique PGB_TOPORLEFT para o botão esquerdo e PGB_BOTTOMORRIGHT para o botão direito. Se o estilo de controle do pager estiver PGS_VERT, especifique PGB_TOPORLEFT para o botão superior e PGB_BOTTOMORRIGHT para o botão inferior. Para obter mais informações, consulte [Estilos de controle do Pager](/windows/win32/Controls/pager-control-styles).|

### <a name="return-value"></a>Valor retornado

TRUE se o botão especificado estiver em estado invisível; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O Windows torna o botão de rolagem em uma direção particular invisível quando a janela contida é rolada até a sua extensão mais distante porque clicar no botão não pode trazer mais da janela contida para a exibição.

Este método envia a mensagem [PGM_GETBUTTONSTATE,](/windows/win32/Controls/pgm-getbuttonstate) que é descrita no SDK do Windows. Em seguida, testa se o estado que é devolvido é PGF_INVISIBLE. Para obter mais informações, consulte a seção Valor de retorno da mensagem [PGM_GETBUTTONSTATE.](/windows/win32/Controls/pgm-getbuttonstate)

### <a name="example"></a>Exemplo

O exemplo a seguir usa o método [CPagerCtrl::IsButtonInvisible](#isbuttoninvisible) para determinar se os botões de rolagem esquerda e direita do controle do pager são visíveis.

[!code-cpp[NVC_MFC_CSplitButton_s2#6](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_5.cpp)]

## <a name="cpagerctrlisbuttonnormal"></a><a name="isbuttonnormal"></a>CPagerCtrl::IsButtonNormal

Indica se o botão de rolagem especificado do controle atual do pager está em estado normal.

```
BOOL IsButtonNormal(int iButton) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Ibutton*|[em] Indica o botão para o qual o estado é recuperado. Se o estilo de controle do pager estiver PGS_HORZ, especifique PGB_TOPORLEFT para o botão esquerdo e PGB_BOTTOMORRIGHT para o botão direito. Se o estilo de controle do pager estiver PGS_VERT, especifique PGB_TOPORLEFT para o botão superior e PGB_BOTTOMORRIGHT para o botão inferior. Para obter mais informações, consulte [Estilos de controle do Pager](/windows/win32/Controls/pager-control-styles).|

### <a name="return-value"></a>Valor retornado

TRUE se o botão especificado estiver em estado normal; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [PGM_GETBUTTONSTATE,](/windows/win32/Controls/pgm-getbuttonstate) que é descrita no SDK do Windows. Em seguida, testa se o estado que é devolvido é PGF_NORMAL. Para obter mais informações, consulte a seção Valor de retorno da mensagem [PGM_GETBUTTONSTATE.](/windows/win32/Controls/pgm-getbuttonstate)

## <a name="cpagerctrlrecalcsize"></a><a name="recalcsize"></a>CPagerCtrl::RecalcSize

Faz com que o controle atual do pager recalcule o tamanho da janela contida.

```
void RecalcSize();
```

### <a name="remarks"></a>Comentários

Este método envia a [mensagem PGM_RECALCSIZE,](/windows/win32/Controls/pgm-recalcsize) que é descrita no SDK do Windows. Consequentemente, o controle do pager envia a notificação [PGN_CALCSIZE](/windows/win32/Controls/pgn-calcsize) para obter as dimensões roláveis da janela contida.

### <a name="example"></a>Exemplo

O exemplo a seguir usa o método [CPagerCtrl::RecalcSize](#recalcsize) para solicitar o controle atual do pager para recalcular seu tamanho.

[!code-cpp[NVC_MFC_CSplitButton_s2#3](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_6.cpp)]

### <a name="example"></a>Exemplo

O exemplo a seguir usa a reflexão de [mensagem](../../mfc/tn062-message-reflection-for-windows-controls.md) para permitir que o controle do pager recalcule seu próprio tamanho em vez de exigir que a caixa de diálogo pai do controle execute o cálculo. O exemplo deriva `MyPagerCtrl` a classe da [classe CPagerCtrl](../../mfc/reference/cpagerctrl-class.md)e, em seguida, `OnCalcsize` usa um mapa de mensagem para associar a notificação [PGN_CALCSIZE](/windows/win32/Controls/pgn-calcsize) com o manipulador de notificação. Neste exemplo, o manipulador de notificações define a largura e a altura do controle do pager como valores fixos.

[!code-cpp[NVC_MFC_CSplitButton_s2#8](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_7.cpp)]

## <a name="cpagerctrlsetbkcolor"></a><a name="setbkcolor"></a>CPagerCtrl::SetBkColor

Define a cor de fundo do controle do pager atual.

```
COLORREF SetBkColor(COLORREF clrBk);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*clrBk*|[em] Um valor [COLORREF](/windows/win32/gdi/colorref) que contém a nova cor de fundo do controle do pager.|

### <a name="return-value"></a>Valor retornado

Um valor [COLORREF](/windows/win32/gdi/colorref) que contém a cor de fundo anterior do controle do pager.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [PGM_SETBKCOLOR,](/windows/win32/Controls/pgm-setbkcolor) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo a seguir usa o método [CPagerCtrl::SetBkColor](#setbkcolor) para definir a cor de fundo do controle do pager como vermelho e o método [CPagerCtrl::GetBkColor](#getbkcolor) para confirmar que a alteração foi feita.

[!code-cpp[NVC_MFC_CSplitButton_s2#4](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_3.cpp)]

## <a name="cpagerctrlsetborder"></a><a name="setborder"></a>CPagerCtrl::SetBorder

Define o tamanho da borda do controle de pager atual.

```
int SetBorder(int iBorder);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*iBorder*|[em] O novo tamanho da borda, medido em pixels. Se o parâmetro *iBorder* for negativo, o tamanho da borda será definido como zero.|

### <a name="return-value"></a>Valor retornado

O tamanho da borda anterior, medido em pixels.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [PGM_SETBORDER,](/windows/win32/Controls/pgm-setborder) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo a seguir cria um controle de pager e, em seguida, usa o método [CPagerCtrl::SetChild](#setchild) para associar um controle de botão muito longo com o controle do pager. O exemplo usa então o método [CPagerCtrl::SetButtonSize](#setbuttonsize) para definir a altura do controle do pager para 20 pixels e o método [CPagerCtrl::SetBorder](#setborder) para definir a espessura da borda para 1 pixel.

[!code-cpp[NVC_MFC_CSplitButton_s2#1](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_1.cpp)]

## <a name="cpagerctrlsetbuttonsize"></a><a name="setbuttonsize"></a>CPagerCtrl::SetButtonSize

Define o tamanho do botão do controle do pager atual.

```
int SetButtonSize(int iButtonSize);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*iButtonSize*|[em] O novo tamanho do botão, medido em pixels.|

### <a name="return-value"></a>Valor retornado

O tamanho do botão anterior, medido em pixels.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [PGM_SETBUTTONSIZE,](/windows/win32/Controls/pgm-setpos) que é descrita no SDK do Windows.

Se o controle do pager tiver o estilo PGS_HORZ, o tamanho do botão determinará a largura dos botões do pager e se o controle do pager tiver o estilo PGS_VERT, o tamanho do botão determinará a altura dos botões do pager. O tamanho padrão do botão é de três quartos da largura da barra de rolagem, e o tamanho mínimo do botão é de 12 pixels. Para obter mais informações, consulte [Estilos de controle do Pager](/windows/win32/Controls/pager-control-styles).

### <a name="example"></a>Exemplo

O exemplo a seguir cria um controle de pager e, em seguida, usa o método [CPagerCtrl::SetChild](#setchild) para associar um controle de botão muito longo com o controle do pager. O exemplo usa então o método [CPagerCtrl::SetButtonSize](#setbuttonsize) para definir a altura do controle do pager para 20 pixels e o método [CPagerCtrl::SetBorder](#setborder) para definir a espessura da borda para 1 pixel.

[!code-cpp[NVC_MFC_CSplitButton_s2#1](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_1.cpp)]

## <a name="cpagerctrlsetchild"></a><a name="setchild"></a>CPagerCtrl::SetChild

Define a janela contida para o controle do pager atual.

```
void SetChild(HWND hwndChild);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*hwndChild*|[em] Manuseie a janela a ser contida.|

### <a name="remarks"></a>Comentários

Este método envia a mensagem [PGM_SETCHILD,](/windows/win32/Controls/pgm-setchild) que é descrita no SDK do Windows.

Este método não altera o pai da janela contida; ele apenas atribui uma alça de janela ao controle do pager para rolagem. Na maioria dos casos, a janela contida será uma janela infantil do controle do pager.

### <a name="example"></a>Exemplo

O exemplo a seguir cria um controle de pager e, em seguida, usa o método [CPagerCtrl::SetChild](#setchild) para associar um controle de botão muito longo com o controle do pager. O exemplo usa então o método [CPagerCtrl::SetButtonSize](#setbuttonsize) para definir a altura do controle do pager para 20 pixels e o método [CPagerCtrl::SetBorder](#setborder) para definir a espessura da borda para 1 pixel.

[!code-cpp[NVC_MFC_CSplitButton_s2#1](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_1.cpp)]

## <a name="cpagerctrlsetscrollpos"></a><a name="setscrollpos"></a>CPagerCtrl::SetScrollPos

Define a posição de rolagem do controle do pager atual.

```
void SetScrollPos(int iPos);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Ipos*|[em] A nova posição do pergaminho, medida em pixels.|

### <a name="remarks"></a>Comentários

Este método envia a mensagem [PGM_SETPOS,](/windows/win32/Controls/pgm-setpos) que é descrita no SDK do Windows.

## <a name="see-also"></a>Confira também

[Classe CPagerCtrl](../../mfc/reference/cpagerctrl-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Controles de pager](/windows/win32/Controls/pager-controls)
