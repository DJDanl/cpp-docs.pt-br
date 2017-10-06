---
title: Recursos da biblioteca CRT | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- c.runtime
dev_langs:
- C++
helpviewer_keywords:
- MSVCR71.dll
- libraries [C++], multithreaded
- library files, run-time
- LIBCMT.lib
- LIBCP.lib
- LIBCPMT.lib
- run-time libraries, C
- CRT, release versions
- MSVCP71.dll
- LIBC.lib
- libraries [C++]
- libraries [C++], run-time
- linking [C++], libraries
ms.assetid: a889fd39-807d-48f2-807f-81492612463f
caps.latest.revision: 32
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: HT
ms.sourcegitcommit: 22da7776e46171467a37d46c3de3227f060eaf77
ms.openlocfilehash: 0ae005c2367f891e0b7a91e3f7e45d42d852fb78
ms.contentlocale: pt-br
ms.lasthandoff: 08/11/2017

---
# <a name="crt-library-features"></a>Funcionalidades da biblioteca CRT
Este tópico aborda os vários arquivos .lib que compõem as bibliotecas em tempo de execução C, bem como suas opções do compilador e diretivas do pré-processador associadas.  
  
## <a name="c-run-time-libraries-crt"></a>Bibliotecas em tempo de execução do C (CRT)  
 A Biblioteca em Tempo de Execução C (CRT) é a parte da Biblioteca Padrão C++ que incorpora a biblioteca padrão ISO C99. As bibliotecas Visual C++ que implementam o CRT dão suporte ao desenvolvimento de código nativo, código nativo e gerenciado misto e código gerenciado puro para o desenvolvimento do .NET. Todas as versões do CRT dão suporte ao desenvolvimento multi-threaded. A maioria das bibliotecas dá suporte tanto à vinculação estática, para vincular a biblioteca diretamente no código, quanto à vinculação dinâmica, para permitir que o código use arquivos DLL comuns.  
  
 A partir do Visual Studio 2015, o CRT foi refatorado em novos binários. O UCRT (CRT Universal) contém as funções e os globais exportados pela biblioteca CRT C99 padrão. O UCRT agora é um componente do Windows e é fornecido como parte do Windows 10. A biblioteca estática, a biblioteca de importação de DLL e os arquivos de cabeçalho do UCRT agora são encontrados no SDK do Windows 10. Ao instalar o Visual C++, a instalação do Visual Studio instala o subconjunto do SDK do Windows 10 necessário para usar o UCRT. É possível usar o UCRT em qualquer versão do Windows com suporte no Visual Studio 2015 e versões posteriores. Você pode redistribuí-lo usando vcredist para versões com suporte do Windows que não sejam o Windows 10. Para obter mais informações, consulte [Redistribuindo arquivos do Visual C++](../ide/redistributing-visual-cpp-files.md).  
  
 A tabela a seguir lista as bibliotecas que implementam o UCRT.  
  
|Biblioteca|DLL associada|Características|Opção|Diretivas do pré-processador|  
|-------------|--------------------|---------------------|------------|-----------------------------|  
|libucrt.lib|Nenhum|Vincula estaticamente o UCRT no código.|**/MT**|_MT|  
|libucrtd.lib|Nenhum|Versão de depuração do UCRT para vinculação estática. Não redistribuível.|**/MTd**|_DEBUG, _MT|  
|ucrt.lib|ucrtbase.dll|Biblioteca de importação de DLL do UCRT.|**/MD**|_MT, _DLL|  
|ucrtd.lib|ucrtbased.dll|Biblioteca de importação de DLL para a versão de Depuração do UCRT. Não redistribuível.|**/MDd**|_DEBUG, _MT, _DLL|  
  
 A biblioteca vcruntime contém códigos específicos à implementação do CRT no Visual C++, como tratamento de exceção e suporte à depuração, verificações em tempo de execução e informações de tipo, detalhes de implementação e algumas funções de biblioteca estendidas. Essa biblioteca é específica à versão do compilador utilizada.  
  
 Esta tabela lista as bibliotecas que implementam a biblioteca vcruntime.  
  
