---
title: Funcionalidades da biblioteca CRT
description: Os arquivos que contêm as bibliotecas de tempo de execução do Microsoft C e suas opções de compilador e diretivas de pré-processador associadas.
ms.date: 09/03/2020
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
ms.openlocfilehash: 2f46577ba81c57c2050f0cae4ae2af73152ba2a4
ms.sourcegitcommit: 0df2b7ab4e81284c5248e4584767591dcc1950c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/09/2020
ms.locfileid: "89609102"
---
# <a name="crt-library-features"></a>Funcionalidades da biblioteca CRT

Este tópico aborda os vários arquivos .lib que compõem as bibliotecas em tempo de execução C, bem como suas opções do compilador e diretivas do pré-processador associadas.

## <a name="c-run-time-libraries-crt"></a>Bibliotecas em tempo de execução do C (CRT)

A Biblioteca em Tempo de Execução C (CRT) é a parte da Biblioteca Padrão C++ que incorpora a biblioteca padrão ISO C99. As bibliotecas do Visual C++ que implementam CRT são compatíveis com o desenvolvimento de código nativo e com a combinação de código nativo e gerenciado. Todas as versões do CRT dão suporte ao desenvolvimento multi-threaded. A maioria das bibliotecas dá suporte tanto à vinculação estática, para vincular a biblioteca diretamente no código, quanto à vinculação dinâmica, para permitir que o código use arquivos DLL comuns.

A partir do Visual Studio 2015, o CRT foi refatorado em novos binários. O UCRT (CRT Universal) contém as funções e os globais exportados pela biblioteca CRT C99 padrão. O UCRT agora é um componente do Windows e é fornecido como parte do Windows 10. A biblioteca estática, a biblioteca de importação de DLL e os arquivos de cabeçalho do UCRT agora são encontrados no SDK do Windows 10. Ao instalar o Visual C++, a instalação do Visual Studio instala o subconjunto do SDK do Windows 10 necessário para usar o UCRT. É possível usar o UCRT em qualquer versão do Windows com suporte no Visual Studio 2015 e versões posteriores. Você pode redistribuí-lo usando vcredist para versões com suporte do Windows que não sejam o Windows 10. Para obter mais informações, consulte [Redistribuindo arquivos do Visual C++](../windows/redistributing-visual-cpp-files.md).

A tabela a seguir lista as bibliotecas que implementam o UCRT.

| Biblioteca | DLL associada | Características | Opção | Diretivas do pré-processador |
|--|--|--|--|--|
| *`libucrt.lib`* | Nenhum | Vincula estaticamente o UCRT no código. | **`/MT`** | `_MT` |
| *`libucrtd.lib`* | Nenhum | Versão de depuração do UCRT para vinculação estática. Não redistribuível. | **`/MTd`** | `_DEBUG`, `_MT` |
| *`ucrt.lib`* | *`ucrtbase.dll`* | Biblioteca de importação de DLL do UCRT. | **`/MD`** | `_MT`, `_DLL` |
| *`ucrtd.lib`* | *`ucrtbased.dll`* | Biblioteca de importação de DLL para a versão de Depuração do UCRT. Não redistribuível. | **`/MDd`** | `_DEBUG`, `_MT`, `_DLL` |

A biblioteca vcruntime contém códigos específicos à implementação do CRT no Visual C++, como tratamento de exceção e suporte à depuração, verificações em tempo de execução e informações de tipo, detalhes de implementação e algumas funções de biblioteca estendidas. Essa biblioteca é específica à versão do compilador utilizada.

Esta tabela lista as bibliotecas que implementam a biblioteca vcruntime.

| Biblioteca | DLL associada | Características | Opção | Diretivas do pré-processador |
|--|--|--|--|--|
| *`libvcruntime.lib`* | Nenhum | Vinculada estaticamente no código. | **`/MT`** | `_MT` |
| *`libvcruntimed.lib`* | Nenhum | Versão de depuração para vinculação estática. Não redistribuível. | **`/MTd`** | `_MT`, `_DEBUG` |
| *`vcruntime.lib`* | *`vcruntime<version>.dll`* | Biblioteca de importação de DLL do vcruntime. | **`/MD`** | `_MT`, `_DLL` |
| *`vcruntimed.lib`* | *`vcruntime<version>d.dll`* | Biblioteca de importação de DLL do vcruntime de Depuração. Não redistribuível. | **`/MDd`** | `_DEBUG`, `_MT`, `_DLL` |

> [!NOTE]
> Quando a refatoração UCRT ocorreu, as funções Tempo de Execução de Simultaneidade foram movidas para *`concrt140.dll`* , que foram adicionadas ao pacote redistribuível C++. Essa DLL é necessária para os contêineres e algoritmos paralelos do C++, como `concurrency::parallel_for`. Além disso, a Biblioteca padrão do C++ requer que essa DLL no Windows XP dê suporte a primitivas de sincronização, porque o Windows XP não tem variáveis de condição.

