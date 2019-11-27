---
title: EXTERNDEF
ms.date: 08/30/2018
f1_keywords:
- EXTERNDEF
helpviewer_keywords:
- EXTERNDEF directive
ms.assetid: 95a10de6-c345-4428-a2f2-90f7d411dc86
ms.openlocfilehash: 469b49832c171ee78336a0c457f0d269acd3b59d
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74397537"
---
# <a name="externdef"></a>EXTERNDEF

Define uma ou mais variáveis, rótulos ou símbolos externos chamados *Name* cujo tipo é *Type*.

## <a name="syntax"></a>Sintaxe

> **EXTERNDEF** ⟦*Language-tipo*⟧ *Name* __:__ *tipo* ⟦ __,__ ⟦*Language-Type*⟧ *Name* __:__ *tipo* ... ⟧

## <a name="remarks"></a>Comentários

Se o *nome* for definido no módulo, ele será tratado como [público](../../assembler/masm/public-masm.md). Se o *nome* for referenciado no módulo, ele será tratado como [externo](../../assembler/masm/extern-masm.md). Se o *nome* não for referenciado, ele será ignorado. O *tipo* pode ser [ABS](../../assembler/masm/operator-abs.md), que importa o *nome* como uma constante. Normalmente usado em arquivos de inclusão.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)
