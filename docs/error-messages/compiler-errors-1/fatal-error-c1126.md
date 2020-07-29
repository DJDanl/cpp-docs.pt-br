---
title: Erro fatal C1126
ms.date: 11/04/2016
f1_keywords:
- C1126
helpviewer_keywords:
- C1126
ms.assetid: f22b26a6-8ad7-47cf-a237-196c8ea60aca
ms.openlocfilehash: 110fbfe984ee7714e0c8ee2e2cb4deec4f43905a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87207921"
---
# <a name="fatal-error-c1126"></a>Erro fatal C1126

' identifier ': a alocação automática excede o tamanho

Espaço alocado para variáveis locais de uma função (mais uma quantidade limitada de espaço usado pelo compilador, como um extra de 20 bytes para funções intercambiáveis) excede o limite.

Para corrigir esse erro, use `malloc` ou **`new`** para alocar grandes quantidades de dados.
