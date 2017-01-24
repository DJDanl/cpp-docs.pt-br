---
title: "Recursos da biblioteca CRT | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "c.runtime"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "MSVCR71.dll"
  - "bibliotecas [C++], multithread"
  - "arquivos de biblioteca de tempo de execução"
  - "LIBCMT.lib"
  - "LIBCP.lib"
  - "LIBCPMT.lib"
  - "bibliotecas de tempo de execução C"
  - "CRT, versões de lançamento"
  - "MSVCP71.dll"
  - "LIBC.lib"
  - "bibliotecas [C++]"
  - "bibliotecas [C++] tempo de execução"
  - "vinculação [C++], bibliotecas"
ms.assetid: a889fd39-807d-48f2-807f-81492612463f
caps.latest.revision: 32
caps.handback.revision: 32
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Recursos da biblioteca CRT
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico aborda os diversos arquivos. lib que compõem as bibliotecas de tempo de execução C, bem como suas opções de compilador associados e diretivas de pré\-processador.  
  
## Bibliotecas em tempo de execução do C \(CRT\)  
 A biblioteca de tempo de execução do C \(CRT\) é a parte da biblioteca padrão C\+\+ que incorpora a biblioteca padrão ISO C99. Bibliotecas do Visual C\+\+ que implementam o CRT suportam a desenvolvimento de código nativo e tanto código nativo e gerenciado misto e código gerenciado puro para desenvolvimento do .NET. Todas as versões do CRT oferece suporte ao desenvolvimento multithread. A maioria das bibliotecas de suporte a vinculação estática, para a biblioteca de vínculo diretamente no seu código, tanto a vinculação dinâmica para permitir que seus arquivos DLL comuns do uso de código.  
  
 No Visual Studio 2015, o CRT tiver sido refatorado em novos binários. A CRT Universal \(UCRT\) contém as funções e globais exportada pela biblioteca CRT C99 padrão. O UCRT agora é um componente do Windows e é fornecido como parte do Windows 10. A biblioteca estática, biblioteca de importação DLL e arquivos de cabeçalho para o UCRT agora são encontrados no SDK do Windows 10. Quando você instala o Visual C\+\+, a instalação do Visual Studio instala o subconjunto do Windows 10 SDK necessário para usar o UCRT. Você pode usar o UCRT em qualquer versão do Windows com suporte pelo Visual Studio 2015. Você pode redistribuí\-lo usando o vcredist para versões com suporte do Windows diferente do Windows 10. Para obter mais informações, consulte [Redistribuindo arquivos do Visual C\+\+](../Topic/Redistributing%20Visual%20C++%20Files.md).  
  
 A tabela a seguir lista as bibliotecas que implementam o UCRT.  
  
|Biblioteca|DLL associado|Características|Opção|Diretivas de pré\-processador|  
|----------------|-------------------|---------------------|-----------|-----------------------------------|  
|libucrt.lib|Nenhum|O UCRT se vincula estaticamente no código.|**\/MT**|MT|  
|libucrtd.lib|Nenhum|Versão de depuração de UCRT para vinculação estática. Não é redistribuível.|**\/MTd**|DEBUG, MT|  
|ucrt.lib|ucrtbase.dll|Biblioteca de importação DLL para o UCRT.|**\/MD**|MT, DLL|  
|ucrtd.lib|ucrtbased.dll|DLL de biblioteca para a versão de depuração de UCRT de importação. Não é redistribuível.|**\/MDd**|DEBUG MT, DLL|  
  
 A biblioteca vcruntime contém código de implementação específica de CRT do Visual C\+\+, como manipuladores de exceção e depuração de suporte, verificações de tempo de execução e informações de tipo, detalhes de implementação e determinadas funções de biblioteca ampliada. Essa biblioteca é específica para a versão do compilador usada.  
  
 Esta tabela lista as bibliotecas que implementam a biblioteca vcruntime.  
  
