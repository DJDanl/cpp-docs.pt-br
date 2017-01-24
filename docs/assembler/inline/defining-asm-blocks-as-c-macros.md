---
title: "Definindo blocos __asm como macros C | Microsoft Docs"
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
  - "Palavra-chave __asm [C++], como macros C"
  - "Macros , blocos __asm"
  - "Visual C, Macros "
ms.assetid: 677ba11c-21c8-4609-bba7-cd47312243b0
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Definindo blocos __asm como macros C
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Macros C oferecem uma maneira conveniente de inserir o código do assembly no código\-fonte, mas o exigem atenção adicional como uma macro é expandida em uma única linha lógica.  Para criar macros sem problemas, siga estas regras:  
  
-   Incluir o bloco de `__asm` em chaves.  
  
-   Colocar a palavra\-chave de `__asm` na frente de cada instrução de assembly.  
  
-   Use comentários desatualizadas C \( `/* comment */`\) em vez dos comentários de estilo de assembly \( `; comment`\) ou de comentários de linha única C \( `// comment`\).  
  
 Para ilustrar, o exemplo define uma macro simples:  
  
```  
#define PORTIO __asm      \  
/* Port output */         \  
{                         \  
   __asm mov al, 2        \  
   __asm mov dx, 0xD007   \  
   __asm out dx, al       \  
}  
```  
  
 à primeira vista, os três palavras\-chave os mais recentes de `__asm` aparecem supérfluos.  São necessários, no entanto, como a macro é expandida em uma única linha:  
  
```  
__asm /* Port output */ { __asm mov al, 2  __asm mov dx, 0xD007 __asm out dx, al }  
```  
  
 O terceiro e quarto palavra\-chave de `__asm` são necessários como separadores da instrução.  Os únicos separadores da instrução reconhecidos em blocos de `__asm` é o caractere de nova linha e a palavra\-chave de `__asm` .  Como um bloco definido como uma macro é uma linha lógica, é necessário separar cada instrução com `__asm`.  
  
 As chaves são essenciais também.  Se você omitir os, o compilador pode ser confundido por instruções de 2.0 C ou C\+\+ na mesma linha à direita de invocação macro.  Sem a chave de fechamento, o compilador não pode informar onde o código do assembly para e, consulte as instruções de 2.0 C ou C\+\+ após o bloco de `__asm` como instruções de assembly.  
  
 o assembly estilo comenta o que começam com um ponto\-e\-vírgula \(\)**;**continua até o final da linha.  Isso causa problemas em macros porque o compilador ignora todos depois que o comentário, qualquer maneira até o final da linha lógica.  O mesmo vale de comentários de linha única de 2.0 C ou C\+\+ \( `// comment`\).  Para evitar erros, use comentários desatualizadas C \( `/* comment */`\) em blocos de `__asm` definidos como macros.  
  
 Um bloco de `__asm` escrito como a macro c pode levar argumentos.  Ao contrário de uma macro comum de C, porém, uma macro de `__asm` não pode retornar um valor.  Portanto você não pode usar em expressões como macros c ou C\+\+ 2.0.  
  
 Tenha cuidado para não invocar indiscriminada macros desse tipo.  Por exemplo, invocar um assembly a macro de idioma em uma função declarada com a convenção de `__fastcall` pode causar resultados inesperados. \(Consulte.\) [Usando e preservando registros no assembly embutido](../../assembler/inline/using-and-preserving-registers-in-inline-assembly.md)  
  
 **FINALIZAR Específico da Microsoft**  
  
## Consulte também  
 [Assembler embutido](../../assembler/inline/inline-assembler.md)