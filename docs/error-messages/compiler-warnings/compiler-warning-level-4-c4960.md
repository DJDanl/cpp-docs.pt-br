---
title: Aviso do compilador (nível 4) C4960
ms.date: 11/04/2016
f1_keywords:
- C4960
helpviewer_keywords:
- C4960
ms.assetid: 3b4ed286-9e8d-46f1-af0c-00ba669693a9
ms.openlocfilehash: 286d3a1953c6c6badf15b712feac99afafe8b0a7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80198114"
---
# <a name="compiler-warning-level-4-c4960"></a>Aviso do compilador (nível 4) C4960

' function ' é muito grande para ser criado

Ao usar [/LTCG: PGOPTIMIZE](../../build/reference/ltcg-link-time-code-generation.md), o compilador detectou um módulo de entrada com uma função maior que 65.535 instruções. Uma função tão grande não está disponível para otimizações guiadas por perfil.

Para resolver esse aviso, reduza o tamanho da função.
