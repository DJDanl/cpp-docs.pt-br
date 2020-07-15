---
title: /HIGHENTROPYVA (dar suporte a ASLR de 64 bits)
ms.date: 06/12/2018
ms.assetid: fe35f9f7-d28e-4694-9aeb-a79db06168e0
ms.openlocfilehash: 8f8601d89e8456461aac3d91f9fd2cfda216d7f5
ms.sourcegitcommit: 31a443c9998cf5cfbaff00fcf815b133f55b2426
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/14/2020
ms.locfileid: "86373834"
---
# <a name="highentropyva-support-64-bit-aslr"></a>/HIGHENTROPYVA (dar suporte a ASLR de 64 bits)

Especifica se a imagem executável dá suporte a alta-entropia (randomização de layout de espaço de endereço) de 64 bits (ASLR).

## <a name="syntax"></a>Syntax

> **/HIGHENTROPYVA**[**: no**]

## <a name="remarks"></a>Comentários

**/HIGHENTROPYVA** modifica o cabeçalho de uma *imagem executável*, um arquivo. dll ou um arquivo. exe, para indicar se a ASLR pode usar todo o espaço de endereço de 64 bits. Quando essa opção é definida em um arquivo executável e todos os módulos dos quais depende, um sistema operacional que dê suporte a ASLR de 64 bits pode rebasear os segmentos da imagem executável no tempo de carregamento usando endereços aleatórios em um espaço de endereço virtual de 64 bits. Esse grande espaço de endereço torna mais difícil para um invasor adivinhar a localização de uma região de memória específica.

Por padrão, o **/HIGHENTROPYVA** está habilitado para imagens executáveis de 64 bits. Essa opção requer [/LARGEADDRESSAWARE](largeaddressaware-handle-large-addresses.md), que também é habilitado por padrão para imagens de 64 bits. **/HIGHENTROPYVA** não é aplicável a imagens executáveis de 32 bits, em que o vinculador ignora a opção. Para desabilitar explicitamente essa opção, use **/HIGHENTROPYVA: no**.

Para que o **/HIGHENTROPYVA** tenha um efeito no tempo de carregamento, [/DynamicBase](dynamicbase-use-address-space-layout-randomization.md) também deve ser habilitado. O **/DynamicBase** é habilitado por padrão e é necessário para habilitar a ASLR no Windows Vista e em sistemas operacionais posteriores. As versões anteriores do Windows ignoram esse sinalizador.

### <a name="to-set-this-linker-option-in-visual-studio"></a>Para definir essa opção do vinculador no Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade da linha de comando do**vinculador**de propriedades de configuração  >  **Command Line** .

1. Em **Opções adicionais**, digite `/HIGHENTROPYVA` ou `/HIGHENTROPYVA:NO` .

## <a name="see-also"></a>Confira também

- [Referência de vinculador MSVC](linking.md)
- [Opções do vinculador MSVC](linker-options.md)
- [/DYNAMICBASE](dynamicbase-use-address-space-layout-randomization.md)
- [/LARGEADDRESSAWARE](largeaddressaware-handle-large-addresses.md)
- [Defesas de segurança de software ISV do Windows](https://docs.microsoft.com/previous-versions/bb430720(v=msdn.10))
