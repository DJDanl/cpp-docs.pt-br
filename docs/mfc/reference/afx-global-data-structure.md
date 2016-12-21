---
title: "Estrutura AFX_GLOBAL_DATA | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "GLOBAL_DATA"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura AFX_GLOBAL_DATA"
  - "Construtor AFX_GLOBAL_DATA"
ms.assetid: c7abf2fb-ad5e-4336-a01d-260c29ed53a2
caps.latest.revision: 30
caps.handback.revision: 30
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura AFX_GLOBAL_DATA
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O `AFX_GLOBAL_DATA` estrutura contém campos e métodos que são usados para gerenciar a estrutura ou personalizar a aparência e comportamento do seu aplicativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct AFX_GLOBAL_DATA  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`AFX_GLOBAL_DATA::AFX_GLOBAL_DATA`|Constrói um `AFX_GLOBAL_DATA` estrutura.|  
|`AFX_GLOBAL_DATA::~AFX_GLOBAL_DATA`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[AFX_GLOBAL_DATA::CleanUp](#afx_global_data__cleanup)|Libera recursos alocados pelo framework, como pincéis, fontes e DLLs.|  
|[AFX_GLOBAL_DATA::D2D1MakeRotateMatrix](#afx_global_data__d2d1makerotatematrix)|Cria uma transformação de rotação gira com um ângulo especificado em torno de um ponto especificado.|  
|[AFX_GLOBAL_DATA::DrawParentBackground](#afx_global_data__drawparentbackground)|Desenha o plano de fundo do pai do controle na área especificada.|  
|[AFX_GLOBAL_DATA::DrawTextOnGlass](#afx_global_data__drawtextonglass)|Desenha o texto especificado no estilo visual do tema especificado.|  
|[AFX_GLOBAL_DATA::ExcludeTag](#afx_global_data__excludetag)|Remove o par de marca XML especificado de um buffer especificado.|  
|[AFX_GLOBAL_DATA::GetColor](#afx_global_data__getcolor)|Recupera a cor atual do elemento de interface do usuário especificado.|  
|[AFX_GLOBAL_DATA::GetDirect2dFactory](#afx_global_data__getdirect2dfactory)|Retorna um ponteiro para o `ID2D1Factory` interface armazenados em dados globais. Se a interface não é inicializada, ele é criado e os parâmetros padrão.|  
|[AFX_GLOBAL_DATA::GetHandCursor](#afx_global_data__gethandcursor)|Recupera o cursor predefinido que lembra uma mão e cujo identificador é `IDC_HAND`.|  
|[AFX_GLOBAL_DATA::GetITaskbarList](#afx_global_data__getitaskbarlist)|Cria e armazena os dados globais um ponteiro de interface ITaskBarList.|  
|[AFX_GLOBAL_DATA::GetITaskbarList3](#afx_global_data__getitaskbarlist3)|Cria e armazena os dados globais um ponteiro de interface ITaskBarList3.|  
|[AFX_GLOBAL_DATA::GetNonClientMetrics](#afx_global_data__getnonclientmetrics)|Recupera as métricas associadas a área não cliente do windows nonminimized.|  
|[AFX_GLOBAL_DATA::GetShellAutohideBars](#afx_global_data__getshellautohidebars)|Determina a posições auto Shell ocultar barras.|  
|[AFX_GLOBAL_DATA::GetTextHeight](#afx_global_data__gettextheight)|Recupera a altura dos caracteres de texto na fonte atual.|  
|[AFX_GLOBAL_DATA::GetWICFactory](#afx_global_data__getwicfactory)|Retorna um ponteiro para o `IWICImagingFactory` interface armazenados em dados globais. Se a interface não é inicializada, ele é criado e os parâmetros padrão.|  
|[AFX_GLOBAL_DATA::GetWriteFactory](#afx_global_data__getwritefactory)|Retorna um ponteiro para o `IDWriteFactory` interface armazenados em dados globais. Se a interface não é inicializada, ele é criado e os parâmetros padrão.|  
|[AFX_GLOBAL_DATA::IsD2DInitialized](#afx_global_data__isd2dinitialized)|Inicializa `D2D`, `DirectWrite`, e `WIC` fábricas. Chame esse método antes da janela principal é inicializada.|  
|[AFX_GLOBAL_DATA::Is32BitIcons](#afx_global_data__is32biticons)|Indica se há suporte para ícones de 32 bits predefinidos.|  
|[AFX_GLOBAL_DATA::IsD2DInitialized](#afx_global_data__isd2dinitialized)|Determina se o `D2D` foi inicializado.|  
|[AFX_GLOBAL_DATA::IsDwmCompositionEnabled](#afx_global_data__isdwmcompositionenabled)|Fornece uma maneira simples para chamar o Windows [DwmIsCompositionEnabled](http://msdn.microsoft.com/library/windows/desktop/aa969518) método.|  
|[AFX_GLOBAL_DATA::IsHighContrastMode](#afx_global_data__ishighcontrastmode)|Indica se as imagens no momento são exibidas em alto contraste.|  
|[AFX_GLOBAL_DATA::OnSettingChange](#afx_global_data__onsettingchange)|Detecta o estado atual da animação de menus e recursos de ocultar automaticamente barra de tarefas da área de trabalho.|  
|[AFX_GLOBAL_DATA::RegisterWindowClass](#afx_global_data__registerwindowclass)|Registra a classe da janela MFC especificada.|  
|[AFX_GLOBAL_DATA::ReleaseTaskBarRefs](#afx_global_data__releasetaskbarrefs)|Libera as interfaces obtidas por meio de métodos GetITaskbarList e GetITaskbarList3.|  
|[AFX_GLOBAL_DATA::resume](#afx_global_data__resume)|Reinicializa os ponteiros de função interna que acessar métodos que oferecem suporte a janelas [estilos visuais e temas](https://msdn.microsoft.com/library/windows/desktop/hh270423.aspx).|  
|[AFX_GLOBAL_DATA::SetLayeredAttrib](#afx_global_data__setlayeredattrib)|Fornece uma maneira simples para chamar o Windows [SetLayeredWindowAttributes](http://msdn.microsoft.com/library/windows/desktop/ms633540) método.|  
|[AFX_GLOBAL_DATA::SetMenuFont](#afx_global_data__setmenufont)|Cria a fonte de lógica especificada.|  
|[AFX_GLOBAL_DATA::ShellCreateItemFromParsingName](#afx_global_data__shellcreateitemfromparsingname)|Cria e inicializa um objeto de item do Shell de um nome de análise.|  
|[AFX_GLOBAL_DATA::UpdateFonts](#afx_global_data__updatefonts)|Reintializes lógicas fontes que são usadas pela estrutura.|  
|[AFX_GLOBAL_DATA::UpdateSysColors](#afx_global_data__updatesyscolors)|Inicializa as cores, profundidade de cores, pincéis, canetas e imagens que são usadas pela estrutura.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[AFX_GLOBAL_DATA::EnableAccessibilitySupport](#afx_global_data__enableaccessibilitysupport)|Habilita ou desabilita o suporte à acessibilidade ativa da Microsoft. Acessibilidade ativa fornece métodos confiáveis para exposição de informações sobre os elementos de interface do usuário.|  
|[AFX_GLOBAL_DATA::IsAccessibilitySupport](#afx_global_data__isaccessibilitysupport)|Indica se o suporte ao Microsoft Active Accessibility está habilitado.|  
|[AFX_GLOBAL_DATA::IsWindowsLayerSupportAvailable](#afx_global_data__iswindowslayersupportavailable)|Indica se o sistema operacional oferece suporte a janelas em camadas.|  
  
### <a name="data-members"></a> Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[AFX_GLOBAL_DATA::bIsOSAlphaBlendingSupport](#afx_global_data__bisosalphablendingsupport)|Indica se o sistema operacional atual oferece suporte a combinação alfa.|  
|[AFX_GLOBAL_DATA::bIsWindows7](#afx_global_data__biswindows7)|Indica se o aplicativo está sendo executado no sistema operacional Windows 7 ou superior|  
|[AFX_GLOBAL_DATA::clrActiveCaptionGradient](#afx_global_data__clractivecaptiongradient)|Especifica a cor do gradiente de legenda ativa. Geralmente usado para painéis de encaixe.|  
|[AFX_GLOBAL_DATA::clrInactiveCaptionGradient](#afx_global_data__clrinactivecaptiongradient)|Especifica a cor do gradiente de legenda ativa inativa. Geralmente usado para painéis de encaixe.|  
|[AFX_GLOBAL_DATA::m_bUseBuiltIn32BitIcons](#afx_global_data__m_busebuiltin32biticons)|Indica se a estrutura usa ícones de cor predefinidos de 32 bits ou ícones de uma resolução mais baixa.|  
|[AFX_GLOBAL_DATA::m_bUseSystemFont](#afx_global_data__m_busesystemfont)|Indica se uma fonte de sistema é usada para menus, barras de ferramentas e faixas de opções.|  
|[AFX_GLOBAL_DATA::m_hcurHand](#afx_global_data__m_hcurhand)|Armazena o identificador para o cursor de mão.|  
|[AFX_GLOBAL_DATA::m_hcurStretch](#afx_global_data__m_hcurstretch)|Armazena o identificador para o cursor horizontal de ampliação.|  
|[AFX_GLOBAL_DATA::m_hcurStretchVert](#afx_global_data__m_hcurstretchvert)|Armazena o identificador para o cursor de alongamento vertical.|  
|[AFX_GLOBAL_DATA::m_hiconTool](#afx_global_data__m_hicontool)|Armazena o identificador para o ícone da ferramenta.|  
|[AFX_GLOBAL_DATA::m_nAutoHideToolBarMargin](#afx_global_data__m_nautohidetoolbarmargin)|Especifica o deslocamento da barra de ferramentas AutoOcultar mais à esquerda para o lado esquerdo da barra de encaixe.|  
|[AFX_GLOBAL_DATA::m_nAutoHideToolBarSpacing](#afx_global_data__m_nautohidetoolbarspacing)|Especifica o intervalo entre as barras de ferramentas de ocultar automaticamente.|  
|[AFX_GLOBAL_DATA::m_nDragFrameThicknessDock](#afx_global_data__m_ndragframethicknessdock)|Especifica a espessura do quadro arrastar que é usado para comunicar o estado encaixado.|  
|[AFX_GLOBAL_DATA::m_nDragFrameThicknessFloat](#afx_global_data__m_ndragframethicknessfloat)|Especifica a espessura do quadro arrastar que é usado para comunicar o estado flutuante.|  
  
## <a name="remarks"></a>Comentários  
 A maioria dos dados no `AFX_GLOBAL_DATA` estrutura é inicializada quando o aplicativo for iniciado.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [AFX_GLOBAL_DATA](../../mfc/reference/afx-global-data-structure.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxglobals.h  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)


## <a name="a-nameafxglobaldatabisosalphablendingsupporta-afxglobaldatabisosalphablendingsupport"></a><a name="afx_global_data__bisosalphablendingsupport"></a> AFX_GLOBAL_DATA::bIsOSAlphaBlendingSupport
Indica se o sistema operacional oferece suporte a combinação alfa.  
  
  
```  
BOOL  bIsOSAlphaBlendingSupport;  
```  
  
## <a name="remarks"></a>Comentários  
 `TRUE` indica que há suporte para a combinação alfa; Caso contrário, `FALSE`.  
  

## <a name="a-nameafxglobaldatacleanupa-afxglobaldatacleanup"></a><a name="afx_global_data__cleanup"></a> AFX_GLOBAL_DATA::CleanUp
Libera recursos alocados pelo framework, como pincéis, fontes e DLLs.  
  
  
```  
void CleanUp();
```  
## <a name="a-nameafxglobaldatad2d1makerotatematrixa-afxglobaldatad2d1makerotatematrix"></a><a name="afx_global_data__d2d1makerotatematrix"></a> AFX_GLOBAL_DATA::D2D1MakeRotateMatrix
Cria uma transformação de rotação gira com um ângulo especificado em torno de um ponto especificado.  
  
  
```  
HRESULT D2D1MakeRotateMatrix(
    FLOAT angle,  
    D2D1_POINT_2F center,  
    D2D1_MATRIX_3X2_F *matrix);
```  
  
#### <a name="parameters"></a>Parâmetros  
 `angle`  
 O ângulo de rotação horária, em graus.  
  
 `center`  
 O ponto sobre a qual girar.  
  
 `matrix`  
 Quando este método retorna, contém a transformação de rotação de novo. Você deve alocar armazenamento para esse parâmetro.  
  
## <a name="return-value"></a>Valor de retorno  
 Caso contrário retorna S_OK se for bem-sucedido, ou um valor de erro.  
  
## <a name="a-nameafxglobaldatadrawparentbackgrounda-afxglobaldatadrawparentbackground"></a><a name="afx_global_data__drawparentbackground"></a> AFX_GLOBAL_DATA::DrawParentBackground
Desenha o plano de fundo do pai do controle na área especificada.  
  
  
```  
BOOL DrawParentBackground(
    CWnd* pWnd,   
    CDC* pDC,   
    LPRECT lpRect = NULL);
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 Ponteiro para uma janela do controle.  
  
 [in] `pDC`  
 Ponteiro para um contexto de dispositivo.  
  
 [in] `lpRect`  
 Ponteiro para um retângulo que circunda a área para desenhar. O valor padrão é `NULL`.  
  
## <a name="return-value"></a>Valor de retorno  
 `TRUE` Se esse método for bem-sucedida; Caso contrário, `FALSE`.  
  
## <a name="a-nameafxglobaldatadrawtextonglassa-afxglobaldatadrawtextonglass"></a><a name="afx_global_data__drawtextonglass"></a> AFX_GLOBAL_DATA::DrawTextOnGlass
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
  
#### <a name="parameters"></a>Parâmetros  
 [in] `hTheme`  
 Identificador para os dados de tema de uma janela, ou `NULL`. A estrutura usa o tema especificado para desenhar o texto, se esse parâmetro não for `NULL` e temas são suportados. Caso contrário, o framework não usa um tema para desenhar o texto.  
  
 Use o [OpenThemeData](http://msdn.microsoft.com/library/windows/desktop/bb759821) método para criar um `HTHEME`.  
  
 [in] `pDC`  
 Ponteiro para um contexto de dispositivo.  
  
 [in] `iPartId`  
 A parte do controle que tem a aparência do texto desejado. Para obter mais informações, consulte a coluna de partes da tabela no [partes e estados](http://msdn.microsoft.com/library/windows/desktop/bb773210). Se esse valor for 0, o texto é desenhado na fonte padrão ou uma fonte selecionada no contexto de dispositivo.  
  
 [in] `iStateId`  
 O estado do controle que tem a aparência do texto desejado. Para obter mais informações, consulte a coluna de estados da tabela no [partes e estados](http://msdn.microsoft.com/library/windows/desktop/bb773210).  
  
 [in] `strText`  
 O texto a ser desenhado.  
  
 [in] `rect`  
 O limite da área na qual o texto especificado é desenhado.  
  
 [in] `dwFlags`  
 Uma combinação bit a bit (OR) de sinalizadores que especificam como o texto especificado é desenhado.  
  
 Se o `hTheme` parâmetro é `NULL` ou se temas não são suportados e habilitados, o `nFormat` parâmetro o [CDC::DrawText](../Topic/CDC%20Class.md#cdc__drawtext) método descreve os sinalizadores válidos. Se houver suporte para temas, o `dwFlags` parâmetro o [DrawThemeTextEx](http://msdn.microsoft.com/library/windows/desktop/bb773317) método descreve os sinalizadores válidos.  
  
 [in] `nGlowSize`  
 O tamanho de um efeito de brilho desenhado em segundo plano antes de desenhar o texto especificado. O valor padrão é 0.  
  
 [in] `clrText`  
 A cor na qual o texto especificado é desenhado. O valor padrão é a cor padrão.  
  
## <a name="return-value"></a>Valor de retorno  
 `TRUE` Se um tema é usado para desenhar o texto especificado. Caso contrário, `FALSE`.  
  
## <a name="remarks"></a>Comentários  
 Um tema define o estilo visual de um aplicativo. Um tema não é usado para desenhar o texto, se o `hTheme` parâmetro é `NULL`, ou se o [DrawThemeTextEx](http://msdn.microsoft.com/library/windows/desktop/bb773317) não há suporte para o método, ou se [Desktop Window Manager](http://msdn.microsoft.com/library/windows/desktop/aa969540) composição está desabilitada.  
  
 
## <a name="see-also"></a>Consulte também  
 [Estrutura AFX_GLOBAL_DATA](../../mfc/reference/afx-global-data-structure.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449)   
 [Partes e Estados](http://msdn.microsoft.com/library/windows/desktop/bb773210)   
 [CDC::DrawText](../Topic/CDC%20Class.md#cdc__drawtext)   
 [DrawThemeTextEx](http://msdn.microsoft.com/library/windows/desktop/bb773317)   
 [Gerenciador de janelas da área de trabalho](http://msdn.microsoft.com/library/windows/desktop/aa969540)   
 [Ativar e controlar a composição do DWM](http://msdn.microsoft.com/library/windows/desktop/aa969538)

## <a name="a-nameafxglobaldataenableaccessibilitysupporta-afxglobaldataenableaccessibilitysupport"></a><a name="afx_global_data__enableaccessibilitysupport"></a> AFX_GLOBAL_DATA::EnableAccessibilitySupport
Habilita ou desabilita o suporte à acessibilidade ativa da Microsoft.  
  
  
```  
void EnableAccessibilitySupport(BOOL bEnable=TRUE);
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE` Para habilitar o suporte de acessibilidade; `FALSE` para desabilitar o suporte de acessibilidade. O valor padrão é `TRUE`.  
  
## <a name="remarks"></a>Comentários  
 Acessibilidade ativa é uma tecnologia baseada em COM que aprimora os maneira como os programas e o trabalho do sistema operacional Windows junto com produtos de tecnologia assistencial. Ele fornece métodos confiáveis para exposição de informações sobre os elementos de interface do usuário. No entanto, um modelo de acessibilidade mais recente chamado automação de interface do Usuário da Microsoft agora está disponível. Para obter uma comparação das duas tecnologias, consulte [automação de interface do Usuário e Microsoft Active Accessibility](../Topic/UI%20Automation%20and%20Microsoft%20Active%20Accessibility.md).  
  
 Use o [AFX_GLOBAL_DATA::IsAccessibilitySupport](#afx_global_data__IsAccessibilitySupport.md) método para determinar se o suporte ao Microsoft Active Accessibility está habilitado.  
  
 
## <a name="see-also"></a>Consulte também  
 [Automação de interface do Usuário e Microsoft Active Accessibility](../Topic/UI%20Automation%20and%20Microsoft%20Active%20Accessibility.md)   
 [AFX_GLOBAL_DATA::IsAccessibilitySupport](#afx_global_data__IsAccessibilitySupport.md)

## <a name="a-nameafxglobaldataexcludetaga-afxglobaldataexcludetag"></a><a name="afx_global_data__excludetag"></a> AFX_GLOBAL_DATA::ExcludeTag
Remove o par de marca XML especificado de um buffer especificado.  
  
  
```  
BOOL ExcludeTag(
    CString& strBuffer,  
    LPCTSTR lpszTag,  
    CString& strTag,  
    BOOL bIsCharsList = FALSE);
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `strBuffer`  
 Um buffer de texto.  
  
 [in] `lpszTag`  
 O nome de um par de abertura e fechamento de marcas XML.  
  
 [out] `strTag`  
 Quando este método retorna, o `strTag` parâmetro contém o texto que está entre a abertura e fechamento XML marcas que são nomeadas, o `lpszTag` parâmetro. Nenhum espaço em branco à esquerda ou à direita é retirado do resultado.  
  
 [in] `bIsCharsList`  
 `TRUE` Para converter caracteres de escape em símbolos de `strTag` parâmetro em caracteres de escape real; `FALSE` para não executar a conversão. O valor padrão é `FALSE`. Para obter mais informações, consulte comentários.  
  
## <a name="return-value"></a>Valor de retorno  
 `TRUE` Se esse método for bem-sucedida; Caso contrário, `FALSE`.  
  
## <a name="remarks"></a>Comentários  
 Um par de marcas XML consiste em chamada de abertura e fechamento de marcas que indicam o início e término de uma execução de texto no buffer especificado. O `strBuffer` parâmetro especifica o buffer e o `lpszTag` parâmetro especifica o nome das marcas XML.  
  
 Use os símbolos na tabela a seguir para codificar um conjunto de caracteres de escape no buffer especificado. Especifique `TRUE` para o `bIsCharsList` parâmetro para converter os símbolos no `strTag` parâmetro em caracteres de escape real. A tabela a seguir usa o [_T()](../../c-runtime-library/data-type-mappings.md) macro para especificar o símbolo e cadeias de caracteres de escape.  
  
|Símbolo|Caractere de escape|  
|------------|----------------------|  
|_T("\\\t")|_T("\t")|  
|_T("\\\n")|_T("\n")|  
|_T("\\\r")|_T("\r")|  
|_T("\\\b")|_T("\b")|  
|_T("LT")|_T("\<")|  
|_T("GT")|_T(">")|  
|_T("AMP")|_T("&")|  
  
## <a name="a-nameafxglobaldatagetcolora-afxglobaldatagetcolor"></a><a name="afx_global_data__getcolor"></a> AFX_GLOBAL_DATA::GetColor
Recupera a cor atual do elemento de interface do usuário especificado.  
  
  
```  
COLORREF GetColor(int nColor);
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `nColor`  
 Um valor que especifica um elemento de interface do usuário cuja cor é recuperado. Para obter uma lista de valores válidos, consulte o `nIndex` parâmetro o [GetSysColor](http://msdn.microsoft.com/library/windows/desktop/ms724371) método.  
  
## <a name="return-value"></a>Valor de retorno  
 O valor de cor RGB de elemento de interface do usuário especificado. Para obter mais informações, consulte comentários.  
  
## <a name="remarks"></a>Comentários  
 Se o `nColor` parâmetro está fora do intervalo, o valor de retorno é zero. Como zero é também um valor válido de RGB, é possível usar esse método para determinar se uma cor do sistema é suportada pelo sistema operacional atual. Em vez disso, use o [GetSysColorBrush](http://msdn.microsoft.com/library/windows/desktop/dd144927) método, que retorna `NULL` se não há suporte para a cor.  
  
## <a name="see-also"></a>Consulte também  

 [Função GetSysColor](http://msdn.microsoft.com/library/windows/desktop/ms724371)   
 [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449)   
 [GetSysColorBrush](http://msdn.microsoft.com/library/windows/desktop/dd144927)

## <a name="a-nameafxglobaldatagetdirect2dfactorya-afxglobaldatagetdirect2dfactory"></a><a name="afx_global_data__getdirect2dfactory"></a> AFX_GLOBAL_DATA::GetDirect2dFactory
 Retorna um ponteiro para a interface ID2D1Factory que é armazenada em dados globais. Se a interface não é inicializada, ele é criado e os parâmetros padrão.  
  
  
```  
ID2D1Factory* GetDirect2dFactory();
```  
  
## <a name="return-value"></a>Valor de retorno  
 Um ponteiro de interface ID2D1Factory se a criação de uma fábrica de êxito ou NULL se houver falha na criação ou sistema operacional atual não tem suporte D2D.  
  
AFX_GLOBAL_DATA::GetHandCursor recupera o cursor predefinido que lembra uma mão e cujo identificador é `IDC_HAND`.  
  
  
```  
HCURSOR GetHandCursor();
```  
  
## <a name="return-value"></a>Valor de retorno  
 O identificador do cursor disponível.  

## <a name="a-nameafxglobaldatagetnonclientmetricsa-afxglobaldatagetnonclientmetrics"></a><a name="afx_global_data__getnonclientmetrics"></a> AFX_GLOBAL_DATA::GetNonClientMetrics
Recupera as métricas associadas a área não cliente do windows nonminimized.  
  
  
```  
BOOL GetNonClientMetrics(NONCLIENTMETRICS& info);
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in, out] `info`  
 A [NONCLIENTMETRICS](http://msdn.microsoft.com/library/windows/desktop/ff729175) estrutura que contém as métricas escalonáveis associadas à área não cliente de uma janela nonminimized.  
  
## <a name="return-value"></a>Valor de retorno  
 `TRUE` Se esse método for bem-sucedida; Caso contrário, `FALSE`.  
 
  
## <a name="see-also"></a>Consulte também   
 [Estrutura NONCLIENTMETRICS](http://msdn.microsoft.com/library/windows/desktop/ff729175)

## <a name="a-nameafxglobaldatagettextheighta-afxglobaldatagettextheight"></a><a name="afx_global_data__gettextheight"></a> AFX_GLOBAL_DATA::GetTextHeight
 Recupera a altura dos caracteres de texto na fonte atual.  
  
  
```  
int GetTextHeight(BOOL bHorz = TRUE);
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `bHorz`  
 `TRUE` para recuperar a altura dos caracteres quando o texto é executado horizontalmente; `FALSE` para recuperar a altura dos caracteres quando o texto é executado verticalmente. O valor padrão é `TRUE`.  
  
## <a name="return-value"></a>Valor de retorno  
 A altura da fonte atual, que é medida do seu descendente até seu descendente.  
  
## <a name="a-nameafxglobaldatagetwicfactorya-afxglobaldatagetwicfactory"></a><a name="afx_global_data__getwicfactory"></a> AFX_GLOBAL_DATA::GetWICFactory
Retorna um ponteiro para uma interface IWICImagingFactory armazenados em dados globais. Se a interface não é inicializada, ele é criado e os parâmetros padrão.  
  
  
```  
IWICImagingFactory* GetWICFactory();
```  
  
## <a name="return-value"></a>Valor de retorno  
 Um ponteiro para uma interface IWICImagingFactory se a criação de uma fábrica de êxito ou NULL se houver falha na criação ou o sistema operacional atual não tem suporte do WIC.  
  
## <a name="a-nameafxglobaldatagetwritefactorya-afxglobaldatagetwritefactory"></a><a name="afx_global_data__getwritefactory"></a> AFX_GLOBAL_DATA::GetWriteFactory
Retorna um ponteiro para a interface de IDWriteFactory que é armazenada em dados globais. Se a interface não é inicializada, ele é criado e os parâmetros padrão.  
  
  
```  
IDWriteFactory* GetWriteFactory();
```  
  
## <a name="return-value"></a>Valor de retorno  
 Um ponteiro de interface IDWriteFactory se a criação de uma fábrica de êxito ou NULL se houver falha na criação ou sistema operacional atual não tem suporte do DirectWrite.  
 
## <a name="a-nameafxglobaldatainitd2da-afxglobaldatainitd2d"></a><a name="afx_global_data__initd2d"></a> AFX_GLOBAL_DATA::InitD2D
Inicializa as fábricas D2D, DirectWrite e WIC. Chame esse método antes da janela principal é inicializada.  
  
  
```  
BOOL InitD2D(
    D2D1_FACTORY_TYPE d2dFactoryType = D2D1_FACTORY_TYPE_SINGLE_THREADED,  
    DWRITE_FACTORY_TYPE writeFactoryType = DWRITE_FACTORY_TYPE_SHARED);
```  
  
#### <a name="parameters"></a>Parâmetros  
 `d2dFactoryType`  
 O modelo de threading de fábrica D2D e os recursos que ele cria.  
  
 `writeFactoryType`  
 Um valor que especifica se o objeto de fábrica de gravação será compartilhado ou isolado  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna TRUE se as fábricas foram intilalizrd, FALSO - caso contrário  
  
## <a name="a-nameafxglobaldatais32biticonsa-afxglobaldatais32biticons"></a><a name="afx_global_data__is32biticons"></a> AFX_GLOBAL_DATA::Is32BitIcons
Indica se há suporte para ícones de 32 bits predefinidos.  
  
  
```  
BOOL Is32BitIcons() const;

 
```  
  
## <a name="return-value"></a>Valor de retorno  
 `TRUE` Se houver suporte para ícones predefinidos de 32 bits; Caso contrário, `FALSE`.  
  
## <a name="remarks"></a>Comentários  
 Esse método retorna `TRUE` se o framework oferece suporte a ícones internos de 32 bits e se o sistema operacional suporta 16 bits por pixel ou mais e se as imagens não são exibidas em alto contraste.  
  
## <a name="a-nameafxglobaldataisaccessibilitysupporta-afxglobaldataisaccessibilitysupport"></a><a name="afx_global_data__isaccessibilitysupport"></a> AFX_GLOBAL_DATA::IsAccessibilitySupport
Indica se o suporte ao Microsoft Active Accessibility está habilitado.  
  
  
```  
BOOL IsAccessibilitySupport() const;

 
```  
  
## <a name="return-value"></a>Valor de retorno  
 `TRUE` Se o suporte à acessibilidade estiver habilitado; Caso contrário, `FALSE`.  
  
## <a name="remarks"></a>Comentários  
 Acessibilidade ativa da Microsoft foi a solução anterior para tornar aplicativos acessíveis. Automação de interface do Usuário da Microsoft é o novo modelo de acessibilidade do Microsoft Windows e se destina a atender às necessidades de produtos de tecnologia assistencial e ferramentas de teste automatizado. Para obter mais informações, consulte [automação de interface do Usuário e Microsoft Active Accessibility](../Topic/UI%20Automation%20and%20Microsoft%20Active%20Accessibility.md).  
  
 Use o [AFX_GLOBAL_DATA::EnableAccessibilitySupport](#afx_global_data__EnableAccessibilitySupport.md) método para habilitar ou desabilitar o suporte à acessibilidade ativa.  
  

## <a name="see-also"></a>Consulte também  
 [Automação de interface do Usuário e Microsoft Active Accessibility](../Topic/UI%20Automation%20and%20Microsoft%20Active%20Accessibility.md)

## <a name="a-nameafxglobaldataisd2dinitializeda-afxglobaldataisd2dinitialized"></a><a name="afx_global_data__isd2dinitialized"></a> AFX_GLOBAL_DATA::IsD2DInitialized
 Determina se o D2D foi inicializado  
  
  
```  
BOOL IsD2DInitialized() const;

 
```  
  
## <a name="return-value"></a>Valor de retorno  
 TRUE se D2D foi inicializado; Caso contrário, FALSE.  
  
## <a name="a-nameafxglobaldataisdwmcompositionenableda-afxglobaldataisdwmcompositionenabled"></a><a name="afx_global_data__isdwmcompositionenabled"></a> AFX_GLOBAL_DATA::IsDwmCompositionEnabled
Fornece uma maneira simples para chamar o Windows [DwmIsCompositionEnabled](http://msdn.microsoft.com/library/windows/desktop/aa969518) método.  
  
  
```  
BOOL IsDwmCompositionEnabled();
```  
  
## <a name="return-value"></a>Valor de retorno  
 `TRUE` Se [Desktop Window Manager](http://msdn.microsoft.com/library/windows/desktop/aa969540) composição estiver habilitada; caso contrário, `FALSE`.  
  
## <a name="see-also"></a>Consulte também    
 [Gerenciador de janelas da área de trabalho](http://msdn.microsoft.com/library/windows/desktop/aa969540)   
 [Ativar e controlar a composição do DWM](http://msdn.microsoft.com/library/windows/desktop/aa969538)

## <a name="a-nameafxglobaldataishighcontrastmodea-afxglobaldataishighcontrastmode"></a><a name="afx_global_data__ishighcontrastmode"></a> AFX_GLOBAL_DATA::IsHighContrastMode
 Indica se as imagens no momento são exibidas em alto contraste.    
```  
BOOL IsHighContrastMode() const;

 
```  
  
## <a name="return-value"></a>Valor de retorno  
 `TRUE` Se as imagens estão exibidas no modo de alto contraste preto ou branco. Caso contrário, `FALSE`.  
  
## <a name="remarks"></a>Comentários  
 No modo de alto contraste preto, voltada para a luz de bordas são brancas e o plano de fundo é preto. No modo de alto contraste branca, voltada para a luz de bordas são pretas e o plano de fundo é branco.  
  
## <a name="a-nameafxglobaldataiswindowslayersupportavailablea-afxglobaldataiswindowslayersupportavailable"></a><a name="afx_global_data__iswindowslayersupportavailable"></a> AFX_GLOBAL_DATA::IsWindowsLayerSupportAvailable
Indica se o sistema operacional oferece suporte a janelas em camadas.  
  
  
```  
BOOL IsWindowsLayerSupportAvailable() const;

 
```  
  
## <a name="return-value"></a>Valor de retorno  
 `TRUE` Se houver suporte para janelas em camadas; Caso contrário, `FALSE`.  
  
## <a name="remarks"></a>Comentários  
 Se houver suporte para janelas em camadas, *encaixe inteligente* marcadores usam janelas em camadas.  
  
## <a name="a-nameafxglobaldatambusebuiltin32biticonsa-afxglobaldatambusebuiltin32biticons"></a><a name="afx_global_data__m_busebuiltin32biticons"></a> AFX_GLOBAL_DATA::m_bUseBuiltIn32BitIcons
Indica se a estrutura usa ícones de cor predefinidos de 32 bits ou ícones de uma resolução mais baixa.  
  
  
```  
BOOL  m_bUseBuiltIn32BitIcons;  
```  
  
## <a name="remarks"></a>Comentários  
 `TRUE` Especifica que a estrutura usa ícones de cor de 32 bits; `FALSE` Especifica ícones de resolução mais baixos. O `AFX_GLOBAL_DATA::AFX_GLOBAL_DATA` construtor inicializa este membro para `TRUE`.  
  
 Esse membro deve ser definido na inicialização do aplicativo.  
  
## <a name="a-nameafxglobaldatambusesystemfonta-afxglobaldatambusesystemfont"></a><a name="afx_global_data__m_busesystemfont"></a> AFX_GLOBAL_DATA::m_bUseSystemFont
Indica se uma fonte de sistema é usada para menus, barras de ferramentas e faixas de opções.  
  
  
```  
BOOL m_bUseSystemFont;  
```  
  
## <a name="remarks"></a>Comentários  
 `TRUE` Especifica o uso de uma fonte de sistema. Caso contrário, `FALSE`. O `AFX_GLOBAL_DATA::AFX_GLOBAL_DATA` construtor inicializa este membro para `FALSE`.  
  
 Teste esse membro não é a única maneira para a estrutura determinar a fonte de usar. O `AFX_GLOBAL_DATA::UpdateFonts` método também testa fontes padrão e alternativos para determinar quais estilos visuais estão disponíveis para serem aplicados aos menus, barras de ferramentas e faixas de opções.  
  
## <a name="a-nameafxglobaldatamhcurhanda-afxglobaldatamhcurhand"></a><a name="afx_global_data__m_hcurhand"></a> AFX_GLOBAL_DATA::m_hcurHand
Armazena o identificador para o cursor de mão.  
  
  
```  
HCURSOR m_hcurHand;  
```  
  
## <a name="a-nameafxglobaldatamhcurstretcha-afxglobaldatamhcurstretch"></a><a name="afx_global_data__m_hcurstretch"></a> AFX_GLOBAL_DATA::m_hcurStretch
Armazena o identificador para o cursor horizontal de ampliação.  
  
  
```  
HCURSOR m_hcurStretch;  
```  

## <a name="a-nameafxglobaldatamhcurstretchverta-afxglobaldatamhcurstretchvert"></a><a name="afx_global_data__m_hcurstretchvert"></a> AFX_GLOBAL_DATA::m_hcurStretchVert
Armazena o identificador para o cursor de alongamento vertical.  
  
  
```  
HCURSOR m_hcurStretchVert;  
```  
  
## <a name="a-nameafxglobaldatamhicontoola-afxglobaldatamhicontool"></a><a name="afx_global_data__m_hicontool"></a> AFX_GLOBAL_DATA::m_hiconTool
Armazena o identificador para o ícone da ferramenta.  
  
  
```  
HICON m_hiconTool;  
```  
## <a name="a-nameafxglobaldatamnautohidetoolbarmargina-afxglobaldatamnautohidetoolbarmargin"></a><a name="afx_global_data__m_nautohidetoolbarmargin"></a> AFX_GLOBAL_DATA::m_nAutoHideToolBarMargin
Especifica o deslocamento da barra de ferramentas AutoOcultar mais à esquerda para o lado esquerdo da barra de encaixe.  
  
  
```  
int   m_nAutoHideToolBarMargin;  
```  
  
## <a name="remarks"></a>Comentários  
 O `AFX_GLOBAL_DATA::AFX_GLOBAL_DATA` construtor inicializa este membro para 4 pixels.  
  
## <a name="a-nameafxglobaldatamnautohidetoolbarspacinga-afxglobaldatamnautohidetoolbarspacing"></a><a name="afx_global_data__m_nautohidetoolbarspacing"></a> AFX_GLOBAL_DATA::m_nAutoHideToolBarSpacing
Especifica o intervalo entre as barras de ferramentas de ocultar automaticamente.  
  
  
```  
int   m_nAutoHideToolBarSpacing;  
```  
  
## <a name="remarks"></a>Comentários  
 O `AFX_GLOBAL_DATA::AFX_GLOBAL_DATA` construtor inicializa este membro para 14 pixels.  
  
## <a name="a-nameafxglobaldatamndragframethicknessdocka-afxglobaldatamndragframethicknessdock"></a><a name="afx_global_data__m_ndragframethicknessdock"></a> AFX_GLOBAL_DATA::m_nDragFrameThicknessDock

Especifica a espessura do quadro arrastar que é usado para indicar o estado de ancoramento.  
  
  
```  
int   m_nDragFrameThicknessDock;  
```  
  
## <a name="remarks"></a>Comentários  
 O `AFX_GLOBAL_DATA::AFX_GLOBAL_DATA` construtor inicializa este membro de 3 pixels.  
  
## <a name="a-nameafxglobaldatamndragframethicknessfloata-afxglobaldatamndragframethicknessfloat"></a><a name="afx_global_data__m_ndragframethicknessfloat"></a> AFX_GLOBAL_DATA::m_nDragFrameThicknessFloat
Especifica a espessura do quadro arrastar que é usado para indicar o estado flutuante.  
  
  
```  
int   m_nDragFrameThicknessFloat;  
```  
  
## <a name="remarks"></a>Comentários  
 O `AFX_GLOBAL_DATA::AFX_GLOBAL_DATA` construtor inicializa este membro para 4 pixels.  
  
## <a name="a-nameafxglobaldataonsettingchangea-afxglobaldataonsettingchange"></a><a name="afx_global_data__onsettingchange"></a> AFX_GLOBAL_DATA::OnSettingChange
Detecta o estado atual da animação de menus e recursos de ocultar automaticamente barra de tarefas da área de trabalho.  
  
  
```  
void OnSettingChange();
```  
  
## <a name="remarks"></a>Comentários  
 Esse método define variáveis de estrutura para o estado de determinados atributos da área de trabalho do usuário. Este método detecta o estado atual da animação de menus, esmaecimento de menu e barra AutoOcultar recursos de tarefas.  
  
## <a name="a-nameafxglobaldataregisterwindowclassa-afxglobaldataregisterwindowclass"></a><a name="afx_global_data__registerwindowclass"></a> AFX_GLOBAL_DATA::RegisterWindowClass
Registra a classe da janela MFC especificada.  
  
  
```  
CString RegisterWindowClass(LPCTSTR lpszClassNamePrefix);
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `lpszClassNamePrefix`  
 O nome da classe de janela para registrar.  
  
## <a name="return-value"></a>Valor de retorno  
 O nome qualificado da classe registrada se esse método for bem-sucedida; Caso contrário, um [exceção de recurso](../Topic/AfxThrowResourceException.md).  
  
## <a name="remarks"></a>Comentários  
 O valor de retorno é uma lista delimitada por vírgula do `lpszClassNamePrefix` cadeia de caracteres do parâmetro e as representações de texto hexadecimal de identificadores da instância do aplicativo atual; o cursor de aplicativo, que é o cursor de seta cujo identificador é IDC_ARROW; e o pincel do plano de fundo. Para obter mais informações sobre como registrar classes de janela MFC, consulte [AfxRegisterClass](../Topic/Application%20Information%20and%20Management.md#afxregisterclass).  
  
## <a name="see-also"></a>Consulte também    
 [AfxRegisterClass](../Topic/Application%20Information%20and%20Management.md#afxregisterclass)   
 [AfxThrowResourceException](../../mfc/reference/exception-processing.md#afxthrowresourceexception)

## <a name="a-nameafxglobaldataresumea-afxglobaldataresume"></a><a name="afx_global_data__resume"></a> AFX_GLOBAL_DATA::resume
 Reinicializa os ponteiros de função interna que acessar métodos que oferecem suporte a estilos visuais e temas do Windows. 
  
  
```  
BOOL Resume();
```  
  
## <a name="return-value"></a>Valor de retorno  
 `TRUE` Se esse método for bem-sucedida; Caso contrário, `FALSE`. No modo de depuração, esse método declara se esse método for bem-sucedido.  
  
## <a name="remarks"></a>Comentários  
 Esse método é chamado quando o framework recebe o [WM_POWERBROADCAST](http://msdn.microsoft.com/library/windows/desktop/aa373247) mensagem.  
  
## <a name="a-nameafxglobaldatasetlayeredattriba-afxglobaldatasetlayeredattrib"></a><a name="afx_global_data__setlayeredattrib"></a> AFX_GLOBAL_DATA::SetLayeredAttrib
Fornece uma maneira simples para chamar o Windows [SetLayeredWindowAttributes](http://msdn.microsoft.com/library/windows/desktop/ms633540) método.  
  
  
```  
BOOL SetLayeredAttrib(
    HWND hwnd,  
    COLORREF crKey,  
    BYTE bAlpha,  
    DWORD dwFlags);
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `hwnd`  
 Identificador para a janela em camadas.  
  
 [in] `crKey`  
 A cor da transparência da chave que o [Desktop Window Manager](http://msdn.microsoft.com/library/windows/desktop/aa969540) usa para compor a janela em camadas.  
  
 [in] `bAlpha`  
 O valor alfa é usado para descrever a opacidade da janela em camadas.  
  
 [in] `dwFlags`  
 Uma combinação bit a bit (OR) de sinalizadores que especificam quais parâmetros de método para usar. Especifique LWA_COLORKEY para usar o `crKey` parâmetro como a cor de transparência. Especifique LWA_ALPHA para usar o `bAlpha` parâmetro para determinar a opacidade da janela em camadas.  
  
## <a name="return-value"></a>Valor de retorno  
 `TRUE` Se esse método for bem-sucedida; Caso contrário, `FALSE`.   
 
## <a name="see-also"></a>Consulte também   
 [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449)   
 [SetLayeredWindowAttributes](http://msdn.microsoft.com/library/windows/desktop/ms633540)

## <a name="a-nameafxglobaldatasetmenufonta-afxglobaldatasetmenufont"></a><a name="afx_global_data__setmenufont"></a> AFX_GLOBAL_DATA::SetMenuFont
Cria a fonte de lógica especificada.  
  
  
```  
BOOL SetMenuFont(
    LPLOGFONT lpLogFont,  
    BOOL bHorz);
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `lpLogFont`  
 Ponteiro para uma estrutura que contém os atributos de uma fonte.  
  
 [in] `bHorz`  
 `TRUE` para especificar que o texto é executado horizontalmente; `FALSE` para especificar que o texto é executado verticalmente.  
  
## <a name="return-value"></a>Valor de retorno  
 `TRUE` Se esse método for bem-sucedida; Caso contrário, `FALSE`. No modo de depuração, esse método declara se esse método for bem-sucedido.  
  
## <a name="remarks"></a>Comentários  
 Esse método cria uma fonte regular horizontal, uma fonte sublinhada, e uma fonte em negrito é usado em default itens de menu. Opcionalmente, esse método cria uma fonte vertical regular. Para obter mais informações sobre fontes lógicas, consulte [CFont::CreateFontIndirect](../../mfc/reference/cfont-class.md#cfont__createfontindirect).  
  
## <a name="a-nameafxglobaldataupdatefontsa-afxglobaldataupdatefonts"></a><a name="afx_global_data__updatefonts"></a> AFX_GLOBAL_DATA::UpdateFonts
Reintializes lógicas fontes que são usadas pela estrutura.  
  
  
```  
void UpdateFonts();
```  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações sobre fontes lógicas, consulte `CFont::CreateFontIndirect`.  
  
## <a name="a-nameafxglobaldataupdatesyscolorsa-afxglobaldataupdatesyscolors"></a><a name="afx_global_data__updatesyscolors"></a> AFX_GLOBAL_DATA::UpdateSysColors
Inicializa as cores, profundidade de cores, pincéis, canetas e imagens que são usadas pela estrutura.  
  
  
```  
void UpdateSysColors();
```  
  
## <a name="a-nameafxglobaldatabiswindows7a-afxglobaldatabiswindows7"></a><a name="afx_global_data__biswindows7"></a> AFX_GLOBAL_DATA::bIsWindows7
Indica se o aplicativo está sendo executado no Windows 7 ou superior.  
  
  
```  
BOOL bIsWindows7;  
```  
  
## <a name="a-nameafxglobaldataclractivecaptiongradienta-afxglobaldataclractivecaptiongradient"></a><a name="afx_global_data__clractivecaptiongradient"></a> AFX_GLOBAL_DATA::clrActiveCaptionGradient
Especifica a cor do gradiente da legenda do ativa. Geralmente usado para painéis de encaixe.  
  
  
```  
COLORREF clrActiveCaptionGradient;  
```  
  
## <a name="a-nameafxglobaldataclrinactivecaptiongradienta-afxglobaldataclrinactivecaptiongradient"></a><a name="afx_global_data__clrinactivecaptiongradient"></a> AFX_GLOBAL_DATA::clrInactiveCaptionGradient
Especifica a cor do gradiente da legenda inativa. Geralmente usado para painéis de encaixe.  
  
  
```  
COLORREF clrInactiveCaptionGradient;  
```  
  
## <a name="a-nameafxglobaldatagetitaskbarlista-afxglobaldatagetitaskbarlist"></a><a name="afx_global_data__getitaskbarlist"></a> AFX_GLOBAL_DATA::GetITaskbarList
Cria e armazena os dados globais um ponteiro para o `ITaskBarList` interface.  
  
  
```  
ITaskbarList *GetITaskbarList();
```  
  
## <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `ITaskbarList` interface se a criação de uma barra objeto da lista de tarefas for bem-sucedida; `NULL` se houver falha na criação ou se o sistema operacional atual for menor que o Windows 7.  
  
## <a name="a-nameafxglobaldatagetitaskbarlist3a-afxglobaldatagetitaskbarlist3"></a><a name="afx_global_data__getitaskbarlist3"></a> AFX_GLOBAL_DATA::GetITaskbarList3
Cria e armazena os dados globais um ponteiro para o `ITaskBarList3` interface.  
  
  
```  
ITaskbarList3 *GetITaskbarList3();
```  
  
## <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `ITaskbarList3` interface se a criação de uma barra objeto da lista de tarefas for bem-sucedida; `NULL` se houver falha na criação ou se o sistema operacional atual for menor que o Windows 7.  
  
## <a name="a-nameafxglobaldatagetshellautohidebarsa-afxglobaldatagetshellautohidebars"></a><a name="afx_global_data__getshellautohidebars"></a> AFX_GLOBAL_DATA::GetShellAutohideBars
Determina a posições auto Shell ocultar barras.  
  
  
```  
int GetShellAutohideBars();
```  
  
## <a name="return-value"></a>Valor de retorno  
 Um valor inteiro com codificado sinalizadores que especificam posições Auto ocultar barras. Ele pode combinar os seguintes valores: AFX_AUTOHIDE_BOTTOM, AFX_AUTOHIDE_TOP, AFX_AUTOHIDE_LEFT, AFX_AUTOHIDE_RIGHT.  
  
## <a name="a-nameafxglobaldatareleasetaskbarrefsa-afxglobaldatareleasetaskbarrefs"></a><a name="afx_global_data__releasetaskbarrefs"></a> AFX_GLOBAL_DATA::ReleaseTaskBarRefs
Libera as interfaces obtidas por meio de `GetITaskbarList` e `GetITaskbarList3` métodos.  
  
  
```  
void ReleaseTaskBarRefs();
```  
  
## <a name="a-nameafxglobaldatashellcreateitemfromparsingnamea-afxglobaldatashellcreateitemfromparsingname"></a><a name="afx_global_data__shellcreateitemfromparsingname"></a> AFX_GLOBAL_DATA::ShellCreateItemFromParsingName
Cria e inicializa um objeto de item do Shell de um nome de análise.  
  
  
```  
HRESULT ShellCreateItemFromParsingName(
    PCWSTR pszPath,  
    IBindCtx *pbc,  
    REFIID riid,  
    void **ppv);
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pszPath`  
 [in] Um ponteiro para um nome de exibição.  
  
 `pbc`  
 Um ponteiro para um contexto de ligação que controla a operação de análise.  
  
 `riid`  
 Uma referência a uma ID de interface.  
  
 `ppv`  
 [out] Quando essa função retorna, contém o ponteiro de interface solicitado em `riid`. Isso geralmente será `IShellItem` ou `IShellItem2`.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna S_OK se for bem-sucedida; um valor de erro caso contrário.  

