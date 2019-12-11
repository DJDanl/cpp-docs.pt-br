---
title: EXTERNDEF
ms.date: 12/06/2019
f1_keywords:
- EXTERNDEF
helpviewer_keywords:
- EXTERNDEF directive
ms.assetid: 95a10de6-c345-4428-a2f2-90f7d411dc86
ms.openlocfilehash: e757781151bd1bb57940e5c54f7333a5daa93c74
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74987888"
---
# <a name="externdef"></a>EXTERNDEF

Define uma ou mais variáveis, rótulos ou símbolos externos chamados *Name* cujo tipo é *Type*.

## <a name="syntax"></a>Sintaxe

> **EXTERNDEF** ⟦*Language-tipo*⟧ *Name* __:__ *tipo* ⟦ __,__ ⟦*Language-Type*⟧ *Name* __:__ *tipo* ... ⟧

## <a name="remarks"></a>Comentários

O argumento de *tipo de idioma* é válido somente no MASM de 32 bits.

Se o *nome* for definido no módulo, ele será tratado como [público](../../assembler/masm/public-masm.md). Se o *nome* for referenciado no módulo, ele será tratado como [externo](../../assembler/masm/extern-masm.md). Se o *nome* não for referenciado, ele será ignorado. O *tipo* pode ser [ABS](../../assembler/masm/operator-abs.md), que importa o *nome* como uma constante. Normalmente usado em arquivos de inclusão.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)
