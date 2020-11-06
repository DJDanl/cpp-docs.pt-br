---
title: Instalar o suporte a C e C++ no Visual Studio
description: Saiba como instalar o Visual Studio com suporte para Microsoft C/C++ e cargas de trabalho relacionadas.
ms.custom: mvc
ms.date: 11/05/2020
ms.topic: tutorial
ms.devlang: cpp
ms.assetid: 45138d70-719d-42dc-90d7-1d0ca31a2f54
ms.openlocfilehash: 3f2d2ade54cb4db2cd692f044a5cd648600bc7f6
ms.sourcegitcommit: 12eb6a824dd7187a065d44fceca4c410f58e121e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/06/2020
ms.locfileid: "94334176"
---
# <a name="install-c-and-c-support-in-visual-studio"></a>Instalar o suporte a C e C++ no Visual Studio

Se você ainda não baixou e instalou o Visual Studio e as ferramentas do Microsoft C/C++, veja aqui como começar.

::: moniker range="msvc-160"

## <a name="visual-studio-2019-installation"></a>Instalação do Visual Studio 2019

Bem-vindo ao Visual Studio 2019. Nesta versão, é fácil escolher e instalar apenas os recursos que você precisa. E, devido a seu volume mínimo reduzido, ele é instalado rapidamente e com menos impacto no sistema.

