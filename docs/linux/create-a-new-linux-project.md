---
title: Criar um novo projeto do C++ Linux no Visual Studio
ms.date: 10/24/2019
description: Crie um novo projeto Linux baseado em MSBuild no Visual Studio.
ms.assetid: 5d7c1d67-bc31-4f96-8622-2b4cf91372fd
ms.openlocfilehash: 1e79dd50756b71aabae7ccec75e57178898e7720
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364344"
---
# <a name="create-a-new-linux-project"></a>Criar um novo projeto do Linux

::: moniker range="vs-2015"

Os projetos do Linux estão disponíveis no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range="vs-2017"

Primeiro, certifique-se de ter a **Carga de trabalho de desenvolvimento do Linux** para Visual Studio instalada. Para obter mais informações, consulte [Baixar, instalar e configurar a carga de trabalho do Linux](download-install-and-setup-the-linux-development-workload.md).

Para compilação multiplataforma, recomendamos o uso do CMake. O suporte ao CMake é mais completo no Visual Studio 2019. Se o CMake não for uma opção, e você tiver uma solução existente do Windows Visual Studio que você gostaria de estender para compilar para Linux, você pode adicionar um projeto visual studio Linux à solução do Windows, juntamente com um projeto **de Itens Compartilhados.** Coloque o código que é compartilhado entre ambas as plataformas no projeto Itens Compartilhados e adicione uma referência a esse projeto a partir dos projetos Windows e Linux.

## <a name="to-create-a-new-linux-project"></a>Para criar um projeto do Linux

Para criar um novo projeto Linux no Visual Studio 2017, siga estas etapas:

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

[Configurar um projeto do Linux](configure-a-linux-project.md)

::: moniker-end

::: moniker range="vs-2019"

Primeiro, certifique-se de ter a **Carga de trabalho de desenvolvimento do Linux** para Visual Studio instalada. Para obter mais informações, consulte [Baixar, instalar e configurar a carga de trabalho do Linux](download-install-and-setup-the-linux-development-workload.md).

Ao criar um projeto C++ para o Linux no Visual Studio, você pode optar por criar um projeto do Visual Studio ou um projeto do CMake. Este artigo descreve como criar um projeto do Visual Studio. Em geral, para novos projetos que podem incluir código-fonte aberto ou que você pretende compilar para desenvolvimento multiplataforma, recomendamos que você use O CMake com o Visual Studio. Com um projeto CMake você pode construir e depurar o mesmo projeto tanto no Windows quanto no Linux. Para obter mais informações, consulte [Criar e configurar um Linux CMake Project](cmake-linux-project.md).

Se você tem uma solução existente do Windows Visual Studio que você gostaria de estender para compilar para Linux, e o CMake não é uma opção, então você pode adicionar um projeto visual studio Linux à solução do Windows, juntamente com um projeto **de Itens Compartilhados.** Coloque o código que é compartilhado entre ambas as plataformas no projeto Itens Compartilhados e adicione uma referência a esse projeto a partir dos projetos Windows e Linux.

## <a name="to-create-a-new-linux-project"></a>Para criar um projeto do Linux

Para criar um novo projeto Linux no Visual Studio 2019, siga estas etapas:

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

[Configurar um projeto do Linux](configure-a-linux-project.md)

::: moniker-end
