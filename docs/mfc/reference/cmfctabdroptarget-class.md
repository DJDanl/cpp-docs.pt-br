---
title: Classe CMFCTabDropTarget
ms.date: 11/04/2016
f1_keywords:
- CMFCTabDropTarget
- AFXBASETABCTRL/CMFCTabDropTarget
- AFXBASETABCTRL/CMFCTabDropTarget::OnDragEnter
- AFXBASETABCTRL/CMFCTabDropTarget::OnDragLeave
- AFXBASETABCTRL/CMFCTabDropTarget::OnDragOver
- AFXBASETABCTRL/CMFCTabDropTarget::OnDropEx
- AFXBASETABCTRL/CMFCTabDropTarget::Register
helpviewer_keywords:
- CMFCTabDropTarget [MFC], OnDragEnter
- CMFCTabDropTarget [MFC], OnDragLeave
- CMFCTabDropTarget [MFC], OnDragOver
- CMFCTabDropTarget [MFC], OnDropEx
- CMFCTabDropTarget [MFC], Register
ms.assetid: 9777b7b6-10da-4c4b-b1d1-7ea795b0f1cb
ms.openlocfilehash: 9160cfd847977f98ac22eecd72632822c751a3aa
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88834226"
---
# <a name="cmfctabdroptarget-class"></a>Classe CMFCTabDropTarget

Fornece o mecanismo de comunicação entre um controle de guia e as bibliotecas OLE.

## <a name="syntax"></a>Sintaxe

```
class CMFCTabDropTarget : public COleDropTarget
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|-|-|
|`CMFCTabDropTarget::CMFCTabDropTarget`|Construtor padrão.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|-|-|
|[CMFCTabDropTarget::OnDragEnter](#ondragenter)|Chamado pelo Framework quando o usuário arrasta um objeto para uma janela de guia. (Substitui [COleDropTarget:: OnDragEnter](../../mfc/reference/coledroptarget-class.md#ondragenter).)|
|[CMFCTabDropTarget::OnDragLeave](#ondragleave)|Chamado pelo Framework quando o usuário arrasta um objeto para fora da janela de guia que tem o foco. (Substitui [COleDropTarget:: OnDragLeave](../../mfc/reference/coledroptarget-class.md#ondragleave).)|
|[CMFCTabDropTarget::OnDragOver](#ondragover)|Chamado pelo Framework quando o usuário arrasta um objeto para a janela de guia que tem o foco. (Substitui [COleDropTarget:: OnDragOver](../../mfc/reference/coledroptarget-class.md#ondragover).)|
|[CMFCTabDropTarget::OnDropEx](#ondropex)|Chamado pelo Framework quando o usuário libera o botão do mouse no final de uma operação de arrastar. (Substitui [COleDropTarget:: OnDropEx](../../mfc/reference/coledroptarget-class.md#ondropex).)|
|[CMFCTabDropTarget:: Register](#register)|Registra o controle como um que pode ser o destino de uma operação de arrastar e soltar OLE.|

### <a name="remarks"></a>Comentários

Essa classe fornece suporte a arrastar e soltar para a `CMFCBaseTabCtrl` classe. Se seu aplicativo inicializar as bibliotecas OLE usando a função [AfxOleInit](ole-initialization.md#afxoleinit) , os `CMFCBaseTabCtrl` objetos se registrarão para operações de arrastar e soltar.

A `CMFCTabDropTarget` classe estende sua classe base, tornando-se a guia sob o cursor quando uma operação de arrastar ocorrer ativa. Para obter mais informações sobre operações de arrastar e soltar, consulte [arrastar e soltar OLE](../../mfc/drag-and-drop-ole.md).

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um `CMFCTabDropTarget` objeto e usar seu `Register` método.

[!code-cpp[NVC_MFC_RibbonApp#39](../../mfc/reference/codesnippet/cpp/cmfctabdroptarget-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[COleDropTarget](../../mfc/reference/coledroptarget-class.md)

[CMFCTabDropTarget](../../mfc/reference/cmfctabdroptarget-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxbasetabctrl. h

## <a name="cmfctabdroptargetondragenter"></a><a name="ondragenter"></a> CMFCTabDropTarget::OnDragEnter

Chamado pelo Framework quando o usuário arrasta um objeto para uma janela de guia.

```
virtual DROPEFFECT OnDragEnter(
    CWnd* pWnd,
    COleDataObject* pDataObject,
    DWORD dwKeyState,
    CPoint point);
