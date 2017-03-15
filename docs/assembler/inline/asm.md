---
title: "__asm | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "__asm"
  - "__asm_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __asm [C++]"
  - "Palavra-chave __asm [C++], vs. blocos asm"
ms.assetid: 77ff3bc9-a492-4b5e-85e1-fa4e414e79cd
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# __asm
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 A palavra\-chave `__asm` chama o assembler embutido e pode aparecer sempre que uma declaração C ou C\+ for válida.  Não pode aparecer sozinha.  Ele deve ser seguido por uma declaração de assembly, um grupo de instruções entre chaves, ou, pelo menos, um par vazio de chaves.  O termo "bloco `__asm`" refere\-se aqui a qualquer instrução ou grupo de instruções, estando ou não entre chaves.  
  
> [!NOTE]
>  O suporte do Visual C\+\+ para a palavra\-chave `asm` do C\+\+ padrão é limitado ao fato de que o compilador não irá gerar um erro na palavra\-chave.  No entanto, um bloco de `asm` não gerará nenhum código significativo.  Use `__asm` em vez de `asm`.  
  
 Sintaxe:  
  
 \_\_asm *assembly\-instruction* \[ ; \]  
  
 \_\_asm { *assembly\-instruction\-list* } \[ ; \]  
  
## Gramática  
 `__asm`  `assembly-instruction`  `;` opt  
  
 `__asm {`  `assembly-instruction-list`  `};` opt  
  
 *assembly\-instruction\-list*:  
 `assembly-instruction` `;` opt  
  
 `assembly-instruction` `;` `assembly-instruction-list` `;` opt  
  
 Se usado sem chaves, a palavra\-chave `__asm` significa que o resto da linha é uma declaração da linguagem de assembly.  Se usado com chaves, significa que cada linha entre as chaves é uma declaração da linguagem de assembly.  Para compatibilidade com versões anteriores, `_asm` é um sinônimo para `__asm`.  
  
 Uma vez que a palavra\-chave `__asm` é um separador de instrução, você pode colocar instruções de assembly na mesma linha.  
  
 Antes do Visual C\+\+ 2005, a instrução  
  
```  
__asm int 3  
```  
  
 não fez com que o código nativo fosse gerado quando compilado com **\/clr**; o compilador traduziu a instrução para uma instrução de interrupção de CLR.  
  
 `__asm int 3` resulta agora na geração de código nativo para a função.  Se você quiser que uma função crie um ponto de interrupção no código e que essa função seja compilada em MSIL, use [\_\_debugbreak](../../intrinsics/debugbreak.md).  
  
## Exemplo  
 O fragmento de código a seguir é um bloco simples de `__asm` entre chaves:  
  
```  
__asm {  
   mov al, 2  
   mov dx, 0xD007  
   out dx, al  
}  
```  
  
 Como alternativa, você pode colocar `__asm` na frente de cada instrução de assemblies:  
  
```  
__asm mov al, 2  
__asm mov dx, 0xD007  
__asm out dx, al  
```  
  
 Como a palavra\-chave `__asm` é um separador de instrução, você também pode colocar instruções de assembly na mesma linha.  
  
```  
__asm mov al, 2   __asm mov dx, 0xD007   __asm out dx, al  
```  
  
 Todos os três exemplos geram o mesmo código, mas o primeiro estilo \(incluindo o bloco `__asm` em chaves\) tem algumas vantagens.  As chaves separam claramente o código do assembly do código C ou C\+\+ e impede a repetição desnecessária da palavra\-chave `__asm`.  Chaves também podem evitar ambiguidades.  Se deseja colocar a declaração do C ou do C\+\+ na mesma linha que um bloco `__asm`, você deve incluir o bloco em chaves.  Sem os colchetes, o compilador não é capaz de determinar onde o código do assembly termina e as instruções C ou C\+\+ começam.  Finalmente, como o texto entre chaves tem o mesmo formato que o texto comum de MASM, você pode facilmente recortar e colar o texto de arquivos de origem existentes de MASM.  
  
 Ao contrário das chaves no C e C\+\+, as chaves que incluem um bloco de `__asm` não afetam o escopo variável.  Você também pode aninhar blocos de `__asm`; o aninhamento não afeta o escopo variável.  
  
 **FINALIZAR Específico da Microsoft**  
  
## Consulte também  
 [Palavras\-chave C\+\+](../../cpp/keywords-cpp.md)   
 [Assembler embutido](../../assembler/inline/inline-assembler.md)