---
title: "bss_seg | Microsoft Docs"
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
  - "vc-pragma.bss_seg"
  - "bss_seg_CPP"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "bss_seg (pragma)"
  - "pragmas, bss_seg"
ms.assetid: 755f0154-de51-4778-97d3-c9b24e445079
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# bss_seg
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica o segmento em que as variáveis não inicializadas são armazenadas no arquivo .obj.  
  
## Sintaxe  
  
```  
  
#pragma bss_seg( [ [ { push | pop }, ] [ identifier, ] ] [ "segment-name" [, "segment-class" ] )  
```  
  
## Comentários  
 Os arquivos Obj podem ser exibidos com o aplicativo [dumpbin](../build/reference/dumpbin-command-line.md).  O segmento padrão no arquivo .obj para os dados não inicializados é .bss.  Em alguns casos, o uso de **bss\_seg** pode reduzir o tempo de carregamento, agrupando dados não inicializados em uma mesma seção.  
  
 **bss\_seg** sem parâmetros redefine o segmento como .bss.  
  
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
// pragma_directive_bss_seg.cpp  
int i;                     // stored in .bss  
#pragma bss_seg(".my_data1")  
int j;                     // stored in "my_data1"  
  
#pragma bss_seg(push, stack1, ".my_data2")     
int l;                     // stored in "my_data2"  
  
#pragma bss_seg(pop, stack1)   // pop stack1 from stack  
int m;                     // stored in "stack_data1"  
  
int main() {  
}  
```  
  
 Você também pode especificar seções para dados inicializados \([data\_seg](../preprocessor/data-seg.md)\), funções \([code\_seg](../preprocessor/code-seg.md)\) e variáveis const \([const\_seg](../preprocessor/const-seg.md)\).  
  
 Os dados alocados usando o pragma **bss\_seg** não retêm nenhuma informação sobre o respectivo local.  
  
 Consulte [\/SECTION](../build/reference/section-specify-section-attributes.md) para obter uma lista de nomes que você não deve usar ou criar uma seção.  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)