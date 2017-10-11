---
title: Baixar, instalar e configurar a carga de trabalho do Linux | Microsoft Docs
ms.custom: 
ms.date: 11/16/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-linux
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: e11b40b2-f3a4-4f06-b788-73334d58dfd9
author: BrianPeek
ms.author: brpeek
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: 338f1bd87dbaaf4caf6a788cd45b3d011bbf40f0
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---

# <a name="download-install-and-setup-the-linux-workload"></a>Baixar, instalar e configurar a carga de trabalho do Linux

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

