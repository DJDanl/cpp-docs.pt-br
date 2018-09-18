---
title: Erro do compilador C2218 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2218
dev_langs:
- C++
helpviewer_keywords:
- C2218
ms.assetid: b0f55da4-8edb-4b45-b298-1a091981bd7b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 52c449381c6e8a7391706ed6097bc38576bc69fe
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46041279"
---
# <a name="compiler-error-c2218"></a>Erro do Compilador C2218

vectorcall' não pode ser usado com ' / arch:IA32 '

A convenção de chamada `__vectorcall` é suportada somente em código nativo nos processadores de x86 e x64 que incluem Streaming SIMD Extensions 2 (SSE2) e superiores. Para obter mais informações, consulte [vectorcall](../../cpp/vectorcall.md).

Para corrigir esse erro, altere as opções do compilador para conjuntos de instruções SSE2, AVX ou AVX2 de destino. Para obter mais informações, consulte [/arch (x86)](../../build/reference/arch-x86.md).