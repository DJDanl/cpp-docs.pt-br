---
title: .CODE
ms.date: 12/17/2019
f1_keywords:
- .CODE
helpviewer_keywords:
- .CODE directive
ms.assetid: 2b8c882c-c0d2-4fa3-8335-e6b12717a4f4
ms.openlocfilehash: 7e53befcc46319d0ecf2287ab96a19a73a0b0b85
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80076271"
---
# <a name="code"></a>.CODE

(somente MASM de 32 bits.) Quando usado com [. MODELO](dot-model.md), indica o início de um segmento de código.

## <a name="syntax"></a>Sintaxe

> **. CODE** ⟦*Name*⟧ \
> ⟦ *segmentItem* ⟧... \
> ⟦ *codesegmentnameId* **termina**;; ⟧\

### <a name="parameters"></a>parâmetros

*nome*\
Parâmetro opcional que especifica o nome do segmento de código. O nome padrão é **_TEXT** para [modelos](dot-model.md)minúsculos, pequenos, compactas e simples. O nome padrão é *modulename*_TEXT para outros modelos.

## <a name="see-also"></a>Confira também

[Referência de diretivas](directives-reference.md)\
[. ](dot-data.md)\ de dados
[MASM BNF Grammar](masm-bnf-grammar.md)
