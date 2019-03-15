---
title: Referência de esquema CppProperties.json
ms.date: 03/05/2019
helpviewer_keywords:
- CMake in Visual C++
ms.openlocfilehash: fd655de3313dd95eb3fcefaeba21e703d32e860a
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824335"
---
# <a name="cpppropertiesjson-schema-reference"></a>Referência de esquema CppProperties.json

Projetos do Open Folder que não usam CMake podem armazenar definições de configuração de projeto em um arquivo `CppProperties.json`. (Projetos de CMake usam um arquivo [CMakeSettings.json](customize-cmake-settings.md).) O IDE do Visual Studio usa `CppProperties.json` para IntelliSense e navegação de código. Uma configuração consiste em pares nome/valor e define #incluir caminhos, opções do compilador e outros parâmetros. 


## <a name="default-configurations"></a>Configurações padrão

O Visual Studio fornece configurações predefinidas para Depuração e Versão de x86 e x64. Por padrão, seu projeto tem uma configuração de Depuração do x86 em `CppProperties.json`. Para adicionar uma nova configuração, clique com o botão direito do mouse no arquivo `CppProperties.json` no **Gerenciador de Soluções** e escolha **Adicionar Configuração**:

![Abrir Pasta, adicionar configuração](media/open-folder-add-config.png "Abrir Pasta, adicionar nova configuração")

As configurações padrão são mostradas aqui:

```json
{
  "configurations": [
    {
      "inheritEnvironments": [
        "msvc_x86"
      ],
      "name": "x86-Debug",
      "includePath": [
        "${env.INCLUDE}",
        "${workspaceRoot}\\**"
      ],
      "defines": [
        "WIN32",
        "_DEBUG",
        "UNICODE",
        "_UNICODE"
      ],
      "intelliSenseMode": "windows-msvc-x86"
    },
    {
      "inheritEnvironments": [
        "msvc_x86"
      ],
      "name": "x86-Release",
      "includePath": [
        "${env.INCLUDE}",
        "${workspaceRoot}\\**"
      ],
      "defines": [
        "WIN32",
        "NDEBUG",
        "UNICODE",
        "_UNICODE"
      ],
      "intelliSenseMode": "windows-msvc-x86"
    },
    {
      "inheritEnvironments": [
        "msvc_x64"
      ],
      "name": "x64-Debug",
      "includePath": [
        "${env.INCLUDE}",
        "${workspaceRoot}\\**"
      ],
      "defines": [
        "WIN32",
        "_DEBUG",
        "UNICODE",
        "_UNICODE"
      ],
      "intelliSenseMode": "windows-msvc-x64"
    },
    {
      "inheritEnvironments": [
        "msvc_x64"
      ],
      "name": "x64-Release",
      "includePath": [
        "${env.INCLUDE}",
        "${workspaceRoot}\\**"
      ],
      "defines": [
        "WIN32",
        "NDEBUG",
        "UNICODE",
        "_UNICODE"
      ],
      "intelliSenseMode": "windows-msvc-x64"
    }
  ]
}
```
Para propriedades que têm um conjunto de valores permitidos, o editor de código mostra as opções disponíveis quando você começa a digitar:

![Abrir Pasta IntelliSense](media/open-folder-intellisense-mode.png "Abrir Pasta IntelliSense")



## <a name="configuration-properties"></a>Propriedades de configuração

Uma configuração pode ter uma das seguintes propriedades:

|||
|-|-|
|`name`|O nome de configuração exibido na lista suspensa de configuração do C++|
|`includePath`|A lista de pastas que deve ser especificada no caminho de inclusão (mapeada para /I na maioria dos compiladores)|
|`defines`|A lista de macros que deve ser definida (mapeada para /D na maioria dos compiladores)|
|`compilerSwitches`|Uma ou mais opções adicionais que podem influenciar o comportamento do IntelliSense|
|`forcedInclude`|O cabeçalho a ser incluído automaticamente em cada unidade de compilação (mapeado para /FI no MSVC ou -include no Clang)|
|`undefines`|A lista de macros a terem as definições excluídas (mapeada para /U no MSVC)|
|`intelliSenseMode`|O mecanismo IntelliSense a ser usado. Especifique as variantes específicas à arquitetura para o MSVC, o GCC ou o Clang:<br/><br/>- msvc-x86 (padrão)<br/>- msvc-x64<br/>- msvc-arm<br/>- windows-clang-x86<br/>- windows-clang-x64<br/>- windows-clang-arm<br/>- Linux-x64<br/>- Linux-x86<br/>- Linux-arm<br/>- gccarm|

## <a name="custom-configurations"></a>Configurações personalizadas


Você pode personalizar qualquer uma das configurações padrão no `CppProperties.json` ou criar novas configurações. Cada uma delas será exibida na lista suspensa de configurações:

```json
{
  "configurations": [
    {
      "name": "Windows",
      ...
    },
    {
      "name": "with EXTERNAL_CODECS",
      ...
    }
  ]
}
```

## <a name="system-environment-variables"></a>Variáveis de ambiente do sistema 

 `CppProperties.json` dá suporte à expansão de variáveis de ambiente do sistema para caminhos de inclusão e outros valores de propriedade. A sintaxe é `${env.FOODIR}` para expandir uma variável de ambiente `%FOODIR%`. Também há suporte para as seguintes variáveis definidas pelo sistema:

