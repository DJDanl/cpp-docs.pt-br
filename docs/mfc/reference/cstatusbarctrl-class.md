---
title: Classe CStatusBarCtrl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CStatusBarCtrl
- AFXCMN/CStatusBarCtrl
- AFXCMN/CStatusBarCtrl::CStatusBarCtrl
- AFXCMN/CStatusBarCtrl::Create
- AFXCMN/CStatusBarCtrl::CreateEx
- AFXCMN/CStatusBarCtrl::DrawItem
- AFXCMN/CStatusBarCtrl::GetBorders
- AFXCMN/CStatusBarCtrl::GetIcon
- AFXCMN/CStatusBarCtrl::GetParts
- AFXCMN/CStatusBarCtrl::GetRect
- AFXCMN/CStatusBarCtrl::GetText
- AFXCMN/CStatusBarCtrl::GetTextLength
- AFXCMN/CStatusBarCtrl::GetTipText
- AFXCMN/CStatusBarCtrl::IsSimple
- AFXCMN/CStatusBarCtrl::SetBkColor
- AFXCMN/CStatusBarCtrl::SetIcon
- AFXCMN/CStatusBarCtrl::SetMinHeight
- AFXCMN/CStatusBarCtrl::SetParts
- AFXCMN/CStatusBarCtrl::SetSimple
- AFXCMN/CStatusBarCtrl::SetText
- AFXCMN/CStatusBarCtrl::SetTipText
dev_langs: C++
helpviewer_keywords:
- CStatusBarCtrl [MFC], CStatusBarCtrl
- CStatusBarCtrl [MFC], Create
- CStatusBarCtrl [MFC], CreateEx
- CStatusBarCtrl [MFC], DrawItem
- CStatusBarCtrl [MFC], GetBorders
- CStatusBarCtrl [MFC], GetIcon
- CStatusBarCtrl [MFC], GetParts
- CStatusBarCtrl [MFC], GetRect
- CStatusBarCtrl [MFC], GetText
- CStatusBarCtrl [MFC], GetTextLength
- CStatusBarCtrl [MFC], GetTipText
- CStatusBarCtrl [MFC], IsSimple
- CStatusBarCtrl [MFC], SetBkColor
- CStatusBarCtrl [MFC], SetIcon
- CStatusBarCtrl [MFC], SetMinHeight
- CStatusBarCtrl [MFC], SetParts
- CStatusBarCtrl [MFC], SetSimple
- CStatusBarCtrl [MFC], SetText
- CStatusBarCtrl [MFC], SetTipText
ms.assetid: 8504ad38-7b91-4746-aede-ac98886eb47b
caps.latest.revision: "20"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3ee095257ddf3fd322a7e42e3f6fff6ac7cec76a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cstatusbarctrl-class"></a>Classe CStatusBarCtrl
Fornece a funcionalidade de controle de barra de status comuns do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CStatusBarCtrl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStatusBarCtrl::CStatusBarCtrl](#cstatusbarctrl)|Constrói um objeto `CStatusBarCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CStatusBarCtrl::Create](#create)|Cria um controle de barra de status e a anexa a um `CStatusBarCtrl` objeto.|  
|[CStatusBarCtrl::CreateEx](#createex)|Cria um controle de barra de status com os estilos estendidos do Windows especificados e anexa-o para um `CStatusBarCtrl` objeto.|  
|[CStatusBarCtrl::DrawItem](#drawitem)|Chamado quando um aspecto visual de um alterações de controle de barra de status de desenho do proprietário.|  
|[CStatusBarCtrl::GetBorders](#getborders)|Recupera as larguras atuais das bordas horizontais e verticais de um controle de barra de status.|  
|[CStatusBarCtrl::GetIcon](#geticon)|Recupera o ícone para uma parte (também conhecido como um painel) no controle de barra de status atual.|  
|[CStatusBarCtrl::GetParts](#getparts)|Recupera uma contagem das partes em um controle de barra de status.|  
|[CStatusBarCtrl::GetRect](#getrect)|Recupera o retângulo delimitador de uma parte de um controle de barra de status.|  
|[CStatusBarCtrl::GetText](#gettext)|Recupera o texto da determinada parte de um controle de barra de status.|  
|[CStatusBarCtrl::GetTextLength](#gettextlength)|Recupere o comprimento, em caracteres, do texto da determinada parte de um controle de barra de status.|  
|[CStatusBarCtrl::GetTipText](#gettiptext)|Recupera o texto de dica de ferramenta para um painel em uma barra de status.|  
|[CStatusBarCtrl::IsSimple](#issimple)|Verifica se um controle de janela de status para determinar se ele está no modo simples.|  
|[CStatusBarCtrl::SetBkColor](#setbkcolor)|Define a cor de plano de fundo na barra de status.|  
|[CStatusBarCtrl::SetIcon](#seticon)|Define o ícone para um painel em uma barra de status.|  
|[CStatusBarCtrl::SetMinHeight](#setminheight)|Define a altura mínima de status de uma área de desenho do controle da barra.|  
|[CStatusBarCtrl::SetParts](#setparts)|Define o número de partes em uma barra de controle e a coordenada da borda direita de cada parte de status.|  
|[CStatusBarCtrl::SetSimple](#setsimple)|Especifica se um controle de barra de status exibe o texto simples ou todas as partes do controle definidas por uma chamada anterior para `SetParts`.|  
|[CStatusBarCtrl::SetText](#settext)|Define o texto na determinada parte de um controle de barra de status.|  
|[CStatusBarCtrl::SetTipText](#settiptext)|Define o texto de dica de ferramenta para um painel em uma barra de status.|  
  
## <a name="remarks"></a>Comentários  
 Um "controle de barra de status" é uma janela horizontal, normalmente é exibida na parte inferior de uma janela pai, em que um aplicativo pode exibir vários tipos de informações de status. O controle de barra de status pode ser dividido em partes para exibir mais de um tipo de informação.  
  
 Esse controle (e, portanto, o `CStatusBarCtrl` classe) está disponível apenas para programas em execução na versão do Windows 95/98 e Windows NT 3.51 e posterior.  
  
 Para obter mais informações sobre como usar `CStatusBarCtrl`, consulte [controles](../../mfc/controls-mfc.md) e [usando CStatusBarCtrl](../../mfc/using-cstatusbarctrl.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CStatusBarCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn.h  
  
##  <a name="create"></a>CStatusBarCtrl::Create  
 Cria um controle de barra de status e a anexa a um `CStatusBarCtrl` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Especifica o estilo do controle de barra de status. Aplique qualquer combinação de estilos de controle listados da barra de status [estilos de controle comuns](http://msdn.microsoft.com/library/windows/desktop/bb775498) no SDK do Windows. Esse parâmetro deve incluir o **WS_CHILD** estilo. Ele também deve incluir o **WS_VISIBLE** estilo.  
  
 `rect`  
 Especifica o tamanho e a posição do controle de barra de status. Ele pode ser um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura.  
  
 `pParentWnd`  
 Especifica o janela do pai do controle, da barra de status geralmente um `CDialog`. Ele não deve ser **nulo.**  
  
 `nID`  
 Especifica a identificação. do controle de barra de status  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Você pode criar um `CStatusBarCtrl` em duas etapas. Primeiro, chame o construtor e, em seguida, chamar **criar**, que cria o controle de barra de status e anexa-o para o `CStatusBarCtrl` objeto.  
  
 É a posição padrão de uma janela de status na parte inferior da janela pai, mas você pode especificar o `CCS_TOP` estilo para que ele apareça na parte superior da área cliente da janela pai. Você pode especificar o **SBARS_SIZEGRIP** estilo para incluir uma alça de dimensionamento na extremidade direita da janela de status. Combinando o `CCS_TOP` e **SBARS_SIZEGRIP** estilos não é recomendado porque a alça de dimensionamento resultante não está funcionando, mesmo que o sistema desenha na janela de status.  
  
 Para criar uma barra de status com estilos de janela estendidos, chame [CStatusBarCtrl::CreateEx](#createex) em vez de **criar**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatusBarCtrl#1](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_1.cpp)]  
  
##  <a name="createex"></a>CStatusBarCtrl::CreateEx  
 Cria um controle (uma janela filho) e o associa a `CStatusBarCtrl` objeto.  
  
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
 Especifica o estilo do controle de barra de status. Aplique qualquer combinação de estilos de controle listados da barra de status [estilos de controle comuns](http://msdn.microsoft.com/library/windows/desktop/bb775498) no SDK do Windows. Esse parâmetro deve incluir o **WS_CHILD** estilo. Ele também deve incluir o **WS_VISIBLE** estilo.  
  
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
  
##  <a name="cstatusbarctrl"></a>CStatusBarCtrl::CStatusBarCtrl  
 Constrói um objeto `CStatusBarCtrl`.  
  
```  
CStatusBarCtrl();
```  
  
##  <a name="drawitem"></a>CStatusBarCtrl::DrawItem  
 Chamado pelo framework quando um aspecto visual de um alterações de controle de barra de status de desenho do proprietário.  
  
```  
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpDrawItemStruct`  
 Um ponteiro de tempo para um [DRAWITEMSTRUCT](http://msdn.microsoft.com/library/windows/desktop/bb775802) estrutura que contém informações sobre o tipo de desenho necessárias.  
  
### <a name="remarks"></a>Comentários  
 O **itemAction** membro o `DRAWITEMSTRUCT` estrutura define a ação de desenho que deve ser executada.  
  
 Por padrão, essa função de membro não faz nada. Substituir essa função de membro para implementar o desenho de um desenho proprietário `CStatusBarCtrl` objeto.  
  
 O aplicativo deve restaurar todos os objetos de interface (GDI) do dispositivo gráficos selecionados para o contexto de exibição fornecido no `lpDrawItemStruct` antes desse membro função termina.  
  
##  <a name="getborders"></a>CStatusBarCtrl::GetBorders  
 Recupera atual as larguras do controle barra de status bordas horizontais e verticais e do espaço entre os retângulos.  
  
```  
BOOL GetBorders(int* pBorders) const;  
  
BOOL GetBorders(
    int& nHorz,  
    int& nVert,  
    int& nSpacing) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pBorders*  
 Endereço de uma matriz de inteiros com três elementos. O primeiro elemento recebe a largura da borda horizontal, a segunda recebe a largura da borda vertical e o terceiro recebe a largura da borda entre os retângulos.  
  
 *nHorz*  
 Referência a um número inteiro que recebe a largura da borda horizontal.  
  
 *nverter*  
 Referência a um número inteiro que recebe a largura da borda vertical.  
  
 *nSpacing*  
 Referência a um número inteiro que recebe a largura da borda entre os retângulos.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Essas áreas determinam o espaçamento entre a borda externa do controle e os retângulos que contêm texto dentro do controle.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatusBarCtrl#2](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_2.cpp)]  
  
##  <a name="geticon"></a>CStatusBarCtrl::GetIcon  
 Recupera o ícone para uma parte (também conhecido como um painel) no controle de barra de status atual.  
  
```  
HICON GetIcon(int iPart) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `iPart`|O índice baseado em zero da parte que contém o ícone a ser recuperado. Se esse parâmetro for -1, a barra de status é considerada uma barra de status de modo simples.|  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador para o ícone se o método bem-sucedida; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia o [SB_GETICON](http://msdn.microsoft.com/library/windows/desktop/bb760744) mensagem, que é descrita no SDK do Windows.  
  
 Consiste em um controle de barra de status de uma linha de texto de painéis de saída, que também são conhecidas como partes. Para obter mais informações sobre a barra de status, consulte [implementação da barra de Status no MFC](../../mfc/status-bar-implementation-in-mfc.md) e [definindo o modo de um objeto CStatusBarCtrl](../../mfc/setting-the-mode-of-a-cstatusbarctrl-object.md).  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define uma variável, `m_statusBar`, que é usado para acessar o controle de barra de status atual. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CStatusBarCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_3.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir copia um ícone para dois painéis de controle de barra de status atual. Em uma seção anterior, o exemplo de código é criado um controle de barra de status com três painéis e, em seguida, adicionar um ícone para o primeiro painel. Este exemplo recupera o ícone do primeiro painel e o adiciona ao painel segundo e terceiro.  
  
 [!code-cpp[NVC_MFC_CStatusBarCtrl_s1#2](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_4.cpp)]  
  
##  <a name="getparts"></a>CStatusBarCtrl::GetParts  
 Recupera uma contagem das partes em um controle de barra de status.  
  
```  
int GetParts(
    int nParts,  
    int* pParts) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nParts`  
 Número de partes para o qual recuperar coordenadas. Se esse parâmetro for maior que o número de partes no controle, a mensagem recupera coordenadas para somente partes existentes.  
  
 *pParts*  
 Endereço de uma matriz de inteiros que têm o mesmo número de elementos como o número de partes especificadas pela `nParts`. Cada elemento na matriz recebe a coordenada de cliente da borda direita da parte correspondente. Se um elemento for definido como - 1, a posição da borda direita para essa parte se estende para a borda direita da barra de status.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de partes de controle se for bem-sucedido, ou zero caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro também recupera a coordenada da borda direita do número especificado de partes.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatusBarCtrl#3](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_5.cpp)]  
  
##  <a name="getrect"></a>CStatusBarCtrl::GetRect  
 Recupera o retângulo delimitador de uma parte de um controle de barra de status.  
  
```  
BOOL GetRect(
    int nPane,  
    LPRECT lpRect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPane`  
 Índice de base zero da parte é cujo retângulo delimitador a ser recuperado.  
  
 `lpRect`  
 Endereço de um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que recebe o retângulo delimitador.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatusBarCtrl#4](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_6.cpp)]  
  
##  <a name="gettext"></a>CStatusBarCtrl::GetText  
 Recupera o texto da determinada parte de um controle de barra de status.  
  
```  
CString GetText(
    int nPane,  
    int* pType = NULL) const;  
  
int GetText(
    LPCTSTR lpszText,  
    int nPane,  
    int* pType = NULL) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszText`  
 Endereço do buffer que recebe o texto. Este parâmetro é uma cadeia de caracteres terminada em nulo.  
  
 `nPane`  
 Índice de base zero da parte do qual recuperar o texto.  
  
 `pType`  
 Ponteiro para um inteiro que recebe as informações de tipo. O tipo pode ser um destes valores:  
  
- **0** o texto é desenhado com uma borda apareça menor do que o plano da barra de status.  
  
- `SBT_NOBORDERS`O texto é desenhado sem bordas.  
  
- `SBT_POPOUT`O texto é desenhado com uma borda apareça maior do que o plano da barra de status.  
  
- `SBT_OWNERDRAW`Se o texto tem o `SBT_OWNERDRAW` , o tipo de desenho `pType` recebe essa mensagem e retorna o valor de 32 bits associado com o texto em vez do tipo de comprimento e a operação.  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento, em caracteres, do texto ou um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém o texto atual.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatusBarCtrl#5](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_7.cpp)]  
  
##  <a name="gettextlength"></a>CStatusBarCtrl::GetTextLength  
 Recupera o comprimento, em caracteres, do texto da determinada parte de um controle de barra de status.  
  
```  
int GetTextLength(
    int nPane,  
    int* pType = NULL) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPane`  
 Índice de base zero da parte do qual recuperar o texto.  
  
 `pType`  
 Ponteiro para um inteiro que recebe as informações de tipo. O tipo pode ser um destes valores:  
  
- **0** o texto é desenhado com uma borda apareça menor do que o plano da barra de status.  
  
- `SBT_NOBORDERS`O texto é desenhado sem bordas.  
  
- `SBT_OWNERDRAW`O texto é desenhado pela janela pai.  
  
- `SBT_POPOUT`O texto é desenhado com uma borda apareça maior do que o plano da barra de status.  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento, em caracteres, do texto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatusBarCtrl#6](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_8.cpp)]  
  
##  <a name="gettiptext"></a>CStatusBarCtrl::GetTipText  
 Recupera o texto de dica de ferramenta para um painel em uma barra de status.  
  
```  
CString GetTipText(int nPane) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPane`  
 O índice com base em zero do painel da barra de status para receber o texto de dica de ferramenta.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém o texto a ser usado na dica de ferramenta.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [SB_GETTIPTEXT](http://msdn.microsoft.com/library/windows/desktop/bb760751), conforme descrito no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatusBarCtrl#7](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_9.cpp)]  
  
##  <a name="issimple"></a>CStatusBarCtrl::IsSimple  
 Verifica se um controle de janela de status para determinar se ele está no modo simples.  
  
```  
BOOL IsSimple() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o controle de janela de status está no modo simple; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [SB_ISSIMPLE](http://msdn.microsoft.com/library/windows/desktop/bb760753), conforme descrito no SDK do Windows.  
  
##  <a name="setbkcolor"></a>CStatusBarCtrl::SetBkColor  
 Define a cor de plano de fundo na barra de status.  
  
```  
COLORREF SetBkColor(COLORREF cr);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cr`  
 **COLORREF** valor que especifica a nova cor do plano de fundo. Especifique o `CLR_DEFAULT` valor para fazer com que a barra de status usar a cor de plano de fundo padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [COLORREF](http://msdn.microsoft.com/library/windows/desktop/dd183449) valor que representa a cor de plano de fundo padrão anterior.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [SB_SETBKCOLOR](http://msdn.microsoft.com/library/windows/desktop/bb760754), conforme descrito no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatusBarCtrl#8](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_10.cpp)]  
  
##  <a name="seticon"></a>CStatusBarCtrl::SetIcon  
 Define o ícone para um painel em uma barra de status.  
  
```  
BOOL SetIcon(
    int nPane,  
    HICON hIcon);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPane`  
 O índice de base zero do painel que receberá o ícone. Se esse parâmetro for -1, a barra de status é considerada uma barra de status simples.  
  
 `hIcon`  
 Identificador para o ícone a ser definido. Se esse valor for **nulo**, o ícone é removido da parte.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [SB_SETICON](http://msdn.microsoft.com/library/windows/desktop/bb760755), conforme descrito no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CStatusBarCtrl::SetBkColor](#setbkcolor).  
  
##  <a name="setminheight"></a>CStatusBarCtrl::SetMinHeight  
 Define a altura mínima de status de uma área de desenho do controle da barra.  
  
```  
void SetMinHeight(int nMin);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMin`  
 Altura mínima, em pixels, do controle.  
  
### <a name="remarks"></a>Comentários  
 A altura mínima é a soma de `nMin` e duas vezes a largura, em pixels, da borda vertical do controle da barra de status.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatusBarCtrl#9](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_11.cpp)]  
  
##  <a name="setparts"></a>CStatusBarCtrl::SetParts  
 Define o número de partes em uma barra de controle e a coordenada da borda direita de cada parte de status.  
  
```  
BOOL SetParts(
    int nParts,  
    int* pWidths);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nParts`  
 Número de partes de conjunto. O número de partes não pode ser maior que 255.  
  
 *pWidths*  
 Endereço de uma matriz de inteiros que têm o mesmo número de elementos como partes especificadas pela `nParts`. Cada elemento na matriz Especifica a posição, nas coordenadas do cliente, da borda direita da parte correspondente. Se um elemento for - 1, a posição da borda direita para essa parte se estende para a borda direita do controle.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatusBarCtrl#10](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_12.cpp)]  
  
##  <a name="setsimple"></a>CStatusBarCtrl::SetSimple  
 Especifica se um controle de barra de status exibe o texto simples ou todas as partes do controle definidas por uma chamada anterior a [SetParts](#setparts).  
  
```  
BOOL SetSimple(BOOL bSimple = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bSimple`  
 Sinalizador de tipo de exibição. Se esse parâmetro for `TRUE`, o controle exibe texto simples; se for `FALSE`, ele exibe várias partes.  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna 0.  
  
### <a name="remarks"></a>Comentários  
 Se seu aplicativo altera o controle de barra de status de não simples como simple ou vice-versa, o sistema imediatamente redesenha o controle.  
  
##  <a name="settext"></a>CStatusBarCtrl::SetText  
 Define o texto na determinada parte de um controle de barra de status.  
  
```  
BOOL SetText(
    LPCTSTR lpszText,  
    int nPane,  
    int nType);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszText`  
 Endereço de uma cadeia de caracteres terminada em nulo especificando o texto a ser definido. Se `nType` é `SBT_OWNERDRAW`, `lpszText` representa 32 bits de dados.  
  
 `nPane`  
 Índice de base zero da parte definido. Se esse valor é 255, o controle de barra de status é considerado um controle simples com apenas uma parte.  
  
 `nType`  
 Tipo de operação de desenho. Consulte [mensagem SB_SETTEXT](http://msdn.microsoft.com/library/bb760758\(vs.85\).aspx) para obter uma lista de valores possíveis.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 A mensagem invalida a parte do controle que foi alterada, fazendo com que ele exibir o novo texto quando o controle recebe lado a `WM_PAINT` mensagem.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatusBarCtrl#11](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_13.cpp)]  
  
##  <a name="settiptext"></a>CStatusBarCtrl::SetTipText  
 Define o texto de dica de ferramenta para um painel em uma barra de status.  
  
```  
void SetTipText(
    int nPane,  
    LPCTSTR pszTipText);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nPane`  
 O índice com base em zero do painel da barra de status para receber o texto de dica de ferramenta.  
  
 *pszTipText*  
 Um ponteiro para uma cadeia de caracteres que contém o texto de dica de ferramenta.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem de Win32 [SB_SETTIPTEXT](http://msdn.microsoft.com/library/windows/desktop/bb760759), conforme descrito no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CStatusBarCtrl#12](../../mfc/reference/codesnippet/cpp/cstatusbarctrl-class_14.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CToolBarCtrl](../../mfc/reference/ctoolbarctrl-class.md)
