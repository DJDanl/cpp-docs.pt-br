---
title: Classe CProgressCtrl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CProgressCtrl
- AFXCMN/CProgressCtrl
- AFXCMN/CProgressCtrl::CProgressCtrl
- AFXCMN/CProgressCtrl::Create
- AFXCMN/CProgressCtrl::CreateEx
- AFXCMN/CProgressCtrl::GetBarColor
- AFXCMN/CProgressCtrl::GetBkColor
- AFXCMN/CProgressCtrl::GetPos
- AFXCMN/CProgressCtrl::GetRange
- AFXCMN/CProgressCtrl::GetState
- AFXCMN/CProgressCtrl::GetStep
- AFXCMN/CProgressCtrl::OffsetPos
- AFXCMN/CProgressCtrl::SetBarColor
- AFXCMN/CProgressCtrl::SetBkColor
- AFXCMN/CProgressCtrl::SetMarquee
- AFXCMN/CProgressCtrl::SetPos
- AFXCMN/CProgressCtrl::SetRange
- AFXCMN/CProgressCtrl::SetState
- AFXCMN/CProgressCtrl::SetStep
- AFXCMN/CProgressCtrl::StepIt
dev_langs:
- C++
helpviewer_keywords:
- CProgressCtrl class
- progress controls [C++], CProgressCtrl class
- Internet Explorer 4.0 common controls
ms.assetid: 222630f4-1598-4026-8198-51649b1192ab
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
ms.sourcegitcommit: 3d045736f9a54d344c67e3f7408198e65a0bc95f
ms.openlocfilehash: a5c006087cb4ca5482ed8c14750686389ddeef68
ms.lasthandoff: 03/29/2017

