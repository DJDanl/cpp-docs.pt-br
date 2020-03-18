---
title: Estrutura AFX_GLOBAL_DATA
ms.date: 11/04/2016
f1_keywords:
- AFX_GLOBAL_DATA
- AFXGLOBALS/AFX_GLOBAL_DATA::AFX_GLOBAL_DATA
- AFXGLOBALS/AFX_GLOBAL_DATA::~AFX_GLOBAL_DATA
- AFXGLOBALS/AFX_GLOBAL_DATA::CleanUp
- AFXGLOBALS/AFX_GLOBAL_DATA::D2D1MakeRotateMatrix
- AFXGLOBALS/AFX_GLOBAL_DATA::DrawParentBackground
- AFXGLOBALS/AFX_GLOBAL_DATA::DrawTextOnGlass
- AFXGLOBALS/AFX_GLOBAL_DATA::ExcludeTag
- AFXGLOBALS/AFX_GLOBAL_DATA::GetColor
- AFXGLOBALS/AFX_GLOBAL_DATA::GetDirect2dFactory
- AFXGLOBALS/AFX_GLOBAL_DATA::GetHandCursor
- AFXGLOBALS/AFX_GLOBAL_DATA::GetITaskbarList
- AFXGLOBALS/AFX_GLOBAL_DATA::GetITaskbarList3
- AFXGLOBALS/AFX_GLOBAL_DATA::GetNonClientMetrics
- AFXGLOBALS/AFX_GLOBAL_DATA::GetShellAutohideBars
- AFXGLOBALS/AFX_GLOBAL_DATA::GetTextHeight
- AFXGLOBALS/AFX_GLOBAL_DATA::GetWICFactory
- AFXGLOBALS/AFX_GLOBAL_DATA::GetWriteFactory
- AFXGLOBALS/AFX_GLOBAL_DATA::IsD2DInitialized
- AFXGLOBALS/AFX_GLOBAL_DATA::Is32BitIcons
- AFXGLOBALS/AFX_GLOBAL_DATA::IsD2DInitialized
- AFXGLOBALS/AFX_GLOBAL_DATA::IsDwmCompositionEnabled
- AFXGLOBALS/AFX_GLOBAL_DATA::IsHighContrastMode
- AFXGLOBALS/AFX_GLOBAL_DATA::OnSettingChange
- AFXGLOBALS/AFX_GLOBAL_DATA::RegisterWindowClass
- AFXGLOBALS/AFX_GLOBAL_DATA::ReleaseTaskBarRefs
- AFXGLOBALS/AFX_GLOBAL_DATA::Resume
- AFXGLOBALS/AFX_GLOBAL_DATA::SetLayeredAttrib
- AFXGLOBALS/AFX_GLOBAL_DATA::SetMenuFont
- AFXGLOBALS/AFX_GLOBAL_DATA::ShellCreateItemFromParsingName
- AFXGLOBALS/AFX_GLOBAL_DATA::UpdateFonts
- AFXGLOBALS/AFX_GLOBAL_DATA::UpdateSysColors
- AFXGLOBALS/AFX_GLOBAL_DATA::EnableAccessibilitySupport
- AFXGLOBALS/AFX_GLOBAL_DATA::IsAccessibilitySupport
- AFXGLOBALS/AFX_GLOBAL_DATA::IsWindowsLayerSupportAvailable
- AFXGLOBALS/AFX_GLOBAL_DATA::bIsOSAlphaBlendingSupport
- AFXGLOBALS/AFX_GLOBAL_DATA::bIsWindows7
- AFXGLOBALS/AFX_GLOBAL_DATA::clrActiveCaptionGradient
- AFXGLOBALS/AFX_GLOBAL_DATA::clrInactiveCaptionGradient
- AFXGLOBALS/AFX_GLOBAL_DATA::m_bUseBuiltIn32BitIcons
- AFXGLOBALS/AFX_GLOBAL_DATA::m_bUseSystemFont
- AFXGLOBALS/AFX_GLOBAL_DATA::m_hcurHand
- AFXGLOBALS/AFX_GLOBAL_DATA::m_hcurStretch
- AFXGLOBALS/AFX_GLOBAL_DATA::m_hcurStretchVert
- AFXGLOBALS/AFX_GLOBAL_DATA::m_hiconTool
- AFXGLOBALS/AFX_GLOBAL_DATA::m_nAutoHideToolBarMargin
- AFXGLOBALS/AFX_GLOBAL_DATA::m_nAutoHideToolBarSpacing
- AFXGLOBALS/AFX_GLOBAL_DATA::m_nDragFrameThicknessDock
- AFXGLOBALS/AFX_GLOBAL_DATA::m_nDragFrameThicknessFloat
helpviewer_keywords:
- AFX_GLOBAL_DATA structure [MFC]
- AFX_GLOBAL_DATA constructor
ms.assetid: c7abf2fb-ad5e-4336-a01d-260c29ed53a2
ms.openlocfilehash: dda3056cbed18ef93e09b52cd9d0a6b00e1db177
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79420585"
---
# <a name="afx_global_data-structure"></a>Estrutura AFX_GLOBAL_DATA

A estrutura de `AFX_GLOBAL_DATA` contém campos e métodos que são usados para gerenciar a estrutura ou personalizar a aparência e o comportamento do seu aplicativo.

## <a name="syntax"></a>Sintaxe