|Biblioteca|DLL associado|Características|Opção|Diretivas de pré\-processador|  
|----------------|-------------------|---------------------|-----------|-----------------------------------|  
|libvcruntime.lib|Nenhum|Vinculadas estaticamente ao seu código.|**\/MT**|MT|  
|libvcruntimed.lib|Nenhum|Depure a versão para a vinculação estática. Não é redistribuível.|**\/MTd**|MT, DEBUG|  
|vcruntime.lib|. dll vcruntime \< versão \>|Biblioteca de importação DLL para o vcruntime.|**\/MD**|MT, DLL|  
|vcruntimed.lib|d.dll vcruntime \< versão \>|Biblioteca de importação DLL para o vcruntime de depuração. Não é redistribuível.|**\/MDd**|DEBUG MT, DLL|  
  
 O código que inicializa o CRT é em uma das várias bibliotecas, com base na existência da biblioteca CRT código estática ou dinamicamente vinculado, ou nativo, gerenciado ou misto. Esse código manipula inicialização CRT, inicialização de dados interna por thread e encerramento. É específico para a versão do compilador usada. Essa biblioteca é sempre estaticamente vinculada, mesmo ao usar um UCRT vinculada dinamicamente.  
  
 Esta tabela lista as bibliotecas que implementam CRT inicialização e término.  
  
|Biblioteca|Características|Opção|Diretivas de pré\-processador|  
|----------------|---------------------|-----------|-----------------------------------|  
|libcmt|A inicialização nativa do CRT se vincula estaticamente no código.|**\/MT**|MT|  
|Libcmtd|A versão de depuração da inicialização do CRT nativa se vincula estaticamente. Não é redistribuível.|**\/MTd**|DEBUG, MT|  
|Msvcrt|Biblioteca estática para a inicialização nativa do CRT para uso com DLL UCRT e vcruntime.|**\/MD**|MT, DLL|  
|Msvcrtd|Biblioteca estática para a versão de depuração da inicialização do CRT nativa para uso com DLL UCRT e vcruntime. Não é redistribuível.|**\/MDd**|DEBUG MT, DLL|  
|msvcmrt.lib|Biblioteca estática para a inicialização do CRT nativa e gerenciada mista para uso com DLL UCRT e vcruntime.|**\/clr**||  
|msvcmrtd.lib|Biblioteca estática para a versão de depuração de inicialização mista nativa e gerenciada de CRT para uso com DLL UCRT e vcruntime. Não é redistribuível.|**\/clr**||  
|msvcurt.lib|Biblioteca estática para o CRT gerenciado puro.|**\/clr:pure**||  
|msvcurtd.lib|Biblioteca estática para a versão de depuração do CRT gerenciado puro. Não é redistribuível.|**\/clr:pure**||  
  
 Se você vincular o programa de linha de comando sem uma opção de compilador que especifica uma biblioteca de tempo de execução C, o vinculador será usar bibliotecas CRT estaticamente vinculadas: libcmt, libvcruntime.lib e libucrt.lib.  
  
 Usar o CRT estaticamente vinculado significa que qualquer informação de estado salva pela biblioteca de tempo de execução do C serão local para essa instância do CRT. Por exemplo, se você usar [strtok, \_strtok\_l, wcstok, \_wcstok\_l, \_mbstok, \_mbstok\_l](../Topic/strtok,%20_strtok_l,%20wcstok,%20_wcstok_l,%20_mbstok,%20_mbstok_l.md) ao usar um CRT vinculado estaticamente, a posição do `strtok` analisador não está relacionado ao `strtok` estado usado em código no mesmo processo \(mas em uma DLL ou EXE\) que está vinculado a outra instância do CRT estático. Por outro lado, o CRT dinamicamente vinculado compartilha estado para todo o código dentro de um processo que está vinculado dinamicamente a CRT. Essa preocupação não se aplica se você usar as novas versões mais seguras dessas funções; Por exemplo, `strtok_s` não tem esse problema.  
  
 Como uma DLL compilada vinculando a um CRT estático terá seu próprio estado CRT, não é recomendável vincular estaticamente a CRT em uma DLL, a menos que as consequências disso são especificamente desejadas e compreendidas. Por exemplo, se você chamar [set\_se\_translator](../c-runtime-library/reference/set-se-translator.md) em um executável que carrega a DLL vinculada a seu próprio CRT estático, as exceções de hardware geradas pelo código na DLL não serão detectadas, o tradutor, mas as exceções de hardware geradas pelo código no executável principal serão detectadas.  
  
 Se você estiver usando o **\/clr** comutador de compilador, seu código será vinculado com uma biblioteca estática, msvcmrt.lib. A biblioteca estática fornece um proxy entre o código gerenciado e nativo CRT. Não é possível usar o CRT vinculado estaticamente \( **\/MT** ou **\/MTd** Opções\) com **\/clr**. Usar as bibliotecas de vínculo dinâmico \(**\/MD** ou **\/MDd**\) em vez disso.  
  
 Se você estiver usando o **\/clr:pure** comutador de compilador, seu código será vinculado a msvcurt.lib biblioteca estática. Assim como acontece com **\/clr**, você não pode vincular com a biblioteca vinculada estaticamente.  
  
 Para obter mais informações sobre como usar o CRT com **\/clr**, consulte [Assemblies mistos \(nativos e gerenciados\)](../Topic/Mixed%20\(Native%20and%20Managed\)%20Assemblies.md); para **\/clr:pure**, consulte [Código puro e verificável](../dotnet/pure-and-verifiable-code-cpp-cli.md).  
  
 Para criar uma versão de depuração do seu aplicativo, o [Debug](../Topic/_DEBUG.md) sinalizador deve ser definido e o aplicativo deve ser vinculado a uma versão de depuração de uma dessas bibliotecas. Para obter mais informações sobre como usar as versões de depuração dos arquivos de biblioteca, consulte [técnicas de depuração CRT](../Topic/CRT%20Debugging%20Techniques.md).  
  
 Esta versão do CRT não é totalmente compatível com o padrão C99. Em particular, o cabeçalho \< tgmath \> e as macros de pragma CX\_LIMITED\_RANGE\/FP\_CONTRACT não são suportadas. Certos elementos, como o significado dos especificadores de parâmetro em funções de e\/s padrão usam interpretações herdadas por padrão. Você pode usar opções de conformidade do compilador \/Zc e especificar as opções do vinculador para controlar alguns aspectos de conformidade de biblioteca  
  
