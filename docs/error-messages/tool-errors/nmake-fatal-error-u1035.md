---
title: Erro fatal U1035 (NMAKE)
ms.date: 11/04/2016
f1_keywords:
- U1035
helpviewer_keywords:
- U1035
ms.assetid: 68f0cc59-007e-4109-ac30-7ac4ac447e6d
ms.openlocfilehash: 3eda424574dfa48901cf4dc6aea3b28beb739dc0
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80193713"
---
# <a name="nmake-fatal-error-u1035"></a>Erro fatal U1035 (NMAKE)

erro de sintaxe: ': ' ou separador ' = ' esperado

Um ou dois pontos ( **:** ) ou um sinal de igual ( **=** ) era esperado.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Dois pontos não seguiram um destino.

1. Dois-pontos e nenhum espaço (como:) um destino de letra única seguido. NMAKE o interpretava como uma especificação de unidade.

1. Dois pontos não seguiram uma regra de inferência.

1. Uma definição de macro não foi seguida por um sinal de igual.

1. Um caractere seguido de uma barra invertida ( **\\** ) que foi usada para continuar um comando para uma nova linha.

1. Uma cadeia de caracteres apareceu que não segue nenhuma regra de sintaxe NMAKE.

1. O makefile foi formatado por um processador de texto.
