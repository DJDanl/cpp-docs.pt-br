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
ms.openlocfilehash: e9aeee31d2952d5362c983934ce85f0332f553fa
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366640"
---
# <a name="ctaskdialog-class"></a>Classe CTaskDialog

Uma caixa de diálogo pop-up que funciona como uma caixa de mensagens, mas pode exibir informações adicionais ao usuário. O `CTaskDialog` também inclui funcionalidade para coletar informações do usuário.

## <a name="syntax"></a>Sintaxe

```
class CTaskDialog : public CObject
```

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|||
|-|-|
|[ctaskDialog::CtaskDialog](#ctaskdialog)|Constrói um objeto `CTaskDialog`.|

### <a name="methods"></a>Métodos

|||
|-|-|
|[ctaskDialog::AddCommandControl](#addcommandcontrol)|Adiciona um controle de `CTaskDialog`botão de comando ao .|
|[ctaskdialog::AddRadiobutton](#addradiobutton)|Adiciona um botão `CTaskDialog`de rádio ao .|
|[ctaskDialog::ClickCommandControl](#clickcommandcontrol)|Clique em um controle de botão de comando ou botão comum programática.|
|[ctaskdialog::ClickRadioButton](#clickradiobutton)|Clique em um botão de rádio programáticamente.|
|[CTaskDialog::DoModal](#domodal)|Exibe `CTaskDialog`o .|
|[ctaskdialog::GetCommonButtonCount](#getcommonbuttoncount)|Recupera o número de botões comuns disponíveis.|
|[ctaskdialog::GetCommonButtonFlag](#getcommonbuttonflag)|Converte um botão padrão do Windows para `CTaskDialog` o tipo de botão comum associado à classe.|
|[ctaskDialog::GetCommonButtonId](#getcommonbuttonid)|Converte um dos tipos de `CTaskDialog` botões comuns associados à classe a um botão padrão do Windows.|
|[ctaskdialog::getOptions](#getoptions)|Retorna as bandeiras `CTaskDialog`de opção para isso .|
|[ctaskdialog::getSelectedCommandControlID](#getselectedcommandcontrolid)|Retorna o controle do botão de comando selecionado.|
|[ctaskdialog::getSelectedRadiobuttonID](#getselectedradiobuttonid)|Retorna o botão de rádio selecionado.|
|[ctaskDialog::GetVerificationCheckCheckboxState](#getverificationcheckboxstate)|Recupera o estado da caixa de verificação.|
|[CTaskDialog::IsCommandControlEnabled](#iscommandcontrolenabled)|Determina se um controle de botão de comando ou um botão comum está ativado.|
|[ctaskDialog::IsRadioButtonEnabled](#isradiobuttonenabled)|Determina se um botão de rádio está ativado.|
|[ctaskdialog::é suportado](#issupported)|Determina se o computador que está executando `CTaskDialog`o aplicativo suporta o .|
|[CTaskDiálogo::Comando de cargaControles](#loadcommandcontrols)|Adiciona controles de botão de comando usando dados da tabela de strings.|
|[ctaskDiálogo::LoadRadioButtons](#loadradiobuttons)|Adiciona botões de rádio usando dados da tabela de strings.|
|[ctaskdialog::navigateto](#navigateto)|Transfere o `CTaskDialog`foco para outro .|
|[ctaskdialog::OnCommandControlClick](#oncommandcontrolclick)|A estrutura chama esse método quando o usuário clica em um controle de botão de comando.|
|[ctaskdialog::onCreate](#oncreate)|A estrutura chama esse método `CTaskDialog`depois de criar o .|
|[ctaskdialog::OnDestroy](#ondestroy)|A estrutura chama este método imediatamente `CTaskDialog`antes de destruir o .|
|[ctaskdialog::OnExpandButtonClick](#onexpandbuttonclick)|A estrutura chama esse método quando o usuário clica no botão de expansão.|
|[ctaskdialog::OnHelp](#onhelp)|A estrutura chama esse método quando o usuário solicita ajuda.|
|[ctaskdialog::OnHyperlinkClick](#onhyperlinkclick)|A estrutura chama esse método quando o usuário clica em um hiperlink.|
|[CTaskDialog::OnInit](#oninit)|A estrutura chama esse `CTaskDialog` método quando o é inicializado.|
|[ctaskdialog::OnNavigatePage](#onnavigatepage)|A estrutura chama esse método quando o usuário move `CTaskDialog`o foco em relação aos controles no .|
|[ctaskdialog::OnRadioButtonClick](#onradiobuttonclick)|A estrutura chama esse método quando o usuário seleciona um controle de botão de rádio.|
|[CTaskDialog::OnTimer](#ontimer)|A estrutura chama esse método quando o temporizador expira.|
|[ctaskDialog::OnVerificationCheckCheckboxClick](#onverificationcheckboxclick)|A estrutura chama esse método quando o usuário clica na caixa de verificação.|
|[CTaskDialog::RemoveAllCommandControls](#removeallcommandcontrols)|Remove todos os controles de `CTaskDialog`comando do .|
|[ctaskdialog::RemoveAllRadioButtons](#removeallradiobuttons)|Remove todos os botões de `CTaskDialog`rádio do .|
|[ctaskDiálogo::SetCommandControlOptions](#setcommandcontroloptions)|Atualiza um controle de `CTaskDialog`botão de comando no .|
|[ctaskDiálogo::SetSetPáginaPáginadebotões de página](#setcommonbuttonoptions)|Atualiza um subconjunto de botões comuns a serem ativados e requerem elevação do UAC.|
|[cTaskDiálogo::SetCommonButtons](#setcommonbuttons)|Adiciona botões comuns `CTaskDialog`ao .|
|[ctaskDialog::SetContent](#setcontent)|Atualiza o conteúdo `CTaskDialog`do .|
|[ctask '''''''''''''''''''''''''''](#setdefaultcommandcontrol)|Especifica o controle padrão do botão de comando.|
|[ctaskDiálogo::SetDefaultRadiobutton](#setdefaultradiobutton)|Especifica o botão de rádio padrão.|
|[ctaskDialog::Set'SOdia-de-armadepara-dia](#setdialogwidth)|Ajusta a `CTaskDialog`largura do .|
|[ctaskDialog::SetExpansionarea](#setexpansionarea)|Atualiza a área de `CTaskDialog`expansão do .|
|[cTaskDialog::SetFooterIcon](#setfootericon)|Atualiza o ícone de `CTaskDialog`rodapé para o .|
|[CTaskDialog::SetFooterText](#setfootertext)|Atualiza o texto no rodapé `CTaskDialog`do .|
|[ctaskDialog::SetmainIcon](#setmainicon)|Atualiza o ícone principal `CTaskDialog`do .|
|[ctaskDialog::SetMainInstruction](#setmaininstruction)|Atualiza a instrução `CTaskDialog`principal do .|
|[ctaskDialog::Definições de configuração](#setoptions)|Configura as opções `CTaskDialog`para o .|
|[ctaskDialog::setProgressbarMarquee](#setprogressbarmarquee)|Configura uma barra de `CTaskDialog` letreiro para o e adiciona-a à caixa de diálogo.|
|[ctaskDialog::setProgressbarPosition](#setprogressbarposition)|Ajusta a posição da barra de progresso.|
|[ctaskDialog::SetProgressBarrange](#setprogressbarrange)|Ajusta o alcance da barra de progresso.|
|[ctaskDialog::setProgressbarstate](#setprogressbarstate)|Define o estado da barra de `CTaskDialog`progresso e exibe-a no .|
|[ctaskDialog::SetRadioButtonOptions](#setradiobuttonoptions)|Ativa ou desativa um botão de rádio.|
|[ctaskDiálogo::SetVerificationcheckbox](#setverificationcheckbox)|Define o estado verificado da caixa de seleção de verificação.|
|[CTaskDialog::SetVerificationCheckboxText](#setverificationcheckboxtext)|Define o texto no lado direito da caixa de verificação.|
|[ctaskDialog::SetWindowTitle](#setwindowtitle)|Define o título `CTaskDialog`do .|
|[ctaskdialog::showDialog](#showdialog)|Cria e `CTaskDialog`exibe um .|
|[CTaskDialog::TaskDialogCallback](#taskdialogcallback)|A estrutura chama isso em resposta a várias mensagens do Windows.|

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|`m_aButtons`|O conjunto de controles do `CTaskDialog`botão de comando para o .|
|`m_aRadioButtons`|A matriz de controles de `CTaskDialog`botão de rádio para o .|
|`m_bVerified`|`TRUE`indica que a caixa de verificação de verificação é verificada; `FALSE` indica que não é.|
|`m_footerIcon`|O ícone no rodapé `CTaskDialog`do .|
|`m_hWnd`|Uma alça na janela `CTaskDialog`para o.|
|`m_mainIcon`|O principal ícone `CTaskDialog`do .|
|`m_nButtonDisabled`|Uma máscara que indica quais dos botões comuns estão desativados.|
|`m_nButtonElevation`|Uma máscara que indica qual dos botões comuns requerem elevação do UAC.|
|`m_nButtonId`|O ID do controle do botão de comando selecionado.|
|`m_nCommonButton`|Uma máscara que indica quais botões comuns são exibidos no `CTaskDialog`.|
|`m_nDefaultCommandControl`|O ID do controle do botão `CTaskDialog` de comando que é selecionado quando é exibido.|
|`m_nDefaultRadioButton`|O ID do controle do botão `CTaskDialog` de rádio que é selecionado quando o é exibido.|
|`m_nFlags`|Uma máscara que indica `CTaskDialog`as opções para o .|
|`m_nProgressPos`|A posição atual para a barra de progresso.  Este valor deve `m_nProgressRangeMin` `m_nProgressRangeMax`ser entre e .|
|`m_nProgressRangeMax`|O valor máximo para a barra de progresso.|
|`m_nProgressRangeMin`|O valor mínimo para a barra de progresso.|
|`m_nProgressState`|O estado da barra de progresso. Para obter mais informações, consulte [CTaskDialog::SetProgressBarState](#setprogressbarstate).|
|`m_nRadioId`|O ID do controle do botão de rádio selecionado.|
|`m_nWidth`|A largura `CTaskDialog` do em pixels.|
|`m_strCollapse`|A seqüência de `CTaskDialog` displays à direita da caixa de expansão quando as informações expandidas estão ocultas.|
|`m_strContent`|A seqüência `CTaskDialog`de conteúdo do .|
|`m_strExpand`|A seqüência de `CTaskDialog` displays à direita da caixa de expansão quando as informações expandidas são exibidas.|
|`m_strFooter`|O rodapé `CTaskDialog`do.|
|`m_strInformation`|As informações expandidas `CTaskDialog`para o .|
|`m_strMainInstruction`|A principal instrução do `CTaskDialog`.|
|`m_strTitle`|O título do `CTaskDialog`.|
|`m_strVerification`|A seqüência que o `CTaskDialog` exibe à direita da caixa de verificação.|

## <a name="remarks"></a>Comentários

A `CTaskDialog` classe substitui a caixa de mensagens padrão do Windows e tem funcionalidades adicionais, como novos controles para coletar informações do usuário. Esta aula está na biblioteca mfc no Visual Studio 2010 e mais tarde. O `CTaskDialog` está disponível a partir do Windows Vista. Versões anteriores `CTaskDialog` do Windows não podem exibir o objeto. Use `CTaskDialog::IsSupported` para determinar em tempo de execução se o usuário atual pode exibir a caixa de diálogo de tarefas. A caixa de mensagens padrão do Windows ainda é suportada.

O `CTaskDialog` só está disponível quando você constrói seu aplicativo usando a biblioteca Unicode.

Tem `CTaskDialog` dois construtores diferentes. Um construtor permite que você especifique dois botões de comando e um máximo de seis controles de botão regulares. Você pode adicionar mais botões de `CTaskDialog`comando depois de criar o . O segundo construtor não suporta nenhum botão de comando, mas você pode adicionar um número ilimitado de controles de botões regulares. Para obter mais informações sobre os construtores, consulte [CTaskDialog::CTaskDialog](#ctaskdialog).

A imagem a `CTaskDialog` seguir mostra uma amostra para ilustrar a localização de alguns dos controles.

![Exemplo de CTaskDialog](../../mfc/reference/media/ctaskdialogsample.png "Exemplo de CTaskDialog") <br/>
Amostra de CtaskDialog

## <a name="requirements"></a>Requisitos

**Sistema operacional mínimo necessário:** Windows Vista

**Cabeçalho:** afxtaskdialog.h

## <a name="ctaskdialogaddcommandcontrol"></a><a name="addcommandcontrol"></a>ctaskDialog::AddCommandControl

Adiciona um novo controle `CTaskDialog`de botão de comando ao .

```
void AddCommandControl(
    int nCommandControlID,
    const CString& strCaption,
    BOOL bEnabled = TRUE,
    BOOL bRequiresElevation = FALSE);
```

### <a name="parameters"></a>Parâmetros

*nCommandControlID*<br/>
[em] O número de identificação do controle de comando.

*strCaption*<br/>
[em] A seqüência que o `CTaskDialog` é exibido para o usuário. Use esta seqüência para explicar o propósito do comando.

*bEnabled*<br/>
[em] Um parâmetro booleano que indica se o novo botão está ativado ou desativado.

*bRequiresElevation*<br/>
[em] Um parâmetro booleano que indica se um comando requer elevação.

### <a name="remarks"></a>Comentários

O `CTaskDialog Class` pode exibir um número ilimitado de controles de botão de comando. No entanto, se um `CTaskDialog` exibe qualquer comando de botão de comando, ele pode exibir um máximo de seis botões. Se `CTaskDialog` um não tiver controles de botão de comando, ele pode exibir um número ilimitado de botões.

Quando o usuário seleciona um `CTaskDialog` controle de botão de comando, o fechado. Se o aplicativo exibir a caixa de diálogo usando `DoModal` [CTaskDialog::DoModal,](#domodal)retorne o *nCommandControlID* do controle do botão de comando selecionado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#2](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]

## <a name="ctaskdialogaddradiobutton"></a><a name="addradiobutton"></a>ctaskdialog::AddRadiobutton

Adiciona um botão `CTaskDialog`de rádio ao .

```
void CTaskDialog::AddRadioButton(
    int nRadioButtonID,
    const CString& strCaption,
    BOOL bEnabled = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nRadioButtonID*<br/>
[em] O número de identificação do botão de rádio.

*strCaption*<br/>
[em] A seqüência que a `CTaskDialog` seqüência exibe ao lado do botão de rádio.

*bEnabled*<br/>
[em] Um parâmetro booleano que indica se o botão de rádio está ativado.

### <a name="remarks"></a>Comentários

Os botões de rádio da [Classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md) permitem coletar informações do usuário. Use a função [CTaskDialog::GetSelectedRadioButtonID](#getselectedradiobuttonid) para determinar qual botão de rádio está selecionado.

O `CTaskDialog` não requer que os parâmetros *nRadioButtonID* sejam únicos para cada botão de rádio. No entanto, você pode experimentar um comportamento inesperado se não usar um identificador distinto para cada botão de rádio.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#3](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]

## <a name="ctaskdialogclickcommandcontrol"></a><a name="clickcommandcontrol"></a>ctaskDialog::ClickCommandControl

Clique em um controle de botão de comando ou botão comum programática.

```
protected:
void ClickCommandControl(int nCommandControlID) const;
```

### <a name="parameters"></a>Parâmetros

*nCommandControlID*<br/>
[em] O id de comando do controle para clicar.

### <a name="remarks"></a>Comentários

Este método gera a TDM_CLICK_BUTTON de mensagens do Windows.

## <a name="ctaskdialogclickradiobutton"></a><a name="clickradiobutton"></a>ctaskdialog::ClickRadioButton

Clique em um botão de rádio programáticamente.

```
protected:
void ClickRadioButton(int nRadioButtonID) const;
```

### <a name="parameters"></a>Parâmetros

*nRadioButtonID*<br/>
[em] O ID do botão de rádio para clicar.

### <a name="remarks"></a>Comentários

Este método gera a TDM_CLICK_RADIO_BUTTON de mensagens do Windows.

## <a name="ctaskdialogctaskdialog"></a><a name="ctaskdialog"></a>ctaskDialog::CtaskDialog

Cria uma instância da [Classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md).

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
[em] A seqüência a ser `CTaskDialog`usada para o conteúdo do .

*strMainInstruction*<br/>
[em] A principal instrução do `CTaskDialog`.

*strTitle*<br/>
[em] O título `CTaskDialog`do.

*nBotões comuns*<br/>
[em] Uma máscara dos botões comuns `CTaskDialog`para adicionar ao .

*nTask'SOptions de diálogo*<br/>
[em] O conjunto de opções `CTaskDialog`para usar para o .

*strFooter*<br/>
[em] A corda para usar como rodapé.

*nIDCommandControlsFirst*<br/>
[em] O ID de seqüência do primeiro comando.

*nIDCommandControlsLast*<br/>
[em] A seqüência de id do último comando.

### <a name="remarks"></a>Comentários

Há duas maneiras que `CTaskDialog` você pode adicionar a à sua aplicação. A primeira maneira é usar um dos construtores para criar um `CTaskDialog` e exibi-lo usando [CTaskDialog::DoModal](#domodal). A segunda maneira é usar a função estática [CTaskDialog::ShowDialog](#showdialog), que permite exibir um `CTaskDialog` sem criar explicitamente um `CTaskDialog` objeto.

O segundo construtor cria controles de botão de comando usando dados do arquivo de recursos do seu aplicativo. A tabela de strings no arquivo de recursos tem várias strings com IDs de seqüência associados. Este método adiciona um controle de botão de comando para cada entrada válida na tabela de strings entre *nIDCommandControlsFirst* e *nCommandControlsLast*, inclusive. Para esses controles de botão de comando, a string na tabela de strings é a legenda do controle e o ID de seqüência é o ID do controle.

Consulte [CTaskDialog::SetOptions](#setoptions) para uma lista de opções válidas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialogdomodal"></a><a name="domodal"></a>CTaskDialog::DoModal

Mostra `CTaskDialog` o e faz modal.

```
INT_PTR DoModal (HWND hParent = ::GetActiveWindow());
```

### <a name="parameters"></a>Parâmetros

*hParent*<br/>
[em] A janela dos `CTaskDialog`pais para o.

### <a name="return-value"></a>Valor retornado

Um inteiro que corresponde à seleção feita pelo usuário.

### <a name="remarks"></a>Comentários

Exibe esta instância do [CTaskDialog](../../mfc/reference/ctaskdialog-class.md). Em seguida, o aplicativo espera que o usuário feche a caixa de diálogo.

O `CTaskDialog` fecha quando o usuário seleciona um botão comum, `CTaskDialog`um controle de link de comando ou fecha o . O valor de retorno é o identificador que indica como o usuário fechou a caixa de diálogo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialoggetcommonbuttoncount"></a><a name="getcommonbuttoncount"></a>ctaskdialog::GetCommonButtonCount

Recupera o número de botões comuns.

```
int GetCommonButtonCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de botões comuns disponíveis.

### <a name="remarks"></a>Comentários

Os botões comuns são os botões padrão fornecidos ao [CTaskDialog::CTaskDialog](#ctaskdialog). A [Classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md) exibe os botões ao longo da parte inferior da caixa de diálogo.

A lista enumerada de botões é fornecida em CommCtrl.h.

## <a name="ctaskdialoggetcommonbuttonflag"></a><a name="getcommonbuttonflag"></a>ctaskdialog::GetCommonButtonFlag

Converte um botão padrão do Windows para o tipo de botão comum associado à [Classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md).

```
int GetCommonButtonFlag(int nButtonId) const;
```

### <a name="parameters"></a>Parâmetros

*nButtonId*<br/>
[em] O valor padrão do botão do Windows.

### <a name="return-value"></a>Valor retornado

O valor do `CTaskDialog` botão comum correspondente. Se não houver um botão comum correspondente, este método retorna 0.

## <a name="ctaskdialoggetcommonbuttonid"></a><a name="getcommonbuttonid"></a>ctaskDialog::GetCommonButtonId

Converte um dos tipos de botões comuns associados à [Classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md) em um botão padrão do Windows.

```
int GetCommonButtonId(int nFlag);
```

### <a name="parameters"></a>Parâmetros

*nFlag*<br/>
[em] O tipo de botão `CTaskDialog` comum associado à classe.

### <a name="return-value"></a>Valor retornado

O valor do botão padrão correspondente do Windows. Se não houver um botão do Windows correspondente, o método retorna 0.

## <a name="ctaskdialoggetoptions"></a><a name="getoptions"></a>ctaskdialog::getOptions

Retorna as bandeiras `CTaskDialog`de opção para isso .

```
int GetOptions() const;
```

### <a name="return-value"></a>Valor retornado

As bandeiras `CTaskDialog`para o.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre as opções disponíveis na [Classe CTaskDialog,](../../mfc/reference/ctaskdialog-class.md)consulte [CTaskDialog::SetOptions](#setoptions).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialoggetselectedcommandcontrolid"></a><a name="getselectedcommandcontrolid"></a>ctaskdialog::getSelectedCommandControlID

Retorna o controle do botão de comando selecionado.

```
int GetSelectedCommandControlID() const;
```

### <a name="return-value"></a>Valor retornado

O ID do controle do botão de comando selecionado no momento.

### <a name="remarks"></a>Comentários

Você não precisa usar este método para recuperar o ID do botão de comando que o usuário selecionou. Esse ID é retornado por [CTaskDialog::DoModal](#domodal) ou [CTaskDialog::ShowDialog](#showdialog).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#2](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]

## <a name="ctaskdialoggetselectedradiobuttonid"></a><a name="getselectedradiobuttonid"></a>ctaskdialog::getSelectedRadiobuttonID

Retorna o botão de rádio selecionado.

```
int GetSelectedRadioButtonID() const;
```

### <a name="return-value"></a>Valor retornado

O ID do botão de rádio selecionado.

### <a name="remarks"></a>Comentários

Você pode usar este método depois que o usuário fecha a caixa de diálogo para recuperar o botão de rádio selecionado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#3](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]

## <a name="ctaskdialoggetverificationcheckboxstate"></a><a name="getverificationcheckboxstate"></a>ctaskDialog::GetVerificationCheckCheckboxState

Recupera o estado da caixa de verificação.

```
BOOL GetVerificationCheckboxState() const;
```

### <a name="return-value"></a>Valor retornado

VERDADE se a caixa de seleção for verificada, FALSA se não for.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#5](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_4.cpp)]

## <a name="ctaskdialogiscommandcontrolenabled"></a><a name="iscommandcontrolenabled"></a>CTaskDialog::IsCommandControlEnabled

Determina se um controle ou botão de botão de comando está ativado.

```
BOOL IsCommandControlEnabled(int nCommandControlID) const;
```

### <a name="parameters"></a>Parâmetros

*nCommandControlID*<br/>
[em] O ID do comando do botão de comando ou botão para testar.

### <a name="return-value"></a>Valor retornado

VERDADE se o controle estiver ativado, FALSO se não estiver.

### <a name="remarks"></a>Comentários

Você pode usar este método para determinar a disponibilidade de ambos `CTaskDialog` os controles do botão de comando e os botões comuns da Classe*.

Se *nCommandControlID* não for um identificador `CTaskDialog` válido para um botão comum ou um controle de botão de comando, este método lançará uma exceção.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#2](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]

## <a name="ctaskdialogisradiobuttonenabled"></a><a name="isradiobuttonenabled"></a>ctaskDialog::IsRadioButtonEnabled

Determina se um botão de rádio está ativado.

```
BOOL IsRadioButtonEnabled(int nRadioButtonID) const;
```

### <a name="parameters"></a>Parâmetros

*nRadioButtonID*<br/>
[em] O ID do botão de rádio para testar.

### <a name="return-value"></a>Valor retornado

VERDADE se o botão de rádio estiver ativado, FALSO se não estiver.

### <a name="remarks"></a>Comentários

Se *nRadioButtonID* não for um identificador válido para um botão de rádio, este método lançará uma exceção.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#3](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]

## <a name="ctaskdialogissupported"></a><a name="issupported"></a>ctaskdialog::é suportado

Determina se o computador que está executando `CTaskDialog`o aplicativo suporta o .

```
static BOOL IsSupported();
```

### <a name="return-value"></a>Valor retornado

TRUE se o computador `CTaskDialog`suportar o ; FALSO de outra forma.

### <a name="remarks"></a>Comentários

Use esta função para determinar em tempo de execução `CTaskDialog` se o computador que está executando seu aplicativo suporta a classe. Se o computador não `CTaskDialog`suportar o , você deve fornecer outro método de comunicação de informações ao usuário. Seu aplicativo falhará se ele `CTaskDialog` tentar usar um em `CTaskDialog` um computador que não suporta a classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#1](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_5.cpp)]

## <a name="ctaskdialogloadcommandcontrols"></a><a name="loadcommandcontrols"></a>CTaskDiálogo::Comando de cargaControles

Adiciona controles de botão de comando usando dados da tabela de strings.

```
void LoadCommandControls(
    int nIDCommandControlsFirst,
    int nIDCommandControlsLast);
```

### <a name="parameters"></a>Parâmetros

*nIDCommandControlsFirst*<br/>
[em] O ID de seqüência do primeiro comando.

*nIDCommandControlsLast*<br/>
[em] A seqüência de id do último comando.

### <a name="remarks"></a>Comentários

Este método cria controles de botão de comando usando dados do arquivo de recursos do seu aplicativo. A tabela de strings no arquivo de recursos tem várias strings com IDs de seqüência associados. Novos controles de botão de comando adicionados usando este método usam a string para a legenda do controle e o ID de seqüência para o ID do controle. A gama de strings selecionadas é fornecida por *nIDCommandControlsFirst* e *nCommandControlsLast*, inclusive. Se houver uma entrada vazia no intervalo, o método não adicionará um controle de botão de comando para essa entrada.

Por padrão, novos controles do botão de comando estão ativados e não requerem elevação.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#2](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]

## <a name="ctaskdialogloadradiobuttons"></a><a name="loadradiobuttons"></a>ctaskDiálogo::LoadRadioButtons

Adiciona controles de botão de rádio usando dados da tabela de strings.

```
void LoadRadioButtons(
    int nIDRadioButtonsFirst,
    int nIDRadioButtonsLast);
```

### <a name="parameters"></a>Parâmetros

*nIDRadioButtonsFirst*<br/>
[em] A seqüência de id do primeiro botão de rádio.

*nIDRadioButtonsLast*<br/>
[em] A seqüência de id do último botão de rádio.

### <a name="remarks"></a>Comentários

Este método cria botões de rádio usando dados do arquivo de recursos do seu aplicativo. A tabela de strings no arquivo de recursos tem várias strings com IDs de seqüência associados. Novos botões de rádio adicionados usando este método usam a string para a legenda do botão de rádio e o ID da seqüência para o ID do botão de rádio. A gama de strings selecionadas é fornecida por *nIDRadioButtonsFirst* e *nRadioButtonsLast*, inclusive. Se houver uma entrada vazia no intervalo, o método não adicionará um botão de rádio para essa entrada.

Por padrão, novos botões de rádio estão ativados.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#3](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]

## <a name="ctaskdialognavigateto"></a><a name="navigateto"></a>ctaskdialog::navigateto

Transfere o `CTaskDialog`foco para outro .

```
protected:
void NavigateTo(CTaskDialog& oTaskDialog) const;
```

### <a name="parameters"></a>Parâmetros

*oTaskDialog*<br/>
[em] O `CTaskDialog` que recebe o foco.

### <a name="remarks"></a>Comentários

Este método oculta `CTaskDialog` a corrente quando exibe *oTaskDialog*. O *oTaskDialog* é exibido no mesmo `CTaskDialog`local que a corrente .

## <a name="ctaskdialogoncommandcontrolclick"></a><a name="oncommandcontrolclick"></a>ctaskdialog::OnCommandControlClick

A estrutura chama esse método quando o usuário clica em um controle de botão de comando.

```
virtual HRESULT OnCommandControlClick(int nCommandControlID);
```

### <a name="parameters"></a>Parâmetros

*nCommandControlID*<br/>
[em] O ID do controle do botão de comando que o usuário selecionou.

### <a name="return-value"></a>Valor retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Anular este método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogoncreate"></a><a name="oncreate"></a>ctaskdialog::onCreate

A estrutura chama esse método `CTaskDialog`depois de criar o .

```
virtual HRESULT OnCreate();
```

### <a name="return-value"></a>Valor retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Anular este método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogondestroy"></a><a name="ondestroy"></a>ctaskdialog::OnDestroy

A estrutura chama este método imediatamente `CTaskDialog`antes de destruir o .

```
virtual HRESULT OnDestroy();
```

### <a name="return-value"></a>Valor retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Anular este método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogonexpandbuttonclick"></a><a name="onexpandbuttonclick"></a>ctaskdialog::OnExpandButtonClick

A estrutura chama esse método quando o usuário clica no botão de expansão.

```
virtual HRESULT OnExpandButtonClicked(BOOL bExpanded);
```

### <a name="parameters"></a>Parâmetros

*bExpandido*<br/>
[em] Um valor não zero indica que as informações extras são exibidas; 0 indica que as informações extras estão ocultas.

### <a name="return-value"></a>Valor retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Anular este método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogonhelp"></a><a name="onhelp"></a>ctaskdialog::OnHelp

A estrutura chama esse método quando o usuário solicita ajuda.

```
virtual HRESULT OnHelp();
```

### <a name="return-value"></a>Valor retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Anular este método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogonhyperlinkclick"></a><a name="onhyperlinkclick"></a>ctaskdialog::OnHyperlinkClick

A estrutura chama esse método quando o usuário clica em um hiperlink.

```
virtual HRESULT OnHyperlinkClick(const CString& strHref);
```

### <a name="parameters"></a>Parâmetros

*strhref*<br/>
[em] A seqüência que representa o hiperlink.

### <a name="return-value"></a>Valor retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Este método chama [ShellExecute](/windows/win32/api/shellapi/nf-shellapi-shellexecutew) antes de retornar S_OK.

Anular este método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogoninit"></a><a name="oninit"></a>CTaskDialog::OnInit

A estrutura chama esse `CTaskDialog` método quando o é inicializado.

```
virtual HRESULT OnInit();
```

### <a name="return-value"></a>Valor retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Anular este método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogonnavigatepage"></a><a name="onnavigatepage"></a>ctaskdialog::OnNavigatePage

A estrutura chama esse método em resposta ao método [CTaskDialog::NavigateTo.](#navigateto)

```
virtual HRESULT OnNavigatePage();
```

### <a name="return-value"></a>Valor retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Anular este método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogonradiobuttonclick"></a><a name="onradiobuttonclick"></a>ctaskdialog::OnRadioButtonClick

A estrutura chama esse método quando o usuário seleciona um controle de botão de rádio.

```
virtual HRESULT OnRadioButtonClick(int nRadioButtonID);
```

### <a name="parameters"></a>Parâmetros

*nRadioButtonID*<br/>
[em] O ID do controle do botão de rádio que o usuário clicou.

### <a name="return-value"></a>Valor retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Anular este método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogontimer"></a><a name="ontimer"></a>CTaskDialog::OnTimer

A estrutura chama esse método quando o temporizador expira.

```
virtual HRESULT OnTimer(long lTime);
```

### <a name="parameters"></a>Parâmetros

*lTime*<br/>
[em] Tempo em milissegundos desde que o `CTaskDialog` temporizador foi redefinido.

### <a name="return-value"></a>Valor retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Anular este método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogonverificationcheckboxclick"></a><a name="onverificationcheckboxclick"></a>ctaskDialog::OnVerificationCheckCheckboxClick

A estrutura chama esse método quando o usuário clica na caixa de verificação.

```
virtual HRESULT OnVerificationCheckboxClick(BOOL bChecked);
```

### <a name="parameters"></a>Parâmetros

*bChecked*<br/>
[em] TRUE indica que a caixa de verificação de verificação está selecionada; FALSE indica que não é.

### <a name="return-value"></a>Valor retornado

A implementação padrão retorna S_OK.

### <a name="remarks"></a>Comentários

Anular este método em uma classe derivada para implementar o comportamento personalizado.

## <a name="ctaskdialogremoveallcommandcontrols"></a><a name="removeallcommandcontrols"></a>CTaskDialog::RemoveAllCommandControls

Remove todos os controles do `CTaskDialog`botão de comando do .

```
void RemoveAllCommandControls();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#2](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]

## <a name="ctaskdialogremoveallradiobuttons"></a><a name="removeallradiobuttons"></a>ctaskdialog::RemoveAllRadioButtons

Remove todos os botões de `CTaskDialog`rádio do .

```
void RemoveAllRadioButtons();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#3](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]

## <a name="ctaskdialogsetcommandcontroloptions"></a><a name="setcommandcontroloptions"></a>ctaskDiálogo::SetCommandControlOptions

Atualiza um controle de `CTaskDialog`botão de comando no .

```
void SetCommandControlOptions(
    int nCommandControlID,
    BOOL bEnabled,
    BOOL bRequiresElevation = FALSE);
```

### <a name="parameters"></a>Parâmetros

*nCommandControlID*<br/>
[em] O ID do controle de comando para atualizar.

*bEnabled*<br/>
[em] Um parâmetro booleano que indica se o controle do botão de comando especificado está ativado ou desativado.

*bRequiresElevation*<br/>
[em] Um parâmetro booleano que indica se o controle do botão de comando especificado requer elevação.

### <a name="remarks"></a>Comentários

Use este método para alterar se um controle de botão de comando `CTaskDialog` está ativado ou requer elevação depois de ter sido adicionado à classe.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#2](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]

## <a name="ctaskdialogsetcommonbuttonoptions"></a><a name="setcommonbuttonoptions"></a>ctaskDiálogo::SetSetPáginaPáginadebotões de página

Atualiza um subconjunto de botões comuns a serem ativados e que requerem a elevação do UAC.

```
void SetCommonButtonOptions(
    int nDisabledButtonMask,
    int nElevationButtonMask = 0);
```

### <a name="parameters"></a>Parâmetros

*nDisabledButtonMask*<br/>
[em] Uma máscara para os botões comuns desabilitar.

*nElevationButtonMask*<br/>
[em] Uma máscara para os botões comuns que requerem elevação.

### <a name="remarks"></a>Comentários

Você pode definir os botões comuns disponíveis em uma instância da [Classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md) usando o construtor [CTaskDialog::CTaskDialog](#ctaskdialog) e o método [CTaskDialog::SetCommonButtons](#setcommonbuttons). `CTaskDialog::SetCommonButtonOptions`não suporta a adição de novos botões comuns.

Se você usar este método para desativar ou elevar um `CTaskDialog`botão comum que não está disponível para isso, este método lança uma exceção usando a macro [ENSURE.](diagnostic-services.md#ensure)

Este método habilita qualquer botão `CTaskDialog` que esteja disponível para o mas não está no *nDisabledButtonMask*, mesmo que tenha sido desativado anteriormente. Este método trata a elevação de maneira semelhante: registra botões comuns como não exigindo elevação se o botão comum estiver disponível, mas não incluído em *nElevationButtonMask*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#6](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_6.cpp)]

## <a name="ctaskdialogsetcommonbuttons"></a><a name="setcommonbuttons"></a>cTaskDiálogo::SetCommonButtons

Adiciona botões comuns `CTaskDialog`ao .

```
void SetCommonButtons(
    int nButtonMask,
    int nDisabledButtonMask = 0,
    int nElevationButtonMask = 0);
```

### <a name="parameters"></a>Parâmetros

*nButtonMask*<br/>
[em] Uma máscara dos botões para `CTaskDialog`adicionar ao .

*nDisabledButtonMask*<br/>
[em] Uma máscara dos botões para desativar.

*nElevationButtonMask*<br/>
[em] Uma máscara dos botões que requerem elevação.

### <a name="remarks"></a>Comentários

Não é possível chamar esse método depois `CTaskDialog` que a janela de exibição para esta instância da classe for criada. Se você fizer isso, este método lança uma exceção.

Os botões indicados por *nButtonMask* anulam quaisquer botões comuns adicionados anteriormente ao `CTaskDialog`. Apenas os botões indicados em *nButtonMask* estão disponíveis.

Se *nDisabledButtonMask* ou *nElevationButtonMask* contiverem um botão que não está em *nButtonMask,* este método lança uma exceção usando a macro [ENSURE.](diagnostic-services.md#ensure)

Por padrão, todos os botões comuns estão ativados e não requerem elevação.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#6](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_6.cpp)]

## <a name="ctaskdialogsetcontent"></a><a name="setcontent"></a>ctaskDialog::SetContent

Atualiza o conteúdo `CTaskDialog`do .

```
void SetContent(const CString& strContent);
```

### <a name="parameters"></a>Parâmetros

*strContent*<br/>
[em] A seqüência a ser exibida ao usuário.

### <a name="remarks"></a>Comentários

O conteúdo `CTaskDialog` da classe é o texto exibido para o usuário na seção principal da caixa de diálogo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialogsetdefaultcommandcontrol"></a><a name="setdefaultcommandcontrol"></a>ctask '''''''''''''''''''''''''''

Especifica o controle padrão do botão de comando.

```
void SetDefaultCommandControl(int nCommandControlID);
```

### <a name="parameters"></a>Parâmetros

*nCommandControlID*<br/>
[em] O ID do controle do botão de comando é o padrão.

### <a name="remarks"></a>Comentários

O controle padrão do botão de comando `CTaskDialog` é o controle selecionado quando o é exibido pela primeira vez para o usuário.

Este método lança uma exceção se não encontrar o controle do botão de comando especificado por *nCommandControlID*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#2](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_1.cpp)]

## <a name="ctaskdialogsetdefaultradiobutton"></a><a name="setdefaultradiobutton"></a>ctaskDiálogo::SetDefaultRadiobutton

Especifica o botão de rádio padrão.

```
void SetDefaultRadioButton(int nRadioButtonID);
```

### <a name="parameters"></a>Parâmetros

*nRadioButtonID*<br/>
[em] O ID do botão de rádio para ser o padrão.

### <a name="remarks"></a>Comentários

O botão de rádio padrão é `CTaskDialog` o botão selecionado quando é exibido pela primeira vez ao usuário.

Este método lança uma exceção se não encontrar o botão de rádio especificado por *nRadioButtonID*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#3](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]

## <a name="ctaskdialogsetdialogwidth"></a><a name="setdialogwidth"></a>ctaskDialog::Set'SOdia-de-armadepara-dia

Ajusta a `CTaskDialog`largura do .

```
void SetDialogWidth(int nWidth = 0);
```

### <a name="parameters"></a>Parâmetros

*Nwidth*<br/>
[em] A largura da caixa de diálogo, em pixels.

### <a name="remarks"></a>Comentários

O parâmetro *nLargura* deve ser maior ou igual a 0. Caso contrário, este método lança uma exceção.

Se *nLargura* estiver definida como 0, este método definirá a caixa de diálogo para o tamanho padrão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialogsetexpansionarea"></a><a name="setexpansionarea"></a>ctaskDialog::SetExpansionarea

Atualiza a área de `CTaskDialog`expansão do .

```
void SetExpansionArea(
    const CString& strExpandedInformation,
    const CString& strCollapsedLabel = _T(""),
    const CString& strExpandedLabel = _T(""));
```

### <a name="parameters"></a>Parâmetros

*strExpandedInformation*<br/>
[em] A seqüência que o `CTaskDialog` exibe no corpo principal da caixa de diálogo quando o usuário clica no botão de expansão.

*strCollapsedLabel*<br/>
[em] A seqüência que o `CTaskDialog` displays é exibido ao lado do botão de expansão quando a área expandida é colapsada.

*strExpandedLabel*<br/>
[em] A seqüência que o `CTaskDialog` display é exibido ao lado do botão de expansão quando a área expandida é exibida.

### <a name="remarks"></a>Comentários

A área de `CTaskDialog` expansão da classe permite que você forneça informações adicionais ao usuário. A área de expansão está `CTaskDialog`na parte principal do , localizado imediatamente abaixo da seqüência de título e conteúdo.

Quando `CTaskDialog` o é exibido pela primeira vez, ele `strCollapsedLabel` não mostra as informações expandidas e coloca ao lado do botão de expansão. Quando o usuário clica no `CTaskDialog` botão de expansão, o exibe *strExpandedInformation* e altera o rótulo para *strExpandedLabel*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialogsetfootericon"></a><a name="setfootericon"></a>cTaskDialog::SetFooterIcon

Atualiza o ícone de `CTaskDialog`rodapé do .

```
void SetFooterIcon(HICON hFooterIcon);
void SetFooterIcon(LPCWSTR lpszFooterIcon);
```

### <a name="parameters"></a>Parâmetros

*hFooterIcon*<br/>
[em] O novo ícone `CTaskDialog`para o .

*lpszFooterIcon*<br/>
[em] O novo ícone `CTaskDialog`para o .

### <a name="remarks"></a>Comentários

O ícone do rodapé é exibido na parte inferior da [Classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md). Pode ter texto de rodapé associado. Você pode alterar o texto do rodapé com [CTaskDialog::SetFooterText](#setfootertext).

Este método lança uma [ENSURE](diagnostic-services.md#ensure) exceção `CTaskDialog` com a macro ENSURE se o for exibido ou o parâmetro de entrada for NULO.

Um `CTaskDialog` só pode `HICON` `LPCWSTR` aceitar um ou como um ícone de rodapé. Isso é configurado definindo a opção TDF_USE_HICON_FOOTER no construtor ou [CTaskDialog::SetOptions](#setoptions). Por padrão, `CTaskDialog` o é `LPCWSTR` configurado para usar como o tipo de entrada para o ícone do rodapé. Este método gera uma exceção se você tentar definir o ícone usando o tipo inapropriado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialogsetfootertext"></a><a name="setfootertext"></a>CTaskDialog::SetFooterText

Atualiza o texto no rodapé `CTaskDialog`do .

```
void SetFooterText(const CString& strFooterText);
```

### <a name="parameters"></a>Parâmetros

*strFooterText*<br/>
[em] O novo texto para o rodapé.

### <a name="remarks"></a>Comentários

O ícone do rodapé aparece ao lado do `CTaskDialog`texto do rodapé na parte inferior do . Você pode alterar o ícone de rodapé com [CTaskDialog::SetFooterIcon](#setfootericon).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialogsetmainicon"></a><a name="setmainicon"></a>ctaskDialog::SetmainIcon

Atualiza o ícone principal `CTaskDialog`do .

```
void SetMainIcon(HICON hMainIcon);
void SetMainIcon(LPCWSTR lpszMainIcon);
```

### <a name="parameters"></a>Parâmetros

*hMainIcon*<br/>
[em] O novo ícone.

*lpszMainIcon*<br/>
[em] O novo ícone.

### <a name="remarks"></a>Comentários

Este método lança uma [ENSURE](diagnostic-services.md#ensure) exceção `CTaskDialog` com a macro ENSURE se o for exibido ou o parâmetro de entrada for NULO.

Um `CTaskDialog` só pode `HICON` `LPCWSTR` aceitar um ou como um ícone principal. Você pode configurá-lo definindo a opção TDF_USE_HICON_MAIN no construtor ou no método [CTaskDialog::SetOptions.](#setoptions) Por padrão, `CTaskDialog` o é `LPCWSTR` configurado para usar como o tipo de entrada para o ícone principal. Este método gera uma exceção se você tentar definir o ícone usando o tipo inapropriado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialogsetmaininstruction"></a><a name="setmaininstruction"></a>ctaskDialog::SetMainInstruction

Atualiza a instrução `CTaskDialog`principal do .

```
void SetMainInstruction(const CString& strInstructions);
```

### <a name="parameters"></a>Parâmetros

*strInstructions*<br/>
[em] A nova instrução principal.

### <a name="remarks"></a>Comentários

A principal instrução da classe é o `CTaskDialog` texto exibido para o usuário em uma fonte em negrito grande. Ele está localizado na caixa de diálogo abaixo da barra de título.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialogsetoptions"></a><a name="setoptions"></a>ctaskDialog::Definições de configuração

Configura as opções `CTaskDialog`para o .

```
void SetOptions(int nOptionFlag);
```

### <a name="parameters"></a>Parâmetros

*nOptionFlag*<br/>
[em] O conjunto de bandeiras `CTaskDialog`para usar para o .

### <a name="remarks"></a>Comentários

Este método limpa todas as `CTaskDialog`opções atuais para o . Para preservar as opções atuais, você deve recuperá-las primeiro com [CTaskDialog::GetOptions](#getoptions) e combiná-las com as opções que você deseja definir.

A tabela a seguir lista todas as opções válidas.

|||
|-|-|
|TDF_ENABLE_HYPERLINKS|Habilita hiperlinks `CTaskDialog`no .|
|TDF_USE_HICON_MAIN|Configura o `CTaskDialog` a `HICON` ser usado para o ícone principal. A alternativa é `LPCWSTR`usar um .|
|TDF_USE_HICON_FOOTER|Configura o `CTaskDialog` para `HICON` usar um para o ícone de rodapé. A alternativa é `LPCWSTR`usar um .|
|TDF_ALLOW_DIALOG_CANCELLATION|Permite que o `CTaskDialog` usuário feche o usando o teclado ou usando o ícone no canto superior direito da caixa de diálogo, mesmo que o botão **Cancelar** não esteja ativado. Se este sinalizador não estiver definido e o botão **Cancelar** não estiver ativado, o usuário não poderá fechar a caixa de diálogo usando Alt+F4, a tecla Escape ou o botão de fechamento da barra de título.|
|TDF_USE_COMMAND_LINKS|Configura os `CTaskDialog` controles do botão de comando para usar.|
|TDF_USE_COMMAND_LINKS_NO_ICON|Configura os `CTaskDialog` controles do botão de comando para usar sem exibir um ícone ao lado do controle. TDF_USE_COMMAND_LINKS substitui TDF_USE_COMMAND_LINKS_NO_ICON.|
|TDF_EXPAND_FOOTER_AREA|Indica que a área de expansão está atualmente expandida.|
|TDF_EXPANDED_BY_DEFAULT|Determina se a área de expansão é expandida por padrão.|
|TDF_VERIFICATION_FLAG_CHECKED|Indica que a caixa de verificação está selecionada no momento.|
|TDF_SHOW_PROGRESS_BAR|Configura o `CTaskDialog` para exibir uma barra de progresso.|
|TDF_SHOW_MARQUEE_PROGRESS_BAR|Configura a barra de progresso como uma barra de progresso da marquise. Se você habilitar essa opção, você deve definir TDF_SHOW_PROGRESS_BAR para ter o comportamento esperado.|
|TDF_CALLBACK_TIMER|Indica que `CTaskDialog` o intervalo de retorno de chamada está definido para aproximadamente 200 milissegundos.|
|TDF_POSITION_RELATIVE_TO_WINDOW|Configura o `CTaskDialog` a ser centrado em relação à janela pai. Se esta bandeira não estiver `CTaskDialog` habilitada, a é centrada em relação ao monitor.|
|TDF_RTL_LAYOUT|Configura o `CTaskDialog` layout de leitura da direita para a esquerda.|
|TDF_NO_DEFAULT_RADIO_BUTTON|Indica que nenhum botão de `CTaskDialog` rádio é selecionado quando o aparece.|
|TDF_CAN_BE_MINIMIZED|Permite que o `CTaskDialog`usuário minimize o . Para apoiar essa `CTaskDialog` opção, o não pode ser modal. O MFC não suporta essa opção porque o `CTaskDialog`MFC não suporta uma modeless .|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialogsetprogressbarmarquee"></a><a name="setprogressbarmarquee"></a>ctaskDialog::setProgressbarMarquee

Configura uma barra de `CTaskDialog` letreiro para o e adiciona-a à caixa de diálogo.

```
void SetProgressBarMarquee(
    BOOL bEnabled = TRUE,
    int nMarqueeSpeed = 0);
```

### <a name="parameters"></a>Parâmetros

*bEnabled*<br/>
[em] TRUE para habilitar a barra de letreiro; FALSO para desativar a barra de `CTaskDialog`letreiro e removê-la do .

*nMarqueeSpeed*<br/>
[em] Um inteiro que indica a velocidade da barra de letreiro.

### <a name="remarks"></a>Comentários

A barra de letreiro `CTaskDialog` aparece abaixo do texto principal da classe.

Use *nMarqueeSpeed* para definir a velocidade da barra de letreiro; valores maiores indicam uma velocidade mais lenta. Um valor de 0 para *nMarqueeSpeed* faz com que a barra de letreiro se mova na velocidade padrão do Windows.

Este método lança uma exceção com a macro [ENSURE](diagnostic-services.md#ensure) se *nMarqueeSpeed* for menor que 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#4](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_7.cpp)]

## <a name="ctaskdialogsetprogressbarposition"></a><a name="setprogressbarposition"></a>ctaskDialog::setProgressbarPosition

Ajusta a posição da barra de progresso.

```
void SetProgressBarPosition(int nProgressPos);
```

### <a name="parameters"></a>Parâmetros

*nProgressPos*<br/>
[em] A posição para a barra de progresso.

### <a name="remarks"></a>Comentários

Este método lança uma exceção com a macro [ENSURE](diagnostic-services.md#ensure) se *nProgressPos* não estiver na faixa de barras de progresso. Você pode alterar o intervalo da barra de progresso com [CTaskDialog::SetProgressBarRange](#setprogressbarrange).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#4](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_7.cpp)]

## <a name="ctaskdialogsetprogressbarrange"></a><a name="setprogressbarrange"></a>ctaskDialog::SetProgressBarrange

Ajusta o alcance da barra de progresso.

```
void SetProgressBarRange(
    int nRangeMin,
    int nRangeMax);
```

### <a name="parameters"></a>Parâmetros

*nRangeMin*<br/>
[em] O limite inferior da barra de progresso.

*nRangeMax*<br/>
[em] O limite superior da barra de progresso.

### <a name="remarks"></a>Comentários

A posição da barra de progresso é relativa a *nRangeMin* e *nRangeMax*. Por exemplo, se *nRangeMin* é 50 e *nRangeMax* é 100, uma posição de 75 está no meio do caminho através da barra de progresso. Use [CTaskDialog::SetProgressBarPosição](#setprogressbarposition) para definir a posição da barra de progresso.

Para exibir a barra de progresso, a opção TDF_SHOW_PROGRESS_BAR deve ser ativada e TDF_SHOW_MARQUEE_PROGRESS_BAR não deve ser habilitada. Este método define automaticamente TDF_SHOW_PROGRESS_BAR e limpa TDF_SHOW_MARQUEE_PROGRESS_BAR. Use [CTaskDialog::SetOptions](#setoptions) para alterar manualmente as opções para esta instância da [Classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md).

Este método lança uma exceção com a macro [ENSURE](diagnostic-services.md#ensure) se *nRangeMin* não for menor que *nRangeMax*. Este método também lança `CTaskDialog` uma exceção se o já estiver exibido e tiver uma barra de progresso de letreiro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#4](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_7.cpp)]

## <a name="ctaskdialogsetprogressbarstate"></a><a name="setprogressbarstate"></a>ctaskDialog::setProgressbarstate

Define o estado da barra de `CTaskDialog`progresso e exibe-a no .

```
void SetProgressBarState(int nState = PBST_NORMAL);
```

### <a name="parameters"></a>Parâmetros

*Nstate*<br/>
[em] O estado da barra de progresso. Consulte a seção Observações para ver os possíveis valores.

### <a name="remarks"></a>Comentários

Este método lança uma [ENSURE](diagnostic-services.md#ensure) exceção `CTaskDialog` com a macro ENSURE se o já estiver exibido e tiver uma barra de progresso da marquise.

A tabela a seguir lista os valores possíveis para *nState*. Em todos esses casos, a barra de progresso será preenchida com a cor regular até atingir a posição de parada designada. Nesse ponto, mudará de cor com base no estado.

|||
|-|-|
|PBST_NORMAL|Após o preenchimento da `CTaskDialog` barra de progresso, o não altera a cor da barra. Por padrão, a cor regular é verde.|
|PBST_ERROR|Após o preenchimento da `CTaskDialog` barra de progresso, a cor da barra para a cor do erro. Por padrão, isso é vermelho.|
|PBST_PAUSED|Após o preenchimento da `CTaskDialog` barra de progresso, a cor da barra muda para a cor pausada. Por padrão, isso é amarelo.|

Você pode definir onde a barra de progresso pára com [CTaskDialog:SetProgressBarPosition](#setprogressbarposition).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#4](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_7.cpp)]

## <a name="ctaskdialogsetradiobuttonoptions"></a><a name="setradiobuttonoptions"></a>ctaskDialog::SetRadioButtonOptions

Ativa ou desativa um botão de rádio.

```
void SetRadioButtonOptions(
    int nRadioButtonID,
    BOOL bEnabled);
```

### <a name="parameters"></a>Parâmetros

*nRadioButtonID*<br/>
[em] A id do controle do botão de rádio.

*bEnabled*<br/>
[em] TRUE para ativar o botão de rádio; FALSO para desativar o botão de rádio.

### <a name="remarks"></a>Comentários

Este método lança uma exceção com a macro [ENSURE](diagnostic-services.md#ensure) se *nRadioButtonID* não for um ID válido para um botão de rádio.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#3](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_2.cpp)]

## <a name="ctaskdialogsetverificationcheckbox"></a><a name="setverificationcheckbox"></a>ctaskDiálogo::SetVerificationcheckbox

Define o estado verificado da caixa de seleção de verificação.

```
void SetVerificationCheckbox(BOOL bChecked);
```

### <a name="parameters"></a>Parâmetros

*bChecked*<br/>
[em] TRUE para ter a caixa `CTaskDialog` de verificação selecionada quando for exibida; FALSO para que a caixa de `CTaskDialog` verificação não seja selecionada quando for exibida.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#5](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_4.cpp)]

## <a name="ctaskdialogsetverificationcheckboxtext"></a><a name="setverificationcheckboxtext"></a>CTaskDialog::SetVerificationCheckboxText

Define o texto exibido à direita da caixa de seleção de verificação.

```
void SetVerificationCheckboxText(CString& strVerificationText);
```

### <a name="parameters"></a>Parâmetros

*strVerificationText*<br/>
[em] O texto que este método exibe ao lado da caixa de verificação.

### <a name="remarks"></a>Comentários

Este método lança uma [ENSURE](diagnostic-services.md#ensure) exceção com a `CTaskDialog` macro ENSURE se esta instância da classe já estiver exibida.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#5](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_4.cpp)]

## <a name="ctaskdialogsetwindowtitle"></a><a name="setwindowtitle"></a>ctaskDialog::SetWindowTitle

Define o título `CTaskDialog`do .

```
void SetWindowTitle(CString& strWindowTitle);
```

### <a name="parameters"></a>Parâmetros

*strWindowTitle*<br/>
[em] O novo título `CTaskDialog`para o .

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#7](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_3.cpp)]

## <a name="ctaskdialogshowdialog"></a><a name="showdialog"></a>ctaskdialog::showDialog

Cria e `CTaskDialog`exibe um .

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
[em] A seqüência a ser `CTaskDialog`usada para o conteúdo do .

*strMainInstruction*<br/>
[em] A principal instrução do `CTaskDialog`.

*strTitle*<br/>
[em] O título `CTaskDialog`do.

*nIDCommandControlsFirst*<br/>
[em] O ID de seqüência do primeiro comando.

*nIDCommandControlsLast*<br/>
[em] A seqüência de id do último comando.

*nBotões comuns*<br/>
[em] Uma máscara dos botões para `CTaskDialog`adicionar ao .

*nTask'SOptions de diálogo*<br/>
[em] O conjunto de opções `CTaskDialog`para usar para o .

*strFooter*<br/>
[em] A corda para usar como rodapé.

### <a name="return-value"></a>Valor retornado

Um inteiro que corresponde à seleção feita pelo usuário.

### <a name="remarks"></a>Comentários

Este método estático permite que `CTaskDialog` você crie uma `CTaskDialog` instância da classe sem criar explicitamente um objeto em seu código. Como não `CTaskDialog` há objeto, você não pode `CTaskDialog` chamar nenhum outro método `CTaskDialog` do se você usar este método para mostrar um ao usuário.

Este método cria controles de botão de comando usando dados do arquivo de recursos do seu aplicativo. A tabela de strings no arquivo de recursos tem várias strings com IDs de seqüência associados. Este método adiciona um controle de botão de comando para cada entrada válida na tabela de strings entre *nIDCommandControlsFirst* e *nCommandControlsLast*, inclusive. Para esses controles de botão de comando, a string na tabela de strings é a legenda do controle e o ID de seqüência é o ID do controle.

Consulte [CTaskDialog::SetOptions](#setoptions) para uma lista de opções válidas.

O `CTaskDialog` fecha quando o usuário seleciona um botão comum, `CTaskDialog`um controle de link de comando ou fecha o . O valor de retorno é o identificador que indica como o usuário fechou a caixa de diálogo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CTaskDialog#1](../../mfc/reference/codesnippet/cpp/ctaskdialog-class_5.cpp)]

## <a name="ctaskdialogtaskdialogcallback"></a><a name="taskdialogcallback"></a>CTaskDialog::TaskDialogCallback

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

### <a name="parameters"></a>Parâmetros

*Hwnd*<br/>
[em] Uma alça `m_hWnd` para a `CTaskDialog`estrutura para o .

*uNotificação*<br/>
[em] O código de notificação que especifica a mensagem gerada.

*wParam*<br/>
[em] Mais informações sobre a mensagem.

*lParam*<br/>
[em] Mais informações sobre a mensagem.

*dwRefData*<br/>
[em] Um ponteiro `CTaskDialog` para o objeto ao que a mensagem de retorno de chamada se aplica.

### <a name="return-value"></a>Valor retornado

Depende do código de notificação específico. Para obter mais informações, consulte a seção Comentários.

### <a name="remarks"></a>Comentários

A implementação `TaskDialogCallback` padrão lida com a mensagem específica e, em seguida, chama o método apropriado on da [Classe CTaskDialog](../../mfc/reference/ctaskdialog-class.md). Por exemplo, em resposta à `TaskDialogCallback` mensagem TDN_BUTTON_CLICKED, chama [CTaskDialog::OnCommandControlClick](#oncommandcontrolclick).

Os valores para *wParam* e *lParam* dependem da mensagem gerada específica. É possível que ambos os valores estejam vazios. A tabela a seguir lista as notificações padrão suportadas e quais os valores de *wParam* e *lParam.* Se você substituir este método em uma classe derivada, você deve implementar o código de retorno de chamada para cada mensagem na tabela a seguir.

|Mensagem de notificação|*wParam* Valor|*IParam* Valor|
|--------------------------|--------------------|--------------------|
|TDN_CREATED|Não usado.|Não usado.|
|TDN_NAVIGATED|Não usado.|Não usado.|
|TDN_BUTTON_CLICKED|O iD de controle do botão de comando.|Não usado.|
|TDN_HYPERLINK_CLICKED|Não usado.|Uma estrutura [LPCWSTR](/windows/win32/WinProg/windows-data-types) que contém o link.|
|TDN_TIMER|Tempo em milissegundos desde que o `CTaskDialog` temporizador foi redefinido.|Não usado.|
|TDN_DESTROYED|Não usado.|Não usado.|
|TDN_RADIO_BUTTON_CLICKED|A id do botão de rádio.|Não usado.|
|TDN_DIALOG_CONSTRUCTED|Não usado.|Não usado.|
|TDN_VERIFICATION_CLICKED|1 se a caixa de seleção for verificada, 0 se não for.|Não usado.|
|TDN_HELP|Não usado.|Não usado.|
|TDN_EXPANDO_BUTTON_CLICKED|0 se a área de expansão for colapsada; não zero se o texto de expansão for exibido.|Não usado.|

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Instruções passo a passo: adicionando um CTaskDialog a um aplicativo](../../mfc/walkthrough-adding-a-ctaskdialog-to-an-application.md)
