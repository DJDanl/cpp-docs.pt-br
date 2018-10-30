---
title: Atualizar seu código para o CRT Universal | Microsoft Docs
ms.custom: ''
ms.date: 03/31/2017
ms.topic: conceptual
ms.assetid: eaf34c1b-da98-4058-a059-a10db693a5ce
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8f384810ba689953274c3b585bbee7a345b948de
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50058967"
---
# <a name="upgrade-your-code-to-the-universal-crt"></a>Atualize seu código para o CRT Universal

No Visual Studio 2015, o Microsoft CRT (Biblioteca em Tempo de Execução do C) foi refatorado. A biblioteca padrão do C, as extensões POSIX e as funções, macros e variáveis globais específicas da Microsoft foram movidas para uma nova biblioteca, a Biblioteca em tempo de execução do C Universal (Universal CRT ou UCRT). Os componentes específicos do compilador do CRT foram movidos para uma nova biblioteca vcruntime.

O UCRT agora é um componente do Windows e é fornecido como parte do Windows 10. O UCRT dá suporte a uma ABI estável baseada em convenções de chamada C, e está em estreita conformidade com o padrão ICO C99, com apenas algumas exceções. Ele não está mais associado a uma versão específica do compilador. É possível usar o UCRT em qualquer versão do Windows com suporte no Visual Studio 2015 ou no Visual Studio 2017. A vantagem é que você não precisa mais atualizar seus builds para definir como destino uma nova versão do CRT com cada atualização do Visual Studio.

Com essa refatoração, os nomes ou locais de muitos arquivos de cabeçalho, arquivos de biblioteca e redistribuíveis do CRT e os métodos de implantação necessários para seu código foram alterados. Além disso, muitas funções e macros no UCRT foram adicionadas ou alteradas para melhorar a conformidade com os padrões. Para aproveitar essas alterações, seu código existente e sistemas de build de projeto devem ser atualizados.

## <a name="where-to-find-the-universal-crt-files"></a>Onde localizar os arquivos do CRT Universal

Como um componente do Windows, os cabeçalhos e arquivos de biblioteca UCRT agora fazem parte do SDK (software development kit) do Windows. Quando você instala o Visual Studio, as partes do SDK do Windows necessárias para usar o UCRT também são instaladas. O instalador do Visual Studio adiciona os locais dos cabeçalhos, bibliotecas e arquivos DLL do UCRT aos caminhos padrão usados pelo sistema de build do projeto do Visual Studio. Quando você atualizar seus projetos Visual C++, se eles usarem as configurações de projeto padrão, o IDE localizará automaticamente os novos locais para arquivos de cabeçalho, e o vinculador usará automaticamente as novas bibliotecas UCRT e vcruntime padrão. Da mesma forma, se você usar um prompt de comando do desenvolvedor para fazer builds de linha de comando, as variáveis do ambiente que contêm caminhos para cabeçalhos e bibliotecas serão atualizadas e funcionarão automaticamente também.

Agora os arquivos de cabeçalho da biblioteca padrão do C são encontrados no SDK do Windows em uma pasta de inclusão em um diretório específico da versão do SDK. Um local comum para os arquivos de cabeçalho é no diretório de Arquivos de Programas ou de Arquivos de Programas (x86) em Windows Kits\\10\\Include\\_sdk-version_\\ucrt, em que _sdk-version_ corresponde a uma versão ou atualização do Windows, por exemplo, 10.0.14393.0 para a Atualização de Aniversário do Windows 10.

As bibliotecas estáticas UCRT e as bibliotecas stub de links dinâmicas estão localizadas no diretório de Arquivos de Programas ou de Arquivos de Programas (x86) em Windows Kits\\10\\Lib\\_sdk-version_\\ucrt\\_arquitetura_, em que _arquitetura_ é ARM, x86 ou X64. As bibliotecas estáticas comerciais e de depuração são libucrt.lib e libucrtd.lib, e as bibliotecas para as DLLs do UCRT são ucrt.lib e ucrtd.lib.

As DLLs comerciais e de depuração do UCRT são encontradas em locais separados. As DLLs comerciais são redistribuíveis e podem ser encontradas no diretório de Arquivos de Programas ou Arquivos de Programas (x86) em Kits do Windows\\10\\Redist\\ucrt\\DLLs\\_architecture_\. As bibliotecas UCRT de depuração não são redistribuíveis e podem ser encontradas no diretório de Arquivos de Programas ou Arquivos de Programas (x86) na pasta Kits do Windows\\10\\bin\\_architecture_\\ucrt.

