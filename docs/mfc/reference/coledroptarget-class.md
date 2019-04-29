---
title: Classe COleDropTarget
ms.date: 11/04/2016
f1_keywords:
- COleDropTarget
- AFXOLE/COleDropTarget
- AFXOLE/COleDropTarget::COleDropTarget
- AFXOLE/COleDropTarget::OnDragEnter
- AFXOLE/COleDropTarget::OnDragLeave
- AFXOLE/COleDropTarget::OnDragOver
- AFXOLE/COleDropTarget::OnDragScroll
- AFXOLE/COleDropTarget::OnDrop
- AFXOLE/COleDropTarget::OnDropEx
- AFXOLE/COleDropTarget::Register
- AFXOLE/COleDropTarget::Revoke
helpviewer_keywords:
- COleDropTarget [MFC], COleDropTarget
- COleDropTarget [MFC], OnDragEnter
- COleDropTarget [MFC], OnDragLeave
- COleDropTarget [MFC], OnDragOver
- COleDropTarget [MFC], OnDragScroll
- COleDropTarget [MFC], OnDrop
- COleDropTarget [MFC], OnDropEx
- COleDropTarget [MFC], Register
- COleDropTarget [MFC], Revoke
ms.assetid: a58c9a48-6a93-4357-b078-4594df258311
ms.openlocfilehash: 9a1633ed48c763b986f3421c33589a05f8bba126
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62224779"
---
# <a name="coledroptarget-class"></a>Classe COleDropTarget

Fornece o mecanismo de comunicação entre uma janela e as bibliotecas OLE.

## <a name="syntax"></a>Sintaxe

