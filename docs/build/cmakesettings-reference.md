---
title: Referência de esquema de CMakeSettings.json
ms.date: 11/22/2019
helpviewer_keywords:
- CMake in Visual C++
ms.assetid: 444d50df-215e-4d31-933a-b41841f186f8
ms.openlocfilehash: 61da0fd70ad68928872a2212b70377ab8a83a76a
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92919391"
---
# <a name="cmakesettingsjson-schema-reference"></a>Referência de esquema de CMakeSettings.json

::: moniker range="msvc-140"

Os projetos CMake têm suporte no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range=">=msvc-150"

O **CMakeSettings.jsno** arquivo contém informações que o Visual Studio usa para o IntelliSense e para construir os argumentos de linha de comando que ele passa para cmake.exe para uma *configuração* especificada e um *ambiente* de compilador. Uma configuração especifica Propriedades que se aplicam a uma plataforma específica e tipo de compilação, por exemplo, `x86-Debug` ou `Linux-Release` . Cada configuração especifica um ambiente, que encapsula informações sobre o conjunto de ferramentas do compilador, por exemplo, MSVC, GCC ou clang. CMake usa os argumentos de linha de comando para regenerar o arquivo de *CMakeCache.txt* raiz e outros arquivos de projeto para o projeto. Os valores podem ser substituídos nos arquivos de *CMakeLists.txt* .

Você pode adicionar ou remover configurações no IDE e editá-las diretamente no arquivo JSON ou usar o **Editor de configurações CMake** (Visual Studio 2019 e posterior). Você pode alternar entre as configurações facilmente no IDE para gerar os vários arquivos de projeto. Consulte [Personalizar configurações de compilação do cmake no Visual Studio](customize-cmake-settings.md) para obter mais informações.

## <a name="configurations"></a>Configurações

A `configurations` matriz contém todas as configurações para um projeto CMake. Consulte [referência de configuração predefinida CMake](cmake-predefined-configuration-reference.md) para obter mais informações sobre as configurações predefinidas. Você pode adicionar qualquer número de configurações predefinidas ou personalizadas ao arquivo.

Um `configuration` tem estas propriedades:

