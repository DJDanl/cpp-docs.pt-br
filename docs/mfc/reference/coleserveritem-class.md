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
ms.openlocfilehash: dcae304e8571ecb5743002638ea23f13c3e21517
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78884099"
---
# <a name="coleserveritem-class"></a>Classe COleServerItem

Fornece a interface de servidor para itens OLE.

## <a name="syntax"></a>Sintaxe

```
class COleServerItem : public CDocItem
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COleServerItem:: COleServerItem](#coleserveritem)|Constrói um objeto `COleServerItem`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COleServerItem:: AddOtherClipboardData](#addotherclipboarddata)|Coloca os formatos de conversão e de apresentação em um objeto `COleDataSource`.|
|[COleServerItem:: CopyToClipboard](#copytoclipboard)|Copia o item para a área de transferência.|
|[COleServerItem::D oDragDrop](#dodragdrop)|Executa uma operação de arrastar e soltar.|
|[COleServerItem:: GetClipboardData](#getclipboarddata)|Obtém a fonte de dados para uso na transferência de dados (arrastar e soltar ou área de transferência).|
|[COleServerItem:: GetDocument](#getdocument)|Retorna o documento do servidor que contém o item.|
|[COleServerItem:: GetEmbedSourceData](#getembedsourcedata)|Obtém os dados de CF_EMBEDSOURCE de um item OLE.|
|[COleServerItem:: getItemName](#getitemname)|Retorna o nome do item. Usado somente para itens vinculados.|
|[COleServerItem:: GetLinkSourceData](#getlinksourcedata)|Obtém os dados de CF_LINKSOURCE de um item OLE.|
|[COleServerItem:: GetObjectDescriptorData](#getobjectdescriptordata)|Obtém os dados de CF_OBJECTDESCRIPTOR de um item OLE.|
|[COleServerItem:: IsConnected](#isconnected)|Indica se o item está anexado no momento a um contêiner ativo.|
|[COleServerItem:: IsLinkedItem](#islinkeditem)|Indica se o item representa um item OLE vinculado.|
|[COleServerItem:: NotifyChanged](#notifychanged)|Atualiza todos os contêineres com atualização automática de link.|
|[COleServerItem:: OnDoVerb](#ondoverb)|Chamado para executar um verbo.|
|[COleServerItem:: OnDraw](#ondraw)|Chamado quando o contêiner solicita o desenho do item; implementação necessária.|
|[COleServerItem:: OnDrawEx](#ondrawex)|Chamado para desenho de item especializado.|
|[COleServerItem:: OnGetClipboardData](#ongetclipboarddata)|Chamado pelo Framework para obter os dados que seriam copiados para a área de transferência.|
|[COleServerItem:: OnGetExtent](#ongetextent)|Chamado pelo Framework para recuperar o tamanho do item OLE.|
|[COleServerItem:: OnInitFromData](#oninitfromdata)|Chamado pelo Framework para inicializar um item OLE usando o conteúdo do objeto de transferência de dados especificado.|
|[COleServerItem:: OnQueryUpdateItems](#onqueryupdateitems)|Chamado para determinar se os itens vinculados precisam ser atualizados.|
|[COleServerItem:: OnRenderData](#onrenderdata)|Recupera dados como parte da renderização atrasada.|
|[COleServerItem:: OnRenderFileData](#onrenderfiledata)|Recupera dados em um objeto `CFile` como parte da renderização atrasada.|
|[COleServerItem:: OnRenderGlobalData](#onrenderglobaldata)|Recupera dados em um HGLOBAL como parte da renderização atrasada.|
|[COleServerItem:: OnSetColorScheme](#onsetcolorscheme)|Chamado para definir o esquema de cores do item.|
|[COleServerItem:: OnSetData](#onsetdata)|Chamado para definir os dados do item.|
|[COleServerItem:: OnSetExtent](#onsetextent)|Chamado pelo Framework para definir o tamanho do item OLE.|
|[COleServerItem:: OnUpdate](#onupdate)|Chamado quando alguma parte do documento ao qual o item pertence é alterada.|
|[COleServerItem:: OnUpdateItems](#onupdateitems)|Chamado para atualizar o cache de apresentação de todos os itens no documento do servidor.|
|[COleServerItem:: setitemname](#setitemname)|Define o nome do item. Usado somente para itens vinculados.|

### <a name="protected-methods"></a>Métodos protegidos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COleServerItem:: getdataname](#getdatasource)|Obtém o objeto usado para armazenar formatos de conversão.|
|[COleServerItem:: OnHide](#onhide)|Chamado pelo Framework para ocultar o item OLE.|
|[COleServerItem:: OnOpen](#onopen)|Chamado pelo Framework para exibir o item OLE em sua própria janela de nível superior.|
|[COleServerItem:: OnShow](#onshow)|Chamado quando o contêiner solicita a exibição do item.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[COleServerItem:: m_sizeExtent](#m_sizeextent)|Informa ao servidor sobre quanto do item OLE está visível.|

## <a name="remarks"></a>Comentários

Um item vinculado pode representar um ou todos os documentos de um servidor. Um item inserido sempre representa um documento inteiro do servidor.

A classe `COleServerItem` define várias funções de membro substituíveis que são chamadas pelas DLLs (bibliotecas de vínculo dinâmico) do sistema OLE, geralmente em resposta às solicitações do aplicativo de contêiner. Essas funções de membro permitem que o aplicativo de contêiner manipule o item indiretamente de várias maneiras, como exibi-lo, executar seus verbos ou recuperar seus dados em vários formatos.

Para usar `COleServerItem`, derive uma classe dela e implemente as funções de membro [OnDraw](#ondraw) e [Serialize](../../mfc/reference/cobject-class.md#serialize) . A função `OnDraw` fornece a representação de metarquivo de um item, permitindo que ele seja exibido quando um aplicativo de contêiner abrir um documento composto. A função `Serialize` do `CObject` fornece a representação nativa de um item, permitindo que um item incorporado seja transferido entre os aplicativos de servidor e de contêiner. [OnGetExtent](#ongetextent) fornece o tamanho natural do item para o contêiner, permitindo que o contêiner dimensione o item.

Para obter mais informações sobre servidores e tópicos relacionados, consulte o artigo [servidores: Implementando um servidor](../../mfc/servers-implementing-a-server.md) e "criando um aplicativo de contêiner/servidor" no artigo [contêineres: recursos avançados](../../mfc/containers-advanced-features.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CDocItem](../../mfc/reference/cdocitem-class.md)

`COleServerItem`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxole. h

##  <a name="addotherclipboarddata"></a>COleServerItem:: AddOtherClipboardData

Chame essa função para posicionar os formatos de apresentação e conversão para o item OLE no objeto de `COleDataSource` especificado.

```
void AddOtherClipboardData(COleDataSource* pDataSource);
```

### <a name="parameters"></a>parâmetros

*pDataSource*<br/>
Ponteiro para o objeto `COleDataSource` no qual os dados devem ser colocados.

### <a name="remarks"></a>Comentários

Você deve ter implementado a função de membro [OnDraw](#ondraw) para fornecer o formato de apresentação (uma imagem de metarquivo) para o item. Para dar suporte a outros formatos de conversão, registre-os usando o objeto [COleDataSource](../../mfc/reference/coledatasource-class.md) retornado por [getdataname](#getdatasource) e substitua a função membro [OnRenderData](#onrenderdata) para fornecer dados nos formatos aos quais você deseja dar suporte.

##  <a name="coleserveritem"></a>COleServerItem:: COleServerItem

Constrói um objeto `COleServerItem` e o adiciona à coleção de itens de documento do documento do servidor.

```
COleServerItem(
    COleServerDoc* pServerDoc,
    BOOL bAutoDelete);
