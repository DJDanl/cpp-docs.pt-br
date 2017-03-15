---
title: Classe CMFCBaseVisualManager | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCBaseVisualManager
- CMFCBaseVisualManager.~CMFCBaseVisualManager
- ~CMFCBaseVisualManager
- CMFCBaseVisualManager::~CMFCBaseVisualManager
dev_langs:
- C++
helpviewer_keywords:
- ~CMFCBaseVisualManager destructor
- CMFCBaseVisualManager class, destructor
- CMFCBaseVisualManager class
ms.assetid: d56f3afc-cdea-4de1-825a-a08999c571e0
caps.latest.revision: 24
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 7c726fe71b7dcf26353fe0ce3a6b383eb5b578b9
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcbasevisualmanager-class"></a>Classe CMFCBaseVisualManager
Uma camada entre gerentes visual derivados e a API de tema do Windows.  
  
 `CMFCBaseVisualManager`carrega o uxtheme, se disponível e gerencia o acesso aos métodos da API de tema do Windows.  
  
 Essa classe é apenas para uso interno.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCBaseVisualManager: public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCBaseVisualManager::CMFCBaseVisualManager](#cmfcbasevisualmanager)|Constrói e inicializa um objeto `CMFCBaseVisualManager`.|  
|`CMFCBaseVisualManager::~CMFCBaseVisualManager`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCBaseVisualManager::DrawCheckBox](#drawcheckbox)|Desenha um controle de caixa de seleção usando o tema do Windows atual.|  
|[CMFCBaseVisualManager::DrawComboBorder](#drawcomboborder)|Desenha uma borda da caixa de combinação usando o tema do Windows atual.|  
|[CMFCBaseVisualManager::DrawComboDropButton](#drawcombodropbutton)|Desenha um botão de lista suspensa da caixa de combinação usando o tema do Windows atual.|  
|[CMFCBaseVisualManager::DrawPushButton](#drawpushbutton)|Desenha um botão de ação usando o tema do Windows atual.|  
|[CMFCBaseVisualManager::DrawRadioButton](#drawradiobutton)|Desenha um controle de botão de rádio usando o tema do Windows atual.|  
|[CMFCBaseVisualManager::DrawStatusBarProgress](#drawstatusbarprogress)|Desenha uma barra de progresso em um controle de barra de status ( [CMFCStatusBar classe](../../mfc/reference/cmfcstatusbar-class.md)) usando o tema do Windows atual.|  
|[CMFCBaseVisualManager::FillReBarPane](#fillrebarpane)|Preenche o plano de fundo do controle rebar usando o tema do Windows atual.|  
|[CMFCBaseVisualManager::GetStandardWindowsTheme](#getstandardwindowstheme)|Obtém o tema do Windows atual.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCBaseVisualManager::CleanUpThemes](#cleanupthemes)|Chamadas `CloseThemeData` para todos os identificadores obtida em `UpdateSystemColors`.|  
|[CMFCBaseVisualManager::UpdateSystemColors](#updatesystemcolors)|Chamadas `OpenThemeData` para obter identificadores para vários controles de desenho: windows, barras de ferramentas, botões e assim por diante.|  
  
## <a name="remarks"></a>Comentários  
 Você não precisa instanciar objetos dessa classe diretamente.  
  
 Porque é uma classe base para todos os gerentes visual, você pode simplesmente chamar [CMFCVisualManager::GetInstance](../../mfc/reference/cmfcvisualmanager-class.md#getinstance), obter um ponteiro para o Gerenciador Visual atual e acessar os métodos para `CMFCBaseVisualManager` usando esse ponteiro. No entanto, se você tiver um controle de exibição usando o tema atual do Windows, é melhor usar o `CMFCVisualManagerWindows` interface.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCBaseVisualManager](../../mfc/reference/cmfcbasevisualmanager-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxvisualmanager.h  
  
##  <a name="a-namecleanupthemesa--cmfcbasevisualmanagercleanupthemes"></a><a name="cleanupthemes"></a>CMFCBaseVisualManager::CleanUpThemes  
 Chamadas `CloseThemeData` para todos os identificadores obtida em `UpdateSystemColors`.  
  
```  
void CleanUpThemes();
```  
  
### <a name="remarks"></a>Comentários  
 Somente para uso interno.  
  
##  <a name="a-namecmfcbasevisualmanagera--cmfcbasevisualmanagercmfcbasevisualmanager"></a><a name="cmfcbasevisualmanager"></a>CMFCBaseVisualManager::CMFCBaseVisualManager  
 Constrói e inicializa um objeto `CMFCBaseVisualManager`.  
  
```  
CMFCBaseVisualManager();
```  
  
##  <a name="a-namedrawcheckboxa--cmfcbasevisualmanagerdrawcheckbox"></a><a name="drawcheckbox"></a>CMFCBaseVisualManager::DrawCheckBox  
 Desenha um controle de caixa de seleção usando o tema do Windows atual.  
  
```  
virtual BOOL DrawCheckBox(
    CDC* pDC,   
    CRect rect,   
    BOOL bHighlighted,   
    int nState,   
    BOOL bEnabled,   
    BOOL bPressed);

);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo  
  
 [in] `rect`  
 O retângulo delimitador da caixa de seleção.  
  
 [in] `bHighlighted`  
 Especifica se a caixa de seleção é realçada.  
  
 [in] `nState`  
 0 para 1 desmarcada, para check normal,  
  
 2 para misto normal.  
  
 [in] `bEnabled`  
 Especifica se a caixa de seleção está habilitada.  
  
 [in] `bPressed`  
 Especifica se a caixa de seleção é pressionada.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o tema API estiver habilitado; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Os valores de `nState` correspondem aos seguintes estilos de caixa de seleção.  
  
|nState|Estilo de caixa de seleção|  
|------------|---------------------|  
|0|CBS_UNCHECKEDNORMAL|  
|1|CBS_CHECKEDNORMAL|  
|2|CBS_MIXEDNORMAL|  
  
##  <a name="a-namedrawcombobordera--cmfcbasevisualmanagerdrawcomboborder"></a><a name="drawcomboborder"></a>CMFCBaseVisualManager::DrawComboBorder  
 Desenha a borda da caixa de combinação usando o tema do Windows atual.  
  
```  
virtual BOOL DrawComboBorder(
    CDC* pDC,   
    CRect rect,   
    BOOL bDisabled,   
    BOOL bIsDropped,   
    BOOL bIsHighlighted);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `rect`  
 Retângulo delimitador da borda da caixa de combinação.  
  
 [in] `bDisabled`  
 Especifica se a borda da caixa de combinação está desabilitada.  
  
 [in] `bIsDropped`  
 Especifica se a borda da caixa de combinação está aberta.  
  
 [in] `bIsHighlighted`  
 Especifica se a borda da caixa de combinação é realçada.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o tema API estiver habilitado; Caso contrário, `FALSE`.  
  
##  <a name="a-namedrawcombodropbuttona--cmfcbasevisualmanagerdrawcombodropbutton"></a><a name="drawcombodropbutton"></a>CMFCBaseVisualManager::DrawComboDropButton  
 Desenha um botão de lista suspensa da caixa de combinação usando o tema do Windows atual.  
  
```  
virtual BOOL DrawComboDropButton(
    CDC* pDC,   
    CRect rect,   
    BOOL bDisabled,   
    BOOL bIsDropped,   
    BOOL bIsHighlighted);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `pDC`|Um ponteiro para um contexto de dispositivo.|  
|[in] `rect`|O retângulo delimitador do botão de lista suspensa da caixa de combinação.|  
|[in] `bDisabled`|Especifica se o botão de lista suspensa de caixa de combinação está desabilitado.|  
|[in] `bIsDropped`|Especifica se o botão de lista suspensa de caixa de combinação está aberto.|  
|[in] `bIsHighlighted`|Especifica se o botão de lista suspensa de caixa de combinação é realçado.|  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o tema API estiver habilitado; Caso contrário, `FALSE`.  
  
##  <a name="a-namedrawpushbuttona--cmfcbasevisualmanagerdrawpushbutton"></a><a name="drawpushbutton"></a>CMFCBaseVisualManager::DrawPushButton  
 Desenha um botão de ação usando o tema do Windows atual.  
  
```  
virtual BOOL DrawPushButton(
    CDC* pDC,   
    CRect rect,   
    CMFCButton* pButton,   
    UINT uiState);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `rect`  
 O retângulo delimitador do botão de envio.  
  
 [in] `pButton`  
 Um ponteiro para o [CMFCButton classe](../../mfc/reference/cmfcbutton-class.md) objeto para desenhar.  
  
 [in] `uiState`  
 Ignorado. O estado é obtido `pButton`.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o tema API estiver habilitado; Caso contrário, `FALSE`.  
  
##  <a name="a-namedrawradiobuttona--cmfcbasevisualmanagerdrawradiobutton"></a><a name="drawradiobutton"></a>CMFCBaseVisualManager::DrawRadioButton  
 Desenha um controle de botão de rádio usando o tema do Windows atual.  
  
```  
virtual BOOL DrawRadioButton(
    CDC* pDC,   
    CRect rect,   
    BOOL bHighlighted,   
    BOOL bChecked,   
    BOOL bEnabled,   
    BOOL bPressed);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `rect`  
 O retângulo delimitador de botão de opção.  
  
 [in] `bHighlighted`  
 Especifica se o botão de opção é realçado.  
  
 [in] `bChecked`  
 Especifica se o botão de opção é verificado.  
  
 [in] `bEnabled`  
 Especifica se o botão de opção está habilitado.  
  
 [in] `bPressed`  
 Especifica se o botão é pressionado.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o tema API estiver habilitado; Caso contrário, `FALSE`.  
  
##  <a name="a-namedrawstatusbarprogressa--cmfcbasevisualmanagerdrawstatusbarprogress"></a><a name="drawstatusbarprogress"></a>CMFCBaseVisualManager::DrawStatusBarProgress  
 Desenha a barra de progresso no controle StatusBar ( [CMFCStatusBar classe](../../mfc/reference/cmfcstatusbar-class.md)) usando o tema do Windows atual.  
  
```  
virtual BOOL DrawStatusBarProgress(
    CDC* pDC,   
    CMFCStatusBar* pStatusBar,   
    CRect rectProgress,   
    int nProgressTotal,   
    int nProgressCurr,  
    COLORREF clrBar,   
    COLORREF clrProgressBarDest,   
    COLORREF clrProgressText,   
    BOOL bProgressText);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `pStatusBar`  
 Um ponteiro para a barra de status. Este valor é ignorado.  
  
 [in] `rectProgress`  
 O retângulo delimitador de barra de progresso `pDC` coordenadas.  
  
 [in] `nProgressTotal`  
 O valor de progresso total.  
  
 [in] `nProgressCurr`  
 O valor atual do progresso.  
  
 [in] `clrBar`  
 A cor inicial. `CMFCBaseVisualManager`ignora isso. Classes derivadas podem usá-lo para gradações de cores.  
  
 [in] `clrProgressBarDest`  
 A cor final. `CMFCBaseVisualManager`ignora isso. Classes derivadas podem usá-lo para gradações de cores.  
  
 [in] `clrProgressText`  
 Cor do texto do progresso. `CMFCBaseVisualManager`ignora isso. A cor do texto é definida por `afxGlobalData.clrBtnText`.  
  
 [in] `bProgressText`  
 Especifica se deve exibir o texto do progresso.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o tema API estiver habilitado; Caso contrário, `FALSE`.  
  
##  <a name="a-namefillrebarpanea--cmfcbasevisualmanagerfillrebarpane"></a><a name="fillrebarpane"></a>CMFCBaseVisualManager::FillReBarPane  
 Preenche o plano de fundo do controle rebar usando o tema do Windows atual.  
  
```  
virtual void FillReBarPane(
    CDC* pDC,   
    CBasePane* pBar,   
    CRect rectClient);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `pBar`  
 Um ponteiro para um painel cujo plano de fundo deve ser desenhado.  
  
 [in] `rectClient`  
 O retângulo delimitador da área a ser preenchido.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o tema API estiver habilitado; Caso contrário, `FALSE`.  
  
##  <a name="a-namegetstandardwindowsthemea--cmfcbasevisualmanagergetstandardwindowstheme"></a><a name="getstandardwindowstheme"></a>CMFCBaseVisualManager::GetStandardWindowsTheme  
 Obtém o tema do Windows atual.  
  
```  
virtual WinXpTheme GetStandardWindowsTheme();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A cor de tema do Windows atualmente selecionada. Pode ser um dos seguintes valores enumerados:  
  
- `WinXpTheme_None`-Não há nenhum tema habilitado.  
  
- `WinXpTheme_NonStandard`-tema padrão não está selecionado (ou seja, um tema é selecionado, mas nenhum da lista abaixo).  
  
- `WinXpTheme_Blue`-tema azul (Luna).  
  
- `WinXpTheme_Olive`-verde-oliva tema.  
  
- `WinXpTheme_Silver`-prateado tema.  
  
##  <a name="a-nameupdatesystemcolorsa--cmfcbasevisualmanagerupdatesystemcolors"></a><a name="updatesystemcolors"></a>CMFCBaseVisualManager::UpdateSystemColors  
 Chamadas `OpenThemeData` para obter identificadores para vários controles de desenho: windows, barras de ferramentas, botões e assim por diante.  
  
```  
void UpdateSystemColors();
```  
  
### <a name="remarks"></a>Comentários  
 Somente para uso interno.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)

