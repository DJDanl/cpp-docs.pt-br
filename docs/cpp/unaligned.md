---
title: unaligned | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- __unaligned_cpp
dev_langs:
- C++
helpviewer_keywords:
- __unaligned keyword [C++]
ms.assetid: 0cd83aad-1840-47e3-ad33-59bfcbe6375b
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 9f899add9a1306344a10840220f3b7504e917d91
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="unaligned"></a>__unaligned
Quando você declara um ponteiro com o modificador `__unaligned`, o compilador presume que o ponteiro aborda os dados que não são alinhados. Por isso, para um aplicativo cujo alvo é um computador da família de processadores Itanium (IPF), o compilador gera o código que lê os dados não alinhados um byte de cada vez.  
  
## <a name="remarks"></a>Comentários  
 O `__unaligned` modificador é válido para o [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)] e [!INCLUDE[vcpritanium](../cpp/includes/vcpritanium_md.md)] compiladores mas afeta somente aplicativos que se destinam a um computador IPF. Esse modificador descreve o alinhamento dos dados endereçados apenas; o ponteiro em si é considerado alinhado.  
  
 O [!INCLUDE[vcpritanium](../cpp/includes/vcpritanium_md.md)] processador gera uma falha de alinhamento quando ela acessa dados desalinhados, e o tempo para processar a falha enfraquece desempenho. Use o modificador `__unaligned` para fazer com que o processador leia os dados de um byte de cada vez e evite a falha. Esse modificador não é necessária para [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)] aplicativos porque o [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)] processador manipula dados desalinhados sem com falha.  
  
 Para obter mais informações sobre alinhamento, consulte:  
  
-   [align](../cpp/align-cpp.md)  
  
-   [Operador __alignof](../cpp/alignof-operator.md)  
  
-   [pack](../preprocessor/pack.md)  
  
-   [/ZP (alinhamento de membro de Struct)](../build/reference/zp-struct-member-alignment.md)  
  
-   [Exemplos de alinhamento da estrutura](../build/examples-of-structure-alignment.md)  
  
## <a name="example"></a>Exemplo  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)
