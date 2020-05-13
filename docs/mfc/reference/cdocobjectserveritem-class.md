---
title: Classe de CDocObjectServerItem
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
ms.openlocfilehash: 1f0f5cf93aab35a17f7174b2beee0d1398564a3d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375533"
---
# <a name="cdocobjectserveritem-class"></a>Classe de CDocObjectServerItem

Implementa verbos de servidor OLE especificamente para servidores DocObject.

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
|[CDocObjectServerItem::OnHide](#onhide)|Abre uma exceção se a estrutura tentar ocultar um item DocObject.|
|[CDocObjectServerItem::OnShow](#onshow)|Chamado pela estrutura para tornar o item DocObject no lugar ativo. Se o item não for um DocObject, chamará [COleServerItem::OnShow](../../mfc/reference/coleserveritem-class.md#onshow).|

## <a name="remarks"></a>Comentários

`CDocObjectServerItem`define funções de membros superridíveis: [OnHide,](#onhide) [OnDoVerb](#ondoverb)e [OnShow](#onshow).

Para `CDocObjectServerItem`usar, certifique-se de que a `COleServerDoc`substituição [onGetEmbeddedItem](../../mfc/reference/coleserverdoc-class.md#ongetembeddeditem) em sua classe derivada retorna um novo `CDocObjectServerItem` objeto. Se você precisar alterar qualquer funcionalidade em seu item, você `CDocObjectServerItem`pode criar uma nova instância de sua própria classe derivada.

Para obter mais informações sobre docObjects, consulte [CDocObjectServer](../../mfc/reference/cdocobjectserver-class.md) e [COleCmdUI](../../mfc/reference/colecmdui-class.md) na *referência MFC*.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[Cdocitem](../../mfc/reference/cdocitem-class.md)

[Coleserveritem](../../mfc/reference/coleserveritem-class.md)

`CDocObjectServerItem`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdocob.h

## <a name="cdocobjectserveritemcdocobjectserveritem"></a><a name="cdocobjectserveritem"></a>CDocObjectServerItem::CDocObjectServerItem

Constrói um objeto `CDocObjectServerItem`.

```
CDocObjectServerItem(COleServerDoc* pServerDoc, BOOL bAutoDelete);
```

### <a name="parameters"></a>Parâmetros

*pServerDoc*<br/>
Um ponteiro para o documento que conterá o novo item DocObject.

*bAutoDelete*<br/>
Indica se o objeto pode ser excluído quando um link é liberado. Defina o argumento `CDocObjectServerItem` como FALSO se o objeto for parte integrante dos dados do seu documento. Defina-o como TRUE se o objeto for uma estrutura secundária usada para identificar um intervalo nos dados do documento que pode ser excluído pela estrutura.

## <a name="cdocobjectserveritemgetdocument"></a><a name="getdocument"></a>CDocObjectServerItem::GetDocument

Recupera um ponteiro para o documento que contém o item.

```
COleServerDoc* GetDocument() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o documento que contém o item; NULO se o item não fizer parte de um documento.

### <a name="remarks"></a>Comentários

Isso permite o acesso ao documento do servidor que você passou como um argumento para o construtor [CDocObjectServerItem.](#cdocobjectserveritem)

## <a name="cdocobjectserveritemondoverb"></a><a name="ondoverb"></a>CDocObjectServerItem::OnDoVerb

Chamado pela estrutura para executar o verbo especificado.

```
virtual void OnDoVerb(LONG iVerb);
```

### <a name="parameters"></a>Parâmetros

*Iverb*<br/>
Especifica o verbo a ser executado. Para obter valores possíveis, consulte [IOleObject::DoVerb](/windows/win32/api/oleidl/nf-oleidl-ioleobject-doverb) no Windows SDK.

### <a name="remarks"></a>Comentários

A implementação padrão chama a função de membro [do OnShow](#onshow) se o item for um DocObject e a OLEIVERB_INPLACEACTIVATE ou OLEIVERB_SHOW for especificada. Se o item não for um DocObject ou um verbo diferente for especificado, a implementação padrão chamará [COleServerItem::OnDoVerb](../../mfc/reference/coleserveritem-class.md#ondoverb).

## <a name="cdocobjectserveritemonhide"></a><a name="onhide"></a>CDocObjectServerItem::OnHide

Chamado pela estrutura para esconder o item.

```
virtual void OnHide();
```

### <a name="remarks"></a>Comentários

A implementação padrão lança uma exceção se o item for um DocObject. Você não pode ocultar um item ativo doCObject porque ele leva toda a exibição. Você deve desativar o item DocObject para fazê-lo desaparecer. Se o item não for um DocObject, a implementação padrão chamará [COleServerItem::OnHide](../../mfc/reference/coleserveritem-class.md#onhide).

## <a name="cdocobjectserveritemonshow"></a><a name="onshow"></a>CDocObjectServerItem::OnShow

Chamado pela estrutura para instruir o aplicativo do servidor para tornar o item DocObject no lugar ativo.

```
virtual void OnShow();
```

### <a name="remarks"></a>Comentários

Se o item não for um DocObject, a implementação padrão chamará [COleServerItem::OnShow](../../mfc/reference/coleserveritem-class.md#onopen). Anular esta função se você quiser executar um processamento especial ao abrir um item DocObject.

## <a name="see-also"></a>Confira também

[Classe COleServerItem](../../mfc/reference/coleserveritem-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDocObjectServer](../../mfc/reference/cdocobjectserver-class.md)<br/>
[Classe COleDocObjectItem](../../mfc/reference/coledocobjectitem-class.md)
