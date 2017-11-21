---
title: Classe CMFCToolTipCtrl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCToolTipCtrl
- AFXTOOLTIPCTRL/CMFCToolTipCtrl
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::GetIconSize
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::GetParams
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::OnDrawBorder
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::OnDrawDescription
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::OnDrawIcon
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::OnDrawLabel
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::OnDrawSeparator
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::OnFillBackground
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::SetDescription
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::SetFixedWidth
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::SetHotRibbonButton
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::SetLocation
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::SetParams
dev_langs: C++
helpviewer_keywords:
- CMFCToolTipCtrl [MFC], GetIconSize
- CMFCToolTipCtrl [MFC], GetParams
- CMFCToolTipCtrl [MFC], OnDrawBorder
- CMFCToolTipCtrl [MFC], OnDrawDescription
- CMFCToolTipCtrl [MFC], OnDrawIcon
- CMFCToolTipCtrl [MFC], OnDrawLabel
- CMFCToolTipCtrl [MFC], OnDrawSeparator
- CMFCToolTipCtrl [MFC], OnFillBackground
- CMFCToolTipCtrl [MFC], SetDescription
- CMFCToolTipCtrl [MFC], SetFixedWidth
- CMFCToolTipCtrl [MFC], SetHotRibbonButton
- CMFCToolTipCtrl [MFC], SetLocation
- CMFCToolTipCtrl [MFC], SetParams
ms.assetid: 9fbfcfb1-a8ab-417f-ae29-9a9ca85ee58f
caps.latest.revision: "33"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 83fe6fc144f4a8864cccb68edef230ba91364416
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cmfctooltipctrl-class"></a>Classe CMFCToolTipCtrl
Uma implementação de dica de ferramenta estendida se baseia o [classe CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md). Uma dica de ferramenta com base no `CMFCToolTipCtrl` classe pode exibir um ícone, um rótulo e uma descrição. Você pode personalizar a aparência visual usando um preenchimento de gradiente, texto personalizado e cores da borda, negrito, cantos arredondados ou um estilo de balão.  

 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCToolTipCtrl : public CToolTipCtrl  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCToolTipCtrl::CMFCToolTipCtrl`|Construtor padrão.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolTipCtrl::GetIconSize](#geticonsize)|Retorna o tamanho de um ícone em uma dica de ferramenta.|  
|[CMFCToolTipCtrl::GetParams](#getparams)|Retorna as configurações de exibição de uma dica de ferramenta.|  
|[CMFCToolTipCtrl::OnDrawBorder](#ondrawborder)|Desenha a borda de uma dica de ferramenta.|  
|[CMFCToolTipCtrl::OnDrawDescription](#ondrawdescription)||  
|[CMFCToolTipCtrl::OnDrawIcon](#ondrawicon)|Exibe um ícone em uma dica de ferramenta.|  
|[CMFCToolTipCtrl::OnDrawLabel](#ondrawlabel)|Desenha o rótulo de uma dica de ferramenta ou calcula o tamanho do rótulo.|  
|[CMFCToolTipCtrl::OnDrawSeparator](#ondrawseparator)|Desenha o separador entre o rótulo e a descrição em uma dica de ferramenta.|  
|[CMFCToolTipCtrl::OnFillBackground](#onfillbackground)|Preenche o plano de fundo da dica de ferramenta.|  
|[CMFCToolTipCtrl::SetDescription](#setdescription)|Define a descrição a ser exibido por tooltip.|  
|[CMFCToolTipCtrl::SetFixedWidth](#setfixedwidth)||  
|[CMFCToolTipCtrl::SetHotRibbonButton](#sethotribbonbutton)||  
|[CMFCToolTipCtrl::SetLocation](#setlocation)||  
|[CMFCToolTipCtrl::SetParams](#setparams)|Especifica a aparência visual de uma dica de ferramenta usando um `CMFCToolTipInfo` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Use `CMFCToolTipCtrl`, `CMFCToolTipInfo`, e [CTooltipManager classe](../../mfc/reference/ctooltipmanager-class.md) objetos juntas para implementar dicas de ferramenta personalizadas em seu aplicativo.  
  
 Por exemplo, para usar dicas de ferramentas do estilo de balão, siga estas etapas:  
  
 1. Use o [classe CWinAppEx](../../mfc/reference/cwinappex-class.md) método para inicializar o Gerenciador de dica de ferramenta em seu aplicativo.  
  
 2. Criar um `CMFCToolTipInfo` para especificar o estilo visual que você deseja:  
  
```  
CMFCToolTipInfo params;  
    params.m_bBoldLabel = FALSE;  
    params.m_bDrawDescription = FALSE;  
    params.m_bDrawIcon = FALSE;  
    params.m_bRoundedCorners = TRUE;  
    params.m_bDrawSeparator = FALSE;  
    if (m_bCustomColors)  
 {  
    params.m_clrFill = RGB (255,
    255,
    255);

    params.m_clrFillGradient = RGB (228,
    228,
    240);

    params.m_clrText = RGB (61,
    83,
    80);

    params.m_clrBorder = RGB (144,
    149,
    168);

 }  