```

### <a name="parameters"></a>parâmetros

*pServerDoc*<br/>
Ponteiro para o documento que conterá o novo item.

*bAutoDelete*<br/>
Sinalizador que indica se o objeto pode ser excluído quando um link para ele é liberado. Defina como FALSE se o objeto `COleServerItem` for uma parte integral dos dados do documento que você deve excluir. Defina como verdadeiro se o objeto for uma estrutura secundária usada para identificar um intervalo nos dados do documento que podem ser excluídos pela estrutura.

##  <a name="copytoclipboard"></a>COleServerItem:: CopyToClipboard

Chame essa função para copiar o item OLE para a área de transferência.

```
void CopyToClipboard(BOOL bIncludeLink = FALSE);
```

### <a name="parameters"></a>parâmetros

*bIncludeLink*<br/>
Defina como verdadeiro se os dados do link devem ser copiados para a área de transferência. Defina como FALSE se o aplicativo do servidor não oferecer suporte a links.

### <a name="remarks"></a>Comentários

A função usa a função de membro [OnGetClipboardData](#ongetclipboarddata) para criar um objeto [COleDataSource](../../mfc/reference/coledatasource-class.md) contendo os dados do item OLE nos formatos com suporte. Em seguida, a função coloca o objeto `COleDataSource` na área de transferência usando a função [COleDataSource:: SetClipboard](../../mfc/reference/coledatasource-class.md#setclipboard) . O objeto `COleDataSource` inclui os dados nativos do item e sua representação no formato CF_METAFILEPICT, bem como os dados em quaisquer formatos de conversão para os quais você optar por dar suporte. Você deve ter implementado [Serialize](../../mfc/reference/cobject-class.md#serialize) e [OnDraw](#ondraw) para que essa função de membro funcione.

##  <a name="dodragdrop"></a>COleServerItem::D oDragDrop

Chame a função de membro `DoDragDrop` para executar uma operação de arrastar e soltar.

```
DROPEFFECT DoDragDrop(
    LPCRECT lpRectItem,
    CPoint ptOffset,
    BOOL bIncludeLink = FALSE,
    DWORD dwEffects = DROPEFFECT_COPY | DROPEFFECT_MOVE,
    LPCRECT lpRectStartDrag = NULL);