|Nome da variável|Descrição|
|-----------|-----------------|
|vsdev|O ambiente padrão do Visual Studio|
|msvc_x86|Compilar para x86 usando ferramentas x86|
|msvc_arm|Compilar para ARM usando ferramentas x86|
|msvc_arm64|Compilar para ARM64 usando ferramentas x86|
|msvc_x86_x64|Compilar para AMD64 usando ferramentas x86|
|msvc_x64_x64|Compilar para AMD64 usando ferramentas de 64 bits|
|msvc_arm_x64|Compilar para ARM usando ferramentas de 64 bits|
|msvc_arm64_x64|Compilar para ARM64 usando ferramentas de 64 bits|

Quando a carga de trabalho do Linux é instalada, os seguintes ambientes ficam disponíveis para o direcionamento remoto do Linux e do WSL:

|Nome da variável|Descrição|
|-----------|-----------------|
|linux_x86|Direcionar ao Linux x86 remotamente|
|linux_x64|Direcionar ao Linux x64 remotamente|
|linux_arm|Direcionar ao ARM Linux remotamente|

## <a name="custom-environment-variables"></a>Variáveis de ambiente personalizadas

Defina variáveis de ambiente personalizadas em `CppProperties.json` globalmente ou por configuração. O exemplo a seguir mostra como as variáveis de ambiente padrão e personalizadas podem ser declaradas e usadas. A propriedade **environments** global declara uma variável chamada **INCLUDE** que pode ser usada por qualquer configuração:

```json
{
  // The "environments" property is an array of key value pairs of the form
  // { "EnvVar1": "Value1", "EnvVar2": "Value2" }
  "environments": [
    {
      "INCLUDE": "${workspaceRoot}\src\includes"
    }
  ],

  "configurations": [
    {
      "inheritEnvironments": [
        // Inherit the MSVC 32-bit environment and toolchain.
        "msvc_x86"
      ],
      "name": "x86",
      "includePath": [
        // Use the include path defined above.
        "${env.INCLUDE}"
      ],
      "defines": [ "WIN32", "_DEBUG", "UNICODE", "_UNICODE" ],
      "intelliSenseMode": "msvc-x86"
    },
    {
      "inheritEnvironments": [
        // Inherit the MSVC 64-bit environment and toolchain.
        "msvc_x64"
      ],
      "name": "x64",
      "includePath": [
        // Use the include path defined above.
        "${env.INCLUDE}"
      ],
      "defines": [ "WIN32", "_DEBUG", "UNICODE", "_UNICODE" ],
      "intelliSenseMode": "msvc-x64"
    }
  ]
}
```
## <a name="per-configuration-environment-variables"></a>Variáveis de ambiente por configuração

Defina também uma propriedade **environments** dentro de uma configuração, de modo que ela só se aplique a essa configuração e substitua todas as variáveis globais com o mesmo nome. No seguinte exemplo, a configuração x64 define uma variável **INCLUDE** local que substitui o valor global:

```json
{
  "environments": [
    {
      "INCLUDE": "${workspaceRoot}\src\includes"
    }
  ],

  "configurations": [
    {
      "inheritEnvironments": [
        "msvc_x86"
      ],
      "name": "x86",
      "includePath": [
        // Use the include path defined in the global environments property.
        "${env.INCLUDE}"
      ],
      "defines": [ "WIN32", "_DEBUG", "UNICODE", "_UNICODE" ],
      "intelliSenseMode": "msvc-x86"
    },
    {
      "environments": [
        {
          // Append 64-bit specific include path to env.INCLUDE.
          "INCLUDE": "${env.INCLUDE};${workspaceRoot}\src\includes64"
        }
      ],

      "inheritEnvironments": [
        "msvc_x64"
      ],
      "name": "x64",
      "includePath": [
        // Use the include path defined in the local environments property.
        "${env.INCLUDE}"
      ],
      "defines": [ "WIN32", "_DEBUG", "UNICODE", "_UNICODE" ],
      "intelliSenseMode": "msvc-x64"
    }
  ]
}
```

Todas as variável de ambiente personalizadas e padrão também estão disponíveis em `tasks.vs.json` e `launch.vs.json`.

#### <a name="build-in-macros"></a>Macros internas

Você tem acesso às seguintes macros internas dentro de `CppProperties.json`:

|||
|-|-|
|`${workspaceRoot}`| o caminho completo para a pasta de workspace|
|`${projectRoot}`| o caminho completo para a pasta em que `CppProperties.json` está localizado|
|`${vsInstallDir}`| o caminho completo para a pasta na qual a instância em execução do VS 2017 está instalada|

Por exemplo, se o projeto tem uma pasta de inclusão e também inclui windows.h e outros cabeçalhos comuns do SDK do Windows, recomendamos que você atualize o arquivo de configuração `CppProperties.json` com estas inclusões:

```json
{
  "configurations": [
    {
      "name": "Windows",
      "includePath": [
        // local include folder
        "${workspaceRoot}\include",
        // Windows SDK and CRT headers
        "${env.WindowsSdkDir}\include\${env.WindowsSDKVersion}\ucrt",
        "${env.NETFXSDKDir}\include\um",
        "${env.WindowsSdkDir}\include\${env.WindowsSDKVersion}\um",
        "${env.WindowsSdkDir}\include\${env.WindowsSDKVersion}\shared",
        "${env.VCToolsInstallDir}\include"
      ]
    }
  ]
}
```

> [!Note]
> `%WindowsSdkDir%` e `%VCToolsInstallDir%` não são definidos como variáveis de ambiente globais; portanto, inicie devenv.exe em um "Prompt de Comando do Desenvolvedor para VS 2017" que define essas variáveis.

## <a name="troubleshoot-intellisense-errors"></a>Solucionar problemas de erros do IntelliSense

Para solucionar erros do IntelliSense causados por caminhos de inclusão ausentes, abra a **Lista de Erros** e filtre a saída para "somente IntelliSense" e o código de erro E1696 "não é possível abrir o arquivo de origem...".



