---
title: "/Gh (habilitar fun&#231;&#227;o de gancho _penter) | Microsoft Docs"
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
  - "_penter"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Gh (C++)"
  - "Função _penter"
  - "Opção de compilador Gh [C++]"
  - "Opção de compilador -Gh [C++]"
ms.assetid: 1510a082-8a0e-486e-a309-6add814b494f
caps.latest.revision: 18
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Gh (habilitar fun&#231;&#227;o de gancho _penter)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Faz uma chamada à função de `_penter` no início de cada método ou função.  
  
## Sintaxe  
  
```  
/Gh  
```  
  
## Comentários  
 A função de `_penter` não é parte de qualquer biblioteca e cabe a você para fornecer uma definição para `_penter`.  
  
 A menos que você planejar para chamar explicitamente `_penter`, você não precisa fornecer um protótipo.  A função deve aparecer como se tivesse o seguinte protótipo, e deve enviar o conteúdo de todos os registros na entrada e o conteúdo inalterado aparecer na saída:  
  
```  
void __declspec(naked) _cdecl _penter( void );  
```  
  
 Essa instrução não está disponível para projetos de 64 bits.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção do compilador na caixa de **Opções Adicionais** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Exemplo  
 O código a seguir, quando criado com **\/Gh**, mostra como `_penter` é chamado duas vezes; uma vez que ao inserir a função `main` e uma vez ao inserir a função `x`.  
  
```  
// Gh_compiler_option.cpp  
// compile with: /Gh  
// processor: x86  
#include <stdio.h>  
void x() {}  
  
int main() {  
   x();  
}  
  
extern "C" void __declspec(naked) _cdecl _penter( void ) {  
   _asm {  
      push eax  
      push ebx  
      push ecx  
      push edx  
      push ebp  
      push edi  
      push esi  
    }  
  
   printf_s("\nIn a function!");  
  
   _asm {  
      pop esi  
      pop edi  
      pop ebp  
      pop edx  
      pop ecx  
      pop ebx  
      pop eax  
      ret  
    }  
}  
```  
  
  **Em uma função\!**  
**Em uma função\!**   
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)