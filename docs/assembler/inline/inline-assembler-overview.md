---
title: Visão geral do assembler embutido
ms.date: 08/30/2018
helpviewer_keywords:
- inline assembler
- __asm keyword [C++], invoking inline assembler
- invoking inline assembler
- inline assembly, inline assembler
ms.assetid: d990331a-0e33-4760-8d7a-b720b0288335
ms.openlocfilehash: 6233e07e115c21a0a173f094079dc9c1753533b6
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169391"
---
# <a name="inline-assembler-overview"></a>Visão geral do assembler embutido

**Seção específica da Microsoft**

O Assembler embutido permite que você incorpore instruções de linguagem de assembly C++ em seus programas C e de origem sem assembly extra e etapas de link. O assembler integrado é incorporado ao compilador e, portanto, não é necessário um assembler separado, como o MASM (Microsoft Macro Assembler).

Como o assembler integrado não requer etapas de link e do assembly separado, é mais conveniente que um assembler separado. O código de assembly embutido pode usar C++ qualquer c ou nome de função ou variável que esteja no escopo, portanto, é fácil integrá-lo com o C++ C e o código do seu programa. E como o código do assembly pode ser misturado com instruções C++ c e, ele pode executar tarefas que são complicadas ou impossíveis C++ em C ou sozinhas.

A palavra-chave [__asm](../../assembler/inline/asm.md) invoca o Assembler embutido e pode aparecer sempre C++ que um C ou uma instrução for legal. Ela não pode aparecer sozinha. Ela deve ser seguida por uma instrução de assembly, um grupo de instruções entre chaves ou, pelo menos, um par vazio de chaves. O termo "bloco `__asm`" refere-se aqui a qualquer instrução ou grupo de instruções, estando ou não entre chaves.

O código a seguir é um bloco de `__asm` simples entre chaves. (O código é uma sequência personalizada de prólogos da função.)

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

## <a name="see-also"></a>Confira também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>
