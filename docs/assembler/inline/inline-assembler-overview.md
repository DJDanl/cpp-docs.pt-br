---
title: Visão geral do assembler embutido
ms.date: 08/30/2018
helpviewer_keywords:
- inline assembler
- __asm keyword [C++], invoking inline assembler
- invoking inline assembler
- inline assembly, inline assembler
ms.assetid: d990331a-0e33-4760-8d7a-b720b0288335
ms.openlocfilehash: 21e0d9ca0e64922b83518eb79c19d2f2e67813bd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62167005"
---
# <a name="inline-assembler-overview"></a>Visão geral do assembler embutido

**Seção específica da Microsoft**

O assembler integrado permite inserir instruções da linguagem de assembly em seus programas de origem C e C++ sem etapas adicionais de assembly e vinculação. O assembler integrado é incorporado ao compilador e, portanto, não é necessário um assembler separado, como o MASM (Microsoft Macro Assembler).

Como o assembler integrado não requer etapas de link e do assembly separado, é mais conveniente que um assembler separado. Código de assembly embutido pode usar qualquer C ou C++ variável ou função nome que está no escopo, portanto, é fácil integrá-la ao código do programa de C e C++. E porque o código do assembly pode ser misturado com instruções de C e C++, ele pode realizar tarefas que são incômodas ou impossíveis em C ou C++ sozinho.

O [ASM](../../assembler/inline/asm.md) palavra-chave invoca o assembler embutido e pode aparecer sempre que um C ou C++ instrução é legal. Ela não pode aparecer sozinha. Ela deve ser seguida por uma instrução de assembly, um grupo de instruções entre chaves ou, pelo menos, um par vazio de chaves. O termo "bloco `__asm`" refere-se aqui a qualquer instrução ou grupo de instruções, estando ou não entre chaves.

O código a seguir é uma simples `__asm` bloco entre chaves. (O código é uma sequência personalizada de prólogos da função.)

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

Como alternativa, você pode colocar `__asm` na frente de cada instrução de assemblies:

```cpp
__asm push ebp
__asm mov  ebp, esp
__asm sub  esp, __LOCAL_SIZE
```

Como a palavra-chave `__asm` é um separador de instruções, você também pode colocar instruções de assembly na mesma linha:

```cpp
__asm push ebp   __asm mov  ebp, esp   __asm sub  esp, __LOCAL_SIZE
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>