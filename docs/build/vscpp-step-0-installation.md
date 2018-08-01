---
title: Instalar o suporte do C++ no Visual Studio | Microsoft Docs
description: Instalar o suporte do Visual Studio para o Visual C++
ms.custom: mvc
ms.date: 06/21/2018
ms.topic: tutorial
ms.technology:
- devlang-C++
ms.devlang: C++
dev_langs:
- C++
ms.assetid: 45138d70-719d-42dc-90d7-1d0ca31a2f54
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3cc9c124a5b3f2fea92f729d7d11df579cc25a39
ms.sourcegitcommit: bad2441d1930275ff506d44759d283d94cccd1c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/31/2018
ms.locfileid: "39376032"
---
# <a name="install-c-support-in-visual-studio"></a>Instalar o suporte do C++ no Visual Studio

Se você ainda não tiver baixado e instalado o Visual Studio e as ferramentas do Visual C++ ainda, aqui está como começar.

## <a name="prerequisites"></a>Pré-requisitos

- Uma conexão de internet banda larga. O instalador do Visual Studio pode baixar vários gigabytes de dados.

- Um computador que executa o Microsoft Windows 7 ou versões posteriores. Recomendamos o Windows 10 para uma melhor experiência de desenvolvimento. Certifique-se de que as atualizações mais recentes sejam aplicadas ao seu sistema antes de instalar o Visual Studio.

- Espaço em disco suficiente. Visual Studio requer pelo menos 7GB de espaço em disco e pode levar a 50GB ou mais se muitas das opções comuns estiverem instalados. É recomendável que instalá-lo em sua unidade c:.

Para obter detalhes sobre o espaço em disco e os requisitos do sistema operacional, consulte [requisitos de sistema família do Visual Studio produto](/visualstudio/productinfo/vs2017-system-requirements-vs). O instalador relata quanto espaço em disco é necessário para as opções selecionadas.

## <a name="installation"></a>Instalação

1. Baixe o instalador mais recente do Visual Studio 2017 para Windows.

   > [!div class="nextstepaction"]
   > [Instalar Visual Studio 2017 Community](https://visualstudio.microsoft.com/downloads/?utm_medium=microsoft&utm_source=docs.microsoft.com&utm_campaign=button+cta&utm_content=download+vs2017)

   >[!Tip]
   > A edição Community é para desenvolvedores individuais, aprendizado em sala de aula, pesquisa acadêmica e desenvolvimento de software livre. Para outros usos, instale o <a target="frameTarget" href="https://visualstudio.microsoft.com/downloads/?utm_medium=microsoft&utm_source=docs.microsoft.com&utm_campaign=button+cta&utm_content=download+vs2017">Visual Studio 2017 Professional</a> ou o <a target="frameTarget" href="https://visualstudio.microsoft.com/downloads/?utm_medium=microsoft&utm_source=docs.microsoft.com&utm_campaign=button+cta&utm_content=download+vs2017">Visual Studio 2017 Enterprise</a>.

1. Localize o arquivo do instalador baixado e executá-lo. Ele pode ser exibido em seu navegador, ou você pode encontrá-lo na pasta Downloads. O instalador precisa de privilégios de administrador para ser executado. Você poderá ver uma **User Account Control** caixa de diálogo solicitando que você conceda permissão para permitir que o instalador de fazer alterações ao seu sistema; escolher **Sim**. Se você estiver tendo problemas, localize o arquivo baixado no Explorador de arquivos, clique com botão direito no ícone de instalação e escolha **executar como administrador** no menu de contexto.

   ![Execute o instalador do Visual Studio 2017](../build/media/vscpp-concierge-run-installer.gif "execute o instalador do Visual Studio")

1. O instalador apresenta uma lista de cargas de trabalho, que são grupos de opções relacionadas para áreas de desenvolvimento específicas. Suporte para C++ agora faz parte das cargas de trabalho opcionais que não são instalados por padrão.

   ![Desenvolvimento para desktop com C++](../build/media/desktop-development-with-cpp.png "desenvolvimento para Desktop com C++")

    Para C++, selecione o **desenvolvimento para Desktop com C++** carga de trabalho e, em seguida, escolha **instalar**.

   ![Instalar o desenvolvimento de área de trabalho com carga de trabalho do C++](../build/media/vscpp-concierge-choose-workload.gif "instalar o desenvolvimento de área de trabalho com carga de trabalho do C++")

1. Quando a instalação for concluída, escolha o **inicie** botão para iniciar o Visual Studio.

   Na primeira vez que você executar o Visual Studio, você será solicitado para entrar com uma Account da Microsoft. Se você não tiver uma, você pode criar um gratuitamente. Você também deve escolher um tema. Não se preocupe, você pode alterá-lo mais tarde, se você quiser. 

   Pode levar o Visual Studio vários minutos para preparar para uso na primeira vez que você executá-lo. Aqui está o que ele se parece com um rápido lapso de tempo:

   ![Visual Studio 2017 entrar](../build/media/vscpp-quickstart-first-run.gif "entrar do Visual Studio 2017")

   Visual Studio inicia muito mais rapidamente quando você executá-lo novamente.

1. Quando o Visual Studio é aberto, verifique se o ícone de sinalizador na barra de título é realçado:

   ![Sinalizador de notificação do Visual Studio 2017](../build/media/vscpp-first-start-page-flag.png "sinalizador de notificação do Visual Studio 2017")

   Se ele estiver selecionado, selecione-o para abrir o **notificações** janela. Se houver quaisquer atualizações disponíveis para o Visual Studio, é recomendável que instalá-los agora. Depois que a instalação for concluída, reinicie o Visual Studio.

Quando o Visual Studio está em execução, você estará pronto para continuar para a próxima etapa.

## <a name="next-steps"></a>Próximas etapas

> [!div class="nextstepaction"]
> [Criar um projeto C++](vscpp-step-1-create.md)

<iframe src="" height="0" width="0" frameborder="0" name="frameTarget" />
