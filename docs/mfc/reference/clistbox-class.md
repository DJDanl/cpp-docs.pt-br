---
title: Classe CListBox | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CListBox
dev_langs:
- C++
helpviewer_keywords:
- CListBox class
- list boxes
ms.assetid: 7ba3c699-c286-4cd9-9066-532c41ec05d1
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
ms.openlocfilehash: f4df970f2df35d399c0c700cf504a76482ad3f6d
ms.lasthandoff: 02/25/2017

---
# <a name="clistbox-class"></a>Classe CListBox
Fornece a funcionalidade de uma caixa de listagem do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CListBox : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CListBox::CListBox](#clistbox)|Constrói um objeto `CListBox`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CListBox::AddString](#addstring)|Adiciona uma cadeia de caracteres para uma caixa de listagem.|  
|[CListBox::CharToItem](#chartoitem)|Substituição para fornecer personalizado `WM_CHAR` tratamento para caixas de listagem de desenho proprietário que não têm cadeias de caracteres.|  
|[CListBox::CompareItem](#compareitem)|Chamado pela estrutura para determinar a posição de um novo item em uma caixa de listagem de desenho proprietário classificada.|  
|[CListBox::Create](#create)|Cria a caixa de listagem do Windows e anexa-o para o `CListBox` objeto.|  
|[CListBox::DeleteItem](#deleteitem)|Chamado pela estrutura quando o usuário exclui um item de uma caixa de listagem de desenho proprietário.|  
|[CListBox::DeleteString](#deletestring)|Exclui uma cadeia de caracteres de uma caixa de listagem.|  
|[CListBox::Dir](#dir)|Adiciona os nomes de arquivos, unidades ou ambos, do diretório atual para uma caixa de listagem.|  
|[CListBox::DrawItem](#drawitem)|Chamado pela estrutura quando um aspecto visual de uma caixa de listagem de desenho proprietário mude.|  
|[CListBox:: FindString](#findstring)|Pesquisa uma cadeia de caracteres em uma caixa de listagem.|  
|[CListBox::FindStringExact](#findstringexact)|Localiza a primeira cadeia de caixa de listagem que corresponde a uma cadeia de caracteres especificada.|  
|[CListBox::GetAnchorIndex](#getanchorindex)|Retorna o índice baseado em zero do item atual âncora em uma caixa de listagem.|  
|[CListBox::GetCaretIndex](#getcaretindex)|Determina o índice do item que tem o retângulo de foco em uma caixa de listagem de seleção múltipla.|  
|[CListBox::GetCount](#getcount)|Retorna o número de cadeias de caracteres em uma caixa de listagem.|  
|[CListBox::GetCurSel](#getcursel)|Retorna o índice baseado em zero da cadeia de caracteres atualmente selecionado em uma caixa de listagem.|  
|[CListBox::GetHorizontalExtent](#gethorizontalextent)|Retorna a largura em pixels que uma caixa de listagem pode ser rolada horizontalmente.|  
|[CListBox::GetItemData](#getitemdata)|Retorna o valor de 32 bits associado ao item de caixa de listagem.|  
|[CListBox::GetItemDataPtr](#getitemdataptr)|Retorna um ponteiro para um item de caixa de listagem.|  
|[CListBox::GetItemHeight](#getitemheight)|Determina a altura dos itens em uma caixa de listagem.|  
|[CListBox::GetItemRect](#getitemrect)|Retorna o retângulo delimitador do item de caixa de listagem como ele é exibido no momento.|  
|[CListBox::GetListBoxInfo](#getlistboxinfo)|Recupera o número de itens por coluna.|  
|[CListBox::GetLocale](#getlocale)|Recupera o identificador de localidade para uma caixa de listagem.|  
|[CListBox::GetSel](#getsel)|Retorna o estado de seleção de um item de caixa de listagem.|  
|[CListBox::GetSelCount](#getselcount)|Retorna o número de cadeias de caracteres atualmente selecionado em uma caixa de listagem de seleção múltipla.|  
|[CListBox::GetSelItems](#getselitems)|Retorna os índices das cadeias de caracteres atualmente selecionados em uma caixa de listagem.|  
|[CListBox::GetText](#gettext)|Copia um item de caixa de listagem em um buffer.|  
|[CListBox::GetTextLen](#gettextlen)|Retorna o comprimento em bytes de um item de caixa de listagem.|  
|[CListBox::GetTopIndex](#gettopindex)|Retorna o índice da primeira cadeia de caracteres visível em uma caixa de listagem.|  
|[CListBox::InitStorage](#initstorage)|Pré-alocar blocos de memória para itens da caixa de lista e cadeias de caracteres.|  
|[CListBox::InsertString](#insertstring)|Insere uma cadeia de caracteres em um local específico em uma caixa de listagem.|  
|[CListBox::ItemFromPoint](#itemfrompoint)|Retorna o índice do item de caixa de listagem mais próximo de um ponto.|  
|[CListBox::MeasureItem](#measureitem)|Chamado pela estrutura quando uma caixa de listagem de desenho proprietário é criada para determinar as dimensões da caixa de listagem.|  
|[CListBox::ResetContent](#resetcontent)|Limpa todas as entradas de uma caixa de listagem.|  
|[CListBox::SelectString](#selectstring)|Localiza e seleciona uma cadeia de caracteres em uma caixa de listagem de seleção única.|  
|[CListBox::SelItemRange](#selitemrange)|Marca ou desmarca um intervalo de cadeias de caracteres em uma caixa de listagem de seleção múltipla.|  
|[CListBox::SetAnchorIndex](#setanchorindex)|Define a âncora em uma caixa de listagem de seleção múltipla para começar uma seleção estendida.|  
|[CListBox::SetCaretIndex](#setcaretindex)|Define o retângulo de foco para o item no índice especificado em uma caixa de listagem de seleção múltipla.|  
|[CListBox::SetColumnWidth](#setcolumnwidth)|Define a largura da coluna de uma caixa de listagem de várias colunas.|  
|[CListBox::SetCurSel](#setcursel)|Seleciona uma cadeia de caracteres da caixa de listagem.|  
|[CListBox::SetHorizontalExtent](#sethorizontalextent)|Define a largura em pixels que uma caixa de listagem pode ser rolada horizontalmente.|  
|[CListBox::SetItemData](#setitemdata)|Define o valor de 32 bits associado ao item de caixa de listagem.|  
|[CListBox::SetItemDataPtr](#setitemdataptr)|Define um ponteiro para o item de caixa de listagem.|  
|[CListBox::SetItemHeight](#setitemheight)|Define a altura de itens em uma caixa de listagem.|  
|[CListBox::SetLocale](#setlocale)|Define o identificador de localidade para uma caixa de listagem.|  
|[CListBox::SetSel](#setsel)|Marca ou desmarca um item de caixa de listagem em uma caixa de listagem de seleção múltipla.|  
|[CListBox::SetTabStops](#settabstops)|Define as posições de tabulação em uma caixa de listagem.|  
|[CListBox::SetTopIndex](#settopindex)|Define o índice baseado em zero da primeira cadeia de caracteres visível em uma caixa de listagem.|  
|[CListBox::VKeyToItem](#vkeytoitem)|Substituição para fornecer personalizado `WM_KEYDOWN` tratamento das caixas de listagem com a **LBS_WANTKEYBOARDINPUT** conjunto de estilos.|  
  
## <a name="remarks"></a>Comentários  
 Uma caixa de listagem exibe uma lista de itens, como nomes de arquivos que o usuário pode exibir e selecionar.  
  
 Em uma caixa de listagem de seleção única, o usuário pode selecionar somente um item. Em uma caixa de listagem de seleção múltipla, um intervalo de itens pode ser selecionado. Quando o usuário seleciona um item, ele será realçado e a caixa de listagem envia uma mensagem de notificação para a janela pai.  
  
 Você pode criar uma caixa de listagem de um modelo de caixa de diálogo ou diretamente no seu código. Para criá-lo diretamente, construir o `CListBox` do objeto, em seguida, chame o [criar](#create) a função de membro para criar o controle de caixa de listagem do Windows e anexá-lo a `CListBox` objeto. Para usar uma caixa de listagem em um modelo de caixa de diálogo, declare uma variável de caixa de listagem em sua classe de caixa de diálogo, use `DDX_Control` em sua classe de caixa de diálogo `DoDataExchange` função para conectar-se a variável de membro para o controle. (Isso é feito para você automaticamente quando você adicionar uma variável de controle para sua classe de caixa de diálogo.)  
  
 Construção pode ser um processo de uma etapa em uma classe derivada de `CListBox`. Escrever um construtor para a classe derivada e chamada **criar** de dentro do construtor.  
  
 Se você quiser controlar mensagens de notificação do Windows enviadas por uma caixa de listagem para seu pai (normalmente uma classe derivada de [CDialog](../../mfc/reference/cdialog-class.md)), adicionar uma função de membro de entrada e o manipulador de mensagens do mapa da mensagem para a classe pai para cada mensagem.  
  
 Cada entrada de mapa de mensagem usa o seguinte formato:  
  
 `ON_Notification( id, memberFxn )`  
  
 onde `id` Especifica a ID de janela filho do controle de caixa de listagem enviando a notificação e `memberFxn` é o nome da função de membro pai que você gravou para tratar a notificação.  
  
 Protótipo de função do pai é o seguinte:  
  
 `afx_msg void memberFxn( );`  
  
 Esta é uma lista de entradas potenciais do mapa da mensagem e uma descrição dos casos em que eles seriam enviados ao pai:  
  
- **ON_LBN_DBLCLK** o usuário clica duas vezes em uma cadeia de caracteres em uma caixa de listagem. Apenas uma caixa de listagem que tem o [LBS_NOTIFY](../../mfc/reference/list-box-styles.md) estilo enviará a mensagem de notificação.  
  
- **ON_LBN_ERRSPACE** a caixa de listagem não pode alocar memória suficiente para atender à solicitação.  
  
- **ON_LBN_KILLFOCUS** a caixa de listagem é perder o foco de entrada.  
  
- **ON_LBN_SELCANCEL** a seleção atual da caixa de listagem é cancelada. Esta mensagem é enviada somente quando uma caixa de listagem tem o **LBS_NOTIFY** estilo.  
  
- **ON_LBN_SELCHANGE** a seleção na caixa de listagem foi alterada. Essa notificação é enviada não se a seleção é alterada o [CListBox::SetCurSel](#setcursel) função de membro. Essa notificação só se aplica a uma caixa de listagem que tem o **LBS_NOTIFY** estilo. O **LBN_SELCHANGE** mensagem de notificação é enviada para uma caixa de listagem de seleção múltipla sempre que o usuário pressiona uma tecla de seta, mesmo se a seleção não for alterada.  
  
- **ON_LBN_SETFOCUS** a caixa de listagem está recebendo o foco de entrada.  
  
- **ON_WM_CHARTOITEM** uma caixa de listagem de desenho proprietário com cadeias de caracteres não recebe um `WM_CHAR` mensagem.  
  
- **ON_WM_VKEYTOITEM** uma caixa de listagem com a **LBS_WANTKEYBOARDINPUT** estilo recebe um `WM_KEYDOWN` mensagem.  
  
 Se você criar um `CListBox` objeto dentro de uma caixa de diálogo (por meio de um recurso de caixa de diálogo), o `CListBox` objeto é destruído automaticamente quando o usuário fecha a caixa de diálogo.  
  
 Se você criar um `CListBox` objeto dentro de uma janela, talvez você precise destruir o `CListBox` objeto. Se você criar o `CListBox` do objeto na pilha, ele será destruído automaticamente. Se você criar o `CListBox` objeto no heap usando o **novo** função, você deve chamar **excluir** no objeto para destruí-lo quando o usuário fecha a janela pai.  
  
 Se você alocar qualquer memória no `CListBox` de objeto, substituir o `CListBox` destruidor de descartar a alocação.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CListBox`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="a-nameaddstringa--clistboxaddstring"></a><a name="addstring"></a>CListBox::AddString  
 Adiciona uma cadeia de caracteres para uma caixa de listagem.  
  
```  
int AddString(LPCTSTR lpszItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszItem`  
 Aponta para a cadeia de caracteres terminada em nulo que deve ser adicionado.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero para a cadeia de caracteres na caixa de listagem. O valor de retorno é **LB_ERR** se ocorrer um erro; o valor de retorno é **LB_ERRSPACE** se houver espaço suficiente armazenar a nova cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Se a caixa de listagem não foi criada com o [LBS_SORT](../../mfc/reference/list-box-styles.md) estilo, a cadeia de caracteres é adicionada ao final da lista. Caso contrário, a cadeia de caracteres é inserida na lista, e a lista é classificada. Se a caixa de listagem foi criada com o **LBS_SORT** estilo mas não o [LBS_HASSTRINGS](../../mfc/reference/list-box-styles.md) estilo, a estrutura classifica a lista por uma ou mais chamadas para o `CompareItem` função de membro.  
  
 Use [InsertString](#insertstring) para inserir uma cadeia de caracteres em um local específico na caixa de listagem.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox n º&3;](../../mfc/codesnippet/cpp/clistbox-class_1.cpp)]  
  
##  <a name="a-namechartoitema--clistboxchartoitem"></a><a name="chartoitem"></a>CListBox::CharToItem  
 Chamado pela estrutura quando a janela do pai da caixa de listagem recebe um `WM_CHARTOITEM` mensagem da caixa de listagem.  
  
```  
virtual int CharToItem(
    UINT nKey,  
    UINT nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nKey`  
 O código ANSI do caractere que o usuário digitou.  
  
 `nIndex`  
 A posição atual do cursor de caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna – 1 ou -2 para nenhuma outra ação ou um número não negativo para especificar um índice de um item de caixa de listagem na qual executar a ação padrão para o pressionamento de teclas. A implementação padrão retorna – 1.  
  
### <a name="remarks"></a>Comentários  
 O `WM_CHARTOITEM` mensagem é enviada pela caixa de listagem quando ele recebe um `WM_CHAR` mensagem, mas somente se a caixa de listagem atende a todos esses critérios:  
  
-   É uma caixa de listagem de desenho proprietário.  
  
-   Não tem o [LBS_HASSTRINGS](../../mfc/reference/list-box-styles.md) conjunto de estilos.  
  
-   Tem pelo menos um item.  
  
 Você nunca deve chamar essa função por conta própria. Substitua essa função para fornecer sua própria manipulação personalizada de mensagens do teclado.  
  
 Em sua substituição, você deve retornar um valor para dizer à estrutura que ação executada. Um valor de retorno de – 1 ou -2 indica que você tratou todos os aspectos de selecionando o item e não requer nenhuma ação adicional na caixa da lista. Antes de retornar – 1 ou -2, você pode definir a seleção ou mover o cursor ou ambos. Para definir a seleção, use [SetCurSel](#setcursel) ou [SetSel](#setsel). Para mover o cursor, use [SetCaretIndex](#setcaretindex).  
  
 Um valor de retorno de 0 ou maior Especifica o índice de um item na caixa de listagem e indica que a caixa de listagem deve realizar a ação padrão para o pressionamento de teclas em determinado item.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox n º&4;](../../mfc/codesnippet/cpp/clistbox-class_2.cpp)]  
  
##  <a name="a-nameclistboxa--clistboxclistbox"></a><a name="clistbox"></a>CListBox::CListBox  
 Constrói um objeto `CListBox`.  
  
```  
CListBox();
```  
  
### <a name="remarks"></a>Comentários  
 Você construir um `CListBox` objeto em duas etapas. Primeiro, chame o construtor **ClistBox** e, em seguida, chame **criar**, que inicializa a caixa de listagem do Windows e anexa-o para o `CListBox`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox n º&1;](../../mfc/codesnippet/cpp/clistbox-class_3.cpp)]  
  
##  <a name="a-namecompareitema--clistboxcompareitem"></a><a name="compareitem"></a>CListBox::CompareItem  
 Chamado pela estrutura para determinar a posição relativa de um novo item em uma caixa de listagem de desenho proprietário classificada.  
  
```  
virtual int CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpCompareItemStruct`  
 Um ponteiro de tempo para um `COMPAREITEMSTRUCT` estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Indica a posição relativa dos dois itens descrito o [COMPAREITEMSTRUCT](../../mfc/reference/compareitemstruct-structure.md) estrutura. Pode ser qualquer um dos seguintes valores:  
  
|Valor|Significado|  
|-----------|-------------|  
|–1|Item 1 classifica antes do item 2.|  
|0|Item 1 e item 2 classificar o mesmo.|  
|1|Item 1 classifica após o item 2.|  
  
 Consulte [CWnd::OnCompareItem](../../mfc/reference/cwnd-class.md#oncompareitem) para obter uma descrição de `COMPAREITEMSTRUCT` estrutura.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, essa função de membro não fará nada. Se você criar uma caixa de listagem de desenho proprietário com o **LBS_SORT** estilo, você deve substituir essa função de membro para ajudar a estrutura de classificação novos itens adicionados à caixa de listagem.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox n º&5;](../../mfc/codesnippet/cpp/clistbox-class_4.cpp)]  
  
##  <a name="a-namecreatea--clistboxcreate"></a><a name="create"></a>CListBox::Create  
 Cria a caixa de listagem do Windows e anexa-o para o `CListBox` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Especifica o estilo da caixa de listagem. Aplique qualquer combinação de [estilos de caixa de listagem](../../mfc/reference/list-box-styles.md) para a caixa.  
  
 `rect`  
 Especifica o tamanho da caixa de listagem e posição. Pode ser um `CRect` objeto ou um `RECT` estrutura.  
  
 `pParentWnd`  
 Especifica a janela do pai da caixa de listagem (geralmente um `CDialog` objeto). Ele não deve ser **nulo**.  
  
 `nID`  
 Especifica a ID de controle. da caixa de listagem  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você construir um `CListBox` objeto em duas etapas. Primeiro, chame o construtor e, em seguida, chame **criar**, que inicializa a caixa de listagem do Windows e anexa-o para o `CListBox` objeto.  
  
 Quando **criar** executa o Windows envia o [WM_NCCREATE](../../mfc/reference/cwnd-class.md#onnccreate), [WM_CREATE](../../mfc/reference/cwnd-class.md#oncreate), [WM_NCCALCSIZE](../../mfc/reference/cwnd-class.md#onnccalcsize), e [WM_GETMINMAXINFO](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) mensagens para o controle de caixa de listagem.  
  
 Essas mensagens são manipuladas por padrão, o [OnNcCreate](../../mfc/reference/cwnd-class.md#onnccreate), [OnCreate](../../mfc/reference/cwnd-class.md#oncreate), [OnNcCalcSize](../../mfc/reference/cwnd-class.md#onnccalcsize), e [OnGetMinMaxInfo](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) funções de membro na `CWnd` classe base. Para estender a manipulação de mensagem padrão, derive uma classe de `CListBox`, adicione um mapa da mensagem para a nova classe e substituir as funções de membro anterior do manipulador de mensagens. Substituir `OnCreate`, por exemplo, para executar inicialização necessária para uma nova classe.  
  
 Aplique o seguinte [estilos de janela](../../mfc/reference/window-styles.md) a um controle de caixa de listagem.  
  
- **Estilo** sempre  
  
- **WS_VISIBLE** geral  
  
- **WS_DISABLED** raramente  
  
- **WS_VSCROLL** para adicionar uma barra de rolagem vertical  
  
- **WS_HSCROLL** para adicionar uma barra de rolagem horizontal  
  
- **WS_GROUP** para agrupar controles  
  
- **WS_TABSTOP** para permitir a este controle de tabulação  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox n º&2;](../../mfc/codesnippet/cpp/clistbox-class_5.cpp)]  
  
##  <a name="a-namedeleteitema--clistboxdeleteitem"></a><a name="deleteitem"></a>CListBox::DeleteItem  
 Chamado pela estrutura quando o usuário exclui um item de um desenho proprietário `CListBox` de objeto ou destrói a caixa de listagem.  
  
```  
virtual void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpDeleteItemStruct`  
 Um ponteiro longo para um Windows [DELETEITEMSTRUCT](../../mfc/reference/deleteitemstruct-structure.md) estrutura que contém informações sobre o item excluído.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função não faz nada. Substitua essa função para redesenhar uma caixa de listagem de desenho proprietário conforme necessário.  
  
 Consulte [CWnd::OnDeleteItem](../../mfc/reference/cwnd-class.md#ondeleteitem) para obter uma descrição de `DELETEITEMSTRUCT` estrutura.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox n º&6;](../../mfc/codesnippet/cpp/clistbox-class_6.cpp)]  
  
##  <a name="a-namedeletestringa--clistboxdeletestring"></a><a name="deletestring"></a>CListBox::DeleteString  
 Exclui o item na posição `nIndex` na caixa de listagem.  
  
```  
int DeleteString(UINT nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice baseado em zero da cadeia de caracteres a ser excluído.  
  
### <a name="return-value"></a>Valor de retorno  
 Uma contagem das cadeias de caracteres restantes na lista. O valor de retorno é **LB_ERR** se `nIndex` Especifica um índice maior que o número de itens na lista.  
  
### <a name="remarks"></a>Comentários  
 Todos os itens a seguir `nIndex` Agora mova uma posição para baixo. Por exemplo, se uma caixa de listagem contém dois itens, excluir o primeiro item fará com que o item restante a ser agora na primeira posição. `nIndex`=&0; para o item na primeira posição.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox&#7;](../../mfc/codesnippet/cpp/clistbox-class_7.cpp)]  
  
##  <a name="a-namedira--clistboxdir"></a><a name="dir"></a>CListBox::Dir  
 Adiciona uma lista de nomes de arquivos, unidades ou ambos para uma caixa de listagem.  
  
```  
int Dir(
    UINT attr,  
    LPCTSTR lpszWildCard);
```  
  
### <a name="parameters"></a>Parâmetros  
 `attr`  
 Pode ser qualquer combinação de `enum` valores descritos na **CFile::GetStatu**[s](../../mfc/reference/cfile-class.md#getstatus), ou qualquer combinação dos seguintes valores:  
  
|Valor|Significado|  
|-----------|-------------|  
|0x0000|Arquivo pode ser lido ou gravado.|  
|0x0001|Arquivo pode ser lido de mas não gravado.|  
|0x0002|Arquivo está oculto e não aparece em uma listagem de diretório.|  
|0x0004|É um arquivo de sistema.|  
|0x0010|O nome especificado pelo `lpszWildCard` Especifica um diretório.|  
|0x0020|Arquivo foi arquivado.|  
|0x4000|Incluir todas as unidades que correspondem ao nome especificado pelo `lpszWildCard`.|  
|0x8000|Sinalizador exclusivo. Se o sinalizador exclusivo é definido, somente os arquivos do tipo especificado serão listados. Caso contrário, os arquivos do tipo especificado são listados além dos arquivos "normais".|  
  
 `lpszWildCard`  
 Aponta para uma cadeia de caracteres de especificação de arquivo. A cadeia de caracteres pode conter caracteres curinga (por exemplo, *.\*).  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero do último nome de arquivo adicionado à lista. O valor de retorno é **LB_ERR** se ocorrer um erro; o valor de retorno é **LB_ERRSPACE** se houver espaço suficiente armazenar novas cadeias de caracteres.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox n º&8;](../../mfc/codesnippet/cpp/clistbox-class_8.cpp)]  
  
##  <a name="a-namedrawitema--clistboxdrawitem"></a><a name="drawitem"></a>CListBox::DrawItem  
 Chamado pela estrutura quando um aspecto visual de uma caixa de listagem de desenho proprietário mude.  
  
```  
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpDrawItemStruct`  
 Um ponteiro de tempo para um [DRAWITEMSTRUCT](../../mfc/reference/drawitemstruct-structure.md) estrutura que contém informações sobre o tipo de desenho necessárias.  
  
### <a name="remarks"></a>Comentários  
 O **itemAction** e **itemState** membros a `DRAWITEMSTRUCT` estrutura define a ação de desenho que deve ser executada.  
  
 Por padrão, essa função de membro não fará nada. Substituir essa função de membro para implementar o desenho de um desenho proprietário `CListBox` objeto. O aplicativo deve restaurar todos os objetos GDI (interface) do dispositivo gráfico selecionados para o contexto de exibição fornecidos no `lpDrawItemStruct` antes desse membro função termina.  
  
 Consulte [CWnd::OnDrawItem](../../mfc/reference/cwnd-class.md#ondrawitem) para obter uma descrição de `DRAWITEMSTRUCT` estrutura.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox n º&9;](../../mfc/codesnippet/cpp/clistbox-class_9.cpp)]  
  
##  <a name="a-namefindstringa--clistboxfindstring"></a><a name="findstring"></a>CListBox:: FindString  
 Localiza a primeira cadeia de caracteres em uma caixa de lista que contém o prefixo especificado sem alterar a seleção da caixa de listagem.  
  
```  
int FindString(
    int nStartAfter,  
    LPCTSTR lpszItem) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nStartAfter`  
 Contém o índice baseado em zero do item antes do primeiro item a ser pesquisada. Quando a pesquisa chega a parte inferior da caixa de listagem, ele continua na parte superior da caixa de listagem no item especificado por `nStartAfter`. Se `nStartAfter` é –&1;, a caixa de listagem inteira é pesquisada desde o início.  
  
 `lpszItem`  
 Aponta para a cadeia de caracteres terminada em nulo que contém o prefixo para pesquisar. A pesquisa é o caso independente, portanto, essa cadeia de caracteres pode conter qualquer combinação de letras maiusculas e minúsculas.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero do item correspondente, ou **LB_ERR** se a pesquisa foi bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 Use o [SelectString](#selectstring) a função de membro para localizar e selecionar uma cadeia de caracteres.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox n º&10;](../../mfc/codesnippet/cpp/clistbox-class_10.cpp)]  
  
##  <a name="a-namefindstringexacta--clistboxfindstringexact"></a><a name="findstringexact"></a>CListBox::FindStringExact  
 Localiza a primeira cadeia de caixa de listagem que corresponde a cadeia de caracteres especificada em `lpszFind`.  
  
```  
int FindStringExact(
    int nIndexStart,  
    LPCTSTR lpszFind) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndexStart`  
 Especifica o índice baseado em zero do item antes do primeiro item a ser pesquisada. Quando a pesquisa chega a parte inferior da caixa de listagem, ele continua na parte superior da caixa de listagem no item especificado por `nIndexStart`. Se `nIndexStart` é –&1;, a caixa de listagem inteira é pesquisada desde o início.  
  
 `lpszFind`  
 Aponta para a cadeia de caracteres terminada em nulo para pesquisar. Essa cadeia de caracteres pode conter um nome de arquivo completo, incluindo a extensão. A pesquisa não diferencia maiusculas de minúsculas, para a cadeia de caracteres pode conter qualquer combinação de letras maiusculas e minúsculas.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do item correspondente, ou **LB_ERR** se a pesquisa foi bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 Se a caixa de listagem foi criada com um estilo de desenho do proprietário, mas sem o [LBS_HASSTRINGS](../../mfc/reference/list-box-styles.md) estilo, o `FindStringExact` função de membro tenta corresponder o valor de palavras duplas em relação ao valor de `lpszFind`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox n º&11;](../../mfc/codesnippet/cpp/clistbox-class_11.cpp)]  
  
##  <a name="a-namegetanchorindexa--clistboxgetanchorindex"></a><a name="getanchorindex"></a>CListBox::GetAnchorIndex  
 Retorna o índice baseado em zero do item atual âncora na caixa de listagem.  
  
```  
int GetAnchorIndex() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do item de âncora atual, se for bem-sucedida; Caso contrário, **LB_ERR**.  
  
### <a name="remarks"></a>Comentários  
 Em uma caixa de listagem de seleção múltipla, o item de âncora é o primeiro ou último item em um bloco contíguo itens selecionados.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CListBox::SetAnchorIndex](#setanchorindex).  
  
##  <a name="a-namegetcaretindexa--clistboxgetcaretindex"></a><a name="getcaretindex"></a>CListBox::GetCaretIndex  
 Determina o índice do item que tem o retângulo de foco em uma caixa de listagem de seleção múltipla.  
  
```  
int GetCaretIndex() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero do item que tem o retângulo de foco em uma caixa de listagem. Se a caixa de listagem é uma caixa de listagem de seleção única, o valor de retorno é o índice do item selecionado, se houver.  
  
### <a name="remarks"></a>Comentários  
 O item pode ou não pode ser selecionado.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CListBox::SetCaretIndex](#setcaretindex).  
  
##  <a name="a-namegetcounta--clistboxgetcount"></a><a name="getcount"></a>CListBox::GetCount  
 Recupera o número de itens em uma caixa de listagem.  
  
```  
int GetCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens na caixa de listagem, ou **LB_ERR** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 A contagem retornada é maior do que o valor de índice do último item (o índice é baseado em zero).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox&#12;](../../mfc/codesnippet/cpp/clistbox-class_12.cpp)]  
  
##  <a name="a-namegetcursela--clistboxgetcursel"></a><a name="getcursel"></a>CListBox::GetCurSel  
 Retorna o índice baseado em zero do item selecionado no momento, se houver, em uma caixa de listagem de seleção única.  
  
```  
int GetCurSel() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero do item atualmente selecionado se ele é uma caixa de listagem de seleção única. É `LB_ERR` se nenhum item está selecionado no momento.  
  
 Em uma caixa de listagem de seleção múltipla, o índice do item que tem o foco.  
  
### <a name="remarks"></a>Comentários  
 Não chame `GetCurSel` para uma caixa de listagem de seleção múltipla. Use [CListBox::GetSelItems](#getselitems) em vez disso.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox&13;](../../mfc/codesnippet/cpp/clistbox-class_13.cpp)]  
  
##  <a name="a-namegethorizontalextenta--clistboxgethorizontalextent"></a><a name="gethorizontalextent"></a>CListBox::GetHorizontalExtent  
 Recupera a largura em pixels por que ele pode ser rolado horizontalmente na caixa de listagem.  
  
```  
int GetHorizontalExtent() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A largura rolável da caixa de listagem, em pixels.  
  
### <a name="remarks"></a>Comentários  
 Isso é aplicável somente se a caixa de listagem tem uma barra de rolagem horizontal.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox&#14;](../../mfc/codesnippet/cpp/clistbox-class_14.cpp)]  
  
##  <a name="a-namegetitemdataa--clistboxgetitemdata"></a><a name="getitemdata"></a>CListBox::GetItemData  
 Recupera o valor de palavras duplas fornecida pelo aplicativo associado ao item de caixa de listagem especificada.  
  
```  
DWORD_PTR GetItemData(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice baseado em zero do item na caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de 32 bits associado ao item ou **LB_ERR** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 O valor de palavras duplas foi o `dwItemData` parâmetro de um [SetItemData](#setitemdata) chamar.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox&#15;](../../mfc/codesnippet/cpp/clistbox-class_15.cpp)]  
  
##  <a name="a-namegetitemdataptra--clistboxgetitemdataptr"></a><a name="getitemdataptr"></a>CListBox::GetItemDataPtr  
 Recupera o valor de 32 bits fornecida pelo aplicativo associado ao item de caixa de listagem especificada como um ponteiro ( **void\***).  
  
```  
void* GetItemDataPtr(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice baseado em zero do item na caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Recupera um ponteiro, ou -1 se ocorrer um erro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox n º&16;](../../mfc/codesnippet/cpp/clistbox-class_16.cpp)]  
  
##  <a name="a-namegetitemheighta--clistboxgetitemheight"></a><a name="getitemheight"></a>CListBox::GetItemHeight  
 Determina a altura dos itens em uma caixa de listagem.  
  
```  
int GetItemHeight(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice baseado em zero do item na caixa de listagem. Esse parâmetro é usado somente se a caixa de listagem tem o **LBS_OWNERDRAWVARIABLE** estilo; caso contrário, ele deve ser definido como 0.  
  
### <a name="return-value"></a>Valor de retorno  
 A altura, em pixels, dos itens na caixa de listagem. Se a caixa de listagem tem o [LBS_OWNERDRAWVARIABLE](../../mfc/reference/list-box-styles.md) estilo, o valor de retorno é a altura do item especificado por `nIndex`. Se ocorrer um erro, o valor de retorno é **LB_ERR**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[17 NVC_MFC_CListBox](../../mfc/codesnippet/cpp/clistbox-class_17.cpp)]  
  
##  <a name="a-namegetitemrecta--clistboxgetitemrect"></a><a name="getitemrect"></a>CListBox::GetItemRect  
 Recupera as dimensões do retângulo item dos limites de uma caixa de listagem como atualmente é exibido na janela da caixa de listagem.  
  
```  
int GetItemRect(
    int nIndex,  
    LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice baseado em zero do item.  
  
 `lpRect`  
 Especifica um ponteiro longo para um [estrutura RECT](../../mfc/reference/rect-structure1.md) que recebe as coordenadas do cliente de caixa de listagem do item.  
  
### <a name="return-value"></a>Valor de retorno  
 **LB_ERR** se ocorrer um erro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox n º&18;](../../mfc/codesnippet/cpp/clistbox-class_18.cpp)]  
  
##  <a name="a-namegetlistboxinfoa--clistboxgetlistboxinfo"></a><a name="getlistboxinfo"></a>CListBox::GetListBoxInfo  
 Recupera o número de itens por coluna.  
  
```  
DWORD GetListBoxInfo() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Número de itens por coluna o `CListBox` objeto.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade do [LB_GETLISTBOXINFO](http://msdn.microsoft.com/library/windows/desktop/bb775208) mensagem, conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetlocalea--clistboxgetlocale"></a><a name="getlocale"></a>CListBox::GetLocale  
 Recupera a localidade usada pela caixa de listagem.  
  
```  
LCID GetLocale() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor LCID (identificador) da localidade para cadeias de caracteres na caixa de listagem.  
  
### <a name="remarks"></a>Comentários  
 A localidade é usada, por exemplo, para determinar a ordem de classificação de cadeias de caracteres em uma caixa de lista classificada.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CListBox::SetLocale](#setlocale).  
  
##  <a name="a-namegetsela--clistboxgetsel"></a><a name="getsel"></a>CListBox::GetSel  
 Recupera o estado de seleção de um item.  
  
```  
int GetSel(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice baseado em zero do item.  
  
### <a name="return-value"></a>Valor de retorno  
 Um número positivo se o item especificado está selecionado. Caso contrário, é 0. O valor de retorno é `LB_ERR` se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro funciona com as duas caixas de listagem de seleção única e múltipla.  
  
 Para recuperar o índice do item de caixa de lista selecionado no momento, use [CListBox::GetCurSel](#getcursel).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[19 NVC_MFC_CListBox](../../mfc/codesnippet/cpp/clistbox-class_19.cpp)]  
  
##  <a name="a-namegetselcounta--clistboxgetselcount"></a><a name="getselcount"></a>CListBox::GetSelCount  
 Recupera o número total de itens selecionados em uma caixa de listagem de seleção múltipla.  
  
```  
int GetSelCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A contagem de itens selecionados em uma caixa de listagem. Se a caixa de listagem é uma caixa de listagem de seleção única, o valor de retorno é **LB_ERR**.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CListBox::GetSelItems](#getselitems).  
  
##  <a name="a-namegetselitemsa--clistboxgetselitems"></a><a name="getselitems"></a>CListBox::GetSelItems  
 Preenche um buffer com uma matriz de inteiros que especifica os números de item dos itens selecionados em uma caixa de listagem de seleção múltipla.  
  
```  
int GetSelItems(
    int nMaxItems,  
    LPINT rgIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMaxItems`  
 Especifica o número máximo de itens selecionados, cujos números de item devem ser colocados no buffer.  
  
 `rgIndex`  
 Especifica um ponteiro para um buffer grande o suficiente para o número de inteiros especificado por `nMaxItems`.  
  
### <a name="return-value"></a>Valor de retorno  
 O número real de itens colocados no buffer. Se a caixa de listagem é uma caixa de listagem de seleção única, o valor de retorno é `LB_ERR`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[20 NVC_MFC_CListBox](../../mfc/codesnippet/cpp/clistbox-class_20.cpp)]  
  
##  <a name="a-namegettexta--clistboxgettext"></a><a name="gettext"></a>CListBox::GetText  
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
 Especifica o índice baseado em zero da cadeia de caracteres a ser recuperado.  
  
 `lpszBuffer`  
 Aponta para o buffer que recebe a cadeia de caracteres. O buffer deve ter espaço suficiente para a cadeia de caracteres e um caractere nulo de terminação. O tamanho da cadeia de caracteres pode ser determinado antecipadamente chamando o `GetTextLen` função de membro.  
  
 `rString`  
 Uma referência a um objeto `CString`.  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento (em bytes) da cadeia de caracteres, exceto o caractere de terminação nula. Se `nIndex` não especificar um índice válido, o valor de retorno é **LB_ERR**.  
  
### <a name="remarks"></a>Comentários  
 O segundo formulário deste membro de função preenche uma `CString` objeto com o texto da cadeia de caracteres.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox&#21;](../../mfc/codesnippet/cpp/clistbox-class_21.cpp)]  
  
##  <a name="a-namegettextlena--clistboxgettextlen"></a><a name="gettextlen"></a>CListBox::GetTextLen  
 Obtém o comprimento de uma cadeia de caracteres em um item de caixa de listagem.  
  
```  
int GetTextLen(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice baseado em zero da cadeia de caracteres.  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento da cadeia de caracteres em caracteres, exceto o caractere de terminação nula. Se `nIndex` não especificar um índice válido, o valor de retorno é **LB_ERR**.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CListBox::GetText](#gettext).  
  
##  <a name="a-namegettopindexa--clistboxgettopindex"></a><a name="gettopindex"></a>CListBox::GetTopIndex  
 Retorna o índice baseado em zero do primeiro item visível na caixa de listagem.  
  
```  
int GetTopIndex() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero do primeiro item visível na caixa de listagem se for bem-sucedido, **LB_ERR** caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Inicialmente, o item 0 está na parte superior da caixa de listagem, mas se a caixa de listagem é rolada, outro item pode estar na parte superior.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox&#22;](../../mfc/codesnippet/cpp/clistbox-class_22.cpp)]  
  
##  <a name="a-nameinitstoragea--clistboxinitstorage"></a><a name="initstorage"></a>CListBox::InitStorage  
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
 Se for bem-sucedido, o número máximo de itens que a caixa de listagem pode armazenar antes de a realocação de memória é necessário, caso contrário, **LB_ERRSPACE**, que significa que não há memória suficiente está disponível.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função antes de adicionar um grande número de itens a um `CListBox`.  
  
 Essa função ajuda a acelerar a inicialização das caixas de listagem que têm um grande número de itens (mais de 100). Ele pré-alocar a quantidade especificada de memória subsequente assim que [AddString](#addstring), [InsertString](#insertstring), e [Dir](#dir) funções usam o menor tempo possível. Você pode usar estimativas para os parâmetros. Se você estimar, é alocada memória extra; Se você subestimar, a alocação normal é usada para itens que excedem a quantidade pré-alocados.  
  
 Windows 95/98 somente: O `nItems` parâmetro é limitado aos valores de 16 bits. Isso significa que caixas de listagem não podem conter mais de 32.767 itens. Embora o número de itens é restrito, o tamanho total dos itens em uma caixa de listagem é limitado apenas pela memória disponível.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox&#23;](../../mfc/codesnippet/cpp/clistbox-class_23.cpp)]  
  
##  <a name="a-nameinsertstringa--clistboxinsertstring"></a><a name="insertstring"></a>CListBox::InsertString  
 Insere uma cadeia de caracteres na caixa de listagem.  
  
```  
int InsertString(
    int nIndex,  
    LPCTSTR lpszItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice baseado em zero da posição para inserir a cadeia de caracteres. Se esse parâmetro é –&1;, a cadeia de caracteres é adicionada ao final da lista.  
  
 `lpszItem`  
 Aponta para a cadeia de caracteres terminada em nulo que deve ser inserido.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero da posição em que a cadeia de caracteres foi inserida. O valor de retorno é **LB_ERR** se ocorrer um erro; o valor de retorno é **LB_ERRSPACE** se houver espaço suficiente armazenar a nova cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Ao contrário do [AddString](#addstring) função de membro, `InsertString` não causa uma lista com o [LBS_SORT](../../mfc/reference/list-box-styles.md) estilo a ser classificada.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox&#24;](../../mfc/codesnippet/cpp/clistbox-class_24.cpp)]  
  
##  <a name="a-nameitemfrompointa--clistboxitemfrompoint"></a><a name="itemfrompoint"></a>CListBox::ItemFromPoint  
 Determina o item de caixa de listagem mais próximo ponto especificado em `pt`.  
  
```  
UINT ItemFromPoint(
    CPoint pt,  
    BOOL& bOutside) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pt`  
 Ponto localizar o item mais próximo, especificado em relação ao canto superior esquerdo da área do cliente da caixa de listagem.  
  
 `bOutside`  
 Referência a um `BOOL` variável que será definido como `TRUE` se `pt` está fora da área do cliente do próximo item de caixa de listagem, `FALSE` se `pt` está dentro da área do cliente do item da caixa de lista mais próximo.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do item mais próximo ao ponto especificado em `pt`.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar esta função para determinar qual item de caixa de listagem o cursor do mouse se move sobre.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CListBox::SetAnchorIndex](#setanchorindex).  
  
##  <a name="a-namemeasureitema--clistboxmeasureitem"></a><a name="measureitem"></a>CListBox::MeasureItem  
 Chamado pela estrutura quando uma caixa de listagem com um estilo de desenho proprietário é criada.  
  
```  
virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpMeasureItemStruct`  
 Um ponteiro de tempo para um [MEASUREITEMSTRUCT](../../mfc/reference/measureitemstruct-structure.md) estrutura.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, essa função de membro não fará nada. Substituir essa função de membro e preencha o `MEASUREITEMSTRUCT` estrutura para informar ao Windows as dimensões da caixa de listagem. Se a caixa de listagem é criada com o [LBS_OWNERDRAWVARIABLE](../../mfc/reference/list-box-styles.md) estilo, a estrutura chama essa função de membro para cada item na caixa de listagem. Caso contrário, este membro é chamado apenas uma vez.  
  
 Para obter mais informações sobre como usar o [LBS_OWNERDRAWFIXED](../../mfc/reference/list-box-styles.md) estilo em uma caixa de listagem de desenho proprietário criado com o `SubclassDlgItem` função de membro `CWnd`, consulte a discussão na [técnico 14 Observação](../../mfc/tn014-custom-controls.md).  
  
 Consulte [CWnd::OnMeasureItem](../../mfc/reference/cwnd-class.md#onmeasureitem) para obter uma descrição de `MEASUREITEMSTRUCT` estrutura **.**  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[25 NVC_MFC_CListBox](../../mfc/codesnippet/cpp/clistbox-class_25.cpp)]  
  
##  <a name="a-nameresetcontenta--clistboxresetcontent"></a><a name="resetcontent"></a>CListBox::ResetContent  
 Remove todos os itens de uma caixa de listagem.  
  
```  
void ResetContent();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox&#26;](../../mfc/codesnippet/cpp/clistbox-class_26.cpp)]  
  
##  <a name="a-nameselectstringa--clistboxselectstring"></a><a name="selectstring"></a>CListBox::SelectString  
 Pesquisas de um item de caixa de listagem que coincide com a cadeia de caracteres especificada e, se um item correspondente for encontrado, ele seleciona o item.  
  
```  
int SelectString(
    int nStartAfter,  
    LPCTSTR lpszItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nStartAfter`  
 Contém o índice baseado em zero do item antes do primeiro item a ser pesquisada. Quando a pesquisa chega a parte inferior da caixa de listagem, ele continua na parte superior da caixa de listagem no item especificado por `nStartAfter`. Se `nStartAfter` é –&1;, a caixa de listagem inteira é pesquisada desde o início.  
  
 `lpszItem`  
 Aponta para a cadeia de caracteres terminada em nulo que contém o prefixo para pesquisar. A pesquisa é o caso independente, portanto, essa cadeia de caracteres pode conter qualquer combinação de letras maiusculas e minúsculas.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do item selecionado, se a pesquisa teve êxito. Se a pesquisa tiver êxito, o valor de retorno é **LB_ERR** e a seleção atual não será alterada.  
  
### <a name="remarks"></a>Comentários  
 A caixa de listagem é rolada, se necessário, para colocar o item selecionado na exibição.  
  
 Essa função de membro não pode ser usada com uma caixa de listagem que tem o [LBS_MULTIPLESEL](../../mfc/reference/list-box-styles.md) estilo.  
  
 Um item é selecionado somente se os caracteres inicias (do ponto de partida) correspondem os caracteres na cadeia de caracteres especificado por `lpszItem`.  
  
 Use o `FindString` a função de membro para localizar uma cadeia de caracteres sem selecionando o item.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox&#27;](../../mfc/codesnippet/cpp/clistbox-class_27.cpp)]  
  
##  <a name="a-nameselitemrangea--clistboxselitemrange"></a><a name="selitemrange"></a>CListBox::SelItemRange  
 Seleciona vários itens consecutivos em uma caixa de listagem de seleção múltipla.  
  
```  
int SelItemRange(
    BOOL bSelect,  
    int nFirstItem,  
    int nLastItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bSelect`  
 Especifica como definir a seleção. Se `bSelect` é **TRUE**, a cadeia de caracteres está selecionada e realçada; se **FALSE**, o realce é removido e a cadeia de caracteres não está selecionada.  
  
 `nFirstItem`  
 Especifica o índice baseado em zero do primeiro item a ser definido.  
  
 `nLastItem`  
 Especifica o índice baseado em zero do último item para definir.  
  
### <a name="return-value"></a>Valor de retorno  
 **LB_ERR** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Use esta função de membro apenas com caixas de listagem de seleção múltipla. Se você precisar selecionar somente um item em uma caixa de listagem de seleção múltipla — ou seja, se `nFirstItem` é igual a `nLastItem` — chamar o [SetSel](#setsel) função do membro em vez disso.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox&#28;](../../mfc/codesnippet/cpp/clistbox-class_28.cpp)]  
  
##  <a name="a-namesetanchorindexa--clistboxsetanchorindex"></a><a name="setanchorindex"></a>CListBox::SetAnchorIndex  
 Define a âncora em uma caixa de listagem de seleção múltipla para começar uma seleção estendida.  
  
```  
void SetAnchorIndex(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice baseado em zero do item da caixa de listagem que será a âncora.  
  
### <a name="remarks"></a>Comentários  
 Em uma caixa de listagem de seleção múltipla, o item de âncora é o primeiro ou último item em um bloco contíguo itens selecionados.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[29 NVC_MFC_CListBox](../../mfc/codesnippet/cpp/clistbox-class_29.cpp)]  
  
##  <a name="a-namesetcaretindexa--clistboxsetcaretindex"></a><a name="setcaretindex"></a>CListBox::SetCaretIndex  
 Define o retângulo de foco para o item no índice especificado em uma caixa de listagem de seleção múltipla.  
  
```  
int SetCaretIndex(
    int nIndex,  
    BOOL bScroll = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice baseado em zero do item para receber o retângulo de foco na caixa de listagem.  
  
 *bScroll*  
 Se esse valor for 0, o item é rolado até que ele seja totalmente visível. Se esse valor não for 0, o item é rolado até que seja pelo menos parcialmente visível.  
  
### <a name="return-value"></a>Valor de retorno  
 **LB_ERR** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Se o item não estiver visível, ela é colocada na exibição.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[30 NVC_MFC_CListBox](../../mfc/codesnippet/cpp/clistbox-class_30.cpp)]  
  
##  <a name="a-namesetcolumnwidtha--clistboxsetcolumnwidth"></a><a name="setcolumnwidth"></a>CListBox::SetColumnWidth  
 Define a largura em pixels de todas as colunas em uma caixa de listagem de várias colunas (criado com o [LBS_MULTICOLUMN](../../mfc/reference/list-box-styles.md) estilo).  
  
```  
void SetColumnWidth(int cxWidth);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cxWidth`  
 Especifica a largura em pixels de todas as colunas.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox&#31;](../../mfc/codesnippet/cpp/clistbox-class_31.cpp)]  
  
##  <a name="a-namesetcursela--clistboxsetcursel"></a><a name="setcursel"></a>CListBox::SetCurSel  
 Seleciona uma cadeia de caracteres e rola-lo no modo de exibição, se necessário.  
  
```  
int SetCurSel(int nSelect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSelect`  
 Especifica o índice baseado em zero da cadeia de caracteres a ser selecionado. Se `nSelect` é –&1;, a caixa de listagem é definida para não ter nenhuma seleção.  
  
### <a name="return-value"></a>Valor de retorno  
 `LB_ERR`Se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Quando a nova cadeia de caracteres é selecionada, a caixa de listagem remove o realce da cadeia de caracteres selecionada anteriormente.  
  
 Use esta função de membro apenas com caixas de listagem de seleção única.  
  
 Para definir ou remover uma seleção em uma caixa de listagem de seleção múltipla, use [CListBox::SetSel](#setsel).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[32 NVC_MFC_CListBox](../../mfc/codesnippet/cpp/clistbox-class_32.cpp)]  
  
##  <a name="a-namesethorizontalextenta--clistboxsethorizontalextent"></a><a name="sethorizontalextent"></a>CListBox::SetHorizontalExtent  
 Define a largura, em pixels, pelo qual uma caixa de listagem pode ser rolada horizontalmente.  
  
```  
void SetHorizontalExtent(int cxExtent);
```  
  
### <a name="parameters"></a>Parâmetros  
 *cxExtent*  
 Especifica o número de pixels por que a caixa de listagem pode ser rolada horizontalmente.  
  
### <a name="remarks"></a>Comentários  
 Se o tamanho da caixa de listagem é menor do que esse valor, a barra de rolagem horizontal rolar horizontalmente itens na caixa de listagem. Se a caixa de listagem é tão grande ou maior que esse valor, a barra de rolagem horizontal está oculta.  
  
 Para responder a uma chamada para `SetHorizontalExtent`, a caixa de listagem deve foram definida com o [WS_HSCROLL](../../mfc/reference/window-styles.md) estilo.  
  
 Essa função de membro não é útil para caixas de listagem de várias colunas. Para caixas de listagem de várias colunas, chame o `SetColumnWidth` função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[33 NVC_MFC_CListBox](../../mfc/codesnippet/cpp/clistbox-class_33.cpp)]  
  
##  <a name="a-namesetitemdataa--clistboxsetitemdata"></a><a name="setitemdata"></a>CListBox::SetItemData  
 Define um valor de 32 bits associado ao item especificado em uma caixa de listagem.  
  
```  
int SetItemData(
    int nIndex,  
    DWORD_PTR dwItemData);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice baseado em zero do item.  
  
 `dwItemData`  
 Especifica o valor a ser associado ao item.  
  
### <a name="return-value"></a>Valor de retorno  
 **LB_ERR** se ocorrer um erro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox&#34;](../../mfc/codesnippet/cpp/clistbox-class_34.cpp)]  
  
##  <a name="a-namesetitemdataptra--clistboxsetitemdataptr"></a><a name="setitemdataptr"></a>CListBox::SetItemDataPtr  
 Define o valor de 32 bits associado ao item especificado em uma caixa de lista para ser o ponteiro especificado ( **void\***).  
  
```  
int SetItemDataPtr(
    int nIndex,  
    void* pData);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice baseado em zero do item.  
  
 `pData`  
 Especifica o ponteiro para ser associado ao item.  
  
### <a name="return-value"></a>Valor de retorno  
 **LB_ERR** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Esse ponteiro permanece válido para a vida útil da caixa de listagem, mesmo que a posição relativa do item na caixa de listagem pode alterar como os itens são adicionados ou removidos. Portanto, pode alterar o índice do item dentro da caixa, mas o ponteiro permanece confiável.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox&#35;](../../mfc/codesnippet/cpp/clistbox-class_35.cpp)]  
  
##  <a name="a-namesetitemheighta--clistboxsetitemheight"></a><a name="setitemheight"></a>CListBox::SetItemHeight  
 Define a altura de itens em uma caixa de listagem.  
  
```  
int SetItemHeight(
    int nIndex,  
    UINT cyItemHeight);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice baseado em zero do item na caixa de listagem. Esse parâmetro é usado somente se a caixa de listagem tem o **LBS_OWNERDRAWVARIABLE** estilo; caso contrário, ele deve ser definido como 0.  
  
 `cyItemHeight`  
 Especifica a altura, em pixels, do item.  
  
### <a name="return-value"></a>Valor de retorno  
 **LB_ERR** se o índice ou a altura é inválida.  
  
### <a name="remarks"></a>Comentários  
 Se a caixa de listagem tem o [LBS_OWNERDRAWVARIABLE](../../mfc/reference/list-box-styles.md) estilo, essa função define a altura do item especificado por `nIndex`. Caso contrário, essa função define a altura de todos os itens na caixa de listagem.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox&#36;](../../mfc/codesnippet/cpp/clistbox-class_36.cpp)]  
  
##  <a name="a-namesetlocalea--clistboxsetlocale"></a><a name="setlocale"></a>CListBox::SetLocale  
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
 Se **SetLocale** não é chamado, o padrão é obtida localidade do sistema. Essa localidade padrão do sistema pode ser modificada por meio do painel de controle do aplicativo regionais (ou internacional).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox&#37;](../../mfc/codesnippet/cpp/clistbox-class_37.cpp)]  
  
##  <a name="a-namesetsela--clistboxsetsel"></a><a name="setsel"></a>CListBox::SetSel  
 Seleciona uma cadeia de caracteres em uma caixa de listagem de seleção múltipla.  
  
```  
int SetSel(
    int nIndex,  
    BOOL bSelect = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Contém o índice baseado em zero da cadeia de caracteres a ser definido. Se –&1;, a seleção é adicionada ou removida de todas as cadeias de caracteres, dependendo do valor de `bSelect`.  
  
 `bSelect`  
 Especifica como definir a seleção. Se `bSelect` é `TRUE`, a cadeia de caracteres está selecionada e realçada; se `FALSE`, o realce é removido e a cadeia de caracteres não está selecionada. A cadeia de caracteres especificada está selecionada e realçada por padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 `LB_ERR`Se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Use esta função de membro apenas com caixas de listagem de seleção múltipla.  
  
 Para selecionar um item em uma caixa de listagem de seleção única, use [CListBox::SetCurSel](#setcursel).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox&38;](../../mfc/codesnippet/cpp/clistbox-class_38.cpp)]  
  
##  <a name="a-namesettabstopsa--clistboxsettabstops"></a><a name="settabstops"></a>CListBox::SetTabStops  
 Define as posições de tabulação em uma caixa de listagem.  
  
```  
void SetTabStops();  
BOOL SetTabStops(const int& cxEachStop);

 
BOOL SetTabStops(
    int nTabStops,  
    LPINT rgTabStops);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cxEachStop`  
 Paradas de tabulação são definidas em cada `cxEachStop` unidades de diálogo. Consulte *rgTabStops* para obter uma descrição de uma unidade de diálogo.  
  
 `nTabStops`  
 Especifica o número de paradas de tabulação ter na caixa de listagem.  
  
 `rgTabStops`  
 Aponta para o primeiro membro de uma matriz de inteiros que contém as posições de tabulação em unidades de diálogo. Uma unidade de diálogo é uma distância horizontal ou vertical. Uma unidade de diálogo horizontal é igual a um quarto da unidade de largura de base da caixa de diálogo atual e uma unidade de diálogo vertical é igual a um oitavo da unidade de base altura da caixa de diálogo atual. As unidades base da caixa de diálogo são calculadas com base na altura e largura da fonte atual do sistema. O **GetDialogBaseUnits** função Windows retorna a caixa de diálogo atual unidades base em pixels. As paradas de tabulação devem ser classificadas em ordem; crescente tabulações à esquerda não são permitidas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se todas as guias foram definidas; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para definir paradas de tabulação para o tamanho padrão de 2 unidades de caixa de diálogo, chame a versão sem parâmetros dessa função de membro. Para definir paradas de tabulação em um tamanho diferente de 2, chame a versão com o `cxEachStop` argumento.  
  
 Para definir paradas de tabulação para uma matriz de tamanhos, use a versão com o `rgTabStops` e `nTabStops` argumentos. Uma parada de tabulação será definida para cada valor na `rgTabStops`, até o número especificado por `nTabStops`.  
  
 Para responder a uma chamada para o `SetTabStops` função de membro, a caixa de listagem deve ter sido criada com o [LBS_USETABSTOPS](../../mfc/reference/list-box-styles.md) estilo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CListBox&#39;](../../mfc/codesnippet/cpp/clistbox-class_39.cpp)]  
  
##  <a name="a-namesettopindexa--clistboxsettopindex"></a><a name="settopindex"></a>CListBox::SetTopIndex  
 Garante que um item específico da caixa de listagem está visível.  
  
```  
int SetTopIndex(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice baseado em zero do item de caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Zero se tiver êxito, ou **LB_ERR** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 O sistema rola a caixa de listagem até que o item especificado por `nIndex` aparece na parte superior da lista de caixa ou o intervalo de rolagem máximo foi atingido.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[40 NVC_MFC_CListBox](../../mfc/codesnippet/cpp/clistbox-class_40.cpp)]  
  
##  <a name="a-namevkeytoitema--clistboxvkeytoitem"></a><a name="vkeytoitem"></a>CListBox::VKeyToItem  
 Chamado pela estrutura quando a janela do pai da caixa de listagem recebe um `WM_VKEYTOITEM` mensagem da caixa de listagem.  
  
```  
virtual int VKeyToItem(
    UINT nKey,  
    UINT nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nKey`  
 O código de tecla virtual da chave que o usuário pressionou. Para obter uma lista de códigos de tecla virtuais padrão, consulte WinUser. h  
  
 `nIndex`  
 A posição atual do cursor de caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna – 2 para nenhuma outra ação, – 1 para ação padrão ou um número não negativo para especificar um índice de um item de caixa de listagem na qual executar a ação padrão para o pressionamento de teclas.  
  
### <a name="remarks"></a>Comentários  
 O `WM_VKEYTOITEM` mensagem é enviada pela caixa de listagem quando ele recebe um `WM_KEYDOWN` mensagem, mas somente se a caixa de listagem atende as seguintes:  
  
-   Tem o [LBS_WANTKEYBOARDINPUT](../../mfc/reference/list-box-styles.md) conjunto de estilos.  
  
-   Tem pelo menos um item.  
  
 Você nunca deve chamar essa função por conta própria. Substitua essa função para fornecer sua própria manipulação personalizada de mensagens do teclado.  
  
 Você deve retornar um valor para dizer à estrutura que ação executada sua substituição. Um valor de retorno de – 2 indica que o aplicativo tratados todos os aspectos de selecionando o item e não requer nenhuma ação adicional na caixa da lista. Retornando antes – 2, você pode definir a seleção ou mover o cursor ou ambos. Para definir a seleção, use [SetCurSel](#setcursel) ou [SetSel](#setsel). Para mover o cursor, use [SetCaretIndex](#setcaretindex).  
  
 Um valor de retorno de – 1 indica que a caixa de listagem deve realizar a ação padrão em resposta ao pressionamento de teclas. A implementação padrão retorna – 1.  
  
 Um valor de retorno de 0 ou maior Especifica o índice de um item na caixa de listagem e indica que a caixa de listagem deve realizar a ação padrão para o pressionamento de teclas em determinado item.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[41 NVC_MFC_CListBox](../../mfc/codesnippet/cpp/clistbox-class_41.cpp)]  
  
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

