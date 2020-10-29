---
title: /DEPENDENTLOADFLAG (definir padrão de sinalizadores de carregamento dependente)
description: A opção/DEPENDENTLOADFLAG define sinalizadores de carga dependentes padrão para DLLs carregadas por este módulo.
ms.date: 01/22/2020
f1_keywords:
- dependentloadflag
helpviewer_keywords:
- LINK tool [C++], dependent load flags
- -DEPENDENTLOADFLAG linker option
- linker [C++], DEPENDENTLOADFLAG
- DEPENDENTLOADFLAG linker option
- /DEPENDENTLOADFLAG linker option
ms.openlocfilehash: 8d0f53ed13143ed7ff5c507df73937a86c07b5b8
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92924204"
---
# <a name="dependentloadflag-set-default-dependent-load-flags"></a>/DEPENDENTLOADFLAG (definir padrão de sinalizadores de carregamento dependente)

::: moniker range="msvc-140"

A opção **/DEPENDENTLOADFLAG** requer o Visual Studio 2017 ou posterior.

::: moniker-end

::: moniker range=">=msvc-150"

Define os sinalizadores de carga padrão usados quando o sistema operacional resolve as importações estaticamente vinculadas de um módulo.

## <a name="syntax"></a>Syntax

> **/DEPENDENTLOADFLAG** [ __:__*load_flags* ]

### <a name="arguments"></a>Argumentos

*load_flags*<br/>
Um valor inteiro opcional que especifica os sinalizadores de carga a serem aplicados ao resolver dependências de importação vinculadas estaticamente do módulo. O valor padrão é 0. Para obter uma lista de valores de sinalizador com suporte, consulte as `LOAD_LIBRARY_SEARCH_*` entradas em [LoadLibraryEx](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw).

## <a name="remarks"></a>Comentários

Quando o sistema operacional resolve as importações estaticamente vinculadas de um módulo, ele usa a ordem de [pesquisa padrão](/windows/win32/dlls/dynamic-link-library-search-order). Use a opção **/DEPENDENTLOADFLAG** para especificar um valor *load_flags* que altera o caminho de pesquisa usado para resolver essas importações. Em sistemas operacionais com suporte, ele altera a ordem de pesquisa de resolução de importação estática, semelhante ao que o [LoadLibraryEx](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexa) faz ao usar `LOAD_LIBRARY_SEARCH` parâmetros. Para obter informações sobre a ordem de pesquisa definida por *load_flags* , consulte [ordem de pesquisa usando sinalizadores de LOAD_LIBRARY_SEARCH](/windows/win32/dlls/dynamic-link-library-search-order#search-order-using-load_library_search-flags).

Esse sinalizador pode ser usado para tornar um vetor de [ataque de planta de dll](/windows/win32/dlls/dynamic-link-library-security) mais difícil. Por exemplo, considere um aplicativo que tem uma DLL vinculada estaticamente:

- Um invasor pode implantar uma DLL com o mesmo nome anteriormente no caminho de pesquisa de resolução de importação, como o diretório do aplicativo. Os diretórios protegidos são mais difíceis, mas não impossíveis, para que um invasor mude.

- Se a DLL estiver ausente nos diretórios Application,%Windows%\System32 e% Windows%, a resolução de importação se enquadrará no diretório atual. Um invasor pode implantar uma DLL lá.

Em ambos os casos, se você especificar a opção de link `/DEPENDENTLOADFLAG:0x800` (o valor do sinalizador `LOAD_LIBRARY_SEARCH_SYSTEM32` ), o caminho de pesquisa do módulo será limitado ao diretório%Windows%\System32 Ele oferece alguma proteção contra a planta de ataques em outros diretórios. Para obter mais informações, consulte [segurança da biblioteca de vínculo dinâmico](/windows/win32/dlls/dynamic-link-library-security).

Para ver o valor definido pela opção **/DEPENDENTLOADFLAG** em qualquer DLL, use o comando [DUMPBIN](dumpbin-reference.md) com a opção [/LOADCONFIG](loadconfig.md) .

A opção **/DEPENDENTLOADFLAG** é nova no Visual Studio 2017. Ele se aplica somente a aplicativos em execução no Windows 10 RS1 e versões posteriores. Essa opção é ignorada por outros sistemas operacionais que executam o aplicativo.

### <a name="to-set-the-dependentloadflag-linker-option-in-the-visual-studio-development-environment"></a>Para definir a opção de vinculador DEPENDENTLOADFLAG no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties** > página de propriedade da linha de comando do **vinculador** de propriedades de configuração > **Command Line** .

1. Insira a opção em **Opções adicionais** .

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Veja também

- [Referência de vinculador MSVC](linking.md)
- [Opções de vinculador MSVC](linker-options.md)
- [Vincular um executável a uma DLL implicitamente](../linking-an-executable-to-a-dll.md#linking-implicitly)
- [Determinar qual método de vinculação usar](../linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use)
- [LoadLibraryEx](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw)
- [Ordem de pesquisa da biblioteca de vínculo dinâmico](/windows/win32/Dlls/dynamic-link-library-search-order)
- [Segurança da biblioteca de vínculo dinâmico](/windows/win32/dlls/dynamic-link-library-security)

::: moniker-end
