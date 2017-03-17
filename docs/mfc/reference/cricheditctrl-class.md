---
title: Classe CRichEditCtrl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CRichEditCtrl
- AFXCMN/CRichEditCtrl
- AFXCMN/CRichEditCtrl::CRichEditCtrl
- AFXCMN/CRichEditCtrl::CanPaste
- AFXCMN/CRichEditCtrl::CanRedo
- AFXCMN/CRichEditCtrl::CanUndo
- AFXCMN/CRichEditCtrl::CharFromPos
- AFXCMN/CRichEditCtrl::Clear
- AFXCMN/CRichEditCtrl::Copy
- AFXCMN/CRichEditCtrl::Create
- AFXCMN/CRichEditCtrl::CreateEx
- AFXCMN/CRichEditCtrl::Cut
- AFXCMN/CRichEditCtrl::DisplayBand
- AFXCMN/CRichEditCtrl::EmptyUndoBuffer
- AFXCMN/CRichEditCtrl::FindText
- AFXCMN/CRichEditCtrl::FindWordBreak
- AFXCMN/CRichEditCtrl::FormatRange
- AFXCMN/CRichEditCtrl::GetCharPos
- AFXCMN/CRichEditCtrl::GetDefaultCharFormat
- AFXCMN/CRichEditCtrl::GetEventMask
- AFXCMN/CRichEditCtrl::GetFirstVisibleLine
- AFXCMN/CRichEditCtrl::GetIRichEditOle
- AFXCMN/CRichEditCtrl::GetLimitText
- AFXCMN/CRichEditCtrl::GetLine
- AFXCMN/CRichEditCtrl::GetLineCount
- AFXCMN/CRichEditCtrl::GetModify
- AFXCMN/CRichEditCtrl::GetOptions
- AFXCMN/CRichEditCtrl::GetParaFormat
- AFXCMN/CRichEditCtrl::GetPunctuation
- AFXCMN/CRichEditCtrl::GetRect
- AFXCMN/CRichEditCtrl::GetRedoName
- AFXCMN/CRichEditCtrl::GetSel
- AFXCMN/CRichEditCtrl::GetSelectionCharFormat
- AFXCMN/CRichEditCtrl::GetSelectionType
- AFXCMN/CRichEditCtrl::GetSelText
- AFXCMN/CRichEditCtrl::GetTextLength
- AFXCMN/CRichEditCtrl::GetTextLengthEx
- AFXCMN/CRichEditCtrl::GetTextMode
- AFXCMN/CRichEditCtrl::GetTextRange
- AFXCMN/CRichEditCtrl::GetUndoName
- AFXCMN/CRichEditCtrl::GetWordWrapMode
- AFXCMN/CRichEditCtrl::HideSelection
- AFXCMN/CRichEditCtrl::LimitText
- AFXCMN/CRichEditCtrl::LineFromChar
- AFXCMN/CRichEditCtrl::LineIndex
- AFXCMN/CRichEditCtrl::LineLength
- AFXCMN/CRichEditCtrl::LineScroll
- AFXCMN/CRichEditCtrl::Paste
- AFXCMN/CRichEditCtrl::PasteSpecial
- AFXCMN/CRichEditCtrl::PosFromChar
- AFXCMN/CRichEditCtrl::Redo
- AFXCMN/CRichEditCtrl::ReplaceSel
- AFXCMN/CRichEditCtrl::RequestResize
- AFXCMN/CRichEditCtrl::SetAutoURLDetect
- AFXCMN/CRichEditCtrl::SetBackgroundColor
- AFXCMN/CRichEditCtrl::SetDefaultCharFormat
- AFXCMN/CRichEditCtrl::SetEventMask
- AFXCMN/CRichEditCtrl::SetModify
- AFXCMN/CRichEditCtrl::SetOLECallback
- AFXCMN/CRichEditCtrl::SetOptions
- AFXCMN/CRichEditCtrl::SetParaFormat
- AFXCMN/CRichEditCtrl::SetPunctuation
- AFXCMN/CRichEditCtrl::SetReadOnly
- AFXCMN/CRichEditCtrl::SetRect
- AFXCMN/CRichEditCtrl::SetSel
- AFXCMN/CRichEditCtrl::SetSelectionCharFormat
- AFXCMN/CRichEditCtrl::SetTargetDevice
- AFXCMN/CRichEditCtrl::SetTextMode
- AFXCMN/CRichEditCtrl::SetUndoLimit
- AFXCMN/CRichEditCtrl::SetWordCharFormat
- AFXCMN/CRichEditCtrl::SetWordWrapMode
- AFXCMN/CRichEditCtrl::StopGroupTyping
- AFXCMN/CRichEditCtrl::StreamIn
- AFXCMN/CRichEditCtrl::StreamOut
- AFXCMN/CRichEditCtrl::Undo
dev_langs:
- C++
helpviewer_keywords:
- CRichEditCtrl class, common controls
- CRichEditCtrl class
- formatted text [C++]
ms.assetid: 2be52788-822c-4c27-aafd-2471231e74eb
caps.latest.revision: 26
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
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 77b8dfb6011831f4e4300096a127f70b26bcc603
ms.lasthandoff: 02/25/2017

