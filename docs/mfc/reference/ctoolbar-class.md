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
ms.openlocfilehash: 2abbf512085c9c59e9e6874e3f815548cd9052c1
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43760777"
---
# <a name="ctoolbar-class"></a>Classe CToolBar
Barras de controle que têm uma linha de botões de bitmap e separadores opcionais.  
  
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
|[CToolBar::Create](#create)|Cria a barra de ferramentas do Windows e anexa-o para o `CToolBar` objeto.|  
|[CToolBar::CreateEx](#createex)|Cria uma `CToolBar` objeto com estilos adicionais para o embedded `CToolBarCtrl` objeto.|  
|[CToolBar::GetButtonInfo](#getbuttoninfo)|Recupera a ID, o estilo e o número de imagem de um botão.|  
|[CToolBar::GetButtonStyle](#getbuttonstyle)|Recupera o estilo para um botão.|  
|[CToolBar::GetButtonText](#getbuttontext)|Recupera o texto que será exibido em um botão.|  
|[CToolBar::GetItemID](#getitemid)|Retorna a ID de comando de um botão ou um separador no índice especificado.|  
|[CToolBar::GetItemRect](#getitemrect)|Recupera o retângulo de exibição para o item no índice especificado.|  
|[CToolBar::GetToolBarCtrl](#gettoolbarctrl)|Permite acesso direto ao controle comum subjacente.|  
|[CToolBar::LoadBitmap](#loadbitmap)|Carrega o bitmap que contém imagens de botões de bitmap.|  
|[CToolBar::LoadToolBar](#loadtoolbar)|Carrega um recurso de barra de ferramentas criado com o editor de recursos.|  
|[CToolBar::SetBitmap](#setbitmap)|Define uma imagem de bitmap.|  
|[CToolBar::SetButtonInfo](#setbuttoninfo)|Define a ID, o estilo e o número de imagem de um botão.|  
|[CToolBar::SetButtons](#setbuttons)|Botão de conjuntos de estilos e um índice de imagens de botão dentro do bitmap.|  
|[CToolBar::SetButtonStyle](#setbuttonstyle)|Define o estilo de um botão.|  
|[CToolBar::SetButtonText](#setbuttontext)|Define o texto que será exibido em um botão.|  
|[CToolBar::SetHeight](#setheight)|Define a altura da barra de ferramentas.|  
|[CToolBar::SetSizes](#setsizes)|Define os tamanhos de botões e seus bitmaps.|  
  
## <a name="remarks"></a>Comentários  
 Os botões podem agir como comportarem, botões de caixa de seleção ou botões de opção. `CToolBar` os objetos são normalmente inseridos membros dos objetos de janela com moldura derivados da classe [CFrameWnd](../../mfc/reference/cframewnd-class.md) ou [CMDIFrameWnd](../../mfc/reference/cmdiframewnd-class.md).  
  
 [CToolBar::GetToolBarCtrl](#gettoolbarctrl), uma função de membro novo a MFC 4.0, permite que você tirar proveito do suporte do controle do Windows comuns de personalização da barra de ferramentas e funcionalidades adicionais. `CToolBar` funções de membro lhe oferece a maioria da funcionalidade dos controles comuns do Windows; No entanto, quando você chama `GetToolBarCtrl`, você pode fornecer suas barras de ferramentas ainda mais as características das barras de ferramentas do Windows 95/98. Quando você chama `GetToolBarCtrl`, ele retornará uma referência a um `CToolBarCtrl` objeto. Ver [CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md) para obter mais informações sobre como criar barras de ferramentas usando controles comuns do Windows. Para obter mais informações sobre controles comuns, consulte [controles comuns](/windows/desktop/Controls/common-controls-intro) no SDK do Windows.  
  
 Visual C++ fornece dois métodos para criar uma barra de ferramentas. Para criar um recurso de barra de ferramentas usando o Editor de recursos, siga estas etapas:  
  
1.  Crie um recurso da barra de ferramentas.  
  
2.  Construir o `CToolBar` objeto.  
  
3.  Chame o [Create](#create) (ou [CreateEx](#createex)) função para criar a barra de ferramentas do Windows e anexá-lo para o `CToolBar` objeto.  
  
4.  Chame [LoadToolBar](#loadtoolbar) para carregar o recurso da barra de ferramentas.  
  
 Caso contrário, siga estas etapas:  
  
1.  Construir o `CToolBar` objeto.  
  
2.  Chame o [Create](#create) (ou [CreateEx](#createex)) função para criar a barra de ferramentas do Windows e anexá-lo para o `CToolBar` objeto.  
  
3.  Chame [LoadBitmap](#loadbitmap) para carregar o bitmap que contém as imagens de botão de barra de ferramentas.  
  
4.  Chame [SetButtons](#setbuttons) para definir o estilo de botão e associar cada botão com uma imagem em bitmap.  
  
 Todas as imagens de botão na barra de ferramentas são tiradas de um bitmap, que deve conter uma imagem para cada botão. Todas as imagens devem ser do mesmo tamanho; o padrão é 16 pixels de largura e 15 pixels de altura. Imagens devem ser lado a lado no bitmap.  
  
 O `SetButtons` função usa um ponteiro para uma matriz de IDs de controle e um inteiro que especifica o número de elementos na matriz. A função define a ID de cada botão para o valor do elemento correspondente da matriz e atribui cada botão de um índice de imagem, que especifica a posição da imagem do botão no bitmap. Se um elemento de matriz tem o valor ID_SEPARATOR, nenhum índice de imagem é atribuído.  
  
 A ordem das imagens no bitmap é normalmente a ordem na qual eles são desenhados na tela, mas você pode usar o [SetButtonInfo](#setbuttoninfo) função para alterar a relação entre a ordem de imagem e a ordem de desenho.  
  
 Todos os botões na barra de ferramentas são do mesmo tamanho. O padrão é 22 x 24 pixels, de acordo com *Windows Interface Guidelines for Software Design*. Nenhum espaço adicional entre as dimensões de imagem e o botão é usado para formar uma borda ao redor da imagem.  
  
 Cada botão tem uma imagem. Os vários estados de botão e estilos (pressionado para cima, para baixo, desabilitado, desabilitado para baixo e indeterminado) gerados a partir de que uma imagem. Embora os bitmaps podem ser qualquer cor, você pode obter os melhores resultados com imagens em preto e tons de cinza.  
  
> [!WARNING]
> `CToolBar` dá suporte a bitmaps com um máximo de 16 cores. Quando você carrega uma imagem em um editor de barra de ferramentas, o Visual Studio automaticamente converte a imagem para um bitmap de 16 cores, se necessário e exibe uma mensagem de aviso se a imagem foi convertida. Se você usar uma imagem com mais de 16 cores (usando um editor externo para editar a imagem), o aplicativo talvez tenha um comportamento inesperado.  
  
 Botões da barra de ferramentas imitar comportarem, por padrão. No entanto, os botões de barra de ferramentas também podem imitar os botões de caixa de seleção ou botões de opção. Botões da caixa de seleção tem três estados: marcado, desmarcado e indeterminado. Botões de opção têm apenas dois estados: marcada e desmarcada.  
  
 Para definir um botão individual ou o estilo do separador sem que aponta para uma matriz, chame [GetButtonStyle](#getbuttonstyle) para recuperar o estilo e, em seguida, chame [SetButtonStyle](#setbuttonstyle) em vez de `SetButtons`. `SetButtonStyle` é mais útil quando você deseja alterar o estilo de um botão em tempo de execução.  
  
 Para atribuir texto a ser exibido em um botão, chame [GetButtonText](#getbuttontext) para recuperar o texto a ser exibido no botão e, em seguida, chame [SetButtonText](#setbuttontext) para definir o texto.  
  
 Para criar um botão da caixa de seleção, atribua a ele o estilo TBBS_CHECKBOX ou usar um `CCmdUI` do objeto `SetCheck` função de membro em um manipulador de ON_UPDATE_COMMAND_UI. Chamar `SetCheck` transforma um botão de ação em um botão da caixa de seleção. Passar `SetCheck` um argumento de 0 para 1 desmarcada, para marcar ou 2 para indeterminado.  
  
 Para criar um botão de opção, chame um [CCmdUI](../../mfc/reference/ccmdui-class.md) do objeto [SetRadio](../../mfc/reference/ccmdui-class.md#setradio) a função de membro de um manipulador ON_UPDATE_COMMAND_UI. Passar `SetRadio` um argumento de 0 para diferente de zero para marcada ou desmarcada. Para fornecer comportamento de um grupo rádio mutuamente exclusivas, você deve ter manipuladores ON_UPDATE_COMMAND_UI para todos os botões no grupo.  
  
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
 Essa função membro retorna o índice da primeira barra de ferramentas botão, começando na posição 0, cuja ID de comando corresponde ao `nIDFind`.  
  
```  
int CommandToIndex(UINT nIDFind) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIDFind*  
 ID de comando de um botão de barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do botão ou -1 se nenhum botão tem a ID do comando fornecido.  
  
##  <a name="create"></a>  CToolBar::Create  
 Essa função membro cria uma barra de ferramentas do Windows (uma janela filho) e o associa com o `CToolBar` objeto.  
  
```  
virtual BOOL Create(
    CWnd* pParentWnd,  
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_TOP,  
    UINT nID = AFX_IDW_TOOLBAR);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pParentWnd*  
 Ponteiro para a janela que é pai da barra de ferramentas.  
  
 *dwStyle*  
 O estilo de barra de ferramentas. Estilos de barra de ferramentas adicionais com suporte são:  
  
- Barra de controle de CBRS_TOP está na parte superior da janela do quadro.  
  
- Barra de controle CBRS_BOTTOM é na parte inferior da janela do quadro.  
  
- Barra de controle de CBRS_NOALIGN não é reposicionada quando o pai for redimensionado.  
  
- Barra de controle CBRS_TOOLTIPS exibe dicas de ferramenta.  
  
- Barra de controle CBRS_SIZE_DYNAMIC é dinâmica.  
  
- Barra de controle CBRS_SIZE_FIXED é fixo.  
  
- Barra de controle CBRS_FLOATING é flutuante.  
  
- Barra de Status de CBRS_FLYBY exibe informações sobre o botão.  
  
- Barra de controle de CBRS_HIDE_INPLACE não é exibida ao usuário.  
  
 *nID*  
 ID da janela filho. da barra de ferramentas  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Ele também define a altura da barra de ferramentas para um valor padrão.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#179](../../mfc/codesnippet/cpp/ctoolbar-class_1.cpp)]  
  
##  <a name="createex"></a>  CToolBar::CreateEx  
 Chame essa função para criar uma barra de ferramentas do Windows (uma janela filho) e associá-lo com o `CToolBar` objeto.  
  
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
 *pParentWnd*  
 Ponteiro para a janela que é pai da barra de ferramentas.  
  
 *dwCtrlStyle*  
 Estilos adicionais para a criação de inserido [CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md) objeto. Por padrão, esse valor é definido como TBSTYLE_FLAT. Para obter uma lista completa dos estilos de barra de ferramentas, consulte *dwStyle*.  
  
 *dwStyle*  
 O estilo de barra de ferramentas. Ver [controle de barra de ferramentas e os estilos de botão](/windows/desktop/Controls/toolbar-control-and-button-styles) no SDK do Windows para obter uma lista de estilos apropriados.  
  
 *rcBorders*  
 Um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que define as larguras das bordas de janela da barra de ferramentas. Essas áreas são definidas como 0,0,0,0 por padrão, resultando em uma janela de ferramentas sem bordas.  
  
 *nID*  
 ID da janela filho. da barra de ferramentas  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Ele também define a altura da barra de ferramentas para um valor padrão.  
  
 Use `CreateEx`, em vez de [criar](#create), quando determinados estilos precisam estar presente durante a criação do controle de barra de ferramenta incorporado. Por exemplo, defina *dwCtrlStyle* para TBSTYLE_FLAT &#124; TBSTYLE_TRANSPARENT para criar uma barra de ferramentas que se parece com as barras de ferramentas do Internet Explorer 4.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#180](../../mfc/codesnippet/cpp/ctoolbar-class_2.cpp)]  
  
##  <a name="ctoolbar"></a>  CToolBar::CToolBar  
 Essa função membro constrói um `CToolBar` do objeto e define os tamanhos padrão.  
  
```  
CToolBar();
```  
  
### <a name="remarks"></a>Comentários  
 Chame o [criar](#create) função de membro para criar a janela de ferramentas.  
  
##  <a name="getbuttoninfo"></a>  CToolBar::GetButtonInfo  
 Essa função membro recupera a ID de controle, o estilo e o índice de imagem do botão de barra de ferramentas ou separador no local especificado por *nIndex.*  
  
```  
void GetButtonInfo(
    int nIndex,  
    UINT& nID,  
    UINT& nStyle,  
    int& iImage) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIndex*  
 Índice do botão de barra de ferramentas ou separador cujas informações deve ser recuperado.  
  
 *nID*  
 Referência a um UINT que é definido como a ID de comando do botão.  
  
 *nStyle*  
 Referência a um UINT que é definido como o estilo do botão.  
  
 *iImage*  
 Referência a um número inteiro que é definido como o índice da imagem do botão dentro do bitmap.  
  
### <a name="remarks"></a>Comentários  
 Esses valores são atribuídos a variáveis referenciada pelo *nID*, *nStyle*, e *iImage*. O índice de imagem é a posição da imagem dentro do bitmap que contém imagens para todos os botões da barra de ferramentas. A primeira imagem está na posição 0.  
  
 Se *nIndex* Especifica um separador *iImage* é definido como a largura do separador em pixels.  
  
##  <a name="getbuttonstyle"></a>  CToolBar::GetButtonStyle  
 Chame essa função de membro para recuperar o estilo de um botão ou um separador na barra de ferramentas.  
  
```  
UINT GetButtonStyle(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIndex*  
 O índice do estilo de botão ou separador de barra de ferramentas a ser recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 O estilo do botão ou separador especificado por *nIndex*.  
  
### <a name="remarks"></a>Comentários  
 Estilo de um botão determina a aparência do botão e como ele responde à entrada do usuário. Ver [SetButtonStyle](#setbuttonstyle) para obter exemplos de estilos de botão.  
  
##  <a name="getbuttontext"></a>  CToolBar::GetButtonText  
 Chame essa função de membro para recuperar o texto que aparece em um botão.  
  
```  
CString GetButtonText(int nIndex) const;  
  
void GetButtonText(
    int nIndex,  
    CString& rString) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIndex*  
 Índice de texto a ser recuperado.  
  
 *rString*  
 Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém o texto a ser recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` objeto que contém o texto do botão.  
  
### <a name="remarks"></a>Comentários  
 O segundo formulário desse membro de função preenche uma `CString` objeto com o texto de cadeia de caracteres.  
  
##  <a name="getitemid"></a>  CToolBar::GetItemID  
 Essa função membro retorna a ID de comando do botão ou separador especificado por *nIndex*.  
  
```  
UINT GetItemID(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIndex*  
 Índice do item cuja ID é a ser recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 A ID de comando do botão ou separador especificado por *nIndex*.  
  
### <a name="remarks"></a>Comentários  
 Separadores de retornam ID_SEPARATOR.  
  
##  <a name="getitemrect"></a>  CToolBar::GetItemRect  
 Essa função membro preenche o `RECT` estrutura cujo endereço está contido no *lpRect* com as coordenadas do botão ou separador especificado por *nIndex*.  
  
```  
virtual void GetItemRect(
    int nIndex,  
    LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIndex*  
 Índice do item (botão ou separador) cujas coordenadas do retângulo devem ser recuperadas.  
  
 *lpRect*  
 Endereço do [RECT](../../mfc/reference/rect-structure1.md) estrutura que contém as coordenadas do item.  
  
### <a name="remarks"></a>Comentários  
 As coordenadas são em pixels, relativa ao canto superior esquerdo da barra de ferramentas.  
  
 Use `GetItemRect` para obter as coordenadas de um separador que você deseja substituir por uma caixa de combinação ou outro controle.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CToolBar::SetSizes](#setsizes).  
  
##  <a name="gettoolbarctrl"></a>  CToolBar::GetToolBarCtrl  
 Essa função membro permite acesso direto ao controle comum subjacente.  
  
```  
CToolBarCtrl& GetToolBarCtrl() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a um objeto `CToolBarCtrl`.  
  
### <a name="remarks"></a>Comentários  
 Use `GetToolBarCtrl` para tirar proveito da funcionalidade do que o controle comum de barra de ferramentas do Windows e para aproveitar o suporte [CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md) permite a personalização da barra de ferramentas.  
  
 Para obter mais informações sobre como usar controles comuns, consulte o artigo [controles](../../mfc/controls-mfc.md) e [controles comuns](/windows/desktop/Controls/common-controls-intro) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocViewSDI#15](../../mfc/codesnippet/cpp/ctoolbar-class_3.cpp)]  
  
##  <a name="loadbitmap"></a>  CToolBar::LoadBitmap  
 Chame essa função de membro para carregar o bitmap especificado por `lpszResourceName` ou `nIDResource`.  
  
```  
BOOL LoadBitmap(LPCTSTR lpszResourceName);  
BOOL LoadBitmap(UINT nIDResource);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszResourceName*  
 Ponteiro para o nome do recurso de bitmap a ser carregado.  
  
 *nIDResource*  
 ID do recurso de bitmap a ser carregado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O bitmap deve conter uma imagem para cada botão de barra de ferramentas. Se as imagens não são do tamanho padrão (16 pixels de largura e 15 pixels de altura), chamada [SetSizes](#setsizes) para definir os tamanhos de botão e suas imagens.  
  
> [!WARNING]
> `CToolBar` dá suporte a bitmaps com um máximo de 16 cores. Quando você carrega uma imagem em um editor de barra de ferramentas, o Visual Studio automaticamente converte a imagem para um bitmap de 16 cores, se necessário e exibe uma mensagem de aviso se a imagem foi convertida. Se você usar uma imagem com mais de 16 cores (usando um editor externo para editar a imagem), o aplicativo talvez tenha um comportamento inesperado.  
  
##  <a name="loadtoolbar"></a>  CToolBar::LoadToolBar  
 Chame essa função de membro para carregar a barra de ferramentas especificada por *lpszResourceName* ou *nIDResource*.  
  
```  
BOOL LoadToolBar(LPCTSTR lpszResourceName);  
BOOL LoadToolBar(UINT nIDResource);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszResourceName*  
 Ponteiro para o nome do recurso da barra de ferramentas a ser carregado.  
  
 *nIDResource*  
 ID do recurso da barra de ferramentas a ser carregado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Ver [editor de barra de ferramentas](../../windows/toolbar-editor.md) para obter mais informações sobre como criar um recurso da barra de ferramentas.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CToolBar::CreateEx](#createex).  
  
##  <a name="setbitmap"></a>  CToolBar::SetBitmap  
 Chame essa função de membro para definir a imagem de bitmap para a barra de ferramentas.  
  
```  
BOOL SetBitmap(HBITMAP hbmImageWell);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hbmImageWell*  
 Identificador de uma imagem de bitmap que está associado com uma barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Por exemplo, chamar `SetBitmap` para alterar a imagem de bitmap depois que o usuário executa uma ação em um documento que altera a ação de um botão.  
  
##  <a name="setbuttoninfo"></a>  CToolBar::SetButtonInfo  
 Chame essa função de membro para definir a ID de comando, o estilo e o número da imagem do botão.  
  
```  
void SetButtonInfo(
    int nIndex,  
    UINT nID,  
    UINT nStyle,  
    int iImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIndex*  
 Índice baseado em zero do botão ou separador para as quais informações deve ser definido.  
  
 *nID*  
 O valor para o qual a ID de comando do botão é definida.  
  
 *nStyle*  
 O novo estilo de botão. Os estilos de botão a seguir têm suporte:  
  
- Pushbutton TBBS_BUTTON Standard (padrão)  
  
- Separador TBBS_SEPARATOR  
  
- Botão de caixa de seleção automática de TBBS_CHECKBOX  
  
- TBBS_GROUP marca o início de um grupo de botões  
  
- TBBS_CHECKGROUP marca o início de um grupo de botões de caixa de seleção  
  
- TBBS_DROPDOWN cria um botão de lista suspensa.  
  
- TBBS_AUTOSIZE a largura do botão será calculada com base no texto do botão, não no tamanho da imagem.  
  
- TBBS_NOPREFIX o texto do botão não terá um prefixo de acelerador associado a ele.  
  
 *iImage*  
 Novo índice para a imagem do botão dentro do bitmap.  
  
### <a name="remarks"></a>Comentários  
 Para separadores, que têm o estilo TBBS_SEPARATOR, essa função define a largura do separador em pixels para o valor armazenado no *iImage*.  
  
> [!NOTE]
>  Você também pode definir os estados do botão usando o *nStyle* parâmetro; no entanto, porque os estados do botão são controlados pelo [ON_UPDATE_COMMAND_UI](message-map-macros-mfc.md#on_update_command_ui) manipulador, qualquer estado definido por você usando `SetButtonInfo` serão perdidas durante o próximo processamento ocioso. Ver [como objetos de Interface do usuário de atualização](../../mfc/how-to-update-user-interface-objects.md) e [TN031: barras de controle](../../mfc/tn031-control-bars.md) para obter mais informações.  
  
 Para obter informações sobre imagens de bitmap e botões, consulte o [CToolBar](../../mfc/reference/ctoolbar-class.md) visão geral e [CToolBar::LoadBitmap](#loadbitmap).  
  
##  <a name="setbuttons"></a>  CToolBar::SetButtons  
 Essa função membro define a ID de comando da cada botão barra de ferramentas como o valor especificado pelo elemento correspondente da matriz *lpIDArray*.  
  
```  
BOOL SetButtons(
    const UINT* lpIDArray,  
    int nIDCount);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpIDArray*  
 Ponteiro para uma matriz de Ids de comando. Ele pode ser NULL para alocar botões vazio.  
  
 *nIDCount*  
 Número de elementos na matriz apontada por *lpIDArray*.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se um elemento da matriz tem o valor ID_SEPARATOR, um separador será criado na posição correspondente da barra de ferramentas. Essa função também define o estilo de cada botão TBBS_BUTTON e estilo do separador cada TBBS_SEPARATOR e atribui um índice de imagem para cada botão. O índice de imagem Especifica a posição da imagem do botão dentro do bitmap.  
  
 Não precisa levar em conta para separadores em bitmap porque essa função não atribui os índices de imagem para separadores. Se sua barra de ferramentas tem botões em posições 0, 1 e 3 e um separador na posição 2, as imagens em posições 0, 1 e 2 em seu bitmap são atribuídos aos botões em posições 0, 1 e 3, respectivamente.  
  
 Se *lpIDArray* for NULL, essa função aloca espaço para o número de itens especificado por *nIDCount*. Use [SetButtonInfo](#setbuttoninfo) para definir atributos de cada item.  
  
##  <a name="setbuttonstyle"></a>  CToolBar::SetButtonStyle  
 Chame essa função de membro para definir o estilo de um botão ou um separador, ou para agrupar os botões.  
  
```  
void SetButtonStyle(
    int nIndex,  
    UINT nStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIndex*  
 Índice do botão ou separador cujas informações deve ser definido.  
  
 *nStyle*  
 O estilo de botão. Os estilos de botão a seguir têm suporte:  
  
- Pushbutton TBBS_BUTTON Standard (padrão)  
  
- Separador TBBS_SEPARATOR  
  
- Botão de caixa de seleção automática de TBBS_CHECKBOX  
  
- TBBS_GROUP marca o início de um grupo de botões  
  
- TBBS_CHECKGROUP marca o início de um grupo de botões de caixa de seleção  
  
- TBBS_DROPDOWN cria um botão de lista suspensa  
  
- TBBS_AUTOSIZE a largura do botão será calculada com base no texto do botão, não no tamanho da imagem  
  
- TBBS_NOPREFIX o texto do botão não terá um prefixo de acelerador associado a ele  
  
### <a name="remarks"></a>Comentários  
 Estilo de um botão determina a aparência do botão e como ele responde à entrada do usuário.  
  
 Antes de chamar `SetButtonStyle`, chame o [GetButtonStyle](#getbuttonstyle) a função de membro para recuperar o estilo de botão ou separador.  
  
> [!NOTE]
>  Você também pode definir os estados do botão usando o *nStyle* parâmetro; no entanto, porque os estados do botão são controlados pelo [ON_UPDATE_COMMAND_UI](message-map-macros-mfc.md#on_update_command_ui) manipulador, qualquer estado definido por você usando `SetButtonStyle` serão perdidas durante o próximo processamento ocioso. Ver [como objetos de Interface do usuário de atualização](../../mfc/how-to-update-user-interface-objects.md) e [TN031: barras de controle](../../mfc/tn031-control-bars.md) para obter mais informações.  
  
##  <a name="setbuttontext"></a>  CToolBar::SetButtonText  
 Chame essa função para definir o texto em um botão.  
  
```  
BOOL SetButtonText(
    int nIndex,  
    LPCTSTR lpszText);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIndex*  
 Índice do botão cujo texto deve ser definido.  
  
 *lpszText*  
 Aponta para o texto a ser definido em um botão.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CToolBar::GetToolBarCtrl](#gettoolbarctrl).  
  
##  <a name="setheight"></a>  CToolBar::SetHeight  
 Essa função membro define a altura da barra de ferramentas como o valor, em pixels, especificado na *cyHeight*.  
  
```  
void SetHeight(int cyHeight);
```  
  
### <a name="parameters"></a>Parâmetros  
 *cyHeight*  
 A altura em pixels, da barra de ferramentas.  
  
### <a name="remarks"></a>Comentários  
 Depois de chamar [SetSizes](#setsizes), usar essa função de membro para substituir a altura da barra de ferramentas padrão. Se a altura for muito pequena, os botões serão recortados na parte inferior.  
  
 Se essa função não for chamada, o framework usa o tamanho do botão para determinar a altura da barra de ferramentas.  
  
##  <a name="setsizes"></a>  CToolBar::SetSizes  
 Chame essa função de membro para definir os botões da barra de ferramentas como o tamanho, em pixels, especificado na *sizeButton*.  
  
```  
void SetSizes(
    SIZE sizeButton,  
    SIZE sizeImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 *sizeButton*  
 O tamanho em pixels, de cada botão.  
  
 *sizeImage*  
 O tamanho em pixels, de cada imagem.  
  
### <a name="remarks"></a>Comentários  
 O *sizeImage* parâmetro deve conter o tamanho, em pixels, das imagens no bitmap da barra de ferramentas. As dimensões no *sizeButton* deve ser suficiente para manter a imagem mais 7 pixels extras na largura e 6 extra de altura de pixels. Essa função também define a altura da barra de ferramentas de acordo com os botões.  
  
 Chame essa função de membro somente para as barras de ferramentas que não seguem *Windows Interface Guidelines for Software Design* recomendações para tamanhos de botão e imagem.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCListView#8](../../atl/reference/codesnippet/cpp/ctoolbar-class_4.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC CTRLBARS](../../visual-cpp-samples.md)   
 [DLGCBR32 de exemplo do MFC](../../visual-cpp-samples.md)   
 [Exemplo MFC DOCKTOOL](../../visual-cpp-samples.md)   
 [Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md)   
 [Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)
