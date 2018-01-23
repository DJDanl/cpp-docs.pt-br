---
title: Redistribuindo arquivos do Visual C++ | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- application deployment [C++], file redistributing
- redistributing applications [C++]
- deploying applications [C++], file redistributing
- file redistribution [C++]
- redistributing applications [C++], about redistributing applications
ms.assetid: d201b2ce-36f1-44e5-a96c-0db81a1ba652
caps.latest.revision: "50"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a89795e19df46b3701cf8dcc7a402540f693db94
ms.sourcegitcommit: 6f40bba1772a09ff0e3843d5f70b553e1a15ab50
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/22/2018
---
# <a name="redistributing-visual-c-files"></a>Redistribuindo arquivos do Visual C++

> [!NOTE]
> É aqui porque você está procurando um download de um dos arquivos de tempo de execução do Visual C++? Vá para o [Microsoft](http://www.microsoft.com/) site da Web e digite **Visual C++ redistribuível** na caixa de pesquisa. Baixe e instale o pacote redistribuível para a arquitetura do computador (por exemplo, x64 se você estiver executando o Windows de 64 bits) e a versão do Visual C++ que você precisa.   
  
Ao implantar um aplicativo, você também deve implantar os arquivos que são necessários para o suporte. Se qualquer um desses arquivos for fornecido pela Microsoft, verifique se você tem permissão para redistribuí-lo. Para revisar os termos de licença do Visual Studio, consulte o link de termos de licença na caixa de diálogo sobre o Microsoft Visual Studio no IDE ou baixar o [Microsoft Software License Terms](http://go.microsoft.com/fwlink/p/?LinkId=831114) arquivo. Para exibir a "lista REDIST" mencionada na seção "Código distribuível" dos termos de licença de Software Microsoft para determinadas edições do Visual Studio, consulte [Código distribuível para o Microsoft Visual Studio 2017 e Microsoft Visual Studio 2017 SDK (inclui utilitários e arquivos do BuildServer)](http://go.microsoft.com/fwlink/p/?LinkId=823098), ou para o Visual Studio 2015, consulte [Código distribuível para o Microsoft Visual Studio 2015 e SDK do Microsoft Visual Studio 2015](http://go.microsoft.com/fwlink/p/?LinkId=523763). Para obter mais informações sobre arquivos redistribuíveis, consulte [determinando quais DLLs devem ser redistribuídas](../ide/determining-which-dlls-to-redistribute.md) e [exemplos de implantação](../ide/deployment-examples.md).  
  
 Para implantar arquivos redistribuíveis do Visual C++, você pode usar os pacotes redistribuíveis do Visual C++ (VCRedist\_x86.exe, VCRedist\_x64.exe ou VCRedist\_arm.exe) que estão incluídos no Visual Studio. No Visual Studio de 2017, esses arquivos podem ser encontrados nos arquivos de programa [(x86)]\\Microsoft Visual Studio\\2017\\_edição_\\VC\\Redist\\ MSVC\\_versão lib_ pasta, onde _edição_ é a edição do Visual Studio instalada, e _versão lib_ é a versão das bibliotecas de redistribuição. No Visual Studio 2015, esses arquivos podem ser encontrados no diretório de instalação do Visual Studio em arquivos de programa [(x86)] \Microsoft Visual Studio *versão*\VC\redist\\*localidade* \\. Outra opção é usar módulos de mesclagem redistribuíveis (arquivos. msm), que podem ser encontrados nos arquivos de programa [(x86)] no Visual Studio de 2017\\Microsoft Visual Studio\\2017\\_edição_ \\ VC\\Redist\\MSVC\\_versão lib_\\MergeModules\\ pasta. No Visual Studio 2015, eles podem ser encontrados em arquivos de programa [(x86)] \Common Files\Merge módulos\\. Também é possível instalar o redistribuível DLLs do Visual C++ em diretamente o *pasta local do aplicativo*, que é a pasta que contém o arquivo executável do aplicativo. Para manutenção motivos, não recomendamos que você usar esse local de instalação.  
  
 Os pacotes redistribuíveis do Visual C++ instalam e registram todas as bibliotecas do Visual C++. Se você usar uma, deverá defini-la para ser executada no sistema de destino como pré-requisito para a instalação de seu aplicativo. Recomendamos que você use esses pacotes para suas implantações, pois permitem a atualização automática das bibliotecas do Visual C++. Para obter um exemplo sobre como usar esses pacotes, consulte [passo a passo: Implantando um Visual C++ aplicativo usando o pacote redistribuível do Visual C++](../ide/deploying-visual-cpp-application-by-using-the-vcpp-redistributable-package.md).  
  
 Cada pacote redistribuível do Visual C++ verifica a existência de uma versão mais recente no computador. Se for encontrada uma versão mais recente, o pacote não está instalado. No Visual Studio 2015, os pacotes redistribuíveis exibir uma mensagem de erro informando que a instalação falha ao iniciar. Se um pacote é executado usando o **/quiet** sinalizador, nenhuma mensagem de erro é exibida. Em ambos os casos, um erro é registrado pelo Microsoft installer e um resultado de erro é retornado ao chamador. A partir do Visual Studio 2015 pacotes, você poderá evitar esse erro ao verificar o registro para descobrir se uma versão mais recente está instalada. A versão atualmente instalada é armazenada no \Microsoft\VisualStudio HKEY_LOCAL_MACHINE\SOFTWARE [\Wow6432Node]\\_versão vs_\VC\Runtimes\\{x86 | x64 | Chave ARM}, onde _versão vs_ é o número de versão para o Visual Studio (14.0 para Visual Studio 2015 e o Visual Studio de 2017, porque o redistribuível de 2017 atualizado é binário compatível com a versão 2015), e onde a chave é ARM, x 86 ou x64 dependendo as versões vcredist instalado para a plataforma. (Você não precisa verificar na subchave Wow6432Node, a menos que você está usando RegEdit para exibir a versão do x86 instaladas pacote em um x64 plataforma.) O número de versão é armazenado no valor de cadeia de caracteres do REG_SZ **versão** e também no conjunto de **principais**, **secundária**, **Bld**e **Rbld** valores REG_DWORD. Para evitar um erro no tempo de instalação, você deverá ignorar a instalação do pacote redistribuível, se a versão atualmente instalada é mais recente.  
  
 Se você usar um módulo de mesclagem que contém uma DLL do Visual C++, você deve incluí-lo no pacote do Windows Installer (ou pacote de instalação semelhante) que você está usando para implantar o aplicativo. Para obter mais informações, consulte [redistribuição por usando Mesclar módulos](../ide/redistributing-components-by-using-merge-modules.md). Para obter um exemplo, consulte [passo a passo: Implantando um Visual C++ aplicativo usando um projeto de instalação](../ide/walkthrough-deploying-a-visual-cpp-application-by-using-a-setup-project.md), que também mostra como usar o InstallShield Limited Edition para criar um pacote de instalação.  
  
## <a name="potential-run-time-errors"></a>Prováveis erros no tempo de execução  
 Se uma DLL de biblioteca do Visual C++ não está acessível e o Windows não pode carregá-lo para seu aplicativo, essa mensagem pode ser exibida: **este aplicativo falhou ao iniciar porque MSVCR\<número de versão >. dll não foi encontrado. A reinstalação do aplicativo pode corrigir este problema.**  
  
 Para resolver este tipo de erro, certifique-se de que seu aplicativo esteja corretamente compilado e que as bibliotecas do Visual C++ estejam, implantadas corretamente no sistema de destino. Para obter mais informações, consulte [Noções básicas sobre as dependências de um aplicativo do Visual C++](../ide/understanding-the-dependencies-of-a-visual-cpp-application.md).  
  
## <a name="related-topics"></a>Tópicos relacionados  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Redistribuindo usando módulos de mesclagem](../ide/redistributing-components-by-using-merge-modules.md)|Descreve como usar módulos de mesclagem redistribuíveis do Visual C++ para instalar as bibliotecas de tempo de execução do Visual C++ como DLLs compartilhadas na pasta %windir%\system32\.|  
|[Redistribuindo controles ActiveX do Visual C++](../ide/redistributing-visual-cpp-activex-controls.md)|Descreve como redistribuir um aplicativo que usa controles do ActiveX.|  
|[Redistribuindo arquivos de suporte de banco de dados](../ide/redistributing-database-support-files.md)|Fala sobre como redistribuir arquivos de suporte para objetos de acesso a dados (DAO) e tecnologias de banco de dados no SDK do Microsoft Data Access.|  
|[Redistribuindo a biblioteca do MFC](../ide/redistributing-the-mfc-library.md)|Descreve como redistribuir um aplicativo que usa MFC.|  
|[Redistribuindo um aplicativo ATL](../ide/redistributing-an-atl-application.md)|Descreve como redistribuir a um aplicativo que usa ATL. Nenhuma biblioteca redistribuível para ATL a partir do Visual Studio 2012, é necessária.|  
|[Exemplos de implantação](../ide/deployment-examples.md)|Links para exemplos que demonstram como implantar aplicativos do Visual C++.|  
|[Implantando aplicativos de área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)|Apresenta conceitos e tecnologias de implantação do Visual C++.|