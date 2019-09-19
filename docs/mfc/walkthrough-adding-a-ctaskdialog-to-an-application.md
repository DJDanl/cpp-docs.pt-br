---
title: 'Passo a passo: Adicionando um CTaskDialog a um aplicativo'
ms.date: 04/25/2019
helpviewer_keywords:
- CTaskDialog, adding
- walkthroughs [MFC], dialogs
ms.assetid: 3a62abb8-2d86-4bec-bdb8-5784d5f9a9f8
ms.openlocfilehash: 1a46cc7681a2556aee8e856be6ce1fd7cc01686a
ms.sourcegitcommit: 2f96e2fda591d7b1b28842b2ea24e6297bcc3622
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2019
ms.locfileid: "71096022"
---
# <a name="walkthrough-adding-a-ctaskdialog-to-an-application"></a>Passo a passo: Adicionando um CTaskDialog a um aplicativo

Este tutorial apresenta a [classe CTaskDialog](../mfc/reference/ctaskdialog-class.md) e mostra como adicionar uma ao seu aplicativo.

A `CTaskDialog` é uma caixa de diálogo de tarefa que substitui a caixa de mensagem do Windows no Windows Vista ou posterior. O `CTaskDialog` melhora a caixa de mensagem original e adiciona a funcionalidade. A caixa de mensagem do Windows ainda tem suporte no Visual Studio.

