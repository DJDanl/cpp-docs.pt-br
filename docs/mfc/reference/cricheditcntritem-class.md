---
title: Classe CRichEditCntrItem
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
ms.openlocfilehash: 8e242504c8ab0f59f6dec0602d4a5352a2d84867
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502723"
---
# <a name="cricheditcntritem-class"></a>Classe CRichEditCntrItem

Com [CRichEditView](../../mfc/reference/cricheditview-class.md) e [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md), o fornece a funcionalidade do controle de edição rico dentro do contexto da arquitetura de exibição de documentos do MFC.

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

Um "controle de edição rico" é uma janela na qual o usuário pode inserir e editar texto. O texto pode ser atribuído à formatação de caractere e de parágrafo e pode incluir objetos OLE incorporados. Os controles de edição avançados fornecem uma interface de programação para formatar texto. No entanto, um aplicativo deve implementar quaisquer componentes de interface do usuário necessários para disponibilizar as operações de formatação para o usuário.

`CRichEditView`mantém a característica de texto e formatação do texto. `CRichEditDoc`mantém a lista de itens de cliente OLE que estão na exibição. `CRichEditCntrItem`fornece acesso do lado do contêiner ao item do cliente OLE.

Esse controle comum do Windows (e, portanto, o [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md) e as classes relacionadas) está disponível somente para programas em execução no Windows 95/98 e no Windows NT versões 3,51 e posteriores.

Para obter um exemplo de como usar itens de contêiner de edição avançada em um aplicativo MFC, consulte o aplicativo de exemplo do [WordPad](../../overview/visual-cpp-samples.md) .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CDocItem](../../mfc/reference/cdocitem-class.md)

[COleClientItem](../../mfc/reference/coleclientitem-class.md)

`CRichEditCntrItem`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrich. h

##  <a name="cricheditcntritem"></a>  CRichEditCntrItem::CRichEditCntrItem

Chame essa função para criar um `CRichEditCntrItem` objeto e adicioná-lo ao documento de contêiner.

```
CRichEditCntrItem(
    REOBJECT* preo = NULL,
    CRichEditDoc* pContainer = NULL);
```

### <a name="parameters"></a>Parâmetros

*preo*<br/>
Ponteiro para uma estrutura de [reobjeto](/windows/win32/api/richole/ns-richole-reobject) que descreve um item OLE. O novo `CRichEditCntrItem` objeto é construído com base neste item OLE. Se *preo* for nulo, o item do cliente estará vazio.

*pContainer*<br/>
Ponteiro para o documento de contêiner que conterá este item. Se *pContainer pode* for nulo, você deverá chamar explicitamente [COleDocument::](../../mfc/reference/coledocument-class.md#additem) AddItem para adicionar este item de cliente a um documento.

### <a name="remarks"></a>Comentários

Essa função não executa nenhuma inicialização OLE.

Para obter mais informações, consulte a estrutura de [reobjeto](/windows/win32/api/richole/ns-richole-reobject) no SDK do Windows.

##  <a name="synctoricheditobject"></a>  CRichEditCntrItem::SyncToRichEditObject

Chame essa função para sincronizar o aspecto do dispositivo, [DVASPECT](/windows/win32/api/wtypes/ne-wtypes-dvaspect), `CRichEditCntrltem` disso para o especificado por *REO*.

```
void SyncToRichEditObject(REOBJECT& reo);
```

### <a name="parameters"></a>Parâmetros

*reo*<br/>
Referência a uma estrutura de [reobjeto](/windows/win32/api/richole/ns-richole-reobject) que descreve um item OLE.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [DVASPECT](/windows/win32/api/wtypes/ne-wtypes-dvaspect) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Exemplo de WORDPAD do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CRichEditDoc](../../mfc/reference/cricheditdoc-class.md)<br/>
[Classe CRichEditView](../../mfc/reference/cricheditview-class.md)
