---
title: Saltando para rótulos em Assembly embutido | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- inline assembly, jumping to labels
- labels, in inline assembly
- __asm keyword [C++], labels
- case sensitivity, labels in inline assembly
- labels, in __asm blocks
- jumping to labels in inline assembly
ms.assetid: 36c18b97-8981-4631-9dfd-af6c14a04297
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e697df32218c3e2bcdeb03cde44b7b5d854cb7b0
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43693618"
---
# <a name="jumping-to-labels-in-inline-assembly"></a>Passando para rótulos no assembly embutido

**Seção específica da Microsoft**

Como um comuns C ou C++ rótulo, um rótulo em um `__asm` bloco tem escopo em toda a função na qual ele é definido (não somente no bloco). Ambas as instruções de assembly e `goto` instruções podem saltar para rótulos dentro ou fora de `__asm` bloco.

Rótulos definidos em `__asm` blocos não diferenciam maiusculas de minúsculas; os dois `goto` instruções e instruções de assembly podem se referir a esses rótulos, independentemente do caso. Rótulos de C e C++ diferenciam maiusculas de minúsculas somente quando usado pelo `goto` instruções. Instruções de assembly podem saltar para um rótulo de C ou C++ independentemente do caso.

O código a seguir mostra todas as permutas:

```cpp
void func( void )
{
   goto C_Dest;  /* Legal: correct case   */
   goto c_dest;  /* Error: incorrect case */

   goto A_Dest;  /* Legal: correct case   */
   goto a_dest;  /* Legal: incorrect case */

   __asm
   {
      jmp C_Dest ; Legal: correct case
      jmp c_dest ; Legal: incorrect case

      jmp A_Dest ; Legal: correct case
      jmp a_dest ; Legal: incorrect case

      a_dest:    ; __asm label
   }

   C_Dest:       /* C label */
   return;
}
int main()
{
}
```

Não use nomes de função de biblioteca C como rótulos em `__asm` blocos. Por exemplo, você pode ficar tentado a usar `exit` como um rótulo, da seguinte maneira:

```cpp
; BAD TECHNIQUE: using library function name as label
   jne exit
   .
   .
   .
exit:
   ; More __asm code follows
```

Porque **saia** é o nome de uma função de biblioteca C, esse código pode causar um salto para o **sair** de função em vez de para o local desejado.

Como em programas MASM, o símbolo de dólar (`$`) serve como o contador de local atual. Ele é um rótulo para a instrução que está sendo montado no momento. No `__asm` blocos, seu uso principal é fazer com saltos condicionais longa:

```cpp
   jne $+5 ; next instruction is 5 bytes long
   jmp farlabel ; $+5
   .
   .
   .
farlabel:
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>