```
struct AFX_GLOBAL_DATA
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|`AFX_GLOBAL_DATA::AFX_GLOBAL_DATA`|Constrói uma estrutura de `AFX_GLOBAL_DATA`.|
|`AFX_GLOBAL_DATA::~AFX_GLOBAL_DATA`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[AFX_GLOBAL_DATA:: CleanUp](#cleanup)|Libera recursos que são alocados pela estrutura, como pincéis, fontes e DLLs.|
|[AFX_GLOBAL_DATA::D 2D1MakeRotateMatrix](#d2d1makerotatematrix)|Cria uma transformação de rotação que gira por um ângulo especificado em torno de um ponto especificado.|
|[AFX_GLOBAL_DATA::D rawParentBackground](#drawparentbackground)|Desenha a tela de fundo do pai de um controle na área especificada.|
|[AFX_GLOBAL_DATA::D rawTextOnGlass](#drawtextonglass)|Desenha o texto especificado no estilo visual do tema especificado.|
|[AFX_GLOBAL_DATA:: ExcludeTag](#excludetag)|Remove o par de marcas XML especificado de um buffer especificado.|
|[AFX_GLOBAL_DATA:: GetColor](#getcolor)|Recupera a cor atual do elemento da interface do usuário especificado.|
|[AFX_GLOBAL_DATA:: GetDirect2dFactory](#getdirect2dfactory)|Retorna um ponteiro para a interface de `ID2D1Factory` que é armazenada nos dados globais. Se a interface não for inicializada, ela será criada e terá os parâmetros padrão.|
|[AFX_GLOBAL_DATA:: GetHandCursor](#gethandcursor)|Recupera o cursor predefinido que se assemelha a uma mão e cujo identificador é `IDC_HAND`.|
|[AFX_GLOBAL_DATA:: GetITaskbarList](#getitaskbarlist)|Cria e armazena no dados global um ponteiro para a interface ITaskBarList.|
|[AFX_GLOBAL_DATA:: GetITaskbarList3](#getitaskbarlist3)|Cria e armazena no dados global um ponteiro para a interface ITaskBarList3.|
|[AFX_GLOBAL_DATA:: GetNonClientMetrics](#getnonclientmetrics)|Recupera as métricas associadas à área não cliente de janelas não minimizadas.|
|[AFX_GLOBAL_DATA:: GetShellAutohideBars](#getshellautohidebars)|Determina as posições das barras de ocultar automaticamente do Shell.|
|[AFX_GLOBAL_DATA:: GetTextHeight](#gettextheight)|Recupera a altura dos caracteres de texto na fonte atual.|
|[AFX_GLOBAL_DATA:: GetWICFactory](#getwicfactory)|Retorna um ponteiro para a interface de `IWICImagingFactory` que é armazenada nos dados globais. Se a interface não for inicializada, ela será criada e terá os parâmetros padrão.|
|[AFX_GLOBAL_DATA:: GetWriteFactory](#getwritefactory)|Retorna um ponteiro para a interface de `IDWriteFactory` que é armazenada nos dados globais. Se a interface não for inicializada, ela será criada e terá os parâmetros padrão.|
|[AFX_GLOBAL_DATA:: IsD2DInitialized](#isd2dinitialized)|Inicializa as fábricas `D2D`, `DirectWrite`e `WIC`. Chame esse método antes que a janela principal seja inicializada.|
|[AFX_GLOBAL_DATA:: Is32BitIcons](#is32biticons)|Indica se há suporte para ícones predefinidos de 32 bits.|
|[AFX_GLOBAL_DATA:: IsD2DInitialized](#isd2dinitialized)|Determina se o `D2D` foi inicializado.|
|[AFX_GLOBAL_DATA:: IsDwmCompositionEnabled](#isdwmcompositionenabled)|Fornece uma maneira simples de chamar o método [DwmIsCompositionEnabled](/windows/win32/api/dwmapi/nf-dwmapi-dwmiscompositionenabled) do Windows.|
|[AFX_GLOBAL_DATA:: IsHighContrastMode](#ishighcontrastmode)|Indica se as imagens são exibidas no momento em alto contraste.|
|[AFX_GLOBAL_DATA:: OnSettingChange](#onsettingchange)|Detecta o estado atual da animação de menu da área de trabalho e dos recursos de AutoOcultar da barra de tarefas.|
|[AFX_GLOBAL_DATA:: RegisterWindowClass](#registerwindowclass)|Registra a classe de janela do MFC especificada.|
|[AFX_GLOBAL_DATA:: ReleaseTaskBarRefs](#releasetaskbarrefs)|Libera interfaces obtidas por meio de métodos GetITaskbarList e GetITaskbarList3.|
|[AFX_GLOBAL_DATA:: retomar](#resume)|Reinicializa os ponteiros de função interna que acessam os métodos que dão suporte a [temas e estilos visuais](/windows/win32/Controls/visual-styles-overview)do Windows.|
|[AFX_GLOBAL_DATA:: SetLayeredAttrib](#setlayeredattrib)|Fornece uma maneira simples de chamar o método [SetLayeredWindowAttributes](/windows/win32/api/winuser/nf-winuser-setlayeredwindowattributes) do Windows.|
|[AFX_GLOBAL_DATA:: SetMenuFont](#setmenufont)|Cria a fonte lógica especificada.|
|[AFX_GLOBAL_DATA:: ShellCreateItemFromParsingName](#shellcreateitemfromparsingname)|Cria e inicializa um objeto de item de Shell a partir de um nome de análise.|
|[AFX_GLOBAL_DATA:: UpdateFonts](#updatefonts)|Reintializes as fontes lógicas que são usadas pela estrutura.|
|[AFX_GLOBAL_DATA:: UpdateSysColors](#updatesyscolors)|Inicializa as cores, a intensidade da cor, os pincéis, as canetas e as imagens usadas pela estrutura.|

### <a name="protected-methods"></a>Métodos protegidos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[AFX_GLOBAL_DATA:: EnableAccessibilitySupport](#enableaccessibilitysupport)|Habilita ou desabilita o suporte ao Microsoft Acessibilidade Ativa. Acessibilidade Ativa fornece métodos confiáveis para expor informações sobre elementos da interface do usuário.|
|[AFX_GLOBAL_DATA:: IsAccessibilitySupport](#isaccessibilitysupport)|Indica se o suporte ao Microsoft Acessibilidade Ativa está habilitado.|
|[AFX_GLOBAL_DATA:: IsWindowsLayerSupportAvailable](#iswindowslayersupportavailable)|Indica se o sistema operacional dá suporte a janelas em camadas.|

### <a name="data-members"></a>Membros de dados

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[AFX_GLOBAL_DATA:: bIsOSAlphaBlendingSupport](#bisosalphablendingsupport)|Indica se o sistema operacional atual dá suporte à mistura alfa.|
|[AFX_GLOBAL_DATA:: bIsWindows7](#biswindows7)|Indica se o aplicativo está sendo executado no sistema operacional Windows 7 ou superior|
|[AFX_GLOBAL_DATA:: clrActiveCaptionGradient](#clractivecaptiongradient)|Especifica a cor de gradiente da legenda ativa. Geralmente usado para painéis de encaixe.|
|[AFX_GLOBAL_DATA:: clrInactiveCaptionGradient](#clrinactivecaptiongradient)|Especifica a cor de gradiente da legenda ativa inativa. Geralmente usado para painéis de encaixe.|
|[AFX_GLOBAL_DATA:: m_bUseBuiltIn32BitIcons](#m_busebuiltin32biticons)|Indica se a estrutura usa ícones ou ícones de cor de 32 bits predefinidos de uma resolução mais baixa.|
|[AFX_GLOBAL_DATA:: m_bUseSystemFont](#m_busesystemfont)|Indica se uma fonte do sistema é usada para menus, barras de ferramentas e faixas de faixa.|
|[AFX_GLOBAL_DATA:: m_hcurHand](#m_hcurhand)|Armazena o identificador para o cursor à mão.|
|[AFX_GLOBAL_DATA:: m_hcurStretch](#m_hcurstretch)|Armazena o identificador do cursor de ampliação horizontal.|
|[AFX_GLOBAL_DATA:: m_hcurStretchVert](#m_hcurstretchvert)|Armazena o identificador do cursor de ampliação vertical.|
|[AFX_GLOBAL_DATA:: m_hiconTool](#m_hicontool)|Armazena o identificador para o ícone de ferramenta.|
|[AFX_GLOBAL_DATA:: m_nAutoHideToolBarMargin](#m_nautohidetoolbarmargin)|Especifica o deslocamento da barra de ferramentas de AutoOcultar da extrema esquerda para o lado esquerdo da barra de encaixe.|
|[AFX_GLOBAL_DATA:: m_nAutoHideToolBarSpacing](#m_nautohidetoolbarspacing)|Especifica a lacuna entre as barras de ferramentas de AutoOcultar.|
|[AFX_GLOBAL_DATA:: m_nDragFrameThicknessDock](#m_ndragframethicknessdock)|Especifica a espessura do quadro de arrastar que é usado para comunicar o estado encaixado.|
|[AFX_GLOBAL_DATA:: m_nDragFrameThicknessFloat](#m_ndragframethicknessfloat)|Especifica a espessura do quadro de arrastar que é usado para comunicar o estado flutuante.|

### <a name="remarks"></a>Comentários

A maioria dos dados na estrutura de `AFX_GLOBAL_DATA` é inicializada quando seu aplicativo é iniciado.

### <a name="inheritance-hierarchy"></a>Hierarquia de herança

`AFX_GLOBAL_DATA`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxglobals. h

## <a name="bisosalphablendingsupport"></a>AFX_GLOBAL_DATA:: bIsOSAlphaBlendingSupport

Indica se o sistema operacional dá suporte à mistura alfa.

```
BOOL  bIsOSAlphaBlendingSupport;
```

### <a name="remarks"></a>Comentários

VERDADEIRO indica que há suporte para a mesclagem alfa; caso contrário, FALSE.

## <a name="cleanup"></a>AFX_GLOBAL_DATA:: CleanUp

Libera recursos que são alocados pela estrutura, como pincéis, fontes e DLLs.

```
void CleanUp();
```

## <a name="d2d1makerotatematrix"></a>AFX_GLOBAL_DATA::D 2D1MakeRotateMatrix

Cria uma transformação de rotação que gira por um ângulo especificado em torno de um ponto especificado.

```
HRESULT D2D1MakeRotateMatrix(
    FLOAT angle,
    D2D1_POINT_2F center,
    D2D1_MATRIX_3X2_F *matrix);
