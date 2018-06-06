---
title: / DEPENDENTLOADFLAG (definir sinalizadores de carga dependente padrão)
description: A opção /DEPENDENTLOADFLAG define os sinalizadores de padrão para DLLs carregadas usando LoadLibrary
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
ms.openlocfilehash: 5a171f3c2edbbbf614a986ff78dd2405e734a1d1
ms.sourcegitcommit: d1f576a0f59678edc3d93508cf46485138332178
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "34753702"
---
# <a name="dependentloadflag-set-default-dependent-load-flags"></a>/ DEPENDENTLOADFLAG (definir sinalizadores de carga dependente padrão)

Define os sinalizadores de carga padrão usado quando `LoadLibrary` é usado para carregar DLLs.

## <a name="syntax"></a>Sintaxe

> **/ DEPENDENTLOADFLAG**[**:**_loadflags_]

### <a name="arguments"></a>Arguments

|||
|-|-|
*loadflags*|Um valor de inteiro de 16 bits de estilo "C" opcional em octal com um zero à esquerda, decimal ou hexadecimal com um prefixo de `0x`, que especifica os sinalizadores de carga dependentes para aplicar a todos os [LoadLibrary](https://go.microsoft.com/fwlink/p/?LinkID=259187) chamadas. O valor padrão é 0.

## <a name="remarks"></a>Comentários

Essa opção é nova no Visual Studio de 2017 e se aplica somente aos aplicativos em execução no Windows 10 RS1 e versões posteriores. Essa opção é ignorada por outros sistemas operacionais que executam o aplicativo.

Em sistemas operacionais com suporte, essa opção tem o efeito de alterar as chamadas para `LoadLibrary("dependent.dll")` equivalente a `LoadLibraryEx("dependent.dll", 0, loadflags)`. Chamadas para [LoadLibraryEx](https://go.microsoft.com/fwlink/p/?LinkID=236091) não são afetados. Essa opção não se aplica recursivamente para DLLs carregadas pelo seu aplicativo.

Este sinalizador pode ser usado para impedir que a DLL implantem ataques. Por exemplo, se um aplicativo usa `LoadLibrary` para carregar uma DLL dependente, um invasor poderia introduzir uma DLL com o mesmo nome no caminho de pesquisa usado pelo `LoadLibrary`, como o diretório atual, que podem ser verificado antes de diretórios do sistema se for de modo seguro de pesquisa DLL desabilitado. Modo de pesquisa DLL segurança coloca o diretório do usuário atual posteriormente na ordem de pesquisa e é habilitado por padrão no Windows XP SP2 e versões posteriores. Para obter mais informações, consulte [ordem de pesquisa de biblioteca de vínculo dinâmico](https://msdn.microsoft.com/library/windows/desktop/ms682586.aspx).

Se você especificar a opção de link `/DEPENDENTLOADFLAG:0xA00` (o valor dos sinalizadores combinados `LOAD_LIBRARY_SEARCH_APPLICATION_DIR | LOAD_LIBRARY_SEARCH_SYSTEM32`), em seguida, mesmo se o modo de segurança de pesquisa DLL está desabilitado no computador do usuário, o caminho de pesquisa DLL é limitado a diretórios protegidos que serão mais difícil para um invasor Altere. Para obter informações sobre os sinalizadores disponíveis e seus valores numéricos e simbólicos, consulte o *dwFlags* descrição do parâmetro no [LoadLibraryEx](https://go.microsoft.com/fwlink/p/?LinkID=236091).

### <a name="to-set-the-dependentloadflag-linker-option-in-the-visual-studio-development-environment"></a>Para definir a opção de vinculador DEPENDENTLOADFLAG no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. Insira a opção no **opções adicionais**.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

- [Definindo opções de vinculador](setting-linker-options.md)
- [Opções do vinculador](linker-options.md)
- [Como vincular implicitamente para uma DLL](../linking-an-executable-to-a-dll.md#linking-implicitly)
- [Determinar qual método de associação usar](../linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use)
- [LoadLibrary](https://go.microsoft.com/fwlink/p/?LinkID=259187)
- [LoadLibraryEx](https://go.microsoft.com/fwlink/p/?LinkID=236091)
- [Ordem de pesquisa de biblioteca de vínculo dinâmico](https://msdn.microsoft.com/library/windows/desktop/ms682586.aspx)