```  
3. Use o [CTooltipManager::SetTooltipParams](../../mfc/reference/ctooltipmanager-class.md#settooltipparams) método para definir o estilo visual para todas as dicas de ferramenta no aplicativo usando os estilos definidos no `CMFCToolTipInfo` objeto:  
  
```  
theApp.GetTooltipManager ()->SetTooltipParams (AFX_TOOLTIP_TYPE_ALL,  
    RUNTIME_CLASS (CMFCToolTipCtrl), &params);
```  
Você também pode derivar uma nova classe de `CMFCToolTipCtrl` para controlar o comportamento de dica de ferramenta e renderização. Para especificar uma nova classe de controle de dica de ferramenta, use o `CTooltipManager::SetTooltipParams` método:  
  
```  
myApp.GetTooltipManager ()->SetTooltipParams (AFX_TOOLTIP_TYPE_ALL,  
    RUNTIME_CLASS (CMyToolTipCtrl))  
```  
Para restaurar o padrão a dica de ferramenta classe de controle e redefinir a aparência de dica de ferramenta para seu estado padrão, especifique NULL nos runtime classe e a dica de ferramenta informações sobre parâmetros de `SetTooltipParams`:  
  
```  
theApp.GetTooltipManager ()->SetTooltipParams (AFX_TOOLTIP_TYPE_ALL,  
    NULL,
    NULL);
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um `CMFCToolTipCtrl` do objeto, defina a descrição do que a dica de ferramenta exibe e definir a largura do controle tooltip.  
  
 [!code-cpp[NVC_MFC_RibbonApp#41](../../mfc/reference/codesnippet/cpp/cmfctooltipctrl-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md)  
  
 [CMFCToolTipCtrl](../../mfc/reference/cmfctooltipctrl-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtooltipctrl.h  
  
##  <a name="cmfctooltipctrl"></a>CMFCToolTipCtrl::CMFCToolTipCtrl  

  
```  
CMFCToolTipCtrl(CMFCToolTipInfo* pParams = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pParams`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="geticonsize"></a>CMFCToolTipCtrl::GetIconSize  
 Retorna o tamanho de um ícone em uma dica de ferramenta.  
  
```  
virtual CSize GetIconSize();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho do ícone, em pixels.  
  
##  <a name="getparams"></a>CMFCToolTipCtrl::GetParams  
 Retorna as configurações de exibição de uma dica de ferramenta.  
  
```  
const CMFCToolTipInfo& GetParams() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 As configurações de exibição de dica de ferramenta atual, que são armazenadas em um [CMFCToolTipInfo classe](../../mfc/reference/cmfctooltipinfo-class.md) objeto.  
  
##  <a name="ondrawborder"></a>CMFCToolTipCtrl::OnDrawBorder  
 Desenha a borda de uma dica de ferramenta.  
  
```  
virtual void OnDrawBorder(
    CDC* pDC,  
    CRect rect,  
    COLORREF clrLine);
```  
  
### <a name="parameters"></a>Parâmetros  
 `[in] pDC`  
 Ponteiro para um contexto de dispositivo.  
  
 `[in] rect`  
 O retângulo delimitador da dica de ferramenta.  
  
 `[in] clrLine`  
 A cor da borda.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método em uma classe derivada para personalizar a aparência da borda da dica de ferramenta.  
  
##  <a name="ondrawdescription"></a>CMFCToolTipCtrl::OnDrawDescription  

  
```  
virtual CSize OnDrawDescription(
    CDC* pDC,  
    CRect rect,  
    BOOL bCalcOnly);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 [in] `rect`  
 [in] `bCalcOnly`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondrawicon"></a>CMFCToolTipCtrl::OnDrawIcon  
 Exibe um ícone em uma dica de ferramenta.  
  
```  
virtual BOOL OnDrawIcon(
    CDC* pDC,  
    CRect rectImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `rectImage`  
 Coordenadas do ícone.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o ícone foi desenhado. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método em uma classe derivada para exibir um ícone personalizado. Você também deve substituir [CMFCToolTipCtrl::GetIconSize](#geticonsize) para habilitar a dica de ferramenta calcular corretamente o layout de texto e descrição.  
  
##  <a name="ondrawlabel"></a>CMFCToolTipCtrl::OnDrawLabel  
 Desenha o rótulo de uma dica de ferramenta ou calcula o tamanho do rótulo.  
  
```  
virtual CSize OnDrawLabel(
    CDC* pDC,  
    CRect rect,  
    BOOL bCalcOnly);
```  
  
### <a name="parameters"></a>Parâmetros  
 `[in] pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 `[in] rect`  
 Retângulo delimitador da área do rótulo.  
  
 `[in] bCalcOnly`  
 Se `TRUE`, o rótulo não será desenhado.  
  
### <a name="return-value"></a>Valor de retorno  
 Tamanho do rótulo, em pixels.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método em uma classe derivada, se você quiser personalizar a aparência do rótulo de dica de ferramenta.  
  
##  <a name="ondrawseparator"></a>CMFCToolTipCtrl::OnDrawSeparator  
 Desenha o separador entre o rótulo e a descrição em uma dica de ferramenta.  
  
```  
virtual void OnDrawSeparator(
    CDC* pDC,  
    int x1,  
    int x2,  
    int y);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `x1`  
 Coordenada horizontal da extremidade esquerda do separador.  
  
 [in] `x2`  
 Coordenada horizontal da extremidade direita do separador.  
  
 [in] `Y`  
 Coordenada vertical do separador.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão desenha uma linha do ponto (x1, y) para o ponto (x2, y).  
  
 Substitua este método em uma classe derivada para personalizar a aparência do separador.  
  
##  <a name="onfillbackground"></a>CMFCToolTipCtrl::OnFillBackground  
 Preenche o plano de fundo da dica de ferramenta.  
  
```  
virtual void OnFillBackground(
    CDC* pDC,  
    CRect rect,  
    COLORREF& clrText,  
    COLORREF& clrLine);
```  
  
### <a name="parameters"></a>Parâmetros  
 `[in] pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 `[in] rect`  
 Especifica o retângulo delimitador da área de preenchimento.  
  
 `[in] clrText`  
 Cor de primeiro plano da dica de ferramenta.  
  
 `[in] clrLine`  
 Cor de bordas e o delimitador da linha entre o rótulo e descrição.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão preenche o retângulo especificado por `rect` com a cor ou o padrão especificado pela chamada mais recente para [CMFCToolTipCtrl::SetParams](#setparams).  
  
 Substitua este método em uma classe derivada, se você quiser personalizar a aparência da dica de ferramenta.  
  
##  <a name="setdescription"></a>CMFCToolTipCtrl::SetDescription  
 Define a descrição a ser exibido por tooltip.  
  
```  
virtual void SetDescription(const CString strDesrciption);
```  
  
### <a name="parameters"></a>Parâmetros  
 `[in] strDesrciption`  
 Texto de descrição.  
  
### <a name="remarks"></a>Comentários  
 O texto de descrição é exibido na dica de ferramenta no separador.  
  
##  <a name="setfixedwidth"></a>CMFCToolTipCtrl::SetFixedWidth  

  
```  
void SetFixedWidth(
    int nWidthRegular,  
    int nWidthLargeImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nWidthRegular`  
 [in] `nWidthLargeImage`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="sethotribbonbutton"></a>CMFCToolTipCtrl::SetHotRibbonButton  

  
```  
void SetHotRibbonButton(CMFCRibbonButton* pRibbonButton);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pRibbonButton`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setlocation"></a>CMFCToolTipCtrl::SetLocation  

  
```  
void SetLocation(CPoint pt);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pt`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setparams"></a>CMFCToolTipCtrl::SetParams  
 Especifica a aparência visual de uma dica de ferramenta usando um [CMFCToolTipInfo classe](../../mfc/reference/cmfctooltipinfo-class.md) objeto.  
  
```  
void SetParams(CMFCToolTipInfo* pParams);
```  
  
### <a name="parameters"></a>Parâmetros  
 `[in] pParams`  
 Ponteiro para um [CMFCToolTipInfo classe](../../mfc/reference/cmfctooltipinfo-class.md) objeto que contém os parâmetros de exibição.  
  
### <a name="remarks"></a>Comentários  
 Sempre que a dica de ferramenta é exibida, ela é desenhada usando as cores e estilos visuais que `pParams` especifica. O valor de `pParams` é armazenado no membro protegido `m_Params`, que pode ser acessado por uma classe derivada que substitui [CMFCToolTipCtrl::OnDrawBorder](#ondrawborder), [CMFCToolTipCtrl::OnDrawIcon](#ondrawicon), [CMFCToolTipCtrl::OnDrawLabel](#ondrawlabel), [CMFCToolTipCtrl::OnDrawSeparator](#ondrawseparator), ou [CMFCToolTipCtrl::OnFillBackground](#onfillbackground) para manter o aparência especificada.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md)   
 [Classe CTooltipManager](../../mfc/reference/ctooltipmanager-class.md)   
 [Classe CMFCToolTipInfo](../../mfc/reference/cmfctooltipinfo-class.md)   
 [Classe CWinAppEx](../../mfc/reference/cwinappex-class.md)
