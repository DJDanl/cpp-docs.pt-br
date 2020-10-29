---
title: Configurar um projeto do Linux CMake no Visual Studio
description: Como definir as configurações de CMake do Linux no Visual Studio
ms.date: 08/08/2020
ms.openlocfilehash: c4c2d4682b6d18f9175a92a810b3f86d8132fc0c
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92921913"
---
# <a name="configure-a-linux-cmake-project-in-visual-studio"></a>Configurar um projeto do Linux CMake no Visual Studio

::: moniker range="msvc-140"
O suporte ao Linux está disponível no Visual Studio 2017 e posterior. Para ver a documentação dessas versões, defina a lista suspensa **versão** localizada acima do Sumário para o **Visual Studio 2017** ou **Visual Studio 2019** .
::: moniker-end

::: moniker range=">=msvc-150"
Este tópico descreve como adicionar uma configuração do Linux a um projeto do CMake que tem como alvo um sistema Linux remoto ou um subsistema do Windows para Linux (WSL). Ele continua a série que começou com a [criação de um projeto CMake do Linux no Visual Studio](cmake-linux-project.md). Se você estiver usando o MSBuild, consulte [configurar um projeto do MSBuild do Linux no Visual Studio](configure-a-linux-project.md)

## <a name="add-a-linux-configuration"></a>Adicionar uma configuração do Linux

Uma configuração pode ser usada para direcionar diferentes plataformas (Windows, WSL, um sistema remoto) com o mesmo código-fonte. Uma configuração também é usada para definir seus compiladores, passar variáveis de ambiente e personalizar como o CMake é invocado. O *CMakeSettings.jsno* arquivo especifica algumas ou todas as propriedades listadas em [Personalizar configurações de CMake](../build/customize-cmake-settings.md), além de propriedades adicionais que controlam as configurações de compilação no computador Linux remoto.
::: moniker-end

::: moniker range="msvc-150"
Para alterar as configurações padrão do cmake no Visual Studio 2017, escolha **CMake**  >  **alterar configurações de CMake**  >  **CMakeLists.txt** no menu principal. Ou clique com o botão direito do mouse em *CMakeLists.txt* em **Gerenciador de soluções** e escolha **alterar configurações de CMake** . Em seguida, o Visual Studio cria um novo *CMakeSettings.jsno* arquivo na pasta do projeto raiz. Para fazer alterações, abra o arquivo e modifique-o diretamente. Para obter mais informações, confira [Personalizar configurações do CMake](../build/customize-cmake-settings.md).

A configuração padrão para Linux-Debug no Visual Studio 2017 (e no Visual Studio 2019 versão 16,0) tem a seguinte aparência:

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

::: moniker range="msvc-160"
Para alterar as configurações padrão do CMake no Visual Studio 2019, na barra de ferramentas principal, abra a lista suspensa **configuração** e escolha **gerenciar configurações** .

![CMake gerenciar configurações](../build/media/vs2019-cmake-manage-configurations.png "Lista suspensa de configurações do CMake")

Esse comando abre o **Editor de configurações do cmake** , que pode ser usado para editar o *CMakeSettings.jsno* arquivo na pasta do projeto raiz. Você também pode abrir o arquivo com o editor de JSON clicando no botão **Editar JSON** no editor. Para obter mais informações, consulte [Personalizar configurações de CMake](../build/customize-cmake-settings.md).

A configuração padrão de Linux-Debug no Visual Studio 2019 versão 16,1 e posterior, tem a seguinte aparência:

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

