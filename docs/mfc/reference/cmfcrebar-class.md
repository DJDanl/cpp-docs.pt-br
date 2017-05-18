---
title: Classe CMFCReBar | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCReBar
- AFXREBAR/CMFCReBar
- AFXREBAR/CMFCReBar::AddBar
- AFXREBAR/CMFCReBar::CalcFixedLayout
- AFXREBAR/CMFCReBar::CanFloat
- AFXREBAR/CMFCReBar::Create
- AFXREBAR/CMFCReBar::EnableDocking
- AFXREBAR/CMFCReBar::GetReBarBandInfoSize
- AFXREBAR/CMFCReBar::GetReBarCtrl
- AFXREBAR/CMFCReBar::OnShowControlBarMenu
- AFXREBAR/CMFCReBar::OnToolHitTest
- AFXREBAR/CMFCReBar::OnUpdateCmdUI
- AFXREBAR/CMFCReBar::SetPaneAlignment
dev_langs:
- C++
helpviewer_keywords:
- CMFCReBar class
ms.assetid: 02a60e29-6224-49c1-9e74-e0a7d9f8d023
caps.latest.revision: 27
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 5ec432cb8cf70d31c04c718fd7e802ee9c099763
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcrebar-class"></a>Classe CMFCReBar
Um `CMFCReBar` objeto é uma barra de controle que fornece informações de estado para controles rebar, persistência e layout.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCReBar : public CPane  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCReBar::AddBar](#addbar)|Adiciona uma faixa um rebar.|  
|[CMFCReBar::CalcFixedLayout](#calcfixedlayout)|(Substitui [CBasePane::CalcFixedLayout](../../mfc/reference/cbasepane-class.md#calcfixedlayout).)|  
|[CMFCReBar::CanFloat](#canfloat)|(Substitui [CBasePane::CanFloat](../../mfc/reference/cbasepane-class.md#canfloat).)|  
|[CMFCReBar::Create](#create)|Cria um controle rebar e anexa-o para o `CMFCReBar` objeto.|  
|[CMFCReBar::EnableDocking](#enabledocking)|(Substitui [CBasePane::EnableDocking](../../mfc/reference/cbasepane-class.md#enabledocking).)|  
|[CMFCReBar::GetReBarBandInfoSize](#getrebarbandinfosize)||  
|[CMFCReBar::GetReBarCtrl](#getrebarctrl)|Fornece acesso direto a subjacente [CReBarCtrl](../../mfc/reference/crebarctrl-class.md) controle comum.|  
|[CMFCReBar::OnShowControlBarMenu](#onshowcontrolbarmenu)|(Substitui [CPane::OnShowControlBarMenu](../../mfc/reference/cpane-class.md#onshowcontrolbarmenu).)|  
|[CMFCReBar::OnToolHitTest](#ontoolhittest)|(Substitui [CWnd::OnToolHitTest](../../mfc/reference/cwnd-class.md#ontoolhittest).)|  
|[CMFCReBar::OnUpdateCmdUI](#onupdatecmdui)|(Substitui [CBasePane::OnUpdateCmdUI](http://msdn.microsoft.com/en-us/e139f06a-9793-4ee2-bc3d-517389368c77).)|  
|[CMFCReBar::SetPaneAlignment](#setpanealignment)|(Substitui [CBasePane::SetPaneAlignment](../../mfc/reference/cbasepane-class.md#setpanealignment).)|  
  
## <a name="remarks"></a>Comentários  
 Um `CMFCReBar` objeto pode conter várias janelas filho. Isso inclui caixas de edição, barras de ferramentas e caixas de listagem. Você pode redimensionar o rebar programaticamente, ou o usuário pode redimensionar manualmente rebar arrastando a barra de garra. Você também pode definir o plano de fundo de um objeto rebar para um bitmap de sua escolha.  
  
 Um objeto rebar se comporta de forma semelhante a um objeto de barra de ferramentas. Um controle rebar pode conter uma ou mais faixas, e cada faixa pode conter uma barra dupla, um bitmap, um rótulo de texto e uma janela filho.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários métodos no `CMFCReBar` classe. O exemplo mostra como criar um controle rebar e adicionar uma faixa a ele. As funções de banda como uma barra de ferramentas interna. Este trecho de código é parte do [Rebar Test sample](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_RebarTest n º&1;](../../mfc/reference/codesnippet/cpp/cmfcrebar-class_1.h)]  
[!code-cpp[NVC_MFC_RebarTest n º&2;](../../mfc/reference/codesnippet/cpp/cmfcrebar-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md) [CCmdTarget](../../mfc/reference/ccmdtarget-class.md) [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md) [CPane](../../mfc/reference/cpane-class.md) [CMFCReBar](../../mfc/reference/cmfcrebar-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxRebar.h  
  
##  <a name="addbar"></a>CMFCReBar::AddBar  
 Adiciona uma faixa um rebar.  
  
```  
BOOL AddBar(
    CWnd* pBar,  
    LPCTSTR pszText = NULL,  
    CBitmap* pbmp = NULL,  
    DWORD dwStyle = RBBS_GRIPPERALWAYS | RBBS_FIXEDBMP);

BOOL AddBar(
    CWnd* pBar,  
    COLORREF clrFore,  
    COLORREF clrBack,  
    LPCTSTR pszText = NULL,  
    DWORD dwStyle = RBBS_GRIPPERALWAYS);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] [out]`pBar`  
 Um ponteiro para a janela filho que deve ser inserido no rebar. O objeto referenciado deve ter o **WS_CHILD** estilo da janela.  
  
 [in] `pszText`  
 Especifica o texto a ser exibido em rebar. O texto não é parte da janela filho. Em vez disso, ele é exibido na rebar em si.  
  
 [in] [out]`pbmp`  
 Especifica o bitmap a ser exibido no plano de fundo rebar.  
  
 [in] `dwStyle`  
 Contém o estilo a ser aplicado para a faixa. Para obter uma lista completa dos estilos de banda, consulte a descrição de `fStyle` no [REBARBANDINFO](http://msdn.microsoft.com/library/windows/desktop/bb774393) estrutura na documentação do SDK do Windows.  
  
 [in] `clrFore`  
 Representa a cor de primeiro plano do rebar.  
  
 [in] `clrBack`  
 Representa a cor de plano de fundo do rebar.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a faixa foi adicionada com êxito para o rebar; Caso contrário, `FALSE`.  
  
##  <a name="create"></a>CMFCReBar::Create  
 Cria um controle rebar e anexa-o para o [CMFCReBar](../../mfc/reference/cmfcrebar-class.md) objeto.  
  
```  
BOOL Create(
    CWnd* pParentWnd,  
    DWORD dwCtrlStyle = RBS_BANDBORDERS,  
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_TOP,  
    UINT nID = AFX_IDW_REBAR);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] [out]`pParentWnd`  
 Um ponteiro para a janela pai deste controle rebar.  
  
 [in] `dwCtrlStyle`  
 Especifica o estilo do controle rebar. O valor de estilo padrão é **RBS_BANDBORDERS**, que exibe restringir linhas para separar adjacentes bandas no controle rebar. Para obter uma lista dos estilos válidos, consulte [estilos de controle Rebar](http://msdn.microsoft.com/library/windows/desktop/bb774377) na documentação do SDK do Windows.  
  
 [in] `dwStyle`  
 O estilo da janela do controle rebar. Para obter uma lista dos estilos válidos, consulte [estilos de janela](../../mfc/reference/window-styles.md).  
  
 [in] `nID`  
 ID da janela filho. de rebar  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o rebar foi criado com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getrebarctrl"></a>CMFCReBar::GetReBarCtrl  
 Fornece acesso direto a `CReBarCtrl` controle comum subjacente para `CMFCReBar` objetos.  
  
```  
CReBarCtrl& GetReBarCtrl() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao subjacente `CReBarCtrl` objeto.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para aproveitar a funcionalidade de controle do Windows rebar comuns ao personalizar o rebar.  
  
##  <a name="calcfixedlayout"></a>CMFCReBar::CalcFixedLayout  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual CSize CalcFixedLayout(
    BOOL bStretch,  
    BOOL bHorz);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bStretch`  
 [in] `bHorz`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="canfloat"></a>CMFCReBar::CanFloat  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL CanFloat() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="enabledocking"></a>CMFCReBar::EnableDocking  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void EnableDocking(DWORD dwDockStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwDockStyle`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getrebarbandinfosize"></a>CMFCReBar::GetReBarBandInfoSize  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
UINT GetReBarBandInfoSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onshowcontrolbarmenu"></a>CMFCReBar::OnShowControlBarMenu  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL OnShowControlBarMenu(CPoint);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `CPoint`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ontoolhittest"></a>CMFCReBar::OnToolHitTest  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual INT_PTR OnToolHitTest(
    CPoint point,  
    TOOLINFO* pTI) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 [in] `pTI`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onupdatecmdui"></a>CMFCReBar::OnUpdateCmdUI  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void OnUpdateCmdUI(
    CFrameWnd* pTarget,  
    BOOL bDisableIfNoHndler);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pTarget`  
 [in] `bDisableIfNoHndler`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setpanealignment"></a>CMFCReBar::SetPaneAlignment  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void SetPaneAlignment(DWORD dwAlignment);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwAlignment`  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CReBarCtrl](../../mfc/reference/crebarctrl-class.md)   
 [Classe CPane](../../mfc/reference/cpane-class.md)

