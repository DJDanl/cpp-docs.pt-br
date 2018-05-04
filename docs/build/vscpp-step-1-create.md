---
title: Crie um projeto de aplicativo de console C++ | Microsoft Docs
description: Criar um aplicativo de console Hello World no Visual C++
ms.custom: mvc
ms.date: 12/12/2017
ms.topic: tutorial
ms.technology:
- devlang-C++
ms.devlang: C++
dev_langs:
- C++
ms.assetid: 45138d70-719d-42dc-90d7-1d0ca31a2f54
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 35b7b896dfb2a4c9dd37a9f59476cbc7f23c3902
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="create-a-c-console-app-project"></a>Crie um projeto de aplicativo de console C++

O usual ponto inicial para um programador de C++ é um "Olá, mundo!" aplicativo que é executado na linha de comando. É o que você criará no Visual Studio nesta etapa.

## <a name="prerequisites"></a>Pré-requisitos

- Ter o Visual Studio com o desenvolvimento de área de trabalho com carga de trabalho C++ instalado e em execução no seu computador. Se ele ainda não estiver instalado, consulte [suporte instalar C++ no Visual Studio](../build/vscpp-step-0-installation.md).

## <a name="create-your-app-project"></a>Criar seu projeto de aplicativo

O Visual Studio usa os *projetos* para organizar o código em um aplicativo e as *soluções* para organizar seus projetos. Um projeto contém as opções, configurações e regras usadas para criar seus aplicativos e gerencia a relação entre todos os arquivos de projeto e todos os arquivos externos. Para criar seu aplicativo, primeiro, você criará um novo projeto e solução.

1. No Visual Studio, abra o **arquivo** menu e escolha **Novo > projeto** para abrir o **novo projeto** caixa de diálogo.

   ![Abra a caixa de diálogo Novo projeto](../build/media/vscpp-file-new-project.gif "abrir a caixa de diálogo Novo projeto")

1. No **novo projeto** caixa de diálogo, selecione **instalado**, **Visual C++** se ele não está selecionado e, em seguida, escolha o **projeto vazio** modelo. No **nome** , digite *HelloWorld*. Escolha **Okey** para criar o projeto.

   ![Nomear e criar o novo projeto](../build/media/vscpp-concierge-project-name-callouts.png "nome e criar o novo projeto")

O Visual Studio cria um projeto novo e vazio, pronto para especializar para o tipo de aplicativo que você deseja criar e adicionar os arquivos de código fonte. Você fará isso em seguida.

