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
ms.openlocfilehash: 83432fdb90fe28214fb1faaf843556deb2f44750
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367350"
---
# <a name="cmfctabdroptarget-class"></a>Classe CMFCTabDropTarget

Fornece o mecanismo de comunicação entre um controle de guias e as bibliotecas OLE.

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
|[CMFCTabDropTarget::OnDragEnter](#ondragenter)|Chamado pela estrutura quando o usuário arrasta um objeto para uma janela de guia. (Substitui [coleDropTarget::OnDragEnter](../../mfc/reference/coledroptarget-class.md#ondragenter).)|
|[CMFCTabDroptarget::OnDragLeave](#ondragleave)|Chamado pela estrutura quando o usuário arrasta um objeto para fora da janela da guia que tem foco. (Substitui [coleDropTarget::OnDragLeave](../../mfc/reference/coledroptarget-class.md#ondragleave).)|
|[CMFCTabDropTarget::OnDragover](#ondragover)|Chamado pela estrutura quando o usuário arrasta um objeto para a janela da guia que tem foco. (Substitui [coleDropTarget::OnDragOver](../../mfc/reference/coledroptarget-class.md#ondragover).)|
|[CMFCTabDroptarget::OnDropEx](#ondropex)|Chamado pela estrutura quando o usuário libera o botão do mouse no final de uma operação de arrastar. (Substitui [coleDropTarget::OnDropEx](../../mfc/reference/coledroptarget-class.md#ondropex).)|
|[CMFCTabDropTarget::Registro](#register)|Registra o controle como aquele que pode ser alvo de uma operação de arrasto e queda de OLE.|

### <a name="remarks"></a>Comentários

Esta classe fornece suporte de arrastar `CMFCBaseTabCtrl` e soltar para a classe. Se o aplicativo inicializar as bibliotecas OLE usando a função `CMFCBaseTabCtrl` [AfxOleInit,](ole-initialization.md#afxoleinit) os objetos se registrarão para operações de arrastar e soltar.

A `CMFCTabDropTarget` classe estende sua classe base fazendo a guia que está sob o cursor quando uma operação de arrasto ocorre ativa. Para obter mais informações sobre operações de arrastar e soltar, consulte [o OLE arrastar e soltar](../../mfc/drag-and-drop-ole.md).

## <a name="example"></a>Exemplo

O exemplo a seguir `CMFCTabDropTarget` demonstra como `Register` construir um objeto e usar seu método.

[!code-cpp[NVC_MFC_RibbonApp#39](../../mfc/reference/codesnippet/cpp/cmfctabdroptarget-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[Coledroptarget](../../mfc/reference/coledroptarget-class.md)

[CMFCTabDropTarget](../../mfc/reference/cmfctabdroptarget-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxbasetabctrl.h

## <a name="cmfctabdroptargetondragenter"></a><a name="ondragenter"></a>CMFCTabDropTarget::OnDragEnter

Chamado pela estrutura quando o usuário arrasta um objeto para uma janela de guia.

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
|*Pwnd*|[em] Utilizadas.|
|*Pdataobject*|[em] Um ponteiro para o objeto que o usuário arrasta.|
|*Dwkeystate*|[em] Contém o estado das chaves modificadoras. Esta é uma combinação de qualquer número do seguinte: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.|
|*Ponto*|[em] A localização do cursor nas coordenadas dos clientes.|

### <a name="return-value"></a>Valor retornado

O efeito que resulta se a queda ocorrer no local especificado por *ponto*. Pode ser um ou mais dos seguintes:

- Dropeffect_none

- Dropeffect_copy

- Dropeffect_move

- DROPEFFECT_LINK

- Dropeffect_scroll

### <a name="remarks"></a>Comentários

Este método retorna DROPEFFECT_NONE se a estrutura da barra de ferramentas não estiver no modo de personalização ou o formato de dados da Área de Transferência estiver indisponível. Caso contrário, ele retorna `CMFCBaseTabCtrl::OnDragEnter` o resultado da chamada com os parâmetros fornecidos.

Para obter mais informações sobre o modo de personalização, consulte [CMFCToolBar::IsCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode). Para obter mais informações sobre formatos de dados da Área de Transferência, consulte [COleDataObject::IsDataAvailable](../../mfc/reference/coledataobject-class.md#isdataavailable).

## <a name="cmfctabdroptargetondragleave"></a><a name="ondragleave"></a>CMFCTabDroptarget::OnDragLeave

Chamado pela estrutura quando o usuário arrasta um objeto para fora da janela da guia que tem foco.

```
virtual void OnDragLeave(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*Pwnd*|[em] Utilizadas.|

### <a name="remarks"></a>Comentários

Este método `CMFCBaseTabCtrl::OnDragLeave` chama o método para executar a operação de arrasto.

## <a name="cmfctabdroptargetondragover"></a><a name="ondragover"></a>CMFCTabDropTarget::OnDragover

Chamado pela estrutura quando o usuário arrasta um objeto para a janela da guia que tem foco.

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
|*Pwnd*|[em] Utilizadas.|
|*Pdataobject*|[em] Um ponteiro para o objeto que o usuário arrasta.|
|*Dwkeystate*|[em] Contém o estado das chaves modificadoras. Esta é uma combinação de qualquer número do seguinte: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.|
|*Ponto*|[em] A localização do ponteiro do mouse nas coordenadas do cliente.|

### <a name="return-value"></a>Valor retornado

O efeito que resulta se a queda ocorrer no local especificado por *ponto*. Pode ser um ou mais dos seguintes:

- Dropeffect_none

- Dropeffect_copy

- Dropeffect_move

- DROPEFFECT_LINK

- Dropeffect_scroll

### <a name="remarks"></a>Comentários

Este método torna ativa a guia que está sob o cursor quando ocorre uma operação de arrasto. Ele retorna DROPEFFECT_NONE se a estrutura da barra de ferramentas não estiver no modo de personalização ou o formato de dados da Área de Transferência estiver indisponível. Caso contrário, ele retorna `CMFCBaseTabCtrl::OnDragOver` o resultado da chamada com os parâmetros fornecidos.

Para obter mais informações sobre o modo de personalização, consulte [CMFCToolBar::IsCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode). Para obter mais informações sobre formatos de dados da Área de Transferência, consulte [COleDataObject::IsDataAvailable](../../mfc/reference/coledataobject-class.md#isdataavailable).

## <a name="cmfctabdroptargetondropex"></a><a name="ondropex"></a>CMFCTabDroptarget::OnDropEx

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
|*Pwnd*|[em] Utilizadas.|
|*Pdataobject*|[em] Um ponteiro para o objeto que o usuário arrasta.|
|*Dropeffect*|[em] A operação de queda padrão.|
|*lista de gotas*|[em] Utilizadas.|
|*Ponto*|[em] A localização do ponteiro do mouse nas coordenadas do cliente.|

### <a name="return-value"></a>Valor retornado

O efeito de queda resultante. Pode ser um ou mais dos seguintes:

- Dropeffect_none

- Dropeffect_copy

- Dropeffect_move

- DROPEFFECT_LINK

- Dropeffect_scroll

### <a name="remarks"></a>Comentários

Este método `CMFCBaseTabCtrl::OnDrop` chama se a estrutura da barra de ferramentas estiver no modo de personalização e o formato de dados da Área de Transferência estiver disponível. Se a `CMFCBaseTabCtrl::OnDrop` chamada para retornar um valor não zero, este método reameda o efeito de queda padrão especificado pelo *dropEffect*. Caso contrário, este método retorna DROPEFFECT_NONE. Para obter mais informações sobre efeitos de queda, consulte [COleDropTarget::OnDropEx](../../mfc/reference/coledroptarget-class.md#ondropex).

Para obter mais informações sobre o modo de personalização, consulte [CMFCToolBar::IsCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode). Para obter mais informações sobre formatos de dados da Área de Transferência, consulte [COleDataObject::IsDataAvailable](../../mfc/reference/coledataobject-class.md#isdataavailable).

## <a name="cmfctabdroptargetregister"></a><a name="register"></a>CMFCTabDropTarget::Registro

Registra o controle como aquele que pode ser alvo de uma operação de arrasto e queda de OLE.

```
BOOL Register(CMFCBaseTabCtrl *pOwner);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pOwner*|[em] O controle da guia para registrar como um alvo de queda.|

### <a name="return-value"></a>Valor retornado

Não zero se o registro foi bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este método chama [COleDropTarget::Registre-se](../../mfc/reference/coledroptarget-class.md#register) para registrar o controle para operações de arrastar e soltar.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Arrastar e soltar do OLE](../../mfc/drag-and-drop-ole.md)
