---
title: Intervalo de valores inteiros | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 0e9c6161-8f3f-4bfb-9fcc-a6c8dc97d702
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d940824e6bb1dc728cb999c1e820cb7adcedf8ce
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46092642"
---
# <a name="range-of-integer-values"></a>Intervalo de valores inteiros

**ANSI 3.1.2.5** As representações e os conjuntos de valores de vários tipos de inteiros

Inteiros contêm 32 bits (quatro bytes). Os inteiros com sinal são representados no formato de dois complementos. O bit mais significativo contém o sinal: 1 para o negativo, 0 para o sinal positivo e zero. Os valores são listados abaixo:

|Tipo|Mínimo e máximo|
|----------|-------------------------|
|**unsigned short**|0 a 65535|
|`signed short`|-32768 a 32767|
|`unsigned long`|0 a 4294967295|
|**signed long**|-2147483648 a 2147483647|

## <a name="see-also"></a>Consulte também

[Inteiros](../c-language/integers.md)