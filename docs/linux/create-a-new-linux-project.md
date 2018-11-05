---
title: Criar um novo projeto do C++ Linux no Visual Studio | Microsoft Docs
ms.custom: ''
ms.date: 09/12/2018
ms.technology:
- cpp-linux
ms.tgt_pltfrm: Linux
ms.topic: conceptual
ms.assetid: 5d7c1d67-bc31-4f96-8622-2b4cf91372fd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- linux
ms.openlocfilehash: 71faf00e5acb980b9ab6f5cafa6a81bb360e7ea2
ms.sourcegitcommit: 8c2de32e96c84d0147af3cce1e89e4f28707ff12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/26/2018
ms.locfileid: "50143634"
---
# <a name="create-a-new-linux-project"></a>Criar um novo projeto do Linux

Primeiro, certifique-se de ter a **Carga de trabalho de desenvolvimento do Linux** para Visual Studio instalada. Para obter mais informações, consulte [Baixar, instalar e configurar a carga de trabalho do Linux](download-install-and-setup-the-linux-development-workload.md).

Ao criar um novo projeto C++ em Visual Studio para Linux, você tem a opção de criar um projeto do Visual Studio ou um projeto do CMake. Este tópico descreve como criar um projeto do Visual Studio. Para obter mais informações sobre criar e trabalhar com projetos existentes do CMake, consulte [Configurar um projeto do CMake Linux](cmake-linux-project.md).

Para criar um novo projeto do Linux no Visual Studio, faça o seguinte:

1. Selecione **Arquivo > Novo Projeto** no Visual Studio ou pressione **Ctrl + Shift + N**.
1. Selecione o nó **Visual C++ > Multiplataforma > Linux**, em seguida, selecione o tipo de projeto que você deseja criar, insira um Nome/Local e clique em OK.

   ![Novo projeto do Linux](media/newproject.png)

   | Tipo de Projeto | Descrição
   | ------------ | ---
   | **Intermitência (Raspberry)**           | Projeto direcionado a um dispositivo Raspberry Pi com o código de exemplo gravado para piscar um LED
   | **Aplicativo de console (Linux)** | Projeto direcionado a qualquer computador Linux com o código de exemplo gravado no texto de saída do console
   | **Projeto vazio (Linux)**       | Projeto direcionado a qualquer computador Linux sem nenhum código de exemplo gravado
   | **Projeto Makefile (Linux)**    | Projeto direcionado a qualquer computador Linux que será compilado usando um sistema de build do Makefile padrão

