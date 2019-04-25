---
title: Erro fatal U1035 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U1035
helpviewer_keywords:
- U1035
ms.assetid: 68f0cc59-007e-4109-ac30-7ac4ac447e6d
ms.openlocfilehash: 9c4055bb99243f7d20c1da90aef7b916c46c2749
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62324331"
---
# <a name="nmake-fatal-error-u1035"></a>Erro fatal U1035 (NMAKE)

Erro de sintaxe: esperado ':' ou separador '='

Qualquer um dos dois-pontos (**:**) ou um sinal de igual (**=**) era esperado.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Dois-pontos não seguiu um destino.

1. Dois-pontos e nenhum espaço (por exemplo, o r:) seguido de um única letra destino. NMAKE interpretado-lo como uma especificação de unidade.

1. Dois-pontos não seguiu uma regra de inferência de tipos.

1. Uma definição de macro não foi seguida por um sinal de igual.

1. Um caractere seguido de uma barra invertida (**\\**) que foi usado para continuar um comando para uma nova linha.

1. Uma cadeia de caracteres apareceu que não seguiu a qualquer regra de sintaxe NMAKE.

1. O makefile foi formatado por um processador de texto.