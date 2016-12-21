---
title: "Instru&#231;&#245;es passo a passo: adicionando um CTaskDialog a um aplicativo | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "CTaskDialog, adicionando"
  - "explicações passo a passo [C++], caixas de diálogo"
ms.assetid: 3a62abb8-2d86-4bec-bdb8-5784d5f9a9f8
caps.latest.revision: 6
caps.handback.revision: 2
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: adicionando um CTaskDialog a um aplicativo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este passo a passo apresenta a [Classe de CTaskDialog](../mfc/reference/ctaskdialog-class.md) e mostra como adicionar um ao seu aplicativo.  
  
 O `CTaskDialog` é uma caixa de diálogo de tarefa que substitui a caixa de mensagem do Windows em [!INCLUDE[wiprlhext](../c-runtime-library/reference/includes/wiprlhext_md.md)]. O `CTaskDialog` melhora a caixa de mensagem original e adiciona a funcionalidade. Ainda há suporte para a caixa de mensagem do Windows em [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)].  
  
> [!NOTE]
>  Versões do Windows anteriores ao [!INCLUDE[wiprlhext](../c-runtime-library/reference/includes/wiprlhext_md.md)] não oferecem suporte a `CTaskDialog`. Você deve programar uma opção de caixa de diálogo alternativa se você quiser mostrar uma mensagem a um usuário que executa o aplicativo em uma versão anterior do Windows. Você pode usar o método estático [CTaskDialog::IsSupported](../Topic/CTaskDialog::IsSupported.md) para determinar o tempo de execução se o computador de um usuário pode exibir um `CTaskDialog`. Além disso, o `CTaskDialog` está disponível apenas quando seu aplicativo é criado com a biblioteca de Unicode.  
  
 O `CTaskDialog` oferece suporte a vários elementos opcionais para coletar e exibir informações. Por exemplo, um `CTaskDialog` pode exibir os links de comando, botões personalizados, ícones personalizados e um rodapé. O `CTaskDialog` também tem vários métodos que permitem que você consultar o estado da caixa de diálogo de tarefa para determinar quais elementos opcionais o usuário selecionado.  
  
## Pré-requisitos  
 Você precisará dos seguintes componentes para concluir este passo a passo:  
  
-   [!INCLUDE[vs_dev10_long](../build/includes/vs_dev10_long_md.md)]  
  
-   [!INCLUDE[wiprlhext](../c-runtime-library/reference/includes/wiprlhext_md.md)]  
  
## Substituindo uma caixa de mensagem do Windows com um CTaskDialog  
 O procedimento a seguir demonstra o uso mais básico de `CTaskDialog`, que é substituir a caixa de mensagem do Windows. Este exemplo também altera o ícone associado a caixa de diálogo de tarefa. Alterar o ícone torna o `CTaskDialog` são idênticos a caixa de mensagem do Windows.  
  
#### Para substituir uma caixa de mensagem do Windows com um CTaskDialog  
  
1.  Crie um novo projeto de aplicativo MFC com as configurações padrão. Chamar `MyProject`.  
  
2.  Use o **Solution Explorer** para abrir o arquivo MyProject.cpp.  
  
3.  Adicionar `#include "afxtaskdialog.h"` depois que a lista de inclui.  
  
4.  Localize o método `CMyProjectApp::InitInstance`. Insira as seguintes linhas de código antes do `return TRUE;` instrução. Esse código cria as cadeias de caracteres que podemos usar a caixa de mensagem de Windows ou na `CTaskDialog`.  
  
    ```  
    CString message("My message to the user");  
    CString dialogTitle("My Task Dialog title");  
    CString emptyString;  
    ```  
  
5.  Adicione o código a seguir após o código da etapa 4. Este código garante que o computador do usuário oferece suporte a `CTaskDialog`. Se a caixa de diálogo não tiver suporte, o aplicativo exibe uma caixa de mensagem do Windows.  
  
    ```  
    if (CTaskDialog::IsSupported())  
    {  
  
    }  
    else  
    {  
       AfxMessageBox(message);  
    }  
    ```  
  
6.  Insira o seguinte código entre colchetes após o `if` instrução da etapa 5. Esse código cria o `CTaskDialog`.  
  
    ```  
    CTaskDialog taskDialog(message, emptyString, dialogTitle, TDCBF_OK_BUTTON);  
    ```  
  
7.  Na próxima linha, adicione o código a seguir. Esse código define o ícone de aviso.  
  
    ```  
    taskDialog.SetMainIcon(TD_WARNING_ICON);  
    ```  
  
8.  Na próxima linha, adicione o código a seguir. Esse código exibe a caixa de diálogo de tarefa.  
  
    ```  
    taskDialog.DoModal();  
    ```  
  
 Você pode pular a etapa 7 se você não quiser que o `CTaskDialog` para exibir o ícone mesmo que a caixa de mensagem do Windows. Se você omitir essa etapa, o `CTaskDialog` tem um ícone quando o aplicativo for exibido.  
  
 Compilar e executar o aplicativo. O aplicativo exibirá a caixa de diálogo de tarefa após ele ser iniciado.  
  
