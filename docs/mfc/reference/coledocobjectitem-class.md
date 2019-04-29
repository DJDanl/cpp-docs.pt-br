---
title: Classe COleDocObjectItem
ms.date: 11/04/2016
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
helpviewer_keywords:
- COleDocObjectItem [MFC], COleDocObjectItem
- COleDocObjectItem [MFC], DoDefaultPrinting
- COleDocObjectItem [MFC], ExecCommand
- COleDocObjectItem [MFC], GetActiveView
- COleDocObjectItem [MFC], GetPageCount
- COleDocObjectItem [MFC], OnPreparePrinting
- COleDocObjectItem [MFC], OnPrint
- COleDocObjectItem [MFC], QueryCommand
- COleDocObjectItem [MFC], Release
ms.assetid: d150d306-8fd3-4831-b06d-afbe71d8fc9b
ms.openlocfilehash: 382960b4dc4dcfa61c836a87044dd14585756174
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62225507"
---
# <a name="coledocobjectitem-class"></a>Classe COleDocObjectItem

Contenção de documento ativo implementa.

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
|[COleDocObjectItem::GetActiveView](#getactiveview)|Recupera o modo de exibição do documento ativo.|
|[COleDocObjectItem::GetPageCount](#getpagecount)|Recupera o número de páginas no documento do aplicativo de contêiner.|
|[COleDocObjectItem::OnPreparePrinting](#onprepareprinting)|Prepara um documento do aplicativo de contêiner para impressão.|
|[COleDocObjectItem::OnPrint](#onprint)|Imprime o documento do aplicativo de contêiner.|
|[COleDocObjectItem::QueryCommand](#querycommand)|Consulta o status de um ou mais comandos gerados pelos eventos de interface do usuário.|
|[COleDocObjectItem::Release](#release)|Libera a conexão para uma item vinculada de OLE e fecha-la se ela estiver aberta. Destrói o item do cliente.|

## <a name="remarks"></a>Comentários

No MFC, um documento ativo é tratado da mesma forma um regular, in loco editável inserção, com as seguintes diferenças:

- O `COleDocument`-classe derivada ainda mantém uma lista de itens inseridos no momento; no entanto, esses itens podem ser `COleDocObjectItem`-derivado de itens.

- Quando um documento ativo está ativo, ele ocupa toda a área cliente do modo de exibição quando ele estiver ativo no local.

- Um contêiner de documento ativo tem controle total sobre o **ajudar** menu.

- O **ajudar** menu contém itens de menu para o contêiner de documento ativo e o servidor.

Como o contêiner de documento ativo possui o **ajudar** menu, o contêiner é responsável por servidor de encaminhamento **ajudar** mensagens de menu para o servidor. Essa integração é tratada pelo `COleDocObjectItem`.

Para obter mais informações sobre mesclagem de menu e ativação do documento ativo, consulte Visão geral dos [contenção de documento ativo](../../mfc/active-document-containment.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CDocItem](../../mfc/reference/cdocitem-class.md)

[COleClientItem](../../mfc/reference/coleclientitem-class.md)

`COleDocObjectItem`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

##  <a name="coledocobjectitem"></a>  COleDocObjectItem::COleDocObjectItem

Chame essa função de membro para inicializar o `COleDocObjectItem` objeto.

```
COleDocObjectItem(COleDocument* pContainerDoc = NULL);
```

### <a name="parameters"></a>Parâmetros

*pContainerDoc*<br/>
Um ponteiro para o `COleDocument` objeto que atua como o contêiner de documento ativo. Esse parâmetro deve ser NULL para habilitar IMPLEMENT_SERIALIZE. Normalmente, itens OLE são construídos com um ponteiro de documento não nulo.

##  <a name="dodefaultprinting"></a>  COleDocObjectItem::DoDefaultPrinting

Chamado pelo framework para um documento usando as configurações padrão.

```
static HRESULT DoDefaultPrinting(
    CView* pCaller,
    CPrintInfo* pInfo);
```

### <a name="parameters"></a>Parâmetros

*pCaller*<br/>
Um ponteiro para um [CView](../../mfc/reference/cview-class.md) objeto que está enviando o comando print.

*pInfo*<br/>
Um ponteiro para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) objeto que descreve o trabalho a ser impresso.

##  <a name="execcommand"></a>  COleDocObjectItem::ExecCommand

Chame essa função de membro para executar o comando especificado pelo usuário.

```
HRESULT ExecCommand(
    DWORD nCmdID,
    DWORD nCmdExecOpt = OLECMDEXECOPT_DONTPROMPTUSER,
    const GUID* pguidCmdGroup = NULL);
```

### <a name="parameters"></a>Parâmetros

*nCmdID*<br/>
O identificador do comando para executar. Deve estar no grupo identificado pelo *pguidCmdGroup*.

*nCmdExecOpt*<br/>
Especifica as opções de execução do comando. Por padrão, definido para executar o comando sem avisar o usuário. Ver [OLECMDEXECOPT](/windows/desktop/api/docobj/ne-docobj-olecmdexecopt) para obter uma lista de valores.

*pguidCmdGroup*<br/>
Identificador exclusivo do grupo de comando. Por padrão, NULL, que especifica o grupo padrão. O comando passado *nCmdID* deve pertencer ao grupo.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK se bem-sucedido; Caso contrário, retorna um dos seguintes códigos de erro.

|Valor|Descrição|
|-----------|-----------------|
|E_UNEXPECTED|Ocorreu um erro inesperado.|
|E_FAIL|Ocorreu o erro.|
|E_NOTIMPL|Indica o MFC em si deve tentar se traduzem e expedir o comando.|
|OLECMDERR_E_UNKNOWNGROUP|*pguidCmdGroup* não for nulo, mas não especificar um grupo de comando reconhecido.|
|OLECMDERR_E_NOTSUPPORTED|*nCmdID* não é reconhecido como um comando válido em pGroup o grupo.|
|OLECMDERR_DISABLED|O comando identificado pelo *nCmdID* está desabilitado e não pode ser executado.|
|OLECMDERR_NOHELP|Chamador frequentes para obter ajuda sobre o comando identificado pelo *nCmdID* , mas nenhuma ajuda está disponível.|
|OLECMDERR_CANCELLED|O usuário cancelou a execução.|

### <a name="remarks"></a>Comentários

O *pguidCmdGroup* e o *nCmdID* parâmetros juntos identificam exclusivamente para invocar o comando. O *nCmdExecOpt* parâmetro especifica a ação exata a ser tomada.

##  <a name="getactiveview"></a>  COleDocObjectItem::GetActiveView

Chame essa função de membro para obter um ponteiro para o `IOleDocumentView` interface do modo de exibição ativa no momento.

```
LPOLEDOCUMENTVIEW GetActiveView() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o [IOleDocumentView](/windows/desktop/api/docobj/nn-docobj-ioledocumentview) interface do modo de exibição ativa no momento. Se não houver nenhum modo de exibição atual, ele retornará NULL.

### <a name="remarks"></a>Comentários

A contagem de referência em retornado `IOleDocumentView` ponteiro não é incrementado antes de ser retornado por essa função.

##  <a name="getpagecount"></a>  COleDocObjectItem::GetPageCount

Chame essa função de membro para recuperar o número de páginas no documento.

```
BOOL GetPageCount(
    LPLONG pnFirstPage,
    LPLONG pcPages);
```

### <a name="parameters"></a>Parâmetros

*pnFirstPage*<br/>
Um ponteiro para o número da primeira página do documento. Pode ser nulo, o que indica que o chamador não precisar esse número.

*pcPages*<br/>
Um ponteiro para o número total de páginas no documento. Pode ser nulo, o que indica que o chamador não precisar esse número.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

##  <a name="onprepareprinting"></a>  COleDocObjectItem::OnPreparePrinting

Essa função membro é chamada pelo framework para preparar um documento para impressão.

```
static BOOL OnPreparePrinting(
    CView* pCaller,
    CPrintInfo* pInfo,
    BOOL bPrintAll = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pCaller*<br/>
Um ponteiro para um [CView](../../mfc/reference/cview-class.md) objeto que está enviando o comando print.

*pInfo*<br/>
Um ponteiro para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) objeto que descreve o trabalho a ser impresso.

*bPrintAll*<br/>
Especifica se o documento inteiro deve ser impresso.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

##  <a name="onprint"></a>  COleDocObjectItem::OnPrint

Essa função membro é chamada pelo framework para imprimir um documento.

```
static void OnPrint(
    CView* pCaller,
    CPrintInfo* pInfo,
    BOOL bPrintAll = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pCaller*<br/>
Um ponteiro para um objeto CView que está enviando o comando print.

*pInfo*<br/>
Um ponteiro para um [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) objeto que descreve o trabalho a ser impresso.

*bPrintAll*<br/>
Especifica se o documento inteiro deve ser impresso.

##  <a name="querycommand"></a>  COleDocObjectItem::QueryCommand

Consulta o status de um ou mais comandos gerados pelos eventos de interface do usuário.

```
HRESULT QueryCommand(
    ULONG nCmdID,
    DWORD* pdwStatus,
    OLECMDTEXT* pCmdText =NULL,
    const GUID* pguidCmdGroup =NULL);
```

### <a name="parameters"></a>Parâmetros

*nCmdID*<br/>
Identificador do comando que está sendo consultado para.

*pdwStatus*<br/>
Um ponteiro para os sinalizadores retornados em virtude da consulta. Para obter uma lista de valores possíveis, consulte [OLECMDF](/windows/desktop/api/docobj/ne-docobj-olecmdf).

*pCmdText*<br/>
Ponteiro para um [OLECMDTEXT](/windows/desktop/api/docobj/ns-docobj-_tagolecmdtext) estrutura na qual retornar informações de nome e o status de um único comando. Pode ser nulo para indicar que o chamador não precisa dessas informações.

*pguidCmdGroup*<br/>
Identificador exclusivo do grupo de comando; pode ser NULL para especificar o grupo padrão.

### <a name="return-value"></a>Valor de retorno

Para obter uma lista completa de valores de retorno, consulte [IOleCommandTarget::QueryStatus](/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-querystatus) no SDK do Windows.

### <a name="remarks"></a>Comentários

Essa função membro emula a funcionalidade dos [IOleCommandTarget::QueryStatus](/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-querystatus) método, conforme descrito no SDK do Windows.

##  <a name="release"></a>  COleDocObjectItem::Release

Libera a conexão para uma item vinculada de OLE e fecha-la se ela estiver aberta. Destrói o item do cliente.

```
virtual void Release(OLECLOSE dwCloseOption = OLECLOSE_NOSAVE);
```

### <a name="parameters"></a>Parâmetros

*dwCloseOption*<br/>
Sinalizador que especifica em quais circunstâncias o item OLE é salvo quando ele é retornado para o estado carregado. Para obter uma lista de valores possíveis, consulte [COleClientItem::Close](../../mfc/reference/coleclientitem-class.md#close).

### <a name="remarks"></a>Comentários

Destrói o item do cliente.

## <a name="see-also"></a>Consulte também

[Exemplo MFC MFCBIND](../../overview/visual-cpp-samples.md)<br/>
[Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)<br/>
[Classe de CDocObjectServerItem](../../mfc/reference/cdocobjectserveritem-class.md)
