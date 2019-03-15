---
title: Erro fatal C1305
ms.date: 11/04/2016
f1_keywords:
- C1305
helpviewer_keywords:
- C1305
ms.assetid: 1629c850-e2db-4678-83d8-9bfc85323bc5
ms.openlocfilehash: 988842a0d5e8002ffd1478a2e10a8c88ee971911
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57822230"
---
# <a name="fatal-error-c1305"></a>Erro fatal C1305

banco de dados de perfil 'pgd_file' é para uma arquitetura diferente

Um arquivo. PGD que foi gerado da operação /LTCG:PGINSTRUMENT para outra plataforma foi passada para [/LTCG:PGOPTIMIZE](../../build/reference/ltcg-link-time-code-generation.md) . [Otimizações guiadas por perfil](../../build/profile-guided-optimizations.md) estão disponíveis para plataformas x86 e x64. No entanto, um arquivo. PGD gerado com uma operação de /LTCG:PGINSTRUMENT para uma plataforma não é válido como entrada para um /LTCG:PGOPTIMIZE para uma plataforma diferente.

Para resolver esse erro, passe apenas um arquivo. PGD que será criado com /LTCG:PGINSTRUMENT para /LTCG:PGOPTIMIZE na mesma plataforma.