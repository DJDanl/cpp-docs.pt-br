---
title: Usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C++
ms.date: 03/14/2019
helpviewer_keywords:
- IDE [C++]
- Visual Studio IDE [C++]
ms.assetid: d985c230-8e81-49d6-92be-2db9cac8d023
ms.openlocfilehash: 7417c46097b1f0c6282e3684a7556880c21be42a
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58773561"
---
# <a name="using-the-visual-studio-ide-for-c-desktop-development"></a>Usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C++

O IDE (Ambiente de Desenvolvimento Integrado) do Visual Studio oferece um conjunto de funcionalidades que ajudam você gerenciar projetos de código grandes e pequenos, escrever e refatorar o código e detectar e corrigir erros usando a análise estática e ferramentas avançadas de depuração. Este conjunto de artigos visa orientá-lo em cada uma das etapas, nas quais você precisará gerenciar seus projetos, escrever, testar, depurar o código e, em seguida, implantá-lo em outro computador.

## <a name="prerequisites"></a>Pré-requisitos

Caso ainda não tenha instalado o Visual Studio, agora é o momento. Para obter os links de download e um passo a passo rápido, confira [Instalar o suporte do C++ no Visual Studio](../build/vscpp-step-0-installation.md). Para obter mais informações de como instalar o Visual Studio em geral e dicas de solução de problemas se algo der errado, confira [Instalar o Visual Studio](/visualstudio/install/install-visual-studio). Escolha a carga de trabalho **Desenvolvimento para desktop com C++** para incluir os compiladores, as ferramentas e as bibliotecas C++ ao instalar o Visual Studio, pois eles não são instalados por padrão.

Estes passos a passos pressupõem que você tenha instalado o Visual Studio e a linguagem Visual C++, bem como os componentes necessários para o desenvolvimento para Área de Trabalho do Windows. Também pressupomos que você conheça os princípios básicos da linguagem C++. Se você precisa aprender a usar o C++, há vários manuais e recursos da Web disponíveis. Um bom lugar para começar é a página [Introdução](https://isocpp.org/get-started) do site Standard C++ Foundation.

Caso ainda não tenha instalado o Visual Studio, agora é o momento.

**Instalação do Visual Studio 2017**

Para obter o Visual Studio 2017, baixe-o de [Downloads do Visual Studio](https://www.visualstudio.com/downloads/download-visual-studio-vs.aspx). Lembre-se de incluir as ferramentas de desenvolvimento do Visual C++ ao instalar o Visual Studio, porque elas não são instaladas por padrão. Para obter mais informações sobre como instalar o Visual Studio, confira [Instalar o Visual Studio](/visualstudio/install/install-visual-studio).

**Instalação do Visual Studio 2015**

Para instalar o Visual Studio 2015, acesse [Baixar versões mais antigas do Visual Studio](https://www.visualstudio.com/vs/older-downloads/). Execute o programa de instalação, escolha **Instalação personalizada** e, em seguida, selecione o componente C++.

Em geral, é altamente recomendado que você use o Visual Studio 2017, mesmo que você precise compilar o código com o compilador do Visual Studio 2015. Para obter mais informações, consulte [Usar a multiplataforma nativa no Visual Studio para compilar projetos antigos](../porting/use-native-multi-targeting.md).

Após a conclusão da instalação do Visual Studio, você estará pronto para continuar.

## <a name="get-started"></a>Introdução

Para começar a usar o IDE do Visual Studio para compilar aplicativos do C++, leia os tópicos a seguir na ordem. Cada um deles baseia-se no trabalho concluído nos tópicos anteriores:

- [Passo a passo: Como trabalhar com Projetos e Soluções (C++)](walkthrough-working-with-projects-and-solutions-cpp.md)

- [Passo a passo: Compilação de um projeto (C++)](walkthrough-building-a-project-cpp.md)

- [Passo a passo: Teste de um projeto (C++)](walkthrough-testing-a-project-cpp.md)

- [Passo a passo: Depurando um projeto (C++)](walkthrough-debugging-a-project-cpp.md)

- [Passo a passo: Implantação do programa (C++)](walkthrough-deploying-your-program-cpp.md)

## <a name="next-steps"></a>Próximas etapas

Depois de concluir esses passos a passos, você estará pronto para começar a criar seus próprios projetos. Para obter mais informações e recursos de desenvolvimento do Visual C++, confira [Visual C++ no Visual Studio](../overview/visual-cpp-in-visual-studio.md).

## <a name="see-also"></a>Consulte também

[Introdução ao desenvolvimento com Visual Studio](/visualstudio/ide/get-started-developing-with-visual-studio)