```

### <a name="parameters"></a>parâmetros

*lpRectItem*<br/>
O retângulo do item na tela, em pixels, em relação à área do cliente.

*ptOffset*<br/>
O deslocamento de *lpItemRect* onde a posição do mouse estava no momento da operação de arrastar.

*bIncludeLink*<br/>
Defina como verdadeiro se os dados do link devem ser copiados para a área de transferência. Defina-a como FALSE se seu aplicativo não oferecer suporte a links.

*dwEffects*<br/>
Determina os efeitos que a fonte de arrastar permitirá na operação de arrastar (uma combinação de copiar, mover e vincular).

*lpRectStartDrag*<br/>
Ponteiro para o retângulo que define onde o arrastar realmente começa. Para obter mais informações, consulte a seção Comentários a seguir.

### <a name="return-value"></a>Valor retornado

Um valor da enumeração DROPEFFECT. Se for DROPEFFECT_MOVE, os dados originais deverão ser removidos.

### <a name="remarks"></a>Comentários

A operação de arrastar e soltar não é iniciada imediatamente. Ele aguarda até que o cursor do mouse saia do retângulo especificado por *lpRectStartDrag* ou até que um número especificado de milissegundos tenha passado. Se *lpRectStartDrag* for NULL, um retângulo padrão será usado para que o arraste seja iniciado quando o cursor do mouse se mover um pixel.

O tempo de atraso é especificado por uma configuração de chave do registro. Você pode alterar o tempo de atraso chamando [CWinApp:: WriteProfileString](../../mfc/reference/cwinapp-class.md#writeprofilestring) ou [CWinApp:: WriteProfileInt](../../mfc/reference/cwinapp-class.md#writeprofileint). Se você não especificar o tempo de atraso, será usado um valor padrão de 200 milissegundos. O tempo de atraso de arrastar é armazenado da seguinte maneira:

- O tempo de atraso de arrastar do Windows NT é armazenado em HKEY_LOCAL_MACHINE \SOFTWARE\Microsoft\Windows\NT\CurrentVersion\IniFileMapping\win.ini\Windows\DragDelay.

- O tempo de espera de arrastar do Windows 3. x é armazenado no WIN. INI, na seção [Windows}.

- O tempo de atraso de arrasto do Windows 95/98 é armazenado em uma versão armazenada em cache do WIN. Personalizado.

Para obter mais informações sobre como as informações de atraso de arrastar são armazenadas no registro ou no. Arquivo INI, consulte [WriteProfileString](/windows/win32/api/winbase/nf-winbase-writeprofilestringw) no SDK do Windows.

##  <a name="getclipboarddata"></a>COleServerItem:: GetClipboardData

Chame essa função para preencher o objeto [COleDataSource](../../mfc/reference/coledatasource-class.md) especificado com todos os dados que seriam copiados para a área de transferência se você chamou [CopyToClipboard](#copytoclipboard) (os mesmos dados também seriam transferidos se você chamou [DoDragDrop](#dodragdrop)).

```
void GetClipboardData(
    COleDataSource* pDataSource,
    BOOL bIncludeLink = FALSE,
    LPPOINT lpOffset = NULL,
    LPSIZE lpSize = NULL);
```

### <a name="parameters"></a>parâmetros

*pDataSource*<br/>
Ponteiro para o objeto `COleDataSource` que receberá os dados do item OLE em todos os formatos com suporte.

*bIncludeLink*<br/>
TRUE se os dados do link devem ser copiados para a área de transferência. FALSE se o aplicativo do servidor não oferecer suporte a links.

*lpOffset*<br/>
O deslocamento, em pixels, do cursor do mouse da origem do objeto.

*lpSize*<br/>
O tamanho do objeto em pixels.

### <a name="remarks"></a>Comentários

Essa função chama a função de membro [GetEmbedSourceData](#getembedsourcedata) para obter os dados nativos do item OLE e chama a função de membro [AddOtherClipboardData](#addotherclipboarddata) para obter o formato de apresentação e todos os formatos de conversão com suporte. Se *bIncludeLink* for true, a função também chamará [GetLinkSourceData](#getlinksourcedata) para obter os dados do link para o item.

Substitua essa função se desejar colocar formatos em um objeto de `COleDataSource` antes ou depois desses formatos fornecidos pelo `CopyToClipboard`.

##  <a name="getdatasource"></a>COleServerItem:: getdataname

Chame essa função para obter o objeto [COleDataSource](../../mfc/reference/coledatasource-class.md) usado para armazenar os formatos de conversão que o aplicativo do servidor suporta.

```
COleDataSource* GetDataSource();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto `COleDataSource` usado para armazenar os formatos de conversão.

### <a name="remarks"></a>Comentários

Se você quiser que o aplicativo de servidor ofereça dados em uma variedade de formatos durante as operações de transferência de dados, registre esses formatos com o objeto `COleDataSource` retornado por essa função. Por exemplo, se você quiser fornecer uma representação CF_TEXT do item OLE para operações de área de transferência ou arrastar e soltar, registre o formato com o objeto `COleDataSource` que essa função retorna e, em seguida, substitua a função membro `OnRenderXxxData` para fornecer os dados.

##  <a name="getdocument"></a>COleServerItem:: GetDocument

Chame essa função para obter um ponteiro para o documento que contém o item.

```
COleServerDoc* GetDocument() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o documento que contém o item; NULL se o item não fizer parte de um documento.

### <a name="remarks"></a>Comentários

Isso permite o acesso ao documento do servidor que você passou como um argumento para o Construtor `COleServerItem`.

##  <a name="getembedsourcedata"></a>COleServerItem:: GetEmbedSourceData

Chame essa função para obter os dados de CF_EMBEDSOURCE de um item OLE.

```
void GetEmbedSourceData(LPSTGMEDIUM lpStgMedium);
```

### <a name="parameters"></a>parâmetros

*lpStgMedium*<br/>
Ponteiro para a estrutura [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) que receberá os dados de CF_EMBEDSOURCE para o item OLE.

### <a name="remarks"></a>Comentários

Esse formato inclui os dados nativos do item. Você deve ter implementado a função de membro `Serialize` para que essa função funcione corretamente.

O resultado pode ser adicionado a uma fonte de dados usando [COleDataSource:: CacheData](../../mfc/reference/coledatasource-class.md#cachedata). Essa função é chamada automaticamente por [COleServerItem:: OnGetClipboardData](#ongetclipboarddata).

Para obter mais informações, consulte [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) no SDK do Windows.

##  <a name="getitemname"></a>COleServerItem:: getItemName

Chame essa função para obter o nome do item.

```
const CString& GetItemName() const;
```

### <a name="return-value"></a>Valor retornado

O nome do item.

### <a name="remarks"></a>Comentários

Normalmente, você chama essa função somente para itens vinculados.

##  <a name="getlinksourcedata"></a>COleServerItem:: GetLinkSourceData

Chame essa função para obter os dados de CF_LINKSOURCE de um item OLE.

```
BOOL GetLinkSourceData(LPSTGMEDIUM lpStgMedium);
```

### <a name="parameters"></a>parâmetros

*lpStgMedium*<br/>
Ponteiro para a estrutura [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) que receberá os dados de CF_LINKSOURCE para o item OLE.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse formato inclui o CLSID que descreve o tipo do item OLE e as informações necessárias para localizar o documento que contém o item OLE.

O resultado pode então ser adicionado a uma fonte de dados com [COleDataSource:: CacheData](../../mfc/reference/coledatasource-class.md#cachedata). Essa função é chamada automaticamente pelo [OnGetClipboardData](#ongetclipboarddata).

Para obter mais informações, consulte [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) no SDK do Windows.

##  <a name="getobjectdescriptordata"></a>COleServerItem:: GetObjectDescriptorData

Chame essa função para obter os dados de CF_OBJECTDESCRIPTOR de um item OLE.

```
void GetObjectDescriptorData(
    LPPOINT lpOffset,
    LPSIZE lpSize,
    LPSTGMEDIUM lpStgMedium);
