---
title: Aviso LNK4253 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK4253
dev_langs: C++
helpviewer_keywords: LNK4253
ms.assetid: ec7433a9-aa9c-495a-a9f2-075e7bc3e7bc
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: fe7e60c3066e2981f1b826381691950b2ccd46d3
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="linker-tools-warning-lnk4253"></a>Aviso LNK4253 (Ferramentas de Vinculador)
seção 'Seção1' não foram mesclados no 'Seção2'; já foi mesclado em 'Remoções3'  
  
 O vinculador detectou vários solicitações de mesclagem conflitante. O vinculador vai ignorar uma das solicitações.  
  
 Um **/mesclagem** opção ou diretiva for encontrada e o `from` seção já foi mesclada em outra seção devido a um anterior **/mesclagem** opção ou diretiva (ou devido a uma mesclagem implícita de o vinculador).  
  
 Para resolver LNK4253, remova uma das solicitações de mesclagem.  
  
 Durante o direcionamento x86 máquinas e destinos do Windows CE (ARM, MIPS, SH4 e Thumb) com o Visual C++, o. Seção de CRT agora é somente leitura. Se seu código depende do comportamento anterior (. Seções de CRT são somente leitura), você pode ver um comportamento inesperado.  
  
 Para obter mais informações, consulte  
  
-   [/Merge (combinar seções)](../../build/reference/merge-combine-sections.md)  
  
-   [comment (C/C++)](../../preprocessor/comment-c-cpp.md)  
  
## <a name="example"></a>Exemplo  
 No exemplo a seguir, o vinculador é instruído para mesclar o `.rdata` seção duas vezes, mas em diferentes seções. O exemplo a seguir gera LNK4253.  
  
```  
// LNK4253.cpp  
// compile with: /W1 /link /merge:.rdata=text2  
// LNK4253 expected  
#pragma comment(linker, "/merge:.rdata=.text")  
int main() {}  
```