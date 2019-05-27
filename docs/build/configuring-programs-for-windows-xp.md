---
title: Como configurar programas para o Windows XP
ms.date: 05/16/2019
ms.assetid: 1e4487b3-d815-4123-878b-5718b22f0fd5
ms.openlocfilehash: 6c94c6a66d0f22b8707012856a65df4b19965acb
ms.sourcegitcommit: a10c9390413978d36b8096b684d5ed4cf1553bc8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2019
ms.locfileid: "65837132"
---
# <a name="configuring-programs-for-windows-xp"></a>Como configurar programas para o Windows XP

Como o Visual Studio dá suporte a vários conjuntos de ferramentas da plataforma, você pode direcionar para sistemas operacionais e bibliotecas de tempo de execução sem suporte no conjunto de ferramentas padrão. Por exemplo, alternando o Conjunto de ferramentas da plataforma, você pode usar as melhorias de linguagem C++11, C++14 e C++17 compatíveis com o compilador do MSVC no Visual Studio para criar aplicativos direcionados ao Windows XP e ao Windows Server 2003. Use também conjuntos de ferramentas da plataforma mais antigos para manter o código herdado compatível com o binário e ainda aproveitar as funcionalidades mais recentes do IDE do Visual Studio.

O Visual Studio 2019 e posterior não inclui suporte para criação de código para Windows XP usando o Conjunto de ferramentas v142. O suporte para o desenvolvimento do Windows XP usando o conjunto de ferramentas v141 fornecido no Visual Studio 2017 está disponível como um componente opcional no Instalador do Visual Studio.

## <a name="install-the-windows-xp-platform-toolset"></a>Instalar o Conjunto de ferramentas da plataforma do Windows XP

Para obter o Conjunto de ferramentas da plataforma e os componentes para direcionamento ao Windows XP e ao Windows Server 2003 no Visual Studio 2017, execute o Instalador do Visual Studio. Quando você instalar inicialmente o Visual Studio ou escolher **Modificar** para modificar uma instalação existente, verifique se a carga de trabalho **Desenvolvimento para desktop com C++** está selecionada. Na lista de componentes opcionais para essa carga de trabalho, escolha **Suporte do Windows XP para C++** e, em seguida, escolha **Instalar** ou **Modificar**.

## <a name="windows-xp-targeting-experience"></a>Experiência de direcionamento do Windows XP

O Conjunto de ferramentas da plataforma do Windows XP incluído no Visual Studio é uma versão do SDK do Windows 7, mas usa o compilador do C++ atual. Ele também configura as propriedades do projeto para valores padrão apropriados, por exemplo, a especificação de um vinculador compatível para o direcionamento de nível inferior. Apenas os aplicativos da área de trabalho do Windows que são criados usando um Conjunto de ferramentas da plataforma do Windows XP executado no Windows XP e no Windows Server 2003, mas esses aplicativos também podem ser executados em sistemas operacionais mais recentes do Windows.

#### <a name="to-target-windows-xp"></a>Para direcionamento ao Windows XP

1. No **Gerenciador de Soluções**, abra o menu de atalho do projeto e escolha **Propriedades**.

1. Na caixa de diálogo **Páginas de Propriedades** do projeto, em **Propriedades da Configuração** > **Geral**, defina a propriedade **Conjunto de Ferramentas da Plataforma** com o Conjunto de ferramentas desejado do Windows XP. Por exemplo, escolha **Visual Studio 2017 – Windows XP (v141_xp)** para criar o código para o Windows XP e o Windows Server 2003 usando o compilador do Microsoft C++ no Visual Studio 2017.

### <a name="c-runtime-support"></a>Suporte de tempo de execução do C++

