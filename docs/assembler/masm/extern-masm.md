---
title: EXTERN (MASM)
ms.date: 08/30/2018
f1_keywords:
- extern
helpviewer_keywords:
- EXTERN directive
ms.assetid: 667d703d-3aaf-4139-a586-29bc5dab1aff
ms.openlocfilehash: fc66338d90b54ecb12ef3ab1aa56214fb445cb13
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74397563"
---
# <a name="extern-masm"></a>EXTERN (MASM)

Define uma ou mais variáveis, rótulos ou símbolos externos chamados *Name* cujo tipo é *Type*.

## <a name="syntax"></a>Sintaxe

> ⟦*De idiomas externo – digite*⟧ *Name* ⟦ __(__ *altid* __)__ ⟧ __:__ *tipo* ⟦ __,__ ⟦*Language-Type*⟧ *Name* ⟦ __(__ *altid* __)__ ⟧ __:__ *Type* ... ⟧

## <a name="remarks"></a>Comentários

O *tipo* pode ser [ABS](../../assembler/masm/operator-abs.md), que importa o *nome* como uma constante. O mesmo que [EXTRN](../../assembler/masm/extrn.md).

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)
