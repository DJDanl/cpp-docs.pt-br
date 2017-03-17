---
title: Classe COleServerDoc | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- servers, OLE
- OLE server applications, managing server documents
- container/server applications
- OLE server documents
- COleServerDoc class
- server documents, OLE
- OLE containers, server documents
ms.assetid: a9cdd96a-e0ac-43bb-9203-2c29237e965c
caps.latest.revision: 24
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
ms.openlocfilehash: db50c2a5709fbc07d0e0db99a4cffc733c4b6ead
ms.lasthandoff: 02/25/2017

---
# <a name="coleserverdoc-class"></a>Classe COleServerDoc
A classe base para documentos de servidor OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class AFX_NOVTABLE COleServerDoc : public COleLinkingDoc  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleServerDoc::COleServerDoc](#coleserverdoc)|Constrói um objeto `COleServerDoc`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleServerDoc::ActivateDocObject](#activatedocobject)|Ativa o documento DocObject associado.|  
|[COleServerDoc::ActivateInPlace](#activateinplace)|Ativa o documento para edição no local.|  
|[COleServerDoc::DeactivateAndUndo](#deactivateandundo)|Desativa a interface do usuário do servidor.|  
|[COleServerDoc::DiscardUndoState](#discardundostate)|Descarta informações de estado de desfazer.|  
|[COleServerDoc::GetClientSite](#getclientsite)|Recupera um ponteiro para subjacente `IOleClientSite` interface.|  
|[COleServerDoc::GetEmbeddedItem](#getembeddeditem)|Retorna um ponteiro para um item que representa o documento inteiro.|  
|[COleServerDoc::GetItemClipRect](#getitemcliprect)|Retorna o retângulo de recorte atual para edição no local.|  
|[COleServerDoc::GetItemPosition](#getitemposition)|Retorna o retângulo posição atual, com relação à área do cliente do aplicativo de contêiner, para edição no local.|  
|[COleServerDoc::GetZoomFactor](#getzoomfactor)|Retorna o fator de zoom em pixels.|  
|[COleServerDoc::IsDocObject](#isdocobject)|Determina se o documento é um DocObject.|  
|[COleServerDoc::IsEmbedded](#isembedded)|Indica se o documento é incorporado em um documento de contêiner ou execução autônoma.|  
|[COleServerDoc::IsInPlaceActive](#isinplaceactive)|Retorna `TRUE` se o item estiver ativado no local.|  
|[COleServerDoc::NotifyChanged](#notifychanged)|Notifica contêineres que o usuário alterou o documento.|  
|[COleServerDoc::NotifyClosed](#notifyclosed)|Notifica contêineres que o usuário tiver fechado o documento.|  
|[COleServerDoc::NotifyRename](#notifyrename)|Notifica contêineres que o usuário tiver renomeado o documento.|  
|[COleServerDoc::NotifySaved](#notifysaved)|Notifica contêineres que o usuário salvou o documento.|  
|[COleServerDoc::OnDeactivate](#ondeactivate)|Chamado pela estrutura quando o usuário desativa um item que foi ativado no local.|  
|[COleServerDoc::OnDeactivateUI](#ondeactivateui)|Chamado pela estrutura para destruir controles e outros elementos de interface do usuário criados para ativação no local.|  
|[COleServerDoc::OnDocWindowActivate](#ondocwindowactivate)|Chamado pela estrutura quando a janela de quadro do documento do contêiner é ativada ou desativada.|  
|[COleServerDoc::OnResizeBorder](#onresizeborder)|Chamado pela estrutura quando o aplicativo de contêiner janela de quadro ou janela de documento é redimensionada.|  
|[COleServerDoc::OnShowControlBars](#onshowcontrolbars)|Chamado pela estrutura para mostrar ou ocultar as barras de controle de edição in-loco.|  
|[COleServerDoc::OnUpdateDocument](#onupdatedocument)|Chamado pela estrutura quando um documento do servidor que é um item inserido é salvo, atualizando a cópia do contêiner do item.|  
|[COleServerDoc::RequestPositionChange](#requestpositionchange)|Altera a posição do quadro de edição in-loco.|  
|[COleServerDoc::SaveEmbedding](#saveembedding)|Informa o aplicativo de contêiner para salvar o documento.|  
|[COleServerDoc::ScrollContainerBy](#scrollcontainerby)|Rola o documento contêiner.|  
|[COleServerDoc::UpdateAllItems](#updateallitems)|Notifica contêineres que o usuário alterou o documento.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleServerDoc::CreateInPlaceFrame](#createinplaceframe)|Chamado pela estrutura para criar uma janela de quadro para edição no local.|  
|[COleServerDoc::DestroyInPlaceFrame](#destroyinplaceframe)|Chamado pela estrutura para destruir uma janela do quadro para edição no local.|  
|[COleServerDoc::GetDocObjectServer](#getdocobjectserver)|Substituir essa função para criar um novo `CDocObjectServer` object e indicar que este documento é um contêiner DocObject.|  
|[COleServerDoc::OnClose](#onclose)|Chamado pela estrutura quando solicita um contêiner para fechar o documento.|  
|[COleServerDoc::OnExecOleCmd](#onexecolecmd)|Executa um comando especificado ou exibe a Ajuda para o comando.|  
|[COleServerDoc::OnFrameWindowActivate](#onframewindowactivate)|Chamado pela estrutura quando a janela do quadro do contêiner é ativada ou desativada.|  
|[COleServerDoc::OnGetEmbeddedItem](#ongetembeddeditem)|Chamado para obter um `COleServerItem` que representa o documento inteiro, usado para obter um item incorporado. Implementação necessários.|  
|[COleServerDoc::OnReactivateAndUndo](#onreactivateandundo)|Chamado pela estrutura para desfazer as alterações feitas durante a edição in-loco.|  
|[COleServerDoc::OnSetHostNames](#onsethostnames)|Chamado pela estrutura quando um contêiner define o título da janela para um objeto incorporado.|  
|[COleServerDoc::OnSetItemRects](#onsetitemrects)|Chamado pela estrutura para posicionar a janela de quadro de edição in-loco na janela do aplicativo de contêiner.|  
|[COleServerDoc::OnShowDocument](#onshowdocument)|Chamado pela estrutura para mostrar ou ocultar o documento.|  
  
## <a name="remarks"></a>Comentários  
 Um documento do servidor pode conter [classe derivada COleServerItem](../../mfc/reference/coleserveritem-class.md) objetos que representam a interface de servidor para itens inseridos ou vinculados. Quando um aplicativo de servidor é iniciado por um contêiner para editar um item inserido, o item é carregado como documento seu próprio servidor. o `COleServerDoc` objeto contém apenas uma `COleServerItem` objeto, consistindo em todo o documento. Quando um aplicativo de servidor é iniciado por um contêiner para editar um item vinculado, um documento existente é carregado do disco; uma parte do conteúdo do documento é realçada para indicar que o item vinculado.  
  
 `COleServerDoc`objetos também podem conter itens de [COleClientItem](../../mfc/reference/coleclientitem-class.md) classe. Isso permite que você crie aplicativos de servidor do contêiner. O framework fornece funções para armazenar corretamente o `COleClientItem` itens durante a manutenção de `COleServerItem` objetos.  
  
 Se o aplicativo de servidor não oferece suporte a links, um documento do servidor sempre conterá apenas um item de servidor, que representa todo o objeto incorporado como um documento. Se o aplicativo de servidor oferecer suporte a links, ele deve criar um item de servidor sempre que uma seleção é copiada para a área de transferência.  
  
 Usar `COleServerDoc`, derive uma classe dele e implementar o [OnGetEmbeddedItem](#ongetembeddeditem) a função de membro, que permite que o servidor dê suporte a itens inseridos. Derivar uma classe de `COleServerItem` para implementar os itens em seus documentos e retornar objetos dessa classe de `OnGetEmbeddedItem`.  
  
 Para oferecer suporte a itens vinculados, `COleServerDoc` fornece o [OnGetLinkedItem](../../mfc/reference/colelinkingdoc-class.md#ongetlinkeditem) função de membro. Você pode usar a implementação padrão ou substituí-la se você tiver sua própria maneira de gerenciar itens de documento.  
  
 Você precisa de um `COleServerDoc`-classe derivada para cada tipo de servidor de documentos suporta o aplicativo. Por exemplo, se seu aplicativo de servidor suporta planilhas e gráficos, você precisa de dois `COleServerDoc`-classes derivadas.  
  
 Para obter mais informações sobre servidores, consulte o artigo [servidores: Implementando um servidor](../../mfc/servers-implementing-a-server.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CDocument](../../mfc/reference/cdocument-class.md)  
  
 [COleDocument](../../mfc/reference/coledocument-class.md)  
  
 [COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md)  
  
 `COleServerDoc`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  
  
##  <a name="activatedocobject"></a>COleServerDoc::ActivateDocObject  
 Ativa o documento DocObject associado.  
  
```  
void ActivateDocObject();
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, `COleServerDoc` não oferece suporte a documentos ativos (também conhecidos como DocObjects). Para habilitar esse suporte, consulte [GetDocObjectServer](#getdocobjectserver) e classe [CDocObjectServer](../../mfc/reference/cdocobjectserver-class.md).  
  
##  <a name="activateinplace"></a>COleServerDoc::ActivateInPlace  
 Ativa o item para edição no local.  
  
```  
BOOL ActivateInPlace();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0, que indica que o item está totalmente aberto.  
  
### <a name="remarks"></a>Comentários  
 Essa função realiza todas as operações necessárias para ativação no local. Ele cria uma janela de quadro in-loco, ativa dimensiona-la para o item, configura compartilhados menus e outros controles, o item é movido para a exibição e define o foco para a janela de quadro in-loco.  
  
 Essa função é chamada pela implementação padrão de [COleServerItem::OnShow](../../mfc/reference/coleserveritem-class.md#onshow). Chame essa função se seu aplicativo oferecer suporte a outro verbo para ativação no local (como Play).  
  
##  <a name="coleserverdoc"></a>COleServerDoc::COleServerDoc  
 Constrói uma `COleServerDoc` objeto sem se conectar com as DLLs do sistema OLE.  
  
```  
COleServerDoc();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar [COleLinkingDoc::Register](../../mfc/reference/colelinkingdoc-class.md#register) para abrir as comunicações com OLE. Se você estiver usando [COleTemplateServer](../../mfc/reference/coletemplateserver-class.md) em seu aplicativo, `COleLinkingDoc::Register` é chamado para você por `COleLinkingDoc`da implementação de `OnNewDocument`, `OnOpenDocument`, e `OnSaveDocument`.  
  
##  <a name="createinplaceframe"></a>COleServerDoc::CreateInPlaceFrame  
 O framework chama essa função para criar uma janela de quadro para edição no local.  
  
```  
virtual COleIPFrameWnd* CreateInPlaceFrame(CWnd* pParentWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pParentWnd`  
 Ponteiro para o contêiner pai janela de aplicativo.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a janela de quadro in-loco ou **nulo** se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão usa informações especificadas no modelo de documento para criar o quadro. A exibição usada é a primeira exibição criada para o documento. Essa exibição é desanexada do quadro original temporariamente e anexada ao quadro recém-criado.  
  
 Isso é uma avançada substituível.  
  
##  <a name="deactivateandundo"></a>COleServerDoc::DeactivateAndUndo  
 Chame essa função se desfazer sua oferece suporte a aplicativos e o usuário escolhe desfazer após ativar um item, mas antes de editá-lo.  
  
```  
BOOL DeactivateAndUndo();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero em caso de êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se o aplicativo de contêiner é escrito usando a biblioteca Microsoft Foundation Class, chamar essa função faz com que [COleClientItem::OnDeactivateAndUndo](../../mfc/reference/coleclientitem-class.md#ondeactivateandundo) para ser chamado, que desativa a interface do usuário do servidor.  
  
##  <a name="destroyinplaceframe"></a>COleServerDoc::DestroyInPlaceFrame  
 O framework chama essa função para destruir uma janela de quadro in-loco e retornar o servidor de janela de documento do aplicativo para seu estado antes da ativação in loco.  
  
```  
virtual void DestroyInPlaceFrame(COleIPFrameWnd* pFrameWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFrameWnd`  
 Ponteiro para a janela de quadro no local a ser destruído.  
  
### <a name="remarks"></a>Comentários  
 Isso é uma avançada substituível.  
  
##  <a name="discardundostate"></a>COleServerDoc::DiscardUndoState  
 Se o usuário executa uma operação de edição que não pode ser desfeita, chame essa função para forçar o aplicativo de contêiner para descartar suas informações de estado de desfazer.  
  
```  
BOOL DiscardUndoState();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero em caso de êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esta função é fornecida para que os servidores que oferecem suporte a desfazer podem liberar recursos caso contrário poderia ser consumidos por informações de estado de desfazer que não podem ser usadas.  
  
##  <a name="getclientsite"></a>COleServerDoc::GetClientSite  
 Recupera um ponteiro para subjacente `IOleClientSite` interface.  
  
```  
LPOLECLIENTSITE GetClientSite() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Recupera um ponteiro para subjacente [IOleClientSite](http://msdn.microsoft.com/library/windows/desktop/ms693706) interface.  
  
##  <a name="getdocobjectserver"></a>COleServerDoc::GetDocObjectServer  
 Substituir essa função para criar um novo `CDocObjectServer` item e retornar um ponteiro para ele.  
  
```  
virtual CDocObjectServer* GetDocObjectServer(LPOLEDOCUMENTSITE pDocSite);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDocSite`  
 Ponteiro para o `IOleDocumentSite` interface que irão se conectar a este documento para o servidor.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CDocObjectServer`; **Nulo** se a operação falhou.  
  
### <a name="remarks"></a>Comentários  
 Quando um servidor DocObject é ativado, o retorno de um não - **nulo** ponteiro mostra que o cliente pode oferecer suporte a DocObjects. Retorna a implementação padrão **nulo**.  
  
 Uma implementação típica de um documento que oferece suporte a DocObjects será simplesmente alocar um novo `CDocObjectServer` do objeto e retorná-lo ao chamador. Por exemplo:  
  
 [!code-cpp[NVC_MFCOleServer n º&3;](../../mfc/codesnippet/cpp/coleserverdoc-class_1.cpp)]  
  
##  <a name="getembeddeditem"></a>COleServerDoc::GetEmbeddedItem  
 Chame essa função para obter um ponteiro para um item que representa o documento inteiro.  
  
```  
COleServerItem* GetEmbeddedItem();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um item que representa o documento inteiro; **Nulo** se a operação falhou.  
  
### <a name="remarks"></a>Comentários  
 Ele chama [COleServerDoc::OnGetEmbeddedItem](#ongetembeddeditem), uma função virtual sem implementação padrão.  
  
##  <a name="getitemcliprect"></a>COleServerDoc::GetItemClipRect  
 Chamar o `GetItemClipRect` a função de membro para obter as coordenadas do retângulo de corte do item que está sendo editado no local.  
  
```  
void GetItemClipRect(LPRECT lpClipRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpClipRect`  
 Ponteiro para uma `RECT` estrutura ou um `CRect` objeto para receber as coordenadas do retângulo de corte do item.  
  
### <a name="remarks"></a>Comentários  
 Coordenadas são em pixels com relação à área do cliente da janela do aplicativo recipiente.  
  
 Desenho não deve ocorrer fora do retângulo de recorte. Geralmente, o desenho é automaticamente restrito. Use esta função para determinar se o usuário rolou fora a parte visível do documento. Nesse caso, rolar o documento contêiner conforme a necessidade por meio de uma chamada para [ScrollContainerBy](#scrollcontainerby).  
  
##  <a name="getitemposition"></a>COleServerDoc::GetItemPosition  
 Chamar o `GetItemPosition` a função de membro para obter as coordenadas do item sendo editado no local.  
  
```  
void GetItemPosition(LPRECT lpPosRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpPosRect`  
 Ponteiro para uma `RECT` estrutura ou um `CRect` objeto para receber as coordenadas do item.  
  
### <a name="remarks"></a>Comentários  
 Coordenadas são em pixels com relação à área do cliente da janela do aplicativo recipiente.  
  
 A posição do item pode ser comparada com o retângulo de recorte atual para determinar a extensão à qual o item está visível (ou não visível) na tela.  
  
##  <a name="getzoomfactor"></a>COleServerDoc::GetZoomFactor  
 O `GetZoomFactor` função membro determina o "fator de zoom" de um item que foi ativado para a edição in-loco.  
  
```  
BOOL GetZoomFactor(
    LPSIZE lpSizeNum = NULL,  
    LPSIZE lpSizeDenom = NULL,  
    LPCRECT lpPosRect = NULL) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpSizeNum*  
 Ponteiro para um objeto da classe `CSize` que irá conter o numerador do fator de zoom. Pode ser **nulo**.  
  
 *lpSizeDenom*  
 Ponteiro para um objeto da classe `CSize` que irá conter o denominador do fator de zoom. Pode ser **nulo**.  
  
 `lpPosRect`  
 Ponteiro para um objeto da classe `CRect` que descreve a nova posição do item. Se esse argumento for **nulo**, a função usa a posição do item atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item está ativado para o local de edição e o fator de zoom é diferente de 100% (1:1); Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O fator de zoom, em pixels, é a proporção do tamanho do item para sua extensão atual. Se o aplicativo de contêiner não tiver definido a extensão do item, sua extensão natural (conforme determinado pela [COleServerItem::OnGetExtent](../../mfc/reference/coleserveritem-class.md#ongetextent)) é usado.  
  
 A função define os dois primeiros argumentos para o numerador e o denominador da "fator de zoom." do item Se o item não está sendo editado no lugar, a função define esses argumentos para um valor padrão de 100% (ou 1:1) e retorna zero. Para obter mais informações, consulte 40 Observação técnica, [zoom e redimensionamento de in-loco MFC/OLE](../../mfc/tn040-mfc-ole-in-place-resizing-and-zooming.md).  
  
##  <a name="isdocobject"></a>COleServerDoc::IsDocObject  
 Determina se o documento é um DocObject.  
  
```  
BOOL IsDocObject() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se o documento for uma DocObject; caso contrário, **FALSE**.  
  
##  <a name="isembedded"></a>COleServerDoc::IsEmbedded  
 Chamar o `IsEmbedded` a função de membro para determinar se o documento representa um objeto incorporado em um contêiner.  
  
```  
BOOL IsEmbedded() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o `COleServerDoc` objeto é um documento que representa um objeto incorporado em um contêiner; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um documento carregado de um arquivo não é inserido, embora ele pode ser manipulado por um aplicativo de contêiner como um link. Um documento que está incorporado em um documento do contêiner é considerado a ser inserido.  
  
##  <a name="isinplaceactive"></a>COleServerDoc::IsInPlaceActive  
 Chamar o `IsInPlaceActive` a função de membro para determinar se o item está no estado ativo no local.  
  
```  
BOOL IsInPlaceActive() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o `COleServerDoc` objeto estiver ativa no local; caso contrário, 0.  
  
##  <a name="notifychanged"></a>COleServerDoc::NotifyChanged  
 Chame essa função para notificar todos os itens vinculados conectados ao documento que o documento foi alterado.  
  
```  
void NotifyChanged();
```  
  
### <a name="remarks"></a>Comentários  
 Normalmente, você chama essa função depois que o usuário altera algum atributo global, como as dimensões do documento do servidor. Se um item OLE é vinculado ao documento com um vínculo automático, o item é atualizado para refletir as alterações. Em aplicativos de contêiner gravados com a biblioteca Microsoft Foundation Class, o [OnChange](../../mfc/reference/coleclientitem-class.md#onchange) função de membro `COleClientItem` é chamado.  
  
> [!NOTE]
>  Essa função é incluída para compatibilidade com OLE 1. Novos aplicativos devem usar [UpdateAllItems](#updateallitems).  
  
##  <a name="notifyclosed"></a>COleServerDoc::NotifyClosed  
 Chame essa função para notificar os contêineres que o documento foi fechado.  
  
```  
void NotifyClosed();
```  
  
### <a name="remarks"></a>Comentários  
 Quando o usuário escolhe o comando Fechar no menu Arquivo, `NotifyClosed` é chamado pelo `COleServerDoc`da implementação de [OnCloseDocument](../../mfc/reference/cdocument-class.md#onclosedocument) função de membro. Em aplicativos de contêiner gravados com a biblioteca Microsoft Foundation Class, o [OnChange](../../mfc/reference/coleclientitem-class.md#onchange) função de membro `COleClientItem` é chamado.  
  
##  <a name="notifyrename"></a>COleServerDoc::NotifyRename  
 Depois que o usuário renomeia o documento de servidor, chame essa função.  
  
```  
void NotifyRename(LPCTSTR lpszNewName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszNewName`  
 Ponteiro para uma cadeia de caracteres que especifica o novo nome do documento do servidor; Isso geralmente é um caminho totalmente qualificado.  
  
### <a name="remarks"></a>Comentários  
 Quando o usuário escolhe o comando Salvar como no menu Arquivo, `NotifyRename` é chamado pelo `COleServerDoc`da implementação de [OnSaveDocument](../../mfc/reference/cdocument-class.md#onsavedocument) função de membro. Essa função notifica o sistema OLE DLLs, que por sua vez notificar os contêineres. Em aplicativos de contêiner gravados com a biblioteca Microsoft Foundation Class, o [OnChange](../../mfc/reference/coleclientitem-class.md#onchange) função de membro `COleClientItem` é chamado.  
  
##  <a name="notifysaved"></a>COleServerDoc::NotifySaved  
 Chame essa função depois que o usuário salva o documento do servidor.  
  
```  
void NotifySaved();
```  
  
### <a name="remarks"></a>Comentários  
 Quando o usuário escolhe o comando Salvar do menu Arquivo, `NotifySaved` é chamado para você por `COleServerDoc`da implementação de [OnSaveDocument](../../mfc/reference/cdocument-class.md#onsavedocument). Essa função notifica o sistema OLE DLLs, que por sua vez notificar os contêineres. Em aplicativos de contêiner gravados com a biblioteca Microsoft Foundation Class, o [OnChange](../../mfc/reference/coleclientitem-class.md#onchange) função de membro `COleClientItem` é chamado.  
  
##  <a name="onclose"></a>COleServerDoc::OnClose  
 Chamado pela estrutura quando um contêiner solicita que o documento de servidor ser fechado.  
  
```  
virtual void OnClose(OLECLOSE dwCloseOption);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwCloseOption`  
 Um valor da enumeração `OLECLOSE`. Esse parâmetro pode ter um dos seguintes valores:  
  
- `OLECLOSE_SAVEIFDIRTY`O arquivo é salvo se ele tiver sido modificado.  
  
- `OLECLOSE_NOSAVE`O arquivo é fechado sem ser salvado.  
  
- `OLECLOSE_PROMPTSAVE`Se o arquivo tiver sido modificado, o usuário é solicitado a salvá-lo.  
  
### <a name="remarks"></a>Comentários  
 As chamadas de implementação padrão `CDocument::OnCloseDocument`.  
  
 Para obter mais informações e valores adicionais, consulte [OLECLOSE](http://msdn.microsoft.com/library/windows/desktop/ms680623) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="ondeactivate"></a>COleServerDoc::OnDeactivate  
 Chamado pela estrutura quando o usuário desativa um item vinculado ou incorporado que está ativo no momento no local.  
  
```  
virtual void OnDeactivate();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função restaura a interface do usuário do aplicativo de contêiner para seu estado original e destrói qualquer menus e outros controles que foram criados para ativação no local.  
  
 As informações de estado de recuperação devem ser liberadas incondicionalmente neste momento.  
  
 Para obter mais informações, consulte o artigo [ativação](../../mfc/activation-cpp.md)...  
  
##  <a name="ondeactivateui"></a>COleServerDoc::OnDeactivateUI  
 Chamado quando o usuário desativa um item que foi ativado no local.  
  
```  
virtual void OnDeactivateUI(BOOL bUndoable);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bUndoable`  
 Especifica se as alterações de edição podem ser desfeitas.  
  
### <a name="remarks"></a>Comentários  
 Essa função restaura a interface do usuário do aplicativo de contêiner para seu estado original, ocultando quaisquer menus e outros controles que foram criados para ativação no local.  
  
 A estrutura define sempre `bUndoable` para **FALSE**. Se o servidor oferece suporte a desfazer e há uma operação que pode ser desfeita, chamar a implementação da classe base com `bUndoable` definida como **TRUE**.  
  
##  <a name="ondocwindowactivate"></a>COleServerDoc::OnDocWindowActivate  
 O framework chama essa função para ativar ou desativar uma janela de documento para edição no local.  
  
```  
virtual void OnDocWindowActivate(BOOL bActivate);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bActivate`  
 Especifica se a janela do documento deve ser ativada ou desativada.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão remove ou adiciona os elementos de interface de usuário de nível de quadro conforme apropriado. Substitua essa função para executar ações adicionais quando o documento que contém o item está ativado ou desativado.  
  
 Para obter mais informações, consulte o artigo [ativação](../../mfc/activation-cpp.md)...  
  
##  <a name="onexecolecmd"></a>COleServerDoc::OnExecOleCmd  
 O framework chama essa função para executar um comando especificado ou exibir a Ajuda para o comando.  
  
```  
virtual HRESULT OnExecOleCmd(
    const GUID* pguidCmdGroup,  
    DWORD nCmdID,  
    DWORD nCmdExecOpt,  
    VARIANTARG* pvarargIn,  
    VARIANTARG* pvarargOut);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pguidCmdGroup`  
 Um ponteiro para um GUID que identifica um conjunto de comandos. Pode ser **nulo** para indicar o grupo de comando padrão.  
  
 `nCmdID`  
 O comando a ser executado. Deve estar no grupo identificado pelo `pguidCmdGroup`.  
  
 *nCmdExecOut*  
 A maneira como o objeto deve executar o comando, um ou mais dos seguintes valores do **OLECMDEXECOPT** enumeração:  
  
 **OLECMDEXECOPT_DODEFAULT**  
  
 **OLECMDEXECOPT_PROMPTUSER**  
  
 **OLECMDEXECOPT_DONTPROMPTUSER**  
  
 **OLECMDEXECOPT_SHOWHELP**  
  
 `pvarargIn`  
 Ponteiro para uma **VARIANTARG** que contém os argumentos de entrada para o comando. Pode ser **nulo**.  
  
 `pvarargOut`  
 Ponteiro para uma **VARIANTARG** para receber os valores de retorno da saída do comando. Pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` se bem-sucedido; caso contrário, um dos seguintes códigos de erro:  
  
|Valor|Descrição|  
|-----------|-----------------|  
|**E_UNEXPECTED**|Ocorreu um erro inesperado|  
|**E_FAIL**|Erro|  
|**E_NOTIMPL**|Indica o MFC em si deve tentar converter e o comando de expedição|  
|**OLECMDERR_E_UNKNOWNGROUP**|`pguidCmdGroup`não **nulo** , mas não especifica um grupo de comando reconhecido|  
|**OLECMDERR_E_NOTSUPPORTED**|`nCmdID`não é reconhecido como um comando válido no grupo`pguidCmdGroup`|  
|**OLECMDERR_DISABLED**|O comando identificado pelo `nCmdID` está desabilitado e não pode ser executado|  
|**OLECMDERR_NOHELP**|Chamador solicitou ajuda sobre o comando identificado por `nCmdID` , mas nenhuma ajuda está disponível|  
|**OLECMDERR_CANCELED**|O usuário cancelou a execução|  
  
### <a name="remarks"></a>Comentários  
 `COleCmdUI`pode ser usado para habilitar, atualizar e definir outras propriedades do DocObject comandos de interface do usuário. Depois que os comandos são inicializados, você pode executá-los com `OnExecOleCmd`.  
  
 O framework chama a função antes de tentar converter e enviar um comando de documento OLE. Você não precisa substituir essa função para lidar com comandos de documento OLE padrão, mas você deve fornecer uma substituição para essa função para lidar com seus próprios comandos personalizados ou manipular os comandos que aceitam parâmetros ou retornam resultados.  
  
 A maioria dos comandos não usam argumentos ou valores de retorno. Para a maioria dos comandos o chamador pode passar **nulo**s para `pvarargIn` e `pvarargOut`. Para comandos que espera que os valores de entrada, o chamador pode declarar e inicializar uma **VARIANTARG** variável e passar um ponteiro para a variável `pvarargIn`. Para comandos que exigem um único valor, o argumento pode ser armazenado diretamente no **VARIANTARG** e passado para a função. Vários argumentos devem ser empacotados dentro de **VARIANTARG** usando um dos tipos com suporte (como `IDispatch` e **SAFEARRAY** ).  
  
 Da mesma forma, se um comando retorna argumentos o chamador deve declarar uma **VARIANTARG**, inicializá-lo para `VT_EMPTY`e passar seu endereço no `pvarargOut`. Se um comando retorna um único valor, o objeto pode armazenar esse valor diretamente no `pvarargOut`. Vários valores de saída devem ser empacotados de alguma forma apropriada para o **VARIANTARG**.  
  
 A implementação da classe base dessa função orientará o **OLE_COMMAND_MAP** estruturas associadas ao destino de comando e tente enviar o comando para um manipulador apropriado. A implementação da classe base funciona apenas com comandos que não aceitam argumentos ou valores de retorno. Se você precisar manipular comandos que aceitam argumentos ou valores de retorno, você deve substituir essa função e trabalhar com o `pvarargIn` e `pvarargOut` parâmetros por conta própria.  
  
##  <a name="onframewindowactivate"></a>COleServerDoc::OnFrameWindowActivate  
 O framework chama essa função quando a janela do quadro do aplicativo de contêiner é ativada ou desativada.  
  
```  
virtual void OnFrameWindowActivate(BOOL bActivate);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bActivate`  
 Especifica se a janela do quadro deve ser ativada ou desativada.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão cancela qualquer modos Ajuda em que a janela do quadro pode estar. Substitua essa função se você quiser executar um processamento especial quando a janela do quadro é ativada ou desativada.  
  
 Para obter mais informações, consulte o artigo [ativação](../../mfc/activation-cpp.md)...  
  
##  <a name="ongetembeddeditem"></a>COleServerDoc::OnGetEmbeddedItem  
 Chamado pela estrutura quando um aplicativo de contêiner chama o aplicativo do servidor para criar ou editar um item incorporado.  
  
```  
virtual COleServerItem* OnGetEmbeddedItem() = 0;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um item que representa o documento inteiro; **Nulo** se a operação falhou.  
  
### <a name="remarks"></a>Comentários  
 Não há nenhuma implementação padrão. Você deve substituir essa função para retornar um item que representa o documento inteiro. Esse valor de retorno deve ser um objeto de um `COleServerItem`-classe derivada.  
  
##  <a name="onreactivateandundo"></a>COleServerDoc::OnReactivateAndUndo  
 O framework chama essa função quando o usuário escolhe desfazer as alterações feitas em um item que foi ativado no local, alterado e subsequentemente desativado.  
  
```  
virtual BOOL OnReactivateAndUndo();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não faz nada exceto retorno **FALSE** para indicar falha.  
  
 Substitua essa função se seu aplicativo suporta desfazer. Geralmente você deve executar a operação de desfazer e ative o item chamando `ActivateInPlace`. Se o aplicativo de contêiner é escrito com a biblioteca Microsoft Foundation Class, chamando `COleClientItem::ReactivateAndUndo` faz com que essa função seja chamada.  
  
##  <a name="onresizeborder"></a>COleServerDoc::OnResizeBorder  
 O framework chama essa função quando janelas de quadro do aplicativo de contêiner altera o tamanho.  
  
```  
virtual void OnResizeBorder(
    LPCRECT lpRectBorder,  
    LPOLEINPLACEUIWINDOW lpUIWindow,  
    BOOL bFrame);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRectBorder`  
 Ponteiro para uma `RECT` estrutura ou um `CRect` objeto que especifica as coordenadas da borda.  
  
 `lpUIWindow`  
 Ponteiro para um objeto da classe **IOleInPlaceUIWindow** que possui a sessão de edição no local atual.  
  
 *bFrame*  
 **TRUE** se `lpUIWindow` aponta para a janela de quadro de nível superior do aplicativo de contêiner, ou **FALSE** se `lpUIWindow` aponta para a janela do quadro de nível de documento do aplicativo de contêiner.  
  
### <a name="remarks"></a>Comentários  
 Essa função é redimensionado e ajusta as barras de ferramentas e outros elementos de interface do usuário de acordo com o novo tamanho da janela.  
  
 Para obter mais informações, consulte [IOleInPlaceUIWindow](http://msdn.microsoft.com/library/windows/desktop/ms680716) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Isso é uma avançada substituível.  
  
##  <a name="onsethostnames"></a>COleServerDoc::OnSetHostNames  
 Chamado pela estrutura quando o contêiner define ou altera os nomes de host para este documento.  
  
```  
virtual void OnSetHostNames(
    LPCTSTR lpszHost,  
    LPCTSTR lpszHostObj);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszHost`  
 Ponteiro para uma cadeia de caracteres que especifica o nome do aplicativo recipiente.  
  
 `lpszHostObj`  
 Ponteiro para uma cadeia de caracteres que especifica o nome do contêiner do documento.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão altera o título do documento para todos os modos de exibição se referir a esse documento.  
  
 Substitua essa função se seu aplicativo define os títulos por meio de um mecanismo diferente.  
  
##  <a name="onsetitemrects"></a>COleServerDoc::OnSetItemRects  
 O framework chama essa função para posicionar a janela de quadro de edição in-loco na janela do quadro do aplicativo de contêiner.  
  
```  
virtual void OnSetItemRects(
    LPCRECT lpPosRect,  
    LPCRECT lpClipRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpPosRect`  
 Ponteiro para uma `RECT` estrutura ou um `CRect` objeto que especifica a posição da janela de quadro in-loco com relação à área do cliente do aplicativo de contêiner.  
  
 `lpClipRect`  
 Ponteiro para uma `RECT` estrutura ou um `CRect` objeto que especifica o retângulo de corte da janela de quadro in-loco com relação à área do cliente do aplicativo de contêiner.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para atualizar o fator de zoom da exibição, se necessário.  
  
 Esta função geralmente é chamada em resposta a um `RequestPositionChange` chamar, embora possa ser chamado a qualquer momento pelo contêiner para solicitar uma alteração de posição do item no local.  
  
##  <a name="onshowcontrolbars"></a>COleServerDoc::OnShowControlBars  
 O framework chama essa função para mostrar ou ocultar as barras de controle do aplicativo de servidor associadas à janela de quadro identificada por `pFrameWnd`.  
  
```  
virtual void OnShowControlBars(
    CFrameWnd* pFrameWnd,  
    BOOL bShow);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFrameWnd`  
 Ponteiro para a janela do quadro cujas barras de controle devem ser ocultadas ou exibidas.  
  
 `bShow`  
 Determina se as barras de controle são mostradas ou ocultadas.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão enumera todas as barras de controle pertencentes a essa janela de quadro e mostra ou oculta-los.  
  
##  <a name="onshowdocument"></a>COleServerDoc::OnShowDocument  
 O framework chama o `OnShowDocument` funcionar quando o documento do servidor deve ser ocultado ou exibido.  
  
```  
virtual void OnShowDocument(BOOL bShow);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bShow`  
 Especifica se a interface do usuário para o documento deve ser mostrado ou ocultado.  
  
### <a name="remarks"></a>Comentários  
 Se `bShow` é **TRUE**, a implementação padrão ativa o aplicativo de servidor, se necessário e faz com que o aplicativo de contêiner rolar a janela para que o item está visível. Se `bShow` é **FALSE**, a implementação padrão desativa o item por meio de uma chamada para `OnDeactivate`, destrói ou oculta todas as janelas de quadro que foram criadas para o documento, exceto o primeiro. Se nenhum documento visível permanecer, a implementação padrão oculta o aplicativo do servidor.  
  
##  <a name="onupdatedocument"></a>COleServerDoc::OnUpdateDocument  
 Chamado pela estrutura quando salvar um documento que é um item inserido em um documento composto.  
  
```  
virtual BOOL OnUpdateDocument();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o documento foi atualizado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão chama o [COleServerDoc::NotifySaved](#notifysaved) e [COleServerDoc::SaveEmbedding](#saveembedding) funções de membro e marca o documento como limpar. Substitua essa função se você quiser executar especiais de processamento ao atualizar um item incorporado.  
  
##  <a name="requestpositionchange"></a>COleServerDoc::RequestPositionChange  
 Chame essa função de membro para que o aplicativo de contêiner de alterar a posição do item.  
  
```  
void RequestPositionChange(LPCRECT lpPosRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpPosRect`  
 Ponteiro para uma `RECT` estrutura ou um `CRect` objeto que contém a nova posição do item.  
  
### <a name="remarks"></a>Comentários  
 Essa função é normalmente chamada (juntamente com `UpdateAllItems`) quando os dados em um item ativo no local foi alterada. Após essa chamada, o contêiner pode ou não pode executar a alteração chamando `OnSetItemRects`. A posição resultante pode ser diferente do solicitado.  
  
##  <a name="saveembedding"></a>COleServerDoc::SaveEmbedding  
 Chame essa função para informar o aplicativo de contêiner para salvar o objeto inserido.  
  
```  
void SaveEmbedding();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função é chamada automaticamente de `OnUpdateDocument`. Observe que essa função faz com que o item seja atualizado no disco, por isso geralmente é chamado como resultado de uma ação específica do usuário.  
  
##  <a name="scrollcontainerby"></a>COleServerDoc::ScrollContainerBy  
 Chamar o `ScrollContainerBy` a função de membro para rolar o documento contêiner pela quantidade, em pixels, indicado por `sizeScroll`.  
  
```  
BOOL ScrollContainerBy(CSize sizeScroll);
```  
  
### <a name="parameters"></a>Parâmetros  
 `sizeScroll`  
 Indica o quanto o documento do contêiner é Role.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Valores positivos indicam rolando para baixo e para a direita; valores negativos indicam rolar para cima e para a esquerda.  
  
##  <a name="updateallitems"></a>COleServerDoc::UpdateAllItems  
 Chame essa função para notificar todos os itens vinculados conectados ao documento que o documento foi alterado.  
  
```  
void UpdateAllItems(
    COleServerItem* pSender,  
    LPARAM lHint = 0L,  
    CObject* pHint = NULL,  
    DVASPECT nDrawAspect = DVASPECT_CONTENT);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pSender`  
 Ponteiro para o item que modificou o documento, ou **nulo** se todos os itens devem ser atualizadas.  
  
 `lHint`  
 Contém informações sobre a modificação.  
  
 `pHint`  
 Ponteiro para um objeto de armazenamento de informações sobre a modificação.  
  
 `nDrawAspect`  
 Determina como o item a ser desenhada. Este é um valor da `DVASPECT` enumeração. Esse parâmetro pode ter um dos seguintes valores:  
  
- `DVASPECT_CONTENT`Item é representado de forma que ele pode ser exibido como um objeto incorporado dentro do seu contêiner.  
  
- `DVASPECT_THUMBNAIL`Item será renderizado em uma representação "em miniatura" para que ela possa ser exibida em uma ferramenta de procura.  
  
- `DVASPECT_ICON`Item é representado por um ícone.  
  
- `DVASPECT_DOCPRINT`Item é representado como se ela fosse impressa usando o comando Imprimir no menu arquivo.  
  
### <a name="remarks"></a>Comentários  
 Você normalmente chama essa função depois que o usuário altera o documento do servidor. Se um item OLE é vinculado ao documento com um vínculo automático, o item é atualizado para refletir as alterações. Em aplicativos de contêiner gravados com a biblioteca Microsoft Foundation Class, o [OnChange](../../mfc/reference/coleclientitem-class.md#onchange) função de membro `COleClientItem` é chamado.  
  
 Essa função chama o `OnUpdate` a função de membro para cada um dos itens do documento exceto o envio de itens, passando `pHint`, `lHint`, e `nDrawAspect`. Use esses parâmetros para passar informações para os itens sobre as modificações feitas no documento. Você pode codificar usando informações `lHint` ou você pode definir um `CObject`-classe para armazenar informações sobre as modificações e passe um objeto usando essa classe derivada `pHint`. Substituir o `OnUpdate` função de membro em sua `COleServerItem`-derivado da classe para otimizar a atualização de cada item dependendo se sua apresentação foi alterada.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC HIERSVR](../../visual-cpp-samples.md)   
 [Classe COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleDocument](../../mfc/reference/coledocument-class.md)   
 [Classe COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md)   
 [Classe COleTemplateServer](../../mfc/reference/coletemplateserver-class.md)

