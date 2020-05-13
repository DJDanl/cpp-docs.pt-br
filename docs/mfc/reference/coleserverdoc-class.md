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
ms.openlocfilehash: 8e75ec5c00c614a225a059a2b3cf97a7a307c61c
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753780"
---
# <a name="coleserverdoc-class"></a>Classe COleServerDoc

A classe base para documentos do servidor OLE.

## <a name="syntax"></a>Sintaxe

```
class AFX_NOVTABLE COleServerDoc : public COleLinkingDoc
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleServerDoc::COleServerDoc](#coleserverdoc)|Constrói um objeto `COleServerDoc`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleServerDoc::AtivarDocObject](#activatedocobject)|Ativa o documento DocObject associado.|
|[COleServerDoc::AtivarinPlace](#activateinplace)|Ativa o documento para edição no local.|
|[COleServerDoc::DeactivateAndUndo](#deactivateandundo)|Desativa a interface de usuário do servidor.|
|[COleServerDoc::DiscardUndoState](#discardundostate)|Descarta informações de desfazer-estado.|
|[COleServerDoc::GetClientSite](#getclientsite)|Recupera um ponteiro para `IOleClientSite` a interface subjacente.|
|[COleServerDoc::GetEmbeddedItem](#getembeddeditem)|Retorna um ponteiro a um item representando todo o documento.|
|[COleServerDoc::GetItemClipRect](#getitemcliprect)|Retorna o retângulo de recorte atual para edição no local.|
|[COleServerDoc::GetItemPosition](#getitemposition)|Retorna o retângulo de posição atual, em relação à área cliente do aplicativo de contêiner, para edição no local.|
|[COleServerDoc::GetZoomFactor](#getzoomfactor)|Retorna o fator zoom em pixels.|
|[COleServerDoc::IsDocObject](#isdocobject)|Determina se o documento é um DocObject.|
|[COleServerDoc::IsEmbedded](#isembedded)|Indica se o documento está incorporado em um documento de contêiner ou executando autônomo.|
|[COleServerDoc::IsInPlaceActive](#isinplaceactive)|Retorna TRUE se o item estiver ativado no momento.|
|[COleServerDoc::NotificarAlterado](#notifychanged)|Notifica os contêineres de que o usuário alterou o documento.|
|[COleServerDoc::NotificarFechado](#notifyclosed)|Notifica os contêineres de que o usuário fechou o documento.|
|[COleServerDoc::NotificarRenome](#notifyrename)|Notifica os contêineres que o usuário renomeou o documento.|
|[COleServerDoc::NotificarSaved](#notifysaved)|Notifica os contêineres de que o usuário salvou o documento.|
|[COleServerDoc::OnDeSactivate](#ondeactivate)|Chamado pela estrutura quando o usuário desativa um item que foi ativado no local.|
|[COleServerDoc::OnDeSactivateUI](#ondeactivateui)|Chamado pela estrutura para destruir controles e outros elementos de interface de usuário criados para ativação no local.|
|[COleServerDoc::OnDocWindowActivate](#ondocwindowactivate)|Chamado pela estrutura quando a janela do quadro de documentos do contêiner é ativada ou desativada.|
|[COleServerDoc::OnResizeBorder](#onresizeborder)|Chamado pela estrutura quando a janela de quadro ou documento do aplicativo de contêiner é redimensionada.|
|[COleServerDoc::OnShowControlBars](#onshowcontrolbars)|Chamado pela estrutura para mostrar ou ocultar barras de controle para edição no local.|
|[COleServerDoc::OnUpdateDocument](#onupdatedocument)|Chamado pela estrutura quando um documento de servidor que é um item incorporado é salvo, atualizando a cópia do contêiner do item.|
|[COleServerDoc::RequestPositionChange](#requestpositionchange)|Altera a posição do quadro de edição no local.|
|[COleServerDoc::SaveEmbedding](#saveembedding)|Diz ao aplicativo do contêiner para salvar o documento.|
|[COleServerDoc::ScrollContainerBy](#scrollcontainerby)|Rola o documento do contêiner.|
|[COleServerDoc::UpdateAllItems](#updateallitems)|Notifica os contêineres de que o usuário alterou o documento.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[COleServerDoc::CreateInPlaceFrame](#createinplaceframe)|Chamado pela estrutura para criar uma janela de quadro para edição no local.|
|[COleServerDoc::DestroyInPlaceFrame](#destroyinplaceframe)|Chamado pela estrutura para destruir uma janela de quadro para edição no local.|
|[COleServerDoc::GetDocObjectServer](#getdocobjectserver)|Substituir essa função para `CDocObjectServer` criar um novo objeto e indicar que este documento é um recipiente DocObject.|
|[COleServerDoc::OnClose](#onclose)|Chamado pela estrutura quando um contêiner solicita o fechamento do documento.|
|[COleServerDoc::OnExecOleCmd](#onexecolecmd)|Executa um comando especificado ou exibe ajuda para o comando.|
|[COleServerDoc::OnFrameWindowActivate](#onframewindowactivate)|Chamado pela estrutura quando a janela do quadro do contêiner é ativada ou desativada.|
|[COleServerDoc::OnGetEmbeddedItem](#ongetembeddeditem)|Chamado para `COleServerItem` obter um que representa todo o documento; usado para obter um item incorporado. Implementação necessária.|
|[COleServerDoc::OnReactivateAndUndo](#onreactivateandundo)|Chamado pelo framework para desfazer alterações feitas durante a edição no local.|
|[COleServerDoc::OnSetHostNames](#onsethostnames)|Chamado pela estrutura quando um contêiner define o título da janela para um objeto incorporado.|
|[COleServerDoc::OnSetItemRects](#onsetitemrects)|Chamado pela estrutura para posicionar a janela do quadro de edição no local dentro da janela do aplicativo de contêiner.|
|[COleServerDoc::OnShowDocument](#onshowdocument)|Chamado pela estrutura para mostrar ou ocultar o documento.|

## <a name="remarks"></a>Comentários

Um documento de servidor pode conter objetos [COleServerItem,](../../mfc/reference/coleserveritem-class.md) que representam a interface do servidor para itens incorporados ou vinculados. Quando um aplicativo de servidor é lançado por um contêiner para editar um item incorporado, o item é carregado como seu próprio documento de servidor; o `COleServerDoc` objeto contém `COleServerItem` apenas um objeto, consistindo de todo o documento. Quando um aplicativo de servidor é lançado por um contêiner para editar um item vinculado, um documento existente é carregado a partir do disco; uma parte do conteúdo do documento é destacada para indicar o item vinculado.

`COleServerDoc`objetos também podem conter itens da classe [COleClientItem.](../../mfc/reference/coleclientitem-class.md) Isso permite que você crie aplicativos de servidor de contêiner. A estrutura fornece funções `COleClientItem` para armazenar corretamente os `COleServerItem` itens durante a manutenção dos objetos.

Se o aplicativo do servidor não suportar links, um documento de servidor sempre conterá apenas um item do servidor, que representa todo o objeto incorporado como um documento. Se o aplicativo do servidor tiver suporte a links, ele deve criar um item de servidor cada vez que uma seleção for copiada para a Área de Transferência.

Para `COleServerDoc`usar, obtenha uma classe a partir dele e implemente a função membro [OnGetEmbeddedItem,](#ongetembeddeditem) que permite que seu servidor suporte itens incorporados. Obtenha uma `COleServerItem` classe para implementar os itens em seus documentos e `OnGetEmbeddedItem`devolva objetos dessa classe de .

Para suportar itens vinculados, `COleServerDoc` fornece a função membro [OnGetLinkedItem.](../../mfc/reference/colelinkingdoc-class.md#ongetlinkeditem) Você pode usar a implementação padrão ou substituí-la se tiver sua própria maneira de gerenciar itens de documento.

Você precisa `COleServerDoc`de uma classe derivada para cada tipo de documento de servidor que seu aplicativo suporta. Por exemplo, se o aplicativo do servidor suportar `COleServerDoc`planilhas e gráficos, você precisará de duas classes derivadas.

Para obter mais informações sobre servidores, consulte o artigo [Servidores: Implementando um Servidor](../../mfc/servers-implementing-a-server.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[Cdocument](../../mfc/reference/cdocument-class.md)

[Coledocument](../../mfc/reference/coledocument-class.md)

[Colelinkingdoc](../../mfc/reference/colelinkingdoc-class.md)

`COleServerDoc`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

## <a name="coleserverdocactivatedocobject"></a><a name="activatedocobject"></a>COleServerDoc::AtivarDocObject

Ativa o documento DocObject associado.

```cpp
void ActivateDocObject();
```

### <a name="remarks"></a>Comentários

Por padrão, `COleServerDoc` não suporta documentos ativos (também chamados de DocObjects). Para habilitar esse suporte, consulte [GetDocObjectServer](#getdocobjectserver) e [classe CDocObjectServer](../../mfc/reference/cdocobjectserver-class.md).

## <a name="coleserverdocactivateinplace"></a><a name="activateinplace"></a>COleServerDoc::AtivarinPlace

Ativa o item para edição no local.

```
BOOL ActivateInPlace();
```

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário 0, o que indica que o item está totalmente aberto.

### <a name="remarks"></a>Comentários

Esta função executa todas as operações necessárias para ativação no local. Ele cria uma janela de quadro no lugar, ativa-a e dimensiona-a para o item, configura menus compartilhados e outros controles, rola o item para a exibição e define o foco para a janela do quadro no local.

Essa função é chamada pela implementação padrão do [COleServerItem::OnShow](../../mfc/reference/coleserveritem-class.md#onshow). Chame esta função se o aplicativo suportar outro verbo para ativação no local (como Play).

## <a name="coleserverdoccoleserverdoc"></a><a name="coleserverdoc"></a>COleServerDoc::COleServerDoc

Constrói um `COleServerDoc` objeto sem se conectar com as DLLs do sistema OLE.

```
COleServerDoc();
```

### <a name="remarks"></a>Comentários

Você deve ligar para [coleLinkingDoc::Registre-se](../../mfc/reference/colelinkingdoc-class.md#register) para abrir comunicações com o OLE. Se você estiver usando [coleTemplateServer](../../mfc/reference/coletemplateserver-class.md) em seu `COleLinkingDoc::Register` `COleLinkingDoc`aplicativo, é `OnNewDocument`chamado para você pela implementação de , `OnOpenDocument`e `OnSaveDocument`.

## <a name="coleserverdoccreateinplaceframe"></a><a name="createinplaceframe"></a>COleServerDoc::CreateInPlaceFrame

A estrutura chama essa função para criar uma janela de quadro para edição no local.

```
virtual COleIPFrameWnd* CreateInPlaceFrame(CWnd* pParentWnd);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
Ponteiro para a janela pai do aplicativo de contêiner.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a janela do quadro no lugar ou NULO se não tiver sucesso.

