---
title: Estrutura CPrintInfo
ms.date: 11/04/2016
f1_keywords:
- CPrintInfo
helpviewer_keywords:
- CPrintInfo structure [MFC]
ms.assetid: 0b3de849-d050-4386-9a14-f4c1a25684f7
ms.openlocfilehash: cf0a1e6b7e742e950663f1ed9cc9ff2ddabd9d6f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364019"
---
# <a name="cprintinfo-structure"></a>Estrutura CPrintInfo

Armazena informações sobre um trabalho de impressão ou visualização de impressão.

## <a name="syntax"></a>Sintaxe

```
struct CPrintInfo
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPrintInfo::getFromPage](#getfrompage)|Retorna o número da primeira página que está sendo impressa.|
|[CPrintInfo::GetMaxPage](#getmaxpage)|Retorna o número da última página do documento.|
|[CPrintInfo::GetMinPage](#getminpage)|Retorna o número da primeira página do documento.|
|[CPrintInfo::GetOffsetPage](#getoffsetpage)|Retorna o número das páginas anteriores à primeira página de um item DocObject sendo impresso em um trabalho de impressão doCObject combinado.|
|[CPrintInfo::GetToPage](#gettopage)|Retorna o número da última página a ser impressa.|
|[CPrintInfo::SetmaxPage](#setmaxpage)|Define o número da última página do documento.|
|[CPrintInfo::SetMinPage](#setminpage)|Define o número da primeira página do documento.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPrintInfo::m_bContinuePrinting](#m_bcontinueprinting)|Contém uma bandeira indicando se a estrutura deve continuar o loop de impressão.|
|[CPrintInfo::m_bDirect](#m_bdirect)|Contém um sinalizador indicando se o documento está sendo impresso diretamente (sem exibir a caixa de diálogo Imprimir).|
|[CPrintInfo::m_bDocObject](#m_bdocobject)|Contém um sinalizador indicando se o documento que está sendo impresso é um DocObject.|
|[CPrintInfo::m_bPreview](#m_bpreview)|Contém uma bandeira indicando se o documento está sendo visualizado.|
|[CPrintInfo::m_dwFlags](#m_dwflags)|Especifica as operações de impressão DocObject.|
|[CPrintInfo::m_lpUserData](#m_lpuserdata)|Contém um ponteiro para uma estrutura criada pelo usuário.|
|[CPrintInfo::m_nCurPage](#m_ncurpage)|Identifica o número da página que está sendo impressa no momento.|
|[CPrintInfo::m_nJobNumber](#m_njobnumber)|Especifica o número de trabalho atribuído pelo sistema operacional para o trabalho de impressão atual|
|[CPrintInfo::m_nNumPreviewPages](#m_nnumpreviewpages)|Identifica o número de páginas exibidas na janela de visualização; 1 ou 2.|
|[CPrintInfo::m_nOffsetPage](#m_noffsetpage)|Especifica deslocamento da primeira página de um determinado DocObject em um trabalho de impressão doCObject combinado.|
|[CPrintInfo::m_pPD](#m_ppd)|Contém um ponteiro `CPrintDialog` para o objeto usado para a caixa de diálogo Imprimir.|
|[CPrintInfo::m_rectDraw](#m_rectdraw)|Especifica um retângulo definindo a área de página utilizável atual.|
|[CPrintInfo::m_strPageDesc](#m_strpagedesc)|Contém uma seqüência de formato para exibição de número de página.|

## <a name="remarks"></a>Comentários

`CPrintInfo`é uma estrutura e não tem uma classe base.

A estrutura cria `CPrintInfo` um objeto de cada vez que o comando Imprimir ou imprimir visualização é escolhido e o destrói quando o comando é concluído.

`CPrintInfo`contém informações sobre o trabalho de impressão como um todo, como a gama de páginas a serem impressas e o status atual do trabalho de impressão, como a página que está sendo impressa. Algumas informações são armazenadas em um objeto [CPrintDialog](../../mfc/reference/cprintdialog-class.md) associado; este objeto contém os valores inseridos pelo usuário na caixa de diálogo Imprimir.

Um `CPrintInfo` objeto é passado entre a estrutura e sua classe de visualização durante o processo de impressão e é usado para trocar informações entre os dois. Por exemplo, o framework informa a classe de exibição qual página `m_nCurPage` do `CPrintInfo`documento a ser impressa atribuindo um valor ao membro do ; a classe de exibição recupera o valor e executa a impressão real da página especificada.

Outro exemplo é o caso em que o comprimento do documento não é conhecido até que seja impresso. Nesta situação, a classe de exibição testa para o final do documento cada vez que uma página é impressa. Quando o fim é alcançado, `m_bContinuePrinting` a `CPrintInfo` classe de exibição define o membro de FALSE; isso informa a estrutura para parar o loop de impressão.

`CPrintInfo`é usado pelas funções `CView` de membro listadas em "Ver Também". Para obter mais informações sobre a arquitetura de impressão fornecida pela Microsoft Foundation Class Library, consulte [Frame Windows](../../mfc/frame-windows.md) e [Document/View Architecture](../../mfc/document-view-architecture.md) e os artigos [Printing](../../mfc/printing.md) and [Printing: Multipage Documents](../../mfc/multipage-documents.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CPrintInfo`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

