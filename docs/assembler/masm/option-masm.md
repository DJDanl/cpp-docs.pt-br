---
title: OPTION (MASM)
ms.date: 08/30/2018
f1_keywords:
- option
helpviewer_keywords:
- OPTION directive
ms.assetid: 8e10dabd-e36f-4586-ab01-ada96736b0bd
ms.openlocfilehash: a8215bf1f816baa490a768fb2cab0b3c2e53e20b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62217251"
---
# <a name="option-masm"></a>OPTION (MASM)

Habilita e desabilita recursos do montador.

## <a name="syntax"></a>Sintaxe

> OPÇÃO *optionlist*

## <a name="remarks"></a>Comentários

As opções disponíveis incluem:

|||||
|-|-|-|-|
|**CASEMAP**|**DOTNAME**|**NODOTNAME**|**EMULADOR**|
|**NOEMULATOR**|**EPILOGUE**|**EXPR16**|**EXPR32**|
|**IDIOMA**|**LJMP**|**NOLJMP**|**M510**|
|**NOM510**|**NOKEYWORD**|**NOSIGNEXTEND**|**OFFSET**|
|**OLDMACROS**|**NOOLDMACROS**|**OLDSTRUCTS**|**NOOLDSTRUCTS**|
|**PROC**|**PROLOGUE**|**READONLY**|**NOREADONLY**|
|**SCOPED**|**NOSCOPED**|**SEGMENT**|**SETIF2**.|

A sintaxe de LINGUAGEM é **opção de LINGUAGEM:**<em>x</em>, onde *x* é um dos C, SYSCALL, STDCALL, PASCAL, FORTRAN ou BASIC.  SYSCALL, PASCAL, FORTRAN e BASIC não têm suporte com usado com [. MODELO](../../assembler/masm/dot-model.md) simples.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>