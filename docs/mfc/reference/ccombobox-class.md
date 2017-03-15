---
title: Classe CComboBox | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComboBox
dev_langs:
- C++
helpviewer_keywords:
- combo boxes, CComboBox objects
- CComboBox class
ms.assetid: 4e73b5df-0d2e-4658-9706-38133fb10513
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
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 5328c245e0d662c4701042b37c16870d6b1e33c7
ms.lasthandoff: 02/25/2017

---
# <a name="ccombobox-class"></a>Classe CComboBox
Fornece a funcionalidade de uma caixa de combinação do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CComboBox : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComboBox::CComboBox](#ccombobox)|Constrói um objeto `CComboBox`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComboBox:: AddString](#addstring)|Adiciona uma cadeia de caracteres ao final da lista na caixa de listagem de uma caixa de combinação ou na posição classificada para caixas de listagem com a **CBS_SORT** estilo.|  
|[CComboBox::Clear](#clear)|Exclui (limpa) a seleção atual, se houver, no controle de edição.|  
|[CComboBox::CompareItem](#compareitem)|Chamado pela estrutura para determinar a posição relativa de um novo item de lista em uma caixa de combinação classificada desenhados pelo proprietário.|  
|[CComboBox::Copy](#copy)|Copia a seleção atual, se houver, na área de transferência em **CF_TEXT** formato.|  
|[CComboBox::Create](#create)|Cria a caixa de combinação e anexa-o para o `CComboBox` objeto.|  
|[CComboBox::Cut](#cut)|Exclui (cortes) a seleção atual, se houver, em Editar controlar e copia o texto excluído na área de transferência em **CF_TEXT** formato.|  
|[CComboBox::DeleteItem](#deleteitem)|Chamado pela estrutura quando um item de lista for excluído de uma caixa de combinação desenhados pelo proprietário.|  
|[CComboBox::DeleteString](#deletestring)|Exclui uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.|  
|[CComboBox::Dir](#dir)|Adiciona uma lista de nomes de arquivo para a caixa de listagem de uma caixa de combinação.|  
|[CComboBox::DrawItem](#drawitem)|Chamado pela estrutura quando um aspecto visual de um alterações de caixa de combinação desenhados pelo proprietário.|  
|[CComboBox:: FindString](#findstring)|Localiza a primeira cadeia de caracteres que contém o prefixo especificado na caixa de listagem de uma caixa de combinação.|  
|[CComboBox::FindStringExact](#findstringexact)|Localiza a primeira cadeia de caixa de listagem (em uma caixa de combinação) que corresponde a cadeia de caracteres especificada.|  
|[CComboBox::GetComboBoxInfo](#getcomboboxinfo)|Recupera informações sobre o `CComboBox` objeto.|  
|[CComboBox::GetCount](#getcount)|Recupera o número de itens na caixa de listagem de uma caixa de combinação.|  
|[CComboBox::GetCueBanner](#getcuebanner)|Obtém o texto de indicação que é exibido para um controle de caixa de combinação.|  
|[CComboBox::GetCurSel](#getcursel)|Recupera o índice do item selecionado no momento, se houver, na caixa de listagem de uma caixa de combinação.|  
|[CComboBox::GetDroppedControlRect](#getdroppedcontrolrect)|Recupera as coordenadas de tela da caixa de listagem (cancelados inativo) visível de uma caixa de combinação suspensa.|  
|[CComboBox::GetDroppedState](#getdroppedstate)|Determina se a caixa de listagem de uma caixa de combinação suspensa é visível (aberta).|  
|[CComboBox::GetDroppedWidth](#getdroppedwidth)|Recupera o mínimo permitido largura para a parte de caixa de listagem suspensa de uma caixa de combinação.|  
|[CComboBox::GetEditSel](#geteditsel)|Obtém as posições de caractere inicial e final da seleção atual no controle de edição de uma caixa de combinação.|  
|[CComboBox::GetExtendedUI](#getextendedui)|Determina se uma caixa de combinação tem a interface do usuário padrão ou a interface do usuário estendida.|  
|[CComboBox::GetHorizontalExtent](#gethorizontalextent)|Retorna a largura em pixels que a parte de caixa de listagem da caixa de combinação pode ser rolada horizontalmente.|  
|[CComboBox::GetItemData](#getitemdata)|Recupera o valor de 32 bits fornecida pelo aplicativo associado ao item de caixa de combinação especificada.|  
|[CComboBox::GetItemDataPtr](#getitemdataptr)|Recupera o ponteiro de 32 bits fornecida pelo aplicativo que está associado ao item de caixa de combinação especificada.|  
|[CComboBox::GetItemHeight](#getitemheight)|Recupera a altura dos itens de lista em uma caixa de combinação.|  
|[CComboBox::GetLBText](#getlbtext)|Obtém uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.|  
|[CComboBox::GetLBTextLen](#getlbtextlen)|Obtém o comprimento de uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.|  
|[CComboBox::GetLocale](#getlocale)|Recupera o identificador de localidade para uma caixa de combinação.|  
|[CComboBox::GetMinVisible](#getminvisible)|Obtém o número mínimo de itens visíveis na lista suspensa da caixa de combinação atual.|  
|[CComboBox::GetTopIndex](#gettopindex)|Retorna o índice do primeiro item visível na parte de caixa de listagem da caixa de combinação.|  
|[CComboBox::InitStorage](#initstorage)|Pré-alocar blocos de memória para itens e cadeias de caracteres na parte caixa de listagem da caixa de combinação.|  
|[CComboBox::InsertString](#insertstring)|Insere uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.|  
|[CComboBox::LimitText](#limittext)|Limita o comprimento do texto que o usuário pode inserir no controle de edição de uma caixa de combinação.|  
|[CComboBox::MeasureItem](#measureitem)|Chamado pela estrutura para determinar as dimensões da caixa de combinação quando uma caixa de combinação do desenho proprietário é criada.|  
|[CComboBox::Paste](#paste)|Insere os dados da área de transferência no controle de edição na posição atual do cursor. Os dados são inseridos somente se a área de transferência contém dados em **CF_TEXT** formato.|  
|[CComboBox::ResetContent](#resetcontent)|Remove todos os itens da lista de caixa e editar o controle de uma caixa de combinação.|  
|[CComboBox::SelectString](#selectstring)|Pesquisa uma cadeia de caracteres na caixa de listagem de uma caixa de combinação e, se a cadeia de caracteres for encontrada, seleciona a cadeia de caracteres na caixa de listagem e copia a cadeia de caracteres para o controle de edição.|  
|[CComboBox::SetCueBanner](#setcuebanner)|Define o texto de indicação que é exibido para um controle de caixa de combinação.|  
|[CComboBox::SetCurSel](#setcursel)|Seleciona uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.|  
|[CComboBox::SetDroppedWidth](#setdroppedwidth)|Define o mínimo permitido largura para a parte de caixa de listagem suspensa de uma caixa de combinação.|  
|[CComboBox::SetEditSel](#seteditsel)|Seleciona caracteres no controle de edição de uma caixa de combinação.|  
|[CComboBox::SetExtendedUI](#setextendedui)|Seleciona a interface do usuário padrão ou interface do usuário estendida para uma caixa de combinação que tem o **CBS_DROPDOWN** ou **CBS_DROPDOWNLIST** estilo.|  
|[CComboBox::SetHorizontalExtent](#sethorizontalextent)|Define a largura em pixels que a parte de caixa de listagem da caixa de combinação pode ser rolada horizontalmente.|  
|[CComboBox::SetItemData](#setitemdata)|Define o valor de 32 bits associado ao item especificado em uma caixa de combinação.|  
|[CComboBox::SetItemDataPtr](#setitemdataptr)|Define o ponteiro de 32 bits associado ao item especificado em uma caixa de combinação.|  
|[CComboBox::SetItemHeight](#setitemheight)|Define a altura de itens de lista em uma caixa de combinação ou a altura da parte do controle de edição (ou texto estático) de uma caixa de combinação.|  
|[CComboBox::SetLocale](#setlocale)|Define o identificador de localidade para uma caixa de combinação.|  
|[CComboBox::SetMinVisibleItems](#setminvisibleitems)|Define o número mínimo de itens visíveis na lista suspensa da caixa de combinação atual.|  
|[CComboBox::SetTopIndex](#settopindex)|Informa a parte de caixa de listagem da caixa de combinação para exibir o item com o índice especificado na parte superior.|  
|[CComboBox::ShowDropDown](#showdropdown)|Mostra ou oculta a caixa de listagem de uma caixa de combinação que tem o **CBS_DROPDOWN** ou **CBS_DROPDOWNLIST** estilo.|  
  
## <a name="remarks"></a>Comentários  
 Uma caixa de combinação consiste em uma caixa de lista combinada com um controle estático ou um controle de edição. A parte de caixa de listagem do controle pode ser exibida em todos os momentos ou pode apenas suspenso quando o usuário seleciona a seta suspensa ao lado do controle.  
  
 O item selecionado no momento (se houver) na caixa de listagem é exibido no estático ou controle de edição. Além disso, se a caixa de combinação com o estilo de lista suspensa, o usuário pode digitar o caractere inicial de um dos itens na lista e a caixa de listagem, caso esteja visível, realçará o próximo item com esse caractere inicial.  
  
 A tabela a seguir compara a caixa de combinação de três [estilos](../../mfc/reference/combo-box-styles.md).  
  
|Estilo|Quando a caixa de listagem está visível|Controle estático ou editar|  
|-----------|-------------------------------|-----------------------------|  
|Simples|Sempre|Editar|  
|Lista suspensa|Ao soltar para baixo|Editar|  
|Lista suspensa|Ao soltar para baixo|Estático|  
  
 Você pode criar um `CComboBox` objeto de um modelo de caixa de diálogo ou diretamente no seu código. Em ambos os casos, chame o construtor `CComboBox` para construir o `CComboBox` objeto; em seguida, chame o [criar](#create) a função de membro para criar o controle e anexá-lo a `CComboBox` objeto.  
  
 Se você quiser controlar mensagens de notificação do Windows enviadas por uma caixa de combinação para seu pai (normalmente uma classe derivada de `CDialog`), adicionar uma função de membro de entrada e o manipulador de mensagens do mapa da mensagem para a classe pai para cada mensagem.  
  
 Cada entrada de mapa de mensagem usa o seguinte formato:  
  
 **ON_**Notification **(**`id`**,**`memberFxn`**)**  
  
 onde `id` Especifica a ID de janela filho do controle de caixa de combinação enviando a notificação e `memberFxn` é o nome da função de membro pai que você gravou para tratar a notificação.  
  
 Protótipo de função do pai é o seguinte:  
  
 **afx_msg** `void` `memberFxn` **( );**  
  
 A ordem na qual determinadas notificações serão enviadas não pode ser prevista. Em particular, uma **CBN_SELCHANGE** notificação pode ocorrer antes ou depois de um **CBN_CLOSEUP** notificação.  
  
 Entradas de mapa de mensagem possíveis são os seguintes:  
  
- **ON_CBN_CLOSEUP** (Windows 3.1 e posterior). Caixa de listagem de uma caixa de combinação foi fechada. Essa mensagem de notificação não é enviada para uma caixa de combinação que tem o [CBS_SIMPLE](../../mfc/reference/combo-box-styles.md) estilo.  
  
- **ON_CBN_DBLCLK** o usuário clica duas vezes em uma cadeia de caracteres na caixa de listagem de uma caixa de combinação. Esta mensagem de notificação é enviada somente para uma caixa de combinação com o **CBS_SIMPLE** estilo. Para uma caixa de combinação com o [CBS_DROPDOWN](../../mfc/reference/combo-box-styles.md) ou [CBS_DROPDOWNLIST](../../mfc/reference/combo-box-styles.md) de estilo, um clique duplo não pode ocorrer porque um único clique oculta a caixa de listagem.  
  
- **ON_CBN_DROPDOWN** caixa de listagem de uma caixa de combinação está prestes a lista suspensa (se tornar visível). Essa mensagem de notificação pode ocorrer apenas para uma caixa de combinação com o **CBS_DROPDOWN** ou **CBS_DROPDOWNLIST** estilo.  
  
- **ON_CBN_EDITCHANGE** o usuário executou uma ação que pode ter alterado o texto na parte do controle de edição de uma caixa de combinação. Ao contrário do **CBN_EDITUPDATE** mensagem, essa mensagem é enviada após a tela de atualizações do Windows. Não é enviado se a caixa de combinação com o **CBS_DROPDOWNLIST** estilo.  
  
- **ON_CBN_EDITUPDATE** a parte do controle de edição de uma caixa de combinação está prestes a exibir o texto alterado. Esta mensagem de notificação é enviada depois que o controle tem o texto formatado, mas antes de exibir o texto. Não é enviado se a caixa de combinação com o **CBS_DROPDOWNLIST** estilo.  
  
- **ON_CBN_ERRSPACE** a caixa de combinação não é possível alocar memória suficiente para atender uma solicitação específica.  
  
- **ON_CBN_SELENDCANCEL** (Windows 3.1 e posterior). Indica que a seleção do usuário deve ser cancelada. O usuário clica em um item e, em seguida, clica em outra janela ou controle para ocultar a caixa de listagem de uma caixa de combinação. Essa mensagem de notificação é enviada antes do **CBN_CLOSEUP** mensagem de notificação para indicar que a seleção do usuário deve ser ignorada. O **CBN_SELENDCANCEL** ou **CBN_SELENDOK** mensagem de notificação é enviada mesmo se o **CBN_CLOSEUP** não é enviada a mensagem de notificação (como no caso de uma caixa de combinação com o **CBS_SIMPLE** estilo).  
  
- **ON_CBN_SELENDOK** o usuário seleciona um item e, em seguida, pressionar a tecla ENTER ou clica a seta para baixo para ocultar a caixa de listagem de uma caixa de combinação. Essa mensagem de notificação é enviada antes do **CBN_CLOSEUP** mensagem para indicar que a seleção do usuário deve ser considerada válida. O **CBN_SELENDCANCEL** ou **CBN_SELENDOK** mensagem de notificação é enviada mesmo se o **CBN_CLOSEUP** não é enviada a mensagem de notificação (como no caso de uma caixa de combinação com o **CBS_SIMPLE** estilo).  
  
- **ON_CBN_KILLFOCUS** a caixa de combinação é perder o foco de entrada.  
  
- **ON_CBN_SELCHANGE** a seleção na caixa de listagem de uma caixa de combinação está prestes a ser alterado como resultado do usuário clicar na caixa de listagem ou alterar a seleção usando as teclas de direção. Ao processar essa mensagem, o texto no controle de edição da caixa de combinação só pode ser recuperado `GetLBText` ou outra função semelhante. `GetWindowText`não pode ser usado.  
  
- **ON_CBN_SETFOCUS** a caixa de combinação recebe o foco de entrada.  
  
 Se você criar um `CComboBox` objeto dentro de uma caixa de diálogo (por meio de um recurso de caixa de diálogo), o `CComboBox` objeto é destruído automaticamente quando o usuário fecha a caixa de diálogo.  
  
 Se você inserir um `CComboBox` objeto dentro de outra janela do objeto, você não precisa destruí-lo. Se você criar o `CComboBox` do objeto na pilha, ele será destruído automaticamente. Se você criar o `CComboBox` objeto no heap usando o **novo** função, você deve chamar **excluir** no objeto para destruí-lo quando a caixa de combinação do Windows é destruída.  
  
 **Observação** se você quiser manipular `WM_KEYDOWN` e `WM_CHAR` mensagens, você tem a subclasse da caixa de combinação editar e controles de caixa de lista, derivar classes de `CEdit` e `CListBox`, e adicionar manipuladores para essas mensagens para as classes derivadas. Para obter mais informações, consulte [http://support.microsoft.com/default.aspxscid=kb;en-us; Q174667](http://support.microsoft.com/default.aspxscid=kb;en-us;q174667) e [CWnd::SubclassWindow](../../mfc/reference/cwnd-class.md#subclasswindow).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CComboBox`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="a-nameaddstringa--ccomboboxaddstring"></a><a name="addstring"></a>CComboBox:: AddString  
 Adiciona uma cadeia de caracteres para a caixa de listagem de uma caixa de combinação.  
  
```  
int AddString(LPCTSTR lpszString);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszString`  
 Aponta para a cadeia de caracteres terminada em nulo que deve ser adicionado.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o valor de retorno é maior que ou igual a 0, é o índice baseado em zero para a cadeia de caracteres na caixa de listagem. O valor de retorno é **CB_ERR** se ocorrer um erro; o valor de retorno é **CB_ERRSPACE** se houver espaço suficiente armazenar a nova cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Se a caixa de listagem não foi criada com o [CBS_SORT](../../mfc/reference/combo-box-styles.md) estilo, a cadeia de caracteres é adicionada ao final da lista. Caso contrário, a cadeia de caracteres é inserida na lista, e a lista é classificada.  
  
> [!NOTE]
>  Essa função não é suportado pelo Windows **ComboBoxEx** controle. Para obter mais informações sobre esse controle, consulte [ComboBoxEx controles](http://msdn.microsoft.com/library/windows/desktop/bb775738) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Para inserir uma cadeia de caracteres em um local específico na lista, use o [InsertString](#insertstring) função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox n º&3;](../../mfc/reference/codesnippet/cpp/ccombobox-class_1.cpp)]  
  
##  <a name="a-nameccomboboxa--ccomboboxccombobox"></a><a name="ccombobox"></a>CComboBox::CComboBox  
 Constrói um objeto `CComboBox`.  
  
```  
CComboBox();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox n º&1;](../../mfc/reference/codesnippet/cpp/ccombobox-class_2.cpp)]  
  
##  <a name="a-namecleara--ccomboboxclear"></a><a name="clear"></a>CComboBox::Clear  
 Exclui (limpa) a seleção atual, se houver, no controle de edição da caixa de combinação.  
  
```  
void Clear();
```  
  
### <a name="remarks"></a>Comentários  
 Para excluir a seleção atual e colocar o conteúdo excluído na área de transferência, use o [Recortar](#cut) função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox n º&4;](../../mfc/reference/codesnippet/cpp/ccombobox-class_3.cpp)]  
  
##  <a name="a-namecompareitema--ccomboboxcompareitem"></a><a name="compareitem"></a>CComboBox::CompareItem  
 Chamado pela estrutura para determinar a posição relativa de um novo item na parte caixa de listagem de uma caixa de combinação do desenho proprietário classificada.  
  
```  
virtual int CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpCompareItemStruct`  
 Um ponteiro de tempo para um [COMPAREITEMSTRUCT](../../mfc/reference/compareitemstruct-structure.md) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Indica a posição relativa dos dois itens descrito o `COMPAREITEMSTRUCT` estrutura. Ele pode ser qualquer um dos seguintes valores:  
  
|Valor|Significado|  
|-----------|-------------|  
|– 1|Item 1 classifica antes do item 2.|  
|0|Item 1 e item 2 classificar o mesmo.|  
|1|Item 1 classifica após o item 2.|  
  
 Consulte [CWnd::OnCompareItem](../../mfc/reference/cwnd-class.md#oncompareitem) para obter uma descrição de `COMPAREITEMSTRUCT`.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, essa função de membro não fará nada. Se você criar uma caixa de combinação do desenho proprietário com o **LBS_SORT** estilo, você deve substituir essa função de membro para ajudar a estrutura de classificação novos itens adicionados à caixa de listagem.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox n º&5;](../../mfc/reference/codesnippet/cpp/ccombobox-class_4.cpp)]  
  
##  <a name="a-namecopya--ccomboboxcopy"></a><a name="copy"></a>CComboBox::Copy  
 Copia a seleção atual, se houver, no controle de edição da caixa de combinação na área de transferência em **CF_TEXT** formato.  
  
```  
void Copy();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox n º&6;](../../mfc/reference/codesnippet/cpp/ccombobox-class_5.cpp)]  
  
##  <a name="a-namecreatea--ccomboboxcreate"></a><a name="create"></a>CComboBox::Create  
 Cria a caixa de combinação e anexa-o para o `CComboBox` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Especifica o estilo da caixa de combinação. Aplique qualquer combinação de [estilos de caixa de combinação](../../mfc/reference/combo-box-styles.md) para a caixa.  
  
 `rect`  
 Aponta para a posição e o tamanho da caixa de combinação. Pode ser um [estrutura RECT](../../mfc/reference/rect-structure1.md) ou um `CRect` objeto.  
  
 `pParentWnd`  
 Especifica a janela do pai da caixa de combinação (geralmente um `CDialog`). Ele não deve ser **nulo**.  
  
 `nID`  
 Especifica a ID de controle. da caixa de combinação  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você construir um `CComboBox` objeto em duas etapas. Primeiro, chame o construtor e, em seguida, chame **criar**, que cria a caixa de combinação do Windows e anexa-o para o `CComboBox` objeto.  
  
 Quando **criar** executa o Windows envia o [WM_NCCREATE](../../mfc/reference/cwnd-class.md#onnccreate), [WM_CREATE](../../mfc/reference/cwnd-class.md#oncreate), [WM_NCCALCSIZE](../../mfc/reference/cwnd-class.md#onnccalcsize), e [WM_GETMINMAXINFO](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) mensagens à caixa de combinação.  
  
 Essas mensagens são manipuladas por padrão, o [OnNcCreate](../../mfc/reference/cwnd-class.md#onnccreate), [OnCreate](../../mfc/reference/cwnd-class.md#oncreate), [OnNcCalcSize](../../mfc/reference/cwnd-class.md#onnccalcsize), e [OnGetMinMaxInfo](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) funções de membro na `CWnd` classe base. Para estender a manipulação de mensagem padrão, derive uma classe de `CComboBox`, adicione um mapa da mensagem para a nova classe e substituir as funções de membro anterior do manipulador de mensagens. Substituir `OnCreate`, por exemplo, para executar inicialização necessária para uma nova classe.  
  
 Aplique o seguinte [estilos de janela](../../mfc/reference/window-styles.md) a um controle de caixa de combinação. :  
  
- **Estilo** sempre  
  
- **WS_VISIBLE** geral  
  
- **WS_DISABLED** raramente  
  
- **WS_VSCROLL** para adicionar a rolagem vertical da caixa de listagem na caixa de combinação  
  
- **WS_HSCROLL** para adicionar a rolagem horizontal da caixa de listagem na caixa de combinação  
  
- **WS_GROUP** para agrupar controles  
  
- **WS_TABSTOP** para incluir a caixa de combinação na ordem de tabulação  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox n º&2;](../../mfc/reference/codesnippet/cpp/ccombobox-class_6.cpp)]  
  
##  <a name="a-namecuta--ccomboboxcut"></a><a name="cut"></a>CComboBox::Cut  
 (Cortes) exclui a seleção atual, se houver, na caixa de combinação Editar controlar e copia o texto excluído na área de transferência em **CF_TEXT** formato.  
  
```  
void Cut();
```  
  
### <a name="remarks"></a>Comentários  
 Para excluir a seleção atual sem colocar o texto excluído na área de transferência, chame o [limpar](#clear) função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox&#7;](../../mfc/reference/codesnippet/cpp/ccombobox-class_7.cpp)]  
  
##  <a name="a-namedeleteitema--ccomboboxdeleteitem"></a><a name="deleteitem"></a>CComboBox::DeleteItem  
 Chamado pela estrutura quando o usuário exclui um item de um desenho proprietário `CComboBox` de objeto ou destrói a caixa de combinação.  
  
```  
virtual void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpDeleteItemStruct`  
 Um ponteiro longo para um Windows [DELETEITEMSTRUCT](../../mfc/reference/deleteitemstruct-structure.md) estrutura que contém informações sobre o item excluído. Consulte [CWnd::OnDeleteItem](../../mfc/reference/cwnd-class.md#ondeleteitem) para obter uma descrição dessa estrutura.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função não faz nada. Substitua essa função para redesenhar a caixa de combinação, conforme necessário.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox n º&8;](../../mfc/reference/codesnippet/cpp/ccombobox-class_8.cpp)]  
  
##  <a name="a-namedeletestringa--ccomboboxdeletestring"></a><a name="deletestring"></a>CComboBox::DeleteString  
 Exclui o item na posição `nIndex` da caixa de combinação.  
  
```  
int DeleteString(UINT nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice para a cadeia de caracteres que deve ser excluído.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o valor de retorno é maior que ou igual a 0, ela é uma contagem das cadeias de caracteres restantes na lista. O valor de retorno é **CB_ERR** se `nIndex` Especifica um índice maior que o número de itens na lista.  
  
### <a name="remarks"></a>Comentários  
 Todos os itens a seguir `nIndex` Agora mova uma posição para baixo. Por exemplo, se uma caixa de combinação contém dois itens, excluir o primeiro item fará com que o item restante a ser agora na primeira posição. `nIndex`=&0; para o item na primeira posição.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox n º&9;](../../mfc/reference/codesnippet/cpp/ccombobox-class_9.cpp)]  
  
##  <a name="a-namedira--ccomboboxdir"></a><a name="dir"></a>CComboBox::Dir  
 Adiciona uma lista de nomes de arquivos ou unidades à caixa de listagem de uma caixa de combinação.  
  
```  
int Dir(
    UINT attr,  
    LPCTSTR lpszWildCard);
```  
  
### <a name="parameters"></a>Parâmetros  
 `attr`  
 Pode ser qualquer combinação de `enum` valores descritos na [cfile:: getStatus](../../mfc/reference/cfile-class.md#getstatus) ou qualquer combinação dos seguintes valores:  
  
- **DDL_READWRITE** arquivo pode ser lido ou gravado.  
  
- **DDL_READONLY** arquivo pode ser lido de mas não gravado.  
  
- **DDL_HIDDEN** arquivo está oculto e não aparece em uma listagem de diretório.  
  
- **DDL_SYSTEM** é um arquivo de sistema.  
  
- **DDL_DIRECTORY** o nome especificado pelo `lpszWildCard` Especifica um diretório.  
  
- **DDL_ARCHIVE** arquivo foi arquivado.  
  
- **DDL_DRIVES** incluem todas as unidades que correspondem ao nome especificado pelo `lpszWildCard`.  
  
- **DDL_EXCLUSIVE** sinalizador exclusivo. Se o sinalizador exclusivo é definido, somente os arquivos do tipo especificado serão listados. Caso contrário, os arquivos do tipo especificado são listados além dos arquivos "normais".  
  
 `lpszWildCard`  
 Aponta para uma cadeia de caracteres de especificação de arquivo. A cadeia de caracteres pode conter caracteres curinga (por exemplo, *.\*).  
  
### <a name="return-value"></a>Valor de retorno  
 Se o valor de retorno é maior que ou igual a 0, é o índice baseado em zero do último nome de arquivo adicionado à lista. O valor de retorno é **CB_ERR** se ocorrer um erro; o valor de retorno é **CB_ERRSPACE** se houver espaço suficiente armazenar novas cadeias de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Essa função não é suportado pelo Windows **ComboBoxEx** controle. Para obter mais informações sobre esse controle, consulte [ComboBoxEx controles](http://msdn.microsoft.com/library/windows/desktop/bb775738) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox n º&10;](../../mfc/reference/codesnippet/cpp/ccombobox-class_10.cpp)]  
  
##  <a name="a-namedrawitema--ccomboboxdrawitem"></a><a name="drawitem"></a>CComboBox::DrawItem  
 Chamado pela estrutura quando um aspecto visual de um alterações de caixa de combinação do desenho proprietário.  
  
```  
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpDrawItemStruct`  
 Um ponteiro para um [DRAWITEMSTRUCT](../../mfc/reference/drawitemstruct-structure.md) estrutura que contém informações sobre o tipo de desenho necessárias.  
  
### <a name="remarks"></a>Comentários  
 O **itemAction** membro o `DRAWITEMSTRUCT` estrutura define a ação de desenho que deve ser executada. Consulte [CWnd::OnDrawItem](../../mfc/reference/cwnd-class.md#ondrawitem) para obter uma descrição dessa estrutura.  
  
 Por padrão, essa função de membro não fará nada. Substituir essa função de membro para implementar o desenho de um desenho proprietário `CComboBox` objeto. Antes de termina essa função de membro, o aplicativo deve restaurar todos os objetos GDI (interface) do dispositivo gráfico selecionados para o contexto de exibição fornecidos no `lpDrawItemStruct`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox n º&11;](../../mfc/reference/codesnippet/cpp/ccombobox-class_11.cpp)]  
  
##  <a name="a-namefindstringa--ccomboboxfindstring"></a><a name="findstring"></a>CComboBox:: FindString  
 Encontrar, mas não selecionar, a primeira cadeia de caracteres que contém o prefixo especificado na caixa de listagem de uma caixa de combinação.  
  
```  
int FindString(
    int nStartAfter,  
    LPCTSTR lpszString) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nStartAfter`  
 Contém o índice baseado em zero do item antes do primeiro item a ser pesquisada. Quando a pesquisa chega a parte inferior da caixa de listagem, ele continua na parte superior da caixa de listagem no item especificado por `nStartAfter`. Se –&1;, a caixa de listagem inteira é pesquisada desde o início.  
  
 `lpszString`  
 Aponta para a cadeia de caracteres terminada em nulo que contém o prefixo para pesquisar. A pesquisa é o caso independente, portanto essa cadeia de caracteres pode conter qualquer combinação de letras maiusculas e minúsculas.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o valor de retorno é maior que ou igual a 0, é o índice baseado em zero do item correspondente. É **CB_ERR** se a pesquisa foi bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 Essa função não é suportado pelo Windows **ComboBoxEx** controle. Para obter mais informações sobre esse controle, consulte [ComboBoxEx controles](http://msdn.microsoft.com/library/windows/desktop/bb775738) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox&#12;](../../mfc/reference/codesnippet/cpp/ccombobox-class_12.cpp)]  
  
##  <a name="a-namefindstringexacta--ccomboboxfindstringexact"></a><a name="findstringexact"></a>CComboBox::FindStringExact  
 Chamar o `FindStringExact` a função de membro para localizar a primeira cadeia de caixa de listagem (em uma caixa de combinação) que corresponde a cadeia de caracteres especificada em `lpszFind`.  
  
```  
int FindStringExact(
    int nIndexStart,  
    LPCTSTR lpszFind) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndexStart`  
 Especifica o índice baseado em zero do item antes do primeiro item a ser pesquisada. Quando a pesquisa chega a parte inferior da caixa de listagem, ele continua na parte superior da caixa de listagem no item especificado por `nIndexStart`. Se `nIndexStart` é –&1;, a caixa de listagem inteira é pesquisada desde o início.  
  
 `lpszFind`  
 Aponta para a cadeia de caracteres terminada em nulo para pesquisar. Essa cadeia de caracteres pode conter um nome de arquivo completo, incluindo a extensão. A pesquisa não diferencia maiusculas de minúsculas, portanto essa cadeia de caracteres pode conter qualquer combinação de letras maiusculas e minúsculas.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero do item correspondente, ou **CB_ERR** se a pesquisa foi bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 Se a caixa de combinação foi criada com um estilo de desenho do proprietário, mas sem o [CBS_HASSTRINGS](../../mfc/reference/combo-box-styles.md) estilo, `FindStringExact` tenta corresponder o valor de palavras duplas em relação ao valor de `lpszFind`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox&13;](../../mfc/reference/codesnippet/cpp/ccombobox-class_13.cpp)]  
  
##  <a name="a-namegetcomboboxinfoa--ccomboboxgetcomboboxinfo"></a><a name="getcomboboxinfo"></a>CComboBox::GetComboBoxInfo  
 Recupera informações para o `CComboBox` objeto.  
  
```  
BOOL GetComboBoxInfo(PCOMBOBOXINFO pcbi) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pcbi*  
 Um ponteiro para o [COMBOBOXINFO](http://msdn.microsoft.com/library/windows/desktop/bb775798) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** com êxito, **FALSE** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade do [CB_GETCOMBOBOXINFO](http://msdn.microsoft.com/library/windows/desktop/bb775839) mensagem, conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetcounta--ccomboboxgetcount"></a><a name="getcount"></a>CComboBox::GetCount  
 Chame essa função de membro para recuperar o número de itens na parte da caixa de listagem de uma caixa de combinação.  
  
```  
int GetCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens. A contagem retornada é maior do que o valor de índice do último item (o índice é baseado em zero). É **CB_ERR** se ocorrer um erro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox&#14;](../../mfc/reference/codesnippet/cpp/ccombobox-class_14.cpp)]  
  
##  <a name="a-namegetcuebannera--ccomboboxgetcuebanner"></a><a name="getcuebanner"></a>CComboBox::GetCueBanner  
 Obtém o texto de indicação que é exibido para um controle de caixa de combinação.  
  
```  
CString GetCueBanner() const;  
  
BOOL GetCueBanner(
    LPTSTR lpszText,   
    int cchText) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[out] `lpszText`|Ponteiro para um buffer que receberá o texto da faixa de indicação.|  
|[in] `cchText`|Tamanho do buffer que o `lpszText` parâmetro aponta.|  
  
### <a name="return-value"></a>Valor de retorno  
 Na primeira sobrecarga, uma [CString](../../atl-mfc-shared/using-cstring.md) objeto que contém o texto da faixa de indicação se existir; caso contrário, um `CString` objeto que tem comprimento zero.  
  
 -ou-  
  
 Na segunda sobrecarga, `true` se esse método for bem-sucedida; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Texto de indicação é uma solicitação que é exibida na área de entrada de controle de caixa de combinação. O texto de indicação é exibido até que o usuário forneça uma entrada.  
  
 Esse método envia o [CB_GETCUEBANNER](http://msdn.microsoft.com/library/windows/desktop/bb775843) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetcursela--ccomboboxgetcursel"></a><a name="getcursel"></a>CComboBox::GetCurSel  
 Chame essa função de membro para determinar qual item na caixa de combinação está selecionado.  
  
```  
int GetCurSel() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero do item atualmente selecionado na caixa de listagem de uma caixa de combinação ou **CB_ERR** se nenhum item é selecionado.  
  
### <a name="remarks"></a>Comentários  
 `GetCurSel`Retorna um índice na lista.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox&#15;](../../mfc/reference/codesnippet/cpp/ccombobox-class_15.cpp)]  
  
##  <a name="a-namegetdroppedcontrolrecta--ccomboboxgetdroppedcontrolrect"></a><a name="getdroppedcontrolrect"></a>CComboBox::GetDroppedControlRect  
 Chamar o `GetDroppedControlRect` função de membro para recuperar as coordenadas de tela da caixa visível (descartado) na lista suspensa de uma caixa de combinação suspensa.  
  
```  
void GetDroppedControlRect(LPRECT lprect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *lprect*  
 Aponta para a [estrutura RECT](../../mfc/reference/rect-structure1.md) que deve receber as coordenadas.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox n º&16;](../../mfc/reference/codesnippet/cpp/ccombobox-class_16.cpp)]  
  
##  <a name="a-namegetdroppedstatea--ccomboboxgetdroppedstate"></a><a name="getdroppedstate"></a>CComboBox::GetDroppedState  
 Chamar o `GetDroppedState` a função de membro para determinar se a caixa de listagem de uma caixa de combinação suspensa é visível (aberta).  
  
```  
BOOL GetDroppedState() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a caixa de listagem estiver visível; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[17 NVC_MFC_CComboBox](../../mfc/reference/codesnippet/cpp/ccombobox-class_17.cpp)]  
  
##  <a name="a-namegetdroppedwidtha--ccomboboxgetdroppedwidth"></a><a name="getdroppedwidth"></a>CComboBox::GetDroppedWidth  
 Chame essa função para recuperar a largura mínima permitida, em pixels, da caixa de listagem de uma caixa de combinação.  
  
```  
int GetDroppedWidth() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, a largura mínima permitida, em pixels. Caso contrário, **CB_ERR**.  
  
### <a name="remarks"></a>Comentários  
 Essa função só se aplica às caixas de combinação com o [CBS_DROPDOWN](../../mfc/reference/combo-box-styles.md) ou [CBS_DROPDOWNLIST](../../mfc/reference/combo-box-styles.md) estilo.  
  
 Por padrão, a largura mínima permitida da caixa de listagem suspensa é 0. A largura mínima de permitido pode ser definida ao chamar [SetDroppedWidth](#setdroppedwidth). Quando a parte de caixa de listagem da caixa de combinação for exibida, sua largura é maior do mínima permitida largura ou a largura da caixa de combinação.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [SetDroppedWidth](#setdroppedwidth).  
  
##  <a name="a-namegeteditsela--ccomboboxgeteditsel"></a><a name="geteditsel"></a>CComboBox::GetEditSel  
 Obtém as posições de caractere inicial e final da seleção atual no controle de edição de uma caixa de combinação.  
  
```  
DWORD GetEditSel() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de 32 bits que contém a posição inicial da palavra de ordem inferior e a posição do primeiro caractere não selecionado após o final da seleção da palavra de ordem superior. Se essa função é usada em uma caixa de combinação sem um controle de edição, **CB_ERR** é retornado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox n º&18;](../../mfc/reference/codesnippet/cpp/ccombobox-class_18.cpp)]  
  
##  <a name="a-namegetextendeduia--ccomboboxgetextendedui"></a><a name="getextendedui"></a>CComboBox::GetExtendedUI  
 Chamar o `GetExtendedUI` a função de membro para determinar se uma caixa de combinação tem a interface do usuário padrão ou a interface do usuário estendida.  
  
```  
BOOL GetExtendedUI() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a caixa de combinação com a interface do usuário estendida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A interface do usuário estendida pode ser identificada das seguintes maneiras:  
  
-   Clicando no controle estático exibe a caixa de listagem apenas para caixas de combinação com o [CBS_DROPDOWNLIST](../../mfc/reference/combo-box-styles.md) estilo.  
  
-   Pressionar a tecla de seta para baixo exibirá a caixa de lista (F4 desabilitado).  
  
 Rolagem no controle estático é desabilitada quando a lista de itens não é visível (seta chaves estão desabilitadas).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[19 NVC_MFC_CComboBox](../../mfc/reference/codesnippet/cpp/ccombobox-class_19.cpp)]  
  
##  <a name="a-namegethorizontalextenta--ccomboboxgethorizontalextent"></a><a name="gethorizontalextent"></a>CComboBox::GetHorizontalExtent  
 Recupera a largura em pixels pelo qual a parte de caixa de listagem da caixa de combinação pode ser rolada horizontalmente da caixa de combinação.  
  
```  
UINT GetHorizontalExtent() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A largura rolável da parte caixa de listagem da caixa de combinação, em pixels.  
  
### <a name="remarks"></a>Comentários  
 Isso é aplicável somente se a parte de caixa de listagem da caixa de combinação tem uma barra de rolagem horizontal.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[20 NVC_MFC_CComboBox](../../mfc/reference/codesnippet/cpp/ccombobox-class_20.cpp)]  
  
##  <a name="a-namegetitemdataa--ccomboboxgetitemdata"></a><a name="getitemdata"></a>CComboBox::GetItemData  
 Recupera o valor de 32 bits fornecida pelo aplicativo associado ao item de caixa de combinação especificada.  
  
```  
DWORD_PTR GetItemData(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Contém o índice com base em zero de um item na caixa de listagem da caixa de combinação.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de 32 bits associado ao item ou **CB_ERR** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 O valor de 32 bits pode ser definido com o `dwItemData` parâmetro de um [SetItemData](#setitemdata) chamada de função de membro. Use o `GetItemDataPtr` se o valor de 32 bits a ser recuperado é um ponteiro de função de membro ( **void\***).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox&#21;](../../mfc/reference/codesnippet/cpp/ccombobox-class_21.cpp)]  
  
##  <a name="a-namegetitemdataptra--ccomboboxgetitemdataptr"></a><a name="getitemdataptr"></a>CComboBox::GetItemDataPtr  
 Recupera o valor de 32 bits fornecida pelo aplicativo associado ao item de caixa de combinação especificado como um ponteiro ( **void\***).  
  
```  
void* GetItemDataPtr(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Contém o índice com base em zero de um item na caixa de listagem da caixa de combinação.  
  
### <a name="return-value"></a>Valor de retorno  
 Recupera um ponteiro, ou -1 se ocorrer um erro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox&#22;](../../mfc/reference/codesnippet/cpp/ccombobox-class_22.cpp)]  
  
##  <a name="a-namegetitemheighta--ccomboboxgetitemheight"></a><a name="getitemheight"></a>CComboBox::GetItemHeight  
 Chamar o `GetItemHeight` função de membro para recuperar a altura dos itens de lista em uma caixa de combinação.  
  
```  
int GetItemHeight(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o componente da caixa de combinação cuja altura deve ser recuperado. Se o `nIndex` parâmetro é –&1;, a altura da parte do controle de edição (ou texto estático) da caixa de combinação é recuperada. Se a caixa de combinação com o [CBS_OWNERDRAWVARIABLE](../../mfc/reference/combo-box-styles.md) estilo, `nIndex` Especifica o índice baseado em zero do item de lista cuja altura deve ser recuperado. Caso contrário, `nIndex` deve ser definido como 0.  
  
### <a name="return-value"></a>Valor de retorno  
 A altura, em pixels, do item especificado em uma caixa de combinação. O valor de retorno é **CB_ERR** se ocorrer um erro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox&#23;](../../mfc/reference/codesnippet/cpp/ccombobox-class_23.cpp)]  
  
##  <a name="a-namegetlbtexta--ccomboboxgetlbtext"></a><a name="getlbtext"></a>CComboBox::GetLBText  
 Obtém uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.  
  
```  
int GetLBText(
    int nIndex,  
    LPTSTR lpszText) const;  
  
void GetLBText(
    int nIndex,  
    CString& rString) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Contém o índice baseado em zero da cadeia de caracteres da caixa de listagem a ser copiado.  
  
 `lpszText`  
 Aponta para um buffer que receberá a cadeia de caracteres. O buffer deve ter espaço suficiente para a cadeia de caracteres e um caractere nulo de terminação.  
  
 `rString`  
 Uma referência a um `CString`.  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento (em bytes) da cadeia de caracteres, exceto o caractere de terminação nula. Se `nIndex` não especificar um índice válido, o valor de retorno é **CB_ERR**.  
  
### <a name="remarks"></a>Comentários  
 O segundo formulário deste membro de função preenche uma `CString` objeto com o texto do item.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox&#24;](../../mfc/reference/codesnippet/cpp/ccombobox-class_24.cpp)]  
  
##  <a name="a-namegetlbtextlena--ccomboboxgetlbtextlen"></a><a name="getlbtextlen"></a>CComboBox::GetLBTextLen  
 Obtém o comprimento de uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.  
  
```  
int GetLBTextLen(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Contém o índice baseado em zero da cadeia de caracteres de caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento da cadeia de caracteres em bytes, excluindo o caractere de terminação nula. Se `nIndex` não especificar um índice válido, o valor de retorno é **CB_ERR**.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CComboBox::GetLBText](#getlbtext).  
  
##  <a name="a-namegetlocalea--ccomboboxgetlocale"></a><a name="getlocale"></a>CComboBox::GetLocale  
 Recupera a localidade usada por caixa de combinação.  
  
```  
LCID GetLocale() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor LCID (identificador) da localidade para cadeias de caracteres na caixa de combinação.  
  
### <a name="remarks"></a>Comentários  
 A localidade é usada, por exemplo, para determinar a ordem de classificação de cadeias de caracteres em uma caixa de combinação classificada.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CComboBox::SetLocale](#setlocale).  
  
##  <a name="a-namegetminvisiblea--ccomboboxgetminvisible"></a><a name="getminvisible"></a>CComboBox::GetMinVisible  
 Obtém o número mínimo de itens visíveis na lista suspensa de controle de caixa de combinação atual.  
  
```  
int GetMinVisible() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número mínimo de itens visíveis na lista suspensa atual.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [CB_GETMINVISIBLE](http://msdn.microsoft.com/library/windows/desktop/bb775915) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegettopindexa--ccomboboxgettopindex"></a><a name="gettopindex"></a>CComboBox::GetTopIndex  
 Retorna o índice baseado em zero do primeiro item visível na parte de caixa de listagem da caixa de combinação.  
  
```  
int GetTopIndex() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero do primeiro item visível na parte de caixa de listagem da caixa de combinação, se for bem-sucedido, **CB_ERR** caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Inicialmente, o item 0 está na parte superior da caixa de listagem, mas se a caixa de listagem é rolada, outro item pode estar na parte superior.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[25 NVC_MFC_CComboBox](../../mfc/reference/codesnippet/cpp/ccombobox-class_25.cpp)]  
  
##  <a name="a-nameinitstoragea--ccomboboxinitstorage"></a><a name="initstorage"></a>CComboBox::InitStorage  
 Aloca memória para armazenar itens de caixa de lista na parte de caixa de listagem da caixa de combinação.  
  
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
 Se for bem-sucedido, o número máximo de itens que a parte de caixa de listagem da caixa de combinação pode armazenar antes de a realocação de memória é necessário, caso contrário, **CB_ERRSPACE**, que significa que não há memória suficiente está disponível.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função antes de adicionar um grande número de itens para a parte da caixa de lista de `CComboBox`.  
  
 Windows 95/98 somente: O `wParam` parâmetro é limitado aos valores de 16 bits. Isso significa que caixas de listagem não podem conter mais de 32.767 itens. Embora o número de itens é restrito, o tamanho total dos itens em uma caixa de listagem é limitado apenas pela memória disponível.  
  
 Essa função ajuda a acelerar a inicialização das caixas de listagem que têm um grande número de itens (mais de 100). Ele pré-alocar a quantidade especificada de memória subsequente assim que [AddString](#addstring), [InsertString](#insertstring), e [Dir](#dir) funções usam o menor tempo possível. Você pode usar estimativas para os parâmetros. Se você estimar, é alocada memória extra; Se você subestimar, a alocação normal é usada para itens que excedem a quantidade pré-alocados.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox&#26;](../../mfc/reference/codesnippet/cpp/ccombobox-class_26.cpp)]  
  
##  <a name="a-nameinsertstringa--ccomboboxinsertstring"></a><a name="insertstring"></a>CComboBox::InsertString  
 Insere uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.  
  
```  
int InsertString(
    int nIndex,  
    LPCTSTR lpszString);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Contém o índice com base em zero para a posição na caixa de listagem que receberá a cadeia de caracteres. Se esse parâmetro é –&1;, a cadeia de caracteres é adicionada ao final da lista.  
  
 `lpszString`  
 Aponta para a cadeia de caracteres terminada em nulo que deve ser inserido.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero da posição em que a cadeia de caracteres foi inserida. O valor de retorno é **CB_ERR** se ocorrer um erro. O valor de retorno é **CB_ERRSPACE** se houver espaço suficiente armazenar a nova cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Ao contrário de [AddString](#addstring) função de membro, o `InsertString` função de membro não faz com que uma lista com o [CBS_SORT](../../mfc/reference/combo-box-styles.md) estilo a ser classificada.  
  
> [!NOTE]
>  Essa função não é suportado pelo Windows **ComboBoxEx** controle. Para obter mais informações sobre esse controle, consulte [ComboBoxEx controles](http://msdn.microsoft.com/library/windows/desktop/bb775738) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox&#27;](../../mfc/reference/codesnippet/cpp/ccombobox-class_27.cpp)]  
  
##  <a name="a-namelimittexta--ccomboboxlimittext"></a><a name="limittext"></a>CComboBox::LimitText  
 Limita o comprimento em bytes do texto que o usuário pode inserir no controle de edição de uma caixa de combinação.  
  
```  
BOOL LimitText(int nMaxChars);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMaxChars`  
 Especifica o comprimento (em bytes) do que o usuário pode digitar texto. Se esse parâmetro for 0, o comprimento do texto é definido como 65.535 bytes.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedido. Se a chamada para uma caixa de combinação com o estilo [CBS_DROPDOWNLIST](../../mfc/reference/combo-box-styles.md) ou para uma caixa de combinação sem um controle de edição, o valor de retorno é **CB_ERR**.  
  
### <a name="remarks"></a>Comentários  
 Se a caixa de combinação não tem o estilo [CBS_AUTOHSCROLL](../../mfc/reference/combo-box-styles.md), definir o limite de texto seja maior que o tamanho do controle de edição não terá efeito.  
  
 `LimitText`só limita o texto que o usuário pode inserir. Ele não tem efeito em qualquer texto já no controle de edição quando a mensagem é enviada, nem afeta o tamanho do texto copiado para o controle de edição quando uma cadeia de caracteres na caixa de listagem está selecionada.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox&#28;](../../mfc/reference/codesnippet/cpp/ccombobox-class_28.cpp)]  
  
##  <a name="a-namemeasureitema--ccomboboxmeasureitem"></a><a name="measureitem"></a>CComboBox::MeasureItem  
 Chamado pela estrutura quando uma caixa de combinação com um estilo de desenho proprietário é criada.  
  
```  
virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpMeasureItemStruct`  
 Um ponteiro de tempo para um [MEASUREITEMSTRUCT](../../mfc/reference/measureitemstruct-structure.md) estrutura.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, essa função de membro não fará nada. Substituir essa função de membro e preencha o `MEASUREITEMSTRUCT` estrutura para informar o Windows as dimensões da lista de caixa na caixa de combinação. Se a caixa de combinação é criada com o [CBS_OWNERDRAWVARIABLE](../../mfc/reference/combo-box-styles.md) estilo, a estrutura chama essa função de membro para cada item na caixa de listagem. Caso contrário, este membro é chamado apenas uma vez.  
  
 Usando o **CBS_OWNERDRAWFIXED** estilo em uma caixa de combinação do desenho proprietário criado com o [SubclassDlgItem](../../mfc/reference/cwnd-class.md#subclassdlgitem) função de membro `CWnd` envolve considerações de programação adicional. Consulte a discussão na [técnico 14 Observação](../../mfc/tn014-custom-controls.md).  
  
 Consulte [CWnd::OnMeasureItem](../../mfc/reference/cwnd-class.md#onmeasureitem) para obter uma descrição de `MEASUREITEMSTRUCT` estrutura.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[29 NVC_MFC_CComboBox](../../mfc/reference/codesnippet/cpp/ccombobox-class_29.cpp)]  
  
##  <a name="a-namepastea--ccomboboxpaste"></a><a name="paste"></a>CComboBox::Paste  
 Insere os dados da área de transferência no controle de edição da caixa de combinação na posição atual do cursor.  
  
```  
void Paste();
```  
  
### <a name="remarks"></a>Comentários  
 Os dados são inseridos somente se a área de transferência contém dados em **CF_TEXT** formato.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[30 NVC_MFC_CComboBox](../../mfc/reference/codesnippet/cpp/ccombobox-class_30.cpp)]  
  
##  <a name="a-nameresetcontenta--ccomboboxresetcontent"></a><a name="resetcontent"></a>CComboBox::ResetContent  
 Remove todos os itens da lista de caixa e editar o controle de uma caixa de combinação.  
  
```  
void ResetContent();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox&#31;](../../mfc/reference/codesnippet/cpp/ccombobox-class_31.cpp)]  
  
##  <a name="a-nameselectstringa--ccomboboxselectstring"></a><a name="selectstring"></a>CComboBox::SelectString  
 Procura uma cadeia de caracteres na caixa de listagem de uma caixa de combinação e, se a cadeia de caracteres for encontrada, seleciona a cadeia de caracteres na caixa de listagem e copiá-lo para o controle de edição.  
  
```  
int SelectString(
    int nStartAfter,  
    LPCTSTR lpszString);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nStartAfter`  
 Contém o índice baseado em zero do item antes do primeiro item a ser pesquisada. Quando a pesquisa chega a parte inferior da caixa de listagem, ele continua na parte superior da caixa de listagem no item especificado por `nStartAfter`. Se –&1;, a caixa de listagem inteira é pesquisada desde o início.  
  
 `lpszString`  
 Aponta para a cadeia de caracteres terminada em nulo que contém o prefixo para pesquisar. A pesquisa é o caso independente, portanto essa cadeia de caracteres pode conter qualquer combinação de letras maiusculas e minúsculas.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero do item selecionado se a cadeia de caracteres foi encontrada. Se a pesquisa tiver êxito, o valor de retorno é **CB_ERR** e a seleção atual não será alterada.  
  
### <a name="remarks"></a>Comentários  
 Uma cadeia de caracteres é selecionada somente se os caracteres inicias (do ponto de partida) correspondem os caracteres na cadeia de caracteres de prefixo.  
  
 Observe que o `SelectString` e `FindString` funções de membro localizar uma cadeia de caracteres, mas o `SelectString` função de membro também seleciona a cadeia de caracteres.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[32 NVC_MFC_CComboBox](../../mfc/reference/codesnippet/cpp/ccombobox-class_32.cpp)]  
  
##  <a name="a-namesetcuebannera--ccomboboxsetcuebanner"></a><a name="setcuebanner"></a>CComboBox::SetCueBanner  
 Define o texto de indicação que é exibido para um controle de caixa de combinação.  
  
```  
BOOL SetCueBanner(LPCTSTR lpszText);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *lpszText*|Ponteiro para um buffer de terminação nula que contém o texto de indicação.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o método for bem-sucedido; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Texto de indicação é uma solicitação que é exibida na área de entrada de controle de caixa de combinação. O texto de indicação é exibido até que o usuário forneça uma entrada.  
  
 Esse método envia o [CB_SETCUEBANNER](http://msdn.microsoft.com/library/windows/desktop/bb775897) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_combobox`, que é usado para acessar programaticamente o controle de caixa de combinação. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CComboBox_s1 n º&1;](../../mfc/reference/codesnippet/cpp/ccombobox-class_33.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a faixa de indicação para o controle de caixa de combinação.  
  
 [!code-cpp[NVC_MFC_CComboBox_s1 n º&2;](../../mfc/reference/codesnippet/cpp/ccombobox-class_34.cpp)]  
  
##  <a name="a-namesetcursela--ccomboboxsetcursel"></a><a name="setcursel"></a>CComboBox::SetCurSel  
 Seleciona uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.  
  
```  
int SetCurSel(int nSelect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSelect`  
 Especifica o índice baseado em zero da cadeia de caracteres para selecionar. Se –&1;, qualquer seleção atual na caixa de listagem é removida e o controle de edição está desmarcado.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero do item selecionado se a mensagem for bem-sucedida. O valor de retorno é **CB_ERR** se `nSelect` é maior que o número de itens na lista ou se `nSelect` for definido como -1, que limpa a seleção.  
  
### <a name="remarks"></a>Comentários  
 Se necessário, a caixa de listagem rola a cadeia de caracteres no modo de exibição (se a caixa de listagem é visível). O texto no controle de edição da caixa de combinação é alterado para refletir a nova seleção. Qualquer seleção anterior na caixa de listagem é removida.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[33 NVC_MFC_CComboBox](../../mfc/reference/codesnippet/cpp/ccombobox-class_35.cpp)]  
  
##  <a name="a-namesetdroppedwidtha--ccomboboxsetdroppedwidth"></a><a name="setdroppedwidth"></a>CComboBox::SetDroppedWidth  
 Chame essa função para definir a largura mínima permitida, em pixels, da caixa de listagem de uma caixa de combinação.  
  
```  
int SetDroppedWidth(UINT nWidth);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nWidth`  
 A largura mínima permitida da parte caixa de listagem da caixa de combinação, em pixels.  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, a nova largura da lista de caixa, caso contrário, **CB_ERR**.  
  
### <a name="remarks"></a>Comentários  
 Essa função só se aplica às caixas de combinação com o [CBS_DROPDOWN](../../mfc/reference/combo-box-styles.md) ou [CBS_DROPDOWNLIST](../../mfc/reference/combo-box-styles.md) estilo.  
  
 Por padrão, a largura mínima permitida da caixa de listagem suspensa é 0. Quando a parte de caixa de listagem da caixa de combinação for exibida, sua largura é maior do mínima permitida largura ou a largura da caixa de combinação.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox&#34;](../../mfc/reference/codesnippet/cpp/ccombobox-class_36.cpp)]  
  
##  <a name="a-nameseteditsela--ccomboboxseteditsel"></a><a name="seteditsel"></a>CComboBox::SetEditSel  
 Seleciona caracteres no controle de edição de uma caixa de combinação.  
  
```  
BOOL SetEditSel(
    int nStartChar,  
    int nEndChar);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nStartChar`  
 Especifica a posição inicial. Se a posição inicial é definida como -1, qualquer seleção existente é removida.  
  
 `nEndChar`  
 Especifica a posição final. Se a posição final for definida como -1, em seguida, todo o texto da posição inicial para o último caractere no controle de edição é selecionado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função de membro for bem-sucedida; Caso contrário, 0. É **CB_ERR** se `CComboBox` tem o [CBS_DROPDOWNLIST](../../mfc/reference/combo-box-styles.md) de estilo ou não tem uma caixa de listagem.  
  
### <a name="remarks"></a>Comentários  
 As posições são baseadas em zero. Para selecionar o primeiro caractere do controle de edição, você deve especificar uma posição inicial de 0. A posição final é o caractere logo após o último caractere para selecionar. Por exemplo, para selecionar os quatro primeiros caracteres do controle de edição, você usaria uma posição inicial de 0 e uma posição final de 4.  
  
> [!NOTE]
>  Essa função não é suportado pelo Windows **ComboBoxEx** controle. Para obter mais informações sobre esse controle, consulte [ComboBoxEx controles](http://msdn.microsoft.com/library/windows/desktop/bb775738) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CComboBox::GetEditSel](#geteditsel).  
  
##  <a name="a-namesetextendeduia--ccomboboxsetextendedui"></a><a name="setextendedui"></a>CComboBox::SetExtendedUI  
 Chamar o `SetExtendedUI` a função de membro para selecionar a interface de usuário padrão ou interface do usuário estendida para uma caixa de combinação que tem o [CBS_DROPDOWN](../../mfc/reference/combo-box-styles.md) ou [CBS_DROPDOWNLIST](../../mfc/reference/combo-box-styles.md) estilo.  
  
```  
int SetExtendedUI(BOOL bExtended = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bO*  
 Especifica se a caixa de combinação deve usar a interface do usuário estendida ou a interface do usuário padrão. Um valor de **TRUE** seleciona estendido interface do usuário; um valor de **FALSE** seleciona a interface de usuário padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 **CB_OKAY** se a operação for bem-sucedida, ou **CB_ERR** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 A interface do usuário estendida pode ser identificada das seguintes maneiras:  
  
-   Clicando no controle estático exibe a caixa de listagem apenas para caixas de combinação com o **CBS_DROPDOWNLIST** estilo.  
  
-   Pressionar a tecla de seta para baixo exibirá a caixa de lista (F4 desabilitado).  
  
 Rolagem no controle estático é desabilitada quando o item de lista não estiver visível (as teclas de seta estiverem desabilitadas).  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CComboBox::GetExtendedUI](#getextendedui).  
  
##  <a name="a-namesethorizontalextenta--ccomboboxsethorizontalextent"></a><a name="sethorizontalextent"></a>CComboBox::SetHorizontalExtent  
 Define a largura, em pixels, pelo qual a parte de caixa de listagem da caixa de combinação pode ser rolada horizontalmente.  
  
```  
void SetHorizontalExtent(UINT nExtent);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nExtent*  
 Especifica o número de pixels pelo qual a parte de caixa de listagem da caixa de combinação pode ser rolada horizontalmente.  
  
### <a name="remarks"></a>Comentários  
 Se a largura da caixa de listagem é menor do que esse valor, a barra de rolagem horizontal rolar horizontalmente itens na caixa de listagem. Se a largura da caixa de listagem é igual ou maior que esse valor, a barra de rolagem horizontal está oculto ou, se a caixa de combinação com o [CBS_DISABLENOSCROLL](../../mfc/reference/combo-box-styles.md) estilo, desabilitado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox&#35;](../../mfc/reference/codesnippet/cpp/ccombobox-class_37.cpp)]  
  
##  <a name="a-namesetitemdataa--ccomboboxsetitemdata"></a><a name="setitemdata"></a>CComboBox::SetItemData  
 Define o valor de 32 bits associado ao item especificado em uma caixa de combinação.  
  
```  
int SetItemData(
    int nIndex,  
    DWORD_PTR dwItemData);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Contém um índice com base em zero para o item a ser definido.  
  
 `dwItemData`  
 Contém o novo valor a ser associado ao item.  
  
### <a name="return-value"></a>Valor de retorno  
 **CB_ERR** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Use o `SetItemDataPtr` se o item de 32 bits deve ser um ponteiro de função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox&#36;](../../mfc/reference/codesnippet/cpp/ccombobox-class_38.cpp)]  
  
##  <a name="a-namesetitemdataptra--ccomboboxsetitemdataptr"></a><a name="setitemdataptr"></a>CComboBox::SetItemDataPtr  
 Define o valor de 32 bits associado ao item especificado em uma caixa de combinação para ser o ponteiro especificado ( **void\***).  
  
```  
int SetItemDataPtr(
    int nIndex,  
    void* pData);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Contém um índice com base em zero para o item.  
  
 `pData`  
 Contém o ponteiro associado ao item.  
  
### <a name="return-value"></a>Valor de retorno  
 **CB_ERR** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Esse ponteiro permanece válido para a vida útil da caixa de combinação, mesmo que a posição relativa do item dentro da caixa de combinação pode alterar como os itens são adicionados ou removidos. Portanto, pode alterar o índice do item dentro da caixa, mas o ponteiro permanece confiável.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox&#37;](../../mfc/reference/codesnippet/cpp/ccombobox-class_39.cpp)]  
  
##  <a name="a-namesetitemheighta--ccomboboxsetitemheight"></a><a name="setitemheight"></a>CComboBox::SetItemHeight  
 Chamar o `SetItemHeight` a função de membro para definir a altura de itens de lista em uma caixa de combinação ou a altura da parte do controle de edição (ou texto estático) de uma caixa de combinação.  
  
```  
int SetItemHeight(
    int nIndex,  
    UINT cyItemHeight);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica se a altura dos itens da lista ou da altura da parte do controle de edição (ou texto estático) da caixa de combinação é definida.  
  
 Se a caixa de combinação com o [CBS_OWNERDRAWVARIABLE](../../mfc/reference/combo-box-styles.md) estilo, `nIndex` Especifica o índice baseado em zero do item de lista cuja altura deve ser definido; caso contrário, `nIndex` deve ser 0 e a altura da lista de todos os itens serão definidos.  
  
 Se `nIndex` é –&1;, a altura do controle de edição ou texto estático da caixa de combinação deve ser definido.  
  
 `cyItemHeight`  
 Especifica a altura em pixels, do componente caixa de combinação identificado por `nIndex`.  
  
### <a name="return-value"></a>Valor de retorno  
 **CB_ERR** se o índice ou a altura é inválido; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A altura da parte do controle de edição (ou texto estático) da caixa de combinação é definida independentemente da altura dos itens da lista. Um aplicativo deve garantir que a altura da parte do controle de edição (ou texto estático) não é menor do que a altura de um item específico da caixa de listagem.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox&38;](../../mfc/reference/codesnippet/cpp/ccombobox-class_40.cpp)]  
  
##  <a name="a-namesetlocalea--ccomboboxsetlocale"></a><a name="setlocale"></a>CComboBox::SetLocale  
 Define o identificador de localidade para essa caixa de combinação.  
  
```  
LCID SetLocale(LCID nNewLocale);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nNewLocale`  
 O novo valor LCID (identificador) de localidade a ser definido para a caixa de combinação.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor LCID (identificador) localidade anterior desta caixa de combinação.  
  
### <a name="remarks"></a>Comentários  
 Se **SetLocale** não é chamado, o padrão é obtida localidade do sistema. Essa localidade padrão do sistema pode ser modificada por meio do painel de controle do aplicativo regionais (ou internacional).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox&#39;](../../mfc/reference/codesnippet/cpp/ccombobox-class_41.cpp)]  
  
##  <a name="a-namesetminvisibleitemsa--ccomboboxsetminvisibleitems"></a><a name="setminvisibleitems"></a>CComboBox::SetMinVisibleItems  
 Define o número mínimo de itens visíveis na lista suspensa da caixa de combinação atual de controle de caixa.  
  
```  
BOOL SetMinVisibleItems(int iMinVisible);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `iMinVisible`|Especifica o número mínimo de itens visíveis.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [CB_SETMINVISIBLE](http://msdn.microsoft.com/library/windows/desktop/bb775915) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_combobox`, que é usado para acessar programaticamente o controle de caixa de combinação. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CComboBox_s1 n º&1;](../../mfc/reference/codesnippet/cpp/ccombobox-class_33.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir insere 20 itens na lista suspensa de um controle de caixa de combinação. Em seguida, especifica que um mínimo de 10 itens ser exibida quando um usuário pressiona a seta suspensa.  
  
 [!code-cpp[NVC_MFC_CComboBox_s1 n º&2;](../../mfc/reference/codesnippet/cpp/ccombobox-class_34.cpp)]  
  
##  <a name="a-namesettopindexa--ccomboboxsettopindex"></a><a name="settopindex"></a>CComboBox::SetTopIndex  
 Garante que um determinado item está visível na parte de caixa de listagem da caixa de combinação.  
  
```  
int SetTopIndex(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice baseado em zero do item de caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Zero se tiver êxito, ou **CB_ERR** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 O sistema rola a caixa de listagem até que o item especificado por `nIndex` aparece na parte superior da lista de caixa ou o intervalo de rolagem máximo foi atingido.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[40 NVC_MFC_CComboBox](../../mfc/reference/codesnippet/cpp/ccombobox-class_42.cpp)]  
  
##  <a name="a-nameshowdropdowna--ccomboboxshowdropdown"></a><a name="showdropdown"></a>CComboBox::ShowDropDown  
 Mostra ou oculta a caixa de listagem de uma caixa de combinação que tem o [CBS_DROPDOWN](../../mfc/reference/combo-box-styles.md) ou [CBS_DROPDOWNLIST](../../mfc/reference/combo-box-styles.md) estilo.  
  
```  
void ShowDropDown(BOOL bShowIt = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bShowIt*  
 Especifica se a caixa de listagem suspensa deve ser mostrado ou ocultado. Um valor de **TRUE** mostra a caixa de listagem. Um valor de **FALSE** oculta a caixa de listagem.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, uma caixa de combinação desse estilo mostrará a caixa de listagem.  
  
 Essa função de membro não tem nenhum efeito em uma caixa de combinação criado com o [CBS_SIMPLE](../../mfc/reference/combo-box-styles.md) estilo.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CComboBox::GetDroppedState](#getdroppedstate).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC CTRLBARS](../../visual-cpp-samples.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Classe CButton](../../mfc/reference/cbutton-class.md)   
 [Classe CEdit](../../mfc/reference/cedit-class.md)   
 [Classe CListBox](../../mfc/reference/clistbox-class.md)   
 [Classe CScrollBar](../../mfc/reference/cscrollbar-class.md)   
 [Classe CStatic](../../mfc/reference/cstatic-class.md)   
 [Classe CDialog](../../mfc/reference/cdialog-class.md)

