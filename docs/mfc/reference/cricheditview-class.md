---
title: Classe CRichEditView | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
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
dev_langs:
- C++
helpviewer_keywords:
- document/view architecture, rich edit controls
- OLE containers, rich edit
- rich edit controls, OLE container
- CRichEditView class
ms.assetid: bd576b10-4cc0-4050-8f76-e1a0548411e4
caps.latest.revision: 25
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 9f54ec0c8aae58828607b01973a263e458c30ddb
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cricheditview-class"></a>Classe CRichEditView
Com [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md) e [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md), fornece a funcionalidade do controle de edição avançada dentro do contexto da arquitetura de exibição de documento do MFC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CRichEditView : public CCtrlView  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRichEditView::CRichEditView](#cricheditview)|Constrói um objeto `CRichEditView`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRichEditView::AdjustDialogPosition](#adjustdialogposition)|Move uma caixa de diálogo para que ele não oculte a seleção atual.|  
|[CRichEditView::CanPaste](#canpaste)|Informa se a área de transferência contém dados que podem ser colados no modo de edição avançada.|  
|[CRichEditView::DoPaste](#dopaste)|Cola um item OLE para essa exibição de edição rica.|  
|[CRichEditView::FindText](#findtext)|Localiza o texto especificado, invocando o cursor de espera.|  
|[CRichEditView::FindTextSimple](#findtextsimple)|Localiza o texto especificado.|  
|[CRichEditView::GetCharFormatSelection](#getcharformatselection)|Recupera o atributos para a seleção atual de formatação de caractere.|  
|[CRichEditView::GetDocument](#getdocument)|Recupera um ponteiro para o relacionado [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md).|  
|[CRichEditView::GetInPlaceActiveItem](#getinplaceactiveitem)|Recupera o item OLE que está ativo atualmente em vigor no modo de edição avançada.|  
|[CRichEditView::GetMargins](#getmargins)|Recupera as margens para este modo de exibição de edição rica.|  
|[CRichEditView::GetPageRect](#getpagerect)|Recupera o retângulo da página para este modo de exibição de edição rica.|  
|[CRichEditView::GetPaperSize](#getpapersize)|Recupera o tamanho do papel para este modo de exibição de edição rica.|  
|[CRichEditView::GetParaFormatSelection](#getparaformatselection)|Recupera os atributos para a seleção atual de formatação de parágrafo.|  
|[CRichEditView::GetPrintRect](#getprintrect)|Recupera o retângulo de impressão para este modo de exibição de edição rica.|  
|[CRichEditView::GetPrintWidth](#getprintwidth)|Recupera a largura de impressa para este modo de exibição de edição rica.|  
|[CRichEditView::GetRichEditCtrl](#getricheditctrl)|Recupera o controle rich edit.|  
|[CRichEditView::GetSelectedItem](#getselecteditem)|Recupera o item selecionado do modo de edição avançada.|  
|[CRichEditView::GetTextLength](#gettextlength)|Recupera o comprimento do texto no modo de edição avançada.|  
|[CRichEditView::GetTextLengthEx](#gettextlengthex)|Recupera o número de caracteres ou bytes no modo de edição avançada. Lista de sinalizador expandido para o método para determinar o comprimento.|  
|[CRichEditView::InsertFileAsObject](#insertfileasobject)|Insere um arquivo como um item OLE.|  
|[CRichEditView::InsertItem](#insertitem)|Insere um novo item como um item OLE.|  
|[CRichEditView::IsRichEditFormat](#isricheditformat)|Informa se a área de transferência contém dados em um formato de texto ou rich edit.|  
|[CRichEditView::OnCharEffect](#onchareffect)|Alterna a formatação de caracteres para a seleção atual.|  
|[CRichEditView::OnParaAlign](#onparaalign)|Altera o alinhamento de parágrafos.|  
|[CRichEditView::OnUpdateCharEffect](#onupdatechareffect)|Atualiza a interface do usuário de comando para funções de membro público do caractere.|  
|[CRichEditView::OnUpdateParaAlign](#onupdateparaalign)|Atualiza a interface do usuário de comando para funções de membro público do parágrafo.|  
|[CRichEditView::PrintInsideRect](#printinsiderect)|Formata o texto especificado dentro do retângulo determinado.|  
|[CRichEditView::PrintPage](#printpage)|Formata o texto especificado em determinada página.|  
|[CRichEditView::SetCharFormat](#setcharformat)|Define o caractere de formatação atributos para a seleção atual.|  
|[CRichEditView::SetMargins](#setmargins)|Define as margens para este rich Editar modo de exibição.|  
|[CRichEditView::SetPaperSize](#setpapersize)|Define o tamanho do papel para este modo de exibição de edição rica.|  
|[CRichEditView::SetParaFormat](#setparaformat)|Define os atributos da seleção atual de formatação de parágrafo.|  
|[CRichEditView::TextNotFound](#textnotfound)|Redefine o estado de pesquisa interno do controle.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRichEditView::GetClipboardData](#getclipboarddata)|Recupera um objeto da área de transferência para um intervalo nesse modo de exibição de edição rica.|  
|[CRichEditView::GetContextMenu](#getcontextmenu)|Recupera um menu de contexto para usar em um botão do mouse à direita para baixo.|  
|[CRichEditView::IsSelected](#isselected)|Indica se a determinado item OLE está selecionado ou não.|  
|[CRichEditView::OnFindNext](#onfindnext)|Localiza a próxima ocorrência de uma subcadeia de caracteres.|  
|[CRichEditView::OnInitialUpdate](#oninitialupdate)|Atualiza uma exibição quando inicialmente anexado a um documento.|  
|[CRichEditView::OnPasteNativeObject](#onpastenativeobject)|Recupera dados nativos de um item OLE.|  
|[CRichEditView::OnPrinterChanged](#onprinterchanged)|Define as características de impressão para um determinado dispositivo.|  
|[CRichEditView::OnReplaceAll](#onreplaceall)|Substitui todas as ocorrências de uma determinada cadeia de caracteres com uma nova cadeia de caracteres.|  
|[CRichEditView::OnReplaceSel](#onreplacesel)|Substitui a seleção atual.|  
|[CRichEditView::OnTextNotFound](#ontextnotfound)|Identificadores de notificação do usuário que o texto solicitado não foi encontrado.|  
|[CRichEditView::QueryAcceptData](#queryacceptdata)|Consultas para ver sobre os dados sobre o `IDataObject`.|  
|[CRichEditView::WrapChanged](#wrapchanged)|Ajusta o dispositivo de saída de destino para esta rich Editar modo de exibição, com base no valor de `m_nWordWrap`.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRichEditView::m_nBulletIndent](#m_nbulletindent)|Indica a quantidade de recuo para listas de marcador.|  
|[CRichEditView::m_nWordWrap](#m_nwordwrap)|Indica as restrições de quebra de palavras.|  
  
## <a name="remarks"></a>Comentários  
 "Controle rich edit" é uma janela na qual o usuário pode inserir e editar texto. O texto pode ser atribuído a formatação de parágrafo e caracteres e pode incluir objetos OLE incorporados. Controles de edição avançados fornecem uma interface de programação de formatação de texto. No entanto, um aplicativo deve implementar quaisquer componentes de interface do usuário necessários para tornar as operações de formatação disponíveis para o usuário.  
  
 `CRichEditView`mantém o texto e as características de formatação de texto. `CRichEditDoc`mantém a lista de itens de cliente OLE que estão no modo de exibição. `CRichEditCntrItem`fornece acesso do lado do contêiner para o item de cliente OLE.  
  
 Esse controle comum do Windows (e, portanto, o [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md) e classes relacionadas) está disponível apenas para programas que executam versões do Windows 95/98 e Windows NT 3.51 e posterior.  
  
 Para obter um exemplo de como usar um modo de exibição de edição rica em um aplicativo MFC, consulte o [WORDPAD](../../visual-cpp-samples.md) aplicativo de exemplo.  
  
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
 Chame essa função para mover a caixa de diálogo determinado para que ele não oculte a seleção atual.  
  
```  
void AdjustDialogPosition(CDialog* pDlg);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDlg*  
 Ponteiro para uma `CDialog` objeto.  
  
##  <a name="canpaste"></a>CRichEditView::CanPaste  
 Chame essa função para determinar se a área de transferência contém informações que podem ser coladas para essa exibição de edição rica.  
  
```  
BOOL CanPaste() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a área de transferência contém dados em um formato que pode aceitar este modo de exibição de edição rica; Caso contrário, 0.  
  
##  <a name="cricheditview"></a>CRichEditView::CRichEditView  
 Chame essa função para criar um `CRichEditView` objeto.  
  
```  
CRichEditView();
```  
  
##  <a name="dopaste"></a>CRichEditView::DoPaste  
 Chame essa função para colar o item OLE em `dataobj` no documento/exibição edição avançada.  
  
```  
void DoPaste(
    COleDataObject& dataobj,  
    CLIPFORMAT cf,  
    HMETAFILEPICT hMetaPict);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dataobj`  
 O [COleDataObject](../../mfc/reference/coledataobject-class.md) que contém os dados para colar.  
  
 `cf`  
 O formato desejado da área de transferência.  
  
 `hMetaPict`  
 Metarquivo que representa o item a ser colado.  
  
### <a name="remarks"></a>Comentários  
 O framework chama essa função como parte da implementação do padrão de [QueryAcceptData](#queryacceptdata).  
  
 Esta função determina o tipo de colar com base nos resultados do manipulador para colar especial. Se `cf` for 0, o novo item usa a representação icônico atual. Se `cf` é diferente de zero e `hMetaPict` não é **nulo**, usa o novo item `hMetaPict` para sua representação.  
  
##  <a name="findtext"></a>CRichEditView::FindText  
 Chame essa função para localizar o texto especificado e defini-lo como a seleção atual.  
  
```  
BOOL FindText(
    LPCTSTR lpszFind,  
    BOOL bCase = TRUE,  
    BOOL bWord = TRUE,  
    BOOL bNext = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFind`  
 Contém a cadeia de caracteres para pesquisar.  
  
 `bCase`  
 Indica se a pesquisa diferencia maiusculas de minúsculas.  
  
 `bWord`  
 Indica se a pesquisa deve coincidir palavra inteira, não partes de palavras.  
  
 `bNext`  
 Indica a direção da pesquisa. Se **TRUE**, a direção da pesquisa é o final do buffer. Se **FALSE**, a direção da pesquisa é o início do buffer.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o `lpszFind` texto for encontrado; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esta função exibe o cursor de espera durante a operação de localização.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#151;](../../mfc/codesnippet/cpp/cricheditview-class_1.cpp)]  
  
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
 `lpszFind`  
 Contém a cadeia de caracteres para pesquisar.  
  
 `bCase`  
 Indica se a pesquisa diferencia maiusculas de minúsculas.  
  
 `bWord`  
 Indica se a pesquisa deve coincidir palavra inteira, não partes de palavras.  
  
 `bNext`  
 Indica a direção da pesquisa. Se **TRUE**, a direção da pesquisa é o final do buffer. Se **FALSE**, a direção da pesquisa é o início do buffer.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o `lpszFind` texto for encontrado; caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRichEditView::FindText](#findtext).  
  
##  <a name="getcharformatselection"></a>CRichEditView::GetCharFormatSelection  
 Chame essa função para obter o atributos da seleção atual de formatação de caractere.  
  
```  
CHARFORMAT2& GetCharFormatSelection();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A [CHARFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787883) estrutura que contém o caractere de formatação atributos da seleção atual.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte o [EM_GETCHARFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb788026) mensagem e o [CHARFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787883) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#152;](../../mfc/codesnippet/cpp/cricheditview-class_2.cpp)]  
  
##  <a name="getclipboarddata"></a>CRichEditView::GetClipboardData  
 O framework chama essa função como parte do processamento de [IRichEditOleCallback::GetClipboardData](http://msdn.microsoft.com/library/windows/desktop/bb774315).  
  
```  
virtual HRESULT GetClipboardData(
    CHARRANGE* lpchrg,  
    DWORD dwReco,  
    LPDATAOBJECT lpRichDataObj,  
    LPDATAOBJECT* lplpdataobj);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpchrg`  
 Ponteiro para o [CHARRANGE](http://msdn.microsoft.com/library/windows/desktop/bb787885) estrutura especificando o intervalo de caracteres (e itens OLE) para copiar para o objeto de dados especificado por `lplpdataobj`.  
  
 `dwReco`  
 Sinalizador de operação da área de transferência. Pode ser um destes valores.  
  
- **RECO_COPY** copiar na área de transferência.  
  
- **RECO_CUT** recortado para a área de transferência.  
  
- **RECO_DRAG** (arrastar e soltar) de operação de arrastar.  
  
- **RECO_DROP** operação (arrastar e soltar) para soltar.  
  
- **RECO_PASTE** colar da área de transferência.  
  
 `lpRichDataObj`  
 Ponteiro para uma [IDataObject](http://msdn.microsoft.com/library/windows/desktop/ms688421) controle de edição de objeto que contém os dados da área de transferência do rich ( [IRichEditOle::GetClipboardData](http://msdn.microsoft.com/library/windows/desktop/bb774341)).  
  
 `lplpdataobj`  
 Ponteiro para a variável de ponteiro que recebe o endereço do `IDataObject` objeto que representa o intervalo especificado na `lpchrg` parâmetro. O valor de `lplpdataobj` será ignorado se um erro será retornado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `HRESULT` valor reporting o sucesso da operação. Para obter mais informações sobre `HRESULT`, consulte [estrutura de códigos de erro COM](http://msdn.microsoft.com/library/windows/desktop/ms690088) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Se o valor de retorno indica êxito, **IRichEditOleCallback::GetClipboardData** retorna o `IDataObject` acessados por `lplpdataobj`; caso contrário, ele retornará o acessado por `lpRichDataObj`. Substitua essa função para fornecer seus próprios dados da área de transferência. Retorna a implementação padrão dessa função **E_NOTIMPL**.  
  
 Isso é uma avançada substituível.  
  
 Para obter mais informações, consulte [IRichEditOle::GetClipboardData](http://msdn.microsoft.com/library/windows/desktop/bb774341), [IRichEditOleCallback::GetClipboardData](http://msdn.microsoft.com/library/windows/desktop/bb774315), e [CHARRANGE](http://msdn.microsoft.com/library/windows/desktop/bb787885) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] e [IDataObject](http://msdn.microsoft.com/library/windows/desktop/ms688421) no [!INCLUDE[winsdkshort](../../atl-mfc-shared/reference/includes/winsdkshort_md.md)].  
  
##  <a name="getcontextmenu"></a>CRichEditView::GetContextMenu  
 O framework chama essa função como parte do processamento de [IRichEditOleCallback::GetContextMenu](http://msdn.microsoft.com/library/windows/desktop/bb774317).  
  
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
 Ponteiro para uma **OLEOBJECT** estrutura especificando o primeiro objeto OLE selecionado se a seleção contém um ou mais itens OLE. Se a seleção não contém itens, `lpoleobj` é **nulo**. O **OLEOBJECT** estrutura contém um ponteiro para um objeto OLE v-table.  
  
 `lpchrg`  
 Ponteiro para uma [CHARRANGE](http://msdn.microsoft.com/library/windows/desktop/bb787885) estrutura que contém a seleção atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Identificador para o menu de contexto.  
  
### <a name="remarks"></a>Comentários  
 Essa função é uma parte típica do botão do mouse à direita processamento.  
  
 O tipo de seleção pode ser qualquer combinação dos sinalizadores a seguir:  
  
- `SEL_EMPTY`Indica que não há nenhuma seleção atual.  
  
- `SEL_TEXT`Indica que a seleção atual contém texto.  
  
- `SEL_OBJECT`Indica que a seleção atual contém pelo menos um item OLE.  
  
- `SEL_MULTICHAR`Indica que a seleção atual contém mais de um caractere de texto.  
  
- `SEL_MULTIOBJECT`Indica que a seleção atual contém mais de um objeto OLE.  
  
 Retorna a implementação padrão **nulo**. Isso é uma avançada substituível.  
  
 Para obter mais informações, consulte [IRichEditOleCallback::GetContextMenu](http://msdn.microsoft.com/library/windows/desktop/bb774317) e [CHARRANGE](http://msdn.microsoft.com/library/windows/desktop/bb787885) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para obter mais informações sobre o **OLEOBJECT** tipo, consulte o artigo de alocação da estrutura e estruturas de dados OLE no *OLE Knowledge Base*.  
  
##  <a name="getdocument"></a>CRichEditView::GetDocument  
 Chame essa função para obter um ponteiro para o `CRichEditDoc` associado a este modo de exibição.  
  
```  
CRichEditDoc* GetDocument() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md) objeto associado ao seu `CRichEditView` objeto.  
  
##  <a name="getinplaceactiveitem"></a>CRichEditView::GetInPlaceActiveItem  
 Chamada essa função para obter a OLE item que estiver ativada no lugar neste `CRichEditView` objeto.  
  
```  
CRichEditCntrItem* GetInPlaceActiveItem() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o ativo único, no local [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md) objeto neste modo de exibição de edição rica; **Nulo** se não houver nenhum item OLE atualmente no estado ativo no local.  
  
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
 [!code-cpp[NVC_MFCDocView&#153;](../../mfc/codesnippet/cpp/cricheditview-class_3.cpp)]  
  
##  <a name="getparaformatselection"></a>CRichEditView::GetParaFormatSelection  
 Chame essa função para obter os atributos da seleção atual de formatação de parágrafo.  
  
```  
PARAFORMAT2& GetParaFormatSelection();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A [PARAFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787942) estrutura que contém os atributos da seleção atual de formatação de parágrafo.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [EM_GETPARAFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb774182) mensagem e [PARAFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787942) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getprintrect"></a>CRichEditView::GetPrintRect  
 Chame essa função para recuperar os limites da área de impressão dentro do retângulo de página.  
  
```  
CRect GetPrintRect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Os limites da área de imagem usados na impressão, medido em `MM_TWIPS`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#154;](../../mfc/codesnippet/cpp/cricheditview-class_4.cpp)]  
  
##  <a name="getprintwidth"></a>CRichEditView::GetPrintWidth  
 Chame essa função para determinar a largura da área de impressão.  
  
```  
int GetPrintWidth() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A largura da área de impressão, medida em `MM_TWIPS`.  
  
##  <a name="getricheditctrl"></a>CRichEditView::GetRichEditCtrl  
 Chame essa função para recuperar o [CRichEditCtrl](../../mfc/reference/cricheditctrl-class.md) objeto associado a `CRichEditView` objeto.  
  
```  
CRichEditCtrl& GetRichEditCtrl() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O `CRichEditCtrl` objeto para esta exibição.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRichEditView::FindText](#findtext).  
  
##  <a name="getselecteditem"></a>CRichEditView::GetSelectedItem  
 Chame essa função para recuperar o item OLE (uma `CRichEditCntrItem` objeto) selecionado no momento neste `CRichEditView` objeto.  
  
```  
CRichEditCntrItem* GetSelectedItem() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md) objeto selecionado no `CRichEditView` do objeto; **Nulo** se nenhum item é selecionado nesta exibição.  
  
##  <a name="gettextlength"></a>CRichEditView::GetTextLength  
 Chame essa função para recuperar o comprimento do texto nesse `CRichEditView` objeto.  
  
```  
long GetTextLength() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento do texto nesse `CRichEditView` objeto.  
  
##  <a name="gettextlengthex"></a>CRichEditView::GetTextLengthEx  
 Chame essa função de membro para calcular o comprimento do texto nesse `CRichEditView` objeto.  
  
```  
long GetTextLengthEx(
    DWORD dwFlags,  
    UINT uCodePage = -1) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwFlags`  
 Valor que especifica o método a ser usado para determinar o comprimento do texto. Esse membro pode ser um ou mais dos valores listados no membro sinalizadores [GETTEXTLENGTHEX](http://msdn.microsoft.com/library/windows/desktop/bb787915) descrito o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `uCodePage`  
 Página de código para tradução (CP_ACP para a página de código ANSI, 1200 para Unicode).  
  
### <a name="return-value"></a>Valor de retorno  
 O número de caracteres ou bytes no controle de edição. Se os sinalizadores incompatíveis foram definidos `dwFlags`, essa função membro retorna `E_INVALIDARG`.  
  
### <a name="remarks"></a>Comentários  
 `GetTextLengthEx`oferece outras maneiras de determinar o comprimento do texto. Ele oferece suporte a funcionalidade avançada Editar 2.0. Para obter mais informações, consulte [sobre controles sofisticados de editar](http://msdn.microsoft.com/library/windows/desktop/bb787873) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="insertfileasobject"></a>CRichEditView::InsertFileAsObject  
 Chame essa função para inserir o arquivo especificado (como uma [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md) objeto) em uma rica Editar modo de exibição.  
  
```  
void InsertFileAsObject(LPCTSTR lpszFileName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFileName`  
 Cadeia de caracteres que contém o nome do arquivo a ser inserido.  
  
##  <a name="insertitem"></a>CRichEditView::InsertItem  
 Chame essa função para inserir um [CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md) objeto em um modo de exibição de edição rica.  
  
```  
HRESULT InsertItem(CRichEditCntrItem* pItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pItem`  
 Ponteiro para o item a ser inserido.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `HRESULT` indicando o êxito da inserção do valor.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre `HRESULT`, consulte [estrutura de códigos de erro COM](http://msdn.microsoft.com/library/windows/desktop/ms690088) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="isricheditformat"></a>CRichEditView::IsRichEditFormat  
 Chame essa função para determinar se `cf` é um formato de área de transferência que é texto, RTF ou rich text com itens OLE.  
  
```  
static BOOL AFX_CDECL IsRichEditFormat(CLIPFORMAT cf);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cf`  
 O formato de área de interesse.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se `cf` é um formato de área de transferência rich edit ou de texto.  
  
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
 Substitua essa função se sua classe derivada tem um método diferente para tratar a seleção de itens OLE.  
  
##  <a name="m_nbulletindent"></a>CRichEditView::m_nBulletIndent  
 O recuo de itens com marcadores em uma lista; Por padrão, as unidades de 720, que é 1/2 polegadas.  
  
```  
int m_nBulletIndent;  
```  
  
##  <a name="m_nwordwrap"></a>CRichEditView::m_nWordWrap  
 Indica o tipo de quebra para este modo de exibição de edição rica.  
  
```  
int m_nWordWrap;  
```  
  
### <a name="remarks"></a>Comentários  
 Um dos seguintes valores:  
  
- `WrapNone`Indica sem quebra automática.  
  
- `WrapToWindow`Indica a quebra automática com base na largura da janela.  
  
- `WrapToTargetDevice`Indica a quebra de texto com base nas características do dispositivo de destino.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRichEditView::WrapChanged](#wrapchanged).  
  
##  <a name="onchareffect"></a>CRichEditView::OnCharEffect  
 Chame essa função para alternar o efeitos da seleção atual de formatação de caractere.  
  
```  
void OnCharEffect(
    DWORD dwMask,  
    DWORD dwEffect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwMask`  
 O caractere de formatação de efeitos para modificar a seleção atual.  
  
 `dwEffect`  
 A lista desejada de efeitos para alternar de formatação de caractere.  
  
### <a name="remarks"></a>Comentários  
 Cada chamada para essa função alterna os efeitos de formatação especificados para a seleção atual.  
  
 Para obter mais informações sobre o `dwMask` e `dwEffect` parâmetros e seus valores possíveis, consulte os membros de dados correspondente [CHARFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb787881) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#155;](../../mfc/codesnippet/cpp/cricheditview-class_5.cpp)]  
  
##  <a name="onfindnext"></a>CRichEditView::OnFindNext  
 Chamado pela estrutura durante o processamento de comandos na caixa de diálogo Localizar/Substituir.  
  
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
 A direção da pesquisa: **TRUE** indica abaixo; **FALSE**, up.  
  
 `bCase`  
 Indica se a pesquisa deve diferenciar maiusculas de minúsculas.  
  
 `bWord`  
 Indica se a pesquisa deve coincidir palavras inteiras somente ou não.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para localizar texto dentro de `CRichEditView`. Substitua essa função para alterar características de pesquisa para sua classe derivada.  
  
##  <a name="oninitialupdate"></a>CRichEditView::OnInitialUpdate  
 Chamado pela estrutura depois que o modo de exibição é anexado ao documento pela primeira vez, mas antes que o modo de exibição é exibido inicialmente.  
  
```  
virtual void OnInitialUpdate();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função chama o [CView::OnUpdate](../../mfc/reference/cview-class.md#onupdate) a função de membro sem informações de dica (ou seja, usando os valores padrão de 0 para o `lHint` parâmetro e **nulo** para o `pHint` parâmetro). Substitua essa função para executar qualquer inicialização única que exige informações sobre o documento. Por exemplo, se seu aplicativo tiver documentos de tamanho fixo, você pode usar essa função para inicializar os limites de rolagem da exibição com base no tamanho do documento. Se o aplicativo suportar documentos de tamanho variável, use `OnUpdate` atualizar a rolagem limita sempre que as alterações do documento.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRichEditView::m_nWordWrap](#m_nwordwrap).  
  
##  <a name="onpastenativeobject"></a>CRichEditView::OnPasteNativeObject  
 Use esta função para carregar dados nativos de um item incorporado.  
  
```  
virtual BOOL OnPasteNativeObject(LPSTORAGE lpStg);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpStg*  
 Ponteiro para uma [IStorage](http://msdn.microsoft.com/library/windows/desktop/aa380015) objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0;  
  
### <a name="remarks"></a>Comentários  
 Normalmente, você faria isso criando uma [COleStreamFile](../../mfc/reference/colestreamfile-class.md) em torno de `IStorage`. O `COleStreamFile` podem ser anexados a um arquivo morto e [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize) chamado para carregar os dados.  
  
 Isso é uma avançada substituível.  
  
 Para obter mais informações, consulte [IStorage](http://msdn.microsoft.com/library/windows/desktop/aa380015) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
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
  
- `PFA_CENTER`Centraliza os parágrafos entre as margens.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#156;](../../mfc/codesnippet/cpp/cricheditview-class_6.cpp)]  
  
##  <a name="onprinterchanged"></a>CRichEditView::OnPrinterChanged  
 Substitua essa função para alterar características para este modo de exibição de edição rica quando a impressora é alterado.  
  
```  
virtual void OnPrinterChanged(const CDC& dcPrinter);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dcPrinter`  
 A [CDC](../../mfc/reference/cdc-class.md) objeto para a nova impressora.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão define o tamanho do papel para a altura física e a largura do dispositivo de saída (impressora). Se não houver nenhum contexto de dispositivo associados `dcPrinter`, a implementação padrão define o tamanho do papel para 8,5 por 11 polegadas.  
  
##  <a name="onreplaceall"></a>CRichEditView::OnReplaceAll  
 Chamado pela estrutura ao processar comandos Substituir tudo na caixa de diálogo Substituir.  
  
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
 Chame essa função para substituir todas as ocorrências de um determinado texto por outra cadeia de caracteres. Substitua essa função para alterar características de pesquisa para esta exibição.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRichEditView::FindText](#findtext).  
  
##  <a name="onreplacesel"></a>CRichEditView::OnReplaceSel  
 Chamado pela estrutura ao processar comandos de substituição na caixa de diálogo Substituir.  
  
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
 Indica a direção da pesquisa: **TRUE** for pressionada; **FALSE**, up.  
  
 `bCase`  
 Indica se a pesquisa diferencia maiusculas de minúsculas.  
  
 `bWord`  
 Indica se a pesquisa deve selecionar palavras inteiras ou não.  
  
 `lpszReplace`  
 O texto de substituição.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para substituir uma ocorrência de um determinado texto por outra cadeia de caracteres. Substitua essa função para alterar características de pesquisa para esta exibição.  
  
##  <a name="ontextnotfound"></a>CRichEditView::OnTextNotFound  
 Chamado pela estrutura sempre que uma pesquisa falha.  
  
```  
virtual void OnTextNotFound(LPCTSTR lpszFind);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFind`  
 O texto que não foi encontrado.  
  
### <a name="remarks"></a>Comentários  
 Substituir essa função para alterar a notificação de saída de um [MessageBeep](http://msdn.microsoft.com/library/windows/desktop/ms680356).  
  
 Para obter mais informações, consulte [MessageBeep](http://msdn.microsoft.com/library/windows/desktop/ms680356) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#157;](../../mfc/codesnippet/cpp/cricheditview-class_7.cpp)]  
  
##  <a name="onupdatechareffect"></a>CRichEditView::OnUpdateCharEffect  
 O framework chama essa função para atualizar a interface de comando para comandos de efeito de caractere.  
  
```  
void OnUpdateCharEffect(
    CCmdUI* pCmdUI,  
    DWORD dwMask,  
    DWORD dwEffect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCmdUI`  
 Ponteiro para uma [CCmdUI](../../mfc/reference/ccmdui-class.md) objeto.  
  
 `dwMask`  
 Indica a máscara de formatação de caractere.  
  
 `dwEffect`  
 Indica o efeito de formatação de caractere.  
  
### <a name="remarks"></a>Comentários  
 A máscara `dwMask` Especifica qual caractere atributos de formatação para verificar. Os sinalizadores `dwEffect` lista de atributos para definir/limpar de formatação de caractere.  
  
 Para obter mais informações sobre o `dwMask` e `dwEffect` parâmetros e seus valores possíveis, consulte os membros de dados correspondente [CHARFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb787881) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#158;](../../mfc/codesnippet/cpp/cricheditview-class_8.cpp)]  
  
##  <a name="onupdateparaalign"></a>CRichEditView::OnUpdateParaAlign  
 O framework chama essa função para atualizar a interface de comando para comandos de efeito do parágrafo.  
  
```  
void OnUpdateParaAlign(
    CCmdUI* pCmdUI,  
    WORD wAlign);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCmdUI`  
 Ponteiro para uma [CCmdUI](../../mfc/reference/ccmdui-class.md) objeto.  
  
 `wAlign`  
 O alinhamento de parágrafo para verificar. Um dos seguintes valores:  
  
- `PFA_LEFT`Alinhe os parágrafos com a margem esquerda.  
  
- `PFA_RIGHT`Alinhe os parágrafos com a margem direita.  
  
- `PFA_CENTER`Centraliza os parágrafos entre as margens.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#159;](../../mfc/codesnippet/cpp/cricheditview-class_9.cpp)]  
  
##  <a name="printinsiderect"></a>CRichEditView::PrintInsideRect  
 Chame essa função para formatar um intervalo de texto em um controle rich edit para ajustarem- *rectLayout* para o dispositivo especificado pelo `pDC`.  
  
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
 Índice baseado em zero do primeiro caractere a ser formatado.  
  
 `nIndexStop`  
 Índice baseado em zero do último caractere a ser formatado.  
  
 *bOutput*  
 Indica se o texto deve ser renderizado. Se **FALSE**, o texto é medido apenas.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do último caractere que couber na área de saída mais um.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, essa chamada é seguida por uma chamada para [CRichEditCtrl::DisplayBand](../../mfc/reference/cricheditctrl-class.md#displayband) que gera a saída.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRichEditView::GetPaperSize](#getpapersize).  
  
##  <a name="printpage"></a>CRichEditView::PrintPage  
 Chame essa função para formatar um intervalo de texto em um controle rich edit para o dispositivo de saída especificado pelo `pDC`.  
  
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
 Índice baseado em zero do primeiro caractere a ser formatado.  
  
 `nIndexStop`  
 Índice baseado em zero do último caractere a ser formatado.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do último caractere que caiba em uma página mais um.  
  
### <a name="remarks"></a>Comentários  
 O layout de cada página é controlado pelo [GetPageRect](#getpagerect) e [GetPrintRect](#getprintrect). Normalmente, essa chamada é seguida por uma chamada para [CRichEditCtrl::DisplayBand](../../mfc/reference/cricheditctrl-class.md#displayband) que gera a saída.  
  
 Observe que as margens são relativos a página física, não a página lógica. Assim, as margens de zero geralmente recortará o texto como muitas impressoras têm áreas não imprimíveis na página. Para evitar que o texto de recorte, você deve chamar [SetMargins](#setmargins) e defina as margens razoáveis antes de imprimir.  
  
##  <a name="queryacceptdata"></a>CRichEditView::QueryAcceptData  
 Chamado pela estrutura para colar um objeto o rich edit.  
  
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
 Ponteiro para o [IDataObject](http://msdn.microsoft.com/library/windows/desktop/ms688421) a consulta.  
  
 *lpcfFormat*  
 Ponteiro para o formato de dados aceitável.  
  
 `dwReco`  
 Não usado.  
  
 *bReally*  
 Indica se a operação de colagem deve continuar ou não.  
  
 `hMetaFile`  
 Um identificador para o metarquivo usado para desenhar o ícone do item.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `HRESULT` valor reporting o sucesso da operação.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para lidar com uma organização diferente dos itens COM em sua classe derivada de documento. Isso é uma avançada substituível.  
  
 Para obter mais informações sobre `HRESULT` e `IDataObject`, consulte [estrutura de códigos de erro COM](http://msdn.microsoft.com/library/windows/desktop/ms690088) e [IDataObject](http://msdn.microsoft.com/library/windows/desktop/ms688421), respectivamente, no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#160;](../../mfc/codesnippet/cpp/cricheditview-class_10.cpp)]  
  
##  <a name="setcharformat"></a>CRichEditView::SetCharFormat  
 Chame essa função para definir o caractere de formatação atributos para um novo texto nesta `CRichEditView` objeto.  
  
```  
void SetCharFormat(CHARFORMAT2 cf);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cf`  
 [CHARFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787883) estrutura que contém o caractere padrão novos atributos de formatação.  
  
### <a name="remarks"></a>Comentários  
 Somente os atributos especificados pelo **dwMask** membro do `cf` alterado por essa função.  
  
 Para obter mais informações, consulte [EM_SETCHARFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb774230) mensagem e [CHARFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787883) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#152;](../../mfc/codesnippet/cpp/cricheditview-class_2.cpp)]  
  
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
  
 Observe que as margens usadas por [PrintPage](#printpage) são relativos à página física, não a página lógica. Assim, as margens de zero geralmente recortará o texto como muitas impressoras têm áreas não imprimíveis na página. Para evitar que o texto de recorte, você deve chamar use `SetMargins` para definir margens de impressão razoável antes de imprimir.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRichEditView::GetPaperSize](#getpapersize).  
  
##  <a name="setpapersize"></a>CRichEditView::SetPaperSize  
 Chame essa função para definir o tamanho do papel para imprimir este modo de exibição de edição rica.  
  
```  
void SetPaperSize(CSize sizePaper);
```  
  
### <a name="parameters"></a>Parâmetros  
 *sizePaper*  
 Os novos valores de tamanho de papel para impressão, medido em `MM_TWIPS`.  
  
### <a name="remarks"></a>Comentários  
 Se [m_nWordWrap](#m_nwordwrap) é `WrapToTargetDevice`, você deve chamar [WrapChanged](#wrapchanged) depois de usar essa função para ajustar as características de impressão.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#161;](../../mfc/codesnippet/cpp/cricheditview-class_11.cpp)]  
  
##  <a name="setparaformat"></a>CRichEditView::SetParaFormat  
 Chame essa função para definir a formatação de atributos para a seleção atual no parágrafo `CRichEditView` objeto.  
  
```  
BOOL SetParaFormat(PARAFORMAT2& pf);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pf`  
 [PARAFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787942) estrutura que contém o novo padrão de atributos de formatação de parágrafo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Somente os atributos especificados pelo **dwMask** membro do `pf` alterado por essa função.  
  
 Para obter mais informações, consulte [EM_SETPARAFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb774276) mensagem e [PARAFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787942) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#162;](../../mfc/codesnippet/cpp/cricheditview-class_12.cpp)]  
  
##  <a name="textnotfound"></a>CRichEditView::TextNotFound  
 Chame essa função para redefinir o estado de pesquisa interno do [CRichEditView](../../mfc/reference/cricheditview-class.md) controle após uma falha na chamada para [FindText](#findtext).  
  
```  
void TextNotFound(LPCTSTR lpszFind);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFind`  
 Contém a cadeia de caracteres de texto que não foi encontrada.  
  
### <a name="remarks"></a>Comentários  
 É recomendável que esse método ser chamado imediatamente após falhas de chamadas para [FindText](#findtext) para que o estado de pesquisa interna do controle é redefinido corretamente.  
  
 O `lpszFind` parâmetro deve incluir o mesmo conteúdo fornecido para a cadeia de caracteres [FindText](#findtext). Depois de redefinir o estado de pesquisa interno, esse método chamará o [OnTextNotFound](#ontextnotfound) método com a cadeia de caracteres de pesquisa fornecido.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRichEditView::FindText](#findtext).  
  
##  <a name="wrapchanged"></a>CRichEditView::WrapChanged  
 Chame essa função quando as características de impressão foram alteradas ( [SetMargins](#setmargins) ou [SetPaperSize](#setpapersize)).  
  
```  
virtual void WrapChanged();
```  
  
### <a name="remarks"></a>Comentários  
 Substituir essa função para modificar o modo como o amplo Editar exibição responde às alterações no [m_nWordWrap](#m_nwordwrap) ou as características ( [OnPrinterChanged](#onprinterchanged)).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#163;](../../mfc/codesnippet/cpp/cricheditview-class_13.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC WORDPAD](../../visual-cpp-samples.md)   
 [Classe CCtrlView](../../mfc/reference/cctrlview-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CRichEditDoc](../../mfc/reference/cricheditdoc-class.md)   
 [Classe CRichEditCntrItem](../../mfc/reference/cricheditcntritem-class.md)

