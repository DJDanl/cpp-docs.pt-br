---
title: /HIGHENTROPYVA (dar suporte a ASLR de 64 bits)
ms.date: 06/12/2018
ms.assetid: fe35f9f7-d28e-4694-9aeb-a79db06168e0
ms.openlocfilehash: ead296b1bd31171fb1a187685f407f6a0cf8a74c
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88835019"
---
# <a name="highentropyva-support-64-bit-aslr"></a>/HIGHENTROPYVA (dar suporte a ASLR de 64 bits)

Especifica se a imagem executável dá suporte a alta-entropia (randomização de layout de espaço de endereço) de 64 bits (ASLR).

## <a name="syntax"></a>Sintaxe

> **`/HIGHENTROPYVA`**[**`:NO`**]

## <a name="remarks"></a>Comentários

**`/HIGHENTROPYVA`** modifica o cabeçalho de um arquivo de *imagem executável* (por exemplo, um *`.dll`* *`.exe`* arquivo ou), para indicar se a ASLR pode usar todo o espaço de endereço de 64 bits.  Para ter um efeito, defina a opção no executável e todos os módulos dos quais ele depende. Em seguida, um sistema operacional que dá suporte a ASLR de 64 bits pode trocar os segmentos da imagem executável no tempo de carregamento usando endereços virtuais aleatórios de 64 bits. Esse grande espaço de endereço torna mais difícil para um invasor adivinhar a localização de uma região de memória específica.

Por padrão, o **`/HIGHENTROPYVA`** é habilitado para imagens executáveis de 64 bits. Essa opção requer [`/LARGEADDRESSAWARE`](largeaddressaware-handle-large-addresses.md) , que também está habilitada por padrão para imagens de 64 bits. **`/HIGHENTROPYVA`** Não é aplicável a imagens executáveis de 32 bits, em que o vinculador ignora a opção. Para desabilitar explicitamente essa opção, use **`/HIGHENTROPYVA:NO`** .

Para que **`/HIGHENTROPYVA`** o tenha um efeito no tempo de carregamento, [`/DYNAMICBASE`](dynamicbase-use-address-space-layout-randomization.md) também deve ser habilitado. **`/DYNAMICBASE`** é habilitado por padrão e é necessário para habilitar a ASLR no Windows Vista e em sistemas operacionais posteriores. As versões anteriores do Windows ignoram esse sinalizador.

### <a name="to-set-this-linker-option-in-visual-studio"></a>Para definir essa opção do vinculador no Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade da linha de comando do**vinculador**de propriedades de configuração  >  **Command Line** .

1. Em **Opções adicionais**, digite `/HIGHENTROPYVA` ou `/HIGHENTROPYVA:NO` .

## <a name="see-also"></a>Confira também

- [Referência de vinculador MSVC](linking.md)
- [Opções de vinculador MSVC](linker-options.md)
- [`/DYNAMICBASE`](dynamicbase-use-address-space-layout-randomization.md)
- [`/LARGEADDRESSAWARE`](largeaddressaware-handle-large-addresses.md)
- [Defesas de segurança de software ISV do Windows](/previous-versions/bb430720(v=msdn.10))