O código que inicializa o CRT está em uma das várias bibliotecas, com base no fato de a biblioteca CRT ser vinculada estática ou dinamicamente ou de o código ser nativo, gerenciado ou misto. Esse código manipula a inicialização, a inicialização interna de dados por thread e o encerramento do CRT. Ele é específico à versão do compilador utilizada. Essa biblioteca é sempre vinculada estaticamente, mesmo ao usar um UCRT vinculado dinamicamente.

Esta tabela lista as bibliotecas que implementam a inicialização e o encerramento do CRT.

| Biblioteca | Características | Opção | Diretivas do pré-processador |
|--|--|--|--|
| *`libcmt.lib`* | Vincula estaticamente a inicialização nativa do CRT no código. | **`/MT`** | `_MT` |
| *`libcmtd.lib`* | Vincula estaticamente a versão de Depuração da inicialização nativa do CRT. Não redistribuível. | **`/MTd`** | `_DEBUG`, `_MT` |
| *`msvcrt.lib`* | Biblioteca estática da inicialização nativa do CRT para uso com o UCRT e o vcruntime da DLL. | **`/MD`** | `_MT`, `_DLL` |
| *`msvcrtd.lib`* | Biblioteca estática da versão de Depuração da inicialização nativa do CRT para uso com o UCRT e o vcruntime da DLL. Não redistribuível. | **`/MDd`** | `_DEBUG`, `_MT`, `_DLL` |
| *`msvcmrt.lib`* | Biblioteca estática da inicialização nativa e gerenciada mista do CRT para uso com o UCRT e o vcruntime da DLL. | **`/clr`** |  |
| *`msvcmrtd.lib`* | Biblioteca estática da versão de Depuração da inicialização nativa e gerenciada mista do CRT para uso com o UCRT e o vcruntime da DLL. Não redistribuível. | **`/clr`** |  |
| *`msvcurt.lib`* | Biblioteca estática **Preterida** para CRT gerenciado puro. | **`/clr:pure`** |  |
| *`msvcurtd.lib`* | Biblioteca estática **Preterida** para a versão de Depuração do CRT gerenciado puro. Não redistribuível. | **`/clr:pure`** |  |

Se você vincular o programa da linha de comando sem uma opção de compilador que especifica uma biblioteca de tempo de execução do C, o vinculador usará as bibliotecas CRT vinculadas estaticamente: *`libcmt.lib`* , *`libvcruntime.lib`* e *`libucrt.lib`* .

O uso do CRT vinculado estaticamente indica que todas as informações de estado salvas pela biblioteca de runtime C serão locais para essa instância do CRT. Por exemplo, se você usar [`strtok`](../c-runtime-library/reference/strtok-strtok-l-wcstok-wcstok-l-mbstok-mbstok-l.md) ao usar um CRT vinculado estaticamente, a posição do `strtok` analisador não estará relacionada ao `strtok` estado usado no código no mesmo processo (mas em uma DLL ou exe diferente) vinculada a outra instância do CRT estático. Por outro lado, o CRT vinculado dinamicamente compartilha o estado de todo o código em um processo que está vinculado dinamicamente ao CRT. Essa preocupação não se aplicará se você usar as novas versões mais seguras dessas funções; por exemplo, `strtok_s` não apresenta esse problema.

Como uma DLL compilada por meio da vinculação a um CRT estático terá seu próprio estado de CRT, não é recomendável vincular estaticamente ao CRT em uma DLL, a menos que as consequências dessa ação sejam especificamente desejadas e compreendidas. Por exemplo, se você chamar [`_set_se_translator`](../c-runtime-library/reference/set-se-translator.md) em um executável que carrega a dll vinculada a seu próprio CRT estático, qualquer exceção de hardware gerada pelo código na DLL não será detectada pelo tradutor, mas exceções de hardware geradas pelo código no executável principal serão capturadas.

Se você estiver usando a **`/clr`** opção do compilador, seu código será vinculado a uma biblioteca estática, msvcmrt. lib. A biblioteca estática fornece um proxy entre o código gerenciado e o CRT nativo. Você não pode usar o CRT ( **`/MT`** ou opções) vinculados estaticamente **`/MTd`** com **`/clr`** . Use as bibliotecas vinculadas dinamicamente ( **`/MD`** ou **`/MDd`** ) em vez disso. As bibliotecas de CRT gerenciado puro são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Para obter mais informações sobre como usar o CRT com o **`/clr`** , consulte [assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md).

Para criar uma versão de depuração do seu aplicativo, o [`_DEBUG`](../c-runtime-library/debug.md) sinalizador deve ser definido e o aplicativo deve ser vinculado a uma versão de depuração de uma dessas bibliotecas. Para obter mais informações sobre como usar as versões de depuração dos arquivos de biblioteca, consulte [Técnicas de depuração do CRT](/visualstudio/debugger/crt-debugging-techniques).

Essa versão do CRT não está em conformidade total com o padrão C99. Em versões anteriores ao Visual Studio 2019 versão 16,8, \<tgmath.h> não há suporte para o cabeçalho. Em todas as versões, `CX_LIMITED_RANGE` `FP_CONTRACT` não há suporte para as macros e pragma. Alguns elementos, como o significado dos especificadores de parâmetro em funções de E/S padrão, usam interpretações herdadas por padrão. Você pode usar **`/Zc`** as opções de conformidade do compilador e especificar as opções do vinculador para controlar alguns aspectos da conformidade da biblioteca.

