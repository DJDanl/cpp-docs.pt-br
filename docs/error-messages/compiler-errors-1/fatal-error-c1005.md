---
title: Erro fatal C1005
ms.date: 11/04/2016
f1_keywords:
- C1005
helpviewer_keywords:
- C1005
ms.assetid: 150daf8e-a38a-4669-9c1a-a05b5a1f65ef
ms.openlocfilehash: a84791367656729b1cbd50ca180368f6c01531a4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50614455"
---
# <a name="fatal-error-c1005"></a>Erro fatal C1005

muito grande para o buffer de cadeia de caracteres

Uma cadeia de caracteres em um arquivo intermediário do compilador estourou um buffer.

Você pode obter esse erro quando o parâmetro que você passa como o [/Fd](../../build/reference/fd-program-database-file-name.md) ou [/Yl](../../build/reference/yl-inject-pch-reference-for-debug-library.md) opções do compilador é maior que 256 bytes.