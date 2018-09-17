---
title: Alinhamento de malloc | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: a8d1d1b4-5122-456f-9a64-a50e105e55a5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: aa6e2748691eeb8a11834bcf8e6962252be7ab3f
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45712056"
---
# <a name="malloc-alignment"></a>Alinhamento de malloc

[malloc](../c-runtime-library/reference/malloc.md) é garantido que retornam uma memória que esteja alinhada corretamente para armazenar qualquer objeto que tenha um alinhamento fundamental e que poderia se ajustar à quantidade de memória é alocada. Um *alinhamento fundamental* é um alinhamento que é menor que ou igual ao alinhamento maior é suportado pela implementação sem uma especificação de alinhamento. (No Visual C++, isso é o alinhamento que é necessário para um `double`, ou 8 bytes. No código que direciona plataformas de 64 bits, ele tem 16 bytes.) Por exemplo, uma alocação de quatro bytes seria alinhada em um limite que dá suporte a qualquer objeto de quatro bytes ou menor.

Visual C++ permite tipos que têm *alinhamento estendido*, que também são conhecidos como *sobrealinhados* tipos. Por exemplo, os tipos SSE [__m128](../cpp/m128.md) e `__m256`e os tipos que são declarados usando `__declspec(align( n ))` onde `n` é maior que 8, têm alinhamento estendido. Alinhamento de memória em um limite que é adequado para um objeto que exija o alinhamento estendido não é garantido por `malloc`. Para alocar memória para tipos sobre-alinhados, use [aligned_malloc](../c-runtime-library/reference/aligned-malloc.md) e funções relacionadas.

## <a name="see-also"></a>Consulte também

[Uso da pilha](../build/stack-usage.md)<br/>
[align](../cpp/align-cpp.md)<br/>
[__declspec](../cpp/declspec.md)