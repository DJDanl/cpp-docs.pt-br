---
title: Classe CTabCtrl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
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
- tab controls
- CTabCtrl class, common controls
- CTabCtrl class
ms.assetid: 42e4aff6-46ae-4b2c-beaa-d1dce8d82138
caps.latest.revision: 21
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
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: 150b11e4989cd45ba2a8065c86c07510d00c346c
ms.lasthandoff: 04/01/2017

---
# <a name="ctabctrl-class"></a>Classe CTabCtrl
Fornece a funcionalidade de controle de guia comum do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CTabCtrl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CTabCtrl::CTabCtrl](#ctabctrl)|Constrói um objeto `CTabCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CTabCtrl::AdjustRect](#adjustrect)|Calcula a área de exibição de um controle guia recebe um retângulo de janela ou calcula o retângulo de janela que corresponde a uma área de exibição fornecido.|  
|[CTabCtrl::Create](#create)|Cria um controle de guia e a anexa a uma instância de um `CTabCtrl` objeto.|  
|[CTabCtrl::CreateEx](#createex)|Cria um controle guia com os estilos estendidos do Windows especificados e a anexa a uma instância de um `CTabCtrl` objeto.|  
|[CTabCtrl::DeleteAllItems](#deleteallitems)|Remove todos os itens de um controle guia.|  
|[CTabCtrl::DeleteItem](#deleteitem)|Remove um item de um controle guia.|  
|[CTabCtrl::DeselectAll](#deselectall)|Redefine os itens em um controle guia, desmarcando qualquer um que foi pressionado.|  
|[CTabCtrl::DrawItem](#drawitem)|Desenha um item especificado de um controle guia.|  
|[CTabCtrl::GetCurFocus](#getcurfocus)|Recupera a guia com o foco atual de um controle guia.|  
|[CTabCtrl::GetCurSel](#getcursel)|Determina a guia selecionada no momento em um controle guia.|  
|[CTabCtrl::GetExtendedStyle](#getextendedstyle)|Recupera os estilos estendidos que estão atualmente em uso para o controle de guia.|  
|[CTabCtrl::GetImageList](#getimagelist)|Recupera a lista de imagens associada a um controle guia.|  
|[CTabCtrl::GetItem](#getitem)|Recupera informações sobre uma guia em um controle guia.|  
|[CTabCtrl::GetItemCount](#getitemcount)|Recupera o número de guias no controle guia.|  
|[CTabCtrl::GetItemRect](#getitemrect)|Recupera o retângulo delimitador para uma guia em um controle guia.|  
|[CTabCtrl::GetItemState](#getitemstate)|Recupera o estado do item de controle de guia indicado.|  
|[CTabCtrl::GetRowCount](#getrowcount)|Recupera o número atual de linhas de guias em um controle guia.|  
|[CTabCtrl::GetToolTips](#gettooltips)|Recupera o identificador do controle de dica de ferramenta associado a um controle guia.|  
|[CTabCtrl::HighlightItem](#highlightitem)|Define o estado de realce de um item de guia.|  
|[CTabCtrl::HitTest](#hittest)|Determina qual guia, se houver, está em uma posição especificada de tela.|  
|[CTabCtrl::InsertItem](#insertitem)|Insere uma nova guia em um controle guia.|  
|[CTabCtrl::RemoveImage](#removeimage)|Remove uma imagem da lista de imagens de um controle guia.|  
|[CTabCtrl::SetCurFocus](#setcurfocus)|Define o foco para um guia especificado em um controle guia.|  
|[CTabCtrl::SetCurSel](#setcursel)|Seleciona uma guia em um controle guia.|  
|[CTabCtrl::SetExtendedStyle](#setextendedstyle)|Define os estilos estendidos para um controle guia.|  
|[CTabCtrl::SetImageList](#setimagelist)|Atribui uma lista de imagens a um controle guia.|  
|[CTabCtrl::SetItem](#setitem)|Define alguns ou todos os atributos da guia.|  
|[CTabCtrl::SetItemExtra](#setitemextra)|Define o número de bytes por guia reservado para dados de aplicativo definido em um controle guia.|  
|[CTabCtrl::SetItemSize](#setitemsize)|Define a largura e altura de um item.|  
|[CTabCtrl::SetItemState](#setitemstate)|Define o estado do item de controle de guia indicado.|  
|[CTabCtrl::SetMinTabWidth](#setmintabwidth)|Define a largura mínima de itens em um controle guia.|  
|[CTabCtrl::SetPadding](#setpadding)|Define a quantidade de espaço (preenchimento) em torno de ícone de cada guia e o rótulo em um controle guia.|  
|[CTabCtrl::SetToolTips](#settooltips)|Atribui um controle de dica de ferramenta a um controle guia.|  
  
## <a name="remarks"></a>Comentários  
 Um "controle de guia" é análogo a divisores em um bloco de anotações ou rótulos em um arquivo de gabinete. Usando um controle guia, um aplicativo pode definir várias páginas para a mesma área de uma caixa de diálogo ou janela. Cada página consiste em um conjunto de informações ou um grupo de controles que o aplicativo é exibido quando o usuário seleciona a guia correspondente. Um tipo especial de controle de guia exibe as guias que se parecem com botões. Clicar em um botão deve executar imediatamente um comando em vez de exibir uma página.  
  
 Esse controle (e, portanto, o `CTabCtrl` classe) está disponível apenas para programas em execução na versão do Windows 95/98 e Windows NT 3.51 e posterior.  
  
 Para obter mais informações sobre como usar `CTabCtrl`, consulte [controles](../../mfc/controls-mfc.md) e [usando CTabCtrl](../../mfc/using-ctabctrl.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CTabCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn.h  
  
##  <a name="adjustrect"></a>CTabCtrl::AdjustRect  
 Calcula a área de exibição de um controle guia recebe um retângulo de janela ou calcula o retângulo de janela que corresponde a uma área de exibição fornecido.  
  
```  
void AdjustRect(BOOL bLarger,   LPRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bLarger`  
 Indica qual operação a ser executada. Se esse parâmetro for **TRUE**, `lpRect` Especifica um retângulo de exibição e recebe o retângulo de janela correspondente. Se esse parâmetro for **FALSE**, `lpRect` Especifica um retângulo de janela e recebe o retângulo de exibição correspondente.  
  
 `lpRect`  
 Ponteiro para um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que especifica o retângulo fornecido e recebe o retângulo calculado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTabCtrl n º 1](../../mfc/reference/codesnippet/cpp/ctabctrl-class_1.cpp)]  
  
##  <a name="create"></a>CTabCtrl::Create  
 Cria um controle de guia e a anexa a uma instância de um `CTabCtrl` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Especifica o estilo do controle de guia. Aplique qualquer combinação de [guia estilos de controle](http://msdn.microsoft.com/library/windows/desktop/bb760549), descrita no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Consulte **comentários** para obter uma lista de estilos de janela que você também pode aplicar ao controle.  
  
 `rect`  
 Especifica o tamanho e a posição do controle. Ele pode ser um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura.  
  
 `pParentWnd`  
 Especifica a janela do pai do controle, geralmente um `CDialog`. Ele não deve ser **nulo**.  
  
 `nID`  
 Especifica a ID. do controle  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se a inicialização do objeto foi bem-sucedida; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Você pode criar um `CTabCtrl` objeto em duas etapas. Primeiro, chame o construtor e, em seguida, chamar **criar**, que cria o controle de guia e anexa-o para o `CTabCtrl` objeto.  
  
 Além dos estilos de controle da guia, você pode aplicar os seguintes estilos de janela a um controle guia:  
  
- **Estilo** cria uma janela filho que representa o controle de guia. Não pode ser usado com o `WS_POPUP` estilo.  
  
- **WS_VISIBLE** cria um controle de guia é visível inicialmente.  
  
- **WS_DISABLED** cria uma janela que é inicialmente desabilitada.  
  
- **WS_GROUP** Especifica o primeiro controle de um grupo de controles em que o usuário pode mover de um controle para o seguinte com as teclas de direção. Todos os controles definidos com o **WS_GROUP** após o primeiro controle pertencem ao mesmo grupo de estilo. O próximo controle com o **WS_GROUP** estilo encerra o grupo de estilo e inicia o próximo grupo (ou seja, termina um grupo onde começa o próximo).  
  
- **WS_TABSTOP** Especifica um número de controles por meio do qual o usuário pode mover usando a tecla TAB. A tecla TAB move o usuário para o próximo controle especificado pelo **WS_TABSTOP** estilo.  
  
 Para criar um controle guia com estilos de janela estendidos, chame [CTabCtrl::CreateEx](#createex) em vez de **criar**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTabCtrl n º 2](../../mfc/reference/codesnippet/cpp/ctabctrl-class_2.cpp)]  
  
##  <a name="createex"></a>CTabCtrl::CreateEx  
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
 `dwExStyle`  
 Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista dos estilos estendidos do Windows, consulte o `dwExStyle` parâmetro [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `dwStyle`  
 Especifica o estilo do controle de guia. Aplique qualquer combinação de [guia estilos de controle](http://msdn.microsoft.com/library/windows/desktop/bb760549), descrita no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Consulte **comentários** na [criar](#create) para obter uma lista de estilos de janela que você também pode aplicar ao controle.  
  
 `rect`  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que descreve o tamanho e a posição da janela deve ser criada, nas coordenadas do cliente de `pParentWnd`.  
  
 `pParentWnd`  
 Um ponteiro para a janela que é o pai do controle.  
  
 `nID`  
 ID de janela filho. do controle  
  
### <a name="return-value"></a>Valor de retorno  
 Caso contrário, 0 diferente de zero se tiver êxito.  
  
### <a name="remarks"></a>Comentários  
 Use `CreateEx` em vez de [criar](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.  
  
 `CreateEx`cria o controle com os estilos estendidos do Windows especificados pela `dwExStyle`. Conjunto estendido estilos específicos para usar um controle [SetExtendedStyle](#setextendedstyle). Por exemplo, use `CreateEx` para definir esses estilos como **WS_EX_CONTEXTHELP**, mas usar `SetExtendedStyle` para definir esses estilos como **TCS_EX_FLATSEPARATORS**. Para obter mais informações, consulte os estilos descritos em [estendidos estilos de controle guia](http://msdn.microsoft.com/library/windows/desktop/bb760546) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="ctabctrl"></a>CTabCtrl::CTabCtrl  
 Constrói um objeto `CTabCtrl`.  
  
```  
CTabCtrl();
```  
  
##  <a name="deleteallitems"></a>CTabCtrl::DeleteAllItems  
 Remove todos os itens de um controle guia.  
  
```  
BOOL DeleteAllItems();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
##  <a name="deleteitem"></a>CTabCtrl::DeleteItem  
 Remove o item especificado de um controle guia.  
  
```  
BOOL DeleteItem(int nItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nItem`  
 Valor com base em zero do item a ser excluído.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTabCtrl n º 3](../../mfc/reference/codesnippet/cpp/ctabctrl-class_3.cpp)]  
  
##  <a name="deselectall"></a>CTabCtrl::DeselectAll  
 Redefine os itens em um controle guia, desmarcando qualquer um que foi pressionado.  
  
```  
void DeselectAll(BOOL fExcludeFocus);
```  
  
### <a name="parameters"></a>Parâmetros  
 *fExcludeFocus*  
 Sinalizador que especifica o escopo de deselection o item. Se esse parâmetro for definido como **FALSE**, todos os botões da guia serão redefinidos. Se ele for definido como **TRUE**, em seguida, todos os itens da guia, exceto atualmente selecionado serão redefinidos.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32, [TCM_DESELECTALL](http://msdn.microsoft.com/library/windows/desktop/bb760579), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="drawitem"></a>CTabCtrl::DrawItem  
 Chamado pelo framework quando um aspecto visual de um desenho proprietário é alterado controle guia.  
  
```  
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpDrawItemStruct`  
 Um ponteiro para um [DRAWITEMSTRUCT](http://msdn.microsoft.com/library/windows/desktop/bb775802) estrutura que descreve o item a ser pintado.  
  
### <a name="remarks"></a>Comentários  
 O **itemAction** membro o `DRAWITEMSTRUCT` estrutura define a ação de desenho que deve ser executada.  
  
 Por padrão, essa função de membro não faz nada. Substituir essa função de membro para implementar o desenho de um desenho proprietário `CTabCtrl` objeto.  
  
 O aplicativo deve restaurar todos os objetos de interface (GDI) do dispositivo gráficos selecionados para o contexto de exibição fornecido no `lpDrawItemStruct` antes desse membro função termina.  
  
##  <a name="getcurfocus"></a>CTabCtrl::GetCurFocus  
 Recupera o índice da guia com o foco atual.  
  
```  
int GetCurFocus() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero da guia com o foco atual.  
  
##  <a name="getcursel"></a>CTabCtrl::GetCurSel  
 Recupera a guia selecionada no momento em um controle guia.  
  
```  
int GetCurSel() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Índice com base em zero da guia selecionada se for bem-sucedido ou - 1 se a guia não estiver selecionada.  
  
##  <a name="getextendedstyle"></a>CTabCtrl::GetExtendedStyle  
 Recupera os estilos estendidos que estão atualmente em uso para o controle de guia.  
  
```  
DWORD GetExtendedStyle();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Representa os estilos estendidos atualmente em uso para o controle de guia. Esse valor é uma combinação de [estendidos estilos de controle guia](http://msdn.microsoft.com/library/windows/desktop/bb760546), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [TCM_GETEXTENDEDSTYLE](http://msdn.microsoft.com/library/windows/desktop/bb760585), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getimagelist"></a>CTabCtrl::GetImageList  
 Recupera a lista de imagem que está associado a um controle guia.  
  
```  
CImageList* GetImageList() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, um ponteiro para a lista de imagens da guia controle; Caso contrário, **nulo**.  
  
##  <a name="getitem"></a>CTabCtrl::GetItem  
 Recupera informações sobre uma guia em um controle guia.  
  
```  
BOOL GetItem(int nItem,   TCITEM* pTabCtrlItem) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nItem`  
 Índice de base zero da guia.  
  
 `pTabCtrlItem`  
 Ponteiro para um [TCITEM](http://msdn.microsoft.com/library/windows/desktop/bb760554) estrutura, usada para especificar as informações a serem recuperados. Também é usado para receber informações sobre a guia. Essa estrutura é usada com o `InsertItem`, `GetItem`, e `SetItem` funções de membro.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** se for bem-sucedida; **FALSE** caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Quando a mensagem é enviada, o **máscara** membro especifica quais atributos retornam. Se o **máscara** membro Especifica o `TCIF_TEXT` valor, o **pszText** membro deve conter o endereço do buffer que recebe o texto do item e o **cchTextMax** membro deve especificar o tamanho do buffer.  
  
 **máscara**  
 Valor que especifica qual `TCITEM` para recuperar ou definir os membros de estrutura. Esse membro pode ser zero ou uma combinação dos seguintes valores:  
  
- `TCIF_TEXT`O **pszText** membro é válido.  
  
- `TCIF_IMAGE`O `iImage` membro é válido.  
  
- `TCIF_PARAM`O **lParam** membro é válido.  
  
- `TCIF_RTLREADING`O texto da **pszText** é exibido usando a ordem de leitura da direita para a esquerda nos sistemas hebraico ou árabe.  
  
- `TCIF_STATE`O **dwState** membro é válido.  
  
 **pszText**  
 Ponteiro para uma cadeia de caracteres terminada em nulo que contém o texto da guia se a estrutura contém informações sobre uma guia. Se a estrutura estiver recebendo informações, esse membro Especifica o endereço do buffer que recebe o texto da guia.  
  
 **cchTextMax**  
 Tamanho do buffer apontado pelo **pszText**. Esse membro será ignorado se a estrutura não está recebendo informações.  
  
 `iImage`  
 Indexar o controle de guia lista de imagens, ou - 1 se não houver nenhuma imagem para a guia.  
  
 **lParam**  
 Dados definidos pelo aplicativo associados com a guia. Se houver mais de quatro bytes de dados definido pelo aplicativo por tabulação, um aplicativo deve definir uma estrutura e usá-lo em vez do `TCITEM` estrutura. O primeiro membro da estrutura de aplicativo definido deve ser um [TCITEMHEADER](http://msdn.microsoft.com/library/windows/desktop/bb760556)estrutura. O **TCITEMHEADER** estrutura é idêntica do `TCITEM` estrutura, mas sem o **lParam** membro. A diferença entre o tamanho da sua estrutura e o tamanho do **TCITEMHEADER** estrutura deve igual ao número de bytes adicionais por tabulação.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTabCtrl n º 4](../../mfc/reference/codesnippet/cpp/ctabctrl-class_4.cpp)]  
  
##  <a name="getitemcount"></a>CTabCtrl::GetItemCount  
 Recupera o número de guias no controle guia.  
  
```  
int GetItemCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Número de itens no controle guia.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CPropertySheet::GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).  
  
##  <a name="getitemrect"></a>CTabCtrl::GetItemRect  
 Recupera o retângulo delimitador para a guia especificada em um controle guia.  
  
```  
BOOL GetItemRect(int nItem,   LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nItem`  
 Índice de base zero do item de guia.  
  
 `lpRect`  
 Ponteiro para um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que recebe o retângulo delimitador da guia. Essas coordenadas usam modo de mapeamento do visor atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CPropertySheet::GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).  
  
##  <a name="getitemstate"></a>CTabCtrl::GetItemState  
 Recupera o estado do item de controle de guia identificado por `nItem`.  
  
```  
DWORD GetItemState(
    int nItem,  
    DWORD dwMask) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nItem`  
 O número de índice com base em zero do item para o qual recuperar informações de estado.  
  
 `dwMask`  
 Especifica que o estado do item de sinalizadores para retornar a máscara. Para obter uma lista de valores, consulte o membro de máscara do [TCITEM](http://msdn.microsoft.com/library/windows/desktop/bb760554) estrutura, conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a um `DWORD` valor receber as informações de estado. Pode ser um dos seguintes valores:  
  
|Valor|Descrição|  
|-----------|-----------------|  
|**TCIS_BUTTONPRESSED**|O item de controle de guia é selecionado.|  
|**TCIS_HIGHLIGHTED**|O item de controle de guia é realçado e a guia e texto são desenhados usando a cor de realce atual. Ao usar a cor de realce, isso será uma interpolação true, não uma cor pontilhada.|  
  
### <a name="remarks"></a>Comentários  
 Estado de um item é especificado pelo **dwState** membro o `TCITEM` estrutura.  
  
##  <a name="getrowcount"></a>CTabCtrl::GetRowCount  
 Recupera o número atual de linhas em um controle guia.  
  
```  
int GetRowCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de linhas de guias no controle guia.  
  
### <a name="remarks"></a>Comentários  
 Guia somente os controles que têm o **TCS_MULTILINE** estilo pode ter várias linhas de guias.  
  
##  <a name="gettooltips"></a>CTabCtrl::GetToolTips  
 Recupera o identificador do controle de dica de ferramenta associado a um controle guia.  
  
```  
CToolTipCtrl* GetToolTips() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Identificador do controle dica de ferramenta se bem-sucedido; Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Um controle guia cria um controle de dica de ferramenta se ele tiver o **TCS_TOOLTIPS** estilo. Você também pode atribuir um controle de dica de ferramenta a um controle guia usando o `SetToolTips` função de membro.  
  
##  <a name="highlightitem"></a>CTabCtrl::HighlightItem  
 Define o estado de realce de um item de guia.  
  
```  
BOOL HighlightItem(int idItem,   BOOL fHighlight = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `idItem`  
 Índice de base zero de um item de controle de guia.  
  
 `fHighlight`  
 Valor que especifica o estado de realce a ser definido. Se esse valor for **TRUE**, a guia é realçada; se **FALSE**, a guia é definida para seu estado padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa a mensagem de Win32 [TCM_HIGHLIGHTITEM](http://msdn.microsoft.com/library/windows/desktop/bb760602), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="hittest"></a>CTabCtrl::HitTest  
 Determina qual guia, se houver, está na posição especificada de tela.  
  
```  
int HitTest(TCHITTESTINFO* pHitTestInfo) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pHitTestInfo`  
 Ponteiro para um [TCHITTESTINFO](http://msdn.microsoft.com/library/windows/desktop/bb760553) estrutura, conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)], que especifica a posição da tela para testar.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o índice baseado em zero da guia ou - 1 se a guia não estiver na posição especificada.  
  
##  <a name="insertitem"></a>CTabCtrl::InsertItem  
 Insere uma nova guia em um controle guia existente.  
  
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
 `nItem`  
 Índice de base zero da nova guia.  
  
 `pTabCtrlItem`  
 Ponteiro para um [TCITEM](http://msdn.microsoft.com/library/windows/desktop/bb760554) estrutura que especifica os atributos da guia.  
  
 `lpszItem`  
 Endereço de uma cadeia de caracteres terminada em nulo que contém o texto da guia.  
  
 `nImage`  
 O índice de base zero de uma imagem para inserir de uma lista de imagens.  
  
 `nMask`  
 Especifica qual `TCITEM` estrutura atributos a serem definidos. Pode ser zero ou uma combinação dos seguintes valores:  
  
- `TCIF_TEXT`O **pszText** membro é válido.  
  
- `TCIF_IMAGE`O `iImage` membro é válido.  
  
- `TCIF_PARAM`O **lParam** membro é válido.  
  
- `TCIF_RTLREADING`O texto da **pszText** é exibido usando a ordem de leitura da direita para a esquerda nos sistemas hebraico ou árabe.  
  
- `TCIF_STATE`O **dwState** membro é válido.  
  
 `lParam`  
 Dados definidos pelo aplicativo associados com a guia.  
  
 `dwState`  
 Especifica valores para os estados do item. Para obter mais informações, consulte [TCITEM](http://msdn.microsoft.com/library/windows/desktop/bb760554) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 *dwStateMask*  
 Especifica quais estados devem ser definidas. Para obter mais informações, consulte [TCITEM](http://msdn.microsoft.com/library/windows/desktop/bb760554) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Índice de base zero da guia novo se bem-sucedido; Caso contrário, - 1.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTabCtrl n º 5](../../mfc/reference/codesnippet/cpp/ctabctrl-class_5.cpp)]  
  
##  <a name="removeimage"></a>CTabCtrl::RemoveImage  
 Remove a imagem especificada da lista de imagens de um controle guia.  
  
```  
void RemoveImage(int nImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nImage`  
 Índice de base zero da imagem a ser removido.  
  
### <a name="remarks"></a>Comentários  
 O controle de guia atualiza o índice de imagem de cada guia para que cada guia permaneça associado com a mesma imagem.  
  
##  <a name="setcurfocus"></a>CTabCtrl::SetCurFocus  
 Define o foco para um guia especificado em um controle guia.  
  
```  
void SetCurFocus(int nItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nItem`  
 Especifica o índice da guia que obtém o foco.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [TCM_SETCURFOCUS](http://msdn.microsoft.com/library/windows/desktop/bb760610), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="setcursel"></a>CTabCtrl::SetCurSel  
 Seleciona uma guia em um controle guia.  
  
```  
int SetCurSel(int nItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nItem`  
 O índice de base zero do item a ser selecionado.  
  
### <a name="return-value"></a>Valor de retorno  
 Índice de base zero da guia anteriormente selecionada se for bem-sucedido, caso contrário, - 1.  
  
### <a name="remarks"></a>Comentários  
 Um controle de guia não enviar um **TCN_SELCHANGING** ou **TCN_SELCHANGE** mensagem de notificação quando uma guia é selecionada usando essa função. Essas notificações são enviadas usando **WM_NOTIFY**, quando o usuário clica ou usa o teclado para alterar guias.  
  
##  <a name="setextendedstyle"></a>CTabCtrl::SetExtendedStyle  
 Define os estilos estendidos para um controle guia.  
  
```  
DWORD SetExtendedStyle(DWORD dwNewStyle,   DWORD dwExMask = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwNewStyle`  
 Valor que especifica uma combinação de guia controle estilos estendidos.  
  
 `dwExMask`  
 Um `DWORD` valor que indica qual estilos em `dwNewStyle` devem ser afetadas. Somente os estilos estendidos em `dwExMask` será alterado. Todos os outros estilos serão mantidos como está. Se esse parâmetro for zero, então todos os estilos no `dwNewStyle` serão afetados.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `DWORD` valor que contém o anterior [estendidos estilos de controle guia](http://msdn.microsoft.com/library/windows/desktop/bb760546), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="return-value"></a>Valor de retorno  
 Essa função de membro implementa o comportamento da mensagem de Win32 [TCM_SETEXTENDEDSTYLE](http://msdn.microsoft.com/library/windows/desktop/bb760627), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="setimagelist"></a>CTabCtrl::SetImageList  
 Atribui uma lista de imagens a um controle guia.  
  
```  
CImageList* SetImageList(CImageList* pImageList);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pImageList`  
 Ponteiro para a lista de imagens a ser atribuído ao controle guia.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para a lista de imagem anterior ou **nulo** se não houver nenhuma lista de imagem anterior.  
  
##  <a name="setitem"></a>CTabCtrl::SetItem  
 Define alguns ou todos os atributos da guia.  
  
```  
BOOL SetItem(int nItem,   TCITEM* pTabCtrlItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nItem`  
 Índice de base zero do item.  
  
 `pTabCtrlItem`  
 Ponteiro para um [TCITEM](http://msdn.microsoft.com/library/windows/desktop/bb760554) estrutura que contém os novos atributos do item. O **máscara** membro especifica quais atributos a serem definidos. Se o **máscara** membro Especifica o `TCIF_TEXT` valor, o **pszText** membro é o endereço de uma cadeia de caracteres terminada em nulo e o **cchTextMax** membro será ignorado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [GetItem](#getitem).  
  
##  <a name="setitemextra"></a>CTabCtrl::SetItemExtra  
 Define o número de bytes por guia reservado para dados de aplicativo definido em um controle guia.  
  
```  
BOOL SetItemExtra(int nBytes);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBytes`  
 O número de bytes adicionais para definir.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [TCM_SETITEMEXTRA](http://msdn.microsoft.com/library/windows/desktop/bb760633), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="setitemsize"></a>CTabCtrl::SetItemSize  
 Define a largura e altura dos itens de controle da guia.  
  
```  
CSize SetItemSize(CSize size);
```  
  
### <a name="parameters"></a>Parâmetros  
 `size`  
 A nova largura e altura, em pixels, dos itens de controle da guia.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a antiga largura e altura dos itens de controle da guia.  
  
##  <a name="setitemstate"></a>CTabCtrl::SetItemState  
 Define o estado do item de controle de guia identificado por `nItem`.  
  
```  
BOOL SetItemState(
    int nItem,
    DWORD dwMask,
    DWORD dwState);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nItem`  
 O número de índice com base em zero do item para o qual definir informações de estado.  
  
 `dwMask`  
 Especifica que o estado do item de sinalizadores para definir a máscara. Para obter uma lista de valores, consulte o membro de máscara do [TCITEM](http://msdn.microsoft.com/library/windows/desktop/bb760554) estrutura, conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `dwState`  
 Uma referência a um `DWORD` valor que contém as informações de estado. Pode ser um dos seguintes valores:  
  
|Valor|Descrição|  
|-----------|-----------------|  
|**TCIS_BUTTONPRESSED**|O item de controle de guia é selecionado.|  
|**TCIS_HIGHLIGHTED**|O item de controle de guia é realçado e a guia e texto são desenhados usando a cor de realce atual. Ao usar a cor de realce, isso será uma interpolação true, não uma cor pontilhada.|  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
##  <a name="setmintabwidth"></a>CTabCtrl::SetMinTabWidth  
 Define a largura mínima de itens em um controle guia.  
  
```  
int SetMinTabWidth(int cx);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cx`  
 Largura mínima a ser definido para um item de controle de guia. Se esse parâmetro for definido como -1, o controle usará a largura da guia padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 A largura mínima de guia anterior.  
  
### <a name="return-value"></a>Valor de retorno  
 Essa função de membro implementa o comportamento da mensagem de Win32 [TCM_SETMINTABWIDTH](http://msdn.microsoft.com/library/windows/desktop/bb760637), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="setpadding"></a>CTabCtrl::SetPadding  
 Define a quantidade de espaço (preenchimento) em torno de ícone de cada guia e o rótulo em um controle guia.  
  
```  
void SetPadding(CSize size);
```  
  
### <a name="parameters"></a>Parâmetros  
 `size`  
 Define a quantidade de espaço (preenchimento) em torno de ícone de cada guia e o rótulo em um controle guia.  
  
##  <a name="settooltips"></a>CTabCtrl::SetToolTips  
 Atribui um controle de dica de ferramenta a um controle guia.  
  
```  
void SetToolTips(CToolTipCtrl* pWndTip);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWndTip`  
 Identificador do controle de dica de ferramenta.  
  
### <a name="remarks"></a>Comentários  
 Você pode obter o controle de dica de ferramenta associado a um controle guia fazendo uma chamada para `GetToolTips`.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CPropertySheet::GetTabControl](../../mfc/reference/cpropertysheet-class.md#gettabcontrol).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CHeaderCtrl](../../mfc/reference/cheaderctrl-class.md)   
 [Classe CListCtrl](../../mfc/reference/clistctrl-class.md)

