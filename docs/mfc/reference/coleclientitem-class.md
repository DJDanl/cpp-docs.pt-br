---
title: Classe COleClientItem | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
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
- OLE containers, client items
- COleClientItem class
- OLE client item class
- container interface class
- OLE containers, interface class
- client items and OLE containers
ms.assetid: 7f571b7c-2758-4839-847a-0cf1ef643128
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
ms.openlocfilehash: a200da03305c20eaf2d9c1de1ea585c82410c570
ms.lasthandoff: 02/25/2017

---
# <a name="coleclientitem-class"></a>Classe COleClientItem
Define a interface do contêiner para itens OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleClientItem : public CDocItem  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleClientItem::COleClientItem](#coleclientitem)|Constrói um objeto `COleClientItem`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleClientItem::Activate](#activate)|Abre o item OLE para uma operação e, em seguida, executa o verbo especificado.|  
|[COleClientItem::ActivateAs](#activateas)|Ativa o item como outro tipo.|  
|[COleClientItem::AttachDataObject](#attachdataobject)|Acessa os dados no objeto OLE.|  
|[COleClientItem::CanCreateFromData](#cancreatefromdata)|Indica se um aplicativo de contêiner pode criar um objeto incorporado.|  
|[COleClientItem::CanCreateLinkFromData](#cancreatelinkfromdata)|Indica se um aplicativo de contêiner pode criar um objeto vinculado.|  
|[COleClientItem::CanPaste](#canpaste)|Indica se a área de transferência contém um item OLE incorporável ou estático.|  
|[COleClientItem::CanPasteLink](#canpastelink)|Indica se a área de transferência contém um item OLE vinculação.|  
|[COleClientItem::Close](#close)|Fecha um link para um servidor, mas não destrói o item OLE.|  
|[COleClientItem::ConvertTo](#convertto)|Converte o item em outro tipo.|  
|[COleClientItem::CopyToClipboard](#copytoclipboard)|Copia o item OLE para a área de transferência.|  
|[COleClientItem::CreateCloneFrom](#createclonefrom)|Cria uma duplicata de um item existente.|  
|[COleClientItem::CreateFromClipboard](#createfromclipboard)|Cria um item incorporado da área de transferência.|  
|[COleClientItem::CreateFromData](#createfromdata)|Cria um item incorporado de um objeto de dados.|  
|[COleClientItem::CreateFromFile](#createfromfile)|Cria um item inserido em um arquivo.|  
|[COleClientItem::CreateLinkFromClipboard](#createlinkfromclipboard)|Cria um item vinculado da área de transferência.|  
|[COleClientItem::CreateLinkFromData](#createlinkfromdata)|Cria um item vinculado de um objeto de dados.|  
|[COleClientItem::CreateLinkFromFile](#createlinkfromfile)|Cria um item vinculado em um arquivo.|  
|[COleClientItem::CreateNewItem](#createnewitem)|Cria um novo item inserido, iniciando o aplicativo de servidor.|  
|[COleClientItem::CreateStaticFromClipboard](#createstaticfromclipboard)|Cria um item estático da área de transferência.|  
|[COleClientItem::CreateStaticFromData](#createstaticfromdata)|Cria um item estático de um objeto de dados.|  
|[COleClientItem::Deactivate](#deactivate)|Desativa o item.|  
|[COleClientItem::DeactivateUI](#deactivateui)|Restaura a interface do usuário do aplicativo de contêiner para seu estado original.|  
|[COleClientItem::Delete](#delete)|Exclui ou fecha o item OLE se fosse um item vinculado.|  
|[COleClientItem::DoDragDrop](#dodragdrop)|Executa uma operação de arrastar e soltar.|  
|[COleClientItem::DoVerb](#doverb)|Executa o verbo especificado.|  
|[COleClientItem::Draw](#draw)|Desenha o item OLE.|  
|[COleClientItem::GetActiveView](#getactiveview)|Obtém a exibição na qual o item está ativado no local.|  
|[COleClientItem::GetCachedExtent](#getcachedextent)|Retorna os limites do retângulo do item OLE.|  
|[COleClientItem::GetClassID](#getclassid)|Obtém a ID de classe. do item atual|  
|[COleClientItem::GetClipboardData](#getclipboarddata)|Obtém os dados que devem ser colocados na área de transferência chamando o `CopyToClipboard` função de membro.|  
|[COleClientItem::GetDocument](#getdocument)|Retorna o `COleDocument` objeto que contém o item atual.|  
|[COleClientItem::GetDrawAspect](#getdrawaspect)|Obtém o modo de exibição atual do item para processamento.|  
|[COleClientItem::GetExtent](#getextent)|Retorna os limites do retângulo do item OLE.|  
|[COleClientItem::GetIconFromRegistry](#geticonfromregistry)|Recupera um identificador para um ícone associado ao servidor de um CLSID particular.|  
|[COleClientItem::GetIconicMetafile](#geticonicmetafile)|Obtém o metarquivo usado para desenhar o ícone do item.|  
|[COleClientItem::GetInPlaceWindow](#getinplacewindow)|Retorna um ponteiro para a janela de edição do item no local.|  
|[COleClientItem::GetItemState](#getitemstate)|Obtém o estado do item atual.|  
|[COleClientItem::GetLastStatus](#getlaststatus)|Retorna o status da última operação OLE.|  
|[COleClientItem::GetLinkUpdateOptions](#getlinkupdateoptions)|Retorna o modo de atualização para um item vinculado (recursos avançados).|  
|[COleClientItem::GetType](#gettype)|Retorna o tipo (incorporado, vinculado ou estático) do item OLE.|  
|[COleClientItem::GetUserType](#getusertype)|Obtém uma cadeia de caracteres que descreve o tipo do item.|  
|[COleClientItem::IsInPlaceActive](#isinplaceactive)|Retorna `TRUE` se o item está ativo no local.|  
|[COleClientItem::IsLinkUpToDate](#islinkuptodate)|Retorna **TRUE** se um item vinculado é atualizado com o documento de origem.|  
|[COleClientItem::IsModified](#ismodified)|Retorna `TRUE` se o item tiver sido modificado desde que foi salvo pela última vez.|  
|[COleClientItem::IsOpen](#isopen)|Retorna `TRUE` se o item estiver aberto no aplicativo do servidor.|  
|[COleClientItem::IsRunning](#isrunning)|Retorna `TRUE` se estiver executando o aplicativo de servidor do item.|  
|[COleClientItem::OnActivate](#onactivate)|Chamado pela estrutura para notificar o item que está ativado.|  
|[COleClientItem::OnActivateUI](#onactivateui)|Chamado pela estrutura para notificar o item que é ativado e deve mostrar interface do usuário.|  
|[COleClientItem::OnChange](#onchange)|Chamado quando o item OLE é alterada no servidor. Implementação necessários.|  
|[COleClientItem::OnDeactivate](#ondeactivate)|Chamado pela estrutura quando um item é desativado.|  
|[COleClientItem::OnDeactivateUI](#ondeactivateui)|Chamado pela estrutura quando o servidor removido sua interface do usuário no local.|  
|[COleClientItem::OnGetClipboardData](#ongetclipboarddata)|Chamado pela estrutura para obter os dados a serem copiados para a área de transferência.|  
|[COleClientItem::OnInsertMenus](#oninsertmenus)|Chamado pela estrutura para criar um menu composto.|  
|[COleClientItem::OnRemoveMenus](#onremovemenus)|Chamado pela estrutura para remover os menus do contêiner de um menu composto.|  
|[COleClientItem::OnSetMenu](#onsetmenu)|Chamado pela estrutura para instalar e remover um menu composto.|  
|[COleClientItem::OnShowControlBars](#onshowcontrolbars)|Chamado pela estrutura para mostrar e ocultar as barras de controle.|  
|[COleClientItem::OnUpdateFrameTitle](#onupdateframetitle)|Chamado pela estrutura para atualizar a barra de título da janela de quadro.|  
|[COleClientItem::ReactivateAndUndo](#reactivateandundo)|Reativa o item e desfaz a última operação de edição in-loco.|  
|[COleClientItem::Release](#release)|Libera a conexão para uma item vinculada de OLE e fechá-lo se ele estava aberto. Não destrói o item do cliente.|  
|[COleClientItem::Reload](#reload)|Recarrega o item após uma chamada para `ActivateAs`.|  
|[COleClientItem::Run](#run)|Executa o aplicativo associado ao item.|  
|[COleClientItem::SetDrawAspect](#setdrawaspect)|Define o modo de exibição atual para o processamento do item.|  
|[COleClientItem::SetExtent](#setextent)|Define o retângulo delimitador de item OLE.|  
|[COleClientItem::SetHostNames](#sethostnames)|Define os nomes do servidor exibe ao editar o item OLE.|  
|[COleClientItem::SetIconicMetafile](#seticonicmetafile)|Armazena em cache o metarquivo usado para desenhar o ícone do item.|  
|[COleClientItem::SetItemRects](#setitemrects)|Define o retângulo delimitador do item.|  
|[COleClientItem::SetLinkUpdateOptions](#setlinkupdateoptions)|Define o modo de atualização para um item vinculado (recursos avançados).|  
|[COleClientItem::SetPrintDevice](#setprintdevice)|Define o dispositivo de destino de impressão para este item de cliente.|  
|[COleClientItem::UpdateLink](#updatelink)|Atualiza o cache de apresentação de um item.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleClientItem::CanActivate](#canactivate)|Chamado pela estrutura para determinar se a ativação no local é permitida.|  
|[COleClientItem::OnChangeItemPosition](#onchangeitemposition)|Chamado pela estrutura quando muda de posição de um item.|  
|[COleClientItem::OnDeactivateAndUndo](#ondeactivateandundo)|Chamado pela estrutura para desfazer após a ativação.|  
|[COleClientItem::OnDiscardUndoState](#ondiscardundostate)|Chamado pela estrutura para descartar informações de estado de recuperação do item.|  
|[COleClientItem::OnGetClipRect](#ongetcliprect)|Chamado pela estrutura para obter as coordenadas do retângulo de corte do item.|  
|[COleClientItem::OnGetItemPosition](#ongetitemposition)|Chamado pela estrutura para obter a posição do item em relação ao modo de exibição.|  
|[COleClientItem::OnGetWindowContext](#ongetwindowcontext)|Chamado pela estrutura quando um item é ativado em vigor.|  
|[COleClientItem::OnScrollBy](#onscrollby)|Chamado pela estrutura para rolar e exibir o item.|  
|[COleClientItem::OnShowItem](#onshowitem)|Chamado pela estrutura para exibir o item OLE.|  
  
## <a name="remarks"></a>Comentários  
 Um item OLE representa dados, criadas e mantidas por um aplicativo de servidor, que pode ser incorporado "diretamente" em um documento para que ele apareça para o usuário seja um único documento. O resultado é um "documento composto" composto por item OLE e que contém o documento.  
  
 Um item OLE pode ser inserido ou vinculado. Se for inserido, seus dados são armazenados como parte do documento composto. Se ele estiver vinculado, seus dados são armazenados como parte de um arquivo separado criado pelo aplicativo de servidor, e apenas um link para esse arquivo é armazenado no documento composto. Todos os itens OLE contêm informações que especificam o aplicativo de servidor que deve ser chamado para editá-los.  
  
 `COleClientItem`define várias funções substituíveis que são chamadas em resposta às solicitações do aplicativo do servidor; sobre esses substituíveis geralmente agem como notificações. Isso permite que o aplicativo de servidor para informar o contêiner das alterações feitas pelo usuário ao editar o item OLE ou recuperar informações necessárias durante a edição.  
  
 `COleClientItem`pode ser usado com qualquer um de [COleDocument](../../mfc/reference/coledocument-class.md), [COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md), ou [COleServerDoc](../../mfc/reference/coleserverdoc-class.md) classe. Usar `COleClientItem`, derive uma classe dele e implementar o [OnChange](#onchange) função de membro, que define como o contêiner responde às alterações feitas no item. Para oferecer suporte a ativação no local, substituir o [OnGetItemPosition](#ongetitemposition) função de membro. Essa função fornece informações sobre a posição exibida do item OLE.  
  
 Para obter mais informações sobre como usar a interface do contêiner, consulte os artigos [contêineres: Implementando um contêiner](../../mfc/containers-implementing-a-container.md) e [ativação](../../mfc/activation-cpp.md).  
  
> [!NOTE]
>  O [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] se refere a itens vinculados e inseridos como "objetos" e se refere a tipos de itens como "classes". Esta referência usa o termo "item" para distinguir a entidade OLE de objeto C++ correspondente e o termo "tipo" para distinguir a categoria OLE da classe C++.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CDocItem](../../mfc/reference/cdocitem-class.md)  
  
 `COleClientItem`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  
  
##  <a name="activate"></a>COleClientItem::Activate  
 Chame essa função para executar o verbo especificado em vez de [DoVerb](#doverb) para que você possa fazer seu próprio processamento quando uma exceção é lançada.  
  
```  
void Activate(
    LONG nVerb,  
    CView* pView,  
    LPMSG lpMsg = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nVerb`  
 Especifica o verbo a ser executado. Ele pode ser um dos seguintes:  
  
|Valor|Significado|Símbolo|  
|-----------|-------------|------------|  
|– 0|Verbo primário|`OLEIVERB_PRIMARY`|  
|– 1|Verbo secundário|(Nenhum)|  
|– 1|Item de exibição para edição|`OLEIVERB_SHOW`|  
|– 2|Editar item na janela separada|`OLEIVERB_OPEN`|  
|– 3|Ocultar item|`OLEIVERB_HIDE`|  
  
 O valor –&1; normalmente é um alias para outro verbo. Se não há suporte para a edição aberta, –&2; tem o mesmo efeito que –&1;. Para obter valores adicionais, consulte [IOleObject:: DoVerb](http://msdn.microsoft.com/library/windows/desktop/ms694508) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `pView`  
 Ponteiro para a janela de exibição de contêiner que contém o item OLE; Isso é usado pelo aplicativo de servidor de ativação no local. Este parâmetro deve ser **nulo** se o contêiner não dá suporte a ativação no local.  
  
 `lpMsg`  
 Ponteiro para a mensagem que causou o item a ser ativado.  
  
### <a name="remarks"></a>Comentários  
 Se o aplicativo de servidor foi escrito usando a biblioteca Microsoft Foundation Class, essa função faz com que o [OnDoVerb](../../mfc/reference/coleserveritem-class.md#ondoverb) a função de membro de correspondente `COleServerItem` objeto a ser executado.  
  
 Se o verbo primário é editar e zero é especificada no `nVerb` parâmetro, o aplicativo do servidor é iniciado para permitir que o item OLE a ser editada. Se o aplicativo de contêiner oferece suporte a ativação no local, a edição pode ser feita no lugar. Se o contêiner não dá suporte a ativação no local (ou se for especificado, o verbo Open), o servidor é iniciado em uma janela separada e edição pode ser feita lá. Normalmente, quando o usuário do aplicativo recipiente clica duas vezes no item OLE, o valor para o verbo primário no `nVerb` parâmetro determina qual ação pode levar o usuário. No entanto, se o servidor oferecer suporte a apenas uma ação, ele usa essa ação, independentemente de qual valor é especificado no `nVerb` parâmetro.  
  
 Para obter mais informações, consulte [IOleObject:: DoVerb](http://msdn.microsoft.com/library/windows/desktop/ms694508) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="activateas"></a>COleClientItem::ActivateAs  
 Usa recursos de conversão de objeto do OLE para ativar o item como se fosse um item do tipo especificado por `clsidNew`.  
  
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
 ID de uma referência à classe atual do item. A ID de classe deve representar o tipo de objeto real, como armazenado, a menos que ele é um link. Nesse caso, ele deve ser o CLSID do item ao qual o link se refere. O [COleConvertDialog](../../mfc/reference/coleconvertdialog-class.md) fornece automaticamente a ID de classe correto para o item.  
  
 `clsidNew`  
 Uma referência para a ID de classe de destino.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Isso é chamado automaticamente pelo [COleConvertDialog::DoConvert](../../mfc/reference/coleconvertdialog-class.md#doconvert). Ele não é geralmente chamado diretamente.  
  
##  <a name="attachdataobject"></a>COleClientItem::AttachDataObject  
 Chame essa função para inicializar um [COleDataObject](../../mfc/reference/coledataobject-class.md) para acessar os dados no item OLE.  
  
```  
void AttachDataObject(COleDataObject& rDataObject) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *rDataObject*  
 Referência a um `COleDataObject` objeto será inicializado para permitir o acesso aos dados no item OLE.  
  
##  <a name="canactivate"></a>COleClientItem::CanActivate  
 Chamado pela estrutura quando o usuário solicita ativação no local do item OLE; o valor de retorno da função determina se a ativação no local é permitida.  
  
```  
virtual BOOL CanActivate();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a ativação no local é permitida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão permite a ativação no local se o contêiner tiver uma janela válido. Substitua essa função para implementar uma lógica especial para aceitar ou recusar a solicitação de ativação. Por exemplo, uma solicitação de ativação pode ser recusada se o item OLE é muito pequeno ou não está visível no momento.  
  
 Para obter mais informações, consulte [IOleInPlaceSite::CanInPlaceActivate](http://msdn.microsoft.com/library/windows/desktop/ms691236) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="cancreatefromdata"></a>COleClientItem::CanCreateFromData  
 Verifica se um aplicativo de contêiner pode criar um objeto incorporado a determinado `COleDataObject` objeto.  
  
```  
static BOOL PASCAL CanCreateFromData(const COleDataObject* pDataObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDataObject`  
 Ponteiro para o [COleDataObject](../../mfc/reference/coledataobject-class.md) objeto do qual o item OLE deve ser criado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o contêiner pode criar um objeto incorporado a `COleDataObject` objeto; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O `COleDataObject` nas transferências de dados, a classe é usada para recuperar dados em vários formatos da área de transferência, por meio de arrastar e soltar, ou de um item OLE incorporado.  
  
 Contêineres podem usar essa função para optar por habilitar ou desabilitar os comandos Editar colar e editar Colar especial.  
  
 Para obter mais informações, consulte o artigo [objetos de dados e fontes de dados (OLE)](../../mfc/data-objects-and-data-sources-ole.md).  
  
##  <a name="cancreatelinkfromdata"></a>COleClientItem::CanCreateLinkFromData  
 Verifica se um aplicativo de contêiner pode criar um objeto vinculado a partir de determinado `COleDataObject` objeto.  
  
```  
static BOOL PASCAL CanCreateLinkFromData(const COleDataObject* pDataObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDataObject`  
 Ponteiro para o [COleDataObject](../../mfc/reference/coledataobject-class.md) objeto do qual o item OLE deve ser criado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o contêiner pode criar um objeto vinculado a partir de `COleDataObject` objeto.  
  
### <a name="remarks"></a>Comentários  
 O `COleDataObject` nas transferências de dados, a classe é usada para recuperar dados em vários formatos da área de transferência, por meio de arrastar e soltar, ou de um item OLE incorporado.  
  
 Contêineres podem usar essa função para optar por habilitar ou desabilitar os comandos Editar Colar especial e editar Colar vínculo.  
  
 Para obter mais informações, consulte o artigo [objetos de dados e fontes de dados (OLE)](../../mfc/data-objects-and-data-sources-ole.md).  
  
##  <a name="canpaste"></a>COleClientItem::CanPaste  
 Chame essa função para ver se um item OLE incorporado pode ser colado da área de transferência.  
  
```  
static BOOL PASCAL CanPaste();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se um item OLE incorporado pode ser colado da área de transferência; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [OleGetClipboard](http://msdn.microsoft.com/library/windows/desktop/ms692778) e [OleQueryCreateFromData](http://msdn.microsoft.com/library/windows/desktop/ms683739) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="canpastelink"></a>COleClientItem::CanPasteLink  
 Chame essa função para ver se um item OLE vinculado pode ser colado da área de transferência.  
  
```  
static BOOL PASCAL CanPasteLink();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se um item OLE vinculado pode ser colado da área de transferência; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [OleGetClipboard](http://msdn.microsoft.com/library/windows/desktop/ms692778) e [OleQueryLinkFromData](http://msdn.microsoft.com/library/windows/desktop/ms690244) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="close"></a>COleClientItem::Close  
 Chame essa função para alterar o estado de um item OLE do estado de execução para o estado carregado, ou seja, carregado com seu manipulador na memória, mas com o servidor não está em execução.  
  
```  
void Close(OLECLOSE dwCloseOption = OLECLOSE_SAVEIFDIRTY);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwCloseOption`  
 Sinalizador que especifica sob quais circunstâncias o item OLE é salva quando ele retorna ao estado carregado. Ele pode ter um dos seguintes valores:  
  
- `OLECLOSE_SAVEIFDIRTY`Salve o item OLE.  
  
- `OLECLOSE_NOSAVE`Não salve o item OLE.  
  
- `OLECLOSE_PROMPTSAVE`Solicite ao usuário se deve salvar o item OLE.  
  
### <a name="remarks"></a>Comentários  
 Essa função não tem efeito quando o item OLE não está em execução.  
  
 Para obter mais informações, consulte [IOleObject::Close](http://msdn.microsoft.com/library/windows/desktop/ms683922) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="coleclientitem"></a>COleClientItem::COleClientItem  
 Constrói um `COleClientItem` do objeto e o adiciona à coleção do documento contêiner de itens do documento, que cria o objeto de C++ e não executa qualquer inicialização OLE.  
  
```  
COleClientItem(COleDocument* pContainerDoc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pContainerDoc`  
 Ponteiro para o documento de contêiner que contém esse item. Isso pode ser qualquer [COleDocument](../../mfc/reference/coledocument-class.md) derivado.  
  
### <a name="remarks"></a>Comentários  
 Se você passar um **nulo** ponteiro, nenhum acréscimo é feito no documento contêiner. Você deve chamar explicitamente [COleDocument::AddItem](../../mfc/reference/coledocument-class.md#additem).  
  
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
  
##  <a name="convertto"></a>COleClientItem::ConvertTo  
 Chame essa função de membro para converter o item para o tipo especificado pelo `clsidNew`.  
  
```  
virtual BOOL ConvertTo(REFCLSID clsidNew);
```  
  
### <a name="parameters"></a>Parâmetros  
 `clsidNew`  
 A ID de classe do tipo de destino.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Isso é chamado automaticamente pelo [COleConvertDialog](../../mfc/reference/coleconvertdialog-class.md). Não é necessário chamá-lo diretamente.  
  
##  <a name="copytoclipboard"></a>COleClientItem::CopyToClipboard  
 Chame essa função para copiar o item OLE para a área de transferência.  
  
```  
void CopyToClipboard(BOOL bIncludeLink = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bIncludeLink`  
 **TRUE** se as informações do link devem ser copiadas para a área de transferência, permitindo que um item vinculado ser colado; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, você chama essa função ao escrever manipuladores de mensagens para os comandos Recortar ou copiar no menu Editar. Você deve implementar a seleção de itens em seu aplicativo de contêiner para implementar os comandos Recortar ou copiar.  
  
 Para obter mais informações, consulte [OleSetClipboard](http://msdn.microsoft.com/library/windows/desktop/ms686623) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="createclonefrom"></a>COleClientItem::CreateCloneFrom  
 Chame essa função para criar uma cópia do item OLE especificado.  
  
```  
BOOL CreateCloneFrom(const COleClientItem* pSrcItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pSrcItem*  
 Ponteiro para o item OLE a ser duplicado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A cópia é idêntica ao item de origem. Você pode usar essa função para dar suporte a operações de desfazer.  
  
##  <a name="createfromclipboard"></a>COleClientItem::CreateFromClipboard  
 Chame essa função para criar um item incorporado do conteúdo da área de transferência.  
  
```  
BOOL CreateFromClipboard(
    OLERENDER render = OLERENDER_DRAW,  
    CLIPFORMAT cfFormat = 0,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *processar*  
 Sinalizador que especifica como o servidor processará o item OLE. Para obter os valores possíveis, consulte [OLERENDER](http://msdn.microsoft.com/library/windows/desktop/ms691507) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `cfFormat`  
 Especifica o formato de dados da área de transferência a ser armazenado em cache ao criar o item OLE.  
  
 `lpFormatEtc`  
 Ponteiro para uma [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura usada se *renderizar* é **OLERENDER_FORMAT** ou **OLERENDER_DRAW**. Forneça um valor para esse parâmetro somente se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo `cfFormat`. Se você omitir esse parâmetro, os valores padrão são usados para os outros campos de **FORMATETC** estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você normalmente chama essa função do manipulador de mensagens para o comando Colar no menu Editar. (O comando Colar é habilitado pela estrutura se o [CanPaste](#canpaste) função membro retorna nulo.)  
  
 Para obter mais informações, consulte [OLERENDER](http://msdn.microsoft.com/library/windows/desktop/ms691507) e [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="createfromdata"></a>COleClientItem::CreateFromData  
 Chame essa função para criar um item incorporado de um `COleDataObject` objeto.  
  
```  
BOOL CreateFromData(
    COleDataObject* pDataObject,  
    OLERENDER render = OLERENDER_DRAW,  
    CLIPFORMAT cfFormat = 0,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDataObject`  
 Ponteiro para o [COleDataObject](../../mfc/reference/coledataobject-class.md) objeto do qual o item OLE deve ser criado.  
  
 *processar*  
 Sinalizador que especifica como o servidor processará o item OLE. Para obter os valores possíveis, consulte [OLERENDER](http://msdn.microsoft.com/library/windows/desktop/ms691507) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `cfFormat`  
 Especifica o formato de dados da área de transferência a ser armazenado em cache ao criar o item OLE.  
  
 `lpFormatEtc`  
 Ponteiro para uma [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura usada se *renderizar* é **OLERENDER_FORMAT** ou **OLERENDER_DRAW**. Forneça um valor para esse parâmetro somente se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo `cfFormat`. Se você omitir esse parâmetro, os valores padrão são usados para os outros campos de **FORMATETC** estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Operações de transferência de dados, como Colar da área de transferência ou operações de arrastar e soltar, fornecem `COleDataObject` objetos que contém as informações oferecidas por um aplicativo de servidor. Ele é normalmente usado em seu substituto do [CView::OnDrop](../../mfc/reference/cview-class.md#ondrop).  
  
 Para obter mais informações, consulte [OleCreateFromData](http://msdn.microsoft.com/library/windows/desktop/ms691211), [OLERENDER](http://msdn.microsoft.com/library/windows/desktop/ms691507), e [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="createfromfile"></a>COleClientItem::CreateFromFile  
 Chame essa função para criar um item OLE incorporado de um arquivo.  
  
```  
BOOL CreateFromFile(
    LPCTSTR lpszFileName,  
    REFCLSID clsid = CLSID_NULL,  
    OLERENDER render = OLERENDER_DRAW,  
    CLIPFORMAT cfFormat = 0,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFileName`  
 Ponteiro para o nome do arquivo do qual o item OLE a ser criado.  
  
 `clsid`  
 Reservado para uso futuro.  
  
 *processar*  
 Sinalizador que especifica como o servidor processará o item OLE. Para obter os valores possíveis, consulte [OLERENDER](http://msdn.microsoft.com/library/windows/desktop/ms691507) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `cfFormat`  
 Especifica o formato de dados da área de transferência a ser armazenado em cache ao criar o item OLE.  
  
 `lpFormatEtc`  
 Ponteiro para uma [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura usada se *renderizar* é **OLERENDER_FORMAT** ou **OLERENDER_DRAW**. Forneça um valor para esse parâmetro somente se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo `cfFormat`. Se você omitir esse parâmetro, os valores padrão são usados para os outros campos de **FORMATETC** estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O framework chama essa função do [COleInsertDialog::CreateItem](../../mfc/reference/coleinsertdialog-class.md#createitem) se o usuário escolher Okey na caixa de diálogo Inserir objeto quando criar do botão do arquivo está selecionada.  
  
 Para obter mais informações, consulte [OleCreateFromFile](http://msdn.microsoft.com/library/windows/desktop/ms690116), [OLERENDER](http://msdn.microsoft.com/library/windows/desktop/ms691507), e [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="createlinkfromclipboard"></a>COleClientItem::CreateLinkFromClipboard  
 Chame essa função para criar um item vinculado do conteúdo da área de transferência.  
  
```  
BOOL CreateLinkFromClipboard(
    OLERENDER render = OLERENDER_DRAW,  
    CLIPFORMAT cfFormat = 0,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *processar*  
 Sinalizador que especifica como o servidor processará o item OLE. Para obter os valores possíveis, consulte [OLERENDER](http://msdn.microsoft.com/library/windows/desktop/ms691507) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `cfFormat`  
 Especifica o formato de dados da área de transferência a ser armazenado em cache ao criar o item OLE.  
  
 `lpFormatEtc`  
 Ponteiro para uma [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura usada se *renderizar* é **OLERENDER_FORMAT** ou **OLERENDER_DRAW**. Forneça um valor para esse parâmetro somente se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo `cfFormat`. Se você omitir esse parâmetro, os valores padrão são usados para os outros campos de **FORMATETC** estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você normalmente chama essa função do manipulador de mensagens para o comando Colar vínculo no menu Editar. (O comando Colar vínculo está habilitado na implementação do padrão de [COleDocument](../../mfc/reference/coledocument-class.md) se a área de transferência contém um item OLE que pode ser vinculado.)  
  
 Para obter mais informações, consulte [OLERENDER](http://msdn.microsoft.com/library/windows/desktop/ms691507) e [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="createlinkfromdata"></a>COleClientItem::CreateLinkFromData  
 Chame essa função para criar um item vinculado de uma `COleDataObject` objeto.  
  
```  
BOOL CreateLinkFromData(
    COleDataObject* pDataObject,  
    OLERENDER render = OLERENDER_DRAW,  
    CLIPFORMAT cfFormat = 0,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDataObject`  
 Ponteiro para o [COleDataObject](../../mfc/reference/coledataobject-class.md) objeto do qual o item OLE deve ser criado.  
  
 *processar*  
 Sinalizador que especifica como o servidor processará o item OLE. Para obter os valores possíveis, consulte [OLERENDER](http://msdn.microsoft.com/library/windows/desktop/ms691507) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `cfFormat`  
 Especifica o formato de dados da área de transferência a ser armazenado em cache ao criar o item OLE.  
  
 `lpFormatEtc`  
 Ponteiro para uma [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura usada se *renderizar* é **OLERENDER_FORMAT** ou **OLERENDER_DRAW**. Forneça um valor para esse parâmetro somente se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo `cfFormat`. Se você omitir esse parâmetro, os valores padrão são usados para os outros campos de **FORMATETC** estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chamada durante uma operação de soltar quando o usuário indica um link deve ser criado. Ele também pode ser usado para lidar com o comando Editar colar. Ele é chamado pela estrutura em `COleClientItem::CreateLinkFromClipboard` e em [COlePasteSpecialDialog::CreateItem](../../mfc/reference/colepastespecialdialog-class.md#createitem) quando a opção Link foi selecionada.  
  
 Para obter mais informações, consulte [OleCreateLinkFromData](http://msdn.microsoft.com/library/windows/desktop/ms680731), [OLERENDER](http://msdn.microsoft.com/library/windows/desktop/ms691507), e [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="createlinkfromfile"></a>COleClientItem::CreateLinkFromFile  
 Chame essa função para criar um item vinculado do OLE de um arquivo.  
  
```  
BOOL CreateLinkFromFile(
    LPCTSTR lpszFileName,  
    OLERENDER render = OLERENDER_DRAW,  
    CLIPFORMAT cfFormat = 0,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFileName`  
 Ponteiro para o nome do arquivo do qual o item OLE a ser criado.  
  
 *processar*  
 Sinalizador que especifica como o servidor processará o item OLE. Para obter os valores possíveis, consulte [OLERENDER](http://msdn.microsoft.com/library/windows/desktop/ms691507) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `cfFormat`  
 Especifica o formato de dados da área de transferência a ser armazenado em cache ao criar o item OLE.  
  
 `lpFormatEtc`  
 Ponteiro para uma [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura usada se *renderizar* é **OLERENDER_FORMAT** ou **OLERENDER_DRAW**. Forneça um valor para esse parâmetro somente se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo `cfFormat`. Se você omitir esse parâmetro, os valores padrão são usados para os outros campos de **FORMATETC** estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O framework chama essa função se o usuário escolher Okey na caixa de diálogo Inserir objeto quando criar do botão do arquivo está selecionada e a caixa de seleção do Link está marcada. Ele é chamado de [COleInsertDialog::CreateItem](../../mfc/reference/coleinsertdialog-class.md#createitem).  
  
 Para obter mais informações, consulte [OleCreateLinkToFile](http://msdn.microsoft.com/library/windows/desktop/ms678434), [OLERENDER](http://msdn.microsoft.com/library/windows/desktop/ms691507), e [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="createnewitem"></a>COleClientItem::CreateNewItem  
 Chame essa função para criar um item inserido; Essa função inicia o aplicativo de servidor que permite ao usuário criar o item OLE.  
  
```  
BOOL CreateNewItem(
    REFCLSID clsid,  
    OLERENDER render = OLERENDER_DRAW,  
    CLIPFORMAT cfFormat = 0,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `clsid`  
 ID que identifica exclusivamente o tipo de item OLE para criar.  
  
 *processar*  
 Sinalizador que especifica como o servidor processará o item OLE. Para obter os valores possíveis, consulte [OLERENDER](http://msdn.microsoft.com/library/windows/desktop/ms691507) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `cfFormat`  
 Especifica o formato de dados da área de transferência a ser armazenado em cache ao criar o item OLE.  
  
 `lpFormatEtc`  
 Ponteiro para uma [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura usada se *renderizar* é **OLERENDER_FORMAT** ou **OLERENDER_DRAW**. Forneça um valor para esse parâmetro somente se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo `cfFormat`. Se você omitir esse parâmetro, os valores padrão são usados para os outros campos de **FORMATETC** estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O framework chama essa função se o usuário escolher Okey na caixa de diálogo Inserir objeto quando o botão Criar novo é selecionado.  
  
 Para obter mais informações, consulte [OleCreate](http://msdn.microsoft.com/library/windows/desktop/ms678409), [OLERENDER](http://msdn.microsoft.com/library/windows/desktop/ms691507), e [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="createstaticfromclipboard"></a>COleClientItem::CreateStaticFromClipboard  
 Chame essa função para criar um item estático do conteúdo da área de transferência.  
  
```  
BOOL CreateStaticFromClipboard(
    OLERENDER render = OLERENDER_DRAW,  
    CLIPFORMAT cfFormat = 0,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *processar*  
 Sinalizador que especifica como o servidor processará o item OLE. Para obter os valores possíveis, consulte [OLERENDER](http://msdn.microsoft.com/library/windows/desktop/ms691507) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `cfFormat`  
 Especifica o formato de dados da área de transferência a ser armazenado em cache ao criar o item OLE.  
  
 `lpFormatEtc`  
 Ponteiro para uma [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura usada se *renderizar* é **OLERENDER_FORMAT** ou **OLERENDER_DRAW**. Forneça um valor para esse parâmetro somente se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo `cfFormat`. Se você omitir esse parâmetro, os valores padrão são usados para os outros campos de **FORMATETC** estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um item estático contém os dados da apresentação, mas não os dados nativos; Consequentemente, ele não pode ser editado. Chamar essa função normalmente se o [CreateFromClipboard](#createfromclipboard) Falha na função de membro.  
  
 Para obter mais informações, consulte [OLERENDER](http://msdn.microsoft.com/library/windows/desktop/ms691507) e [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="createstaticfromdata"></a>COleClientItem::CreateStaticFromData  
 Chame essa função para criar um item estático de uma `COleDataObject` objeto.  
  
```  
BOOL CreateStaticFromData(
    COleDataObject* pDataObject,  
    OLERENDER render = OLERENDER_DRAW,  
    CLIPFORMAT cfFormat = 0,  
    LPFORMATETC lpFormatEtc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDataObject`  
 Ponteiro para o [COleDataObject](../../mfc/reference/coledataobject-class.md) objeto do qual o item OLE deve ser criado.  
  
 *processar*  
 Sinalizador que especifica como o servidor processará o item OLE. Para obter os valores possíveis, consulte [OLERENDER](http://msdn.microsoft.com/library/windows/desktop/ms691507) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `cfFormat`  
 Especifica o formato de dados da área de transferência a ser armazenado em cache ao criar o item OLE.  
  
 `lpFormatEtc`  
 Ponteiro para uma [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) estrutura usada se *renderizar* é **OLERENDER_FORMAT** ou **OLERENDER_DRAW**. Forneça um valor para esse parâmetro somente se você deseja especificar informações de formato adicionais além do formato da área de transferência especificado pelo `cfFormat`. Se você omitir esse parâmetro, os valores padrão são usados para os outros campos de **FORMATETC** estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um item estático contém os dados da apresentação, mas não os dados nativos; Consequentemente, ele não pode ser editado. Isso é basicamente o mesmo [CreateStaticFromClipboard](#createstaticfromclipboard) exceto que um item estático pode ser criado de um arbitrário `COleDataObject`, não apenas da área de transferência.  
  
 Usado em [COlePasteSpecialDialog::CreateItem](../../mfc/reference/colepastespecialdialog-class.md#createitem) quando estático é selecionado.  
  
 Para obter mais informações, consulte [OleCreateStaticFromData](http://msdn.microsoft.com/library/windows/desktop/ms687290), [OLERENDER](http://msdn.microsoft.com/library/windows/desktop/ms691507), e [FORMATETC](http://msdn.microsoft.com/library/windows/desktop/ms682177) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="deactivate"></a>COleClientItem::Deactivate  
 Chame essa função para desativar o item OLE e liberar os recursos associados.  
  
```  
void Deactivate();
```  
  
### <a name="remarks"></a>Comentários  
 Desativar um item OLE ativo in-loco normalmente quando o usuário clica com o mouse na área do cliente fora dos limites do item. Observe que desativar o item OLE descartará o estado de desfazer, tornando Impossível chamar o [ReactivateAndUndo](#reactivateandundo) função de membro.  
  
 Se seu aplicativo suporta desfazer, não chame `Deactivate`; em vez disso, chame [DeactivateUI](#deactivateui).  
  
 Para obter mais informações, consulte [IOleInPlaceObject::InPlaceDeactivate](http://msdn.microsoft.com/library/windows/desktop/ms679700) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="deactivateui"></a>COleClientItem::DeactivateUI  
 Chame essa função quando o usuário desativa um item que foi ativado no local.  
  
```  
void DeactivateUI();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função restaura a interface do usuário do aplicativo de contêiner para seu estado original, ocultando quaisquer menus e outros controles que foram criados para ativação no local.  
  
 Essa função libera as informações de estado de recuperação para o item. Que informações são mantidas para que [ReactivateAndUndo](#reactivateandundo) posteriormente pode ser usado para executar um comando Desfazer no aplicativo do servidor, no caso de comando de desfazer do contêiner é escolhido imediatamente após a desativação do item.  
  
 Para obter mais informações, consulte [IOleInPlaceObject::InPlaceDeactivate](http://msdn.microsoft.com/library/windows/desktop/ms679700) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="delete"></a>COleClientItem::Delete  
 Chame essa função para excluir o item OLE do documento contêiner.  
  
```  
void Delete(BOOL bAutoDelete = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bAutoDelete`  
 Especifica se o item deve ser removido do documento.  
  
### <a name="remarks"></a>Comentários  
 Essa função chama o [versão](#release) a função de membro, que por sua vez, exclui o objeto C++ para o item, removendo permanentemente o item OLE do documento. Se o item OLE é inserido, os dados nativos para o item são excluídos. Ele sempre fecha um servidor em execução; Portanto, se o item for uma conexão aberta, essa função fecha.  
  
##  <a name="dodragdrop"></a>COleClientItem::DoDragDrop  
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
 `lpItemRect`  
 Retângulo do item na tela em coordenadas do cliente (pixels).  
  
 `ptOffset`  
 O deslocamento do `lpItemRect` onde a posição do mouse estava na hora de arrastar.  
  
 `bIncludeLink`  
 Defina-o como **TRUE** se vincular dados devem ser copiados para a área de transferência. Defina-o como **FALSE** se o aplicativo de servidor não oferece suporte a links.  
  
 `dwEffects`  
 Determina os efeitos que permitirá que a fonte na operação de arrastar.  
  
 `lpRectStartDrag`  
 Ponteiro para o retângulo que define onde realmente começa a arrastar. Para obter mais informações, consulte a seção Comentários a seguir.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor `DROPEFFECT`. Se for `DROPEFFECT_MOVE`, os dados originais devem ser removidos.  
  
### <a name="remarks"></a>Comentários  
 A operação de arrastar e soltar não será iniciado imediatamente. Ele aguarda até que o cursor do mouse sai do retângulo especificado por `lpRectStartDrag` ou até que um número especificado de milissegundos tiver passado. Se `lpRectStartDrag` é **nulo**, o tamanho do retângulo é um pixel.  
  
 O tempo de atraso é especificado pela configuração da chave do registro. Você pode alterar o tempo de atraso chamando [CWinApp::WriteProfileString](../../mfc/reference/cwinapp-class.md#writeprofilestring) ou [CWinApp::WriteProfileInt](../../mfc/reference/cwinapp-class.md#writeprofileint). Se você não especificar o tempo de espera, é usado um valor padrão de 200 milissegundos. Tempo de atraso de arrastar é armazenado da seguinte maneira:  
  
-   Tempo de atraso de arraste do Windows NT é armazenado em HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\NT\CurrentVersion\IniFileMapping\win.ini\Windows\DragDelay.  
  
-   Tempo de atraso de arraste do Windows 3. x é armazenado em arquivos WIN. Arquivo INI, em [} seção Windows.  
  
-   Tempo de espera do Windows 95/98 arrastar é armazenado em uma versão em cache do WIN. INI.  
  
 Para obter mais informações sobre como arrastar informações de atraso são armazenadas no registro ou o. O arquivo INI, consulte [WriteProfileString](http://msdn.microsoft.com/library/windows/desktop/ms725504) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="doverb"></a>COleClientItem::DoVerb  
 Chamar `DoVerb` para executar o verbo especificado.  
  
```  
virtual BOOL DoVerb(
    LONG nVerb,  
    CView* pView,
    LPMSG lpMsg = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nVerb`  
 Especifica o verbo a ser executado. Ele pode incluir o seguinte:  
  
|Valor|Significado|Símbolo|  
|-----------|-------------|------------|  
|– 0|Verbo primário|`OLEIVERB_PRIMARY`|  
|– 1|Verbo secundário|(Nenhum)|  
|– 1|Item de exibição para edição|`OLEIVERB_SHOW`|  
|– 2|Editar item na janela separada|`OLEIVERB_OPEN`|  
|– 3|Ocultar item|`OLEIVERB_HIDE`|  
  
 O valor –&1; normalmente é um alias para outro verbo. Se não há suporte para a edição aberta, –&2; tem o mesmo efeito que –&1;. Para obter valores adicionais, consulte [IOleObject:: DoVerb](http://msdn.microsoft.com/library/windows/desktop/ms694508) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `pView`  
 Ponteiro para a janela de exibição; Isso é usado pelo servidor de ativação no local. Este parâmetro deve ser **nulo** se o aplicativo de contêiner não permitir a ativação no local.  
  
 `lpMsg`  
 Ponteiro para a mensagem que causou o item a ser ativado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o verbo foi executado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função chama o [ativar](#activate) função de membro para executar o verbo. Ele também captura exceções e exibe uma caixa de mensagem para o usuário se um for lançado.  
  
 Se o verbo primário é editar e zero é especificada no `nVerb` parâmetro, o aplicativo do servidor é iniciado para permitir que o item OLE a ser editada. Se o aplicativo de contêiner oferece suporte a ativação no local, a edição pode ser feita no lugar. Se o contêiner não dá suporte a ativação no local (ou se for especificado, o verbo Open), o servidor é iniciado em uma janela separada e edição pode ser feita lá. Normalmente, quando o usuário do aplicativo recipiente clica duas vezes no item OLE, o valor para o verbo primário no `nVerb` parâmetro determina qual ação pode levar o usuário. No entanto, se o servidor oferecer suporte a apenas uma ação, ele usa essa ação, independentemente de qual valor é especificado no `nVerb` parâmetro.  
  
##  <a name="draw"></a>COleClientItem::Draw  
 Chame essa função para desenhar o item OLE no retângulo delimitador especificado usando o contexto de dispositivo especificado.  
  
```  
BOOL Draw(
    CDC* pDC,  
    LPCRECT lpBounds,  
    DVASPECT nDrawAspect = (DVASPECT)-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Ponteiro para uma [CDC](../../mfc/reference/cdc-class.md) objeto usado para desenhar o item OLE.  
  
 `lpBounds`  
 Ponteiro para uma [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou `RECT` estrutura que define o retângulo delimitador para desenhar o item OLE (em unidades lógicas determinadas pelo contexto do dispositivo).  
  
 `nDrawAspect`  
 Especifica o aspecto da OLE item, ou seja, como deve ser exibido. Se `nDrawAspect` será –&1;, o último aspecto definido usando [SetDrawAspect](#setdrawaspect) é usado. Para obter mais informações sobre os valores possíveis para esse sinalizador, consulte [SetDrawAspect](#setdrawaspect).  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A função pode usar a representação de metarquivo do item OLE criado pelo [OnDraw](../../mfc/reference/coleserveritem-class.md#ondraw) função de membro `COleServerItem`.  
  
 Normalmente você usa **desenhar** para exibição na tela, transmitindo o contexto de dispositivo de tela como `pDC`. Nesse caso, você precisa especificar somente os primeiros dois parâmetros.  
  
 O `lpBounds` parâmetro identifica o retângulo no contexto do dispositivo de destino (em relação ao modo de mapeamento atual). O processamento pode envolver a dimensionar a imagem e pode ser usado por aplicativos de contêiner para impor uma exibição que pode ser dimensionado entre a exibição mostrada e a imagem impressa final.  
  
 Para obter mais informações, consulte [IViewObject::Draw](http://msdn.microsoft.com/library/windows/desktop/ms688655) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getactiveview"></a>COleClientItem::GetActiveView  
 Retorna o modo no qual o item está ativado no local.  
  
```  
CView* GetActiveView() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o modo de exibição; Caso contrário, **nulo** se o item não está ativado no local.  
  
##  <a name="getcachedextent"></a>COleClientItem::GetCachedExtent  
 Chame essa função para recuperar o tamanho do item OLE.  
  
```  
BOOL GetCachedExtent(
    LPSIZE lpSize,  
    DVASPECT nDrawAspect = (DVASPECT)-1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpSize`  
 Ponteiro para uma **tamanho** estrutura ou um [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto que receberá as informações de tamanho.  
  
 `nDrawAspect`  
 Especifica o aspecto do item OLE cujos limites devem ser recuperadas. Para obter valores possíveis, consulte [SetDrawAspect](#setdrawaspect).  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; 0 se o item OLE está em branco.  
  
### <a name="remarks"></a>Comentários  
 Essa função fornece as mesmas informações que [GetExtent](#getextent). No entanto, você pode chamar `GetCachedExtent` para obter informações de extensão durante o processamento dos outros manipuladores OLE, como [OnChange](#onchange). As dimensões são em `MM_HIMETRIC` unidades.  
  
 Isso é possível porque `GetCachedExtent` usa o [IViewObject2](http://msdn.microsoft.com/library/windows/desktop/ms691318) interface em vez de usar o [IOleObject](http://msdn.microsoft.com/library/windows/desktop/dd542709) interface para obter a extensão deste item. O **IViewObject2** objeto COM armazena em cache as informações de extensão usadas na chamada anterior a [IViewObject::Draw](http://msdn.microsoft.com/library/windows/desktop/ms688655).  
  
 Para obter mais informações, consulte [IViewObject2::GetExtent](http://msdn.microsoft.com/library/windows/desktop/ms684032) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getclassid"></a>COleClientItem::GetClassID  
 Retorna a ID de classe do item na memória apontada por `pClassID`.  
  
```  
void GetClassID(CLSID* pClassID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pClassID`  
 Ponteiro para um identificador de tipo [CLSID](http://msdn.microsoft.com/library/windows/desktop/ms691424) para recuperar a ID de classe. Para obter informações sobre **CLSID**, consulte o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 A ID de classe é um número de 128 bits que identifica exclusivamente o aplicativo que edita o item.  
  
 Para obter mais informações, consulte [IPersist::GetClassID](http://msdn.microsoft.com/library/windows/desktop/ms688664) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getclipboarddata"></a>COleClientItem::GetClipboardData  
 Chame essa função para obter um `COleDataSource` objeto que contém todos os dados devem ser colocados na área de transferência por uma chamada para o [CopyToClipboard](#copytoclipboard) função de membro.  
  
```  
void GetClipboardData(
    COleDataSource* pDataSource,  
    BOOL bIncludeLink = FALSE,  
    LPPOINT lpOffset = NULL,  
    LPSIZE lpSize = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDataSource`  
 Ponteiro para uma [COleDataSource](../../mfc/reference/coledatasource-class.md) objeto que receberá os dados contidos no item OLE.  
  
 `bIncludeLink`  
 **TRUE** se vincular dados devem ser incluídas; caso contrário **FALSE**.  
  
 `lpOffset`  
 O deslocamento do cursor do mouse em relação à origem do objeto em pixels.  
  
 `lpSize`  
 O tamanho do objeto em pixels.  
  
### <a name="remarks"></a>Comentários  
 `GetClipboardData`é chamado como a implementação padrão de [OnGetClipboardData](#ongetclipboarddata). Substituir `OnGetClipboardData` somente se você desejar oferecer formatos de dados além daqueles oferecidos pelo `CopyToClipboard`. Coloque esses formatos no `COleDataSource` objeto antes ou depois de chamar `CopyToClipboard`e, em seguida, passar o `COleDataSource` o objeto para o [COleDataSource::SetClipboard](../../mfc/reference/coledatasource-class.md#setclipboard) função. Por exemplo, se desejar que a posição do item OLE no documento de contêiner para acompanhá-lo na área de transferência, você deve definir seu próprio formato para transmitir essas informações e colocá-lo no `COleDataSource` antes de chamar `CopyToClipboard`.  
  
##  <a name="getdocument"></a>COleClientItem::GetDocument  
 Chame essa função para obter um ponteiro para o documento que contém o item OLE.  
  
```  
COleDocument* GetDocument() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o documento que contém o item OLE. **NULO** se o item não for parte de um documento.  
  
### <a name="remarks"></a>Comentários  
 Permite o acesso a esse ponteiro o `COleDocument` objeto passado como um argumento para o `COleClientItem` construtor.  
  
##  <a name="getdrawaspect"></a>COleClientItem::GetDrawAspect  
 Chamar o `GetDrawAspect` a função de membro para determinar o atual "aspecto" ou o modo de exibição do item.  
  
```  
DVASPECT GetDrawAspect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor a partir de `DVASPECT` enumeração, cujos valores são listados na referência para [SetDrawAspect](#setdrawaspect).  
  
### <a name="remarks"></a>Comentários  
 O aspecto Especifica como o item a ser processado.  
  
##  <a name="getextent"></a>COleClientItem::GetExtent  
 Chame essa função para recuperar o tamanho do item OLE.  
  
```  
BOOL GetExtent(
    LPSIZE lpSize,  
    DVASPECT nDrawAspect = (DVASPECT)- 1);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpSize`  
 Ponteiro para uma **tamanho** estrutura ou um `CSize` objeto que receberá as informações de tamanho.  
  
 `nDrawAspect`  
 Especifica o aspecto do item OLE cujos limites devem ser recuperadas. Para obter valores possíveis, consulte [SetDrawAspect](#setdrawaspect).  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; 0 se o item OLE está em branco.  
  
### <a name="remarks"></a>Comentários  
 Se o aplicativo de servidor foi escrito usando a biblioteca Microsoft Foundation Class, essa função faz com que o [OnGetExtent](../../mfc/reference/coleserveritem-class.md#ongetextent) a função de membro de correspondente `COleServerItem` objeto a ser chamado. Observe que o tamanho recuperado pode diferir do tamanho definidas por último o [SetExtent](#setextent) função de membro; o tamanho especificado pelo `SetExtent` é tratado como uma sugestão. As dimensões são em `MM_HIMETRIC` unidades.  
  
> [!NOTE]
>  Não chame `GetExtent` durante o processamento de um manipulador de OLE, como [OnChange](#onchange). Chamar [GetCachedExtent](#getcachedextent) em vez disso.  
  
 Para obter mais informações, consulte [IOleObject::GetExtent](http://msdn.microsoft.com/library/windows/desktop/ms692325) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="geticonfromregistry"></a>COleClientItem::GetIconFromRegistry  
 Chame essa função de membro para recuperar um identificador para um recurso de ícone associado ao servidor de um CLSID particular.  
  
```  
HICON GetIconFromRegistry() const;  
  
static HICON GetIconFromRegistry(CLSID& clsid);
```  
  
### <a name="parameters"></a>Parâmetros  
 `clsid`  
 Uma referência para o CLSID para o servidor associado ao ícone.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador válido para o recurso de ícone, ou **nulo** se o ícone do servidor ou um ícone padrão, não pode ser encontrado.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro não será iniciar o servidor ou obtenha um ícone dinamicamente, mesmo se o servidor já está em execução. Em vez disso, essa função membro abre imagem executável do servidor e recupera o ícone estático associado ao servidor que foi registrada.  
  
##  <a name="geticonicmetafile"></a>COleClientItem::GetIconicMetafile  
 Recupera o metarquivo usado para desenhar o ícone do item.  
  
```  
HGLOBAL GetIconicMetafile();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o metarquivo se for bem-sucedida; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Se não houver nenhum ícone atual, um ícone padrão será retornado. Isso é chamado automaticamente pelas caixas de diálogo do MFC/OLE e normalmente não é chamado diretamente.  
  
 Essa função também chama [SetIconicMetafile](#seticonicmetafile) para armazenar em cache o metarquivo para uso posterior.  
  
##  <a name="getinplacewindow"></a>COleClientItem::GetInPlaceWindow  
 Chamar o `GetInPlaceWindow` a função de membro para obter um ponteiro para a janela na qual o item foi aberto para edição no local.  
  
```  
CWnd* GetInPlaceWindow();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a janela de edição do item no local; **Nulo** se o item não está ativo ou se seu servidor não está disponível.  
  
### <a name="remarks"></a>Comentários  
 Essa função deve ser chamada somente para itens que estão ativos no local.  
  
##  <a name="getitemstate"></a>COleClientItem::GetItemState  
 Chame essa função para obter o estado atual do item OLE.  
  
```  
UINT GetItemState() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A **COleClientItem::ItemState** enumerados valor, que pode ser um dos seguintes: `emptyState`, **loadedState**, `openState`, `activeState`, `activeUIState`. Para obter informações sobre esses estados, consulte o artigo [contêineres: Estados de Item do cliente](../../mfc/containers-client-item-states.md).  
  
### <a name="remarks"></a>Comentários  
 Para ser notificado quando o estado do item OLE é alterado, use o [OnChange](#onchange) função de membro.  
  
 Para obter mais informações, consulte o artigo [contêineres: Estados de Item do cliente](../../mfc/containers-client-item-states.md).  
  
##  <a name="getlaststatus"></a>COleClientItem::GetLastStatus  
 Retorna o código de status da última operação OLE.  
  
```  
SCODE GetLastStatus() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor `SCODE`.  
  
### <a name="remarks"></a>Comentários  
 Membro funções que retornam uma **BOOL** valor **FALSE**, ou outro membro funções que retornam **nulo**, `GetLastStatus` retorna falha informações mais detalhadas. Lembre-se de que a maioria das funções de membro OLE lançam exceções para erros mais graves. As informações específicas sobre a interpretação de `SCODE` depende da chamada OLE subjacente que retornado pela última um `SCODE` valor.  
  
 Para obter mais informações sobre `SCODE`, consulte [estrutura de códigos de erro COM](http://msdn.microsoft.com/library/windows/desktop/ms690088) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] documentação.  
  
##  <a name="getlinkupdateoptions"></a>COleClientItem::GetLinkUpdateOptions  
 Chame essa função para obter o valor atual da opção de atualização de link para o item OLE.  
  
```  
OLEUPDATE GetLinkUpdateOptions();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos seguintes valores:  
  
- `OLEUPDATE_ALWAYS`Atualize o item vinculado sempre que possível. Essa opção oferece suporte ao botão de opção atualização automática de link na caixa de diálogo Links.  
  
- `OLEUPDATE_ONCALL`Atualizar o item vinculado somente na solicitação do aplicativo de contêiner (quando o [UpdateLink](#updatelink) é chamada de função de membro). Essa opção oferece suporte ao botão de opção Atualização Manual de link na caixa de diálogo Links.  
  
### <a name="remarks"></a>Comentários  
 Esta é uma operação avançada.  
  
 Essa função é chamada automaticamente pelo [COleLinksDialog](../../mfc/reference/colelinksdialog-class.md) classe.  
  
 Para obter mais informações, consulte [IOleLink::GetUpdateOptions](http://msdn.microsoft.com/library/windows/desktop/ms680100) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="gettype"></a>COleClientItem::GetType  
 Chame essa função para determinar se o item OLE incorporado ou vinculado ou static.  
  
```  
OLE_OBJTYPE GetType() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um inteiro não assinado com um dos seguintes valores:  
  
- `OT_LINK`O item OLE é um link.  
  
- `OT_EMBEDDED`O item OLE é incorporado.  
  
- `OT_STATIC`O item OLE é estático, ou seja, ele contém apenas apresentação, dados não nativo e, portanto, não pode ser editado.  
  
##  <a name="getusertype"></a>COleClientItem::GetUserType  
 Chame essa função para obter a cadeia de caracteres visíveis ao usuário que descreve o tipo do item OLE, como "Documento do Word".  
  
```  
void GetUserType(
    USERCLASSTYPE nUserClassType,  
    CString& rString);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nUserClassType*  
 Um valor que indica a variação desejada da cadeia de caracteres que descreve o tipo do item OLE. Isso pode ter um dos seguintes valores:  
  
- `USERCLASSTYPE_FULL`O nome de tipo completo exibido para o usuário.  
  
- `USERCLASSTYPE_SHORT`Um nome curto (no máximo&15; caracteres) para uso em menus pop-up e a caixa de diálogo Editar vínculos.  
  
- `USERCLASSTYPE_APPNAME`Nome do aplicativo atendendo a classe.  
  
 `rString`  
 Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto ao qual a cadeia de caracteres que descreve o tipo do item OLE a ser retornado.  
  
### <a name="remarks"></a>Comentários  
 Isso geralmente é a entrada do banco de dados de registro do sistema.  
  
 Se o nome de tipo completo for solicitada, mas não está disponível, o nome curto é usado em vez disso. Se nenhuma entrada para o tipo de item OLE foi encontrada no banco de dados de registro, ou se não houver nenhum tipo de usuário registrado para o tipo de item OLE, em seguida, o tipo de usuário atualmente armazenados no item OLE é usado. Se esse nome de tipo de usuário é uma cadeia de caracteres vazia, "Objeto desconhecido" é usado.  
  
 Para obter mais informações, consulte [IOleObject::GetUserType](http://msdn.microsoft.com/library/windows/desktop/ms688643) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="isinplaceactive"></a>COleClientItem::IsInPlaceActive  
 Chame essa função para ver se o item OLE está ativo no local.  
  
```  
BOOL IsInPlaceActive() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item OLE está ativo no local; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 É comum para executar lógica diferente dependendo se o item está sendo editado no local. A função verifica se o estado do item atual for igual ao `activeState` ou `activeUIState`.  
  
##  <a name="islinkuptodate"></a>COleClientItem::IsLinkUpToDate  
 Chame essa função para ver se o item OLE é atualizado.  
  
```  
BOOL IsLinkUpToDate() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item OLE é atualizado; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Um item vinculado pode ser desatualizado se seu documento de origem tiver sido atualizado. Um item incorporado que contém links dentro da mesma forma pode se tornar desatualizado. A função faz uma verificação recursiva do item OLE. Observe que a determinar se um item OLE está desatualizado pode ser mais caro que realmente executar uma atualização.  
  
 Isso é chamado automaticamente pelo [COleLinksDialog](../../mfc/reference/colelinksdialog-class.md) implementação.  
  
 Para obter mais informações, consulte [IOleObject::IsUpToDate](http://msdn.microsoft.com/library/windows/desktop/ms686624) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="ismodified"></a>COleClientItem::IsModified  
 Chame essa função para ver se o item OLE está sujo (modificado desde que foi salvo pela última vez).  
  
```  
BOOL IsModified() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item OLE está sujo; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [IPersistStorage::IsDirty](http://msdn.microsoft.com/library/windows/desktop/ms683910) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="isopen"></a>COleClientItem::IsOpen  
 Chame essa função para ver se o item OLE é aberto. Isto é, é aberto em uma instância do aplicativo de servidor executado em uma janela separada.  
  
```  
BOOL IsOpen() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item OLE está aberto. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Ele é usado para determinar quando desenhar o objeto com um padrão de hachura. Um objeto deve ter um padrão de hachura desenhado na parte superior do objeto. Você pode usar um [CRectTracker](../../mfc/reference/crecttracker-class.md) objeto para fazer isso.  
  
##  <a name="isrunning"></a>COleClientItem::IsRunning  
 Chame essa função para ver se o item OLE está em execução; ou seja, se o item é carregado e executado no aplicativo do servidor.  
  
```  
BOOL IsRunning() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item OLE está sendo executado. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [OleIsRunning](http://msdn.microsoft.com/library/windows/desktop/ms688705) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="onactivate"></a>COleClientItem::OnActivate  
 Chamado pela estrutura para notificar o item que simplesmente foi ativado no local.  
  
```  
virtual void OnActivate();
```  
  
### <a name="remarks"></a>Comentários  
 Observe que essa função é chamada para indicar que o servidor está em execução, não para indicar que a interface do usuário foi instalada no aplicativo de contêiner. Neste ponto, o objeto não tem uma interface de usuário ativas (não é `activeUIState`). Ele não tiver instalado os seus menus ou a barra de ferramentas. O [OnActivateUI](#onactivateui) função de membro é chamada quando isso acontece.  
  
 A implementação padrão chama o [OnChange](#onchange) a função de membro com **OLE_CHANGEDSTATE** como um parâmetro. Substitua essa função para realizar processamento personalizado quando um item se torna ativo no local.  
  
##  <a name="onactivateui"></a>COleClientItem::OnActivateUI  
 O framework chama `OnActivateUI` quando o objeto entrou no estado ativo de interface do usuário.  
  
```  
virtual void OnActivateUI();
```  
  
### <a name="remarks"></a>Comentários  
 O objeto agora instalado sua barra de ferramentas e menus.  
  
 O servidor se lembra a implementação padrão `HWND` posteriormente **GetServerWindow** chamadas.  
  
##  <a name="onchange"></a>COleClientItem::OnChange  
 Chamado pela estrutura quando o usuário modifica, salva ou fecha o item OLE.  
  
```  
virtual void OnChange(
    OLE_NOTIFICATION nCode,  
    DWORD dwParam);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nCode`  
 O motivo pelo qual o servidor alterou esse item. Ele pode ter um dos seguintes valores:  
  
- `OLE_CHANGED`Aparência do item OLE foi alterado.  
  
- `OLE_SAVED`O item OLE foi salvo.  
  
- `OLE_CLOSED`O item OLE foi fechado.  
  
- `OLE_CHANGED_STATE`O item OLE foi alterado de um estado para outro.  
  
 `dwParam`  
 Se `nCode` é `OLE_SAVED` ou `OLE_CLOSED`, esse parâmetro não for usado. Se `nCode` é `OLE_CHANGED`, esse parâmetro especifica o aspecto do item OLE que foi alterado. Para obter valores possíveis, consulte o `dwParam` parâmetro do [COleClientItem::Draw](#draw). Se `nCode` é `OLE_CHANGED_STATE`, este parâmetro é um **COleClientItem::ItemState** valor enumerado e descreve o estado que está sendo inserido. Ele pode ter um dos seguintes valores: `emptyState`, **loadedState**, `openState`, `activeState`, ou `activeUIState`.  
  
### <a name="remarks"></a>Comentários  
 (Se o aplicativo do servidor é escrito usando a biblioteca Microsoft Foundation Class, essa função é chamada em resposta ao `Notify` funções de membro `COleServerDoc` ou `COleServerItem`.) A implementação padrão marca documento contêiner como modificado se `nCode` é `OLE_CHANGED` ou `OLE_SAVED`.  
  
 Para `OLE_CHANGED_STATE`, o estado atual retornado de [GetItemState](#getitemstate) ainda será o estado antigo, que significa que o estado atual antes dessa alteração de estado.  
  
 Substitua essa função para responder a alterações no estado do item OLE. Normalmente você atualizar a aparência do item ao invalidar a área na qual o item é exibido. Chame a implementação da classe base no início de sua substituição.  
  
##  <a name="onchangeitemposition"></a>COleClientItem::OnChangeItemPosition  
 Chamado pela estrutura para notificar o contêiner de extensão do item OLE foi alterado durante a ativação no local.  
  
```  
virtual BOOL OnChangeItemPosition(const CRect& rectPos);
```  
  
### <a name="parameters"></a>Parâmetros  
 *rectPos*  
 Indica a posição do item com relação à área do cliente do aplicativo de contêiner.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a posição do item é alterada com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão determina o novo retângulo visível do item OLE e chamadas [SetItemRects](#setitemrects) com os novos valores. A implementação padrão calcula o retângulo visível para o item e passa essas informações para o servidor.  
  
 Substitua essa função para aplicar regras especiais para a operação de redimensionamento/movimentação. Se o aplicativo é escrito no MFC, essa chamada ocorre porque o servidor chamado [COleServerDoc::RequestPositionChange](../../mfc/reference/coleserverdoc-class.md#requestpositionchange).  
  
##  <a name="ondeactivate"></a>COleClientItem::OnDeactivate  
 Chamado pela estrutura quando o item OLE faz a transição de estado ativo no local ( `activeState`) para o estado carregado, o que significa que ele é desativado após uma ativação no local.  
  
```  
virtual void OnDeactivate();
```  
  
### <a name="remarks"></a>Comentários  
 Observe que essa função é chamada para indicar que o item OLE é fechado, não que sua interface do usuário foi removida do aplicativo de contêiner. Quando isso acontece, o [OnDeactivateUI](#ondeactivateui) é chamada de função de membro.  
  
 A implementação padrão chama o [OnChange](#onchange) a função de membro com **OLE_CHANGEDSTATE** como um parâmetro. Substitua essa função para realizar processamento personalizado quando um item ativo no local é desativado. Por exemplo, se o comando Desfazer suporte em seu aplicativo de contêiner, você pode substituir essa função para descartar o estado de desfazer, indicando que a última operação realizada no item OLE não pode ser desfeita depois que o item está desativado.  
  
##  <a name="ondeactivateandundo"></a>COleClientItem::OnDeactivateAndUndo  
 Chamado pela estrutura quando o usuário chama o comando Desfazer após ativar o item OLE no local.  
  
```  
virtual void OnDeactivateAndUndo();
```  
  
### <a name="remarks"></a>Comentários  
 As chamadas de implementação padrão [DeactivateUI](#deactivateui) para desativar a interface do usuário do servidor. Substitua essa função se você estiver implementando o comando Desfazer em seu aplicativo de contêiner. Na sua substituição, chame a versão da classe base da função e, em seguida, desfazer o último comando executado em seu aplicativo.  
  
 Para obter mais informações, consulte [IOleInPlaceSite::DeactivateAndUndo](http://msdn.microsoft.com/library/windows/desktop/ms683743) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="ondeactivateui"></a>COleClientItem::OnDeactivateUI  
 Chamado quando o usuário desativa um item que foi ativado no local.  
  
```  
virtual void OnDeactivateUI(BOOL bUndoable);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bUndoable`  
 Especifica se as alterações de edição não pode ser desfeitas.  
  
### <a name="remarks"></a>Comentários  
 Essa função restaura a interface do usuário do aplicativo de contêiner para seu estado original, ocultando quaisquer menus e outros controles que foram criados para ativação no local.  
  
 Se `bUndoable` é **FALSE**, o contêiner deve desabilitar o comando Desfazer, não é possível refazer em vigor descartar o estado de desfazer do contêiner, pois indica que a última operação executada pelo servidor.  
  
##  <a name="ondiscardundostate"></a>COleClientItem::OnDiscardUndoState  
 Chamado pela estrutura quando o usuário executa uma ação que descarta o estado de desfazer ao editar o item OLE.  
  
```  
virtual void OnDiscardUndoState();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não faz nada. Substitua essa função se você estiver implementando o comando Desfazer em seu aplicativo de contêiner. Em sua substituição, descarte o estado de desfazer do aplicativo de contêiner.  
  
 Se o servidor foi escrito com a biblioteca Microsoft Foundation Class, o servidor pode causar essa função a ser chamada chamando [COleServerDoc::DiscardUndoState](../../mfc/reference/coleserverdoc-class.md#discardundostate).  
  
 Para obter mais informações, consulte [IOleInPlaceSite::DiscardUndoState](http://msdn.microsoft.com/library/windows/desktop/ms688642) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="ongetclipboarddata"></a>COleClientItem::OnGetClipboardData  
 Chamado pela estrutura para obter um `COleDataSource` objeto que contém todos os dados são colocados na área de transferência por uma chamada para o [CopyToClipboard](#copytoclipboard) ou [DoDragDrop](#dodragdrop) função de membro.  
  
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
 Ponteiro para o deslocamento do cursor do mouse em relação à origem do objeto em pixels.  
  
 `lpSize`  
 Ponteiro para o tamanho do objeto em pixels.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [COleDataSource](../../mfc/reference/coledatasource-class.md) objeto que contém os dados da área de transferência.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função chama [GetClipboardData](#getclipboarddata).  
  
##  <a name="ongetcliprect"></a>COleClientItem::OnGetClipRect  
 O framework chama o `OnGetClipRect` a função de membro para obter as coordenadas do retângulo de corte do item que está sendo editado no local.  
  
```  
virtual void OnGetClipRect(CRect& rClipRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 *rClipRect*  
 Ponteiro para um objeto da classe [CRect](../../atl-mfc-shared/reference/crect-class.md) que conterá as coordenadas do retângulo de corte do item.  
  
### <a name="remarks"></a>Comentários  
 Coordenadas são em pixels com relação à área do cliente da janela do aplicativo recipiente.  
  
 A implementação padrão simplesmente retorna o retângulo do cliente do modo de exibição em que o item está ativo no local.  
  
##  <a name="ongetitemposition"></a>COleClientItem::OnGetItemPosition  
 O framework chama o `OnGetItemPosition` a função de membro para obter as coordenadas do item que está sendo editado no local.  
  
```  
virtual void OnGetItemPosition(CRect& rPosition);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rPosition`  
 Referência para o [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que contém coordenadas de posição do item.  
  
### <a name="remarks"></a>Comentários  
 Coordenadas são em pixels com relação à área do cliente da janela do aplicativo recipiente.  
  
 A implementação padrão dessa função não faz nada. Os aplicativos que oferecem suporte à edição in-loco exigem sua implementação.  
  
##  <a name="ongetwindowcontext"></a>COleClientItem::OnGetWindowContext  
 Chamado pela estrutura quando um item é ativado em vigor.  
  
```  
virtual BOOL OnGetWindowContext(
    CFrameWnd** ppMainFrame,  
    CFrameWnd** ppDocFrame,  
    LPOLEINPLACEFRAMEINFO lpFrameInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppMainFrame`  
 Ponteiro para um ponteiro para a janela do quadro principal.  
  
 `ppDocFrame`  
 Ponteiro para um ponteiro para a janela de quadro do documento.  
  
 `lpFrameInfo`  
 Ponteiro para uma [OLEINPLACEFRAMEINFO](http://msdn.microsoft.com/library/windows/desktop/ms693737) estrutura que receberá informações de janela de quadro.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função é usada para recuperar informações sobre a janela pai do item OLE.  
  
 Se o contêiner for um aplicativo MDI, a implementação padrão retorna um ponteiro para o [CMDIFrameWnd](../../mfc/reference/cmdiframewnd-class.md) objeto `ppMainFrame` e um ponteiro para o ativo [CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md) o objeto no `ppDocFrame`. Se o contêiner for um aplicativo SDI, a implementação padrão retorna um ponteiro para o [CFrameWnd](../../mfc/reference/cframewnd-class.md) objeto `ppMainFrame` e retorna **nulo** em `ppDocFrame`. A implementação padrão também preenche os membros de `lpFrameInfo`.  
  
 Substituir essa função somente se a implementação padrão não atenderem às seu aplicativo; Por exemplo, se seu aplicativo tiver um paradigma de interface do usuário difere SDI ou MDI. Isso é uma avançada substituível.  
  
 Para obter mais informações, consulte [IOleInPlaceSite::GetWindowContext](http://msdn.microsoft.com/library/windows/desktop/ms694366) e [OLEINPLACEFRAMEINFO](http://msdn.microsoft.com/library/windows/desktop/ms693737) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="oninsertmenus"></a>COleClientItem::OnInsertMenus  
 Chamado pela estrutura durante a ativação no local para inserir os menus do aplicativo de contêiner em um menu vazio.  
  
```  
virtual void OnInsertMenus(
    CMenu* pMenuShared,  
    LPOLEMENUGROUPWIDTHS lpMenuWidths);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pMenuShared`  
 Aponta para um menu vazio.  
  
 `lpMenuWidths`  
 Aponta para uma matriz de seis **longo** valores indicando quantos menus estão em cada um dos seguintes grupos de menu: arquivo, editar, contêiner, objeto, a janela Ajuda. O aplicativo de contêiner é responsável por grupos de menu Arquivo, contêiner e janela, correspondentes aos elementos 0, 2 e 4 dessa matriz.  
  
### <a name="remarks"></a>Comentários  
 Esse menu é então passado para o servidor, que insere seus próprios menus, criando um menu composto. Essa função pode ser chamada repetidamente para criar vários menus compostos.  
  
 A implementação padrão insere `pMenuShared` os menus de contêiner no local; ou seja, os grupos de arquivos, contêiner e janela do menu. [CDocTemplate::SetContainerInfo](../../mfc/reference/cdoctemplate-class.md#setcontainerinfo) é usado para definir esse recurso do menu. A implementação padrão também atribui os valores apropriados para elementos 0, 2 e 4 em `lpMenuWidths`, dependendo do recurso de menu. Substituir essa função se a implementação padrão não é apropriada para seu aplicativo. Por exemplo, se seu aplicativo não usar modelos de documento para associar recursos com tipos de documento. Se você substituir essa função, você também deve substituir [OnSetMenu](#onsetmenu) e [OnRemoveMenus](#onremovemenus). Isso é uma avançada substituível.  
  
 Para obter mais informações, consulte [IOleInPlaceFrame::InsertMenus](http://msdn.microsoft.com/library/windows/desktop/ms683987) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="onremovemenus"></a>COleClientItem::OnRemoveMenus  
 Chamado pela estrutura para remover os menus do contêiner no menu composto especificado quando termina de ativação no local.  
  
```  
virtual void OnRemoveMenus(CMenu* pMenuShared);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pMenuShared`  
 Aponta para o menu composto construído por chamadas para o [OnInsertMenus](#oninsertmenus) função de membro.  
  
### <a name="remarks"></a>Comentários  
 Remove a implementação padrão de `pMenuShared` os menus de contêiner no local, que é, os grupos de arquivos, contêiner e janela do menu. Substituir essa função se a implementação padrão não é apropriada para seu aplicativo. Por exemplo, se seu aplicativo não usar modelos de documento para associar recursos com tipos de documento. Se você substituir essa função, você provavelmente deve substituir [OnInsertMenus](#oninsertmenus) e [OnSetMenu](#onsetmenu) também. Isso é uma avançada substituível.  
  
 Os submenus em `pMenuShared` pode ser compartilhado por mais de um menu composto se o servidor tiver sido chamado repetidamente `OnInsertMenus`. Portanto, você não deve excluir qualquer submenus em seu substituto do `OnRemoveMenus`; você só deve desanexá-los.  
  
 Para obter mais informações, consulte [IOleInPlaceFrame::RemoveMenus](http://msdn.microsoft.com/library/windows/desktop/ms688685) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="onscrollby"></a>COleClientItem::OnScrollBy  
 Chamado pela estrutura para rolar o item OLE em resposta às solicitações do servidor.  
  
```  
virtual BOOL OnScrollBy(CSize sizeExtent);
```  
  
### <a name="parameters"></a>Parâmetros  
 *sizeExtent*  
 Especifica a distância, em pixels, para rolar em x e y direções.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item foi rolado; 0 se o item não pode ser rolado.  
  
### <a name="remarks"></a>Comentários  
 Por exemplo, se o item OLE é parcialmente visível e o usuário move fora da região visível ao executar a edição in-loco, essa função é chamada para manter o cursor visíveis. A implementação padrão não faz nada. Substitua essa função para rolar o item pelo valor especificado. Observe que, como resultado de rolagem, pode alterar a parte visível do item OLE. Chamar [SetItemRects](#setitemrects) para atualizar o retângulo visível do item.  
  
 Para obter mais informações, consulte [IOleInPlaceSite::Scroll](http://msdn.microsoft.com/library/windows/desktop/ms690291) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="onsetmenu"></a>COleClientItem::OnSetMenu  
 Chamado pela estrutura duas vezes quando a ativação no local começa e termina; na primeira vez para instalar o menu composto e a segunda vez (com `holemenu` igual a **nulo**) para removê-lo.  
  
```  
virtual void OnSetMenu(
    CMenu* pMenuShared,  
    HOLEMENU holemenu,  
    HWND hwndActiveObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pMenuShared`  
 Ponteiro para o menu composto construído por chamadas para o [OnInsertMenus](#oninsertmenus) função de membro e o `InsertMenu` função.  
  
 `holemenu`  
 Identificador para o descritor de menu retornado pelo **OleCreateMenuDescriptor** função, ou **nulo** se o código de expedição deve ser removido.  
  
 *hwndActiveObject*  
 Identificador para a janela de edição do item OLE. Esta é a janela que irão receber comandos de edição de OLE.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão instala ou remove o menu composto e, em seguida, chama o [OleSetMenuDescriptor](http://msdn.microsoft.com/library/windows/desktop/ms692831) função para instalar ou remover o código de expedição. Substitua essa função se a implementação padrão não é apropriada para seu aplicativo. Se você substituir essa função, você provavelmente deve substituir [OnInsertMenus](#oninsertmenus) e [OnRemoveMenus](#onremovemenus) também. Isso é uma avançada substituível.  
  
 Para obter mais informações, consulte [OleCreateMenuDescriptor](http://msdn.microsoft.com/library/windows/desktop/ms691415), [OleSetMenuDescriptor](http://msdn.microsoft.com/library/windows/desktop/ms692831), e [IOleInPlaceFrame::SetMenu](http://msdn.microsoft.com/library/windows/desktop/ms693713) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="onshowcontrolbars"></a>COleClientItem::OnShowControlBars  
 Chamado pela estrutura para mostrar e ocultar as barras de controle do aplicativo de contêiner.  
  
```  
virtual BOOL OnShowControlBars(
    CFrameWnd* pFrameWnd,  
    BOOL bShow);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFrameWnd`  
 Ponteiro para a janela do quadro do aplicativo de contêiner. Isso pode ser uma janela do quadro principal ou em uma janela de filho MDI.  
  
 `bShow`  
 Especifica se as barras de controle devem ser mostrados ou ocultados.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a chamada de função faz com que uma alteração no estado de barras de controle. 0 se a chamada não faz qualquer alteração ou `pFrameWnd` não aponta para a janela do quadro do contêiner.  
  
### <a name="remarks"></a>Comentários  
 Esta função retorna 0 se as barras de controle já estiverem no estado especificado por *bMostrar.* Isso poderia ocorrer, por exemplo, se as barras de controle são ocultas e `bShow` é **FALSE**.  
  
 A implementação padrão remove a barra de ferramentas da janela de quadro de nível superior.  
  
##  <a name="onshowitem"></a>COleClientItem::OnShowItem  
 Chamado pela estrutura para exibir o item OLE, torná-lo totalmente visível durante a edição.  
  
```  
virtual void OnShowItem();
```  
  
### <a name="remarks"></a>Comentários  
 Ele é usado quando o aplicativo de contêiner oferece suporte a links para itens inseridos (isto é, se derivada sua classe de documento de [COleLinkingDoc](../../mfc/reference/colelinkingdoc-class.md)). Essa função é chamada durante a ativação no local ou quando o item OLE é uma fonte de link e o usuário deseja editá-lo. A implementação padrão ativa a primeira exibição no documento contêiner. Substitua essa função para rolar o documento para que o item OLE está visível.  
  
##  <a name="onupdateframetitle"></a>COleClientItem::OnUpdateFrameTitle  
 Chamado pela estrutura durante a ativação no local para atualizar a barra de título da janela de quadro.  
  
```  
virtual BOOL OnUpdateFrameTitle();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se essa função foi atualizada com êxito o título do quadro, caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não altera o título da janela de quadro. Substituir essa função se você quiser um título do quadro diferente para seu aplicativo, por exemplo " *aplicativo server* - *item* na *NomeDoMéd*" (como "Microsoft Excel - planilha no relatório. DOC"). Isso é uma avançada substituível.  
  
##  <a name="reactivateandundo"></a>COleClientItem::ReactivateAndUndo  
 Chame essa função para reativar o item OLE e desfazer a última operação realizada pelo usuário durante a edição in-loco.  
  
```  
BOOL ReactivateAndUndo();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se seu aplicativo recipiente suporta o comando Desfazer, chame essa função se o usuário escolher o comando Desfazer imediatamente depois de desativar o item OLE.  
  
 Se o aplicativo de servidor é escrito com as bibliotecas de classes do Microsoft Foundation, essa função faz com que o servidor chame [COleServerDoc::OnReactivateAndUndo](../../mfc/reference/coleserverdoc-class.md#onreactivateandundo).  
  
 Para obter mais informações, consulte [IOleInPlaceObject::ReactivateAndUndo](http://msdn.microsoft.com/library/windows/desktop/ms691372) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="release"></a>COleClientItem::Release  
 Chame essa função para limpar os recursos usados pelo item OLE.  
  
```  
virtual void Release(OLECLOSE dwCloseOption = OLECLOSE_NOSAVE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwCloseOption`  
 Sinalizador que especifica sob quais circunstâncias o item OLE é salva quando ele retorna ao estado carregado. Para obter uma lista dos valores possíveis, consulte [COleClientItem::Close](#close).  
  
### <a name="remarks"></a>Comentários  
 **Versão** é chamado pelo `COleClientItem` destruidor.  
  
 Para obter mais informações, consulte [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms682317) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="reload"></a>COleClientItem::Reload  
 Fecha e recarrega o item.  
  
```  
BOOL Reload();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chamar o `Reload` função depois de ativar o item como um item de outro tipo por uma chamada a [ActivateAs](#activateas).  
  
##  <a name="run"></a>COleClientItem::Run  
 Executa o aplicativo associado a este item.  
  
```  
void Run();
```  
  
### <a name="remarks"></a>Comentários  
 Chamar o **executar** função de membro para iniciar o aplicativo de servidor antes de ativar o item. Isso é feito automaticamente pelo [ativar](#activate) e [DoVerb](#doverb), portanto, geralmente não é necessário chamar essa função. Chame essa função se for necessário executar o servidor para definir um atributo do item, como [SetExtent](#setextent), antes de executar [DoVerb](#doverb).  
  
##  <a name="setdrawaspect"></a>COleClientItem::SetDrawAspect  
 Chamar o `SetDrawAspect` a função de membro para definir o "aspecto" ou o modo de exibição do item.  
  
```  
virtual void SetDrawAspect(DVASPECT nDrawAspect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nDrawAspect`  
 Um valor da enumeração `DVASPECT`. Esse parâmetro pode ter um dos seguintes valores:  
  
- `DVASPECT_CONTENT`Item é representado de forma que ele pode ser exibido como um objeto incorporado dentro do seu contêiner.  
  
- `DVASPECT_THUMBNAIL`Item será renderizado em uma representação "em miniatura" para que ela possa ser exibida em uma ferramenta de procura.  
  
- `DVASPECT_ICON`Item é representado por um ícone.  
  
- `DVASPECT_DOCPRINT`Item é representado como se ela fosse impressa usando o comando Imprimir no menu arquivo.  
  
### <a name="remarks"></a>Comentários  
 O aspecto Especifica como o item a ser processada pelo [desenhar](#draw) quando o valor padrão para essa função `nDrawAspect` argumento é usado.  
  
 Essa função é chamada automaticamente pelo ícone de alteração (e outras caixas de diálogo que chamem a caixa de diálogo Alterar ícone diretamente) para habilitar o aspecto de exibição icônico quando solicitado pelo usuário.  
  
##  <a name="setextent"></a>COleClientItem::SetExtent  
 Chame essa função para especificar quanto espaço está disponível para o item OLE.  
  
```  
void SetExtent(
    const CSize& size,  
    DVASPECT nDrawAspect = DVASPECT_CONTENT);
```  
  
### <a name="parameters"></a>Parâmetros  
 `size`  
 A [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto que contém as informações de tamanho.  
  
 `nDrawAspect`  
 Especifica o aspecto do item OLE cujos limites devem ser definidas. Para obter valores possíveis, consulte [SetDrawAspect](#setdrawaspect).  
  
### <a name="remarks"></a>Comentários  
 Se o aplicativo de servidor foi escrito usando a biblioteca Microsoft Foundation Class, isso faz com que o [OnSetExtent](../../mfc/reference/coleserveritem-class.md#onsetextent) a função de membro de correspondente `COleServerItem` objeto a ser chamado. O item OLE pode ajustar sua exibição adequadamente. As dimensões devem ser em `MM_HIMETRIC` unidades. Chame essa função quando o usuário redimensiona o item OLE ou se você oferecer suporte a alguma forma de negociação de layout.  
  
 Para obter mais informações, consulte [IOleObject::SetExtent](http://msdn.microsoft.com/library/windows/desktop/ms694330) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="sethostnames"></a>COleClientItem::SetHostNames  
 Chame essa função para especificar o nome do aplicativo de contêiner e o nome do contêiner para um item OLE incorporado.  
  
```  
void SetHostNames(
    LPCTSTR lpszHost,  
    LPCTSTR lpszHostObj);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszHost`  
 Ponteiro para o nome de usuário visível do aplicativo recipiente.  
  
 `lpszHostObj`  
 Ponteiro para uma cadeia de caracteres de identificação do contêiner que contém o item OLE.  
  
### <a name="remarks"></a>Comentários  
 Se o aplicativo de servidor foi escrito usando a biblioteca Microsoft Foundation Class, essa função chama o [OnSetHostNames](../../mfc/reference/coleserverdoc-class.md#onsethostnames) função de membro de `COleServerDoc` documento que contém o item OLE. Essas informações são usadas em títulos de janela quando o item OLE está sendo editado. Sempre que um documento de contêiner é carregado, o framework chama essa função para todos os itens OLE no documento. `SetHostNames`é aplicável somente para itens inseridos. Não é necessário chamar esta função sempre que um item OLE incorporado é ativado para edição.  
  
 Isso também é chamado automaticamente com o nome do aplicativo e o nome do documento quando um objeto é carregado ou quando um arquivo é salvo com um nome diferente. Da mesma forma, não é geralmente necessário chamar essa função diretamente.  
  
 Para obter mais informações, consulte [IOleObject::SetHostNames](http://msdn.microsoft.com/library/windows/desktop/ms680642) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="seticonicmetafile"></a>COleClientItem::SetIconicMetafile  
 Armazena em cache o metarquivo usado para desenhar o ícone do item.  
  
```  
BOOL SetIconicMetafile(HGLOBAL hMetaPict);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hMetaPict`  
 Um identificador para o metarquivo usado para desenhar o ícone do item.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use [GetIconicMetafile](#geticonicmetafile) para recuperar o metarquivo.  
  
 O `hMetaPict` parâmetro é copiado para o item; portanto, `hMetaPict` deve ser liberada por ele.  
  
##  <a name="setitemrects"></a>COleClientItem::SetItemRects  
 Chame essa função para definir o retângulo delimitador ou retângulo visível do item OLE.  
  
```  
BOOL SetItemRects(
    LPCRECT lpPosRect = NULL,  
    LPCRECT lpClipRect = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lprcPosRect*  
 Ponteiro para o retângulo que contém os limites do item OLE em relação a sua janela pai, nas coordenadas do cliente.  
  
 *lprcClipRect*  
 Ponteiro para o retângulo que contém os limites da parte visível do item OLE em relação a sua janela pai, nas coordenadas do cliente.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função é chamada pela implementação do padrão de [OnChangeItemPosition](#onchangeitemposition) função de membro. Você deve chamar essa função sempre que as alterações de item a posição ou a parte visível do OLE. Geralmente, isso significa que você chamá-la em seu modo de exibição [OnSize](../../mfc/reference/cwnd-class.md#onsize) e [OnScrollBy](../../mfc/reference/cview-class.md#onscrollby) funções de membro.  
  
 Para obter mais informações, consulte [IOleInPlaceObject::SetObjectRects](http://msdn.microsoft.com/library/windows/desktop/ms683767) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="setlinkupdateoptions"></a>COleClientItem::SetLinkUpdateOptions  
 Chame essa função para definir a opção de atualização de link para a apresentação do item vinculado especificado.  
  
```  
void SetLinkUpdateOptions(OLEUPDATE dwUpdateOpt);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwUpdateOpt*  
 O valor da opção de atualização de link para este item. Esse valor deve ser um dos seguintes:  
  
- `OLEUPDATE_ALWAYS`Atualize o item vinculado sempre que possível. Essa opção oferece suporte ao botão de opção atualização automática de link na caixa de diálogo Links.  
  
- `OLEUPDATE_ONCALL`Atualizar o item vinculado somente na solicitação do aplicativo de contêiner (quando o [UpdateLink](#updatelink) é chamada de função de membro). Essa opção oferece suporte ao botão de opção Atualização Manual de link na caixa de diálogo Links.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, você não deve alterar as opções de atualização escolhidas pelo usuário na caixa de diálogo Links.  
  
 Para obter mais informações, consulte [IOleLink::SetUpdateOptions](http://msdn.microsoft.com/library/windows/desktop/ms680120) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="setprintdevice"></a>COleClientItem::SetPrintDevice  
 Chame essa função para alterar o dispositivo de destino de impressão para este item.  
  
```  
BOOL SetPrintDevice(const DVTARGETDEVICE* ptd);  
BOOL SetPrintDevice(const PRINTDLG* ppd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptd`  
 Ponteiro para uma [DVTARGETDEVICE](http://msdn.microsoft.com/library/windows/desktop/ms686613) estrutura de dados, que contém informações sobre o novo dispositivo de destino de impressão. Pode ser **nulo**.  
  
 `ppd`  
 Ponteiro para uma [PRINTDLG](http://msdn.microsoft.com/library/windows/desktop/ms646940) estrutura de dados, que contém informações sobre o novo dispositivo de destino de impressão. Pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função atualiza o dispositivo de destino de impressão para o item, mas não atualiza o cache de apresentação. Para atualizar o cache de apresentação para um item, chame [UpdateLink](#updatelink).  
  
 Os argumentos para essa função contêm informações que o sistema OLE usa para identificar o dispositivo de destino. O **PRINTDLG** estrutura contém informações que o Windows usa para inicializar a caixa de diálogo de impressão comuns. Depois que o usuário fecha a caixa de diálogo, o Windows retorna informações sobre as seleções do usuário nessa estrutura. O `m_pd` membro de um [CPrintDialog](../../mfc/reference/cprintdialog-class.md) objeto é um **PRINTDLG** estrutura.  
  
 Para obter mais informações sobre essa estrutura, consulte [PRINTDLG](http://msdn.microsoft.com/library/windows/desktop/ms646843) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações, consulte [DVTARGETDEVICE](http://msdn.microsoft.com/library/windows/desktop/ms686613) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="updatelink"></a>COleClientItem::UpdateLink  
 Chame essa função para atualizar os dados da apresentação do item OLE imediatamente.  
  
```  
BOOL UpdateLink();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero em caso de êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Itens vinculados, a função localiza a fonte do link para obter uma nova apresentação do item OLE. Esse processo pode envolver a execução de um ou mais aplicativos de servidor, que pode ser demorados. Para itens inseridos, a função opera recursivamente, verificando se o item inserido contém links que podem estar desatualizadas e atualizá-los. O usuário também pode atualizar manualmente usando a caixa de diálogo Links de vínculos individuais.  
  
 Para obter mais informações, consulte [IOleLink::Update](http://msdn.microsoft.com/library/windows/desktop/ms692660) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MFCBIND](../../visual-cpp-samples.md)   
 [Exemplo MFC OCLIENT](../../visual-cpp-samples.md)   
 [Classe CDocItem](../../mfc/reference/cdocitem-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe da classe derivada COleServerItem](../../mfc/reference/coleserveritem-class.md)

