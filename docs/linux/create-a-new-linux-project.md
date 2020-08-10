---
title: Criar um projeto C++ do MSBuild do Linux no Visual Studio
ms.date: 08/04/2020
description: Crie um novo projeto do Linux baseado em MSBuild no Visual Studio.
ms.assetid: 5d7c1d67-bc31-4f96-8622-2b4cf91372fd
ms.openlocfilehash: 86d8b8fd2abe8970b5146d4ab08dc4251b5562d5
ms.sourcegitcommit: 2034f8e744a8b36cff8b15e9a5cfe684afebadfb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/10/2020
ms.locfileid: "88043844"
---
# <a name="create-a-linux-msbuild-c-project-in-visual-studio"></a>Criar um projeto C++ do MSBuild do Linux no Visual Studio

::: moniker range="vs-2015"

Os projetos do Linux estão disponíveis no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range="vs-2017"

Primeiro, certifique-se de ter a **Carga de trabalho de desenvolvimento do Linux** para Visual Studio instalada. Para obter mais informações, consulte [Baixar, instalar e configurar a carga de trabalho do Linux](download-install-and-setup-the-linux-development-workload.md).

Para a compilação de plataforma cruzada, é recomendável usar CMake. O suporte a CMake é mais completo no Visual Studio 2019. Se CMake não for uma opção e você tiver uma solução existente do Windows Visual Studio que você deseja estender para compilar para Linux, você poderá adicionar um projeto do Visual Studio Linux à solução do Windows, juntamente com um projeto de **itens compartilhados** . Coloque o código que é compartilhado entre as duas plataformas no projeto de itens compartilhados e adicione uma referência a esse projeto dos projetos do Windows e do Linux.

## <a name="to-create-a-new-linux-project"></a>Para criar um projeto do Linux

Para criar um novo projeto do Linux no Visual Studio 2017, siga estas etapas:

1. Selecione **Arquivo > Novo Projeto** no Visual Studio ou pressione **Ctrl + Shift + N**.
1. Selecione o nó **Visual C++ > Multiplataforma > Linux** e, em seguida, selecione o tipo de projeto a ser criado. Insira um **Nome** e **Localização** e escolha **OK**.

   ![Novo projeto do Linux](media/newproject.png)

   | Tipo de Projeto | Descrição |
   | ------------ | --- |
   | **Intermitência (Raspberry)**           | Projeto direcionado a um dispositivo Raspberry Pi, com o código de exemplo que pisca um LED |
   | **Aplicativo de console (Linux)** | Projeto direcionado a qualquer computador Linux, com o código de exemplo que produz um texto no console |
   | **Projeto vazio (Linux)**       | Projeto direcionado a qualquer computador Linux, sem nenhum código de exemplo |
   | **Projeto Makefile (Linux)**    | Projeto direcionado a qualquer computador Linux, compilado usando um sistema de build padrão do Makefile |

## <a name="next-steps"></a>Próximas etapas

[Configurar um projeto do MSBuild para Linux](configure-a-linux-project.md)

::: moniker-end

::: moniker range="vs-2019"

Primeiro, certifique-se de ter a **Carga de trabalho de desenvolvimento do Linux** para Visual Studio instalada. Para obter mais informações, consulte [baixar, instalar e configurar a carga de trabalho do Linux](download-install-and-setup-the-linux-development-workload.md).

Ao criar um projeto C++ para o Linux no Visual Studio, você pode optar por criar um projeto do Visual Studio ou um projeto do CMake. Este artigo descreve como criar um projeto do Visual Studio. Em geral, para novos projetos que podem incluir código-fonte aberto ou que você pretende compilar para desenvolvimento de plataforma cruzada, recomendamos que você use o CMake com o Visual Studio. Com um projeto CMake, você pode criar e depurar o mesmo projeto no Windows e no Linux. Para obter mais informações, consulte [criar e configurar um projeto CMake do Linux](cmake-linux-project.md).

Se você tiver uma solução existente do Windows Visual Studio que deseja estender para compilar para Linux e CMake não for uma opção, você poderá adicionar um projeto do Visual Studio Linux à solução do Windows, juntamente com um projeto de **itens compartilhados** . Coloque o código que é compartilhado entre as duas plataformas no projeto de itens compartilhados e adicione uma referência a esse projeto dos projetos do Windows e do Linux.

## <a name="to-create-a-new-linux-project"></a>Para criar um projeto do Linux

Para criar um novo projeto do Linux no Visual Studio 2019, siga estas etapas:

1. Selecione **Arquivo > Novo Projeto** no Visual Studio ou pressione **Ctrl + Shift + N**.
1. Defina a **Linguagem** como **C++** e pesquise "Linux". Selecione o tipo de projeto para criar e, em seguida, escolha **Avançar**. Insira um **Nome** e uma **Localização** e escolha **Criar**.

   ![Novo projeto do Linux](media/newproject-vs2019.png)

   | Tipo de Projeto | Descrição |
   | ------------ | --- |
   | **Intermitência (Raspberry)**           | Projeto direcionado a um dispositivo Raspberry Pi, com o código de exemplo que pisca um LED |
   | **Aplicativo de console (Linux)** | Projeto direcionado a qualquer computador Linux, com o código de exemplo que produz um texto no console |
   | **Projeto vazio (Linux)**       | Projeto direcionado a qualquer computador Linux, sem nenhum código de exemplo |
   | **Projeto Makefile (Linux)**    | Projeto direcionado a qualquer computador Linux, compilado usando um sistema de build padrão do Makefile |

## <a name="next-steps"></a>Próximas etapas

[Configurar um projeto do MSBuild do Linux](configure-a-linux-project.md)

::: moniker-end
