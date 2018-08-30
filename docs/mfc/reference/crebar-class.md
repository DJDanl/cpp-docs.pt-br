---
title: Classe CReBar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CReBar
- AFXEXT/CReBar
- AFXEXT/CReBar::AddBar
- AFXEXT/CReBar::Create
- AFXEXT/CReBar::GetReBarCtrl
dev_langs:
- C++
helpviewer_keywords:
- CReBar [MFC], AddBar
- CReBar [MFC], Create
- CReBar [MFC], GetReBarCtrl
ms.assetid: c1ad2720-1d33-4106-8e4e-80aa84f93559
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 61601baca7a91d76f473281184c335cc5277f815
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43201848"
---
# <a name="crebar-class"></a>Classe CReBar
Uma barra de controle que fornece o layout, persistência e informações de estado para controles rebar.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CReBar : public CControlBar  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CReBar::AddBar](#addbar)|Adiciona uma faixa de um rebar.|  
|[CReBar::Create](#create)|Cria um controle rebar e anexa-o para o `CReBar` objeto.|  
|[CReBar::GetReBarCtrl](#getrebarctrl)|Permite acesso direto ao controle comum subjacente.|  
  
## <a name="remarks"></a>Comentários  
 Um objeto de rebar pode conter uma variedade de janelas filho, geralmente outros controles, incluindo caixas de listagem, barras de ferramentas e caixas de edição. Um objeto de rebar pode exibir suas janelas filho ao longo de um bitmap especificado. Seu aplicativo pode redimensionar automaticamente o rebar, ou o usuário pode redimensionar manualmente o rebar clicando ou arrastando sua barra de garra.  
  
 ![Exemplo de RebarMenu](../../mfc/reference/media/vc4sc61.gif "vc4sc61")  
  
## <a name="rebar-control"></a>Controle rebar  
 Um objeto de rebar se comporta da mesma forma para um objeto de barra de ferramentas. Um rebar usa o mecanismo de clique e arraste para redimensionar suas faixas. Um controle rebar pode conter um ou mais faixas, com cada faixa ter qualquer combinação de uma barra de garra, um bitmap, um rótulo de texto e uma janela filho. No entanto, as faixas não podem conter mais de uma janela filho.  
  
 `CReBar` usa o [CReBarCtrl](../../mfc/reference/crebarctrl-class.md) classe para fornecer sua implementação. Você pode acessar o controle rebar por meio [GetReBarCtrl](#getrebarctrl) para tirar proveito das opções de personalização do controle. Para obter mais informações sobre controles rebar, consulte `CReBarCtrl`. Para obter mais informações sobre como usar controles rebar, consulte [usando CReBarCtrl](../../mfc/using-crebarctrl.md).  
  
> [!CAUTION]
>  Rebar e objetos de controle rebar não oferecem suporte a controle MFC da barra de encaixe. Se `CRebar::EnableDocking` é chamado, declarará o seu aplicativo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CControlBar](../../mfc/reference/ccontrolbar-class.md)  
  
 `CReBar`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxext.h  
  
##  <a name="addbar"></a>  CReBar::AddBar  
 Chame essa função de membro para adicionar uma faixa de rebar.  
  
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
 *pBar*  
 Um ponteiro para um `CWnd` objeto que é a janela filho a ser inserido no rebar. O objeto referenciado deve ter um WS_CHILD.  
  
 *lpszText*  
 Um ponteiro para uma cadeia de caracteres que contém o texto para aparecer em rebar. NULL por padrão. O texto contido em *lpszText* não é parte da janela filho; ele está em rebar em si.  
  
 *pbmp*  
 Um ponteiro para um `CBitmap` objeto a ser exibido no plano de fundo de rebar. NULL por padrão.  
  
 *dwStyle*  
 Um DWORD que contém o estilo para aplicar a rebar. Consulte a `fStyle` descrição na estrutura Win32 da função [REBARBANDINFO](/windows/desktop/api/commctrl/ns-commctrl-tagrebarbandinfoa) para obter uma lista completa dos estilos de banda.  
  
 *clrFore*  
 Um valor COLORREF que representa a cor de primeiro plano do rebar.  
  
 *clrBack*  
 Um valor COLORREF que representa a cor do plano de fundo do rebar.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CReBarCtrl#1](../../mfc/reference/codesnippet/cpp/crebar-class_1.cpp)]  
  
##  <a name="create"></a>  CReBar::Create  
 Chame essa função de membro para criar um rebar.  
  
```  
virtual BOOL Create(
    CWnd* pParentWnd,  
    DWORD dwCtrlStyle = RBS_BANDBORDERS,  
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_TOP,  
    UINT nID = AFX_IDW_REBAR);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pParentWnd*  
 Ponteiro para o `CWnd` objeto cuja janela do Windows é o pai da barra de status. Normalmente, a janela do quadro.  
  
 *dwCtrlStyle*  
 O estilo do controle rebar. Por padrão, RBS_BANDBORDERS, que exibe linhas estreitas para separar as faixas adjacentes dentro do controle rebar. Ver [estilos de controle Rebar](/windows/desktop/Controls/rebar-control-styles) no SDK do Windows para obter uma lista de estilos.  
  
 *dwStyle*  
 Os estilos de janela de rebar.  
  
 *nID*  
 ID da janela filho. de rebar  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CReBar::AddBar](#addbar).  
  
##  <a name="getrebarctrl"></a>  CReBar::GetReBarCtrl  
 Essa função membro permite acesso direto ao controle comum subjacente.  
  
```  
CReBarCtrl& GetReBarCtrl() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a um [CReBarCtrl](../../mfc/reference/crebarctrl-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função de membro para tirar proveito da funcionalidade do controle comum rebar Windows personalizar seu rebar. Quando você chama `GetReBarCtrl`, ele retorna um objeto de referência para o `CReBarCtrl` , você pode usar o conjunto de funções de membro de objeto.  
  
 Para obter mais informações sobre como usar `CReBarCtrl` para personalizar seu rebar, consulte [usando CReBarCtrl](../../mfc/using-crebarctrl.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CReBarCtrl#2](../../mfc/reference/codesnippet/cpp/crebar-class_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MFCIE](../../visual-cpp-samples.md)   
 [Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



