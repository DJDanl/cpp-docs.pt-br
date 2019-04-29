---
title: Erro do compilador C2585
ms.date: 11/04/2016
f1_keywords:
- C2585
helpviewer_keywords:
- C2585
ms.assetid: 05bb1a9c-28fb-4a88-a1b5-aea85ebdee1c
ms.openlocfilehash: 812ab15aacd1f6a215c6a5beb7781983859fe858
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62360496"
---
# <a name="compiler-error-c2585"></a>Erro do compilador C2585

conversão explícita para 'type' é ambíguo

A conversão de tipo pode produzir mais de um resultado.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Convertendo de um tipo de classe ou estrutura com base na herança múltipla. Se o tipo herda a mesma classe base mais de uma vez, a função de conversão ou um operador deve usar resolução de escopo (`::`) para especificar quais as classes herdadas para usar na conversão.

1. Um operador de conversão e um construtor foram definidos a mesma conversão.