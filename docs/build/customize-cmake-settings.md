---
title: Personalizar as configurações de build do CMake no Visual Studio
ms.date: 08/20/2019
helpviewer_keywords:
- CMake build settings
ms.openlocfilehash: ecd2964e035cbf3d48a737164b0067720e9b6b9a
ms.sourcegitcommit: 0df462d79ad617296095c3012badc2fe669bab2f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/21/2019
ms.locfileid: "69887040"
---
# <a name="customize-cmake-build-settings"></a>Personalizar as configurações de build do CMake

::: moniker range="vs-2019"

No Visual Studio 2019 e posterior, adicione configurações e personalize suas definições usando o **Editor de Configurações do CMake**. O editor deve ser uma alternativa mais simples para editar manualmente o arquivo *CMakeSettings. JSON* , mas se você preferir editar o arquivo diretamente, você pode clicar no link **Editar JSON** no canto superior direito do editor. 

Para abrir o editor, clique na lista suspensa **Configuração** na barra de ferramentas principal e escolha **Gerenciar Configurações**.

![Lista suspensa de configurações do CMake](media/vs2019-cmake-manage-configurations.png)

Agora você vê o **Editor de Configurações** com as configurações instaladas à esquerda. 

![Editor de Configurações do CMake](media/cmake-settings-editor.png)

Por padrão, o `x64-Debug` Visual Studio fornece uma configuração. Você pode adicionar configurações adicionais clicando no sinal de adição verde. As configurações que você vê no editor podem variar dependendo da configuração selecionada.

As opções escolhidas no editor são gravadas em um arquivo chamado *CMakeSettings. JSON*. Esse arquivo fornece argumentos de linha de comando e variáveis de ambiente que são passadas para o CMake quando você compila os projetos. O Visual Studio nunca modifica *CMakeLists. txt* automaticamente; usando *CMakeSettings. JSON* , você pode personalizar a compilação por meio do Visual Studio enquanto deixa os arquivos de projeto do cmake intocados para que outras pessoas em sua equipe possam consumi-los com quaisquer ferramentas que estejam usando.

## <a name="cmake-general-settings"></a>Configurações Gerais do CMake

As seguintes configurações estão disponíveis sob o título **Geral**:

### <a name="configuration-name"></a>Nome da configuração

Corresponde à configuração **name**. Esse nome aparece na lista C++ suspensa configuração. Use a macro `${name}` para compor outros valores de propriedade, como caminhos.


### <a name="configuration-type"></a>Tipo de configuração

