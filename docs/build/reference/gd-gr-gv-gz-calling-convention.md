---
title: "/Gd, /Gr, /Gv, /Gz (conven&#231;&#227;o de chamada) | Microsoft Docs"
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
  - "/gr"
  - "/Gv"
  - "/gz"
  - "/Gd"
  - "VC.Project.VCCLCompilerTool.CallingConvention"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Gd (C++)"
  - "Opção de compilador /Gr (C++)"
  - "Opção de compilador /Gv [C++]"
  - "Opção de compilador /Gz (C++)"
  - "Opção de compilador Gd [C++]"
  - "Opção de compilador -Gd [C++]"
  - "Opção de compilador Gr [C++]"
  - "Opção de compilador -Gr [C++]"
  - "Opção de compilador Gv [C++]"
  - "Opção de compilador -Gv [C++]"
  - "Opção de compilador Gz [C++]"
  - "Opção de compilador -Gz [C++]"
ms.assetid: fd3110cb-2d77-49f2-99cf-a03f9ead00a3
caps.latest.revision: 19
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Gd, /Gr, /Gv, /Gz (conven&#231;&#227;o de chamada)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essas opções determinam a ordem em que os argumentos de função são enviados para a pilha, se a função do chamador ou a função chamada remove os argumentos da pilha no final da chamada, e a convenção de decoração de nomes que o compilador usa para identificar funções individuais.  
  
## Sintaxe  
  
```  
/Gd  
/Gr  
/Gv  
/Gz  
```  
  
## Comentários  
 **\/Gd**, configuração padrão, especifica a convenção de chamada [\_\_cdecl](../Topic/__cdecl.md) para todas as funções, exceto as funções de membro do C\+\+, e as funções que são marcadas com [\_\_stdcall](../../cpp/stdcall.md), [\_\_fastcall](../../cpp/fastcall.md), ou [\_\_vectorcall](../Topic/__vectorcall.md).  
  
 **\/Gr** especifica a convenção de chamada `__fastcall` para todas as funções exceto funções de membro de C\+\+, funções chamadas `main`, e funções que são `__cdecl`marcada, `__stdcall`, ou `__vectorcall`.  Todas as funções de `__fastcall` devem ter protótipos.  Esta convenção de chamada só está disponível nos compiladores que direcionam o x86 e é ignorada pelos compiladores que direcionam outras arquiteturas.  
  
 **\/Gz** especifica a convenção de chamada `__stdcall` para todas as funções exceto funções de membro de C\+\+, funções chamadas `main`, e funções que são `__cdecl`marcada, `__fastcall`, ou `__vectorcall`.  Todas as funções de `__stdcall` devem ter protótipos.  Esta convenção de chamada só está disponível nos compiladores que direcionam o x86 e é ignorada pelos compiladores que direcionam outras arquiteturas.  
  
 **\/Gv** especifica a convenção de chamada `__vectorcall` para todas as funções, exceto as funções de membro de C\+\+, funções chamadas main, funções com uma lista de argumentos variáveis de `vararg` , ou funções que são marcadas com um `__cdecl`conflitante, `__stdcall`, ou atributo de `__fastcall` .  Esta convenção de chamada está disponível somente em arquiteturas x86 e x64, que são compatíveis com \/arch:SSE2 e superior, e é ignorada por compiladores que direcionam a arquitetura ARM.  
  
 As funções que recebem um número variável de argumentos devem ser marcadas como `__cdecl`.  
  
 **\/Gd**, **\/Gr**, **\/Gv** e **\/Gz** não são compatíveis com [\/clr: seguro](../../build/reference/clr-common-language-runtime-compilation.md) ou **\/clr:pure**.  
  
> [!NOTE]
>  Por padrão para os processadores x86, as funções de membro de C\+\+ usam [\_\_thiscall](../../cpp/thiscall.md).  
  
 Para todos os processadores, uma função membro que está explicitamente marcada como `__cdecl`, `__fastcall`, `__vectorcall` ou `__stdcall` usa a convenção de chamada especificada caso não seja ignorada na arquitetura.  Uma função de membro que recebe um número variável de argumentos sempre usa `__cdecl` que chama a convenção.  
  
 Essas opções de compilador não têm nenhum efeito sobre a decoração de nome de métodos e funções do C\+\+.  A menos que declarado como `extern "C"`, métodos e funções do C\+\+ usam um esquema de decoração de nome diferente.  Para obter mais informações, consulte [Nomes decorados](../Topic/Decorated%20Names.md).  
  
 Para obter mais informações sobre as convenções de chamada, consulte [Convenções de chamada](../Topic/Calling%20Conventions.md).  
  
## Específicos de \_\_cdecl  
 Nos processadores x86, os argumentos de função são passados na pilha da direita para a esquerda.  Em arquiteturas ARM e x64, alguns argumentos são passados pelo registro e o restante é passado na pilha da direita para a esquerda.  A rotina de chamada remove os argumentos da pilha.  
  
 Para o C, a convenção de nomenclatura de `__cdecl` usa o nome da função precedido por um sublinhado \( `_` \); nenhuma tradução de maiúscula ou minúscula é executada.  A menos que declarado como `extern "C"`, funções do C\+\+ usam um esquema de decoração de nome diferente.  Para obter mais informações, consulte [Nomes decorados](../Topic/Decorated%20Names.md).  
  
## Específicos de \_\_fastcall  
 Alguns dos argumentos de uma função `__fastcall` são passados em registros \(para processadores x86, ECX e EDX\), e o restante é empurrado para uma pilha da direita para a esquerda.  A rotina chamada remove esses argumentos da pilha antes de retornar.  Normalmente, **\/Gr** diminui o tempo de execução.  
  
> [!NOTE]
>  Seja cuidadoso ao usar a convenção de chamada `__fastcall` para qualquer função que está escrita na linguagem de assembly embutida.  O uso de registros poderia entrar em conflito com o uso do compilador.  
  
 Para o C, a convenção de nomenclatura de `__fastcall` usa o nome da função precedido por um sinal de arroba \(`@`\) seguido pelo tamanho dos argumentos da função em bytes.  Nenhuma tradução realizada.  O compilador usa esse modelo para a convenção de nomenclatura:  
  
```c  
@function_name@number  
```  
  
 Ao usar a convenção de nomenclatura de `__fastcall`, use os arquivos inclusos por padrão.  Caso contrário, você terá referências externas não resolvidas.  
  
## Específicos de \_\_stdcall  
 Os argumentos de uma função de `__stdcall` são empurrados na pilha da direita para a esquerda, e a função chamada remove esses argumentos da pilha antes que retornem.  
  
 Para o C, a convenção de nomenclatura de `__stdcall` usa o nome da função precedido por um sublinhado \(`_`\) seguido por um sinal de arroba \(@\) e o tamanho dos argumentos da função em bytes.  Nenhuma tradução realizada.  O compilador usa esse modelo para a convenção de nomenclatura:  
  
```c  
_functionname@number  
```  
  
## Específicos de \_\_vectorcall  
 Os argumentos inteiros de uma função de `__vectorcall` são passados por valor, usando até dois \(em x86\) ou quatro \(em x64\) registros inteiros, e até seis registros de MMX para valores de ponto flutuante e vetoriais, e o restante é passado na pilha da direita para a esquerda.  A função chamada limpa a pilha antes de retornar.  Valores de retorno do vetor e do ponto flutuante são retornados em XMM0.  
  
 Para o C, a convenção de nomenclatura de `__vectorcall` usa o nome da função precedido por dois sinais de arroba \(@@\) e o tamanho dos argumentos da função em bytes.  Nenhuma tradução realizada.  O compilador usa esse modelo para a convenção de nomenclatura:  
  
```c  
functionname@@number  
```  
  
### To set this compiler option in the Visual Studio development environment  
  
1.  Open the project's **Property Pages** dialog box.  For details, see [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Select the **C\/C\+\+** folder.  
  
3.  Select the **Advanced** property page.  
  
4.  Modify the **Calling Convention** property.  
  
### To set this compiler option programmatically  
  
-   See <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.CallingConvention%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)