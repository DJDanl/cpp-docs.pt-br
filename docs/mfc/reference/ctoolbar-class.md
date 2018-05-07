---
title: Classe CToolBar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2a80ea4cb188d879b9af0a7901ffbe89b8673df6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="ctoolbar-class"></a>Classe CToolBar
Barras de controle que tem uma linha de botões de bitmap e separadores opcionais.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CToolBar : public CControlBar  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CToolBar::CToolBar](#ctoolbar)|Constrói um objeto `CToolBar`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CToolBar::CommandToIndex](#commandtoindex)|Retorna o índice de um botão com a ID de comando especificada.|  
|[CToolBar::Create](#create)|Cria a barra de ferramentas do Windows e a anexa ao `CToolBar` objeto.|  
|[CToolBar::CreateEx](#createex)|Cria um `CToolBar` objeto com estilos adicionais para o item inserido `CToolBarCtrl` objeto.|  
|[CToolBar::GetButtonInfo](#getbuttoninfo)|Recupera a ID, o estilo e o número de imagem de um botão.|  
|[CToolBar::GetButtonStyle](#getbuttonstyle)|Recupera o estilo de um botão.|  
|[CToolBar::GetButtonText](#getbuttontext)|Recupera o texto que será exibido em um botão.|  
|[CToolBar::GetItemID](#getitemid)|Retorna a ID de comando de um botão ou um separador no índice especificado.|  
|[CToolBar::GetItemRect](#getitemrect)|Recupera o retângulo de exibição para o item no índice especificado.|  
|[CToolBar::GetToolBarCtrl](#gettoolbarctrl)|Permite acesso direto ao controle comum subjacente.|  
|[CToolBar::LoadBitmap](#loadbitmap)|Carrega o bitmap que contém imagens de bitmap de botão.|  
|[CToolBar::LoadToolBar](#loadtoolbar)|Carrega um recurso da barra de ferramentas criado com o editor de recurso.|  
|[CToolBar::SetBitmap](#setbitmap)|Define uma imagem de bitmap.|  
|[CToolBar::SetButtonInfo](#setbuttoninfo)|Define a ID, o estilo e o número de imagem de um botão.|  
|[CToolBar::SetButtons](#setbuttons)|Botão de conjuntos de estilos e um índice de imagens de botão dentro do bitmap.|  
|[CToolBar::SetButtonStyle](#setbuttonstyle)|Define o estilo de um botão.|  
|[CToolBar::SetButtonText](#setbuttontext)|Define o texto que será exibido em um botão.|  
|[CToolBar::SetHeight](#setheight)|Define a altura da barra de ferramentas.|  
|[CToolBar::SetSizes](#setsizes)|Define os tamanhos dos botões e seus bitmaps.|  
  
## <a name="remarks"></a>Comentários  
 Os botões podem agir como pushbuttons, botões da caixa de seleção ou botões de opção. `CToolBar` os objetos são geralmente inseridos membros dos objetos de janela com moldura derivados da classe [CFrameWnd](../../mfc/reference/cframewnd-class.md) ou [CMDIFrameWnd](../../mfc/reference/cmdiframewnd-class.md).  
  
 [CToolBar::GetToolBarCtrl](#gettoolbarctrl), uma função de membro novo MFC 4.0, permite aproveitar o suporte para personalização da barra de ferramentas e recursos adicionais do controle comum do Windows. `CToolBar` funções de membro lhe oferece a maioria da funcionalidade de controles comuns do Windows; No entanto, quando você chama `GetToolBarCtrl`, você pode fornecer as barras de ferramentas ainda mais as características das barras de ferramentas do Windows 95/98. Quando você chama `GetToolBarCtrl`, ela retornará uma referência a um `CToolBarCtrl` objeto. Consulte [CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md) para obter mais informações sobre a criação de barras de ferramentas usando controles comuns do Windows. Para obter mais informações sobre controles comuns, consulte [controles comuns](http://msdn.microsoft.com/library/windows/desktop/bb775493) no SDK do Windows.  
  
 Visual C++ fornece dois métodos para criar uma barra de ferramentas. Para criar um recurso da barra de ferramentas usando o Editor de recursos, siga estas etapas:  
  
1.  Crie um recurso da barra de ferramentas.  
  
2.  Construir o `CToolBar` objeto.  
  
3.  Chamar o [criar](#create) (ou [CreateEx](#createex)) função para criar a barra de ferramentas do Windows e anexá-lo para o `CToolBar` objeto.  
  
4.  Chamar [LoadToolBar](#loadtoolbar) carregar o recurso da barra de ferramentas.  
  
 Caso contrário, siga estas etapas:  
  
1.  Construir o `CToolBar` objeto.  
  
2.  Chamar o [criar](#create) (ou [CreateEx](#createex)) função para criar a barra de ferramentas do Windows e anexá-lo para o `CToolBar` objeto.  
  
3.  Chamar [LoadBitmap](#loadbitmap) para carregar o bitmap que contém as imagens de botão da barra de ferramentas.  
  
4.  Chamar [SetButtons](#setbuttons) para definir o estilo do botão e associar cada botão com uma imagem de bitmap.  
  
 Todas as imagens do botão na barra de ferramentas são obtidas de um bitmap, que deve conter uma imagem para cada botão. Todas as imagens devem ser do mesmo tamanho; o padrão é 16 pixels de largura e 15 pixels de altura. Imagens devem ser lado a lado no bitmap.  
  
 O `SetButtons` função usa um ponteiro para uma matriz de IDs de controle e um inteiro que especifica o número de elementos na matriz. A função define ID cada botão como o valor do elemento correspondente da matriz e atribui cada botão de um índice de imagem, que especifica a posição da imagem do botão no bitmap. Se um elemento de matriz tem o valor **ID_SEPARATOR**, nenhum índice de imagem é atribuído.  
  
 A ordem das imagens no bitmap geralmente é a ordem na qual eles são desenhados na tela, mas você pode usar o [SetButtonInfo](#setbuttoninfo) função para alterar a relação entre a ordem de imagem e a ordem de desenho.  
  
 Todos os botões na barra de ferramentas são do mesmo tamanho. O padrão é 22 x 24 pixels, de acordo com *diretrizes de Interface do Windows para Design de Software*. Nenhum espaço adicional entre as dimensões de imagem e o botão é usado para formar uma borda ao redor da imagem.  
  
 Cada botão tem uma imagem. Os vários estados de botão e estilos (pressionado para cima, para baixo, indeterminado desabilitado e desabilitado para baixo) são gerados a partir de uma imagem. Embora os bitmaps podem ser todas as cores, você pode obter os melhores resultados com imagens em preto e tons de cinza.  
  
> [!WARNING]
> `CToolBar` dá suporte a bitmaps com um máximo de 16 cores. Quando você carregar uma imagem em um editor de barra de ferramentas, o Visual Studio automaticamente converte a imagem em um bitmap de 16 cores, se necessário e exibe uma mensagem de aviso se a imagem foi convertida. Se você usar uma imagem com mais de 16 cores (usando um editor externo para editar a imagem), o aplicativo pode se comportar inesperadamente.  
  
 Botões da barra de ferramentas imitar pushbuttons por padrão. No entanto, os botões de barra de ferramentas também podem imitar botões da caixa de seleção ou botões de opção. Botões da caixa de seleção tem três estados: indeterminado marcados e desmarcados. Botões de opção têm apenas dois estados: marcada e desmarcada.  
  
 Para definir um botão individual ou o estilo do separador sem apontando para uma matriz, chame [GetButtonStyle](#getbuttonstyle) para recuperar o estilo e, em seguida, chamar [SetButtonStyle](#setbuttonstyle) em vez de `SetButtons`. `SetButtonStyle` é mais útil quando você deseja alterar o estilo do botão em tempo de execução.  
  
 Para atribuir o texto a ser exibido em um botão, chame [GetButtonText](#getbuttontext) para recuperar o texto a ser exibido no botão e, em seguida, chame [SetButtonText](#setbuttontext) para definir o texto.  
  
 Para criar um botão de caixa de seleção, atribuir o estilo de **TBBS_CHECKBOX** ou use um `CCmdUI` do objeto `SetCheck` função de membro em uma `ON_UPDATE_COMMAND_UI` manipulador. Chamando `SetCheck` uma botão se transforma em um botão de caixa de seleção. Passar `SetCheck` um argumento de 0 para 1 desmarcada, para marcada ou 2 para indeterminado.  
  
 Para criar um botão de opção, chame um [CCmdUI](../../mfc/reference/ccmdui-class.md) do objeto [SetRadio](../../mfc/reference/ccmdui-class.md#setradio) a função de membro de um `ON_UPDATE_COMMAND_UI` manipulador. Passar `SetRadio` um argumento de 0 para diferente de zero para marcada ou desmarcada. Para fornecer um comportamento mutuamente exclusivos de um grupo opção, você deve ter `ON_UPDATE_COMMAND_UI` manipuladores para todos os botões no grupo.  
  
 Para obter mais informações sobre como usar `CToolBar`, consulte o artigo [implementação da barra de ferramentas MFC](../../mfc/mfc-toolbar-implementation.md) e [31 de observação técnica: barras de controle](../../mfc/tn031-control-bars.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CControlBar](../../mfc/reference/ccontrolbar-class.md)  
  
 `CToolBar`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxext.h  
  
##  <a name="commandtoindex"></a>  CToolBar::CommandToIndex  
 Essa função de membro retorna o índice da primeira barra de ferramentas botão, começando na posição 0, cuja ID de comando corresponde `nIDFind`.  
  
```  
int CommandToIndex(UINT nIDFind) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIDFind`  
 ID de comando de um botão de barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do botão, ou -1 se o botão não tem a ID de comando especificada.  
  
##  <a name="create"></a>  CToolBar::Create  
 Essa função de membro cria uma barra de ferramentas do Windows (uma janela filho) e o associa a `CToolBar` objeto.  
  
```  
virtual BOOL Create(
    CWnd* pParentWnd,  
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_TOP,  
    UINT nID = AFX_IDW_TOOLBAR);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParentWnd`  
 Ponteiro para a janela que é pai da barra de ferramentas.  
  
 `dwStyle`  
 O estilo de barra de ferramentas. Estilos de barra de ferramentas adicionais com suporte são:  
  
- `CBRS_TOP` Barra de controle está na parte superior da janela do quadro.  
  
- `CBRS_BOTTOM` Barra de controle está na parte inferior da janela do quadro.  
  
- `CBRS_NOALIGN` Barra de controle é reposicionado de forma não quando o pai for redimensionado.  
  
- `CBRS_TOOLTIPS` Barra de controle exibe dicas de ferramenta.  
  
- **CBRS_SIZE_DYNAMIC** barra de controle é dinâmica.  
  
- **CBRS_SIZE_FIXED** barra de controle é fixo.  
  
- **CBRS_FLOATING** barra de controle é flutuante.  
  
- `CBRS_FLYBY` Barra de status exibe informações sobre o botão.  
  
- **CBRS_HIDE_INPLACE** barra de controle não será exibida para o usuário.  
  
 `nID`  
 ID de janela filho. da barra de ferramentas  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Ele também define a altura da barra de ferramentas para um valor padrão.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#179](../../mfc/codesnippet/cpp/ctoolbar-class_1.cpp)]  
  
##  <a name="createex"></a>  CToolBar::CreateEx  
 Chamar essa função para criar uma barra de ferramentas do Windows (uma janela filho) e associá-lo com o `CToolBar` objeto.  
  
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
 `pParentWnd`  
 Ponteiro para a janela que é pai da barra de ferramentas.  
  
 `dwCtrlStyle`  
 Estilos adicionais para a criação do item inserido [CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md) objeto. Por padrão, esse valor é definido como **TBSTYLE_FLAT**. Para obter uma lista completa dos estilos de barra de ferramentas, consulte `dwStyle`.  
  
 `dwStyle`  
 O estilo de barra de ferramentas. Consulte [controle de barra de ferramentas e os estilos de botão](http://msdn.microsoft.com/library/windows/desktop/bb760439) no SDK do Windows para obter uma lista de estilos apropriados.  
  
 *rcBorders*  
 Um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que define as larguras das bordas da janela de ferramentas. Essas áreas são definidas como 0,0,0,0 por padrão, resultando assim em uma janela de ferramentas sem bordas.  
  
 `nID`  
 ID de janela filho. da barra de ferramentas  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Ele também define a altura da barra de ferramentas para um valor padrão.  
  
 Use `CreateEx`, em vez de [criar](#create), quando determinados estilos precisam estar presente durante a criação do controle de barra de ferramenta incorporado. Por exemplo, definir `dwCtrlStyle` para **TBSTYLE_FLAT &#124; TBSTYLE_TRANSPARENT** para criar uma barra de ferramentas que se parece com as barras de ferramentas do Internet Explorer 4.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#180](../../mfc/codesnippet/cpp/ctoolbar-class_2.cpp)]  
  
##  <a name="ctoolbar"></a>  CToolBar::CToolBar  
 Essa função de membro constrói um `CToolBar` do objeto e define o tamanho padrão.  
  
```  
CToolBar();
```  
  
### <a name="remarks"></a>Comentários  
 Chamar o [criar](#create) função de membro para criar a janela de ferramentas.  
  
##  <a name="getbuttoninfo"></a>  CToolBar::GetButtonInfo  
 Essa função de membro recupera a ID de controle, o estilo e o índice de imagem do botão da barra de ferramentas ou separador no local especificado por *nIndex.*  
  
```  
void GetButtonInfo(
    int nIndex,  
    UINT& nID,  
    UINT& nStyle,  
    int& iImage) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice do botão ou o separador são cujas informações a serem recuperados.  
  
 `nID`  
 Referência a um **UINT** que é definido como a ID de comando do botão.  
  
 `nStyle`  
 Referência a um **UINT** que é definido para o estilo do botão.  
  
 `iImage`  
 Referência a um número inteiro que é definido como o índice da imagem do botão dentro do bitmap.  
  
### <a name="remarks"></a>Comentários  
 Esses valores são atribuídos a variáveis referenciadas por `nID`, `nStyle`, e `iImage`. O índice de imagem é a posição da imagem dentro do bitmap que contém imagens para todos os botões da barra de ferramentas. A primeira imagem está na posição 0.  
  
 Se `nIndex` Especifica um separador, `iImage` é definido como a largura em pixels do separador.  
  
##  <a name="getbuttonstyle"></a>  CToolBar::GetButtonStyle  
 Chame essa função de membro para recuperar o estilo de um botão ou separador na barra de ferramentas.  
  
```  
UINT GetButtonStyle(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice do estilo de botão ou o separador de barra de ferramentas a ser recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 O estilo do botão ou separador especificado por `nIndex`.  
  
### <a name="remarks"></a>Comentários  
 Estilo do botão determina como o botão é exibido e como ele responde à entrada do usuário. Consulte [SetButtonStyle](#setbuttonstyle) para obter exemplos de estilos de botão.  
  
##  <a name="getbuttontext"></a>  CToolBar::GetButtonText  
 Chame essa função de membro para recuperar o texto que aparece em um botão.  
  
```  
CString GetButtonText(int nIndex) const;  
  
void GetButtonText(
    int nIndex,  
    CString& rString) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice de texto a ser recuperado.  
  
 `rString`  
 Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém o texto a ser recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` objeto que contém o texto do botão.  
  
### <a name="remarks"></a>Comentários  
 O segundo formulário desse membro da função preenchimentos um `CString` objeto com o texto de cadeia de caracteres.  
  
##  <a name="getitemid"></a>  CToolBar::GetItemID  
 Essa função de membro retorna a ID de comando do botão ou separador especificado por `nIndex`.  
  
```  
UINT GetItemID(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice do item cuja ID é a ser recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 A ID de comando do botão ou separador especificado por `nIndex`.  
  
### <a name="remarks"></a>Comentários  
 Separadores de retorno **ID_SEPARATOR**.  
  
##  <a name="getitemrect"></a>  CToolBar::GetItemRect  
 Essa função de membro preenche o `RECT` estrutura cujo endereço está contido no `lpRect` com as coordenadas do botão ou separador especificado por `nIndex`.  
  
```  
virtual void GetItemRect(
    int nIndex,  
    LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice do item (botão ou separador) cujas coordenadas do retângulo devem ser recuperados.  
  
 `lpRect`  
 Endereço do [RECT](../../mfc/reference/rect-structure1.md) estrutura que conterá as coordenadas do item.  
  
### <a name="remarks"></a>Comentários  
 As coordenadas são em pixels em relação ao canto superior esquerdo da barra de ferramentas.  
  
 Use `GetItemRect` para obter as coordenadas de um separador que você deseja substituir por uma caixa de combinação ou outro controle.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CToolBar::SetSizes](#setsizes).  
  
##  <a name="gettoolbarctrl"></a>  CToolBar::GetToolBarCtrl  
 Essa função de membro permite acesso direto ao controle comum subjacente.  
  
```  
CToolBarCtrl& GetToolBarCtrl() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a um objeto `CToolBarCtrl`.  
  
### <a name="remarks"></a>Comentários  
 Use `GetToolBarCtrl` para tirar proveito da funcionalidade de controle comum da barra de ferramentas do Windows e para aproveitar o suporte [CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md) permite a personalização da barra de ferramentas.  
  
 Para obter mais informações sobre o uso de controles comuns, consulte o artigo [controles](../../mfc/controls-mfc.md) e [controles comuns](http://msdn.microsoft.com/library/windows/desktop/bb775493) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocViewSDI#15](../../mfc/codesnippet/cpp/ctoolbar-class_3.cpp)]  
  
##  <a name="loadbitmap"></a>  CToolBar::LoadBitmap  
 Chamar essa função de membro para carregar o bitmap especificado por `lpszResourceName` ou `nIDResource`.  
  
```  
BOOL LoadBitmap(LPCTSTR lpszResourceName);  
BOOL LoadBitmap(UINT nIDResource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszResourceName`  
 Ponteiro para o nome do recurso de bitmap a ser carregado.  
  
 `nIDResource`  
 ID de recurso do bitmap a ser carregado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O bitmap deve conter uma imagem para cada botão da barra de ferramentas. Se as imagens não são do tamanho padrão (16 pixels de largura e 15 pixels de altura), chamada [SetSizes](#setsizes) para definir os tamanhos de botão e suas imagens.  
  
> [!WARNING]
> `CToolBar` dá suporte a bitmaps com um máximo de 16 cores. Quando você carregar uma imagem em um editor de barra de ferramentas, o Visual Studio automaticamente converte a imagem em um bitmap de 16 cores, se necessário e exibe uma mensagem de aviso se a imagem foi convertida. Se você usar uma imagem com mais de 16 cores (usando um editor externo para editar a imagem), o aplicativo pode se comportar inesperadamente.  
  
##  <a name="loadtoolbar"></a>  CToolBar::LoadToolBar  
 Chamar essa função de membro para carregar a barra de ferramentas especificada por `lpszResourceName` ou `nIDResource`.  
  
```  
BOOL LoadToolBar(LPCTSTR lpszResourceName);  
BOOL LoadToolBar(UINT nIDResource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszResourceName`  
 Ponteiro para o nome do recurso da barra de ferramentas a ser carregado.  
  
 `nIDResource`  
 ID de recurso da barra de ferramentas a ser carregado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Consulte [editor de barra de ferramentas](../../windows/toolbar-editor.md) para obter mais informações sobre como criar um recurso da barra de ferramentas.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CToolBar::CreateEx](#createex).  
  
##  <a name="setbitmap"></a>  CToolBar::SetBitmap  
 Chame essa função de membro para definir a imagem de bitmap para a barra de ferramentas.  
  
```  
BOOL SetBitmap(HBITMAP hbmImageWell);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hbmImageWell*  
 Identificador de uma imagem de bitmap que está associado com uma barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Por exemplo, chamar `SetBitmap` para alterar a imagem de bitmap depois que o usuário executa uma ação em um documento que altera a ação de um botão.  
  
##  <a name="setbuttoninfo"></a>  CToolBar::SetButtonInfo  
 Chame essa função de membro para definir a ID de comando, o estilo e o número de imagem do botão.  
  
```  
void SetButtonInfo(
    int nIndex,  
    UINT nID,  
    UINT nStyle,  
    int iImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice de base zero do botão ou separador para o qual as informações são a ser definido.  
  
 `nID`  
 O valor para o qual a ID de comando do botão é definida.  
  
 `nStyle`  
 O estilo do botão novo. Os estilos de botão a seguir têm suporte:  
  
- **TBBS_BUTTON** o botão de ação padrão (padrão)  
  
- **TBBS_SEPARATOR** separador  
  
- **TBBS_CHECKBOX** botão da caixa de seleção automática  
  
- **TBBS_GROUP** marca o início de um grupo de botões  
  
- **TBBS_CHECKGROUP** marca o início de um grupo de botões de caixa de seleção  
  
- **TBBS_DROPDOWN** cria um botão de lista suspensa.  
  
- **TBBS_AUTOSIZE** largura do botão será calculada com base em texto do botão, não o tamanho da imagem.  
  
- **TBBS_NOPREFIX** o texto do botão não terá um prefixo de acelerador associado a ele.  
  
 `iImage`  
 Novo índice de imagem do botão dentro do bitmap.  
  
### <a name="remarks"></a>Comentários  
 Para separadores, que tem o estilo **TBBS_SEPARATOR**, essa função define a largura do separador em pixels para o valor armazenado na `iImage`.  
  
> [!NOTE]
>  Você também pode definir estados de botão usando o `nStyle` parâmetro; no entanto, como estados do botão são controlados pelo [ON_UPDATE_COMMAND_UI](message-map-macros-mfc.md#on_update_command_ui) manipulador, qualquer estado definido por você usando `SetButtonInfo` serão perdidas durante a próxima ocioso processamento. Consulte [como objetos de atualização de Interface do usuário](../../mfc/how-to-update-user-interface-objects.md) e [TN031: barras de controle](../../mfc/tn031-control-bars.md) para obter mais informações.  
  
 Para obter informações sobre imagens de bitmap e botões, consulte o [CToolBar](../../mfc/reference/ctoolbar-class.md) visão geral e [CToolBar::LoadBitmap](#loadbitmap).  
  
##  <a name="setbuttons"></a>  CToolBar::SetButtons  
 Essa função de membro define a ID de comando da cada botão barra de ferramentas para o valor especificado pelo elemento correspondente da matriz `lpIDArray`.  
  
```  
BOOL SetButtons(
    const UINT* lpIDArray,  
    int nIDCount);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpIDArray`  
 Ponteiro para uma matriz de Ids de comando. Ele pode ser **nulo** alocar botões vazio.  
  
 `nIDCount`  
 Número de elementos na matriz apontada pelo `lpIDArray`.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se um elemento da matriz tem o valor **ID_SEPARATOR**, um separador é criado na posição correspondente da barra de ferramentas. Essa função também define o estilo de cada botão como **TBBS_BUTTON** e o estilo de cada separador para **TBBS_SEPARATOR**e atribui um índice de imagem para cada botão. O índice de imagem Especifica a posição da imagem do botão dentro do bitmap.  
  
 Não precisa levar em conta para separadores em bitmap porque essa função não atribui índices de imagem para separadores. Se a barra de ferramentas tem botões em posições 0, 1 e 3 e um separador na posição 2, as imagens em posições 0, 1 e 2 em seu bitmap são atribuídos aos botões em posições 0, 1 e 3, respectivamente.  
  
 Se `lpIDArray` é **nulo**, essa função aloca espaço para o número de itens especificado pelo `nIDCount`. Use [SetButtonInfo](#setbuttoninfo) para definir atributos de cada item.  
  
##  <a name="setbuttonstyle"></a>  CToolBar::SetButtonStyle  
 Chame essa função de membro para definir o estilo de um botão ou um separador, ou para botões.  
  
```  
void SetButtonStyle(
    int nIndex,  
    UINT nStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice do botão ou separador cujas informações são definido.  
  
 `nStyle`  
 O estilo do botão. Os estilos de botão a seguir têm suporte:  
  
- **TBBS_BUTTON** o botão de ação padrão (padrão)  
  
- **TBBS_SEPARATOR** separador  
  
- **TBBS_CHECKBOX** botão da caixa de seleção automática  
  
- **TBBS_GROUP** marca o início de um grupo de botões  
  
- **TBBS_CHECKGROUP** marca o início de um grupo de botões de caixa de seleção  
  
- **TBBS_DROPDOWN** cria um botão de lista suspensa  
  
- **TBBS_AUTOSIZE** largura do botão será calculada com base em texto do botão, não o tamanho da imagem  
  
- **TBBS_NOPREFIX** o texto do botão não terá um prefixo de acelerador associado a ele  
  
### <a name="remarks"></a>Comentários  
 Estilo do botão determina como o botão é exibido e como ele responde à entrada do usuário.  
  
 Antes de chamar `SetButtonStyle`, chame o [GetButtonStyle](#getbuttonstyle) função de membro para recuperar o estilo do botão ou separador.  
  
> [!NOTE]
>  Você também pode definir estados de botão usando o `nStyle` parâmetro; no entanto, como estados do botão são controlados pelo [ON_UPDATE_COMMAND_UI](message-map-macros-mfc.md#on_update_command_ui) manipulador, qualquer estado definido por você usando `SetButtonStyle` serão perdidas durante a próxima ocioso processamento. Consulte [como objetos de atualização de Interface do usuário](../../mfc/how-to-update-user-interface-objects.md) e [TN031: barras de controle](../../mfc/tn031-control-bars.md) para obter mais informações.  
  
##  <a name="setbuttontext"></a>  CToolBar::SetButtonText  
 Chame essa função para definir o texto em um botão.  
  
```  
BOOL SetButtonText(
    int nIndex,  
    LPCTSTR lpszText);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice do botão cujo texto será definido.  
  
 `lpszText`  
 Aponta para o texto a ser definido em um botão.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CToolBar::GetToolBarCtrl](#gettoolbarctrl).  
  
##  <a name="setheight"></a>  CToolBar::SetHeight  
 Essa função de membro define a altura da barra de ferramentas para o valor, em pixels, especificado em `cyHeight`.  
  
```  
void SetHeight(int cyHeight);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cyHeight`  
 A altura em pixels, da barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Depois de chamar [SetSizes](#setsizes), use a função de membro para substituir a altura da barra de ferramentas padrão. Se a altura for muito pequena, serão recortados os botões na parte inferior.  
  
 Se essa função não for chamada, a estrutura usa o tamanho do botão para determinar a altura da barra de ferramentas.  
  
##  <a name="setsizes"></a>  CToolBar::SetSizes  
 Chamar essa função de membro para definir os botões da barra de ferramentas para o tamanho, em pixels, especificado em *sizeButton*.  
  
```  
void SetSizes(
    SIZE sizeButton,  
    SIZE sizeImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 *sizeButton*  
 O tamanho em pixels de cada botão.  
  
 `sizeImage`  
 O tamanho em pixels de cada imagem.  
  
### <a name="remarks"></a>Comentários  
 O `sizeImage` parâmetro deve conter o tamanho, em pixels, das imagens de bitmap da barra de ferramentas. As dimensões em *sizeButton* deve ser suficiente para manter a imagem mais 7 pixels extras de largura e 6 extra de altura. Essa função também define a altura da barra de ferramentas para ajustar os botões.  
  
 Chamar essa função de membro apenas para as barras de ferramentas que não seguem *diretrizes de Interface do Windows para Design de Software* recomendações para tamanhos de imagem do botão.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCListView#8](../../atl/reference/codesnippet/cpp/ctoolbar-class_4.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC CTRLBARS](../../visual-cpp-samples.md)   
 [DLGCBR32 de exemplo do MFC](../../visual-cpp-samples.md)   
 [Exemplo MFC DOCKTOOL](../../visual-cpp-samples.md)   
 [Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md)   
 [Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)
