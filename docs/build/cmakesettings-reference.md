---
title: Referência de esquema de CMakeSettings.json
ms.date: 04/25/2019
helpviewer_keywords:
- CMake in Visual C++
ms.assetid: 444d50df-215e-4d31-933a-b41841f186f8
ms.openlocfilehash: 80392eedd5ef50ddd9c9bcb81c1605a534088133
ms.sourcegitcommit: 18d3b1e9cdb4fc3a76f7a650c31994bdbd2bde64
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/29/2019
ms.locfileid: "64877100"
---
# <a name="cmakesettingsjson-schema-reference"></a>Referência de esquema de CMakeSettings.json

O **cmakesettings**' arquivo contém informações que especificam como o Visual Studio deve interagir com CMake para compilar um projeto de uma plataforma específica. O arquivo armazena informações como argumentos para o ambiente cmake.exe ou variáveis de ambiente. Você pode editar diretamente ou usar o **editor de configurações de CMake**. Ver [CMake personalizar compilar configurações no Visual Studio](customize-cmake-settings.md) para obter mais informações sobre o editor.

## <a name="environments"></a>Ambientes

O `environments` matriz contém uma lista de `items` do tipo `object` que definem um conjunto de ferramentas do compilador "ambiente". Um ambiente pode ser usado para aplicar um conjunto de variáveis a uma `configuration`. Cada item na matriz `environments` consiste em:

- `namespace`: dá um nome ao ambiente de modo que suas variáveis possam ser referenciadas de uma configuração na forma `namespace.variable`. O objeto de ambiente padrão é chamado `env` e é preenchido com determinadas variáveis de ambiente do sistema, incluindo `%USERPROFILE%`.
- `environment`: identifica exclusivamente este grupo de variáveis. Permite que o grupo seja herdado posteriormente em uma entrada `inheritEnvironments`.
- `groupPriority`: Um inteiro que especifica a prioridade dessas variáveis ao avaliá-las. Itens de maior número são avaliados primeiro.
- `inheritEnvironments`: Uma matriz de valores que especificam o conjunto de ambientes herdados por esse grupo. Esse recurso permite que você herdar ambientes padrão e criar variáveis de ambiente personalizadas que são passadas para CMake.exe quando ele é executado.

   ```json
   "inheritEnvironments": [ "msvc_x64_x64" ]
   ```

   O exemplo acima é o mesmo que executar o **Prompt de Comando do Desenvolvedor para VS 2017** com os argumentos **-arch=amd64 -host_arch=amd64**. Qualquer ambiente personalizado pode ser usado ou use estes ambientes predefinidos:
 
  - linux_arm: direcione ao ARM Linux remotamente.
  - linux_x64: direcione ao Linux x64 remotamente.
  - linux_x86: direcione ao Linux x86 remotamente.
  - msvc_arm: direcione o Windows ARM com o compilador MSVC.
  - msvc_arm_x64: direcione o Windows ARM com o compilador MSVC de 64 bits.
  - msvc_arm64: direcione o Windows ARM64 com o compilador MSVC.
  - msvc_arm64_x64: direcione o Windows ARM64 com o compilador MSVC de 64 bits.
  - msvc_x64: direcione o Windows x64 com o compilador MSVC.
  - msvc_x64_x64: direcione o Windows x64 com o compilador MSVC de 64 bits.
  - msvc_x86: direcione o Windows x86 com o compilador MSVC.
  - msvc_x86_x64: direcione o Windows x86 com o compilador MSVC de 64 bits.

## <a name="configurations"></a>Configurações

A matriz `configurations` consiste em objetos que representam as configurações do CMake que se aplicam ao arquivo CMakeLists.txt na mesma pasta. Você pode usar esses objetos para definir várias configurações de build e alternar convenientemente entre elas no IDE. 

Um `configuration` tem estas propriedades:
- `name`: dá um nome à configuração.
- `description`: a descrição dessa configuração que será exibida nos menus.
- `generator`: especifica o gerador do CMake a ser usado para essa configuração. Pode ser um destes:

  - Visual Studio 15 2017
  - Visual Studio 15 2017 Win64
  - Visual Studio 15 2017 ARM
  - Visual Studio 14 2015
  - Visual Studio 14 2015 Win64
  - Visual Studio 14 2015 ARM
  - Unix Makefiles
  - Ninja

Como o Ninja é criado para velocidades rápidas de builds em vez de flexibilidade e função, ele está definido como padrão. No entanto, alguns projetos do CMake podem não conseguir executar o build corretamente usando o Ninja. Se isso ocorrer, instrua o CMake a gerar um projeto do Visual Studio em vez disso.

