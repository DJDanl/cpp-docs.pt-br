---
title: Saltando para rótulos em Assembly embutido | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 5a96bd532b5b4f03cb2040dd3157a6224ccf5029
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
---
# <a name="jumping-to-labels-in-inline-assembly"></a>Passando para rótulos no assembly embutido
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Como um comum C ou C++ rótulo, um rótulo em uma `__asm` bloco tem escopo em toda a função na qual ela está definida (não apenas no bloco). Ambas as instruções de assembly e `goto` instruções podem saltar para rótulos dentro ou fora de `__asm` bloco.  
  
 Rótulos definidos em `__asm` blocos não diferenciam maiusculas de minúsculas; as `goto` instruções e instruções de assembly podem fazer referência a esses rótulos sem considerar o caso. Rótulos de C e C++ diferenciam maiusculas de minúsculas apenas quando usado por `goto` instruções. Instruções de assembly podem saltar para um rótulo de C ou C++ sem considerar o caso.  
  
 O código a seguir mostra todas as permutações:  
  
```  
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
  
 Não use nomes de função de biblioteca C como rótulos em `__asm` blocos. Por exemplo, você poderá ficar tentado usar `exit` como um rótulo, da seguinte maneira:  
  
```  
; BAD TECHNIQUE: using library function name as label  
jne exit  
   .  
   .  
   .  
exit:  
   ; More __asm code follows  
```  
  
 Porque **sair** é o nome de uma função de biblioteca C, esse código pode causar um salto para o **sair** função em vez de para o local desejado.  
  
 Como programas MASM, o símbolo de dólar (`$`) serve como o contador de local atual. É um rótulo para a instrução que está sendo montado no momento. Em `__asm` blocos, seu uso principal é tornar saltos longa condicionais:  
  
```  
jne $+5 ; next instruction is 5 bytes long  
jmp farlabel  
; $+5  
   .  
   .  
   .  
farlabel:  
```  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Assembler embutido](../../assembler/inline/inline-assembler.md)