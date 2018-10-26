---
title: Instalar uma carga de trabalho do Linux em C++ em Visual Studio| Microsoft Docs
description: Descreve como baixar, instalar e configurar a carga de trabalho do Linux para C++ no Visual Studio.
ms.custom: ''
ms.date: 10/12/2018
ms.technology:
- cpp-linux
ms.tgt_pltfrm: Linux
ms.topic: conceptual
ms.assetid: e11b40b2-f3a4-4f06-b788-73334d58dfd9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- linux
ms.openlocfilehash: a45d216f1d6ddcef704dba40ff97f6ed71f98240
ms.sourcegitcommit: db6b2ad3195e71abfb60b62f3f015f08b0a719d0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/18/2018
ms.locfileid: "49410636"
---
# <a name="download-install-and-setup-the-linux-workload"></a>Baixar, instalar e configurar a carga de trabalho do Linux

É possível usar o Visual Studio IDE no Windows para criar, editar e depurar projetos do C++ executados em um computador físico Linux, máquina virtual ou o [Subsistema do Windows para Linux](/windows/wsl/about). Para qualquer um desses cenários, instale primeiro a carga de trabalho **Desenvolvimento para Linux com C++**.

## <a name="visual-studio-setup"></a>Configuração do Visual Studio

1. Digite "Instalador do Visual Studio" no menu de pesquisa do Windows, procure-o nos resultados dos **Aplicativos** e clique duas vezes nele. Quando o instalador é aberto, escolha **Modificar** e, em seguida, clique na guia **Cargas de trabalho**. Role para baixo até **Outros conjuntos de ferramentas** e selecione a carga de trabalho **Desenvolvimento para Linux com C++**.

   ![Carga de trabalho do Visual C++ para Desenvolvimento em Linux](media/linuxworkload.png)

1. Se você usa o CMake ou está definindo as plataformas inseridas ou IoT como destino, vá para o painel **Detalhes da instalação** à direita, em **Desenvolvimento para Linux com C++**, expanda **Componentes opcionais** e escolha os componentes de que precisa. 

1. Clique em **Modificar** para continuar a instalação.


## <a name="options-for-creating-a-linux-environment"></a>Opções para criar um ambiente Linux

Se você ainda não tem um computador Linux, é possível criar uma máquina virtual do Linux no Azure. Para obter mais informações, consulte [Início Rápido: criar uma máquina virtual Linux no portal do Azure](/azure/virtual-machines/linux/quick-create-portal).

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

   `sudo dnf install openssh-server g++ gdb gdbserver zip`

   Sua senha raiz pode ser solicitada devido ao comando sudo.  Nesse caso, insira-a e continue. Depois de concluídos, os serviços e ferramentas necessários são instalados.

1. Verifique se o serviço ssh está em execução no seu computador Linux executando:

   `sudo systemctl start sshd`

   Isso inicia o serviço e o executa em segundo plano, pronto para aceitar as conexões.