## <a name="cprintinfogetfrompage"></a><a name="getfrompage"></a>CPrintInfo::getFromPage

Ligue para esta função para recuperar o número da primeira página a ser impressa.

```
UINT GetFromPage() const;
```

### <a name="return-value"></a>Valor retornado

O número da primeira página a ser impressa.

### <a name="remarks"></a>Comentários

Este é o valor especificado pelo usuário na caixa de `CPrintDialog` diálogo Imprimir e `m_pPD` é armazenado no objeto referenciado pelo membro. Se o usuário não tiver especificado um valor, o padrão será a primeira página do documento.

## <a name="cprintinfogetmaxpage"></a><a name="getmaxpage"></a>CPrintInfo::GetMaxPage

Ligue para esta função para recuperar o número da última página do documento.

```
UINT GetMaxPage() const;
```

### <a name="return-value"></a>Valor retornado

O número da última página do documento.

### <a name="remarks"></a>Comentários

Este valor é `CPrintDialog` armazenado no objeto `m_pPD` referenciado pelo membro.

## <a name="cprintinfogetminpage"></a><a name="getminpage"></a>CPrintInfo::GetMinPage

Ligue para esta função para recuperar o número da primeira página do documento.

```
UINT GetMinPage() const;
```

### <a name="return-value"></a>Valor retornado

O número da primeira página do documento.

### <a name="remarks"></a>Comentários

Este valor é `CPrintDialog` armazenado no objeto `m_pPD` referenciado pelo membro.

## <a name="cprintinfogetoffsetpage"></a><a name="getoffsetpage"></a>CPrintInfo::GetOffsetPage

Chame esta função para recuperar o deslocamento ao imprimir vários itens do DocObject de um cliente DocObject.

```
UINT GetOffsetPage() const;
```

### <a name="return-value"></a>Valor retornado

O número de páginas que precedem a primeira página de um item DocObject sendo impresso em um trabalho de impressão docObject combinado.

### <a name="remarks"></a>Comentários

Esse valor é referenciado pelo `m_nOffsetPage` membro. A primeira página do documento será `m_nOffsetPage` numerada o valor + 1 quando impresso como um DocObject com outros documentos ativos. O `m_nOffsetPage` membro só é `m_bDocObject` válido se o valor for TRUE.

## <a name="cprintinfogettopage"></a><a name="gettopage"></a>CPrintInfo::GetToPage

Ligue para esta função para recuperar o número da última página a ser impressa.

```
UINT GetToPage() const;
```

### <a name="return-value"></a>Valor retornado

O número da última página a ser impressa.

### <a name="remarks"></a>Comentários

Este é o valor especificado pelo usuário na caixa de `CPrintDialog` diálogo Imprimir e `m_pPD` é armazenado no objeto referenciado pelo membro. Se o usuário não especificou um valor, o padrão será a última página do documento.

## <a name="cprintinfom_bcontinueprinting"></a><a name="m_bcontinueprinting"></a>CPrintInfo::m_bContinuePrinting

Contém uma bandeira indicando se a estrutura deve continuar o loop de impressão.

### <a name="remarks"></a>Comentários

Se você estiver fazendo paginação em tempo de impressão, você `CView::OnPrepareDC` pode definir este membro como FALSE em sua substituição de uma vez que o fim do documento foi alcançado. Você não precisa modificar esta variável se você tiver especificado o comprimento do `SetMaxPage` documento no início do trabalho de impressão usando a função membro. O `m_bContinuePrinting` membro é uma variável pública do tipo BOOL.

