---
title: 'Passo a passo: Adicionando um CTaskDialog a um aplicativo | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 2e8e6c7d5f8144b2aec6c7783680feeff5f6f8a1
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36951618"
---
# <a name="walkthrough-adding-a-ctaskdialog-to-an-application"></a>Instruções passo a passo: adicionando um CTaskDialog a um aplicativo
Este passo a passo apresenta a [CTaskDialog classe](../mfc/reference/ctaskdialog-class.md) e mostra como adicionar um ao seu aplicativo.  
  
 O `CTaskDialog` é uma caixa de diálogo de tarefa que substitui a caixa de mensagem do Windows no Windows Vista ou posterior. O `CTaskDialog` melhora a caixa de mensagem original e adiciona a funcionalidade. Ainda há suporte para a caixa de mensagem do Windows no Visual Studio.  
  
> [!NOTE]
> Versões do Windows anteriores ao Windows Vista não dão suporte a `CTaskDialog`. Se você quiser mostrar uma mensagem para um usuário que executa o aplicativo em uma versão anterior do Windows, você deve programar uma opção da caixa de diálogo alternativo. Você pode usar o método estático [CTaskDialog::IsSupported](../mfc/reference/ctaskdialog-class.md#issupported) para determinar o tempo de execução se o computador de um usuário pode exibir um `CTaskDialog`. Além disso, o `CTaskDialog` só está disponível quando o aplicativo é compilado com a biblioteca de Unicode.  
  
 O `CTaskDialog` oferece suporte a vários elementos opcionais para coletar e exibir informações. Por exemplo, um `CTaskDialog` pode exibir os links de comando, botões personalizados, ícones personalizados e um rodapé. O `CTaskDialog` também tem vários métodos que permitem que você consultar o estado da caixa de diálogo de tarefas para determinar quais elementos opcionais o usuário selecionado.  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Você precisa dos seguintes componentes para concluir esta instrução passo a passo:  
  
- Visual Studio 2010 ou posterior  
  
- Windows Vista ou posterior  
  
## <a name="replacing-a-windows-message-box-with-a-ctaskdialog"></a>Substituindo uma caixa de mensagem do Windows com um CTaskDialog  
 O procedimento a seguir demonstra o uso mais básico de `CTaskDialog`, que é substituir a caixa de mensagem do Windows. Este exemplo também altera o ícone associado a caixa de diálogo. Alterar o ícone torna o `CTaskDialog` são idênticos a caixa de mensagem do Windows.  
  
#### <a name="to-replace-a-windows-message-box-with-a-ctaskdialog"></a>Para substituir uma caixa de mensagem do Windows com um CTaskDialog  
  
1.  Crie um novo projeto de aplicativo MFC com as configurações padrão. Chamá-lo *MyProject*.  
  
2.  Use o **Solution Explorer** para abrir o arquivo MyProject.cpp.  
  
3.  Adicionar `#include "afxtaskdialog.h"` depois que a lista de inclui.  
  
4.  Localizar o método `CMyProjectApp::InitInstance`. Insira as seguintes linhas de código antes do `return TRUE;` instrução. Esse código cria as cadeias de caracteres, use a caixa de mensagem Windows ou no `CTaskDialog`.  
  
 ```  
    CString message("My message to the user");

    CString dialogTitle("My Task Dialog title");

    CString emptyString;  
 ```  
  
5.  Adicione o seguinte código após o código da etapa 4. Esse código garante que o computador do usuário oferece suporte a `CTaskDialog`. Se não há suporte para a caixa de diálogo, o aplicativo exibe uma caixa de mensagem do Windows.  
  
 ```  
    if (CTaskDialog::IsSupported())  
 {  
 
 }  
    else 
 {  
    AfxMessageBox(message);

 }  
 ```  
  
6.  Insira o seguinte código entre parênteses após o **se** instrução da etapa 5. Esse código cria o `CTaskDialog`.  
  
 ```  
    CTaskDialog taskDialog(message,
    emptyString,
    dialogTitle,
    TDCBF_OK_BUTTON);

 ```  
  
7.  Na próxima linha, adicione o código a seguir. Esse código define o ícone de aviso.  
  
 ```  
    taskDialog.SetMainIcon(TD_WARNING_ICON);

 ```  
  
8.  Na próxima linha, adicione o código a seguir. Este código exibe a caixa de diálogo.  
  
 ```  
    taskDialog.DoModal();

 ```  
  
 Você pode pular a etapa 7 se você não quiser que o `CTaskDialog` para exibir o ícone mesmo que a caixa de mensagem do Windows. Se você omitir essa etapa, o `CTaskDialog` tem um ícone quando o aplicativo for exibido.  
  
 Compile e execute o aplicativo. O aplicativo exibe a caixa de diálogo após ele ser iniciado.  
  
## <a name="adding-functionality-to-the-ctaskdialog"></a>Adicionando funcionalidade para o CTaskDialog  
 O procedimento a seguir mostra como adicionar funcionalidade a `CTaskDialog` que você criou no procedimento anterior. O exemplo de código mostra como executar instruções específicas com base nas seleções do usuário.  
  
#### <a name="to-add-functionality-to-the-ctaskdialog"></a>Para adicionar funcionalidade ao CTaskDialog  
  
1.  Navegue até o **exibição recursos**. Se você não conseguir ver o **exibição recursos**, você pode abri-lo no **exibição** menu.  
  
2.  Expanda o **exibição recursos** até que você pode selecionar o **tabela de cadeia de caracteres** pasta. Expandi-lo e clique duas vezes o **tabela de cadeia de caracteres** entrada.  
  
3.  Role até a parte inferior da tabela de cadeia de caracteres e adicionar uma nova entrada. Alterar a ID para *TEMP_LINE1*. Definir a legenda para *1 linha de comando*.  
  
4.  Adicione nova entrada de outra. Alterar a ID para *TEMP_LINE2*. Definir a legenda para *2 de linha de comando*.  
  
5.  Navegue de volta para MyProject.cpp.  
  
6.  Depois de `CString emptyString;`, adicione o seguinte código:  
  
 ```  
    CString expandedLabel("Hide extra information");

    CString collapsedLabel("Show extra information");

    CString expansionInfo("This is the additional information to the user,\nextended over two lines.");

 ```  
  
7.  Localizar o `taskDialog.DoModal()` instrução e substitua essa instrução com o código a seguir. Esse código atualiza a caixa de diálogo de tarefa e adiciona novos controles:  
  
 ```  
    taskDialog.SetMainInstruction(L"Warning");

 taskDialog.SetCommonButtons(TDCBF_YES_BUTTON | TDCBF_NO_BUTTON | TDCBF_CANCEL_BUTTON);

    taskDialog.LoadCommandControls(TEMP_LINE1,
    TEMP_LINE2);

    taskDialog.SetExpansionArea(expansionInfo,
    collapsedLabel,
    expandedLabel);

    taskDialog.SetFooterText(L"This is the a small footnote to the user");

    taskDialog.SetVerificationCheckboxText(L"Remember your selection");

 ```  
  
8.  Adicione a seguinte linha de código que exibe a caixa de diálogo para o usuário e recupera a seleção do usuário:  
  
 ```  
    INT_PTR result = taskDialog.DoModal();

 ```  
  
9. Insira o seguinte código após a chamada a `taskDialog.DoModal()`. Esta seção do código processa a entrada do usuário:  
  
 ```  
    if (taskDialog.GetVerificationCheckboxState())  
 { *// PROCESS IF the user selects the verification checkbox   
 }  
 
    switch (result)  
 {  
    case TEMP_LINE1: *// PROCESS IF the first command line  
    break; 
    case TEMP_LINE2: *// PROCESS IF the second command line  
    break; 
    case IDYES: *// PROCESS IF the user clicks yes  
    break; 
    case IDNO: *// PROCESS IF the user clicks no  
    break; 
    case IDCANCEL: *// PROCESS IF the user clicks cancel  
    break; 
    default: *// This case should not be hit because closing the dialog box results in IDCANCEL  
    break; 
 }  
 ```  
  
 No código da etapa 9, substitua os comentários que começam com o processo se com o código que você deseja executar sob as condições especificadas.  
  
 Compile e execute o aplicativo. O aplicativo exibe a caixa de diálogo de tarefa que usa os novos controles e informações adicionais.  
  
## <a name="displaying-a-ctaskdialog-without-creating-a-ctaskdialog-object"></a>Exibindo um CTaskDialog sem criar um objeto CTaskDialog  
 O procedimento a seguir mostra como exibir um `CTaskDialog` sem primeiro criar uma `CTaskDialog` objeto. Este exemplo continua procedimentos anteriores.  
  
#### <a name="to-display-a-ctaskdialog-without-creating-a-ctaskdialog-object"></a>Para exibir um CTaskDialog sem criar um objeto CTaskDialog  
  
1.  Abra o arquivo MyProject.cpp se ele não ainda estiver aberto.  
  
2.  Navegue até o colchete de fechamento para o `if (CTaskDialog::IsSupported())` instrução.  
  
3.  Insira o seguinte código imediatamente antes do colchete de fechamento do **se** instrução (antes do **else** bloco):  
  
 ```  
    HRESULT result2 = CTaskDialog::ShowDialog(L"My error message",
    L"Error",
    L"New Title",
    TEMP_LINE1,
    TEMP_LINE2);

 ```  
  
 Compile e execute o aplicativo. O aplicativo exibe duas caixas de diálogo de tarefa. A primeira caixa de diálogo é de para adicionar funcionalidade ao procedimento CTaskDialog; é a segunda caixa de diálogo do último procedimento.  
  
 Esses exemplos demonstram não todas as opções disponíveis para um `CTaskDialog`, mas deve ajudá-lo a começar. Consulte [CTaskDialog classe](../mfc/reference/ctaskdialog-class.md) para obter uma descrição completa da classe.  
  
## <a name="see-also"></a>Consulte também  
 [Caixas de diálogo](../mfc/dialog-boxes.md)   
 [Classe CTaskDialog](../mfc/reference/ctaskdialog-class.md)   
 [CTaskDialog::CTaskDialog](../mfc/reference/ctaskdialog-class.md#ctaskdialog)

