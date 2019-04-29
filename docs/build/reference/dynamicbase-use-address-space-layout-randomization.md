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
ms.openlocfilehash: a3495de3ec72bcac78cdee2f5f3265864e7a2932
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62293063"
---
# <a name="dynamicbase-use-address-space-layout-randomization"></a>/DYNAMICBASE (usar aleatorização do layout de espaço do endereço)

Especifica se deve gerar uma imagem executável que possa ter REBASE aleatória no momento do carregamento usando o recurso de aleatoriedade (ASLR) de layout de espaço de endereço do Windows que foi disponibilizado inicialmente no Windows Vista.

## <a name="syntax"></a>Sintaxe

> **/DYNAMICBASE**[**:NO**]

## <a name="remarks"></a>Comentários

O **/DYNAMICBASE** opção modifica o cabeçalho de uma *imagem executável*, um arquivo. dll ou .exe, para indicar se o aplicativo deve ter REBASE aleatória no tempo de carregamento e permite que o endereço virtual randomização de alocação, o que afeta o local da memória virtual de heaps, pilhas e outras alocações de sistema operacional. O **/DYNAMICBASE** opção se aplica a imagens de 32 bits e 64 bits. ASLR tem suporte no Windows Vista e sistemas operacionais posteriores. A opção é ignorada por sistemas operacionais anteriores.

Por padrão, **/DYNAMICBASE** está habilitado. Para desabilitar essa opção, use **/DYNAMICBASE: no**. O **/DYNAMICBASE** opção é necessária para o [/HIGHENTROPYVA](highentropyva-support-64-bit-aslr.md) opção para ter efeito.

### <a name="to-set-this-linker-option-in-visual-studio"></a>Para definir essa opção do vinculador no Visual Studio

1. Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **avançado** página de propriedades.

1. Modificar a **endereço Base aleatório** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.RandomizedBaseAddress%2A>.

## <a name="see-also"></a>Consulte também

- [Referência de vinculador MSVC](linking.md)
- [Opções de vinculador MSVC](linker-options.md)
- [/HIGHENTROPYVA](highentropyva-support-64-bit-aslr.md)
- [Defesas de segurança de Software ISV do Windows](https://msdn.microsoft.com/library/bb430720.aspx)