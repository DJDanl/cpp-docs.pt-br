---
title: .SAFESEH
ms.date: 08/30/2018
f1_keywords:
- .SAFESEH
helpviewer_keywords:
- registering functions as exception handlers
- SAFESEH directive
- .SAFESEH directive
ms.assetid: 6eaac8c4-c46f-47ae-8a66-f5cfeb267e43
ms.openlocfilehash: 417aea13518621f775cafa176ff7d74f9704d511
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62178287"
---
# <a name="safeseh"></a>.SAFESEH

Registra uma função como um manipulador de exceção estruturada.

## <a name="syntax"></a>Sintaxe

> .SAFESEH identifier

## <a name="remarks"></a>Comentários

*identificador* deve ser a ID para definidos localmente [PROC](../../assembler/masm/proc.md) ou [EXTRN](../../assembler/masm/extrn.md) PROC. Um [rótulo](../../assembler/masm/label-masm.md) não é permitido. A. Diretiva SAFESEH requer o [/safeseh](../../assembler/masm/ml-and-ml64-command-line-reference.md) ml.exe opção de linha de comando.

Para obter mais informações sobre manipuladores de exceção estruturada, consulte [/SAFESEH](../../build/reference/safeseh-image-has-safe-exception-handlers.md).

Por exemplo, para registrar um manipulador de exceção segura, crie um novo arquivo MASM (como a seguir), montar /SafeSEH. e adicioná-lo para os objetos vinculados.

```asm
.386
.model  flat
MyHandler   proto
.safeseh    MyHandler
end
```

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>