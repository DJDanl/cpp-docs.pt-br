---
title: Instalar uma carga de trabalho do Linux para C++ no Visual Studio
description: Descreve como baixar, instalar e configurar a carga de trabalho do Linux para C++ no Visual Studio.
ms.date: 06/11/2019
ms.assetid: e11b40b2-f3a4-4f06-b788-73334d58dfd9
ms.openlocfilehash: 8e10521ab35f3d85ced8bffd771b4e101d4d4fe6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364335"
---
# <a name="download-install-and-set-up-the-linux-workload"></a>Baixar, instalar e configurar a carga de trabalho do Linux

::: moniker range="vs-2015"

Os projetos do Linux são permitidos no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range=">=vs-2017"

Você pode usar o Visual Studio IDE no Windows para criar, editar e depurar projetos C++ que são executados em um sistema Linux remoto, máquina virtual ou o [Subsistema Windows para Linux](/windows/wsl/about).

Você pode trabalhar em sua base de código existente que usa CMake sem ter que convertê-la em um projeto do Visual Studio. Se sua base de código for de multiplaforma, você poderá direcioná-la ao Windows e ao Linux de dentro do Visual Studio. Por exemplo, você pode editar, construir e depurar seu código no Windows usando o Visual Studio e, em seguida, redirecionar rapidamente o projeto para Linux para construir e depurar em um ambiente Linux. Os arquivos de cabeçalho Linux são automaticamente copiados para sua máquina local, onde o Visual Studio os usa para fornecer suporte total ao IntelliSense (Conclusão de declaração, ir para definição e assim por diante).

Para qualquer um desses cenários, a carga de trabalho **Desenvolvimento para Linux com C++** é necessária.

::: moniker-end

::: moniker range=">=vs-2017"

## <a name="visual-studio-setup"></a>Configuração do Visual Studio

1. Digite "Instalador do Visual Studio" na caixa de pesquisa do Windows:

   ![Caixa de pesquisa do Windows](media/visual-studio-installer-search.png)

1. Procure o instalador sob os resultados dos **Aplicativos** e clique duas vezes nele. Quando o instalador for aberto, escolha **Modificar**e clique na guia **Cargas de trabalho.** Role até Outros **conjuntos de ferramentas** e selecione o desenvolvimento do Linux com a carga de trabalho **C++.**

   ![Carga de trabalho do Visual C++ para Desenvolvimento em Linux](media/linuxworkload.png)

1. Se você estiver mirando plataformas IoT ou incorporadas, vá para o painel **de detalhes de instalação** à direita. Em **desenvolvimento Linux com C++,** expanda **componentes opcionais**e escolha os componentes necessários. O suporte do CMake para o Linux está selecionado por padrão.

1. Clique em **Modificar** para continuar a instalação.

## <a name="options-for-creating-a-linux-environment"></a>Opções para criar um ambiente Linux

Se você ainda não tem um computador Linux, é possível criar uma máquina virtual do Linux no Azure. Para obter mais informações, consulte [Início Rápido: criar uma máquina virtual Linux no portal do Azure](/azure/virtual-machines/linux/quick-create-portal).

No Windows 10, você pode instalar e ter sua distribuição favorita do Linux como destino no WSL (Subsistema do Windows para Linux). Para obter mais informações, confira [Guia de instalação do Subsistema do Windows para Linux para Windows 10](/windows/wsl/install-win10). Se você não conseguir acessar a Windows Store, você pode [baixar manualmente os pacotes de distro WSL](/windows/wsl/install-manual). WSL é um ambiente de console conveniente, mas não é recomendado para aplicações gráficas.

::: moniker-end

::: moniker range="vs-2019"

Os projetos Linux no Visual Studio exigem que as seguintes dependências sejam instaladas no seu sistema Linux remoto ou WSL:

