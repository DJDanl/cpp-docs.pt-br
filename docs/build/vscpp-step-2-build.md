---
title: Desenvolver e executar um projeto de aplicativo de console C++
description: Construa e execute um aplicativo de console Hello World no Visual C++
ms.custom: mvc
ms.date: 04/20/2020
ms.topic: tutorial
ms.devlang: cpp
ms.assetid: 45138d71-719d-42dc-90d7-1d0ca31a2f55
ms.openlocfilehash: d1e92e598b370312730a7c4e208b935a264010bf
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81749246"
---
# <a name="build-and-run-a-c-console-app-project"></a>Desenvolver e executar um projeto de aplicativo de console C++

Você criou um projeto de aplicativo de console C++ e inseriu seu código. Agora você pode construí-lo e executá-lo dentro do Visual Studio. Em seguida, execute-o como um aplicativo autônomo a partir da linha de comando.

## <a name="prerequisites"></a>Pré-requisitos

- Ter o Visual Studio com o desenvolvimento de Desktop com carga de trabalho do C++ instalada e em execução no seu computador. Se ainda não estiver instalado, siga as etapas do [suporte ao Install C++ no Visual Studio](vscpp-step-0-installation.md).

- Crie um "Olá, Mundo!" projetar e inserir seu código fonte. Se você ainda não fez essa etapa, siga os passos em Criar um projeto de [aplicativo de console C++.](vscpp-step-1-create.md)

Se o Visual Studio se parece com isso, você está pronto para construir e executar o seu aplicativo:

   ![Pronto para construir o novo projeto](media/vscpp-ready-to-build.png "Pronto para construir o novo projeto")

## <a name="build-and-run-your-code-in-visual-studio"></a>Construa e execute seu código no Visual Studio

1. Para compilar o projeto, escolha **Compilar Solução** no menu **Compilar**. A janela de **Saída** mostra os resultados do processo de build.

   ![Construa o projeto](media/vscpp-build-solution.gif "Compilar o projeto")

1. Para executar o código, na barra de menus, escolha **Depurar**, **Iniciar sem depuração**.

   ![Iniciar o projeto](media/vscpp-start-without-debugging.gif "Iniciar o projeto")

   Uma janela do console é aberta e, em seguida, executa seu aplicativo. Quando você inicia um aplicativo de console no Visual Studio, ele é executado em seu código e, em seguida, imprime "Pressione qualquer tecla para continuar. . ." para dar a oportunidade de ver a saída.

Parabéns! Você criou seu primeiro aplicativo de console "Olá, mundo!" no Visual Studio! Pressione uma tecla para ignorar a janela do console e retornar ao Visual Studio.

[Houve um problema.](#build-and-run-your-code-in-visual-studio-issues)

## <a name="run-your-code-in-a-command-window"></a>Execute seu código em uma janela de comando

Normalmente, você executa aplicativos de console no prompt de comando, não no Visual Studio. Uma vez que seu aplicativo é construído pelo Visual Studio, você pode executá-lo a partir de qualquer janela de comando. Veja como encontrar e executar seu novo aplicativo em uma janela de solicitação de comando.

1. No **Solution Explorer,** selecione a solução HelloWorld (não o projeto HelloWorld) e clique com o botão direito do mouse para abrir o menu de contexto. Escolha **Abrir pasta no Explorador de arquivos** para abrir uma janela do File **Explorer** na pasta de solução HelloWorld.

1. Na janela **Explorador de arquivos,** abra a pasta Debug. Esta pasta contém seu aplicativo, *HelloWorld.exe,* e alguns outros arquivos de depuração. Mantenha a tecla **Shift** e clique com o botão direito do mouse no *HelloWorld.exe* para abrir o menu de contexto. Escolha **Copiar como caminho** para copiar o caminho para o seu aplicativo para a área de transferência.

1. Para abrir uma janela de solicitação de comando, pressione **o Windows+R** para abrir a caixa de diálogo **Executar.** Digite *cmd.exe* na **caixa de** texto Aberta e escolha **OK** para executar uma janela de solicitação de comando.

1. Na janela de solicitação de comando, clique com o botão direito do mouse para colar o caminho para o aplicativo no prompt de comando. Pressione Enter para executar seu aplicativo.

   ![Execute o aplicativo no prompt de comando](media/vscpp-run-in-cmd.gif "Execute o aplicativo no prompt de comando")

Parabéns, você construiu e executou um aplicativo de console no Visual Studio!

[Houve um problema.](#run-your-code-in-a-command-window-issues)

## <a name="next-steps"></a>Próximas etapas

Depois de construir e executar este aplicativo simples, você está pronto para projetos mais complexos. Para obter mais informações, consulte [Usando o Visual Studio IDE para Desenvolvimento de Desktop C++.](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md) Possui passo a passo mais detalhado que exploram os recursos do Microsoft C++ no Visual Studio.

## <a name="troubleshooting-guide"></a>Guia de Solução de Problemas

Venha aqui para obter soluções para problemas comuns quando você criar seu primeiro projeto C++.

### <a name="build-and-run-your-code-in-visual-studio-issues"></a>Construa e execute seu código no Visual Studio: problemas

Se os rabiscos vermelhos aparecerem em qualquer coisa no editor de código fonte, a compilação pode ter erros ou avisos. Verifique se seu código corresponde ao exemplo em ortografia, pontuação e estojo.

[Voltar.](#build-and-run-your-code-in-visual-studio)

### <a name="run-your-code-in-a-command-window-issues"></a>Execute seu código em uma janela de comando: problemas

Se o caminho mostrado no File Explorer terminar no * \\HelloWorld\\HelloWorld,* você abriu o *projeto* HelloWorld em vez da *solução*HelloWorld . Você será confundido por uma pasta Debug que não contém seu aplicativo. Navegue até um nível no File Explorer para chegar à pasta de soluções, o primeiro *HelloWorld* no caminho. Esta pasta também contém uma pasta Debug, e você encontrará seu aplicativo lá.

Você também pode navegar até a pasta Debug de solução na linha de comando para executar seu aplicativo. Seu aplicativo não será executado a partir de outros diretórios sem especificar o caminho para o aplicativo. No entanto, você pode copiar seu aplicativo para outro diretório e executá-lo a partir daí. Também é possível copiá-lo a um diretório especificado pela variável de ambiente PATH e executá-lo de qualquer lugar.

Se você não ver **Copiar como caminho** no menu de atalho, descarte o menu e, em seguida, mantenha a tecla **Shift** enquanto você a abre novamente. Este comando é apenas por conveniência. Você também pode copiar o caminho para a pasta na barra de pesquisa do Explorador de arquivos e colá-lo na caixa de diálogo **Executar** e, em seguida, digitar o nome do executável no final. É só um pouco mais de digitação, mas tem o mesmo resultado.

[Voltar.](#run-your-code-in-a-command-window)

<iframe src="" height="0" width="0" frameborder="0" name="frameTarget" />
