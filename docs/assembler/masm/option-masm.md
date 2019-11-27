---
title: OPTION (MASM)
ms.date: 08/30/2018
f1_keywords:
- option
helpviewer_keywords:
- OPTION directive
ms.assetid: 8e10dabd-e36f-4586-ab01-ada96736b0bd
ms.openlocfilehash: 0f90ab0115c3dde894d468bbbe60ffa0193b8336
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74395174"
---
# <a name="option-masm"></a>OPTION (MASM)

Habilita e desabilita os recursos do Assembler.

## <a name="syntax"></a>Sintaxe

> **Opção** optionlist

## <a name="remarks"></a>Comentários

As opções disponíveis incluem:

|||||
|-|-|-|-|
|**CASEMAP**|**DOTNAME**|**NODOTNAME**|**EMULATOR**|
|**NOEMULATOR**|**EPÍLOGO**|**EXPR16**|**EXPR32**|
|**IDIOMA**|**LJMP**|**NOLJMP**|**M510**|
|**NOM510**|**Nopalavra-chave**|**NOSIGNEXTEND**|**DESVIO**|
|**OLDMACROS**|**NOOLDMACROS**|**OLDSTRUCTS**|**NOOLDSTRUCTS**|
|**PROC**|**PRÓLOGO**|**LEITURA**|**Noreadonly**|
|**COM escopo**|**Sem escopo**|**SEGMENT**|**SETIF2**.|

A sintaxe de LANGUAGE é **language option:** <em>x</em>, em que *x* é uma das opções C, syscall, stdcall, Pascal, Fortran ou Basic.  Não há suporte para SYSCALL, PASCAL, FORTRAN e BASIC com o usado com [. MODELO](../../assembler/masm/dot-model.md) simples.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](directives-reference.md)
