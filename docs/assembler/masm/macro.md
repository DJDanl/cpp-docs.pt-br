---
title: MACRO
ms.date: 12/16/2019
f1_keywords:
- MACRO
helpviewer_keywords:
- MACRO directive
ms.assetid: 89434f7c-bc2c-4e91-8940-fe2db8785233
ms.openlocfilehash: 8eb0afdf73270c3e741f43b2e1fba02fe965846c
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80076143"
---
# <a name="macro"></a>MACRO

Marca um bloco de macro chamado *Name* e estabelece espaços reservados de *parâmetro* para argumentos passados quando a macro é chamada.

## <a name="syntax"></a>Sintaxe

> *nome***macro** ⟦*parâmetro* ⟦ **: req** | : =*default* | *args* **: vararg**⟧... ⟧\
> *instruções*\
⟦**Goto** :*macrolabelId*⟧ \
> ⟦**Sair**do ⟧ \
> **ENDM** ⟦*Value*⟧

## <a name="remarks"></a>Comentários

Uma função macro retorna um *valor* para a instrução de chamada.

## <a name="see-also"></a>Confira também

[Referência de diretivas](directives-reference.md)\
[Goto (MASM)](goto-masm.md)\
\ [ENDM](endm.md)
[MASM BNF Grammar](masm-bnf-grammar.md)
