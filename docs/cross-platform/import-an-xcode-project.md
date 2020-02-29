---
title: Importar um projeto do Xcode
ms.date: 10/17/2019
ms.assetid: aa4b8161-d98f-4a1a-9db3-520133bfc82f
ms.openlocfilehash: 709060e053852f4518a842467ccfb7f0ed760ba2
ms.sourcegitcommit: a673f6a54cc97e3d4cd032b10aa8dce7f0539d39
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/28/2020
ms.locfileid: "78177629"
---
# <a name="import-an-xcode-project"></a>Importar um projeto do Xcode

As ferramentas do Visual Studio para desenvolvimento móvel de plataforma cruzada com C++ o incluem suporte para mover seus projetos do Xcode para o Visual Studio, onde você pode criar bibliotecas de plataforma cruzada e compartilhar código com outros projetos. O assistente de importação do Xcode simplifica o processo de importação de projetos e divisão do C++ código em seus destinos do Xcode para uso como uma biblioteca estática ou um projeto de código compartilhado. Você pode gerenciar seu código específico do iOS no Visual Studio e ainda usar o Xcode para fazer storyboards e compilações. Para obter informações sobre como mover facilmente o código para frente e para trás entre o Visual Studio e o Xcode, consulte [sincronizar alterações entre o Xcode e o Visual Studio](sync-changes-between-xcode-and-visual-studio.md).

## <a name="use-the-import-from-xcode-wizard"></a>Usar o assistente de importação do Xcode

Este artigo mostra como mover um projeto do Xcode para o Visual Studio, para aproveitar as vantagens do compartilhamento de código e das soluções entre plataformas. Como pré-requisito, você deve emparelhar seu Mac com o Visual Studio para importar, exportar e compilar seu projeto. Para obter instruções sobre como configurar o emparelhamento, confira [Instalar e configurar ferramentas de build usando o iOS](../cross-platform/install-and-configure-tools-to-build-using-ios.md). Você também deve compartilhar seu projeto do Xcode pela rede ou movê-lo para o computador do Visual Studio, para usar o assistente de importação do Xcode.

### <a name="import-from-xcode"></a>Importar do Xcode

1. No menu **arquivo** , escolha **novo**, **importar**, **Importar do Xcode**. Esse comando inicia a caixa de diálogo **Importar do assistente do Xcode** .

   ![Escolha o projeto de destino do Xcode para importar](../cross-platform/media/cppmdd-u2-importxcode-choose.png "Escolha o projeto de destino do Xcode para importar")

1. No painel **escolher um projeto** , escolha o botão procurar para selecionar um arquivo Xcode *. pbxproj* . Navegue até o arquivo de projeto na caixa de diálogo **Selecionar arquivo de projeto do Xcode** e, em seguida, escolha **abrir**.

   ![Selecione um arquivo de projeto na caixa de diálogo Selecionar arquivo de projeto do Xcode](../cross-platform/media/cppmdd-u2-importxcode-browse.png "Selecione um arquivo de projeto na caixa de diálogo Selecionar arquivo de projeto do Xcode")

   No assistente importar do Xcode, escolha **Avançar**.

1. No painel **destinos de destino** , escolha os destinos do projeto Xcode para importar para projetos do Visual Studio. Os destinos do Xcode são semelhantes aos projetos do Visual Studio; a maioria é uma coleção de código e recursos que produzem um binário. O assistente de importação do Xcode permite apenas a importação de destinos que produzem um binário, mas não uma biblioteca estática, como destinos de destino. Os destinos da biblioteca estática do Xcode são o assunto da próxima etapa.

   ![Painel importar de destinos de destino do assistente do Xcode](../cross-platform/media/cppmdd-u2-importxcode-destination.jpg "Painel importar de destinos de destino do assistente do Xcode")

   Para cada destino selecionado em **Destinos para importar**, o assistente detecta automaticamente os arquivos de código C++ que podem ser divididos em um projeto de biblioteca estática separado e os coloca na seção **Itens de projeto C++** . Outros códigos e recursos são deixados na seção **itens de projeto do Xcode** . Elas se tornam projetos de aplicativo e biblioteca estática separados no Visual Studio quando o assistente conclui o processo de importação. Por padrão, os destinos de teste de unidade e de estrutura não são divididos em projetos separados pelo assistente.

   Para alterar quais arquivos estão em cada projeto, use os botões para cima e para baixo. Quando estiver satisfeito com os arquivos em cada projeto, escolha **Avançar** para continuar.

