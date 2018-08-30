---
title: Classe COleServerItem | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b4c5dad276db338b5efa0d15786b090779fcf41a
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43207499"
---
# <a name="coleserveritem-class"></a>Classe COleServerItem
Fornece a interface de servidor para itens OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleServerItem : public CDocItem  
```  
  
## <a name="members"></a>Membros  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleServerItem::COleServerItem](#coleserveritem)|Constrói um objeto `COleServerItem`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleServerItem::AddOtherClipboardData](#addotherclipboarddata)|Coloca os formatos de apresentação e a conversão em um `COleDataSource` objeto.|  
|[COleServerItem::CopyToClipboard](#copytoclipboard)|Copia o item na área de transferência.|  
|[COleServerItem::DoDragDrop](#dodragdrop)|Executa uma operação de arrastar e soltar.|  
|[COleServerItem::GetClipboardData](#getclipboarddata)|Obtém a fonte de dados para uso na transferência de dados (arrastar e soltar ou área de transferência).|  
|[COleServerItem::GetDocument](#getdocument)|Retorna o documento de servidor que contém o item.|  
|[COleServerItem::GetEmbedSourceData](#getembedsourcedata)|Obtém os dados CF_EMBEDSOURCE para um item OLE.|  
|[COleServerItem::GetItemName](#getitemname)|Retorna o nome do item. Usado para apenas os itens vinculados.|  
|[COleServerItem::GetLinkSourceData](#getlinksourcedata)|Obtém os dados CF_LINKSOURCE para um item OLE.|  
|[COleServerItem::GetObjectDescriptorData](#getobjectdescriptordata)|Obtém os dados CF_OBJECTDESCRIPTOR para um item OLE.|  
|[COleServerItem::IsConnected](#isconnected)|Indica se o item está atualmente anexado a um contêiner do Active Directory.|  
|[COleServerItem::IsLinkedItem](#islinkeditem)|Indica se o item representa um item OLE vinculado.|  
|[COleServerItem::NotifyChanged](#notifychanged)|Atualiza todos os contêineres com a atualização automática de link.|  
|[COleServerItem::OnDoVerb](#ondoverb)|Chamado para executar um verbo.|  
|[COleServerItem::OnDraw](#ondraw)|Chamado quando o contêiner solicita para desenhar o item; implementação necessários.|  
|[COleServerItem::OnDrawEx](#ondrawex)|Chamado para o desenho do item especializado.|  
|[COleServerItem::OnGetClipboardData](#ongetclipboarddata)|Chamado pelo framework para obter os dados que seriam copiados para a área de transferência.|  
|[COleServerItem::OnGetExtent](#ongetextent)|Chamado pelo framework para recuperar o tamanho do item OLE.|  
|[COleServerItem::OnInitFromData](#oninitfromdata)|Chamado pelo framework para inicializar um item OLE usando o conteúdo do objeto de transferência de dados especificado.|  
|[COleServerItem::OnQueryUpdateItems](#onqueryupdateitems)|Chamado para determinar se os itens vinculados exigem atualização.|  
|[COleServerItem::OnRenderData](#onrenderdata)|Recupera dados como parte da renderização atrasada.|  
|[COleServerItem::OnRenderFileData](#onrenderfiledata)|Recupera os dados em um `CFile` objeto como parte da renderização atrasada.|  
|[COleServerItem::OnRenderGlobalData](#onrenderglobaldata)|Recupera os dados em um HGLOBAL como parte da renderização atrasada.|  
|[COleServerItem::OnSetColorScheme](#onsetcolorscheme)|Chamado para definir o esquema de cores do item.|  
|[COleServerItem::OnSetData](#onsetdata)|Chamado para definir os dados do item.|  
|[COleServerItem::OnSetExtent](#onsetextent)|Chamado pelo framework para definir o tamanho do item OLE.|  
|[COleServerItem::OnUpdate](#onupdate)|Chamado quando pertence a uma parte do documento do item é alterado.|  
|[COleServerItem::OnUpdateItems](#onupdateitems)|Chamado para atualizar o cache de apresentação de todos os itens no documento do servidor.|  
|[COleServerItem::SetItemName](#setitemname)|Define o nome do item. Usado para apenas os itens vinculados.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleServerItem::GetDataSource](#getdatasource)|Obtém o objeto usado para armazenar os formatos de conversão.|  
|[COleServerItem::OnHide](#onhide)|Chamado pelo framework para ocultar o item OLE.|  
|[COleServerItem::OnOpen](#onopen)|Chamado pelo framework para exibir o item OLE em sua própria janela de nível superior.|  
|[COleServerItem::OnShow](#onshow)|Chamado quando o contêiner solicita para mostrar o item.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleServerItem::m_sizeExtent](#m_sizeextent)|Informa o servidor sobre quanto o item OLE é visível.|  
  
## <a name="remarks"></a>Comentários  
 Um item vinculado pode representar alguns ou todos de um documento do servidor. Um item inserido sempre representa um documento de todo o servidor.  
  
 O `COleServerItem` classe define várias funções de membro substituíveis que são chamadas pelas bibliotecas de vínculo dinâmico do sistema OLE (DLLs), geralmente em resposta às solicitações do aplicativo de contêiner. Essas funções de membro que o aplicativo de contêiner manipular o item indiretamente de várias maneiras, como exibi-lo, executando seus verbos, ou recuperar seus dados em vários formatos.  
  
 Para usar `COleServerItem`, derive uma classe dele e implementar o [OnDraw](#ondraw) e [Serialize](../../mfc/reference/cobject-class.md#serialize) funções de membro. O `OnDraw` função fornece a representação meta-arquivo de um item, permitindo que ele seja exibido quando um aplicativo de contêiner é aberto um documento composto. O `Serialize` função de `CObject` fornece a representação nativa de um item, permitindo que um item inserido ser transferido entre os aplicativos de servidor e um contêiner. [OnGetExtent](#ongetextent) fornece o tamanho natural do item a ser o contêiner, habilitando o contêiner para o item de tamanho.  
  
 Para obter mais informações sobre servidores e tópicos relacionados, consulte o artigo [servidores: Implementando um servidor](../../mfc/servers-implementing-a-server.md) e "Criando um aplicativo de contêiner/servidor", no artigo [contêineres: recursos avançados](../../mfc/containers-advanced-features.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CDocItem](../../mfc/reference/cdocitem-class.md)  
  
 `COleServerItem`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  
  
##  <a name="addotherclipboarddata"></a>  COleServerItem::AddOtherClipboardData  
 Chame essa função para colocar os formatos de apresentação e a conversão para o item OLE especificado na `COleDataSource` objeto.  
  
```  
void AddOtherClipboardData(COleDataSource* pDataSource);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDataSource*  
 Ponteiro para o `COleDataSource` do objeto no qual os dados devem ser colocados.  
  
