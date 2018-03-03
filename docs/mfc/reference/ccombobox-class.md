---
title: Classe CComboBox | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComboBox
- AFXWIN/CComboBox
- AFXWIN/CComboBox::CComboBox
- AFXWIN/CComboBox::AddString
- AFXWIN/CComboBox::Clear
- AFXWIN/CComboBox::CompareItem
- AFXWIN/CComboBox::Copy
- AFXWIN/CComboBox::Create
- AFXWIN/CComboBox::Cut
- AFXWIN/CComboBox::DeleteItem
- AFXWIN/CComboBox::DeleteString
- AFXWIN/CComboBox::Dir
- AFXWIN/CComboBox::DrawItem
- AFXWIN/CComboBox::FindString
- AFXWIN/CComboBox::FindStringExact
- AFXWIN/CComboBox::GetComboBoxInfo
- AFXWIN/CComboBox::GetCount
- AFXWIN/CComboBox::GetCueBanner
- AFXWIN/CComboBox::GetCurSel
- AFXWIN/CComboBox::GetDroppedControlRect
- AFXWIN/CComboBox::GetDroppedState
- AFXWIN/CComboBox::GetDroppedWidth
- AFXWIN/CComboBox::GetEditSel
- AFXWIN/CComboBox::GetExtendedUI
- AFXWIN/CComboBox::GetHorizontalExtent
- AFXWIN/CComboBox::GetItemData
- AFXWIN/CComboBox::GetItemDataPtr
- AFXWIN/CComboBox::GetItemHeight
- AFXWIN/CComboBox::GetLBText
- AFXWIN/CComboBox::GetLBTextLen
- AFXWIN/CComboBox::GetLocale
- AFXWIN/CComboBox::GetMinVisible
- AFXWIN/CComboBox::GetTopIndex
- AFXWIN/CComboBox::InitStorage
- AFXWIN/CComboBox::InsertString
- AFXWIN/CComboBox::LimitText
- AFXWIN/CComboBox::MeasureItem
- AFXWIN/CComboBox::Paste
- AFXWIN/CComboBox::ResetContent
- AFXWIN/CComboBox::SelectString
- AFXWIN/CComboBox::SetCueBanner
- AFXWIN/CComboBox::SetCurSel
- AFXWIN/CComboBox::SetDroppedWidth
- AFXWIN/CComboBox::SetEditSel
- AFXWIN/CComboBox::SetExtendedUI
- AFXWIN/CComboBox::SetHorizontalExtent
- AFXWIN/CComboBox::SetItemData
- AFXWIN/CComboBox::SetItemDataPtr
- AFXWIN/CComboBox::SetItemHeight
- AFXWIN/CComboBox::SetLocale
- AFXWIN/CComboBox::SetMinVisibleItems
- AFXWIN/CComboBox::SetTopIndex
- AFXWIN/CComboBox::ShowDropDown
dev_langs:
- C++
helpviewer_keywords:
- CComboBox [MFC], CComboBox
- CComboBox [MFC], AddString
- CComboBox [MFC], Clear
- CComboBox [MFC], CompareItem
- CComboBox [MFC], Copy
- CComboBox [MFC], Create
- CComboBox [MFC], Cut
- CComboBox [MFC], DeleteItem
- CComboBox [MFC], DeleteString
- CComboBox [MFC], Dir
- CComboBox [MFC], DrawItem
- CComboBox [MFC], FindString
- CComboBox [MFC], FindStringExact
- CComboBox [MFC], GetComboBoxInfo
- CComboBox [MFC], GetCount
- CComboBox [MFC], GetCueBanner
- CComboBox [MFC], GetCurSel
- CComboBox [MFC], GetDroppedControlRect
- CComboBox [MFC], GetDroppedState
- CComboBox [MFC], GetDroppedWidth
- CComboBox [MFC], GetEditSel
- CComboBox [MFC], GetExtendedUI
- CComboBox [MFC], GetHorizontalExtent
- CComboBox [MFC], GetItemData
- CComboBox [MFC], GetItemDataPtr
- CComboBox [MFC], GetItemHeight
- CComboBox [MFC], GetLBText
- CComboBox [MFC], GetLBTextLen
- CComboBox [MFC], GetLocale
- CComboBox [MFC], GetMinVisible
- CComboBox [MFC], GetTopIndex
- CComboBox [MFC], InitStorage
- CComboBox [MFC], InsertString
- CComboBox [MFC], LimitText
- CComboBox [MFC], MeasureItem
- CComboBox [MFC], Paste
- CComboBox [MFC], ResetContent
- CComboBox [MFC], SelectString
- CComboBox [MFC], SetCueBanner
- CComboBox [MFC], SetCurSel
- CComboBox [MFC], SetDroppedWidth
- CComboBox [MFC], SetEditSel
- CComboBox [MFC], SetExtendedUI
- CComboBox [MFC], SetHorizontalExtent
- CComboBox [MFC], SetItemData
- CComboBox [MFC], SetItemDataPtr
- CComboBox [MFC], SetItemHeight
- CComboBox [MFC], SetLocale
- CComboBox [MFC], SetMinVisibleItems
- CComboBox [MFC], SetTopIndex
- CComboBox [MFC], ShowDropDown
ms.assetid: 4e73b5df-0d2e-4658-9706-38133fb10513
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: fffa5c09f1572200ca7850c8870b7daee9e3e75f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ccombobox-class"></a>Classe CComboBox
Fornece a funcionalidade de uma caixa de combinação do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CComboBox : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComboBox::CComboBox](#ccombobox)|Constrói um objeto `CComboBox`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComboBox::AddString](#addstring)|Adiciona uma cadeia de caracteres ao final da lista na caixa de listagem de uma caixa de combinação ou na posição de classificação para caixas de listagem com o **CBS_SORT** estilo.|  
|[CComboBox::Clear](#clear)|Exclui (limpa) a seleção atual, se houver, no controle de edição.|  
|[CComboBox::CompareItem](#compareitem)|Chamado pelo framework para determinar a posição relativa de um novo item de lista em uma caixa de combinação classificada desenhados pelo proprietário.|  
|[CComboBox::Copy](#copy)|Copia a seleção atual, se houver, na área de transferência em **CF_TEXT** formato.|  
|[CComboBox::Create](#create)|Cria a caixa de combinação e anexa-o para o `CComboBox` objeto.|  
|[CComboBox::Cut](#cut)|Exclui (cortes) a seleção atual, se houver, em que a edição de controle e copia o texto excluído na área de transferência no **CF_TEXT** formato.|  
|[CComboBox::DeleteItem](#deleteitem)|Chamado pelo framework quando um item de lista é excluído de uma caixa de combinação do desenho proprietário.|  
|[CComboBox::DeleteString](#deletestring)|Exclui uma cadeia de caracteres da caixa de listagem de uma caixa de combinação.|  
|[CComboBox::Dir](#dir)|Adiciona uma lista de nomes de arquivo para a caixa de listagem de uma caixa de combinação.|  
|[CComboBox::DrawItem](#drawitem)|Chamado pelo framework quando um aspecto visual de um alterações de caixa de combinação do desenho proprietário.|  
|[CComboBox:: FindString](#findstring)|Localiza a primeira cadeia de caracteres que contém o prefixo especificado na caixa de listagem de uma caixa de combinação.|  
|[CComboBox::FindStringExact](#findstringexact)|Localiza a primeira cadeia de caixa de listagem (em uma caixa de combinação) que corresponde à cadeia especificada.|  
|[CComboBox::GetComboBoxInfo](#getcomboboxinfo)|Recupera informações sobre o `CComboBox` objeto.|  
|[CComboBox::GetCount](#getcount)|Recupera o número de itens na caixa de listagem de uma caixa de combinação.|  
|[CComboBox::GetCueBanner](#getcuebanner)|Obtém o texto da indicação que é exibido para um controle de caixa de combinação.|  
|[CComboBox::GetCurSel](#getcursel)|Recupera o índice do item selecionado no momento, se houver, na caixa de listagem de uma caixa de combinação.|  
|[CComboBox::GetDroppedControlRect](#getdroppedcontrolrect)|Recupera as coordenadas de tela da caixa de lista (removido para baixo) visíveis de uma caixa de combinação suspensa.|  
|[CComboBox::GetDroppedState](#getdroppedstate)|Determina se a caixa de listagem de uma caixa de combinação suspensa está visível (aberta).|  
|[CComboBox::GetDroppedWidth](#getdroppedwidth)|Recupera o mínimo permitido largura para a parte de caixa de listagem suspensa de uma caixa de combinação.|  
|[CComboBox::GetEditSel](#geteditsel)|Obtém as posições de caractere inicial e final da seleção atual no controle de edição de uma caixa de combinação.|  
|[CComboBox::GetExtendedUI](#getextendedui)|Determina se uma caixa de combinação tem a interface do usuário padrão ou a interface do usuário estendida.|  
|[CComboBox::GetHorizontalExtent](#gethorizontalextent)|Retorna a largura em pixels que a parte da caixa de listagem da caixa de combinação pode ser rolada horizontalmente.|  
|[CComboBox::GetItemData](#getitemdata)|Recupera o valor de 32 bits fornecido pelo aplicativo associado ao item de caixa de combinação especificada.|  
|[CComboBox::GetItemDataPtr](#getitemdataptr)|Recupera o ponteiro de 32 bits fornecidas pelo aplicativo que está associado ao item de caixa de combinação especificada.|  
|[CComboBox::GetItemHeight](#getitemheight)|Recupera a altura dos itens de lista em uma caixa de combinação.|  
|[CComboBox::GetLBText](#getlbtext)|Obtém uma cadeia de caracteres da caixa de listagem de uma caixa de combinação.|  
|[CComboBox::GetLBTextLen](#getlbtextlen)|Obtém o comprimento de uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.|  
|[CComboBox::GetLocale](#getlocale)|Recupera o identificador de localidade para uma caixa de combinação.|  
|[CComboBox::GetMinVisible](#getminvisible)|Obtém o número mínimo de itens visíveis na lista suspensa da caixa de combinação atual.|  
|[CComboBox::GetTopIndex](#gettopindex)|Retorna o índice do primeiro item visível na parte de caixa de listagem da caixa de combinação.|  
|[CComboBox::InitStorage](#initstorage)|Preallocates blocos de memória para cadeias de caracteres na parte caixa de listagem da caixa de combinação e itens.|  
|[CComboBox::InsertString](#insertstring)|Insere uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.|  
|[CComboBox::LimitText](#limittext)|Limita o comprimento do texto que o usuário pode inserir no controle de edição de uma caixa de combinação.|  
|[CComboBox::MeasureItem](#measureitem)|Chamado pelo framework para determinar as dimensões da caixa de combinação quando uma caixa de combinação do desenho proprietário é criada.|  
|[CComboBox::Paste](#paste)|Insere os dados da área de transferência no controle de edição na posição atual do cursor. Os dados são inseridos somente se a área de transferência contém dados em **CF_TEXT** formato.|  
|[CComboBox::ResetContent](#resetcontent)|Remove todos os itens da lista de caixa e controle de uma caixa de combinação de edição.|  
|[CComboBox::SelectString](#selectstring)|Pesquisa uma cadeia de caracteres na caixa de listagem de uma caixa de combinação e, se a cadeia de caracteres for encontrada, seleciona a cadeia de caracteres na caixa de listagem e copia a cadeia de caracteres para o controle de edição.|  
|[CComboBox::SetCueBanner](#setcuebanner)|Define o texto da indicação que é exibido para um controle de caixa de combinação.|  
|[CComboBox::SetCurSel](#setcursel)|Seleciona uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.|  
|[CComboBox::SetDroppedWidth](#setdroppedwidth)|Define o mínimo permitido largura para a parte de caixa de listagem suspensa de uma caixa de combinação.|  
|[CComboBox::SetEditSel](#seteditsel)|Seleciona caracteres no controle de edição de uma caixa de combinação.|  
|[CComboBox::SetExtendedUI](#setextendedui)|Seleciona a interface do usuário padrão ou a interface do usuário estendida para uma caixa de combinação que tenha o **CBS_DROPDOWN** ou **CBS_DROPDOWNLIST** estilo.|  
|[CComboBox::SetHorizontalExtent](#sethorizontalextent)|Define a largura em pixels que a parte da caixa de listagem da caixa de combinação pode ser rolada horizontalmente.|  
|[CComboBox::SetItemData](#setitemdata)|Define o valor de 32 bits associado com o item especificado em uma caixa de combinação.|  
|[CComboBox::SetItemDataPtr](#setitemdataptr)|Define o ponteiro de 32 bits associado com o item especificado em uma caixa de combinação.|  
|[CComboBox::SetItemHeight](#setitemheight)|Define a altura de itens de lista em uma caixa de combinação ou da altura da porção de controle de edição (ou texto estático) de uma caixa de combinação.|  
|[CComboBox::SetLocale](#setlocale)|Define o identificador de localidade para uma caixa de combinação.|  
|[CComboBox::SetMinVisibleItems](#setminvisibleitems)|Define o número mínimo de itens visíveis na lista suspensa da caixa de combinação atual.|  
|[CComboBox::SetTopIndex](#settopindex)|Informa a parte da caixa de listagem da caixa de combinação para exibir o item com o índice especificado na parte superior.|  
|[CComboBox::ShowDropDown](#showdropdown)|Mostra ou oculta a caixa de listagem de uma caixa de combinação que tenha o **CBS_DROPDOWN** ou **CBS_DROPDOWNLIST** estilo.|  
  
## <a name="remarks"></a>Comentários  
 Uma caixa de combinação consiste em uma caixa de listagem combinada com um controle estático ou o controle de edição. A parte da caixa de listagem do controle pode ser exibida em todos os momentos ou pode apenas suspenso quando o usuário seleciona a seta suspensa ao lado do controle.  
  
 O item selecionado no momento (se houver) na caixa de listagem é exibido no estático ou controle de edição. Além disso, se a caixa de combinação com o estilo de lista suspensa, o usuário pode digitar o caractere inicial de um dos itens na lista, e a caixa de listagem, se estiver visível, realçará o próximo item com esse caractere inicial.  
  
 A tabela a seguir compara a caixa de combinação de três [estilos](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles).  
  
|Estilo|Quando a caixa de listagem é visível|Controle estático ou editar|  
|-----------|-------------------------------|-----------------------------|  
|Simples|Sempre|Editar|  
|Lista suspensa|Quando aberta|Editar|  
|Lista suspensa|Quando aberta|Estático|  
  
 Você pode criar um `CComboBox` objeto de um modelo de caixa de diálogo ou diretamente em seu código. Em ambos os casos, chame o construtor `CComboBox` para construir o `CComboBox` objeto; em seguida, chame o [criar](#create) a função de membro para criar o controle e anexá-lo para o `CComboBox` objeto.  
  
 Se você desejar tratar mensagens de notificação do Windows enviadas por uma caixa de combinação para seu pai (geralmente uma classe derivada de `CDialog`), adicionar uma função de membro de entrada e o manipulador de mensagens do mapa de mensagem para a classe pai para cada mensagem.  
  
 Cada entrada de mapa de mensagem assume o seguinte formato:  
  
 **On _**notificação **(**`id`**,**`memberFxn`**)**  
  
 onde `id` Especifica a ID de janela filho do controle de caixa de combinação enviando a notificação e `memberFxn` é o nome da função de membro pai que você tenha escrito para manipular a notificação.  
  
 O protótipo de função do pai é o seguinte:  
  
 **afx_msg** `void` `memberFxn` **();**  
  
 A ordem em que determinadas notificações serão enviadas não pode ser prevista. Em particular, uma **CBN_SELCHANGE** notificação pode ocorrer antes ou depois de um **CBN_CLOSEUP** notificação.  
  
 Entradas de mapa de mensagem possíveis são os seguintes:  
  
- **ON_CBN_CLOSEUP** (Windows 3.1 e posterior). Caixa de listagem de uma caixa de combinação foi fechada. Essa mensagem de notificação não é enviada para uma caixa de combinação que tenha o [CBS_SIMPLE](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo.  
  
- **ON_CBN_DBLCLK** o usuário clica duas vezes em uma cadeia de caracteres na caixa de listagem de uma caixa de combinação. Esta mensagem de notificação é enviada somente para uma caixa de combinação com o **CBS_SIMPLE** estilo. Para uma caixa de combinação com o [CBS_DROPDOWN](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) de estilo, um clique duplo não pode ocorrer porque um único clique oculta a caixa de listagem.  
  
- **ON_CBN_DROPDOWN** caixa de listagem de uma caixa de combinação está prestes a lista suspensa (ficar visível). Essa mensagem de notificação pode ocorrer apenas uma caixa de combinação com o **CBS_DROPDOWN** ou **CBS_DROPDOWNLIST** estilo.  
  
- **ON_CBN_EDITCHANGE** o usuário executou uma ação que pode ter alterado o texto na parte do controle de edição de uma caixa de combinação. Ao contrário de **CBN_EDITUPDATE** mensagem, essa mensagem é enviada após a tela de atualizações do Windows. Não é enviada se a caixa de combinação com o **CBS_DROPDOWNLIST** estilo.  
  
- **ON_CBN_EDITUPDATE** a parte do controle de edição de uma caixa de combinação está prestes a exibir o texto alterado. Esta mensagem de notificação é enviada depois que o controle tem o texto formatado, mas antes de exibir o texto. Não é enviada se a caixa de combinação com o **CBS_DROPDOWNLIST** estilo.  
  
- **ON_CBN_ERRSPACE** a caixa de combinação não é possível alocar memória suficiente para atender uma solicitação específica.  
  
- **ON_CBN_SELENDCANCEL** (Windows 3.1 e posterior). Indica que a seleção do usuário deve ser cancelada. O usuário clica em um item e, em seguida, clica em outra janela ou controle para ocultar a caixa de listagem de uma caixa de combinação. Essa mensagem de notificação é enviada antes do **CBN_CLOSEUP** mensagem de notificação para indicar que a seleção do usuário deve ser ignorada. O **CBN_SELENDCANCEL** ou **CBN_SELENDOK** mensagem de notificação é enviada mesmo que o **CBN_CLOSEUP** mensagem de notificação não é enviada (como no caso de uma caixa de combinação com o **CBS_SIMPLE** estilo).  
  
- **ON_CBN_SELENDOK** o usuário seleciona um item e, em seguida, pressionar a tecla ENTER ou clica a seta para baixo para ocultar a caixa de listagem de uma caixa de combinação. Essa mensagem de notificação é enviada antes do **CBN_CLOSEUP** mensagem para indicar que a seleção do usuário deve ser considerada válida. O **CBN_SELENDCANCEL** ou **CBN_SELENDOK** mensagem de notificação é enviada mesmo que o **CBN_CLOSEUP** mensagem de notificação não é enviada (como no caso de uma caixa de combinação com o **CBS_SIMPLE** estilo).  
  
- **ON_CBN_KILLFOCUS** a caixa de combinação está perdendo o foco de entrada.  
  
- **ON_CBN_SELCHANGE** a seleção na caixa de listagem de uma caixa de combinação está prestes a ser alterada como resultado do usuário clicar na caixa de listagem ou alterar a seleção usando as teclas de direção. Ao processar esta mensagem, o texto no controle de edição da caixa de combinação só pode ser recuperado por meio de `GetLBText` ou outra função semelhante. `GetWindowText`não pode ser usado.  
  
- **ON_CBN_SETFOCUS** a caixa de combinação recebe o foco de entrada.  
  
 Se você criar um `CComboBox` objeto dentro de uma caixa de diálogo (por meio de um recurso de caixa de diálogo), o `CComboBox` objeto é destruído automaticamente quando o usuário fecha a caixa de diálogo.  
  
 Se você inserir um `CComboBox` objeto dentro de outra janela do objeto, você não precisa destruída. Se você criar o `CComboBox` do objeto na pilha, ele será destruído automaticamente. Se você criar o `CComboBox` objeto na pilha usando o **novo** função, você deve chamar **excluir** sobre o objeto a ser destruída quando a caixa de combinação do Windows é destruída.  
  
 **Observação** se você desejar tratar `WM_KEYDOWN` e `WM_CHAR` mensagens, você tem a subclasse da caixa de combinação editar e controles de caixa de lista, derivar de classes de `CEdit` e `CListBox`, e adicionar manipuladores para essas mensagens para derivada classes. Para obter mais informações, consulte [http://support.microsoft.com/default.aspxscid=kb;en-us; Q174667](http://support.microsoft.com/default.aspxscid=kb;en-us;q174667) e [CWnd::SubclassWindow](../../mfc/reference/cwnd-class.md#subclasswindow).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CComboBox`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
##  <a name="addstring"></a>CComboBox::AddString  
 Adiciona uma cadeia de caracteres para a caixa de listagem de uma caixa de combinação.  
  
```  
int AddString(LPCTSTR lpszString);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszString`  
 Aponta para a cadeia de caracteres terminada em nulo que deve ser adicionado.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o valor de retorno é maior que ou igual a 0, é o índice de base zero para a cadeia de caracteres na caixa de listagem. O valor de retorno é **CB_ERR** se ocorrer um erro; o valor de retorno é **CB_ERRSPACE** se houver espaço suficiente armazenar a nova cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Se a caixa de listagem não foi criada com o [CBS_SORT](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo, a cadeia de caracteres é adicionada ao final da lista. Caso contrário, a cadeia de caracteres é inserida na lista, e a lista é classificada.  
  
> [!NOTE]
>  Não há suporte para essa função do Windows **ComboBoxEx** controle. Para obter mais informações sobre esse controle, consulte [ComboBoxEx controles](http://msdn.microsoft.com/library/windows/desktop/bb775738) no SDK do Windows.  
  
 Para inserir uma cadeia de caracteres em um local específico na lista, use o [InsertString](#insertstring) função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#3](../../mfc/reference/codesnippet/cpp/ccombobox-class_1.cpp)]  
  
##  <a name="ccombobox"></a>CComboBox::CComboBox  
 Constrói um objeto `CComboBox`.  
  
```  
CComboBox();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#1](../../mfc/reference/codesnippet/cpp/ccombobox-class_2.cpp)]  
  
##  <a name="clear"></a>CComboBox::Clear  
 Exclui (limpa) a seleção atual, se houver, no controle de edição da caixa de combinação.  
  
```  
void Clear();
```  
  
### <a name="remarks"></a>Comentários  
 Para excluir a seleção atual e colocar o conteúdo excluído na área de transferência, use o [Recortar](#cut) função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#4](../../mfc/reference/codesnippet/cpp/ccombobox-class_3.cpp)]  
  
##  <a name="compareitem"></a>CComboBox::CompareItem  
 Chamado pelo framework para determinar a posição relativa de um novo item na parte de caixa de listagem de uma caixa de combinação do desenho proprietário classificada.  
  
```  
virtual int CompareItem(LPCOMPAREITEMSTRUCT lpCompareItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpCompareItemStruct`  
 Um ponteiro de tempo para um [COMPAREITEMSTRUCT](../../mfc/reference/compareitemstruct-structure.md) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Indica a posição relativa dos dois itens descritos no `COMPAREITEMSTRUCT` estrutura. Ele pode ser qualquer um dos seguintes valores:  
  
|Valor|Significado|  
|-----------|-------------|  
|- 1|Item 1 classifica antes do item 2.|  
|0|Item 1 e item 2 classificados iguais.|  
|1|Item 1 classificado depois item 2.|  
  
 Consulte [CWnd::OnCompareItem](../../mfc/reference/cwnd-class.md#oncompareitem) para obter uma descrição de `COMPAREITEMSTRUCT`.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, essa função de membro não faz nada. Se você criar uma caixa de combinação do desenho proprietário com o **LBS_SORT** estilo, você deve substituir esta função de membro para ajudar a estrutura de classificação novos itens adicionados à caixa de listagem.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#5](../../mfc/reference/codesnippet/cpp/ccombobox-class_4.cpp)]  
  
##  <a name="copy"></a>CComboBox::Copy  
 Copia a seleção atual, se houver, no controle de edição da caixa de combinação para a área de transferência em **CF_TEXT** formato.  
  
```  
void Copy();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#6](../../mfc/reference/codesnippet/cpp/ccombobox-class_5.cpp)]  
  
##  <a name="create"></a>CComboBox::Create  
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
 Especifica o estilo da caixa de combinação. Aplique qualquer combinação de [estilos de caixa de combinação](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) para a caixa.  
  
 `rect`  
 Aponta para a posição e o tamanho da caixa de combinação. Pode ser um [estrutura RECT](../../mfc/reference/rect-structure1.md) ou um `CRect` objeto.  
  
 `pParentWnd`  
 Especifica a janela do pai da caixa de combinação (geralmente um `CDialog`). Ele não deve ser **nulo**.  
  
 `nID`  
 Especifica a ID de controle. da caixa de combinação  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você pode criar um `CComboBox` objeto em duas etapas. Primeiro, chame o construtor e, em seguida, chamar **criar**, que cria a caixa de combinação do Windows e a anexa ao `CComboBox` objeto.  
  
 Quando **criar** executa o Windows envia o [WM_NCCREATE](../../mfc/reference/cwnd-class.md#onnccreate), [WM_CREATE](../../mfc/reference/cwnd-class.md#oncreate), [WM_NCCALCSIZE](../../mfc/reference/cwnd-class.md#onnccalcsize), e [WM _ GETMINMAXINFO](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) mensagens para a caixa de combinação.  
  
 Essas mensagens são tratadas por padrão, o [OnNcCreate](../../mfc/reference/cwnd-class.md#onnccreate), [OnCreate](../../mfc/reference/cwnd-class.md#oncreate), [OnNcCalcSize](../../mfc/reference/cwnd-class.md#onnccalcsize), e [OnGetMinMaxInfo](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) funções de membro no `CWnd` classe base. Para estender a manipulação de mensagem padrão, derive uma classe de `CComboBox`, adicione um mapa de mensagem para a nova classe e substituem as funções de membro anterior do manipulador de mensagens. Substituir `OnCreate`, por exemplo, para executar inicialização necessária para uma nova classe.  
  
 Aplicar o seguinte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) a um controle de caixa de combinação. :  
  
- **Estilo** sempre  
  
- **WS_VISIBLE** normalmente  
  
- **WS_DISABLED** raramente  
  
- **WS_VSCROLL** para adicionar a rolagem vertical da caixa de listagem na caixa de combinação  
  
- **WS_HSCROLL** para adicionar a rolagem horizontal para a caixa de listagem na caixa de combinação  
  
- **WS_GROUP** a controles de grupo  
  
- **WS_TABSTOP** para incluir a caixa de combinação na ordem de tabulação  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#2](../../mfc/reference/codesnippet/cpp/ccombobox-class_6.cpp)]  
  
##  <a name="cut"></a>CComboBox::Cut  
 Exclui (cortes) a seleção atual, se houver, na caixa de combinação Editar controlar e copia o texto excluído na área de transferência em **CF_TEXT** formato.  
  
```  
void Cut();
```  
  
### <a name="remarks"></a>Comentários  
 Para excluir a seleção atual sem colocar o texto excluído na área de transferência, chame o [limpar](#clear) função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#7](../../mfc/reference/codesnippet/cpp/ccombobox-class_7.cpp)]  
  
##  <a name="deleteitem"></a>CComboBox::DeleteItem  
 Chamado pelo framework quando o usuário exclui um item de um desenho proprietário `CComboBox` de objeto ou destrói a caixa de combinação.  
  
```  
virtual void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpDeleteItemStruct`  
 Um ponteiro longo para um Windows [DELETEITEMSTRUCT](../../mfc/reference/deleteitemstruct-structure.md) estrutura que contém informações sobre o item excluído. Consulte [CWnd::OnDeleteItem](../../mfc/reference/cwnd-class.md#ondeleteitem) para obter uma descrição dessa estrutura.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função não faz nada. Substitua essa função para redesenhar a caixa de combinação, conforme necessário.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#8](../../mfc/reference/codesnippet/cpp/ccombobox-class_8.cpp)]  
  
##  <a name="deletestring"></a>CComboBox::DeleteString  
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
 Todos os itens a seguir `nIndex` Agora mova uma posição para baixo. Por exemplo, se uma caixa de combinação contém dois itens, excluir o primeiro item fará com que o item restante ser agora na primeira posição. `nIndex`= 0 para o item na primeira posição.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#9](../../mfc/reference/codesnippet/cpp/ccombobox-class_9.cpp)]  
  
##  <a name="dir"></a>CComboBox::Dir  
 Adiciona uma lista de nomes de arquivos ou unidades de caixa de listagem de uma caixa de combinação.  
  
```  
int Dir(
    UINT attr,  
    LPCTSTR lpszWildCard);
```  
  
### <a name="parameters"></a>Parâmetros  
 `attr`  
 Pode ser qualquer combinação da `enum` valores descritos na [CFile::GetStatus](../../mfc/reference/cfile-class.md#getstatus) ou qualquer combinação dos valores a seguir:  
  
- **DDL_READWRITE** arquivo pode ser lido ou gravado.  
  
- **DDL_READONLY** arquivo pode ser lido do mas não gravado.  
  
- **DDL_HIDDEN** arquivo está oculta e não aparecem em uma listagem de diretório.  
  
- **DDL_SYSTEM** é um arquivo de sistema.  
  
- **DDL_DIRECTORY** o nome especificado pelo `lpszWildCard` Especifica um diretório.  
  
- **DDL_ARCHIVE** arquivo foi arquivado.  
  
- **DDL_DRIVES** incluem todas as unidades que correspondem ao nome especificado pelo `lpszWildCard`.  
  
- **DDL_EXCLUSIVE** sinalizador exclusivo. Se o sinalizador exclusive for definido, somente os arquivos do tipo especificado são listados. Caso contrário, os arquivos do tipo especificado são listados além de arquivos "normais".  
  
 `lpszWildCard`  
 Aponta para uma cadeia de caracteres de especificação de arquivo. A cadeia de caracteres pode conter caracteres curinga (por exemplo, *.\*).  
  
### <a name="return-value"></a>Valor de retorno  
 Se o valor de retorno é maior que ou igual a 0, é o índice de base zero do último nome de arquivo adicionado à lista. O valor de retorno é **CB_ERR** se ocorrer um erro; o valor de retorno é **CB_ERRSPACE** se houver espaço suficiente disponível para armazenar as cadeias de caracteres de nova.  
  
### <a name="remarks"></a>Comentários  
 Não há suporte para essa função do Windows **ComboBoxEx** controle. Para obter mais informações sobre esse controle, consulte [ComboBoxEx controles](http://msdn.microsoft.com/library/windows/desktop/bb775738) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#10](../../mfc/reference/codesnippet/cpp/ccombobox-class_10.cpp)]  
  
##  <a name="drawitem"></a>CComboBox::DrawItem  
 Chamado pelo framework quando um aspecto visual de um muda de caixa de combinação do desenho proprietário.  
  
```  
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpDrawItemStruct`  
 Um ponteiro para um [DRAWITEMSTRUCT](../../mfc/reference/drawitemstruct-structure.md) estrutura que contém informações sobre o tipo de desenho necessárias.  
  
### <a name="remarks"></a>Comentários  
 O **itemAction** membro o `DRAWITEMSTRUCT` estrutura define a ação de desenho que deve ser executada. Consulte [CWnd::OnDrawItem](../../mfc/reference/cwnd-class.md#ondrawitem) para obter uma descrição dessa estrutura.  
  
 Por padrão, essa função de membro não faz nada. Substituir essa função de membro para implementar o desenho de um desenho proprietário `CComboBox` objeto. Antes do encerramento essa função de membro, o aplicativo deve restaurar todos os objetos de interface (GDI) de dispositivo de gráficos selecionados para o contexto de exibição fornecido no `lpDrawItemStruct`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#11](../../mfc/reference/codesnippet/cpp/ccombobox-class_11.cpp)]  
  
##  <a name="findstring"></a>CComboBox:: FindString  
 Localiza, mas não selecionar, a primeira cadeia de caracteres que contém o prefixo especificado na caixa de listagem de uma caixa de combinação.  
  
```  
int FindString(
    int nStartAfter,  
    LPCTSTR lpszString) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nStartAfter`  
 Contém o índice de base zero do item antes do primeiro item a ser pesquisada. Quando a pesquisa alcançar a parte inferior da caixa de listagem, ele continua na parte superior da caixa de listagem para o item especificado pela `nStartAfter`. Se-1, a caixa de listagem inteiro é pesquisada desde o início.  
  
 `lpszString`  
 Aponta para a cadeia de caracteres terminada em nulo que contém o prefixo a ser pesquisado. A pesquisa é o caso independente, para que essa cadeia de caracteres pode conter qualquer combinação de letras maiusculas e minúsculas.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o valor de retorno é maior que ou igual a 0, é o índice de base zero do item correspondente. É **CB_ERR** se a pesquisa não foi bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 Não há suporte para essa função do Windows **ComboBoxEx** controle. Para obter mais informações sobre esse controle, consulte [ComboBoxEx controles](http://msdn.microsoft.com/library/windows/desktop/bb775738) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#12](../../mfc/reference/codesnippet/cpp/ccombobox-class_12.cpp)]  
  
##  <a name="findstringexact"></a>CComboBox::FindStringExact  
 Chamar o `FindStringExact` a função de membro para localizar a primeira caixa de listagem cadeia de caracteres (em uma caixa de combinação) que corresponde à cadeia especificada no `lpszFind`.  
  
```  
int FindStringExact(
    int nIndexStart,  
    LPCTSTR lpszFind) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndexStart`  
 Especifica o índice de base zero do item antes do primeiro item a ser pesquisada. Quando a pesquisa alcançar a parte inferior da caixa de listagem, ele continua na parte superior da caixa de listagem para o item especificado pela `nIndexStart`. Se `nIndexStart` é -1, a caixa de listagem inteiro é pesquisada desde o início.  
  
 `lpszFind`  
 Aponta para a cadeia de caracteres terminada em nulo para pesquisar. Essa cadeia de caracteres pode conter um nome de arquivo completo, incluindo a extensão. A pesquisa não diferencia maiusculas de minúsculas, portanto essa cadeia de caracteres pode conter qualquer combinação de letras maiusculas e minúsculas.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de base zero do item correspondente, ou **CB_ERR** se a pesquisa não foi bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 Se a caixa de combinação foi criada com um estilo de desenho do proprietário, mas sem o [CBS_HASSTRINGS](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo, `FindStringExact` tenta corresponder o valor doubleword em relação ao valor de `lpszFind`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#13](../../mfc/reference/codesnippet/cpp/ccombobox-class_13.cpp)]  
  
##  <a name="getcomboboxinfo"></a>CComboBox::GetComboBoxInfo  
 Recupera informações para o `CComboBox` objeto.  
  
```  
BOOL GetComboBoxInfo(PCOMBOBOXINFO pcbi) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pcbi*  
 Um ponteiro para o [COMBOBOXINFO](http://msdn.microsoft.com/library/windows/desktop/bb775798) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** em caso de sucesso, **FALSE** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro emula a funcionalidade do [CB_GETCOMBOBOXINFO](http://msdn.microsoft.com/library/windows/desktop/bb775839) mensagem, conforme descrito no SDK do Windows.  
  
##  <a name="getcount"></a>CComboBox::GetCount  
 Chame essa função de membro para recuperar o número de itens na parte da caixa de listagem de uma caixa de combinação.  
  
```  
int GetCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens. A contagem é maior do que o valor de índice do último item (o índice é baseado em zero). É **CB_ERR** se ocorrer um erro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#14](../../mfc/reference/codesnippet/cpp/ccombobox-class_14.cpp)]  
  
##  <a name="getcuebanner"></a>CComboBox::GetCueBanner  
 Obtém o texto da indicação que é exibido para um controle de caixa de combinação.  
  
```  
CString GetCueBanner() const;  
  
BOOL GetCueBanner(
    LPTSTR lpszText,   
    int cchText) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[out] `lpszText`|Ponteiro para um buffer que recebe o texto da faixa de indicação.|  
|[in] `cchText`|Tamanho do buffer que o `lpszText` parâmetro aponta para.|  
  
### <a name="return-value"></a>Valor de retorno  
 Na primeira sobrecarga, uma [CString](../../atl-mfc-shared/using-cstring.md) objeto que contém o texto da faixa de indicação se existir; caso contrário, um `CString` objeto que tem comprimento zero.  
  
 -ou-  
  
 Na segunda sobrecarga, `true` se esse método for bem-sucedida; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Texto da indicação é uma solicitação que é exibida na área de entrada de controle de caixa de combinação. O texto da indicação é exibido até que o usuário forneça uma entrada.  
  
 Esse método envia o [CB_GETCUEBANNER](http://msdn.microsoft.com/library/windows/desktop/bb775843) mensagem, que é descrita no SDK do Windows.  
  
##  <a name="getcursel"></a>CComboBox::GetCurSel  
 Chame essa função de membro para determinar qual item na caixa de combinação está selecionado.  
  
```  
int GetCurSel() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de base zero do item atualmente selecionado na caixa de listagem de uma caixa de combinação ou **CB_ERR** se nenhum item selecionado.  
  
### <a name="remarks"></a>Comentários  
 `GetCurSel`Retorna um índice na lista.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#15](../../mfc/reference/codesnippet/cpp/ccombobox-class_15.cpp)]  
  
##  <a name="getdroppedcontrolrect"></a>CComboBox::GetDroppedControlRect  
 Chamar o `GetDroppedControlRect` função de membro para recuperar as coordenadas de tela da caixa visível (descartado) na lista suspensa de uma caixa de combinação suspensa.  
  
```  
void GetDroppedControlRect(LPRECT lprect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *lprect*  
 Aponta para o [estrutura RECT](../../mfc/reference/rect-structure1.md) que está receber as coordenadas.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#16](../../mfc/reference/codesnippet/cpp/ccombobox-class_16.cpp)]  
  
##  <a name="getdroppedstate"></a>CComboBox::GetDroppedState  
 Chamar o `GetDroppedState` a função de membro para determinar se a caixa de listagem de uma caixa de combinação suspensa está visível (aberta).  
  
```  
BOOL GetDroppedState() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a caixa de listagem estiver visível; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#17](../../mfc/reference/codesnippet/cpp/ccombobox-class_17.cpp)]  
  
##  <a name="getdroppedwidth"></a>CComboBox::GetDroppedWidth  
 Chame essa função para recuperar a largura mínima permitida, em pixels, da caixa de listagem de uma caixa de combinação.  
  
```  
int GetDroppedWidth() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, a largura mínima permitida, em pixels. Caso contrário, **CB_ERR**.  
  
### <a name="remarks"></a>Comentários  
 Essa função só se aplica a caixas de combinação com o [CBS_DROPDOWN](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo.  
  
 Por padrão, a largura mínima permitida da caixa de listagem suspensa é 0. A largura mínima de permitido pode ser definida chamando [SetDroppedWidth](#setdroppedwidth). Quando a parte da caixa de listagem da caixa de combinação é exibida, sua largura é maior da largura mínima de permitido ou a largura da caixa de combinação.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [SetDroppedWidth](#setdroppedwidth).  
  
##  <a name="geteditsel"></a>CComboBox::GetEditSel  
 Obtém as posições de caractere inicial e final da seleção atual no controle de edição de uma caixa de combinação.  
  
```  
DWORD GetEditSel() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de 32 bits que contém a posição inicial da palavra de ordem inferior e a posição do primeiro caractere que não selecionado após o final da seleção da palavra de ordem superior. Se essa função é usada em uma caixa de combinação sem um controle de edição, **CB_ERR** é retornado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#18](../../mfc/reference/codesnippet/cpp/ccombobox-class_18.cpp)]  
  
##  <a name="getextendedui"></a>CComboBox::GetExtendedUI  
 Chamar o `GetExtendedUI` a função de membro para determinar se uma caixa de combinação tem a interface do usuário padrão ou a interface do usuário estendida.  
  
```  
BOOL GetExtendedUI() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a caixa de combinação com a interface do usuário estendida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A interface do usuário estendida pode ser identificada das seguintes maneiras:  
  
-   Clicando no controle estático exibe a caixa de listagem somente para caixas de combinação com o [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo.  
  
-   Pressionar a tecla de seta para baixo exibe a caixa de listagem (F4 está desativado).  
  
 Rolagem no controle estático é desabilitada quando a lista de itens não é visível (seta chaves estão desativadas).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#19](../../mfc/reference/codesnippet/cpp/ccombobox-class_19.cpp)]  
  
##  <a name="gethorizontalextent"></a>CComboBox::GetHorizontalExtent  
 Recupera a largura em pixels pelo qual a parte da caixa de listagem da caixa de combinação rolagem horizontal da caixa de combinação.  
  
```  
UINT GetHorizontalExtent() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A largura rolável da parte da caixa de listagem da caixa de combinação, em pixels.  
  
### <a name="remarks"></a>Comentários  
 Isso é aplicável somente se a parte da caixa de listagem da caixa de combinação tem uma barra de rolagem horizontal.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#20](../../mfc/reference/codesnippet/cpp/ccombobox-class_20.cpp)]  
  
##  <a name="getitemdata"></a>CComboBox::GetItemData  
 Recupera o valor de 32 bits fornecido pelo aplicativo associado ao item de caixa de combinação especificada.  
  
```  
DWORD_PTR GetItemData(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Contém o índice de base zero de um item na caixa de listagem da caixa de combinação.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de 32 bits associado ao item ou **CB_ERR** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 O valor de 32 bits pode ser definido com o `dwItemData` parâmetro de um [SetItemData](#setitemdata) chamada de função de membro. Use o `GetItemDataPtr` se o valor de 32 bits a ser recuperado é um ponteiro de função de membro ( **void\***).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#21](../../mfc/reference/codesnippet/cpp/ccombobox-class_21.cpp)]  
  
##  <a name="getitemdataptr"></a>CComboBox::GetItemDataPtr  
 Recupera o valor de 32 bits fornecido pelo aplicativo associado ao item de caixa de combinação especificado como um ponteiro ( **void\***).  
  
```  
void* GetItemDataPtr(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Contém o índice de base zero de um item na caixa de listagem da caixa de combinação.  
  
### <a name="return-value"></a>Valor de retorno  
 Recupera um ponteiro ou -1 se ocorrer um erro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#22](../../mfc/reference/codesnippet/cpp/ccombobox-class_22.cpp)]  
  
##  <a name="getitemheight"></a>CComboBox::GetItemHeight  
 Chamar o `GetItemHeight` função de membro para recuperar a altura dos itens de lista em uma caixa de combinação.  
  
```  
int GetItemHeight(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o componente da caixa de combinação cuja altura é a ser recuperado. Se o `nIndex` parâmetro é -1, a altura da porção de controle de edição (ou texto estático) da caixa de combinação é recuperada. Se a caixa de combinação com o [CBS_OWNERDRAWVARIABLE](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo, `nIndex` Especifica o índice de base zero do item da lista cuja altura é a ser recuperado. Caso contrário, `nIndex` deve ser definido como 0.  
  
### <a name="return-value"></a>Valor de retorno  
 A altura, em pixels, do item especificado em uma caixa de combinação. O valor de retorno é **CB_ERR** se ocorrer um erro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#23](../../mfc/reference/codesnippet/cpp/ccombobox-class_23.cpp)]  
  
##  <a name="getlbtext"></a>CComboBox::GetLBText  
 Obtém uma cadeia de caracteres da caixa de listagem de uma caixa de combinação.  
  
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
 Contém o índice de base zero da cadeia de caracteres da caixa de listagem a ser copiado.  
  
 `lpszText`  
 Aponta para um buffer que está receber a cadeia de caracteres. O buffer deve ter espaço suficiente para a cadeia de caracteres e um caractere null de terminação.  
  
 `rString`  
 Uma referência a um `CString`.  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento (em bytes) da cadeia de caracteres, excluindo o caractere null de terminação. Se `nIndex` não especifica um índice válido, o valor de retorno é **CB_ERR**.  
  
### <a name="remarks"></a>Comentários  
 O segundo formulário desse membro da função preenchimentos um `CString` objeto com o texto do item.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#24](../../mfc/reference/codesnippet/cpp/ccombobox-class_24.cpp)]  
  
##  <a name="getlbtextlen"></a>CComboBox::GetLBTextLen  
 Obtém o comprimento de uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.  
  
```  
int GetLBTextLen(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Contém o índice de base zero da cadeia de caracteres da caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento da cadeia de caracteres em bytes, excluindo o caractere null de terminação. Se `nIndex` não especifica um índice válido, o valor de retorno é **CB_ERR**.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CComboBox::GetLBText](#getlbtext).  
  
##  <a name="getlocale"></a>CComboBox::GetLocale  
 Recupera a localidade usada por caixa de combinação.  
  
```  
LCID GetLocale() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor LCID (identificador) da localidade para cadeias de caracteres na caixa de combinação.  
  
### <a name="remarks"></a>Comentários  
 A localidade é usada, por exemplo, para determinar a ordem de classificação de cadeias de caracteres em uma caixa de combinação classificada.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CComboBox::SetLocale](#setlocale).  
  
##  <a name="getminvisible"></a>CComboBox::GetMinVisible  
 Obtém o número mínimo de itens visíveis na lista suspensa de controle de caixa de combinação atual.  
  
```  
int GetMinVisible() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número mínimo de itens visíveis na lista suspensa atual.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [CB_GETMINVISIBLE](http://msdn.microsoft.com/library/windows/desktop/bb775915) mensagem, que é descrita no SDK do Windows.  
  
##  <a name="gettopindex"></a>CComboBox::GetTopIndex  
 Recupera o índice com base em zero do primeiro item visível na parte de caixa de listagem da caixa de combinação.  
  
```  
int GetTopIndex() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de base zero do primeiro item visível na parte de caixa de listagem da caixa de combinação, se for bem-sucedido, **CB_ERR** caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Inicialmente, o item 0 está na parte superior da caixa de listagem, mas se a caixa de listagem é rolada, outro item pode estar no topo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#25](../../mfc/reference/codesnippet/cpp/ccombobox-class_25.cpp)]  
  
##  <a name="initstorage"></a>CComboBox::InitStorage  
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
 Se for bem-sucedido, o número máximo de itens que a parte da caixa de listagem da caixa de combinação pode armazenar antes de uma realocação de memória é necessária, caso contrário, **CB_ERRSPACE**, que significa que não há memória suficiente está disponível.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função antes de adicionar um grande número de itens para a parte da caixa de lista de `CComboBox`.  
  
 Windows 95/98 somente: O `wParam` parâmetro é limitado a valores de 16 bits. Isso significa que caixas de listagem não podem conter mais de 32.767 itens. Embora o número de itens é restrito, o tamanho total dos itens em uma caixa de listagem é limitado apenas pela memória disponível.  
  
 Essa função ajuda a acelerar a inicialização das caixas de listagem que têm um grande número de itens (mais de 100). Ele preallocates a quantidade especificada de memória subsequente assim que [AddString](#addstring), [InsertString](#insertstring), e [Dir](#dir) funções usam o menor tempo possível. Você pode usar estimativas para os parâmetros. Se você superestimar, é alocada memória extra; Se você subestimar, a alocação normal é usada para itens que excedem a quantidade pré-alocados.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#26](../../mfc/reference/codesnippet/cpp/ccombobox-class_26.cpp)]  
  
##  <a name="insertstring"></a>CComboBox::InsertString  
 Insere uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.  
  
```  
int InsertString(
    int nIndex,  
    LPCTSTR lpszString);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Contém o índice com base em zero para a posição na caixa de listagem que receberá a cadeia de caracteres. Se esse parâmetro for -1, a cadeia de caracteres é adicionada ao final da lista.  
  
 `lpszString`  
 Aponta para a cadeia de caracteres terminada em nulo que deve ser inserido.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero da posição em que a cadeia de caracteres foi inserida. O valor de retorno é **CB_ERR** se ocorrer um erro. O valor de retorno é **CB_ERRSPACE** se houver espaço suficiente armazenar a nova cadeia de caracteres.  
  
### <a name="remarks"></a>Comentários  
 Ao contrário de [AddString](#addstring) função de membro, o `InsertString` função de membro não faz com que uma lista com o [CBS_SORT](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo a ser classificada.  
  
> [!NOTE]
>  Não há suporte para essa função do Windows **ComboBoxEx** controle. Para obter mais informações sobre esse controle, consulte [ComboBoxEx controles](http://msdn.microsoft.com/library/windows/desktop/bb775738) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#27](../../mfc/reference/codesnippet/cpp/ccombobox-class_27.cpp)]  
  
##  <a name="limittext"></a>CComboBox::LimitText  
 Limita o comprimento em bytes do texto que o usuário pode inserir no controle de edição de uma caixa de combinação.  
  
```  
BOOL LimitText(int nMaxChars);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMaxChars`  
 Especifica o comprimento (em bytes) do que o usuário pode inserir texto. Se esse parâmetro for 0, o comprimento do texto é definido como 65.535 bytes.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se tiver êxito. Se a chamada para uma caixa de combinação com o estilo [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou para uma caixa de combinação sem um controle de edição, o valor de retorno é **CB_ERR**.  
  
### <a name="remarks"></a>Comentários  
 Se a caixa de combinação não tem o estilo [CBS_AUTOHSCROLL](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles), definir o limite de texto seja maior que o tamanho do controle de edição não terá efeito.  
  
 `LimitText`limita apenas o texto que o usuário pode inserir. Não tem nenhum efeito em qualquer texto já no controle de edição quando a mensagem é enviada, nem afeta o tamanho do texto copiado para o controle de edição quando uma cadeia de caracteres na caixa de listagem é selecionada.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#28](../../mfc/reference/codesnippet/cpp/ccombobox-class_28.cpp)]  
  
##  <a name="measureitem"></a>CComboBox::MeasureItem  
 Chamado pelo framework quando uma caixa de combinação com um estilo de desenho proprietário é criada.  
  
```  
virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpMeasureItemStruct`  
 Um ponteiro de tempo para um [MEASUREITEMSTRUCT](../../mfc/reference/measureitemstruct-structure.md) estrutura.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, essa função de membro não faz nada. Substituir essa função de membro e preencha o `MEASUREITEMSTRUCT` estrutura para informar a caixa Windows das dimensões da lista na caixa de combinação. Se a caixa de combinação é criada com o [CBS_OWNERDRAWVARIABLE](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo, o framework chama esta função de membro para cada item na caixa de listagem. Caso contrário, esse membro é chamado apenas uma vez.  
  
 Usando o **CBS_OWNERDRAWFIXED** estilo em uma caixa de combinação do desenho proprietário criado com o [SubclassDlgItem](../../mfc/reference/cwnd-class.md#subclassdlgitem) função de membro `CWnd` envolve considerações de programação mais. Consulte a discussão na [14 de observação técnica](../../mfc/tn014-custom-controls.md).  
  
 Consulte [CWnd::OnMeasureItem](../../mfc/reference/cwnd-class.md#onmeasureitem) para obter uma descrição de `MEASUREITEMSTRUCT` estrutura.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#29](../../mfc/reference/codesnippet/cpp/ccombobox-class_29.cpp)]  
  
##  <a name="paste"></a>CComboBox::Paste  
 Insere os dados da área de transferência no controle de edição da caixa de combinação na posição atual do cursor.  
  
```  
void Paste();
```  
  
### <a name="remarks"></a>Comentários  
 Os dados são inseridos somente se a área de transferência contém dados em **CF_TEXT** formato.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#30](../../mfc/reference/codesnippet/cpp/ccombobox-class_30.cpp)]  
  
##  <a name="resetcontent"></a>CComboBox::ResetContent  
 Remove todos os itens da lista de caixa e controle de uma caixa de combinação de edição.  
  
```  
void ResetContent();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#31](../../mfc/reference/codesnippet/cpp/ccombobox-class_31.cpp)]  
  
##  <a name="selectstring"></a>CComboBox::SelectString  
 Pesquisa uma cadeia de caracteres na caixa de listagem de uma caixa de combinação e se a cadeia de caracteres for encontrada, seleciona a cadeia de caracteres na caixa de listagem e copiá-lo para o controle de edição.  
  
```  
int SelectString(
    int nStartAfter,  
    LPCTSTR lpszString);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nStartAfter`  
 Contém o índice de base zero do item antes do primeiro item a ser pesquisada. Quando a pesquisa alcançar a parte inferior da caixa de listagem, ele continua na parte superior da caixa de listagem para o item especificado pela `nStartAfter`. Se-1, a caixa de listagem inteiro é pesquisada desde o início.  
  
 `lpszString`  
 Aponta para a cadeia de caracteres terminada em nulo que contém o prefixo a ser pesquisado. A pesquisa é o caso independente, para que essa cadeia de caracteres pode conter qualquer combinação de letras maiusculas e minúsculas.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de base zero do item selecionado se a cadeia de caracteres foi encontrada. Se a pesquisa tiver êxito, o valor de retorno é **CB_ERR** e a seleção atual não é alterada.  
  
### <a name="remarks"></a>Comentários  
 Uma cadeia de caracteres é selecionada apenas se seu caracteres inicias (do ponto de partida) corresponder aos caracteres na cadeia de caracteres de prefixo.  
  
 Observe que o `SelectString` e `FindString` funções de membro localizar uma cadeia de caracteres, mas o `SelectString` função membro também seleciona a cadeia de caracteres.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#32](../../mfc/reference/codesnippet/cpp/ccombobox-class_32.cpp)]  
  
##  <a name="setcuebanner"></a>CComboBox::SetCueBanner  
 Define o texto da indicação que é exibido para um controle de caixa de combinação.  
  
```  
BOOL SetCueBanner(LPCTSTR lpszText);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *lpszText*|Ponteiro para um buffer terminada em nulo que contém o texto da indicação.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o método for bem-sucedido; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Texto da indicação é uma solicitação que é exibida na área de entrada de controle de caixa de combinação. O texto da indicação é exibido até que o usuário forneça uma entrada.  
  
 Esse método envia o [CB_SETCUEBANNER](http://msdn.microsoft.com/library/windows/desktop/bb775897) mensagem, que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_combobox`, que é usado para acessar programaticamente o controle de caixa de combinação. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CComboBox_s1#1](../../mfc/reference/codesnippet/cpp/ccombobox-class_33.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a faixa de indicação para o controle de caixa de combinação.  
  
 [!code-cpp[NVC_MFC_CComboBox_s1#2](../../mfc/reference/codesnippet/cpp/ccombobox-class_34.cpp)]  
  
##  <a name="setcursel"></a>CComboBox::SetCurSel  
 Seleciona uma cadeia de caracteres na caixa de listagem de uma caixa de combinação.  
  
```  
int SetCurSel(int nSelect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSelect`  
 Especifica o índice de base zero da cadeia de caracteres para selecionar. Se-1, qualquer seleção atual na caixa de listagem é removida e o controle de edição é limpo.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de base zero do item selecionado se a mensagem for bem-sucedida. O valor de retorno é **CB_ERR** se `nSelect` é maior que o número de itens na lista ou se `nSelect` é definido como -1, que limpa a seleção.  
  
### <a name="remarks"></a>Comentários  
 Se necessário, a caixa de listagem rola a cadeia de caracteres para exibição (se a caixa de listagem é visível). O texto no controle de edição da caixa de combinação é alterado para refletir a nova seleção. Qualquer seleção anterior na caixa de listagem é removida.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#33](../../mfc/reference/codesnippet/cpp/ccombobox-class_35.cpp)]  
  
##  <a name="setdroppedwidth"></a>CComboBox::SetDroppedWidth  
 Chame essa função para definir a largura mínima permitida, em pixels, da caixa de listagem de uma caixa de combinação.  
  
```  
int SetDroppedWidth(UINT nWidth);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nWidth`  
 A largura mínima permitida da parte da caixa de listagem da caixa de combinação, em pixels.  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, a nova largura da lista de caixa, caso contrário, **CB_ERR**.  
  
### <a name="remarks"></a>Comentários  
 Essa função só se aplica a caixas de combinação com o [CBS_DROPDOWN](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo.  
  
 Por padrão, a largura mínima permitida da caixa de listagem suspensa é 0. Quando a parte da caixa de listagem da caixa de combinação é exibida, sua largura é maior da largura mínima de permitido ou a largura da caixa de combinação.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#34](../../mfc/reference/codesnippet/cpp/ccombobox-class_36.cpp)]  
  
##  <a name="seteditsel"></a>CComboBox::SetEditSel  
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
 Especifica a posição final. Se a posição final é definida como -1, em seguida, todo o texto da posição inicial para o último caractere no controle de edição é selecionado.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função de membro for bem-sucedida; Caso contrário, 0. É **CB_ERR** se `CComboBox` tem o [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo ou não tem uma caixa de listagem.  
  
### <a name="remarks"></a>Comentários  
 As posições são baseadas em zero. Para selecionar o primeiro caractere do controle de edição, você deve especificar uma posição inicial de 0. É a posição final para o caractere logo após o último caractere para selecionar. Por exemplo, para selecionar os primeiros quatro caracteres do controle de edição, você usaria uma posição inicial de 0 e uma posição final de 4.  
  
> [!NOTE]
>  Não há suporte para essa função do Windows **ComboBoxEx** controle. Para obter mais informações sobre esse controle, consulte [ComboBoxEx controles](http://msdn.microsoft.com/library/windows/desktop/bb775738) no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CComboBox::GetEditSel](#geteditsel).  
  
##  <a name="setextendedui"></a>CComboBox::SetExtendedUI  
 Chamar o `SetExtendedUI` a função de membro para selecionar a interface de usuário padrão ou a interface do usuário estendida para uma caixa de combinação que tenha o [CBS_DROPDOWN](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo.  
  
```  
int SetExtendedUI(BOOL bExtended = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bO*  
 Especifica se a caixa de combinação deve usar a interface do usuário estendida ou a interface de usuário padrão. Um valor de **TRUE** seleciona estendido interface do usuário; um valor de **FALSE** seleciona a interface de usuário padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 **CB_OKAY** se a operação for bem-sucedida, ou **CB_ERR** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 A interface do usuário estendida pode ser identificada das seguintes maneiras:  
  
-   Clicando no controle estático exibe a caixa de listagem somente para caixas de combinação com o **CBS_DROPDOWNLIST** estilo.  
  
-   Pressionar a tecla de seta para baixo exibe a caixa de listagem (F4 está desativado).  
  
 Rolagem no controle estático é desabilitada quando a lista de itens não estiver visível (as teclas de direção estiverem desabilitadas).  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CComboBox::GetExtendedUI](#getextendedui).  
  
##  <a name="sethorizontalextent"></a>CComboBox::SetHorizontalExtent  
 Define a largura, em pixels, pelo qual a parte da caixa de listagem da caixa de combinação pode ser rolada horizontalmente.  
  
```  
void SetHorizontalExtent(UINT nExtent);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nExtent*  
 Especifica o número de pixels pelo qual a parte da caixa de listagem da caixa de combinação pode ser rolada horizontalmente.  
  
### <a name="remarks"></a>Comentários  
 Se a largura da caixa de listagem é menor do que esse valor, a barra de rolagem horizontal rolar horizontalmente itens na caixa de listagem. Se a largura da caixa de listagem é igual ou maior que esse valor, a barra de rolagem horizontal está oculto ou, se a caixa de combinação com o [CBS_DISABLENOSCROLL](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo, desabilitado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#35](../../mfc/reference/codesnippet/cpp/ccombobox-class_37.cpp)]  
  
##  <a name="setitemdata"></a>CComboBox::SetItemData  
 Define o valor de 32 bits associado com o item especificado em uma caixa de combinação.  
  
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
 [!code-cpp[NVC_MFC_CComboBox#36](../../mfc/reference/codesnippet/cpp/ccombobox-class_38.cpp)]  
  
##  <a name="setitemdataptr"></a>CComboBox::SetItemDataPtr  
 Define o valor de 32 bits associado com o item especificado em uma caixa de combinação para ser o ponteiro especificado ( **void\***).  
  
```  
int SetItemDataPtr(
    int nIndex,  
    void* pData);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Contém um índice com base em zero para o item.  
  
 `pData`  
 Contém o ponteiro para associar o item.  
  
### <a name="return-value"></a>Valor de retorno  
 **CB_ERR** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Este ponteiro permanece válido durante a vida útil da caixa de combinação, mesmo que a posição relativa do item dentro da caixa de combinação pode alterar como os itens são adicionados ou removidos. Portanto, pode alterar o índice do item dentro da caixa, mas o ponteiro permanece confiável.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#37](../../mfc/reference/codesnippet/cpp/ccombobox-class_39.cpp)]  
  
##  <a name="setitemheight"></a>CComboBox::SetItemHeight  
 Chamar o `SetItemHeight` a função de membro para definir a altura de itens de lista em uma caixa de combinação ou a altura da porção de controle de edição (ou texto estático) de uma caixa de combinação.  
  
```  
int SetItemHeight(
    int nIndex,  
    UINT cyItemHeight);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica se a altura de itens da lista ou da altura da porção de controle de edição (ou texto estático) da caixa de combinação está definida.  
  
 Se a caixa de combinação com o [CBS_OWNERDRAWVARIABLE](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo, `nIndex` Especifica o índice de base zero do item da lista é ser definida; caso contrário, cuja altura `nIndex` deve ser 0 e a altura da lista de todos os itens serão definidos.  
  
 Se `nIndex` é -1, a altura do controle de edição ou parte do texto estático da caixa de combinação será definido.  
  
 `cyItemHeight`  
 Especifica a altura, em pixels, do componente caixa de combinação identificado por `nIndex`.  
  
### <a name="return-value"></a>Valor de retorno  
 **CB_ERR** se o índice ou a altura é inválido; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A altura da porção de controle de edição (ou texto estático) da caixa de combinação é definida independentemente da altura dos itens da lista. Um aplicativo deve garantir que a altura da parte do controle de edição (ou texto estático) não é menor do que a altura de um item específico da caixa de listagem.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#38](../../mfc/reference/codesnippet/cpp/ccombobox-class_40.cpp)]  
  
##  <a name="setlocale"></a>CComboBox::SetLocale  
 Define o identificador de localidade para essa caixa de combinação.  
  
```  
LCID SetLocale(LCID nNewLocale);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nNewLocale`  
 O novo valor LCID (identificador) de localidade a ser definido para a caixa de combinação.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor LCID (identificador) localidade anterior para essa caixa de combinação.  
  
### <a name="remarks"></a>Comentários  
 Se **SetLocale** não for chamado, o padrão é obtida localidade do sistema. Esse local padrão do sistema pode ser modificado por meio do painel de controle de aplicativo regionais (ou internacional).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#39](../../mfc/reference/codesnippet/cpp/ccombobox-class_41.cpp)]  
  
##  <a name="setminvisibleitems"></a>CComboBox::SetMinVisibleItems  
 Define o número mínimo de itens visíveis na lista suspensa da caixa de combinação de atual de controle de caixa.  
  
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
 Esse método envia o [CB_SETMINVISIBLE](http://msdn.microsoft.com/library/windows/desktop/bb775915) mensagem, que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_combobox`, que é usado para acessar programaticamente o controle de caixa de combinação. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CComboBox_s1#1](../../mfc/reference/codesnippet/cpp/ccombobox-class_33.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir insere 20 itens na lista suspensa de um controle de caixa de combinação. Em seguida, especifica que um mínimo de 10 itens exibida quando um usuário pressiona a seta suspensa.  
  
 [!code-cpp[NVC_MFC_CComboBox_s1#2](../../mfc/reference/codesnippet/cpp/ccombobox-class_34.cpp)]  
  
##  <a name="settopindex"></a>CComboBox::SetTopIndex  
 Garante que um determinado item está visível na parte de caixa de listagem da caixa de combinação.  
  
```  
int SetTopIndex(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Especifica o índice de base zero do item de caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Zero se tiver êxito, ou **CB_ERR** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 O sistema rola a caixa de listagem até que o item especificado pelo `nIndex` aparece na parte superior da lista de caixa ou o intervalo de rolagem máximo foi atingido.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CComboBox#40](../../mfc/reference/codesnippet/cpp/ccombobox-class_42.cpp)]  
  
##  <a name="showdropdown"></a>CComboBox::ShowDropDown  
 Mostra ou oculta a caixa de listagem de uma caixa de combinação que tenha o [CBS_DROPDOWN](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) ou [CBS_DROPDOWNLIST](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo.  
  
```  
void ShowDropDown(BOOL bShowIt = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bShowIt*  
 Especifica se a caixa de listagem suspensa deve ser mostrado ou oculto. Um valor de **TRUE** mostra a caixa de listagem. Um valor de **FALSE** oculta a caixa de listagem.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, uma caixa de combinação desse estilo mostrará a caixa de listagem.  
  
 Essa função de membro não tem nenhum efeito em uma caixa de combinação criada com o [CBS_SIMPLE](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles) estilo.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CComboBox::GetDroppedState](#getdroppedstate).  
  
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
