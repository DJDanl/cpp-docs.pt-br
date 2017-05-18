---
title: Classe CPagerCtrl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CPagerCtrl
- AFXCMN/CPagerCtrl
- AFXCMN/CPagerCtrl::CPagerCtrl
- AFXCMN/CPagerCtrl::Create
- AFXCMN/CPagerCtrl::CreateEx
- AFXCMN/CPagerCtrl::ForwardMouse
- AFXCMN/CPagerCtrl::GetBkColor
- AFXCMN/CPagerCtrl::GetBorder
- AFXCMN/CPagerCtrl::GetButtonSize
- AFXCMN/CPagerCtrl::GetButtonState
- AFXCMN/CPagerCtrl::GetDropTarget
- AFXCMN/CPagerCtrl::GetScrollPos
- AFXCMN/CPagerCtrl::IsButtonDepressed
- AFXCMN/CPagerCtrl::IsButtonGrayed
- AFXCMN/CPagerCtrl::IsButtonHot
- AFXCMN/CPagerCtrl::IsButtonInvisible
- AFXCMN/CPagerCtrl::IsButtonNormal
- AFXCMN/CPagerCtrl::RecalcSize
- AFXCMN/CPagerCtrl::SetBkColor
- AFXCMN/CPagerCtrl::SetBorder
- AFXCMN/CPagerCtrl::SetButtonSize
- AFXCMN/CPagerCtrl::SetChild
- AFXCMN/CPagerCtrl::SetScrollPos
dev_langs:
- C++
helpviewer_keywords:
- CPagerCtrl class
ms.assetid: 65ac58dd-4f5e-4b7e-b15c-e0d435a7e884
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 8b8bf05873239f274a9b1285797c01123fe071f7
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cpagerctrl-class"></a>Classe CPagerCtrl
O `CPagerCtrl` classe envolve o controle de pager do Windows, que pode rolar e exibir uma janela independente que não se ajustar a janela.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CPagerCtrl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPagerCtrl::CPagerCtrl](#cpagerctrl)|Constrói um objeto `CPagerCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPagerCtrl::Create](#create)|Cria um controle de paginação com estilos especificados e o anexa à atual `CPagerCtrl` objeto.|  
|[CPagerCtrl::CreateEx](#createex)|Cria um controle de paginação com estilos estendidos especificados e o anexa à atual `CPagerCtrl` objeto.|  
|[CPagerCtrl::ForwardMouse](#forwardmouse)|Habilita ou desabilita encaminhamento [WM_MOUSEMOVE](http://msdn.microsoft.com/library/windows/desktop/ms645616) mensagens para a janela que está contido no controle de paginação atual.|  
|[CPagerCtrl::GetBkColor](#getbkcolor)|Recupera a cor de plano de fundo do controle de paginação atual.|  
|[CPagerCtrl::GetBorder](#getborder)|Recupera o tamanho da borda do controle de paginação atual.|  
|[CPagerCtrl::GetButtonSize](#getbuttonsize)|Recupera o tamanho do botão de controle de paginação atual.|  
|[CPagerCtrl::GetButtonState](#getbuttonstate)|Recupera o estado do botão especificado no controle de paginação atual.|  
|[CPagerCtrl::GetDropTarget](#getdroptarget)|Recupera o [IDropTarget](http://msdn.microsoft.com/library/windows/desktop/ms679679) interface para o controle de paginação atual.|  
|[CPagerCtrl::GetScrollPos](#getscrollpos)|Recupera a posição de rolagem de controle de paginação atual.|  
|[CPagerCtrl::IsButtonDepressed](#isbuttondepressed)|Indica se o botão especificado do controle pager atual está em `pressed` estado.|  
|[CPagerCtrl::IsButtonGrayed](#isbuttongrayed)|Indica se o botão especificado do controle pager atual está em `grayed` estado.|  
|[CPagerCtrl::IsButtonHot](#isbuttonhot)|Indica se o botão especificado do controle pager atual está em `hot` estado.|  
|[CPagerCtrl::IsButtonInvisible](#isbuttoninvisible)|Indica se o botão especificado do controle pager atual está em `invisible` estado.|  
|[CPagerCtrl::IsButtonNormal](#isbuttonnormal)|Indica se o botão especificado do controle pager atual está em `normal` estado.|  
|[CPagerCtrl::RecalcSize](#recalcsize)|Faz com que o controle de paginação atual recalcular o tamanho da janela contida.|  
|[CPagerCtrl::SetBkColor](#setbkcolor)|Define a cor de plano de fundo do controle de paginação atual.|  
|[CPagerCtrl::SetBorder](#setborder)|Define o tamanho da borda do controle de paginação atual.|  
|[CPagerCtrl::SetButtonSize](#setbuttonsize)|Define o tamanho do botão de controle de paginação atual.|  
|[CPagerCtrl::SetChild](#setchild)|Define a janela independente para o controle de paginação atual.|  
|[CPagerCtrl::SetScrollPos](#setscrollpos)|Define a posição de rolagem de controle de paginação atual.|  
  
## <a name="remarks"></a>Comentários  
 Um controle de paginação é uma janela que contém outra janela linear e maior do que a janela contém, e permite que você rolar a janela contida na exibição. O controle de paginação exibe dois botões de rolagem que desaparecem automaticamente quando a janela independente é rolada para sua extensão mais distante e reaparecer caso contrário. Você pode criar um controle de paginação que rola horizontalmente ou verticalmente.  
  
 Por exemplo, se seu aplicativo tiver uma barra de ferramentas que não é grande o suficiente para mostrar todos os seus itens, você pode atribuir a barra de ferramentas para um controle de paginação e os usuários poderão rolar barra de ferramentas para a esquerda ou direita para acessar todos os itens. Microsoft Internet Explorer versão 4.0 (versão Commctrl 4.71) introduz o controle de paginação.  
  
 O `CPagerCtrl` classe é derivada do [CWnd](../../mfc/reference/cwnd-class.md) classe. Para obter mais informações e uma ilustração de um controle de paginação, consulte [controles de paginação](http://msdn.microsoft.com/library/windows/desktop/bb760855).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CPagerCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn.h  
  
##  <a name="cpagerctrl"></a>CPagerCtrl::CPagerCtrl  
 Constrói um objeto `CPagerCtrl`.  
  
```  
CPagerCtrl();
```  
  
### <a name="remarks"></a>Comentários  
 Use o [CPagerCtrl::Create](#create) ou [CPagerCtrl::CreateEx](#createex) método para criar um controle de paginação e anexá-lo a `CPagerCtrl` objeto.  
  
##  <a name="create"></a>CPagerCtrl::Create  
 Cria um controle de paginação com estilos especificados e o anexa à atual `CPagerCtrl` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,   
    const RECT& rect,   
    CWnd* pParentWnd,   
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `dwStyle`|Uma combinação bit a bit (OR) de [estilos de janela](../../mfc/reference/window-styles.md) e [estilos de controle pager](http://msdn.microsoft.com/library/windows/desktop/bb760859) a ser aplicado ao controle.|  
|[in] `rect`|Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que contém a posição e o tamanho do controle em coordenadas do cliente.|  
|[in] `pParentWnd`|Um ponteiro para um [CWnd](../../mfc/reference/cwnd-class.md) objeto que é a janela pai do controle. O parâmetro não pode ser `NULL`.|  
|[in] `nID`|A ID do controle.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Para criar um controle de paginação, declare um `CPagerCtrl` variável, em seguida, chame o [CPagerCtrl::Create](#create) ou [CPagerCtrl::CreateEx](#createex) método naquela variável.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir cria um controle de paginação, em seguida, usa o [CPagerCtrl::SetChild](#setchild) método para associar um controle de botão muito com o controle de paginação. O exemplo usa o [CPagerCtrl::SetButtonSize](#setbuttonsize) método para definir a altura do controle pager para 20 pixels e o [CPagerCtrl::SetBorder](#setborder) método para definir a espessura da borda de 1 pixel.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2 n º&1;](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_1.cpp)]  
  
##  <a name="createex"></a>CPagerCtrl::CreateEx  
 Cria um controle de paginação com estilos estendidos especificados e o anexa à atual `CPagerCtrl` objeto.  
  
```  
virtual BOOL CreateEx(
    DWORD dwExStyle,   
    DWORD dwStyle,   
    const RECT& rect,   
    CWnd* pParentWnd,   
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `dwExStyle`|Uma combinação bit a bit dos estilos estendidos para ser aplicado ao controle. Para obter mais informações, consulte o `dwExStyle` parâmetro o [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680) função.|  
|[in] `dwStyle`|Uma combinação bit a bit (OR) de [estilos de janela](../../mfc/reference/window-styles.md) e [estilos de controle pager](http://msdn.microsoft.com/library/windows/desktop/bb760859) a ser aplicado ao controle.|  
|[in] `rect`|Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que contém a posição e o tamanho do controle em coordenadas do cliente.|  
|[in] `pParentWnd`|Um ponteiro para um [CWnd](../../mfc/reference/cwnd-class.md) objeto que é a janela pai do controle. O parâmetro não pode ser `NULL`.|  
|[in] `nID`|A ID do controle.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Para criar um controle de paginação, declare um `CPagerCtrl` variável, em seguida, chame o [CPagerCtrl::Create](#create) ou [CPagerCtrl::CreateEx](#createex) método naquela variável.  
  
##  <a name="forwardmouse"></a>CPagerCtrl::ForwardMouse  
 Habilita ou desabilita encaminhamento [WM_MOUSEMOVE](http://msdn.microsoft.com/library/windows/desktop/ms645616) mensagens para a janela que está contido no controle de paginação atual.  
  
```  
void ForwardMouse(BOOL bForward);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `bForward`|`true`para encaminhar mensagens de mouse ou `false` não encaminhar mensagens do mouse.|  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_FORWARDMOUSE](http://msdn.microsoft.com/library/windows/desktop/bb760867) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getborder"></a>CPagerCtrl::GetBorder  
 Recupera o tamanho da borda do controle de paginação atual.  
  
```  
int GetBorder() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho atual da borda, medida em pixels.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_GETBORDER](http://msdn.microsoft.com/library/windows/desktop/bb760869) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir usa o [CPagerCtrl::GetBorder](#getborder) método para recuperar a espessura da borda do controle de paginação.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2 n º&5;](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_2.cpp)]  
  
##  <a name="getbkcolor"></a>CPagerCtrl::GetBkColor  
 Recupera a cor de plano de fundo do controle de paginação atual.  
  
```  
COLORREF GetBkColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor que contém a cor de plano de fundo atual do controle pager.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_GETBKCOLOR](http://msdn.microsoft.com/library/windows/desktop/bb760868) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir usa o [CPagerCtrl::SetBkColor](#setbkcolor) método para definir a cor de plano de fundo do controle pager para vermelho e o [CPagerCtrl::GetBkColor](#getbkcolor) método para confirmar que a alteração foi feita.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2 n º&4;](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_3.cpp)]  
  
##  <a name="getbuttonsize"></a>CPagerCtrl::GetButtonSize  
 Recupera o tamanho do botão de controle de paginação atual.  
  
```  
int GetButtonSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho atual do botão, medida em pixels.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_GETBUTTONSIZE](http://msdn.microsoft.com/library/windows/desktop/bb760870) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Se o controle de paginação tem o `PGS_HORZ` estilo, o tamanho do botão determina a largura dos botões de paginação, e se o controle de paginação tem o `PGS_VERT` estilo, o tamanho do botão determina a altura dos botões de paginação. Para obter mais informações, consulte [estilos de controle Pager](http://msdn.microsoft.com/library/windows/desktop/bb760859).  
  
##  <a name="getbuttonstate"></a>CPagerCtrl::GetButtonState  
 Recupera o estado do botão de rolagem especificado no controle de paginação atual.  
  
```  
DWORD GetButtonState(int iButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `iButton`|Indica o botão para que o estado é recuperado. Se o estilo de controle de paginação é `PGS_HORZ`, especifique `PGB_TOPORLEFT` para o botão esquerdo e `PGB_BOTTOMORRIGHT` para o botão direito. Se o estilo de controle de paginação é `PGS_VERT`, especifique `PGB_TOPORLEFT` do botão superior e `PGB_BOTTOMORRIGHT` do botão inferior. Para obter mais informações, consulte [estilos de controle Pager](http://msdn.microsoft.com/library/windows/desktop/bb760859).|  
  
### <a name="return-value"></a>Valor de retorno  
 O estado do botão especificado pelo `iButton` parâmetro. The state is either `PGF_INVISIBLE`, `PGF_NORMAL`, `PGF_GRAYED`, `PGF_DEPRESSED`, or `PGF_HOT`. Para obter mais informações, consulte a seção de valor de retorno do [PGM_GETBUTTONSTATE](http://msdn.microsoft.com/library/windows/desktop/bb760871) mensagem.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_GETBUTTONSTATE](http://msdn.microsoft.com/library/windows/desktop/bb760871) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getdroptarget"></a>CPagerCtrl::GetDropTarget  
 Recupera o [IDropTarget](http://msdn.microsoft.com/library/windows/desktop/ms679679) interface para o controle de paginação atual.  
  
```  
IDropTarget* GetDropTarget() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `IDropTarget` interface para o controle de paginação atual.  
  
### <a name="remarks"></a>Comentários  
 `IDropTarget`é uma das interfaces de implementar para oferecer suporte a operações de arrastar e soltar em seu aplicativo.  
  
 Esse método envia o [PGM_GETDROPTARGET](http://msdn.microsoft.com/library/windows/desktop/bb760872) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. O chamador desse método é responsável por chamar o `Release` membro o [IDropTarget](http://msdn.microsoft.com/library/windows/desktop/ms679679) interface quando a interface não é mais necessária.  
  
##  <a name="getscrollpos"></a>CPagerCtrl::GetScrollPos  
 Recupera a posição de rolagem de controle de paginação atual.  
  
```  
int GetScrollPos() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A posição de rolagem atual, medida em pixels.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_GETPOS](http://msdn.microsoft.com/library/windows/desktop/bb760874) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir usa o [CPagerCtrl::GetScrollPos](#getscrollpos) método para recuperar a posição de rolagem atual de controle de paginação. Se o controle de paginação já não é rolado para zero, a posição mais à esquerda, o exemplo usa o [CPagerCtrl::SetScrollPos](#setscrollpos) método para definir a posição de rolagem como zero.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s&#2;7](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_4.cpp)]  
  
##  <a name="isbuttondepressed"></a>CPagerCtrl::IsButtonDepressed  
 Indica se o botão de rolagem especificado do controle pager atual está no estado pressionado.  
  
```  
BOOL IsButtonDepressed(int iButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `iButton`|Indica o botão para que o estado é recuperado. Se o estilo de controle de paginação é `PGS_HORZ`, especifique `PGB_TOPORLEFT` para o botão esquerdo e `PGB_BOTTOMORRIGHT` para o botão direito. Se o estilo de controle de paginação é `PGS_VERT`, especifique `PGB_TOPORLEFT` do botão superior e `PGB_BOTTOMORRIGHT` do botão inferior. Para obter mais informações, consulte [estilos de controle Pager](http://msdn.microsoft.com/library/windows/desktop/bb760859).|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o botão especificado está no estado pressionado. Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_GETBUTTONSTATE](http://msdn.microsoft.com/library/windows/desktop/bb760871) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Em seguida, testa se o estado que é retornado é `PGF_DEPRESSED`. Para obter mais informações, consulte a seção de valor de retorno do [PGM_GETBUTTONSTATE](http://msdn.microsoft.com/library/windows/desktop/bb760871) mensagem.  
  
##  <a name="isbuttongrayed"></a>CPagerCtrl::IsButtonGrayed  
 Indica se o botão de rolagem especificado do controle pager atual está no estado esmaecido.  
  
```  
BOOL IsButtonGrayed(int iButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `iButton`|Indica o botão para que o estado é recuperado. Se o estilo de controle de paginação é `PGS_HORZ`, especifique `PGB_TOPORLEFT` para o botão esquerdo e `PGB_BOTTOMORRIGHT` para o botão direito. Se o estilo de controle de paginação é `PGS_VERT`, especifique `PGB_TOPORLEFT` do botão superior e `PGB_BOTTOMORRIGHT` do botão inferior. Para obter mais informações, consulte [estilos de controle Pager](http://msdn.microsoft.com/library/windows/desktop/bb760859).|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o botão especificado está no estado esmaecido. Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_GETBUTTONSTATE](http://msdn.microsoft.com/library/windows/desktop/bb760871) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Em seguida, testa se o estado que é retornado é `PGF_GRAYED`. Para obter mais informações, consulte a seção de valor de retorno do [PGM_GETBUTTONSTATE](http://msdn.microsoft.com/library/windows/desktop/bb760871) mensagem.  
  
##  <a name="isbuttonhot"></a>CPagerCtrl::IsButtonHot  
 Indica se o botão de rolagem especificado do controle pager atual está no estado ativo.  
  
```  
BOOL IsButtonHot(int iButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `iButton`|Indica o botão para que o estado é recuperado. Se o estilo de controle de paginação é `PGS_HORZ`, especifique `PGB_TOPORLEFT` para o botão esquerdo e `PGB_BOTTOMORRIGHT` para o botão direito. Se o estilo de controle de paginação é `PGS_VERT`, especifique `PGB_TOPORLEFT` do botão superior e `PGB_BOTTOMORRIGHT` do botão inferior. Para obter mais informações, consulte [estilos de controle Pager](http://msdn.microsoft.com/library/windows/desktop/bb760859).|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o botão especificado estiver no estado ativo. Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_GETBUTTONSTATE](http://msdn.microsoft.com/library/windows/desktop/bb760871) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Em seguida, testa se o estado que é retornado é `PGF_HOT`. Para obter mais informações, consulte a seção de valor de retorno do [PGM_GETBUTTONSTATE](http://msdn.microsoft.com/library/windows/desktop/bb760871) mensagem.  
  
##  <a name="isbuttoninvisible"></a>CPagerCtrl::IsButtonInvisible  
 Indica se o botão de rolagem especificado do controle pager atual está no estado invisível.  
  
```  
BOOL IsButtonInvisible(int iButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `iButton`|Indica o botão para que o estado é recuperado. Se o estilo de controle de paginação é `PGS_HORZ`, especifique `PGB_TOPORLEFT` para o botão esquerdo e `PGB_BOTTOMORRIGHT` para o botão direito. Se o estilo de controle de paginação é `PGS_VERT`, especifique `PGB_TOPORLEFT` do botão superior e `PGB_BOTTOMORRIGHT` do botão inferior. Para obter mais informações, consulte [estilos de controle Pager](http://msdn.microsoft.com/library/windows/desktop/bb760859).|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o botão especificado está no estado invisível. Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Windows faz com que o botão de rolagem em uma direção específica invisível quando a janela independente é rolada para sua extensão mais distante porque clicando no botão adicional não pode colocar mais da janela contida na exibição.  
  
 Esse método envia o [PGM_GETBUTTONSTATE](http://msdn.microsoft.com/library/windows/desktop/bb760871) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Em seguida, testa se o estado que é retornado é `PGF_INVISIBLE`. Para obter mais informações, consulte a seção de valor de retorno do [PGM_GETBUTTONSTATE](http://msdn.microsoft.com/library/windows/desktop/bb760871) mensagem.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir usa o [CPagerCtrl::IsButtonInvisible](#isbuttoninvisible) método para determinar se o controle de paginação da esquerda e botões de rolagem à direita são visíveis.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2 n º&6;](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_5.cpp)]  
  
##  <a name="isbuttonnormal"></a>CPagerCtrl::IsButtonNormal  
 Indica se o botão de rolagem especificado do controle pager atual está em estado normal.  
  
```  
BOOL IsButtonNormal(int iButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `iButton`|Indica o botão para que o estado é recuperado. Se o estilo de controle de paginação é `PGS_HORZ`, especifique `PGB_TOPORLEFT` para o botão esquerdo e `PGB_BOTTOMORRIGHT` para o botão direito. Se o estilo de controle de paginação é `PGS_VERT`, especifique `PGB_TOPORLEFT` do botão superior e `PGB_BOTTOMORRIGHT` do botão inferior. Para obter mais informações, consulte [estilos de controle Pager](http://msdn.microsoft.com/library/windows/desktop/bb760859).|  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se o botão especificado está no estado normal. Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_GETBUTTONSTATE](http://msdn.microsoft.com/library/windows/desktop/bb760871) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Em seguida, testa se o estado que é retornado é `PGF_NORMAL`. Para obter mais informações, consulte a seção de valor de retorno do [PGM_GETBUTTONSTATE](http://msdn.microsoft.com/library/windows/desktop/bb760871) mensagem.  
  
##  <a name="recalcsize"></a>CPagerCtrl::RecalcSize  
 Faz com que o controle de paginação atual recalcular o tamanho da janela contida.  
  
```  
void RecalcSize();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_RECALCSIZE](http://msdn.microsoft.com/library/windows/desktop/bb760876) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Consequentemente, o controle de pager envia o [PGN_CALCSIZE](http://msdn.microsoft.com/library/windows/desktop/bb760864) notificação para obter as dimensões de rolagem da janela contida.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir usa o [CPagerCtrl::RecalcSize](#recalcsize) método para solicitar o controle de paginação atual para recalcular o seu tamanho.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2 n º&3;](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_6.cpp)]  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir usa [reflexão de mensagem](../../mfc/tn062-message-reflection-for-windows-controls.md) para habilitar o controle de pager recalcular o seu próprio tamanho, em vez de exigir que a caixa de diálogo do controle pai para executar o cálculo. Deriva de exemplo o `MyPagerCtrl` classe a partir o [CPagerCtrl classe](../../mfc/reference/cpagerctrl-class.md), usa um mapa da mensagem para associar o [PGN_CALCSIZE](http://msdn.microsoft.com/library/windows/desktop/bb760864) notificação com o `OnCalcsize` manipulador de notificação. Neste exemplo, o manipulador de notificação define a largura e altura do controle pager para valores fixos.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2 n º&8;](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_7.cpp)]  
  
##  <a name="setbkcolor"></a>CPagerCtrl::SetBkColor  
 Define a cor de plano de fundo do controle de paginação atual.  
  
```  
COLORREF SetBkColor(COLORREF clrBk);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `clrBk`|A [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor que contém a nova cor de plano de fundo do controle pager.|  
  
### <a name="return-value"></a>Valor de retorno  
 A [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor que contém a cor de plano de fundo anterior do controle pager.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_SETBKCOLOR](http://msdn.microsoft.com/library/windows/desktop/bb760878) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir usa o [CPagerCtrl::SetBkColor](#setbkcolor) método para definir a cor de plano de fundo do controle pager para vermelho e o [CPagerCtrl::GetBkColor](#getbkcolor) método para confirmar que a alteração foi feita.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2 n º&4;](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_3.cpp)]  
  
##  <a name="setborder"></a>CPagerCtrl::SetBorder  
 Define o tamanho da borda do controle de paginação atual.  
  
```  
int SetBorder(int iBorder);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `iBorder`|O novo tamanho da borda, medida em pixels. Se o `iBorder` parâmetro for negativo, o tamanho da borda é definido como zero.|  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho da borda anterior, medido em pixels.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_SETBORDER](http://msdn.microsoft.com/library/windows/desktop/bb760880) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir cria um controle de paginação, em seguida, usa o [CPagerCtrl::SetChild](#setchild) método para associar um controle de botão muito com o controle de paginação. O exemplo usa o [CPagerCtrl::SetButtonSize](#setbuttonsize) método para definir a altura do controle pager para 20 pixels e o [CPagerCtrl::SetBorder](#setborder) método para definir a espessura da borda de 1 pixel.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2 n º&1;](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_1.cpp)]  
  
##  <a name="setbuttonsize"></a>CPagerCtrl::SetButtonSize  
 Define o tamanho do botão de controle de paginação atual.  
  
```  
int SetButtonSize(int iButtonSize);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `iButtonSize`|O novo tamanho do botão, medida em pixels.|  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho do botão anterior, medido em pixels.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_SETBUTTONSIZE](http://msdn.microsoft.com/library/windows/desktop/bb760886) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Se o controle de paginação tem o `PGS_HORZ` estilo, o tamanho do botão determina a largura dos botões de paginação, e se o controle de paginação tem o `PGS_VERT` estilo, o tamanho do botão determina a altura dos botões de paginação. O tamanho padrão do botão é três-quartos da largura da barra de rolagem e o tamanho mínimo do botão é 12 pixels. Para obter mais informações, consulte [estilos de controle Pager](http://msdn.microsoft.com/library/windows/desktop/bb760859).  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir cria um controle de paginação, em seguida, usa o [CPagerCtrl::SetChild](#setchild) método para associar um controle de botão muito com o controle de paginação. O exemplo usa o [CPagerCtrl::SetButtonSize](#setbuttonsize) método para definir a altura do controle pager para 20 pixels e o [CPagerCtrl::SetBorder](#setborder) método para definir a espessura da borda de 1 pixel.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2 n º&1;](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_1.cpp)]  
  
##  <a name="setchild"></a>CPagerCtrl::SetChild  
 Define a janela independente para o controle de paginação atual.  
  
```  
void SetChild(HWND hwndChild);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `hwndChild`|Identificador para a janela a ser contido.|  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_SETCHILD](http://msdn.microsoft.com/library/windows/desktop/bb760884) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 Este método não altera o pai da janela independente; apenas atribui um identificador de janela para o controle de paginação de rolagem. Na maioria dos casos, a janela contida será uma janela filho do controle pager.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir cria um controle de paginação, em seguida, usa o [CPagerCtrl::SetChild](#setchild) método para associar um controle de botão muito com o controle de paginação. O exemplo usa o [CPagerCtrl::SetButtonSize](#setbuttonsize) método para definir a altura do controle pager para 20 pixels e o [CPagerCtrl::SetBorder](#setborder) método para definir a espessura da borda de 1 pixel.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2 n º&1;](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_1.cpp)]  
  
##  <a name="setscrollpos"></a>CPagerCtrl::SetScrollPos  
 Define a posição de rolagem de controle de paginação atual.  
  
```  
void SetScrollPos(int iPos);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `iPos`|A nova posição de rolagem, medido em pixels.|  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_SETPOS](http://msdn.microsoft.com/library/windows/desktop/bb760886) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Classe CPagerCtrl](../../mfc/reference/cpagerctrl-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Controles de paginação](http://msdn.microsoft.com/library/windows/desktop/bb760855)