|Biblioteca|DLL associada|Características|Opção|Diretivas do pré-processador|  
|-------------|--------------------|---------------------|------------|-----------------------------|  
|libvcruntime.lib|Nenhum|Vinculada estaticamente no código.|**/MT**|_MT|  
|libvcruntimed.lib|Nenhum|Versão de depuração para vinculação estática. Não redistribuível.|**/MTd**|_MT, _DEBUG|  
|vcruntime.lib|vcruntime\<version>.dll|Biblioteca de importação de DLL do vcruntime.|**/MD**|_MT, _DLL|  
|vcruntimed.lib|vcruntime\<version>d.dll|Biblioteca de importação de DLL do vcruntime de Depuração. Não redistribuível.|**/MDd**|_DEBUG, _MT, _DLL|  
  
 O código que inicializa o CRT está em uma das várias bibliotecas, com base no fato de a biblioteca CRT ser vinculada estática ou dinamicamente ou de o código ser nativo, gerenciado ou misto. Esse código manipula a inicialização, a inicialização interna de dados por thread e o encerramento do CRT. Ele é específico à versão do compilador utilizada. Essa biblioteca é sempre vinculada estaticamente, mesmo ao usar um UCRT vinculado dinamicamente.  
  
 Esta tabela lista as bibliotecas que implementam a inicialização e o encerramento do CRT.  
  
|Biblioteca|Características|Opção|Diretivas do pré-processador|  
|-------------|---------------------|------------|-----------------------------|  
|libcmt.lib|Vincula estaticamente a inicialização nativa do CRT no código.|**/MT**|_MT|  
|libcmtd.lib|Vincula estaticamente a versão de Depuração da inicialização nativa do CRT. Não redistribuível.|**/MTd**|_DEBUG, _MT|  
|msvcrt.lib|Biblioteca estática da inicialização nativa do CRT para uso com o UCRT e o vcruntime da DLL.|**/MD**|_MT, _DLL|  
|msvcrtd.lib|Biblioteca estática da versão de Depuração da inicialização nativa do CRT para uso com o UCRT e o vcruntime da DLL. Não redistribuível.|**/MDd**|_DEBUG, _MT, _DLL|  
|msvcmrt.lib|Biblioteca estática da inicialização nativa e gerenciada mista do CRT para uso com o UCRT e o vcruntime da DLL.|**/clr**||  
|msvcmrtd.lib|Biblioteca estática da versão de Depuração da inicialização nativa e gerenciada mista do CRT para uso com o UCRT e o vcruntime da DLL. Não redistribuível.|**/clr**||  
|msvcurt.lib|Biblioteca estática **Preterida** para CRT gerenciado puro.|**/clr:pure**||  
|msvcurtd.lib|Biblioteca estática **Preterida** para a versão de Depuração do CRT gerenciado puro. Não redistribuível.|**/clr:pure**||  
  
 Se você vincular o programa por meio da linha de comando sem uma opção do compilador que especifica uma biblioteca em tempo de execução C, o vinculador usará as bibliotecas CRT vinculadas estaticamente: libcmt.lib, libvcruntime.lib e libucrt.lib.  
  
 O uso do CRT vinculado estaticamente indica que todas as informações de estado salvas pela biblioteca em tempo de execução C serão locais para essa instância do CRT. Por exemplo, se você usar [strtok, _strtok_l, wcstok, _wcstok_l, _mbstok, _mbstok_l](../c-runtime-library/reference/strtok-strtok-l-wcstok-wcstok-l-mbstok-mbstok-l.md) ao usar um CRT vinculado estaticamente, a posição do analisador `strtok` não estará relacionada ao estado `strtok` usado em código no mesmo processo (mas em outra DLL ou outro EXE) que está vinculado a outra instância do CRT estático. Por outro lado, o CRT vinculado dinamicamente compartilha o estado de todo o código em um processo que está vinculado dinamicamente ao CRT. Essa preocupação não se aplicará se você usar as novas versões mais seguras dessas funções; por exemplo, `strtok_s` não apresenta esse problema.  
  
 Como uma DLL compilada por meio da vinculação a um CRT estático terá seu próprio estado de CRT, não é recomendável vincular estaticamente ao CRT em uma DLL, a menos que as consequências dessa ação sejam especificamente desejadas e compreendidas. Por exemplo, se você chamar [_set_se_translator](../c-runtime-library/reference/set-se-translator.md) em um executável que carrega a DLL vinculada a seu próprio CRT estático, as exceções de hardware geradas pelo código na DLL não serão capturadas pelo conversor, mas as exceções de hardware geradas pelo código no executável principal serão capturadas.  
  
 Se estiver usando a opção **/clr** do compilador, o código será vinculado a uma biblioteca estática, msvcmrt.lib. A biblioteca estática fornece um proxy entre o código gerenciado e o CRT nativo. Não é possível usar o CRT vinculado estaticamente (opções **/MT** ou **/MTd**) com **/clr**. Em vez disso, use as bibliotecas vinculadas dinamicamente (**/MD** ou **/MDd**).  
  
 Se estiver usando a opção **/clr:pure** do compilador, o código será vinculado à biblioteca estática msvcurt.lib. Assim como ocorre com **/clr**, não é possível vincular à biblioteca vinculada estaticamente. As opções do compilador **/clr:pure** e **/clr:safe** foram preteridas a partir do Visual Studio 2015.  
  
 Para obter mais informações sobre como usar o CRT com **/clr**, consulte [Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md); para **/clr:pure**, consulte [Código puro e verificável (C++/CLI)](../dotnet/pure-and-verifiable-code-cpp-cli.md).  
  
 Para compilar uma versão de depuração de seu aplicativo, o sinalizador [_DEBUG](../c-runtime-library/debug.md) deve estar definido e o aplicativo deve estar vinculado a uma versão de depuração de uma dessas bibliotecas. Para obter mais informações sobre como usar as versões de depuração dos arquivos de biblioteca, consulte [Técnicas de depuração do CRT](/visualstudio/debugger/crt-debugging-techniques).  
  
 Essa versão do CRT não está em conformidade total com o padrão C99. Especificamente, não há suporte para o cabeçalho \<tgmath.h> nem para as macros de pragma CX_LIMITED_RANGE/FP_CONTRACT. Alguns elementos, como o significado dos especificadores de parâmetro em funções de E/S padrão, usam interpretações herdadas por padrão. É possível usar as opções de conformidade do compilador /Zc e especificar as opções do vinculador para controlar alguns aspectos de conformidade da biblioteca,  
  
