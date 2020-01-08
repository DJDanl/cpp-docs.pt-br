---
title: ALIAS (MASM)
ms.date: 12/17/2019
f1_keywords:
- Alias
helpviewer_keywords:
- ALIAS directive
ms.assetid: d9725c49-58de-41da-ab01-b06a56cf5cf2
ms.openlocfilehash: 5aef169c5632e74722438c63718ce5b783a8da09
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75316597"
---
# <a name="alias"></a>ALIAS

A diretiva **alias** cria um nome alternativo para uma função.  Isso permite que você crie vários nomes para uma função ou crie bibliotecas que permitem que o vinculador (LINK. exe) mapeie uma função antiga para uma nova função.

## <a name="syntax"></a>Sintaxe

> Alias **\<** _alias_ **> = \<** _nome real_ **>**

#### <a name="parameters"></a>Parâmetros

\ *de nome real*
O nome real da função ou procedimento.  Os colchetes angulares são obrigatórios.

\ de *alias*
O nome alternativo ou alias.  Os colchetes angulares são obrigatórios.

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
