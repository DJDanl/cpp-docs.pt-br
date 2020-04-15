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
- AFXGLOBALS/AFX_GLOBAL_DATA::InitD2D
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
ms.openlocfilehash: 60f7513075e8da7e17f2113c01b954af5a690aaf
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81363675"
---
# <a name="afx_global_data-structure"></a>Estrutura AFX_GLOBAL_DATA

A `AFX_GLOBAL_DATA` estrutura contém campos e métodos usados para gerenciar a estrutura ou personalizar a aparência e o comportamento de sua aplicação.

## <a name="syntax"></a>Sintaxe

```
struct AFX_GLOBAL_DATA
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|`AFX_GLOBAL_DATA::AFX_GLOBAL_DATA`|Constrói uma `AFX_GLOBAL_DATA` estrutura.|
|`AFX_GLOBAL_DATA::~AFX_GLOBAL_DATA`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[AFX_GLOBAL_DATA::CleanUp](#cleanup)|Libera recursos que são alocados pelo framework, como pincéis, fontes e DLLs.|
|[AFX_GLOBAL_DATA::D2D1MakeRotateMatrix](#d2d1makerotatematrix)|Cria uma transformação de rotação que gira por um ângulo especificado em torno de um ponto especificado.|
|[AFX_GLOBAL_DATA::DrawParentBackground](#drawparentbackground)|Desenha a tela de fundo do pai de um controle na área especificada.|
|[AFX_GLOBAL_DATA::DrawTextOnGlass](#drawtextonglass)|Desenha o texto especificado no estilo visual do tema especificado.|
|[AFX_GLOBAL_DATA::ExcludeTag](#excludetag)|Remove o par de tag XML especificado de um buffer especificado.|
|[AFX_GLOBAL_DATA::GetColor](#getcolor)|Recupera a cor atual do elemento de interface de usuário especificado.|
|[AFX_GLOBAL_DATA::GetDirect2dFactory](#getdirect2dfactory)|Retorna um ponteiro `ID2D1Factory` para a interface armazenada nos dados globais. Se a interface não for inicializada, ela será criada e tiver os parâmetros padrão.|
|[AFX_GLOBAL_DATA::GetHandCursor](#gethandcursor)|Recupera o cursor predefinido que se assemelha a `IDC_HAND`uma mão e cujo identificador é .|
|[AFX_GLOBAL_DATA::GetITaskbarList](#getitaskbarlist)|Cria e armazena nos dados globais um ponteiro para a interface ITaskBarList.|
|[AFX_GLOBAL_DATA::GetITaskbarList3](#getitaskbarlist3)|Cria e armazena nos dados globais um ponteiro para a interface ITaskBarList3.|
|[AFX_GLOBAL_DATA::GetNonClientMetrics](#getnonclientmetrics)|Recupera as métricas associadas à área não cliente de janelas não minimizadas.|
|[AFX_GLOBAL_DATA::GetShellAutohideBars](#getshellautohidebars)|Determina posições das barras de ocultação automática Shell.|
|[AFX_GLOBAL_DATA::GetTextHeight](#gettextheight)|Recupera a altura dos caracteres de texto na fonte atual.|
|[AFX_GLOBAL_DATA::GetWICFactory](#getwicfactory)|Retorna um ponteiro `IWICImagingFactory` para a interface armazenada nos dados globais. Se a interface não for inicializada, ela será criada e tiver os parâmetros padrão.|
|[AFX_GLOBAL_DATA::GetWriteFactory](#getwritefactory)|Retorna um ponteiro `IDWriteFactory` para a interface armazenada nos dados globais. Se a interface não for inicializada, ela será criada e tiver os parâmetros padrão.|
|[AFX_GLOBAL_DATA::InitD2D](#initd2d)|Inicializa `D2D`, `DirectWrite`e `WIC` fábricas. Chame este método antes que a janela principal seja inicializada.|
|[AFX_GLOBAL_DATA::Is32BitIcons](#is32biticons)|Indica se ícones predefinidos de 32 bits são suportados.|
|[AFX_GLOBAL_DATA::IsD2DInitialized](#isd2dinitialized)|Determina se `D2D` o foi inicializado.|
|[AFX_GLOBAL_DATA::IsDwmCompositionEnabled](#isdwmcompositionenabled)|Fornece uma maneira simples de chamar o método [Windows DwmIsCompositionEnabled.](/windows/win32/api/dwmapi/nf-dwmapi-dwmiscompositionenabled)|
|[AFX_GLOBAL_DATA::IsHighContrastMode](#ishighcontrastmode)|Indica se as imagens são exibidas atualmente em alto contraste.|
|[AFX_GLOBAL_DATA::OnSettingChange](#onsettingchange)|Detecta o estado atual dos recursos de animação de menu e barra de tarefas da barra de tarefas.|
|[AFX_GLOBAL_DATA::RegisterWindowClass](#registerwindowclass)|Registra a classe de janela MFC especificada.|
|[AFX_GLOBAL_DATA::ReleaseTaskBarRefs](#releasetaskbarrefs)|Libera interfaces obtidas através dos métodos GetITaskbarList e GetITaskbarList3.|
|[AFX_GLOBAL_DATA::Resume](#resume)|Reinicializa ponteiros de função interna que acessam métodos que suportam temas do Windows [e estilos visuais](/windows/win32/Controls/visual-styles-overview).|
|[AFX_GLOBAL_DATA::SetLayeredAttrib](#setlayeredattrib)|Fornece uma maneira simples de chamar o método [SetLayeredWindowAttributes do](/windows/win32/api/winuser/nf-winuser-setlayeredwindowattributes) Windows.|
|[AFX_GLOBAL_DATA::SetMenuFont](#setmenufont)|Cria a fonte lógica especificada.|
|[AFX_GLOBAL_DATA::ShellCreateItemFromParsingName](#shellcreateitemfromparsingname)|Cria e inicializa um objeto de item Shell a partir de um nome de análise.|
|[AFX_GLOBAL_DATA::UpdateFonts](#updatefonts)|Reintializa as fontes lógicas que são usadas pela estrutura.|
|[AFX_GLOBAL_DATA::UpdateSysColors](#updatesyscolors)|Inicializa as cores, profundidade de cor, pincéis, canetas e imagens que são usadas pela estrutura.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[AFX_GLOBAL_DATA::EnableAccessibilitySupport](#enableaccessibilitysupport)|Ativa ou desativa o suporte ao Microsoft Active Accessibility. A Acessibilidade Ativa fornece métodos confiáveis para expor informações sobre elementos de interface do usuário.|
|[AFX_GLOBAL_DATA::IsAccessibilitySupport](#isaccessibilitysupport)|Indica se o suporte ao Microsoft Active Accessibility está ativado.|
|[AFX_GLOBAL_DATA::IsWindowsLayerSupportAvailable](#iswindowslayersupportavailable)|Indica se o sistema operacional suporta janelas em camadas.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[AFX_GLOBAL_DATA::bIsOSAlphaBlendingSupport](#bisosalphablendingsupport)|Indica se o sistema operacional atual suporta a mistura alfa.|
|[AFX_GLOBAL_DATA::bIsWindows7](#biswindows7)|Indica se o aplicativo está sendo executado no sistema operacional Windows 7 ou superior|
|[AFX_GLOBAL_DATA::clrActiveCaptionGradient](#clractivecaptiongradient)|Especifica a cor gradiente da legenda ativa. Geralmente usado para encaixe de painéis.|
|[AFX_GLOBAL_DATA::clrInactiveCaptionGradient](#clrinactivecaptiongradient)|Especifica a cor gradiente da legenda ativa inativa. Geralmente usado para encaixe de painéis.|
|[AFX_GLOBAL_DATA::m_bUseBuiltIn32BitIcons](#m_busebuiltin32biticons)|Indica se a estrutura usa ícones de cores predefinidos de 32 bits ou ícones de uma resolução inferior.|
|[AFX_GLOBAL_DATA::m_bUseSystemFont](#m_busesystemfont)|Indica se uma fonte do sistema é usada para menus, barras de ferramentas e fitas.|
|[AFX_GLOBAL_DATA::m_hcurHand](#m_hcurhand)|Armazena a alça do cursor de mão.|
|[AFX_GLOBAL_DATA::m_hcurStretch](#m_hcurstretch)|Armazena a alça para o cursor de estiramento horizontal.|
|[AFX_GLOBAL_DATA::m_hcurStretchVert](#m_hcurstretchvert)|Armazena a alça para o cursor de estiramento vertical.|
|[AFX_GLOBAL_DATA::m_hiconTool](#m_hicontool)|Armazena a alça para o ícone da ferramenta.|
|[AFX_GLOBAL_DATA::m_nAutoHideToolBarMargin](#m_nautohidetoolbarmargin)|Especifica o deslocamento da barra de ferramentas de ocultação automática mais à esquerda para o lado esquerdo da barra de acoplamento.|
|[AFX_GLOBAL_DATA::m_nAutoHideToolBarSpacing](#m_nautohidetoolbarspacing)|Especifica a lacuna entre as barras de ferramentas de ocultação automática.|
|[AFX_GLOBAL_DATA::m_nDragFrameThicknessDock](#m_ndragframethicknessdock)|Especifica a espessura do quadro de arrasto que é usado para comunicar o estado ancorado.|
|[AFX_GLOBAL_DATA::m_nDragFrameThicknessFloat](#m_ndragframethicknessfloat)|Especifica a espessura do quadro de arrasto que é usado para comunicar o estado flutuante.|

### <a name="remarks"></a>Comentários

A maioria dos `AFX_GLOBAL_DATA` dados na estrutura é inicializada quando sua aplicação é iniciada.

### <a name="inheritance-hierarchy"></a>Hierarquia de herança

`AFX_GLOBAL_DATA`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxglobals.h

## <a name="afx_global_databisosalphablendingsupport"></a><a name="bisosalphablendingsupport"></a>AFX_GLOBAL_DATA:bIsOSAlphaBlendingSupport

Indica se o sistema operacional suporta a mistura alfa.

```
BOOL  bIsOSAlphaBlendingSupport;
```

### <a name="remarks"></a>Comentários

TRUE indica que a mistura alfa é suportada; caso contrário, FALSE.

## <a name="afx_global_datacleanup"></a><a name="cleanup"></a>AFX_GLOBAL_DATA::Limpeza

Libera recursos que são alocados pelo framework, como pincéis, fontes e DLLs.

```
void CleanUp();
```

## <a name="afx_global_datad2d1makerotatematrix"></a><a name="d2d1makerotatematrix"></a>AFX_GLOBAL_DATA::D2D1MakeRotateMatrix

Cria uma transformação de rotação que gira por um ângulo especificado em torno de um ponto especificado.

```
HRESULT D2D1MakeRotateMatrix(
    FLOAT angle,
    D2D1_POINT_2F center,
    D2D1_MATRIX_3X2_F *matrix);
