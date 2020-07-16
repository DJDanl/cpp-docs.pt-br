---
title: /HIGHENTROPYVA
ms.date: 06/12/2018
f1_keywords:
- /HIGHENTROPYVA
helpviewer_keywords:
- HIGHENTROPYVA editbin option
- -HIGHENTROPYVA editbin option
- /HIGHENTROPYVA editbin option
ms.assetid: ef4b7c63-440d-40ca-b39d-edefb3217505
ms.openlocfilehash: 1adc12c0673764460b4af5eb7cf3b394d9666e81
ms.sourcegitcommit: 6b3d793f0ef3bbb7eefaf9f372ba570fdfe61199
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/15/2020
ms.locfileid: "86404093"
---
# <a name="highentropyva"></a>/HIGHENTROPYVA

Especifica se a imagem executável dá suporte a alta-entropia (randomização de layout de espaço de endereço) de 64 bits (ASLR).

## <a name="syntax"></a>Sintaxe

> **`/HIGHENTROPYVA`**[**`:NO`**]

## <a name="remarks"></a>Comentários

Essa opção modifica o cabeçalho de um arquivo de *imagem executável* (por exemplo, um *`.dll`* *`.exe`* arquivo ou), para indicar suporte para ASLR de endereço de 64 bits. Para ter um efeito, defina a opção no executável e todos os módulos dos quais ele depende. Em seguida, os sistemas operacionais que dão suporte a ASLR de 64 bits podem trocar os segmentos da imagem executável no tempo de carregamento usando endereços virtuais aleatórios de 64 bits. Esse grande espaço de endereço torna mais difícil para um invasor adivinhar a localização de uma região de memória específica.

Por padrão, o vinculador permite **`/HIGHENTROPYVA`** imagens executáveis de 64 bits. Essa opção requer [`/DYNAMICBASE`](dynamicbase.md) e [`/LARGEADDRESSAWARE`](largeaddressaware.md) , que também são habilitados por padrão para imagens de 64 bits. **`/HIGHENTROPYVA`** Não é aplicável a imagens executáveis de 32 bits, em que a opção é ignorada. Para desabilitar explicitamente essa opção, use **`/HIGHENTROPYVA:NO`** .

## <a name="see-also"></a>Confira também

[Opções de EDITBIN](editbin-options.md)\
[`/DYNAMICBASE`](dynamicbase.md)\
[`/LARGEADDRESSAWARE`](largeaddressaware.md)\
[Defesas de segurança de software ISV do Windows](https://docs.microsoft.com/previous-versions/bb430720(v=msdn.10))
