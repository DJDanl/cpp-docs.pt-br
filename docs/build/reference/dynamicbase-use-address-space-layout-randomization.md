---
title: /DYNAMICBASE (usar aleatorização do layout de espaço do endereço)
ms.date: 06/12/2018
f1_keywords:
- VC.Project.VCLinkerTool.RandomizedBaseAddress
helpviewer_keywords:
- -DYNAMICBASE linker option
- /DYNAMICBASE linker option
- DYNAMICBASE linker option
ms.assetid: 6c0ced8e-fe9c-4b63-b956-eb8a55fbceb2
ms.openlocfilehash: 66d6232ed43f9c842ebbb0e22b57c509cf610afa
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80170053"
---
# <a name="dynamicbase-use-address-space-layout-randomization"></a>/DYNAMICBASE (usar aleatorização do layout de espaço do endereço)

Especifica se uma imagem executável pode ser gerada aleatoriamente com base no tempo de carregamento usando o recurso ASLR (Address Space layout Randomization) do Windows que foi disponibilizado pela primeira vez no Windows Vista.

## <a name="syntax"></a>Sintaxe

> **/DynamicBase**[ **: no**]

## <a name="remarks"></a>Comentários

A opção **/DynamicBase** modifica o cabeçalho de uma *imagem executável*, um arquivo. dll ou. exe, para indicar se o aplicativo deve ser baseado aleatoriamente com base no tempo de carregamento e habilita a randomização de alocação de endereço virtual, que afeta o local da memória virtual de heaps, pilhas e outras alocações do sistema operacional. A opção **/DynamicBase** se aplica a imagens de 32 bits e 64 bits. A ASLR tem suporte no Windows Vista e em sistemas operacionais posteriores. A opção é ignorada pelos sistemas operacionais anteriores.

Por padrão, o **/DynamicBase** está habilitado. Para desabilitar essa opção, use **/DynamicBase: no**. A opção **/DynamicBase** é necessária para que a opção [/HIGHENTROPYVA](highentropyva-support-64-bit-aslr.md) tenha um efeito.

### <a name="to-set-this-linker-option-in-visual-studio"></a>Para definir essa opção do vinculador no Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione as **Propriedades de configuração** > **vinculador** > página de propriedades **avançada** .

1. Modifique a propriedade de **endereço base aleatória** .

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.RandomizedBaseAddress%2A>.

## <a name="see-also"></a>Confira também

- [Referência de vinculador MSVC](linking.md)
- [Opções de vinculador MSVC](linker-options.md)
- [/HIGHENTROPYVA](highentropyva-support-64-bit-aslr.md)
- [Defesas de segurança de software ISV do Windows](https://msdn.microsoft.com/library/bb430720.aspx)
