---
title: Erro do compilador C2439
ms.date: 11/04/2016
f1_keywords:
- C2439
helpviewer_keywords:
- C2439
ms.assetid: 3c5dbe5c-b7d3-4bb0-8619-92f6e280461e
ms.openlocfilehash: 99f3644869f6c5395684643f0e7802f3a01baa62
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80205355"
---
# <a name="compiler-error-c2439"></a>Erro do compilador C2439

' identifier ': não foi possível inicializar o membro

Um membro de classe, estrutura ou União não pode ser inicializado.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Tentando inicializar uma classe base indireta ou estrutura.

1. Tentando inicializar um membro herdado de uma classe ou estrutura. Um membro herdado deve ser inicializado pelo construtor da classe ou estrutura.
