---
title: Como configurar programas para o Windows XP
description: Como instalar e usar os conjuntos C++ de ferramentas do Windows XP no Visual Studio.
ms.date: 03/16/2020
ms.assetid: 1e4487b3-d815-4123-878b-5718b22f0fd5
ms.openlocfilehash: 92364d7fd25ac617baacc125b279fb0ee9c92f62
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79440473"
---
# <a name="configuring-programs-for-windows-xp"></a>Como configurar programas para o Windows XP

O Visual Studio dá suporte a vários conjuntos de ferramentas de plataforma. Isso significa que é possível direcionar sistemas operacionais e bibliotecas de tempo de execução que não são compatíveis com o conjunto de ferramentas padrão. Por exemplo, alternando o conjunto de ferramentas de plataforma, você pode usar o C++ compilador do Visual Studio 2017 para criar aplicativos destinados ao Windows XP e ao windows Server 2003. Use também conjuntos de ferramentas da plataforma mais antigos para manter o código herdado compatível com o binário e ainda aproveitar as funcionalidades mais recentes do IDE do Visual Studio.

::: moniker range="vs-2019"

O conjunto de ferramentas v142 fornecido no Visual Studio 2019 não inclui suporte para a criação de código para o Windows XP. O suporte para o desenvolvimento do Windows XP usando o conjunto de ferramentas de v141_xp do Visual Studio 2017 está disponível como uma opção de componente individual na Instalador do Visual Studio.

::: moniker-end

## <a name="install-the-windows-xp-platform-toolset"></a>Instalar o Conjunto de ferramentas da plataforma do Windows XP

::: moniker range="<=vs-2017"

Para obter o conjunto de ferramentas e os componentes da plataforma Visual Studio 2017 para direcionar para o Windows XP e o Windows Server 2003, execute o Instalador do Visual Studio. Ao instalar inicialmente o Visual Studio ou quando você modificar uma instalação existente, verifique se o **desenvolvimento de área C++ de trabalho com** carga de trabalho está selecionado. Na lista de componentes opcionais para essa carga de trabalho, escolha **Suporte do Windows XP para C++** e, em seguida, escolha **Instalar** ou **Modificar**.

::: moniker-end

::: moniker range="vs-2019"

Para obter o conjunto de ferramentas e os componentes da plataforma v141_xp para o Windows XP e o Windows Server 2003 de destino, execute o Instalador do Visual Studio. Ao instalar inicialmente o Visual Studio, ou quando você modificar uma instalação existente, verifique se o **desenvolvimento de área C++ de trabalho com** carga de trabalho está selecionado. Na guia **componentes individuais** , em **compiladores, ferramentas de compilação e tempos de execução**, escolha  **C++ suporte do Windows XP para ferramentas do vs 2017 (v141) \[preterido]** e, em seguida, escolha **instalar** ou **Modificar**.

::: moniker-end

## <a name="windows-xp-targeting-experience"></a>Experiência de direcionamento do Windows XP

O conjunto de ferramentas da plataforma Windows XP que está incluído no Visual Studio é uma versão do SDK do Windows 7, mas usa o compilador C++ do visual Studio 2017. Ele também configura as propriedades do projeto para valores padrão apropriados, por exemplo, a especificação de um vinculador compatível para o direcionamento de nível inferior. Somente os aplicativos da área de trabalho do Windows criados com o uso de um conjunto de ferramentas da plataforma Windows XP podem ser executados no Windows XP e no Windows Server 2003. Esses aplicativos também podem ser executados em sistemas operacionais Windows mais recentes.

### <a name="to-target-windows-xp"></a>Para direcionamento ao Windows XP

1. No **Gerenciador de Soluções**, abra o menu de atalho do projeto e escolha **Propriedades**.

1. Na caixa de diálogo **páginas de propriedades** do projeto, selecione **propriedades de configuração** > **geral**. Defina a propriedade do **conjunto de ferramentas da plataforma** para o seu conjunto de ferramentas do Windows XP preferencial. Por exemplo, escolha **Visual Studio 2017 – Windows XP (v141_xp)** para criar o código para o Windows XP e o Windows Server 2003 usando o compilador do Microsoft C++ no Visual Studio 2017.

### <a name="c-runtime-support"></a>Suporte de runtime do C++

Juntamente com o conjunto de ferramentas da plataforma Windows XP, várias bibliotecas incluem suporte ao tempo de execução para o Windows XP e o Windows Server 2003. Essas bibliotecas são: a biblioteca de tempo de execução C ( C++ CRT), a biblioteca padrão, a Active Template Library (ATL), a biblioteca de tempo de execução de simultaneidade (ConCRT), a PPL (biblioteca de padrões C++ paralelosC++ ), a MFC (biblioteca MFC) e a biblioteca de amp (grande programação maciça). Para esses sistemas operacionais, as versões mínimas com suporte são: Windows XP Service Pack 3 (SP3) para x86, Windows XP Service Pack 2 (SP2) para x64 e Windows Server 2003 Service Pack 2 (SP2) para x86 e x64.

