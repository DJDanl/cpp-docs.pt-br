---
title: EXTERN (MASM)
ms.date: 12/06/2019
helpviewer_keywords:
- EXTERN directive
ms.assetid: 667d703d-3aaf-4139-a586-29bc5dab1aff
ms.openlocfilehash: 2674f358fe22f74c5272d90a0d8cbff234ddcd11
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79440876"
---
# <a name="extern"></a>EXTERN

Define uma ou mais variáveis, rótulos ou símbolos externos chamados *Name* cujo tipo é *Type*.

## <a name="syntax"></a>Sintaxe

> **EXTERN** ⟦*De idiomas externo – digite*⟧ *Name* ⟦ __(__ *altid* __)__ ⟧ __:__ *tipo* ⟦ __,__ ⟦*Language-Type*⟧ *Name* ⟦ __(__ *altid* __)__ ⟧ __:__ *Type* ... ⟧

## <a name="remarks"></a>Comentários

O argumento de *tipo de idioma* é válido somente no MASM de 32 bits.

O *tipo* pode ser [ABS](operator-abs.md), que importa o *nome* como uma constante. O mesmo que [EXTRN](extrn.md).

## <a name="see-also"></a>Consulte também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