### <a name="remarks"></a>Comentários  
 Você deve ter implementado a [OnDraw](#ondraw) função de membro para fornecer o formato de apresentação (uma imagem de metarquivo) para o item. Para dar suporte a outros formatos de conversão, registrá-los usando o [COleDataSource](../../mfc/reference/coledatasource-class.md) objeto retornado por [GetDataSource](#getdatasource) e substitua o [OnRenderData](#onrenderdata) a função de membro para Fornece dados nos formatos que você deseja dar suporte.  
  
##  <a name="coleserveritem"></a>  COleServerItem::COleServerItem  
 Constrói um `COleServerItem` do objeto e o adiciona à coleção do documento do servidor de itens de documento.  
  
```  
COleServerItem(
    COleServerDoc* pServerDoc,  
    BOOL bAutoDelete);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pServerDoc*  
 Ponteiro para o documento que contém o novo item.  
  
 *bAutoDelete*  
 Sinalizador que indica se o objeto pode ser excluído quando um link para ele é liberado. Defina isso como FALSE se o `COleServerItem` objeto é uma parte integral de dados do documento que você deve excluir. Defina isso como TRUE se o objeto é uma estrutura secundária usada para identificar um intervalo nos dados do documento que podem ser excluídos pela estrutura.  
  
##  <a name="copytoclipboard"></a>  COleServerItem::CopyToClipboard  
 Chame essa função para copiar o item OLE para a área de transferência.  
  
```  
void CopyToClipboard(BOOL bIncludeLink = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bIncludeLink*  
 Defina isso como TRUE se os dados de link devem ser copiados para a área de transferência. Defina isso como FALSE se o servidor de aplicativo não dá suporte a links.  
  
### <a name="remarks"></a>Comentários  
 A função usa o [OnGetClipboardData](#ongetclipboarddata) função de membro para criar um [COleDataSource](../../mfc/reference/coledatasource-class.md) objeto que contém dados do item OLE nos formatos com suporte. A função, em seguida, coloca o `COleDataSource` objeto na área de transferência usando o [COleDataSource::SetClipboard](../../mfc/reference/coledatasource-class.md#setclipboard) função. O `COleDataSource` objeto inclui dados nativos do item e sua representação no formato CF_METAFILEPICT, bem como dados em todos os formatos de conversão você optar por dar suporte. Você deve ter implementado [Serialize](../../mfc/reference/cobject-class.md#serialize) e [OnDraw](#ondraw) para essa função de membro trabalhar.  
  
##  <a name="dodragdrop"></a>  COleServerItem::DoDragDrop  
 Chamar o `DoDragDrop` a função de membro para executar uma operação de arrastar e soltar.  
  
```  
DROPEFFECT DoDragDrop(
    LPCRECT lpRectItem,  
    CPoint ptOffset,  
    BOOL bIncludeLink = FALSE,  
    DWORD dwEffects = DROPEFFECT_COPY | DROPEFFECT_MOVE,  
    LPCRECT lpRectStartDrag = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpRectItem*  
 Retângulo do item na tela, em pixels, relativa a área de cliente.  
  
 *ptOffset*  
 O deslocamento a partir *lpItemRect* em que a posição do mouse foi o momento da operação de arrastar.  
  
 *bIncludeLink*  
 Defina isso como TRUE se os dados de link devem ser copiados para a área de transferência. Defina-o como FALSE se seu aplicativo não dá suporte a links.  
  
 *dwEffects*  
 Determina os efeitos que a origem do arrasto permitirá na operação de arrastar (uma combinação de copiar, mover e Link).  
  
 *lpRectStartDrag*  
 Ponteiro para o retângulo que define onde realmente inicia a operação de arrastar. Para obter mais informações, consulte a seção Comentários a seguir.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de enumeração DROPEFFECT. Se for DROPEFFECT_MOVE, os dados originais devem ser removidos.  
  
### <a name="remarks"></a>Comentários  
 A operação de arrastar e soltar não é iniciado imediatamente. Ele aguarda até que o cursor do mouse deixa o retângulo especificado por *lpRectStartDrag* ou até que um número especificado de milissegundos tiver passado. Se *lpRectStartDrag* for NULL, um retângulo padrão é usado para que a operação de arrastar inicia quando o cursor do mouse se move de um pixel.  
  
 O tempo de atraso é especificado por uma configuração de chave do registro. Você pode alterar o tempo de atraso, chamando [CWinApp::WriteProfileString](../../mfc/reference/cwinapp-class.md#writeprofilestring) ou [CWinApp::WriteProfileInt](../../mfc/reference/cwinapp-class.md#writeprofileint). Se você não especificar o tempo de atraso, é usado um valor padrão de 200 milissegundos. Tempo de atraso de arrastar é armazenado da seguinte maneira:  
  
-   Tempo de atraso de arrastar do Windows NT é armazenado no HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\NT\CurrentVersion\IniFileMapping\win.ini\Windows\DragDelay.  
  
-   Tempo de atraso de arrastar do Windows 3. x é armazenado no arquivo o WIN. Arquivo INI, sob a [seção Windows}.  
  
-   Tempo de atraso de arrastar do Windows 95/98 é armazenado em uma versão em cache do WIN. INI.  
  
 Para obter mais informações sobre como arrastar informações de atraso são armazenadas no registro ou o. O arquivo INI, consulte [WriteProfileString](/windows/desktop/api/winbase/nf-winbase-writeprofilestringa) no SDK do Windows.  
  
##  <a name="getclipboarddata"></a>  COleServerItem::GetClipboardData  
 Chame essa função para preencher especificado [COleDataSource](../../mfc/reference/coledatasource-class.md) objeto com todos os dados que seriam copiados para a área de transferência se você chamasse [CopyToClipboard](#copytoclipboard) (os mesmos dados também serão transferidos se você chamado [DoDragDrop](#dodragdrop)).  
  
```  
void GetClipboardData(
    COleDataSource* pDataSource,  
    BOOL bIncludeLink = FALSE,  
    LPPOINT lpOffset = NULL,  
    LPSIZE lpSize = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDataSource*  
 Ponteiro para o `COleDataSource` objeto que receberá os dados do item OLE em todos os formatos com suporte.  
  
 *bIncludeLink*  
 TRUE se o link de dados devem ser copiados para a área de transferência. FALSE se o aplicativo de servidor não dá suporte a links.  
  
 *lpOffset*  
 O deslocamento, em pixels, do cursor do mouse em relação à origem do objeto.  
  
 *lpSize*  
 O tamanho do objeto em pixels.  
  
### <a name="remarks"></a>Comentários  
 Essa função chama o [GetEmbedSourceData](#getembedsourcedata) função de membro para obter os dados nativos para o item OLE e chama o [AddOtherClipboardData](#addotherclipboarddata) a função de membro para obter o formato de apresentação e qualquer suporte para formatos de conversão. Se *bIncludeLink* for TRUE, a função também chama [GetLinkSourceData](#getlinksourcedata) para obter os dados de link para o item.  
  
 Substituir essa função se você quiser colocar formatos em um `COleDataSource` objeto antes ou depois dos formatos fornecidos pelo `CopyToClipboard`.  
  
##  <a name="getdatasource"></a>  COleServerItem::GetDataSource  
 Chame essa função para obter o [COleDataSource](../../mfc/reference/coledatasource-class.md) objeto usado para armazenar os formatos de conversão que o aplicativo de servidor dá suporte.  
  
```  
COleDataSource* GetDataSource();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `COleDataSource` objeto usado para armazenar os formatos de conversão.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser que seu aplicativo de servidor oferecem dados em uma variedade de formatos durante a transferência de dados de operações, registre-se nesses formatos com o `COleDataSource` objeto retornado por essa função. Por exemplo, se você quiser fornecer uma representação CF_TEXT do item OLE para área de transferência ou operações de arrastar e soltar, registrar o formato com o `COleDataSource` objeto essa função retorna e depois substitui o `OnRenderXxxData` a função de membro para fornece os dados.  
  
##  <a name="getdocument"></a>  COleServerItem::GetDocument  
 Chame essa função para obter um ponteiro para o documento que contém o item.  
  
```  
COleServerDoc* GetDocument() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o documento que contém o item; NULL se o item não é parte de um documento.  
  
### <a name="remarks"></a>Comentários  
 Isso permite o acesso ao documento no servidor que é passado como um argumento para o `COleServerItem` construtor.  
  
##  <a name="getembedsourcedata"></a>  COleServerItem::GetEmbedSourceData  
 Chame essa função para obter os dados CF_EMBEDSOURCE para um item OLE.  
  
```  
void GetEmbedSourceData(LPSTGMEDIUM lpStgMedium);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpStgMedium*  
 Ponteiro para o [STGMEDIUM](/windows/desktop/api/objidl/ns-objidl-tagstgmedium) estrutura que receberá os dados CF_EMBEDSOURCE para o item OLE.  
  
### <a name="remarks"></a>Comentários  
 Esse formato inclui dados nativos do item. Você deve ter implementado a `Serialize` a função de membro para essa função funcione corretamente.  
  
 O resultado, em seguida, pode ser adicionado a uma fonte de dados usando [COleDataSource::CacheData](../../mfc/reference/coledatasource-class.md#cachedata). Essa função é chamada automaticamente pelo [COleServerItem::OnGetClipboardData](#ongetclipboarddata).  
  
 Para obter mais informações, consulte [STGMEDIUM](/windows/desktop/api/objidl/ns-objidl-tagstgmedium) no SDK do Windows.  
  
##  <a name="getitemname"></a>  COleServerItem::GetItemName  
 Chame essa função para obter o nome do item.  
  
```  
const CString& GetItemName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome do item.  
  
### <a name="remarks"></a>Comentários  
 Você normalmente chama esta função apenas para itens vinculados.  
  
##  <a name="getlinksourcedata"></a>  COleServerItem::GetLinkSourceData  
 Chame essa função para obter os dados CF_LINKSOURCE para um item OLE.  
  
```  
BOOL GetLinkSourceData(LPSTGMEDIUM lpStgMedium);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpStgMedium*  
 Ponteiro para o [STGMEDIUM](/windows/desktop/api/objidl/ns-objidl-tagstgmedium) estrutura que receberá os dados CF_LINKSOURCE para o item OLE.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse formato inclui o CLSID que descreve o tipo do item OLE e as informações necessárias para localizar o documento que contém o item OLE.  
  
 O resultado, em seguida, pode ser adicionado a uma fonte de dados com [COleDataSource::CacheData](../../mfc/reference/coledatasource-class.md#cachedata). Essa função é chamada automaticamente pelo [OnGetClipboardData](#ongetclipboarddata).  
  
 Para obter mais informações, consulte [STGMEDIUM](/windows/desktop/api/objidl/ns-objidl-tagstgmedium) no SDK do Windows.  
  
##  <a name="getobjectdescriptordata"></a>  COleServerItem::GetObjectDescriptorData  
 Chame essa função para obter os dados CF_OBJECTDESCRIPTOR para um item OLE.  
  
```  
void GetObjectDescriptorData(
    LPPOINT lpOffset,  
    LPSIZE lpSize,  
    LPSTGMEDIUM lpStgMedium);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpOffset*  
 Deslocamento do clique do mouse no canto superior esquerdo do item OLE. Pode ser NULL.  
  
 *lpSize*  
 Tamanho do item OLE. Pode ser NULL.  
  
 *lpStgMedium*  
 Ponteiro para o [STGMEDIUM](/windows/desktop/api/objidl/ns-objidl-tagstgmedium) estrutura que receberá os dados CF_OBJECTDESCRIPTOR para o item OLE.  
  
### <a name="remarks"></a>Comentários  
 As informações são copiadas para o `STGMEDIUM` estrutura apontada por *lpStgMedium*. Esse formato inclui as informações necessárias para a caixa de diálogo Colar especial.  
  
 Para obter mais informações, consulte [STGMEDIUM](/windows/desktop/api/objidl/ns-objidl-tagstgmedium) no SDK do Windows.  
  
##  <a name="isconnected"></a>  COleServerItem::IsConnected  
 Chame essa função para ver se o item OLE é conectado.  
  
```  
BOOL IsConnected() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item está conectado; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um item OLE é considerado conectado se um ou mais contêineres tem referências para o item. Um item é conectado se sua contagem de referência for maior que 0 ou se ele for um item inserido.  
  
##  <a name="islinkeditem"></a>  COleServerItem::IsLinkedItem  
 Chame essa função para ver se o item OLE é um item vinculado.  
  
```  
BOOL IsLinkedItem() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item for um item vinculado; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um item está vinculado se o item é válido e não é retornado na lista de documentos de itens inseridos. Um item vinculado pode ou não pode ser conectado a um contêiner.  
  
 É comum usar a mesma classe para os itens vinculados e incorporados. `IsLinkedItem` permite que você faça com que itens vinculados se comportam de maneira diferente de itens inseridos, embora muitas vezes o código é comum.  
  
##  <a name="m_sizeextent"></a>  COleServerItem::m_sizeExtent  
 Esse membro informa ao servidor quanto o objeto é visível no documento contêiner.  
  
```  
CSize m_sizeExtent;  
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão de [OnSetExtent](#onsetextent) define esse membro.  
  
##  <a name="notifychanged"></a>  COleServerItem::NotifyChanged  
 Chame essa função depois que o item vinculado foi alterado.  
  
```  
void NotifyChanged(DVASPECT nDrawAspect = DVASPECT_CONTENT);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nDrawAspect*  
 Um valor de enumeração DVASPECT que indica qual aspecto do item OLE foi alterado. Esse parâmetro pode ter qualquer um dos seguintes valores:  
  
- Item DVASPECT_CONTENT é representado de forma que ele pode ser exibido como um objeto inserido dentro do seu contêiner.  
  
- DVASPECT_THUMBNAIL Item será renderizado em uma representação "em miniatura" para que ele pode ser exibido em uma ferramenta de procura.  
  
- Item DVASPECT_ICON é representado por um ícone.  
  
- Item DVASPECT_DOCPRINT é representada como se fosse imprimível usando o comando Imprimir no menu arquivo.  
  
### <a name="remarks"></a>Comentários  
 Se um item de contêiner é vinculado ao documento com um link automático, o item é atualizado para refletir as alterações. Em aplicativos de contêiner escritos usando a biblioteca Microsoft Foundation Class [COleClientItem::OnChange](../../mfc/reference/coleclientitem-class.md#onchange) é chamado em resposta.  
  
##  <a name="ondoverb"></a>  COleServerItem::OnDoVerb  
 Chamado pelo framework para executar o verbo especificado.  
  
```  
virtual void OnDoVerb(LONG iVerb);
```  
  
### <a name="parameters"></a>Parâmetros  
 *iVerb*  
 Especifica o verbo a ser executado. Ele pode ser qualquer um dos seguintes:  
  
|Valor|Significado|Símbolo|  
|-----------|-------------|------------|  
|0|Verbo primário|OLEIVERB_PRIMARY|  
|1|Verbo secundário|(Nenhum)|  
|- 1|Item de exibição para edição|OLEIVERB_SHOW|  
|- 2|Editar item na janela separada|OLEIVERB_OPEN|  
|- 3|Ocultar o item|OLEIVERB_HIDE|  
  
 O valor de-1 normalmente é um alias para outro verbo. Se não há suporte para a edição aberto, -2 tem o mesmo efeito que -1. Para obter valores adicionais, consulte [IOleObject:: DoVerb](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb) no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Se o aplicativo de contêiner foi escrito com a biblioteca Microsoft Foundation Class, essa função é chamada quando o [COleClientItem::Activate](../../mfc/reference/coleclientitem-class.md#activate) função de membro de correspondente `COleClientItem` objeto é chamado. A implementação padrão chama o [OnShow](#onshow) se o verbo primário ou OLEIVERB_SHOW for especificado, de função de membro [AoAbrir](#onopen) se o verbo secundário ou OLEIVERB_OPEN for especificado, e [OnHide ](#onhide) se OLEIVERB_HIDE for especificado. A implementação padrão chama `OnShow` se *iVerb* não é um dos verbos listados acima.  
  
 Substitua essa função se suas verbo primário não mostrar o item. Por exemplo, se o item for uma gravação de som e sua verbo primário é Play, você não precisa exibir o aplicativo de servidor para executar o item.  
  
 Para obter mais informações, consulte [IOleObject:: DoVerb](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb) no SDK do Windows.  
  
##  <a name="ondraw"></a>  COleServerItem::OnDraw  
 Chamado pelo framework para renderizar o item OLE em um metarquivo.  
  
```  
virtual BOOL OnDraw(
    CDC* pDC,  
    CSize& rSize) = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDC*  
 Um ponteiro para o [CDC](../../mfc/reference/cdc-class.md) objeto no qual desenhar o item. O contexto de exibição é conectado automaticamente ao contexto de exibição de atributo para que você possa chamar funções de atributo, embora isso tornaria o metarquivo específicos do dispositivo.  
  
 *rSize*  
 Tamanho, em unidades HIMETRIC, no qual desenhar o metarquivo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item foi desenhado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A representação de metarquivo do item OLE é usada para exibir o item no aplicativo de contêiner. Se o aplicativo de contêiner foi escrito com a biblioteca Microsoft Foundation Class, metarquivo é usado pelas [desenhar](../../mfc/reference/coleclientitem-class.md#draw) função de membro de correspondente [COleClientItem](../../mfc/reference/coleclientitem-class.md) objeto. Não há nenhuma implementação padrão. Você deve substituir essa função para desenhar o item no contexto de dispositivo especificado.  
  
##  <a name="ondrawex"></a>  COleServerItem::OnDrawEx  
 Chamado pelo framework para todos os desenhos.  
  
```  
virtual BOOL OnDrawEx(
    CDC* pDC,  
    DVASPECT nDrawAspect,  
    CSize& rSize);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDC*  
 Um ponteiro para o [CDC](../../mfc/reference/cdc-class.md) objeto no qual desenhar o item. O controlador de domínio é conectado automaticamente ao atributo de controlador de domínio para que você possa chamar funções de atributo, embora isso tornaria o metarquivo específicos do dispositivo.  
  
 *nDrawAspect*  
 Um valor de enumeração DVASPECT. Esse parâmetro pode ter qualquer um dos seguintes valores:  
  
- Item DVASPECT_CONTENT é representado de forma que ele pode ser exibido como um objeto inserido dentro do seu contêiner.  
  
- DVASPECT_THUMBNAIL Item será renderizado em uma representação "em miniatura" para que ele pode ser exibido em uma ferramenta de procura.  
  
- Item DVASPECT_ICON é representado por um ícone.  
  
- Item DVASPECT_DOCPRINT é representada como se fosse imprimível usando o comando Imprimir no menu arquivo.  
  
 *rSize*  
 Tamanho do item em unidades HIMETRIC.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item foi desenhado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão chama `OnDraw` quando DVASPECT é igual a DVASPECT_CONTENT; caso contrário, ele falhará.  
  
 Substitua essa função para fornecer dados de apresentação para aspectos que não seja DVASPECT_CONTENT como DVASPECT_ICON ou DVASPECT_THUMBNAIL.  
  
##  <a name="ongetclipboarddata"></a>  COleServerItem::OnGetClipboardData  
 Chamado pelo framework para obter um `COleDataSource` objeto que contém todos os dados devem ser colocados na área de transferência por uma chamada para o [CopyToClipboard](#copytoclipboard) função de membro.  
  
```  
virtual COleDataSource* OnGetClipboardData(
    BOOL bIncludeLink,  
    LPPOINT lpOffset,  
    LPSIZE lpSize);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bIncludeLink*  
 Defina isso como TRUE se os dados de link devem ser copiados para a área de transferência. Defina isso como FALSE se o servidor de aplicativo não dá suporte a links.  
  
 *lpOffset*  
 O deslocamento do cursor do mouse em relação à origem do objeto em pixels.  
  
 *lpSize*  
 O tamanho do objeto em pixels.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [COleDataSource](../../mfc/reference/coledatasource-class.md) objeto que contém os dados da área de transferência.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função chama [GetClipboardData](#getclipboarddata).  
  
##  <a name="ongetextent"></a>  COleServerItem::OnGetExtent  
 Chamado pelo framework para recuperar o tamanho, em unidades HIMETRIC, do item OLE.  
  
```  
virtual BOOL OnGetExtent(
    DVASPECT nDrawAspect,  
    CSize& rSize);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nDrawAspect*  
 Especifica o aspecto do item OLE cujos limites devem ser recuperadas. Esse parâmetro pode ter qualquer um dos seguintes valores:  
  
- Item DVASPECT_CONTENT é representado de forma que ele pode ser exibido como um objeto inserido dentro do seu contêiner.  
  
- DVASPECT_THUMBNAIL Item será renderizado em uma representação "em miniatura" para que ele pode ser exibido em uma ferramenta de procura.  
  
- Item DVASPECT_ICON é representado por um ícone.  
  
- Item DVASPECT_DOCPRINT é representada como se fosse imprimível usando o comando Imprimir no menu arquivo.  
  
 *rSize*  
 Referência a um `CSize` objeto que receberá o tamanho do item OLE.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se o aplicativo de contêiner foi escrito com a biblioteca Microsoft Foundation Class, essa função é chamada quando o [GetExtent](../../mfc/reference/coleclientitem-class.md#getextent) função de membro de correspondente `COleClientItem` objeto é chamado. A implementação padrão não faz nada. Você deve implementá-la para si mesmo. Substitua essa função se você quiser executar um processamento especial ao manipular uma solicitação para o tamanho do item OLE.  
  
##  <a name="onhide"></a>  COleServerItem::OnHide  
 Chamado pelo framework para ocultar o item OLE.  
  
```  
virtual void OnHide();
```  
  
### <a name="remarks"></a>Comentários  
 A padrão chama `COleServerDoc::OnShowDocument( FALSE )`. A função também notifica o contêiner que o item OLE foi oculto. Substitua essa função se você quiser executar um processamento especial ao ocultar um item OLE.  
  
##  <a name="oninitfromdata"></a>  COleServerItem::OnInitFromData  
 Chamado pelo framework para inicializar um item OLE usando o conteúdo do *pDataObject*.  
  
```  
virtual BOOL OnInitFromData(
    COleDataObject* pDataObject,  
    BOOL bCreation);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDataObject*  
 Ponteiro para um objeto de dados OLE que contém os dados em vários formatos para inicializar o item OLE.  
  
 *bCreation*  
 TRUE se a função é chamada para inicializar um item OLE que está sendo criado recentemente por um aplicativo de contêiner. FALSE se a função é chamada para substituir o conteúdo de um item OLE já existente.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se *bCreation* for TRUE, essa função é chamada se um contêiner implementa Inserir novo objeto com base na seleção atual. Os dados selecionados são usados ao criar o novo item OLE. Por exemplo, quando selecionar um intervalo de células em um programa de planilha e, em seguida, usando o novo objeto inserir para criar um gráfico com base nos valores no intervalo selecionado. A implementação padrão não faz nada. Substituir essa função para escolher um formato aceitável oferecida pelo *pDataObject* e inicializar o item OLE com base nos dados fornecidos. Isso é um avançado substituível.  
  
 Para obter mais informações, consulte [IOleObject::InitFromData](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-initfromdata) no SDK do Windows.  
  
##  <a name="onopen"></a>  COleServerItem::OnOpen  
 Chamado pelo framework para exibir o item OLE em uma instância separada do aplicativo de servidor, em vez de em vigor.  
  
```  
virtual void OnOpen();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão ativa a primeira janela de quadro exibindo o documento que contém o item OLE; Se o aplicativo for um minisservidor, a implementação padrão mostra a janela principal. A função também notifica o contêiner que o item OLE foi aberto.  
  
 Substitua essa função se você quiser executar um processamento especial ao abrir um item OLE. Isso é especialmente comum com os itens vinculados em que você deseja definir a seleção para o link quando ele é aberto.  
  
 Para obter mais informações, consulte [IOleClientSite::OnShowWindow](/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-onshowwindow) no SDK do Windows.  
  
##  <a name="onqueryupdateitems"></a>  COleServerItem::OnQueryUpdateItems  
 Chamado pelo framework para determinar se os itens vinculados no documento atual do servidor estão desatualizados.  
  
```  
virtual BOOL OnQueryUpdateItems();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o documento tem itens que precisam de atualizações; 0 se todos os itens estão atualizados.  
  
### <a name="remarks"></a>Comentários  
 Um item está desatualizado, se seu documento de origem foi alterado, mas o item vinculado não foi atualizado para refletir as alterações no documento.  
  
##  <a name="onrenderdata"></a>  COleServerItem::OnRenderData  
 Chamado pelo framework para recuperar dados no formato especificado.  
  
```  
virtual BOOL OnRenderData(
    LPFORMATETC lpFormatEtc,  
    LPSTGMEDIUM lpStgMedium);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpFormatEtc*  
 Aponta para o [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura especificando o formato no qual as informações são solicitadas.  
  
 *lpStgMedium*  
 Aponta para um [STGMEDIUM](/windows/desktop/api/objidl/ns-objidl-tagstgmedium) estrutura na qual os dados deve ser retornado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O formato especificado é um colocado anteriormente na `COleDataSource` do objeto usando o [DelayRenderData](../../mfc/reference/coledatasource-class.md#delayrenderdata) ou [DelayRenderFileData](../../mfc/reference/coledatasource-class.md#delayrenderfiledata) a função de membro para renderização atrasada. A implementação padrão dessa função chama [OnRenderFileData](#onrenderfiledata) ou [OnRenderGlobalData](#onrenderglobaldata), respectivamente, se a mídia de armazenamento fornecido é um arquivo ou memória. Se nenhum desses formatos for fornecido, a implementação padrão retorna 0 e não faz nada.  
  
 Se *lpStgMedium*-> *tymed* é TYMED_NULL, o STGMEDIUM deve ser alocado e preenchido conforme especificado por *lpFormatEtc -> tymed*. Se não for TYMED_NULL, o STGMEDIUM deve ser preenchido em vigor com os dados.  
  
 Isso é um avançado substituível. Substitua essa função para fornecer seus dados no formato solicitado e média. Dependendo de seus dados, você talvez queira substituir uma das outras versões dessa função em vez disso. Se os dados forem pequenos e com o tamanho fixo, substituir `OnRenderGlobalData`. Se os dados estiverem em um arquivo ou é de tamanho variável, substituir `OnRenderFileData`.  
  
 Para obter mais informações, consulte [IDataObject::](/windows/desktop/api/objidl/nf-objidl-idataobject-getdata), [STGMEDIUM](/windows/desktop/api/objidl/ns-objidl-tagstgmedium), [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc), e [TYMED](/windows/desktop/api/objidl/ne-objidl-tagtymed) no SDK do Windows.  
  
##  <a name="onrenderfiledata"></a>  COleServerItem::OnRenderFileData  
 Chamado pelo framework para recuperar dados no formato especificado quando a mídia de armazenamento é um arquivo.  
  
```  
virtual BOOL OnRenderFileData(
    LPFORMATETC lpFormatEtc,  
    CFile* pFile);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpFormatEtc*  
 Aponta para o [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura especificando o formato no qual as informações são solicitadas.  
  
 *pFile*  
 Aponta para um `CFile` objeto no qual os dados a serem renderizados.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O formato especificado é um colocado anteriormente na `COleDataSource` do objeto usando o [DelayRenderData](../../mfc/reference/coledatasource-class.md#delayrenderdata) a função de membro para renderização atrasada. A implementação padrão dessa função simplesmente retorna FALSE.  
  
 Isso é um avançado substituível. Substitua essa função para fornecer seus dados no formato solicitado e média. Dependendo de seus dados, você talvez queira substituir uma das outras versões dessa função em vez disso. Se você quiser manipular vários meios de armazenamento, substitua [OnRenderData](#onrenderdata). Se os dados estiverem em um arquivo ou é de tamanho variável, substitua [OnRenderFileData](#onrenderfiledata).  
  
 Para obter mais informações, consulte [IDataObject::](/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) e [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) no SDK do Windows.  
  
##  <a name="onrenderglobaldata"></a>  COleServerItem::OnRenderGlobalData  
 Chamado pelo framework para recuperar dados no formato especificado quando a mídia de armazenamento especificado é memória global.  
  
```  
virtual BOOL OnRenderGlobalData(
    LPFORMATETC lpFormatEtc,  
    HGLOBAL* phGlobal);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpFormatEtc*  
 Aponta para o [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura especificando o formato no qual as informações são solicitadas.  
  
 *phGlobal*  
 Aponta para um identificador para a memória global no qual os dados deve ser retornado. Se nenhuma memória foi alocada, esse parâmetro pode ser NULL.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O formato especificado é um colocado anteriormente na `COleDataSource` do objeto usando o [DelayRenderData](../../mfc/reference/coledatasource-class.md#delayrenderdata) a função de membro para renderização atrasada. A implementação padrão dessa função simplesmente retorna FALSE.  
  
 Se *phGlobal* for NULL, e em seguida, um novo HGLOBAL deve ser alocado e retornado na *phGlobal*. Caso contrário, o HGLOBAL especificado por *phGlobal* deve ser preenchido com os dados. A quantidade de dados colocados no HGLOBAL não deve exceder o tamanho atual do bloco de memória. Além disso, o bloco não pode ser realocado para um tamanho maior.  
  
 Isso é um avançado substituível. Substitua essa função para fornecer seus dados no formato solicitado e média. Dependendo de seus dados, você talvez queira substituir uma das outras versões dessa função em vez disso. Se você quiser manipular vários meios de armazenamento, substitua [OnRenderData](#onrenderdata). Se os dados estiverem em um arquivo ou é de tamanho variável, substitua [OnRenderFileData](#onrenderfiledata).  
  
 Para obter mais informações, consulte [IDataObject::](/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) e [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) no SDK do Windows.  
  
##  <a name="onsetcolorscheme"></a>  COleServerItem::OnSetColorScheme  
 Chamado pelo framework para especificar uma paleta de cores a ser usada ao editar o item OLE.  
  
```  
virtual BOOL OnSetColorScheme(const LOGPALETTE* lpLogPalette);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpLogPalette*  
 Ponteiro para um Windows [LOGPALETTE](/windows/desktop/api/wingdi/ns-wingdi-taglogpalette) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a paleta de cores é usada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se o aplicativo de contêiner foi escrito usando a biblioteca Microsoft Foundation Class, essa função é chamada quando o [IOleObject::SetColorScheme](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setcolorscheme) função de correspondente `COleClientItem` objeto é chamado. A implementação padrão retorna falso. Substitua essa função se você quiser usar a paleta recomendada. O aplicativo de servidor não é necessário usar a paleta sugerida.  
  
 Para obter mais informações, consulte [IOleObject::SetColorScheme](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setcolorscheme) no SDK do Windows.  
  
##  <a name="onsetdata"></a>  COleServerItem::OnSetData  
 Chamado pelo framework para substituir os dados do item OLE com os dados especificados.  
  
```  
virtual BOOL OnSetData(
    LPFORMATETC lpFormatEtc,  
    LPSTGMEDIUM lpStgMedium,  
    BOOL bRelease);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpFormatEtc*  
 Ponteiro para um [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura especificando o formato dos dados.  
  
 *lpStgMedium*  
 Ponteiro para um [STGMEDIUM](/windows/desktop/api/objidl/ns-objidl-tagstgmedium) estrutura na qual os dados residem.  
  
 *bRelease*  
 Indica que é proprietária da mídia de armazenamento depois de concluir a chamada de função. O chamador decide quem é responsável por liberar os recursos alocados em nome da mídia de armazenamento. O chamador faz isso definindo *bRelease*. Se *bRelease* é diferente de zero, o item de servidor assume a propriedade, liberando a mídia quando ele tiver terminado de usá-lo. Quando *bRelease* é 0, o chamador retém a propriedade e o item do servidor pode usar a mídia de armazenamento apenas para a duração da chamada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O item do servidor não assumir a propriedade dos dados até que ele tenha obtido-lo com êxito. Ou seja, ele não apropriar-se ele retorna 0. Se a fonte de dados assume a propriedade, ela libera a mídia de armazenamento por meio da chamada a [ReleaseStgMedium](/windows/desktop/api/ole2/nf-ole2-releasestgmedium) função.  
  
 A implementação padrão não faz nada. Substitua essa função para substituir os dados do item OLE com os dados especificados. Isso é um avançado substituível.  
  
 Para obter mais informações, consulte [STGMEDIUM](/windows/desktop/api/objidl/ns-objidl-tagstgmedium), [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc), e [ReleaseStgMedium](/windows/desktop/api/ole2/nf-ole2-releasestgmedium) no SDK do Windows.  
  
##  <a name="onsetextent"></a>  COleServerItem::OnSetExtent  
 Chamado pelo framework para informar ao item OLE quanto espaço está disponível para ele no documento contêiner.  
  
```  
virtual BOOL OnSetExtent(
    DVASPECT nDrawAspect,  
    const CSize& size);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nDrawAspect*  
 Especifica o aspecto do item OLE cujos limites estão sendo especificados. Esse parâmetro pode ter qualquer um dos seguintes valores:  
  
- Item DVASPECT_CONTENT é representado de forma que ele pode ser exibido como um objeto inserido dentro do seu contêiner.  
  
- DVASPECT_THUMBNAIL Item será renderizado em uma representação "em miniatura" para que ele pode ser exibido em uma ferramenta de procura.  
  
- Item DVASPECT_ICON é representado por um ícone.  
  
- Item DVASPECT_DOCPRINT é representada como se fosse imprimível usando o comando Imprimir no menu arquivo.  
  
 *size*  
 Um [CSize](../../atl-mfc-shared/reference/csize-class.md) estrutura especificando o novo tamanho do item OLE.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se o aplicativo de contêiner foi escrito com a biblioteca Microsoft Foundation Class, essa função é chamada quando o [SetExtent](../../mfc/reference/coleclientitem-class.md#setextent) função de membro de correspondente `COleClientItem` objeto é chamado. Os conjuntos de implementação do padrão de [m_sizeExtent](#m_sizeextent) membro para o tamanho especificado se *nDrawAspect* é DVASPECT_CONTENT; caso contrário, retornará 0. Substitua esta função para executar um processamento especial quando você alterar o tamanho do item.  
  
##  <a name="onshow"></a>  COleServerItem::OnShow  
 Chamado pelo framework para instruir o aplicativo de servidor para exibir o item OLE em vigor.  
  
```  
virtual void OnShow();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função normalmente é chamada quando o usuário do aplicativo recipiente cria um item ou executa um verbo, como editar, que exige que o item a ser mostrado. A implementação padrão tenta fazer a ativação in-loco. Se isso falhar, a função chamará o `OnOpen` a função de membro para exibir o item OLE em uma janela separada.  
  
 Substitua essa função se você quiser executar o processamento especial quando um item OLE é mostrado.  
  
##  <a name="onupdate"></a>  COleServerItem::OnUpdate  
 Chamado pelo framework quando um item foi modificado.  
  
```  
virtual void OnUpdate(
    COleServerItem* pSender,  
    LPARAM lHint,  
    CObject* pHint,  
    DVASPECT nDrawAspect);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pSender*  
 Ponteiro para o item que modificou o documento. Pode ser NULL.  
  
 *lHint*  
 Contém informações sobre a modificação.  
  
 *pHint*  
 Ponteiro para um objeto que armazena informações sobre a modificação.  
  
 *nDrawAspect*  
 Um valor de enumeração DVASPECT. Esse parâmetro pode ter qualquer um dos seguintes valores:  
  
- Item DVASPECT_CONTENT é representado de forma que ele pode ser exibido como um objeto inserido dentro do seu contêiner.  
  
- DVASPECT_THUMBNAIL Item será renderizado em uma representação "em miniatura" para que ele pode ser exibido em uma ferramenta de procura.  
  
- Item DVASPECT_ICON é representado por um ícone.  
  
- Item DVASPECT_DOCPRINT é representada como se fosse imprimível usando o comando Imprimir no menu arquivo.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão chama [NotifyChanged](#notifychanged), independentemente do remetente ou dica.  
  
##  <a name="onupdateitems"></a>  COleServerItem::OnUpdateItems  
 Chamado pelo framework para atualizar todos os itens no documento do servidor.  
  
```  
virtual void OnUpdateItems();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão chama [UpdateLink](../../mfc/reference/coleclientitem-class.md#updatelink) para todos os `COleClientItem` objetos no documento.  
  
##  <a name="setitemname"></a>  COleServerItem::SetItemName  
 Chame essa função quando você cria um item vinculado para definir seu nome.  
  
```  
void SetItemName(LPCTSTR lpszItemName);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszItemName*  
 Ponteiro para o novo nome do item.  
  
### <a name="remarks"></a>Comentários  
 O nome deve ser exclusivo dentro do documento. Quando um aplicativo de servidor é chamado para editar um item vinculado, o aplicativo usa esse nome para localizar o item. Você não precisa chamar essa função para itens inseridos.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC HIERSVR](../../visual-cpp-samples.md)   
 [Classe CDocItem](../../mfc/reference/cdocitem-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)   
 [Classe COleServerDoc](../../mfc/reference/coleserverdoc-class.md)   
 [Classe COleTemplateServer](../../mfc/reference/coletemplateserver-class.md)
