---
title: Erro do compilador C2410 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2410
dev_langs:
- C++
helpviewer_keywords:
- C2410
ms.assetid: b69b2de1-56f3-4ebc-8913-04ac57ffe8a1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ba4c2b57bcae062ccf811e33cf1deaea45f83737
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46052446"
---
# <a name="compiler-error-c2410"></a>Erro do compilador C2410

'identifier': nome de membro ambíguo em 'context'

O identificador é um membro de mais de uma estrutura ou união neste contexto.

Use um especificador de estrutura ou união no operando que causou o erro. Um especificador de estrutura ou união é um identificador do tipo `struct` ou `union` (um `typedef` nome ou uma variável do mesmo tipo que a estrutura ou união que está sendo referenciado). O especificador deve ser o operando esquerdo do operador de seleção de membro (.) primeiro para usar o operando.