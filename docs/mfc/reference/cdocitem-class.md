---
title: Classe CDocItem
ms.date: 11/04/2016
f1_keywords:
- CDocItem
- AFXOLE/CDocItem
- AFXOLE/CDocItem::GetDocument
- AFXOLE/CDocItem::IsBlank
helpviewer_keywords:
- CDocItem [MFC], GetDocument
- CDocItem [MFC], IsBlank
ms.assetid: 84fb8610-a4c8-4211-adc0-e70e8d002c11
ms.openlocfilehash: cf854bbc99ebeee55ae130b747c77fd7fe52f8d8
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50437085"
---
# <a name="cdocitem-class"></a>Classe CDocItem

A classe base para itens de documento, que são componentes de dados de um documento.

## <a name="syntax"></a>Sintaxe

```
class CDocItem : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDocItem::GetDocument](#getdocument)|Retorna o documento que contém o item.|
|[CDocItem::IsBlank](#isblank)|Determina se o item contém todas as informações.|

## <a name="remarks"></a>Comentários

`CDocItem` objetos são usados para representar itens OLE em documentos de cliente e servidor.

Para obter mais informações, consulte o artigo [contêineres: Implementando um contêiner](../../mfc/containers-implementing-a-container.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

`CDocItem`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

##  <a name="getdocument"></a>  CDocItem::GetDocument

Chame essa função para obter o documento que contém o item.

```
CDocument* GetDocument() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o documento que contém o item; NULO, se o item não for parte de um documento.

### <a name="remarks"></a>Comentários

Essa função é substituída em classes derivadas [COleClientItem](../../mfc/reference/coleclientitem-class.md) e [COleServerItem](../../mfc/reference/coleserveritem-class.md), retornando um ponteiro para qualquer um uma [COleDocument](../../mfc/reference/coledocument-class.md), um [ COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md), ou uma [COleServerDoc](../../mfc/reference/coleserverdoc-class.md) objeto.

##  <a name="isblank"></a>  CDocItem::IsBlank

Chamado pelo framework quando ocorre de serialização padrão.

```
virtual BOOL IsBlank() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o item não contém nenhuma informação; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Por padrão, `CDocItem` objetos não estão em branco. [COleClientItem](../../mfc/reference/coleclientitem-class.md) objetos, às vezes, estão em branco porque eles derivam diretamente de `CDocItem`. No entanto, [COleServerItem](../../mfc/reference/coleserveritem-class.md) os objetos são sempre em branco. Por padrão, os aplicativos OLE que contêm `COleClientItem` objetos que não têm nenhum x ou y extensão são serializados. Isso é feito retornando TRUE da substituição de `IsBlank` quando o item não tem x ou y extensão.

Substitua essa função se você quiser implementar outras ações durante a serialização.

## <a name="see-also"></a>Consulte também

[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDocument](../../mfc/reference/coledocument-class.md)<br/>
[Classe COleServerItem](../../mfc/reference/coleserveritem-class.md)<br/>
[Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)