No Visual Studio 2019 versão 16,6 ou posterior, ninja é o gerador padrão para configurações direcionadas a um sistema remoto ou WSL. Para obter mais informações, consulte esta postagem no [blog da equipe do C++](https://devblogs.microsoft.com/cppblog/linux-development-with-visual-studio-first-class-support-for-gdbserver-improved-build-times-with-ninja-and-updates-to-the-connection-manager/).

::: moniker-end
::: moniker range=">=msvc-150"
Para saber mais informações sobre essas configurações, confira [Referência do CMakeSettings.json](../build/cmakesettings-reference.md).

Quando você faz uma compilação:

- Se você estiver direcionando a um sistema remoto, o Visual Studio escolherá o primeiro sistema remoto na lista em **ferramentas** > **Opções** > **Cross Platform** > **Gerenciador de conexões** entre plataformas por padrão para destinos remotos.
- Se nenhuma conexão remota for encontrada, você será solicitado a criar uma. Para obter mais informações, confira [Conectar-se ao seu computador Linux remoto](connect-to-your-remote-linux-computer.md).

## <a name="choose-a-linux-target"></a>Escolha um destino do Linux

Quando você abre uma pasta de projeto CMake, o Visual Studio analisa o arquivo de *CMakeLists.txt* e especifica um destino do Windows de **depuração x86** . Para direcionar um sistema Linux remoto, você alterará as configurações do projeto com base no seu compilador do Linux. Por exemplo, se você estiver usando o GCC no Linux e compilando com as informações de depuração, você escolherá:  **linux-gcc-Debug** ou **linux-gcc-Release** .

Se você especificar um destino remoto do Linux, a origem será copiada para o sistema remoto.

Depois de selecionar um destino, o CMake é executado automaticamente no sistema Linux para gerar o cache CMake para seu projeto:

![Gerar cache CMake no Linux](media/cmake-linux-1.png "Gerar o cache CMake no Linux")

::: moniker-end
::: moniker range="msvc-160"

### <a name="target-windows-subsystem-for-linux"></a>Subsistema do Windows de destino para Linux

Se você estiver direcionando o subsistema do Windows para Linux (WSL), não precisará adicionar uma conexão remota.

Para direcionar o WSL, selecione **gerenciar configurações** no menu suspenso configuração na barra de ferramentas principal:

![CMake gerenciar configurações](../build/media/vs2019-cmake-manage-configurations.png "Lista suspensa de configurações do CMake")

A **CMakeSettings.jsna** janela é exibida.

![Adicionar configuração](media/cmake-linux-configurations.png "Adicionar uma configuração às configurações do CMake")

Pressione **Adicionar configuração** (o botão verde ' + ') e escolha **linux-gcc-Debug** ou **linux-gcc-Release** se estiver usando gcc. Use as variantes Clang se você estiver usando o conjunto de ferramentas Clang/LLVM.  Pressione **selecionar** e, em seguida, **Ctrl + S** para salvar a configuração.

**Visual Studio 2019 versão 16,1** Quando você direciona o WSL, o Visual Studio não precisa copiar arquivos de origem e manter duas cópias síncronas de sua árvore de Build porque o compilador no Linux tem acesso direto aos seus arquivos de origem no sistema de arquivos montado do Windows.
::: moniker-end
::: moniker range=">=msvc-150"

### <a name="intellisense"></a>IntelliSense

O C++ IntelliSense preciso requer acesso aos cabeçalhos C++ referenciados por seus arquivos de origem do C++. O Visual Studio usa automaticamente os cabeçalhos referenciados por um projeto CMake do Linux para o Windows para fornecer uma experiência do IntelliSense de fidelidade total. Para obter mais informações, veja [IntelliSense para cabeçalhos remotos](configure-a-linux-project.md#remote_intellisense).

### <a name="locale-setting"></a>Configuração de localidade

As configurações de linguagem do Visual Studio não são propagadas para destinos do Linux porque o Visual Studio não gerencia nem configura pacotes instalados. As mensagens mostradas na janela de saída, como erros de compilação, são mostradas usando o idioma e a localidade do destino do Linux. Você precisará configurar seus destinos do Linux para a localidade desejada.

## <a name="additional-settings"></a>Configurações adicionais

Use as configurações a seguir para executar comandos no sistema Linux antes e depois da compilação, e antes da geração de CMake. Os valores podem ser qualquer comando válido no sistema remoto. A saída é canalizada para o Visual Studio.

```json
{
      "remotePrebuildCommand": "",
      "remotePreGenerateCommand": "",
      "remotePostbuildCommand": "",
}
```

## <a name="next-steps"></a>Próximas etapas

[Configurar sessões de depuração do CMake](../build/configure-cmake-debugging-sessions.md?toc=/cpp/linux/toc.json&bc=/cpp/_breadcrumb/toc.json)

## <a name="see-also"></a>Veja também

[Trabalhando com propriedades de projeto](../build/working-with-project-properties.md)<br/>
[Personalizar as configurações do CMake](../build/customize-cmake-settings.md)<br/>
[Referência de configuração predefinida do CMake](../build/cmake-predefined-configuration-reference.md)

::: moniker-end
