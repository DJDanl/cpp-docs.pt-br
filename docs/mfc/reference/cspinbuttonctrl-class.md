---
title: Classe CSpinButtonCtrl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSpinButtonCtrl
dev_langs:
- C++
helpviewer_keywords:
- Windows common controls [C++], CSpinButtonCtrl
- CSpinButtonCtrl class
- CSpinButtonCtrl class, common controls
- up-down controls, spin button control
- spin button control
ms.assetid: 509bfd76-1c5a-4af6-973f-e133c0b87734
caps.latest.revision: 23
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
ms.openlocfilehash: 486a0842ed04f0e760bbb332986a97a35ce9851f
ms.lasthandoff: 02/25/2017

---
# <a name="cspinbuttonctrl-class"></a>Classe CSpinButtonCtrl
Fornece a funcionalidade do controle de botão de rotação comuns do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSpinButtonCtrl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSpinButtonCtrl::CSpinButtonCtrl](#cspinbuttonctrl)|Constrói um objeto `CSpinButtonCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSpinButtonCtrl::Create](#create)|Cria um controle de botão de rotação e a anexa a um `CSpinButtonCtrl` objeto.|  
|[CSpinButtonCtrl::CreateEx](#createex)|Cria um controle de botão de rotação com os estilos estendidos do Windows especificados e a anexa a um `CSpinButtonCtrl` objeto.|  
|[CSpinButtonCtrl::GetAccel](#getaccel)|Recupera informações de aceleração para um controle de botão de rotação.|  
|[CSpinButtonCtrl::GetBase](#getbase)|Recupera a base atual para um controle de botão de rotação.|  
|[CSpinButtonCtrl::GetBuddy](#getbuddy)|Recupera um ponteiro para a janela atual do amigo.|  
|[CSpinButtonCtrl::GetPos](#getpos)|Recupera a posição atual de um controle de botão de rotação.|  
|[CSpinButtonCtrl::GetRange](#getrange)|Recupera os limites superiores e inferiores (intervalo) para um controle de botão de rotação.|  
|[CSpinButtonCtrl::SetAccel](#setaccel)|Define a aceleração de um controle de botão de rotação.|  
|[CSpinButtonCtrl::SetBase](#setbase)|Define a base para um controle de botão de rotação.|  
|[CSpinButtonCtrl::SetBuddy](#setbuddy)|Define a janela de amigo para um controle de botão de rotação.|  
|[CSpinButtonCtrl::SetPos](#setpos)|Define a posição atual do controle.|  
|[CSpinButtonCtrl::SetRange](#setrange)|Define os limites superiores e inferiores (intervalo) para um controle de botão de rotação.|  
  
## <a name="remarks"></a>Comentários  
 Um "botão controle de rotação" (também conhecido como um controle de cima para baixo) é um par de botões de seta para que o usuário pode clicar para incrementar ou decrementar um valor, como uma posição de rolagem ou um número exibido em um controle complementar. O valor associado a um controle de botão de rotação é chamado de sua posição atual. Um controle de botão de rotação é geralmente usado com um controle complementar, chamado de "janela buddy".  
  
 Esse controle (e, portanto, a `CSpinButtonCtrl` classe) está disponível apenas para programas em execução na versão do Windows 95/98 e Windows NT 3.51 e posterior.  
  
 Para o usuário, um controle de botão de rotação e sua janela buddy muitas vezes parecer um único controle. Você pode especificar que um controle de botão de rotação automaticamente se posiciona ao lado de sua janela de amigo e que ele definido automaticamente a legenda da janela buddy na posição atual. Você pode usar um controle de botão de rotação com um controle de edição para avisar o usuário para a entrada numérica.  
  
 Clicando na seta para cima move a posição atual para o máximo e clicar na seta para baixo move a posição atual para o mínimo. Por padrão, o mínimo é de 100 e o máximo é de 0. Sempre que a configuração mínima é maior que o máximo de configuração (por exemplo, quando são usadas as configurações padrão), clicando no diminui seta para cima o valor da posição e clicando na seta para baixo aumenta.  
  
 Um controle de botão de rotação sem uma janela buddy funciona como uma espécie de barra de rolagem simplificada. Por exemplo, um controle de guia, às vezes, exibe um controle de botão de rotação para permitir que o usuário rolar guias adicionais no modo de exibição.  
  
 Para obter mais informações sobre como usar o `CSpinButtonCtrl`, consulte [controles](../../mfc/controls-mfc.md) e [CSpinButtonCtrl usando](../../mfc/using-cspinbuttonctrl.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CSpinButtonCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn.h  
  
##  <a name="a-namecreatea--cspinbuttonctrlcreate"></a><a name="create"></a>CSpinButtonCtrl::Create  
 Cria um controle de botão de rotação e a anexa a um `CSpinButtonCtrl` objeto...  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Especifica o estilo do controle de botão de rotação. Aplica qualquer combinação de estilos de controle de botão de rotação para o controle. Esses estilos são descritos em [estilos de controle para cima para baixo](http://msdn.microsoft.com/library/windows/desktop/bb759885) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `rect`  
 Especifica o tamanho e a posição do controle de botão de rotação. Ele pode ser um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura  
  
 `pParentWnd`  
 Um ponteiro para a janela do pai do controle de botão de rotação, geralmente um `CDialog`. Ele não deve ser **nulo.**  
  
 `nID`  
 Especifica a ID. do controle de botão de rotação  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a inicialização foi bem sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você construir um `CSpinButtonCtrl` objeto em duas etapas, primeiro, chame o construtor e, em seguida, chame **criar**, que cria o controle de botão de rotação e anexa-o para o `CSpinButtonCtrl` objeto.  
  
 Para criar um controle de botão de rotação com estilos de janela estendidos, chame [CSpinButtonCtrl::CreateEx](#createex) em vez de **criar**.  
  
##  <a name="a-namecreateexa--cspinbuttonctrlcreateex"></a><a name="createex"></a>CSpinButtonCtrl::CreateEx  
 Cria um controle (uma janela filho) e o associa a `CSpinButtonCtrl` objeto.  
  
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
 Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista dos estilos estendidos do windows, consulte o `dwExStyle` parâmetro [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `dwStyle`  
 Especifica o estilo do controle de botão de rotação. Aplica qualquer combinação de estilos de controle de botão de rotação para o controle. Esses estilos são descritos em [estilos de controle para cima para baixo](http://msdn.microsoft.com/library/windows/desktop/bb759885) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `rect`  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que descreve o tamanho e a posição da janela deve ser criada, nas coordenadas do cliente de `pParentWnd`.  
  
 `pParentWnd`  
 Um ponteiro para a janela que é o pai do controle.  
  
 `nID`  
 ID da janela filho. do controle  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use `CreateEx` em vez de [criar](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido Windows **WS_EX_**.  
  
##  <a name="a-namecspinbuttonctrla--cspinbuttonctrlcspinbuttonctrl"></a><a name="cspinbuttonctrl"></a>CSpinButtonCtrl::CSpinButtonCtrl  
 Constrói um objeto `CSpinButtonCtrl`.  
  
```  
CSpinButtonCtrl();
```  
  
##  <a name="a-namegetaccela--cspinbuttonctrlgetaccel"></a><a name="getaccel"></a>CSpinButtonCtrl::GetAccel  
 Recupera informações de aceleração para um controle de botão de rotação.  
  
```  
UINT GetAccel(
    int nAccel,  
    UDACCEL* pAccel) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nAccel`  
 Número de elementos na matriz especificada pelo `pAccel`.  
  
 `pAccel`  
 Ponteiro para uma matriz de [UDACCEL](http://msdn.microsoft.com/library/windows/desktop/bb759897) estruturas que recebe informações de aceleração.  
  
### <a name="return-value"></a>Valor de retorno  
 Número de estruturas de acelerador recuperados.  
  
##  <a name="a-namegetbasea--cspinbuttonctrlgetbase"></a><a name="getbase"></a>CSpinButtonCtrl::GetBase  
 Recupera a base atual para um controle de botão de rotação.  
  
```  
UINT GetBase() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor base atual.  
  
##  <a name="a-namegetbuddya--cspinbuttonctrlgetbuddy"></a><a name="getbuddy"></a>CSpinButtonCtrl::GetBuddy  
 Recupera um ponteiro para a janela atual do amigo.  
  
```  
CWnd* GetBuddy() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a janela atual do amigo.  
  
##  <a name="a-namegetposa--cspinbuttonctrlgetpos"></a><a name="getpos"></a>CSpinButtonCtrl::GetPos  
 Recupera a posição atual de um controle de botão de rotação.  
  
```  
int GetPos() const;  int GetPos32(LPBOOL lpbError = NULL) const;  ```  
  
### Parameters  
 *lpbError*  
 A pointer to a boolean value that is set to zero if the value is successfully retrieved or non-zero if an error occurs. If this parameter is set to **NULL**, errors are not reported.  
  
### Return Value  
 The first version returns the 16-bit current position in the low-order word. The high-order word is nonzero if an error occurred.  
  
 The second version returns the 32-bit position.  
  
### Remarks  
 When it processes the value returned, the control updates its current position based on the caption of the buddy window. The control returns an error if there is no buddy window or if the caption specifies an invalid or out-of-range value.  
  
##  <a name="getrange"></a>  CSpinButtonCtrl::GetRange  
 Retrieves the upper and lower limits (range) for a spin button control.  
  
```  
DWORD GetRange() const;  
  
void GetRange (int < / inferior,  
    int < / superior) const;  
  
void GetRange32 (int < / inferior,  
    int < / superior) const;  
```  
  
### Parameters  
 *lower*  
 Reference to an integer that receives the lower limit for the control.  
  
 *upper*  
 Reference to an integer that receives the upper limit for the control.  
  
### Return Value  
 The first version returns a 32-bit value containing the upper and lower limits. The low-order word is the upper limit for the control, and the high-order word is the lower limit.  
  
### Remarks  
 The member function `GetRange32` retrieves the spin button control's range as a 32-bit integer.  
  
##  <a name="setaccel"></a>  CSpinButtonCtrl::SetAccel  
 Sets the acceleration for a spin button control.  
  
```  
BOOL SetAccel (int nAccel,  
    UDACCEL* pAccel);
```  
  
### Parameters  
 `nAccel`  
 Number of [UDACCEL](http://msdn.microsoft.com/library/windows/desktop/bb759897) structures specified by `pAccel`.  
  
 `pAccel`  
 Pointer to an array of `UDACCEL` structures, which contain acceleration information. Elements should be sorted in ascending order based on the **nSec** member.  
  
### Return Value  
 Nonzero if successful; otherwise 0.  
  
##  <a name="setbase"></a>  CSpinButtonCtrl::SetBase  
 Sets the base for a spin button control.  
  
```  
int SetBase (int nBase);
```  
  
### Parameters  
 `nBase`  
 New base value for the control. It can be 10 for decimal or 16 for hexadecimal.  
  
### Return Value  
 The previous base value if successful, or zero if an invalid base is given.  
  
### Remarks  
 The base value determines whether the buddy window displays numbers in decimal or hexadecimal digits. Hexadecimal numbers are always unsigned; decimal numbers are signed.  
  
##  <a name="setbuddy"></a>  CSpinButtonCtrl::SetBuddy  
 Sets the buddy window for a spin button control.  
  
```  
CWnd* SetBuddy (CWnd* pWndBuddy);
```  
  
### Parameters  
 `pWndBuddy`  
 Pointer to the new buddy window.  
  
### Return Value  
 A pointer to the previous buddy window.  
  
### Remarks  
 A spin control is almost always associated with another window, such as an edit control, that displays some content. This other window is called the "buddy" of the spin control.  
  
##  <a name="setpos"></a>  CSpinButtonCtrl::SetPos  
 Sets the current position for a spin button control.  
  
```  
int SetPos (int nPos);  
int SetPos32(int nPos);
```  
  
### Parameters  
 `nPos`  
 New position for the control. This value must be in the range specified by the upper and lower limits for the control.  
  
### Return Value  
 The previous position (16-bit precision for `SetPos`, 32-bit precision for `SetPos32`).  
  
### Remarks  
 `SetPos32` sets the 32-bit position.  
  
##  <a name="setrange"></a>  CSpinButtonCtrl::SetRange  
 Sets the upper and lower limits (range) for a spin button control.  
  
```  
SetRange void (nLower curto,  
    nUpper curto);

 
void SetRange32 (int nLower,  
    int nUpper);
```  
  
### Parameters  
 `nLower`and `nUpper`  
 Upper and lower limits for the control. For `SetRange`, neither limit can be greater than **UD_MAXVAL** or less than **UD_MINVAL**; in addition, the difference between the two limits cannot exceed **UD_MAXVAL**. `SetRange32` places no restrictions on the limits; use any integers.  
  
### Remarks  
 The member function `SetRange32` sets the 32-bit range for the spin button control.  
  
> [!NOTE]
>  The default range for the spin button has the maximum set to zero (0) and the minimum set to 100. Because the maximum value is less than the minimum value, clicking the up arrow will decrease the position and clicking the down arrow will increase it. Use `CSpinButtonCtrl::SetRange` to adjust these values.  
  
## See Also  
 [MFC Sample CMNCTRL2](../../visual-cpp-samples.md)   
 [CWnd Class](../../mfc/reference/cwnd-class.md)   
 [Hierarchy Chart](../../mfc/hierarchy-chart.md)   
 [CSliderCtrl Class](../../mfc/reference/csliderctrl-class.md)

