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
ms.openlocfilehash: 90d3c868eaab85e3b1a2a416c9aa14b0e27ec8f9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50603977"
---
# <a name="highentropyva"></a>/HIGHENTROPYVA

Especifica se a imagem executável dá suporte a randomização de layout de espaço de endereço de 64 bits de alta entropia (ASLR).

## <a name="syntax"></a>Sintaxe

> **/ HIGHENTROPYVA**[**: NENHUMA**]

## <a name="remarks"></a>Comentários

Essa opção modifica o cabeçalho de uma *imagem executável*, um arquivo. dll ou .exe, para indicar se o ASLR com endereços de 64 bits tem suporte. Quando essa opção é definida em um arquivo executável e todos os módulos dos quais depende, um sistema operacional que dê suporte a ASLR de 64 bits pode rebasear os segmentos da imagem executável no tempo de carregamento usando endereços aleatórios em um espaço de endereço virtual de 64 bits. Esse grande espaço de endereço torna mais difícil para um invasor adivinhar a localização de uma região de memória específica.

Por padrão, o vinculador habilita **/HIGHENTROPYVA** para imagens executáveis de 64 bits. Essa opção exige [/LARGEADDRESSAWARE](largeaddressaware.md), que também é habilitado por padrão para as imagens de 64 bits. **/ HIGHENTROPYVA** não é aplicável para imagens executáveis de 32 bits, em que a opção será ignorada. Para desabilitar explicitamente essa opção, use **/highentropyva: no**. Para esta opção para ter um efeito, a [/DYNAMICBASE](dynamicbase.md) opção também deve ser definida.

## <a name="see-also"></a>Consulte também

- [Opções de EDITBIN](editbin-options.md)
- [/DYNAMICBASE](dynamicbase.md)
- [Defesas de segurança de Software ISV do Windows](https://msdn.microsoft.com/library/bb430720.aspx)
