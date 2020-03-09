---
title: Classe CToolBar
ms.date: 11/04/2016
f1_keywords:
- CToolBar
- AFXEXT/CToolBar
- AFXEXT/CToolBar::CToolBar
- AFXEXT/CToolBar::CommandToIndex
- AFXEXT/CToolBar::Create
- AFXEXT/CToolBar::CreateEx
- AFXEXT/CToolBar::GetButtonInfo
- AFXEXT/CToolBar::GetButtonStyle
- AFXEXT/CToolBar::GetButtonText
- AFXEXT/CToolBar::GetItemID
- AFXEXT/CToolBar::GetItemRect
- AFXEXT/CToolBar::GetToolBarCtrl
- AFXEXT/CToolBar::LoadBitmap
- AFXEXT/CToolBar::LoadToolBar
- AFXEXT/CToolBar::SetBitmap
- AFXEXT/CToolBar::SetButtonInfo
- AFXEXT/CToolBar::SetButtons
- AFXEXT/CToolBar::SetButtonStyle
- AFXEXT/CToolBar::SetButtonText
- AFXEXT/CToolBar::SetHeight
- AFXEXT/CToolBar::SetSizes
helpviewer_keywords:
- CToolBar [MFC], CToolBar
- CToolBar [MFC], CommandToIndex
- CToolBar [MFC], Create
- CToolBar [MFC], CreateEx
- CToolBar [MFC], GetButtonInfo
- CToolBar [MFC], GetButtonStyle
- CToolBar [MFC], GetButtonText
- CToolBar [MFC], GetItemID
- CToolBar [MFC], GetItemRect
- CToolBar [MFC], GetToolBarCtrl
- CToolBar [MFC], LoadBitmap
- CToolBar [MFC], LoadToolBar
- CToolBar [MFC], SetBitmap
- CToolBar [MFC], SetButtonInfo
- CToolBar [MFC], SetButtons
- CToolBar [MFC], SetButtonStyle
- CToolBar [MFC], SetButtonText
- CToolBar [MFC], SetHeight
- CToolBar [MFC], SetSizes
ms.assetid: e868da26-5e07-4607-9651-e2f863ad9059
ms.openlocfilehash: 4977cbe0b749724f999d6d7089d46f12d1e2963e
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78866418"
---
# <a name="ctoolbar-class"></a>Classe CToolBar

Barras de controle que têm uma linha de botões de bitmap e separadores opcionais.

## <a name="syntax"></a>Sintaxe

