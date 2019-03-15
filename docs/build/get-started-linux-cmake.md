---
title: Criar projetos multiplataforma do C++ no Visual Studio
description: Este tutorial mostra como configurar, compilar e depurar um projeto do CMake de software livre em C++ no Visual Studio que tem como alvo tanto Linux quanto Windows.
author: mikeblome
ms.topic: tutorial
ms.date: 03/05/2019
ms.openlocfilehash: deb2c91d6d09d8945e5eb57a7ac742c5b1705e83
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824214"
---
# <a name="tutorial-create-c-cross-platform-projects-in-visual-studio"></a>Tutorial: Criar projetos multiplataforma do C++ no Visual Studio 

Desenvolvimento do Visual Studio C e C++ não é mais apenas para Windows. Este tutorial mostra como usar o Visual Studio para desenvolvimento multiplataforma em C++ com base no CMake sem precisar criar ou gerar projetos do Visual Studio. Quando você abre uma pasta que contém um arquivo CMakeLists.txt, o Visual Studio define as configurações de IntelliSense e build automaticamente. Você pode rapidamente começar a editar, compilar e depurar seu código localmente no Windows e, em seguida, alternar a configuração para fazer o mesmo em Linux, tudo de dentro do Visual Studio.

Neste tutorial, você aprenderá como:

> [!div class="checklist"]
> * clonar um projeto do CMake de software livre do GitHub
> * abra o projeto no Visual Studio 
> * compilar e depurar um destino de executável no Windows
> * Adicionar uma conexão a um computador Linux
> * compilar e depurar o mesmo destino no Linux

## <a name="prerequisites"></a>Pré-requisitos