- **Um compilador** - Visual Studio 2019 tem suporte fora da caixa para GCC e [Clang](/cpp/build/clang-support-cmake?view=vs-2019).
- **gdb** - O Visual Studio lança automaticamente o gdb no sistema Linux, e usa o front-end do depurador Visual Studio para fornecer uma experiência de depuração de fidelidade total no Linux.
- **rsync** e **zip** - a inclusão de rsync e zip permite que o Visual Studio extraia arquivos de cabeçalho do seu sistema Linux para o sistema de arquivos Windows para uso pelo IntelliSense.
- **Fazer**
- **openssh-server** (somente sistemas Linux remotos) - O Visual Studio se conecta a sistemas Linux remotos por meio de uma conexão SSH segura.
- **CMake** (somente projetos CMake) - Você pode instalar [binários CMake vinculados estáticamente](https://github.com/microsoft/CMake/releases)da Microsoft para Linux .
- **ninja-build** (somente projetos CMake)- [Ninja](https://ninja-build.org/) é o gerador padrão para configurações Linux e WSL no Visual Studio 2019 versão 16.6 ou posterior.

Os seguintes comandos assumem que você está usando g++ em vez de gíria.

::: moniker-end

::: moniker range="vs-2017"

Os projetos Linux no Visual Studio exigem que as seguintes dependências sejam instaladas no seu sistema Linux remoto ou WSL:

- **gCC** - Visual Studio 2017 tem suporte fora da caixa para GCC.
- **gdb** - O Visual Studio lança automaticamente o gdb no sistema Linux e usa o front-end do depurador Visual Studio para fornecer uma experiência de depuração de fidelidade total no Linux.
- **rsync** e **zip** - a inclusão de rsync e zip permite que o Visual Studio extraia arquivos de cabeçalho do seu sistema Linux para o sistema de arquivos Windows para usar no IntelliSense.
- **Fazer**
- **abre o servidorsh** - O Visual Studio conecta-se a sistemas Linux remotos por meio de uma conexão SSH segura.
- **CMake** (somente projetos CMake) - Você pode instalar [binários CMake vinculados estáticamente](https://github.com/microsoft/CMake/releases)da Microsoft para Linux .

::: moniker-end

::: moniker range="vs-2019"

## <a name="linux-setup-ubuntu-on-wsl"></a>Configuração do Linux: Ubuntu na WSL

Quando o seu alvo for o WSL, não é necessário adicionar uma conexão remota nem configurar o SSH para compilar e depurar. O **zip** e o **rsync** são necessários para a sincronização automática de cabeçalhos do Linux com o Visual Studio para o suporte ao IntelliSense. Se os aplicativos necessários ainda não estiverem presentes, você pode instalá-los da seguinte forma. **a compilação ninja** é necessária apenas para projetos CMake.

```bash
sudo apt-get install g++ gdb make ninja-build rsync zip
```

::: moniker-end

::: moniker range=">=vs-2017"

## <a name="ubuntu-on-remote-linux-systems"></a>Ubuntu em sistemas Linux remotos

O sistema Linux de destino deve ter **openssh-server,** **g++**, **gdb,** **ninja-build** (somente projetos CMake), e **fazer** instalado, e o daemon ssh deve estar sendo executado. **zip** e **rsync** são necessários para sincronização automática de cabeçalhos remotos com sua máquina local para suporte intellisense. Se esses aplicativos ainda não estiverem presentes, será possível instalá-los da seguinte maneira:

1. Em um prompt de shell no seu computador Linux, execute:

   ```bash
   sudo apt-get install openssh-server g++ gdb make ninja-build rsync zip
   ```

   Sua senha raiz pode ser solicitada devido ao comando sudo.  Nesse caso, insira-a e continue. Depois de concluídos, os serviços e ferramentas necessários são instalados.

1. Verifique se o serviço ssh está em execução no seu computador Linux executando:

   ```bash
   sudo service ssh start
   ```

   Isso inicia o serviço e o executa em segundo plano, pronto para aceitar as conexões.

::: moniker-end

::: moniker range="vs-2019"

## <a name="fedora-on-wsl"></a>Fedora no WSL

O Fedora usa o instalador de pacote **dnf**. Para baixar **g++**, **gdb**, **make**, **rsync**, **ninja-build**, e **zip**, execute:

   ```bash
   sudo dnf install gcc-g++ gdb rsync ninja-build make zip
   ```

O **zip** e o **rsync** são necessários para a sincronização automática de cabeçalhos do Linux com o Visual Studio para o suporte ao IntelliSense. **a compilação ninja** é necessária apenas para projetos CMake.

::: moniker-end

::: moniker range=">=vs-2017"

## <a name="fedora-on-remote-linux-systems"></a>Fedora em sistemas Linux remotos

O computador de destino que executa o Fedora usa o instalador do pacote **dnf**. Para baixar **openssh-server**, **g++**, **gdb**, **make**, **ninja-build**, **rsync**, e **zip**, e reiniciar o daemon ssh, siga estas instruções. **a compilação ninja** é necessária apenas para projetos CMake.

1. Em um prompt de shell no seu computador Linux, execute:

   ```bash
   sudo dnf install openssh-server gcc-g++ gdb ninja-build make rsync zip
   ```

   Sua senha raiz pode ser solicitada devido ao comando sudo.  Nesse caso, insira-a e continue. Depois de concluídos, os serviços e ferramentas necessários são instalados.

1. Verifique se o serviço ssh está em execução no seu computador Linux executando:

   ```bash
   sudo systemctl start sshd
   ```

   Isso inicia o serviço e o executa em segundo plano, pronto para aceitar as conexões.

::: moniker-end

::: moniker range="vs-2015"

O suporte ao desenvolvimento para Linux C++ está disponível no Visual Studio 2017 e posterior.

::: moniker-end

## <a name="next-steps"></a>Próximas etapas

Agora você está pronto para criar ou abrir um projeto do Linux e configurá-lo para ser executado no sistema de destino. Para obter mais informações, consulte:

- [Criar um novo projeto do Linux](create-a-new-linux-project.md)
- [Configurar um projeto do Linux CMake](cmake-linux-project.md)
