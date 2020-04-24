---
title: Classe COleServerItem
ms.date: 11/04/2016
f1_keywords:
- COleServerItem
- AFXOLE/COleServerItem
- AFXOLE/COleServerItem::COleServerItem
- AFXOLE/COleServerItem::AddOtherClipboardData
- AFXOLE/COleServerItem::CopyToClipboard
- AFXOLE/COleServerItem::DoDragDrop
- AFXOLE/COleServerItem::GetClipboardData
- AFXOLE/COleServerItem::GetDocument
- AFXOLE/COleServerItem::GetEmbedSourceData
- AFXOLE/COleServerItem::GetItemName
- AFXOLE/COleServerItem::GetLinkSourceData
- AFXOLE/COleServerItem::GetObjectDescriptorData
- AFXOLE/COleServerItem::IsConnected
- AFXOLE/COleServerItem::IsLinkedItem
- AFXOLE/COleServerItem::NotifyChanged
- AFXOLE/COleServerItem::OnDoVerb
- AFXOLE/COleServerItem::OnDraw
- AFXOLE/COleServerItem::OnDrawEx
- AFXOLE/COleServerItem::OnGetClipboardData
- AFXOLE/COleServerItem::OnGetExtent
- AFXOLE/COleServerItem::OnInitFromData
- AFXOLE/COleServerItem::OnQueryUpdateItems
- AFXOLE/COleServerItem::OnRenderData
- AFXOLE/COleServerItem::OnRenderFileData
- AFXOLE/COleServerItem::OnRenderGlobalData
- AFXOLE/COleServerItem::OnSetColorScheme
- AFXOLE/COleServerItem::OnSetData
- AFXOLE/COleServerItem::OnSetExtent
- AFXOLE/COleServerItem::OnUpdate
- AFXOLE/COleServerItem::OnUpdateItems
- AFXOLE/COleServerItem::SetItemName
- AFXOLE/COleServerItem::GetDataSource
- AFXOLE/COleServerItem::OnHide
- AFXOLE/COleServerItem::OnOpen
- AFXOLE/COleServerItem::OnShow
- AFXOLE/COleServerItem::m_sizeExtent
helpviewer_keywords:
- COleServerItem [MFC], COleServerItem
- COleServerItem [MFC], AddOtherClipboardData
- COleServerItem [MFC], CopyToClipboard
- COleServerItem [MFC], DoDragDrop
- COleServerItem [MFC], GetClipboardData
- COleServerItem [MFC], GetDocument
- COleServerItem [MFC], GetEmbedSourceData
- COleServerItem [MFC], GetItemName
- COleServerItem [MFC], GetLinkSourceData
- COleServerItem [MFC], GetObjectDescriptorData
- COleServerItem [MFC], IsConnected
- COleServerItem [MFC], IsLinkedItem
- COleServerItem [MFC], NotifyChanged
- COleServerItem [MFC], OnDoVerb
- COleServerItem [MFC], OnDraw
- COleServerItem [MFC], OnDrawEx
- COleServerItem [MFC], OnGetClipboardData
- COleServerItem [MFC], OnGetExtent
- COleServerItem [MFC], OnInitFromData
- COleServerItem [MFC], OnQueryUpdateItems
- COleServerItem [MFC], OnRenderData
- COleServerItem [MFC], OnRenderFileData
- COleServerItem [MFC], OnRenderGlobalData
- COleServerItem [MFC], OnSetColorScheme
- COleServerItem [MFC], OnSetData
- COleServerItem [MFC], OnSetExtent
- COleServerItem [MFC], OnUpdate
- COleServerItem [MFC], OnUpdateItems
- COleServerItem [MFC], SetItemName
- COleServerItem [MFC], GetDataSource
- COleServerItem [MFC], OnHide
- COleServerItem [MFC], OnOpen
- COleServerItem [MFC], OnShow
- COleServerItem [MFC], m_sizeExtent
ms.assetid: 80256df6-3888-4256-944b-787d4b2e6b0d
ms.openlocfilehash: bdb91168a7c0ae718ca7d7514448b55965186aa8
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753748"
---
# <a name="coleserveritem-class"></a>Classe COleServerItem

Fornece a interface do servidor aos itens OLE.

## <a name="syntax"></a>Sintaxe

