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
ms.openlocfilehash: a696226185dd99b9e277e74d92cbe15c95cc900a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375046"
---
# <a name="coledocobjectitem-class"></a>Classe COleDocObjectItem

Implementa contenção ativa de documentos.

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
|[COleDocObjectItem::DoDefaultPrinting](#dodefaultprinting)|Imprime o documento do aplicativo de contêiner usando as configurações padrão da impressora.|
|[COleDocObjectItem::ExecCommand](#execcommand)|Executa o comando especificado pelo usuário.|
|[COleDocObjectItem::GetActiveView](#getactiveview)|Recupera a exibição ativa do documento.|
|[COleDocObjectItem::GetPageCount](#getpagecount)|Recupera o número de páginas no documento do aplicativo de contêiner.|
|[COleDocObjectItem::OnPreparePrinting](#onprepareprinting)|Prepara o documento da aplicação do recipiente para impressão.|
|[COleDocObjectItem::OnPrint](#onprint)|Imprime o documento do aplicativo do contêiner.|
|[COleDocObjectItem::QueryCommand](#querycommand)|Consultas para o status de um ou mais comandos gerados por eventos de interface de usuário.|
|[COleDocObjectItem::Lançamento](#release)|Libera a conexão a um item vinculado ao OLE e fecha-a se estiver aberta. Não destrói o item do cliente.|

## <a name="remarks"></a>Comentários

No MFC, um documento Ativo é tratado de forma semelhante a uma incorporação editado regular no local, com as seguintes diferenças:

- A `COleDocument`classe derivada ainda mantém uma lista dos itens atualmente incorporados; no entanto, esses `COleDocObjectItem`itens podem ser itens derivados.

- Quando um documento ativo está ativo, ele ocupa toda a área cliente da exibição quando ele está ativo no local.

- Um recipiente de documento Ativo tem controle total do menu **Ajuda.**

- O menu **Ajuda** contém itens do menu para o contêiner de documento ativo e o servidor.

Como o contêiner de documento Ativo possui o menu **Ajuda,** o contêiner é responsável por encaminhar mensagens de menu **de ajuda** do servidor para o servidor. Essa integração é `COleDocObjectItem`tratada por .

Para obter mais informações sobre a fusão do menu e a ativação do documento ativo, consulte Visão geral da [contenção ativa](../../mfc/active-document-containment.md)de documentos .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[Cdocitem](../../mfc/reference/cdocitem-class.md)

[Coleclientitem](../../mfc/reference/coleclientitem-class.md)

`COleDocObjectItem`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

## <a name="coledocobjectitemcoledocobjectitem"></a><a name="coledocobjectitem"></a>COleDocObjectItem::COleDocObjectItem

Chame esta função de `COleDocObjectItem` membro para inicializar o objeto.

```
COleDocObjectItem(COleDocument* pContainerDoc = NULL);
```

### <a name="parameters"></a>Parâmetros

*pContainerDoc*<br/>
Um ponteiro `COleDocument` para o objeto agindo como o recipiente de documento ativo. Este parâmetro deve ser NULO para permitir IMPLEMENT_SERIALIZE. Normalmente, os itens OLE são construídos com um ponteiro de documento não-NULO.

## <a name="coledocobjectitemdodefaultprinting"></a><a name="dodefaultprinting"></a>COleDocObjectItem::DoDefaultPrinting

Chamado pelo framework para um documento usando as configurações padrão.

```
static HRESULT DoDefaultPrinting(
    CView* pCaller,
    CPrintInfo* pInfo);
```

### <a name="parameters"></a>Parâmetros

*pCaller*<br/>
Um ponteiro para um objeto [CView](../../mfc/reference/cview-class.md) que está enviando o comando print.

*Pinfo*<br/>
Um ponteiro para um objeto [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) que descreve o trabalho a ser impresso.

## <a name="coledocobjectitemexeccommand"></a><a name="execcommand"></a>COleDocObjectItem::ExecCommand

Chame esta função de membro para executar o comando especificado pelo usuário.

```
HRESULT ExecCommand(
    DWORD nCmdID,
    DWORD nCmdExecOpt = OLECMDEXECOPT_DONTPROMPTUSER,
    const GUID* pguidCmdGroup = NULL);
```

### <a name="parameters"></a>Parâmetros

*Ncmdid*<br/>
O identificador do comando para executar. Deve estar no grupo identificado pelo *pguidCmdGroup*.

*nCmdExecOpt*<br/>
Especifica opções de execução de comando. Por padrão, configure para executar o comando sem avisar o usuário. Consulte [OLECMDEXECOPT](/windows/win32/api/docobj/ne-docobj-olecmdexecopt) para obter uma lista de valores.

*Pguidcmdgroup*<br/>
Identificador único do grupo de comando. Por padrão, NULL, que especifica o grupo padrão. O comando passado no *nCmdID* deve pertencer ao grupo.

### <a name="return-value"></a>Valor retornado

Os retornos S_OK se forem bem sucedidos; caso contrário, retorna um dos seguintes códigos de erro.

|Valor|Descrição|
|-----------|-----------------|
|E_UNEXPECTED|Ocorreu um erro inesperado.|
|E_FAIL|ocorreu um erro.|
|E_NOTIMPL|Indica que o próprio MFC deve tentar traduzir e despachar o comando.|
|OLECMDERR_E_UNKNOWNGROUP|*pguidCmdGroup* não é NULA, mas não especifica um grupo de comando reconhecido.|
|OLECMDERR_E_NOTSUPPORTED|*nCmdID* não é reconhecido como um comando válido no grupo pGroup.|
|OLECMDERR_DISABLED|O comando identificado pelo *nCmdID* está desativado e não pode ser executado.|
|OLECMDERR_NOHELP|O chamador pediu ajuda no comando identificado pelo *nCmdID,* mas não há ajuda disponível.|
|OLECMDERR_CANCELLED|O usuário cancelou a execução.|

### <a name="remarks"></a>Comentários

Os parâmetros *pguidCmdGroup* e *nCmdID* juntos identificam exclusivamente o comando a ser invocado. O parâmetro *nCmdExecOpt* especifica a ação exata a ser tomada.

## <a name="coledocobjectitemgetactiveview"></a><a name="getactiveview"></a>COleDocObjectItem::GetActiveView

Ligue para esta função de `IOleDocumentView` membro para obter um ponteiro para a interface da exibição ativa atualmente.

```
LPOLEDOCUMENTVIEW GetActiveView() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a interface [IOleDocumentView](/windows/win32/api/docobj/nn-docobj-ioledocumentview) da exibição ativa atualmente. Se não houver uma visão atual, ela retorna NULL.

### <a name="remarks"></a>Comentários

A contagem de `IOleDocumentView` referência no ponteiro retornado não é incrementada antes de ser devolvida por esta função.

## <a name="coledocobjectitemgetpagecount"></a><a name="getpagecount"></a>COleDocObjectItem::GetPageCount

Ligue para esta função de membro para recuperar o número de páginas no documento.

```
BOOL GetPageCount(
    LPLONG pnFirstPage,
    LPLONG pcPages);
```

### <a name="parameters"></a>Parâmetros

*pnFirstPage*<br/>
Um ponteiro para o número da primeira página do documento. Pode ser NULO, o que indica que o interlocutor não precisa deste número.

*pcPages*<br/>
Um ponteiro para o número total de páginas no documento. Pode ser NULO, o que indica que o interlocutor não precisa deste número.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

## <a name="coledocobjectitemonprepareprinting"></a><a name="onprepareprinting"></a>COleDocObjectItem::OnPreparePrinting

Esta função membro é chamada pela estrutura para preparar um documento para impressão.

```
static BOOL OnPreparePrinting(
    CView* pCaller,
    CPrintInfo* pInfo,
    BOOL bPrintAll = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pCaller*<br/>
Um ponteiro para um objeto [CView](../../mfc/reference/cview-class.md) que está enviando o comando print.

*Pinfo*<br/>
Um ponteiro para um objeto [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) que descreve o trabalho a ser impresso.

*bPrintAll*<br/>
Especifica se todo o documento deve ser impresso.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

## <a name="coledocobjectitemonprint"></a><a name="onprint"></a>COleDocObjectItem::OnPrint

Esta função membro é chamada pela estrutura para imprimir um documento.

```
static void OnPrint(
    CView* pCaller,
    CPrintInfo* pInfo,
    BOOL bPrintAll = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pCaller*<br/>
Um ponteiro para um objeto CView que está enviando o comando print.

*Pinfo*<br/>
Um ponteiro para um objeto [CPrintInfo](../../mfc/reference/cprintinfo-structure.md) que descreve o trabalho a ser impresso.

*bPrintAll*<br/>
Especifica se todo o documento deve ser impresso.

## <a name="coledocobjectitemquerycommand"></a><a name="querycommand"></a>COleDocObjectItem::QueryCommand

Consultas para o status de um ou mais comandos gerados por eventos de interface de usuário.

```
HRESULT QueryCommand(
    ULONG nCmdID,
    DWORD* pdwStatus,
    OLECMDTEXT* pCmdText =NULL,
    const GUID* pguidCmdGroup =NULL);
```

### <a name="parameters"></a>Parâmetros

*Ncmdid*<br/>
identificador do comando que está sendo consultado.

*pdwStatus*<br/>
Um ponteiro para as bandeiras retornou como resultado da consulta. Para obter uma lista de valores possíveis, consulte [OLECMDF](/windows/win32/api/docobj/ne-docobj-olecmdf).

*pCmdText*<br/>
Pointer para uma estrutura [OLECMDTEXT](/windows/win32/api/docobj/ns-docobj-olecmdtext) na qual retornar informações de nome e status para um único comando. Pode ser NULO para indicar que o chamador não precisa dessas informações.

*Pguidcmdgroup*<br/>
Identificador exclusivo do grupo de comando; pode ser NULL para especificar o grupo padrão.

### <a name="return-value"></a>Valor retornado

Para obter uma lista completa de valores de retorno, consulte [IOleCommandTarget::QueryStatus](/windows/win32/api/docobj/nf-docobj-iolecommandtarget-querystatus) no SDK do Windows.

### <a name="remarks"></a>Comentários

Essa função de membro emula a funcionalidade do método [IOleCommandTarget::QueryStatus,](/windows/win32/api/docobj/nf-docobj-iolecommandtarget-querystatus) conforme descrito no SDK do Windows.

## <a name="coledocobjectitemrelease"></a><a name="release"></a>COleDocObjectItem::Lançamento

Libera a conexão a um item vinculado ao OLE e fecha-a se estiver aberta. Não destrói o item do cliente.

```
virtual void Release(OLECLOSE dwCloseOption = OLECLOSE_NOSAVE);
```

### <a name="parameters"></a>Parâmetros

*dwCloseOption*<br/>
Sinalizador especificando em que circunstâncias o item OLE é salvo quando ele retorna ao estado carregado. Para obter uma lista de valores possíveis, consulte [COleClientItem::Close](../../mfc/reference/coleclientitem-class.md#close).

### <a name="remarks"></a>Comentários

Não destrói o item do cliente.

## <a name="see-also"></a>Confira também

[MFC Amostra MFCBIND](../../overview/visual-cpp-samples.md)<br/>
[Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleClientItem](../../mfc/reference/coleclientitem-class.md)<br/>
[Classe de CDocObjectServerItem](../../mfc/reference/cdocobjectserveritem-class.md)
