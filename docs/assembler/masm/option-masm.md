---
title: OPTION (MASM)
ms.date: 12/17/2019
f1_keywords:
- option
helpviewer_keywords:
- OPTION directive
ms.assetid: 8e10dabd-e36f-4586-ab01-ada96736b0bd
ms.openlocfilehash: bd50ac2e051db7f02ac077054e5856524745df54
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75318742"
---
# <a name="option"></a>OPTION

Habilita e desabilita os recursos do Assembler.

## <a name="syntax"></a>Sintaxe

> **Opção** optionlist

## <a name="remarks"></a>Comentários

As opções disponíveis incluem:

|||||
|-|-|-|-|
|**CASEMAP**|**DOTNAME**|**NODOTNAME**|**EMULATOR**|
|**NOEMULATOR**|**EPÍLOGO**|**EXPR16**|**EXPR32**|
|**LANGUAGE**|**LJMP**|**NOLJMP**|**M510**|
|**NOM510**|**Nopalavra-chave**|**NOSIGNEXTEND**|**OFFSET**|
|**OLDMACROS**|**NOOLDMACROS**|**OLDSTRUCTS**|**NOOLDSTRUCTS**|
|**PROC**|**PRÓLOGO**|**READONLY**|**NOREADONLY**|
|**SCOPED**|**Sem escopo**|**SEGMENT**|**SETIF2**.|

A sintaxe de LANGUAGE é **language option:** <em>x</em>, em que *x* é uma das opções C, syscall, stdcall, Pascal, Fortran ou Basic.  Não há suporte para SYSCALL, PASCAL, FORTRAN e BASIC com [. MODELO](dot-model.md) simples.

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
