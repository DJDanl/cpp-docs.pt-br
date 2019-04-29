---
title: Erro fatal U1073 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U1073
helpviewer_keywords:
- U1073
ms.assetid: d46bf2dd-400a-4802-9db2-f832e1c97f02
ms.openlocfilehash: 2aa02fd86906bd545373a313fa5e6e409ffb3cf9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62366921"
---
# <a name="nmake-fatal-error-u1073"></a>Erro fatal U1073 (NMAKE)

não sabe como tornar 'targetname'

O destino especificado não existe e não há nenhum comando para executar ou a regra de inferência para aplicar.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Verifique a ortografia do nome do destino.

1. Se *targetname* é um pseudotarget, especifique-o como um destino em outro bloco de descrição.

1. Se *targetname* é uma invocação de macro, certifique-se de que não expande para uma cadeia de caracteres nula.