---
title: Erro do Compilador C2218
ms.date: 11/04/2016
f1_keywords:
- C2218
helpviewer_keywords:
- C2218
ms.assetid: b0f55da4-8edb-4b45-b298-1a091981bd7b
ms.openlocfilehash: db14c37992fc1e2dd409c653d622d3419fcae4f3
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80206642"
---
# <a name="compiler-error-c2218"></a>Erro do Compilador C2218

' __vectorcall ' não pode ser usado com '/Arch: IA32 '

A convenção de chamada `__vectorcall` é suportada somente em código nativo nos processadores de x86 e x64 que incluem Streaming SIMD Extensions 2 (SSE2) e superiores. Para obter mais informações, consulte [__vectorcall](../../cpp/vectorcall.md).

Para corrigir esse erro, altere as opções do compilador para os conjuntos de instruções SSE2, AVX ou AVX2 de destino. Para obter mais informações, consulte [/arch (x86)](../../build/reference/arch-x86.md).
