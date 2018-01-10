---
title: Classe CRichEditView | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs: C++
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
caps.latest.revision: "25"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c9062e9cf781363b482c5ee77238d315044be7df
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cricheditview-class"></a>Classe CRichEditView
Com [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md) e [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md), fornece a funcionalidade do controle de edição rico dentro do contexto da arquitetura de exibição de documento do MFC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CRichEditView : public CCtrlView  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRichEditView::CRichEditView](#cricheditview)|Constrói um objeto `CRichEditView`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRichEditView::AdjustDialogPosition](#adjustdialogposition)|Move uma caixa de diálogo para que ele não oculte a seleção atual.|  
|[CRichEditView::CanPaste](#canpaste)|Indica se a área de transferência contém dados que podem ser colados na exibição de edição rica.|  
|[CRichEditView::DoPaste](#dopaste)|Cola um item OLE em exibição de edição rica.|  
|[CRichEditView::FindText](#findtext)|Localiza o texto especificado, invocando o cursor de espera.|  
|[CRichEditView::FindTextSimple](#findtextsimple)|Localiza o texto especificado.|  
|[CRichEditView::GetCharFormatSelection](#getcharformatselection)|Recupera o caractere de formatação de atributos para a seleção atual.|  
|[CRichEditView::GetDocument](#getdocument)|Recupera um ponteiro para relacionado [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md).|  
|[CRichEditView::GetInPlaceActiveItem](#getinplaceactiveitem)|Recupera o item OLE que está ativo no momento no local no modo de exibição de edição rica.|  
|[CRichEditView::GetMargins](#getmargins)|Recupera as margens de exibição de edição rica.|  
|[CRichEditView::GetPageRect](#getpagerect)|Recupera o retângulo de página para exibição de edição rica.|  
|[CRichEditView::GetPaperSize](#getpapersize)|Recupera o tamanho do papel para exibição de edição rica.|  
|[CRichEditView::GetParaFormatSelection](#getparaformatselection)|Recupera os atributos para a seleção atual de formatação de parágrafo.|  
|[CRichEditView::GetPrintRect](#getprintrect)|Recupera o retângulo de impressão para este modo de exibição de edição rica.|  
|[CRichEditView::GetPrintWidth](#getprintwidth)|Recupera a largura de impressão para este modo de exibição de edição rica.|  
|[CRichEditView::GetRichEditCtrl](#getricheditctrl)|Recupera o controle de edição.|  
|[CRichEditView::GetSelectedItem](#getselecteditem)|Recupera o item selecionado da exibição de edição rica.|  
|[CRichEditView::GetTextLength](#gettextlength)|Recupera o comprimento do texto no modo de exibição de edição rica.|  
|[CRichEditView::GetTextLengthEx](#gettextlengthex)|Recupera o número de caracteres ou bytes na exibição de edição rica. Lista de sinalizador expandido para o método para determinar o comprimento.|  
|[CRichEditView::InsertFileAsObject](#insertfileasobject)|Insere um arquivo como um item OLE.|  
|[CRichEditView::InsertItem](#insertitem)|Insere um novo item como um item OLE.|  
|[CRichEditView::IsRichEditFormat](#isricheditformat)|Indica se a área de transferência contém dados em um formato de texto ou rich edit.|  
|[CRichEditView::OnCharEffect](#onchareffect)|Alterna a formatação de caracteres para a seleção atual.|  
|[CRichEditView::OnParaAlign](#onparaalign)|Altera o alinhamento dos parágrafos.|  
|[CRichEditView::OnUpdateCharEffect](#onupdatechareffect)|Atualiza a interface do usuário de comando para funções de membro público de caractere.|  
|[CRichEditView::OnUpdateParaAlign](#onupdateparaalign)|Atualiza a interface do usuário de comando para funções de membro público de parágrafo.|  
|[CRichEditView::PrintInsideRect](#printinsiderect)|Formata o texto especificado dentro do retângulo determinado.|  
|[CRichEditView::PrintPage](#printpage)|Formata o texto especificado na página fornecida.|  
|[CRichEditView::SetCharFormat](#setcharformat)|Define o caractere de formatação de atributos para a seleção atual.|  
|[CRichEditView::SetMargins](#setmargins)|Define as margens para este rich Editar modo de exibição.|  
|[CRichEditView::SetPaperSize](#setpapersize)|Define o tamanho do papel para exibição de edição rica.|  
|[CRichEditView::SetParaFormat](#setparaformat)|Define os atributos para a seleção atual de formatação de parágrafo.|  
|[CRichEditView::TextNotFound](#textnotfound)|Redefine o estado de pesquisa interna do controle.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRichEditView::GetClipboardData](#getclipboarddata)|Recupera um objeto da área de transferência para um intervalo de exibição de edição rica.|  
|[CRichEditView::GetContextMenu](#getcontextmenu)|Recupera um menu de contexto a ser usado em um botão direito do mouse para baixo.|  
|[CRichEditView::IsSelected](#isselected)|Indica se o item OLE fornecido está selecionado ou não.|  
|[CRichEditView::OnFindNext](#onfindnext)|Localiza a próxima ocorrência de uma subcadeia de caracteres.|  
|[CRichEditView::OnInitialUpdate](#oninitialupdate)|Atualiza um modo de exibição quando inicialmente anexado a um documento.|  
|[CRichEditView::OnPasteNativeObject](#onpastenativeobject)|Recupera dados nativos de um item OLE.|  
|[CRichEditView::OnPrinterChanged](#onprinterchanged)|Define as características de impressão para um determinado dispositivo.|  
|[CRichEditView::OnReplaceAll](#onreplaceall)|Substitui todas as ocorrências de uma determinada cadeia de caracteres com uma nova cadeia de caracteres.|  
|[CRichEditView::OnReplaceSel](#onreplacesel)|Substitui a seleção atual.|  
|[CRichEditView::OnTextNotFound](#ontextnotfound)|Identificadores de notificação do usuário que o texto solicitado não foi encontrado.|  
|[CRichEditView::QueryAcceptData](#queryacceptdata)|Consultas para ver sobre os dados sobre o `IDataObject`.|  
|[CRichEditView::WrapChanged](#wrapchanged)|Ajusta o dispositivo de saída de destino para este rich Editar modo de exibição, com base no valor de `m_nWordWrap`.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRichEditView::m_nBulletIndent](#m_nbulletindent)|Indica a quantidade de recuo para listas de marcador.|  
|[CRichEditView::m_nWordWrap](#m_nwordwrap)|Indica as restrições de quebra de palavras.|  
  
## <a name="remarks"></a>Comentários  
 Um "controle de edição avançada" é uma janela na qual o usuário pode inserir e editar texto. O texto pode ser atribuído a formatação de parágrafo e caracteres e pode incluir objetos OLE inseridos. Controles de edição avançada fornecem uma interface de programação de formatação de texto. No entanto, um aplicativo deve implementar quaisquer componentes de interface de usuário necessários para tornar as operações de formatação disponíveis para o usuário.  
  
 `CRichEditView`mantém a característica de formatação de texto e texto. `CRichEditDoc`mantém a lista de itens de cliente OLE que estão no modo de exibição. `CRichEditCntrItem`fornece acesso do lado do contêiner para o item de cliente OLE.  
  
 Esse controle comum do Windows (e, portanto, o [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md) e classes relacionadas) está disponível apenas para programas que executam versões do Windows 95/98 e Windows NT 3.51 e posterior.  
  
 Para obter um exemplo de como usar uma exibição de edição rica em um aplicativo MFC, consulte o [WORDPAD](../../visual-cpp-samples.md) aplicativo de exemplo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CView](../../mfc/reference/cview-class.md)  
  
 [CCtrlView](../../mfc/reference/cctrlview-class.md)  
  
 `CRichEditView`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrich.h  
  
##  <a name="adjustdialogposition"></a>CRichEditView::AdjustDialogPosition  
 Chame esta função para mover a caixa de diálogo fornecida para que ele não oculte a seleção atual.  
  
```  
void AdjustDialogPosition(CDialog* pDlg);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDlg*  
 Ponteiro para uma `CDialog` objeto.  
  
##  <a name="canpaste"></a>CRichEditView::CanPaste  
 Chame essa função para determinar se a área de transferência contém informações que podem ser coladas na exibição de edição rica.  
  
```  
BOOL CanPaste() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a área de transferência contém dados em um formato que pode aceitar a exibição de edição rica; Caso contrário, 0.  
  
##  <a name="cricheditview"></a>CRichEditView::CRichEditView  
 Chamar essa função para criar um `CRichEditView` objeto.  
  
```  
CRichEditView();
```  
  
##  <a name="dopaste"></a>CRichEditView::DoPaste  
 Chamar essa função para colar o item OLE em `dataobj` a esta exibição de documentos edição avançada.  
  
```  
void DoPaste(
    COleDataObject& dataobj,  
    CLIPFORMAT cf,  
    HMETAFILEPICT hMetaPict);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dataobj`  
 O [COleDataObject](../../mfc/reference/coledataobject-class.md) que contém os dados a ser colado.  
  
 `cf`  
 O formato desejado da área de transferência.  
  
 `hMetaPict`  
 O metarquivo que representa o item a ser colado.  
  
### <a name="remarks"></a>Comentários  
 O framework chama essa função como parte da implementação padrão do [QueryAcceptData](#queryacceptdata).  
  
 Esta função determina o tipo de acordo com os resultados do manipulador para colar especial de colar. Se `cf` for 0, o novo item usa a representação de ícone atual. Se `cf` é diferente de zero e `hMetaPict` não é **nulo**, usa o novo item `hMetaPict` para sua representação.  
  
##  <a name="findtext"></a>CRichEditView::FindText  
 Chame essa função para localizar o texto especificado e defini-lo para ser a seleção atual.  
  
```  
BOOL FindText(
    LPCTSTR lpszFind,  
    BOOL bCase = TRUE,  
    BOOL bWord = TRUE,  
    BOOL bNext = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFind`  
 Contém a cadeia de caracteres a ser pesquisado.  
  
 `bCase`  
 Indica se a pesquisa diferencia maiusculas de minúsculas.  
  
 `bWord`  
 Indica se a pesquisa deve coincidir palavra inteira, não as partes de palavras.  
  
 `bNext`  
 Indica a direção da pesquisa. Se **TRUE**, é a direção de pesquisa no final do buffer. Se **FALSE**, é a direção de pesquisa para o início do buffer.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o `lpszFind` texto for encontrado; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esta função exibe o cursor de espera durante a operação de localização.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#151](../../mfc/codesnippet/cpp/cricheditview-class_1.cpp)]  
  
##  <a name="findtextsimple"></a>CRichEditView::FindTextSimple  
 Chame essa função para localizar o texto especificado e defini-lo para ser a seleção atual.  
  
```  
BOOL FindTextSimple(
    LPCTSTR lpszFind,  
    BOOL bCase = TRUE,  
    BOOL bWord = TRUE,  
    BOOL bNext = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFind`  
 Contém a cadeia de caracteres a ser pesquisado.  
  
 `bCase`  
 Indica se a pesquisa diferencia maiusculas de minúsculas.  
  
 `bWord`  
 Indica se a pesquisa deve coincidir palavra inteira, não as partes de palavras.  
  
 `bNext`  
 Indica a direção da pesquisa. Se **TRUE**, é a direção de pesquisa no final do buffer. Se **FALSE**, é a direção de pesquisa para o início do buffer.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o `lpszFind` texto for encontrado; caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CRichEditView::FindText](#findtext).  
  
##  <a name="getcharformatselection"></a>CRichEditView::GetCharFormatSelection  
 Chame essa função para obter o atributos da seleção atual de formatação de caractere.  
  
```  
CHARFORMAT2& GetCharFormatSelection();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CHARFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787883) estrutura que contém o caractere de formatação atributos da seleção atual.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte o [EM_GETCHARFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb788026) mensagem e o [CHARFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787883) estrutura no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#152](../../mfc/codesnippet/cpp/cricheditview-class_2.cpp)]  
  
##  <a name="getclipboarddata"></a>CRichEditView::GetClipboardData  
 O framework chama essa função como parte do processamento do [IRichEditOleCallback::GetClipboardData](http://msdn.microsoft.com/library/windows/desktop/bb774315).  
  
```  
virtual HRESULT GetClipboardData(
    CHARRANGE* lpchrg,  
    DWORD dwReco,  
    LPDATAOBJECT lpRichDataObj,  
    LPDATAOBJECT* lplpdataobj);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpchrg`  
 Ponteiro para o [CHARRANGE](http://msdn.microsoft.com/library/windows/desktop/bb787885) estrutura especificando o intervalo de caracteres (e itens OLE) para copiar para o objeto de dados especificado pelo `lplpdataobj`.  
  
 `dwReco`  
 Sinalizador de operação de área de transferência. Pode ser um destes valores.  
  
- **RECO_COPY** copiar na área de transferência.  
  
- **RECO_CUT** Recortar para a área de transferência.  
  
- **RECO_DRAG** (arrastar e soltar) de operação de arrastar.  
  
- **RECO_DROP** Remover operação (arrastar e soltar).  
  
- **RECO_PASTE** colar da área de transferência.  
  
 `lpRichDataObj`  
 Ponteiro para um [IDataObject](http://msdn.microsoft.com/library/windows/desktop/ms688421) objeto que contém os dados de área de transferência do sofisticado controle de edição ( [IRichEditOle::GetClipboardData](http://msdn.microsoft.com/library/windows/desktop/bb774341)).  
  
 `lplpdataobj`  
 Ponteiro para a variável de ponteiro que recebe o endereço do `IDataObject` objeto que representa o intervalo especificado na `lpchrg` parâmetro. O valor de `lplpdataobj` será ignorado se um erro será retornado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `HRESULT` valor relatando o êxito da operação. Para obter mais informações sobre `HRESULT`, consulte [estrutura de códigos de erro COM](http://msdn.microsoft.com/library/windows/desktop/ms690088) no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Se o valor de retorno indica êxito, **IRichEditOleCallback::GetClipboardData** retorna o `IDataObject` acessados por `lplpdataobj`; caso contrário, ele retornará o acessados por `lpRichDataObj`. Substitua essa função para fornecer seus próprios dados de área de transferência. Retorna a implementação padrão dessa função **E_NOTIMPL**.  
  
 Isso é uma avançada substituível.  
  
 Para obter mais informações, consulte [IRichEditOle::GetClipboardData](http://msdn.microsoft.com/library/windows/desktop/bb774341), [IRichEditOleCallback::GetClipboardData](http://msdn.microsoft.com/library/windows/desktop/bb774315), e [CHARRANGE](http://msdn.microsoft.com/library/windows/desktop/bb787885) no SDK do Windows e consulte [IDataObject](http://msdn.microsoft.com/library/windows/desktop/ms688421) no SDK do Windows.  
  
##  <a name="getcontextmenu"></a>CRichEditView::GetContextMenu  
 O framework chama essa função como parte do processamento do [IRichEditOleCallback::GetContextMenu](http://msdn.microsoft.com/library/windows/desktop/bb774317).  
  
```  
virtual HMENU GetContextMenu(
    WORD seltyp,  
    LPOLEOBJECT lpoleobj,  
    CHARRANGE* lpchrg);
```  
  
### <a name="parameters"></a>Parâmetros  
 *seltyp*  
 O tipo de seleção. Os valores de tipo de seleção são descritos na seção comentários.  
  
 `lpoleobj`  
 Ponteiro para um **OLEOBJECT** estrutura especificando o primeiro objeto OLE selecionado se a seleção contém um ou mais itens OLE. Se a seleção não contém itens, `lpoleobj` é **nulo**. O **OLEOBJECT** estrutura contém um ponteiro para um objeto OLE v-table.  
  
 `lpchrg`  
 Ponteiro para um [CHARRANGE](http://msdn.microsoft.com/library/windows/desktop/bb787885) estrutura que contém a seleção atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Identificador para o menu de contexto.  
  
### <a name="remarks"></a>Comentários  
 Essa função é uma parte comum do botão direito do mouse para baixo de processamento.  
  
 O tipo de seleção pode ser qualquer combinação dos sinalizadores a seguir:  
  
- `SEL_EMPTY`Indica que não há nenhuma seleção atual.  
  
- `SEL_TEXT`Indica que a seleção atual contém texto.  
  
- `SEL_OBJECT`Indica que a seleção atual contém pelo menos um item OLE.  
  
- `SEL_MULTICHAR`Indica que a seleção atual contém mais de um caractere de texto.  
  
- `SEL_MULTIOBJECT`Indica que a seleção atual contém mais de um objeto OLE.  
  
 A implementação padrão retorna **nulo**. Isso é uma avançada substituível.  
  
 Para obter mais informações, consulte [IRichEditOleCallback::GetContextMenu](http://msdn.microsoft.com/library/windows/desktop/bb774317) e [CHARRANGE](http://msdn.microsoft.com/library/windows/desktop/bb787885) no SDK do Windows.  
  
 Para obter mais informações sobre o **OLEOBJECT** de tipo, consulte o artigo de estruturas de dados OLE e estrutura de alocação no *OLE da Base de Conhecimento*.  
  
##  <a name="getdocument"></a>CRichEditView::GetDocument  
 Chamar essa função para obter um ponteiro para o `CRichEditDoc` associado a esta exibição.  
  
```  
CRichEditDoc* GetDocument() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para um [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md) objeto associado ao seu `CRichEditView` objeto.  
  
##  <a name="getinplaceactiveitem"></a>CRichEditView::GetInPlaceActiveItem  
 Chamada para essa função para obter a OLE do item que está ativada atualmente em vigor na `CRichEditView` objeto.  
  
```  
CRichEditCntrItem* GetInPlaceActiveItem() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o ativo único, no local [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md) objeto na exibição de edição rica; **Nulo** se não houver nenhum item OLE no momento no estado ativo no local.  
  
##  <a name="getmargins"></a>CRichEditView::GetMargins  
 Chame essa função para recuperar as margens atuais usadas na impressão.  
  
```  
CRect GetMargins() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 As margens usadas na impressão, medido em `MM_TWIPS`.  
  
##  <a name="getpagerect"></a>CRichEditView::GetPageRect  
 Chame essa função para obter as dimensões da página usado na impressão.  
  
```  
CRect GetPageRect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Os limites da página usado na impressão, medido em `MM_TWIPS`.  
  
### <a name="remarks"></a>Comentários  
 Esse valor se baseia no tamanho de papel.  
  
##  <a name="getpapersize"></a>CRichEditView::GetPaperSize  
 Chame essa função para recuperar o tamanho do papel.  
  
```  
CSize GetPaperSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho do papel usado na impressão, medido em `MM_TWIPS`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#153](../../mfc/codesnippet/cpp/cricheditview-class_3.cpp)]  
  
##  <a name="getparaformatselection"></a>CRichEditView::GetParaFormatSelection  
 Chame essa função para obter os atributos da seleção atual de formatação de parágrafo.  
  
```  
PARAFORMAT2& GetParaFormatSelection();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [PARAFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787942) estrutura que contém os atributos da seleção atual de formatação de parágrafo.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [EM_GETPARAFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb774182) mensagem e [PARAFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787942) estrutura no SDK do Windows.  
  
##  <a name="getprintrect"></a>CRichEditView::GetPrintRect  
 Chame essa função para recuperar os limites da área de impressão dentro do retângulo de página.  
  
```  
CRect GetPrintRect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Os limites da área de imagem usado na impressão, medido em `MM_TWIPS`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#154](../../mfc/codesnippet/cpp/cricheditview-class_4.cpp)]  
  
##  <a name="getprintwidth"></a>CRichEditView::GetPrintWidth  
 Chame essa função para determinar a largura da área de impressão.  
  
```  
int GetPrintWidth() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A largura da área de impressão, medida em `MM_TWIPS`.  
  
##  <a name="getricheditctrl"></a>CRichEditView::GetRichEditCtrl  
 Chamar essa função para recuperar o [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md) objeto associado a `CRichEditView` objeto.  
  
```  
CRichEditCtrl& GetRichEditCtrl() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O `CRichEditCtrl` objeto para este modo de exibição.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CRichEditView::FindText](#findtext).  
  
##  <a name="getselecteditem"></a>CRichEditView::GetSelectedItem  
 Chamar essa função para recuperar o item OLE (um `CRichEditCntrItem` objeto) selecionado no momento neste `CRichEditView` objeto.  
  
```  
CRichEditCntrItem* GetSelectedItem() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para um [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md) objeto selecionado no `CRichEditView` do objeto; **Nulo** se nenhum item selecionado nessa exibição.  
  
##  <a name="gettextlength"></a>CRichEditView::GetTextLength  
 Chamar essa função para recuperar o comprimento do texto na `CRichEditView` objeto.  
  
```  
long GetTextLength() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento do texto na `CRichEditView` objeto.  
  
##  <a name="gettextlengthex"></a>CRichEditView::GetTextLengthEx  
 Chamar essa função de membro para calcular o comprimento do texto na `CRichEditView` objeto.  
  
```  
long GetTextLengthEx(
    DWORD dwFlags,  
    UINT uCodePage = -1) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwFlags`  
 Valor que especifica o método a ser usado para determinar o comprimento do texto. Esse membro pode ser um ou mais dos valores listados no membro sinalizadores [GETTEXTLENGTHEX](http://msdn.microsoft.com/library/windows/desktop/bb787915) descrito no SDK do Windows.  
  
 `uCodePage`  
 Página de código de conversão (CP_ACP para a página de código ANSI, 1200 para Unicode).  
  
### <a name="return-value"></a>Valor de retorno  
 O número de caracteres ou bytes no controle de edição. Se os sinalizadores incompatíveis foram definidos `dwFlags`, essa função de membro retorna `E_INVALIDARG`.  
  
### <a name="remarks"></a>Comentários  
 `GetTextLengthEx`oferece outras maneiras de determinar o comprimento do texto. Ele dá suporte a funcionalidade avançada Editar 2.0. Para obter mais informações, consulte [sobre Rich editar controles](http://msdn.microsoft.com/library/windows/desktop/bb787873) no SDK do Windows.  
  
##  <a name="insertfileasobject"></a>CRichEditView::InsertFileAsObject  
 Chamar essa função para inserir o arquivo especificado (como um [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md) objeto) em um conjunto avançado Editar modo de exibição.  
  
```  
void InsertFileAsObject(LPCTSTR lpszFileName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFileName`  
 Cadeia de caracteres que contém o nome do arquivo a ser inserido.  
  
##  <a name="insertitem"></a>CRichEditView::InsertItem  
 Chamar essa função para inserir um [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md) objeto em um modo de exibição de edição rica.  
  
```  
HRESULT InsertItem(CRichEditCntrItem* pItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pItem`  
 Ponteiro para o item a ser inserido.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `HRESULT` valor que indica o sucesso da inserção.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre `HRESULT`, consulte [estrutura de códigos de erro COM](http://msdn.microsoft.com/library/windows/desktop/ms690088) no SDK do Windows.  
  
##  <a name="isricheditformat"></a>CRichEditView::IsRichEditFormat  
 Chamar esta função para determinar se `cf` é um formato de área de transferência que é texto, rich text ou rich text com itens OLE.  
  
```  
static BOOL AFX_CDECL IsRichEditFormat(CLIPFORMAT cf);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cf`  
 O formato de área de interesse.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se `cf` é um formato de área de transferência editar ou texto avançado.  
  
##  <a name="isselected"></a>CRichEditView::IsSelected  
 Chame essa função para determinar se o item OLE especificado está selecionado atualmente neste modo de exibição.  
  
```  
virtual BOOL IsSelected(const CObject* pDocItem) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDocItem`  
 Ponteiro para um objeto no modo de exibição.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o objeto está selecionado. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função se sua classe derivada de exibição tem um método diferente para lidar com a seleção de itens OLE.  
  
##  <a name="m_nbulletindent"></a>CRichEditView::m_nBulletIndent  
 O recuo para itens de marcadores em uma lista; Por padrão, as unidades de 720, que é 1/2 polegadas.  
  
```  
int m_nBulletIndent;  
```  
  
##  <a name="m_nwordwrap"></a>CRichEditView::m_nWordWrap  
 Indica o tipo de quebra automática de linha para exibição de edição rica.  
  
```  
int m_nWordWrap;  
```  
  
### <a name="remarks"></a>Comentários  
 Um dos seguintes valores:  
  
- `WrapNone`Não indica que nenhuma quebra automática.  
  
- `WrapToWindow`Indica a quebra de texto com base na largura da janela.  
  
- `WrapToTargetDevice`Indica a quebra de texto com base nas características do dispositivo de destino.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CRichEditView::WrapChanged](#wrapchanged).  
  
##  <a name="onchareffect"></a>CRichEditView::OnCharEffect  
 Chame essa função para alternar o efeitos da seleção atual de formatação de caractere.  
  
```  
void OnCharEffect(
    DWORD dwMask,  
    DWORD dwEffect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwMask`  
 O caractere de formatação efeitos para modificar a seleção atual.  
  
 `dwEffect`  
 A lista desejada efeitos para alternar de formatação de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Cada chamada para essa função alterna os efeitos de formatação especificados para a seleção atual.  
  
 Para obter mais informações sobre o `dwMask` e `dwEffect` parâmetros e seus valores possíveis, consulte os membros de dados correspondente [CHARFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb787881) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#155](../../mfc/codesnippet/cpp/cricheditview-class_5.cpp)]  
  
##  <a name="onfindnext"></a>CRichEditView::OnFindNext  
 Chamado pelo framework quando o processamento de comandos na caixa de diálogo Localizar/Substituir.  
  
```  
virtual void OnFindNext(
    LPCTSTR lpszFind,  
    BOOL bNext,  
    BOOL bCase,  
    BOOL bWord);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFind`  
 A cadeia de caracteres para localizar.  
  
 `bNext`  
 A direção da pesquisa: **TRUE** indica para baixo; **FALSE**, até.  
  
 `bCase`  
 Indica se a pesquisa deve diferenciar maiusculas de minúsculas.  
  
 `bWord`  
 Indica se a pesquisa de palavras inteiras somente ou não.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função para localizar texto dentro de `CRichEditView`. Substitua essa função para alterar as características de pesquisa para a sua classe derivada de exibição.  
  
##  <a name="oninitialupdate"></a>CRichEditView::OnInitialUpdate  
 Chamado pelo framework depois que a exibição é anexado ao documento pela primeira vez, mas antes do modo de exibição é exibido inicialmente.  
  
```  
virtual void OnInitialUpdate();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão Esta função chama o [CView::OnUpdate](../../mfc/reference/cview-class.md#onupdate) a função de membro sem informações de dica (ou seja, usando os valores padrão de 0 para o `lHint` parâmetro e **nulo** para o `pHint` parâmetro). Substitua esta função para executar qualquer inicialização única que exige informações sobre o documento. Por exemplo, se seu aplicativo tiver documentos de tamanho fixo, você pode usar essa função para inicializar os limites de rolagem do modo de exibição com base no tamanho do documento. Se seu aplicativo dá suporte a documentos de tamanho variável, use `OnUpdate` atualizar a rolagem limita toda vez que as alterações de documento.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CRichEditView::m_nWordWrap](#m_nwordwrap).  
  
##  <a name="onpastenativeobject"></a>CRichEditView::OnPasteNativeObject  
 Use esta função para carregar dados nativos de um item inserido.  
  
```  
virtual BOOL OnPasteNativeObject(LPSTORAGE lpStg);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpStg*  
 Ponteiro para um [IStorage](http://msdn.microsoft.com/library/windows/desktop/aa380015) objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0;  
  
### <a name="remarks"></a>Comentários  
 Normalmente, você pode fazer isso criando um [COleStreamFile](../../mfc/reference/colestreamfile-class.md) em torno de `IStorage`. O `COleStreamFile` pode ser anexado a um arquivo morto e [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize) chamado para carregar os dados.  
  
 Isso é uma avançada substituível.  
  
 Para obter mais informações, consulte [IStorage](http://msdn.microsoft.com/library/windows/desktop/aa380015) no SDK do Windows.  
  
##  <a name="onparaalign"></a>CRichEditView::OnParaAlign  
 Chame essa função para alterar o alinhamento de parágrafo dos parágrafos selecionados.  
  
```  
void OnParaAlign(WORD wAlign);
```  
  
### <a name="parameters"></a>Parâmetros  
 `wAlign`  
 Alinhamento de parágrafo desejado. Um dos seguintes valores:  
  
- `PFA_LEFT`Alinhe os parágrafos com a margem esquerda.  
  
- `PFA_RIGHT`Alinhe os parágrafos com a margem direita.  
  
- `PFA_CENTER`Centralize os parágrafos entre as margens.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#156](../../mfc/codesnippet/cpp/cricheditview-class_6.cpp)]  
  
##  <a name="onprinterchanged"></a>CRichEditView::OnPrinterChanged  
 Substitua essa função para alterar as características de exibição de edição rica quando altera a impressora.  
  
```  
virtual void OnPrinterChanged(const CDC& dcPrinter);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dcPrinter`  
 Um [CDC](../../mfc/reference/cdc-class.md) objeto para a nova impressora.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão define o tamanho do papel como física altura e largura para o dispositivo de saída (impressora). Se não houver nenhum contexto de dispositivo associados `dcPrinter`, a implementação padrão define o tamanho do papel para 8,5 por 11 polegadas.  
  
##  <a name="onreplaceall"></a>CRichEditView::OnReplaceAll  
 Chamado pelo framework durante o processamento de substituir todos os comandos na caixa de diálogo Substituir.  
  
```  
virtual void OnReplaceAll(
    LPCTSTR lpszFind,  
    LPCTSTR lpszReplace,  
    BOOL bCase,  
    BOOL bWord);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFind`  
 O texto a ser substituído.  
  
 `lpszReplace`  
 O texto de substituição.  
  
 `bCase`  
 Indica se a pesquisa diferencia maiusculas de minúsculas.  
  
 `bWord`  
 Indica se a pesquisa deve selecionar palavras inteiras ou não.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para substituir todas as ocorrências de um determinado texto por outra cadeia de caracteres. Substitua essa função para alterar as características de pesquisa para esta exibição.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CRichEditView::FindText](#findtext).  
  
##  <a name="onreplacesel"></a>CRichEditView::OnReplaceSel  
 Chamado pelo framework quando o processamento de comandos de substituição na caixa de diálogo Substituir.  
  
```  
virtual void OnReplaceSel(
    LPCTSTR lpszFind,  
    BOOL bNext,  
    BOOL bCase,  
    BOOL bWord,  
    LPCTSTR lpszReplace);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFind`  
 O texto a ser substituído.  
  
 `bNext`  
 Indica a direção da pesquisa: **TRUE** está inativo; **FALSE**, até.  
  
 `bCase`  
 Indica se a pesquisa diferencia maiusculas de minúsculas.  
  
 `bWord`  
 Indica se a pesquisa deve selecionar palavras inteiras ou não.  
  
 `lpszReplace`  
 O texto de substituição.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para substituir uma ocorrência de um determinado texto por outra cadeia de caracteres. Substitua essa função para alterar as características de pesquisa para esta exibição.  
  
##  <a name="ontextnotfound"></a>CRichEditView::OnTextNotFound  
 Chamado pelo framework sempre que houver falha em uma pesquisa.  
  
```  
virtual void OnTextNotFound(LPCTSTR lpszFind);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFind`  
 O texto que não foi encontrado.  
  
### <a name="remarks"></a>Comentários  
 Substituir essa função para alterar a notificação de saída de um [MessageBeep](http://msdn.microsoft.com/library/windows/desktop/ms680356).  
  
 Para obter mais informações, consulte [MessageBeep](http://msdn.microsoft.com/library/windows/desktop/ms680356) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#157](../../mfc/codesnippet/cpp/cricheditview-class_7.cpp)]  
  
##  <a name="onupdatechareffect"></a>CRichEditView::OnUpdateCharEffect  
 O framework chama esta função para atualizar a interface de comando para comandos do efeito de caractere.  
  
```  
void OnUpdateCharEffect(
    CCmdUI* pCmdUI,  
    DWORD dwMask,  
    DWORD dwEffect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCmdUI`  
 Ponteiro para um [CCmdUI](../../mfc/reference/ccmdui-class.md) objeto.  
  
 `dwMask`  
 Indica a máscara de formatação de caractere.  
  
 `dwEffect`  
 Indica o efeito de formatação de caractere.  
  
### <a name="remarks"></a>Comentários  
 A máscara `dwMask` Especifica qual caractere atributos de formatação para verificar. Os sinalizadores `dwEffect` lista de atributos para definir/limpar de formatação de caractere.  
  
 Para obter mais informações sobre o `dwMask` e `dwEffect` parâmetros e seus valores possíveis, consulte os membros de dados correspondente [CHARFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb787881) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#158](../../mfc/codesnippet/cpp/cricheditview-class_8.cpp)]  
  
##  <a name="onupdateparaalign"></a>CRichEditView::OnUpdateParaAlign  
 O framework chama esta função para atualizar a interface de comando para comandos de efeito do parágrafo.  
  
```  
void OnUpdateParaAlign(
    CCmdUI* pCmdUI,  
    WORD wAlign);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCmdUI`  
 Ponteiro para um [CCmdUI](../../mfc/reference/ccmdui-class.md) objeto.  
  
 `wAlign`  
 O alinhamento do parágrafo para verificar. Um dos seguintes valores:  
  
- `PFA_LEFT`Alinhe os parágrafos com a margem esquerda.  
  
- `PFA_RIGHT`Alinhe os parágrafos com a margem direita.  
  
- `PFA_CENTER`Centralize os parágrafos entre as margens.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#159](../../mfc/codesnippet/cpp/cricheditview-class_9.cpp)]  
  
##  <a name="printinsiderect"></a>CRichEditView::PrintInsideRect  
 Chamar essa função para formatar um intervalo de texto em um controle de edição rica para se ajustarem *rectLayout* para o dispositivo especificado pelo `pDC`.  
  
```  
long PrintInsideRect(
    CDC* pDC,  
    RECT& rectLayout,  
    long nIndexStart,  
    long nIndexStop,  
    BOOL bOutput);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Ponteiro para um contexto de dispositivo para a área de saída.  
  
 *rectLayout*  
 [RECT](../../mfc/reference/rect-structure1.md) ou [CRect](../../atl-mfc-shared/reference/crect-class.md) que define a área de saída.  
  
 `nIndexStart`  
 Índice de base zero do primeiro caractere a ser formatado.  
  
 `nIndexStop`  
 Índice de base zero do último caractere a ser formatado.  
  
 *bOutput*  
 Indica se o texto deve ser renderizado. Se **FALSE**, o texto é medido apenas.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do último caractere que caiba na área de saída mais um.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, essa chamada é seguida por uma chamada para [CRichEditCtrl::DisplayBand](../../mfc/reference/cricheditctrl-class.md#displayband) que gera a saída.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CRichEditView::GetPaperSize](#getpapersize).  
  
##  <a name="printpage"></a>CRichEditView::PrintPage  
 Chamar essa função para formatar um intervalo de texto em um controle de edição para o dispositivo de saída especificado por `pDC`.  
  
```  
long PrintPage(
    CDC* pDC,  
    long nIndexStart,  
    long nIndexStop);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Ponteiro para um contexto de dispositivo de saída de página.  
  
 `nIndexStart`  
 Índice de base zero do primeiro caractere a ser formatado.  
  
 `nIndexStop`  
 Índice de base zero do último caractere a ser formatado.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do último caractere que caiba em uma página mais um.  
  
### <a name="remarks"></a>Comentários  
 O layout de cada página é controlado por [GetPageRect](#getpagerect) e [GetPrintRect](#getprintrect). Normalmente, essa chamada é seguida por uma chamada para [CRichEditCtrl::DisplayBand](../../mfc/reference/cricheditctrl-class.md#displayband) que gera a saída.  
  
 Observe que as margens são relativa à página física, não a página lógica. Assim, as margens de zero geralmente recortará o texto como muitas impressoras tem áreas não imprimíveis na página. Para evitar que o texto de recorte, você deve chamar [SetMargins](#setmargins) e defina as margens razoáveis antes de imprimir.  
  
##  <a name="queryacceptdata"></a>CRichEditView::QueryAcceptData  
 Chamado pelo framework para colar um objeto de edição com formato.  
  
```  
virtual HRESULT QueryAcceptData(
    LPDATAOBJECT lpdataobj,  
    CLIPFORMAT* lpcfFormat,  
    DWORD dwReco,  
    BOOL bReally,  
    HGLOBAL hMetaFile);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpdataobj*  
 Ponteiro para o [IDataObject](http://msdn.microsoft.com/library/windows/desktop/ms688421) à consulta.  
  
 *lpcfFormat*  
 Ponteiro para o formato de dados aceitável.  
  
 `dwReco`  
 Não usado.  
  
 *bReally*  
 Indica se a operação de colagem deverá continuar ou não.  
  
 `hMetaFile`  
 Um identificador para o metarquivo usado para desenhar o ícone do item.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `HRESULT` valor relatando o êxito da operação.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para manipular uma organização diferente de itens COM em sua classe derivada de documento. Isso é uma avançada substituível.  
  
 Para obter mais informações sobre `HRESULT` e `IDataObject`, consulte [estrutura de códigos de erro COM](http://msdn.microsoft.com/library/windows/desktop/ms690088) e [IDataObject](http://msdn.microsoft.com/library/windows/desktop/ms688421), respectivamente, no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#160](../../mfc/codesnippet/cpp/cricheditview-class_10.cpp)]  
  
##  <a name="setcharformat"></a>CRichEditView::SetCharFormat  
 Chamar essa função para definir o caractere de atributos de texto novo na formatação `CRichEditView` objeto.  
  
```  
void SetCharFormat(CHARFORMAT2 cf);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cf`  
 [CHARFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787883) estrutura que contém o caractere padrão novos atributos de formatação.  
  
### <a name="remarks"></a>Comentários  
 Somente os atributos especificados pelo **dwMask** membro `cf` são alteradas por essa função.  
  
 Para obter mais informações, consulte [EM_SETCHARFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb774230) mensagem e [CHARFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787883) estrutura no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#152](../../mfc/codesnippet/cpp/cricheditview-class_2.cpp)]  
  
##  <a name="setmargins"></a>CRichEditView::SetMargins  
 Chame essa função para definir as margens de impressão para este modo de exibição de edição rica.  
  
```  
void SetMargins(const CRect& rectMargin);
```  
  
### <a name="parameters"></a>Parâmetros  
 *rectMargin*  
 Os novos valores de margem para impressão, medido em `MM_TWIPS`.  
  
### <a name="remarks"></a>Comentários  
 Se [m_nWordWrap](#m_nwordwrap) é `WrapToTargetDevice`, você deve chamar [WrapChanged](#wrapchanged) depois de usar essa função para ajustar as características de impressão.  
  
 Observe que as margens usadas por [PrintPage](#printpage) são relativos à página física, não a página lógica. Assim, as margens de zero geralmente recortará o texto como muitas impressoras tem áreas não imprimíveis na página. Para evitar que o texto de recorte, você deve chamar use `SetMargins` para definir as margens de impressão razoável antes de imprimir.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CRichEditView::GetPaperSize](#getpapersize).  
  
##  <a name="setpapersize"></a>CRichEditView::SetPaperSize  
 Chame essa função para definir o tamanho do papel para a exibição de edição rica de impressão.  
  
```  
void SetPaperSize(CSize sizePaper);
```  
  
### <a name="parameters"></a>Parâmetros  
 *sizePaper*  
 Os novos valores de tamanho de papel para impressão, medido em `MM_TWIPS`.  
  
### <a name="remarks"></a>Comentários  
 Se [m_nWordWrap](#m_nwordwrap) é `WrapToTargetDevice`, você deve chamar [WrapChanged](#wrapchanged) depois de usar essa função para ajustar as características de impressão.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#161](../../mfc/codesnippet/cpp/cricheditview-class_11.cpp)]  
  
##  <a name="setparaformat"></a>CRichEditView::SetParaFormat  
 Chamar essa função para definir os atributos para a seleção atual na de formatação de parágrafo `CRichEditView` objeto.  
  
```  
BOOL SetParaFormat(PARAFORMAT2& pf);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pf`  
 [PARAFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787942) atributos de formatação de parágrafo de estrutura que contém o novo padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Somente os atributos especificados pelo **dwMask** membro `pf` são alteradas por essa função.  
  
 Para obter mais informações, consulte [EM_SETPARAFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb774276) mensagem e [PARAFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787942) estrutura no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#162](../../mfc/codesnippet/cpp/cricheditview-class_12.cpp)]  
  
##  <a name="textnotfound"></a>CRichEditView::TextNotFound  
 Chamar essa função para redefinir o estado de pesquisa interna do [CRichEditView](../../mfc/reference/cricheditview-class.md) controle após uma falha na chamada para [FindText](#findtext).  
  
```  
void TextNotFound(LPCTSTR lpszFind);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFind`  
 Contém a cadeia de caracteres de texto que não foi encontrada.  
  
### <a name="remarks"></a>Comentários  
 É recomendável que esse método ser chamado imediatamente após a chamadas com falha para [FindText](#findtext) para que o estado de pesquisa interna do controle é redefinido corretamente.  
  
 O `lpszFind` parâmetro deve incluir o mesmo conteúdo como cadeia de caracteres fornecida para [FindText](#findtext). Depois de redefinir o estado de pesquisa interno, esse método chamará o [OnTextNotFound](#ontextnotfound) método com a cadeia de caracteres de pesquisa fornecido.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CRichEditView::FindText](#findtext).  
  
##  <a name="wrapchanged"></a>CRichEditView::WrapChanged  
 Chamar esta função quando alteraram as características ( [SetMargins](#setmargins) ou [SetPaperSize](#setpapersize)).  
  
```  
virtual void WrapChanged();
```  
  
### <a name="remarks"></a>Comentários  
 Substituir essa função para modificar o modo de exibição de edição a avançada responde às alterações no [m_nWordWrap](#m_nwordwrap) ou as características ( [OnPrinterChanged](#onprinterchanged)).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#163](../../mfc/codesnippet/cpp/cricheditview-class_13.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC WORDPAD](../../visual-cpp-samples.md)   
 [Classe CCtrlView](../../mfc/reference/cctrlview-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CRichEditDoc](../../mfc/reference/cricheditdoc-class.md)   
 [Classe CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md)