- `addressSanitizerEnabled`: se **`true`** o compilar o programa com limpeza de endereço (experimental no Windows). No Linux, compile com-fno-omita-frame-ponteiro e otimização do compilador Level-os ou-OO para obter os melhores resultados.
- `addressSanitizerRuntimeFlags`: sinalizadores de tempo de execução passados para AddressSanitizer por meio da variável de ambiente ASAN_OPTIONS. Formato: sinalizador1 = valor: Flag2 = value2.
- `buildCommandArgs`: especifica as opções de build nativas passadas para o CMake após --build --. Por exemplo, passar -v ao usar o gerador Ninja força o Ninja a emitir linhas de comando de saída. Confira [Argumentos de linha de comando do Ninja](#ninja) para obter mais informações sobre os comandos do Ninja.
- `buildRoot`: especifica o diretório no qual o CMake gera scripts de build para o gerador escolhido.  Mapeia para a opção **-DCMAKE_BINARY_DIR** e especifica onde *CMakeCache.txt* será criado. Se a pasta não existir, ela será criada. Macros com suporte incluem `${workspaceRoot}`, `${workspaceHash}`, `${projectFile}`, `${projectDir}`, `${thisFile}`, `${thisFileDir}`, `${name}`, `${generator}`, `${env.VARIABLE}`.
- `cacheGenerationCommand`: especifica uma ferramenta de linha de comando e argumentos, por exemplo *gencache.bat depurar* para gerar o cache. O comando é executado a partir do Shell no ambiente especificado para a configuração quando o usuário solicita explicitamente a regeneração ou um CMakeLists.txt ou CMakeSettings.jsno arquivo é modificado.
- `cacheRoot`: especifica o caminho para um cache do CMake. Esse diretório deve conter um arquivo de *CMakeCache.txt* existente.
- `clangTidyChecks`: lista de avisos separados por vírgulas que serão passados para Clang; caracteres curinga são permitidos e o prefixo '-' removerá as verificações.
- `cmakeCommandArgs`: Especifica opções de linha de comando adicionais passadas para CMake quando invocada para gerar os arquivos de projeto.
- `cmakeToolchain`: especifica o arquivo de cadeia de ferramentas. Isso é passado para o CMake usando -DCMAKE_TOOLCHAIN_FILE."
- `codeAnalysisRuleset`: especifica o conjunto de regras para usar ao executar a análise de código. Pode ser um caminho completo ou o nome do arquivo de um conjunto de regras instalado pelo Visual Studio.
- `configurationType`: especifica a configuração do tipo de build para o gerador selecionado. Pode ser um destes:

  - Depurar
  - Versão
  - MinSizeRel
  - RelWithDebInfo
  
- `ctestCommandArgs`: especifica opções de linha de comando adicionais passadas para CTest ao executar os testes."
- `description`: a descrição dessa configuração que será exibida nos menus.
- `enableClangTidyCodeAnalysis`: Use Clang-Tidy para análise de código.
- `enableMicrosoftCodeAnalysis`: Use as ferramentas de análise de código da Microsoft para análise de código.
- `generator`: especifica o gerador do CMake a ser usado para essa configuração. Pode ser um destes:
  
  **Somente Visual Studio 2019:**
  - Visual Studio 16 2019
  - Visual Studio 16 2019 Win64
  - Visual Studio 16 2019 ARM

  **Visual Studio 2017 e posterior:**
  - Visual Studio 15 2017
  - Visual Studio 15 2017 Win64
  - Visual Studio 15 2017 ARM
  - Visual Studio 14 2015
  - Visual Studio 14 2015 Win64
  - Visual Studio 14 2015 ARM
  - Unix Makefiles
  - Ninja

Como o Ninja é criado para velocidades rápidas de builds em vez de flexibilidade e função, ele está definido como padrão. No entanto, alguns projetos do CMake podem não conseguir executar o build corretamente usando o Ninja. Se isso ocorrer, você poderá instruir o CMake para gerar projetos do Visual Studio em vez disso.

Para especificar um gerador do Visual Studio no Visual Studio 2017, abra o editor de configurações no menu principal escolhendo **CMake | Altere as configurações de CMake** . Exclua "Ninja" e digite "V". Isso ativa o IntelliSense, que permite escolher o gerador desejado.

Para especificar um gerador do Visual Studio no Visual Studio 2019, clique com o botão direito do mouse no arquivo de *CMakeLists.txt* em **Gerenciador de soluções** e escolha **configurações de CMake para projeto** > **Mostrar configurações avançadas** > **CMake gerador** .

Quando a configuração ativa especifica um gerador do Visual Studio, por padrão, MSBuild.exe é invocado com argumentos `-m -v:minimal`. Para personalizar a compilação, dentro do  *CMakeSettings.jsno* arquivo, você pode especificar [argumentos de linha de comando](../build/reference/msbuild-visual-cpp-overview.md) adicionais do MSBuild a serem passados para o sistema de compilação por meio da `buildCommandArgs` Propriedade:

   ```json
   "buildCommandArgs": "-m:8 -v:minimal -p:PreferredToolArchitecture=x64"
   ```

- `installRoot`: especifica o diretório no qual o CMake gera destinos de instalação para o gerador escolhido. Macros com suporte incluem `${workspaceRoot}`, `${workspaceHash}`, `${projectFile}`, `${projectDir}`, `${thisFile}`, `${thisFileDir}`, `${name}`, `${generator}`, `${env.VARIABLE}`.
- `inheritEnvironments`: especifica um ou mais ambientes do compilador dos quais essa configuração depende. Pode ser qualquer ambiente personalizado ou um dos ambientes predefinidos. Para obter mais informações, veja [Ambientes](#environments).
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

- `name`: dá um nome à configuração.  Consulte [referência de configuração predefinida CMake](cmake-predefined-configuration-reference.md) para obter mais informações sobre as configurações predefinidas.
- `wslPath`: o caminho para o iniciador de uma instância do subsistema do Windows para Linux.

### <a name="additional-settings-for-cmake-linux-projects"></a>Configurações adicionais para projetos do CMake Linux

- `remoteMachineName`: especifica o nome do computador Linux remoto que hospeda o CMake, builds e o depurador. Use o Gerenciador de Conexões para a adição de novos computadores Linux. Macros com suporte incluem `${defaultRemoteMachineName}`.
- `remoteCopySourcesOutputVerbosity`: especifica o nível de detalhes da fonte que copia a operação no computador remoto. Pode ser um entre "Normal", "Detalhado" ou "Diagnóstico".
- `remoteCopySourcesConcurrentCopies`: especifica o número de cópias simultâneas usadas durante a sincronização das origens para o computador remoto (somente SFTP).
- `remoteCopySourcesMethod`: especifica o método para copiar os arquivos para o computador remoto. Pode ser "rsync" ou "sftp".
- `remoteCMakeListsRoot`: especifica o diretório no computador remoto que contém o projeto do CMake. Macros com suporte incluem `${workspaceRoot}`, `${workspaceHash}`, `${projectFile}`, `${projectDir}`, `${thisFile}`, `${thisFileDir}`, `${name}`, `${generator}`, `${env.VARIABLE}`.
- `remoteBuildRoot`: especifica o diretório no computador remoto no qual o CMake gera scripts de build para o gerador escolhido. Macros com suporte incluem `${workspaceRoot}`, `${workspaceHash}`, `${projectFile}`, `${projectDir}`, `${thisFile}`, `${thisFileDir}`, `${name}`, `${generator}`, `${env.VARIABLE}`.
- `remoteInstallRoot`: especifica o diretório no computador remoto no qual o CMake gera destinos de instalação para o gerador escolhido. Macros com suporte incluem `${workspaceRoot}`, `${workspaceHash}`, `${projectFile}`, `${projectDir}`, `${thisFile}`, `${thisFileDir}`, `${name}`, `${generator}` e `${env.VARIABLE}`, em que `VARIABLE` é uma variável de ambiente definida no nível do sistema, do usuário ou da sessão.
- `remoteCopySources`: Um `boolean` que especifica se o Visual Studio deve copiar os arquivos de origem para o computador remoto. O padrão é true. Defina como false se você mesmo gerenciar a sincronização de arquivos.
- `remoteCopyBuildOutput`: Um `boolean` que especifica se as saídas de compilação devem ser copiadas do sistema remoto.
- `remoteCopyAdditionalIncludeDirectories`: Diretórios de inclusão adicionais a serem copiados do computador remoto para dar suporte ao IntelliSense. Formate como "/path1;/path2...".
- `remoteCopyExcludeDirectories`: Incluir diretórios para não copiar do computador remoto. Formate como "/path1;/path2...".
- `remoteCopyUseCompilerDefaults`: Especifica se deve ser usado o padrão de definição e inclusão de caminhos do compilador para o IntelliSense. Deve ser false somente se os compiladores em uso não oferecerem suporte a argumentos de estilo gcc.
- `rsyncCommandArgs`: especifica um conjunto de opções adicionais de linha de comando passadas para rsync.
- `remoteCopySourcesExclusionList`: A `array` que especifica uma lista de caminhos a serem excluídos ao copiar arquivos de origem ': um caminho pode ser o nome de um arquivo/diretório ou um caminho relativo à raiz da cópia. Curingas \\\"*\\\" e \\\"?\\\" podem ser usados para correspondência de padrões glob.
- `cmakeExecutable`: especifica o caminho completo para o executável do programa do CMake, incluindo o nome e a extensão do arquivo.
- `remotePreGenerateCommand`: especifica o comando a ser executado antes de executar CMake para analisar o arquivo de *CMakeLists.txt* .
- `remotePrebuildCommand`: especifica o comando a ser executado no computador remoto antes da compilação.
- `remotePostbuildCommand`: especifica o comando a ser executado no computador remoto após a compilação.
- `variables`: contém um par nome-valor das variáveis do CMake que serão passadas como **-D** *_nome_=_valor_* para o CMake. Se as instruções de compilação do projeto CMake especificarem a adição de qualquer variável diretamente ao arquivo de *CMakeCache.txt* , é recomendável adicioná-las aqui em vez disso. O exemplo a seguir mostra como especificar os pares nome-valor para o conjunto de ferramentas 14.14.26428:

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

Observe que, se você não definir o `"type"` , o `"STRING"` tipo será assumido por padrão.

- `remoteCopyOptimizations`: As propriedades da **versão 16,5 ou posterior do Visual Studio 2019** para controlar a cópia de origem para o destino remoto. As otimizações são habilitadas por padrão. Inclui `remoteCopyUseOptimizations`, `rsyncSingleDirectoryCommandArgs` e `remoteCopySourcesMaxSmallChange`.

## <a name="environments"></a><a name="environments"></a> Sistemas

Um *ambiente* encapsula as variáveis de ambiente que são definidas no processo que o Visual Studio usa para invocar cmake.exe. Para projetos MSVC, as variáveis são aquelas que são definidas em um [prompt de comando do desenvolvedor](building-on-the-command-line.md) para uma plataforma específica. Por exemplo, o `msvc_x64_x64` ambiente é o mesmo que executar o **prompt de comando do desenvolvedor para vs 2017** ou **prompt de comando do desenvolvedor para vs 2019** com os argumentos **-Arch = AMD64-host_arch = AMD64** . Você pode usar a `env.{<variable_name>}` sintaxe em *CMakeSettings.js* para fazer referência às variáveis de ambiente individuais, por exemplo, para construir caminhos para pastas.  Os seguintes ambientes predefinidos são fornecidos:

- linux_arm: direcione o Linux do ARM remotamente.
- linux_x64: direcione o Linux x64 remotamente.
- linux_x86: direcione o Linux x86 remotamente.
- msvc_arm: direcionar as janelas ARM com o compilador MSVC.
- msvc_arm_x64: direcione as janelas ARM com o compilador MSVC de 64 bits.
- msvc_arm64: direcione o Windows ARM64 com o compilador MSVC.
- msvc_arm64_x64: direcione o Windows ARM64 com o compilador MSVC de 64 bits.
- msvc_x64: direcione o Windows x64 com o compilador MSVC.
- msvc_x64_x64: direcionar o Windows x64 com o compilador MSVC de 64 bits.
- msvc_x86: direcione o Windows x86 com o compilador MSVC.
- msvc_x86_x64: direcione o Windows x86 com o compilador MSVC de 64 bits.

### <a name="accessing-environment-variables-from-cmakeliststxt"></a>Acessando variáveis de ambiente de CMakeLists.txt

De um arquivo de CMakeLists.txt, todas as variáveis de ambiente são referenciadas pela sintaxe `$ENV{variable_name}` . Para ver as variáveis disponíveis para um ambiente, abra o prompt de comando correspondente e digite `SET` . Algumas das informações em variáveis de ambiente também estão disponíveis por meio de variáveis de introspecção do sistema CMake, mas talvez você ache mais conveniente usar a variável de ambiente. Por exemplo, a versão do compilador MSVC ou a versão SDK do Windows são facilmente recuperadas por meio das variáveis de ambiente.

### <a name="custom-environment-variables"></a>Variáveis de ambiente personalizadas

No  `CMakeSettings.json` , você pode definir variáveis de ambiente personalizadas globalmente ou por configuração na `environments` matriz. Um ambiente personalizado é uma maneira conveniente de agrupar um conjunto de propriedades que você pode usar no lugar de um ambiente predefinido ou estender ou modificar um ambiente predefinido. Cada item na matriz `environments` consiste em:

- `namespace`: dá um nome ao ambiente de modo que suas variáveis possam ser referenciadas de uma configuração na forma `namespace.variable`. O objeto de ambiente padrão é chamado `env` e é preenchido com determinadas variáveis de ambiente do sistema, incluindo `%USERPROFILE%` .
- `environment`: identifica exclusivamente este grupo de variáveis. Permite que o grupo seja herdado posteriormente em uma entrada `inheritEnvironments`.
- `groupPriority`: Um inteiro que especifica a prioridade dessas variáveis ao avaliá-las. Itens de maior número são avaliados primeiro.
- `inheritEnvironments`: Uma matriz de valores que especificam o conjunto de ambientes que são herdados por esse grupo. Essa funcionalidade permite que você herde ambientes padrão e crie variáveis de ambiente personalizadas que são passadas para o CMake.exe quando ele é executado.

**Visual Studio 2019 versão 16,4 e posterior:** Os destinos de depuração são iniciados automaticamente com o ambiente que você especifica no *CMakeSettings.js* . Você pode substituir ou adicionar variáveis de ambiente em uma base por destino ou por tarefa em [launch.vs.js](launch-vs-schema-reference-cpp.md) e [tasks.vs.jsem](tasks-vs-json-schema-reference-cpp.md).

O exemplo a seguir define uma variável global, **BuildDir** , que é herdada nas configurações x86-Debug e x64-Debug. Cada configuração usa a variável para especificar o valor para a propriedade **buildRoot** dessa configuração. Também observe como cada configuração usa a propriedade **inheritEnvironments** para especificar uma variável que só se aplica a essa configuração.

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

No exemplo a seguir, a configuração de Depuração x86 define seu próprio valor para a propriedade **BuildDir** . Esse valor substitui o valor definido pela propriedade **BuildDir** global de modo que **BuildRoot** seja avaliada como `D:\custom-builddir\x86-Debug`.

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
      // Since this configuration doesn't modify BuildDir, it inherits
      // from the one defined globally.
      "buildRoot": "${env.BuildDir}\\${name}"
    }
  ]
}
```

## <a name="macros"></a>Macros

As macros a seguir podem ser usadas no *CMakeSettings.jsem* :

- `${workspaceRoot}` – o caminho completo da pasta do espaço de trabalho
- `${workspaceHash}` – hash do local do workspace; útil para criação de um identificador exclusivo para o workspace atual (por exemplo, para uso em caminhos de pasta)
- `${projectFile}` – o caminho completo do arquivo CMakeLists.txt raiz
- `${projectDir}` – o caminho completo da pasta do arquivo CMakeLists.txt raiz
- `${thisFile}` – o caminho completo do arquivo `CMakeSettings.json`
- `${name}` – o nome da configuração
- `${generator}` – o nome do gerador do CMake usado nessa configuração

Todas as referências a macros e variáveis de ambiente no *CMakeSettings.jsem* são expandidas antes de serem passadas para a linha de comando cmake.exe.

## <a name="ninja-command-line-arguments"></a><a name="ninja"></a> Argumentos de linha de comando do Ninja

Se os destinos não estão especificados, compila o destino 'padrão'.

```cmd
C:\Program Files (x86)\Microsoft Visual Studio\Preview\Enterprise>ninja -?
ninja: invalid option -- `-?'
usage: ninja [options] [targets...]
```

|Opção|Descrição|
|--------------|------------|
| --versão  | imprime a versão do Ninja ("1.7.1")|
|   -C DIR   | altera para DIR antes de qualquer outra ação|
|   -f FILE  | especifica o arquivo de entrada de build (padrão= build.ninja)|
|   -j N     | executa N trabalhos em paralelo (padrão= 14, derivado das CPUs disponíveis)|
|   -k N     | continua até N trabalhos falharem (padrão= 1)|
|   -l N     | não inicia novos trabalhos se a média de carga é maior que N|
|   -n       | simulação (não executa comandos, mas se comporta como se eles tiveram êxito)|
|   -v       | mostra todas as linhas de comando durante o build|
|   -d MODE  | habilita a depuração (usa a lista -d para listar os modos)|
|   -t TOOL  | executa uma subferramenta (usa a lista -t para listar as subferramentas). encerra as opções de nível superior; outros sinalizadores são passados para a ferramenta|
|   -w FLAG  | ajusta os avisos (usa a lista -w para listar os avisos)|

::: moniker-end
