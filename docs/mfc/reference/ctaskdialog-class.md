---
title: Classe CTaskDialog | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CTaskDialog
- AFXTASKDIALOG/CTaskDialog
- AFXTASKDIALOG/CTaskDialog::CTaskDialog
- AFXTASKDIALOG/CTaskDialog::AddCommandControl
- AFXTASKDIALOG/CTaskDialog::AddRadioButton
- AFXTASKDIALOG/CTaskDialog::ClickCommandControl
- AFXTASKDIALOG/CTaskDialog::ClickRadioButton
- AFXTASKDIALOG/CTaskDialog::DoModal
- AFXTASKDIALOG/CTaskDialog::GetCommonButtonCount
- AFXTASKDIALOG/CTaskDialog::GetCommonButtonFlag
- AFXTASKDIALOG/CTaskDialog::GetCommonButtonId
- AFXTASKDIALOG/CTaskDialog::GetOptions
- AFXTASKDIALOG/CTaskDialog::GetSelectedCommandControlID
- AFXTASKDIALOG/CTaskDialog::GetSelectedRadioButtonID
- AFXTASKDIALOG/CTaskDialog::GetVerificationCheckboxState
- AFXTASKDIALOG/CTaskDialog::IsCommandControlEnabled
- AFXTASKDIALOG/CTaskDialog::IsRadioButtonEnabled
- AFXTASKDIALOG/CTaskDialog::IsSupported
- AFXTASKDIALOG/CTaskDialog::LoadCommandControls
- AFXTASKDIALOG/CTaskDialog::LoadRadioButtons
- AFXTASKDIALOG/CTaskDialog::NavigateTo
- AFXTASKDIALOG/CTaskDialog::OnCommandControlClick
- AFXTASKDIALOG/CTaskDialog::OnCreate
- AFXTASKDIALOG/CTaskDialog::OnDestroy
- AFXTASKDIALOG/CTaskDialog::OnExpandButtonClick
- AFXTASKDIALOG/CTaskDialog::OnHelp
- AFXTASKDIALOG/CTaskDialog::OnHyperlinkClick
- AFXTASKDIALOG/CTaskDialog::OnInit
- AFXTASKDIALOG/CTaskDialog::OnNavigatePage
- AFXTASKDIALOG/CTaskDialog::OnRadioButtonClick
- AFXTASKDIALOG/CTaskDialog::OnTimer
- AFXTASKDIALOG/CTaskDialog::OnVerificationCheckboxClick
- AFXTASKDIALOG/CTaskDialog::RemoveAllCommandControls
- AFXTASKDIALOG/CTaskDialog::RemoveAllRadioButtons
- AFXTASKDIALOG/CTaskDialog::SetCommandControlOptions
- AFXTASKDIALOG/CTaskDialog::SetCommonButtonOptions
- AFXTASKDIALOG/CTaskDialog::SetCommonButtons
- AFXTASKDIALOG/CTaskDialog::SetContent
- AFXTASKDIALOG/CTaskDialog::SetDefaultCommandControl
- AFXTASKDIALOG/CTaskDialog::SetDefaultRadioButton
- AFXTASKDIALOG/CTaskDialog::SetDialogWidth
- AFXTASKDIALOG/CTaskDialog::SetExpansionArea
- AFXTASKDIALOG/CTaskDialog::SetFooterIcon
- AFXTASKDIALOG/CTaskDialog::SetFooterText
- AFXTASKDIALOG/CTaskDialog::SetMainIcon
- AFXTASKDIALOG/CTaskDialog::SetMainInstruction
- AFXTASKDIALOG/CTaskDialog::SetOptions
- AFXTASKDIALOG/CTaskDialog::SetProgressBarMarquee
- AFXTASKDIALOG/CTaskDialog::SetProgressBarPosition
- AFXTASKDIALOG/CTaskDialog::SetProgressBarRange
- AFXTASKDIALOG/CTaskDialog::SetProgressBarState
- AFXTASKDIALOG/CTaskDialog::SetRadioButtonOptions
- AFXTASKDIALOG/CTaskDialog::SetVerificationCheckbox
- AFXTASKDIALOG/CTaskDialog::SetVerificationCheckboxText
- AFXTASKDIALOG/CTaskDialog::SetWindowTitle
- AFXTASKDIALOG/CTaskDialog::ShowDialog
- AFXTASKDIALOG/CTaskDialog::TaskDialogCallback
dev_langs:
- C++
helpviewer_keywords:
- CTaskDialog class
ms.assetid: 1991ec98-ae56-4483-958b-233809c8c559
caps.latest.revision: 29
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
ms.openlocfilehash: 46de64825de9f824ce3d0a5d0c74b7cdc2352774
ms.lasthandoff: 02/25/2017

