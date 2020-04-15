---
title: Criar projetos multiplataforma do C++ no Visual Studio
description: Como configurar, compilar e depurar um projeto C++ de código aberto C++ no Visual Studio que tem como alvo tanto o Linux quanto o Windows.
ms.topic: tutorial
ms.date: 01/08/2020
ms.openlocfilehash: aac536f488cf22adf5aa835c9fe5b884fc5d7298
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328752"
---
# <a name="tutorial-create-c-cross-platform-projects-in-visual-studio"></a>Tutorial: Crie projetos multiplataforma C++ no Visual Studio

Desenvolvimento do Visual Studio C e C++ não é mais apenas para Windows. Este tutorial mostra como usar o Visual Studio para o desenvolvimento de plataformas cruzadas C++ no Windows e Linux. É baseado no CMake, então você não precisa criar ou gerar projetos do Visual Studio. Quando você abre uma pasta que contém um arquivo CMakeLists.txt, o Visual Studio configura o IntelliSense e configurações de compilação automaticamente. Você pode começar rapidamente a editar, construir e depurar seu código localmente no Windows. Em seguida, alterne sua configuração para fazer o mesmo no Linux, tudo de dentro do Visual Studio.

Neste tutorial, você aprenderá como:

> [!div class="checklist"]
>
> * clonar um projeto do CMake de software livre do GitHub
> * abra o projeto no Visual Studio
> * compilar e depurar um destino de executável no Windows
> * Adicionar uma conexão a um computador Linux
> * compilar e depurar o mesmo destino no Linux

## <a name="prerequisites"></a>Pré-requisitos