```

### <a name="parameters"></a>parâmetros

*pWnd*\
no Não utilizado.

*pDataObject*\
no Um ponteiro para o objeto que o usuário arrasta.

*dwKeyState*\
no Contém o estado das teclas modificadoras. Essa é uma combinação de qualquer número dos seguintes: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

*empresas*\
no O local do cursor em coordenadas do cliente.

### <a name="return-value"></a>Valor Retornado

O efeito que resulta se a queda ocorre no local especificado por *ponto*. Pode ser um ou mais dos seguintes:

- DROPEFFECT_NONE

- DROPEFFECT_COPY

- DROPEFFECT_MOVE

- DROPEFFECT_LINK

- DROPEFFECT_SCROLL

### <a name="remarks"></a>Comentários

Esse método retornará DROPEFFECT_NONE se a estrutura da barra de ferramentas não estiver no modo de personalização ou o formato de dados da área de transferência estiver indisponível. Caso contrário, ele retornará o resultado da chamada `CMFCBaseTabCtrl::OnDragEnter` com os parâmetros fornecidos.

Para obter mais informações sobre o modo de personalização, consulte [CMFCToolBar:: Iscustommode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode). Para obter mais informações sobre os formatos de dados da área de transferência, consulte [COleDataObject:: IsDataAvailable](../../mfc/reference/coledataobject-class.md#isdataavailable).

## <a name="cmfctabdroptargetondragleave"></a><a name="ondragleave"></a> CMFCTabDropTarget::OnDragLeave

Chamado pelo Framework quando o usuário arrasta um objeto para fora da janela de guia que tem o foco.

```
virtual void OnDragLeave(CWnd* pWnd);
```

### <a name="parameters"></a>parâmetros

*pWnd*\
no Não utilizado.

### <a name="remarks"></a>Comentários

Esse método chama o `CMFCBaseTabCtrl::OnDragLeave` método para executar a operação de arrastar.

## <a name="cmfctabdroptargetondragover"></a><a name="ondragover"></a> CMFCTabDropTarget::OnDragOver

Chamado pelo Framework quando o usuário arrasta um objeto para a janela de guia que tem o foco.

```
virtual DROPEFFECT OnDragOver(
    CWnd* pWnd,
    COleDataObject* pDataObject,
    DWORD dwKeyState,
    CPoint point);
```

### <a name="parameters"></a>parâmetros

*pWnd*\
no Não utilizado.

*pDataObject*\
no Um ponteiro para o objeto que o usuário arrasta.

*dwKeyState*\
no Contém o estado das teclas modificadoras. Essa é uma combinação de qualquer número dos seguintes: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

*empresas*\
no O local do ponteiro do mouse nas coordenadas do cliente.

### <a name="return-value"></a>Valor Retornado

O efeito que resulta se a queda ocorre no local especificado por *ponto*. Pode ser um ou mais dos seguintes:

- DROPEFFECT_NONE

- DROPEFFECT_COPY

- DROPEFFECT_MOVE

- DROPEFFECT_LINK

- DROPEFFECT_SCROLL

### <a name="remarks"></a>Comentários

Esse método torna a guia sob o cursor quando ocorre uma operação de arrastar ativa. Ele retornará DROPEFFECT_NONE se a estrutura da barra de ferramentas não estiver no modo de personalização ou o formato de dados da área de transferência estiver indisponível. Caso contrário, ele retornará o resultado da chamada `CMFCBaseTabCtrl::OnDragOver` com os parâmetros fornecidos.

Para obter mais informações sobre o modo de personalização, consulte [CMFCToolBar:: Iscustommode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode). Para obter mais informações sobre os formatos de dados da área de transferência, consulte [COleDataObject:: IsDataAvailable](../../mfc/reference/coledataobject-class.md#isdataavailable).

## <a name="cmfctabdroptargetondropex"></a><a name="ondropex"></a> CMFCTabDropTarget::OnDropEx

Chamado pelo Framework quando o usuário libera o botão do mouse no final de uma operação de arrastar.

```
virtual DROPEFFECT OnDropEx(
    CWnd* pWnd,
    COleDataObject* pDataObject,
    DROPEFFECT dropEffect,
    DROPEFFECT dropList,
    CPoint point);
```

### <a name="parameters"></a>parâmetros

*pWnd*\
no Não utilizado.

*pDataObject*\
no Um ponteiro para o objeto que o usuário arrasta.

*dropEffect*\
no A operação de remoção padrão.

*lista suspensa*\
no Não utilizado.

*empresas*\
no O local do ponteiro do mouse nas coordenadas do cliente.

### <a name="return-value"></a>Valor Retornado

O efeito de cancelamento resultante. Pode ser um ou mais dos seguintes:

- DROPEFFECT_NONE

- DROPEFFECT_COPY

- DROPEFFECT_MOVE

- DROPEFFECT_LINK

- DROPEFFECT_SCROLL

### <a name="remarks"></a>Comentários

Esse método chama `CMFCBaseTabCtrl::OnDrop` se a estrutura da barra de ferramentas está no modo de personalização e o formato de dados da área de transferência está disponível. Se a chamada para `CMFCBaseTabCtrl::OnDrop` retornar um valor diferente de zero, esse método retornará o efeito de soltar padrão especificado por *DROPEFFECT*. Caso contrário, esse método retornará DROPEFFECT_NONE. Para obter mais informações sobre drop Effects, consulte [COleDropTarget:: OnDropEx](../../mfc/reference/coledroptarget-class.md#ondropex).

Para obter mais informações sobre o modo de personalização, consulte [CMFCToolBar:: Iscustommode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode). Para obter mais informações sobre os formatos de dados da área de transferência, consulte [COleDataObject:: IsDataAvailable](../../mfc/reference/coledataobject-class.md#isdataavailable).

## <a name="cmfctabdroptargetregister"></a><a name="register"></a> CMFCTabDropTarget:: Register

Registra o controle como um que pode ser o destino de uma operação de arrastar e soltar OLE.

```
BOOL Register(CMFCBaseTabCtrl *pOwner);
```

### <a name="parameters"></a>parâmetros

*pOwner*\
no O controle guia para se registrar como um destino de soltar.

### <a name="return-value"></a>Valor Retornado

Diferente de zero se o registro tiver sido bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método chama [COleDropTarget:: Register](../../mfc/reference/coledroptarget-class.md#register) para registrar o controle para operações de arrastar e soltar.

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Arrastar e soltar do OLE](../../mfc/drag-and-drop-ole.md)