```
class COleDropTarget : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDropTarget::COleDropTarget](#coledroptarget)|Constrói um objeto `COleDropTarget`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDropTarget::OnDragEnter](#ondragenter)|Chamado quando o cursor entra primeiro na janela.|
|[COleDropTarget::OnDragLeave](#ondragleave)|Chamado quando o cursor é arrastado para fora da janela.|
|[COleDropTarget::OnDragOver](#ondragover)|Chamado repetidamente quando o cursor é arrastado sobre a janela.|
|[COleDropTarget::OnDragScroll](#ondragscroll)|Chamado para determinar se o cursor é arrastado para a região de rolagem da janela.|
|[COleDropTarget::OnDrop](#ondrop)|Chamado quando dados são soltos na janela, o manipulador padrão.|
|[COleDropTarget::OnDropEx](#ondropex)|Chamado quando dados são soltos na janela, o manipulador inicial.|
|[COleDropTarget::Register](#register)|Registra a janela como um destino de soltar válido.|
|[COleDropTarget::Revoke](#revoke)|Faz com que a janela pare sendo um destino de soltar válido.|

## <a name="remarks"></a>Comentários

Criar um objeto dessa classe permite que uma janela aceitar dados por meio do mecanismo de arrastar e soltar OLE.

Para obter uma janela para aceitar comandos drop, você deve primeiro criar um objeto do `COleDropTarget` de classe e, em seguida, chamar o [registre](#register) função com um ponteiro para o estado desejado `CWnd` objeto como o único parâmetro.

Para obter mais informações sobre operações de arrastar e soltar usando OLE, consulte o artigo [arrastar e soltar (OLE)](../../mfc/drag-and-drop-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

`COleDropTarget`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

##  <a name="coledroptarget"></a>  COleDropTarget::COleDropTarget

Constrói um objeto da classe `COleDropTarget`.

```
COleDropTarget();
```

### <a name="remarks"></a>Comentários

Chame [registrar](#register) para associar o objeto uma janela.

##  <a name="ondragenter"></a>  COleDropTarget::OnDragEnter

Chamado pelo framework quando o cursor é arrastado primeiro para a janela.

```
virtual DROPEFFECT OnDragEnter(
    CWnd* pWnd,
    COleDataObject* pDataObject,
    DWORD dwKeyState,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Aponta para a janela que o cursor está entrando.

*pDataObject*<br/>
Aponta para o objeto de dados que contém os dados que podem ser descartados.

*dwKeyState*<br/>
Contém o estado das teclas modificadoras. Isso é uma combinação de qualquer número das seguintes opções: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

*point*<br/>
Contém o local atual do cursor em coordenadas do cliente.

### <a name="return-value"></a>Valor de retorno

O efeito que resultaria caso uma operação de soltar foram tentada no local especificado por *aponte*. Ele pode ser um ou mais das seguintes opções:

- DROPEFFECT_NONE uma operação de soltar não teria permissão.

- DROPEFFECT_COPY seria realizada uma operação de cópia.

- DROPEFFECT_MOVE seria realizada uma operação de movimentação.

- Link de um DROPEFFECT_LINK dos dados soltos para os dados originais seja estabelecido.

- Operação de rolagem de arrastar de um DROPEFFECT_SCROLL está prestes a ocorrer ou está ocorrendo no destino.

### <a name="remarks"></a>Comentários

Substitua essa função para permitir operações de soltar ocorrer na janela. A implementação padrão chama [CView::OnDragEnter](../../mfc/reference/cview-class.md#ondragenter), que simplesmente retorna DROPEFFECT_NONE por padrão.

Para obter mais informações, consulte [IDropTarget::DragEnter](/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragenter) no SDK do Windows.

##  <a name="ondragleave"></a>  COleDropTarget::OnDragLeave

Chamado pelo framework quando o cursor deixa a janela enquanto uma operação de arrastar estiver em vigor.

```
virtual void OnDragLeave(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Aponta para a janela que está deixando o cursor.

### <a name="remarks"></a>Comentários

Substitua essa função se você quiser o comportamento especial quando a operação de arrastar deixa a janela especificada. A implementação padrão dessa função chama [CView::OnDragLeave](../../mfc/reference/cview-class.md#ondragleave).

Para obter mais informações, consulte [IDropTarget::DragLeave](/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragleave) no SDK do Windows.

##  <a name="ondragover"></a>  COleDropTarget::OnDragOver

Chamado pelo framework quando o cursor é arrastado sobre a janela.

```
virtual DROPEFFECT OnDragOver(
    CWnd* pWnd,
    COleDataObject* pDataObject,
    DWORD dwKeyState,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Aponta para a janela que o cursor está sobre.

*pDataObject*<br/>
Aponta para o objeto de dados que contém os dados a ser removido.

*dwKeyState*<br/>
Contém o estado das teclas modificadoras. Isso é uma combinação de qualquer número das seguintes opções: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

*point*<br/>
Contém o local atual do cursor em coordenadas do cliente.

### <a name="return-value"></a>Valor de retorno

O efeito que resultaria caso uma operação de soltar foram tentada no local especificado por *aponte*. Ele pode ser um ou mais das seguintes opções:

- DROPEFFECT_NONE uma operação de soltar não teria permissão.

- DROPEFFECT_COPY seria realizada uma operação de cópia.

- DROPEFFECT_MOVE seria realizada uma operação de movimentação.

- Link de um DROPEFFECT_LINK dos dados soltos para os dados originais seja estabelecido.

- DROPEFFECT_SCROLL indica que uma operação de arrastar rolagem está prestes a ocorrer ou se está ocorrendo no destino.

### <a name="remarks"></a>Comentários

Essa função deve ser substituída para permitir operações de soltar ocorrer na janela. A implementação padrão dessa função chama [CView::OnDragOver](../../mfc/reference/cview-class.md#ondragover), que retorna DROPEFFECT_NONE por padrão. Porque essa função é chamada com frequência durante uma operação de arrastar e soltar, ele deve ser otimizado tanto quanto possível.

Para obter mais informações, consulte [IDropTarget::DragOver](/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragover) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#21](../../mfc/codesnippet/cpp/coledroptarget-class_1.cpp)]

##  <a name="ondragscroll"></a>  COleDropTarget::OnDragScroll

Chamado pelo framework antes de chamar [OnDragEnter](#ondragenter) ou [OnDragOver](#ondragover) para determinar se *aponte* está na região de rolagem.

```
virtual DROPEFFECT OnDragScroll(
    CWnd* pWnd,
    DWORD dwKeyState,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Aponta para a janela que o cursor está atualmente posicionado.

*dwKeyState*<br/>
Contém o estado das teclas modificadoras. Isso é uma combinação de qualquer número das seguintes opções: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

*point*<br/>
Contém o local do cursor, em pixels, em relação à tela.

### <a name="return-value"></a>Valor de retorno

O efeito que resultaria caso uma operação de soltar foram tentada no local especificado por *aponte*. Ele pode ser um ou mais das seguintes opções:

- DROPEFFECT_NONE uma operação de soltar não teria permissão.

- DROPEFFECT_COPY seria realizada uma operação de cópia.

- DROPEFFECT_MOVE seria realizada uma operação de movimentação.

- Link de um DROPEFFECT_LINK dos dados soltos para os dados originais seja estabelecido.

- DROPEFFECT_SCROLL indica que uma operação de arrastar rolagem está prestes a ocorrer ou se está ocorrendo no destino.

### <a name="remarks"></a>Comentários

Substitua essa função quando quiser fornecer um comportamento especial para esse evento. A implementação padrão dessa função chama [CView::OnDragScroll](../../mfc/reference/cview-class.md#ondragscroll), que retorna DROPEFFECT_NONE e rola a janela quando o cursor é arrastado para a região de rolagem padrão dentro da borda da janela.

##  <a name="ondrop"></a>  COleDropTarget::OnDrop

Chamado pelo framework quando uma operação de soltar deve ocorrer.

```
virtual BOOL OnDrop(
    CWnd* pWnd,
    COleDataObject* pDataObject,
    DROPEFFECT dropEffect,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Aponta para a janela que o cursor está atualmente posicionado.

*pDataObject*<br/>
Aponta para o objeto de dados que contém os dados a ser removido.

*dropEffect*<br/>
O efeito que o usuário escolheu para a operação de soltar. Ele pode ser um ou mais das seguintes opções:

- DROPEFFECT_COPY seria realizada uma operação de cópia.

- DROPEFFECT_MOVE seria realizada uma operação de movimentação.

- Link de um DROPEFFECT_LINK dos dados soltos para os dados originais seja estabelecido.

*point*<br/>
Contém o local do cursor, em pixels, em relação à tela.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a operação de soltar for bem-sucedida; Caso contrário, 0.

### <a name="remarks"></a>Comentários

A estrutura do primeiro chama [OnDropEx](#ondropex). Se o `OnDropEx` função não lidar com a operação de soltar, a estrutura, em seguida, chama essa função de membro `OnDrop`. Normalmente, o aplicativo substitui [OnDropEx](../../mfc/reference/cview-class.md#ondropex) na classe de exibição para lidar com o botão direito do mouse, arraste e solte. Normalmente, a classe de exibição [OnDrop](../../mfc/reference/cview-class.md#ondrop) é usado para lidar com a simple arrastar e soltar.

A implementação padrão de `COleDropTarget::OnDrop` chamadas [CView::OnDrop](../../mfc/reference/cview-class.md#ondrop), que simplesmente retorna FALSE por padrão.

Para obter mais informações, consulte [IDropTarget::Drop](/windows/desktop/api/oleidl/nf-oleidl-idroptarget-drop) no SDK do Windows.

##  <a name="ondropex"></a>  COleDropTarget::OnDropEx

Chamado pelo framework quando uma operação de soltar deve ocorrer.

```
virtual DROPEFFECT OnDropEx(
    CWnd* pWnd,
    COleDataObject* pDataObject,
    DROPEFFECT dropDefault,
    DROPEFFECT dropList,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Aponta para a janela que o cursor está atualmente posicionado.

*pDataObject*<br/>
Aponta para o objeto de dados que contém os dados a ser removido.

*dropDefault*<br/>
O efeito que o usuário escolheu para a operação de soltar padrão com base no estado atual da chave. Ele pode ser DROPEFFECT_NONE. Efeitos de soltar são discutidos na seção comentários.

*dropList*<br/>
Uma lista dos efeitos de soltar que ofereça suporte a origem de soltar. Valores de efeito de soltar podem ser combinados usando o OR bit a bit (**&#124;**) operação. Efeitos de soltar são discutidos na seção comentários.

*point*<br/>
Contém o local do cursor, em pixels, em relação à tela.

### <a name="return-value"></a>Valor de retorno

O efeito de soltar que resultaram na tentativa de descarte no local especificado por *aponte*. Efeitos de soltar são discutidos na seção comentários.

### <a name="remarks"></a>Comentários

Primeiro, o framework chama essa função. Se ele não manipular a operação de soltar, a estrutura, em seguida, chama [OnDrop](#ondrop). Normalmente, você substituirá [OnDropEx](../../mfc/reference/cview-class.md#ondropex) na classe de exibição para dar suporte ao botão direito do mouse, arraste e solte. Normalmente, a classe de exibição [OnDrop](../../mfc/reference/cview-class.md#ondrop) é usado para manipular o caso de suporte simple arrastar e soltar.

A implementação padrão de `COleDropTarget::OnDropEx` chamadas [CView::OnDropEx](../../mfc/reference/cview-class.md#ondropex). Por padrão, [CView::OnDropEx](../../mfc/reference/cview-class.md#ondropex) simplesmente retorna um valor fictício para indicar o [OnDrop](#ondrop) função de membro deve ser chamada.

Efeitos de soltar descrevem a ação associada a uma operação de soltar. Consulte a seguinte lista de efeitos de soltar:

- DROPEFFECT_NONE uma operação de soltar não teria permissão.

- DROPEFFECT_COPY seria realizada uma operação de cópia.

- DROPEFFECT_MOVE seria realizada uma operação de movimentação.

- Link de um DROPEFFECT_LINK dos dados soltos para os dados originais seja estabelecido.

- DROPEFFECT_SCROLL indica que uma operação de arrastar rolagem está prestes a ocorrer ou se está ocorrendo no destino.

Para obter mais informações, consulte [IDropTarget::Drop](/windows/desktop/api/oleidl/nf-oleidl-idroptarget-drop) no SDK do Windows.

##  <a name="register"></a>  COleDropTarget::Register

Chame essa função para registrar sua janela com DLLs OLE como um destino de soltar válido.

```
BOOL Register(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Aponta para a janela que deve ser registrado como um destino de soltar.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o registro for bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada para operações de descarte para serem aceitos.

Para obter mais informações, consulte [RegisterDragDrop](/windows/desktop/api/ole2/nf-ole2-registerdragdrop) no SDK do Windows.

##  <a name="revoke"></a>  COleDropTarget::Revoke

Chame essa função antes da destruição de qualquer janela que foi registrada como um destino de soltar por meio de uma chamada para [registrar](#register) para removê-lo da lista de destinos de soltar.

```
virtual void Revoke();
```

### <a name="remarks"></a>Comentários

Essa função é chamada automaticamente a partir de [o OnDestroy](../../mfc/reference/cwnd-class.md#ondestroy) manipulador para a janela que foi registrada, portanto, geralmente não é necessário chamar essa função explicitamente.

Para obter mais informações, consulte [RevokeDragDrop](/windows/desktop/api/ole2/nf-ole2-revokedragdrop) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Exemplo MFC HIERSVR](../../overview/visual-cpp-samples.md)<br/>
[Exemplo MFC OCLIENT](../../overview/visual-cpp-samples.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDropSource](../../mfc/reference/coledropsource-class.md)