* Configurar o Visual Studio para Desenvolvimento em C++ Multiplataforma
  * Primeiro, [instale](https://visualstudio.microsoft.com/vs/) o Visual Studio e escolha o desenvolvimento de Desktop com desenvolvimento **C++** e **Linux com cargas de trabalho C++.** Esta instalação mínima é de apenas 3 GB. Dependendo da velocidade de download, a instalação não deve levar mais de 10 minutos.

* Configurar um computador Linux para desenvolvimento em C++ multiplataforma
  * O Visual Studio não exige nenhuma distribuição específica do Linux. O Sistema Operacional pode estar funcionando em uma máquina física, em uma VM, ou na nuvem. Você também pode usar o Subsistema Windows para Linux (WSL). No entanto, para este tutorial é necessário um ambiente gráfico. WSL não é recomendado aqui, porque é destinado principalmente para operações de linha de comando.
  * O Visual Studio requer essas ferramentas na máquina Linux: compiladores C++, gdb, ssh, rsync, ninja e zip. Em sistemas baseados no Debian, você pode usar este comando para instalar essas dependências:

    ```cmd
    sudo apt install -y openssh-server build-essential gdb rsync ninja-build zip
    ```

  * O Visual Studio requer uma versão recente do CMake na máquina Linux que tenha o modo servidor ativado (pelo menos 3.8). A Microsoft produz um build universal do CMake que você pode instalar em qualquer distribuição do Linux. Recomendamos que você use esta compilação para garantir que você tenha os recursos mais recentes. Você pode obter os binários do CMake da [bifurcação da Microsoft do repositório CMake](https://github.com/Microsoft/CMake/releases) no GitHub. Vá para essa página e baixe a versão que corresponde à arquitetura do sistema em sua máquina Linux, em seguida, marque-a como um executável:

    ```cmd
    wget <path to binary>
    chmod +x cmake-3.11.18033000-MSVC_2-Linux-x86_64.sh
    ```

  * Você pode ver as opções para executar o script com `-–help`. Recomendamos que você `–prefix` use a opção para especificar a instalação no caminho **/usr,** porque **/usr/bin** é o local padrão onde o Visual Studio procura cMake. O exemplo a seguir mostra o script do Linux-x86_64. Mude-o conforme necessário se você estiver usando uma plataforma de destino diferente.

    ```cmd
    sudo ./cmake-3.11.18033000-MSVC_2-Linux-x86_64.sh --skip-license --prefix=/usr
    ```

* Git para Windows instalado em seu computador Windows.
* Uma conta do GitHub.

## <a name="clone-an-open-source-cmake-project-from-github"></a>Clonar um projeto do CMake de software livre do GitHub

Este tutorial usa o Bullet Physics SDK no GitHub. Ele fornece detecção de colisões e simulações físicas para muitas aplicações. O SDK inclui programas executáveis de exemplo que compilam e executam sem ter que escrever código adicional. Este tutorial não modifica nenhum dos códigos-fonte ou criar scripts. Para começar, clone o repositório *bullet3* do GitHub na máquina onde você tem o Visual Studio instalado.

```cmd
git clone https://github.com/bulletphysics/bullet3.git
```

1. No menu principal do Visual Studio, escolha **Arquivo > Abra > CMake**. Navegue até o arquivo CMakeLists.txt na raiz do repo bullet3 que você acabou de baixar.

    ![Menu do Visual Studio para Arquivo > Abrir > CMake](media/cmake-open-cmake.png)

    Assim que você abrir a pasta, sua estrutura de pasta fica visível no **Solution Explorer**.

    ![Exibição de pasta do Gerenciador de Soluções do Visual Studio](media/cmake-bullet3-solution-explorer.png)

    Essa exibição mostra exatamente o que está no disco, não uma exibição filtrada ou lógica. Por padrão, não mostra arquivos ocultos.

1. Escolha o botão **Mostrar todos os arquivos** para ver todos os arquivos da pasta.

    ![Botão Mostrar Todos os Arquivos do Gerenciador de Soluções do Visual Studio](media/cmake-bullet3-show-all-files.png)

## <a name="switch-to-targets-view"></a>Mude para a exibição de destinos

Quando você abre uma pasta que usa CMake, o Visual Studio gera automaticamente o cache de CMake. Essa operação pode levar alguns minutos, dependendo do tamanho do seu projeto.

1. Na **Janela de Saída**, selecione **Mostrar saída de** e, em seguida, escolha **CMake** para monitorar o status do processo de geração de cache. Quando a operação for concluída, é indicado "Extração de informações destino concluída".

   ![Janela de Saída do Visual Studio mostrando a saída do CMake](media/cmake-bullet3-output-window.png)

   Após a conclusão desta operação, o IntelliSense é configurado. Você pode construir o projeto e depurar o aplicativo. O Visual Studio agora mostra uma visão lógica da solução, com base nos alvos especificados nos arquivos CMakeLists.

1. Use o botão **Soluções e Pastas** no **Gerenciador de Soluções** para alternar para exibição de destinos do CMake.

   ![Botão Soluções e Pastas no Gerenciador de Soluções para mostrar a exibição de destinos do CMake](media/cmake-bullet3-show-targets.png)

   Esta é a aparência dessa exibição para o SDK do Bullet:

   ![Exibição de destinos do CMake do Gerenciador de Soluções](media/cmake-bullet3-targets-view.png)

   A exibição de destinos fornece uma exibição mais intuitiva do que essa base de código-fonte. Você pode ver que alguns destinos são bibliotecas e outros são executáveis.

1. Expanda um nó na exibição de destinos do CMake para ver seus arquivos de código-fonte, independentemente do local em que esses arquivos estejam no disco.

## <a name="add-an-explicit-windows-x64-debug-configuration"></a>Adicionar uma configuração x64-Debug do Windows explícita

O Visual Studio cria uma configuração **padrão x64-Debug** para Windows. As configurações são como o Visual Studio entende que destino de plataforma ele vai usar para o CMake. A configuração padrão não é representada no disco. Quando você adiciona explicitamente uma configuração, o Visual Studio cria um arquivo chamado *CMakeSettings.json*. Ele é preenchido com configurações para todas as configurações especificadas.

1. Adicione uma nova configuração. Abra a posição de **configuração** na barra de ferramentas e selecione **Gerenciar configurações**.

   ![Lista suspensa Gerenciar Configuração](media/cmake-bullet3-manage-configurations.png)

   O [CMake Settings Editor é](customize-cmake-settings.md) aberto. Selecione o sinal verde mais no lado esquerdo do editor para adicionar uma nova configuração. A configuração adicionar à caixa de diálogo **CMakeSettings** é exibida.

   ![Caixa de diálogo Adicionar Configuração a CMakeSettings](media/cmake-bullet3-add-configuration-x64-debug.png)

   Esta caixa de diálogo mostra todas as configurações incluídas no Visual Studio, além de quaisquer configurações personalizadas que você criar. Se você quiser continuar a usar uma configuração **x64-Debug,** essa deve ser a primeira a adicionar. Selecione **x64-Debug**e escolha o botão **Selecionar.** O Visual Studio cria o arquivo CMakeSettings.json com uma configuração para **x64-Debug**e o salva em disco. Você pode usar qualquer nome que desejar para suas configurações, alterando o parâmetro de nome diretamente no CMakeSettings.json.

## <a name="set-a-breakpoint-build-and-run-on-windows"></a>Defina um ponto de ruptura, construa e execute no Windows

Nesta etapa, vamos depurar um programa de exemplo que demonstra a biblioteca do Bullet Physics.
  
1. Em **Gerenciador de Soluções**, selecione AppBasicExampleGui e expanda-o.

1. Abra o arquivo `BasicExample.cpp`.

1. Defina um ponto de ruptura que é atingido quando você clica no aplicativo em execução. O evento de clique é tratado em um método dentro de uma classe auxiliar. Para rapidamente chegar lá:

   1. Selecione `CommonRigidBodyBase` de onde `BasicExample` a estrutura é derivada. É em torno da linha 30.

   1. Clique com o botão direito do mouse e escolha **Ir para Definição**. Agora você está no cabeçalho CommonRigidBodyBase.h.

   1. Na visão do navegador acima da sua fonte, `CommonRigidBodyBase`você deve ver que você está no . À direita, você pode selecionar membros para examinar. Abra o drop-down `mouseButtonCallback` e selecione para ir para a definição dessa função no cabeçalho.

      ![Barra de ferramentas da lista de membros do Visual Studio](media/cmake-bullet3-member-list-toolbar.png)

1. Coloque um ponto de interrupção na primeira linha nessa função. Ele é atingido quando você clica em um botão do mouse dentro da janela do aplicativo, quando executado sob o depurador Visual Studio.

1. Para iniciar o aplicativo, selecione a parada de lançamento na barra de ferramentas. É aquele com o ícone de reprodução verde que diz "Selecione item de inicialização". Na queda, selecione AppBasicExampleGui.exe. O nome do executável agora é exibido no botão de inicialização:

   ![Lista suspensa de inicialização da barra de ferramentas do Visual Studio para Selecionar Item de Inicialização](media/cmake-bullet3-launch-button.png)

1. Escolha o botão de inicialização para construir o aplicativo e as dependências necessárias e, em seguida, inicie-o com o depurador visual studio conectado. Após alguns instantes, o aplicativo em execução é exibido:

   ![Visual Studio depurando um aplicativo do Windows](media/cmake-bullet3-launched.png)

1. Mova o mouse para a janela do aplicativo e, em seguida, clique em um botão para disparar o ponto de interrupção. O ponto de partida traz o Visual Studio de volta ao primeiro plano, e o editor mostra a linha onde a execução é pausada. Você pode inspecionar as variáveis de aplicativo, objetos, threads e memória, ou passar pelo seu código de forma interativa. Escolha **Continuar** para deixar o aplicativo ser retomado e, em seguida, sair normalmente. Ou, interrompa a execução dentro do Visual Studio usando o botão stop.

## <a name="add-a-linux-configuration-and-connect-to-the-remote-machine"></a>Adicionar uma configuração do Linux e conectar-se ao computador remoto

1. Adicione uma configuração Linux. Clique com o botão direito do mouse no arquivo CMakeSettings.json na exibição **Gerenciador de Soluções** e selecione **Adicionar Configuração**. Você verá a mesma caixa de diálogo Adicionar Configuração a CMakeSettings de antes. Selecione **Linux-Debug** desta vez e salve o arquivo CMakeSettings.json (ctrl + s).

1. Selecione **O Linux-Debug** na configuração parada.

   ![Inicie a lista suspensa de configuração com as opções X64-Debug e Linux-Debug](media/cmake-bullet3-linux-configuration-item.png)

   Se é a primeira vez que você está se conectando a um sistema Linux, a caixa de diálogo **Conexão ao Sistema Remoto** será exibida.

   ![Caixa de diálogo Conectar-se ao sistema remoto do Visual Studio](media/cmake-bullet3-connection-manager.png)

   Se você já adicionou uma conexão remota, você pode abrir essa janela navegando para **ferramentas > opções > Cross Platform > Connection Manager**.

1. Forneça as [informações de conexão à sua máquina Linux](/cpp/linux/connect-to-your-remote-linux-computer) e escolha **Conectar**. O Visual Studio adiciona essa máquina quanto ao CMakeSettings.json como sua conexão padrão para **Linux-Debug**. Ele também puxa para baixo os cabeçalhos da sua máquina remota, para que você obtenha [o IntelliSense específico para essa conexão remota](/cpp/linux/configure-a-linux-project?view=vs-2019#remote_intellisense). Em seguida, o Visual Studio envia seus arquivos para a máquina remota e gera o cache CMake no sistema remoto. Essas etapas podem levar algum tempo, dependendo da velocidade da sua rede e da potência da sua máquina remota. Você saberá que está completa quando a mensagem "Destino de extração de informações concluída" aparecer na janela de saída CMake.

## <a name="set-a-breakpoint-build-and-run-on-linux"></a>Defina um ponto de ruptura, construa e execute no Linux

Por ser um aplicativo de desktop, você precisa fornecer algumas informações adicionais de configuração para a configuração de depuração.

1. Na exibição CMake Targets, clique com o botão direito do mouseBasicExampleGui e escolha **Debug e Configurações de lançamento** para abrir o arquivo launch.vs.json que está na subpasta oculta **.vs.** Esse arquivo é local para seu ambiente de desenvolvimento. Você poderá movê-lo para a raiz do seu projeto se você quiser realizar o check-in e salvá-lo com sua equipe. Neste arquivo, uma configuração foi adicionada para AppBasicExampleGui. Essas configurações padrão funcionam na maioria dos casos, mas não aqui. Por ser um aplicativo de desktop, você precisa fornecer algumas informações adicionais para iniciar o programa para que você possa vê-lo em sua máquina Linux.

1. Para encontrar o valor `DISPLAY` da variável ambiente na sua máquina Linux, execute este comando:

   ```cmd
   echo $DISPLAY
   ```

   Na configuração de AppBasicExampleGui, há um conjunto de parâmetros, "pipeArgs". Ele contém uma linha: "${debuggerCommand}". É o comando que lança gdb na máquina remota. O Visual Studio deve exportar o display para este contexto antes que esse comando seja executado. Por exemplo, se o valor `:1`do seu display for, modifique essa linha da seguinte forma:

   ```cmd
   "export DISPLAY=:1;${debuggerCommand}",
   ```

1. Inicie e depura sua aplicação. Abra a parada de itens de **inicialização select** na barra de ferramentas e escolha **AppBasicExampleGui**. Em seguida, escolha o ícone de reprodução verde na barra de ferramentas ou pressione **F5**. O aplicativo e suas dependências são construídos na máquina Linux remota, em seguida, lançado com o depurador Visual Studio conectado. Em seu computador Linux remoto, você deverá ver uma janela do aplicativo.

1. Mova o mouse para a janela do aplicativo e clique em um botão. O ponto de ruptura foi atingido. Pausas de execução do programa, o Visual Studio volta para o primeiro plano, e você vê o seu ponto de ruptura. Você também deve ver uma Janela de Console do Linux ser exibida no Visual Studio. A janela fornece saída da máquina Linux remota, `stdin`e também pode aceitar entrada para . Como qualquer janela do Visual Studio, você pode ancorá-la onde preferir vê-la. Sua posição é persistiu em sessões futuras.

   ![Janela de Console do Linux do Visual Studio](media/cmake-bullet3-linux-console.png)

1. Você pode inspecionar variáveis de aplicativo, objetos, threads e memória e percorrer seu código de forma interativa usando o Visual Studio. Mas desta vez, você está fazendo tudo em uma máquina Linux remota em vez de seu ambiente Windows local. Você pode escolher **Continuar** a deixar o aplicativo retomar e sair normalmente, ou você pode escolher o botão stop, assim como com a execução local.

1. Observe a janela Pilha de Chamadas e exiba as Chamadas para `x11OpenGLWindow`, já que o Visual Studio iniciou o aplicativo no Linux.

   ![Janela de pilha de chamadas mostrando a pilha de chamadas do Linux](media/cmake-bullet3-linux-callstack.png)

## <a name="what-you-learned"></a>O que você aprendeu

Neste tutorial, você clonou uma base de código diretamente do GitHub. Você construiu, executou e depurado no Windows sem modificações. Em seguida, você usou a mesma base de código, com pequenas alterações de configuração, para construir, executar e depurar em uma máquina Linux remota.

## <a name="next-steps"></a>Próximas etapas

Saiba mais sobre como configurar e depurar projetos do CMake no Visual Studio:

> [!div class="nextstepaction"]
> [Projetos do CMake no Visual Studio](cmake-projects-in-visual-studio.md)<br/><br/>
> [Configurar um projeto do Linux CMake](../linux/cmake-linux-project.md)<br/><br/>
> [Conectar-se ao computador Linux remoto](../linux/connect-to-your-remote-linux-computer.md)<br/><br/>
> [Personalizar as configurações de build do CMake](customize-cmake-settings.md)<br/><br/>
> [Configurar sessões de depuração do CMake](configure-cmake-debugging-sessions.md)<br/><br/>
> [Implantar, executar e depurar o projeto do Linux](../linux/deploy-run-and-debug-your-linux-project.md)<br/><br/>
> [Referência de configuração predefinida do CMake](cmake-predefined-configuration-reference.md)
>
