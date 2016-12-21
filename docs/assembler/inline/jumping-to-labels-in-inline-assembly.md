---
title: "Saltando at&#233; r&#243;tulos no assembly embutido | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __asm [C++], rótulos"
  - "diferenciação de maiúsculas e minúsculas, rótulos em assembly embutido"
  - "assembly embutido, saltando para rótulos"
  - "saltando para rótulos em assembly embutido"
  - "rótulos, em blocos __asm"
  - "rótulos, em assembly embutido"
ms.assetid: 36c18b97-8981-4631-9dfd-af6c14a04297
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Saltando at&#233; r&#243;tulos no assembly embutido
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 Como um rótulo comum de 2.0 C ou C\+\+, um rótulo em um bloco de `__asm` tem o escopo em toda a função na qual é definido \(não apenas no bloco\).  As instruções de assembly e as instruções de `goto` podem ir diretamente para rótulos dentro ou fora do bloco de `__asm` .  
  
 Os rótulos definidas em blocos de `__asm` não diferenciam maiúsculas e minúsculas; as instruções de `goto` e as instruções de assembly podem fazer referência a essas rótulos sem considerar o caso.  Os rótulos de 2.0 C e C\+\+ diferenciam maiúsculas e minúsculas somente quando usadas pelas instruções de `goto` .  As instruções de assembly podem passar a c ou C\+\+ para o rótulo sem considerar o caso.  
  
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
  
 Não use nomes de função de biblioteca de 2.0 c como rótulos em blocos de `__asm` .  Por exemplo, você poderia ser tentado usar `exit` como um rótulo, como segue:  
  
```  
; BAD TECHNIQUE: using library function name as label  
jne exit  
   .  
   .  
   .  
exit:  
   ; More __asm code follows  
```  
  
 Como **exit** é o nome da função de biblioteca c, esse código pode causar um salto à função de **exit** em vez do local desejado.  
  
 Como em programas de MASM, o símbolo de cifrão \(`$`\) serve como o contador de local atual.  É um rótulo para a instrução que está sendo atualmente montada.  Em blocos de `__asm` , sua própria principal é fazer saltos condicionais longos:  
  
```  
jne $+5 ; next instruction is 5 bytes long  
jmp farlabel  
; $+5  
   .  
   .  
   .  
farlabel:  
```  
  
 **FINALIZAR Específico da Microsoft**  
  
## Consulte também  
 [Assembler embutido](../../assembler/inline/inline-assembler.md)