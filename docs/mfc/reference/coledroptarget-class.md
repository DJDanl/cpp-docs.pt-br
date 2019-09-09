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
ms.openlocfilehash: 891b19112c8baf2efb088f064892e1ea19a7deab
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69503971"
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
|[COleDropTarget::OnDragOver](#ondragover)|Chamado repetidamente quando o cursor é arrastado sobre a janela.|
|[COleDropTarget::OnDragScroll](#ondragscroll)|Chamado para determinar se o cursor é arrastado para a região de rolagem da janela.|
|[COleDropTarget::OnDrop](#ondrop)|Chamado quando os dados são retirados para a janela, manipulador padrão.|
|[COleDropTarget::OnDropEx](#ondropex)|Chamado quando os dados são retirados para a janela, manipulador inicial.|
|[COleDropTarget::Register](#register)|Registra a janela como um destino de soltura válido.|
|[COleDropTarget::Revoke](#revoke)|Faz com que a janela pare de ser um destino de soltura válido.|

## <a name="remarks"></a>Comentários

A criação de um objeto dessa classe permite que uma janela aceite dados por meio do mecanismo de arrastar e soltar OLE.

Para obter uma janela para aceitar comandos drop, primeiro você deve criar um objeto da `COleDropTarget` classe e, em seguida, chamar a função [Register](#register) com um ponteiro para o `CWnd` objeto desejado como o único parâmetro.

Para obter mais informações sobre operações de arrastar e soltar usando OLE, consulte o artigo [arrastar e soltar (OLE)](../../mfc/drag-and-drop-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

`COleDropTarget`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxole. h

##  <a name="coledroptarget"></a>  COleDropTarget::COleDropTarget

Constrói um objeto da classe `COleDropTarget`.

```
COleDropTarget();
```

### <a name="remarks"></a>Comentários

Chame [o registro](#register) para associar esse objeto a uma janela.

##  <a name="ondragenter"></a>  COleDropTarget::OnDragEnter

Chamado pelo Framework quando o cursor é arrastado pela primeira vez para a janela.

```
virtual DROPEFFECT OnDragEnter(
    CWnd* pWnd,
    COleDataObject* pDataObject,
    DWORD dwKeyState,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Aponta para a janela que o cursor está inserindo.

*pDataObject*<br/>
Aponta para o objeto de dados que contém os dados que podem ser descartados.

*dwKeyState*<br/>
Contém o estado das teclas modificadoras. Essa é uma combinação de qualquer número do seguinte: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

*point*<br/>
Contém o local atual do cursor nas coordenadas do cliente.

### <a name="return-value"></a>Valor de retorno

O efeito que resultaria se houvesse uma tentativa de soltar no local especificado por *ponto*. Pode ser um ou mais dos seguintes:

- DROPEFFECT_NONE uma queda não seria permitida.

- DROPEFFECT_COPY uma operação de cópia seria executada.

- DROPEFFECT_MOVE uma operação de movimentação seria executada.

- DROPEFFECT_LINK um link dos dados descartados para os dados originais seria estabelecido.

- DROPEFFECT_SCROLL uma operação de rolagem de arrastar está prestes a ocorrer ou está ocorrendo no destino.

### <a name="remarks"></a>Comentários

Substitua essa função para permitir que as operações drop ocorram na janela. A implementação padrão chama [cvisualização:: OnDragEnter](../../mfc/reference/cview-class.md#ondragenter), que simplesmente retorna DROPEFFECT_NONE por padrão.

Para obter mais informações, consulte [IDropTarget::D ragenter](/windows/win32/api/oleidl/nf-oleidl-idroptarget-dragenter) no SDK do Windows.

##  <a name="ondragleave"></a>  COleDropTarget::OnDragLeave

Chamado pelo Framework quando o cursor sai da janela enquanto uma operação de arrastar está em vigor.

```
virtual void OnDragLeave(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Aponta para a janela que o cursor está saindo.

### <a name="remarks"></a>Comentários

Substitua essa função se desejar um comportamento especial quando a operação de arrastar sair da janela especificada. A implementação padrão dessa função chama [cvisualização:: OnDragLeave](../../mfc/reference/cview-class.md#ondragleave).

Para obter mais informações, consulte [IDropTarget::D ragleave](/windows/win32/api/oleidl/nf-oleidl-idroptarget-dragleave) no SDK do Windows.

##  <a name="ondragover"></a>  COleDropTarget::OnDragOver

Chamado pelo Framework quando o cursor é arrastado sobre a janela.

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
Aponta para o objeto de dados que contém os dados a serem removidos.

*dwKeyState*<br/>
Contém o estado das teclas modificadoras. Essa é uma combinação de qualquer número do seguinte: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

*point*<br/>
Contém o local atual do cursor nas coordenadas do cliente.

### <a name="return-value"></a>Valor de retorno

O efeito que resultaria se houvesse uma tentativa de soltar no local especificado por *ponto*. Pode ser um ou mais dos seguintes:

- DROPEFFECT_NONE uma queda não seria permitida.

- DROPEFFECT_COPY uma operação de cópia seria executada.

- DROPEFFECT_MOVE uma operação de movimentação seria executada.

- DROPEFFECT_LINK um link dos dados descartados para os dados originais seria estabelecido.

- DROPEFFECT_SCROLL Indica que uma operação de rolagem de arrastar está prestes a ocorrer ou está ocorrendo no destino.

### <a name="remarks"></a>Comentários

Essa função deve ser substituída para permitir que operações drop ocorram na janela. A implementação padrão dessa função chama [cvisualização:: OnDragOver](../../mfc/reference/cview-class.md#ondragover), que retorna DROPEFFECT_NONE por padrão. Como essa função é chamada com frequência durante uma operação de arrastar e soltar, ela deve ser otimizada tanto quanto possível.

Para obter mais informações, consulte [IDropTarget::D ragover](/windows/win32/api/oleidl/nf-oleidl-idroptarget-dragover) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#21](../../mfc/codesnippet/cpp/coledroptarget-class_1.cpp)]

##  <a name="ondragscroll"></a>  COleDropTarget::OnDragScroll

Chamado pelo Framework antes de chamar [OnDragEnter](#ondragenter) ou [OnDragOver](#ondragover) para determinar se o *ponto* está na região de rolagem.

```
virtual DROPEFFECT OnDragScroll(
    CWnd* pWnd,
    DWORD dwKeyState,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Aponta para a janela em que o cursor está no momento.

*dwKeyState*<br/>
Contém o estado das teclas modificadoras. Essa é uma combinação de qualquer número do seguinte: MK_CONTROL, MK_SHIFT, MK_ALT, MK_LBUTTON, MK_MBUTTON e MK_RBUTTON.

*point*<br/>
Contém o local do cursor, em pixels, em relação à tela.

### <a name="return-value"></a>Valor de retorno

O efeito que resultaria se houvesse uma tentativa de soltar no local especificado por *ponto*. Pode ser um ou mais dos seguintes:

- DROPEFFECT_NONE uma queda não seria permitida.

- DROPEFFECT_COPY uma operação de cópia seria executada.

- DROPEFFECT_MOVE uma operação de movimentação seria executada.

- DROPEFFECT_LINK um link dos dados descartados para os dados originais seria estabelecido.

- DROPEFFECT_SCROLL Indica que uma operação de rolagem de arrastar está prestes a ocorrer ou está ocorrendo no destino.

### <a name="remarks"></a>Comentários

Substitua essa função quando desejar fornecer um comportamento especial para esse evento. A implementação padrão dessa função chama [cvisualização:: OnDragScroll](../../mfc/reference/cview-class.md#ondragscroll), que retorna DROPEFFECT_NONE e rola a janela quando o cursor é arrastado para a região de rolagem padrão dentro da borda da janela.

##  <a name="ondrop"></a>  COleDropTarget::OnDrop

Chamado pelo Framework quando uma operação de soltar é executada.

```
virtual BOOL OnDrop(
    CWnd* pWnd,
    COleDataObject* pDataObject,
    DROPEFFECT dropEffect,
    CPoint point);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Aponta para a janela em que o cursor está no momento.

*pDataObject*<br/>
Aponta para o objeto de dados que contém os dados a serem removidos.

*dropEffect*<br/>
O efeito que o usuário escolheu para a operação de soltar. Pode ser um ou mais dos seguintes:

- DROPEFFECT_COPY uma operação de cópia seria executada.

- DROPEFFECT_MOVE uma operação de movimentação seria executada.

- DROPEFFECT_LINK um link dos dados descartados para os dados originais seria estabelecido.

*point*<br/>
Contém o local do cursor, em pixels, em relação à tela.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a remoção for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

A estrutura primeiro chama [OnDropEx](#ondropex). Se a `OnDropEx` função não tratar a queda, a estrutura chamará essa função de membro, `OnDrop`. Normalmente, o aplicativo substitui [OnDropEx](../../mfc/reference/cview-class.md#ondropex) na classe View para manipular o arrastar e soltar com o botão do mouse. Normalmente, a classe View [OnDrop](../../mfc/reference/cview-class.md#ondrop) é usada para manipular arrastar e soltar simples.

A implementação padrão de `COleDropTarget::OnDrop` chama [cvisualização:: OnDrop](../../mfc/reference/cview-class.md#ondrop), que simplesmente retorna false por padrão.

Para obter mais informações, consulte [IDropTarget::D ROP](/windows/win32/api/oleidl/nf-oleidl-idroptarget-drop) no SDK do Windows.

##  <a name="ondropex"></a>  COleDropTarget::OnDropEx

Chamado pelo Framework quando uma operação de soltar é executada.

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
Aponta para a janela em que o cursor está no momento.

*pDataObject*<br/>
Aponta para o objeto de dados que contém os dados a serem removidos.

*dropDefault*<br/>
O efeito que o usuário escolheu para a operação de soltar padrão com base no estado de chave atual. Pode ser DROPEFFECT_NONE. Os efeitos de soltar são discutidos na seção comentários.

*dropList*<br/>
Uma lista dos efeitos de soltar aos quais a fonte de soltar dá suporte. Os valores de queda de efeito podem ser combinados usando a **&#124;** operação OR () de OR bit. Os efeitos de soltar são discutidos na seção comentários.

*point*<br/>
Contém o local do cursor, em pixels, em relação à tela.

### <a name="return-value"></a>Valor de retorno

O efeito de soltar que resultou da tentativa de soltar no local especificado por *ponto*. Os efeitos de soltar são discutidos na seção comentários.

### <a name="remarks"></a>Comentários

A estrutura chama primeiro essa função. Se não tratar a queda, a estrutura Então chamará [OnDrop](#ondrop). Normalmente, você substituirá [OnDropEx](../../mfc/reference/cview-class.md#ondropex) na classe de exibição para dar suporte ao arrastar e soltar com o botão direito do mouse. Normalmente, a classe View [OnDrop](../../mfc/reference/cview-class.md#ondrop) é usada para lidar com o caso de suporte para arrastar e soltar simples.

A implementação padrão de `COleDropTarget::OnDropEx` chama [cvisualização:: OnDropEx](../../mfc/reference/cview-class.md#ondropex). Por padrão, [cvisualização:: OnDropEx](../../mfc/reference/cview-class.md#ondropex) simplesmente retorna um valor fictício para indicar que a função de membro [OnDrop](#ondrop) deve ser chamada.

Drop Effects descreve a ação associada a uma operação DROP. Consulte a seguinte lista de efeitos suspensos:

- DROPEFFECT_NONE uma queda não seria permitida.

- DROPEFFECT_COPY uma operação de cópia seria executada.

- DROPEFFECT_MOVE uma operação de movimentação seria executada.

- DROPEFFECT_LINK um link dos dados descartados para os dados originais seria estabelecido.

- DROPEFFECT_SCROLL Indica que uma operação de rolagem de arrastar está prestes a ocorrer ou está ocorrendo no destino.

Para obter mais informações, consulte [IDropTarget::D ROP](/windows/win32/api/oleidl/nf-oleidl-idroptarget-drop) no SDK do Windows.

##  <a name="register"></a>  COleDropTarget::Register

Chame essa função para registrar sua janela com as DLLs OLE como um destino de soltura válido.

```
BOOL Register(CWnd* pWnd);
```

### <a name="parameters"></a>Parâmetros

*pWnd*<br/>
Aponta para a janela que deve ser registrada como um destino de soltar.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o registro for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada para operações de remoção para serem aceitas.

Para obter mais informações, consulte [RegisterDragDrop](/windows/win32/api/ole2/nf-ole2-registerdragdrop) no SDK do Windows.

##  <a name="revoke"></a>  COleDropTarget::Revoke

Chame essa função antes de destruir qualquer janela que tenha sido registrada como uma interface "soltar" por meio de uma chamada de [registro](#register) para removê-la da lista de destinos de destino.

```
virtual void Revoke();
```

### <a name="remarks"></a>Comentários

Essa função é chamada automaticamente do manipulador [OnDestroy](../../mfc/reference/cwnd-class.md#ondestroy) para a janela que foi registrada, portanto, normalmente não é necessário chamar essa função explicitamente.

Para obter mais informações, consulte [RevokeDragDrop](/windows/win32/api/ole2/nf-ole2-revokedragdrop) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Exemplo de HIERSVR do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de OCLIENT do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDropSource](../../mfc/reference/coledropsource-class.md)
