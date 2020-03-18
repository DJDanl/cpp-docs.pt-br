---
title: Classe CControlBar
ms.date: 11/04/2016
f1_keywords:
- CControlBar
- AFXEXT/CControlBar
- AFXEXT/CControlBar::CControlBar
- AFXEXT/CControlBar::CalcDynamicLayout
- AFXEXT/CControlBar::CalcFixedLayout
- AFXEXT/CControlBar::CalcInsideRect
- AFXEXT/CControlBar::DoPaint
- AFXEXT/CControlBar::DrawBorders
- AFXEXT/CControlBar::DrawGripper
- AFXEXT/CControlBar::EnableDocking
- AFXEXT/CControlBar::GetBarStyle
- AFXEXT/CControlBar::GetBorders
- AFXEXT/CControlBar::GetCount
- AFXEXT/CControlBar::GetDockingFrame
- AFXEXT/CControlBar::IsFloating
- AFXEXT/CControlBar::OnUpdateCmdUI
- AFXEXT/CControlBar::SetBarStyle
- AFXEXT/CControlBar::SetBorders
- AFXEXT/CControlBar::SetInPlaceOwner
- AFXEXT/CControlBar::m_bAutoDelete
- AFXEXT/CControlBar::m_pInPlaceOwner
helpviewer_keywords:
- CControlBar [MFC], CControlBar
- CControlBar [MFC], CalcDynamicLayout
- CControlBar [MFC], CalcFixedLayout
- CControlBar [MFC], CalcInsideRect
- CControlBar [MFC], DoPaint
- CControlBar [MFC], DrawBorders
- CControlBar [MFC], DrawGripper
- CControlBar [MFC], EnableDocking
- CControlBar [MFC], GetBarStyle
- CControlBar [MFC], GetBorders
- CControlBar [MFC], GetCount
- CControlBar [MFC], GetDockingFrame
- CControlBar [MFC], IsFloating
- CControlBar [MFC], OnUpdateCmdUI
- CControlBar [MFC], SetBarStyle
- CControlBar [MFC], SetBorders
- CControlBar [MFC], SetInPlaceOwner
- CControlBar [MFC], m_bAutoDelete
- CControlBar [MFC], m_pInPlaceOwner
ms.assetid: 4d668c55-9b42-4838-97ac-cf2b3000b82c
ms.openlocfilehash: 41e40b3da7b4a294fe396a9d93f7c6a93593ff95
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79420529"
---
# <a name="ccontrolbar-class"></a>Classe CControlBar

A classe base para as classes de barra de controle [CStatusBar](../../mfc/reference/cstatusbar-class.md), [CToolBar](../../mfc/reference/ctoolbar-class.md), [CDialogBar](../../mfc/reference/cdialogbar-class.md), [CReBar](../../mfc/reference/crebar-class.md)e [COleResizeBar](../../mfc/reference/coleresizebar-class.md).

## <a name="syntax"></a>Sintaxe

