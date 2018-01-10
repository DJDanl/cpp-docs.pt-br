---
title: Classe CControlBar | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CControlBar
- AFXEXT/CControlBar
- AFXEXT/CControlBar::CControlBar
- AFXEXT/CControlBar::CalcDynamicLayout
- AFXEXT/CControlBar::CalcFixedLayout
- AFXEXT/CControlBar::CalcInsideRect
- AFXEXT/CControlBar::DoPaint
- AFXEXT/CControlBar::DrawBorders
- AFXEXT/CControlBar::DrawGripper
- AFXEXT/CControlBar::EnableDocking
- AFXEXT/CControlBar::GetBarStyle
- AFXEXT/CControlBar::GetBorders
- AFXEXT/CControlBar::GetCount
- AFXEXT/CControlBar::GetDockingFrame
- AFXEXT/CControlBar::IsFloating
- AFXEXT/CControlBar::OnUpdateCmdUI
- AFXEXT/CControlBar::SetBarStyle
- AFXEXT/CControlBar::SetBorders
- AFXEXT/CControlBar::SetInPlaceOwner
- AFXEXT/CControlBar::m_bAutoDelete
- AFXEXT/CControlBar::m_pInPlaceOwner
dev_langs: C++
helpviewer_keywords:
- CControlBar [MFC], CControlBar
- CControlBar [MFC], CalcDynamicLayout
- CControlBar [MFC], CalcFixedLayout
- CControlBar [MFC], CalcInsideRect
- CControlBar [MFC], DoPaint
- CControlBar [MFC], DrawBorders
- CControlBar [MFC], DrawGripper
- CControlBar [MFC], EnableDocking
- CControlBar [MFC], GetBarStyle
- CControlBar [MFC], GetBorders
- CControlBar [MFC], GetCount
- CControlBar [MFC], GetDockingFrame
- CControlBar [MFC], IsFloating
- CControlBar [MFC], OnUpdateCmdUI
- CControlBar [MFC], SetBarStyle
- CControlBar [MFC], SetBorders
- CControlBar [MFC], SetInPlaceOwner
- CControlBar [MFC], m_bAutoDelete
- CControlBar [MFC], m_pInPlaceOwner
ms.assetid: 4d668c55-9b42-4838-97ac-cf2b3000b82c
caps.latest.revision: "22"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a911ff6251a6b34162377610ae139cfa3a7cefaa
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ccontrolbar-class"></a>Classe CControlBar
A classe base para as classes da barra de controle [CStatusBar](../../mfc/reference/cstatusbar-class.md), [CToolBar](../../mfc/reference/ctoolbar-class.md), [CDialogBar](../../mfc/reference/cdialogbar-class.md), [CReBar](../../mfc/reference/crebar-class.md), e [ COleResizeBar](../../mfc/reference/coleresizebar-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CControlBar : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CControlBar::CControlBar](#ccontrolbar)|Constrói um objeto `CControlBar`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CControlBar::CalcDynamicLayout](#calcdynamiclayout)|Retorna o tamanho de uma barra de controle dinâmico como um [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.|  
|[CControlBar::CalcFixedLayout](#calcfixedlayout)|Retorna o tamanho da barra de controle, como um [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.|  
|[CControlBar::CalcInsideRect](#calcinsiderect)|Retorna as dimensões atuais da área de barra de controle; incluindo as bordas.|  
|[CControlBar::DoPaint](#dopaint)|Renderiza as bordas e garra da barra de controle.|  
|[CControlBar::DrawBorders](#drawborders)|Apresenta as bordas da barra de controle.|  
|[CControlBar::DrawGripper](#drawgripper)|Renderiza a alça da barra de controle.|  
|[CControlBar::EnableDocking](#enabledocking)|Permite que uma barra de controle encaixado ou flutuante.|  
|[CControlBar::GetBarStyle](#getbarstyle)|Recupera as configurações de estilo de barra de controle.|  
|[CControlBar::GetBorders](#getborders)|Recupera os valores de borda da barra de controle.|  
|[CControlBar::GetCount](#getcount)|Retorna o número de não - `HWND` elementos na barra de controle.|  
|[CControlBar::GetDockingFrame](#getdockingframe)|Retorna um ponteiro para o quadro no qual uma barra de controle está encaixada.|  
|[CControlBar::IsFloating](#isfloating)|Retorna um valor diferente de zero se a barra de controle em questão é uma barra flutuante do controle.|  
|[CControlBar::OnUpdateCmdUI](#onupdatecmdui)|Chama os manipuladores de comando da interface do usuário.|  
|[CControlBar::SetBarStyle](#setbarstyle)|Modifica as configurações de estilo de barra de controle.|  
|[CControlBar::SetBorders](#setborders)|Define os valores de borda da barra de controle.|  
|[CControlBar::SetInPlaceOwner](#setinplaceowner)|Altera o proprietário do local de uma barra de controle.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CControlBar::m_bAutoDelete](#m_bautodelete)|Se for diferente de zero, o `CControlBar` objeto é excluído quando a barra de controle do Windows é destruída.|  
|[CControlBar::m_pInPlaceOwner](#m_pinplaceowner)|O proprietário do local da barra de controle.|  
  
## <a name="remarks"></a>Comentários  
 Uma barra de controle é uma janela que geralmente é alinhada à esquerda ou à direita de uma janela do quadro. Ele pode conter itens filho que são `HWND`- com base em controles que são janelas que geram e respondem a mensagens do Windows, ou não - `HWND`-com base em itens que não sejam windows e são gerenciados pelo código do aplicativo ou código do framework. Caixas de listagem e controles de edição são exemplos de `HWND`- controles com base; painéis da barra de status e botões de bitmap são exemplos de não - `HWND`-com base em controles.  
  
 Windows da barra de controle são geralmente janelas filho de uma janela do quadro pai e geralmente são irmãos para o modo de exibição do cliente ou o cliente MDI da janela do quadro. Um `CControlBar` objeto usa informações sobre o retângulo de cliente da janela pai para se posicionar. Em seguida, ele informa a janela pai como a quantidade de espaço permanece não alocado na área cliente da janela pai.  
  
 Para obter mais informações sobre `CControlBar`, consulte:  
  
- [Barras de controle](../../mfc/control-bars.md)  
  
- [Observação técnica 31: Barras de controle](../../mfc/tn031-control-bars.md).  
  
-   Artigo da Base de dados de Conhecimento Q242577: PRB: atualização de comando da interface do usuário manipuladores não funcionam para Menu anexados a uma caixa de diálogo  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CControlBar`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxext.h  
  
##  <a name="calcdynamiclayout"></a>CControlBar::CalcDynamicLayout  
 O framework chama esta função de membro para calcular as dimensões de uma barra de ferramentas dinâmica.  
  
```  
virtual CSize CalcDynamicLayout(
    int nLength,  
    DWORD nMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nLength`  
 A dimensão solicitada da barra de controle, horizontal ou verticalmente, dependendo da `dwMode`.  
  
 `nMode`  
 Os seguintes sinalizadores predefinidos são usados para determinar a altura e largura da barra de controle dinâmico. Use o OR bit a bit (&#124;) operador para combinar os sinalizadores.  
  
|Sinalizadores de modo de layout|O que significa|  
|-----------------------|-------------------|  
|`LM_STRETCH`|Indica se a barra de controle deve ser estendida para o tamanho do quadro. Defina se a barra não é uma barra de encaixe (não disponível para encaixar). Não defina quando a barra estiver encaixado ou flutuante (disponível para encaixar). Se definido, `LM_STRETCH` ignora `nLength` e retorna as dimensões com base no `LM_HORZ` estado. `LM_STRETCH`funciona da mesma forma que o `bStretch` parâmetro usado em [CalcFixedLayout](#calcfixedlayout); consulte essa função de membro para obter mais informações sobre a relação entre ampliar e orientação.|  
|`LM_HORZ`|Indica que a barra é orientada horizontal ou verticalmente. Defina se a barra é orientada horizontal, e se ele é orientado verticalmente, ele não está definido. `LM_HORZ`funciona da mesma forma que o `bHorz` parâmetro usado em [CalcFixedLayout](#calcfixedlayout); consulte essa função de membro para obter mais informações sobre a relação entre ampliar e orientação.|  
|**LM_MRUWIDTH**|Usado mais recentemente largura dinâmica. Ignora `nLength` parâmetro e usa o lembrados largura usado mais recentemente.|  
|`LM_HORZDOCK`|Horizontal encaixado dimensões. Ignora `nLength` parâmetro e retorna o tamanho dinâmico com a maior largura.|  
|`LM_VERTDOCK`|Vertical encaixado dimensões. Ignora `nLength` parâmetro e retorna o tamanho dinâmico com a altura maior.|  
|`LM_LENGTHY`|Defina se `nLength` indica a altura (direção Y) em vez de largura.|  
|`LM_COMMIT`|Redefine **LM_MRUWIDTH** a largura atual da barra de controle flutuante.|  
  
### <a name="return-value"></a>Valor de retorno  
 A barra de controle de tamanho, em pixels, de um [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Substituir essa função de membro para fornecer seu próprio layout dinâmico em classes que derivam de `CControlBar`. Classes MFC derivadas de `CControlBar`, como [CToolbar](../../mfc/reference/ctoolbar-class.md), substitua essa função de membro e fornecer sua própria implementação.  
  
##  <a name="calcfixedlayout"></a>CControlBar::CalcFixedLayout  
 Chame essa função de membro para calcular o tamanho horizontal de uma barra de controle.  
  
```  
virtual CSize CalcFixedLayout(
    BOOL bStretch,  
    BOOL bHorz);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bStretch`  
 Indica se a barra deve ser estendida para o tamanho do quadro. O `bStretch` parâmetro é diferente de zero quando a barra não é uma barra de encaixe (não disponível para encaixar) e é 0 quando ele está encaixado ou flutuante (disponível para encaixar).  
  
 `bHorz`  
 Indica que a barra é orientada horizontal ou verticalmente. O `bHorz` parâmetro é diferente de zero se a barra é orientada horizontal e é 0 se for orientação vertical.  
  
### <a name="return-value"></a>Valor de retorno  
 A barra de controle de tamanho, em pixels, de um `CSize` objeto.  
  
### <a name="remarks"></a>Comentários  
 Barras de controle, como barras de ferramentas podem ampliar horizontalmente ou verticalmente acomodar os botões contidos na barra de controle.  
  
 Se `bStretch` é **TRUE**, Alongar dimensão a orientação fornecida pelo `bHorz`. Em outras palavras, se `bHorz` é **FALSE**, a barra de controle é ampliada verticalmente. Se `bStretch` é **FALSE**, nenhum stretch ocorre. A tabela a seguir mostra os estilos de barra de controle resultante e a possíveis permutações de `bStretch` e `bHorz`.  
  
|bStretch|bHorz|Ampliar|{1&gt;Orientação&lt;1}|Encaixe de encaixe ou não|  
|--------------|-----------|----------------|-----------------|--------------------------|  
|**TRUE**|**TRUE**|Expansão horizontal|Horizontalmente|Não encaixe|  
|**TRUE**|**FALSE**|Expansão vertical|Orientados verticalmente|Não encaixe|  
|**FALSE**|**TRUE**|Nenhum alongando disponíveis|Horizontalmente|Encaixe|  
|**FALSE**|**FALSE**|Nenhum alongando disponíveis|Orientados verticalmente|Encaixe|  
  
##  <a name="calcinsiderect"></a>CControlBar::CalcInsideRect  
 O framework chama esta função para calcular a área de cliente da barra de controle.  
  
```  
virtual void CalcInsideRect(
    CRect& rect,  
    BOOL bHorz) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `rect`  
 Contém as dimensões atuais da barra de controle; incluindo as bordas.  
  
 `bHorz`  
 Indica que a barra é orientada horizontal ou verticalmente. O `bHorz` parâmetro é diferente de zero se a barra é orientada horizontal e é 0 se for orientação vertical.  
  
### <a name="remarks"></a>Comentários  
 Essa função é chamada antes que a barra de controle é pintada.  
  
 Substitua esta função para personalizar a renderização de bordas e barra de garra da barra de controle.  
  
##  <a name="ccontrolbar"></a>CControlBar::CControlBar  
 Constrói um objeto `CControlBar`.  
  
```  
CControlBar();
```  
  
##  <a name="dopaint"></a>CControlBar::DoPaint  
 Chamado pelo framework para processar as bordas e barra de garra da barra de controle.  
  
```  
virtual void DoPaint(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Aponta para o contexto de dispositivo a ser usado para a renderização de bordas e da alça da barra de controle.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para personalizar o comportamento de desenho da barra de controle.  
  
 Outro método de personalização é substituir a `DrawBorders` e `DrawGripper` funções e adicione o código de desenho personalizado para as bordas e garra. Como esses métodos são chamados pelo padrão `DoPaint` método, uma substituição de `DoPaint` não é necessária.  
  
##  <a name="drawborders"></a>CControlBar::DrawBorders  
 Chamado pelo framework para processar as bordas da barra de controle.  
  
```  
virtual void DrawBorders(
    CDC* pDC,  
    CRect& rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Aponta para o contexto de dispositivo a ser usado para a renderização de bordas da barra de controle.  
  
 `rect`  
 Um `CRect` objeto que contém as dimensões da barra de controle.  
  
### <a name="remarks"></a>Comentários  
 Substitua esta função para personalizar a aparência das bordas da barra de controle.  
  
##  <a name="drawgripper"></a>CControlBar::DrawGripper  
 Chamado pelo framework para renderizar a alça da barra de controle.  
  
```  
virtual void DrawGripper(
    CDC* pDC,  
    const CRect& rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Aponta para o contexto de dispositivo a ser usado para renderizar a alça da barra de controle.  
  
 `rect`  
 Um `CRect` objeto que contém as dimensões da garra de barra de controle.  
  
### <a name="remarks"></a>Comentários  
 Substitua esta função para personalizar a aparência da garra de barra de controle.  
  
##  <a name="enabledocking"></a>CControlBar::EnableDocking  
 Chame essa função para habilitar uma barra de controle encaixado.  
  
```  
void EnableDocking(DWORD dwDockStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwDockStyle`  
 Especifica se a barra de controle oferece suporte de encaixe e os lados da sua janela pai à qual a barra de controle pode ser encaixada, se houver suporte. Pode ser um ou mais dos seguintes:  
  
- `CBRS_ALIGN_TOP`Permite que o encaixe na parte superior da área cliente.  
  
- `CBRS_ALIGN_BOTTOM`Permite que o encaixe na parte inferior da área do cliente.  
  
- `CBRS_ALIGN_LEFT`Permite que o encaixe no lado esquerdo da área cliente.  
  
- `CBRS_ALIGN_RIGHT`Permite que o encaixe no lado direito da área do cliente.  
  
- `CBRS_ALIGN_ANY`Permite que o encaixe em qualquer lado da área do cliente.  
  
- `CBRS_FLOAT_MULTI`Permite que várias barras de controle ser flutuante em uma janela do miniúnico quadro.  
  
 Se for 0 (ou seja, indicando que nenhum sinalizador), não será encaixar a barra de controle.  
  
### <a name="remarks"></a>Comentários  
 Os lados especificados devem corresponder a um dos lados habilitados para encaixar na janela do quadro de destino ou a barra de controle não pode ser encaixada para essa janela do quadro.  
  
##  <a name="getbarstyle"></a>CControlBar::GetBarStyle  
 Chamar esta função para determinar qual **CBRS_** (estilos de barra de controle) configurações definidas atualmente para a barra de controle.  
  
```  
DWORD GetBarStyle();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Atual **CBRS_** configurações (estilos de barra de controle) para a barra de controle. Consulte [CControlBar::SetBarStyle](#setbarstyle) para obter uma lista de estilos disponíveis.  
  
### <a name="remarks"></a>Comentários  
 Não processa **WS_** estilos (estilo da janela).  
  
##  <a name="getborders"></a>CControlBar::GetBorders  
 Retorna os valores atuais de borda para a barra de controle.  
  
```  
CRect GetBorders() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CRect` objeto que contém a largura atual (em pixels) de cada lado do objeto de barra de controle. Por exemplo, o valor da `left` membro, de [CRect](../../atl-mfc-shared/reference/crect-class.md) de objeto, é a largura da borda esquerda.  
  
##  <a name="getcount"></a>CControlBar::GetCount  
 Retorna o número de não - `HWND` itens no `CControlBar` objeto.  
  
```  
int GetCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de não - `HWND` itens no `CControlBar` objeto. Essa função retorna 0 para um [CDialogBar](../../mfc/reference/cdialogbar-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 O tipo do item depende o objeto derivado: painéis para [CStatusBar](../../mfc/reference/cstatusbar-class.md) objetos e botões e separadores de [CToolBar](../../mfc/reference/ctoolbar-class.md) objetos.  
  
##  <a name="getdockingframe"></a>CControlBar::GetDockingFrame  
 Chame essa função de membro para obter um ponteiro para a janela do quadro atual ao qual sua barra de controle está encaixada.  
  
```  
CFrameWnd* GetDockingFrame() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para uma janela do quadro se bem-sucedido; Caso contrário, **nulo**.  
  
 Se a barra de controle não está encaixada para uma janela do quadro (ou seja, se a barra de controle é flutuante), essa função retorna um ponteiro para seu pai [CMiniFrameWnd](../../mfc/reference/cminiframewnd-class.md).  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre barras de controle acopláveis, consulte [CControlBar::EnableDocking](#enabledocking) e [CFrameWnd::DockControlBar](../../mfc/reference/cframewnd-class.md#dockcontrolbar).  
  
##  <a name="isfloating"></a>CControlBar::IsFloating  
 Chame essa função de membro para determinar se a barra de controle está encaixado ou flutuante.  
  
```  
BOOL IsFloating() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a barra de controle é flutuante; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para alterar o estado de uma barra de controle de ancorada para flutuante, chame [CFrameWnd::FloatControlBar](../../mfc/reference/cframewnd-class.md#floatcontrolbar).  
  
##  <a name="m_bautodelete"></a>CControlBar::m_bAutoDelete  
 Se for diferente de zero, o `CControlBar` objeto é excluído quando a barra de controle do Windows é destruída.  
  
```  
BOOL m_bAutoDelete;  
```  
  
### <a name="remarks"></a>Comentários  
 `m_bAutoDelete`é uma variável pública do tipo **BOOL**.  
  
 Um objeto de barra de controle geralmente é inserido em um objeto de janela do quadro. Nesse caso, `m_bAutoDelete` é 0 porque o objeto de barra de controle inserido é destruído quando a janela do quadro é destruída.  
  
 Definir essa variável como um valor diferente de zero, se você alocar um `CControlBar` objeto no heap e você não planeja chamar **excluir**.  
  
##  <a name="m_pinplaceowner"></a>CControlBar::m_pInPlaceOwner  
 O proprietário do local da barra de controle.  
  
```  
CWnd* m_pInPlaceOwner;  
```  
  
##  <a name="onupdatecmdui"></a>CControlBar::OnUpdateCmdUI  
 Essa função de membro é chamada pelo framework para atualizar o status da barra de ferramentas ou status.  
  
```  
virtual void OnUpdateCmdUI(
    CFrameWnd* pTarget,  
    BOOL bDisableIfNoHndler) = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pTarget`  
 Aponta para a janela do quadro principal do aplicativo. Esse ponteiro é usado para roteamento de mensagens de atualização.  
  
 `bDisableIfNoHndler`  
 Sinalizador que indica se um controle que não possui nenhum manipulador de atualização deve ser exibido automaticamente como desabilitado.  
  
### <a name="remarks"></a>Comentários  
 Para atualizar um botão individual ou o painel, use o `ON_UPDATE_COMMAND_UI` macro em seu mapa de mensagem para definir um manipulador de atualização adequadamente. Consulte [ON_UPDATE_COMMAND_UI](message-map-macros-mfc.md#on_update_command_ui) para obter mais informações sobre como usar esta macro.  
  
 `OnUpdateCmdUI`é chamado pelo framework quando o aplicativo estiver ocioso. A janela do quadro a ser atualizado deve ser uma janela filho, pelo menos indiretamente, de uma janela do quadro visíveis. `OnUpdateCmdUI`é uma avançada substituível.  
  
##  <a name="setbarstyle"></a>CControlBar::SetBarStyle  
 Chamar essa função para definir os detalhes desejados **CBRS_** estilos para a barra de controle.  
  
```  
void SetBarStyle(DWORD dwStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Os estilos desejados para a barra de controle. Pode ser um ou mais dos seguintes:  
  
- `CBRS_ALIGN_TOP`Permite que a barra de controle para ser encaixado à parte superior da área cliente de uma janela do quadro.  
  
- `CBRS_ALIGN_BOTTOM`Permite que a barra de controle para ser encaixado na parte inferior da área cliente de uma janela do quadro.  
  
- `CBRS_ALIGN_LEFT`Permite que a barra de controle encaixado à esquerda da área cliente de uma janela do quadro.  
  
- `CBRS_ALIGN_RIGHT`Permite que a barra de controle encaixado à direita da área cliente de uma janela do quadro.  
  
- `CBRS_ALIGN_ANY`Permite que a barra de controle encaixado para qualquer lado da área cliente de uma janela do quadro.  
  
- `CBRS_BORDER_TOP`Faz com que uma borda a ser desenhada na borda superior da barra de controle quando ele deve ser visível.  
  
- `CBRS_BORDER_BOTTOM`Faz com que uma borda a ser desenhada na borda inferior da barra de controle quando ele deve ser visível.  
  
- `CBRS_BORDER_LEFT`Faz com que uma borda a ser desenhada na borda esquerda da barra de controle quando ele deve ser visível.  
  
- `CBRS_BORDER_RIGHT`Faz com que uma borda a ser desenhada na borda direita da barra de controle quando ele deve ser visível.  
  
- `CBRS_FLOAT_MULTI`Permite que várias barras de controle ser flutuante em uma janela do miniúnico quadro.  
  
- `CBRS_TOOLTIPS`Faz com que as dicas de ferramenta a ser exibido para a barra de controle.  
  
- `CBRS_FLYBY`Faz com que o texto da mensagem a ser atualizados ao mesmo tempo como dicas de ferramenta.  
  
- **CBRS_GRIPPER** faz com que uma garra semelhante àquela usada em faixas em um **CReBar** objeto a ser desenhada para qualquer `CControlBar`-classe derivada.  
  
### <a name="remarks"></a>Comentários  
 Não afeta o **WS_** configurações (estilo da janela).  
  
##  <a name="setborders"></a>CControlBar::SetBorders  
 Chame essa função para definir o tamanho das bordas da barra de controle.  
  
```  
void SetBorders(
    int cxLeft = 0,  
    int cyTop = 0,  
    int cxRight = 0,  
    int cyBottom = 0);  
  
void SetBorders(LPCRECT lpRect);
```  
  
### <a name="parameters"></a>Parâmetros  
 *cxLeft*  
 A largura (em pixels) da borda esquerda da barra de controle.  
  
 *cyTop*  
 A altura (em pixels) da borda superior da barra de controle.  
  
 *cxRight*  
 A largura (em pixels) da borda direita da barra de controle.  
  
 *cyBottom*  
 A altura (em pixels) da borda de parte inferior da barra de controle.  
  
 `lpRect`  
 Um ponteiro para um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto que contém a largura atual (em pixels) de cada borda do objeto de barra de controle.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define as bordas superior e inferior da barra de controle para 5 pixels e as bordas esquerdas e direita como 2 pixels:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#61](../../mfc/codesnippet/cpp/ccontrolbar-class_1.cpp)]  
  
##  <a name="setinplaceowner"></a>CControlBar::SetInPlaceOwner  
 Altera o proprietário do local de uma barra de controle.  
  
```  
void SetInPlaceOwner(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Um ponteiro para um `CWnd` objeto.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC CTRLBARS](../../visual-cpp-samples.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CToolBar](../../mfc/reference/ctoolbar-class.md)   
 [Classe CDialogBar](../../mfc/reference/cdialogbar-class.md)   
 [Classe CStatusBar](../../mfc/reference/cstatusbar-class.md)   
 [Classe CReBar](../../mfc/reference/crebar-class.md)
