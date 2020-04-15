---
title: Classe CStatusBar
ms.date: 11/04/2016
f1_keywords:
- CStatusBar
- AFXEXT/CStatusBar
- AFXEXT/CStatusBar::CStatusBar
- AFXEXT/CStatusBar::CommandToIndex
- AFXEXT/CStatusBar::Create
- AFXEXT/CStatusBar::CreateEx
- AFXEXT/CStatusBar::DrawItem
- AFXEXT/CStatusBar::GetItemID
- AFXEXT/CStatusBar::GetItemRect
- AFXEXT/CStatusBar::GetPaneInfo
- AFXEXT/CStatusBar::GetPaneStyle
- AFXEXT/CStatusBar::GetPaneText
- AFXEXT/CStatusBar::GetStatusBarCtrl
- AFXEXT/CStatusBar::SetIndicators
- AFXEXT/CStatusBar::SetPaneInfo
- AFXEXT/CStatusBar::SetPaneStyle
- AFXEXT/CStatusBar::SetPaneText
helpviewer_keywords:
- CStatusBar [MFC], CStatusBar
- CStatusBar [MFC], CommandToIndex
- CStatusBar [MFC], Create
- CStatusBar [MFC], CreateEx
- CStatusBar [MFC], DrawItem
- CStatusBar [MFC], GetItemID
- CStatusBar [MFC], GetItemRect
- CStatusBar [MFC], GetPaneInfo
- CStatusBar [MFC], GetPaneStyle
- CStatusBar [MFC], GetPaneText
- CStatusBar [MFC], GetStatusBarCtrl
- CStatusBar [MFC], SetIndicators
- CStatusBar [MFC], SetPaneInfo
- CStatusBar [MFC], SetPaneStyle
- CStatusBar [MFC], SetPaneText
ms.assetid: a3bde3db-e71c-4881-a3ca-1d5481c345ba
ms.openlocfilehash: 0549ee10faa15b80b18a0bee2f115425002e1479
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376254"
---
# <a name="cstatusbar-class"></a>Classe CStatusBar

Uma barra de controle com uma linha de painéis de saída de texto, ou "indicadores".

## <a name="syntax"></a>Sintaxe

