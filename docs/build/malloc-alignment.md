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
ms.openlocfilehash: d503d0dd891c651a405cb79bb5ce50996f46cff6
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32368659"
---
# <a name="malloc-alignment"></a>Alinhamento de malloc
[malloc](../c-runtime-library/reference/malloc.md) é garantido para retornar a memória que está alinhada adequadamente para armazenar qualquer objeto que tenha um alinhamento fundamental e que caibam na quantidade de memória alocada. Um *alinhamento fundamental* é um alinhamento que seja menor ou igual ao maior alinhamento que é compatível com a implementação sem uma especificação de alinhamento. (No Visual C++, este é o alinhamento que é necessário para um `double`, ou 8 bytes. No código que direciona plataformas de 64 bits, ele tem 16 bytes.) Por exemplo, uma alocação de quatro bytes deve ser alinhada em um limite que dá suporte a qualquer objeto de quatro bytes ou menor.  
  
 Visual C++ permite tipos que têm *estendidos alinhamento*, que também são conhecidas como *excesso alinhado* tipos. Por exemplo, os tipos de SSE [m128](../cpp/m128.md) e `__m256`e tipos que são declarados usando `__declspec(align( n ))` onde `n` é maior que 8, tiver estendido o alinhamento. Alinhamento de memória em um limite que é adequado para um objeto que requer alinhamento estendido não é garantido por `malloc`. Para alocar memória para tipos de excesso alinhados, use [aligned_malloc](../c-runtime-library/reference/aligned-malloc.md) e funções relacionadas.  
  
## <a name="see-also"></a>Consulte também  
 [Uso da pilha](../build/stack-usage.md)   
 [Alinhar](../cpp/align-cpp.md)   
 [__declspec](../cpp/declspec.md)