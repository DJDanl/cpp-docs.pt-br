---
title: NMAKE Erro Fatal U1073 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U1073
dev_langs:
- C++
helpviewer_keywords:
- U1073
ms.assetid: d46bf2dd-400a-4802-9db2-f832e1c97f02
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4c309ed94cd1c984406e0d21f0139e35c6e41d7d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46053928"
---
# <a name="nmake-fatal-error-u1073"></a>Erro fatal U1073 (NMAKE)

não sabe como tornar 'targetname'

O destino especificado não existe e não há nenhum comando para executar ou a regra de inferência para aplicar.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Verifique a ortografia do nome do destino.

1. Se *targetname* é um pseudotarget, especifique-o como um destino em outro bloco de descrição.

1. Se *targetname* é uma invocação de macro, certifique-se de que não expande para uma cadeia de caracteres nula.