---
title: "Determinando quais DLLs devem ser redistribuídas | Microsoft Docs"
ms.custom: 
ms.date: 09/21/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- redistributing DLLs
- DLLs [C++], redistributing
- dependencies [C++], application deployment and
- application deployment [C++], DLL redistribution
- deploying applications [C++], DLL redistribution
ms.assetid: f7a2cb42-fb48-42ab-abd2-b35e2fd5601a
caps.latest.revision: "31"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: ae47ec92ecea46aba5f0e1bf144a34fd5532af9d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="determining-which-dlls-to-redistribute"></a>Determinando quais DLLs devem ser redistribuídas

Quando você cria um aplicativo que usa a biblioteca DLLs fornecidas pelo Visual Studio, os usuários do seu aplicativo também devem ter essas DLLs em seus computadores para o aplicativo seja executado. Como a maioria dos usuários provavelmente não tiver instalado o Visual Studio, você deve fornecer essas DLLs para eles. O Visual Studio torna essas DLLs disponíveis como *arquivos redistribuíveis* que você pode incluir no instalador de seu aplicativo.

Para tornar mais fácil de incluir as DLLs redistribuíveis com o instalador, eles estão disponíveis como autônomo *pacotes redistribuíveis*. Esses são executáveis específicos de arquitetura que usa implantação central para instalar os arquivos redistribuíveis no computador do usuário. Por exemplo, vcredist\_x86.exe instala as bibliotecas de 32 bits x86 computadores, vcredist\_x64.exe instala as bibliotecas de 32 bits e 64 bits para x64 computadores e vcredist\_ARM.exe instala as bibliotecas para ARM computadores. Recomendamos a implantação central como Microsoft pode usar o serviço Windows Update para atualizar independentemente dessas bibliotecas. Além da cópia em sua instalação do Visual Studio, os pacotes redistribuíveis atuais estão disponíveis para download em [VisualStudio.com/Downloads](https://www.visualstudio.com/downloads/) na seção outras ferramentas e estruturas.

O número de versão principal do pacote redistribuível que implantar deve corresponder à versão do conjunto de ferramentas Visual Studio usada para criar seu aplicativo. Visual Studio 2017 e Visual Studio 2015 têm números de versão compatível do conjunto de ferramentas, o que significa que o Visual 2017 Studio arquivos redistribuíveis podem ser usados por aplicativos criados usando o conjunto de ferramentas de 2015. Enquanto eles podem ser compatíveis, não oferecemos suporte usando os arquivos redistribuíveis 2015 em aplicativos criados usando o conjunto de ferramentas de 2017. Só há suporte para usar um pacote redistribuível que seja igual ou mais recente do que a versão do conjunto de ferramentas. Para obter links para os mais recente com suporte pacotes redistribuíveis para conjuntos de ferramentas mais antigos, consulte [a versão mais recente com suporte de downloads do Visual C++](https://support.microsoft.com/en-us/help/2977003/the-latest-supported-visual-c-downloads). Versões anteriores específicas dos pacotes redistribuíveis podem ser encontradas pesquisando o [Microsoft Download Center](http://go.microsoft.com/fwlink/p/?LinkId=158431) para "Visual C++ redistribuível pacotes".

Outra maneira de incluir as DLLs redistribuíveis com o instalador é usar *Mesclar módulos*. Esses módulos do Microsoft Installer estão incluídos no e instalados pelo instalador de seu aplicativo. Módulos de mesclagem para as DLLs redistribuíveis encontram-se em seu diretório de instalação do Visual Studio em \\VC\\Redist\MSVC\\*versão*\\MergeModules\\ . Em versões anteriores do Visual Studio, esses arquivos são encontrados no seu \\arquivos de programas ou \\diretório de arquivos de programa (x86) em arquivos comuns\\subdiretório de módulos de mesclagem. Para obter mais informações sobre o uso desses arquivos, consulte [redistribuindo componentes usando módulos de mesclagem](../ide/redistributing-components-by-using-merge-modules.md).

As DLLs redistribuíveis individuais também estão incluídas na instalação do Visual Studio. Por padrão, eles são instalados no diretório de instalação do Visual Studio no \\VC\\Redist\\MSVC\\*versão* pasta. O *versão* números podem representar números diferentes de compilação secundária de um único conjunto de arquivos redistribuíveis comum. Use a versão mais recente de qualquer arquivo DLL de biblioteca, pacote redistribuível ou módulo de mesclagem encontrado nesses diretórios. Você pode usar essas bibliotecas para implantação local, instalando-os no mesmo diretório do seu aplicativo. Nós não recomendamos a implantação local porque ele faz com que é responsável por distribuir atualizações para seus aplicativos implantados. Implantação Central usando os pacotes redistribuíveis é preferencial.

Para determinar quais DLLs necessário redistribuir com seu aplicativo, colete uma lista de DLLs que seu aplicativo depende. Normalmente, eles estão listados como entradas para o vinculador de biblioteca de importação. Determinadas bibliotecas, como vcruntime e o Universal C Runtime Library (UCRT), são incluídas por padrão. Se seu aplicativo ou uma de suas dependências usa LoadLibrary ao carregar dinamicamente uma DLL, essa DLL pode não estar listado nas entradas para o vinculador. Uma maneira de coletar a lista de DLLs carregadas dinamicamente é executar dependência Walker (depends.exe) em seu aplicativo, conforme descrito em [Noções básicas sobre as dependências de um aplicativo do Visual C++](../ide/understanding-the-dependencies-of-a-visual-cpp-application.md). Infelizmente, essa ferramenta está desatualizada e pode reportar que ele não é possível localizar determinadas DLLs.

Quando você tem a lista de dependências, compará-la à lista vinculada no arquivo Redist encontrado no diretório de instalação do Microsoft Visual Studio, ou para a "lista REDIST" DLLs redistribuíveis que é mencionada na seção "Arquivos de código distribuível" dos termos de licença do Software Microsoft para sua cópia do Visual Studio. Para o Visual Studio de 2017, consulte [Código distribuível para o Microsoft Visual Studio 2017 (inclui utilitários, extensibilidade e arquivos do BuildServer)](http://go.microsoft.com/fwlink/?LinkId=823098). Para o Visual Studio 2015, consulte [Código distribuível para o Microsoft Visual Studio 2015 e Microsoft Visual Studio 2015 SDK (inclui utilitários e arquivos do BuildServer)](http://go.microsoft.com/fwlink/?LinkId=799794). Para Visual Studio 2013, a lista está disponível online em [Código distribuível para o Microsoft Visual Studio 2013 e o SDK do Microsoft Visual Studio 2013](http://go.microsoft.com/fwlink/p/?LinkId=313603).

Em versões do Visual Studio antes de Visual Studio 2015, a biblioteca de tempo de execução do C (CRT) foi incluída como uma DLL redistribuível, em msvc*versão*. dll. A partir do Visual Studio 2015, as funções de CRT foram refatorar o vcruntime e a UCRT. Agora, a UCRT é um componente do sistema no Windows 10, gerenciado pelo Windows Update. Ele está disponível em todos os sistemas operacionais Windows 10. Para implantar seu aplicativo para sistemas operacionais anteriores, talvez seja necessário redistribuir a UCRT também. Uma versão anterior da UCRT é incluído nos arquivos de pacotes redistribuíveis do Visual Studio, que só é instalado em sistemas operacionais anteriores ao Windows 10, e apenas se nenhuma versão da UCRT já está instalado. Para obter uma versão instalável UCRT para sistemas de nível inferior como um pacote de atualização do sistema Microsoft, consulte [Windows 10 Universal C Runtime](https://www.microsoft.com/en-us/download/details.aspx?id=48234) no Microsoft Download Center.

Você não pode redistribuir todos os arquivos que estão incluídos no Visual Studio; são permitidas somente para redistribuir os arquivos que são especificados em Redist ou a on-line "lista REDIST." Versões de depuração de aplicativos e a depuração do Visual C++ várias DLLs não são redistribuíveis. Para obter mais informações, consulte [escolhendo um método de implantação](../ide/choosing-a-deployment-method.md).

A tabela a seguir descreve algumas das DLLs Visual C++ que pode depender de seu aplicativo.

|Biblioteca do Visual C++|Descrição|Aplica-se a|
|--------------------------|-----------------|----------------|
|vcruntime*versão*. dll|Biblioteca de tempo de execução de código nativo.|Aplicativos que usam os normal C e C++ language inicialização e encerramento serviços.|
|vccorlib*versão*. dll|Biblioteca de tempo de execução de código gerenciado.|Aplicativos que usam os serviços de linguagem C++ para código gerenciado.|
|msvcp*versão*. dll|Biblioteca padrão C++ para código nativo.|Aplicativos que usam o [biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md).|
|concrt*versão*. dll|Biblioteca de tempo de execução de simultaneidade para código nativo.|Aplicativos que usam o [tempo de execução de simultaneidade](../parallel/concrt/concurrency-runtime.md).|
|MFC*versão*. dll|Microsoft Foundation Classes (MFC) de biblioteca.|Aplicativos que usam o [biblioteca MFC](../mfc/mfc-desktop-applications.md).|
|MFC*versão* *idioma*. dll|Microsoft Foundation Classes (MFC) recursos de biblioteca.|Aplicativos que usam recursos de idioma específico para MFC.|
|MFC*versão*u.dll|Biblioteca do MFC com suporte a Unicode.|Aplicativos que usam o [biblioteca MFC](../mfc/mfc-desktop-applications.md) necessita de suporte de Unicode.|
|mfcmifc80|Biblioteca do MFC Interfaces gerenciadas.|Aplicativos que usam o [biblioteca MFC](../mfc/mfc-desktop-applications.md) com [controles dos Windows Forms](/dotnet/framework/winforms/controls/index).|
|mfcm*versão*. dll|Biblioteca gerenciada do MFC.|Aplicativos que usam o [biblioteca MFC](../mfc/mfc-desktop-applications.md) com [controles dos Windows Forms](/dotnet/framework/winforms/controls/index).|
|mfcm*versão*u.dll|Biblioteca gerenciada MFC com suporte a Unicode.|Aplicativos que usam o [biblioteca MFC](../mfc/mfc-desktop-applications.md) com [controles dos Windows Forms](/dotnet/framework/winforms/controls/index) necessita de suporte de Unicode.|
|vcamp*versão*. dll|Biblioteca de AMP para código nativo.|Aplicativos que usam o [biblioteca C++ AMP](../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md) código.|
|vcomp*versão*. dll|Biblioteca de OpenMP para código nativo.|Aplicativos que usam o [biblioteca C++ OpenMP](../parallel/openmp/openmp-in-visual-cpp.md) código.|

> [!NOTE]
> Você não precisa redistribuir o Active Template Library como uma DLL separada. Sua funcionalidade foi movida para cabeçalhos e uma biblioteca estática.

Para obter mais informações sobre como redistribuir essas DLLs com seu aplicativo, consulte [arquivos de redistribuição do Visual C++](../ide/redistributing-visual-cpp-files.md). Para obter exemplos, consulte [exemplos de implantação](../ide/deployment-examples.md).

Normalmente, você não precisa redistribuir DLLs do sistema porque elas fazem parte do sistema operacional. No entanto, pode haver exceções, por exemplo, quando o aplicativo será executado em várias versões de sistemas operacionais da Microsoft. Nesse caso, certifique-se de ler os termos de licença correspondente. Além disso, ao tente obter o sistema DLLs atualizados por meio do Windows Update, os service packs ou usando os pacotes redistribuíveis disponibilizados pela Microsoft.

## <a name="see-also"></a>Consulte também

[Escolhendo um método de implantação](../ide/choosing-a-deployment-method.md)

[Implantando aplicativos de área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)