```
class CControlBar : public CWnd
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores protegidos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CControlBar::CControlBar](#ccontrolbar)|Constrói um objeto `CControlBar`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CControlBar::CalcDynamicLayout](#calcdynamiclayout)|Retorna o tamanho de uma barra de controle dinâmica como um objeto [CSize](../../atl-mfc-shared/reference/csize-class.md) .|
|[CControlBar::CalcFixedLayout](#calcfixedlayout)|Retorna o tamanho da barra de controle como um objeto [CSize](../../atl-mfc-shared/reference/csize-class.md) .|
|[CControlBar::CalcInsideRect](#calcinsiderect)|Retorna as dimensões atuais da área da barra de controle; incluindo as bordas.|
|[CControlBar::D oPaint](#dopaint)|Renderiza as bordas e a garra da barra de controle.|
|[CControlBar::D rawBorders](#drawborders)|Renderiza as bordas da barra de controle.|
|[CControlBar::D rawGripper](#drawgripper)|Renderiza a garra da barra de controle.|
|[CControlBar::EnableDocking](#enabledocking)|Permite que uma barra de controle seja encaixada ou flutuante.|
|[CControlBar::GetBarStyle](#getbarstyle)|Recupera as configurações de estilo da barra de controle.|
|[CControlBar:: GetBorders](#getborders)|Recupera os valores de borda da barra de controle.|
|[CControlBar:: GetCount](#getcount)|Retorna o número de elementos não HWND na barra de controle.|
|[CControlBar::GetDockingFrame](#getdockingframe)|Retorna um ponteiro para o quadro no qual uma barra de controle é encaixada.|
|[CControlBar:: IsFloat](#isfloating)|Retornará um valor diferente de zero se a barra de controle em questão for uma barra de controle flutuante.|
|[CControlBar::OnUpdateCmdUI](#onupdatecmdui)|Chama os manipuladores de interface do usuário de comando.|
|[CControlBar::SetBarStyle](#setbarstyle)|Modifica as configurações de estilo da barra de controle.|
|[CControlBar:: SetBorders](#setborders)|Define os valores de borda da barra de controle.|
|[CControlBar::SetInPlaceOwner](#setinplaceowner)|Altera o proprietário local de uma barra de controle.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CControlBar:: m_bAutoDelete](#m_bautodelete)|Se for diferente de zero, o objeto `CControlBar` será excluído quando a barra de controle do Windows for destruída.|
|[CControlBar:: m_pInPlaceOwner](#m_pinplaceowner)|O proprietário local da barra de controle.|

## <a name="remarks"></a>Comentários

Uma barra de controle é uma janela que geralmente está alinhada à esquerda ou à direita de uma janela do quadro. Ele pode conter itens filho que são controles baseados em HWND, que são janelas que geram e respondem a mensagens do Windows ou a itens não baseados em HWND, que não são Windows e são gerenciados por código de aplicativo ou código de estrutura. As caixas de listagem e os controles de edição são exemplos de controles baseados em HWND; painéis de status-barra e botões de bitmap são exemplos de controles não baseados em HWND.

As janelas de barras de controle geralmente são janelas filhas de uma janela de quadro pai e geralmente são irmãos à exibição de cliente ou ao cliente MDI da janela do quadro. Um objeto `CControlBar` usa informações sobre o retângulo do cliente da janela pai para se posicionar. Em seguida, ele informa à janela pai o quanto espaço permanece não alocado na área cliente da janela pai.

Para obter mais informações sobre `CControlBar`, consulte:

- [Barras de controle](../../mfc/control-bars.md)

- [Nota técnica 31: barras de controle](../../mfc/tn031-control-bars.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CControlBar`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext. h

##  <a name="calcdynamiclayout"></a>CControlBar::CalcDynamicLayout

A estrutura chama essa função de membro para calcular as dimensões de uma barra de ferramentas dinâmica.

```
virtual CSize CalcDynamicLayout(
    int nLength,
    DWORD nMode);
```

### <a name="parameters"></a>parâmetros

*nLength*<br/>
A dimensão solicitada da barra de controle, seja horizontal ou vertical, dependendo de *dwMode*.

*nMode*<br/>
Os sinalizadores predefinidos a seguir são usados para determinar a altura e a largura da barra de controle dinâmico. Use o operador bit-a&#124;-or () para combinar os sinalizadores.