### <a name="remarks"></a>Comentários

A implementação padrão usa informações especificadas no modelo do documento para criar o quadro. A exibição utilizada é a primeira exibição criada para o documento. Esta exibição é temporariamente separada do quadro original e anexada ao quadro recém-criado.

Este é um avançado super-rididável.

## <a name="coleserverdocdeactivateandundo"></a><a name="deactivateandundo"></a>COleServerDoc::DeactivateAndUndo

Chame esta função se o aplicativo suportar Desfazer e o usuário escolher Desfazer depois de ativar um item, mas antes de editá-lo.

```
BOOL DeactivateAndUndo();
```

### <a name="return-value"></a>Valor retornado

Não zero no sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o aplicativo de contêiner for escrito usando a Biblioteca de Classes da Microsoft Foundation, chamar essa função faz com que [coleClientItem::OnDeactivateAndUndo](../../mfc/reference/coleclientitem-class.md#ondeactivateandundo) seja chamado, o que desativa a interface de usuário do servidor.

## <a name="coleserverdocdestroyinplaceframe"></a><a name="destroyinplaceframe"></a>COleServerDoc::DestroyInPlaceFrame

A estrutura chama essa função para destruir uma janela de quadro no local e retornar a janela de documento do aplicativo do servidor para o seu estado antes da ativação no local.

```
virtual void DestroyInPlaceFrame(COleIPFrameWnd* pFrameWnd);
```

### <a name="parameters"></a>Parâmetros

*pFrameWnd*<br/>
Ponteiro para a janela do quadro no local a ser destruído.

### <a name="remarks"></a>Comentários

Este é um avançado super-rididável.

## <a name="coleserverdocdiscardundostate"></a><a name="discardundostate"></a>COleServerDoc::DiscardUndoState

Se o usuário realizar uma operação de edição que não possa ser desfeita, chame esta função para forçar o aplicativo de contêiner a descartar suas informações de desfazer-estado.

```
BOOL DiscardUndoState();
```

### <a name="return-value"></a>Valor retornado

Não zero no sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é fornecida para que os servidores que suportam o Desfazer possam liberar recursos que de outra forma seriam consumidos por informações de desfazer-estado que não podem ser usadas.

## <a name="coleserverdocgetclientsite"></a><a name="getclientsite"></a>COleServerDoc::GetClientSite

Recupera um ponteiro para `IOleClientSite` a interface subjacente.

```
LPOLECLIENTSITE GetClientSite() const;
```

### <a name="return-value"></a>Valor retornado

Recupera um ponteiro para a interface [IOleClientSite](/windows/win32/api/oleidl/nn-oleidl-ioleclientsite) subjacente.

## <a name="coleserverdocgetdocobjectserver"></a><a name="getdocobjectserver"></a>COleServerDoc::GetDocObjectServer

Anular esta função para `CDocObjectServer` criar um novo item e retornar um ponteiro para ele.

```
virtual CDocObjectServer* GetDocObjectServer(LPOLEDOCUMENTSITE pDocSite);
```

### <a name="parameters"></a>Parâmetros

*pDocSite*<br/>
Ponteiro para `IOleDocumentSite` a interface que conectará este documento ao servidor.

### <a name="return-value"></a>Valor retornado

Um ponteiro `CDocObjectServer`para um; NULO se a operação falhar.

### <a name="remarks"></a>Comentários

Quando um servidor DocObject é ativado, o retorno de um ponteiro não-NULL mostra que o cliente pode suportar DocObjects. A implementação padrão retorna NULL.

Uma implementação típica para um documento que suporta `CDocObjectServer` DocObjects simplesmente alocará um novo objeto e o devolverá ao chamador. Por exemplo:

[!code-cpp[NVC_MFCOleServer#3](../../mfc/codesnippet/cpp/coleserverdoc-class_1.cpp)]

## <a name="coleserverdocgetembeddeditem"></a><a name="getembeddeditem"></a>COleServerDoc::GetEmbeddedItem

Chame esta função para obter um ponteiro para um item representando todo o documento.

```
COleServerItem* GetEmbeddedItem();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um item representando todo o documento; NULO se a operação falhar.

### <a name="remarks"></a>Comentários

Ele chama [COleServerDoc::OnGetEmbeddedItem](#ongetembeddeditem), uma função virtual sem implementação padrão.

## <a name="coleserverdocgetitemcliprect"></a><a name="getitemcliprect"></a>COleServerDoc::GetItemClipRect

Ligue `GetItemClipRect` para a função membro para obter as coordenadas retângulo de recorte do item que está sendo editado no lugar.

```cpp
void GetItemClipRect(LPRECT lpClipRect) const;
```

### <a name="parameters"></a>Parâmetros

*lpClipRect*<br/>
Ponteiro para `RECT` uma `CRect` estrutura ou um objeto para receber as coordenadas retângulo de recorte do item.

### <a name="remarks"></a>Comentários

As coordenadas estão em pixels relativos à área cliente da janela do aplicativo de contêiner.

O desenho não deve ocorrer fora do retângulo de recorte. Normalmente, o desenho é automaticamente restrito. Use esta função para determinar se o usuário rolou para fora da parte visível do documento; se assim for, role o documento do contêiner conforme necessário por meio de uma chamada para [ScrollContainerBy](#scrollcontainerby).

## <a name="coleserverdocgetitemposition"></a><a name="getitemposition"></a>COleServerDoc::GetItemPosition

Ligue `GetItemPosition` para a função de membro para obter as coordenadas do item que está sendo editado no lugar.

```cpp
void GetItemPosition(LPRECT lpPosRect) const;
```

### <a name="parameters"></a>Parâmetros

*lpPosRect*<br/>
Ponteiro para `RECT` uma `CRect` estrutura ou um objeto para receber as coordenadas do item.

### <a name="remarks"></a>Comentários

As coordenadas estão em pixels relativos à área cliente da janela do aplicativo de contêiner.

A posição do item pode ser comparada com o retângulo de recorte atual para determinar até que ponto o item está visível (ou não visível) na tela.

## <a name="coleserverdocgetzoomfactor"></a><a name="getzoomfactor"></a>COleServerDoc::GetZoomFactor

A `GetZoomFactor` função membro determina o "fator zoom" de um item que foi ativado para edição no local.

```
BOOL GetZoomFactor(
    LPSIZE lpSizeNum = NULL,
    LPSIZE lpSizeDenom = NULL,
    LPCRECT lpPosRect = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*lpSizeNum*<br/>
Ponteiro para um `CSize` objeto de classe que irá segurar o numerador do fator zoom. Pode ser NULL.

*lpSizeDenom*<br/>
Ponteiro para um `CSize` objeto de classe que irá segurar o denominador do fator zoom. Pode ser NULL.

*lpPosRect*<br/>
Ponteiro para um `CRect` objeto de classe que descreve a nova posição do item. Se esse argumento for NULO, a função usará a posição atual do item.

### <a name="return-value"></a>Valor retornado

Não zero se o item for ativado para edição no local e seu fator de zoom for diferente de 100% (1:1); caso contrário, 0.

### <a name="remarks"></a>Comentários

O fator zoom, em pixels, é a proporção do tamanho do item até a sua extensão atual. Se o aplicativo de contêiner não tiver definido a extensão do item, sua extensão natural (conforme determinado por [COleServerItem::OnGetExtent](../../mfc/reference/coleserveritem-class.md#ongetextent)) será usada.

A função define seus dois primeiros argumentos para o numerador e denominador do "fator zoom" do item. Se o item não estiver sendo editado no lugar, a função definirá esses argumentos para um valor padrão de 100% (ou 1:1) e retorna zero. Para obter mais informações, consulte Nota Técnica 40, [Redimensionamento e Zoom no Local do MFC/OLE.](../../mfc/tn040-mfc-ole-in-place-resizing-and-zooming.md)

## <a name="coleserverdocisdocobject"></a><a name="isdocobject"></a>COleServerDoc::IsDocObject

Determina se o documento é um DocObject.

```
BOOL IsDocObject() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o documento for um DocObject; caso contrário, FALSO.

## <a name="coleserverdocisembedded"></a><a name="isembedded"></a>COleServerDoc::IsEmbedded

Ligue `IsEmbedded` para a função membro para determinar se o documento representa um objeto incorporado em um contêiner.

```
BOOL IsEmbedded() const;
```

### <a name="return-value"></a>Valor retornado

Não zero `COleServerDoc` se o objeto for um documento que represente um objeto incorporado em um contêiner; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um documento carregado de um arquivo não está incorporado, embora possa ser manipulado por um aplicativo de contêiner como um link. Considera-se que um documento embutido em um documento de contêiner está embutido.

## <a name="coleserverdocisinplaceactive"></a><a name="isinplaceactive"></a>COleServerDoc::IsInPlaceActive

Ligue `IsInPlaceActive` para a função membro para determinar se o item está atualmente no estado ativo em vigor.

```
BOOL IsInPlaceActive() const;
```

### <a name="return-value"></a>Valor retornado

Não zero `COleServerDoc` se o objeto estiver ativo no lugar; caso contrário, 0.

## <a name="coleserverdocnotifychanged"></a><a name="notifychanged"></a>COleServerDoc::NotificarAlterado

Ligue para esta função para notificar todos os itens vinculados conectados ao documento que o documento foi alterado.

```cpp
void NotifyChanged();
```

### <a name="remarks"></a>Comentários

Normalmente, você chama essa função depois que o usuário altera algum atributo global, como as dimensões do documento do servidor. Se um item OLE estiver vinculado ao documento com um link automático, o item será atualizado para refletir as alterações. Em aplicativos de contêiner escritos com a Microsoft Foundation `COleClientItem` Class Library, a função de membro [OnChange](../../mfc/reference/coleclientitem-class.md#onchange) é chamada.

> [!NOTE]
> Esta função está incluída para compatibilidade com o OLE 1. Novos aplicativos devem usar [UpdateAllItems](#updateallitems).

## <a name="coleserverdocnotifyclosed"></a><a name="notifyclosed"></a>COleServerDoc::NotificarFechado

Ligue para esta função para notificar os contêineres que o documento foi fechado.

```cpp
void NotifyClosed();
```

### <a name="remarks"></a>Comentários

Quando o usuário escolhe o comando Fechar `NotifyClosed` no `COleServerDoc`menu Arquivo, é chamada pela implementação da função de membro [OnCloseDocument.](../../mfc/reference/cdocument-class.md#onclosedocument) Em aplicativos de contêiner escritos com a Microsoft Foundation `COleClientItem` Class Library, a função de membro [OnChange](../../mfc/reference/coleclientitem-class.md#onchange) é chamada.

## <a name="coleserverdocnotifyrename"></a><a name="notifyrename"></a>COleServerDoc::NotificarRenome

Chame esta função depois que o usuário renomear o documento do servidor.

```cpp
void NotifyRename(LPCTSTR lpszNewName);
```

### <a name="parameters"></a>Parâmetros

*lpszNewName*<br/>
Ponteiro para uma seqüência especificando o novo nome do documento do servidor; este é tipicamente um caminho totalmente qualificado.

### <a name="remarks"></a>Comentários

Quando o usuário escolhe o comando Salvar `NotifyRename` como no `COleServerDoc`menu Arquivo, é chamado pela implementação da função de membro [OnSaveDocument.](../../mfc/reference/cdocument-class.md#onsavedocument) Esta função notifica as DLLs do sistema OLE, que por sua vez notificam os recipientes. Em aplicativos de contêiner escritos com a Microsoft Foundation `COleClientItem` Class Library, a função de membro [OnChange](../../mfc/reference/coleclientitem-class.md#onchange) é chamada.

## <a name="coleserverdocnotifysaved"></a><a name="notifysaved"></a>COleServerDoc::NotificarSaved

Chame esta função depois que o usuário salvar o documento do servidor.

```cpp
void NotifySaved();
```

### <a name="remarks"></a>Comentários

Quando o usuário escolhe o comando Salvar `NotifySaved` no menu `COleServerDoc`Arquivo, é chamado para você pela implementação do [OnSaveDocument](../../mfc/reference/cdocument-class.md#onsavedocument). Esta função notifica as DLLs do sistema OLE, que por sua vez notificam os recipientes. Em aplicativos de contêiner escritos com a Microsoft Foundation `COleClientItem` Class Library, a função de membro [OnChange](../../mfc/reference/coleclientitem-class.md#onchange) é chamada.

## <a name="coleserverdoconclose"></a><a name="onclose"></a>COleServerDoc::OnClose

Chamado pela estrutura quando um contêiner solicita que o documento do servidor seja fechado.

```
virtual void OnClose(OLECLOSE dwCloseOption);
```

### <a name="parameters"></a>Parâmetros

*dwCloseOption*<br/>
Um valor da enumeração OLECLOSE. Esse parâmetro pode ter um dos seguintes valores:

- OLECLOSE_SAVEIFDIRTYO arquivo é salvo se tiver sido modificado.

- OLECLOSE_NOSAVE O arquivo é fechado sem ser salvo.

- OLECLOSE_PROMPTSAVE Se o arquivo foi modificado, o usuário é solicitado a salvá-lo.

### <a name="remarks"></a>Comentários

As chamadas `CDocument::OnCloseDocument`de implementação padrão .

Para obter mais informações e valores adicionais, consulte [OLECLOSE](/windows/win32/api/oleidl/ne-oleidl-oleclose) no SDK do Windows.

## <a name="coleserverdocondeactivate"></a><a name="ondeactivate"></a>COleServerDoc::OnDeSactivate

Chamado pela estrutura quando o usuário desativa um item incorporado ou vinculado que está atualmente ativo no local.

```
virtual void OnDeactivate();
```

### <a name="remarks"></a>Comentários

Esta função restaura a interface de usuário do aplicativo de contêiner ao seu estado original e destrói quaisquer menus e outros controles que foram criados para ativação no local.

As informações do estado de desfazer devem ser divulgadas incondicionalmente neste momento.

Para obter mais informações, consulte o artigo [Ativação](../../mfc/activation-cpp.md)..

## <a name="coleserverdocondeactivateui"></a><a name="ondeactivateui"></a>COleServerDoc::OnDeSactivateUI

Chamado quando o usuário desativa um item que foi ativado no local.

```
virtual void OnDeactivateUI(BOOL bUndoable);
```

### <a name="parameters"></a>Parâmetros

*bUndoable*<br/>
Especifica se as alterações de edição podem ser desfeitas.

### <a name="remarks"></a>Comentários

Esta função restaura a interface de usuário do aplicativo de contêiner ao seu estado original, ocultando quaisquer menus e outros controles que foram criados para ativação no local.

A estrutura sempre define *bUndoable* para FALSE. Se o servidor suportar desfazer e houver uma operação que possa ser desfeita, chame a implementação da classe base com *bUndoable* set para TRUE.

## <a name="coleserverdocondocwindowactivate"></a><a name="ondocwindowactivate"></a>COleServerDoc::OnDocWindowActivate

A estrutura chama essa função para ativar ou desativar uma janela de documento para edição no local.

```
virtual void OnDocWindowActivate(BOOL bActivate);
```

### <a name="parameters"></a>Parâmetros

*bAtivar*<br/>
Especifica se a janela do documento deve ser ativada ou desativada.

### <a name="remarks"></a>Comentários

A implementação padrão remove ou adiciona os elementos de interface do usuário em nível de quadro conforme apropriado. Anular essa função se você quiser executar ações adicionais quando o documento contendo seu item estiver ativado ou desativado.

Para obter mais informações, consulte o artigo [Ativação](../../mfc/activation-cpp.md)..

## <a name="coleserverdoconexecolecmd"></a><a name="onexecolecmd"></a>COleServerDoc::OnExecOleCmd

A estrutura chama essa função para executar um comando especificado ou mostrar ajuda para o comando.

```
virtual HRESULT OnExecOleCmd(
    const GUID* pguidCmdGroup,
    DWORD nCmdID,
    DWORD nCmdExecOpt,
    VARIANTARG* pvarargIn,
    VARIANTARG* pvarargOut);
```

### <a name="parameters"></a>Parâmetros

*Pguidcmdgroup*<br/>
Um ponteiro para um GUID que identifica um conjunto de comandos. Pode ser NULL para indicar o grupo de comando padrão.

*Ncmdid*<br/>
O comando a ser executado. Deve estar no grupo identificado pelo *pguidCmdGroup*.

*nCmdExecOut*<br/>
A forma como o objeto deve executar o comando, um ou mais dos seguintes valores da enumeração OLECMDEXECOPT:

OLECMDEXECOPT_DODEFAULT

OLECMDEXECOPT_PROMPTUSER

OLECMDEXECOPT_DONTPROMPTUSER

OLECMDEXECOPT_SHOWHELP

*Pvarargin*<br/>
Ponteiro para um VARIANTARG contendo argumentos de entrada para o comando. Pode ser NULL.

*Pvarargout*<br/>
Pointer para um VARIANTARG para receber os valores de retorno de saída do comando. Pode ser NULL.

### <a name="return-value"></a>Valor retornado

Os retornos S_OK se forem bem sucedidos; caso contrário, um dos seguintes códigos de erro:

|Valor|Descrição|
|-----------|-----------------|
|E_UNEXPECTED|Erro inesperado ocorreu|
|E_FAIL|na instalação|
|E_NOTIMPL|Indica que o próprio MFC deve tentar traduzir e despachar o comando|
|OLECMDERR_E_UNKNOWNGROUP|*pguidCmdGroup* não é NULA, mas não especifica um grupo de comando reconhecido|
|OLECMDERR_E_NOTSUPPORTED|*nCmdID* não é reconhecido como um comando válido no grupo *pguidCmdGroup*|
|OLECMDERR_DISABLED|O comando identificado pelo *nCmdID* está desativado e não pode ser executado|
|OLECMDERR_NOHELP|O chamador pediu ajuda no comando identificado pelo *nCmdID,* mas nenhuma ajuda está disponível|
|OLECMDERR_CANCELED|Usuário cancelou a execução|

### <a name="remarks"></a>Comentários

`COleCmdUI`pode ser usado para ativar, atualizar e definir outras propriedades dos comandos de interface do usuário DocObject. Depois que os comandos são inicializados, você pode executá-los com `OnExecOleCmd`.

O framework chama a função antes de tentar traduzir e enviar um comando de documento OLE. Você não precisa substituir essa função para lidar com comandos de documentos OLE padrão, mas você deve fornecer uma substituição a esta função se você quiser lidar com seus próprios comandos personalizados ou lidar com comandos que aceitem parâmetros ou resultados de retorno.

A maioria dos comandos não aceita argumentos ou valores de devolução. Para a maioria dos comandos, o chamador pode passar NULLs para *pvarargIn* e *pvarargOut*. Para comandos que esperam valores de entrada, o chamador pode declarar e inicializar uma variável VARIANTARG e passar um ponteiro para a variável em *pvarargIn*. Para comandos que requerem um único valor, o argumento pode ser armazenado diretamente no VARIANTARG e passado para a função. Vários argumentos devem ser embalados dentro do VARIANTARG usando `IDispatch` um dos tipos suportados (como e SAFEARRAY ).

Da mesma forma, se um comando retornar argumentos, espera-se que o chamador declare um VARIANTARG, inicialize-o para VT_EMPTY e passe seu endereço em *pvarargOut*. Se um comando retornar um único valor, o objeto poderá armazenar esse valor diretamente em *pvarargOut*. Vários valores de saída devem ser embalados de alguma forma apropriados para o VARIANTARG.

A implementação da classe base desta função caminhará pelas estruturas OLE_COMMAND_MAP associadas ao alvo de comando e tentará enviar o comando para um manipulador apropriado. A implementação da classe base funciona apenas com comandos que não aceitam argumentos ou valores de devolução. Se você precisar lidar com comandos que aceitem argumentos ou valores de devolução, você deve substituir essa função e trabalhar com os parâmetros *pvarargIn* e *pvarargOut* você mesmo.

## <a name="coleserverdoconframewindowactivate"></a><a name="onframewindowactivate"></a>COleServerDoc::OnFrameWindowActivate

A estrutura chama essa função quando a janela de quadro do aplicativo de contêiner é ativada ou desativada.

```
virtual void OnFrameWindowActivate(BOOL bActivate);
```

### <a name="parameters"></a>Parâmetros

*bAtivar*<br/>
Especifica se a janela do quadro deve ser ativada ou desativada.

### <a name="remarks"></a>Comentários

A implementação padrão cancela todos os modos de ajuda em que a janela do quadro possa estar. Anular esta função se você quiser realizar um processamento especial quando a janela do quadro estiver ativada ou desativada.

Para obter mais informações, consulte o artigo [Ativação](../../mfc/activation-cpp.md)..

## <a name="coleserverdocongetembeddeditem"></a><a name="ongetembeddeditem"></a>COleServerDoc::OnGetEmbeddedItem

Chamado pela estrutura quando um aplicativo de contêiner chama o aplicativo do servidor para criar ou editar um item incorporado.

```
virtual COleServerItem* OnGetEmbeddedItem() = 0;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um item representando todo o documento; NULO se a operação falhar.

### <a name="remarks"></a>Comentários

Não há implementação padrão. Você deve substituir esta função para retornar um item que representa todo o documento. Este valor de retorno deve `COleServerItem`ser um objeto de uma classe derivada.

## <a name="coleserverdoconreactivateandundo"></a><a name="onreactivateandundo"></a>COleServerDoc::OnReactivateAndUndo

O framework chama essa função quando o usuário opta por desfazer alterações feitas em um item que foi ativado no local, alterado e posteriormente desativado.

```
virtual BOOL OnReactivateAndUndo();
```

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão não faz nada além de retornar FALSO para indicar falha.

Anular essa função se o seu aplicativo suportar desfazer. Normalmente você executaria a operação de desfazer e, em seguida, ativaria o item ligando `ActivateInPlace`. Se o aplicativo de contêiner for escrito `COleClientItem::ReactivateAndUndo` com a Biblioteca de Classes da Microsoft Foundation, a chamada fará com que essa função seja chamada.

## <a name="coleserverdoconresizeborder"></a><a name="onresizeborder"></a>COleServerDoc::OnResizeBorder

A estrutura chama essa função quando as janelas do quadro do aplicativo de contêiner mudam de tamanho.

```
virtual void OnResizeBorder(
    LPCRECT lpRectBorder,
    LPOLEINPLACEUIWINDOW lpUIWindow,
    BOOL bFrame);
```

### <a name="parameters"></a>Parâmetros

*lpRectBorder*<br/>
Ponteiro para `RECT` uma `CRect` estrutura ou um objeto que especifica as coordenadas da borda.

*lpUIWindow*<br/>
Ponteiro para um `IOleInPlaceUIWindow` objeto de classe que possui a sessão de edição atual no local.

*bFrame*<br/>
TRUE se *lpUIWindow* aponta para a janela de quadro de nível superior do aplicativo de contêiner ou FALSE se *lpUIWindow* aponta para a janela de quadro de nível de documento do aplicativo de contêiner.

### <a name="remarks"></a>Comentários

Esta função redimensiona e ajusta barras de ferramentas e outros elementos de interface do usuário de acordo com o novo tamanho da janela.

Para obter mais informações, consulte [IOleInPlaceUIWindow](/windows/win32/api/oleidl/nn-oleidl-ioleinplaceuiwindow) no Windows SDK.

Este é um avançado super-rididável.

## <a name="coleserverdoconsethostnames"></a><a name="onsethostnames"></a>COleServerDoc::OnSetHostNames

Chamado pela estrutura quando o contêiner define ou altera os nomes de host para este documento.

```
virtual void OnSetHostNames(
    LPCTSTR lpszHost,
    LPCTSTR lpszHostObj);
```

### <a name="parameters"></a>Parâmetros

*lpszHost*<br/>
Ponteiro para uma seqüência que especifica o nome da aplicação do contêiner.

*lpszHostObj*<br/>
Pointer para uma seqüência que especifica o nome do contêiner para o documento.

### <a name="remarks"></a>Comentários

A implementação padrão altera o título do documento para todas as visualizações referentes a este documento.

Anular essa função se o aplicativo definir os títulos através de um mecanismo diferente.

## <a name="coleserverdoconsetitemrects"></a><a name="onsetitemrects"></a>COleServerDoc::OnSetItemRects

A estrutura chama essa função para posicionar a janela do quadro de edição no local dentro da janela de quadro do aplicativo de contêiner.

```
virtual void OnSetItemRects(
    LPCRECT lpPosRect,
    LPCRECT lpClipRect);
```

### <a name="parameters"></a>Parâmetros

*lpPosRect*<br/>
Ponteiro para `RECT` uma `CRect` estrutura ou um objeto que especifique a posição da janela do quadro no local em relação à área cliente do aplicativo de contêiner.

*lpClipRect*<br/>
Ponteiro para `RECT` uma `CRect` estrutura ou um objeto que especifica o retângulo de recorte da janela do quadro no local em relação à área cliente do aplicativo de contêiner.

### <a name="remarks"></a>Comentários

Anular esta função para atualizar o fator de zoom da visualização, se necessário.

Esta função geralmente é chamada `RequestPositionChange` em resposta a uma chamada, embora possa ser chamada a qualquer momento pelo contêiner para solicitar uma mudança de posição para o item no local.

## <a name="coleserverdoconshowcontrolbars"></a><a name="onshowcontrolbars"></a>COleServerDoc::OnShowControlBars

O framework chama essa função para mostrar ou ocultar as barras de controle do aplicativo do servidor associadas à janela de quadro identificada por *pFrameWnd*.

```
virtual void OnShowControlBars(
    CFrameWnd* pFrameWnd,
    BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*pFrameWnd*<br/>
Ponteiro para a janela do quadro cujas barras de controle devem ser ocultas ou mostradas.

*Bshow*<br/>
Determina se as barras de controle são mostradas ou ocultas.

### <a name="remarks"></a>Comentários

A implementação padrão enumera todas as barras de controle pertencentes a essa janela de quadro e esconde ou mostra.

## <a name="coleserverdoconshowdocument"></a><a name="onshowdocument"></a>COleServerDoc::OnShowDocument

A estrutura `OnShowDocument` chama a função quando o documento do servidor deve ser oculto ou mostrado.

```
virtual void OnShowDocument(BOOL bShow);
```

### <a name="parameters"></a>Parâmetros

*Bshow*<br/>
Especifica se a interface do usuário para o documento deve ser mostrada ou oculta.

### <a name="remarks"></a>Comentários

Se *bShow* for TRUE, a implementação padrão ativa o aplicativo do servidor, se necessário, e faz com que o aplicativo de contêiner role sua janela para que o item fique visível. Se *bShow* for FALSE, a implementação padrão desativa o item através de uma chamada para, `OnDeactivate`em seguida, destrói ou oculta todas as janelas de quadro que foram criadas para o documento, exceto a primeira. Se não permanecerem documentos visíveis, a implementação padrão ocultará o aplicativo do servidor.

## <a name="coleserverdoconupdatedocument"></a><a name="onupdatedocument"></a>COleServerDoc::OnUpdateDocument

Chamado pelo framework ao salvar um documento que é um item incorporado em um documento composto.

```
virtual BOOL OnUpdateDocument();
```

### <a name="return-value"></a>Valor retornado

Não zero se o documento foi atualizado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão chama o [COleServerDoc::NotificarSaved](#notifysaved) e [COleServerDoc::SaveEmserdding](#saveembedding) funções de membro e, em seguida, marca o documento como limpo. Anular esta função se você quiser realizar um processamento especial ao atualizar um item incorporado.

## <a name="coleserverdocrequestpositionchange"></a><a name="requestpositionchange"></a>COleServerDoc::RequestPositionChange

Chame esta função de membro para que o aplicativo de contêiner altere a posição do item.

```cpp
void RequestPositionChange(LPCRECT lpPosRect);
```

### <a name="parameters"></a>Parâmetros

*lpPosRect*<br/>
Ponteiro para `RECT` uma `CRect` estrutura ou um objeto contendo a nova posição do item.

### <a name="remarks"></a>Comentários

Esta função é geralmente chamada `UpdateAllItems`(em conjunto com ) quando os dados em um item ativo no local foram alterados. Após esta chamada, o contêiner pode ou `OnSetItemRects`não realizar a alteração ligando . A posição resultante pode ser diferente da solicitada.

## <a name="coleserverdocsaveembedding"></a><a name="saveembedding"></a>COleServerDoc::SaveEmbedding

Ligue para esta função para dizer ao aplicativo de contêiner para salvar o objeto incorporado.

```cpp
void SaveEmbedding();
```

### <a name="remarks"></a>Comentários

Esta função é chamada `OnUpdateDocument`automaticamente de . Observe que essa função faz com que o item seja atualizado no disco, por isso geralmente é chamado apenas como resultado de uma ação específica do usuário.

## <a name="coleserverdocscrollcontainerby"></a><a name="scrollcontainerby"></a>COleServerDoc::ScrollContainerBy

Chame `ScrollContainerBy` a função de membro para rolar o documento do `sizeScroll`contêiner pela quantidade, em pixels, indicada por .

```
BOOL ScrollContainerBy(CSize sizeScroll);
```

### <a name="parameters"></a>Parâmetros

*Sizescroll*<br/>
Indica até onde o documento do contêiner deve rolar.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Valores positivos indicam rolagem para baixo e para a direita; valores negativos indicam rolagem para cima e para a esquerda.

## <a name="coleserverdocupdateallitems"></a><a name="updateallitems"></a>COleServerDoc::UpdateAllItems

Ligue para esta função para notificar todos os itens vinculados conectados ao documento que o documento foi alterado.

```cpp
void UpdateAllItems(
    COleServerItem* pSender,
    LPARAM lHint = 0L,
    CObject* pHint = NULL,
    DVASPECT nDrawAspect = DVASPECT_CONTENT);
```

### <a name="parameters"></a>Parâmetros

*Psender*<br/>
Pointer para o item que modificou o documento, ou NULL se todos os itens forem atualizados.

*Lhint*<br/>
Contém informações sobre a modificação.

*Phint*<br/>
Ponteiro para um objeto armazenando informações sobre a modificação.

*Ndrawaspect*<br/>
Determina como o item deve ser desenhado. Este é um valor da enumeração DVASPECT. Esse parâmetro pode ter um dos seguintes valores:

- DVASPECT_CONTENT Item é representado de tal forma que pode ser exibido como um objeto incorporado dentro de seu recipiente.

- DVASPECT_THUMBNAIL Item é renderizado em uma representação "miniatura" para que possa ser exibido em uma ferramenta de navegação.

- DVASPECT_ICON Item é representado por um ícone.

- DVASPECT_DOCPRINT Item é representado como se fosse impresso usando o comando Imprimir no menu Arquivo.

### <a name="remarks"></a>Comentários

Você normalmente chama essa função depois que o usuário altera o documento do servidor. Se um item OLE estiver vinculado ao documento com um link automático, o item será atualizado para refletir as alterações. Em aplicativos de contêiner escritos com a Microsoft Foundation `COleClientItem` Class Library, a função de membro [OnChange](../../mfc/reference/coleclientitem-class.md#onchange) é chamada.

Esta função `OnUpdate` chama a função de membro para cada um dos itens do documento, exceto o item de envio, passando *pHint*, *lHint*e *nDrawAspect*. Use esses parâmetros para passar informações aos itens sobre as modificações feitas no documento. Você pode codificar informações usando *lHint* ou você pode definir uma `CObject`classe derivada para armazenar informações sobre as modificações e passar um objeto dessa classe usando *pHint*. Substituir a `OnUpdate` função de `COleServerItem`membro em sua classe derivada para otimizar a atualização de cada item, dependendo se sua apresentação foi alterada.

## <a name="see-also"></a>Confira também

[Amostra de MFC HIERSVR](../../overview/visual-cpp-samples.md)<br/>
[Classe COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDocument](../../mfc/reference/coledocument-class.md)<br/>
[Classe COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md)<br/>
[Classe COleTemplateServer](../../mfc/reference/coletemplateserver-class.md)
