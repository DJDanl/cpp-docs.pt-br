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
ms.openlocfilehash: 80e34a3f57974e1af6afb65196697cce9aa344b1
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88834993"
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
[Defesas de segurança de software ISV do Windows](/previous-versions/bb430720(v=msdn.10))
