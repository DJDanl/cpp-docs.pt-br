---
title: IF (MASM)
ms.date: 08/30/2018
f1_keywords:
- if
helpviewer_keywords:
- IF directive
ms.assetid: 82e43712-4f0c-4bf6-90ce-0663e81af707
ms.openlocfilehash: 2b91698640e028bf91d822c12b85ded651a04d8d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62203058"
---
# <a name="if-masm"></a>IF (MASM)

Concede o conjunto de *ifstatements* se *expression1* for verdadeira (diferente de zero) ou *elseifstatements* se *expression1* for false (0) e *expression2* é verdadeiro.

## <a name="syntax"></a>Sintaxe

> IF *expression1*<br/>
> *ifstatements*<br/>
> [[ELSEIF *expression2*<br/>
> *elseifstatements*]]<br/>
> [[ELSE<br/>
> *elsestatements*]]<br/>
> ENDIF

## <a name="remarks"></a>Comentários

As seguintes diretivas podem ser substituídas por [ELSEIF](../../assembler/masm/elseif-masm.md): **ELSEIFB**, **ELSEIFDEF**, **ELSEIFDIF**, **ELSEIFDIFI**, **ELSEIFE**, **ELSEIFIDN**, **ELSEIFIDNI**, **ELSEIFNB**, e **ELSEIFNDEF**. Opcionalmente, monta *elsestatements* se a expressão for falsa. Observe que as expressões são avaliadas em tempo de assembly.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>