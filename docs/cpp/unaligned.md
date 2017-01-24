---
title: "__unaligned | Microsoft Docs"
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
  - "__unaligned_cpp"
  - "__unaligned"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __unaligned [C++]"
ms.assetid: 0cd83aad-1840-47e3-ad33-59bfcbe6375b
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# __unaligned
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você declara um ponteiro com o modificador `__unaligned`, o compilador presume que o ponteiro aborda os dados que não são alinhados.  Por isso, para um aplicativo cujo alvo é um computador da família de processadores Itanium \(IPF\), o compilador gera o código que lê os dados não alinhados um byte de cada vez.  
  
## Comentários  
 O modificador `__unaligned` é válido para os compiladores [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] e [!INCLUDE[vcpritanium](../Token/vcpritanium_md.md)], mas só afeta os aplicativos cujo alvo é um computador IPF.  Esse modificador descreve o alinhamento dos dados endereçados apenas; o ponteiro em si é considerado alinhado.  
  
 O processador [!INCLUDE[vcpritanium](../Token/vcpritanium_md.md)] gera uma falha de alinhamento quando acessa dados desalinhados, e o tempo de processamento da falha enfraquece o desempenho.  Use o modificador `__unaligned` para fazer com que o processador leia os dados de um byte de cada vez e evite a falha.  Esse modificador não é necessário para aplicativos do [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] porque o processador [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] trata dados desalinhados sem falhas.  
  
 Para obter mais informações sobre alinhamento, consulte:  
  
-   [align](../cpp/align-cpp.md)  
  
-   [Operador \_\_alignof](../cpp/alignof-operator.md)  
  
-   [pack](../preprocessor/pack.md)  
  
-   [\/Zp \(alinhamento de membro do Struct\)](../Topic/-Zp%20\(Struct%20Member%20Alignment\).md)  
  
-   [Exemplos de alinhamento da estrutura](../build/examples-of-structure-alignment.md)  
  
## Exemplo  
  
```  
// unaligned_keyword.cpp  
// compile with: /c  
// processor: x64 IPF  
#include <stdio.h>  
int main() {  
   char buf[100];  
  
   int __unaligned *p1 = (int*)(&buf[37]);  
   int *p2 = (int *)p1;  
  
   *p1 = 0;   // ok  
  
   __try {  
      *p2 = 0;  // throws an exception  
   }  
   __except(1) {  
      puts("exception");  
   }  
}  
```  
  
## Consulte também  
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)