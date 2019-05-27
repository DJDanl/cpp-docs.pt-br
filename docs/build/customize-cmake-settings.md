---
title: Personalizar as configurações de build do CMake no Visual Studio
ms.date: 05/16/2019
helpviewer_keywords:
- CMake build settings
ms.openlocfilehash: d8102250fa59dc787cc48fc293ac740b81b4446c
ms.sourcegitcommit: a10c9390413978d36b8096b684d5ed4cf1553bc8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2019
ms.locfileid: "65837103"
---
# <a name="customize-cmake-build-settings"></a>Personalizar as configurações de build do CMake

::: moniker range="vs-2019"

No Visual Studio 2019 e posterior, adicione configurações e personalize suas definições usando o **Editor de Configurações do CMake**. O editor pretende ser uma alternativa mais simples para edição manual do arquivo CMakeSettings.json, mas se você preferir editar o arquivo diretamente, clique no link **Editar JSON** no canto superior direito do editor. 

Para abrir o editor, clique na lista suspensa **Configuração** na barra de ferramentas principal e escolha **Gerenciar Configurações**.

![Lista suspensa de configurações do CMake](media/vs2019-cmake-manage-configurations.png)

Agora você vê o **Editor de Configurações** com as configurações instaladas à esquerda. 

![Editor de Configurações do CMake](media/cmake-settings-editor.png)

O Visual Studio fornece duas configurações por padrão: `x64-Debug` e `x86-Debug`. Adicione outras configurações clicando no sinal de adição verde. As configurações exibidas no editor podem variar de acordo com a configuração selecionada.

As opções escolhidas no editor são gravadas em um arquivo chamado CMakeSettings.json. Esse arquivo fornece argumentos de linha de comando e variáveis de ambiente que são passadas para o CMake quando você compila os projetos. O Visual Studio nunca modifica CMakeLists.txt automaticamente; usando o CMakeSettings.json, você pode personalizar o build por meio do Visual Studio, deixando os arquivos de projeto do CMake inalterados para que outras pessoas em sua equipe possam consumi-los com as ferramentas que estiverem usando.

## <a name="cmake-general-settings"></a>Configurações Gerais do CMake

As seguintes configurações estão disponíveis sob o título **Geral**:

### <a name="configuration-name"></a>Nome da configuração

Corresponde à configuração **name**. O nome exibido na lista suspensa de configuração do C++. Use a macro `${name}` para compor outros valores de propriedade, como caminhos.


### <a name="configuration-type"></a>Tipo de configuração

Corresponde à configuração **configurationType**. Define o tipo de configuração de build para o gerador selecionado. Os valores compatíveis no momento são "Debug", "MinSizeRel", "Release" e "RelWithDebInfo".

### <a name="toolset"></a>Conjunto de Ferramentas

Corresponde à configuração **inheritedEnvironments**. Define o ambiente do compilador que será usado para compilar a configuração selecionada. Os valores compatíveis dependem do tipo de configuração. Para criar um ambiente personalizado, clique no link **Editar JSON** no canto superior direito do Editor de Configurações e edite o arquivo CMakeSettings.json diretamente.

### <a name="cmake-toolchain-file"></a>Arquivo de cadeia de ferramentas do CMake

Caminho para o arquivo de cadeia de ferramentas do CMake. Será passado para o CMake como "-DCMAKE_TOOLCHAIN_FILE = \<caminhodoarquivo>".

### <a name="build-root"></a>Raiz de build

Corresponde a **buildRoot**. É mapeado para a opção **-DCMAKE_BINARY_DIR** e especifica a localização em que o cache do CMake será criado. Se a pasta não existir, ela será criada.

## <a name="command-arguments"></a>Argumentos de comando

As seguintes configurações estão disponíveis sob o título **Argumentos de comando**:

### <a name="cmake-command-arguments"></a>Argumentos de comando do CMake

Corresponde a **cmakeCommandArgs**. Especifica as opções adicionais que você deseja passar para CMake.exe.

### <a name="build-command-arguments"></a>Argumentos de comando de build

Corresponde a **buildCommandArgs**: especifica as opções adicionais a serem passadas para o sistema de build subjacente. Por exemplo, passar -v ao usar o gerador Ninja força o Ninja a emitir linhas de comando de saída.


### <a name="ctest-command-arguments"></a>Argumentos de comando do CTest

Corresponde a **ctestCommandArgs**: especifica as opções adicionais a serem passadas para o CTest ao executar testes.

## <a name="general-settings-for-remote-builds"></a>Configurações gerais para builds remotos

Para configurações como o Linux que usam builds remotos, as seguintes configurações também estão disponíveis:

### <a name="rsync-command-arguments"></a>Argumentos de comando do rsync

Forneça os argumentos de comando a serem passados para o rsync. 

## <a name="cmake-variables-and-cache"></a>Variáveis e cache do CMake

Essas configurações permitem definir as variáveis do CMake e salvá-las no CMakeSettings.json. Elas serão passadas para o CMake no momento do build e substituirão todos os valores que possam estar no arquivo CMakeLists.txt. Use esta seção da mesma forma que usaria a CMakeGUI para exibir uma lista de todas as variáveis do CMake disponíveis para edição. Clique no botão **Salvar e gerar cache** para exibir uma lista de todas as variáveis do CMake disponíveis para edição, incluindo variáveis avançadas (de acordo com a CMakeGUI). Filtre a lista por nome de variáveis. 

Corresponde a **variables**: contém um par nome-valor das variáveis do CMake que serão passadas como **-D** *_nome_=_valor_* para o CMake. Se as instruções de build do projeto do CMake especificam a adição de variáveis diretamente ao arquivo de cache do CMake, é recomendável que você adicione-as aqui.