```

### <a name="parameters"></a>Parâmetros

*angle*<br/>
O ângulo da rotação no sentido horário, em graus.

*centro*<br/>
O ponto sobre o qual girar.

*Matriz*<br/>
Quando este método retorna, contém a nova transformação de rotação. Você deve alocar armazenamento para este parâmetro.

### <a name="return-value"></a>Valor retornado

O retorno S_OK se for bem-sucedido, ou um valor de erro de outra forma.

## <a name="afx_global_datadrawparentbackground"></a><a name="drawparentbackground"></a>AFX_GLOBAL_DATA::DrawParentBackground

Desenha a tela de fundo do pai de um controle na área especificada.

```
BOOL DrawParentBackground(
    CWnd* pWnd,
    CDC* pDC,
    LPRECT lpRect = NULL);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
[em] Ponteiro para a janela de um controle.

*pDC*<br/>
[em] Ponteiro para um contexto de dispositivo.

*Lprect*<br/>
[em] Ponteiro para um retângulo que limita a área a desenhar. O valor padrão é NULL.

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

## <a name="afx_global_datadrawtextonglass"></a><a name="drawtextonglass"></a>AFX_GLOBAL_DATA::DrawTextOnGlass

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

### <a name="parameters"></a>Parâmetros

*hTheme*<br/>
[em] Manuseie os dados temáticos de uma janela, ou NULL. O quadro usa o tema especificado para desenhar o texto se este parâmetro não for NULO e os temas forem suportados. Caso contrário, o quadro não usa um tema para desenhar o texto.

