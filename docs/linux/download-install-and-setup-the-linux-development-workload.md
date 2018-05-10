---
title: Baixar, instalar e configurar a carga de trabalho do Linux | Microsoft Docs
ms.custom: ''
ms.date: 11/16/2016
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
ms.openlocfilehash: 1d28f0db0ff91dbdb08c9ca88dfe197e8942a7f4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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