## Biblioteca Padrão C\+\+  
  
|Biblioteca Padrão C\+\+|Características|Opção|Diretivas de pré\-processador|  
|-----------------------------|---------------------|-----------|-----------------------------------|  
|LIBCPMT. LIB|Link multithread, estático|**\/MT**|MT|  
|MSVCPRT. LIB|Multithread, dynamic link \(biblioteca de importação. dll MSVCP \< versão \>\)|**\/MD**|MT, DLL|  
|LIBCPMTD. LIB|Link multithread, estático|**\/MTd**|DEBUG, MT|  
|MSVCPRTD. LIB|Multithread, dynamic link \(biblioteca de importação para MSVCP \< versão \> d. dll\)|**\/MDd**|DEBUG MT, DLL|  
  
 Quando você cria uma versão de lançamento do seu projeto, uma das bibliotecas de tempo de execução básicas do C \(LIBCMT. LIB, MSVCMRT. LIB, MSVCRT. LIB\) é vinculado por padrão, dependendo da opção de compilador que você escolher \(multithreaded, DLL, \/clr\). Se você incluir o [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md) no seu código, uma biblioteca C\+\+ padrão será vinculada no automaticamente pelo [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] em tempo de compilação. Por exemplo:  
  
```  
#include <ios>   
```  
  
## Quais problemas existirem se um aplicativo usa mais de uma versão de CRT?  
 Se você tiver mais de uma DLL ou EXE, você pode ter mais de um CRT, se você estiver usando versões diferentes do ou não [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)]. Por exemplo, a vinculação estática CRT em várias DLLs pode apresentar o mesmo problema. Os desenvolvedores encontrar esse problema com CRTs estáticos tem sido instruídos a compilar com **\/MD** para usar a DLL do CRT. Se suas DLLs passam recursos CRT além do limite DLL, você pode encontrar problemas com CRTs incompatíveis e precisará recompilar o projeto com o Visual C\+\+.  
  
 Se seu programa está usando mais de uma versão do CRT, algum cuidado é necessária ao passar determinados objetos CRT \(como identificadores de arquivos, locais e variáveis de ambiente\) em limites de DLL. Para obter mais informações sobre os problemas envolvidos e como resolvê\-los, consulte [Erros em potencial passando por objetos CRT em limites de DLL](../c-runtime-library/potential-errors-passing-crt-objects-across-dll-boundaries.md).  
  
## Consulte também  
 [Referência da biblioteca em tempo de execução do C](../c-runtime-library/c-run-time-library-reference.md)