---
# <a name="cricheditctrl-class"></a>Classe CRichEditCtrl
Fornece a funcionalidade do controle de edição avançada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CRichEditCtrl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRichEditCtrl::CRichEditCtrl](#cricheditctrl)|Constrói um objeto `CRichEditCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRichEditCtrl::CanPaste](#canpaste)|Determina se o conteúdo da área de transferência puder ser colado nesse controle rich edit.|  
|[CRichEditCtrl::CanRedo](#canredo)|Determina se há quaisquer ações na fila de restauração do controle.|  
|[CRichEditCtrl::CanUndo](#canundo)|Determina se uma operação de edição pode ser desfeita.|  
|[CRichEditCtrl::CharFromPos](#charfrompos)|Recupera informações sobre o caractere mais próximo a um ponto especificado na área cliente de um controle de edição.|  
|[CRichEditCtrl::Clear](#clear)|Limpa a seleção atual.|  
|[CRichEditCtrl::Copy](#copy)|Copia a seleção atual na área de transferência.|  
|[CRichEditCtrl::Create](#create)|Cria o controle rich edit Windows e o associa com isso `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::CreateEx](#createex)|Cria o controle rich edit Windows com o Windows estilos estendidos e o associa com isso `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::Cut](#cut)|Recorta a seleção atual na área de transferência.|  
|[CRichEditCtrl::DisplayBand](#displayband)|Exibe uma parte do conteúdo deste `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::EmptyUndoBuffer](#emptyundobuffer)|Redefine o sinalizador de desfazer isso (limpa) `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::FindText](#findtext)|Localiza texto dentro dessa `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::FindWordBreak](#findwordbreak)|Localiza a próxima quebra de palavras antes ou depois da posição do caractere especificado ou recupera informações sobre o caractere na posição.|  
|[CRichEditCtrl::FormatRange](#formatrange)|Formata um intervalo de texto para o dispositivo de saída de destino.|  
|[CRichEditCtrl::GetCharPos](#getcharpos)|Determina o local de um determinado caractere dentro dessa `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::GetDefaultCharFormat](#getdefaultcharformat)|Recupera o caractere padrão atual formatação atributos neste `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::GetEventMask](#geteventmask)|Recupera a máscara de evento para isso `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::GetFirstVisibleLine](#getfirstvisibleline)|Determina a primeira linha visível isso `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::GetIRichEditOle](#getiricheditole)|Recupera um ponteiro para o `IRichEditOle` da interface para controle de edição esse avançado.|  
|[CRichEditCtrl::GetLimitText](#getlimittext)|Obtém o limite na quantidade de texto que um usuário pode inserir em isso `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::GetLine](#getline)|Recupera uma linha de texto desse `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::GetLineCount](#getlinecount)|Recupera o número de linhas no `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::GetModify](#getmodify)|Determina se o conteúdo desse `CRichEditCtrl` objeto foram alterados desde a última gravação.|  
|[CRichEditCtrl::GetOptions](#getoptions)|Recupera as opções de controle de edição avançada.|  
|[CRichEditCtrl::GetParaFormat](#getparaformat)|Recupera os atributos na seleção atual neste de formatação de parágrafo `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::GetPunctuation](#getpunctuation)|Recupera os caracteres de pontuação atual para o controle rich edit. Esta mensagem está disponível apenas nas versões de idioma asiático do sistema operacional.|  
|[CRichEditCtrl::GetRect](#getrect)|Recupera o retângulo de formatação para isso `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::GetRedoName](#getredoname)|Recupera o tipo da próxima ação, se houver, no controle de fila de restauração.|  
|[CRichEditCtrl::GetSel](#getsel)|Obtém o início e término posições da seleção atual neste `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::GetSelectionCharFormat](#getselectioncharformat)|Recupera o caractere de formatação atributos na seleção atual neste `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::GetSelectionType](#getselectiontype)|Recupera o tipo de conteúdo na seleção atual neste `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::GetSelText](#getseltext)|Obtém o texto da seleção atual neste `CRichEditCtrl` objeto|  
|[CRichEditCtrl::GetTextLength](#gettextlength)|Recupera o comprimento do texto, em caracteres, neste `CRichEditCtrl` objeto. Não inclua o caractere de terminação nula.|  
|[CRichEditCtrl::GetTextLengthEx](#gettextlengthex)|Recupera o número de caracteres ou bytes no modo de edição avançada. Aceita uma lista de sinalizadores para indicar o método para determinar o comprimento do texto em um controle rich edit|  
|[CRichEditCtrl::GetTextMode](#gettextmode)|Recupera o texto modo e desfazer nível atual de um controle rich edit.|  
|[CRichEditCtrl::GetTextRange](#gettextrange)|Recupera o intervalo de texto especificado.|  
|[CRichEditCtrl::GetUndoName](#getundoname)|Recupera o tipo de ação de desfazer o próximo, se houver.|  
|[CRichEditCtrl::GetWordWrapMode](#getwordwrapmode)|Recupera a quebra de texto atual e opções de quebra de palavras para o controle rich edit. Esta mensagem está disponível apenas nas versões de idioma asiático do sistema operacional.|  
|[CRichEditCtrl::HideSelection](#hideselection)|Mostra ou oculta a seleção atual.|  
|[CRichEditCtrl::LimitText](#limittext)|Limita a quantidade de texto que um usuário pode inserir no `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::LineFromChar](#linefromchar)|Determina qual linha contém o caractere especificado.|  
|[CRichEditCtrl::LineIndex](#lineindex)|Recupera o índice de uma determinada linha neste `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::LineLength](#linelength)|Recupera o comprimento de uma determinada linha neste `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::LineScroll](#linescroll)|Rola o texto neste `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::Paste](#paste)|Insere o conteúdo da área de transferência para este controle rich edit.|  
|[CRichEditCtrl::PasteSpecial](#pastespecial)|Insere o conteúdo da área de transferência para este controle rich edit no formato de dados especificado.|  
|[CRichEditCtrl::PosFromChar](#posfromchar)|Recupera as coordenadas da área de cliente de um caractere especificado em um controle de edição.|  
|[CRichEditCtrl::Redo](#redo)|Refaz a próxima ação na fila de restauração do controle.|  
|[CRichEditCtrl::ReplaceSel](#replacesel)|Substitui a seleção atual na `CRichEditCtrl` objeto com o texto especificado.|  
|[CRichEditCtrl::RequestResize](#requestresize)|Isso força o `CRichEditCtrl` objeto para enviar notificações de redimensionamento de solicitação.|  
|[CRichEditCtrl::SetAutoURLDetect](#setautourldetect)|Indica se a detecção automática do URL está ativa em um controle rich edit.|  
|[CRichEditCtrl::SetBackgroundColor](#setbackgroundcolor)|Define a cor de plano de fundo neste `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::SetDefaultCharFormat](#setdefaultcharformat)|Define o caractere padrão atual formatação atributos neste `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::SetEventMask](#seteventmask)|Define a máscara de evento para isso `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::SetModify](#setmodify)|Define ou limpa o sinalizador de modificação para este `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::SetOLECallback](#setolecallback)|Conjuntos de `IRichEditOleCallback` objeto COM para esse controle rich edit.|  
|[CRichEditCtrl::SetOptions](#setoptions)|Define as opções para isso `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::SetParaFormat](#setparaformat)|Define a formatação de atributos na seleção atual neste parágrafo `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::SetPunctuation](#setpunctuation)|Define os caracteres de pontuação para um controle rich edit. Esta mensagem está disponível apenas nas versões de idioma asiático do sistema operacional.|  
|[CRichEditCtrl::SetReadOnly](#setreadonly)|Define a opção de somente leitura para este `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::SetRect](#setrect)|Define o retângulo de formatação para isso `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::SetSel](#setsel)|Define a seleção nessa `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::SetSelectionCharFormat](#setselectioncharformat)|Define o caractere de formatação atributos na seleção atual neste `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::SetTargetDevice](#settargetdevice)|Define o dispositivo de saída de destino para este `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::SetTextMode](#settextmode)|Define o nível de desfazer ou de modo de texto de um controle rich edit. A mensagem de falha se o controle contiver texto.|  
|[CRichEditCtrl::SetUndoLimit](#setundolimit)|Define o número máximo de ações que podem ser armazenadas na fila de desfazer.|  
|[CRichEditCtrl::SetWordCharFormat](#setwordcharformat)|Define o caractere de formatação atributos da palavra atual neste `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::SetWordWrapMode](#setwordwrapmode)|Define as opções de quebra de palavras e quebra de palavras para o sofisticado de controle de edição. Esta mensagem está disponível apenas nas versões de idioma asiático do sistema operacional.|  
|[CRichEditCtrl::StopGroupTyping](#stopgrouptyping)|Interrompe o controle de coleta adicional de digitação ações para a ação de desfazer atual. O controle armazena a próxima ação de digitação, se houver, em uma nova ação na fila de desfazer.|  
|[CRichEditCtrl::StreamIn](#streamin)|Insere o texto de um fluxo de entrada em isso `CRichEditCtrl` objeto.|  
|[CRichEditCtrl::StreamOut](#streamout)|Armazena o texto neste `CRichEditCtrl` objeto em um fluxo de saída.|  
|[CRichEditCtrl::Undo](#undo)|Reverte a última operação de edição.|  
  
## <a name="remarks"></a>Comentários  
 "Controle rich edit" é uma janela na qual o usuário pode inserir e editar texto. O texto pode ser atribuído a formatação de parágrafo e caracteres e pode incluir objetos OLE incorporados. Controles de edição avançados fornecem uma interface de programação de formatação de texto. No entanto, um aplicativo deve implementar quaisquer componentes de interface do usuário necessários para tornar as operações de formatação disponíveis para o usuário.  
  
 Esse controle comum do Windows (e, portanto, a `CRichEditCtrl` classe) está disponível apenas para programas que executam versões do Windows 95/98 e Windows NT 3.51 e posterior. O `CRichEditCtrl` classe oferece suporte a versões 2.0 e 3.0 do [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] controle de edição avançado.  
  
> [!CAUTION]
>  Se você estiver usando um controle rich edit na caixa de diálogo (independentemente se o aplicativo está SDI, MDI, ou baseado em diálogo), você deve chamar [AfxInitRichEdit](application-information-and-management.md#afxinitrichedit) depois antes da caixa de diálogo caixa é exibida. Em geral para chamar essa função é em seu programa `InitInstance` função de membro. Você não precisa chamá-la sempre que você exibe a caixa de diálogo, somente na primeira vez. Você não precisa chamar `AfxInitRichEdit` se você estiver trabalhando com `CRichEditView`.  
  
 Para obter mais informações sobre como usar `CRichEditCtrl`, consulte:  
  
- [Controles](../../mfc/controls-mfc.md)  
  
- [Usando CRichEditCtrl](../../mfc/using-cricheditctrl.md)  
  
-   Artigo da Base de dados de Conhecimento Q259949: INFO: SetCaretPos() é não apropriado com CEdit ou controles de CRichEditCtrl  
  
 Para obter um exemplo de como usar um controle rich edit em um aplicativo MFC, consulte o [WORDPAD](../../visual-cpp-samples.md) aplicativo de exemplo.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CRichEditCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn.h  
  
##  <a name="canpaste"></a>CRichEditCtrl::CanPaste  
 Determina se o controle rich edit pode colar o formato da área de transferência especificado.  
  
```  
BOOL CanPaste(UINT nFormat = 0) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nFormat`  
 O formato de dados da área de transferência para consulta. Esse parâmetro pode ser um dos formatos predefinidos de área de transferência ou o valor retornado por [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049).  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o formato da área de transferência pode ser colado; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se `nFormat` é 0, `CanPaste` tentará qualquer formato atualmente na área de transferência.  
  
 Para obter mais informações, consulte [EM_CANPASTE](http://msdn.microsoft.com/library/windows/desktop/bb787993) mensagem e [RegisterClipboardFormat](http://msdn.microsoft.com/library/windows/desktop/ms649049) funcionar a [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl n º&1;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_1.cpp)]  
  
##  <a name="canredo"></a>CRichEditCtrl::CanRedo  
 Determina se a fila de restauração contém quaisquer ações.  
  
```  
BOOL CanRedo() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a fila de restauração contém ações, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para descobrir o nome da operação na fila de restauração, chame [CRichEditCtrl::GetRedoName](#getredoname). Para refazer a operação desfazer mais recente, chame [Refazer](#redo).  
  
 Para obter mais informações, consulte [EM_CANREDO](http://msdn.microsoft.com/library/windows/desktop/bb787995) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="canundo"></a>CRichEditCtrl::CanUndo  
 Determina se a última operação de edição pode ser desfeita.  
  
```  
BOOL CanUndo() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a última operação de edição pode ser desfeita por uma chamada para o [desfazer](#undo) função de membro; 0 se ela não pode ser desfeita.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [EM_CANUNDO](http://msdn.microsoft.com/library/windows/desktop/bb775468) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl n º&2;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_2.cpp)]  
  
##  <a name="charfrompos"></a>CRichEditCtrl::CharFromPos  
 Recupera informações sobre o caractere no ponto especificado pelo parâmetro `pt`.  
  
```  
int CharFromPos(CPoint pt) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pt`  
 A [CPoint](../../atl-mfc-shared/reference/cpoint-class.md) objeto que contém as coordenadas do ponto especificado.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de caracteres baseado em zero do caractere mais próximo ponto especificado. Se o ponto especificado estiver além do último caractere no controle, o valor de retorno indica o último caractere no controle.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro funciona com um controle rich edit. Para obter as informações de um controle de edição, chame [CEdit::CharFromPos](../../mfc/reference/cedit-class.md#charfrompos).  
  
 Para obter mais informações, consulte [EM_CHARFROMPOS](http://msdn.microsoft.com/library/windows/desktop/bb761566) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="clear"></a>CRichEditCtrl::Clear  
 Exclui (limpa) a seleção atual (se houver) na sofisticada de controle de edição.  
  
```  
void Clear();
```  
  
### <a name="remarks"></a>Comentários  
 A exclusão executada pelo **limpar** podem ser desfeitas chamando o [desfazer](#undo) função de membro.  
  
 Para excluir a seleção atual e colocar o conteúdo excluído na área de transferência, chame o [Recortar](#cut) função de membro.  
  
 Para obter mais informações, consulte [WM_CLEAR](http://msdn.microsoft.com/library/windows/desktop/ms649020) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl n º&3;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_3.cpp)]  
  
##  <a name="copy"></a>CRichEditCtrl::Copy  
 Copia a seleção atual (se houver) no controle de edição avançado na área de transferência.  
  
```  
void Copy();
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [WM_COPY](http://msdn.microsoft.com/library/windows/desktop/ms649022) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl n º&4;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_4.cpp)]  
  
##  <a name="create"></a>CRichEditCtrl::Create  
 Cria o controle rich edit Windows e o associa com isso `CRichEditCtrl` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Especifica o estilo do controle de edição. Aplicar uma combinação dos estilos de janela listados no **comentários** seção abaixo, e [Editar estilos de controle](http://msdn.microsoft.com/library/windows/desktop/bb775464), descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `rect`  
 Especifica o tamanho e a posição do controle de edição. Pode ser um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou [RECT](../../mfc/reference/rect-structure1.md) estrutura.  
  
 `pParentWnd`  
 Especifica a janela pai do controle de edição (geralmente um [CDialog](../../mfc/reference/cdialog-class.md)). Ele não deve ser **nulo**.  
  
 `nID`  
 Especifica a ID. do controle de edição  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a inicialização for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você construir um `CRichEditCtrl` objeto em duas etapas. Primeiro, chame o [CRichEditCtrl](#cricheditctrl) construtor, em seguida, chame **criar**, que cria o controle de edição do Windows e o anexa ao `CRichEditCtrl` objeto.  
  
 Quando você cria um controle rich edit com essa função, primeiro você deve carregar a biblioteca de controles comuns necessários. Para carregar a biblioteca, chame a função global [AfxInitRichEdit](application-information-and-management.md#afxinitrichedit), que por sua vez inicializa a biblioteca de controles comuns. É necessário chamar `AfxInitRichEdit` apenas uma vez em seu processo.  
  
 Quando **criar** executa o Windows envia o [WM_NCCREATE](../../mfc/reference/cwnd-class.md#onnccreate), [WM_NCCALCSIZE](../../mfc/reference/cwnd-class.md#onnccalcsize), [WM_CREATE](../../mfc/reference/cwnd-class.md#oncreate), e [WM_GETMINMAXINFO](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) mensagens para o controle de edição.  
  
 Essas mensagens são manipuladas por padrão, o [OnNcCreate](../../mfc/reference/cwnd-class.md#onnccreate), [OnNcCalcSize](../../mfc/reference/cwnd-class.md#onnccalcsize), [OnCreate](../../mfc/reference/cwnd-class.md#oncreate), e [OnGetMinMaxInfo](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) funções de membro na `CWnd` classe base. Para estender a manipulação de mensagem padrão, derive uma classe de `CRichEditCtrl`, adicione um mapa da mensagem para a nova classe e substituir as funções de membro acima do manipulador de mensagens. Substituir `OnCreate`, por exemplo, para executar inicialização necessária para a nova classe.  
  
 Aplique o seguinte [estilos de janela](../../mfc/reference/window-styles.md) para um controle de edição.  
  
- **Estilo** sempre.  
  
- **WS_VISIBLE** normalmente.  
  
- **WS_DISABLED** raramente.  
  
- **WS_GROUP** para agrupar controles.  
  
- **WS_TABSTOP** para incluir o controle de edição na ordem de tabulação.  
  
 Para obter mais informações sobre estilos de janela, consulte [CreateWindow](http://msdn.microsoft.com/library/windows/desktop/ms632679) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl n º&5;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_5.cpp)]  
  
##  <a name="createex"></a>CRichEditCtrl::CreateEx  
 Cria um controle (uma janela filho) e o associa a `CRichEditCtrl` objeto.  
  
```  
virtual BOOL CreateEx(
    DWORD dwExStyle,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwExStyle`  
 Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista dos estilos estendidos do Windows, consulte o `dwExStyle` parâmetro [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `dwStyle`  
 Especifica o estilo do controle de edição. Aplicar uma combinação dos estilos de janela listados no **comentários** seção [criar](#create) e [Editar estilos de controle](http://msdn.microsoft.com/library/windows/desktop/bb775464), descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `rect`  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que descreve o tamanho e a posição da janela deve ser criada, nas coordenadas do cliente de `pParentWnd`.  
  
 `pParentWnd`  
 Um ponteiro para a janela que é o pai do controle.  
  
 `nID`  
 ID da janela filho. do controle  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use `CreateEx` em vez de **criar** para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido Windows **WS_EX_**.  
  
##  <a name="cricheditctrl"></a>CRichEditCtrl::CRichEditCtrl  
 Constrói um objeto `CRichEditCtrl`.  
  
```  
CRichEditCtrl();
```  
  
### <a name="remarks"></a>Comentários  
 Use [criar](#create) para construir as janelas de controle edição avançada.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl n º&6;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_6.cpp)]  
  
##  <a name="cut"></a>CRichEditCtrl::Cut  
 Excluir (cortes) a seleção atual (se houver) no amplo controle de edição e copia o texto excluído na área de transferência.  
  
```  
void Cut();
```  
  
### <a name="remarks"></a>Comentários  
 A exclusão executada pelo **Recortar** podem ser desfeitas chamando o [desfazer](#undo) função de membro.  
  
 Para excluir a seleção atual sem colocar o texto excluído na área de transferência, chame o [limpar](#clear) função de membro.  
  
 Para obter mais informações, consulte [WM_CUT](http://msdn.microsoft.com/library/windows/desktop/ms649023) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl&#7;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_7.cpp)]  
  
##  <a name="displayband"></a>CRichEditCtrl::DisplayBand  
 Exibe uma parte do conteúdo do controle de edição avançada (texto e itens OLE), formatada como anteriormente por [FormatRange](#formatrange).  
  
```  
BOOL DisplayBand(LPRECT pDisplayRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDisplayRect`  
 Ponteiro para uma [RECT](../../mfc/reference/rect-structure1.md) ou [CRect](../../atl-mfc-shared/reference/crect-class.md) especificando a área do dispositivo para exibir o texto do objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a exibição do texto formatado for bem-sucedida, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 O texto e os itens OLE são cortados para a área especificada pelo ponteiro `pDisplayRect`.  
  
 Para obter mais informações, consulte [EM_DISPLAYBAND](http://msdn.microsoft.com/library/windows/desktop/bb787997) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRichEditCtrl::FormatRange](#formatrange).  
  
##  <a name="emptyundobuffer"></a>CRichEditCtrl::EmptyUndoBuffer  
 (Clear) redefine o sinalizador desfazer esse controle rich edit.  
  
```  
void EmptyUndoBuffer();
```  
  
### <a name="remarks"></a>Comentários  
 O controle agora será possível desfazer a última operação de edição. O sinalizador de desfazer é definido sempre que uma operação em que o controle rich edit pode ser desfeita.  
  
 O sinalizador de desfazer é removido automaticamente sempre que você chamar o [CWnd](../../mfc/reference/cwnd-class.md) função de membro [SetWindowText](../../mfc/reference/cwnd-class.md#setwindowtext).  
  
 Para obter mais informações, consulte [EM_EMPTYUNDOBUFFER](http://msdn.microsoft.com/library/windows/desktop/bb761568) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl n º&8;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_8.cpp)]  
  
##  <a name="findtext"></a>CRichEditCtrl::FindText  
 Localiza texto dentro do controle rich edit.  
  
```  
long FindText(
    DWORD dwFlags,  
    FINDTEXTEX* pFindText) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwFlags`  
 Para obter uma lista dos valores possíveis, consulte `wParam` na [EM_FINDTEXTEXT](http://msdn.microsoft.com/library/windows/desktop/bb788011) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 *pFindText*  
 Ponteiro para o [FINDTEXTEX](http://msdn.microsoft.com/library/windows/desktop/bb787909) estrutura fornecendo os parâmetros para a pesquisa e retornar o intervalo em que a correspondência foi encontrada.  
  
### <a name="return-value"></a>Valor de retorno  
 Posição do caractere com base em zero da próxima correspondência; – 1 se não houver nenhuma outra correspondência.  
  
### <a name="remarks"></a>Comentários  
 Você pode pesquisar para cima ou para baixo, definindo os parâmetros de intervalo adequado no [CHARRANGE](http://msdn.microsoft.com/library/windows/desktop/bb787885) estrutura dentro do **FINDTEXTEX** estrutura.  
  
 Para obter mais informações, consulte [EM_FINDTEXTEX](http://msdn.microsoft.com/library/windows/desktop/bb788011) mensagem e [FINDTEXTEX](http://msdn.microsoft.com/library/windows/desktop/bb787909) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl n º&9;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_9.cpp)]  
  
##  <a name="findwordbreak"></a>CRichEditCtrl::FindWordBreak  
 Localiza a próxima quebra de palavras antes ou após a posição especificada pelo `nStart`.  
  
```  
DWORD FindWordBreak(
    UINT nCode,  
    DWORD nStart) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nCode`  
 Indica a ação a ser tomada. Para obter uma lista dos valores possíveis, consulte a descrição para o parâmetro `code` na **EM_FINDWORDBREAK** no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `nStart`  
 A posição do caractere com base em zero do início.  
  
### <a name="return-value"></a>Valor de retorno  
 Com base no parâmetro `nCode`. Para obter mais informações, consulte [EM_FINDWORDBREAK](http://msdn.microsoft.com/library/windows/desktop/bb788018) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Você pode usar essa função de membro para recuperar informações sobre um caractere na posição especificada.  
  
##  <a name="formatrange"></a>CRichEditCtrl::FormatRange  
 Formata um intervalo de texto em um controle rich edit para um dispositivo específico.  
  
```  
long FormatRange(
    FORMATRANGE* pfr,  
    BOOL bDisplay = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *PFR*  
 Ponteiro para o [FORMATRANGE](http://msdn.microsoft.com/library/windows/desktop/bb787911) estrutura que contém informações sobre o dispositivo de saída. **NULO** indica que as informações armazenadas em cache dentro o controle rich edit podem ser liberadas.  
  
 *bDisplay*  
 Indica se o texto deve ser renderizado. Se **FALSE**, o texto é medido apenas.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do último caractere que se ajusta a região mais um.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, essa chamada é seguida por uma chamada para [DisplayBand](#displayband).  
  
 Para obter mais informações, consulte [EM_FORMATRANGE](http://msdn.microsoft.com/library/windows/desktop/bb788020) mensagem e [FORMATRANGE](http://msdn.microsoft.com/library/windows/desktop/bb787911) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl n º&10;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_10.cpp)]  
  
##  <a name="getcharpos"></a>CRichEditCtrl::GetCharPos  
 Obtém a posição (canto superior esquerdo) de um determinado caractere dentro dessa `CRichEditCtrl` objeto.  
  
```  
CPoint GetCharPos(long lChar) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lChar`  
 Índice baseado em zero do caractere.  
  
### <a name="return-value"></a>Valor de retorno  
 O local do canto superior esquerdo do caractere especificado por `lChar`.  
  
### <a name="remarks"></a>Comentários  
 O caractere for especificado, fornecendo seu valor de índice baseado em zero. Se `lChar` é maior do que o índice do último caractere na `CRichEditCtrl` do objeto, o valor de retorno Especifica as coordenadas de posição do caractere apenas após o último caractere no `CRichEditCtrl` objeto.  
  
 Para obter mais informações, consulte [EM_POSFROMCHAR](http://msdn.microsoft.com/library/windows/desktop/bb761631) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getdefaultcharformat"></a>CRichEditCtrl::GetDefaultCharFormat  
 Obtém o caractere padrão de formatação atributos deste `CRichEditCtrl` objeto.  
  
```  
DWORD GetDefaultCharFormat(CHARFORMAT& cf) const;  DWORD GetDefaultCharFormat(CHARFORMAT2& cf) const;  ```  
  
### Parameters  
 `cf`  
 In the first version, a pointer to a **CHARFORMAT** structure holding the default character formatting attributes.  
  
 In the second version, a pointer to a **CHARFORMAT2** structure, which is a Rich Edit 2.0 extension to the **CHARFORMAT** structure, holding the default character formatting attributes.  
  
### Return Value  
 The **dwMask** data member of `cf`. It specified the default character formatting attributes.  
  
### Remarks  
 For more information, see the **EM_GETCHARFORMAT** message and the **CHARFORMAT** and **CHARFORMAT2** structures in the [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### Example  
  See the example for [SetDefaultCharFormat](#setdefaultcharformat).  
  
##  <a name="geteventmask"></a>  CRichEditCtrl::GetEventMask  
 Gets the event mask for this `CRichEditCtrl` object.  
  
```  
longo GetEventMask() const;  
```  
  
### Return Value  
 The event mask for this `CRichEditCtrl` object.  
  
### Remarks  
 The event mask specifies which notification messages the `CRichEditCtrl` object sends to its parent window.  
  
 For more information, see [EM_GETEVENTMASK](http://msdn.microsoft.com/library/windows/desktop/bb788032) in the [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### Example  
  See the example for [CRichEditCtrl::SetEventMask](#seteventmask).  
  
##  <a name="getfirstvisibleline"></a>  CRichEditCtrl::GetFirstVisibleLine  
 Determines the topmost visible line in this `CRichEditCtrl` object.  
  
```  
int GetFirstVisibleLine() const;  
```  
  
### Return Value  
 Zero-based index of the uppermost visible line in this `CRichEditCtrl` object.  
  
### Remarks  
 For more information, see [EM_GETFIRSTVISIBLELINE](http://msdn.microsoft.com/library/windows/desktop/bb761574) in the [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### Example  
 [!code-cpp[NVC_MFC_CRichEditCtrl#11](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_11.cpp)]  
  
##  <a name="getiricheditole"></a>  CRichEditCtrl::GetIRichEditOle  
 Accesses the **IRichEditOle** interface for this `CRichEditCtrl` object.  
  
```  
IRichEditOle * GetIRichEditOle() const;  
```  
  
### Return Value  
 Pointer to the [IRichEditOle](http://msdn.microsoft.com/library/windows/desktop/bb774306) interface that can be used to access this `CRichEditCtrl` object's OLE functionality; **NULL** if the interface is not accessible.  
  
### Remarks  
 Use this interface to access this `CRichEditCtrl` object's OLE functionality.  
  
 For more information, see [EM_GETOLEINTERFACE](http://msdn.microsoft.com/library/windows/desktop/bb788041) message and [IRichEditOle](http://msdn.microsoft.com/library/windows/desktop/bb774306) interface in the [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getlimittext"></a>  CRichEditCtrl::GetLimitText  
 Gets the text limit for this `CRichEditCtrl` object.  
  
```  
longo GetLimitText() const;  
```  
  
### Return Value  
 The current text limit, in bytes, for this `CRichEditCtrl` object.  
  
### Remarks  
 The text limit is the maximum amount of text, in bytes, the rich edit control can accept.  
  
 For more information, see [EM_GETLIMITTEXT](http://msdn.microsoft.com/library/windows/desktop/bb761582) in the [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### Example  
 [!code-cpp[NVC_MFC_CRichEditCtrl#12](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_12.cpp)]  
  
##  <a name="getline"></a>  CRichEditCtrl::GetLine  
 Retrieves a line of text from this `CRichEditCtrl` object.  
  
```  
GetLine (nIndex int, int  
    LpszBuffer LPTSTR) const;  
  
GetLine (nIndex int, int  
    LpszBuffer LPTSTR,  
    nMaxLength int) const;  
```  
  
### Parameters  
 `nIndex`  
 Zero-based index of the line to retrieve.  
  
 `lpszBuffer`  
 Points to the buffer to receive the text. The first word of the buffer must specify the maximum number of bytes that can be copied into the buffer.  
  
 `nMaxLength`  
 Maximum number of characters that can be copied into `lpszBuffer`. The second form of `GetLine` places this value into the first word of the buffer specified by `lpszBuffer`.  
  
### Return Value  
 The number of characters copied into `lpszBuffer`.  
  
### Remarks  
 The copied line does not contain a terminating null character.  
  
> [!NOTE]
>  Because the first word of the buffer stores the number of characters to be copied, make sure that your buffer is at least 4 bytes long.  
  
 For more information, see [EM_GETLINE](http://msdn.microsoft.com/library/windows/desktop/bb761584) in the [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### Example  
  See the example for [GetLineCount](#getlinecount).  
  
##  <a name="getlinecount"></a>  CRichEditCtrl::GetLineCount  
 Retrieves the number of lines in the `CRichEditCtrl` object.  
  
```  
int GetLineCount() const;  
```  
  
### Return Value  
 The number of lines in this `CRichEditCtrl` object.  
  
### Remarks  
 For more information, see [EM_GETLINECOUNT](http://msdn.microsoft.com/library/windows/desktop/bb761586) in the [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### Example  
 [!code-cpp[NVC_MFC_CRichEditCtrl#13](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_13.cpp)]  
  
##  <a name="getmodify"></a>  CRichEditCtrl::GetModify  
 Determines if the contents of this `CRichEditCtrl` object have been modified.  
  
```  
BOOL GetModify() const;  
```  
  
### Return Value  
 Nonzero if the text in this `CRichEditCtrl` object has been modified; otherwise 0.  
  
### Remarks  
 Windows maintains an internal flag indicating whether the contents of the rich edit control have been changed. This flag is cleared when the edit control is first created and can also be cleared by calling the [SetModify](#setmodify) member function.  
  
 For more information, see [EM_GETMODIFY](http://msdn.microsoft.com/library/windows/desktop/bb761592) in the [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### Example  
 [!code-cpp[NVC_MFC_CRichEditCtrl#14](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_14.cpp)]  
  
##  <a name="getoptions"></a>  CRichEditCtrl::GetOptions  
 Retrieves the options currently set for the rich edit control.  
  
```  
UINT GetOptions() const;  
```  
  
### Return Value  
 A combination of the current option flag values. For a list of these values, see the *fOptions* parameter in the [EM_SETOPTIONS](http://msdn.microsoft.com/library/windows/desktop/bb774254) message, as described in the [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getparaformat"></a>  CRichEditCtrl::GetParaFormat  
 Gets the paragraph formatting attributes of the current selection.  
  
```  
DWORD GetParaFormat(PARAFORMAT& pf) const;  DWORD GetParaFormat(PARAFORMAT2& pf) const;  ```  
  
### <a name="parameters"></a>Parâmetros  
 `pf`  
 Na primeira versão, um ponteiro para um [PARAFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb787940) para conter os atributos da seleção atual de formatação de parágrafo.  
  
 Na segunda versão, um ponteiro para um [PARAFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787942) estrutura, que é uma extensão de Rich Editar 2.0 para o **PARAFORMAT** estrutura, que contém o caractere padrão de atributos de formatação.  
  
### <a name="return-value"></a>Valor de retorno  
 O **dwMask** membro de dados de `pf`. Especifica os atributos que são consistentes em toda a seleção atual de formatação de parágrafo.  
  
### <a name="remarks"></a>Comentários  
 Se mais de um parágrafo for selecionado, `pf` recebe os atributos do primeiro parágrafo selecionado. O valor de retorno Especifica quais atributos estão consistentes em toda a seleção.  
  
 Para obter mais informações, consulte o [EM_GETPARAFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb774182) mensagem e o **PARAFORMAT** e **PARAFORMAT2** estruturas no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRichEditCtrl::SetParaFormat](#setparaformat).  
  
##  <a name="getpunctuation"></a>CRichEditCtrl::GetPunctuation  
 Obtém os caracteres de pontuação atual em um controle rich edit.  
  
```  
BOOL GetPunctuation(
    UINT fType,  
    PUNCTUATION* lpPunc) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `fType`  
 O sinalizador de tipo de pontuação, conforme descrito na `fType` parâmetro do [EM_GETPUNCTUATION](http://msdn.microsoft.com/library/windows/desktop/bb774184) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `lpPunc`  
 Um ponteiro para um [PONTUAÇÃO](http://msdn.microsoft.com/library/windows/desktop/bb787944) estrutura, conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação foi bem-sucedida, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro está disponível com apenas as versões para idioma asiático do sistema operacional.  
  
##  <a name="getrect"></a>CRichEditCtrl::GetRect  
 Recupera o retângulo de formatação para isso `CRichEditCtrl` objeto.  
  
```  
void GetRect(LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 [CRect](../../atl-mfc-shared/reference/crect-class.md) ou ponteiro para um [RECT](../../mfc/reference/rect-structure1.md) para receber o retângulo formatação isso `CRichEditCtrl` objeto.  
  
### <a name="remarks"></a>Comentários  
 O retângulo de formatação é o retângulo delimitador do texto. Esse valor é independente do tamanho do `CRichEditCtrl` objeto.  
  
 Para obter mais informações, consulte [EM_GETRECT](http://msdn.microsoft.com/library/windows/desktop/bb761596) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [LimitText](#limittext).  
  
##  <a name="getredoname"></a>CRichEditCtrl::GetRedoName  
 Recupera o tipo da próxima ação disponível na fila de restauração, se houver.  
  
```  
UNDONAMEID GetRedoName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, `GetRedoName` retorna o [UNDONAMEID](http://msdn.microsoft.com/library/windows/desktop/bb774365) tipo de enumeração que indica o tipo da ação Avançar na fila de restauração do controle. Se a fila de restauração está vazia ou se a ação de refazer na fila é de um tipo desconhecido, `GetRedoName` retornará 0.  
  
### <a name="remarks"></a>Comentários  
 Os tipos de ações que podem ser desfeitas ou refeitas incluem digitando, excluir, arrastar e soltar, recortar e colagem operações. Essa informação pode ser útil para aplicativos que fornecem uma interface de usuário estendida para operações de desfazer e refazer, como uma caixa de lista suspensa de ações redoable.  
  
##  <a name="getsel"></a>CRichEditCtrl::GetSel  
 Recupera os limites da seleção atual neste `CRichEditCtrl` objeto.  
  
```  
void GetSel(CHARRANGE& cr) const;  
  
void GetSel(
    long& nStartChar,  
    long& nEndChar) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `cr`  
 Referência a um [CHARRANGE](http://msdn.microsoft.com/library/windows/desktop/bb787885) estrutura para receber os limites da seleção atual.  
  
 `nStartChar`  
 Índice baseado em zero do primeiro caractere na seleção atual.  
  
 `nEndChar`  
 Índice baseado em zero do último caractere na seleção atual.  
  
### <a name="remarks"></a>Comentários  
 As duas formas dessa função oferecem formas alternativas de obter os limites para a seleção. Execute as breves descrições destas formas:  
  
- **GetSel (** `cr` **)** este formulário usa o **CHARRANGE** estrutura com seus **cpMin** e **cpMax** membros para retornar os limites.  
  
- **GetSel (** `nStartChar` **,** `nEndChar` **)** este formulário retorna os limites nos parâmetros de `nStartChar` e `nEndChar`.  
  
 A seleção inclui tudo o que se o início ( **cpMin** ou `nStartChar`) é 0 e o final ( **cpMax** ou `nEndChar`) é – 1.  
  
 Para obter mais informações, consulte [EM_EXGETSEL](http://msdn.microsoft.com/library/windows/desktop/bb788001) mensagem e [CHARRANGE](http://msdn.microsoft.com/library/windows/desktop/bb787885) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl&#15;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_15.cpp)]  
  
##  <a name="getselectioncharformat"></a>CRichEditCtrl::GetSelectionCharFormat  
 Obtém o caractere de formatação atributos da seleção atual.  
  
```  
DWORD GetSelectionCharFormat(CHARFORMAT& cf) const;  DWORD GetSelectionCharFormat(CHARFORMAT2& cf) const;  ```  
  
### Parameters  
 `cf`  
 In the first version, a pointer to a [CHARFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb787881) structure to receive the character formatting attributes of the current selection.  
  
 In the second version, a pointer to a [CHARFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787883) structure, which is a Rich Edit 2.0 extension to the **CHARFORMAT** structure to receive the character formatting attributes of the current selection.  
  
### Return Value  
 The **dwMask** data member of `cf`. It specifies the character formatting attributes that are consistent throughout the current selection.  
  
### Remarks  
 The `cf` parameter receives the attributes of the first character in the current selection. The return value specifies which attributes are consistent throughout the selection.  
  
 For more information, see the [EM_GETCHARFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb788026) message and the **CHARFORMAT** and **CHARFORMAT2** structures in the [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### Example  
  See the example for [SetSelectionCharFormat](#setselectioncharformat).  
  
##  <a name="getselectiontype"></a>  CRichEditCtrl::GetSelectionType  
 Determines the selection type in this `CRichEditCtrl` object.  
  
```  
GetSelectionType() WORD const;  
```  
  
### Return Value  
 Flags indicating the contents of the current selection. A combination of the following flags:  
  
- `SEL_EMPTY` Indicates that there is no current selection.  
  
- `SEL_TEXT` Indicates that the current selection contains text.  
  
- `SEL_OBJECT` Indicates that the current selection contains at least one OLE item.  
  
- `SEL_MULTICHAR` Indicates that the current selection contains more than one character of text.  
  
- `SEL_MULTIOBJECT` Indicates that the current selection contains more than one OLE object.  
  
### Remarks  
 For more information, see [EM_SELECTIONTYPE](http://msdn.microsoft.com/library/windows/desktop/bb774223) in the [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### Example  
 [!code-cpp[NVC_MFC_CRichEditCtrl#16](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_16.cpp)]  
  
##  <a name="getseltext"></a>  CRichEditCtrl::GetSelText  
 Retrieves the text from the current selection in this `CRichEditCtrl` object.  
  
```  
longo GetSelText(LPSTR lpBuf) const;  CString GetSelText() const;  ```  
  
### <a name="parameters"></a>Parâmetros  
 `lpBuf`  
 Ponteiro para o buffer para receber o texto da seleção atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Depende do formulário:  
  
- **GetSelText (** `lpBuf` **)** o número de caracteres copiados para `lpBuf`, não incluindo a finalização null.  
  
- **(GetSelText)** a cadeia de caracteres que contém a seleção atual.  
  
### <a name="remarks"></a>Comentários  
 Se você usar o primeiro formulário **GetSelText (** `lpBuf` **)**, você deve garantir que o buffer seja grande o suficiente para o texto que será exibida. Chamar [GetSel](#getsel) para determinar o número de caracteres na seleção atual.  
  
 Para obter mais informações, consulte [EM_GETSELTEXT](http://msdn.microsoft.com/library/windows/desktop/bb774190) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CRichEditCtrl::GetSelectionType](#getselectiontype).  
  
##  <a name="gettextlength"></a>CRichEditCtrl::GetTextLength  
 Recupera o comprimento do texto, em caracteres, neste `CRichEditCtrl` objeto, não incluindo o caractere de terminação nula.  
  
```  
long GetTextLength() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento do texto nesse `CRichEditCtrl` objeto.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [WM_GETTEXTLENGTH](http://msdn.microsoft.com/library/windows/desktop/ms632628) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[17 NVC_MFC_CRichEditCtrl](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_17.cpp)]  
  
##  <a name="gettextlengthex"></a>CRichEditCtrl::GetTextLengthEx  
 Calcula o tamanho do texto no controle de edição avançada.  
  
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
 `GetTextLengthEx`oferece outras maneiras de determinar o comprimento do texto. Ele oferece suporte a funcionalidade avançada Editar 2.0. Consulte [sobre controles sofisticados de editar](http://msdn.microsoft.com/library/windows/desktop/bb787873) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]para obter mais informações.  
  
##  <a name="gettextmode"></a>CRichEditCtrl::GetTextMode  
 Recupera o texto modo e desfazer nível atual de um controle rich edit.  
  
```  
UINT GetTextMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um conjunto de sinalizadores de bit do [TEXTMODE](http://msdn.microsoft.com/library/windows/desktop/bb774364) tipo de enumeração, conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Os sinalizadores de indicam o modo de texto atual e desfazer o nível do controle.  
  
##  <a name="gettextrange"></a>CRichEditCtrl::GetTextRange  
 Obtém o intervalo especificado de caracteres.  
  
```  
int GetTextRange(
    int nFirst,  
    int nLast,  
    CString& refString) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nFirst`  
 O índice de posição de caractere imediatamente antes do primeiro caractere no intervalo.  
  
 `nLast`  
 A posição do caractere imediatamente após o último caractere no intervalo.  
  
 `refString`  
 Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que receberá o texto.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de caracteres copiados, sem incluir o caractere de terminação nula.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [EM_GETTEXTRANGE](http://msdn.microsoft.com/library/windows/desktop/bb774199) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `GetTextRange`oferece suporte a funcionalidade avançada Editar 2.0. Consulte [sobre controles sofisticados de editar](http://msdn.microsoft.com/library/windows/desktop/bb787873) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]para obter mais informações.  
  
##  <a name="getundoname"></a>CRichEditCtrl::GetUndoName  
 Recupera o tipo da próxima ação disponível na fila de desfazer, se houver.  
  
```  
UNDONAMEID GetUndoName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se uma ação de desfazer está na fila de desfazer do controle, `GetUndoName` retorna o [UNDONAMEID](http://msdn.microsoft.com/library/windows/desktop/bb774365) tipo de enumeração que indica o tipo da ação Avançar na fila. Se a fila de desfazer está vazia ou se a ação de desfazer na fila é de um tipo desconhecido, `GetUndoName` retornará 0.  
  
### <a name="remarks"></a>Comentários  
 Os tipos de ações que podem ser desfeitas ou refeitas incluem digitando, excluir, arrastar e soltar, recortar e colagem operações. Essa informação pode ser útil para aplicativos que fornecem uma interface de usuário estendida para operações de desfazer e refazer, como uma caixa de lista suspensa de ações que podem ser desfeitas.  
  
##  <a name="getwordwrapmode"></a>CRichEditCtrl::GetWordWrapMode  
 Recupera a quebra de texto atual e opções de quebra de palavras para o controle rich edit.  
  
```  
UINT GetWordWrapMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A quebra de texto atual e opções de quebra de palavras. Essas opções são descritas na [EM_SETWORDWRAPMODE](http://msdn.microsoft.com/library/windows/desktop/bb774294) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro está disponível somente para versões de idioma asiático do sistema operacional.  
  
##  <a name="hideselection"></a>CRichEditCtrl::HideSelection  
 Altera a visibilidade da seleção.  
  
```  
void HideSelection(
    BOOL bHide,  
    BOOL bPerm);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bHide`  
 Indica se a seleção deve ser mostrada ou oculta, **TRUE** para ocultar a seleção.  
  
 `bPerm`  
 Indica se esta alteração na visibilidade para a seleção deve ser permanente.  
  
### <a name="remarks"></a>Comentários  
 Quando `bPerm` é **TRUE**, ele altera o `ECO_NOHIDESEL` opção desta `CRichEditCtrl` objeto. Para obter uma breve descrição dessa opção, consulte [SetOptions](#setoptions). Você pode usar essa função para definir todas as opções para este `CRichEditCtrl` objeto.  
  
 Para obter mais informações, consulte [EM_HIDESELECTION](http://msdn.microsoft.com/library/windows/desktop/bb774210) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl n º&18;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_18.cpp)]  
  
##  <a name="limittext"></a>CRichEditCtrl::LimitText  
 Limita o comprimento do texto que o usuário pode inserir em um controle de edição.  
  
```  
void LimitText(long nChars = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nChars`  
 Especifica o comprimento (em bytes) do que o usuário pode digitar texto. Se esse parâmetro for 0 (o valor padrão), o comprimento do texto é definido como 64K bytes.  
  
### <a name="remarks"></a>Comentários  
 Alterar o limite de texto restringe somente o texto que o usuário pode inserir. Não tem nenhum efeito em qualquer texto já no controle de edição, nem afeta o tamanho do texto copiado para o controle de edição, o [SetWindowText](../../mfc/reference/cwnd-class.md#setwindowtext) função de membro em `CWnd`. Se um aplicativo usa o `SetWindowText` função colocar mais texto em um controle de edição que é especificado na chamada para `LimitText`, o usuário pode excluir o texto dentro do controle de edição. No entanto, o limite de texto impedirá que o usuário substituindo o texto existente pelo novo texto, a menos que excluindo a seleção atual faz com que o texto esteja abaixo do limite de texto.  
  
> [!NOTE]
>  Para o limite de texto, cada item OLE conta como um único caractere.  
  
 Para obter mais informações, consulte [EM_EXLIMITTEXT](http://msdn.microsoft.com/library/windows/desktop/bb788003) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[19 NVC_MFC_CRichEditCtrl](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_19.cpp)]  
  
##  <a name="linefromchar"></a>CRichEditCtrl::LineFromChar  
 Recupera o número da linha que contém o índice do caractere especificado.  
  
```  
long LineFromChar(long nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Contém o valor de índice baseado em zero para o caractere desejado no texto do controle de edição ou contém –&1;. Se `nIndex` é –&1;, ele especifica a linha atual, ou seja, a linha que contém o cursor.  
  
### <a name="return-value"></a>Valor de retorno  
 O número da linha de base zero da linha que contém o índice do caractere especificado por `nIndex`. Se `nIndex` é –&1;, o número da linha que contém o primeiro caractere da seleção é retornado. Se não houver nenhuma seleção, o número da linha atual será retornado.  
  
### <a name="remarks"></a>Comentários  
 Um índice de caractere é o número de caracteres do início do controle rich edit. Para a contagem de caracteres, um item OLE é contado como um único caractere.  
  
 Para obter mais informações, consulte [EM_EXLINEFROMCHAR](http://msdn.microsoft.com/library/windows/desktop/bb788005) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[20 NVC_MFC_CRichEditCtrl](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_20.cpp)]  
  
##  <a name="lineindex"></a>CRichEditCtrl::LineIndex  
 Recupera o índice do caractere de uma linha dentro dessa `CRichEditCtrl` objeto.  
  
```  
int LineIndex(int nLine = -1) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nLine`  
 Contém o valor de índice de linha desejada no texto do controle de edição ou contém –&1;. Se `nLine` é –&1;, ele especifica a linha atual, ou seja, a linha que contém o cursor.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do caractere da linha especificada no `nLine` ou -1 se o número de linha especificado é maior e o número de linhas no controle de edição.  
  
### <a name="remarks"></a>Comentários  
 O índice do caractere é o número de caracteres do início do controle de edição avançado para a linha especificada.  
  
 Para obter mais informações, consulte [EM_LINEINDEX](http://msdn.microsoft.com/library/windows/desktop/bb761611) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl&#21;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_21.cpp)]  
  
##  <a name="linelength"></a>CRichEditCtrl::LineLength  
 Recupera o comprimento de uma linha em um controle rich edit.  
  
```  
int LineLength(int nLine = -1) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nLine`  
 Especifica o índice de um caractere na linha cujo tamanho deve ser recuperado. Se esse parâmetro é –&1;, o comprimento da linha atual (a linha que contém o cursor) é retornado, sem incluir o comprimento de qualquer texto na linha selecionado. Quando `LineLength` é chamado para um controle de edição de linha única, esse parâmetro será ignorado.  
  
### <a name="return-value"></a>Valor de retorno  
 Quando `LineLength` é chamado para um controle de edição de várias linhas, o valor de retorno é o comprimento (em bytes) da linha especificada por `nLine`. Quando `LineLength` é chamado para um controle de edição de linha única, o valor de retorno é o comprimento (em bytes) do texto no controle de edição.  
  
### <a name="remarks"></a>Comentários  
 Use o [LineIndex](#lineindex) função de membro para recuperar um índice de caractere para um dado número de linha dentro dessa `CRichEditCtrl` objeto.  
  
 Para obter mais informações, consulte [EM_LINELENGTH](http://msdn.microsoft.com/library/windows/desktop/bb761613) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [LineIndex](#lineindex).  
  
##  <a name="linescroll"></a>CRichEditCtrl::LineScroll  
 Rola o texto de um controle de edição de várias linhas.  
  
```  
void LineScroll(
    int nLines,  
    int nChars = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nLines`  
 Especifica o número de linhas para rolar verticalmente.  
  
 `nChars`  
 Especifica o número de posições de caractere para rolar horizontalmente. Esse valor é ignorado se o controle rich edit tem o **ES_RIGHT** ou **ES_CENTER** estilo. [Editar estilos](../../mfc/reference/edit-styles.md) são especificados em [criar](#create).  
  
### <a name="remarks"></a>Comentários  
 O controle de edição não rola verticalmente após a última linha do texto no controle de edição. Se a linha atual mais o número de linhas especificado pelo `nLines` excede o número total de linhas no controle de edição, o valor é ajustado para que a última linha do controle de edição é rolada para a parte superior da janela de controle de edição.  
  
 `LineScroll`pode ser usado para rolar horizontalmente após o último caractere de qualquer linha.  
  
 Para obter mais informações, consulte [EM_LINESCROLL](http://msdn.microsoft.com/library/windows/desktop/bb761615) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [GetFirstVisibleLine](#getfirstvisibleline).  
  
##  <a name="paste"></a>CRichEditCtrl::Paste  
 Insere os dados da área de transferência para o `CRichEditCtrl` no ponto de inserção, o local do cursor.  
  
```  
void Paste();
```  
  
### <a name="remarks"></a>Comentários  
 Dados são inseridos somente se a área de transferência contém dados em um formato reconhecido.  
  
 Para obter mais informações, consulte [WM_PASTE](http://msdn.microsoft.com/library/windows/desktop/ms649028) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl&#22;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_22.cpp)]  
  
##  <a name="pastespecial"></a>CRichEditCtrl::PasteSpecial  
 Cola dados em um formato específico da área de transferência em isso `CRichEditCtrl` objeto.  
  
```  
void PasteSpecial(
    UINT nClipFormat,  
    DWORD dvAspect = 0,  
    HMETAFILE hMF = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nClipFormat*  
 Formato de área de transferência para colar isso `CRichEditCtrl` objeto.  
  
 *dvAspect*  
 Aspecto de dispositivo para os dados a serem recuperados da área de transferência.  
  
 *hMF*  
 Manipula o metarquivo que contém o modo de exibição de ícones do objeto a ser colado.  
  
### <a name="remarks"></a>Comentários  
 O novo material é inserido no ponto de inserção, o local do cursor.  
  
 Para obter mais informações, consulte [EM_PASTESPECIAL](http://msdn.microsoft.com/library/windows/desktop/bb774214) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl&#23;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_23.cpp)]  
  
##  <a name="posfromchar"></a>CRichEditCtrl::PosFromChar  
 Recupera as coordenadas da área de cliente de um caractere especificado em um controle de edição.  
  
```  
CPoint PosFromChar(UINT nChar) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nChar`  
 O índice baseado em zero do caractere.  
  
### <a name="return-value"></a>Valor de retorno  
 A posição do caractere, (x, y). Para um controle de edição de linha única, a coordenada y é sempre zero.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [EM_POSFROMCHAR](http://msdn.microsoft.com/library/windows/desktop/bb761631) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="redo"></a>CRichEditCtrl::Redo  
 Refaz a próxima ação na fila de restauração do controle.  
  
```  
BOOL Redo();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [EM_REDO](http://msdn.microsoft.com/library/windows/desktop/bb774218) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="replacesel"></a>CRichEditCtrl::ReplaceSel  
 Substitui a seleção atual na `CRichEditCtrl` objeto com o texto especificado.  
  
```  
void ReplaceSel(
    LPCTSTR lpszNewText,  
    BOOL bCanUndo = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszNewText`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que contém o texto de substituição.  
  
 `bCanUndo`  
 Para especificar que essa função pode ser desfeita, defina o valor desse parâmetro para **TRUE**. O valor padrão é **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Para substituir todo o texto nesse `CRichEditCtrl` de objeto, use [CWnd::SetWindowText](../../mfc/reference/cwnd-class.md#setwindowtext).  
  
 Se não houver nenhuma seleção atual, o texto de substituição será inserido no ponto de inserção, ou seja, o local atual do cursor.  
  
 Esta função irá formatar o texto inserido com a formatação de caracteres existente. Ao substituir todo o intervalo de texto (chamando `SetSel`(0, -1) antes de chamar `ReplaceSel`), há um final do caractere de parágrafo que retém a formatação do parágrafo anterior, que em herdada pelo texto recém-inserida.  
  
 Para obter mais informações, consulte [EM_REPLACESEL](http://msdn.microsoft.com/library/windows/desktop/bb761633) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [LineIndex](#lineindex).  
  
##  <a name="requestresize"></a>CRichEditCtrl::RequestResize  
 Isso força o `CRichEditCtrl` objeto enviar **EN_REQUESTRESIZE** mensagens de notificação à sua janela pai.  
  
```  
void RequestResize();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função é útil durante o [CWnd::OnSize](../../mfc/reference/cwnd-class.md#onsize) de processamento para um sem parte inferior `CRichEditCtrl` objeto.  
  
 Para obter mais informações, consulte o [EM_REQUESTRESIZE](http://msdn.microsoft.com/library/windows/desktop/bb774220) mensagem e o **sem parte inferior controles de edição de Rich** seção [sobre controles sofisticados de editar](http://msdn.microsoft.com/library/windows/desktop/bb787873) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="setautourldetect"></a>CRichEditCtrl::SetAutoURLDetect  
 Define o controle rich edit para detectar automaticamente uma URL.  
  
```  
BOOL SetAutoURLDetect(BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bEnable`  
 Especifica se o controle está definido para detectar automaticamente uma URL. Se **TRUE**, ele está habilitado. Se **FALSE**, ela é desabilitada.  
  
### <a name="return-value"></a>Valor de retorno  
 Zero se bem-sucedido, caso contrário, diferente de zero. Por exemplo, a mensagem pode falhar devido à memória insuficiente.  
  
### <a name="remarks"></a>Comentários  
 Se habilitada, o controle rich edit examinará o texto para determinar se ele corresponde a um formato de URL padrão. Para obter uma lista desses formatos de URL, consulte [EM_AUTOURLDETECT](http://msdn.microsoft.com/library/windows/desktop/bb787991) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
> [!NOTE]
>  Não defina `SetAutoURLDetect` para **TRUE** se usa o controle de edição de **CFE_LINK** efeito de texto diferente de URLs. `SetAutoURLDetect`permite que o efeito de URLs e desativa para todos os outros textos. Consulte [EN_LINK](http://msdn.microsoft.com/library/windows/desktop/bb787970) para obter mais informações sobre o **CFE_LINK** efeito.  
  
##  <a name="setbackgroundcolor"></a>CRichEditCtrl::SetBackgroundColor  
 Define a cor de plano de fundo para este `CRichEditCtrl` objeto.  
  
```  
COLORREF SetBackgroundColor(
    BOOL bSysColor,  
    COLORREF cr);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bSysColor`  
 Indica se a cor de plano de fundo deve ser definida como o valor do sistema. Se esse valor for **TRUE**, `cr` será ignorado.  
  
 `cr`  
 A cor de fundo solicitada. Usado somente se `bSysColor` é **FALSE**.  
  
### <a name="return-value"></a>Valor de retorno  
 A cor de plano de fundo anterior desta `CRichEditCtrl` objeto.  
  
### <a name="remarks"></a>Comentários  
 A cor de plano de fundo pode ser definida como o valor do sistema ou um especificado [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor.  
  
 Para obter mais informações, consulte [EM_SETBKGNDCOLOR](http://msdn.microsoft.com/library/windows/desktop/bb774228) mensagem e [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl&#24;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_24.cpp)]  
  
##  <a name="setdefaultcharformat"></a>CRichEditCtrl::SetDefaultCharFormat  
 Define o caractere de formatação atributos para um novo texto nesta `CRichEditCtrl` objeto.  
  
```  
BOOL SetDefaultCharFormat(CHARFORMAT& cf);  
BOOL SetDefaultCharFormat(CHARFORMAT2& cf);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cf`  
 Na primeira versão, um ponteiro para um [CHARFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb787881) estrutura que contém o caractere padrão novos atributos de formatação.  
  
 Na segunda versão, um ponteiro para um [CHARFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787883) estrutura, que é uma extensão de Rich Editar 2.0 para o **CHARFORMAT** estrutura, que contém o caractere padrão de atributos de formatação.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Somente os atributos especificados pelo **dwMask** membro do `cf` alterado por essa função.  
  
 Para obter mais informações, consulte o [EM_SETCHARFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb774230) mensagem e o **CHARFORMAT** e **CHARFORMAT2** estruturas no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[25 NVC_MFC_CRichEditCtrl](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_25.cpp)]  
  
##  <a name="seteventmask"></a>CRichEditCtrl::SetEventMask  
 Define a máscara de evento para isso `CRichEditCtrl` objeto.  
  
```  
DWORD SetEventMask(DWORD dwEventMask);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwEventMask*  
 A nova máscara de eventos para este `CRichEditCtrl` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 A máscara de evento anterior.  
  
### <a name="remarks"></a>Comentários  
 A máscara de evento especifica quais mensagens de notificação de `CRichEditCtrl` objeto envia à sua janela pai.  
  
 Para obter mais informações, consulte [EM_SETEVENTMASK](http://msdn.microsoft.com/library/windows/desktop/bb774238) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl&#26;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_26.cpp)]  
  
##  <a name="setmodify"></a>CRichEditCtrl::SetModify  
 Define ou limpa o sinalizador modificado para um controle de edição.  
  
```  
void SetModify(BOOL bModified = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bModified`  
 Um valor de **TRUE** indica que o texto foi modificado e um valor de **FALSE** indica é inalterado. Por padrão, o sinalizador modificado é definido.  
  
### <a name="remarks"></a>Comentários  
 O sinalizador modificado indica se o texto dentro do controle de edição foi modificado. Ela é definida automaticamente sempre que o usuário altera o texto. Seu valor pode ser recuperado com o [GetModify](#getmodify) função de membro.  
  
 Para obter mais informações, consulte [EM_SETMODIFY](http://msdn.microsoft.com/library/windows/desktop/bb761651) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [GetModify](#getmodify).  
  
##  <a name="setolecallback"></a>CRichEditCtrl::SetOLECallback  
 Fornecerá esse `CRichEditCtrl` objeto um **IRichEditOleCallback** objeto para acessar informações e recursos relacionados ao OLE.  
  
```  
BOOL SetOLECallback(IRichEditOleCallback* pCallback);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCallback`  
 Ponteiro para uma [IRichEditOleCallback](http://msdn.microsoft.com/library/windows/desktop/bb774308) objeto desse `CRichEditCtrl` objeto usará para obter informações e recursos relacionados ao OLE.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Isso `CRichEditCtrl` objeto chamará [AddRef](http://msdn.microsoft.com/library/windows/desktop/ms691379) para incrementar a contagem de uso para o objeto COM especificado por `pCallback`.  
  
 Para obter mais informações, consulte [EM_SETOLECALLBACK](http://msdn.microsoft.com/library/windows/desktop/bb774252) mensagem e [IRichEditOleCallback](http://msdn.microsoft.com/library/windows/desktop/bb774308) interface de [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="setoptions"></a>CRichEditCtrl::SetOptions  
 Define as opções para isso `CRichEditCtrl` objeto.  
  
```  
void SetOptions(
    WORD wOp,  
    DWORD dwFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
 *wOp*  
 Indica o tipo de operação. Um dos seguintes valores:  
  
- `ECOOP_SET`Defina as opções para aqueles especificados pelo `dwFlags`.  
  
- `ECOOP_OR`Combinar as opções atuais com os especificados por `dwFlags`.  
  
- `ECOOP_AND`Manter somente as opções atuais que também são especificadas pelo `dwFlags`.  
  
- `ECOOP_XOR`Manter somente as opções atuais são *não* especificado por `dwFlags`.  
  
 `dwFlags`  
 Opções de edição avançada. Os valores do sinalizador são listados na seção comentários.  
  
### <a name="remarks"></a>Comentários  
 As opções podem ser uma combinação dos seguintes valores:  
  
- `ECO_AUTOWORDSELECTION`Seleção automática de palavras em clique duas vezes.  
  
- `ECO_AUTOVSCROLL`Rola automaticamente o texto à direita por 10 caracteres quando o usuário digita um caractere no final da linha. Quando o usuário pressiona a tecla ENTER, o controle rola todo texto de volta à posição zero.  
  
- `ECO_AUTOHSCROLL`Rola automaticamente o texto para cima uma página quando o usuário pressiona a tecla ENTER na última linha.  
  
- `ECO_NOHIDESEL`Nega o comportamento padrão para um controle de edição. O comportamento padrão oculta a seleção quando o controle perde o foco de entrada e mostra a seleção quando o controle recebe o foco de entrada. Se você especificar `ECO_NOHIDESEL`, o texto selecionado é invertido, mesmo se o controle não tem o foco.  
  
- `ECO_READONLY`Impede que o usuário digitar ou editar texto no controle de edição.  
  
- `ECO_WANTRETURN`Especifica que um retorno de carro inserido quando o usuário pressiona a tecla ENTER ao inserir texto em um controle de edição avançada de várias linhas em uma caixa de diálogo. Se você não especificar esse estilo, pressionando a tecla ENTER envia um comando para a janela pai do controle de edição avançados, que imita o botão da janela pai padrão (por exemplo, o botão Okey em uma caixa de diálogo). Este estilo não tem nenhum efeito em uma única linha controle de edição.  
  
- `ECO_SAVESEL`Preserva a seleção quando o controle perde o foco. Por padrão, todo o conteúdo do controle é selecionado quando ele recupere o foco.  
  
- `ECO_VERTICAL`Desenha o texto e objetos em uma direção vertical. Disponível para somente para idiomas asiáticos.  
  
 Para obter mais informações, consulte [EM_SETOPTIONS](http://msdn.microsoft.com/library/windows/desktop/bb774254) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl&#27;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_27.cpp)]  
  
##  <a name="setparaformat"></a>CRichEditCtrl::SetParaFormat  
 Define a formatação de atributos para a seleção atual no parágrafo `CRichEditCtrl` objeto.  
  
```  
BOOL SetParaFormat(PARAFORMAT& pf);  
BOOL SetParaFormat(PARAFORMAT2& pf);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pf`  
 Na primeira versão, um ponteiro para um [PARAFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb787940) estrutura que contém o novo padrão de atributos de formatação de parágrafo.  
  
 Na segunda versão, um ponteiro para um [PARAFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787942) estrutura, que é uma extensão de Rich Editar 2.0 para o **PARAFORMAT** estrutura, que contém o caractere padrão de atributos de formatação.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Somente os atributos especificados pelo **dwMask** membro do `pf` alterado por essa função.  
  
 Para obter mais informações, consulte o [EM_SETPARAFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb774276) mensagem e o **PARAFORMAT** e **PARAFORMAT2** estruturas no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl&#28;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_28.cpp)]  
  
##  <a name="setpunctuation"></a>CRichEditCtrl::SetPunctuation  
 Define a pontuação em um controle rich edit.  
  
```  
BOOL SetPunctuation(
    UINT fType,  
    PUNCTUATION* lpPunc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `fType`  
 O sinalizador de pontuação. Para obter uma lista dos valores possíveis, consulte o `fType` parâmetro [EM_SETPUNCTUATION](http://msdn.microsoft.com/library/windows/desktop/bb774278) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `lpPunc`  
 Um ponteiro para um [PONTUAÇÃO](http://msdn.microsoft.com/library/windows/desktop/bb787944) estrutura, conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se tiver êxito, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro está disponível para apenas as versões de idioma asiático do sistema operacional.  
  
##  <a name="setreadonly"></a>CRichEditCtrl::SetReadOnly  
 Alterações de `ECO_READONLY` opção desta `CRichEditCtrl` objeto.  
  
```  
BOOL SetReadOnly(BOOL bReadOnly = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bReadOnly`  
 Indica se este `CRichEditCtrl` objeto deve ser somente leitura.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para obter uma breve descrição dessa opção, consulte [SetOptions](#setoptions). Você pode usar essa função para definir todas as opções para este `CRichEditCtrl` objeto.  
  
 Para obter mais informações, consulte [EM_SETREADONLY](http://msdn.microsoft.com/library/windows/desktop/bb761655) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[29 NVC_MFC_CRichEditCtrl](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_29.cpp)]  
  
##  <a name="setrect"></a>CRichEditCtrl::SetRect  
 Define o retângulo de formatação para isso `CRichEditCtrl` objeto.  
  
```  
void SetRect(LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 [CRect](../../atl-mfc-shared/reference/crect-class.md) ou ponteiro para um [RECT](../../mfc/reference/rect-structure1.md) que indica os novos limites para o retângulo de formatação.  
  
### <a name="remarks"></a>Comentários  
 O retângulo de formatação é o limitação retângulo do texto. O retângulo limitação é independente do tamanho da janela de controle rich edit. Quando isso `CRichEditCtrl` objeto é criado, o retângulo formatação é do mesmo tamanho que a área do cliente da janela. Use `SetRect` para transformar o retângulo formatação maior ou menor que a janela de edição avançada.  
  
 Para obter mais informações, consulte [EM_SETRECT](http://msdn.microsoft.com/library/windows/desktop/bb761657) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[30 NVC_MFC_CRichEditCtrl](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_30.cpp)]  
  
##  <a name="setsel"></a>CRichEditCtrl::SetSel  
 Define a seleção dentro dessa `CRichEditCtrl` objeto.  
  
```  
void SetSel(
    long nStartChar,  
    long nEndChar);  
  
void SetSel(CHARRANGE& cr);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nStartChar`  
 Índice baseado em zero do primeiro caractere da seleção.  
  
 `nEndChar`  
 Índice baseado em zero do último caractere da seleção.  
  
 `cr`  
 [CHARRANGE](http://msdn.microsoft.com/library/windows/desktop/bb787885) estrutura que contém os limites da seleção atual.  
  
### <a name="remarks"></a>Comentários  
 As duas formas dessa função oferecem formas alternativas de definir os limites da seleção. Execute as breves descrições destas formas:  
  
- **SetSel (** `cr` **)** este formulário usa o **CHARRANGE** estrutura com seus **cpMin** e **cpMax** membros para definir os limites.  
  
- **SetSel (** `nStartChar` **,** `nEndChar` **)** este formulário usar os parâmetros `nStartChar` e `nEndChar` para definir os limites.  
  
 O cursor é colocado no final da seleção indicado pelo maior do início ( **cpMin** ou `nStartChar`) e de término ( **cpMax** ou `nEndChar`) índices. Essa função rola o conteúdo do `CRichEditCtrl` para que o cursor fique visível.  
  
 Para selecionar todo o texto nesse `CRichEditCtrl` de objeto, chame `SetSel` com um índice inicial de 0 e um índice de final de – 1.  
  
 Para obter mais informações, consulte [EM_EXSETSEL](http://msdn.microsoft.com/library/windows/desktop/bb788007) mensagem e [CHARRANGE](http://msdn.microsoft.com/library/windows/desktop/bb787885) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [GetSel](#getsel).  
  
##  <a name="setselectioncharformat"></a>CRichEditCtrl::SetSelectionCharFormat  
 Define o caractere de atributos de texto da seleção atual na formatação `CRichEditCtrl` objeto.  
  
```  
BOOL SetSelectionCharFormat(CHARFORMAT& cf);  
BOOL SetSelectionCharFormat(CHARFORMAT2& cf);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cf`  
 Na primeira versão, um ponteiro para um [CHARFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb787881) atributos de estrutura que contém a nova formatação de caractere da seleção atual.  
  
 Na segunda versão, um ponteiro para um [CHARFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787883) estrutura, que é uma extensão de Rich Editar 2.0 para o **CHARFORMAT** estrutura, que contém o caractere de nova formatação atributos para a seleção atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Somente os atributos especificados pelo **dwMask** membro do `cf` alterado por essa função.  
  
 Para obter mais informações, consulte o [EM_SETCHARFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb774230) e **CHARFORMAT** e **CHARFORMAT2** estruturas no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl&#31;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_31.cpp)]  
  
##  <a name="settargetdevice"></a>CRichEditCtrl::SetTargetDevice  
 Define a largura de linha e o dispositivo de destino usada nas WYSIWYG (o que você vê é o que você obtém) formatação neste `CRichEditCtrl` objeto.  
  
```  
BOOL SetTargetDevice(
    HDC hDC,  
    long lLineWidth);

 
BOOL SetTargetDevice(
    CDC& dc,  
    long lLineWidth);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hDC`  
 Identificador para o contexto de dispositivo para o novo dispositivo de destino.  
  
 *lLineWidth*  
 Largura da linha a ser usado para formatação.  
  
 `dc`  
 [CDC](../../mfc/reference/cdc-class.md) para o novo dispositivo de destino.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se essa função for bem-sucedida, o controle rich edit possui o dispositivo contexto passado como um parâmetro. Nesse caso, a função de chamada não deve destruir o contexto do dispositivo.  
  
 Para obter mais informações, consulte [EM_SETTARGETDEVICE](http://msdn.microsoft.com/library/windows/desktop/bb774282) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[32 NVC_MFC_CRichEditCtrl](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_32.cpp)]  
  
##  <a name="settextmode"></a>CRichEditCtrl::SetTextMode  
 Define o nível de modo ou desfazer e refazer do texto de um controle rich edit.  
  
```  
BOOL SetTextMode(UINT fMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 *fMode*  
 Especifica as novas configurações para modo e desfazer nível parâmetros de texto do controle. Para obter uma lista dos valores possíveis, consulte o parâmetro modo [EM_SETTEXTMODE](http://msdn.microsoft.com/library/windows/desktop/bb774286) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Zero se bem-sucedido, caso contrário, diferente de zero.  
  
### <a name="remarks"></a>Comentários  
 Para obter uma descrição dos modos de texto, consulte **EM_SETTEXTMODE** no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Essa função de membro falhará se o controle contiver texto. Para verificar se o controle estiver vazio, envie um [WM_SETTEXT](http://msdn.microsoft.com/library/windows/desktop/ms632644) mensagem com uma cadeia de caracteres vazia.  
  
##  <a name="setundolimit"></a>CRichEditCtrl::SetUndoLimit  
 Define o número máximo de ações que podem ser armazenadas na fila de desfazer.  
  
```  
UINT SetUndoLimit(UINT nLimit);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nLimit*  
 Especifica o número máximo de ações que podem ser armazenadas na fila de desfazer. Definido como zero para desabilitar desfazer.  
  
### <a name="return-value"></a>Valor de retorno  
 O novo número máximo de ações de desfazer para o sofisticado de controle de edição.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, o número máximo de ações na fila de desfazer é 100. Se você aumentar esse número, deve haver memória suficiente para acomodar o novo número. Para obter melhor desempenho, defina o limite para o menor valor possível.  
  
##  <a name="setwordcharformat"></a>CRichEditCtrl::SetWordCharFormat  
 Define o caractere de formatação atributos para a palavra atualmente selecionada neste `CRichEditCtrl` objeto.  
  
```  
BOOL SetWordCharFormat(CHARFORMAT& cf);  
BOOL SetWordCharFormat(CHARFORMAT2& cf);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cf`  
 Na primeira versão, um ponteiro para um [CHARFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb787881) atributos de estrutura que contém a nova formatação de caractere da palavra selecionada no momento.  
  
 Na segunda versão, um ponteiro para um [CHARFORMAT2](http://msdn.microsoft.com/library/windows/desktop/bb787883) estrutura, que é uma extensão de Rich Editar 2.0 para o **CHARFORMAT** estrutura, que contém o caractere de nova formatação atributos para a palavra atualmente selecionada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Somente os atributos especificados pelo **dwMask** membro do `cf` alterado por essa função.  
  
 Para obter mais informações, consulte o [EM_SETCHARFORMAT](http://msdn.microsoft.com/library/windows/desktop/bb774230) mensagem e o **CHARFORMAT** e **CHARFORMAT2** estruturas no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[33 NVC_MFC_CRichEditCtrl](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_33.cpp)]  
  
##  <a name="setwordwrapmode"></a>CRichEditCtrl::SetWordWrapMode  
 Define as opções de quebra de palavras e quebra de palavras para o sofisticado de controle de edição.  
  
```  
UINT SetWordWrapMode(UINT uFlags) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `uFlags`  
 As opções definidas para a quebra de palavras e quebra de palavras. Para obter uma lista de opções possíveis, consulte [EM_SETWORDWRAPMODE](http://msdn.microsoft.com/library/windows/desktop/bb774294) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 A quebra de palavras e quebra atual opções.  
  
### <a name="remarks"></a>Comentários  
 Esta mensagem está disponível apenas nas versões de idioma asiático do sistema operacional.  
  
##  <a name="stopgrouptyping"></a>CRichEditCtrl::StopGroupTyping  
 Interrompe o controle de coleta adicional de digitação ações para a ação de desfazer atual.  
  
```  
void StopGroupTyping();
```  
  
### <a name="remarks"></a>Comentários  
 O controle armazena a próxima ação de digitação, se houver, em uma nova ação na fila de desfazer.  
  
 Para obter mais informações, consulte [EM_STOPGROUPTYPING](http://msdn.microsoft.com/library/windows/desktop/bb774300) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="streamin"></a>CRichEditCtrl::StreamIn  
 Substitui o texto neste `CRichEditCtrl` objeto com o texto do fluxo de entrada especificado.  
  
```  
long StreamIn(
    int nFormat,  
    EDITSTREAM& es);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nFormat`  
 Sinalizadores que especificam os formatos de dados de entrada. Consulte a seção Comentários para obter mais informações.  
  
 `es`  
 [EDITSTREAM](http://msdn.microsoft.com/library/windows/desktop/bb787891) estrutura especificando o fluxo de entrada. Consulte a seção Comentários para obter mais informações.  
  
### <a name="return-value"></a>Valor de retorno  
 Número de caracteres lidos do fluxo de entrada.  
  
### <a name="remarks"></a>Comentários  
 O valor de `nFormat` deve ser um dos seguintes:  
  
- `SF_TEXT`Indica o texto de leitura somente.  
  
- `SF_RTF`Indica a leitura de texto e formatação.  
  
 Qualquer um desses valores pode ser combinado com `SFF_SELECTION`. Se `SFF_SELECTION` for especificado, `StreamIn` substitui a seleção atual pelo conteúdo do fluxo de entrada. Se não for especificado, `StreamIn` substitui todo o conteúdo deste `CRichEditCtrl` objeto.  
  
 No **EDITSTREAM** parâmetro `es`, especifique uma função de retorno de chamada que preenche um buffer com texto. Essa função de retorno de chamada é chamada repetidamente, até que o fluxo de entrada seja esgotado.  
  
 Para obter mais informações, consulte [EM_STREAMIN](http://msdn.microsoft.com/library/windows/desktop/bb774302) mensagem e [EDITSTREAM](http://msdn.microsoft.com/library/windows/desktop/bb787891) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl&#34;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_34.cpp)]  
  
 [!code-cpp[NVC_MFC_CRichEditCtrl&#35;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_35.cpp)]  
  
##  <a name="streamout"></a>CRichEditCtrl::StreamOut  
 Grava o conteúdo desse `CRichEditCtrl` objeto ao fluxo de saída especificado.  
  
```  
long StreamOut(
    int nFormat,  
    EDITSTREAM& es);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nFormat`  
 Sinalizadores que especificam os formatos de dados de saída. Consulte a seção Comentários para obter mais informações.  
  
 `es`  
 [EDITSTREAM](http://msdn.microsoft.com/library/windows/desktop/bb787891) estrutura especificando o fluxo de saída. Consulte a seção Comentários para obter mais informações.  
  
### <a name="return-value"></a>Valor de retorno  
 Número de caracteres gravados no fluxo de saída.  
  
### <a name="remarks"></a>Comentários  
 O valor de `nFormat` deve ser um dos seguintes:  
  
- `SF_TEXT`Indica somente o texto de gravação.  
  
- `SF_RTF`Indica a escrita de texto e formatação.  
  
- `SF_RTFNOOBJS`Indica a escrever texto e formatação, substituindo itens OLE com espaços.  
  
- `SF_TEXTIZED`Indica a escrever texto e formatação, com representações textuais de itens OLE.  
  
 Qualquer um desses valores pode ser combinado com `SFF_SELECTION`. Se `SFF_SELECTION` for especificado, `StreamOut` gravará a seleção atual no fluxo de saída. Se não for especificado, `StreamOut` grava todo o conteúdo deste `CRichEditCtrl` objeto.  
  
 No **EDITSTREAM** parâmetro `es`, especifique uma função de retorno de chamada que ocupa um buffer com texto. Essa função de retorno de chamada é chamada repetidamente, até que o fluxo de saída seja esgotado.  
  
 Para obter mais informações, consulte [EM_STREAMOUT](http://msdn.microsoft.com/library/windows/desktop/bb774304) mensagem e [EDITSTREAM](http://msdn.microsoft.com/library/windows/desktop/bb787891) estrutura no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CRichEditCtrl&#36;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_36.cpp)]  
  
 [!code-cpp[NVC_MFC_CRichEditCtrl&#37;](../../mfc/reference/codesnippet/cpp/cricheditctrl-class_37.cpp)]  
  
##  <a name="undo"></a>CRichEditCtrl::Undo  
 Desfaz a última operação no controle de edição avançada.  
  
```  
BOOL Undo();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a operação de desfazer for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Uma operação de desfazer também pode ser desfeita. Por exemplo, você pode restaurar o texto excluído com a primeira chamada para **desfazer**. Como não há nenhuma operação de edição intermediários, você pode remover o texto novamente com uma segunda chamada para **desfazer**.  
  
 Para obter mais informações, consulte [EM_UNDO](http://msdn.microsoft.com/library/windows/desktop/bb761670) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CanUndo](#canundo).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC WORDPAD](../../visual-cpp-samples.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CEdit](../../mfc/reference/cedit-class.md)   
 [Classe CRichEditView](../../mfc/reference/cricheditview-class.md)

