---
title: Erro fatal U1073 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U1073
helpviewer_keywords:
- U1073
ms.assetid: d46bf2dd-400a-4802-9db2-f832e1c97f02
ms.openlocfilehash: 97d44594540d18bf008757506a9e36e6d16d2cd7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80182689"
---
# <a name="nmake-fatal-error-u1073"></a>Erro fatal U1073 (NMAKE)

Não sabe como criar ' targetname '

O destino especificado não existe e não há nenhum comando a ser executado ou a regra de inferência a ser aplicada.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Verifique a ortografia do nome de destino.

1. Se *TargetName* for um pseudotarget, especifique-o como um destino em outro bloco de descrição.

1. Se *TargetName* for uma chamada de macro, certifique-se de que ele não expanda para uma cadeia de caracteres nula.
