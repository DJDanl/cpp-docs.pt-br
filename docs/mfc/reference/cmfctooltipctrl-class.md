---
title: Classe CMFCToolTipCtrl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCToolTipCtrl
dev_langs:
- C++
helpviewer_keywords:
- CMFCToolTipCtrl class
ms.assetid: 9fbfcfb1-a8ab-417f-ae29-9a9ca85ee58f
caps.latest.revision: 33
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: c4acd1cff8b3ce6fb4815ad78ad91225b385d547
ms.lasthandoff: 02/25/2017

---
# <a name="cmfctooltipctrl-class"></a>Classe CMFCToolTipCtrl
Uma implementação de dica de ferramenta estendida com base no [classe CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md). Uma dica de ferramenta com base no `CMFCToolTipCtrl` classe pode exibir um ícone, um rótulo e uma descrição. Você pode personalizar sua aparência visual usando um preenchimento de gradiente, texto personalizado e cores de borda, negrito, cantos arredondados ou um estilo de balão.  
  
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
|[CMFCToolTipCtrl::SetDescription](#setdescription)|Define a descrição a ser exibida com a dica de ferramenta.|  
|[CMFCToolTipCtrl::SetFixedWidth](#setfixedwidth)||  
|[CMFCToolTipCtrl::SetHotRibbonButton](#sethotribbonbutton)||  
|[CMFCToolTipCtrl::SetLocation](#setlocation)||  
|[CMFCToolTipCtrl::SetParams](#setparams)|Especifica a aparência visual de uma dica de ferramenta usando um `CMFCToolTipInfo` objeto.|  
  
## <a name="remarks"></a>Comentários  
 Use `CMFCToolTipCtrl`, `CMFCToolTipInfo`, e [CTooltipManager classe](../../mfc/reference/ctooltipmanager-class.md) objetos juntas para implementar a dicas de ferramenta personalizadas em seu aplicativo.  
  
 Por exemplo, para usar dicas de ferramentas em estilo de balão, siga estas etapas:  
  
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
Para restaurar o padrão a dica de ferramenta classe de controle e redefinir a aparência de dica de ferramenta para seu estado padrão, especifique NULL nos runtime classe e dica de ferramenta informações sobre parâmetros de `SetTooltipParams`:  
  
```  
theApp.GetTooltipManager ()->SetTooltipParams (AFX_TOOLTIP_TYPE_ALL,  
    NULL,
    NULL);
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar um `CMFCToolTipCtrl` do objeto, defina a descrição que exibe a dica de ferramenta e defina a largura do controle dica de ferramenta.  
  
 [!code-cpp[41 NVC_MFC_RibbonApp](../../mfc/reference/codesnippet/cpp/cmfctooltipctrl-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md)  
  
 [CMFCToolTipCtrl](../../mfc/reference/cmfctooltipctrl-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtooltipctrl.h  
  
##  <a name="a-namecmfctooltipctrla--cmfctooltipctrlcmfctooltipctrl"></a><a name="cmfctooltipctrl"></a>CMFCToolTipCtrl::CMFCToolTipCtrl  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CMFCToolTipCtrl(CMFCToolTipInfo* pParams = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pParams`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegeticonsizea--cmfctooltipctrlgeticonsize"></a><a name="geticonsize"></a>CMFCToolTipCtrl::GetIconSize  
 Retorna o tamanho de um ícone em uma dica de ferramenta.  
  
```  
virtual CSize GetIconSize();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho do ícone, em pixels.  
  
##  <a name="a-namegetparamsa--cmfctooltipctrlgetparams"></a><a name="getparams"></a>CMFCToolTipCtrl::GetParams  
 Retorna as configurações de exibição de uma dica de ferramenta.  
  
```  
const CMFCToolTipInfo& GetParams() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 As configurações de exibição de dica de ferramenta atual, que são armazenadas em uma [CMFCToolTipInfo classe](../../mfc/reference/cmfctooltipinfo-class.md) objeto.  
  
##  <a name="a-nameondrawbordera--cmfctooltipctrlondrawborder"></a><a name="ondrawborder"></a>CMFCToolTipCtrl::OnDrawBorder  
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
 Cor da borda.  
  
### <a name="remarks"></a>Comentários  
 Substitua esse método em uma classe derivada para personalizar a aparência da borda da dica de ferramenta.  
  
##  <a name="a-nameondrawdescriptiona--cmfctooltipctrlondrawdescription"></a><a name="ondrawdescription"></a>CMFCToolTipCtrl::OnDrawDescription  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
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
  
##  <a name="a-nameondrawicona--cmfctooltipctrlondrawicon"></a><a name="ondrawicon"></a>CMFCToolTipCtrl::OnDrawIcon  
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
 `TRUE`Se o ícone de desenho. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Substitua esse método em uma classe derivada para exibir um ícone personalizado. Você também deve substituir [CMFCToolTipCtrl::GetIconSize](#geticonsize) para habilitar a dica de ferramenta calcular corretamente o layout de texto e descrição.  
  
##  <a name="a-nameondrawlabela--cmfctooltipctrlondrawlabel"></a><a name="ondrawlabel"></a>CMFCToolTipCtrl::OnDrawLabel  
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
 Substitua esse método em uma classe derivada se você quiser personalizar a aparência do rótulo de dica de ferramenta.  
  
##  <a name="a-nameondrawseparatora--cmfctooltipctrlondrawseparator"></a><a name="ondrawseparator"></a>CMFCToolTipCtrl::OnDrawSeparator  
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
  
 Substitua esse método em uma classe derivada para personalizar a aparência do separador.  
  
##  <a name="a-nameonfillbackgrounda--cmfctooltipctrlonfillbackground"></a><a name="onfillbackground"></a>CMFCToolTipCtrl::OnFillBackground  
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
 Cor das bordas e a linha de delimitador entre rótulo e descrição.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão preenche o retângulo que é especificado pelo `rect` com a cor ou o padrão especificado pela chamada mais recente para [CMFCToolTipCtrl::SetParams](#setparams).  
  
 Substitua esse método em uma classe derivada se você quiser personalizar a aparência da dica de ferramenta.  
  
##  <a name="a-namesetdescriptiona--cmfctooltipctrlsetdescription"></a><a name="setdescription"></a>CMFCToolTipCtrl::SetDescription  
 Define a descrição a ser exibida com a dica de ferramenta.  
  
```  
virtual void SetDescription(const CString strDesrciption);
```  
  
### <a name="parameters"></a>Parâmetros  
 `[in] strDesrciption`  
 Texto de descrição.  
  
### <a name="remarks"></a>Comentários  
 O texto de descrição é exibido na dica de ferramenta sob o separador.  
  
##  <a name="a-namesetfixedwidtha--cmfctooltipctrlsetfixedwidth"></a><a name="setfixedwidth"></a>CMFCToolTipCtrl::SetFixedWidth  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void SetFixedWidth(
    int nWidthRegular,  
    int nWidthLargeImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nWidthRegular`  
 [in] `nWidthLargeImage`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesethotribbonbuttona--cmfctooltipctrlsethotribbonbutton"></a><a name="sethotribbonbutton"></a>CMFCToolTipCtrl::SetHotRibbonButton  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void SetHotRibbonButton(CMFCRibbonButton* pRibbonButton);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pRibbonButton`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetlocationa--cmfctooltipctrlsetlocation"></a><a name="setlocation"></a>CMFCToolTipCtrl::SetLocation  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void SetLocation(CPoint pt);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pt`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetparamsa--cmfctooltipctrlsetparams"></a><a name="setparams"></a>CMFCToolTipCtrl::SetParams  
 Especifica a aparência visual de uma dica de ferramenta usando um [CMFCToolTipInfo classe](../../mfc/reference/cmfctooltipinfo-class.md) objeto.  
  
```  
void SetParams(CMFCToolTipInfo* pParams);
```  
  
### <a name="parameters"></a>Parâmetros  
 `[in] pParams`  
 Ponteiro para uma [CMFCToolTipInfo classe](../../mfc/reference/cmfctooltipinfo-class.md) objeto que contém os parâmetros de exibição.  
  
### <a name="remarks"></a>Comentários  
 Sempre que a dica de ferramenta é exibida, ela é desenhada usando as cores e estilos visuais que `pParams` especifica. O valor de `pParams` é armazenado no membro protegido `m_Params`, que pode ser acessada por uma classe derivada que substitui [CMFCToolTipCtrl::OnDrawBorder](#ondrawborder), [CMFCToolTipCtrl::OnDrawIcon](#ondrawicon), [CMFCToolTipCtrl::OnDrawLabel](#ondrawlabel), [CMFCToolTipCtrl::OnDrawSeparator](#ondrawseparator), ou [CMFCToolTipCtrl::OnFillBackground](#onfillbackground) para manter a aparência especificada.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md)   
 [Classe CTooltipManager](../../mfc/reference/ctooltipmanager-class.md)   
 [Classe CMFCToolTipInfo](../../mfc/reference/cmfctooltipinfo-class.md)   
 [Classe de CWinAppEx](../../mfc/reference/cwinappex-class.md)

