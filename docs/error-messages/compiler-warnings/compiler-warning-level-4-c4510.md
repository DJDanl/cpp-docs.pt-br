---
title: Aviso do compilador (nível 4) C4510
description: Descrição e solução de aviso do compilador C4510.
ms.date: 09/22/2019
f1_keywords:
- C4510
helpviewer_keywords:
- C4510
ms.assetid: fd28d1d4-ad27-4dad-94c0-9dba46c93180
ms.openlocfilehash: 05a6d0fe42d8247d3328506d8772b2fa77b5703c
ms.sourcegitcommit: 389c559918d9bfaf303d262ee5430d787a662e92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/24/2019
ms.locfileid: "71230381"
---
# <a name="compiler-warning-level-4-c4510"></a>Aviso do compilador (nível 4) C4510

> '*Class*': não foi possível gerar o construtor padrão

O compilador não pode gerar um construtor padrão para a classe especificada, que não tem construtores definidos pelo usuário. Não é possível criar objetos desse tipo.

Há várias situações que impedem que o compilador gere um construtor padrão, incluindo:

- Um membro de dados **const** .

- Um membro de dados que é uma referência.

Para corrigir esse problema, crie um construtor padrão definido pelo usuário para a classe que inicializa esses membros.
