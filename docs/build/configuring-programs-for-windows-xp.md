---
title: Configurando programas para Windows XP
ms.date: 02/02/2018
ms.assetid: 1e4487b3-d815-4123-878b-5718b22f0fd5
ms.openlocfilehash: 989a4e2c7e91c05498902bf1c5cb9d838ee47c3b
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57814287"
---
# <a name="configuring-programs-for-windows-xp"></a>Configurando programas para Windows XP

Como o Visual Studio oferece suporte a vários conjuntos de ferramentas de plataforma, você pode direcionar os sistemas operacionais e bibliotecas de tempo de execução que não têm suporte pelo conjunto de ferramentas padrão. Por exemplo, alternando o conjunto de ferramentas de plataforma, você pode usar o c++11, c++14 e aprimoramentos de linguagem C + + 17 suportados pelo compilador MSVC no Visual Studio para criar aplicativos destinados ao Windows XP e Windows Server 2003. Você pode também usar conjuntos de ferramentas de plataforma mais antigos para manter o código herdado de compatíveis com o binário e ainda aproveitar os recursos mais recentes do IDE do Visual Studio.

## <a name="install-the-windows-xp-platform-toolset"></a>Instalar o conjunto de ferramentas de plataforma do Windows XP

Para obter o conjunto de ferramentas de plataforma e componentes de destino Windows XP e Windows Server 2003 no Visual Studio 2017, execute o instalador do Visual Studio. Quando você instala o Visual Studio inicialmente ou quando você escolhe **Modify** para modificar uma instalação existente, certifique-se de que o **desenvolvimento para Desktop com C++** carga de trabalho é selecionada. Na lista de componentes opcionais para essa carga de trabalho, escolha **suporte do Windows XP para C++** e, em seguida, escolha **instalar** ou **modificar**.

## <a name="windows-xp-targeting-experience"></a>XP do Windows visando a experiência

O conjunto de ferramentas da plataforma Windows XP que está incluído no Visual Studio é uma versão do SDK do Windows 7, mas usa o compilador C++ atual. Ele também configura as propriedades do projeto para valores padrão apropriados, por exemplo, a especificação de um vinculador compatível para o direcionamento de nível inferior. Apenas os aplicativos da área de trabalho Windows que são criados usando um conjunto de ferramentas da plataforma Windows XP executado no Windows XP e Windows Server 2003, mas esses aplicativos também podem executar em sistemas de operacionais mais recentes do Windows.

#### <a name="to-target-windows-xp"></a>Para ter como destino o Windows XP

1. No **Gerenciador de Soluções**, abra o menu de atalho do projeto e escolha **Propriedades**.

1. No **páginas de propriedades** caixa de diálogo do projeto, em **propriedades de configuração** > **geral**, defina o **doconjuntodeferramentasdeplataforma** propriedade para o conjunto de ferramentas desejado do Windows XP. Por exemplo, escolha **Visual Studio 2017 – Windows XP (v141_xp)** para criar o código para o Windows XP e Windows Server 2003 usando o compilador Microsoft Visual C++ 2017.

### <a name="c-runtime-support"></a>Suporte de tempo de execução do C++

Juntamente com o conjunto de ferramentas de plataforma do Windows XP, a biblioteca de tempo de execução C (CRT), biblioteca padrão C++, ATL Active Template Library (), biblioteca de tempo de execução de simultaneidade (ConCRT), biblioteca de padrões paralelos (PPL), Microsoft Foundation Class Library (MFC) e C++ AMP (C++ Aceleradas programação maciça) biblioteca incluem o suporte de tempo de execução para Windows XP e Windows Server 2003. Para esses sistemas operacionais, as versões mínimas com suporte são Windows XP Service Pack 3 (SP3) para x86, Windows XP Service Pack 2 (SP2) para x64 e Windows Server 2003 Service Pack 2 (SP2) para x86 e x64.

Essas bibliotecas são suportadas pelos conjuntos de ferramentas de plataforma instalados pelo Visual Studio, dependendo do destino:

|Biblioteca|Padrão de conjunto de ferramentas direcionamento Windows da área de trabalho aplicativos de plataforma|Aplicativos de Store de direcionamento da conjunto de ferramentas de plataforma padrão|Conjunto de ferramentas da plataforma Windows XP visando o Windows XP, Windows Server 2003|
|---|---|---|---|
|CRT|X|X|X|
|Biblioteca Padrão C++|X|X|X|
|ATL|X|X|X|
|ConCRT/PPL|X|X|X|
|MFC|X||X|
|C++ AMP|X|X||

> [!NOTE]
> Aplicativos que são escritos em C + + c++ CLI e o destino do .NET Framework 4 são executados no Windows XP e Windows Server 2003.

### <a name="differences-between-the-toolsets"></a>Diferenças entre os conjuntos de ferramentas

Devido às diferenças no suporte de plataforma e de biblioteca, a experiência de desenvolvimento para aplicativos que usam um conjunto de ferramentas de plataforma do Windows XP não é completa para aplicativos que usam o conjunto de ferramentas da plataforma Visual Studio padrão.

- **Recursos da linguagem C++**

   Somente recursos da linguagem C++ implementados no Visual Studio 2012 têm suporte em aplicativos que usam o v110\_xp conjunto de ferramentas da plataforma. Somente recursos da linguagem C++ implementados no Visual Studio 2013 têm suporte em aplicativos que usam o v120\_xp conjunto de ferramentas da plataforma. Somente recursos da linguagem C++ implementados no Visual Studio 2015 têm suporte em aplicativos que usam o v140\_xp conjunto de ferramentas da plataforma. Visual Studio usa o compilador correspondente quando ele é compilado usando os conjuntos de ferramentas de plataforma mais antigos. Use o conjunto de ferramentas plataforma mais recente do Windows XP para tirar proveito dos recursos da linguagem C++ adicionais implementado nessa versão do compilador.

- **Depuração remota**

   Ferramentas remotas para Visual Studio não dá suporte a depuração remota no Windows XP ou Windows Server 2003. Para depurar um aplicativo quando ele está em execução no Windows XP ou Windows Server 2003, você pode usar um depurador de uma versão anterior do Visual Studio para depurá-lo localmente ou remotamente. Isso é semelhante a experiência de depuração de um aplicativo no Windows Vista, que é um destino de tempo de execução do conjunto de ferramentas de plataforma, mas não é um destino de depuração remoto.

- **Análise estática**

   Os conjuntos de ferramentas de plataforma do Windows XP não oferecem suporte a análise estática porque as anotações de SAL para o SDK do Windows 7 e as bibliotecas de tempo de execução são incompatíveis. Quando você deseja executar uma análise estática em um aplicativo que dá suporte ao Windows XP ou Windows Server 2003, você pode alternar temporariamente a solução para o conjunto de ferramentas de plataforma padrão para executar a análise de destino e, em seguida, alterne para o conjunto de ferramentas da plataforma Windows XP para criar o aplicativo.

- **Depuração de gráficos do DirectX**

   Porque o depurador de gráficos não oferece suporte a API do Direct3D 9, ele não pode ser usado para depurar aplicativos que usam o Direct3D no Windows XP ou Windows Server 2003. No entanto, se o aplicativo implementa um renderizador alternativo que usa o Direct3D 10 ou as APIs do Direct3D 11, o depurador de gráficos pode ser usado para diagnosticar problemas com o uso dessas APIs.

- **Construção HLSL**

   Por padrão, o conjunto de ferramentas do Windows XP não compila arquivos de código-fonte HLSL. Para compilar arquivos HLSL, baixe e instale de junho de 2010 SDK do DirectX e defina o projeto do VC diretórios para incluí-lo. Para obter mais informações, consulte o "SDK do DirectX não registra os caminhos de inclusão ou a biblioteca com o Visual Studio 2010" seção o [junho de 2010 página de download do SDK do DirectX](http://www.microsoft.com/download/details.aspx?displaylang=en&id=6812).