```

### <a name="parameters"></a>parâmetros

*lpOffset*<br/>
Deslocamento do clique do mouse no canto superior esquerdo do item OLE. Pode ser NULL.

*lpSize*<br/>
Tamanho do item OLE. Pode ser NULL.

*lpStgMedium*<br/>
Ponteiro para a estrutura [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) que receberá os dados de CF_OBJECTDESCRIPTOR para o item OLE.

### <a name="remarks"></a>Comentários

As informações são copiadas para a estrutura de `STGMEDIUM` apontada por *lpStgMedium*. Esse formato inclui as informações necessárias para a caixa de diálogo colar especial.

Para obter mais informações, consulte [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) no SDK do Windows.

##  <a name="isconnected"></a>COleServerItem:: IsConnected

Chame essa função para ver se o item OLE está conectado.

```
BOOL IsConnected() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o item estiver conectado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um item OLE será considerado conectado se um ou mais contêineres tiverem referências ao item. Um item será conectado se sua contagem de referência for maior que 0 ou se for um item inserido.

##  <a name="islinkeditem"></a>COleServerItem:: IsLinkedItem

Chame essa função para ver se o item OLE é um item vinculado.

```
BOOL IsLinkedItem() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o item for um item vinculado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um item será vinculado se o item for válido e não for retornado na lista de itens inseridos do documento. Um item vinculado pode ou não estar conectado a um contêiner.

É comum usar a mesma classe para itens vinculados e incorporados. `IsLinkedItem` permite que você faça com que os itens vinculados se comportem de forma diferente dos itens inseridos, embora muitas vezes o código seja comum.

##  <a name="m_sizeextent"></a>COleServerItem:: m_sizeExtent

Esse membro informa ao servidor quanto do objeto está visível no documento do contêiner.

```
CSize m_sizeExtent;
```

### <a name="remarks"></a>Comentários

A implementação padrão de [OnSetExtent](#onsetextent) define esse membro.

##  <a name="notifychanged"></a>COleServerItem:: NotifyChanged

Chame essa função depois que o item vinculado tiver sido alterado.

```
void NotifyChanged(DVASPECT nDrawAspect = DVASPECT_CONTENT);
```

### <a name="parameters"></a>parâmetros

*nDrawAspect*<br/>
Um valor da enumeração DVASPECT que indica qual aspecto do item OLE foi alterado. Esse parâmetro pode ter qualquer um dos seguintes valores:

- DVASPECT_CONTENT item é representado de forma que possa ser exibido como um objeto incorporado dentro de seu contêiner.

- DVASPECT_THUMBNAIL item é renderizado em uma representação de "miniatura" para que possa ser exibido em uma ferramenta de navegação.

- DVASPECT_ICON item é representado por um ícone.

- DVASPECT_DOCPRINT Item é representado como se fosse impresso usando o comando Imprimir no menu arquivo.

### <a name="remarks"></a>Comentários

Se um item de contêiner estiver vinculado ao documento com um link automático, o item será atualizado para refletir as alterações. Em aplicativos de contêiner escritos usando o biblioteca MFC, [COleClientItem:: OnChange](../../mfc/reference/coleclientitem-class.md#onchange) é chamado em resposta.

##  <a name="ondoverb"></a>COleServerItem:: OnDoVerb

Chamado pelo Framework para executar o verbo especificado.

```
virtual void OnDoVerb(LONG iVerb);
```

### <a name="parameters"></a>parâmetros

*iVerb*<br/>
Especifica o verbo a ser executado. Pode ser qualquer um dos seguintes:

|Valor|Significado|Símbolo|
|-----------|-------------|------------|
|0|Verbo primário|OLEIVERB_PRIMARY|
|1|Verbo secundário|(Nenhuma)|
|- 1|Exibir item para edição|OLEIVERB_SHOW|
|- 2|Editar item em janela separada|OLEIVERB_OPEN|
|- 3|Ocultar item|OLEIVERB_HIDE|

O valor-1 normalmente é um alias para outro verbo. Se a edição aberta não tiver suporte,-2 terá o mesmo efeito que-1. Para obter valores adicionais, consulte [IOleObject::D overb](/windows/win32/api/oleidl/nf-oleidl-ioleobject-doverb) no SDK do Windows.

### <a name="remarks"></a>Comentários

Se o aplicativo de contêiner foi gravado com o biblioteca MFC, essa função é chamada quando a função de membro [COleClientItem:: Activate](../../mfc/reference/coleclientitem-class.md#activate) do objeto `COleClientItem` correspondente é chamada. A implementação padrão chama a função de membro [OnShow](#onshow) se o verbo ou OLEIVERB_SHOW primário for especificado, [OnOpen](#onopen) se o verbo secundário ou OLEIVERB_OPEN for especificado e [OnHide](#onhide) se OLEIVERB_HIDE for especificado. A implementação padrão chama `OnShow` se *iVerb* não for um dos verbos listados acima.

Substitua essa função se o verbo primário não mostrar o item. Por exemplo, se o item for uma gravação de som e seu verbo primário for reproduzir, você não precisará exibir o aplicativo de servidor para reproduzir o item.

Para obter mais informações, consulte [IOleObject::D overb](/windows/win32/api/oleidl/nf-oleidl-ioleobject-doverb) no SDK do Windows.

##  <a name="ondraw"></a>COleServerItem:: OnDraw

Chamado pelo Framework para renderizar o item OLE em um metarquivo.

```
virtual BOOL OnDraw(
    CDC* pDC,
    CSize& rSize) = 0;