```
class COleServerItem : public CDocItem
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[COleServerItem::COleServerItem](#coleserveritem)|Constrói um objeto `COleServerItem`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleServerItem::AddOtherClipboardData](#addotherclipboarddata)|Coloca formatos de apresentação `COleDataSource` e conversão em um objeto.|
|[COleServerItem::CopyToClipboard](#copytoclipboard)|Copia o item para a área de transferência.|
|[COleServerItem::DoDragDrop](#dodragdrop)|Realiza uma operação de arrastar e soltar.|
|[COleServerItem::GetClipboardData](#getclipboarddata)|Obtém a fonte de dados para uso na transferência de dados (arrastar e soltar ou Prancheta).|
|[COleServerItem::GetDocument](#getdocument)|Retorna o documento do servidor que contém o item.|
|[COleServerItem::GetEmbedSourceData](#getembedsourcedata)|Obtém os dados CF_EMBEDSOURCE de um item OLE.|
|[COleServerItem::GetItemName](#getitemname)|Retorna o nome do item. Usado apenas para itens vinculados.|
|[COleServerItem::GetLinkSourceData](#getlinksourcedata)|Obtém os dados CF_LINKSOURCE de um item OLE.|
|[COleServerItem::GetObjectDescriptorData](#getobjectdescriptordata)|Obtém os dados CF_OBJECTDESCRIPTOR de um item OLE.|
|[COleServerItem::IsConnected](#isconnected)|Indica se o item está atualmente conectado a um recipiente ativo.|
|[COleServerItem::IsLinkedItem](#islinkeditem)|Indica se o item representa um item OLE vinculado.|
|[COleServerItem::NotificarAlterado](#notifychanged)|Atualiza todos os contêineres com atualização automática de link.|
|[COleServerItem::OnDoVerb](#ondoverb)|Chamado para executar um verbo.|
|[COleServerItem::OnDraw](#ondraw)|Chamado quando o contêiner solicita para desenhar o item; implementação necessária.|
|[COleServerItem::OnDrawEx](#ondrawex)|Pediu desenho de itens especializados.|
|[COleServerItem::OnGetClipboardData](#ongetclipboarddata)|Chamado pela estrutura para obter os dados que seriam copiados para a Área de Transferência.|
|[COleServerItem::OnGetExtent](#ongetextent)|Chamado pela estrutura para recuperar o tamanho do item OLE.|
|[COleServerItem::OnInitFromData](#oninitfromdata)|Chamado pela estrutura para inicializar um item OLE usando o conteúdo do objeto de transferência de dados especificado.|
|[COleServerItem::OnQueryUpdateItems](#onqueryupdateitems)|Chamado para determinar se algum item vinculado requer atualização.|
|[COleServerItem::OnRenderData](#onrenderdata)|Recupera dados como parte da renderização atrasada.|
|[COleServerItem::OnRenderFileData](#onrenderfiledata)|Recupera dados em `CFile` um objeto como parte da renderização atrasada.|
|[COleServerItem::OnRenderGlobalData](#onrenderglobaldata)|Recupera dados em um HGLOBAL como parte da renderização atrasada.|
|[COleServerItem::OnSetColorScheme](#onsetcolorscheme)|Chamado para definir o esquema de cores do item.|
|[COleServerItem::OnSetData](#onsetdata)|Chamado para definir os dados do item.|
|[COleServerItem::OnSetExtent](#onsetextent)|Chamado pela estrutura para definir o tamanho do item OLE.|
|[COleServerItem::OnUpdate](#onupdate)|Chamado quando parte do documento em que o item pertence é alterado.|
|[COleServerItem::OnUpdateItems](#onupdateitems)|Chamado para atualizar o cache de apresentação de todos os itens no documento do servidor.|
|[COleServerItem::SetItemName](#setitemname)|Define o nome do item. Usado apenas para itens vinculados.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[COleServerItem::GetDataSource](#getdatasource)|Obtém o objeto usado para armazenar formatos de conversão.|
|[COleServerItem::OnHide](#onhide)|Chamado pela estrutura para ocultar o item OLE.|
|[COleServerItem::OnOpen](#onopen)|Chamado pela estrutura para exibir o item OLE em sua própria janela de nível superior.|
|[COleServerItem::OnShow](#onshow)|Chamado quando o contêiner solicita para mostrar o item.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleServerItem::m_sizeExtent](#m_sizeextent)|Informa o servidor sobre quanto do item OLE está visível.|

## <a name="remarks"></a>Comentários

Um item vinculado pode representar alguns ou todos os documentos de um servidor. Um item incorporado sempre representa um documento inteiro do servidor.

A `COleServerItem` classe define várias funções de membros superignoráveis que são chamadas pelas Bibliotecas de link dinâmico (DLLs) do sistema OLE, geralmente em resposta às solicitações do aplicativo de contêiner. Essas funções de membro permitem que o aplicativo de contêiner manipule o item indiretamente de várias maneiras, como exibi-lo, executar seus verbos ou recuperar seus dados em vários formatos.

Para `COleServerItem`usar, obtenha uma classe a partir dele e implemente as funções de membro [OnDraw](#ondraw) e [Serialize.](../../mfc/reference/cobject-class.md#serialize) A `OnDraw` função fornece a representação de metaarquivo de um item, permitindo que ele seja exibido quando um aplicativo de contêiner abre um documento composto. A `Serialize` função `CObject` de fornecer a representação nativa de um item, permitindo que um item incorporado seja transferido entre os aplicativos de servidor e contêiner. [OnGetExtent](#ongetextent) fornece o tamanho natural do item para o recipiente, permitindo que o recipiente dimensione o item.

Para obter mais informações sobre servidores e tópicos relacionados, consulte o artigo [Servidores: Implementando um servidor](../../mfc/servers-implementing-a-server.md) e "Criando um Aplicativo de Contêiner/Servidor" no artigo [Containers: Recursos avançados](../../mfc/containers-advanced-features.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[Cdocitem](../../mfc/reference/cdocitem-class.md)

`COleServerItem`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

## <a name="coleserveritemaddotherclipboarddata"></a><a name="addotherclipboarddata"></a>COleServerItem::AddOtherClipboardData

Chame esta função para colocar os formatos de apresentação e `COleDataSource` conversão para o item OLE no objeto especificado.

```cpp
void AddOtherClipboardData(COleDataSource* pDataSource);
```

### <a name="parameters"></a>Parâmetros

*pDataSource*<br/>
Ponteiro para `COleDataSource` o objeto no qual os dados devem ser colocados.

### <a name="remarks"></a>Comentários

Você deve ter implementado a função de membro [OnDraw](#ondraw) para fornecer o formato de apresentação (uma imagem de metaarquivo) para o item. Para oferecer suporte a outros formatos de conversão, registre-os usando o objeto [COleDataSource](../../mfc/reference/coledatasource-class.md) retornado pelo [GetDataSource](#getdatasource) e alterne a função de membro [OnRenderData](#onrenderdata) para fornecer dados nos formatos que você deseja oferecer suporte.

## <a name="coleserveritemcoleserveritem"></a><a name="coleserveritem"></a>COleServerItem::COleServerItem

Constrói um `COleServerItem` objeto e o adiciona à coleção de itens de documento do documento do servidor.

```
COleServerItem(
    COleServerDoc* pServerDoc,
    BOOL bAutoDelete);
