---
title: CRichEditCntriItem Class
ms.date: 11/04/2016
f1_keywords:
- CRichEditCntrItem
- AFXRICH/CRichEditCntrItem
- AFXRICH/CRichEditCntrItem::CRichEditCntrItem
- AFXRICH/CRichEditCntrItem::SyncToRichEditObject
helpviewer_keywords:
- CRichEditCntrItem [MFC], CRichEditCntrItem
- CRichEditCntrItem [MFC], SyncToRichEditObject
ms.assetid: 6c0b4efe-0fb8-4621-b5e1-fdcb8ec48c3b
ms.openlocfilehash: b8158105d09d5cfc7c25512567a98121b194a82a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368282"
---
# <a name="cricheditcntritem-class"></a>CRichEditCntriItem Class

Com [CRichEditView](../../mfc/reference/cricheditview-class.md) e [CRichEditDoc,](../../mfc/reference/cricheditdoc-class.md)fornece a funcionalidade do rico controle de edição dentro do contexto da arquitetura de exibição de documentos do MFC.

## <a name="syntax"></a>Sintaxe

```
class CRichEditCntrItem : public COleClientItem
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CRichEditCntrItem::CRichEditCntrItem](#cricheditcntritem)|Constrói um objeto `CRichEditCntrItem`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CRichEditCntrItem::SyncToRichEditObject](#synctoricheditobject)|Ativa o item como outro tipo.|

## <a name="remarks"></a>Comentários

Um "rico controle de edição" é uma janela na qual o usuário pode inserir e editar texto. O texto pode ser atribuído formatação de caracteres e parágrafos, e pode incluir objetos OLE incorporados. Os controles de edição ricos fornecem uma interface de programação para formatação de texto. No entanto, um aplicativo deve implementar quaisquer componentes de interface do usuário necessários para tornar as operações de formatação disponíveis para o usuário.

`CRichEditView`mantém o texto e a formatação característicos do texto. `CRichEditDoc`mantém a lista de itens clientes OLE que estão na exibição. `CRichEditCntrItem`fornece acesso ao lado do contêiner ao item cliente OLE.

Este controle do Windows Common (e, portanto, o [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md) e classes relacionadas) está disponível apenas para programas em execução nas versões Windows 95/98 e Windows NT 3.51 e posteriores.

Para obter um exemplo de uso de itens ricos de contêiner de edição em um aplicativo MFC, consulte o aplicativo de exemplo [WORDPAD.](../../overview/visual-cpp-samples.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[Cdocitem](../../mfc/reference/cdocitem-class.md)

[Coleclientitem](../../mfc/reference/coleclientitem-class.md)

`CRichEditCntrItem`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrich.h

## <a name="cricheditcntritemcricheditcntritem"></a><a name="cricheditcntritem"></a>CRichEditCntrItem::CRichEditCntrItem

Chame esta função `CRichEditCntrItem` para criar um objeto e adicioná-lo ao documento do contêiner.

```
CRichEditCntrItem(
    REOBJECT* preo = NULL,
    CRichEditDoc* pContainer = NULL);
```

### <a name="parameters"></a>Parâmetros

*preo*<br/>
Ponteiro para uma estrutura [REOBJECT](/windows/win32/api/richole/ns-richole-reobject) que descreve um item OLE. O `CRichEditCntrItem` novo objeto é construído em torno deste item OLE. Se *o preo* for NULO, o item do cliente está vazio.

*pContainer*<br/>
Ponteiro para o documento do contêiner que conterá este item. Se *pContainer* for NULL, você deve ligar explicitamente para [COleDocument::AddItem](../../mfc/reference/coledocument-class.md#additem) para adicionar esse item cliente a um documento.

### <a name="remarks"></a>Comentários

Esta função não realiza nenhuma inicialização OLE.

Para obter mais informações, consulte a estrutura [REOBJECT](/windows/win32/api/richole/ns-richole-reobject) no SDK do Windows.

## <a name="cricheditcntritemsynctoricheditobject"></a><a name="synctoricheditobject"></a>CRichEditCntrItem::SyncToRichEditObject

Chame esta função para sincronizar o aspecto `CRichEditCntrltem` do dispositivo, [DVASPECT](/windows/win32/api/wtypes/ne-wtypes-dvaspect), deste para o especificado por *reo*.

```
void SyncToRichEditObject(REOBJECT& reo);
```

### <a name="parameters"></a>Parâmetros

*Reo*<br/>
Referência a uma estrutura [REOBJECT](/windows/win32/api/richole/ns-richole-reobject) que descreve um item OLE.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [DVASPECT](/windows/win32/api/wtypes/ne-wtypes-dvaspect) no Windows SDK.

## <a name="see-also"></a>Confira também

[MFC Sample WORDPAD](../../overview/visual-cpp-samples.md)<br/>
[Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CRichEditDoc](../../mfc/reference/cricheditdoc-class.md)<br/>
[Classe CRichEditView](../../mfc/reference/cricheditview-class.md)
