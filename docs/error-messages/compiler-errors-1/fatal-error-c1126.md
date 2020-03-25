---
title: Erro fatal C1126
ms.date: 11/04/2016
f1_keywords:
- C1126
helpviewer_keywords:
- C1126
ms.assetid: f22b26a6-8ad7-47cf-a237-196c8ea60aca
ms.openlocfilehash: a6c9d06cd087eb4462ae475cc1f6d64ba451887f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80203613"
---
# <a name="fatal-error-c1126"></a>Erro fatal C1126

' identifier ': a alocação automática excede o tamanho

Espaço alocado para variáveis locais de uma função (mais uma quantidade limitada de espaço usado pelo compilador, como um extra de 20 bytes para funções intercambiáveis) excede o limite.

Para corrigir esse erro, use `malloc` ou `new` para alocar grandes quantidades de dados.
