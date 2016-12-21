---
title: "const_seg | Microsoft Docs"
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
  - "vc-pragma.const_seg"
  - "const_seg_CPP"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "const_seg (pragma)"
  - "pragmas, const_seg"
ms.assetid: 1eb58ee2-fb0e-4a39-9621-699c8f5ef957
caps.latest.revision: 12
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# const_seg
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica o segmento em que as variáveis [const](../cpp/const-cpp.md) são armazenadas no arquivo .obj.  
  
## Sintaxe  
  
```  
#pragma const_seg ( [ [ { push | pop}, ] [ identifier, ] ] [ "segment-name" [, "segment-class" ] )  
```  
  
## Comentários  
 O significado dos termos *segmento* e *seção* são usados alternadamente neste tópico.  
  
 Os arquivos OBJ podem ser exibidos com o aplicativo [dumpbin](../build/reference/dumpbin-command-line.md).  O segmento padrão no arquivo. obj para `const` variáveis é RDATA.  Alguns `const` como escalares, as variáveis são embutidas automaticamente no fluxo de código.  O código embutido não aparecerá em .rdata.  
  
 Definindo um objeto que exigem a inicialização dinâmica em um `const_seg` resulta em um comportamento indefinido.  
  
 `#pragma const_seg` sem parâmetros redefine o segmento como RDATA.  
  
 `push` \(opcional\)  
 Coloca um registro na pilha interna do compilador.  Um `push` pode ter um `identifier` e `segment-name`.  
  
 `pop` \(opcional\)  
 Remove um registro do topo da pilha interna do compilador.  
  
 `identifier` \(opcional\)  
 Quando usado com `push`, atribui um nome ao registro na pilha interna do compilador.  Quando usado com `pop`, elimina registros da pilha interna até que `identifier` seja removido; se `identifier` não for localizado na pilha interna, nada será exibido.  
  
 Usando `identifier` habilita vários registros a serem exibidos com um único `pop` comando.  
  
 "`segment-name`" \(opcional\)  
 O nome de um segmento.  Quando usado com `pop`, a pilha é exibida e `segment-name` se torna o nome do segmento ativo.  
  
 "`segment-class`" \(opcional\)  
 Incluído para compatibilidade com o C\+\+ antes da versão 2.0.  É ignorado.  
  
## Exemplo  
  
```  
// pragma_directive_const_seg.cpp  
// compile with: /EHsc  
#include <iostream>  
  
const int i = 7;               // inlined, not stored in .rdata  
const char sz1[]= "test1";     // stored in .rdata  
  
#pragma const_seg(".my_data1")  
const char sz2[]= "test2";     // stored in .my_data1  
  
#pragma const_seg(push, stack1, ".my_data2")  
const char sz3[]= "test3";     // stored in .my_data2  
  
#pragma const_seg(pop, stack1) // pop stack1 from stack  
const char sz4[]= "test4";     // stored in .my_data1  
  
int main() {  
    using namespace std;  
   // const data must be referenced to be put in .obj  
   cout << sz1 << endl;  
   cout << sz2 << endl;  
   cout << sz3 << endl;  
   cout << sz4 << endl;  
}  
```  
  
  **test1**  
**test2**  
**test3**  
**test4**   
## Comentários  
 Consulte [\/SECTION](../build/reference/section-specify-section-attributes.md) para obter uma lista de nomes que você não deve usar ou criar uma seção.  
  
 Você também pode especificar seções para dados inicializados \([data\_seg](../preprocessor/data-seg.md)\), dados não inicializados \([bss\_seg](../preprocessor/bss-seg.md)\) e funções \([code\_seg](../preprocessor/code-seg.md)\).  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)