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
ms.openlocfilehash: b32578cc3c9ad4f7a89b8ee76449259c0fa0b43b
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78883640"
---
# <a name="cricheditview-class"></a>Classe CRichEditView

Com [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md) e [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md), o fornece a funcionalidade do controle de edição rico dentro do contexto da arquitetura de exibição de documentos do MFC.

## <a name="syntax"></a>Sintaxe

```
class CRichEditView : public CCtrlView
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CRichEditView::CRichEditView](#cricheditview)|Constrói um objeto `CRichEditView`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CRichEditView::AdjustDialogPosition](#adjustdialogposition)|Move uma caixa de diálogo para que ela não oculte a seleção atual.|
|[CRichEditView:: CanPaste](#canpaste)|Informa se a área de transferência contém dados que podem ser colados na exibição de edição rica.|
|[CRichEditView::D oPaste](#dopaste)|Cola um item OLE nesse modo de exibição de edição avançado.|
|[CRichEditView:: LocalizarTexto](#findtext)|Localiza o texto especificado, invocando o cursor de espera.|
|[CRichEditView::FindTextSimple](#findtextsimple)|Localiza o texto especificado.|
|[CRichEditView::GetCharFormatSelection](#getcharformatselection)|Recupera os atributos de formatação de caractere para a seleção atual.|
|[CRichEditView:: GetDocument](#getdocument)|Recupera um ponteiro para o [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md)relacionado.|
|[CRichEditView::GetInPlaceActiveItem](#getinplaceactiveitem)|Recupera o item OLE que está atualmente no local ativo no modo de exibição de edição avançada.|
|[CRichEditView:: GetMargins](#getmargins)|Recupera as margens desta exibição de edição rica.|
|[CRichEditView::GetPageRect](#getpagerect)|Recupera o retângulo da página para esta exibição de edição rica.|
|[CRichEditView:: getwhiteize](#getpapersize)|Recupera o tamanho do papel para esta exibição de edição rica.|
|[CRichEditView::GetParaFormatSelection](#getparaformatselection)|Recupera os atributos de formatação de parágrafo para a seleção atual.|
|[CRichEditView::GetPrintRect](#getprintrect)|Recupera o retângulo de impressão desta exibição de edição rica.|
|[CRichEditView::GetPrintWidth](#getprintwidth)|Recupera a largura de impressão desta exibição de edição rica.|
|[CRichEditView::GetRichEditCtrl](#getricheditctrl)|Recupera o controle de edição rico.|
|[CRichEditView:: GetSelectedItem](#getselecteditem)|Recupera o item selecionado da exibição edição rica.|
|[CRichEditView::GetTextLength](#gettextlength)|Recupera o comprimento do texto na exibição de edição rica.|
|[CRichEditView::GetTextLengthEx](#gettextlengthex)|Recupera o número de caracteres ou bytes na exibição de edição rica. Lista de sinalizadores expandida para o método de determinação do comprimento.|
|[CRichEditView::InsertFileAsObject](#insertfileasobject)|Insere um arquivo como um item OLE.|
|[CRichEditView:: InsertItem](#insertitem)|Insere um novo item como um item OLE.|
|[CRichEditView::IsRichEditFormat](#isricheditformat)|Informa se a área de transferência contém dados em uma edição rica ou em um formato de texto.|
|[CRichEditView::OnCharEffect](#onchareffect)|Alterna a formatação de caractere para a seleção atual.|
|[CRichEditView::OnParaAlign](#onparaalign)|Altera o alinhamento dos parágrafos.|
|[CRichEditView::OnUpdateCharEffect](#onupdatechareffect)|Atualiza a interface do usuário de comando para funções de membro público de caractere.|
|[CRichEditView::OnUpdateParaAlign](#onupdateparaalign)|Atualiza a interface do usuário de comando para funções de membro público de parágrafo.|
|[CRichEditView::P rintInsideRect](#printinsiderect)|Formata o texto especificado dentro do retângulo fornecido.|
|[CRichEditView::P rintPage](#printpage)|Formata o texto especificado dentro da página especificada.|
|[CRichEditView::SetCharFormat](#setcharformat)|Define os atributos de formatação de caractere para a seleção atual.|
|[CRichEditView:: SetMargins](#setmargins)|Define as margens para esta exibição de edição avançada.|
|[CRichEditView:: setpapers](#setpapersize)|Define o tamanho do papel para esta exibição de edição avançada.|
|[CRichEditView::SetParaFormat](#setparaformat)|Define os atributos de formatação de parágrafo para a seleção atual.|
|[CRichEditView::TextNotFound](#textnotfound)|Redefine o estado de pesquisa interno do controle.|

### <a name="protected-methods"></a>Métodos protegidos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CRichEditView::GetClipboardData](#getclipboarddata)|Recupera um objeto da área de transferência para um intervalo nesta exibição de edição rica.|
|[CRichEditView:: GetContextMenu](#getcontextmenu)|Recupera um menu de contexto a ser usado em um botão direito do mouse.|
|[CRichEditView:: IsSelected](#isselected)|Indica se o item OLE fornecido está selecionado ou não.|
|[CRichEditView::OnFindNext](#onfindnext)|Localiza a próxima ocorrência de uma subcadeia de caracteres.|
|[CRichEditView::OnInitialUpdate](#oninitialupdate)|Atualiza uma exibição quando é anexada pela primeira vez a um documento.|
|[CRichEditView::OnPasteNativeObject](#onpastenativeobject)|Recupera dados nativos de um item OLE.|
|[CRichEditView:: OnPrinterChanged](#onprinterchanged)|Define as características de impressão para o dispositivo especificado.|
|[CRichEditView::OnReplaceAll](#onreplaceall)|Substitui todas as ocorrências de determinada cadeia de caracteres por uma nova cadeia de caracteres.|
|[CRichEditView::OnReplaceSel](#onreplacesel)|Substitui a seleção atual.|
|[CRichEditView::OnTextNotFound](#ontextnotfound)|Manipula a notificação do usuário de que o texto solicitado não foi encontrado.|
|[CRichEditView::QueryAcceptData](#queryacceptdata)|Consultas para ver sobre os dados no `IDataObject`.|
|[CRichEditView:: WrapChanged](#wrapchanged)|Ajusta o dispositivo de saída de destino para essa exibição de edição avançada, com base no valor de `m_nWordWrap`.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CRichEditView:: m_nBulletIndent](#m_nbulletindent)|Indica a quantidade de recuo para listas com marcadores.|
|[CRichEditView:: m_nWordWrap](#m_nwordwrap)|Indica as restrições de quebra automática de palavra.|

## <a name="remarks"></a>Comentários

Um "controle de edição rico" é uma janela na qual o usuário pode inserir e editar texto. O texto pode ser atribuído à formatação de caractere e de parágrafo e pode incluir objetos OLE incorporados. Os controles de edição avançados fornecem uma interface de programação para formatar texto. No entanto, um aplicativo deve implementar quaisquer componentes de interface do usuário necessários para disponibilizar as operações de formatação para o usuário.

`CRichEditView` mantém a característica de texto e formatação do texto. `CRichEditDoc` mantém a lista de itens de cliente OLE que estão na exibição. `CRichEditCntrItem` fornece acesso do lado do contêiner ao item do cliente OLE.

Esse controle comum do Windows (e, portanto, o [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md) e as classes relacionadas) está disponível somente para programas em execução no Windows 95/98 e no Windows NT versões 3,51 e posteriores.

Para obter um exemplo de como usar uma exibição de edição rica em um aplicativo MFC, consulte o aplicativo de exemplo do [WordPad](../../overview/visual-cpp-samples.md) .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cvisualização](../../mfc/reference/cview-class.md)

[CCtrlView](../../mfc/reference/cctrlview-class.md)

`CRichEditView`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** afxrich. h

##  <a name="adjustdialogposition"></a>CRichEditView::AdjustDialogPosition

Chame essa função para mover a caixa de diálogo fornecida para que ela não oculte a seleção atual.

```
void AdjustDialogPosition(CDialog* pDlg);
```

### <a name="parameters"></a>Parâmetros

*pDlg*<br/>
Ponteiro para um objeto `CDialog`.

##  <a name="canpaste"></a>CRichEditView:: CanPaste

Chame essa função para determinar se a área de transferência contém informações que podem ser coladas nesta exibição de edição rica.

```
BOOL CanPaste() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a área de transferência contiver dados em um formato que essa exibição de edição avançada possa aceitar; caso contrário, 0.

