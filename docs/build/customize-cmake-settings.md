---
title: Personalizar as configurações de build do CMake no Visual Studio
ms.date: 08/20/2019
helpviewer_keywords:
- CMake build settings
ms.openlocfilehash: c6bd1404799ccc9ad6b689646cd066849d48fca8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328688"
---
# <a name="customize-cmake-build-settings"></a>Personalizar as configurações de build do CMake

::: moniker range="vs-2019"

No Visual Studio 2019 e posterior, adicione configurações e personalize suas definições usando o **Editor de Configurações do CMake**. O editor pretende ser uma alternativa mais simples para editar manualmente o arquivo *CMakeSettings.json,* mas se você preferir editar o arquivo diretamente, você pode clicar no link **Editar JSON** no canto superior direito do editor.

Para abrir o editor, clique na lista suspensa **Configuração** na barra de ferramentas principal e escolha **Gerenciar Configurações**.

![Lista suspensa de configurações do CMake](media/vs2019-cmake-manage-configurations.png)

Agora você vê o **Editor de Configurações** com as configurações instaladas à esquerda.

![Editor de Configurações do CMake](media/cmake-settings-editor.png)

O Visual `x64-Debug` Studio fornece uma configuração por padrão. Você pode adicionar configurações adicionais clicando no sinal verde mais. As configurações que você vê no editor podem variar dependendo de qual configuração é selecionada.

As opções escolhidas no editor são escritas em um arquivo chamado *CMakeSettings.json*. Esse arquivo fornece argumentos de linha de comando e variáveis de ambiente que são passadas para o CMake quando você compila os projetos. O Visual Studio nunca modifica *cMakeLists.txt* automaticamente; usando *CMakeSettings.json,* você pode personalizar a compilação através do Visual Studio, deixando os arquivos do projeto CMake intocados para que outros da sua equipe possam consumi-los com quaisquer ferramentas que estejam usando.

## <a name="cmake-general-settings"></a>Configurações Gerais do CMake

As seguintes configurações estão disponíveis sob o título **Geral**:

### <a name="configuration-name"></a>Nome da configuração

Corresponde à configuração **name**. Este nome aparece na estada de configuração C++. Use a macro `${name}` para compor outros valores de propriedade, como caminhos.

### <a name="configuration-type"></a>Tipo de configuração

