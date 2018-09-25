---
title: 'Passo a passo: Adicionando um CTaskDialog a um aplicativo | Microsoft Docs'
ms.custom: ''
ms.date: 09/19/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CTaskDialog, adding
- walkthroughs [MFC], dialogs
ms.assetid: 3a62abb8-2d86-4bec-bdb8-5784d5f9a9f8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 48efa5d85ac6c7ba7e989cc55196f12fb391fa6d
ms.sourcegitcommit: edb46b0239a0e616af4ec58906e12338c3e8d2c6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2018
ms.locfileid: "47169717"
---
# <a name="walkthrough-adding-a-ctaskdialog-to-an-application"></a>Instruções passo a passo: adicionando um CTaskDialog a um aplicativo

Este passo a passo apresenta a [classe CTaskDialog](../mfc/reference/ctaskdialog-class.md) e mostra como adicionar uma ao seu aplicativo.

O `CTaskDialog` é uma caixa de diálogo de tarefa que substitui a caixa de mensagem do Windows no Windows Vista ou posterior. O `CTaskDialog` melhora a caixa de mensagem original e adiciona funcionalidade. Ainda há suporte para a caixa de mensagem do Windows no Visual Studio.

> [!NOTE]
> As versões do Windows anteriores ao Windows Vista não dão suporte a `CTaskDialog`. Se você quiser mostrar uma mensagem a um usuário que executa o seu aplicativo em uma versão anterior do Windows, você deve programar uma opção da caixa de diálogo alternativo. Você pode usar o método estático [CTaskDialog::IsSupported](../mfc/reference/ctaskdialog-class.md#issupported) para determinar no tempo de execução se o computador de um usuário pode exibir um `CTaskDialog`. Além disso, o `CTaskDialog` está disponível apenas quando seu aplicativo é compilado com a biblioteca Unicode.

O `CTaskDialog` dá suporte a vários elementos opcionais para coletar e exibir informações. Por exemplo, um `CTaskDialog` pode exibir os links de comando, botões personalizados, ícones personalizados e um rodapé. O `CTaskDialog` também tem vários métodos que permitem que você consultar o estado da caixa de diálogo de tarefa para determinar quais elementos opcionais o usuário selecionado.

## <a name="prerequisites"></a>Pré-requisitos

Você precisa dos seguintes componentes para concluir esta instrução passo a passo:

- Visual Studio 2010 ou posterior

- Windows Vista ou posterior

## <a name="replacing-a-windows-message-box-with-a-ctaskdialog"></a>Substituindo uma caixa de mensagem do Windows com um CTaskDialog

O procedimento a seguir demonstra o uso mais básico do `CTaskDialog`, que é substituir a caixa de mensagem do Windows. Este exemplo também altera o ícone associado a caixa de diálogo de tarefa. Alterando o ícone torna o `CTaskDialog` são idênticos a caixa de mensagem do Windows.

### <a name="to-replace-a-windows-message-box-with-a-ctaskdialog"></a>Para substituir uma caixa de mensagem do Windows com um CTaskDialog

1. Crie um novo projeto de aplicativo do MFC com as configurações padrão. Chamá-lo *MyProject*.

1. Use o **Gerenciador de soluções** para abrir o arquivo MyProject.cpp.

1. Adicionar `#include "afxtaskdialog.h"` depois que a lista de inclui.

1. Localize o método `CMyProjectApp::InitInstance`. Insira as seguintes linhas de código antes do `return TRUE;` instrução. Esse código cria as cadeias de caracteres que usamos na caixa de mensagem de Windows ou no `CTaskDialog`.

    ```cpp
    CString message("My message to the user");
    CString dialogTitle("My Task Dialog title");
    CString emptyString;
    ```

1. Adicione o seguinte código após o código da etapa 4. Esse código garante que o computador do usuário oferece suporte a `CTaskDialog`. Se não há suporte para a caixa de diálogo, o aplicativo exibe uma caixa de mensagem do Windows em vez disso.

    ```cpp
    if (CTaskDialog::IsSupported())
    {

    }
    else
    {
        AfxMessageBox(message);
    }
    ```

1. Insira o seguinte código entre colchetes após o `if` instrução da etapa 5. Esse código cria o `CTaskDialog`.

    ```cpp
    CTaskDialog taskDialog(message, emptyString, dialogTitle, TDCBF_OK_BUTTON);
    ```

1. Na próxima linha, adicione o código a seguir. Esse código define o ícone de aviso.

    ```cpp
    taskDialog.SetMainIcon(TD_WARNING_ICON);
    ```

1. Na próxima linha, adicione o código a seguir. Esse código exibe a caixa de diálogo de tarefa.

    ```cpp
    taskDialog.DoModal();
    ```

Você pode pular a etapa 7 se você não quiser que o `CTaskDialog` para exibir o ícone mesmo que a caixa de mensagem do Windows. Se você omitir essa etapa, o `CTaskDialog` tem um ícone quando o aplicativo for exibido.

Compile e execute o aplicativo. O aplicativo exibe a caixa de diálogo de tarefa depois de ter começado.

## <a name="adding-functionality-to-the-ctaskdialog"></a>Adicionando uma funcionalidade para a classe CTaskDialog

O procedimento a seguir mostra como adicionar funcionalidade para o `CTaskDialog` que você criou no procedimento anterior. O exemplo de código mostra como executar instruções específicas com base nas seleções do usuário.

### <a name="to-add-functionality-to-the-ctaskdialog"></a>Para adicionar funcionalidade para a classe CTaskDialog

1. Navegue até a **exibição de recurso**. Se você não conseguir ver a **exibição de recurso**, você pode abri-lo da **exibição** menu.

1. Expanda o **exibição de recurso** até que você pode selecionar a **tabela de cadeia de caracteres** pasta. Expandi-la e clique duas vezes o **tabela de cadeia de caracteres** entrada.

1. Role até a parte inferior da tabela de cadeia de caracteres e adicionar uma nova entrada. Alterar a ID para `TEMP_LINE1`. Definir a legenda para **linha de comando 1**.

1. Adicione outra entrada nova. Alterar a ID para `TEMP_LINE2`. Definir a legenda para **linha de comando 2**.

1. Navegue de volta para MyProject.cpp.

1. Depois de `CString emptyString;`, adicione o seguinte código:

    ```cpp
    CString expandedLabel("Hide extra information");
    CString collapsedLabel("Show extra information");
    CString expansionInfo("This is the additional information to the user,\nextended over two lines.");
    ```

1. Encontre o `taskDialog.DoModal()` declaração e substitua essa instrução com o código a seguir. Esse código atualiza a caixa de diálogo de tarefa e adiciona novos controles:

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

1. Adicione a seguinte linha de código que exibe a caixa de diálogo de tarefa para o usuário e recupera a seleção do usuário:

    ```cpp
    INT_PTR result = taskDialog.DoModal();
    ```

1. Insira o seguinte código após a chamada para `taskDialog.DoModal()`. Esta seção do código processa a entrada do usuário:

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

O código na etapa 9, substitua os comentários que começam com `PROCESS IF` com o código que você deseja executar nas condições especificadas.

Compile e execute o aplicativo. O aplicativo exibe a caixa de diálogo de tarefa que usa os novos controles e informações adicionais.

## <a name="displaying-a-ctaskdialog-without-creating-a-ctaskdialog-object"></a>Exibindo um CTaskDialog sem criar um objeto CTaskDialog

O procedimento a seguir mostra como exibir uma `CTaskDialog` sem primeiro criar um `CTaskDialog` objeto. Este exemplo continua procedimentos anteriores.

### <a name="to-display-a-ctaskdialog-without-creating-a-ctaskdialog-object"></a>Para exibir um CTaskDialog sem criar um objeto CTaskDialog

1. Abra o arquivo de MyProject.cpp se ele não ainda estiver aberto.

1. Navegue até o colchete de fechamento para o `if (CTaskDialog::IsSupported())` instrução.

1. Insira o seguinte código imediatamente antes do colchete de fechamento do `if` instrução (antes do `else` bloco):

    ```cpp
    HRESULT result2 = CTaskDialog::ShowDialog(L"My error message",
        L"Error",
        L"New Title",
        TEMP_LINE1,
        TEMP_LINE2);
    ```

Compile e execute o aplicativo. O aplicativo exibe duas caixas de diálogo de tarefa. A primeira caixa de diálogo é do **para adicionar funcionalidade para a classe CTaskDialog** procedimento; a segunda caixa de diálogo é do último procedimento.

Esses exemplos não demonstram todas as opções disponíveis para um `CTaskDialog`, mas deve ajudá-lo a começar. Ver [classe CTaskDialog](../mfc/reference/ctaskdialog-class.md) para obter uma descrição completa da classe.

## <a name="see-also"></a>Consulte também

[Caixas de diálogo](../mfc/dialog-boxes.md)<br/>
[Classe CTaskDialog](../mfc/reference/ctaskdialog-class.md)<br/>
[CTaskDialog::CTaskDialog](../mfc/reference/ctaskdialog-class.md#ctaskdialog)