---
# <a name="cprogressctrl-class"></a>Classe CProgressCtrl
Fornece a funcionalidade de controle de barra de progresso comuns do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CProgressCtrl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CProgressCtrl::CProgressCtrl](#cprogressctrl)|Constrói um objeto `CProgressCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CProgressCtrl::Create](#create)|Cria um controle de barra de progresso e a anexa a um `CProgressCtrl` objeto.|  
|[CProgressCtrl::CreateEx](#createex)|Cria um controle de progresso com os estilos estendidos do Windows especificados e anexa-o para um `CProgressCtrl` objeto.|  
|[CProgressCtrl::GetBarColor](#getbarcolor)|Obtém a cor da barra do indicador de progresso para o controle de barra de andamento atual.|  
|[CProgressCtrl::GetBkColor](#getbkcolor)|Obtém a cor do plano de fundo da barra de andamento atual.|  
|[CProgressCtrl::GetPos](#getpos)|Obtém a posição atual da barra de progresso.|  
|[CProgressCtrl::GetRange](#getrange)|Obtém os limites inferiores e superiores do intervalo de controle de barra de progresso.|  
|[CProgressCtrl::GetState](#getstate)|Obtém o estado do controle de barra de andamento atual.|  
|[CProgressCtrl::GetStep](#getstep)|Recupera o incremento de etapa para a barra de progresso do controle de barra de andamento atual.|  
|[CProgressCtrl::OffsetPos](#offsetpos)|Avança a posição atual de um controle de barra de progresso em um incremento especificado e redesenha a barra para refletir a nova posição.|  
|[CProgressCtrl::SetBarColor](#setbarcolor)|Define a cor da barra do indicador de progresso no controle de barra de andamento atual.|  
|[CProgressCtrl::SetBkColor](#setbkcolor)|Define a cor de plano de fundo para a barra de progresso.|  
|[CProgressCtrl::SetMarquee](#setmarquee)|Ativa o modo de marca de seleção Ativar ou desativar para o controle de barra de andamento atual.|  
|[CProgressCtrl::SetPos](#setpos)|Define a posição atual de um controle de barra de progresso e redesenha a barra para refletir a nova posição.|  
|[CProgressCtrl::SetRange](#setrange)|Define o intervalo mínimo e máximo para um controle de barra de progresso e redesenha a barra para refletir os novos intervalos.|  
|[CProgressCtrl::SetState](#setstate)|Define o estado do controle de barra de andamento atual.|  
|[CProgressCtrl::SetStep](#setstep)|Especifica o incremento de etapa de um controle de barra de progresso.|  
|[CProgressCtrl::StepIt](#stepit)|Avança a posição atual para um controle de barra de progresso, o incremento de etapa (consulte [SetStep](#setstep)) e redesenha a barra para refletir a nova posição.|  
  
## <a name="remarks"></a>Comentários  
 Um controle de barra de progresso é uma janela que um aplicativo pode usar para indicar o progresso de uma operação demorada. Ele consiste em um retângulo que é preenchido, da esquerda para a direita com o sistema de cor de realce como uma operação progride.  
  
 Um controle de barra de progresso tem um intervalo e a posição atual. O intervalo representa a duração total da operação e a posição atual representa o progresso que do aplicativo fez para concluir a operação. O procedimento de janela usa o intervalo e a posição atual para determinar a porcentagem da barra de progresso para preencher com a cor de realce. Porque o intervalo e os valores de posição atuais são expressas como inteiros com sinal, o intervalo de valores de posição atual possível é de -2.147.483.648 a 2.147.483.647 inclusivo.  
  
 Para obter mais informações sobre como usar `CProgressCtrl`, consulte [controles](../../mfc/controls-mfc.md) e [usando CProgressCtrl](../../mfc/using-cprogressctrl.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CProgressCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn.h  
  
##  <a name="cprogressctrl"></a>CProgressCtrl::CProgressCtrl  
 Constrói um objeto `CProgressCtrl`.  
  
```  
CProgressCtrl();
```  
  
### <a name="remarks"></a>Comentários  
 Após a criação de `CProgressCtrl` de objeto, chame `CProgressCtrl::Create` para criar o controle de barra de progresso.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CProgressCtrl n º 1](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_1.cpp)]  
  
##  <a name="create"></a>CProgressCtrl::Create  
 Cria um controle de barra de progresso e a anexa a um `CProgressCtrl` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Especifica o estilo do controle de barra de progresso. Aplicar qualquer combinação de janela stylesdescribed em [CreateWindow](http://msdn.microsoft.com/library/windows/desktop/ms632679) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)], além de barra estilos de controle, o controle de progresso seguinte:  
  
- `PBS_VERTICAL`Exibe informações de andamento verticalmente, de cima para baixo. Sem esse sinalizador, o controle de barra de progresso exibe horizontalmente, da esquerda para a direita.  
  
- `PBS_SMOOTH`Exibe gradual, smooth preencher o controle de barra de progresso. Sem esse sinalizador, o controle será preenchido com blocos.  
  
 `rect`  
 Especifica o tamanho e a posição do controle de barra de progresso. Ele pode ser um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura. Como o controle deve ser uma janela filho, as coordenadas especificadas são relativas à área do cliente do `pParentWnd`.  
  
 `pParentWnd`  
 Especifica o andamento da barra janela do pai do controle, geralmente um `CDialog`. Ele não deve ser **nulo.**  
  
 `nID`  
 Especifica a ID. do controle de barra de progresso  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se o `CProgressCtrl` objeto é criado com êxito; caso contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Você pode criar um `CProgressCtrl` objeto em duas etapas. Primeiro, chame o construtor, que cria o `CProgressCtrl` do objeto e, em seguida, chame **criar**, que cria o controle de barra de progresso.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CProgressCtrl n º 2](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_2.cpp)]  
  
##  <a name="createex"></a>CProgressCtrl::CreateEx  
 Cria um controle (uma janela filho) e o associa a `CProgressCtrl` objeto.  
  
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
 Especifica o estilo do controle de barra de progresso. Aplique qualquer combinação de estilos de janela descritos na [CreateWindow](http://msdn.microsoft.com/library/windows/desktop/ms632679) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `rect`  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que descreve o tamanho e a posição da janela deve ser criada, nas coordenadas do cliente de `pParentWnd`.  
  
 `pParentWnd`  
 Um ponteiro para a janela que é o pai do controle.  
  
 `nID`  
 ID de janela filho. do controle  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use `CreateEx` em vez de [criar](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.  
  
##  <a name="getbarcolor"></a>CProgressCtrl::GetBarColor  
 Obtém a cor da barra do indicador de progresso para o controle de barra de andamento atual.  
  
```  
COLORREF GetBarColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A cor da barra de andamento atual, representado como um [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor, ou `CLR_DEFAULT` se a cor de barra do indicador de progresso é a cor padrão.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PBM_GETBARCOLOR](http://msdn.microsoft.com/library/windows/desktop/bb760826) mensagem, que é descrita a [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getbkcolor"></a>CProgressCtrl::GetBkColor  
 Obtém a cor do plano de fundo da barra de andamento atual.  
  
```  
COLORREF GetBkColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A cor de plano de fundo da barra de andamento atual, representado como um [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PBM_GETBKCOLOR](http://msdn.microsoft.com/library/windows/desktop/bb760828) mensagem, que é descrita a [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="getpos"></a>CProgressCtrl::GetPos  
 Recupera a posição atual da barra de progresso.  
  
```  
int GetPos();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A posição do controle da barra de progresso.  
  
### <a name="remarks"></a>Comentários  
 A posição do controle de barra de progresso não é o local físico da tela, mas em vez disso, entre a parte superior e inferior intervalo indicado em [SetRange](#setrange).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CProgressCtrl n º 3](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_3.cpp)]  
  
##  <a name="getrange"></a>CProgressCtrl::GetRange  
 Obtém o atuais limites superiores e inferiores ou intervalo do controle de barra de progresso.  
  
```  
void GetRange(
    int& nLower,  
    int& nUpper);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nLower`  
 Uma referência a um número inteiro recebendo o limite inferior do controle de barra de progresso.  
  
 `nUpper`  
 Uma referência a um número inteiro recebendo o limite superior do controle de barra de progresso.  
  
### <a name="remarks"></a>Comentários  
 Esta função copia os valores dos limites superiores e inferiores para inteiros referenciados por `nLower` e `nUpper`, respectivamente.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CProgressCtrl n º 4](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_4.cpp)]  
  
##  <a name="getstate"></a>CProgressCtrl::GetState  
 Obtém o estado do controle de barra de andamento atual.  
  
```  
int GetState() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O estado do controle de barra de andamento atual, que é um dos seguintes valores:  
  
|Valor|Estado|  
|-----------|-----------|  
|`PBST_NORMAL`|Em andamento|  
|`PBST_ERROR`|Erro|  
|`PBST_PAUSED`|Paused|  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PBM_GETSTATE](http://msdn.microsoft.com/library/windows/desktop/bb760834) mensagem, que é descrita a [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_progressCtrl`, que é usado para acessar programaticamente o controle de barra de progresso. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CProgressCtrl_s1 n º 9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_5.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir recupera o estado do controle de barra de andamento atual.  
  
 [!code-cpp[NVC_MFC_CProgressCtrl_s1 n º 5](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_6.cpp)]  
  
##  <a name="getstep"></a>CProgressCtrl::GetStep  
 Recupera o incremento de etapa para a barra de progresso do controle de barra de andamento atual.  
  
```  
int GetStep() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O incremento de etapa da barra de progresso.  
  
### <a name="remarks"></a>Comentários  
 O incremento de etapa é a quantidade pela qual uma chamada para [CProgressCtrl::StepIt](#stepit) aumenta a posição atual da barra de progresso.  
  
 Esse método envia o [PBM_GETSTEP](http://msdn.microsoft.com/library/windows/desktop/bb760836) mensagem, que é descrita a [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_progressCtrl`, que é usado para acessar programaticamente o controle de barra de progresso. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CProgressCtrl_s1 n º 9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_5.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir recupera o incremento de etapa do controle de barra de andamento atual.  
  
 [!code-cpp[NVC_MFC_CProgressCtrl_s1 n º 3](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_7.cpp)]  
  
##  <a name="offsetpos"></a>CProgressCtrl::OffsetPos  
 Avança o progresso da posição atual do controle, o incremento especificado pelo `nPos` e redesenha a barra para refletir a nova posição.  
  
```  
int OffsetPos(int nPos);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPos`  
 Valor para Avançar a posição.  
  
### <a name="return-value"></a>Valor de retorno  
 A posição anterior do controle da barra de progresso.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CProgressCtrl n º 5](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_8.cpp)]  
  
##  <a name="setbarcolor"></a>CProgressCtrl::SetBarColor  
 Define a cor da barra do indicador de progresso no controle de barra de andamento atual.  
  
```  
COLORREF SetBarColor(COLORREF clrBar);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `clrBar`|Um [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor que especifica a nova cor da barra do indicador de progresso. Especifique `CLR_DEFAULT` para fazer com que a barra de progresso usar a cor padrão.|  
  
### <a name="return-value"></a>Valor de retorno  
 A cor anterior da barra do indicador de progresso, representado como um [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor, ou `CLR_DEFAULT` se a cor da barra do indicador de progresso é o padrão.  
  
### <a name="remarks"></a>Comentários  
 O `SetBarColor` método define o progresso barra se somente cor um [!INCLUDE[windowsver](../../build/reference/includes/windowsver_md.md)] [tema](https://msdn.microsoft.com/library/windows/desktop/hh270423.aspx) não está em vigor.  
  
 Esse método envia o [PBM_SETBARCOLOR](http://msdn.microsoft.com/library/windows/desktop/bb760838) mensagem, que é descrita a [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_progressCtrl`, que é usado para acessar programaticamente o controle de barra de progresso. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CProgressCtrl_s1 n º 9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_5.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir altera a cor da barra de progresso para vermelho, verde, azul ou o padrão.  
  
 [!code-cpp[NVC_MFC_CProgressCtrl_s1 n º 1](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_9.cpp)]  
  
##  <a name="setbkcolor"></a>CProgressCtrl::SetBkColor  
 Define a cor de plano de fundo para a barra de progresso.  
  
```  
COLORREF SetBkColor(COLORREF clrNew);
```  
  
### <a name="parameters"></a>Parâmetros  
 `clrNew`  
 Um **COLORREF** valor que especifica a nova cor do plano de fundo. Especifique o `CLR_DEFAULT` valor para usar a cor de plano de fundo padrão para a barra de progresso.  
  
### <a name="return-value"></a>Valor de retorno  
 O [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor que indica a cor do plano de fundo anterior, ou **CLR_DEFAULT** se a cor do plano de fundo é a cor padrão.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CProgressCtrl 6](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_10.cpp)]  
  
##  <a name="setmarquee"></a>CProgressCtrl::SetMarquee  
 Ativa o modo de marca de seleção Ativar ou desativar para o controle de barra de andamento atual.  
  
```  
BOOL SetMarquee(
    BOOL fMarqueeMode,   
    int nInterval);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `fMarqueeMode`|`true`Para ativar o modo de marca de seleção, ou `false` para desativar o modo de marca de seleção.|  
|[in] `nInterval`|Tempo em milissegundos, entre as atualizações da animação do letreiro.|  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método sempre retorna `true`.  
  
### <a name="remarks"></a>Comentários  
 Quando o modo de marca de seleção está ativado, a barra de progresso é animada e rola como uma entrada em uma marca de seleção de teatro.  
  
 Esse método envia o [PBM_SETMARQUEE](http://msdn.microsoft.com/library/windows/desktop/bb760842) mensagem, que é descrita a [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_progressCtrl`, que é usado para acessar programaticamente o controle de barra de progresso. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CProgressCtrl_s1 n º 9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_5.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir inicia e interrompe o animação de letreiro digital.  
  
 [!code-cpp[NVC_MFC_CProgressCtrl_s1 n º 2](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_11.cpp)]  
  
##  <a name="setpos"></a>CProgressCtrl::SetPos  
 Define o progresso, a posição atual do controle conforme especificado pelas `nPos` e redesenha a barra para refletir a nova posição.  
  
```  
int SetPos(int nPos);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPos`  
 Nova posição do controle de barra de progresso.  
  
### <a name="return-value"></a>Valor de retorno  
 A posição anterior do controle da barra de progresso.  
  
### <a name="remarks"></a>Comentários  
 A posição do controle de barra de progresso não é o local físico da tela, mas em vez disso, entre a parte superior e inferior intervalo indicado em [SetRange](#setrange).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CProgressCtrl #7](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_12.cpp)]  
  
##  <a name="setrange"></a>CProgressCtrl::SetRange  
 Define os limites superiores e inferiores da barra de intervalo do controle de progresso e redesenha a barra para refletir os novos intervalos.  
  
```  
void SetRange(
    short nLower,  
    short nUpper);

 
void SetRange32(
    int nLower,  
    int nUpper);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nLower`  
 Especifica o limite inferior do intervalo (o padrão é zero).  
  
 `nUpper`  
 Especifica o limite superior do intervalo (o padrão é 100).  
  
### <a name="remarks"></a>Comentários  
 A função de membro `SetRange32` define o intervalo de 32 bits para o controle de progresso.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CProgressCtrl n º 8](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_13.cpp)]  
  
##  <a name="setstate"></a>CProgressCtrl::SetState  
 Define o estado do controle de barra de andamento atual.  
  
```  
int SetState(int iState);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `iState`|O estado para definir a barra de progresso. Use um dos seguintes valores:<br /><br /> - `PBST_NORMAL`-Em andamento<br />- `PBST_ERROR`-Erro<br />- `PBST_PAUSED`-Em pausa|  
  
### <a name="return-value"></a>Valor de retorno  
 O estado anterior do controle de barra de andamento atual.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [PBM_SETSTATE](http://msdn.microsoft.com/library/windows/desktop/bb760850) mensagem, que é descrita a [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_progressCtrl`, que é usado para acessar programaticamente o controle de barra de progresso. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CProgressCtrl_s1 n º 9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_5.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define o estado do controle de barra de andamento atual pausado ou em andamento.  
  
 [!code-cpp[NVC_MFC_CProgressCtrl_s1 n º 4](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_14.cpp)]  
  
##  <a name="setstep"></a>CProgressCtrl::SetStep  
 Especifica o incremento de etapa de um controle de barra de progresso.  
  
```  
int SetStep(int nStep);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nStep*  
 Incremento de nova etapa.  
  
### <a name="return-value"></a>Valor de retorno  
 O incremento de etapa anterior.  
  
### <a name="remarks"></a>Comentários  
 O incremento de etapa é a quantidade pela qual uma chamada para `CProgressCtrl::StepIt` aumenta o andamento da barra da posição atual.  
  
 O incremento de etapa de padrão é 10.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CProgressCtrl n º 9](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_15.cpp)]  
  
##  <a name="stepit"></a>CProgressCtrl::StepIt  
 Avança a posição atual de um controle de barra de progresso, o incremento de etapa e redesenha a barra para refletir a nova posição.  
  
```  
int StepIt();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A posição anterior do controle da barra de progresso.  
  
### <a name="remarks"></a>Comentários  
 O incremento de etapa é definido pelo `CProgressCtrl::SetStep` função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CProgressCtrl #10](../../mfc/reference/codesnippet/cpp/cprogressctrl-class_16.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [CMNCTRL2 de exemplo do MFC](../../visual-cpp-samples.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



