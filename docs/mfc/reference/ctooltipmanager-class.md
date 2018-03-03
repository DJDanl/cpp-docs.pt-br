---
title: Classe CTooltipManager | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CTooltipManager
- AFXTOOLTIPMANAGER/CTooltipManager
- AFXTOOLTIPMANAGER/CTooltipManager::CreateToolTip
- AFXTOOLTIPMANAGER/CTooltipManager::DeleteToolTip
- AFXTOOLTIPMANAGER/CTooltipManager::SetTooltipParams
- AFXTOOLTIPMANAGER/CTooltipManager::SetTooltipText
- AFXTOOLTIPMANAGER/CTooltipManager::UpdateTooltips
dev_langs:
- C++
helpviewer_keywords:
- CTooltipManager [MFC], CreateToolTip
- CTooltipManager [MFC], DeleteToolTip
- CTooltipManager [MFC], SetTooltipParams
- CTooltipManager [MFC], SetTooltipText
- CTooltipManager [MFC], UpdateTooltips
ms.assetid: c71779d7-8b6e-47ef-8500-d4552731fe86
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2adb62f107cb50ade529d552ce1735c57f74b171
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ctooltipmanager-class"></a>Classe CTooltipManager
Mantém informações de tempo de execução sobre dicas de ferramenta. O `CTooltipManager` classe é instanciada uma vez por aplicativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CTooltipManager : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CTooltipManager::CreateToolTip](#createtooltip)|Cria um controle de dica de ferramenta para os tipos especificados de controle do Windows.|  
|[CTooltipManager::DeleteToolTip](#deletetooltip)|Exclui um controle de dica de ferramenta.|  
|[CTooltipManager::SetTooltipParams](#settooltipparams)|Personaliza a aparência visual do controle de dica de ferramenta para os tipos especificados de controle do Windows.|  
|[CTooltipManager::SetTooltipText](#settooltiptext)|Define o texto e a descrição de um controle de dica de ferramenta.|  
|[CTooltipManager::UpdateTooltips](#updatetooltips)||  
  
## <a name="remarks"></a>Comentários  
 Use [CMFCToolTipCtrl classe](../../mfc/reference/cmfctooltipctrl-class.md), `CMFCToolTipInfo`, e `CTooltipManager` para implementar dicas de ferramenta personalizadas em seu aplicativo. Para obter um exemplo de como usar essas classes de dica de ferramenta, consulte o [CMFCToolTipCtrl classe](../../mfc/reference/cmfctooltipctrl-class.md) tópico.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CTooltipManager](../../mfc/reference/ctooltipmanager-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtooltipmanager.h  
  
##  <a name="createtooltip"></a>CTooltipManager::CreateToolTip  
 Cria um controle de dica de ferramenta.  
  
```  
static BOOL CreateToolTip(
    CToolTipCtrl*& pToolTip,  
    CWnd* pWndParent,  
    UINT nType);
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `pToolTip`  
 Uma referência a um ponteiro de dica de ferramenta. Ela é definida para apontar para a dica de ferramenta recém-criado quando a função retorna.  
  
 [in] `pWndParent`  
 Pai da dica de ferramenta.  
  
 [in] `nType`  
 Tipo de dica de ferramenta.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se uma dica de ferramenta tiver sido criada com êxito.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar [CTooltipManager::DeleteToolTip](#deletetooltip) para excluir o controle de dica de ferramenta que é passado de volta no `pToolTip`.  
  
 O [CTooltipManager](../../mfc/reference/ctooltipmanager-class.md) define os parâmetros de exibição visual de cada dica de ferramenta que cria com base na dica de ferramenta do tipo que `nType` especifica. Para alterar os parâmetros para um ou mais tipos de dica de ferramenta, chame [CTooltipManager::SetTooltipParams](#settooltipparams).  
  
 Tipos de dica de ferramenta válidos estão listados na tabela a seguir:  
  
|Tipo de dica de ferramenta|Categoria de controle|Exemplos de tipos|  
|------------------|----------------------|-------------------|  
|AFX_TOOLTIP_TYPE_BUTTON|Um botão.|CMFCButton|  
|AFX_TOOLTIP_TYPE_CAPTIONBAR|Uma barra de legenda.|CMFCCaptionBar|  
|AFX_TOOLTIP_TYPE_DEFAULT|Qualquer controle que não é adequado para outra categoria.|nenhuma.|  
|AFX_TOOLTIP_TYPE_DOCKBAR|Um painel encaixável.|CDockablePane|  
|AFX_TOOLTIP_TYPE_EDIT|Uma caixa de texto.|nenhuma.|  
|AFX_TOOLTIP_TYPE_MINIFRAME|Um miniquadros.|CPaneFrameWnd|  
|AFX_TOOLTIP_TYPE_PLANNER|Um planejamento.|nenhuma.|  
|AFX_TOOLTIP_TYPE_RIBBON|Uma barra de faixa de opções.|CMFCRibbonBar, CMFCRibbonPanelMenuBar|  
|AFX_TOOLTIP_TYPE_TAB|Um controle de guia.|CMFCTabCtrl|  
|AFX_TOOLTIP_TYPE_TOOLBAR|Uma barra de ferramentas.|CMFCToolBar, CMFCPopupMenuBar|  
|AFX_TOOLTIP_TYPE_TOOLBOX|Uma caixa de ferramentas.|nenhuma.|  
  
##  <a name="deletetooltip"></a>CTooltipManager::DeleteToolTip  
 Exclui um controle de dica de ferramenta.  
  
```  
static void DeleteToolTip(CToolTipCtrl*& pToolTip);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in, out] `pToolTip`  
 Uma referência a um ponteiro para uma dica de ferramenta a ser destruído.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para cada [classe CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md) que foi criado por [CTooltipManager::CreateToolTip](#createtooltip). O controle pai deve chamar esse método de sua `OnDestroy` manipulador. Isso é necessário para remover a dica de ferramenta do framework. Esse método define `pToolTip` para `NULL` antes de retornar.  
  
##  <a name="settooltipparams"></a>CTooltipManager::SetTooltipParams  
 Personaliza a aparência do controle de dica de ferramenta para os tipos de controle do Windows especificados.  
  
```  
void SetTooltipParams(
    UINT nTypes,  
    CRuntimeClass* pRTC=RUNTIME_CLASS(CMFCToolTipCtrl),  
    CMFCToolTipInfo* pParams=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nTypes`  
 Especifica os tipos de controle.  
  
 [in] `pRTC`  
 Classe de tempo de execução da dica de ferramenta personalizada.  
  
 [in] `pParams`  
 Parâmetros de dica de ferramenta.  
  
### <a name="remarks"></a>Comentários  
 Esse método define a classe de tempo de execução e os parâmetros iniciais que o [CToolTipManager](../../mfc/reference/ctooltipmanager-class.md) usa quando ele cria dicas de ferramenta. Quando um controle chama [CTooltipManager::CreateToolTip](#createtooltip) e passa em uma dica de ferramenta tipo que é um dos tipos indicados pelo `nTypes`, o Gerenciador de dica de ferramenta cria um controle de dica de ferramenta que é uma instância da classe de tempo de execução especificada por `pRTC` e passa os parâmetros especificados pelo `pParams` à nova dica de ferramenta.  
  
 Quando você chamar esse método, todos os proprietários existentes de dica de ferramenta a mensagem AFX_WM_UPDATETOOLTIPS e eles devem recriar suas dicas de ferramentas usando [CTooltipManager::CreateToolTip](#createtooltip).  
  
 `nTypes`pode ser qualquer combinação de dica de ferramenta válida tipos [CTooltipManager::CreateToolTip](#createtooltip) usa, ou pode ser AFX_TOOLTIP_TYPE_ALL. Se você passar AFX_TOOLTIP_TYPE_ALL, todos os tipos de dica de ferramenta serão afetados.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `SetTooltipParams` método o `CTooltipManager` classe. Este trecho de código é parte do [desenhar cliente de exemplo](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_DrawClient#11](../../mfc/reference/codesnippet/cpp/ctooltipmanager-class_1.cpp)]  
  
##  <a name="settooltiptext"></a>CTooltipManager::SetTooltipText  
 Define o texto e a descrição de uma dica de ferramenta.  
  
```  
static void SetTooltipText(
    TOOLINFO* pTI,  
    CToolTipCtrl* pToolTip,  
    UINT nType,  
    const CString strText,  
    LPCTSTR lpszDescr=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pTI`  
 Um ponteiro para um objeto TOOLINFO.  
  
 [in, out] `pToolTip`  
 Um ponteiro para o controle de dica de ferramenta para o qual definir o texto e a descrição.  
  
 [in] `nType`  
 Especifica o tipo de controle com o qual esta dica de ferramenta está associada.  
  
 [in] `strText`  
 O texto a ser definido como o texto de dica de ferramenta.  
  
 [in] `lpszDescr`  
 Um ponteiro para a descrição de dica de ferramenta. Pode ser `NULL`.  
  
### <a name="remarks"></a>Comentários  
 O valor de `nType` deve ser o mesmo valor que o `nType` parâmetro [CTooltipManager::CreateToolTip](#createtooltip) quando criou a dica de ferramenta.  
  
##  <a name="updatetooltips"></a>CTooltipManager::UpdateTooltips  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void UpdateTooltips();
```  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCToolTipCtrl](../../mfc/reference/cmfctooltipctrl-class.md)   
 [Classe CMFCToolTipInfo](../../mfc/reference/cmfctooltipinfo-class.md)
