---
title: ALIAS (MASM)
ms.date: 08/30/2018
f1_keywords:
- Alias
helpviewer_keywords:
- ALIAS directive
ms.assetid: d9725c49-58de-41da-ab01-b06a56cf5cf2
ms.openlocfilehash: 274ac451005015b2693d8674673af574ec781bdc
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74399287"
---
# <a name="alias-masm"></a>ALIAS (MASM)

A diretiva **alias** cria um nome alternativo para uma função.  Isso permite que você crie vários nomes para uma função ou crie bibliotecas que permitem que o vinculador (LINK. exe) mapeie uma função antiga para uma nova função.

## <a name="syntax"></a>Sintaxe

> Alias **\<** _alias_ **> = \<** _nome real_ **>**

#### <a name="parameters"></a>Parâmetros

\ *de nome real*
O nome real da função ou procedimento.  Os colchetes angulares são obrigatórios.

\ de *alias*
O nome alternativo ou alias.  Os colchetes angulares são obrigatórios.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)
