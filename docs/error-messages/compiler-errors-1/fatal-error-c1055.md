---
title: Erro fatal C1055
ms.date: 11/04/2016
f1_keywords:
- C1055
helpviewer_keywords:
- C1055
ms.assetid: a9fb9190-d7eb-4d5f-b1a2-a41e584a28c1
ms.openlocfilehash: c349c09b4931c0a303e7619b364ab237394bd4fc
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80204445"
---
# <a name="fatal-error-c1055"></a>Erro fatal C1055

limite do compilador: sem chaves

O arquivo de origem contém muitos símbolos. O compilador ficou sem chaves de hash para a tabela de símbolos.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Divida o arquivo de origem em arquivos menores.

1. Elimine arquivos de cabeçalho desnecessários.

1. Reutilize variáveis temporárias e globais em vez de criar novas.
