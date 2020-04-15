---
title: Classe CRichEditView
ms.date: 11/04/2016
f1_keywords:
- CRichEditView
- AFXRICH/CRichEditView
- AFXRICH/CRichEditView::CRichEditView
- AFXRICH/CRichEditView::AdjustDialogPosition
- AFXRICH/CRichEditView::CanPaste
- AFXRICH/CRichEditView::DoPaste
- AFXRICH/CRichEditView::FindText
- AFXRICH/CRichEditView::FindTextSimple
- AFXRICH/CRichEditView::GetCharFormatSelection
- AFXRICH/CRichEditView::GetDocument
- AFXRICH/CRichEditView::GetInPlaceActiveItem
- AFXRICH/CRichEditView::GetMargins
- AFXRICH/CRichEditView::GetPageRect
- AFXRICH/CRichEditView::GetPaperSize
- AFXRICH/CRichEditView::GetParaFormatSelection
- AFXRICH/CRichEditView::GetPrintRect
- AFXRICH/CRichEditView::GetPrintWidth
- AFXRICH/CRichEditView::GetRichEditCtrl
- AFXRICH/CRichEditView::GetSelectedItem
- AFXRICH/CRichEditView::GetTextLength
- AFXRICH/CRichEditView::GetTextLengthEx
- AFXRICH/CRichEditView::InsertFileAsObject
- AFXRICH/CRichEditView::InsertItem
- AFXRICH/CRichEditView::IsRichEditFormat
- AFXRICH/CRichEditView::OnCharEffect
- AFXRICH/CRichEditView::OnParaAlign
- AFXRICH/CRichEditView::OnUpdateCharEffect
- AFXRICH/CRichEditView::OnUpdateParaAlign
- AFXRICH/CRichEditView::PrintInsideRect
- AFXRICH/CRichEditView::PrintPage
- AFXRICH/CRichEditView::SetCharFormat
- AFXRICH/CRichEditView::SetMargins
- AFXRICH/CRichEditView::SetPaperSize
- AFXRICH/CRichEditView::SetParaFormat
- AFXRICH/CRichEditView::TextNotFound
- AFXRICH/CRichEditView::GetClipboardData
- AFXRICH/CRichEditView::GetContextMenu
- AFXRICH/CRichEditView::IsSelected
- AFXRICH/CRichEditView::OnFindNext
- AFXRICH/CRichEditView::OnInitialUpdate
- AFXRICH/CRichEditView::OnPasteNativeObject
- AFXRICH/CRichEditView::OnPrinterChanged
- AFXRICH/CRichEditView::OnReplaceAll
- AFXRICH/CRichEditView::OnReplaceSel
- AFXRICH/CRichEditView::OnTextNotFound
- AFXRICH/CRichEditView::QueryAcceptData
- AFXRICH/CRichEditView::WrapChanged
- AFXRICH/CRichEditView::m_nBulletIndent
- AFXRICH/CRichEditView::m_nWordWrap
helpviewer_keywords:
- CRichEditView [MFC], CRichEditView
- CRichEditView [MFC], AdjustDialogPosition
- CRichEditView [MFC], CanPaste
- CRichEditView [MFC], DoPaste
- CRichEditView [MFC], FindText
- CRichEditView [MFC], FindTextSimple
- CRichEditView [MFC], GetCharFormatSelection
- CRichEditView [MFC], GetDocument
- CRichEditView [MFC], GetInPlaceActiveItem
- CRichEditView [MFC], GetMargins
- CRichEditView [MFC], GetPageRect
- CRichEditView [MFC], GetPaperSize
- CRichEditView [MFC], GetParaFormatSelection
- CRichEditView [MFC], GetPrintRect
- CRichEditView [MFC], GetPrintWidth
- CRichEditView [MFC], GetRichEditCtrl
- CRichEditView [MFC], GetSelectedItem
- CRichEditView [MFC], GetTextLength
- CRichEditView [MFC], GetTextLengthEx
- CRichEditView [MFC], InsertFileAsObject
- CRichEditView [MFC], InsertItem
- CRichEditView [MFC], IsRichEditFormat
- CRichEditView [MFC], OnCharEffect
- CRichEditView [MFC], OnParaAlign
- CRichEditView [MFC], OnUpdateCharEffect
- CRichEditView [MFC], OnUpdateParaAlign
- CRichEditView [MFC], PrintInsideRect
- CRichEditView [MFC], PrintPage
- CRichEditView [MFC], SetCharFormat
- CRichEditView [MFC], SetMargins
- CRichEditView [MFC], SetPaperSize
- CRichEditView [MFC], SetParaFormat
- CRichEditView [MFC], TextNotFound
- CRichEditView [MFC], GetClipboardData
- CRichEditView [MFC], GetContextMenu
- CRichEditView [MFC], IsSelected
- CRichEditView [MFC], OnFindNext
- CRichEditView [MFC], OnInitialUpdate
- CRichEditView [MFC], OnPasteNativeObject
- CRichEditView [MFC], OnPrinterChanged
- CRichEditView [MFC], OnReplaceAll
- CRichEditView [MFC], OnReplaceSel
- CRichEditView [MFC], OnTextNotFound
- CRichEditView [MFC], QueryAcceptData
- CRichEditView [MFC], WrapChanged
- CRichEditView [MFC], m_nBulletIndent
- CRichEditView [MFC], m_nWordWrap
ms.assetid: bd576b10-4cc0-4050-8f76-e1a0548411e4
ms.openlocfilehash: 2d832f3cc07d39ace9e679901c5344a376cea03c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318633"
---
# <a name="cricheditview-class"></a>Classe CRichEditView

Com [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md) e [CRichEditCntrItem,](../../mfc/reference/cricheditcntritem-class.md)fornece a funcionalidade do rico controle de edição dentro do contexto da arquitetura de exibição de documentos do MFC.

## <a name="syntax"></a>Sintaxe

