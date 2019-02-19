---
title: Operadores pós-fixados
ms.date: 11/04/2016
helpviewer_keywords:
- operators [C], postfix
- postfix operators
ms.assetid: 76260011-1624-484e-8bef-72ae7ab556cc
ms.openlocfilehash: a86ede25feeaee3a9fb1c6b146cf9667b85c0c2f
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56147900"
---
# <a name="postfix-operators"></a>Operadores pós-fixados

Os operadores pós-fixados tem a precedência mais alta (a associação mais estreita) na avaliação da expressão.

## <a name="syntax"></a>Sintaxe

*postfix-expression*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*primary-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*postfix-expression*  **[**  *expression*  **]**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*postfix-expression*  **(**  *argument-expression-list*<sub>opt</sub> **)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*postfix-expression*  **.**  *identifier*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*postfix-expression*  **->**  *identifier*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*postfix-expression*  **++**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*postfix-expression*  **--**

Os operadores nesse nível de precedência são: subscritos de matriz, chamadas de função, membros de estrutura e união, e operadores de incremento e decremento pós-fixados.

## <a name="see-also"></a>Consulte também

[Operadores C](../c-language/c-operators.md)
