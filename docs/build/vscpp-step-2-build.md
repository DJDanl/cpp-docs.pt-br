---
title: Desenvolver e executar um projeto de aplicativo de console C++
description: Compilar e executar um aplicativo de console Olá, mundo em Visual C++
ms.custom: mvc
ms.date: 12/12/2017
ms.topic: tutorial
ms.devlang: cpp
ms.assetid: 45138d71-719d-42dc-90d7-1d0ca31a2f55
ms.openlocfilehash: 59813a553a9034503d8bf432400db31e6e3d9478
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62314220"
---
# <a name="build-and-run-a-c-console-app-project"></a>Desenvolver e executar um projeto de aplicativo de console C++

Quando você criou um projeto de aplicativo de console C++ e inseriu seu código, compilação e executá-lo dentro do Visual Studio e, em seguida, executá-lo como um aplicativo autônomo da linha de comando.

## <a name="prerequisites"></a>Prerequisites

- Ter o Visual Studio com o desenvolvimento de Desktop com carga de trabalho do C++ instalada e em execução no seu computador. Se ele ainda não estiver instalado, siga as etapas em [suporte de instalar o C++ no Visual Studio](vscpp-step-0-installation.md).

- Criar um "Olá, mundo!" projeto e insira seu código-fonte. Se você ainda não fez isso, siga as etapas em [criar um projeto de aplicativo de console C++](vscpp-step-1-create.md).

Se o Visual Studio se parece com isso, você estará pronto para compilar e executar seu aplicativo:

   ![Pronto para criar o novo projeto](media/vscpp-ready-to-build.png "pronto para criar o novo projeto")

## <a name="build-and-run-your-code-in-visual-studio"></a>Compilar e executar seu código no Visual Studio

1. Para compilar o projeto, escolha **Compilar Solução** no menu **Compilar**. A janela de **Saída** mostra os resultados do processo de build.

   ![Compilar o projeto](media/vscpp-build-solution.gif "Compilar o projeto")

1. Para executar o código, na barra de menus, escolha **Depurar**, **Iniciar sem depuração**.

   ![Iniciar o projeto](media/vscpp-start-without-debugging.gif "Iniciar o projeto")

   Uma janela do console é aberta e, em seguida, executa seu aplicativo. Quando você inicia um aplicativo de console no Visual Studio, ele é executado em seu código e, em seguida, imprime "Pressione qualquer tecla para continuar. . ." para dar a oportunidade de ver a saída.

Parabéns! Você criou seu primeiro aplicativo de console "Olá, mundo!" no Visual Studio! Pressione uma tecla para ignorar a janela do console e retornar ao Visual Studio.

[Houve um problema.](#build-and-run-your-code-in-visual-studio-issues)

## <a name="run-your-code-in-a-command-window"></a>Executar seu código em uma janela de comando

Normalmente, você deve executar aplicativos de console no prompt de comando, não no Visual Studio. Depois que seu aplicativo é criado pelo Visual Studio, você pode executá-lo a partir de qualquer janela de comando. Aqui está como localizar e executar seu novo aplicativo em uma janela de prompt de comando.

1. Na **Gerenciador de soluções**, selecione a Solução HelloWorld e com o botão direito para abrir o menu de contexto. Escolher **Abrir pasta no Explorador de arquivos** para abrir um **Explorador de arquivos** janela na pasta da Solução HelloWorld.

1. No **Explorador de arquivos** janela, abra a pasta de depuração. Isso contém seu aplicativo, HelloWorld.exe e alguns outros arquivos de depuração. Selecione HelloWorld.exe, mantenha pressionada a tecla Shift e clique com botão direito para abrir o menu de contexto. Escolher **copiar como caminho** para copiar o caminho para seu aplicativo na área de transferência.

1. Para abrir uma janela de prompt de comando, pressione Windows-R para abrir o **executar** caixa de diálogo. Insira *cmd.exe* na **aberto** caixa de texto, em seguida, escolha **Okey** para executar uma janela de prompt de comando.

1. Na janela do prompt de comando, clique com botão direito para colar o caminho para seu aplicativo no prompt de comando. Pressione Enter para executar seu aplicativo.

   ![Execute o aplicativo no prompt de comando](media/vscpp-run-in-cmd.gif "executar o aplicativo no prompt de comando")

Parabéns, você criou e executar um aplicativo de console no Visual Studio!

[Houve um problema.](#run-your-code-in-a-command-window-issues)

## <a name="next-steps"></a>Próximas etapas

Depois que você criou e executar esse aplicativo simple, você está pronto para projetos mais complexos. Ver [usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md) para obter mais explicações passo a passo que exploram os recursos do Visual C++ no Visual Studio.

## <a name="troubleshooting-guide"></a>Guia de solução de problemas

Venha aqui para soluções para problemas comuns quando você cria seu primeiro projeto em C++.

### <a name="build-and-run-your-code-in-visual-studio-issues"></a>Compilar e executar seu código nas edições do Visual Studio

Se linhas onduladas vermelhas aparecem em qualquer coisa no editor de código fonte, a compilação pode ter erros ou avisos. Verifique se o seu código corresponde ao exemplo na ortografia, pontuação e caso.

[Voltar.](#build-and-run-your-code-in-visual-studio)

### <a name="run-your-code-in-a-command-window-issues"></a>Executar seu código em uma janela de comando problemas

Você também pode navegar para a pasta de solução de depuração na linha de comando para executar seu aplicativo. Você não pode executar seu aplicativo de outros diretórios sem especificar o caminho para o aplicativo. No entanto, você pode copiar seu aplicativo para outro diretório e executá-lo a partir daí.

Se você não vir **copiar como caminho** no menu de atalho, ignorar o menu e, em seguida, mantenha pressionada a tecla SHIFT pressionada enquanto você abri-lo novamente. Isso é apenas para conveniência. Você também pode copiar o caminho para a pasta da barra de pesquisa do Explorador de arquivos e cole-o na **executar** caixa de diálogo e, em seguida, insira o nome de seu executável no final. É um pouco mais de digitação, mas ele tem o mesmo resultado.

[Voltar.](#run-your-code-in-a-command-window)

<iframe src="" height="0" width="0" frameborder="0" name="frameTarget" />