```

### <a name="parameters"></a>Parâmetros

*pServerDoc*<br/>
Pointer para o documento que conterá o novo item.

*bAutoDelete*<br/>
Sinalizar indicando se o objeto pode ser excluído quando um link para ele é liberado. Defina isso como `COleServerItem` FALSO se o objeto for parte integrante dos dados do documento que você deve excluir. Defina isso como TRUE se o objeto for uma estrutura secundária usada para identificar um intervalo nos dados do documento que pode ser excluído pela estrutura.

## <a name="coleserveritemcopytoclipboard"></a><a name="copytoclipboard"></a>COleServerItem::CopyToClipboard

Chame esta função para copiar o item OLE para a Área de Transferência.

```cpp
void CopyToClipboard(BOOL bIncludeLink = FALSE);
```

### <a name="parameters"></a>Parâmetros

*bIncludeLink*<br/>
Defina isso como TRUE se os dados do link forem copiados para a Área de Transferência. Defina isso como FALSO se o aplicativo do servidor não suportar links.

### <a name="remarks"></a>Comentários

A função usa a função [membro OnGetClipboardData](#ongetclipboarddata) para criar um objeto [COleDataSource](../../mfc/reference/coledatasource-class.md) contendo os dados do item OLE nos formatos suportados. Em seguida, a `COleDataSource` função coloca o objeto na área de transferência usando a função [COleDataSource::SetClipboard.](../../mfc/reference/coledatasource-class.md#setclipboard) O `COleDataSource` objeto inclui os dados nativos do item e sua representação em CF_METAFILEPICT formato, bem como dados em quaisquer formatos de conversão que você escolher para suportar. Você deve ter implementado [Serialize](../../mfc/reference/cobject-class.md#serialize) e [OnDraw](#ondraw) para que esta função de membro funcione.

## <a name="coleserveritemdodragdrop"></a><a name="dodragdrop"></a>COleServerItem::DoDragDrop

Ligue `DoDragDrop` para a função de membro para executar uma operação de arrastar e soltar.

```
DROPEFFECT DoDragDrop(
    LPCRECT lpRectItem,
    CPoint ptOffset,
    BOOL bIncludeLink = FALSE,
    DWORD dwEffects = DROPEFFECT_COPY | DROPEFFECT_MOVE,
    LPCRECT lpRectStartDrag = NULL);
```

### <a name="parameters"></a>Parâmetros

*lpRectItem*<br/>
O retângulo do item na tela, em pixels, em relação à área do cliente.

*ptOffset*<br/>
O deslocamento do *lpItemRect* onde a posição do mouse estava no momento do arrasto.

*bIncludeLink*<br/>
Defina isso como TRUE se os dados do link forem copiados para a Área de Transferência. Defina-o como FALSO se o aplicativo não tiver suporte a links.

*dwEffects*<br/>
Determina os efeitos que a fonte de arrastar permitirá na operação de arrastar (uma combinação de Copiar, Mover e Link).

*lpRectStartDrag*<br/>
Ponteiro para o retângulo que define onde o arrasto realmente começa. Para obter mais informações, consulte a seção Comentários a seguir.

### <a name="return-value"></a>Valor retornado

Um valor da enumeração DROPEFFECT. Se for em DROPEFFECT_MOVE, os dados originais devem ser removidos.

### <a name="remarks"></a>Comentários

A operação de arrastar e soltar não começa imediatamente. Ele espera até que o cursor do mouse deixe o retângulo especificado pelo *lpRectStartDrag* ou até que um número especificado de milissegundos tenha passado. Se *lpRectStartDrag* for NULL, um retângulo padrão será usado para que o arrasto seja iniciado quando o cursor do mouse mover um pixel.

O tempo de atraso é especificado por uma configuração de chave de registro. Você pode alterar o tempo de atraso ligando para [CWinApp::WriteProfileString](../../mfc/reference/cwinapp-class.md#writeprofilestring) ou [CWinApp::WriteProfileInt](../../mfc/reference/cwinapp-class.md#writeprofileint). Se você não especificar o tempo de atraso, um valor padrão de 200 milissegundos será usado. O tempo de atraso do arrasto é armazenado da seguinte forma:

- O tempo de atraso do Windows NT Drag é armazenado no HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\NT\CurrentVersion\IniFileMapping\win.ini\Windows\DragDelay.

- Windows 3.x O tempo de atraso de arrastar é armazenado no WIN. Arquivo INI, na seção [Windows}.

- Windows 95/98 O tempo de atraso do arrastar é armazenado em uma versão em cache do WIN. Ini.

Para obter mais informações sobre como as informações de atraso de arrasto são armazenadas no registro ou no . Arquivo INI, consulte [WriteProfileString](/windows/win32/api/winbase/nf-winbase-writeprofilestringw) no Windows SDK.

## <a name="coleserveritemgetclipboarddata"></a><a name="getclipboarddata"></a>COleServerItem::GetClipboardData

Chame esta função para preencher o objeto [COleDataSource](../../mfc/reference/coledatasource-class.md) especificado com todos os dados que seriam copiados para a Área de Transferência se você chamou [CopyToClipboard](#copytoclipboard) (os mesmos dados também seriam transferidos se você chamou [DoDragDrop](#dodragdrop)).

```cpp
void GetClipboardData(
    COleDataSource* pDataSource,
    BOOL bIncludeLink = FALSE,
    LPPOINT lpOffset = NULL,
    LPSIZE lpSize = NULL);
```

### <a name="parameters"></a>Parâmetros

*pDataSource*<br/>
Ponteiro para `COleDataSource` o objeto que receberá os dados do item OLE em todos os formatos suportados.

*bIncludeLink*<br/>
TRUE se os dados do link devem ser copiados para a Área de Transferência. FALSO se o aplicativo do servidor não suportar links.

*lpOffset*<br/>
O deslocamento, em pixels, do cursor do mouse da origem do objeto.

*lpTamanho*<br/>
O tamanho do objeto em pixels.

### <a name="remarks"></a>Comentários

Esta função chama a função [membro GetEmbedSourceData](#getembedsourcedata) para obter os dados nativos do item OLE e chama a função [membro AddOtherClipboardData](#addotherclipboarddata) para obter o formato de apresentação e quaisquer formatos de conversão suportados. Se *bIncludeLink* for TRUE, a função também chama [GetLinkSourceData](#getlinksourcedata) para obter os dados de link para o item.

Anular esta função se você quiser colocar `COleDataSource` formatos em um objeto `CopyToClipboard`antes ou depois desses formatos fornecidos por .

## <a name="coleserveritemgetdatasource"></a><a name="getdatasource"></a>COleServerItem::GetDataSource

Chame essa função para obter o objeto [COleDataSource](../../mfc/reference/coledatasource-class.md) usado para armazenar os formatos de conversão que o aplicativo de servidor suporta.

```
COleDataSource* GetDataSource();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro `COleDataSource` para o objeto usado para armazenar os formatos de conversão.

### <a name="remarks"></a>Comentários

Se você quiser que seu aplicativo de servidor ofereça dados em uma variedade `COleDataSource` de formatos durante operações de transferência de dados, registre esses formatos com o objeto retornado por esta função. Por exemplo, se você quiser fornecer uma representação CF_TEXT do item OLE para operações de `COleDataSource` área de transferência ou arrastar `OnRenderXxxData` e soltar, você registrará o formato com o objeto que essa função retorna e, em seguida, substituirá a função de membro para fornecer os dados.