## Adicionando funcionalidade a CTaskDialog  
 O procedimento a seguir mostra como adicionar funcionalidade a `CTaskDialog` que você criou no procedimento anterior. O exemplo de código mostra como executar instruções específicas com base nas seleções do usuário.  
  
#### Para adicionar funcionalidade ao CTaskDialog  
  
1.  Navegue até o **exibição recurso**. Se você não vir o **exibição recursos**, você pode abri\-la no **exibição** menu.  
  
2.  Expanda o **exibição recursos** até que você pode selecionar o **tabela de cadeia de caracteres** pasta. Expandi\-la e clique duas vezes o **tabela de cadeia de caracteres** entrada.  
  
3.  Role até a parte inferior da tabela de cadeia de caracteres e adicionar uma nova entrada. Altere a ID para `TEMP_LINE1`. Definir a legenda para **1 de linha de comando**.  
  
4.  Adicione outra nova entrada. Altere a ID para `TEMP_LINE2`. Definir a legenda para **2 de linha de comando**.  
  
5.  Navegue até MyProject.cpp.  
  
6.  Depois de `CString emptyString;`, adicione o seguinte código:  
  
    ```  
    CString expandedLabel("Hide extra information");  
    CString collapsedLabel("Show extra information");  
    CString expansionInfo("This is the additional information to the user,\nextended over two lines.");  
    ```  
  
7.  Encontre o `taskDialog.DoModal()` instrução e substitua essa instrução com o código a seguir. Esse código atualiza a caixa de diálogo de tarefa e adiciona novos controles:  
  
    ```  
    taskDialog.SetMainInstruction(L"Warning");  
    taskDialog.SetCommonButtons(TDCBF_YES_BUTTON | TDCBF_NO_BUTTON | TDCBF_CANCEL_BUTTON);  
    taskDialog.LoadCommandControls(TEMP_LINE1, TEMP_LINE2);  
    taskDialog.SetExpansionArea(expansionInfo, collapsedLabel, expandedLabel);  
    taskDialog.SetFooterText(L"This is the a small footnote to the user");  
    taskDialog.SetVerificationCheckboxText(L"Remember your selection");  
    ```  
  
8.  Adicione a seguinte linha de código que exibe a caixa de diálogo de tarefa para o usuário e recupera a seleção do usuário:  
  
    ```  
    INT_PTR result = taskDialog.DoModal();  
    ```  
  
9. Insira o seguinte código após a chamada para `taskDialog.DoModal()`. Esta seção do código processa a entrada do usuário:  
  
    ```  
    if (taskDialog.GetVerificationCheckboxState() )  
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
          // This case should not be hit because closing the dialog box results in IDCANCEL  
          break;  
    }  
    ```  
  
 No código na etapa 9, substitua os comentários que começam com o processo se com o código que você deseja executar sob as condições especificadas.  
  
 Compilar e executar o aplicativo. O aplicativo exibe a caixa de diálogo de tarefa que usa os novos controles e informações adicionais.  
  
## Exibindo um CTaskDialog sem criar um objeto CTaskDialog  
 O procedimento a seguir mostra como exibir um `CTaskDialog` sem primeiro criar uma `CTaskDialog` objeto. Este exemplo continua procedimentos anteriores.  
  
#### Para exibir um CTaskDialog sem criar um objeto CTaskDialog  
  
1.  Abra o arquivo MyProject.cpp se ele não ainda estiver aberto.  
  
2.  Navegue até o colchete de fechamento para o `if (CTaskDialog::IsSupported())` instrução.  
  
3.  Insira o seguinte código imediatamente antes do colchete de fechamento do `if` instrução \(antes do `else` bloco\):  
  
    ```  
    HRESULT result2 = CTaskDialog::ShowDialog(L"My error message", L"Error", L"New Title", TEMP_LINE1, TEMP_LINE2);  
    ```  
  
 Compilar e executar o aplicativo. O aplicativo exibe duas caixas de diálogo de tarefa. A primeira caixa de diálogo é para adicionar funcionalidade ao procedimento CTaskDialog; a segunda caixa de diálogo é do último procedimento.  
  
 Esses exemplos não demonstram todas as opções disponíveis para um `CTaskDialog`, mas deve ajudá\-lo a começar. Consulte [Classe de CTaskDialog](../mfc/reference/ctaskdialog-class.md) para obter uma descrição completa da classe.  
  
## Consulte também  
 [Caixas de diálogo](../mfc/dialog-boxes.md)   
 [Classe de CTaskDialog](../mfc/reference/ctaskdialog-class.md)   
 [CTaskDialog::CTaskDialog](../Topic/CTaskDialog::CTaskDialog.md)