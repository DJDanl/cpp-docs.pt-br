---
title: Estrutura CPrintInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CPrintInfo
dev_langs:
- C++
helpviewer_keywords:
- CPrintInfo structure [MFC]
ms.assetid: 0b3de849-d050-4386-9a14-f4c1a25684f7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b12c93375618cacf25e88ecba6919808ac7bd705
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46446849"
---
# <a name="cprintinfo-structure"></a>Estrutura CPrintInfo

Armazena informações sobre um trabalho de impressão ou visualização de impressão.

## <a name="syntax"></a>Sintaxe

```
struct CPrintInfo
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPrintInfo::GetFromPage](#getfrompage)|Retorna o número da primeira página que está sendo impresso.|
|[CPrintInfo::GetMaxPage](#getmaxpage)|Retorna o número da última página do documento.|
|[CPrintInfo::GetMinPage](#getminpage)|Retorna o número da primeira página do documento.|
|[CPrintInfo::GetOffsetPage](#getoffsetpage)|Retorna o número das páginas que precede a primeira página de um item de DocObject que está sendo impressa em um trabalho de impressão DocObject combinado.|
|[CPrintInfo::GetToPage](#gettopage)|Retorna o número da última página que está sendo impresso.|
|[CPrintInfo::SetMaxPage](#setmaxpage)|Define o número da última página do documento.|
|[CPrintInfo::SetMinPage](#setminpage)|Define o número da primeira página do documento.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CPrintInfo::m_bContinuePrinting](#m_bcontinueprinting)|Contém um sinalizador que indica se a estrutura deve continuar o loop de impressão.|
|[CPrintInfo::m_bDirect](#m_bdirect)|Contém um sinalizador que indica se o documento está sendo impresso diretamente (sem exibir a caixa de diálogo de impressão).|
|[CPrintInfo::m_bDocObject](#m_bdocobject)|Contém um sinalizador que indica se o documento que está sendo impresso é DocObject.|
|[CPrintInfo::m_bPreview](#m_bpreview)|Contém um sinalizador que indica se o documento está sendo visualizado.|
|[CPrintInfo::m_dwFlags](#m_dwflags)|Especifica as operações de impressão DocObject.|
|[CPrintInfo::m_lpUserData](#m_lpuserdata)|Contém um ponteiro para uma estrutura criada pelo usuário.|
|[CPrintInfo::m_nCurPage](#m_ncurpage)|Identifica o número da página que está sendo impresso.|
|[CPrintInfo::m_nJobNumber](#m_njobnumber)|Especifica o número de trabalho atribuído pelo sistema operacional para o trabalho de impressão atual|
|[CPrintInfo::m_nNumPreviewPages](#m_nnumpreviewpages)|Identifica o número de páginas exibidas na janela de visualização. 1 ou 2.|
|[CPrintInfo::m_nOffsetPage](#m_noffsetpage)|Especifica o deslocamento da primeira página do DocObject específico em um trabalho de impressão DocObject combinado.|
|[CPrintInfo::m_pPD](#m_ppd)|Contém um ponteiro para o `CPrintDialog` objeto usado para a caixa de diálogo de impressão.|
|[CPrintInfo::m_rectDraw](#m_rectdraw)|Especifica um retângulo que define a área utilizável da página atual.|
|[CPrintInfo::m_strPageDesc](#m_strpagedesc)|Contém uma cadeia de caracteres de formato para exibição do número de página.|

## <a name="remarks"></a>Comentários

`CPrintInfo` é uma estrutura e não tem uma classe base.

A estrutura cria um objeto do `CPrintInfo` cada vez que a impressão ou o comando Visualizar impressão é escolhido e destrói a ele quando o comando for concluído.

`CPrintInfo` contém informações sobre o trabalho de impressão como um todo, como o intervalo de páginas a serem impressos e o status atual do trabalho de impressão, como a página que está sendo impresso. Algumas informações são armazenadas em um associado [CPrintDialog](../../mfc/reference/cprintdialog-class.md) do objeto; esse objeto contém os valores inseridos pelo usuário na caixa de diálogo Imprimir.

Um `CPrintInfo` objeto é passado entre a estrutura e sua classe de exibição durante o processo de impressão e é usado para trocar informações entre os dois. Por exemplo, o framework informa à classe de exibição qual página de documento para impressão, atribuindo um valor para o `m_nCurPage` membro do `CPrintInfo`; a exibição de classe recupera o valor e faz a impressão real da página especificada.

Outro exemplo é o caso em que o tamanho do documento não é conhecido até que ele é impresso. Nessa situação, a classe de exibição testa o final do documento sempre que uma página é impressa. Quando o final for atingido, a classe de exibição define a `m_bContinuePrinting` membro do `CPrintInfo` como falso; isso informa a estrutura para interromper o loop de impressão.

`CPrintInfo` é usado pelas funções membro de `CView` listado em "ver também." Para obter mais informações sobre a arquitetura de impressão fornecida pela biblioteca de classes Microsoft Foundation, consulte [Windows quadro](../../mfc/frame-windows.md) e [arquitetura de documento/exibição](../../mfc/document-view-architecture.md) e os artigos [ Imprimindo](../../mfc/printing.md) e [imprimindo: documentos Multipágina](../../mfc/multipage-documents.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CPrintInfo`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxext.h

