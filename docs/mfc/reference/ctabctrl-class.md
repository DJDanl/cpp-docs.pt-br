---
title: Classe CTabCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CTabCtrl
- AFXCMN/CTabCtrl
- AFXCMN/CTabCtrl::CTabCtrl
- AFXCMN/CTabCtrl::AdjustRect
- AFXCMN/CTabCtrl::Create
- AFXCMN/CTabCtrl::CreateEx
- AFXCMN/CTabCtrl::DeleteAllItems
- AFXCMN/CTabCtrl::DeleteItem
- AFXCMN/CTabCtrl::DeselectAll
- AFXCMN/CTabCtrl::DrawItem
- AFXCMN/CTabCtrl::GetCurFocus
- AFXCMN/CTabCtrl::GetCurSel
- AFXCMN/CTabCtrl::GetExtendedStyle
- AFXCMN/CTabCtrl::GetImageList
- AFXCMN/CTabCtrl::GetItem
- AFXCMN/CTabCtrl::GetItemCount
- AFXCMN/CTabCtrl::GetItemRect
- AFXCMN/CTabCtrl::GetItemState
- AFXCMN/CTabCtrl::GetRowCount
- AFXCMN/CTabCtrl::GetToolTips
- AFXCMN/CTabCtrl::HighlightItem
- AFXCMN/CTabCtrl::HitTest
- AFXCMN/CTabCtrl::InsertItem
- AFXCMN/CTabCtrl::RemoveImage
- AFXCMN/CTabCtrl::SetCurFocus
- AFXCMN/CTabCtrl::SetCurSel
- AFXCMN/CTabCtrl::SetExtendedStyle
- AFXCMN/CTabCtrl::SetImageList
- AFXCMN/CTabCtrl::SetItem
- AFXCMN/CTabCtrl::SetItemExtra
- AFXCMN/CTabCtrl::SetItemSize
- AFXCMN/CTabCtrl::SetItemState
- AFXCMN/CTabCtrl::SetMinTabWidth
- AFXCMN/CTabCtrl::SetPadding
- AFXCMN/CTabCtrl::SetToolTips
dev_langs:
- C++
helpviewer_keywords:
- CTabCtrl [MFC], CTabCtrl
- CTabCtrl [MFC], AdjustRect
- CTabCtrl [MFC], Create
- CTabCtrl [MFC], CreateEx
- CTabCtrl [MFC], DeleteAllItems
- CTabCtrl [MFC], DeleteItem
- CTabCtrl [MFC], DeselectAll
- CTabCtrl [MFC], DrawItem
- CTabCtrl [MFC], GetCurFocus
- CTabCtrl [MFC], GetCurSel
- CTabCtrl [MFC], GetExtendedStyle
- CTabCtrl [MFC], GetImageList
- CTabCtrl [MFC], GetItem
- CTabCtrl [MFC], GetItemCount
- CTabCtrl [MFC], GetItemRect
- CTabCtrl [MFC], GetItemState
- CTabCtrl [MFC], GetRowCount
- CTabCtrl [MFC], GetToolTips
- CTabCtrl [MFC], HighlightItem
- CTabCtrl [MFC], HitTest
- CTabCtrl [MFC], InsertItem
- CTabCtrl [MFC], RemoveImage
- CTabCtrl [MFC], SetCurFocus
- CTabCtrl [MFC], SetCurSel
- CTabCtrl [MFC], SetExtendedStyle
- CTabCtrl [MFC], SetImageList
- CTabCtrl [MFC], SetItem
- CTabCtrl [MFC], SetItemExtra
- CTabCtrl [MFC], SetItemSize
- CTabCtrl [MFC], SetItemState
- CTabCtrl [MFC], SetMinTabWidth
- CTabCtrl [MFC], SetPadding
- CTabCtrl [MFC], SetToolTips
ms.assetid: 42e4aff6-46ae-4b2c-beaa-d1dce8d82138
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ac6e8215cc46fd190703981869a065df8d46b18d
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43690465"
---
# <a name="ctabctrl-class"></a>Classe CTabCtrl
Fornece a funcionalidade de controle de guia comum do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CTabCtrl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CTabCtrl::CTabCtrl](#ctabctrl)|Constrói um objeto `CTabCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CTabCtrl::AdjustRect](#adjustrect)|Calcula a área de exibição de um controle guia, dada um retângulo de janela ou calcula o retângulo de janela que corresponde a uma área de exibição em questão.|  
|[CTabCtrl::Create](#create)|Cria um controle guia e o anexa a uma instância de um `CTabCtrl` objeto.|  
|[CTabCtrl::CreateEx](#createex)|Cria um controle guia com os estilos estendidos do Windows especificados e anexa-o a uma instância de um `CTabCtrl` objeto.|  
|[CTabCtrl::DeleteAllItems](#deleteallitems)|Remove todos os itens de um controle guia.|  
|[CTabCtrl::DeleteItem](#deleteitem)|Remove um item de um controle guia.|  
|[CTabCtrl::DeselectAll](#deselectall)|Redefine os itens em um controle guia, limpando todos os que foram pressionadas.|  
|[CTabCtrl::DrawItem](#drawitem)|Desenha um item especificado de um controle guia.|  
|[CTabCtrl::GetCurFocus](#getcurfocus)|Recupera a guia com o foco atual de um controle guia.|  
|[CTabCtrl::GetCurSel](#getcursel)|Determina a guia selecionada no momento em um controle guia.|  
|[CTabCtrl::GetExtendedStyle](#getextendedstyle)|Recupera os estilos estendidos que estão atualmente em uso para o controle de guia.|  
|[CTabCtrl::GetImageList](#getimagelist)|Recupera a lista de imagens associada com um controle guia.|  
|[CTabCtrl::GetItem](#getitem)|Recupera informações sobre uma guia em um controle guia.|  
|[CTabCtrl::GetItemCount](#getitemcount)|Recupera o número de guias no controle guia.|  
|[CTabCtrl::GetItemRect](#getitemrect)|Recupera o retângulo delimitador para uma guia em um controle guia.|  
|[CTabCtrl::GetItemState](#getitemstate)|Recupera o estado do item de controle de guia indicado.|  
|[CTabCtrl::GetRowCount](#getrowcount)|Recupera o número atual de linhas de guias em um controle guia.|  
|[CTabCtrl::GetToolTips](#gettooltips)|Recupera o identificador de controle de dica de ferramenta associado com um controle guia.|  
|[CTabCtrl::HighlightItem](#highlightitem)|Define o estado de realce de um item de guia.|  
|[CTabCtrl::HitTest](#hittest)|Determina qual guia, se houver, está em uma posição da tela especificadas.|  
|[CTabCtrl::InsertItem](#insertitem)|Insere uma nova guia em um controle guia.|  
|[CTabCtrl::RemoveImage](#removeimage)|Remove uma imagem da lista de imagens de um controle guia.|  
|[CTabCtrl::SetCurFocus](#setcurfocus)|Define o foco para uma guia especificada em um controle guia.|  
|[CTabCtrl::SetCurSel](#setcursel)|Seleciona uma guia em um controle guia.|  
|[CTabCtrl::SetExtendedStyle](#setextendedstyle)|Define os estilos estendidos para um controle guia.|  
|[CTabCtrl::SetImageList](#setimagelist)|Atribui uma lista de imagens a um controle guia.|  
|[CTabCtrl::SetItem](#setitem)|Define alguns ou todos os atributos de uma guia.|  
|[CTabCtrl::SetItemExtra](#setitemextra)|Define o número de bytes por guia reservado para os dados definidos pelo aplicativo em um controle guia.|  
|[CTabCtrl::SetItemSize](#setitemsize)|Define a largura e altura de um item.|  
|[CTabCtrl::SetItemState](#setitemstate)|Define o estado do item de controle de guia indicado.|  
|[CTabCtrl::SetMinTabWidth](#setmintabwidth)|Define a largura mínima de itens em um controle guia.|  
|[CTabCtrl::SetPadding](#setpadding)|Define a quantidade de espaço (preenchimento) em torno do ícone de cada guia e o rótulo em um controle guia.|  
|[CTabCtrl::SetToolTips](#settooltips)|Atribui um controle de dica de ferramenta para um controle guia.|  
  
## <a name="remarks"></a>Comentários  
 Um "controle de guia" é análogo aos divisores de um bloco de anotações ou os rótulos em um arquivo de gabinete. Ao usar um controle guia, um aplicativo pode definir várias páginas para a mesma área de uma janela ou caixa de diálogo. Cada página consiste em um conjunto de informações ou um grupo de controles que o aplicativo exibe quando o usuário seleciona a guia correspondente. Um tipo especial de controle de guia exibe as guias que se parecem com botões. Clicar em um botão deve executar imediatamente um comando em vez de exibir uma página.  
  
 Esse controle (e, portanto, o `CTabCtrl` classe) está disponível somente para programas executados na versão do Windows 95/98 e Windows NT 3.51 e posterior.  
  
 Para obter mais informações sobre como usar `CTabCtrl`, consulte [controles](../../mfc/controls-mfc.md) e [usando CTabCtrl](../../mfc/using-ctabctrl.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CTabCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn. h  
  
##  <a name="adjustrect"></a>  CTabCtrl::AdjustRect  
 Calcula a área de exibição de um controle guia, dada um retângulo de janela ou calcula o retângulo de janela que corresponde a uma área de exibição em questão.  
  
```  
void AdjustRect(BOOL bLarger,   LPRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bLarger*  
 Indica qual operação executar. Se esse parâmetro for TRUE, o *lpRect* Especifica um retângulo de exibição e recebe o retângulo de janela correspondente. Se esse parâmetro for FALSE, o *lpRect* Especifica um retângulo de janela e recebe o retângulo de exibição correspondente.  
  
 *lpRect*  
 Ponteiro para um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que especifica o retângulo determinado e recebe o retângulo calculado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTabCtrl#1](../../mfc/reference/codesnippet/cpp/ctabctrl-class_1.cpp)]  
  
##  <a name="create"></a>  CTabCtrl::Create  
 Cria um controle guia e o anexa a uma instância de um `CTabCtrl` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwStyle*  
 Especifica o estilo do controle guia. Aplicar qualquer combinação de [estilos de controle de guia](/windows/desktop/Controls/tab-control-styles), descrito no SDK do Windows. Ver **comentários** para obter uma lista de estilos de janela que você também pode aplicar ao controle.  
  
 *Rect*  
 Especifica o tamanho e a posição do controle guia. Ela pode ser um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou uma [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura.  
  
 *pParentWnd*  
 Especifica a janela do pai do controle de guia, geralmente um `CDialog`. Ele não deve ser NULL.  
  
 *nID*  
 Especifica a ID. do controle guia  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a inicialização do objeto foi bem-sucedida; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Você constrói um `CTabCtrl` objeto em duas etapas. Primeiro, chame o construtor e, em seguida, chame `Create`, que cria o controle de guia e anexa-o para o `CTabCtrl` objeto.  
  
 Além dos estilos de controle de guia, você pode aplicar os seguintes estilos de janela a um controle guia:  
  
- WS_CHILD cria uma janela filho que representa o controle de guia. Não pode ser usado com o estilo WS_POPUP.  
  
- WS_VISIBLE cria um controle guia que está visível inicialmente.  
  
- WS_DISABLED cria uma janela que é inicialmente desabilitada.  
  
- WS_GROUP Especifica o primeiro controle de um grupo de controles em que o usuário pode mover de um controle para a próxima com as teclas de direção. Todos os controles definidos com o estilo WS_GROUP após o primeiro controle pertencem ao mesmo grupo. O próximo controle com o estilo WS_GROUP termina o grupo de estilo e inicia o próximo grupo (ou seja, um grupo termina onde o próximo começa).  
  
- WS_TABSTOP Especifica um número de controles por meio do qual o usuário pode mover usando a tecla TAB. A tecla TAB move o usuário para o próximo controle especificado pelo estilo de WS_TABSTOP.  
  
 Para criar um controle guia com estilos de janela estendidos, chame [CTabCtrl::CreateEx](#createex) em vez de `Create`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTabCtrl#2](../../mfc/reference/codesnippet/cpp/ctabctrl-class_2.cpp)]  
  
##  <a name="createex"></a>  CTabCtrl::CreateEx  
 Cria um controle (uma janela filho) e o associa a `CTabCtrl` objeto.  
  
```  
virtual BOOL CreateEx(
    DWORD dwExStyle,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwExStyle*  
 Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista dos estilos estendidos do Windows, consulte o *dwExStyle* parâmetro para [CreateWindowEx](/windows/desktop/api/winuser/nf-winuser-createwindowexa) no SDK do Windows.  
  
 *dwStyle*  
 Especifica o estilo do controle guia. Aplicar qualquer combinação de [estilos de controle de guia](/windows/desktop/Controls/tab-control-styles), descrito no SDK do Windows. Ver **Remarks** na [criar](#create) para obter uma lista de estilos de janela que você também pode aplicar ao controle.  
  
 *Rect*  
 Uma referência a um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que descreve o tamanho e posição da janela a ser criado, em coordenadas do cliente do *pParentWnd*.  
  
 *pParentWnd*  
 Um ponteiro para a janela que é o pai do controle.  
  
 *nID*  
 ID da janela filho. do controle  
  
### <a name="return-value"></a>Valor de retorno  
 Caso contrário, 0 diferente de zero se for bem-sucedido.  
  
### <a name="remarks"></a>Comentários  
 Use `CreateEx` em vez de [Create](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.  
  
 `CreateEx` cria o controle com os estilos estendidos do Windows especificados pela *dwExStyle*. Conjunto de estilos específicos para um controle usando estendidos [SetExtendedStyle](#setextendedstyle). Por exemplo, use `CreateEx` para definir esses estilos como WS_EX_CONTEXTHELP, mas use `SetExtendedStyle` para definir esses estilos como TCS_EX_FLATSEPARATORS. Para obter mais informações, consulte os estilos descritos em [estilos estendidos de controle de guia](/windows/desktop/Controls/tab-control-extended-styles) no SDK do Windows.  
  
##  <a name="ctabctrl"></a>  CTabCtrl::CTabCtrl  
 Constrói um objeto `CTabCtrl`.  
  
```  
CTabCtrl();
```  
  
##  <a name="deleteallitems"></a>  CTabCtrl::DeleteAllItems  
 Remove todos os itens de um controle guia.  
  
```  
BOOL DeleteAllItems();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
##  <a name="deleteitem"></a>  CTabCtrl::DeleteItem  
 Remove o item especificado de um controle guia.  
  
```  
BOOL DeleteItem(int nItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nItem*  
 Valor com base em zero do item a ser excluído.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTabCtrl#3](../../mfc/reference/codesnippet/cpp/ctabctrl-class_3.cpp)]  
  
##  <a name="deselectall"></a>  CTabCtrl::DeselectAll  
 Redefine os itens em um controle guia, limpando todos os que foram pressionadas.  
  
```  
void DeselectAll(BOOL fExcludeFocus);
```  
  
### <a name="parameters"></a>Parâmetros  
 *fExcludeFocus*  
 Sinalizador que especifica o escopo de deselection o item. Se esse parâmetro for definido como FALSE, todos os botões da guia serão redefinidos. Se for definido como TRUE, em seguida, todos os guia itens além daquele selecionado no momento será redefinido.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem Win32, [TCM_DESELECTALL](/windows/desktop/Controls/tcm-deselectall), conforme descrito no SDK do Windows.  
  
##  <a name="drawitem"></a>  CTabCtrl::DrawItem  
 Chamado pelo framework quando um aspecto visual de um alterações de controle de guia de desenho do proprietário.  
  
```  
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpDrawItemStruct*  
 Um ponteiro para um [DRAWITEMSTRUCT](/windows/desktop/api/winuser/ns-winuser-tagdrawitemstruct) estrutura que descreve o item a ser pintado.  
  
### <a name="remarks"></a>Comentários  
 O `itemAction` membro o `DRAWITEMSTRUCT` estrutura define a ação de desenho a ser executada.  
  
 Por padrão, essa função membro não faz nada. Substituir essa função de membro para implementar o desenho de um desenho proprietário `CTabCtrl` objeto.  
  
 O aplicativo deve restaurar todos os objetos de interface (GDI) do dispositivo gráficos selecionados para o contexto de exibição fornecido no *lpDrawItemStruct* antes desse membro função encerra.  
  
##  <a name="getcurfocus"></a>  CTabCtrl::GetCurFocus  
 Recupera o índice da guia com o foco atual.  
  
```  
int GetCurFocus() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero da guia com o foco atual.  
  
##  <a name="getcursel"></a>  CTabCtrl::GetCurSel  
 Recupera a guia selecionada no momento em um controle guia.  
  
```  
int GetCurSel() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Índice baseado em zero da guia selecionada se for bem-sucedido ou - 1 se a guia não estiver selecionada.  
  
##  <a name="getextendedstyle"></a>  CTabCtrl::GetExtendedStyle  
 Recupera os estilos estendidos que estão atualmente em uso para o controle de guia.  
  
```  
DWORD GetExtendedStyle();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Representa os estilos estendidos atualmente em uso para o controle de guia. Esse valor é uma combinação de [estilos estendidos de controle guia](/windows/desktop/Controls/tab-control-extended-styles), conforme descrito no SDK do Windows.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem do Win32 [TCM_GETEXTENDEDSTYLE](/windows/desktop/Controls/tcm-getextendedstyle), conforme descrito no SDK do Windows.  
  
##  <a name="getimagelist"></a>  CTabCtrl::GetImageList  
 Recupera a lista de imagens que está associada com um controle guia.  
  
```  
CImageList* GetImageList() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, um ponteiro para a lista de imagens da guia de controle; Caso contrário, nulo.  
  
##  <a name="getitem"></a>  CTabCtrl::GetItem  
 Recupera informações sobre uma guia em um controle guia.  
  
```  
BOOL GetItem(int nItem,   TCITEM* pTabCtrlItem) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nItem*  
 Índice baseado em zero da guia.  
  
 *pTabCtrlItem*  
 Ponteiro para um [TCITEM](/windows/desktop/api/commctrl/ns-commctrl-tagtcitema) estrutura, usada para especificar as informações a serem recuperadas. Também é usado para receber informações sobre a guia. Essa estrutura é usada com o `InsertItem`, `GetItem`, e `SetItem` funções de membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará TRUE se bem-sucedido; FALSE caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Quando a mensagem é enviada, o `mask` membro especifica quais atributos retornam. Se o `mask` membro Especifica o valor TCIF_TEXT, o `pszText` membro deve conter o endereço do buffer que recebe o texto do item e o `cchTextMax` membro deve especificar o tamanho do buffer.  
  
 `mask`  
 Valor que especifica qual `TCITEM` membros para recuperar ou definir da estrutura. Esse membro pode ser zero ou uma combinação dos seguintes valores:  
  
- TCIF_TEXT o `pszText` membro é válido.  
  
- TCIF_IMAGE o `iImage` membro é válido.  
  
- TCIF_PARAM o `lParam` membro é válido.  
  
- TCIF_RTLREADING o texto de `pszText` é exibido usando a ordem de leitura da direita para a esquerda nos sistemas hebraico ou árabe.  
  
- TCIF_STATE o `dwState` membro é válido.  
  
 `pszText`  
 Ponteiro para uma cadeia de caracteres terminada em nulo que contém o texto da guia se a estrutura contém informações sobre uma guia. Se a estrutura é receber informações, esse membro Especifica o endereço do buffer que recebe o texto da guia.  
  
 `cchTextMax`  
 Tamanho do buffer apontado por `pszText`. Esse membro será ignorado se a estrutura não está recebendo informações.  
  
 `iImage`  
 Indexar o controle de guia lista de imagens, ou - 1 se não houver nenhuma imagem da guia.  
  
 lParam  
 Dados definidos pelo aplicativo associados com a guia. Se houver mais de quatro bytes de dados definido pelo aplicativo por tabulação, um aplicativo deve definir uma estrutura e usá-lo em vez do `TCITEM` estrutura. O primeiro membro da estrutura definida pelo aplicativo deve ser um [TCITEMHEADER](/windows/desktop/api/commctrl/ns-commctrl-tagtcitemheadera)estrutura. O `TCITEMHEADER` estrutura é idêntica de `TCITEM` estrutura, mas sem o `lParam` membro. A diferença entre o tamanho da sua estrutura e o tamanho do `TCITEMHEADER` estrutura deve ser igual ao número de bytes adicionais por guia.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTabCtrl#4](../../mfc/reference/codesnippet/cpp/ctabctrl-class_4.cpp)]  
  
##  <a name="getitemcount"></a>  CTabCtrl::GetItemCount  
 Recupera o número de guias no controle guia.  
  
```  
int GetItemCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Número de itens no controle guia.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPropertySheet::GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).  
  
##  <a name="getitemrect"></a>  CTabCtrl::GetItemRect  
 Recupera o retângulo delimitador para a guia especificada em um controle guia.  
  
```  
BOOL GetItemRect(int nItem,   LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nItem*  
 Índice baseado em zero do item de guia.  
  
 *lpRect*  
 Ponteiro para um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que recebe o retângulo delimitador da guia. Essas coordenadas usam modo de mapeamento do visor atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPropertySheet::GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).  
  
##  <a name="getitemstate"></a>  CTabCtrl::GetItemState  
 Recupera o estado do item de controle de guia identificado pelo *nItem*.  
  
```  
DWORD GetItemState(
    int nItem,  
    DWORD dwMask) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nItem*  
 O número de índice baseado em zero do item para o qual recuperar informações de estado.  
  
 *dwMask*  
 Máscara especificando quais do estado do item de sinalizadores para retornar. Para obter uma lista de valores, consulte o membro de máscara do [TCITEM](/windows/desktop/api/commctrl/ns-commctrl-tagtcitema) estrutura, conforme descrito no SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a um valor DWORD que recebe as informações de estado. pode ser um dos seguintes valores:  
  
|Valor|Descrição|  
|-----------|-----------------|  
|TCIS_BUTTONPRESSED|O item de controle de guia é selecionado.|  
|TCIS_HIGHLIGHTED|O item de controle de guia é realçado, e a guia e texto são desenhados usando a cor de realce atual. Ao usar a cor de realce, esse será uma verdadeira interpolação, não uma cor pontilhada.|  
  
### <a name="remarks"></a>Comentários  
 Estado de um item é especificado pelo `dwState` membro o `TCITEM` estrutura.  
  
##  <a name="getrowcount"></a>  CTabCtrl::GetRowCount  
 Recupera o número atual de linhas em um controle guia.  
  
```  
int GetRowCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de linhas de guias no controle guia.  
  
### <a name="remarks"></a>Comentários  
 Somente os controles de guia que têm o estilo TCS_MULTILINE podem ter várias linhas de guias.  
  
##  <a name="gettooltips"></a>  CTabCtrl::GetToolTips  
 Recupera o identificador de controle de dica de ferramenta associado com um controle guia.  
  
```  
CToolTipCtrl* GetToolTips() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Identificador do controle dica de ferramenta se bem-sucedido; Caso contrário, nulo.  
  
### <a name="remarks"></a>Comentários  
 Um controle guia cria um controle de dica de ferramenta se ele tem o estilo TCS_TOOLTIPS. Você também pode atribuir um controle de dica de ferramenta a um controle guia usando o `SetToolTips` função de membro.  
  
##  <a name="highlightitem"></a>  CTabCtrl::HighlightItem  
 Define o estado de realce de um item de guia.  
  
```  
BOOL HighlightItem(int idItem,   BOOL fHighlight = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *idItem*  
 Índice baseado em zero de um item de controle de guia.  
  
 *fHighlight*  
 Valor que especifica o estado de realce a ser definido. Se esse valor for TRUE, a guia é realçada; Se for FALSE, a guia é definida como seu estado padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa a mensagem do Win32 [TCM_HIGHLIGHTITEM](/windows/desktop/Controls/tcm-highlightitem), conforme descrito no SDK do Windows.  
  
##  <a name="hittest"></a>  CTabCtrl::HitTest  
 Determina qual guia, se houver, será a posição da tela especificadas.  
  
```  
int HitTest(TCHITTESTINFO* pHitTestInfo) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pHitTestInfo*  
 Ponteiro para um [TCHITTESTINFO](/windows/desktop/api/commctrl/ns-commctrl-tagtchittestinfo) estrutura, conforme descrito no SDK do Windows, que especifica a posição da tela para testar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o índice baseado em zero da guia ou - 1 se a guia não estiver na posição especificada.  
  
##  <a name="insertitem"></a>  CTabCtrl::InsertItem  
 Insere uma nova guia em um controle de guia existente.  
  
```  
LONG InsertItem(
    int nItem,
    TCITEM* pTabCtrlItem);

 
LONG InsertItem(
    int nItem,
    LPCTSTR lpszItem);

 
LONG InsertItem(
    int nItem,
    LPCTSTR lpszItem,
    int nImage);

 
LONG InsertItem(
    UINT nMask,
    int nItem,
    LPCTSTR lpszItem,
    int nImage,
    LPARAM lParam);

 
LONG InsertItem(
    UINT nMask,  
    int nItem,  
    LPCTSTR lpszItem,  
    int nImage,  
    LPARAM lParam,  
    DWORD dwState,  
    DWORD dwStateMask);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nItem*  
 Índice baseado em zero da nova guia.  
  
 *pTabCtrlItem*  
 Ponteiro para um [TCITEM](/windows/desktop/api/commctrl/ns-commctrl-tagtcitema) estrutura que especifica os atributos da guia.  
  
 *lpszItem*  
 Endereço de uma cadeia de caracteres terminada em nulo que contém o texto da guia.  
  
 *Nimagem*  
 O índice baseado em zero de uma imagem para inserir de uma lista de imagens.  
  
 *nMask*  
 Especifica qual `TCITEM` estruturar os atributos a serem definidos. Pode ser zero ou uma combinação dos seguintes valores:  
  
- TCIF_TEXT o `pszText` membro é válido.  
  
- TCIF_IMAGE o `iImage` membro é válido.  
  
- TCIF_PARAM a *lParam* membro é válido.  
  
- TCIF_RTLREADING o texto de `pszText` é exibido usando a ordem de leitura da direita para a esquerda nos sistemas hebraico ou árabe.  
  
- TCIF_STATE a *dwState* membro é válido.  
  
 *lParam*  
 Dados definidos pelo aplicativo associados com a guia.  
  
 *dwState*  
 Especifica valores para os estados do item. Para obter mais informações, consulte [TCITEM](/windows/desktop/api/commctrl/ns-commctrl-tagtcitema) no SDK do Windows.  
  
 *dwStateMask*  
 Especifica quais estados devem ser definidas. Para obter mais informações, consulte [TCITEM](/windows/desktop/api/commctrl/ns-commctrl-tagtcitema) no SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Índice baseado em zero da guia novo se bem-sucedido; Caso contrário, - 1.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTabCtrl#5](../../mfc/reference/codesnippet/cpp/ctabctrl-class_5.cpp)]  
  
##  <a name="removeimage"></a>  CTabCtrl::RemoveImage  
 Remove a imagem especificada da lista de imagens de um controle guia.  
  
```  
void RemoveImage(int nImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 *Nimagem*  
 Índice baseado em zero da imagem a ser removida.  
  
### <a name="remarks"></a>Comentários  
 O controle de guia atualiza o índice de imagem de cada guia para que cada guia permaneça associado com a mesma imagem.  
  
##  <a name="setcurfocus"></a>  CTabCtrl::SetCurFocus  
 Define o foco para uma guia especificada em um controle guia.  
  
```  
void SetCurFocus(int nItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nItem*  
 Especifica o índice do guia, que obtém o foco.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem do Win32 [TCM_SETCURFOCUS](/windows/desktop/Controls/tcm-setcurfocus), conforme descrito no SDK do Windows.  
  
##  <a name="setcursel"></a>  CTabCtrl::SetCurSel  
 Seleciona uma guia em um controle guia.  
  
```  
int SetCurSel(int nItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nItem*  
 O índice baseado em zero do item a ser selecionado.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero da guia selecionada anteriormente se for bem-sucedido, caso contrário, - 1.  
  
### <a name="remarks"></a>Comentários  
 Um controle guia não envia uma mensagem de notificação TCN_SELCHANGING ou TCN_SELCHANGE quando uma guia é selecionada com o uso dessa função. Essas notificações são enviadas, WM_NOTIFY, quando o usuário clica ou usa o teclado para alterar as guias.  
  
##  <a name="setextendedstyle"></a>  CTabCtrl::SetExtendedStyle  
 Define os estilos estendidos para um controle guia.  
  
```  
DWORD SetExtendedStyle(DWORD dwNewStyle,   DWORD dwExMask = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwNewStyle*  
 Valor que especifica uma combinação de guia controla estilos estendidos.  
  
 *dwExMask*  
 Um valor DWORD que indica quais estilos no *dwNewStyle* são que serão afetadas. Somente os estilos estendidos na *dwExMask* será alterado. Todos os outros estilos serão mantidos como está. Se esse parâmetro for zero, então todos os estilos no *dwNewStyle* serão afetados.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor DWORD que contém o anterior [estilos estendidos de controle guia](/windows/desktop/Controls/tab-control-extended-styles), conforme descrito no SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Essa função membro implementa o comportamento da mensagem do Win32 [TCM_SETEXTENDEDSTYLE](/windows/desktop/Controls/tcm-setextendedstyle), conforme descrito no SDK do Windows.  
  
##  <a name="setimagelist"></a>  CTabCtrl::SetImageList  
 Atribui uma lista de imagens a um controle guia.  
  
```  
CImageList* SetImageList(CImageList* pImageList);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pImageList*  
 Ponteiro para a lista de imagens a ser atribuído ao controle guia.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para a lista de imagens anteriores ou nulo se não houver nenhuma lista de imagens anteriores.  
  
##  <a name="setitem"></a>  CTabCtrl::SetItem  
 Define alguns ou todos os atributos de uma guia.  
  
```  
BOOL SetItem(int nItem,   TCITEM* pTabCtrlItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nItem*  
 Índice baseado em zero do item.  
  
 *pTabCtrlItem*  
 Ponteiro para um [TCITEM](/windows/desktop/api/commctrl/ns-commctrl-tagtcitema) estrutura que contém os novos atributos de item. O `mask` membro especifica quais atributos a serem definidos. Se o `mask` membro Especifica o valor TCIF_TEXT, o `pszText` membro é o endereço de uma cadeia de caracteres terminada em nulo e o `cchTextMax` membro será ignorado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [GetItem](#getitem).  
  
##  <a name="setitemextra"></a>  CTabCtrl::SetItemExtra  
 Define o número de bytes por guia reservado para os dados definidos pelo aplicativo em um controle guia.  
  
```  
BOOL SetItemExtra(int nBytes);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nBytes*  
 O número de bytes adicionais para definir.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem do Win32 [TCM_SETITEMEXTRA](/windows/desktop/Controls/tcm-setitemextra), conforme descrito no SDK do Windows.  
  
##  <a name="setitemsize"></a>  CTabCtrl::SetItemSize  
 Define a largura e altura dos itens de controle de guia.  
  
```  
CSize SetItemSize(CSize size);
```  
  
### <a name="parameters"></a>Parâmetros  
 *size*  
 A nova largura e altura, em pixels, dos itens de controle de guia.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a antiga largura e altura dos itens de controle de guia.  
  
##  <a name="setitemstate"></a>  CTabCtrl::SetItemState  
 Define o estado do item de controle de guia identificado pelo *nItem*.  
  
```  
BOOL SetItemState(
    int nItem,
    DWORD dwMask,
    DWORD dwState);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nItem*  
 O número de índice baseado em zero do item para o qual definir informações de estado.  
  
 *dwMask*  
 Especificando quais do estado do item de sinalizadores para definir a máscara. Para obter uma lista de valores, consulte o membro de máscara do [TCITEM](/windows/desktop/api/commctrl/ns-commctrl-tagtcitema) estrutura, conforme descrito no SDK do Windows.  
  
 *dwState*  
 Uma referência a um valor DWORD que contém as informações de estado. pode ser um dos seguintes valores:  
  
|Valor|Descrição|  
|-----------|-----------------|  
|TCIS_BUTTONPRESSED|O item de controle de guia é selecionado.|  
|TCIS_HIGHLIGHTED|O item de controle de guia é realçado, e a guia e texto são desenhados usando a cor de realce atual. Ao usar a cor de realce, esse será uma verdadeira interpolação, não uma cor pontilhada.|  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
##  <a name="setmintabwidth"></a>  CTabCtrl::SetMinTabWidth  
 Define a largura mínima de itens em um controle guia.  
  
```  
int SetMinTabWidth(int cx);
```  
  
### <a name="parameters"></a>Parâmetros  
 *CX*  
 Largura mínima a ser definido para um item de controle de guia. Se esse parâmetro for definido como -1, o controle usará a largura de tabulação padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 A largura mínima de guia anterior.  
  
### <a name="return-value"></a>Valor de retorno  
 Essa função membro implementa o comportamento da mensagem do Win32 [TCM_SETMINTABWIDTH](/windows/desktop/Controls/tcm-setmintabwidth), conforme descrito no SDK do Windows.  
  
##  <a name="setpadding"></a>  CTabCtrl::SetPadding  
 Define a quantidade de espaço (preenchimento) em torno do ícone de cada guia e o rótulo em um controle guia.  
  
```  
void SetPadding(CSize size);
```  
  
### <a name="parameters"></a>Parâmetros  
 *size*  
 Define a quantidade de espaço (preenchimento) em torno do ícone de cada guia e o rótulo em um controle guia.  
  
##  <a name="settooltips"></a>  CTabCtrl::SetToolTips  
 Atribui um controle de dica de ferramenta para um controle guia.  
  
```  
void SetToolTips(CToolTipCtrl* pWndTip);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pWndTip*  
 Identificador do controle de dica de ferramenta.  
  
### <a name="remarks"></a>Comentários  
 Você pode obter o controle da dica de ferramenta associado com um controle guia, fazendo uma chamada para `GetToolTips`.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPropertySheet::GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CHeaderCtrl](../../mfc/reference/cheaderctrl-class.md)   
 [Classe CListCtrl](../../mfc/reference/clistctrl-class.md)
