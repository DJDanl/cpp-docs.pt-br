---
title: Assembler embutido (C)
ms.date: 11/04/2016
helpviewer_keywords:
- __asm keyword [C]
- inline assembler [C]
ms.assetid: 821acc77-60b1-434c-ba54-2ba930a25ab4
ms.openlocfilehash: f6bff3bfef64b45c8a02bb9ad69d2731ba778525
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229604"
---
# <a name="inline-assembler-c"></a>Assembler embutido (C)

**Específico da Microsoft**

O assembler integrado permite inserir instruções da linguagem de assembly diretamente aos seus programas de código-fonte C sem etapas adicionais de assembly e vinculação. O assembler integrado é incorporado ao compilador e, portanto, não é necessário um assembler separado, como o MASM (Microsoft Macro Assembler).

Como o assembler integrado não requer etapas de link e do assembly separado, é mais conveniente que um assembler separado. O código do assembly integrado pode usar qualquer nome de variável ou de função C que esteja no escopo. Portanto, ele é de fácil integração com código C do programa. E como o código do assembly pode ser combinado com as instruções de C, ele poderá realizar as tarefas que são incômodas ou impossíveis apenas em C.

A **`__asm`** palavra-chave invoca o Assembler embutido e pode aparecer sempre que uma instrução C for legal. Ela não pode aparecer sozinha. Ela deve ser seguida por uma instrução de assembly, um grupo de instruções entre chaves ou, pelo menos, um par vazio de chaves. O termo " **`__asm`** Bloquear" refere-se a qualquer instrução ou grupo de instruções, seja ou não entre chaves.

O código a seguir é um **`__asm`** bloco simples entre chaves. (O código é uma sequência personalizada de prólogos da função.)

```
__asm
{
   push ebp
   mov  ebp, esp
   sub  esp, __LOCAL_SIZE
}
```

Como alternativa, você pode colocar **`__asm`** na frente de cada instrução de assembly:

```
__asm push ebp
__asm mov  ebp, esp
__asm sub  esp, __LOCAL_SIZE
```

Como a **`__asm`** palavra-chave é um separador de instrução, você também pode colocar instruções de assembly na mesma linha:

```
__asm push ebp   __asm mov  ebp, esp   __asm sub  esp, __LOCAL_SIZE
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Atributos de função](../c-language/function-attributes.md)