|Sinalizadores de modo de layout|O que significa|
|-----------------------|-------------------|
|LM_STRETCH|Indica se a barra de controle deve ser ampliada para o tamanho do quadro. Defina se a barra não é uma barra de encaixe (não disponível para encaixe). Não definido quando a barra está encaixada ou flutuante (disponível para encaixe). Se definido, LM_STRETCH ignora *nLength* e retorna dimensões com base no estado de LM_HORZ. LM_STRETCH funciona de forma semelhante ao parâmetro *bStretch* usado em [CalcFixedLayout](#calcfixedlayout); consulte essa função de membro para obter mais informações sobre a relação entre alongamento e orientação.|
|LM_HORZ|Indica que a barra é orientada horizontal ou verticalmente. Defina se a barra é orientada horizontalmente e, se ela for verticalmente orientada, ela não será definida. LM_HORZ funciona de forma semelhante ao parâmetro *bHorz* usado em [CalcFixedLayout](#calcfixedlayout); consulte essa função de membro para obter mais informações sobre a relação entre alongamento e orientação.|
|LM_MRUWIDTH|Largura dinâmica usada mais recentemente. Ignora o parâmetro *nLength* e usa a largura lembrada usada mais recentemente.|
|LM_HORZDOCK|Dimensões encaixadas horizontais. Ignora o parâmetro *nLength* e retorna o tamanho dinâmico com a maior largura.|
|LM_VERTDOCK|Dimensões encaixadas verticais. Ignora o parâmetro *nLength* e retorna o tamanho dinâmico com a maior altura.|
|LM_LENGTHY|Defina se *nLength* indica a altura (direção Y) em vez da largura.|
|LM_COMMIT|Redefine LM_MRUWIDTH para a largura atual da barra de controle flutuante.|

### <a name="return-value"></a>Valor retornado

O tamanho da barra de controle, em pixels, de um objeto [CSize](../../atl-mfc-shared/reference/csize-class.md) .

### <a name="remarks"></a>Comentários

Substitua essa função de membro para fornecer seu próprio layout dinâmico em classes que derivam de `CControlBar`. Classes MFC derivadas de `CControlBar`, como [CToolBar](../../mfc/reference/ctoolbar-class.md), substituem essa função de membro e fornecem sua própria implementação.

##  <a name="calcfixedlayout"></a>CControlBar::CalcFixedLayout

Chame essa função de membro para calcular o tamanho horizontal de uma barra de controle.

```
virtual CSize CalcFixedLayout(
    BOOL bStretch,
    BOOL bHorz);
```

### <a name="parameters"></a>parâmetros

*bStretch*<br/>
Indica se a barra deve ser ampliada para o tamanho do quadro. O parâmetro *bStretch* é diferente de zero quando a barra não é uma barra de encaixe (não disponível para encaixe) e é 0 quando é encaixada ou flutuante (disponível para encaixe).

*bHorz*<br/>
Indica que a barra é orientada horizontal ou verticalmente. O parâmetro *bHorz* será diferente de zero se a barra for horizontalmente orientada e for 0 se for verticalmente orientada.

### <a name="return-value"></a>Valor retornado

O tamanho da barra de controle, em pixels, de um objeto `CSize`.

### <a name="remarks"></a>Comentários

Barras de controle, como barras de ferramentas, podem ser alongadas horizontal ou verticalmente para acomodar os botões contidos na barra de controle.

Se *bStretch* for true, estique a dimensão ao longo da orientação fornecida pelo *bHorz*. Em outras palavras, se *bHorz* for false, a barra de controle será ampliada verticalmente. Se *bStretch* for false, não ocorrerá nenhuma ampliação. A tabela a seguir mostra as possíveis permutas e os estilos de barra de controle resultantes de *bStretch* e *bHorz*.

|bStretch|bHorz|Tira|Orientação|Encaixe/não encaixe|
|--------------|-----------|----------------|-----------------|--------------------------|
|TRUE|TRUE|Alongamento horizontal|Orientado horizontalmente|Sem encaixe|
|TRUE|FALSE|Alongamento vertical|Verticalmente orientado|Sem encaixe|
|FALSE|TRUE|Não há alargamento disponível|Orientado horizontalmente|Docking|
|FALSE|FALSE|Não há alargamento disponível|Verticalmente orientado|Docking|

##  <a name="calcinsiderect"></a>CControlBar::CalcInsideRect

A estrutura chama essa função para calcular a área do cliente da barra de controle.

```
virtual void CalcInsideRect(
    CRect& rect,
    BOOL bHorz) const;
```

### <a name="parameters"></a>parâmetros

*Rect*<br/>
Contém as dimensões atuais da barra de controle; incluindo as bordas.

*bHorz*<br/>
Indica que a barra é orientada horizontal ou verticalmente. O parâmetro *bHorz* será diferente de zero se a barra for horizontalmente orientada e for 0 se for verticalmente orientada.

### <a name="remarks"></a>Comentários

Essa função é chamada antes que a barra de controle seja pintada.

Substitua essa função para personalizar a renderização das bordas e da garra da barra de controle.

##  <a name="ccontrolbar"></a>CControlBar::CControlBar

Constrói um objeto `CControlBar`.

```
CControlBar();
```

##  <a name="dopaint"></a>CControlBar::D oPaint

Chamado pelo Framework para renderizar as bordas e a barra de garra da barra de controle.

```
virtual void DoPaint(CDC* pDC);
```

### <a name="parameters"></a>parâmetros

*pDC*<br/>
Aponta para o contexto do dispositivo a ser usado para renderizar as bordas e a garra da barra de controle.

### <a name="remarks"></a>Comentários

Substitua essa função para personalizar o comportamento de desenho da barra de controle.

Outro método de personalização é substituir as funções `DrawBorders` e `DrawGripper` e adicionar um código de desenho personalizado para as bordas e a garra. Como esses métodos são chamados pelo método de `DoPaint` padrão, uma substituição de `DoPaint` não é necessária.

##  <a name="drawborders"></a>CControlBar::D rawBorders

Chamado pelo Framework para renderizar as bordas da barra de controle.

```
virtual void DrawBorders(
    CDC* pDC,
    CRect& rect);
```

### <a name="parameters"></a>parâmetros

*pDC*<br/>
Aponta para o contexto do dispositivo a ser usado para renderizar as bordas da barra de controle.

*Rect*<br/>
Um objeto `CRect` que contém as dimensões da barra de controle.

### <a name="remarks"></a>Comentários

Substitua essa função para personalizar a aparência das bordas da barra de controle.

##  <a name="drawgripper"></a>CControlBar::D rawGripper

Chamado pelo Framework para renderizar a garra da barra de controle.

```
virtual void DrawGripper(
    CDC* pDC,
    const CRect& rect);
```

### <a name="parameters"></a>parâmetros

*pDC*<br/>
Aponta para o contexto do dispositivo a ser usado para renderizar a garra da barra de controle.

*Rect*<br/>
Um objeto `CRect` que contém as dimensões da garra da barra de controle.

### <a name="remarks"></a>Comentários

Substitua essa função para personalizar a aparência da garra da barra de controle.

##  <a name="enabledocking"></a>CControlBar::EnableDocking

Chame essa função para permitir que uma barra de controle seja encaixada.

```
void EnableDocking(DWORD dwDockStyle);
```

### <a name="parameters"></a>parâmetros

*dwDockStyle*<br/>
Especifica se a barra de controle oferece suporte a encaixe e aos lados de sua janela pai para a qual a barra de controle pode ser encaixada, se houver suporte. Pode ser um ou mais dos seguintes:

- CBRS_ALIGN_TOP permite o encaixe na parte superior da área do cliente.

- CBRS_ALIGN_BOTTOM permite o encaixe na parte inferior da área do cliente.

- CBRS_ALIGN_LEFT permite o encaixe no lado esquerdo da área do cliente.

- CBRS_ALIGN_RIGHT permite o encaixe no lado direito da área do cliente.

- CBRS_ALIGN_ANY permite o encaixe em qualquer lado da área do cliente.

- CBRS_FLOAT_MULTI permite que várias barras de controle sejam flutuadas em uma única janela de mini-quadro.

Se 0 (ou seja, indicando que não há sinalizadores), a barra de controle não será encaixada.

### <a name="remarks"></a>Comentários

Os lados especificados devem corresponder a um dos lados habilitados para encaixe na janela do quadro de destino ou a barra de controle não pode ser encaixada nessa janela do quadro.

##  <a name="getbarstyle"></a>CControlBar::GetBarStyle

Chame essa função para determinar quais **CBRS_** (estilos de barra de controle) estão definidas no momento para a barra de controle.

```
DWORD GetBarStyle();
```

### <a name="return-value"></a>Valor retornado

As configurações atuais de **CBRS_** (estilos de barra de controle) para a barra de controle. Consulte [CControlBar:: SetBarStyle](#setbarstyle) para obter a lista completa de estilos disponíveis.

### <a name="remarks"></a>Comentários

Não trata os estilos de **WS_** (estilo de janela).

##  <a name="getborders"></a>CControlBar:: GetBorders

Retorna os valores da borda atual para a barra de controle.

```
CRect GetBorders() const;
```

### <a name="return-value"></a>Valor retornado

Um objeto `CRect` que contém a largura atual (em pixels) de cada lado do objeto da barra de controle. Por exemplo, o valor do membro *esquerdo* , do objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) , é a largura da borda esquerda.

##  <a name="getcount"></a>CControlBar:: GetCount

Retorna o número de itens não HWND no objeto `CControlBar`.

```
int GetCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens não HWND no objeto de `CControlBar`. Essa função retorna 0 para um objeto [CDialogBar](../../mfc/reference/cdialogbar-class.md) .

### <a name="remarks"></a>Comentários

O tipo do item depende do objeto derivado: painéis para objetos [CStatusBar](../../mfc/reference/cstatusbar-class.md) e botões e separadores para objetos [CToolBar](../../mfc/reference/ctoolbar-class.md) .

##  <a name="getdockingframe"></a>CControlBar::GetDockingFrame

Chame essa função de membro para obter um ponteiro para a janela do quadro atual para a qual sua barra de controle está encaixada.

```
CFrameWnd* GetDockingFrame() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma janela de quadro se for bem-sucedido; caso contrário, NULL.

Se a barra de controle não estiver encaixada em uma janela de quadro (ou seja, se a barra de controle estiver flutuante), essa função retornará um ponteiro para seu [CMiniFrameWnd](../../mfc/reference/cminiframewnd-class.md)pai.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre barras de controle encaixáveis, consulte [CControlBar:: EnableDocking](#enabledocking) e [CFrameWnd::D ockcontrolbar](../../mfc/reference/cframewnd-class.md#dockcontrolbar).

##  <a name="isfloating"></a>CControlBar:: IsFloat

Chame essa função de membro para determinar se a barra de controle está flutuante ou encaixada.

```
BOOL IsFloating() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a barra de controle estiver flutuante; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para alterar o estado de uma barra de controle de encaixar para flutuante, chame [CFrameWnd:: FloatControlBar](../../mfc/reference/cframewnd-class.md#floatcontrolbar).

##  <a name="m_bautodelete"></a>CControlBar:: m_bAutoDelete

Se for diferente de zero, o objeto `CControlBar` será excluído quando a barra de controle do Windows for destruída.

```
BOOL m_bAutoDelete;
```

### <a name="remarks"></a>Comentários

*m_bAutoDelete* é uma variável pública do tipo bool.

Um objeto de barra de controle geralmente é inserido em um objeto de janela de quadro. Nesse caso, *m_bAutoDelete* é 0 porque o objeto de barra de controle inserido é destruído quando a janela do quadro é destruída.

Defina essa variável como um valor diferente de zero se você alocar um objeto `CControlBar` no heap e não planeja chamar **delete**.

##  <a name="m_pinplaceowner"></a>CControlBar:: m_pInPlaceOwner

O proprietário local da barra de controle.

```
CWnd* m_pInPlaceOwner;
```

##  <a name="onupdatecmdui"></a>CControlBar::OnUpdateCmdUI

Essa função de membro é chamada pelo Framework para atualizar o status da barra de ferramentas ou da barra de status.

```
virtual void OnUpdateCmdUI(
    CFrameWnd* pTarget,
    BOOL bDisableIfNoHndler) = 0;
```

### <a name="parameters"></a>parâmetros

*pTarget*<br/>
Aponta para a janela principal do quadro do aplicativo. Esse ponteiro é usado para rotear mensagens de atualização.

*bDisableIfNoHndler*<br/>
Sinalizador que indica se um controle que não tem um manipulador de atualização deve ser exibido automaticamente como desabilitado.

### <a name="remarks"></a>Comentários

Para atualizar um botão ou painel individual, use a macro ON_UPDATE_COMMAND_UI em seu mapa de mensagens para definir um manipulador de atualização adequadamente. Consulte [ON_UPDATE_COMMAND_UI](message-map-macros-mfc.md#on_update_command_ui) para obter mais informações sobre como usar essa macro.

`OnUpdateCmdUI` é chamado pela estrutura quando o aplicativo está ocioso. A janela do quadro a ser atualizada deve ser uma janela filho, pelo menos indiretamente, de uma janela de quadro visível. `OnUpdateCmdUI` é um substituível avançado.

##  <a name="setbarstyle"></a>CControlBar::SetBarStyle

Chame essa função para definir os estilos de **CBRS_** desejados para a barra de controle.

```
void SetBarStyle(DWORD dwStyle);
```

### <a name="parameters"></a>parâmetros

*dwStyle*<br/>
Os estilos desejados para a barra de controle. Pode ser um ou mais dos seguintes:

- CBRS_ALIGN_TOP permite que a barra de controle seja encaixada na parte superior da área do cliente de uma janela do quadro.

- CBRS_ALIGN_BOTTOM permite que a barra de controle seja encaixada na parte inferior da área do cliente de uma janela do quadro.

- CBRS_ALIGN_LEFT permite que a barra de controle seja encaixada no lado esquerdo da área do cliente de uma janela do quadro.

- CBRS_ALIGN_RIGHT permite que a barra de controle seja encaixada no lado direito da área do cliente de uma janela do quadro.

- CBRS_ALIGN_ANY permite que a barra de controle seja encaixada em qualquer lado da área do cliente de uma janela do quadro.

- CBRS_BORDER_TOP faz com que uma borda seja desenhada na borda superior da barra de controle quando ela estaria visível.

- CBRS_BORDER_BOTTOM faz com que uma borda seja desenhada na borda inferior da barra de controle quando ela estaria visível.

- CBRS_BORDER_LEFT Faz com que uma borda seja desenhada na borda esquerda da barra de controle quando ela ficar visível.

- CBRS_BORDER_RIGHT faz com que uma borda seja desenhada na borda direita da barra de controle quando ela ficar visível.

- CBRS_FLOAT_MULTI permite que várias barras de controle sejam flutuadas em uma única janela de mini-quadro.

- CBRS_TOOLTIPS Faz com que as dicas de ferramenta sejam exibidas para a barra de controle.

- CBRS_FLYBY Faz com que o texto da mensagem seja atualizado ao mesmo tempo que as dicas de ferramenta.

- CBRS_GRIPPER causa uma garra, semelhante àquela usada em bandas em um objeto `CReBar`, a ser desenhada para qualquer classe derivada de `CControlBar`.

### <a name="remarks"></a>Comentários

Não afeta as configurações de **WS_** (estilo de janela).

##  <a name="setborders"></a>CControlBar:: SetBorders

Chame essa função para definir o tamanho das bordas da barra de controle.

```
void SetBorders(
    int cxLeft = 0,
    int cyTop = 0,
    int cxRight = 0,
    int cyBottom = 0);

void SetBorders(LPCRECT lpRect);
```

### <a name="parameters"></a>parâmetros

*cxLeft*<br/>
A largura (em pixels) da borda esquerda da barra de controle.

*cyTop*<br/>
A altura (em pixels) da borda superior da barra de controle.

*cxRight*<br/>
A largura (em pixels) da borda direita da barra de controle.

*cyBottom*<br/>
A altura (em pixels) da borda inferior da barra de controle.

*lpRect*<br/>
Um ponteiro para um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) que contém a largura atual (em pixels) de cada borda do objeto de barra de controle.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define as bordas superior e inferior da barra de controle como 5 pixels e as bordas esquerda e direita para 2 pixels:

[!code-cpp[NVC_MFCControlLadenDialog#61](../../mfc/codesnippet/cpp/ccontrolbar-class_1.cpp)]

##  <a name="setinplaceowner"></a>CControlBar::SetInPlaceOwner

Altera o proprietário local de uma barra de controle.

```
void SetInPlaceOwner(CWnd* pWnd);
```

### <a name="parameters"></a>parâmetros

*pWnd*<br/>
Um ponteiro para um objeto `CWnd`.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Exemplo de CTRLBARS do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CToolBar](../../mfc/reference/ctoolbar-class.md)<br/>
[Classe CDialogBar](../../mfc/reference/cdialogbar-class.md)<br/>
[Classe CStatusBar](../../mfc/reference/cstatusbar-class.md)<br/>
[Classe CReBar](../../mfc/reference/crebar-class.md)