## <a name="coleserveritemgetdocument"></a><a name="getdocument"></a>COleServerItem::GetDocument

Chame esta função para obter um ponteiro para o documento que contém o item.

```
COleServerDoc* GetDocument() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o documento que contém o item; NULO se o item não fizer parte de um documento.

### <a name="remarks"></a>Comentários

Isso permite o acesso ao documento do servidor `COleServerItem` que você passou como argumento para o construtor.

## <a name="coleserveritemgetembedsourcedata"></a><a name="getembedsourcedata"></a>COleServerItem::GetEmbedSourceData

Ligue para esta função para obter os dados CF_EMBEDSOURCE de um item OLE.

```cpp
void GetEmbedSourceData(LPSTGMEDIUM lpStgMedium);
```

### <a name="parameters"></a>Parâmetros

*Lpstgmedium*<br/>
Pointer para a estrutura [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) que receberá os dados CF_EMBEDSOURCE para o item OLE.

### <a name="remarks"></a>Comentários

Este formato inclui os dados nativos do item. Você deve ter `Serialize` implementado a função de membro para que esta função funcione corretamente.

O resultado pode então ser adicionado a uma fonte de dados usando [COleDataSource::CacheData](../../mfc/reference/coledatasource-class.md#cachedata). Esta função é chamada automaticamente por [COleServerItem::OnGetClipboardData](#ongetclipboarddata).

Para obter mais informações, consulte [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) no Windows SDK.

## <a name="coleserveritemgetitemname"></a><a name="getitemname"></a>COleServerItem::GetItemName

Ligue para esta função para obter o nome do item.

```
const CString& GetItemName() const;
```

### <a name="return-value"></a>Valor retornado

O nome do item.

### <a name="remarks"></a>Comentários

Você normalmente chama essa função apenas para itens vinculados.

## <a name="coleserveritemgetlinksourcedata"></a><a name="getlinksourcedata"></a>COleServerItem::GetLinkSourceData

Ligue para esta função para obter os dados CF_LINKSOURCE de um item OLE.

```
BOOL GetLinkSourceData(LPSTGMEDIUM lpStgMedium);
```

### <a name="parameters"></a>Parâmetros

*Lpstgmedium*<br/>
Pointer para a estrutura [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) que receberá os dados CF_LINKSOURCE para o item OLE.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Este formato inclui o CLSID descrevendo o tipo do item OLE e as informações necessárias para localizar o documento que contém o item OLE.

O resultado pode então ser adicionado a uma fonte de dados com [COleDataSource::CacheData](../../mfc/reference/coledatasource-class.md#cachedata). Esta função é chamada automaticamente pelo [OnGetClipboardData](#ongetclipboarddata).

Para obter mais informações, consulte [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) no Windows SDK.

## <a name="coleserveritemgetobjectdescriptordata"></a><a name="getobjectdescriptordata"></a>COleServerItem::GetObjectDescriptorData

Ligue para esta função para obter os dados CF_OBJECTDESCRIPTOR de um item OLE.

```cpp
void GetObjectDescriptorData(
    LPPOINT lpOffset,
    LPSIZE lpSize,
    LPSTGMEDIUM lpStgMedium);
```

### <a name="parameters"></a>Parâmetros

*lpOffset*<br/>
Deslocamento do mouse clique no canto superior esquerdo do item OLE. Pode ser NULL.

*lpTamanho*<br/>
Tamanho do item OLE. Pode ser NULL.

*Lpstgmedium*<br/>
Pointer para a estrutura [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) que receberá os dados CF_OBJECTDESCRIPTOR para o item OLE.

### <a name="remarks"></a>Comentários

As informações são copiadas para a `STGMEDIUM` estrutura apontada pelo *lpStgMedium*. Este formato inclui as informações necessárias para a caixa de diálogo Colar especial.

Para obter mais informações, consulte [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) no Windows SDK.

## <a name="coleserveritemisconnected"></a><a name="isconnected"></a>COleServerItem::IsConnected

Ligue para esta função para ver se o item OLE está conectado.

```
BOOL IsConnected() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o item estiver conectado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um item OLE é considerado conectado se um ou mais contêineres tiverem referências ao item. Um item é conectado se sua contagem de referência for maior que 0 ou se for um item incorporado.

## <a name="coleserveritemislinkeditem"></a><a name="islinkeditem"></a>COleServerItem::IsLinkedItem

Ligue para esta função para ver se o item OLE é um item vinculado.

