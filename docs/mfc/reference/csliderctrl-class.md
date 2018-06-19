---
title: Classe CSliderCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CSliderCtrl
- AFXCMN/CSliderCtrl
- AFXCMN/CSliderCtrl::CSliderCtrl
- AFXCMN/CSliderCtrl::ClearSel
- AFXCMN/CSliderCtrl::ClearTics
- AFXCMN/CSliderCtrl::Create
- AFXCMN/CSliderCtrl::CreateEx
- AFXCMN/CSliderCtrl::GetBuddy
- AFXCMN/CSliderCtrl::GetChannelRect
- AFXCMN/CSliderCtrl::GetLineSize
- AFXCMN/CSliderCtrl::GetNumTics
- AFXCMN/CSliderCtrl::GetPageSize
- AFXCMN/CSliderCtrl::GetPos
- AFXCMN/CSliderCtrl::GetRange
- AFXCMN/CSliderCtrl::GetRangeMax
- AFXCMN/CSliderCtrl::GetRangeMin
- AFXCMN/CSliderCtrl::GetSelection
- AFXCMN/CSliderCtrl::GetThumbLength
- AFXCMN/CSliderCtrl::GetThumbRect
- AFXCMN/CSliderCtrl::GetTic
- AFXCMN/CSliderCtrl::GetTicArray
- AFXCMN/CSliderCtrl::GetTicPos
- AFXCMN/CSliderCtrl::GetToolTips
- AFXCMN/CSliderCtrl::SetBuddy
- AFXCMN/CSliderCtrl::SetLineSize
- AFXCMN/CSliderCtrl::SetPageSize
- AFXCMN/CSliderCtrl::SetPos
- AFXCMN/CSliderCtrl::SetRange
- AFXCMN/CSliderCtrl::SetRangeMax
- AFXCMN/CSliderCtrl::SetRangeMin
- AFXCMN/CSliderCtrl::SetSelection
- AFXCMN/CSliderCtrl::SetThumbLength
- AFXCMN/CSliderCtrl::SetTic
- AFXCMN/CSliderCtrl::SetTicFreq
- AFXCMN/CSliderCtrl::SetTipSide
- AFXCMN/CSliderCtrl::SetToolTips
dev_langs:
- C++
helpviewer_keywords:
- CSliderCtrl [MFC], CSliderCtrl
- CSliderCtrl [MFC], ClearSel
- CSliderCtrl [MFC], ClearTics
- CSliderCtrl [MFC], Create
- CSliderCtrl [MFC], CreateEx
- CSliderCtrl [MFC], GetBuddy
- CSliderCtrl [MFC], GetChannelRect
- CSliderCtrl [MFC], GetLineSize
- CSliderCtrl [MFC], GetNumTics
- CSliderCtrl [MFC], GetPageSize
- CSliderCtrl [MFC], GetPos
- CSliderCtrl [MFC], GetRange
- CSliderCtrl [MFC], GetRangeMax
- CSliderCtrl [MFC], GetRangeMin
- CSliderCtrl [MFC], GetSelection
- CSliderCtrl [MFC], GetThumbLength
- CSliderCtrl [MFC], GetThumbRect
- CSliderCtrl [MFC], GetTic
- CSliderCtrl [MFC], GetTicArray
- CSliderCtrl [MFC], GetTicPos
- CSliderCtrl [MFC], GetToolTips
- CSliderCtrl [MFC], SetBuddy
- CSliderCtrl [MFC], SetLineSize
- CSliderCtrl [MFC], SetPageSize
- CSliderCtrl [MFC], SetPos
- CSliderCtrl [MFC], SetRange
- CSliderCtrl [MFC], SetRangeMax
- CSliderCtrl [MFC], SetRangeMin
- CSliderCtrl [MFC], SetSelection
- CSliderCtrl [MFC], SetThumbLength
- CSliderCtrl [MFC], SetTic
- CSliderCtrl [MFC], SetTicFreq
- CSliderCtrl [MFC], SetTipSide
- CSliderCtrl [MFC], SetToolTips
ms.assetid: dd12b084-4eda-4550-a810-8f3cfb06b871
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0e5b0fac11c2472bbaf0d5f4a3ede7d4f5658f9b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33377152"
---
# <a name="csliderctrl-class"></a>Classe CSliderCtrl
Fornece a funcionalidade do controle deslizante comuns do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSliderCtrl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSliderCtrl::CSliderCtrl](#csliderctrl)|Constrói um objeto `CSliderCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSliderCtrl::ClearSel](#clearsel)|Limpa a seleção atual em um controle deslizante.|  
|[CSliderCtrl::ClearTics](#cleartics)|Remove as marcas de escala atual do controle deslizante.|  
|[CSliderCtrl::Create](#create)|Cria um controle deslizante e anexa-o para um `CSliderCtrl` objeto.|  
|[CSliderCtrl::CreateEx](#createex)|Cria um controle deslizante com os estilos estendidos do Windows especificados e a anexa a um `CSliderCtrl` objeto.|  
|[CSliderCtrl::GetBuddy](#getbuddy)|Recupera o identificador para a janela de buddy do controle deslizante em um local específico.|  
|[CSliderCtrl::GetChannelRect](#getchannelrect)|Recupera o tamanho do canal de controle deslizante.|  
|[CSliderCtrl::GetLineSize](#getlinesize)|Recupera o tamanho de linha do controle deslizante.|  
|[CSliderCtrl::GetNumTics](#getnumtics)|Recupera o número de marcas de escala em um controle deslizante.|  
|[CSliderCtrl::GetPageSize](#getpagesize)|Recupera o tamanho da página de um controle deslizante.|  
|[CSliderCtrl::GetPos](#getpos)|Recupera a posição atual do controle deslizante.|  
|[CSliderCtrl::GetRange](#getrange)|Recupera as posições de mínimas e máxima para um controle deslizante.|  
|[CSliderCtrl::GetRangeMax](#getrangemax)|Recupera a posição de máximo de um controle deslizante.|  
|[CSliderCtrl::GetRangeMin](#getrangemin)|Recupera a posição mínima para um controle deslizante.|  
|[CSliderCtrl::GetSelection](#getselection)|Recupera o intervalo da seleção atual.|  
|[CSliderCtrl::GetThumbLength](#getthumblength)|Recupera o comprimento do controle deslizante em trackbar controle atual.|  
|[CSliderCtrl::GetThumbRect](#getthumbrect)|Recupera o tamanho da miniatura do controle deslizante.|  
|[CSliderCtrl::GetTic](#gettic)|Recupera a posição da marca de escala especificado.|  
|[CSliderCtrl::GetTicArray](#getticarray)|Recupera a matriz de posições de marca de escala para um controle deslizante.|  
|[CSliderCtrl::GetTicPos](#getticpos)|Recupera a posição da marca de escala especificado, nas coordenadas do cliente.|  
|[CSliderCtrl::GetToolTips](#gettooltips)|Recupera o identificador para o controle de dica de ferramenta com o controle deslizante, se houver.|  
|[CSliderCtrl::SetBuddy](#setbuddy)|Atribui uma janela como a janela buddy para um controle deslizante.|  
|[CSliderCtrl::SetLineSize](#setlinesize)|Define o tamanho da linha do controle deslizante.|  
|[CSliderCtrl::SetPageSize](#setpagesize)|Define o tamanho da página de um controle deslizante.|  
|[CSliderCtrl::SetPos](#setpos)|Define a posição atual do controle deslizante.|  
|[CSliderCtrl::SetRange](#setrange)|Define as posições de mínimas e máxima para um controle deslizante.|  
|[CSliderCtrl::SetRangeMax](#setrangemax)|Define a posição de máximo de um controle deslizante.|  
|[CSliderCtrl::SetRangeMin](#setrangemin)|Define a posição mínima para um controle deslizante.|  
|[CSliderCtrl::SetSelection](#setselection)|Define o intervalo da seleção atual.|  
|[CSliderCtrl::SetThumbLength](#setthumblength)|Define o comprimento do controle deslizante em trackbar controle atual.|  
|[CSliderCtrl::SetTic](#settic)|Define a posição da marca de escala especificado.|  
|[CSliderCtrl::SetTicFreq](#setticfreq)|Define a frequência de tique marcas por incremento do controle deslizante.|  
|[CSliderCtrl::SetTipSide](#settipside)|Posições de um controle de dica de ferramenta usada por uma barra de controle.|  
|[CSliderCtrl::SetToolTips](#settooltips)|Atribui um controle de dica de ferramenta a um controle deslizante.|  
  
## <a name="remarks"></a>Comentários  
 "Controle deslizante" (também conhecido como uma barra de controle) é uma janela que contém um controle deslizante e marcas de escala opcional. Quando o usuário move o controle deslizante, usando o mouse ou as teclas de direção, o controle envia mensagens de notificação para indicar a alteração.  
  
 Controles deslizantes são úteis quando você deseja que o usuário selecione um valor discreto ou um conjunto de valores consecutivos em um intervalo. Por exemplo, você pode usar um controle deslizante para permitir que o usuário definir a taxa de repetição do teclado, movendo o controle deslizante para uma marca de escala especificado.  
  
 Esse controle (e, portanto, o `CSliderCtrl` classe) está disponível apenas para programas em execução na versão do Windows 95/98 e Windows NT 3.51 e posterior.  
  
 O controle deslizante se move em incrementos que você especificar ao criá-lo. Por exemplo, se você especificar que o controle deslizante deve ter um intervalo de cinco, o controle deslizante pode apenas ocupam seis posições: uma posição no lado esquerdo do controle deslizante e uma posição para cada incremento no intervalo. Normalmente, cada uma dessas posições é identificado por uma marca de escala.  
  
 Criar um controle deslizante com o construtor e o **criar** função de membro `CSliderCtrl`. Depois de criar um controle deslizante, você pode usar funções de membro em `CSliderCtrl` para alterar muitas de suas propriedades. As alterações que você pode fazer incluem definindo as posições de mínimas e máxima para o controle deslizante, as marcas de escala de desenho, definindo um intervalo de seleção e reposicionar o controle deslizante.  
  
 Para obter mais informações sobre como usar `CSliderCtrl`, consulte [controles](../../mfc/controls-mfc.md) e [usando CSliderCtrl](../../mfc/using-csliderctrl.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CSliderCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn.h  
  
##  <a name="clearsel"></a>  CSliderCtrl::ClearSel  
 Limpa a seleção atual em um controle deslizante.  
  
```  
void ClearSel(BOOL bRedraw = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bRedraw`  
 Redesenhe sinalizador. Se esse parâmetro for **TRUE**, o controle deslizante é redesenhado após a seleção é desmarcada; caso contrário, o controle deslizante não é redesenhado.  
  
##  <a name="cleartics"></a>  CSliderCtrl::ClearTics  
 Remove as marcas de escala atual do controle deslizante.  
  
```  
void ClearTics(BOOL bRedraw = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bRedraw`  
 Redesenhe sinalizador. Se esse parâmetro for **TRUE**, o controle deslizante é redesenhado depois que as marcas de escala são desmarcadas; caso contrário, o controle deslizante não é redesenhado.  
  
##  <a name="create"></a>  CSliderCtrl::Create  
 Cria um controle deslizante e anexa-o para um `CSliderCtrl` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Especifica o estilo do controle deslizante. Aplique qualquer combinação de [estilos de controle deslizante](http://msdn.microsoft.com/library/windows/desktop/bb760147), descrito no SDK do Windows para o controle.  
  
 `rect`  
 Especifica o tamanho e a posição do controle deslizante. Ele pode ser um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura.  
  
 `pParentWnd`  
 Especifica a janela do pai do controle deslizante, geralmente um `CDialog`. Ele não deve ser **nulo**.  
  
 `nID`  
 Especifica a ID. do controle deslizante  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a inicialização foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você pode criar um `CSliderCtrl` em duas etapas. Primeiro, chame o construtor e, em seguida, chamar **criar**, que cria o controle deslizante e anexa-o para o `CSliderCtrl` objeto.  
  
 Dependendo dos valores definidos para `dwStyle`, o controle deslizante pode ter uma orientação vertical ou horizontal. Ele pode ter marcas de escala em ambos os lados, ambos os lados, ou nenhum. Ele também pode ser usado para especificar um intervalo de valores consecutivos.  
  
 Para aplicar estilos de janela estendidos para o controle deslizante, chame [CreateEx](#createex) em vez de **criar**.  
  
##  <a name="createex"></a>  CSliderCtrl::CreateEx  
 Cria um controle (uma janela filho) e o associa a `CSliderCtrl` objeto.  
  
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
 Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista dos estilos estendidos do Windows, consulte o `dwExStyle` parâmetro [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680) no SDK do Windows.  
  
 `dwStyle`  
 Especifica o estilo do controle deslizante. Aplique qualquer combinação de [estilos de controle deslizante](http://msdn.microsoft.com/library/windows/desktop/bb760147), descrito no SDK do Windows para o controle.  
  
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
  
##  <a name="csliderctrl"></a>  CSliderCtrl::CSliderCtrl  
 Constrói um objeto `CSliderCtrl`.  
  
```  
CSliderCtrl();
```  
  
##  <a name="getbuddy"></a>  CSliderCtrl::GetBuddy  
 Recupera o identificador para a janela de buddy do controle deslizante em um local específico.  
  
```  
CWnd* GetBuddy(BOOL fLocation = TRUE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `fLocation`  
 Um valor booliano que indica qual das duas alças de janela buddy para recuperar. Pode ser um dos seguintes valores:  
  
- **TRUE** recupera o identificador para o buddy à esquerda do controle deslizante. Se usar o controle deslizante de `TBS_VERT` estilo, a mensagem recuperará buddy acima do controle deslizante.  
  
- **FALSE** recupera o identificador para o buddy à direita do controle deslizante. Se usar o controle deslizante de `TBS_VERT` estilo, a mensagem recuperará buddy abaixo o controle deslizante.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CWnd](../../mfc/reference/cwnd-class.md) objeto que é a janela buddy no local especificado por `fLocation`, ou **nulo** se nenhuma janela buddy existe nesse local.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [TBM_GETBUDDY](http://msdn.microsoft.com/library/windows/desktop/bb760178), conforme descrito no SDK do Windows. Para obter uma descrição dos estilos de controle deslizante, consulte [estilos de controle Trackbar](http://msdn.microsoft.com/library/windows/desktop/bb760147) no SDK do Windows.  
  
##  <a name="getchannelrect"></a>  CSliderCtrl::GetChannelRect  
 Recupera o tamanho e a posição do retângulo delimitador do canal do controle deslizante.  
  
```  
void GetChannelRect(LPRECT lprc) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lprc`  
 Um ponteiro para um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que contém o tamanho e a posição do canal de limite do retângulo quando a função retorna.  
  
### <a name="remarks"></a>Comentários  
 O canal é a área em que o controle deslizante se move e que contém o realce quando um intervalo está selecionado.  
  
##  <a name="getlinesize"></a>  CSliderCtrl::GetLineSize  
 Recupera o tamanho da linha de um controle deslizante.  
  
```  
int GetLineSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho de uma linha para o controle deslizante.  
  
### <a name="remarks"></a>Comentários  
 O tamanho de linha afeta quanto o controle deslizante se move para o **TB_LINEUP** e **TB_LINEDOWN** notificações. A configuração padrão para o tamanho de linha é 1.  
  
##  <a name="getnumtics"></a>  CSliderCtrl::GetNumTics  
 Recupera o número de marcas de escala em um controle deslizante.  
  
```  
UINT GetNumTics() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de marcas de escala no controle deslizante.  
  
##  <a name="getpagesize"></a>  CSliderCtrl::GetPageSize  
 Recupera o tamanho da página de um controle deslizante.  
  
```  
int GetPageSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho de uma página para o controle deslizante.  
  
### <a name="remarks"></a>Comentários  
 O tamanho de página afeta quanto o controle deslizante se move para o **TB_PAGEUP** e **TB_PAGEDOWN** notificações.  
  
##  <a name="getpos"></a>  CSliderCtrl::GetPos  
 Recupera a posição atual do controle deslizante no controle deslizante.  
  
```  
int GetPos() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A posição atual.  
  
##  <a name="getrange"></a>  CSliderCtrl::GetRange  
 Recupera as posições de mínimas e máxima para o controle deslizante no controle deslizante.  
  
```  
void GetRange(
    int& nMin,  
    int& nMax) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMin`  
 Referência a um número inteiro que recebe a posição mínima.  
  
 `nMax`  
 Referência a um número inteiro que recebe a posição máxima.  
  
### <a name="remarks"></a>Comentários  
 Esta função copia os valores em inteiros referenciados por `nMin` e `nMax`.  
  
##  <a name="getrangemax"></a>  CSliderCtrl::GetRangeMax  
 Recupera a posição máximo para o controle deslizante no controle deslizante.  
  
```  
int GetRangeMax() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A posição do controle máximo.  
  
##  <a name="getrangemin"></a>  CSliderCtrl::GetRangeMin  
 Recupera a posição mínima para o controle deslizante no controle deslizante.  
  
```  
int GetRangeMin() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A posição do controle mínimo.  
  
##  <a name="getselection"></a>  CSliderCtrl::GetSelection  
 Recupera as posições iniciais e final da seleção atual em um controle deslizante.  
  
```  
void GetSelection(
    int& nMin,  
    int& nMax) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMin`  
 Referência a um número inteiro que recebe a posição inicial da seleção atual.  
  
 `nMax`  
 Referência a um número inteiro que recebe a posição final da seleção atual.  
  
##  <a name="getthumblength"></a>  CSliderCtrl::GetThumbLength  
 Recupera o comprimento do controle deslizante em trackbar controle atual.  
  
```  
int GetThumbLength() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento do controle deslizante, em pixels.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [TBM_GETTHUMBLENGTH](http://msdn.microsoft.com/library/windows/desktop/bb760201) mensagem, que é descrita no SDK do Windows.  
  
##  <a name="getthumbrect"></a>  CSliderCtrl::GetThumbRect  
 Recupera o tamanho e a posição do retângulo delimitador para o controle deslizante (miniatura) em um controle deslizante.  
  
```  
void GetThumbRect(LPRECT lprc) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lprc`  
 Um ponteiro para um `CRect` objeto que contém o retângulo delimitador para o controle deslizante quando a função retorna.  
  
##  <a name="gettic"></a>  CSliderCtrl::GetTic  
 Recupera a posição de uma marca de escala em um controle deslizante.  
  
```  
int GetTic(int nTic) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nTic`  
 Índice de base zero que identifica uma marca de escala.  
  
### <a name="return-value"></a>Valor de retorno  
 A posição da marca de escala especificado ou - 1 se `nTic` não especifica um índice válido.  
  
##  <a name="getticarray"></a>  CSliderCtrl::GetTicArray  
 Recupera o endereço da matriz que contém as posições das marcas de escala para um controle deslizante.  
  
```  
DWORD* GetTicArray() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O endereço da matriz que contém posições de marca de escala para o controle deslizante.  
  
##  <a name="getticpos"></a>  CSliderCtrl::GetTicPos  
 Recupera a posição física atual de uma marca de escala em um controle deslizante.  
  
```  
int GetTicPos(int nTic) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nTic`  
 Índice de base zero que identifica uma marca de escala.  
  
### <a name="return-value"></a>Valor de retorno  
 A posição física, nas coordenadas do cliente, de marca de escala especificado ou - 1 se `nTic` não especifica um índice válido.  
  
##  <a name="gettooltips"></a>  CSliderCtrl::GetToolTips  
 Recupera o identificador para o controle de dica de ferramenta com o controle deslizante, se houver.  
  
```  
CToolTipCtrl* GetToolTips() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md) objeto, ou **nulo** se dicas de ferramenta não estiverem em uso. Se não usar o controle deslizante de **TBS_TOOLTIPS** estilo, o valor de retorno é **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [TBM_GETTOOLTIPS](http://msdn.microsoft.com/library/windows/desktop/bb760209), conforme descrito no SDK do Windows. Observe que essa função de membro retorna um `CToolTipCtrl` objeto em vez de um identificador para um controle.  
  
 Para obter uma descrição dos estilos de controle deslizante, consulte [estilos de controle Trackbar](http://msdn.microsoft.com/library/windows/desktop/bb760147) no SDK do Windows.  
  
##  <a name="setbuddy"></a>  CSliderCtrl::SetBuddy  
 Atribui uma janela como a janela buddy para um controle deslizante.  
  
```  
CWnd* SetBuddy(
    CWnd* pWndBuddy,  
    BOOL fLocation = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWndBuddy`  
 Um ponteiro para um `CWnd` objeto será definido como buddy do controle deslizante.  
  
 `fLocation`  
 Valor que especifica o local no qual exibir a janela buddy. Esse valor pode ser um dos seguintes:  
  
- **TRUE** de amigo será exibida à esquerda de trackbar se usa a barra de controle de `TBS_HORZ` estilo. Se a barra de controle usa o `TBS_VERT` de estilo, a colega aparece acima do controle trackbar.  
  
- **FALSE** de amigo aparecerá à direita de trackbar se usar a barra de controle de `TBS_HORZ` estilo. Se a barra de controle usa o `TBS_VERT` de estilo, a colega aparece abaixo do controle trackbar.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CWnd](../../mfc/reference/cwnd-class.md) objeto que foi anteriormente atribuído para o controle deslizante nesse local.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [TBM_SETBUDDY](http://msdn.microsoft.com/library/windows/desktop/bb760213), conforme descrito no SDK do Windows. Observe que essa função de membro usa ponteiros para `CWnd` objetos, em vez de identificadores de janela para seu valor de retorno e de parâmetro.  
  
 Para obter uma descrição dos estilos de controle deslizante, consulte [estilos de controle Trackbar](http://msdn.microsoft.com/library/windows/desktop/bb760147) no SDK do Windows.  
  
##  <a name="setlinesize"></a>  CSliderCtrl::SetLineSize  
 Define o tamanho da linha de um controle deslizante.  
  
```  
int SetLineSize(int nSize);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSize`  
 O novo tamanho de linha do controle deslizante.  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho da linha anterior.  
  
### <a name="remarks"></a>Comentários  
 O tamanho de linha afeta quanto o controle deslizante se move para o **TB_LINEUP** e **TB_LINEDOWN** notificações.  
  
##  <a name="setpagesize"></a>  CSliderCtrl::SetPageSize  
 Define o tamanho da página de um controle deslizante.  
  
```  
int SetPageSize(int nSize);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nSize`  
 O novo tamanho de página do controle deslizante.  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho da página anterior.  
  
### <a name="remarks"></a>Comentários  
 O tamanho de página afeta quanto o controle deslizante se move para o **TB_PAGEUP** e **TB_PAGEDOWN** notificações.  
  
##  <a name="setpos"></a>  CSliderCtrl::SetPos  
 Define a posição atual do controle deslizante no controle deslizante.  
  
```  
void SetPos(int nPos);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPos`  
 Especifica a nova posição do controle deslizante.  
  
##  <a name="setrange"></a>  CSliderCtrl::SetRange  
 Define o intervalo (posições mínimos e máximo) para o controle deslizante no controle deslizante.  
  
```  
void SetRange(
    int nMin,  
    int nMax,  
    BOOL bRedraw = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMin`  
 Posição do mínimo para o controle deslizante.  
  
 `nMax`  
 Posição máximo para o controle deslizante.  
  
 `bRedraw`  
 O sinalizador de atualização. Se esse parâmetro for **TRUE**, o controle deslizante é redesenhado depois que o intervalo é definido; caso contrário, o controle deslizante não é redesenhado.  
  
##  <a name="setrangemax"></a>  CSliderCtrl::SetRangeMax  
 Define o intervalo máximo para o controle deslizante no controle deslizante.  
  
```  
void SetRangeMax(
    int nMax,  
    BOOL bRedraw = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMax`  
 Posição máximo para o controle deslizante.  
  
 `bRedraw`  
 O sinalizador de atualização. Se esse parâmetro for **TRUE**, o controle deslizante é redesenhado depois que o intervalo é definido; caso contrário, o controle deslizante não é redesenhado.  
  
##  <a name="setrangemin"></a>  CSliderCtrl::SetRangeMin  
 Define o período mínimo para o controle deslizante no controle deslizante.  
  
```  
void SetRangeMin(
    int nMin,  
    BOOL bRedraw = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMin`  
 Posição do mínimo para o controle deslizante.  
  
 `bRedraw`  
 O sinalizador de atualização. Se esse parâmetro for **TRUE**, o controle deslizante é redesenhado depois que o intervalo é definido; caso contrário, o controle deslizante não é redesenhado.  
  
##  <a name="setselection"></a>  CSliderCtrl::SetSelection  
 Define as posições iniciais e final da seleção atual em um controle deslizante.  
  
```  
void SetSelection(
    int nMin,  
    int nMax);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMin`  
 Posição inicial para o controle deslizante.  
  
 `nMax`  
 Posição final para o controle deslizante.  
  
##  <a name="setthumblength"></a>  CSliderCtrl::SetThumbLength  
 Define o comprimento do controle deslizante em trackbar controle atual.  
  
```  
void SetThumbLength(int nLength);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `nLength`|Comprimento do controle deslizante, em pixels.|  
  
### <a name="remarks"></a>Comentários  
 Esse método requer que a barra de controle seja definida como [TBS_FIXEDLENGTH](http://msdn.microsoft.com/library/windows/desktop/bb760147) estilo.  
  
 Esse método envia o [TBM_SETTHUMBLENGTH](http://msdn.microsoft.com/library/windows/desktop/bb760234) mensagem, que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_sliderCtrl`, que é usado para acessar a barra de controle atual. O exemplo também define uma variável, `thumbLength`, que é usado para armazenar o comprimento padrão do componente de miniatura do controle trackbar. Essas variáveis são usadas no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CSliderCtrl_s1#1](../../mfc/reference/codesnippet/cpp/csliderctrl-class_1.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define o componente de miniatura do controle trackbar a duas vezes seu tamanho padrão.  
  
 [!code-cpp[NVC_MFC_CSliderCtrl_s1#2](../../mfc/reference/codesnippet/cpp/csliderctrl-class_2.cpp)]  
  
##  <a name="settic"></a>  CSliderCtrl::SetTic  
 Define a posição de uma marca de escala em um controle deslizante.  
  
```  
BOOL SetTic(int nTic);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nTic`  
 Posição da marca de escala. Esse parâmetro deve especificar um valor positivo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a marca de escala está definida; Caso contrário, 0.  
  
##  <a name="setticfreq"></a>  CSliderCtrl::SetTicFreq  
 Define a frequência com que escala marcas são exibidas em um controle deslizante.  
  
```  
void SetTicFreq(int nFreq);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nFreq*  
 Frequência das marcas de escala.  
  
### <a name="remarks"></a>Comentários  
 Por exemplo, se a frequência é definida como 2, uma marca de escala é exibida para todos os outros incremento no intervalo do controle deslizante. A configuração padrão para a frequência é 1 (ou seja, cada incremento na faixa está associado com uma marca de escala).  
  
 Você deve criar o controle com o `TBS_AUTOTICKS` estilo usar essa função. Para obter mais informações, consulte [CSliderCtrl::Create](#create).  
  
##  <a name="settipside"></a>  CSliderCtrl::SetTipSide  
 Posições de um controle de dica de ferramenta usada por uma barra de controle.  
  
```  
int SetTipSide(int nLocation);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nLocation`  
 Valor que representa o local no qual exibir o controle de dica de ferramenta. Para obter uma lista de valores possíveis, consulte a mensagem de Win32 [TBM_SETTIPSIDE](http://msdn.microsoft.com/library/windows/desktop/bb760240), conforme descrito no SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que representa o local anterior do controle de dica de ferramenta. O valor de retorno é igual a um dos possíveis valores para `nLocation`.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 **TBM_SETTIPSIDE**, conforme descrito no SDK do Windows. Controle deslizante de controles que usam o **TBS_TOOLTIPS** dicas de ferramenta de exibição de estilo. Para obter uma descrição dos estilos de controle deslizante, consulte [estilos de controle Trackbar](http://msdn.microsoft.com/library/windows/desktop/bb760147) no SDK do Windows.  
  
##  <a name="settooltips"></a>  CSliderCtrl::SetToolTips  
 Atribui um controle de dica de ferramenta a um controle deslizante.  
  
```  
void SetToolTips(CToolTipCtrl* pWndTip);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWndTip`  
 Um ponteiro para um [CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md) objeto que contém as dicas de ferramentas para usar com o controle deslizante.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [TBM_SETTOOLTIPS](http://msdn.microsoft.com/library/windows/desktop/bb760242), conforme descrito no SDK do Windows. Quando um controle deslizante é criado com o **TBS_TOOLTIPS** estilo, ele cria um controle de dica de ferramenta padrão que aparece ao lado do controle deslizante, exibindo a posição atual do controle deslizante. Para obter uma descrição dos estilos de controle deslizante, consulte [estilos de controle Trackbar](http://msdn.microsoft.com/library/windows/desktop/bb760147) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [CMNCTRL2 de exemplo do MFC](../../visual-cpp-samples.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CProgressCtrl](../../mfc/reference/cprogressctrl-class.md)
