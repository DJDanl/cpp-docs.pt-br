---
title: Erro fatal C1054 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1054
dev_langs:
- C++
helpviewer_keywords:
- C1054
ms.assetid: 9cfb7307-b22a-4418-b7c0-2621b0ab5b1b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 439019b1f510127ae54e77d445d59e86be09a49b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46101963"
---
# <a name="fatal-error-c1054"></a>Erro fatal C1054

limite do compilador: inicializadores com aninhamento muito profundo

O código excede o limite de aninhamento inicializadores (10 a 15 níveis, dependendo da combinação de tipos que está sendo inicializado).

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Simplifique os tipos de dados que está sendo inicializados para reduzir o aninhamento.

1. Inicialize variáveis em instruções separadas depois da declaração.