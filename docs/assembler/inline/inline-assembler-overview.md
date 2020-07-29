---
title: Visão geral do assembler embutido
ms.date: 08/30/2018
helpviewer_keywords:
- inline assembler
- __asm keyword [C++], invoking inline assembler
- invoking inline assembler
- inline assembly, inline assembler
ms.assetid: d990331a-0e33-4760-8d7a-b720b0288335
ms.openlocfilehash: 3872dcb194146bf0f4c89b0be03a49b5fe3a9e37
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87192074"
---
# <a name="inline-assembler-overview"></a>Visão geral do assembler embutido

**Específico da Microsoft**

O Assembler embutido permite que você incorpore instruções de linguagem de assembly em seus programas de origem C e C++ sem assembly extra e etapas de link. O assembler integrado é incorporado ao compilador e, portanto, não é necessário um assembler separado, como o MASM (Microsoft Macro Assembler).

Como o assembler integrado não requer etapas de link e do assembly separado, é mais conveniente que um assembler separado. O código de assembly embutido pode usar qualquer variável ou nome de função C ou C++ que esteja no escopo, portanto, é fácil integrá-lo com o código C e C++ do seu programa. E como o código do assembly pode ser misturado com instruções C e C++, ele pode executar tarefas que são complicadas ou impossíveis apenas em C ou C++.

A palavra-chave [__asm](../../assembler/inline/asm.md) invoca o Assembler embutido e pode aparecer sempre que uma instrução C ou C++ for legal. Ela não pode aparecer sozinha. Ela deve ser seguida por uma instrução de assembly, um grupo de instruções entre chaves ou, pelo menos, um par vazio de chaves. O termo " **`__asm`** Bloquear" refere-se a qualquer instrução ou grupo de instruções, seja ou não entre chaves.

O código a seguir é um **`__asm`** bloco simples entre chaves. (O código é uma sequência personalizada de prólogos da função.)

```cpp
// asm_overview.cpp
// processor: x86
void __declspec(naked) main()
{
    // Naked functions must provide their own prolog...
    __asm {
        push ebp
        mov ebp, esp
        sub esp, __LOCAL_SIZE
    }

    // ... and epilog
    __asm {
        pop ebp
        ret
    }
}
```

Como alternativa, você pode colocar **`__asm`** na frente de cada instrução de assembly:

```cpp
__asm push ebp
__asm mov  ebp, esp
__asm sub  esp, __LOCAL_SIZE
```

Como a **`__asm`** palavra-chave é um separador de instrução, você também pode colocar instruções de assembly na mesma linha:

```cpp
__asm push ebp   __asm mov  ebp, esp   __asm sub  esp, __LOCAL_SIZE
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>
