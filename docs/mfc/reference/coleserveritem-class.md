---
title: Classe da classe derivada COleServerItem | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
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
- servers, OLE
- OLE server applications, managing server documents
- OLE server applications, server interfaces
- OLE server documents
- COleServerItem class
ms.assetid: 80256df6-3888-4256-944b-787d4b2e6b0d
caps.latest.revision: 23
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 49dd8cc258ebf96c91ac8ff1190f9a830b6bb5ec
ms.lasthandoff: 02/25/2017

---
# <a name="coleserveritem-class"></a>Classe da classe derivada COleServerItem
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
|[COleServerItem::CopyToClipboard](#copytoclipboard)|Copia o item para a área de transferência.|  
|[COleServerItem::DoDragDrop](#dodragdrop)|Executa uma operação de arrastar e soltar.|  
|[COleServerItem::GetClipboardData](#getclipboarddata)|Obtém a fonte de dados para uso na transferência de dados (arrastar e soltar ou área de transferência).|  
|[COleServerItem::GetDocument](#getdocument)|Retorna o documento de servidor que contém o item.|  
|[COleServerItem::GetEmbedSourceData](#getembedsourcedata)|Obtém o **CF_EMBEDSOURCE** dados para um item OLE.|  
|[COleServerItem::GetItemName](#getitemname)|Retorna o nome do item. Usado somente para itens vinculados.|  
|[COleServerItem::GetLinkSourceData](#getlinksourcedata)|Obtém o `CF_LINKSOURCE` dados para um item OLE.|  
|[COleServerItem::GetObjectDescriptorData](#getobjectdescriptordata)|Obtém o **CF_OBJECTDESCRIPTOR** dados para um item OLE.|  
|[COleServerItem::IsConnected](#isconnected)|Indica se o item está atualmente conectado a um contêiner do active.|  
|[COleServerItem::IsLinkedItem](#islinkeditem)|Indica se o item representa um item OLE vinculado.|  
|[COleServerItem::NotifyChanged](#notifychanged)|Atualiza todos os contêineres com atualização automática de link.|  
|[COleServerItem::OnDoVerb](#ondoverb)|Chamado para executar um verbo.|  
|[COleServerItem::OnDraw](#ondraw)|Chamado quando o contêiner solicita para desenhar o item; implementação necessários.|  
|[COleServerItem::OnDrawEx](#ondrawex)|Chamado para o desenho do item especializados.|  
|[COleServerItem::OnGetClipboardData](#ongetclipboarddata)|Chamado pela estrutura para obter os dados que seriam copiados para a área de transferência.|  
|[COleServerItem::OnGetExtent](#ongetextent)|Chamado pela estrutura para recuperar o tamanho do item OLE.|  
|[COleServerItem::OnInitFromData](#oninitfromdata)|Chamado pela estrutura para inicializar um item OLE usando o conteúdo do objeto de transferência de dados especificado.|  
|[COleServerItem::OnQueryUpdateItems](#onqueryupdateitems)|Chamado para determinar se os itens vinculados precisam de atualização.|  
|[COleServerItem::OnRenderData](#onrenderdata)|Recupera dados como parte da renderização atrasada.|  
|[COleServerItem::OnRenderFileData](#onrenderfiledata)|Recupera dados em uma `CFile` objeto como parte da renderização atrasada.|  
|[COleServerItem::OnRenderGlobalData](#onrenderglobaldata)|Recupera dados em um `HGLOBAL` como parte do processamento atrasado.|  
|[COleServerItem::OnSetColorScheme](#onsetcolorscheme)|Chamado para definir o esquema de cores do item.|  
|[COleServerItem::OnSetData](#onsetdata)|Chamado para definir os dados do item.|  
|[COleServerItem::OnSetExtent](#onsetextent)|Chamado pela estrutura para definir o tamanho do item OLE.|  
|[COleServerItem::OnUpdate](#onupdate)|Chamado quando uma parte do documento do item pertence é alterado.|  
|[COleServerItem::OnUpdateItems](#onupdateitems)|Chamado para atualizar o cache de apresentação de todos os itens no documento do servidor.|  
|[COleServerItem::SetItemName](#setitemname)|Define o nome do item. Usado somente para itens vinculados.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleServerItem::GetDataSource](#getdatasource)|Obtém o objeto usado para armazenar os formatos de conversão.|  
|[COleServerItem::OnHide](#onhide)|Chamado pela estrutura para ocultar o item OLE.|  
|[COleServerItem::OnOpen](#onopen)|Chamado pela estrutura para exibir o item OLE em sua própria janela de nível superior.|  
|[COleServerItem::OnShow](#onshow)|Chamado quando o contêiner solicita para mostrar o item.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleServerItem::m_sizeExtent](#m_sizeextent)|Informa o servidor quanto do item OLE é visível.|  
  
## <a name="remarks"></a>Comentários  
 Um item vinculado pode representar parte ou todo um documento do servidor. Um item inserido sempre representa um documento de todo o servidor.  
  
 O `COleServerItem` classe define várias funções de membro substituível chamadas pelas bibliotecas de vínculo dinâmico do sistema OLE (DLLs), geralmente em resposta a solicitações do aplicativo de contêiner. Essas funções de membro que o aplicativo de contêiner manipular o item indiretamente de várias maneiras, como exibi-lo, executando seus verbos ou recuperar seus dados em vários formatos.  
  
 Usar `COleServerItem`, derive uma classe dele e implementar o [OnDraw](#ondraw) e [Serialize](../../mfc/reference/cobject-class.md#serialize) funções de membro. O `OnDraw` função fornece a representação de metarquivo de um item, permitindo que ela seja exibida quando um aplicativo de contêiner é aberto um documento composto. O `Serialize` função do `CObject` fornece a representação nativa de um item, permitindo que um item incorporado a ser transferido entre os aplicativos de servidor e um contêiner. [OnGetExtent](#ongetextent) fornece o tamanho do item no contêiner, habilitando o contêiner para o item de tamanho natural.  
  
 Para obter mais informações sobre servidores e tópicos relacionados, consulte o artigo [servidores: Implementando um servidor](../../mfc/servers-implementing-a-server.md) e "Criando um aplicativo de contêiner/servidor", no artigo [contêineres: recursos avançados](../../mfc/containers-advanced-features.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CDocItem](../../mfc/reference/cdocitem-class.md)  
  
 `COleServerItem`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  
  
##  <a name="addotherclipboarddata"></a>COleServerItem::AddOtherClipboardData  
 Chame essa função para colocar os formatos de apresentação e a conversão para o item OLE especificado na `COleDataSource` objeto.  
  
```  
void AddOtherClipboardData(COleDataSource* pDataSource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDataSource`  
 Ponteiro para o `COleDataSource` do objeto no qual os dados devem ser colocados.  
  
### <a name="remarks"></a>Comentários  
 Você deve ter implementado a [OnDraw](#ondraw) função de membro para fornecer o formato de apresentação (uma imagem de metarquivo) para o item. Para oferecer suporte a outros formatos de conversão, registrá-los usando o [COleDataSource](../../mfc/reference/coledatasource-class.md) objeto retornado por [GetDataSource](#getdatasource) e substituir o [OnRenderData](#onrenderdata) a função de membro para fornecer dados nos formatos que você deseja oferecer suporte.  
  
##  <a name="coleserveritem"></a>COleServerItem::COleServerItem  
 Constrói um `COleServerItem` do objeto e o adiciona à coleção do documento do servidor de itens de documentos.  
  
```  
COleServerItem(
    COleServerDoc* pServerDoc,  
    BOOL bAutoDelete);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pServerDoc`  
 Ponteiro para o documento que conterá o novo item.  
  
 `bAutoDelete`  
 Sinalizador que indica se o objeto pode ser excluído quando um link para ele é liberado. Defina-o como **FALSE** se o `COleServerItem` objeto é uma parte integral de dados do documento que você deve excluir. Defina-o como **TRUE** se o objeto é uma estrutura secundária usada para identificar um intervalo de dados do documento que podem ser excluídos pelo framework.  
  
##  <a name="copytoclipboard"></a>COleServerItem::CopyToClipboard  
 Chame essa função para copiar o item OLE para a área de transferência.  
  
```  
void CopyToClipboard(BOOL bIncludeLink = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bIncludeLink`  
 Defina-o como **TRUE** se vincular dados devem ser copiados para a área de transferência. Defina-o como **FALSE** se o aplicativo de servidor não oferece suporte a links.  
  
### <a name="remarks"></a>Comentários  
 A função usa o [OnGetClipboardData](#ongetclipboarddata) a função de membro para criar um [COleDataSource](../../mfc/reference/coledatasource-class.md) objeto contendo os dados do item OLE os formatos com suporte. A função coloca o `COleDataSource` objeto na área de transferência usando o [COleDataSource::SetClipboard](../../mfc/reference/coledatasource-class.md#setclipboard) função. O `COleDataSource` objeto inclui dados nativos do item e sua representação em `CF_METAFILEPICT` formato, bem como dados em formatos de conversão escolher dar suporte. Você deve ter implementado [Serialize](../../mfc/reference/cobject-class.md#serialize) e [OnDraw](#ondraw) para essa função de membro trabalhar.  
  
##  <a name="dodragdrop"></a>COleServerItem::DoDragDrop  
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
 Retângulo do item na tela, em pixels, em relação a área do cliente.  
  
 `ptOffset`  
 O deslocamento do `lpItemRect` onde a posição do mouse estava na hora de arrastar.  
  
 `bIncludeLink`  
 Defina-o como **TRUE** se vincular dados devem ser copiados para a área de transferência. Defina-o como **FALSE** se seu aplicativo não oferece suporte a links.  
  
 `dwEffects`  
 Determina os efeitos que permitirá que a fonte na operação de arrastar (uma combinação de copiar, mover e Link).  
  
 `lpRectStartDrag`  
 Ponteiro para o retângulo que define onde realmente começa a arrastar. Para obter mais informações, consulte a seção Comentários a seguir.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor da enumeração `DROPEFFECT`. Se for `DROPEFFECT_MOVE`, os dados originais devem ser removidos.  
  
### <a name="remarks"></a>Comentários  
 A operação de arrastar e soltar não será iniciado imediatamente. Ele aguarda até que o cursor do mouse sai do retângulo especificado por `lpRectStartDrag` ou até que um número especificado de milissegundos tiver passado. Se `lpRectStartDrag` é **nulo**, um retângulo padrão é usado para que o arrastar começa quando o cursor do mouse se move de um pixel.  
  
 O tempo de atraso é especificado pela configuração da chave do registro. Você pode alterar o tempo de atraso chamando [CWinApp::WriteProfileString](../../mfc/reference/cwinapp-class.md#writeprofilestring) ou [CWinApp::WriteProfileInt](../../mfc/reference/cwinapp-class.md#writeprofileint). Se você não especificar o tempo de espera, é usado um valor padrão de 200 milissegundos. Tempo de atraso de arrastar é armazenado da seguinte maneira:  
  
-   Tempo de atraso de arraste do Windows NT é armazenado em HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\NT\CurrentVersion\IniFileMapping\win.ini\Windows\DragDelay.  
  
-   Tempo de atraso de arraste do Windows 3. x é armazenado em arquivos WIN. Arquivo INI, em [} seção Windows.  
  
-   Tempo de espera do Windows 95/98 arrastar é armazenado em uma versão em cache do WIN. INI.  
  
 Para obter mais informações sobre como arrastar informações de atraso são armazenadas no registro ou o. O arquivo INI, consulte [WriteProfileString](http://msdn.microsoft.com/library/windows/desktop/ms725504) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getclipboarddata"></a>COleServerItem::GetClipboardData  
 Chame essa função para preencher especificado [COleDataSource](../../mfc/reference/coledatasource-class.md) objeto com todos os dados que seriam copiados para a área de transferência se você chamou [CopyToClipboard](#copytoclipboard) (os mesmos dados também serão transferidos se tiver chamado [DoDragDrop](#dodragdrop)).  
  
```  
void GetClipboardData(
    COleDataSource* pDataSource,  
    BOOL bIncludeLink = FALSE,  
    LPPOINT lpOffset = NULL,  
    LPSIZE lpSize = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDataSource`  
 Ponteiro para o `COleDataSource` objeto que receberá os dados do item OLE em todos os formatos com suporte.  
  
 `bIncludeLink`  
 **TRUE** se vincular dados devem ser copiados para a área de transferência. **FALSE** se o aplicativo de servidor não oferece suporte a links.  
  
 `lpOffset`  
 O deslocamento, em pixels, do cursor do mouse em relação à origem do objeto.  
  
 `lpSize`  
 O tamanho do objeto em pixels.  
  
### <a name="remarks"></a>Comentários  
 Essa função chama o [GetEmbedSourceData](#getembedsourcedata) a função de membro para obter os dados nativos para o item OLE e chama o [AddOtherClipboardData](#addotherclipboarddata) suporte para a função de membro para obter o formato de apresentação e quaisquer formatos de conversão. Se `bIncludeLink` é **TRUE**, também chama a função [GetLinkSourceData](#getlinksourcedata) para obter os dados de link para o item.  
  
 Substituir essa função se você quiser colocar formatos em uma `COleDataSource` objeto antes ou depois dos formatos fornecidos pelo `CopyToClipboard`.  
  
##  <a name="getdatasource"></a>COleServerItem::GetDataSource  
 Chame essa função para obter o [COleDataSource](../../mfc/reference/coledatasource-class.md) objeto usado para armazenar os formatos de conversão que suporta o aplicativo do servidor.  
  
```  
COleDataSource* GetDataSource();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `COleDataSource` objeto usado para armazenar os formatos de conversão.  
  
### <a name="remarks"></a>Comentários  
 Se desejar que o aplicativo de servidor para oferecer uma variedade de formatos de dados durante a transferência de dados operações, registre os formatos com o `COleDataSource` objeto retornado por essa função. Por exemplo, se você desejar fornecer um **CF_TEXT** representação do item OLE para as operações de arrastar e soltar ou área de transferência, você deve registrar o formato com a `COleDataSource` objeto essa função retorna e depois substitui o **OnRenderXxxData** a função de membro para fornecer os dados.  
  
##  <a name="getdocument"></a>COleServerItem::GetDocument  
 Chame essa função para obter um ponteiro para o documento que contém o item.  
  
```  
COleServerDoc* GetDocument() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o documento que contém o item; **Nulo** se o item não for parte de um documento.  
  
### <a name="remarks"></a>Comentários  
 Isso permite o acesso ao documento do servidor que é passado como um argumento para o `COleServerItem` construtor.  
  
##  <a name="getembedsourcedata"></a>COleServerItem::GetEmbedSourceData  
 Chame essa função para obter o **CF_EMBEDSOURCE** dados para um item OLE.  
  
```  
void GetEmbedSourceData(LPSTGMEDIUM lpStgMedium);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpStgMedium`  
 Ponteiro para o [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) estrutura que receberá o **CF_EMBEDSOURCE** dados do item OLE.  
  
### <a name="remarks"></a>Comentários  
 Esse formato inclui dados nativos do item. Você deve ter implementado a `Serialize` a função de membro para esta função funcione corretamente.  
  
 O resultado, em seguida, pode ser adicionado a uma fonte de dados usando [COleDataSource::CacheData](../../mfc/reference/coledatasource-class.md#cachedata). Essa função é chamada automaticamente pelo [COleServerItem::OnGetClipboardData](#ongetclipboarddata).  
  
 Para obter mais informações, consulte [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getitemname"></a>COleServerItem::GetItemName  
 Chame essa função para obter o nome do item.  
  
```  
const CString& GetItemName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome do item.  
  
### <a name="remarks"></a>Comentários  
 Você normalmente chama essa função somente para itens vinculados.  
  
##  <a name="getlinksourcedata"></a>COleServerItem::GetLinkSourceData  
 Chame essa função para obter o `CF_LINKSOURCE` dados para um item OLE.  
  
```  
BOOL GetLinkSourceData(LPSTGMEDIUM lpStgMedium);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpStgMedium`  
 Ponteiro para o [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) estrutura que receberá o `CF_LINKSOURCE` dados do item OLE.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse formato inclui o CLSID que descreve o tipo de item OLE e as informações necessárias para localizar o documento que contém o item OLE.  
  
 O resultado, em seguida, pode ser adicionado a uma fonte de dados com [COleDataSource::CacheData](../../mfc/reference/coledatasource-class.md#cachedata). Essa função é chamada automaticamente pelo [OnGetClipboardData](#ongetclipboarddata).  
  
 Para obter mais informações, consulte [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getobjectdescriptordata"></a>COleServerItem::GetObjectDescriptorData  
 Chame essa função para obter o **CF_OBJECTDESCRIPTOR** dados para um item OLE.  
  
```  
void GetObjectDescriptorData(
    LPPOINT lpOffset,  
    LPSIZE lpSize,  
    LPSTGMEDIUM lpStgMedium);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpOffset`  
 Deslocamento do clique do mouse no canto superior esquerdo do item OLE. Pode ser **nulo**.  
  
 `lpSize`  
 Tamanho do item OLE. Pode ser **nulo**.  
  
 `lpStgMedium`  
 Ponteiro para o [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) estrutura que receberá o **CF_OBJECTDESCRIPTOR** dados do item OLE.  
  
### <a name="remarks"></a>Comentários  
 As informações são copiadas para o **STGMEDIUM** estrutura apontada por `lpStgMedium`. Esse formato inclui as informações necessárias para a caixa de diálogo Colar especial.  
  
 Para obter mais informações, consulte [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="isconnected"></a>COleServerItem::IsConnected  
 Chame essa função para ver se o item OLE está conectado.  
  
```  
BOOL IsConnected() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item está conectado; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um item OLE é considerado conectado se um ou mais contêineres têm referências ao item. Um item é conectado se sua contagem de referência é maior que 0 ou se é um item inserido.  
  
##  <a name="islinkeditem"></a>COleServerItem::IsLinkedItem  
 Chame essa função para ver se o item OLE é um item vinculado.  
  
```  
BOOL IsLinkedItem() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item for um item vinculado; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um item está vinculado se o item é válido e não é retornado na lista de documentos de itens inseridos. Um item vinculado pode ou não pode ser conectado a um contêiner.  
  
 É comum usar a mesma classe para itens vinculados e incorporados. `IsLinkedItem`permite que você faça itens vinculados se comportam diferentemente das itens incorporados, embora muitas vezes o código é comum.  
  
##  <a name="m_sizeextent"></a>COleServerItem::m_sizeExtent  
 Esse membro informa ao servidor quanto o objeto está visível no documento contêiner.  
  
```  
CSize m_sizeExtent;  
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão de [OnSetExtent](#onsetextent) define esse membro.  
  
##  <a name="notifychanged"></a>COleServerItem::NotifyChanged  
 Chame essa função depois que o item vinculado foi alterado.  
  
```  
void NotifyChanged(DVASPECT nDrawAspect = DVASPECT_CONTENT);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nDrawAspect`  
 Um valor a partir de `DVASPECT` enumeração que indica quais aspectos do item OLE foi alterado. Esse parâmetro pode ter qualquer um dos seguintes valores:  
  
- `DVASPECT_CONTENT`Item é representado de forma que ele pode ser exibido como um objeto incorporado dentro do seu contêiner.  
  
- `DVASPECT_THUMBNAIL`Item será renderizado em uma representação "em miniatura" para que ela possa ser exibida em uma ferramenta de procura.  
  
- `DVASPECT_ICON`Item é representado por um ícone.  
  
- `DVASPECT_DOCPRINT`Item é representado como se ela fosse impressa usando o comando Imprimir no menu arquivo.  
  
### <a name="remarks"></a>Comentários  
 Se um item de contêiner é vinculado ao documento com um vínculo automático, o item é atualizado para refletir as alterações. Em aplicativos de contêiner escritos usando a biblioteca Microsoft Foundation Class [COleClientItem::OnChange](../../mfc/reference/coleclientitem-class.md#onchange) é chamado em resposta.  
  
##  <a name="ondoverb"></a>COleServerItem::OnDoVerb  
 Chamado pela estrutura para executar o verbo especificado.  
  
```  
virtual void OnDoVerb(LONG iVerb);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iVerb`  
 Especifica o verbo a ser executado. Ele pode ser qualquer um dos seguintes:  
  
|Valor|Significado|Símbolo|  
|-----------|-------------|------------|  
|0|Verbo primário|`OLEIVERB_PRIMARY`|  
|1|Verbo secundário|(Nenhum)|  
|– 1|Item de exibição para edição|`OLEIVERB_SHOW`|  
|– 2|Editar item na janela separada|`OLEIVERB_OPEN`|  
|– 3|Ocultar item|`OLEIVERB_HIDE`|  
  
 O valor –&1; normalmente é um alias para outro verbo. Se não há suporte para a edição aberta, –&2; tem o mesmo efeito que –&1;. Para obter valores adicionais, consulte [IOleObject:: DoVerb](http://msdn.microsoft.com/library/windows/desktop/ms694508) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Se o aplicativo de contêiner foi escrito com a biblioteca Microsoft Foundation Class, essa função é chamada quando o [COleClientItem::Activate](../../mfc/reference/coleclientitem-class.md#activate) a função de membro de correspondente `COleClientItem` objeto é chamado. As chamadas de implementação padrão de [OnShow](#onshow) função do membro se o verbo primário ou `OLEIVERB_SHOW` for especificado, [AoAbrir](#onopen) se o verbo secundário ou `OLEIVERB_OPEN` for especificado, e [OnHide](#onhide) se `OLEIVERB_HIDE` for especificado. As chamadas de implementação padrão `OnShow` se `iVerb` não for um dos verbos listados acima.  
  
 Substitua essa função se o verbo primário não mostrar o item. Por exemplo, se o item for uma gravação de som e o verbo primário for Play, você não precisa exibir o aplicativo de servidor para executar o item.  
  
 Para obter mais informações, consulte [IOleObject:: DoVerb](http://msdn.microsoft.com/library/windows/desktop/ms694508) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="ondraw"></a>COleServerItem::OnDraw  
 Chamado pelo framework para renderizar um item OLE em um meta-arquivo.  
  
```  
virtual BOOL OnDraw(
    CDC* pDC,  
    CSize& rSize) = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Um ponteiro para o [CDC](../../mfc/reference/cdc-class.md) objeto na qual desenhar o item. O contexto de exibição é conectado automaticamente ao contexto de exibição do atributo para que possa chamar funções de atributo, embora isso tornaria o metarquivo específicos do dispositivo.  
  
 `rSize`  
 Tamanho, **HIMETRIC** unidades, na qual desenhar o metarquivo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item foi desenhado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A representação de metarquivo do item OLE é usada para exibir o item no aplicativo de contêiner. Se o aplicativo de contêiner foi escrito com a biblioteca Microsoft Foundation Class, metarquivo é usado pelo [desenhar](../../mfc/reference/coleclientitem-class.md#draw) a função de membro de correspondente [COleClientItem](../../mfc/reference/coleclientitem-class.md) objeto. Não há nenhuma implementação padrão. Você deve substituir essa função para desenhar o item no contexto de dispositivo especificado.  
  
##  <a name="ondrawex"></a>COleServerItem::OnDrawEx  
 Chamado pela estrutura para todos os desenhos.  
  
```  
virtual BOOL OnDrawEx(
    CDC* pDC,  
    DVASPECT nDrawAspect,  
    CSize& rSize);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Um ponteiro para o [CDC](../../mfc/reference/cdc-class.md) objeto na qual desenhar o item. O controlador de domínio é conectado automaticamente ao atributo de controlador de domínio para que possa chamar funções de atributo, embora isso tornaria o metarquivo específicos do dispositivo.  
  
 `nDrawAspect`  
 Um valor da enumeração `DVASPECT`. Esse parâmetro pode ter qualquer um dos seguintes valores:  
  
- `DVASPECT_CONTENT`Item é representado de forma que ele pode ser exibido como um objeto incorporado dentro do seu contêiner.  
  
- `DVASPECT_THUMBNAIL`Item será renderizado em uma representação "em miniatura" para que ela possa ser exibida em uma ferramenta de procura.  
  
- `DVASPECT_ICON`Item é representado por um ícone.  
  
- `DVASPECT_DOCPRINT`Item é representado como se ela fosse impressa usando o comando Imprimir no menu arquivo.  
  
 `rSize`  
 Tamanho do item no **HIMETRIC** unidades.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item foi desenhado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 As chamadas de implementação padrão `OnDraw` quando `DVASPECT` é igual a `DVASPECT_CONTENT`; caso contrário ela falhará.  
  
 Substituir essa função para fornecer dados de apresentação para aspectos diferentes de `DVASPECT_CONTENT`, como `DVASPECT_ICON` ou `DVASPECT_THUMBNAIL`.  
  
##  <a name="ongetclipboarddata"></a>COleServerItem::OnGetClipboardData  
 Chamado pela estrutura para obter um `COleDataSource` objeto que contém todos os dados devem ser colocados na área de transferência por uma chamada para o [CopyToClipboard](#copytoclipboard) função de membro.  
  
```  
virtual COleDataSource* OnGetClipboardData(
    BOOL bIncludeLink,  
    LPPOINT lpOffset,  
    LPSIZE lpSize);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bIncludeLink`  
 Defina-o como **TRUE** se vincular dados devem ser copiados para a área de transferência. Defina-o como **FALSE** se o aplicativo de servidor não oferece suporte a links.  
  
 `lpOffset`  
 O deslocamento do cursor do mouse em relação à origem do objeto em pixels.  
  
 `lpSize`  
 O tamanho do objeto em pixels.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [COleDataSource](../../mfc/reference/coledatasource-class.md) objeto que contém os dados da área de transferência.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função chama [GetClipboardData](#getclipboarddata).  
  
##  <a name="ongetextent"></a>COleServerItem::OnGetExtent  
 Chamado pela estrutura para recuperar o tamanho, em **HIMETRIC** unidades do item OLE.  
  
```  
virtual BOOL OnGetExtent(
    DVASPECT nDrawAspect,  
    CSize& rSize);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nDrawAspect`  
 Especifica o aspecto do item OLE cujos limites devem ser recuperadas. Esse parâmetro pode ter qualquer um dos seguintes valores:  
  
- `DVASPECT_CONTENT`Item é representado de forma que ele pode ser exibido como um objeto incorporado dentro do seu contêiner.  
  
- `DVASPECT_THUMBNAIL`Item será renderizado em uma representação "em miniatura" para que ela possa ser exibida em uma ferramenta de procura.  
  
- `DVASPECT_ICON`Item é representado por um ícone.  
  
- `DVASPECT_DOCPRINT`Item é representado como se ela fosse impressa usando o comando Imprimir no menu arquivo.  
  
 `rSize`  
 Referência a um `CSize` objeto que receberá o tamanho do item OLE.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se o aplicativo de contêiner foi escrito com a biblioteca Microsoft Foundation Class, essa função é chamada quando o [GetExtent](../../mfc/reference/coleclientitem-class.md#getextent) a função de membro de correspondente `COleClientItem` objeto é chamado. A implementação padrão não faz nada. Você deve implementá-la para si mesmo. Substitua essa função se você quiser executar um processamento especial ao lidar com uma solicitação para o tamanho do item OLE.  
  
##  <a name="onhide"></a>COleServerItem::OnHide  
 Chamado pela estrutura para ocultar o item OLE.  
  
```  
virtual void OnHide();
```  
  
### <a name="remarks"></a>Comentários  
 As chamadas padrão **COleServerDoc::OnShowDocument (FALSE)**. A função também avisa ao contêiner que o item OLE está oculto. Substitua essa função se você quiser executar um processamento especial ao ocultar um item OLE.  
  
##  <a name="oninitfromdata"></a>COleServerItem::OnInitFromData  
 Chamado pela estrutura para inicializar um item OLE usando o conteúdo de `pDataObject`.  
  
```  
virtual BOOL OnInitFromData(
    COleDataObject* pDataObject,  
    BOOL bCreation);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDataObject`  
 Ponteiro para um objeto de dados OLE que contém os dados em vários formatos para inicializar o item OLE.  
  
 `bCreation`  
 **TRUE** se a função é chamada para inicializar um item OLE recentemente que está sendo criado por um aplicativo de contêiner. **FALSE** se a função é chamada para substituir o conteúdo de um item OLE já existente.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se `bCreation` é **TRUE**, essa função é chamada se um contêiner implementa Inserir novo objeto com base na seleção atual. Os dados selecionados são usados ao criar o novo item OLE. Por exemplo, ao selecionar um intervalo de células em um programa de planilha e, em seguida, usando o novo objeto inserir para criar um gráfico com base nos valores do intervalo selecionado. A implementação padrão não faz nada. Substituir essa função para escolher um formato aceitável daqueles oferecidos pelo `pDataObject` e inicializar o item OLE com base nos dados fornecidos. Isso é uma avançada substituível.  
  
 Para obter mais informações, consulte [IOleObject::InitFromData](http://msdn.microsoft.com/library/windows/desktop/ms688510) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="onopen"></a>COleServerItem::OnOpen  
 Chamado pela estrutura para exibir o item OLE em uma instância separada do aplicativo de servidor, em vez de no local.  
  
```  
virtual void OnOpen();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão ativa a primeira janela de quadro exibindo o documento que contém o item OLE; Se o aplicativo for um servidor simplificado, a implementação padrão mostra a janela principal. A função também avisa ao contêiner que o item OLE foi aberto.  
  
 Substitua essa função se você quiser executar um processamento especial ao abrir um item OLE. Isso é especialmente comum com itens vinculados em que você deseja definir a seleção para o link quando ele é aberto.  
  
 Para obter mais informações, consulte [IOleClientSite::OnShowWindow](http://msdn.microsoft.com/library/windows/desktop/ms688658) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="onqueryupdateitems"></a>COleServerItem::OnQueryUpdateItems  
 Chamado pela estrutura para determinar se os itens vinculados no documento atual do servidor estão desatualizados.  
  
```  
virtual BOOL OnQueryUpdateItems();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o documento tem itens que precisam de atualizações. 0 se todos os itens sejam atualizados.  
  
### <a name="remarks"></a>Comentários  
 Um item está desatualizado se seu documento de origem tiver sido alterado, mas o item vinculado não foi atualizado para refletir as alterações no documento.  
  
##  <a name="onrenderdata"></a>COleServerItem::OnRenderData  
 Chamado pela estrutura para recuperar dados no formato especificado.  
  
```  
virtual BOOL OnRenderData(
    LPFORMATETC lpFormatEtc,  
    LPSTGMEDIUM lpStgMedium);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpFormatEtc`  
 Aponta para a [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura especificando o formato no qual as informações são solicitadas.  
  
 `lpStgMedium`  
 Aponta para um [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) estrutura na qual os dados são a ser retornado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O formato especificado é um colocado anteriormente no `COleDataSource` objeto usando o [DelayRenderData](../../mfc/reference/coledatasource-class.md#delayrenderdata) ou [DelayRenderFileData](../../mfc/reference/coledatasource-class.md#delayrenderfiledata) a função de membro para processamento posterior. A implementação padrão dessa função chama [OnRenderFileData](#onrenderfiledata) ou [OnRenderGlobalData](#onrenderglobaldata), respectivamente, se a mídia de armazenamento fornecido é um arquivo ou memória. Se nenhum desses formatos for fornecido, a implementação padrão retorna 0 e não faz nada.  
  
 Se `lpStgMedium` ->  *tymed* é **TYMED_NULL**, o **STGMEDIUM** deve alocado e preenchida conforme especificado por *lpFormatEtc-> tymed*. Se não **TYMED_NULL**, o **STGMEDIUM** deve ser preenchido no local com os dados.  
  
 Isso é uma avançada substituível. Substitua essa função para fornecer os dados no formato solicitado e mídia. Dependendo de seus dados, você talvez queira substituir uma das outras versões dessa função em vez disso. Se os dados forem pequenos e com o tamanho fixo, substituir `OnRenderGlobalData`. Se os dados estiverem em um arquivo ou é de tamanho variável, substituir `OnRenderFileData`.  
  
 Para obter mais informações, consulte [IDataObject::](http://msdn.microsoft.com/library/windows/desktop/ms678431), [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812), [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177), e [TYMED](http://msdn.microsoft.com/library/windows/desktop/ms691227) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="onrenderfiledata"></a>COleServerItem::OnRenderFileData  
 Chamado pela estrutura para recuperar dados no formato especificado quando a mídia de armazenamento é um arquivo.  
  
```  
virtual BOOL OnRenderFileData(
    LPFORMATETC lpFormatEtc,  
    CFile* pFile);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpFormatEtc`  
 Aponta para a [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura especificando o formato no qual as informações são solicitadas.  
  
 `pFile`  
 Aponta para um `CFile` objeto no qual os dados a serem processados.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O formato especificado é um colocado anteriormente no `COleDataSource` objeto usando o [DelayRenderData](../../mfc/reference/coledatasource-class.md#delayrenderdata) a função de membro para processamento posterior. A implementação padrão dessa função simplesmente retorna **FALSE**.  
  
 Isso é uma avançada substituível. Substitua essa função para fornecer os dados no formato solicitado e mídia. Dependendo de seus dados, você talvez queira substituir uma das outras versões dessa função em vez disso. Se você quiser manipular várias mídias de armazenamento, substituir [OnRenderData](#onrenderdata). Se os dados estiverem em um arquivo ou é de tamanho variável, substituir [OnRenderFileData](#onrenderfiledata).  
  
 Para obter mais informações, consulte [IDataObject::](http://msdn.microsoft.com/library/windows/desktop/ms678431) e [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="onrenderglobaldata"></a>COleServerItem::OnRenderGlobalData  
 Chamado pela estrutura para recuperar dados no formato especificado quando a mídia de armazenamento especificado é memória global.  
  
```  
virtual BOOL OnRenderGlobalData(
    LPFORMATETC lpFormatEtc,  
    HGLOBAL* phGlobal);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpFormatEtc`  
 Aponta para a [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura especificando o formato no qual as informações são solicitadas.  
  
 `phGlobal`  
 Aponta para um identificador de memória global na qual os dados são a ser retornado. Se nenhuma memória foi alocada, esse parâmetro pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O formato especificado é um colocado anteriormente no `COleDataSource` objeto usando o [DelayRenderData](../../mfc/reference/coledatasource-class.md#delayrenderdata) a função de membro para processamento posterior. A implementação padrão dessa função simplesmente retorna **FALSE**.  
  
 Se `phGlobal` é **nulo**, em seguida, um novo `HGLOBAL` deve ser alocado e retornados em `phGlobal`. Caso contrário, o `HGLOBAL` especificado por `phGlobal` deve ser preenchido com os dados. A quantidade de dados colocados no `HGLOBAL` não deve exceder o tamanho atual do bloco de memória. Além disso, o bloco não pode ser realocado para um tamanho maior.  
  
 Isso é uma avançada substituível. Substitua essa função para fornecer os dados no formato solicitado e mídia. Dependendo de seus dados, você talvez queira substituir uma das outras versões dessa função em vez disso. Se você quiser manipular várias mídias de armazenamento, substituir [OnRenderData](#onrenderdata). Se os dados estiverem em um arquivo ou é de tamanho variável, substituir [OnRenderFileData](#onrenderfiledata).  
  
 Para obter mais informações, consulte [IDataObject::](http://msdn.microsoft.com/library/windows/desktop/ms678431) e [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="onsetcolorscheme"></a>COleServerItem::OnSetColorScheme  
 Chamado pela estrutura para especificar uma paleta de cores a ser usado ao editar o item OLE.  
  
```  
virtual BOOL OnSetColorScheme(const LOGPALETTE* lpLogPalette);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpLogPalette`  
 Ponteiro para um Windows [LOGPALETTE](http://msdn.microsoft.com/library/windows/desktop/dd145040) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a paleta de cores é usada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se o aplicativo de contêiner foi escrito usando a biblioteca Microsoft Foundation Class, essa função é chamada quando o [IOleObject::SetColorScheme](http://msdn.microsoft.com/library/windows/desktop/ms683971) função do correspondente `COleClientItem` objeto é chamado. Retorna a implementação padrão **FALSE**. Substitua essa função se você quiser usar a paleta recomendada. O aplicativo de servidor não é necessário usar a paleta sugerida.  
  
 Para obter mais informações, consulte [IOleObject::SetColorScheme](http://msdn.microsoft.com/library/windows/desktop/ms683971) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="onsetdata"></a>COleServerItem::OnSetData  
 Chamado pela estrutura para substituir os dados do item OLE com os dados especificados.  
  
```  
virtual BOOL OnSetData(
    LPFORMATETC lpFormatEtc,  
    LPSTGMEDIUM lpStgMedium,  
    BOOL bRelease);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpFormatEtc`  
 Ponteiro para uma [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura especificando o formato dos dados.  
  
 `lpStgMedium`  
 Ponteiro para uma [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812) estrutura na qual os dados residem.  
  
 `bRelease`  
 Indica que é proprietária da mídia de armazenamento depois de concluir a chamada de função. O chamador decide quem é responsável por liberar os recursos alocados em nome de mídia de armazenamento. O chamador faz isso definindo `bRelease`. Se `bRelease` é diferente de zero, o item do servidor apropria, liberando a mídia quando ele tiver terminado de usá-lo. Quando `bRelease` é 0, o chamador reterá a propriedade e o item do servidor pode usar a mídia de armazenamento apenas para a duração da chamada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O item do servidor não assumir a propriedade dos dados até que ele obteve com êxito-lo. Ou seja, ele não apropriar-se retorna 0. Se a fonte de dados se apropria, libera a mídia de armazenamento, chamando o [ReleaseStgMedium](http://msdn.microsoft.com/library/windows/desktop/ms693491) função.  
  
 A implementação padrão não faz nada. Substitua essa função para substituir os dados do item OLE com os dados especificados. Isso é uma avançada substituível.  
  
 Para obter mais informações, consulte [STGMEDIUM](http://msdn.microsoft.com/library/windows/desktop/ms683812), [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177), e [ReleaseStgMedium](http://msdn.microsoft.com/library/windows/desktop/ms693491) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="onsetextent"></a>COleServerItem::OnSetExtent  
 Chamado pela estrutura para informar o item OLE quanto espaço está disponível para ele no documento contêiner.  
  
```  
virtual BOOL OnSetExtent(
    DVASPECT nDrawAspect,  
    const CSize& size);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nDrawAspect`  
 Especifica o aspecto do item OLE cujos limites estão sendo especificados. Esse parâmetro pode ter qualquer um dos seguintes valores:  
  
- `DVASPECT_CONTENT`Item é representado de forma que ele pode ser exibido como um objeto incorporado dentro do seu contêiner.  
  
- `DVASPECT_THUMBNAIL`Item será renderizado em uma representação "em miniatura" para que ela possa ser exibida em uma ferramenta de procura.  
  
- `DVASPECT_ICON`Item é representado por um ícone.  
  
- `DVASPECT_DOCPRINT`Item é representado como se ela fosse impressa usando o comando Imprimir no menu arquivo.  
  
 `size`  
 A [CSize](../../atl-mfc-shared/reference/csize-class.md) estrutura especificando o novo tamanho do item OLE.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se o aplicativo de contêiner foi escrito com a biblioteca Microsoft Foundation Class, essa função é chamada quando o [SetExtent](../../mfc/reference/coleclientitem-class.md#setextent) a função de membro de correspondente `COleClientItem` objeto é chamado. Os conjuntos de implementação padrão de [m_sizeExtent](#m_sizeextent) membro com o tamanho especificado se `nDrawAspect` é `DVASPECT_CONTENT`; caso contrário, retornará 0. Substitua essa função para executar um processamento especial quando você alterar o tamanho do item.  
  
##  <a name="onshow"></a>COleServerItem::OnShow  
 Chamado pela estrutura para instruir o aplicativo do servidor para exibir o item OLE no local.  
  
```  
virtual void OnShow();
```  
  
### <a name="remarks"></a>Comentários  
 Esta função geralmente é chamada quando o usuário do aplicativo de contêiner cria um item ou executar um verbo, como editar, que requer o item a ser mostrado. A implementação padrão de tentativas de ativação no local. Se isso falhar, as chamadas de função de `OnOpen` função de membro para exibir o item OLE em uma janela separada.  
  
 Substitua essa função se você quiser executar um processamento especial quando um item OLE é mostrado.  
  
##  <a name="onupdate"></a>COleServerItem::OnUpdate  
 Chamado pela estrutura quando um item foi modificado.  
  
```  
virtual void OnUpdate(
    COleServerItem* pSender,  
    LPARAM lHint,  
    CObject* pHint,  
    DVASPECT nDrawAspect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pSender`  
 Ponteiro para o item que modificou o documento. Pode ser **nulo**.  
  
 `lHint`  
 Contém informações sobre a modificação.  
  
 `pHint`  
 Ponteiro para um objeto de armazenamento de informações sobre a modificação.  
  
 `nDrawAspect`  
 Um valor da enumeração `DVASPECT`. Esse parâmetro pode ter qualquer um dos seguintes valores:  
  
- `DVASPECT_CONTENT`Item é representado de forma que ele pode ser exibido como um objeto incorporado dentro do seu contêiner.  
  
- `DVASPECT_THUMBNAIL`Item será renderizado em uma representação "em miniatura" para que ela possa ser exibida em uma ferramenta de procura.  
  
- `DVASPECT_ICON`Item é representado por um ícone.  
  
- `DVASPECT_DOCPRINT`Item é representado como se ela fosse impressa usando o comando Imprimir no menu arquivo.  
  
### <a name="remarks"></a>Comentários  
 As chamadas de implementação padrão [NotifyChanged](#notifychanged), independentemente da dica ou o remetente.  
  
##  <a name="onupdateitems"></a>COleServerItem::OnUpdateItems  
 Chamado pela estrutura para atualizar todos os itens no documento do servidor.  
  
```  
virtual void OnUpdateItems();
```  
  
### <a name="remarks"></a>Comentários  
 As chamadas de implementação padrão [UpdateLink](../../mfc/reference/coleclientitem-class.md#updatelink) para todos os `COleClientItem` objetos no documento.  
  
##  <a name="setitemname"></a>COleServerItem::SetItemName  
 Chame essa função quando você cria um item vinculado para definir seu nome.  
  
```  
void SetItemName(LPCTSTR lpszItemName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszItemName`  
 Ponteiro para o novo nome do item.  
  
### <a name="remarks"></a>Comentários  
 O nome deve ser exclusivo dentro do documento. Quando um aplicativo de servidor é chamado para editar um item vinculado, o aplicativo usa esse nome para localizar o item. Você não precisa chamar essa função para itens inseridos.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC HIERSVR](../../visual-cpp-samples.md)   
 [Classe CDocItem](../../mfc/reference/cdocitem-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)   
 [Classe COleServerDoc](../../mfc/reference/coleserverdoc-class.md)   
 [Classe COleTemplateServer](../../mfc/reference/coletemplateserver-class.md)

