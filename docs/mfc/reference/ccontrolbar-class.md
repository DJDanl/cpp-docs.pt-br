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
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58773236"
---
# <a name="ccontrolbar-class"></a>Classe CControlBar

A classe base para as classes da barra de controle [CStatusBar](../../mfc/reference/cstatusbar-class.md), [CToolBar](../../mfc/reference/ctoolbar-class.md), [CDialogBar](../../mfc/reference/cdialogbar-class.md), [CReBar](../../mfc/reference/crebar-class.md), e [ COleResizeBar](../../mfc/reference/coleresizebar-class.md).

## <a name="syntax"></a>Sintaxe

```
class CControlBar : public CWnd
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CControlBar::CControlBar](#ccontrolbar)|Constrói um objeto `CControlBar`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CControlBar::CalcDynamicLayout](#calcdynamiclayout)|Retorna o tamanho de uma barra de controle dinâmico como um [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.|
|[CControlBar::CalcFixedLayout](#calcfixedlayout)|Retorna o tamanho da barra de controle como um [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.|
|[CControlBar::CalcInsideRect](#calcinsiderect)|Retorna as dimensões atuais da área de barra de controle; incluindo as bordas.|
|[CControlBar::DoPaint](#dopaint)|Renderiza as bordas e a alça da barra de controle.|
|[CControlBar::DrawBorders](#drawborders)|Renderiza as bordas da barra de controle.|
|[CControlBar::DrawGripper](#drawgripper)|Renderiza a alça da barra de controle.|
|[CControlBar::EnableDocking](#enabledocking)|Permite que uma barra de controle ser encaixado ou flutuante.|
|[CControlBar::GetBarStyle](#getbarstyle)|Recupera as configurações de estilo da barra de controle.|
|[CControlBar::GetBorders](#getborders)|Recupera os valores de borda da barra de controle.|
|[CControlBar::GetCount](#getcount)|Retorna o número de elementos não HWND na barra de controle.|
|[CControlBar::GetDockingFrame](#getdockingframe)|Retorna um ponteiro para o quadro ao qual uma barra de controle está encaixada.|
|[CControlBar::IsFloating](#isfloating)|Retorna um valor diferente de zero se a barra de controle em questão for uma barra de controle de flutuante.|
|[CControlBar::OnUpdateCmdUI](#onupdatecmdui)|Chama os manipuladores de comando da interface do usuário.|
|[CControlBar::SetBarStyle](#setbarstyle)|Modifica as configurações de estilo da barra de controle.|
|[CControlBar::SetBorders](#setborders)|Define os valores de borda da barra de controle.|
|[CControlBar::SetInPlaceOwner](#setinplaceowner)|Altera o proprietário no local de uma barra de controle.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CControlBar::m_bAutoDelete](#m_bautodelete)|Se for diferente de zero, o `CControlBar` objeto é excluído quando a barra de controle do Windows é destruída.|
|[CControlBar::m_pInPlaceOwner](#m_pinplaceowner)|O proprietário do local da barra de controle.|

## <a name="remarks"></a>Comentários

Uma barra de controle é uma janela que geralmente é alinhada à esquerda ou à direita de uma janela do quadro. Ele pode conter itens filho que são controles baseados em HWND, que são janelas que geram e respondem às mensagens do Windows, ou itens não são baseados em HWND, que não sejam windows e são gerenciados pelo código do aplicativo ou código do framework. Caixas de listagem e controles de edição são exemplos de controles baseados em HWND. painéis da barra de status e botões de bitmap são exemplos de controles baseados em HWND.

Windows da barra de controle são geralmente janelas filho de uma janela do quadro pai e geralmente são irmãos para a exibição de cliente ou o cliente do MDI da janela do quadro. Um `CControlBar` objeto usa informações sobre o retângulo do cliente da janela pai para se posicionar. Em seguida, informa a janela pai sobre como o espaço restante não alocado na área de cliente da janela pai.

Para obter mais informações sobre `CControlBar`, consulte:

- [Barras de controle](../../mfc/control-bars.md)

- [Observação técnica 31: Barras de controle](../../mfc/tn031-control-bars.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CControlBar`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

##  <a name="calcdynamiclayout"></a>  CControlBar::CalcDynamicLayout

O framework chama essa função de membro para calcular as dimensões de uma barra de ferramentas dinâmica.

