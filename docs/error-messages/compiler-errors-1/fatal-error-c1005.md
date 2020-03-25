---
title: Erro fatal C1005
ms.date: 11/04/2016
f1_keywords:
- C1005
helpviewer_keywords:
- C1005
ms.assetid: 150daf8e-a38a-4669-9c1a-a05b5a1f65ef
ms.openlocfilehash: a8b0fe71dcfb6253327de247d24ef9d90c59181d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80204861"
---
# <a name="fatal-error-c1005"></a>Erro fatal C1005

Cadeia de caracteres muito grande para o buffer

Uma cadeia de caracteres em um arquivo intermediário do compilador estourou um buffer.

Você pode obter esse erro quando o parâmetro que você passa para as opções do compilador [/FD](../../build/reference/fd-program-database-file-name.md) ou [/YL](../../build/reference/yl-inject-pch-reference-for-debug-library.md) é maior que 256 bytes.
