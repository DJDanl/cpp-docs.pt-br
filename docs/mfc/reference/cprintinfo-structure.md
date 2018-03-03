---
title: Estrutura CPrintInfo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CPrintInfo
dev_langs:
- C++
helpviewer_keywords:
- CPrintInfo structure [MFC]
ms.assetid: 0b3de849-d050-4386-9a14-f4c1a25684f7
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4943554e67d43b6dc1652a984a0e758af9d6951b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
|[CPrintInfo::GetFromPage](#getfrompage)|Retorna o número da primeira página seja impresso.|  
|[CPrintInfo::GetMaxPage](#getmaxpage)|Retorna o número da última página do documento.|  
|[CPrintInfo::GetMinPage](#getminpage)|Retorna o número da primeira página do documento.|  
|[CPrintInfo::GetOffsetPage](#getoffsetpage)|Retorna o número de páginas anteriores a primeira página de um item de DocObject seja impresso em um trabalho de impressão DocObject combinado.|  
|[CPrintInfo::GetToPage](#gettopage)|Retorna o número da última página seja impresso.|  
|[CPrintInfo::SetMaxPage](#setmaxpage)|Define o número da última página do documento.|  
|[CPrintInfo::SetMinPage](#setminpage)|Define o número da primeira página do documento.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPrintInfo::m_bContinuePrinting](#m_bcontinueprinting)|Contém um sinalizador que indica se a estrutura deve continuar o loop de impressão.|  
|[CPrintInfo::m_bDirect](#m_bdirect)|Contém um sinalizador que indica se o documento está sendo impressa diretamente (sem exibir a caixa de diálogo de impressão).|  
|[CPrintInfo::m_bDocObject](#m_bdocobject)|Contém um sinalizador que indica se o documento que está sendo impresso é um DocObject.|  
|[CPrintInfo::m_bPreview](#m_bpreview)|Contém um sinalizador que indica se o documento está sendo visualizado.|  
|[CPrintInfo::m_dwFlags](#m_dwflags)|Especifica as operações de impressão DocObject.|  
|[CPrintInfo::m_lpUserData](#m_lpuserdata)|Contém um ponteiro para uma estrutura criada pelo usuário.|  
|[CPrintInfo::m_nCurPage](#m_ncurpage)|Identifica o número da página que está sendo impressa no momento.|  
|[CPrintInfo::m_nJobNumber](#m_njobnumber)|Especifica o número de trabalho atribuído pelo sistema operacional para o trabalho de impressão atual|  
|[CPrintInfo::m_nNumPreviewPages](#m_nnumpreviewpages)|Identifica o número de páginas exibidas na janela de visualização. 1 ou 2.|  
|[CPrintInfo::m_nOffsetPage](#m_noffsetpage)|Especifica o deslocamento da primeira página de um determinado DocObject em um trabalho de impressão DocObject combinado.|  
|[CPrintInfo::m_pPD](#m_ppd)|Contém um ponteiro para o `CPrintDialog` objeto usado para a caixa de diálogo de impressão.|  
|[CPrintInfo::m_rectDraw](#m_rectdraw)|Especifica um retângulo definindo a área utilizável da página atual.|  
|[CPrintInfo::m_strPageDesc](#m_strpagedesc)|Contém uma cadeia de caracteres de formato para exibição de número de página.|  
  
## <a name="remarks"></a>Comentários  
 `CPrintInfo`é uma estrutura e não tem uma classe base.  
  
 A estrutura cria um objeto de `CPrintInfo` cada vez que a impressão ou o comando Visualizar impressão é escolhido e destrói a ele quando o comando for concluído.  
  
 `CPrintInfo`contém informações sobre o trabalho de impressão como um todo, como o intervalo de páginas a serem impressas e o status atual do trabalho de impressão, como a página está sendo impressa no momento. Algumas informações são armazenadas em um tipo de [CPrintDialog](../../mfc/reference/cprintdialog-class.md) objeto; este objeto contém os valores inseridos pelo usuário na caixa de diálogo Imprimir.  
  
 Um `CPrintInfo` objeto transmitido entre a estrutura e a classe de exibição durante o processo de impressão e é usado para trocar informações entre os dois. Por exemplo, a estrutura informa a classe de exibição que página do documento para impressão, atribuindo um valor para o `m_nCurPage` membro do `CPrintInfo`; o modo de exibição recupera o valor de classe e executa a impressão real da página especificada.  
  
 Outro exemplo é o caso em que o tamanho do documento não é conhecido até ele ser impresso. Nessa situação, a classe de exibição testa o fim do documento sempre que uma página é impresso. Quando é atingido o fim, define a classe de exibição de `m_bContinuePrinting` membro do `CPrintInfo` para **FALSE**; isso informa a estrutura para interromper o loop de impressão.  
  
 `CPrintInfo`é usado pelas funções de membro de `CView` listadas em "Consulte também". Para obter mais informações sobre a arquitetura de impressão fornecida pela biblioteca Microsoft Foundation Class, consulte [janelas com moldura](../../mfc/frame-windows.md) e [arquitetura de documento/exibição](../../mfc/document-view-architecture.md) e os artigos [ Imprimindo](../../mfc/printing.md) e [impressão: documentos Multipágina](../../mfc/multipage-documents.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CPrintInfo`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxext.h  
  
##  <a name="getfrompage"></a>CPrintInfo::GetFromPage  
 Chame essa função para recuperar o número da primeira página a ser impressa.  
  
```  
UINT GetFromPage() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número da primeira página a ser impressa.  
  
### <a name="remarks"></a>Comentários  
 Esse é o valor especificado pelo usuário na caixa de diálogo de impressão e ele é armazenado na `CPrintDialog` objeto referenciado pelo `m_pPD` membro. Se o usuário não tiver especificado um valor, o padrão é a primeira página do documento.  
  
##  <a name="getmaxpage"></a>CPrintInfo::GetMaxPage  
 Chame essa função para recuperar o número da última página do documento.  
  
```  
UINT GetMaxPage() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número da última página do documento.  
  
### <a name="remarks"></a>Comentários  
 Esse valor é armazenado no `CPrintDialog` objeto referenciado pelo `m_pPD` membro.  
  
##  <a name="getminpage"></a>CPrintInfo::GetMinPage  
 Chame essa função para recuperar o número da primeira página do documento.  
  
```  
UINT GetMinPage() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número da primeira página do documento.  
  
### <a name="remarks"></a>Comentários  
 Esse valor é armazenado no `CPrintDialog` objeto referenciado pelo `m_pPD` membro.  
  
##  <a name="getoffsetpage"></a>CPrintInfo::GetOffsetPage  
 Chame essa função para recuperar o deslocamento quando vários itens DocObject de impressão de um cliente DocObject.  
  
```  
UINT GetOffsetPage() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de páginas que precede a primeira página de um item de DocObject seja impresso em um trabalho de impressão DocObject combinado.  
  
### <a name="remarks"></a>Comentários  
 Esse valor é referenciado pelo **m_nOffsetPage** membro. A primeira página do documento será numerada o **m_nOffsetPage** valor + 1 quando impresso como um DocObject com outros documentos ativos. O **m_nOffsetPage** membro é válido somente se o **m_bDocObject** valor é **TRUE**.  
  
##  <a name="gettopage"></a>CPrintInfo::GetToPage  
 Chame essa função para recuperar o número da última página a ser impressa.  
  
```  
UINT GetToPage() const;

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número da última página a ser impressa.  
  
### <a name="remarks"></a>Comentários  
 Esse é o valor especificado pelo usuário na caixa de diálogo de impressão e ele é armazenado na `CPrintDialog` objeto referenciado pelo `m_pPD` membro. Se o usuário não tiver especificado um valor, o padrão é a última página do documento.  
  
##  <a name="m_bcontinueprinting"></a>CPrintInfo::m_bContinuePrinting  
 Contém um sinalizador que indica se a estrutura deve continuar o loop de impressão.  
  
### <a name="remarks"></a>Comentários  
 Se você estiver fazendo a paginação de tempo de impressão, você pode definir esse membro como **FALSE** em sua substituição de `CView::OnPrepareDC` após o fim do documento foi atingido. Você não precisa modificar essa variável se você tiver especificado o tamanho do documento no início do trabalho de impressão usando o `SetMaxPage` função de membro. O `m_bContinuePrinting` membro é uma variável pública do tipo **BOOL**.  
  
##  <a name="m_bdirect"></a>CPrintInfo::m_bDirect  
 A estrutura define esse membro como **TRUE** se a caixa de diálogo Imprimir será ignorada para impressão direta; **FALSE** caso contrário.  
  
### <a name="remarks"></a>Comentários  
 A caixa de diálogo de impressão normalmente é ignorada quando você imprime do shell ou quando a impressão é feita usando a ID de comando **ID_FILE_PRINT_DIRECT**.  
  
 Você normalmente não altere esse membro, mas se você alterá-lo, alterá-lo antes de você chamada [CView::DoPreparePrinting](../../mfc/reference/cview-class.md#doprepareprinting) em sua substituição de [CView::OnPreparePrinting](../../mfc/reference/cview-class.md#onprepareprinting).  
  
##  <a name="m_bdocobject"></a>CPrintInfo::m_bDocObject  
 Contém um sinalizador que indica se o documento que está sendo impresso é um DocObject.  
  
### <a name="remarks"></a>Comentários  
 Membros de dados `m_dwFlags` e **m_nOffsetPage** são inválidos, a menos que esse sinalizador é **TRUE**.  
  
##  <a name="m_bpreview"></a>CPrintInfo::m_bPreview  
 Contém um sinalizador que indica se o documento está sendo visualizado.  
  
### <a name="remarks"></a>Comentários  
 Isso é definido pela estrutura dependendo de qual executar o comando do usuário. A caixa de diálogo de impressão não é exibida para um trabalho de visualização de impressão. O **m_bPreview** membro é uma variável pública do tipo **BOOL**.  
  
##  <a name="m_dwflags"></a>CPrintInfo::m_dwFlags  
 Contém uma combinação de sinalizadores que especificam as operações de impressão DocObject.  
  
### <a name="remarks"></a>Comentários  
 Válido somente se o membro de dados **m_bDocObject** é **TRUE**.  
  
 Os sinalizadores podem ser um ou mais dos seguintes valores:  
  
- **PRINTFLAG_MAYBOTHERUSER**  
  
- **PRINTFLAG_PROMPTUSER**  
  
- **PRINTFLAG_USERMAYCHANGEPRINTER**  
  
- **PRINTFLAG_RECOMPOSETODEVICE**  
  
- **PRINTFLAG_DONTACTUALLYPRINT**  
  
- **PRINTFLAG_FORCEPROPERTIES**  
  
- **PRINTFLAG_PRINTTOFILE**  
  
##  <a name="m_lpuserdata"></a>CPrintInfo::m_lpUserData  
 Contém um ponteiro para uma estrutura criada pelo usuário.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar isso para armazenar dados de impressão específicos que você não deseja armazenar em sua classe de exibição. O **m_lpUserData** membro é uma variável pública do tipo **LPVOID**.  
  
##  <a name="m_ncurpage"></a>CPrintInfo::m_nCurPage  
 Contém o número da página atual.  
  
### <a name="remarks"></a>Comentários  
 A estrutura chama `CView::OnPrepareDC` e `CView::OnPrint` uma vez para cada página do documento, especificando um valor diferente para este membro de cada vez; seus valores de intervalo do valor retornado por `GetFromPage` àquele retornado por `GetToPage`. Use este membro suas substituições de `CView::OnPrepareDC` e `CView::OnPrint` para imprimir a página especificada do documento.  
  
 Quando o modo de visualização é invocado pela primeira vez, o framework lê o valor desse membro para determinar qual página do documento deve ser visualizada inicialmente. Você pode definir o valor desse membro em sua substituição de `CView::OnPreparePrinting` para manter a posição atual do usuário no documento ao inserir o modo de visualização. O `m_nCurPage` membro é uma variável pública do tipo **UINT**.  
  
##  <a name="m_njobnumber"></a>CPrintInfo::m_nJobNumber  
 Indica o número de trabalho atribuído pelo sistema operacional para o trabalho de impressão atual.  
  
### <a name="remarks"></a>Comentários  
 Esse valor pode ser **SP_ERROR** se o trabalho ainda não foi impresso (ou seja, se o `CPrintInfo` objeto é construído recentemente e ainda não foi usado para imprimir), ou se ocorreu um erro ao iniciar o trabalho.  
  
##  <a name="m_nnumpreviewpages"></a>CPrintInfo::m_nNumPreviewPages  
 Contém o número de páginas exibidas no modo de visualização; ele pode ser 1 ou 2.  
  
### <a name="remarks"></a>Comentários  
 O **m_nNumPreviewPages** membro é uma variável pública do tipo **UINT**.  
  
##  <a name="m_noffsetpage"></a>CPrintInfo::m_nOffsetPage  
 Contém o número de páginas que precedem a primeira página de um determinado DocObject em um trabalho de impressão DocObject combinado.  
  
##  <a name="m_ppd"></a>CPrintInfo::m_pPD  
 Contém um ponteiro para o `CPrintDialog` objeto usado para exibir a caixa de diálogo de impressão para o trabalho de impressão.  
  
### <a name="remarks"></a>Comentários  
 O `m_pPD` membro é uma variável pública declarada como um ponteiro para `CPrintDialog`.  
  
##  <a name="m_rectdraw"></a>CPrintInfo::m_rectDraw  
 Especifica a área de desenho utilizável da página em coordenadas lógicas.  
  
### <a name="remarks"></a>Comentários  
 Talvez você queira consulte isso na sua substituição de `CView::OnPrint`. Você pode usar este membro para controlar qual área permaneça usável depois que você imprimir cabeçalhos, rodapés e assim por diante. O **m_rectDraw** membro é uma variável pública do tipo `CRect`.  
  
##  <a name="m_strpagedesc"></a>CPrintInfo::m_strPageDesc  
 Contém uma cadeia de caracteres de formato usada para exibir os números de página durante a visualização da impressão. Essa cadeia de caracteres consiste em dois subcadeias de caracteres, uma para exibição de página única e outra para a exibição de página dupla, cada terminada por um caractere '\n'.  
  
### <a name="remarks"></a>Comentários  
 A estrutura usa "Página %u\nPages % u-%u\n" como o valor padrão. Se você quiser um formato diferente para os números de página, especifique uma cadeia de caracteres de formato em sua substituição de `CView::OnPreparePrinting`. O **m_strPageDesc** membro é uma variável pública do tipo `CString`.  
  
##  <a name="setmaxpage"></a>CPrintInfo::SetMaxPage  
 Chame essa função para especificar o número da última página do documento.  
  
```  
void SetMaxPage(UINT nMaxPage);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nMaxPage*  
 Número da última página do documento.  
  
### <a name="remarks"></a>Comentários  
 Esse valor é armazenado no `CPrintDialog` objeto referenciado pelo `m_pPD` membro. Se o tamanho do documento é conhecido antes que ele seja impresso, chamar essa função de sua substituição de `CView::OnPreparePrinting`. Se o tamanho do documento depende de uma configuração especificada pelo usuário na caixa de diálogo Imprimir, chamar essa função de sua substituição de `CView::OnBeginPrinting`. Se o tamanho do documento não é conhecido até ele ser impresso, use o `m_bContinuePrinting` membro para controlar o loop de impressão.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CView::OnPreparePrinting](../../mfc/reference/cview-class.md#onprepareprinting).  
  
##  <a name="setminpage"></a>CPrintInfo::SetMinPage  
 Chame essa função para especificar o número da primeira página do documento.  
  
```  
void SetMinPage(UINT nMinPage);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nMinPage*  
 Número da primeira página do documento.  
  
### <a name="remarks"></a>Comentários  
 Números de página normalmente começam em 1. Esse valor é armazenado no `CPrintDialog` objeto referenciado pelo `m_pPD` membro.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC DIBLOOK](../../visual-cpp-samples.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [CView::OnBeginPrinting](../../mfc/reference/cview-class.md#onbeginprinting)   
 [CView::OnEndPrinting](../../mfc/reference/cview-class.md#onendprinting)   
 [CView::OnEndPrintPreview](../../mfc/reference/cview-class.md#onendprintpreview)   
 [CView::OnPrepareDC](../../mfc/reference/cview-class.md#onpreparedc)   
 [CView::OnPreparePrinting](../../mfc/reference/cview-class.md#onprepareprinting)   
 [CView::OnPrint](../../mfc/reference/cview-class.md#onprint)



