---
title: ASSUME
ms.date: 11/05/2019
f1_keywords:
- ASSUME
helpviewer_keywords:
- ASSUME directive
ms.assetid: cd162070-aee9-4c65-babc-005c6cc73d7c
ms.openlocfilehash: a74a5336e626f561f1fc61e866792ce193332d84
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75316532"
---
# <a name="assume"></a>ASSUME

Habilita a verificação de erros para os valores de registro. (somente MASM de 32 bits.)

## <a name="syntax"></a>Sintaxe

> **Supor**  *segregister* __:__ *Name* ⟦ __,__ *segregister* __:__ *Name*... ⟧\
> **Assumir**  *o registro de dataregister* __:__ *tipo* ⟦ __,__ *dataregister* __:__ *tipo*... ⟧\
> **Assumir**  *o registro* __: erro__ ⟦ __,__ *registrar* __: erro__... ⟧\
> **Assuma** *o registro*de ⟦ __:__ ⟧**Nothing** ⟦ __,__ *Register* __: Nothing__... ⟧

## <a name="remarks"></a>Comentários

Depois que um **pressuposto** é colocado em vigor, o Assembler observa as alterações nos valores dos registros fornecidos. **Erro** gerará um erro se o registro for usado. **Nada** remove a verificação de erros de registro. Você pode combinar diferentes tipos de pressuposições em uma instrução.

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