```
virtual CSize CalcDynamicLayout(
    int nLength,
    DWORD nMode);
```

### <a name="parameters"></a>Parâmetros

*nLength*<br/>
A dimensão solicitada da barra de controle, horizontal ou vertical, dependendo da *dwMode*.

*nMode*<br/>
Os seguintes sinalizadores predefinidos são usados para determinar a altura e largura da barra de controle dinâmico. Use o OR bit a bit (&#124;) operador para combinar os sinalizadores.

|Sinalizadores de modo de layout|O que significa|
|-----------------------|-------------------|
|LM_STRETCH|Indica se a barra de controle deve ser esticada para o tamanho do quadro. Defina se a barra não é uma barra de encaixe (não disponível para encaixar). Não definido quando a barra é encaixado ou flutuante (disponível para encaixar). Se definido, LM_STRETCH ignora *nLength* e retorna as dimensões com base no estado LM_HORZ. LM_STRETCH funciona da mesma forma que o *bStretch* parâmetro usado na [CalcFixedLayout](#calcfixedlayout); consulte essa função de membro para obter mais informações sobre a relação entre a ampliação e a orientação.|
|LM_HORZ|Indica que a barra é orientada horizontal ou verticalmente. Defina se a barra é orientada horizontalmente, e se ele é orientado verticalmente, ele não estiver definido. LM_HORZ funciona da mesma forma que o *bHorz* parâmetro usado na [CalcFixedLayout](#calcfixedlayout); consulte essa função de membro para obter mais informações sobre a relação entre a ampliação e a orientação.|
|LM_MRUWIDTH|Usado mais recentemente largura dinâmica. Ignora *nLength* parâmetro e usa o lembrados largura usados mais recentemente.|
|LM_HORZDOCK|Horizontal encaixado dimensões. Ignora *nLength* parâmetro e retorna o tamanho dinâmico com a maior largura.|
|LM_VERTDOCK|Vertical encaixado dimensões. Ignora *nLength* parâmetro e retorna o tamanho dinâmico com a maior altura.|
|LM_LENGTHY|Defina se *nLength* indica a altura (direção Y) em vez de largura.|
|LM_COMMIT|Redefine LM_MRUWIDTH para largura atual da barra de controle de flutuante.|

### <a name="return-value"></a>Valor de retorno

A barra de controle de tamanho, em pixels, de um [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.

### <a name="remarks"></a>Comentários

Substituir essa função de membro para fornecer seu próprio layout dinâmico em classes que derivam de `CControlBar`. Classes MFC derivadas de `CControlBar`, como [CToolbar](../../mfc/reference/ctoolbar-class.md), substituem essa função de membro e fornecer sua própria implementação.

##  <a name="calcfixedlayout"></a>  CControlBar::CalcFixedLayout

Chame essa função de membro para calcular o tamanho horizontal de uma barra de controle.

```
virtual CSize CalcFixedLayout(
    BOOL bStretch,
    BOOL bHorz);
```

### <a name="parameters"></a>Parâmetros

*bStretch*<br/>
Indica se a barra deve ser esticada para o tamanho do quadro. O *bStretch* parâmetro é diferente de zero quando a barra não é uma barra de encaixe (não disponível para encaixar) e é 0 quando está encaixado ou flutuante (disponível para encaixar).

*bHorz*<br/>
Indica que a barra é orientada horizontal ou verticalmente. O *bHorz* parâmetro é diferente de zero se a barra é orientada horizontalmente e será 0 se ele for orientado verticalmente.

### <a name="return-value"></a>Valor de retorno

A barra de controle de tamanho, em pixels, de um `CSize` objeto.

### <a name="remarks"></a>Comentários

Barras de controle, como barras de ferramentas podem ampliar horizontalmente ou verticalmente acomodar os botões contidos na barra de controle.

Se *bStretch* for TRUE, alongar a dimensão junto a orientação fornecida pelo *bHorz*. Em outras palavras, se *bHorz* é FALSE, a barra de controle é alongada verticalmente. Se *bStretch* é FALSE, nenhum stretch ocorre. A tabela a seguir mostra os estilos de barra de controle resultante e a possíveis permutações de *bStretch* e *bHorz*.

|bStretch|bHorz|Alongando|{1&gt;Orientação&lt;1}|O encaixe de encaixe/não|
|--------------|-----------|----------------|-----------------|--------------------------|
|TRUE|TRUE|Expansão horizontal|Orientado horizontalmente|Não encaixe|
|TRUE|FALSE|Alongando vertical|Orientados verticalmente|Não encaixe|
|FALSE|TRUE|Sem alongamento disponíveis|Orientado horizontalmente|Encaixe|
|FALSE|FALSE|Sem alongamento disponíveis|Orientados verticalmente|Encaixe|

##  <a name="calcinsiderect"></a>  CControlBar::CalcInsideRect

O framework chama essa função para calcular a área de cliente da barra de controle.

```
virtual void CalcInsideRect(
    CRect& rect,
    BOOL bHorz) const;
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
Contém as dimensões atuais da barra de controle; incluindo as bordas.

*bHorz*<br/>
Indica que a barra é orientada horizontal ou verticalmente. O *bHorz* parâmetro é diferente de zero se a barra é orientada horizontalmente e será 0 se ele for orientado verticalmente.

### <a name="remarks"></a>Comentários

Essa função é chamada antes que a barra de controle é pintada.

Substitua essa função para personalizar a renderização de bordas e barra de garra da barra de controle.

##  <a name="ccontrolbar"></a>  CControlBar::CControlBar

Constrói um objeto `CControlBar`.

```
CControlBar();
```

##  <a name="dopaint"></a>  CControlBar::DoPaint

Chamado pelo framework para renderizar as bordas e barra de garra da barra de controle.

```
virtual void DoPaint(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Aponta para o contexto de dispositivo a ser usado para renderizar as bordas e da alça da barra de controle.

### <a name="remarks"></a>Comentários

Substitua essa função para personalizar o comportamento de desenho da barra de controle.

Outro método de personalização é substituir a `DrawBorders` e `DrawGripper` funções e adicionar o código de desenho personalizado para as bordas e da garra. Como esses métodos são chamados pelo padrão `DoPaint` método, uma substituição do `DoPaint` não é necessária.

##  <a name="drawborders"></a>  CControlBar::DrawBorders

Chamado pelo framework para renderizar as bordas da barra de controle.

```
virtual void DrawBorders(
    CDC* pDC,
    CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Aponta para o contexto de dispositivo a ser usado para renderizar as bordas da barra de controle.

*rect*<br/>
Um `CRect` objeto que contém as dimensões da barra de controle.

### <a name="remarks"></a>Comentários

Substitua essa função para personalizar a aparência das bordas da barra de controle.

##  <a name="drawgripper"></a>  CControlBar::DrawGripper

Chamado pelo framework para renderizar a alça da barra de controle.

```
virtual void DrawGripper(
    CDC* pDC,
    const CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Aponta para o contexto de dispositivo a ser usado para renderizar a alça da barra de controle.

*rect*<br/>
Um `CRect` objeto que contém as dimensões da garra de barra de controle.

### <a name="remarks"></a>Comentários

Substitua essa função para personalizar a aparência de garra de barra de controle.

##  <a name="enabledocking"></a>  CControlBar::EnableDocking

Chame essa função para habilitar uma barra de controle encaixado.

```
void EnableDocking(DWORD dwDockStyle);
```

### <a name="parameters"></a>Parâmetros

*dwDockStyle*<br/>
Especifica se a barra de controle oferece suporte de encaixe e as laterais da sua janela pai ao qual a barra de controle pode ser encaixada, se houver suporte. Pode ser um ou mais destes procedimentos:

- CBRS_ALIGN_TOP permite o encaixe na parte superior da área de cliente.

- CBRS_ALIGN_BOTTOM permite o encaixe na parte inferior da área de cliente.

- CBRS_ALIGN_LEFT permite o encaixe no lado esquerdo da área de cliente.

- CBRS_ALIGN_RIGHT permite o encaixe no lado direito da área de cliente.

- CBRS_ALIGN_ANY permite o encaixe em qualquer lado da área de cliente.

- CBRS_FLOAT_MULTI permite que várias barras de controle ser flutuante em uma janela com minimoldura único.

Se for 0 (ou seja, indicando que nenhum sinalizador), a barra de controle não será encaixado.

### <a name="remarks"></a>Comentários

Os lados especificados devem corresponder a um dos lados habilitados para encaixar na janela de quadro de destino ou a barra de controle não pode ser encaixada para essa janela de quadro.

##  <a name="getbarstyle"></a>  CControlBar::GetBarStyle

Chame essa função para determinar quais **CBRS_** (estilos de barra de controle) configurações definidas atualmente para a barra de controle.

```
DWORD GetBarStyle();
```

### <a name="return-value"></a>Valor de retorno

O atual **CBRS_** configurações (estilos de barra de controle) para a barra de controle. Ver [CControlBar::SetBarStyle](#setbarstyle) para obter uma lista de estilos disponíveis.

### <a name="remarks"></a>Comentários

Não manipula **WS _** estilos (estilo da janela).

##  <a name="getborders"></a>  CControlBar::GetBorders

Retorna os valores atuais de borda para a barra de controle.

```
CRect GetBorders() const;
```

### <a name="return-value"></a>Valor de retorno

Um `CRect` objeto que contém a largura atual (em pixels) de cada lado do objeto de barra de controle. Por exemplo, o valor da *esquerdo* membro, dos [CRect](../../atl-mfc-shared/reference/crect-class.md) de objeto, é a largura da borda esquerda.

##  <a name="getcount"></a>  CControlBar::GetCount

Retorna o número de itens não HWND sobre o `CControlBar` objeto.

```
int GetCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número de itens não HWND no `CControlBar` objeto. Essa função retorna 0 para um [CDialogBar](../../mfc/reference/cdialogbar-class.md) objeto.

### <a name="remarks"></a>Comentários

O tipo do item depende o objeto derivado: painéis para [CStatusBar](../../mfc/reference/cstatusbar-class.md) objetos e botões e separadores para [CToolBar](../../mfc/reference/ctoolbar-class.md) objetos.

##  <a name="getdockingframe"></a>  CControlBar::GetDockingFrame

Chame essa função de membro para obter um ponteiro para a janela do quadro atual ao qual sua barra de controle está encaixada.

```
CFrameWnd* GetDockingFrame() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para uma janela do quadro se bem-sucedido; Caso contrário, nulo.

Se a barra de controle não está encaixada em uma janela do quadro (ou seja, se a barra de controle é flutuante), essa função retornará um ponteiro para seu pai [CMiniFrameWnd](../../mfc/reference/cminiframewnd-class.md).

### <a name="remarks"></a>Comentários

Para obter mais informações sobre barras de controle encaixáveis, consulte [CControlBar::EnableDocking](#enabledocking) e [CFrameWnd::DockControlBar](../../mfc/reference/cframewnd-class.md#dockcontrolbar).

##  <a name="isfloating"></a>  CControlBar::IsFloating

Chame essa função de membro para determinar se a barra de controle está encaixado ou flutuante.

```
BOOL IsFloating() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a barra de controle é flutuante; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Para alterar o estado de uma barra de controle de ancorada para flutuante, chame [CFrameWnd::FloatControlBar](../../mfc/reference/cframewnd-class.md#floatcontrolbar).

##  <a name="m_bautodelete"></a>  CControlBar::m_bAutoDelete

Se for diferente de zero, o `CControlBar` objeto é excluído quando a barra de controle do Windows é destruída.

```
BOOL m_bAutoDelete;
```

### <a name="remarks"></a>Comentários

*m_bAutoDelete* é uma variável pública do tipo BOOL.

Geralmente, um objeto de barra de controle é inserido em um objeto de janela com moldura. Nesse caso, *m_bAutoDelete* é 0, porque o objeto inserido de barra de controle é destruído quando a janela do quadro é destruída.

Definir essa variável como um valor diferente de zero, se você alocar uma `CControlBar` objeto no heap e você não planeja chamar **excluir**.

##  <a name="m_pinplaceowner"></a>  CControlBar::m_pInPlaceOwner

O proprietário do local da barra de controle.

```
CWnd* m_pInPlaceOwner;
```

##  <a name="onupdatecmdui"></a>  CControlBar::OnUpdateCmdUI

Essa função membro é chamada pelo framework para atualizar o status da barra de ferramentas ou status.

```
virtual void OnUpdateCmdUI(
    CFrameWnd* pTarget,
    BOOL bDisableIfNoHndler) = 0;
```

### <a name="parameters"></a>Parâmetros

*pTarget*<br/>
Aponta para a janela do quadro principal do aplicativo. Esse ponteiro é usado para roteamento de mensagens de atualização.

*bDisableIfNoHndler*<br/>
Sinalizador que indica se um controle que não tem nenhum manipulador de atualização deve ser exibido automaticamente como desabilitado.

### <a name="remarks"></a>Comentários

Para atualizar um botão individual ou painel, use a macro ON_UPDATE_COMMAND_UI no seu mapa de mensagem para definir um manipulador de atualização adequadamente. Ver [ON_UPDATE_COMMAND_UI](message-map-macros-mfc.md#on_update_command_ui) para obter mais informações sobre como usar essa macro.

`OnUpdateCmdUI` é chamado pelo framework quando o aplicativo está ocioso. A janela do quadro a ser atualizado deve ser uma janela filho, pelo menos indiretamente, de uma janela de quadro visível. `OnUpdateCmdUI` é um avançado substituível.

##  <a name="setbarstyle"></a>  CControlBar::SetBarStyle

Chame essa função para definir o estado desejado **CBRS_** estilos para a barra de controle.

```
void SetBarStyle(DWORD dwStyle);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Os estilos desejados para a barra de controle. Pode ser um ou mais destes procedimentos:

- CBRS_ALIGN_TOP permite que a barra de controle encaixado na parte superior da área de cliente de uma janela do quadro.

- CBRS_ALIGN_BOTTOM permite que a barra de controle encaixado na parte inferior da área de cliente de uma janela do quadro.

- CBRS_ALIGN_LEFT permite que a barra de controle encaixado à esquerda da área de cliente de uma janela de quadro.

- CBRS_ALIGN_RIGHT permite que a barra de controle encaixado à direita da área de cliente de uma janela de quadro.

- CBRS_ALIGN_ANY permite que a barra de controle para ser encaixado em qualquer lado da área de cliente de uma janela do quadro.

- CBRS_BORDER_TOP faz com que uma borda a ser desenhada na borda superior do controle da barra quando seria visível.

- CBRS_BORDER_BOTTOM faz com que uma borda a ser desenhada na borda inferior do controle da barra quando seria visível.

- CBRS_BORDER_LEFT faz com que uma borda a ser desenhada na borda esquerda do controle da barra quando seria visível.

- CBRS_BORDER_RIGHT faz com que uma borda a ser desenhada na borda direita do controle da barra quando seria visível.

- CBRS_FLOAT_MULTI permite que várias barras de controle ser flutuante em uma janela com minimoldura único.

- CBRS_TOOLTIPS faz com que a dicas de ferramenta a ser exibido para a barra de controle.

- Texto da mensagem CBRS_FLYBY faz com que sejam atualizados ao mesmo tempo em que as dicas de ferramenta.

- CBRS_GRIPPER faz com que uma garra, semelhante àquela usada em faixas em um `CReBar` objeto a ser desenhado de qualquer `CControlBar`-classe derivada.

### <a name="remarks"></a>Comentários

Não afeta a **WS _** configurações (estilo da janela).

##  <a name="setborders"></a>  CControlBar::SetBorders

Chame essa função para definir o tamanho das bordas da barra de controle.

```
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

*cxRight*<br/>
A largura (em pixels) da borda de à direita da barra de controle.

*cyBottom*<br/>
A altura (em pixels) da borda de parte inferior da barra de controle.

*lpRect*<br/>
Um ponteiro para um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que contém a largura atual (em pixels) de cada borda do objeto de barra de controle.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define as bordas superior e inferior da barra de controle para 5 pixels e as bordas esquerdas e direita para 2 pixels:

[!code-cpp[NVC_MFCControlLadenDialog#61](../../mfc/codesnippet/cpp/ccontrolbar-class_1.cpp)]

##  <a name="setinplaceowner"></a>  CControlBar::SetInPlaceOwner

Altera o proprietário no local de uma barra de controle.

```
void SetInPlaceOwner(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Um ponteiro para um `CWnd` objeto.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Exemplo MFC CTRLBARS](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CToolBar](../../mfc/reference/ctoolbar-class.md)<br/>
[Classe CDialogBar](../../mfc/reference/cdialogbar-class.md)<br/>
[Classe CStatusBar](../../mfc/reference/cstatusbar-class.md)<br/>
[Classe CReBar](../../mfc/reference/crebar-class.md)