---
# <a name="ctaskdialog-class"></a>Classe CTaskDialog
Uma caixa de diálogo pop-up que funciona como uma caixa de mensagem, mas pode exibir informações adicionais para o usuário. O `CTaskDialog` também inclui a funcionalidade para coletar informações do usuário.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CTaskDialog : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[CTaskDialog::CTaskDialog](#ctaskdialog)|Constrói um objeto `CTaskDialog`.|  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[CTaskDialog::AddCommandControl](#addcommandcontrol)|Adiciona um controle de botão de comando para o `CTaskDialog`.|  
|[CTaskDialog::AddRadioButton](#addradiobutton)|Adiciona um botão de opção para o `CTaskDialog`.|  
|[CTaskDialog::ClickCommandControl](#clickcommandcontrol)|Clica em um controle de botão de comando ou botão comum por meio de programação.|  
|[CTaskDialog::ClickRadioButton](#clickradiobutton)|Clica em um botão de opção programaticamente.|  
|[CTaskDialog::DoModal](#domodal)|Exibe o `CTaskDialog`.|  
|[CTaskDialog::GetCommonButtonCount](#getcommonbuttoncount)|Recupera o número de botões comuns disponíveis.|  
|[CTaskDialog::GetCommonButtonFlag](#getcommonbuttonflag)|Converte um padrão de botão do Windows para o tipo de botão comuns associado a `CTaskDialog` classe.|  
|[CTaskDialog::GetCommonButtonId](#getcommonbuttonid)|Converte um dos tipos de botão comuns associados a `CTaskDialog` classe a um botão padrão do Windows.|  
|[CTaskDialog::GetOptions](#getoptions)|Retorna os sinalizadores de opção para este `CTaskDialog`.|  
|[CTaskDialog::GetSelectedCommandControlID](#getselectedcommandcontrolid)|Retorna o controle de botão de comando selecionado.|  
|[CTaskDialog::GetSelectedRadioButtonID](#getselectedradiobuttonid)|Retorna o botão de opção selecionado.|  
|[CTaskDialog::GetVerificationCheckboxState](#getverificationcheckboxstate)|Recupera o estado da caixa de seleção de verificação.|  
|[CTaskDialog::IsCommandControlEnabled](#iscommandcontrolenabled)|Determina se um controle de botão de comando ou botão comum está habilitada.|  
|[CTaskDialog::IsRadioButtonEnabled](#isradiobuttonenabled)|Determina se um botão de opção é habilitado.|  
|[CTaskDialog::IsSupported](#issupported)|Determina se o computador que está executando o aplicativo oferece suporte a `CTaskDialog`.|  
|[CTaskDialog::LoadCommandControls](#loadcommandcontrols)|Adiciona controles de botão de comando usando dados da tabela de cadeia de caracteres.|  
|[CTaskDialog::LoadRadioButtons](#loadradiobuttons)|Adiciona botões de opção usando dados da tabela de cadeia de caracteres.|  
|[CTaskDialog::NavigateTo](#navigateto)|Transfere o foco para outra `CTaskDialog`.|  
|[CTaskDialog::OnCommandControlClick](#oncommandcontrolclick)|O framework chama esse método quando o usuário clica em um controle de botão de comando.|  
|[CTaskDialog::OnCreate](#oncreate)|O framework chama esse método depois que ele cria o `CTaskDialog`.|  
|[CTaskDialog::OnDestroy](#ondestroy)|O framework chama esse método imediatamente antes ele destrói o `CTaskDialog`.|  
|[CTaskDialog::OnExpandButtonClick](#onexpandbuttonclick)|O framework chama esse método quando o usuário clica no botão de expansão.|  
|[CTaskDialog::OnHelp](#onhelp)|O framework chama esse método quando o usuário solicita ajuda.|  
|[CTaskDialog::OnHyperlinkClick](#onhyperlinkclick)|O framework chama esse método quando o usuário clica em um hiperlink.|  
|[CTaskDialog::OnInit](#oninit)|O framework chama esse método quando o `CTaskDialog` é inicializado.|  
|[CTaskDialog::OnNavigatePage](#onnavigatepage)|O framework chama esse método quando o usuário move o foco em relação a controles o `CTaskDialog`.|  
|[CTaskDialog::OnRadioButtonClick](#onradiobuttonclick)|O framework chama esse método quando o usuário seleciona um controle de botão de opção.|  
|[CTaskDialog::OnTimer](#ontimer)|O framework chama esse método quando o temporizador expirar.|  
|[CTaskDialog::OnVerificationCheckboxClick](#onverificationcheckboxclick)|O framework chama esse método quando o usuário clica a caixa de seleção de verificação.|  
|[CTaskDialog::RemoveAllCommandControls](#removeallcommandcontrols)|Remove todos os controles de comando da `CTaskDialog`.|  
|[CTaskDialog::RemoveAllRadioButtons](#removeallradiobuttons)|Remove todos os botões de opção de `CTaskDialog`.|  
|[CTaskDialog::SetCommandControlOptions](#setcommandcontroloptions)|Atualiza um controle de botão de comando na `CTaskDialog`.|  
|[CTaskDialog::SetCommonButtonOptions](#setcommonbuttonoptions)|Atualiza um subconjunto dos botões comuns para ser habilitado e que exigem elevação do UAC.|  
|[CTaskDialog::SetCommonButtons](#setcommonbuttons)|Adiciona botões comuns para o `CTaskDialog`.|  
|[CTaskDialog::SetContent](#setcontent)|Atualiza o conteúdo do `CTaskDialog`.|  
|[CTaskDialog::SetDefaultCommandControl](#setdefaultcommandcontrol)|Especifica o controle de botão de comando padrão.|  
|[CTaskDialog::SetDefaultRadioButton](#setdefaultradiobutton)|Especifica o botão padrão.|  
|[CTaskDialog::SetDialogWidth](#setdialogwidth)|Ajusta a largura do `CTaskDialog`.|  
|[CTaskDialog::SetExpansionArea](#setexpansionarea)|Atualiza a área de expansão do `CTaskDialog`.|  
|[CTaskDialog::SetFooterIcon](#setfootericon)|Atualiza o ícone de rodapé para a `CTaskDialog`.|  
|[CTaskDialog::SetFooterText](#setfootertext)|Atualiza o texto no rodapé do `CTaskDialog`.|  
|[CTaskDialog::SetMainIcon](#setmainicon)|O ícone principal de atualizações de `CTaskDialog`.|  
|[CTaskDialog::SetMainInstruction](#setmaininstruction)|Atualiza a instrução principal do `CTaskDialog`.|  
|[CTaskDialog::SetOptions](#setoptions)|Configura as opções para o `CTaskDialog`.|  
|[CTaskDialog::SetProgressBarMarquee](#setprogressbarmarquee)|Configura uma barra de marca de seleção para o `CTaskDialog` e o adiciona à caixa de diálogo.|  
|[CTaskDialog::SetProgressBarPosition](#setprogressbarposition)|Ajusta a posição da barra de progresso.|  
|[CTaskDialog::SetProgressBarRange](#setprogressbarrange)|Ajusta o intervalo da barra de progresso.|  
|[CTaskDialog::SetProgressBarState](#setprogressbarstate)|Define o estado da barra de progresso e exibe-os na `CTaskDialog`.|  
|[CTaskDialog::SetRadioButtonOptions](#setradiobuttonoptions)|Habilita ou desabilita um botão de opção.|  
|[CTaskDialog::SetVerificationCheckbox](#setverificationcheckbox)|Define o estado da caixa de seleção de verificação selecionado.|  
|[CTaskDialog::SetVerificationCheckboxText](#setverificationcheckboxtext)|Define o texto no lado direito da caixa de seleção de verificação.|  
|[CTaskDialog::SetWindowTitle](#setwindowtitle)|Define o título do `CTaskDialog`.|  
|[CTaskDialog::ShowDialog](#showdialog)|Cria e exibe um `CTaskDialog`.|  
|[CTaskDialog::TaskDialogCallback](#taskdialogcallback)|O framework chama isso em resposta a várias mensagens do Windows.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|`m_aButtons`|A matriz de controles de botão de comando para o `CTaskDialog`.|  
|`m_aRadioButtons`|A matriz de controles de botão de opção para o `CTaskDialog`.|  
|`m_bVerified`|`TRUE`indica que a caixa de seleção de verificação está marcada. `FALSE` indica que não é.|  
|`m_footerIcon`|O ícone no rodapé do `CTaskDialog`.|  
|`m_hWnd`|Um identificador para a janela para o `CTaskDialog`.|  
|`m_mainIcon`|O ícone principal do `CTaskDialog`.|  
|`m_nButtonDisabled`|Uma máscara que indica quais dos botões comuns estão desabilitados.|  
|`m_nButtonElevation`|Uma máscara que indica quais dos botões comuns exigem elevação do UAC.|  
|`m_nButtonId`|A ID do controle de botão de comando selecionado.|  
|`m_nCommonButton`|Uma máscara que indica quais botões comuns são exibidos na `CTaskDialog`.|  
|`m_nDefaultCommandControl`|A ID do botão de comando de controle que é selecionada quando o `CTaskDialog` é exibida.|  
|`m_nDefaultRadioButton`|A ID do botão de opção de controle que é selecionada quando o `CTaskDialog` é exibida.|  
|`m_nFlags`|Uma máscara que indica as opções para o `CTaskDialog`.|  
|`m_nProgressPos`|A posição atual para a barra de progresso.  Esse valor deve estar entre `m_nProgressRangeMin` e `m_nProgressRangeMax`.|  
|`m_nProgressRangeMax`|O valor máximo para a barra de progresso.|  
|`m_nProgressRangeMin`|O valor mínimo para a barra de progresso.|  
|`m_nProgressState`|O estado da barra de progresso. Para obter mais informações, consulte [CTaskDialog::SetProgressBarState](#setprogressbarstate).|  
|`m_nRadioId`|A ID do controle de botão de opção selecionado.|  
|`m_nWidth`|A largura do `CTaskDialog` em pixels.|  
|`m_strCollapse`|A cadeia de caracteres de `CTaskDialog` exibido à direita da caixa de expansão quando as informações expandidas está oculto.|  
|`m_strContent`|A cadeia de caracteres de conteúdo do `CTaskDialog`.|  
|`m_strExpand`|A cadeia de caracteres de `CTaskDialog` exibido à direita da caixa de expansão quando as informações expandidas são exibidas.|  
|`m_strFooter`|Rodapé do `CTaskDialog`.|  
|`m_strInformation`|As informações expandidas para o `CTaskDialog`.|  
|`m_strMainInstruction`|A instrução principal do `CTaskDialog`.|  
|`m_strTitle`|O título do `CTaskDialog`.|  
|`m_strVerification`|A cadeia de caracteres que o `CTaskDialog` exibe à direita da caixa de seleção de verificação.|  
  
## <a name="remarks"></a>Comentários  
 O `CTaskDialog` classe substitui a caixa de mensagem padrão do Windows e tem funcionalidade adicional, como novos controles para coletar informações do usuário. Essa classe é na biblioteca MFC no [!INCLUDE[vs_dev10_long](../../build/includes/vs_dev10_long_md.md)]. O `CTaskDialog` está disponível desde [!INCLUDE[wiprlhext](../../c-runtime-library/reference/includes/wiprlhext_md.md)]. Versões anteriores do Windows não podem exibir o `CTaskDialog` objeto. Use `CTaskDialog::IsSupported` para determinar em tempo de execução se o usuário atual pode exibir a caixa de diálogo de tarefa. Ainda há suporte para a caixa de mensagem padrão do Windows em [!INCLUDE[vs_dev10_long](../../build/includes/vs_dev10_long_md.md)].  
  
 O `CTaskDialog` está disponível somente quando você cria seu aplicativo usando a biblioteca de Unicode.  
  
 O `CTaskDialog` possui dois construtores diferentes. Um construtor permite que você especifique dois botões de comando e um máximo de seis controles button normal. Você pode adicionar mais botões de comando depois de criar o `CTaskDialog`. O segundo construtor não oferece suporte para os botões de comando, mas você pode adicionar um número ilimitado de controles button regulares. Para obter mais informações sobre os construtores, consulte [CTaskDialog::CTaskDialog](#ctaskdialog).  
  
 A imagem a seguir mostra um exemplo `CTaskDialog` para ilustrar a localização de alguns dos controles.  
  
 ![Exemplo de CTaskDialog](../../mfc/reference/media/ctaskdialogsample.png "ctaskdialogsample")  
Exemplo de CTaskDialog  
  
## <a name="requirements"></a>Requisitos  
 **Sistema operacional mínimo necessário:**[!INCLUDE[wiprlhext](../../c-runtime-library/reference/includes/wiprlhext_md.md)]  
  
 **Cabeçalho:** afxtaskdialog.h  
  
##  <a name="addcommandcontrol"></a>CTaskDialog::AddCommandControl  
 Adiciona um novo controle de botão de comando para o `CTaskDialog`.  
  
```  
void AddCommandControl(
    int nCommandControlID,  
    const CString& strCaption,  
    BOOL bEnabled = TRUE,  
    BOOL bRequiresElevation = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nCommandControlID`  
 O número de identificação do controle de comando.  
  
 [in] `strCaption`  
 A cadeia de caracteres que o `CTaskDialog` exibe para o usuário. Use essa cadeia de caracteres para explicar a finalidade do comando.  
  
 [in] `bEnabled`  
 Um parâmetro booleano que indica se o novo botão está habilitado ou desabilitado.  
  
 [in] `bRequiresElevation`  
 Um parâmetro booleano que indica se um comando requer elevação.  
  
### <a name="remarks"></a>Comentários  
 O `CTaskDialog Class` pode exibir um número ilimitado de controles de botão de comando. No entanto, se um `CTaskDialog` exibe controles de qualquer botão de comando, ele pode exibir um máximo de seis botões. Se um `CTaskDialog` não tem nenhum controle de botão de comando, ele pode exibir um número ilimitado de botões.  
  
 Quando o usuário seleciona um controle de botão de comando, o `CTaskDialog` fecha. Se seu aplicativo exibe a caixa de diálogo usando [CTaskDialog::DoModal](#domodal), `DoModal` retorna o `nCommandControlID` do controle de botão de comando selecionado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&2;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]  
  
##  <a name="addradiobutton"></a>CTaskDialog::AddRadioButton  
 Adiciona um botão de opção para o `CTaskDialog`.  
  
```  
void CTaskDialog::AddRadioButton(
    int nRadioButtonID,  
    const CString& strCaption,  
    BOOL bEnabled = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nRadioButtonID`  
 O número de identificação do botão de opção.  
  
 [in] `strCaption`  
 A cadeia de caracteres que o `CTaskDialog` é exibido ao lado do botão de opção.  
  
 [in] `bEnabled`  
 Um parâmetro booleano que indica se o botão de opção está habilitado.  
  
### <a name="remarks"></a>Comentários  
 Botões de rádio para o [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md) permitem coletar informações do usuário. Use a função [CTaskDialog::GetSelectedRadioButtonID](#getselectedradiobuttonid) para determinar qual botão está selecionado.  
  
 O `CTaskDialog` não requer que o `nRadioButtonID` parâmetros são exclusivos para cada botão de opção. No entanto, você pode enfrentar um comportamento inesperado se você não usar um identificador distinto para cada botão de opção.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&3;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]  
  
##  <a name="clickcommandcontrol"></a>CTaskDialog::ClickCommandControl  
 Clica em um controle de botão de comando ou botão comum por meio de programação.  
  
```  
protected:  
void ClickCommandControl(int nCommandControlID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nCommandControlID`  
 A ID de comando do controle, clique em.  
  
### <a name="remarks"></a>Comentários  
 Esse método gera a mensagem do windows `TDM_CLICK_BUTTON`.  
  
##  <a name="clickradiobutton"></a>CTaskDialog::ClickRadioButton  
 Clica em um botão de opção programaticamente.  
  
```  
protected:  
void ClickRadioButton(int nRadioButtonID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nRadioButtonID`  
 A ID do botão de opção, clique em.  
  
### <a name="remarks"></a>Comentários  
 Esse método gera a mensagem do windows `TDM_CLICK_RADIO_BUTTON`.  
  
##  <a name="ctaskdialog"></a>CTaskDialog::CTaskDialog  
 Cria uma instância do [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md).  
  
```  
CTaskDialog(
    const CString& strContent,  
    const CString& strMainInstruction,  
    const CString& strTitle,  
    int nCommonButtons = TDCBF_OK_BUTTON | TDCBF_CANCEL_BUTTON,  
    int nTaskDialogOptions = TDF_ENABLE_HYPERLINKS | TDF_USE_COMMAND_LINKS,  
    const CString& strFooter = _T(""));

 
CTaskDialog(
    const CString& strContent,  
    const CString& strMainInstruction,  
    const CString& strTitle,  
    int nIDCommandControlsFirst,  
    int nIDCommandControlsLast,  
    int nCommonButtons,  
    int nTaskDialogOptions = TDF_ENABLE_HYPERLINKS | TDF_USE_COMMAND_LINKS,  
    const CString& strFooter = _T(""));
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `strContent`  
 A cadeia de caracteres a ser usado para o conteúdo a `CTaskDialog`.  
  
 [in] `strMainInstruction`  
 A instrução principal do `CTaskDialog`.  
  
 [in] `strTitle`  
 O título do `CTaskDialog`.  
  
 [in] `nCommonButtons`  
 Uma máscara de botões comuns para adicionar para o `CTaskDialog`.  
  
 [in] `nTaskDialogOptions`  
 O conjunto de opções a serem usadas para o `CTaskDialog`.  
  
 [in] `strFooter`  
 A cadeia de caracteres a ser usado como o rodapé.  
  
 [in] `nIDCommandControlsFirst`  
 A ID de cadeia de caracteres do primeiro comando.  
  
 [in] `nIDCommandControlsLast`  
 A ID de cadeia de caracteres do último comando.  
  
### <a name="remarks"></a>Comentários  
 Há duas maneiras que você pode adicionar uma `CTaskDialog` ao seu aplicativo. A primeira maneira é usar um dos construtores para criar um `CTaskDialog` e exibi-los usando [CTaskDialog::DoModal](#domodal). A segunda maneira é usar a função estática [CTaskDialog::ShowDialog](#showdialog), que permite que você exiba uma `CTaskDialog` sem criar explicitamente uma `CTaskDialog` objeto.  
  
 O segundo construtor cria controles de botão de comando usando dados do arquivo de recursos do seu aplicativo. A tabela de cadeia de caracteres no arquivo de recurso tem várias cadeias de caracteres com IDs de cadeia de caracteres associada. Este método adiciona um controle de botão de comando para cada entrada válida na tabela de cadeia de caracteres entre `nIDCommandControlsFirst` e `nCommandControlsLast`, inclusive. Para esses controles de botão de comando, a cadeia de caracteres na tabela de cadeia de caracteres é a legenda do controle e a ID de cadeia de caracteres é a identificação. do controle  
  
 Consulte [CTaskDialog::SetOptions](#setoptions) para obter uma lista de opções válidas.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog&#7;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]  
  
##  <a name="domodal"></a>CTaskDialog::DoModal  
 Mostra o `CTaskDialog` e o torna restrito.  
  
```  
INT_PTR DoModal (HWND hParent = ::GetActiveWindow());
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hParent`  
 A janela pai para o `CTaskDialog`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um inteiro que corresponde à seleção feita pelo usuário.  
  
### <a name="remarks"></a>Comentários  
 Exibe esta instância do [CTaskDialog](../../mfc/reference/ctaskdialog-class.md). O aplicativo aguarda o usuário fechar a caixa de diálogo.  
  
 O `CTaskDialog` fecha quando o usuário seleciona um botão comum, um controle de link de comando, ou fecha o `CTaskDialog`. O valor de retorno é o identificador que indica como o usuário fechou a caixa de diálogo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog&#7;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]  
  
##  <a name="getcommonbuttoncount"></a>CTaskDialog::GetCommonButtonCount  
 Recupera o número de botões comuns.  
  
```  
int GetCommonButtonCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de botões comuns disponíveis.  
  
### <a name="remarks"></a>Comentários  
 Os botões comuns são os botões padrão que você fornece para [CTaskDialog::CTaskDialog](#ctaskdialog). O [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md) exibe os botões na parte inferior da caixa de diálogo.  
  
 A lista enumerada dos botões é fornecida em commctrl. H.  
  
##  <a name="getcommonbuttonflag"></a>CTaskDialog::GetCommonButtonFlag  
 Converte um padrão de botão do Windows para o tipo de botão comuns associado a [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md).  
  
```  
int GetCommonButtonFlag(int nButtonId) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nButtonId`  
 O valor padrão de botão do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor correspondente `CTaskDialog` botão comuns. Se não houver nenhum botão comum correspondente, esse método retornará 0.  
  
##  <a name="getcommonbuttonid"></a>CTaskDialog::GetCommonButtonId  
 Converte um dos tipos de botão comuns associados a [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md) a um botão padrão do Windows.  
  
```  
int GetCommonButtonId(int nFlag);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nFlag`  
 O tipo de botão comuns associados a `CTaskDialog` classe.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor do botão Windows padrão correspondente. Se não houver nenhum botão correspondente do Windows, o método retornará 0.  
  
##  <a name="getoptions"></a>CTaskDialog::GetOptions  
 Retorna os sinalizadores de opção para este `CTaskDialog`.  
  
```  
int GetOptions() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Os sinalizadores para a `CTaskDialog`.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre as opções disponíveis para o [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md), consulte [CTaskDialog::SetOptions](#setoptions).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog&#7;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]  
  
##  <a name="getselectedcommandcontrolid"></a>CTaskDialog::GetSelectedCommandControlID  
 Retorna o controle de botão de comando selecionado.  
  
```  
int GetSelectedCommandControlID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A ID do controle de botão de comando selecionado no momento.  
  
### <a name="remarks"></a>Comentários  
 Você não precisa usar esse método para recuperar a ID do botão de comando que o usuário selecionado. Essa ID é retornada pela [CTaskDialog::DoModal](#domodal) ou [CTaskDialog::ShowDialog](#showdialog).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&2;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]  
  
##  <a name="getselectedradiobuttonid"></a>CTaskDialog::GetSelectedRadioButtonID  
 Retorna o botão de opção selecionado.  
  
```  
int GetSelectedRadioButtonID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A ID do botão de opção selecionado.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar este método depois que o usuário fecha a caixa de diálogo para recuperar o botão de opção selecionado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&3;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]  
  
##  <a name="getverificationcheckboxstate"></a>CTaskDialog::GetVerificationCheckboxState  
 Recupera o estado da caixa de seleção de verificação.  
  
```  
BOOL GetVerificationCheckboxState() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a caixa de seleção estiver marcada, `FALSE` se não for.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&5;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_4.cpp)]  
  
##  <a name="iscommandcontrolenabled"></a>CTaskDialog::IsCommandControlEnabled  
 Determina se um controle de botão de comando ou botão está habilitado.  
  
```  
BOOL IsCommandControlEnabled(int nCommandControlID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nCommandControlID`  
 A ID do controle de botão de comando ou no botão Testar.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o controle estiver habilitado, `FALSE` se não for.  
  
### <a name="remarks"></a>Comentários  
 Você pode usar esse método para determinar a disponibilidade de ambos os controles de botão de comando e os botões comuns do `CTaskDialog Class`.  
  
 Se `nCommandControlID` é não um identificador válido para um um comum `CTaskDialog` botão ou um controle de botão de comando, esse método lançará uma exceção.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&2;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]  
  
##  <a name="isradiobuttonenabled"></a>CTaskDialog::IsRadioButtonEnabled  
 Determina se um botão de opção é habilitado.  
  
```  
BOOL IsRadioButtonEnabled(int nRadioButtonID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nRadioButtonID`  
 A ID do botão de opção para testar.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o botão de opção é habilitado, `FALSE` se não for.  
  
### <a name="remarks"></a>Comentários  
 Se `nRadioButtonID` não é um identificador válido para um botão de opção, esse método lançará uma exceção.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&3;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]  
  
##  <a name="issupported"></a>CTaskDialog::IsSupported  
 Determina se o computador que está executando o aplicativo oferece suporte a `CTaskDialog`.  
  
```  
static BOOL IsSupported();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o computador oferecer suporte a `CTaskDialog`; `FALSE` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para determinar em tempo de execução se o computador que está executando o aplicativo oferece suporte a `CTaskDialog Class`. Se o computador não oferece suporte a `CTaskDialog`, você deve fornecer outro método de comunicação de informações ao usuário. Seu aplicativo irá falhar se tentar usar um `CTaskDialog` em um computador que não oferece suporte a `CTaskDialog` classe.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&1;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_5.cpp)]  
  
##  <a name="loadcommandcontrols"></a>CTaskDialog::LoadCommandControls  
 Adiciona controles de botão de comando usando dados da tabela de cadeia de caracteres.  
  
```  
void LoadCommandControls(
    int nIDCommandControlsFirst,  
    int nIDCommandControlsLast);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIDCommandControlsFirst`  
 A ID de cadeia de caracteres do primeiro comando.  
  
 [in] `nIDCommandControlsLast`  
 A ID de cadeia de caracteres do último comando.  
  
### <a name="remarks"></a>Comentários  
 Esse método cria controles de botão de comando usando os dados do arquivo de recursos do seu aplicativo. A tabela de cadeia de caracteres no arquivo de recurso tem várias cadeias de caracteres com IDs de cadeia de caracteres associada. Novos controles de botão de comando adicionados usando esse método usam a cadeia de caracteres para a legenda do controle e a ID de cadeia de caracteres de identificação. do controle O intervalo de cadeias de caracteres selecionado é fornecido por `nIDCommandControlsFirst` e `nCommandControlsLast`, inclusive. Se houver uma entrada vazia no intervalo, o método não adiciona um controle de botão de comando para a entrada.  
  
 Por padrão, novos controles de botão de comando estão habilitados e não exigem elevação.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&2;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]  
  
##  <a name="loadradiobuttons"></a>CTaskDialog::LoadRadioButtons  
 Adiciona controles de botão de rádio usando dados da tabela de cadeia de caracteres.  
  
```  
void LoadRadioButtons(
    int nIDRadioButtonsFirst,  
    int nIDRadioButtonsLast);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIDRadioButtonsFirst`  
 A ID de cadeia de caracteres do primeiro botão de opção.  
  
 [in] `nIDRadioButtonsLast`  
 A ID de cadeia de caracteres do último botão de rádio.  
  
### <a name="remarks"></a>Comentários  
 Esse método cria botões de opção usando dados do arquivo de recursos do seu aplicativo. A tabela de cadeia de caracteres no arquivo de recurso tem várias cadeias de caracteres com IDs de cadeia de caracteres associada. Novos botões adicionados usando esse método usam a cadeia de caracteres para a legenda do botão de opção e a ID de cadeia de caracteres para ID. do botão de opção O intervalo de cadeias de caracteres selecionado é fornecido por `nIDRadioButtonsFirst` e `nRadioButtonsLast`, inclusive. Se houver uma entrada vazia no intervalo, o método não adiciona um botão de opção para a entrada.  
  
 Por padrão, novos botões de opção são habilitados.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&3;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]  
  
##  <a name="navigateto"></a>CTaskDialog::NavigateTo  
 Transfere o foco para outra `CTaskDialog`.  
  
```  
protected:  
void NavigateTo(CTaskDialog& oTaskDialog) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `oTaskDialog`  
 O `CTaskDialog` que recebe o foco.  
  
### <a name="remarks"></a>Comentários  
 Esse método oculta atual `CTaskDialog` quando ele for exibido o `oTaskDialog`. O `oTaskDialog` é exibido no mesmo local que o atual `CTaskDialog`.  
  
##  <a name="oncommandcontrolclick"></a>CTaskDialog::OnCommandControlClick  
 O framework chama esse método quando o usuário clica em um controle de botão de comando.  
  
```  
virtual HRESULT OnCommandControlClick(int nCommandControlID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nCommandControlID`  
 A ID do controle de botão de comando que o usuário selecionado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a implementação padrão `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Substitua esse método em uma classe derivada para implementar comportamento personalizado.  
  
##  <a name="oncreate"></a>CTaskDialog::OnCreate  
 O framework chama esse método depois que ele cria o `CTaskDialog`.  
  
```  
virtual HRESULT OnCreate();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a implementação padrão `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Substitua esse método em uma classe derivada para implementar comportamento personalizado.  
  
##  <a name="ondestroy"></a>CTaskDialog::OnDestroy  
 O framework chama esse método imediatamente antes ele destrói o `CTaskDialog`.  
  
```  
virtual HRESULT OnDestroy();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a implementação padrão `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Substitua esse método em uma classe derivada para implementar comportamento personalizado.  
  
##  <a name="onexpandbuttonclick"></a>CTaskDialog::OnExpandButtonClick  
 O framework chama esse método quando o usuário clica no botão de expansão.  
  
```  
virtual HRESULT OnExpandButtonClicked(BOOL bExpanded);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bExpanded`  
 Um valor diferente de zero indica que as informações adicionais são exibidas. 0 indica que as informações extras está oculto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a implementação padrão `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Substitua esse método em uma classe derivada para implementar comportamento personalizado.  
  
##  <a name="onhelp"></a>CTaskDialog::OnHelp  
 O framework chama esse método quando o usuário solicita ajuda.  
  
```  
virtual HRESULT OnHelp();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a implementação padrão `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Substitua esse método em uma classe derivada para implementar comportamento personalizado.  
  
##  <a name="onhyperlinkclick"></a>CTaskDialog::OnHyperlinkClick  
 O framework chama esse método quando o usuário clica em um hiperlink.  
  
```  
virtual HRESULT OnHyperlinkClick(const CString& strHref);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `strHref`  
 A cadeia de caracteres que representa o hiperlink.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a implementação padrão `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Esse método chama [ShellExecute](http://msdn.microsoft.com/library/windows/desktop/bb762153) antes de retornar `S_OK`.  
  
 Substitua esse método em uma classe derivada para implementar comportamento personalizado.  
  
##  <a name="oninit"></a>CTaskDialog::OnInit  
 O framework chama esse método quando o `CTaskDialog` é inicializado.  
  
```  
virtual HRESULT OnInit();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a implementação padrão `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Substitua esse método em uma classe derivada para implementar comportamento personalizado.  
  
##  <a name="onnavigatepage"></a>CTaskDialog::OnNavigatePage  
 O framework chama esse método em resposta ao [CTaskDialog::NavigateTo](#navigateto) método.  
  
```  
virtual HRESULT OnNavigatePage();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a implementação padrão `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Substitua esse método em uma classe derivada para implementar comportamento personalizado.  
  
##  <a name="onradiobuttonclick"></a>CTaskDialog::OnRadioButtonClick  
 O framework chama esse método quando o usuário seleciona um controle de botão de opção.  
  
```  
virtual HRESULT OnRadioButtonClick(int nRadioButtonID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nRadioButtonID`  
 A ID do controle de botão de opção que o usuário clicou.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a implementação padrão `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Substitua esse método em uma classe derivada para implementar comportamento personalizado.  
  
##  <a name="ontimer"></a>CTaskDialog::OnTimer  
 O framework chama esse método quando o temporizador expirar.  
  
```  
virtual HRESULT OnTimer(long lTime);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lTime`  
 Tempo em milissegundos desde a `CTaskDialog` foi criado ou o temporizador foi redefinido.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a implementação padrão `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Substitua esse método em uma classe derivada para implementar comportamento personalizado.  
  
##  <a name="onverificationcheckboxclick"></a>CTaskDialog::OnVerificationCheckboxClick  
 O framework chama esse método quando o usuário clica a caixa de seleção de verificação.  
  
```  
virtual HRESULT OnVerificationCheckboxClick(BOOL bChecked);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bChecked`  
 `TRUE`indica que a caixa de seleção de verificação é selecionada; `FALSE` indica que não é.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a implementação padrão `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Substitua esse método em uma classe derivada para implementar comportamento personalizado.  
  
##  <a name="removeallcommandcontrols"></a>CTaskDialog::RemoveAllCommandControls  
 Remove todos os controles de botão de comando da `CTaskDialog`.  
  
```  
void RemoveAllCommandControls();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&2;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]  
  
##  <a name="removeallradiobuttons"></a>CTaskDialog::RemoveAllRadioButtons  
 Remove todos os botões de opção de `CTaskDialog`.  
  
```  
void RemoveAllRadioButtons();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&3;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]  
  
##  <a name="setcommandcontroloptions"></a>CTaskDialog::SetCommandControlOptions  
 Atualiza um controle de botão de comando na `CTaskDialog`.  
  
```  
void SetCommandControlOptions(
    int nCommandControlID,  
    BOOL bEnabled,  
    BOOL bRequiresElevation = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nCommandControlID`  
 A ID do controle de comando para atualizar.  
  
 [in] `bEnabled`  
 Um parâmetro booleano que indica se o controle de botão de comando especificado está habilitado ou desabilitado.  
  
 [in] `bRequiresElevation`  
 Um parâmetro booleano que indica se o controle de botão de comando especificado requer elevação.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para alterar se um controle de botão de comando é habilitado ou requer elevação depois que ele foi adicionado para o `CTaskDialog Class`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&2;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]  
  
##  <a name="setcommonbuttonoptions"></a>CTaskDialog::SetCommonButtonOptions  
 Atualiza um subconjunto dos botões comuns para ser habilitado e exigem elevação do UAC.  
  
```  
void SetCommonButtonOptions(
    int nDisabledButtonMask,  
    int nElevationButtonMask = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nDisabledButtonMask`  
 Uma máscara para desabilitar os botões comuns.  
  
 [in] `nElevationButtonMask`  
 Uma máscara para os botões comuns que exigem elevação.  
  
### <a name="remarks"></a>Comentários  
 Você pode definir os botões comuns disponíveis para uma instância do [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md) usando o construtor [CTaskDialog::CTaskDialog](#ctaskdialog) e o método [CTaskDialog::SetCommonButtons](#setcommonbuttons). `CTaskDialog::SetCommonButtonOptions`não suporta a adição de novos botões comuns.  
  
 Se você usar esse método para desabilitar ou elevar um botão comum que não está disponível para este `CTaskDialog`, esse método lança uma exceção usando o [Verifique](http://msdn.microsoft.com/library/738c4ccf-c29c-4c04-8d6c-f126bedf6e91) macro.  
  
 Este método permite que qualquer botão que está disponível para o `CTaskDialog` , mas não está no `nDisabledButtonMask`, mesmo se ele tiver sido desabilitado anteriormente. Este método trata a elevação de maneira semelhante: registra botões comuns como não exigir elevação, se o botão comuns estiver disponível, mas não estão incluídos no `nElevationButtonMask`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&6;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_6.cpp)]  
  
##  <a name="setcommonbuttons"></a>CTaskDialog::SetCommonButtons  
 Adiciona botões comuns para o `CTaskDialog`.  
  
```  
void SetCommonButtons(
    int nButtonMask,  
    int nDisabledButtonMask = 0,  
    int nElevationButtonMask = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nButtonMask`  
 Uma máscara de botões para adicionar para o `CTaskDialog`.  
  
 [in] `nDisabledButtonMask`  
 Uma máscara para desabilitar os botões.  
  
 [in] `nElevationButtonMask`  
 Uma máscara dos botões que exigem elevação.  
  
### <a name="remarks"></a>Comentários  
 Você não pode chamar esse método após a janela de exibição para essa instância do `CTaskDialog Class` é criado. Nesse caso, esse método lança uma exceção.  
  
 Os botões indicado por `nButtonMask` substituir quaisquer botões comuns adicionados anteriormente para o `CTaskDialog`. Somente os botões indicado na `nButtonMask` estão disponíveis.  
  
 Se qualquer um dos `nDisabledButtonMask` ou `nElevationButtonMask` contém um botão que não está em `nButtonMask`, esse método lança uma exceção usando o [Verifique](http://msdn.microsoft.com/library/738c4ccf-c29c-4c04-8d6c-f126bedf6e91) macro.  
  
 Por padrão, todos os botões comuns estão habilitados e não exigem elevação.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&6;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_6.cpp)]  
  
##  <a name="setcontent"></a>CTaskDialog::SetContent  
 Atualiza o conteúdo do `CTaskDialog`.  
  
```  
void SetContent(const CString& strContent);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `strContent`  
 A cadeia de caracteres para exibição ao usuário.  
  
### <a name="remarks"></a>Comentários  
 O conteúdo a `CTaskDialog Class` é o texto que é exibido para o usuário na seção principal da caixa de diálogo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog&#7;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]  
  
##  <a name="setdefaultcommandcontrol"></a>CTaskDialog::SetDefaultCommandControl  
 Especifica o controle de botão de comando padrão.  
  
```  
void SetDefaultCommandControl(int nCommandControlID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nCommandControlID`  
 A ID do controle de botão de comando padrão.  
  
### <a name="remarks"></a>Comentários  
 O controle de botão de comando padrão é o controle que é selecionado quando o `CTaskDialog` é exibida primeiro para o usuário.  
  
 Esse método gera uma exceção se não é possível localizar o controle de botão de comando especificado pelo `nCommandControlID`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&2;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]  
  
##  <a name="setdefaultradiobutton"></a>CTaskDialog::SetDefaultRadioButton  
 Especifica o botão padrão.  
  
```  
void SetDefaultRadioButton(int nRadioButtonID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nRadioButtonID`  
 A ID do botão de opção padrão.  
  
### <a name="remarks"></a>Comentários  
 Botão de opção padrão é o botão que é selecionado quando o `CTaskDialog` é exibida primeiro para o usuário.  
  
 Esse método gera uma exceção se não é possível localizar o botão de opção especificado por `nRadioButtonID`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&3;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]  
  
##  <a name="setdialogwidth"></a>CTaskDialog::SetDialogWidth  
 Ajusta a largura do `CTaskDialog`.  
  
```  
void SetDialogWidth(int nWidth = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nWidth`  
 A largura da caixa de diálogo, em pixels.  
  
### <a name="remarks"></a>Comentários  
 O parâmetro `nWidth` deve ser maior ou igual a 0. Caso contrário, esse método lança uma exceção.  
  
 Se `nWidth` for definido como 0, esse método define a caixa de diálogo para o tamanho padrão.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog&#7;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]  
  
##  <a name="setexpansionarea"></a>CTaskDialog::SetExpansionArea  
 Atualiza a área de expansão do `CTaskDialog`.  
  
```  
void SetExpansionArea(
    const CString& strExpandedInformation,  
    const CString& strCollapsedLabel = _T(""),  
    const CString& strExpandedLabel = _T(""));
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `strExpandedInformation`  
 A cadeia de caracteres que o `CTaskDialog` exibe no corpo principal da caixa de diálogo quando o usuário clica no botão de expansão.  
  
 [in] `strCollapsedLabel`  
 A cadeia de caracteres que o `CTaskDialog` é exibido ao lado do botão de expansão quando a área expandida é recolhida.  
  
 [in] `strExpandedLabel`  
 A cadeia de caracteres que o `CTaskDialog` é exibido ao lado do botão de expansão quando a área expandida é exibida.  
  
### <a name="remarks"></a>Comentários  
 A área de expansão do `CTaskDialog Class` permite que você forneça informações adicionais para o usuário. A área de expansão é na parte principal do `CTaskDialog`, localizada imediatamente abaixo a cadeia de caracteres do título e conteúdo.  
  
 Quando o `CTaskDialog` primeiro é exibido, ele não mostra as informações expandidas e coloca `strCollapsedLabel` ao lado do botão de expansão. Quando o usuário clica no botão de expansão, o `CTaskDialog` exibe `strExpandedInformation` e altera o rótulo a ser `strExpandedLabel`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog&#7;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]  
  
##  <a name="setfootericon"></a>CTaskDialog::SetFooterIcon  
 O ícone de rodapé de atualizações de `CTaskDialog`.  
  
```  
void SetFooterIcon(HICON hFooterIcon);  
void SetFooterIcon(LPCWSTR lpszFooterIcon);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hFooterIcon`  
 Ícone novo para o `CTaskDialog`.  
  
 [in] `lpszFooterIcon`  
 Ícone novo para o `CTaskDialog`.  
  
### <a name="remarks"></a>Comentários  
 O ícone de rodapé é exibido na parte inferior do [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md). Ele pode ter associado texto de rodapé. Você pode alterar o texto do rodapé com [CTaskDialog::SetFooterText](#setfootertext).  
  
 Esse método lançará uma exceção com o [Verifique](http://msdn.microsoft.com/library/738c4ccf-c29c-4c04-8d6c-f126bedf6e91) macro se o `CTaskDialog` é exibida ou o parâmetro de entrada é `NULL`.  
  
 A `CTaskDialog` só pode aceitar uma `HICON` ou `LPCWSTR` como um ícone de rodapé. Isso é configurado, definindo a opção `TDF_USE_HICON_FOOTER` no construtor ou [CTaskDialog::SetOptions](#setoptions). Por padrão, o `CTaskDialog` está configurado para usar `LPCWSTR` como o tipo de entrada para o ícone de rodapé. Esse método gera uma exceção se você tentar definir o ícone usando o tipo inadequado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog&#7;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]  
  
##  <a name="setfootertext"></a>CTaskDialog::SetFooterText  
 Atualiza o texto no rodapé do `CTaskDialog`.  
  
```  
void SetFooterText(const CString& strFooterText);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `strFooterText`  
 O novo texto do rodapé.  
  
### <a name="remarks"></a>Comentários  
 O ícone de rodapé é exibido ao lado do texto de rodapé na parte inferior da `CTaskDialog`. Você pode alterar o ícone de rodapé com [CTaskDialog::SetFooterIcon](#setfootericon).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog&#7;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]  
  
##  <a name="setmainicon"></a>CTaskDialog::SetMainIcon  
 O ícone principal de atualizações de `CTaskDialog`.  
  
```  
void SetMainIcon(HICON hMainIcon);  
void SetMainIcon(LPCWSTR lpszMainIcon);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hMainIcon`  
 O novo ícone.  
  
 [in] `lpszMainIcon`  
 O novo ícone.  
  
### <a name="remarks"></a>Comentários  
 Esse método lançará uma exceção com o [Verifique](http://msdn.microsoft.com/library/738c4ccf-c29c-4c04-8d6c-f126bedf6e91) macro se o `CTaskDialog` é exibida ou o parâmetro de entrada é `NULL`.  
  
 A `CTaskDialog` só pode aceitar uma `HICON` ou `LPCWSTR` como um ícone principal. Você pode configurar isso definindo a `TDF_USE_HICON_MAIN` opção no construtor ou no [CTaskDialog::SetOptions](#setoptions) método. Por padrão, o `CTaskDialog` está configurado para usar `LPCWSTR` como o tipo de entrada para o ícone principal. Esse método gera uma exceção se você tentar definir o ícone usando o tipo inadequado.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog&#7;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]  
  
##  <a name="setmaininstruction"></a>CTaskDialog::SetMainInstruction  
 Atualiza a instrução principal do `CTaskDialog`.  
  
```  
void SetMainInstruction(const CString& strInstructions);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `strInstructions`  
 A nova instrução principal.  
  
### <a name="remarks"></a>Comentários  
 A instrução principal do `CTaskDialog Class` é o texto exibido para o usuário em uma grande fonte em negrito. Ele está localizado na caixa de diálogo abaixo da barra de título.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog&#7;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]  
  
##  <a name="setoptions"></a>CTaskDialog::SetOptions  
 Configura as opções para o `CTaskDialog`.  
  
```  
void SetOptions(int nOptionFlag);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nOptionFlag`  
 O conjunto de sinalizadores para usar para o `CTaskDialog`.  
  
### <a name="remarks"></a>Comentários  
 Esse método limpa todas as opções atuais para o `CTaskDialog`. Para preservar as opções atuais, você precisa recuperá-las primeiro com [CTaskDialog::GetOptions](#getoptions) e combiná-los com as opções que você deseja definir.  
  
 A tabela a seguir lista as opções válidas.  
  
 `TDF_ENABLE_HYPERLINKS`  
 Permite hiperlinks a `CTaskDialog`.  
  
 `TDF_USE_HICON_MAIN`  
 Configura o `CTaskDialog` usar um `HICON` para o ícone principal. A alternativa é usar um `LPCWSTR`.  
  
 `TDF_USE_HICON_FOOTER`  
 Configura o `CTaskDialog` usar um `HICON` para o ícone de rodapé. A alternativa é usar um `LPCWSTR`.  
  
 `TDF_ALLOW_DIALOG_CANCELLATION`  
 Permite que o usuário feche o `CTaskDialog` usando o teclado ou usando o ícone no canto superior direito da caixa de diálogo, mesmo se o **Cancelar** botão não está habilitado. Se este sinalizador não for definido e o **Cancelar** botão não estiver habilitado, o usuário não pode fechar a caixa de diálogo usando Alt + F4, a chave de Escape, ou na barra de título botão fecha.  
  
 `TDF_USE_COMMAND_LINKS`  
 Configura o `CTaskDialog` usar controles de botão de comando.  
  
 `TDF_USE_COMMAND_LINKS_NO_ICON`  
 Configura o `CTaskDialog` usar controles de botão de comando sem exibir um ícone ao lado do controle. `TDF_USE_COMMAND_LINKS`substituições `TDF_USE_COMMAND_LINKS_NO_ICON`.  
  
 `TDF_EXPAND_FOOTER_AREA`  
 Indica que a área de expansão no momento é expandida.  
  
 `TDF_EXPANDED_BY_DEFAULT`  
 Determina se a área de expansão é expandida por padrão.  
  
 `TDF_VERIFICATION_FLAG_CHECKED`  
 Indica se que a caixa de seleção de verificação está selecionada no momento.  
  
 `TDF_SHOW_PROGRESS_BAR`  
 Configura o `CTaskDialog` para exibir uma barra de progresso.  
  
 `TDF_SHOW_MARQUEE_PROGRESS_BAR`  
 Configura a barra de progresso para uma barra de progresso de marca de seleção. Se você habilitar essa opção, você deve definir `TDF_SHOW_PROGRESS_BAR` para que o comportamento esperado.  
  
 `TDF_CALLBACK_TIMER`  
 Indica que o `CTaskDialog` intervalo de retorno de chamada é definido para aproximadamente 200 milissegundos.  
  
 `TDF_POSITION_RELATIVE_TO_WINDOW`  
 Configura o `CTaskDialog` centralizado em relação a janela pai. Se este sinalizador não estiver habilitado, o `CTaskDialog` é centralizada em relação ao monitor.  
  
 `TDF_RTL_LAYOUT`  
 Configura o `CTaskDialog` para um layout de leitura da direita para esquerda.  
  
 `TDF_NO_DEFAULT_RADIO_BUTTON`  
 Indica que nenhum botão de opção é selecionada quando o `CTaskDialog` é exibida.  
  
 `TDF_CAN_BE_MINIMIZED`  
 Permite que o usuário minimizar a `CTaskDialog`. Para oferecer suporte a essa opção, o `CTaskDialog` não pode ser modal. MFC não dá suporte a essa opção porque o MFC não suporta uma sem janela restrita `CTaskDialog`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog&#7;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]  
  
##  <a name="setprogressbarmarquee"></a>CTaskDialog::SetProgressBarMarquee  
 Configura uma barra de marca de seleção para o `CTaskDialog` e o adiciona à caixa de diálogo.  
  
```  
void SetProgressBarMarquee(
    BOOL bEnabled = TRUE,  
    int nMarqueeSpeed = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnabled`  
 `TRUE`Para habilitar a barra de marca de seleção. `FALSE` para desabilitar a barra de letreiro e removê-lo a `CTaskDialog`.  
  
 [in] `nMarqueeSpeed`  
 Um inteiro que indica a velocidade da barra de marca de seleção.  
  
### <a name="remarks"></a>Comentários  
 A barra de marca de seleção aparece abaixo do texto principal do `CTaskDialog Class`.  
  
 Use `nMarqueeSpeed` para definir a velocidade da barra de ferramentas Letreiro; valores maiores indicam uma velocidade mais lenta. Um valor de 0 para `nMarqueeSpeed` faz com que a barra de letreiro mover na velocidade padrão para [!INCLUDE[wiprlhext](../../c-runtime-library/reference/includes/wiprlhext_md.md)].  
  
 Esse método lançará uma exceção com o [Verifique](http://msdn.microsoft.com/library/738c4ccf-c29c-4c04-8d6c-f126bedf6e91) macro se `nMarqueeSpeed` for menor que 0.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&4;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_7.cpp)]  
  
##  <a name="setprogressbarposition"></a>CTaskDialog::SetProgressBarPosition  
 Ajusta a posição da barra de progresso.  
  
```  
void SetProgressBarPosition(int nProgressPos);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nProgressPos`  
 A posição para a barra de progresso.  
  
### <a name="remarks"></a>Comentários  
 Esse método lançará uma exceção com o [Verifique](http://msdn.microsoft.com/library/738c4ccf-c29c-4c04-8d6c-f126bedf6e91) macro se `nProgressPos` não está no intervalo de barra de progresso. Você pode alterar o intervalo da barra de progresso com [CTaskDialog::SetProgressBarRange](#setprogressbarrange).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&4;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_7.cpp)]  
  
##  <a name="setprogressbarrange"></a>CTaskDialog::SetProgressBarRange  
 Ajusta o intervalo da barra de progresso.  
  
```  
void SetProgressBarRange(
    int nRangeMin,  
    int nRangeMax);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nRangeMin`  
 O limite inferior da barra de progresso.  
  
 [in] `nRangeMax`  
 O limite superior da barra de progresso.  
  
### <a name="remarks"></a>Comentários  
 A posição da barra de progresso é relativo a `nRangeMin` e `nRangeMax`. Por exemplo, se `nRangeMin` é 50 e `nRangeMax` é 100, uma posição de 75 é meio caminho entre a barra de progresso. Use [CTaskDialog::SetProgressBarPosition](#setprogressbarposition) para definir a posição da barra de progresso.  
  
 Para exibir o andamento da barra, a opção `TDF_SHOW_PROGRESS_BAR` deve estar habilitado e `TDF_SHOW_MARQUEE_PROGRESS_BAR` não deve ser habilitado. Esse método define automaticamente `TDF_SHOW_PROGRESS_BAR` e limpa `TDF_SHOW_MARQUEE_PROGRESS_BAR`. Use [CTaskDialog::SetOptions](#setoptions) para alterar manualmente as opções para essa instância do [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md).  
  
 Esse método lançará uma exceção com o [Verifique](http://msdn.microsoft.com/library/738c4ccf-c29c-4c04-8d6c-f126bedf6e91) macro se `nRangeMin` é não é menor que `nRangeMax`. Esse método também lançará uma exceção se o `CTaskDialog` estiver sendo exibida e tem uma barra de progresso de marca de seleção.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&4;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_7.cpp)]  
  
##  <a name="setprogressbarstate"></a>CTaskDialog::SetProgressBarState  
 Define o estado da barra de progresso e exibe-os na `CTaskDialog`.  
  
```  
void SetProgressBarState(int nState = PBST_NORMAL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nState`  
 O estado da barra de progresso. Consulte a seção comentários para os valores possíveis.  
  
### <a name="remarks"></a>Comentários  
 Esse método lançará uma exceção com o [Verifique](http://msdn.microsoft.com/library/738c4ccf-c29c-4c04-8d6c-f126bedf6e91) macro se o `CTaskDialog` estiver sendo exibida e tem uma barra de progresso de marca de seleção.  
  
 A tabela a seguir lista os possíveis valores para `nState`. Nesses casos, a barra de progresso será preenchido com a cor regular até atingir a posição da parada designado. Nesse ponto, ele mudará cor com base no estado.  
  
 PBST_NORMAL  
 Após o andamento da barra é preenchida, o `CTaskDialog` não altera a cor da barra. Por padrão, a cor regular é verde.  
  
 PBST_ERROR  
 Após o andamento da barra é preenchida, o `CTaskDialog` altera a cor da barra para a cor de erro. Por padrão, isso é vermelho.  
  
 PBST_PAUSED  
 Após o andamento da barra é preenchida, o `CTaskDialog` altera a cor da barra para a cor em pausa. Por padrão, isso é amarelo.  
  
 Você pode definir onde a barra de progresso para com [CTaskDialog::SetProgressBarPosition](#setprogressbarposition).  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&4;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_7.cpp)]  
  
##  <a name="setradiobuttonoptions"></a>CTaskDialog::SetRadioButtonOptions  
 Habilita ou desabilita um botão de opção.  
  
```  
void SetRadioButtonOptions(
    int nRadioButtonID,  
    BOOL bEnabled);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nRadioButtonID`  
 A ID do controle de botão de rádio.  
  
 [in] `bEnabled`  
 `TRUE`Para habilitar o botão de opção; `FALSE` para desabilitar o botão de opção.  
  
### <a name="remarks"></a>Comentários  
 Esse método lançará uma exceção com o [Verifique](http://msdn.microsoft.com/library/738c4ccf-c29c-4c04-8d6c-f126bedf6e91) macro se `nRadioButtonID` não é uma ID válida para um botão de opção.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&3;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]  
  
##  <a name="setverificationcheckbox"></a>CTaskDialog::SetVerificationCheckbox  
 Define o estado da caixa de seleção de verificação selecionado.  
  
```  
void SetVerificationCheckbox(BOOL bChecked);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bChecked`  
 `TRUE`para que a verificação da caixa de seleção marcada quando o `CTaskDialog` é exibida; `FALSE` para que a verificação da caixa de seleção desmarcada quando o `CTaskDialog` é exibida.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&5;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_4.cpp)]  
  
##  <a name="setverificationcheckboxtext"></a>CTaskDialog::SetVerificationCheckboxText  
 Define o texto que é exibido à direita da caixa de seleção de verificação.  
  
```  
void SetVerificationCheckboxText(CString& strVerificationText);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `strVerificationText`  
 O texto que esse método exibe ao lado da caixa de seleção de verificação.  
  
### <a name="remarks"></a>Comentários  
 Esse método lançará uma exceção com o [Verifique](http://msdn.microsoft.com/library/738c4ccf-c29c-4c04-8d6c-f126bedf6e91) macro se esta instância do `CTaskDialog Class` já é exibido.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&5;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_4.cpp)]  
  
##  <a name="setwindowtitle"></a>CTaskDialog::SetWindowTitle  
 Define o título do `CTaskDialog`.  
  
```  
void SetWindowTitle(CString& strWindowTitle);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `strWindowTitle`  
 O novo título para o `CTaskDialog`.  
  
### <a name="remarks"></a>Comentários  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog&#7;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]  
  
##  <a name="showdialog"></a>CTaskDialog::ShowDialog  
 Cria e exibe um `CTaskDialog`.  
  
```  
static INT_PTR ShowDialog(
    const CString& strContent,  
    const CString& strMainInstruction,  
    const CString& strTitle,  
    int nIDCommandControlsFirst,  
    int nIDCommandControlsLast,  
    int nCommonButtons = TDCBF_YES_BUTTON | TDCBF_NO_BUTTON,  
    int nTaskDialogOptions = TDF_ENABLE_HYPERLINKS | TDF_USE_COMMAND_LINKS,  
    const CString& strFooter = _T(""));
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `strContent`  
 A cadeia de caracteres a ser usado para o conteúdo a `CTaskDialog`.  
  
 [in] `strMainInstruction`  
 A instrução principal do `CTaskDialog`.  
  
 [in] `strTitle`  
 O título do `CTaskDialog`.  
  
 [in] `nIDCommandControlsFirst`  
 A ID de cadeia de caracteres do primeiro comando.  
  
 [in] `nIDCommandControlsLast`  
 A ID de cadeia de caracteres do último comando.  
  
 [in] `nCommonButtons`  
 Uma máscara de botões para adicionar para o `CTaskDialog`.  
  
 [in] `nTaskDialogOptions`  
 O conjunto de opções a serem usadas para o `CTaskDialog`.  
  
 [in] `strFooter`  
 A cadeia de caracteres a ser usado como o rodapé.  
  
### <a name="return-value"></a>Valor de retorno  
 Um inteiro que corresponde à seleção feita pelo usuário.  
  
### <a name="remarks"></a>Comentários  
 Esse método estático permite que você crie uma instância do `CTaskDialog Class` sem criar explicitamente uma `CTaskDialog` objeto em seu código. Porque não há nenhum `CTaskDialog` do objeto, você não pode chamar outros métodos do `CTaskDialog` se você usar esse método para mostrar um `CTaskDialog` para o usuário.  
  
 Esse método cria controles de botão de comando usando os dados do arquivo de recursos do seu aplicativo. A tabela de cadeia de caracteres no arquivo de recurso tem várias cadeias de caracteres com IDs de cadeia de caracteres associada. Este método adiciona um controle de botão de comando para cada entrada válida na tabela de cadeia de caracteres entre `nIDCommandControlsFirst` e `nCommandControlsLast`, inclusive. Para esses controles de botão de comando, a cadeia de caracteres na tabela de cadeia de caracteres é a legenda do controle e a ID de cadeia de caracteres é a identificação. do controle  
  
 Consulte [CTaskDialog::SetOptions](#setoptions) para obter uma lista de opções válidas.  
  
 O `CTaskDialog` fecha quando o usuário seleciona um botão comum, um controle de link de comando, ou fecha o `CTaskDialog`. O valor de retorno é o identificador que indica como o usuário fechou a caixa de diálogo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CTaskDialog n º&1;](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_5.cpp)]  
  
##  <a name="taskdialogcallback"></a>CTaskDialog::TaskDialogCallback  
 O framework chama esse método em resposta a várias mensagens do Windows.  
  
```  
friend:  
HRESULT TaskDialogCallback(
    HWND hWnd,  
    UINT uNotification,  
    WPARAM wParam,  
    LPARAM lParam,  
    LONG_PTR dwRefData);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hwnd`  
 Um identificador para o `m_hWnd` estrutura o `CTaskDialog`.  
  
 [in] `uNotification`  
 O código de notificação que especifica a mensagem gerada.  
  
 [in] `wParam`  
 Mais informações sobre a mensagem.  
  
 [in] `lParam`  
 Mais informações sobre a mensagem.  
  
 [in] `dwRefData`  
 Um ponteiro para o `CTaskDialog` que a mensagem de retorno de chamada se aplica ao objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Depende do código de notificação específica. Consulte a seção Comentários para obter mais informações.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão de `TaskDialogCallback` manipula a mensagem específica e, em seguida, chama apropriado no método do [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md). Por exemplo, em resposta ao `TDN_BUTTON_CLICKED` mensagem, `TaskDialogCallback` chamadas [CTaskDialog::OnCommandControlClick](#oncommandcontrolclick).  
  
 Os valores para `wParam` e `lParam` dependem da mensagem gerada específica. É possível que um ou ambos destes valores estar vazio. A tabela a seguir lista as notificações de padrão com suporte e o que os valores de `wParam` e `lParam` representam. Se você substituir esse método em uma classe derivada, você deve implementar o código de retorno de chamada para cada mensagem na tabela a seguir.  
  
|Mensagem de notificação|Valor `wParam`|Valor `lParam`|  
|--------------------------|--------------------|--------------------|  
|`TDN_CREATED`|Não usado.|Não usado.|  
|`TDN_NAVIGATED`|Não usado.|Não usado.|  
|`TDN_BUTTON_CLICKED`|ID de controle de botão de comando|Não usado.|  
|`TDN_HYPERLINK_CLICKED`|Não usado.|A [LPCWSTR](http://msdn.microsoft.com/library/windows/desktop/aa383751) estrutura que contém o link.|  
|`TDN_TIMER`|Tempo em milissegundos desde a `CTaskDialog` foi criado ou o temporizador foi redefinido.|Não usado.|  
|`TDN_DESTROYED`|Não usado.|Não usado.|  
|`TDN_RADIO_BUTTON_CLICKED`|A ID do botão de rádio.|Não usado.|  
|`TDN_DIALOG_CONSTRUCTED`|Não usado.|Não usado.|  
|`TDN_VERIFICATION_CLICKED`|1 se a caixa de seleção estiver marcada, 0 se não for.|Não usado.|  
|`TDN_HELP`|Não usado.|Não usado.|  
|`TDN_EXPANDO_BUTTON_CLICKED`|0 se a área de expansão estiver recolhida; diferente de zero se o texto de expansão é exibido.|Não usado.|  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Passo a passo: Adicionando um CTaskDialog a um aplicativo](../../mfc/walkthrough-adding-a-ctaskdialog-to-an-application.md)