```
class CToolBar : public CControlBar
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CToolBar::CToolBar](#ctoolbar)|Constrói um objeto `CToolBar`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CToolBar::CommandToIndex](#commandtoindex)|Retorna o índice de um botão com a ID de comando fornecida.|
|[CToolBar:: criar](#create)|Cria a barra de ferramentas do Windows e a anexa ao objeto `CToolBar`.|
|[CToolBar::CreateEx](#createex)|Cria um objeto `CToolBar` com estilos adicionais para o objeto `CToolBarCtrl` inserido.|
|[CToolBar::GetButtonInfo](#getbuttoninfo)|Recupera a ID, o estilo e o número da imagem de um botão.|
|[CToolBar:: GetButtonStyle](#getbuttonstyle)|Recupera o estilo de um botão.|
|[CToolBar::GetButtonText](#getbuttontext)|Recupera o texto que será exibido em um botão.|
|[CToolBar:: getitemid](#getitemid)|Retorna a ID de comando de um botão ou separador no índice especificado.|
|[CToolBar::GetItemRect](#getitemrect)|Recupera o retângulo de exibição do item no índice fornecido.|
|[CToolBar::GetToolBarCtrl](#gettoolbarctrl)|Permite acesso direto ao controle comum subjacente.|
|[CToolBar:: LoadBitmap](#loadbitmap)|Carrega o bitmap que contém imagens de botão de bitmap.|
|[CToolBar:: LoadToolBar](#loadtoolbar)|Carrega um recurso de barra de ferramentas criado com o editor de recursos.|
|[CToolBar:: SetBitmap](#setbitmap)|Define uma imagem de bitmap.|
|[CToolBar::SetButtonInfo](#setbuttoninfo)|Define a ID, o estilo e o número da imagem de um botão.|
|[CToolBar:: setbotões](#setbuttons)|Define os estilos de botão e um índice de imagens de botão no bitmap.|
|[CToolBar:: SetButtonStyle](#setbuttonstyle)|Define o estilo de um botão.|
|[CToolBar:: SetButtonText](#setbuttontext)|Define o texto que será exibido em um botão.|
|[CToolBar:: SetHeight](#setheight)|Define a altura da barra de ferramentas.|
|[CToolBar:: settamanhos](#setsizes)|Define os tamanhos dos botões e seus bitmaps.|

## <a name="remarks"></a>Comentários

Os botões podem agir como os botões de ação, botões de seleção ou botão de opção. os objetos de `CToolBar` geralmente são membros incorporados de objetos de janela de quadro derivados da classe [CFrameWnd](../../mfc/reference/cframewnd-class.md) ou [CMDIFrameWnd](../../mfc/reference/cmdiframewnd-class.md).

[CToolBar:: GetToolBarCtrl](#gettoolbarctrl), uma função membro nova no MFC 4,0, permite que você aproveite o suporte do controle comum do Windows para a personalização da barra de ferramentas e funcionalidades adicionais. `CToolBar` funções membro oferecem a maior parte da funcionalidade dos controles comuns do Windows; no entanto, ao chamar `GetToolBarCtrl`, você pode dar às suas barras de ferramentas ainda mais as características das barras de ferramentas do Windows 95/98. Quando você chama `GetToolBarCtrl`, ele retornará uma referência a um objeto `CToolBarCtrl`. Consulte [CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md) para obter mais informações sobre como criar barras de ferramentas usando os controles comuns do Windows. Para obter mais informações gerais sobre controles comuns, consulte [controles comuns](/windows/win32/Controls/common-controls-intro) na SDK do Windows.

O C++ Visual fornece dois métodos para criar uma barra de ferramentas. Para criar um recurso de barra de ferramentas usando o editor de recursos, siga estas etapas:

1. Crie um recurso de barra de ferramentas.

1. Construa o objeto `CToolBar`.

1. Chame a função [Create](#create) (ou [CreateEx](#createex)) para criar a barra de ferramentas do Windows e anexá-la ao objeto `CToolBar`.

1. Chame [LoadToolBar](#loadtoolbar) para carregar o recurso da barra de ferramentas.

Caso contrário, siga estas etapas:

1. Construa o objeto `CToolBar`.

1. Chame a função [Create](#create) (ou [CreateEx](#createex)) para criar a barra de ferramentas do Windows e anexá-la ao objeto `CToolBar`.

1. Chame [LoadBitmap](#loadbitmap) para carregar o bitmap que contém as imagens do botão da barra de ferramentas.

1. Ligue para os [botões](#setbuttons) para definir o estilo do botão e associar cada botão a uma imagem no bitmap.

Todas as imagens de botão na barra de ferramentas são tiradas de um bitmap, que deve conter uma imagem para cada botão. Todas as imagens devem ter o mesmo tamanho; o padrão é 16 pixels de largura e 15 pixels de altura. As imagens devem estar lado a lado no bitmap.

A função `SetButtons` usa um ponteiro para uma matriz de IDs de controle e um inteiro que especifica o número de elementos na matriz. A função define a ID de cada botão como o valor do elemento correspondente da matriz e atribui a cada botão um índice de imagem, que especifica a posição da imagem do botão no bitmap. Se um elemento de matriz tiver o valor ID_SEPARATOR, nenhum índice de imagem será atribuído.

A ordem das imagens no bitmap geralmente é a ordem na qual elas são desenhadas na tela, mas você pode usar a função [SetButtonInfo](#setbuttoninfo) para alterar a relação entre ordem de imagem e ordem de desenho.

Todos os botões em uma barra de ferramentas têm o mesmo tamanho. O padrão é 24 x 22 pixels, de acordo com as *diretrizes de interface do Windows para o design de software*. Qualquer espaço adicional entre as dimensões de imagem e botão é usado para formar uma borda em torno da imagem.

Cada botão tem uma imagem. Os vários Estados e estilos de botão (pressionado, para cima, para baixo, desabilitado, desabilitado e indeterminado) são gerados a partir de uma imagem. Embora os bitmaps possam ser qualquer cor, você pode obter os melhores resultados com imagens em preto e tonalidades de cinza.

> [!WARNING]
> o `CToolBar` dá suporte a bitmaps com um máximo de 16 cores. Quando você carrega uma imagem em um editor de barra de ferramentas, o Visual Studio converte automaticamente a imagem em um bitmap de 16 cores, se necessário, e exibe uma mensagem de aviso se a imagem foi convertida. Se você usar uma imagem com mais de 16 cores (usando um editor externo para editar a imagem), o aplicativo poderá se comportar inesperadamente.

Os botões da barra de ferramentas imitam os suistos por padrão. No entanto, os botões da barra de ferramentas também podem imitar botões de caixa de seleção ou botões de opção. Os botões de caixa de seleção têm três Estados: marcada, desmarcada e indeterminada. Os botões de opção têm apenas dois Estados: marcado e limpo.

Para definir um botão individual ou estilo de separador sem apontar para uma matriz, chame [GetButtonStyle](#getbuttonstyle) para recuperar o estilo e, em seguida, chame [SetButtonStyle](#setbuttonstyle) em vez de `SetButtons`. `SetButtonStyle` é mais útil quando você deseja alterar o estilo de um botão em tempo de execução.

Para atribuir o texto a ser exibido em um botão, chame [GetButtonText](#getbuttontext) para recuperar o texto a ser exibido no botão e, em seguida, chame [SetButtonText](#setbuttontext) para definir o texto.

Para criar um botão de caixa de seleção, atribua o estilo TBBS_CHECKBOX ou use a função de membro `SetCheck` de um objeto `CCmdUI` em um manipulador de ON_UPDATE_COMMAND_UI. Chamar `SetCheck` transforma um botão de seleção na caixa de verificação. Passe `SetCheck` um argumento de 0 para desmarcado, 1 para marcado ou 2 para indeterminado.

Para criar um botão de opção, chame uma função de membro [SetRadio](../../mfc/reference/ccmdui-class.md#setradio) de um objeto [CCmdUI](../../mfc/reference/ccmdui-class.md) de um manipulador de ON_UPDATE_COMMAND_UI. Passe `SetRadio` um argumento de 0 para desmarcado ou diferente de zero para marcado. Para fornecer um comportamento mutuamente exclusivo de um grupo de botões, você deve ter ON_UPDATE_COMMAND_UI manipuladores para todos os botões do grupo.

Para obter mais informações sobre como usar `CToolBar`, consulte o artigo [implementação da barra de ferramentas MFC](../../mfc/mfc-toolbar-implementation.md) e [Nota técnica 31: barras de controle](../../mfc/tn031-control-bars.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CControlBar](../../mfc/reference/ccontrolbar-class.md)

`CToolBar`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext. h

##  <a name="commandtoindex"></a>CToolBar::CommandToIndex

Essa função de membro retorna o índice do primeiro botão da barra de ferramentas, começando na posição 0, cuja ID de comando corresponde a `nIDFind`.

```
int CommandToIndex(UINT nIDFind) const;
```

### <a name="parameters"></a>Parâmetros

*nIDFind*<br/>
ID de comando de um botão da barra de ferramentas.

### <a name="return-value"></a>Valor retornado

O índice do botão ou-1 se nenhum botão tiver a ID de comando fornecida.

##  <a name="create"></a>CToolBar:: criar

Essa função de membro cria uma barra de ferramentas do Windows (uma janela filho) e a associa com o objeto `CToolBar`.

```
virtual BOOL Create(
    CWnd* pParentWnd,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_TOP,
    UINT nID = AFX_IDW_TOOLBAR);
