---
title: "Instru&#231;&#245;es passo a passo: criando e usando uma biblioteca est&#225;tica (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "bibliotecas [C++], estáticas"
  - "bibliotecas estáticas [C++]"
ms.assetid: 3cc36411-7d66-4240-851e-dacb9a8fd6ac
caps.latest.revision: 38
caps.handback.revision: 38
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: criando e usando uma biblioteca est&#225;tica (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este passo a passo mostra como criar uma biblioteca estática \(arquivo. lib\) para uso com aplicativos do C\+\+. Usando uma biblioteca estática é uma ótima maneira de reutilizar o código. Em vez de reimplementar as mesmas rotinas em cada aplicativo que exija a funcionalidade, você escrevê\-los uma vez em uma biblioteca estática e, em seguida, fazer referência a ela, dos aplicativos. Vinculado a partir de uma biblioteca estática de código se torna parte do seu aplicativo, você não precisa instalar outro arquivo para usar o código.  
  
 Este passo a passo apresenta estas tarefas:  
  
-   [Criando um projeto de biblioteca estática](#BKMK_CreateLibProject)  
  
-   [Adicionando uma classe para a biblioteca estática](#BKMK_AddClassToLib)  
  
-   [Criar um aplicativo de console do C++ que faz referência a biblioteca estática](#BKMK_CreateAppToRefTheLib)  
  
-   [Usando a funcionalidade da biblioteca estática no aplicativo](#BKMK_UseLibInApp)  
  
-   [Executando o aplicativo](#BKMK_RunApp)  
  
## Pré-requisitos  
 Noções básicas sobre os conceitos básicos da linguagem C\+\+.  
  
##  <a name="BKMK_CreateLibProject"></a> Criando um projeto de biblioteca estática  
  
#### Para criar um projeto de biblioteca estática  
  
1.  Na barra de menus, escolha **arquivo**, **novo**, **projeto**.  
  
2.  No painel esquerdo do **novo projeto** caixa de diálogo caixa, expanda **instalados**, **modelos**, **Visual C\+\+**, e, em seguida, selecione **Win32**.  
  
3.  No painel central, selecione **aplicativo do Console Win32**.  
  
4.  Especifique um nome para o projeto — por exemplo, **MathFuncsLib**— no **nome** caixa. Especifique um nome para a solução — por exemplo, **StaticLibrary**— no **nome da solução** caixa. Escolha o botão **OK**.  
  
5.  No **Visão geral** página do **Win32 Application Wizard** caixa de diálogo, escolha o **próximo** botão.  
  
6.  Sobre o **configurações do aplicativo** página em **tipo de aplicativo**, selecione **biblioteca estática.**  
  
7.  Sobre o **configurações do aplicativo** página, em **Opções adicionais**, desmarque o **cabeçalho pré\-compilado** caixa de seleção.  
  
8.  Escolha o **Concluir** botão para criar o projeto.  
  
##  <a name="BKMK_AddClassToLib"></a> Adicionando uma classe para a biblioteca estática  
  
#### Para adicionar uma classe para a biblioteca estática  
  
1.  Para criar um arquivo de cabeçalho para uma nova classe, abra o menu de atalho para o **MathFuncsLib** project no **Solution Explorer**, e, em seguida, escolha **Add**, **Novo Item**. No **Add New Item** caixa de diálogo, no painel esquerdo, em **Visual C\+\+**, selecione **código**. No painel central, selecione **arquivo de cabeçalho \(. h\)**. Especifique um nome para o arquivo de cabeçalho — por exemplo, **MathFuncsLib.h**— e, em seguida, escolha o **Add** botão. Um arquivo de cabeçalho em branco é exibido.  
  
2.  Adicione uma classe chamada **MyMathFuncs** fazer operações matemáticas comuns, como adição, subtração, multiplicação e divisão. O código deve ter esta aparência:  
  
     [!CODE [NVC_Walkthrough_Create_Static_Lib#100](../CodeSnippet/VS_Snippets_Cpp/nvc_walkthrough_create_static_lib#100)]  
  
3.  Para criar um arquivo de origem para a nova classe, abra o menu de atalho para o **MathFuncsLib** project no **Solution Explorer**, e, em seguida, escolha **Add**, **Novo Item**. No **Add New Item** caixa de diálogo, no painel esquerdo, em **Visual C\+\+**, selecione **código**. No painel central, selecione **arquivo C\+\+ \(. cpp\)**. Especifique um nome para o arquivo de origem — por exemplo, **MathFuncsLib.cpp**— e, em seguida, escolha o **Add** botão. Um arquivo de origem em branco é exibido.  
  
4.  Usar esse arquivo de origem para implementar a funcionalidade de **MyMathFuncs**. O código deve ter esta aparência:  
  
     [!CODE [NVC_Walkthrough_Create_Static_Lib#110](../CodeSnippet/VS_Snippets_Cpp/nvc_walkthrough_create_static_lib#110)]  
  
5.  Compilar a biblioteca estática selecionando **criar**, **Build Solution** na barra de menus. Isso cria uma biblioteca estática que pode ser usada por outros programas.  
  
    > [!NOTE]
    >  Quando você compila na linha de comando do Visual Studio, você deve compilar o programa em duas etapas. Primeiro, execute **cl \/c \/EHsc MathFuncsLib.cpp** para compilar o código e criar um arquivo de objeto que é nomeado **MathFuncsLib.obj**. \(O **cl** comando invoca o compilador, Cl.exe e o **\/c** opção especifica compilar sem vinculação. Para obter mais informações, consulte [\/c \(compilar sem vinculação\)](../build/reference/c-compile-without-linking.md).\) Segundo, executam **lib MathFuncsLib.obj** para vincular o código e criar a biblioteca estática **MathFuncsLib.lib**. \(O **lib** comando invoca o Gerenciador de biblioteca Lib.exe. Para obter mais informações, consulte [Referência LIB](../build/reference/lib-reference.md).\)  
  
##  <a name="BKMK_CreateAppToRefTheLib"></a> Criar um aplicativo de console do C\+\+ que faz referência a biblioteca estática  
  
#### Para criar um aplicativo de console do C\+\+ que faz referência a biblioteca estática  
  
1.  Na barra de menus, escolha **arquivo**, **novo**, **projeto**.  
  
2.  No painel esquerdo, em **Visual C\+\+**, selecione **Win32**.  
  
3.  No painel central, selecione **aplicativo do Console Win32**.  
  
4.  Especifique um nome para o projeto — por exemplo, **MyExecRefsLib**— no **nome** caixa. Na lista suspensa lista próxima de **solução**, selecione **Adicionar à solução**. Isso adiciona o novo projeto para a solução que contém a biblioteca estática. Escolha o botão **OK**.  
  
5.  No **Visão geral** página do **Win32 Application Wizard** caixa de diálogo, escolha o **próximo** botão.  
  
6.  Sobre o **configurações do aplicativo** página em **tipo de aplicativo**, selecione **aplicativo de Console**.  
  
7.  Sobre o **configurações do aplicativo** página, em **Opções adicionais**, desmarque o **cabeçalho pré\-compilado** caixa de seleção.  
  
8.  Escolha o **Concluir** botão para criar o projeto.  
  
##  <a name="BKMK_UseLibInApp"></a> Usando a funcionalidade da biblioteca estática no aplicativo  
  
#### Para usar a funcionalidade da biblioteca estática no aplicativo  
  
1.  Depois de criar um aplicativo de console, um programa vazio é criado para você. O nome do arquivo de origem é igual ao nome que você escolheu anteriormente. Neste exemplo, ele é chamado **MyExecRefsLib.cpp**.  
  
2.  Antes de usar as rotinas de matemática na biblioteca estática, você deve fazer referência a ele. Para fazer isso, abra o menu de atalho para o **MyExecRefsLib** project no **Solution Explorer**, e, em seguida, escolha **referências**. No **MyExecRefsLib páginas de propriedade** caixa de diálogo caixa, expanda o **Propriedades comuns** nó, selecione **estrutura e referências**, e, em seguida, escolha o **Adicionar nova referência** botão.  Para obter mais informações sobre o **referências** caixa de diálogo, consulte [Adicionando referências](../ide/adding-references-in-visual-cpp-projects.md).  
  
3.  O **Adicionar referência** caixa de diálogo lista as bibliotecas que você pode fazer referência. O **projetos** guia lista os projetos na solução atual e todas as bibliotecas que eles contêm. No **projetos** guia, selecione o **MathFuncsLib** caixa de seleção e, em seguida, escolha o **OK** botão.  
  
4.  A referência a **MathFuncsLib.h** arquivo de cabeçalho, você deve modificar os caminhos dos diretórios incluídos. No **páginas de propriedade** caixa de diálogo **MyExecRefsLib**, expanda o **Propriedades de configuração** nó, expanda o **C\/C\+\+** nó e selecione **geral**. Lado **diretórios de inclusão adicionais**, especifique o caminho da **MathFuncsLib** diretório ou procurar por ele.  
  
     Para procurar o caminho do diretório, abra a lista de lista suspensa de valores de propriedade e escolha **Editar**. No **diretórios de inclusão adicionais** caixa de diálogo, na caixa de texto, selecione uma linha em branco e, em seguida, escolha o botão de reticências \(**...**\) no final da linha. No **Selecionar diretório** caixa de diálogo, selecione o **MathFuncsLib** diretório e, em seguida, escolha **Selecionar pasta** botão para salvar sua seleção e fechar a caixa de diálogo. No **diretórios de inclusão adicionais** caixa de diálogo, escolha o **OK** botão e, em seguida, no **páginas de propriedade** caixa de diálogo, escolha o **OK** botão para salvar suas alterações ao projeto.  
  
5.  Agora você pode usar o **MyMathFuncs** classe neste aplicativo. Para fazer isso, substitua o conteúdo do **MyExecRefsLib.cpp** com este código:  
  
     [!CODE [NVC_Walkthrough_Create_Static_Lib#120](../CodeSnippet/VS_Snippets_Cpp/nvc_walkthrough_create_static_lib#120)]  
  
6.  Criar o executável escolhendo **criar**, **Build Solution** na barra de menus.  
  
##  <a name="BKMK_RunApp"></a> Executando o aplicativo  
  
#### Para executar o aplicativo  
  
1.  Verifique se **MyExecRefsLib** está selecionado como o projeto padrão abrindo o menu de atalho **MyExecRefsLib** na **Solution Explorer**, e, em seguida, escolhendo **Set as StartUp Project**.  
  
2.  Para executar o projeto, na barra de menus, escolha **Depurar**, **Start Without Debugging**. A saída deve ter esta aparência:  
  
    ```Output  
    um + b = 106,4 - b = -91,6 um * b = 732,6 um / b = 0,0747475  
    ```  
  
## Consulte também  
 [Tour guiado do Visual C\+\+](http://msdn.microsoft.com/pt-br/499cb66f-7df1-45d6-8b6b-33d94fd1f17c)   
 [Instruções passo a passo: criando e usando uma biblioteca de vínculo dinâmico \(C\+\+\)](../build/walkthrough-creating-and-using-a-dynamic-link-library-cpp.md)   
 [Aplicativos de área de trabalho do Windows \(Visual C\+\+\)](../windows/desktop-applications-visual-cpp.md)