```
BOOL IsLinkedItem() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o item for um item vinculado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um item é vinculado se o item for válido e não for devolvido na lista de itens incorporados do documento. Um item vinculado pode ou não estar conectado a um contêiner.

É comum usar a mesma classe para itens ligados e incorporados. `IsLinkedItem`permite que você faça com que itens vinculados se comportem de forma diferente dos itens incorporados, embora muitas vezes o código seja comum.

## <a name="coleserveritemm_sizeextent"></a><a name="m_sizeextent"></a>COleServerItem::m_sizeExtent

Este membro informa ao servidor quanto do objeto está visível no documento do contêiner.

```
CSize m_sizeExtent;
```

### <a name="remarks"></a>Comentários

A implementação padrão do [OnSetExtent](#onsetextent) define esse membro.

## <a name="coleserveritemnotifychanged"></a><a name="notifychanged"></a>COleServerItem::NotificarAlterado

Chame esta função depois que o item vinculado for alterado.

```cpp
void NotifyChanged(DVASPECT nDrawAspect = DVASPECT_CONTENT);
```

### <a name="parameters"></a>Parâmetros

*Ndrawaspect*<br/>
Um valor da enumeração DVASPECT que indica qual aspecto do item OLE foi alterado. Esse parâmetro pode ter qualquer um dos seguintes valores:

- DVASPECT_CONTENT Item é representado de tal forma que pode ser exibido como um objeto incorporado dentro de seu recipiente.

- DVASPECT_THUMBNAIL Item é renderizado em uma representação "miniatura" para que possa ser exibido em uma ferramenta de navegação.

- DVASPECT_ICON Item é representado por um ícone.

- DVASPECT_DOCPRINT Item é representado como se fosse impresso usando o comando Imprimir no menu Arquivo.

### <a name="remarks"></a>Comentários

Se um item de contêiner estiver vinculado ao documento com um link automático, o item será atualizado para refletir as alterações. Em aplicativos de contêiner gravados usando a Biblioteca de Classes da Microsoft Foundation, [COleClientItem::OnChange](../../mfc/reference/coleclientitem-class.md#onchange) é chamado em resposta.

## <a name="coleserveritemondoverb"></a><a name="ondoverb"></a>COleServerItem::OnDoVerb

Chamado pela estrutura para executar o verbo especificado.

```
virtual void OnDoVerb(LONG iVerb);
```

### <a name="parameters"></a>Parâmetros

*Iverb*<br/>
Especifica o verbo a ser executado. Pode ser qualquer um dos seguintes:

|Valor|Significado|Símbolo|
|-----------|-------------|------------|
|0|Verbo primário|OLEIVERB_PRIMARY|
|1|Verbo secundário|(Nenhuma)|
|- 1|Display item para edição|Oleiverb_show|
|- 2|Editar item em janela separada|OLEIVERB_OPEN|
|- 3|Ocultar item|OLEIVERB_HIDE|

O valor -1 é tipicamente um pseudônimo para outro verbo. Se a edição aberta não for suportada, -2 tem o mesmo efeito que -1. Para obter valores adicionais, consulte [IOleObject::DoVerb](/windows/win32/api/oleidl/nf-oleidl-ioleobject-doverb) no Windows SDK.

### <a name="remarks"></a>Comentários

Se o aplicativo de contêiner foi gravado com a Biblioteca de Classes da Microsoft Foundation, essa `COleClientItem` função será chamada quando o [COleClientItem::Ativar](../../mfc/reference/coleclientitem-class.md#activate) a função de membro do objeto correspondente é chamado. A implementação padrão chama a função de membro [onShow](#onshow) se o verbo principal ou OLEIVERB_SHOW for especificado, [OnOpen](#onopen) se o verbo secundário ou OLEIVERB_OPEN for especificado e [onOcultase](#onhide) OLEIVERB_HIDE for especificado. A implementação `OnShow` padrão é chamada se *iVerb* não for um dos verbos listados acima.

Anular esta função se o verbo principal não mostrar o item. Por exemplo, se o item for uma gravação de som e seu verbo principal for Reprodução, você não terá que exibir o aplicativo do servidor para reproduzir o item.

Para obter mais informações, consulte [IOleObject::DoVerb](/windows/win32/api/oleidl/nf-oleidl-ioleobject-doverb) no Windows SDK.

## <a name="coleserveritemondraw"></a><a name="ondraw"></a>COleServerItem::OnDraw

Chamado pela estrutura para transformar o item OLE em um metaarquivo.

```
virtual BOOL OnDraw(
    CDC* pDC,
    CSize& rSize) = 0;
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Um ponteiro para o objeto [CDC](../../mfc/reference/cdc-class.md) sobre o qual desenhar o item. O contexto de exibição está automaticamente conectado ao contexto de exibição de atributos para que você possa chamar funções de atributo, embora isso torne o dispositivo de metaarquivo específico.

*rTamanho*<br/>
Tamanho, em unidades HIMETRIC, para desenhar o metaarquivo.

### <a name="return-value"></a>Valor retornado

Não zero se o item foi sorteado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

