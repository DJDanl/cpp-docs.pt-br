---
title: Instalar uma carga de trabalho do Linux em C++ em Visual Studio| Microsoft Docs
description: Descreve como baixar, instalar e configurar a carga de trabalho do Linux para C++ no Visual Studio.
ms.custom: ''
ms.date: 07/20/2018
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
ms.openlocfilehash: e33b9ac72ca7691ccbb80a9a30349d3a1e31e194
ms.sourcegitcommit: 7eadb968405bcb92ffa505e3ad8ac73483e59685
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/23/2018
ms.locfileid: "39207553"
---
# <a name="download-install-and-setup-the-linux-workload"></a>Baixar, instalar e configurar a carga de trabalho do Linux

Para usar o IDE do Visual Studio para criar e depurar projetos do C++ no Linux, você deve instalar a carga de trabalho de **Desenvolvimento do Linux com C++**.

## <a name="visual-studio-setup"></a>Configuração do Visual Studio
1. Inicie o instalador do Visual Studio e selecione a carga de trabalho **Desenvolvimento Linux com C++**.

   ![Visual C++ para extensão de desenvolvimento do Linux](media/linuxworkload.png)

2. Clique em **Instalar** para continuar a instalação.

## <a name="linux-setup"></a>Configuração do Linux
O computador Linux de destino deve ter **openssh-server**, **g++**, **gdb** e **gdbserver** instalados e o daemon ssh deve estar em execução.  Se eles ainda não estiverem presentes, você poderá instalá-los da seguinte maneira:
 
1. Em um prompt de shell no seu computador Linux, execute:

   `sudo apt-get install openssh-server g++ gdb gdbserver`

   Sua senha raiz pode ser solicitada devido ao comando sudo.  Nesse caso, insira-a e continue.  Depois de concluído, esses serviços e ferramentas serão instaladas.

1. Verifique se o serviço ssh está em execução no seu computador Linux executando:

   `sudo service ssh start`
   
   Isso iniciará o serviço e o executará em segundo plano, pronto para aceitar as conexões.
