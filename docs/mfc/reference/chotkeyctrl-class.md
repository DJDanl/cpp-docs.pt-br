---
title: Classe CHotKeyCtrl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CHotKeyCtrl
- AFXCMN/CHotKeyCtrl
- AFXCMN/CHotKeyCtrl::CHotKeyCtrl
- AFXCMN/CHotKeyCtrl::Create
- AFXCMN/CHotKeyCtrl::CreateEx
- AFXCMN/CHotKeyCtrl::GetHotKey
- AFXCMN/CHotKeyCtrl::GetHotKeyName
- AFXCMN/CHotKeyCtrl::GetKeyName
- AFXCMN/CHotKeyCtrl::SetHotKey
- AFXCMN/CHotKeyCtrl::SetRules
dev_langs:
- C++
helpviewer_keywords:
- hot key controls
- CHotKeyCtrl class
- Windows common controls [C++], CHotKeyCtrl
ms.assetid: 896f9766-0718-4f58-aab2-20325e118ca6
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
ms.openlocfilehash: cbcc720d2b934cde9f8beb9bb95499d9cc569413
ms.lasthandoff: 02/25/2017

---
# <a name="chotkeyctrl-class"></a>Classe CHotKeyCtrl
Fornece a funcionalidade de controle do Windows comuns hot chave.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CHotKeyCtrl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHotKeyCtrl::CHotKeyCtrl](#chotkeyctrl)|Constrói um objeto `CHotKeyCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CHotKeyCtrl::Create](#create)|Cria um controle de chave de acesso e a anexa a um `CHotKeyCtrl` objeto.|  
|[CHotKeyCtrl::CreateEx](#createex)|Cria um controle de chave de acesso com os estilos estendidos do Windows especificados e a anexa a um `CHotKeyCtrl` objeto.|  
|[CHotKeyCtrl::GetHotKey](#gethotkey)|Recupera os virtual sinalizadores principais de código e modificador de uma tecla de acesso de um controle de chave de acesso.|  
|[CHotKeyCtrl::GetHotKeyName](#gethotkeyname)|Recupera o nome da chave, no conjunto de caracteres local, atribuído a uma tecla de acesso.|  
|[CHotKeyCtrl::GetKeyName](#getkeyname)|Recupera o nome da chave, no conjunto de caracteres local, com o código de tecla virtual especificado.|  
|[CHotKeyCtrl::SetHotKey](#sethotkey)|Define a combinação de teclas de acesso para um controle de chave de acesso.|  
|[CHotKeyCtrl::SetRules](#setrules)|Define as combinações inválidas e a combinação de modificador padrão para um controle de chave de acesso.|  
  
## <a name="remarks"></a>Comentários  
 Um "principais controle de acesso" é uma janela que permite que o usuário crie uma tecla de acesso. Uma "tecla de acesso" é uma combinação de teclas que o usuário pode pressionar para executar uma ação rapidamente. (Por exemplo, um usuário pode criar uma tecla de acesso que ativa uma determinada janela e a coloca na parte superior da ordem Z.) O controle de chave de acesso exibe as opções do usuário e garante que o usuário seleciona uma combinação de chave válida.  
  
 Esse controle (e, portanto, a `CHotKeyCtrl` classe) está disponível apenas para programas em execução na versão do Windows 95/98 e Windows NT 3.51 e posterior.  
  
 Quando o usuário escolher uma combinação de teclas, o aplicativo pode recuperar a combinação de teclas especificada do controle e usar o **WM_SETHOTKEY** mensagem para configurar a tecla de acesso no sistema. Sempre que o usuário pressiona a tecla de acesso daí em diante, de qualquer parte do sistema, a janela especificada no **WM_SETHOTKEY** mensagem recebe um `WM_SYSCOMMAND` mensagem especificando **SC_HOTKEY**. Essa mensagem ativa a janela que recebe. A tecla de acesso permanece válida até o aplicativo que chamou **WM_SETHOTKEY** sai.  
  
 Esse mecanismo é diferente do suporte chave ativo que depende do **WM_HOTKEY** mensagem e o Windows [RegisterHotKey](http://msdn.microsoft.com/library/windows/desktop/ms646309) e [UnregisterHotKey](http://msdn.microsoft.com/library/windows/desktop/ms646327) funções.  
  
 Para obter mais informações sobre como usar o `CHotKeyCtrl`, consulte [controles](../../mfc/controls-mfc.md) e [CHotKeyCtrl usando](../../mfc/using-chotkeyctrl.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CHotKeyCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn.h  
  
##  <a name="chotkeyctrl"></a>CHotKeyCtrl::CHotKeyCtrl  
 Constrói um objeto `CHotKeyCtrl`.  
  
```  
CHotKeyCtrl();
```  
  
##  <a name="create"></a>CHotKeyCtrl::Create  
 Cria um controle de chave de acesso e a anexa a um `CHotKeyCtrl` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Especifica o estilo do controle chave ativa. Aplique qualquer combinação de estilos de controle. Consulte [estilos de controle comum](http://msdn.microsoft.com/library/windows/desktop/bb775498) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter mais informações.  
  
 `rect`  
 Especifica o tamanho e a posição do controle de tecla ativo. Ele pode ser um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou um [estrutura RECT](../../mfc/reference/rect-structure1.md).  
  
 `pParentWnd`  
 Especifica o hot chave janela pai do controle, geralmente um [CDialog](../../mfc/reference/cdialog-class.md). Ele não deve ser **nulo**.  
  
 `nID`  
 Especifica a identificação. do controle de chave ativa  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero, se a inicialização foi bem sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você construir um `CHotKeyCtrl` objeto em duas etapas. Primeiro, chame o construtor e, em seguida, chame **criar**, que cria o controle de chave de acesso e anexa-o para o `CHotKeyCtrl` objeto.  
  
 Se você quiser usar estilos estendidos do windows com o controle, chame [CreateEx](#createex) em vez de **criar**.  
  
##  <a name="createex"></a>CHotKeyCtrl::CreateEx  
 Chame essa função para criar um controle (uma janela filho) e associá-lo a `CHotKeyCtrl` objeto.  
  
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
 Especifica o estilo do controle chave ativa. Aplique qualquer combinação de estilos de controle. Para obter mais informações, consulte [estilos de controle comum](http://msdn.microsoft.com/library/windows/desktop/bb775498) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
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
  
##  <a name="gethotkey"></a>CHotKeyCtrl::GetHotKey  
 Recupera os virtual sinalizadores principais de código e modificador de um atalho de teclado de um controle de chave de acesso.  
  
```  
DWORD GetHotKey() const;  
  
void GetHotKey(
    WORD& wVirtualKeyCode,  
    WORD& wModifiers) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `wVirtualKeyCode`  
 Código de tecla virtual do atalho de teclado. Para obter uma lista de códigos de tecla virtuais padrão, consulte WinUser. h.  
  
 [out] `wModifiers`  
 Uma combinação bit a bit (OR) de sinalizadores que indicam as teclas modificadoras o atalho de teclado.  
  
 Os sinalizadores de modificador são da seguinte maneira:  
  
|Sinalizador|Chave correspondente|  
|----------|-----------------------|  
|`HOTKEYF_ALT`|tecla ALT|  
|`HOTKEYF_CONTROL`|Tecla CTRL|  
|`HOTKEYF_EXT`|Chave estendida|  
|`HOTKEYF_SHIFT`|Tecla SHIFT|  
  
### <a name="return-value"></a>Valor de retorno  
 O primeiro método, sobrecarregado um `DWORD` que contém os sinalizadores de código e modificador chave virtual. O byte de ordem inferior da palavra de ordem inferior contém o código de tecla virtual, o byte de ordem superior da palavra de ordem inferior contém os sinalizadores de modificador e a palavra de ordem superior for zero.  
  
### <a name="remarks"></a>Comentários  
 O código de tecla virtual e as teclas modificadoras juntas definem o atalho de teclado.  
  
##  <a name="gethotkeyname"></a>CHotKeyCtrl::GetHotKeyName  
 Chame essa função de membro para obter o nome localizado da tecla de acesso.  
  
```  
CString GetHotKeyName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome localizado da chave de acesso selecionado no momento. Se não houver nenhuma tecla de acesso selecionada, `GetHotKeyName` retorna uma cadeia de caracteres vazia.  
  
### <a name="remarks"></a>Comentários  
 O nome que essa função membro retorna vem do driver de teclado. Você pode instalar um driver de teclado não localizado em uma versão localizada do Windows e vice-versa.  
  
##  <a name="getkeyname"></a>CHotKeyCtrl::GetKeyName  
 Chame essa função de membro para obter o nome localizado da chave atribuída a um código de tecla virtual especificado.  
  
```  
static CString GetKeyName(
    UINT vk,  
    BOOL fExtended);
```  
  
### <a name="parameters"></a>Parâmetros  
 `vk`  
 O código de tecla virtual.  
  
 *fExtended*  
 Se o código de tecla virtual é uma chave estendida, **TRUE**; caso contrário, **FALSE**.  
  
### <a name="return-value"></a>Valor de retorno  
 O nome localizado da chave especificada pelo `vk` parâmetro. Se a chave não tem nenhum nome mapeado, `GetKeyName` retorna uma cadeia de caracteres vazia.  
  
### <a name="remarks"></a>Comentários  
 O nome da chave que esta função retorna vem do driver de teclado, para que você pode instalar um driver de teclado não localizado em uma versão localizada do Windows e vice-versa.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCControlLadenDialog&#69;](../../mfc/codesnippet/cpp/chotkeyctrl-class_1.cpp)]  
  
##  <a name="sethotkey"></a>CHotKeyCtrl::SetHotKey  
 Define o atalho de teclado para um controle de chave de acesso.  
  
```  
void SetHotKey(
    WORD wVirtualKeyCode,  
    WORD wModifiers);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `wVirtualKeyCode`  
 Código de tecla virtual do atalho de teclado. Para obter uma lista de códigos de tecla virtuais padrão, consulte WinUser. h.  
  
 [in] `wModifiers`  
 Uma combinação bit a bit (OR) de sinalizadores que indicam as teclas modificadoras o atalho de teclado.  
  
 Os sinalizadores de modificador são da seguinte maneira:  
  
|Sinalizador|Chave correspondente|  
|----------|-----------------------|  
|`HOTKEYF_ALT`|tecla ALT|  
|`HOTKEYF_CONTROL`|Tecla CTRL|  
|`HOTKEYF_EXT`|Chave estendida|  
|`HOTKEYF_SHIFT`|Tecla SHIFT|  
  
### <a name="remarks"></a>Comentários  
 O código de tecla virtual e as teclas modificadoras juntas definem o atalho de teclado.  
  
##  <a name="setrules"></a>CHotKeyCtrl::SetRules  
 Chame essa função para definir as combinações inválidas e a combinação de modificador padrão para um controle de chave de acesso.  
  
```  
void SetRules(
    WORD wInvalidComb,  
    WORD wModifiers);
```  
  
### <a name="parameters"></a>Parâmetros  
 `wInvalidComb`  
 Matriz de sinalizadores que especifica combinações de chave inválidas. Pode ser uma combinação dos seguintes valores:  
  
- `HKCOMB_A`ALT  
  
- `HKCOMB_C`CTRL  
  
- `HKCOMB_CA`CTRL + ALT  
  
- `HKCOMB_NONE`Chaves não modificadas  
  
- `HKCOMB_S`SHIFT  
  
- `HKCOMB_SA`SHIFT + ALT  
  
- `HKCOMB_SC`SHIFT + CTRL  
  
- `HKCOMB_SCA`SHIFT + CTRL + ALT  
  
 `wModifiers`  
 Matriz de sinalizadores que especifica a combinação de teclas para usar quando o usuário insere uma combinação inválida. Para obter mais informações sobre os sinalizadores de modificador, consulte [GetHotKey](#gethotkey).  
  
### <a name="remarks"></a>Comentários  
 Quando um usuário insere uma combinação de chave inválida, conforme definido pelos sinalizadores especificados na `wInvalidComb`, o sistema usa o operador OR para combinar as chaves inseridas pelo usuário com os sinalizadores especificados na `wModifiers`. A combinação de teclas resultante é convertida em uma cadeia de caracteres e exibida no controle de chave de acesso.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)




