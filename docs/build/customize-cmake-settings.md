---
title: Personalizar as configurações de build do CMake no Visual Studio
ms.date: 04/25/2019
helpviewer_keywords:
- CMake build settings
ms.openlocfilehash: 20ed066f71a5c8c3acb00ef5923fa5c9f16ac229
ms.sourcegitcommit: 18d3b1e9cdb4fc3a76f7a650c31994bdbd2bde64
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/29/2019
ms.locfileid: "64877144"
---
# <a name="customize-cmake-build-settings"></a>Personalizar as configurações de build do CMake

::: moniker range="vs-2019"

No Visual Studio de 2019 e posterior, você pode adicionar configurações e personalizar suas configurações usando o **editor de configurações do CMake**. O editor deve ser uma alternativa mais simples para editar manualmente o arquivo de Cmakesettings, mas se você preferir editar o arquivo diretamente, você pode clicar na **Editar JSON** link no canto superior direito do editor. 

Para abrir o editor, clique no **Configuration** lista suspensa na barra de ferramentas principal e escolha **gerenciar configurações**.

![Lista suspensa de configurações de CMake](media/vs2019-cmake-manage-configurations.png)

Agora você vê o **Editor de configurações** com as configurações instaladas à esquerda. 

![Editor de configurações do CMake](media/cmake-settings-editor.png)

O Visual Studio fornece duas configurações por padrão: `x64-Debug` e `x86-Debug`. Você pode adicionar configurações adicionais clicando no sinal de adição verde. As configurações que você vê no editor podem variar dependendo de qual configuração é selecionada.

As opções que você escolher no editor são gravadas em um arquivo chamado Cmakesettings. Esse arquivo fornece argumentos de linha de comando e variáveis de ambiente que são passadas para o CMake quando você compila projetos. O Visual Studio nunca modifica cmakelists. txt automaticamente. usando Cmakesettings, você pode personalizar a compilação por meio do Visual Studio enquanto deixa os arquivos de projeto do CMake inalterados para que outras pessoas em sua equipe podem consumi-los com quaisquer ferramentas que eles estão usando.

## <a name="cmake-general-settings"></a>Configurações gerais do CMake

As configurações a seguir estão disponíveis sob o **geral** título:

### <a name="configuration-name"></a>Nome da configuração

Corresponde do **nome** configuração. Esse é o nome que aparece no C++ lista suspensa de configuração. Você pode usar o `${name}` macro para compor a outros valores de propriedade, como caminhos.


### <a name="configuration-type"></a>Tipo de configuração

Corresponde do **configurationType** configuração. Define o tipo de configuração de compilação para o gerador selecionado. Os valores compatíveis no momento são "Debug", "MinSizeRel", "Release" e "RelWithDebInfo".

### <a name="toolset"></a>Conjunto de Ferramentas

Corresponde do **inheritedEnvironments** configuração. Define o ambiente de compilador que será usado para compilar a configuração selecionada. Valores com suporte dependem do tipo de configuração. Para criar um ambiente personalizado, clique o **Editar JSON** link no canto superior direito do editor de configurações e editar o arquivo Cmakesettings JSON diretamente.

### <a name="cmake-toolchain-file"></a>Arquivo de cadeia de ferramentas do CMake

Caminho para o arquivo de cadeia de ferramentas do CMake. Serão passados para o CMake como "-DCMAKE_TOOLCHAIN_FILE = \<filepath >".

### <a name="build-root"></a>Raiz de build

Corresponde ao **buildRoot**. Mapeia para **-DCMAKE_BINARY_DIR** alternar e especifica onde o cache de CMake será criado. Se a pasta não existir, ela será criada.

## <a name="command-arguments"></a>Argumentos de comando

As configurações a seguir estão disponíveis sob o **argumentos de comando** título:

### <a name="cmake-command-arguments"></a>Argumentos de comando do CMake

Corresponde ao **cmakeCommandArgs**. Especifica quaisquer opções adicionais que você deseja passar para CMake.exe.

### <a name="build-command-arguments"></a>Argumentos de comando de compilação

Corresponde ao **buildCommandArgs**: Especifica o sistema de compilação de opções adicionais para passar para subjacente. Por exemplo, passar -v ao usar o gerador Ninja força o Ninja a emitir linhas de comando de saída.


### <a name="ctest-command-arguments"></a>Argumentos de comando de CTest

Corresponde ao**ctestCommandArgs**: especifica as opções adicionais para passar para CTest ao executar testes.

## <a name="general-settings-for-remote-builds"></a>Configurações gerais para builds remotos

Para configurações como o Linux que utilizam builds remotos, as configurações a seguir também estão disponíveis:

### <a name="rsync-command-arguments"></a>argumentos de comando rsync

Forneça quaisquer argumentos de comando para ser passadas para rsync. 

## <a name="cmake-variables-and-cache"></a>Cache e variáveis do CMake

Essas configurações permitem que você defina as variáveis do CMake e salvá-los no Cmakesettings. Eles serão passados para o CMake no momento da compilação e substituirão quaisquer valores podem estar no arquivo cmakelists. txt. Você pode usar esta seção da mesma forma que você pode usar o CMakeGUI para exibir uma lista de todas as variáveis do CMake disponíveis para edição. Clique o **salvar e gerar cache** botão para exibir uma lista de todas as variáveis do CMake disponíveis para edição, incluindo variáveis avançadas (por CMakeGUI). Você pode filtrar a lista por nome de variáveis. 

Corresponde ao **variáveis**: contém um par nome-valor das variáveis do CMake que será passada como **-D** *_nome_ =  _valor_* para CMake. Se as instruções de build do projeto do CMake especificam a adição de variáveis diretamente ao arquivo de cache do CMake, é recomendável que você adicione-as aqui.