```

### <a name="parameters"></a>parâmetros

*pDC*<br/>
Um ponteiro para o objeto [CDC](../../mfc/reference/cdc-class.md) no qual desenhar o item. O contexto de exibição é automaticamente conectado ao contexto de exibição de atributo para que você possa chamar funções de atributo, embora isso torne o metarquivo específico ao dispositivo.

*rSize*<br/>
Tamanho, em unidades HIMETRIC, no qual desenhar o metarquivo.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o item foi desenhado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

A representação de metarquivo do item OLE é usada para exibir o item no aplicativo de contêiner. Se o aplicativo de contêiner foi gravado com o biblioteca MFC, o metarquivo é usado pela função de membro [draw](../../mfc/reference/coleclientitem-class.md#draw) do objeto [COleClientItem](../../mfc/reference/coleclientitem-class.md) correspondente. Não há implementação padrão. Você deve substituir essa função para desenhar o item no contexto do dispositivo especificado.

##  <a name="ondrawex"></a>COleServerItem:: OnDrawEx

Chamado pelo Framework para todo o desenho.

```
virtual BOOL OnDrawEx(
    CDC* pDC,
    DVASPECT nDrawAspect,
    CSize& rSize);
```

### <a name="parameters"></a>parâmetros

*pDC*<br/>
Um ponteiro para o objeto [CDC](../../mfc/reference/cdc-class.md) no qual desenhar o item. O controlador de domínio é conectado automaticamente ao DC do atributo para que você possa chamar funções de atributo, embora isso torne o metarquivo específico ao dispositivo.

*nDrawAspect*<br/>
Um valor da enumeração DVASPECT. Esse parâmetro pode ter qualquer um dos seguintes valores:

- DVASPECT_CONTENT item é representado de forma que possa ser exibido como um objeto incorporado dentro de seu contêiner.

- DVASPECT_THUMBNAIL item é renderizado em uma representação de "miniatura" para que possa ser exibido em uma ferramenta de navegação.

- DVASPECT_ICON item é representado por um ícone.

- DVASPECT_DOCPRINT Item é representado como se fosse impresso usando o comando Imprimir no menu arquivo.

*rSize*<br/>
Tamanho do item em unidades HIMETRIC.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o item foi desenhado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão chama `OnDraw` quando DVASPECT é igual a DVASPECT_CONTENT; caso contrário, ele falhará.

Substitua essa função para fornecer dados de apresentação para aspectos diferentes de DVASPECT_CONTENT, como DVASPECT_ICON ou DVASPECT_THUMBNAIL.

##  <a name="ongetclipboarddata"></a>COleServerItem:: OnGetClipboardData

Chamado pelo Framework para obter um objeto `COleDataSource` contendo todos os dados que seriam colocados na área de transferência por uma chamada para a função membro [CopyToClipboard](#copytoclipboard) .

```
virtual COleDataSource* OnGetClipboardData(
    BOOL bIncludeLink,
    LPPOINT lpOffset,
    LPSIZE lpSize);
```

### <a name="parameters"></a>parâmetros

*bIncludeLink*<br/>
Defina como verdadeiro se os dados do link devem ser copiados para a área de transferência. Defina como FALSE se o aplicativo do servidor não oferecer suporte a links.

*lpOffset*<br/>
O deslocamento do cursor do mouse da origem do objeto em pixels.

*lpSize*<br/>
O tamanho do objeto em pixels.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [COleDataSource](../../mfc/reference/coledatasource-class.md) que contém os dados da área de transferência.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função chama [GetClipboardData](#getclipboarddata).

##  <a name="ongetextent"></a>COleServerItem:: OnGetExtent

Chamado pelo Framework para recuperar o tamanho, em unidades HIMETRIC, do item OLE.

```
virtual BOOL OnGetExtent(
    DVASPECT nDrawAspect,
    CSize& rSize);