A representação de metaarquivo do item OLE é usada para exibir o item no aplicativo do contêiner. Se o aplicativo de contêiner foi escrito com a Biblioteca de Classes da Microsoft Foundation, o metaarquivo será usado pela função [Draw](../../mfc/reference/coleclientitem-class.md#draw) member do objeto [COleClientItem](../../mfc/reference/coleclientitem-class.md) correspondente. Não há implementação padrão. Você deve substituir esta função para desenhar o item no contexto do dispositivo especificado.

## <a name="coleserveritemondrawex"></a><a name="ondrawex"></a>COleServerItem::OnDrawEx

Chamado pela estrutura para todos os desenhos.

```
virtual BOOL OnDrawEx(
    CDC* pDC,
    DVASPECT nDrawAspect,
    CSize& rSize);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Um ponteiro para o objeto [CDC](../../mfc/reference/cdc-class.md) sobre o qual desenhar o item. O DC está automaticamente conectado ao atributo DC para que você possa chamar funções de atributo, embora isso torne o dispositivo de metaarquivo específico.

*Ndrawaspect*<br/>
Um valor da enumeração DVASPECT. Esse parâmetro pode ter qualquer um dos seguintes valores:

- DVASPECT_CONTENT Item é representado de tal forma que pode ser exibido como um objeto incorporado dentro de seu recipiente.

- DVASPECT_THUMBNAIL Item é renderizado em uma representação "miniatura" para que possa ser exibido em uma ferramenta de navegação.

- DVASPECT_ICON Item é representado por um ícone.

- DVASPECT_DOCPRINT Item é representado como se fosse impresso usando o comando Imprimir no menu Arquivo.

*rTamanho*<br/>
Tamanho do item em unidades HIMETRIC.

### <a name="return-value"></a>Valor retornado

Não zero se o item foi sorteado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação `OnDraw` padrão é chamada quando o DVASPECT é igual a DVASPECT_CONTENT; caso contrário, ele falha.

Substituir essa função para fornecer dados de apresentação para outros aspectos que não DVASPECT_CONTENT, como DVASPECT_ICON ou DVASPECT_THUMBNAIL.

## <a name="coleserveritemongetclipboarddata"></a><a name="ongetclipboarddata"></a>COleServerItem::OnGetClipboardData

Chamado pela estrutura para `COleDataSource` obter um objeto contendo todos os dados que seriam colocados na Área de Transferência por uma chamada para a função de membro [CopyToClipboard.](#copytoclipboard)

```
virtual COleDataSource* OnGetClipboardData(
    BOOL bIncludeLink,
    LPPOINT lpOffset,
    LPSIZE lpSize);
```

### <a name="parameters"></a>Parâmetros

*bIncludeLink*<br/>
Defina isso como TRUE se os dados do link forem copiados para a Área de Transferência. Defina isso como FALSO se o aplicativo do servidor não suportar links.

*lpOffset*<br/>
O deslocamento do cursor do mouse da origem do objeto em pixels.

*lpTamanho*<br/>
O tamanho do objeto em pixels.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [COleDataSource](../../mfc/reference/coledatasource-class.md) contendo os dados da Área de Transferência.

### <a name="remarks"></a>Comentários

A implementação padrão desta função chama [GetClipboardData](#getclipboarddata).

## <a name="coleserveritemongetextent"></a><a name="ongetextent"></a>COleServerItem::OnGetExtent

Chamado pela estrutura para recuperar o tamanho, em unidades HIMETRIC, do item OLE.

```
virtual BOOL OnGetExtent(
    DVASPECT nDrawAspect,
    CSize& rSize);
```

### <a name="parameters"></a>Parâmetros

*Ndrawaspect*<br/>
Especifica o aspecto do item OLE cujos limites devem ser recuperados. Esse parâmetro pode ter qualquer um dos seguintes valores:

- DVASPECT_CONTENT Item é representado de tal forma que pode ser exibido como um objeto incorporado dentro de seu recipiente.

- DVASPECT_THUMBNAIL Item é renderizado em uma representação "miniatura" para que possa ser exibido em uma ferramenta de navegação.

- DVASPECT_ICON Item é representado por um ícone.

- DVASPECT_DOCPRINT Item é representado como se fosse impresso usando o comando Imprimir no menu Arquivo.

*rTamanho*<br/>
Faça referência `CSize` a um objeto que receberá o tamanho do item OLE.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o aplicativo de contêiner foi escrito com a Biblioteca de Classes da `COleClientItem` Microsoft Foundation, essa função será chamada quando a função de membro [GetExtent](../../mfc/reference/coleclientitem-class.md#getextent) do objeto correspondente for chamada. A implementação padrão não faz nada. Você mesmo deve implementá-lo. Anular esta função se você quiser realizar um processamento especial ao lidar com uma solicitação para o tamanho do item OLE.

## <a name="coleserveritemonhide"></a><a name="onhide"></a>COleServerItem::OnHide

Chamado pela estrutura para ocultar o item OLE.

```
virtual void OnHide();
```

### <a name="remarks"></a>Comentários

As chamadas `COleServerDoc::OnShowDocument( FALSE )`padrão . A função também notifica o recipiente de que o item OLE foi escondido. Anular esta função se você quiser realizar um processamento especial ao ocultar um item OLE.

## <a name="coleserveritemoninitfromdata"></a><a name="oninitfromdata"></a>COleServerItem::OnInitFromData

Chamado pela estrutura para inicializar um item OLE usando o conteúdo do *pDataObject*.

```
virtual BOOL OnInitFromData(
    COleDataObject* pDataObject,
    BOOL bCreation);
```

### <a name="parameters"></a>Parâmetros

*Pdataobject*<br/>
Ponteiro para um objeto de dados OLE contendo dados em vários formatos para inicializar o item OLE.

*bCriação*<br/>
TRUE se a função for chamada para inicializar um item OLE sendo recém-criado por um aplicativo de contêiner. FALSO se a função for chamada para substituir o conteúdo de um item OLE já existente.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se *bCriação* for TRUE, essa função será chamada se um contêiner implementar Inserir novo objeto com base na seleção atual. Os dados selecionados são usados ao criar o novo item OLE. Por exemplo, ao selecionar uma gama de células em um programa de planilha e, em seguida, usar o Inserir novo objeto para criar um gráfico com base nos valores no intervalo selecionado. A implementação padrão não faz nada. Substituir esta função para escolher um formato aceitável daqueles oferecidos pelo *pDataObject* e inicializar o item OLE com base nos dados fornecidos. Este é um avançado super-rididável.

Para obter mais informações, consulte [IOleObject::InitFromData](/windows/win32/api/oleidl/nf-oleidl-ioleobject-initfromdata) no Windows SDK.

## <a name="coleserveritemonopen"></a><a name="onopen"></a>COleServerItem::OnOpen

Chamado pela estrutura para exibir o item OLE em uma instância separada do aplicativo do servidor, em vez de no lugar.

```
virtual void OnOpen();
```

### <a name="remarks"></a>Comentários

A implementação padrão ativa a primeira janela de quadro exibindo o documento que contém o item OLE; se o aplicativo for um mini-servidor, a implementação padrão mostrará a janela principal. A função também notifica o recipiente de que o item OLE foi aberto.

Anular esta função se você quiser realizar um processamento especial ao abrir um item OLE. Isso é especialmente comum com itens vinculados onde você deseja definir a seleção para o link quando ele é aberto.

Para obter mais informações, consulte [IOleClientSite::OnShowWindow](/windows/win32/api/oleidl/nf-oleidl-ioleclientsite-onshowwindow) no Windows SDK.

## <a name="coleserveritemonqueryupdateitems"></a><a name="onqueryupdateitems"></a>COleServerItem::OnQueryUpdateItems

Chamado pelo framework para determinar se algum item vinculado no documento atual do servidor está desatualizado.

```
virtual BOOL OnQueryUpdateItems();
```

### <a name="return-value"></a>Valor retornado

Não zero se o documento tiver itens que precisam de atualizações; 0 se todos os itens estiverem atualizados.

### <a name="remarks"></a>Comentários

Um item está desatualizado se seu documento de origem foi alterado, mas o item vinculado não foi atualizado para refletir as alterações no documento.

## <a name="coleserveritemonrenderdata"></a><a name="onrenderdata"></a>COleServerItem::OnRenderData

Chamado pela estrutura para recuperar dados no formato especificado.

```
virtual BOOL OnRenderData(
    LPFORMATETC lpFormatEtc,
    LPSTGMEDIUM lpStgMedium);
```

### <a name="parameters"></a>Parâmetros

*Lpformatetc*<br/>
Aponta para a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) especificando o formato no qual as informações são solicitadas.

*Lpstgmedium*<br/>
Aponta para uma estrutura [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) na qual os dados devem ser devolvidos.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O formato especificado é um `COleDataSource` anteriormente colocado no objeto usando a função de membro [DelayRenderData](../../mfc/reference/coledatasource-class.md#delayrenderdata) ou [DelayRenderFileData](../../mfc/reference/coledatasource-class.md#delayrenderfiledata) para renderização atrasada. A implementação padrão desta função chama [OnRenderFileData](#onrenderfiledata) ou [OnRenderGlobalData,](#onrenderglobaldata)respectivamente, se o meio de armazenamento fornecido for um arquivo ou memória. Se nenhum desses formatos for fornecido, a implementação padrão retorna 0 e não faz nada.

Se o*tmed* *lpStgMedium*-> for TYMED_NULL, o STGMEDIUM deverá ser alocado e preenchido conforme especificado pelo *lpFormatEtc->tymed*. Se não TYMED_NULL, o STGMEDIUM deve ser preenchido no lugar com os dados.

Este é um avançado super-rididável. Anular esta função para fornecer seus dados no formato e meio solicitados. Dependendo dos seus dados, você pode querer substituir uma das outras versões desta função. Se seus dados forem pequenos e `OnRenderGlobalData`fixos em tamanho, anular . Se seus dados estão em um arquivo, ou `OnRenderFileData`são de tamanho variável, sobreposição .

Para obter mais informações, consulte [IDataObject::GetData](/windows/win32/api/objidl/nf-objidl-idataobject-getdata), [STGMEDIUM,](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc)e [TYMED](/windows/win32/api/objidl/ne-objidl-tymed) no Windows SDK.

## <a name="coleserveritemonrenderfiledata"></a><a name="onrenderfiledata"></a>COleServerItem::OnRenderFileData

Chamado pela estrutura para recuperar dados no formato especificado quando o meio de armazenamento é um arquivo.

```
virtual BOOL OnRenderFileData(
    LPFORMATETC lpFormatEtc,
    CFile* pFile);
```

### <a name="parameters"></a>Parâmetros

*Lpformatetc*<br/>
Aponta para a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) especificando o formato no qual as informações são solicitadas.

*Pfile*<br/>
Aponta para `CFile` um objeto no qual os dados devem ser renderizados.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O formato especificado é aquele `COleDataSource` anteriormente colocado no objeto usando a função [membro DelayRenderData](../../mfc/reference/coledatasource-class.md#delayrenderdata) para renderização atrasada. A implementação padrão desta função simplesmente retorna FALSE.

Este é um avançado super-rididável. Anular esta função para fornecer seus dados no formato e meio solicitados. Dependendo dos seus dados, você pode querer substituir uma das outras versões desta função. Se você quiser lidar com vários meios de armazenamento, anule [o OnRenderData](#onrenderdata). Se seus dados estão em um arquivo ou são de tamanho variável, anular [OnRenderFileData](#onrenderfiledata).

Para obter mais informações, consulte [IDataObject::GetData](/windows/win32/api/objidl/nf-objidl-idataobject-getdata) e [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no Windows SDK.

## <a name="coleserveritemonrenderglobaldata"></a><a name="onrenderglobaldata"></a>COleServerItem::OnRenderGlobalData

Chamado pela estrutura para recuperar dados no formato especificado quando o meio de armazenamento especificado é memória global.

```
virtual BOOL OnRenderGlobalData(
    LPFORMATETC lpFormatEtc,
    HGLOBAL* phGlobal);
```

### <a name="parameters"></a>Parâmetros

*Lpformatetc*<br/>
Aponta para a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) especificando o formato no qual as informações são solicitadas.

*Phglobal*<br/>
Aponta para uma alça para a memória global na qual os dados devem ser devolvidos. Se nenhuma memória foi alocada, este parâmetro pode ser NULO.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O formato especificado é aquele `COleDataSource` anteriormente colocado no objeto usando a função [membro DelayRenderData](../../mfc/reference/coledatasource-class.md#delayrenderdata) para renderização atrasada. A implementação padrão desta função simplesmente retorna FALSE.

Se *phGlobal* for NULL, então um novo HGLOBAL deve ser alocado e devolvido em *phGlobal*. Caso contrário, o HGLOBAL especificado pela *phGlobal* deve ser preenchido com os dados. A quantidade de dados colocados no HGLOBAL não deve exceder o tamanho atual do bloco de memória. Além disso, o bloco não pode ser realocado para um tamanho maior.

Este é um avançado super-rididável. Anular esta função para fornecer seus dados no formato e meio solicitados. Dependendo dos seus dados, você pode querer substituir uma das outras versões desta função. Se você quiser lidar com vários meios de armazenamento, anule [o OnRenderData](#onrenderdata). Se seus dados estão em um arquivo ou são de tamanho variável, anular [OnRenderFileData](#onrenderfiledata).

Para obter mais informações, consulte [IDataObject::GetData](/windows/win32/api/objidl/nf-objidl-idataobject-getdata) e [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no Windows SDK.

## <a name="coleserveritemonsetcolorscheme"></a><a name="onsetcolorscheme"></a>COleServerItem::OnSetColorScheme

Chamado pela estrutura para especificar uma paleta de cores a ser usada ao editar o item OLE.

```
virtual BOOL OnSetColorScheme(const LOGPALETTE* lpLogPalette);
```

### <a name="parameters"></a>Parâmetros

*paleta de p.p.P.P.P*<br/>
Ponteiro para uma estrutura [logpalette do](/windows/win32/api/wingdi/ns-wingdi-logpalette) Windows.

### <a name="return-value"></a>Valor retornado

Não zero se a paleta de cores for usada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o aplicativo de contêiner foi gravado usando a Biblioteca de Classes da Microsoft Foundation, essa `COleClientItem` função será chamada quando a função [IOleObject::SetColorScheme](/windows/win32/api/oleidl/nf-oleidl-ioleobject-setcolorscheme) do objeto correspondente é chamada. A implementação padrão retorna FALSE. Anular esta função se quiser usar a paleta recomendada. O aplicativo do servidor não é necessário para usar a paleta sugerida.

Para obter mais informações, consulte [IOleObject::SetColorScheme](/windows/win32/api/oleidl/nf-oleidl-ioleobject-setcolorscheme) no Windows SDK.

## <a name="coleserveritemonsetdata"></a><a name="onsetdata"></a>COleServerItem::OnSetData

Chamado pela estrutura para substituir os dados do item OLE pelos dados especificados.

```
virtual BOOL OnSetData(
    LPFORMATETC lpFormatEtc,
    LPSTGMEDIUM lpStgMedium,
    BOOL bRelease);
```

### <a name="parameters"></a>Parâmetros

*Lpformatetc*<br/>
Pointer para uma estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) especificando o formato dos dados.

*Lpstgmedium*<br/>
Ponteiro para uma estrutura [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) na qual os dados residem.

*Brelease*<br/>
Indica quem possui a propriedade do meio de armazenamento após concluir a chamada de função. O chamador decide quem é responsável pela liberação dos recursos alocados em nome do meio de armazenamento. O chamador faz isso definindo *bRelease*. Se *bRelease* não for zero, o item do servidor assumirá a propriedade, liberando o meio quando ele tiver terminado de usá-lo. Quando *bRelease* é 0, o chamador mantém a propriedade e o item do servidor pode usar o meio de armazenamento apenas durante a duração da chamada.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O item do servidor não se apropria dos dados até que ele os tenha obtido com sucesso. Ou seja, ele não toma posse se retornar 0. Se a fonte de dados tomar posse, ela libera o meio de armazenamento chamando a função [ReleaseStgMedium.](/windows/win32/api/ole2/nf-ole2-releasestgmedium)

A implementação padrão não faz nada. Substitua esta função para substituir os dados do item OLE pelos dados especificados. Este é um avançado super-rididável.

Para obter mais informações, consulte [STGMEDIUM,](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc)e [ReleaseStgMedium](/windows/win32/api/ole2/nf-ole2-releasestgmedium) no Windows SDK.

## <a name="coleserveritemonsetextent"></a><a name="onsetextent"></a>COleServerItem::OnSetExtent

Chamado pela estrutura para dizer ao item OLE quanto espaço está disponível para ele no documento do contêiner.

```
virtual BOOL OnSetExtent(
    DVASPECT nDrawAspect,
    const CSize& size);
```

### <a name="parameters"></a>Parâmetros

*Ndrawaspect*<br/>
Especifica o aspecto do item OLE cujos limites estão sendo especificados. Esse parâmetro pode ter qualquer um dos seguintes valores:

- DVASPECT_CONTENT Item é representado de tal forma que pode ser exibido como um objeto incorporado dentro de seu recipiente.

- DVASPECT_THUMBNAIL Item é renderizado em uma representação "miniatura" para que possa ser exibido em uma ferramenta de navegação.

- DVASPECT_ICON Item é representado por um ícone.

- DVASPECT_DOCPRINT Item é representado como se fosse impresso usando o comando Imprimir no menu Arquivo.

*size*<br/>
Uma estrutura [CSize](../../atl-mfc-shared/reference/csize-class.md) especificando o novo tamanho do item OLE.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o aplicativo de contêiner foi escrito com a Biblioteca de Classes da `COleClientItem` Microsoft Foundation, essa função será chamada quando a função de membro [SetExtent](../../mfc/reference/coleclientitem-class.md#setextent) do objeto correspondente for chamada. A implementação padrão define o [membro m_sizeExtent](#m_sizeextent) para o tamanho especificado se *nDrawAspect* estiver DVASPECT_CONTENT; caso contrário, ele retorna 0. Anular esta função para realizar um processamento especial quando você alterar o tamanho do item.

## <a name="coleserveritemonshow"></a><a name="onshow"></a>COleServerItem::OnShow

Chamado pela estrutura para instruir o aplicativo do servidor a exibir o item OLE no lugar.

```
virtual void OnShow();
```

### <a name="remarks"></a>Comentários

Essa função é normalmente chamada quando o usuário do aplicativo de contêiner cria um item ou executa um verbo, como Editar, que requer que o item seja mostrado. A implementação padrão tenta a ativação no local. Se isso falhar, a `OnOpen` função chamará a função de membro para exibir o item OLE em uma janela separada.

Anular esta função se você quiser realizar um processamento especial quando um item OLE é mostrado.

## <a name="coleserveritemonupdate"></a><a name="onupdate"></a>COleServerItem::OnUpdate

Chamado pela estrutura quando um item foi modificado.

```
virtual void OnUpdate(
    COleServerItem* pSender,
    LPARAM lHint,
    CObject* pHint,
    DVASPECT nDrawAspect);
```

### <a name="parameters"></a>Parâmetros

*Psender*<br/>
Pointer para o item que modificou o documento. Pode ser NULL.

*Lhint*<br/>
Contém informações sobre a modificação.

*Phint*<br/>
Ponteiro para um objeto armazenando informações sobre a modificação.

*Ndrawaspect*<br/>
Um valor da enumeração DVASPECT. Este parâmetro pode ter qualquer um dos seguintes valores:

- DVASPECT_CONTENT Item é representado de tal forma que pode ser exibido como um objeto incorporado dentro de seu recipiente.

- DVASPECT_THUMBNAIL Item é renderizado em uma representação "miniatura" para que possa ser exibido em uma ferramenta de navegação.

- DVASPECT_ICON Item é representado por um ícone.

- DVASPECT_DOCPRINT Item é representado como se fosse impresso usando o comando Imprimir no menu Arquivo.

### <a name="remarks"></a>Comentários

A implementação padrão chama [NotifyChanged,](#notifychanged)independentemente da dica ou do remetente.

## <a name="coleserveritemonupdateitems"></a><a name="onupdateitems"></a>COleServerItem::OnUpdateItems

Chamado pelo framework para atualizar todos os itens no documento do servidor.

```
virtual void OnUpdateItems();
```

### <a name="remarks"></a>Comentários

A implementação padrão chama `COleClientItem` [UpdateLink](../../mfc/reference/coleclientitem-class.md#updatelink) para todos os objetos no documento.

## <a name="coleserveritemsetitemname"></a><a name="setitemname"></a>COleServerItem::SetItemName

Chame esta função quando criar um item vinculado para definir seu nome.

```cpp
void SetItemName(LPCTSTR lpszItemName);
```

### <a name="parameters"></a>Parâmetros

*lpszItemName*<br/>
Pointer para o novo nome do item.

### <a name="remarks"></a>Comentários

O nome deve ser único dentro do documento. Quando um aplicativo de servidor é chamado para editar um item vinculado, o aplicativo usa esse nome para encontrar o item. Você não precisa chamar esta função para itens incorporados.

## <a name="see-also"></a>Confira também

[Amostra de MFC HIERSVR](../../overview/visual-cpp-samples.md)<br/>
[Classe CDocItem](../../mfc/reference/cdocitem-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)<br/>
[Classe COleServerDoc](../../mfc/reference/coleserverdoc-class.md)<br/>
[Classe COleTemplateServer](../../mfc/reference/coletemplateserver-class.md)
