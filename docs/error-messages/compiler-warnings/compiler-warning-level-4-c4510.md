---
title: Aviso do compilador (nível 4) C4510
description: Descrição e solução de aviso do compilador C4510.
ms.date: 09/22/2019
f1_keywords:
- C4510
helpviewer_keywords:
- C4510
ms.assetid: fd28d1d4-ad27-4dad-94c0-9dba46c93180
ms.openlocfilehash: e4bb688266d9fe638978d2d3fa2666b83b3e6cc9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225248"
---
# <a name="compiler-warning-level-4-c4510"></a>Aviso do compilador (nível 4) C4510

> '*Class*': não foi possível gerar o construtor padrão

O compilador não pode gerar um construtor padrão para a classe especificada, que não tem construtores definidos pelo usuário. Não é possível criar objetos desse tipo.

Há várias situações que impedem que o compilador gere um construtor padrão, incluindo:

- Um **`const`** membro de dados.

- Um membro de dados que é uma referência.

Para corrigir esse problema, crie um construtor padrão definido pelo usuário para a classe que inicializa esses membros.
