---
title: -HIGHENTROPYVA | Microsoft Docs
ms.custom: ''
ms.date: 06/12/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /HIGHENTROPYVA
dev_langs:
- C++
helpviewer_keywords:
- HIGHENTROPYVA editbin option
- -HIGHENTROPYVA editbin option
- /HIGHENTROPYVA editbin option
ms.assetid: ef4b7c63-440d-40ca-b39d-edefb3217505
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5fec9314be9d69e2cb0af2a98884bd78de1ff679
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43202068"
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
