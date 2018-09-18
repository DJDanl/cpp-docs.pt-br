---
title: Erro fatal C1305 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1305
dev_langs:
- C++
helpviewer_keywords:
- C1305
ms.assetid: 1629c850-e2db-4678-83d8-9bfc85323bc5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4beb1140d161b8cbe54cab40dcc72899c976edc3
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46048741"
---
# <a name="fatal-error-c1305"></a>Erro fatal C1305

banco de dados de perfil 'pgd_file' é para uma arquitetura diferente

Um arquivo. PGD que foi gerado da operação /LTCG:PGINSTRUMENT para outra plataforma foi passada para [/LTCG:PGOPTIMIZE](../../build/reference/ltcg-link-time-code-generation.md) . [Otimizações guiadas por perfil](../../build/reference/profile-guided-optimizations.md) estão disponíveis para plataformas x86 e x64. No entanto, um arquivo. PGD gerado com uma operação de /LTCG:PGINSTRUMENT para uma plataforma não é válido como entrada para um /LTCG:PGOPTIMIZE para uma plataforma diferente.

Para resolver esse erro, passe apenas um arquivo. PGD que será criado com /LTCG:PGINSTRUMENT para /LTCG:PGOPTIMIZE na mesma plataforma.