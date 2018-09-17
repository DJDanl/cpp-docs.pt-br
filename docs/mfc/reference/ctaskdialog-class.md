---
title: Classe CTaskDialog | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
- CTaskDialog [MFC], CTaskDialog
- CTaskDialog [MFC], AddCommandControl
- CTaskDialog [MFC], AddRadioButton
- CTaskDialog [MFC], ClickCommandControl
- CTaskDialog [MFC], ClickRadioButton
- CTaskDialog [MFC], DoModal
- CTaskDialog [MFC], GetCommonButtonCount
- CTaskDialog [MFC], GetCommonButtonFlag
- CTaskDialog [MFC], GetCommonButtonId
- CTaskDialog [MFC], GetOptions
- CTaskDialog [MFC], GetSelectedCommandControlID
- CTaskDialog [MFC], GetSelectedRadioButtonID
- CTaskDialog [MFC], GetVerificationCheckboxState
- CTaskDialog [MFC], IsCommandControlEnabled
- CTaskDialog [MFC], IsRadioButtonEnabled
- CTaskDialog [MFC], IsSupported
- CTaskDialog [MFC], LoadCommandControls
- CTaskDialog [MFC], LoadRadioButtons
- CTaskDialog [MFC], NavigateTo
- CTaskDialog [MFC], OnCommandControlClick
- CTaskDialog [MFC], OnCreate
- CTaskDialog [MFC], OnDestroy
- CTaskDialog [MFC], OnExpandButtonClick
- CTaskDialog [MFC], OnHelp
- CTaskDialog [MFC], OnHyperlinkClick
- CTaskDialog [MFC], OnInit
- CTaskDialog [MFC], OnNavigatePage
- CTaskDialog [MFC], OnRadioButtonClick
- CTaskDialog [MFC], OnTimer
- CTaskDialog [MFC], OnVerificationCheckboxClick
- CTaskDialog [MFC], RemoveAllCommandControls
- CTaskDialog [MFC], RemoveAllRadioButtons
- CTaskDialog [MFC], SetCommandControlOptions
- CTaskDialog [MFC], SetCommonButtonOptions
- CTaskDialog [MFC], SetCommonButtons
- CTaskDialog [MFC], SetContent
- CTaskDialog [MFC], SetDefaultCommandControl
- CTaskDialog [MFC], SetDefaultRadioButton
- CTaskDialog [MFC], SetDialogWidth
- CTaskDialog [MFC], SetExpansionArea
- CTaskDialog [MFC], SetFooterIcon
- CTaskDialog [MFC], SetFooterText
- CTaskDialog [MFC], SetMainIcon
- CTaskDialog [MFC], SetMainInstruction
- CTaskDialog [MFC], SetOptions
- CTaskDialog [MFC], SetProgressBarMarquee
- CTaskDialog [MFC], SetProgressBarPosition
- CTaskDialog [MFC], SetProgressBarRange
- CTaskDialog [MFC], SetProgressBarState
- CTaskDialog [MFC], SetRadioButtonOptions
- CTaskDialog [MFC], SetVerificationCheckbox
- CTaskDialog [MFC], SetVerificationCheckboxText
- CTaskDialog [MFC], SetWindowTitle
- CTaskDialog [MFC], ShowDialog
- CTaskDialog [MFC], TaskDialogCallback
ms.assetid: 1991ec98-ae56-4483-958b-233809c8c559
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 51970f99a05b587bcdbccc5d24ad21b036d87f74
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45710808"
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
|[CTaskDialog::ClickRadioButton](#clickradiobutton)|Clica em um botão de rádio por meio de programação.|
|[CTaskDialog::DoModal](#domodal)|Exibe o `CTaskDialog`.|
|[CTaskDialog::GetCommonButtonCount](#getcommonbuttoncount)|Recupera o número de botões comuns disponíveis.|
|[CTaskDialog::GetCommonButtonFlag](#getcommonbuttonflag)|Converte um padrão de botão do Windows para o tipo de botão comuns associado a `CTaskDialog` classe.|
|[CTaskDialog::GetCommonButtonId](#getcommonbuttonid)|Converte um dos tipos comuns de botão associados com o `CTaskDialog` classe para um botão padrão do Windows.|
|[CTaskDialog::GetOptions](#getoptions)|Retorna os sinalizadores de opção para este `CTaskDialog`.|
|[CTaskDialog::GetSelectedCommandControlID](#getselectedcommandcontrolid)|Retorna o controle de botão de comando selecionado.|
|[CTaskDialog::GetSelectedRadioButtonID](#getselectedradiobuttonid)|Retorna o botão de opção selecionado.|
|[CTaskDialog::GetVerificationCheckboxState](#getverificationcheckboxstate)|Recupera o estado da caixa de seleção de verificação.|
|[CTaskDialog::IsCommandControlEnabled](#iscommandcontrolenabled)|Determina se um controle de botão de comando ou botão comuns está habilitada.|
|[CTaskDialog::IsRadioButtonEnabled](#isradiobuttonenabled)|Determina se um botão de opção está habilitado.|
|[CTaskDialog::IsSupported](#issupported)|Determina se o computador que está executando o aplicativo é compatível com o `CTaskDialog`.|
|[CTaskDialog::LoadCommandControls](#loadcommandcontrols)|Adiciona os controles de botão de comando usando dados da tabela de cadeia de caracteres.|
|[CTaskDialog::LoadRadioButtons](#loadradiobuttons)|Adiciona botões de opção usando dados da tabela de cadeia de caracteres.|
|[CTaskDialog::NavigateTo](#navigateto)|Transfere o foco para outra `CTaskDialog`.|
|[CTaskDialog::OnCommandControlClick](#oncommandcontrolclick)|O framework chama esse método quando o usuário clica em um controle de botão de comando.|
|[CTaskDialog::OnCreate](#oncreate)|O framework chama esse método depois que ele cria o `CTaskDialog`.|
|[CTaskDialog::OnDestroy](#ondestroy)|O framework chama esse método imediatamente antes de ele destrói o `CTaskDialog`.|
|[CTaskDialog::OnExpandButtonClick](#onexpandbuttonclick)|O framework chama esse método quando o usuário clica no botão de expansão.|
|[CTaskDialog::OnHelp](#onhelp)|O framework chama esse método quando o usuário solicita ajuda.|
|[CTaskDialog::OnHyperlinkClick](#onhyperlinkclick)|O framework chama esse método quando o usuário clica em um hiperlink.|
|[CTaskDialog::OnInit](#oninit)|O framework chama esse método quando o `CTaskDialog` é inicializado.|
|[CTaskDialog::OnNavigatePage](#onnavigatepage)|O framework chama esse método quando o usuário move o foco em relação a controles `CTaskDialog`.|
|[CTaskDialog::OnRadioButtonClick](#onradiobuttonclick)|O framework chama esse método quando o usuário seleciona um controle de botão de opção.|
|[CTaskDialog::OnTimer](#ontimer)|O framework chama esse método quando o temporizador expirar.|
|[CTaskDialog::OnVerificationCheckboxClick](#onverificationcheckboxclick)|O framework chama esse método quando o usuário clica na caixa de seleção de verificação.|
|[CTaskDialog::RemoveAllCommandControls](#removeallcommandcontrols)|Remove todos os controles de comando do `CTaskDialog`.|
|[CTaskDialog::RemoveAllRadioButtons](#removeallradiobuttons)|Remove todos os botões de rádio a `CTaskDialog`.|
|[CTaskDialog::SetCommandControlOptions](#setcommandcontroloptions)|Atualiza um controle de botão de comando no `CTaskDialog`.|
|[CTaskDialog::SetCommonButtonOptions](#setcommonbuttonoptions)|Atualiza um subconjunto dos botões comuns para ser habilitado e que exigem elevação do UAC.|
|[CTaskDialog::SetCommonButtons](#setcommonbuttons)|Adiciona os botões comuns para o `CTaskDialog`.|
|[CTaskDialog::SetContent](#setcontent)|Atualiza o conteúdo do `CTaskDialog`.|
|[CTaskDialog::SetDefaultCommandControl](#setdefaultcommandcontrol)|Especifica o controle de botão de comando padrão.|
|[CTaskDialog::SetDefaultRadioButton](#setdefaultradiobutton)|Especifica o botão de opção padrão.|
|[CTaskDialog::SetDialogWidth](#setdialogwidth)|Ajusta a largura do `CTaskDialog`.|
|[CTaskDialog::SetExpansionArea](#setexpansionarea)|Atualiza a área de expansão do `CTaskDialog`.|
|[CTaskDialog::SetFooterIcon](#setfootericon)|Atualiza o ícone de rodapé para o `CTaskDialog`.|
|[CTaskDialog::SetFooterText](#setfootertext)|Atualiza o texto no rodapé do `CTaskDialog`.|
|[CTaskDialog::SetMainIcon](#setmainicon)|Atualiza o ícone principal do `CTaskDialog`.|
|[CTaskDialog::SetMainInstruction](#setmaininstruction)|Atualiza a instrução principal do `CTaskDialog`.|
|[CTaskDialog::SetOptions](#setoptions)|Configura as opções para o `CTaskDialog`.|
|[CTaskDialog::SetProgressBarMarquee](#setprogressbarmarquee)|Configura uma barra de marca de seleção para o `CTaskDialog` e o adiciona à caixa de diálogo.|
|[CTaskDialog::SetProgressBarPosition](#setprogressbarposition)|Ajusta a posição da barra de progresso.|
|[CTaskDialog::SetProgressBarRange](#setprogressbarrange)|Ajusta o intervalo da barra de progresso.|
|[CTaskDialog::SetProgressBarState](#setprogressbarstate)|Define o estado da barra de progresso e os exibe no `CTaskDialog`.|
|[CTaskDialog::SetRadioButtonOptions](#setradiobuttonoptions)|Habilita ou desabilita um botão de opção.|
|[CTaskDialog::SetVerificationCheckbox](#setverificationcheckbox)|Define o estado selecionado da caixa de seleção de verificação.|
|[CTaskDialog::SetVerificationCheckboxText](#setverificationcheckboxtext)|Define o texto no lado direito da caixa de seleção de verificação.|
|[CTaskDialog::SetWindowTitle](#setwindowtitle)|Define o título do `CTaskDialog`.|
|[CTaskDialog::ShowDialog](#showdialog)|Cria e exibe um `CTaskDialog`.|
|[CTaskDialog::TaskDialogCallback](#taskdialogcallback)|O framework chama isso em resposta a várias mensagens do Windows.|

### <a name="data-members"></a>Membros de Dados

|||
|-|-|
|`m_aButtons`|A matriz de controles de botão de comando para o `CTaskDialog`.|
|`m_aRadioButtons`|A matriz de controles de botão de opção para o `CTaskDialog`.|
|`m_bVerified`|`TRUE` indica que a caixa de seleção de verificação está marcada; `FALSE` indica que não é.|
|`m_footerIcon`|O ícone no rodapé do `CTaskDialog`.|
|`m_hWnd`|Um identificador para a janela para o `CTaskDialog`.|
|`m_mainIcon`|O ícone principal do `CTaskDialog`.|
|`m_nButtonDisabled`|Uma máscara que indica qual dos botões comuns estão desabilitados.|
|`m_nButtonElevation`|Uma máscara que indica qual dos botões comuns exigem elevação do UAC.|
|`m_nButtonId`|A ID do controle de botão de comando selecionado.|
|`m_nCommonButton`|Uma máscara que indica quais botões comuns são exibidos na `CTaskDialog`.|
|`m_nDefaultCommandControl`|A ID do botão de comando de controle que está selecionado quando o `CTaskDialog` é exibida.|
|`m_nDefaultRadioButton`|A ID do botão de opção de controle que está selecionado quando o `CTaskDialog` é exibida.|
|`m_nFlags`|Uma máscara que indica as opções para o `CTaskDialog`.|
|`m_nProgressPos`|A posição atual para a barra de progresso.  Esse valor deve estar entre `m_nProgressRangeMin` e `m_nProgressRangeMax`.|
|`m_nProgressRangeMax`|O valor máximo para a barra de progresso.|
|`m_nProgressRangeMin`|O valor mínimo para a barra de progresso.|
|`m_nProgressState`|O estado da barra de progresso. Para obter mais informações, consulte [CTaskDialog::SetProgressBarState](#setprogressbarstate).|
|`m_nRadioId`|A ID do controle de botão de opção selecionado.|
|`m_nWidth`|A largura do `CTaskDialog` em pixels.|
|`m_strCollapse`|A cadeia de caracteres a `CTaskDialog` exibe à direita da caixa de expansão quando as informações expandidas está oculto.|
|`m_strContent`|A cadeia de caracteres de conteúdo a `CTaskDialog`.|
|`m_strExpand`|A cadeia de caracteres a `CTaskDialog` exibe à direita da caixa de expansão quando as informações de expandido são exibidas.|
|`m_strFooter`|Rodapé do `CTaskDialog`.|
|`m_strInformation`|As informações de expandida para o `CTaskDialog`.|
|`m_strMainInstruction`|A instrução principal do `CTaskDialog`.|
|`m_strTitle`|O título do `CTaskDialog`.|
|`m_strVerification`|A cadeia de caracteres que o `CTaskDialog` exibe à direita da caixa de seleção de verificação.|

## <a name="remarks"></a>Comentários

O `CTaskDialog` classe substitui a caixa de mensagem padrão do Windows e tem funcionalidade adicional, como novos controles para coletar informações do usuário. Essa classe é na biblioteca do MFC no Visual Studio 2010 e versões posteriores. O `CTaskDialog` está disponível a partir do Windows Vista. Versões anteriores do Windows não é possível exibir o `CTaskDialog` objeto. Use `CTaskDialog::IsSupported` para determinar no tempo de execução se o usuário atual pode exibir a caixa de diálogo de tarefa. Ainda há suporte para a caixa de mensagem padrão do Windows.

O `CTaskDialog` está disponível apenas quando você cria o aplicativo usando a biblioteca Unicode.

O `CTaskDialog` possui dois construtores diferentes. Um construtor permite que você especifique dois botões de comando e no máximo seis controles de botão regular. Você pode adicionar mais botões de comando depois de criar o `CTaskDialog`. O segundo construtor não oferece suporte a qualquer botões de comando, mas você pode adicionar um número ilimitado de controles de botão regular. Para obter mais informações sobre os construtores, consulte [CTaskDialog::CTaskDialog](#ctaskdialog).

A imagem a seguir mostra um exemplo `CTaskDialog` para ilustrar a localização de alguns dos controles.

![Exemplo de CTaskDialog](../../mfc/reference/media/ctaskdialogsample.png "ctaskdialogsample") CTaskDialog de exemplo

## <a name="requirements"></a>Requisitos

**Sistema operacional mínimo necessário:** Windows Vista

**Cabeçalho:** afxtaskdialog.h

##  <a name="addcommandcontrol"></a>  CTaskDialog::AddCommandControl

Adiciona um novo controle de botão de comando para o `CTaskDialog`.

```
void AddCommandControl(
    int nCommandControlID,
    const CString& strCaption,
    BOOL bEnabled = TRUE,
    BOOL bRequiresElevation = FALSE);
```

### <a name="parameters"></a>Parâmetros

*nCommandControlID*<br/>
[in] O número de identificação do controle de comando.

*strCaption*<br/>
[in] A cadeia de caracteres que o `CTaskDialog` exibe ao usuário. Use essa cadeia de caracteres para explicar a finalidade do comando.

*bAtivado*<br/>
[in] Um parâmetro booliano que indica se o novo botão está habilitado ou desabilitado.

*bRequiresElevation*<br/>
[in] Um parâmetro booliano que indica se um comando requer elevação.

### <a name="remarks"></a>Comentários

O `CTaskDialog Class` pode exibir um número ilimitado de controles de botão de comando. No entanto, se um `CTaskDialog` exibe controles de qualquer botão de comando, ele pode exibir um máximo de seis botões. Se um `CTaskDialog` não tem nenhum controle de botão de comando, ele pode exibir um número ilimitado de botões.

Quando o usuário seleciona um controle de botão de comando, o `CTaskDialog` fecha. Se seu aplicativo exibe a caixa de diálogo usando [CTaskDialog::DoModal](#domodal), `DoModal` retorna o *nCommandControlID* do controle de botão de comando selecionado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#2](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]

##  <a name="addradiobutton"></a>  CTaskDialog::AddRadioButton

Adiciona um botão de opção para o `CTaskDialog`.

```
void CTaskDialog::AddRadioButton(
    int nRadioButtonID,
    const CString& strCaption,
    BOOL bEnabled = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nRadioButtonID*<br/>
[in] O número de identificação do botão de opção.

*strCaption*<br/>
[in] A cadeia de caracteres que o `CTaskDialog` é exibido ao lado do botão de opção.

*bAtivado*<br/>
[in] Um parâmetro booliano que indica se o botão de opção está habilitado.

### <a name="remarks"></a>Comentários

Botões de rádio para o [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md) permitem coletar informações do usuário. Use a função [CTaskDialog::GetSelectedRadioButtonID](#getselectedradiobuttonid) para determinar qual botão de opção está selecionado.

O `CTaskDialog` não requer que o *nRadioButtonID* parâmetros são exclusivos para cada botão de opção. No entanto, você pode enfrentar um comportamento inesperado se você não usar um identificador distinto para cada botão de opção.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#3](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]

##  <a name="clickcommandcontrol"></a>  CTaskDialog::ClickCommandControl

Clica em um controle de botão de comando ou botão comum por meio de programação.

```
protected:
void ClickCommandControl(int nCommandControlID) const;
```

### <a name="parameters"></a>Parâmetros

*nCommandControlID*<br/>
[in] A ID de comando do controle, clique em.

### <a name="remarks"></a>Comentários

Este método gera a mensagem do windows TDM_CLICK_BUTTON.

##  <a name="clickradiobutton"></a>  CTaskDialog::ClickRadioButton

Clica em um botão de rádio por meio de programação.

```
protected:
void ClickRadioButton(int nRadioButtonID) const;
```

### <a name="parameters"></a>Parâmetros

*nRadioButtonID*<br/>
[in] A ID do botão de opção, clique em.

### <a name="remarks"></a>Comentários

Este método gera a mensagem do windows TDM_CLICK_RADIO_BUTTON.

##  <a name="ctaskdialog"></a>  CTaskDialog::CTaskDialog

Cria uma instância de [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md).

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

*strContent*<br/>
[in] A cadeia de caracteres a ser usado para o conteúdo a `CTaskDialog`.

*strMainInstruction*<br/>
[in] A instrução principal do `CTaskDialog`.

*strTitle*<br/>
[in] O título do `CTaskDialog`.

*nCommonButtons*<br/>
[in] Uma máscara dos botões comuns para adicionar ao `CTaskDialog`.

*nTaskDialogOptions*<br/>
[in] O conjunto de opções a serem usadas para o `CTaskDialog`.

*strFooter*<br/>
[in] A cadeia de caracteres a ser usado como o rodapé.

*nIDCommandControlsFirst*<br/>
[in] A ID de cadeia de caracteres do primeiro comando.

*nIDCommandControlsLast*<br/>
[in] A ID de cadeia de caracteres do último comando.

### <a name="remarks"></a>Comentários

Há duas maneiras que você pode adicionar um `CTaskDialog` ao seu aplicativo. A primeira maneira é usar um dos construtores para criar uma `CTaskDialog` e exibi-lo usando [CTaskDialog::DoModal](#domodal). A segunda maneira é usar a função estática [CTaskDialog::ShowDialog](#showdialog), que permite que você exiba uma `CTaskDialog` sem criar explicitamente um `CTaskDialog` objeto.

O segundo construtor cria controles de botão de comando usando os dados do arquivo de recurso do seu aplicativo. A tabela de cadeia de caracteres no arquivo de recurso tem várias cadeias de caracteres com IDs de cadeia de caracteres associada. Esse método adiciona um controle de botão de comando para cada entrada válida na tabela de cadeia de caracteres entre *nIDCommandControlsFirst* e *nCommandControlsLast*, inclusive. Para esses controles de botão de comando, a cadeia de caracteres na tabela de cadeia de caracteres é a legenda do controle e a ID de cadeia de caracteres é a ID. do controle

Ver [CTaskDialog::SetOptions](#setoptions) para obter uma lista de opções válidas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

##  <a name="domodal"></a>  CTaskDialog::DoModal

Mostra o `CTaskDialog` e o torna restrito.

```
INT_PTR DoModal (HWND hParent = ::GetActiveWindow());
```

### <a name="parameters"></a>Parâmetros

*hParent*<br/>
[in] A janela pai para o `CTaskDialog`.

### <a name="return-value"></a>Valor de retorno

Um inteiro que corresponde à seleção feita pelo usuário.

### <a name="remarks"></a>Comentários

Exibe esta instância das [CTaskDialog](../../mfc/reference/ctaskdialog-class.md). Em seguida, o aplicativo aguarda o usuário fechar a caixa de diálogo.

O `CTaskDialog` fecha quando o usuário seleciona um botão comum, um controle de link de comando, ou fecha o `CTaskDialog`. O valor de retorno é o identificador que indica como o usuário fechou a caixa de diálogo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

##  <a name="getcommonbuttoncount"></a>  CTaskDialog::GetCommonButtonCount

Recupera o número de botões comuns.

```
int GetCommonButtonCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número de botões comuns disponíveis.

### <a name="remarks"></a>Comentários

Os botões comuns são os botões padrão que você fornecer aos [CTaskDialog::CTaskDialog](#ctaskdialog). O [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md) exibe os botões na parte inferior da caixa de diálogo.

A lista enumerada dos botões é fornecida em commctrl. H.

##  <a name="getcommonbuttonflag"></a>  CTaskDialog::GetCommonButtonFlag

Converte um padrão de botão do Windows para o tipo de botão comuns associado a [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md).

```
int GetCommonButtonFlag(int nButtonId) const;
```

### <a name="parameters"></a>Parâmetros

*nButtonId*<br/>
[in] O valor padrão do botão Windows.

### <a name="return-value"></a>Valor de retorno

O valor correspondente `CTaskDialog` botão comuns. Se não houver nenhum botão comuns correspondente, esse método retornará 0.

##  <a name="getcommonbuttonid"></a>  CTaskDialog::GetCommonButtonId

Converte um dos tipos comuns de botão associados a [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md) para um botão padrão do Windows.

```
int GetCommonButtonId(int nFlag);
```

### <a name="parameters"></a>Parâmetros

*Nalização*<br/>
[in] O tipo de botão comuns associados a `CTaskDialog` classe.

### <a name="return-value"></a>Valor de retorno

O valor do botão Windows padrão correspondente. Se não houver nenhum botão correspondente do Windows, o método retornará 0.

##  <a name="getoptions"></a>  CTaskDialog::GetOptions

Retorna os sinalizadores de opção para este `CTaskDialog`.

```
int GetOptions() const;
```

### <a name="return-value"></a>Valor de retorno

Os sinalizadores para o `CTaskDialog`.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre as opções disponíveis para o [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md), consulte [CTaskDialog::SetOptions](#setoptions).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

##  <a name="getselectedcommandcontrolid"></a>  CTaskDialog::GetSelectedCommandControlID

Retorna o controle de botão de comando selecionado.

```
int GetSelectedCommandControlID() const;
```

### <a name="return-value"></a>Valor de retorno

A ID do controle de botão de comando selecionado no momento.

### <a name="remarks"></a>Comentários

Não é necessário usar esse método para recuperar a ID do botão de comando que o usuário selecionou. Essa ID é retornada pela [CTaskDialog::DoModal](#domodal) ou [CTaskDialog::ShowDialog](#showdialog).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#2](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]

##  <a name="getselectedradiobuttonid"></a>  CTaskDialog::GetSelectedRadioButtonID

Retorna o botão de opção selecionado.

```
int GetSelectedRadioButtonID() const;
```

### <a name="return-value"></a>Valor de retorno

A ID do botão de opção selecionado.

### <a name="remarks"></a>Comentários

Você pode usar este método depois que o usuário fecha a caixa de diálogo para recuperar o botão de opção selecionado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#3](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]

##  <a name="getverificationcheckboxstate"></a>  CTaskDialog::GetVerificationCheckboxState

Recupera o estado da caixa de seleção de verificação.

```
BOOL GetVerificationCheckboxState() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se a caixa de seleção estiver marcada, FALSE se não for.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#5](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_4.cpp)]

##  <a name="iscommandcontrolenabled"></a>  CTaskDialog::IsCommandControlEnabled

Determina se um controle de botão de comando ou botão está habilitado.

```
BOOL IsCommandControlEnabled(int nCommandControlID) const;
```

### <a name="parameters"></a>Parâmetros

*nCommandControlID*<br/>
[in] A ID do controle de botão de comando ou botão Testar.

### <a name="return-value"></a>Valor de retorno

TRUE se o controle está habilitado, FALSO se não for.

### <a name="remarks"></a>Comentários

Você pode usar esse método para determinar a disponibilidade de ambos os controles de botão de comando e os botões comuns do `CTaskDialog` classe *.

Se *nCommandControlID* é não um identificador válido para cada uma um comum `CTaskDialog` botão ou um controle de botão de comando, esse método gerará uma exceção.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#2](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]

##  <a name="isradiobuttonenabled"></a>  CTaskDialog::IsRadioButtonEnabled

Determina se um botão de opção está habilitado.

```
BOOL IsRadioButtonEnabled(int nRadioButtonID) const;
```

### <a name="parameters"></a>Parâmetros

*nRadioButtonID*<br/>
[in] A ID do botão de opção para testar.

### <a name="return-value"></a>Valor de retorno

TRUE se o botão de opção é habilitado, FALSO se não for.

### <a name="remarks"></a>Comentários

Se *nRadioButtonID* não é um identificador válido para um botão de opção, esse método gerará uma exceção.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#3](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]

##  <a name="issupported"></a>  CTaskDialog::IsSupported

Determina se o computador que está executando o aplicativo é compatível com o `CTaskDialog`.

```
static BOOL IsSupported();
```

### <a name="return-value"></a>Valor de retorno

TRUE se o computador oferece suporte a `CTaskDialog`; FALSE caso contrário.

### <a name="remarks"></a>Comentários

Use esta função para determinar no tempo de execução se o computador que está executando o aplicativo oferece suporte a `CTaskDialog` classe. Se o computador não dá suporte a `CTaskDialog`, você deverá fornecer outro método de comunicação de informações ao usuário. Seu aplicativo falhará se tentar usar um `CTaskDialog` em um computador que não oferece suporte a `CTaskDialog` classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#1](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_5.cpp)]

##  <a name="loadcommandcontrols"></a>  CTaskDialog::LoadCommandControls

Adiciona os controles de botão de comando usando dados da tabela de cadeia de caracteres.

```
void LoadCommandControls(
    int nIDCommandControlsFirst,
    int nIDCommandControlsLast);
```

### <a name="parameters"></a>Parâmetros

*nIDCommandControlsFirst*<br/>
[in] A ID de cadeia de caracteres do primeiro comando.

*nIDCommandControlsLast*<br/>
[in] A ID de cadeia de caracteres do último comando.

### <a name="remarks"></a>Comentários

Esse método cria controles de botão de comando usando os dados do arquivo de recurso do seu aplicativo. A tabela de cadeia de caracteres no arquivo de recurso tem várias cadeias de caracteres com IDs de cadeia de caracteres associada. Novos controles de botão de comando adicionados usando esse método usam a cadeia de caracteres para a legenda do controle e a ID de cadeia de caracteres para a ID. do controle O intervalo de cadeias de caracteres selecionada é fornecido pela *nIDCommandControlsFirst* e *nCommandControlsLast*, inclusive. Se houver uma entrada vazia no intervalo, o método não adiciona um controle de botão de comando para a entrada.

Por padrão, novos controles de botão de comando são habilitados e não exigem elevação.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#2](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]

##  <a name="loadradiobuttons"></a>  CTaskDialog::LoadRadioButtons

Adiciona os controles de botão de opção usando dados da tabela de cadeia de caracteres.

```
void LoadRadioButtons(
    int nIDRadioButtonsFirst,
    int nIDRadioButtonsLast);
```

### <a name="parameters"></a>Parâmetros

*nIDRadioButtonsFirst*<br/>
[in] A ID de cadeia de caracteres do primeiro botão de opção.

*nIDRadioButtonsLast*<br/>
[in] A ID de cadeia de caracteres do último botão de opção.

### <a name="remarks"></a>Comentários

Esse método cria os botões de opção por meio de dados do arquivo de recurso do seu aplicativo. A tabela de cadeia de caracteres no arquivo de recurso tem várias cadeias de caracteres com IDs de cadeia de caracteres associada. Novos botões de opção adicionados usando esse método usam a cadeia de caracteres para a legenda do botão de opção e a ID de cadeia de caracteres para a ID. do botão de opção O intervalo de cadeias de caracteres selecionada é fornecido pela *nIDRadioButtonsFirst* e *nRadioButtonsLast*, inclusive. Se houver uma entrada vazia no intervalo, o método não adiciona um botão de opção para a entrada.

Por padrão, novos botões de opção estão habilitados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#3](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]

##  <a name="navigateto"></a>  CTaskDialog::NavigateTo

Transfere o foco para outra `CTaskDialog`.

```
protected:
void NavigateTo(CTaskDialog& oTaskDialog) const;
```

### <a name="parameters"></a>Parâmetros

*oTaskDialog*<br/>
[in] O `CTaskDialog` que recebe o foco.

### <a name="remarks"></a>Comentários

Esse método oculta atual `CTaskDialog` quando ele for exibido o *oTaskDialog*. O *oTaskDialog* é exibido no mesmo local que atual `CTaskDialog`.

##  <a name="oncommandcontrolclick"></a>  CTaskDialog::OnCommandControlClick

O framework chama esse método quando o usuário clica em um controle de botão de comando.

```
virtual HRESULT OnCommandControlClick(int nCommandControlID);
```

### <a name="parameters"></a>Parâmetros

*nCommandControlID*<br/>
[in] A ID do controle de botão de comando que o usuário selecionou.

### <a name="return-value"></a>Valor de retorno

A implementação padrão Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua este método em uma classe derivada para implementar comportamento personalizado.

##  <a name="oncreate"></a>  CTaskDialog::OnCreate

O framework chama esse método depois que ele cria o `CTaskDialog`.

```
virtual HRESULT OnCreate();
```

### <a name="return-value"></a>Valor de retorno

A implementação padrão Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua este método em uma classe derivada para implementar comportamento personalizado.

##  <a name="ondestroy"></a>  CTaskDialog::OnDestroy

O framework chama esse método imediatamente antes de ele destrói o `CTaskDialog`.

```
virtual HRESULT OnDestroy();
```

### <a name="return-value"></a>Valor de retorno

A implementação padrão Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua este método em uma classe derivada para implementar comportamento personalizado.

##  <a name="onexpandbuttonclick"></a>  CTaskDialog::OnExpandButtonClick

O framework chama esse método quando o usuário clica no botão de expansão.

```
virtual HRESULT OnExpandButtonClicked(BOOL bExpanded);
```

### <a name="parameters"></a>Parâmetros

*bExpanded*<br/>
[in] Um valor diferente de zero indica que as informações extras são exibidas. 0 indica que as informações extras está oculto.

### <a name="return-value"></a>Valor de retorno

A implementação padrão Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua este método em uma classe derivada para implementar comportamento personalizado.

##  <a name="onhelp"></a>  CTaskDialog::OnHelp

O framework chama esse método quando o usuário solicita ajuda.

```
virtual HRESULT OnHelp();
```

### <a name="return-value"></a>Valor de retorno

A implementação padrão Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua este método em uma classe derivada para implementar comportamento personalizado.

##  <a name="onhyperlinkclick"></a>  CTaskDialog::OnHyperlinkClick

O framework chama esse método quando o usuário clica em um hiperlink.

```
virtual HRESULT OnHyperlinkClick(const CString& strHref);
```

### <a name="parameters"></a>Parâmetros

*strHref*<br/>
[in] A cadeia de caracteres que representa o hiperlink.

### <a name="return-value"></a>Valor de retorno

A implementação padrão Retorna S_OK.

### <a name="remarks"></a>Comentários

Este método chama [ShellExecute](/windows/desktop/api/shellapi/nf-shellapi-shellexecutea) antes de retornar S_OK.

Substitua este método em uma classe derivada para implementar comportamento personalizado.

##  <a name="oninit"></a>  CTaskDialog::OnInit

O framework chama esse método quando o `CTaskDialog` é inicializado.

```
virtual HRESULT OnInit();
```

### <a name="return-value"></a>Valor de retorno

A implementação padrão Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua este método em uma classe derivada para implementar comportamento personalizado.

##  <a name="onnavigatepage"></a>  CTaskDialog::OnNavigatePage

O framework chama esse método em resposta à [CTaskDialog::NavigateTo](#navigateto) método.

```
virtual HRESULT OnNavigatePage();
```

### <a name="return-value"></a>Valor de retorno

A implementação padrão Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua este método em uma classe derivada para implementar comportamento personalizado.

##  <a name="onradiobuttonclick"></a>  CTaskDialog::OnRadioButtonClick

O framework chama esse método quando o usuário seleciona um controle de botão de opção.

```
virtual HRESULT OnRadioButtonClick(int nRadioButtonID);
```

### <a name="parameters"></a>Parâmetros

*nRadioButtonID*<br/>
[in] A ID do controle de botão de rádio que o usuário clicou.

### <a name="return-value"></a>Valor de retorno

A implementação padrão Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua este método em uma classe derivada para implementar comportamento personalizado.

##  <a name="ontimer"></a>  CTaskDialog::OnTimer

O framework chama esse método quando o temporizador expirar.

```
virtual HRESULT OnTimer(long lTime);
```

### <a name="parameters"></a>Parâmetros

*lTime*<br/>
[in] Tempo em milissegundos desde a `CTaskDialog` foi criado ou o temporizador foi redefinido.

### <a name="return-value"></a>Valor de retorno

A implementação padrão Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua este método em uma classe derivada para implementar comportamento personalizado.

##  <a name="onverificationcheckboxclick"></a>  CTaskDialog::OnVerificationCheckboxClick

O framework chama esse método quando o usuário clica na caixa de seleção de verificação.

```
virtual HRESULT OnVerificationCheckboxClick(BOOL bChecked);
```

### <a name="parameters"></a>Parâmetros

*bChecked*<br/>
[in] TRUE indica que a caixa de seleção de verificação está selecionada; FALSE indica que não é.

### <a name="return-value"></a>Valor de retorno

A implementação padrão Retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua este método em uma classe derivada para implementar comportamento personalizado.

##  <a name="removeallcommandcontrols"></a>  CTaskDialog::RemoveAllCommandControls

Remove todos os controles de botão de comando do `CTaskDialog`.

```
void RemoveAllCommandControls();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#2](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]

##  <a name="removeallradiobuttons"></a>  CTaskDialog::RemoveAllRadioButtons

Remove todos os botões de rádio a `CTaskDialog`.

```
void RemoveAllRadioButtons();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#3](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]

##  <a name="setcommandcontroloptions"></a>  CTaskDialog::SetCommandControlOptions

Atualiza um controle de botão de comando no `CTaskDialog`.

```
void SetCommandControlOptions(
    int nCommandControlID,
    BOOL bEnabled,
    BOOL bRequiresElevation = FALSE);
```

### <a name="parameters"></a>Parâmetros

*nCommandControlID*<br/>
[in] A ID do controle de comando para atualizar.

*bAtivado*<br/>
[in] Um parâmetro booliano que indica se o controle de botão de comando especificado está habilitado ou desabilitado.

*bRequiresElevation*<br/>
[in] Um parâmetro booliano que indica se o controle de botão de comando especificado requer elevação.

### <a name="remarks"></a>Comentários

Use esse método para alterar se um controle de botão de comando é habilitado ou exige a elevação depois que ele foi adicionado para o `CTaskDialog` classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#2](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]

##  <a name="setcommonbuttonoptions"></a>  CTaskDialog::SetCommonButtonOptions

Atualiza um subconjunto dos botões comuns para ser habilitado e exigem elevação do UAC.

```
void SetCommonButtonOptions(
    int nDisabledButtonMask,
    int nElevationButtonMask = 0);
```

### <a name="parameters"></a>Parâmetros

*nDisabledButtonMask*<br/>
[in] Uma máscara para os botões comuns desabilitar.

*nElevationButtonMask*<br/>
[in] Uma máscara para os botões comuns que exigem elevação.

### <a name="remarks"></a>Comentários

Você pode definir os botões comuns disponíveis para uma instância das [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md) usando o construtor [CTaskDialog::CTaskDialog](#ctaskdialog) e o método [CTaskDialog::SetCommonButtons ](#setcommonbuttons). `CTaskDialog::SetCommonButtonOptions` não oferece suporte a adição de novos botões comuns.

Se você usar esse método para desabilitar ou elevar um botão comuns que não está disponível para este `CTaskDialog`, esse método gerará uma exceção usando o [Certifique-se de](diagnostic-services.md#ensure) macro.

Esse método permite que qualquer botão que está disponível para o `CTaskDialog` , mas não está no *nDisabledButtonMask*, mesmo se ele foi previamente desabilitado. Este método trata a elevação de maneira semelhante: registra botões comuns como não exigindo a elevação se o botão comum estiver disponível, mas não está incluído no *nElevationButtonMask*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#6](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_6.cpp)]

##  <a name="setcommonbuttons"></a>  CTaskDialog::SetCommonButtons

Adiciona os botões comuns para o `CTaskDialog`.

```
void SetCommonButtons(
    int nButtonMask,
    int nDisabledButtonMask = 0,
    int nElevationButtonMask = 0);
```

### <a name="parameters"></a>Parâmetros

*nButtonMask*<br/>
[in] Uma máscara dos botões para adicionar ao `CTaskDialog`.

*nDisabledButtonMask*<br/>
[in] Uma máscara dos botões para desabilitar.

*nElevationButtonMask*<br/>
[in] Uma máscara dos botões que exigem elevação.

### <a name="remarks"></a>Comentários

Você não pode chamar esse método após a janela de exibição para esta instância da `CTaskDialog` classe é criada. Se você fizer isso, esse método gera uma exceção.

Os botões indicado por *nButtonMask* substituir quaisquer botões comuns adicionados anteriormente à `CTaskDialog`. Somente os botões indicado na *nButtonMask* estão disponíveis.

Se qualquer um dos *nDisabledButtonMask* ou *nElevationButtonMask* contido em um botão que não está no *nButtonMask*, esse método gerará uma exceção usando o [Certifique-se de](diagnostic-services.md#ensure) macro.

Por padrão, todos os botões comuns são habilitados e não exigem elevação.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#6](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_6.cpp)]

##  <a name="setcontent"></a>  CTaskDialog::SetContent

Atualiza o conteúdo do `CTaskDialog`.

```
void SetContent(const CString& strContent);
```

### <a name="parameters"></a>Parâmetros

*strContent*<br/>
[in] A cadeia de caracteres a ser exibido para o usuário.

### <a name="remarks"></a>Comentários

O conteúdo a `CTaskDialog` classe é o texto que é exibido ao usuário na seção principal da caixa de diálogo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

##  <a name="setdefaultcommandcontrol"></a>  CTaskDialog::SetDefaultCommandControl

Especifica o controle de botão de comando padrão.

```
void SetDefaultCommandControl(int nCommandControlID);
```

### <a name="parameters"></a>Parâmetros

*nCommandControlID*<br/>
[in] A ID do controle de botão de comando para ser o padrão.

### <a name="remarks"></a>Comentários

O controle de botão de comando padrão é o controle que é selecionado quando o `CTaskDialog` é exibido pela primeira vez para o usuário.

Esse método gera uma exceção se não for possível encontrar o controle de botão de comando especificado pelo *nCommandControlID*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#2](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]

##  <a name="setdefaultradiobutton"></a>  CTaskDialog::SetDefaultRadioButton

Especifica o botão de opção padrão.

```
void SetDefaultRadioButton(int nRadioButtonID);
```

### <a name="parameters"></a>Parâmetros

*nRadioButtonID*<br/>
[in] A ID do botão de opção para ser o padrão.

### <a name="remarks"></a>Comentários

O botão de opção padrão é o botão que é selecionado quando o `CTaskDialog` é exibido pela primeira vez para o usuário.

Esse método gera uma exceção se não for possível encontrar o botão de opção especificado por *nRadioButtonID*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#3](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]

##  <a name="setdialogwidth"></a>  CTaskDialog::SetDialogWidth

Ajusta a largura do `CTaskDialog`.

```
void SetDialogWidth(int nWidth = 0);
```

### <a name="parameters"></a>Parâmetros

*nWidth*<br/>
[in] A largura da caixa de diálogo, em pixels.

### <a name="remarks"></a>Comentários

O parâmetro *nWidth* deve ser maior que ou igual a 0. Caso contrário, esse método gera uma exceção.

Se *nWidth* é definido como 0, esse método define a caixa de diálogo para o tamanho padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

##  <a name="setexpansionarea"></a>  CTaskDialog::SetExpansionArea

Atualiza a área de expansão do `CTaskDialog`.

```
void SetExpansionArea(
    const CString& strExpandedInformation,
    const CString& strCollapsedLabel = _T(""),
    const CString& strExpandedLabel = _T(""));
```

### <a name="parameters"></a>Parâmetros

*strExpandedInformation*<br/>
[in] A cadeia de caracteres que o `CTaskDialog` exibe no corpo principal da caixa de diálogo quando o usuário clica no botão de expansão.

*strCollapsedLabel*<br/>
[in] A cadeia de caracteres que o `CTaskDialog` quando a área expandida é recolhida é exibido ao lado do botão de expansão.

*strExpandedLabel*<br/>
[in] A cadeia de caracteres que o `CTaskDialog` é exibido ao lado do botão de expansão quando a área expandida é exibida.

### <a name="remarks"></a>Comentários

A área de expansão do `CTaskDialog` classe permite que você forneça informações adicionais para o usuário. A área de expansão é na parte principal do `CTaskDialog`, localizado imediatamente sob a cadeia de caracteres do título e conteúdo.

Quando o `CTaskDialog` é o primeiro exibido, ele não mostra as informações expandidas e coloca `strCollapsedLabel` ao lado do botão de expansão. Quando o usuário clica no botão de expansão, o `CTaskDialog` exibe *strExpandedInformation* e altera o rótulo a ser *strExpandedLabel*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

##  <a name="setfootericon"></a>  CTaskDialog::SetFooterIcon

Atualiza o ícone de rodapé do `CTaskDialog`.

```
void SetFooterIcon(HICON hFooterIcon);
void SetFooterIcon(LPCWSTR lpszFooterIcon);
```

### <a name="parameters"></a>Parâmetros

*hFooterIcon*<br/>
[in] O ícone novo para o `CTaskDialog`.

*lpszFooterIcon*<br/>
[in] O ícone novo para o `CTaskDialog`.

### <a name="remarks"></a>Comentários

O ícone de rodapé é exibido na parte inferior do [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md). Ela pode ter associada texto do rodapé. Você pode alterar o texto do rodapé com [CTaskDialog::SetFooterText](#setfootertext).

Esse método gera uma exceção com o [Verifique se](diagnostic-services.md#ensure) macro se a `CTaskDialog` é exibida ou o parâmetro de entrada é NULL.

Um `CTaskDialog` só pode aceitar uma `HICON` ou `LPCWSTR` como um ícone de rodapé. Isso é configurado, definindo a opção TDF_USE_HICON_FOOTER no construtor ou [CTaskDialog::SetOptions](#setoptions). Por padrão, o `CTaskDialog` está configurado para usar `LPCWSTR` como o tipo de entrada para o ícone de rodapé. Este método gera uma exceção se você tentar definir o ícone usando o tipo inadequado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

##  <a name="setfootertext"></a>  CTaskDialog::SetFooterText

Atualiza o texto no rodapé do `CTaskDialog`.

```
void SetFooterText(const CString& strFooterText);
```

### <a name="parameters"></a>Parâmetros

*strFooterText*<br/>
[in] O novo texto do rodapé.

### <a name="remarks"></a>Comentários

O ícone de rodapé é exibido ao lado do texto na parte inferior do rodapé do `CTaskDialog`. Você pode alterar o ícone de rodapé com [CTaskDialog::SetFooterIcon](#setfootericon).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

##  <a name="setmainicon"></a>  CTaskDialog::SetMainIcon

Atualiza o ícone principal do `CTaskDialog`.

```
void SetMainIcon(HICON hMainIcon);
void SetMainIcon(LPCWSTR lpszMainIcon);
```

### <a name="parameters"></a>Parâmetros

*hMainIcon*<br/>
[in] O novo ícone.

*lpszMainIcon*<br/>
[in] O novo ícone.

### <a name="remarks"></a>Comentários

Esse método gera uma exceção com o [Verifique se](diagnostic-services.md#ensure) macro se a `CTaskDialog` é exibida ou o parâmetro de entrada é NULL.

Um `CTaskDialog` só pode aceitar uma `HICON` ou `LPCWSTR` como um ícone principal. Você pode configurar isso, definindo a opção TDF_USE_HICON_MAIN no construtor ou nos [CTaskDialog::SetOptions](#setoptions) método. Por padrão, o `CTaskDialog` está configurado para usar `LPCWSTR` como o tipo de entrada para o ícone principal. Este método gera uma exceção se você tentar definir o ícone usando o tipo inadequado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

##  <a name="setmaininstruction"></a>  CTaskDialog::SetMainInstruction

Atualiza a instrução principal do `CTaskDialog`.

```
void SetMainInstruction(const CString& strInstructions);
```

### <a name="parameters"></a>Parâmetros

*strInstructions*<br/>
[in] A nova instrução principal.

### <a name="remarks"></a>Comentários

A instrução principal do `CTaskDialog` classe é o texto exibido para o usuário em uma grande fonte em negrito. Ele está localizado na caixa de diálogo abaixo da barra de título.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

##  <a name="setoptions"></a>  CTaskDialog::SetOptions

Configura as opções para o `CTaskDialog`.

```
void SetOptions(int nOptionFlag);
```

### <a name="parameters"></a>Parâmetros

*nOptionFlag*<br/>
[in] O conjunto de sinalizadores a ser usado para o `CTaskDialog`.

### <a name="remarks"></a>Comentários

Esse método limpa todas as opções atuais para o `CTaskDialog`. Para preservar as opções atuais, você deve recuperá-los pela primeira vez com [CTaskDialog::GetOptions](#getoptions) e combiná-los com as opções que você deseja definir.

A tabela a seguir lista as opções válidas.

|||
|-|-|
|TDF_ENABLE_HYPERLINKS|Permite que os hiperlinks no `CTaskDialog`.|
|TDF_USE_HICON_MAIN|Configura a `CTaskDialog` usar um `HICON` para o ícone principal. A alternativa é usar um `LPCWSTR`.|
|TDF_USE_HICON_FOOTER|Configura a `CTaskDialog` usar um `HICON` para o ícone de rodapé. A alternativa é usar um `LPCWSTR`.|
|TDF_ALLOW_DIALOG_CANCELLATION|Permite que o usuário fechar o `CTaskDialog` usando o teclado ou usando o ícone no canto superior direito da caixa de diálogo, mesmo se o **Cancelar** botão não está habilitado. Se este sinalizador não for definido e o **Cancelar** botão não está habilitado, o usuário não é possível fechar a caixa de diálogo usando Alt + F4, a tecla ESC, ou botão de fechar a barra de título.|
|TDF_USE_COMMAND_LINKS|Configura o `CTaskDialog` usar controles de botão de comando.|
|TDF_USE_COMMAND_LINKS_NO_ICON|Configura o `CTaskDialog` usar controles de botão de comando sem exibir um ícone ao lado do controle. TDF_USE_COMMAND_LINKS substitui TDF_USE_COMMAND_LINKS_NO_ICON.|
|TDF_EXPAND_FOOTER_AREA|Indica que a área de expansão no momento está expandida.|
|TDF_EXPANDED_BY_DEFAULT|Determina se a área de expansão é expandida por padrão.|
|TDF_VERIFICATION_FLAG_CHECKED|Indica se que a caixa de seleção de verificação está selecionada no momento.|
|TDF_SHOW_PROGRESS_BAR|Configura o `CTaskDialog` para exibir uma barra de progresso.|
|TDF_SHOW_MARQUEE_PROGRESS_BAR|Configura a barra de progresso para ser uma barra de progresso com estilo letreiro. Se você habilitar essa opção, você deve definir TDF_SHOW_PROGRESS_BAR ter o comportamento esperado.|
|TDF_CALLBACK_TIMER|Indica que o `CTaskDialog` intervalo de retorno de chamada é definido para aproximadamente 200 milissegundos.|
|TDF_POSITION_RELATIVE_TO_WINDOW|Configura o `CTaskDialog` centralizado em relação à janela pai. Se esse sinalizador não estiver habilitado, o `CTaskDialog` é centralizada em relação ao monitor.|
|TDF_RTL_LAYOUT|Configura o `CTaskDialog` para um layout de leitura da direita para esquerda.|
|TDF_NO_DEFAULT_RADIO_BUTTON|Indica que nenhum botão de opção é selecionada quando o `CTaskDialog` é exibida.|
|TDF_CAN_BE_MINIMIZED|Permite que o usuário minimizar a `CTaskDialog`. Para dar suporte a essa opção, o `CTaskDialog` não pode ser modal. MFC não dá suporte a essa opção porque o MFC não oferece suporte a uma sem janela restrita `CTaskDialog`.|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

##  <a name="setprogressbarmarquee"></a>  CTaskDialog::SetProgressBarMarquee

Configura uma barra de marca de seleção para o `CTaskDialog` e o adiciona à caixa de diálogo.

```
void SetProgressBarMarquee(
    BOOL bEnabled = TRUE,
    int nMarqueeSpeed = 0);
```

### <a name="parameters"></a>Parâmetros

*bAtivado*<br/>
[in] TRUE para habilitar a barra de marca de seleção. FALSE para desabilitar a barra de marca de seleção e removê-lo do `CTaskDialog`.

*nMarqueeSpeed*<br/>
[in] Um inteiro que indica a velocidade da barra de marca de seleção.

### <a name="remarks"></a>Comentários

A barra de marca de seleção é exibida abaixo do texto principal do `CTaskDialog` classe.

Use *nMarqueeSpeed* para definir a velocidade da barra de marca de seleção; valores maiores indicam uma velocidade mais lenta. Um valor de 0 para *nMarqueeSpeed* faz com que a barra de letreiro mover na velocidade padrão para Windows.

Esse método gera uma exceção com o [Verifique se](diagnostic-services.md#ensure) macro se *nMarqueeSpeed* é menor que 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#4](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_7.cpp)]

##  <a name="setprogressbarposition"></a>  CTaskDialog::SetProgressBarPosition

Ajusta a posição da barra de progresso.

```
void SetProgressBarPosition(int nProgressPos);
```

### <a name="parameters"></a>Parâmetros

*nProgressPos*<br/>
[in] A posição para a barra de progresso.

### <a name="remarks"></a>Comentários

Esse método gera uma exceção com o [Verifique se](diagnostic-services.md#ensure) macro se *nProgressPos* não está no intervalo de barra de progresso. Você pode alterar o intervalo da barra de progresso com [CTaskDialog::SetProgressBarRange](#setprogressbarrange).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#4](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_7.cpp)]

##  <a name="setprogressbarrange"></a>  CTaskDialog::SetProgressBarRange

Ajusta o intervalo da barra de progresso.

```
void SetProgressBarRange(
    int nRangeMin,
    int nRangeMax);
```

### <a name="parameters"></a>Parâmetros

*nRangeMin*<br/>
[in] O limite inferior da barra de progresso.

*nRangeMax*<br/>
[in] O limite superior da barra de progresso.

### <a name="remarks"></a>Comentários

A posição da barra de progresso é relativo ao *nRangeMin* e *nRangeMax*. Por exemplo, se *nRangeMin* é 50 e *nRangeMax* é 100, uma posição de 75 é meio caminho entre a barra de progresso. Use [CTaskDialog::SetProgressBarPosition](#setprogressbarposition) para definir a posição da barra de progresso.

Para exibir a barra de progresso, a opção que tdf_show_progress_bar deve estar habilitada e o TDF_SHOW_MARQUEE_PROGRESS_BAR não pode ser habilitada. Esse método automaticamente define TDF_SHOW_PROGRESS_BAR e limpa TDF_SHOW_MARQUEE_PROGRESS_BAR. Use [CTaskDialog::SetOptions](#setoptions) para alterar manualmente as opções para esta instância das [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md).

Esse método gera uma exceção com o [Verifique se](diagnostic-services.md#ensure) macro se *nRangeMin* é não é menor que *nRangeMax*. Esse método também lançará uma exceção se o `CTaskDialog` já é exibido e tem uma barra de progresso com estilo letreiro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#4](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_7.cpp)]

##  <a name="setprogressbarstate"></a>  CTaskDialog::SetProgressBarState

Define o estado da barra de progresso e os exibe no `CTaskDialog`.

```
void SetProgressBarState(int nState = PBST_NORMAL);
```

### <a name="parameters"></a>Parâmetros

*nState*<br/>
[in] O estado da barra de progresso. Consulte a seção comentários para os valores possíveis.

### <a name="remarks"></a>Comentários

Esse método gera uma exceção com o [Verifique se](diagnostic-services.md#ensure) macro se o `CTaskDialog` já é exibido e tem uma barra de progresso com estilo letreiro.

A tabela a seguir lista os possíveis valores para *nState*. Nesses casos, a barra de progresso será preenchido com a cor regular até atingir a posição de parada designado. Nesse ponto, ele mudará de cor com base no estado.

|||
|-|-|
|PBST_NORMAL|Após o andamento da barra é preenchida, o `CTaskDialog` não altera a cor da barra. Por padrão, a cor regular é verde.|
|PBST_ERROR|Após o andamento da barra é preenchida, o `CTaskDialog` altera a cor da barra para a cor do erro. Por padrão, isso é vermelho.|
|PBST_PAUSED|Após o andamento da barra é preenchida, o `CTaskDialog` altera a cor da barra para a cor em pausa. Por padrão, isso é amarelo.|

Você pode definir em que a barra de progresso para com [CTaskDialog::SetProgressBarPosition](#setprogressbarposition).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#4](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_7.cpp)]

##  <a name="setradiobuttonoptions"></a>  CTaskDialog::SetRadioButtonOptions

Habilita ou desabilita um botão de opção.

```
void SetRadioButtonOptions(
    int nRadioButtonID,
    BOOL bEnabled);
```

### <a name="parameters"></a>Parâmetros

*nRadioButtonID*<br/>
[in] A ID do controle de botão de opção.

*bAtivado*<br/>
[in] TRUE para habilitar o botão de opção; FALSE para desabilitar o botão de opção.

### <a name="remarks"></a>Comentários

Esse método gera uma exceção com o [Verifique se](diagnostic-services.md#ensure) macro se *nRadioButtonID* não é uma ID válida para um botão de opção.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#3](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]

##  <a name="setverificationcheckbox"></a>  CTaskDialog::SetVerificationCheckbox

Define o estado selecionado da caixa de seleção de verificação.

```
void SetVerificationCheckbox(BOOL bChecked);
```

### <a name="parameters"></a>Parâmetros

*bChecked*<br/>
[in] True para a caixa de seleção de verificação selecionado quando o `CTaskDialog` são exibidos. FALSE para que a caixa de seleção de verificação não selecionada quando o `CTaskDialog` é exibida.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#5](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_4.cpp)]

##  <a name="setverificationcheckboxtext"></a>  CTaskDialog::SetVerificationCheckboxText

Define o texto que é exibido à direita da caixa de seleção de verificação.

```
void SetVerificationCheckboxText(CString& strVerificationText);
```

### <a name="parameters"></a>Parâmetros

*strVerificationText*<br/>
[in] O texto que esse método é exibido ao lado da caixa de seleção de verificação.

### <a name="remarks"></a>Comentários

Esse método gera uma exceção com o [Certifique-se](diagnostic-services.md#ensure) macro se esta instância da `CTaskDialog` classe já é exibido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#5](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_4.cpp)]

##  <a name="setwindowtitle"></a>  CTaskDialog::SetWindowTitle

Define o título do `CTaskDialog`.

```
void SetWindowTitle(CString& strWindowTitle);
```

### <a name="parameters"></a>Parâmetros

*strWindowTitle*<br/>
[in] O novo título para o `CTaskDialog`.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

##  <a name="showdialog"></a>  CTaskDialog::ShowDialog

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

*strContent*<br/>
[in] A cadeia de caracteres a ser usado para o conteúdo a `CTaskDialog`.

*strMainInstruction*<br/>
[in] A instrução principal do `CTaskDialog`.

*strTitle*<br/>
[in] O título do `CTaskDialog`.

*nIDCommandControlsFirst*<br/>
[in] A ID de cadeia de caracteres do primeiro comando.

*nIDCommandControlsLast*<br/>
[in] A ID de cadeia de caracteres do último comando.

*nCommonButtons*<br/>
[in] Uma máscara dos botões para adicionar ao `CTaskDialog`.

*nTaskDialogOptions*<br/>
[in] O conjunto de opções a serem usadas para o `CTaskDialog`.

*strFooter*<br/>
[in] A cadeia de caracteres a ser usado como o rodapé.

### <a name="return-value"></a>Valor de retorno

Um inteiro que corresponde à seleção feita pelo usuário.

### <a name="remarks"></a>Comentários

Esse método estático permite que você crie uma instância das `CTaskDialog` classe sem criar explicitamente um `CTaskDialog` objeto em seu código. Porque não há nenhuma `CTaskDialog` do objeto, você não pode chamar quaisquer outros métodos de `CTaskDialog` se você usar esse método para mostrar um `CTaskDialog` ao usuário.

Esse método cria controles de botão de comando usando os dados do arquivo de recurso do seu aplicativo. A tabela de cadeia de caracteres no arquivo de recurso tem várias cadeias de caracteres com IDs de cadeia de caracteres associada. Esse método adiciona um controle de botão de comando para cada entrada válida na tabela de cadeia de caracteres entre *nIDCommandControlsFirst* e *nCommandControlsLast*, inclusive. Para esses controles de botão de comando, a cadeia de caracteres na tabela de cadeia de caracteres é a legenda do controle e a ID de cadeia de caracteres é a ID. do controle

Ver [CTaskDialog::SetOptions](#setoptions) para obter uma lista de opções válidas.

O `CTaskDialog` fecha quando o usuário seleciona um botão comum, um controle de link de comando, ou fecha o `CTaskDialog`. O valor de retorno é o identificador que indica como o usuário fechou a caixa de diálogo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#1](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_5.cpp)]

##  <a name="taskdialogcallback"></a>  CTaskDialog::TaskDialogCallback

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

*HWND*<br/>
[in] Um identificador para o `m_hWnd` de estrutura para o `CTaskDialog`.

*uNotification*<br/>
[in] O código de notificação que especifica a mensagem gerada.

*wParam*<br/>
[in] Mais informações sobre a mensagem.

*lParam*<br/>
[in] Mais informações sobre a mensagem.

*dwRefData*<br/>
[in] Um ponteiro para o `CTaskDialog` que a mensagem de retorno de chamada se aplica ao objeto.

### <a name="return-value"></a>Valor de retorno

Depende do código de notificação específica. Consulte a seção Comentários para obter mais informações.

### <a name="remarks"></a>Comentários

A implementação padrão de `TaskDialogCallback` manipula a mensagem específica e, em seguida, chama apropriado no método da [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md). Por exemplo, em resposta à mensagem de TDN_BUTTON_CLICKED `TaskDialogCallback` chamadas [CTaskDialog::OnCommandControlClick](#oncommandcontrolclick).

Os valores para *wParam* e *lParam* dependem da mensagem gerada específica. É possível que um ou ambos esses valores para ficar vazio. A tabela a seguir lista as notificações padrão que têm suporte e o que os valores de *wParam* e *lParam* representam. Se você substituir esse método em uma classe derivada, você deve implementar o código de retorno de chamada para cada mensagem na tabela a seguir.

|Mensagem de notificação|*wParam* valor|*lParam* valor|
|--------------------------|--------------------|--------------------|
|TDN_CREATED|Não usado.|Não usado.|
|TDN_NAVIGATED|Não usado.|Não usado.|
|TDN_BUTTON_CLICKED|ID de controle de botão de comando|Não usado.|
|TDN_HYPERLINK_CLICKED|Não usado.|Um [LPCWSTR](/windows/desktop/WinProg/windows-data-types) estrutura que contém o link.|
|TDN_TIMER|Tempo em milissegundos desde a `CTaskDialog` foi criado ou o temporizador foi redefinido.|Não usado.|
|TDN_DESTROYED|Não usado.|Não usado.|
|TDN_RADIO_BUTTON_CLICKED|A ID do botão de rádio.|Não usado.|
|TDN_DIALOG_CONSTRUCTED|Não usado.|Não usado.|
|TDN_VERIFICATION_CLICKED|1 se a caixa de seleção estiver marcada, 0 se não for.|Não usado.|
|TDN_HELP|Não usado.|Não usado.|
|TDN_EXPANDO_BUTTON_CLICKED|0 se a área de expansão é recolhida; diferente de zero se o texto de expansão é exibido.|Não usado.|

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)  
[Classe CObject](../../mfc/reference/cobject-class.md)  
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)  
[Instruções passo a passo: adicionando um CTaskDialog a um aplicativo](../../mfc/walkthrough-adding-a-ctaskdialog-to-an-application.md)  
