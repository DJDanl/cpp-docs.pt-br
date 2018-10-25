---
title: Operadores aditivos C | Microsoft Docs
ms.custom: ''
ms.date: 10/18/2018
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- usual arithmetic conversions
- operators [C], addition
- + operator, additive operators
- additive operators
- arithmetic operators [C++], additive operators
ms.assetid: bb8ac205-b061-41fc-8dd4-dab87c8b900c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 339904e3fe75c712254f3a7802fc76a0e283c8e5
ms.sourcegitcommit: 0164af5615389ffb1452ccc432eb55f6dc931047
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/23/2018
ms.locfileid: "49808349"
---
# <a name="c-additive-operators"></a>Operadores aditivos C

Os operadores aditivos executam adição (**+**) e subtração (**-**).

## <a name="syntax"></a>Sintaxe

*additive-expression*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*multiplicative-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*additive-expression* **+** *multiplicative-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*additive-expression* **-** *multiplicative-expression*

> [!NOTE]
> Embora a sintaxe de *additive-expression* inclua *multiplicative-expression*, isso não significa que expressões que usam multiplicação sejam necessárias. Consulte a sintaxe em [Resumo de sintaxe da linguagem C](../c-language/c-language-syntax-summary.md), para *multiplicative-expression*, *cast-expression* e *unary-expression*.

Os operandos podem ser valores integrais ou flutuantes. Algumas operações aditivas também podem ser executadas em valores de ponteiro, como descrito na discussão de cada operador.

Os operadores aditivos executam as conversões aritméticas comuns em operandos do tipo integral ou flutuantes. O tipo do resultado é o tipo dos operandos após conversão. Como as conversões executadas pelos operadores aditivos não fornecem condições de estouro ou de estouro negativo, as informações podem ser perdidas se o resultado de uma operação aditiva não puder ser representado no tipo dos operandos após a conversão.

## <a name="see-also"></a>Consulte também

[Operadores aditivos: + e -](../cpp/additive-operators-plus-and.md)