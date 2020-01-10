---
title: Criar projetos multiplataforma do C++ no Visual Studio
description: Como configurar, compilar e depurar um C++ projeto CMake de software livre no Visual Studio que tem como alvo o Linux e o Windows.
ms.topic: tutorial
ms.date: 01/08/2020
ms.openlocfilehash: 83d71d3078e892a51aef159b225fecec2b581f20
ms.sourcegitcommit: 5f276064779d90a4cfda758f89e0c0f1e4d1a188
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/09/2020
ms.locfileid: "75791757"
---
# <a name="tutorial-create-c-cross-platform-projects-in-visual-studio"></a>Tutorial: criar C++ projetos de plataforma cruzada no Visual Studio

Desenvolvimento do Visual Studio C e C++ não é mais apenas para Windows. Este tutorial mostra como usar o Visual Studio para C++ o desenvolvimento de plataforma cruzada no Windows e no Linux. Ele é baseado em CMake, portanto, você não precisa criar nem gerar projetos do Visual Studio. Quando você abre uma pasta que contém um arquivo CMakeLists. txt, o Visual Studio configura o IntelliSense e as configurações de compilação automaticamente. Você pode começar rapidamente a editar, criar e depurar seu código localmente no Windows. Em seguida, alterne sua configuração para fazer o mesmo no Linux, tudo de dentro do Visual Studio.

Neste tutorial, você aprenderá como:

> [!div class="checklist"]
> * clonar um projeto do CMake de software livre do GitHub
> * abra o projeto no Visual Studio
> * compilar e depurar um destino de executável no Windows
> * Adicionar uma conexão a um computador Linux
> * compilar e depurar o mesmo destino no Linux

## <a name="prerequisites"></a>{1&gt;{2&gt;Pré-requisitos&lt;2}&lt;1}

