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
ms.openlocfilehash: 199156a08af13f4a70793609b37c70b0c95bf9ba
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169325"
---
# <a name="jumping-to-labels-in-inline-assembly"></a>Passando para rótulos no assembly embutido

**Seção específica da Microsoft**

Como um C ou C++ rótulo comum, um rótulo em um bloco de `__asm` tem um escopo em toda a função na qual ele está definido (não apenas no bloco). As instruções de assembly e as instruções `goto` podem ir para rótulos dentro ou fora do bloco de `__asm`.

Rótulos definidos em blocos de `__asm` não diferenciam maiúsculas de minúsculas; as instruções `goto` e instruções de assembly podem se referir a esses rótulos sem considerar maiúsculas e minúsculas. C e C++ rótulos diferenciam maiúsculas de minúsculas somente quando usados por instruções `goto`. Instruções de assembly podem ir para um C C++ ou rótulo sem considerar maiúsculas e minúsculas.

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

Não use nomes de função de biblioteca C como rótulos em blocos de `__asm`. Por exemplo, você pode estar tentado a usar `exit` como um rótulo, da seguinte maneira:

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

Como nos programas MASM, o símbolo de dólar (`$`) serve como o contador de local atual. É um rótulo para a instrução que está sendo montada no momento. Em blocos de `__asm`, seu principal uso é fazer saltos condicionais longos:

```cpp
   jne $+5 ; next instruction is 5 bytes long
   jmp farlabel ; $+5
   .
   .
   .
farlabel:
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>
