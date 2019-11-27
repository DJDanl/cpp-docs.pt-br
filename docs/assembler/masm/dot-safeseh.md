---
title: .SAFESEH
ms.date: 11/05/2019
f1_keywords:
- .SAFESEH
helpviewer_keywords:
- registering functions as exception handlers
- SAFESEH directive
- .SAFESEH directive
ms.assetid: 6eaac8c4-c46f-47ae-8a66-f5cfeb267e43
ms.openlocfilehash: df9798800da293e5e0b4f545a8442380b7ff9408
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74397992"
---
# <a name="safeseh-32-bit-masm"></a>. SAFESEH (32-bit MASM)

Registra uma função como um manipulador de exceção estruturado. (somente MASM de 32 bits.)

## <a name="syntax"></a>Sintaxe

> **.**  *Identificador* SAFESEH

## <a name="remarks"></a>Comentários

o *identificador* deve ser a ID para [um proc. proc ou](../../assembler/masm/proc.md) [EXTRN](../../assembler/masm/extrn.md) definido localmente. Um [rótulo](../../assembler/masm/label-masm.md) não é permitido. Dos. A diretiva SAFESEH requer a opção de linha de comando [/SAFESEH](../../assembler/masm/ml-and-ml64-command-line-reference.md) ml. exe.

Para obter mais informações sobre manipuladores de exceção estruturada, consulte [/SAFESEH](../../build/reference/safeseh-image-has-safe-exception-handlers.md).

Por exemplo, para registrar um manipulador de exceção seguro, crie um novo arquivo MASM (da seguinte maneira), monte com/SAFESEH e adicione-o aos objetos vinculados.

```asm
.386
.model  flat
MyHandler   proto
.safeseh    MyHandler
end
```

## <a name="see-also"></a>Consulte também

[Referência de diretivas](directives-reference.md)