## <a name="cprintinfom_bdirect"></a><a name="m_bdirect"></a>CPrintInfo::m_bDirect

O framework define este membro como TRUE se a caixa de diálogo Imprimir será contornada para impressão direta; FALSO de outra forma.

### <a name="remarks"></a>Comentários

A caixa de diálogo Imprimir é normalmente ignorada quando você imprime da concha ou quando a impressão é feita usando o ID_FILE_PRINT_DIRECT de id de comando.

Você normalmente não altera este membro, mas se você alterá-lo, altere-o antes de chamar [CView::DoPreparePrinting](../../mfc/reference/cview-class.md#doprepareprinting) em sua substituição de [CView::OnPreparePrinting](../../mfc/reference/cview-class.md#onprepareprinting).

## <a name="cprintinfom_bdocobject"></a><a name="m_bdocobject"></a>CPrintInfo::m_bDocObject

Contém um sinalizador indicando se o documento que está sendo impresso é um DocObject.

### <a name="remarks"></a>Comentários

Os `m_dwFlags` membros `m_nOffsetPage` dos dados são inválidos, a menos que esta bandeira seja VERDADEIRA.

## <a name="cprintinfom_bpreview"></a><a name="m_bpreview"></a>CPrintInfo::m_bPreview

Contém uma bandeira indicando se o documento está sendo visualizado.

### <a name="remarks"></a>Comentários

Isso é definido pela estrutura, dependendo do comando executado pelo usuário. A caixa de diálogo Imprimir não é exibida para um trabalho de visualização de impressão. O `m_bPreview` membro é uma variável pública do tipo BOOL.

## <a name="cprintinfom_dwflags"></a><a name="m_dwflags"></a>CPrintInfo::m_dwFlags

Contém uma combinação de sinalizadores especificando operações de impressão DocObject.

### <a name="remarks"></a>Comentários

Válido somente se `m_bDocObject` o membro de dados for TRUE.

As bandeiras podem ser um ou mais dos seguintes valores:

- PRINTFLAG_MAYBOTHERUSER

- PRINTFLAG_PROMPTUSER

- PRINTFLAG_USERMAYCHANGEPRINTER

- PRINTFLAG_RECOMPOSETODEVICE

- PRINTFLAG_DONTACTUALLYPRINT

- PRINTFLAG_FORCEPROPERTIES

- PRINTFLAG_PRINTTOFILE

## <a name="cprintinfom_lpuserdata"></a><a name="m_lpuserdata"></a>CPrintInfo::m_lpUserData

Contém um ponteiro para uma estrutura criada pelo usuário.

### <a name="remarks"></a>Comentários

Você pode usar isso para armazenar dados específicos de impressão que você não deseja armazenar em sua classe de exibição. O `m_lpUserData` membro é uma variável pública do tipo LPVOID.

## <a name="cprintinfom_ncurpage"></a><a name="m_ncurpage"></a>CPrintInfo::m_nCurPage

Contém o número da página atual.

### <a name="remarks"></a>Comentários

O framework `CView::OnPrepareDC` `CView::OnPrint` chama e uma vez para cada página do documento, especificando um valor diferente para este membro cada vez; seus valores variam do `GetFromPage` valor devolvido até `GetToPage`o devolvido por . Use este membro em `CView::OnPrepareDC` suas `CView::OnPrint` substituições e para imprimir a página especificada do documento.

Quando o modo de visualização é invocado pela primeira vez, a estrutura lê o valor deste membro para determinar qual página do documento deve ser visualizada inicialmente. Você pode definir o valor deste membro `CView::OnPreparePrinting` em sua substituição de manter a posição atual do usuário no documento ao entrar no modo de visualização. O `m_nCurPage` membro é uma variável pública do tipo UINT.

## <a name="cprintinfom_njobnumber"></a><a name="m_njobnumber"></a>CPrintInfo::m_nJobNumber

Indica o número de trabalho atribuído pelo sistema operacional para o trabalho de impressão atual.

### <a name="remarks"></a>Comentários

Esse valor pode ser SP_ERROR se o trabalho ainda não `CPrintInfo` foi impresso (ou seja, se o objeto é recém-construído e ainda não foi usado para imprimir), ou se houve um erro no início do trabalho.

## <a name="cprintinfom_nnumpreviewpages"></a><a name="m_nnumpreviewpages"></a>CPrintInfo::m_nNumPreviewPages

Contém o número de páginas exibidas no modo de visualização; pode ser 1 ou 2.

### <a name="remarks"></a>Comentários

O `m_nNumPreviewPages` membro é uma variável pública do tipo UINT.

## <a name="cprintinfom_noffsetpage"></a><a name="m_noffsetpage"></a>CPrintInfo::m_nOffsetPage

Contém o número de páginas que precedem a primeira página de um DocObject específico em um trabalho de impressão docObject combinado.

## <a name="cprintinfom_ppd"></a><a name="m_ppd"></a>CPrintInfo::m_pPD

Contém um ponteiro `CPrintDialog` para o objeto usado para exibir a caixa de diálogo Imprimir para o trabalho de impressão.

### <a name="remarks"></a>Comentários

O `m_pPD` membro é uma variável pública `CPrintDialog`declarada como um ponteiro para .

## <a name="cprintinfom_rectdraw"></a><a name="m_rectdraw"></a>CPrintInfo::m_rectDraw

Especifica a área de desenho utilizável da página em coordenadas lógicas.

### <a name="remarks"></a>Comentários

Você pode querer se referir a `CView::OnPrint`isso em sua substituição de . Você pode usar este membro para acompanhar qual área permanece utilizável depois de imprimir cabeçalhos, rodapés e assim por diante. O `m_rectDraw` membro é uma `CRect`variável pública do tipo .

## <a name="cprintinfom_strpagedesc"></a><a name="m_strpagedesc"></a>CPrintInfo::m_strPageDesc

Contém uma seqüência de formato usada para exibir os números da página durante a visualização de impressão; esta seqüência consiste em duas substrings, uma para exibição de uma página e outra para exibição de duas páginas, cada uma terminada por um caractere '\n'.

### <a name="remarks"></a>Comentários

A estrutura usa "Page %u\nPages %u-%u\n" como o valor padrão. Se você quiser um formato diferente para os números da `CView::OnPreparePrinting`página, especifique uma seqüência de formato satisfaz a substituição de . O `m_strPageDesc` membro é uma `CString`variável pública do tipo .

## <a name="cprintinfosetmaxpage"></a><a name="setmaxpage"></a>CPrintInfo::SetmaxPage

Ligue para esta função para especificar o número da última página do documento.

```
void SetMaxPage(UINT nMaxPage);
```

### <a name="parameters"></a>Parâmetros

*nMaxPage*<br/>
Número da última página do documento.

### <a name="remarks"></a>Comentários

Este valor é `CPrintDialog` armazenado no objeto `m_pPD` referenciado pelo membro. Se o comprimento do documento for conhecido antes de ser impresso, `CView::OnPreparePrinting`chame esta função a partir de sua substituição de . Se o comprimento do documento depender de uma configuração especificada pelo usuário na caixa `CView::OnBeginPrinting`de diálogo Imprimir, chame esta função a partir da substituição de . Se o comprimento do documento não for conhecido até `m_bContinuePrinting` que seja impresso, use o membro para controlar o loop de impressão.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CView::OnPreparePrinting](../../mfc/reference/cview-class.md#onprepareprinting).

## <a name="cprintinfosetminpage"></a><a name="setminpage"></a>CPrintInfo::SetMinPage

Ligue para esta função para especificar o número da primeira página do documento.

```
void SetMinPage(UINT nMinPage);
```

### <a name="parameters"></a>Parâmetros

*nMinPage*<br/>
Número da primeira página do documento.

### <a name="remarks"></a>Comentários

Os números das páginas normalmente começam em 1. Este valor é `CPrintDialog` armazenado no objeto `m_pPD` referenciado pelo membro.

## <a name="see-also"></a>Confira também

[Amostra de MFC DIBLOOK](../../overview/visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Cview::OnBeginPrinting](../../mfc/reference/cview-class.md#onbeginprinting)<br/>
[CView::OnEndPrinting](../../mfc/reference/cview-class.md#onendprinting)<br/>
[CView::OnendPrintPreview](../../mfc/reference/cview-class.md#onendprintpreview)<br/>
[CView::OnPrepareDC](../../mfc/reference/cview-class.md#onpreparedc)<br/>
[CView::OnPreparePrinting](../../mfc/reference/cview-class.md#onprepareprinting)<br/>
[CView::OnPrint](../../mfc/reference/cview-class.md#onprint)
