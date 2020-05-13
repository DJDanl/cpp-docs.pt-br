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
ms.openlocfilehash: 01eb277da029d06ee44d8e048cf3244f4371a9ec
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375001"
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
|[COleDropTarget::OnDragEnter](#ondragenter)|Chamado quando o cursor entra pela primeira vez na janela.|
|[COleDropTarget::OnDragLeave](#ondragleave)|Chamado quando o cursor é arrastado para fora da janela.|
|[COleDropTarget::OnDragOver](#ondragover)|Chamado repetidamente quando o cursor é arrastado pela janela.|
|[COleDropTarget::OnDragScroll](#ondragscroll)|Chamado para determinar se o cursor é arrastado para a região do pergaminho da janela.|
|[COleDropTarget::OnDrop](#ondrop)|Chamado quando os dados são lançados na janela, manipulador padrão.|
|[COleDropTarget::OnDropEx](#ondropex)|Chamado quando os dados são jogados na janela, manipulador inicial.|
|[COleDropTarget::Registro](#register)|Registra a janela como um alvo de queda válido.|
|[COleDropTarget::Revogar](#revoke)|Faz com que a janela deixe de ser um alvo de queda válido.|

## <a name="remarks"></a>Comentários

A criação de um objeto dessa classe permite que uma janela aceite dados através do mecanismo de arrastar e soltar o Le.

Para obter uma janela para aceitar comandos de queda, você deve primeiro criar um objeto da `COleDropTarget` classe e, em seguida, chamar a função [Registrar](#register) com um ponteiro para o objeto desejado `CWnd` como o único parâmetro.

Para obter mais informações sobre operações de arrastar e soltar usando o OLE, consulte o artigo [OLE arrastar e soltar](../../mfc/drag-and-drop-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

`COleDropTarget`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

## <a name="coledroptargetcoledroptarget"></a><a name="coledroptarget"></a>COleDropTarget::COleDropTarget

Constrói um objeto `COleDropTarget`de classe.

```
COleDropTarget();
```

### <a name="remarks"></a>Comentários

Ligue para o [Register](#register) para associar esse objeto a uma janela.

## <a name="coledroptargetondragenter"></a><a name="ondragenter"></a>COleDropTarget::OnDragEnter

Chamado pela estrutura quando o cursor é arrastado pela primeira vez para a janela.

```
virtual DROPEFFECT OnDragEnter(
    CWnd* pWnd,
    COleDataObject* pDataObject,
    DWORD dwKeyState,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Aponta para a janela que o cursor está entrando.

*Pdataobject*<br/>
Aponta para o objeto de dados que contém os dados que podem ser descartados.

*Dwkeystate*<br/>
Contém o estado das chaves modificadoras. Esta é uma combinação de qualquer número do seguinte: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

*Ponto*<br/>
Contém a localização atual do cursor nas coordenadas do cliente.

### <a name="return-value"></a>Valor retornado

O efeito que resultaria se uma queda fosse tentada no local especificado por *ponto*. Pode ser um ou mais dos seguintes:

- DROPEFFECT_NONE uma gota não seria permitida.

- DROPEFFECT_COPY Seria realizada uma operação de cópia.

- DROPEFFECT_MOVE uma operação de mudança seria realizada.

- DROPEFFECT_LINK Seria estabelecido um link dos dados descartados para os dados originais.

- DROPEFFECT_SCROLL Uma operação de rolagem de arrasto está prestes a ocorrer ou está ocorrendo no alvo.

### <a name="remarks"></a>Comentários

Anular esta função para permitir que as operações de queda ocorram na janela. A implementação padrão chama [CView::OnDragEnter](../../mfc/reference/cview-class.md#ondragenter), que simplesmente retorna DROPEFFECT_NONE por padrão.

Para obter mais informações, consulte [IDropTarget::DragEnter](/windows/win32/api/oleidl/nf-oleidl-idroptarget-dragenter) no SDK do Windows.

## <a name="coledroptargetondragleave"></a><a name="ondragleave"></a>COleDropTarget::OnDragLeave

Chamado pela estrutura quando o cursor sai da janela enquanto uma operação de arrasto está em vigor.

```
virtual void OnDragLeave(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Aponta para a janela que o cursor está deixando.

### <a name="remarks"></a>Comentários

Anular esta função se você quiser comportamento especial quando a operação arrastar deixa a janela especificada. A implementação padrão desta função chama [CView::OnDragLeave](../../mfc/reference/cview-class.md#ondragleave).

Para obter mais informações, consulte [IDropTarget::DragLeave](/windows/win32/api/oleidl/nf-oleidl-idroptarget-dragleave) no Windows SDK.

## <a name="coledroptargetondragover"></a><a name="ondragover"></a>COleDropTarget::OnDragOver

Chamado pela estrutura quando o cursor é arrastado pela janela.

```
virtual DROPEFFECT OnDragOver(
    CWnd* pWnd,
    COleDataObject* pDataObject,
    DWORD dwKeyState,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Aponta para a janela que o cursor acabou.

*Pdataobject*<br/>
Aponta para o objeto de dados que contém os dados a serem descartados.

*Dwkeystate*<br/>
Contém o estado das chaves modificadoras. Esta é uma combinação de qualquer número do seguinte: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

*Ponto*<br/>
Contém a localização atual do cursor nas coordenadas do cliente.

### <a name="return-value"></a>Valor retornado

O efeito que resultaria se uma queda fosse tentada no local especificado por *ponto*. Pode ser um ou mais dos seguintes:

- DROPEFFECT_NONE uma gota não seria permitida.

- DROPEFFECT_COPY Seria realizada uma operação de cópia.

- DROPEFFECT_MOVE uma operação de mudança seria realizada.

- DROPEFFECT_LINK Seria estabelecido um link dos dados descartados para os dados originais.

- DROPEFFECT_SCROLL Indica que uma operação de rolagem de arrasto está prestes a ocorrer ou está ocorrendo no alvo.

### <a name="remarks"></a>Comentários

Esta função deve ser substituída para permitir que as operações de queda ocorram na janela. A implementação padrão desta função chama [CView::OnDragOver](../../mfc/reference/cview-class.md#ondragover), que retorna DROPEFFECT_NONE por padrão. Como essa função é chamada com freqüência durante uma operação de arrastar e soltar, ela deve ser otimizada o máximo possível.

Para obter mais informações, consulte [IDropTarget::DragOver](/windows/win32/api/oleidl/nf-oleidl-idroptarget-dragover) no Windows SDK.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#21](../../mfc/codesnippet/cpp/coledroptarget-class_1.cpp)]

## <a name="coledroptargetondragscroll"></a><a name="ondragscroll"></a>COleDropTarget::OnDragScroll

Chamado pela estrutura antes de chamar [OnDragEnter](#ondragenter) ou [OnDragOver](#ondragover) para determinar se o *ponto* está na região de rolagem.

```
virtual DROPEFFECT OnDragScroll(
    CWnd* pWnd,
    DWORD dwKeyState,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Aponta para a janela que o cursor está atualmente sobre.

*Dwkeystate*<br/>
Contém o estado das chaves modificadoras. Esta é uma combinação de qualquer número do seguinte: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

*Ponto*<br/>
Contém a localização do cursor, em pixels, em relação à tela.

### <a name="return-value"></a>Valor retornado

O efeito que resultaria se uma queda fosse tentada no local especificado por *ponto*. Pode ser um ou mais dos seguintes:

- DROPEFFECT_NONE uma gota não seria permitida.

- DROPEFFECT_COPY Seria realizada uma operação de cópia.

- DROPEFFECT_MOVE uma operação de mudança seria realizada.

- DROPEFFECT_LINK Seria estabelecido um link dos dados descartados para os dados originais.

- DROPEFFECT_SCROLL Indica que uma operação de rolagem de arrasto está prestes a ocorrer ou está ocorrendo no alvo.

### <a name="remarks"></a>Comentários

Anular esta função quando você quiser fornecer um comportamento especial para este evento. A implementação padrão desta função chama [CView::OnDragScroll](../../mfc/reference/cview-class.md#ondragscroll), que retorna DROPEFFECT_NONE e rola a janela quando o cursor é arrastado para a região de rolagem padrão dentro da borda da janela.

## <a name="coledroptargetondrop"></a><a name="ondrop"></a>COleDropTarget::OnDrop

Chamado pela estrutura quando uma operação de queda deve ocorrer.

```
virtual BOOL OnDrop(
    CWnd* pWnd,
    COleDataObject* pDataObject,
    DROPEFFECT dropEffect,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Aponta para a janela que o cursor está atualmente sobre.

*Pdataobject*<br/>
Aponta para o objeto de dados que contém os dados a serem descartados.

*Dropeffect*<br/>
O efeito que o usuário escolheu para a operação de queda. Pode ser um ou mais dos seguintes:

- DROPEFFECT_COPY Seria realizada uma operação de cópia.

- DROPEFFECT_MOVE uma operação de mudança seria realizada.

- DROPEFFECT_LINK Seria estabelecido um link dos dados descartados para os dados originais.

*Ponto*<br/>
Contém a localização do cursor, em pixels, em relação à tela.

### <a name="return-value"></a>Valor retornado

Não zero se a queda for bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

A estrutura primeiro chama [o OnDropEx](#ondropex). Se `OnDropEx` a função não lidar com a queda, `OnDrop`a estrutura então chamará essa função de membro, . Normalmente, o aplicativo substitui o [OnDropEx](../../mfc/reference/cview-class.md#ondropex) na classe de exibição para lidar com o arrasto e a queda do botão do mouse direito. Normalmente, a classe de exibição [OnDrop](../../mfc/reference/cview-class.md#ondrop) é usada para lidar com arrastar e soltar simples.

A implementação `COleDropTarget::OnDrop` padrão das chamadas [CView::OnDrop](../../mfc/reference/cview-class.md#ondrop), que simplesmente retorna FALSE por padrão.

Para obter mais informações, consulte [IDropTarget::Drop](/windows/win32/api/oleidl/nf-oleidl-idroptarget-drop) no SDK do Windows.

## <a name="coledroptargetondropex"></a><a name="ondropex"></a>COleDropTarget::OnDropEx

Chamado pela estrutura quando uma operação de queda deve ocorrer.

```
virtual DROPEFFECT OnDropEx(
    CWnd* pWnd,
    COleDataObject* pDataObject,
    DROPEFFECT dropDefault,
    DROPEFFECT dropList,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Aponta para a janela que o cursor está atualmente sobre.

*Pdataobject*<br/>
Aponta para o objeto de dados que contém os dados a serem descartados.

*Dropdefault*<br/>
O efeito que o usuário escolheu para a operação de queda padrão com base no estado-chave atual. Pode ser DROPEFFECT_NONE. Os efeitos de queda são discutidos na seção Observações.

*lista de gotas*<br/>
Uma lista dos efeitos de queda que a fonte de queda suporta. Os valores de efeito de queda podem ser combinados usando a operação bitwise OR** (&#124;). ** Os efeitos de queda são discutidos na seção Observações.

*Ponto*<br/>
Contém a localização do cursor, em pixels, em relação à tela.

### <a name="return-value"></a>Valor retornado

O efeito de queda resultante da tentativa de queda no local especificado por *ponto*. Os efeitos de queda são discutidos na seção Observações.

### <a name="remarks"></a>Comentários

A estrutura primeiro chama essa função. Se ele não lidar com a queda, a estrutura então chama [o OnDrop](#ondrop). Normalmente, você substituirá o [OnDropEx](../../mfc/reference/cview-class.md#ondropex) na classe de exibição para suportar arrastar e soltar o botão do mouse direito. Normalmente, a classe de exibição [OnDrop](../../mfc/reference/cview-class.md#ondrop) é usada para lidar com o caso de suporte para arrastar e soltar simples.

A implementação `COleDropTarget::OnDropEx` padrão das chamadas [CView::OnDropEx](../../mfc/reference/cview-class.md#ondropex). Por padrão, [CView::OnDropEx](../../mfc/reference/cview-class.md#ondropex) simplesmente retorna um valor para indicar que a função de membro [do OnDrop](#ondrop) deve ser chamada.

Os efeitos de gota descrevem a ação associada a uma operação de queda. Veja a lista a seguir de efeitos de queda:

- DROPEFFECT_NONE uma gota não seria permitida.

- DROPEFFECT_COPY Seria realizada uma operação de cópia.

- DROPEFFECT_MOVE uma operação de mudança seria realizada.

- DROPEFFECT_LINK Seria estabelecido um link dos dados descartados para os dados originais.

- DROPEFFECT_SCROLL Indica que uma operação de rolagem de arrasto está prestes a ocorrer ou está ocorrendo no alvo.

Para obter mais informações, consulte [IDropTarget::Drop](/windows/win32/api/oleidl/nf-oleidl-idroptarget-drop) no SDK do Windows.

## <a name="coledroptargetregister"></a><a name="register"></a>COleDropTarget::Registro

Chame esta função para registrar sua janela com os DLLs OLE como um alvo de queda válido.

```
BOOL Register(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*Pwnd*<br/>
Aponta para a janela que deve ser registrada como um alvo de queda.

### <a name="return-value"></a>Valor retornado

Não zero se o registro for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função deve ser solicitada para que as operações de queda sejam aceitas.

Para obter mais informações, consulte [RegisterDragDrop](/windows/win32/api/ole2/nf-ole2-registerdragdrop) no Windows SDK.

## <a name="coledroptargetrevoke"></a><a name="revoke"></a>COleDropTarget::Revogar

Chame esta função antes de destruir qualquer janela que tenha sido registrada como um alvo de queda através de uma chamada para [Registrar](#register) para removê-la da lista de alvos de queda.

```
virtual void Revoke();
```

### <a name="remarks"></a>Comentários

Esta função é chamada automaticamente do manipulador [OnDestroy](../../mfc/reference/cwnd-class.md#ondestroy) para a janela que foi registrada, por isso geralmente não é necessário chamar essa função explicitamente.

Para obter mais informações, consulte [RevokeDragDrop](/windows/win32/api/ole2/nf-ole2-revokedragdrop) no SDK do Windows.

## <a name="see-also"></a>Confira também

[Amostra de MFC HIERSVR](../../overview/visual-cpp-samples.md)<br/>
[MFC Amostra OCLIENT](../../overview/visual-cpp-samples.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDropSource](../../mfc/reference/coledropsource-class.md)
