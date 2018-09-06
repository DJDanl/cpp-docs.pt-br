---
title: Classe COleClientItem | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COleClientItem
- AFXOLE/COleClientItem
- AFXOLE/COleClientItem::COleClientItem
- AFXOLE/COleClientItem::Activate
- AFXOLE/COleClientItem::ActivateAs
- AFXOLE/COleClientItem::AttachDataObject
- AFXOLE/COleClientItem::CanCreateFromData
- AFXOLE/COleClientItem::CanCreateLinkFromData
- AFXOLE/COleClientItem::CanPaste
- AFXOLE/COleClientItem::CanPasteLink
- AFXOLE/COleClientItem::Close
- AFXOLE/COleClientItem::ConvertTo
- AFXOLE/COleClientItem::CopyToClipboard
- AFXOLE/COleClientItem::CreateCloneFrom
- AFXOLE/COleClientItem::CreateFromClipboard
- AFXOLE/COleClientItem::CreateFromData
- AFXOLE/COleClientItem::CreateFromFile
- AFXOLE/COleClientItem::CreateLinkFromClipboard
- AFXOLE/COleClientItem::CreateLinkFromData
- AFXOLE/COleClientItem::CreateLinkFromFile
- AFXOLE/COleClientItem::CreateNewItem
- AFXOLE/COleClientItem::CreateStaticFromClipboard
- AFXOLE/COleClientItem::CreateStaticFromData
- AFXOLE/COleClientItem::Deactivate
- AFXOLE/COleClientItem::DeactivateUI
- AFXOLE/COleClientItem::Delete
- AFXOLE/COleClientItem::DoDragDrop
- AFXOLE/COleClientItem::DoVerb
- AFXOLE/COleClientItem::Draw
- AFXOLE/COleClientItem::GetActiveView
- AFXOLE/COleClientItem::GetCachedExtent
- AFXOLE/COleClientItem::GetClassID
- AFXOLE/COleClientItem::GetClipboardData
- AFXOLE/COleClientItem::GetDocument
- AFXOLE/COleClientItem::GetDrawAspect
- AFXOLE/COleClientItem::GetExtent
- AFXOLE/COleClientItem::GetIconFromRegistry
- AFXOLE/COleClientItem::GetIconicMetafile
- AFXOLE/COleClientItem::GetInPlaceWindow
- AFXOLE/COleClientItem::GetItemState
- AFXOLE/COleClientItem::GetLastStatus
- AFXOLE/COleClientItem::GetLinkUpdateOptions
- AFXOLE/COleClientItem::GetType
- AFXOLE/COleClientItem::GetUserType
- AFXOLE/COleClientItem::IsInPlaceActive
- AFXOLE/COleClientItem::IsLinkUpToDate
- AFXOLE/COleClientItem::IsModified
- AFXOLE/COleClientItem::IsOpen
- AFXOLE/COleClientItem::IsRunning
- AFXOLE/COleClientItem::OnActivate
- AFXOLE/COleClientItem::OnActivateUI
- AFXOLE/COleClientItem::OnChange
- AFXOLE/COleClientItem::OnDeactivate
- AFXOLE/COleClientItem::OnDeactivateUI
- AFXOLE/COleClientItem::OnGetClipboardData
- AFXOLE/COleClientItem::OnInsertMenus
- AFXOLE/COleClientItem::OnRemoveMenus
- AFXOLE/COleClientItem::OnSetMenu
- AFXOLE/COleClientItem::OnShowControlBars
- AFXOLE/COleClientItem::OnUpdateFrameTitle
- AFXOLE/COleClientItem::ReactivateAndUndo
- AFXOLE/COleClientItem::Release
- AFXOLE/COleClientItem::Reload
- AFXOLE/COleClientItem::Run
- AFXOLE/COleClientItem::SetDrawAspect
- AFXOLE/COleClientItem::SetExtent
- AFXOLE/COleClientItem::SetHostNames
- AFXOLE/COleClientItem::SetIconicMetafile
- AFXOLE/COleClientItem::SetItemRects
- AFXOLE/COleClientItem::SetLinkUpdateOptions
- AFXOLE/COleClientItem::SetPrintDevice
- AFXOLE/COleClientItem::UpdateLink
- AFXOLE/COleClientItem::CanActivate
- AFXOLE/COleClientItem::OnChangeItemPosition
- AFXOLE/COleClientItem::OnDeactivateAndUndo
- AFXOLE/COleClientItem::OnDiscardUndoState
- AFXOLE/COleClientItem::OnGetClipRect
- AFXOLE/COleClientItem::OnGetItemPosition
- AFXOLE/COleClientItem::OnGetWindowContext
- AFXOLE/COleClientItem::OnScrollBy
- AFXOLE/COleClientItem::OnShowItem
dev_langs:
- C++
helpviewer_keywords:
- COleClientItem [MFC], COleClientItem
- COleClientItem [MFC], Activate
- COleClientItem [MFC], ActivateAs
- COleClientItem [MFC], AttachDataObject
- COleClientItem [MFC], CanCreateFromData
- COleClientItem [MFC], CanCreateLinkFromData
- COleClientItem [MFC], CanPaste
- COleClientItem [MFC], CanPasteLink
- COleClientItem [MFC], Close
- COleClientItem [MFC], ConvertTo
- COleClientItem [MFC], CopyToClipboard
- COleClientItem [MFC], CreateCloneFrom
- COleClientItem [MFC], CreateFromClipboard
- COleClientItem [MFC], CreateFromData
- COleClientItem [MFC], CreateFromFile
- COleClientItem [MFC], CreateLinkFromClipboard
- COleClientItem [MFC], CreateLinkFromData
- COleClientItem [MFC], CreateLinkFromFile
- COleClientItem [MFC], CreateNewItem
- COleClientItem [MFC], CreateStaticFromClipboard
- COleClientItem [MFC], CreateStaticFromData
- COleClientItem [MFC], Deactivate
- COleClientItem [MFC], DeactivateUI
- COleClientItem [MFC], Delete
- COleClientItem [MFC], DoDragDrop
- COleClientItem [MFC], DoVerb
- COleClientItem [MFC], Draw
- COleClientItem [MFC], GetActiveView
- COleClientItem [MFC], GetCachedExtent
- COleClientItem [MFC], GetClassID
- COleClientItem [MFC], GetClipboardData
- COleClientItem [MFC], GetDocument
- COleClientItem [MFC], GetDrawAspect
- COleClientItem [MFC], GetExtent
- COleClientItem [MFC], GetIconFromRegistry
- COleClientItem [MFC], GetIconicMetafile
- COleClientItem [MFC], GetInPlaceWindow
- COleClientItem [MFC], GetItemState
- COleClientItem [MFC], GetLastStatus
- COleClientItem [MFC], GetLinkUpdateOptions
- COleClientItem [MFC], GetType
- COleClientItem [MFC], GetUserType
- COleClientItem [MFC], IsInPlaceActive
- COleClientItem [MFC], IsLinkUpToDate
- COleClientItem [MFC], IsModified
- COleClientItem [MFC], IsOpen
- COleClientItem [MFC], IsRunning
- COleClientItem [MFC], OnActivate
- COleClientItem [MFC], OnActivateUI
- COleClientItem [MFC], OnChange
- COleClientItem [MFC], OnDeactivate
- COleClientItem [MFC], OnDeactivateUI
- COleClientItem [MFC], OnGetClipboardData
- COleClientItem [MFC], OnInsertMenus
- COleClientItem [MFC], OnRemoveMenus
- COleClientItem [MFC], OnSetMenu
- COleClientItem [MFC], OnShowControlBars
- COleClientItem [MFC], OnUpdateFrameTitle
- COleClientItem [MFC], ReactivateAndUndo
- COleClientItem [MFC], Release
- COleClientItem [MFC], Reload
- COleClientItem [MFC], Run
- COleClientItem [MFC], SetDrawAspect
- COleClientItem [MFC], SetExtent
- COleClientItem [MFC], SetHostNames
- COleClientItem [MFC], SetIconicMetafile
- COleClientItem [MFC], SetItemRects
- COleClientItem [MFC], SetLinkUpdateOptions
- COleClientItem [MFC], SetPrintDevice
- COleClientItem [MFC], UpdateLink
- COleClientItem [MFC], CanActivate
- COleClientItem [MFC], OnChangeItemPosition
- COleClientItem [MFC], OnDeactivateAndUndo
- COleClientItem [MFC], OnDiscardUndoState
- COleClientItem [MFC], OnGetClipRect
- COleClientItem [MFC], OnGetItemPosition
- COleClientItem [MFC], OnGetWindowContext
- COleClientItem [MFC], OnScrollBy
- COleClientItem [MFC], OnShowItem
ms.assetid: 7f571b7c-2758-4839-847a-0cf1ef643128
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 43f9e1b342d6de1a93906d2469d0fd1eb211e886
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43764999"
---
# <a name="coleclientitem-class"></a>Classe COleClientItem
Define a interface de contêiner para itens OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleClientItem : public CDocItem  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleClientItem::COleClientItem](#coleclientitem)|Constrói um objeto `COleClientItem`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleClientItem::Activate](#activate)|Abre o item OLE para uma operação e, em seguida, executa o verbo especificado.|  
|[COleClientItem::ActivateAs](#activateas)|Ativa o item como outro tipo.|  
|[COleClientItem::AttachDataObject](#attachdataobject)|Acessa os dados no objeto OLE.|  
|[COleClientItem::CanCreateFromData](#cancreatefromdata)|Indica se um aplicativo de contêiner pode criar um objeto inserido.|  
|[COleClientItem::CanCreateLinkFromData](#cancreatelinkfromdata)|Indica se um aplicativo de contêiner pode criar um objeto vinculado.|  
|[COleClientItem::CanPaste](#canpaste)|Indica se a área de transferência contém um item OLE incorporável ou estático.|  
|[COleClientItem::CanPasteLink](#canpastelink)|Indica se a área de transferência contém um item OLE vinculável.|  
|[COleClientItem::Close](#close)|Fecha um link para um servidor, mas não destrói o item OLE.|  
|[COleClientItem::ConvertTo](#convertto)|Converte o item em outro tipo.|  
|[COleClientItem::CopyToClipboard](#copytoclipboard)|Copia o item OLE para a área de transferência.|  
|[COleClientItem::CreateCloneFrom](#createclonefrom)|Cria uma duplicata de um item existente.|  
|[COleClientItem::CreateFromClipboard](#createfromclipboard)|Cria um item inserido da área de transferência.|  
|[COleClientItem::CreateFromData](#createfromdata)|Cria um item inserido de um objeto de dados.|  
|[COleClientItem::CreateFromFile](#createfromfile)|Cria um item inserido de um arquivo.|  
|[COleClientItem::CreateLinkFromClipboard](#createlinkfromclipboard)|Cria um item vinculado da área de transferência.|  
|[COleClientItem::CreateLinkFromData](#createlinkfromdata)|Cria um item vinculado de um objeto de dados.|  
|[COleClientItem::CreateLinkFromFile](#createlinkfromfile)|Cria um item vinculado de um arquivo.|  
|[COleClientItem::CreateNewItem](#createnewitem)|Cria um novo item inserido, iniciando o aplicativo de servidor.|  
|[COleClientItem::CreateStaticFromClipboard](#createstaticfromclipboard)|Cria um item estático da área de transferência.|  
|[COleClientItem::CreateStaticFromData](#createstaticfromdata)|Cria um item estático de um objeto de dados.|  
|[COleClientItem::Deactivate](#deactivate)|Desativa o item.|  
|[COleClientItem::DeactivateUI](#deactivateui)|Restaura a interface do usuário do aplicativo de contêiner para seu estado original.|  
|[COleClientItem::Delete](#delete)|Exclui ou fecha o item OLE se fosse um item vinculado.|  
|[COleClientItem::DoDragDrop](#dodragdrop)|Executa uma operação de arrastar e soltar.|  
|[COleClientItem::DoVerb](#doverb)|Executa o verbo especificado.|  
|[COleClientItem::Draw](#draw)|Desenha o item OLE.|  
|[COleClientItem::GetActiveView](#getactiveview)|Obtém a exibição na qual o item é ativado em vigor.|  
|[COleClientItem::GetCachedExtent](#getcachedextent)|Retorna os limites do retângulo do item OLE.|  
|[COleClientItem::GetClassID](#getclassid)|Obtém a ID de classe. do item presente|  
|[COleClientItem::GetClipboardData](#getclipboarddata)|Obtém os dados que devem ser colocados na área de transferência, chamando o `CopyToClipboard` função de membro.|  
|[COleClientItem::GetDocument](#getdocument)|Retorna o `COleDocument` objeto que contém o item presente.|  
|[COleClientItem::GetDrawAspect](#getdrawaspect)|Obtém o modo de exibição atual do item para renderização.|  
|[COleClientItem::GetExtent](#getextent)|Retorna os limites do retângulo do item OLE.|  
|[COleClientItem::GetIconFromRegistry](#geticonfromregistry)|Recupera um identificador para um ícone associado ao servidor de um CLSID particular.|  
|[COleClientItem::GetIconicMetafile](#geticonicmetafile)|Obtém o metarquivo usado para desenhar o ícone do item.|  
|[COleClientItem::GetInPlaceWindow](#getinplacewindow)|Retorna um ponteiro para a janela de edição do item no local.|  
|[COleClientItem::GetItemState](#getitemstate)|Obtém o estado do item atual.|  
|[COleClientItem::GetLastStatus](#getlaststatus)|Retorna o status da última operação OLE.|  
|[COleClientItem::GetLinkUpdateOptions](#getlinkupdateoptions)|Retorna o modo de atualização para um item vinculado (recurso avançado).|  
|[COleClientItem::GetType](#gettype)|Retorna o tipo (incorporado, vinculado ou estático) do item OLE.|  
|[COleClientItem::GetUserType](#getusertype)|Obtém uma cadeia de caracteres que descreve o tipo do item.|  
|[COleClientItem::IsInPlaceActive](#isinplaceactive)|Retornará TRUE se o item está ativo no local.|  
|[COleClientItem::IsLinkUpToDate](#islinkuptodate)|Retorna TRUE se um item vinculado é atualizado com seu documento de origem.|  
|[COleClientItem::IsModified](#ismodified)|Retorna TRUE se o item tiver sido modificado desde a última salvo.|  
|[COleClientItem::IsOpen](#isopen)|Retorna TRUE se o item está atualmente aberta no aplicativo do servidor.|  
|[COleClientItem::IsRunning](#isrunning)|Retornará TRUE se o aplicativo de servidor do item está sendo executado.|  
|[COleClientItem::OnActivate](#onactivate)|Chamado pelo framework para notificar o item que está ativado.|  
|[COleClientItem::OnActivateUI](#onactivateui)|Chamado pelo framework para notificar o item que ele é ativado e deve mostrar sua interface do usuário.|  
|[COleClientItem::OnChange](#onchange)|Chamado quando o servidor de item OLE é alterada. Implementação necessários.|  
|[COleClientItem::OnDeactivate](#ondeactivate)|Chamado pelo framework quando um item é desativado.|  
|[COleClientItem::OnDeactivateUI](#ondeactivateui)|Chamado pelo framework quando o servidor tiver removido a sua interface do usuário no local.|  
|[COleClientItem::OnGetClipboardData](#ongetclipboarddata)|Chamado pelo framework para obter os dados a serem copiados para a área de transferência.|  
|[COleClientItem::OnInsertMenus](#oninsertmenus)|Chamado pelo framework para criar um menu composto.|  
|[COleClientItem::OnRemoveMenus](#onremovemenus)|Chamado pelo framework para remover os menus do contêiner de um menu composto.|  
|[COleClientItem::OnSetMenu](#onsetmenu)|Chamado pelo framework para instalar e remover um menu composto.|  
|[COleClientItem::OnShowControlBars](#onshowcontrolbars)|Chamado pelo framework para mostrar e ocultar as barras de controle.|  
|[COleClientItem::OnUpdateFrameTitle](#onupdateframetitle)|Chamado pelo framework para atualizar a barra de título da janela do quadro.|  
|[COleClientItem::ReactivateAndUndo](#reactivateandundo)|Reativa o item e desfaz a última operação de edição in-loco.|  
|[COleClientItem::Release](#release)|Libera a conexão para uma item vinculada de OLE e fecha-la se ela estiver aberta. Destrói o item do cliente.|  
|[COleClientItem::Reload](#reload)|Recarrega o item após uma chamada para `ActivateAs`.|  
|[COleClientItem::Run](#run)|Executa o aplicativo associado ao item.|  
|[COleClientItem::SetDrawAspect](#setdrawaspect)|Define o modo de exibição atual para a renderização do item.|  
|[COleClientItem::SetExtent](#setextent)|Define o retângulo delimitador do item OLE.|  
|[COleClientItem::SetHostNames](#sethostnames)|Define os nomes do servidor exibe ao editar o item OLE.|  
|[COleClientItem::SetIconicMetafile](#seticonicmetafile)|Armazena em cache o metarquivo usado para desenhar o ícone do item.|  
|[COleClientItem::SetItemRects](#setitemrects)|Define o retângulo delimitador do item.|  
|[COleClientItem::SetLinkUpdateOptions](#setlinkupdateoptions)|Define o modo de atualização para um item vinculado (recurso avançado).|  
|[COleClientItem::SetPrintDevice](#setprintdevice)|Define o dispositivo de destino de impressão para este item do cliente.|  
|[COleClientItem::UpdateLink](#updatelink)|Atualiza o cache de apresentação de um item.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleClientItem::CanActivate](#canactivate)|Chamado pelo framework para determinar se a ativação no local é permitida.|  
|[COleClientItem::OnChangeItemPosition](#onchangeitemposition)|Chamado pelo framework quando muda de posição de um item.|  
|[COleClientItem::OnDeactivateAndUndo](#ondeactivateandundo)|Chamado pelo framework para desfazer após a ativação.|  
|[COleClientItem::OnDiscardUndoState](#ondiscardundostate)|Chamado pelo framework para descartar informações de estado de desfazer do item.|  
|[COleClientItem::OnGetClipRect](#ongetcliprect)|Chamado pelo framework para obter as coordenadas do retângulo de recorte do item.|  
|[COleClientItem::OnGetItemPosition](#ongetitemposition)|Chamado pelo framework para obter a posição do item em relação ao modo de exibição.|  
|[COleClientItem::OnGetWindowContext](#ongetwindowcontext)|Chamado pelo framework quando um item é ativado em vigor.|  
|[COleClientItem::OnScrollBy](#onscrollby)|Chamado pelo framework para rolar o item na exibição.|  
|[COleClientItem::OnShowItem](#onshowitem)|Chamado pelo framework para exibir o item OLE.|  
  
## <a name="remarks"></a>Comentários  
 Um item OLE representa os dados, criados e mantidos por um aplicativo de servidor, que pode ser "diretamente" incorporado em um documento para que ele apareça para o usuário seja um único documento. O resultado é um "documento composto" composto por item OLE e que contém o documento.  
  
 Um item OLE pode ser inserido ou vinculado. Se for inserido, seus dados são armazenados como parte do documento composto. Se estiver vinculada, seus dados são armazenados como parte de um arquivo separado criado pelo aplicativo de servidor, e apenas um link para esse arquivo é armazenado no documento composto. Todos os itens OLE contêm informações que especificam o aplicativo de servidor que deve ser chamado para editá-los.  
  
 `COleClientItem` define várias funções substituíveis que são chamadas em resposta às solicitações do aplicativo de servidor; sobre esses substituíveis geralmente agem como notificações. Isso permite que o aplicativo de servidor para informar o contêiner de alterações que o usuário fizer ao editar o item OLE, ou para recuperar as informações necessárias durante a edição.  
  
 `COleClientItem` pode ser usado com o [COleDocument](../../mfc/reference/coledocument-class.md), [COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md), ou [COleServerDoc](../../mfc/reference/coleserverdoc-class.md) classe. Para usar `COleClientItem`, derive uma classe dele e implementar o [OnChange](#onchange) função de membro, que define como o contêiner responde às alterações feitas ao item. Para dar suporte à ativação in-loco, substituir os [OnGetItemPosition](#ongetitemposition) função de membro. Essa função fornece informações sobre a posição exibida do item OLE.  
  
 Para obter mais informações sobre como usar a interface de contêiner, consulte os artigos [contêineres: Implementando um contêiner](../../mfc/containers-implementing-a-container.md) e [ativação](../../mfc/activation-cpp.md).  
  
> [!NOTE]
>  O SDK do Windows se refere a itens vinculados e inseridos como "objetos" e se refere a tipos de itens como "classes". Esta referência usa o termo "item" para distinguir a entidade OLE de objeto C++ correspondente e o termo "tipo" para distinguir a categoria OLE da classe C++.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CDocItem](../../mfc/reference/cdocitem-class.md)  
  
 `COleClientItem`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  
  
##  <a name="activate"></a>  COleClientItem::Activate  
 Chame essa função para executar o verbo especificado em vez de [DoVerb](#doverb) para que você possa fazer seu próprio processamento quando uma exceção é lançada.  
  
```  
void Activate(
    LONG nVerb,  
    CView* pView,  
    LPMSG lpMsg = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nVerb*  
 Especifica o verbo a ser executado. Ele pode ser um dos seguintes:  
  
|Valor|Significado|Símbolo|  
|-----------|-------------|------------|  
|- 0|Verbo primário|OLEIVERB_PRIMARY|  
|- 1|Verbo secundário|(Nenhum)|  
|- 1|Item de exibição para edição|OLEIVERB_SHOW|  
|- 2|Editar item na janela separada|OLEIVERB_OPEN|  
|- 3|Ocultar o item|OLEIVERB_HIDE|  
  
 O valor de-1 normalmente é um alias para outro verbo. Se não há suporte para a edição aberto, -2 tem o mesmo efeito que -1. Para obter valores adicionais, consulte [IOleObject:: DoVerb](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb) no SDK do Windows.  
  
 *pView*  
 Ponteiro para a janela de exibição de contêiner que contém o item OLE; Isso é usado pelo aplicativo servidor para ativação no local. Esse parâmetro deve ser NULL se o contêiner não dá suporte a ativação in-loco.  
  
 *lpMsg*  
 Ponteiro para a mensagem que causou o item a ser ativado.  
  
### <a name="remarks"></a>Comentários  
 Se o aplicativo de servidor foi escrito usando a biblioteca Microsoft Foundation Class, essa função faz com que o [OnDoVerb](../../mfc/reference/coleserveritem-class.md#ondoverb) função de membro de correspondente `COleServerItem` objeto a ser executado.  
  
 Se o verbo primário é editar e zero for especificada na *nVerb* parâmetro, o aplicativo de servidor é iniciado para permitir que o item OLE a ser editado. Se o aplicativo de contêiner dá suporte à ativação in-loco, a edição pode ser feita em vigor. Se o contêiner não dá suporte a ativação no local (ou se o verbo Open for especificado), o servidor é iniciado em uma janela separada e edição pode ser feita lá. Normalmente, quando o usuário do aplicativo recipiente clica duas vezes no item OLE, o valor para o verbo primário na *nVerb* parâmetro determina qual ação o usuário pode executar. No entanto, se o servidor oferecer suporte a apenas uma ação, ele usa essa ação, não importa qual valor é especificado na *nVerb* parâmetro.  
  
 Para obter mais informações, consulte [IOleObject:: DoVerb](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb) no SDK do Windows.  
  
##  <a name="activateas"></a>  COleClientItem::ActivateAs  
 Usa recursos de conversão de objeto do OLE para ativar o item como se fosse um item do tipo especificado pelo *clsidNew*.  
  
```  
virtual BOOL ActivateAs(
    LPCTSTR lpszUserType,  
    REFCLSID clsidOld,  
    REFCLSID clsidNew);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszUserType*  
 Ponteiro para uma cadeia de caracteres que representa o tipo de usuário de destino, como "Documento do Word".  
  
 *clsidOld*  
 Uma referência à classe de atual do item ID. A ID de classe deve representar o tipo do objeto real, conforme armazenado, a menos que ele é um link. Nesse caso, ele deve ser o CLSID do item ao qual o link se refere. O [COleConvertDialog](../../mfc/reference/coleconvertdialog-class.md) fornece automaticamente a ID de classe correto para o item.  
  
 *clsidNew*  
 Uma referência para a ID de classe de destino.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Isso é chamado automaticamente pelo [COleConvertDialog::DoConvert](../../mfc/reference/coleconvertdialog-class.md#doconvert). Ele não é geralmente chamado diretamente.  
  
##  <a name="attachdataobject"></a>  COleClientItem::AttachDataObject  
 Chame essa função para inicializar uma [COleDataObject](../../mfc/reference/coledataobject-class.md) para acessar os dados em um item OLE.  
  
```  
void AttachDataObject(COleDataObject& rDataObject) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *rDataObject*  
 Referência a um `COleDataObject` objeto será inicializado para permitir o acesso aos dados no item OLE.  
  
##  <a name="canactivate"></a>  COleClientItem::CanActivate  
 Chamado pelo framework quando o usuário solicita a ativação no local do item OLE; o valor de retorno dessa função determina se a ativação no local é permitida.  
  
```  
virtual BOOL CanActivate();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a ativação in-loco é permitida. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão permite que a ativação no local se o contêiner tiver uma janela válida. Substitua essa função para implementar uma lógica especial para aceitar ou recusar a solicitação de ativação. Por exemplo, uma solicitação de ativação pode ser recusada se o item OLE é muito pequeno ou não está visível no momento.  
  
 Para obter mais informações, consulte [IOleInPlaceSite::CanInPlaceActivate](/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-caninplaceactivate) no SDK do Windows.  
  
##  <a name="cancreatefromdata"></a>  COleClientItem::CanCreateFromData  
 Verifica se um aplicativo de contêiner pode criar um objeto incorporado a determinado `COleDataObject` objeto.  
  
```  
static BOOL PASCAL CanCreateFromData(const COleDataObject* pDataObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDataObject*  
 Ponteiro para o [COleDataObject](../../mfc/reference/coledataobject-class.md) objeto do qual o item OLE deve ser criado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o contêiner pode criar um objeto incorporado a `COleDataObject` objeto; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O `COleDataObject` nas transferências de dados, a classe é usada para recuperar dados em vários formatos da área de transferência, por meio de arrastar e soltar, ou de um item OLE inserido.  
  
 Contêineres podem usar essa função para optar por habilitar ou desabilitar os comandos Editar colar e editar Colar especial.  
  
 Para obter mais informações, consulte o artigo [objetos de dados e fontes de dados (OLE)](../../mfc/data-objects-and-data-sources-ole.md).  
  
##  <a name="cancreatelinkfromdata"></a>  COleClientItem::CanCreateLinkFromData  
 Verifica se um aplicativo de contêiner pode criar um objeto vinculado a partir de determinado `COleDataObject` objeto.  
  
```  
static BOOL PASCAL CanCreateLinkFromData(const COleDataObject* pDataObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDataObject*  
 Ponteiro para o [COleDataObject](../../mfc/reference/coledataobject-class.md) objeto do qual o item OLE deve ser criado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o contêiner pode criar um objeto vinculado a partir de `COleDataObject` objeto.  
  
### <a name="remarks"></a>Comentários  
 O `COleDataObject` nas transferências de dados, a classe é usada para recuperar dados em vários formatos da área de transferência, por meio de arrastar e soltar, ou de um item OLE inserido.  
  
 Contêineres podem usar essa função para optar por habilitar ou desabilitar os comandos Editar Colar especial e Editar Link de colar.  
  
 Para obter mais informações, consulte o artigo [objetos de dados e fontes de dados (OLE)](../../mfc/data-objects-and-data-sources-ole.md).  
  
##  <a name="canpaste"></a>  COleClientItem::CanPaste  
 Chame essa função para ver se um item OLE inserido pode ser colado da área de transferência.  
  
```  
static BOOL PASCAL CanPaste();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se um item OLE inserido pode ser colado da área de transferência; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [OleGetClipboard](/windows/desktop/api/ole2/nf-ole2-olegetclipboard) e [OleQueryCreateFromData](/windows/desktop/api/ole2/nf-ole2-olequerycreatefromdata) no SDK do Windows.  
  
##  <a name="canpastelink"></a>  COleClientItem::CanPasteLink  
 Chame essa função para ver se um item OLE vinculado pode ser colado da área de transferência.  
  
```  
static BOOL PASCAL CanPasteLink();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se um item OLE vinculado pode ser colado da área de transferência; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [OleGetClipboard](/windows/desktop/api/ole2/nf-ole2-olegetclipboard) e [OleQueryLinkFromData](/windows/desktop/api/ole2/nf-ole2-olequerylinkfromdata) no SDK do Windows.  
  
##  <a name="close"></a>  COleClientItem::Close  
 Chame essa função para alterar o estado de um item OLE do estado de execução para o estado carregado, ou seja, carregado com seu manipulador na memória, mas com o servidor não está em execução.  
  
```  
void Close(OLECLOSE dwCloseOption = OLECLOSE_SAVEIFDIRTY);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwCloseOption*  
 Sinalizador que especifica em quais circunstâncias o item OLE é salvo quando ele é retornado para o estado carregado. Ele pode ter um dos seguintes valores:  
  
- Item OLECLOSE_SAVEIFDIRTY salvar o OLE.  
  
- OLECLOSE_NOSAVE não salvar o item OLE.  
  
- OLECLOSE_PROMPTSAVE solicitar ao usuário se deve salvar o item OLE.  
  
### <a name="remarks"></a>Comentários  
 Essa função não tem efeito quando o item OLE não está em execução.  
  
 Para obter mais informações, consulte [IOleObject::Close](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close) no SDK do Windows.  
  
##  <a name="coleclientitem"></a>  COleClientItem::COleClientItem  
 Constrói um `COleClientItem` do objeto e o adiciona à coleção do documento do contêiner de itens de documento, que constrói apenas o objeto de C++ e não executa qualquer inicialização OLE.  
  
```  
COleClientItem(COleDocument* pContainerDoc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pContainerDoc*  
 Ponteiro para o documento de contêiner que contém esse item. Isso pode ser qualquer [COleDocument](../../mfc/reference/coledocument-class.md) derivativo.  
  
### <a name="remarks"></a>Comentários  
 Se você passar um ponteiro nulo, nenhuma adição é feita para o documento contêiner. Você deve chamar explicitamente [COleDocument::AddItem](../../mfc/reference/coledocument-class.md#additem).  
  
 Você deve chamar uma das seguintes funções de membro de criação antes de usar o item OLE:  
  
- [CreateFromClipboard](#createfromclipboard)  
  
- [CreateFromData](#createfromdata)  
  
- [CreateFromFile](#createfromfile)  
  
- [CreateStaticFromClipboard](#createstaticfromclipboard)  
  
- [CreateStaticFromData](#createstaticfromdata)  
  
- [CreateLinkFromClipboard](#createlinkfromclipboard)  
  
- [CreateLinkFromData](#createlinkfromdata)  
  
- [CreateLinkFromFile](#createlinkfromfile)  
  
- [CreateNewItem](#createnewitem)  
  
- [CreateCloneFrom](#createclonefrom)  
  
##  <a name="convertto"></a>  COleClientItem::ConvertTo  
 Chame essa função de membro para converter o item para o tipo especificado pelo *clsidNew*.  
  
```  
virtual BOOL ConvertTo(REFCLSID clsidNew);
```  
  
### <a name="parameters"></a>Parâmetros  
 *clsidNew*  
 A ID de classe do tipo de destino.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Isso é chamado automaticamente pelo [COleConvertDialog](../../mfc/reference/coleconvertdialog-class.md). Não é necessário chamá-lo diretamente.  
  
##  <a name="copytoclipboard"></a>  COleClientItem::CopyToClipboard  
 Chame essa função para copiar o item OLE para a área de transferência.  
  
```  
void CopyToClipboard(BOOL bIncludeLink = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bIncludeLink*  
 TRUE se as informações de link devem ser copiadas para a área de transferência, permitindo que um item vinculado ser colado; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, chame essa função ao escrever manipuladores de mensagens para os comandos Recortar ou copiar no menu Editar. Você deve implementar a seleção de item em seu aplicativo de contêiner para implementar os comandos Recortar ou copiar.  
  
 Para obter mais informações, consulte [OleSetClipboard](/windows/desktop/api/ole2/nf-ole2-olesetclipboard) no SDK do Windows.  
  
##  <a name="createclonefrom"></a>  COleClientItem::CreateCloneFrom  
 Chame essa função para criar uma cópia do item OLE especificado.  
  
```  
BOOL CreateCloneFrom(const COleClientItem* pSrcItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pSrcItem*  
 Ponteiro para o item OLE a ser duplicado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A cópia é idêntica ao item de origem. Você pode usar essa função para dar suporte a operações de desfazer.  
  
##  <a name="createfromclipboard"></a>  COleClientItem::CreateFromClipboard  
 Chame essa função para criar um item inserido a partir do conteúdo da área de transferência.  
  
```  
BOOL CreateFromClipboard(
    OLERENDER render = OLERENDER_DRAW,  
    CLIPFORMAT cfFormat = 0,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Renderizar*  
 Sinalizador que especifica como o servidor processará o item OLE. Para os valores possíveis, consulte [OLERENDER](/windows/desktop/api/oleidl/ne-oleidl-tagolerender) no SDK do Windows.  
  
 *cfFormat*  
 Especifica o formato de dados de área de transferência a ser armazenado em cache ao criar o item OLE.  
  
 *lpFormatEtc*  
 Ponteiro para um [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura usada se *renderizar* é OLERENDER_FORMAT ou OLERENDER_DRAW. Forneça um valor para esse parâmetro somente se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo *cfFormat*. Se você omitir esse parâmetro, os valores padrão serão usados para os outros campos no `FORMATETC` estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você normalmente chama essa função do manipulador de mensagens para o comando Colar no menu Editar. (O comando Colar é habilitado pela estrutura se o [CanPaste](#canpaste) função membro retorna não zero.)  
  
 Para obter mais informações, consulte [OLERENDER](/windows/desktop/api/oleidl/ne-oleidl-tagolerender) e [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) no SDK do Windows.  
  
##  <a name="createfromdata"></a>  COleClientItem::CreateFromData  
 Chame essa função para criar um item inserido de um `COleDataObject` objeto.  
  
```  
BOOL CreateFromData(
    COleDataObject* pDataObject,  
    OLERENDER render = OLERENDER_DRAW,  
    CLIPFORMAT cfFormat = 0,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDataObject*  
 Ponteiro para o [COleDataObject](../../mfc/reference/coledataobject-class.md) objeto do qual o item OLE deve ser criado.  
  
 *Renderizar*  
 Sinalizador que especifica como o servidor processará o item OLE. Para os valores possíveis, consulte [OLERENDER](/windows/desktop/api/oleidl/ne-oleidl-tagolerender) no SDK do Windows.  
  
 *cfFormat*  
 Especifica o formato de dados de área de transferência a ser armazenado em cache ao criar o item OLE.  
  
 *lpFormatEtc*  
 Ponteiro para um [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura usada se *renderizar* é OLERENDER_FORMAT ou OLERENDER_DRAW. Forneça um valor para esse parâmetro somente se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo *cfFormat*. Se você omitir esse parâmetro, os valores padrão serão usados para os outros campos no `FORMATETC` estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Operações de transferência de dados, como Colar da área de transferência ou operações de arrastar e soltar, fornecem `COleDataObject` objetos que contém as informações oferecidas por um aplicativo de servidor. Ele geralmente é usado em sua substituição de [CView::OnDrop](../../mfc/reference/cview-class.md#ondrop).  
  
 Para obter mais informações, consulte [OleCreateFromData](/windows/desktop/api/ole2/nf-ole2-olecreatefromdata), [OLERENDER](/windows/desktop/api/oleidl/ne-oleidl-tagolerender), e [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) no SDK do Windows.  
  
##  <a name="createfromfile"></a>  COleClientItem::CreateFromFile  
 Chame essa função para criar um item OLE inserido de um arquivo.  
  
```  
BOOL CreateFromFile(
    LPCTSTR lpszFileName,  
    REFCLSID clsid = CLSID_NULL,  
    OLERENDER render = OLERENDER_DRAW,  
    CLIPFORMAT cfFormat = 0,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszFileName*  
 Ponteiro para o nome do arquivo do qual o item OLE é a ser criado.  
  
 *clsid*  
 Reservado para uso futuro.  
  
 *Renderizar*  
 Sinalizador que especifica como o servidor processará o item OLE. Para os valores possíveis, consulte [OLERENDER](/windows/desktop/api/oleidl/ne-oleidl-tagolerender) no SDK do Windows.  
  
 *cfFormat*  
 Especifica o formato de dados de área de transferência a ser armazenado em cache ao criar o item OLE.  
  
 *lpFormatEtc*  
 Ponteiro para um [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura usada se *renderizar* é OLERENDER_FORMAT ou OLERENDER_DRAW. Forneça um valor para esse parâmetro somente se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo *cfFormat*. Se você omitir esse parâmetro, os valores padrão serão usados para os outros campos no `FORMATETC` estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O framework chama essa função do [COleInsertDialog::CreateItem](../../mfc/reference/coleinsertdialog-class.md#createitem) se o usuário escolher Okey na caixa de diálogo Inserir objeto quando a criar de um botão de arquivo é selecionado.  
  
 Para obter mais informações, consulte [OleCreateFromFile](/windows/desktop/api/ole/nf-ole-olecreatefromfile), [OLERENDER](/windows/desktop/api/oleidl/ne-oleidl-tagolerender), e [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) no SDK do Windows.  
  
##  <a name="createlinkfromclipboard"></a>  COleClientItem::CreateLinkFromClipboard  
 Chame essa função para criar um item vinculado a partir do conteúdo da área de transferência.  
  
```  
BOOL CreateLinkFromClipboard(
    OLERENDER render = OLERENDER_DRAW,  
    CLIPFORMAT cfFormat = 0,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Renderizar*  
 Sinalizador que especifica como o servidor processará o item OLE. Para os valores possíveis, consulte [OLERENDER](/windows/desktop/api/oleidl/ne-oleidl-tagolerender) no SDK do Windows.  
  
 *cfFormat*  
 Especifica o formato de dados de área de transferência a ser armazenado em cache ao criar o item OLE.  
  
 *lpFormatEtc*  
 Ponteiro para um [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura usada se *renderizar* é OLERENDER_FORMAT ou OLERENDER_DRAW. Forneça um valor para esse parâmetro somente se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo *cfFormat*. Se você omitir esse parâmetro, os valores padrão serão usados para os outros campos no `FORMATETC` estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você normalmente chama essa função do manipulador de mensagens para o comando de Link de colar no menu Editar. (O comando Colar Link está habilitado na implementação padrão de [COleDocument](../../mfc/reference/coledocument-class.md) se a área de transferência contém um item OLE que pode ser vinculado a.)  
  
 Para obter mais informações, consulte [OLERENDER](/windows/desktop/api/oleidl/ne-oleidl-tagolerender) e [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) no SDK do Windows.  
  
##  <a name="createlinkfromdata"></a>  COleClientItem::CreateLinkFromData  
 Chame essa função para criar um item vinculado de um `COleDataObject` objeto.  
  
```  
BOOL CreateLinkFromData(
    COleDataObject* pDataObject,  
    OLERENDER render = OLERENDER_DRAW,  
    CLIPFORMAT cfFormat = 0,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDataObject*  
 Ponteiro para o [COleDataObject](../../mfc/reference/coledataobject-class.md) objeto do qual o item OLE deve ser criado.  
  
 *Renderizar*  
 Sinalizador que especifica como o servidor processará o item OLE. Para os valores possíveis, consulte [OLERENDER](/windows/desktop/api/oleidl/ne-oleidl-tagolerender) no SDK do Windows.  
  
 *cfFormat*  
 Especifica o formato de dados de área de transferência a ser armazenado em cache ao criar o item OLE.  
  
 *lpFormatEtc*  
 Ponteiro para um [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura usada se *renderizar* é OLERENDER_FORMAT ou OLERENDER_DRAW. Forneça um valor para esse parâmetro somente se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo *cfFormat*. Se você omitir esse parâmetro, os valores padrão serão usados para os outros campos no `FORMATETC` estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chamá-lo durante uma operação de soltar quando o usuário indicar que um link deve ser criado. Ele também pode ser usado para lidar com o comando Colar editar. Ele é chamado pela estrutura na `COleClientItem::CreateLinkFromClipboard` e, na [COlePasteSpecialDialog::CreateItem](../../mfc/reference/colepastespecialdialog-class.md#createitem) quando a opção de Link foi selecionada.  
  
 Para obter mais informações, consulte [OleCreateLinkFromData](/windows/desktop/api/ole2/nf-ole2-olecreatelinkfromdata), [OLERENDER](/windows/desktop/api/oleidl/ne-oleidl-tagolerender), e [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) no SDK do Windows.  
  
##  <a name="createlinkfromfile"></a>  COleClientItem::CreateLinkFromFile  
 Chame essa função para criar um item OLE vinculado de um arquivo.  
  
```  
BOOL CreateLinkFromFile(
    LPCTSTR lpszFileName,  
    OLERENDER render = OLERENDER_DRAW,  
    CLIPFORMAT cfFormat = 0,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszFileName*  
 Ponteiro para o nome do arquivo do qual o item OLE é a ser criado.  
  
 *Renderizar*  
 Sinalizador que especifica como o servidor processará o item OLE. Para os valores possíveis, consulte [OLERENDER](/windows/desktop/api/oleidl/ne-oleidl-tagolerender) no SDK do Windows.  
  
 *cfFormat*  
 Especifica o formato de dados de área de transferência a ser armazenado em cache ao criar o item OLE.  
  
 *lpFormatEtc*  
 Ponteiro para um [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura usada se *renderizar* é OLERENDER_FORMAT ou OLERENDER_DRAW. Forneça um valor para esse parâmetro somente se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo *cfFormat*. Se você omitir esse parâmetro, os valores padrão serão usados para os outros campos no `FORMATETC` estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O framework chama essa função se o usuário escolher Okey na caixa de diálogo Inserir objeto quando a criar de um botão de arquivo é selecionado e a caixa de seleção do Link está marcada. Ele é chamado de [COleInsertDialog::CreateItem](../../mfc/reference/coleinsertdialog-class.md#createitem).  
  
 Para obter mais informações, consulte [OleCreateLinkToFile](/windows/desktop/api/ole2/nf-ole2-olecreatelinktofile), [OLERENDER](/windows/desktop/api/oleidl/ne-oleidl-tagolerender), e [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) no SDK do Windows.  
  
##  <a name="createnewitem"></a>  COleClientItem::CreateNewItem  
 Chame essa função para criar um item inserido; Essa função inicia o aplicativo de servidor que permite ao usuário criar o item OLE.  
  
```  
BOOL CreateNewItem(
    REFCLSID clsid,  
    OLERENDER render = OLERENDER_DRAW,  
    CLIPFORMAT cfFormat = 0,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *clsid*  
 ID que identifica exclusivamente o tipo de item OLE para criar.  
  
 *Renderizar*  
 Sinalizador que especifica como o servidor processará o item OLE. Para os valores possíveis, consulte [OLERENDER](/windows/desktop/api/oleidl/ne-oleidl-tagolerender) no SDK do Windows.  
  
 *cfFormat*  
 Especifica o formato de dados de área de transferência a ser armazenado em cache ao criar o item OLE.  
  
 *lpFormatEtc*  
 Ponteiro para um [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura usada se *renderizar* é OLERENDER_FORMAT ou OLERENDER_DRAW. Forneça um valor para esse parâmetro somente se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo *cfFormat*. Se você omitir esse parâmetro, os valores padrão serão usados para os outros campos no `FORMATETC` estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O framework chama essa função se o usuário escolhe Okey na caixa de diálogo Inserir objeto quando o botão Criar novo é selecionado.  
  
 Para obter mais informações, consulte [OleCreate](/windows/desktop/api/ole/nf-ole-olecreate), [OLERENDER](/windows/desktop/api/oleidl/ne-oleidl-tagolerender), e [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) no SDK do Windows.  
  
##  <a name="createstaticfromclipboard"></a>  COleClientItem::CreateStaticFromClipboard  
 Chame essa função para criar um item estático usando o conteúdo da área de transferência.  
  
```  
BOOL CreateStaticFromClipboard(
    OLERENDER render = OLERENDER_DRAW,  
    CLIPFORMAT cfFormat = 0,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Renderizar*  
 Sinalizador que especifica como o servidor processará o item OLE. Para os valores possíveis, consulte [OLERENDER](/windows/desktop/api/oleidl/ne-oleidl-tagolerender) no SDK do Windows.  
  
 *cfFormat*  
 Especifica o formato de dados de área de transferência a ser armazenado em cache ao criar o item OLE.  
  
 *lpFormatEtc*  
 Ponteiro para um [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura usada se *renderizar* é OLERENDER_FORMAT ou OLERENDER_DRAW. Forneça um valor para esse parâmetro somente se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo *cfFormat*. Se você omitir esse parâmetro, os valores padrão serão usados para os outros campos no `FORMATETC` estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um item estático contém os dados da apresentação, mas não dados nativos; Consequentemente ele não pode ser editado. Normalmente você chama essa função se o [CreateFromClipboard](#createfromclipboard) falha da função de membro.  
  
 Para obter mais informações, consulte [OLERENDER](/windows/desktop/api/oleidl/ne-oleidl-tagolerender) e [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) no SDK do Windows.  
  
##  <a name="createstaticfromdata"></a>  COleClientItem::CreateStaticFromData  
 Chame essa função para criar um item estático de uma `COleDataObject` objeto.  
  
```  
BOOL CreateStaticFromData(
    COleDataObject* pDataObject,  
    OLERENDER render = OLERENDER_DRAW,  
    CLIPFORMAT cfFormat = 0,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDataObject*  
 Ponteiro para o [COleDataObject](../../mfc/reference/coledataobject-class.md) objeto do qual o item OLE deve ser criado.  
  
 *Renderizar*  
 Sinalizador que especifica como o servidor processará o item OLE. Para os valores possíveis, consulte [OLERENDER](/windows/desktop/api/oleidl/ne-oleidl-tagolerender) no SDK do Windows.  
  
 *cfFormat*  
 Especifica o formato de dados de área de transferência a ser armazenado em cache ao criar o item OLE.  
  
 *lpFormatEtc*  
 Ponteiro para um [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) estrutura usada se *renderizar* é OLERENDER_FORMAT ou OLERENDER_DRAW. Forneça um valor para esse parâmetro somente se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo *cfFormat*. Se você omitir esse parâmetro, os valores padrão serão usados para os outros campos no `FORMATETC` estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um item estático contém os dados da apresentação, mas não dados nativos; Consequentemente, ele não pode ser editado. Isso é essencialmente o mesmo que [CreateStaticFromClipboard](#createstaticfromclipboard) , exceto que um item estático pode ser criado de um arbitrário `COleDataObject`, não apenas da área de transferência.  
  
 Usado na [COlePasteSpecialDialog::CreateItem](../../mfc/reference/colepastespecialdialog-class.md#createitem) quando estático é selecionado.  
  
 Para obter mais informações, consulte [OleCreateStaticFromData](/windows/desktop/api/ole2/nf-ole2-olecreatestaticfromdata), [OLERENDER](/windows/desktop/api/oleidl/ne-oleidl-tagolerender), e [FORMATETC](/windows/desktop/api/objidl/ns-objidl-tagformatetc) no SDK do Windows.  
  
##  <a name="deactivate"></a>  COleClientItem::Deactivate  
 Chame essa função para desativar o item OLE e liberar os recursos associados.  
  
```  
void Deactivate();
```  
  
### <a name="remarks"></a>Comentários  
 Normalmente você desativa um item OLE da Active Directory no local quando o usuário clica com o mouse na área de cliente fora dos limites do item. Observe que desativar o item OLE descartará seu estado de desfazer, tornando Impossível chamar o [ReactivateAndUndo](#reactivateandundo) função de membro.  
  
 Se seu aplicativo dá suporte a desfazer, não chame `Deactivate`; em vez disso, chame [DeactivateUI](#deactivateui).  
  
 Para obter mais informações, consulte [IOleInPlaceObject::InPlaceDeactivate](/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-inplacedeactivate) no SDK do Windows.  
  
##  <a name="deactivateui"></a>  COleClientItem::DeactivateUI  
 Chame essa função quando o usuário desativa um item que foi ativado no local.  
  
```  
void DeactivateUI();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função restaura a interface do usuário do aplicativo de contêiner para seu estado original, ocultando qualquer menus e outros controles que foram criados para ativação no local.  
  
 Essa função não limpa as informações de estado de recuperação para o item. Que informações são mantidas para que [ReactivateAndUndo](#reactivateandundo) posteriormente pode ser usado para executar um comando de desfazer no aplicativo do servidor, no caso de comando de desfazer do contêiner é escolhido imediatamente após a desativação do item.  
  
 Para obter mais informações, consulte [IOleInPlaceObject::InPlaceDeactivate](/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-inplacedeactivate) no SDK do Windows.  
  
##  <a name="delete"></a>  COleClientItem::Delete  
 Chame essa função para excluir o item OLE do documento contêiner.  
  
```  
void Delete(BOOL bAutoDelete = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bAutoDelete*  
 Especifica se o item deve ser removido do documento.  
  
### <a name="remarks"></a>Comentários  
 Essa função chama o [versão](#release) a função de membro, que por sua vez, exclui o objeto de C++ para o item, removendo permanentemente o item OLE do documento. Se o item OLE é inserido, os dados nativos para o item são excluídos. Ele sempre fecha um servidor em execução; Portanto, se o item é abrir o link, essa função é fechada-lo.  
  
##  <a name="dodragdrop"></a>  COleClientItem::DoDragDrop  
 Chamar o `DoDragDrop` a função de membro para executar uma operação de arrastar e soltar.  
  
```  
DROPEFFECT DoDragDrop(
    LPCRECT lpItemRect,  
    CPoint ptOffset,  
    BOOL bIncludeLink = FALSE,  
    DWORD dwEffects = DROPEFFECT_COPY | DROPEFFECT_MOVE,  
    LPCRECT lpRectStartDrag = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpItemRect*  
 Retângulo do item na tela em coordenadas do cliente (pixels).  
  
 *ptOffset*  
 O deslocamento a partir *lpItemRect* em que a posição do mouse foi o momento da operação de arrastar.  
  
 *bIncludeLink*  
 Defina isso como TRUE se o link de dados devem ser copiados para a área de transferência. Defina-o como FALSE se o aplicativo de servidor não dá suporte a links.  
  
 *dwEffects*  
 Determina os efeitos que a origem do arrasto permitirá na operação de arrastar.  
  
 *lpRectStartDrag*  
 Ponteiro para o retângulo que define onde realmente inicia a operação de arrastar. Para obter mais informações, consulte a seção Comentários a seguir.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor DROPEFFECT. Se for DROPEFFECT_MOVE, os dados originais devem ser removidos.  
  
### <a name="remarks"></a>Comentários  
 A operação de arrastar e soltar não é iniciado imediatamente. Ele aguarda até que o cursor do mouse deixa o retângulo especificado por *lpRectStartDrag* ou até que um número especificado de milissegundos tiver passado. Se *lpRectStartDrag* for NULL, o tamanho do retângulo é um pixel.  
  
 O tempo de atraso é especificado por uma configuração de chave do registro. Você pode alterar o tempo de atraso, chamando [CWinApp::WriteProfileString](../../mfc/reference/cwinapp-class.md#writeprofilestring) ou [CWinApp::WriteProfileInt](../../mfc/reference/cwinapp-class.md#writeprofileint). Se você não especificar o tempo de atraso, é usado um valor padrão de 200 milissegundos. Tempo de atraso de arrastar é armazenado da seguinte maneira:  
  
-   Tempo de atraso de arrastar do Windows NT é armazenado no HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\NT\CurrentVersion\IniFileMapping\win.ini\Windows\DragDelay.  
  
-   Tempo de atraso de arrastar do Windows 3. x é armazenado no arquivo o WIN. Arquivo INI, sob a [seção Windows}.  
  
-   Tempo de atraso de arrastar do Windows 95/98 é armazenado em uma versão em cache do WIN. INI.  
  
 Para obter mais informações sobre como arrastar informações de atraso são armazenadas no registro ou o. O arquivo INI, consulte [WriteProfileString](/windows/desktop/api/winbase/nf-winbase-writeprofilestringa) no SDK do Windows.  
  
##  <a name="doverb"></a>  COleClientItem::DoVerb  
 Chamar `DoVerb` para executar o verbo especificado.  
  
```  
virtual BOOL DoVerb(
    LONG nVerb,  
    CView* pView,
    LPMSG lpMsg = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nVerb*  
 Especifica o verbo a ser executado. Ele pode incluir um dos seguintes:  
  
|Valor|Significado|Símbolo|  
|-----------|-------------|------------|  
|- 0|Verbo primário|OLEIVERB_PRIMARY|  
|- 1|Verbo secundário|(Nenhum)|  
|- 1|Item de exibição para edição|OLEIVERB_SHOW|  
|- 2|Editar item na janela separada|OLEIVERB_OPEN|  
|- 3|Ocultar o item|OLEIVERB_HIDE|  
  
 O valor de-1 normalmente é um alias para outro verbo. Se não há suporte para a edição aberto, -2 tem o mesmo efeito que -1. Para obter valores adicionais, consulte [IOleObject:: DoVerb](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb) no SDK do Windows.  
  
 *pView*  
 Ponteiro para a janela de exibição; Isso é usado pelo servidor de ativação no local. Esse parâmetro deve ser NULL se o aplicativo de contêiner não permitir a ativação in-loco.  
  
 *lpMsg*  
 Ponteiro para a mensagem que causou o item a ser ativado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o verbo foi executado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função chama o [ativar](#activate) função de membro para executar o verbo. Ele também captura exceções e exibe uma caixa de mensagem para o usuário se um for gerado.  
  
 Se o verbo primário é editar e zero for especificada na *nVerb* parâmetro, o aplicativo de servidor é iniciado para permitir que o item OLE a ser editado. Se o aplicativo de contêiner dá suporte à ativação in-loco, a edição pode ser feita em vigor. Se o contêiner não dá suporte a ativação no local (ou se o verbo Open for especificado), o servidor é iniciado em uma janela separada e edição pode ser feita lá. Normalmente, quando o usuário do aplicativo recipiente clica duas vezes no item OLE, o valor para o verbo primário na *nVerb* parâmetro determina qual ação o usuário pode executar. No entanto, se o servidor oferecer suporte a apenas uma ação, ele usa essa ação, não importa qual valor é especificado na *nVerb* parâmetro.  
  
##  <a name="draw"></a>  COleClientItem::Draw  
 Chame essa função para desenhar o item OLE no retângulo delimitador especificado usando o contexto de dispositivo especificado.  
  
```  
BOOL Draw(
    CDC* pDC,  
    LPCRECT lpBounds,  
    DVASPECT nDrawAspect = (DVASPECT)-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDC*  
 Ponteiro para um [CDC](../../mfc/reference/cdc-class.md) objeto usado para desenhar o item OLE.  
  
 *lpBounds*  
 Ponteiro para um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou `RECT` estrutura que define o retângulo delimitador no qual desenhar o item OLE (em unidades lógicas determinadas pelo contexto de dispositivo).  
  
 *nDrawAspect*  
 Especifica o aspecto da OLE do item, ou seja, como deve ser exibida. Se *nDrawAspect* é -1, o último aspecto definido por meio [SetDrawAspect](#setdrawaspect) é usado. Para obter mais informações sobre os valores possíveis para esse sinalizador, consulte [SetDrawAspect](#setdrawaspect).  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A função pode usar a representação de metarquivo do item OLE criado pelo [OnDraw](../../mfc/reference/coleserveritem-class.md#ondraw) função de membro de `COleServerItem`.  
  
 Normalmente você usa `Draw` para a exibição de tela, transmitindo o contexto de dispositivo de tela como *pDC*. Nesse caso, você precisa especificar somente os primeiros dois parâmetros.  
  
 O *lpBounds* parâmetro identifica o retângulo no contexto de dispositivo de destino (relativo ao seu modo de mapeamento atual). O processamento pode envolver a dimensionar a imagem e pode ser usado por aplicativos de contêiner para impor uma exibição que pode ser dimensionado entre a exibição que aparece e a imagem impressa final.  
  
 Para obter mais informações, consulte [IViewObject::Draw](/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw) no SDK do Windows.  
  
##  <a name="getactiveview"></a>  COleClientItem::GetActiveView  
 Retorna o modo no qual o item é ativado no local.  
  
```  
CView* GetActiveView() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o modo de exibição; Caso contrário, nulo se o item não está ativado no local.  
  
##  <a name="getcachedextent"></a>  COleClientItem::GetCachedExtent  
 Chame essa função para recuperar o tamanho do item OLE.  
  
```  
BOOL GetCachedExtent(
    LPSIZE lpSize,  
    DVASPECT nDrawAspect = (DVASPECT)-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpSize*  
 Ponteiro para um `SIZE` estrutura ou um [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto que receberá as informações de tamanho.  
  
 *nDrawAspect*  
 Especifica o aspecto do item OLE cujos limites devem ser recuperadas. Para os valores possíveis, consulte [SetDrawAspect](#setdrawaspect).  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; 0 se o item OLE estiver em branco.  
  
### <a name="remarks"></a>Comentários  
 Essa função fornece as mesmas informações que [GetExtent](#getextent). No entanto, você pode chamar `GetCachedExtent` para obter informações de extensão durante o processamento de outros manipuladores OLE, como [OnChange](#onchange). As dimensões são em unidades MM_HIMETRIC.  
  
 Isso é possível porque `GetCachedExtent` usa o [IViewObject2](/windows/desktop/api/oleidl/nn-oleidl-iviewobject2) interface em vez de usar os [IOleObject](/windows/desktop/api/oleidl/nn-oleidl-ioleobject) a interface para obter a extensão deste item. O `IViewObject2` objeto COM armazena em cache as informações de extensão usadas na chamada anterior a [IViewObject::Draw](/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw).  
  
 Para obter mais informações, consulte [IViewObject2::GetExtent](/windows/desktop/api/oleidl/nf-oleidl-iviewobject2-getextent) no SDK do Windows.  
  
##  <a name="getclassid"></a>  COleClientItem::GetClassID  
 Retorna a ID de classe do item na memória apontada por *pClassID*.  
  
```  
void GetClassID(CLSID* pClassID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pClassID*  
 Ponteiro para um identificador de tipo [CLSID](/windows/desktop/com/clsid-key-hklm) para recuperar a ID de classe. Para obter informações sobre o CLSID, consulte o SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 A ID de classe é um número de 128 bits que identifica exclusivamente o aplicativo que edita o item.  
  
 Para obter mais informações, consulte [IPersist::GetClassID](/windows/desktop/api/objidl/nf-objidl-ipersist-getclassid) no SDK do Windows.  
  
##  <a name="getclipboarddata"></a>  COleClientItem::GetClipboardData  
 Chame essa função para obter um `COleDataSource` objeto que contém todos os dados devem ser colocados na área de transferência por uma chamada para o [CopyToClipboard](#copytoclipboard) função de membro.  
  
```  
void GetClipboardData(
    COleDataSource* pDataSource,  
    BOOL bIncludeLink = FALSE,  
    LPPOINT lpOffset = NULL,  
    LPSIZE lpSize = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDataSource*  
 Ponteiro para um [COleDataSource](../../mfc/reference/coledatasource-class.md) objeto que receberá os dados contidos no item OLE.  
  
 *bIncludeLink*  
 TRUE se o link de dados devem ser incluídos; Caso contrário, FALSE.  
  
 *lpOffset*  
 O deslocamento do cursor do mouse em relação à origem do objeto em pixels.  
  
 *lpSize*  
 O tamanho do objeto em pixels.  
  
### <a name="remarks"></a>Comentários  
 `GetClipboardData` é chamado como a implementação padrão de [OnGetClipboardData](#ongetclipboarddata). Substituir `OnGetClipboardData` somente se você desejar oferecer a formatos de dados, além daqueles oferecidos pelo `CopyToClipboard`. Coloque esses formatos na `COleDataSource` objeto antes ou depois de chamar `CopyToClipboard`e, em seguida, passe o `COleDataSource` do objeto para o [COleDataSource::SetClipboard](../../mfc/reference/coledatasource-class.md#setclipboard) função. Por exemplo, se você quiser que a posição do item OLE no documento de contêiner para acompanhá-lo na área de transferência, você seria definir seu próprio formato para passá-las e colocá-lo a `COleDataSource` antes de chamar `CopyToClipboard`.  
  
##  <a name="getdocument"></a>  COleClientItem::GetDocument  
 Chame essa função para obter um ponteiro para o documento que contém o item OLE.  
  
```  
COleDocument* GetDocument() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o documento que contém o item OLE. NULL se o item não é parte de um documento.  
  
### <a name="remarks"></a>Comentários  
 Esse ponteiro permite o acesso para o `COleDocument` objeto passado como um argumento para o `COleClientItem` construtor.  
  
##  <a name="getdrawaspect"></a>  COleClientItem::GetDrawAspect  
 Chamar o `GetDrawAspect` a função de membro para determinar o atual "aspecto" ou o modo de exibição do item.  
  
```  
DVASPECT GetDrawAspect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de enumeração DVASPECT, cujos valores são listados na referência para [SetDrawAspect](#setdrawaspect).  
  
### <a name="remarks"></a>Comentários  
 O aspecto Especifica como o item a ser renderizado.  
  
##  <a name="getextent"></a>  COleClientItem::GetExtent  
 Chame essa função para recuperar o tamanho do item OLE.  
  
```  
BOOL GetExtent(
    LPSIZE lpSize,  
    DVASPECT nDrawAspect = (DVASPECT)- 1);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpSize*  
 Ponteiro para um `SIZE` estrutura ou um `CSize` objeto que receberá as informações de tamanho.  
  
 *nDrawAspect*  
 Especifica o aspecto do item OLE cujos limites devem ser recuperadas. Para os valores possíveis, consulte [SetDrawAspect](#setdrawaspect).  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; 0 se o item OLE estiver em branco.  
  
### <a name="remarks"></a>Comentários  
 Se o aplicativo de servidor foi escrito usando a biblioteca Microsoft Foundation Class, essa função faz com que o [OnGetExtent](../../mfc/reference/coleserveritem-class.md#ongetextent) função de membro de correspondente `COleServerItem` objeto a ser chamado. Observe que o tamanho recuperado pode ser diferente do tamanho definido pela última vez [SetExtent](#setextent) função de membro; o tamanho especificado pelo `SetExtent` é tratado como uma sugestão. As dimensões são em unidades MM_HIMETRIC.  
  
> [!NOTE]
>  Não chame `GetExtent` durante o processamento de um manipulador de OLE, como [OnChange](#onchange). Chame [GetCachedExtent](#getcachedextent) em vez disso.  
  
 Para obter mais informações, consulte [IOleObject::GetExtent](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getextent) no SDK do Windows.  
  
##  <a name="geticonfromregistry"></a>  COleClientItem::GetIconFromRegistry  
 Chame essa função de membro para recuperar um identificador para um recurso de ícone associado ao servidor de um CLSID particular.  
  
```  
HICON GetIconFromRegistry() const;  
  
static HICON GetIconFromRegistry(CLSID& clsid);
```  
  
### <a name="parameters"></a>Parâmetros  
 *clsid*  
 Uma referência ao CLSID para o servidor associado ao ícone.  
  
### <a name="return-value"></a>Valor de retorno  
 Válido a alça para o recurso de ícone, ou nulo se o ícone do servidor ou um ícone padrão, não pode ser encontrado.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro não iniciar o servidor ou obter um ícone dinamicamente, mesmo se o servidor já está em execução. Em vez disso, essa função membro abre a imagem do executável do servidor e recupera o ícone estático associado ao servidor como ele foi registrado.  
  
##  <a name="geticonicmetafile"></a>  COleClientItem::GetIconicMetafile  
 Recupera o metarquivo usado para desenhar o ícone do item.  
  
```  
HGLOBAL GetIconicMetafile();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o metarquivo se bem-sucedido; Caso contrário, nulo.  
  
### <a name="remarks"></a>Comentários  
 Se não houver nenhum ícone atual, um ícone padrão será retornado. Isso é chamado automaticamente pelas caixas de diálogo do MFC/OLE e normalmente não é chamado diretamente.  
  
 Essa função também chama [SetIconicMetafile](#seticonicmetafile) para armazenar em cache o metarquivo para uso posterior.  
  
##  <a name="getinplacewindow"></a>  COleClientItem::GetInPlaceWindow  
 Chamar o `GetInPlaceWindow` a função de membro para obter um ponteiro para a janela na qual o item foi aberto para edição no local.  
  
```  
CWnd* GetInPlaceWindow();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a janela de edição do item no local; NULL se o item não estiver ativo ou se seu servidor não está disponível.  
  
### <a name="remarks"></a>Comentários  
 Essa função deve ser chamada apenas para itens que estão ativos no local.  
  
##  <a name="getitemstate"></a>  COleClientItem::GetItemState  
 Chame essa função para obter o estado atual do item OLE.  
  
```  
UINT GetItemState() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `COleClientItem::ItemState` enumerados valor, que pode ser uma das seguintes opções: `emptyState`, `loadedState`, `openState`, `activeState`, `activeUIState`. Para obter informações sobre esses estados, consulte o artigo [contêineres: Estados de Item do cliente](../../mfc/containers-client-item-states.md).  
  
### <a name="remarks"></a>Comentários  
 Para ser notificado quando o estado do item OLE é alterado, use o [OnChange](#onchange) função de membro.  
  
 Para obter mais informações, consulte o artigo [contêineres: Estados de Item do cliente](../../mfc/containers-client-item-states.md).  
  
##  <a name="getlaststatus"></a>  COleClientItem::GetLastStatus  
 Retorna o código de status da última operação OLE.  
  
```  
SCODE GetLastStatus() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor SCODE.  
  
### <a name="remarks"></a>Comentários  
 Para funções de membro que retornam um valor BOOLIANO FALSE ou outro membro funções que retornam NULL, `GetLastStatus` retorna informações de falha mais detalhadas. Lembre-se de que a maioria das funções de membro OLE lançar exceções para erros mais graves. As informações específicas sobre a interpretação do SCODE dependem da chamada OLE subjacente que um valor SCODE retornado pela última vez.  
  
 Para obter mais informações sobre SCODE, consulte [estrutura de códigos de erro COM](/windows/desktop/com/structure-of-com-error-codes) na documentação do SDK do Windows.  
  
##  <a name="getlinkupdateoptions"></a>  COleClientItem::GetLinkUpdateOptions  
 Chame essa função para obter o valor atual da opção de atualização de link para o item OLE.  
  
```  
OLEUPDATE GetLinkUpdateOptions();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos seguintes valores:  
  
- OLEUPDATE_ALWAYS atualizar o item vinculado sempre que possível. Essa opção dá suporte a no botão de opção de atualização automática de link na caixa de diálogo de Links.  
  
- OLEUPDATE_ONCALL atualizar o item vinculado somente na solicitação do aplicativo de contêiner (quando o [UpdateLink](#updatelink) é chamada de função de membro). Essa opção dá suporte a no botão de opção de atualização Manual de link na caixa de diálogo de Links.  
  
### <a name="remarks"></a>Comentários  
 Isso é uma operação avançada.  
  
 Essa função é chamada automaticamente pelo [COleLinksDialog](../../mfc/reference/colelinksdialog-class.md) classe.  
  
 Para obter mais informações, consulte [IOleLink::GetUpdateOptions](/windows/desktop/api/oleidl/nf-oleidl-iolelink-getupdateoptions) no SDK do Windows.  
  
##  <a name="gettype"></a>  COleClientItem::GetType  
 Chame essa função para determinar se o item OLE é incorporado ou vinculado ou static.  
  
```  
OLE_OBJTYPE GetType() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um inteiro sem sinal com um dos seguintes valores:  
  
- Item OT_LINK a OLE é um link.  
  
- OT_EMBEDDED a OLE item é inserido.  
  
- Item OT_STATIC a OLE é estático, ou seja, ele contém dados de apresentação apenas, dados não nativos e, portanto, não pode ser editado.  
  
##  <a name="getusertype"></a>  COleClientItem::GetUserType  
 Chame essa função para obter a cadeia de caracteres visíveis ao usuário que descreve o tipo do item OLE, como "Documento do Word".  
  
```  
void GetUserType(
    USERCLASSTYPE nUserClassType,  
    CString& rString);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nUserClassType*  
 Um valor que indica a variante desejada da cadeia de caracteres que descreve o tipo do item OLE. Isso pode ter um dos seguintes valores:  
  
- USERCLASSTYPE_FULL completo digite o nome exibido para o usuário.  
  
- USERCLASSTYPE_SHORT um nome curto (no máximo 15 caracteres) para uso em menus pop-up e a caixa de diálogo Editar Links.  
  
- USERCLASSTYPE_APPNAME o nome do aplicativo a classe de serviço.  
  
 *rString*  
 Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto ao qual a cadeia de caracteres que descreve o tipo do item OLE a ser retornado.  
  
### <a name="remarks"></a>Comentários  
 Isso geralmente é a entrada no banco de dados de registro do sistema.  
  
 Se o nome de tipo completo for solicitada, mas não está disponível, o nome curto é usado em vez disso. Se nenhuma entrada para o tipo do item OLE é encontrada no banco de dados de registro, ou se não houver nenhum tipo de usuário registrado para o tipo de item OLE, em seguida, o tipo de usuário atualmente armazenados no item OLE é usado. Se esse nome de tipo de usuário é uma cadeia de caracteres vazia, "Objeto desconhecido" será usado.  
  
 Para obter mais informações, consulte [IOleObject::GetUserType](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getusertype) no SDK do Windows.  
  
##  <a name="isinplaceactive"></a>  COleClientItem::IsInPlaceActive  
 Chame essa função para ver se o item OLE é ativado.  
  
```  
BOOL IsInPlaceActive() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item OLE é ativado; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 É comum para executar uma lógica diferente, dependendo se o item está sendo editado no local. A função verifica se o estado do item atual é igual a qualquer um de `activeState` ou o `activeUIState`.  
  
##  <a name="islinkuptodate"></a>  COleClientItem::IsLinkUpToDate  
 Chame essa função para ver se o item OLE é atualizado.  
  
```  
BOOL IsLinkUpToDate() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item OLE é atualizado; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um item vinculado pode ser desatualizado se seu documento de origem tiver sido atualizado. Da mesma forma, um item inserido que contém os links dentro dele pode ficar desatualizado. A função faz uma verificação recursiva do item OLE. Observe que a determinar se um item OLE é desatualizado pode ser mais caro que realmente executar uma atualização.  
  
 Isso é chamado automaticamente pelo [COleLinksDialog](../../mfc/reference/colelinksdialog-class.md) implementação.  
  
 Para obter mais informações, consulte [IOleObject::IsUpToDate](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-isuptodate) no SDK do Windows.  
  
##  <a name="ismodified"></a>  COleClientItem::IsModified  
 Chame essa função para ver se o item OLE é sujo (modificada desde que foi salvo pela última vez).  
  
```  
BOOL IsModified() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item OLE estiver sujo; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [IPersistStorage::IsDirty](/windows/desktop/api/objidl/nf-objidl-ipersiststorage-isdirty) no SDK do Windows.  
  
##  <a name="isopen"></a>  COleClientItem::IsOpen  
 Chame essa função para ver se o item OLE é aberto. ou seja, abertos em uma instância do aplicativo para servidores em execução em uma janela separada.  
  
```  
BOOL IsOpen() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item OLE está aberto. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Ele é usado para determinar quando desenhar o objeto com um padrão de hachura. Um objeto aberto deve ter um padrão de hachura desenhado na parte superior do objeto. Você pode usar um [CRectTracker](../../mfc/reference/crecttracker-class.md) objeto para fazer isso.  
  
##  <a name="isrunning"></a>  COleClientItem::IsRunning  
 Chame essa função para ver se o item OLE está em execução; ou seja, se o item é carregado e executado no aplicativo do servidor.  
  
```  
BOOL IsRunning() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item OLE estiver em execução; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [OleIsRunning](/windows/desktop/api/ole2/nf-ole2-oleisrunning) no SDK do Windows.  
  
##  <a name="onactivate"></a>  COleClientItem::OnActivate  
 Chamado pelo framework para notificar o item que apenas foi ativado no local.  
  
```  
virtual void OnActivate();
```  
  
### <a name="remarks"></a>Comentários  
 Observe que essa função é chamada para indicar que o servidor está sendo executado, não para indicar que sua interface do usuário foi instalada no aplicativo de contêiner. Neste ponto, o objeto não tem uma interface do usuário do Active Directory (não é `activeUIState`). Ele não tiver instalado seus menus ou a barra de ferramentas. O [OnActivateUI](#onactivateui) função membro é chamada quando isso acontece.  
  
 A implementação padrão chama o [OnChange](#onchange) função membro com OLE_CHANGEDSTATE como um parâmetro. Substitua essa função para executar o processamento personalizado quando um item se torna ativo no local.  
  
##  <a name="onactivateui"></a>  COleClientItem::OnActivateUI  
 A estrutura chama `OnActivateUI` quando o objeto entrou no estado ativo da interface do usuário.  
  
```  
virtual void OnActivateUI();
```  
  
### <a name="remarks"></a>Comentários  
 O objeto agora instalado sua barra de ferramentas e menus.  
  
 A implementação padrão lembra o HWND do servidor para uso posterior `GetServerWindow` chamadas.  
  
##  <a name="onchange"></a>  COleClientItem::OnChange  
 Chamado pelo framework quando o usuário modifica, salva ou fecha o item OLE.  
  
```  
virtual void OnChange(
    OLE_NOTIFICATION nCode,  
    DWORD dwParam);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nCode*  
 O motivo pelo qual o servidor alterou esse item. Ele pode ter um dos seguintes valores:  
  
- OLE_CHANGED a OLE aparência do item foi alterado.  
  
- Item OLE_SAVED a OLE foi salvo.  
  
- Item OLE_CLOSED a OLE foi fechado.  
  
- Item OLE_CHANGED_STATE a OLE foi alterado de um estado para outro.  
  
 *dwParam*  
 Se *nCode* é OLE_SAVED ou OLE_CLOSED, esse parâmetro não é usado. Se *nCode* é OLE_CHANGED, esse parâmetro especifica o aspecto do item OLE que foi alterado. Para os valores possíveis, consulte o *dwParam* parâmetro do [COleClientItem::Draw](#draw). Se *nCode* é OLE_CHANGED_STATE, esse parâmetro é um `COleClientItem::ItemState` valor enumerado e descreve o estado que está sendo inserido. Ele pode ter um dos seguintes valores: `emptyState`, `loadedState`, `openState`, `activeState`, ou `activeUIState`.  
  
### <a name="remarks"></a>Comentários  
 (Se o aplicativo de servidor é escrito usando a biblioteca Microsoft Foundation Class, essa função é chamada em resposta à `Notify` funções de membro `COleServerDoc` ou `COleServerItem`.) A implementação padrão marca o documento de contêiner como modificado se *nCode* é OLE_CHANGED ou OLE_SAVED.  
  
 Para OLE_CHANGED_STATE, o estado atual retornado de [GetItemState](#getitemstate) ainda será o estado antigo, o que significa que o estado que foi atual antes dessa mudança de estado.  
  
 Substitua essa função para responder a alterações no estado do item OLE. Normalmente você atualizar a aparência do item ao invalidar a área na qual o item é exibido. Chame a implementação de classe base no início de sua substituição.  
  
##  <a name="onchangeitemposition"></a>  COleClientItem::OnChangeItemPosition  
 Chamado pelo framework para notificar o contêiner que a extensão do item OLE foi alterado durante a ativação in-loco.  
  
```  
virtual BOOL OnChangeItemPosition(const CRect& rectPos);
```  
  
### <a name="parameters"></a>Parâmetros  
 *rectPos*  
 Indica a posição do item em relação à área de cliente do aplicativo de contêiner.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a posição do item é alterada com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão determina o novo retângulo visível do item OLE e chamadas [SetItemRects](#setitemrects) com os novos valores. A implementação padrão calcula o retângulo visível para o item e transmite essas informações para o servidor.  
  
 Substitua essa função para aplicar regras especiais para a operação de redimensionamento/movimentação. Se o aplicativo é escrito no MFC, essa chamada resulta porque o servidor chamado [COleServerDoc::RequestPositionChange](../../mfc/reference/coleserverdoc-class.md#requestpositionchange).  
  
##  <a name="ondeactivate"></a>  COleClientItem::OnDeactivate  
 Chamado pelo framework quando o item OLE faz a transição de estado ativo no local ( `activeState`) para o estado carregado, o que significa que ele está desativado após uma ativação in-loco.  
  
```  
virtual void OnDeactivate();
```  
  
### <a name="remarks"></a>Comentários  
 Observe que essa função é chamada para indicar que o item OLE é fechado, não que sua interface do usuário foi removida do aplicativo de contêiner. Quando isso acontece, o [OnDeactivateUI](#ondeactivateui) função membro é chamada.  
  
 A implementação padrão chama o [OnChange](#onchange) função membro com OLE_CHANGEDSTATE como um parâmetro. Substitua essa função para realizar o processamento personalizado quando um item de Active Directory no local é desativado. Por exemplo, se você der suporte o comando Desfazer em seu aplicativo de contêiner, você pode substituir essa função para descartar o estado de desfazer, que indica que a última operação executada em um item OLE não pode ser desfeita depois que o item está desativado.  
  
##  <a name="ondeactivateandundo"></a>  COleClientItem::OnDeactivateAndUndo  
 Chamado pelo framework quando o usuário invoca o comando Desfazer após ativar o item OLE em vigor.  
  
```  
virtual void OnDeactivateAndUndo();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão chama [DeactivateUI](#deactivateui) para desativar a interface do usuário do servidor. Substitua essa função se você estiver implementando o comando Desfazer em seu aplicativo de contêiner. Em sua substituição, chame a versão da classe base da função e, em seguida, desfazer o último comando executado em seu aplicativo.  
  
 Para obter mais informações, consulte [IOleInPlaceSite::DeactivateAndUndo](/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-deactivateandundo) no SDK do Windows.  
  
##  <a name="ondeactivateui"></a>  COleClientItem::OnDeactivateUI  
 Chamado quando o usuário desativa um item que foi ativado no local.  
  
```  
virtual void OnDeactivateUI(BOOL bUndoable);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bUndoable*  
 Especifica se as alterações de edição que podem ser desfeitas.  
  
### <a name="remarks"></a>Comentários  
 Essa função restaura a interface do usuário do aplicativo de contêiner para seu estado original, ocultando qualquer menus e outros controles que foram criados para ativação no local.  
  
 Se *bUndoable* é FALSE, o contêiner deve desabilitar o comando de desfazer descartando em vigor o estado de desfazer do contêiner, pois indica que não é possível refazer a última operação executada pelo servidor.  
  
##  <a name="ondiscardundostate"></a>  COleClientItem::OnDiscardUndoState  
 Chamado pelo framework quando o usuário executa uma ação que descarta o estado de desfazer ao editar o item OLE.  
  
```  
virtual void OnDiscardUndoState();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não faz nada. Substitua essa função se você estiver implementando o comando Desfazer em seu aplicativo de contêiner. Em sua substituição, descarte o estado de desfazer do aplicativo de contêiner.  
  
 Se o servidor tenha sido escrito com a biblioteca Microsoft Foundation Class, o servidor pode fazer com que essa função a ser chamada por meio da chamada [COleServerDoc::DiscardUndoState](../../mfc/reference/coleserverdoc-class.md#discardundostate).  
  
 Para obter mais informações, consulte [IOleInPlaceSite::DiscardUndoState](/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-discardundostate) no SDK do Windows.  
  
##  <a name="ongetclipboarddata"></a>  COleClientItem::OnGetClipboardData  
 Chamado pelo framework para obter um `COleDataSource` objeto que contém todos os dados são colocados na área de transferência por uma chamada para ao [CopyToClipboard](#copytoclipboard) ou o [DoDragDrop](#dodragdrop) função de membro.  
  
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
 Ponteiro para o deslocamento do cursor do mouse em relação à origem do objeto em pixels.  
  
 *lpSize*  
 Ponteiro para o tamanho do objeto em pixels.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [COleDataSource](../../mfc/reference/coledatasource-class.md) objeto que contém os dados da área de transferência.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função chama [GetClipboardData](#getclipboarddata).  
  
##  <a name="ongetcliprect"></a>  COleClientItem::OnGetClipRect  
 A estrutura chama o `OnGetClipRect` a função de membro para obter as coordenadas do retângulo de recorte do item que está sendo editado in-loco.  
  
```  
virtual void OnGetClipRect(CRect& rClipRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 *rClipRect*  
 Ponteiro para um objeto da classe [CRect](../../atl-mfc-shared/reference/crect-class.md) que conterá as coordenadas do retângulo de recorte do item.  
  
### <a name="remarks"></a>Comentários  
 As coordenadas são em pixels, relativas à área de cliente da janela do aplicativo recipiente.  
  
 A implementação padrão simplesmente retorna o retângulo do cliente do modo de exibição na qual o item está ativo no local.  
  
##  <a name="ongetitemposition"></a>  COleClientItem::OnGetItemPosition  
 A estrutura chama o `OnGetItemPosition` a função de membro para obter as coordenadas do item que está sendo editado in-loco.  
  
```  
virtual void OnGetItemPosition(CRect& rPosition);
```  
  
### <a name="parameters"></a>Parâmetros  
 *rPosition*  
 Referência para o [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que contém coordenadas de posição do item.  
  
### <a name="remarks"></a>Comentários  
 As coordenadas são em pixels, relativas à área de cliente da janela do aplicativo recipiente.  
  
 A implementação padrão dessa função não faz nada. Aplicativos que dão suporte à edição in-loco exigem sua implementação.  
  
##  <a name="ongetwindowcontext"></a>  COleClientItem::OnGetWindowContext  
 Chamado pelo framework quando um item é ativado em vigor.  
  
```  
virtual BOOL OnGetWindowContext(
    CFrameWnd** ppMainFrame,  
    CFrameWnd** ppDocFrame,  
    LPOLEINPLACEFRAMEINFO lpFrameInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 *ppMainFrame*  
 Ponteiro para um ponteiro para a janela do quadro principal.  
  
 *ppDocFrame*  
 Ponteiro para um ponteiro para a janela de quadro do documento.  
  
 *lpFrameInfo*  
 Ponteiro para um [OLEINPLACEFRAMEINFO](/windows/desktop/api/oleidl/ns-oleidl-tagoifi) estrutura que receberá informações de janela do quadro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função é usada para recuperar informações sobre a janela do pai do item OLE.  
  
 Se o contêiner for um aplicativo MDI, a implementação padrão retorna um ponteiro para o [CMDIFrameWnd](../../mfc/reference/cmdiframewnd-class.md) do objeto na *ppMainFrame* e um ponteiro para o Active Directory [CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md)do objeto no *ppDocFrame*. Se o contêiner for um aplicativo SDI, a implementação padrão retorna um ponteiro para o [CFrameWnd](../../mfc/reference/cframewnd-class.md) do objeto na *ppMainFrame* e retorna NULL no *ppDocFrame*. A implementação padrão também preenche os membros da *lpFrameInfo*.  
  
 Substituir essa função somente se a implementação padrão não atenderem às seu aplicativo. Por exemplo, se seu aplicativo tiver um paradigma de interface do usuário que é diferente de SDI ou MDI. Isso é um avançado substituível.  
  
 Para obter mais informações, consulte [IOleInPlaceSite::GetWindowContext](/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-getwindowcontext) e o [OLEINPLACEFRAMEINFO](/windows/desktop/api/oleidl/ns-oleidl-tagoifi) estrutura no SDK do Windows.  
  
##  <a name="oninsertmenus"></a>  COleClientItem::OnInsertMenus  
 Chamado pelo framework durante a ativação no local para inserir os menus do aplicativo de contêiner em um menu vazio.  
  
```  
virtual void OnInsertMenus(
    CMenu* pMenuShared,  
    LPOLEMENUGROUPWIDTHS lpMenuWidths);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pMenuShared*  
 Aponta para um menu vazio.  
  
 *lpMenuWidths*  
 Aponta para uma matriz de seis valores longos indicando quantos menus estão em cada um dos seguintes grupos de menu: arquivo, editar, contêiner, objeto, a janela Ajuda. O aplicativo de contêiner é responsável por grupos de menu Arquivo, o contêiner e a janela, correspondentes aos elementos, 0, 2 e 4 dessa matriz.  
  
### <a name="remarks"></a>Comentários  
 Esse menu é então passado para o servidor, que insere seus próprios menus, criando um menu composto. Essa função pode ser chamada repetidamente para criar vários menus de composição.  
  
 A implementação padrão insere *pMenuShared* os menus de contêiner no local, ou seja, os grupos de menu Arquivo, o contêiner e a janela. [CDocTemplate::SetContainerInfo](../../mfc/reference/cdoctemplate-class.md#setcontainerinfo) é usado para definir esse recurso de menu. A implementação padrão também atribui os valores apropriados aos elementos, 0, 2 e 4 na *lpMenuWidths*, dependendo do recurso de menu. Substituir essa função se a implementação padrão não é apropriada para seu aplicativo. Por exemplo, se seu aplicativo não usa modelos de documento para associar os recursos de tipos de documento. Se você substituir essa função, você também deve substituir [OnSetMenu](#onsetmenu) e [OnRemoveMenus](#onremovemenus). Isso é um avançado substituível.  
  
 Para obter mais informações, consulte [IOleInPlaceFrame::InsertMenus](/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-insertmenus) no SDK do Windows.  
  
##  <a name="onremovemenus"></a>  COleClientItem::OnRemoveMenus  
 Chamado pelo framework para remover os menus do contêiner do menu de composição especificado quando termina de ativação no local.  
  
```  
virtual void OnRemoveMenus(CMenu* pMenuShared);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pMenuShared*  
 Aponta para o menu composto construído por chamadas para o [OnInsertMenus](#oninsertmenus) função de membro.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão remove *pMenuShared* os menus de contêiner no local, que é, os grupos de menu Arquivo, o contêiner e a janela. Substituir essa função se a implementação padrão não é apropriada para seu aplicativo. Por exemplo, se seu aplicativo não usa modelos de documento para associar os recursos de tipos de documento. Se você substituir essa função, você deve substituir provavelmente [OnInsertMenus](#oninsertmenus) e [OnSetMenu](#onsetmenu) também. Isso é um avançado substituível.  
  
 Os submenus na *pMenuShared* pode ser compartilhado por mais de um menu composto, se o servidor tiver sido chamado repetidamente `OnInsertMenus`. Portanto, você não deve excluir qualquer submenus em seu substituto do `OnRemoveMenus`; você apenas deve desanexá-los.  
  
 Para obter mais informações, consulte [IOleInPlaceFrame::RemoveMenus](/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-removemenus) no SDK do Windows.  
  
##  <a name="onscrollby"></a>  COleClientItem::OnScrollBy  
 Chamado pelo framework para rolar o item OLE em resposta às solicitações do servidor.  
  
```  
virtual BOOL OnScrollBy(CSize sizeExtent);
```  
  
### <a name="parameters"></a>Parâmetros  
 *sizeExtent*  
 Especifica as distâncias, em pixels, para rolar em x e y direções.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item foi rolado; 0 se o item não pode ser rolado.  
  
### <a name="remarks"></a>Comentários  
 Por exemplo, se o item OLE é parcialmente visível e o usuário é movido para fora da região visível ao executar a edição in-loco, essa função é chamada para manter o cursor visíveis. A implementação padrão não faz nada. Substitua essa função para rolar o item pelo valor especificado. Observe que, como resultado de rolagem, pode alterar a parte visível do item OLE. Chame [SetItemRects](#setitemrects) para atualizar o retângulo de visível do item.  
  
 Para obter mais informações, consulte [IOleInPlaceSite::Scroll](/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-scroll) no SDK do Windows.  
  
##  <a name="onsetmenu"></a>  COleClientItem::OnSetMenu  
 Chamado pelo framework duas vezes quando a ativação in-loco começa e termina; na primeira vez para instalar o menu composto e na segunda vez (com *holemenu* igual a NULL) para removê-lo.  
  
```  
virtual void OnSetMenu(
    CMenu* pMenuShared,  
    HOLEMENU holemenu,  
    HWND hwndActiveObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pMenuShared*  
 Ponteiro para o menu composto construído por chamadas para o [OnInsertMenus](#oninsertmenus) função de membro e o `InsertMenu` função.  
  
 *holemenu*  
 Identificador para o descritor de menu retornado pelo `OleCreateMenuDescriptor` de função, ou nulo se o código de expedição deve ser removida.  
  
 *hwndActiveObject*  
 Identificador para a janela de edição para o item OLE. Esta é a janela que receberá os comandos de edição do OLE.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão instala ou remove o menu composto e, em seguida, chama o [OleSetMenuDescriptor](/windows/desktop/api/ole2/nf-ole2-olesetmenudescriptor) função para instalar ou remover o código de expedição. Substitua essa função se a implementação padrão não é apropriada para seu aplicativo. Se você substituir essa função, você deve substituir provavelmente [OnInsertMenus](#oninsertmenus) e [OnRemoveMenus](#onremovemenus) também. Isso é um avançado substituível.  
  
 Para obter mais informações, consulte [OleCreateMenuDescriptor](/windows/desktop/api/ole2/nf-ole2-olecreatemenudescriptor), [OleSetMenuDescriptor](/windows/desktop/api/ole2/nf-ole2-olesetmenudescriptor), e [IOleInPlaceFrame::SetMenu](/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-setmenu) no SDK do Windows.  
  
##  <a name="onshowcontrolbars"></a>  COleClientItem::OnShowControlBars  
 Chamado pelo framework para mostrar e ocultar as barras de controle do aplicativo de contêiner.  
  
```  
virtual BOOL OnShowControlBars(
    CFrameWnd* pFrameWnd,  
    BOOL bShow);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pFrameWnd*  
 Ponteiro para a janela do quadro do aplicativo de contêiner. Isso pode ser uma janela de quadro principal ou em uma janela filho MDI.  
  
 *bMostrar*  
 Especifica se as barras de controle devem ser mostrados ou ocultados.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a chamada de função faz com que uma alteração no estado as barras de controle; 0 se a chamada faz com que nenhuma alteração, ou se *pFrameWnd* não aponta para a janela do quadro do contêiner.  
  
### <a name="remarks"></a>Comentários  
 Essa função retorna 0 se as barras de controle já estiverem no estado especificado pelo *bMostrar.* Isso seria ocorrer, por exemplo, se as barras de controle estão ocultos e *bMostrar* é FALSE.  
  
 A implementação padrão remove a barra de ferramentas da janela de quadro de nível superior.  
  
##  <a name="onshowitem"></a>  COleClientItem::OnShowItem  
 Chamado pelo framework para exibir o item OLE, tornando-o totalmente visível durante a edição.  
  
```  
virtual void OnShowItem();
```  
  
### <a name="remarks"></a>Comentários  
 Ele é usado quando seu aplicativo de contêiner dá suporte a links para itens inseridos (ou seja, se você tiver derivadas de sua classe de documento de [COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md)). Essa função é chamada durante a ativação in-loco ou quando o item OLE é uma origem do link e o usuário quer editá-lo. A implementação padrão ativa a primeira exibição no documento contêiner. Substitua essa função para rolar o documento para que o item OLE é visível.  
  
##  <a name="onupdateframetitle"></a>  COleClientItem::OnUpdateFrameTitle  
 Chamado pelo framework durante a ativação in-loco para atualizar a barra de título da janela do quadro.  
  
```  
virtual BOOL OnUpdateFrameTitle();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se essa função foi atualizada com êxito o título do quadro, caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não altera o título da janela do quadro. Substituir essa função se você quiser um título de quadros diferentes para seu aplicativo, por exemplo " *aplicativo de servidor* - *item* na *NomeDoMéd*" (por exemplo, "Microsoft Excel - planilha no relatório. DOC"). Isso é um avançado substituível.  
  
##  <a name="reactivateandundo"></a>  COleClientItem::ReactivateAndUndo  
 Chame essa função para reativar o item OLE e desfaça a última operação executada pelo usuário durante a edição in-loco.  
  
```  
BOOL ReactivateAndUndo();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se seu aplicativo de contêiner suporta o comando Desfazer, chame essa função se o usuário escolhe o comando Desfazer imediatamente após a desativação do item OLE.  
  
 Se o aplicativo de servidor é escrito com as bibliotecas de classes do Microsoft Foundation, essa função faz com que o servidor chamar [COleServerDoc::OnReactivateAndUndo](../../mfc/reference/coleserverdoc-class.md#onreactivateandundo).  
  
 Para obter mais informações, consulte [IOleInPlaceObject::ReactivateAndUndo](/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-reactivateandundo) no SDK do Windows.  
  
##  <a name="release"></a>  COleClientItem::Release  
 Chame essa função para limpar os recursos usados pelo item OLE.  
  
```  
virtual void Release(OLECLOSE dwCloseOption = OLECLOSE_NOSAVE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwCloseOption*  
 Sinalizador que especifica em quais circunstâncias o item OLE é salvo quando ele é retornado para o estado carregado. Para obter uma lista de valores possíveis, consulte [COleClientItem::Close](#close).  
  
### <a name="remarks"></a>Comentários  
 `Release` é chamado pelo `COleClientItem` destruidor.  
  
 Para obter mais informações, consulte [IUnknown:: Release](/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) no SDK do Windows.  
  
##  <a name="reload"></a>  COleClientItem::Reload  
 Fecha e recarrega o item.  
  
```  
BOOL Reload();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chame o `Reload` função depois de ativar o item como um item de outro tipo por uma chamada para [ActivateAs](#activateas).  
  
##  <a name="run"></a>  COleClientItem::Run  
 Executa o aplicativo associado a este item.  
  
```  
void Run();
```  
  
### <a name="remarks"></a>Comentários  
 Chamar o `Run` a função de membro para iniciar o aplicativo de servidor antes de ativar o item. Isso é feito automaticamente pelo [Activate](#activate) e [DoVerb](#doverb), portanto, geralmente não é necessário chamar essa função. Chame essa função se for necessário executar o servidor para definir um atributo de item, tais como [SetExtent](#setextent), antes de executar [DoVerb](#doverb).  
  
##  <a name="setdrawaspect"></a>  COleClientItem::SetDrawAspect  
 Chamar o `SetDrawAspect` a função de membro para definir o "aspecto" ou a exibição do item.  
  
```  
virtual void SetDrawAspect(DVASPECT nDrawAspect);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nDrawAspect*  
 Um valor de enumeração DVASPECT. Esse parâmetro pode ter um dos seguintes valores:  
  
- Item DVASPECT_CONTENT é representado de forma que ele pode ser exibido como um objeto inserido dentro do seu contêiner.  
  
- DVASPECT_THUMBNAIL Item será renderizado em uma representação "em miniatura" para que ele pode ser exibido em uma ferramenta de procura.  
  
- Item DVASPECT_ICON é representado por um ícone.  
  
- Item DVASPECT_DOCPRINT é representada como se fosse imprimível usando o comando Imprimir no menu arquivo.  
  
### <a name="remarks"></a>Comentários  
 O aspecto Especifica como o item a ser processada pelo [desenhar](#draw) quando o valor padrão para essa função *nDrawAspect* argumento é usado.  
  
 Essa função é chamada automaticamente pelo alterar ícone (e outras caixas de diálogo que chamam a caixa de diálogo Alterar ícone diretamente) para habilitar o aspecto de exibição icônico quando solicitado pelo usuário.  
  
##  <a name="setextent"></a>  COleClientItem::SetExtent  
 Chame essa função para especificar a quantidade de espaço está disponível para o item OLE.  
  
```  
void SetExtent(
    const CSize& size,  
    DVASPECT nDrawAspect = DVASPECT_CONTENT);
```  
  
### <a name="parameters"></a>Parâmetros  
 *size*  
 Um [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto que contém as informações de tamanho.  
  
 *nDrawAspect*  
 Especifica o aspecto do item OLE cujos limites devem ser definidas. Para os valores possíveis, consulte [SetDrawAspect](#setdrawaspect).  
  
### <a name="remarks"></a>Comentários  
 Se o aplicativo de servidor foi escrito usando a biblioteca Microsoft Foundation Class, isso faz com que o [OnSetExtent](../../mfc/reference/coleserveritem-class.md#onsetextent) função de membro de correspondente `COleServerItem` objeto a ser chamado. O item OLE pode, em seguida, ajustar adequadamente sua exibição. As dimensões devem estar em unidades MM_HIMETRIC. Chame essa função quando o usuário redimensiona o item OLE ou se você oferecer suporte a alguma forma de negociação de layout.  
  
 Para obter mais informações, consulte [IOleObject::SetExtent](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setextent) no SDK do Windows.  
  
##  <a name="sethostnames"></a>  COleClientItem::SetHostNames  
 Chame essa função para especificar o nome do aplicativo de contêiner e o nome do contêiner para um item OLE inserido.  
  
```  
void SetHostNames(
    LPCTSTR lpszHost,  
    LPCTSTR lpszHostObj);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszHost*  
 Ponteiro para o nome visível pelo usuário do aplicativo recipiente.  
  
 *lpszHostObj*  
 Ponteiro para uma cadeia de caracteres de identificação do contêiner que contém o item OLE.  
  
### <a name="remarks"></a>Comentários  
 Se o aplicativo de servidor foi escrito usando a biblioteca Microsoft Foundation Class, essa função chama o [OnSetHostNames](../../mfc/reference/coleserverdoc-class.md#onsethostnames) função de membro a `COleServerDoc` documento que contém o item OLE. Essas informações são usadas em títulos de janela quando o item OLE está sendo editado. Cada vez que um documento de contêiner é carregado, o framework chama essa função para todos os itens OLE no documento. `SetHostNames` é aplicável apenas aos itens inseridos. Não é necessário chamar essa função sempre que um item OLE inserido é ativado para edição.  
  
 Isso também é chamado automaticamente com o nome do aplicativo e o nome do documento quando um objeto é carregado ou quando um arquivo é salvo com um nome diferente. Da mesma forma, não é geralmente necessário chamar essa função diretamente.  
  
 Para obter mais informações, consulte [IOleObject::SetHostNames](/windows/desktop/api/oleidl/nf-oleidl-ioleobject-sethostnames) no SDK do Windows.  
  
##  <a name="seticonicmetafile"></a>  COleClientItem::SetIconicMetafile  
 Armazena em cache o metarquivo usado para desenhar o ícone do item.  
  
```  
BOOL SetIconicMetafile(HGLOBAL hMetaPict);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hMetaPict*  
 Um identificador para o metarquivo usado para desenhar o ícone do item.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use [GetIconicMetafile](#geticonicmetafile) para recuperar o metarquivo.  
  
 O *hMetaPict* parâmetro é copiado para o item; portanto, *hMetaPict* deve ser liberada por ele.  
  
##  <a name="setitemrects"></a>  COleClientItem::SetItemRects  
 Chame essa função para definir o retângulo delimitador ou retângulo visível do item OLE.  
  
```  
BOOL SetItemRects(
    LPCRECT lpPosRect = NULL,  
    LPCRECT lpClipRect = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lprcPosRect*  
 Ponteiro para o retângulo que contém os limites do item OLE em relação à sua janela pai, em coordenadas do cliente.  
  
 *lprcClipRect*  
 Ponteiro para o retângulo que contém os limites da parte visível do item OLE em relação à sua janela pai, em coordenadas do cliente.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função é chamada pela implementação do padrão de [OnChangeItemPosition](#onchangeitemposition) função de membro. Você deve chamar essa função sempre que a posição ou a parte visível da OLE alterações no item. Geralmente, isso significa que você chamá-lo do seu modo de exibição [OnSize](../../mfc/reference/cwnd-class.md#onsize) e [OnScrollBy](../../mfc/reference/cview-class.md#onscrollby) funções de membro.  
  
 Para obter mais informações, consulte [IOleInPlaceObject::SetObjectRects](/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceobject-setobjectrects) no SDK do Windows.  
  
##  <a name="setlinkupdateoptions"></a>  COleClientItem::SetLinkUpdateOptions  
 Chame essa função para definir a opção de atualização de link para a apresentação do item vinculado especificado.  
  
```  
void SetLinkUpdateOptions(OLEUPDATE dwUpdateOpt);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwUpdateOpt*  
 O valor da opção de atualização de link para este item. Esse valor deve ser um destes procedimentos:  
  
- OLEUPDATE_ALWAYS atualizar o item vinculado sempre que possível. Essa opção dá suporte a no botão de opção de atualização automática de link na caixa de diálogo de Links.  
  
- OLEUPDATE_ONCALL atualizar o item vinculado somente na solicitação do aplicativo de contêiner (quando o [UpdateLink](#updatelink) é chamada de função de membro). Essa opção dá suporte a no botão de opção de atualização Manual de link na caixa de diálogo de Links.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, você não deve alterar as opções de atualização escolhidas pelo usuário na caixa de diálogo de Links.  
  
 Para obter mais informações, consulte [IOleLink::SetUpdateOptions](/windows/desktop/api/oleidl/nf-oleidl-iolelink-setupdateoptions) no SDK do Windows.  
  
##  <a name="setprintdevice"></a>  COleClientItem::SetPrintDevice  
 Chame essa função para alterar o dispositivo de destino de impressão para este item.  
  
```  
BOOL SetPrintDevice(const DVTARGETDEVICE* ptd);  
BOOL SetPrintDevice(const PRINTDLG* ppd);
```  
  
### <a name="parameters"></a>Parâmetros  
 *ptd*  
 Ponteiro para um [DVTARGETDEVICE](/windows/desktop/api/objidl/ns-objidl-tagdvtargetdevice) estrutura de dados, que contém informações sobre o novo dispositivo de destino de impressão. Pode ser NULL.  
  
 *PPD*  
 Ponteiro para um [PRINTDLG](https://msdn.microsoft.com/library/windows/desktop/ms646940) estrutura de dados, que contém informações sobre o novo dispositivo de destino de impressão. Pode ser NULL.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função atualiza o dispositivo de destino de impressão para o item, mas não atualiza o cache de apresentação. Para atualizar o cache de apresentação para um item, chame [UpdateLink](#updatelink).  
  
 Os argumentos para essa função contêm informações que o sistema OLE usa para identificar o dispositivo de destino. O `PRINTDLG` estrutura contém informações que o Windows usa para inicializar a caixa de diálogo de impressão comum. Depois que o usuário fecha a caixa de diálogo, o Windows retorna informações sobre as seleções do usuário nessa estrutura. O `m_pd` membro de uma [CPrintDialog](../../mfc/reference/cprintdialog-class.md) objeto é um `PRINTDLG` estrutura.  
  
 Para obter mais informações sobre essa estrutura, consulte [PRINTDLG](/windows/desktop/api/commdlg/ns-commdlg-tagpda) no SDK do Windows.  
  
 Para obter mais informações, consulte [DVTARGETDEVICE](/windows/desktop/api/objidl/ns-objidl-tagdvtargetdevice) no SDK do Windows.  
  
##  <a name="updatelink"></a>  COleClientItem::UpdateLink  
 Chame essa função para atualizar os dados da apresentação do item OLE imediatamente.  
  
```  
BOOL UpdateLink();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero em caso de êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Itens vinculados, a função localiza a origem do link para obter uma nova apresentação para o item OLE. Esse processo pode envolver a execução de um ou mais aplicativos de servidor, que pode ser demorados. Para itens incorporados, a função opera recursivamente, verificando se o item inserido contém links que podem estar desatualizadas e atualizá-los. O usuário também pode atualizar manualmente usando a caixa de diálogo Links de links individuais.  
  
 Para obter mais informações, consulte [IOleLink::Update](/windows/desktop/api/oleidl/nf-oleidl-iolelink-update) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MFCBIND](../../visual-cpp-samples.md)   
 [Exemplo MFC OCLIENT](../../visual-cpp-samples.md)   
 [Classe CDocItem](../../mfc/reference/cdocitem-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleServerItem](../../mfc/reference/coleserveritem-class.md)