```

### <a name="parameters"></a>parâmetros

*firmeza*<br/>
O ângulo da rotação no sentido horário, em graus.

*centraliza*<br/>
O ponto sobre o qual girar.

*tabela*<br/>
Quando esse método retorna, contém a nova transformação de rotação. Você deve alocar armazenamento para esse parâmetro.

### <a name="return-value"></a>Valor retornado

Retorna S_OK se obtiver êxito ou um valor de erro, caso contrário.

## <a name="drawparentbackground"></a>AFX_GLOBAL_DATA::D rawParentBackground

Desenha a tela de fundo do pai de um controle na área especificada.

```
BOOL DrawParentBackground(
    CWnd* pWnd,
    CDC* pDC,
    LPRECT lpRect = NULL);
```

### <a name="parameters"></a>parâmetros

*pWnd*<br/>
no Ponteiro para a janela de um controle.

*pDC*<br/>
no Ponteiro para um contexto de dispositivo.

*lpRect*<br/>
no Ponteiro para um retângulo que limita a área a ser desenhada. O valor padrão é NULL.

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

## <a name="drawtextonglass"></a>AFX_GLOBAL_DATA::D rawTextOnGlass

Desenha o texto especificado no estilo visual do tema especificado.

```
BOOL DrawTextOnGlass(
    HTHEME hTheme,
    CDC* pDC,
    int iPartId,
    int iStateId,
    CString strText,
    CRect rect,
    DWORD dwFlags,
    int nGlowSize = 0,
    COLORREF clrText = (COLORREF)-1);