- Configurar o Visual Studio para Desenvolvimento em C++ Multiplataforma
    - Primeiro você precisa ter o [Visual Studio instalado](https://visualstudio.microsoft.com/vs/). Em seguida, confirme que você tem as cargas de trabalho **Desenvolvimento para área de trabalho com C++** e **Desenvolvimento em Linux com C++** instaladas. A instalação mínima é de apenas 3 GB. Dependendo da sua velocidade de download, a instalação não deverá levar mais de 10 minutos.
- Configurar um computador Linux para desenvolvimento em C++ multiplataforma
    - O Visual Studio não exige nenhuma distribuição específica do Linux. O sistema operacional pode ser executado em um computador físico, em uma VM, na nuvem ou no WSL (Subsistema Windows para Linux). No entanto, para este tutorial, um ambiente gráfico é necessário; portanto, o WSL não é recomendado porque ele se destina principalmente a operações de linha de comando.
    - As ferramentas que o Visual Studio requer no computador Linux são: Compiladores C++, GDB, ssh e zip. Em sistemas baseados em Debian, você pode instalar essas dependências da seguinte maneira.
    
    ```cmd
        sudo apt install -y openssh-server build-essential gdb zip
    ```
    - O Visual Studio requer que o computador Linux tenha uma versão recente do CMake com o modo de servidor habilitado (pelo menos 3.8). A Microsoft produz um build universal do CMake que você pode instalar em qualquer distribuição do Linux. É recomendável usar esse build para garantir que você tenha os recursos mais recentes. Você pode obter os binários do CMake da [bifurcação da Microsoft do repositório CMake](https://github.com/Microsoft/CMake/releases) no GitHub. Vá para aquela página e baixe a versão que corresponde à arquitetura do seu sistema no computador Linux, em seguida, marque-o como um executável:
    
    ```cmd
        wget <path to binary>
        chmod +x cmake-3.11.18033000-MSVC_2-Linux-x86_64.sh
    ```
    - Você pode ver as opções para executar o script com `-–help`. É recomendável que você use a opção `–prefix` para especificar a instalação no caminho **usr/local** porque essa é a localização padrão em que o Visual Studio procura CMake. O exemplo a seguir mostra o script do Linux-x86_64. Altere conforme necessário se você estiver usando uma plataforma de destino diferente. 
    
    ```cmd
        sudo ./cmake-3.11.18033000-MSVC_2-Linux-x86_64.sh --skip-license --prefix=/usr/local
    ```
- Git para Windows instalado em seu computador Windows.
- Uma conta do GitHub.

## <a name="clone-an-open-source-cmake-project-from-github"></a>Clonar um projeto do CMake de software livre do GitHub

Este tutorial usa o SDK do Bullet Physics no GitHub, que fornece detecção de colisão e simulações de física para uma variedade de aplicativos diferentes. Inclui amostras de programas executáveis que são compilados e executados sem necessidade de escrever código adicional. Este tutorial não modifica nenhum código-fonte ou scripts de build. Para começar, clone o repositório bullet3 do GitHub no computador em que você tem o Visual Studio instalado. 

```cmd

git clone https://github.com/bulletphysics/bullet3.git

```

1. No menu principal do Visual Studio, escolha **Arquivo > Abrir > CMake** e navegue até o arquivo CMakeLists.txt na raiz do repositório bullet3 que você acabou de baixar.

    ![Menu do Visual Studio para Arquivo > Abrir > CMake](media/cmake-open-cmake.png)

    Assim que você abre a pasta, a estrutura de pastas fica visível no **Gerenciador de Soluções**.

    ![Exibição de pasta do Gerenciador de Soluções do Visual Studio](media/cmake-bullet3-solution-explorer.png)

    Essa exibição mostra exatamente o que está no disco, não uma exibição filtrada ou lógica. Por padrão, não mostra arquivos ocultos. 

2. Pressione o botão **Mostrar todos os arquivos** para ver todos os arquivos na pasta.

    ![Botão Mostrar Todos os Arquivos do Gerenciador de Soluções do Visual Studio](media/cmake-bullet3-show-all-files.png)

## <a name="switch-to-targets-view"></a>Mude para a exibição de destinos

Quando você abre uma pasta que usa CMake, o Visual Studio gera automaticamente o cache de CMake. Essa operação pode levar alguns minutos, dependendo do tamanho do seu projeto. 

1. Na **Janela de Saída**, selecione **Mostrar saída de** e, em seguida, escolha **CMake** para monitorar o status do processo de geração de cache. Quando a operação for concluída, é indicado "Extração de informações destino concluída".

    ![Janela de Saída do Visual Studio mostrando a saída do CMake](media/cmake-bullet3-output-window.png)

    Depois de essa operação ter sido concluída, o IntelliSense estará configurado, o projeto poderá ser compilado e você poderá depurar o aplicativo. O Visual Studio agora pode fornecer uma exibição lógica da solução com base em um dos destinos especificados nos arquivos CMakeLists. 

2. Use o botão **Soluções e Pastas** no **Gerenciador de Soluções** para alternar para exibição de destinos do CMake.

    ![Botão Soluções e Pastas no Gerenciador de Soluções para mostrar a exibição de destinos do CMake](media/cmake-bullet3-show-targets.png)

    Esta é a aparência dessa exibição para o SDK do Bullet:

    ![Exibição de destinos do CMake do Gerenciador de Soluções](media/cmake-bullet3-targets-view.png)

    A exibição de destinos fornece uma exibição mais intuitiva do que essa base de código-fonte. Você pode ver que alguns destinos são bibliotecas e outros são executáveis. 

3. Expanda um nó na exibição de destinos do CMake para ver seus arquivos de código-fonte, independentemente do local em que esses arquivos estejam no disco.

## <a name="set-a-breakpoint-build-and-run"></a>Definir um ponto de interrupção, compilar e executar

Nesta etapa, vamos depurar um programa de exemplo que demonstra a biblioteca do Bullet Physics.
  
1. Em **Gerenciador de Soluções**, selecione AppBasicExampleGui e expanda-o. 
1. Abra o arquivo `BasicExample.cpp`. 
1. Defina um ponto de interrupção que será atingido quando você clicar no aplicativo em execução. O evento de clique é tratado em um método dentro de uma classe auxiliar. Para rapidamente chegar lá:

    1. Selecione a `CommonRigidBodyBase` da qual o struct `BasicExample` é derivado perto da linha 30.
    1. Clique com o botão direito do mouse e escolha **Ir para Definição**. Agora você está no cabeçalho CommonRigidBodyBase.h. 
    1. Na exibição do navegador acima, sua fonte, você deve ver que você está no `CommonRigidBodyBase`. À direita, você pode selecionar membros para examinar. Clique na lista suspensa e selecione `mouseButtonCallback` para ir para a definição dessa função no cabeçalho.

        ![Barra de ferramentas da lista de membros do Visual Studio](media/cmake-bullet3-member-list-toolbar.png)

1. Coloque um ponto de interrupção na primeira linha nessa função. Isso será atingido quando você clica em um botão do mouse dentro da janela do aplicativo quando inicializado sob o depurador do Visual Studio.

1. Para iniciar o aplicativo, selecione a lista suspensa de inicialização com o ícone de reprodução que diz "Selecionar Item de Inicialização" na barra de ferramentas. Na lista suspensa, selecione AppBasicExampleGui.exe. O nome do executável agora é exibido no botão de inicialização:

    ![Lista suspensa de inicialização da barra de ferramentas do Visual Studio para Selecionar Item de Inicialização](media/cmake-bullet3-launch-button.png)

5.  Pressione o botão inicialização para compilar o aplicativo e as dependências necessárias e, em seguida, inicializá-lo com o depurador do Visual Studio anexado. Após alguns instantes, o aplicativo em execução é exibido:

    ![Visual Studio depurando um aplicativo do Windows](media/cmake-bullet3-launched.png)

6. Mova o mouse para a janela do aplicativo e, em seguida, clique em um botão para disparar o ponto de interrupção. Isso abre o Visual Studio novamente para o primeiro plano com o editor mostrando a linha em que a execução está em pausa. Você poderá inspecionar variáveis de aplicativo, objetos, threads e memória. Você pode percorrer seu código de forma interativa. Você pode clicar em **Continuar** para permitir que o aplicativo retome e sair dele normalmente ou encerrar a execução dentro do Visual Studio usando o botão Parar.

## <a name="add-an-explicit-windows-x64-debug-configuration"></a>Adicionar uma configuração x64-Debug do Windows explícita

Até agora, você está usando a configuração **x64-Debug** padrão para Windows. As configurações são como o Visual Studio entende que destino de plataforma ele vai usar para o CMake. A configuração padrão não é representada no disco. Quando você adiciona explicitamente uma configuração, o Visual Studio cria um arquivo chamado CMakeSettings.json que é preenchido com as definições para todas as configurações que você especifica. 

1. Adicione uma nova configuração clicando o a configuração de lista suspensa na barra de ferramentas e selecionando **Gerenciar Configurações…**

    ![Lista suspensa Gerenciar Configuração](media/cmake-bullet3-manage-configurations.png)

    A caixa de diálogo **Adicionar Configuração a CMakeSettings** será exibida.

    ![Caixa de diálogo Adicionar Configuração a CMakeSettings](media/cmake-bullet3-add-configuration-x64-debug.png)

    Essa caixa de diálogo mostra todas as configurações incluídas com o Visual Studio, bem como todas as configurações personalizadas que você pode criar. Se você quiser continuar a usar a configuração **x64-Debug** padrão, ela deverá ser a primeira a ser adicionada. Ao adicionar essa configuração, você poderá alternar entre as configurações Windows e Linux. Selecione **x64-Debug** e clique em **Selecionar**. Isso cria o arquivo CMakeSettings.json com uma configuração para **x64-Debug** e alterna o Visual Studio para usar essa configuração, em vez do padrão. Você verá que a lista suspensa configuração não diz mais "(default)" como parte do nome. Você pode usar qualquer nome que desejar para suas configurações, alterando o parâmetro de nome diretamente no CMakeSettings.json.

##  <a name="add-a-linux-configuration-and-connect-to-the-remote-machine"></a>Adicionar uma configuração do Linux e conectar-se ao computador remoto

1. Agora, adicione uma configuração do Linux. Clique com o botão direito do mouse no arquivo CMakeSettings.json na exibição **Gerenciador de Soluções** e selecione **Adicionar Configuração**. Você verá a mesma caixa de diálogo Adicionar Configuração a CMakeSettings de antes. Selecione **Linux-Debug** neste momento e salve o arquivo CMakeSettings.json. 
2. Agora, selecione **Linux-Debug** na configuração da lista suspensa.

    ![Inicie a lista suspensa de configuração com as opções X64-Debug e Linux-Debug](media/cmake-bullet3-linux-configuration-item.png)

    Se esta for a primeira vez que você está se conectando a um sistema Linux, a caixa de diálogo **Conectar-se ao sistema remoto** será exibida.

    ![Caixa de diálogo Conectar-se ao sistema remoto do Visual Studio](media/cmake-bullet3-connection-manager.png)

    Se você já tiver adicionado uma conexão remota, poderá abrir essa janela navegando até **Ferramentas > Opções > Multiplataforma > Gerenciador de Conexão**.
 
3. Forneça as informações de conexão em seu computador Linux e clique em **Conectar**. O Visual Studio adiciona esse computador como para CMakeSettings.json como seu padrão para **Linux-Debug**. Também obterá os cabeçalhos do seu computador remoto de modo que você obtenha IntelliSense específica para esse computador ao usá-lo. Agora o Visual Studio enviará arquivos para o computador remoto, em seguida, gerará o cache de CMake e, quando isso estiver pronto, o Visual Studio será configurado para usar a mesma base de origem que o computador Linux remoto. Essas etapas podem levar algum tempo, dependendo da velocidade da sua rede e da potência do computador remoto. Você saberá que isso foi concluído quando a mensagem "Extração de informações de destino concluída" for exibida na janela de Saída do CMake.

## <a name="set-a-breakpoint-build-and-run-on-linux"></a>Definir um ponto de interrupção, compilar e executar no Linux

Como esse é um aplicativo de desktop, você precisará fornecer algumas informações de configuração adicionais para a configuração de depuração. 

1. Na exibição de destinos do CMake, clique com o botão direito do mouse em AppBasicExampleGui e escolha **Configurações de Depuração e de Inicialização** para abrir o arquivo launch.vs.json que está na subpasta **.vs** oculta. Esse arquivo é local para seu ambiente de desenvolvimento. Você poderá movê-lo para a raiz do seu projeto se você quiser realizar o check-in e salvá-lo com sua equipe. Neste arquivo, foi adicionada uma configuração para AppBasicExampleGui. Essas configurações padrão funcionam na maioria dos casos, porém, uma vez que esse é um aplicativo de desktop, que você precisará fornecer algumas informações adicionais para iniciar o programa de modo que possa vê-lo em nosso computador Linux. 
2. Você precisa saber o valor da variável de ambiente `DISPLAY` em seu computador Linux; execute este comando para obtê-lo.

    ```cmd
    echo $DISPLAY
    ```

    Na configuração de AppBasicExampleGui, há uma matriz de parâmetros "pipeArgs". Lá, há uma linha "${debuggerCommand}". Esse é o comando que inicializa o gdb no computador remoto. O Visual Studio precisa exportar a exibição para este contexto antes que o comando seja executado. Por exemplo, se o valor da sua exibição for :1, modifique essa linha da seguinte maneira:

    ```cmd
    "export DISPLAY=:1;${debuggerCommand}",
    ```
3. Agora, para iniciar e depurar o nosso aplicativo, escolha a lista suspensa **Selecionar Item de Inicialização** na barra de ferramentas e escolha AppBasicExampleGui. Agora, pressione o botão ou pressione **F5**. Isso compilará o aplicativo e suas dependências no computador Linux remoto, em seguida, o inicializará com o depurador do Visual Studio anexado. Em seu computador Linux remoto, você deverá ver uma janela do aplicativo.

4. Move o mouse para a janela do aplicativo, clique em um botão e o ponto de interrupção será atingido. A execução do programa é pausada, o Visual Studio volta para o primeiro plano e você estará no ponto de interrupção. Você também deve ver uma Janela de Console do Linux ser exibida no Visual Studio. Esta janela fornece a saída do computador Linux remoto e também pode aceitar a entrada para `stdin`. Como qualquer janela do Visual Studio, ela pode ser encaixada no local que você preferir e sua posição será mantida em futuras sessões.

    ![Janela de Console do Linux do Visual Studio](media/cmake-bullet3-linux-console.png)

5. Você pode inspecionar variáveis de aplicativo, objetos, threads e memória e percorrer seu código de forma interativa usando o Visual Studio. Mas, desta vez, você está fazendo tudo isso em um computador Linux remoto, em vez de em seu ambiente local do Windows. Você pode clicar em **Continuar** para permitir que o aplicativo seja retomado e sia normalmente ou pode pressionar o botão Parar, assim como ocorre com a execução local.

6. Observe a janela Pilha de Chamadas e exiba as Chamadas para `x11OpenGLWindow`, já que o Visual Studio iniciou o aplicativo no Linux.

    ![Janela de pilha de chamadas mostrando a pilha de chamadas do Linux](media/cmake-bullet3-linux-callstack.png)

## <a name="what-you-learned"></a>O que você aprendeu 

Neste tutorial, você viu um código base clonado diretamente do GitHub e compilou, executou e depurou no Windows sem modificações. Essa mesma base de código, com pequenas alterações de configuração, foi compilada, executada e depurada em um computador Linux remoto. 

## <a name="next-steps"></a>Próximas etapas

Saiba mais sobre como configurar e depurar projetos do CMake no Visual Studio:

> [!div class="nextstepaction"]
> [Projetos de CMake no Visual Studio](cmake-projects-in-visual-studio.md)<br/><br/>
> [Configurar um projeto do Linux CMake](../linux/cmake-linux-project.md)<br/><br/>
> [Conectar-se ao computador Linux remoto](../linux/connect-to-your-remote-linux-computer.md)<br/><br/>
> [Personalizar as configurações de compilação do CMake](customize-cmake-settings.md)<br/><br/>
> [Configurar sessões de depuração do CMake](configure-cmake-debugging-sessions.md)<br/><br/>
> [Implantar, executar e depurar o projeto do Linux](../linux/deploy-run-and-debug-your-linux-project.md)<br/><br/>
> [Referência de configuração predefinida do CMake](cmake-predefined-configuration-reference.md)
> 
