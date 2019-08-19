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
ms.openlocfilehash: def0c55ff1faf12729226aa445c9614119c546c4
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69502669"
---
# <a name="cricheditdoc-class"></a>Classe CRichEditDoc

Com [CRichEditView](../../mfc/reference/cricheditview-class.md) e [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md), o fornece a funcionalidade do controle de edição rico dentro do contexto da arquitetura de exibição de documentos do MFC.

## <a name="syntax"></a>Sintaxe

```
class CRichEditDoc : public COleServerDoc
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CRichEditDoc::CreateClientItem](#createclientitem)|Chamado para executar a limpeza do documento.|
|[CRichEditDoc::GetStreamFormat](#getstreamformat)|Indica se a entrada e a saída do fluxo devem incluir informações de formatação.|
|[CRichEditDoc::GetView](#getview)|Recupera o objeto asssociated [CRichEditView](../../mfc/reference/cricheditview-class.md) .|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CRichEditDoc::m_bRTF](#m_brtf)|Indica se a e/s de fluxo deve incluir formatação.|

## <a name="remarks"></a>Comentários

Um "controle de edição rico" é uma janela na qual o usuário pode inserir e editar texto. O texto pode ser atribuído à formatação de caractere e de parágrafo e pode incluir objetos OLE incorporados. Os controles de edição avançados fornecem uma interface de programação para formatar texto. No entanto, um aplicativo deve implementar quaisquer componentes de interface do usuário necessários para disponibilizar as operações de formatação para o usuário.

`CRichEditView`mantém a característica de texto e formatação do texto. `CRichEditDoc`mantém a lista de itens de cliente que estão na exibição. `CRichEditCntrItem`fornece acesso do lado do contêiner aos itens do cliente OLE.

Esse controle comum do Windows (e, portanto, o [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md) e as classes relacionadas) está disponível somente para programas em execução no Windows 95/98 e no Windows NT versões 3,51 e posteriores.

Para obter um exemplo de como usar um documento de edição rico em um aplicativo MFC, consulte o aplicativo de exemplo do [WordPad](../../overview/visual-cpp-samples.md) .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CDocument](../../mfc/reference/cdocument-class.md)

[COleDocument](../../mfc/reference/coledocument-class.md)

[COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md)

[COleServerDoc](../../mfc/reference/coleserverdoc-class.md)

`CRichEditDoc`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrich. h

##  <a name="createclientitem"></a>  CRichEditDoc::CreateClientItem

Chame essa função para criar um `CRichEditCntrItem` objeto e adicioná-lo a este documento.

```
virtual CRichEditCntrItem* CreateClientItem(REOBJECT* preo = NULL) const = 0;
```

### <a name="parameters"></a>Parâmetros

*preo*<br/>
Ponteiro para uma estrutura de [reobjeto](/windows/win32/api/richole/ns-richole-reobject) que descreve um item OLE. O novo `CRichEditCntrItem` objeto é construído com base neste item OLE. Se *preo* for nulo, o novo item de cliente estará vazio.

### <a name="return-value"></a>Valor de retorno

Ponteiro para um novo objeto [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md) que foi adicionado a este documento.

### <a name="remarks"></a>Comentários

Essa função não executa nenhuma inicialização OLE.

Para obter mais informações, consulte a estrutura [de reobjeto](/windows/win32/api/richole/ns-richole-reobject) no SDK do Windows.

##  <a name="getstreamformat"></a>  CRichEditDoc::GetStreamFormat

Chame essa função para determinar o formato de texto para transmitir o conteúdo da edição rica.

```
int GetStreamFormat() const;
```

### <a name="return-value"></a>Valor de retorno

Um dos seguintes sinalizadores:

- SF_TEXT Indica que o controle de edição rico não mantém as informações de formatação.

- SF_RTF indica que o controle de edição rico mantém as informações de formatação.

### <a name="remarks"></a>Comentários

O valor de retorno é baseado no membro de dados [m_bRTF](#m_brtf) . Essa função retornará SF_RTF se `m_bRTF` for true; caso contrário, SF_TEXT.

##  <a name="getview"></a>  CRichEditDoc::GetView

Chame essa função para acessar o objeto [CRichEditView](../../mfc/reference/cricheditview-class.md) associado a este `CRichEditDoc` objeto.

```
virtual CRichEditView* GetView() const;
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para o `CRichEditView` objeto associado ao documento.

### <a name="remarks"></a>Comentários

As informações de texto e formatação estão contidas `CRichEditView` no objeto. O `CRichEditDoc` objeto mantém os itens OLE para serialização. Deve haver apenas um `CRichEditView` para cada. `CRichEditDoc`

##  <a name="m_brtf"></a>  CRichEditDoc::m_bRTF

Quando TRUE, indica que [CRichEditCtrl:: Streame](../../mfc/reference/cricheditctrl-class.md#streamin) e [CRichEditCtrl:: StreamOut](../../mfc/reference/cricheditctrl-class.md#streamout) devem armazenar características de formatação de parágrafo e caractere.

```
BOOL m_bRTF;
```

## <a name="see-also"></a>Consulte também

[Exemplo de WORDPAD do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe COleServerDoc](../../mfc/reference/coleserverdoc-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CRichEditView](../../mfc/reference/cricheditview-class.md)<br/>
[Classe CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md)<br/>
[Classe COleDocument](../../mfc/reference/coledocument-class.md)<br/>
[Classe CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md)