Corresponde à configuração **configurationType**. Define o tipo de configuração de build para o gerador selecionado. Os valores compatíveis no momento são "Debug", "MinSizeRel", "Release" e "RelWithDebInfo". Ele é mapeado para [CMAKE_BUILD_TYPE](https://cmake.org/cmake/help/latest/variable/CMAKE_BUILD_TYPE.html).

### <a name="toolset"></a>Conjunto de Ferramentas

Corresponde à configuração **inheritedEnvironments**. Define o ambiente do compilador que é usado para criar a configuração selecionada. Os valores compatíveis dependem do tipo de configuração. Para criar um ambiente personalizado, escolha o link **Editar JSON** no canto superior direito do editor de configurações e edite o arquivo *CMakeSettings. JSON* diretamente.

### <a name="cmake-toolchain-file"></a>Arquivo de cadeia de ferramentas do CMake

Caminho para o [arquivo CMake ferramentas](https://cmake.org/cmake/help/latest/variable/CMAKE_TOOLCHAIN_FILE.html). Esse caminho é passado para CMake como "-DCMAKE_TOOLCHAIN_FILE = \<FilePath >". Os arquivos ferramentas especificam locais de compiladores e utilitários de ferramentas, além de outras informações relacionadas à plataforma de destino e ao compilador. Por padrão, o Visual Studio usa o [arquivo vcpkg ferramentas](https://github.com/microsoft/vcpkg/blob/master/docs/examples/installing-and-using-packages.md#cmake) se essa configuração não for especificada. 

### <a name="build-root"></a>Raiz de build

Corresponde a **buildRoot**. Mapeia para [CMAKE_BINARY_DIR](https://cmake.org/cmake/help/v3.15/variable/CMAKE_BINARY_DIR.html)e especifica onde criar o cache CMAKE. A pasta especificada será criada se ela não existir.

## <a name="command-arguments"></a>Argumentos de comando

As seguintes configurações estão disponíveis sob o título **Argumentos de comando**:

### <a name="cmake-command-arguments"></a>Argumentos de comando do CMake

Corresponde a **cmakeCommandArgs**. Especifica quaisquer [Opções de linha de comando](https://cmake.org/cmake/help/latest/manual/cmake.1.html) adicionais passadas para CMake. exe.

### <a name="build-command-arguments"></a>Argumentos de comando de build

Corresponde a **buildCommandArgs**. Especifica opções adicionais a serem passadas para o sistema de compilação subjacente. Por exemplo, passar `-v` ao usar o gerador ninja força o ninja a gerar linhas de comando.


### <a name="ctest-command-arguments"></a>Argumentos de comando do CTest

Corresponde a **ctestCommandArgs**. Especifica [Opções de linha de comando](https://cmake.org/cmake/help/v3.15/manual/ctest.1.html) adicionais para passar para CTest ao executar testes.

## <a name="general-settings-for-remote-builds"></a>Configurações gerais para builds remotos

Para configurações como o Linux que usam builds remotos, as seguintes configurações também estão disponíveis:

### <a name="rsync-command-arguments"></a>Argumentos de comando do rsync

Opções de linha de comando adicionais passadas para o [rsync](https://download.samba.org/pub/rsync/rsync.html), uma ferramenta de cópia de arquivos rápida e versátil. 

## <a name="cmake-variables-and-cache"></a>Variáveis e cache do CMake

Essas configurações permitem que você defina as variáveis CMake e salve-as em *CMakeSettings. JSON*. Eles são passados para CMake no momento da compilação e substituem quaisquer valores no arquivo *CMakeLists. txt* . Use esta seção da mesma forma que usaria a CMakeGUI para exibir uma lista de todas as variáveis do CMake disponíveis para edição. Clique no botão **Salvar e gerar cache** para exibir uma lista de todas as variáveis do CMake disponíveis para edição, incluindo variáveis avançadas (de acordo com a CMakeGUI). Você pode filtrar a lista pelo nome da variável. 

Corresponde a **variáveis**. Contém um par nome-valor de variáveis CMake passadas como *_valor_ de _nome_=* **-D** para CMake. Se as instruções de compilação do projeto CMake especificarem a adição de quaisquer variáveis diretamente ao arquivo de cache CMake, recomendamos que você as adicione aqui em vez disso.

## <a name="advanced-settings"></a>Configurações avançadas

### <a name="cmake-generator"></a>Gerador do CMake

Corresponde ao **gerador**. Mapeia para a opção CMake **-G** e especifica o [gerador de CMake](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html) a ser usado. Essa propriedade também pode ser usada como uma macro, `${generator}`, ao compor outros valores de propriedade. No momento, o Visual Studio dá suporte aos seguintes geradores do CMake:

  - "Ninja"
  - "UNIX Makefiles"
  - "Visual Studio 16 2019"
  - "Visual Studio 16 2019 Win64"
  - "Visual Studio 16 2019 ARM"
  - "Visual Studio 15 2017"
  - "Visual Studio 15 2017 Win64"
  - "Visual Studio 15 2017 ARM"
  - "Visual Studio 14 2015"
  - "Visual Studio 14 2015 Win64"
  - "Visual Studio 14 2015 ARM"
  
Como o ninja foi projetado para velocidades de compilação rápidas em vez de flexibilidade e função, ele é definido como o padrão. No entanto, alguns projetos do CMake podem não conseguir executar o build corretamente usando o Ninja. Se isso ocorrer, você poderá instruir o CMake para gerar um projeto do Visual Studio em vez disso.

### <a name="intellisense-mode"></a>Modo do IntelliSense

O modo IntelliSense usado pelo mecanismo do IntelliSense. Se nenhum modo for selecionado, o Visual Studio será herdado do conjunto de ferramentas especificado.  

### <a name="install-directory"></a>Diretório de instalação

O diretório no qual o CMake instala destinos. Mapeia para [CMAKE_INSTALL_PREFIX](https://cmake.org/cmake/help/latest/variable/CMAKE_INSTALL_PREFIX.html). 

### <a name="cmake-executable"></a>Executável do CMake

O caminho completo para o executável do programa CMake, incluindo o nome do arquivo e a extensão. Ele permite que você use uma versão personalizada do CMake com o Visual Studio. Para builds remotos, especifique a localização do CMake no computador remoto.

Para configurações como o Linux que usam builds remotos, as seguintes configurações também estão disponíveis:

### <a name="remote-cmakeliststxt-root"></a>Raiz remota de CMakeLists.txt

O diretório no computador remoto que contém o arquivo raiz *CMakeLists. txt* .

### <a name="remote-install-root"></a>Raiz de instalação remota

O diretório no computador remoto no qual o CMake instala os destinos. Mapeia para [CMAKE_INSTALL_PREFIX](https://cmake.org/cmake/help/latest/variable/CMAKE_INSTALL_PREFIX.html). 

### <a name="remote-copy-sources"></a>Origens de cópia remota

Especifica se os arquivos de origem devem ser copiados para o computador remoto e permite que você especifique se deseja usar o rsync ou SFTP. 

## <a name="directly-edit-cmakesettingsjson"></a>Editar o CMakeSettings.json diretamente

Você também pode editar diretamente o *CMakeSettings. JSON* para criar configurações personalizadas. O **Editor de Configurações** tem um botão **Editar JSON** no canto superior direito que abre o arquivo para edição. 

O seguinte exemplo mostra uma configuração de exemplo, que pode ser usada como ponto de partida:

```json
    {
      "name": "x86-Debug",
      "generator": "Ninja",
      "configurationType": "Debug",
      "inheritEnvironments": [ "msvc_x86" ],
      "buildRoot": "${env.USERPROFILE}\\CMakeBuilds\\${workspaceHash}\\build\\${name}",
      "installRoot": "${env.USERPROFILE}\\CMakeBuilds\\${workspaceHash}\\install\\${name}",
      "cmakeCommandArgs": "",
      "buildCommandArgs": "-v",
      "ctestCommandArgs": ""
    },
```

O JSON IntelliSense ajuda a editar o arquivo *CMakeSettings. JSON* :

   ![CMake JSON IntelliSense](media/cmake-json-intellisense.png "CMake JSON IntelliSense")

O editor JSON também o informa quando você escolhe configurações incompatíveis.

Para obter mais informações sobre cada uma das propriedades no arquivo, confira [Referência de esquema de CMakeSettings.json](cmakesettings-reference.md).

::: moniker-end

::: moniker range="<=vs-2017"

O Visual Studio 2017 fornece várias configurações do CMake que definem como o CMake.exe é invocado para criar o cache do CMake para determinado projeto. Para adicionar uma nova configuração, clique na lista suspensa na barra de ferramentas de configuração e escolha **Gerenciar Configurações**:

   ![Gerenciar configurações do CMake](media/cmake-manage-configurations.png)

Você pode escolher na lista de configurações predefinidas:

   ![Configurações predefinidas do CMake](media/cmake-configurations.png)

Na primeira vez que você selecionar uma configuração, o Visual Studio criará um arquivo *CMakeSettings. JSON* na pasta raiz do projeto. Esse arquivo é usado para recriar o arquivo de cache do CMake, por exemplo, após uma operação de **Limpeza**. 

Para adicionar uma configuração adicional, clique com o botão direito do mouse em *CMakeSettings. JSON* e escolha **Adicionar configuração**. 

   ![Adicionar configuração do CMake](media/cmake-add-configuration.png "Adicionar configuração do CMake")

Você também pode editar o arquivo usando o **Editor de Configurações do CMake**. Clique com o botão direito do mouse em *CMakeSettings. JSON* em **Gerenciador de soluções** e escolha **Editar configurações de CMake**. Ou selecione **Gerenciar Configurações** na lista suspensa de configurações na parte superior da janela do editor. 

Você também pode editar diretamente o *CMakeSettings. JSON* para criar configurações personalizadas. O seguinte exemplo mostra uma configuração de exemplo, que pode ser usada como ponto de partida:

```json
    {
      "name": "x86-Debug",
      "generator": "Ninja",
      "configurationType": "Debug",
      "inheritEnvironments": [ "msvc_x86" ],
      "buildRoot": "${env.USERPROFILE}\\CMakeBuilds\\${workspaceHash}\\build\\${name}",
      "installRoot": "${env.USERPROFILE}\\CMakeBuilds\\${workspaceHash}\\install\\${name}",
      "cmakeCommandArgs": "",
      "buildCommandArgs": "-v",
      "ctestCommandArgs": ""
    },
```

O JSON IntelliSense ajuda a editar o arquivo *CMakeSettings. JSON* :

   ![CMake JSON IntelliSense](media/cmake-json-intellisense.png "CMake JSON IntelliSense")

Para obter mais informações sobre cada uma das propriedades no arquivo, confira [Referência de esquema de CMakeSettings.json](cmakesettings-reference.md).

::: moniker-end

## <a name="see-also"></a>Consulte também

[Projetos do CMake no Visual Studio](cmake-projects-in-visual-studio.md)<br/>
[Configurar um projeto do Linux CMake](../linux/cmake-linux-project.md)<br/>
[Conectar-se ao computador Linux remoto](../linux/connect-to-your-remote-linux-computer.md)<br/>
[Configurar sessões de depuração do CMake](configure-cmake-debugging-sessions.md)<br/>
[Implantar, executar e depurar o projeto do Linux](../linux/deploy-run-and-debug-your-linux-project.md)<br/>
[Referência de configuração predefinida do CMake](cmake-predefined-configuration-reference.md)
