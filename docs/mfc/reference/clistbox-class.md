---
title: Classe CListBox | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CListBox
- AFXWIN/CListBox
- AFXWIN/CListBox::CListBox
- AFXWIN/CListBox::AddString
- AFXWIN/CListBox::CharToItem
- AFXWIN/CListBox::CompareItem
- AFXWIN/CListBox::Create
- AFXWIN/CListBox::DeleteItem
- AFXWIN/CListBox::DeleteString
- AFXWIN/CListBox::Dir
- AFXWIN/CListBox::DrawItem
- AFXWIN/CListBox::FindString
- AFXWIN/CListBox::FindStringExact
- AFXWIN/CListBox::GetAnchorIndex
- AFXWIN/CListBox::GetCaretIndex
- AFXWIN/CListBox::GetCount
- AFXWIN/CListBox::GetCurSel
- AFXWIN/CListBox::GetHorizontalExtent
- AFXWIN/CListBox::GetItemData
- AFXWIN/CListBox::GetItemDataPtr
- AFXWIN/CListBox::GetItemHeight
- AFXWIN/CListBox::GetItemRect
- AFXWIN/CListBox::GetListBoxInfo
- AFXWIN/CListBox::GetLocale
- AFXWIN/CListBox::GetSel
- AFXWIN/CListBox::GetSelCount
- AFXWIN/CListBox::GetSelItems
- AFXWIN/CListBox::GetText
- AFXWIN/CListBox::GetTextLen
- AFXWIN/CListBox::GetTopIndex
- AFXWIN/CListBox::InitStorage
- AFXWIN/CListBox::InsertString
- AFXWIN/CListBox::ItemFromPoint
- AFXWIN/CListBox::MeasureItem
- AFXWIN/CListBox::ResetContent
- AFXWIN/CListBox::SelectString
- AFXWIN/CListBox::SelItemRange
- AFXWIN/CListBox::SetAnchorIndex
- AFXWIN/CListBox::SetCaretIndex
- AFXWIN/CListBox::SetColumnWidth
- AFXWIN/CListBox::SetCurSel
- AFXWIN/CListBox::SetHorizontalExtent
- AFXWIN/CListBox::SetItemData
- AFXWIN/CListBox::SetItemDataPtr
- AFXWIN/CListBox::SetItemHeight
- AFXWIN/CListBox::SetLocale
- AFXWIN/CListBox::SetSel
- AFXWIN/CListBox::SetTabStops
- AFXWIN/CListBox::SetTopIndex
- AFXWIN/CListBox::VKeyToItem
dev_langs:
- C++
helpviewer_keywords:
- CListBox [MFC], CListBox
- CListBox [MFC], AddString
- CListBox [MFC], CharToItem
- CListBox [MFC], CompareItem
- CListBox [MFC], Create
- CListBox [MFC], DeleteItem
- CListBox [MFC], DeleteString
- CListBox [MFC], Dir
- CListBox [MFC], DrawItem
- CListBox [MFC], FindString
- CListBox [MFC], FindStringExact
- CListBox [MFC], GetAnchorIndex
- CListBox [MFC], GetCaretIndex
- CListBox [MFC], GetCount
- CListBox [MFC], GetCurSel
- CListBox [MFC], GetHorizontalExtent
- CListBox [MFC], GetItemData
- CListBox [MFC], GetItemDataPtr
- CListBox [MFC], GetItemHeight
- CListBox [MFC], GetItemRect
- CListBox [MFC], GetListBoxInfo
- CListBox [MFC], GetLocale
- CListBox [MFC], GetSel
- CListBox [MFC], GetSelCount
- CListBox [MFC], GetSelItems
- CListBox [MFC], GetText
- CListBox [MFC], GetTextLen
- CListBox [MFC], GetTopIndex
- CListBox [MFC], InitStorage
- CListBox [MFC], InsertString
- CListBox [MFC], ItemFromPoint
- CListBox [MFC], MeasureItem
- CListBox [MFC], ResetContent
- CListBox [MFC], SelectString
- CListBox [MFC], SelItemRange
- CListBox [MFC], SetAnchorIndex
- CListBox [MFC], SetCaretIndex
- CListBox [MFC], SetColumnWidth
- CListBox [MFC], SetCurSel
- CListBox [MFC], SetHorizontalExtent
- CListBox [MFC], SetItemData
- CListBox [MFC], SetItemDataPtr
- CListBox [MFC], SetItemHeight
- CListBox [MFC], SetLocale
- CListBox [MFC], SetSel
- CListBox [MFC], SetTabStops
- CListBox [MFC], SetTopIndex
- CListBox [MFC], VKeyToItem
ms.assetid: 7ba3c699-c286-4cd9-9066-532c41ec05d1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1101e4115efa3c5c822d0d64b767cdee379a0e0b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33377830"
---
# <a name="clistbox-class"></a>Classe CListBox
Fornece a funcionalidade de uma caixa de listagem do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CListBox : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CListBox::CListBox](#clistbox)|Constrói um objeto `CListBox`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CListBox::AddString](#addstring)|Adiciona uma cadeia de caracteres para uma caixa de listagem.|  
|[CListBox::CharToItem](#chartoitem)|Substituição para fornecer personalizado `WM_CHAR` tratamento de caixas de listagem do desenho proprietário que não têm cadeias de caracteres.|  
|[CListBox::CompareItem](#compareitem)|Chamado pelo framework para determinar a posição de um novo item em uma caixa de listagem do desenho proprietário classificada.|  
|[CListBox::Create](#create)|Cria a caixa de listagem do Windows e a anexa ao `CListBox` objeto.|  
|[CListBox::DeleteItem](#deleteitem)|Chamado pelo framework quando o usuário exclui um item de uma caixa de listagem do desenho proprietário.|  
|[CListBox::DeleteString](#deletestring)|Exclui uma cadeia de caracteres de uma caixa de listagem.|  
|[CListBox::Dir](#dir)|Adiciona nomes de arquivos, unidades ou ambos do diretório atual para uma caixa de listagem.|  
|[CListBox::DrawItem](#drawitem)|Chamado pelo framework quando um aspecto visual de uma caixa de listagem do desenho proprietário mude.|  
|[CListBox:: FindString](#findstring)|Pesquisa uma cadeia de caracteres em uma caixa de listagem.|  
|[CListBox::FindStringExact](#findstringexact)|Localiza a primeira cadeia de caixa de listagem que corresponde a uma cadeia de caracteres especificada.|  
|[CListBox::GetAnchorIndex](#getanchorindex)|Recupera o índice com base em zero do item atual âncora em uma caixa de listagem.|  
|[CListBox::GetCaretIndex](#getcaretindex)|Determina o índice do item que tem o foco do retângulo em uma caixa de listagem de seleção múltipla.|  
|[CListBox::GetCount](#getcount)|Retorna o número de cadeias de caracteres em uma caixa de listagem.|  
|[CListBox::GetCurSel](#getcursel)|Retorna o índice baseado em zero da cadeia de caracteres atualmente selecionado em uma caixa de listagem.|  
|[CListBox::GetHorizontalExtent](#gethorizontalextent)|Retorna a largura em pixels que uma caixa de listagem pode ser rolada horizontalmente.|  
|[CListBox::GetItemData](#getitemdata)|Retorna o valor de 32 bits associado ao item de caixa de listagem.|  
|[CListBox::GetItemDataPtr](#getitemdataptr)|Retorna um ponteiro para um item de caixa de listagem.|  
|[CListBox::GetItemHeight](#getitemheight)|Determina a altura dos itens em uma caixa de listagem.|  
|[CListBox::GetItemRect](#getitemrect)|Retorna o retângulo delimitador do item de caixa de listagem, como ele é exibido no momento.|  
|[CListBox::GetListBoxInfo](#getlistboxinfo)|Recupera o número de itens por coluna.|  
|[CListBox::GetLocale](#getlocale)|Recupera o identificador de localidade para uma caixa de listagem.|  
|[CListBox::GetSel](#getsel)|Retorna o estado de seleção de um item de caixa de listagem.|  
|[CListBox::GetSelCount](#getselcount)|Retorna o número de cadeias de caracteres atualmente selecionado em uma caixa de listagem de seleção múltipla.|  
|[CListBox::GetSelItems](#getselitems)|Retorna os índices das cadeias de caracteres atualmente selecionados em uma caixa de listagem.|  
|[CListBox::GetText](#gettext)|Copia um item de caixa de listagem para um buffer.|  
|[CListBox::GetTextLen](#gettextlen)|Retorna o comprimento em bytes de um item de caixa de listagem.|  
|[CListBox::GetTopIndex](#gettopindex)|Retorna o índice da primeira cadeia de caracteres visível em uma caixa de listagem.|  
|[CListBox::InitStorage](#initstorage)|Preallocates blocos de memória para cadeias de caracteres e itens de caixa de lista.|  
|[CListBox::InsertString](#insertstring)|Insere uma cadeia de caracteres em um local específico em uma caixa de listagem.|  
|[CListBox::ItemFromPoint](#itemfrompoint)|Retorna o índice do item de caixa de listagem mais próximo de um ponto.|  
|[CListBox::MeasureItem](#measureitem)|Chamado pelo framework quando uma caixa de listagem do desenho proprietário é criada para determinar as dimensões da caixa de listagem.|  
|[CListBox::ResetContent](#resetcontent)|Limpa todas as entradas de uma caixa de listagem.|  
|[CListBox::SelectString](#selectstring)|Procura e seleciona uma cadeia de caracteres em uma caixa de listagem de seleção única.|  
|[CListBox::SelItemRange](#selitemrange)|Marca ou desmarca uma variedade de cadeias de caracteres em uma caixa de listagem de seleção múltipla.|  
|[CListBox::SetAnchorIndex](#setanchorindex)|Define a âncora em uma caixa de listagem de seleção múltipla para começar uma seleção estendida.|  
|[CListBox::SetCaretIndex](#setcaretindex)|Define o retângulo de foco para o item no índice especificado em uma caixa de listagem de seleção múltipla.|  
|[CListBox::SetColumnWidth](#setcolumnwidth)|Define a largura da coluna de uma caixa de listagem de várias colunas.|  
|[CListBox::SetCurSel](#setcursel)|Seleciona uma cadeia de caracteres da caixa de listagem.|  
|[CListBox::SetHorizontalExtent](#sethorizontalextent)|Define a largura em pixels que uma caixa de listagem pode ser rolada horizontalmente.|  
|[CListBox::SetItemData](#setitemdata)|Define o valor de 32 bits associado ao item de caixa de listagem.|  
|[CListBox::SetItemDataPtr](#setitemdataptr)|Define um ponteiro para o item de caixa de listagem.|  
|[CListBox::SetItemHeight](#setitemheight)|Define a altura dos itens em uma caixa de listagem.|  
|[CListBox::SetLocale](#setlocale)|Define o identificador de localidade para uma caixa de listagem.|  
|[CListBox::SetSel](#setsel)|Marca ou desmarca um item de caixa de listagem em uma caixa de listagem de seleção múltipla.|  
|[CListBox::SetTabStops](#settabstops)|Define as posições de parada de tabulação em uma caixa de listagem.|  
|[CListBox::SetTopIndex](#settopindex)|Define o índice baseado em zero da primeira cadeia de caracteres visível em uma caixa de listagem.|  
|[CListBox::VKeyToItem](#vkeytoitem)|Substituição para fornecer personalizado `WM_KEYDOWN` tratamento de caixas de listagem com o **LBS_WANTKEYBOARDINPUT** conjunto de estilos.|  
  
## <a name="remarks"></a>Comentários  
 Uma caixa de listagem exibe uma lista de itens, como nomes de arquivos, o que o usuário pode exibir e selecionar.  
  
 Em uma caixa de listagem de seleção única, o usuário pode selecionar somente um item. Em uma caixa de listagem de seleção múltipla, um intervalo de itens pode ser selecionado. Quando o usuário seleciona um item, ele será realçado e a caixa de listagem envia uma mensagem de notificação para a janela pai.  
  
 Você pode criar uma caixa de listagem de um modelo de caixa de diálogo ou diretamente em seu código. Para criá-la diretamente, construir o `CListBox` do objeto e, em seguida, chamar o [criar](#create) a função de membro para criar o controle de caixa de listagem do Windows e anexá-lo para o `CListBox` objeto. Para usar uma caixa de listagem em um modelo de caixa de diálogo, declarar uma variável de caixa de listagem na sua classe de caixa de diálogo, em seguida, usar `DDX_Control` em sua classe de caixa de diálogo `DoDataExchange` função para conectar-se a variável de membro para o controle. (Isso é feito para você automaticamente quando você adicionar uma variável de controle para sua classe de caixa de diálogo.)  
  
 Construção pode ser um processo de uma etapa em uma classe derivada de `CListBox`. Escrever um construtor para a classe derivada e chamada **criar** de dentro do construtor.  
  
 Se você desejar tratar mensagens de notificação do Windows enviadas por uma caixa de listagem para seu pai (geralmente uma classe derivada de [CDialog](../../mfc/reference/cdialog-class.md)), adicionar uma função de membro de entrada e o manipulador de mensagens do mapa de mensagem para a classe pai para cada mensagem.  
  
 Cada entrada de mapa de mensagem assume o seguinte formato:  
  
 `ON_Notification( id, memberFxn )`  
  
 onde `id` Especifica a ID de janela filho do controle de caixa de listagem enviando a notificação e `memberFxn` é o nome da função de membro pai que você tenha escrito para manipular a notificação.  
  
 O protótipo de função do pai é o seguinte:  
  
 `afx_msg void memberFxn( );`  
  
 A seguir está uma lista de possíveis entradas de mapa de mensagem e uma descrição dos casos em que eles seriam enviados para o pai:  
  
- **ON_LBN_DBLCLK** o usuário clica duas vezes em uma cadeia de caracteres em uma caixa de listagem. Apenas uma caixa de listagem que tem o [LBS_NOTIFY](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) estilo enviará a mensagem de notificação.  
  
- **ON_LBN_ERRSPACE** a caixa de listagem não é possível alocar memória suficiente para atender à solicitação.  
  
- **ON_LBN_KILLFOCUS** a caixa de listagem está perdendo o foco de entrada.  
  
- **ON_LBN_SELCANCEL** a seleção atual da caixa de listagem é cancelada. Esta mensagem é enviada somente quando uma caixa de listagem tem o **LBS_NOTIFY** estilo.  
  
- **ON_LBN_SELCHANGE** a seleção na caixa de listagem é alterada. Essa notificação não é enviada se a seleção é alterada o [CListBox::SetCurSel](#setcursel) função de membro. Essa notificação se aplica somente a uma caixa de listagem que tem o **LBS_NOTIFY** estilo. O **LBN_SELCHANGE** mensagem de notificação é enviada para uma caixa de listagem de seleção múltipla sempre que o usuário pressiona uma tecla de direção, mesmo se a seleção não for alterada.  
  
- **ON_LBN_SETFOCUS** a caixa de listagem recebe o foco de entrada.  
  
- **ON_WM_CHARTOITEM** uma caixa de listagem do desenho proprietário com cadeias de caracteres não recebe um `WM_CHAR` mensagem.  
  
- **ON_WM_VKEYTOITEM** uma caixa de listagem com o **LBS_WANTKEYBOARDINPUT** estilo recebe um `WM_KEYDOWN` mensagem.  
  
 Se você criar um `CListBox` objeto dentro de uma caixa de diálogo (por meio de um recurso de caixa de diálogo), o `CListBox` objeto é destruído automaticamente quando o usuário fecha a caixa de diálogo.  
  
 Se você criar um `CListBox` objeto dentro de uma janela, talvez seja necessário destruir o `CListBox` objeto. Se você criar o `CListBox` do objeto na pilha, ele será destruído automaticamente. Se você criar o `CListBox` objeto na pilha usando o **novo** função, você deve chamar **excluir** sobre o objeto a ser destruída quando o usuário fecha a janela pai.  
  
 Se você alocar toda a memória no `CListBox` de objeto, substituir o `CListBox` destruidor de descartar a alocação.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CListBox`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
##  <a name="addstring"></a>  CListBox::AddString  
 Adiciona uma cadeia de caracteres para uma caixa de listagem.  
  
```  
int AddString(LPCTSTR lpszItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszItem`  
 Aponta para a cadeia de caracteres terminada em nulo que deve ser adicionado.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice com base em zero para a cadeia de caracteres na caixa de listagem. O valor de retorno é **LB_ERR** se ocorrer um erro; o valor de retorno é **LB_ERRSPACE** se houver espaço suficiente armazenar a nova cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Se a caixa de listagem não foi criada com o [LBS_SORT](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) estilo, a cadeia de caracteres é adicionada ao final da lista. Caso contrário, a cadeia de caracteres é inserida na lista, e a lista é classificada. Se a caixa de listagem foi criada com o **LBS_SORT** estilo mas não o [LBS_HASSTRINGS](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) estilo, a estrutura classifica a lista por um ou mais chamadas para o `CompareItem` função de membro.  
  
 Use [InsertString](#insertstring) para inserir uma cadeia de caracteres em um local específico na caixa de listagem.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#3](../../mfc/codesnippet/cpp/clistbox-class_1.cpp)]  
  
##  <a name="chartoitem"></a>  CListBox::CharToItem  
 Chamado pelo framework quando a janela do pai da caixa de listagem recebe um `WM_CHARTOITEM` mensagem na caixa de listagem.  
  
```  
virtual int CharToItem(
    UINT nKey,  
    UINT nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nKey`  
 O código ANSI do usuário caractere digitado.  
  
 `nIndex`  
 A posição atual do cursor de caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna - 1 ou - 2 para nenhuma outra ação ou um número não negativo para especificar um índice de um item de caixa de listagem na qual executar a ação padrão para o pressionamento de tecla. A implementação padrão retorna - 1.  
  
### <a name="remarks"></a>Comentários  
 O `WM_CHARTOITEM` mensagem é enviada pela caixa de listagem quando ele recebe um `WM_CHAR` mensagem, mas somente se a caixa de listagem atende a todos estes critérios:  
  
-   É uma caixa de listagem do desenho proprietário.  
  
-   Não tem o [LBS_HASSTRINGS](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) conjunto de estilos.  
  
-   Tem pelo menos um item.  
  
 Você nunca deve chamar essa função por conta própria. Substitua essa função para fornecer sua própria manipulação personalizada das mensagens de teclado.  
  
 Em sua substituição, você deve retornar um valor para informar o framework que ação executada. Um valor de retorno de - 1 ou - 2 indica que você tratados todos os aspectos de seleção do item e não requer nenhuma ação adicional pela caixa de listagem. Antes de retorná - 1 ou - 2, você pode definir a seleção ou mover o cursor ou ambos. Para definir a seleção, use [SetCurSel](#setcursel) ou [SetSel](#setsel). Para mover o cursor, use [SetCaretIndex](#setcaretindex).  
  
 Um valor de 0 ou maior retorno Especifica o índice de um item na caixa de listagem e indica que a caixa de listagem deve executar a ação padrão para pressionamento de tecla em um determinado item.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#4](../../mfc/codesnippet/cpp/clistbox-class_2.cpp)]  
  
##  <a name="clistbox"></a>  CListBox::CListBox  
 Constrói um objeto `CListBox`.  
  
```  
CListBox();
```  
  
### <a name="remarks"></a>Comentários  
 Você pode criar um `CListBox` objeto em duas etapas. Primeiro, chame o construtor **ClistBox** e, em seguida, chame **criar**, que inicia a caixa de listagem do Windows e anexa-o para o `CListBox`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#1](../../mfc/codesnippet/cpp/clistbox-class_3.cpp)]  
  
##  <a name="compareitem"></a>  CListBox::CompareItem  
 Chamado pelo framework para determinar a posição relativa de um novo item em uma caixa de listagem do desenho proprietário classificada.  
  
```  
virtual int CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpCompareItemStruct`  
 Um ponteiro de tempo para um `COMPAREITEMSTRUCT` estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Indica a posição relativa dos dois itens descritos no [COMPAREITEMSTRUCT](../../mfc/reference/compareitemstruct-structure.md) estrutura. Pode ser qualquer um dos seguintes valores:  
  
|Valor|Significado|  
|-----------|-------------|  
|-1|Item 1 classifica antes do item 2.|  
|0|Item 1 e item 2 classificados iguais.|  
|1|Item 1 classificado depois item 2.|  
  
 Consulte [CWnd::OnCompareItem](../../mfc/reference/cwnd-class.md#oncompareitem) para obter uma descrição de `COMPAREITEMSTRUCT` estrutura.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, essa função de membro não faz nada. Se você criar uma caixa de listagem do desenho proprietário com o **LBS_SORT** estilo, você deve substituir esta função de membro para ajudar a estrutura de classificação novos itens adicionados à caixa de listagem.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#5](../../mfc/codesnippet/cpp/clistbox-class_4.cpp)]  
  
##  <a name="create"></a>  CListBox::Create  
 Cria a caixa de listagem do Windows e a anexa ao `CListBox` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Especifica o estilo da caixa de listagem. Aplique qualquer combinação de [estilos de caixa de listagem](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) para a caixa.  
  
 `rect`  
 Especifica o tamanho da caixa de listagem e a posição. Pode ser um `CRect` objeto ou um `RECT` estrutura.  
  
 `pParentWnd`  
 Especifica a janela do pai da caixa de listagem (geralmente um `CDialog` objeto). Ele não deve ser **nulo**.  
  
 `nID`  
 Especifica a ID de controle. da caixa de listagem  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você pode criar um `CListBox` objeto em duas etapas. Primeiro, chame o construtor e, em seguida, chamar **criar**, que inicia a caixa de listagem do Windows e anexa-o para o `CListBox` objeto.  
  
 Quando **criar** executa o Windows envia o [WM_NCCREATE](../../mfc/reference/cwnd-class.md#onnccreate), [WM_CREATE](../../mfc/reference/cwnd-class.md#oncreate), [WM_NCCALCSIZE](../../mfc/reference/cwnd-class.md#onnccalcsize), e [WM _ GETMINMAXINFO](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) mensagens para o controle de caixa de listagem.  
  
 Essas mensagens são tratadas por padrão, o [OnNcCreate](../../mfc/reference/cwnd-class.md#onnccreate), [OnCreate](../../mfc/reference/cwnd-class.md#oncreate), [OnNcCalcSize](../../mfc/reference/cwnd-class.md#onnccalcsize), e [OnGetMinMaxInfo](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) funções de membro no `CWnd` classe base. Para estender a manipulação de mensagem padrão, derive uma classe de `CListBox`, adicione um mapa de mensagem para a nova classe e substituem as funções de membro anterior do manipulador de mensagens. Substituir `OnCreate`, por exemplo, para executar inicialização necessária para uma nova classe.  
  
 Aplicar o seguinte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) a um controle de caixa de listagem.  
  
- **Estilo** sempre  
  
- **WS_VISIBLE** normalmente  
  
- **WS_DISABLED** raramente  
  
- **WS_VSCROLL** para adicionar uma barra de rolagem vertical  
  
- **WS_HSCROLL** para adicionar uma barra de rolagem horizontal  
  
- **WS_GROUP** a controles de grupo  
  
- **WS_TABSTOP** para permitir a este controle de tabulação  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#2](../../mfc/codesnippet/cpp/clistbox-class_5.cpp)]  
  
##  <a name="deleteitem"></a>  CListBox::DeleteItem  
 Chamado pelo framework quando o usuário exclui um item de um desenho proprietário `CListBox` de objeto ou destrói a caixa de listagem.  
  
```  
virtual void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpDeleteItemStruct`  
 Um ponteiro longo para um Windows [DELETEITEMSTRUCT](../../mfc/reference/deleteitemstruct-structure.md) estrutura que contém informações sobre o item excluído.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função não faz nada. Substitua essa função para redesenhar uma caixa de listagem do desenho proprietário conforme necessário.  
  
 Consulte [CWnd::OnDeleteItem](../../mfc/reference/cwnd-class.md#ondeleteitem) para obter uma descrição de `DELETEITEMSTRUCT` estrutura.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#6](../../mfc/codesnippet/cpp/clistbox-class_6.cpp)]  
  
##  <a name="deletestring"></a>  CListBox::DeleteString  
 Exclui o item na posição `nIndex` na caixa de listagem.  
  
```  
int DeleteString(UINT nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice de base zero da cadeia de caracteres a ser excluído.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma contagem das cadeias de caracteres restantes na lista. O valor de retorno é **LB_ERR** se `nIndex` Especifica um índice maior que o número de itens na lista.  
  
### <a name="remarks"></a>Comentários  
 Todos os itens a seguir `nIndex` Agora mova uma posição para baixo. Por exemplo, se uma caixa de listagem contém dois itens, excluir o primeiro item fará com que o item restante ser agora na primeira posição. `nIndex`= 0 para o item na primeira posição.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#7](../../mfc/codesnippet/cpp/clistbox-class_7.cpp)]  
  
##  <a name="dir"></a>  CListBox::Dir  
 Adiciona uma lista de nomes de arquivos, unidades ou ambos para uma caixa de listagem.  
  
```  
int Dir(
    UINT attr,  
    LPCTSTR lpszWildCard);
```  
  
### <a name="parameters"></a>Parâmetros  
 `attr`  
 Pode ser qualquer combinação da `enum` valores descritos na **CFile::GetStatu**[s](../../mfc/reference/cfile-class.md#getstatus), ou qualquer combinação dos valores a seguir:  
  
|Valor|Significado|  
|-----------|-------------|  
|0x0000|Arquivo pode ser lido ou gravado.|  
|0x0001|Possível leiam mas não gravado no arquivo.|  
|0x0002|Arquivo está oculta e não aparecem em uma listagem de diretório.|  
|0x0004|É um arquivo de sistema.|  
|0x0010|O nome especificado pelo `lpszWildCard` Especifica um diretório.|  
|0x0020|Arquivo foi arquivado.|  
|0x4000|Incluir todas as unidades que correspondem ao nome especificado pelo `lpszWildCard`.|  
|0x8000|Sinalizador exclusivo. Se o sinalizador exclusive for definido, somente os arquivos do tipo especificado são listados. Caso contrário, os arquivos do tipo especificado são listados além de arquivos "normais".|  
  
 `lpszWildCard`  
 Aponta para uma cadeia de caracteres de especificação de arquivo. A cadeia de caracteres pode conter caracteres curinga (por exemplo, *.\*).  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de base zero do último nome de arquivo adicionado à lista. O valor de retorno é **LB_ERR** se ocorrer um erro; o valor de retorno é **LB_ERRSPACE** se houver espaço suficiente disponível para armazenar as cadeias de caracteres de nova.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#8](../../mfc/codesnippet/cpp/clistbox-class_8.cpp)]  
  
##  <a name="drawitem"></a>  CListBox::DrawItem  
 Chamado pelo framework quando um aspecto visual de uma caixa de listagem do desenho proprietário mude.  
  
```  
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpDrawItemStruct`  
 Um ponteiro de tempo para um [DRAWITEMSTRUCT](../../mfc/reference/drawitemstruct-structure.md) estrutura que contém informações sobre o tipo de desenho necessárias.  
  
### <a name="remarks"></a>Comentários  
 O **itemAction** e **itemState** membros o `DRAWITEMSTRUCT` estrutura define a ação de desenho que deve ser executada.  
  
 Por padrão, essa função de membro não faz nada. Substituir essa função de membro para implementar o desenho de um desenho proprietário `CListBox` objeto. O aplicativo deve restaurar todos os objetos de interface (GDI) do dispositivo gráficos selecionados para o contexto de exibição fornecido no `lpDrawItemStruct` antes desse membro função termina.  
  
 Consulte [CWnd::OnDrawItem](../../mfc/reference/cwnd-class.md#ondrawitem) para obter uma descrição de `DRAWITEMSTRUCT` estrutura.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#9](../../mfc/codesnippet/cpp/clistbox-class_9.cpp)]  
  
##  <a name="findstring"></a>  CListBox:: FindString  
 Localiza a primeira cadeia de caracteres em uma caixa de lista que contém o prefixo especificado sem alterar a seleção da caixa de listagem.  
  
```  
int FindString(
    int nStartAfter,  
    LPCTSTR lpszItem) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nStartAfter`  
 Contém o índice de base zero do item antes do primeiro item a ser pesquisada. Quando a pesquisa alcançar a parte inferior da caixa de listagem, ele continua na parte superior da caixa de listagem para o item especificado pela `nStartAfter`. Se `nStartAfter` é -1, a caixa de listagem inteiro é pesquisada desde o início.  
  
 `lpszItem`  
 Aponta para a cadeia de caracteres terminada em nulo que contém o prefixo a ser pesquisado. A pesquisa é o caso independente, para que essa cadeia de caracteres pode conter qualquer combinação de letras maiusculas e minúsculas.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de base zero do item correspondente, ou **LB_ERR** se a pesquisa não foi bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 Use o [SelectString](#selectstring) a função de membro para localizar e selecionar uma cadeia de caracteres.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#10](../../mfc/codesnippet/cpp/clistbox-class_10.cpp)]  
  
##  <a name="findstringexact"></a>  CListBox::FindStringExact  
 Localiza a primeira cadeia de caixa de listagem que corresponde à cadeia especificada no `lpszFind`.  
  
```  
int FindStringExact(
    int nIndexStart,  
    LPCTSTR lpszFind) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndexStart`  
 Especifica o índice de base zero do item antes do primeiro item a ser pesquisada. Quando a pesquisa alcançar a parte inferior da caixa de listagem, ele continua na parte superior da caixa de listagem para o item especificado pela `nIndexStart`. Se `nIndexStart` é -1, a caixa de listagem inteiro é pesquisada desde o início.  
  
 `lpszFind`  
 Aponta para a cadeia de caracteres terminada em nulo para pesquisar. Essa cadeia de caracteres pode conter um nome de arquivo completo, incluindo a extensão. A pesquisa não diferencia maiusculas de minúsculas, portanto a cadeia de caracteres pode conter qualquer combinação de letras maiusculas e minúsculas.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do item correspondente, ou **LB_ERR** se a pesquisa não foi bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 Se a caixa de listagem foi criada com um estilo de desenho do proprietário, mas sem o [LBS_HASSTRINGS](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) estilo, o `FindStringExact` função membro tenta corresponder o valor doubleword em relação ao valor de `lpszFind`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#11](../../mfc/codesnippet/cpp/clistbox-class_11.cpp)]  
  
##  <a name="getanchorindex"></a>  CListBox::GetAnchorIndex  
 Recupera o índice com base em zero do item atual âncora na caixa de listagem.  
  
```  
int GetAnchorIndex() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do item de âncora atual, se for bem-sucedida; Caso contrário, **LB_ERR**.  
  
### <a name="remarks"></a>Comentários  
 Em uma caixa de listagem de seleção múltipla, o item de ancoragem é o primeiro ou último item em um bloco de contíguos itens selecionados.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CListBox::SetAnchorIndex](#setanchorindex).  
  
##  <a name="getcaretindex"></a>  CListBox::GetCaretIndex  
 Determina o índice do item que tem o foco do retângulo em uma caixa de listagem de seleção múltipla.  
  
```  
int GetCaretIndex() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de base zero do item que tem o foco do retângulo em uma caixa de listagem. Se a caixa de listagem é uma caixa de listagem de seleção única, o valor de retorno é o índice do item selecionado, se houver.  
  
### <a name="remarks"></a>Comentários  
 O item pode ou não pode ser selecionado.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CListBox::SetCaretIndex](#setcaretindex).  
  
##  <a name="getcount"></a>  CListBox::GetCount  
 Recupera o número de itens em uma caixa de listagem.  
  
```  
int GetCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens na caixa de listagem, ou **LB_ERR** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 A contagem é maior do que o valor de índice do último item (o índice é baseado em zero).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#12](../../mfc/codesnippet/cpp/clistbox-class_12.cpp)]  
  
##  <a name="getcursel"></a>  CListBox::GetCurSel  
 Recupera o índice com base em zero do item selecionado no momento, se houver, em uma caixa de listagem de seleção única.  
  
```  
int GetCurSel() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de base zero do item selecionado no momento se ele for uma caixa de listagem de seleção única. É `LB_ERR` se nenhum item atualmente selecionado.  
  
 Em uma caixa de listagem de seleção múltipla, o índice do item que tem o foco.  
  
### <a name="remarks"></a>Comentários  
 Não chame `GetCurSel` para uma caixa de listagem de seleção múltipla. Use [CListBox::GetSelItems](#getselitems) em vez disso.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#13](../../mfc/codesnippet/cpp/clistbox-class_13.cpp)]  
  
##  <a name="gethorizontalextent"></a>  CListBox::GetHorizontalExtent  
 Recupera a largura em pixels por que ele pode ser rolado horizontalmente na caixa de listagem.  
  
```  
int GetHorizontalExtent() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A largura rolável da caixa de listagem, em pixels.  
  
### <a name="remarks"></a>Comentários  
 Isso é aplicável somente se a caixa de listagem tem uma barra de rolagem horizontal.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#14](../../mfc/codesnippet/cpp/clistbox-class_14.cpp)]  
  
##  <a name="getitemdata"></a>  CListBox::GetItemData  
 Recupera o valor de doubleword fornecidas pelo aplicativo associado ao item de caixa de lista especificado.  
  
```  
DWORD_PTR GetItemData(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice de base zero do item na caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de 32 bits associado ao item ou **LB_ERR** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 O valor de doubleword era o `dwItemData` parâmetro de um [SetItemData](#setitemdata) chamar.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#15](../../mfc/codesnippet/cpp/clistbox-class_15.cpp)]  
  
##  <a name="getitemdataptr"></a>  CListBox::GetItemDataPtr  
 Recupera o valor de 32 bits fornecido pelo aplicativo associado ao item de caixa de listagem especificado como um ponteiro ( **void\***).  
  
```  
void* GetItemDataPtr(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice de base zero do item na caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Recupera um ponteiro ou -1 se ocorrer um erro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#16](../../mfc/codesnippet/cpp/clistbox-class_16.cpp)]  
  
##  <a name="getitemheight"></a>  CListBox::GetItemHeight  
 Determina a altura dos itens em uma caixa de listagem.  
  
```  
int GetItemHeight(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice de base zero do item na caixa de listagem. Esse parâmetro é usado somente se a caixa de listagem tem o **LBS_OWNERDRAWVARIABLE** estilo; caso contrário, ele deve ser definido como 0.  
  
### <a name="return-value"></a>Valor de retorno  
 A altura, em pixels, dos itens na caixa de listagem. Se a caixa de listagem tem o [LBS_OWNERDRAWVARIABLE](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) estilo, o valor de retorno é a altura do item especificado por `nIndex`. Se ocorrer um erro, o valor de retorno é **LB_ERR**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#17](../../mfc/codesnippet/cpp/clistbox-class_17.cpp)]  
  
##  <a name="getitemrect"></a>  CListBox::GetItemRect  
 Recupera as dimensões do retângulo item dos limites de uma caixa de listagem que atualmente é exibida na janela de caixa de listagem.  
  
```  
int GetItemRect(
    int nIndex,  
    LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice de base zero do item.  
  
 `lpRect`  
 Especifica um ponteiro longo para um [estrutura RECT](../../mfc/reference/rect-structure1.md) que recebe as coordenadas do cliente de caixa de listagem do item.  
  
### <a name="return-value"></a>Valor de retorno  
 **LB_ERR** se ocorrer um erro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#18](../../mfc/codesnippet/cpp/clistbox-class_18.cpp)]  
  
##  <a name="getlistboxinfo"></a>  CListBox::GetListBoxInfo  
 Recupera o número de itens por coluna.  
  
```  
DWORD GetListBoxInfo() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Número de itens por coluna o `CListBox` objeto.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro emula a funcionalidade do [LB_GETLISTBOXINFO](http://msdn.microsoft.com/library/windows/desktop/bb775208) mensagem, conforme descrito no SDK do Windows.  
  
##  <a name="getlocale"></a>  CListBox::GetLocale  
 Recupera a localidade usada pela caixa de listagem.  
  
```  
LCID GetLocale() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor LCID (identificador) da localidade para cadeias de caracteres na caixa de listagem.  
  
### <a name="remarks"></a>Comentários  
 A localidade é usada, por exemplo, para determinar a ordem de classificação de cadeias de caracteres em uma caixa de lista classificada.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CListBox::SetLocale](#setlocale).  
  
##  <a name="getsel"></a>  CListBox::GetSel  
 Recupera o estado de seleção de um item.  
  
```  
int GetSel(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice de base zero do item.  
  
### <a name="return-value"></a>Valor de retorno  
 Um número positivo se o item especificado está selecionado. Caso contrário, é 0. O valor de retorno é `LB_ERR` se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro funciona com ambas as caixas de listagem de seleção única e vários.  
  
 Para recuperar o índice do item de caixa de lista selecionado no momento, use [CListBox::GetCurSel](#getcursel).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#19](../../mfc/codesnippet/cpp/clistbox-class_19.cpp)]  
  
##  <a name="getselcount"></a>  CListBox::GetSelCount  
 Recupera o número total de itens selecionados em uma caixa de listagem de seleção múltipla.  
  
```  
int GetSelCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A contagem de itens selecionados em uma caixa de listagem. Se a caixa de listagem é uma caixa de listagem de seleção única, o valor de retorno é **LB_ERR**.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CListBox::GetSelItems](#getselitems).  
  
##  <a name="getselitems"></a>  CListBox::GetSelItems  
 Um buffer é preenchido com uma matriz de inteiros que especifica os números de item dos itens selecionados em uma caixa de listagem de seleção múltipla.  
  
```  
int GetSelItems(
    int nMaxItems,  
    LPINT rgIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMaxItems`  
 Especifica o número máximo de itens selecionados cujos números de itens devem ser colocados no buffer.  
  
 `rgIndex`  
 Especifica um ponteiro para um buffer grande o suficiente para o número de inteiros especificado pelo `nMaxItems`.  
  
### <a name="return-value"></a>Valor de retorno  
 O número real de itens colocados no buffer. Se a caixa de listagem é uma caixa de listagem de seleção única, o valor de retorno é `LB_ERR`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#20](../../mfc/codesnippet/cpp/clistbox-class_20.cpp)]  
  
##  <a name="gettext"></a>  CListBox::GetText  
 Obtém uma cadeia de caracteres de uma caixa de listagem.  
  
```  
int GetText(
    int nIndex,  
    LPTSTR lpszBuffer) const;  
  
void GetText(
    int nIndex,  
    CString& rString) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice de base zero da cadeia de caracteres a ser recuperado.  
  
 `lpszBuffer`  
 Aponta para o buffer que recebe a cadeia de caracteres. O buffer deve ter espaço suficiente para a cadeia de caracteres e um caractere null de terminação. O tamanho da cadeia de caracteres pode ser determinado antecipadamente chamando o `GetTextLen` função de membro.  
  
 `rString`  
 Uma referência a um objeto `CString`.  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento (em bytes) da cadeia de caracteres, excluindo o caractere null de terminação. Se `nIndex` não especifica um índice válido, o valor de retorno é **LB_ERR**.  
  
### <a name="remarks"></a>Comentários  
 O segundo formulário desse membro da função preenchimentos um `CString` objeto com o texto de cadeia de caracteres.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#21](../../mfc/codesnippet/cpp/clistbox-class_21.cpp)]  
  
##  <a name="gettextlen"></a>  CListBox::GetTextLen  
 Obtém o comprimento de uma cadeia de caracteres em um item de caixa de listagem.  
  
```  
int GetTextLen(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice de base zero da cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento da cadeia de caracteres em caracteres, excluindo o caractere null de terminação. Se `nIndex` não especifica um índice válido, o valor de retorno é **LB_ERR**.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CListBox::GetText](#gettext).  
  
##  <a name="gettopindex"></a>  CListBox::GetTopIndex  
 Recupera o índice com base em zero do primeiro item visível em uma caixa de listagem.  
  
```  
int GetTopIndex() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de base zero do primeiro item visível em uma caixa de listagem se for bem-sucedido, **LB_ERR** caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Inicialmente, o item 0 está na parte superior da caixa de listagem, mas se a caixa de listagem é rolada, outro item pode estar no topo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#22](../../mfc/codesnippet/cpp/clistbox-class_22.cpp)]  
  
##  <a name="initstorage"></a>  CListBox::InitStorage  
 Aloca memória para armazenar itens de caixa de listagem.  
  
```  
int InitStorage(
    int nItems,  
    UINT nBytes);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nItems`  
 Especifica o número de itens a serem adicionados.  
  
 `nBytes`  
 Especifica a quantidade de memória, em bytes, para alocar para cadeias de caracteres do item.  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, o número máximo de itens que a caixa de listagem pode armazenar antes de uma realocação de memória é necessária, caso contrário, **LB_ERRSPACE**, que significa que não há memória suficiente está disponível.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função antes de adicionar um grande número de itens a um `CListBox`.  
  
 Essa função ajuda a acelerar a inicialização das caixas de listagem que têm um grande número de itens (mais de 100). Ele preallocates a quantidade especificada de memória subsequente assim que [AddString](#addstring), [InsertString](#insertstring), e [Dir](#dir) funções usam o menor tempo possível. Você pode usar estimativas para os parâmetros. Se você superestimar, é alocada memória extra; Se você subestimar, a alocação normal é usada para itens que excedem a quantidade pré-alocados.  
  
 Windows 95/98 somente: O `nItems` parâmetro é limitado a valores de 16 bits. Isso significa que caixas de listagem não podem conter mais de 32.767 itens. Embora o número de itens é restrito, o tamanho total dos itens em uma caixa de listagem é limitado apenas pela memória disponível.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#23](../../mfc/codesnippet/cpp/clistbox-class_23.cpp)]  
  
##  <a name="insertstring"></a>  CListBox::InsertString  
 Insere uma cadeia de caracteres na caixa de listagem.  
  
```  
int InsertString(
    int nIndex,  
    LPCTSTR lpszItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice com base em zero da posição para inserir a cadeia de caracteres. Se esse parâmetro for -1, a cadeia de caracteres é adicionada ao final da lista.  
  
 `lpszItem`  
 Aponta para a cadeia de caracteres terminada em nulo que deve ser inserido.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero da posição em que a cadeia de caracteres foi inserida. O valor de retorno é **LB_ERR** se ocorrer um erro; o valor de retorno é **LB_ERRSPACE** se houver espaço suficiente armazenar a nova cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Ao contrário de [AddString](#addstring) função de membro, `InsertString` não faz com que uma lista com o [LBS_SORT](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) estilo a ser classificada.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#24](../../mfc/codesnippet/cpp/clistbox-class_24.cpp)]  
  
##  <a name="itemfrompoint"></a>  CListBox::ItemFromPoint  
 Determina o item de caixa de listagem mais próximo ponto especificado em `pt`.  
  
```  
UINT ItemFromPoint(
    CPoint pt,  
    BOOL& bOutside) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pt`  
 Ponto localizar o item mais próximo, especificado em relação ao canto superior esquerdo da área cliente da caixa de listagem.  
  
 `bOutside`  
 Referência a um `BOOL` variável que será definido como `TRUE` se `pt` está fora da área cliente de item de caixa de listagem mais próximo, `FALSE` se `pt` está dentro da área cliente do item da caixa de lista mais próximo.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do item mais próximo para o ponto especificado em `pt`.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar essa função para determinar qual item de caixa de listagem o cursor do mouse se move sobre.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CListBox::SetAnchorIndex](#setanchorindex).  
  
##  <a name="measureitem"></a>  CListBox::MeasureItem  
 Chamado pelo framework quando uma caixa de listagem com um estilo de desenho proprietário é criada.  
  
```  
virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpMeasureItemStruct`  
 Um ponteiro de tempo para um [MEASUREITEMSTRUCT](../../mfc/reference/measureitemstruct-structure.md) estrutura.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, essa função de membro não faz nada. Substituir essa função de membro e preencha o `MEASUREITEMSTRUCT` estrutura para informar ao Windows as dimensões da caixa de listagem. Se a caixa de listagem é criada com o [LBS_OWNERDRAWVARIABLE](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) estilo, o framework chama esta função de membro para cada item na caixa de listagem. Caso contrário, esse membro é chamado apenas uma vez.  
  
 Para obter mais informações sobre como usar o [LBS_OWNERDRAWFIXED](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) estilo em uma caixa de listagem do desenho proprietário criado com o `SubclassDlgItem` função membro de `CWnd`, consulte a discussão na [14 de observação técnica](../../mfc/tn014-custom-controls.md).  
  
 Consulte [CWnd::OnMeasureItem](../../mfc/reference/cwnd-class.md#onmeasureitem) para obter uma descrição de `MEASUREITEMSTRUCT` estrutura **.**  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#25](../../mfc/codesnippet/cpp/clistbox-class_25.cpp)]  
  
##  <a name="resetcontent"></a>  CListBox::ResetContent  
 Remove todos os itens de uma caixa de listagem.  
  
```  
void ResetContent();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#26](../../mfc/codesnippet/cpp/clistbox-class_26.cpp)]  
  
##  <a name="selectstring"></a>  CListBox::SelectString  
 Pesquisas em um item de caixa de listagem que coincide com a cadeia de caracteres especificada e, se um item correspondente for encontrado, ele seleciona o item.  
  
```  
int SelectString(
    int nStartAfter,  
    LPCTSTR lpszItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nStartAfter`  
 Contém o índice de base zero do item antes do primeiro item a ser pesquisada. Quando a pesquisa alcançar a parte inferior da caixa de listagem, ele continua na parte superior da caixa de listagem para o item especificado pela `nStartAfter`. Se `nStartAfter` é -1, a caixa de listagem inteiro é pesquisada desde o início.  
  
 `lpszItem`  
 Aponta para a cadeia de caracteres terminada em nulo que contém o prefixo a ser pesquisado. A pesquisa é o caso independente, para que essa cadeia de caracteres pode conter qualquer combinação de letras maiusculas e minúsculas.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do item selecionado se a pesquisa foi bem-sucedida. Se a pesquisa tiver êxito, o valor de retorno é **LB_ERR** e a seleção atual não é alterada.  
  
### <a name="remarks"></a>Comentários  
 A caixa de listagem é rolada, se necessário, para colocar o item selecionado no modo de exibição.  
  
 Essa função de membro não pode ser usada com uma caixa de listagem que tem o [LBS_MULTIPLESEL](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) estilo.  
  
 Um item é selecionado apenas se seu caracteres inicias (do ponto de partida) corresponder aos caracteres na cadeia de caracteres especificado por `lpszItem`.  
  
 Use o `FindString` a função de membro para localizar uma cadeia de caracteres sem selecionar o item.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#27](../../mfc/codesnippet/cpp/clistbox-class_27.cpp)]  
  
##  <a name="selitemrange"></a>  CListBox::SelItemRange  
 Selecionar vários itens consecutivos em uma caixa de listagem de seleção múltipla.  
  
```  
int SelItemRange(
    BOOL bSelect,  
    int nFirstItem,  
    int nLastItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bSelect`  
 Especifica como definir a seleção. Se `bSelect` é **TRUE**, a cadeia de caracteres está selecionada e realçada; se **FALSE**, o realce será removido e a cadeia de caracteres não está selecionada.  
  
 `nFirstItem`  
 Especifica o índice de base zero do primeiro item a ser definido.  
  
 `nLastItem`  
 Especifica o índice de base zero do último item para definir.  
  
### <a name="return-value"></a>Valor de retorno  
 **LB_ERR** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Use esta função de membro somente com caixas de listagem de seleção múltipla. Se você precisa selecionar apenas um item em uma caixa de listagem de seleção múltipla — ou seja, se `nFirstItem` é igual a `nLastItem` — chamar o [SetSel](#setsel) função de membro em vez disso.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#28](../../mfc/codesnippet/cpp/clistbox-class_28.cpp)]  
  
##  <a name="setanchorindex"></a>  CListBox::SetAnchorIndex  
 Define a âncora em uma caixa de listagem de seleção múltipla para começar uma seleção estendida.  
  
```  
void SetAnchorIndex(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice de base zero do item de caixa de listagem que será a âncora.  
  
### <a name="remarks"></a>Comentários  
 Em uma caixa de listagem de seleção múltipla, o item de ancoragem é o primeiro ou último item em um bloco de contíguos itens selecionados.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#29](../../mfc/codesnippet/cpp/clistbox-class_29.cpp)]  
  
##  <a name="setcaretindex"></a>  CListBox::SetCaretIndex  
 Define o retângulo de foco para o item no índice especificado em uma caixa de listagem de seleção múltipla.  
  
```  
int SetCaretIndex(
    int nIndex,  
    BOOL bScroll = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice de base zero do item para receber o retângulo de foco na caixa de listagem.  
  
 *bScroll*  
 Se esse valor for 0, o item será rolado até que ela esteja totalmente visível. Se esse valor não for 0, o item é rolado até que seja pelo menos parcialmente visível.  
  
### <a name="return-value"></a>Valor de retorno  
 **LB_ERR** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Se o item não estiver visível, ela é colocada na exibição.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#30](../../mfc/codesnippet/cpp/clistbox-class_30.cpp)]  
  
##  <a name="setcolumnwidth"></a>  CListBox::SetColumnWidth  
 Define a largura em pixels de todas as colunas em uma caixa de listagem de várias colunas (criado com o [LBS_MULTICOLUMN](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) estilo).  
  
```  
void SetColumnWidth(int cxWidth);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cxWidth`  
 Especifica a largura em pixels de todas as colunas.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#31](../../mfc/codesnippet/cpp/clistbox-class_31.cpp)]  
  
##  <a name="setcursel"></a>  CListBox::SetCurSel  
 Seleciona uma cadeia de caracteres e rola-lo no modo de exibição, se necessário.  
  
```  
int SetCurSel(int nSelect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSelect`  
 Especifica o índice de base zero da cadeia de caracteres a ser selecionado. Se `nSelect` é -1, a caixa de listagem é definida para não ter nenhuma seleção.  
  
### <a name="return-value"></a>Valor de retorno  
 `LB_ERR` Se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Quando a nova cadeia de caracteres é selecionada, a caixa de listagem remove o realce a cadeia de caracteres selecionada anteriormente.  
  
 Use esta função de membro somente com caixas de listagem de seleção única.  
  
 Para definir ou remover uma seleção em uma caixa de listagem de seleção múltipla, use [CListBox::SetSel](#setsel).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#32](../../mfc/codesnippet/cpp/clistbox-class_32.cpp)]  
  
##  <a name="sethorizontalextent"></a>  CListBox::SetHorizontalExtent  
 Define a largura, em pixels, pelo qual uma caixa de listagem pode ser rolada horizontalmente.  
  
```  
void SetHorizontalExtent(int cxExtent);
```  
  
### <a name="parameters"></a>Parâmetros  
 *cxExtent*  
 Especifica o número de pixels por que a caixa de listagem pode ser rolada horizontalmente.  
  
### <a name="remarks"></a>Comentários  
 Se o tamanho da caixa de listagem é menor do que esse valor, a barra de rolagem horizontal rolar horizontalmente itens na caixa de listagem. Se a caixa de listagem é tão grande ou maior que esse valor, a barra de rolagem horizontal está oculta.  
  
 Para responder a uma chamada para `SetHorizontalExtent`, a caixa de listagem deve ter sido definida com o [WS_HSCROLL](../../mfc/reference/styles-used-by-mfc.md#window-styles) estilo.  
  
 Essa função de membro não é útil para caixas de listagem de várias colunas. Para caixas de listagem de várias colunas, chame o `SetColumnWidth` função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#33](../../mfc/codesnippet/cpp/clistbox-class_33.cpp)]  
  
##  <a name="setitemdata"></a>  CListBox::SetItemData  
 Define um valor de 32 bits associado com o item especificado em uma caixa de listagem.  
  
```  
int SetItemData(
    int nIndex,  
    DWORD_PTR dwItemData);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice de base zero do item.  
  
 `dwItemData`  
 Especifica o valor a ser associado ao item.  
  
### <a name="return-value"></a>Valor de retorno  
 **LB_ERR** se ocorrer um erro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#34](../../mfc/codesnippet/cpp/clistbox-class_34.cpp)]  
  
##  <a name="setitemdataptr"></a>  CListBox::SetItemDataPtr  
 Define o valor de 32 bits associado com o item especificado em uma caixa de lista para ser o ponteiro especificado ( **void\***).  
  
```  
int SetItemDataPtr(
    int nIndex,  
    void* pData);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice de base zero do item.  
  
 `pData`  
 Especifica o ponteiro para ser associado ao item.  
  
### <a name="return-value"></a>Valor de retorno  
 **LB_ERR** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Este ponteiro permanece válido durante a vida útil da caixa de listagem, mesmo que a posição relativa do item dentro da caixa de lista pode alterar como os itens são adicionados ou removidos. Portanto, pode alterar o índice do item dentro da caixa, mas o ponteiro permanece confiável.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#35](../../mfc/codesnippet/cpp/clistbox-class_35.cpp)]  
  
##  <a name="setitemheight"></a>  CListBox::SetItemHeight  
 Define a altura dos itens em uma caixa de listagem.  
  
```  
int SetItemHeight(
    int nIndex,  
    UINT cyItemHeight);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice de base zero do item na caixa de listagem. Esse parâmetro é usado somente se a caixa de listagem tem o **LBS_OWNERDRAWVARIABLE** estilo; caso contrário, ele deve ser definido como 0.  
  
 `cyItemHeight`  
 Especifica a altura, em pixels, do item.  
  
### <a name="return-value"></a>Valor de retorno  
 **LB_ERR** se o índice ou a altura é inválida.  
  
### <a name="remarks"></a>Comentários  
 Se a caixa de listagem tem o [LBS_OWNERDRAWVARIABLE](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) estilo, essa função define a altura do item especificado por `nIndex`. Caso contrário, essa função define a altura de todos os itens na caixa de listagem.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#36](../../mfc/codesnippet/cpp/clistbox-class_36.cpp)]  
  
##  <a name="setlocale"></a>  CListBox::SetLocale  
 Define o identificador de localidade para essa caixa de listagem.  
  
```  
LCID SetLocale(LCID nNewLocale);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nNewLocale`  
 O novo valor LCID (identificador) de localidade a ser definido para a caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor LCID (identificador) localidade anterior para essa caixa de listagem.  
  
### <a name="remarks"></a>Comentários  
 Se **SetLocale** não for chamado, o padrão é obtida localidade do sistema. Esse local padrão do sistema pode ser modificado por meio do painel de controle de aplicativo regionais (ou internacional).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#37](../../mfc/codesnippet/cpp/clistbox-class_37.cpp)]  
  
##  <a name="setsel"></a>  CListBox::SetSel  
 Seleciona uma cadeia de caracteres em uma caixa de listagem de seleção múltipla.  
  
```  
int SetSel(
    int nIndex,  
    BOOL bSelect = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Contém o índice de base zero da cadeia de caracteres a ser definido. Se -1, a seleção é adicionada ou removida de todas as cadeias de caracteres, dependendo do valor de `bSelect`.  
  
 `bSelect`  
 Especifica como definir a seleção. Se `bSelect` é `TRUE`, a cadeia de caracteres está selecionada e realçada; se `FALSE`, o realce será removido e a cadeia de caracteres não está selecionada. A cadeia de caracteres especificada está selecionada e realçada por padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 `LB_ERR` Se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Use esta função de membro somente com caixas de listagem de seleção múltipla.  
  
 Para selecionar um item de uma caixa de listagem de seleção única, use [CListBox::SetCurSel](#setcursel).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#38](../../mfc/codesnippet/cpp/clistbox-class_38.cpp)]  
  
##  <a name="settabstops"></a>  CListBox::SetTabStops  
 Define as posições de parada de tabulação em uma caixa de listagem.  
  
```  
void SetTabStops();  
BOOL SetTabStops(const int& cxEachStop);

 
BOOL SetTabStops(
    int nTabStops,  
    LPINT rgTabStops);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cxEachStop`  
 Paradas de tabulação são definidas em cada `cxEachStop` unidades de diálogo. Consulte *rgTabStops* para obter uma descrição de uma unidade de caixa de diálogo.  
  
 `nTabStops`  
 Especifica o número de paradas de tabulação ter na caixa de listagem.  
  
 `rgTabStops`  
 Aponta para o primeiro membro de uma matriz de inteiros que contém as posições de parada de tabulação em unidades de diálogo. Uma unidade de diálogo é uma distância horizontal ou vertical. Uma unidade de diálogo horizontal é igual a um quarto da unidade de largura de base da caixa de diálogo atual e uma unidade de diálogo vertical é igual a um oitavo da unidade de base altura da caixa de diálogo atual. As unidades de base da caixa de diálogo são calculadas com base na altura e largura da fonte atual do sistema. O **GetDialogBaseUnits** função Windows retorna a caixa de diálogo atual unidades base em pixels. As paradas de tabulação devem ser classificadas em ordem; crescente guias de backup não são permitidos.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se todas as guias foram definidas; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para definir paradas de tabulação para o tamanho padrão de 2 unidades de caixa de diálogo, chame a versão para essa função de membro. Para definir paradas de tabulação para um tamanho diferente de 2, chame a versão com o `cxEachStop` argumento.  
  
 Para definir paradas de tabulação para uma matriz de tamanhos, use a versão com o `rgTabStops` e `nTabStops` argumentos. Uma parada de tabulação será definida para cada valor na `rgTabStops`, até o número especificado por `nTabStops`.  
  
 Para responder a uma chamada para o `SetTabStops` função de membro, a caixa de listagem deve ter sido criada com o [LBS_USETABSTOPS](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) estilo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#39](../../mfc/codesnippet/cpp/clistbox-class_39.cpp)]  
  
##  <a name="settopindex"></a>  CListBox::SetTopIndex  
 Garante que um item de caixa de listagem específico está visível.  
  
```  
int SetTopIndex(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice de base zero do item de caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Zero se tiver êxito, ou **LB_ERR** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 O sistema rola a caixa de listagem até que o item especificado pelo `nIndex` aparece na parte superior da lista de caixa ou o intervalo de rolagem máximo foi atingido.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#40](../../mfc/codesnippet/cpp/clistbox-class_40.cpp)]  
  
##  <a name="vkeytoitem"></a>  CListBox::VKeyToItem  
 Chamado pelo framework quando a janela do pai da caixa de listagem recebe um `WM_VKEYTOITEM` mensagem na caixa de listagem.  
  
```  
virtual int VKeyToItem(
    UINT nKey,  
    UINT nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nKey`  
 O código de tecla virtual da chave que o usuário pressionou. Para obter uma lista de códigos de tecla virtuais padrão, consulte WinUser  
  
 `nIndex`  
 A posição atual do cursor de caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna - 2 para nenhuma outra ação, - 1 para a ação padrão ou um número não negativo para especificar um índice de um item de caixa de listagem na qual executar a ação padrão para o pressionamento de tecla.  
  
### <a name="remarks"></a>Comentários  
 O `WM_VKEYTOITEM` mensagem é enviada pela caixa de listagem quando ele recebe um `WM_KEYDOWN` mensagem, mas somente se a caixa de listagem atende as seguintes:  
  
-   Tem o [LBS_WANTKEYBOARDINPUT](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) conjunto de estilos.  
  
-   Tem pelo menos um item.  
  
 Você nunca deve chamar essa função por conta própria. Substitua essa função para fornecer sua própria manipulação personalizada das mensagens de teclado.  
  
 Você deve retornar um valor para informar o framework ação executada sua substituição. Um valor de retorno de - 2 indica que o aplicativo tratados todos os aspectos de seleção do item e não requer nenhuma ação adicional pela caixa de listagem. Retornando antes - 2, você pode definir a seleção ou mover o cursor ou ambos. Para definir a seleção, use [SetCurSel](#setcursel) ou [SetSel](#setsel). Para mover o cursor, use [SetCaretIndex](#setcaretindex).  
  
 Um valor de retorno de - 1 indica que a caixa de listagem deve realizar a ação padrão em resposta ao pressionamento de tecla. A implementação padrão retorna - 1.  
  
 Um valor de 0 ou maior retorno Especifica o índice de um item na caixa de listagem e indica que a caixa de listagem deve executar a ação padrão para pressionamento de tecla em um determinado item.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox#41](../../mfc/codesnippet/cpp/clistbox-class_41.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC CTRLTEST](../../visual-cpp-samples.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Classe CButton](../../mfc/reference/cbutton-class.md)   
 [Classe CComboBox](../../mfc/reference/ccombobox-class.md)   
 [Classe CEdit](../../mfc/reference/cedit-class.md)   
 [Classe CScrollBar](../../mfc/reference/cscrollbar-class.md)   
 [Classe CStatic](../../mfc/reference/cstatic-class.md)
