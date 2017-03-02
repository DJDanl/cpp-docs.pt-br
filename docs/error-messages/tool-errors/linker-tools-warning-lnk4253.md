---
title: Aviso LNK4253 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4253
dev_langs:
- C++
helpviewer_keywords:
- LNK4253
ms.assetid: ec7433a9-aa9c-495a-a9f2-075e7bc3e7bc
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 7a8500b427a9e6aa57bf12f0ecda9afaee8aadd1
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4253"></a>Aviso LNK4253 (Ferramentas de Vinculador)
seção 'section1' não são mesclados em 'section2'; já mesclados 'Remoções3'  
  
 Mesclar conflitante o vinculador detectou várias solicitações. O vinculador irá ignorar uma das solicitações.  
  
 A **/mesclar** opção ou diretiva é encontrada e o `from` seção já foram mesclada em uma seção diferente devido a uma anterior **/mesclar** opção ou diretiva (ou devido a uma mesclagem implícita do vinculador).  
  
 Para resolver LNK4253, remova uma das solicitações de mesclagem.  
  
 Ao direcionar x86 máquinas e destinos do Windows CE (ARM, MIPS, SH4 e Thumb) com o Visual C++, o. Seção de CRT agora é somente leitura. Se seu código depende do comportamento anterior (. Seções de CRT são leitura/gravação), você pode ver um comportamento inesperado.  
  
 Para obter mais informações, consulte  
  
-   [/Merge (combinar seções)](../../build/reference/merge-combine-sections.md)  
  
-   [comentário (C/C++)](../../preprocessor/comment-c-cpp.md)  
  
## <a name="example"></a>Exemplo  
 No exemplo a seguir, o vinculador é instruído para mesclar o `.rdata` seção duas vezes, mas em diferentes seções. O exemplo a seguir gera LNK4253.  
  
```  
// LNK4253.cpp  
// compile with: /W1 /link /merge:.rdata=text2  
// LNK4253 expected  
#pragma comment(linker, "/merge:.rdata=.text")  
int main() {}  
```