1. No painel **destinos de biblioteca** , escolha qual biblioteca estática é direcionada do projeto Xcode para importar para projetos do Visual Studio. Nesse painel, você pode escolher quais arquivos incluir em um projeto de código compartilhado e qual deles deve ser colocado em um projeto de biblioteca estática. Em cada um dos destinos na lista **destinos para importar** , você pode controlar os arquivos a serem colocados nos **itens do projeto de código compartilhado** e os **itens do projeto de biblioteca estática** usando os botões para cima e para baixo.

   ![Importar do painel destinos da biblioteca do Xcode](../cross-platform/media/cppmdd-u2-importxcode-library.jpg "Importar do painel destinos da biblioteca do Xcode")

   Um projeto de código compartilhado é uma maneira de compartilhar um conjunto de arquivos de origem entre projetos no Visual Studio. O código é compilado como parte do projeto que o inclui, não como um projeto independente. Os projetos que incluem o código compartilhado podem ter diferentes arquiteturas e configurações. Um projeto de código compartilhado é a melhor maneira de fornecer um único projeto que contém código que pode ser criado para muitos tipos de plataformas.

   Quando estiver satisfeito com os arquivos em cada projeto, escolha **Avançar** para continuar.

1. Use o painel **propriedades globais** para definir um caminho de pesquisa de estrutura e um caminho de pesquisa de cabeçalho de inclusão para todos os projetos do Ios no Visual Studio. O Visual Studio usa esses caminhos para navegação no código-fonte e para o IntelliSense. Esses caminhos globais são úteis quando você cria projetos de iOS que usam um conjunto comum de cabeçalhos e estruturas.

   ![Importar do painel de propriedades globais do Xcode](../cross-platform/media/cppmdd-u2-importxcode-global.jpg "Importar do painel de propriedades globais do Xcode")

   Esses caminhos globais também podem ser definidos no Visual Studio na caixa de diálogo **Opções**. Para encontrá-los, no menu **Ferramentas**, selecione **Opções**. Na caixa de diálogo **Opções** , expanda **várias plataformas** > **C++**  > **Ios** > **propriedades globais**.

   Escolha **Avançar** para continuar.

1. O painel **Estruturas** é usado para configurar os caminhos usados pelo Visual Studio para navegar e IntelliSense para seu projeto. Os caminhos devem ser acessíveis para o Visual Studio para cada estrutura referenciada por seu projeto do Xcode. O assistente verifica as referências de estrutura nos projetos do Xcode e exibe se o Visual Studio pode encontrar a estrutura. Qualquer caminho que você já configurou nas Propriedades Globais deve ser descoberto pelo Visual Studio. As exceções são listadas na lista Estruturas. Para cada estrutura listada com um X, forneça um caminho acessível do computador para o Visual Studio localizar a estrutura. Use o botão Procurar **...** para usar uma caixa de diálogo **Selecionar Pasta** para localizar o caminho. O caminho da estrutura pode ser para uma cópia local ou para um compartilhamento acessível pela rede no Mac.

   ![Importar do painel do Xcode frameworks](../cross-platform/media/cppmdd-u2-importxcode-frameworks.jpg "Importar do painel do Xcode frameworks")

   Escolha **Avançar** para continuar.

1. O painel **Configurações do Projeto** permite que você altere as configurações de caminho de pesquisa de cabeçalho de inclusão e de estrutura para cada projeto que o assistente cria. Use este painel para definir caminhos específicos do projeto que são diferentes das configurações globais.

   Para definir um caminho para um projeto específico, na lista suspensa **projeto de destino** , selecione o arquivo de projeto. Em seguida, defina os valores no **caminho de pesquisa do Framework** e inclua controles de **caminho de pesquisa de cabeçalho** . Use o botão Procurar **...** ao lado de cada controle para usar uma caixa de diálogo **Selecionar Pasta** para localizar o caminho.

   ![Importar do painel de projetos do Xcode](../cross-platform/media/cppmdd-u2-importxcode-projects.jpg "Importar do painel de projetos do Xcode")

   Se nenhum Mac remoto tiver sido emparelhado com esse computador no Visual Studio, o link **Configurar um Computador Remoto** será exibido. Para obter instruções sobre como configurar o emparelhamento, confira [Instalar e configurar ferramentas de build usando o iOS](../cross-platform/install-and-configure-tools-to-build-using-ios.md).

   Para importar o projeto do Xcode usando as configurações do assistente, escolha **importar**.

   O assistente de importação do Xcode cria projetos no Visual Studio que correspondem aos destinos do projeto do Xcode selecionado. O código que pode ser compartilhado com outros projetos do C++ é dividido em projetos de biblioteca estática e código compartilhado separados. O código restante é colocado em projetos de aplicativo e biblioteca iOS que podem ser compilados remotamente pelo Visual Studio. Para obter mais informações sobre como mover o código entre o Visual Studio e o Xcode, consulte [sincronizar alterações entre o Xcode e o Visual Studio](../cross-platform/sync-changes-between-xcode-and-visual-studio.md).

## <a name="see-also"></a>Confira também

- [Instalar o desenvolvimento móvel de plataforma cruzada com oC++](../cross-platform/install-visual-cpp-for-cross-platform-mobile-development.md)
