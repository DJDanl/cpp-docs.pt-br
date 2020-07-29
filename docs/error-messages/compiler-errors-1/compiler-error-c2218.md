---
title: Erro do Compilador C2218
ms.date: 11/04/2016
f1_keywords:
- C2218
helpviewer_keywords:
- C2218
ms.assetid: b0f55da4-8edb-4b45-b298-1a091981bd7b
ms.openlocfilehash: 97f3290ef8bcb6a91442effdbf84261c03545ce2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87209520"
---
# <a name="compiler-error-c2218"></a>Erro do Compilador C2218

> ' __vectorcall ' não pode ser usado com '/Arch: IA32 '

A **`__vectorcall`** Convenção de chamada só tem suporte em código nativo em processadores x86 e x64 que incluem Streaming SIMD Extensions 2 (SSE2) e superior. Para obter mais informações, consulte [`__vectorcall`](../../cpp/vectorcall.md).

Para corrigir esse erro, altere as opções do compilador para os conjuntos de instruções SSE2, AVX ou AVX2 de destino. Para obter mais informações, consulte [ `/arch` (x86)](../../build/reference/arch-x86.md).