```

### <a name="parameters"></a>parâmetros

*nDrawAspect*<br/>
Especifica o aspecto do item OLE cujos limites devem ser recuperados. Esse parâmetro pode ter qualquer um dos seguintes valores:

- DVASPECT_CONTENT item é representado de forma que possa ser exibido como um objeto incorporado dentro de seu contêiner.

- DVASPECT_THUMBNAIL item é renderizado em uma representação de "miniatura" para que possa ser exibido em uma ferramenta de navegação.

- DVASPECT_ICON item é representado por um ícone.

- DVASPECT_DOCPRINT Item é representado como se fosse impresso usando o comando Imprimir no menu arquivo.

*rSize*<br/>
Referência a um objeto `CSize` que receberá o tamanho do item OLE.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o aplicativo de contêiner foi gravado com o biblioteca MFC, essa função é chamada quando a função [de membro](../../mfc/reference/coleclientitem-class.md#getextent) getcall do objeto `COleClientItem` correspondente é chamada. A implementação padrão não faz nada. Você mesmo deve implementá-lo. Substitua essa função se você quiser executar processamento especial ao manipular uma solicitação para o tamanho do item OLE.

##  <a name="onhide"></a>COleServerItem:: OnHide

Chamado pelo Framework para ocultar o item OLE.

```
virtual void OnHide();
```

### <a name="remarks"></a>Comentários

As chamadas padrão `COleServerDoc::OnShowDocument( FALSE )`. A função também notifica o contêiner de que o item OLE foi ocultado. Substitua essa função se desejar executar um processamento especial ao ocultar um item OLE.

##  <a name="oninitfromdata"></a>COleServerItem:: OnInitFromData

Chamado pelo Framework para inicializar um item OLE usando o conteúdo de *pDataObject*.

```
virtual BOOL OnInitFromData(
    COleDataObject* pDataObject,
    BOOL bCreation);
```

### <a name="parameters"></a>parâmetros

*pDataObject*<br/>
Ponteiro para um objeto de dados OLE que contém dados em vários formatos para inicializar o item OLE.

*bCreation*<br/>
TRUE se a função for chamada para inicializar um item OLE que está sendo criado recentemente por um aplicativo de contêiner. FALSE se a função for chamada para substituir o conteúdo de um item OLE já existente.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se *bCreation* for true, essa função será chamada se um contêiner implementar Inserir novo objeto com base na seleção atual. Os dados selecionados são usados ao criar o novo item OLE. Por exemplo, ao selecionar um intervalo de células em um programa de planilha e, em seguida, usar o novo objeto INSERT para criar um gráfico com base nos valores no intervalo selecionado. A implementação padrão não faz nada. Substitua essa função para escolher um formato aceitável daqueles oferecidos pelo *pDataObject* e inicializar o item OLE com base nos dados fornecidos. Esse é um substituível avançado.

Para obter mais informações, consulte [IOleObject:: InitFromData](/windows/win32/api/oleidl/nf-oleidl-ioleobject-initfromdata) no SDK do Windows.

##  <a name="onopen"></a>COleServerItem:: OnOpen

Chamado pelo Framework para exibir o item OLE em uma instância separada do aplicativo de servidor, em vez de em vigor.

```
virtual void OnOpen();
```

### <a name="remarks"></a>Comentários

A implementação padrão ativa a primeira janela do quadro exibindo o documento que contém o item OLE; Se o aplicativo for um mini-servidor, a implementação padrão mostrará a janela principal. A função também notifica o contêiner de que o item OLE foi aberto.

Substitua essa função se desejar executar um processamento especial ao abrir um item OLE. Isso é especialmente comum com itens vinculados nos quais você deseja definir a seleção para o link quando ele é aberto.

Para obter mais informações, consulte [IOleClientSite:: OnShowWindow](/windows/win32/api/oleidl/nf-oleidl-ioleclientsite-onshowwindow) no SDK do Windows.

##  <a name="onqueryupdateitems"></a>COleServerItem:: OnQueryUpdateItems

Chamado pelo Framework para determinar se os itens vinculados no documento do servidor atual estão desatualizados.

```
virtual BOOL OnQueryUpdateItems();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o documento tiver itens que precisam de atualizações; 0 se todos os itens estiverem atualizados.

### <a name="remarks"></a>Comentários

Um item estará desatualizado se o documento de origem tiver sido alterado, mas o item vinculado não tiver sido atualizado para refletir as alterações no documento.

##  <a name="onrenderdata"></a>COleServerItem:: OnRenderData

Chamado pelo Framework para recuperar dados no formato especificado.

```
virtual BOOL OnRenderData(
    LPFORMATETC lpFormatEtc,
    LPSTGMEDIUM lpStgMedium);
```

### <a name="parameters"></a>parâmetros

*lpFormatEtc*<br/>
Aponta para a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) especificando o formato no qual as informações são solicitadas.

*lpStgMedium*<br/>
Aponta para uma estrutura [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) na qual os dados serão retornados.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O formato especificado é um colocado anteriormente no objeto `COleDataSource` usando a função de membro [DelayRenderData](../../mfc/reference/coledatasource-class.md#delayrenderdata) ou [DelayRenderFileData](../../mfc/reference/coledatasource-class.md#delayrenderfiledata) para a renderização atrasada. A implementação padrão dessa função chama [OnRenderFileData](#onrenderfiledata) ou [OnRenderGlobalData](#onrenderglobaldata), respectivamente, se o meio de armazenamento fornecido for um arquivo ou uma memória. Se nenhum desses formatos for fornecido, a implementação padrão retornará 0 e não fará nada.

Se *lpStgMedium*-> *TYMED* for TYMED_NULL, o STGMEDIUM deverá ser alocado e preenchido conforme especificado por *lpFormatEtc-> tymed*. Se não TYMED_NULL, o STGMEDIUM deverá ser preenchido no local com os dados.

Esse é um substituível avançado. Substitua essa função para fornecer seus dados no formato solicitado e médio. Dependendo de seus dados, talvez você queira substituir uma das outras versões dessa função. Se os dados forem pequenos e forem corrigidos, substitua `OnRenderGlobalData`. Se os dados estiverem em um arquivo ou forem de tamanho variável, substitua `OnRenderFileData`.

Para obter mais informações, consulte [IDataObject:: GetData](/windows/win32/api/objidl/nf-objidl-idataobject-getdata), [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1), [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc)e [TYMED](/windows/win32/api/objidl/ne-objidl-tymed) no SDK do Windows.

##  <a name="onrenderfiledata"></a>COleServerItem:: OnRenderFileData

Chamado pelo Framework para recuperar dados no formato especificado quando a mídia de armazenamento é um arquivo.

```
virtual BOOL OnRenderFileData(
    LPFORMATETC lpFormatEtc,
    CFile* pFile);
```

### <a name="parameters"></a>parâmetros

*lpFormatEtc*<br/>
Aponta para a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) especificando o formato no qual as informações são solicitadas.

