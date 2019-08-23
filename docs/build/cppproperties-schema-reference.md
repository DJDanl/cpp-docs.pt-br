---
title: Referência de esquema CppProperties.json
ms.date: 08/09/2019
helpviewer_keywords:
- CppProperties.json file [C++]
ms.openlocfilehash: 06029157b4b3826bc9c34a4434ab390f3eaa5a44
ms.sourcegitcommit: ace42fa67e704d56d03c03745b0b17d2a5afeba4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2019
ms.locfileid: "69975933"
---
# <a name="cpppropertiesjson-schema-reference"></a>Referência de esquema CppProperties.json

Abra pastas projetos que não usam CMake podem armazenar definições de configuração de projeto para IntelliSense em um arquivo *CppProperties. JSON* . (Projetos de CMake usam um arquivo [CMakeSettings.json](customize-cmake-settings.md).) Uma configuração consiste em pares nome/valor e define #incluir caminhos, opções do compilador e outros parâmetros. Consulte [abrir projetos de pasta C++ para](open-folder-projects-cpp.md) obter mais informações sobre como adicionar configurações em um projeto de pasta aberta.

## <a name="configuration-properties"></a>Propriedades de configuração

Uma configuração pode ter uma das seguintes propriedades:

|||
|-|-|
|`inheritEnvironments`| Especifica quais ambientes se aplicam a essa configuração.|
|`name`|O nome da configuração que aparecerá no C++ menu suspenso de configuração|
|`includePath`|Uma lista separada por vírgulas de pastas que devem ser especificadas no caminho de inclusão (mapeia para/I para a maioria dos compiladores)|
|`defines`|A lista de macros que deve ser definida (mapeada para /D na maioria dos compiladores)|
|`compilerSwitches`|Uma ou mais opções adicionais que podem influenciar o comportamento do IntelliSense|
|`forcedInclude`|O cabeçalho a ser incluído automaticamente em cada unidade de compilação (mapeado para /FI no MSVC ou -include no Clang)|
|`undefines`|A lista de macros a terem as definições excluídas (mapeada para /U no MSVC)|
|`intelliSenseMode`|O mecanismo IntelliSense a ser usado. Você pode especificar uma das variantes específicas de arquitetura predefinidas para MSVC, gcc ou clang.|
|`environments`|Conjuntos de variáveis definidos pelo usuário que se comportam como variáveis de ambiente em um prompt de comando e são acessados com $ {env.<VARIABLE>} Ela.|

### <a name="intellisensemode-values"></a>valores de intelliSensemode

O editor de código mostra as opções disponíveis quando você começa a digitar:

![Abrir Pasta IntelliSense](media/open-folder-intellisense-mode.png "Abrir Pasta IntelliSense")

Estes são os valores com suporte:

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
- Linux-gcc-ARM

Observação: Há suporte para os valores `msvc-x86` e `msvc-x64` apenas por motivos de herança. Em vez `windows-msvc-*` disso, use as variantes.

## <a name="pre-defined-environments"></a>Ambientes predefinidos

O Visual Studio fornece os seguintes ambientes predefinidos para a Microsoft C++ que são mapeados para o prompt de comando do desenvolvedor correspondente. Ao herdar um desses ambientes, você pode consultar qualquer uma das variáveis de ambiente usando a propriedade `env` global com esta sintaxe de macro: $ {env.\< VARIÁVEL >}.

|Nome da variável|Descrição|
|-----------|-----------------|
|vsdev|O ambiente padrão do Visual Studio|
|msvc_x86|Compilar para x86 usando ferramentas x86|
|msvc_x64|Compilar para AMD64 usando ferramentas de 64 bits|
|msvc_arm|Compilar para ARM usando ferramentas x86|
|msvc_arm64|Compilar para ARM64 usando ferramentas x86|
|msvc_x86_x64|Compilar para AMD64 usando ferramentas x86|
|msvc_arm_x64|Compilar para ARM usando ferramentas de 64 bits|
|msvc_arm64_x64|Compilar para ARM64 usando ferramentas de 64 bits|

Quando a carga de trabalho do Linux é instalada, os seguintes ambientes ficam disponíveis para o direcionamento remoto do Linux e do WSL:

|Nome da variável|Descrição|
|-----------|-----------------|
|linux_x86|Direcionar ao Linux x86 remotamente|
|linux_x64|Direcionar ao Linux x64 remotamente|
|linux_arm|Direcionar ao ARM Linux remotamente|

## <a name="user_defined_environments"></a>Ambientes definidos pelo usuário