##  <a name="getfrompage"></a>  CPrintInfo::GetFromPage

Chame essa função para recuperar o número da primeira página a ser impresso.

```
UINT GetFromPage() const;


```

### <a name="return-value"></a>Valor de retorno

O número da primeira página a ser impresso.

### <a name="remarks"></a>Comentários

Esse é o valor especificado pelo usuário na caixa de diálogo Imprimir, e ele é armazenado na `CPrintDialog` objeto referenciado pelo `m_pPD` membro. Se o usuário não tiver especificado um valor, o padrão é a primeira página do documento.

##  <a name="getmaxpage"></a>  CPrintInfo::GetMaxPage

Chame essa função para recuperar o número da última página do documento.

```
UINT GetMaxPage() const;


```

### <a name="return-value"></a>Valor de retorno

O número da última página do documento.

### <a name="remarks"></a>Comentários

Esse valor é armazenado na `CPrintDialog` objeto referenciado pelo `m_pPD` membro.

##  <a name="getminpage"></a>  CPrintInfo::GetMinPage

Chame essa função para recuperar o número da primeira página do documento.

```
UINT GetMinPage() const;


```

### <a name="return-value"></a>Valor de retorno

O número da primeira página do documento.

### <a name="remarks"></a>Comentários

Esse valor é armazenado na `CPrintDialog` objeto referenciado pelo `m_pPD` membro.

##  <a name="getoffsetpage"></a>  CPrintInfo::GetOffsetPage

Chame essa função para recuperar o deslocamento ao imprimir vários DocObject itens de um cliente DocObject.

```
UINT GetOffsetPage() const;


```

### <a name="return-value"></a>Valor de retorno

O número de páginas que precede a primeira página de um item de DocObject que está sendo impressa em um trabalho de impressão DocObject combinado.

### <a name="remarks"></a>Comentários

Esse valor é referenciado pelo `m_nOffsetPage` membro. A primeira página do documento será numerada o `m_nOffsetPage` valor + 1 quando impresso como DocObject com outros documentos do Active Directory. O `m_nOffsetPage` membro é válido somente se o `m_bDocObject` valor é TRUE.

##  <a name="gettopage"></a>  CPrintInfo::GetToPage

Chame essa função para recuperar o número da última página a ser impresso.

```
UINT GetToPage() const;


```

### <a name="return-value"></a>Valor de retorno

O número da última página a ser impresso.

### <a name="remarks"></a>Comentários

Esse é o valor especificado pelo usuário na caixa de diálogo Imprimir, e ele é armazenado na `CPrintDialog` objeto referenciado pelo `m_pPD` membro. Se o usuário não tiver especificado um valor, o padrão é a última página do documento.

##  <a name="m_bcontinueprinting"></a>  CPrintInfo::m_bContinuePrinting

Contém um sinalizador que indica se a estrutura deve continuar o loop de impressão.

### <a name="remarks"></a>Comentários

