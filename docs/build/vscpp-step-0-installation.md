---
title: Instalar o suporte ao C++ no Visual Studio
description: Instale o suporte do Visual Studio para Visual C++
ms.custom: mvc
ms.date: 04/02/2019
ms.topic: tutorial
ms.devlang: cpp
ms.assetid: 45138d70-719d-42dc-90d7-1d0ca31a2f54
ms.openlocfilehash: d3018bef9254a8eab557057c035cde84310a2452
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81335361"
---
# <a name="install-c-support-in-visual-studio"></a>Instalar o suporte ao C++ no Visual Studio

Se você ainda não baixou e instalou o Visual Studio e as ferramentas Visual C+++, veja como começar.

::: moniker range="vs-2019"

## <a name="visual-studio-2019-installation"></a>Instalação do Visual Studio 2019

Bem-vindo ao Visual Studio 2019. Nesta versão, é fácil escolher e instalar apenas os recursos que você precisa. E, devido a seu volume mínimo reduzido, ele é instalado rapidamente e com menos impacto no sistema.

> [!NOTE]
> Este tópico se aplica à instalação do Visual Studio no Windows. [Visual Studio Code](https://code.visualstudio.com/) é um ambiente leve de desenvolvimento multiplataforma que funciona em sistemas Windows, Mac e Linux. A extensão Microsoft [C/C++ for Visual Studio Code](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) suporta IntelliSense, depuração, formatação de código, preenchimento automático. O Visual Studio for Mac não suporta o Microsoft C++, mas suporta idiomas .NET e desenvolvimento multiplataforma. Para obter instruções de instalação, consulte [Instalar o Visual Studio para Mac](/visualstudio/mac/installation/).

Quer saber mais sobre quais são as outras novidades nesta versão? Veja as [notas de lançamento](/visualstudio/releases/2019/release-notes/)do Visual Studio.

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

   - **vs_community.exe** para Visual Studio Community
   - **vs_professional.exe** para Visual Studio Professional
   - **vs_enterprise.exe** para Visual Studio Enterprise

   Se você receber um aviso de Controle de Conta de Usuário, escolha **Sim**.

1. Pedimos que você reconheça os Termos de [Licença](https://visualstudio.microsoft.com/license-terms/) da Microsoft e a [Declaração](https://privacy.microsoft.com/privacystatement)de Privacidade da Microsoft. Escolha **Continuar**.

### <a name="step-4---choose-workloads"></a>Etapa 4 – escolher cargas de trabalho

Depois que o instalador for instalado, você pode usá-lo para personalizar sua instalação selecionando as cargas de trabalho ou *conjuntos*de recursos que você deseja. Veja como.

1. Encontre a carga de trabalho desejada na tela **Instalando o Visual Studio**.

   ![Visual Studio 2019: Instale uma carga de trabalho](../get-started/media/vs-installer-workloads.png)

   Para obter suporte ao C++ principal, escolha a carga de trabalho "Desenvolvimento de desktop com C++". Ela vem com o editor de núcleo padrão, que inclui o suporte à edição de código básico para mais de 20 linguagens, a capacidade de abrir e editar o código de qualquer pasta sem precisar de um projeto e o controle do código-fonte integrado.

   Cargas de trabalho adicionais suportam outros tipos de desenvolvimento C++. Por exemplo, escolha a carga de trabalho "Universal Windows Platform" para criar aplicativos que usam o Windows Runtime para a Microsoft Store. Escolha "Desenvolvimento de jogos com C++" para criar jogos que usam DirectX, Unreal e Cocos2d. Escolha "Desenvolvimento Linux com C++" para segmentar plataformas Linux, incluindo desenvolvimento de IoT.

   O painel **De instalação lista** os componentes incluídos e opcionais instalados por cada carga de trabalho. Você pode selecionar ou desmarcar componentes opcionais nesta lista. Por exemplo, para apoiar o desenvolvimento usando os conjuntos de ferramentas do compilador Visual Studio 2017 ou 2015, escolha os componentes opcionais MSVC v141 ou MSVC v140. Você pode adicionar suporte para MFC, a extensão de linguagem de módulos experimentais, IncrediBuild e muito mais.

1. Depois de escolher a carga de trabalho e os componentes opcionais que deseja, escolha **Instalar**.

   Em seguida, serão exibidas telas de status que mostram o progresso da instalação do Visual Studio.

> [!TIP]
> A qualquer momento após a instalação, você pode instalar as cargas de trabalho ou os componentes não instalados inicialmente. Se você tiver o Visual Studio aberto, vá para **Tools** > **Get Tools and Features...** que abre o Visual Studio Installer. Outra opção é abrir o **Instalador do Visual Studio** no menu Iniciar. Assim, é possível escolher as cargas de trabalho ou os componentes que você deseja instalar. Em seguida, escolha **Modificar**.

### <a name="step-5---choose-individual-components-optional"></a>Etapa 5 – escolher componentes individuais (opcional)

Se você não quiser usar o recurso Cargas de Trabalho para personalizar sua instalação do Visual Studio ou quiser adicionar mais componentes do que uma carga de trabalho instalada, você pode fazê-lo instalando ou adicionando componentes individuais da guia **Componentes Individuais.** Escolha o que deseja e siga as instruções.

  ![Visual Studio 2019 - Instalar componentes individuais](../get-started/media/vs-installer-individual-components.png "Instale componentes individuais do Visual Studio")

### <a name="step-6---install-language-packs-optional"></a>Etapa 6 - Instalar pacotes de idiomas (opcional)

Por padrão, o programa do instalador tenta encontrar a correspondência do idioma do sistema operacional quando ele é executado pela primeira vez. Para instalar o Visual Studio em um idioma de sua escolha, escolha a guia **Pacotes de idioma** do Instalador do Visual Studio e siga os prompts.

  ![Visual Studio 2019 - Instale pacotes de idiomas](../get-started/media/vs-installer-language-packs.png "Instale pacotes de idiomas do Visual Studio")

#### <a name="change-the-installer-language-from-the-command-line"></a>Alterar o idioma de instalação da linha de comando

Outra maneira de alterar o idioma padrão é executar o instalador a partir da linha de comando. Por exemplo, é possível forçar o instalador a ser executado em inglês usando o seguinte comando: `vs_installer.exe --locale en-US`. O instalador lembrará desta configuração quando for executada da próxima vez. O instalador dá suporte aos seguintes tokens de idioma: zh-cn, zh-tw, cs-cz, en-us, es-es, fr-fr, de-de, it-it, ja-jp, ko-kr, pl-pl, pt-br, ru-ru e tr-tr.

### <a name="step-7---change-the-installation-location-optional"></a>Etapa 7 – Alterar o local de instalação (opcional)

Você pode reduzir o volume de instalação do Visual Studio na unidade do sistema. Você pode optar por mover o cache de download, os componentes compartilhados, os SDKs e as ferramentas para unidades diferentes e manter o Visual Studio na unidade que executá-los com mais rapidez.

  ![Visual Studio 2019 - Mudar locais de instalação](../get-started/media/vs-installer-installation-locations.png "Alterar o local de instalação")

> [!IMPORTANT]
> Você pode selecionar uma unidade diferente apenas quando você instala o Visual Studio pela primeira vez. Se você já tiver instalado e quiser alterar unidades, precisará desinstalar o Visual Studio e, em seguida, reinstalá-lo.

### <a name="step-8---start-developing"></a>Etapa 8 – Começar a desenvolver

1. Após a conclusão da instalação do Visual Studio, escolha o botão **Iniciar** para ver a introdução ao desenvolvimento com o Visual Studio.

1. Na janela inicial, escolha **Criar um novo projeto**.

1. Na caixa de pesquisa, insira o tipo de aplicativo que deseja criar para ver uma lista de modelos disponíveis. A lista de modelos depende das cargas de trabalho escolhidas durante a instalação. Para ver os diferentes modelos, escolha diferentes cargas de trabalho.

   Você também pode filtrar sua pesquisa para uma linguagem de programação específica usando a lista suspensa **Linguagem de programação**. Você também pode filtrar usando as listas **Plataforma** e **Tipo de projeto**.

1. O Visual Studio abre seu novo projeto e você está pronto para codificar!

::: moniker-end

::: moniker range="<=vs-2017"

## <a name="visual-studio-2017-installation"></a>Instalação do Visual Studio 2017

No Visual Studio 2017, é fácil escolher e instalar apenas os recursos que você precisa. E, devido a seu volume mínimo reduzido, ele é instalado rapidamente e com menos impacto no sistema.

### <a name="prerequisites"></a>Pré-requisitos

- Uma conexão de internet de banda larga. O instalador do Visual Studio pode baixar vários gigabytes de dados.

- Um computador que executa o Microsoft Windows 7 ou versões posteriores. Recomendamos o Windows 10 para obter a melhor experiência de desenvolvimento. Certifique-se de que as últimas atualizações sejam aplicadas ao seu sistema antes de instalar o Visual Studio.

- Espaço em disco suficiente. O Visual Studio requer pelo menos 7 GB de espaço em disco, e pode levar 50 GB ou mais se muitas opções comuns estiverem instaladas. Recomendamos instalá-lo em sua unidade C: drive.

Para obter detalhes sobre os requisitos do espaço em disco e do sistema operacional, consulte [os requisitos do sistema familiar de produtos do Visual Studio](/visualstudio/productinfo/vs2017-system-requirements-vs). O instalador informa quanto espaço em disco é necessário para as opções selecionadas.

### <a name="download-and-install"></a>Fazer o download e instalar

1. Baixe o mais recente instalador visual studio 2017 para Windows.

   > [!div class="nextstepaction"]
   > [Instalar Visual Studio 2017 Community](https://visualstudio.microsoft.com/downloads/?utm_medium=microsoft&utm_source=docs.microsoft.com&utm_campaign=button+cta&utm_content=download+vs2017)

   >[!Tip]
   > A edição Community é para desenvolvedores individuais, aprendizado em sala de aula, pesquisa acadêmica e desenvolvimento de software livre. Para outros usos, instale o [Visual Studio 2017 Professional](https://visualstudio.microsoft.com/downloads/?utm_medium=microsoft&utm_source=docs.microsoft.com&utm_campaign=button+cta&utm_content=download+vs2017) ou o [Visual Studio 2017 Enterprise](https://visualstudio.microsoft.com/downloads/?utm_medium=microsoft&utm_source=docs.microsoft.com&utm_campaign=button+cta&utm_content=download+vs2017).

1. Encontre o arquivo instalador que você baixou e execute-o. Ele pode ser exibido no seu navegador, ou você pode encontrá-lo em sua pasta Downloads. O instalador precisa de privilégios de administrador para ser executado. Você pode ver uma caixa de diálogo **Controle de Conta** de Usuário pedindo que você dê permissão para permitir que o instalador faça alterações no seu sistema; escolher **Sim**. Se você estiver tendo problemas, encontre o arquivo baixado no File Explorer, clique com o botão direito do mouse no ícone do instalador e escolha **Executar como Administrador** no menu de contexto.

   ![Baixe e instale o Visual Studio Installer](media/vscpp-concierge-run-installer.gif "Baixe e instale o Visual Studio Installer")

1. O instalador apresenta uma lista de cargas de trabalho, que são grupos de opções relacionadas para áreas de desenvolvimento específicas. O suporte ao C++ agora faz parte de cargas de trabalho opcionais que não são instaladas por padrão.

   ![Desenvolvimento de desktop com carga de trabalho C++](media/desktop-development-with-cpp.png "Desenvolvimento para desktop com C++")

   Para C++, selecione o desenvolvimento da área de trabalho com carga de trabalho **C++** e, em seguida, escolha **Instalar**.

   ![Instale o desenvolvimento do desktop com carga de trabalho C++](media/vscpp-concierge-choose-workload.gif "Instale o desenvolvimento do desktop com carga de trabalho C++")

1. Quando a instalação for concluída, escolha o botão **Iniciar** para iniciar o Visual Studio.

   A primeira vez que você executa o Visual Studio, você é solicitado a fazer login com uma conta Microsoft. Se não tiver uma, poderá criá-la gratuitamente. Você também deve escolher um tema. Não se preocupe, pode mudá-lo mais tarde, se quiser.

   O Visual Studio pode levar vários minutos para se preparar para usar na primeira vez que você executá-lo. Aqui está o que parece em um rápido lapso de tempo:

   ![Visual Studio 2017 faça login](media/vscpp-quickstart-first-run.gif "Visual Studio 2017 faça login")

   O Visual Studio começa muito mais rápido quando você executá-lo novamente.

1. Quando o Visual Studio for aberto, verifique se o ícone da bandeira na barra de título está destacado:

   ![Bandeira de notificação do Visual Studio 2017](media/vscpp-first-start-page-flag.png "Bandeira de notificação do Visual Studio 2017")

   Se estiver destacado, selecione-o para abrir a janela **Notificações.** Se houver alguma atualização disponível para o Visual Studio, recomendamos instalá-las agora. Assim que a instalação estiver concluída, reinicie o Visual Studio.

::: moniker-end

::: moniker range="<vs-2017"

## <a name="visual-studio-2015-installation"></a>Instalação do Visual Studio 2015

Para instalar o Visual Studio 2015, acesse [Baixar versões mais antigas do Visual Studio](https://www.visualstudio.com/vs/older-downloads/). Execute o programa de instalação, escolha **Instalação personalizada** e, em seguida, selecione o componente C++. Para adicionar suporte c++ a uma instalação existente do Visual Studio 2015, clique no botão Iniciar do Windows e **digite Adicionar programas**de remoção . Abra o programa na lista de resultados e, em seguida, encontre sua instalação do Visual Studio 2015 na lista de programas instalados. Clique duas vezes e **selecione Modificar** e selecione os componentes Visuais C++ para instalar.

Em geral, é altamente recomendado que você use o Visual Studio 2017, mesmo que você precise compilar o código com o compilador do Visual Studio 2015. Para obter mais informações, consulte [Usar a multiplataforma nativa no Visual Studio para compilar projetos antigos](../porting/use-native-multi-targeting.md).

::: moniker-end

Quando o Visual Studio estiver funcionando, você está pronto para continuar até o próximo passo.

## <a name="next-steps"></a>Próximas etapas

> [!div class="nextstepaction"]
> [Crie um projeto C++](vscpp-step-1-create.md)

<iframe src="" height="0" width="0" frameborder="0" name="frameTarget" />