```
class CRichEditView : public CCtrlView
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CricheditView::CricheditView](#cricheditview)|Constrói um objeto `CRichEditView`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CricheditView::AdjustDialogPosition](#adjustdialogposition)|Move uma caixa de diálogo para que não obscureça a seleção atual.|
|[CRichEditView::CanPaste](#canpaste)|Informa se a Área de Transferência contém dados que podem ser colados na exibição de edição rica.|
|[CRichEditView::DoPaste](#dopaste)|Cole um item OLE nesta rica exibição de edição.|
|[CricheditView::FindText](#findtext)|Encontra o texto especificado, invocando o cursor de espera.|
|[CricheditView::FindTextSimple](#findtextsimple)|Encontra o texto especificado.|
|[CricheditView::GetCharFormatSelection](#getcharformatselection)|Recupera os atributos de formatação de caracteres para a seleção atual.|
|[CricheditView::getDocument](#getdocument)|Recupera um ponteiro para o [CRichEditDoc relacionado](../../mfc/reference/cricheditdoc-class.md).|
|[CRichEditView::GetInPlaceActiveItem](#getinplaceactiveitem)|Recupera o item OLE que está atualmente ativo na exibição de edição rica.|
|[CricheditView::getMargins](#getmargins)|Recupera as margens para esta rica exibição de edição.|
|[CRichEditView::GetPageRect](#getpagerect)|Recupera o retângulo de página para esta exibição de edição rica.|
|[CricheditView::GetPaperSize](#getpapersize)|Recupera o tamanho do papel para esta exibição de edição rica.|
|[CricheditView::GetParaFormatSelection](#getparaformatselection)|Recupera os atributos de formatação de parágrafo para a seleção atual.|
|[CRichEditView::GetPrintRect](#getprintrect)|Recupera o retângulo de impressão para esta exibição de edição rica.|
|[CricheditView::GetPrintWidth](#getprintwidth)|Recupera a largura de impressão para esta exibição de edição rica.|
|[CRichEditView::GetRichEditCtrl](#getricheditctrl)|Recupera o rico controle de edição.|
|[CRichEditView::GetSelectedItem](#getselecteditem)|Recupera o item selecionado da exibição de edição rica.|
|[CricheditView::GetTextLength](#gettextlength)|Recupera o comprimento do texto na exibição de edição rica.|
|[CricheditView::getTextlengthEx](#gettextlengthex)|Recupera o número de caracteres ou bytes na exibição de edição rica. Lista de bandeiras expandida para o método de determinar o comprimento.|
|[CricheditView::InsertFileAsObject](#insertfileasobject)|Insere um arquivo como item OLE.|
|[CRichEditView::InsertItem](#insertitem)|Insere um novo item como item OLE.|
|[CricheditView::isricheditformat](#isricheditformat)|Informa se a Área de Transferência contém dados em um formato de edição ou texto rico.|
|[CricheditView::OnCharEffect](#onchareffect)|Alterna a formatação do caractere para a seleção atual.|
|[CricheditView::OnParaalign](#onparaalign)|Altera o alinhamento dos parágrafos.|
|[CricheditView::OnUpdateCharEffect](#onupdatechareffect)|Atualiza a ui de comando para funções de membro público de caracteres.|
|[CricheditView::OnUpdateParaalign](#onupdateparaalign)|Atualiza a UI de comando para funções de membro público de parágrafo.|
|[CRichEditView::PrintInsideRect](#printinsiderect)|Formata o texto especificado no retângulo dado.|
|[CRichEditView::PrintPage](#printpage)|Formata o texto especificado na página dada.|
|[CricheditView::SetCharFormat](#setcharformat)|Define os atributos de formatação de caracteres para a seleção atual.|
|[CricheditView::SetMargins](#setmargins)|Define as margens para esta rica exibição de edição.|
|[CricheditView::SetPaperSize](#setpapersize)|Define o tamanho do papel para esta rica exibição de edição.|
|[CricheditView::SetParaformat](#setparaformat)|Define os atributos de formatação de parágrafo para a seleção atual.|
|[CricheditView::TextNotFound](#textnotfound)|Redefine o estado de busca interna do controle.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CRichEditView::GetClipboardData](#getclipboarddata)|Recupera um objeto de área de transferência para um intervalo nesta exibição de edição rica.|
|[CricheditView::GetContextMenu](#getcontextmenu)|Recupera um menu de contexto para usar em um botão de mouse direito para baixo.|
|[CricheditView::isSelected](#isselected)|Indica se o item OLE dado está selecionado ou não.|
|[CricheditView::OnFindNext](#onfindnext)|Encontra a próxima ocorrência de uma substring.|
|[CricheditView::OnInitialUpdate](#oninitialupdate)|Atualiza uma exibição quando ela é anexada pela primeira vez a um documento.|
|[CRichEditView::OnPasteNativeObject](#onpastenativeobject)|Recupera dados nativos de um item OLE.|
|[CricheditView::OnPrinterChanged](#onprinterchanged)|Define as características de impressão para o dispositivo dado.|
|[CricheditView::OnReplaceall](#onreplaceall)|Substitui todas as ocorrências de uma determinada seqüência por uma nova seqüência.|
|[CricheditView::OnReplaceSel](#onreplacesel)|Substitui a seleção atual.|
|[Cricheditview::OnTextNotFound](#ontextnotfound)|Trata da notificação do usuário de que o texto solicitado não foi encontrado.|
|[CRichEditView::ConsultaAcceptData](#queryacceptdata)|Consultas para ver sobre os `IDataObject`dados no .|
|[CricheditView::WrapChanged](#wrapchanged)|Ajusta o dispositivo de saída de destino para `m_nWordWrap`esta exibição de edição rica, com base no valor de .|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CRichEditView::m_nBulletIndent](#m_nbulletindent)|Indica a quantidade de recuo para listas de balas.|
|[CRichEditView::m_nWordWrap](#m_nwordwrap)|Indica a palavra restrições de envoltório.|

## <a name="remarks"></a>Comentários

Um "rico controle de edição" é uma janela na qual o usuário pode inserir e editar texto. O texto pode ser atribuído formatação de caracteres e parágrafos, e pode incluir objetos OLE incorporados. Os controles de edição ricos fornecem uma interface de programação para formatação de texto. No entanto, um aplicativo deve implementar quaisquer componentes de interface do usuário necessários para tornar as operações de formatação disponíveis para o usuário.

`CRichEditView`mantém o texto e a formatação característicos do texto. `CRichEditDoc`mantém a lista de itens clientes OLE que estão na exibição. `CRichEditCntrItem`fornece acesso ao lado do contêiner ao item cliente OLE.

Este controle do Windows Common (e, portanto, o [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md) e classes relacionadas) está disponível apenas para programas em execução nas versões Windows 95/98 e Windows NT 3.51 e posteriores.

Para um exemplo de usar uma exibição de edição rica em um aplicativo MFC, consulte o aplicativo de exemplo [WORDPAD.](../../overview/visual-cpp-samples.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CView](../../mfc/reference/cview-class.md)

[Cctrlview](../../mfc/reference/cctrlview-class.md)

`CRichEditView`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrich.h

## <a name="cricheditviewadjustdialogposition"></a><a name="adjustdialogposition"></a>CricheditView::AdjustDialogPosition

Chame esta função para mover a caixa de diálogo dada para que ela não obscureça a seleção atual.

```
void AdjustDialogPosition(CDialog* pDlg);
```

### <a name="parameters"></a>Parâmetros

*pDlg*<br/>
Ponteiro para `CDialog` um objeto.

## <a name="cricheditviewcanpaste"></a><a name="canpaste"></a>CRichEditView::CanPaste

Chame esta função para determinar se a Área de Transferência contém informações que podem ser coladas nesta rica exibição de edição.

```
BOOL CanPaste() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se a Área de Transferência contiver dados em um formato que essa rica exibição de edição pode aceitar; caso contrário, 0.

