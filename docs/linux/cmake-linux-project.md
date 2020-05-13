---
title: Criar e configurar um projeto CMake do Linux no Visual Studio
description: Como criar, configurar, editar e compilar um projeto CMake do Linux no Visual Studio
ms.date: 05/03/2020
ms.assetid: f8707b32-f90d-494d-ae0b-1d44425fdc25
ms.openlocfilehash: c12e32801c992f6ba3675327b9ae537890202a4c
ms.sourcegitcommit: 8a01ae145bc65f5bc90d6e47b4a1bdf47b073ee7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2020
ms.locfileid: "82765754"
---
# <a name="create-and-configure-a-linux-cmake-project"></a>Criar e configurar um projeto do Linux CMake

::: moniker range="vs-2015"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end

::: moniker range=">=vs-2017"

## <a name="before-you-begin"></a>Antes de começar

Primeiro, verifique se você tem a carga de trabalho **Desenvolvimento do Linux com C++** instalada, incluindo o componente do CMake. Veja [Instalar uma carga de trabalho do Linux para C++ no Visual Studio](download-install-and-setup-the-linux-development-workload.md).

No sistema Linux, verifique se os seguintes itens estão instalados:

- gcc
- gdb
- rsync
- zip
- Ninja-compilação

::: moniker-end

::: moniker range="vs-2019"

