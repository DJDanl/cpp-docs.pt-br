---
title: Classe COleServerDoc
ms.date: 11/04/2016
f1_keywords:
- COleServerDoc
- AFXOLE/COleServerDoc
- AFXOLE/COleServerDoc::COleServerDoc
- AFXOLE/COleServerDoc::ActivateDocObject
- AFXOLE/COleServerDoc::ActivateInPlace
- AFXOLE/COleServerDoc::DeactivateAndUndo
- AFXOLE/COleServerDoc::DiscardUndoState
- AFXOLE/COleServerDoc::GetClientSite
- AFXOLE/COleServerDoc::GetEmbeddedItem
- AFXOLE/COleServerDoc::GetItemClipRect
- AFXOLE/COleServerDoc::GetItemPosition
- AFXOLE/COleServerDoc::GetZoomFactor
- AFXOLE/COleServerDoc::IsDocObject
- AFXOLE/COleServerDoc::IsEmbedded
- AFXOLE/COleServerDoc::IsInPlaceActive
- AFXOLE/COleServerDoc::NotifyChanged
- AFXOLE/COleServerDoc::NotifyClosed
- AFXOLE/COleServerDoc::NotifyRename
- AFXOLE/COleServerDoc::NotifySaved
- AFXOLE/COleServerDoc::OnDeactivate
- AFXOLE/COleServerDoc::OnDeactivateUI
- AFXOLE/COleServerDoc::OnDocWindowActivate
- AFXOLE/COleServerDoc::OnResizeBorder
- AFXOLE/COleServerDoc::OnShowControlBars
- AFXOLE/COleServerDoc::OnUpdateDocument
- AFXOLE/COleServerDoc::RequestPositionChange
- AFXOLE/COleServerDoc::SaveEmbedding
- AFXOLE/COleServerDoc::ScrollContainerBy
- AFXOLE/COleServerDoc::UpdateAllItems
- AFXOLE/COleServerDoc::CreateInPlaceFrame
- AFXOLE/COleServerDoc::DestroyInPlaceFrame
- AFXOLE/COleServerDoc::GetDocObjectServer
- AFXOLE/COleServerDoc::OnClose
- AFXOLE/COleServerDoc::OnExecOleCmd
- AFXOLE/COleServerDoc::OnFrameWindowActivate
- AFXOLE/COleServerDoc::OnGetEmbeddedItem
- AFXOLE/COleServerDoc::OnReactivateAndUndo
- AFXOLE/COleServerDoc::OnSetHostNames
- AFXOLE/COleServerDoc::OnSetItemRects
- AFXOLE/COleServerDoc::OnShowDocument
helpviewer_keywords:
- COleServerDoc [MFC], COleServerDoc
- COleServerDoc [MFC], ActivateDocObject
- COleServerDoc [MFC], ActivateInPlace
- COleServerDoc [MFC], DeactivateAndUndo
- COleServerDoc [MFC], DiscardUndoState
- COleServerDoc [MFC], GetClientSite
- COleServerDoc [MFC], GetEmbeddedItem
- COleServerDoc [MFC], GetItemClipRect
- COleServerDoc [MFC], GetItemPosition
- COleServerDoc [MFC], GetZoomFactor
- COleServerDoc [MFC], IsDocObject
- COleServerDoc [MFC], IsEmbedded
- COleServerDoc [MFC], IsInPlaceActive
- COleServerDoc [MFC], NotifyChanged
- COleServerDoc [MFC], NotifyClosed
- COleServerDoc [MFC], NotifyRename
- COleServerDoc [MFC], NotifySaved
- COleServerDoc [MFC], OnDeactivate
- COleServerDoc [MFC], OnDeactivateUI
- COleServerDoc [MFC], OnDocWindowActivate
- COleServerDoc [MFC], OnResizeBorder
- COleServerDoc [MFC], OnShowControlBars
- COleServerDoc [MFC], OnUpdateDocument
- COleServerDoc [MFC], RequestPositionChange
- COleServerDoc [MFC], SaveEmbedding
- COleServerDoc [MFC], ScrollContainerBy
- COleServerDoc [MFC], UpdateAllItems
- COleServerDoc [MFC], CreateInPlaceFrame
- COleServerDoc [MFC], DestroyInPlaceFrame
- COleServerDoc [MFC], GetDocObjectServer
- COleServerDoc [MFC], OnClose
- COleServerDoc [MFC], OnExecOleCmd
- COleServerDoc [MFC], OnFrameWindowActivate
- COleServerDoc [MFC], OnGetEmbeddedItem
- COleServerDoc [MFC], OnReactivateAndUndo
- COleServerDoc [MFC], OnSetHostNames
- COleServerDoc [MFC], OnSetItemRects
- COleServerDoc [MFC], OnShowDocument
ms.assetid: a9cdd96a-e0ac-43bb-9203-2c29237e965c
ms.openlocfilehash: eec94a32fa0963d4cf2eccae0fb9e2423e75ffdc
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79421691"
---
# <a name="coleserverdoc-class"></a>Classe COleServerDoc

A classe base para documentos de servidor OLE.

## <a name="syntax"></a>Sintaxe

