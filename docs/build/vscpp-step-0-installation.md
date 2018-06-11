---
title: Instalar o suporte do C++ no Visual Studio | Microsoft Docs
description: Instalar o suporte do Visual Studio para Visual C++
ms.custom: mvc
ms.date: 06/08/2018
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
ms.openlocfilehash: 4fd04450b75083152d058aef4a85d83f5635c8d9
ms.sourcegitcommit: 1c2e035f98fb55d9b3c08ec3bb562179a368d0d1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/11/2018
ms.locfileid: "35253750"
---
# <a name="install-c-support-in-visual-studio"></a>Instalar o suporte do C++ no Visual Studio

Se você ainda não tiver baixado e instalado o Visual Studio e as ferramentas do Visual C++, ainda, aqui está como começar.

## <a name="prerequisites"></a>Pré-requisitos

- Uma conexão de internet de banda larga. O instalador do Visual Studio pode baixar vários gigabytes de dados.

- Um computador que executa o Microsoft Windows 7 ou versões posteriores. É recomendável Windows 10 para a melhor experiência de desenvolvimento. Certifique-se de que as atualizações mais recentes são aplicadas ao seu sistema antes de instalar o Visual Studio.

- Espaço livre em disco. Visual Studio requer pelo menos 7GB de espaço em disco e pode levar a 50GB ou mais se muitas das opções comuns são instalados. É recomendável que instalá-lo em sua unidade c:.

Para obter detalhes sobre o espaço em disco e os requisitos de sistema operacional, consulte [requisitos de sistema família do Visual Studio produto](/visualstudio/productinfo/vs2017-system-requirements-vs). O instalador informa a quantidade de espaço em disco é necessário para as opções selecionadas.

## <a name="installation"></a>Instalação

1. Baixe o instalador do Visual Studio de 2017 mais recente para o Windows.

   > [!div class="nextstepaction"]
   > <a target="frameTarget" href="https://www.visualstudio.com/downloads/?utm_medium=microsoft&utm_source=docs.microsoft.com&utm_campaign=button+cta&utm_content=download+vs2017">Instalar Visual Studio 2017 Community</a>

   >[!Tip]
   > A edição Community é para desenvolvedores individuais, aprendizado em sala de aula, pesquisa acadêmica e desenvolvimento de software livre. Para outros usos, instale o <a target="frameTarget" href="https://www.visualstudio.com/downloads/?utm_medium=microsoft&utm_source=docs.microsoft.com&utm_campaign=button+cta&utm_content=download+vs2017">Visual Studio 2017 Professional</a> ou o <a target="frameTarget" href="https://www.visualstudio.com/downloads/?utm_medium=microsoft&utm_source=docs.microsoft.com&utm_campaign=button+cta&utm_content=download+vs2017">Visual Studio 2017 Enterprise</a>.

1. Localize o arquivo do instalador baixado e executá-lo. Ele pode ser exibido no navegador, ou talvez você ache na sua pasta de Downloads. O instalador precisa de privilégios de administrador para executar. Você pode ver um **User Account Control** caixa de diálogo solicitando que você conceda permissão para permitir que o instalador fazer alterações ao seu sistema; escolher **Sim**. Se você estiver tendo problemas, localize o arquivo baixado no Explorador de arquivos, clique no ícone de instalação e escolha **executar como administrador** no menu de contexto.

   ![Execute o instalador do Visual Studio de 2017](../build/media/vscpp-concierge-run-installer.gif "executar o instalador do Visual Studio")

1. O instalador apresenta uma lista de cargas de trabalho, que são grupos de opções relacionadas para áreas de desenvolvimento específicas. Suporte para C++ agora faz parte de cargas de trabalho opcionais que não são instalados por padrão.

   ![Desenvolvimento de área de trabalho com C++](../build/media/desktop-development-with-cpp.png "desenvolvimento de área de trabalho com C++")

    Para C++, selecione o **desenvolvimento de área de trabalho com C++** carga de trabalho e, em seguida, escolha **instalar**.

   ![Instalar o desenvolvimento de área de trabalho com carga de trabalho C++](../build/media/vscpp-concierge-choose-workload.gif "instalar o desenvolvimento de área de trabalho com carga de trabalho do C++")

1. Quando a instalação for concluída, escolha o **iniciar** botão para iniciar o Visual Studio.

   Na primeira vez que você executar o Visual Studio, você será solicitado a entrar com uma Account da Microsoft. Se você não tiver um, você pode criar um gratuitamente. Você também deve escolher um tema. Não se preocupe, você pode alterá-la mais tarde, se você quiser. 

   Pode levar Visual Studio vários minutos para obter pronto para uso na primeira vez que você executá-lo. Aqui está a sua aparência em uma rápida lapso de tempo:

   ![Visual Studio de 2017 entrar](../build/media/vscpp-quickstart-first-run.gif "2017 do Visual Studio entrar")

   Muito mais rápido, o Visual Studio inicia quando você executá-lo novamente.

1. Quando o Visual Studio é aberto, verifique se o ícone de sinalizador na barra de título é realçado:

   ![Sinalizador de notificação do Visual Studio 2017](../build/media/vscpp-first-start-page-flag.png "sinalizador de notificação de 2017 do Visual Studio")

   Se ele estiver selecionado, selecione-o para abrir o **notificações** janela. Se há atualizações disponíveis para o Visual Studio, é recomendável que instalá-los agora. Depois que a instalação for concluída, reinicie o Visual Studio.

Quando o Visual Studio está em execução, você estará pronto para continuar para a próxima etapa.

## <a name="next-steps"></a>Próximas etapas

> [!div class="nextstepaction"]
> [Criar um projeto de C++](vscpp-step-1-create.md)

<iframe src="" height="0" width="0" frameborder="0" name="frameTarget" />
