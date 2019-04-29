---
title: Instalar o suporte ao C++ no Visual Studio
description: Instalar o suporte do Visual Studio para o Visual C++
ms.custom: mvc
ms.date: 04/02/2019
ms.topic: tutorial
ms.devlang: cpp
ms.assetid: 45138d70-719d-42dc-90d7-1d0ca31a2f54
ms.openlocfilehash: 2c2bed4063194bdc3c0f3fbc405be6bf9a4031e7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62315099"
---
# <a name="install-c-support-in-visual-studio"></a>Instalar o suporte ao C++ no Visual Studio

Se você ainda não tiver baixado e instalado o Visual Studio e as ferramentas do Visual C++ ainda, aqui está como começar.

::: moniker range="vs-2019"

## <a name="visual-studio-2019-installation"></a>Instalação do Visual Studio de 2019

Bem-vindo ao Visual Studio 2019. Nesta versão, é fácil escolher e instalar apenas os recursos que você precisa. E, devido a seu volume mínimo reduzido, ele é instalado rapidamente e com menos impacto no sistema.

> [!NOTE]
> Este tópico aplica-se a instalação do Visual Studio no Windows. [Visual Studio Code](https://code.visualstudio.com/) é um ambiente de desenvolvimento de plataforma cruzada leve que é executado nos sistemas Windows, Mac e Linux. O Microsoft [C/C++ para Visual Studio Code](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) extensão dá suporte ao IntelliSense, depuração, formatação de código, preenchimento automático. O Visual Studio para Mac não dá suporte a Microsoft C++, mas dá suporte a linguagens .NET e desenvolvimento de plataforma cruzada. Para obter instruções de instalação, consulte [instalar o Visual Studio para Mac](/visualstudio/mac/installation/).

Quer saber mais sobre quais são as outras novidades nesta versão? Consulte o Visual Studio [notas de versão](/visualstudio/releases/2019/release-notes/).

Pronto para instalar? Guiaremos você no processo, passo a passo.

### <a name="step-1---make-sure-your-computer-is-ready-for-visual-studio"></a>Etapa 1 - Verificar se o computador está pronto para o Visual Studio

Antes de começar a instalação do Visual Studio:

1. Verifique os [requisitos do sistema](/visualstudio/releases/2019/system-requirements). Esses requisitos ajudam você a saber se o computador dá suporte ao Visual Studio 2019.

1. Aplique as atualizações mais recentes do Windows. Essas atualizações garantem que o computador tenha as atualizações de segurança mais recentes e os componentes de sistema obrigatórios para o Visual Studio.

1. Reinicialize. Isso garante que todas as instalações ou atualizações pendentes não atrapalhem a instalação do Visual Studio.

1. Libere espaço. Remova arquivos e aplicativos desnecessários de %SystemDrive%, por exemplo, executando o aplicativo Limpeza de Disco.

Para solucionar dúvidas sobre a execução de versões anteriores do Visual Studio lado a lado com o Visual Studio 2019, veja a página [Direcionamento e compatibilidade da plataforma Visual Studio 2019](/visualstudio/releases/2019/compatibility/).

### <a name="step-2---download-visual-studio"></a>Etapa 2 - Baixar o Visual Studio

Em seguida, baixe o arquivo bootstrapper do Visual Studio. Para fazer isso, escolha o botão a seguir, escolha a edição desejada do Visual Studio, escolha **Salvar** e, em seguida, escolha **Abrir pasta**.

 > [!div class="button"]
 > [Baixar o Visual Studio](https://visualstudio.microsoft.com/downloads/?utm_medium=microsoft&utm_source=docs.microsoft.com&utm_campaign=button+cta&utm_content=download+vs2019+rc)

### <a name="step-3---install-the-visual-studio-installer"></a>Etapa 3 - Instalar o instalador do Visual Studio

Execute o arquivo bootstrapper para instalar o Instalador do Visual Studio. Esse novo instalador leve inclui tudo o que você precisa para instalar e personalizar o Visual Studio.

1. Da sua pasta **Downloads**, clique duas vezes no inicializador que corresponde ou é semelhante a um dos seguintes arquivos:

   * **vs_community.exe** para Visual Studio Community
   * **vs_professional.exe** para Visual Studio Professional
   * **vs_enterprise.exe** para Visual Studio Enterprise

   Se você receber um aviso de Controle de Conta de Usuário, escolha **Sim**.

1. Solicitaremos sua confirmação dos [Termos de Licença](https://visualstudio.microsoft.com/license-terms/) da Microsoft e da [Política de Privacidade](https://privacy.microsoft.com/privacystatement) da Microsoft. Escolha **Continuar**.

### <a name="step-4---choose-workloads"></a>Etapa 4 – escolher cargas de trabalho

Depois que o instalador está instalado, você pode usá-lo para personalizar sua instalação selecionando os *cargas de trabalho*, ou o recurso de conjuntos, o que você deseja. Veja como.

1. Encontre a carga de trabalho desejada na tela **Instalando o Visual Studio**.

   ![Visual Studio 2019: Instalar uma carga de trabalho](../get-started/media/vs-installer-workloads.png)

   Para obter suporte de principal do C++, escolha a carga de trabalho "Desenvolvimento para Desktop com C++". Ela vem com o editor de núcleo padrão, que inclui o suporte à edição de código básico para mais de 20 linguagens, a capacidade de abrir e editar o código de qualquer pasta sem precisar de um projeto e o controle do código-fonte integrado.

   Cargas de trabalho adicionais dão suporte a outros tipos de desenvolvimento do C++. Por exemplo, escolha a carga de trabalho "Desenvolvimento da plataforma Universal do Windows" para criar aplicativos que usam o tempo de execução do Windows para a Microsoft Store. Escolha "Desenvolvimento de jogos com C++" para criar jogos que usam o DirectX, Unreal e Cocos2d. Escolha "Desenvolvimento de Linux com C++" para plataformas Linux de destino, incluindo o desenvolvimento de IoT.

   O **detalhes da instalação** painel lista os componentes opcionais e incluídos instalados por cada carga de trabalho. Você pode selecionar ou anular a seleção de componentes opcionais nessa lista. Por exemplo, para dar suporte ao desenvolvimento, usando o Visual Studio 2017 ou conjuntos de ferramentas do compilador de 2015, escolha o MSVC v141 ou os componentes opcionais do MSVC v140. Você pode adicionar suporte MFC, a extensão da linguagem módulos experimental, IncrediBuild e muito mais.

1. Depois de escolher as cargas de trabalho e componentes opcionais que você deseja, escolha **instalar**.

    Em seguida, serão exibidas telas de status que mostram o progresso da instalação do Visual Studio.

> [!TIP]
> A qualquer momento após a instalação, você pode instalar as cargas de trabalho ou os componentes não instalados inicialmente. Caso o Visual Studio esteja aberto, acesse **Ferramentas** > **Obter Ferramentas e Funcionalidades...**, que abre o Instalador do Visual Studio. Outra opção é abrir o **Instalador do Visual Studio** no menu Iniciar. Assim, é possível escolher as cargas de trabalho ou os componentes que você deseja instalar. Em seguida, escolha **Modificar**.

## <a name="step-5---choose-individual-components-optional"></a>Etapa 5 – escolher componentes individuais (opcional)

Se não quiser usar o recurso de cargas de trabalho para personalizar a instalação do Visual Studio ou se desejar adicionar mais componentes do que aqueles instalados por uma carga de trabalho, você poderá fazer isso instalando ou adicionando componentes individuais por meio da guia **Componentes individuais**. Escolha o que deseja e, em seguida, siga os prompts.

  ![Visual Studio 2019 — Instalar componentes individuais](../get-started/media/vs-installer-individual-components.png "Instalar componentes individuais do Visual Studio")

## <a name="step-6---install-language-packs-optional"></a>Etapa 6 - Instalar pacotes de idiomas (opcional)

Por padrão, o programa do instalador tenta encontrar a correspondência do idioma do sistema operacional quando ele é executado pela primeira vez. Para instalar o Visual Studio em um idioma de sua escolha, escolha a guia **Pacotes de idioma** do Instalador do Visual Studio e siga os prompts.

  ![Visual Studio 2019 — Instalar pacotes de idiomas](../get-started/media/vs-installer-language-packs.png "Instalar pacotes de idiomas do Visual Studio")

### <a name="change-the-installer-language-from-the-command-line"></a>Alterar o idioma de instalação da linha de comando

Outra maneira de alterar o idioma padrão é executar o instalador a partir da linha de comando. Por exemplo, é possível forçar o instalador a ser executado em inglês usando o seguinte comando: `vs_installer.exe --locale en-US`. O instalador memorizará essa configuração quando ele é executado na próxima vez. O instalador dá suporte aos seguintes tokens de idioma: zh-cn, zh-tw, cs-cz, en-us, es-es, fr-fr, de-de, it-it, ja-jp, ko-kr, pl-pl, pt-br, ru-ru e tr-tr.

### <a name="step-7---change-the-installation-location-optional"></a>Etapa 7 – Alterar o local de instalação (opcional)

Você pode reduzir o volume de instalação do Visual Studio na unidade do sistema. Você pode optar por mover o cache de download, os componentes compartilhados, os SDKs e as ferramentas para unidades diferentes e manter o Visual Studio na unidade que executá-los com mais rapidez.

  ![Visual Studio 2019 – Alterar locais de instalação](../get-started/media/vs-installer-installation-locations.png "Alterar o local de instalação")

> [!IMPORTANT]
> Você pode selecionar uma unidade diferente apenas quando você instala o Visual Studio pela primeira vez. Se você já tiver instalado e quiser alterar unidades, precisará desinstalar o Visual Studio e, em seguida, reinstalá-lo.

## <a name="step-8---start-developing"></a>Etapa 8 – Começar a desenvolver

1. Após a conclusão da instalação do Visual Studio, escolha o botão **Iniciar** para ver a introdução ao desenvolvimento com o Visual Studio.

1. Na tela Iniciar, selecione **Criar um novo projeto**.

1. Na caixa de pesquisa, insira o tipo de aplicativo que deseja criar para ver uma lista de modelos disponíveis. A lista de modelos depende das cargas de trabalho escolhidas durante a instalação. Para ver os diferentes modelos, escolha diferentes cargas de trabalho.

   Você também pode filtrar sua pesquisa para uma linguagem de programação específica usando a lista suspensa **Linguagem de programação**. Você também pode filtrar usando as listas **Plataforma** e **Tipo de projeto**.

1. O Visual Studio abre seu novo projeto e você está pronto para codificar!

::: moniker-end

::: moniker range="<=vs-2017"

## <a name="visual-studio-2017-installation"></a>Instalação do Visual Studio 2017

No Visual Studio 2017, é fácil escolher e instalar apenas os recursos que necessários. E, devido a seu volume mínimo reduzido, ele é instalado rapidamente e com menos impacto no sistema.

### <a name="prerequisites"></a>Pré-requisitos

- Uma conexão de internet banda larga. O instalador do Visual Studio pode baixar vários gigabytes de dados.

- Um computador que executa o Microsoft Windows 7 ou versões posteriores. Recomendamos o Windows 10 para uma melhor experiência de desenvolvimento. Certifique-se de que as atualizações mais recentes sejam aplicadas ao seu sistema antes de instalar o Visual Studio.

- Espaço em disco suficiente. Visual Studio requer pelo menos 7 GB de espaço em disco e pode levar a 50 GB ou mais se muitas das opções comuns estiverem instalados. É recomendável que instalá-lo em sua unidade c:.

Para obter detalhes sobre o espaço em disco e os requisitos do sistema operacional, consulte [requisitos de sistema família do Visual Studio produto](/visualstudio/productinfo/vs2017-system-requirements-vs). O instalador relata quanto espaço em disco é necessário para as opções selecionadas.

### <a name="download-and-install"></a>Baixe e instale

1. Baixe o instalador mais recente do Visual Studio 2017 para Windows.

   > [!div class="nextstepaction"]
   > [Instalar Visual Studio 2017 Community](https://visualstudio.microsoft.com/downloads/?utm_medium=microsoft&utm_source=docs.microsoft.com&utm_campaign=button+cta&utm_content=download+vs2017)

   >[!Tip]
   > A edição Community é para desenvolvedores individuais, aprendizado em sala de aula, pesquisa acadêmica e desenvolvimento de software livre. Para outros usos, instale o [Visual Studio 2017 Professional](https://visualstudio.microsoft.com/downloads/?utm_medium=microsoft&utm_source=docs.microsoft.com&utm_campaign=button+cta&utm_content=download+vs2017) ou o [Visual Studio 2017 Enterprise](https://visualstudio.microsoft.com/downloads/?utm_medium=microsoft&utm_source=docs.microsoft.com&utm_campaign=button+cta&utm_content=download+vs2017).

1. Localize o arquivo do instalador baixado e executá-lo. Ele pode ser exibido em seu navegador, ou você pode encontrá-lo na pasta Downloads. O instalador precisa de privilégios de administrador para ser executado. Você poderá ver uma **User Account Control** caixa de diálogo solicitando que você conceda permissão para permitir que o instalador de fazer alterações ao seu sistema; escolher **Sim**. Se você estiver tendo problemas, localize o arquivo baixado no Explorador de arquivos, clique com botão direito no ícone de instalação e escolha **executar como administrador** no menu de contexto.

   ![Baixe e instale o instalador do Visual Studio](media/vscpp-concierge-run-installer.gif "Baixe e instale o instalador do Visual Studio")

1. O instalador apresenta uma lista de cargas de trabalho, que são grupos de opções relacionadas para áreas de desenvolvimento específicas. Suporte para C++ agora faz parte das cargas de trabalho opcionais que não são instalados por padrão.

   ![Desenvolvimento para desktop com a carga de trabalho C++](media/desktop-development-with-cpp.png "desenvolvimento para Desktop com C++")

   Para C++, selecione o **desenvolvimento para Desktop com C++** carga de trabalho e, em seguida, escolha **instalar**.

   ![Instalar o desenvolvimento de área de trabalho com carga de trabalho do C++](media/vscpp-concierge-choose-workload.gif "instalar o desenvolvimento de área de trabalho com carga de trabalho do C++")

1. Quando a instalação for concluída, escolha o **inicie** botão para iniciar o Visual Studio.

   Na primeira vez que você executar o Visual Studio, que você está solicitado a entrar com uma Account da Microsoft. Se você não tiver uma, você pode criar um gratuitamente. Você também deve escolher um tema. Não se preocupe, você pode alterá-lo mais tarde, se você quiser.

   Pode levar o Visual Studio vários minutos para se preparar para usam na primeira vez em que você executá-lo. Aqui está o que ele se parece com um rápido lapso de tempo:

   ![Visual Studio 2017 entrar](media/vscpp-quickstart-first-run.gif "entrar do Visual Studio 2017")

   Visual Studio inicia muito mais rapidamente quando você executá-lo novamente.

1. Quando o Visual Studio é aberto, verifique se o ícone de sinalizador na barra de título é realçado:

   ![Sinalizador de notificação do Visual Studio 2017](media/vscpp-first-start-page-flag.png "sinalizador de notificação do Visual Studio 2017")

   Se ele estiver selecionado, selecione-o para abrir o **notificações** janela. Se houver quaisquer atualizações disponíveis para o Visual Studio, é recomendável que instalá-los agora. Depois que a instalação for concluída, reinicie o Visual Studio.

::: moniker-end

::: moniker range="<vs-2017"

## <a name="visual-studio-2015-installation"></a>Instalação do Visual Studio 2015

Para instalar o Visual Studio 2015, acesse [Baixar versões mais antigas do Visual Studio](https://www.visualstudio.com/vs/older-downloads/). Execute o programa de instalação, escolha **Instalação personalizada** e, em seguida, selecione o componente C++. Para adicionar suporte do C++ a uma instalação existente do Visual Studio 2015, clique no botão Iniciar do Windows e digite **adicionar ou remover programas**. Abra o programa na lista de resultados e, em seguida, localize sua instalação do Visual Studio 2015 na lista de programas instalados. Clique duas vezes nele e, em seguida, escolha **modificar** e selecione os componentes do Visual C++ para instalar.

Em geral, é altamente recomendado que você use o Visual Studio 2017, mesmo que você precise compilar o código com o compilador do Visual Studio 2015. Para obter mais informações, consulte [Usar a multiplataforma nativa no Visual Studio para compilar projetos antigos](../porting/use-native-multi-targeting.md).

::: moniker-end

Quando o Visual Studio está em execução, você estará pronto para continuar para a próxima etapa.

## <a name="next-steps"></a>Próximas etapas

> [!div class="nextstepaction"]
> [Criar um projeto C++](vscpp-step-1-create.md)

<iframe src="" height="0" width="0" frameborder="0" name="frameTarget" />
