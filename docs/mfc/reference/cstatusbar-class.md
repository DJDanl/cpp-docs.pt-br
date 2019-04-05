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
ms.openlocfilehash: d714159aa9fd52df682b1e5f3dbf3957bbef1b91
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "58777318"
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
|[CStatusBar::CStatusBar](#cstatusbar)|Constrói um objeto `CStatusBar`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CStatusBar::CommandToIndex](#commandtoindex)|Obtém o índice para uma ID de indicador especificado.|
|[CStatusBar::Create](#create)|Cria a barra de status, anexa-o para o `CStatusBar` de objeto e define a altura da fonte e a barra inicial.|
|[CStatusBar::CreateEx](#createex)|Cria uma `CStatusBar` objeto com estilos adicionais para o embedded `CStatusBarCtrl` objeto.|
|[CStatusBar::DrawItem](#drawitem)|Chamado quando um aspecto visual de um alterações de controle de barra de status de desenho do proprietário.|
|[CStatusBar::GetItemID](#getitemid)|Obtém a ID de indicador para um determinado índice.|
|[CStatusBar::GetItemRect](#getitemrect)|Obtém exibe o retângulo para um determinado índice.|
|[CStatusBar::GetPaneInfo](#getpaneinfo)|Obtém a ID do indicador, estilo e largura de um determinado índice.|
|[CStatusBar::GetPaneStyle](#getpanestyle)|Obtém o estilo de indicador para um determinado índice.|
|[CStatusBar::GetPaneText](#getpanetext)|Obtém o texto do indicador para um determinado índice.|
|[CStatusBar::GetStatusBarCtrl](#getstatusbarctrl)|Permite acesso direto ao controle comum subjacente.|
|[CStatusBar::SetIndicators](#setindicators)|Define as IDs do indicador.|
|[CStatusBar::SetPaneInfo](#setpaneinfo)|Define a ID do indicador, estilo e largura de um determinado índice.|
|[CStatusBar::SetPaneStyle](#setpanestyle)|Define o estilo do indicador para um determinado índice.|
|[CStatusBar::SetPaneText](#setpanetext)|Define o texto do indicador para um determinado índice.|

## <a name="remarks"></a>Comentários

Os painéis de saída normalmente são usados como linhas de mensagem e como os indicadores de status. Exemplos incluem as linhas de mensagem de Ajuda do menu que explicam resumidamente o comando de menu selecionado e os indicadores que mostram o status de SCROLL LOCK, NUM LOCK e outras chaves.

[CStatusBar::GetStatusBarCtrl](#getstatusbarctrl), uma função de membro novo a MFC 4.0, permite que você tirar proveito do suporte do controle do Windows comuns para personalização e funcionalidade adicional da barra de status. `CStatusBar` funções de membro lhe oferece a maioria da funcionalidade dos controles comuns do Windows; No entanto, quando você chama `GetStatusBarCtrl`, você pode dar as barras de status ainda mais as características de uma barra de status do Windows 95/98. Quando você chama `GetStatusBarCtrl`, ele retornará uma referência a um `CStatusBarCtrl` objeto. Ver [CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md) para obter mais informações sobre como criar barras de ferramentas usando controles comuns do Windows. Para obter mais informações sobre controles comuns, consulte [controles comuns](/windows/desktop/Controls/common-controls-intro) no SDK do Windows.

O framework armazena informações sobre o indicador em uma matriz com o indicador mais à esquerda na posição 0. Quando você cria uma barra de status, você pode usar uma matriz de IDs que o framework associa os indicadores correspondentes de cadeia de caracteres. Em seguida, você pode usar uma ID de cadeia de caracteres ou um índice para acessar um indicador.

Por padrão, o primeiro indicador é "elastic": ele ocupa o comprimento da barra de status não usado por outros painéis de indicador, para que outros painéis sejam alinhados à direita.

Para criar uma barra de status, siga estas etapas:

1. Construir o `CStatusBar` objeto.

1. Chame o [Create](#create) (ou [CreateEx](#createex)) função para criar a janela da barra de status e anexá-lo para o `CStatusBar` objeto.

1. Chame [SetIndicators](#setindicators) para associar uma ID de cadeia de caracteres de cada indicador.

Há três maneiras de atualizar o texto em um painel da barra de status:

1. Chame [CWnd::SetWindowText](../../mfc/reference/cwnd-class.md#setwindowtext) para atualizar o texto no painel somente 0.

1. Chame [CCmdUI::SetText](../../mfc/reference/ccmdui-class.md#settext) no manipulador ON_UPDATE_COMMAND_UI da barra de status.

1. Chame [SetPaneText](#setpanetext) para atualizar o texto para qualquer painel.

Chame [SetPaneStyle](#setpanestyle) para atualizar o estilo de um painel da barra de status.

Para obter mais informações sobre como usar `CStatusBar`, consulte o artigo [implementação da barra de Status no MFC](../../mfc/status-bar-implementation-in-mfc.md) e [31 de observação técnica: Barras de controle](../../mfc/tn031-control-bars.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CControlBar](../../mfc/reference/ccontrolbar-class.md)

`CStatusBar`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

##  <a name="commandtoindex"></a>  CStatusBar::CommandToIndex

Obtém o índice de indicador para um ID especificado.

```
int CommandToIndex(UINT nIDFind) const;
```

### <a name="parameters"></a>Parâmetros

*nIDFind*<br/>
ID de cadeia de caracteres do indicador cujo índice deve ser recuperado.

### <a name="return-value"></a>Valor de retorno

O índice do indicador se bem-sucedido; -1 se não for bem-sucedido.

### <a name="remarks"></a>Comentários

O índice do primeiro indicador é 0.

##  <a name="create"></a>  CStatusBar::Create

Cria uma barra (uma janela filho) de status e o associa com o `CStatusBar` objeto.

```
virtual BOOL Create(
    CWnd* pParentWnd,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,
    UINT nID = AFX_IDW_STATUS_BAR);
```

### <a name="parameters"></a>Parâmetros

*pParentWnd*<br/>
Ponteiro para o [CWnd](../../mfc/reference/cwnd-class.md) objeto cuja janela do Windows é o pai da barra de status.

*dwStyle*<br/>
O estilo de barra de status. Além do Windows padrão [estilos](../../mfc/reference/styles-used-by-mfc.md#window-styles), há suporte para esses estilos.

- Barra de controle de CBRS_TOP está na parte superior da janela do quadro.

- Barra de controle CBRS_BOTTOM é na parte inferior da janela do quadro.

- Barra de controle de CBRS_NOALIGN não é reposicionada quando o pai for redimensionado.

*nID*<br/>
ID da janela filho. da barra de ferramentas

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Também define a fonte inicial e define o status da altura da barra para um valor padrão.

##  <a name="createex"></a>  CStatusBar::CreateEx

Chame essa função para criar um (uma janela filho) da barra de status e associá-lo com o `CStatusBar` objeto.

```
virtual BOOL CreateEx(
    CWnd* pParentWnd,
    DWORD dwCtrlStyle = 0,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,
    UINT nID = AFX_IDW_STATUS_BAR);
```

### <a name="parameters"></a>Parâmetros

*pParentWnd*<br/>
Ponteiro para o [CWnd](../../mfc/reference/cwnd-class.md) objeto cuja janela do Windows é o pai da barra de status.

*dwCtrlStyle*<br/>
Estilos adicionais para a criação de inserido [CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md) objeto. O padrão especifica uma barra de status sem uma alça de dimensionamento ou dica de ferramenta dão suporte. Estilos de barra de status com suporte são:

- O controle de barra de status SBARS_SIZEGRIP inclui uma alça de dimensionamento na extremidade direita da barra de status. Uma alça de dimensionamento é semelhante a uma borda de dimensionamento; é uma área retangular que o usuário possa clicar e arrastar para redimensionar a janela pai.

- A barra de status SBT_TOOLTIPS dá suporte a dicas de ferramenta.

Para obter detalhes sobre esses estilos, consulte [configurações do CStatusBarCtrl](../../mfc/settings-for-the-cstatusbarctrl.md).

*dwStyle*<br/>
O estilo de barra de status. O padrão especifica que uma barra de status visível ser criado na parte inferior da janela do quadro. Aplicar qualquer combinação de estilos de controle listado da barra de status [estilos da janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) e [CDialogBar::Create](../../mfc/reference/cdialogbar-class.md#create). No entanto, esse parâmetro sempre deve incluir os estilos WS_CHILD e WS_VISIBLE.

*nID*<br/>
ID da janela filho da barra de status.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função também define a fonte inicial e define o status da altura da barra para um valor padrão.

Use `CreateEx`, em vez de [criar](#create), quando determinados estilos precisam estar presente durante a criação do controle de barra de status incorporada. Por exemplo, defina *dwCtrlStyle* para SBT_TOOLTIPS para exibir dicas de ferramenta em um objeto de barra de status.

##  <a name="cstatusbar"></a>  CStatusBar::CStatusBar

Constrói um `CStatusBar` objeto, cria uma fonte de barra de status padrão, se necessário e define as características da fonte para os valores padrão.

```
CStatusBar();
```

##  <a name="drawitem"></a>  CStatusBar::DrawItem

Essa função membro é chamada pelo framework quando um aspecto visual de um alterações de barra de status desenhado pelo proprietário.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>Parâmetros

*lpDrawItemStruct*<br/>
Um ponteiro para um [DRAWITEMSTRUCT](/windows/desktop/api/winuser/ns-winuser-tagdrawitemstruct) estrutura que contém informações sobre o tipo de desenho necessárias.

### <a name="remarks"></a>Comentários

O `itemAction` membro o `DRAWITEMSTRUCT` estrutura define a ação de desenho a ser executada. Substituir essa função de membro para implementar o desenho de um desenho proprietário `CStatusBar` objeto. O aplicativo deve restaurar todos os objetos de interface (GDI) do dispositivo gráficos selecionados para o contexto de exibição fornecido no *lpDrawItemStruct* antes do encerramento desta função de membro.

##  <a name="getitemid"></a>  CStatusBar::GetItemID

Retorna a ID do indicador especificado por *nIndex*.

```
UINT GetItemID(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do indicador cuja ID é a ser recuperado.

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
Índice do indicador cujas coordenadas do retângulo devem ser recuperadas.

*lpRect*<br/>
Aponta para um [RECT](/previous-versions/dd162897\(v=vs.85\)) estrutura ou um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que receberá as coordenadas do indicador especificado por *nIndex*.

### <a name="remarks"></a>Comentários

As coordenadas são em pixels, relativa ao canto superior esquerdo da barra de status.

##  <a name="getpaneinfo"></a>  CStatusBar::GetPaneInfo

Conjuntos *nID*, *nStyle*, e *cxWidth* para a ID, o estilo e a largura do painel do indicador no local especificado por *nIndex*.

```
void GetPaneInfo(
    int nIndex,
    UINT& nID,
    UINT& nStyle,
    int& cxWidth) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do painel cujas informações deve ser recuperado.

*nID*<br/>
Referência a um UINT que é definido como a ID do painel.

*nStyle*<br/>
Referência a um UINT que é definido como o estilo do painel.

*cxWidth*<br/>
Referência a um número inteiro que é definido como a largura do painel.

##  <a name="getpanestyle"></a>  CStatusBar::GetPaneStyle

Chame essa função de membro para recuperar o estilo do painel da barra de status.

```
UINT GetPaneStyle(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do painel cujo estilo deve ser recuperado.

### <a name="return-value"></a>Valor de retorno

O estilo do painel de barra de status especificado por *nIndex*.

### <a name="remarks"></a>Comentários

Estilo de um painel determina como o painel será exibido.

Para obter uma lista de estilos disponíveis para barras de status, consulte [criar](#create).

##  <a name="getpanetext"></a>  CStatusBar::GetPaneText

Chame essa função de membro para recuperar o texto que aparece em um painel da barra de status.

```
CString GetPaneText(int nIndex) const;  void GetPaneText(int nIndex, CString& rString) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do painel cujo texto deve ser recuperado.

*rString*<br/>
Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém o texto a ser recuperado.

### <a name="return-value"></a>Valor de retorno

Um `CString` objeto que contém o texto do painel.

### <a name="remarks"></a>Comentários

O segundo formulário desse membro de função preenche uma `CString` objeto com o texto de cadeia de caracteres.

##  <a name="getstatusbarctrl"></a>  CStatusBar::GetStatusBarCtrl

Essa função membro permite acesso direto ao controle comum subjacente.

```
CStatusBarCtrl& GetStatusBarCtrl() const;
```

### <a name="return-value"></a>Valor de retorno

Contém uma referência a um [CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md) objeto.

### <a name="remarks"></a>Comentários

Use `GetStatusBarCtrl` para tirar proveito da funcionalidade do controle comum de barra de status de Windows e para aproveitar o suporte [CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md) permite a personalização da barra de status. Por exemplo, usando o controle comum, você pode especificar um estilo que inclui uma alça de dimensionamento na barra de status, ou você pode especificar um estilo para que a barra de status aparecem na parte superior da área de cliente da janela pai.

Para obter mais informações sobre controles comuns, consulte [controles comuns](/windows/desktop/Controls/common-controls-intro) no SDK do Windows.

##  <a name="setindicators"></a>  CStatusBar::SetIndicators

Define a ID de cada nome do indicador para o valor especificado pelo elemento correspondente da matriz *lpIDArray*, carrega o recurso de cadeia de caracteres especificado por cada ID e define o texto do indicador para a cadeia de caracteres.

```
BOOL SetIndicators(
    const UINT* lpIDArray,
    int nIDCount);
```

### <a name="parameters"></a>Parâmetros

*lpIDArray*<br/>
Ponteiro para uma matriz de IDs.

*nIDCount*<br/>
Número de elementos na matriz apontada por *lpIDArray*.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

##  <a name="setpaneinfo"></a>  CStatusBar::SetPaneInfo

Define o painel do indicador especificado para uma nova ID, estilo e largura.

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
Nova ID para o painel do indicador.

*nStyle*<br/>
Novo estilo para o painel do indicador.

*cxWidth*<br/>
Nova largura para o painel do indicador.

### <a name="remarks"></a>Comentários

Há suporte para os seguintes estilos de indicador:

- Sem SBPS_NOBORDERS borda 3D em torno do painel.

- Inverter SBPS_POPOUT da borda, de modo que o texto "é exibido."

- SBPS_DISABLED não desenhar texto.

- Painel SBPS_STRETCH Stretch para preencher o espaço não utilizado. Somente um painel por barra de status pode ter esse estilo.

- Ampliação não SBPS_NORMAL, bordas ou pop-out.

##  <a name="setpanestyle"></a>  CStatusBar::SetPaneStyle

Chame essa função de membro para definir o estilo do painel da barra de status.

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

Estilo de um painel determina como o painel será exibido.

Para obter uma lista de estilos disponíveis para barras de status, consulte [SetPaneInfo](#setpaneinfo).

##  <a name="setpanetext"></a>  CStatusBar::SetPaneText

Chame essa função de membro para definir o texto do painel para a cadeia de caracteres apontada por *lpszNewText*.

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
Se for TRUE, o painel é invalidado depois que o texto é definido.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Depois de chamar `SetPaneText`, você deve adicionar um manipulador de atualização de interface do usuário para exibir o novo texto na barra de status.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#176](../../mfc/codesnippet/cpp/cstatusbar-class_1.cpp)]

[!code-cpp[NVC_MFCDocView#177](../../mfc/codesnippet/cpp/cstatusbar-class_2.cpp)]

[!code-cpp[NVC_MFCDocView#178](../../mfc/codesnippet/cpp/cstatusbar-class_3.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo MFC CTRLBARS](../../overview/visual-cpp-samples.md)<br/>
[DLGCBR32 de exemplo do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CStatusBarCtrl](../../mfc/reference/cstatusbarctrl-class.md)<br/>
[Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)
