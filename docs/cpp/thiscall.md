---
title: "__thiscall | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "__thiscall"
  - "__thiscall_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __thiscall [C++]"
ms.assetid: a6a22dd2-0101-4885-b33b-22f6057965df
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# __thiscall
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 A convenção de chamada `__thiscall` é usada em funções membro e é a convenção de chamada padrão usada por funções membro do C\+\+ que não usam argumentos variáveis.  Sob `__thiscall`, o receptor limpa a pilha, o que é impossível para funções `vararg`.  Os argumentos são enviados por push na pilha da direita para a esquerda, com o ponteiro `this` passado por meio do registro de ECX, e não na pilha, na arquitetura x86.  
  
 Uma razão para usar `__thiscall` está em classes cujas funções membro usam `__clrcall` por padrão.  Nesse caso, você pode usar `__thiscall` para tornar funções membro individuais a partir de código nativo.  
  
 Ao compilar com [\/clr:pure](../build/reference/clr-common-language-runtime-compilation.md), todas as funções e ponteiros de função são `__clrcall`, exceto se especificada de outra forma.  
  
 Nas versões anteriores do Visual C\+\+ 2005, a convenção de chamada thiscall não podia ser especificada explicitamente em um programa, pois `thiscall` não era uma palavra\-chave.  
  
 As funções membro `vararg` usam a convenção de chamada `__cdecl`.  Todos os argumentos de função são enviadas por push na pilha, com o ponteiro `this` posicionado na última pilha  
  
 Como esta convenção de chamada se aplica apenas a C\+\+, não há nenhum esquema de decoração de nome de C.  
  
 Em computadores ARM e [!INCLUDE[vcprx64](../Token/vcprx64_md.md)], `__thiscall` é aceito e ignorado pelo compilador.  
  
 Para funções de classe não estáticas, se a função for definida como fora da linha, o modificador da convenção de chamada não precisa ser especificado na definição fora da linha.  Ou seja, para métodos de membro de classe não estática, a convenção de chamada especificada durante a declaração é assumida no ponto de definição.  
  
## Exemplo  
  
```  
// thiscall_cc.cpp  
// compile with: /c /clr:oldSyntax  
struct CMyClass {  
   void __thiscall mymethod();  
   void __clrcall mymethod2();  
};  
```  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Passagem de argumento e convenções de nomenclatura](../Topic/Argument%20Passing%20and%20Naming%20Conventions.md)