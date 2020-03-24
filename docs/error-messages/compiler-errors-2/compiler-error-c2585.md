---
title: Erro do compilador C2585
ms.date: 11/04/2016
f1_keywords:
- C2585
helpviewer_keywords:
- C2585
ms.assetid: 05bb1a9c-28fb-4a88-a1b5-aea85ebdee1c
ms.openlocfilehash: 57a0cd7a200c5bbb875821eb9e10314d98e58185
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80177385"
---
# <a name="compiler-error-c2585"></a>Erro do compilador C2585

a conversão explícita para ' type ' é ambígua

A conversão de tipo pode produzir mais de um resultado.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Conversão de um tipo de classe ou estrutura com base em várias heranças. Se o tipo herdar a mesma classe base mais de uma vez, a função de conversão ou o operador deverá usar a resolução de escopo (`::`) para especificar quais das classes herdadas usar na conversão.

1. Um operador de conversão e um Construtor foram definidos fazendo a mesma conversão.
