---
title: Personalizar as configurações de build do CMake no Visual Studio
ms.date: 03/05/2019
helpviewer_keywords:
- CMake build settings
ms.openlocfilehash: 1bdf4ef3e20b055b6fa3d5449a880ddb7aab44a0
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59037517"
---
# <a name="customize-cmake-build-settings"></a>Personalizar as configurações de build do CMake

O Visual Studio fornece várias configurações do CMake que definem como o CMake.exe é invocado para criar o cache do CMake para um dado projeto. Para adicionar uma nova configuração, clique na lista suspensa na barra de ferramentas de configuração e escolha **Gerenciar Configurações**:

   ![Gerenciar configurações do CMake](media/cmake-manage-configurations.png)

Você pode escolher na lista de configurações predefinidas:

   ![Configurações predefinidas do CMake](media/cmake-configurations.png)

Na primeira vez que você seleciona uma configuração, o Visual Studio cria um arquivo `CMakeSettings.json` na pasta raiz do seu projeto. Esse arquivo é usado para recriar o arquivo de cache do CMake, por exemplo, após uma operação de **Limpeza**. 

Para adicionar uma configuração extra, clique com o botão direito do mouse em `CMakeSettings.json` e escolha **Adicionar Configuração**. 

   ![Adicionar configuração do CMake](media/cmake-add-configuration.png "Adicionar configuração do CMake")

O JSON IntelliSense ajuda a editar o arquivo `CMakeSettings.json`:

   ![CMake JSON IntelliSense](media/cmake-json-intellisense.png "CMake JSON IntelliSense")

Você também pode editar o arquivo usando o **Editor de Configurações do CMake**. Clique com o botão direito do mouse em `CMakeSettings.json` no **Gerenciador de Soluções** e escolha **Editar Configurações do CMake**. Ou selecione **Gerenciar Configurações** na lista suspensa de configurações na parte superior da janela do editor. 

Você também pode editar diretamente `CMakeSettings.json` para criar configurações personalizadas O exemplo a seguir apresenta uma amostra de configuração, que pode ser usada como ponto de partida:

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

- **name**: o nome exibido na lista suspensa de configuração do C++. A macro `${name}` permite que você use esse valor ao compor outros valores de propriedade, como caminhos. Por exemplo, confira a definição de **buildRoot** em `CMakeSettings.json`.

- **generator**: mapeia para opção **-G** do CMake e especifica o gerador a ser usado. Essa propriedade também pode ser usada como uma macro, `${generator}`, ao compor outros valores de propriedade. No momento, o Visual Studio dá suporte aos seguintes geradores do CMake:

  - "Ninja"
  - "Visual Studio 14 2015"
  - "Visual Studio 14 2015 ARM"
  - "Visual Studio 14 2015 Win64"
  - "Visual Studio 15 2017"
  - "Visual Studio 15 2017 ARM"
  - "Visual Studio 15 2017 Win64"

  Como o Ninja é criado para velocidades rápidas de builds em vez de flexibilidade e função, ele está definido como padrão. No entanto, alguns projetos do CMake podem não conseguir executar o build corretamente usando o Ninja. Se isso ocorrer, instrua o CMake a gerar um projeto do Visual Studio em vez disso.

  Para especificar um gerador do Visual Studio, abra o `CMakeSettings.json` no menu principal escolhendo **CMake | Alterar Configurações do CMake**. Exclua "Ninja" e digite "V". Isso ativa o IntelliSense, que permite escolher o gerador desejado.

  Quando a configuração ativa especifica um gerador do Visual Studio, por padrão, MSBuild.exe é invocado com argumentos `-m -v:minimal`. Para personalizar o build, dentro do arquivo `CMakeSettings.json`, especifique [argumentos de linha de comando do MSBuild](../build/reference/msbuild-visual-cpp-overview.md) adicionais a serem passados para o sistema de build por meio da propriedade `buildCommandArgs`:
    
    ```json
    "buildCommandArgs": "-m:8 -v:minimal -p:PreferredToolArchitecture=x64"
    ```

- **buildRoot**: é mapeado para a opção **-DCMAKE_BINARY_DIR** e especifica o local em que o cache do CMake será criado. Se a pasta não existir, ela será criada.

