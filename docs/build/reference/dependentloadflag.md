---
title: / DEPENDENTLOADFLAG (definir sinalizadores de carregamento dependente padrão)
description: A opção /DEPENDENTLOADFLAG define sinalizadores padrão para DLLs carregadas usando LoadLibrary
ms.custom: ''
ms.date: 05/18/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- dependentloadflag
dev_langs:
- C++
helpviewer_keywords:
- LINK tool [C++], dependent load flags
- -DEPENDENTLOADFLAG linker option
- linker [C++], DEPENDENTLOADFLAG
- DEPENDENTLOADFLAG linker option
- /DEPENDENTLOADFLAG linker option
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0b6d5099e90e4a4bf83874fe8e761280bc277830
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43688111"
---
# <a name="dependentloadflag-set-default-dependent-load-flags"></a>/ DEPENDENTLOADFLAG (definir sinalizadores de carregamento dependente padrão)

Define os sinalizadores de carga padrão usado quando `LoadLibrary` é usado para carregar as DLLs.

## <a name="syntax"></a>Sintaxe

> **/ DEPENDENTLOADFLAG**[**:**_loadflags_]

### <a name="arguments"></a>Arguments

|||
|-|-|
*loadflags*|Um valor de inteiro de 16 bits de estilo "C" opcional em decimal, octal com um zero à esquerda ou hexadecimais com um líder `0x`, que especifica os sinalizadores de carregamento dependente para aplicar a todos [LoadLibrary](/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa) chamadas. O valor padrão é 0.

## <a name="remarks"></a>Comentários

Essa opção é nova no Visual Studio 2017 e só se aplica a aplicativos em execução no Windows 10 RS1 e versões posteriores. Essa opção é ignorada por outros sistemas operacionais que executam o aplicativo.

Em sistemas operacionais com suporte, essa opção tem o efeito de alterar as chamadas para `LoadLibrary("dependent.dll")` equivalente a `LoadLibraryEx("dependent.dll", 0, loadflags)`. Chamadas para [LoadLibraryEx](/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa) não são afetados. Essa opção não é aplicada recursivamente para DLLs carregadas pelo seu aplicativo.

Este sinalizador pode ser usado para impedir que a DLL implantem ataques. Por exemplo, se um aplicativo usa `LoadLibrary` para carregar uma DLL dependente, um invasor poderia introduzir uma DLL com o mesmo nome no caminho de pesquisa usado pelo `LoadLibrary`, como o diretório atual, que pode ser verificado antes de diretórios do sistema se for de modo seguro de pesquisa DLL desabilitada. Modo de pesquisa DLL segurança coloca o diretório atual do usuário mais tarde na ordem de pesquisa e é habilitado por padrão no Windows XP SP2 e versões posteriores. Para obter mais informações, consulte [ordem de pesquisa de biblioteca de vínculo dinâmico](/windows/desktop/Dlls/dynamic-link-library-search-order).

Se você especificar a opção de link `/DEPENDENTLOADFLAG:0xA00` (o valor dos sinalizadores combinados `LOAD_LIBRARY_SEARCH_APPLICATION_DIR | LOAD_LIBRARY_SEARCH_SYSTEM32`), em seguida, mesmo se o modo de pesquisa DLL seguro está desabilitado no computador do usuário, o caminho de pesquisa DLL é limitado a diretórios protegidos que estão mais difícil para um invasor Altere. Para obter informações sobre os sinalizadores disponíveis e seus valores simbólicos e numéricos, consulte o *dwFlags* descrição do parâmetro na [LoadLibraryEx](/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa).

### <a name="to-set-the-dependentloadflag-linker-option-in-the-visual-studio-development-environment"></a>Para definir a opção de vinculador DEPENDENTLOADFLAG no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. Insira a opção no **opções adicionais**.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

- [Definindo opções de vinculador](setting-linker-options.md)
- [Opções do vinculador](linker-options.md)
- [Como vincular implicitamente para uma DLL](../linking-an-executable-to-a-dll.md#linking-implicitly)
- [Determinar qual método de vinculação usar](../linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use)
- [LoadLibraryEx](/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibraryexa)
- [Ordem de pesquisa de biblioteca de vínculo dinâmico](/windows/desktop/Dlls/dynamic-link-library-search-order)