A biblioteca de suporte em tempo de execução específica do compilador C e C++, **vcruntime**, contém o código necessário para dar suporte à inicialização e aos recursos do programa como tratamento de exceção e intrínsecos. A biblioteca e seus arquivos de cabeçalho ainda são encontrados na pasta do Microsoft Visual Studio específica da versão em seu diretório de Arquivos de Programas ou Arquivos de Programas (x86). No Visual Studio 2017, os cabeçalhos estão localizados em Microsoft Visual Studio\\2017\\_edição_\\VC\\Tools\\MSVC\\_lib-version_\\include e as bibliotecas de links estão localizadas em Microsoft Visual Studio\\2017\\_edição_\\VC\\Tools\\MSVC\\_lib-version_\\lib\\_arquitetura_, em que _edição_ é a edição do Visual Studio instalado, _lib-version_ é a versão das bibliotecas e _arquitetura_ é a arquitetura do processador. As bibliotecas de links para OneCore e Store também são encontradas na pasta de bibliotecas. As versões comerciais e de depuração da biblioteca estática são libvcruntime.lib e libvcruntimed.lib. As bibliotecas dinâmicas stub de depuração e de comércio de link são vcruntime.lib e vcruntimed.lib respectivamente.

Ao atualizar seus projetos do Visual C++, se você tiver definido a propriedade **Ignorar todas as bibliotecas padrão** do **Vinculador** do projeto como **Sim** ou se você usar a opção do vinculador `/NODEFAULTLIB` na linha de comando, será necessário atualizar sua lista de bibliotecas para incluir as bibliotecas novas e refatoradas. Substitua a biblioteca CRT antiga, por exemplo, libcmt.lib, libcmtd.lib, msvcrt.lib ou msvcrtd.lib, com as bibliotecas refatoradas equivalentes. Para obter informações sobre as bibliotecas específicas a serem usadas, consulte [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md).

## <a name="deployment-and-redistribution-of-the-universal-crt"></a>Implantação e redistribuição do CRT Universal

Como o UCRT agora é um componente de sistema operacional do Microsoft Windows, ele é incluído como parte do sistema operacional no Windows 10 e está disponível por meio do Windows Update para sistemas operacionais mais antigos, do Windows Vista ao Windows 8.1. Uma versão redistribuível está disponível para o Windows XP. Como um componente de sistema operacional, as atualizações e a manutenção do UCRT são gerenciadas pelo Windows Update independentemente das versões de compilador do Visual Studio e do Microsoft C++. Como o UCRT é um componente do Windows, para obter segurança e facilidade de atualizações, e um tamanho de imagem menor, recomendamos a implantação centralizada do UCRT para seu aplicativo.

É possível usar o UCRT em qualquer versão do Windows com suporte no Visual Studio 2015 ou no Visual Studio 2017. É possível redistribuí-lo usando um pacote vcredist para versões com suporte do Windows que não sejam o Windows 10. Os pacotes vcredist incluem os componentes UCRT e os instala automaticamente nos sistemas operacionais Windows em que eles não estão instalados por padrão. Para obter mais informações, consulte [Redistribuindo arquivos do Visual C++](../ide/redistributing-visual-cpp-files.md).

Há suporte para a implantação local de aplicativos, embora isso não seja recomendado por motivos de desempenho e de segurança. As DLLS para implantação local de aplicativos são incluídas como parte do SDK do Windows, no subdiretório **redist**. As DLLs necessárias incluem ucrtbase.dll e um conjunto de DLLs **encaminhador APISet** denominado api-ms-win-_subset_.dll. O conjunto de DLLs necessário em cada sistema operacional varia. Portanto, recomendamos que você inclua todas as DLLs ao usar a implantação local de aplicativos. Para obter mais detalhes e advertências sobre a implantação local de aplicativos, consulte [Implantação no Visual C++](../ide/deployment-in-visual-cpp.md).

## <a name="changes-to-the-universal-crt-functions-and-macros"></a>Alterações nas funções e nas macros do CRT Universal

Muitas funções foram adicionadas ou atualizadas no UCRT para melhorar a conformidade com a ISO C99 e para solucionar problemas de segurança e de qualidade do código. Em alguns casos, isso exigiria alterações significativas na biblioteca. Se seu código tiver sido compilado corretamente ao usar uma versão mais antiga do CRT, mas for corrompido quando tiver sido compilado suando o UCRT, será necessário alterá-lo para poder usufruir essas atualizações e recursos. Para obter uma lista detalhada das alterações e atualizações significativas no CRT encontrado no CRT Universal, consulte a seção [C Runtime Library (CRT) (CRT – Biblioteca em tempo de execução do C)](visual-cpp-change-history-2003-2015.md#BK_CRT) do histórico de alterações do Visual C++. Inclui uma lista de funções e cabeçalhos afetados que podem ser usados para identificar as alterações necessárias em seu código.

## <a name="see-also"></a>Consulte também

[Guia de atualização e portabilidade do Visual C++](visual-cpp-porting-and-upgrading-guide.md)<br/>
[Visão geral de possíveis problemas de atualização (Visual C++)](overview-of-potential-upgrade-issues-visual-cpp.md)<br/>
[Atualizando projetos de versões anteriores do Visual C++](upgrading-projects-from-earlier-versions-of-visual-cpp.md)<br/>
[Histórico de alterações de 2003 a 2015 do Visual C++](visual-cpp-change-history-2003-2015.md)<br/>
[Aprimoramentos de conformidade do C++ no Visual Studio 2017](../cpp-conformance-improvements-2017.md)