O suporte do Linux para projetos CMake exige que o computador de destino tenha uma versão recente do CMake. Geralmente, a versão oferecida pelo Gerenciador de pacotes padrão de uma distribuição não é recente o suficiente para dar suporte a todos os recursos exigidos pelo Visual Studio. O Visual Studio 2019 detecta se uma versão recente do CMake está instalada no sistema Linux. Se nenhum for encontrado, o Visual Studio mostrará uma barra de informações na parte superior do painel do editor. Ele oferece para instalar o CMake para você [https://github.com/Microsoft/CMake/releases](https://github.com/Microsoft/CMake/releases)do.

O suporte ao CMake no Visual Studio requer o suporte do modo de servidor que foi apresentado no CMake 3.8. No Visual Studio 2019 versão 3.14 ou posterior, é recomendável.

::: moniker-end

::: moniker range="vs-2017"

O suporte ao CMake no Visual Studio requer o suporte do modo de servidor que foi apresentado no CMake 3.8. Para obter uma variante CMake fornecida pela Microsoft, baixe os binários predefinidos mais recentes em [https://github.com/Microsoft/CMake/releases](https://github.com/Microsoft/CMake/releases).

Os binários são instalados `~/.vs/cmake`no. Depois de implantar os binários, seu projeto é regenerado automaticamente. Se o CMake especificado pelo `cmakeExecutable` campo em *CMakeSettings. JSON* for inválido (ele não existe ou é uma versão sem suporte) e os binários pré-criados estiverem presentes, o Visual Studio ignorará `cmakeExecutable` e usará os binários pré-criados.

:::moniker-end

::: moniker range="vs-2019"

## <a name="create-a-new-linux-cmake-project"></a>Criar um novo projeto CMake do Linux

Para criar um novo projeto CMake do Linux no Visual Studio 2019:

1. Selecione **Arquivo > Novo Projeto** no Visual Studio ou pressione **Ctrl + Shift + N**.
1. Defina a **Linguagem** como **C++** e pesquise "CMake". Em seguida, escolha **Avançar**. Insira um **Nome** e uma **Localização** e escolha **Criar**.

O Visual Studio cria um arquivo *CMakeLists. txt* mínimo com apenas o nome do executável e a versão mínima do cmake necessária. Você pode editar manualmente esse arquivo da maneira que desejar. O Visual Studio nunca substituirá suas alterações. Você pode especificar argumentos de linha de comando CMake e variáveis de ambiente neste arquivo. Clique com o botão direito do mouse no arquivo root *CMakeLists. txt* em **Gerenciador de soluções** e escolha **configurações de CMake para o projeto**. Para especificar opções para depuração, clique com o botão direito do mouse no nó do projeto e escolha **Depurar e iniciar configurações**.

::: moniker-end

::: moniker range=">=vs-2017"

## <a name="open-a-cmake-project-folder"></a>Abrir uma pasta de projeto do CMake

Quando você abre uma pasta que contém um projeto CMake existente, o Visual Studio usa variáveis no cache CMake para configurar automaticamente o IntelliSense e as compilações. A configuração local e as configurações de depuração são armazenadas em arquivos JSON. Opcionalmente, você pode compartilhar esses arquivos com outras pessoas que estejam usando o Visual Studio.

O Visual Studio não modifica os arquivos *CMakeLists. txt* . Ele é apenas deixado para que outras pessoas que trabalham no mesmo projeto possam continuar a usar suas ferramentas existentes. O Visual Studio gera novamente o cache quando você salva as edições em *CMakeLists. txt* ou em alguns casos para *CMakeSettings. JSON*. Mas se você estiver usando uma configuração de **cache existente** , o Visual Studio não modificará o cache.

Para obter informações gerais sobre o suporte do CMake no Visual Studio, confira [Projetos CMake no Visual Studio](../build/cmake-projects-in-visual-studio.md). Leia este primeiro antes de continuar aqui.

Para começar, escolha **arquivo** > **abrir** > **pasta** no menu principal ou digite outro tipo `devenv.exe <foldername>` em uma janela de prompt de comando do [desenvolvedor](../build/building-on-the-command-line.md) . A pasta que você abrir deve ter um arquivo *CMakeLists. txt* , junto com seu código-fonte.

O exemplo a seguir mostra um arquivo *CMakeLists. txt* simples e o arquivo. cpp:

```cpp
// hello.cpp

#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Hello from Linux CMake" << std::endl;
}
```

*CMakeLists. txt*:

```txt
cmake_minimum_required(VERSION 3.8)
project (hello-cmake)
add_executable(hello-cmake hello.cpp)
```

## <a name="choose-a-linux-target"></a>Escolha um destino do Linux

Assim que você abrir a pasta, o Visual Studio analisará o arquivo *CMakeLists. txt* e especificará um destino do Windows de **depuração x86**. Para ter como destino um sistema Linux remoto, altere as configurações de projeto para **Linux-Debug** ou **Linux-Release**. (Confira [Definir as configurações do CMake para Linux](#configure_cmake_linux) abaixo.)

::: moniker-end

::: moniker range="vs-2019"

Para direcionar o subsistema do Windows para Linux, clique em **gerenciar configurações** no menu suspenso de configuração na barra de ferramentas principal. Em seguida, pressione o botão **Adicionar configuração** e escolha **WSL-Debug** ou **WSL-Release** se estiver usando gcc. Use as variantes Clang se estiver usando o conjunto de ferramentas Clang/LLVM.

**Visual Studio 2019 versão 16,1** Ao direcionar WSL, não é necessário copiar fontes ou cabeçalhos. Isso ocorre porque o compilador no Linux tem acesso direto aos seus arquivos de origem no sistema de arquivos do Windows. (No Windows 10 versão 1903 e posterior, os aplicativos do Windows da mesma forma podem acessar os arquivos de cabeçalho do Linux diretamente. O Visual Studio ainda não aproveita esse recurso.)

::: moniker-end

::: moniker range=">=vs-2017"

O Visual Studio escolhe o primeiro sistema remoto na lista em **ferramentas** > **Opções** > **Gerenciador de conexões** **entre plataformas** > por padrão para destinos remotos. Se nenhuma conexão remota for encontrada, você será solicitado a criar uma. Para obter mais informações, confira [Conectar-se ao seu computador Linux remoto](connect-to-your-remote-linux-computer.md).

Se você especificar um destino remoto do Linux, a origem será copiada para o sistema remoto.

Depois que você seleciona um destino, CMake é executado automaticamente no sistema Linux para gerar o cache do CMake para o projeto.

![Gerar cache CMake no Linux](media/cmake-linux-1.png "Gerar o cache CMake no Linux")

Para fornecer suporte ao IntelliSense para cabeçalhos em sistemas Linux remotos, o Visual Studio os copia automaticamente do computador Linux para um diretório do computador Windows local. Para obter mais informações, veja [IntelliSense para cabeçalhos remotos](configure-a-linux-project.md#remote_intellisense).

## <a name="debug-the-cmake-project"></a><a name="debug_cmake_project"></a> Depurar o projeto CMake

Para depurar seu código no sistema de destino especificado, defina um ponto de interrupção. Selecione o destino CMake como o item de inicialização no menu da barra de ferramentas ao lado da configuração do projeto. Em seguida, escolha **&#x23f5; iniciar** na barra de ferramentas ou pressione **F5**.

Para personalizar os argumentos de linha de comando do programa, pressione o botão **alternar destinos** na parte superior da **Gerenciador de soluções** e escolha **exibição de destinos**. Em seguida, clique com o botão direito do mouse no destino e selecione **Configurações de Depuração e de Inicialização**. Esse comando abre ou cria um arquivo de configuração de *inicialização. vs. JSON* que contém informações sobre seu programa. Para especificar o local dos arquivos de origem, adicione uma propriedade **sourceFileMap** ao arquivo, conforme mostrado neste exemplo:

```json
"MIMode": "gdb",
"externalConsole": true,
"sourceFileMap": {
"c/Users/USER/source/repos/CMAKEPROJECTNAME": "C:\\Users\\USER\\source\\repos\\CMAKEPROJECTNAME"
},
"remoteMachineName": "${debugInfo.remoteMachineName}",
```

Para especificar argumentos adicionais, adicione-os na matriz JSON `args`. Para obter mais informações, confira [Projetos Open Folder para C++](../build/open-folder-projects-cpp.md) e [Configurar sessões de depuração do CMake](../build/configure-cmake-debugging-sessions.md).

## <a name="configure-cmake-settings-for-linux"></a><a name="configure_cmake_linux"></a>Definir configurações de CMake para Linux

Um arquivo *CMakeSettings. JSON* em um projeto CMake Linux pode especificar todas as propriedades listadas em [Personalizar configurações de CMake](../build/customize-cmake-settings.md), além de propriedades adicionais que controlam as configurações de compilação no computador Linux remoto.

::: moniker-end

::: moniker range="vs-2019"

Para alterar as configurações padrão do CMake no Visual Studio 2019, na barra de ferramentas principal, abra a lista suspensa **configuração** e escolha **gerenciar configurações**.

![CMake gerenciar configurações](../build/media/vs2019-cmake-manage-configurations.png "Lista suspensa de configurações do CMake")

Esse comando abre o **Editor de configurações do cmake**, que pode ser usado para editar o arquivo *CMakeSettings. JSON* na pasta do projeto raiz. Também é possível abrir o arquivo diretamente clicando no botão **Editar JSON** no editor. Para obter mais informações, consulte [Personalizar configurações de CMake](../build/customize-cmake-settings.md).

A configuração Linux-Debug padrão no Visual Studio 2019 versão 16.1 e posteriores é exibida aqui:

```json
{
      "name": "Linux-Debug",
      "generator": "Unix Makefiles",
      "configurationType": "Debug",
      "cmakeExecutable": "/usr/bin/cmake",
      "remoteCopySourcesExclusionList": [ ".vs", ".git", "out" ],
      "cmakeCommandArgs": "",
      "buildCommandArgs": "",
      "ctestCommandArgs": "",
      "inheritEnvironments": [ "linux_x64" ],
      "remoteMachineName": "${defaultRemoteMachineName}",
      "remoteCMakeListsRoot": "$HOME/.vs/${projectDirName}/${workspaceHash}/src",
      "remoteBuildRoot": "$HOME/.vs/${projectDirName}/${workspaceHash}/out/build/${name}",
      "remoteInstallRoot": "$HOME/.vs/${projectDirName}/${workspaceHash}/out/install/${name}",
      "remoteCopySources": true,
      "rsyncCommandArgs": "-t --delete --delete-excluded",
      "remoteCopyBuildOutput": false,
      "remoteCopySourcesMethod": "rsync",
      "addressSanitizerRuntimeFlags": "detect_leaks=0",
      "variables": []
    }
  ]
}
```

::: moniker-end

::: moniker range="vs-2017"

Para alterar as configurações padrão do cmake no Visual Studio 2017, escolha **CMake** > **alterar CMake configurações** > **CMakeLists. txt** no menu principal. Ou clique com o botão direito do mouse em *CMakeSettings. txt* em **Gerenciador de soluções** e escolha **alterar configurações de CMake**. Em seguida, o Visual Studio cria um novo arquivo *CMakeSettings. JSON* na pasta do projeto raiz. Você pode abrir o arquivo usando o editor **Configurações do CMake** ou modificando o arquivo diretamente. Para obter mais informações, confira [Personalizar configurações do CMake](../build/customize-cmake-settings.md).

O exemplo seguinte mostra a configuração padrão para Linux-Debug no Visual Studio 2017 (e Visual Studio 2019 versão 16.0) com base no exemplo de código anterior:

```json
{
      "name": "Linux-Debug",
      "generator": "Unix Makefiles",
      "remoteMachineName": "${defaultRemoteMachineName}",
      "configurationType": "Debug",
      "remoteCMakeListsRoot": "/var/tmp/src/${workspaceHash}/${name}",
      "cmakeExecutable": "/usr/local/bin/cmake",
      "buildRoot": "${env.LOCALAPPDATA}\\CMakeBuilds\\${workspaceHash}\\build\\${name}",
      "installRoot": "${env.LOCALAPPDATA}\\CMakeBuilds\\${workspaceHash}\\install\\${name}",
      "remoteBuildRoot": "/var/tmp/build/${workspaceHash}/build/${name}",
      "remoteInstallRoot": "/var/tmp/build/${workspaceHash}/install/${name}",
      "remoteCopySources": true,
      "remoteCopySourcesOutputVerbosity": "Normal",
      "remoteCopySourcesConcurrentCopies": "10",
      "remoteCopySourcesMethod": "rsync",
      "remoteCopySourcesExclusionList": [".vs", ".git"],
      "rsyncCommandArgs" : "-t --delete --delete-excluded",
      "remoteCopyBuildOutput" : "false",
      "cmakeCommandArgs": "",
      "buildCommandArgs": "",
      "ctestCommandArgs": "",
      "inheritEnvironments": [ "linux-x64" ]
}
```

::: moniker-end

::: moniker range=">=vs-2017"

Para saber mais informações sobre essas configurações, confira [Referência do CMakeSettings.json](../build/cmakesettings-reference.md).

## <a name="optional-settings"></a>Configurações opcionais

Você pode usar as seguintes configurações opcionais para obter mais controle:

```json
{
      "remotePrebuildCommand": "",
      "remotePreGenerateCommand": "",
      "remotePostbuildCommand": "",
}
```

Essas opções permitem que você execute comandos no sistema Linux antes e depois do build e antes da geração do CMake. Os valores podem ser qualquer comando válido no sistema remoto. A saída é canalizada para o Visual Studio.

## <a name="see-also"></a>Confira também

[Trabalhando com Propriedades do Projeto](../build/working-with-project-properties.md)<br/>
[Projetos do CMake no Visual Studio](../build/cmake-projects-in-visual-studio.md)<br/>
[Conectar-se ao computador Linux remoto](connect-to-your-remote-linux-computer.md)<br/>
[Personalizar as configurações do CMake](../build/customize-cmake-settings.md)<br/>
[Configurar sessões de depuração do CMake](../build/configure-cmake-debugging-sessions.md)<br/>
[Implantar, executar e depurar o projeto do Linux](deploy-run-and-debug-your-linux-project.md)<br/>
[Referência de configuração predefinida do CMake](../build/cmake-predefined-configuration-reference.md)

::: moniker-end
