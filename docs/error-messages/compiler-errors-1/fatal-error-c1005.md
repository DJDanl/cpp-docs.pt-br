---
title: Erro fatal C1005 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1005
dev_langs:
- C++
helpviewer_keywords:
- C1005
ms.assetid: 150daf8e-a38a-4669-9c1a-a05b5a1f65ef
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 888bdaf2eaddc0d4178affa1ccc4ae77c34f4617
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46092304"
---
# <a name="fatal-error-c1005"></a>Erro fatal C1005

muito grande para o buffer de cadeia de caracteres

Uma cadeia de caracteres em um arquivo intermediário do compilador estourou um buffer.

Você pode obter esse erro quando o parâmetro que você passa como o [/Fd](../../build/reference/fd-program-database-file-name.md) ou [/Yl](../../build/reference/yl-inject-pch-reference-for-debug-library.md) opções do compilador é maior que 256 bytes.