```

### <a name="parameters"></a>parâmetros

*hTheme*<br/>
no Manipule os dados de tema de uma janela ou NULL. A estrutura usará o tema especificado para desenhar o texto se esse parâmetro não for nulo e houver suporte para temas. Caso contrário, a estrutura não usa um tema para desenhar o texto.

Use o método [OpenThemeData](/windows/win32/api/uxtheme/nf-uxtheme-openthemedata) para criar um hTheme.

*pDC*<br/>
no Ponteiro para um contexto de dispositivo.

*iPartId*<br/>
no A parte de controle que tem a aparência de texto desejada. Para obter mais informações, consulte a coluna Parts da tabela em [Parts and statess](/windows/win32/controls/parts-and-states). Se esse valor for 0, o texto será desenhado na fonte padrão ou uma fonte selecionada no contexto do dispositivo.

*istateid*<br/>
no O estado de controle que tem a aparência de texto desejada. Para obter mais informações, consulte a coluna Estados da tabela em [partes e Estados](/windows/win32/controls/parts-and-states).

*strText*<br/>
no O texto a ser desenhado.

*Rect*<br/>
no O limite da área na qual o texto especificado é desenhado.

*dwFlags*<br/>
no Uma combinação de bits (ou) de sinalizadores que especifica como o texto especificado é desenhado.

Se o parâmetro *hTheme* for `NULL` ou se não houver suporte e estiver habilitado para temas, o parâmetro *NFormat* do método [CDC::D rawtext](../../mfc/reference/cdc-class.md#drawtext) descreverá os sinalizadores válidos. Se houver suporte para temas, o parâmetro *dwFlags* do método [DrawThemeTextEx](/windows/win32/api/uxtheme/nf-uxtheme-drawthemetextex) descreverá os sinalizadores válidos.

*nGlowSize*<br/>
no O tamanho de um efeito de brilho que é desenhado em segundo plano antes de desenhar o texto especificado. O valor padrão é 0.

*clrText*<br/>
no A cor na qual o texto especificado é desenhado. O valor padrão é a cor padrão.

### <a name="return-value"></a>Valor retornado

TRUE se um tema for usado para desenhar o texto especificado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Um tema define o estilo visual de um aplicativo. Um tema não será usado para desenhar o texto se o parâmetro *hTheme* for nulo ou se o método [DrawThemeTextEx](/windows/win32/api/uxtheme/nf-uxtheme-drawthemetextex) não tiver suporte ou se a composição de [Gerenciador de janelas da área de trabalho](/windows/win32/dwm/dwm-overview) (DWM) estiver desabilitada.

## <a name="enableaccessibilitysupport"></a>AFX_GLOBAL_DATA:: EnableAccessibilitySupport

Habilita ou desabilita o suporte ao Microsoft Acessibilidade Ativa.

```
void EnableAccessibilitySupport(BOOL bEnable=TRUE);
```

### <a name="parameters"></a>parâmetros

*bEnable*<br/>
no TRUE para habilitar o suporte de acessibilidade; FALSE para desabilitar o suporte de acessibilidade. O valor padrão é TRUE.

### <a name="remarks"></a>Comentários

O Acessibilidade Ativa é uma tecnologia baseada em COM que melhora a maneira como os programas e o sistema operacional Windows funcionam em conjunto com produtos de tecnologia assistencial. Ele fornece métodos confiáveis para expor informações sobre elementos da interface do usuário. No entanto, um modelo de acessibilidade mais recente chamado Microsoft UI Automation já está disponível. Para obter uma comparação das duas tecnologias, consulte [automação da interface do usuário e Microsoft acessibilidade ativa](/dotnet/framework/ui-automation/ui-automation-and-microsoft-active-accessibility).

Use o método [AFX_GLOBAL_DATA:: IsAccessibilitySupport](#isaccessibilitysupport) para determinar se o suporte ao Microsoft acessibilidade ativa está habilitado.

## <a name="excludetag"></a>AFX_GLOBAL_DATA:: ExcludeTag

Remove o par de marcas XML especificado de um buffer especificado.

```
BOOL ExcludeTag(
    CString& strBuffer,
    LPCTSTR lpszTag,
    CString& strTag,
    BOOL bIsCharsList = FALSE);
