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
ms.openlocfilehash: b2ff9929de74d99fbc45e4f4ff38fd6b939697bc
ms.sourcegitcommit: 31a443c9998cf5cfbaff00fcf815b133f55b2426
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/14/2020
ms.locfileid: "86373821"
---
# <a name="highentropyva"></a>/HIGHENTROPYVA

Especifica se a imagem executável dá suporte a alta-entropia (randomização de layout de espaço de endereço) de 64 bits (ASLR).

## <a name="syntax"></a>Syntax

> **/HIGHENTROPYVA**[**: no**]

## <a name="remarks"></a>Comentários

Essa opção modifica o cabeçalho de uma *imagem executável*, um arquivo. dll ou um arquivo. exe, para indicar se o ASLR com endereços de 64 bits tem suporte. Quando essa opção é definida em um arquivo executável e todos os módulos dos quais depende, um sistema operacional que dê suporte a ASLR de 64 bits pode rebasear os segmentos da imagem executável no tempo de carregamento usando endereços aleatórios em um espaço de endereço virtual de 64 bits. Esse grande espaço de endereço torna mais difícil para um invasor adivinhar a localização de uma região de memória específica.

Por padrão, o vinculador permite **/HIGHENTROPYVA** para imagens executáveis de 64 bits. Essa opção requer [/LARGEADDRESSAWARE](largeaddressaware.md), que também é habilitado por padrão para imagens de 64 bits. **/HIGHENTROPYVA** não é aplicável a imagens executáveis de 32 bits, em que a opção é ignorada. Para desabilitar explicitamente essa opção, use **/HIGHENTROPYVA: no**. Para que essa opção tenha um efeito, a opção [/DynamicBase](dynamicbase.md) também deve ser definida.

## <a name="see-also"></a>Confira também

- [Opções de EDITBIN](editbin-options.md)
- [/DYNAMICBASE](dynamicbase.md)
- [Defesas de segurança de software ISV do Windows](https://docs.microsoft.com/previous-versions/bb430720(v=msdn.10))
