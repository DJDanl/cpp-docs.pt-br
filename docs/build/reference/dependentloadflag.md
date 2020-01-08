---
title: /DEPENDENTLOADFLAG (definir padrão de sinalizadores de carregamento dependente)
description: A opção/DEPENDENTLOADFLAG define sinalizadores padrão para DLLs carregadas usando LoadLibrary
ms.date: 12/22/2018
f1_keywords:
- dependentloadflag
helpviewer_keywords:
- LINK tool [C++], dependent load flags
- -DEPENDENTLOADFLAG linker option
- linker [C++], DEPENDENTLOADFLAG
- DEPENDENTLOADFLAG linker option
- /DEPENDENTLOADFLAG linker option
ms.openlocfilehash: 3a403f22c88ccd3e25ba95c183656ad2ffafd05a
ms.sourcegitcommit: ef34a11cb04511221bf5c7b9f4f55ad91a7a603f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/23/2019
ms.locfileid: "75329992"
---
# <a name="dependentloadflag-set-default-dependent-load-flags"></a>/DEPENDENTLOADFLAG (definir padrão de sinalizadores de carregamento dependente)

Define os sinalizadores de carga padrão usados quando `LoadLibrary` é usado para carregar DLLs.

## <a name="syntax"></a>Sintaxe

> **/DEPENDENTLOADFLAG**[ __:__ *load_flags*]

### <a name="arguments"></a>Arguments

*load_flags*<br/>
Um valor de inteiro de 16 bits com estilo "C" opcional em decimal, octal com um zero à esquerda ou hexadecimal com um `0x`à esquerda, que especifica os sinalizadores de carregamento dependentes a serem aplicados a todas as chamadas de [LoadLibrary](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw) . O valor padrão é 0.

## <a name="remarks"></a>Comentários

Essa opção é nova no Visual Studio 2017. Ele se aplica somente a aplicativos em execução no Windows 10 RS1 e versões posteriores. Essa opção é ignorada por outros sistemas operacionais que executam o aplicativo.

Em sistemas operacionais com suporte, essa opção tem o efeito de alterar chamadas para `LoadLibrary("dependent.dll")` ao equivalente de `LoadLibraryEx("dependent.dll", 0, load_flags)`. As chamadas para [LoadLibraryEx](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw) não são afetadas. Essa opção não se aplica recursivamente às DLLs carregadas pelo seu aplicativo.

Esse sinalizador pode ser usado para tornar os [ataques de planta de dll](/windows/win32/dlls/dynamic-link-library-security) mais difíceis. Por exemplo, se um aplicativo usar `LoadLibrary` para carregar uma DLL dependente, um invasor poderá implantar uma DLL com o mesmo nome no caminho de pesquisa usado pelo `LoadLibrary`, como o diretório atual, que pode ser verificado antes dos diretórios do sistema se o modo de pesquisa de DLL seguro estiver desabilitado. O modo de pesquisa de DLL seguro coloca o diretório atual do usuário mais tarde na ordem de pesquisa e é habilitado por padrão no Windows XP SP2 e versões posteriores. Para obter mais informações, consulte [ordem de pesquisa da biblioteca de vínculo dinâmico](/windows/win32/Dlls/dynamic-link-library-search-order).

Se você especificar a opção de link `/DEPENDENTLOADFLAG:0xA00` (o valor dos sinalizadores combinados `LOAD_LIBRARY_SEARCH_APPLICATION_DIR | LOAD_LIBRARY_SEARCH_SYSTEM32`), mesmo que o modo de pesquisa de DLL seguro esteja desabilitado no computador do usuário, o caminho de pesquisa da DLL será limitado ao diretório do aplicativo, seguido pelo diretório%Windows%\System32. Uma opção de `/DEPENDENTLOADFLAG:0x800` é ainda mais restritiva, limitando a pesquisa ao diretório%Windows%\System32. Os diretórios protegidos são mais difíceis, mas não impossíveis, para que um invasor mude. Para obter informações sobre os sinalizadores disponíveis e seus valores simbólicos e numéricos, consulte a descrição do parâmetro *dwFlags* em [LoadLibraryEx](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw). Para obter informações sobre a ordem de pesquisa usada quando vários sinalizadores de carregamento dependentes são usados, consulte [ordem de pesquisa usando sinalizadores de LOAD_LIBRARY_SEARCH](/windows/win32/dlls/dynamic-link-library-search-order#search-order-using-load_library_search-flags).

### <a name="to-set-the-dependentloadflag-linker-option-in-the-visual-studio-development-environment"></a>Para definir a opção de vinculador DEPENDENTLOADFLAG no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **página de propriedades de** linha de **comando** do > **vinculador > conexão** .

1. Insira a opção em **Opções adicionais**.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Veja também

- [Referência de vinculador MSVC](linking.md)
- [Opções de vinculador MSVC](linker-options.md)
- [Vincular um executável a uma DLL](../linking-an-executable-to-a-dll.md#linking-implicitly)
- [Vincular um executável a uma DLL](../linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use)
- [LoadLibraryEx](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw)
- [Ordem de pesquisa da biblioteca de vínculo dinâmico](/windows/win32/Dlls/dynamic-link-library-search-order)
