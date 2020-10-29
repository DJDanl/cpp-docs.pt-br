---
title: Instalar uma carga de trabalho do Linux para C++ no Visual Studio
description: Como baixar, instalar e configurar a carga de trabalho do Linux para C++ no Visual Studio.
ms.date: 05/03/2020
ms.assetid: e11b40b2-f3a4-4f06-b788-73334d58dfd9
ms.openlocfilehash: 9d0c832ec383286b5f89b8ed1474e69d72b5cb98
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92921601"
---
# <a name="download-install-and-set-up-the-linux-workload"></a>Baixar, instalar e configurar a carga de trabalho do Linux

::: moniker range="msvc-140"

Os projetos do Linux são permitidos no Visual Studio 2017 e posterior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end

::: moniker range=">=msvc-150"

Você pode usar o Visual Studio IDE no Windows para criar, editar e depurar projetos do C++ que são executados em um sistema Linux remoto, máquina virtual ou o [subsistema do Windows para Linux](/windows/wsl/about).

Você pode trabalhar em sua base de código existente que usa CMake sem precisar convertê-la em um projeto do Visual Studio. Se sua base de código for de multiplaforma, você poderá direcioná-la ao Windows e ao Linux de dentro do Visual Studio. Por exemplo, você pode editar, compilar e depurar seu código no Windows usando o Visual Studio. Em seguida, redirecione rapidamente o projeto para Linux para compilar e depurar em um ambiente Linux. Os arquivos de cabeçalho do Linux são copiados automaticamente para o computador local. O Visual Studio os usa para fornecer suporte total ao IntelliSense (conclusão da instrução, ir para definição e assim por diante).

Para qualquer um desses cenários, a carga de trabalho **Desenvolvimento para Linux com C++** é necessária.

::: moniker-end

::: moniker range=">=msvc-150"

## <a name="visual-studio-setup"></a>Configuração do Visual Studio

1. Digite "Instalador do Visual Studio" na caixa de pesquisa do Windows:

   ![Caixa de pesquisa do Windows](media/visual-studio-installer-search.png)

1. Procure o instalador sob os resultados dos **Aplicativos** e clique duas vezes nele. Quando o instalador for aberto, escolha **Modificar** e, em seguida, clique na guia **cargas de trabalho** . Role para baixo até **outros conjuntos de ferramentas** e selecione o **desenvolvimento do Linux com** carga de trabalho do C++.

   ![Carga de trabalho do Visual C++ para Desenvolvimento em Linux](media/linuxworkload.png)

1. Se você estiver direcionando para IoT ou plataformas incorporadas, vá para o painel **detalhes da instalação** à direita. Em **desenvolvimento Linux com C++** , expanda **componentes opcionais** e escolha os componentes de que você precisa. O suporte do CMake para o Linux está selecionado por padrão.

1. Clique em **Modificar** para continuar a instalação.

## <a name="options-for-creating-a-linux-environment"></a>Opções para criar um ambiente Linux

Se você ainda não tem um computador Linux, é possível criar uma máquina virtual do Linux no Azure. Para obter mais informações, consulte [Início Rápido: criar uma máquina virtual Linux no portal do Azure](/azure/virtual-machines/linux/quick-create-portal).

No Windows 10, você pode instalar e ter sua distribuição favorita do Linux como destino no WSL (Subsistema do Windows para Linux). Para obter mais informações, confira [Guia de instalação do Subsistema do Windows para Linux para Windows 10](/windows/wsl/install-win10). Se não for possível acessar a Windows Store, você poderá [baixar manualmente os pacotes do WSL distribuição](/windows/wsl/install-manual). O WSL é um ambiente de console conveniente, mas não é recomendado para aplicativos gráficos.

::: moniker-end

::: moniker range="msvc-160"

Os projetos do Linux no Visual Studio exigem que as seguintes dependências sejam instaladas em seu sistema Linux remoto ou WSL:

- **Um compilador-o** Visual Studio 2019 tem suporte completo para gcc e [Clang](../build/clang-support-cmake.md).
- **gdb** – o Visual Studio inicia automaticamente o gdb no sistema Linux e usa o front-end do depurador do Visual Studio para fornecer uma experiência de depuração de fidelidade total no Linux.
- **rsync** e **zip** -a inclusão de rsync e zip permite que o Visual Studio Extraia Arquivos de cabeçalho do seu sistema Linux para o sistema de arquivos do Windows para uso pelo IntelliSense.
- **make**
- **OpenSSH-Server** (somente sistemas Linux remotos)-o Visual Studio se conecta a sistemas Linux remotos por meio de uma conexão SSH segura.
- **CMake** (somente projetos CMake) – você pode instalar [binários CMake vinculados estaticamente da Microsoft para Linux](https://github.com/microsoft/CMake/releases).
- **ninja-Build** (somente projetos CMake)- [ninja](https://ninja-build.org/) é o gerador padrão para as configurações do Linux e do WSL no Visual Studio 2019 versão 16,6 ou posterior.

Os comandos a seguir pressupõem que você esteja usando g + + em vez de Clang.

::: moniker-end

::: moniker range="msvc-150"

Os projetos do Linux no Visual Studio exigem que as seguintes dependências sejam instaladas em seu sistema Linux remoto ou WSL:

- **gcc** -o Visual Studio 2017 tem suporte completo para gcc.
- **gdb** – o Visual Studio inicia automaticamente o gdb no sistema Linux e usa o front-end do depurador do Visual Studio para fornecer uma experiência de depuração de fidelidade total no Linux.
- **rsync** e **zip** -a inclusão de rsync e zip permite que o Visual Studio Extraia Arquivos de cabeçalho do seu sistema Linux para o sistema de arquivos do Windows a ser usado para o IntelliSense.
- **make**
- **OpenSSH-Server** -o Visual Studio se conecta a sistemas Linux remotos por meio de uma conexão SSH segura.
- **CMake** (somente projetos CMake) – você pode instalar [binários CMake vinculados estaticamente da Microsoft para Linux](https://github.com/microsoft/CMake/releases).

::: moniker-end

::: moniker range="msvc-160"

## <a name="linux-setup-ubuntu-on-wsl"></a>Instalação do Linux: Ubuntu no WSL

Quando você está direcionando para o WSL, não há necessidade de adicionar uma conexão remota ou configurar o SSH para compilar e depurar. O **zip** e o **rsync** são necessários para a sincronização automática de cabeçalhos do Linux com o Visual Studio para o suporte ao IntelliSense. **ninja-Build** só é necessário para projetos CMake. Se os aplicativos necessários ainda não estiverem presentes, você poderá instalá-los usando este comando:

```bash
sudo apt-get install g++ gdb make ninja-build rsync zip
```

::: moniker-end

::: moniker range=">=msvc-150"

## <a name="ubuntu-on-remote-linux-systems"></a>Ubuntu em sistemas Linux remotos

O sistema Linux de destino deve ter o **OpenSSH-Server** , o **g + +** , o **gdb** e o **Make** instalado. **ninja-Build** é necessário apenas para projetos CMake. O daemon **SSH** deve estar em execução. o **zip** e o **rsync** são necessários para a sincronização automática de cabeçalhos remotos com seu computador local para suporte ao IntelliSense. Se esses aplicativos ainda não estiverem presentes, você poderá instalá-los da seguinte maneira:

1. Em um prompt de shell no seu computador Linux, execute:

   ```bash
   sudo apt-get install openssh-server g++ gdb make ninja-build rsync zip
   ```

   Você pode ser solicitado a fornecer sua senha raiz para executar o comando sudo. Nesse caso, insira-a e continue. Depois de concluídos, os serviços e ferramentas necessários são instalados.

1. Verifique se o serviço ssh está em execução no seu computador Linux executando:

   ```bash
   sudo service ssh start
   ```

   Esse comando inicia o serviço e o executa em segundo plano, pronto para aceitar conexões.

::: moniker-end

::: moniker range="msvc-160"

## <a name="fedora-on-wsl"></a>Fedora no WSL

O Fedora usa o instalador de pacote **dnf** . Para baixar o **g + +** , o **gdb** , **Make** , **rsync** , **ninja-Build** e **zip** , execute:

   ```bash
   sudo dnf install gcc-g++ gdb rsync ninja-build make zip
   ```

O **zip** e o **rsync** são necessários para a sincronização automática de cabeçalhos do Linux com o Visual Studio para o suporte ao IntelliSense. **ninja-Build** só é necessário para projetos CMake.

::: moniker-end

::: moniker range=">=msvc-150"

## <a name="fedora-on-remote-linux-systems"></a>Fedora em sistemas Linux remotos

O computador de destino que executa o Fedora usa o instalador do pacote **dnf** . Para baixar o **OpenSSH-Server** , **g + +** , **gdb** , **Make** , **ninja-Build** , **rsync** e **zip** , e reinicie o daemon SSH, siga estas instruções. **ninja-Build** só é necessário para projetos CMake.

1. Em um prompt de shell no seu computador Linux, execute:

   ```bash
   sudo dnf install openssh-server gcc-g++ gdb ninja-build make rsync zip
   ```

   Você pode ser solicitado a fornecer sua senha raiz para executar o comando sudo. Nesse caso, insira-a e continue. Depois de concluídos, os serviços e ferramentas necessários são instalados.

1. Verifique se o serviço ssh está em execução no seu computador Linux executando:

   ```bash
   sudo systemctl start sshd
   ```

   Esse comando inicia o serviço e o executa em segundo plano, pronto para aceitar conexões.

## <a name="next-steps"></a>Próximas etapas

Agora você está pronto para criar ou abrir um projeto do Linux e configurá-lo para ser executado no sistema de destino. Para obter mais informações, consulte:

- [Criar um novo projeto do C++ do MSBuild do Linux](create-a-new-linux-project.md)
- [Configurar um projeto do Linux CMake](cmake-linux-project.md)

::: moniker-end