*pFile*<br/>
Aponta para um objeto `CFile` no qual os dados serão renderizados.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O formato especificado é um colocado anteriormente no objeto `COleDataSource` usando a função membro [DelayRenderData](../../mfc/reference/coledatasource-class.md#delayrenderdata) para a renderização atrasada. A implementação padrão dessa função simplesmente retorna FALSE.

Esse é um substituível avançado. Substitua essa função para fornecer seus dados no formato solicitado e médio. Dependendo de seus dados, talvez você queira substituir uma das outras versões dessa função. Se você quiser lidar com vários meios de armazenamento, substitua [OnRenderData](#onrenderdata). Se os dados estiverem em um arquivo ou forem de tamanho variável, substitua [OnRenderFileData](#onrenderfiledata).

Para obter mais informações, consulte [IDataObject:: GetData](/windows/win32/api/objidl/nf-objidl-idataobject-getdata) e [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

##  <a name="onrenderglobaldata"></a>COleServerItem:: OnRenderGlobalData

Chamado pelo Framework para recuperar dados no formato especificado quando a mídia de armazenamento especificada é a memória global.

```
virtual BOOL OnRenderGlobalData(
    LPFORMATETC lpFormatEtc,
    HGLOBAL* phGlobal);
```

### <a name="parameters"></a>parâmetros

*lpFormatEtc*<br/>
Aponta para a estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) especificando o formato no qual as informações são solicitadas.

*phGlobal*<br/>
Aponta para um identificador para a memória global na qual os dados serão retornados. Se nenhuma memória tiver sido alocada, esse parâmetro poderá ser nulo.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O formato especificado é um colocado anteriormente no objeto `COleDataSource` usando a função membro [DelayRenderData](../../mfc/reference/coledatasource-class.md#delayrenderdata) para a renderização atrasada. A implementação padrão dessa função simplesmente retorna FALSE.

Se *phGlobal* for NULL, um novo HGLOBAL deverá ser alocado e retornado em *phGlobal*. Caso contrário, o HGLOBAL especificado por *phGlobal* deve ser preenchido com os dados. A quantidade de dados colocados em HGLOBAL não deve exceder o tamanho atual do bloco de memória. Além disso, o bloco não pode ser realocado para um tamanho maior.

Esse é um substituível avançado. Substitua essa função para fornecer seus dados no formato solicitado e médio. Dependendo de seus dados, talvez você queira substituir uma das outras versões dessa função. Se você quiser lidar com vários meios de armazenamento, substitua [OnRenderData](#onrenderdata). Se os dados estiverem em um arquivo ou forem de tamanho variável, substitua [OnRenderFileData](#onrenderfiledata).

Para obter mais informações, consulte [IDataObject:: GetData](/windows/win32/api/objidl/nf-objidl-idataobject-getdata) e [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) no SDK do Windows.

##  <a name="onsetcolorscheme"></a>COleServerItem:: OnSetColorScheme

Chamado pelo Framework para especificar uma paleta de cores a ser usada ao editar o item OLE.

```
virtual BOOL OnSetColorScheme(const LOGPALETTE* lpLogPalette);
```

### <a name="parameters"></a>parâmetros

*lpLogPalette*<br/>
Ponteiro para uma estrutura [LOGPALETTE](/windows/win32/api/wingdi/ns-wingdi-logpalette) do Windows.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a paleta de cores for usada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o aplicativo de contêiner foi escrito usando o biblioteca MFC, essa função é chamada quando a função [IOleObject:: SetColorScheme](/windows/win32/api/oleidl/nf-oleidl-ioleobject-setcolorscheme) do objeto `COleClientItem` correspondente é chamada. A implementação padrão retorna FALSE. Substitua essa função se desejar usar a paleta recomendada. O aplicativo de servidor não é necessário para usar a paleta sugerida.

Para obter mais informações, consulte [IOleObject:: SetColorScheme](/windows/win32/api/oleidl/nf-oleidl-ioleobject-setcolorscheme) no SDK do Windows.

##  <a name="onsetdata"></a>COleServerItem:: OnSetData

Chamado pelo Framework para substituir os dados do item OLE pelos dados especificados.

```
virtual BOOL OnSetData(
    LPFORMATETC lpFormatEtc,
    LPSTGMEDIUM lpStgMedium,
    BOOL bRelease);
```

### <a name="parameters"></a>parâmetros

*lpFormatEtc*<br/>
Ponteiro para uma estrutura [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) especificando o formato dos dados.

*lpStgMedium*<br/>
Ponteiro para uma estrutura [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1) na qual os dados residem.

*bRelease*<br/>
Indica quem tem a propriedade do meio de armazenamento depois de concluir a chamada de função. O chamador decide quem é responsável por liberar os recursos alocados em nome do meio de armazenamento. O chamador faz isso definindo *bRelease*. Se *bRelease* for diferente de zero, o item de servidor assumirá a propriedade, liberando a mídia quando terminar de usá-la. Quando *bRelease* é 0, o chamador retém a propriedade e o item do servidor pode usar a mídia de armazenamento somente durante a chamada.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O item de servidor não assume a propriedade dos dados até que ele seja obtido com êxito. Ou seja, ele não assumirá a propriedade se retornar 0. Se a fonte de dados assumir a propriedade, ela liberará o meio de armazenamento chamando a função [ReleaseStgMedium](/windows/win32/api/ole2/nf-ole2-releasestgmedium) .

A implementação padrão não faz nada. Substitua essa função para substituir os dados do item OLE pelos dados especificados. Esse é um substituível avançado.

Para obter mais informações, consulte [STGMEDIUM](/windows/win32/api/objidl/ns-objidl-ustgmedium~r1), [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc)e [ReleaseStgMedium](/windows/win32/api/ole2/nf-ole2-releasestgmedium) no SDK do Windows.

##  <a name="onsetextent"></a>COleServerItem:: OnSetExtent

Chamado pelo Framework para dizer ao item OLE quanto espaço está disponível para ele no documento do contêiner.

```
virtual BOOL OnSetExtent(
    DVASPECT nDrawAspect,
    const CSize& size);
```

### <a name="parameters"></a>parâmetros

*nDrawAspect*<br/>
Especifica o aspecto do item OLE cujos limites estão sendo especificados. Esse parâmetro pode ter qualquer um dos seguintes valores:

- DVASPECT_CONTENT item é representado de forma que possa ser exibido como um objeto incorporado dentro de seu contêiner.

- DVASPECT_THUMBNAIL item é renderizado em uma representação de "miniatura" para que possa ser exibido em uma ferramenta de navegação.

- DVASPECT_ICON item é representado por um ícone.

- DVASPECT_DOCPRINT Item é representado como se fosse impresso usando o comando Imprimir no menu arquivo.

*size*<br/>
Uma estrutura [CSize](../../atl-mfc-shared/reference/csize-class.md) especificando o novo tamanho do item OLE.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o aplicativo de contêiner foi gravado com o biblioteca MFC, essa função é chamada quando a função membro [SetExtent](../../mfc/reference/coleclientitem-class.md#setextent) do objeto `COleClientItem` correspondente é chamada. A implementação padrão define o membro [m_sizeExtent](#m_sizeextent) como o tamanho especificado se *nDrawAspect* for DVASPECT_CONTENT; caso contrário, retornará 0. Substitua essa função para executar processamento especial quando você alterar o tamanho do item.

##  <a name="onshow"></a>COleServerItem:: OnShow

Chamado pelo Framework para instruir o aplicativo de servidor a exibir o item OLE no local.

```
virtual void OnShow();
```

### <a name="remarks"></a>Comentários

Essa função é normalmente chamada quando o usuário do aplicativo de contêiner cria um item ou executa um verbo, como editar, que requer que o item seja mostrado. A implementação padrão tenta a ativação in-loco. Se isso falhar, a função chamará a função de membro `OnOpen` para exibir o item OLE em uma janela separada.

Substitua essa função se desejar executar processamento especial quando um item OLE for mostrado.

##  <a name="onupdate"></a>COleServerItem:: OnUpdate

Chamado pelo Framework quando um item foi modificado.

```
virtual void OnUpdate(
    COleServerItem* pSender,
    LPARAM lHint,
    CObject* pHint,
    DVASPECT nDrawAspect);
```

### <a name="parameters"></a>parâmetros

*pSender*<br/>
Ponteiro para o item que modificou o documento. Pode ser NULL.

*lHint*<br/>
Contém informações sobre a modificação.

*pHint*<br/>
Ponteiro para um objeto que armazena informações sobre a modificação.

*nDrawAspect*<br/>
Um valor da enumeração DVASPECT. Esse parâmetro pode ter qualquer um dos seguintes valores:

- DVASPECT_CONTENT item é representado de forma que possa ser exibido como um objeto incorporado dentro de seu contêiner.

- DVASPECT_THUMBNAIL item é renderizado em uma representação de "miniatura" para que possa ser exibido em uma ferramenta de navegação.

- DVASPECT_ICON item é representado por um ícone.

- DVASPECT_DOCPRINT Item é representado como se fosse impresso usando o comando Imprimir no menu arquivo.

### <a name="remarks"></a>Comentários

A implementação padrão chama [notificachanged](#notifychanged), independentemente da dica ou do remetente.

##  <a name="onupdateitems"></a>COleServerItem:: OnUpdateItems

Chamado pelo Framework para atualizar todos os itens no documento do servidor.

```
virtual void OnUpdateItems();
```

### <a name="remarks"></a>Comentários

A implementação padrão chama [UpdateLink](../../mfc/reference/coleclientitem-class.md#updatelink) para todos os objetos `COleClientItem` no documento.

##  <a name="setitemname"></a>COleServerItem:: setitemname

Chame essa função quando você criar um item vinculado para definir seu nome.

```
void SetItemName(LPCTSTR lpszItemName);
```

### <a name="parameters"></a>parâmetros

*lpszItemName*<br/>
Ponteiro para o novo nome do item.

### <a name="remarks"></a>Comentários

O nome deve ser exclusivo dentro do documento. Quando um aplicativo de servidor é chamado para editar um item vinculado, o aplicativo usa esse nome para localizar o item. Você não precisa chamar essa função para itens inseridos.

## <a name="see-also"></a>Confira também

[Exemplo de HIERSVR do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CDocItem](../../mfc/reference/cdocitem-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)<br/>
[Classe COleServerDoc](../../mfc/reference/coleserverdoc-class.md)<br/>
[Classe COleTemplateServer](../../mfc/reference/coletemplateserver-class.md)
