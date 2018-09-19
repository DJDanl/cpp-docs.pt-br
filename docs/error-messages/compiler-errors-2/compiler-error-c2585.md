---
title: Erro do compilador C2585 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2585
dev_langs:
- C++
helpviewer_keywords:
- C2585
ms.assetid: 05bb1a9c-28fb-4a88-a1b5-aea85ebdee1c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7ec7b1e9c1e5e7894740cc80f9c030fa1ee26ec0
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46028838"
---
# <a name="compiler-error-c2585"></a>Erro do compilador C2585

conversão explícita para 'type' é ambíguo

A conversão de tipo pode produzir mais de um resultado.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Convertendo de um tipo de classe ou estrutura com base na herança múltipla. Se o tipo herda a mesma classe base mais de uma vez, a função de conversão ou um operador deve usar resolução de escopo (`::`) para especificar quais as classes herdadas para usar na conversão.

1. Um operador de conversão e um construtor foram definidos a mesma conversão.