Opcionalmente, você pode usar `environments` a propriedade para definir conjuntos de variáveis em *CppProperties. JSON* globalmente ou por configuração. Essas variáveis se comportam como variáveis de ambiente no contexto de um projeto de pasta aberta e podem ser acessadas\< com o $ {env. VARIÁVEL >} sintaxe de *Tasks. vs. JSON* e *Launch. vs. JSON* depois de definidos aqui. No entanto, eles não são necessariamente definidos como variáveis de ambiente reais em qualquer prompt de comando que o Visual Studio usa internamente.

Quando você consumir um ambiente, precisará especificá-lo na `inheritsEnvironments` Propriedade mesmo se o ambiente for definido como parte da mesma configuração; a `environment` propriedade especifica o nome do ambiente. O exemplo a seguir mostra uma configuração de exemplo para habilitar o IntelliSense para GCC em uma instalação do MSYS2. Observe como a configuração define e herda o `mingw_64` ambiente e como a `includePath` propriedade pode acessar a `INCLUDE` variável.

```json
"configurations": [
    {

      "inheritEnvironments": [
        "mingw_64"
      ],
      "name": "Mingw64",
      "includePath ,": [
        "${env.INCLUDE}",
        "${workspaceRoot}\\**",
      ],
      "intelliSenseMode": "linux-gcc-x64",
      "environments": [
        {
          "MINGW64_ROOT": "C:\\msys64\\mingw64",
          "BIN_ROOT": "${env.MINGW64_ROOT}\\bin",
          "FLAVOR": "x86_64-w64-mingw32",
          "TOOLSET_VERSION": "9.1.0",
          "PATH": "${env.MINGW64_ROOT}\\bin;${env.MINGW64_ROOT}\\..\\usr\\local\\bin;${env.MINGW64_ROOT}\\..\\usr\\bin;${env.MINGW64_ROOT}\\..\\bin;${env.PATH}",
          "INCLUDE": "${env.MINGW64_ROOT}\\include\\c++\\${env.TOOLSET_VERSION};${env.MINGW64_ROOT}\\include\\c++\\${env.TOOLSET_VERSION}\\tr1;${env.MINGW64_ROOT}\\include\\c++\\${env.TOOLSET_VERSION}\\${env.FLAVOR};",
          "environment": "mingw_64"
        }
      ]
    }
  ]
```

Quando você define uma propriedade de **ambientes** dentro de uma configuração, ela substitui todas as variáveis globais do mesmo nome.

## <a name="built-in-macros"></a>Macros internas

Você tem acesso às seguintes macros internas dentro de *CppProperties. JSON*:

|||
|-|-|
|`${workspaceRoot}`| O caminho completo para a pasta do espaço de trabalho|
|`${projectRoot}`| O caminho completo para a pasta onde *CppProperties. JSON* é colocado|
|`${env.vsInstallDir}`| O caminho completo para a pasta em que a instância em execução do Visual Studio está instalada|

### <a name="example"></a>Exemplo

Se o seu projeto tiver uma pasta include e também incluir o *Windows. h* e outros cabeçalhos comuns da SDK do Windows, talvez você queira atualizar o arquivo de configuração *CppProperties. JSON* com o seguinte:

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
> `%WindowsSdkDir%` e `%VCToolsInstallDir%` não são definidos como variáveis de ambiente globais; portanto, inicie devenv.exe em um Prompt de Comando do Desenvolvedor que define essas variáveis. (Digite "desenvolvedor" no Menu Iniciar do Windows.)

## <a name="troubleshoot-intellisense-errors"></a>Solucionar problemas de erros do IntelliSense

Se você não estiver vendo o IntelliSense que espera, poderá solucionar problemas acessando **ferramentas** > **Opções** > **Editor** > de texto > **CC++/** **avançado** e configuração **habilitar registro em log** como **true**. Para começar, tente definir o **nível de log** para 5 e **registrar filtros em log** como 8.

![Diagnostic logging](media/diagnostic-logging.png)

A saída é canalizada para o **janela de saída** e fica visível quando você **escolhe Mostrar saída de: C++ Log**do Visual. A saída contém, entre outras coisas, a lista de caminhos de inclusão reais que o IntelliSense está tentando usar. Se os caminhos não corresponderem àqueles em *CppProperties. JSON*, tente fechar a pasta e excluir a subpasta *. vs* que contém dados de navegação armazenados em cache.

Para solucionar erros do IntelliSense causados por caminhos de inclusão ausentes, abra a **Lista de Erros** e filtre a saída para "somente IntelliSense" e o código de erro E1696 "não é possível abrir o arquivo de origem...".
