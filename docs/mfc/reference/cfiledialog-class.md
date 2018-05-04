---
title: Classe CFileDialog | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- CFileDialog
- AFXDLGS/CFileDialog
- AFXDLGS/CFileDialog::CFileDialog
- AFXDLGS/CFileDialog::AddCheckButton
- AFXDLGS/CFileDialog::AddComboBox
- AFXDLGS/CFileDialog::AddControlItem
- AFXDLGS/CFileDialog::AddEditBox
- AFXDLGS/CFileDialog::AddMenu
- AFXDLGS/CFileDialog::AddPlace
- AFXDLGS/CFileDialog::AddPushButton
- AFXDLGS/CFileDialog::AddRadioButtonList
- AFXDLGS/CFileDialog::AddSeparator
- AFXDLGS/CFileDialog::AddText
- AFXDLGS/CFileDialog::ApplyOFNToShellDialog
- AFXDLGS/CFileDialog::DoModal
- AFXDLGS/CFileDialog::EnableOpenDropDown
- AFXDLGS/CFileDialog::EndVisualGroup
- AFXDLGS/CFileDialog::GetCheckButtonState
- AFXDLGS/CFileDialog::GetControlItemState
- AFXDLGS/CFileDialog::GetControlState
- AFXDLGS/CFileDialog::GetEditBoxText
- AFXDLGS/CFileDialog::GetFileExt
- AFXDLGS/CFileDialog::GetFileName
- AFXDLGS/CFileDialog::GetFileTitle
- AFXDLGS/CFileDialog::GetFolderPath
- AFXDLGS/CFileDialog::GetIFileDialogCustomize
- AFXDLGS/CFileDialog::GetIFileOpenDialog
- AFXDLGS/CFileDialog::GetIFileSaveDialog
- AFXDLGS/CFileDialog::GetNextPathName
- AFXDLGS/CFileDialog::GetOFN
- AFXDLGS/CFileDialog::GetPathName
- AFXDLGS/CFileDialog::GetReadOnlyPref
- AFXDLGS/CFileDialog::GetResult
- AFXDLGS/CFileDialog::GetResults
- AFXDLGS/CFileDialog::GetSelectedControlItem
- AFXDLGS/CFileDialog::GetStartPosition
- AFXDLGS/CFileDialog::HideControl
- AFXDLGS/CFileDialog::IsPickFoldersMode
- AFXDLGS/CFileDialog::MakeProminent
- AFXDLGS/CFileDialog::RemoveControlItem
- AFXDLGS/CFileDialog::SetCheckButtonState
- AFXDLGS/CFileDialog::SetControlItemState
- AFXDLGS/CFileDialog::SetControlItemText
- AFXDLGS/CFileDialog::SetControlLabel
- AFXDLGS/CFileDialog::SetControlState
- AFXDLGS/CFileDialog::SetControlText
- AFXDLGS/CFileDialog::SetDefExt
- AFXDLGS/CFileDialog::SetEditBoxText
- AFXDLGS/CFileDialog::SetProperties
- AFXDLGS/CFileDialog::SetSelectedControlItem
- AFXDLGS/CFileDialog::SetTemplate
- AFXDLGS/CFileDialog::StartVisualGroup
- AFXDLGS/CFileDialog::UpdateOFNFromShellDialog
- AFXDLGS/CFileDialog::OnButtonClicked
- AFXDLGS/CFileDialog::OnCheckButtonToggled
- AFXDLGS/CFileDialog::OnControlActivating
- AFXDLGS/CFileDialog::OnFileNameChange
- AFXDLGS/CFileDialog::OnFileNameOK
- AFXDLGS/CFileDialog::OnFolderChange
- AFXDLGS/CFileDialog::OnInitDone
- AFXDLGS/CFileDialog::OnItemSelected
- AFXDLGS/CFileDialog::OnLBSelChangedNotify
- AFXDLGS/CFileDialog::OnShareViolation
- AFXDLGS/CFileDialog::OnTypeChange
- AFXDLGS/CFileDialog::m_ofn
dev_langs:
- C++
helpviewer_keywords:
- CFileDialog [MFC], CFileDialog
- CFileDialog [MFC], AddCheckButton
- CFileDialog [MFC], AddComboBox
- CFileDialog [MFC], AddControlItem
- CFileDialog [MFC], AddEditBox
- CFileDialog [MFC], AddMenu
- CFileDialog [MFC], AddPlace
- CFileDialog [MFC], AddPushButton
- CFileDialog [MFC], AddRadioButtonList
- CFileDialog [MFC], AddSeparator
- CFileDialog [MFC], AddText
- CFileDialog [MFC], ApplyOFNToShellDialog
- CFileDialog [MFC], DoModal
- CFileDialog [MFC], EnableOpenDropDown
- CFileDialog [MFC], EndVisualGroup
- CFileDialog [MFC], GetCheckButtonState
- CFileDialog [MFC], GetControlItemState
- CFileDialog [MFC], GetControlState
- CFileDialog [MFC], GetEditBoxText
- CFileDialog [MFC], GetFileExt
- CFileDialog [MFC], GetFileName
- CFileDialog [MFC], GetFileTitle
- CFileDialog [MFC], GetFolderPath
- CFileDialog [MFC], GetIFileDialogCustomize
- CFileDialog [MFC], GetIFileOpenDialog
- CFileDialog [MFC], GetIFileSaveDialog
- CFileDialog [MFC], GetNextPathName
- CFileDialog [MFC], GetOFN
- CFileDialog [MFC], GetPathName
- CFileDialog [MFC], GetReadOnlyPref
- CFileDialog [MFC], GetResult
- CFileDialog [MFC], GetResults
- CFileDialog [MFC], GetSelectedControlItem
- CFileDialog [MFC], GetStartPosition
- CFileDialog [MFC], HideControl
- CFileDialog [MFC], IsPickFoldersMode
- CFileDialog [MFC], MakeProminent
- CFileDialog [MFC], RemoveControlItem
- CFileDialog [MFC], SetCheckButtonState
- CFileDialog [MFC], SetControlItemState
- CFileDialog [MFC], SetControlItemText
- CFileDialog [MFC], SetControlLabel
- CFileDialog [MFC], SetControlState
- CFileDialog [MFC], SetControlText
- CFileDialog [MFC], SetDefExt
- CFileDialog [MFC], SetEditBoxText
- CFileDialog [MFC], SetProperties
- CFileDialog [MFC], SetSelectedControlItem
- CFileDialog [MFC], SetTemplate
- CFileDialog [MFC], StartVisualGroup
- CFileDialog [MFC], UpdateOFNFromShellDialog
- CFileDialog [MFC], OnButtonClicked
- CFileDialog [MFC], OnCheckButtonToggled
- CFileDialog [MFC], OnControlActivating
- CFileDialog [MFC], OnFileNameChange
- CFileDialog [MFC], OnFileNameOK
- CFileDialog [MFC], OnFolderChange
- CFileDialog [MFC], OnInitDone
- CFileDialog [MFC], OnItemSelected
- CFileDialog [MFC], OnLBSelChangedNotify
- CFileDialog [MFC], OnShareViolation
- CFileDialog [MFC], OnTypeChange
- CFileDialog [MFC], m_ofn
ms.assetid: fda4fd3c-08b8-4ce0-8e9d-7bab23f8c6c0
caps.latest.revision: 47
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 68c07bd6a172c704003ac2e4d83ef27fc1efc64a
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="cfiledialog-class"></a>Classe CFileDialog
Encapsula a caixa de diálogo comum que é usada para abrir o arquivo ou salvar as operações de arquivo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CFileDialog : public CCommonDialog  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFileDialog::CFileDialog](#cfiledialog)|Constrói um objeto `CFileDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFileDialog::AddCheckButton](#addcheckbutton)|Adiciona um botão de seleção para a caixa de diálogo.|  
|[CFileDialog::AddComboBox](#addcombobox)|Adiciona uma caixa de combinação para a caixa de diálogo.|  
|[CFileDialog::AddControlItem](#addcontrolitem)|Adiciona um item a um controle de contêiner na caixa de diálogo.|  
|[CFileDialog::AddEditBox](#addeditbox)|Adiciona uma caixa de edição na caixa de diálogo.|  
|[CFileDialog::AddMenu](#addmenu)|Adiciona um menu para a caixa de diálogo.|  
|[CFileDialog::AddPlace](#addplace)|Sobrecarregado. Adiciona que uma pasta à lista de coloca disponível para o usuário abrir ou salvar os itens.|  
|[CFileDialog::AddPushButton](#addpushbutton)|Adiciona um botão à caixa de diálogo.|  
|[CFileDialog::AddRadioButtonList](#addradiobuttonlist)|Adiciona um grupo de botão (também conhecido como o botão de opção) de opção na caixa de diálogo.|  
|[CFileDialog::AddSeparator](#addseparator)|Adiciona um separador para a caixa de diálogo.|  
|[CFileDialog::AddText](#addtext)|Adiciona o conteúdo de texto para a caixa de diálogo.|  
|[CFileDialog::ApplyOFNToShellDialog](#applyofntoshelldialog)|Atualiza o estado do `CFileDialog` para corresponder os parâmetros e os sinalizadores armazenados no `m_ofn` variável de membro.|  
|[CFileDialog::DoModal](#domodal)|Exibe a caixa de diálogo e permite que o usuário faça uma seleção.|  
|[CFileDialog::EnableOpenDropDown](#enableopendropdown)|Habilita uma lista suspensa no **abrir** ou **salvar** botão na caixa de diálogo.|  
|[CFileDialog::EndVisualGroup](#endvisualgroup)|Interrompe a adição de elementos a um grupo de visual na caixa de diálogo.|  
|[CFileDialog::GetCheckButtonState](#getcheckbuttonstate)|Obtém o estado atual de um botão de seleção (caixa de seleção) na caixa de diálogo.|  
|[CFileDialog::GetControlItemState](#getcontrolitemstate)|Obtém o estado atual de um item em um controle de contêiner encontrado na caixa de diálogo.|  
|[CFileDialog::GetControlState](#getcontrolstate)|Obtém a visibilidade atual e estados de um dado controle habilitados.|  
|[CFileDialog::GetEditBoxText](#geteditboxtext)|Obtém o texto atual em um controle de caixa de edição.|  
|[CFileDialog::GetFileExt](#getfileext)|Retorna a extensão do arquivo selecionado.|  
|[CFileDialog::GetFileName](#getfilename)|Retorna o nome de arquivo do arquivo selecionado.|  
|[CFileDialog::GetFileTitle](#getfiletitle)|Retorna o título do arquivo selecionado.|  
|[CFileDialog::GetFolderPath](#getfolderpath)|Recupera o caminho da pasta aberta no momento ou diretório de um estilo do Explorer **abrir** ou **Salvar como** caixa de diálogo comum.|  
|[CFileDialog::GetIFileDialogCustomize](#getifiledialogcustomize)|Recupera o objeto COM interno para um personalizado `CFileDialog` objeto.|  
|[CFileDialog::GetIFileOpenDialog](#getifileopendialog)|Recupera o objeto COM interno para uma `CFileDialog` que é usado como um **abrir** caixa de diálogo de arquivo.|  
|[CFileDialog::GetIFileSaveDialog](#getifilesavedialog)|Recupera o objeto COM interno para uma `CFileDialog` que é usado como um **salvar** caixa de diálogo de arquivo.|  
|[CFileDialog::GetNextPathName](#getnextpathname)|Retorna o caminho completo do próximo arquivo selecionado.|  
|[CFileDialog::GetOFN](#getofn)|Recupera o `OPENFILENAME` estrutura do `CFileDialog` objeto.|  
|[CFileDialog::GetPathName](#getpathname)|Retorna o caminho completo do arquivo selecionado.|  
|[CFileDialog::GetReadOnlyPref](#getreadonlypref)|Retorna o status de somente leitura do arquivo selecionado.|  
|[CFileDialog::GetResult](#getresult)|Obtém a opção que o usuário feito na caixa de diálogo.|  
|[CFileDialog::GetResults](#getresults)|Obtém as opções do usuário em uma caixa de diálogo que permite a seleção múltipla.|  
|[CFileDialog::GetSelectedControlItem](#getselectedcontrolitem)|Obtém um item específico de controles de contêiner especificado na caixa de diálogo.|  
|[CFileDialog::GetStartPosition](#getstartposition)|Retorna a posição do primeiro elemento da lista de nome de arquivo.|  
|[CFileDialog::HideControl](#hidecontrol)|Oculta o controle especificado em um estilo do Explorer **abrir** ou **Salvar como** caixa de diálogo comum.|  
|[CFileDialog::IsPickFoldersMode](#ispickfoldersmode)|Determina se a caixa de diálogo atual no modo do seletor de pasta.|  
|[CFileDialog::MakeProminent](#makeprominent)|Locais de um controle na caixa de diálogo para que ele se destaque em comparação com outros controles adicionados.|  
|[CFileDialog::RemoveControlItem](#removecontrolitem)|Remove um item de um controle de contêiner na caixa de diálogo.|  
|[CFileDialog::SetCheckButtonState](#setcheckbuttonstate)|Define o estado atual de um botão de seleção (caixa de seleção) na caixa de diálogo.|  
|[CFileDialog::SetControlItemState](#setcontrolitemstate)|Define o estado atual de um item em um controle de contêiner encontrado na caixa de diálogo.|  
|[CFileDialog::SetControlItemText](#setcontrolitemtext)|Define o texto de um item de controle. Por exemplo, o texto que acompanha um botão de opção ou um item em um menu.|  
|[CFileDialog::SetControlLabel](#setcontrollabel)|Define o texto associado ao controle, como o texto do botão ou um rótulo da caixa de edição.|  
|[CFileDialog::SetControlState](#setcontrolstate)|Define a visibilidade atual e estados de um dado controle habilitados.|  
|[CFileDialog::SetControlText](#setcontroltext)|Define o texto para o controle especificado em um estilo do Explorer **abrir** ou **Salvar como** caixa de diálogo comum.|  
|[CFileDialog::SetDefExt](#setdefext)|Define a extensão de nome de arquivo padrão para um estilo do Explorer **abrir** ou **Salvar como** caixa de diálogo comum.|  
|[CFileDialog::SetEditBoxText](#seteditboxtext)|Define o texto atual em um controle de caixa de edição.|  
|[CFileDialog::SetProperties](#setproperties)|Fornece um repositório de propriedades que define os valores padrão a serem usados para o item que está sendo salvo.|  
|[CFileDialog::SetSelectedControlItem](#setselectedcontrolitem)|Define o estado selecionado de um item específico em um grupo de botões de opção ou uma caixa de combinação encontrado na caixa de diálogo.|  
|[CFileDialog::SetTemplate](#settemplate)|Define o modelo de caixa de diálogo para o `CFileDialog` objeto.|  
|[CFileDialog::StartVisualGroup](#startvisualgroup)|Declara um grupo visual na caixa de diálogo. As chamadas subsequentes para qualquer método "Adicionar" adicionam esses elementos para esse grupo.|  
|[CFileDialog::UpdateOFNFromShellDialog](#updateofnfromshelldialog)|Atualiza os dados armazenados no `m_ofn` variável de membro para corresponder o estado atual da caixa de diálogo de arquivo.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFileDialog::OnButtonClicked](#onbuttonclicked)|Chamado quando o botão é clicado.|  
|[CFileDialog::OnCheckButtonToggled](#oncheckbuttontoggled)|Chamado quando a caixa de seleção estiver marcada/desmarcada.|  
|[CFileDialog::OnControlActivating](#oncontrolactivating)|Chamado quando o controle está sendo ativo.|  
|[CFileDialog::OnFileNameChange](#onfilenamechange)|Manipula o `WM_NOTIFY CDN_SELCHANGE` mensagem.|  
|[CFileDialog::OnFileNameOK](#onfilenameok)|Valida o nome de arquivo inserido na caixa de diálogo.|  
|[CFileDialog::OnFolderChange](#onfolderchange)|Manipula o `WM_NOTIFY CDN_FOLDERCHANGE` mensagem.|  
|[CFileDialog::OnInitDone](#oninitdone)|Manipula o `WM_NOTIFY CDN_INITDONE` mensagem.|  
|[CFileDialog::OnItemSelected](#onitemselected)|Chamado quando o contêiner do item é selecionado.|  
|[CFileDialog::OnLBSelChangedNotify](#onlbselchangednotify)|Permite que você execute ações personalizadas quando a seleção de arquivo é alterado.|  
|[CFileDialog::OnShareViolation](#onshareviolation)|Identificadores de compartilham violações.|  
|[CFileDialog::OnTypeChange](#ontypechange)|Manipula o `WM_NOTIFY CDN_TYPECHANGE` mensagem.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CFileDialog::m_ofn](#m_ofn)|O Windows `OPENFILENAME` estrutura. Fornece acesso aos parâmetros de caixa de diálogo de arquivo básico.|  
  
## <a name="remarks"></a>Comentários  
 Caixas de diálogo comuns permitem implementar caixas de diálogo de seleção de arquivos, por exemplo, **abrir arquivo** e **Salvar como**, de forma consistente com os padrões do Windows.  
  
 Você pode usar `CFileDialog` como é com o construtor fornecido, ou você pode derivar sua própria classe de caixa de diálogo de `CFileDialog` e escrever um construtor para atender às suas necessidades. Em ambos os casos, essas caixas de diálogo se comportará como caixas de diálogo MFC padrão porque eles são derivados do [CCommonDialog classe](../../mfc/reference/ccommondialog-class.md). `CFileDialog` depende do COMMDLG. Arquivo DLL que está incluído no Windows.  
  
 A aparência e a funcionalidade do `CFileDialog` com o Windows Vista ou posterior são diferentes das versões anteriores do Windows. O padrão `CFileDialog` usa automaticamente o novo Windows Vista ou posterior estilo sem alterações de código, se um programa é compilado e executado no Windows Vista ou posterior. Use o `bVistaStyle` parâmetro no construtor para substituir manualmente a atualização automática. A exceção para a atualização automática é caixas de diálogo personalizadas. Eles não serão convertidos para o novo estilo. Para obter mais informações sobre o construtor, consulte [CFileDialog::CFileDialog](#cfiledialog).  
  
> [!NOTE]
>  O sistema de controle de ID é diferente no Windows Vista ou posterior a partir de versões anteriores do Windows quando você usar um `CFileDialog`. Você deve atualizar todas as referências a `CFileDialog` controles no código antes de você pode transferir seu projeto de uma versão anterior do Windows.  
  
 Alguns `CFileDialog` métodos não têm suporte no Windows Vista ou posterior. Consulte o tópico do método individual para obter informações sobre se o método tem suporte. Além disso, as seguintes funções herdadas não têm suporte no Windows Vista ou posterior:  
  
- [CDialog::OnInitDialog](../../mfc/reference/cdialog-class.md#oninitdialog)  
  
- [CDialog::OnSetFont](../../mfc/reference/cdialog-class.md#onsetfont)  
  
 As mensagens do windows para o `CFileDialog` classe variam de acordo com o sistema operacional que você está usando. Por exemplo, Windows XP não suporta [CDialog::OnCancel](../../mfc/reference/cdialog-class.md#oncancel) e [CDialog::OnOK](../../mfc/reference/cdialog-class.md#onok) para o `CFileDialog` classe. No entanto, o Windows Vista e sistemas operacionais posteriores dão suporte a eles. Para obter mais informações sobre as mensagens de diferentes que são geradas e a ordem em que são recebidos, consulte [CFileDialog exemplo: ordem de eventos de log](../../visual-cpp-samples.md).  
  
 Para usar um `CFileDialog` de objeto, primeiro crie o objeto usando o `CFileDialog` construtor. Depois que a caixa de diálogo foi construída, você pode definir ou modificar quaisquer valores de [CFileDialog::m_ofn](#m_ofn) estrutura para inicializar os valores ou os estados dos controles de caixa de diálogo. O `m_ofn` estrutura é do tipo `OPENFILENAME`. Para obter mais informações, consulte o [OPENFILENAME](http://msdn.microsoft.com/library/windows/desktop/ms646839) estrutura no SDK do Windows.  
  
 Depois de inicializar os controles de caixa de diálogo, chame o [CFileDialog::DoModal](#domodal) método para exibir a caixa de diálogo caixa para que o usuário pode digitar o nome de arquivo e caminho. `DoModal` Retorna se o usuário clicou Okey (IDOK) ou o botão Cancelar (IDCANCEL). Se `DoModal` retorna IDOK, você pode usar uma da `CFileDialog` funções de membro público para recuperar as informações inseridas pelo usuário.  
  
> [!NOTE]
> No Windows Vista ou posterior, diversas chamadas para [IFileDialog::SetFileTypes](http://msdn.microsoft.com/library/windows/desktop/bb775980) causa um erro. A segunda chamada para `SetFileTypes` para qualquer instância de um `CFileDialog` retornará `E_UNEXPECTED` no Windows Vista ou posterior. Alguns `CFileDialog` método funções chamada `SetFileTypes`. Por exemplo, duas chamadas para `CFileDialog::DoModal` para a mesma instância de um `CFileDialog` gera [ASSERT](diagnostic-services.md#assert).  
  
 `CFileDialog` inclui vários membros protegidos que permitem realizar tratamento personalizado de violações de compartilhamento, validação de nome de arquivo e notificação de alteração de caixa de listagem. Esses membros protegidos são funções de retorno de chamada que não têm a maioria dos aplicativos para usar como o tratamento de padrão é executado automaticamente. Entradas de mapa de mensagem para essas funções não são necessárias porque eles são funções virtuais padrão.  
  
 Você pode usar o Windows [CommDlgExtendedError](http://msdn.microsoft.com/library/windows/desktop/ms646916) função para determinar se ocorreu um erro durante a inicialização da caixa de diálogo e para saber mais sobre o erro.  
  
 A destruição do `CFileDialog` objetos é tratado automaticamente. Você não precisa chamar [CDialog::EndDialog](../../mfc/reference/cdialog-class.md#enddialog).  
  
 Para permitir que o usuário selecione vários arquivos, defina o `OFN_ALLOWMULTISELECT` sinalizador antes de chamar `DoModal`. Você deve fornecer seu próprio buffer do nome de arquivo para acomodar a lista retornada de vários nomes de arquivo. Para fazer isso, substituindo `m_ofn.lpstrFile` com um ponteiro para um buffer alocou, depois de construir o `CFileDialog`, mas antes de chamar `DoModal`.  
  
 Além disso, você deve definir `m_ofn.nMaxFile` usando o número de caracteres no buffer apontado pelo `m_ofn.lpstrFile`. Se você definir o número máximo de arquivos a ser selecionado para `n`, o tamanho do buffer necessário é `n * (_MAX_PATH + 1) + 1`. O primeiro item retornado no buffer é o caminho para a pasta onde os arquivos foram selecionados. Para Windows Vista ou caixas de diálogo de estilo mais recente, as cadeias de caracteres de nome do arquivo e diretório são terminada em nulo, com um caractere null extra após o último nome de arquivo. Este formato permite que as caixas de diálogo de estilo do Explorer retornar nomes de arquivo longos que incluem espaços. Para caixas de diálogo de estilo antigo, as cadeias de caracteres de nome do arquivo e diretório são separadas por espaços e a função usa nomes de arquivo curtos para nomes de arquivo com espaços.  
  
 O exemplo a seguir demonstra como usar um buffer para recuperar e lista vários nomes de arquivo.  
  
 [!code-cpp[NVC_MFCFiles#23](../../atl-mfc-shared/reference/codesnippet/cpp/cfiledialog-class_1.cpp)]  
  
 Para alterar o tamanho do buffer em resposta ao usuário selecionar vários nomes de arquivo, você deve derivar uma nova classe de `CFileDialog` e substituir o [CFileDialog::OnFileNameChange](#onfilenamechange) método.  
  
 Se você derivar uma nova classe de `CFileDialog`, você pode usar um mapa de mensagem para lidar com todas as mensagens. Para estender a manipulação de mensagem padrão, derive uma classe de `CFileDialog`, adicione um mapa de mensagem para a nova classe e fornecer funções de membro para as novas mensagens. Você não precisa fornecer uma função de gancho para personalizar a caixa de diálogo.  
  
 Para personalizar a caixa de diálogo, derive uma classe de `CFileDialog`, forneça um modelo de caixa de diálogo personalizada e adicionar um mapa de mensagem para processar as mensagens de notificação de controles estendidos. Passe todas as mensagens não processadas para a classe base. Você não precisa personalizar a função de gancho.  
  
 Quando você estiver usando o Windows Vista ou posterior estilo do `CFileDialog`, você não pode usar mapas de mensagem e modelos de caixa de diálogo. Em vez disso, você deve usar as interfaces COM para uma funcionalidade semelhante.  
  
 Para obter mais informações sobre como usar `CFileDialog`, consulte [Classes de caixa de diálogo comuns](../../mfc/common-dialog-classes.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CCommonDialog](../../mfc/reference/ccommondialog-class.md)  
  
 `CFileDialog`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdlgs.h  
  
##  <a name="addcheckbutton"></a>  CFileDialog::AddCheckButton  
 Adiciona um botão de seleção para a caixa de diálogo.  
  
```  
HRESULT AddCheckButton(
    DWORD dwIDCtl,  
    const CString& strLabel,  
    BOOL bChecked);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID do botão de seleção para adicionar.  
  
 `strLabel`  
 O nome do botão de seleção.  
  
 `bChecked`  
 Um valor booleano que indica o estado atual do botão de seleção. `TRUE` Se marcado. `FALSE` caso contrário  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="addcombobox"></a>  CFileDialog::AddComboBox  
 Adiciona uma caixa de combinação para a caixa de diálogo.  
  
```  
HRESULT AddComboBox(DWORD dwIDCtl);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A identificação da caixa de combinação.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="addcontrolitem"></a>  CFileDialog::AddControlItem  
 Adiciona um item a um controle de contêiner na caixa de diálogo.  
  
```  
HRESULT AddControlItem(
    DWORD dwIDCtl,  
    DWORD dwIDItem,  
    const CString& strLabel);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID do controle de contêiner para adicionar o item.  
  
 `dwIDItem`  
 A ID do item.  
  
 `strLabel`  
 Texto do item.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="addeditbox"></a>  CFileDialog::AddEditBox  
 Adiciona uma caixa de edição na caixa de diálogo.  
  
```  
HRESULT AddEditBox(
    DWORD dwIDCtl,  
    const CString& strText);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A identificação da caixa de edição.  
  
 `strText`  
 O nome da caixa de edição.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="addmenu"></a>  CFileDialog::AddMenu  
 Adiciona um menu para a caixa de diálogo.  
  
```  
HRESULT AddMenu(
    DWORD dwIDCtl,  
    const CString& strLabel);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A identificação do menu.  
  
 `strLabel`  
 O nome do menu.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="addplace"></a>  CFileDialog::AddPlace  
 Adiciona que uma pasta à lista de coloca disponível para o usuário abrir ou salvar os itens.  
  
```  
void AddPlace(
    LPCWSTR lpszFolder,  
    FDAP fdap = FDAP_TOP) throw();

 
void AddPlace(
    IShellItem* psi,  
    FDAP fdap = FDAP_TOP) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFolder`  
 Um caminho para a pasta a ser disponibilizados para o usuário. Isso só pode ser uma pasta.  
  
 `fdap`  
 Especifica onde a pasta é colocada dentro da lista.  
  
 `psi`  
 Um ponteiro para um IShellItem que representa a pasta a ser disponibilizados para o usuário. Isso só pode ser uma pasta.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="addpushbutton"></a>  CFileDialog::AddPushButton  
 Adiciona um botão à caixa de diálogo.  
  
```  
HRESULT AddPushButton(
    DWORD dwIDCtl,  
    const CString& strLabel);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID do botão Adicionar.  
  
 `strLabel`  
 O nome do botão.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="addradiobuttonlist"></a>  CFileDialog::AddRadioButtonList  
 Adiciona um grupo de botão (também conhecido como o botão de opção) de opção na caixa de diálogo.  
  
```  
HRESULT AddRadioButtonList(DWORD dwIDCtl);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID do grupo de botões de opção para adicionar.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="addseparator"></a>  CFileDialog::AddSeparator  
 Adiciona um separador para a caixa de diálogo.  
  
```  
HRESULT AddSeparator(DWORD dwIDCtl);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 Adicione a ID do separador.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="addtext"></a>  CFileDialog::AddText  
 Adiciona texto à caixa de diálogo.  
  
```  
HRESULT AddText(
    DWORD dwIDCtl,  
    const CString& strText);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A identificação do texto.  
  
 `strText`  
 O nome de texto.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="applyofntoshelldialog"></a>  CFileDialog::ApplyOFNToShellDialog  
 Atualiza o estado atual do [CFileDialog](../../mfc/reference/cfiledialog-class.md) com base nos valores armazenados no `m_ofn` estrutura de dados.  
  
```  
void ApplyOFNToShellDialog();
```  
  
### <a name="remarks"></a>Comentários  
 Em versões do Windows anteriores ao Windows Vista, o membro [OPENFILENAME](https://msdn.microsoft.com/library/ms911906.aspx) estrutura de dados continuamente foi sincronizada com o estado do `CFileDialog`. As alterações para o [m_ofn](#m_ofn) variável de membro foram refletidas imediatamente no estado da caixa de diálogo. Além disso, as alterações para o estado da caixa de diálogo atualizam imediatamente o `m_ofn` variável de membro.  
  
 No Windows Vista ou posterior, os valores de `m_ofn` variável de membro e o estado do `CFileDialog` não há garantia de ser sincronizada. Essa função força o estado do `CFileDialog` para ser atualizado para corresponder a `m_ofn` estrutura. Essa função automaticamente durante o Windows chama [CFileDialog::DoModal](#domodal).  
  
 Para obter mais informações sobre como usar o `CFileDialog` classe no Windows Vista ou posterior, consulte [classe CFileDialog](../../mfc/reference/cfiledialog-class.md).  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileDialog::UpdateOFNFromShellDialog](#updateofnfromshelldialog).  
  
##  <a name="cfiledialog"></a>  CFileDialog::CFileDialog  
 Chame essa função para construir uma caixa de diálogo de arquivo padrão do Windows.  
  
```  
explicit CFileDialog(
    BOOL bOpenFileDialog,  
    LPCTSTR lpszDefExt = NULL,  
    LPCTSTR lpszFileName = NULL,  
    DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,  
    LPCTSTR lpszFilter = NULL,  
    CWnd* pParentWnd = NULL,  
    DWORD dwSize = 0,  
    BOOL bVistaStyle = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bOpenFileDialog`  
 O parâmetro que especifica o tipo de caixa de diálogo para criar. Defina-a como `TRUE` para construir um **abrir arquivo** caixa de diálogo. Defina-a como `FALSE` para construir um **Salvar como arquivo** caixa de diálogo.  
  
 [in] `lpszDefExt`  
 A extensão de nome de arquivo padrão. Se o usuário não inclui uma extensão conhecida (uma que tenha uma associação no computador do usuário) na caixa Nome do arquivo, a extensão especificada pelo `lpszDefExt` automaticamente é acrescentado ao nome do arquivo. Se esse parâmetro for `NULL`, sem extensão é anexado.  
  
 [in] `lpszFileName`  
 O nome do arquivo inicial que aparece na caixa Nome do arquivo. Se `NULL`, nenhum nome de arquivo inicial é exibida.  
  
 [in] `dwFlags`  
 Uma combinação de um ou mais sinalizadores que você pode usar para personalizar a caixa de diálogo. Para obter uma descrição desses sinalizadores, consulte o [OPENFILENAME](http://msdn.microsoft.com/library/windows/desktop/ms646839) estrutura no SDK do Windows. Se você modificar o `m_ofn.Flags` membro da estrutura, use um operador OR bit a bit em suas alterações para manter o comportamento padrão.  
  
 [in] `lpszFilter`  
 Uma série de pares de cadeia de caracteres que especifique os filtros que você pode aplicar o arquivo. Se você especificar filtros de arquivo, somente os arquivos que correspondem aos critérios de filtro serão exibidos na lista de arquivos. Consulte a seção comentários para obter mais informações sobre como trabalhar com filtros de arquivo.  
  
 [in] `pParentWnd`  
 Um ponteiro para a janela pai ou o proprietário da caixa de diálogo de arquivo.  
  
 [in] `dwSize`  
 O tamanho do `OPENFILENAME` estrutura. Esse valor depende da versão do sistema operacional. MFC usado esse parâmetro para determinar o tipo apropriado de caixa de diálogo para criar. O tamanho padrão de 0 significa que o código MFC determinará o tamanho da caixa de diálogo correto a ser usado com base na versão do sistema operacional no qual o programa é executado.  
  
 [in] `bVistaStyle`  
 **Observação** esse parâmetro está disponível no Visual Studio 2008 e posterior e será fazer com que a caixa de diálogo Novo estilo a ser usado somente se você estiver executando no Windows Vista ou posterior.  
  
 O parâmetro que especifica o estilo da caixa de diálogo de arquivo. Defina-a como `TRUE` para usar as caixas de diálogo de arquivo de estilo Vista novo. Caso contrário, será usado o estilo antigo de caixas de diálogo. Consulte a seção comentários para obter mais informações em execução em Vista.  
  
### <a name="remarks"></a>Comentários  
 Qualquer um **abrir arquivo** ou **Salvar como arquivo** caixa de diálogo é construída, dependendo do valor de `bOpenFileDialog`.  
  
 Especificando uma extensão padrão usando `lpszDefExt` podem não produzir o comportamento esperado, pois raramente é previsível quais extensões têm associações de arquivo no computador do usuário. Se você precisar de mais controle sobre o acréscimo de uma extensão padrão, você pode derivar sua própria classe de `CFileDialog`e substituir o `CFileDialog::OnFileNameOK` método para executar seu próprio tratamento de extensão.  
  
 Para permitir que o usuário selecione vários arquivos, defina o `OFN_ALLOWMULTISELECT` sinalizador antes de chamar [DoModal](#domodal). Você deve fornecer seu próprio buffer do nome de arquivo para armazenar a lista retornada de vários nomes de arquivo. Para fazer isso, substituindo `m_ofn.lpstrFile` com um ponteiro para um buffer alocou, depois de construir o [CFileDialog](../../mfc/reference/cfiledialog-class.md), mas antes de chamar `DoModal`. Além disso, você deve definir `m_ofn.nMaxFile` com o número de caracteres no buffer apontado pelo `m_ofn.lpstrFile`. Se você definir o número máximo de arquivos a ser selecionado para `n`, é o tamanho do buffer necessário `n`*(_MAX_PATH + 1) + 1. Por exemplo:  
  
 [!code-cpp[NVC_MFCFiles#23](../../atl-mfc-shared/reference/codesnippet/cpp/cfiledialog-class_1.cpp)]  
  
 Para habilitar o usuário redimensionar uma caixa de diálogo de estilo do Explorer usando o mouse ou teclado, defina o `OFN_ENABLESIZING` sinalizador. Defina esse sinalizador é necessário somente se você fornecer um modelo personalizado ou um procedimento de cabo. O sinalizador funciona apenas com uma caixa de diálogo de estilo do Explorer. caixas de diálogo de estilo antigo não podem ser redimensionadas.  
  
 O `lpszFilter` parâmetro é usado para determinar o tipo de nome de arquivo deve ter um arquivo a ser exibido na lista de arquivos. A primeira cadeia de caracteres do par de cadeia de caracteres descreve o filtro. a segunda cadeia indica a extensão de nome de arquivo a ser usado. Várias extensões podem ser especificadas usando um ponto e vírgula (o caractere ';') como o delimitador. A cadeia de caracteres termina com dois '&#124;' caracteres, seguido por um `NULL` caracteres. Você também pode usar um [CString](../../atl-mfc-shared/using-cstring.md) objeto para este parâmetro.  
  
 Por exemplo, [!INCLUDE[ofprexcel](../../mfc/reference/includes/ofprexcel_md.md)] permite aos usuários abrir arquivos que têm extensões. xlc (gráfico) ou. xls (planilha), entre outros. O filtro para o Excel pode ser escrito como:  
  
 [!code-cpp[NVC_MFCFiles#24](../../atl-mfc-shared/reference/codesnippet/cpp/cfiledialog-class_2.cpp)]  
  
 No entanto, se você pretende usar essa cadeia de caracteres diretamente atualizar o `OPENFILENAME` estrutura, você deve delimitar cadeias de caracteres com o caractere null, '\0', em vez das barras verticais ('&#124;').  
  
 O `bVistaStyle` parâmetro só é aplicável quando em execução no Windows Vista ou posterior. Em versões anteriores do Windows, esse parâmetro é ignorado. Se `bVistaStyle` é definido como `TRUE`, quando você compilar um programa com o Visual Studio 2008 ou posterior, o novo estilo Vista **caixa de diálogo arquivo** será usado. Caso contrário, o estilo MFC anterior **caixa de diálogo arquivo** será usado.  
  
 Não há suporte para modelos de caixa de diálogo em caixas de diálogo com base em `bVistaStyle`  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileDialog::DoModal](#domodal).  
  
##  <a name="domodal"></a>  CFileDialog::DoModal  
 Chame essa função para exibir a caixa de diálogo de arquivo comuns do Windows e permitir que o usuário procurar arquivos e diretórios e insira um nome de arquivo.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 **IDOK** ou **IDCANCEL**. Se **IDCANCEL** é retornado, chame o Windows [CommDlgExtendedError](http://msdn.microsoft.com/library/windows/desktop/ms646916) função para determinar se ocorreu um erro.  
  
 **IDOK** e **IDCANCEL** são constantes que indicam se o usuário selecionou o botão Okey ou em Cancelar.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser inicializar as várias opções de caixa de diálogo de arquivo definindo membros do **m_ofn** estrutura, você deve fazer isso antes de chamar `DoModal`, mas depois que o objeto de caixa de diálogo é construído.  
  
 Por exemplo, se você quiser permitir que o usuário selecione vários arquivos, defina o `OFN_ALLOWMULTISELECT` sinalizador antes de chamar `DoModal`, conforme mostrado no exemplo de código neste tópico.  
  
 Quando a usuário clica em botões Okey ou cancelar a caixa de diálogo ou seleciona o fechamento de opção na caixa de diálogo controle de menu, o controle é retornado ao seu aplicativo. Em seguida, você pode chamar outras funções de membro para recuperar as configurações ou informações de entradas do usuário na caixa de diálogo.  
  
 `DoModal` é uma função virtual substituída da classe `CDialog`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCFiles#25](../../atl-mfc-shared/reference/codesnippet/cpp/cfiledialog-class_3.cpp)]  
  
##  <a name="enableopendropdown"></a>  CFileDialog::EnableOpenDropDown  
 Permite que uma lista suspensa em abrir ou salvar o botão na caixa de diálogo.  
  
```  
HRESULT EnableOpenDropDown(DWORD dwIDCtl);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID da lista suspensa.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="endvisualgroup"></a>  CFileDialog::EndVisualGroup  
 Interrompe a adição de elementos a um grupo de visual na caixa de diálogo.  
  
```  
HRESULT EndVisualGroup();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK se bem-sucedido; um valor de erro caso contrário.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getcheckbuttonstate"></a>  CFileDialog::GetCheckButtonState  
 Recupera o estado atual de um botão de seleção (caixa de seleção) na caixa de diálogo.  
  
```  
HRESULT GetCheckButtonState(
    DWORD dwIDCtl,  
    BOOL& bChecked);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID da caixa de seleção.  
  
 `bChecked`  
 O estado da caixa de seleção. `TRUE` indica a ativação; `FALSE` indica desmarcada.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getcontrolitemstate"></a>  CFileDialog::GetControlItemState  
 Recupera o estado atual de um item em um controle de contêiner encontrado na caixa de diálogo.  
  
```  
HRESULT GetControlItemState(
    DWORD dwIDCtl,  
    DWORD dwIDItem,  
    CDCONTROLSTATEF& dwState);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID do controle de contêiner.  
  
 `dwIDItem`  
 A ID do item.  
  
 `dwState`  
 Uma referência a uma variável que recebe um dos mais valores de enumeração CDCONTROLSTATE que indica o estado atual do controle.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getcontrolstate"></a>  CFileDialog::GetControlState  
 Recupera a visibilidade atual e os estados de um dado controle habilitados.  
  
```  
HRESULT GetControlState(
    DWORD dwIDCtl,  
    CDCONTROLSTATEF& dwState);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID do controle.  
  
 `dwState`  
 Uma referência a uma variável que recebe um ou mais valores de enumeração CDCONTROLSTATE que indica o estado atual do controle.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="geteditboxtext"></a>  CFileDialog::GetEditBoxText  
 Recupera o texto atual em um controle de caixa de edição.  
  
```  
HRESULT GetEditBoxText(
    DWORD dwIDCtl,  
    CString& strText);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID da caixa de edição.  
  
 `strText`  
 O valor do texto.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getfileext"></a>  CFileDialog::GetFileExt  
 Chame essa função para recuperar a extensão do nome de arquivo inserido na caixa de diálogo.  
  
```  
CString GetFileExt() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A extensão do nome de arquivo.  
  
### <a name="remarks"></a>Comentários  
 Por exemplo, se o nome do arquivo inserido dados. TXT, `GetFileExt` retorna "TXT".  
  
 Se `m_ofn.Flags` tem o `OFN_ALLOWMULTISELECT` sinalizador definido, essa cadeia de caracteres contém uma sequência de cadeias de caracteres terminada em nulo, com a primeira cadeia de caracteres que está sendo o caminho do diretório do grupo de arquivos selecionado, seguido pelos nomes de todos os arquivos selecionados pelo usuário. Para recuperar nomes de caminhos de arquivo, use o [GetStartPosition](#getstartposition) e [GetNextPathName](#getnextpathname) funções de membro.  
  
##  <a name="getfilename"></a>  CFileDialog::GetFileName  
 Chame essa função para recuperar o nome do nome de arquivo inserido na caixa de diálogo.  
  
```  
CString GetFileName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome do arquivo.  
  
### <a name="remarks"></a>Comentários  
 O nome do arquivo inclui o prefixo e a extensão. Por exemplo, `GetFileName` retornará "texto. DAT"para o arquivo C:\FILES\TEXT.DAT.  
  
 Se `m_ofn.Flags` tem o `OFN_ALLOWMULTISELECT` o sinalizador será definido, você deve chamar [GetStartPosition](#getstartposition) e [GetNextPathName](#getnextpathname) para recuperar um nome de caminho do arquivo.  
  
##  <a name="getfiletitle"></a>  CFileDialog::GetFileTitle  
 Chame essa função para recuperar o título do arquivo digitado na caixa de diálogo.  
  
```  
CString GetFileTitle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O título do arquivo.  
  
### <a name="remarks"></a>Comentários  
 O título do arquivo inclui apenas o prefixo, sem o caminho ou a extensão. Por exemplo, `GetFileTitle` retornará "Texto" para o arquivo C:\FILES\TEXT.DAT.  
  
 Se `m_ofn.Flags` tem o `OFN_ALLOWMULTISELECT` sinalizador definido, essa cadeia de caracteres contém uma sequência de cadeias de caracteres terminada em nulo, com a primeira cadeia de caracteres que está sendo o caminho do diretório do grupo de arquivos selecionado, seguido pelos nomes de todos os arquivos selecionados pelo usuário. Por esse motivo, use o [GetStartPosition](#getstartposition) e [GetNextPathName](#getnextpathname) funções de membro para recuperar o próximo nome de arquivo na lista.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileDialog::DoModal](#domodal).  
  
##  <a name="getfolderpath"></a>  CFileDialog::GetFolderPath  
 Chame essa função de membro para recuperar o caminho da pasta aberta no momento ou do diretório para uma caixa de diálogo comuns do estilo do Explorer abrir ou salvar como.  
  
```  
CString GetFolderPath() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém a pasta aberta no momento ou diretório.  
  
### <a name="remarks"></a>Comentários  
 A caixa de diálogo deve ter sido criada com o **OFN_EXPLORER** estilo; caso contrário, o método falhará com uma declaração.  
  
 Você pode chamar esse método apenas enquanto a caixa de diálogo está sendo exibida. Depois que a caixa de diálogo foi fechada, essa função deixarão de funcionar e o método falhará com uma declaração.  
  
##  <a name="getifiledialogcustomize"></a>  CFileDialog::GetIFileDialogCustomize  
 Recupera um ponteiro para o objeto COM interno para um determinado [CFileDialog](../../mfc/reference/cfiledialog-class.md).  
  
```  
IFileDialogCustomize* GetIFileDialogCustomize();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O ponteiro para o objeto COM interno para o `CFileDialog`. É sua responsabilidade para liberar esse ponteiro adequadamente.  
  
### <a name="remarks"></a>Comentários  
 Use esta função apenas no Windows Vista ou posterior com um objeto que tem `bVistaStyle` definido como `true`. Se você usar essa função quando `bVistaStyle` é `false`, ela retornará `NULL` no modo de liberação e lançar uma asserção no modo de depuração.  
  
 Para obter mais informações sobre o `IFileDialogCustomize` interface, consulte [IFileDialogCustomize](http://msdn.microsoft.com/library/windows/desktop/bb775912).  
  
### <a name="example"></a>Exemplo  
 Este exemplo recupera o objeto interno do COM. Para executar este exemplo de código, você deve compilá-lo com o Windows Vista ou posterior.  
  
 [!code-cpp[NVC_MFC_CFileDialog#4](../../mfc/reference/codesnippet/cpp/cfiledialog-class_4.cpp)]  
  
##  <a name="getifileopendialog"></a>  CFileDialog::GetIFileOpenDialog  
 Recupera um ponteiro para o objeto COM interno para um determinado `CFileDialog`.  
  
```  
IFileOpenDialog* GetIFileOpenDialog();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O ponteiro para o objeto COM interno para o `CFileDialog`. É sua responsabilidade para liberar esse ponteiro adequadamente.  
  
### <a name="remarks"></a>Comentários  
 Use esta função apenas no Windows Vista ou posterior com um objeto que tem `bVistaStyle` definido como `true`. Essa função retorna `NULL` se o `CFileDialog` não é um **abrir** caixa de diálogo ou se `bVistaStyle` é definido como `false`. Nesse caso final, a função retornará somente `NULL` no modo de liberação - no modo de depuração lançará uma asserção.  
  
 Para obter mais informações sobre o `IFileOpenDialog` interface, consulte [IFileOpenDialog](http://msdn.microsoft.com/library/windows/desktop/bb775834).  
  
### <a name="example"></a>Exemplo  
 Este exemplo recupera o objeto interno do COM. Para executar esse código, você deve compilá-lo com o Windows Vista ou posterior.  
  
 [!code-cpp[NVC_MFC_CFileDialog#2](../../mfc/reference/codesnippet/cpp/cfiledialog-class_5.cpp)]  
  
##  <a name="getifilesavedialog"></a>  CFileDialog::GetIFileSaveDialog  
 Recupera um ponteiro para o objeto COM interno para um determinado `CFileDialog`.  
  
```  
IFileSaveDialog* GetIFileSaveDialog();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O ponteiro para o objeto COM interno para o `CFileDialog`. É sua responsabilidade para liberar esse ponteiro adequadamente.  
  
### <a name="remarks"></a>Comentários  
 Use esta função apenas no Windows Vista ou posterior com um objeto que tem `bVistaStyle` definido como `true`. Esta função retornará `NULL` se o `CFileDialog` não é um **salvar** caixa de diálogo ou se `bVistaStyle` é definido como `false`. Nesse caso final, a função retornará somente `NULL` no modo de liberação - no modo de depuração lançará uma asserção.  
  
 Para obter mais informações sobre o `IFileSaveDialog` interface, consulte [IFileSaveDialog](http://msdn.microsoft.com/library/windows/desktop/bb775688).  
  
### <a name="example"></a>Exemplo  
 Este exemplo recupera o objeto interno do COM. Para executar este exemplo de código, você deve compilá-lo com o Windows Vista ou posterior.  
  
 [!code-cpp[NVC_MFC_CFileDialog#3](../../mfc/reference/codesnippet/cpp/cfiledialog-class_6.cpp)]  
  
##  <a name="getnextpathname"></a>  CFileDialog::GetNextPathName  
 Chame essa função para recuperar o próximo nome de arquivo a partir do grupo selecionado na caixa de diálogo.  
  
```  
CString GetNextPathName(POSITION& pos) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pos`  
 Uma referência a um **posição** valor retornado pelo anterior `GetNextPathName` ou `GetStartPosition` chamada de função. **NULO** se tiver sido alcançado o final da lista.  
  
### <a name="return-value"></a>Valor de retorno  
 O caminho completo do arquivo.  
  
### <a name="remarks"></a>Comentários  
 O caminho do nome de arquivo inclui o título do arquivo e o caminho da pasta inteira. Por exemplo, `GetNextPathName` retornará "C:\FILES\TEXT. DAT"para o arquivo C:\FILES\TEXT.DAT. Você pode usar `GetNextPathName` em um loop de interação direta se estabelecer a posição inicial com uma chamada para `GetStartPosition`.  
  
 Se a seleção consistir de apenas um arquivo, esse nome será retornado.  
  
##  <a name="getofn"></a>  CFileDialog::GetOFN  
 Recupera o associado **OPENFILENAME** estrutura.  
  
```  
const OPENFILENAME& GetOFN() const;  
  
OPENFILENAME& GetOFN();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [OPENFILENAME](http://msdn.microsoft.com/library/windows/desktop/ms646839) estrutura.  
  
### <a name="remarks"></a>Comentários  
 Usar a segunda versão dessa função para inicializar a aparência de um **abrir arquivo** ou **Salvar como arquivo** caixa de diálogo depois que ele é criado, mas antes de ser exibido com o `DoModal` função de membro. Por exemplo, você pode definir o **lpstrTitle** membro do **m_ofn** para a legenda você deseja ter a caixa de diálogo.  
  
##  <a name="getpathname"></a>  CFileDialog::GetPathName  
 Chame essa função para recuperar o caminho completo do arquivo digitado na caixa de diálogo.  
  
```  
CString GetPathName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O caminho completo do arquivo.  
  
### <a name="remarks"></a>Comentários  
 O caminho do nome de arquivo inclui o título do arquivo e o caminho da pasta inteira. Por exemplo, `GetPathName` retornará "C:\FILES\TEXT. DAT"para o arquivo C:\FILES\TEXT.DAT.  
  
 Se `m_ofn.Flags` tem o `OFN_ALLOWMULTISELECT` sinalizador definido, essa cadeia de caracteres contém uma sequência de null teminated cadeias de caracteres, com a primeira cadeia de caracteres que está sendo o caminho do diretório do grupo de arquivos selecionado, seguido pelos nomes de todos os arquivos selecionados pelo usuário. Por esse motivo, use o [GetStartPosition](#getstartposition) e [GetNextPathName](#getnextpathname) funções de membro para recuperar o próximo nome de arquivo na lista.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CFileDialog::DoModal](#domodal).  
  
##  <a name="getreadonlypref"></a>  CFileDialog::GetReadOnlyPref  
 Chame essa função para determinar se a caixa de seleção somente leitura foi selecionada nas caixas de diálogo Windows abrir arquivo e salvar como arquivo padrão.  
  
```  
BOOL GetReadOnlyPref() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a caixa de seleção somente leitura na caixa de diálogo é selecionada. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você pode ocultar a caixa de seleção de somente leitura, definindo o `OFN_HIDEREADONLY` de estilo no `CFileDialog` construtor.  
  
> [!NOTE]
> Windows Vista ou posterior estilo `CFileDialog` objetos dão suporte a essa função. Tentativa de usar essa função em um Windows Vista ou posterior estilo `CFileDialog` lançará [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md).   
  
##  <a name="getresult"></a>  CFileDialog::GetResult  
 Recupera a opção que o usuário feito na caixa de diálogo.  
  
```  
IShellItem* GetResult() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um IShellItem que representa a opção do usuário.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getresults"></a>  CFileDialog::GetResults  
 Recupera as opções do usuário em uma caixa de diálogo que permite a seleção múltipla.  
  
```  
IShellItemArray* GetResults() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um IShellItemArray por meio do qual os itens selecionados na caixa de diálogo podem ser acessados.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getselectedcontrolitem"></a>  CFileDialog::GetSelectedControlItem  
 Recupera um item específico do controle de contêiner especificado na caixa de diálogo.  
  
```  
HRESULT GetSelectedControlItem(
    DWORD dwIDCtl,  
    DWORD& dwIDItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID do controle de contêiner.  
  
 `dwIDItem`  
 A ID do item selecionado pelo usuário no controle.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getstartposition"></a>  CFileDialog::GetStartPosition  
 Chamar essa função de membro para recuperar a posição do nome do caminho de arquivo primeiro na lista, se `m_ofn.Flags` tem o `OFN_ALLOWMULTISELECT` o sinalizador será definido.  
  
```  
POSITION GetStartPosition() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um **posição** valor que pode ser usado para iteração; **Nulo** se a lista está vazia.  
  
##  <a name="hidecontrol"></a>  CFileDialog::HideControl  
 Chame essa função de membro para ocultar o controle especificado em uma caixa de diálogo comuns do estilo do Explorer abrir ou salvar como.  
  
```  
void HideControl(int nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 A ID do controle para ocultar.  
  
### <a name="remarks"></a>Comentários  
 A caixa de diálogo deve ter sido criada com o **OFN_EXPLORER** estilo; caso contrário, a função falhará com uma declaração.  
  
##  <a name="ispickfoldersmode"></a>  CFileDialog::IsPickFoldersMode  
 Determina se a caixa de diálogo atual está no modo do seletor de pasta.  
  
```  
BOOL IsPickFoldersMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se a caixa de diálogo estiver no modo do seletor de pasta. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_ofn"></a>  CFileDialog::m_ofn  
 `m_ofn` é uma estrutura de tipo `OPENFILENAME`. Os dados nessa estrutura representam o estado atual do `CFileDialog`.  
  
### <a name="remarks"></a>Comentários  
 Usar essa estrutura para inicializar a aparência de um **abrir arquivo** ou **Salvar como arquivo** caixa de diálogo depois que você a construir, mas antes de exibi-lo com o [DoModal](#domodal) método. Por exemplo, você pode definir o `lpstrTitle` membro de `m_ofn` para a legenda você deseja ter a caixa de diálogo.  
  
 Com o Windows Vista ou posterior estilo de [CFileDialog](../../mfc/reference/cfiledialog-class.md), `m_ofn` não é garantia de que sempre coincidir com o estado da caixa de diálogo. Ele é sincronizado com a caixa de diálogo em versões anteriores do Windows. Consulte [CFileDialog::ApplyOFNToShellDialog](#applyofntoshelldialog) e [CFileDialog::UpdateOFNFromShellDialog](#updateofnfromshelldialog) para obter mais informações sobre a sincronização de `m_ofn` estrutura e o `CFileDialog` estado no Windows Vista ou posterior.  
  
 Windows Vista ou posteriores caixas de diálogo de arquivo de estilo não dão suporte a certos membros e os sinalizadores do `CFileDialog`. Como resultado, eles não terá efeito.  
  
 A seguir está uma lista dos membros que não são suportados pelo Windows Vista ou posterior:  
  
- `lpstrCustomFilter`  
  
- `lpstrInitialDir`  
  
- `lCustData`  
  
- `lpfnHook`  
  
- `lpTemplateName`  
  
 Os sinalizadores a seguir não têm suporte e, portanto, não têm nenhum efeito quando você usar o Windows Vista ou posterior estilo de `CFileDialog`:  
  
-   OFN_ENABLEHOOK  
  
-   OFN_ENABLEINCLUDENOTIFY  
  
-   OFN_ENABLETEMPLATE  
  
-   OFN_ENABLETEMPLATEHANDLE  
  
-   OFN_EXPLORER  
  
-   OFN_EXTENSIONDIFFERENT  
  
-   OFN_HIDEREADONLY  
  
-   OFN_LONGNAMES - efetivamente sempre no Windows Vista ou posterior  
  
-   OFN_NOLONGNAMES - efetivamente sempre desativada no Windows Vista ou posterior  
  
-   OFN_NONETWORKBUTTON - efetivamente sempre no Windows Vista ou posterior  
  
-   OFN_READONLY  
  
-   OFN_SHOWHELP  
  
 Para obter mais informações sobre essa estrutura, consulte o [OPENFILENAME](http://msdn.microsoft.com/library/windows/desktop/ms646839) estrutura no SDK do Windows.  
  
##  <a name="makeprominent"></a>  CFileDialog::MakeProminent  
 Locais de um controle na caixa de diálogo para que ele se destaque em comparação com outros controles.  
  
```  
HRESULT MakeProminent(DWORD dwIDCtl);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID do controle.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onbuttonclicked"></a>  CFileDialog::OnButtonClicked  
 Chamado quando o botão é clicado.  
  
```  
virtual void OnButtonClicked(DWORD dwIDCtl);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID do botão.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="oncheckbuttontoggled"></a>  CFileDialog::OnCheckButtonToggled  
 Chamado quando a caixa de seleção é marcada ou desmarcada.  
  
```  
virtual void OnCheckButtonToggled(
    DWORD dwIDCtl,  
    BOOL bChecked);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID da caixa de seleção.  
  
 `bChecked`  
 Marcada ou desmarcada.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="oncontrolactivating"></a>  CFileDialog::OnControlActivating  
 Chamado quando o controle é ativado.  
  
```  
virtual void OnControlActivating(DWORD dwIDCtl);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID do controle.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onfilenamechange"></a>  CFileDialog::OnFileNY` `alteração  
 Substitua este método se você desejar tratar o `WM_NOTIFY` `CDN_SELCHANGE` mensagem.  
  
```  
virtual void OnFileNameChange();
```  
  
### <a name="remarks"></a>Comentários  
 O sistema envia o `CDN_SELCHANGE` mensagem quando o usuário seleciona um novo arquivo ou pasta na lista de arquivos o **abrir** ou **Salvar como** caixa de diálogo. Substitua este método se você quiser realizar ações em resposta a essa mensagem.  
  
 O sistema envia essa mensagem somente se a caixa de diálogo foi criada com o sinalizador OFN_EXPLORER ativado. Para obter mais informações sobre a notificação, consulte [CDN_SELCHANGE](http://msdn.microsoft.com/library/windows/desktop/ms646865). Para obter informações sobre o sinalizador OFN_EXPLORER, consulte o [OPENFILENAME](http://msdn.microsoft.com/library/windows/desktop/ms646839) estrutura e [abrir e salvar como caixas de diálogo](http://msdn.microsoft.com/library/windows/desktop/ms646960).  
  
##  <a name="onfilenameok"></a>  CFileDialog::OnFileNameOK  
 Substitua essa função somente se você deseja fornecer validação personalizada de nomes de arquivos que são inseridos em uma caixa de diálogo comuns.  
  
```  
virtual BOOL OnFileNameOK();
```  
  
### <a name="return-value"></a>Valor de retorno  
 1 se o nome do arquivo não é um nome de arquivo válido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esta função permite que você rejeitar um nome de arquivo por qualquer motivo específico do aplicativo. Normalmente, você não precisa usar essa função, porque a estrutura fornece validação de padrão de nomes de arquivos e exibe uma caixa de mensagem se for digitado um nome de arquivo inválido.  
  
 Se 1 é retornado, a caixa de diálogo permanecerá exibida para o usuário insira outro nome de arquivo. O procedimento da caixa de diálogo descarta a caixa de diálogo se o retorno é 0. Outros diferente de zero valores de retorno estão atualmente reservados e não devem ser usados.  
  
##  <a name="onfolderchange"></a>  CFileDialog::OnFolderChange  
 Substituir esta função para manipular o **WM_NOTIFYCDN_FOLDERCHANGE** mensagem.  
  
```  
virtual void OnFolderChange();
```  
  
### <a name="remarks"></a>Comentários  
 A mensagem de notificação é enviada quando uma nova pasta é aberta na caixa de diálogo Abrir ou salvar como.  
  
 Notificação é enviada somente se a caixa de diálogo foi criada com o estilo OFN_EXPLORER. Para obter mais informações sobre a notificação, consulte [CDN_FOLDERCHANGE](http://msdn.microsoft.com/library/windows/desktop/ms646859). Para obter informações sobre o estilo OFN_EXPLORER, consulte o [OPENFILENAME](http://msdn.microsoft.com/library/windows/desktop/ms646839) estrutura e [abrir e salvar como caixas de diálogo](http://msdn.microsoft.com/library/windows/desktop/ms646960).  
  
##  <a name="oninitdone"></a>  CFileDialog::OnInitDone  
 Substituir esta função para manipular o `WM_NOTIFY` `CDN_INITDONE` mensagem.  
  
```  
virtual void OnInitDone();
```  
  
### <a name="remarks"></a>Comentários  
 O sistema envia essa mensagem de notificação quando o sistema tenha terminado Organizando controles no **abrir** ou **Salvar como** caixa de diálogo para abrir espaço para os controles da caixa de diálogo filho.  
  
 O sistema envia isso apenas se a caixa de diálogo foi criada com o estilo OFN_EXPLORER. Para obter mais informações sobre a notificação, consulte [CDN_INITDONE](http://msdn.microsoft.com/library/windows/desktop/ms646863). Para obter informações sobre o estilo OFN_EXPLORER, consulte o [OPENFILENAME](http://msdn.microsoft.com/library/windows/desktop/ms646839) estrutura e [abrir e salvar como caixas de diálogo](http://msdn.microsoft.com/library/windows/desktop/ms646960).  
  
> [!NOTE]
> Windows Vista ou posteriores caixas de diálogo de arquivo de estilo não dão suporte a essa função. Tentativa de usar essa função em um Windows Vista ou posterior caixa de diálogo de arquivo de estilo lançará [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md). 
  
##  <a name="onitemselected"></a>  CFileDialog::OnItemSelected  
 Chamado quando o item de contêiner é selecionado.  
  
```  
virtual void OnItemSelected(
    DWORD dwIDCtl,  
    DWORD dwIDItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID do controle de contêiner.  
  
 `dwIDItem`  
 A ID do item.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onlbselchangednotify"></a>  CFileDialog::OnLBSelChangedNotify  
 Essa função é chamada sempre que a seleção atual em uma caixa de listagem está prestes a ser alterada.  
  
```  
virtual void OnLBSelChangedNotify(
    UINT nIDBox,  
    UINT iCurSel,  
    UINT nCode);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIDBox*  
 A ID da caixa de listagem ou caixa de combinação no qual ocorreu a seleção.  
  
 `iCurSel`  
 O índice da seleção atual.  
  
 `nCode`  
 O código de notificação do controle. Esse parâmetro deve ter um dos seguintes valores:  
  
- **CD_LBSELCHANGE** especifica `iCurSel` é o item selecionado em uma caixa de listagem de seleção única.  
  
- **CD_LBSELSUB** Especifica que `iCurSel` não está selecionado em uma caixa de listagem de seleção múltipla.  
  
- **CD_LBSELADD** Especifica que `iCurSel` está selecionado em uma caixa de listagem de seleção múltipla.  
  
- **CD_LBSELNOITEMS** Especifica que nenhuma seleção existe em uma caixa de listagem de seleção múltipla.  
  
### <a name="remarks"></a>Comentários  
 Substitua essa função para fornecer manipulação personalizada das alterações de seleção na caixa de listagem. Por exemplo, você pode usar essa função para exibir os direitos de acesso ou data-last-modified de cada arquivo o usuário seleciona.  
  
##  <a name="onshareviolation"></a>  CFileDialog::OnShareViolation  
 Substitua essa função para fornecer manipulação personalizada das violações de compartilhamento.  
  
```  
virtual UINT OnShareViolation(LPCTSTR lpszPathName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszPathName`  
 O caminho do arquivo no qual ocorreu a violação de compartilhamento.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos seguintes valores:  
  
- **OFN_SHAREFALLTHROUGH** o nome do arquivo é retornado da caixa de diálogo.  
  
- **OFN_SHARENOWARN** nenhuma ação precisa ser tomada.  
  
- **OFN_SHAREWARN** o usuário recebe a mensagem de aviso padrão para esse erro.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, você não precisa usar essa função, porque a estrutura fornece o padrão de verificação de violações de compartilhamento e exibe uma caixa de mensagem se ocorrer uma violação de compartilhamento.  
  
 Se você quiser desabilitar a verificação de violação de compartilhamento, use o operador OR bit a bit para combinar o sinalizador **OFN_SHAREAWARE** com `m_ofn.Flags`.  
  
##  <a name="ontypechange"></a>  CFileDialog::OnTypeChange  
 Substituir esta função para manipular o **WM_NOTIFYCDN_TYPECHANGE** mensagem.  
  
```  
virtual void OnTypeChange();
```  
  
### <a name="remarks"></a>Comentários  
 A mensagem de notificação é enviada quando o usuário seleciona um novo tipo de arquivo da lista de tipos de arquivo aberta ou a caixa de diálogo Salvar como.  
  
 Notificação é enviada somente se a caixa de diálogo foi criada com o estilo OFN_EXPLORER. Para obter mais informações sobre a notificação, consulte [CDN_TYPECHANGE](http://msdn.microsoft.com/library/windows/desktop/ms646868). Para obter informações sobre o estilo OFN_EXPLORER, consulte o [OPENFILENAME](http://msdn.microsoft.com/library/windows/desktop/ms646839) estrutura e [abrir e salvar como caixas de diálogo](http://msdn.microsoft.com/library/windows/desktop/ms646960).  
  
##  <a name="removecontrolitem"></a>  CFileDialog::RemoveControlItem  
 Remove um item de um controle de contêiner na caixa de diálogo.  
  
```  
HRESULT RemoveControlItem(
    DWORD dwIDCtl,  
    DWORD dwIDItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID do controle de contêiner para remover o item do.  
  
 `dwIDItem`  
 A ID do item.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setcheckbuttonstate"></a>  CFileDialog::SetCheckButtonState  
 Define o estado atual de um botão de seleção (caixa de seleção) na caixa de diálogo.  
  
```  
HRESULT SetCheckButtonState(
    DWORD dwIDCtl,  
    BOOL bChecked);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID da caixa de seleção.  
  
 `bChecked`  
 O estado da caixa de seleção. `TRUE` indica a ativação; `FALSE` indica desmarcado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setcontrolitemstate"></a>  CFileDialog::SetControlItemState  
 Define o estado atual de um item em um controle de contêiner encontrado na caixa de diálogo.  
  
```  
HRESULT SetControlItemState(
    DWORD dwIDCtl,  
    DWORD dwIDItem,  
    CDCONTROLSTATEF dwState);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID do controle de contêiner.  
  
 `dwIDItem`  
 A ID do item.  
  
 `dwState`  
 Um ou mais valores de enumeração CDCONTROLSTATE que indicam o novo estado do controle.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setcontrolitemtext"></a>  CFileDialog::SetControlItemText  
 Define o texto de um item de controle. Por exemplo, o texto que acompanha um botão de opção ou um item em um menu.  
  
```  
HRESULT SetControlItemText(
    DWORD dwIDCtl,  
    DWORD dwIDItem,  
    const CString& strLabel);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID do controle de contêiner.  
  
 `dwIDItem`  
 A ID do item.  
  
 `strLabel`  
 Texto do item.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setcontrollabel"></a>  CFileDialog::SetControlLabel  
 Define o texto associado ao controle, como o texto do botão ou um rótulo da caixa de edição.  
  
```  
HRESULT SetControlLabel(
    DWORD dwIDCtl,  
    const CString& strLabel);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID do controle.  
  
 `strLabel`  
 O nome do controle.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setcontrolstate"></a>  CFileDialog::SetControlState  
 Define a visibilidade atual e estados de um dado controle habilitados.  
  
```  
HRESULT SetControlState(
    DWORD dwIDCtl,  
    CDCONTROLSTATEF dwState);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID do controle.  
  
 `dwState`  
 Um ou mais valores de enumeração CDCONTROLSTATE que indicam o estado atual do controle.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setcontroltext"></a>  CFileDialog::SetControlText  
 Chame este método para definir o texto para o controle especificado em um estilo do Explorer **abrir** ou **Salvar como** caixa de diálogo.  
  
```  
void SetControlText(
    int nID,  
    LPCSTR lpsz);

 
void SetControlText(
    int nID,  
    const wchar_t *lpsz);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nID`  
 A ID do controle para o qual definir o texto.  
  
 [in] `lpsz`  
 Um ponteiro para a cadeia de caracteres que contém o texto a ser definido para o controle.  
  
### <a name="remarks"></a>Comentários  
 Ambas as versões desta função são válidas para aplicativos que usam Unicode. No entanto, é válida para os aplicativos que usam somente a versão com o tipo LPCSTR [!INCLUDE[vcpransi](../../atl-mfc-shared/reference/includes/vcpransi_md.md)].  
  
 Para usar esse método, você deve criar a caixa de diálogo com o estilo OFN_EXPLORER. Caso contrário, a função falhará com uma declaração.  
  
##  <a name="setdefext"></a>  CFileDialog::SetDefExt  
 Chame essa função para definir a extensão de nome de arquivo padrão para uma caixa de diálogo comuns do estilo do Explorer abrir ou salvar como.  
  
```  
void SetDefExt(LPCSTR lpsz);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpsz`  
 Um ponteiro para uma cadeia de caracteres que contém a extensão padrão a ser usado para o objeto de caixa de diálogo. Essa cadeia de caracteres não deve conter um ponto (.).  
  
### <a name="remarks"></a>Comentários  
 A caixa de diálogo deve ter sido criada com o **OFN_EXPLORER** estilo; caso contrário, a função falhará com uma declaração.  
  
##  <a name="seteditboxtext"></a>  CFileDialog::SetEditBoxText  
 Define o texto atual em um controle de caixa de edição.  
  
```  
HRESULT SetEditBoxText(
    DWORD dwIDCtl,  
    const CString& strText);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID da caixa de edição.  
  
 `strText`  
 O valor do texto.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setproperties"></a>  CFileDialog::SetProperties  
 Fornece um repositório de propriedades que define os valores padrão a serem usados para o item que está sendo salvo.  
  
```  
BOOL SetProperties(LPCWSTR lpszPropList);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszPropList`  
 Uma lista de propriedades predefinidas separadas por ";". Para obter uma lista dos sinalizadores, consulte o `Flags` seção [OPENFILENAME](http://msdn.microsoft.com/en-us/8cecfd45-f7c1-4f8d-81a0-4e7fecc3b104).  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setselectedcontrolitem"></a>  CFileDialog::SetSelectedControlItem  
 Define o estado selecionado de um item específico em um grupo de botões de opção ou uma caixa de combinação encontrado na caixa de diálogo.  
  
```  
HRESULT SetSelectedControlItem(
    DWORD dwIDCtl,  
    DWORD dwIDItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID do controle de contêiner.  
  
 `dwIDItem`  
 A ID do item selecionado pelo usuário no controle.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="settemplate"></a>  CFileDialog::SetTemplate  
 Define o modelo de caixa de diálogo para o [CFileDialog](../../mfc/reference/cfiledialog-class.md) objeto.  
  
```  
void SetTemplate(
    UINT nWin3ID,  
    UINT nWin4ID);

 
void SetTemplate(
    LPCTSTR lpWin3ID,  
    LPCTSTR lpWin4ID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nWin3ID`  
 Contém o número da ID do recurso de modelo para o Gerenciador não- `CFileDialog` objeto. Este modelo é usado somente no Windows NT 3.51 ou quando o estilo OFN_EXPLORER não está presente.  
  
 [in] `nWin4ID`  
 Contém o número da ID do recurso de modelo para o Gerenciador de `CFileDialog` objeto. Este modelo é usado somente em [!INCLUDE[WinNt4Family](../../mfc/reference/includes/winnt4family_md.md)] e versões posteriores, o Windows 95 e versões posteriores, ou quando o estilo OFN_EXPLORER está presente.  
  
 [in] `lpWin3ID`  
 Contém o nome do recurso de modelo para o Gerenciador não- `CFileDialog` objeto. Este modelo é usado somente no Windows NT 3.51 ou quando o estilo OFN_EXPLORER não está presente.  
  
 [in] `lpWin4ID`  
 Contém o nome do recurso de modelo do Gerenciador de `CFileDialog` objeto. Este modelo é usado somente em [!INCLUDE[WinNt4Family](../../mfc/reference/includes/winnt4family_md.md)] e versões posteriores, o Windows 95 e versões posteriores, ou quando o estilo OFN_EXPLORER está presente.  
  
### <a name="remarks"></a>Comentários  
 O sistema usará apenas um dos modelos de especificado. O sistema determina qual modelo usar com base na presença de estilo OFN_EXPLORER e o sistema operacional que o aplicativo está em execução no. Especificando um não Explorer e o modelo de estilo do Explorer, é fácil de suporte do Windows NT 3.51, [!INCLUDE[WinNt4Family](../../mfc/reference/includes/winnt4family_md.md)] e versões posteriores e o Windows 95 e versões posteriores.  
  
> [!NOTE]
> Windows Vista ou posteriores caixas de diálogo de arquivo de estilo não dão suporte a essa função. Tentativa de usar essa função em um Windows Vista ou posterior caixa de diálogo de arquivo de estilo lançará [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md). Uma alternativa é usar uma caixa de diálogo personalizada. Para obter mais informações sobre como usar um personalizado `CFileDialog`, consulte [IFileDialogCustomize](http://msdn.microsoft.com/library/windows/desktop/bb775912).  
  
##  <a name="startvisualgroup"></a>  CFileDialog::StartVisualGroup  
 Declara um grupo visual na caixa de diálogo. As chamadas subsequentes para qualquer método "Adicionar" adicionam esses elementos para esse grupo.  
  
```  
HRESULT StartVisualGroup(
    DWORD dwIDCtl,  
    const CString& strLabel);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwIDCtl`  
 A ID do grupo de visual.  
  
 `strLabel`  
 O nome do grupo.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="updateofnfromshelldialog"></a>  CFileDialog::UpdateOFNFromShellDialog  
 Atualizações de `m_ofn` estrutura de dados do [CFileDialog](../../mfc/reference/cfiledialog-class.md) com base no estado atual do objeto interno.  
  
```  
void UpdateOFNFromShellDialog();
```  
  
### <a name="remarks"></a>Comentários  
 Em versões do Windows anteriores ao Windows Vista, o membro [OPENFILENAME](https://msdn.microsoft.com/library/ms911906.aspx) estrutura de dados continuamente foi sincronizada com o estado do `CFileDialog`. As alterações para o [m_ofn](#m_ofn) variável de membro diretamente afetado o estado da caixa de diálogo. Além disso, as alterações para o estado da caixa de diálogo atualizado imediatamente a variável de membro m_ofn.  
  
 No Windows Vista ou posterior, o `m_ofn` estrutura de dados não é atualizada automaticamente. Para garantir a precisão dos dados de `m_ofn` variável de membro, você deve chamar o `UpdateOFNFromShellDialog` função antes de acessar os dados. O Windows chama esta função automaticamente durante o processamento de [IFileDialog::OnFileOK](http://msdn.microsoft.com/library/windows/desktop/bb775879).  
  
 Para obter mais informações sobre como usar o `CFileDialog` classe no Windows Vista ou posterior, consulte [classe CFileDialog](../../mfc/reference/cfiledialog-class.md).  
  
### <a name="example"></a>Exemplo  
 Este exemplo atualiza o `CFileDialog` antes de exibi-lo. Antes de atualizar o `m_ofn` variável de membro, é necessário sincronizá-lo para o estado atual da caixa de diálogo.  
  
 [!code-cpp[NVC_MFC_CFileDialog#1](../../mfc/reference/codesnippet/cpp/cfiledialog-class_7.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

