---
title: Classe CTaskDialog
ms.date: 11/19/2018
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
ms.openlocfilehash: 3fd67eed7e80a2e594710df8ae8bc6fd13f0e96c
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88837665"
---
# <a name="ctaskdialog-class"></a>Classe CTaskDialog

Uma caixa de diálogo pop-up que funciona como uma caixa de mensagem, mas pode exibir informações adicionais ao usuário. O `CTaskDialog` também inclui a funcionalidade para coletar informações do usuário.

## <a name="syntax"></a>Sintaxe

```
class CTaskDialog : public CObject
```

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|Nome|Descrição|
|-|-|
|[CTaskDialog:: CTaskDialog](#ctaskdialog)|Constrói um objeto `CTaskDialog`.|

### <a name="methods"></a>Métodos

|Nome|Descrição|
|-|-|
|[CTaskDialog:: AddCommandControl](#addcommandcontrol)|Adiciona um controle de botão de comando ao `CTaskDialog` .|
|[CTaskDialog:: AddRadioButton](#addradiobutton)|Adiciona um botão de opção ao `CTaskDialog` .|
|[CTaskDialog:: ClickCommandControl](#clickcommandcontrol)|Clica em um controle de botão de comando ou em um botão comum programaticamente.|
|[CTaskDialog:: ClickRadioButton](#clickradiobutton)|Clica em um botão de opção programaticamente.|
|[CTaskDialog::D oModal](#domodal)|Exibe o `CTaskDialog` .|
|[CTaskDialog:: GetCommonButtonCount](#getcommonbuttoncount)|Recupera o número de botões comuns disponíveis.|
|[CTaskDialog:: GetCommonButtonFlag](#getcommonbuttonflag)|Converte um botão padrão do Windows para o tipo de botão comum associado à `CTaskDialog` classe.|
|[CTaskDialog:: GetCommonButtonId](#getcommonbuttonid)|Converte um dos tipos de botão comuns associados à `CTaskDialog` classe em um botão padrão do Windows.|
|[CTaskDialog:: getoptions](#getoptions)|Retorna os sinalizadores de opção para isso `CTaskDialog` .|
|[CTaskDialog:: GetSelectedCommandControlID](#getselectedcommandcontrolid)|Retorna o controle de botão de comando selecionado.|
|[CTaskDialog:: GetSelectedRadioButtonID](#getselectedradiobuttonid)|Retorna o botão de opção selecionado.|
|[CTaskDialog:: GetVerificationCheckboxState](#getverificationcheckboxstate)|Recupera o estado da caixa de seleção de verificação.|
|[CTaskDialog:: IsCommandControlEnabled](#iscommandcontrolenabled)|Determina se um controle de botão de comando ou um botão comum está habilitado.|
|[CTaskDialog:: IsRadioButtonEnabled](#isradiobuttonenabled)|Determina se um botão de opção está habilitado.|
|[CTaskDialog:: IsSupported](#issupported)|Determina se o computador que está executando o aplicativo dá suporte ao `CTaskDialog` .|
|[CTaskDialog:: LoadCommandControls](#loadcommandcontrols)|Adiciona controles de botão de comando usando dados da tabela de cadeia de caracteres.|
|[CTaskDialog:: loadradiobuttons](#loadradiobuttons)|Adiciona botões de opção usando dados da tabela de cadeia de caracteres.|
|[CTaskDialog:: NavigateTo](#navigateto)|Transfere o foco para outro `CTaskDialog` .|
|[CTaskDialog:: OnCommandControlClick](#oncommandcontrolclick)|A estrutura chama esse método quando o usuário clica em um controle de botão de comando.|
|[CTaskDialog:: OnCreate](#oncreate)|A estrutura chama esse método depois de criar o `CTaskDialog` .|
|[CTaskDialog:: OnDestroy](#ondestroy)|A estrutura chama esse método imediatamente antes de destruir o `CTaskDialog` .|
|[CTaskDialog:: OnExpandButtonClick](#onexpandbuttonclick)|A estrutura chama esse método quando o usuário clica no botão de expansão.|
|[CTaskDialog:: OnHelp](#onhelp)|A estrutura chama esse método quando o usuário solicita ajuda.|
|[CTaskDialog:: OnHyperlinkClick](#onhyperlinkclick)|A estrutura chama esse método quando o usuário clica em um hiperlink.|
|[CTaskDialog:: OnInit](#oninit)|A estrutura chama esse método quando o `CTaskDialog` é inicializado.|
|[CTaskDialog:: OnNavigatePage](#onnavigatepage)|A estrutura chama esse método quando o usuário move o foco em relação aos controles no `CTaskDialog` .|
|[CTaskDialog:: OnRadioButtonClick](#onradiobuttonclick)|A estrutura chama esse método quando o usuário seleciona um controle de botão de opção.|
|[CTaskDialog:: OnTimer](#ontimer)|A estrutura chama esse método quando o temporizador expira.|
|[CTaskDialog:: OnVerificationCheckboxClick](#onverificationcheckboxclick)|A estrutura chama esse método quando o usuário clica na caixa de seleção de verificação.|
|[CTaskDialog:: RemoveAllCommandControls](#removeallcommandcontrols)|Remove todos os controles de comando do `CTaskDialog` .|
|[CTaskDialog:: RemoveAllRadioButtons](#removeallradiobuttons)|Remove todos os botões de opção do `CTaskDialog` .|
|[CTaskDialog:: SetCommandControlOptions](#setcommandcontroloptions)|Atualiza um controle de botão de comando no `CTaskDialog` .|
|[CTaskDialog:: SetCommonButtonOptions](#setcommonbuttonoptions)|Atualiza um subconjunto de botões comuns a serem habilitados e exigem a elevação do UAC.|
|[CTaskDialog:: SetCommonButtons](#setcommonbuttons)|Adiciona botões comuns ao `CTaskDialog` .|
|[CTaskDialog:: setContent](#setcontent)|Atualiza o conteúdo do `CTaskDialog` .|
|[CTaskDialog:: SetDefaultCommandControl](#setdefaultcommandcontrol)|Especifica o controle de botão de comando padrão.|
|[CTaskDialog:: SetDefaultRadioButton](#setdefaultradiobutton)|Especifica o botão de opção padrão.|
|[CTaskDialog:: SetDialogWidth](#setdialogwidth)|Ajusta a largura do `CTaskDialog` .|
|[CTaskDialog:: SetExpansionArea](#setexpansionarea)|Atualiza a área de expansão do `CTaskDialog` .|
|[CTaskDialog:: SetFooterIcon](#setfootericon)|Atualiza o ícone de rodapé do `CTaskDialog` .|
|[CTaskDialog:: SetFooterText](#setfootertext)|Atualiza o texto no rodapé do `CTaskDialog` .|
|[CTaskDialog:: SetMainIcon](#setmainicon)|Atualiza o ícone principal do `CTaskDialog` .|
|[CTaskDialog:: SetMainInstruction](#setmaininstruction)|Atualiza a instrução principal do `CTaskDialog` .|
|[CTaskDialog:: SetOptions](#setoptions)|Configura as opções para o `CTaskDialog` .|
|[CTaskDialog:: SetProgressBarMarquee](#setprogressbarmarquee)|Configura uma barra de marcas para o `CTaskDialog` e adiciona-a à caixa de diálogo.|
|[CTaskDialog:: SetProgressBarPosition](#setprogressbarposition)|Ajusta a posição da barra de progresso.|
|[CTaskDialog:: SetProgressBarRange](#setprogressbarrange)|Ajusta o intervalo da barra de progresso.|
|[CTaskDialog:: setprogressbarstate](#setprogressbarstate)|Define o estado da barra de progresso e a exibe no `CTaskDialog` .|
|[CTaskDialog:: setradiobuttonoptions](#setradiobuttonoptions)|Habilita ou desabilita um botão de opção.|
|[CTaskDialog:: SetVerificationCheckbox](#setverificationcheckbox)|Define o estado marcado da caixa de seleção de verificação.|
|[CTaskDialog:: SetVerificationCheckboxText](#setverificationcheckboxtext)|Define o texto no lado direito da caixa de seleção de verificação.|
|[CTaskDialog:: SetWindowTitle](#setwindowtitle)|Define o título do `CTaskDialog` .|
|[CTaskDialog:: ShowDialog](#showdialog)|Cria e exibe um `CTaskDialog` .|
|[CTaskDialog:: TaskDialogCallback](#taskdialogcallback)|A estrutura chama isso em resposta a várias mensagens do Windows.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|-|-|
|`m_aButtons`|A matriz de controles de botão de comando para o `CTaskDialog` .|
|`m_aRadioButtons`|A matriz de controles de botão de opção para o `CTaskDialog` .|
|`m_bVerified`|`TRUE` indica que a caixa de seleção de verificação está marcada; `FALSE` indica que não é.|
|`m_footerIcon`|O ícone no rodapé do `CTaskDialog` .|
|`m_hWnd`|Um identificador para a janela do `CTaskDialog` .|
|`m_mainIcon`|O ícone principal do `CTaskDialog` .|
|`m_nButtonDisabled`|Uma máscara que indica qual dos botões comuns está desabilitado.|
|`m_nButtonElevation`|Uma máscara que indica qual dos botões comuns requer elevação do UAC.|
|`m_nButtonId`|A ID do controle do botão de comando selecionado.|
|`m_nCommonButton`|Uma máscara que indica quais botões comuns são exibidos no `CTaskDialog` .|
|`m_nDefaultCommandControl`|A ID do controle de botão de comando que é selecionado quando o `CTaskDialog` é exibido.|
|`m_nDefaultRadioButton`|A ID do controle de botão de opção que é selecionado quando o `CTaskDialog` é exibido.|
|`m_nFlags`|Uma máscara que indica as opções para o `CTaskDialog` .|
|`m_nProgressPos`|A posição atual da barra de progresso.  Esse valor deve estar entre `m_nProgressRangeMin` e `m_nProgressRangeMax` .|
|`m_nProgressRangeMax`|O valor máximo da barra de progresso.|
|`m_nProgressRangeMin`|O valor mínimo da barra de progresso.|
|`m_nProgressState`|O estado da barra de progresso. Para obter mais informações, consulte [CTaskDialog:: Setprogressbarstate](#setprogressbarstate).|
|`m_nRadioId`|A ID do controle do botão de opção selecionado.|
|`m_nWidth`|A largura do `CTaskDialog` em pixels.|
|`m_strCollapse`|A cadeia de caracteres `CTaskDialog` exibe à direita da caixa expansão quando as informações expandidas estão ocultas.|
|`m_strContent`|A cadeia de caracteres de conteúdo do `CTaskDialog` .|
|`m_strExpand`|A cadeia de caracteres `CTaskDialog` exibe à direita da caixa expansão quando as informações expandidas são exibidas.|
|`m_strFooter`|O rodapé do `CTaskDialog` .|
|`m_strInformation`|As informações expandidas para o `CTaskDialog` .|
|`m_strMainInstruction`|A principal instrução do `CTaskDialog` .|
|`m_strTitle`|O título do `CTaskDialog`.|
|`m_strVerification`|A cadeia de caracteres `CTaskDialog` exibida à direita da caixa de seleção de verificação.|

## <a name="remarks"></a>Comentários

A `CTaskDialog` classe substitui a caixa de mensagem padrão do Windows e tem funcionalidade adicional, como novos controles para coletar informações do usuário. Essa classe está na biblioteca do MFC no Visual Studio 2010 e posterior. O `CTaskDialog` está disponível a partir do Windows Vista. As versões anteriores do Windows não podem exibir o `CTaskDialog` objeto. Use `CTaskDialog::IsSupported` para determinar em tempo de execução se o usuário atual pode exibir a caixa de diálogo de tarefa. A caixa de mensagem padrão do Windows ainda é suportada.

O `CTaskDialog` está disponível somente quando você cria seu aplicativo usando a biblioteca Unicode.

O `CTaskDialog` tem dois construtores diferentes. Um construtor permite que você especifique dois botões de comando e um máximo de seis controles Button regulares. Você pode adicionar mais botões de comando depois de criar o `CTaskDialog` . O segundo construtor não oferece suporte a botões de comando, mas você pode adicionar um número ilimitado de controles de botão regulares. Para obter mais informações sobre os construtores, consulte [CTaskDialog:: CTaskDialog](#ctaskdialog).

A imagem a seguir mostra um exemplo `CTaskDialog` para ilustrar o local de alguns dos controles.

![Exemplo de CTaskDialog](../../mfc/reference/media/ctaskdialogsample.png "Exemplo de CTaskDialog") <br/>
Exemplo de CTaskDialog

## <a name="requirements"></a>Requisitos

**Sistema operacional mínimo necessário:** Windows Vista

**Cabeçalho:** afxtaskdialog. h

## <a name="ctaskdialogaddcommandcontrol"></a><a name="addcommandcontrol"></a> CTaskDialog:: AddCommandControl

Adiciona um novo controle de botão de comando ao `CTaskDialog` .

```cpp
void AddCommandControl(
    int nCommandControlID,
    const CString& strCaption,
    BOOL bEnabled = TRUE,
    BOOL bRequiresElevation = FALSE);
```

### <a name="parameters"></a>parâmetros

*nCommandControlID*<br/>
no O número de identificação do controle de comando.

*strCaption*<br/>
no A cadeia de caracteres que o `CTaskDialog` exibe para o usuário. Use essa cadeia de caracteres para explicar a finalidade do comando.

*bEnabled*<br/>
no Um parâmetro booliano que indica se o novo botão está habilitado ou desabilitado.

*bRequiresElevation*<br/>
no Um parâmetro booliano que indica se um comando requer elevação.

### <a name="remarks"></a>Comentários

O `CTaskDialog Class` pode exibir um número ilimitado de controles de botão de comando. No entanto, se um `CTaskDialog` exibir qualquer controle de botão de comando, ele poderá exibir um máximo de seis botões. Se um `CTaskDialog` não tiver controles de botão de comando, ele poderá exibir um número ilimitado de botões.

Quando o usuário seleciona um controle de botão de comando, o `CTaskDialog` fecha. Se seu aplicativo exibir a caixa de diálogo usando [CTaskDialog::D omodal](#domodal), `DoModal` retornará o *nCommandControlID* do controle de botão de comando selecionado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#2](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]

## <a name="ctaskdialogaddradiobutton"></a><a name="addradiobutton"></a> CTaskDialog:: AddRadioButton

Adiciona um botão de opção ao `CTaskDialog` .

```cpp
void CTaskDialog::AddRadioButton(
    int nRadioButtonID,
    const CString& strCaption,
    BOOL bEnabled = TRUE);
```

### <a name="parameters"></a>parâmetros

*nRadioButtonID*<br/>
no O número de identificação do botão de opção.

*strCaption*<br/>
no A cadeia de caracteres `CTaskDialog` exibida ao lado do botão de opção.

*bEnabled*<br/>
no Um parâmetro booliano que indica se o botão de opção está habilitado.

### <a name="remarks"></a>Comentários

Os botões de opção para a [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md) permitem que você colete informações do usuário. Use a função [CTaskDialog:: GetSelectedRadioButtonID](#getselectedradiobuttonid) para determinar qual botão de opção está selecionado.

O não `CTaskDialog` exige que os parâmetros *nRadioButtonID* sejam exclusivos para cada botão de opção. No entanto, você poderá enfrentar um comportamento inesperado se não usar um identificador distinto para cada botão de opção.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#3](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]

## <a name="ctaskdialogclickcommandcontrol"></a><a name="clickcommandcontrol"></a> CTaskDialog:: ClickCommandControl

Clica em um controle de botão de comando ou em um botão comum programaticamente.

```
protected:
void ClickCommandControl(int nCommandControlID) const;
```

### <a name="parameters"></a>parâmetros

*nCommandControlID*<br/>
no A ID de comando do controle para clicar.

### <a name="remarks"></a>Comentários

Esse método gera a TDM_CLICK_BUTTON de mensagens do Windows.

## <a name="ctaskdialogclickradiobutton"></a><a name="clickradiobutton"></a> CTaskDialog:: ClickRadioButton

Clica em um botão de opção programaticamente.

```
protected:
void ClickRadioButton(int nRadioButtonID) const;
```

### <a name="parameters"></a>parâmetros

*nRadioButtonID*<br/>
no A ID do botão de opção para clicar.

### <a name="remarks"></a>Comentários

Esse método gera a TDM_CLICK_RADIO_BUTTON de mensagens do Windows.

## <a name="ctaskdialogctaskdialog"></a><a name="ctaskdialog"></a> CTaskDialog:: CTaskDialog

Cria uma instância da [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md).

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

### <a name="parameters"></a>parâmetros

*strContent*<br/>
no A cadeia de caracteres a ser usada para o conteúdo do `CTaskDialog` .

*strMainInstruction*<br/>
no A principal instrução do `CTaskDialog` .

*strTitle*<br/>
no O título do `CTaskDialog` .

*nCommonButtons*<br/>
no Uma máscara dos botões comuns a serem adicionados ao `CTaskDialog` .

*nTaskDialogOptions*<br/>
no O conjunto de opções a ser usado para o `CTaskDialog` .

*strFooter*<br/>
no A cadeia de caracteres a ser usada como o rodapé.

*nIDCommandControlsFirst*<br/>
no A ID da cadeia de caracteres do primeiro comando.

*nIDCommandControlsLast*<br/>
no A ID da cadeia de caracteres do último comando.

### <a name="remarks"></a>Comentários

Há duas maneiras de adicionar um `CTaskDialog` ao seu aplicativo. A primeira maneira é usar um dos construtores para criar um `CTaskDialog` e exibi-lo usando [CTaskDialog::D omodal](#domodal). A segunda maneira é usar a função estática [CTaskDialog:: ShowDialog](#showdialog), que permite que você exiba um `CTaskDialog` sem criar explicitamente um `CTaskDialog` objeto.

O segundo construtor cria controles de botão de comando usando dados do arquivo de recurso do seu aplicativo. A tabela de cadeias de caracteres no arquivo de recurso tem várias cadeias de caracteres com IDs de cadeia associadas. Esse método adiciona um controle de botão de comando para cada entrada válida na tabela de cadeia de caracteres entre *nIDCommandControlsFirst* e *nCommandControlsLast*, inclusive. Para esses controles de botão de comando, a cadeia de caracteres na tabela de cadeia de caracteres é a legenda do controle e a ID da cadeia de caracteres é a ID do controle.

Consulte [CTaskDialog:: SetOptions](#setoptions) para obter uma lista de opções válidas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialogdomodal"></a><a name="domodal"></a> CTaskDialog::D oModal

Mostra o `CTaskDialog` e torna-o modal.

```
INT_PTR DoModal (HWND hParent = ::GetActiveWindow());
```

### <a name="parameters"></a>parâmetros

*hParent*<br/>
no A janela pai do `CTaskDialog` .

### <a name="return-value"></a>Valor Retornado

Um inteiro que corresponde à seleção feita pelo usuário.

### <a name="remarks"></a>Comentários

Exibe esta instância do [CTaskDialog](../../mfc/reference/ctaskdialog-class.md). Em seguida, o aplicativo aguarda que o usuário feche a caixa de diálogo.

O `CTaskDialog` é fechado quando o usuário seleciona um botão comum, um controle de link de comando ou fecha o `CTaskDialog` . O valor de retorno é o identificador que indica como o usuário fechou a caixa de diálogo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialoggetcommonbuttoncount"></a><a name="getcommonbuttoncount"></a> CTaskDialog:: GetCommonButtonCount

Recupera o número de botões comuns.

```
int GetCommonButtonCount() const;
```

### <a name="return-value"></a>Valor Retornado

O número de botões comuns disponíveis.

### <a name="remarks"></a>Comentários

Os botões comuns são os botões padrão que você fornece ao [CTaskDialog:: CTaskDialog](#ctaskdialog). A [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md) exibe os botões na parte inferior da caixa de diálogo.

A lista enumerada de botões é fornecida em CommCtrl. h.

## <a name="ctaskdialoggetcommonbuttonflag"></a><a name="getcommonbuttonflag"></a> CTaskDialog:: GetCommonButtonFlag

Converte um botão padrão do Windows para o tipo de botão comum associado à [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md).

```
int GetCommonButtonFlag(int nButtonId) const;
```

### <a name="parameters"></a>parâmetros

*nButtonId*<br/>
no O valor do botão padrão do Windows.

### <a name="return-value"></a>Valor Retornado

O valor do `CTaskDialog` botão comum correspondente. Se não houver nenhum botão comum correspondente, esse método retornará 0.

## <a name="ctaskdialoggetcommonbuttonid"></a><a name="getcommonbuttonid"></a> CTaskDialog:: GetCommonButtonId

Converte um dos tipos de botão comuns associados à [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md) em um botão padrão do Windows.

```
int GetCommonButtonId(int nFlag);
```

### <a name="parameters"></a>parâmetros

*nalização*<br/>
no O tipo de botão comum associado à `CTaskDialog` classe.

### <a name="return-value"></a>Valor Retornado

O valor do botão padrão correspondente do Windows. Se não houver nenhum botão do Windows correspondente, o método retornará 0.

## <a name="ctaskdialoggetoptions"></a><a name="getoptions"></a> CTaskDialog:: getoptions

Retorna os sinalizadores de opção para isso `CTaskDialog` .

```
int GetOptions() const;
```

### <a name="return-value"></a>Valor Retornado

Os sinalizadores para o `CTaskDialog` .

### <a name="remarks"></a>Comentários

Para obter mais informações sobre as opções disponíveis para a [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md), consulte [CTaskDialog:: SetOptions](#setoptions).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialoggetselectedcommandcontrolid"></a><a name="getselectedcommandcontrolid"></a> CTaskDialog:: GetSelectedCommandControlID

Retorna o controle de botão de comando selecionado.

```
int GetSelectedCommandControlID() const;
```

### <a name="return-value"></a>Valor Retornado

A ID do controle do botão de comando selecionado no momento.

### <a name="remarks"></a>Comentários

Você não precisa usar esse método para recuperar a ID do botão de comando que o usuário selecionou. Essa ID é retornada por [CTaskDialog::D omodal](#domodal) ou [CTaskDialog:: ShowDialog](#showdialog).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#2](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]

## <a name="ctaskdialoggetselectedradiobuttonid"></a><a name="getselectedradiobuttonid"></a> CTaskDialog:: GetSelectedRadioButtonID

Retorna o botão de opção selecionado.

```
int GetSelectedRadioButtonID() const;
```

### <a name="return-value"></a>Valor Retornado

A ID do botão de opção selecionado.

### <a name="remarks"></a>Comentários

Você pode usar esse método depois que o usuário fechar a caixa de diálogo para recuperar o botão de opção selecionado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#3](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]

## <a name="ctaskdialoggetverificationcheckboxstate"></a><a name="getverificationcheckboxstate"></a> CTaskDialog:: GetVerificationCheckboxState

Recupera o estado da caixa de seleção de verificação.

```
BOOL GetVerificationCheckboxState() const;
```

### <a name="return-value"></a>Valor Retornado

TRUE se a caixa de seleção estiver marcada, FALSE se não for.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#5](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_4.cpp)]

## <a name="ctaskdialogiscommandcontrolenabled"></a><a name="iscommandcontrolenabled"></a> CTaskDialog:: IsCommandControlEnabled

Determina se um botão ou controle de botão de comando está habilitado.

```
BOOL IsCommandControlEnabled(int nCommandControlID) const;
```

### <a name="parameters"></a>parâmetros

*nCommandControlID*<br/>
no A ID do controle do botão de comando ou do botão a ser testado.

### <a name="return-value"></a>Valor Retornado

TRUE se o controle estiver habilitado, FALSE se não for.

### <a name="remarks"></a>Comentários

Você pode usar esse método para determinar a disponibilidade dos dois controles de botão de comando e os botões comuns da `CTaskDialog` classe *.

Se *nCommandControlID* não for um identificador válido para um botão comum `CTaskDialog` ou um controle de botão de comando, esse método lançará uma exceção.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#2](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]

## <a name="ctaskdialogisradiobuttonenabled"></a><a name="isradiobuttonenabled"></a> CTaskDialog:: IsRadioButtonEnabled

Determina se um botão de opção está habilitado.

```
BOOL IsRadioButtonEnabled(int nRadioButtonID) const;
```

### <a name="parameters"></a>parâmetros

*nRadioButtonID*<br/>
no A ID do botão de opção a ser testada.

### <a name="return-value"></a>Valor Retornado

TRUE se o botão de opção estiver habilitado, FALSE se não for.

### <a name="remarks"></a>Comentários

Se *nRadioButtonID* não for um identificador válido para um botão de opção, esse método lançará uma exceção.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#3](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]

## <a name="ctaskdialogissupported"></a><a name="issupported"></a> CTaskDialog:: IsSupported

Determina se o computador que está executando o aplicativo dá suporte ao `CTaskDialog` .

```
static BOOL IsSupported();
```

### <a name="return-value"></a>Valor Retornado

TRUE se o computador oferecer suporte a `CTaskDialog` ; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use essa função para determinar em tempo de execução se o computador que está executando seu aplicativo der suporte à `CTaskDialog` classe. Se o computador não oferecer suporte ao `CTaskDialog` , você deverá fornecer outro método de comunicação de informações para o usuário. Seu aplicativo falhará se tentar usar um `CTaskDialog` em um computador que não ofereça suporte à `CTaskDialog` classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#1](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_5.cpp)]

## <a name="ctaskdialogloadcommandcontrols"></a><a name="loadcommandcontrols"></a> CTaskDialog:: LoadCommandControls

Adiciona controles de botão de comando usando dados da tabela de cadeia de caracteres.

```cpp
void LoadCommandControls(
    int nIDCommandControlsFirst,
    int nIDCommandControlsLast);
```

### <a name="parameters"></a>parâmetros

*nIDCommandControlsFirst*<br/>
no A ID da cadeia de caracteres do primeiro comando.

*nIDCommandControlsLast*<br/>
no A ID da cadeia de caracteres do último comando.

### <a name="remarks"></a>Comentários

Esse método cria controles de botão de comando usando dados do arquivo de recurso do seu aplicativo. A tabela de cadeias de caracteres no arquivo de recurso tem várias cadeias de caracteres com IDs de cadeia associadas. Os novos controles de botão de comando adicionados usando esse método usam a cadeia de caracteres para a legenda do controle e a ID da cadeia de caracteres para a ID do controle. O intervalo de cadeias de caracteres selecionado é fornecido por *nIDCommandControlsFirst* e *nCommandControlsLast*, inclusive. Se houver uma entrada vazia no intervalo, o método não adicionará um controle de botão de comando para essa entrada.

Por padrão, os novos controles de botão de comando são habilitados e não exigem elevação.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#2](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]

## <a name="ctaskdialogloadradiobuttons"></a><a name="loadradiobuttons"></a> CTaskDialog:: loadradiobuttons

Adiciona controles de botão de opção usando dados da tabela de cadeia de caracteres.

```cpp
void LoadRadioButtons(
    int nIDRadioButtonsFirst,
    int nIDRadioButtonsLast);
```

### <a name="parameters"></a>parâmetros

*nIDRadioButtonsFirst*<br/>
no A ID da cadeia de caracteres do primeiro botão de opção.

*nIDRadioButtonsLast*<br/>
no A ID da cadeia de caracteres do último botão de opção.

### <a name="remarks"></a>Comentários

Esse método cria botões de opção usando dados do arquivo de recurso do seu aplicativo. A tabela de cadeias de caracteres no arquivo de recurso tem várias cadeias de caracteres com IDs de cadeia associadas. Novos botões de opção adicionados usando esse método usam a cadeia de caracteres para a legenda do botão de opção e a ID da cadeia de caracteres para a ID do botão de opção. O intervalo de cadeias de caracteres selecionado é fornecido por *nIDRadioButtonsFirst* e *nRadioButtonsLast*, inclusive. Se houver uma entrada vazia no intervalo, o método não adicionará um botão de opção para essa entrada.

Por padrão, novos botões de opção são habilitados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#3](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]

## <a name="ctaskdialognavigateto"></a><a name="navigateto"></a> CTaskDialog:: NavigateTo

Transfere o foco para outro `CTaskDialog` .

```
protected:
void NavigateTo(CTaskDialog& oTaskDialog) const;
```

### <a name="parameters"></a>parâmetros

*oTaskDialog*<br/>
no O `CTaskDialog` que recebe o foco.

### <a name="remarks"></a>Comentários

Esse método oculta o atual `CTaskDialog` quando ele exibe o *oTaskDialog*. O *oTaskDialog* é exibido no mesmo local que o atual `CTaskDialog` .

## <a name="ctaskdialogoncommandcontrolclick"></a><a name="oncommandcontrolclick"></a> CTaskDialog:: OnCommandControlClick

A estrutura chama esse método quando o usuário clica em um controle de botão de comando.

```
virtual HRESULT OnCommandControlClick(int nCommandControlID);
```

### <a name="parameters"></a>parâmetros

*nCommandControlID*<br/>
no A ID do controle de botão de comando que o usuário selecionou.

### <a name="return-value"></a>Valor Retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua esse método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogoncreate"></a><a name="oncreate"></a> CTaskDialog:: OnCreate

A estrutura chama esse método depois de criar o `CTaskDialog` .

```
virtual HRESULT OnCreate();
```

### <a name="return-value"></a>Valor Retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua esse método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogondestroy"></a><a name="ondestroy"></a> CTaskDialog:: OnDestroy

A estrutura chama esse método imediatamente antes de destruir o `CTaskDialog` .

```
virtual HRESULT OnDestroy();
```

### <a name="return-value"></a>Valor Retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua esse método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogonexpandbuttonclick"></a><a name="onexpandbuttonclick"></a> CTaskDialog:: OnExpandButtonClick

A estrutura chama esse método quando o usuário clica no botão de expansão.

```
virtual HRESULT OnExpandButtonClicked(BOOL bExpanded);
```

### <a name="parameters"></a>parâmetros

*bExpanded*<br/>
no Um valor diferente de zero indica que as informações extras são exibidas; 0 indica que as informações extras estão ocultas.

### <a name="return-value"></a>Valor Retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua esse método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogonhelp"></a><a name="onhelp"></a> CTaskDialog:: OnHelp

A estrutura chama esse método quando o usuário solicita ajuda.

```
virtual HRESULT OnHelp();
```

### <a name="return-value"></a>Valor Retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua esse método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogonhyperlinkclick"></a><a name="onhyperlinkclick"></a> CTaskDialog:: OnHyperlinkClick

A estrutura chama esse método quando o usuário clica em um hiperlink.

```
virtual HRESULT OnHyperlinkClick(const CString& strHref);
```

### <a name="parameters"></a>parâmetros

*strHref*<br/>
no A cadeia de caracteres que representa o hiperlink.

### <a name="return-value"></a>Valor Retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Esse método chama [ShellExecute](/windows/win32/api/shellapi/nf-shellapi-shellexecutew) antes de retornar S_OK.

Substitua esse método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogoninit"></a><a name="oninit"></a> CTaskDialog:: OnInit

A estrutura chama esse método quando o `CTaskDialog` é inicializado.

```
virtual HRESULT OnInit();
```

### <a name="return-value"></a>Valor Retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua esse método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogonnavigatepage"></a><a name="onnavigatepage"></a> CTaskDialog:: OnNavigatePage

A estrutura chama esse método em resposta ao método [CTaskDialog:: NavigateTo](#navigateto) .

```
virtual HRESULT OnNavigatePage();
```

### <a name="return-value"></a>Valor Retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua esse método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogonradiobuttonclick"></a><a name="onradiobuttonclick"></a> CTaskDialog:: OnRadioButtonClick

A estrutura chama esse método quando o usuário seleciona um controle de botão de opção.

```
virtual HRESULT OnRadioButtonClick(int nRadioButtonID);
```

### <a name="parameters"></a>parâmetros

*nRadioButtonID*<br/>
no A ID do controle de botão de opção em que o usuário clicou.

### <a name="return-value"></a>Valor Retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua esse método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogontimer"></a><a name="ontimer"></a> CTaskDialog:: OnTimer

A estrutura chama esse método quando o temporizador expira.

```
virtual HRESULT OnTimer(long lTime);
```

### <a name="parameters"></a>parâmetros

*lTime*<br/>
no Tempo em milissegundos desde que o `CTaskDialog` foi criado ou o temporizador foi redefinido.

### <a name="return-value"></a>Valor Retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua esse método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogonverificationcheckboxclick"></a><a name="onverificationcheckboxclick"></a> CTaskDialog:: OnVerificationCheckboxClick

A estrutura chama esse método quando o usuário clica na caixa de seleção de verificação.

```
virtual HRESULT OnVerificationCheckboxClick(BOOL bChecked);
```

### <a name="parameters"></a>parâmetros

*bChecked*<br/>
no TRUE indica que a caixa de seleção de verificação está marcada; FALSE indica que não é.

### <a name="return-value"></a>Valor Retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Substitua esse método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogremoveallcommandcontrols"></a><a name="removeallcommandcontrols"></a> CTaskDialog:: RemoveAllCommandControls

Remove todos os controles de botão de comando do `CTaskDialog` .

```cpp
void RemoveAllCommandControls();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#2](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]

## <a name="ctaskdialogremoveallradiobuttons"></a><a name="removeallradiobuttons"></a> CTaskDialog:: RemoveAllRadioButtons

Remove todos os botões de opção do `CTaskDialog` .

```cpp
void RemoveAllRadioButtons();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#3](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]

## <a name="ctaskdialogsetcommandcontroloptions"></a><a name="setcommandcontroloptions"></a> CTaskDialog:: SetCommandControlOptions

Atualiza um controle de botão de comando no `CTaskDialog` .

```cpp
void SetCommandControlOptions(
    int nCommandControlID,
    BOOL bEnabled,
    BOOL bRequiresElevation = FALSE);
```

### <a name="parameters"></a>parâmetros

*nCommandControlID*<br/>
no A ID do controle de comando a ser atualizada.

*bEnabled*<br/>
no Um parâmetro booliano que indica se o controle de botão de comando especificado está habilitado ou desabilitado.

*bRequiresElevation*<br/>
no Um parâmetro booliano que indica se o controle do botão de comando especificado requer elevação.

### <a name="remarks"></a>Comentários

Use este método para alterar se um controle de botão de comando está habilitado ou requer elevação após ele ter sido adicionado à `CTaskDialog` classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#2](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]

## <a name="ctaskdialogsetcommonbuttonoptions"></a><a name="setcommonbuttonoptions"></a> CTaskDialog:: SetCommonButtonOptions

Atualiza um subconjunto de botões comuns a serem habilitados e para exigir a elevação do UAC.

```cpp
void SetCommonButtonOptions(
    int nDisabledButtonMask,
    int nElevationButtonMask = 0);
```

### <a name="parameters"></a>parâmetros

*nDisabledButtonMask*<br/>
no Uma máscara para os botões comuns a serem desabilitados.

*nElevationButtonMask*<br/>
no Uma máscara para os botões comuns que exigem elevação.

### <a name="remarks"></a>Comentários

Você pode definir os botões comuns disponíveis para uma instância da [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md) usando o construtor [CTaskDialog:: CTaskDialog](#ctaskdialog) e o método [CTaskDialog:: SetCommonButtons](#setcommonbuttons). `CTaskDialog::SetCommonButtonOptions` não oferece suporte à adição de novos botões comuns.

Se você usar esse método para desabilitar ou elevar um botão comum que não está disponível para isso `CTaskDialog` , esse método lançará uma exceção usando a macro [garantir](diagnostic-services.md#ensure) .

Esse método habilita qualquer botão disponível para o `CTaskDialog` , mas não está no *nDisabledButtonMask*, mesmo que ele tenha sido desabilitado anteriormente. Esse método trata a elevação de maneira semelhante: ela registra botões comuns como não exigindo elevação se o botão comum estiver disponível, mas não estiver incluído no *nElevationButtonMask*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#6](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_6.cpp)]

## <a name="ctaskdialogsetcommonbuttons"></a><a name="setcommonbuttons"></a> CTaskDialog:: SetCommonButtons

Adiciona botões comuns ao `CTaskDialog` .

```cpp
void SetCommonButtons(
    int nButtonMask,
    int nDisabledButtonMask = 0,
    int nElevationButtonMask = 0);
```

### <a name="parameters"></a>parâmetros

*nButtonMask*<br/>
no Uma máscara dos botões a serem adicionados ao `CTaskDialog` .

*nDisabledButtonMask*<br/>
no Uma máscara dos botões a serem desabilitados.

*nElevationButtonMask*<br/>
no Uma máscara dos botões que exigem elevação.

### <a name="remarks"></a>Comentários

Você não poderá chamar esse método depois que a janela de exibição dessa instância da `CTaskDialog` classe for criada. Se você fizer isso, esse método lançará uma exceção.

Os botões indicados por *nButtonMask* substituem os botões comuns adicionados anteriormente ao `CTaskDialog` . Somente os botões indicados em *nButtonMask* estão disponíveis.

Se *nDisabledButtonMask* ou *nElevationButtonMask* contiver um botão que não esteja em *nButtonMask*, esse método lançará uma exceção [usando a macro](diagnostic-services.md#ensure) If.

Por padrão, todos os botões comuns estão habilitados e não exigem elevação.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#6](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_6.cpp)]

## <a name="ctaskdialogsetcontent"></a><a name="setcontent"></a> CTaskDialog:: setContent

Atualiza o conteúdo do `CTaskDialog` .

```cpp
void SetContent(const CString& strContent);
```

### <a name="parameters"></a>parâmetros

*strContent*<br/>
no A cadeia de caracteres a ser exibida para o usuário.

### <a name="remarks"></a>Comentários

O conteúdo da `CTaskDialog` classe é o texto que é exibido para o usuário na seção principal da caixa de diálogo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialogsetdefaultcommandcontrol"></a><a name="setdefaultcommandcontrol"></a> CTaskDialog:: SetDefaultCommandControl

Especifica o controle de botão de comando padrão.

```cpp
void SetDefaultCommandControl(int nCommandControlID);
```

### <a name="parameters"></a>parâmetros

*nCommandControlID*<br/>
no A ID do controle de botão de comando para ser o padrão.

### <a name="remarks"></a>Comentários

O controle de botão de comando padrão é o controle selecionado quando o `CTaskDialog` é exibido pela primeira vez para o usuário.

Esse método gera uma exceção se não for possível localizar o controle de botão de comando especificado por *nCommandControlID*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#2](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]

## <a name="ctaskdialogsetdefaultradiobutton"></a><a name="setdefaultradiobutton"></a> CTaskDialog:: SetDefaultRadioButton

Especifica o botão de opção padrão.

```cpp
void SetDefaultRadioButton(int nRadioButtonID);
```

### <a name="parameters"></a>parâmetros

*nRadioButtonID*<br/>
no A ID do botão de opção para ser o padrão.

### <a name="remarks"></a>Comentários

O botão de opção padrão é o botão selecionado quando o `CTaskDialog` é exibido pela primeira vez para o usuário.

Esse método gera uma exceção se não for possível localizar o botão de opção especificado por *nRadioButtonID*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#3](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]

## <a name="ctaskdialogsetdialogwidth"></a><a name="setdialogwidth"></a> CTaskDialog:: SetDialogWidth

Ajusta a largura do `CTaskDialog` .

```cpp
void SetDialogWidth(int nWidth = 0);
```

### <a name="parameters"></a>parâmetros

*nWidth*<br/>
no A largura da caixa de diálogo, em pixels.

### <a name="remarks"></a>Comentários

O parâmetro *nWidth* deve ser maior ou igual a 0. Caso contrário, esse método gera uma exceção.

Se *nWidth* for definido como 0, esse método definirá a caixa de diálogo como o tamanho padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialogsetexpansionarea"></a><a name="setexpansionarea"></a> CTaskDialog:: SetExpansionArea

Atualiza a área de expansão do `CTaskDialog` .

```cpp
void SetExpansionArea(
    const CString& strExpandedInformation,
    const CString& strCollapsedLabel = _T(""),
    const CString& strExpandedLabel = _T(""));
```

### <a name="parameters"></a>parâmetros

*strExpandedInformation*<br/>
no A cadeia de caracteres `CTaskDialog` exibida no corpo principal da caixa de diálogo quando o usuário clica no botão de expansão.

*strCollapsedLabel*<br/>
no A cadeia de caracteres `CTaskDialog` exibida ao lado do botão de expansão quando a área expandida é recolhida.

*strExpandedLabel*<br/>
no A cadeia de caracteres `CTaskDialog` exibida ao lado do botão de expansão quando a área expandida é exibida.

### <a name="remarks"></a>Comentários

A área de expansão da `CTaskDialog` classe permite que você forneça informações adicionais ao usuário. A área de expansão está na parte principal do `CTaskDialog` , localizada imediatamente abaixo do título e da cadeia de caracteres de conteúdo.

Quando o `CTaskDialog` é exibido pela primeira vez, ele não mostra as informações expandidas e coloca ao `strCollapsedLabel` lado do botão de expansão. Quando o usuário clica no botão de expansão, o `CTaskDialog` exibe *strExpandedInformation* e altera o rótulo para *strExpandedLabel*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialogsetfootericon"></a><a name="setfootericon"></a> CTaskDialog:: SetFooterIcon

Atualiza o ícone de rodapé do `CTaskDialog` .

```cpp
void SetFooterIcon(HICON hFooterIcon);
void SetFooterIcon(LPCWSTR lpszFooterIcon);
```

### <a name="parameters"></a>parâmetros

*hFooterIcon*<br/>
no O novo ícone para o `CTaskDialog` .

*lpszFooterIcon*<br/>
no O novo ícone para o `CTaskDialog` .

### <a name="remarks"></a>Comentários

O ícone de rodapé é exibido na parte inferior da [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md). Ele pode ter um texto de rodapé associado. Você pode alterar o texto do rodapé com [CTaskDialog:: SetFooterText](#setfootertext).

Esse método gera uma exceção com a [macro If](diagnostic-services.md#ensure) , se o `CTaskDialog` for exibido ou se o parâmetro de entrada for NULL.

Um `CTaskDialog` só pode aceitar um `HICON` ou `LPCWSTR` como um ícone de rodapé. Isso é configurado definindo a opção TDF_USE_HICON_FOOTER no construtor ou [CTaskDialog:: SetOptions](#setoptions). Por padrão, o `CTaskDialog` é configurado para usar `LPCWSTR` como o tipo de entrada para o ícone de rodapé. Esse método gera uma exceção se você tentar definir o ícone usando o tipo inadequado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialogsetfootertext"></a><a name="setfootertext"></a> CTaskDialog:: SetFooterText

Atualiza o texto no rodapé do `CTaskDialog` .

```cpp
void SetFooterText(const CString& strFooterText);
```

### <a name="parameters"></a>parâmetros

*strFooterText*<br/>
no O novo texto do rodapé.

### <a name="remarks"></a>Comentários

O ícone de rodapé é exibido ao lado do texto do rodapé na parte inferior do `CTaskDialog` . Você pode alterar o ícone de rodapé com [CTaskDialog:: SetFooterIcon](#setfootericon).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialogsetmainicon"></a><a name="setmainicon"></a> CTaskDialog:: SetMainIcon

Atualiza o ícone principal do `CTaskDialog` .

```cpp
void SetMainIcon(HICON hMainIcon);
void SetMainIcon(LPCWSTR lpszMainIcon);
```

### <a name="parameters"></a>parâmetros

*hMainIcon*<br/>
no O ícone novo.

*lpszMainIcon*<br/>
no O ícone novo.

### <a name="remarks"></a>Comentários

Esse método gera uma exceção com a [macro If](diagnostic-services.md#ensure) , se o `CTaskDialog` for exibido ou se o parâmetro de entrada for NULL.

Um `CTaskDialog` só pode aceitar um `HICON` ou `LPCWSTR` um ícone principal. Você pode configurar isso definindo a opção TDF_USE_HICON_MAIN no construtor ou no método [CTaskDialog:: SetOptions](#setoptions) . Por padrão, o `CTaskDialog` é configurado para usar `LPCWSTR` como o tipo de entrada para o ícone principal. Esse método gera uma exceção se você tentar definir o ícone usando o tipo inadequado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialogsetmaininstruction"></a><a name="setmaininstruction"></a> CTaskDialog:: SetMainInstruction

Atualiza a instrução principal do `CTaskDialog` .

```cpp
void SetMainInstruction(const CString& strInstructions);
```

### <a name="parameters"></a>parâmetros

*strInstructions*<br/>
no A nova instrução principal.

### <a name="remarks"></a>Comentários

A principal instrução da `CTaskDialog` classe é o texto exibido para o usuário em uma fonte grande em negrito. Ele está localizado na caixa de diálogo abaixo da barra de título.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialogsetoptions"></a><a name="setoptions"></a> CTaskDialog:: SetOptions

Configura as opções para o `CTaskDialog` .

```cpp
void SetOptions(int nOptionFlag);
```

### <a name="parameters"></a>parâmetros

*nOptionFlag*<br/>
no O conjunto de sinalizadores a serem usados para o `CTaskDialog` .

### <a name="remarks"></a>Comentários

Esse método limpa todas as opções atuais para o `CTaskDialog` . Para preservar as opções atuais, você deve recuperá-las primeiro com [CTaskDialog:: getoptions](#getoptions) e combiná-las com as opções que você deseja definir.

A tabela a seguir lista todas as opções válidas.

|Nome|Descrição|
|-|-|
|TDF_ENABLE_HYPERLINKS|Habilita hiperlinks no `CTaskDialog` .|
|TDF_USE_HICON_MAIN|Configura o `CTaskDialog` para usar um `HICON` para o ícone principal. A alternativa é usar um `LPCWSTR` .|
|TDF_USE_HICON_FOOTER|Configura o `CTaskDialog` para usar um `HICON` para o ícone de rodapé. A alternativa é usar um `LPCWSTR` .|
|TDF_ALLOW_DIALOG_CANCELLATION|Permite que o usuário feche o `CTaskDialog` usando o teclado ou usando o ícone no canto superior direito da caixa de diálogo, mesmo que o botão **Cancelar** não esteja habilitado. Se esse sinalizador não estiver definido e o botão **Cancelar** não estiver habilitado, o usuário não poderá fechar a caixa de diálogo usando ALT + F4, a tecla escape ou o botão fechar da barra de título.|
|TDF_USE_COMMAND_LINKS|Configura o `CTaskDialog` para usar controles de botão de comando.|
|TDF_USE_COMMAND_LINKS_NO_ICON|Configura o `CTaskDialog` para usar controles de botão de comando sem exibir um ícone ao lado do controle. TDF_USE_COMMAND_LINKS substitui TDF_USE_COMMAND_LINKS_NO_ICON.|
|TDF_EXPAND_FOOTER_AREA|Indica que a área de expansão está expandida no momento.|
|TDF_EXPANDED_BY_DEFAULT|Determina se a área de expansão é expandida por padrão.|
|TDF_VERIFICATION_FLAG_CHECKED|Indica que a caixa de seleção de verificação está selecionada no momento.|
|TDF_SHOW_PROGRESS_BAR|Configura o `CTaskDialog` para exibir uma barra de progresso.|
|TDF_SHOW_MARQUEE_PROGRESS_BAR|Configura a barra de progresso para ser uma barra de progresso do letreiro. Se você habilitar essa opção, deverá definir TDF_SHOW_PROGRESS_BAR para ter o comportamento esperado.|
|TDF_CALLBACK_TIMER|Indica que o `CTaskDialog` intervalo de retorno de chamada está definido para aproximadamente 200 milissegundos.|
|TDF_POSITION_RELATIVE_TO_WINDOW|Configura o `CTaskDialog` a ser centralizado em relação à janela pai. Se esse sinalizador não estiver habilitado, o `CTaskDialog` será centralizado em relação ao monitor.|
|TDF_RTL_LAYOUT|Configura o `CTaskDialog` para um layout de leitura da direita para a esquerda.|
|TDF_NO_DEFAULT_RADIO_BUTTON|Indica que nenhum botão de opção está selecionado quando o `CTaskDialog` é exibido.|
|TDF_CAN_BE_MINIMIZED|Permite que o usuário minimize o `CTaskDialog` . Para dar suporte a essa opção, o `CTaskDialog` não pode ser modal. O MFC não oferece suporte a essa opção porque o MFC não oferece suporte a modelos sem janela `CTaskDialog` .|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialogsetprogressbarmarquee"></a><a name="setprogressbarmarquee"></a> CTaskDialog:: SetProgressBarMarquee

Configura uma barra de marcas para o `CTaskDialog` e adiciona-a à caixa de diálogo.

```cpp
void SetProgressBarMarquee(
    BOOL bEnabled = TRUE,
    int nMarqueeSpeed = 0);
```

### <a name="parameters"></a>parâmetros

*bEnabled*<br/>
no TRUE para habilitar a barra do letreiro; FALSE para desabilitar a barra do letreiro e removê-la do `CTaskDialog` .

*nMarqueeSpeed*<br/>
no Um inteiro que indica a velocidade da barra do letreiro.

### <a name="remarks"></a>Comentários

A barra do letreiro aparece abaixo do texto principal da `CTaskDialog` classe.

Use *nMarqueeSpeed* para definir a velocidade da barra do letreiro; valores maiores indicam uma velocidade mais lenta. Um valor de 0 para *nMarqueeSpeed* faz com que a barra de letreiro seja movida na velocidade padrão do Windows.

Esse método gera uma exceção [com a macro](diagnostic-services.md#ensure) If If *nMarqueeSpeed* é menor que 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#4](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_7.cpp)]

## <a name="ctaskdialogsetprogressbarposition"></a><a name="setprogressbarposition"></a> CTaskDialog:: SetProgressBarPosition

Ajusta a posição da barra de progresso.

```cpp
void SetProgressBarPosition(int nProgressPos);
```

### <a name="parameters"></a>parâmetros

*nProgressPos*<br/>
no A posição da barra de progresso.

### <a name="remarks"></a>Comentários

Esse método gera uma exceção [com a macro](diagnostic-services.md#ensure) If If *nProgressPos* não está no intervalo de barras de progresso. Você pode alterar o intervalo de barras de progresso com [CTaskDialog:: SetProgressBarRange](#setprogressbarrange).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#4](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_7.cpp)]

## <a name="ctaskdialogsetprogressbarrange"></a><a name="setprogressbarrange"></a> CTaskDialog:: SetProgressBarRange

Ajusta o intervalo da barra de progresso.

```cpp
void SetProgressBarRange(
    int nRangeMin,
    int nRangeMax);
```

### <a name="parameters"></a>parâmetros

*nRangeMin*<br/>
no O limite inferior da barra de progresso.

*nRangeMax*<br/>
no O limite superior da barra de progresso.

### <a name="remarks"></a>Comentários

A posição da barra de progresso é relativa a *nRangeMin* e *nRangeMax*. Por exemplo, se *nRangeMin* for 50 e *nRangeMax* for 100, uma posição de 75 será a metade na barra de progresso. Use [CTaskDialog:: SetProgressBarPosition](#setprogressbarposition) para definir a posição da barra de progresso.

Para exibir a barra de progresso, a opção TDF_SHOW_PROGRESS_BAR deve ser habilitada e TDF_SHOW_MARQUEE_PROGRESS_BAR não deve ser habilitada. Esse método define automaticamente TDF_SHOW_PROGRESS_BAR e limpa TDF_SHOW_MARQUEE_PROGRESS_BAR. Use [CTaskDialog:: SetOptions](#setoptions) para alterar manualmente as opções dessa instância da [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md).

Esse método gera uma exceção [com a macro](diagnostic-services.md#ensure) If If *nRangeMin* não é menor que *nRangeMax*. Esse método também lançará uma exceção se o `CTaskDialog` já estiver exibido e tiver uma barra de progresso do letreiro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#4](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_7.cpp)]

## <a name="ctaskdialogsetprogressbarstate"></a><a name="setprogressbarstate"></a> CTaskDialog:: setprogressbarstate

Define o estado da barra de progresso e a exibe no `CTaskDialog` .

```cpp
void SetProgressBarState(int nState = PBST_NORMAL);
```

### <a name="parameters"></a>parâmetros

*nState*<br/>
no O estado da barra de progresso. Consulte a seção comentários para obter os valores possíveis.

### <a name="remarks"></a>Comentários

Esse método gera uma exceção [com a macro](diagnostic-services.md#ensure) If, se a `CTaskDialog` já estiver exibida, e tem uma barra de progresso de letreiro.

A tabela a seguir lista os possíveis valores para *nState*. Em todos esses casos, a barra de progresso será preenchida com a cor regular até atingir a posição de parada designada. Nesse ponto, ele mudará a cor com base no estado.

|Nome|Descrição|
|-|-|
|PBST_NORMAL|Depois que a barra de progresso é preenchida, o `CTaskDialog` não altera a cor da barra. Por padrão, a cor regular é verde.|
|PBST_ERROR|Depois que a barra de progresso é preenchida, o `CTaskDialog` altera a cor da barra para a cor do erro. Por padrão, isso é vermelho.|
|PBST_PAUSED|Depois que a barra de progresso é preenchida, o `CTaskDialog` altera a cor da barra para a cor pausada. Por padrão, isso é amarelo.|

Você pode definir onde a barra de progresso é interrompida com [CTaskDialog:: SetProgressBarPosition](#setprogressbarposition).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#4](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_7.cpp)]

## <a name="ctaskdialogsetradiobuttonoptions"></a><a name="setradiobuttonoptions"></a> CTaskDialog:: setradiobuttonoptions

Habilita ou desabilita um botão de opção.

```cpp
void SetRadioButtonOptions(
    int nRadioButtonID,
    BOOL bEnabled);
```

### <a name="parameters"></a>parâmetros

*nRadioButtonID*<br/>
no A ID do controle de botão de opção.

*bEnabled*<br/>
no TRUE para habilitar o botão de opção; FALSE para desabilitar o botão de opção.

### <a name="remarks"></a>Comentários

Esse método gera uma exceção [com a macro](diagnostic-services.md#ensure) If If *nRadioButtonID* não é uma ID válida para um botão de opção.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#3](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]

## <a name="ctaskdialogsetverificationcheckbox"></a><a name="setverificationcheckbox"></a> CTaskDialog:: SetVerificationCheckbox

Define o estado marcado da caixa de seleção de verificação.

```cpp
void SetVerificationCheckbox(BOOL bChecked);
```

### <a name="parameters"></a>parâmetros

*bChecked*<br/>
no TRUE para que a caixa de seleção de verificação seja marcada quando o `CTaskDialog` for exibido; FALSE para que a caixa de seleção de verificação não seja selecionada quando o `CTaskDialog` for exibido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#5](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_4.cpp)]

## <a name="ctaskdialogsetverificationcheckboxtext"></a><a name="setverificationcheckboxtext"></a> CTaskDialog:: SetVerificationCheckboxText

Define o texto que é exibido à direita da caixa de seleção de verificação.

```cpp
void SetVerificationCheckboxText(CString& strVerificationText);
```

### <a name="parameters"></a>parâmetros

*strVerificationText*<br/>
no O texto que esse método exibe ao lado da caixa de seleção de verificação.

### <a name="remarks"></a>Comentários

Esse método gera uma exceção [com a macro If, se essa](diagnostic-services.md#ensure) instância da `CTaskDialog` classe já estiver sendo exibida.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#5](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_4.cpp)]

## <a name="ctaskdialogsetwindowtitle"></a><a name="setwindowtitle"></a> CTaskDialog:: SetWindowTitle

Define o título do `CTaskDialog` .

```cpp
void SetWindowTitle(CString& strWindowTitle);
```

### <a name="parameters"></a>parâmetros

*strWindowTitle*<br/>
no O novo título para o `CTaskDialog` .

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialogshowdialog"></a><a name="showdialog"></a> CTaskDialog:: ShowDialog

Cria e exibe um `CTaskDialog` .

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

### <a name="parameters"></a>parâmetros

*strContent*<br/>
no A cadeia de caracteres a ser usada para o conteúdo do `CTaskDialog` .

*strMainInstruction*<br/>
no A principal instrução do `CTaskDialog` .

*strTitle*<br/>
no O título do `CTaskDialog` .

*nIDCommandControlsFirst*<br/>
no A ID da cadeia de caracteres do primeiro comando.

*nIDCommandControlsLast*<br/>
no A ID da cadeia de caracteres do último comando.

*nCommonButtons*<br/>
no Uma máscara dos botões a serem adicionados ao `CTaskDialog` .

*nTaskDialogOptions*<br/>
no O conjunto de opções a ser usado para o `CTaskDialog` .

*strFooter*<br/>
no A cadeia de caracteres a ser usada como o rodapé.

### <a name="return-value"></a>Valor Retornado

Um inteiro que corresponde à seleção feita pelo usuário.

### <a name="remarks"></a>Comentários

Esse método estático permite que você crie uma instância da `CTaskDialog` classe sem criar explicitamente um `CTaskDialog` objeto em seu código. Como não há nenhum `CTaskDialog` objeto, você não poderá chamar outros métodos do `CTaskDialog` se usar esse método para mostrar um `CTaskDialog` para o usuário.

Esse método cria controles de botão de comando usando dados do arquivo de recurso do seu aplicativo. A tabela de cadeias de caracteres no arquivo de recurso tem várias cadeias de caracteres com IDs de cadeia associadas. Esse método adiciona um controle de botão de comando para cada entrada válida na tabela de cadeia de caracteres entre *nIDCommandControlsFirst* e *nCommandControlsLast*, inclusive. Para esses controles de botão de comando, a cadeia de caracteres na tabela de cadeia de caracteres é a legenda do controle e a ID da cadeia de caracteres é a ID do controle.

Consulte [CTaskDialog:: SetOptions](#setoptions) para obter uma lista de opções válidas.

O `CTaskDialog` é fechado quando o usuário seleciona um botão comum, um controle de link de comando ou fecha o `CTaskDialog` . O valor de retorno é o identificador que indica como o usuário fechou a caixa de diálogo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#1](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_5.cpp)]

## <a name="ctaskdialogtaskdialogcallback"></a><a name="taskdialogcallback"></a> CTaskDialog:: TaskDialogCallback

A estrutura chama esse método em resposta a várias mensagens do Windows.

```
friend:
HRESULT TaskDialogCallback(
    HWND hWnd,
    UINT uNotification,
    WPARAM wParam,
    LPARAM lParam,
    LONG_PTR dwRefData);
```

### <a name="parameters"></a>parâmetros

*HWND*<br/>
no Um identificador para a `m_hWnd` estrutura do `CTaskDialog` .

*uNotification*<br/>
no O código de notificação que especifica a mensagem gerada.

*wParam*<br/>
no Mais informações sobre a mensagem.

*lParam*<br/>
no Mais informações sobre a mensagem.

*dwRefData*<br/>
no Um ponteiro para o `CTaskDialog` objeto ao qual a mensagem de retorno de chamada se aplica.

### <a name="return-value"></a>Valor Retornado

Depende do código de notificação específico. Consulte a seção Comentários para obter mais informações.

### <a name="remarks"></a>Comentários

A implementação padrão de `TaskDialogCallback` manipula a mensagem específica e, em seguida, chama o método on apropriado da [classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md). Por exemplo, em resposta à mensagem de TDN_BUTTON_CLICKED, `TaskDialogCallback` chama [CTaskDialog:: OnCommandControlClick](#oncommandcontrolclick).

Os valores de *wParam* e *lParam* dependem da mensagem gerada específica. É possível que um ou ambos os valores estejam vazios. A tabela a seguir lista as notificações padrão com suporte e quais os valores de *wParam* e *lParam* representam. Se você substituir esse método em uma classe derivada, deverá implementar o código de retorno de chamada para cada mensagem na tabela a seguir.

|Mensagem de notificação|*wParam* Valor|*lParam* Valor|
|--------------------------|--------------------|--------------------|
|TDN_CREATED|Não usado.|Não usado.|
|TDN_NAVIGATED|Não usado.|Não usado.|
|TDN_BUTTON_CLICKED|A ID de controle do botão de comando.|Não usado.|
|TDN_HYPERLINK_CLICKED|Não usado.|Uma estrutura [LPCWSTR](/windows/win32/WinProg/windows-data-types) que contém o link.|
|TDN_TIMER|Tempo em milissegundos desde que o `CTaskDialog` foi criado ou o temporizador foi redefinido.|Não usado.|
|TDN_DESTROYED|Não usado.|Não usado.|
|TDN_RADIO_BUTTON_CLICKED|A ID do botão de opção.|Não usado.|
|TDN_DIALOG_CONSTRUCTED|Não usado.|Não usado.|
|TDN_VERIFICATION_CLICKED|1 se a caixa de seleção estiver marcada, 0 se não for.|Não usado.|
|TDN_HELP|Não usado.|Não usado.|
|TDN_EXPANDO_BUTTON_CLICKED|0 se a área de expansão estiver recolhida; diferente de zero se o texto de expansão for exibido.|Não usado.|

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Walkthrough: adicionando um CTaskDialog a um aplicativo](../../mfc/walkthrough-adding-a-ctaskdialog-to-an-application.md)
