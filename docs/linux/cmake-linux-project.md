---
title: Criar um projeto do CMake Linux no Visual Studio
description: Como criar um projeto CMake do Linux no Visual Studio
ms.date: 08/06/2020
ms.assetid: f8707b32-f90d-494d-ae0b-1d44425fdc25
ms.openlocfilehash: 8a960f89274fbbf235b88fdcd787ee6de8ab988b
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92921796"
---
# <a name="create-a-cmake-linux-project-in-visual-studio"></a>Criar um projeto do CMake Linux no Visual Studio

::: moniker range="msvc-140"
O suporte ao Linux está disponível no Visual Studio 2017 e posterior. Para ver a documentação dessas versões, defina a lista suspensa **versão** localizada acima do Sumário para o **Visual Studio 2017** ou **Visual Studio 2019** .
::: moniker-end

::: moniker range=">=msvc-150"

Recomendamos que você use o CMake para projetos que são de plataforma cruzada ou que serão criados em código-fonte aberto. Você pode usar projetos CMake para criar e depurar o mesmo código-fonte no Windows, no subsistema do Windows para Linux (WSL) e em sistemas remotos.

## <a name="before-you-begin"></a>Antes de começar

Primeiro, verifique se você tem a carga de trabalho do Linux do Visual Studio instalada, incluindo o componente CMake. Esse é o **desenvolvimento do Linux com** carga de trabalho do C++ no instalador do Visual Studio. Consulte [instalar a carga de trabalho do C++ Linux no Visual Studio](download-install-and-setup-the-linux-development-workload.md) se você não tiver certeza de que o está instalado.

Além disso, verifique se os itens a seguir estão instalados no computador remoto:

- gcc
- gdb
- rsync
- zip
- Ninja-Build (Visual Studio 2019 ou superior)
::: moniker-end

::: moniker range="msvc-150"
O suporte do CMake no Visual Studio requer suporte ao modo de servidor introduzido no CMake 3,8. Para obter uma variante CMake fornecida pela Microsoft, baixe os binários predefinidos mais recentes em [https://github.com/Microsoft/CMake/releases](https://github.com/Microsoft/CMake/releases) .

Os binários são instalados no `~/.vs/cmake` . Depois de implantar os binários, seu projeto é regenerado automaticamente. Se o CMake especificado pelo `cmakeExecutable` campo em *CMakeSettings.jsem* for inválido (ele não existe ou é uma versão sem suporte) e os binários pré-criados estiverem presentes, o Visual Studio ignorará `cmakeExecutable` e usará os binários pré-criados.

O Visual Studio 2017 não pode criar um projeto CMake do zero, mas você pode abrir uma pasta que contém um projeto CMake existente, conforme descrito na próxima seção.
::: moniker-end

::: moniker range=">=msvc-160"
Você pode usar o Visual Studio 2019 para compilar e depurar em um sistema Linux remoto ou WSL, e CMake será invocado nesse sistema. O CMake versão 3,14 ou posterior deve ser instalado no computador de destino.

Verifique se o computador de destino tem uma versão recente do CMake. Geralmente, a versão oferecida pelo Gerenciador de pacotes padrão de uma distribuição não é recente o suficiente para dar suporte a todos os recursos exigidos pelo Visual Studio. O Visual Studio 2019 detecta se uma versão recente do CMake está instalada no sistema Linux. Se nenhum for encontrado, o Visual Studio mostrará uma barra de informações na parte superior do painel do editor. Ele oferece para instalar o CMake para você do [https://github.com/Microsoft/CMake/releases](https://github.com/Microsoft/CMake/releases) .

Com o Visual Studio 2019, você pode criar um projeto CMake do zero ou abrir um projeto CMake existente. Para criar um novo projeto CMake, siga as instruções abaixo. Ou pule para [abrir uma pasta de projeto CMake](#open-a-cmake-project-folder) se você já tiver um projeto CMake.

## <a name="create-a-new-linux-cmake-project"></a>Criar um novo projeto CMake do Linux

Para criar um novo projeto CMake do Linux no Visual Studio 2019:

1. Selecione **Arquivo > Novo Projeto** no Visual Studio ou pressione **Ctrl + Shift + N** .
1. Defina a **Linguagem** como **C++** e pesquise "CMake". Em seguida, escolha **Avançar** . Insira um **Nome** e uma **Localização** e escolha **Criar** .

Como alternativa, você pode abrir seu próprio projeto CMake no Visual Studio 2019. A seção a seguir explica como.

O Visual Studio cria um arquivo de *CMakeLists.txt* mínimo com apenas o nome do executável e a versão mínima do cmake necessária. Você pode editar manualmente esse arquivo da maneira que desejar. O Visual Studio nunca substituirá suas alterações.

Para ajudá-lo a fazer sentido, editar e criar seus scripts do CMake no Visual Studio 2019, consulte os seguintes recursos:

- [Documentação no editor para CMake no Visual Studio](https://devblogs.microsoft.com/cppblog/in-editor-documentation-for-cmake-in-visual-studio/)
- [Navegação de código para scripts CMake](https://devblogs.microsoft.com/cppblog/code-navigation-for-cmake-scripts/)
- [Adicione, remova e renomeie facilmente arquivos e destinos em projetos CMake](https://devblogs.microsoft.com/cppblog/easily-add-remove-and-rename-files-and-targets-in-cmake-projects/)
::: moniker-end

::: moniker range=">=msvc-150"

## <a name="open-a-cmake-project-folder"></a>Abrir uma pasta de projeto do CMake

Quando você abre uma pasta que contém um projeto CMake existente, o Visual Studio usa variáveis no cache CMake para configurar automaticamente o IntelliSense e as compilações. A configuração local e as configurações de depuração são armazenadas em arquivos JSON. Opcionalmente, você pode compartilhar esses arquivos com outras pessoas que estejam usando o Visual Studio.

O Visual Studio não modifica os arquivos de *CMakeLists.txt* . Isso permite que outras pessoas trabalhem no mesmo projeto para continuar usando suas ferramentas existentes. O Visual Studio gera novamente o cache quando você salva as edições no *CMakeLists.txt* , ou em alguns casos, para *CMakeSettings.jsno* . Se você estiver usando uma configuração de **cache existente** , o Visual Studio não modificará o cache.

Para obter informações gerais sobre o suporte do CMake no Visual Studio, confira [Projetos CMake no Visual Studio](../build/cmake-projects-in-visual-studio.md). Leia isso antes de continuar aqui.

Para começar, escolha **arquivo**  >  **abrir**  >  **pasta** no menu principal ou digite outro tipo `devenv.exe <foldername>` em uma janela de [prompt de comando do desenvolvedor](../build/building-on-the-command-line.md) . A pasta que você abrir deve ter um arquivo *CMakeLists.txt* nele, junto com o código-fonte.

O exemplo a seguir mostra um arquivo *CMakeLists.txt* simples e arquivo. cpp:

```cpp
// hello.cpp

#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Hello from Linux CMake" << std::endl;
}
```

*CMakeLists.txt* :

```txt
cmake_minimum_required(VERSION 3.8)
project (hello-cmake)
add_executable(hello-cmake hello.cpp)
```

## <a name="next-steps"></a>Próximas etapas

[Configurar um projeto do Linux CMake](cmake-linux-configure.md)

## <a name="see-also"></a>Veja também

[Projetos do CMake no Visual Studio](../build/cmake-projects-in-visual-studio.md)<br/>
::: moniker-end
