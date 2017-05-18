---
title: Classe CHeaderCtrl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CHeaderCtrl
- AFXCMN/CHeaderCtrl
- AFXCMN/CHeaderCtrl::CHeaderCtrl
- AFXCMN/CHeaderCtrl::ClearAllFilters
- AFXCMN/CHeaderCtrl::ClearFilter
- AFXCMN/CHeaderCtrl::Create
- AFXCMN/CHeaderCtrl::CreateDragImage
- AFXCMN/CHeaderCtrl::CreateEx
- AFXCMN/CHeaderCtrl::DeleteItem
- AFXCMN/CHeaderCtrl::DrawItem
- AFXCMN/CHeaderCtrl::EditFilter
- AFXCMN/CHeaderCtrl::GetBitmapMargin
- AFXCMN/CHeaderCtrl::GetFocusedItem
- AFXCMN/CHeaderCtrl::GetImageList
- AFXCMN/CHeaderCtrl::GetItem
- AFXCMN/CHeaderCtrl::GetItemCount
- AFXCMN/CHeaderCtrl::GetItemDropDownRect
- AFXCMN/CHeaderCtrl::GetItemRect
- AFXCMN/CHeaderCtrl::GetOrderArray
- AFXCMN/CHeaderCtrl::GetOverflowRect
- AFXCMN/CHeaderCtrl::HitTest
- AFXCMN/CHeaderCtrl::InsertItem
- AFXCMN/CHeaderCtrl::Layout
- AFXCMN/CHeaderCtrl::OrderToIndex
- AFXCMN/CHeaderCtrl::SetBitmapMargin
- AFXCMN/CHeaderCtrl::SetFilterChangeTimeout
- AFXCMN/CHeaderCtrl::SetFocusedItem
- AFXCMN/CHeaderCtrl::SetHotDivider
- AFXCMN/CHeaderCtrl::SetImageList
- AFXCMN/CHeaderCtrl::SetItem
- AFXCMN/CHeaderCtrl::SetOrderArray
dev_langs:
- C++
helpviewer_keywords:
- CHeaderCtrl class
- Windows common controls [C++], CHeaderCtrl
- header controls, CHeaderCtrl class
ms.assetid: b847ac90-5fae-4a87-88e0-ca45f77b8b3b
caps.latest.revision: 24
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
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: faa23ea6f28c2643c9bee090ea150e37d0add97c
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="cheaderctrl-class"></a>Classe CHeaderCtrl
Fornece a funcionalidade de controle de cabeçalho comuns do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CHeaderCtrl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHeaderCtrl::CHeaderCtrl](#cheaderctrl)|Constrói um objeto `CHeaderCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHeaderCtrl::ClearAllFilters](#clearallfilters)|Limpa todos os filtros para um controle de cabeçalho.|  
|[CHeaderCtrl::ClearFilter](#clearfilter)|Limpa o filtro para um controle de cabeçalho.|  
|[CHeaderCtrl::Create](#create)|Cria um controle de cabeçalho e a anexa a um `CHeaderCtrl` objeto.|  
|[CHeaderCtrl::CreateDragImage](#createdragimage)|Cria uma versão transparente da imagem de um item dentro de um controle de cabeçalho.|  
|[CHeaderCtrl::CreateEx](#createex)|Cria um controle de cabeçalho com os estilos estendidos do Windows especificados e a anexa a um `CListCtrl` objeto.|  
|[CHeaderCtrl::DeleteItem](#deleteitem)|Exclui um item de um controle de cabeçalho.|  
|[CHeaderCtrl::DrawItem](#drawitem)|Desenha o item especificado de um controle de cabeçalho.|  
|[CHeaderCtrl::EditFilter](#editfilter)|Começa a editar o filtro especificado de um controle de cabeçalho.|  
|[CHeaderCtrl::GetBitmapMargin](#getbitmapmargin)|Recupera a largura da margem de um bitmap em um controle de cabeçalho.|  
|[CHeaderCtrl::GetFocusedItem](#getfocuseditem)|Obtém o identificador do item no controle de cabeçalho atual que tem o foco.|  
|[CHeaderCtrl::GetImageList](#getimagelist)|Recupera o identificador de uma lista de imagens usada para desenho itens de cabeçalho em um controle de cabeçalho.|  
|[CHeaderCtrl::GetItem](#getitem)|Recupera informações sobre um item em um controle de cabeçalho.|  
|[CHeaderCtrl::GetItemCount](#getitemcount)|Recupera uma contagem dos itens em um controle de cabeçalho.|  
|[CHeaderCtrl::GetItemDropDownRect](#getitemdropdownrect)|Obtém as informações de retângulo delimitador para o botão suspenso especificado em um controle de cabeçalho.|  
|[CHeaderCtrl::GetItemRect](#getitemrect)|Recupera o retângulo delimitador para um determinado item em um controle de cabeçalho.|  
|[CHeaderCtrl::GetOrderArray](#getorderarray)|Recupera a ordem da esquerda para a direita de itens em um controle de cabeçalho.|  
|[CHeaderCtrl::GetOverflowRect](#getoverflowrect)|Obtém o retângulo delimitador de botão de estouro do controle de cabeçalho atual.|  
|[CHeaderCtrl::HitTest](#hittest)|Determina qual item de cabeçalho, se houver, está localizado em um momento específico.|  
|[CHeaderCtrl::InsertItem](#insertitem)|Insere um novo item em um controle de cabeçalho.|  
|[CHeaderCtrl::Layout](#layout)|Recupera o tamanho e a posição de um controle de cabeçalho dentro de um retângulo determinado.|  
|[CHeaderCtrl::OrderToIndex](#ordertoindex)|Recupera o valor de índice de um item com base em sua ordem no controle de cabeçalho.|  
|[CHeaderCtrl::SetBitmapMargin](#setbitmapmargin)|Define a largura da margem de um bitmap em um controle de cabeçalho.|  
|[CHeaderCtrl::SetFilterChangeTimeout](#setfilterchangetimeout)|Define o intervalo de tempo limite entre a hora em que uma alteração é feita em atributos de filtro e o lançamento de um `HDN_FILTERCHANGE` notificação.|  
|[CHeaderCtrl::SetFocusedItem](#setfocuseditem)|Define o foco para um item de cabeçalho especificado no controle de cabeçalho atual.|  
|[CHeaderCtrl::SetHotDivider](#sethotdivider)|Alterações no divisor entre itens de cabeçalho para indicar um manual de arrastar e soltar de um item de cabeçalho.|  
|[CHeaderCtrl::SetImageList](#setimagelist)|Atribui uma lista de imagens a um controle de cabeçalho.|  
|[CHeaderCtrl::SetItem](#setitem)|Define os atributos do item especificado em um controle de cabeçalho.|  
|[CHeaderCtrl::SetOrderArray](#setorderarray)|Define a ordem da esquerda para a direita dos itens em um controle de cabeçalho.|  
  
## <a name="remarks"></a>Comentários  
 Um controle de cabeçalho é uma janela que geralmente é posicionada acima de um conjunto de colunas de texto ou números. Ele contém um título para cada coluna, e ele pode ser dividido em partes. O usuário pode arrastar os divisores que separam as partes para definir a largura de cada coluna. Para obter uma ilustração de um controle de cabeçalho, consulte [controles de cabeçalho](http://msdn.microsoft.com/library/windows/desktop/bb775238).  
  
 Esse controle (e, portanto, o `CHeaderCtrl` classe) está disponível apenas para programas que são executados na versão do Windows 95/98 e Windows NT 3.51 e posterior.  
  
 Funcionalidade adicionada para controles comuns do Windows 95/Internet Explorer 4.0 inclui o seguinte:  
  
-   Cabeçalho personalizado ordenação de itens.  
  
-   Item de cabeçalho arrastar e soltar, de reordenação de itens de cabeçalho. Use o `HDS_DRAGDROP` estilo quando você cria o `CHeaderCtrl` objeto.  
  
-   Texto do cabeçalho coluna constantemente visível durante o redimensionamento de coluna. Use o `HDS_FULLDRAG` estilo quando você cria um `CHeaderCtrl` objeto.  
  
-   Cabeçalho rastreio importante, que destaca o item de cabeçalho quando o ponteiro passa sobre ele. Use o `HDS_HOTTRACK` estilo quando você cria o `CHeaderCtrl` objeto.  
  
-   Suporte à lista de imagem. Itens de cabeçalho podem conter imagens armazenadas em uma `CImageList` objeto ou texto.  
  
 Para obter mais informações sobre como usar `CHeaderCtrl`, consulte [controles](../../mfc/controls-mfc.md) e [usando CHeaderCtrl](../../mfc/using-cheaderctrl.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CHeaderCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn.h  
  
##  <a name="cheaderctrl"></a>CHeaderCtrl::CHeaderCtrl  
 Constrói um objeto `CHeaderCtrl`.  
  
```  
CHeaderCtrl();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CHeaderCtrl n º 1](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_1.cpp)]  
  
##  <a name="clearallfilters"></a>CHeaderCtrl::ClearAllFilters  
 Limpa todos os filtros para um controle de cabeçalho.  
  
```  
BOOL ClearAllFilters();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método implementa o comportamento da mensagem de Win32 [HDM_CLEARFILTER](http://msdn.microsoft.com/library/windows/desktop/bb775306) com um valor de coluna de -1, conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CHeaderCtrl n º 2](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_2.cpp)]  
  
##  <a name="clearfilter"></a>CHeaderCtrl::ClearFilter  
 Limpa o filtro para um controle de cabeçalho.  
  
```  
BOOL ClearFilter(int nColumn);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nColumn`  
 Valor de coluna que indica quais filtrar para limpar.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método implementa o comportamento da mensagem de Win32 [HDM_CLEARFILTER](http://msdn.microsoft.com/library/windows/desktop/bb775306), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CHeaderCtrl n º 3](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_3.cpp)]  
  
##  <a name="create"></a>CHeaderCtrl::Create  
 Cria um controle de cabeçalho e a anexa a um `CHeaderCtrl` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Especifica o estilo do controle de cabeçalho. Para obter uma descrição dos estilos de controle de cabeçalho, consulte [estilos de controle de cabeçalho](http://msdn.microsoft.com/library/windows/desktop/bb775241) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `rect`  
 Especifica o tamanho e a posição do controle de cabeçalho. Ele pode ser um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura.  
  
 `pParentWnd`  
 Especifica a janela do pai do controle de cabeçalho, geralmente um `CDialog`. Ele não deve ser **nulo**.  
  
 `nID`  
 Especifica a ID. do controle de cabeçalho  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a inicialização foi bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Você pode criar um `CHeaderCtrl` objeto em duas etapas. Primeiro, chame o construtor e, em seguida, chamar **criar**, que cria o controle de cabeçalho e anexa-o para o `CHeaderCtrl` objeto.  
  
 Além dos estilos de controle de cabeçalho, você pode usar os seguintes estilos de controle comum para determinar como o controle de cabeçalho posiciona e redimensionado (consulte [estilos de controle comuns](http://msdn.microsoft.com/library/windows/desktop/bb775498) para obter mais informações):  
  
- `CCS_BOTTOM`Faz com que o controle se posicionar na parte inferior da área cliente da janela pai e define a largura para ser o mesmo que o pai largura da janela.  
  
- `CCS_NODIVIDER`Impede que um realce dois pixels desenhada na parte superior do controle.  
  
- `CCS_NOMOVEY`Faz com que o controle redimensione e mova-se horizontalmente, mas não verticalmente, em resposta a um `WM_SIZE` mensagem. Se o `CCS_NORESIZE` estilo for usado, não se aplicam a esse estilo. Por padrão, os controles de cabeçalho têm esse estilo.  
  
- `CCS_NOPARENTALIGN`Impede que o controle mover automaticamente na parte superior ou inferior da janela pai. Em vez disso, o controle mantém sua posição dentro da janela pai, apesar as alterações para o tamanho da janela pai. Se o `CCS_TOP` ou `CCS_BOTTOM` estilo também é usado, a altura é ajustada para o padrão, mas a posição e a largura permanecem inalteradas.  
  
- `CCS_NORESIZE`Impede que o controle usando a largura e altura padrão ao definir seu tamanho inicial ou um novo tamanho. Em vez disso, o controle usa a largura e altura especificada na solicitação de criação ou dimensionamento.  
  
- `CCS_TOP`Faz com que o controle se posicionar na parte superior da área cliente da janela pai e define a largura para ser o mesmo que o pai largura da janela.  
  
 Você também pode aplicar os seguintes estilos de janela para um controle de cabeçalho (consulte [estilos de janela](../../mfc/reference/window-styles.md) para obter mais informações):  
  
- **Estilo** cria uma janela filho. Não pode ser usado com o `WS_POPUP` estilo.  
  
- **WS_VISIBLE** cria uma janela que é visível inicialmente.  
  
- **WS_DISABLED** cria uma janela que é inicialmente desabilitada.  
  
- **WS_GROUP** Especifica o primeiro controle de um grupo de controles em que o usuário pode mover de um controle para o seguinte com as teclas de direção. Todos os controles definidos com o **WS_GROUP** após o primeiro controle pertencem ao mesmo grupo de estilo. O próximo controle com o **WS_GROUP** estilo encerra o grupo de estilo e inicia o próximo grupo (ou seja, termina um grupo onde começa o próximo).  
  
- **WS_TABSTOP** Especifica um número de controles por meio do qual o usuário pode mover usando a tecla TAB. A tecla TAB move o usuário para o próximo controle especificado pelo **WS_TABSTOP** estilo.  
  
 Se desejar usar estilos de windows estendida com o controle, chame [CreateEx](#createex) em vez de **criar**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CHeaderCtrl n º 4](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_4.cpp)]  
  
##  <a name="createex"></a>CHeaderCtrl::CreateEx  
 Cria um controle (uma janela filho) e associá-lo com o `CHeaderCtrl` objeto.  
  
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
 Estilo do controle de cabeçalho. Para obter uma descrição dos estilos de controle de cabeçalho, consulte [estilos de controle de cabeçalho](http://msdn.microsoft.com/library/windows/desktop/bb775241) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Consulte [criar](#create) para obter uma lista de estilos adicionais.  
  
 `rect`  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que descreve o tamanho e a posição da janela deve ser criada, nas coordenadas do cliente de `pParentWnd`.  
  
 `pParentWnd`  
 Um ponteiro para a janela que é o pai do controle.  
  
 `nID`  
 ID de janela filho. do controle  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use `CreateEx` em vez de **criar** para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.  
  
##  <a name="createdragimage"></a>CHeaderCtrl::CreateDragImage  
 Cria uma versão transparente da imagem de um item dentro de um controle de cabeçalho.  
  
```  
CImageList* CreateDragImage(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice de base zero do item dentro do controle de cabeçalho. A imagem atribuída a este item é a base para a imagem transparente.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto se for bem-sucedida; caso contrário **nulo**. A lista retornada conterá apenas uma imagem.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [HDM_CREATEDRAGIMAGE](http://msdn.microsoft.com/library/windows/desktop/bb775308), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Ele é fornecido para dar suporte ao cabeçalho item arrastar e soltar.  
  
 O `CImageList` objeto ao qual os pontos de ponteiro retornado é um objeto temporário e será excluído no próximo processamento de tempo ocioso.  
  
##  <a name="deleteitem"></a>CHeaderCtrl::DeleteItem  
 Exclui um item de um controle de cabeçalho.  
  
```  
BOOL DeleteItem(int nPos);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPos`  
 Especifica o índice com base em zero do item a ser excluído.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CHeaderCtrl n º 5](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_5.cpp)]  
  
##  <a name="drawitem"></a>CHeaderCtrl::DrawItem  
 Chamado pelo framework quando um aspecto visual das alterações de controle de cabeçalho desenho proprietário.  
  
```  
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpDrawItemStruct`  
 Um ponteiro para um [DRAWITEMSTRUCT](http://msdn.microsoft.com/library/windows/desktop/bb775802) estrutura que descreve o item a ser pintado.  
  
### <a name="remarks"></a>Comentários  
 O **itemAction** membro o `DRAWITEMSTRUCT` estrutura define a ação de desenho que deve ser executada.  
  
 Por padrão, essa função de membro não faz nada. Substituir essa função de membro para implementar o desenho de um desenho proprietário `CHeaderCtrl` objeto.  
  
 O aplicativo deve restaurar todos os objetos de interface (GDI) do dispositivo gráficos selecionados para o contexto de exibição fornecido no `lpDrawItemStruct` antes desse membro função termina.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CHeaderCtrl 6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_6.cpp)]  
  
##  <a name="editfilter"></a>CHeaderCtrl::EditFilter  
 Começa a editar o filtro especificado de um controle de cabeçalho.  
  
```  
BOOL EditFilter(
    int nColumn,  
    BOOL bDiscardChanges);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nColumn`  
 A coluna para editar.  
  
 `bDiscardChanges`  
 Um valor que especifica como tratar o usuário de edição do alterações se o usuário estiver editando o filtro quando o [HDM_EDITFILTER](http://msdn.microsoft.com/library/windows/desktop/bb775312) mensagem é enviada.  
  
 Especifique `true` para descartar as alterações feitas pelo usuário, ou `false` para aceitar as alterações feitas pelo usuário.  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método implementa o comportamento da mensagem de Win32 [HDM_EDITFILTER](http://msdn.microsoft.com/library/windows/desktop/bb775312), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CHeaderCtrl #7](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_7.cpp)]  
  
##  <a name="getbitmapmargin"></a>CHeaderCtrl::GetBitmapMargin  
 Recupera a largura da margem de um bitmap em um controle de cabeçalho.  
  
```  
int GetBitmapMargin() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A largura da margem de bitmap em pixels.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [HDM_GETBITMAPMARGIN](http://msdn.microsoft.com/library/windows/desktop/bb775314), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CHeaderCtrl n º 8](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_8.cpp)]  
  
##  <a name="getfocuseditem"></a>CHeaderCtrl::GetFocusedItem  
 Obtém o índice do item que tem o foco no controle de cabeçalho atual.  
  
```  
int GetFocusedItem() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de base zero do item de cabeçalho que tem o foco.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [HDM_GETFOCUSEDITEM](http://msdn.microsoft.com/library/windows/desktop/bb775330) mensagem, que é descrita a [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_headerCtrl`, que é usado para acessar o controle de cabeçalho atual. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CHeaderCtrl_s4 6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_9.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir demonstra o `SetFocusedItem` e `GetFocusedItem` métodos. Em uma seção anterior do código, criamos um controle de cabeçalho com cinco colunas. No entanto, você pode arrastar um separador de coluna para que a coluna não é visível. O exemplo a seguir define e, em seguida, confirma o último cabeçalho de coluna como o item de foco.  
  
 [!code-cpp[NVC_MFC_CHeaderCtrl_s4 n º 4](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_10.cpp)]  
  
##  <a name="getimagelist"></a>CHeaderCtrl::GetImageList  
 Recupera o identificador de uma lista de imagens usada para desenho itens de cabeçalho em um controle de cabeçalho.  
  
```  
CImageList* GetImageList() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [HDM_GETIMAGELIST](http://msdn.microsoft.com/library/windows/desktop/bb775332), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. O `CImageList` objeto ao qual os pontos de ponteiro retornado é um objeto temporário e será excluído no próximo processamento de tempo ocioso.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CHeaderCtrl n º 9](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_11.cpp)]  
  
##  <a name="getitem"></a>CHeaderCtrl::GetItem  
 Recupera informações sobre um item de controle de cabeçalho.  
  
```  
BOOL GetItem(
    int nPos,  
    HDITEM* pHeaderItem) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPos`  
 Especifica o índice de base zero do item para recuperar.  
  
 `pHeaderItem`  
 Ponteiro para um [HDITEM](http://msdn.microsoft.com/library/windows/desktop/bb775247) estrutura que recebe o novo item. Essa estrutura é usada com o `InsertItem` e `SetItem` funções de membro. Definir os sinalizadores no **máscara** elemento Certifique-se de que os valores nos elementos correspondentes corretamente são preenchidos após retornar. Se o **máscara** é definido como zero, os valores nos elementos de estrutura são sem sentido.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CHeaderCtrl #10](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_12.cpp)]  
  
##  <a name="getitemcount"></a>CHeaderCtrl::GetItemCount  
 Recupera uma contagem dos itens em um controle de cabeçalho.  
  
```  
int GetItemCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Número de itens de controle de cabeçalho se bem-sucedido; Caso contrário, - 1.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CHeaderCtrl::DeleteItem](#deleteitem).  
  
##  <a name="getitemdropdownrect"></a>CHeaderCtrl::GetItemDropDownRect  
 Obtém o retângulo delimitador do botão suspenso para um item de cabeçalho no controle de cabeçalho atual.  
  
```  
BOOL GetItemDropDownRect(
    int iItem,   
    LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `iItem`|Índice de base zero de um item de cabeçalho cujo estilo é `HDF_SPLITBUTTON`. Para obter mais informações, consulte o `fmt` membro o [HDITEM](http://msdn.microsoft.com/library/windows/desktop/bb775247) estrutura.|  
|[out] `lpRect`|Ponteiro para um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura para receber as informações de retângulo delimitador.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se essa função for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [HDM_GETITEMDROPDOWNRECT](http://msdn.microsoft.com/library/windows/desktop/bb775339) mensagem, que é descrita a [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_headerCtrl`, que é usado para acessar o controle de cabeçalho atual. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CHeaderCtrl_s4 6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_9.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir demonstra o `GetItemDropDownRect` método. Em uma seção anterior do código, criamos um controle de cabeçalho com cinco colunas. O exemplo de código a seguir desenha um retângulo 3D em todo o local na primeira coluna que é reservada para o botão suspenso de cabeçalho.  
  
 [!code-cpp[NVC_MFC_CHeaderCtrl_s4 n º 2](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_13.cpp)]  
  
##  <a name="getitemrect"></a>CHeaderCtrl::GetItemRect  
 Recupera o retângulo delimitador para um determinado item em um controle de cabeçalho.  
  
```  
BOOL GetItemRect(
    int nIndex,  
    LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIndex`  
 O índice de base zero do item de controle de cabeçalho.  
  
 `lpRect`  
 Um ponteiro para o endereço de um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que recebe as informações de retângulo delimitador.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método implementa o comportamento da mensagem de Win32 [HDM_GETITEMRECT](http://msdn.microsoft.com/library/windows/desktop/bb775341), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getorderarray"></a>CHeaderCtrl::GetOrderArray  
 Recupera a ordem da esquerda para a direita de itens em um controle de cabeçalho.  
  
```  
BOOL GetOrderArray(
    LPINT piArray,  
    int iCount);
```  
  
### <a name="parameters"></a>Parâmetros  
 `piArray`  
 Um ponteiro para o endereço de um buffer que recebe os valores de índice dos itens no controle de cabeçalho, na ordem em que aparecem da esquerda para a direita.  
  
 `iCount`  
 O número de itens de controle de cabeçalho. Deve ser não negativo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [HDM_GETORDERARRAY](http://msdn.microsoft.com/library/windows/desktop/bb775343), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Ele é fornecido para oferecer suporte a ordenação de item de cabeçalho.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CHeaderCtrl n º 11](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_14.cpp)]  
  
##  <a name="getoverflowrect"></a>CHeaderCtrl::GetOverflowRect  
 Obtém o retângulo delimitador de botão de estouro do controle de cabeçalho atual.  
  
```  
BOOL GetOverflowRect(LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[out] `lpRect`|Ponteiro para um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que recebe as informações de retângulo delimitador.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se essa função for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Se o controle de cabeçalho contém mais itens do que podem ser exibidas ao mesmo tempo, o controle pode exibir um botão de estouro rola para itens que não estão visíveis. O controle de cabeçalho deve ter o `HDS_OVERFLOW` e `HDF_SPLITBUTTON` estilos para exibir o botão de estouro. O retângulo delimitador inclui um botão de estouro e existe somente quando o botão de estouro é exibido. Para obter mais informações, consulte [estilos de controle de cabeçalho](http://msdn.microsoft.com/library/windows/desktop/bb775241).  
  
 Esse método envia o [HDM_GETOVERFLOWRECT](http://msdn.microsoft.com/library/windows/desktop/bb775345) mensagem, que é descrita a [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_headerCtrl`, que é usado para acessar o controle de cabeçalho atual. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CHeaderCtrl_s4 6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_9.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir demonstra o `GetOverflowRect` método. Em uma seção anterior do código, criamos um controle de cabeçalho com cinco colunas. No entanto, você pode arrastar um separador de coluna para que a coluna não é visível. Se algumas colunas não estiverem visíveis, o controle de cabeçalho desenha um botão de estouro. O exemplo de código a seguir desenha um retângulo 3D alternativa para o local do botão de estouro.  
  
 [!code-cpp[NVC_MFC_CHeaderCtrl_s4 n º 3](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_15.cpp)]  
  
##  <a name="hittest"></a>CHeaderCtrl::HitTest  
 Determina qual item de cabeçalho, se houver, está localizado em um momento específico.  
  
```  
int HitTest(LPHDHITTESTINFO* phdhti);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in, out] `phdhti`|Ponteiro para um [HDHITTESTINFO](http://msdn.microsoft.com/library/windows/desktop/bb775245) estrutura que especifica o ponto de teste e recebe os resultados do teste.|  
  
### <a name="return-value"></a>Valor de retorno  
 O índice com base em zero do item de cabeçalho, se houver, na posição especificada; Caso contrário, retornará -1.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [HDM_HITTEST](http://msdn.microsoft.com/library/windows/desktop/bb775349) mensagem, que é descrita a [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_headerCtrl`, que é usado para acessar o controle de cabeçalho atual. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CHeaderCtrl_s4 6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_9.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir demonstra o `HitTest` método. Em uma seção anterior deste exemplo de código, criamos um controle de cabeçalho com cinco colunas. No entanto, você pode arrastar um separador de coluna para que a coluna não é visível. Este exemplo informa o índice da coluna se ela estiver visível e -1 se a coluna não estiver visível.  
  
 [!code-cpp[NVC_MFC_CHeaderCtrl_s4 n º 1](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_16.cpp)]  
  
##  <a name="insertitem"></a>CHeaderCtrl::InsertItem  
 Insere um novo item em um controle de cabeçalho no índice especificado.  
  
```  
int InsertItem(
    int nPos,  
    HDITEM* phdi);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPos`  
 O índice de base zero do item a ser inserido. Se o valor for zero, o item é inserido no início do controle de cabeçalho. Se o valor for maior que o valor máximo, o item é inserido no final do controle de cabeçalho.  
  
 *phdi*  
 Ponteiro para um [HDITEM](http://msdn.microsoft.com/library/windows/desktop/bb775247) estrutura que contém informações sobre o item a ser inserido.  
  
### <a name="return-value"></a>Valor de retorno  
 Índice do novo item, se for bem-sucedido; Caso contrário, - 1.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CHeaderCtrl #12](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_17.cpp)]  
  
##  <a name="layout"></a>CHeaderCtrl::Layout  
 Recupera o tamanho e a posição de um controle de cabeçalho dentro de um retângulo determinado.  
  
```  
BOOL Layout(HDLAYOUT* pHeaderLayout);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pHeaderLayout*  
 Ponteiro para um [HDLAYOUT](http://msdn.microsoft.com/library/windows/desktop/bb775249) estrutura, que contém informações usadas para definir o tamanho e posição de um controle de cabeçalho.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função é usada para determinar as dimensões apropriadas para um novo controle de cabeçalho que ocupam o retângulo especificado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CHeaderCtrl 13](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_18.cpp)]  
  
##  <a name="ordertoindex"></a>CHeaderCtrl::OrderToIndex  
 Recupera o valor de índice de um item com base em sua ordem no controle de cabeçalho.  
  
```  
int OrderToIndex(int nOrder) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *nOrder*  
 A ordem de base zero que o item é exibido no controle de cabeçalho, da esquerda para a direita.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do item, com base em sua ordem no controle de cabeçalho. O índice de conta da esquerda para a direita, começando com 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da macro do Win32 [HDM_ORDERTOINDEX](http://msdn.microsoft.com/library/windows/desktop/bb775355), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Ele é fornecido para oferecer suporte a ordenação de item de cabeçalho.  
  
##  <a name="setbitmapmargin"></a>CHeaderCtrl::SetBitmapMargin  
 Define a largura da margem de um bitmap em um controle de cabeçalho.  
  
```  
int SetBitmapMargin(int nWidth);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nWidth`  
 Largura, especificada em pixels, da margem ao redor de um bitmap dentro de um controle de cabeçalho existente.  
  
### <a name="return-value"></a>Valor de retorno  
 A largura da margem de bitmap em pixels.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [HDM_SETBITMAPMARGIN](http://msdn.microsoft.com/library/windows/desktop/bb775357), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CHeaderCtrl #14](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_19.cpp)]  
  
##  <a name="setfilterchangetimeout"></a>CHeaderCtrl::SetFilterChangeTimeout  
 Define o intervalo de tempo limite entre a hora em que uma alteração é feita em atributos de filtro e o lançamento de um [HDN_FILTERCHANGE](http://msdn.microsoft.com/library/windows/desktop/bb775277) notificação.  
  
```  
int SetFilterChangeTimeout(DWORD dwTimeOut);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwTimeOut*  
 Valor de tempo limite, em milissegundos.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice do controle de filtro que está sendo modificado.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [HDM_SETFILTERCHANGETIMEOUT](http://msdn.microsoft.com/library/windows/desktop/bb775359), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CHeaderCtrl #15](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_20.cpp)]  
  
##  <a name="setfocuseditem"></a>CHeaderCtrl::SetFocusedItem  
 Define o foco para um item de cabeçalho especificado no controle de cabeçalho atual.  
  
```  
BOOL SetFocusedItem(int iItem);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `iItem`|Índice de base zero de um item de cabeçalho.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [HDM_SETFOCUSEDITEM](http://msdn.microsoft.com/library/windows/desktop/bb775361) mensagem, que é descrita a [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_headerCtrl`, que é usado para acessar o controle de cabeçalho atual. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CHeaderCtrl_s4 6](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_9.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir demonstra o `SetFocusedItem` e `GetFocusedItem` métodos. Em uma seção anterior do código, criamos um controle de cabeçalho com cinco colunas. No entanto, você pode arrastar um separador de coluna para que a coluna não é visível. O exemplo a seguir define e, em seguida, confirma o último cabeçalho de coluna como o item de foco.  
  
 [!code-cpp[NVC_MFC_CHeaderCtrl_s4 n º 4](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_10.cpp)]  
  
##  <a name="sethotdivider"></a>CHeaderCtrl::SetHotDivider  
 Alterações no divisor entre itens de cabeçalho para indicar um manual de arrastar e soltar de um item de cabeçalho.  
  
```  
int SetHotDivider(CPoint pt);  
int SetHotDivider(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pt`  
 A posição do ponteiro. O controle de cabeçalho realça o divisor apropriado com base na posição do ponteiro.  
  
 `nIndex`  
 O índice da divisória realçado.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice da divisória realçado.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [HDM_SETHOTDIVIDER](http://msdn.microsoft.com/library/windows/desktop/bb775363), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Ele é fornecido para dar suporte ao cabeçalho item arrastar e soltar.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CHeaderCtrl n º 16](../../mfc/reference/codesnippet/cpp/cheaderctrl-class_21.cpp)]  
  
##  <a name="setimagelist"></a>CHeaderCtrl::SetImageList  
 Atribui uma lista de imagens a um controle de cabeçalho.  
  
```  
CImageList* SetImageList(CImageList* pImageList);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pImageList`  
 Um ponteiro para um `CImageList` objeto que contém a lista de imagens a ser atribuído ao controle de cabeçalho.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o [CImageList](../../mfc/reference/cimagelist-class.md) anteriormente atribuído ao controle de cabeçalho do objeto.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [HDM_SETIMAGELIST](http://msdn.microsoft.com/library/windows/desktop/bb775365), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. O `CImageList` objeto ao qual os pontos de ponteiro retornado é um objeto temporário e será excluído no próximo processamento de tempo ocioso.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CHeaderCtrl::GetImageList](#getimagelist).  
  
##  <a name="setitem"></a>CHeaderCtrl::SetItem  
 Define os atributos do item especificado em um controle de cabeçalho.  
  
```  
BOOL SetItem(
    int nPos,  
    HDITEM* pHeaderItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPos`  
 O índice de base zero do item a ser manipulada.  
  
 `pHeaderItem`  
 Ponteiro para um [HDITEM](http://msdn.microsoft.com/library/windows/desktop/bb775247) estrutura que contém informações sobre o novo item.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CHeaderCtrl::GetItem](#getitem).  
  
##  <a name="setorderarray"></a>CHeaderCtrl::SetOrderArray  
 Define a ordem da esquerda para a direita dos itens em um controle de cabeçalho.  
  
```  
BOOL SetOrderArray(
    int iCount,  
    LPINT piArray);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iCount`  
 O número de itens de controle de cabeçalho.  
  
 `piArray`  
 Um ponteiro para o endereço de um buffer que recebe os valores de índice dos itens no controle de cabeçalho, na ordem em que aparecem da esquerda para a direita.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da macro do Win32 [HDM_SETORDERARRAY](http://msdn.microsoft.com/library/windows/desktop/bb775369), conforme descrito no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Ele é fornecido para oferecer suporte a ordenação de item de cabeçalho.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CHeaderCtrl::GetOrderArray](#getorderarray).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CTabCtrl](../../mfc/reference/ctabctrl-class.md)   
 [Classe CListCtrl](../../mfc/reference/clistctrl-class.md)   
 [Classe CImageList](../../mfc/reference/cimagelist-class.md)

