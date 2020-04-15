---
title: Classe CRichEditDoc
ms.date: 11/04/2016
f1_keywords:
- CRichEditDoc
- AFXRICH/CRichEditDoc
- AFXRICH/CRichEditDoc::CreateClientItem
- AFXRICH/CRichEditDoc::GetStreamFormat
- AFXRICH/CRichEditDoc::GetView
- AFXRICH/CRichEditDoc::m_bRTF
helpviewer_keywords:
- CRichEditDoc [MFC], CreateClientItem
- CRichEditDoc [MFC], GetStreamFormat
- CRichEditDoc [MFC], GetView
- CRichEditDoc [MFC], m_bRTF
ms.assetid: c936ec18-d516-49d4-b7fb-c9aa0229eddc
ms.openlocfilehash: 587cf65543e24e586fb8b2336481d6e841473134
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368256"
---
# <a name="cricheditdoc-class"></a>Classe CRichEditDoc

Com [CRichEditView](../../mfc/reference/cricheditview-class.md) e [CRichEditCntrItem,](../../mfc/reference/cricheditcntritem-class.md)fornece a funcionalidade do rico controle de edição dentro do contexto da arquitetura de exibição de documentos do MFC.

## <a name="syntax"></a>Sintaxe

```
class CRichEditDoc : public COleServerDoc
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CRichEditDoc::CreateClientItem](#createclientitem)|Chamado para realizar a limpeza do documento.|
|[CRichEditDoc::GetStreamFormat](#getstreamformat)|Indica se a entrada e a saída do fluxo devem incluir informações de formatação.|
|[CRichEditDoc::GetView](#getview)|Recupera o objeto [CRichEditView](../../mfc/reference/cricheditview-class.md) asssociado.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CRichEditDoc::m_bRTF](#m_brtf)|Indica se a I/O do fluxo deve incluir a formatação.|

## <a name="remarks"></a>Comentários

Um "rico controle de edição" é uma janela na qual o usuário pode inserir e editar texto. O texto pode ser atribuído formatação de caracteres e parágrafos, e pode incluir objetos OLE incorporados. Os controles de edição ricos fornecem uma interface de programação para formatação de texto. No entanto, um aplicativo deve implementar quaisquer componentes de interface do usuário necessários para tornar as operações de formatação disponíveis para o usuário.

`CRichEditView`mantém o texto e a formatação característicos do texto. `CRichEditDoc`mantém a lista de itens do cliente que estão na exibição. `CRichEditCntrItem`fornece acesso ao lado do contêiner aos itens clientes OLE.

Este controle do Windows Common (e, portanto, o [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md) e classes relacionadas) está disponível apenas para programas em execução nas versões Windows 95/98 e Windows NT 3.51 e posteriores.

Para um exemplo de uso de um documento de edição rico em um aplicativo MFC, consulte o aplicativo de exemplo [WORDPAD.](../../overview/visual-cpp-samples.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[Cdocument](../../mfc/reference/cdocument-class.md)

[Coledocument](../../mfc/reference/coledocument-class.md)

[Colelinkingdoc](../../mfc/reference/colelinkingdoc-class.md)

[Coleserverdoc](../../mfc/reference/coleserverdoc-class.md)

`CRichEditDoc`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrich.h

## <a name="cricheditdoccreateclientitem"></a><a name="createclientitem"></a>CRichEditDoc::CreateClientItem

Chame esta função `CRichEditCntrItem` para criar um objeto e adicioná-lo a este documento.

```
virtual CRichEditCntrItem* CreateClientItem(REOBJECT* preo = NULL) const = 0;
```

### <a name="parameters"></a>Parâmetros

*preo*<br/>
Ponteiro para uma estrutura [REOBJECT](/windows/win32/api/richole/ns-richole-reobject) que descreve um item OLE. O `CRichEditCntrItem` novo objeto é construído em torno deste item OLE. Se *o preo* for NULO, o novo item do cliente está vazio.

### <a name="return-value"></a>Valor retornado

Ponteiro para um novo objeto [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md) que foi adicionado a este documento.

### <a name="remarks"></a>Comentários

Esta função não realiza nenhuma inicialização OLE.

Para obter mais informações, consulte a estrutura [REOBJECT](/windows/win32/api/richole/ns-richole-reobject) no SDK do Windows.

## <a name="cricheditdocgetstreamformat"></a><a name="getstreamformat"></a>CRichEditDoc::GetStreamFormat

Chame esta função para determinar o formato de texto para transmitir o conteúdo da edição rica.

```
int GetStreamFormat() const;
```

### <a name="return-value"></a>Valor retornado

Uma das seguintes bandeiras:

- SF_TEXT Indica que o rico controle de edição não mantém informações de formatação.

- SF_RTF Indica que o rico controle de edição mantém a formatação das informações.

### <a name="remarks"></a>Comentários

O valor de retorno é baseado no membro de dados [m_bRTF.](#m_brtf) Esta função retorna `m_bRTF` SF_RTF se for TRUE; caso contrário, SF_TEXT.

## <a name="cricheditdocgetview"></a><a name="getview"></a>CRichEditDoc::GetView

Chame esta função para acessar o objeto `CRichEditDoc` [CRichEditView](../../mfc/reference/cricheditview-class.md) associado a este objeto.

```
virtual CRichEditView* GetView() const;
```

### <a name="return-value"></a>Valor retornado

Ponteiro para `CRichEditView` o objeto associado ao documento.

### <a name="remarks"></a>Comentários

As informações de texto e `CRichEditView` formatação estão contidas no objeto. O `CRichEditDoc` objeto mantém os itens OLE para serialização. Deve haver apenas `CRichEditView` um `CRichEditDoc`para cada.

## <a name="cricheditdocm_brtf"></a><a name="m_brtf"></a>CRichEditDoc::m_bRTF

Quando TRUE, indica que [CRichEditCtrl::StreamIn](../../mfc/reference/cricheditctrl-class.md#streamin) e [CRichEditCtrl::StreamOut](../../mfc/reference/cricheditctrl-class.md#streamout) devem armazenar características de formatação de parágrafo e caracteres.

```
BOOL m_bRTF;
```

## <a name="see-also"></a>Confira também

[MFC Sample WORDPAD](../../overview/visual-cpp-samples.md)<br/>
[Classe COleServerDoc](../../mfc/reference/coleserverdoc-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CRichEditView](../../mfc/reference/cricheditview-class.md)<br/>
[CRichEditCntriItem Class](../../mfc/reference/cricheditcntritem-class.md)<br/>
[Classe COleDocument](../../mfc/reference/coledocument-class.md)<br/>
[Classe CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md)
