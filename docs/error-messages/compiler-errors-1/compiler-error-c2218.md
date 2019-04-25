---
title: Erro do Compilador C2218
ms.date: 11/04/2016
f1_keywords:
- C2218
helpviewer_keywords:
- C2218
ms.assetid: b0f55da4-8edb-4b45-b298-1a091981bd7b
ms.openlocfilehash: 5a9d897686fc915c9892fa2bcd51fa3ca3c8b05e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62165655"
---
# <a name="compiler-error-c2218"></a>Erro do Compilador C2218

vectorcall' não pode ser usado com ' / arch:IA32 '

A convenção de chamada `__vectorcall` é suportada somente em código nativo nos processadores de x86 e x64 que incluem Streaming SIMD Extensions 2 (SSE2) e superiores. Para obter mais informações, consulte [vectorcall](../../cpp/vectorcall.md).

Para corrigir esse erro, altere as opções do compilador para conjuntos de instruções SSE2, AVX ou AVX2 de destino. Para obter mais informações, consulte [/arch (x86)](../../build/reference/arch-x86.md).