```
class CStatusBar : public CControlBar
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Barra de cstatus::CStatusBar](#cstatusbar)|Constrói um objeto `CStatusBar`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CStatusbar::CommandToIndex](#commandtoindex)|Obtém índice para um dado indicador ID.|
|[CStatusBar::Criar](#create)|Cria a barra de status, `CStatusBar` anexa-a ao objeto e define a fonte inicial e a altura da barra.|
|[CStatusbar::CreateEx](#createex)|Cria `CStatusBar` um objeto com estilos `CStatusBarCtrl` adicionais para o objeto incorporado.|
|[CStatusBar::DrawItem](#drawitem)|Chamado quando um aspecto visual de uma barra de status de proprietário-draw muda.|
|[CStatusBar::GetItemID](#getitemid)|Obtém iD indicador para um determinado índice.|
|[CStatusBar::GetItemRect](#getitemrect)|Obtém retângulo de exibição para um determinado índice.|
|[CStatusBar::GetPaneInfo](#getpaneinfo)|Obtém ID indicador, estilo e largura para um determinado índice.|
|[CStatusBar::GetPaneStyle](#getpanestyle)|Obtém estilo indicador para um determinado índice.|
|[CStatusBar::GetPaneText](#getpanetext)|Obtém texto indicador para um determinado índice.|
|[CStatusBar::GetStatusBarCtrl](#getstatusbarctrl)|Permite acesso direto ao controle comum subjacente.|
|[CStatusBar::SetIndicators](#setindicators)|Define iDs de indicador.|
|[CStatusBar::SetPaneInfo](#setpaneinfo)|Define iD de indicador, estilo e largura para um determinado índice.|
|[CStatusBar::SetPaneStyle](#setpanestyle)|Define o estilo do indicador para um determinado índice.|
|[CStatusBar::SetPaneText](#setpanetext)|Define o texto indicador para um determinado índice.|

## <a name="remarks"></a>Comentários

Os painéis de saída são comumente usados como linhas de mensagem e como indicadores de status. Exemplos incluem as linhas de mensagens de ajuda do menu que explicam brevemente o comando de menu selecionado e os indicadores que mostram o status do SCROLL LOCK, NUM LOCK e outras teclas.

[CStatusBar::GetStatusBarCtrl](#getstatusbarctrl), uma função de membro nova no MFC 4.0, permite que você aproveite o suporte do controle comum do Windows para personalização da barra de status e funcionalidade adicional. `CStatusBar`as funções de membro dão a maior parte da funcionalidade dos controles comuns do Windows; no entanto, `GetStatusBarCtrl`quando você liga, você pode dar às suas barras de status ainda mais as características de uma barra de status do Windows 95/98. Quando você `GetStatusBarCtrl`ligar, ele retornará `CStatusBarCtrl` uma referência a um objeto. Consulte [CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md) para obter mais informações sobre como projetar barras de ferramentas usando controles comuns do Windows. Para obter informações mais gerais sobre controles comuns, consulte [Controles Comuns](/windows/win32/Controls/common-controls-intro) no SDK do Windows.

O framework armazena as informações do indicador em uma matriz com o indicador mais à esquerda na posição 0. Quando você cria uma barra de status, você usa uma matriz de IDs de seqüência que a estrutura associa com os indicadores correspondentes. Em seguida, você pode usar um ID de seqüência ou um índice para acessar um indicador.

Por padrão, o primeiro indicador é "elástico": ele ocupa o comprimento da barra de status não utilizado pelos outros painéis indicadores, de modo que os outros painéis estejam alinhados à direita.

Para criar uma barra de status, siga estas etapas:

1. Construa `CStatusBar` o objeto.

1. Chame a função [Criar](#create) (ou [CreateEx)](#createex)para criar a `CStatusBar` janela da barra de status e anexá-la ao objeto.

1. [Indicadores de configuração de chamadas](#setindicators) para associar um ID de seqüência com cada indicador.

Existem três maneiras de atualizar o texto em um painel de barra de status:

1. Ligue [para CWnd::SetWindowText](../../mfc/reference/cwnd-class.md#setwindowtext) para atualizar o texto apenas no painel 0.

1. Ligue [para CCmdUI::SetText](../../mfc/reference/ccmdui-class.md#settext) no manipulador de ON_UPDATE_COMMAND_UI da barra de status.

1. Ligue para [SetPaneText](#setpanetext) para atualizar o texto para qualquer painel.

Ligue para [setPaneStyle](#setpanestyle) para atualizar o estilo de um painel de barra de status.

Para obter mais `CStatusBar`informações sobre o uso, consulte o artigo [Implementação da barra de status em MFC](../../mfc/status-bar-implementation-in-mfc.md) e [Nota Técnica 31 : Barras de Controle](../../mfc/tn031-control-bars.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Ccontrolbar](../../mfc/reference/ccontrolbar-class.md)

`CStatusBar`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

## <a name="cstatusbarcommandtoindex"></a><a name="commandtoindex"></a>CStatusbar::CommandToIndex

Obtém o índice indicador de uma determinada ID.

```
int CommandToIndex(UINT nIDFind) const;
```

### <a name="parameters"></a>Parâmetros

*nIDFind*<br/>
ID de corda do indicador cujo índice deve ser recuperado.

### <a name="return-value"></a>Valor retornado

O índice do indicador se for bem sucedido; -1 se não for bem sucedido.

### <a name="remarks"></a>Comentários

O índice do primeiro indicador é 0.

## <a name="cstatusbarcreate"></a><a name="create"></a>CStatusBar::Criar

Cria uma barra de status (uma janela `CStatusBar` filho) e associa-a ao objeto.

```
virtual BOOL Create(
    CWnd* pParentWnd,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,
    UINT nID = AFX_IDW_STATUS_BAR);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