Juntamente com o Conjunto de ferramentas da plataforma do Windows XP, o CRT (Biblioteca em Tempo de Execução C), a Biblioteca Padrão C++, a ATL (Active Template Library), o ConCRT (Biblioteca em Tempo de Execução de Simultaneidade), a PPL (Biblioteca de Padrões Paralelos), o MFC (biblioteca Microsoft Foundation Class) e a biblioteca C++ AMP (C++ Accelerated Massive Programming) incluem o suporte de tempo de execução para o Windows XP e o Windows Server 2003. Para esses sistemas operacionais, as versões mínimas com suporte são Windows XP Service Pack 3 (SP3) para x86, Windows XP Service Pack 2 (SP2) para x64 e Windows Server 2003 Service Pack 2 (SP2) para x86 e x64.

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

Devido às diferenças no suporte de plataforma e biblioteca, a experiência de desenvolvimento para aplicativos que usam um conjunto de ferramentas da plataforma do Windows XP não é completa para aplicativos que usam o Conjunto de ferramentas da plataforma padrão do Visual Studio.

- **Funcionalidades da linguagem C++**

   Há suporte apenas para as funcionalidades da linguagem C++ implementadas no Visual Studio 2012 em aplicativos que usam o Conjunto de ferramentas da plataforma v110\_xp. Há suporte apenas para as funcionalidades da linguagem C++ implementadas no Visual Studio 2013 em aplicativos que usam o Conjunto de ferramentas da plataforma v120\_xp. Há suporte apenas para as funcionalidades da linguagem C++ implementadas no Visual Studio 2015 em aplicativos que usam o Conjunto de ferramentas da plataforma v140\_xp. O Visual Studio usa o compilador correspondente quando faz a compilação usando os conjuntos de ferramentas da plataforma mais antigos. Use o Conjunto de ferramentas da plataforma mais recente do Windows XP para aproveitar funcionalidades da linguagem C++ adicionais implementadas nessa versão do compilador.

- **Depuração remota**

   As Ferramentas Remotas para Visual Studio não dão suporte à depuração remota no Windows XP nem no Windows Server 2003. Para depurar um aplicativo quando ele está em execução no Windows XP ou no Windows Server 2003, use um depurador de uma versão anterior do Visual Studio para depurá-lo local ou remotamente. Isso é semelhante à experiência de depuração de um aplicativo no Windows Vista, que é um destino de tempo de execução do Conjunto de ferramentas da plataforma, mas não é um destino de depuração remota.

- **Análise estática**

   Os Conjuntos de ferramentas da plataforma do Windows XP não dão suporte à análise estática, porque as anotações de SAL para o SDK do Windows 7 e as bibliotecas de tempo de execução são incompatíveis. Quando você desejar executar uma análise estática em um aplicativo que dá suporte ao Windows XP ou ao Windows Server 2003, alterne temporariamente a solução para que ela seja direcionada ao Conjunto de ferramentas da plataforma padrão a fim de executar a análise e, em seguida, alterne novamente para o Conjunto de ferramentas da plataforma do Windows XP para criar o aplicativo.

- **Como depurar elementos gráficos DirectX**

   Como o Depurador de Gráficos não dá suporte à API do Direct3D 9, ele não pode ser usado para depurar aplicativos que usam o Direct3D no Windows XP ou no Windows Server 2003. No entanto, se o aplicativo implementar um renderizador alternativo que use as APIs do Direct3D 10 ou do Direct3D 11, o Depurador de Gráficos poderá ser usado para diagnosticar problemas com o uso dessas APIs.

- **Como compilar o HLSL**

   Por padrão, o Conjunto de ferramentas do Windows XP não compila arquivos de código-fonte HLSL. Para compilar arquivos HLSL, baixe e instale o SDK do DirectX de junho de 2010 e, em seguida, defina os diretórios VC do projeto para incluí-lo. Para obter mais informações, confira a seção "O SDK do DirectX não registra os caminhos de inclusão/biblioteca no Visual Studio 2010" da [página de download do SDK do DirectX de junho de 2010](http://www.microsoft.com/download/details.aspx?displaylang=en&id=6812).