##  <a name="cricheditview"></a>CRichEditView::CRichEditView

Chame essa função para criar um objeto de `CRichEditView`.

```
CRichEditView();
```

##  <a name="dopaste"></a>CRichEditView::D oPaste

Chame essa função para colar o item OLE em *dataobj* nesse documento/exibição Rich Edit.

```
void DoPaste(
    COleDataObject& dataobj,
    CLIPFORMAT cf,
    HMETAFILEPICT hMetaPict);
```

### <a name="parameters"></a>Parâmetros

*dataobj*<br/>
O [COleDataObject](../../mfc/reference/coledataobject-class.md) que contém os dados a serem colados.

*CF*<br/>
O formato de área de transferência desejado.

*hMetaPict*<br/>
O metarquivo que representa o item a ser colado.

### <a name="remarks"></a>Comentários

A estrutura chama essa função como parte da implementação padrão de [QueryAcceptData](#queryacceptdata).

Essa função determina o tipo de colagem com base nos resultados do manipulador para colar especial. Se o *CF* for 0, o novo item usará a representação icônico atual. Se o *CF* for diferente de zero e *HMETAPICT* não for nulo, o novo item usará *hMetaPict* para sua representação.

##  <a name="findtext"></a>CRichEditView:: LocalizarTexto

Chame essa função para localizar o texto especificado e defini-lo como a seleção atual.

```
BOOL FindText(
    LPCTSTR lpszFind,
    BOOL bCase = TRUE,
    BOOL bWord = TRUE,
    BOOL bNext = TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszFind*<br/>
Contém a cadeia de caracteres a ser pesquisada.

*bCase*<br/>
Indica se a pesquisa diferencia maiúsculas de minúsculas.

*bWord*<br/>
Indica se a pesquisa deve corresponder apenas a palavras inteiras, não partes de palavras.

*bNext*<br/>
Indica a direção da pesquisa. Se for TRUE, a direção da pesquisa será para o final do buffer. Se for FALSE, a direção da pesquisa será para o início do buffer.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o texto *lpszFind* for encontrado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função exibe o cursor de espera durante a operação de localização.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#151](../../mfc/codesnippet/cpp/cricheditview-class_1.cpp)]

##  <a name="findtextsimple"></a>CRichEditView::FindTextSimple

Chame essa função para localizar o texto especificado e defini-lo como a seleção atual.

```
BOOL FindTextSimple(
    LPCTSTR lpszFind,
    BOOL bCase = TRUE,
    BOOL bWord = TRUE,
    BOOL bNext = TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszFind*<br/>
Contém a cadeia de caracteres a ser pesquisada.

*bCase*<br/>
Indica se a pesquisa diferencia maiúsculas de minúsculas.

*bWord*<br/>
Indica se a pesquisa deve corresponder apenas a palavras inteiras, não partes de palavras.

*bNext*<br/>
Indica a direção da pesquisa. Se for TRUE, a direção da pesquisa será para o final do buffer. Se for FALSE, a direção da pesquisa será para o início do buffer.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o texto *lpszFind* for encontrado; caso contrário, 0.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo para [CRichEditView:: LocalizarTexto](#findtext).

##  <a name="getcharformatselection"></a>CRichEditView::GetCharFormatSelection

Chame essa função para obter os atributos de formatação de caracteres da seleção atual.

```
CHARFORMAT2& GetCharFormatSelection();
```

### <a name="return-value"></a>Valor retornado

Uma estrutura [CHARFORMAT2](/windows/win32/api/richedit/ns-richedit-charformat2w) que contém os atributos de formatação de caracteres da seleção atual.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte a mensagem [EM_GETCHARFORMAT](/windows/win32/Controls/em-getcharformat) e a estrutura [CHARFORMAT2](/windows/win32/api/richedit/ns-richedit-charformat2w) no SDK do Windows.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#152](../../mfc/codesnippet/cpp/cricheditview-class_2.cpp)]

##  <a name="getclipboarddata"></a>CRichEditView::GetClipboardData

A estrutura chama essa função como parte do processamento de [IRichEditOleCallback:: GetClipboardData](/windows/win32/api/richole/nf-richole-iricheditolecallback-getclipboarddata).

```
virtual HRESULT GetClipboardData(
    CHARRANGE* lpchrg,
    DWORD dwReco,
    LPDATAOBJECT lpRichDataObj,
    LPDATAOBJECT* lplpdataobj);
```

### <a name="parameters"></a>Parâmetros

*lpchrg*<br/>
Ponteiro para a estrutura [CHARRANGE](/windows/win32/api/richedit/ns-richedit-charrange) especificando o intervalo de caracteres (e os itens OLE) a serem copiados para o objeto de dados especificado por *lplpdataobj*.

*dwReco*<br/>
Sinalizador de operação da área de transferência. Pode ser um desses valores.

- RECO_COPY copiar para a área de transferência.

- RECO_CUT recortar para a área de transferência.

- RECO_DRAG operação de arrastar (arrastar e soltar).

- Operação de remoção de RECO_DROP (arrastar e soltar).

- RECO_PASTE colar da área de transferência.

*lpRichDataObj*<br/>
Ponteiro para um objeto [IDataObject](/windows/win32/api/objidl/nn-objidl-idataobject) que contém os dados da área de transferência do controle rich edit ( [IRichEditOle:: GetClipboardData](/windows/win32/api/richole/nf-richole-iricheditole-getclipboarddata)).

*lplpdataobj*<br/>
Ponteiro para a variável de ponteiro que recebe o endereço do `IDataObject` objeto que representa o intervalo especificado no parâmetro *lpchrg* . O valor de *lplpdataobj* será ignorado se um erro for retornado.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT que relata o êxito da operação. Para obter mais informações sobre HRESULT, consulte [estrutura de códigos de erro com](/windows/win32/com/structure-of-com-error-codes) no SDK do Windows.

### <a name="remarks"></a>Comentários

Se o valor de retorno indicar êxito, `IRichEditOleCallback::GetClipboardData` retornará o `IDataObject` acessado por *lplpdataobj*; caso contrário, ele retorna o que é acessado pelo *lpRichDataObj*. Substitua essa função para fornecer seus próprios dados da área de transferência. A implementação padrão dessa função retorna E_NOTIMPL.

Esse é um substituível avançado.

Para obter mais informações, consulte [IRichEditOle:: GetClipboardData](/windows/win32/api/richole/nf-richole-iricheditole-getclipboarddata), [IRichEditOleCallback:: GetClipboardData](/windows/win32/api/richole/nf-richole-iricheditolecallback-getclipboarddata)e [CHARRANGE](/windows/win32/api/richedit/ns-richedit-charrange) no SDK do Windows e consulte [IDataObject](/windows/win32/api/objidl/nn-objidl-idataobject) no SDK do Windows.

##  <a name="getcontextmenu"></a>CRichEditView:: GetContextMenu

A estrutura chama essa função como parte do processamento de [IRichEditOleCallback:: GetContextMenu](/windows/win32/api/richole/nf-richole-iricheditolecallback-getcontextmenu).

```
virtual HMENU GetContextMenu(
    WORD seltyp,
    LPOLEOBJECT lpoleobj,
    CHARRANGE* lpchrg);
```

### <a name="parameters"></a>Parâmetros

*seltyp*<br/>
O tipo de seleção. Os valores de tipo de seleção são descritos na seção comentários.

*lpoleobj*<br/>
Ponteiro para uma estrutura de `OLEOBJECT` especificando o primeiro objeto OLE selecionado se a seleção contiver um ou mais itens OLE. Se a seleção não contiver nenhum item, *lpoleobj* será nulo. A estrutura de `OLEOBJECT` contém um ponteiro para uma tabela v de objeto OLE.

*lpchrg*<br/>
Ponteiro para uma estrutura [CHARRANGE](/windows/win32/api/richedit/ns-richedit-charrange) que contém a seleção atual.

### <a name="return-value"></a>Valor retornado

Identificador para o menu de contexto.

### <a name="remarks"></a>Comentários

Essa função é uma parte típica do processamento do botão direito do mouse para baixo.

O tipo de seleção pode ser qualquer combinação dos seguintes sinalizadores:

- SEL_EMPTY Indica que não há seleção atual.

- SEL_TEXT indica que a seleção atual contém texto.

- SEL_OBJECT indica que a seleção atual contém pelo menos um item OLE.

- SEL_MULTICHAR Indica que a seleção atual contém mais de um caractere de texto.

- SEL_MULTIOBJECT Indica que a seleção atual contém mais de um objeto OLE.

A implementação padrão retorna NULL. Esse é um substituível avançado.

Para obter mais informações, consulte [IRichEditOleCallback:: GetContextMenu](/windows/win32/api/richole/nf-richole-iricheditolecallback-getcontextmenu) e [CHARRANGE](/windows/win32/api/richedit/ns-richedit-charrange) no SDK do Windows.

##  <a name="getdocument"></a>CRichEditView:: GetDocument

Chame essa função para obter um ponteiro para o `CRichEditDoc` associado a essa exibição.

```
CRichEditDoc* GetDocument() const;
```

### <a name="return-value"></a>Valor retornado

Ponteiro para um objeto [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md) associado ao seu objeto `CRichEditView`.

##  <a name="getinplaceactiveitem"></a>CRichEditView::GetInPlaceActiveItem

Chame essa função para obter o item OLE que está atualmente ativado no local neste `CRichEditView` objeto.

```
CRichEditCntrItem* GetInPlaceActiveItem() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o único objeto Active [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md) no local neste modo de exibição de edição avançado; NULL se não houver nenhum item OLE atualmente no estado ativo in-loco.

##  <a name="getmargins"></a>CRichEditView:: GetMargins

Chame essa função para recuperar as margens atuais usadas na impressão.

```
CRect GetMargins() const;
```

### <a name="return-value"></a>Valor retornado

As margens usadas na impressão, medidas em MM_TWIPS.

##  <a name="getpagerect"></a>CRichEditView::GetPageRect

Chame essa função para obter as dimensões da página usada na impressão.

```
CRect GetPageRect() const;
```

### <a name="return-value"></a>Valor retornado

Os limites da página usados na impressão, medidos em MM_TWIPS.

### <a name="remarks"></a>Comentários

Esse valor é baseado no tamanho do papel.

##  <a name="getpapersize"></a>CRichEditView:: getwhiteize

Chame essa função para recuperar o tamanho do papel atual.

```
CSize GetPaperSize() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho do papel usado na impressão, medido em MM_TWIPS.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#153](../../mfc/codesnippet/cpp/cricheditview-class_3.cpp)]

##  <a name="getparaformatselection"></a>CRichEditView::GetParaFormatSelection

Chame essa função para obter os atributos de formatação de parágrafo da seleção atual.

```
PARAFORMAT2& GetParaFormatSelection();
```

### <a name="return-value"></a>Valor retornado

Uma estrutura [PARAFORMAT2](/windows/win32/api/richedit/ns-richedit-paraformat2) que contém os atributos de formatação de parágrafo da seleção atual.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [EM_GETPARAFORMAT](/windows/win32/Controls/em-getparaformat) mensagem e estrutura [PARAFORMAT2](/windows/win32/api/richedit/ns-richedit-paraformat2) no SDK do Windows.

##  <a name="getprintrect"></a>CRichEditView::GetPrintRect

Chame essa função para recuperar os limites da área de impressão dentro do retângulo da página.

```
CRect GetPrintRect() const;
```

### <a name="return-value"></a>Valor retornado

Os limites da área da imagem usada na impressão, medida em MM_TWIPS.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#154](../../mfc/codesnippet/cpp/cricheditview-class_4.cpp)]

##  <a name="getprintwidth"></a>CRichEditView::GetPrintWidth

Chame essa função para determinar a largura da área de impressão.

```
int GetPrintWidth() const;
```

### <a name="return-value"></a>Valor retornado

A largura da área de impressão, medida em MM_TWIPS.

##  <a name="getricheditctrl"></a>CRichEditView::GetRichEditCtrl

Chame essa função para recuperar o objeto [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md) associado ao objeto `CRichEditView`.

```
CRichEditCtrl& GetRichEditCtrl() const;
```

### <a name="return-value"></a>Valor retornado

O objeto `CRichEditCtrl` para esta exibição.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo para [CRichEditView:: LocalizarTexto](#findtext).

##  <a name="getselecteditem"></a>CRichEditView:: GetSelectedItem

Chame essa função para recuperar o item OLE (um objeto `CRichEditCntrItem`) selecionado atualmente neste objeto de `CRichEditView`.

```
CRichEditCntrItem* GetSelectedItem() const;
```

### <a name="return-value"></a>Valor retornado

Ponteiro para um objeto [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md) selecionado no objeto `CRichEditView`; NULL se nenhum item for selecionado nesta exibição.

##  <a name="gettextlength"></a>CRichEditView::GetTextLength

Chame essa função para recuperar o comprimento do texto neste `CRichEditView` objeto.

```
long GetTextLength() const;
```

### <a name="return-value"></a>Valor retornado

O comprimento do texto neste `CRichEditView` objeto.

##  <a name="gettextlengthex"></a>CRichEditView::GetTextLengthEx

Chame essa função de membro para calcular o comprimento do texto neste `CRichEditView` objeto.

```
long GetTextLengthEx(
    DWORD dwFlags,
    UINT uCodePage = -1) const;
```

### <a name="parameters"></a>Parâmetros

*dwFlags*<br/>
Valor que especifica o método a ser usado para determinar o comprimento do texto. Esse membro pode ser um ou mais dos valores listados no membro flags de [GETTEXTLENGTHEX](/windows/win32/api/richedit/ns-richedit-gettextlengthex) descrito na SDK do Windows.

*uCodePage*<br/>
Página de código para tradução (CP_ACP para página de código ANSI, 1200 para Unicode).

### <a name="return-value"></a>Valor retornado

O número de caracteres ou bytes no controle de edição. Se sinalizadores incompatíveis tiverem sido definidos em *dwFlags*, essa função de membro retornará E_INVALIDARG.

### <a name="remarks"></a>Comentários

`GetTextLengthEx` fornece maneiras adicionais de determinar o comprimento do texto. Ele dá suporte à funcionalidade rich edit 2,0. Para obter mais informações, consulte [sobre os controles de edição avançados](/windows/win32/Controls/about-rich-edit-controls) no SDK do Windows.

##  <a name="insertfileasobject"></a>CRichEditView::InsertFileAsObject

Chame essa função para inserir o arquivo especificado (como um objeto [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md) ) em uma exibição de edição rica.

```
void InsertFileAsObject(LPCTSTR lpszFileName);
```

### <a name="parameters"></a>Parâmetros

*lpszFileName*<br/>
Cadeia de caracteres que contém o nome do arquivo a ser inserido.

##  <a name="insertitem"></a>CRichEditView:: InsertItem

Chame essa função para inserir um objeto [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md) em uma exibição de edição rica.

```
HRESULT InsertItem(CRichEditCntrItem* pItem);
```

### <a name="parameters"></a>Parâmetros

*pItem*<br/>
Ponteiro para o item a ser inserido.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT que indica o sucesso da inserção.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre HRESULT, consulte [estrutura de códigos de erro com](/windows/win32/com/structure-of-com-error-codes) no SDK do Windows.

##  <a name="isricheditformat"></a>CRichEditView::IsRichEditFormat

Chame essa função para determinar se o *CF* é um formato de área de transferência que é texto, Rich Text ou Rich Text com itens OLE.

```
static BOOL AFX_CDECL IsRichEditFormat(CLIPFORMAT cf);
```

### <a name="parameters"></a>Parâmetros

*CF*<br/>
O formato de área de transferência de interesse.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o *CF* for um formato de área de transferência de Rich Text ou de edição.

##  <a name="isselected"></a>CRichEditView:: IsSelected

Chame essa função para determinar se o item OLE especificado está selecionado atualmente neste modo de exibição.

```
virtual BOOL IsSelected(const CObject* pDocItem) const;
```

### <a name="parameters"></a>Parâmetros

*pDocItem*<br/>
Ponteiro para um objeto na exibição.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o objeto for selecionado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Substitua essa função se a classe de exibição derivada tiver um método diferente para lidar com a seleção de itens OLE.

##  <a name="m_nbulletindent"></a>CRichEditView:: m_nBulletIndent

O recuo de itens de marcador em uma lista; Por padrão, 720 unidades, que é de 1/2 polegadas.

```
int m_nBulletIndent;
```

##  <a name="m_nwordwrap"></a>CRichEditView:: m_nWordWrap

Indica o tipo de quebra automática de texto para esta exibição de edição rica.

```
int m_nWordWrap;
```

### <a name="remarks"></a>Comentários

Um dos seguintes valores:

- `WrapNone` não indica nenhum encapsulamento automático de palavras.

- `WrapToWindow` indica quebra automática de palavra com base na largura da janela.

- `WrapToTargetDevice` indica quebra automática de palavra com base nas características do dispositivo de destino.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo para [CRichEditView:: WrapChanged](#wrapchanged).

##  <a name="onchareffect"></a>CRichEditView::OnCharEffect

Chame essa função para alternar os efeitos de formatação de caractere para a seleção atual.

```
void OnCharEffect(
    DWORD dwMask,
    DWORD dwEffect);
```

### <a name="parameters"></a>Parâmetros

*dwMask*<br/>
Os efeitos de formatação de caractere a serem modificados na seleção atual.

*dwEffect*<br/>
A lista desejada de efeitos de formatação de caracteres a serem alternados.

### <a name="remarks"></a>Comentários

Cada chamada para essa função alterna os efeitos de formatação especificados para a seleção atual.

Para obter mais informações sobre os parâmetros *dwMask* e *dwEffect* e seus valores possíveis, consulte os membros de dados correspondentes de [CHARFORMAT](/windows/win32/api/richedit/ns-richedit-charformata) no SDK do Windows.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#155](../../mfc/codesnippet/cpp/cricheditview-class_5.cpp)]

##  <a name="onfindnext"></a>CRichEditView::OnFindNext

Chamado pelo Framework ao processar comandos da caixa de diálogo localizar/substituir.

```
virtual void OnFindNext(
    LPCTSTR lpszFind,
    BOOL bNext,
    BOOL bCase,
    BOOL bWord);
```

### <a name="parameters"></a>Parâmetros

*lpszFind*<br/>
A cadeia de caracteres a ser localizada.

*bNext*<br/>
A direção da pesquisa: TRUE indica inoperante; FALSE, para cima.

*bCase*<br/>
Indica se a pesquisa deve diferenciar maiúsculas de minúsculas.

*bWord*<br/>
Indica se a pesquisa deve corresponder apenas a palavras inteiras ou não.

### <a name="remarks"></a>Comentários

Chame essa função para localizar texto dentro do `CRichEditView`. Substitua essa função para alterar as características de pesquisa para sua classe de exibição derivada.

##  <a name="oninitialupdate"></a>CRichEditView::OnInitialUpdate

Chamado pelo Framework depois que a exibição é anexada primeiro ao documento, mas antes de a exibição ser inicialmente exibida.

```
virtual void OnInitialUpdate();
```

### <a name="remarks"></a>Comentários

A implementação padrão dessa função chama a função de membro [cvisualização:: OnUpdate](../../mfc/reference/cview-class.md#onupdate) sem informações de dica (isto é, usando os valores padrão de 0 para o parâmetro *lHint* e NULL para o parâmetro *pHint* ). Substitua essa função para executar uma inicialização única que exija informações sobre o documento. Por exemplo, se seu aplicativo tiver documentos de tamanho fixo, você poderá usar essa função para inicializar os limites de rolagem de uma exibição com base no tamanho do documento. Se seu aplicativo der suporte a documentos de tamanho variável, use `OnUpdate` para atualizar os limites de rolagem sempre que o documento for alterado.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo de [CRichEditView:: m_nWordWrap](#m_nwordwrap).

##  <a name="onpastenativeobject"></a>CRichEditView::OnPasteNativeObject

Use essa função para carregar dados nativos de um item inserido.

```
virtual BOOL OnPasteNativeObject(LPSTORAGE lpStg);
```

### <a name="parameters"></a>Parâmetros

*lpStg*<br/>
Ponteiro para um objeto [IStorage](/windows/win32/api/objidl/nn-objidl-istorage) .

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0;

### <a name="remarks"></a>Comentários

Normalmente, você faria isso criando um [COleStreamFile](../../mfc/reference/colestreamfile-class.md) em relação ao `IStorage`. O `COleStreamFile` pode ser anexado a um arquivo morto e [CObject:: Serialize](../../mfc/reference/cobject-class.md#serialize) chamado para carregar os dados.

Esse é um substituível avançado.

Para obter mais informações, consulte [IStorage](/windows/win32/api/objidl/nn-objidl-istorage) no SDK do Windows.

##  <a name="onparaalign"></a>CRichEditView::OnParaAlign

Chame essa função para alterar o alinhamento de parágrafo para os parágrafos selecionados.

```
void OnParaAlign(WORD wAlign);
```

### <a name="parameters"></a>Parâmetros

*wAlign*<br/>
Alinhamento de parágrafo desejado. Um dos seguintes valores:

- PFA_LEFT alinhar os parágrafos com a margem esquerda.

- PFA_RIGHT Alinhar os parágrafos com a margem direita.

- PFA_CENTER centralizar os parágrafos entre as margens.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#156](../../mfc/codesnippet/cpp/cricheditview-class_6.cpp)]

##  <a name="onprinterchanged"></a>CRichEditView:: OnPrinterChanged

Substitua essa função para alterar as características dessa exibição de edição avançada quando a impressora for alterada.

```
virtual void OnPrinterChanged(const CDC& dcPrinter);
```

### <a name="parameters"></a>Parâmetros

*dcPrinter*<br/>
Um objeto [CDC](../../mfc/reference/cdc-class.md) para a nova impressora.

### <a name="remarks"></a>Comentários

A implementação padrão define o tamanho do papel para a altura física e a largura do dispositivo de saída (impressora). Se não houver nenhum contexto de dispositivo associado a *dcPrinter*, a implementação padrão definirá o tamanho do papel como 8,5 por 11 polegadas.

##  <a name="onreplaceall"></a>CRichEditView::OnReplaceAll

Chamado pelo Framework ao processar substituir todos os comandos da caixa de diálogo substituir.

```
virtual void OnReplaceAll(
    LPCTSTR lpszFind,
    LPCTSTR lpszReplace,
    BOOL bCase,
    BOOL bWord);
```

### <a name="parameters"></a>Parâmetros

*lpszFind*<br/>
O texto a ser substituído.

*lpszReplace*<br/>
O texto de substituição.

*bCase*<br/>
Indica se a pesquisa diferencia maiúsculas de minúsculas.

*bWord*<br/>
Indica se a pesquisa deve selecionar palavras inteiras ou não.

### <a name="remarks"></a>Comentários

Chame essa função para substituir todas as ocorrências de um determinado texto por outra cadeia de caracteres. Substitua essa função para alterar as características da pesquisa para esta exibição.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo para [CRichEditView:: LocalizarTexto](#findtext).

##  <a name="onreplacesel"></a>CRichEditView::OnReplaceSel

Chamado pelo Framework ao processar comandos Replace da caixa de diálogo substituir.

```
virtual void OnReplaceSel(
    LPCTSTR lpszFind,
    BOOL bNext,
    BOOL bCase,
    BOOL bWord,
    LPCTSTR lpszReplace);
```

### <a name="parameters"></a>Parâmetros

*lpszFind*<br/>
O texto a ser substituído.

*bNext*<br/>
Indica a direção da pesquisa: TRUE está inoperante; FALSE, para cima.

*bCase*<br/>
Indica se a pesquisa diferencia maiúsculas de minúsculas.

*bWord*<br/>
Indica se a pesquisa deve selecionar palavras inteiras ou não.

*lpszReplace*<br/>
O texto de substituição.

### <a name="remarks"></a>Comentários

Chame essa função para substituir uma ocorrência de um determinado texto por outra cadeia de caracteres. Substitua essa função para alterar as características da pesquisa para esta exibição.

##  <a name="ontextnotfound"></a>CRichEditView::OnTextNotFound

Chamado pelo Framework sempre que uma pesquisa falha.

```
virtual void OnTextNotFound(LPCTSTR lpszFind);
```

### <a name="parameters"></a>Parâmetros

*lpszFind*<br/>
O texto que não foi encontrado.

### <a name="remarks"></a>Comentários

Substitua essa função para alterar a notificação de saída de um [MessageBeep](/windows/win32/api/winuser/nf-winuser-messagebeep).

Para obter mais informações, consulte [MessageBeep](/windows/win32/api/winuser/nf-winuser-messagebeep) no SDK do Windows.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#157](../../mfc/codesnippet/cpp/cricheditview-class_7.cpp)]

##  <a name="onupdatechareffect"></a>CRichEditView::OnUpdateCharEffect

A estrutura chama essa função para atualizar a interface do usuário do comando para comandos de efeito de caractere.

```
void OnUpdateCharEffect(
    CCmdUI* pCmdUI,
    DWORD dwMask,
    DWORD dwEffect);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Ponteiro para um objeto [CCmdUI](../../mfc/reference/ccmdui-class.md) .

*dwMask*<br/>
Indica a máscara de formatação de caracteres.

*dwEffect*<br/>
Indica o efeito de formatação de caractere.

### <a name="remarks"></a>Comentários

A máscara *dwMask* especifica quais atributos de formatação de caracteres verificar. Os sinalizadores *dwEffect* listam os atributos de formatação de caracteres a serem definidos/desmarcados.

Para obter mais informações sobre os parâmetros *dwMask* e *dwEffect* e seus valores possíveis, consulte os membros de dados correspondentes de [CHARFORMAT](/windows/win32/api/richedit/ns-richedit-charformata) no SDK do Windows.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#158](../../mfc/codesnippet/cpp/cricheditview-class_8.cpp)]

##  <a name="onupdateparaalign"></a>CRichEditView::OnUpdateParaAlign

A estrutura chama essa função para atualizar a interface do usuário do comando para comandos de efeito de parágrafo.

```
void OnUpdateParaAlign(
    CCmdUI* pCmdUI,
    WORD wAlign);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Ponteiro para um objeto [CCmdUI](../../mfc/reference/ccmdui-class.md) .

*wAlign*<br/>
O alinhamento de parágrafo a ser verificado. Um dos seguintes valores:

- PFA_LEFT alinhar os parágrafos com a margem esquerda.

- PFA_RIGHT Alinhar os parágrafos com a margem direita.

- PFA_CENTER centralizar os parágrafos entre as margens.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#159](../../mfc/codesnippet/cpp/cricheditview-class_9.cpp)]

##  <a name="printinsiderect"></a>CRichEditView::P rintInsideRect

Chame essa função para formatar um intervalo de texto em um controle de edição rico para caber em *rectLayout* para o dispositivo especificado pelo *PDC*.

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
[Rect](/windows/win32/api/windef/ns-windef-rect) ou [CRect](../../atl-mfc-shared/reference/crect-class.md) que define a área de saída.

*nIndexStart*<br/>
Índice de base zero do primeiro caractere a ser formatado.

*nIndexStop*<br/>
Índice de base zero do último caractere a ser formatado.

*bOutput*<br/>
Indica se o texto deve ser renderizado. Se for FALSE, o texto será apenas medido.

### <a name="return-value"></a>Valor retornado

O índice do último caractere que se ajusta à área de saída mais um.

### <a name="remarks"></a>Comentários

Normalmente, essa chamada é seguida por uma chamada para [CRichEditCtrl::D isplayband](../../mfc/reference/cricheditctrl-class.md#displayband) que gera a saída.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo para [CRichEditView:: Getpapers](#getpapersize).

##  <a name="printpage"></a>CRichEditView::P rintPage

Chame essa função para formatar um intervalo de texto em um controle de edição rico para o dispositivo de saída especificado pelo *PDC*.

```
long PrintPage(
    CDC* pDC,
    long nIndexStart,
    long nIndexStop);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Ponteiro para um contexto de dispositivo para saída de página.

*nIndexStart*<br/>
Índice de base zero do primeiro caractere a ser formatado.

*nIndexStop*<br/>
Índice de base zero do último caractere a ser formatado.

### <a name="return-value"></a>Valor retornado

O índice do último caractere que se ajusta à página mais um.

### <a name="remarks"></a>Comentários

O layout de cada página é controlado por [GetPageRect](#getpagerect) e [GetPrintRect](#getprintrect). Normalmente, essa chamada é seguida por uma chamada para [CRichEditCtrl::D isplayband](../../mfc/reference/cricheditctrl-class.md#displayband) que gera a saída.

Observe que as margens são relativas à página física, não à página lógica. Assim, as margens de zero geralmente serão cortadas pelo texto, pois muitas impressoras têm áreas não imprimíveis na página. Para evitar o recorte do texto, você deve chamar [SetMargins](#setmargins) e definir margens razoáveis antes da impressão.

##  <a name="queryacceptdata"></a>CRichEditView::QueryAcceptData

Chamado pelo Framework para colar um objeto na edição rica.

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
Ponteiro para o [IDataObject](/windows/win32/api/objidl/nn-objidl-idataobject) a ser consultado.

*lpcfFormat*<br/>
Ponteiro para o formato de dados aceitável.

*dwReco*<br/>
Não usado.

*bReally*<br/>
Indica se a operação de colagem deve continuar ou não.

*hMetaFile*<br/>
Um identificador para o metarquivo usado para desenhar o ícone do item.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT que relata o êxito da operação.

### <a name="remarks"></a>Comentários

Substitua essa função para lidar com a organização diferente de itens COM em sua classe de documento derivada. Esse é um substituível avançado.

Para obter mais informações sobre HRESULT e `IDataObject`, consulte [estrutura de códigos de erro com](/windows/win32/com/structure-of-com-error-codes) e [IDataObject](/windows/win32/api/objidl/nn-objidl-idataobject), respectivamente, na SDK do Windows.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#160](../../mfc/codesnippet/cpp/cricheditview-class_10.cpp)]

##  <a name="setcharformat"></a>CRichEditView::SetCharFormat

Chame essa função para definir os atributos de formatação de caracteres para o novo texto neste `CRichEditView` objeto.

```
void SetCharFormat(CHARFORMAT2 cf);
```

### <a name="parameters"></a>Parâmetros

*CF*<br/>
Estrutura [CHARFORMAT2](/windows/win32/api/richedit/ns-richedit-charformat2w) que contém os novos atributos de formatação de caractere padrão.

### <a name="remarks"></a>Comentários

Somente os atributos especificados pelo membro `dwMask` de *CF* são alterados por essa função.

Para obter mais informações, consulte [EM_SETCHARFORMAT](/windows/win32/Controls/em-setcharformat) mensagem e estrutura [CHARFORMAT2](/windows/win32/api/richedit/ns-richedit-charformat2w) no SDK do Windows.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#152](../../mfc/codesnippet/cpp/cricheditview-class_2.cpp)]

##  <a name="setmargins"></a>CRichEditView:: SetMargins

Chame essa função para definir as margens de impressão para esta exibição de edição avançada.

```
void SetMargins(const CRect& rectMargin);
```

### <a name="parameters"></a>Parâmetros

*rectMargin*<br/>
Os novos valores de margem para impressão, medidos em MM_TWIPS.

### <a name="remarks"></a>Comentários

Se [m_nWordWrap](#m_nwordwrap) for `WrapToTargetDevice`, você deverá chamar [WrapChanged](#wrapchanged) depois de usar essa função para ajustar as características de impressão.

Observe que as margens usadas pelo [PrintPage](#printpage) são relativas à página física, não à página lógica. Assim, as margens de zero geralmente serão cortadas pelo texto, pois muitas impressoras têm áreas não imprimíveis na página. Para evitar o recorte do texto, você deve chamar use `SetMargins` para definir margens de impressora razoáveis antes da impressão.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo para [CRichEditView:: Getpapers](#getpapersize).

##  <a name="setpapersize"></a>CRichEditView:: setpapers

Chame essa função para definir o tamanho do papel para imprimir esta exibição de edição rica.

```
void SetPaperSize(CSize sizePaper);
```

### <a name="parameters"></a>Parâmetros

*sizePaper*<br/>
Os novos valores de tamanho de papel para impressão, medidos em MM_TWIPS.

### <a name="remarks"></a>Comentários

Se [m_nWordWrap](#m_nwordwrap) for `WrapToTargetDevice`, você deverá chamar [WrapChanged](#wrapchanged) depois de usar essa função para ajustar as características de impressão.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#161](../../mfc/codesnippet/cpp/cricheditview-class_11.cpp)]

##  <a name="setparaformat"></a>CRichEditView::SetParaFormat

Chame essa função para definir os atributos de formatação de parágrafo para a seleção atual neste `CRichEditView` objeto.

```
BOOL SetParaFormat(PARAFORMAT2& pf);
```

### <a name="parameters"></a>Parâmetros

*pf*<br/>
Estrutura [PARAFORMAT2](/windows/win32/api/richedit/ns-richedit-paraformat2) que contém os novos atributos de formatação de parágrafo padrão.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Somente os atributos especificados pelo membro `dwMask` de *PF* são alterados por essa função.

Para obter mais informações, consulte [EM_SETPARAFORMAT](/windows/win32/Controls/em-setparaformat) mensagem e estrutura [PARAFORMAT2](/windows/win32/api/richedit/ns-richedit-paraformat2) no SDK do Windows.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#162](../../mfc/codesnippet/cpp/cricheditview-class_12.cpp)]

##  <a name="textnotfound"></a>CRichEditView::TextNotFound

Chame essa função para redefinir o estado de pesquisa interno do controle [CRichEditView](../../mfc/reference/cricheditview-class.md) após uma chamada com falha para [LocalizarTexto](#findtext).

```
void TextNotFound(LPCTSTR lpszFind);
```

### <a name="parameters"></a>Parâmetros

*lpszFind*<br/>
Contém a cadeia de texto que não foi encontrada.

### <a name="remarks"></a>Comentários

É recomendável que esse método seja chamado imediatamente após as chamadas com falha para [LocalizarTexto](#findtext) , de modo que o estado de pesquisa interno do controle seja redefinido corretamente.

O parâmetro *lpszFind* deve incluir o mesmo conteúdo que a cadeia de caracteres fornecida para [LocalizarTexto](#findtext). Depois de redefinir o estado de pesquisa interno, esse método chamará o método [OnTextNotFound](#ontextnotfound) com a cadeia de caracteres de pesquisa fornecida.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo para [CRichEditView:: LocalizarTexto](#findtext).

##  <a name="wrapchanged"></a>CRichEditView:: WrapChanged

Chame essa função quando as características de impressão forem alteradas ( [SetMargins](#setmargins) ou [setpaperize](#setpapersize)).

```
virtual void WrapChanged();
```

### <a name="remarks"></a>Comentários

Substitua essa função para modificar a maneira como o modo de exibição de edição avançada responde a alterações no [m_nWordWrap](#m_nwordwrap) ou nas características de impressão ( [OnPrinterChanged](#onprinterchanged)).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#163](../../mfc/codesnippet/cpp/cricheditview-class_13.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo de WORDPAD do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CCtrlView](../../mfc/reference/cctrlview-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CRichEditDoc](../../mfc/reference/cricheditdoc-class.md)<br/>
[Classe CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md)