* Configurar o Visual Studio para Desenvolvimento em C++ Multiplataforma
  * Primeiro, [Instale o Visual Studio](https://visualstudio.microsoft.com/vs/) e escolha o **desenvolvimento de C++ desktop com** o e o **desenvolvimento do Linux C++ com cargas**de trabalho. Essa instalação mínima é de apenas 3 GB. Dependendo da velocidade de download, a instalação não deve levar mais de 10 minutos.

* Configurar um computador Linux para desenvolvimento em C++ multiplataforma
  * O Visual Studio não exige nenhuma distribuição específica do Linux. O sistema operacional pode ser executado em um computador físico, em uma VM ou na nuvem. Você também pode usar o subsistema do Windows para Linux (WSL). No entanto, para este tutorial, é necessário um ambiente gráfico. WSL não é recomendado aqui, porque ele é destinado principalmente para operações de linha de comando.
  * O Visual Studio requer essas ferramentas no computador Linux: C++ compiladores, gdb, SSH, rsync e zip. Em sistemas baseados em Debian, você pode usar esse comando para instalar essas dependências:

    ```cmd
    sudo apt install -y openssh-server build-essential gdb rsync zip
    ```

  * O Visual Studio requer uma versão recente do CMake no computador Linux que tem o modo de servidor habilitado (pelo menos 3,8). A Microsoft produz um build universal do CMake que você pode instalar em qualquer distribuição do Linux. Recomendamos que você use essa compilação para garantir que tem os recursos mais recentes. Você pode obter os binários do CMake da [bifurcação da Microsoft do repositório CMake](https://github.com/Microsoft/CMake/releases) no GitHub. Acesse essa página e baixe a versão que corresponde à arquitetura do sistema em seu computador Linux e, em seguida, marque-a como um executável:

    ```cmd
    wget <path to binary>
    chmod +x cmake-3.11.18033000-MSVC_2-Linux-x86_64.sh
    ```

  * Você pode ver as opções para executar o script com `-–help`. Recomendamos que você use a opção `–prefix` para especificar a instalação no caminho **/usr** , porque **/usr/bin** é o local padrão onde o Visual Studio procura CMake. O exemplo a seguir mostra o script do Linux-x86_64. Altere-o conforme necessário se você estiver usando uma plataforma de destino diferente.

    ```cmd
    sudo ./cmake-3.11.18033000-MSVC_2-Linux-x86_64.sh --skip-license --prefix=/usr
    ```

* Git para Windows instalado em seu computador Windows.
* Uma conta do GitHub.

## <a name="clone-an-open-source-cmake-project-from-github"></a>Clonar um projeto do CMake de software livre do GitHub

Este tutorial usa o SDK de física do marcador no GitHub. Ele fornece detecção de colisão e simulações de física para muitos aplicativos. O SDK inclui programas executáveis de exemplo que são compilados e executados sem a necessidade de escrever código adicional. Este tutorial não modifica nenhum código-fonte ou scripts de compilação. Para iniciar, clone o repositório *bullet3* do GitHub no computador em que você tem o Visual Studio instalado.

```cmd
git clone https://github.com/bulletphysics/bullet3.git
```

1. No menu principal do Visual Studio, escolha **arquivo > abrir > CMake**. Navegue até o arquivo CMakeLists. txt na raiz do repositório bullet3 que você acabou de baixar.

    ![Menu do Visual Studio para Arquivo > Abrir > CMake](media/cmake-open-cmake.png)

    Assim que você abrir a pasta, sua estrutura de pastas ficará visível no **Gerenciador de soluções**.

    ![Exibição de pasta do Gerenciador de Soluções do Visual Studio](media/cmake-bullet3-solution-explorer.png)

    Essa exibição mostra exatamente o que está no disco, não uma exibição filtrada ou lógica. Por padrão, não mostra arquivos ocultos.

1. Escolha o botão **Mostrar todos os arquivos** para ver todos os arquivos na pasta.

    ![Botão Mostrar Todos os Arquivos do Gerenciador de Soluções do Visual Studio](media/cmake-bullet3-show-all-files.png)

## <a name="switch-to-targets-view"></a>Mude para a exibição de destinos

Quando você abre uma pasta que usa CMake, o Visual Studio gera automaticamente o cache de CMake. Essa operação pode levar alguns minutos, dependendo do tamanho do seu projeto.

1. Na **Janela de Saída**, selecione **Mostrar saída de** e, em seguida, escolha **CMake** para monitorar o status do processo de geração de cache. Quando a operação for concluída, é indicado "Extração de informações destino concluída".

   ![Janela de Saída do Visual Studio mostrando a saída do CMake](media/cmake-bullet3-output-window.png)

   Após a conclusão dessa operação, o IntelliSense é configurado. Você pode compilar o projeto e depurar o aplicativo. O Visual Studio agora mostra uma exibição lógica da solução, com base nos destinos especificados nos arquivos CMakeLists.

1. Use o botão **Soluções e Pastas** no **Gerenciador de Soluções** para alternar para exibição de destinos do CMake.

   ![Botão Soluções e Pastas no Gerenciador de Soluções para mostrar a exibição de destinos do CMake](media/cmake-bullet3-show-targets.png)

   Esta é a aparência dessa exibição para o SDK do Bullet:

   ![Exibição de destinos do CMake do Gerenciador de Soluções](media/cmake-bullet3-targets-view.png)

   A exibição de destinos fornece uma exibição mais intuitiva do que essa base de código-fonte. Você pode ver que alguns destinos são bibliotecas e outros são executáveis.

1. Expanda um nó na exibição de destinos do CMake para ver seus arquivos de código-fonte, independentemente do local em que esses arquivos estejam no disco.

## <a name="add-an-explicit-windows-x64-debug-configuration"></a>Adicionar uma configuração x64-Debug do Windows explícita

O Visual Studio cria uma configuração de **depuração x64** padrão para o Windows. As configurações são como o Visual Studio entende que destino de plataforma ele vai usar para o CMake. A configuração padrão não é representada no disco. Quando você adiciona uma configuração explicitamente, o Visual Studio cria um arquivo chamado *CMakeSettings. JSON*. Ele é populado com configurações para todas as configurações que você especificar.

1. Adicione uma nova configuração. Abra a lista suspensa **configuração** na barra de ferramentas e selecione **gerenciar configurações**.

   ![Lista suspensa Gerenciar Configuração](media/cmake-bullet3-manage-configurations.png)

   O [Editor de configurações do cmake](customize-cmake-settings.md) é aberto. Selecione o sinal de adição verde no lado esquerdo do editor para adicionar uma nova configuração. A caixa de diálogo **Adicionar configuração ao CMakeSettings** é exibida.

   ![Caixa de diálogo Adicionar Configuração a CMakeSettings](media/cmake-bullet3-add-configuration-x64-debug.png)

   Essa caixa de diálogo mostra todas as configurações incluídas no Visual Studio, além de quaisquer configurações personalizadas que você criar. Se você quiser continuar usando uma configuração de **depuração x64** , ela deverá ser a primeira que você adicionar. Selecione **x64-depurar**e, em seguida, escolha o botão **selecionar** . O Visual Studio cria o arquivo CMakeSettings. JSON com uma configuração para **a depuração x64**e salva-o no disco. Você pode usar qualquer nome que desejar para suas configurações, alterando o parâmetro de nome diretamente no CMakeSettings.json.

## <a name="set-a-breakpoint-build-and-run-on-windows"></a>Definir um ponto de interrupção, compilar e executar no Windows

Nesta etapa, vamos depurar um programa de exemplo que demonstra a biblioteca do Bullet Physics.
  
1. Em **Gerenciador de Soluções**, selecione AppBasicExampleGui e expanda-o.

1. Abra o arquivo `BasicExample.cpp`.

1. Defina um ponto de interrupção que é atingido quando você clica no aplicativo em execução. O evento de clique é tratado em um método dentro de uma classe auxiliar. Para rapidamente chegar lá:

   1. Selecione `CommonRigidBodyBase` do qual o `BasicExample` de struct é derivado. Em torno da linha 30.

   1. Clique com o botão direito do mouse e escolha **Ir para Definição**. Agora você está no cabeçalho CommonRigidBodyBase. h.

   1. No modo de exibição de navegador acima da fonte, você verá que está na `CommonRigidBodyBase`. À direita, você pode selecionar membros para examinar. Abra a lista suspensa e selecione `mouseButtonCallback` para ir para a definição dessa função no cabeçalho.

      ![Barra de ferramentas da lista de membros do Visual Studio](media/cmake-bullet3-member-list-toolbar.png)

1. Coloque um ponto de interrupção na primeira linha nessa função. Ele é atingido quando você clica em um botão do mouse dentro da janela do aplicativo, quando executado no depurador do Visual Studio.

1. Para iniciar o aplicativo, selecione a lista suspensa iniciar na barra de ferramentas. É aquele com o ícone de reprodução verde que indica "selecionar item de inicialização". Na lista suspensa, selecione AppBasicExampleGui. exe. O nome do executável agora é exibido no botão de inicialização:

   ![Lista suspensa de inicialização da barra de ferramentas do Visual Studio para Selecionar Item de Inicialização](media/cmake-bullet3-launch-button.png)

1. Escolha o botão Iniciar para criar o aplicativo e as dependências necessárias e, em seguida, inicie-o com o depurador do Visual Studio anexado. Após alguns instantes, o aplicativo em execução é exibido:

   ![Visual Studio depurando um aplicativo do Windows](media/cmake-bullet3-launched.png)

1. Mova o mouse para a janela do aplicativo e, em seguida, clique em um botão para disparar o ponto de interrupção. O ponto de interrupção traz o Visual Studio de volta para o primeiro plano e o editor mostra a linha em que a execução é pausada. Você pode inspecionar as variáveis do aplicativo, os objetos, os threads e a memória, ou percorrer o código interativamente. Escolha **continuar** para permitir que o aplicativo seja retomado e, em seguida, encerre-o normalmente. Ou pare a execução no Visual Studio usando o botão parar.

## <a name="add-a-linux-configuration-and-connect-to-the-remote-machine"></a>Adicionar uma configuração do Linux e conectar-se ao computador remoto

1. Adicione uma configuração do Linux. Clique com o botão direito do mouse no arquivo CMakeSettings.json na exibição **Gerenciador de Soluções** e selecione **Adicionar Configuração**. Você verá a mesma caixa de diálogo Adicionar Configuração a CMakeSettings de antes. Selecione **Linux-depurar** desta vez e salve o arquivo CMakeSettings. JSON (CTRL + s).

1. Selecione **Linux-depurar** na lista suspensa configuração.

   ![Inicie a lista suspensa de configuração com as opções X64-Debug e Linux-Debug](media/cmake-bullet3-linux-configuration-item.png)

   Se for a primeira vez que você está se conectando a um sistema Linux, a caixa de diálogo **conectar ao sistema remoto** será exibida.

   ![Caixa de diálogo Conectar-se ao sistema remoto do Visual Studio](media/cmake-bullet3-connection-manager.png)

   Se você já tiver adicionado uma conexão remota, poderá abrir essa janela navegando até **ferramentas > opções > Gerenciador de conexões > plataforma cruzada**.

1. Forneça as [informações de conexão para seu computador Linux](/cpp/linux/connect-to-your-remote-linux-computer) e escolha **conectar**. O Visual Studio adiciona esse computador como ao CMakeSettings. JSON como sua conexão padrão para o **Linux-Debug**. Ele também efetua pull dos cabeçalhos de seu computador remoto, para que você obtenha o [IntelliSense específico para essa conexão remota](/cpp/linux/configure-a-linux-project?view=vs-2019#remote_intellisense). Em seguida, o Visual Studio envia os arquivos para o computador remoto e gera o cache CMake no sistema remoto. Essas etapas podem levar algum tempo, dependendo da velocidade da rede e da potência da sua máquina remota. Você saberá que ela está completa quando a mensagem "extração de informações de destino concluída" aparecer na janela saída do CMake.

## <a name="set-a-breakpoint-build-and-run-on-linux"></a>Definir um ponto de interrupção, compilar e executar no Linux

Como é um aplicativo de área de trabalho, você precisa fornecer algumas informações de configuração adicionais para a configuração de depuração.

1. Na exibição destinos de CMake, clique com o botão direito do mouse em AppBasicExampleGui e escolha **depurar e iniciar configurações** para abrir o arquivo launch. vs. JSON que está na subpasta Hidden **. vs** . Esse arquivo é local para seu ambiente de desenvolvimento. Você poderá movê-lo para a raiz do seu projeto se você quiser realizar o check-in e salvá-lo com sua equipe. Neste arquivo, uma configuração foi adicionada para AppBasicExampleGui. Essas configurações padrão funcionam na maioria dos casos, mas não aqui. Como é um aplicativo de área de trabalho, você precisa fornecer algumas informações adicionais para iniciar o programa para que possa vê-lo em seu computador Linux.

1. Para localizar o valor da variável de ambiente `DISPLAY` em seu computador Linux, execute este comando:

   ```cmd
   echo $DISPLAY
   ```

   Na configuração de AppBasicExampleGui, há uma matriz de parâmetros, "pipeArgs". Ele contém uma linha: "$ {debuggerCommand}". É o comando que inicia o gdb no computador remoto. O Visual Studio deve exportar a exibição para esse contexto antes que esse comando seja executado. Por exemplo, se o valor de sua exibição for `:1`, modifique essa linha da seguinte maneira:

   ```cmd
   "export DISPLAY=:1;${debuggerCommand}",
   ```

1. Inicie e depure seu aplicativo. Abra a lista suspensa **selecionar item de inicialização** na barra de ferramentas e escolha **AppBasicExampleGui**. Em seguida, escolha o ícone de reprodução verde na barra de ferramentas ou pressione **F5**. O aplicativo e suas dependências são criados no computador Linux remoto e, em seguida, iniciados com o depurador do Visual Studio anexado. Em seu computador Linux remoto, você deverá ver uma janela do aplicativo.

1. Mova o mouse para a janela do aplicativo e clique em um botão. O ponto de interrupção é atingido. A execução do programa é pausada, o Visual Studio volta para o primeiro plano e você vê o ponto de interrupção. Você também deve ver uma Janela de Console do Linux ser exibida no Visual Studio. A janela fornece a saída do computador Linux remoto e também pode aceitar entrada para `stdin`. Como qualquer janela do Visual Studio, você pode encaixá-la onde preferir vê-la. Sua posição é mantida em sessões futuras.

   ![Janela de Console do Linux do Visual Studio](media/cmake-bullet3-linux-console.png)

1. Você pode inspecionar variáveis de aplicativo, objetos, threads e memória e percorrer seu código de forma interativa usando o Visual Studio. Mas, desta vez, você está fazendo tudo isso em um computador Linux remoto em vez de em seu ambiente Windows local. Você pode escolher **continuar** para permitir que o aplicativo seja retomado e encerrado normalmente, ou pode escolher o botão parar, assim como ocorre com a execução local.

1. Observe a janela Pilha de Chamadas e exiba as Chamadas para `x11OpenGLWindow`, já que o Visual Studio iniciou o aplicativo no Linux.

   ![Janela de pilha de chamadas mostrando a pilha de chamadas do Linux](media/cmake-bullet3-linux-callstack.png)

## <a name="what-you-learned"></a>O que você aprendeu

Neste tutorial, você clonou uma base de código diretamente do GitHub. Você criou, executou e depurau no Windows sem modificações. Em seguida, você usou a mesma base de código, com alterações de configuração secundárias, para compilar, executar e depurar em um computador Linux remoto.

## <a name="next-steps"></a>{1&gt;{2&gt;Próximas etapas&lt;2}&lt;1}

Saiba mais sobre como configurar e depurar projetos do CMake no Visual Studio:

> [!div class="nextstepaction"]
> [Projetos do CMake no Visual Studio](cmake-projects-in-visual-studio.md)<br/><br/>
> [Configurar um projeto do Linux CMake](../linux/cmake-linux-project.md)<br/><br/>
> [Conectar-se ao computador Linux remoto](../linux/connect-to-your-remote-linux-computer.md)<br/><br/>
> [Personalizar as configurações de compilação do CMake](customize-cmake-settings.md)<br/><br/>
> [Configurar sessões de depuração do CMake](configure-cmake-debugging-sessions.md)<br/><br/>
> [Implantar, executar e depurar o projeto do Linux](../linux/deploy-run-and-debug-your-linux-project.md)<br/><br/>
> [Referência de configuração predefinida do CMake](cmake-predefined-configuration-reference.md)
>