> [!NOTE]
> Este tópico aplica-se à instalação do Visual Studio no Windows. [Visual Studio Code](https://code.visualstudio.com/) é um ambiente de desenvolvimento leve de plataforma cruzada que é executado em sistemas Windows, Mac e Linux. A extensão do Microsoft [C/C++ para Visual Studio Code](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) dá suporte ao IntelliSense, depuração, formatação de código, preenchimento automático. O Visual Studio para Mac não dá suporte ao Microsoft C++, mas oferece suporte a linguagens .NET e desenvolvimento de plataforma cruzada. Para obter instruções de instalação, consulte [instalar Visual Studio para Mac](/visualstudio/mac/installation/).

Quer saber mais sobre quais são as outras novidades nesta versão? Consulte as notas de [versão](/visualstudio/releases/2019/release-notes/)do Visual Studio.

Pronto para instalar? Guiaremos você no processo, passo a passo.

### <a name="step-1---make-sure-your-computer-is-ready-for-visual-studio"></a>Etapa 1 - Verificar se o computador está pronto para o Visual Studio

Antes de começar a instalação do Visual Studio:

1. Verifique os [requisitos do sistema](/visualstudio/releases/2019/system-requirements). Esses requisitos ajudam você a saber se o computador dá suporte ao Visual Studio 2019.

1. Aplique as atualizações mais recentes do Windows. Essas atualizações garantem que o computador tenha as atualizações de segurança mais recentes e os componentes de sistema obrigatórios para o Visual Studio.

1. Reinicialize. Isso garante que todas as instalações ou atualizações pendentes não atrapalhem a instalação do Visual Studio.

1. Libere espaço. Remova arquivos e aplicativos desnecessários de %SystemDrive%, por exemplo, executando o aplicativo Limpeza de Disco.

Para solucionar dúvidas sobre a execução de versões anteriores do Visual Studio lado a lado com o Visual Studio 2019, veja a página [Direcionamento e compatibilidade da plataforma Visual Studio 2019](/visualstudio/releases/2019/compatibility/).

### <a name="step-2---download-visual-studio"></a>Etapa 2 - Baixar o Visual Studio

Em seguida, baixe o arquivo bootstrapper do Visual Studio. Para fazer isso, escolha o botão a seguir para ir para a página de download do Visual Studio. Selecione a edição do Visual Studio que você deseja e escolha o botão **avaliação gratuita** ou **Download gratuito** .

 > [!div class="button"]
 > [Baixar o Visual Studio](https://visualstudio.microsoft.com/downloads/?utm_medium=microsoft&utm_source=docs.microsoft.com&utm_campaign=button+cta&utm_content=download+vs2019+rc)

### <a name="step-3---install-the-visual-studio-installer"></a>Etapa 3 - Instalar o instalador do Visual Studio

Execute o arquivo bootstrapper que você baixou para instalar o Instalador do Visual Studio. Esse novo instalador leve inclui tudo o que você precisa para instalar e personalizar o Visual Studio.

1. Da sua pasta **Downloads** , clique duas vezes no inicializador que corresponde ou é semelhante a um dos seguintes arquivos:

   - **vs_community.exe** para Visual Studio Community
   - **vs_professional.exe** para Visual Studio Professional
   - **vs_enterprise.exe** para Visual Studio Enterprise

   Se você receber um aviso de controle de conta de usuário, escolha **Sim** para permitir que o bootstrapper seja executado.

1. Solicitaremos que você confirme os termos de [licença](https://visualstudio.microsoft.com/license-terms/) da Microsoft e a [política de privacidade](https://privacy.microsoft.com/privacystatement)da Microsoft. Escolha **Continuar**.

### <a name="step-4---choose-workloads"></a>Etapa 4 – escolher cargas de trabalho

Depois que o instalador for instalado, você poderá usá-lo para personalizar a instalação selecionando as *cargas de trabalho* ou os conjuntos de recursos que você deseja. Veja como.

1. Encontre a carga de trabalho desejada na tela **Instalando o Visual Studio**.

   ![Visual Studio 2019: instalar uma carga de trabalho](../get-started/media/vs-installer-workloads.png)

   Para obter suporte a C e C++ principal, escolha a carga de trabalho "desenvolvimento de desktop com C++". Ela vem com o editor de núcleo padrão, que inclui o suporte à edição de código básico para mais de 20 linguagens, a capacidade de abrir e editar o código de qualquer pasta sem precisar de um projeto e o controle do código-fonte integrado.

   As cargas de trabalho adicionais dão suporte a outros tipos de desenvolvimento. Por exemplo, escolha a carga de trabalho "desenvolvimento de Plataforma Universal do Windows" para criar aplicativos que usam o Windows Runtime para o Microsoft Store. Escolha "desenvolvimento de jogos com C++" para criar jogos que usam DirectX, inreal e cocos2d. Escolha "desenvolvimento Linux com C++" para as plataformas Linux de destino, incluindo o desenvolvimento de IoT.

   O painel **detalhes da instalação** lista os componentes incluídos e opcionais instalados por cada carga de trabalho. Você pode selecionar ou anular a seleção de componentes opcionais nesta lista. Por exemplo, para dar suporte ao desenvolvimento usando os conjuntos de ferramentas do compilador do Visual Studio 2017 ou 2015, escolha os componentes opcionais MSVC v141 ou MSVC v140. Você pode adicionar suporte para MFC, a extensão de linguagem de módulos experimentais, IncrediBuild e muito mais.

1. Depois de escolher as cargas de trabalho e os componentes opcionais desejados, escolha **instalar**.

   Em seguida, serão exibidas telas de status que mostram o progresso da instalação do Visual Studio.

> [!TIP]
> A qualquer momento após a instalação, você pode instalar as cargas de trabalho ou os componentes não instalados inicialmente. Se você tiver o Visual Studio aberto, vá para **ferramentas**  >  **obter ferramentas e recursos...** que abre a instalador do Visual Studio. Outra opção é abrir o **Instalador do Visual Studio** no menu Iniciar. Assim, é possível escolher as cargas de trabalho ou os componentes que você deseja instalar. Em seguida, escolha **Modificar**.

### <a name="step-5---choose-individual-components-optional"></a>Etapa 5 – escolher componentes individuais (opcional)

Se você não quiser usar o recurso de cargas de trabalho para personalizar a instalação do Visual Studio ou se quiser adicionar mais componentes do que uma carga de trabalho é instalada, você pode fazer isso instalando ou adicionando componentes individuais da guia **componentes individuais** . Escolha o que você deseja e, em seguida, siga os prompts.

  ![Visual Studio 2019-instalar componentes individuais](../get-started/media/vs-installer-individual-components.png "Instalar componentes individuais do Visual Studio")

### <a name="step-6---install-language-packs-optional"></a>Etapa 6 - Instalar pacotes de idiomas (opcional)

Por padrão, o programa do instalador tenta encontrar a correspondência do idioma do sistema operacional quando ele é executado pela primeira vez. Para instalar o Visual Studio em um idioma de sua escolha, escolha a guia **Pacotes de idioma** do Instalador do Visual Studio e siga os prompts.

  ![Visual Studio 2019-instalar pacotes de idiomas](../get-started/media/vs-installer-language-packs.png "Instalar pacotes de idiomas do Visual Studio")

#### <a name="change-the-installer-language-from-the-command-line"></a>Alterar o idioma de instalação da linha de comando

Outra maneira de alterar o idioma padrão é executar o instalador a partir da linha de comando. Por exemplo, é possível forçar o instalador a ser executado em inglês usando o seguinte comando: `vs_installer.exe --locale en-US`. O instalador se lembrará dessa configuração quando for executada na próxima vez. O instalador dá suporte aos seguintes tokens de idioma: zh-cn, zh-tw, cs-cz, en-us, es-es, fr-fr, de-de, it-it, ja-jp, ko-kr, pl-pl, pt-br, ru-ru e tr-tr.

### <a name="step-7---change-the-installation-location-optional"></a>Etapa 7 – Alterar o local de instalação (opcional)

Você pode reduzir o volume de instalação do Visual Studio na unidade do sistema. Você pode optar por mover o cache de download, os componentes compartilhados, os SDKs e as ferramentas para unidades diferentes e manter o Visual Studio na unidade que executá-los com mais rapidez.

  ![Visual Studio 2019-alterar locais de instalação](../get-started/media/vs-installer-installation-locations.png "Alterar o local de instalação")

> [!IMPORTANT]
> Você pode selecionar uma unidade diferente apenas quando você instala o Visual Studio pela primeira vez. Se você já tiver instalado e quiser alterar unidades, precisará desinstalar o Visual Studio e, em seguida, reinstalá-lo.

### <a name="step-8---start-developing"></a>Etapa 8 – Começar a desenvolver

1. Após a conclusão da instalação do Visual Studio, escolha o botão **Iniciar** para ver a introdução ao desenvolvimento com o Visual Studio.

1. Na janela iniciar, escolha **criar um novo projeto**.

1. Na caixa de pesquisa, insira o tipo de aplicativo que deseja criar para ver uma lista de modelos disponíveis. A lista de modelos depende das cargas de trabalho escolhidas durante a instalação. Para ver os diferentes modelos, escolha diferentes cargas de trabalho.

   Você também pode filtrar sua pesquisa para uma linguagem de programação específica usando a lista suspensa **Linguagem de programação**. Você também pode filtrar usando as listas **Plataforma** e **Tipo de projeto**.

1. O Visual Studio abre seu novo projeto e você está pronto para codificar!

::: moniker-end

::: moniker range="msvc-150"

## <a name="visual-studio-2017-installation"></a>Instalação do Visual Studio 2017

No Visual Studio 2017, é fácil escolher e instalar apenas os recursos de que você precisa. E, devido a seu volume mínimo reduzido, ele é instalado rapidamente e com menos impacto no sistema.

### <a name="prerequisites"></a>Pré-requisitos

- Uma conexão de Internet de banda larga. O instalador do Visual Studio pode baixar vários gigabytes de dados.

- Um computador que executa o Microsoft Windows 7 ou versões posteriores. Recomendamos o Windows 10 para obter a melhor experiência de desenvolvimento. Certifique-se de que as atualizações mais recentes sejam aplicadas ao seu sistema antes de instalar o Visual Studio.

- Espaço livre em disco suficiente. O Visual Studio requer pelo menos 7 GB de espaço em disco e pode levar de 50 GB ou mais se muitas opções comuns forem instaladas. Recomendamos que você o instale em sua unidade C:.

Para obter detalhes sobre o espaço em disco e os requisitos do sistema operacional, consulte [requisitos de sistema da família de produtos do Visual Studio](/visualstudio/productinfo/vs2017-system-requirements-vs). O instalador relata a quantidade de espaço em disco necessária para as opções selecionadas.

### <a name="download-and-install"></a>Baixar e instalar

1. Para baixar o instalador mais recente do Visual Studio 2017 para Windows, acesse a página Microsoft Visual Studio [downloads mais antigos](https://www.visualstudio.com/vs/older-downloads/) . Expanda a seção **2017** e escolha o botão **baixar** .

   >[!Tip]
   > A edição Community é para desenvolvedores individuais, aprendizado em sala de aula, pesquisa acadêmica e desenvolvimento de software livre. Para outros usos, instale o Visual Studio 2017 Professional ou o Visual Studio 2017 Enterprise.

1. Localize o arquivo do instalador que você baixou e execute-o. O arquivo baixado pode ser exibido no navegador, ou você pode encontrá-lo na pasta downloads. O instalador precisa de privilégios de administrador para ser executado. Você pode ver uma caixa de diálogo **controle de conta de usuário** solicitando que você Conceda permissão para permitir que o instalador faça alterações no seu sistema; escolha **Sim**. Se você estiver com problemas, localize o arquivo baixado no explorador de arquivos, clique com o botão direito do mouse no ícone do instalador e escolha **Executar como administrador** no menu de contexto.

   ![Baixar e instalar o Instalador do Visual Studio](media/vscpp-concierge-run-installer.gif "Baixar e instalar o Instalador do Visual Studio")

1. O instalador apresenta uma lista de cargas de trabalho, que são grupos de opções relacionadas para áreas de desenvolvimento específicas. O suporte para C++ agora faz parte das cargas de trabalho opcionais que não estão instaladas por padrão.

   ![Desenvolvimento de desktop com carga de trabalho de C++](media/desktop-development-with-cpp.png "Desenvolvimento para desktop com C++")

   Para C e C++, selecione o **desenvolvimento de desktop com carga de trabalho C++** e, em seguida, escolha **instalar**.

   ![Instalar o desenvolvimento de desktop com carga de trabalho de C++](media/vscpp-concierge-choose-workload.gif "Instalar o desenvolvimento de desktop com carga de trabalho de C++")

1. Quando a instalação for concluída, escolha o botão **Iniciar** para iniciar o Visual Studio.

   Na primeira vez que você executar o Visual Studio, será solicitado que você entre com uma conta da Microsoft. Se não tiver uma, poderá criá-la gratuitamente. Você também deve escolher um tema. Não se preocupe, você poderá alterá-lo mais tarde, se desejar.

   Pode levar alguns minutos para que o Visual Studio fique pronto para uso na primeira vez que você executá-lo. Aqui está o que se parece em um lapso de tempo rápido:

   ![Entrada do Visual Studio 2017](media/vscpp-quickstart-first-run.gif "Entrada do Visual Studio 2017")

   O Visual Studio começa muito mais rapidamente quando você o executa novamente.

1. Quando o Visual Studio for aberto, verifique se o ícone de sinalizador na barra de título está realçado:

   ![Sinalizador de notificação do Visual Studio 2017](media/vscpp-first-start-page-flag.png "Sinalizador de notificação do Visual Studio 2017")

   Se ele estiver realçado, selecione-o para abrir a janela **notificações** . Se houver alguma atualização disponível para o Visual Studio, recomendamos instalá-las agora. Quando a instalação for concluída, reinicie o Visual Studio.

::: moniker-end

::: moniker range="<msvc-150"

## <a name="visual-studio-2015-installation"></a>Instalação do Visual Studio 2015

Para instalar o Visual Studio 2015, vá para a página Microsoft Visual Studio [downloads mais antigos](https://www.visualstudio.com/vs/older-downloads/) . Expanda a seção **2015** e escolha o botão **baixar** . Execute o programa de instalação baixado e escolha **instalação personalizada** e, em seguida, escolha o componente C++. Para adicionar suporte a C e C++ a uma instalação existente do Visual Studio 2015, clique no botão Iniciar do Windows e digite **Adicionar remover programas**. Abra o programa na lista de resultados e localize a instalação do Visual Studio 2015 na lista de programas instalados. Clique duas vezes nele, escolha **Modificar** e selecione a Visual C++ componentes a serem instalados.

Em geral, é altamente recomendável que você use a versão mais recente do Visual Studio mesmo se precisar compilar seu código usando o compilador do Visual Studio 2015. Para obter mais informações, consulte [Usar a multiplataforma nativa no Visual Studio para compilar projetos antigos](../porting/use-native-multi-targeting.md).

::: moniker-end

Quando o Visual Studio estiver em execução, você estará pronto para continuar para a próxima etapa.

## <a name="next-steps"></a>Próximas etapas

> [!div class="nextstepaction"]
> [Criar um projeto C++](vscpp-step-1-create.md)

<iframe src="" height="0" width="0" frameborder="0" name="frameTarget" />
