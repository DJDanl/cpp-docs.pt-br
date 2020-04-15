---
title: Referência CppProperties.json
ms.date: 08/09/2019
helpviewer_keywords:
- CppProperties.json file [C++]
ms.openlocfilehash: be6db52e1e62244e9f44db8ac86238242ab50ca0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328724"
---
# <a name="cpppropertiesjson-reference"></a>Referência CppProperties.json

Projetos de Open Folder que não usam CMake podem armazenar configurações de configuração de projeto para o IntelliSense em um arquivo *CppProperties.json.* (Os projetos CMake usam um arquivo [CMakeSettings.json.)](customize-cmake-settings.md) Uma configuração consiste em pares de nomes/valores e define #include caminhos, switches de compilador e outros parâmetros. Consulte [projetos open folder para C++](open-folder-projects-cpp.md) para obter mais informações sobre como adicionar configurações em um projeto de Pasta Aberta. As seções a seguir resumem as várias configurações. Para obter uma descrição completa do esquema, navegue até *CppProperties_schema.json*, cujo caminho completo é dado no topo do editor de código quando *CppProperties.json* estiver aberto.

## <a name="configuration-properties"></a>Propriedades de configuração

Uma configuração pode ter uma das seguintes propriedades:

|||
|-|-|
|`inheritEnvironments`| Especifica quais ambientes se aplicam a essa configuração.|
|`name`|O nome de configuração que aparecerá na parada de configuração C++|
|`includePath`|Uma lista separada por comma de pastas que devem ser especificadas no caminho de inclusão (mapas para /I para a maioria dos compiladores)|
|`defines`|A lista de macros que deve ser definida (mapeada para /D na maioria dos compiladores)|
|`compilerSwitches`|Uma ou mais opções adicionais que podem influenciar o comportamento do IntelliSense|
|`forcedInclude`|O cabeçalho a ser incluído automaticamente em cada unidade de compilação (mapeado para /FI no MSVC ou -include no Clang)|
|`undefines`|A lista de macros a terem as definições excluídas (mapeada para /U no MSVC)|
|`intelliSenseMode`|O mecanismo IntelliSense a ser usado. Você pode especificar uma das variantes predefinidas específicas da arquitetura para MSVC, gcc ou Clang.|
|`environments`|Conjuntos de variáveis definidas pelo usuário que se comportam como variáveis de ambiente\< em um prompt de comando e são acessados com o ${env. Macro VARIÁVEL>}.|

### <a name="intellisensemode-values"></a>intelliSenseMode valores

O editor de código mostra as opções disponíveis quando você começa a digitar:

![Abrir pasta IntelliSense](media/open-folder-intellisense-mode.png "Abrir pasta IntelliSense")

Estes são os valores suportados:

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
- linux-gcc-arm

Nota: `msvc-x86` Os `msvc-x64` valores e são suportados apenas por razões herdadas. Use `windows-msvc-*` as variantes em vez disso.

## <a name="pre-defined-environments"></a>Ambientes pré-definidos

O Visual Studio fornece os seguintes ambientes predefinidos para o Microsoft C++ que mapeiam o Prompt de Comando do Desenvolvedor correspondente. Quando você herda um desses ambientes, você pode se referir a `env` qualquer uma das variáveis do ambiente\< usando a propriedade global com esta sintaxe macro: ${env. VARIÁVEL>}.

|Nome de variável|Descrição|
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

|Nome de variável|Descrição|
|-----------|-----------------|
|linux_x86|Direcionar ao Linux x86 remotamente|
|linux_x64|Direcionar ao Linux x64 remotamente|
|linux_arm|Direcionar ao ARM Linux remotamente|

## <a name="user-defined-environments"></a><a name="user_defined_environments"></a>Ambientes definidos pelo usuário

Você pode usar `environments` opcionalmente a propriedade para definir conjuntos de variáveis no *CppProperties.json* globalmente ou por configuração. Essas variáveis se comportam como variáveis de ambiente no contexto de um projeto Open\< Folder e podem ser acessadas com o ${env. Sintaxe variável>} de *tasks.vs.json* e *launch.vs.json* depois de definidas aqui. No entanto, eles não são necessariamente definidos como variáveis de ambiente reais em qualquer prompt de comando que o Visual Studio usa internamente.

**Visual Studio 2019 versão 16.4 e posteriores:** As variáveis específicas de configuração definidas no *CppProperties.json* são captadas automaticamente por `inheritEnvironments`alvos e tarefas de depuração sem a necessidade de definir . Os alvos de depuração são lançados automaticamente com o ambiente especificado em *CppProperties.json*.

**Visual Studio 2019 versão 16.3 e anterior:** Quando você consome um ambiente, então `inheritsEnvironments` você tem que especificá-lo na propriedade, mesmo que o ambiente seja definido como parte da mesma configuração; a `environment` propriedade especifica o nome do ambiente. O exemplo a seguir mostra uma configuração de amostra para habilitar o IntelliSense para GCC em uma instalação MSYS2. Observe como a configuração define `mingw_64` e herda `includePath` o ambiente `INCLUDE` e como a propriedade pode acessar a variável.

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

Quando você define uma propriedade **de ambientes** dentro de uma configuração, ela substitui quaisquer variáveis globais de mesmo nome.

## <a name="built-in-macros"></a>Macros incorporadas

Você tem acesso às seguintes macros incorporadas dentro *do CppProperties.json*:

|||
|-|-|
|`${workspaceRoot}`| O caminho completo para a pasta do espaço de trabalho|
|`${projectRoot}`| O caminho completo para a pasta onde *CppProperties.json* é colocado|
|`${env.vsInstallDir}`| O caminho completo para a pasta onde a instância de execução do Visual Studio é instalada|

### <a name="example"></a>Exemplo

Se o seu projeto tiver uma pasta de inclusão e também incluir *windows.h* e outros cabeçalhos comuns do Windows SDK, você pode querer atualizar seu arquivo de configuração *CppProperties.json* com o seguinte inclui:

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

Se você não estiver vendo o IntelliSense que você espera, você pode solucionar problemas indo para O**Editor** > de texto**de opções** >  **de ferramentas** > **C/C++** > **avançado** e configurando Ativar **o registro** para **true**. Para começar, tente definir **o nível de registro** para 5 e os **filtros de registro** para 8.

![Registro de diagnóstico](media/diagnostic-logging.png)

A saída é canalizada para a **janela de saída** e é visível quando você escolhe Mostrar saída **de: Log Visual C++**. A saída contém, entre outras coisas, a lista de caminhos reais que o IntelliSense está tentando usar. Se os caminhos não corresponderem aos do *CppProperties.json,* tente fechar a pasta e excluir a subpasta *.vs* que contém dados de navegação em cache.

Para solucionar erros do IntelliSense causados por caminhos de inclusão ausentes, abra a **Lista de Erros** e filtre a saída para "somente IntelliSense" e o código de erro E1696 "não é possível abrir o arquivo de origem...".
