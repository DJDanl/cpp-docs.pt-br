---
title: Desenvolver e executar um projeto de aplicativo de console C++
description: Compilar e executar um aplicativo de console de Olá, Mundo no Visual C++
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

Você criou um projeto de aplicativo de console do C++ e inseriu seu código. Agora você pode criar e executá-lo no Visual Studio. Em seguida, execute-o como um aplicativo autônomo na linha de comando.

## <a name="prerequisites"></a>Pré-requisitos

- Ter o Visual Studio com o desenvolvimento de Desktop com carga de trabalho do C++ instalada e em execução no seu computador. Se ele ainda não estiver instalado, siga as etapas em [Instalar suporte a C++ no Visual Studio](vscpp-step-0-installation.md).

- Criar um "Olá, mundo!" projeto e insira seu código-fonte. Se você ainda não fez essa etapa, siga as etapas em [criar um projeto de aplicativo de console do C++](vscpp-step-1-create.md).

Se o Visual Studio tiver esta aparência, você estará pronto para compilar e executar seu aplicativo:

   ![Pronto para criar o novo projeto](media/vscpp-ready-to-build.png "Pronto para criar o novo projeto")

## <a name="build-and-run-your-code-in-visual-studio"></a>Compilar e executar seu código no Visual Studio

1. Para compilar o projeto, escolha **Compilar Solução** no menu **Compilar**. A janela de **Saída** mostra os resultados do processo de build.

   ![Compilar o projeto](media/vscpp-build-solution.gif "Compilar o projeto")

1. Para executar o código, na barra de menus, escolha **Depurar**, **Iniciar sem depuração**.

   ![Iniciar o projeto](media/vscpp-start-without-debugging.gif "Iniciar o projeto")

   Uma janela do console é aberta e, em seguida, executa seu aplicativo. Quando você inicia um aplicativo de console no Visual Studio, ele é executado em seu código e, em seguida, imprime "Pressione qualquer tecla para continuar. . ." para dar a oportunidade de ver a saída.

Parabéns! Você criou seu primeiro aplicativo de console "Olá, mundo!" no Visual Studio! Pressione uma tecla para ignorar a janela do console e retornar ao Visual Studio.

[Houve um problema.](#build-and-run-your-code-in-visual-studio-issues)

## <a name="run-your-code-in-a-command-window"></a>Executar seu código em uma janela de comando

Normalmente, você executa aplicativos de console no prompt de comando, não no Visual Studio. Depois que seu aplicativo for criado pelo Visual Studio, você poderá executá-lo em qualquer janela de comando. Veja como localizar e executar seu novo aplicativo em uma janela de prompt de comando.

1. Em **Gerenciador de soluções**, selecione a solução HelloWorld (não o projeto HelloWorld) e clique com o botão direito do mouse para abrir o menu de contexto. Escolha **abrir pasta no explorador de arquivos** para abrir uma janela do **Explorador de arquivos** na pasta da solução HelloWorld.

1. Na janela **Explorador de arquivos** , abra a pasta depurar. Essa pasta contém seu aplicativo, *HelloWorld. exe*e alguns outros arquivos de depuração. Mantenha pressionada a tecla **Shift** e clique com o botão direito do mouse em *HelloWorld. exe* para abrir o menu de contexto. Escolha **Copiar como caminho** para copiar o caminho para o aplicativo na área de transferência.

1. Para abrir uma janela de prompt de comando, pressione **Windows + R** para abrir a caixa de diálogo **executar** . Insira *cmd. exe* na caixa de texto **abrir** e escolha **OK** para executar uma janela de prompt de comando.

1. Na janela do prompt de comando, clique com o botão direito do mouse para colar o caminho para seu aplicativo no prompt de comando. Pressione Enter para executar seu aplicativo.

   ![Executar o aplicativo no prompt de comando](media/vscpp-run-in-cmd.gif "Executar o aplicativo no prompt de comando")

Parabéns, você criou e executou um aplicativo de console no Visual Studio!

[Houve um problema.](#run-your-code-in-a-command-window-issues)

## <a name="next-steps"></a>Próximas etapas

Depois de criar e executar este aplicativo simples, você estará pronto para projetos mais complexos. Para obter mais informações, consulte [usando o IDE do Visual Studio para desenvolvimento de Desktop C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md). Ele tem orientações mais detalhadas que exploram os recursos do Microsoft C++ no Visual Studio.

## <a name="troubleshooting-guide"></a>Guia de Solução de Problemas

Venha aqui para soluções para problemas comuns quando você cria seu primeiro projeto C++.

### <a name="build-and-run-your-code-in-visual-studio-issues"></a>Compilar e executar seu código no Visual Studio: problemas

Se os rabiscos vermelhos aparecerem em qualquer coisa no editor de código-fonte, a compilação poderá ter erros ou avisos. Verifique se o seu código corresponde ao exemplo em ortografia, pontuação e caso.

[Voltar.](#build-and-run-your-code-in-visual-studio)

### <a name="run-your-code-in-a-command-window-issues"></a>Execute seu código em uma janela de comando: problemas

Se o caminho mostrado no explorador de arquivos terminar * \\em\\HelloWorld HelloWorld*, você terá aberto o *projeto* HelloWorld em vez da *solução*HelloWorld. Você ficará confuso com uma pasta de depuração que não contém seu aplicativo. Navegue até um nível no explorador de arquivos para obter a pasta da solução, o primeiro *HelloWorld* no caminho. Essa pasta também contém uma pasta de depuração e você encontrará seu aplicativo lá.

Você também pode navegar até a pasta de depuração da solução na linha de comando para executar seu aplicativo. Seu aplicativo não será executado de outros diretórios sem especificar o caminho para o aplicativo. No entanto, você pode copiar seu aplicativo para outro diretório e executá-lo a partir daí. Também é possível copiá-lo para um diretório especificado pela variável de ambiente PATH e, em seguida, executá-lo de qualquer lugar.

Se você não vir **Copiar como caminho** no menu de atalho, ignore o menu e mantenha a tecla **Shift** pressionada enquanto abri-la novamente. Esse comando é apenas para sua conveniência. Você também pode copiar o caminho para a pasta na barra de pesquisa do explorador de arquivos e colá-lo na caixa de diálogo **executar** e, em seguida, inserir o nome do seu executável no final. É apenas um pouco mais de digitação, mas tem o mesmo resultado.

[Voltar.](#run-your-code-in-a-command-window)

<iframe src="" height="0" width="0" frameborder="0" name="frameTarget" />