```

### <a name="parameters"></a>parâmetros

*strBuffer*<br/>
no Um buffer de texto.

*lpszTag*<br/>
no O nome de um par de marcas XML de abertura e fechamento.

*strTag*<br/>
fora Quando esse método retorna, o parâmetro *strTag* contém o texto que está entre as marcas XML de abertura e fechamento que são nomeadas pelo parâmetro *lpszTag* . Qualquer espaço em branco à esquerda ou à direita é cortado do resultado.

*bIsCharsList*<br/>
no TRUE para converter símbolos de caracteres de escape no parâmetro *strTag* em caracteres de escape reais; FALSE não para executar a conversão. O valor padrão é FALSE. Para obter mais informações, consulte Comentários.

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Um par de marcas XML consiste em marcas de abertura e fechamento nomeadas que indicam o início e o término de uma execução de texto no buffer especificado. O parâmetro *strBuffer* especifica o buffer e o parâmetro *lpszTag* especifica o nome das marcas XML.

Use os símbolos na tabela a seguir para codificar um conjunto de caracteres de escape no buffer especificado. Especifique TRUE para que o parâmetro *bIsCharsList* converta os símbolos no parâmetro *strTag* em caracteres de escape reais. A tabela a seguir usa a macro [_T ()](../../c-runtime-library/data-type-mappings.md) para especificar o símbolo e as cadeias de caracteres de escape.

|Símbolo|Caractere de escape|
|------------|----------------------|
|_T ("\\\t")|_T ("\t")|
|_T ("\\\n")|_T("\n")|
|_T ("\\\r")|_T ("\r")|
|_T ("\\\b")|_T ("\b")|
|_T("LT")|_T ("\<")|
|_T("GT")|_T(">")|
|_T ("AMP")|_T("&")|

## <a name="getcolor"></a>AFX_GLOBAL_DATA:: GetColor

Recupera a cor atual do elemento da interface do usuário especificado.

```
COLORREF GetColor(int nColor);
```

### <a name="parameters"></a>parâmetros

*nColor*<br/>
no Um valor que especifica um elemento de interface do usuário cuja cor é recuperada. Para obter uma lista de valores válidos, consulte o parâmetro *nIndex* do método [GetSysColor](/windows/win32/api/winuser/nf-winuser-getsyscolor) .

### <a name="return-value"></a>Valor retornado

O valor de cor RGB do elemento de interface do usuário especificado. Para obter mais informações, consulte Comentários.

### <a name="remarks"></a>Comentários

Se o parâmetro *nColor* estiver fora do intervalo, o valor de retorno será zero. Como zero também é um valor RGB válido, você não pode usar esse método para determinar se há suporte para uma cor do sistema no sistema operacional atual. Em vez disso, use o método [GetSysColorBrush](/windows/win32/api/winuser/nf-winuser-getsyscolorbrush) , que retornará NULL se a cor não for suportada.

## <a name="getdirect2dfactory"></a>AFX_GLOBAL_DATA:: GetDirect2dFactory

Retorna um ponteiro para a interface ID2D1Factory que é armazenada nos dados globais. Se a interface não for inicializada, ela será criada e terá os parâmetros padrão.

```
ID2D1Factory* GetDirect2dFactory();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a interface ID2D1Factory se a criação de uma fábrica for bem-sucedida ou for nula se a criação falhar ou se o sistema operacional atual não tiver suporte a D2D.

## <a name="gethandcursor"></a>AFX_GLOBAL_DATA:: GetHandCursor

Recupera o cursor predefinido que se assemelha a uma mão e cujo identificador é IDC_HAND.

```
HCURSOR GetHandCursor();
```

### <a name="return-value"></a>Valor retornado

O identificador do cursor à mão.

## <a name="getnonclientmetrics"></a>AFX_GLOBAL_DATA:: GetNonClientMetrics

Recupera as métricas associadas à área não cliente de janelas não minimizadas.

```
BOOL GetNonClientMetrics(NONCLIENTMETRICS& info);
```

### <a name="parameters"></a>parâmetros

*info*<br/>
[entrada, saída] Uma estrutura [NONCLIENTMETRICS](/windows/win32/api/winuser/ns-winuser-nonclientmetricsw) que contém as métricas escalonáveis associadas à área não cliente de uma janela não minimizada.

### <a name="return-value"></a>Valor retornado

TRUE se esse método tiver sucesso; caso contrário, FALSE.

## <a name="gettextheight"></a>AFX_GLOBAL_DATA:: GetTextHeight

Recupera a altura dos caracteres de texto na fonte atual.

```
int GetTextHeight(BOOL bHorz = TRUE);
```

### <a name="parameters"></a>parâmetros

*bHorz*<br/>
no TRUE para recuperar a altura dos caracteres quando o texto é executado horizontalmente; FALSE para recuperar a altura dos caracteres quando o texto é executado verticalmente. O valor padrão é TRUE.

### <a name="return-value"></a>Valor retornado

A altura da fonte atual, que é medida de sua ascendente para a mais decrescente.

## <a name="getwicfactory"></a>AFX_GLOBAL_DATA:: GetWICFactory

Retorna um ponteiro para a interface IWICImagingFactory que é armazenada nos dados globais. Se a interface não for inicializada, ela será criada e terá os parâmetros padrão.

```
IWICImagingFactory* GetWICFactory();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a interface IWICImagingFactory se a criação de uma fábrica for bem-sucedida ou for nula se a criação falhar ou se o sistema operacional atual não tiver suporte a WIC.

## <a name="getwritefactory"></a>AFX_GLOBAL_DATA:: GetWriteFactory

Retorna um ponteiro para a interface IDWriteFactory que é armazenada nos dados globais. Se a interface não for inicializada, ela será criada e terá os parâmetros padrão.

```
IDWriteFactory* GetWriteFactory();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a interface IDWriteFactory se a criação de uma fábrica for bem-sucedida ou for nula se a criação falhar ou se o sistema operacional atual não tiver suporte a DirectWrite.

## <a name="initd2d"></a>AFX_GLOBAL_DATA:: InitD2D

Inicializa as fábricas D2D, DirectWrite e WIC. Chame esse método antes que a janela principal seja inicializada.

```
BOOL InitD2D(
    D2D1_FACTORY_TYPE d2dFactoryType = D2D1_FACTORY_TYPE_SINGLE_THREADED,
    DWRITE_FACTORY_TYPE writeFactoryType = DWRITE_FACTORY_TYPE_SHARED);
```

### <a name="parameters"></a>parâmetros

*d2dFactoryType*<br/>
O modelo de Threading da fábrica D2D e os recursos que ele cria.

*writeFactoryType*<br/>
Um valor que especifica se o objeto de fábrica de gravação será compartilhado ou isolado

### <a name="return-value"></a>Valor retornado

Retornará TRUE se as fábricas forem intilalizrd; caso contrário, FALSE

## <a name="is32biticons"></a>AFX_GLOBAL_DATA:: Is32BitIcons

