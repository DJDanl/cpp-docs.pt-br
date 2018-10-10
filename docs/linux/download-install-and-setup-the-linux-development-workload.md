---
title: Instalar uma carga de trabalho do Linux em C++ em Visual Studio| Microsoft Docs
description: Descreve como baixar, instalar e configurar a carga de trabalho do Linux para C++ no Visual Studio.
ms.custom: ''
ms.date: 09/12/2018
ms.technology:
- cpp-linux
ms.tgt_pltfrm: Linux
ms.topic: conceptual
ms.assetid: e11b40b2-f3a4-4f06-b788-73334d58dfd9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
- linux
ms.openlocfilehash: 403f1bcd8634c3f471f34ff1266501de5bf05d52
ms.sourcegitcommit: 87d317ac62620c606464d860aaa9e375a91f4c99
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/14/2018
ms.locfileid: "45601386"
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

## <a name="linux-setup"></a>Configuração do Linux

O computador Linux de destino deve ter **openssh-server**, **g++**, **gdb** e **gdbserver** instalados e o daemon ssh deve estar em execução. O **zip** é necessário para sincronização automática de cabeçalhos remotos com seu computador local para suporte ao Intellisense. Se esses aplicativos ainda não estiverem presentes, será possível instalá-los da seguinte maneira:

1. Em um prompt de shell no seu computador Linux, execute:

   `sudo apt-get install openssh-server g++ gdb gdbserver zip`

   Sua senha raiz pode ser solicitada devido ao comando sudo.  Nesse caso, insira-a e continue.  Depois de concluído, esses serviços e ferramentas serão instaladas.

1. Verifique se o serviço ssh está em execução no seu computador Linux executando:

   `sudo service ssh start`

   Isso iniciará o serviço e o executará em segundo plano, pronto para aceitar as conexões.