Use o método [OpenThemeData](/windows/win32/api/uxtheme/nf-uxtheme-openthemedata) para criar um HTHEME.

*pDC*<br/>
[em] Ponteiro para um contexto de dispositivo.

*iPartId*<br/>
[em] A parte de controle que tem a aparência de texto desejada. Para obter mais informações, consulte a coluna Partes da tabela em [Partes e Estados](/windows/win32/controls/parts-and-states). Se esse valor for 0, o texto será desenhado na fonte padrão ou uma fonte selecionada no contexto do dispositivo.

*iStateId*<br/>
[em] O estado de controle que tem a aparência de texto desejada. Para obter mais informações, consulte a coluna Estados da tabela em [Partes e Estados](/windows/win32/controls/parts-and-states).

*strText*<br/>
[em] O texto para desenhar.

*Rect*<br/>
[em] O limite da área em que o texto especificado é desenhado.

*dwFlags*<br/>
[em] Uma combinação bitwise (OR) de sinalizadores que especificam como o texto especificado é desenhado.

Se o parâmetro *hTheme* for `NULL` ou se os temas não forem suportados e habilitados, o parâmetro *nFormat* do método [CDC::DrawText](../../mfc/reference/cdc-class.md#drawtext) descreve as bandeiras válidas. Se os temas forem suportados, o parâmetro *dwFlags* do método [DrawThemeTextEx](/windows/win32/api/uxtheme/nf-uxtheme-drawthemetextex) descreverá as bandeiras válidas.

*nGlowSize*<br/>
[em] O tamanho de um efeito de brilho que é desenhado no fundo antes de desenhar o texto especificado. O valor padrão é 0.

*clrText*<br/>
[em] A cor em que o texto especificado é desenhado. O valor padrão é a cor padrão.

### <a name="return-value"></a>Valor retornado

VERDADE se um tema for usado para desenhar o texto especificado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Um tema define o estilo visual de uma aplicação. Um tema não é usado para desenhar o texto se o parâmetro *hTheme* for NULL ou se o método [DrawThemeTextEx](/windows/win32/api/uxtheme/nf-uxtheme-drawthemetextex) não for suportado ou se a composição do DWM [(Desktop Window Manager)](/windows/win32/dwm/dwm-overview) estiver desativada.

## <a name="afx_global_dataenableaccessibilitysupport"></a><a name="enableaccessibilitysupport"></a>AFX_GLOBAL_DATA::Habilitar o suporte à acessibilidade

Ativa ou desativa o suporte ao Microsoft Active Accessibility.

```
void EnableAccessibilitySupport(BOOL bEnable=TRUE);
```

### <a name="parameters"></a>Parâmetros

*Benable*<br/>
[em] TRUE para habilitar suporte à acessibilidade; FALSO para desativar o suporte de acessibilidade. O valor padrão é TRUE.

### <a name="remarks"></a>Comentários

Active Accessibility é uma tecnologia baseada em COM que melhora a forma como os programas e o sistema operacional Windows trabalham em conjunto com produtos de tecnologia assistiva. Ele fornece métodos confiáveis para expor informações sobre elementos de interface do usuário. No entanto, um modelo de acessibilidade mais novo chamado Microsoft UI Automation já está disponível. Para uma comparação das duas tecnologias, consulte [Automação de ICarros e Acessibilidade Ativa da Microsoft](/dotnet/framework/ui-automation/ui-automation-and-microsoft-active-accessibility).

Use o método [AFX_GLOBAL_DATA::IsAccessibilitySupport](#isaccessibilitysupport) para determinar se o suporte ao Microsoft Active Accessibility está ativado.

## <a name="afx_global_dataexcludetag"></a><a name="excludetag"></a>AFX_GLOBAL_DATA::Excluatag

Remove o par de tag XML especificado de um buffer especificado.

```
BOOL ExcludeTag(
    CString& strBuffer,
    LPCTSTR lpszTag,
    CString& strTag,
    BOOL bIsCharsList = FALSE);
```

### <a name="parameters"></a>Parâmetros

*strBuffer*<br/>
[em] Um tampão de texto.

*Lpsztag*<br/>
[em] O nome de um par de tags XML de abertura e fechamento.

*strTag*<br/>
[fora] Quando este método retorna, o parâmetro *strTag* contém o texto que está entre as tags XML de abertura e fechamento que são nomeadas pelo parâmetro *lpszTag.* Qualquer espaço branco de liderança ou de arrasto é aparado a partir do resultado.

*bIsCharsList*<br/>
[em] VERDADEIRO converter símbolos para caracteres de fuga no parâmetro *strTag* em caracteres de fuga reais; FALSO para não realizar a conversão. O valor padrão é FALSO. Para obter mais informações, consulte Comentários.

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Um par de tags XML consiste em tags de abertura e fechamento nomeadas que indicam o início e o fim de uma execução de texto no buffer especificado. O parâmetro *strBuffer* especifica o buffer, e o parâmetro *lpszTag* especifica o nome das tags XML.

Use os símbolos na tabela a seguir para codificar um conjunto de caracteres de fuga no buffer especificado. Especifique TRUE para o parâmetro *bIsCharsList* para converter os símbolos no parâmetro *strTag* em caracteres de fuga reais. A tabela a seguir usa a [macro _T()](../../c-runtime-library/data-type-mappings.md) para especificar o símbolo e escapar das strings do caractere.

|Símbolo|Caractere de escape|
|------------|----------------------|
|_T("\\\t")|_T("\t")|
|_T("\\\n")|_T("\n")|
|_T("\\\r")|_T("\r")|
|_T("\\\b")|_T("\b")|
|_T ("LT")|_T(\<")|
|_T("GT")|_T(">")|
|_T("AMP")|_T("&")|

## <a name="afx_global_datagetcolor"></a><a name="getcolor"></a>AFX_GLOBAL_DATA::GetColor

Recupera a cor atual do elemento de interface de usuário especificado.

```
COLORREF GetColor(int nColor);
```

### <a name="parameters"></a>Parâmetros

*nColor*<br/>
[em] Um valor que especifica um elemento de interface de usuário cuja cor é recuperada. Para obter uma lista de valores válidos, consulte o parâmetro *nIndex* do método [GetSysColor.](/windows/win32/api/winuser/nf-winuser-getsyscolor)

### <a name="return-value"></a>Valor retornado

O valor de cor RGB do elemento de interface de usuário especificado. Para obter mais informações, consulte Comentários.

### <a name="remarks"></a>Comentários

Se o parâmetro *nColor* estiver fora de alcance, o valor de retorno será zero. Como zero também é um valor RGB válido, você não pode usar este método para determinar se uma cor do sistema é suportada pelo sistema operacional atual. Em vez disso, use o método [GetSysColorBrush,](/windows/win32/api/winuser/nf-winuser-getsyscolorbrush) que retorna NULL se a cor não for suportada.

## <a name="afx_global_datagetdirect2dfactory"></a><a name="getdirect2dfactory"></a>AFX_GLOBAL_DATA:GetDirect2dFactory

Retorna um ponteiro para a interface ID2D1Factory armazenada nos dados globais. Se a interface não for inicializada, ela será criada e tiver os parâmetros padrão.

```
ID2D1Factory* GetDirect2dFactory();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para interface ID2D1Factory se a criação de uma fábrica for bem-sucedida ou NULL se a criação falhar ou o sistema de operação atual não tiver suporte a D2D.

## <a name="afx_global_datagethandcursor"></a><a name="gethandcursor"></a>AFX_GLOBAL_DATA:GetHandCursor

Recupera o cursor predefinido que se assemelha a uma mão e cujo identificador é IDC_HAND.

```
HCURSOR GetHandCursor();
```

### <a name="return-value"></a>Valor retornado

A alça do cursor de mão.

## <a name="afx_global_datagetnonclientmetrics"></a><a name="getnonclientmetrics"></a>AFX_GLOBAL_DATA:GetNonClientMetrics

Recupera as métricas associadas à área não cliente de janelas não minimizadas.

```
BOOL GetNonClientMetrics(NONCLIENTMETRICS& info);
```

### <a name="parameters"></a>Parâmetros

*Informação*<br/>
[dentro, fora] Uma [estrutura NÃO-CLIENTMETRICS](/windows/win32/api/winuser/ns-winuser-nonclientmetricsw) que contém as métricas escaláveis associadas à área não cliente de uma janela não minimizada.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se este método for bem sucedido; caso contrário, FALSE.

## <a name="afx_global_datagettextheight"></a><a name="gettextheight"></a>AFX_GLOBAL_DATA::GetTextHeight

Recupera a altura dos caracteres de texto na fonte atual.

```
int GetTextHeight(BOOL bHorz = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Bhorz*<br/>
[em] TRUE para recuperar a altura dos caracteres quando o texto é executado horizontalmente; FALSE para recuperar a altura dos caracteres quando o texto é executado verticalmente. O valor padrão é TRUE.

### <a name="return-value"></a>Valor retornado

A altura da fonte atual, que é medida de seu ascendente para seu descendente.

## <a name="afx_global_datagetwicfactory"></a><a name="getwicfactory"></a>AFX_GLOBAL_DATA::GetWICFactory

Retorna um ponteiro para a interface IWICImagingFactory que é armazenado nos dados globais. Se a interface não for inicializada, ela será criada e tiver os parâmetros padrão.

```
IWICImagingFactory* GetWICFactory();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para interface IWICImagingFactory se a criação de uma fábrica for bem sucedida ou NULL se a criação falhar ou o sistema de operação atual não tiver suporte wic.

## <a name="afx_global_datagetwritefactory"></a><a name="getwritefactory"></a>AFX_GLOBAL_DATA::GetWriteFactory

Retorna um ponteiro para a interface IDWriteFactory que é armazenado nos dados globais. Se a interface não for inicializada, ela será criada e tiver os parâmetros padrão.

```
IDWriteFactory* GetWriteFactory();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para interface IDWriteFactory se a criação de uma fábrica for bem sucedida ou NULA se a criação falhar ou o sistema de operação atual não tiver suporte ao DirectWrite.

## <a name="afx_global_datainitd2d"></a><a name="initd2d"></a>AFX_GLOBAL_DATA:InitD2D

Inicializa fábricas de D2D, DirectWrite e WIC. Chame este método antes que a janela principal seja inicializada.

```
BOOL InitD2D(
    D2D1_FACTORY_TYPE d2dFactoryType = D2D1_FACTORY_TYPE_SINGLE_THREADED,
    DWRITE_FACTORY_TYPE writeFactoryType = DWRITE_FACTORY_TYPE_SHARED);
```

### <a name="parameters"></a>Parâmetros

*d2dFactoryType*<br/>
O modelo de rosca da fábrica D2D e os recursos que ele cria.

*writeFactoryType*<br/>
Um valor que especifica se o objeto de fábrica de gravação será compartilhado ou isolado

### <a name="return-value"></a>Valor retornado

Retorna TRUE se as fábricas foram intilalizante, FALSE - caso contrário

## <a name="afx_global_datais32biticons"></a><a name="is32biticons"></a>AFX_GLOBAL_DATA:Is32BitIcons

Indica se ícones predefinidos de 32 bits são suportados.

```
BOOL Is32BitIcons() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se os ícones de 32 bits predefinidos forem suportados; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método retorna TRUE se a estrutura suportar ícones incorporados de 32 bits e se o sistema operacional suportar 16 bits por pixel ou mais, e se as imagens não forem exibidas em alto contraste.

## <a name="afx_global_dataisaccessibilitysupport"></a><a name="isaccessibilitysupport"></a>AFX_GLOBAL_DATA::Ésuporte de acessibilidade

Indica se o suporte ao Microsoft Active Accessibility está ativado.

```
BOOL IsAccessibilitySupport() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o suporte à acessibilidade estiver ativado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O Microsoft Active Accessibility foi a solução anterior para tornar os aplicativos acessíveis. Microsoft UI Automation é o novo modelo de acessibilidade do Microsoft Windows e destina-se a atender às necessidades de produtos de tecnologia assistiva e ferramentas de teste automatizadas.

Use o [método AFX_GLOBAL_DATA::Habilitar acessibilidadeDesuporte](#enableaccessibilitysupport) para ativar ou desativar o suporte à acessibilidade ativa.

## <a name="afx_global_dataisd2dinitialized"></a><a name="isd2dinitialized"></a>AFX_GLOBAL_DATA:IsD2DInitialized

Determina se o D2D foi inicializado

```
BOOL IsD2DInitialized() const;
```

### <a name="return-value"></a>Valor retornado

VERDADEIRO se D2D foi inicializado; caso contrário, FALSO.

## <a name="afx_global_dataisdwmcompositionenabled"></a><a name="isdwmcompositionenabled"></a>AFX_GLOBAL_DATA:IsDwmCompositionEnabled

Fornece uma maneira simples de chamar o método [Windows DwmIsCompositionEnabled.](/windows/win32/api/dwmapi/nf-dwmapi-dwmiscompositionenabled)

```
BOOL IsDwmCompositionEnabled();
```

### <a name="return-value"></a>Valor retornado

TRUE se a composição do Desktop [Window Manager](/windows/win32/dwm/dwm-overview) (DWM) estiver habilitada; caso contrário, FALSE.

## <a name="afx_global_dataishighcontrastmode"></a><a name="ishighcontrastmode"></a>AFX_GLOBAL_DATA::IsHighcontrastmode

Indica se as imagens são exibidas atualmente em alto contraste.

```
BOOL IsHighContrastMode() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se as imagens forem exibidas no modo preto ou branco de alto contraste; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

No modo preto de alto contraste, as bordas voltadas para a luz são brancas e o fundo é preto. No modo branco de alto contraste, as bordas voltadas para a luz são pretas e o fundo é branco.

## <a name="afx_global_dataiswindowslayersupportavailable"></a><a name="iswindowslayersupportavailable"></a>AFX_GLOBAL_DATA::ÉoSuporte de camadasdoWindowsDisponível

Indica se o sistema operacional suporta janelas em camadas.

```
BOOL IsWindowsLayerSupportAvailable() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se as janelas em camadas forem suportadas; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se as janelas em camadas forem suportadas, os marcadores *de encaixe inteligentes* usarão janelas em camadas.

## <a name="afx_global_datam_busebuiltin32biticons"></a><a name="m_busebuiltin32biticons"></a>AFX_GLOBAL_DATA:m_bUseBuiltIn32BitIcons

Indica se a estrutura usa ícones de cores predefinidos de 32 bits ou ícones de uma resolução inferior.

```
BOOL  m_bUseBuiltIn32BitIcons;
```

### <a name="remarks"></a>Comentários

True especifica que a estrutura usa ícones de cores de 32 bits; False especifica ícones de resolução mais baixa. O `AFX_GLOBAL_DATA::AFX_GLOBAL_DATA` construtor inicializa este membro para TRUE.

Este membro deve ser definido na inicialização do aplicativo.

## <a name="afx_global_datam_busesystemfont"></a><a name="m_busesystemfont"></a>AFX_GLOBAL_DATA:m_bUseSystemFont

Indica se uma fonte do sistema é usada para menus, barras de ferramentas e fitas.

```
BOOL m_bUseSystemFont;
```

### <a name="remarks"></a>Comentários

True especifica para usar uma fonte do sistema; caso contrário, FALSE. O `AFX_GLOBAL_DATA::AFX_GLOBAL_DATA` construtor inicializa este membro para FALSE.

Testar este membro não é a única maneira de a estrutura determinar a fonte a ser usada. O `AFX_GLOBAL_DATA::UpdateFonts` método também testa fontes padrão e alternativas para determinar quais estilos visuais estão disponíveis para serem aplicados em menus, barras de ferramentas e fitas.

## <a name="afx_global_datam_hcurhand"></a><a name="m_hcurhand"></a>AFX_GLOBAL_DATA:m_hcurHand

Armazena a alça do cursor de mão.

```
HCURSOR m_hcurHand;
```

## <a name="afx_global_datam_hcurstretch"></a><a name="m_hcurstretch"></a>AFX_GLOBAL_DATA:m_hcurStretch

Armazena a alça para o cursor de estiramento horizontal.

```
HCURSOR m_hcurStretch;
```

## <a name="afx_global_datam_hcurstretchvert"></a><a name="m_hcurstretchvert"></a>AFX_GLOBAL_DATA:m_hcurStretchVert

Armazena a alça para o cursor de estiramento vertical.

```
HCURSOR m_hcurStretchVert;
```

## <a name="afx_global_datam_hicontool"></a><a name="m_hicontool"></a>AFX_GLOBAL_DATA:m_hiconTool

Armazena a alça para o ícone da ferramenta.

```
HICON m_hiconTool;
```

## <a name="afx_global_datam_nautohidetoolbarmargin"></a><a name="m_nautohidetoolbarmargin"></a>AFX_GLOBAL_DATA:m_nAutoHideToolBarMargin

Especifica o deslocamento da barra de ferramentas de ocultação automática mais à esquerda para o lado esquerdo da barra de doca.

```
int  m_nAutoHideToolBarMargin;
```

### <a name="remarks"></a>Comentários

O `AFX_GLOBAL_DATA::AFX_GLOBAL_DATA` construtor inicializa este membro para 4 pixels.

## <a name="afx_global_datam_nautohidetoolbarspacing"></a><a name="m_nautohidetoolbarspacing"></a>AFX_GLOBAL_DATA:m_nAutoHideToolBarSpacing

Especifica a lacuna entre as barras de ferramentas de ocultação automática.

```
int   m_nAutoHideToolBarSpacing;
```

### <a name="remarks"></a>Comentários

O `AFX_GLOBAL_DATA::AFX_GLOBAL_DATA` construtor inicializa este membro para 14 pixels.

## <a name="afx_global_datam_ndragframethicknessdock"></a><a name="m_ndragframethicknessdock"></a>AFX_GLOBAL_DATA:m_nDragFrameThicknessDock

Especifica a espessura do quadro de arrasto que é usado para indicar o estado ancorado.

```
int  m_nDragFrameThicknessDock;
```

### <a name="remarks"></a>Comentários

O `AFX_GLOBAL_DATA::AFX_GLOBAL_DATA` construtor inicializa este membro para 3 pixels.

## <a name="afx_global_datam_ndragframethicknessfloat"></a><a name="m_ndragframethicknessfloat"></a>AFX_GLOBAL_DATA:m_nDragFrameThicknessFloat

Especifica a espessura do quadro de arrasto que é usado para indicar o estado flutuante.

```
int  m_nDragFrameThicknessFloat;
```

### <a name="remarks"></a>Comentários

O `AFX_GLOBAL_DATA::AFX_GLOBAL_DATA` construtor inicializa este membro para 4 pixels.

## <a name="afx_global_dataonsettingchange"></a><a name="onsettingchange"></a>AFX_GLOBAL_DATA::Alterações de configuração

Detecta o estado atual dos recursos de animação de menu e barra de tarefas da barra de tarefas.

```
void OnSettingChange();
```

### <a name="remarks"></a>Comentários

Este método define variáveis-quadro para o estado de certos atributos da área de trabalho do usuário. Este método detecta o estado atual da animação do menu, o desbotamento do menu e os recursos de ocultação automática da barra de tarefas.

## <a name="afx_global_dataregisterwindowclass"></a><a name="registerwindowclass"></a>AFX_GLOBAL_DATA::RegisterWindowClass

Registra a classe de janela MFC especificada.

```
CString RegisterWindowClass(LPCTSTR lpszClassNamePrefix);
```

### <a name="parameters"></a>Parâmetros

*lpszClassNamePrefix*<br/>
[em] O nome da turma da janela para registrar.

### <a name="return-value"></a>Valor retornado

O nome qualificado da classe registrada se este método for bem sucedido; caso contrário, uma [exceção de recursos.](exception-processing.md#afxthrowresourceexception)

### <a name="remarks"></a>Comentários

O valor de retorno é uma lista delimitada de cólon da seqüência de *parâmetros lpszClassNamePrefix* e as representações de texto hexadecimal das alças da instância atual do aplicativo; o cursor de aplicação, que é o cursor de seta cujo identificador é IDC_ARROW; e o pincel de fundo. Para obter mais informações sobre como registrar as classes de janela do MFC, consulte [AfxRegisterClass](../../mfc/reference/application-information-and-management.md#afxregisterclass).

## <a name="afx_global_dataresume"></a><a name="resume"></a>AFX_GLOBAL_DATA::Retomar

Reinicializa ponteiros de função interna que acessam métodos que suportam temas do Windows e estilos visuais.

```
BOOL Resume();
```

### <a name="return-value"></a>Valor retornado

VERDADEIRO se este método for bem sucedido; caso contrário, FALSE. No modo de depuração, este método afirma se este método não tiver sucesso.

### <a name="remarks"></a>Comentários

Esse método é chamado quando a estrutura recebe a [mensagem WM_POWERBROADCAST.](/windows/win32/Power/wm-powerbroadcast)

## <a name="afx_global_datasetlayeredattrib"></a><a name="setlayeredattrib"></a>AFX_GLOBAL_DATA:SetLayeredAttrib

Fornece uma maneira simples de chamar o método [SetLayeredWindowAttributes do](/windows/win32/api/winuser/nf-winuser-setlayeredwindowattributes) Windows.

```
BOOL SetLayeredAttrib(
    HWND hwnd,
    COLORREF crKey,
    BYTE bAlpha,
    DWORD dwFlags);
```

### <a name="parameters"></a>Parâmetros

*Hwnd*<br/>
[em] Manuseie a janela em camadas.

*crKey*<br/>
[em] A chave de cor de transparência que o [Gerenciador de Janelas da Área de Trabalho](/windows/win32/dwm/dwm-overview) usa para compor a janela em camadas.

*Balpha*<br/>
[em] O valor alfa que é usado para descrever a opacidade da janela em camadas.

*dwFlags*<br/>
[em] Uma combinação bitwise (OR) de sinalizadores que especificam quais parâmetros de método usar. Especifique LWA_COLORKEY de usar o parâmetro *crKey* como cor de transparência. Especifique LWA_ALPHA de usar o parâmetro *bAlpha* para determinar a opacidade da janela em camadas.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se este método for bem sucedido; caso contrário, FALSE.

## <a name="afx_global_datasetmenufont"></a><a name="setmenufont"></a>AFX_GLOBAL_DATA::SetMenufont

Cria a fonte lógica especificada.

```
BOOL SetMenuFont(
    LPLOGFONT lpLogFont,
    BOOL bHorz);
```

### <a name="parameters"></a>Parâmetros

*lpLogFont*<br/>
[em] Ponteiro para uma estrutura que contém os atributos de uma fonte.

*Bhorz*<br/>
[em] TRUE para especificar que o texto é executado horizontalmente; FALSO para especificar que o texto é executado verticalmente.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se este método for bem sucedido; caso contrário, FALSE. No modo de depuração, este método afirma se este método não tiver sucesso.

### <a name="remarks"></a>Comentários

Este método cria uma fonte horizontal regular, uma fonte sublinhada e uma fonte em negrito que é usada em itens de menu padrão. Este método cria opcionalmente uma fonte vertical regular. Para obter mais informações sobre fontes lógicas, consulte [CFont::CreateFontIndirect](../../mfc/reference/cfont-class.md#createfontindirect).

## <a name="afx_global_dataupdatefonts"></a><a name="updatefonts"></a>AFX_GLOBAL_DATA::UpdateFonts

Reintializa as fontes lógicas que são usadas pela estrutura.

```
void UpdateFonts();
```

### <a name="remarks"></a>Comentários

Para obter mais informações sobre `CFont::CreateFontIndirect`fontes lógicas, consulte .

## <a name="afx_global_dataupdatesyscolors"></a><a name="updatesyscolors"></a>AFX_GLOBAL_DATA::UpdateSysColors

Inicializa as cores, profundidade de cor, pincéis, canetas e imagens que são usadas pela estrutura.

```
void UpdateSysColors();
```

## <a name="afx_global_databiswindows7"></a><a name="biswindows7"></a>AFX_GLOBAL_DATA:bIsWindows7

Indica se o aplicativo está sendo executado no Windows 7 ou superior.

```
BOOL bIsWindows7;
```

## <a name="afx_global_dataclractivecaptiongradient"></a><a name="clractivecaptiongradient"></a>AFX_GLOBAL_DATA:clrActiveCaptionGradient

Especifica a cor gradiente da legenda ativa. Geralmente usado para encaixe de painéis.

```
COLORREF clrActiveCaptionGradient;
```

## <a name="afx_global_dataclrinactivecaptiongradient"></a><a name="clrinactivecaptiongradient"></a>AFX_GLOBAL_DATA:clrInactiveCaptionGradient

Especifica a cor gradiente da legenda inativa. Geralmente usado para encaixe de painéis.

```
COLORREF clrInactiveCaptionGradient;
```

## <a name="afx_global_datagetitaskbarlist"></a><a name="getitaskbarlist"></a>AFX_GLOBAL_DATA:GetITaskbarList

Cria e armazena nos dados globais um ponteiro para a `ITaskBarList` interface.

```
ITaskbarList *GetITaskbarList();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro `ITaskbarList` para a interface se a criação de um objeto de lista de barras de tarefas for bem-sucedida; NULL se a criação falhar ou se o sistema de operação atual for menor que o Windows 7.

## <a name="afx_global_datagetitaskbarlist3"></a><a name="getitaskbarlist3"></a>AFX_GLOBAL_DATA:GetITaskbarList3

Cria e armazena nos dados globais um ponteiro para a `ITaskBarList3` interface.

```
ITaskbarList3 *GetITaskbarList3();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro `ITaskbarList3` para a interface se a criação de um objeto de lista de barras de tarefas for bem-sucedida; NULL se a criação falhar ou se o sistema de operação atual for menor que o Windows 7.

## <a name="afx_global_datagetshellautohidebars"></a><a name="getshellautohidebars"></a>AFX_GLOBAL_DATA:GetShellAutohideBars

Determina posições das barras de ocultação automática Shell.

```
int GetShellAutohideBars();
```

### <a name="return-value"></a>Valor retornado

Um valor inteiro com sinalizadores codificados que especificam posições de barras de ocultação automática. Pode combinar os seguintes valores: AFX_AUTOHIDE_BOTTOM, AFX_AUTOHIDE_TOP, AFX_AUTOHIDE_LEFT, AFX_AUTOHIDE_RIGHT.

## <a name="afx_global_datareleasetaskbarrefs"></a><a name="releasetaskbarrefs"></a>AFX_GLOBAL_DATA::ReleaseTaskBarRefs

Libera interfaces obtidas `GetITaskbarList` através `GetITaskbarList3` dos métodos.

```
void ReleaseTaskBarRefs();
```

## <a name="afx_global_datashellcreateitemfromparsingname"></a><a name="shellcreateitemfromparsingname"></a>AFX_GLOBAL_DATA::ShellCreateItemFromParsingName

Cria e inicializa um objeto de item Shell a partir de um nome de análise.

```
HRESULT ShellCreateItemFromParsingName(
    PCWSTR pszPath,
    IBindCtx *pbc,
    REFIID riid,
    void **ppv);
```

### <a name="parameters"></a>Parâmetros

*Pszpath*<br/>
[em] Um ponteiro para um nome de exibição.

*Pbc*<br/>
Um ponteiro para um contexto de ligação que controla a operação de análise.

*riid*<br/>
Uma referência a um ID de interface.

*Ppv*<br/>
[fora] Quando esta função retorna, contém o ponteiro de interface solicitado em *riid*. Isso normalmente `IShellItem` será `IShellItem2`ou .

### <a name="return-value"></a>Valor retornado

Os retornos S_OK se forem bem sucedidos; um valor de erro de outra forma.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../hierarchy-chart.md)<br/>
[Estruturas, estilos, retornos de chamada e mapas de mensagem](structures-styles-callbacks-and-message-maps.md)<br/>
[COLORREF](/windows/win32/gdi/colorref)<br/>
[Partes e Estados](/windows/win32/controls/parts-and-states)<br/>
[CDC::DrawText](cdc-class.md#drawtext)<br/>
[DrawThemeTextEx](/windows/win32/api/uxtheme/nf-uxtheme-drawthemetextex)<br/>
[Gerenciador de Janelas da Área de Trabalho](/windows/win32/dwm/dwm-overview)<br/>
[Habilitar e controlar a composição do DWM](/windows/win32/dwm/composition-ovw)<br/>
[Automação de Interface do usuário e Microsoft Active Accessibility](/dotnet/framework/ui-automation/ui-automation-and-microsoft-active-accessibility)<br/>
[Função GetSysColor](/windows/win32/api/winuser/nf-winuser-getsyscolor)<br/>
[GetSysColorBrush](/windows/win32/api/winuser/nf-winuser-getsyscolorbrush)<br/>
[Estrutura NÃO-CLIENTMETRICS](/windows/win32/api/winuser/ns-winuser-nonclientmetricsw)<br/>
[AfxRegisterClass](application-information-and-management.md#afxregisterclass)<br/>
[AfxThrowResourceException](exception-processing.md#afxthrowresourceexception)<br/>
[SetLayeredWindowAttributes](/windows/win32/api/winuser/nf-winuser-setlayeredwindowattributes)
