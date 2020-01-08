---
title: .CODE
ms.date: 12/17/2019
f1_keywords:
- .CODE
helpviewer_keywords:
- .CODE directive
ms.assetid: 2b8c882c-c0d2-4fa3-8335-e6b12717a4f4
ms.openlocfilehash: 0975e96e670400b7fa221ae2d1b9982b5cee613b
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75314140"
---
# <a name="code"></a>.CODE

(somente MASM de 32 bits.) Quando usado com [. MODELO](dot-model.md), indica o início de um segmento de código.

## <a name="syntax"></a>Sintaxe

> **. CODE** ⟦*Name*⟧ \
> ⟦ *segmentItem* ⟧... \
> ⟦ *codesegmentnameId* **termina**;; ⟧\

### <a name="parameters"></a>Parâmetros

*nome*\
Parâmetro opcional que especifica o nome do segmento de código. O nome padrão é **_TEXT** para [modelos](dot-model.md)minúsculos, pequenos, compactas e simples. O nome padrão é *modulename*_TEXT para outros modelos.

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[. ](dot-data.md)\ de dados
[MASM BNF Grammar](masm-bnf-grammar.md)