- **variables**: contém um par nome-valor das variáveis do CMake que serão passadas como **-D** *_name_=_value_* para o CMake. Se as instruções de build do projeto do CMake especificam a adição de variáveis diretamente ao arquivo de cache do CMake, é recomendável que você adicione-as aqui. O exemplo a seguir mostra como especificar os pares nome-valor para o conjunto de ferramentas 14.14.26428:

```json
"variables": [
    {
      "name": "CMAKE_CXX_COMPILER",
      "value": "C:/Program Files (x86)/Microsoft Visual Studio/157/Enterprise/VC/Tools/MSVC/14.14.26428/bin/HostX86/x86/cl.exe"
    },
    {
      "name": "CMAKE_C_COMPILER",
      "value": "C:/Program Files (x86)/Microsoft Visual Studio/157/Enterprise/VC/Tools/MSVC/14.14.26428/bin/HostX86/x86/cl.exe"
    }
  ]
```

- **cmakeCommandArgs**: especifica as opções adicionais que você deseja passar para CMake.exe.

- **configurationType**: define o tipo de configuração de build para o gerador selecionado. Os valores compatíveis no momento são "Debug", "MinSizeRel", "Release" e "RelWithDebInfo".

- **ctestCommandArgs**: especifica as opções adicionais a serem passadas para CTest ao executar testes.

- **buildCommandArgs**: especifica as opções adicionais a serem passadas para o sistema de build subjacente. Por exemplo, passar -v ao usar o gerador Ninja força o Ninja a emitir linhas de comando de saída.

Configurações adicionais estão disponíveis para projetos do CMake Linux. Veja [Configurar um projeto do CMake Linux](../linux/cmake-linux-project.md).

## <a name="environment-variables"></a>Variáveis de ambiente

 `CMakeSettings.json` também dá suporte ao consumo de variáveis de ambiente em uma das propriedades mencionadas acima. A sintaxe a ser usada é `${env.FOO}` para expandir a variável de ambiente %FOO%.
Você também tem acesso às macros internas dentro deste arquivo:

- `${workspaceRoot}` – fornece o caminho completo da pasta de workspace
- `${workspaceHash}` – hash do local do workspace; útil para criação de um identificador exclusivo para o workspace atual (por exemplo, para uso em caminhos de pasta)
- `${projectFile}` – o caminho completo do arquivo CMakeLists.txt raiz
- `${projectDir}` – o caminho completo da pasta do arquivo CMakeLists.txt raiz
- `${thisFile}` – o caminho completo do arquivo `CMakeSettings.json`
- `${name}` – o nome da configuração
- `${generator}` – o nome do gerador do CMake usado nessa configuração

## <a name="ninja-command-line-arguments"></a>Argumentos da linha de comando do Ninja

Se os destinos não estão especificados, compila o destino 'padrão' (consulte o manual).

```cmd
C:\Program Files (x86)\Microsoft Visual Studio\Preview\Enterprise>ninja -?
ninja: invalid option -- `-?'
usage: ninja [options] [targets...]
```

|Opção|Descrição|
|--------------|------------|
| --version  | imprime a versão do Ninja ("1.7.1")|
|   -C DIR   | altera para DIR antes de qualquer outra ação|
|   -f FILE  | especifica o arquivo de entrada de build (padrão= build.ninja)|
|   -j N     | executa N trabalhos em paralelo (padrão= 14, derivado das CPUs disponíveis)|
|   -k N     | continua até N trabalhos falharem (padrão= 1)|
|   -l N     | não inicia novos trabalhos se a média de carga é maior que N|
|   -n       | simulação (não executa comandos, mas se comporta como se eles tiveram êxito)|
|   -v       | mostra todas as linhas de comando durante o build|
|   -d MODE  | habilita a depuração (usa a lista -d para listar os modos)|
|   -t TOOL  | executa uma subferramenta (usa a lista -t para listar as subferramentas). encerra as opções de nível superior; ainda mais os sinalizadores são passados para a ferramenta|
|   -w FLAG  | ajusta os avisos (usa a lista -w para listar os avisos)|

## <a name="inherited-environments"></a>Ambientes herdados

 `CMakeSettings.json` dá suporte a ambientes herdados. Esse recurso permite que você (1) herde os ambientes padrão e (2) crie variáveis de ambiente personalizadas que são passadas para CMake.exe quando ele é executado.

```json
  "inheritEnvironments": [ "msvc_x64_x64" ]
