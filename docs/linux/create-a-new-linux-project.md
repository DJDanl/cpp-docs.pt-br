---
title: Criar um novo projeto do C++ Linux no Visual Studio
ms.date: 09/12/2018
ms.assetid: 5d7c1d67-bc31-4f96-8622-2b4cf91372fd
ms.openlocfilehash: bd5ab1d2bc1077f366082bf8767f8f690173ac8b
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57745164"
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