Ponteiro para o objeto [CWnd](../../mfc/reference/cwnd-class.md) cuja janela do Windows é o pai da barra de status.

*Dwstyle*<br/>
O estilo status-bar. Além dos [estilos](../../mfc/reference/styles-used-by-mfc.md#window-styles)padrão do Windows, esses estilos são suportados.

- CBRS_TOP barra de controle está na parte superior da janela da moldura.

- CBRS_BOTTOM barra de controle está na parte inferior da janela da moldura.

- CBRS_NOALIGN barra de controle não é reposicionada quando o pai é redimensionado.

*nID*<br/>
A caixa de ferramentas da janela infantil.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Também define a fonte inicial e define a altura da barra de status como um valor padrão.

## <a name="cstatusbarcreateex"></a><a name="createex"></a>CStatusbar::CreateEx

Chame essa função para criar uma barra de status `CStatusBar` (uma janela filho) e associá-la com o objeto.

```
virtual BOOL CreateEx(
    CWnd* pParentWnd,
    DWORD dwCtrlStyle = 0,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,
    UINT nID = AFX_IDW_STATUS_BAR);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
Ponteiro para o objeto [CWnd](../../mfc/reference/cwnd-class.md) cuja janela do Windows é o pai da barra de status.

*dwCtrlStyle*<br/>
Estilos adicionais para a criação do objeto [CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md) incorporado. O padrão especifica uma barra de status sem um suporte de controle de controle de dimensionamento ou ponta de ferramenta. Os estilos de barra de status suportados são:

- SBARS_SIZEGRIP O controle da barra de status inclui uma aderência de tamanho na extremidade direita da barra de status. Um aperto de tamanho é semelhante a uma borda de tamanho; é uma área retangular que o usuário pode clicar e arrastar para redimensionar a janela pai.

- SBT_TOOLTIPS A barra de status suporta dicas de ferramentas.

Para obter detalhes sobre esses estilos, consulte [Configurações para o CStatusBarCtrl](../../mfc/settings-for-the-cstatusbarctrl.md).

*Dwstyle*<br/>
O estilo da barra de status. O padrão especifica que uma barra de status visível seja criada na parte inferior da janela do quadro. Aplique qualquer combinação de estilos de controle de barra de status listados em [Estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) e [CDialogBar::Criar](../../mfc/reference/cdialogbar-class.md#create). No entanto, este parâmetro deve sempre incluir os estilos WS_CHILD e WS_VISIBLE.

*nID*<br/>
A barra de status da janela infantil.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função também define a fonte inicial e define a altura da barra de status como um valor padrão.

Use `CreateEx`, em vez de [Criar,](#create)quando certos estilos precisarem estar presentes durante a criação do controle da barra de status incorporada. Por exemplo, defina *dwCtrlStyle* para SBT_TOOLTIPS para exibir dicas de ferramentas em um objeto de barra de status.

## <a name="cstatusbarcstatusbar"></a><a name="cstatusbar"></a>Barra de cstatus::CStatusBar

Constrói um `CStatusBar` objeto, cria uma fonte de barra de status padrão, se necessário, e define as características da fonte como valores padrão.

```
CStatusBar();
```

## <a name="cstatusbardrawitem"></a><a name="drawitem"></a>CStatusBar::DrawItem

Essa função de membro é chamada pela estrutura quando um aspecto visual de uma barra de status desenhada pelo proprietário muda.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>Parâmetros

*Lpdrawitemstruct*<br/>
Um ponteiro para uma estrutura [DRAWITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-drawitemstruct) que contém informações sobre o tipo de desenho necessário.

### <a name="remarks"></a>Comentários

O `itemAction` membro `DRAWITEMSTRUCT` da estrutura define a ação de desenho a ser realizada. Substituir esta função de membro para implementar `CStatusBar` o desenho para um objeto de desenho do proprietário. O aplicativo deve restaurar todos os objetos GDI (Graphics Device Interface, interface de dispositivo gráfico) selecionados para o contexto de exibição fornecido no *lpDrawItemStruct* antes do término desta função de membro.

## <a name="cstatusbargetitemid"></a><a name="getitemid"></a>CStatusBar::GetItemID

Retorna o ID do indicador especificado por *nIndex*.

```
UINT GetItemID(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do indicador cujo ID deve ser recuperado.

### <a name="return-value"></a>Valor retornado

O ID do indicador especificado por *nIndex*.

## <a name="cstatusbargetitemrect"></a><a name="getitemrect"></a>CStatusBar::GetItemRect

Copia as coordenadas do indicador especificadas por *nIndex* na estrutura apontada por *lpRect*.

```
void GetItemRect(
    int nIndex,
    LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do indicador cujas coordenadas retângulo devem ser recuperadas.

*Lprect*<br/>
Aponta para uma estrutura [RECT](/previous-versions/dd162897\(v=vs.85\)) ou um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) que receberá as coordenadas do indicador especificado por *nIndex*.

### <a name="remarks"></a>Comentários

As coordenadas estão em pixels relativos ao canto superior esquerdo da barra de status.

## <a name="cstatusbargetpaneinfo"></a><a name="getpaneinfo"></a>CStatusBar::GetPaneInfo

Define *nID,* *nStyle*e *cxWidth* para o ID, estilo e largura do painel indicador no local especificado por *nIndex*.

```
void GetPaneInfo(
    int nIndex,
    UINT& nID,
    UINT& nStyle,
    int& cxWidth) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do painel cujas informações devem ser recuperadas.

*nID*<br/>
Referência a um UINT definido como id do painel.

*nStyle*<br/>
Referência a um UINT que é definido para o estilo do painel.

*cxWidth*<br/>
Referência a um inteiro definido para a largura do painel.

## <a name="cstatusbargetpanestyle"></a><a name="getpanestyle"></a>CStatusBar::GetPaneStyle

Ligue para esta função de membro para recuperar o estilo do painel de uma barra de status.

```
UINT GetPaneStyle(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do painel cujo estilo deve ser recuperado.

### <a name="return-value"></a>Valor retornado

O estilo do painel de barra de status especificado por *nIndex*.

### <a name="remarks"></a>Comentários

O estilo de um painel determina como o painel aparece.

Para obter uma lista de estilos disponíveis para barras de status, consulte [Criar](#create).

## <a name="cstatusbargetpanetext"></a><a name="getpanetext"></a>CStatusBar::GetPaneText

Ligue para esta função de membro para recuperar o texto que aparece em um painel de barra de status.

```
CString GetPaneText(int nIndex) const;  void GetPaneText(int nIndex, CString& rString) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do painel cujo texto deve ser recuperado.

*rString*<br/>
Uma referência a um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém o texto a ser recuperado.

### <a name="return-value"></a>Valor retornado

Um `CString` objeto contendo o texto do painel.

### <a name="remarks"></a>Comentários

A segunda forma desta função `CString` membro preenche um objeto com o texto da seqüência.

## <a name="cstatusbargetstatusbarctrl"></a><a name="getstatusbarctrl"></a>CStatusBar::GetStatusBarCtrl

Esta função de membro permite acesso direto ao controle comum subjacente.

```
CStatusBarCtrl& GetStatusBarCtrl() const;
```

### <a name="return-value"></a>Valor retornado

Contém uma referência a um objeto [CStatusBarCtrl.](../../mfc/reference/cstatusbarctrl-class.md)

### <a name="remarks"></a>Comentários

Use `GetStatusBarCtrl` para aproveitar a funcionalidade do controle comum da barra de status do Windows e para aproveitar o suporte que o [CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md) fornece para personalização da barra de status. Por exemplo, usando o controle comum, você pode especificar um estilo que inclui um controle de dimensionamento na barra de status ou você pode especificar um estilo para que a barra de status apareça na parte superior da área cliente da janela pai.

Para obter informações mais gerais sobre controles comuns, consulte [Controles comuns](/windows/win32/Controls/common-controls-intro) no SDK do Windows.

## <a name="cstatusbarsetindicators"></a><a name="setindicators"></a>CStatusBar::SetIndicators

Define o ID de cada indicador para o valor especificado pelo elemento correspondente do array *lpIDArray,* carrega o recurso de string especificado por cada ID e define o texto do indicador para a string.

```
BOOL SetIndicators(
    const UINT* lpIDArray,
    int nIDCount);
```

### <a name="parameters"></a>Parâmetros

*Lpidarray*<br/>
Ponteiro para uma matriz de IDs.

*nIDCount*<br/>
Número de elementos na matriz apontado sustado por *lpIDArray*.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

## <a name="cstatusbarsetpaneinfo"></a><a name="setpaneinfo"></a>CStatusBar::SetPaneInfo

Define o painel indicador especificado como um novo ID, estilo e largura.

```
void SetPaneInfo(
    int nIndex,
    UINT nID,
    UINT nStyle,
    int cxWidth);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do painel indicador cujo estilo deve ser definido.

*nID*<br/>
Novo ID para o painel indicador.

*nStyle*<br/>
Novo estilo para o painel indicador.

*cxWidth*<br/>
Nova largura para o painel indicador.

### <a name="remarks"></a>Comentários

Os seguintes estilos indicadores são suportados:

- SBPS_NOBORDERS fronteira 3D ao redor do painel.

- SBPS_POPOUT fronteira inversa para que o texto "saia".

- SBPS_DISABLED Não desenhe texto.

- SBPS_STRETCH painel de estiramento para preencher espaço não utilizado. Apenas um painel por barra de status pode ter esse estilo.

- SBPS_NORMAL Sem elasticidade, fronteiras ou pop-out.

## <a name="cstatusbarsetpanestyle"></a><a name="setpanestyle"></a>CStatusBar::SetPaneStyle

Chame esta função de membro para definir o estilo do painel de uma barra de status.

```
void SetPaneStyle(
    int nIndex,
    UINT nStyle);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do painel cujo estilo deve ser definido.

*nStyle*<br/>
Estilo do painel cujo estilo deve ser definido.

### <a name="remarks"></a>Comentários

O estilo de um painel determina como o painel aparece.

Para obter uma lista de estilos disponíveis para barras de status, consulte [SetPaneInfo](#setpaneinfo).

## <a name="cstatusbarsetpanetext"></a><a name="setpanetext"></a>CStatusBar::SetPaneText

Chame esta função de membro para definir o texto do painel para a seqüência apontada por *lpszNewText*.

```
BOOL SetPaneText(
    int nIndex,
    LPCTSTR lpszNewText,
    BOOL bUpdate = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do painel cujo texto deve ser definido.

*Lpsznewtext*<br/>
Ponteiro para o novo texto do painel.

*bAtualização*<br/>
Se TRUE, o painel é invalidado após a configuração do texto.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Depois de `SetPaneText`ligar, você deve adicionar um manipulador de atualização de iu para exibir o novo texto na barra de status.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#176](../../mfc/codesnippet/cpp/cstatusbar-class_1.cpp)]

[!code-cpp[NVC_MFCDocView#177](../../mfc/codesnippet/cpp/cstatusbar-class_2.cpp)]

[!code-cpp[NVC_MFCDocView#178](../../mfc/codesnippet/cpp/cstatusbar-class_3.cpp)]

## <a name="see-also"></a>Confira também

[Amostra de MFC CTRLBARS](../../overview/visual-cpp-samples.md)<br/>
[Amostra de MFC DLGCBR32](../../overview/visual-cpp-samples.md)<br/>
[Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md)<br/>
[Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)
