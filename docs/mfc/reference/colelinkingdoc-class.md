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
ms.openlocfilehash: f9f184542aaceb206d3eae110d3a088d5fbc95cf
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374946"
---
# <a name="colelinkingdoc-class"></a>Classe COleLinkingDoc

A classe base para documentos de contêiner OLE que suportam a vinculação aos itens incorporados que eles contêm.

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
|[COleLinkingDoc::Registro](#register)|Registra o documento com os DLLs do sistema OLE.|
|[COleLinkingDoc::Revogar](#revoke)|Revoga o registro do documento.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[COleLinkingDoc::OnFindEmbeddedItem](#onfindembeddeditem)|Encontra o item incorporado especificado.|
|[COleLinkingDoc::OnGetLinkedItem](#ongetlinkeditem)|Encontra o item vinculado especificado.|

## <a name="remarks"></a>Comentários

Um aplicativo de contêiner que suporta a vinculação a itens incorporados é chamado de "contêiner de link". O aplicativo de amostra [OCLIENT](../../overview/visual-cpp-samples.md) é um exemplo de um contêiner de link.

Quando a fonte de um item vinculado é um item incorporado em outro documento, esse documento que contém deve ser carregado para que o item incorporado seja editado. Por essa razão, um contêiner de link deve ser capaz de ser lançado por outro aplicativo de contêiner quando o usuário quiser editar a fonte de um item vinculado. Seu aplicativo também deve usar a classe [COleTemplateServer](../../mfc/reference/coletemplateserver-class.md) para que ele possa criar documentos quando lançado de forma programática.

Para tornar o contêiner um contêiner de `COleLinkingDoc` link, obtenha sua classe de documento em vez de [COleDocument](../../mfc/reference/coledocument-class.md). Como em qualquer outro contêiner OLE, você deve projetar sua classe para armazenar os dados nativos do aplicativo, bem como itens incorporados ou vinculados. Além disso, você deve projetar estruturas de dados para armazenar seus dados nativos. Se você `CDocItem`definir uma classe derivada para os dados nativos do `COleDocument` seu aplicativo, você poderá usar a interface definida para armazenar seus dados nativos, bem como seus dados OLE.

Para permitir que seu aplicativo seja lançado de `COleTemplateServer` forma programática por outro `CWinApp`contêiner, declare um objeto como membro da classe derivada do seu aplicativo:

[!code-cpp[NVC_MFCOleContainer#23](../../mfc/codesnippet/cpp/colelinkingdoc-class_1.h)]

Na `InitInstance` função membro `CWinApp`da sua classe derivada, crie `COleLinkingDoc`um modelo de documento e especifique sua classe derivada como a classe de documento:

[!code-cpp[NVC_MFCOleContainer#24](../../mfc/codesnippet/cpp/colelinkingdoc-class_2.cpp)]

Conecte `COleTemplateServer` seu objeto aos modelos de `ConnectTemplate` documento chamando a função de membro do `COleTemplateServer::RegisterAll`objeto e registre todos os objetos de classe com o sistema OLE ligando para:

[!code-cpp[NVC_MFCOleContainer#25](../../mfc/codesnippet/cpp/colelinkingdoc-class_3.cpp)]

Para obter `CWinApp`uma definição e `InitInstance` função de classe derivada da amostra, consulte OCLIENT. H e OCLIENT. CPP na amostra [DeOCLIENT](../../overview/visual-cpp-samples.md)mfc .

Para obter mais `COleLinkingDoc`informações sobre o uso, consulte os artigos [Containers: Implementando um container](../../mfc/containers-implementing-a-container.md) e [contêineres: Recursos avançados](../../mfc/containers-advanced-features.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[Cdocument](../../mfc/reference/cdocument-class.md)

[Coledocument](../../mfc/reference/coledocument-class.md)

`COleLinkingDoc`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

## <a name="colelinkingdoccolelinkingdoc"></a><a name="colelinkingdoc"></a>COleLinkingDoc::COleLinkingDoc

Constrói um `COleLinkingDoc` objeto sem iniciar as comunicações com as DLLs do sistema OLE.

```
COleLinkingDoc();
```

### <a name="remarks"></a>Comentários

Você deve `Register` ligar para a função de membro para informar o OLE que o documento está aberto.

## <a name="colelinkingdoconfindembeddeditem"></a><a name="onfindembeddeditem"></a>COleLinkingDoc::OnFindEmbeddedItem

Chamado pela estrutura para determinar se o documento contém um item OLE incorporado com o nome especificado.

```
virtual COleClientItem* OnFindEmbeddedItem(LPCTSTR lpszItemName);
```

### <a name="parameters"></a>Parâmetros

*lpszItemName*<br/>
Ponteiro para o nome do item OLE incorporado solicitado.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o item especificado; NULO se o item não for encontrado.

### <a name="remarks"></a>Comentários

A implementação padrão pesquisa a lista de itens incorporados para um item com o nome especificado (a comparação de nomes é sensível ao caso). Anular esta função se você tiver seu próprio método de armazenar ou nomear itens OLE incorporados.

## <a name="colelinkingdocongetlinkeditem"></a><a name="ongetlinkeditem"></a>COleLinkingDoc::OnGetLinkedItem

Chamado pela estrutura para verificar se o documento contém um item de servidor vinculado com o nome especificado.

```
virtual COleServerItem* OnGetLinkedItem(LPCTSTR lpszItemName);
```

### <a name="parameters"></a>Parâmetros

*lpszItemName*<br/>
Ponteiro para o nome do item OLE vinculado solicitado.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o item especificado; NULO se o item não for encontrado.

### <a name="remarks"></a>Comentários

A `COleLinkingDoc` implementação padrão sempre retorna NULL. Esta função é anulada na classe `COleServerDoc` derivada para pesquisar a lista de itens do servidor OLE para um item vinculado com o nome especificado (a comparação de nomes é sensível ao caso). Anular essa função se você implementou seu próprio método de armazenar ou recuperar itens de servidor vinculados.

## <a name="colelinkingdocregister"></a><a name="register"></a>COleLinkingDoc::Registro

Informa os DLLs do sistema OLE que o documento está aberto.

```
BOOL Register(
    COleObjectFactory* pFactory,
    LPCTSTR lpszPathName);
```

### <a name="parameters"></a>Parâmetros

*pFactory*<br/>
Ponteiro para um objeto de fábrica OLE (pode ser NULO).

*Lpszpathname*<br/>
Ponteiro para o caminho totalmente qualificado do documento do contêiner.

### <a name="return-value"></a>Valor retornado

Não zero se o documento for registrado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame essa função ao criar ou abrir um arquivo nomeado para registrar o documento com as DLLs do sistema OLE. Não há necessidade de chamar essa função se o documento representar um item incorporado.

Se você `COleTemplateServer` estiver usando `Register` em seu aplicativo, é `OnNewDocument`chamado `OnOpenDocument`para `OnSaveDocument`você pela `COleLinkingDoc`implementação de , e .

## <a name="colelinkingdocrevoke"></a><a name="revoke"></a>COleLinkingDoc::Revogar

Informa os DLLs do sistema OLE que o documento não está mais aberto.

```
void Revoke();
```

### <a name="remarks"></a>Comentários

Chame esta função para revogar o registro do documento com as DLLs do sistema OLE.

Você deve chamar essa função ao fechar um arquivo nomeado, mas geralmente não precisa chamá-la diretamente. `Revoke`é chamado por `COleLinkingDoc`você pela `OnCloseDocument` `OnNewDocument`implementação de , , `OnOpenDocument`e `OnSaveDocument`.

## <a name="see-also"></a>Confira também

[MFC Amostra OCLIENT](../../overview/visual-cpp-samples.md)<br/>
[Classe COleDocument](../../mfc/reference/coledocument-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)
