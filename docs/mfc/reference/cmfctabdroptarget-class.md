---
title: Classe CMFCTabDropTarget | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCTabDropTarget
dev_langs:
- C++
helpviewer_keywords:
- CMFCTabDropTarget class
ms.assetid: 9777b7b6-10da-4c4b-b1d1-7ea795b0f1cb
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 31f9950df5974fe1561d601d4e9c26b3e8a96a62
ms.lasthandoff: 02/25/2017

---
# <a name="cmfctabdroptarget-class"></a>Classe CMFCTabDropTarget
Fornece o mecanismo de comunicação entre um controle de guia e as bibliotecas OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCTabDropTarget : public COleDropTarget  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CMFCTabDropTarget::CMFCTabDropTarget`|Construtor padrão.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCTabDropTarget::OnDragEnter](#ondragenter)|Chamado pela estrutura quando o usuário arrasta um objeto em uma janela de guia. (Substitui [COleDropTarget::OnDragEnter](../../mfc/reference/coledroptarget-class.md#ondragenter).)|  
|[CMFCTabDropTarget::OnDragLeave](#ondragleave)|Chamado pela estrutura quando o usuário arrasta um objeto fora da janela de guia que tem o foco. (Substitui [COleDropTarget::OnDragLeave](../../mfc/reference/coledroptarget-class.md#ondragleave).)|  
|[CMFCTabDropTarget::OnDragOver](#ondragover)|Chamado pela estrutura quando o usuário arrasta um objeto para a janela de guia que tem o foco. (Substitui [COleDropTarget::OnDragOver](../../mfc/reference/coledroptarget-class.md#ondragover).)|  
|[CMFCTabDropTarget::OnDropEx](#ondropex)|Chamado pela estrutura quando o usuário libera o botão do mouse no final de uma operação de arrastar. (Substitui [COleDropTarget::OnDropEx](../../mfc/reference/coledroptarget-class.md#ondropex).)|  
|[CMFCTabDropTarget::Register](#register)|Registra o controle como um que pode ser o destino de uma operação de arrastar e soltar OLE.|  
  
### <a name="remarks"></a>Comentários  
 Essa classe fornece suporte a arrastar e soltar para o `CMFCBaseTabCtrl` classe. Se seu aplicativo inicializa as bibliotecas OLE usando o [AfxOleInit](ole-initialization.md#afxoleinit) função `CMFCBaseTabCtrl` objetos se registram para operações de arrastar e soltar.  
  
 O `CMFCTabDropTarget` classe estende sua classe base, tornando a guia que está sob o cursor quando ocorre uma operação de arrastar ativo. Para obter mais informações sobre as operações de arrastar e soltar, consulte [arrastar e soltar (OLE)](../../mfc/drag-and-drop-ole.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar um `CMFCTabDropTarget` e usa seu `Register` método.  
  
 [!code-cpp[NVC_MFC_RibbonApp&#39;](../../mfc/reference/codesnippet/cpp/cmfctabdroptarget-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [COleDropTarget](../../mfc/reference/coledroptarget-class.md)  
  
 [CMFCTabDropTarget](../../mfc/reference/cmfctabdroptarget-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxbasetabctrl.h  
  
##  <a name="a-nameondragentera--cmfctabdroptargetondragenter"></a><a name="ondragenter"></a>CMFCTabDropTarget::OnDragEnter  
 Chamado pela estrutura quando o usuário arrasta um objeto em uma janela de guia.  
  
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
|[in] `pWnd`|Não utilizado.|  
|[in] `pDataObject`|Um ponteiro para o objeto que o usuário arrasta.|  
|[in] `dwKeyState`|Contém o estado das teclas modificadoras. Isso é uma combinação de qualquer número das seguintes opções: `MK_CONTROL`, `MK_SHIFT`, `MK_ALT`, `MK_LBUTTON`, `MK_MBUTTON`, e `MK_RBUTTON`.|  
|[in] `point`|O local do cursor nas coordenadas do cliente.|  
  
### <a name="return-value"></a>Valor de retorno  
 O efeito resultante se a operação de soltar ocorre no local especificado por `point`. Ele pode ser um ou mais destes procedimentos:  
  
- `DROPEFFECT_NONE`  
  
- `DROPEFFECT_COPY`  
  
- `DROPEFFECT_MOVE`  
  
- `DROPEFFECT_LINK`  
  
- `DROPEFFECT_SCROLL`  
  
### <a name="remarks"></a>Comentários  
 Esse método retorna `DROPEFFECT_NONE` se a estrutura da barra de ferramentas não está no modo de personalização ou o formato de dados da área de transferência não está disponível. Caso contrário, retorna o resultado da chamada `CMFCBaseTabCtrl::OnDragEnter` com os parâmetros fornecidos.  
  
 Para obter mais informações sobre o modo de personalização, consulte [CMFCToolBar::IsCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode). Para obter mais informações sobre formatos de dados da área de transferência, consulte [COleDataObject::IsDataAvailable](../../mfc/reference/coledataobject-class.md#isdataavailable).  
  
##  <a name="a-nameondragleavea--cmfctabdroptargetondragleave"></a><a name="ondragleave"></a>CMFCTabDropTarget::OnDragLeave  
 Chamado pela estrutura quando o usuário arrasta um objeto fora da janela de guia que tem o foco.  
  
```  
virtual void OnDragLeave(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `pWnd`|Não utilizado.|  
  
### <a name="remarks"></a>Comentários  
 Esse método chama o `CMFCBaseTabCtrl::OnDragLeave` método para executar a operação de arrastar.  
  
##  <a name="a-nameondragovera--cmfctabdroptargetondragover"></a><a name="ondragover"></a>CMFCTabDropTarget::OnDragOver  
 Chamado pela estrutura quando o usuário arrasta um objeto para a janela de guia que tem o foco.  
  
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
|[in] `pWnd`|Não utilizado.|  
|[in] `pDataObject`|Um ponteiro para o objeto que o usuário arrasta.|  
|[in] `dwKeyState`|Contém o estado das teclas modificadoras. Isso é uma combinação de qualquer número das seguintes opções: `MK_CONTROL`, `MK_SHIFT`, `MK_ALT`, `MK_LBUTTON`, `MK_MBUTTON`, e `MK_RBUTTON`.|  
|[in] `point`|O local do ponteiro do mouse nas coordenadas do cliente.|  
  
### <a name="return-value"></a>Valor de retorno  
 O efeito resultante se a operação de soltar ocorre no local especificado por `point`. Ele pode ser um ou mais destes procedimentos:  
  
- `DROPEFFECT_NONE`  
  
- `DROPEFFECT_COPY`  
  
- `DROPEFFECT_MOVE`  
  
- `DROPEFFECT_LINK`  
  
- `DROPEFFECT_SCROLL`  
  
### <a name="remarks"></a>Comentários  
 Esse método torna a guia que está sob o cursor quando ocorre uma operação de arrastar ativo. Retorna `DROPEFFECT_NONE` se a estrutura da barra de ferramentas não está no modo de personalização ou o formato de dados da área de transferência não está disponível. Caso contrário, retorna o resultado da chamada `CMFCBaseTabCtrl::OnDragOver` com os parâmetros fornecidos.  
  
 Para obter mais informações sobre o modo de personalização, consulte [CMFCToolBar::IsCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode). Para obter mais informações sobre formatos de dados da área de transferência, consulte [COleDataObject::IsDataAvailable](../../mfc/reference/coledataobject-class.md#isdataavailable).  
  
##  <a name="a-nameondropexa--cmfctabdroptargetondropex"></a><a name="ondropex"></a>CMFCTabDropTarget::OnDropEx  
 Chamado pela estrutura quando o usuário libera o botão do mouse no final de uma operação de arrastar.  
  
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
|[in] `pWnd`|Não utilizado.|  
|[in] `pDataObject`|Um ponteiro para o objeto que o usuário arrasta.|  
|[in] `dropEffect`|A operação de descarte padrão.|  
|[in] `dropList`|Não utilizado.|  
|[in] `point`|O local do ponteiro do mouse nas coordenadas do cliente.|  
  
### <a name="return-value"></a>Valor de retorno  
 O efeito de soltar resultante. Ele pode ser um ou mais destes procedimentos:  
  
- `DROPEFFECT_NONE`  
  
- `DROPEFFECT_COPY`  
  
- `DROPEFFECT_MOVE`  
  
- `DROPEFFECT_LINK`  
  
- `DROPEFFECT_SCROLL`  
  
### <a name="remarks"></a>Comentários  
 Esse método chama `CMFCBaseTabCtrl::OnDrop` se a estrutura da barra de ferramentas está no modo de personalização e o formato de dados da área de transferência está disponível. Se a chamada para `CMFCBaseTabCtrl::OnDrop` retorna um valor diferente de zero, esse método retorna o efeito de soltar padrão especificado por `dropEffect`. Do contrário, esse método retorna `DROPEFFECT_NONE`. Para obter mais informações sobre os efeitos de descarte, consulte [COleDropTarget::OnDropEx](../../mfc/reference/coledroptarget-class.md#ondropex).  
  
 Para obter mais informações sobre o modo de personalização, consulte [CMFCToolBar::IsCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode). Para obter mais informações sobre formatos de dados da área de transferência, consulte [COleDataObject::IsDataAvailable](../../mfc/reference/coledataobject-class.md#isdataavailable).  
  
##  <a name="a-nameregistera--cmfctabdroptargetregister"></a><a name="register"></a>CMFCTabDropTarget::Register  
 Registra o controle como um que pode ser o destino de uma operação de arrastar e soltar OLE.  
  
```  
BOOL Register(CMFCBaseTabCtrl *pOwner);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `pOwner`|O controle de guia para registrar como um destino de soltar.|  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o registro foi bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método chama [COleDropTarget::Register](../../mfc/reference/coledroptarget-class.md#register) para registrar o controle para operações de arrastar e soltar.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Arrastar e soltar (OLE)](../../mfc/drag-and-drop-ole.md)




