---
title: Classe CReBar | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2cd32c4df0465426d99ca6246648520d160f382e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="crebar-class"></a>Classe CReBar
Uma barra de controle que fornece informações de estado para controles rebar, persistência e layout.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CReBar : public CControlBar  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CReBar::AddBar](#addbar)|Adiciona uma faixa para um rebar.|  
|[CReBar::Create](#create)|Cria um controle rebar e anexa-o para o `CReBar` objeto.|  
|[CReBar::GetReBarCtrl](#getrebarctrl)|Permite acesso direto ao controle comum subjacente.|  
  
## <a name="remarks"></a>Comentários  
 Um objeto de rebar pode conter uma variedade de janelas filho, geralmente outros controles, incluindo caixas de edição, barras de ferramentas e caixas de listagem. Um objeto de rebar pode exibir janelas filho em um bitmap especificado. Seu aplicativo pode redimensionar automaticamente o rebar ou o usuário pode redimensionar manualmente rebar clicando ou arrastando sua barra dupla.  
  
 ![Exemplo de RebarMenu](../../mfc/reference/media/vc4sc61.gif "vc4sc61")  
  
## <a name="rebar-control"></a>Controle rebar  
 Um objeto de rebar se comporta de maneira semelhante a um objeto de barra de ferramentas. Um rebar usa o mecanismo de clique e arraste para redimensionar seus faixas. Um controle rebar pode conter uma ou mais faixas, com cada faixa com qualquer combinação de uma barra dupla, um bitmap, um rótulo de texto e uma janela filho. No entanto, as faixas não podem conter mais de uma janela filho.  
  
 **CReBar** usa o [CReBarCtrl](../../mfc/reference/crebarctrl-class.md) classe para fornecer sua implementação. Você pode acessar o controle rebar por meio de [GetReBarCtrl](#getrebarctrl) para tirar proveito das opções de personalização do controle. Para obter mais informações sobre controles rebar, consulte `CReBarCtrl`. Para obter mais informações sobre como usar controles rebar, consulte [usando CReBarCtrl](../../mfc/using-crebarctrl.md).  
  
> [!CAUTION]
>  Rebar e objetos de controle rebar não dão suporte a controle MFC ancoragem de barra. Se **CRebar::EnableDocking** é chamado, declarará seu aplicativo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CControlBar](../../mfc/reference/ccontrolbar-class.md)  
  
 `CReBar`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxext.h  
  
##  <a name="addbar"></a>CReBar::AddBar  
 Chame essa função de membro para adicionar uma faixa rebar.  
  
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
 `pBar`  
 Um ponteiro para um `CWnd` objeto que é a janela filho a ser inserido na rebar. O objeto referenciado deve ter uma **WS_CHILD**.  
  
 `lpszText`  
 Um ponteiro para uma cadeia de caracteres que contém o texto a ser exibido em rebar. **NULO** por padrão. O texto contido em `lpszText` não é parte da janela filho; está em rebar em si.  
  
 `pbmp`  
 Um ponteiro para um `CBitmap` objeto a ser exibido no plano de fundo rebar. **NULO** por padrão.  
  
 `dwStyle`  
 Um `DWORD` que contém o estilo a ser aplicado ao rebar. Consulte o **fStyle** descrição na estrutura de Win32 da função [REBARBANDINFO](http://msdn.microsoft.com/library/windows/desktop/bb774393) para obter uma lista de estilos de banda.  
  
 *clrFore*  
 Um **COLORREF** valor que representa a cor de primeiro plano do rebar.  
  
 *clrBack*  
 Um **COLORREF** valor que representa a cor de plano de fundo do rebar.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CReBarCtrl#1](../../mfc/reference/codesnippet/cpp/crebar-class_1.cpp)]  
  
##  <a name="create"></a>CReBar::Create  
 Chame essa função de membro para criar um rebar.  
  
```  
virtual BOOL Create(
    CWnd* pParentWnd,  
    DWORD dwCtrlStyle = RBS_BANDBORDERS,  
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_TOP,  
    UINT nID = AFX_IDW_REBAR);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParentWnd`  
 Ponteiro para o `CWnd` objeto cuja janela do Windows é o pai da barra de status. Normalmente, a janela do quadro.  
  
 `dwCtrlStyle`  
 O estilo do controle rebar. Por padrão, **RBS_BANDBORDERS**, que exibe restringir linhas para separar as faixas adjacentes dentro do controle rebar. Consulte [estilos de controle Rebar](http://msdn.microsoft.com/library/windows/desktop/bb774377) no SDK do Windows para obter uma lista de estilos.  
  
 `dwStyle`  
 Os estilos de janela rebar.  
  
 `nID`  
 ID de janela filho. do rebar  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CReBar::AddBar](#addbar).  
  
##  <a name="getrebarctrl"></a>CReBar::GetReBarCtrl  
 Essa função de membro permite acesso direto ao controle comum subjacente.  
  
```  
CReBarCtrl& GetReBarCtrl() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a um [CReBarCtrl](../../mfc/reference/crebarctrl-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função de membro para tirar proveito da funcionalidade do controle comum rebar Windows nos Personalizando seu rebar. Quando você chama `GetReBarCtrl`, ele retorna um objeto de referência para o `CReBarCtrl` , você pode usar um conjunto de funções de membro de objeto.  
  
 Para obter mais informações sobre como usar `CReBarCtrl` para personalizar seu rebar, consulte [usando CReBarCtrl](../../mfc/using-crebarctrl.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CReBarCtrl#2](../../mfc/reference/codesnippet/cpp/crebar-class_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MFCIE](../../visual-cpp-samples.md)   
 [Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



