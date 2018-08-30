---
title: Classe CPagerCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
- CPagerCtrl [MFC], CPagerCtrl
- CPagerCtrl [MFC], Create
- CPagerCtrl [MFC], CreateEx
- CPagerCtrl [MFC], ForwardMouse
- CPagerCtrl [MFC], GetBkColor
- CPagerCtrl [MFC], GetBorder
- CPagerCtrl [MFC], GetButtonSize
- CPagerCtrl [MFC], GetButtonState
- CPagerCtrl [MFC], GetDropTarget
- CPagerCtrl [MFC], GetScrollPos
- CPagerCtrl [MFC], IsButtonDepressed
- CPagerCtrl [MFC], IsButtonGrayed
- CPagerCtrl [MFC], IsButtonHot
- CPagerCtrl [MFC], IsButtonInvisible
- CPagerCtrl [MFC], IsButtonNormal
- CPagerCtrl [MFC], RecalcSize
- CPagerCtrl [MFC], SetBkColor
- CPagerCtrl [MFC], SetBorder
- CPagerCtrl [MFC], SetButtonSize
- CPagerCtrl [MFC], SetChild
- CPagerCtrl [MFC], SetScrollPos
ms.assetid: 65ac58dd-4f5e-4b7e-b15c-e0d435a7e884
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f311f7b73e72f47f363cfd5645c97b57eda5b480
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43200870"
---
# <a name="cpagerctrl-class"></a>Classe CPagerCtrl
O `CPagerCtrl` classe encapsula o controle de paginação do Windows, que pode rolar na exibição de uma janela contida que não se ajusta a janela.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CPagerCtrl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPagerCtrl::CPagerCtrl](#cpagerctrl)|Constrói um objeto `CPagerCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPagerCtrl::Create](#create)|Cria um controle de paginação com estilos especificados e a anexa ao atual `CPagerCtrl` objeto.|  
|[CPagerCtrl::CreateEx](#createex)|Cria um controle de paginação com estilos estendidos especificados e a anexa ao atual `CPagerCtrl` objeto.|  
|[CPagerCtrl::ForwardMouse](#forwardmouse)|Habilita ou desabilita o encaminhamento [WM_MOUSEMOVE](/windows/desktop/inputdev/wm-mousemove) mensagens na janela que está contido no controle de pager atual.|  
|[CPagerCtrl::GetBkColor](#getbkcolor)|Recupera a cor de plano de fundo do controle de pager atual.|  
|[CPagerCtrl::GetBorder](#getborder)|Recupera o tamanho da borda do controle de pager atual.|  
|[CPagerCtrl::GetButtonSize](#getbuttonsize)|Recupera o tamanho do botão do controle de pager atual.|  
|[CPagerCtrl::GetButtonState](#getbuttonstate)|Recupera o estado do botão especificado no controle de pager atual.|  
|[CPagerCtrl::GetDropTarget](#getdroptarget)|Recupera o [IDropTarget](/windows/desktop/api/oleidl/nn-oleidl-idroptarget) interface para o controle de paginação atual.|  
|[CPagerCtrl::GetScrollPos](#getscrollpos)|Recupera a posição de rolagem do controle de pager atual.|  
|[CPagerCtrl::IsButtonDepressed](#isbuttondepressed)|Indica se o botão especificado do controle de pager atual está em `pressed` estado.|  
|[CPagerCtrl::IsButtonGrayed](#isbuttongrayed)|Indica se o botão especificado do controle de pager atual está em `grayed` estado.|  
|[CPagerCtrl::IsButtonHot](#isbuttonhot)|Indica se o botão especificado do controle de pager atual está em `hot` estado.|  
|[CPagerCtrl::IsButtonInvisible](#isbuttoninvisible)|Indica se o botão especificado do controle de pager atual está em `invisible` estado.|  
|[CPagerCtrl::IsButtonNormal](#isbuttonnormal)|Indica se o botão especificado do controle de pager atual está em `normal` estado.|  
|[CPagerCtrl::RecalcSize](#recalcsize)|Faz com que o controle de paginação atual recalcular o tamanho da janela contida.|  
|[CPagerCtrl::SetBkColor](#setbkcolor)|Define a cor do plano de fundo do controle de pager atual.|  
|[CPagerCtrl::SetBorder](#setborder)|Define o tamanho da borda do controle de pager atual.|  
|[CPagerCtrl::SetButtonSize](#setbuttonsize)|Define o tamanho do botão do controle de pager atual.|  
|[CPagerCtrl::SetChild](#setchild)|Define a janela independente para o controle de paginação atual.|  
|[CPagerCtrl::SetScrollPos](#setscrollpos)|Define a posição de rolagem do controle de pager atual.|  
  
## <a name="remarks"></a>Comentários  
 Um controle de paginação é uma janela que contém outra janela que é maior do que a janela que contém e linear e permite que você rolar a janela contida na exibição. O controle de paginação exibe dois botões de rolagem que desaparecem automaticamente quando a janela contida é rolada até seu ponto mais distante e reaparecer caso contrário. Você pode criar um controle de paginação que rola horizontalmente ou verticalmente.  
  
 Por exemplo, se seu aplicativo tiver uma barra de ferramentas que não é grande o suficiente para mostrar todos os seus itens, você pode atribuir a barra de ferramentas a um controle de paginação e os usuários poderão rolar a barra de ferramentas para a esquerda ou direita para acessar todos os itens. Microsoft Internet Explorer versão 4.0 (Commctrl versão 4.71) introduz o controle de paginação.  
  
 O `CPagerCtrl` classe é derivada de [CWnd](../../mfc/reference/cwnd-class.md) classe. Para obter mais informações e uma ilustração de um controle de paginação, consulte [controles de paginação](/windows/desktop/Controls/pager-controls).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CPagerCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn. h  
  
##  <a name="cpagerctrl"></a>  CPagerCtrl::CPagerCtrl  
 Constrói um objeto `CPagerCtrl`.  
  
```  
CPagerCtrl();
```  
  
### <a name="remarks"></a>Comentários  
 Use o [CPagerCtrl::Create](#create) ou [CPagerCtrl::CreateEx](#createex) método para criar um controle de paginação e anexá-lo para o `CPagerCtrl` objeto.  
  
##  <a name="create"></a>  CPagerCtrl::Create  
 Cria um controle de paginação com estilos especificados e a anexa ao atual `CPagerCtrl` objeto.  
  
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
|[in] *dwStyle*|Uma combinação bit a bit (OR) de [estilos da janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) e [estilos de controle de pager](/windows/desktop/Controls/pager-control-styles) a ser aplicado ao controle.|  
|[in] *rect*|Uma referência a um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que contém a posição e tamanho do controle em coordenadas de cliente.|  
|[in] *pParentWnd*|Um ponteiro para um [CWnd](../../mfc/reference/cwnd-class.md) objeto que é a janela pai do controle. Esse parâmetro não pode ser NULL.|  
|[in] *nID*|A ID do controle.|  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se esse método for bem-sucedida; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Para criar um controle de paginação, declare uma `CPagerCtrl` variável, em seguida, chamar o [CPagerCtrl::Create](#create) ou [CPagerCtrl::CreateEx](#createex) método nessa variável.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir cria um controle de paginação, em seguida, usa o [CPagerCtrl::SetChild](#setchild) método para associar um controle de botão muito com o controle de paginação. O exemplo usa o [CPagerCtrl::SetButtonSize](#setbuttonsize) método para definir a altura do controle de pager a 20 pixels e o [CPagerCtrl::SetBorder](#setborder) método para definir a espessura da borda de 1 pixel.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2#1](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_1.cpp)]  
  
##  <a name="createex"></a>  CPagerCtrl::CreateEx  
 Cria um controle de paginação com estilos estendidos especificados e a anexa ao atual `CPagerCtrl` objeto.  
  
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
|[in] *dwExStyle*|Uma combinação bit a bit dos estilos estendidos para ser aplicado ao controle. Para obter mais informações, consulte o *dwExStyle* parâmetro do [CreateWindowEx](https://msdn.microsoft.com/library/windows/desktop/ms632680) função.|  
|[in] *dwStyle*|Uma combinação bit a bit (OR) de [estilos da janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) e [estilos de controle de pager](/windows/desktop/Controls/pager-control-styles) a ser aplicado ao controle.|  
|[in] *rect*|Uma referência a um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que contém a posição e tamanho do controle em coordenadas de cliente.|  
|[in] *pParentWnd*|Um ponteiro para um [CWnd](../../mfc/reference/cwnd-class.md) objeto que é a janela pai do controle. Esse parâmetro não pode ser NULL.|  
|[in] *nID*|A ID do controle.|  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se esse método for bem-sucedida; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Para criar um controle de paginação, declare uma `CPagerCtrl` variável, em seguida, chamar o [CPagerCtrl::Create](#create) ou [CPagerCtrl::CreateEx](#createex) método nessa variável.  
  
##  <a name="forwardmouse"></a>  CPagerCtrl::ForwardMouse  
 Habilita ou desabilita o encaminhamento [WM_MOUSEMOVE](/windows/desktop/inputdev/wm-mousemove) mensagens na janela que está contido no controle de pager atual.  
  
```  
void ForwardMouse(BOOL bForward);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *bForward*|True para mensagens de mouse de encaminhamento, ou falso para não encaminhar mensagens do mouse.|  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_FORWARDMOUSE](/windows/desktop/Controls/pgm-forwardmouse) mensagem, que é descrita no SDK do Windows.  
  
##  <a name="getborder"></a>  CPagerCtrl::GetBorder  
 Recupera o tamanho da borda do controle de pager atual.  
  
```  
int GetBorder() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho atual da borda, medida em pixels.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_GETBORDER](/windows/desktop/Controls/pgm-getborder) mensagem, que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir usa o [CPagerCtrl::GetBorder](#getborder) método para recuperar a espessura da borda do controle de pager.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2#5](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_2.cpp)]  
  
##  <a name="getbkcolor"></a>  CPagerCtrl::GetBkColor  
 Recupera a cor de plano de fundo do controle de pager atual.  
  
```  
COLORREF GetBkColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [COLORREF](/windows/desktop/gdi/colorref) valor que contém a cor de plano de fundo atual de controle de paginação.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_GETBKCOLOR](/windows/desktop/Controls/pgm-getbkcolor) mensagem, que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir usa o [CPagerCtrl::SetBkColor](#setbkcolor) método para definir a cor de plano de fundo do controle de pager para vermelho e o [CPagerCtrl::GetBkColor](#getbkcolor) método para confirmar que a alteração foi feita.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2#4](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_3.cpp)]  
  
##  <a name="getbuttonsize"></a>  CPagerCtrl::GetButtonSize  
 Recupera o tamanho do botão do controle de pager atual.  
  
```  
int GetButtonSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho atual do botão, medida em pixels.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_GETBUTTONSIZE](/windows/desktop/Controls/pgm-getbuttonsize) mensagem, que é descrita no SDK do Windows.  
  
 Se o controle de paginação tem o estilo PGS_HORZ, o tamanho do botão determina a largura dos botões de paginação, e se o controle de paginação tem o estilo PGS_VERT, o tamanho do botão determina a altura dos botões de paginação. Para obter mais informações, consulte [estilos de controle de Pager](/windows/desktop/Controls/pager-control-styles).  
  
##  <a name="getbuttonstate"></a>  CPagerCtrl::GetButtonState  
 Recupera o estado do botão de rolagem especificado no controle de pager atual.  
  
```  
DWORD GetButtonState(int iButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *iButton*|Indica o botão para o qual o estado é recuperado. Se o estilo de controle de pager for PGS_HORZ, especifique PGB_TOPORLEFT para o botão esquerdo e PGB_BOTTOMORRIGHT para o botão direito. Se o estilo de controle de pager for PGS_VERT, especifique PGB_TOPORLEFT para o botão superior e PGB_BOTTOMORRIGHT do botão inferior. Para obter mais informações, consulte [estilos de controle de Pager](/windows/desktop/Controls/pager-control-styles).|  
  
### <a name="return-value"></a>Valor de retorno  
 O estado do botão especificado pelo *iButton* parâmetro. O estado é PGF_INVISIBLE, PGF_NORMAL, PGF_GRAYED, PGF_DEPRESSED ou PGF_HOT. Para obter mais informações, consulte a seção valor retornar os [PGM_GETBUTTONSTATE](/windows/desktop/Controls/pgm-getbuttonstate) mensagem.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_GETBUTTONSTATE](/windows/desktop/Controls/pgm-getbuttonstate) mensagem, que é descrita no SDK do Windows.  
  
##  <a name="getdroptarget"></a>  CPagerCtrl::GetDropTarget  
 Recupera o [IDropTarget](/windows/desktop/api/oleidl/nn-oleidl-idroptarget) interface para o controle de paginação atual.  
  
```  
IDropTarget* GetDropTarget() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `IDropTarget` interface para o controle de paginação atual.  
  
### <a name="remarks"></a>Comentários  
 `IDropTarget` é uma das interfaces de implementar para dar suporte a operações de arrastar e soltar em seu aplicativo.  
  
 Esse método envia o [PGM_GETDROPTARGET](/windows/desktop/Controls/pgm-getdroptarget) mensagem, que é descrita no SDK do Windows. O chamador desse método é responsável por chamar o `Release` membro a [IDropTarget](/windows/desktop/api/oleidl/nn-oleidl-idroptarget) interface quando a interface não é mais necessário.  
  
##  <a name="getscrollpos"></a>  CPagerCtrl::GetScrollPos  
 Recupera a posição de rolagem do controle de pager atual.  
  
```  
int GetScrollPos() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A atual posição de rolagem, medida em pixels.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_GETPOS](/windows/desktop/Controls/pgm-getpos) mensagem, que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir usa o [CPagerCtrl::GetScrollPos](#getscrollpos) método para recuperar a posição de rolagem atual de controle de paginação. Se o controle de paginação já não é rolado para zero, a posição mais à esquerda, o exemplo usa o [CPagerCtrl::SetScrollPos](#setscrollpos) método para definir a posição de rolagem como zero.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2#7](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_4.cpp)]  
  
##  <a name="isbuttondepressed"></a>  CPagerCtrl::IsButtonDepressed  
 Indica se o botão de rolagem especificado do controle de pager atual está no estado pressionado.  
  
```  
BOOL IsButtonDepressed(int iButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *iButton*|Indica o botão para o qual o estado é recuperado. Se o estilo de controle de pager for PGS_HORZ, especifique PGB_TOPORLEFT para o botão esquerdo e PGB_BOTTOMORRIGHT para o botão direito. Se o estilo de controle de pager for PGS_VERT, especifique PGB_TOPORLEFT para o botão superior e PGB_BOTTOMORRIGHT do botão inferior. Para obter mais informações, consulte [estilos de controle de Pager](/windows/desktop/Controls/pager-control-styles).|  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o botão especificado estiver no estado pressionado; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_GETBUTTONSTATE](/windows/desktop/Controls/pgm-getbuttonstate) mensagem, que é descrita no SDK do Windows. Ele, em seguida, testa se o estado que é retornado é PGF_DEPRESSED. Para obter mais informações, consulte a seção valor retornar os [PGM_GETBUTTONSTATE](/windows/desktop/Controls/pgm-getbuttonstate) mensagem.  
  
##  <a name="isbuttongrayed"></a>  CPagerCtrl::IsButtonGrayed  
 Indica se o botão de rolagem especificado do controle de pager atual está no estado cinza.  
  
```  
BOOL IsButtonGrayed(int iButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *iButton*|Indica o botão para o qual o estado é recuperado. Se o estilo de controle de pager for PGS_HORZ, especifique PGB_TOPORLEFT para o botão esquerdo e PGB_BOTTOMORRIGHT para o botão direito. Se o estilo de controle de pager for PGS_VERT, especifique PGB_TOPORLEFT para o botão superior e PGB_BOTTOMORRIGHT do botão inferior. Para obter mais informações, consulte [estilos de controle de Pager](/windows/desktop/Controls/pager-control-styles).|  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o botão especificado estiver no estado cinza; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_GETBUTTONSTATE](/windows/desktop/Controls/pgm-getbuttonstate) mensagem, que é descrita no SDK do Windows. Ele, em seguida, testa se o estado que é retornado é PGF_GRAYED. Para obter mais informações, consulte a seção valor retornar os [PGM_GETBUTTONSTATE](/windows/desktop/Controls/pgm-getbuttonstate) mensagem.  
  
##  <a name="isbuttonhot"></a>  CPagerCtrl::IsButtonHot  
 Indica se o botão de rolagem especificado do controle de pager atual está no estado ativo.  
  
```  
BOOL IsButtonHot(int iButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *iButton*|Indica o botão para o qual o estado é recuperado. Se o estilo de controle de pager for PGS_HORZ, especifique PGB_TOPORLEFT para o botão esquerdo e PGB_BOTTOMORRIGHT para o botão direito. Se o estilo de controle de pager for PGS_VERT, especifique PGB_TOPORLEFT para o botão superior e PGB_BOTTOMORRIGHT do botão inferior. Para obter mais informações, consulte [estilos de controle de Pager](/windows/desktop/Controls/pager-control-styles).|  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o botão especificado está no estado ativo; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_GETBUTTONSTATE](/windows/desktop/Controls/pgm-getbuttonstate) mensagem, que é descrita no SDK do Windows. Ele, em seguida, testa se o estado que é retornado é PGF_HOT. Para obter mais informações, consulte a seção valor retornar os [PGM_GETBUTTONSTATE](/windows/desktop/Controls/pgm-getbuttonstate) mensagem.  
  
##  <a name="isbuttoninvisible"></a>  CPagerCtrl::IsButtonInvisible  
 Indica se o botão de rolagem especificado do controle de pager atual está no estado invisível.  
  
```  
BOOL IsButtonInvisible(int iButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *iButton*|Indica o botão para o qual o estado é recuperado. Se o estilo de controle de pager for PGS_HORZ, especifique PGB_TOPORLEFT para o botão esquerdo e PGB_BOTTOMORRIGHT para o botão direito. Se o estilo de controle de pager for PGS_VERT, especifique PGB_TOPORLEFT para o botão superior e PGB_BOTTOMORRIGHT do botão inferior. Para obter mais informações, consulte [estilos de controle de Pager](/windows/desktop/Controls/pager-control-styles).|  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o botão especificado estiver no estado invisível; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Windows faz com que o botão de rolagem em uma direção específica invisível quando a janela contida é rolada para sua extensão mais distante, porque mais de janela contida clicando no botão ainda mais, não é possível colocar em modo de exibição.  
  
 Esse método envia o [PGM_GETBUTTONSTATE](/windows/desktop/Controls/pgm-getbuttonstate) mensagem, que é descrita no SDK do Windows. Ele, em seguida, testa se o estado que é retornado é PGF_INVISIBLE. Para obter mais informações, consulte a seção valor retornar os [PGM_GETBUTTONSTATE](/windows/desktop/Controls/pgm-getbuttonstate) mensagem.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir usa o [CPagerCtrl::IsButtonInvisible](#isbuttoninvisible) método para determinar se a esquerda do controle de paginação e botões de rolagem à direita são visíveis.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2#6](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_5.cpp)]  
  
##  <a name="isbuttonnormal"></a>  CPagerCtrl::IsButtonNormal  
 Indica se o botão de rolagem especificado do controle de pager atual está no estado normal.  
  
```  
BOOL IsButtonNormal(int iButton) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *iButton*|Indica o botão para o qual o estado é recuperado. Se o estilo de controle de pager for PGS_HORZ, especifique PGB_TOPORLEFT para o botão esquerdo e PGB_BOTTOMORRIGHT para o botão direito. Se o estilo de controle de pager for PGS_VERT, especifique PGB_TOPORLEFT para o botão superior e PGB_BOTTOMORRIGHT do botão inferior. Para obter mais informações, consulte [estilos de controle de Pager](/windows/desktop/Controls/pager-control-styles).|  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o botão especificado estiver no estado normal; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_GETBUTTONSTATE](/windows/desktop/Controls/pgm-getbuttonstate) mensagem, que é descrita no SDK do Windows. Ele, em seguida, testa se o estado que é retornado é PGF_NORMAL. Para obter mais informações, consulte a seção valor retornar os [PGM_GETBUTTONSTATE](/windows/desktop/Controls/pgm-getbuttonstate) mensagem.  
  
##  <a name="recalcsize"></a>  CPagerCtrl::RecalcSize  
 Faz com que o controle de paginação atual recalcular o tamanho da janela contida.  
  
```  
void RecalcSize();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_RECALCSIZE](/windows/desktop/Controls/pgm-recalcsize) mensagem, que é descrita no SDK do Windows. Consequentemente, o controle de pager envia o [PGN_CALCSIZE](/windows/desktop/Controls/pgn-calcsize) notificação para obter as dimensões com rolagem da janela contida.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir usa o [CPagerCtrl::RecalcSize](#recalcsize) método para solicitar o controle de paginação atual a recalcular seu tamanho.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2#3](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_6.cpp)]  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir usa [reflexão de mensagem](../../mfc/tn062-message-reflection-for-windows-controls.md) para habilitar o controle de pager recalcular o seu próprio tamanho, em vez de exigir que a caixa de diálogo do controle pai para executar o cálculo. Deriva o exemplo a `MyPagerCtrl` classe do [classe CPagerCtrl](../../mfc/reference/cpagerctrl-class.md), em seguida, usa um mapa de mensagem para associar o [PGN_CALCSIZE](/windows/desktop/Controls/pgn-calcsize) notificação com o `OnCalcsize` manipulador de notificação. Neste exemplo, o manipulador de notificação define a largura e altura do controle de pager para valores fixos.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2#8](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_7.cpp)]  
  
##  <a name="setbkcolor"></a>  CPagerCtrl::SetBkColor  
 Define a cor do plano de fundo do controle de pager atual.  
  
```  
COLORREF SetBkColor(COLORREF clrBk);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *clrBk*|Um [COLORREF](/windows/desktop/gdi/colorref) valor que contém a nova cor de plano de fundo do controle de pager.|  
  
### <a name="return-value"></a>Valor de retorno  
 Um [COLORREF](/windows/desktop/gdi/colorref) valor que contém a cor anterior da tela de fundo de controle de paginação.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_SETBKCOLOR](/windows/desktop/Controls/pgm-setbkcolor) mensagem, que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir usa o [CPagerCtrl::SetBkColor](#setbkcolor) método para definir a cor de plano de fundo do controle de pager para vermelho e o [CPagerCtrl::GetBkColor](#getbkcolor) método para confirmar que a alteração foi feita.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2#4](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_3.cpp)]  
  
##  <a name="setborder"></a>  CPagerCtrl::SetBorder  
 Define o tamanho da borda do controle de pager atual.  
  
```  
int SetBorder(int iBorder);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *iBorder*|O novo tamanho de borda, medida em pixels. Se o *iBorder* parâmetro for negativo, o tamanho da borda é definido como zero.|  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho anterior da borda, medida em pixels.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_SETBORDER](/windows/desktop/Controls/pgm-setborder) mensagem, que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir cria um controle de paginação, em seguida, usa o [CPagerCtrl::SetChild](#setchild) método para associar um controle de botão muito com o controle de paginação. O exemplo usa o [CPagerCtrl::SetButtonSize](#setbuttonsize) método para definir a altura do controle de pager a 20 pixels e o [CPagerCtrl::SetBorder](#setborder) método para definir a espessura da borda de 1 pixel.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2#1](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_1.cpp)]  
  
##  <a name="setbuttonsize"></a>  CPagerCtrl::SetButtonSize  
 Define o tamanho do botão do controle de pager atual.  
  
```  
int SetButtonSize(int iButtonSize);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *iButtonSize*|O novo tamanho do botão, medida em pixels.|  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho anterior do botão, medida em pixels.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_SETBUTTONSIZE](/windows/desktop/Controls/pgm-setpos) mensagem, que é descrita no SDK do Windows.  
  
 Se o controle de paginação tem o estilo PGS_HORZ, o tamanho do botão determina a largura dos botões de paginação, e se o controle de paginação tem o estilo PGS_VERT, o tamanho do botão determina a altura dos botões de paginação. O tamanho do botão padrão é três-quartos da largura da barra de rolagem e o tamanho mínimo do botão é de 12 pixels. Para obter mais informações, consulte [estilos de controle de Pager](/windows/desktop/Controls/pager-control-styles).  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir cria um controle de paginação, em seguida, usa o [CPagerCtrl::SetChild](#setchild) método para associar um controle de botão muito com o controle de paginação. O exemplo usa o [CPagerCtrl::SetButtonSize](#setbuttonsize) método para definir a altura do controle de pager a 20 pixels e o [CPagerCtrl::SetBorder](#setborder) método para definir a espessura da borda de 1 pixel.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2#1](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_1.cpp)]  
  
##  <a name="setchild"></a>  CPagerCtrl::SetChild  
 Define a janela independente para o controle de paginação atual.  
  
```  
void SetChild(HWND hwndChild);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *hwndChild*|Identificador da janela a ser contido.|  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_SETCHILD](/windows/desktop/Controls/pgm-setchild) mensagem, que é descrita no SDK do Windows.  
  
 Esse método não altera o pai da janela contida; Ele apenas atribui um identificador de janela para o controle de paginação para rolagem. Na maioria dos casos, a janela contida será uma janela filho do controle de pager.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir cria um controle de paginação, em seguida, usa o [CPagerCtrl::SetChild](#setchild) método para associar um controle de botão muito com o controle de paginação. O exemplo usa o [CPagerCtrl::SetButtonSize](#setbuttonsize) método para definir a altura do controle de pager a 20 pixels e o [CPagerCtrl::SetBorder](#setborder) método para definir a espessura da borda de 1 pixel.  
  
 [!code-cpp[NVC_MFC_CSplitButton_s2#1](../../mfc/reference/codesnippet/cpp/cpagerctrl-class_1.cpp)]  
  
##  <a name="setscrollpos"></a>  CPagerCtrl::SetScrollPos  
 Define a posição de rolagem do controle de pager atual.  
  
```  
void SetScrollPos(int iPos);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *iPos*|A nova posição de rolagem, medida em pixels.|  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PGM_SETPOS](/windows/desktop/Controls/pgm-setpos) mensagem, que é descrita no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CPagerCtrl](../../mfc/reference/cpagerctrl-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Controles de paginação](/windows/desktop/Controls/pager-controls)