Se você estiver fazendo a paginação de tempo de impressão, você pode definir esse membro como FALSE em seu substituto do `CView::OnPrepareDC` depois que você atingiu o final do documento. Você não precisa modificar essa variável se você tiver especificado o tamanho do documento no início do trabalho de impressão usando o `SetMaxPage` função de membro. O `m_bContinuePrinting` membro é uma variável pública do tipo BOOL.

##  <a name="m_bdirect"></a>  CPrintInfo::m_bDirect

A estrutura define esse membro como TRUE se a caixa de diálogo de impressão será ignorada para impressão direta; FALSE caso contrário.

### <a name="remarks"></a>Comentários

A caixa de diálogo de impressão normalmente é ignorada quando você imprime do shell ou quando a impressão é feita usando o comando ID_FILE_PRINT_DIRECT ID.

Você normalmente não altere esse membro, mas se você alterá-lo, alterá-lo antes de chamada [CView::DoPreparePrinting](../../mfc/reference/cview-class.md#doprepareprinting) em seu substituto do [CView::OnPreparePrinting](../../mfc/reference/cview-class.md#onprepareprinting).

##  <a name="m_bdocobject"></a>  CPrintInfo::m_bDocObject

Contém um sinalizador que indica se o documento que está sendo impresso é DocObject.

### <a name="remarks"></a>Comentários

Membros de dados `m_dwFlags` e `m_nOffsetPage` são inválidas, a menos que esse sinalizador é verdadeiro.

##  <a name="m_bpreview"></a>  CPrintInfo::m_bPreview

Contém um sinalizador que indica se o documento está sendo visualizado.

### <a name="remarks"></a>Comentários

Isso é definido pela estrutura, dependendo de qual lugar do comando executado. A caixa de diálogo de impressão não é exibida para um trabalho de visualização de impressão. O `m_bPreview` membro é uma variável pública do tipo BOOL.

##  <a name="m_dwflags"></a>  CPrintInfo::m_dwFlags

Contém uma combinação de sinalizadores que especificam as operações de impressão DocObject.

### <a name="remarks"></a>Comentários

Válido somente se o membro de dados `m_bDocObject` é TRUE.

Os sinalizadores de podem ser um ou mais dos seguintes valores:

- PRINTFLAG_MAYBOTHERUSER

- PRINTFLAG_PROMPTUSER

- PRINTFLAG_USERMAYCHANGEPRINTER

- PRINTFLAG_RECOMPOSETODEVICE

- PRINTFLAG_DONTACTUALLYPRINT

- PRINTFLAG_FORCEPROPERTIES

- PRINTFLAG_PRINTTOFILE

##  <a name="m_lpuserdata"></a>  CPrintInfo::m_lpUserData

Contém um ponteiro para uma estrutura criada pelo usuário.

### <a name="remarks"></a>Comentários

Você pode usar isso para armazenar dados específicos de impressão que você não deseja armazenar em sua classe de exibição. O `m_lpUserData` membro é uma variável pública do tipo LPVOID.

##  <a name="m_ncurpage"></a>  CPrintInfo::m_nCurPage

Contém o número da página atual.

### <a name="remarks"></a>Comentários

A estrutura chama `CView::OnPrepareDC` e `CView::OnPrint` uma vez para cada página do documento, especificando um valor diferente para este membro sempre; seus valores de intervalo do valor retornado por `GetFromPage` àquele retornado por `GetToPage`. Use esse membro nas suas substituições de `CView::OnPrepareDC` e `CView::OnPrint` para imprimir a página especificada do documento.

Quando o modo de visualização é invocado pela primeira vez, o framework lê o valor desse membro para determinar qual página do documento deve ser visualizada inicialmente. Você pode definir o valor desse membro em seu substituto do `CView::OnPreparePrinting` para manter a posição atual do usuário no documento ao inserir o modo de visualização. O `m_nCurPage` membro é uma variável pública do tipo UINT.

##  <a name="m_njobnumber"></a>  CPrintInfo::m_nJobNumber

Indica o número atribuído pelo sistema operacional para o trabalho de impressão atual.

### <a name="remarks"></a>Comentários

Esse valor pode ser SP_ERROR se o trabalho ainda não foi impresso (ou seja, se o `CPrintInfo` objeto é construído recentemente e ainda não foi usado para imprimir), ou se ocorreu um erro ao iniciar o trabalho.

##  <a name="m_nnumpreviewpages"></a>  CPrintInfo::m_nNumPreviewPages

Contém o número de páginas exibidas no modo de visualização; ele pode ser 1 ou 2.

### <a name="remarks"></a>Comentários

O `m_nNumPreviewPages` membro é uma variável pública do tipo UINT.

##  <a name="m_noffsetpage"></a>  CPrintInfo::m_nOffsetPage

Contém o número de páginas que precede a primeira página do DocObject específico em um trabalho de impressão DocObject combinado.

##  <a name="m_ppd"></a>  CPrintInfo::m_pPD

Contém um ponteiro para o `CPrintDialog` objeto usado para exibir a caixa de diálogo de impressão para o trabalho de impressão.

### <a name="remarks"></a>Comentários

O `m_pPD` membro é uma variável pública declarada como um ponteiro para `CPrintDialog`.

##  <a name="m_rectdraw"></a>  CPrintInfo::m_rectDraw

Especifica a área de desenho utilizável da página em coordenadas lógicas.

### <a name="remarks"></a>Comentários

Você talvez queira consultar a isso em seu substituto do `CView::OnPrint`. Você pode usar esse membro para controlar qual área permaneça utilizável depois que você imprimir cabeçalhos, rodapés e assim por diante. O `m_rectDraw` membro é uma variável pública do tipo `CRect`.

##  <a name="m_strpagedesc"></a>  CPrintInfo::m_strPageDesc

Contém uma cadeia de caracteres de formato usada para exibir os números de página durante a visualização de impressão; Essa cadeia de caracteres consiste em duas subcadeias de caracteres, um para a exibição de página única e outra para a exibição de página dupla, cada terminada por um caractere '\n'.

### <a name="remarks"></a>Comentários

A estrutura usa a "Página %u\nPages % u-%u\n" como o valor padrão. Se você quiser um formato diferente para os números de página, especifique uma cadeia de caracteres de formato em seu substituto do `CView::OnPreparePrinting`. O `m_strPageDesc` membro é uma variável pública do tipo `CString`.

##  <a name="setmaxpage"></a>  CPrintInfo::SetMaxPage

Chame essa função para especificar o número da última página do documento.

```
void SetMaxPage(UINT nMaxPage);
```

### <a name="parameters"></a>Parâmetros

*nMaxPage*<br/>
Número da última página do documento.

### <a name="remarks"></a>Comentários

Esse valor é armazenado na `CPrintDialog` objeto referenciado pelo `m_pPD` membro. Se o tamanho do documento é conhecido antes que ele seja impresso, chame essa função de sua substituição do `CView::OnPreparePrinting`. Se o tamanho do documento depende de uma configuração especificada pelo usuário na caixa de diálogo Imprimir, chame essa função de sua substituição do `CView::OnBeginPrinting`. Se o tamanho do documento não é conhecido até que ele é impresso, use o `m_bContinuePrinting` membro para controlar o loop de impressão.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CView::OnPreparePrinting](../../mfc/reference/cview-class.md#onprepareprinting).

##  <a name="setminpage"></a>  CPrintInfo::SetMinPage

Chame essa função para especificar o número da primeira página do documento.

```
void SetMinPage(UINT nMinPage);
```

### <a name="parameters"></a>Parâmetros

*nMinPage*<br/>
Número da primeira página do documento.

### <a name="remarks"></a>Comentários

Números de página normalmente começam em 1. Esse valor é armazenado na `CPrintDialog` objeto referenciado pelo `m_pPD` membro.

## <a name="see-also"></a>Consulte também

[Exemplo MFC DIBLOOK](../../visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[CView::OnBeginPrinting](../../mfc/reference/cview-class.md#onbeginprinting)<br/>
[CView::OnEndPrinting](../../mfc/reference/cview-class.md#onendprinting)<br/>
[CView::OnEndPrintPreview](../../mfc/reference/cview-class.md#onendprintpreview)<br/>
[CView::OnPrepareDC](../../mfc/reference/cview-class.md#onpreparedc)<br/>
[CView::OnPreparePrinting](../../mfc/reference/cview-class.md#onprepareprinting)<br/>
[CView::OnPrint](../../mfc/reference/cview-class.md#onprint)