> [!NOTE]
> As versões do Windows anteriores ao Windows Vista não dão suporte `CTaskDialog`ao. Você deve programar uma opção de caixa de diálogo alternativa se desejar mostrar uma mensagem para um usuário que executa o aplicativo em uma versão anterior do Windows. Você pode usar o método estático [CTaskDialog:: IsSupported](../mfc/reference/ctaskdialog-class.md#issupported) para determinar em tempo de execução se o computador de um usuário pode `CTaskDialog`exibir um. Além disso, o `CTaskDialog` está disponível apenas quando seu aplicativo é compilado com a biblioteca Unicode.

O `CTaskDialog` oferece suporte a vários elementos opcionais para coletar e exibir informações. Por exemplo, um `CTaskDialog` pode exibir links de comando, botões personalizados, ícones personalizados e um rodapé. O `CTaskDialog` também tem vários métodos que permitem consultar o estado da caixa de diálogo da tarefa para determinar quais elementos opcionais o usuário selecionou.

## <a name="prerequisites"></a>Pré-requisitos

Você precisa dos seguintes componentes para concluir esta instrução passo a passo:

- Visual Studio 2010 ou posterior

- Windows Vista ou posterior

## <a name="replacing-a-windows-message-box-with-a-ctaskdialog"></a>Substituindo uma caixa de mensagem do Windows por um CTaskDialog

O procedimento a seguir demonstra o uso mais básico do `CTaskDialog`, que é substituir a caixa de mensagem do Windows. Este exemplo também altera o ícone associado à caixa de diálogo de tarefa. A alteração do ícone faz `CTaskDialog` com que a aparência apareça na caixa de mensagem do Windows.

### <a name="to-replace-a-windows-message-box-with-a-ctaskdialog"></a>Para substituir uma caixa de mensagem do Windows por um CTaskDialog

1. Use o **Assistente de aplicativo MFC** para criar um aplicativo MFC com todas as configurações padrão. Confira [Passo a passo: Usando os novos controles](walkthrough-using-the-new-mfc-shell-controls.md) do shell do MFC para obter instruções sobre como abrir o assistente para sua versão do Visual Studio.

1. Chame *MyProject*.

1. Use o **Gerenciador de soluções** para abrir o arquivo myproject. cpp.

1. Adicione `#include "afxtaskdialog.h"` após a lista de inclusões.

1. Localize o método `CMyProjectApp::InitInstance`. Insira as linhas de código a seguir antes `return TRUE;` da instrução. Esse código cria as cadeias de caracteres que usamos na caixa de mensagem do Windows ou `CTaskDialog`no.

    ```cpp
    CString message("My message to the user");
    CString dialogTitle("My Task Dialog title");
    CString emptyString;
    ```

1. Adicione o código a seguir após o código da etapa 4. Esse código garante que o computador do usuário dê suporte `CTaskDialog`ao. Se o diálogo não tiver suporte, o aplicativo exibirá uma caixa de mensagem do Windows em vez disso.

    ```cpp
    if (CTaskDialog::IsSupported())
    {

    }
    else
    {
        AfxMessageBox(message);
    }
    ```

1. Insira o código a seguir entre colchetes após a `if` instrução da etapa 5. Esse código cria o `CTaskDialog`.

    ```cpp
    CTaskDialog taskDialog(message, emptyString, dialogTitle, TDCBF_OK_BUTTON);
    ```

1. Na próxima linha, adicione o código a seguir. Esse código define o ícone de aviso.

    ```cpp
    taskDialog.SetMainIcon(TD_WARNING_ICON);
    ```

1. Na próxima linha, adicione o código a seguir. Esse código exibe a caixa de diálogo tarefa.

    ```cpp
    taskDialog.DoModal();
    ```

Você pode evitar a etapa 7 se não quiser que `CTaskDialog` o exiba o mesmo ícone da caixa de mensagem do Windows. Se você evitar essa etapa, o `CTaskDialog` não terá nenhum ícone quando o aplicativo o exibir.

Compile e execute o aplicativo. O aplicativo exibe a caixa de diálogo de tarefa depois de iniciar.

## <a name="adding-functionality-to-the-ctaskdialog"></a>Adicionando funcionalidade ao CTaskDialog

O procedimento a seguir mostra como adicionar funcionalidade ao `CTaskDialog` que você criou no procedimento anterior. O código de exemplo mostra como executar instruções específicas com base nas seleções do usuário.

### <a name="to-add-functionality-to-the-ctaskdialog"></a>Para adicionar funcionalidade ao CTaskDialog

1. Navegue até a **modo de exibição de recursos**. Se você não conseguir ver a **modo de exibição de recursos**, poderá abri-la no menu **Exibir** .

1. Expanda a **modo de exibição de recursos** até que você possa selecionar a pasta da **tabela de cadeia de caracteres** . Expanda-o e clique duas vezes na entrada da **tabela de cadeia de caracteres** .

1. Role até a parte inferior da tabela de cadeia de caracteres e adicione uma nova entrada. Altere a ID para `TEMP_LINE1`. Defina a legenda para a **linha de comando 1**.

1. Adicione outra entrada nova. Altere a ID para `TEMP_LINE2`. Defina a legenda para a **linha de comando 2**.

1. Navegue de volta para MyProject. cpp.

1. Depois `CString emptyString;`, adicione o seguinte código:

    ```cpp
    CString expandedLabel("Hide extra information");
    CString collapsedLabel("Show extra information");
    CString expansionInfo("This is the additional information to the user,\nextended over two lines.");
    ```

1. Localize a `taskDialog.DoModal()` instrução e substitua essa instrução pelo código a seguir. Esse código atualiza a caixa de diálogo de tarefas e adiciona novos controles:

    ```cpp
    taskDialog.SetMainInstruction(L"Warning");
    taskDialog.SetCommonButtons(
        TDCBF_YES_BUTTON | TDCBF_NO_BUTTON | TDCBF_CANCEL_BUTTON);
    taskDialog.LoadCommandControls(TEMP_LINE1, TEMP_LINE2);
    taskDialog.SetExpansionArea(
        expansionInfo, collapsedLabel, expandedLabel);
    taskDialog.SetFooterText(L"This is the a small footnote to the user");
    taskDialog.SetVerificationCheckboxText(L"Remember your selection");
    ```

1. Adicione a seguinte linha de código que exibe a caixa de diálogo de tarefa ao usuário e recupera a seleção do usuário:

    ```cpp
    INT_PTR result = taskDialog.DoModal();
    ```

1. Insira o código a seguir após a chamada `taskDialog.DoModal()`para. Esta seção de código processa a entrada do usuário:

    ```cpp
    if (taskDialog.GetVerificationCheckboxState())
    {
        // PROCESS IF the user selects the verification checkbox
    }

    switch (result)
    {
    case TEMP_LINE1:
        // PROCESS IF the first command line
        break;
    case TEMP_LINE2:
        // PROCESS IF the second command line
        break;
    case IDYES:
        // PROCESS IF the user clicks yes
        break;
    case IDNO:
        // PROCESS IF the user clicks no
        break;
    case IDCANCEL:
        // PROCESS IF the user clicks cancel
        break;
    default:
        // This case should not be hit because closing
        // the dialog box results in IDCANCEL
        break;
    }
    ```

No código na etapa 9, substitua os comentários que começam com `PROCESS IF` com o código que você deseja executar nas condições especificadas.

Compile e execute o aplicativo. O aplicativo exibe a caixa de diálogo de tarefa que usa os novos controles e informações adicionais.

## <a name="displaying-a-ctaskdialog-without-creating-a-ctaskdialog-object"></a>Exibindo um CTaskDialog sem criar um objeto CTaskDialog

O procedimento a seguir mostra como exibir um `CTaskDialog` sem primeiro criar um `CTaskDialog` objeto. Este exemplo continua os procedimentos anteriores.

### <a name="to-display-a-ctaskdialog-without-creating-a-ctaskdialog-object"></a>Para exibir um CTaskDialog sem criar um objeto CTaskDialog

1. Abra o arquivo myproject. cpp se ele ainda não estiver aberto.

1. Navegue até o colchete `if (CTaskDialog::IsSupported())` de fechamento da instrução.

1. Insira o código a seguir imediatamente antes do colchete de fechamento `if` da instrução (antes `else` do bloco):

    ```cpp
    HRESULT result2 = CTaskDialog::ShowDialog(L"My error message",
        L"Error",
        L"New Title",
        TEMP_LINE1,
        TEMP_LINE2);
    ```

Compile e execute o aplicativo. O aplicativo exibe duas caixas de diálogo de tarefas. A primeira caixa de diálogo é do **para adicionar funcionalidade ao procedimento CTaskDialog** ; a segunda caixa de diálogo é do último procedimento.

Esses exemplos não demonstram todas as opções disponíveis para `CTaskDialog`um, mas devem ajudá-lo a começar. Consulte a [classe CTaskDialog](../mfc/reference/ctaskdialog-class.md) para obter uma descrição completa da classe.

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](../mfc/dialog-boxes.md)<br/>
[Classe CTaskDialog](../mfc/reference/ctaskdialog-class.md)<br/>
[CTaskDialog::CTaskDialog](../mfc/reference/ctaskdialog-class.md#ctaskdialog)
