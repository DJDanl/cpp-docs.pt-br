---
title: Erro fatal C1305
ms.date: 11/04/2016
f1_keywords:
- C1305
helpviewer_keywords:
- C1305
ms.assetid: 1629c850-e2db-4678-83d8-9bfc85323bc5
ms.openlocfilehash: 6ad00eb3d95e9f09d4f84daefb7e2a87fd1a3abf
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80203353"
---
# <a name="fatal-error-c1305"></a>Erro fatal C1305

o banco de dados de perfil ' pgd_file ' é para uma arquitetura diferente

Um arquivo. pgd que foi gerado da operação/LTCG: PGINSTRUMENT para outra plataforma foi passado para [/LTCG: PGOPTIMIZE](../../build/reference/ltcg-link-time-code-generation.md) . As [otimizações guiadas por perfil](../../build/profile-guided-optimizations.md) estão disponíveis para plataformas x86 e x64. No entanto, um arquivo. pgd gerado com uma operação/LTCG: PGINSTRUMENT para uma plataforma não é válido como entrada para um/LTCG: PGOPTIMIZE para uma plataforma diferente.

Para resolver esse erro, passe apenas um arquivo. pgd criado com/LTCG: PGINSTRUMENT para/LTCG: PGOPTIMIZE na mesma plataforma.
