---
title: Classe CReBar | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CReBar
dev_langs:
- C++
helpviewer_keywords:
- rebar controls, control bar
- CReBar class
- Internet Explorer 4.0 common controls
ms.assetid: c1ad2720-1d33-4106-8e4e-80aa84f93559
caps.latest.revision: 22
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
ms.openlocfilehash: 38ac4611503bec70ea9f809a4d4f9d4b5133e30e
ms.lasthandoff: 02/25/2017

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
|[CReBar::AddBar](#addbar)|Adiciona uma faixa um rebar.|  
|[CReBar::Create](#create)|Cria um controle rebar e anexa-o para o `CReBar` objeto.|  
|[CReBar::GetReBarCtrl](#getrebarctrl)|Permite acesso direto ao controle comum subjacente.|  
  
## <a name="remarks"></a>Comentários  
 Um objeto rebar pode conter várias janelas filho, geralmente outros controles, incluindo caixas de edição, barras de ferramentas e caixas de listagem. Um objeto rebar pode exibir suas janelas-filho em um bitmap especificado. Seu aplicativo pode redimensionar automaticamente o rebar, ou o usuário pode redimensionar manualmente rebar clicando ou arrastando a barra de garra.  
  
 ![Exemplo de RebarMenu](../../mfc/reference/media/vc4sc61.gif "vc4sc61")  
  
## <a name="rebar-control"></a>Controle rebar  
 Um objeto rebar se comporta de forma semelhante a um objeto de barra de ferramentas. Um rebar usa o mecanismo de clique e arraste para redimensionar suas faixas. Um controle rebar pode conter uma ou mais faixas, com cada faixa com qualquer combinação de uma barra dupla, um bitmap, um rótulo de texto e uma janela filho. No entanto, as faixas não podem conter mais de uma janela filho.  
  
 **CReBar** usa o [CReBarCtrl](../../mfc/reference/crebarctrl-class.md) classe para fornecer sua implementação. Você pode acessar o controle rebar por meio de [GetReBarCtrl](#getrebarctrl) para tirar proveito das opções de personalização do controle. Para obter mais informações sobre controles rebar, consulte `CReBarCtrl`. Para obter mais informações sobre como usar controles rebar, consulte [CReBarCtrl usando](../../mfc/using-crebarctrl.md).  
  
> [!CAUTION]
>  Espelhos e objetos de controle rebar dão suporte ao controle MFC ancoragem de barra. Se **CRebar::EnableDocking** é chamado, declarará o seu aplicativo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CControlBar](../../mfc/reference/ccontrolbar-class.md)  
  
 `CReBar`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxext.h  
  
##  <a name="a-nameaddbara--crebaraddbar"></a><a name="addbar"></a>CReBar::AddBar  
 Chame essa função de membro para adicionar uma faixa para o rebar.  
  
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
 Um ponteiro para uma cadeia de caracteres que contém o texto a ser exibido em rebar. **NULO** por padrão. O texto contido em `lpszText` não é parte da janela filho; está na rebar em si.  
  
 `pbmp`  
 Um ponteiro para um `CBitmap` objeto a ser exibido no plano de fundo rebar. **NULO** por padrão.  
  
 `dwStyle`  
 Um `DWORD` que contém o estilo a ser aplicado ao rebar. Consulte o **fStyle** descrição na estrutura do Win32 da função [REBARBANDINFO](http://msdn.microsoft.com/library/windows/desktop/bb774393) para obter uma lista completa dos estilos de banda.  
  
 *clrFore*  
 A **COLORREF** valor que representa a cor de primeiro plano do rebar.  
  
 *clrBack*  
 A **COLORREF** valor que representa a cor de plano de fundo do rebar.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CReBarCtrl n º&1;](../../mfc/reference/codesnippet/cpp/crebar-class_1.cpp)]  
  
##  <a name="a-namecreatea--crebarcreate"></a><a name="create"></a>CReBar::Create  
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
 O estilo do controle rebar. Por padrão, **RBS_BANDBORDERS**, que exibe restringir linhas para separar adjacentes bandas no controle rebar. Consulte [estilos de controle Rebar](http://msdn.microsoft.com/library/windows/desktop/bb774377) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter uma lista de estilos.  
  
 `dwStyle`  
 Os estilos de janela rebar.  
  
 `nID`  
 ID da janela filho. de rebar  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CReBar::AddBar](#addbar).  
  
##  <a name="a-namegetrebarctrla--crebargetrebarctrl"></a><a name="getrebarctrl"></a>CReBar::GetReBarCtrl  
 Essa função de membro permite acesso direto ao controle comum subjacente.  
  
```  
CReBarCtrl& GetReBarCtrl() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a um [CReBarCtrl](../../mfc/reference/crebarctrl-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função de membro para tirar proveito da funcionalidade de controle comum do Windows rebar personalizar seu rebar. Quando você chama `GetReBarCtrl`, ele retorna um objeto de referência para o `CReBarCtrl` para que possa usar qualquer conjunto de funções de membro de objeto.  
  
 Para obter mais informações sobre como usar o `CReBarCtrl` para personalizar seu rebar, consulte [CReBarCtrl usando](../../mfc/using-crebarctrl.md).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CReBarCtrl n º&2;](../../mfc/reference/codesnippet/cpp/crebar-class_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MFCIE](../../visual-cpp-samples.md)   
 [Classe CControlBar](../../mfc/reference/ccontrolbar-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)