## <a name="c-standard-library"></a>Biblioteca Padrão C++

| Biblioteca Padrão C++ | Características | Opção | Diretivas do pré-processador |
|--|--|--|--|
| *`libcpmt.lib`* | Multi-threaded, vínculo estático | **`/MT`** | `_MT` |
| *`msvcprt.lib`* | Multithread, link dinâmico (biblioteca de importação para *`msvcp<version>.dll`* ) | **`/MD`** | `_MT`, `_DLL` |
| *`libcpmtd.lib`* | Multi-threaded, vínculo estático | **`/MTd`** | `_DEBUG`, `_MT` |
| *`msvcprtd.lib`* | Multithread, link dinâmico (biblioteca de importação para *`msvcp<version>d.dll`* ) | **`/MDd`** | `_DEBUG`, `_MT`, `_DLL` |

Quando você cria uma versão de lançamento do seu projeto, uma das bibliotecas básicas de tempo de execução do C ( *`libcmt.lib`* , *`msvcmrt.lib`* , *`msvcrt.lib`* ) é vinculada por padrão, dependendo da opção do compilador que você escolher (multi-threaded, dll, **`/clr`** ). Quando você inclui um dos [arquivos de cabeçalho da Biblioteca Padrão C++](../standard-library/cpp-standard-library-header-files.md) no código, uma Biblioteca Padrão C++ é vinculada automaticamente pelo Visual C++ em tempo de compilação. Por exemplo:

```cpp
#include <ios>
```

Para a compatibilidade binária, mais de um arquivo DLL pode ser especificado por uma única biblioteca de importação. As atualizações de versão podem introduzir *bibliotecas dot*, DLLs separadas que apresentam uma nova funcionalidade de biblioteca. Por exemplo, a versão 15,6 do Visual Studio 2017 introduzida *`msvcp140_1.dll`* para dar suporte à funcionalidade de biblioteca padrão adicional sem interromper a Abi suportada pelo *`msvcp140.dll`* . A *`msvcprt.lib`* biblioteca de importação incluída no conjunto de ferramentas para o Visual Studio 2017 versão 15,6 dá suporte a ambas as DLLs, e o VCRedist para essa versão instala ambas as DLLs. Depois de fornecida, uma biblioteca dot terá uma ABI fixa e nunca terá uma dependência em uma biblioteca dot posterior.

## <a name="what-problems-exist-if-an-application-uses-more-than-one-crt-version"></a>Quais problemas poderão ocorrer se um aplicativo usar mais de uma versão do CRT?

Todas as imagens executáveis (EXE ou DLL) podem ter seu próprio CRT estaticamente vinculado ou podem vincular dinamicamente a um CRT. A versão do CRT, incluída estaticamente ou carregada dinamicamente por uma imagem específica, depende das versões das ferramentas e das bibliotecas com as quais ela foi compilada. Um único processo pode carregar várias imagens EXE e DLL, cada qual com seu próprio CRT. Cada um desses CRTs pode usar um alocador diferente, pode ter layouts de estruturas internas diferentes e pode usar combinações diferentes de armazenamento. Isso significa que a memória, os recursos de CRT ou as classes alocadas transmitidas em um limite de DLL podem causar problemas no gerenciamento de memória, no uso estático interno ou na interpretação de layout. Por exemplo, se uma classe é alocada em um DLL, mas transmitida para e excluída por outra, qual desalocador CRT será usado? Os erros causados podem variar de sutis ao imediatamente fatal e, portanto, a transferência direta de tais recursos não é recomendada.

Você pode evitar muitos desses problemas usando tecnologias ABI (Interface Binária de Aplicativo), pois elas são projetadas para serem estáveis e versáteis. Projete suas interfaces de exportação DLL para passar informações por valor ou para trabalhar na memória que é transmitida pelo chamador, em vez de alocada localmente e retornada ao chamador. Use técnicas de marshaling para copiar dados estruturados entre imagens executáveis. Encapsule os recursos localmente e só permita a manipulação por meio de identificadores ou funções que você expõe aos clientes.

Também é possível evitar alguns desses problemas, se todas as imagens em seu processo usarem a mesma versão carregada dinamicamente do CRT. Para garantir que todos os componentes usem a mesma versão de DLL do CRT, crie-os usando a **`/MD`** opção e use o mesmo conjunto de ferramentas e configurações de Propriedade do compilador.

Tenha cuidado se o programa passar determinados recursos CRT entre limites de DLL. Recursos como identificadores de arquivo, localidades e variáveis de ambiente podem causar problemas, mesmo ao usar a mesma versão do CRT. Para obter mais informações sobre os problemas envolvidos e como resolvê-los, consulte [Erros potenciais ao passar objetos do CRT em limites da DLL](../c-runtime-library/potential-errors-passing-crt-objects-across-dll-boundaries.md).

## <a name="see-also"></a>Confira também

- [Referência da biblioteca de tempo de execução C](../c-runtime-library/c-run-time-library-reference.md)
