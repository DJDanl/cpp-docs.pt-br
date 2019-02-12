---
title: Instalar uma carga de trabalho do Linux para C++ no Visual Studio
description: Descreve como baixar, instalar e configurar a carga de trabalho do Linux para C++ no Visual Studio.
ms.date: 02/06/2019
ms.assetid: e11b40b2-f3a4-4f06-b788-73334d58dfd9
ms.openlocfilehash: c01c8ddeeb8439a7610c0f6c7c11b608ab3675d8
ms.sourcegitcommit: 63c072f5e941989636f5a2b13800b68bb7129931
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/06/2019
ms.locfileid: "55763876"
---
# <a name="download-install-and-setup-the-linux-workload"></a>Baixar, instalar e configurar a carga de trabalho do Linux

É possível usar o Visual Studio IDE no Windows para criar, editar e depurar projetos do C++ executados em um computador físico Linux, máquina virtual ou o [Subsistema do Windows para Linux](/windows/wsl/about). Para qualquer um desses cenários, instale primeiro a carga de trabalho **Desenvolvimento para Linux com C++**.

## <a name="visual-studio-setup"></a>Configuração do Visual Studio

1. Digite "Instalador do Visual Studio" na caixa de pesquisa do Windows: ![caixa de pesquisa do Windows](media/visual-studio-installer-search.png)
2. Procure o instalador sob os resultados dos **Aplicativos** e clique duas vezes nele. Quando o instalador é aberto, escolha **Modificar** e, em seguida, clique na guia **Cargas de trabalho**. Role para baixo até **Outros conjuntos de ferramentas** e selecione a carga de trabalho **Desenvolvimento para Linux com C++**.

   ![Carga de trabalho do Visual C++ para Desenvolvimento em Linux](media/linuxworkload.png)

1. Se você usa o CMake ou está definindo as plataformas inseridas ou IoT como destino, vá para o painel **Detalhes da instalação** à direita, em **Desenvolvimento para Linux com C++**, expanda **Componentes opcionais** e escolha os componentes de que precisa.

1. Clique em **Modificar** para continuar a instalação.

## <a name="options-for-creating-a-linux-environment"></a>Opções para criar um ambiente Linux

Se você ainda não tem um computador Linux, é possível criar uma máquina virtual do Linux no Azure. Para obter mais informações, confira [Início Rápido: Criar uma máquina virtual do Linux no portal do Azure](/azure/virtual-machines/linux/quick-create-portal).

Outra opção, no Windows 10, é ativar o Subsistema do Windows para Linux. Para obter informações, consulte [Guia de Instalação do Windows 10](/windows/wsl/install-win10).

## <a name="linux-setup-ubuntu"></a>Configuração do Linux: Ubuntu

O computador Linux de destino deve ter **openssh-server**, **g++**, **gdb** e **gdbserver** instalados e o daemon ssh deve estar em execução. O **zip** é necessário para sincronização automática de cabeçalhos remotos com seu computador local para suporte ao Intellisense. Se esses aplicativos ainda não estiverem presentes, será possível instalá-los da seguinte maneira:

1. Em um prompt de shell no seu computador Linux, execute:

   `sudo apt-get install openssh-server g++ gdb gdbserver zip`

   Sua senha raiz pode ser solicitada devido ao comando sudo.  Nesse caso, insira-a e continue. Depois de concluídos, os serviços e ferramentas necessários são instalados.

1. Verifique se o serviço ssh está em execução no seu computador Linux executando:

   `sudo service ssh start`

   Isso inicia o serviço e o executa em segundo plano, pronto para aceitar as conexões.

## <a name="linux-setup-fedora"></a>Configuração do Linux: Fedora

O computador de destino que executa o Fedora usa o instalador do pacote **dnf**. Para baixar **openssh-server**, **g++**, **gdb**, **gdbserver** e **zip** e reiniciar o daemon do SSH, siga estas instruções:

1. Em um prompt de shell no seu computador Linux, execute:

   `sudo dnf install openssh-server gcc-g++ gdb gdb-gdbserver zip`

   Sua senha raiz pode ser solicitada devido ao comando sudo.  Nesse caso, insira-a e continue. Depois de concluídos, os serviços e ferramentas necessários são instalados.

1. Verifique se o serviço ssh está em execução no seu computador Linux executando:

   `sudo systemctl start sshd`

   Isso inicia o serviço e o executa em segundo plano, pronto para aceitar as conexões.

