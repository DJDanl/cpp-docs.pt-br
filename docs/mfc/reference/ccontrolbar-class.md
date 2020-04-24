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
ms.openlocfilehash: c2f8ea48bf9a1f015928650085b07198b152771a
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754791"
---
# <a name="ccontrolbar-class"></a>Classe CControlBar

A classe base para as classes [cstatusbar,](../../mfc/reference/cstatusbar-class.md) [CToolBar,](../../mfc/reference/ctoolbar-class.md) [CDialogBar,](../../mfc/reference/cdialogbar-class.md) [CReBar](../../mfc/reference/crebar-class.md)e [COleResizeBar](../../mfc/reference/coleresizebar-class.md).

## <a name="syntax"></a>Sintaxe

```
class CControlBar : public CWnd
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[Barra de controle::CControlBar](#ccontrolbar)|Constrói um objeto `CControlBar`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CControlBar::CalcDynamicLayout](#calcdynamiclayout)|Retorna o tamanho de uma barra de controle dinâmica como um objeto [CSize.](../../atl-mfc-shared/reference/csize-class.md)|
|[CControlBar::CalcFixedLayout](#calcfixedlayout)|Retorna o tamanho da barra de controle como um objeto [CSize.](../../atl-mfc-shared/reference/csize-class.md)|
|[CControlBar::CalcInsideRect](#calcinsiderect)|Retorna as dimensões atuais da área da barra de controle; incluindo as fronteiras.|
|[CControlBar::DoPaint](#dopaint)|Torna as bordas e a aderência da barra de controle.|
|[CControlBar::D-arrastemfronteiras](#drawborders)|Torna as bordas da barra de controle.|
|[CControlBar::DrawGripper](#drawgripper)|Torna o aperto da barra de controle.|
|[CControlBar::Ativardocking](#enabledocking)|Permite que uma barra de controle seja encaixada ou flutuando.|
|[CControlBar::GetBarStyle](#getbarstyle)|Recupera as configurações de estilo da barra de controle.|
|[CControlBar::GetBorders](#getborders)|Recupera os valores de borda da barra de controle.|
|[CControlBar::GetCount](#getcount)|Retorna o número de elementos não-HWND na barra de controle.|
|[CControlBar::GetDockingFrame](#getdockingframe)|Retorna um ponteiro para o quadro ao qual uma barra de controle está encaixada.|
|[Barra de controle::está flutuando](#isfloating)|Retorna um valor não zero se a barra de controle em questão for uma barra de controle flutuante.|
|[CControlBar::OnUpdateCmdUI](#onupdatecmdui)|Chama os manipuladores de UI de comando.|
|[CControlBar::SetBarStyle](#setbarstyle)|Modifica as configurações de estilo da barra de controle.|
|[CControlBar::SetBorders](#setborders)|Define os valores de borda da barra de controle.|
|[CControlBar::setInPlaceowner](#setinplaceowner)|Muda o dono de uma barra de controle no lugar.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[Barra de controle::m_bAutoDelete](#m_bautodelete)|Se não zero, o `CControlBar` objeto será excluído quando a barra de controle do Windows for destruída.|
|[Barra de controle::m_pInPlaceOwner](#m_pinplaceowner)|O dono da barra de controle.|

## <a name="remarks"></a>Comentários

Uma barra de controle é uma janela que geralmente está alinhada à esquerda ou à direita de uma janela de quadro. Ele pode conter itens infantis que são controles baseados em HWND, que são janelas que geram e respondem a mensagens do Windows, ou itens não baseados em HWND, que não são janelas e são gerenciados por código de aplicativo ou código-quadro. Caixas de lista e controles de edição são exemplos de controles baseados em HWND; painéis de barras de status e botões de bitmap são exemplos de controles não baseados em HWND.

As janelas da barra de controle geralmente são janelas de uma janela de quadro dos pais e geralmente são irmãos para a exibição do cliente ou cliente MDI da janela do quadro. Um `CControlBar` objeto usa informações sobre o retângulo do cliente da janela pai para se posicionar. Em seguida, ele informa a janela pai quanto ao espaço que permanece não alocado na área cliente da janela pai.

Para obter `CControlBar`mais informações sobre, consulte:

- [Barras de controle](../../mfc/control-bars.md)

- [Nota Técnica 31: Barras de Controle](../../mfc/tn031-control-bars.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CControlBar`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

## <a name="ccontrolbarcalcdynamiclayout"></a><a name="calcdynamiclayout"></a>CControlBar::CalcDynamicLayout

A estrutura chama essa função de membro para calcular as dimensões de uma barra de ferramentas dinâmica.

