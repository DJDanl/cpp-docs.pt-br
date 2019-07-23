---
title: Instalar uma carga de trabalho do Linux para C++ no Visual Studio
description: Descreve como baixar, instalar e configurar a carga de trabalho do Linux para C++ no Visual Studio.
ms.date: 06/11/2019
ms.assetid: e11b40b2-f3a4-4f06-b788-73334d58dfd9
ms.openlocfilehash: 5df7b323d202f398059e92abaeeeedbf73439fa4
ms.sourcegitcommit: 7f5b29e24e1be9b5985044a030977485fea0b50c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/17/2019
ms.locfileid: "68299801"
---
# <a name="download-install-and-set-up-the-linux-workload"></a>Baixar, instalar e configurar a carga de trabalho do Linux

::: moniker range="vs-2015"

Os projetos do Linux são permitidos no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range=">=vs-2017"

É possível usar o Visual Studio IDE no Windows para criar, editar e depurar projetos do C++ executados em um computador físico Linux, máquina virtual ou o [Subsistema do Windows para Linux](/windows/wsl/about). 

É possível trabalhar em sua base de código existente que usa CMake ou qualquer outro sistema de build sem precisar convertê-la em um projeto do Visual Studio. Se sua base de código for de multiplaforma, você poderá direcioná-la ao Windows e ao Linux de dentro do Visual Studio. Por exemplo, você pode editar, depurar e analisar seu código no Windows usando o Visual Studio e rapidamente redirecionar o projeto para Linux para fazer mais testes. Os arquivos de cabeçalho do Linux são copiados automaticamente para seu computador local, em que o Visual Studio os usa para fornecer suporte total a IntelliSense (Preenchimento de Declaração, Ir para Definição e assim por diante). 
 
Para qualquer um desses cenários, a carga de trabalho **Desenvolvimento para Linux com C++** é necessária. 

::: moniker-end

::: moniker range="vs-2019"

No Visual Studio 2019, especifique destinos separados para build e depuração. Ao ter o WSL como destino, não é mais necessário adicionar uma conexão remota nem configurar o SSH.

::: moniker-end

::: moniker range=">=vs-2017"

## <a name="visual-studio-setup"></a>Configuração do Visual Studio

1. Digite "Instalador do Visual Studio" na caixa de pesquisa do Windows:

   ![Caixa de pesquisa do Windows](media/visual-studio-installer-search.png)

2. Procure o instalador sob os resultados dos **Aplicativos** e clique duas vezes nele. Quando o instalador é aberto, escolha **Modificar** e, em seguida, clique na guia **Cargas de trabalho**. Role para baixo até **Outros conjuntos de ferramentas** e selecione a carga de trabalho **Desenvolvimento para Linux com C++** .

   ![Carga de trabalho do Visual C++ para Desenvolvimento em Linux](media/linuxworkload.png)

1. Se você tem plataformas inseridas ou o IoT como destino, acesse o painel **Detalhes da instalação** à direita, expanda **Componentes Opcionais** em **Desenvolvimento para Linux com C++** e escolha os componentes necessários. O suporte do CMake para o Linux está selecionado por padrão.

1. Clique em **Modificar** para continuar a instalação.

## <a name="options-for-creating-a-linux-environment"></a>Opções para criar um ambiente Linux

Se você ainda não tem um computador Linux, é possível criar uma máquina virtual do Linux no Azure. Para obter mais informações, confira [Início Rápido: Criar uma máquina virtual do Linux no portal do Azure](/azure/virtual-machines/linux/quick-create-portal).

No Windows 10, você pode instalar e ter sua distribuição favorita do Linux como destino no WSL (Subsistema do Windows para Linux). Para obter mais informações, confira [Guia de instalação do Subsistema do Windows para Linux para Windows 10](/windows/wsl/install-win10). O WSL é um ambiente de console conveniente, mas não é recomendado para aplicativos gráficos. 

::: moniker-end

::: moniker range="vs-2019"

## <a name="linux-setup-ubuntu-on-wsl"></a>Configuração do Linux: Ubuntu no WSL

Quando o seu alvo for o WSL, não é necessário adicionar uma conexão remota nem configurar o SSH para compilar e depurar. O **zip** e o **rsync** são necessários para a sincronização automática de cabeçalhos do Linux com o Visual Studio para o suporte ao IntelliSense. Se os aplicativos necessários ainda não estiverem presentes, você poderá instalá-los da seguinte maneira:

```bash
sudo apt-get install g++ gdb make rsync zip
```
::: moniker-end

::: moniker range=">=vs-2017"

## <a name="ubuntu-on-remote-linux-systems"></a>Ubuntu em sistemas Linux remotos

O sistema Linux de destino precisa ter o **openssh-server**, o **g++** , o **gdb** e o **gdbserver** instalados, e o daemon do SSH precisa estar em execução. O **zip** é necessário para sincronização automática de cabeçalhos remotos com seu computador local para suporte ao Intellisense. Se esses aplicativos ainda não estiverem presentes, será possível instalá-los da seguinte maneira:

1. Em um prompt de shell no seu computador Linux, execute:

   ```bash
   sudo apt-get install openssh-server g++ gdb gdbserver zip
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

O Fedora usa o instalador de pacote **dnf**. Para baixar o **g++** , o **gdb**, o **rsync** e o **zip**, execute:

   ```bash
   sudo dnf install gcc-g++ gdb rsync zip
   ```

O **zip** e o **rsync** são necessários para a sincronização automática de cabeçalhos do Linux com o Visual Studio para o suporte ao IntelliSense.

::: moniker-end

::: moniker range=">=vs-2017"

## <a name="fedora-on-remote-linux-systems"></a>Fedora em sistemas Linux remotos

O computador de destino que executa o Fedora usa o instalador do pacote **dnf**. Para baixar **openssh-server**, **g++** , **gdb**, **gdbserver** e **zip** e reiniciar o daemon do SSH, siga estas instruções:

1. Em um prompt de shell no seu computador Linux, execute:

   ```bash
   sudo dnf install openssh-server gcc-g++ gdb gdb-gdbserver zip
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