```
class AFX_NOVTABLE COleServerDoc : public COleLinkingDoc
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COleServerDoc::COleServerDoc](#coleserverdoc)|Constrói um objeto `COleServerDoc`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COleServerDoc::ActivateDocObject](#activatedocobject)|Ativa o documento DocObject associado.|
|[COleServerDoc::ActivateInPlace](#activateinplace)|Ativa o documento para edição in-loco.|
|[COleServerDoc::D eactivateAndUndo](#deactivateandundo)|Desativa a interface do usuário do servidor.|
|[COleServerDoc::D iscardUndoState](#discardundostate)|Descarta informações de estado de desfazer.|
|[COleServerDoc::GetClientSite](#getclientsite)|Recupera um ponteiro para a interface de `IOleClientSite` subjacente.|
|[COleServerDoc::GetEmbeddedItem](#getembeddeditem)|Retorna um ponteiro para um item que representa o documento inteiro.|
|[COleServerDoc::GetItemClipRect](#getitemcliprect)|Retorna o retângulo de recorte atual para edição in-loco.|
|[COleServerDoc::GetItemPosition](#getitemposition)|Retorna o retângulo de posição atual, relativo à área do cliente do aplicativo de contêiner, para edição in-loco.|
|[COleServerDoc::GetZoomFactor](#getzoomfactor)|Retorna o fator de zoom em pixels.|
|[COleServerDoc::IsDocObject](#isdocobject)|Determina se o documento é um DocObject.|
|[COleServerDoc:: IsEmbedded](#isembedded)|Indica se o documento está inserido em um documento de contêiner ou se está sendo executado de forma autônoma.|
|[COleServerDoc::IsInPlaceActive](#isinplaceactive)|Retornará TRUE se o item estiver atualmente ativado no local.|
|[COleServerDoc:: NotifyChanged](#notifychanged)|Notifica os contêineres que o usuário alterou o documento.|
|[COleServerDoc::NotifyClosed](#notifyclosed)|Notifica os contêineres que o usuário fechou o documento.|
|[COleServerDoc::NotifyRename](#notifyrename)|Notifica os contêineres de que o usuário renomeou o documento.|
|[COleServerDoc::NotifySaved](#notifysaved)|Notifica os contêineres que o usuário salvou o documento.|
|[COleServerDoc:: OnActivate](#ondeactivate)|Chamado pelo Framework quando o usuário desativa um item que foi ativado no local.|
|[COleServerDoc::OnDeactivateUI](#ondeactivateui)|Chamado pelo Framework para destruir controles e outros elementos de interface do usuário criados para ativação in-loco.|
|[COleServerDoc::OnDocWindowActivate](#ondocwindowactivate)|Chamado pelo Framework quando a janela do quadro do documento do contêiner é ativada ou desativada.|
|[COleServerDoc::OnResizeBorder](#onresizeborder)|Chamado pelo Framework quando a janela do quadro ou a janela do documento do aplicativo de contêiner é redimensionada.|
|[COleServerDoc::OnShowControlBars](#onshowcontrolbars)|Chamado pelo Framework para mostrar ou Ocultar barras de controle para edição in-loco.|
|[COleServerDoc::OnUpdateDocument](#onupdatedocument)|Chamado pelo Framework quando um documento do servidor que é um item inserido é salvo, atualizando a cópia do item do contêiner.|
|[COleServerDoc::RequestPositionChange](#requestpositionchange)|Altera a posição do quadro de edição in-loco.|
|[COleServerDoc::SaveEmbedding](#saveembedding)|Informa ao aplicativo de contêiner para salvar o documento.|
|[COleServerDoc::ScrollContainerBy](#scrollcontainerby)|Rola o documento do contêiner.|
|[COleServerDoc::UpdateAllItems](#updateallitems)|Notifica os contêineres que o usuário alterou o documento.|

### <a name="protected-methods"></a>Métodos protegidos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COleServerDoc::CreateInPlaceFrame](#createinplaceframe)|Chamado pelo Framework para criar uma janela de quadro para edição in-loco.|
|[COleServerDoc::D estroyInPlaceFrame](#destroyinplaceframe)|Chamado pelo Framework para destruir uma janela de quadro para edição in-loco.|
|[COleServerDoc::GetDocObjectServer](#getdocobjectserver)|Substitua essa função para criar um novo objeto `CDocObjectServer` e indicar que este documento é um contêiner DocObject.|
|[COleServerDoc:: fechamento](#onclose)|Chamado pelo Framework quando um contêiner solicita o fechamento do documento.|
|[COleServerDoc::OnExecOleCmd](#onexecolecmd)|Executa um comando especificado ou exibe a ajuda para o comando.|
|[COleServerDoc::OnFrameWindowActivate](#onframewindowactivate)|Chamado pelo Framework quando a janela do quadro do contêiner é ativada ou desativada.|
|[COleServerDoc:: OnGetEmbeddedItem](#ongetembeddeditem)|Chamado para obter um `COleServerItem` que representa o documento inteiro; usado para obter um item incorporado. Implementação necessária.|
|[COleServerDoc::OnReactivateAndUndo](#onreactivateandundo)|Chamado pelo Framework para desfazer as alterações feitas durante a edição in-loco.|
|[COleServerDoc::OnSetHostNames](#onsethostnames)|Chamado pelo Framework quando um contêiner define o título da janela para um objeto inserido.|
|[COleServerDoc::OnSetItemRects](#onsetitemrects)|Chamado pelo Framework para posicionar a janela do quadro de edição in-loco dentro da janela do aplicativo de contêiner.|
|[COleServerDoc::OnShowDocument](#onshowdocument)|Chamado pelo Framework para mostrar ou ocultar o documento.|

## <a name="remarks"></a>Comentários

Um documento de servidor pode conter objetos [COleServerItem](../../mfc/reference/coleserveritem-class.md) , que representam a interface do servidor para itens inseridos ou vinculados. Quando um aplicativo de servidor é iniciado por um contêiner para editar um item inserido, o item é carregado como seu próprio documento de servidor; o objeto `COleServerDoc` contém apenas um objeto `COleServerItem`, que consiste em todo o documento. Quando um aplicativo de servidor é iniciado por um contêiner para editar um item vinculado, um documento existente é carregado do disco; uma parte do conteúdo do documento é realçada para indicar o item vinculado.

`COleServerDoc` objetos também podem conter itens da classe [COleClientItem](../../mfc/reference/coleclientitem-class.md) . Isso permite que você crie aplicativos de servidor de contêiner. A estrutura fornece funções para armazenar corretamente os itens de `COleClientItem` ao atender os objetos de `COleServerItem`.

Se o aplicativo do servidor não oferecer suporte a links, um documento do servidor sempre conterá apenas um item de servidor, que representa o objeto inserido inteiro como um documento. Se o aplicativo de servidor não oferecer suporte a links, ele deverá criar um item de servidor sempre que uma seleção for copiada para a área de transferência.

Para usar `COleServerDoc`, derive uma classe dela e implemente a função membro [OnGetEmbeddedItem](#ongetembeddeditem) , que permite que o servidor dê suporte a itens inseridos. Derive uma classe de `COleServerItem` para implementar os itens em seus documentos e retornar objetos dessa classe de `OnGetEmbeddedItem`.

Para dar suporte a itens vinculados, `COleServerDoc` fornece a função de membro [OnGetLinkedItem](../../mfc/reference/colelinkingdoc-class.md#ongetlinkeditem) . Você pode usar a implementação padrão ou substituí-la se tiver sua própria maneira de gerenciar itens de documento.

Você precisa de uma classe derivada de `COleServerDoc`para cada tipo de documento de servidor ao qual seu aplicativo dá suporte. Por exemplo, se o aplicativo de servidor oferecer suporte a planilhas e gráficos, você precisará de duas classes derivadas de `COleServerDoc`.

Para obter mais informações sobre servidores, consulte o artigo [servidores: Implementando um servidor](../../mfc/servers-implementing-a-server.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CDocument](../../mfc/reference/cdocument-class.md)

[COleDocument](../../mfc/reference/coledocument-class.md)

[COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md)

`COleServerDoc`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxole. h

##  <a name="activatedocobject"></a>COleServerDoc::ActivateDocObject

Ativa o documento DocObject associado.

```
void ActivateDocObject();
```

### <a name="remarks"></a>Comentários

Por padrão, `COleServerDoc` não oferece suporte a documentos ativos (também conhecidos como DocObjects). Para habilitar esse suporte, consulte [GetDocObjectServer](#getdocobjectserver) e classe [CDocObjectServer](../../mfc/reference/cdocobjectserver-class.md).

##  <a name="activateinplace"></a>COleServerDoc::ActivateInPlace

Ativa o item para edição in-loco.

```
BOOL ActivateInPlace();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0, que indica que o item está totalmente aberto.