```

### <a name="parameters"></a>Parâmetros

*pParentWnd*<br/>
Ponteiro para a janela que é o pai da barra de ferramentas.

*dwStyle*<br/>
O estilo da barra de ferramentas. Os estilos de barra de ferramentas adicionais com suporte são:

- CBRS_TOP Barra de controle está na parte superior da janela do quadro.

- CBRS_BOTTOM barra de controle está na parte inferior da janela do quadro.

- CBRS_NOALIGN Barra de controle não é reposicionada quando o pai é redimensionado.

- CBRS_TOOLTIPS barra de controle exibe dicas de ferramenta.

- CBRS_SIZE_DYNAMIC barra de controle é dinâmica.

- CBRS_SIZE_FIXED barra de controle é fixa.

- CBRS_FLOATING barra de controle está flutuante.

- CBRS_FLYBY Barra de status exibe informações sobre o botão.

- CBRS_HIDE_INPLACE barra de controle não é exibida para o usuário.

*nID*<br/>
A ID da janela filho da barra de ferramentas.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Ele também define a altura da barra de ferramentas como um valor padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#179](../../mfc/codesnippet/cpp/ctoolbar-class_1.cpp)]

##  <a name="createex"></a>CToolBar::CreateEx

Chame essa função para criar uma barra de ferramentas do Windows (uma janela filho) e associá-la ao objeto `CToolBar`.

```
virtual BOOL CreateEx(
    CWnd* pParentWnd,
    DWORD dwCtrlStyle = TBSTYLE_FLAT,
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP,
    CRect rcBorders = CRect(
    0,
    0,
    0,
    0),
    UINT nID = AFX_IDW_TOOLBAR);
