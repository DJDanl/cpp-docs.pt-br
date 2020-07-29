---
title: Passando para rótulos no assembly embutido
ms.date: 08/30/2018
helpviewer_keywords:
- inline assembly, jumping to labels
- labels, in inline assembly
- __asm keyword [C++], labels
- case sensitivity, labels in inline assembly
- labels, in __asm blocks
- jumping to labels in inline assembly
ms.assetid: 36c18b97-8981-4631-9dfd-af6c14a04297
ms.openlocfilehash: 0c411289745466bd6478cc82ab30e6a05be9cc25
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87191996"
---
# <a name="jumping-to-labels-in-inline-assembly"></a>Passando para rótulos no assembly embutido

**Específico da Microsoft**

Como um rótulo C ou C++ comum, um rótulo em um **`__asm`** bloco tem um escopo em toda a função na qual ele está definido (não apenas no bloco). Ambas as instruções de assembly e **`goto`** instruções podem ir para rótulos dentro ou fora do **`__asm`** bloco.

Rótulos definidos em **`__asm`** blocos não diferenciam maiúsculas de minúsculas; ambas as instruções **`goto`** e instruções de assembly podem se referir a esses rótulos sem considerar maiúsculas e minúsculas. Os rótulos C e C++ diferenciam maiúsculas de minúsculas somente quando usados por **`goto`** instruções. Instruções de assembly podem ir para um rótulo C ou C++ sem considerar maiúsculas e minúsculas.

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

Não use nomes de função de biblioteca C como rótulos em **`__asm`** blocos. Por exemplo, você pode estar tentado a usar `exit` como um rótulo, da seguinte maneira:

```cpp
; BAD TECHNIQUE: using library function name as label
   jne exit
   .
   .
   .
exit:
   ; More __asm code follows
```

Como **Exit** é o nome de uma função da biblioteca C, esse código pode causar um salto para a função **Exit** em vez de para o local desejado.

Como nos programas MASM, o símbolo de dólar ( `$` ) serve como o contador de local atual. É um rótulo para a instrução que está sendo montada no momento. Em **`__asm`** blocos, seu principal uso é fazer saltos condicionais longos:

```cpp
   jne $+5 ; next instruction is 5 bytes long
   jmp farlabel ; $+5
   .
   .
   .
farlabel:
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>
