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
ms.openlocfilehash: c6e00bf42cf20b46c949c218efe1820cc7ce0f9b
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69504017"
---
# <a name="coledocobjectitem-class"></a>Classe COleDocObjectItem

Implementa a contenção do documento ativo.

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
|[COleDocObjectItem::GetActiveView](#getactiveview)|Recupera o modo de exibição ativo do documento.|
|[COleDocObjectItem::GetPageCount](#getpagecount)|Recupera o número de páginas no documento do aplicativo de contêiner.|
|[COleDocObjectItem::OnPreparePrinting](#onprepareprinting)|Prepara o documento do aplicativo de contêiner para impressão.|
|[COleDocObjectItem::OnPrint](#onprint)|Imprime o documento do aplicativo de contêiner.|
|[COleDocObjectItem::QueryCommand](#querycommand)|Consulta o status de um ou mais comandos gerados por eventos da interface do usuário.|
|[COleDocObjectItem::Release](#release)|Libera a conexão a um item OLE vinculado e o fecha se ele estava aberto. Não destrói o item do cliente.|

## <a name="remarks"></a>Comentários

No MFC, um documento ativo é tratado de forma semelhante a uma incorporação editável regular e in-loco, com as seguintes diferenças:

- A `COleDocument`classe derivada ainda mantém uma lista dos itens atualmente inseridos; no entanto, esses itens podem `COleDocObjectItem`ser itens derivados.

- Quando um documento ativo está ativo, ele ocupa toda a área do cliente da exibição quando ele está ativo no local.

- Um contêiner de documento ativo tem controle total do menu **ajuda** .

- O menu **ajuda** contém itens de menu para o contêiner e o servidor do documento ativo.

Como o contêiner do documento ativo possui o menu **ajuda** , o contêiner é responsável por encaminhar mensagens de menu da **ajuda** do servidor para o servidor. Essa integração é tratada pelo `COleDocObjectItem`.

Para obter mais informações sobre mesclagem de menu e ativação de documento ativa, consulte Visão geral da contenção de [documento ativo](../../mfc/active-document-containment.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CDocItem](../../mfc/reference/cdocitem-class.md)

[COleClientItem](../../mfc/reference/coleclientitem-class.md)

`COleDocObjectItem`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxole. h

##  <a name="coledocobjectitem"></a>  COleDocObjectItem::COleDocObjectItem

Chame essa função de membro para inicializar `COleDocObjectItem` o objeto.

```
COleDocObjectItem(COleDocument* pContainerDoc = NULL);
```

### <a name="parameters"></a>Parâmetros

*pContainerDoc*<br/>
Um ponteiro para o `COleDocument` objeto que atua como o contêiner do documento ativo. Esse parâmetro deve ser nulo para habilitar IMPLEMENT_SERIALIZE. Normalmente, os itens OLE são construídos com um ponteiro de documento não nulo.

##  <a name="dodefaultprinting"></a>  COleDocObjectItem::DoDefaultPrinting

Chamado pelo Framework para um documento usando as configurações padrão.

```
static HRESULT DoDefaultPrinting(
    CView* pCaller,
    CPrintInfo* pInfo);
```

### <a name="parameters"></a>Parâmetros

*pCaller*<br/>
Um ponteiro para um objeto [cvisualização](../../mfc/reference/cview-class.md) que está enviando o comando Print.

*pInfo*<br/>
Um ponteiro para um objeto [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) que descreve o trabalho a ser impresso.

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
O identificador do comando a ser executado. Deve estar no grupo identificado por *pguidCmdGroup*.

*nCmdExecOpt*<br/>
Especifica opções de execução de comando. Por padrão, defina para executar o comando sem avisar o usuário. Consulte [OLECMDEXECOPT](/windows/win32/api/docobj/ne-docobj-olecmdexecopt) para obter uma lista de valores.

*pguidCmdGroup*<br/>
Identificador exclusivo do grupo de comandos. Por padrão, NULL, que especifica o grupo padrão. O comando passado em *nCmdID* deve pertencer ao grupo.

### <a name="return-value"></a>Valor de retorno

Retornará S_OK se for bem-sucedido; caso contrário, retorna um dos seguintes códigos de erro.

|Valor|Descrição|
|-----------|-----------------|
|E_UNEXPECTED|Ocorreu um erro inesperado.|
|E_FAIL|Ocorreu um erro.|
|E_NOTIMPL|Indica que o próprio MFC deve tentar converter e enviar o comando.|
|OLECMDERR_E_UNKNOWNGROUP|*pguidCmdGroup* não é nulo, mas não especifica um grupo de comandos reconhecido.|
|OLECMDERR_E_NOTSUPPORTED|*nCmdID* não é reconhecido como um comando válido no grupo pGroup.|
|OLECMDERR_DISABLED|O comando identificado por *nCmdID* está desabilitado e não pode ser executado.|
|OLECMDERR_NOHELP|O chamador solicitou ajuda no comando identificado por *nCmdID* , mas nenhuma ajuda está disponível.|
|OLECMDERR_CANCELLED|O usuário cancelou a execução.|

### <a name="remarks"></a>Comentários

Os parâmetros *pguidCmdGroup* e *nCmdID* juntos identificam exclusivamente o comando a ser invocado. O parâmetro *nCmdExecOpt* especifica a ação exata a ser tomada.

##  <a name="getactiveview"></a>  COleDocObjectItem::GetActiveView

Chame essa função de membro para obter um ponteiro para `IOleDocumentView` a interface do modo de exibição atualmente ativo.

```
LPOLEDOCUMENTVIEW GetActiveView() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a interface [IOleDocumentView](/windows/win32/api/docobj/nn-docobj-ioledocumentview) do modo de exibição atualmente ativo. Se não houver nenhuma exibição atual, ela retornará NULL.

### <a name="remarks"></a>Comentários

A contagem de referência no ponteiro `IOleDocumentView` retornado não é incrementada antes de ser retornada por essa função.

##  <a name="getpagecount"></a>  COleDocObjectItem::GetPageCount

Chame essa função de membro para recuperar o número de páginas no documento.

```
BOOL GetPageCount(
    LPLONG pnFirstPage,
    LPLONG pcPages);
```

### <a name="parameters"></a>Parâmetros

*pnFirstPage*<br/>
Um ponteiro para o número da primeira página do documento. Pode ser NULL, o que indica que o chamador não precisa desse número.

*pcPages*<br/>
Um ponteiro para o número total de páginas no documento. Pode ser NULL, o que indica que o chamador não precisa desse número.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

##  <a name="onprepareprinting"></a>  COleDocObjectItem::OnPreparePrinting

Essa função de membro é chamada pelo Framework para preparar um documento para impressão.

```
static BOOL OnPreparePrinting(
    CView* pCaller,
    CPrintInfo* pInfo,
    BOOL bPrintAll = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pCaller*<br/>
Um ponteiro para um objeto [cvisualização](../../mfc/reference/cview-class.md) que está enviando o comando Print.

*pInfo*<br/>
Um ponteiro para um objeto [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) que descreve o trabalho a ser impresso.

*bPrintAll*<br/>
Especifica se o documento inteiro deve ser impresso.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

##  <a name="onprint"></a>  COleDocObjectItem::OnPrint

Essa função de membro é chamada pelo Framework para imprimir um documento.

```
static void OnPrint(
    CView* pCaller,
    CPrintInfo* pInfo,
    BOOL bPrintAll = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pCaller*<br/>
Um ponteiro para um objeto Cvisualização que está enviando o comando Print.

*pInfo*<br/>
Um ponteiro para um objeto [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) que descreve o trabalho a ser impresso.

*bPrintAll*<br/>
Especifica se o documento inteiro deve ser impresso.

##  <a name="querycommand"></a>  COleDocObjectItem::QueryCommand

Consulta o status de um ou mais comandos gerados por eventos da interface do usuário.

```
HRESULT QueryCommand(
    ULONG nCmdID,
    DWORD* pdwStatus,
    OLECMDTEXT* pCmdText =NULL,
    const GUID* pguidCmdGroup =NULL);
```

### <a name="parameters"></a>Parâmetros

*nCmdID*<br/>
identificador do comando que está sendo consultado.

*pdwStatus*<br/>
Um ponteiro para os sinalizadores retornados como resultado da consulta. Para obter uma lista de valores possíveis, consulte [OLECMDF](/windows/win32/api/docobj/ne-docobj-olecmdf).

*pCmdText*<br/>
Ponteiro para uma estrutura [OLECMDTEXT](/windows/win32/api/docobj/ns-docobj-olecmdtext) na qual retornar informações de nome e status de um único comando. Pode ser NULL para indicar que o chamador não precisa dessas informações.

*pguidCmdGroup*<br/>
Identificador exclusivo do grupo de comandos; pode ser nulo para especificar o grupo padrão.

### <a name="return-value"></a>Valor de retorno

Para obter uma lista completa de valores de retorno, consulte [IOleCommandTarget:: QueryStatus](/windows/win32/api/docobj/nf-docobj-iolecommandtarget-querystatus) no SDK do Windows.

### <a name="remarks"></a>Comentários

Essa função de membro emula a funcionalidade do método [IOleCommandTarget:: QueryStatus](/windows/win32/api/docobj/nf-docobj-iolecommandtarget-querystatus) , conforme descrito no SDK do Windows.

##  <a name="release"></a>  COleDocObjectItem::Release

Libera a conexão a um item OLE vinculado e o fecha se ele estava aberto. Não destrói o item do cliente.

```
virtual void Release(OLECLOSE dwCloseOption = OLECLOSE_NOSAVE);
```

### <a name="parameters"></a>Parâmetros

*dwCloseOption*<br/>
Sinalizador que especifica em que circunstâncias o item OLE é salvo quando retorna ao estado carregado. Para obter uma lista de valores possíveis, consulte [COleClientItem:: Close](../../mfc/reference/coleclientitem-class.md#close).

### <a name="remarks"></a>Comentários

Não destrói o item do cliente.

## <a name="see-also"></a>Consulte também

[Exemplo de MFCBIND do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)<br/>
[Classe de CDocObjectServerItem](../../mfc/reference/cdocobjectserveritem-class.md)
