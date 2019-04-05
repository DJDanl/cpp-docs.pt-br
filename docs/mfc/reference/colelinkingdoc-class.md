---
title: Classe COleLinkingDoc
ms.date: 11/04/2016
f1_keywords:
- COleLinkingDoc
- AFXOLE/COleLinkingDoc
- AFXOLE/COleLinkingDoc::COleLinkingDoc
- AFXOLE/COleLinkingDoc::Register
- AFXOLE/COleLinkingDoc::Revoke
- AFXOLE/COleLinkingDoc::OnFindEmbeddedItem
- AFXOLE/COleLinkingDoc::OnGetLinkedItem
helpviewer_keywords:
- COleLinkingDoc [MFC], COleLinkingDoc
- COleLinkingDoc [MFC], Register
- COleLinkingDoc [MFC], Revoke
- COleLinkingDoc [MFC], OnFindEmbeddedItem
- COleLinkingDoc [MFC], OnGetLinkedItem
ms.assetid: 9f547f35-2f95-427f-b9c0-85c31940198b
ms.openlocfilehash: c5076ceef0c6626fac0232fadf6818edd78b4ccf
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "58773548"
---
# <a name="colelinkingdoc-class"></a>Classe COleLinkingDoc

A classe base para documentos de contêiner OLE que dão suporte à vinculação aos itens inseridos que eles contêm.

## <a name="syntax"></a>Sintaxe

```
class COleLinkingDoc : public COleDocument
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleLinkingDoc::COleLinkingDoc](#colelinkingdoc)|Constrói um objeto `COleLinkingDoc`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleLinkingDoc::Register](#register)|Registra o documento com as DLLs do sistema OLE.|
|[COleLinkingDoc::Revoke](#revoke)|Revoga o registro do documento.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[COleLinkingDoc::OnFindEmbeddedItem](#onfindembeddeditem)|Localiza o item inserido especificado.|
|[COleLinkingDoc::OnGetLinkedItem](#ongetlinkeditem)|Localiza o item vinculado especificado.|

## <a name="remarks"></a>Comentários

Um aplicativo de contêiner que dá suporte à vinculação aos itens inseridos é chamado de "recipiente de link". O [OCLIENT](../../overview/visual-cpp-samples.md) aplicativo de exemplo é um exemplo de um contêiner de link.

Quando a fonte de um item vinculado é um item inserido em outro documento, que a que contém o documento deve ser carregado para que o item inserido a ser editado. Por esse motivo, um contêiner de link deve ser capaz de ser iniciado por outro aplicativo de contêiner quando o usuário desejar editar a fonte de um item vinculado. Seu aplicativo também deve usar o [COleTemplateServer](../../mfc/reference/coletemplateserver-class.md) de classe para que ele possa criar documentos quando iniciado por meio de programação.

Para tornar seu contêiner em um contêiner de link, derive sua classe de documento da `COleLinkingDoc` em vez de [COleDocument](../../mfc/reference/coledocument-class.md). Assim como acontece com qualquer outro contêiner OLE, você deve projetar sua classe para armazenar o aplicativo nativos dados, bem como os itens inseridos ou vinculados. Além disso, você deve criar estruturas de dados para armazenar seus dados nativos. Se você definir um `CDocItem`-classe derivada para seu aplicativo nativo do dados, você pode usar a interface definida por `COleDocument` para armazenar seus dados nativos, bem como seus dados OLE.

Para permitir que seu aplicativo para ser iniciado de forma programática por outro contêiner, declare uma `COleTemplateServer` objeto como um membro do seu aplicativo `CWinApp`-classe derivada:

[!code-cpp[NVC_MFCOleContainer#23](../../mfc/codesnippet/cpp/colelinkingdoc-class_1.h)]

No `InitInstance` função de membro de seu `CWinApp`-derivado da classe, crie um modelo de documento e especifique seu `COleLinkingDoc`-derivado à classe de documento:

[!code-cpp[NVC_MFCOleContainer#24](../../mfc/codesnippet/cpp/colelinkingdoc-class_2.cpp)]

Conectar seu `COleTemplateServer` objeto aos seus modelos de documento ao chamar o objeto `ConnectTemplate` função de membro e registre-se a classe todos os objetos com o sistema OLE chamando `COleTemplateServer::RegisterAll`:

[!code-cpp[NVC_MFCOleContainer#25](../../mfc/codesnippet/cpp/colelinkingdoc-class_3.cpp)]

Para obter um exemplo `CWinApp`-derivado de definição de classe e `InitInstance` , consulte OCLIENT. H e OCLIENT. CPP na amostra MFC [OCLIENT](../../overview/visual-cpp-samples.md).

Para obter mais informações sobre como usar `COleLinkingDoc`, consulte os artigos [contêineres: Implementando um contêiner](../../mfc/containers-implementing-a-container.md) e [contêineres: Recursos avançados de](../../mfc/containers-advanced-features.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CDocument](../../mfc/reference/cdocument-class.md)

[COleDocument](../../mfc/reference/coledocument-class.md)

`COleLinkingDoc`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

##  <a name="colelinkingdoc"></a>  COleLinkingDoc::COleLinkingDoc

Constrói um `COleLinkingDoc` objeto sem iniciar comunicações com as DLLs do sistema OLE.

```
COleLinkingDoc();
```

### <a name="remarks"></a>Comentários

Você deve chamar o `Register` a função de membro para informar ao OLE que o documento é aberto.

##  <a name="onfindembeddeditem"></a>  COleLinkingDoc::OnFindEmbeddedItem

Chamado pelo framework para determinar se o documento contém um item OLE inserido com o nome especificado.

```
virtual COleClientItem* OnFindEmbeddedItem(LPCTSTR lpszItemName);
```

### <a name="parameters"></a>Parâmetros

*lpszItemName*<br/>
Ponteiro para o nome do OLE incorporados item solicitado.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o item especificado; NULL se o item não for encontrado.

### <a name="remarks"></a>Comentários

A implementação padrão de pesquisa a lista de itens inseridos por um item com o nome especificado (a comparação de nome diferencia maiusculas de minúsculas). Substitua essa função se você tiver seu próprio método de armazenar ou itens inseridos OLE de nomenclatura.

##  <a name="ongetlinkeditem"></a>  COleLinkingDoc::OnGetLinkedItem

Chamado pelo framework para verificar se o documento contém um item de servidor vinculado com o nome especificado.

```
virtual COleServerItem* OnGetLinkedItem(LPCTSTR lpszItemName);
```

### <a name="parameters"></a>Parâmetros

*lpszItemName*<br/>
Ponteiro para o nome da OLE vinculado item solicitado.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o item especificado; NULL se o item não for encontrado.

### <a name="remarks"></a>Comentários

O padrão `COleLinkingDoc` implementação sempre retorna NULL. Essa função pode ser substituído na classe derivada `COleServerDoc` para pesquisar a lista de itens de servidor OLE para um item vinculado com o nome especificado (a comparação de nome diferencia maiusculas de minúsculas). Substitua essa função se você tiver implementado seu próprio método de armazenar ou recuperar itens do servidor vinculado.

##  <a name="register"></a>  COleLinkingDoc::Register

Informa as DLLs do sistema OLE que o documento é aberto.

```
BOOL Register(
    COleObjectFactory* pFactory,
    LPCTSTR lpszPathName);
