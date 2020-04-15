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
ms.openlocfilehash: 438bc2a03239946dbfca53d5f2989c731b682ab0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375621"
---
# <a name="cdocitem-class"></a>Classe CDocItem

A classe base para itens de documento, que são componentes dos dados de um documento.

## <a name="syntax"></a>Sintaxe

```
class CDocItem : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDocItem::GetDocument](#getdocument)|Retorna o documento que contém o item.|
|[CDocItem::IsBlank](#isblank)|Determina se o item contém alguma informação.|

## <a name="remarks"></a>Comentários

`CDocItem`objetos são usados para representar itens OLE em documentos de cliente e servidor.

Para obter mais informações, consulte o artigo [Containers: Implementando um container](../../mfc/containers-implementing-a-container.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

`CDocItem`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

## <a name="cdocitemgetdocument"></a><a name="getdocument"></a>CDocItem::GetDocument

Ligue para esta função para obter o documento que contém o item.

```
CDocument* GetDocument() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o documento que contém o item; NULL, se o item não faz parte de um documento.

### <a name="remarks"></a>Comentários

Esta função é substituída nas classes derivadas [COleClientItem](../../mfc/reference/coleclientitem-class.md) e [COleServerItem](../../mfc/reference/coleserveritem-class.md), retornando um ponteiro para um [COleDocument,](../../mfc/reference/coledocument-class.md)um [COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md)ou um objeto [COleServerDoc.](../../mfc/reference/coleserverdoc-class.md)

## <a name="cdocitemisblank"></a><a name="isblank"></a>CDocItem::IsBlank

Chamado pelo framework quando ocorre serialização padrão.

```
virtual BOOL IsBlank() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o item não contiver nenhuma informação; caso contrário, 0.

### <a name="remarks"></a>Comentários

Por padrão, `CDocItem` os objetos não estão em branco. [Os objetos COleClientItem](../../mfc/reference/coleclientitem-class.md) às vezes `CDocItem`ficam em branco porque derivam diretamente de . No [entanto, os objetos COleServerItem](../../mfc/reference/coleserveritem-class.md) estão sempre em branco. Por padrão, os aplicativos `COleClientItem` OLE contendo objetos que não têm extensão x ou y são serializados. Isso é feito retornando TRUE de `IsBlank` uma substituição de quando o item não tem extensão x ou y.

Anular essa função se você quiser implementar outras ações durante a serialização.

## <a name="see-also"></a>Confira também

[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDocument](../../mfc/reference/coledocument-class.md)<br/>
[Classe COleServerItem](../../mfc/reference/coleserveritem-class.md)<br/>
[Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)