### <a name="remarks"></a>Comentários

Essa função executa todas as operações necessárias para ativação in-loco. Ele cria uma janela de quadro in-loco, ativa-a e a dimensiona para o item, configura menus compartilhados e outros controles, rola o item para a exibição e define o foco para a janela de quadro in-loco.

Essa função é chamada pela implementação padrão de [COleServerItem:: OnShow](../../mfc/reference/coleserveritem-class.md#onshow). Chame essa função se seu aplicativo der suporte a outro verbo para ativação in-loco (como Play).

##  <a name="coleserverdoc"></a>COleServerDoc::COleServerDoc

Constrói um objeto `COleServerDoc` sem se conectar com as DLLs do sistema OLE.

```
COleServerDoc();
```

### <a name="remarks"></a>Comentários

Você deve chamar [COleLinkingDoc:: Register](../../mfc/reference/colelinkingdoc-class.md#register) para abrir comunicações com OLE. Se você estiver usando o [COleTemplateServer](../../mfc/reference/coletemplateserver-class.md) em seu aplicativo, `COleLinkingDoc::Register` será chamado para você pela implementação de `COleLinkingDoc`de `OnNewDocument`, `OnOpenDocument`e `OnSaveDocument`.

##  <a name="createinplaceframe"></a>COleServerDoc::CreateInPlaceFrame

A estrutura chama essa função para criar uma janela de quadro para edição in-loco.

```
virtual COleIPFrameWnd* CreateInPlaceFrame(CWnd* pParentWnd);
```

### <a name="parameters"></a>parâmetros

*pParentWnd*<br/>
Ponteiro para a janela pai do aplicativo de contêiner.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a janela do quadro in-loco ou nulo se não for bem-sucedido.

### <a name="remarks"></a>Comentários

A implementação padrão usa as informações especificadas no modelo de documento para criar o quadro. A exibição usada é a primeira exibição criada para o documento. Essa exibição é temporariamente desanexada do quadro original e anexada ao quadro recém-criado.

Esse é um substituível avançado.

##  <a name="deactivateandundo"></a>COleServerDoc::D eactivateAndUndo

Chame essa função se seu aplicativo oferecer suporte a desfazer e o usuário escolher desfazer depois de ativar um item, mas antes de editá-lo.

```
BOOL DeactivateAndUndo();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero em caso de êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o aplicativo de contêiner for escrito usando o biblioteca MFC, chamar essa função fará com que [COleClientItem:: OnDeactivateAndUndo](../../mfc/reference/coleclientitem-class.md#ondeactivateandundo) seja chamado, o que desativa a interface do usuário do servidor.

##  <a name="destroyinplaceframe"></a>COleServerDoc::D estroyInPlaceFrame

A estrutura chama essa função para destruir uma janela de quadro in-loco e retornar a janela de documento do aplicativo de servidor ao seu estado antes da ativação in-loco.

```
virtual void DestroyInPlaceFrame(COleIPFrameWnd* pFrameWnd);
```

### <a name="parameters"></a>parâmetros

*pFrameWnd*<br/>
Ponteiro para a janela do quadro in-loco a ser destruído.

### <a name="remarks"></a>Comentários

Esse é um substituível avançado.

##  <a name="discardundostate"></a>COleServerDoc::D iscardUndoState

Se o usuário executar uma operação de edição que não pode ser desfeita, chame essa função para forçar o aplicativo de contêiner a descartar suas informações de estado de desfazer.

```
BOOL DiscardUndoState();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero em caso de êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é fornecida para que os servidores que dão suporte a desfazer possam liberar recursos que, de outra forma, seriam consumidos por informações de desfazer estado que não podem ser usadas.

##  <a name="getclientsite"></a>COleServerDoc::GetClientSite

Recupera um ponteiro para a interface de `IOleClientSite` subjacente.

```
LPOLECLIENTSITE GetClientSite() const;
```

### <a name="return-value"></a>Valor retornado

Recupera um ponteiro para a interface [IOleClientSite](/windows/win32/api/oleidl/nn-oleidl-ioleclientsite) subjacente.

##  <a name="getdocobjectserver"></a>COleServerDoc::GetDocObjectServer

Substitua essa função para criar um novo item de `CDocObjectServer` e retornar um ponteiro para ele.

```
virtual CDocObjectServer* GetDocObjectServer(LPOLEDOCUMENTSITE pDocSite);
```

### <a name="parameters"></a>parâmetros

*pDocSite*<br/>
Ponteiro para a interface de `IOleDocumentSite` que conectará este documento ao servidor.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um `CDocObjectServer`; NULL se a operação falhar.

### <a name="remarks"></a>Comentários

Quando um servidor DocObject é ativado, o retorno de um ponteiro não nulo mostra que o cliente pode dar suporte a DocObjects. A implementação padrão retorna NULL.

Uma implementação típica para um documento que dá suporte a DocObjects simplesmente alocará um novo objeto `CDocObjectServer` e o retornará ao chamador. Por exemplo:

[!code-cpp[NVC_MFCOleServer#3](../../mfc/codesnippet/cpp/coleserverdoc-class_1.cpp)]

##  <a name="getembeddeditem"></a>COleServerDoc::GetEmbeddedItem

Chame essa função para obter um ponteiro para um item que representa o documento inteiro.

```
COleServerItem* GetEmbeddedItem();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um item que representa o documento inteiro; NULL se a operação falhar.

### <a name="remarks"></a>Comentários

Ele chama [COleServerDoc:: OnGetEmbeddedItem](#ongetembeddeditem), uma função virtual sem implementação padrão.

##  <a name="getitemcliprect"></a>COleServerDoc::GetItemClipRect

Chame a função de membro `GetItemClipRect` para obter as coordenadas de retângulo de recorte do item que está sendo editado no local.

```
void GetItemClipRect(LPRECT lpClipRect) const;
```

### <a name="parameters"></a>parâmetros

*lpClipRect*<br/>
Ponteiro para uma estrutura de `RECT` ou um objeto de `CRect` para receber as coordenadas de retângulo de recorte do item.

### <a name="remarks"></a>Comentários

As coordenadas são em pixels em relação à área do cliente da janela do aplicativo de contêiner.

O desenho não deve ocorrer fora do retângulo de recorte. Normalmente, o desenho é restrito automaticamente. Use esta função para determinar se o usuário rolou para fora da parte visível do documento; Nesse caso, role o documento de contêiner conforme necessário por meio de uma chamada para [ScrollContainerBy](#scrollcontainerby).

##  <a name="getitemposition"></a>COleServerDoc::GetItemPosition

Chame a função de membro `GetItemPosition` para obter as coordenadas do item que está sendo editado no local.

```
void GetItemPosition(LPRECT lpPosRect) const;
```

### <a name="parameters"></a>parâmetros

*lpPosRect*<br/>
Ponteiro para uma estrutura de `RECT` ou um objeto de `CRect` para receber as coordenadas do item.

### <a name="remarks"></a>Comentários

As coordenadas são em pixels em relação à área do cliente da janela do aplicativo de contêiner.

A posição do item pode ser comparada ao retângulo de recorte atual para determinar a extensão até a qual o item está visível (ou não visível) na tela.

##  <a name="getzoomfactor"></a>COleServerDoc::GetZoomFactor

A função de membro `GetZoomFactor` determina o "fator de zoom" de um item que foi ativado para edição in-loco.

```
BOOL GetZoomFactor(
    LPSIZE lpSizeNum = NULL,
    LPSIZE lpSizeDenom = NULL,
    LPCRECT lpPosRect = NULL) const;
```

### <a name="parameters"></a>parâmetros

*lpSizeNum*<br/>
Ponteiro para um objeto da classe `CSize` que irá conter o numerador do fator de zoom. Pode ser NULL.

*lpSizeDenom*<br/>
Ponteiro para um objeto da classe `CSize` que irá conter o denominador do fator de zoom. Pode ser NULL.

*lpPosRect*<br/>
Ponteiro para um objeto da classe `CRect` que descreve a nova posição do item. Se esse argumento for nulo, a função usará a posição atual do item.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o item for ativado para edição in-loco e seu fator de zoom for diferente de 100% (1:1); caso contrário, 0.

### <a name="remarks"></a>Comentários

O fator de zoom, em pixels, é a proporção do tamanho do item em relação à sua extensão atual. Se o aplicativo de contêiner não tiver definido a extensão do item, sua extensão natural (conforme determinado por [COleServerItem:: OnGetExtent](../../mfc/reference/coleserveritem-class.md#ongetextent)) será usada.

A função define seus primeiros dois argumentos para o numerador e o denominador do "fator de zoom" do item. Se o item não estiver sendo editado no local, a função definirá esses argumentos como um valor padrão de 100% (ou 1:1) e retornará zero. Para obter mais informações, consulte a observação técnica 40, [redimensionamento e zoom no local do MFC/OLE](../../mfc/tn040-mfc-ole-in-place-resizing-and-zooming.md).

##  <a name="isdocobject"></a>COleServerDoc::IsDocObject

Determina se o documento é um DocObject.

```
BOOL IsDocObject() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o documento for um DocObject; caso contrário, FALSE.

##  <a name="isembedded"></a>COleServerDoc:: IsEmbedded

Chame a função de membro `IsEmbedded` para determinar se o documento representa um objeto inserido em um contêiner.

```
BOOL IsEmbedded() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o objeto `COleServerDoc` for um documento que representa um objeto inserido em um contêiner; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um documento carregado de um arquivo não é inserido, embora possa ser manipulado por um aplicativo de contêiner como um link. Um documento inserido em um documento de contêiner é considerado como incorporado.

##  <a name="isinplaceactive"></a>COleServerDoc::IsInPlaceActive

Chame a função de membro `IsInPlaceActive` para determinar se o item está atualmente no estado ativo in-loco.

```
BOOL IsInPlaceActive() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o objeto de `COleServerDoc` estiver ativo no local; caso contrário, 0.

##  <a name="notifychanged"></a>COleServerDoc:: NotifyChanged

Chame essa função para notificar todos os itens vinculados conectados ao documento que o documento alterou.

```
void NotifyChanged();
```

### <a name="remarks"></a>Comentários

Normalmente, você chama essa função depois que o usuário altera algum atributo global, como as dimensões do documento do servidor. Se um item OLE estiver vinculado ao documento com um link automático, o item será atualizado para refletir as alterações. Em aplicativos de contêiner escritos com o biblioteca MFC, a função de membro [onChange](../../mfc/reference/coleclientitem-class.md#onchange) de `COleClientItem` é chamada.

> [!NOTE]
>  Essa função é incluída para compatibilidade com o OLE 1. Os novos aplicativos devem usar o [UpdateAllItems](#updateallitems).

##  <a name="notifyclosed"></a>COleServerDoc::NotifyClosed

Chame essa função para notificar o (s) contêiner (es) de que o documento foi fechado.

```
void NotifyClosed();
```

### <a name="remarks"></a>Comentários

Quando o usuário escolhe o comando fechar no menu arquivo, `NotifyClosed` é chamado pela implementação de `COleServerDoc`da função membro [OnCloseDocument](../../mfc/reference/cdocument-class.md#onclosedocument) . Em aplicativos de contêiner escritos com o biblioteca MFC, a função de membro [onChange](../../mfc/reference/coleclientitem-class.md#onchange) de `COleClientItem` é chamada.

##  <a name="notifyrename"></a>COleServerDoc::NotifyRename

Chame essa função depois que o usuário renomear o documento do servidor.

```
void NotifyRename(LPCTSTR lpszNewName);
```

### <a name="parameters"></a>parâmetros

*lpszNewName*<br/>
Ponteiro para uma cadeia de caracteres especificando o novo nome do documento do servidor; Normalmente, esse é um caminho totalmente qualificado.

### <a name="remarks"></a>Comentários

Quando o usuário escolhe o comando Salvar como no menu arquivo, `NotifyRename` é chamado pela implementação de `COleServerDoc`da função membro [OnSaveDocument](../../mfc/reference/cdocument-class.md#onsavedocument) . Essa função notifica as DLLs do sistema OLE que, por sua vez, notificam os contêineres. Em aplicativos de contêiner escritos com o biblioteca MFC, a função de membro [onChange](../../mfc/reference/coleclientitem-class.md#onchange) de `COleClientItem` é chamada.

##  <a name="notifysaved"></a>COleServerDoc::NotifySaved

Chame essa função depois que o usuário salvar o documento do servidor.

```
void NotifySaved();
```

### <a name="remarks"></a>Comentários

Quando o usuário escolhe o comando salvar no menu arquivo, `NotifySaved` é chamado para você pela implementação de `COleServerDoc`do [OnSaveDocument](../../mfc/reference/cdocument-class.md#onsavedocument). Essa função notifica as DLLs do sistema OLE que, por sua vez, notificam os contêineres. Em aplicativos de contêiner escritos com o biblioteca MFC, a função de membro [onChange](../../mfc/reference/coleclientitem-class.md#onchange) de `COleClientItem` é chamada.

##  <a name="onclose"></a>COleServerDoc:: fechamento

Chamado pelo Framework quando um contêiner solicita que o documento do servidor seja fechado.

```
virtual void OnClose(OLECLOSE dwCloseOption);
```

### <a name="parameters"></a>parâmetros

*dwCloseOption*<br/>
Um valor da enumeração OLECLOSE. Esse parâmetro pode ter um dos seguintes valores:

- OLECLOSE_SAVEIFDIRTY o arquivo for salvo se ele tiver sido modificado.

- OLECLOSE_NOSAVE o arquivo está fechado sem ser salvo.

- OLECLOSE_PROMPTSAVE se o arquivo tiver sido modificado, o usuário será solicitado a salvá-lo.

### <a name="remarks"></a>Comentários

A implementação padrão chama `CDocument::OnCloseDocument`.

Para obter mais informações e valores adicionais, consulte [OLECLOSE](/windows/win32/api/oleidl/ne-oleidl-oleclose) no SDK do Windows.

##  <a name="ondeactivate"></a>COleServerDoc:: OnActivate

Chamado pelo Framework quando o usuário desativa um item incorporado ou vinculado que está atualmente no local ativo.

```
virtual void OnDeactivate();
```

### <a name="remarks"></a>Comentários

Essa função restaura a interface do usuário do aplicativo de contêiner para seu estado original e destrói todos os menus e outros controles que foram criados para ativação in-loco.

As informações de estado de desfazer devem ser liberadas incondicionalmente neste ponto.

Para obter mais informações, consulte o artigo [ativação](../../mfc/activation-cpp.md)..

##  <a name="ondeactivateui"></a>COleServerDoc::OnDeactivateUI

Chamado quando o usuário desativa um item que foi ativado no local.

```
virtual void OnDeactivateUI(BOOL bUndoable);
```

### <a name="parameters"></a>parâmetros

*bUndoable*<br/>
Especifica se as alterações de edição podem ser desfeitas.

### <a name="remarks"></a>Comentários

Essa função restaura a interface do usuário do aplicativo de contêiner para seu estado original, ocultando todos os menus e outros controles que foram criados para ativação in-loco.

A estrutura sempre define *bUndoable* como false. Se o servidor oferecer suporte a desfazer e houver uma operação que possa ser desfeita, chame a implementação da classe base com *bUndoable* definido como true.

##  <a name="ondocwindowactivate"></a>COleServerDoc::OnDocWindowActivate

A estrutura chama essa função para ativar ou desativar uma janela de documento para edição in-loco.

```
virtual void OnDocWindowActivate(BOOL bActivate);
```

### <a name="parameters"></a>parâmetros

*bActivate*<br/>
Especifica se a janela do documento deve ser ativada ou desativada.

### <a name="remarks"></a>Comentários

A implementação padrão remove ou adiciona os elementos da interface do usuário de nível de quadro, conforme apropriado. Substitua essa função se desejar executar ações adicionais quando o documento que contém o item for ativado ou desativado.

Para obter mais informações, consulte o artigo [ativação](../../mfc/activation-cpp.md)..

##  <a name="onexecolecmd"></a>COleServerDoc::OnExecOleCmd

A estrutura chama essa função para executar um comando especificado ou exibir a ajuda para o comando.

```
virtual HRESULT OnExecOleCmd(
    const GUID* pguidCmdGroup,
    DWORD nCmdID,
    DWORD nCmdExecOpt,
    VARIANTARG* pvarargIn,
    VARIANTARG* pvarargOut);
```

### <a name="parameters"></a>parâmetros

*pguidCmdGroup*<br/>
Um ponteiro para um GUID que identifica um conjunto de comandos. Pode ser NULL para indicar o grupo de comandos padrão.

*nCmdID*<br/>
O comando a ser executado. Deve estar no grupo identificado por *pguidCmdGroup*.

*nCmdExecOut*<br/>
A maneira como o objeto deve executar o comando, um ou mais dos seguintes valores da enumeração OLECMDEXECOPT:

OLECMDEXECOPT_DODEFAULT

OLECMDEXECOPT_PROMPTUSER

OLECMDEXECOPT_DONTPROMPTUSER

OLECMDEXECOPT_SHOWHELP

*pvarargIn*<br/>
Ponteiro para um VARIANTARG que contém argumentos de entrada para o comando. Pode ser NULL.

*pvarargOut*<br/>
Ponteiro para um VARIANTARG para receber os valores de retorno de saída do comando. Pode ser NULL.

### <a name="return-value"></a>Valor retornado

Retorna S_OK se obtiver êxito; caso contrário, um dos seguintes códigos de erro:

|Valor|DESCRIÇÃO|
|-----------|-----------------|
|E_UNEXPECTED|Ocorreu um erro inesperado|
|E_FAIL|Ocorreu um erro|
|{1&gt;E_NOTIMPL&lt;1}|Indica que o próprio MFC deve tentar traduzir e enviar o comando|
|OLECMDERR_E_UNKNOWNGROUP|*pguidCmdGroup* não é nulo, mas não especifica um grupo de comandos reconhecido|
|OLECMDERR_E_NOTSUPPORTED|*nCmdID* não é reconhecido como um comando válido no grupo *pguidCmdGroup*|
|OLECMDERR_DISABLED|O comando identificado por *nCmdID* está desabilitado e não pode ser executado|
|OLECMDERR_NOHELP|O chamador solicitou ajuda no comando identificado por *nCmdID* , mas nenhuma ajuda está disponível|
|OLECMDERR_CANCELED|O usuário cancelou a execução|

### <a name="remarks"></a>Comentários

`COleCmdUI` pode ser usado para habilitar, atualizar e definir outras propriedades de comandos da interface do usuário do DocObject. Depois que os comandos forem inicializados, você poderá executá-los com `OnExecOleCmd`.

A estrutura chama a função antes de tentar traduzir e distribuir um comando de documento OLE. Você não precisa substituir essa função para manipular comandos de documento OLE padrão, mas deve fornecer uma substituição para essa função se desejar manipular seus próprios comandos personalizados ou manipular comandos que aceitam parâmetros ou retornam resultados.

A maioria dos comandos não assume argumentos nem valores de retorno. Para obter a maioria dos comandos, o chamador pode passar nulos para *pvarargIn* e *pvarargOut*. Para comandos que esperam valores de entrada, o chamador pode declarar e inicializar uma variável VARIANTARG e passar um ponteiro para a variável em *pvarargIn*. Para comandos que exigem um único valor, o argumento pode ser armazenado diretamente no VARIANTARG e passado para a função. Vários argumentos devem ser empacotados dentro do VARIANTARG usando um dos tipos com suporte (como `IDispatch` e SAFEARRAY).

Da mesma forma, se um comando retornar argumentos, espera-se que o chamador declare um VARIANTARG, inicialize-o para VT_EMPTY e passe seu endereço em *pvarargOut*. Se um comando retornar um único valor, o objeto poderá armazenar esse valor diretamente em *pvarargOut*. Vários valores de saída devem ser empacotados de alguma maneira apropriada para o VARIANTARG.

A implementação da classe base dessa função examinará as estruturas de OLE_COMMAND_MAP associadas ao destino do comando e tentará enviar o comando para um manipulador apropriado. A implementação da classe base funciona apenas com comandos que não aceitam argumentos ou valores de retorno. Se você precisar manipular comandos que aceitam argumentos ou valores de retorno, você deve substituir essa função e trabalhar com os parâmetros *pvarargIn* e *pvarargOut* por conta própria.

##  <a name="onframewindowactivate"></a>COleServerDoc::OnFrameWindowActivate

A estrutura chama essa função quando a janela do quadro do aplicativo de contêiner é ativada ou desativada.

```
virtual void OnFrameWindowActivate(BOOL bActivate);
```

### <a name="parameters"></a>parâmetros

*bActivate*<br/>
Especifica se a janela do quadro deve ser ativada ou desativada.

### <a name="remarks"></a>Comentários

A implementação padrão cancela os modos de ajuda em que a janela do quadro pode estar. Substitua essa função se desejar executar processamento especial quando a janela do quadro for ativada ou desativada.

Para obter mais informações, consulte o artigo [ativação](../../mfc/activation-cpp.md)..

##  <a name="ongetembeddeditem"></a>COleServerDoc:: OnGetEmbeddedItem

Chamado pelo Framework quando um aplicativo de contêiner chama o aplicativo de servidor para criar ou editar um item inserido.

```
virtual COleServerItem* OnGetEmbeddedItem() = 0;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um item que representa o documento inteiro; NULL se a operação falhar.

### <a name="remarks"></a>Comentários

Não há implementação padrão. Você deve substituir essa função para retornar um item que representa o documento inteiro. Esse valor de retorno deve ser um objeto de uma classe derivada de `COleServerItem`.

##  <a name="onreactivateandundo"></a>COleServerDoc::OnReactivateAndUndo

A estrutura chama essa função quando o usuário opta por desfazer as alterações feitas em um item que foi ativado no local, alterado e subsequentemente desativado.

```
virtual BOOL OnReactivateAndUndo();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão não faz nada, exceto retorna FALSE para indicar falha.

Substitua essa função se seu aplicativo oferecer suporte a desfazer. Normalmente, você executaria a operação de desfazer e, em seguida, ativaria o item chamando `ActivateInPlace`. Se o aplicativo de contêiner for gravado com o biblioteca MFC, chamar `COleClientItem::ReactivateAndUndo` fará com que essa função seja chamada.

##  <a name="onresizeborder"></a>COleServerDoc::OnResizeBorder

A estrutura chama essa função quando o Windows do quadro do aplicativo de contêiner altera o tamanho.

```
virtual void OnResizeBorder(
    LPCRECT lpRectBorder,
    LPOLEINPLACEUIWINDOW lpUIWindow,
    BOOL bFrame);
```

### <a name="parameters"></a>parâmetros

*lpRectBorder*<br/>
Ponteiro para uma estrutura de `RECT` ou um objeto de `CRect` que especifica as coordenadas da borda.

*lpUIWindow*<br/>
Ponteiro para um objeto da classe `IOleInPlaceUIWindow` que possui a sessão de edição in-loco atual.

*bFrame*<br/>
TRUE se *lpUIWindow* apontar para a janela de quadro de nível superior do aplicativo de contêiner ou false se *lpUIWindow* apontar para a janela de quadro de nível de documento do aplicativo de contêiner.

### <a name="remarks"></a>Comentários

Essa função redimensiona e ajusta as barras de ferramentas e outros elementos da interface do usuário de acordo com o novo tamanho da janela.

Para obter mais informações, consulte [IOleInPlaceUIWindow](/windows/win32/api/oleidl/nn-oleidl-ioleinplaceuiwindow) no SDK do Windows.

Esse é um substituível avançado.

##  <a name="onsethostnames"></a>COleServerDoc::OnSetHostNames

Chamado pelo Framework quando o contêiner define ou altera os nomes de host para este documento.

```
virtual void OnSetHostNames(
    LPCTSTR lpszHost,
    LPCTSTR lpszHostObj);
```

### <a name="parameters"></a>parâmetros

*lpszHost*<br/>
Ponteiro para uma cadeia de caracteres que especifica o nome do aplicativo de contêiner.

*lpszHostObj*<br/>
Ponteiro para uma cadeia de caracteres que especifica o nome do contêiner para o documento.

### <a name="remarks"></a>Comentários

A implementação padrão altera o título do documento para todas as exibições referentes a este documento.

Substitua essa função se seu aplicativo definir os títulos por meio de um mecanismo diferente.

##  <a name="onsetitemrects"></a>COleServerDoc::OnSetItemRects

A estrutura chama essa função para posicionar a janela do quadro de edição in-loco dentro da janela do quadro do aplicativo de contêiner.

```
virtual void OnSetItemRects(
    LPCRECT lpPosRect,
    LPCRECT lpClipRect);
```

### <a name="parameters"></a>parâmetros

*lpPosRect*<br/>
Ponteiro para uma estrutura de `RECT` ou um objeto de `CRect` que especifica a posição da janela do quadro in-loco em relação à área do cliente do aplicativo de contêiner.

*lpClipRect*<br/>
Ponteiro para uma estrutura de `RECT` ou um objeto de `CRect` que especifica o retângulo de recorte da janela do quadro no local em relação à área do cliente do aplicativo de contêiner.

### <a name="remarks"></a>Comentários

Substitua essa função para atualizar o fator de zoom da exibição, se necessário.

Essa função geralmente é chamada em resposta a uma chamada `RequestPositionChange`, embora possa ser chamada a qualquer momento pelo contêiner para solicitar uma alteração de posição para o item in-loco.

##  <a name="onshowcontrolbars"></a>COleServerDoc::OnShowControlBars

A estrutura chama essa função para mostrar ou ocultar as barras de controle do aplicativo de servidor associadas à janela do quadro identificada por *pFrameWnd*.

```
virtual void OnShowControlBars(
    CFrameWnd* pFrameWnd,
    BOOL bShow);
```

### <a name="parameters"></a>parâmetros

*pFrameWnd*<br/>
Ponteiro para a janela do quadro cujas barras de controle devem ser ocultadas ou mostradas.

*bShow*<br/>
Determina se as barras de controle são mostradas ou ocultas.

### <a name="remarks"></a>Comentários

A implementação padrão enumera todas as barras de controle pertencentes à janela do quadro e as oculta ou mostra.

##  <a name="onshowdocument"></a>COleServerDoc::OnShowDocument

A estrutura chama a função `OnShowDocument` quando o documento do servidor deve ser ocultado ou exibido.

```
virtual void OnShowDocument(BOOL bShow);
```

### <a name="parameters"></a>parâmetros

*bShow*<br/>
Especifica se a interface do usuário para o documento deve ser exibida ou ocultada.

### <a name="remarks"></a>Comentários

Se *bShow* for true, a implementação padrão ativará o aplicativo de servidor, se necessário, e fará com que o aplicativo de contêiner role a janela para que o item fique visível. Se *bShow* for false, a implementação padrão desativará o item por meio de uma chamada para `OnDeactivate`, destruirá ou ocultará todas as janelas de quadros que foram criadas para o documento, exceto a primeira. Se nenhum documento visível permanecer, a implementação padrão ocultará o aplicativo de servidor.

##  <a name="onupdatedocument"></a>COleServerDoc::OnUpdateDocument

Chamado pelo Framework ao salvar um documento que é um item inserido em um documento composto.

```
virtual BOOL OnUpdateDocument();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o documento foi atualizado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão chama as funções membro [COleServerDoc:: NotifySaved](#notifysaved) e [COleServerDoc:: SaveEmbedding](#saveembedding) e marca o documento como limpo. Substitua essa função se desejar executar um processamento especial ao atualizar um item inserido.

##  <a name="requestpositionchange"></a>COleServerDoc::RequestPositionChange

Chame essa função de membro para que o aplicativo de contêiner altere a posição do item.

```
void RequestPositionChange(LPCRECT lpPosRect);
```

### <a name="parameters"></a>parâmetros

*lpPosRect*<br/>
Ponteiro para uma estrutura de `RECT` ou um objeto de `CRect` que contém a nova posição do item.

### <a name="remarks"></a>Comentários

Essa função é geralmente chamada (em conjunto com `UpdateAllItems`) quando os dados em um item ativo in-loco são alterados. Após essa chamada, o contêiner pode ou não executar a alteração chamando `OnSetItemRects`. A posição resultante pode ser diferente da solicitada.

##  <a name="saveembedding"></a>COleServerDoc::SaveEmbedding

Chame essa função para dizer ao aplicativo de contêiner para salvar o objeto inserido.

```
void SaveEmbedding();
```

### <a name="remarks"></a>Comentários

Essa função é chamada automaticamente do `OnUpdateDocument`. Observe que essa função faz com que o item seja atualizado no disco, portanto, geralmente é chamado apenas como resultado de uma ação específica do usuário.

##  <a name="scrollcontainerby"></a>COleServerDoc::ScrollContainerBy

Chame a função de membro `ScrollContainerBy` para rolar o documento de contêiner pelo valor, em pixels, indicado por `sizeScroll`.

```
BOOL ScrollContainerBy(CSize sizeScroll);
```

### <a name="parameters"></a>parâmetros

*sizeScroll*<br/>
Indica a distância da rolagem do documento de contêiner.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Valores positivos indicam a rolagem para baixo e para a direita; valores negativos indicam rolar para cima e para a esquerda.

##  <a name="updateallitems"></a>COleServerDoc::UpdateAllItems

Chame essa função para notificar todos os itens vinculados conectados ao documento que o documento alterou.

```
void UpdateAllItems(
    COleServerItem* pSender,
    LPARAM lHint = 0L,
    CObject* pHint = NULL,
    DVASPECT nDrawAspect = DVASPECT_CONTENT);
```

### <a name="parameters"></a>parâmetros

*pSender*<br/>
Ponteiro para o item que modificou o documento, ou nulo, se todos os itens forem atualizados.

*lHint*<br/>
Contém informações sobre a modificação.

*pHint*<br/>
Ponteiro para um objeto que armazena informações sobre a modificação.

*nDrawAspect*<br/>
Determina como o item deve ser desenhado. Esse é um valor da enumeração DVASPECT. Esse parâmetro pode ter um dos seguintes valores:

- DVASPECT_CONTENT item é representado de forma que possa ser exibido como um objeto incorporado dentro de seu contêiner.

- DVASPECT_THUMBNAIL item é renderizado em uma representação de "miniatura" para que possa ser exibido em uma ferramenta de navegação.

- DVASPECT_ICON item é representado por um ícone.

- DVASPECT_DOCPRINT Item é representado como se fosse impresso usando o comando Imprimir no menu arquivo.

### <a name="remarks"></a>Comentários

Normalmente, você chama essa função depois que o usuário altera o documento do servidor. Se um item OLE estiver vinculado ao documento com um link automático, o item será atualizado para refletir as alterações. Em aplicativos de contêiner escritos com o biblioteca MFC, a função de membro [onChange](../../mfc/reference/coleclientitem-class.md#onchange) de `COleClientItem` é chamada.

Essa função chama a função de membro `OnUpdate` para cada um dos itens do documento, exceto o item de envio, passando *pHint*, *lHint*e *nDrawAspect*. Use esses parâmetros para passar informações para os itens sobre as modificações feitas no documento. Você pode codificar informações usando *lHint* ou pode definir uma classe derivada de `CObject`para armazenar informações sobre as modificações e passar um objeto dessa classe usando *pHint*. Substitua a função de membro `OnUpdate` em sua classe derivada de `COleServerItem`para otimizar a atualização de cada item dependendo se sua apresentação foi alterada.

## <a name="see-also"></a>Confira também

[Exemplo de HIERSVR do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDocument](../../mfc/reference/coledocument-class.md)<br/>
[Classe COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md)<br/>
[Classe COleTemplateServer](../../mfc/reference/coletemplateserver-class.md)
