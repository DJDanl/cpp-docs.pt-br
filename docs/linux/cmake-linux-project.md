---
title: Criar e configurar um projeto CMake do Linux no Visual Studio
description: Como criar, configurar, editar e compilar um projeto CMake do Linux no Visual Studio
ms.date: 10/04/2019
ms.assetid: f8707b32-f90d-494d-ae0b-1d44425fdc25
ms.openlocfilehash: d781d1995a4c9a60932d498d2ad7cfea97ee023f
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80077660"
---
# <a name="create-and-configure-a-linux-cmake-project"></a>Criar e configurar um projeto do Linux CMake

::: moniker range="vs-2015"

O suporte ao Linux está disponível no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range="vs-2019"

Para criar um novo projeto CMake do Linux no Visual Studio 2019:

1. Selecione **Arquivo > Novo Projeto** no Visual Studio ou pressione **Ctrl + Shift + N**.
1. Defina a **Linguagem** como **C++** e pesquise "CMake". Em seguida, escolha **Avançar**. Insira um **Nome** e uma **Localização** e escolha **Criar**.

O Visual Studio cria um arquivo mínimo CMakeLists.txt apenas com o nome do executável e a versão mínima necessária do CMake. Você pode editar manualmente esse arquivo da maneira que desejar. O Visual Studio nunca substituirá suas alterações. Você pode especificar argumentos de linha de comando CMake e variáveis de ambiente clicando com o botão direito do mouse no arquivo root CMakeLists. txt em **Gerenciador de soluções** e escolhendo **configurações de CMake para o projeto**. Para especificar opções para depuração, clique com o botão direito do mouse no nó do projeto e escolha **Depurar e iniciar configurações**.

::: moniker-end

Quando você abre uma pasta que contém um projeto CMake existente, o Visual Studio usa variáveis no cache CMake para configurar o IntelliSense e compila automaticamente. As definições de configuração e depuração locais são armazenadas em arquivos JSON que opcionalmente podem ser compartilhados com outras pessoas que estão usando o Visual Studio.

O Visual Studio não modifica os arquivos CMakeLists.txt, de modo que outras pessoas trabalhando no mesmo projeto possam continuar usando quaisquer ferramentas que já estejam usando. O Visual Studio gera novamente o cache quando você salva as edições em CMakeLists. txt ou em alguns casos para CMakeSettings. JSON. Mas, se você estiver usando uma configuração de **Cache Existente**, o Visual Studio não modificará o cache.

Para obter informações gerais sobre o suporte do CMake no Visual Studio, confira [Projetos CMake no Visual Studio](../build/cmake-projects-in-visual-studio.md). Leia este primeiro antes de continuar aqui.

## <a name="before-you-begin"></a>Antes de começar

Primeiro, verifique se você tem a carga de trabalho **Desenvolvimento do Linux com C++** instalada, incluindo o componente do CMake. Veja [Instalar uma carga de trabalho do Linux para C++ no Visual Studio](download-install-and-setup-the-linux-development-workload.md).

No sistema Linux, verifique se os seguintes itens estão instalados:

- gcc
- gdb
- rsync
- zip

::: moniker range="vs-2019"