## <a name="advanced-settings"></a>Configurações avançadas

### <a name="cmake-generator"></a>Gerador do CMake

Corresponde a **generator**: é mapeado para a opção **-G** do CMake e especifica o gerador a ser usado. Essa propriedade também pode ser usada como uma macro, `${generator}`, ao compor outros valores de propriedade. No momento, o Visual Studio dá suporte aos seguintes geradores do CMake:

  - "Ninja"
  - "UNIX Makefiles"
  - "Visual Studio 16 2019"
  - "Visual Studio 16 2019 Win64"
  - - "Visual Studio 16 2019 ARM"
  - "Visual Studio 15 2017"
  - "Visual Studio 15 2017 Win64"
  - "Visual Studio 15 2017 ARM"
  - "Visual Studio 14 2015"
  - "Visual Studio 14 2015 Win64"
  - "Visual Studio 14 2015 ARM"
  
  Como o Ninja é criado para velocidades rápidas de builds em vez de flexibilidade e função, ele está definido como padrão. No entanto, alguns projetos do CMake podem não conseguir executar o build corretamente usando o Ninja. Se isso ocorrer, instrua o CMake a gerar um projeto do Visual Studio em vez disso.

### <a name="intellisense-mode"></a>Modo do IntelliSense

Para obter um IntelliSense preciso, defina isso com o valor apropriado para o seu projeto.

### <a name="install-directory"></a>Diretório de instalação

O diretório no qual o CMake instala os destinos compilados.

### <a name="cmake-executable"></a>Executável do CMake

O caminho completo para o executável do CMake, incluindo o nome e a extensão do arquivo. Para builds remotos, especifique a localização do CMake no computador remoto.

Para configurações como o Linux que usam builds remotos, as seguintes configurações também estão disponíveis:

### <a name="remote-cmakeliststxt-root"></a>Raiz remota de CMakeLists.txt

O diretório no computador remoto que contém o arquivo raiz de CMakeLists.txt.

### <a name="remote-install-root"></a>Raiz de instalação remota

O diretório no computador remoto no qual o CMake instala os destinos.

### <a name="remote-copy-sources"></a>Origens de cópia remota

Especifica se os arquivos de origem devem ser copiados para o computador remoto e permite que você especifique se deseja usar o rsync ou o sftp. 

## <a name="directly-edit-cmakesettingsjson"></a>Editar o CMakeSettings.json diretamente

Edite também o `CMakeSettings.json` diretamente para criar configurações personalizadas. O **Editor de Configurações** tem um botão **Editar JSON** no canto superior direito que abre o arquivo para edição. 

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

O JSON IntelliSense ajuda a editar o arquivo `CMakeSettings.json`:

   ![CMake JSON IntelliSense](media/cmake-json-intellisense.png "CMake JSON IntelliSense")

O editor de JSON também informará quando você escolher configurações incompatíveis.

Para obter mais informações sobre cada uma das propriedades no arquivo, confira [Referência de esquema de CMakeSettings.json](cmakesettings-reference.md).

::: moniker-end

::: moniker range="<=vs-2017"

O Visual Studio 2017 fornece várias configurações do CMake que definem como o CMake.exe é invocado para criar o cache do CMake para determinado projeto. Para adicionar uma nova configuração, clique na lista suspensa na barra de ferramentas de configuração e escolha **Gerenciar Configurações**:

   ![Gerenciar configurações do CMake](media/cmake-manage-configurations.png)

Você pode escolher na lista de configurações predefinidas:

   ![Configurações predefinidas do CMake](media/cmake-configurations.png)

Na primeira vez que você seleciona uma configuração, o Visual Studio cria um arquivo `CMakeSettings.json` na pasta raiz do seu projeto. Esse arquivo é usado para recriar o arquivo de cache do CMake, por exemplo, após uma operação de **Limpeza**. 

Para adicionar uma configuração extra, clique com o botão direito do mouse em `CMakeSettings.json` e escolha **Adicionar Configuração**. 

   ![Adicionar configuração do CMake](media/cmake-add-configuration.png "Adicionar configuração do CMake")

Você também pode editar o arquivo usando o **Editor de Configurações do CMake**. Clique com o botão direito do mouse em `CMakeSettings.json` no **Gerenciador de Soluções** e escolha **Editar Configurações do CMake**. Ou selecione **Gerenciar Configurações** na lista suspensa de configurações na parte superior da janela do editor. 

Edite também o `CMakeSettings.json` diretamente para criar configurações personalizadas. O seguinte exemplo mostra uma configuração de exemplo, que pode ser usada como ponto de partida:

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

O JSON IntelliSense ajuda a editar o arquivo `CMakeSettings.json`:

   ![CMake JSON IntelliSense](media/cmake-json-intellisense.png "CMake JSON IntelliSense")

Para obter mais informações sobre cada uma das propriedades no arquivo, confira [Referência de esquema de CMakeSettings.json](cmakesettings-reference.md).

::: moniker-end

## <a name="see-also"></a>Consulte também

[Projetos do CMake no Visual Studio](cmake-projects-in-visual-studio.md)<br/>
[Configurar um projeto do Linux CMake](../linux/cmake-linux-project.md)<br/>
[Conectar-se ao computador Linux remoto](../linux/connect-to-your-remote-linux-computer.md)<br/>
[Configurar sessões de depuração do CMake](configure-cmake-debugging-sessions.md)<br/>
[Implantar, executar e depurar o projeto do Linux](../linux/deploy-run-and-debug-your-linux-project.md)<br/>
[Referência de configuração predefinida do CMake](cmake-predefined-configuration-reference.md)<br/>
