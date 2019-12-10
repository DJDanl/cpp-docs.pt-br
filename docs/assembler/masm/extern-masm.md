---
title: EXTERN (MASM)
ms.date: 12/06/2019
f1_keywords:
- extern
helpviewer_keywords:
- EXTERN directive
ms.assetid: 667d703d-3aaf-4139-a586-29bc5dab1aff
ms.openlocfilehash: 38ea50e75f2a8e19a7a99860f691904053b6739a
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74987861"
---
# <a name="extern-masm"></a>EXTERN (MASM)

Define uma ou mais variáveis, rótulos ou símbolos externos chamados *Name* cujo tipo é *Type*.

## <a name="syntax"></a>Sintaxe

> ⟦*De idiomas externo – digite*⟧ *Name* ⟦ __(__ *altid* __)__ ⟧ __:__ *tipo* ⟦ __,__ ⟦*Language-Type*⟧ *Name* ⟦ __(__ *altid* __)__ ⟧ __:__ *Type* ... ⟧

## <a name="remarks"></a>Comentários

O argumento de *tipo de idioma* é válido somente no MASM de 32 bits.

O *tipo* pode ser [ABS](../../assembler/masm/operator-abs.md), que importa o *nome* como uma constante. O mesmo que [EXTRN](../../assembler/masm/extrn.md).

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)
