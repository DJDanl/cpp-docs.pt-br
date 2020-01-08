---
title: IF1 e IF2
ms.date: 11/21/2019
f1_keywords:
- IF2
- IF1
helpviewer_keywords:
- IF2 directive
- IF2 directive
ms.assetid: a0f75564-b51b-4e39-ad3b-f7421e7ecad6
ms.openlocfilehash: 60f8b0dcedb61ac06de929aff300845e342d7cfc
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75317312"
---
# <a name="if1-and-if2"></a>IF1 e IF2

O bloco **IF1** é avaliado no primeiro passo do assembly.

O bloco **IF2** será avaliado em cada passagem de assembly se a **opção: SETIF2** for **true**.

## <a name="syntax"></a>Sintaxe

> **IF1;;**

> **IF2;;**

## <a name="remarks"></a>Comentários

Confira [se](if-masm.md) para obter a sintaxe completa.

Diferentemente da versão 5,1, MASM 6,1 e acima fazem a maior parte de seu trabalho em sua primeira passagem e, em seguida, executa quantas etapas subsequentes forem necessárias. Por outro lado, o MASM 5,1 sempre se reúne em duas passagens de origem. Como resultado, talvez seja necessário revisar ou excluir algumas construções dependentes de Pass em MASM 6,1 e superior.

### <a name="two-pass-directives"></a>Diretivas de duas passagens

Para garantir a compatibilidade, MASM 6,1 e superior dão suporte a diretivas 5,1 que se referem a duas passagens. Isso inclui **. ERR1**, **. ERR2**, **IF1**, **IF2**, **ELSEIF1**e **ELSEIF2**. Para construções de segundo passo, você deve especificar a [opção SETIF2](option-masm.md). Sem a **opção SETIF2**, o **IF2** e o **.** As diretivas Err2 causam um erro:

```output
.ERR2 not allowed : single-pass assembler
```

MASM 6,1 e acima lidam com as construções de primeira passagem de forma diferente. Ele trata o **. Diretiva ERR1** como **. ERR**e a diretiva **IF1** como **If**.

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
