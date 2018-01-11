---
title: "Passo a passo: Criando e usando uma biblioteca estática (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: get-started-article
dev_langs: C++
helpviewer_keywords:
- libraries [C++], static
- static libraries [C++]
ms.assetid: 3cc36411-7d66-4240-851e-dacb9a8fd6ac
caps.latest.revision: "38"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3af6bc41d353f82bb1f95c73f079e530da19dba0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="walkthrough-creating-and-using-a-static-library-c"></a>Instruções passo a passo: criando e usando uma biblioteca estática (C++)
Este passo a passo mostra como criar uma biblioteca estática (arquivo. lib) para uso com aplicativos do C++. Usando uma biblioteca estática é uma ótima maneira de reutilizar o código. Em vez de implementar novamente as rotinas mesmo em cada aplicativo que exige a funcionalidade, você grava uma vez em uma biblioteca estática e, em seguida, referenciá-lo dos aplicativos. Código vinculado a partir de uma biblioteca estática se torna parte do seu aplicativo, você não precisa instalar outro arquivo para usar o código.  
  
 Este passo a passo apresenta estas tarefas:  
  
-   [Criando um projeto de biblioteca estática](#BKMK_CreateLibProject)  
  
-   [Adicionando uma classe para a biblioteca estática](#BKMK_AddClassToLib)  
  
-   [Criando um aplicativo de console C++ que faz referência à biblioteca estática](#BKMK_CreateAppToRefTheLib)  
  
-   [Usando a funcionalidade da biblioteca estática no aplicativo](#BKMK_UseLibInApp)  
  
-   [Executando o aplicativo](#BKMK_RunApp)  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Noções básicas sobre os conceitos básicos da linguagem C++.  
  
##  <a name="BKMK_CreateLibProject"></a>Criando um projeto de biblioteca estática  
  
#### <a name="to-create-a-static-library-project"></a>Para criar um projeto de biblioteca estática  
  
1.  Na barra de menus, escolha **Arquivo**, **Novo**, **Projeto**.  
  
2.  No painel esquerdo do **novo projeto** caixa de diálogo caixa, expanda **instalado**, **modelos**, **Visual C++**e, em seguida, selecione  **Win32**.  
  
3.  No painel central, selecione **aplicativo do Console Win32**.  
  
4.  Especifique um nome para o projeto — por exemplo, **MathFuncsLib**— no **nome** caixa. Especifique um nome para a solução — por exemplo, **StaticLibrary**— no **nome da solução** caixa. Escolha o botão **OK**.  
  
5.  No **visão geral** página do **Assistente de aplicativo Win32** caixa de diálogo caixa, escolha o **próximo** botão.  
  
6.  Sobre o **configurações do aplicativo** página em **tipo de aplicativo**, selecione **biblioteca estática.**  
  
7.  Sobre o **configurações do aplicativo** página em **opções adicionais**, desmarque o **cabeçalho pré-compilado** caixa de seleção.  
  
8.  Escolha o **concluir** botão para criar o projeto.  
  
##  <a name="BKMK_AddClassToLib"></a>Adicionando uma classe para a biblioteca estática  
  
#### <a name="to-add-a-class-to-the-static-library"></a>Para adicionar uma classe para a biblioteca estática  
  
1.  Para criar um arquivo de cabeçalho para uma nova classe, abra o menu de atalho para o **MathFuncsLib** project no **Solution Explorer**e, em seguida, escolha **adicionar**, **Novo Item** . No **Adicionar Novo Item** caixa de diálogo, no painel esquerdo, em **Visual C++**, selecione **código**. No painel central, selecione **o arquivo de cabeçalho (. h)**. Especifique um nome para o arquivo de cabeçalho — por exemplo, **MathFuncsLib.h**— e, em seguida, escolha o **adicionar** botão. Um arquivo de cabeçalho em branco é exibido.  
  
2.  Adicione uma classe denominada **MyMathFuncs** para realizar as operações matemáticas comuns, como adição, subtração, multiplicação e divisão. O código deve ser parecido com este:  
  
     [!code-cpp[NVC_Walkthrough_Create_Static_Lib#100](../windows/codesnippet/CPP/walkthrough-creating-and-using-a-static-library-cpp_1.h)]  
  
3.  Para criar um arquivo de origem para a nova classe, abra o menu de atalho para o **MathFuncsLib** project no **Solution Explorer**e, em seguida, escolha **adicionar**, **Novo Item** . No **Adicionar Novo Item** caixa de diálogo, no painel esquerdo, em **Visual C++**, selecione **código**. No painel central, selecione **C++ arquivo (. cpp)**. Especifique um nome para o arquivo de origem — por exemplo, **MathFuncsLib.cpp**— e, em seguida, escolha o **adicionar** botão. Um arquivo de origem em branco é exibido.  
  
4.  Use este arquivo de origem para implementar a funcionalidade para **MyMathFuncs**. O código deve ser parecido com este:  
  
     [!code-cpp[NVC_Walkthrough_Create_Static_Lib#110](../windows/codesnippet/CPP/walkthrough-creating-and-using-a-static-library-cpp_2.cpp)]  
  
5.  Compilar a biblioteca estática selecionando **criar**, **compilar solução** na barra de menus. Isso cria uma biblioteca estática que pode ser usada por outros programas.  
  
    > [!NOTE]
    >  Quando você compila na linha de comando do Visual Studio, você deve criar o programa em duas etapas. Primeiro, execute **cl /c /EHsc MathFuncsLib.cpp** para compilar o código e criar um arquivo de objeto que é nomeado **MathFuncsLib.obj**. (O **cl** comando invoca o compilador, Cl.exe e o **/c** opção especifica compilar sem vinculação. Para obter mais informações, consulte [/c (compilar sem vinculação)](../build/reference/c-compile-without-linking.md).) Em seguida, executar **lib MathFuncsLib.obj** para vincular o código e criar a biblioteca estática **MathFuncsLib.lib**. (O **lib** comando chama o Gerenciador de biblioteca, Lib.exe. Para obter mais informações, consulte [referência LIB](../build/reference/lib-reference.md).)  
  
##  <a name="BKMK_CreateAppToRefTheLib"></a>Criando um aplicativo de console C++ que faz referência à biblioteca estática  
  
#### <a name="to-create-a-c-console-app-that-references-the-static-library"></a>Para criar um aplicativo de console C++ que faz referência à biblioteca estática  
  
1.  Na barra de menus, escolha **Arquivo**, **Novo**, **Projeto**.  
  
2.  No painel esquerdo, em **Visual C++**, selecione **Win32**.  
  
3.  No painel central, selecione **aplicativo do Console Win32**.  
  
4.  Especifique um nome para o projeto — por exemplo, **MyExecRefsLib**— no **nome** caixa. Na lista suspensa lista ao lado **solução**, selecione **adicionar à solução**. Isso adiciona o novo projeto à solução que contém a biblioteca estática. Escolha o botão **OK**.  
  
5.  No **visão geral** página do **Assistente de aplicativo Win32** caixa de diálogo caixa, escolha o **próximo** botão.  
  
6.  Sobre o **configurações do aplicativo** página em **tipo de aplicativo**, selecione **aplicativo de Console**.  
  
7.  Sobre o **configurações do aplicativo** página em **opções adicionais**, desmarque o **cabeçalho pré-compilado** caixa de seleção.  
  
8.  Escolha o **concluir** botão para criar o projeto.  
  
##  <a name="BKMK_UseLibInApp"></a>Usando a funcionalidade da biblioteca estática no aplicativo  
  
#### <a name="to-use-the-functionality-from-the-static-library-in-the-app"></a>Para usar a funcionalidade da biblioteca estática no aplicativo  
  
1.  Depois que você cria um aplicativo de console, o sistema cria um programa vazio para você. O nome do arquivo de origem será o mesmo que você escolheu anteriormente. Neste exemplo, ele é chamado **MyExecRefsLib.cpp**.  
  
2.  Antes de usar as rotinas de matemática na biblioteca estática, você deve fazer referência a ele. Para fazer isso, abra o menu de atalho para o **MyExecRefsLib** project no **Solution Explorer**e, em seguida, escolha **referências**. No **MyExecRefsLibProperty páginas** caixa de diálogo caixa, expanda o **propriedades comuns** nó, selecione **estrutura e referências**e, em seguida, escolha o **adicionar Nova referência** botão. Para obter mais informações sobre o **referências** caixa de diálogo, consulte [adicionando referências](../ide/adding-references-in-visual-cpp-projects.md).  
  
3.  O **adicionar referência** caixa de diálogo lista as bibliotecas que você pode fazer referência. O **projetos** guia lista os projetos na solução atual e todas as bibliotecas que eles contêm. Sobre o **projetos** guia, selecione o **MathFuncsLib** caixa de seleção e, em seguida, escolha o **Okey** botão.  
  
4.  A referência a **MathFuncsLib.h** arquivo de cabeçalho, você deve modificar o caminho de diretórios incluído. No **páginas de propriedade** caixa de diálogo **MyExecRefsLib**, expanda o **propriedades de configuração** nó, expanda o **C/C++** nó, e em seguida, selecione **geral**. Ao lado de **diretórios de inclusão adicionais**, especifique o caminho do **MathFuncsLib** diretório ou procurar por ele.  
  
     Para procurar o caminho do diretório, abra a lista de lista suspensa de valor de propriedade e, em seguida, escolha **editar**. No **diretórios de inclusão adicionais** caixa de diálogo, na caixa de texto, selecione uma linha em branco e, em seguida, escolha o botão de reticências (**...** ) no final da linha. No **Selecionar diretório** caixa de diálogo, selecione o **MathFuncsLib** diretório e, em seguida, escolha **Selecionar pasta** botão para salvar sua seleção e fechar a caixa de diálogo. No **diretórios de inclusão adicionais** caixa de diálogo caixa, escolha o **Okey** botão e, em seguida, no **páginas de propriedade** caixa de diálogo caixa, escolha o **Okey**botão para salvar suas alterações para o projeto.  
  
5.  Agora você pode usar o **MyMathFuncs** classe neste aplicativo. Para fazer isso, substitua o conteúdo do **MyExecRefsLib.cpp** com este código:  
  
     [!code-cpp[NVC_Walkthrough_Create_Static_Lib#120](../windows/codesnippet/CPP/walkthrough-creating-and-using-a-static-library-cpp_3.cpp)]  
  
6.  Criar o executável escolhendo **criar**, **compilar solução** na barra de menus.  
  
##  <a name="BKMK_RunApp"></a>Executando o aplicativo  
  
#### <a name="to-run-the-app"></a>Para executar o aplicativo  
  
1.  Verifique se **MyExecRefsLib** é selecionado como o projeto padrão abrindo o menu de atalho **MyExecRefsLib** na **Solution Explorer**e, em seguida, escolhendo  **Definir como projeto de inicialização**.  
  
2.  Para executar o projeto, na barra de menus, escolha **depurar**, **Start Without Debugging**. O resultado deve ser semelhante a este:  
  
    ```Output  
    a + b = 106.4  
    a - b = -91.6  
    a * b = 732.6  
    a / b = 0.0747475  
    ```  
  
## <a name="see-also"></a>Consulte também  
 [Instruções passo a passo: criando e usando uma biblioteca de vínculo dinâmico (C++)](../build/walkthrough-creating-and-using-a-dynamic-link-library-cpp.md)   
 [Aplicativos de área de trabalho (Visual C++)](../windows/desktop-applications-visual-cpp.md)