[Encontrei um problema.](#create-your-app-project-issues)

## <a name="make-your-project-a-console-app"></a>Verifique seu projeto de um aplicativo de console

O Visual Studio pode criar todos os tipos de aplicativos e componentes do Windows e outras plataformas. O **projeto vazio** modelo não é específico sobre que tipo de aplicativo que ele cria. Para criar um *aplicativo de console*, um que é executado em uma janela de prompt de comando ou o console, você deve informar o Visual Studio para criar seu aplicativo para usar o subsistema de console.

1. No Visual Studio, abra o **projeto** menu e escolha **propriedades** para abrir o **páginas de propriedade HelloWorld** caixa de diálogo.

1. No **páginas de propriedade** caixa de diálogo, em **propriedades de configuração**, selecione **vinculador**, **sistema**e, em seguida, escolha a caixa de edição em o **subsistema** propriedade. No menu suspenso que aparece, selecione **Console (/ subsistema: CONSOLE)**. Escolha **Okey** para salvar suas alterações.

   ![Abra a caixa de diálogo páginas de propriedade](../build/media/vscpp-properties-linker-subsystem.gif "abrir a caixa de diálogo páginas de propriedades")

Agora, o Visual Studio sabe para compilar o projeto para ser executado em uma janela de console. Em seguida, você adicionará um arquivo de código fonte e insira o código para seu aplicativo.

[Encontrei um problema.](#make-your-project-a-console-app-issues)

## <a name="add-a-source-code-file"></a>Adicionar um arquivo de código fonte

1. Em **Solution Explorer**, selecione o projeto HelloWorld. Na barra de menus, escolha **projeto**, **Adicionar Novo Item** para abrir o **Adicionar Novo Item** caixa de diálogo.

1. No **Adicionar Novo Item** caixa de diálogo, selecione **Visual C++** em **instalado** se ainda não estiver selecionado. No painel central, selecione **arquivo C++ (. cpp)**. Alterar o **nome** para *HelloWorld*. Escolha **adicionar** para fechar a caixa de diálogo e criar o arquivo.

   ![Adicionar um arquivo de origem para HelloWorld](../build/media/vscpp-add-new-item.gif "adicionar um arquivo de origem de HelloWorld")

Visual studio cria um arquivo de código fonte novo e vazio e abre em uma janela do editor, pronta para entrar no seu código-fonte.

[Encontrei um problema.](#add-a-source-code-file-issues)

## <a name="add-code-to-the-source-file"></a>Adicione código ao arquivo de origem

1. Copie esse código na janela de editor de HelloWorld.

   ```cpp
   #include <iostream>

   int main()
   {
       std::cout << "Hello, world!" << std::endl;
       return 0;
   }
   ```

   Na janela do editor, o código deve ser assim:

   ![Olá no editor de código do mundo](../build/media/vscpp-hello-world-editor.png "código Hello World no editor")

Quando o código é semelhante isso no editor, você estará pronto para ir para a próxima etapa e criar seu aplicativo.

[Encontrei um problema.](#add-a-source-code-file-issues)

## <a name="next-steps"></a>Próximas etapas

> [!div class="nextstepaction"]
> [Compilar e executar um projeto de C++](vscpp-step-2-build.md)

## <a name="troubleshooting-guide"></a>Guia de solução de problemas

Vir aqui para soluções para problemas comuns ao criar seu primeiro projeto C++.

### <a name="create-your-app-project-issues"></a>Crie seu aplicativo questões do projeto

Se o **novo projeto** não mostra caixa de diálogo um **Visual C++** entrada em **instalado**, provavelmente sua cópia do Visual Studio não tem o **área de trabalho desenvolvimento com C++** instalada da carga de trabalho. Você pode executar o instalador desde o **novo projeto** caixa de diálogo. Escolha o **abrir instalador do Visual Studio** link para iniciar o instalador novamente. Se o **User Account Control** caixa de diálogo solicita permissões, escolha **Sim**. O instalador, certifique-se a **desenvolvimento de área de trabalho com C++** cargas de trabalho está marcada e escolha **Okey** para atualizar sua instalação do Visual Studio.

Se já existir outro projeto com o mesmo nome, escolha outro nome para seu projeto, ou exclua o projeto existente e tente novamente. Para excluir um projeto existente, exclua a pasta de solução (a pasta que contém o arquivo HelloWorld) no Explorador de arquivos.

[Voltar](#create-your-app-project).

### <a name="make-your-project-a-console-app-issues"></a>Verifique seu projeto de um problema de aplicativo de console

Se você não vir **vinculador** listado em **propriedades de configuração**, escolha **Cancelar** para fechar o **páginas de propriedade** caixa de diálogo e, em seguida, Verifique se o **HelloWorld** projeto for selecionado no **Solution Explorer**, não a solução ou outro arquivo ou pasta, antes de tentar novamente.

O controle de lista suspensa não aparecer no **subsistema** caixa de edição de propriedade até que você selecionar a propriedade. Você pode selecioná-lo usando o ponteiro ou pressione Tab para alternar entre os controles de caixa de diálogo até **subsistema** é realçado. Escolha o controle dropdown ou pressione Alt + seta para baixo para abri-lo.

[Voltar](#make-your-project-a-console-app)

### <a name="add-a-source-code-file-issues"></a>Adicionar um problema de arquivo de código fonte

É okey se você fornecer o arquivo de código fonte um nome diferente. No entanto, não adicione mais de um arquivo de código fonte que contém o mesmo código ao seu projeto.

Se você adicionou o tipo errado de arquivo ao seu projeto, por exemplo, um arquivo de cabeçalho, exclua-o e tente novamente. Para excluir o arquivo, selecione-a na **Solution Explorer** e pressione a tecla Delete.

[Voltar](#add-a-source-code-file).

### <a name="add-code-to-the-source-file-issues"></a>Adicione código para os problemas de arquivo de origem

Se você fechar acidentalmente a fonte arquivo janela editor de códigos, para abri-lo novamente, clique duas vezes em HelloWorld no **Solution Explorer** janela.

Se linhas onduladas vermelhas aparecem em qualquer coisa no editor de código fonte, verifique se o seu código corresponde o exemplo no caso de ortografia e pontuação. Caso é significativo no código C++.

[Voltar](#add-code-to-the-source-file).

<iframe src="" height="0" width="0" frameborder="0" name="frameTarget" />