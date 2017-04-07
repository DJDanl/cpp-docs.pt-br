---
title: Classe COleDocObjectItem | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COleDocObjectItem
- AFXOLE/COleDocObjectItem
- AFXOLE/COleDocObjectItem::COleDocObjectItem
- AFXOLE/COleDocObjectItem::DoDefaultPrinting
- AFXOLE/COleDocObjectItem::ExecCommand
- AFXOLE/COleDocObjectItem::GetActiveView
- AFXOLE/COleDocObjectItem::GetPageCount
- AFXOLE/COleDocObjectItem::OnPreparePrinting
- AFXOLE/COleDocObjectItem::OnPrint
- AFXOLE/COleDocObjectItem::QueryCommand
- AFXOLE/COleDocObjectItem::Release
dev_langs:
- C++
helpviewer_keywords:
- COleDocObjectItem class
- document object containment
- containment
- containment, doc object
- doc object containment
ms.assetid: d150d306-8fd3-4831-b06d-afbe71d8fc9b
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
ms.openlocfilehash: 0815454fa4b194e97a2d16a621cfc25da61d5fd0
ms.lasthandoff: 02/25/2017

---
# <a name="coledocobjectitem-class"></a>Classe COleDocObjectItem
Contenção de documento ativa implementa.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class COleDocObjectItem : public COleClientItem  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDocObjectItem::COleDocObjectItem](#coledocobjectitem)|Constrói um `COleDocObject` item.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[COleDocObjectItem::DoDefaultPrinting](#dodefaultprinting)|Imprime o documento do aplicativo de contêiner usando as configurações de impressora padrão.|  
|[COleDocObjectItem::ExecCommand](#execcommand)|Executa o comando especificado pelo usuário.|  
|[COleDocObjectItem::GetActiveView](#getactiveview)|Recupera a exibição ativa do documento.|  
|[COleDocObjectItem::GetPageCount](#getpagecount)|Recupera o número de páginas no documento do aplicativo de contêiner.|  
|[COleDocObjectItem::OnPreparePrinting](#onprepareprinting)|Prepara um documento do aplicativo de contêiner para impressão.|  
|[COleDocObjectItem::OnPrint](#onprint)|Imprime o documento do aplicativo de contêiner.|  
|[COleDocObjectItem::QueryCommand](#querycommand)|Consulta o status de um ou mais comandos gerados pelos eventos da interface do usuário.|  
|[COleDocObjectItem::Release](#release)|Libera a conexão para uma item vinculada de OLE e fechá-lo se ele estava aberto. Não destrói o item do cliente.|  
  
## <a name="remarks"></a>Comentários  
 Em MFC, um documento ativo é tratado da mesma forma para um regular, in-loco editável incorporar, com as seguintes diferenças:  
  
-   O `COleDocument`-classe derivada ainda mantém uma lista dos itens inseridos no momento; no entanto, esses itens podem ser `COleDocObjectItem`-derivado de itens.  
  
-   Quando um documento ativo está ativo, ele ocupará toda a área cliente do modo de exibição quando ele está ativo no local.  
  
-   Um contêiner de documento ativo tem controle total sobre o **ajuda** menu.  
  
-   O **ajuda** menu contém itens de menu para o contêiner do documento ativo e o servidor.  
  
 Como o contêiner do documento ativo possui o **ajuda** menu, o contêiner é responsável por servidor de encaminhamento **ajuda** mensagens de menu para o servidor. Essa integração é tratada pelo `COleDocObjectItem`.  
  
 Para obter mais informações sobre mesclagem de menu e a ativação do documento ativo, consulte Visão geral de [contenção de documento ativo](../../mfc/active-document-containment.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CDocItem](../../mfc/reference/cdocitem-class.md)  
  
 [COleClientItem](../../mfc/reference/coleclientitem-class.md)  
  
 `COleDocObjectItem`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  
  
##  <a name="coledocobjectitem"></a>COleDocObjectItem::COleDocObjectItem  
 Chame essa função de membro para inicializar o `COleDocObjectItem` objeto.  
  
```  
COleDocObjectItem(COleDocument* pContainerDoc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pContainerDoc`  
 Um ponteiro para o `COleDocument` objeto atuando como o contêiner do documento ativo. Esse parâmetro deve ser **nulo** para habilitar **IMPLEMENT_SERIALIZE**. Normalmente os itens OLE são construídos com um não - **nulo** ponteiro de documento.  
  
##  <a name="dodefaultprinting"></a>COleDocObjectItem::DoDefaultPrinting  
 Chamado pela estrutura para um documento usando as configurações padrão.  
  
```  
static HRESULT DoDefaultPrinting(
    CView* pCaller,  
    CPrintInfo* pInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCaller`  
 Um ponteiro para um [CView](../../mfc/reference/cview-class.md) objeto que está enviando o comando print.  
  
 `pInfo`  
 Um ponteiro para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) objeto que descreve o trabalho a ser impresso.  
  
##  <a name="execcommand"></a>COleDocObjectItem::ExecCommand  
 Chame essa função de membro para executar o comando especificado pelo usuário.  
  
```  
HRESULT ExecCommand(
    DWORD nCmdID,  
    DWORD nCmdExecOpt = OLECMDEXECOPT_DONTPROMPTUSER,  
    const GUID* pguidCmdGroup = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nCmdID`  
 O identificador do comando executar. Deve estar no grupo identificado pelo `pguidCmdGroup`.  
  
 `nCmdExecOpt`  
 Especifica as opções de execução do comando. Por padrão, definido para executar o comando sem avisar o usuário. Consulte [OLECMDEXECOPT](http://msdn.microsoft.com/library/windows/desktop/ms683930) para obter uma lista de valores.  
  
 `pguidCmdGroup`  
 Identificador exclusivo do grupo de comando. Por padrão, **nulo**, que especifica o grupo padrão. O comando passado `nCmdID` deve pertencer ao grupo.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `S_OK` se for bem-sucedido; caso contrário, retorna um dos seguintes códigos de erro.  
  
|Valor|Descrição|  
|-----------|-----------------|  
|**E_UNEXPECTED**|Ocorreu um erro inesperado.|  
|**E_FAIL**|Erro.|  
|**E_NOTIMPL**|Indica o MFC em si deve tentar converter e enviar o comando.|  
|**OLECMDERR_E_UNKNOWNGROUP**|`pguidCmdGroup`não **nulo** , mas não especifica um comando reconhecido group.|  
|**OLECMDERR_E_NOTSUPPORTED**|`nCmdID`não é reconhecido como um comando válido no pGroup grupo.|  
|**OLECMDERR_DISABLED**|O comando identificado pelo `nCmdID` está desabilitado e não pode ser executado.|  
|**OLECMDERR_NOHELP**|Chamador solicitou ajuda sobre o comando identificado por `nCmdID` , mas nenhuma ajuda está disponível.|  
|**OLECMDERR_CANCELLED**|O usuário cancelou a execução.|  
  
### <a name="remarks"></a>Comentários  
 O `pguidCmdGroup` e `nCmdID` parâmetros juntos identificam exclusivamente para invocar o comando. O `nCmdExecOpt` parâmetro especifica à ação exata.  
  
##  <a name="getactiveview"></a>COleDocObjectItem::GetActiveView  
 Chame essa função de membro para obter um ponteiro para o `IOleDocumentView` interface da exibição ativa no momento.  
  
```  
LPOLEDOCUMENTVIEW GetActiveView() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o [IOleDocumentView](http://msdn.microsoft.com/library/windows/desktop/ms678455) interface da exibição ativa no momento. Se não houver nenhum modo de exibição atual, ele retorna **nulo**.  
  
### <a name="remarks"></a>Comentários  
 A contagem de referência em retornado `IOleDocumentView` ponteiro não é incrementado antes de serem retornado por essa função.  
  
##  <a name="getpagecount"></a>COleDocObjectItem::GetPageCount  
 Chame essa função de membro para recuperar o número de páginas do documento.  
  
```  
BOOL GetPageCount(
    LPLONG pnFirstPage,  
    LPLONG pcPages);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pnFirstPage*  
 Um ponteiro para o número da primeira página do documento. Pode ser **nulo**, que indica que o chamador não precisa esse número.  
  
 *pcPages*  
 Um ponteiro para o número total de páginas do documento. Pode ser **nulo**, que indica que o chamador não precisa esse número.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
##  <a name="onprepareprinting"></a>COleDocObjectItem::OnPreparePrinting  
 Essa função de membro é chamada pela estrutura para preparar um documento para impressão.  
  
```  
static BOOL OnPreparePrinting(
    CView* pCaller,  
    CPrintInfo* pInfo,  
    BOOL bPrintAll = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCaller`  
 Um ponteiro para um [CView](../../mfc/reference/cview-class.md) objeto que está enviando o comando print.  
  
 `pInfo`  
 Um ponteiro para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) objeto que descreve o trabalho a ser impresso.  
  
 `bPrintAll`  
 Especifica se o documento inteiro deve ser impresso.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
##  <a name="onprint"></a>COleDocObjectItem::OnPrint  
 Essa função de membro é chamada pela estrutura para imprimir um documento.  
  
```  
static void OnPrint(
    CView* pCaller,  
    CPrintInfo* pInfo,  
    BOOL bPrintAll = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCaller`  
 Um ponteiro para um objeto CView que está enviando o comando print.  
  
 `pInfo`  
 Um ponteiro para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) objeto que descreve o trabalho a ser impresso.  
  
 `bPrintAll`  
 Especifica se o documento inteiro deve ser impresso.  
  
##  <a name="querycommand"></a>COleDocObjectItem::QueryCommand  
 Consulta o status de um ou mais comandos gerados pelos eventos da interface do usuário.  
  
```  
HRESULT QueryCommand(
    ULONG nCmdID,  
    DWORD* pdwStatus,  
    OLECMDTEXT* pCmdText =NULL,  
    const GUID* pguidCmdGroup =NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nCmdID`  
 Identificador do comando que está sendo pesquisado.  
  
 `pdwStatus`  
 Um ponteiro para os sinalizadores retornados como resultado da consulta. Para obter uma lista dos valores possíveis, consulte [OLECMDF](http://msdn.microsoft.com/library/windows/desktop/ms695237).  
  
 `pCmdText`  
 Ponteiro para uma [OLECMDTEXT](http://msdn.microsoft.com/library/windows/desktop/ms693314) estrutura na qual retornar informações de nome e o status de um único comando. Pode ser **nulo** para indicar que o chamador não precisa de informações.  
  
 `pguidCmdGroup`  
 Identificador exclusivo do grupo de comando; pode ser **nulo** para especificar o grupo padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 Para obter uma lista completa de valores de retorno, consulte [IOleCommandTarget::QueryStatus](http://msdn.microsoft.com/library/windows/desktop/ms688491) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade do [IOleCommandTarget::QueryStatus](http://msdn.microsoft.com/library/windows/desktop/ms688491) método, conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="release"></a>COleDocObjectItem::Release  
 Libera a conexão para uma item vinculada de OLE e fechá-lo se ele estava aberto. Não destrói o item do cliente.  
  
```  
virtual void Release(OLECLOSE dwCloseOption = OLECLOSE_NOSAVE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwCloseOption`  
 Sinalizador que especifica sob quais circunstâncias o item OLE é salva quando ele retorna ao estado carregado. Para obter uma lista dos valores possíveis, consulte [COleClientItem::Close](../../mfc/reference/coleclientitem-class.md#close).  
  
### <a name="remarks"></a>Comentários  
 Não destrói o item do cliente.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MFCBIND](../../visual-cpp-samples.md)   
 [Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)   
 [Classe CDocObjectServerItem](../../mfc/reference/cdocobjectserveritem-class.md)

