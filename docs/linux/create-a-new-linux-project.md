---
title: Criar um novo projeto do C++ Linux no Visual Studio
ms.date: 06/07/2019
ms.assetid: 5d7c1d67-bc31-4f96-8622-2b4cf91372fd
ms.openlocfilehash: e39e60c906901420a4809c22b4f4e71d3b621da1
ms.sourcegitcommit: 8adabe177d557c74566c13145196c11cef5d10d4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/10/2019
ms.locfileid: "66821643"
---
# <a name="create-a-new-linux-project"></a>Criar um novo projeto do Linux

::: moniker range="vs-2015"

Os projetos do Linux estão disponíveis no Visual Studio 2017 e posterior.

::: moniker-end

Primeiro, certifique-se de ter a **Carga de trabalho de desenvolvimento do Linux** para Visual Studio instalada. Para obter mais informações, consulte [Baixar, instalar e configurar a carga de trabalho do Linux](download-install-and-setup-the-linux-development-workload.md).

Ao criar um projeto C++ para o Linux no Visual Studio, você pode optar por criar um projeto do Visual Studio ou um projeto do CMake. Este artigo descreve como criar um projeto do Visual Studio. Para obter informações sobre criar e trabalhar com projetos existentes do CMake, confira [Configurar um projeto do CMake Linux](cmake-linux-project.md).

## <a name="to-create-a-new-linux-project"></a>Para criar um projeto do Linux

Para criar um projeto do Linux no Visual Studio, siga estas etapas:

::: moniker range="vs-2019"

1. Selecione **Arquivo > Novo Projeto** no Visual Studio ou pressione **Ctrl + Shift + N**.
1. Defina a **Linguagem** como **C++** e pesquise "Linux". Selecione o tipo de projeto para criar e, em seguida, escolha **Avançar**. Insira um **Nome** e uma **Localização** e escolha **Criar**.

   ![Novo projeto do Linux](media/newproject-vs2019.png)

::: moniker-end

::: moniker range="vs-2017"

1. Selecione **Arquivo > Novo Projeto** no Visual Studio ou pressione **Ctrl + Shift + N**.
1. Selecione o nó **Visual C++ > Multiplataforma > Linux** e, em seguida, selecione o tipo de projeto a ser criado. Insira um **Nome** e **Localização** e escolha **OK**.

   ![Novo projeto do Linux](media/newproject.png)

::: moniker-end

   | Tipo de Projeto | Descrição |
   | ------------ | --- |
   | **Intermitência (Raspberry)**           | Projeto direcionado a um dispositivo Raspberry Pi, com o código de exemplo que pisca um LED |
   | **Aplicativo de console (Linux)** | Projeto direcionado a qualquer computador Linux, com o código de exemplo que produz um texto no console |
   | **Projeto vazio (Linux)**       | Projeto direcionado a qualquer computador Linux, sem nenhum código de exemplo |
   | **Projeto Makefile (Linux)**    | Projeto direcionado a qualquer computador Linux, compilado usando um sistema de build padrão do Makefile |

## <a name="next-steps"></a>Próximas etapas

[Configurar um projeto do Linux](configure-a-linux-project.md)