```

### <a name="parameters"></a>Parâmetros

*pFactory*<br/>
Ponteiro para um objeto de fábrica OLE (pode ser nulo).

*lpszPathName*<br/>
Ponteiro para o caminho totalmente qualificado do documento contêiner.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o documento for registrado com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame essa função ao criar ou abrir um arquivo nomeado para registrar o documento com as DLLs do sistema OLE. Não é necessário chamar essa função se o documento representa um item inserido.

Se você estiver usando `COleTemplateServer` em seu aplicativo, `Register` é chamado para você por `COleLinkingDoc`da implementação do `OnNewDocument`, `OnOpenDocument`, e `OnSaveDocument`.

##  <a name="revoke"></a>  COleLinkingDoc::Revoke

Informa as DLLs do sistema OLE que o documento não está aberto.

```
void Revoke();
```

### <a name="remarks"></a>Comentários

Chame essa função para revogar o registro do documento com as DLLs do sistema OLE.

Você deve chamar essa função ao fechar um arquivo nomeado, mas geralmente não é necessário chamá-lo diretamente. `Revoke` é chamado para você por `COleLinkingDoc`da implementação de `OnCloseDocument`, `OnNewDocument`, `OnOpenDocument`, e `OnSaveDocument`.

## <a name="see-also"></a>Consulte também

[Exemplo MFC OCLIENT](../../overview/visual-cpp-samples.md)<br/>
[Classe COleDocument](../../mfc/reference/coledocument-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)
