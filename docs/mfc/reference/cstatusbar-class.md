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
ms.openlocfilehash: 48de31d95814ce5fc1fb015e69cf38d73337cb79
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502330"
---
# <a name="cstatusbar-class"></a>Classe CStatusBar

Uma barra de controle com uma linha de painéis de saída de texto ou "indicadores".

## <a name="syntax"></a>Sintaxe

```
class CStatusBar : public CControlBar
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CStatusBar::CStatusBar](#cstatusbar)|Constrói um objeto `CStatusBar`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CStatusBar::CommandToIndex](#commandtoindex)|Obtém o índice para uma determinada ID de indicador.|
|[CStatusBar:: criar](#create)|Cria a barra de status, anexa-a ao `CStatusBar` objeto e define a fonte inicial e a altura da barra.|
|[CStatusBar::CreateEx](#createex)|Cria um `CStatusBar` objeto com estilos adicionais para o objeto `CStatusBarCtrl` inserido.|
|[CStatusBar::DrawItem](#drawitem)|Chamado quando um aspecto visual de um controle de barra de status de desenho proprietário é alterado.|
|[CStatusBar::GetItemID](#getitemid)|Obtém a ID do indicador para um determinado índice.|
|[CStatusBar::GetItemRect](#getitemrect)|Obtém o retângulo de exibição para um determinado índice.|
|[CStatusBar::GetPaneInfo](#getpaneinfo)|Obtém a ID do indicador, o estilo e a largura de um determinado índice.|
|[CStatusBar::GetPaneStyle](#getpanestyle)|Obtém o estilo do indicador para um determinado índice.|
|[CStatusBar::GetPaneText](#getpanetext)|Obtém o texto do indicador para um determinado índice.|
|[CStatusBar::GetStatusBarCtrl](#getstatusbarctrl)|Permite acesso direto ao controle comum subjacente.|
|[CStatusBar:: setindicadores](#setindicators)|Define as IDs do indicador.|
|[CStatusBar::SetPaneInfo](#setpaneinfo)|Define a ID do indicador, o estilo e a largura de um determinado índice.|
|[CStatusBar::SetPaneStyle](#setpanestyle)|Define o estilo do indicador para um determinado índice.|
|[CStatusBar::SetPaneText](#setpanetext)|Define o texto do indicador para um determinado índice.|

## <a name="remarks"></a>Comentários

Os painéis de saída normalmente são usados como linhas de mensagem e como indicadores de status. Os exemplos incluem o menu de linhas de mensagem de ajuda que explicam brevemente o comando de menu selecionado e os indicadores que mostram o status do bloqueio de ROLAgem, NUM LOCK e outras chaves.

[CStatusBar:: GetStatusBarCtrl](#getstatusbarctrl), uma função membro nova no MFC 4,0, permite que você aproveite o suporte do controle comum do Windows para a personalização da barra de status e a funcionalidade adicional. `CStatusBar`as funções de membro oferecem a você a maior parte da funcionalidade dos controles comuns do Windows; no entanto, ao `GetStatusBarCtrl`chamar, você pode dar a suas barras de status ainda mais as características de uma barra de status do Windows 95/98. Quando você chamar `GetStatusBarCtrl`, retornará uma referência a um `CStatusBarCtrl` objeto. Consulte [CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md) para obter mais informações sobre como criar barras de ferramentas usando os controles comuns do Windows. Para obter mais informações gerais sobre controles comuns, consulte [controles comuns](/windows/win32/Controls/common-controls-intro) na SDK do Windows.

A estrutura armazena informações de indicador em uma matriz com o indicador mais à esquerda na posição 0. Ao criar uma barra de status, você usa uma matriz de IDs de cadeia de caracteres que a estrutura associa aos indicadores correspondentes. Você pode usar uma ID de cadeia de caracteres ou um índice para acessar um indicador.

Por padrão, o primeiro indicador é "elástico": ele ocupa o comprimento da barra de status não usado pelos outros painéis do indicador, para que os outros painéis estejam alinhados à direita.

Para criar uma barra de status, siga estas etapas:

1. Construa o `CStatusBar` objeto.

1. Chame a função [Create](#create) (ou [CreateEx](#createex)) para criar a janela de barra de status e anexá `CStatusBar` -la ao objeto.

1. Chame [setindicadores](#setindicators) para associar uma ID de cadeia de caracteres a cada indicador.

Há três maneiras de atualizar o texto em um painel da barra de status:

1. Chame [CWnd:: SetWindowText](../../mfc/reference/cwnd-class.md#setwindowtext) para atualizar o texto somente no painel 0.

1. Chame [CCmdUI:: SetText](../../mfc/reference/ccmdui-class.md#settext) no manipulador ON_UPDATE_COMMAND_UI da barra de status.

1. Chame [SetPaneText](#setpanetext) para atualizar o texto de qualquer painel.

Chame [setpainéis](#setpanestyle) para atualizar o estilo de um painel da barra de status.

Para obter mais informações sobre `CStatusBar`como usar o, consulte a implementação da barra de [status do artigo [no MFC](../../mfc/status-bar-implementation-in-mfc.md) e a observação técnica 31: Barras](../../mfc/tn031-control-bars.md)de controle.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CControlBar](../../mfc/reference/ccontrolbar-class.md)

`CStatusBar`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext. h

##  <a name="commandtoindex"></a>CStatusBar::CommandToIndex

Obtém o índice do indicador para uma determinada ID.

```
int CommandToIndex(UINT nIDFind) const;
```

### <a name="parameters"></a>Parâmetros

*nIDFind*<br/>
ID da cadeia de caracteres do indicador cujo índice deve ser recuperado.

### <a name="return-value"></a>Valor de retorno

O índice do indicador se for bem-sucedido; -1 se não for bem-sucedido.

### <a name="remarks"></a>Comentários

O índice do primeiro indicador é 0.

##  <a name="create"></a>  CStatusBar::Create

Cria uma barra de status (uma janela filho) e a `CStatusBar` associa ao objeto.

```
virtual BOOL Create(
    CWnd* pParentWnd,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,
    UINT nID = AFX_IDW_STATUS_BAR);