Para especificar um gerador do Visual Studio, abra o `CMakeSettings.json` no menu principal escolhendo **CMake | Alterar Configurações do CMake**. Exclua "Ninja" e digite "V". Isso ativa o IntelliSense, que permite escolher o gerador desejado.

Quando a configuração ativa especifica um gerador do Visual Studio, por padrão, MSBuild.exe é invocado com argumentos `-m -v:minimal`. Para personalizar o build, dentro do arquivo `CMakeSettings.json`, especifique [argumentos de linha de comando do MSBuild](../build/reference/msbuild-visual-cpp-overview.md) adicionais a serem passados para o sistema de build por meio da propriedade `buildCommandArgs`:

   ```json
   "buildCommandArgs": "-m:8 -v:minimal -p:PreferredToolArchitecture=x64"
   ```

- `configurationType`: especifica a configuração do tipo de build para o gerador selecionado. Pode ser um destes:
 
  - Depurar
  - Versão
  - MinSizeRel
  - RelWithDebInfo
 
- `inheritEnvironments`: especifica um ou mais ambientes de compilador que essa configuração depende. Pode ser qualquer ambiente personalizado ou um dos ambientes predefinidos.
- `buildRoot`: Especifica o diretório no qual o CMake gera scripts de build para o gerador escolhido.  Mapeia para **-DCMAKE_BINARY_DIR** alternar e especifica onde o cache de CMake será criado. Se a pasta não existir, ele é criado. Macros com suporte incluem `${workspaceRoot}`, `${workspaceHash}`, `${projectFile}`, `${projectDir}`, `${thisFile}`, `${thisFileDir}`, `${name}`, `${generator}`, `${env.VARIABLE}`.
- `installRoot`: especifica o diretório no qual o CMake gera destinos de instalação para o gerador escolhido. Macros com suporte incluem `${workspaceRoot}`, `${workspaceHash}`, `${projectFile}`, `${projectDir}`, `${thisFile}`, `${thisFileDir}`, `${name}`, `${generator}`, `${env.VARIABLE}`.
- `cmakeCommandArgs`: especifica as opções de linha de comando adicionais passaram para o CMake quando invocado para gerar o cache.
- `cmakeToolchain`: especifica o arquivo de cadeia de ferramentas. Isso é passado para o CMake usando -DCMAKE_TOOLCHAIN_FILE."
- `buildCommandArgs`: especifica as opções de build nativas passaram para CMake depois - compilação –. Por exemplo, passar -v ao usar o gerador Ninja força o Ninja a emitir linhas de comando de saída. Ver [argumentos de linha de comando do Ninja](#ninja) para obter mais informações sobre os comandos de Ninja.
- `ctestCommandArgs`: especifica opções de linha de comando adicionais passadas para CTest ao executar os testes."
- `codeAnalysisRuleset`: especifica o conjunto de regras para usar ao executar a análise de código. Isso pode ser um caminho completo ou o nome do arquivo de um arquivo de conjunto de regras instalado pelo Visual Studio.
- `intelliSenseMode`: especifica o modo usado para computar informações do IntelliSense". Pode ser um destes:
 
  - windows-msvc-x86
  - windows-msvc-x64
  - windows-msvc-arm
  - windows-msvc-arm64
  - android-clang-x86
  - android-clang-x64
  - android-clang-arm
  - android-clang-arm64
  - ios-clang-x86
  - ios-clang-x64
  - ios-clang-arm
  - ios-clang-arm64
  - windows-clang-x86
  - windows-clang-x64
  - windows-clang-arm
  - windows-clang-arm64
  - linux-gcc-x86
  - linux-gcc-x64
  - linux-gcc-arm"

- `cacheRoot`: especifica o caminho para um cache do CMake. Esse diretório deve conter um arquivo CMakeCache.txt existente.

### <a name="additional-settings-for-cmake-linux-projects"></a>Configurações adicionais para projetos do CMake Linux. 

- `remoteMachineName`: especifica o nome do computador Linux remoto que hospeda o CMake, builds e o depurador. Use o Gerenciador de Conexões para a adição de novos computadores Linux. Macros com suporte incluem `${defaultRemoteMachineName}`.
- `remoteCopySourcesOutputVerbosity`: especifica o nível de detalhes da fonte que copia a operação no computador remoto. Pode ser um entre "Normal", "Detalhado" ou "Diagnóstico".
- `remoteCopySourcesConcurrentCopies`: especifica o número de cópias simultâneas usadas durante a sincronização das fontes com o computador remoto.
- `remoteCopySourcesMethod`: especifica o método para copiar os arquivos para o computador remoto. Pode ser "rsync" ou "sftp".
- `remoteCMakeListsRoot`: especifica o diretório no computador remoto que contém o projeto do CMake. Macros com suporte incluem `${workspaceRoot}`, `${workspaceHash}`, `${projectFile}`, `${projectDir}`, `${thisFile}`, `${thisFileDir}`, `${name}`, `${generator}`, `${env.VARIABLE}`.
- `remoteBuildRoot`: especifica o diretório no computador remoto no qual o CMake gera scripts de build para o gerador escolhido. Macros com suporte incluem `${workspaceRoot}`, `${workspaceHash}`, `${projectFile}`, `${projectDir}`, `${thisFile}`, `${thisFileDir}`, `${name}`, `${generator}`, `${env.VARIABLE}`.
- `remoteInstallRoot`: especifica o diretório no computador remoto no qual o CMake gera destinos de instalação para o gerador escolhido. Macros com suporte incluem `${workspaceRoot}`, `${workspaceHash}`, `${projectFile}`, `${projectDir}`, `${thisFile}`, `${thisFileDir}`, `${name}`, `${generator}` e `${env.VARIABLE}`, em que `VARIABLE` é uma variável de ambiente definida no nível do sistema, do usuário ou da sessão.
- `remoteCopySources`: Um `boolean` que especifica se o Visual Studio deve copiar arquivos de origem para o computador remoto. O padrão é true. Defina como false se você mesmo gerenciar a sincronização de arquivos.
- `remoteCopyBuildOutput`: Um `boolean` que especifica se é preciso copiar as saídas de build do sistema remoto.
- `rsyncCommandArgs`: especifica um conjunto de opções adicionais de linha de comando passadas para rsync.
- `remoteCopySourcesExclusionList`: Um `array` que especifica uma lista de caminhos a serem excluídos ao copiar arquivos de origem: um caminho pode ter o nome de um arquivo/diretório ou um caminho relativo à raiz da cópia. Curingas \\\"*\\\" e \\\"?\\\" podem ser usados para correspondência de padrões glob.
- `cmakeExecutable`: especifica o caminho completo para o executável do programa do CMake, incluindo o nome e a extensão do arquivo.
- `remotePreGenerateCommand`: especifica o comando a ser executado antes da execução do CMake para analisar o arquivo CMakeLists.txt.
- `remotePrebuildCommand`: especifica o comando a ser executado no computador remoto antes da compilação.
- `remotePostbuildCommand`: especifica o comando a ser executado no computador remoto após a compilação.
- `variables`: contém um par de nome-valor de serão passados como variáveis do CMake **-D** *_nome_=_valor_* para CMake. Se as instruções de build do projeto do CMake especificam a adição de variáveis diretamente ao arquivo de cache do CMake, é recomendável que você adicione-as aqui. O exemplo a seguir mostra como especificar os pares nome-valor para o conjunto de ferramentas 14.14.26428:

```json
"variables": [
    {
      "name": "CMAKE_CXX_COMPILER",
      "value": "C:/Program Files (x86)/Microsoft Visual Studio/157/Enterprise/VC/Tools/MSVC/14.14.26428/bin/HostX86/x86/cl.exe",
      "type": "FILEPATH"
    },
    {
      "name": "CMAKE_C_COMPILER",
      "value": "C:/Program Files (x86)/Microsoft Visual Studio/157/Enterprise/VC/Tools/MSVC/14.14.26428/bin/HostX86/x86/cl.exe",
      "type": "FILEPATH"
    }
  ]
```

Observe que, se você não definir o `"type"`, o tipo "STRING" será considerado por padrão.

## <a name="environment-variables"></a>Variáveis de ambiente

`CMakeSettings.json` também dá suporte a variáveis de ambiente de consumo em qualquer uma de suas propriedades mencionadas acima. A sintaxe a ser usada é `${env.FOO}` para expandir a variável de ambiente %FOO%.

Você também tem acesso às macros internas dentro deste arquivo:

- `${workspaceRoot}` – fornece o caminho completo da pasta de workspace
- `${workspaceHash}` – hash do local do workspace; útil para criação de um identificador exclusivo para o workspace atual (por exemplo, para uso em caminhos de pasta)
- `${projectFile}` – o caminho completo do arquivo CMakeLists.txt raiz
- `${projectDir}` – o caminho completo da pasta do arquivo CMakeLists.txt raiz
- `${thisFile}` – o caminho completo do arquivo `CMakeSettings.json`
- `${name}` – o nome da configuração
- `${generator}` – o nome do gerador do CMake usado nessa configuração


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
          "BuildDir": "D:\\custom-builddir"
          // This environment does not specify a namespace, hence by default "env" will be assumed.
          // "namespace" : "name" would require that this variable be referenced with "${name.BuildDir}".
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

## <a name="ninja"></a> Argumentos de linha de comando do Ninja

Se os destinos estiverem especificados, cria o destino de 'default'.

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




