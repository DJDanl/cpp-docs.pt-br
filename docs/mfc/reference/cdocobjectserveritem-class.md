---
title: Classe CDocObjectServerItem
ms.date: 03/27/2019
f1_keywords:
- CDocObjectServerItem
- AFXDOCOB/CDocObjectServerItem
- AFXDOCOB/CDocObjectServerItem::CDocObjectServerItem
- AFXDOCOB/CDocObjectServerItem::GetDocument
- AFXDOCOB/CDocObjectServerItem::OnDoVerb
- AFXDOCOB/CDocObjectServerItem::OnHide
- AFXDOCOB/CDocObjectServerItem::OnShow
helpviewer_keywords:
- CDocObjectServerItem [MFC], CDocObjectServerItem
- CDocObjectServerItem [MFC], GetDocument
- CDocObjectServerItem [MFC], OnDoVerb
- CDocObjectServerItem [MFC], OnHide
- CDocObjectServerItem [MFC], OnShow
ms.assetid: 530f7156-50c8-4806-9328-602c9133f622
ms.openlocfilehash: 4d44791415626f1a94500b9c3885581d67e8fe42
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69506816"
---
# <a name="cdocobjectserveritem-class"></a>Classe CDocObjectServerItem

Implementa verbos do servidor OLE especificamente para servidores DocObject.

## <a name="syntax"></a>Sintaxe

```
class CDocObjectServerItem : public COleServerItem
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CDocObjectServerItem::CDocObjectServerItem](#cdocobjectserveritem)|Constrói um objeto `CDocObjectServerItem`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDocObjectServerItem::GetDocument](#getdocument)|Recupera um ponteiro para o documento que contém o item.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CDocObjectServerItem::OnDoVerb](#ondoverb)|Chamado para executar um verbo.|
|[CDocObjectServerItem::OnHide](#onhide)|Gera uma exceção se a estrutura tenta ocultar um item DocObject.|
|[CDocObjectServerItem::OnShow](#onshow)|Chamado pelo Framework para tornar o item DocObject ativo no local. Se o item não for um DocObject, chama [COleServerItem:: OnShow](../../mfc/reference/coleserveritem-class.md#onshow).|

## <a name="remarks"></a>Comentários

`CDocObjectServerItem`define funções de membro substituíveis: [OnHide](#onhide), [OnDoVerb](#ondoverb)e [OnShow](#onshow).

Para usar `CDocObjectServerItem`, certifique-se de que a substituição [OnGetEmbeddedItem](../../mfc/reference/coleserverdoc-class.md#ongetembeddeditem) na sua `COleServerDoc`classe derivada retorna um novo objeto `CDocObjectServerItem`. Se você precisar alterar qualquer funcionalidade em seu item, poderá criar uma nova instância de sua própria `CDocObjectServerItem`classe derivada.

Para obter mais informações sobre DocObjects, consulte [CDocObjectServer](../../mfc/reference/cdocobjectserver-class.md) e [COleCmdUI](../../mfc/reference/colecmdui-class.md) na *referência do MFC*.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CDocItem](../../mfc/reference/cdocitem-class.md)

[COleServerItem](../../mfc/reference/coleserveritem-class.md)

`CDocObjectServerItem`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AfxDocOb. h

##  <a name="cdocobjectserveritem"></a>  CDocObjectServerItem::CDocObjectServerItem

Constrói um objeto `CDocObjectServerItem`.

```
CDocObjectServerItem(COleServerDoc* pServerDoc, BOOL bAutoDelete);
```

### <a name="parameters"></a>Parâmetros

*pServerDoc*<br/>
Um ponteiro para o documento que conterá o novo item DocObject.

*bAutoDelete*<br/>
Indica se o objeto pode ser excluído quando um link para ele é liberado. Defina o argumento como false se o `CDocObjectServerItem` objeto for uma parte integral dos dados do documento. Defina-a como TRUE se o objeto for uma estrutura secundária usada para identificar um intervalo nos dados do documento que podem ser excluídos pela estrutura.

##  <a name="getdocument"></a>  CDocObjectServerItem::GetDocument

Recupera um ponteiro para o documento que contém o item.

```
COleServerDoc* GetDocument() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o documento que contém o item; NULL se o item não fizer parte de um documento.

### <a name="remarks"></a>Comentários

Isso permite o acesso ao documento do servidor que você passou como um argumento para o construtor [CDocObjectServerItem](#cdocobjectserveritem) .

##  <a name="ondoverb"></a>  CDocObjectServerItem::OnDoVerb

Chamado pelo Framework para executar o verbo especificado.

```
virtual void OnDoVerb(LONG iVerb);
```

### <a name="parameters"></a>Parâmetros

*iVerb*<br/>
Especifica o verbo a ser executado. Para obter os valores possíveis, consulte [IOleObject::D overb](/windows/win32/api/oleidl/nf-oleidl-ioleobject-doverb) no SDK do Windows.

### <a name="remarks"></a>Comentários

A implementação padrão chama a função de membro [OnShow](#onshow) se o item for um DOCOBJECT e OLEIVERB_INPLACEACTIVATE ou OLEIVERB_SHOW for especificado. Se o item não for um DocObject ou um verbo diferente for especificado, a implementação padrão chamará [COleServerItem:: OnDoVerb](../../mfc/reference/coleserveritem-class.md#ondoverb).

##  <a name="onhide"></a>  CDocObjectServerItem::OnHide

Chamado pelo Framework para ocultar o item.

```
virtual void OnHide();
```

### <a name="remarks"></a>Comentários

A implementação padrão gera uma exceção se o item for um DocObject. Não é possível ocultar um item DocObject ativo porque ele usa a exibição inteira. Você deve desativar o item DocObject para que ele desapareça. Se o item não for um DocObject, a implementação padrão chamará [COleServerItem:: OnHide](../../mfc/reference/coleserveritem-class.md#onhide).

##  <a name="onshow"></a>  CDocObjectServerItem::OnShow

Chamado pelo Framework para instruir o aplicativo de servidor a tornar o item DocObject ativo no local.

```
virtual void OnShow();
```

### <a name="remarks"></a>Comentários

Se o item não for um DocObject, a implementação padrão chamará [COleServerItem:: OnShow](../../mfc/reference/coleserveritem-class.md#onopen). Substitua essa função se você quiser executar um processamento especial ao abrir um item DocObject.

## <a name="see-also"></a>Consulte também

[Classe COleServerItem](../../mfc/reference/coleserveritem-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDocObjectServer](../../mfc/reference/cdocobjectserver-class.md)<br/>
[Classe COleDocObjectItem](../../mfc/reference/coledocobjectitem-class.md)
