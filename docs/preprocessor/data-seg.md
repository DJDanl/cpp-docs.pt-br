---
title: "data_seg | Microsoft Docs"
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
  - "data_seg_CPP"
  - "vc-pragma.data_seg"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "data_seg (pragma)"
  - "pragmas, data_seg"
ms.assetid: 65c66466-4c98-494f-93af-106beb4caf78
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# data_seg
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica o segmento de dados em que as variáveis inicializadas são armazenadas no arquivo .obj.  
  
## Sintaxe  
  
```  
  
#pragma data_seg( [ [ { push | pop }, ] [ identifier, ] ] [ "segment-name" [, "segment-class" ] )  
```  
  
## Comentários  
 O significado dos termos *segmento* e *seção* são usados alternadamente neste tópico.  
  
 Os arquivos OBJ podem ser exibidos com o aplicativo [dumpbin](../build/reference/dumpbin-command-line.md).  O segmento padrão no arquivo .obj para as variáveis inicializadas é .data.  As variáveis que são não inicializadas são consideradas inicializadas em zero e são armazenadas em .bss.  
  
 **data\_seg** sem parâmetros redefine o segmento como .data.  
  
 **push** \(opcional\)  
 Coloca um registro na pilha interna do compilador.  **push** pode ter um elemento *identifier* e *segment\-name*.  
  
 **pop** \(opcional\)  
 Remove um registro do topo da pilha interna do compilador.  
  
 *identifier* \(opcional\)  
 Quando usado com **push**, atribui um nome ao registro na pilha interna do compilador.  Quando usado com **pop**, elimina registros da pilha interna até que *identifier* seja removido; se *identifier* não for localizado na pilha interna, nada será exibido.  
  
 *identifier* habilita vários registros a serem removidos com um único comando **pop** .  
  
 *"segment\-name"*\(opcional\)  
 O nome de um segmento*.* Quando usado com **pop**, a pilha é exibida e *segment\-name* torna\-se o nome do segmento ativo.  
  
 *"segment\-class"* \(opcional\)  
 Incluído para compatibilidade com o C\+\+ antes da versão 2.0.  É ignorado.  
  
## Exemplo  
  
```  
// pragma_directive_data_seg.cpp  
int h = 1;                     // stored in .data  
int i = 0;                     // stored in .bss  
#pragma data_seg(".my_data1")  
int j = 1;                     // stored in "my_data1"  
  
#pragma data_seg(push, stack1, ".my_data2")     
int l = 2;                     // stored in "my_data2"  
  
#pragma data_seg(pop, stack1)   // pop stack1 off the stack  
int m = 3;                     // stored in "stack_data1"  
  
int main() {  
}  
```  
  
 Os dados alocados com **data\_seg** não retêm nenhuma informação sobre o respectivo local.  
  
 Consulte [\/SECTION](../build/reference/section-specify-section-attributes.md) para obter uma lista de nomes que você não deve usar ou criar uma seção.  
  
 Você também pode especificar seções para variáveis const \([const\_seg](../preprocessor/const-seg.md)\), dados não inicializados \([bss\_seg](../preprocessor/bss-seg.md)\) e funções \([code\_seg](../preprocessor/code-seg.md)\).  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)