O suporte do Linux para projetos do CMake requer que uma versão recente do CMake seja instalada no computador de destino. Muitas vezes, a versão oferecida pelo gerenciador de pacotes padrão de uma distribuição não é recente o suficiente para dar suporte a todos os recursos necessários para o Visual Studio. O Visual Studio 2019 detecta se uma versão recente do CMake está instalada no sistema Linux. Se nenhuma for encontrada, o Visual Studio mostrará uma barra de informações na parte superior do painel do editor que oferece a instalação para você em [https://github.com/Microsoft/CMake/releases](https://github.com/Microsoft/CMake/releases).

O suporte ao CMake no Visual Studio requer o suporte do modo de servidor que foi apresentado no CMake 3.8. No Visual Studio 2019 versão 3.14 ou posterior, é recomendável.

::: moniker-end

::: moniker range="vs-2017"

O suporte ao CMake no Visual Studio requer o suporte do modo de servidor que foi apresentado no CMake 3.8. Para uma variante CMake fornecida pela Microsoft, baixe os binários predefinidos mais recentes em [https://github.com/Microsoft/CMake/releases](https://github.com/Microsoft/CMake/releases).

Os binários serão instalados no `~/.vs/cmake`. Depois de implantar os binários, seu projeto será automaticamente regenerado. Se o CMake especificado pelo campo `cmakeExecutable` em `CMakeSettings.json` for inválido (não existir ou for uma versão sem suporte) e os binários predefinidos estiverem presentes, o Visual Studio ignorará `cmakeExecutable` e usará os binários predefinidos.

:::moniker-end

## <a name="open-a-folder"></a>Abrir uma pasta

Para começar, escolha **Arquivo** > **Abrir** > **Pasta** no menu principal ou digite `devenv.exe <foldername>` na linha de comando. A pasta que você abrir deverá conter um arquivo CMakeLists.txt, junto com o código-fonte.
O exemplo a seguir mostra um arquivo CMakeLists.txt simples e o arquivo .cpp:

```cpp
// hello.cpp

#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Hello from Linux CMake" << std::endl;
}
```

CMakeLists.txt:

```cmd
cmake_minimum_required(VERSION 3.8)
project (hello-cmake)
add_executable(hello-cmake hello.cpp)
```

## <a name="choose-a-linux-target"></a>Escolha um destino do Linux

Assim que você abre a pasta, o Visual Studio analisa o arquivo CMakeLists.txt e especifica um destino do Windows de **x86-Debug**. Para ter como destino um sistema Linux remoto, altere as configurações de projeto para **Linux-Debug** ou **Linux-Release**. (Confira [Definir as configurações do CMake para Linux](#configure_cmake_linux) abaixo.)

::: moniker range="vs-2019"

Para direcionar o subsistema do Windows para Linux, clique em **Gerenciar Configurações** na lista suspensa de configuração na barra de ferramentas principal. Em seguida, pressione o botão **Adicionar Configuração** e escolha **WSL-Debug** ou **WSL-Release** se estiver usando o GCC ou as variantes do Clang se estiver usando o conjunto de ferramentas do Clang/LLVM.

**Visual Studio 2019 versão 16.1** Ao ter como destino o WSL, não é necessário usar cópia de fontes ou cabeçalhos, pois o compilador no Linux tem acesso direto ao sistema de arquivos do Windows em que os arquivos de origem estão localizados. (Na versão 1903 e posteriores do Windows, os aplicativos do Windows podem acessar igualmente os arquivos de cabeçalho do Linux diretamente, mas o Visual Studio ainda não pode aproveitar esse recurso.)

::: moniker-end

Para destinos remotos, por padrão, o Visual Studio escolhe o primeiro sistema remoto da lista em **Ferramentas** > **Opções** > **Multiplataforma** > **Gerenciador de Conexões**. Se nenhuma conexão remota for encontrada, será solicitado que você crie uma. Para obter mais informações, confira [Conectar-se ao seu computador Linux remoto](connect-to-your-remote-linux-computer.md).

Se você especificar um destino remoto do Linux, a origem será copiada para o sistema remoto.

Depois que você seleciona um destino, CMake é executado automaticamente no sistema Linux para gerar o cache do CMake para o projeto.

![Gerar cache CMake no Linux](media/cmake-linux-1.png "Gerar o cache CMake no Linux")

Para fornecer suporte ao IntelliSense para cabeçalhos em sistemas Linux remotos, o Visual Studio os copia automaticamente do computador Linux para um diretório do computador Windows local. Para obter mais informações, veja [IntelliSense para cabeçalhos remotos](configure-a-linux-project.md#remote_intellisense).

## <a name="debug-the-cmake-project"></a><a name="debug_cmake_project"></a> Depurar o projeto CMake

Para depurar o código no sistema de destino de depuração especificado, defina um ponto de interrupção, selecione o destino do CMake como o item de inicialização no menu da barra de ferramentas ao lado da configuração do projeto e escolha **&#x23f5; Iniciar** na barra de ferramentas ou pressione F5.

Para personalizar os argumentos de linha de comando do programa, pressione o botão **Alternar Destinos** na parte superior do **Gerenciador de Soluções** e escolha **Exibição de Destinos**. Em seguida, clique com o botão direito do mouse no destino e selecione **Configurações de Depuração e de Inicialização**. Isso abre ou cria um arquivo de configuração launch.vs.json que contém as informações do seu programa. Para especificar o local dos arquivos de origem, adicione uma propriedade **sourceFileMap** ao arquivo, conforme mostrado neste exemplo:

```json
"MIMode": "gdb",
"externalConsole": true,
"sourceFileMap": {
"c/Users/USER/source/repos/CMAKEPROJECTNAME": "C:\\Users\\USER\\source\\repos\\CMAKEPROJECTNAME"
},
"remoteMachineName": "${debugInfo.remoteMachineName}",
```

Para especificar argumentos adicionais, adicione-os na matriz JSON `args`. Para obter mais informações, confira [Projetos Open Folder para C++](../build/open-folder-projects-cpp.md) e [Configurar sessões de depuração do CMake](../build/configure-cmake-debugging-sessions.md).

## <a name="configure-cmake-settings-for-linux"></a><a name="configure_cmake_linux"></a> Definir as configurações do CMake para Linux

Um arquivo CMakeSettings.json em um projeto do CMake Linux pode especificar todas as propriedades listadas em [Personalizar configurações do CMake](../build/customize-cmake-settings.md), além de propriedades adicionais que controlam as configurações de build no computador Linux remoto.

::: moniker range="vs-2019"

Para alterar as configurações padrão do CMake no Visual Studio 2019, na barra de ferramentas principal, abra a lista suspensa **Configuração** e escolha **Gerenciar Configurações**.

![CMake gerenciar configurações](../build/media/vs2019-cmake-manage-configurations.png "Lista suspensa de configurações do CMake")

Isso abre o **Editor de Configurações do CMake** que você pode usar para editar o arquivo `CMakeSettings.json` na pasta raiz do projeto. Também é possível abrir o arquivo diretamente clicando no botão **Editar JSON** no editor. Para saber mais, confira [Customize CMake Settings](../build/customize-cmake-settings.md) (Personalizar Configurações do CMake).

::: moniker-end

::: moniker range="vs-2017"

Para alterar as configurações do CMake padrão no Visual Studio 2017, escolha **CMake | Alterar as Configurações do CMake | CMakeLists.txt** no menu principal ou clique com o botão direito do mouse em CMakeSettings.txt no **Gerenciador de Soluções** e escolha **Alterar as Configurações do CMake**. O Visual Studio então cria um novo arquivo `CMakeSettings.json` na pasta raiz do projeto. Você pode abrir o arquivo usando o editor **Configurações do CMake** ou modificando o arquivo diretamente. Para obter mais informações, confira [Personalizar configurações do CMake](../build/customize-cmake-settings.md).

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

::: moniker range="vs-2019"

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
[Referência de configuração predefinida do CMake](../build/cmake-predefined-configuration-reference.md)<br/>
