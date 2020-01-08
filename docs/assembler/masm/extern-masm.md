---
title: EXTERN (MASM)
ms.date: 12/06/2019
f1_keywords:
- extern
helpviewer_keywords:
- EXTERN directive
ms.assetid: 667d703d-3aaf-4139-a586-29bc5dab1aff
ms.openlocfilehash: 681c4091a3c54a781bed4b01b235dfeb04f552c6
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75318092"
---
# <a name="extern"></a>EXTERN

Define uma ou mais variáveis, rótulos ou símbolos externos chamados *Name* cujo tipo é *Type*.

## <a name="syntax"></a>Sintaxe

> ⟦*De idiomas externo – digite*⟧ *Name* ⟦ __(__ *altid* __)__ ⟧ __:__ *tipo* ⟦ __,__ ⟦*Language-Type*⟧ *Name* ⟦ __(__ *altid* __)__ ⟧ __:__ *Type* ... ⟧

## <a name="remarks"></a>Comentários

O argumento de *tipo de idioma* é válido somente no MASM de 32 bits.

O *tipo* pode ser [ABS](operator-abs.md), que importa o *nome* como uma constante. O mesmo que [EXTRN](extrn.md).

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
