---
title: Classe CMFCDesktopAlertWnd | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCDesktopAlertWnd
dev_langs:
- C++
helpviewer_keywords:
- CMFCDesktopAlertWnd class
ms.assetid: 73a2dd7b-ea84-4ae2-9830-7cf6e8dd2425
caps.latest.revision: 33
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
ms.openlocfilehash: be9d81ffff003119aa7ff9e0cd100c575bd82d36
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcdesktopalertwnd-class"></a>Classe CMFCDesktopAlertWnd
O `CMFCDesktopAlertWnd` classe implementa a funcionalidade de uma caixa de diálogo sem janela restrita que aparece na tela para informar ao usuário sobre um evento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCDesktopAlertWnd : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCDesktopAlertWnd::Create](#create)|Cria e inicializa a janela da área de trabalho de alerta.|  
|[CMFCDesktopAlertWnd::GetAnimationSpeed](#getanimationspeed)|Retorna a velocidade da animação.|  
|[CMFCDesktopAlertWnd::GetAnimationType](#getanimationtype)|Retorna o tipo de animação.|  
|[CMFCDesktopAlertWnd::GetAutoCloseTime](#getautoclosetime)|Retorna o tempo limite de fechamento automático.|  
|[CMFCDesktopAlertWnd::GetCaptionHeight](#getcaptionheight)|Retorna a altura da legenda.|  
|[CMFCDesktopAlertWnd::GetDialogSize](#getdialogsize)||  
|[CMFCDesktopAlertWnd::GetLastPos](#getlastpos)|Retorna a última posição válida da janela de alerta da área de trabalho na tela.|  
|[CMFCDesktopAlertWnd::GetTransparency](#gettransparency)|Retorna o nível de transparência.|  
|[CMFCDesktopAlertWnd::HasSmallCaption](#hassmallcaption)|Determina se a janela da área de trabalho de alerta é exibida com o título pequeno.|  
|[CMFCDesktopAlertWnd::OnBeforeShow](#onbeforeshow)||  
|[CMFCDesktopAlertWnd::OnClickLinkButton](#onclicklinkbutton)|Chamado pela estrutura quando o usuário clica em um botão de link localizado no menu do alerta da área de trabalho.|  
|[CMFCDesktopAlertWnd::OnCommand](#oncommand)|O framework chama essa função membro quando o usuário seleciona um item em um menu, quando um controle filho envia uma mensagem de notificação ou quando um pressionamento de tecla de aceleração é traduzido. (Substitui [CWnd::OnCommand](../../mfc/reference/cwnd-class.md#oncommand).)|  
|[CMFCDesktopAlertWnd::OnDraw](#ondraw)||  
|[CMFCDesktopAlertWnd::ProcessCommand](#processcommand)||  
|[CMFCDesktopAlertWnd::SetAnimationSpeed](#setanimationspeed)|Define a nova velocidade da animação.|  
|[CMFCDesktopAlertWnd::SetAnimationType](#setanimationtype)|Define o tipo de animação.|  
|[CMFCDesktopAlertWnd::SetAutoCloseTime](#setautoclosetime)|Define o tempo limite de fechamento automático.|  
|[CMFCDesktopAlertWnd::SetSmallCaption](#setsmallcaption)|Alterna entre legendas pequenas e normais.|  
|[CMFCDesktopAlertWnd::SetTransparency](#settransparency)|Define o nível de transparência.|  
  
## <a name="remarks"></a>Comentários  
 Uma janela de alerta da área de trabalho pode ser transparente, ele pode aparecer com efeitos de animação e ele pode desaparecer (após um atraso especificado ou quando o usuário descartá-la clicando no botão Fechar).  
  
 Uma janela de alerta da área de trabalho também pode conter uma caixa de diálogo padrão que contém um link, um ícone e texto da mensagem (um rótulo). Como alternativa, uma janela de alerta da área de trabalho pode conter uma caixa de diálogo personalizada dos recursos do aplicativo.  
  
 Você cria uma janela de alerta da área de trabalho em duas etapas. Primeiro, chame o construtor para construir o `CMFCDesktopAlertWnd` objeto. Em segundo lugar, chamar o [CMFCDesktopAlertWnd::Create](#create) a função de membro para criar a janela e anexá-lo a `CMFCDesktopAlertWnd` objeto.  
  
 O `CMFCDesktopAlertWnd` objeto cria uma caixa de diálogo filho especiais que preenche a área cliente da janela do alerta da área de trabalho. A caixa de diálogo possui todos os controles são posicionados nele.  
  
 Para exibir uma caixa de diálogo na janela pop-up, siga estas etapas:  
  
1.  Derivar uma classe de `CMFCDesktopAlertDialog`.  
  
2.  Crie um modelo de caixa de diálogo filho nos recursos.  
  
3.  Chamar [CMFCDesktopAlertWnd::Create](#create) usando a ID de recurso de modelo de caixa de diálogo e um ponteiro para as informações de classe de tempo de execução da classe derivada.  
  
4.  A caixa de diálogo personalizada para manipular todas as notificações proveniente os controles hospedados de programas ou programar os controles hospedados para manipular essas notificações diretamente.  
  
 Use as seguintes funções para controlar o comportamento da janela da área de trabalho de alerta:  
  
-   Definir o tipo de animação chamando [CMFCDesktopAlertWnd::SetAnimationType](#setanimationtype). As opções válidas incluem Desdobrar, slide e desaparecer.  
  
-   Definir a velocidade de quadro de animação chamando [CMFCDesktopAlertWnd::SetAnimationSpeed](#setanimationspeed).  
  
-   Definir o nível de transparência chamando [CMFCDesktopAlertWnd::SetTransparency](#settransparency).  
  
-   Alterar o tamanho da legenda como pequeno chamando [CMFCDesktopAlertWnd::SetSmallCaption](#setsmallcaption). A legenda pequeno é 7 pixels de altura.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir ilustra como usar vários métodos no `CMFCDesktopAlertWnd` classe para configurar um `CMFCDesktopAlertWnd` objeto. O exemplo mostra como definir um tipo de animação, definir a transparência da janela pop-up, especifique que a janela de alerta exibe uma legenda curta e definir o tempo decorrido antes que a janela de alerta é fechado automaticamente. O exemplo também demonstra como criar e inicializar a janela de alerta da área de trabalho. Este trecho de código é parte do [exemplo de demonstração de alerta de área de trabalho](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_DesktopAlertDemo n º&1;](../../mfc/reference/codesnippet/cpp/cmfcdesktopalertwnd-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CMFCDesktopAlertWnd](../../mfc/reference/cmfcdesktopalertwnd-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxDesktopAlertWnd.h  
  
##  <a name="a-namecreatea--cmfcdesktopalertwndcreate"></a><a name="create"></a>CMFCDesktopAlertWnd::Create  
 Cria e inicializa a janela da área de trabalho de alerta.  
  
```  
virtual BOOL Create(
    CWnd* pWndOwner,  
    UINT uiDlgResID,  
    HMENU hMenu = NULL,  
    CPoint ptPos = CPoint(-1,-1),  
    CRuntimeClass* pRTIDlgBar = RUNTIME_CLASS(CMFCDesktopAlertDialog));

 
virtual BOOL Create(
    CWnd* pWndOwner,  
    CMFCDesktopAlertWndInfo& params,  
    HMENU hMenu = NULL,  
    CPoint ptPos = CPoint(-1,-1));
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] [out]`pWndOwner`  
 Especifica o proprietário da janela de alerta. Proprietário receberá todas as notificações para a janela de alerta da área de trabalho. Este valor pode não ser `NULL`.  
  
 [in] `uiDlgResID`  
 Especifica a ID de recurso da janela de alerta.  
  
 [in] `hMenu`  
 Especifica o menu que é exibido quando o usuário clica no botão de menu. Se `NULL`, o botão de menu não é exibido.  
  
 [in] `ptPos`  
 Especifica a posição inicial onde a janela de alerta é exibida, usando coordenadas da tela. Se esse parâmetro for (-1, -1), a janela de alerta é exibida no canto inferior direito da tela.  
  
 [in] `pRTIDlgBar`  
 Informações de classe de tempo de execução para uma classe de caixa de diálogo personalizada que abrange a área cliente da janela do alerta.  
  
 [in] `params`  
 Especifica os parâmetros que são usados para criar uma janela de alerta.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a janela de alerta foi criada com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para criar uma janela de alerta. A área do cliente da janela de alerta contém uma caixa de diálogo filho que hospeda todos os controles que são exibidos para o usuário.  
  
 A primeira sobrecarga do método cria uma janela de alerta que contém uma caixa de diálogo filho que é carregada de recursos do aplicativo. A primeira sobrecarga do método também pode especificar informações de classe de tempo de execução para uma classe de caixa de diálogo personalizada.  
  
 A segunda sobrecarga do método cria uma janela de alerta que contém controles padrão. Você pode especificar os controles para exibir modificando o [CMFCDesktopAlertWndInfo classe](../../mfc/reference/cmfcdesktopalertwndinfo-class.md).  
  
##  <a name="a-namegetanimationspeeda--cmfcdesktopalertwndgetanimationspeed"></a><a name="getanimationspeed"></a>CMFCDesktopAlertWnd::GetAnimationSpeed  
 Retorna a velocidade da animação.  
  
```  
UINT GetAnimationSpeed() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A velocidade da animação da janela do alerta, em milissegundos.  
  
### <a name="remarks"></a>Comentários  
 A velocidade da animação descreve quão rápido à janela alert abre e fecha.  
  
##  <a name="a-namegetanimationtypea--cmfcdesktopalertwndgetanimationtype"></a><a name="getanimationtype"></a>CMFCDesktopAlertWnd::GetAnimationType  
 Retorna o tipo de animação.  
  
```  
CMFCPopupMenu::ANIMATION_TYPE GetAnimationType();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos seguintes tipos de animação:  
  
- `NO_ANIMATION`  
  
- `UNFOLD`  
  
- `SLIDE`  
  
- `FADE`  
  
- `SYSTEM_DEFAULT_ANIMATION`  
  
##  <a name="a-namegetautoclosetimea--cmfcdesktopalertwndgetautoclosetime"></a><a name="getautoclosetime"></a>CMFCDesktopAlertWnd::GetAutoCloseTime  
 Retorna o tempo limite de fechamento automático.  
  
```  
int GetAutoCloseTime() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tempo, em milissegundos, após o qual a alerta janela será fechada automaticamente.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para determinar quanto tempo deve decorrer antes que o alerta janela será fechada automaticamente.  
  
##  <a name="a-namegetcaptionheighta--cmfcdesktopalertwndgetcaptionheight"></a><a name="getcaptionheight"></a>CMFCDesktopAlertWnd::GetCaptionHeight  
 Retorna a altura da legenda.  
  
```  
virtual int GetCaptionHeight();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A altura, em pixels, da legenda.  
  
### <a name="remarks"></a>Comentários  
 Esse método pode ser substituído em uma classe derivada. A implementação padrão de ambos: retorna o valor de altura de legenda pequena (7 pixels) se a janela pop-up deve exibir a legenda pequeno ou o valor obtido com a função de API do Windows `GetSystemMetrics(SM_CYSMCAPTION)`.  
  
##  <a name="a-namegetlastposa--cmfcdesktopalertwndgetlastpos"></a><a name="getlastpos"></a>CMFCDesktopAlertWnd::GetLastPos  
 Retorna a última posição da janela de alerta da área de trabalho na tela.  
  
```  
CPoint GetLastPos() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponto em coordenadas de tela.  
  
### <a name="remarks"></a>Comentários  
 Esse método retorna a última posição válida da janela de alerta na tela.  
  
##  <a name="a-namegettransparencya--cmfcdesktopalertwndgettransparency"></a><a name="gettransparency"></a>CMFCDesktopAlertWnd::GetTransparency  
 Retorna o nível de transparência.  
  
```  
BYTE GetTransparency() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um nível de transparência entre 0 e 255, inclusive. Quanto maior o valor, a mais opaca a janela.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para recuperar o nível de transparência atual da janela de alerta.  
  
##  <a name="a-namehassmallcaptiona--cmfcdesktopalertwndhassmallcaption"></a><a name="hassmallcaption"></a>CMFCDesktopAlertWnd::HasSmallCaption  
 Determina se a janela de alerta da área de trabalho tem uma legenda curta ou uma legenda de tamanho regular.  
  
```  
BOOL HasSmallCaption() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a janela pop-up é exibida com uma legenda pequena; `FALSE` se a janela pop-up é exibida com uma legenda de tamanho regular.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para determinar se a janela pop-up tem uma legenda curta ou uma legenda de tamanho regular. Por padrão, a legenda pequeno é 7 pixels de altura. Você pode obter a altura da legenda do tamanho regular chamando a função de API do Windows `GetSystemMetrics(SM_CYCAPTION)`.  
  
##  <a name="a-nameonbeforeshowa--cmfcdesktopalertwndonbeforeshow"></a><a name="onbeforeshow"></a>CMFCDesktopAlertWnd::OnBeforeShow  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL OnBeforeShow(CPoint&);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `CPoint&`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonclicklinkbuttona--cmfcdesktopalertwndonclicklinkbutton"></a><a name="onclicklinkbutton"></a>CMFCDesktopAlertWnd::OnClickLinkButton  
 Chamado pela estrutura quando o usuário clica em um botão de link localizado no menu do alerta da área de trabalho.  
  
```  
virtual BOOL OnClickLinkButton(UINT uiCmdID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdID`  
 Este parâmetro não é usado.  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Substitua esse método em uma classe derivada se você deseja ser notificado quando um usuário clica no link na janela de alerta.  
  
##  <a name="a-nameoncommanda--cmfcdesktopalertwndoncommand"></a><a name="oncommand"></a>CMFCDesktopAlertWnd::OnCommand  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL OnCommand(
    WPARAM wParam,  
    LPARAM lParam);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `wParam`  
 [in] `lParam`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameondrawa--cmfcdesktopalertwndondraw"></a><a name="ondraw"></a>CMFCDesktopAlertWnd::OnDraw  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void OnDraw(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameprocesscommanda--cmfcdesktopalertwndprocesscommand"></a><a name="processcommand"></a>CMFCDesktopAlertWnd::ProcessCommand  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL ProcessCommand(HWND hwnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hwnd`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetanimationspeeda--cmfcdesktopalertwndsetanimationspeed"></a><a name="setanimationspeed"></a>CMFCDesktopAlertWnd::SetAnimationSpeed  
 Define a nova velocidade da animação.  
  
```  
void SetAnimationSpeed(UINT nSpeed);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nSpeed`  
 Especifica a velocidade da animação novo, em milissegundos.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para definir a velocidade da animação para a janela de alerta. A velocidade da animação padrão é 30 milissegundos.  
  
##  <a name="a-namesetanimationtypea--cmfcdesktopalertwndsetanimationtype"></a><a name="setanimationtype"></a>CMFCDesktopAlertWnd::SetAnimationType  
 Define o tipo de animação.  
  
```  
void SetAnimationType(CMFCPopupMenu::ANIMATION_TYPE type);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `type`  
 Especifica o tipo de animação.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para definir o tipo de animação. É possível especificar um dos seguintes valores:  
  
- `NO_ANIMATION`  
  
- `UNFOLD`  
  
- `SLIDE`  
  
- `FADE`  
  
- `SYSTEM_DEFAULT_ANIMATION`  
  
##  <a name="a-namesetautoclosetimea--cmfcdesktopalertwndsetautoclosetime"></a><a name="setautoclosetime"></a>CMFCDesktopAlertWnd::SetAutoCloseTime  
 Define o tempo limite de fechamento automático.  
  
```  
void SetAutoCloseTime(int nTime);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nTime`  
 O tempo, em milissegundos, que expira antes que a janela de alerta é fechado automaticamente.  
  
### <a name="remarks"></a>Comentários  
 A janela de alerta é fechada automaticamente após o período especificado se o usuário interage com a janela.  
  
##  <a name="a-namesetsmallcaptiona--cmfcdesktopalertwndsetsmallcaption"></a><a name="setsmallcaption"></a>CMFCDesktopAlertWnd::SetSmallCaption  
 Alterna entre legendas pequenas e de tamanho regular.  
  
```  
void SetSmallCaption(BOOL bSmallCaption = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bSmallCaption`  
 `TRUE`para especificar que a janela de alerta exibe uma legenda curta; Caso contrário, `FALSE` para especificar que a janela de alerta exibe uma legenda de tamanho regular.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para exibir a legenda pequena ou tamanho regular. Por padrão, a legenda pequeno é 7 pixels de altura. Você pode obter o tamanho da legenda regular chamando a função de API do Windows `GetSystemMetrics(SM_CYCAPTION)`.  
  
##  <a name="a-namesettransparencya--cmfcdesktopalertwndsettransparency"></a><a name="settransparency"></a>CMFCDesktopAlertWnd::SetTransparency  
 Define o nível de transparência da janela pop-up.  
  
```  
void SetTransparency(BYTE nTransparency);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nTransparency`  
 Especifica o nível de transparência. Esse valor deve estar entre 0 e 255, inclusive. Quanto maior o valor, a mais opaca a janela.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para definir o nível de transparência da janela pop-up.  
  
##  <a name="a-namegetdialogsizea--cmfcdesktopalertwndgetdialogsize"></a><a name="getdialogsize"></a>CMFCDesktopAlertWnd::GetDialogSize  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual CSize GetDialogSize();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCDesktopAlertWndInfo](../../mfc/reference/cmfcdesktopalertwndinfo-class.md)   
 [Classe CMFCDesktopAlertDialog](../../mfc/reference/cmfcdesktopalertdialog-class.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)

