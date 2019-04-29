---
title: Erro fatal C1126
ms.date: 11/04/2016
f1_keywords:
- C1126
helpviewer_keywords:
- C1126
ms.assetid: f22b26a6-8ad7-47cf-a237-196c8ea60aca
ms.openlocfilehash: 3f4d152163d3b21ddf99644c34e63f35ca15e6e9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62230006"
---
# <a name="fatal-error-c1126"></a>Erro fatal C1126

'identifier': a alocação automática excede o tamanho

Espaço alocado para variáveis locais de uma função (mais uma quantidade limitada de espaço usado pelo compilador, como um extra de 20 bytes para funções swappable) excede o limite.

Para corrigir esse erro, use `malloc` ou `new` alocar grandes quantidades de dados.