## <a name="cricheditviewcricheditview"></a><a name="cricheditview"></a>CricheditView::CricheditView

Chame esta função `CRichEditView` para criar um objeto.

```
CRichEditView();
```

## <a name="cricheditviewdopaste"></a><a name="dopaste"></a>CRichEditView::DoPaste

Chame esta função para colar o item OLE no *dataobj* neste documento/exibição de edição rica.

```
void DoPaste(
    COleDataObject& dataobj,
    CLIPFORMAT cf,
    HMETAFILEPICT hMetaPict);
```

### <a name="parameters"></a>Parâmetros

*dataobj*<br/>
O [COleDataObject](../../mfc/reference/coledataobject-class.md) contendo os dados a serem colados.

*Cf*<br/>
O formato de área de transferência desejado.

*hMetaPict*<br/>
O metaarquivo que representa o item a ser colado.

### <a name="remarks"></a>Comentários

O framework chama essa função como parte da implementação padrão do [QueryAcceptData](#queryacceptdata).

Esta função determina o tipo de pasta com base nos resultados do manipulador para Colar Especial. Se *cf* é 0, o novo item usa a representação icônica atual. Se *cf* não é zero e *hMetaPict* não é NULL, o novo item usa *hMetaPict* para sua representação.

## <a name="cricheditviewfindtext"></a><a name="findtext"></a>CricheditView::FindText

Chame esta função para encontrar o texto especificado e defina-o como sendo a seleção atual.

```
BOOL FindText(
    LPCTSTR lpszFind,
    BOOL bCase = TRUE,
    BOOL bWord = TRUE,
    BOOL bNext = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Lpszfind*<br/>
Contém a seqüência para procurar.

*Bcase*<br/>
Indica se a busca é sensível ao caso.

*bWord*<br/>
Indica se a pesquisa deve corresponder apenas a palavras inteiras, não partes de palavras.

*bNext*<br/>
Indica a direção da busca. Se TRUE, a direção da pesquisa é no final do buffer. Se FALSO, a direção de busca é para o início do buffer.

### <a name="return-value"></a>Valor retornado

Não zero se o *texto lpszFind* for encontrado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função exibe o cursor de espera durante a operação find.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#151](../../mfc/codesnippet/cpp/cricheditview-class_1.cpp)]

## <a name="cricheditviewfindtextsimple"></a><a name="findtextsimple"></a>CricheditView::FindTextSimple

Chame esta função para encontrar o texto especificado e defina-o como sendo a seleção atual.

```
BOOL FindTextSimple(
    LPCTSTR lpszFind,
    BOOL bCase = TRUE,
    BOOL bWord = TRUE,
    BOOL bNext = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Lpszfind*<br/>
Contém a seqüência para procurar.

*Bcase*<br/>
Indica se a busca é sensível ao caso.

*bWord*<br/>
Indica se a pesquisa deve corresponder apenas a palavras inteiras, não partes de palavras.

*bNext*<br/>
Indica a direção da busca. Se TRUE, a direção da pesquisa é no final do buffer. Se FALSO, a direção de busca é para o início do buffer.

### <a name="return-value"></a>Valor retornado

Não zero se o *texto lpszFind* for encontrado; caso contrário, 0.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CRichEditView::FindText](#findtext).

## <a name="cricheditviewgetcharformatselection"></a><a name="getcharformatselection"></a>CricheditView::GetCharFormatSelection

Chame esta função para obter os atributos de formatação de caracteres da seleção atual.

```
CHARFORMAT2& GetCharFormatSelection();
```

### <a name="return-value"></a>Valor retornado

Uma estrutura [CHARFORMAT2](/windows/win32/api/richedit/ns-richedit-charformat2w) que contém os atributos de formatação de caracteres da seleção atual.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte a mensagem [EM_GETCHARFORMAT](/windows/win32/Controls/em-getcharformat) e a estrutura [CHARFORMAT2](/windows/win32/api/richedit/ns-richedit-charformat2w) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#152](../../mfc/codesnippet/cpp/cricheditview-class_2.cpp)]

## <a name="cricheditviewgetclipboarddata"></a><a name="getclipboarddata"></a>CRichEditView::GetClipboardData

O framework chama essa função como parte do processamento do [IRichEditOleCallback::GetClipboardData](/windows/win32/api/richole/nf-richole-iricheditolecallback-getclipboarddata).

```
virtual HRESULT GetClipboardData(
    CHARRANGE* lpchrg,
    DWORD dwReco,
    LPDATAOBJECT lpRichDataObj,
    LPDATAOBJECT* lplpdataobj);
```

### <a name="parameters"></a>Parâmetros

*Lpchrg*<br/>
Pointer para a estrutura [CHARRANGE](/windows/win32/api/richedit/ns-richedit-charrange) especificando a gama de caracteres (e itens OLE) para copiar para o objeto de dados especificado pelo *lplpdataobj*.

*dwReco*<br/>
Bandeira de operação da prancheta. Pode ser um desses valores.

- RECO_COPY Copiar para a área de transferência.

- RECO_CUT corte para a prancheta.

- RECO_DRAG Operação arrastar (arrastar e soltar).

- RECO_DROP operação Drop (arrastar e soltar).

- RECO_PASTE Pasta da Prancheta.

*lpRichDataObj*<br/>
Pointer para um objeto [IDataObject](/windows/win32/api/objidl/nn-objidl-idataobject) contendo os dados da Área de Transferência do rico controle de edição [(IRichEditOle::GetClipboardData](/windows/win32/api/richole/nf-richole-iricheditole-getclipboarddata)).

*lplpdataobj*<br/>
Ponteiro para a variável ponteiro que `IDataObject` recebe o endereço do objeto representando o intervalo especificado no parâmetro *lpchrg.* O valor do *lplpdataobj* é ignorado se um erro for devolvido.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT relatando o sucesso da operação. Para obter mais informações sobre o HRESULT, consulte [Estrutura de Códigos de erro COM](/windows/win32/com/structure-of-com-error-codes) no SDK do Windows.

### <a name="remarks"></a>Comentários

Se o valor de `IRichEditOleCallback::GetClipboardData` retorno `IDataObject` indicar sucesso, retorna o acessado pelo *lplpdataobj*; caso contrário, ele retorna o acessado por *lpRichDataObj*. Anular esta função para fornecer seus próprios dados da Área de Transferência. A implementação padrão desta função retorna E_NOTIMPL.

Este é um avançado super-rididável.

Para obter mais informações, consulte [IRichEditOle::GetClipboardData,](/windows/win32/api/richole/nf-richole-iricheditole-getclipboarddata) [IRichEditOleCallback::GetClipboardData](/windows/win32/api/richole/nf-richole-iricheditolecallback-getclipboarddata)e [CHARRANGE](/windows/win32/api/richedit/ns-richedit-charrange) no Windows SDK e veja [IDataObject](/windows/win32/api/objidl/nn-objidl-idataobject) no Windows SDK.

## <a name="cricheditviewgetcontextmenu"></a><a name="getcontextmenu"></a>CricheditView::GetContextMenu

O framework chama essa função como parte do processamento do [IRichEditOleCallback::GetContextMenu](/windows/win32/api/richole/nf-richole-iricheditolecallback-getcontextmenu).

```
virtual HMENU GetContextMenu(
    WORD seltyp,
    LPOLEOBJECT lpoleobj,
    CHARRANGE* lpchrg);
```

### <a name="parameters"></a>Parâmetros

*seltyp*<br/>
O tipo de seleção. Os valores do tipo de seleção são descritos na seção Observações.

*Pólobj*<br/>
Ponteiro para `OLEOBJECT` uma estrutura especificando o primeiro objeto OLE selecionado se a seleção contiver um ou mais itens OLE. Se a seleção não contiver itens, *lpoleobj* será NULA. A `OLEOBJECT` estrutura contém um ponteiro para uma tabela V do objeto OLE.

*Lpchrg*<br/>
Ponteiro para uma estrutura [CHARRANGE](/windows/win32/api/richedit/ns-richedit-charrange) contendo a seleção atual.

### <a name="return-value"></a>Valor retornado

Manuseie o menu de contexto.

### <a name="remarks"></a>Comentários

Esta função é uma parte típica do processamento para baixo do botão do mouse direito.

O tipo de seleção pode ser qualquer combinação das seguintes bandeiras:

- SEL_EMPTY Indica que não há seleção atual.

- SEL_TEXT Indica que a seleção atual contém texto.

- SEL_OBJECT Indica que a seleção atual contém pelo menos um item OLE.

- SEL_MULTICHAR Indica que a seleção atual contém mais de um caractere de texto.

- SEL_MULTIOBJECT Indica que a seleção atual contém mais de um objeto OLE.

A implementação padrão retorna NULL. Este é um avançado super-rididável.

Para obter mais informações, consulte [IRichEditOleCallback::GetContextMenu](/windows/win32/api/richole/nf-richole-iricheditolecallback-getcontextmenu) e [CHARRANGE](/windows/win32/api/richedit/ns-richedit-charrange) no Windows SDK.

## <a name="cricheditviewgetdocument"></a><a name="getdocument"></a>CricheditView::getDocument

Chame esta função para obter `CRichEditDoc` um ponteiro para o associado a esta exibição.

```
CRichEditDoc* GetDocument() const;
```

### <a name="return-value"></a>Valor retornado

Pointer para um objeto [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md) associado ao seu `CRichEditView` objeto.

## <a name="cricheditviewgetinplaceactiveitem"></a><a name="getinplaceactiveitem"></a>CRichEditView::GetInPlaceActiveItem

Chame esta função para obter o item OLE que `CRichEditView` está atualmente ativado neste objeto.

```
CRichEditCntrItem* GetInPlaceActiveItem() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md) ativo único e no lugar nesta exibição de edição rica; NULO se não houver nenhum item OLE atualmente no estado ativo em vigor.

## <a name="cricheditviewgetmargins"></a><a name="getmargins"></a>CricheditView::getMargins

Chame esta função para recuperar as margens atuais usadas na impressão.

```
CRect GetMargins() const;
```

### <a name="return-value"></a>Valor retornado

As margens utilizadas na impressão, medidas em MM_TWIPS.

## <a name="cricheditviewgetpagerect"></a><a name="getpagerect"></a>CRichEditView::GetPageRect

Chame esta função para obter as dimensões da página usada na impressão.

```
CRect GetPageRect() const;
```

### <a name="return-value"></a>Valor retornado

Os limites da página utilizada na impressão, medidos em MM_TWIPS.

### <a name="remarks"></a>Comentários

Este valor é baseado no tamanho do papel.

## <a name="cricheditviewgetpapersize"></a><a name="getpapersize"></a>CricheditView::GetPaperSize

Chame esta função para recuperar o tamanho atual do papel.

```
CSize GetPaperSize() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho do papel utilizado na impressão, medido em MM_TWIPS.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#153](../../mfc/codesnippet/cpp/cricheditview-class_3.cpp)]

## <a name="cricheditviewgetparaformatselection"></a><a name="getparaformatselection"></a>CricheditView::GetParaFormatSelection

Chame esta função para obter os atributos de formatação de parágrafo da seleção atual.

```
PARAFORMAT2& GetParaFormatSelection();
```

### <a name="return-value"></a>Valor retornado

Uma [estrutura PARAFORMAT2](/windows/win32/api/richedit/ns-richedit-paraformat2) que contém os atributos de formatação de parágrafo da seleção atual.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [EM_GETPARAFORMAT](/windows/win32/Controls/em-getparaformat) mensagem e a estrutura [PARAFORMAT2](/windows/win32/api/richedit/ns-richedit-paraformat2) no SDK do Windows.

## <a name="cricheditviewgetprintrect"></a><a name="getprintrect"></a>CRichEditView::GetPrintRect

Chame esta função para recuperar os limites da área de impressão dentro do retângulo da página.

```
CRect GetPrintRect() const;
```

### <a name="return-value"></a>Valor retornado

Os limites da área de imagem utilizada na impressão, medidos em MM_TWIPS.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#154](../../mfc/codesnippet/cpp/cricheditview-class_4.cpp)]

## <a name="cricheditviewgetprintwidth"></a><a name="getprintwidth"></a>CricheditView::GetPrintWidth

Ligue para esta função para determinar a largura da área de impressão.

```
int GetPrintWidth() const;
```

### <a name="return-value"></a>Valor retornado

A largura da área de impressão, medida em MM_TWIPS.

## <a name="cricheditviewgetricheditctrl"></a><a name="getricheditctrl"></a>CRichEditView::GetRichEditCtrl

Chame esta função para recuperar o objeto [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md) associado ao `CRichEditView` objeto.

```
CRichEditCtrl& GetRichEditCtrl() const;
```

### <a name="return-value"></a>Valor retornado

O `CRichEditCtrl` objeto para essa visão.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CRichEditView::FindText](#findtext).

## <a name="cricheditviewgetselecteditem"></a><a name="getselecteditem"></a>CRichEditView::GetSelectedItem

Chame esta função para recuperar o `CRichEditCntrItem` item OLE (um objeto) atualmente selecionado neste `CRichEditView` objeto.

```
CRichEditCntrItem* GetSelectedItem() const;
```

### <a name="return-value"></a>Valor retornado

Ponteiro para um objeto [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md) selecionado no `CRichEditView` objeto; NULL se nenhum item for selecionado nesta exibição.

## <a name="cricheditviewgettextlength"></a><a name="gettextlength"></a>CricheditView::GetTextLength

Chame esta função para recuperar o `CRichEditView` comprimento do texto neste objeto.

```
long GetTextLength() const;
```

### <a name="return-value"></a>Valor retornado

A duração do texto `CRichEditView` neste objeto.

## <a name="cricheditviewgettextlengthex"></a><a name="gettextlengthex"></a>CricheditView::getTextlengthEx

Chame esta função de membro para calcular `CRichEditView` o comprimento do texto neste objeto.

```
long GetTextLengthEx(
    DWORD dwFlags,
    UINT uCodePage = -1) const;
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Valor especificando o método a ser usado na determinação do comprimento do texto. Este membro pode ser um ou mais dos valores listados no membro de bandeiras do [GETTEXTLENGTHEX](/windows/win32/api/richedit/ns-richedit-gettextlengthex) descrito no Windows SDK.

*uCodePage*<br/>
Página de código para tradução (CP_ACP para página de código ANSI, 1200 para Unicode).

### <a name="return-value"></a>Valor retornado

O número de caracteres ou bytes no controle de edição. Se as bandeiras incompatíveis foram definidas em *dwFlags,* esta função membro retorna E_INVALIDARG.

### <a name="remarks"></a>Comentários

`GetTextLengthEx`fornece formas adicionais de determinar a duração do texto. Ele suporta a funcionalidade Rich Edit 2.0. Para obter mais informações, consulte Controles de [edição de Rich](/windows/win32/Controls/about-rich-edit-controls) no SDK do Windows.

## <a name="cricheditviewinsertfileasobject"></a><a name="insertfileasobject"></a>CricheditView::InsertFileAsObject

Chame essa função para inserir o arquivo especificado (como um objeto [CRichEditCntrItem)](../../mfc/reference/cricheditcntritem-class.md) em uma exibição de edição rica.

```
void InsertFileAsObject(LPCTSTR lpszFileName);
```

### <a name="parameters"></a>Parâmetros

*lpszFileName*<br/>
String contendo o nome do arquivo a ser inserido.

## <a name="cricheditviewinsertitem"></a><a name="insertitem"></a>CRichEditView::InsertItem

Chame essa função para inserir um objeto [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md) em uma exibição de edição rica.

```
HRESULT InsertItem(CRichEditCntrItem* pItem);
```

### <a name="parameters"></a>Parâmetros

*Pitem*<br/>
Pointer para o item a ser inserido.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT indicando o sucesso da inserção.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o HRESULT, consulte [Estrutura de Códigos de erro COM](/windows/win32/com/structure-of-com-error-codes) no SDK do Windows.

## <a name="cricheditviewisricheditformat"></a><a name="isricheditformat"></a>CricheditView::isricheditformat

Chame esta função para determinar se *cf* é um formato de área de transferência que é texto, texto rico ou texto rico com itens OLE.

```
static BOOL AFX_CDECL IsRichEditFormat(CLIPFORMAT cf);
```

### <a name="parameters"></a>Parâmetros

*Cf*<br/>
O formato de interesse da Área de Transferência.

### <a name="return-value"></a>Valor retornado

Não zero se *cf* é um formato de edição rica ou texto de área de transferência.

## <a name="cricheditviewisselected"></a><a name="isselected"></a>CricheditView::isSelected

Chame esta função para determinar se o item OLE especificado está atualmente selecionado nesta exibição.

```
virtual BOOL IsSelected(const CObject* pDocItem) const;
```

### <a name="parameters"></a>Parâmetros

*pDocItem*<br/>
Ponteiro para um objeto na exibição.

### <a name="return-value"></a>Valor retornado

Não zero se o objeto for selecionado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Anular esta função se a sua classe de exibição derivada tiver um método diferente para lidar com a seleção de itens OLE.

## <a name="cricheditviewm_nbulletindent"></a><a name="m_nbulletindent"></a>CRichEditView::m_nBulletIndent

O recuo para itens de bala em uma lista; por padrão, 720 unidades, que é de 1/2 polegada.

```
int m_nBulletIndent;
```

## <a name="cricheditviewm_nwordwrap"></a><a name="m_nwordwrap"></a>CRichEditView::m_nWordWrap

Indica o tipo de wrap de palavra para esta exibição de edição rica.

```
int m_nWordWrap;
```

### <a name="remarks"></a>Comentários

Um dos seguintes valores:

- `WrapNone`Não indica nenhuma embalagem automática de palavras.

- `WrapToWindow`Indica o embrulho da palavra com base na largura da janela.

- `WrapToTargetDevice`Indica o embrulho da palavra com base nas características do dispositivo de destino.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CRichEditView::WrapChanged](#wrapchanged).

## <a name="cricheditviewonchareffect"></a><a name="onchareffect"></a>CricheditView::OnCharEffect

Chame esta função para alternar os efeitos de formatação de caracteres para a seleção atual.

```
void OnCharEffect(
    DWORD dwMask,
    DWORD dwEffect);
```

### <a name="parameters"></a>Parâmetros

*Dwmask*<br/>
Os efeitos de formatação de caracteres para modificar na seleção atual.

*dwEffect*<br/>
A lista desejada de efeitos de formatação de caracteres para alternar.

### <a name="remarks"></a>Comentários

Cada chamada para esta função alterna os efeitos de formatação especificados para a seleção atual.

Para obter mais informações sobre os parâmetros *dwMask* e *dwEffect* e seus valores potenciais, consulte os membros de dados correspondentes do [CHARFORMAT](/windows/win32/api/richedit/ns-richedit-charformata) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#155](../../mfc/codesnippet/cpp/cricheditview-class_5.cpp)]

## <a name="cricheditviewonfindnext"></a><a name="onfindnext"></a>CricheditView::OnFindNext

Chamado pelo framework ao processar comandos da caixa de diálogo Encontrar/Substituir.

```
virtual void OnFindNext(
    LPCTSTR lpszFind,
    BOOL bNext,
    BOOL bCase,
    BOOL bWord);
```

### <a name="parameters"></a>Parâmetros

*Lpszfind*<br/>
A cadeia de caracteres a ser localizada.

*bNext*<br/>
A direção de pesquisa: TRUE indica para baixo; FALSO, para cima.

*Bcase*<br/>
Indica se a busca deve ser sensível ao caso.

*bWord*<br/>
Indica se a pesquisa é para combinar palavras inteiras apenas ou não.

### <a name="remarks"></a>Comentários

Chame esta função para `CRichEditView`encontrar texto dentro do . Substituir esta função para alterar as características de pesquisa para sua classe de exibição derivada.

## <a name="cricheditviewoninitialupdate"></a><a name="oninitialupdate"></a>CricheditView::OnInitialUpdate

Chamado pelo framework após a exibição é anexado primeiro ao documento, mas antes que a exibição seja exibida inicialmente.

```
virtual void OnInitialUpdate();
```

### <a name="remarks"></a>Comentários

A implementação padrão desta função chama a função de membro [CView::OnUpdate](../../mfc/reference/cview-class.md#onupdate) sem informações de dica (isto é, usando os valores padrão de 0 para o parâmetro *lHint* e NULL para o parâmetro *pHint).* Anular essa função para executar qualquer inicialização única que exija informações sobre o documento. Por exemplo, se o aplicativo tiver documentos de tamanho fixo, você pode usar essa função para inicializar os limites de rolagem de uma exibição com base no tamanho do documento. Se o aplicativo tiver suporte a `OnUpdate` documentos de tamanho variável, use para atualizar os limites de rolagem toda vez que o documento for alterado.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CRichEditView::m_nWordWrap](#m_nwordwrap).

## <a name="cricheditviewonpastenativeobject"></a><a name="onpastenativeobject"></a>CRichEditView::OnPasteNativeObject

Use esta função para carregar dados nativos de um item incorporado.

```
virtual BOOL OnPasteNativeObject(LPSTORAGE lpStg);
```

### <a name="parameters"></a>Parâmetros

*lpStg*<br/>
Ponteiro para um objeto [IStorage.](/windows/win32/api/objidl/nn-objidl-istorage)

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0;

### <a name="remarks"></a>Comentários

Normalmente, você faria isso criando um [COleStreamFile](../../mfc/reference/colestreamfile-class.md) em torno do `IStorage`. O `COleStreamFile` pode ser anexado a um arquivo e [cObject::Serialize](../../mfc/reference/cobject-class.md#serialize) chamado para carregar os dados.

Este é um avançado super-rididável.

Para obter mais informações, consulte [IStorage](/windows/win32/api/objidl/nn-objidl-istorage) no SDK do Windows.

## <a name="cricheditviewonparaalign"></a><a name="onparaalign"></a>CricheditView::OnParaalign

Chame esta função para alterar o alinhamento de parágrafos para os parágrafos selecionados.

```
void OnParaAlign(WORD wAlign);
```

### <a name="parameters"></a>Parâmetros

*wAlign*<br/>
Alinhamento de parágrafo desejado. Um dos seguintes valores:

- PFA_LEFT Alinhe os parágrafos com a margem esquerda.

- PFA_RIGHT Alinhe os parágrafos com a margem certa.

- PFA_CENTER Centralos parágrafos entre as margens.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#156](../../mfc/codesnippet/cpp/cricheditview-class_6.cpp)]

## <a name="cricheditviewonprinterchanged"></a><a name="onprinterchanged"></a>CricheditView::OnPrinterChanged

Substituir esta função para alterar características para esta exibição de edição rica quando a impressora muda.

```
virtual void OnPrinterChanged(const CDC& dcPrinter);
```

### <a name="parameters"></a>Parâmetros

*dcPrinter*<br/>
Um objeto [CDC](../../mfc/reference/cdc-class.md) para a nova impressora.

### <a name="remarks"></a>Comentários

A implementação padrão define o tamanho do papel para a altura física e a largura do dispositivo de saída (impressora). Se não houver um contexto de dispositivo associado ao *dcPrinter,* a implementação padrão define o tamanho do papel para 8,5 por 11 polegadas.

## <a name="cricheditviewonreplaceall"></a><a name="onreplaceall"></a>CricheditView::OnReplaceall

Chamado pela estrutura ao processar Substituir todos os comandos da caixa de diálogo Substituir.

```
virtual void OnReplaceAll(
    LPCTSTR lpszFind,
    LPCTSTR lpszReplace,
    BOOL bCase,
    BOOL bWord);
```

### <a name="parameters"></a>Parâmetros

*Lpszfind*<br/>
O texto a ser substituído.

*lpszReplace*<br/>
O texto de substituição.

*Bcase*<br/>
Indica se a busca é sensível ao caso.

*bWord*<br/>
Indica se a pesquisa deve selecionar palavras inteiras ou não.

### <a name="remarks"></a>Comentários

Chame esta função para substituir todas as ocorrências de algum texto dado por outra seqüência. Substituir esta função para alterar as características de pesquisa para esta exibição.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CRichEditView::FindText](#findtext).

## <a name="cricheditviewonreplacesel"></a><a name="onreplacesel"></a>CricheditView::OnReplaceSel

Chamado pelo framework ao processar Substituir comandos da caixa de diálogo Substituir.

```
virtual void OnReplaceSel(
    LPCTSTR lpszFind,
    BOOL bNext,
    BOOL bCase,
    BOOL bWord,
    LPCTSTR lpszReplace);
```

### <a name="parameters"></a>Parâmetros

*Lpszfind*<br/>
O texto a ser substituído.

*bNext*<br/>
Indica a direção da pesquisa: TRUE está para baixo; FALSO, para cima.

*Bcase*<br/>
Indica se a busca é sensível ao caso.

*bWord*<br/>
Indica se a pesquisa deve selecionar palavras inteiras ou não.

*lpszReplace*<br/>
O texto de substituição.

### <a name="remarks"></a>Comentários

Chame esta função para substituir uma ocorrência de algum texto dado por outra seqüência. Substituir esta função para alterar as características de pesquisa para esta exibição.

## <a name="cricheditviewontextnotfound"></a><a name="ontextnotfound"></a>Cricheditview::OnTextNotFound

Chamado pela estrutura sempre que uma pesquisa falha.

```
virtual void OnTextNotFound(LPCTSTR lpszFind);
```

### <a name="parameters"></a>Parâmetros

*Lpszfind*<br/>
O texto que não foi encontrado.

### <a name="remarks"></a>Comentários

Substituir esta função para alterar a notificação de saída de um [MessageBeep](/windows/win32/api/winuser/nf-winuser-messagebeep).

Para obter mais informações, consulte [MessageBeep](/windows/win32/api/winuser/nf-winuser-messagebeep) no Windows SDK.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#157](../../mfc/codesnippet/cpp/cricheditview-class_7.cpp)]

## <a name="cricheditviewonupdatechareffect"></a><a name="onupdatechareffect"></a>CricheditView::OnUpdateCharEffect

A estrutura chama essa função para atualizar a ui de comando para comandos de efeito de caractere.

```
void OnUpdateCharEffect(
    CCmdUI* pCmdUI,
    DWORD dwMask,
    DWORD dwEffect);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Ponteiro para um objeto [CCmdUI.](../../mfc/reference/ccmdui-class.md)

*Dwmask*<br/>
Indica a máscara de formatação do caractere.

*dwEffect*<br/>
Indica o efeito de formatação do caractere.

### <a name="remarks"></a>Comentários

A máscara *dwMask* especifica quais atributos de formatação de caracteres para verificar. Os sinalizadores *dwEffect* listam os atributos de formatação de caracteres a set/clear.

Para obter mais informações sobre os parâmetros *dwMask* e *dwEffect* e seus valores potenciais, consulte os membros de dados correspondentes do [CHARFORMAT](/windows/win32/api/richedit/ns-richedit-charformata) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#158](../../mfc/codesnippet/cpp/cricheditview-class_8.cpp)]

## <a name="cricheditviewonupdateparaalign"></a><a name="onupdateparaalign"></a>CricheditView::OnUpdateParaalign

A estrutura chama essa função para atualizar a ui de comando para comandos de efeito de parágrafo.

```
void OnUpdateParaAlign(
    CCmdUI* pCmdUI,
    WORD wAlign);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Ponteiro para um objeto [CCmdUI.](../../mfc/reference/ccmdui-class.md)

*wAlign*<br/>
O alinhamento do parágrafo para verificar. Um dos seguintes valores:

- PFA_LEFT Alinhe os parágrafos com a margem esquerda.

- PFA_RIGHT Alinhe os parágrafos com a margem certa.

- PFA_CENTER Centralos parágrafos entre as margens.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#159](../../mfc/codesnippet/cpp/cricheditview-class_9.cpp)]

## <a name="cricheditviewprintinsiderect"></a><a name="printinsiderect"></a>CRichEditView::PrintInsideRect

Chame esta função para formatar uma gama de texto em um rico controle de edição para caber dentro *do rectLayout* para o dispositivo especificado pelo *pDC*.

```
long PrintInsideRect(
    CDC* pDC,
    RECT& rectLayout,
    long nIndexStart,
    long nIndexStop,
    BOOL bOutput);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Ponteiro para um contexto de dispositivo para a área de saída.

*rectLayout*<br/>
[RECT](/windows/win32/api/windef/ns-windef-rect) ou [CRect](../../atl-mfc-shared/reference/crect-class.md) que define a área de saída.

*Nindexstart*<br/>
Índice baseado em zero do primeiro caractere a ser formatado.

*nIndexStop*<br/>
Índice baseado em zero do último caractere a ser formatado.

*bSaída*<br/>
Indica se o texto deve ser renderizado. Se FALSO, o texto é apenas medido.

### <a name="return-value"></a>Valor retornado

O índice do último caractere que se encaixa na área de saída mais um.

### <a name="remarks"></a>Comentários

Normalmente, essa chamada é seguida por uma chamada para [CRichEditCtrl::DisplayBand](../../mfc/reference/cricheditctrl-class.md#displayband) que gera a saída.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CRichEditView::GetPaperSize](#getpapersize).

## <a name="cricheditviewprintpage"></a><a name="printpage"></a>CRichEditView::PrintPage

Chame esta função para formatar uma gama de texto em um rico controle de edição para o dispositivo de saída especificado pelo *pDC*.

```
long PrintPage(
    CDC* pDC,
    long nIndexStart,
    long nIndexStop);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Ponteiro para um contexto de dispositivo para saída de página.

*Nindexstart*<br/>
Índice baseado em zero do primeiro caractere a ser formatado.

*nIndexStop*<br/>
Índice baseado em zero do último caractere a ser formatado.

### <a name="return-value"></a>Valor retornado

O índice do último caractere que se encaixa na página mais um.

### <a name="remarks"></a>Comentários

O layout de cada página é controlado por [GetPageRect](#getpagerect) e [GetPrintRect](#getprintrect). Normalmente, essa chamada é seguida por uma chamada para [CRichEditCtrl::DisplayBand](../../mfc/reference/cricheditctrl-class.md#displayband) que gera a saída.

Observe que as margens são relativas à página física, não à página lógica. Assim, as margens de zero muitas vezes cortam o texto, já que muitas impressoras têm áreas imprimíveis na página. Para evitar o recorte do texto, você deve chamar [SetMargins](#setmargins) e definir margens razoáveis antes de imprimir.

## <a name="cricheditviewqueryacceptdata"></a><a name="queryacceptdata"></a>CRichEditView::ConsultaAcceptData

Chamado pela estrutura para colar um objeto na edição rica.

```
virtual HRESULT QueryAcceptData(
    LPDATAOBJECT lpdataobj,
    CLIPFORMAT* lpcfFormat,
    DWORD dwReco,
    BOOL bReally,
    HGLOBAL hMetaFile);
```

### <a name="parameters"></a>Parâmetros

*lpdataobj*<br/>
Ponteiro para o [IDataObject](/windows/win32/api/objidl/nn-objidl-idataobject) para consulta.

*lpcfFormat*<br/>
Ponteiro para o formato de dados aceitável.

*dwReco*<br/>
Não usado.

*bRealmente*<br/>
Indica se a operação da pasta deve continuar ou não.

*hMetaFile*<br/>
Uma alça para o metaarquivo usado para desenhar o ícone do item.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT relatando o sucesso da operação.

### <a name="remarks"></a>Comentários

Substituir esta função para lidar com diferentes organizações de itens COM em sua classe de documentos derivados. Este é um avançado super-rididável.

Para obter mais informações `IDataObject`sobre HRESULT e , consulte [Estrutura de Códigos de Erro COM](/windows/win32/com/structure-of-com-error-codes) e [IDataObject,](/windows/win32/api/objidl/nn-objidl-idataobject)respectivamente, no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#160](../../mfc/codesnippet/cpp/cricheditview-class_10.cpp)]

## <a name="cricheditviewsetcharformat"></a><a name="setcharformat"></a>CricheditView::SetCharFormat

Chame esta função para definir os atributos `CRichEditView` de formatação de caracteres para novo texto neste objeto.

```
void SetCharFormat(CHARFORMAT2 cf);
```

### <a name="parameters"></a>Parâmetros

*Cf*<br/>
[Estrutura CHARFORMAT2](/windows/win32/api/richedit/ns-richedit-charformat2w) contendo os novos atributos de formatação de caracteres padrão.

### <a name="remarks"></a>Comentários

Apenas os atributos `dwMask` especificados pelo membro da *CF* são alterados por esta função.

Para obter mais informações, consulte [EM_SETCHARFORMAT](/windows/win32/Controls/em-setcharformat) mensagem e a estrutura [CHARFORMAT2](/windows/win32/api/richedit/ns-richedit-charformat2w) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#152](../../mfc/codesnippet/cpp/cricheditview-class_2.cpp)]

## <a name="cricheditviewsetmargins"></a><a name="setmargins"></a>CricheditView::SetMargins

Chame esta função para definir as margens de impressão para esta exibição de edição rica.

```
void SetMargins(const CRect& rectMargin);
```

### <a name="parameters"></a>Parâmetros

*rectMargem*<br/>
Os novos valores de margem para impressão, medidos em MM_TWIPS.

### <a name="remarks"></a>Comentários

Se [m_nWordWrap](#m_nwordwrap) m_nWordWrap `WrapToTargetDevice`for, você deve chamar [WrapChanged](#wrapchanged) depois de usar esta função para ajustar as características de impressão.

Observe que as margens usadas pelo [PrintPage](#printpage) são relativas à página física, não à página lógica. Assim, as margens de zero muitas vezes cortam o texto, já que muitas impressoras têm áreas imprimíveis na página. Para evitar cortar seu texto, `SetMargins` você deve usar o uso para definir margens razoáveis da impressora antes de imprimir.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CRichEditView::GetPaperSize](#getpapersize).

## <a name="cricheditviewsetpapersize"></a><a name="setpapersize"></a>CricheditView::SetPaperSize

Chame esta função para definir o tamanho do papel para imprimir esta rica exibição de edição.

```
void SetPaperSize(CSize sizePaper);
```

### <a name="parameters"></a>Parâmetros

*sizePaper*<br/>
Os novos valores de tamanho do papel para impressão, medidos em MM_TWIPS.

### <a name="remarks"></a>Comentários

Se [m_nWordWrap](#m_nwordwrap) m_nWordWrap `WrapToTargetDevice`for, você deve chamar [WrapChanged](#wrapchanged) depois de usar esta função para ajustar as características de impressão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#161](../../mfc/codesnippet/cpp/cricheditview-class_11.cpp)]

## <a name="cricheditviewsetparaformat"></a><a name="setparaformat"></a>CricheditView::SetParaformat

Chame esta função para definir os atributos de `CRichEditView` formatação de parágrafo para a seleção atual neste objeto.

```
BOOL SetParaFormat(PARAFORMAT2& pf);
```

### <a name="parameters"></a>Parâmetros

*Pf*<br/>
[Estrutura PARAFORMAT2](/windows/win32/api/richedit/ns-richedit-paraformat2) contendo os novos atributos de formatação de parágrafo padrão.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Apenas os atributos `dwMask` especificados pelo membro da *PF* são alterados por esta função.

Para obter mais informações, consulte [EM_SETPARAFORMAT](/windows/win32/Controls/em-setparaformat) mensagem e a estrutura [PARAFORMAT2](/windows/win32/api/richedit/ns-richedit-paraformat2) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#162](../../mfc/codesnippet/cpp/cricheditview-class_12.cpp)]

## <a name="cricheditviewtextnotfound"></a><a name="textnotfound"></a>CricheditView::TextNotFound

Chame esta função para redefinir o estado de pesquisa interna do controle [CRichEditView](../../mfc/reference/cricheditview-class.md) após uma chamada com falha no [FindText](#findtext).

```
void TextNotFound(LPCTSTR lpszFind);
```

### <a name="parameters"></a>Parâmetros

*Lpszfind*<br/>
Contém a seqüência de texto que não foi encontrada.

### <a name="remarks"></a>Comentários

Recomenda-se que este método seja chamado imediatamente após chamadas fracassadas para [FindText](#findtext) para que o estado de pesquisa interna do controle seja adequadamente redefinido.

O parâmetro *lpszFind* deve incluir o mesmo conteúdo da seqüência fornecida ao [FindText](#findtext). Depois de redefinir o estado de pesquisa interna, este método chamará o método [OnTextNotFound](#ontextnotfound) com a seqüência de pesquisa fornecida.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CRichEditView::FindText](#findtext).

## <a name="cricheditviewwrapchanged"></a><a name="wrapchanged"></a>CricheditView::WrapChanged

Chame esta função quando as características de impressão tiverem sido [alteradas (SetMargins](#setmargins) ou [SetPaperSize](#setpapersize)).

```
virtual void WrapChanged();
```

### <a name="remarks"></a>Comentários

Substituir essa função para modificar a forma como a visualização de edição rica responde a alterações no [m_nWordWrap](#m_nwordwrap) ou nas características de impressão [(OnPrinterChanged).](#onprinterchanged)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#163](../../mfc/codesnippet/cpp/cricheditview-class_13.cpp)]

## <a name="see-also"></a>Confira também

[MFC Sample WORDPAD](../../overview/visual-cpp-samples.md)<br/>
[Classe CCtrlView](../../mfc/reference/cctrlview-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CRichEditDoc](../../mfc/reference/cricheditdoc-class.md)<br/>
[CRichEditCntriItem Class](../../mfc/reference/cricheditcntritem-class.md)
