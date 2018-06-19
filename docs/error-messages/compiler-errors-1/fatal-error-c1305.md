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
ms.openlocfilehash: 3cb1cf19d0fc4152fbb458d684972bb5a4418f37
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33227128"
---
# <a name="fatal-error-c1305"></a>Erro fatal C1305
banco de dados de perfil 'pgd_file' é para uma arquitetura diferente  
  
 Um arquivo. PGD que foi gerado da operação /LTCG:PGINSTRUMENT para outra plataforma foi passada para [/LTCG:PGOPTIMIZE](../../build/reference/ltcg-link-time-code-generation.md) . [Otimizações guiadas por perfil](../../build/reference/profile-guided-optimizations.md) estão disponíveis para x86 e [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] plataformas. No entanto, um arquivo. PGD gerado com uma operação de /LTCG:PGINSTRUMENT para uma plataforma não é válido como entrada para uma /LTCG:PGOPTIMIZE para uma plataforma diferente.  
  
 Para resolver esse erro, passe apenas um arquivo. PGD que é criado com /LTCG:PGINSTRUMENT para /LTCG:PGOPTIMIZE na mesma plataforma.