```

### <a name="parameters"></a>Parâmetros

*pParentWnd*<br/>
Ponteiro para o objeto [CWnd](../../mfc/reference/cwnd-class.md) cuja janela do Windows é o pai da barra de status.

*dwStyle*<br/>
O estilo da barra de status. Além dos [estilos](../../mfc/reference/styles-used-by-mfc.md#window-styles)padrão do Windows, há suporte para esses estilos.

- A barra de controle CBRS_TOP está na parte superior da janela do quadro.

- A barra de controle CBRS_BOTTOM está na parte inferior da janela do quadro.

- A barra de controle CBRS_NOALIGN não é reposicionada quando o pai é redimensionado.

*nID*<br/>
A ID da janela filho da barra de ferramentas.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Também define a fonte inicial e define a altura da barra de status como um valor padrão.

##  <a name="createex"></a>CStatusBar::CreateEx

Chame essa função para criar uma barra de status (uma janela filho) e associá-la `CStatusBar` ao objeto.

```
virtual BOOL CreateEx(
    CWnd* pParentWnd,
    DWORD dwCtrlStyle = 0,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,
    UINT nID = AFX_IDW_STATUS_BAR);
```

### <a name="parameters"></a>Parâmetros

*pParentWnd*<br/>
Ponteiro para o objeto [CWnd](../../mfc/reference/cwnd-class.md) cuja janela do Windows é o pai da barra de status.

*dwCtrlStyle*<br/>
Estilos adicionais para a criação do objeto [CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md) inserido. O padrão especifica uma barra de status sem um suporte de alça de dimensionamento ou dica de ferramenta. Os estilos de barra de status com suporte são:

- SBARS_SIZEGRIP o controle da barra de status inclui uma alça de dimensionamento na extremidade direita da barra de status. Uma alça de dimensionamento é semelhante a uma borda de dimensionamento; é uma área retangular que o usuário pode clicar e arrastar para redimensionar a janela pai.

- SBT_TOOLTIPS a barra de status dá suporte a dicas de ferramentas.

Para obter detalhes sobre esses estilos, consulte [configurações para o CStatusBarCtrl](../../mfc/settings-for-the-cstatusbarctrl.md).

*dwStyle*<br/>
O estilo da barra de status. O padrão especifica que uma barra de status visível seja criada na parte inferior da janela do quadro. Aplique qualquer combinação de estilos de controle da barra de status listada em [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) e [CDialogBar:: criar](../../mfc/reference/cdialogbar-class.md#create). No entanto, esse parâmetro sempre deve incluir os estilos WS_CHILD e WS_VISIBLE.

*nID*<br/>
A ID da janela filho da barra de status.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função também define a fonte inicial e define a altura da barra de status como um valor padrão.

Use `CreateEx`, em vez de [criar](#create), quando determinados estilos precisam estar presentes durante a criação do controle de barra de status inserido. Por exemplo, defina *dwCtrlStyle* como SBT_TOOLTIPS para exibir dicas de ferramentas em um objeto de barra de status.

##  <a name="cstatusbar"></a>  CStatusBar::CStatusBar

Constrói um `CStatusBar` objeto, cria uma fonte padrão de barra de status, se necessário, e define as características da fonte como valores padrão.

```
CStatusBar();
```

##  <a name="drawitem"></a>CStatusBar::D rawItem

Essa função de membro é chamada pela estrutura quando um aspecto visual de uma barra de status desenhada pelo proprietário é alterado.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpDrawItemStruct*<br/>
Um ponteiro para uma estrutura [DRAWITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-drawitemstruct) que contém informações sobre o tipo de desenho necessário.

### <a name="remarks"></a>Comentários

O `itemAction` membro`DRAWITEMSTRUCT` da estrutura define a ação de desenho a ser executada. Substitua essa função de membro para implementar o desenho de um objeto `CStatusBar` de desenho proprietário. O aplicativo deve restaurar todos os objetos da interface de dispositivo de gráficos (GDI) selecionados para o contexto de exibição fornecido em *lpDrawItemStruct* antes do término dessa função de membro.

##  <a name="getitemid"></a>  CStatusBar::GetItemID

Retorna a ID do indicador especificado por *nIndex*.

```
UINT GetItemID(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do indicador cuja ID deve ser recuperada.

### <a name="return-value"></a>Valor de retorno

A ID do indicador especificado por *nIndex*.

##  <a name="getitemrect"></a>  CStatusBar::GetItemRect

Copia as coordenadas do indicador especificado por *nIndex* na estrutura apontada por *lpRect*.

```
void GetItemRect(
    int nIndex,
    LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do indicador cujas coordenadas de retângulo devem ser recuperadas.

*lpRect*<br/>
Aponta para uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) ou um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) que receberá as coordenadas do indicador especificado por *nIndex*.

### <a name="remarks"></a>Comentários

As coordenadas são em pixels em relação ao canto superior esquerdo da barra de status.

##  <a name="getpaneinfo"></a>  CStatusBar::GetPaneInfo

Define *NID*, *nStyle*e *cxWidth* como a ID, o estilo e a largura do painel indicador no local especificado por *nIndex*.

```
void GetPaneInfo(
    int nIndex,
    UINT& nID,
    UINT& nStyle,
    int& cxWidth) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do painel cujas informações serão recuperadas.

*nID*<br/>
Referência a um UINT que é definido como a ID do painel.

*nStyle*<br/>
Referência a um UINT que é definido como o estilo do painel.

*cxWidth*<br/>
Referência a um inteiro que é definido como a largura do painel.

##  <a name="getpanestyle"></a>  CStatusBar::GetPaneStyle

Chame essa função de membro para recuperar o estilo de um painel da barra de status.

```
UINT GetPaneStyle(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do painel cujo estilo deve ser recuperado.

### <a name="return-value"></a>Valor de retorno

O estilo do painel da barra de status especificado por *nIndex*.

### <a name="remarks"></a>Comentários

O estilo de um painel determina como o painel é exibido.

Para obter uma lista de estilos disponíveis para barras de status, consulte [criar](#create).

##  <a name="getpanetext"></a>  CStatusBar::GetPaneText

Chame essa função de membro para recuperar o texto que aparece em um painel de barra de status.

```
CString GetPaneText(int nIndex) const;  void GetPaneText(int nIndex, CString& rString) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do painel cujo texto deve ser recuperado.

*rString*<br/>
Uma referência a um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém o texto a ser recuperado.

### <a name="return-value"></a>Valor de retorno

Um `CString` objeto que contém o texto do painel.

### <a name="remarks"></a>Comentários

A segunda forma dessa função de membro preenche um `CString` objeto com o texto da cadeia de caracteres.

##  <a name="getstatusbarctrl"></a>  CStatusBar::GetStatusBarCtrl

Essa função de membro permite o acesso direto ao controle comum subjacente.

```
CStatusBarCtrl& GetStatusBarCtrl() const;
```

### <a name="return-value"></a>Valor de retorno

Contém uma referência a um objeto [CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md) .

### <a name="remarks"></a>Comentários

Use `GetStatusBarCtrl` o para aproveitar a funcionalidade do controle comum de barra de status do Windows e para aproveitar o suporte que o [CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md) fornece para a personalização da barra de status. Por exemplo, usando o controle comum, você pode especificar um estilo que inclui uma alça de dimensionamento na barra de status ou pode especificar um estilo para que a barra de status apareça na parte superior da área do cliente da janela pai.

Para obter mais informações gerais sobre controles comuns, consulte [controles comuns](/windows/win32/Controls/common-controls-intro) na SDK do Windows.

##  <a name="setindicators"></a>CStatusBar:: setindicadores

Define a ID de cada indicador para o valor especificado pelo elemento correspondente da matriz *lpIDArray*, carrega o recurso de cadeia de caracteres especificado por cada ID e define o texto do indicador como a cadeia de caracteres.

```
BOOL SetIndicators(
    const UINT* lpIDArray,
    int nIDCount);
```

### <a name="parameters"></a>Parâmetros

*lpIDArray*<br/>
Ponteiro para uma matriz de IDs.

*nIDCount*<br/>
Número de elementos na matriz apontados por *lpIDArray*.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

##  <a name="setpaneinfo"></a>  CStatusBar::SetPaneInfo

Define o painel indicador especificado como uma nova ID, estilo e largura.

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
Nova ID para o painel indicador.

*nStyle*<br/>
Novo estilo para o painel indicador.

*cxWidth*<br/>
Nova largura para o painel indicador.

### <a name="remarks"></a>Comentários

Há suporte para os seguintes estilos de indicador:

- SBPS_NOBORDERS nenhuma borda 3D em torno do painel.

- SBPS_POPOUT a borda reversa para que o texto "se desprenda".

- SBPS_DISABLED não desenhar texto.

- SBPS_STRETCH painel de ampliação para preencher o espaço não utilizado. Somente um painel por barra de status pode ter esse estilo.

- SBPS_NORMAL sem ampliação, bordas ou pop-out.

##  <a name="setpanestyle"></a>  CStatusBar::SetPaneStyle

Chame essa função de membro para definir o estilo do painel de uma barra de status.

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

O estilo de um painel determina como o painel é exibido.

Para obter uma lista de estilos disponíveis para barras de status, consulte [SetPaneInfo](#setpaneinfo).

##  <a name="setpanetext"></a>  CStatusBar::SetPaneText

Chame essa função de membro para definir o texto do painel como a cadeia de caracteres apontada por *lpszNewText*.

```
BOOL SetPaneText(
    int nIndex,
    LPCTSTR lpszNewText,
    BOOL bUpdate = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do painel cujo texto deve ser definido.

*lpszNewText*<br/>
Ponteiro para o novo texto do painel.

*bUpdate*<br/>
Se for TRUE, o painel será invalidado depois que o texto for definido.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Depois de chamar `SetPaneText`, você deve adicionar um manipulador de atualização de interface do usuário para exibir o novo texto na barra de status.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#176](../../mfc/codesnippet/cpp/cstatusbar-class_1.cpp)]

[!code-cpp[NVC_MFCDocView#177](../../mfc/codesnippet/cpp/cstatusbar-class_2.cpp)]

[!code-cpp[NVC_MFCDocView#178](../../mfc/codesnippet/cpp/cstatusbar-class_3.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo de CTRLBARS do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de DLGCBR32 do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md)<br/>
[Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)
