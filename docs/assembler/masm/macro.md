---
title: MACRO
ms.date: 12/16/2019
f1_keywords:
- MACRO
helpviewer_keywords:
- MACRO directive
ms.assetid: 89434f7c-bc2c-4e91-8940-fe2db8785233
ms.openlocfilehash: 23c6b0aefae856da449da574669e8475122c7556
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75312944"
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

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[Goto (MASM)](goto-masm.md)\
\ [ENDM](endm.md)
[MASM BNF Grammar](masm-bnf-grammar.md)

