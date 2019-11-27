---
title: ASSUME
ms.date: 11/05/2019
f1_keywords:
- ASSUME
helpviewer_keywords:
- ASSUME directive
ms.assetid: cd162070-aee9-4c65-babc-005c6cc73d7c
ms.openlocfilehash: 73ef8bcc33087a56747b80f94482fcd6c50e3bf6
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74399259"
---
# <a name="assume-32-bit-masm"></a>SUPOR (MASM de 32 bits)

Habilita a verificação de erros para os valores de registro. (somente MASM de 32 bits.)

## <a name="syntax"></a>Sintaxe

> **Supor**  *segregister* __:__ *Name* ⟦ __,__ *segregister* __:__ *Name*... ⟧\
> **Assumir**  *o registro de dataregister* __:__ *tipo* ⟦ __,__ *dataregister* __:__ *tipo*... ⟧\
> **Assumir**  *o registro* __: erro__ ⟦ __,__ *registrar* __: erro__... ⟧\
> **Assuma** *o registro*de ⟦ __:__ ⟧**Nothing** ⟦ __,__ *Register* __: Nothing__... ⟧

## <a name="remarks"></a>Comentários

Depois que um **pressuposto** é colocado em vigor, o Assembler observa as alterações nos valores dos registros fornecidos. **Erro** gerará um erro se o registro for usado. **Nada** remove a verificação de erros de registro. Você pode combinar diferentes tipos de pressuposições em uma instrução.

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)