Há suporte para essas bibliotecas nos conjuntos de ferramentas da plataforma instalados pelo Visual Studio, dependendo do destino:

|Biblioteca|Conjunto de ferramentas da plataforma padrão direcionado a aplicativos da área de trabalho do Windows|Conjunto de ferramentas da plataforma padrão direcionado a aplicativos da Store|Conjunto de ferramentas da plataforma do Windows XP direcionado ao Windows XP e ao Windows Server 2003|
|---|---|---|---|
|CRT|X|X|X|
|Biblioteca Padrão C++|X|X|X|
|ATL|X|X|X|
|ConCRT/PPL|X|X|X|
|MFC|X||X|
|C++ AMP|X|X||

> [!NOTE]
> Os aplicativos que são escritos em C++/CLI direcionados ao .NET Framework 4 são executados no Windows XP e no Windows Server 2003.

### <a name="differences-between-the-toolsets"></a>Diferenças entre os conjuntos de ferramentas

Devido a diferenças no suporte à plataforma e à biblioteca, a experiência de desenvolvimento para aplicativos que usam um conjunto de ferramentas de plataforma do Windows XP não é tão completa quanto para aplicativos que usam o conjunto de ferramentas de plataforma do Visual Studio padrão.

- **Funcionalidades da linguagem C++**

   Há suporte apenas para as funcionalidades da linguagem C++ implementadas no Visual Studio 2012 em aplicativos que usam o Conjunto de ferramentas da plataforma v110\_xp. Há suporte apenas para as funcionalidades da linguagem C++ implementadas no Visual Studio 2013 em aplicativos que usam o Conjunto de ferramentas da plataforma v120\_xp. Há suporte apenas para as funcionalidades da linguagem C++ implementadas no Visual Studio 2015 em aplicativos que usam o Conjunto de ferramentas da plataforma v140\_xp. Somente C++ os recursos de linguagem implementados no Visual Studio 2017 têm suporte em aplicativos que usam o conjunto de ferramentas de plataforma v141\_XP. O Visual Studio usa o compilador correspondente quando faz a compilação usando os conjuntos de ferramentas da plataforma mais antigos. Use o Conjunto de ferramentas da plataforma mais recente do Windows XP para aproveitar funcionalidades da linguagem C++ adicionais implementadas nessa versão do compilador.

- **Depuração remota**

   As Ferramentas Remotas para Visual Studio não dão suporte à depuração remota no Windows XP nem no Windows Server 2003. Para depurar um aplicativo local ou remotamente no Windows XP ou no Windows Server 2003, use um depurador de uma versão mais antiga do Visual Studio. É semelhante a depurar um aplicativo no Windows Vista, que é um destino de tempo de execução do conjunto de ferramentas da plataforma, mas não um destino de depuração remota.

- **Análise estática**

   Os Conjuntos de ferramentas da plataforma do Windows XP não dão suporte à análise estática, porque as anotações de SAL para o SDK do Windows 7 e as bibliotecas de runtime são incompatíveis. Você ainda pode executar a análise estática em um aplicativo que dá suporte ao Windows XP ou ao Windows Server 2003. Alterne temporariamente a solução para direcionar o conjunto de ferramentas de plataforma padrão para a análise e, em seguida, volte para o conjunto de ferramentas da plataforma Windows XP para compilar o aplicativo.

- **Como depurar elementos gráficos DirectX**

   Como o depurador de gráficos não dá suporte à API do Direct3D 9, ele não pode ser usado para depurar aplicativos que usam o Direct3D no Windows XP ou no Windows Server 2003. No entanto, se o aplicativo implementar um renderizador alternativo baseado em APIs do Direct3D 10 ou Direct3D 11, você poderá usar o depurador de gráficos para diagnosticar problemas.

- **Como compilar o HLSL**

   Por padrão, o conjunto de ferramentas do Windows XP não compila arquivos de código-fonte do HLSL. Para compilar arquivos HLSL, baixe e instale o SDK do DirectX de junho de 2010 e, em seguida, defina os diretórios VC do projeto para incluí-lo. Para obter mais informações, confira a seção "O SDK do DirectX não registra os caminhos de inclusão/biblioteca no Visual Studio 2010" da [página de download do SDK do DirectX de junho de 2010](https://www.microsoft.com/download/details.aspx?displaylang=en&id=6812).