Corresponde à configuração **configurationType**. Define o tipo de configuração de build para o gerador selecionado. Os valores compatíveis no momento são "Debug", "MinSizeRel", "Release" e "RelWithDebInfo". Ele mapeia para [CMAKE_BUILD_TYPE.](https://cmake.org/cmake/help/latest/variable/CMAKE_BUILD_TYPE.html)

### <a name="toolset"></a>Conjunto de Ferramentas

Corresponde à configuração **inheritedEnvironments**. Define o ambiente do compilador usado para construir a configuração selecionada. Os valores compatíveis dependem do tipo de configuração. Para criar um ambiente personalizado, escolha o link **Editar JSON** no canto superior direito do editor de Configurações e edite diretamente o arquivo *CMakeSettings.json.*

### <a name="cmake-toolchain-file"></a>Arquivo de cadeia de ferramentas do CMake

Caminho para o [arquivo CMake toolchain](https://cmake.org/cmake/help/latest/variable/CMAKE_TOOLCHAIN_FILE.html). Esse caminho é passado para CMake \<como "-DCMAKE_TOOLCHAIN_FILE = filepath>". Os arquivos toolchain especificam locais de compiladores e utilitários de cadeia de ferramentas e outras informações relacionadas à plataforma de destino e compilador. Por padrão, o Visual Studio usa o [arquivo vcpkg toolchain](https://github.com/microsoft/vcpkg/blob/master/docs/examples/installing-and-using-packages.md#cmake) se essa configuração não for especificada.

### <a name="build-root"></a>Raiz de build

Corresponde a **buildRoot**. [Mapeia para CMAKE_BINARY_DIR](https://cmake.org/cmake/help/v3.15/variable/CMAKE_BINARY_DIR.html)e especifica onde criar o cache CMake. A pasta especificada é criada se ela não existir.

## <a name="command-arguments"></a>Argumentos de comando

As seguintes configurações estão disponíveis sob o título **Argumentos de comando**:

### <a name="cmake-command-arguments"></a>Argumentos de comando do CMake

Corresponde a **cmakeCommandArgs**. Especifica quaisquer [opções](https://cmake.org/cmake/help/latest/manual/cmake.1.html) adicionais de linha de comando passadas para CMake.exe.

### <a name="build-command-arguments"></a>Argumentos de comando de build

Corresponde à **construçãoCommandArgs**. Especifica switches adicionais para passar para o sistema de compilação subjacente. Por exemplo, `-v` passar ao usar o gerador Ninja força ninja a saída de linhas de comando.

### <a name="ctest-command-arguments"></a>Argumentos de comando do CTest

Corresponde ao **ctestCommandArgs**. Especifica [opções](https://cmake.org/cmake/help/v3.15/manual/ctest.1.html) adicionais de linha de comando para passar para CTest ao executar testes.

## <a name="general-settings-for-remote-builds"></a>Configurações gerais para builds remotos

Para configurações como o Linux que usam builds remotos, as seguintes configurações também estão disponíveis:

### <a name="rsync-command-arguments"></a>Argumentos de comando do rsync

Opções adicionais de linha de comando passaram para [rsync](https://download.samba.org/pub/rsync/rsync.html), uma ferramenta rápida e versátil de cópia de arquivos.

## <a name="cmake-variables-and-cache"></a>Variáveis e cache do CMake

Essas configurações permitem definir variáveis CMake e salvá-las em *CMakeSettings.json*. Eles são passados para CMake no momento da compilação e anulam quaisquer valores que estejam no arquivo *CMakeLists.txt.* Use esta seção da mesma forma que usaria a CMakeGUI para exibir uma lista de todas as variáveis do CMake disponíveis para edição. Clique no botão **Salvar e gerar cache** para exibir uma lista de todas as variáveis do CMake disponíveis para edição, incluindo variáveis avançadas (de acordo com a CMakeGUI). Você pode filtrar a lista por nome variável.

Corresponde às **variáveis**. Contém um par de variáveis CMake de valor de nome passadas como valor de * _nome_=* **-D** para CMake. Se as instruções de construção do projeto CMake especificarem a adição de quaisquer variáveis diretamente ao arquivo de cache CMake, recomendamos que você as adicione aqui.

## <a name="advanced-settings"></a>Configurações avançadas

### <a name="cmake-generator"></a>Gerador do CMake

Corresponde ao **gerador**. Mapeia para o switch CMake **-G** e especifica o [gerador CMake](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html) para usar. Essa propriedade também pode ser usada como uma macro, `${generator}`, ao compor outros valores de propriedade. No momento, o Visual Studio dá suporte aos seguintes geradores do CMake:

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
  
Como ninja é projetado para velocidades de construção rápidas em vez de flexibilidade e função, ele é definido como o padrão. No entanto, alguns projetos do CMake podem não conseguir executar o build corretamente usando o Ninja. Se isso ocorrer, você pode instruir o CMake a gerar um projeto do Visual Studio.

### <a name="intellisense-mode"></a>Modo do IntelliSense

O modo IntelliSense usado pelo motor IntelliSense. Se nenhum modo for selecionado, o Visual Studio herdará do conjunto de ferramentas especificado.  

### <a name="install-directory"></a>Diretório de instalação

O diretório no qual cMake instala alvos. Mapas para [CMAKE_INSTALL_PREFIX.](https://cmake.org/cmake/help/latest/variable/CMAKE_INSTALL_PREFIX.html)

### <a name="cmake-executable"></a>Executável do CMake

O caminho completo para o programa CMake executável, incluindo o nome do arquivo e a extensão. Ele permite que você use uma versão personalizada do CMake com o Visual Studio. Para builds remotos, especifique a localização do CMake no computador remoto.

Para configurações como o Linux que usam builds remotos, as seguintes configurações também estão disponíveis:

### <a name="remote-cmakeliststxt-root"></a>Raiz remota de CMakeLists.txt

O diretório na máquina remota que contém o arquivo *CMakeLists.txt* raiz.

### <a name="remote-install-root"></a>Raiz de instalação remota

O diretório no computador remoto no qual o CMake instala os destinos. Mapas para [CMAKE_INSTALL_PREFIX.](https://cmake.org/cmake/help/latest/variable/CMAKE_INSTALL_PREFIX.html)

### <a name="remote-copy-sources"></a>Origens de cópia remota

Especifica se deseja copiar arquivos de origem para a máquina remota e permite especificar se deve usar rsync ou sftp.

## <a name="directly-edit-cmakesettingsjson"></a>Editar o CMakeSettings.json diretamente

Você também pode editar diretamente *CMakeSettings.json* para criar configurações personalizadas. O **Editor de Configurações** tem um botão **Editar JSON** no canto superior direito que abre o arquivo para edição.

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

O JSON IntelliSense ajuda você a editar o arquivo *CMakeSettings.json:*

   ![CMake JSON IntelliSense](media/cmake-json-intellisense.png "CMake JSON IntelliSense")

O editor jSON também informa quando você escolhe configurações incompatíveis.

Para obter mais informações sobre cada uma das propriedades no arquivo, confira [Referência de esquema de CMakeSettings.json](cmakesettings-reference.md).

::: moniker-end

::: moniker range="<=vs-2017"

O Visual Studio 2017 fornece várias configurações do CMake que definem como o CMake.exe é invocado para criar o cache do CMake para determinado projeto. Para adicionar uma nova configuração, clique na lista suspensa na barra de ferramentas de configuração e escolha **Gerenciar Configurações**:

   ![Gerenciar configurações do CMake](media/cmake-manage-configurations.png)

Você pode escolher na lista de configurações predefinidas:

   ![Configurações predefinidas do CMake](media/cmake-configurations.png)

Na primeira vez que você seleciona uma configuração, o Visual Studio cria um arquivo *CMakeSettings.json* na pasta raiz do projeto. Esse arquivo é usado para recriar o arquivo de cache do CMake, por exemplo, após uma operação de **Limpeza**.

Para adicionar uma configuração adicional, clique com o botão direito do mouse *CMakeSettings.json* e escolha **Adicionar configuração**.

   ![CMake adicionar configuração](media/cmake-add-configuration.png "Configuração cmake add")

Você também pode editar o arquivo usando o **Editor de Configurações do CMake**. Clique com o botão direito do mouse em *CMakeSettings.json* no **Solution Explorer** e escolha **Editar configurações cMake**. Ou selecione **Gerenciar Configurações** na lista suspensa de configurações na parte superior da janela do editor.

Você também pode editar diretamente *CMakeSettings.json* para criar configurações personalizadas. O seguinte exemplo mostra uma configuração de exemplo, que pode ser usada como ponto de partida:

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

O JSON IntelliSense ajuda você a editar o arquivo *CMakeSettings.json:*

   ![CMake JSON IntelliSense](media/cmake-json-intellisense.png "CMake JSON IntelliSense")

Para obter mais informações sobre cada uma das propriedades no arquivo, confira [Referência de esquema de CMakeSettings.json](cmakesettings-reference.md).

::: moniker-end

## <a name="see-also"></a>Confira também

[Projetos do CMake no Visual Studio](cmake-projects-in-visual-studio.md)<br/>
[Configurar um projeto do Linux CMake](../linux/cmake-linux-project.md)<br/>
[Conectar-se ao computador Linux remoto](../linux/connect-to-your-remote-linux-computer.md)<br/>
[Configurar sessões de depuração do CMake](configure-cmake-debugging-sessions.md)<br/>
[Implantar, executar e depurar o projeto do Linux](../linux/deploy-run-and-debug-your-linux-project.md)<br/>
[Referência de configuração predefinida do CMake](cmake-predefined-configuration-reference.md)
