---
title: Configurar um projeto do Linux CMake no Visual Studio
description: Como configurar, editar e compilar um projeto do Linux CMake no Visual Studio
ms.date: 05/21/2019
ms.assetid: f8707b32-f90d-494d-ae0b-1d44425fdc25
ms.openlocfilehash: e2cda5e9b942342cca035c48054aadb5425b69cf
ms.sourcegitcommit: bde3279f70432f819018df74923a8bb895636f81
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/23/2019
ms.locfileid: "66182886"
---
# <a name="configure-a-linux-cmake-project"></a>Configurar um projeto do Linux CMake

Quando você abre uma pasta que contém um projeto do CMake, o Visual Studio usa os metadados que o CMake produz para configurar o IntelliSense e é compilado automaticamente. As definições de configuração e depuração locais são armazenadas em arquivos JSON que opcionalmente podem ser compartilhados com outras pessoas que estão usando o Visual Studio. 

O Visual Studio não modifica os arquivos CMakeLists.txt ou o cache do CMake original de modo que outras pessoas trabalhando no mesmo projeto possam continuar a usar quaisquer ferramentas que já estejam usando.

Para obter informações gerais sobre o suporte do CMake no Visual Studio, confira [Ferramentas CMake para Visual Studio](../build/cmake-projects-in-visual-studio.md). Leia este primeiro antes de continuar aqui.

## <a name="before-you-begin"></a>Antes de começar

Primeiro, verifique se você tem a carga de trabalho **Desenvolvimento do Linux com C++** instalada, incluindo o componente do CMake. Veja [Instalar uma carga de trabalho do Linux para C++ no Visual Studio](download-install-and-setup-the-linux-development-workload.md). 

No computador do Linux, verifique se os seguintes itens estão instalados: 

- gcc
- gdb
- rsync
- zip 

::: moniker range="vs-2019"

O suporte do Linux para projetos do CMake requer que uma versão recente do CMake seja instalada no computador de destino. Muitas vezes, a versão oferecida pelo gerenciador de pacotes padrão de uma distribuição não é recente o suficiente para dar suporte aos recursos de todos do IDE. O Visual Studio 2019 pode instalar automaticamente uma cópia local do usuário do CMake em computadores Linux remotos que não têm uma versão recente do CMake instalado. Se uma versão compatível do CMake não for detectada na primeira vez em que você compilar seu projeto, você verá uma barra de informações oferecendo a instalação do CMake.

Os binários serão instalados no `~/.vs/cmake`. Depois de implantar os binários, seu projeto será automaticamente regenerado. Se o CMake especificado pelo campo `cmakeExecutable` em `CMakeSettings.json` for inválido (não existir ou for uma versão sem suporte) e os binários predefinidos estiverem presentes, o Visual Studio ignorará `cmakeExecutable` e usará os binários predefinidos.

::: moniker-end

::: moniker range="vs-2017"