Indica se há suporte para ícones predefinidos de 32 bits.

```
BOOL Is32BitIcons() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se os ícones predefinidos de 32 bits forem suportados; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método retornará TRUE se a estrutura der suporte a ícones internos de 32 bits e se o sistema operacional der suporte a 16 bits por pixel ou mais, e se as imagens não forem exibidas em alto contraste.

## <a name="isaccessibilitysupport"></a>AFX_GLOBAL_DATA:: IsAccessibilitySupport

Indica se o suporte ao Microsoft Acessibilidade Ativa está habilitado.

```
BOOL IsAccessibilitySupport() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o suporte à acessibilidade estiver habilitado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O Microsoft Acessibilidade Ativa foi a solução anterior para tornar os aplicativos acessíveis. A automação da interface do usuário da Microsoft é o novo modelo de acessibilidade para o Microsoft Windows e destina-se a atender às necessidades de produtos de tecnologia assistencial e ferramentas de teste automatizadas.

Use o método [AFX_GLOBAL_DATA:: EnableAccessibilitySupport](#enableaccessibilitysupport) para habilitar ou desabilitar o suporte a acessibilidade ativa.

## <a name="isd2dinitialized"></a>AFX_GLOBAL_DATA:: IsD2DInitialized

Determina se o D2D foi inicializado

```
BOOL IsD2DInitialized() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se D2D tiver sido inicializado; caso contrário, FALSE.

## <a name="isdwmcompositionenabled"></a>AFX_GLOBAL_DATA:: IsDwmCompositionEnabled

Fornece uma maneira simples de chamar o método [DwmIsCompositionEnabled](/windows/win32/api/dwmapi/nf-dwmapi-dwmiscompositionenabled) do Windows.

```
BOOL IsDwmCompositionEnabled();
```

### <a name="return-value"></a>Valor retornado

TRUE se a composição de [Gerenciador de janelas da área de trabalho](/windows/win32/dwm/dwm-overview) (DWM) estiver habilitada; caso contrário, FALSE.

## <a name="ishighcontrastmode"></a>AFX_GLOBAL_DATA:: IsHighContrastMode

Indica se as imagens são exibidas no momento em alto contraste.
```
BOOL IsHighContrastMode() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se as imagens forem exibidas no momento em modo de alto contraste preto ou branco; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

No modo preto de alto contraste, as bordas voltadas para a luz são brancas e o plano de fundo é preto. No modo de alto contraste em branco, as bordas voltadas para a luz são pretas e o plano de fundo é branco.

## <a name="iswindowslayersupportavailable"></a>AFX_GLOBAL_DATA:: IsWindowsLayerSupportAvailable

Indica se o sistema operacional dá suporte a janelas em camadas.

```
BOOL IsWindowsLayerSupportAvailable() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se houver suporte para janelas em camadas; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se houver suporte para janelas em camadas, os marcadores de *encaixe inteligentes* usarão janelas em camadas.

## <a name="m_busebuiltin32biticons"></a>AFX_GLOBAL_DATA:: m_bUseBuiltIn32BitIcons

Indica se a estrutura usa ícones ou ícones de cor de 32 bits predefinidos de uma resolução mais baixa.

```
BOOL  m_bUseBuiltIn32BitIcons;
```

### <a name="remarks"></a>Comentários

VERDADEIRO especifica que a estrutura usa ícones de cor de 32 bits; FALSE especifica ícones de resolução inferior. O Construtor `AFX_GLOBAL_DATA::AFX_GLOBAL_DATA` inicializa esse membro como TRUE.

Esse membro deve ser definido na inicialização do aplicativo.

## <a name="m_busesystemfont"></a>AFX_GLOBAL_DATA:: m_bUseSystemFont

Indica se uma fonte do sistema é usada para menus, barras de ferramentas e faixas de faixa.

```
BOOL m_bUseSystemFont;
```

### <a name="remarks"></a>Comentários

VERDADEIRO especifica a utilização de uma fonte do sistema; caso contrário, FALSE. O Construtor `AFX_GLOBAL_DATA::AFX_GLOBAL_DATA` inicializa esse membro como FALSE.

O teste desse membro não é a única maneira de a estrutura determinar a fonte a ser usada. O método `AFX_GLOBAL_DATA::UpdateFonts` também testa fontes padrão e alternativas para determinar quais estilos visuais estão disponíveis para serem aplicados a menus, barras de ferramentas e faixas de faixa.

## <a name="m_hcurhand"></a>AFX_GLOBAL_DATA:: m_hcurHand

Armazena o identificador para o cursor à mão.

```
HCURSOR m_hcurHand;
```

## <a name="m_hcurstretch"></a>AFX_GLOBAL_DATA:: m_hcurStretch

Armazena o identificador do cursor de ampliação horizontal.

```
HCURSOR m_hcurStretch;
```

## <a name="m_hcurstretchvert"></a>AFX_GLOBAL_DATA:: m_hcurStretchVert

Armazena o identificador do cursor de ampliação vertical.

```
HCURSOR m_hcurStretchVert;
```

## <a name="m_hicontool"></a>AFX_GLOBAL_DATA:: m_hiconTool

Armazena o identificador para o ícone de ferramenta.

```
HICON m_hiconTool;
```

## <a name="m_nautohidetoolbarmargin"></a>AFX_GLOBAL_DATA:: m_nAutoHideToolBarMargin

Especifica o deslocamento da barra de ferramentas de AutoOcultar da extrema esquerda para o lado esquerdo da barra de encaixe.

```
int  m_nAutoHideToolBarMargin;
```

### <a name="remarks"></a>Comentários

O construtor de `AFX_GLOBAL_DATA::AFX_GLOBAL_DATA` inicializa esse membro para 4 pixels.

## <a name="m_nautohidetoolbarspacing"></a>AFX_GLOBAL_DATA:: m_nAutoHideToolBarSpacing

Especifica a lacuna entre as barras de ferramentas de AutoOcultar.

```
int   m_nAutoHideToolBarSpacing;
```

### <a name="remarks"></a>Comentários

O Construtor `AFX_GLOBAL_DATA::AFX_GLOBAL_DATA` inicializa esse membro para 14 pixels.

## <a name="m_ndragframethicknessdock"></a>AFX_GLOBAL_DATA:: m_nDragFrameThicknessDock

Especifica a espessura do quadro de arrastar que é usado para indicar o estado encaixado.

```
int  m_nDragFrameThicknessDock;
```

### <a name="remarks"></a>Comentários

O Construtor `AFX_GLOBAL_DATA::AFX_GLOBAL_DATA` inicializa esse membro para 3 pixels.

## <a name="m_ndragframethicknessfloat"></a>AFX_GLOBAL_DATA:: m_nDragFrameThicknessFloat

Especifica a espessura do quadro de arrastar que é usado para indicar o estado flutuante.

```
int  m_nDragFrameThicknessFloat;
```

### <a name="remarks"></a>Comentários

O construtor de `AFX_GLOBAL_DATA::AFX_GLOBAL_DATA` inicializa esse membro para 4 pixels.

## <a name="onsettingchange"></a>AFX_GLOBAL_DATA:: OnSettingChange

Detecta o estado atual da animação de menu da área de trabalho e dos recursos de AutoOcultar da barra de tarefas.

```
void OnSettingChange();
```

### <a name="remarks"></a>Comentários

Esse método define variáveis de estrutura para o estado de determinados atributos da área de trabalho do usuário. Esse método detecta o estado atual da animação do menu, fade menu e recursos de AutoOcultar da barra de tarefas.

## <a name="registerwindowclass"></a>AFX_GLOBAL_DATA:: RegisterWindowClass

Registra a classe de janela do MFC especificada.

```
CString RegisterWindowClass(LPCTSTR lpszClassNamePrefix);
```

### <a name="parameters"></a>parâmetros

*lpszClassNamePrefix*<br/>
no O nome da classe de janela a ser registrada.

### <a name="return-value"></a>Valor retornado

O nome qualificado da classe registrada se esse método tiver sucesso; caso contrário, uma [exceção de recurso](exception-processing.md#afxthrowresourceexception).

### <a name="remarks"></a>Comentários

O valor de retorno é uma lista delimitada por dois-pontos da cadeia de caracteres do parâmetro *lpszClassNamePrefix* e as representações de texto hexadecimal dos identificadores da instância do aplicativo atual; o cursor do aplicativo, que é o cursor de seta cujo identificador é IDC_ARROW; e o pincel de plano de fundo. Para obter mais informações sobre como registrar classes de janela MFC, consulte [AfxRegisterClass](../../mfc/reference/application-information-and-management.md#afxregisterclass).

## <a name="resume"></a>AFX_GLOBAL_DATA:: retomar

Reinicializa os ponteiros de função interna que acessam os métodos que dão suporte a temas e estilos visuais do Windows.

```
BOOL Resume();
```

### <a name="return-value"></a>Valor retornado

TRUE se esse método tiver sucesso; caso contrário, FALSE. No modo de depuração, esse método é declarado se esse método não for bem-sucedido.

### <a name="remarks"></a>Comentários

Esse método é chamado quando a estrutura recebe a mensagem de [WM_POWERBROADCAST](/windows/win32/Power/wm-powerbroadcast) .

## <a name="setlayeredattrib"></a>AFX_GLOBAL_DATA:: SetLayeredAttrib

Fornece uma maneira simples de chamar o método [SetLayeredWindowAttributes](/windows/win32/api/winuser/nf-winuser-setlayeredwindowattributes) do Windows.

```
BOOL SetLayeredAttrib(
    HWND hwnd,
    COLORREF crKey,
    BYTE bAlpha,
    DWORD dwFlags);
```

### <a name="parameters"></a>parâmetros

*HWND*<br/>
no Identificador para a janela em camadas.

*crKey*<br/>
no A chave de cor de transparência que o [Gerenciador de janelas da área de trabalho](/windows/win32/dwm/dwm-overview) usa para compor a janela em camadas.

*bAlpha*<br/>
no O valor alfa que é usado para descrever a opacidade da janela em camadas.

*dwFlags*<br/>
no Uma combinação de bits (ou) de sinalizadores que especifica quais parâmetros de método usar. Especifique LWA_COLORKEY para usar o parâmetro *crKey* como a cor de transparência. Especifique LWA_ALPHA para usar o parâmetro *bAlpha* para determinar a opacidade da janela em camadas.

### <a name="return-value"></a>Valor retornado

TRUE se esse método tiver sucesso; caso contrário, FALSE.

## <a name="setmenufont"></a>AFX_GLOBAL_DATA:: SetMenuFont

Cria a fonte lógica especificada.

```
BOOL SetMenuFont(
    LPLOGFONT lpLogFont,
    BOOL bHorz);
```

### <a name="parameters"></a>parâmetros

*lpLogFont*<br/>
no Ponteiro para uma estrutura que contém os atributos de uma fonte.

*bHorz*<br/>
no TRUE para especificar que o texto é executado horizontalmente; FALSE para especificar que o texto é executado verticalmente.

### <a name="return-value"></a>Valor retornado

TRUE se esse método tiver sucesso; caso contrário, FALSE. No modo de depuração, esse método é declarado se esse método não for bem-sucedido.

### <a name="remarks"></a>Comentários

Esse método cria uma fonte horizontal regular, uma fonte sublinhada e uma fonte em negrito que é usada em itens de menu padrão. Esse método cria, opcionalmente, uma fonte vertical regular. Para obter mais informações sobre fontes lógicas, consulte [CFont:: CreateFontIndirect](../../mfc/reference/cfont-class.md#createfontindirect).

## <a name="updatefonts"></a>AFX_GLOBAL_DATA:: UpdateFonts

Reintializes as fontes lógicas que são usadas pela estrutura.

```
void UpdateFonts();
```

### <a name="remarks"></a>Comentários

Para obter mais informações sobre fontes lógicas, consulte `CFont::CreateFontIndirect`.

## <a name="updatesyscolors"></a>AFX_GLOBAL_DATA:: UpdateSysColors

Inicializa as cores, a intensidade da cor, os pincéis, as canetas e as imagens usadas pela estrutura.

```
void UpdateSysColors();
```

## <a name="biswindows7"></a>AFX_GLOBAL_DATA:: bIsWindows7

Indica se o aplicativo está sendo executado no Windows 7 ou superior.

```
BOOL bIsWindows7;
```

## <a name="clractivecaptiongradient"></a>AFX_GLOBAL_DATA:: clrActiveCaptionGradient

Especifica a cor do gradiente da legenda ativa. Geralmente usado para painéis de encaixe.

```
COLORREF clrActiveCaptionGradient;
```

## <a name="clrinactivecaptiongradient"></a>AFX_GLOBAL_DATA:: clrInactiveCaptionGradient

Especifica a cor do gradiente da legenda inativa. Geralmente usado para painéis de encaixe.

```
COLORREF clrInactiveCaptionGradient;
```

## <a name="getitaskbarlist"></a>AFX_GLOBAL_DATA:: GetITaskbarList

Cria e armazena no dados globais um ponteiro para a interface `ITaskBarList`.

```
ITaskbarList *GetITaskbarList();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a interface de `ITaskbarList` se a criação de um objeto de lista da barra de tarefas for realizada com sucesso; NULL se a criação falhar ou se o sistema operacional atual for menor do que o Windows 7.

## <a name="getitaskbarlist3"></a>AFX_GLOBAL_DATA:: GetITaskbarList3

Cria e armazena no dados globais um ponteiro para a interface `ITaskBarList3`.

```
ITaskbarList3 *GetITaskbarList3();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a interface de `ITaskbarList3` se a criação de um objeto de lista da barra de tarefas for realizada com sucesso; NULL se a criação falhar ou se o sistema operacional atual for menor do que o Windows 7.

## <a name="getshellautohidebars"></a>AFX_GLOBAL_DATA:: GetShellAutohideBars

Determina as posições das barras de ocultar automaticamente do Shell.

```
int GetShellAutohideBars();
```

### <a name="return-value"></a>Valor retornado

Um valor inteiro com sinalizadores codificados que especificam posições de barras de ocultar automaticamente. Ele pode combinar os seguintes valores: AFX_AUTOHIDE_BOTTOM, AFX_AUTOHIDE_TOP, AFX_AUTOHIDE_LEFT AFX_AUTOHIDE_RIGHT.

## <a name="releasetaskbarrefs"></a>AFX_GLOBAL_DATA:: ReleaseTaskBarRefs

Libera interfaces obtidas por meio dos métodos `GetITaskbarList` e `GetITaskbarList3`.

```
void ReleaseTaskBarRefs();
```

## <a name="shellcreateitemfromparsingname"></a>AFX_GLOBAL_DATA:: ShellCreateItemFromParsingName

Cria e inicializa um objeto de item de Shell a partir de um nome de análise.

```
HRESULT ShellCreateItemFromParsingName(
    PCWSTR pszPath,
    IBindCtx *pbc,
    REFIID riid,
    void **ppv);
```

### <a name="parameters"></a>parâmetros

*pszPath*<br/>
no Um ponteiro para um nome de exibição.

*pbc*<br/>
Um ponteiro para um contexto de associação que controla a operação de análise.

*riid*<br/>
Uma referência a uma ID de interface.

*ppv*<br/>
fora Quando essa função retorna, contém o ponteiro de interface solicitado em *riid*. Normalmente, isso será `IShellItem` ou `IShellItem2`.

### <a name="return-value"></a>Valor retornado

Retorna S_OK se obtiver êxito; caso contrário, será um valor de erro.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../hierarchy-chart.md)<br/>
[Estruturas, estilos, retornos de chamada e mapas de mensagem](structures-styles-callbacks-and-message-maps.md)<br/>
[COLORREF](/windows/win32/gdi/colorref)<br/>
[Partes e Estados](/windows/win32/controls/parts-and-states)<br/>
[CDC::D rawText](cdc-class.md#drawtext)<br/>
[DrawThemeTextEx](/windows/win32/api/uxtheme/nf-uxtheme-drawthemetextex)<br/>
[Gerenciador de Janelas da Área de Trabalho](/windows/win32/dwm/dwm-overview)<br/>
[Habilitar e controlar a composição do DWM](/windows/win32/dwm/composition-ovw)<br/>
[Automação de interface do usuário e Acessibilidade Ativa da Microsoft](/dotnet/framework/ui-automation/ui-automation-and-microsoft-active-accessibility)<br/>
[Função GetSysColor](/windows/win32/api/winuser/nf-winuser-getsyscolor)<br/>
[GetSysColorBrush](/windows/win32/api/winuser/nf-winuser-getsyscolorbrush)<br/>
[Estrutura NONCLIENTMETRICS](/windows/win32/api/winuser/ns-winuser-nonclientmetricsw)<br/>
[AfxRegisterClass](application-information-and-management.md#afxregisterclass)<br/>
[AfxThrowResourceException](exception-processing.md#afxthrowresourceexception)<br/>
[SetLayeredWindowAttributes](/windows/win32/api/winuser/nf-winuser-setlayeredwindowattributes)