```

### <a name="parameters"></a>Parâmetros

*pParentWnd*<br/>
Ponteiro para a janela que é o pai da barra de ferramentas.

*dwCtrlStyle*<br/>
Estilos adicionais para a criação do objeto [CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md) inserido. Por padrão, esse valor é definido como TBSTYLE_FLAT. Para obter uma lista completa de estilos de barra de ferramentas, consulte *dwStyle*.

*dwStyle*<br/>
O estilo da barra de ferramentas. Consulte [controle da barra de ferramentas e estilos de botão](/windows/win32/Controls/toolbar-control-and-button-styles) na SDK do Windows para obter uma lista de estilos apropriados.

*rcBorders*<br/>
Um objeto [CRect](../../atl-mfc-shared/reference/crect-class.md) que define as larguras das bordas da janela da barra de ferramentas. Essas bordas são definidas como 0, 0, 0, por padrão, resultando assim em uma janela de barra de ferramentas sem bordas.

*nID*<br/>
A ID da janela filho da barra de ferramentas.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Ele também define a altura da barra de ferramentas como um valor padrão.

Use `CreateEx`, em vez de [Create](#create), quando determinados estilos precisam estar presentes durante a criação do controle da barra de ferramentas inserido. Por exemplo, defina *dwCtrlStyle* como TBSTYLE_FLAT &#124; TBSTYLE_TRANSPARENT para criar uma barra de ferramentas que se assemelha às barras de ferramentas do Internet Explorer 4.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#180](../../mfc/codesnippet/cpp/ctoolbar-class_2.cpp)]

##  <a name="ctoolbar"></a>CToolBar::CToolBar

Essa função de membro constrói um objeto `CToolBar` e define os tamanhos padrão.

```
CToolBar();
```

### <a name="remarks"></a>Comentários

Chame a função [criar](#create) membro para criar a janela da barra de ferramentas.

##  <a name="getbuttoninfo"></a>CToolBar::GetButtonInfo

Essa função de membro recupera a ID de controle, o estilo e o índice de imagem do botão da barra de ferramentas ou do separador no local especificado por *nIndex.*

```
void GetButtonInfo(
    int nIndex,
    UINT& nID,
    UINT& nStyle,
    int& iImage) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do botão da barra de ferramentas ou do separador cujas informações serão recuperadas.

*nID*<br/>
Referência a um UINT que é definido como a ID de comando do botão.

*nStyle*<br/>
Referência a um UINT que é definido como o estilo do botão.

*iImage*<br/>
Referência a um inteiro que é definido como o índice da imagem do botão dentro do bitmap.

### <a name="remarks"></a>Comentários

Esses valores são atribuídos às variáveis referenciadas por *NID*, *nStyle*e *iImage*. O índice de imagem é a posição da imagem no bitmap que contém imagens para todos os botões da barra de ferramentas. A primeira imagem está na posição 0.

Se *nIndex* especificar um separador, *iImage* será definido como a largura do separador em pixels.

##  <a name="getbuttonstyle"></a>CToolBar:: GetButtonStyle

Chame essa função de membro para recuperar o estilo de um botão ou separador na barra de ferramentas.

```
UINT GetButtonStyle(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice do botão da barra de ferramentas ou do estilo do separador a ser recuperado.

### <a name="return-value"></a>Valor retornado

O estilo do botão ou separador especificado por *nIndex*.

### <a name="remarks"></a>Comentários

O estilo de um botão determina como o botão é exibido e como ele responde à entrada do usuário. Consulte [SetButtonStyle](#setbuttonstyle) para obter exemplos de estilos de botão.

##  <a name="getbuttontext"></a>CToolBar::GetButtonText

Chame essa função de membro para recuperar o texto que aparece em um botão.

```
CString GetButtonText(int nIndex) const;

