---
title: Classe CMFCTabDropTarget | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCTabDropTarget
- AFXBASETABCTRL/CMFCTabDropTarget
- AFXBASETABCTRL/CMFCTabDropTarget::OnDragEnter
- AFXBASETABCTRL/CMFCTabDropTarget::OnDragLeave
- AFXBASETABCTRL/CMFCTabDropTarget::OnDragOver
- AFXBASETABCTRL/CMFCTabDropTarget::OnDropEx
- AFXBASETABCTRL/CMFCTabDropTarget::Register
dev_langs:
- C++
helpviewer_keywords:
- CMFCTabDropTarget [MFC], OnDragEnter
- CMFCTabDropTarget [MFC], OnDragLeave
- CMFCTabDropTarget [MFC], OnDragOver
- CMFCTabDropTarget [MFC], OnDropEx
- CMFCTabDropTarget [MFC], Register
ms.assetid: 9777b7b6-10da-4c4b-b1d1-7ea795b0f1cb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 717be77589e31292fe6adbb4920a704794979a57
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45711627"
---
# <a name="cmfctabdroptarget-class"></a>Classe CMFCTabDropTarget
Fornece o mecanismo de comunicação entre um controle guia e as bibliotecas OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCTabDropTarget : public COleDropTarget  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CMFCTabDropTarget::CMFCTabDropTarget`|Construtor padrão.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCTabDropTarget::OnDragEnter](#ondragenter)|Chamado pelo framework quando o usuário arrasta um objeto em uma janela de guia. (Substitui [COleDropTarget::OnDragEnter](../../mfc/reference/coledroptarget-class.md#ondragenter).)|  
|[CMFCTabDropTarget::OnDragLeave](#ondragleave)|Chamado pelo framework quando o usuário arrasta um objeto fora da janela de guia que tem o foco. (Substitui [COleDropTarget::OnDragLeave](../../mfc/reference/coledroptarget-class.md#ondragleave).)|  
|[CMFCTabDropTarget::OnDragOver](#ondragover)|Chamado pelo framework quando o usuário arrasta um objeto para a janela de guia que tem o foco. (Substitui [COleDropTarget::OnDragOver](../../mfc/reference/coledroptarget-class.md#ondragover).)|  
|[CMFCTabDropTarget::OnDropEx](#ondropex)|Chamado pelo framework quando o usuário libera o botão do mouse no final de uma operação de arrastar. (Substitui [COleDropTarget::OnDropEx](../../mfc/reference/coledroptarget-class.md#ondropex).)|  
|[CMFCTabDropTarget::Register](#register)|Registra o controle como um que pode ser o destino de uma operação de arrastar e soltar OLE.|  
  
### <a name="remarks"></a>Comentários  
 Essa classe fornece suporte de arrastar e soltar para o `CMFCBaseTabCtrl` classe. Se seu aplicativo inicializa as bibliotecas OLE usando o [AfxOleInit](ole-initialization.md#afxoleinit) função, `CMFCBaseTabCtrl` objetos se registram para operações de arrastar e soltar.  
  
 O `CMFCTabDropTarget` classe estende sua classe base, tornando a guia que está sob o cursor quando uma operação de arrastar ocorre Active Directory. Para obter mais informações sobre as operações de arrastar e soltar, consulte [arrastar e soltar (OLE)](../../mfc/drag-and-drop-ole.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar uma `CMFCTabDropTarget` do objeto e usar seu `Register` método.  
  
 [!code-cpp[NVC_MFC_RibbonApp#39](../../mfc/reference/codesnippet/cpp/cmfctabdroptarget-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [COleDropTarget](../../mfc/reference/coledroptarget-class.md)  
  
 [CMFCTabDropTarget](../../mfc/reference/cmfctabdroptarget-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxbasetabctrl.h  
  
##  <a name="ondragenter"></a>  CMFCTabDropTarget::OnDragEnter  
 Chamado pelo framework quando o usuário arrasta um objeto em uma janela de guia.  
  
```  
virtual DROPEFFECT OnDragEnter(
    CWnd* pWnd,  
    COleDataObject* pDataObject,  
    DWORD dwKeyState,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|*Apropriei*|[in] Não utilizado.|  
|*pDataObject*|[in] Um ponteiro para o objeto que o usuário arrasta.|  
|*dwKeyState*|[in] Contém o estado das teclas modificadoras. Isso é uma combinação de qualquer número das seguintes opções: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.|  
|*ponto*|[in] O local do cursor em coordenadas do cliente.|  
  
### <a name="return-value"></a>Valor de retorno  
 O efeito dos resultados se a operação de soltar ocorre no local especificado por *aponte*. Ele pode ser um ou mais das seguintes opções:  
  
- DROPEFFECT_NONE  
  
- DROPEFFECT_COPY  
  
- DROPEFFECT_MOVE  
  
- DROPEFFECT_LINK  
  
- DROPEFFECT_SCROLL  
  
### <a name="remarks"></a>Comentários  
 Esse método retorna DROPEFFECT_NONE se a estrutura da barra de ferramentas não está no modo de personalização ou o formato de dados da área de transferência não está disponível. Caso contrário, retornará o resultado da chamada `CMFCBaseTabCtrl::OnDragEnter` com os parâmetros fornecidos.  
  
 Para obter mais informações sobre o modo de personalização, consulte [CMFCToolBar::IsCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode). Para obter mais informações sobre formatos de dados da área de transferência, consulte [COleDataObject::IsDataAvailable](../../mfc/reference/coledataobject-class.md#isdataavailable).  
  
##  <a name="ondragleave"></a>  CMFCTabDropTarget::OnDragLeave  
 Chamado pelo framework quando o usuário arrasta um objeto fora da janela de guia que tem o foco.  
  
```  
virtual void OnDragLeave(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|*Apropriei*|[in] Não utilizado.|  
  
### <a name="remarks"></a>Comentários  
 Este método chama o `CMFCBaseTabCtrl::OnDragLeave` método para executar a operação de arrastar.  
  
##  <a name="ondragover"></a>  CMFCTabDropTarget::OnDragOver  
 Chamado pelo framework quando o usuário arrasta um objeto para a janela de guia que tem o foco.  
  
```  
virtual DROPEFFECT OnDragOver(
    CWnd* pWnd,  
    COleDataObject* pDataObject,  
    DWORD dwKeyState,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|*Apropriei*|[in] Não utilizado.|  
|*pDataObject*|[in] Um ponteiro para o objeto que o usuário arrasta.|  
|*dwKeyState*|[in] Contém o estado das teclas modificadoras. Isso é uma combinação de qualquer número das seguintes opções: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.|  
|*ponto*|[in] O local do ponteiro do mouse nas coordenadas do cliente.|  
  
### <a name="return-value"></a>Valor de retorno  
 O efeito dos resultados se a operação de soltar ocorre no local especificado por *aponte*. Ele pode ser um ou mais das seguintes opções:  
  
- DROPEFFECT_NONE  
  
- DROPEFFECT_COPY  
  
- DROPEFFECT_MOVE  
  
- DROPEFFECT_LINK  
  
- DROPEFFECT_SCROLL  
  
### <a name="remarks"></a>Comentários  
 Esse método torna a guia que está sob o cursor quando uma operação de arrastar ocorre Active Directory. Ele retorna DROPEFFECT_NONE se a estrutura da barra de ferramentas não está no modo de personalização ou o formato de dados da área de transferência não está disponível. Caso contrário, retornará o resultado da chamada `CMFCBaseTabCtrl::OnDragOver` com os parâmetros fornecidos.  
  
 Para obter mais informações sobre o modo de personalização, consulte [CMFCToolBar::IsCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode). Para obter mais informações sobre formatos de dados da área de transferência, consulte [COleDataObject::IsDataAvailable](../../mfc/reference/coledataobject-class.md#isdataavailable).  
  
##  <a name="ondropex"></a>  CMFCTabDropTarget::OnDropEx  
 Chamado pelo framework quando o usuário libera o botão do mouse no final de uma operação de arrastar.  
  
```  
virtual DROPEFFECT OnDropEx(
    CWnd* pWnd,  
    COleDataObject* pDataObject,  
    DROPEFFECT dropEffect,  
    DROPEFFECT dropList,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|*Apropriei*|[in] Não utilizado.|  
|*pDataObject*|[in] Um ponteiro para o objeto que o usuário arrasta.|  
|*dropEffect*|[in] A operação de soltar padrão.|  
|*lista suspensa*|[in] Não utilizado.|  
|*ponto*|[in] O local do ponteiro do mouse nas coordenadas do cliente.|  
  
### <a name="return-value"></a>Valor de retorno  
 O efeito resultante. Ele pode ser um ou mais das seguintes opções:  
  
- DROPEFFECT_NONE  
  
- DROPEFFECT_COPY  
  
- DROPEFFECT_MOVE  
  
- DROPEFFECT_LINK  
  
- DROPEFFECT_SCROLL  
  
### <a name="remarks"></a>Comentários  
 Este método chama `CMFCBaseTabCtrl::OnDrop` se a estrutura da barra de ferramentas está em modo de personalização e o formato da área de transferência de dados estiver disponível. Se a chamada para `CMFCBaseTabCtrl::OnDrop` retorna um valor diferente de zero, esse método retorna o efeito de soltar padrão especificado por *dropEffect*. Caso contrário, esse método retorna DROPEFFECT_NONE. Para obter mais informações sobre os efeitos de soltar, consulte [COleDropTarget::OnDropEx](../../mfc/reference/coledroptarget-class.md#ondropex).  
  
 Para obter mais informações sobre o modo de personalização, consulte [CMFCToolBar::IsCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode). Para obter mais informações sobre formatos de dados da área de transferência, consulte [COleDataObject::IsDataAvailable](../../mfc/reference/coledataobject-class.md#isdataavailable).  
  
##  <a name="register"></a>  CMFCTabDropTarget::Register  
 Registra o controle como um que pode ser o destino de uma operação de arrastar e soltar OLE.  
  
```  
BOOL Register(CMFCBaseTabCtrl *pOwner);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|*pOwner*|[in] O controle de guia para registrar como um destino de soltar.|  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o registro foi bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Este método chama [COleDropTarget::Register](../../mfc/reference/coledroptarget-class.md#register) para registrar o controle para operações de arrastar e soltar.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Arrastar e soltar (OLE)](../../mfc/drag-and-drop-ole.md)



