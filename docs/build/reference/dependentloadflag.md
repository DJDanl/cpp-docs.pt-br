---
title: /DEPENDENTLOADFLAG (definir padrão de sinalizadores de carregamento dependente)
description: A opção/DEPENDENTLOADFLAG define sinalizadores padrão para DLLs carregadas usando LoadLibrary
ms.date: 05/18/2018
f1_keywords:
- dependentloadflag
helpviewer_keywords:
- LINK tool [C++], dependent load flags
- -DEPENDENTLOADFLAG linker option
- linker [C++], DEPENDENTLOADFLAG
- DEPENDENTLOADFLAG linker option
- /DEPENDENTLOADFLAG linker option
ms.openlocfilehash: 072fa1103d049c7d5c395ae88d268f3b47e20b4f
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492948"
---
# <a name="dependentloadflag-set-default-dependent-load-flags"></a>/DEPENDENTLOADFLAG (definir padrão de sinalizadores de carregamento dependente)

Define os sinalizadores de carga padrão usados `LoadLibrary` quando o é usado para carregar DLLs.

## <a name="syntax"></a>Sintaxe

> **/DEPENDENTLOADFLAG**[ **:** _loadflags_]

### <a name="arguments"></a>Arguments

*loadflags*<br/>
Um valor de inteiro de 16 bits com estilo "C" opcional em decimal, octal com um zero à esquerda ou hexadecimal com uma `0x`entrelinha, que especifica os sinalizadores de carga dependentes a serem aplicados a todas as chamadas de [LoadLibrary](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw) . O valor padrão é 0.

## <a name="remarks"></a>Comentários

Essa opção é nova no Visual Studio 2017 e se aplica somente a aplicativos em execução no Windows 10 RS1 e versões posteriores. Essa opção é ignorada por outros sistemas operacionais que executam o aplicativo.

Em sistemas operacionais com suporte, essa opção tem o efeito de alterar chamadas `LoadLibrary("dependent.dll")` para para o equivalente `LoadLibraryEx("dependent.dll", 0, loadflags)`de. As chamadas para [LoadLibraryEx](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw) não são afetadas. Essa opção não se aplica recursivamente às DLLs carregadas pelo seu aplicativo.

Esse sinalizador pode ser usado para evitar ataques de planta de DLL. Por exemplo, se um aplicativo usar `LoadLibrary` o para carregar uma DLL dependente, um invasor poderá implantar uma DLL com o mesmo nome no caminho de pesquisa usado pelo `LoadLibrary`, como o diretório atual, que pode ser verificado antes dos diretórios do sistema se o modo de pesquisa de dll seguro for desabilitado. O modo de pesquisa de DLL seguro coloca o diretório atual do usuário mais tarde na ordem de pesquisa e é habilitado por padrão no Windows XP SP2 e versões posteriores. Para obter mais informações, consulte [ordem de pesquisa da biblioteca de vínculo dinâmico](/windows/win32/Dlls/dynamic-link-library-search-order).

Se você especificar a opção `/DEPENDENTLOADFLAG:0xA00` de link (o valor dos sinalizadores `LOAD_LIBRARY_SEARCH_APPLICATION_DIR | LOAD_LIBRARY_SEARCH_SYSTEM32`combinados), mesmo que o modo de pesquisa de dll seguro esteja desabilitado no computador do usuário, o caminho de pesquisa da dll será limitado a diretórios protegidos que são mais difíceis de ser um invasor alteração. Para obter informações sobre os sinalizadores disponíveis e seus valores simbólicos e numéricos, consulte a descrição do parâmetro *dwFlags* em [LoadLibraryEx](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw).

### <a name="to-set-the-dependentloadflag-linker-option-in-the-visual-studio-development-environment"></a>Para definir a opção de vinculador DEPENDENTLOADFLAG no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedade da**linha de comando** do**vinculador** > de **Propriedades** > de configuração.

1. Insira a opção em **Opções adicionais**.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

- [Referência de vinculador MSVC](linking.md)
- [Opções de vinculador MSVC](linker-options.md)
- [Vincular um executável a uma DLL](../linking-an-executable-to-a-dll.md#linking-implicitly)
- [Vincular um executável a uma DLL](../linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use)
- [LoadLibraryEx](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw)
- [Ordem de pesquisa da biblioteca de vínculo dinâmico](/windows/win32/Dlls/dynamic-link-library-search-order)
