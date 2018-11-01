---
title: Erro do compilador C2410
ms.date: 11/04/2016
f1_keywords:
- C2410
helpviewer_keywords:
- C2410
ms.assetid: b69b2de1-56f3-4ebc-8913-04ac57ffe8a1
ms.openlocfilehash: 8b01a2f7b9c55fb57c880df5033538f4e45f76b4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50643684"
---
# <a name="compiler-error-c2410"></a>Erro do compilador C2410

'identifier': nome de membro ambíguo em 'context'

O identificador é um membro de mais de uma estrutura ou união neste contexto.

Use um especificador de estrutura ou união no operando que causou o erro. Um especificador de estrutura ou união é um identificador do tipo `struct` ou `union` (um `typedef` nome ou uma variável do mesmo tipo que a estrutura ou união que está sendo referenciado). O especificador deve ser o operando esquerdo do operador de seleção de membro (.) primeiro para usar o operando.