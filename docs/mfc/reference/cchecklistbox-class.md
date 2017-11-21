---
title: Classe CCheckListBox | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CCheckListBox
- AFXWIN/CCheckListBox
- AFXWIN/CCheckListBox::CCheckListBox
- AFXWIN/CCheckListBox::Create
- AFXWIN/CCheckListBox::DrawItem
- AFXWIN/CCheckListBox::Enable
- AFXWIN/CCheckListBox::GetCheck
- AFXWIN/CCheckListBox::GetCheckStyle
- AFXWIN/CCheckListBox::IsEnabled
- AFXWIN/CCheckListBox::MeasureItem
- AFXWIN/CCheckListBox::OnGetCheckPosition
- AFXWIN/CCheckListBox::SetCheck
- AFXWIN/CCheckListBox::SetCheckStyle
dev_langs: C++
helpviewer_keywords:
- CCheckListBox [MFC], CCheckListBox
- CCheckListBox [MFC], Create
- CCheckListBox [MFC], DrawItem
- CCheckListBox [MFC], Enable
- CCheckListBox [MFC], GetCheck
- CCheckListBox [MFC], GetCheckStyle
- CCheckListBox [MFC], IsEnabled
- CCheckListBox [MFC], MeasureItem
- CCheckListBox [MFC], OnGetCheckPosition
- CCheckListBox [MFC], SetCheck
- CCheckListBox [MFC], SetCheckStyle
ms.assetid: 1dd78438-00e8-441c-b36f-9c4f9ac0d019
caps.latest.revision: "26"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: fe432aec3a68889ad70ab7c229df3c2f7529df3f
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cchecklistbox-class"></a>Classe CCheckListBox
Fornece a funcionalidade de uma caixa de lista de verificação do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CCheckListBox : public CListBox  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCheckListBox::CCheckListBox](#cchecklistbox)|Constrói um objeto `CCheckListBox`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCheckListBox::Create](#create)|Cria a caixa de lista de verificação do Windows e a anexa ao `CCheckListBox` objeto.|  
|[CCheckListBox::DrawItem](#drawitem)|Chamado pelo framework quando um aspecto visual de uma caixa de listagem do desenho proprietário mude.|  
|[CCheckListBox::Enable](#enable)|Habilita ou desabilita um item da caixa de lista de verificação.|  
|[CCheckListBox::GetCheck](#getcheck)|Obtém o estado do item caixa de seleção.|  
|[CCheckListBox::GetCheckStyle](#getcheckstyle)|Obtém o estilo das caixas de seleção do controle.|  
|[CCheckListBox::IsEnabled](#isenabled)|Determina se um item está habilitado.|  
|[CCheckListBox::MeasureItem](#measureitem)|Chamado pelo framework quando uma caixa de listagem com um estilo de desenho proprietário é criada.|  
|[CCheckListBox::OnGetCheckPosition](#ongetcheckposition)|Chamado pelo framework para obter a posição da caixa de seleção de um item.|  
|[CCheckListBox::SetCheck](#setcheck)|Define o estado do item caixa de seleção.|  
|[CCheckListBox::SetCheckStyle](#setcheckstyle)|Define o estilo do controle caixas de seleção.|  
  
## <a name="remarks"></a>Comentários  
 Uma caixa de lista de verificação"" exibe uma lista de itens, como nomes de arquivos. Cada item na lista tem uma caixa de seleção ao lado dele que o usuário pode verificar ou limpar.  
  
 `CCheckListBox`é somente para controles desenhados pelo proprietário porque a lista contém mais de cadeias de caracteres de texto. Em sua forma mais simples, uma caixa de lista de verificação contém cadeias de caracteres de texto e caixas de seleção, mas você não precisa ter texto. Por exemplo, você pode ter uma lista de bitmaps pequenos com uma caixa de seleção ao lado de cada item.  
  
 Para criar sua própria caixa de lista de verificação, você deve derivar sua própria classe de `CCheckListBox`. Derive sua classe, escrever um construtor para a classe derivada, em seguida, chame **criar**.  
  
 Se você desejar tratar mensagens de notificação do Windows enviadas por uma caixa de listagem para seu pai (geralmente uma classe derivada de [CDialog](../../mfc/reference/cdialog-class.md)), adicionar uma função de membro de entrada e o manipulador de mensagens do mapa de mensagem para a classe pai para cada mensagem.  
  
 Cada entrada de mapa de mensagem assume o seguinte formato:  
  
 **On _**notificação **(**`id`, `memberFxn` **)**  
  
 onde `id` Especifica a ID de janela filho do controle que está enviando a notificação e `memberFxn` é o nome da função de membro pai que você tenha escrito para manipular a notificação.  
  
 O protótipo de função do pai é o seguinte:  
  
 **afx_msg** `void` `memberFxn` **();**  
  
 Há apenas uma entrada de mapa de mensagem que diz respeito especificamente ao **CCheckListBox** (mas consulte também as entradas de mapa de mensagem para [CListBox](../../mfc/reference/clistbox-class.md)):  
  
- **ON_CLBN_CHKCHANGE** o usuário alterou o estado da caixa de seleção de um item.  
  
 Se sua caixa de lista de verificação é uma caixa de lista de verificação padrão (uma lista de cadeias de caracteres com as caixas de seleção de tamanho padrão à esquerda de cada), você pode usar o padrão [CCheckListBox::DrawItem](#drawitem) para desenhar a caixa de lista de verificação. Caso contrário, você deve substituir o [CListBox::CompareItem](../../mfc/reference/clistbox-class.md#compareitem) função e o [CCheckListBox::DrawItem](#drawitem) e [CCheckListBox::MeasureItem](#measureitem) funções.  
  
 Você pode criar uma caixa de lista de verificação de um modelo de caixa de diálogo ou diretamente em seu código.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CListBox](../../mfc/reference/clistbox-class.md)  
  
 `CCheckListBox`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
##  <a name="cchecklistbox"></a>CCheckListBox::CCheckListBox  
 Constrói um objeto `CCheckListBox`.  
  
```  
CCheckListBox();
```  
  
### <a name="remarks"></a>Comentários  
 Você pode criar um `CCheckListBox` objeto em duas etapas. Primeiro definir uma classe derivada de `CCheckListBox`, em seguida, chame **criar**, que inicia a caixa de lista de verificação do Windows e a anexa ao `CCheckListBox` objeto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCControlLadenDialog#60](../../mfc/codesnippet/cpp/cchecklistbox-class_1.cpp)]  
  
##  <a name="create"></a>CCheckListBox::Create  
 Cria a caixa de lista de verificação do Windows e a anexa ao `CCheckListBox` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Especifica o estilo da caixa de lista de verificação. O estilo deve ser **LBS_HASSTRINGS** e **LBS_OWNERDRAWFIXED** (todos os itens na lista são da mesma altura) ou **LBS_OWNERDRAWVARIABLE** (itens da lista são do alturas diferentes). Esse estilo pode ser combinado com outros [estilos de caixa de listagem](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) exceto **LBS_USETABSTOPS**.  
  
 `rect`  
 Especifica o tamanho da caixa de lista de verificação e a posição. Pode ser um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou um [RECT](../../mfc/reference/rect-structure1.md) estrutura.  
  
 `pParentWnd`  
 Especifica a janela do pai da caixa de lista de verificação (geralmente um `CDialog` objeto). Ele não deve ser **nulo**.  
  
 `nID`  
 Especifica a ID de controle. da caixa de lista de verificação  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você pode criar um `CCheckListBox` objeto em duas etapas. Primeiro, definir uma classe derivada de **CcheckListBox** e, em seguida, chame **criar**, que inicia a caixa de lista de verificação do Windows e anexa-o para o `CCheckListBox`. Consulte [CCheckListBox::CCheckListBox](#cchecklistbox) para obter um exemplo.  
  
 Quando **criar** executa o Windows envia o [WM_NCCREATE](../../mfc/reference/cwnd-class.md#onnccreate), [WM_CREATE](../../mfc/reference/cwnd-class.md#oncreate), [WM_NCCALCSIZE](../../mfc/reference/cwnd-class.md#onnccalcsize), e [WM _ GETMINMAXINFO](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) mensagens para o controle de caixa de lista de verificação.  
  
 Essas mensagens são tratadas por padrão, o [OnNcCreate](../../mfc/reference/cwnd-class.md#onnccreate), [OnCreate](../../mfc/reference/cwnd-class.md#oncreate), [OnNcCalcSize](../../mfc/reference/cwnd-class.md#onnccalcsize), e [OnGetMinMaxInfo](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) funções de membro no `CWnd` classe base. Para estender a manipulação de mensagem padrão, adicione um mapa de mensagem para a sua classe derivada e funções de membro de substituição, o manipulador de mensagem anterior. Substituir `OnCreate`, por exemplo, para executar inicialização necessária para uma nova classe.  
  
 Aplicar o seguinte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) para um controle de caixa de lista de verificação:  
  
- **Estilo** sempre  
  
- **WS_VISIBLE** normalmente  
  
- **WS_DISABLED** raramente  
  
- **WS_VSCROLL** para adicionar uma barra de rolagem vertical  
  
- **WS_HSCROLL** para adicionar uma barra de rolagem horizontal  
  
- **WS_GROUP** a controles de grupo  
  
- **WS_TABSTOP** para permitir a este controle de tabulação  
  
##  <a name="drawitem"></a>CCheckListBox::DrawItem  
 Chamado pelo framework quando um aspecto visual de uma caixa muda desenhados pelo proprietário da lista de verificação.  
  
```  
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpDrawItemStruct`  
 Um ponteiro de tempo para um [DRAWITEMSTRUCT](../../mfc/reference/drawitemstruct-structure.md) estrutura que contém informações sobre o tipo de desenho necessárias.  
  
### <a name="remarks"></a>Comentários  
 O **itemAction** e **itemState** membros o `DRAWITEMSTRUCT` estrutura define a ação de desenho que deve ser executada.  
  
 Por padrão, essa função desenha uma lista de caixa de seleção padrão, que consiste de uma lista de cadeias de caracteres de cada com uma caixa de seleção de tamanho padrão para a esquerda. O tamanho da lista de caixa de seleção é especificada em [criar](#create).  
  
 Substitua essa função de membro para implementar desenho de caixas de lista de verificação de desenho do proprietário que não são padrão, como caixas de lista de verificação com listas que não são cadeias de caracteres, com itens de altura variável ou com caixas de seleção que não estão no lado esquerdo. O aplicativo deve restaurar todos os objetos de interface (GDI) do dispositivo gráficos selecionados para o contexto de exibição fornecido no `lpDrawItemStruct` antes do encerramento desta função de membro.  
  
 Se itens da caixa de lista de verificação não são da mesma altura, a lista de verificação do estilo de caixa (especificado na **criar**) deve ser **LBS_OWNERVARIABLE**, e você deve substituir o [MeasureItem](#measureitem) função.  
  
##  <a name="enable"></a>CCheckListBox::Enable  
 Chame essa função para habilitar ou desabilitar um item de caixa de lista de verificação.  
  
```  
void Enable(
    int nIndex,  
    BOOL bEnabled = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice do item de caixa de lista de verificação a ser habilitado.  
  
 `bEnabled`  
 Especifica se o item está habilitado ou desabilitado.  
  
##  <a name="getcheck"></a>CCheckListBox::GetCheck  
 Recupera o estado da caixa de seleção especificado.  
  
```  
int GetCheck(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice de base zero de uma caixa de seleção está contida na caixa de listagem.  
  
### <a name="return-value"></a>Valor de retorno  
 O estado da caixa de seleção especificado. A tabela a seguir lista os valores possíveis.  
  
|Valor|Descrição|  
|-----------|-----------------|  
|`BST_CHECKED`|A caixa de seleção está marcada.|  
|`BST_UNCHECKED`|A caixa de seleção não está marcada.|  
|`BST_INDETERMINATE`|O estado da caixa de seleção é indeterminado.|  
  
##  <a name="getcheckstyle"></a>CCheckListBox::GetCheckStyle  
 Chame essa função para obter o estilo da caixa de lista de verificação.  
  
```  
UINT GetCheckStyle();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O estilo das caixas de seleção do controle.  
  
### <a name="remarks"></a>Comentários  
 Para obter informações sobre estilos possíveis, consulte [SetCheckStyle](#setcheckstyle).  
  
##  <a name="isenabled"></a>CCheckListBox::IsEnabled  
 Chame essa função para determinar se um item está habilitado.  
  
```  
BOOL IsEnabled(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice do item.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o item estiver habilitado; Caso contrário, 0.  
  
##  <a name="measureitem"></a>CCheckListBox::MeasureItem  
 Chamado pelo framework quando uma caixa de lista de verificação com um estilo não padrão é criada.  
  
```  
virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpMeasureItemStruct`  
 Um ponteiro de tempo para um [MEASUREITEMSTRUCT](../../mfc/reference/measureitemstruct-structure.md) estrutura.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, essa função de membro não faz nada. Substituir essa função de membro e preencha o `MEASUREITEMSTRUCT` estrutura para informar ao Windows das dimensões de itens da caixa de lista de verificação. Se a caixa de lista de verificação é criada com o [LBS_OWNERDRAWVARIABLE](../../mfc/reference/styles-used-by-mfc.md#list-box-styles) estilo, o framework chama esta função de membro para cada item na caixa de listagem. Caso contrário, esse membro é chamado apenas uma vez.  
  
##  <a name="ongetcheckposition"></a>CCheckListBox::OnGetCheckPosition  
 O framework chama esta função para obter a posição e o tamanho da caixa de seleção em um item.  
  
```  
virtual CRect OnGetCheckPosition(
    CRect rectItem,  
    CRect rectCheckBox);
```  
  
### <a name="parameters"></a>Parâmetros  
 *rectItem*  
 A posição e o tamanho do item da lista.  
  
 `rectCheckBox`  
 A posição padrão e o tamanho de um item de caixa de seleção.  
  
### <a name="return-value"></a>Valor de retorno  
 A posição e tamanho de um item de caixa de seleção.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão retorna apenas a posição padrão e o tamanho da caixa de seleção ( `rectCheckBox`). Por padrão, uma caixa de seleção é alinhada no canto superior esquerdo de um item e o tamanho da caixa de seleção padrão. Pode haver casos em que as caixas de seleção à direita ou uma caixa de seleção maior ou menor. Nesses casos, substituir `OnGetCheckPosition` para alterar a posição da caixa de seleção e o tamanho dentro do item.  
  
##  <a name="setcheck"></a>CCheckListBox::SetCheck  
 Define o estado da caixa de seleção especificado.  
  
```  
void SetCheck(
    int nIndex,  
    int nCheck);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 Índice de base zero de uma caixa de seleção está contida na caixa de listagem.  
  
 `nCheck`  
 O estado do botão para a caixa de seleção. Consulte a seção comentários para os valores possíveis.  
  
### <a name="remarks"></a>Comentários  
 A tabela a seguir lista os possíveis valores para o `nCheck` parâmetro.  
  
|Valor|Descrição|  
|-----------|-----------------|  
|**BST_CHECKED**|Selecione a caixa de seleção.|  
|**BST_UNCHECKED**|Desmarque a caixa de seleção.|  
|**BST_INDETERMINATE**|Defina o estado da caixa de seleção especificada para indeterminado.<br /><br /> Esse estado só estará disponível se o estilo de caixa de seleção é `BS_AUTO3STATE` ou `BS_3STATE`. Para obter mais informações, consulte [estilos de botão](../../mfc/reference/styles-used-by-mfc.md#button-styles).|  
  
##  <a name="setcheckstyle"></a>CCheckListBox::SetCheckStyle  
 Chame essa função para definir o estilo das caixas de seleção na caixa de lista de verificação.  
  
```  
void SetCheckStyle(UINT nStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nStyle`  
 Determina o estilo das caixas de seleção na caixa de lista de verificação.  
  
### <a name="remarks"></a>Comentários  
 Estilos válidos são:  
  
- **BS_CHECKBOX**  
  
- **BS_AUTOCHECKBOX**  
  
- **BS_AUTO3STATE**  
  
- **BS_3STATE**  
  
 Para obter informações sobre esses estilos, consulte [estilos de botão](../../mfc/reference/styles-used-by-mfc.md#button-styles).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC TSTCON](../../visual-cpp-samples.md)   
 [Classe CListBox](../../mfc/reference/clistbox-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CListBox](../../mfc/reference/clistbox-class.md)