void GetButtonText(
    int nIndex,
    CString& rString) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do texto a ser recuperado.

*rString*<br/>
Uma referência a um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) que conterá o texto a ser recuperado.

### <a name="return-value"></a>Valor retornado

Um objeto de `CString` que contém o texto do botão.

### <a name="remarks"></a>Comentários

A segunda forma dessa função de membro preenche um objeto `CString` com o texto da cadeia de caracteres.

##  <a name="getitemid"></a>CToolBar:: getitemid

Essa função de membro retorna a ID de comando do botão ou separador especificado por *nIndex*.

```
UINT GetItemID(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do item cuja ID deve ser recuperada.

### <a name="return-value"></a>Valor retornado

A ID de comando do botão ou separador especificado por *nIndex*.

### <a name="remarks"></a>Comentários

Os separadores retornam ID_SEPARATOR.

##  <a name="getitemrect"></a>CToolBar::GetItemRect

Essa função de membro preenche a estrutura de `RECT` cujo endereço está contido em *lpRect* com as coordenadas do botão ou separador especificado por *nIndex*.

```
virtual void GetItemRect(
    int nIndex,
    LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do item (botão ou separador) cujas coordenadas de retângulo devem ser recuperadas.

*lpRect*<br/>
Endereço da estrutura [Rect](/windows/win32/api/windef/ns-windef-rect) que conterá as coordenadas do item.

### <a name="remarks"></a>Comentários

As coordenadas são em pixels em relação ao canto superior esquerdo da barra de ferramentas.

Use `GetItemRect` para obter as coordenadas de um separador que você deseja substituir por uma caixa de combinação ou outro controle.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CToolBar:: SetSizes](#setsizes).

##  <a name="gettoolbarctrl"></a>CToolBar::GetToolBarCtrl

Essa função de membro permite o acesso direto ao controle comum subjacente.

```
CToolBarCtrl& GetToolBarCtrl() const;
```

### <a name="return-value"></a>Valor retornado

Uma referência a um objeto `CToolBarCtrl`.

### <a name="remarks"></a>Comentários

Use `GetToolBarCtrl` para aproveitar a funcionalidade do controle comum da barra de ferramentas do Windows e aproveitar o suporte que o [CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md) fornece para a personalização da barra de ferramentas.

Para obter mais informações sobre como usar controles comuns, consulte o artigo [controles](../../mfc/controls-mfc.md) e [controles comuns](/windows/win32/Controls/common-controls-intro) na SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocViewSDI#15](../../mfc/codesnippet/cpp/ctoolbar-class_3.cpp)]

##  <a name="loadbitmap"></a>CToolBar:: LoadBitmap

Chame essa função de membro para carregar o bitmap especificado por `lpszResourceName` ou `nIDResource`.

```
BOOL LoadBitmap(LPCTSTR lpszResourceName);
BOOL LoadBitmap(UINT nIDResource);
```

### <a name="parameters"></a>Parâmetros

*lpszResourceName*<br/>
Ponteiro para o nome do recurso do bitmap a ser carregado.

*nIDResource*<br/>
ID de recurso do bitmap a ser carregado.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O bitmap deve conter uma imagem para cada botão da barra de ferramentas. Se as imagens não tiverem o tamanho padrão (16 pixels de largura e 15 pixels de altura), chame conjuntos de [tamanho](#setsizes) para definir os tamanhos de botão e suas imagens.

> [!WARNING]
> o `CToolBar` dá suporte a bitmaps com um máximo de 16 cores. Quando você carrega uma imagem em um editor de barra de ferramentas, o Visual Studio converte automaticamente a imagem em um bitmap de 16 cores, se necessário, e exibe uma mensagem de aviso se a imagem foi convertida. Se você usar uma imagem com mais de 16 cores (usando um editor externo para editar a imagem), o aplicativo poderá se comportar inesperadamente.

##  <a name="loadtoolbar"></a>CToolBar:: LoadToolBar

Chame essa função de membro para carregar a barra de ferramentas especificada por *lpszResourceName* ou *nIDResource*.

```
BOOL LoadToolBar(LPCTSTR lpszResourceName);
BOOL LoadToolBar(UINT nIDResource);
```

### <a name="parameters"></a>Parâmetros

*lpszResourceName*<br/>
Ponteiro para o nome do recurso da barra de ferramentas a ser carregada.

*nIDResource*<br/>
ID de recurso da barra de ferramentas a ser carregada.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Consulte [Editor de barra de ferramentas](../../windows/toolbar-editor.md) em para obter mais informações sobre como criar um recurso de barra de ferramentas.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CToolBar:: CreateEx](#createex).

##  <a name="setbitmap"></a>CToolBar:: SetBitmap

Chame essa função de membro para definir a imagem de bitmap para a barra de ferramentas.

```
BOOL SetBitmap(HBITMAP hbmImageWell);
```

### <a name="parameters"></a>Parâmetros

*hbmImageWell*<br/>
Identificador de uma imagem de bitmap associada a uma barra de ferramentas.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Por exemplo, chame `SetBitmap` para alterar a imagem de bitmap depois que o usuário executar uma ação em um documento que altera a ação de um botão.

##  <a name="setbuttoninfo"></a>CToolBar::SetButtonInfo

Chame essa função de membro para definir a ID de comando, o estilo e o número da imagem do botão.

```
void SetButtonInfo(
    int nIndex,
    UINT nID,
    UINT nStyle,
    int iImage);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice de base zero do botão ou separador para o qual as informações serão definidas.

*nID*<br/>
O valor para o qual a ID de comando do botão é definida.

*nStyle*<br/>
O novo estilo de botão. Há suporte para os seguintes estilos de botão:

- TBBS_BUTTON de pressão padrão (padrão)

- Separador de TBBS_SEPARATOR

- Botão de caixa de seleção automática TBBS_CHECKBOX

- TBBS_GROUP marca o início de um grupo de botões

- TBBS_CHECKGROUP marca o início de um grupo de botões de caixa de seleção

- TBBS_DROPDOWN Cria um botão de lista suspensa.

- TBBS_AUTOSIZE a largura do botão será calculada com base no texto do botão, não no tamanho da imagem.

- TBBS_NOPREFIX o texto do botão não terá um prefixo de acelerador associado a ele.

*iImage*<br/>
Novo índice para a imagem do botão dentro do bitmap.

### <a name="remarks"></a>Comentários

Para separadores, que têm o estilo TBBS_SEPARATOR, essa função define a largura do separador em pixels para o valor armazenado em *iImage*.

> [!NOTE]
>  Você também pode definir Estados de botão usando o parâmetro *nStyle* ; no entanto, como os Estados de botão são controlados pelo manipulador de [ON_UPDATE_COMMAND_UI](message-map-macros-mfc.md#on_update_command_ui) , qualquer Estado que você definir usando `SetButtonInfo` será perdido durante o próximo processamento ocioso. Consulte [como atualizar objetos de interface do usuário](../../mfc/how-to-update-user-interface-objects.md) e [TN031: barras de controle](../../mfc/tn031-control-bars.md) para obter mais informações.

Para obter informações sobre imagens e botões de bitmap, consulte a visão geral do [CToolBar](../../mfc/reference/ctoolbar-class.md) e [CToolBar:: LoadBitmap](#loadbitmap).

##  <a name="setbuttons"></a>CToolBar:: setbotões

Essa função de membro define a ID de comando de cada botão da barra de ferramentas para o valor especificado pelo elemento correspondente da matriz *lpIDArray*.

```
BOOL SetButtons(
    const UINT* lpIDArray,
    int nIDCount);
```

### <a name="parameters"></a>Parâmetros

*lpIDArray*<br/>
Ponteiro para uma matriz de IDs de comando. Pode ser nulo para alocar botões vazios.

*nIDCount*<br/>
Número de elementos na matriz apontados por *lpIDArray*.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se um elemento da matriz tiver o valor ID_SEPARATOR, um separador será criado na posição correspondente da barra de ferramentas. Essa função também define o estilo de cada botão como TBBS_BUTTON e cada estilo de separador como TBBS_SEPARATOR e atribui um índice de imagem a cada botão. O índice de imagem especifica a posição da imagem do botão dentro do bitmap.

Você não precisa considerar separadores no bitmap porque essa função não atribui índices de imagem para separadores. Se a barra de ferramentas tiver botões nas posições 0, 1 e 3 e um separador na posição 2, as imagens nas posições 0, 1 e 2 no bitmap serão atribuídas aos botões nas posições 0, 1 e 3, respectivamente.

Se *lpIDArray* for NULL, essa função alocará espaço para o número de itens especificados por *nIDCount*. Use [SetButtonInfo](#setbuttoninfo) para definir os atributos de cada item.

##  <a name="setbuttonstyle"></a>CToolBar:: SetButtonStyle

Chame essa função de membro para definir o estilo de um botão ou separador ou para agrupar botões.

```
void SetButtonStyle(
    int nIndex,
    UINT nStyle);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do botão ou separador cujas informações serão definidas.

*nStyle*<br/>
O estilo do botão. Há suporte para os seguintes estilos de botão:

- TBBS_BUTTON de pressão padrão (padrão)

- Separador de TBBS_SEPARATOR

- Botão de caixa de seleção automática TBBS_CHECKBOX

- TBBS_GROUP marca o início de um grupo de botões

- TBBS_CHECKGROUP marca o início de um grupo de botões de caixa de seleção

- TBBS_DROPDOWN Cria um botão de lista suspensa

- TBBS_AUTOSIZE a largura do botão será calculada com base no texto do botão, não no tamanho da imagem

- TBBS_NOPREFIX o texto do botão não terá um prefixo de acelerador associado a ele

### <a name="remarks"></a>Comentários

O estilo de um botão determina como o botão é exibido e como ele responde à entrada do usuário.

Antes de chamar `SetButtonStyle`, chame a função de membro [GetButtonStyle](#getbuttonstyle) para recuperar o botão ou o estilo do separador.

> [!NOTE]
>  Você também pode definir Estados de botão usando o parâmetro *nStyle* ; no entanto, como os Estados de botão são controlados pelo manipulador de [ON_UPDATE_COMMAND_UI](message-map-macros-mfc.md#on_update_command_ui) , qualquer Estado que você definir usando `SetButtonStyle` será perdido durante o próximo processamento ocioso. Consulte [como atualizar objetos de interface do usuário](../../mfc/how-to-update-user-interface-objects.md) e [TN031: barras de controle](../../mfc/tn031-control-bars.md) para obter mais informações.

##  <a name="setbuttontext"></a>CToolBar:: SetButtonText

Chame essa função para definir o texto em um botão.

```
BOOL SetButtonText(
    int nIndex,
    LPCTSTR lpszText);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice do botão cujo texto deve ser definido.

*lpszText*<br/>
Aponta para o texto a ser definido em um botão.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CToolBar:: GetToolBarCtrl](#gettoolbarctrl).

##  <a name="setheight"></a>CToolBar:: SetHeight

Essa função de membro define a altura da barra de ferramentas para o valor, em pixels, especificado em *cyHeight*.

```
void SetHeight(int cyHeight);
```

### <a name="parameters"></a>Parâmetros

*cyHeight*<br/>
A altura em pixels da barra de ferramentas.

### <a name="remarks"></a>Comentários

Depois de chamar [SetSizes](#setsizes), use essa função de membro para substituir a altura da barra de ferramentas padrão. Se a altura for muito pequena, os botões serão recortados na parte inferior.

Se essa função não for chamada, a estrutura usará o tamanho do botão para determinar a altura da barra de ferramentas.

##  <a name="setsizes"></a>CToolBar:: settamanhos

Chame essa função de membro para definir os botões da barra de ferramentas com o tamanho, em pixels, especificado em *sizeButton*.

```
void SetSizes(
    SIZE sizeButton,
    SIZE sizeImage);
```

### <a name="parameters"></a>Parâmetros

*sizeButton*<br/>
O tamanho em pixels de cada botão.

*sizeImage*<br/>
O tamanho em pixels de cada imagem.

### <a name="remarks"></a>Comentários

O parâmetro *sizeImage* deve conter o tamanho, em pixels, das imagens no bitmap da barra de ferramentas. As dimensões em *sizeButton* devem ser suficientes para conter a imagem, mais 7 pixels de largura e 6 pixels extra em altura. Essa função também define a altura da barra de ferramentas para ajustar os botões.

Chame essa função de membro somente para barras de ferramentas que não seguem as *diretrizes de interface do Windows para* obter recomendações de design de software para tamanhos de imagem e de botão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCListView#8](../../atl/reference/codesnippet/cpp/ctoolbar-class_4.cpp)]

## <a name="see-also"></a>Veja também

[Exemplo de CTRLBARS do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de DLGCBR32 do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de DOCKTOOL do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md)<br/>
[Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)
