---
title: OPTION (MASM)
ms.date: 07/15/2020
f1_keywords:
- option
helpviewer_keywords:
- OPTION directive
ms.assetid: 8e10dabd-e36f-4586-ab01-ada96736b0bd
ms.openlocfilehash: 3d5bef52106b38487d1a2be248cff274f39e009c
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88830833"
---
# <a name="option"></a>OPTION

Habilita e desabilita os recursos do Assembler.

## <a name="syntax"></a>Sintaxe

> **`OPTION`***opção-lista*

## <a name="remarks"></a>Comentários

As opções disponíveis incluem:

:::row:::
   :::column span="":::
      **`CASEMAP`**\
      **`DOTNAME`**\
      **`NODOTNAME`**\
      **`EMULATOR`**\
      **`NOEMULATOR`**\
      **`EPILOGUE`**\
      **`EXPR16`**
   :::column-end:::
   :::column span="":::
      **`EXPR32`**\
      **`LANGUAGE`**\
      **`LJMP`**\
      **`NOLJMP`**\
      **`M510`**\
      **`NOM510`**\
      **`NOKEYWORD`**
   :::column-end:::
   :::column span="":::
      **`NOSIGNEXTEND`**\
      **`OFFSET`**\
      **`OLDMACROS`**\
      **`NOOLDMACROS`**\
      **`OLDSTRUCTS`**\
      **`NOOLDSTRUCTS`**\
      **`PROC`**
   :::column-end:::
   :::column span="":::
      **`PROLOGUE`**\
      **`READONLY`**\
      **`NOREADONLY`**\
      **`SCOPED`**\
      **`NOSCOPED`**\
      **`SEGMENT`**\
      **`SETIF2`**
   :::column-end:::
:::row-end:::

A sintaxe de Language é **`OPTION LANGUAGE:`** _`x`_ , em que *`x`* é um dos **`C`** , **`SYSCALL`** ,,, **`STDCALL`** **`PASCAL`** **`FORTRAN`** ou **`BASIC`** . **`SYSCALL`**, **`PASCAL`** , **`FORTRAN`** e **`BASIC`** não têm suporte com [`.MODEL`](dot-model.md) **`FLAT`** .

## <a name="see-also"></a>Confira também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