```
virtual CSize CalcDynamicLayout(
    int nLength,
    DWORD nMode);
```

### <a name="parameters"></a>Parâmetros

*Nlength*<br/>
A dimensão solicitada da barra de controle, horizontal ou vertical, dependendo do *dwMode*.

*nMode*<br/>
As seguintes bandeiras predefinidas são usadas para determinar a altura e a largura da barra de controle dinâmica. Use o operador bitwise-OR (&#124;) para combinar as bandeiras.

|Sinalizadores de modo de layout|O que significa|
|-----------------------|-------------------|
|LM_STRETCH|Indica se a barra de controle deve ser esticada até o tamanho do quadro. Defina se a barra não for uma barra de acoplamento (não disponível para acoplamento). Não definido quando a barra está ancorada ou flutuando (disponível para acoplamento). Se definido, LM_STRETCH ignora *nComprimento* e retorna as dimensões com base no estado LM_HORZ. LM_STRETCH funciona de forma semelhante ao parâmetro *bStretch* usado em [CalcFixedLayout](#calcfixedlayout); ver essa função de membro para obter mais informações sobre a relação entre alongamento e orientação.|
|LM_HORZ|Indica que a barra está horizontal ou verticalmente orientada. Defina se a barra estiver orientada horizontalmente e se estiver orientada verticalmente, ela não está definida. LM_HORZ funciona de forma semelhante ao parâmetro *bHorz* usado em [CalcFixedLayout](#calcfixedlayout); ver essa função de membro para obter mais informações sobre a relação entre alongamento e orientação.|
|LM_MRUWIDTH|Mais recentemente usado largura dinâmica. Ignora o parâmetro *nLength* e usa a largura usada mais recentemente.|
|LM_HORZDOCK|Dimensões Horizontais Ancoradas. Ignora o parâmetro *nLength* e retorna o tamanho dinâmico com a maior largura.|
|LM_VERTDOCK|Dimensões ancoradas verticais. Ignora o parâmetro *nLength* e retorna o tamanho dinâmico com a maior altura.|
|LM_LENGTHY|Ajuste se *nComprimento* indicar altura (direção Y) em vez de largura.|
|LM_COMMIT|Reinicia LM_MRUWIDTH para a largura atual da barra de controle flutuante.|

### <a name="return-value"></a>Valor retornado

O tamanho da barra de controle, em pixels, de um objeto [CSize.](../../atl-mfc-shared/reference/csize-class.md)

### <a name="remarks"></a>Comentários

Substituir essa função de membro para fornecer seu `CControlBar`próprio layout dinâmico em classes das aulas das que você deriva . As classes MFC `CControlBar`derivadas, como [cToolbar,](../../mfc/reference/ctoolbar-class.md)sobrepõem essa função de membro e fornecem sua própria implementação.

## <a name="ccontrolbarcalcfixedlayout"></a><a name="calcfixedlayout"></a>CControlBar::CalcFixedLayout

Ligue para esta função de membro para calcular o tamanho horizontal de uma barra de controle.

```
virtual CSize CalcFixedLayout(
    BOOL bStretch,
    BOOL bHorz);
```

### <a name="parameters"></a>Parâmetros

*Bstretch*<br/>
Indica se a barra deve ser esticada até o tamanho do quadro. O parâmetro *bStretch* não é zero quando a barra não é uma barra de acoplamento (não disponível para acoplamento) e é 0 quando está ancorada ou flutuante (disponível para acoplamento).

*Bhorz*<br/>
Indica que a barra está horizontal ou verticalmente orientada. O parâmetro *bHorz* não é zero se a barra for orientada horizontalmente e for 0 se for orientada verticalmente.

### <a name="return-value"></a>Valor retornado

O tamanho da barra de controle, em pixels, de um `CSize` objeto.

### <a name="remarks"></a>Comentários

Barras de controle como barras de ferramentas podem esticar horizontal ou verticalmente para acomodar os botões contidos na barra de controle.

Se *bStretch* for TRUE, estique a dimensão ao longo da orientação fornecida por *bHorz*. Em outras palavras, se *bHorz* é FALSE, a barra de controle é esticada verticalmente. Se *bStretch* for FALSO, não ocorre nenhum estiramento. A tabela a seguir mostra as possíveis permutações, e os estilos resultantes da barra de controle, de *bStretch* e *bHorz*.

|Bstretch|Bhorz|Esticão|Orientação|Acoplamento/Não acoplamento|
|--------------|-----------|----------------|-----------------|--------------------------|
|TRUE|TRUE|Alongamento horizontal|Horizontalmente orientado|Não acoplar|
|TRUE|FALSE|Alongamento vertical|Orientado verticalmente|Não acoplar|
|FALSE|TRUE|Não há alongamento disponível|Horizontalmente orientado|Encaixe|
|FALSE|FALSE|Não há alongamento disponível|Orientado verticalmente|Encaixe|

## <a name="ccontrolbarcalcinsiderect"></a><a name="calcinsiderect"></a>CControlBar::CalcInsideRect

O framework chama essa função para calcular a área do cliente da barra de controle.

```
virtual void CalcInsideRect(
    CRect& rect,
    BOOL bHorz) const;
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
Contém as dimensões atuais da barra de controle; incluindo as fronteiras.

*Bhorz*<br/>
Indica que a barra está horizontal ou verticalmente orientada. O parâmetro *bHorz* não é zero se a barra for orientada horizontalmente e for 0 se for orientada verticalmente.

### <a name="remarks"></a>Comentários

Esta função é chamada antes da barra de controle ser pintada.

Anular esta função para personalizar a renderização das bordas e da barra de aperto da barra de controle.

## <a name="ccontrolbarccontrolbar"></a><a name="ccontrolbar"></a>Barra de controle::CControlBar

Constrói um objeto `CControlBar`.

```
CControlBar();
```

## <a name="ccontrolbardopaint"></a><a name="dopaint"></a>CControlBar::DoPaint

Chamado pela estrutura para tornar as bordas e a barra de aderência da barra de controle.

```
virtual void DoPaint(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Aponta para o contexto do dispositivo a ser usado para renderizar as bordas e o aperto da barra de controle.

### <a name="remarks"></a>Comentários

Anular esta função para personalizar o comportamento de desenho da barra de controle.

Outro método de personalização `DrawBorders` é `DrawGripper` substituir as funções e adicionar código de desenho personalizado para as bordas e gripper. Como esses métodos são `DoPaint` chamados pelo método `DoPaint` padrão, não é necessário uma substituição.

## <a name="ccontrolbardrawborders"></a><a name="drawborders"></a>CControlBar::D-arrastemfronteiras

Chamado pelo quadro para tornar as fronteiras da barra de controle.

```
virtual void DrawBorders(
    CDC* pDC,
    CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Aponta para o contexto do dispositivo a ser usado para renderizar as bordas da barra de controle.

*Rect*<br/>
Um `CRect` objeto contendo as dimensões da barra de controle.

### <a name="remarks"></a>Comentários

Anular esta função para personalizar a aparência das bordas da barra de controle.

## <a name="ccontrolbardrawgripper"></a><a name="drawgripper"></a>CControlBar::DrawGripper

Chamado pela estrutura para renderizar o gripper da barra de controle.

```
virtual void DrawGripper(
    CDC* pDC,
    const CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Aponta para o contexto do dispositivo a ser usado para renderizar o gripper da barra de controle.

*Rect*<br/>
Um `CRect` objeto contendo as dimensões do gripper da barra de controle.

### <a name="remarks"></a>Comentários

Anular esta função para personalizar a aparência do gripper da barra de controle.

## <a name="ccontrolbarenabledocking"></a><a name="enabledocking"></a>CControlBar::Ativardocking

Ligue para esta função para permitir que uma barra de controle seja encaixada.

```cpp
void EnableDocking(DWORD dwDockStyle);
```

### <a name="parameters"></a>Parâmetros

*dwDockStyle*<br/>
Especifica se a barra de controle suporta o encaixe e os lados da janela pai para a qual a barra de controle pode ser encaixada, se suportada. Pode ser um ou mais dos seguintes:

- CBRS_ALIGN_TOP permite acoplar no topo da área do cliente.

- CBRS_ALIGN_BOTTOM permite acoplar na parte inferior da área do cliente.

- CBRS_ALIGN_LEFT permite acoplar no lado esquerdo da área do cliente.

- CBRS_ALIGN_RIGHT Permite acoplar no lado direito da área do cliente.

- CBRS_ALIGN_ANY permite ancorar em qualquer lado da área do cliente.

- CBRS_FLOAT_MULTI Permite que várias barras de controle sejam flutuadas em uma única janela de miniquadro.

Se 0 (ou seja, sem bandeiras), a barra de controle não atracará.

### <a name="remarks"></a>Comentários

Os lados especificados devem corresponder a um dos lados habilitados para acoplamento na janela do quadro de destino, ou a barra de controle não pode ser encaixada nessa janela de quadro.

## <a name="ccontrolbargetbarstyle"></a><a name="getbarstyle"></a>CControlBar::GetBarStyle

Ligue para esta função para determinar quais **CBRS_** (estilos de barra de controle) estão atualmente definidas para a barra de controle.

```
DWORD GetBarStyle();
```

### <a name="return-value"></a>Valor retornado

As configurações atuais **CBRS_** (estilos de barra de controle) para a barra de controle. Consulte [CControlBar::SetBarStyle](#setbarstyle) para obter a lista completa de estilos disponíveis.

### <a name="remarks"></a>Comentários

Não lida com **estilos WS_** (estilo de janela).

## <a name="ccontrolbargetborders"></a><a name="getborders"></a>CControlBar::GetBorders

Retorna os valores de borda atuais para a barra de controle.

```
CRect GetBorders() const;
```

### <a name="return-value"></a>Valor retornado

Um `CRect` objeto que contém a largura atual (em pixels) de cada lado do objeto da barra de controle. Por exemplo, o valor do membro *esquerdo,* do objeto [CRect,](../../atl-mfc-shared/reference/crect-class.md) é a largura da borda da mão esquerda.

## <a name="ccontrolbargetcount"></a><a name="getcount"></a>CControlBar::GetCount

Retorna o número de itens não-HWND no `CControlBar` objeto.

```
int GetCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens não-HWND `CControlBar` no objeto. Esta função retorna 0 para um objeto [CDialogBar.](../../mfc/reference/cdialogbar-class.md)

### <a name="remarks"></a>Comentários

O tipo do item depende do objeto derivado: painéis para objetos [CStatusBar](../../mfc/reference/cstatusbar-class.md) e botões e separadores para objetos [CToolBar.](../../mfc/reference/ctoolbar-class.md)

## <a name="ccontrolbargetdockingframe"></a><a name="getdockingframe"></a>CControlBar::GetDockingFrame

Ligue para esta função de membro para obter um ponteiro para a janela atual do quadro para a qual a barra de controle está encaixada.

```
CFrameWnd* GetDockingFrame() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma janela de quadro se for bem sucedido; caso contrário, NULL.

Se a barra de controle não estiver encaixada em uma janela de quadro (isto é, se a barra de controle estiver flutuando), esta função retornará um ponteiro para seu [CMiniFrameWnd](../../mfc/reference/cminiframewnd-class.md)pai .

### <a name="remarks"></a>Comentários

Para obter mais informações sobre barras de controle ancoráveis, consulte [CControlBar:EnableDocking](#enabledocking) e [CFrameWnd::DockControlBar](../../mfc/reference/cframewnd-class.md#dockcontrolbar).

## <a name="ccontrolbarisfloating"></a><a name="isfloating"></a>Barra de controle::está flutuando

Ligue para esta função de membro para determinar se a barra de controle está flutuando ou encaixada.

```
BOOL IsFloating() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se a barra de controle estiver flutuando; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para alterar o estado de uma barra de controle de ancorada para flutuante, ligue para [CFrameWnd::FloatControlBar](../../mfc/reference/cframewnd-class.md#floatcontrolbar).

## <a name="ccontrolbarm_bautodelete"></a><a name="m_bautodelete"></a>Barra de controle::m_bAutoDelete

Se não zero, o `CControlBar` objeto será excluído quando a barra de controle do Windows for destruída.

```
BOOL m_bAutoDelete;
```

### <a name="remarks"></a>Comentários

*m_bAutoDelete* é uma variável pública do tipo BOOL.

Um objeto de barra de controle geralmente está incorporado em um objeto de janela de quadro. Neste caso, *m_bAutoDelete* é 0 porque o objeto da barra de controle incorporado é destruído quando a janela do quadro é destruída.

Defina essa variável como um valor `CControlBar` não zero se você alocar um objeto no heap e não pretende chamar **excluir**.

## <a name="ccontrolbarm_pinplaceowner"></a><a name="m_pinplaceowner"></a>Barra de controle::m_pInPlaceOwner

O dono da barra de controle.

```
CWnd* m_pInPlaceOwner;
```

## <a name="ccontrolbaronupdatecmdui"></a><a name="onupdatecmdui"></a>CControlBar::OnUpdateCmdUI

Esta função de membro é chamada pela framework para atualizar o status da barra de ferramentas ou barra de status.

```
virtual void OnUpdateCmdUI(
    CFrameWnd* pTarget,
    BOOL bDisableIfNoHndler) = 0;
```

### <a name="parameters"></a>Parâmetros

*Ptarget*<br/>
Aponta para a janela principal do quadro da aplicação. Este ponteiro é usado para roteamento de mensagens de atualização.

*bDisableIfNoHndler*<br/>
Sinalizador que indica se um controle que não tem manipulador de atualização deve ser exibido automaticamente como desativado.

### <a name="remarks"></a>Comentários

Para atualizar um botão ou painel individual, use a macro ON_UPDATE_COMMAND_UI no mapa de mensagens para definir um manipulador de atualizações adequadamente. Consulte [ON_UPDATE_COMMAND_UI](message-map-macros-mfc.md#on_update_command_ui) para obter mais informações sobre o uso desta macro.

`OnUpdateCmdUI`é chamado pelo framework quando a aplicação está ociosa. A janela do quadro a ser atualizada deve ser uma janela de criança, pelo menos indiretamente, de uma janela de quadro visível. `OnUpdateCmdUI`é um avançado superridable.

## <a name="ccontrolbarsetbarstyle"></a><a name="setbarstyle"></a>CControlBar::SetBarStyle

Chame esta função para definir os estilos **de CBRS_** desejados para a barra de controle.

```cpp
void SetBarStyle(DWORD dwStyle);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
Os estilos desejados para a barra de controle. Pode ser um ou mais dos seguintes:

- CBRS_ALIGN_TOP Permite que a barra de controle seja encaixada no topo da área do cliente de uma janela de quadro.

- CBRS_ALIGN_BOTTOM Permite que a barra de controle seja encaixada na parte inferior da área do cliente de uma janela de quadro.

- CBRS_ALIGN_LEFT Permite que a barra de controle seja encaixada no lado esquerdo da área do cliente de uma janela de quadro.

- CBRS_ALIGN_RIGHT Permite que a barra de controle seja encaixada no lado direito da área do cliente de uma janela de quadro.

- CBRS_ALIGN_ANY Permite que a barra de controle seja encaixada em qualquer lado da área do cliente de uma janela de quadro.

- CBRS_BORDER_TOP faz com que uma borda seja desenhada na borda superior da barra de controle quando ela seria visível.

- CBRS_BORDER_BOTTOM faz com que uma borda seja desenhada na borda inferior da barra de controle quando ela seria visível.

- CBRS_BORDER_LEFT faz com que uma borda seja desenhada na borda esquerda da barra de controle quando ela seria visível.

- CBRS_BORDER_RIGHT faz com que uma borda seja desenhada na borda direita da barra de controle quando ela seria visível.

- CBRS_FLOAT_MULTI Permite que várias barras de controle sejam flutuadas em uma única janela de miniquadro.

- CBRS_TOOLTIPS Faz com que as dicas da ferramenta sejam exibidas para a barra de controle.

- CBRS_FLYBY faz com que o texto da mensagem seja atualizado ao mesmo tempo que as dicas da ferramenta.

- CBRS_GRIPPER faz com que um gripper, `CReBar` semelhante ao usado em `CControlBar`bandas em um objeto, seja desenhado para qualquer classe derivada.

### <a name="remarks"></a>Comentários

Não afeta as **configurações de WS_** (estilo de janela).

## <a name="ccontrolbarsetborders"></a><a name="setborders"></a>CControlBar::SetBorders

Chame esta função para definir o tamanho das bordas da barra de controle.

```cpp
void SetBorders(
    int cxLeft = 0,
    int cyTop = 0,
    int cxRight = 0,
    int cyBottom = 0);

void SetBorders(LPCRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*cxLeft*<br/>
A largura (em pixels) da borda esquerda da barra de controle.

*cyTop*<br/>
A altura (em pixels) da borda superior da barra de controle.

*cxDireito*<br/>
A largura (em pixels) da borda direita da barra de controle.

*cyBottom*<br/>
A altura (em pixels) da borda inferior da barra de controle.

*Lprect*<br/>
Um ponteiro para um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) que contenha a largura atual (em pixels) de cada borda do objeto da barra de controle.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define as bordas superior e inferior da barra de controle para 5 pixels, e as bordas esquerda e direita para 2 pixels:

[!code-cpp[NVC_MFCControlLadenDialog#61](../../mfc/codesnippet/cpp/ccontrolbar-class_1.cpp)]

## <a name="ccontrolbarsetinplaceowner"></a><a name="setinplaceowner"></a>CControlBar::setInPlaceowner

Muda o dono de uma barra de controle no lugar.

```cpp
void SetInPlaceOwner(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Um ponteiro para um objeto `CWnd`.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Amostra de MFC CTRLBARS](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CToolBar](../../mfc/reference/ctoolbar-class.md)<br/>
[Classe CDialogBar](../../mfc/reference/cdialogbar-class.md)<br/>
[Classe CStatusBar](../../mfc/reference/cstatusbar-class.md)<br/>
[Classe Crebar](../../mfc/reference/crebar-class.md)
