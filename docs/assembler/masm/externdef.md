---
title: EXTERNDEF
ms.date: 12/06/2019
f1_keywords:
- EXTERNDEF
helpviewer_keywords:
- EXTERNDEF directive
ms.assetid: 95a10de6-c345-4428-a2f2-90f7d411dc86
ms.openlocfilehash: 2cc5884a7473da9175a6b6af4b4251314deffeb4
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75313386"
---
# <a name="externdef"></a>EXTERNDEF

Define uma ou mais variáveis, rótulos ou símbolos externos chamados *Name* cujo tipo é *Type*.

## <a name="syntax"></a>Sintaxe

> **EXTERNDEF** ⟦*Language-tipo*⟧ *Name* __:__ *tipo* ⟦ __,__ ⟦*Language-Type*⟧ *Name* __:__ *tipo* ... ⟧

## <a name="remarks"></a>Comentários

O argumento de *tipo de idioma* é válido somente no MASM de 32 bits.

Se o *nome* for definido no módulo, ele será tratado como [público](public-masm.md). Se o *nome* for referenciado no módulo, ele será tratado como [externo](extern-masm.md). Se o *nome* não for referenciado, ele será ignorado. O *tipo* pode ser [ABS](operator-abs.md), que importa o *nome* como uma constante. Normalmente usado em arquivos de inclusão.

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
