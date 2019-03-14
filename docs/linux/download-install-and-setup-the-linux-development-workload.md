---
title: Instalar uma carga de trabalho do Linux para C++ no Visual Studio
description: Descreve como baixar, instalar e configurar a carga de trabalho do Linux para C++ no Visual Studio.
ms.date: 03/05/2019
ms.assetid: e11b40b2-f3a4-4f06-b788-73334d58dfd9
ms.openlocfilehash: 74155724abb3a0e02cc27dd8a8d144f142ee4b6f
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57747716"
---
# <a name="download-install-and-set-up-the-linux-workload"></a>Baixar, instalar e configurar a carga de trabalho do Linux

É possível usar o IDE do Visual Studio 2017 no Windows para criar, editar e depurar projetos do C++ executados em um computador físico Linux, máquina virtual ou o [Subsistema do Windows para Linux](/windows/wsl/about). 

É possível trabalhar em sua base de código existente que usa CMake ou qualquer outro sistema de build sem precisar convertê-la em um projeto do Visual Studio. Se sua base de código for de multiplaforma, você poderá direcioná-la ao Windows e ao Linux de dentro do Visual Studio. Por exemplo, você pode editar, depurar e analisar seu código no Windows usando o Visual Studio e rapidamente redirecionar o projeto para Linux para fazer mais testes. Os arquivos de cabeçalho do Linux são copiados automaticamente para seu computador local, em que o Visual Studio os usa para fornecer suporte total a IntelliSense (Preenchimento de Declaração, Ir para Definição e assim por diante).
 
Para qualquer um desses cenários, a carga de trabalho **Desenvolvimento para Linux com C++** é necessária. 

## <a name="visual-studio-setup"></a>Configuração do Visual Studio

1. Digite "Instalador do Visual Studio" na caixa de pesquisa do Windows: ![caixa de pesquisa do Windows](media/visual-studio-installer-search.png)
2. Procure o instalador sob os resultados dos **Aplicativos** e clique duas vezes nele. Quando o instalador é aberto, escolha **Modificar** e, em seguida, clique na guia **Cargas de trabalho**. Role para baixo até **Outros conjuntos de ferramentas** e selecione a carga de trabalho **Desenvolvimento para Linux com C++**.

   ![Carga de trabalho do Visual C++ para Desenvolvimento em Linux](media/linuxworkload.png)

1. Se você usa o CMake ou está definindo as plataformas inseridas ou IoT como destino, vá para o painel **Detalhes da instalação** à direita, em **Desenvolvimento para Linux com C++**, expanda **Componentes opcionais** e escolha os componentes de que precisa.

    **Visual Studio 2017 versão 15.4 e posteriores.**<br/>: Quando você instala a carga de trabalho Linux C++ para Visual Studio, o suporte do CMake para o Linux é selecionado por padrão.

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

## <a name="ensure-you-have-cmake-38-on-the-remote-linux-machine"></a>Verifique se que você tem o CMake 3.8 no computador Linux remoto

Sua distribuição Linux pode ter uma versão mais antiga do CMake. O suporte ao CMake no Visual Studio requer o suporte do modo de servidor que foi apresentado no CMake 3.8. Para uma variante CMake fornecida pela Microsoft, baixe os binários predefinidos mais recentes para seu computador Linux em [https://github.com/Microsoft/CMake/releases](https://github.com/Microsoft/CMake/releases).
