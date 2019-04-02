---
title: Determinando quais DLLs devem ser redistribuídas
ms.date: 03/25/2019
helpviewer_keywords:
- redistributing DLLs
- DLLs [C++], redistributing
- dependencies [C++], application deployment and
- application deployment [C++], DLL redistribution
- deploying applications [C++], DLL redistribution
ms.assetid: f7a2cb42-fb48-42ab-abd2-b35e2fd5601a
ms.openlocfilehash: dd600e2b3e094b1547badd93596a9dbed2438fb3
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58786132"
---
# <a name="determining-which-dlls-to-redistribute"></a>Determinando quais DLLs devem ser redistribuídas

Quando você compila um aplicativo que usa as DLLs de biblioteca fornecidas pelo Visual Studio, os usuários do seu aplicativo também devem ter essas DLLs em seus computadores para que o aplicativo seja executado. Como a maioria dos usuários provavelmente não tem o Visual Studio instalado, você deve fornecer essas DLLs para eles. O Visual Studio disponibiliza essas DLLs como *arquivos redistribuíveis* que podem ser incluídos no instalador do aplicativo.

Para facilitar a inclusão das DLLs redistribuíveis com o instalador, elas estão disponíveis como *pacotes redistribuíveis* autônomos. Esses são executáveis específicos a uma arquitetura que usa a implantação central para instalar os arquivos redistribuíveis no computador de um usuário. Por exemplo, vcredist\_x86.exe instala as bibliotecas de 32 bits para x86 computadores, vcredist\_x64.exe instala as bibliotecas de 64 bits para x64 computadores e vcredist\_ARM.exe instala as bibliotecas para computadores ARM. Recomendamos a implantação central, pois a Microsoft pode usar o serviço Windows Update para atualizar essas bibliotecas de maneira independente. Além da cópia em sua instalação do Visual Studio, os pacotes redistribuíveis atuais estão disponíveis para download. Para obter links para os últimos pacotes redistribuíveis compatíveis com conjuntos de ferramentas atuais e antigos, confira [Os downloads do Visual C++ mais recentes com suporte](https://support.microsoft.com/help/2977003/the-latest-supported-visual-c-downloads). Encontre versões anteriores específicas dos pacotes redistribuíveis pesquisando "Pacotes Redistribuíveis do Visual C++" no [Centro de Download da Microsoft](http://go.microsoft.com/fwlink/p/?LinkId=158431).

O número de versão principal do pacote redistribuível implantado precisa corresponder à versão do conjunto de ferramentas do Visual Studio usado para criar o aplicativo e a versão secundária deve ser igual ou posterior. O Visual Studio 2017 e o Visual Studio 2015 têm números de versão do conjunto de ferramentas compatíveis, o que significa que os arquivos redistribuíveis do Visual Studio 2017 podem ser usados por aplicativos compilados usando o conjunto de ferramentas da versão 2015. Embora eles possam ser compatíveis, não damos suporte ao uso dos arquivos redistribuíveis da versão 2015 em aplicativos compilados com o conjunto de ferramentas da versão 2017. Só damos suporte ao uso de um pacote redistribuível que seja igual ou mais recente do que a versão do conjunto de ferramentas.

Outra maneira de incluir as DLLs redistribuíveis no instalador é usar *módulos de mesclagem*. Esses módulos do Microsoft Installer são incluídos no instalador do aplicativo e instalados por ele. Os módulos de mesclagem para as DLLs redistribuíveis estão localizados no diretório de instalação do Visual Studio em \\VC\\Redist\MSVC\\*versão*\\MergeModules\\. Em versões anteriores do Visual Studio, esses arquivos são encontrados no diretório \\Arquivos de Programas ou \\Arquivos de Programas (x86) em um subdiretório de Common Files\\Merge Modules. Para obter mais informações sobre o uso desses arquivos, confira [Redistribuindo componentes usando módulos de mesclagem](redistributing-components-by-using-merge-modules.md).

As DLLs redistribuíveis individuais também estão incluídas na instalação do Visual Studio. Por padrão, elas são instaladas no diretório de instalação do Visual Studio na pasta \\VC\\Redist\\MSVC\\*versão*. O número de *versão* pode representar diferentes números de build secundário de um único conjunto comum de arquivos redistribuíveis. Use a última versão de qualquer arquivo DLL de biblioteca, pacote redistribuível ou módulo de mesclagem encontrado nesses diretórios. Você pode usar essas bibliotecas para implantação local, instalando-as no mesmo diretório do aplicativo. Não recomendamos a implantação local porque ela faz com que você fique responsável por fornecer atualizações aos aplicativos implantados. A implantação central usando os pacotes redistribuíveis é preferencial.

Para determinar quais DLLs você precisa redistribuir com o aplicativo, colete uma lista das DLLs das quais o aplicativo depende. Normalmente, elas estão listadas como entradas da biblioteca de importação para o vinculador. Algumas bibliotecas, como vcruntime e o UCRT (Biblioteca de Tempo de Execução do C Universal), estão incluídas por padrão. Se o aplicativo ou uma de suas dependências usa LoadLibrary ao carregar uma DLL dinamicamente, essa DLL pode não estar listada nas entradas para o vinculador. Uma maneira de coletar a lista das DLLs carregadas dinamicamente é executar o Dependency Walker (depends.exe) no aplicativo, conforme descrito em [Noções básicas sobre as dependências de um aplicativo do Visual C++](understanding-the-dependencies-of-a-visual-cpp-application.md). Infelizmente, essa ferramenta está desatualizada e pode relatar que não pode encontrar algumas DLLs.

Quando você tiver a lista de dependências, compare-a com a lista vinculada no arquivo Redist.txt encontrado no diretório de instalação do Microsoft Visual Studio ou com a "lista REDIST" das DLLs redistribuíveis referenciada na seção "Arquivos de código distribuíveis" dos Termos de Licença para Software Microsoft de sua cópia do Visual Studio. Para o Visual Studio 2017, confira [Código distribuível para o Microsoft Visual Studio 2017 (inclui utilitários, extensibilidade e arquivos do BuildServer)](http://go.microsoft.com/fwlink/p/?linkid=823098). Para o Visual Studio 2015, confira [Código distribuível para o Microsoft Visual Studio 2015 e o SDK do Microsoft Visual Studio 2015 (inclui utilitários e arquivos do BuildServer)](http://go.microsoft.com/fwlink/p/?linkid=799794). Para o Visual Studio 2013, a lista está disponível online em [Código distribuível para o Microsoft Visual Studio 2013 e o SDK do Microsoft Visual Studio 2013](http://go.microsoft.com/fwlink/p/?LinkId=313603).

Em versões do Visual Studio anteriores ao Visual Studio 2015, o CRT (Biblioteca de Tempo de Execução do C) foi incluído como uma DLL redistribuível, em msvc*version*.dll. Do Visual Studio 2015 em diante, as funções no CRT foram refatoradas no vcruntime e no UCRT. Agora, o UCRT é um componente do sistema no Windows 10, gerenciado pelo Windows Update. Ele está disponível em todos os sistemas operacionais Windows 10. Para implantar o aplicativo em sistemas operacionais anteriores, talvez seja necessário redistribuir o UCRT também. Uma versão anterior do UCRT é incluída nos arquivos de pacotes redistribuíveis do Visual Studio, que só é instalada em sistemas operacionais anteriores ao Windows 10, e apenas se nenhuma versão do UCRT já está instalada. Para obter uma versão instalável do UCRT para sistemas de nível inferior como um pacote de Atualização do Sistema da Microsoft, confira [Tempo de Execução do C Universal do Windows 10](https://www.microsoft.com/download/details.aspx?id=48234) no Centro de Download da Microsoft.

Você não pode redistribuir todos os arquivos incluídos no Visual Studio; é permitido redistribuir somente os arquivos especificados em Redist.txt ou na "lista REDIST" online. As versões de depuração de aplicativos e as várias DLLs de depuração do Visual C++ não são redistribuíveis. Para obter mais informações, confira [Escolhendo um método de implantação](choosing-a-deployment-method.md).

A tabela a seguir descreve algumas das DLLs do Visual C++ das quais o aplicativo pode depender.

|Biblioteca do Visual C++|Descrição|Aplica-se a|
|--------------------------|-----------------|----------------|
|vcruntime*versão*.dll|Biblioteca de Tempo de Execução para código nativo.|Aplicativos que usam os serviços de inicialização e encerramento normais da linguagem C e C++.|
|vccorlib*versão*.dll|Biblioteca de Tempo de Execução para código gerenciado.|Aplicativos que usam os serviços de linguagem C++ para código gerenciado.|
|msvcp*versão*.dll e msvcp*versão*_*dotnumber*.dll|Biblioteca Padrão C++ para código nativo.|Aplicativos que usam a [Biblioteca Padrão C++](../standard-library/cpp-standard-library-reference.md).|
|concrt*versão*.dll|Biblioteca de Tempo de Execução de Simultaneidade para código nativo.|Aplicativos que usam o [Tempo de Execução de Simultaneidade](../parallel/concrt/concurrency-runtime.md).|
|mfc*versão*.dll|Biblioteca MFC (Microsoft Foundation Classes).|Aplicativos que usam a [Biblioteca MFC](../mfc/mfc-desktop-applications.md).|
|mfc*versão* *linguagem*.dll|Recursos da Biblioteca MFC (Microsoft Foundation Classes).|Aplicativos que usam recursos de linguagem específicos ao MFC.|
|mfc*versão*u.dll|Biblioteca MFC com suporte a Unicode.|Aplicativos que usam a [Biblioteca MFC](../mfc/mfc-desktop-applications.md) e que precisam de suporte a Unicode.|
|mfcmifc80.dll|Biblioteca MFC de Interfaces Gerenciadas.|Aplicativos que usam a [Biblioteca MFC](../mfc/mfc-desktop-applications.md) com [Controles do Windows Forms](/dotnet/framework/winforms/controls/index).|
|mfcm*versão*.dll|Biblioteca MFC Gerenciada.|Aplicativos que usam a [Biblioteca MFC](../mfc/mfc-desktop-applications.md) com [Controles do Windows Forms](/dotnet/framework/winforms/controls/index).|
|mfcm*versão*u.dll|Biblioteca MFC Gerenciada com suporte a Unicode.|Aplicativos que usam a [Biblioteca MFC](../mfc/mfc-desktop-applications.md) com [Controles do Windows Forms](/dotnet/framework/winforms/controls/index) e que precisam de suporte a Unicode.|
|vcamp*versão*.dll|Biblioteca AMP para código nativo.|Aplicativos que usam o código da [Biblioteca C++ AMP](../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md).|
|vcomp*versão*.dll|Biblioteca OpenMP para código nativo.|Aplicativos que usam o código da [Biblioteca C++ OpenMP](../parallel/openmp/openmp-in-visual-cpp.md).|

> [!NOTE]
> Você não precisa mais redistribuir a Active Template Library como uma DLL separada. Sua funcionalidade foi movida para cabeçalhos e uma biblioteca estática.

Para obter mais informações sobre como redistribuir essas DLLs com seu aplicativo, confira [Redistribuindo arquivos do Visual C++](redistributing-visual-cpp-files.md). Para obter exemplos, confira [Exemplos de implantação](deployment-examples.md).

Normalmente, não é necessário redistribuir DLLs do sistema porque elas fazem parte do sistema operacional. No entanto, pode haver exceções, por exemplo, quando o aplicativo for executado em várias versões de sistemas operacionais Microsoft. Nesse caso, leia os termos de licença correspondentes. Além disso, tente atualizar as DLLs do sistema por meio do Windows Update, dos service packs ou usando os pacotes redistribuíveis disponibilizados pela Microsoft.

## <a name="see-also"></a>Consulte também

[Escolhendo um método de implantação](choosing-a-deployment-method.md)<br/>
[Implantando aplicativos da área de trabalho](deploying-native-desktop-applications-visual-cpp.md)