## <a name="c-standard-library"></a>Biblioteca Padrão C++  
  
|Biblioteca Padrão C++|Características|Opção|Diretivas do pré-processador|  
|----------------------------|---------------------|------------|-----------------------------|  
|LIBCPMT.LIB|Multi-threaded, vínculo estático|**/MT**|_MT|  
|MSVCPRT.LIB|Multi-threaded, vínculo dinâmico (biblioteca de importação para MSVCP\<version>.dll)|**/MD**|_MT, _DLL|  
|LIBCPMTD.LIB|Multi-threaded, vínculo estático|**/MTd**|_DEBUG, _MT|  
|MSVCPRTD.LIB|Multi-threaded, vínculo dinâmico (biblioteca de importação para MSVCP\<version>D.DLL)|**/MDd**|_DEBUG, _MT, _DLL|  
  
 Ao compilar uma versão de lançamento do projeto, uma das bibliotecas básicas em tempo de execução C (LIBCMT.LIB, MSVCMRT.LIB, MSVCRT.LIB) é vinculada por padrão, dependendo da opção do compilador escolhida (multi-threaded, DLL, /clr). Quando você inclui um dos [arquivos de cabeçalho da Biblioteca Padrão C++](../standard-library/cpp-standard-library-header-files.md) no código, uma Biblioteca Padrão C++ é vinculada automaticamente pelo Visual C++ em tempo de compilação. Por exemplo:  
  
```  
#include <ios>   
```  
  
## <a name="what-problems-exist-if-an-application-uses-more-than-one-crt-version"></a>Quais problemas poderão ocorrer se um aplicativo usar mais de uma versão do CRT?  
 Caso tenha mais de uma DLL ou mais de um EXE, então você pode ter mais de um CRT, independentemente de estar usando ou não versões diferentes do Visual C++. Por exemplo, a vinculação estática do CRT em várias DLLs poderá apresentar o mesmo problema. Os desenvolvedores que tiveram esse problema com CRTs estáticos foram instruídos a compilar com **/MD** para usar a DLL do CRT. Se as DLLs passarem recursos do CRT além do limite da DLL, você poderá ter problemas com CRTs incompatíveis e precisará recompilar o projeto com o Visual C++.  
  
 Se o programa estiver usando mais de uma versão do CRT, será necessário ter cuidado ao passar determinados objetos do CRT (como identificadores de arquivo, localidades e variáveis de ambiente) em limites da DLL. Para obter mais informações sobre os problemas envolvidos e como resolvê-los, consulte [Erros potenciais ao passar objetos do CRT em limites da DLL](../c-runtime-library/potential-errors-passing-crt-objects-across-dll-boundaries.md).  
  
## <a name="see-also"></a>Consulte também  
 [Referência da biblioteca em tempo de execução C](../c-runtime-library/c-run-time-library-reference.md)
