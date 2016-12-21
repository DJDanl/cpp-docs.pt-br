---
title: ".MODEL | Microsoft Docs"
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
  - ".MODEL"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - ".MODEL directive"
ms.assetid: 057f00df-1515-4c55-852a-d936c8a34b53
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# .MODEL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Inicializa o modelo de memória de programa.  
  
## Sintaxe  
  
```  
.MODEL memorymodel [[, langtype]] [[, stackoption]]  
```  
  
#### Parâmetros  
 `memorymodel`  
 Parâmetro obrigatório que determina o tamanho dos ponteiros de código e dados.  
  
 `langtype`  
 Parâmetro opcional que define as convenções de chamada e de nomes para procedimentos e símbolos públicos.  
  
 `stackoption`  
 Parâmetro opcional.  
  
 `stackoption`is not used if `memorymodel` is `FLAT`.  
  
 Especificação de `NEARSTACK` agrupa o segmento de pilha em um único segmento físico \(`DGROUP`\) juntamente com os dados.  O registrador de segmento de pilha \(`SS`\) será adotada para manter o mesmo endereço do registrador de segmento de dados \(`DS`\).  `FARSTACK`não agrupar a pilha com `DGROUP`; Assim, `SS` não é igual a `DS`.  
  
## Comentários  
 .`MODEL`não é usado em [MASM for x64 \(ml64.exe\)](../../assembler/masm/masm-for-x64-ml64-exe.md).  
  
 A tabela a seguir lista os possíveis valores para cada parâmetro durante o direcionamento para plataformas de 32 bits e 16 bits:  
  
|Parâmetro|valores de 32 bits|valores de 16 bits \(suporte para desenvolvimento de 16 bits anterior\)|  
|---------------|------------------------|-----------------------------------------------------------------------------|  
|`memorymodel`|`FLAT`|`TINY`, `SMALL`, `COMPACT`, `MEDIUM`, `LARGE`, `HUGE`, `FLAT`|  
|`langtype`|`C`, `STDCALL`|`C`, `BASIC`, `FORTRAN`, `PASCAL`, `SYSCALL`, `STDCALL`|  
|`stackoption`|Não usado|`NEARSTACK`, `FARSTACK`|  
  
## Código  
 Para exemplos relacionados MASM, baixe as amostras de compilador de [exemplos do Visual C\+\+ e documentação relacionada para 2010 de Visual Studio](http://go.microsoft.com/fwlink/?LinkID=178749).  
  
 O exemplo a seguir demonstra o uso de `.MODEL` diretiva.  
  
## Exemplo  
  
```  
; file simple.asm  
; For x86 (32-bit), assemble with debug information:   
;   ml -c -Zi simple.asm  
; For x64 (64-bit), assemble with debug information:   
;   ml64 -c -DX64 -Zi simple.asm  
;  
; In this sample, the 'X64' define excludes source not used   
;  when targeting the x64 architecture  
  
ifndef X64  
.686p  
.XMM  
.model flat, C  
endif  
  
.data  
; user data  
  
.code  
; user code  
  
fxn PROC public  
  xor eax, eax ; zero function return value  
  ret  
fxn ENDP  
  
end  
```  
  
## Consulte também  
 [Directives Reference](../../assembler/masm/directives-reference.md)   
 [Exemplos do Visual C\+\+ e documentação relacionada para 2010 de Visual Studio](http://go.microsoft.com/fwlink/?LinkID=178749)