O suporte ao CMake no Visual Studio requer o suporte do modo de servidor que foi apresentado no CMake 3.8. Para uma variante CMake fornecida pela Microsoft, baixe os binários predefinidos mais recentes em [https://github.com/Microsoft/CMake/releases](https://github.com/Microsoft/CMake/releases).

:::moniker-end

## <a name="open-a-folder"></a>Abrir uma pasta

Para começar, escolha **Arquivo** > **Abrir** > **Pasta** no menu principal ou digite `devenv.exe <foldername>` na linha de comando. A pasta que você abrir deverá conter um arquivo CMakeLists.txt, junto com o código-fonte.
O exemplo a seguir mostra um arquivo CMakeLists.txt simples e o arquivo .cpp:

```cpp
// hello.cpp

#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Hello from Linux CMake" << std::endl;
}
```

CMakeLists.txt:

```cmd
project (hello-cmake)
add_executable(hello-cmake hello.cpp)
```

## <a name="choose-a-linux-target"></a>Escolha um destino do Linux

Assim que você abre a pasta, o Visual Studio analisa o arquivo CMakeLists.txt e especifica um destino do Windows de **x86-Debug**. Para direcionar ao Linux, altere as configurações de projeto para **Linux-Debug** ou **Linux-Release**.

Por padrão, o Visual Studio escolhe o primeiro sistema remoto na lista em **Ferramentas** > **Opções** > **Plataforma Cruzada** > **Gerenciador de Conexões**. Se nenhuma conexão remota for encontrada, será solicitado que você crie uma. Para obter mais informações, confira [Conectar-se ao seu computador Linux remoto](connect-to-your-remote-linux-computer.md).

Depois de especificar um destino de Linux, sua origem será copiada para o computador Linux. Em seguida, o CMake é executado no computador Linux para gerar o cache de CMake para o projeto.

![Gerar o cache de CMake no Linux](media/cmake-linux-1.png "Gerar o cache de CMake no Linux")

Para oferecer suporte ao IntelliSense para cabeçalhos remotos, o Visual Studio os copia automaticamente do computador Linux para um diretório no seu computador Windows local. Para obter mais informações, veja [IntelliSense para cabeçalhos remotos](configure-a-linux-project.md#remote_intellisense).

## <a name="debug-the-project"></a>Depurar o projeto

Para depurar seu código no sistema remoto, defina um ponto de interrupção, selecione o destino do CMake como o item de inicialização no menu da barra de ferramentas ao lado da configuração do projeto e escolha **&#x23f5; Iniciar** na barra de ferramentas ou pressione F5.

Para personalizar os argumentos de linha de comando do programa, clique com o botão direito do mouse no executável no **Gerenciador de Soluções** e selecione **Configurações de Depuração e de Inicialização**. Isso abre ou cria um arquivo de configuração launch.vs.json que contém as informações do seu programa. Para especificar argumentos adicionais, adicione-os na matriz JSON `args`. Para obter mais informações, confira [Projetos Open Folder para C++](../build/open-folder-projects-cpp.md) e [Configurar sessões de depuração do CMake](../build/configure-cmake-debugging-sessions.md).

## <a name="configure-cmake-settings-for-linux"></a>Definir as configurações do CMake para Linux

Um arquivo CMakeSettings.json em um projeto do CMake Linux pode especificar todas as propriedades listadas em [Personalizar configurações do CMake](../build/customize-cmake-settings.md), além de propriedades adicionais que controlam as configurações de build no computador Linux remoto. 

::: moniker range="vs-2019"

Para alterar as configurações padrão do CMake no Visual Studio 2019, na barra de ferramentas principal, abra a lista suspensa **Configuração** e escolha **Gerenciar Configurações**. 

   ![Gerenciar Configurações do CMake](../build/media/vs2019-cmake-manage-configurations.png "Lista suspensa de configurações do CMake")

Isso abre o **Editor de Configurações do CMake** que você pode usar para editar o arquivo `CMakeSettings.json` na pasta raiz do projeto. Também é possível abrir o arquivo diretamente clicando no botão **Editar JSON** no editor. Para saber mais, confira [Customize CMake Settings](../build/customize-cmake-settings.md) (Personalizar Configurações do CMake).

::: moniker-end

::: moniker range="vs-2017"

Para alterar as configurações do CMake padrão no Visual Studio 2017, escolha **CMake | Alterar as Configurações do CMake | CMakeLists.txt** no menu principal ou clique com o botão direito do mouse em CMakeSettings.txt no **Gerenciador de Soluções** e escolha **Alterar as Configurações do CMake**. O Visual Studio então cria um novo arquivo `CMakeSettings.json` na pasta raiz do projeto. Você pode abrir o arquivo usando o editor **Configurações do CMake** ou modificando o arquivo diretamente. Para obter mais informações, confira [Personalizar configurações do CMake](../build/customize-cmake-settings.md).

::: moniker-end

O exemplo a seguir mostra a configuração padrão para Linux-Debug com base no exemplo de código anterior:

```json
{
      "name": "Linux-Debug",
      "generator": "Unix Makefiles",
      "remoteMachineName": "${defaultRemoteMachineName}",
      "configurationType": "Debug",
      "remoteCMakeListsRoot": "/var/tmp/src/${workspaceHash}/${name}",
      "cmakeExecutable": "/usr/local/bin/cmake",
      "buildRoot": "${env.LOCALAPPDATA}\\CMakeBuilds\\${workspaceHash}\\build\\${name}",
      "installRoot": "${env.LOCALAPPDATA}\\CMakeBuilds\\${workspaceHash}\\install\\${name}",
      "remoteBuildRoot": "/var/tmp/build/${workspaceHash}/build/${name}",
      "remoteInstallRoot": "/var/tmp/build/${workspaceHash}/install/${name}",
      "remoteCopySources": true,
      "remoteCopySourcesOutputVerbosity": "Normal",
      "remoteCopySourcesConcurrentCopies": "10",
      "remoteCopySourcesMethod": "rsync",
      "remoteCopySourcesExclusionList": [".vs", ".git"],
      "rsyncCommandArgs" : "-t --delete --delete-excluded",
      "remoteCopyBuildOutput" : "false",
      "cmakeCommandArgs": "",
      "buildCommandArgs": "",
      "ctestCommandArgs": "",
      "inheritEnvironments": [ "linux-x64" ]
}
```
A tabela a seguir resume as configurações:

|Configuração|Descrição|
|-----------|-----------------|
|`name`|Esse valor pode ser o que você desejar.|
|`remoteMachineName`|Especifica qual sistema remoto deve ser o destino, caso você tenha mais de um. O IntelliSense está habilitado para este campo para ajudá-lo a selecionar o sistema certo.|
|`remoteCMakeListsRoot`|Especifica para que local as fontes do projeto serão copiadas no sistema remoto.|
|`remoteBuildRoot`|Especifica em que local a saída de build será gerada no sistema remoto. Essa saída também é copiada localmente para o local especificado por `buildRoot`.|
|`remoteInstallRoot` e `installRoot`| Semelhantes a `remoteBuildRoot` e `buildRoot`, exceto que eles se aplicam quando uma instalação do CMake é realizada.|
|`remoteCopySources`|Especifica se suas fontes locais são copiadas ou não para o computador remoto. Defina essa opção como false se houver muitos arquivos e você já estiver sincronizando as fontes por conta própria.|
|`remoteCopyOutputVerbosity`| Especifica o nível de detalhes da etapa de cópia, caso seja necessário diagnosticar erros.|
|`remoteCopySourcesConcurrentCopies`| Especifica quantos processos são gerados para fazer a cópia.|
|`remoteCopySourcesMethod`| Pode ser `rsync` ou `sftp`.|
|`remoteCopySourcesExclusionList`| Especifica os arquivos que você não deseja que sejam copiados para o computador remoto.|
|`rsyncCommandArgs`|Controla o método rsync de cópia.|
|`remoteCopyBuildOutput`| Controla se a saída do build remoto é copiada ou não para a pasta de build local.|

Você pode usar essas configurações opcionais para obter mais controle:

```json
{
      "remotePrebuildCommand": "",
      "remotePreGenerateCommand": "",
      "remotePostbuildCommand": "",
}
```

essas opções permitem que você execute comandos no sistema remoto antes e depois do build e antes da geração do CMake. Os valores podem ser qualquer comando válido no sistema remoto. A saída é canalizada para o Visual Studio.

::: moniker range="vs-2019"

No Visual Studio 2019, é possível editar todas essas configurações no **Editor de Configurações do CMake**.

::: moniker-end

## <a name="see-also"></a>Consulte também

[Trabalhando com Propriedades do Projeto](../build/working-with-project-properties.md)<br/>
[Projetos do CMake no Visual Studio](../build/cmake-projects-in-visual-studio.md)<br/>
[Conectar-se ao computador Linux remoto](connect-to-your-remote-linux-computer.md)<br/>
[Personalizar as configurações do CMake](../build/customize-cmake-settings.md)<br/>
[Configurar sessões de depuração do CMake](../build/configure-cmake-debugging-sessions.md)<br/>
[Implantar, executar e depurar o projeto do Linux](deploy-run-and-debug-your-linux-project.md)<br/>
[Referência de configuração predefinida do CMake](../build/cmake-predefined-configuration-reference.md)<br/>