```

O exemplo acima é o mesmo que executar o **Prompt de Comando do Desenvolvedor para VS 2017** com os argumentos **-arch=amd64 -host_arch=amd64**.

A tabela a seguir mostra os valores padrão:

|Nome do contexto|Descrição|
|-----------|-----------------|
|vsdev|O ambiente padrão do Visual Studio|
|msvc_x86|Compilar para x86 usando ferramentas x86|
|msvc_arm| Compilar para ARM usando ferramentas x86|
|msvc_arm64|Compilar para ARM64 usando ferramentas x86|
|msvc_x86_x64|Compilar para AMD64 usando ferramentas x86|
|msvc_x64_x64|Compilar para AMD64 usando ferramentas de 64 bits|
|msvc_arm_x64|Compilar para ARM usando ferramentas de 64 bits|
|msvc_arm64_x64|Compilar para ARM64 usando ferramentas de 64 bits|

### <a name="custom-environment-variables"></a>Variáveis de ambiente personalizadas

Em `CMakeSettings.json`, defina as variáveis de ambiente personalizadas globalmente ou por configuração na propriedade **environments**. O exemplo a seguir define uma variável global, **BuildDir**, que é herdada nas configurações x86-Debug e x64-Debug. Cada configuração usa a variável para especificar o valor para a propriedade **buildRoot** dessa configuração. Também observe como cada configuração usa a propriedade **inheritEnvironments** para especificar uma variável que só se aplica a essa configuração.

```json
{
  // The "environments" property is an array of key value pairs of the form
  // { "EnvVar1": "Value1", "EnvVar2": "Value2" }
  "environments": [
    {
      "BuildDir": "${env.USERPROFILE}\\CMakeBuilds\\${workspaceHash}\\build",
    }
  ],

  "configurations": [
    {
      "name": "x86-Debug",
      "generator": "Ninja",
      "configurationType": "Debug",
      // Inherit the defaults for using the MSVC x86 compiler.
      "inheritEnvironments": [ "msvc_x86" ],
      "buildRoot": "${env.BuildDir}\\${name}"    },
    {
      "name": "x64-Debug",
      "generator": "Ninja",
      "configurationType": "Debug",
      // Inherit the defaults for using the MSVC x64 compiler.
      "inheritEnvironments": [ "msvc_x64" ],
      "buildRoot": "${env.BuildDir}\\${name}"
    }
  ]
}
```

No exemplo a seguir, a configuração de Depuração x86 define seu próprio valor para a propriedade **BuildDir**. Esse valor substitui o valor definido pela propriedade **BuildDir** global de modo que **BuildRoot** seja avaliada como `D:\custom-builddir\x86-Debug`.

```json
{
  "environments": [
    {
      "BuildDir": "${env.USERPROFILE}\\CMakeBuilds\\${workspaceHash}",
    }
  ],

  "configurations": [
    {
      "name": "x86-Debug",

      // The syntax for this property is the same as the global one above.
      "environments": [
        {
          // Replace the global property entirely.
          "BuildDir": "D:\\custom-builddir",
        }
      ],

      "generator": "Ninja",
      "configurationType": "Debug",
      "inheritEnvironments": [ "msvc_x86" ],
      // Evaluates to "D:\custom-builddir\x86-Debug"
      "buildRoot": "${env.BuildDir}\\${name}"
    },
    {
      "name": "x64-Debug",

      "generator": "Ninja",
      "configurationType": "Debug",
      "inheritEnvironments": [ "msvc_x64" ],
      // Since this configuration doesn’t modify BuildDir, it inherits
      // from the one defined globally.
      "buildRoot": "${env.BuildDir}\\${name}"
    }
  ]
}
```

## <a name="see-also"></a>Consulte também

[Projetos do CMake no Visual Studio](cmake-projects-in-visual-studio.md)<br/>
[Configurar um projeto do Linux CMake](../linux/cmake-linux-project.md)<br/>
[Conectar-se ao computador Linux remoto](../linux/connect-to-your-remote-linux-computer.md)<br/>
[Configurar sessões de depuração do CMake](configure-cmake-debugging-sessions.md)<br/>
[Implantar, executar e depurar o projeto do Linux](../linux/deploy-run-and-debug-your-linux-project.md)<br/>
[Referência de configuração predefinida do CMake](cmake-predefined-configuration-reference.md)<br/>