## <a name="advanced-settings"></a>Configurações avançadas

### <a name="cmake-generator"></a>Gerador de CMake

Corresponde ao **gerador**: é mapeado para o CMake **- G** alternar e especifica o gerador para ser usado. Essa propriedade também pode ser usada como uma macro, `${generator}`, ao compor outros valores de propriedade. No momento, o Visual Studio dá suporte aos seguintes geradores do CMake:

  - "Ninja"
  - "Unix Makefiles"
  - "Visual Studio 2019 16"
  - "Win64 do visual Studio 2019 16"
  - - "ARM de 16 2019 do visual Studio"
  - "Visual Studio 15 2017"
  - "Visual Studio 15 2017 Win64"
  - "Visual Studio 15 2017 ARM"
  - "Visual Studio 14 2015"
  - "Visual Studio 14 2015 Win64"
  - "Visual Studio 14 2015 ARM"
  
  Como o Ninja é criado para velocidades rápidas de builds em vez de flexibilidade e função, ele está definido como padrão. No entanto, alguns projetos do CMake podem não conseguir executar o build corretamente usando o Ninja. Se isso ocorrer, instrua o CMake a gerar um projeto do Visual Studio em vez disso.

### <a name="intellisense-mode"></a>Modo do IntelliSense

Para o IntelliSense precisos, defina como o valor apropriado para seu projeto.

### <a name="install-directory"></a>Diretório de instalação

O diretório no qual o CMake instala os destinos que ele se baseia.

### <a name="cmake-executable"></a>Executável de CMake

O caminho completo para o executável de CMake, incluindo a extensão e o nome do arquivo. Para compilações remotas, especifique o local do CMake no computador remoto.

Para configurações como o Linux que utilizam builds remotos, as configurações a seguir também estão disponíveis:

### <a name="remote-cmakeliststxt-root"></a>Raiz remota de cmakelists. txt

O diretório no computador remoto que contém o arquivo cmakelists. txt de raiz.

### <a name="remote-install-root"></a>Raiz de instalação remota

O diretório no computador remoto no qual o CMake instala destinos.

### <a name="remote-copy-sources"></a>Fontes de cópia remota

Especifica se deve copiar arquivos de origem para o computador remoto e permite que você especifique se deseja Use rsync ou sftp. 

## <a name="directly-edit-cmakesettingsjson"></a>Editar diretamente o Cmakesettings

Você também pode editar diretamente `CMakeSettings.json` para criar configurações personalizadas. O **Editor de configurações** tem um **Editar JSON** botão no canto superior direito que abre o arquivo para edição. 

O exemplo a seguir mostra um exemplo de configuração, que pode ser usado como um ponto de partida:

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

JSON IntelliSense ajuda a editar o `CMakeSettings.json` arquivo:

   ![CMake JSON IntelliSense](media/cmake-json-intellisense.png "CMake JSON IntelliSense")

O editor de JSON também informam quando você escolhe configurações incompatíveis.

Para obter mais informações sobre cada uma das propriedades no arquivo, consulte [referência de esquema de Cmakesettings](cmakesettings-reference.md).

::: moniker-end

::: moniker range="<=vs-2017"

Visual Studio 2017 fornece várias configurações de CMake que definem como CMake.exe é invocada para criar o cache de CMake para um determinado projeto. Para adicionar uma nova configuração, clique na lista suspensa na barra de ferramentas de configuração e escolha **Gerenciar Configurações**:

   ![Gerenciar configurações do CMake](media/cmake-manage-configurations.png)

Você pode escolher na lista de configurações predefinidas:

   ![Configurações predefinidas do CMake](media/cmake-configurations.png)

Na primeira vez que você seleciona uma configuração, o Visual Studio cria um arquivo `CMakeSettings.json` na pasta raiz do seu projeto. Esse arquivo é usado para recriar o arquivo de cache do CMake, por exemplo, após uma operação de **Limpeza**. 

Para adicionar uma configuração extra, clique com o botão direito do mouse em `CMakeSettings.json` e escolha **Adicionar Configuração**. 

   ![Adicionar configuração do CMake](media/cmake-add-configuration.png "Adicionar configuração do CMake")

Você também pode editar o arquivo usando o **Editor de Configurações do CMake**. Clique com o botão direito do mouse em `CMakeSettings.json` no **Gerenciador de Soluções** e escolha **Editar Configurações do CMake**. Ou selecione **Gerenciar Configurações** na lista suspensa de configurações na parte superior da janela do editor. 

Você também pode editar diretamente `CMakeSettings.json` criar configurações personalizadas que o exemplo a seguir mostra um exemplo de configuração, que pode ser usado como um ponto de partida:

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

Para obter mais informações sobre cada uma das propriedades no arquivo, consulte [referência de esquema de Cmakesettings](cmakesettings-reference.md).

::: moniker-end

## <a name="see-also"></a>Consulte também

[Projetos do CMake no Visual Studio](cmake-projects-in-visual-studio.md)<br/>
[Configurar um projeto do Linux CMake](../linux/cmake-linux-project.md)<br/>
[Conectar-se ao computador Linux remoto](../linux/connect-to-your-remote-linux-computer.md)<br/>
[Configurar sessões de depuração do CMake](configure-cmake-debugging-sessions.md)<br/>
[Implantar, executar e depurar o projeto do Linux](../linux/deploy-run-and-debug-your-linux-project.md)<br/>
[Referência de configuração predefinida do CMake](cmake-predefined-configuration-reference.md)<br/>
