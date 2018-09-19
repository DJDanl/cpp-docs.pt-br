---
title: Erro fatal C1061 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1061
dev_langs:
- C++
helpviewer_keywords:
- C1061
ms.assetid: 9366c0bc-96e0-4967-aa7d-4ebf098de806
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 21ca27534aa23d0d81ec7fb191c336b35b18391a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46083269"
---
# <a name="fatal-error-c1061"></a>Erro fatal C1061

limite do compilador: blocos aninhados muito profundamente

O aninhamento de blocos de código excede o limite de 128 níveis de aninhamento. Esse é um limite fixo do compilador para C e C++, no conjunto de ferramentas de 32 bits e de 64 bits. A contagem de níveis de aninhamento pode ser aumentada em qualquer proporção que crie um escopo ou um bloco. Por exemplo, namespaces, usar diretivas, expansões de pré-processador, expansão do modelo, tratamento de exceções, construções de loop e cláusulas else-if podem qualquer aumentar o nível de aninhamento visto pelo compilador.

Para corrigir esse erro, é necessário refatorar seu código. Em qualquer caso, o código aninhado é difícil de compreender e justificar. Refatorar seu código para ter menos níveis de aninhamento pode melhorar a qualidade do código e simplificar a manutenção. Divida o código aninhado profundamente em funções que são chamadas pelo contexto original. Limite o número de loops ou cláusulas else-if encadeadas dentro de um bloco.