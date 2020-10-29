---
title: Criar um projeto C++ do MSBuild do Linux no Visual Studio
ms.date: 10/15/2020
description: Crie um novo projeto do Linux baseado em MSBuild no Visual Studio.
ms.assetid: 5d7c1d67-bc31-4f96-8622-2b4cf91372fd
ms.openlocfilehash: 458a26408bfd29b714150e5259fd23807c9b2908
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92921627"
---
# <a name="create-a-linux-msbuild-c-project-in-visual-studio"></a>Criar um projeto C++ do MSBuild do Linux no Visual Studio

::: moniker range="msvc-140"

Os projetos do Linux estão disponíveis no Visual Studio 2017 e posterior.

::: moniker-end

::: moniker range="msvc-150"

Primeiro, certifique-se de ter a **Carga de trabalho de desenvolvimento do Linux** para Visual Studio instalada. Para obter mais informações, consulte [Baixar, instalar e configurar a carga de trabalho do Linux](download-install-and-setup-the-linux-development-workload.md).

Para a compilação de plataforma cruzada, é recomendável usar CMake. O suporte a CMake é mais completo no Visual Studio 2019. Se CMake não for uma opção e você tiver uma solução existente do Windows Visual Studio que deseja estender para compilar para Linux, você poderá adicionar um projeto do Visual Studio Linux à solução do Windows, juntamente com um projeto de **itens compartilhados** . Coloque o código que é compartilhado entre as duas plataformas no projeto de itens compartilhados e adicione uma referência a esse projeto dos projetos do Windows e do Linux.

## <a name="to-create-a-new-linux-project"></a>Para criar um projeto do Linux

Para criar um novo projeto do Linux no Visual Studio 2017, siga estas etapas:

1. Selecione **Arquivo > Novo Projeto** no Visual Studio ou pressione **Ctrl + Shift + N** .
1. Selecione o nó **Visual C++ > Multiplataforma > Linux** e, em seguida, selecione o tipo de projeto a ser criado. Insira um **Nome** e **Localização** e escolha **OK** .

   ![Captura de tela mostrando a caixa de diálogo novo projeto com o Visual C Plus Plus > plataforma cruzada > Linux selecionado, todos os tipos de projeto chamados e as caixas de texto nome e local também são chamadas de saída.](media/newproject.png)

   | Tipo de Projeto | Descrição |
   | ------------ | --- |
   | **Intermitência (Raspberry)** | Projeto direcionado a um dispositivo Raspberry Pi, com o código de exemplo que pisca um LED |
   | **Aplicativo de console (Linux)** | Projeto direcionado a qualquer computador Linux, com o código de exemplo que produz um texto no console |
   | **Projeto vazio (Linux)** | Projeto direcionado a qualquer computador Linux, sem nenhum código de exemplo |
   | **Projeto Makefile (Linux)** | Projeto direcionado a qualquer computador Linux, compilado usando um sistema de build padrão do Makefile |

## <a name="next-steps"></a>Próximas etapas

[Configurar um projeto do MSBuild para Linux](configure-a-linux-project.md)

::: moniker-end

::: moniker range="msvc-160"

Primeiro, certifique-se de ter a **Carga de trabalho de desenvolvimento do Linux** para Visual Studio instalada. Para obter mais informações, consulte [baixar, instalar e configurar a carga de trabalho do Linux](download-install-and-setup-the-linux-development-workload.md).

Ao criar um projeto C++ para o Linux no Visual Studio, você pode optar por criar um projeto do Visual Studio ou um projeto do CMake. Este artigo descreve como criar um projeto do Visual Studio. Em geral, para novos projetos que podem incluir código de software livre ou você pretende compilar para desenvolvimento de plataforma cruzada, recomendamos que você use o CMake com o Visual Studio. Com um projeto CMake, você pode criar e depurar o mesmo projeto no Windows e no Linux. Para obter mais informações, consulte [criar e configurar um projeto CMake do Linux](cmake-linux-project.md).

Se você tiver uma solução existente do Windows Visual Studio que deseja estender para compilar para Linux e CMake não for uma opção, você poderá adicionar um projeto do Visual Studio Linux à solução do Windows, juntamente com um projeto de **itens compartilhados** . Coloque o código que é compartilhado entre as duas plataformas no projeto de itens compartilhados e adicione uma referência a esse projeto dos projetos do Windows e do Linux.

## <a name="create-a-new-linux-project"></a>Criar um novo projeto do Linux

Para criar um novo projeto do Linux no Visual Studio 2019, siga estas etapas:

1. Selecione **arquivo > novo projeto** no Visual Studio ou pressione **Ctrl + Shift + N** . A caixa de diálogo criar um novo projeto é exibida.
1. Na caixa de texto **Pesquisar modelos** , insira **Linux** para listar os modelos disponíveis para projetos do Linux.
1. Selecione o tipo de projeto a ser criado, por exemplo, **aplicativo de console** e escolha **Avançar** . Insira um **Nome** e uma **Localização** e escolha **Criar** .

   ![Captura de tela da caixa de diálogo novo projeto com a lista suspensa idioma definida como C++ e a lista suspensa plataforma definida como Linux.](media/newproject-vs2019.png)

   | Tipo de Projeto | Descrição |
   | ------------ | --- |
   | **Projeto do Raspberry Pi** | Projeto direcionado a um dispositivo Raspberry Pi, com o código de exemplo que pisca um LED |
   | **Aplicativo do Console** | Projeto direcionado a qualquer computador Linux, com o código de exemplo que produz um texto no console |
   | **Projeto em branco** | Projeto direcionado a qualquer computador Linux, sem nenhum código de exemplo |
   | **Projeto Makefile** | Projeto direcionado a qualquer computador Linux, compilado usando um sistema de build padrão do Makefile |
   | **Projeto do CMake** | Projeto destinado a qualquer computador Linux, criado usando o sistema de compilação CMake |

## <a name="next-steps"></a>Próximas etapas

[Configurar um projeto do Linux com o MSBuild](configure-a-linux-project.md)

::: moniker-end
