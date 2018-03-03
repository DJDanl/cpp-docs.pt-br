---
title: Aviso LNK4254 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4254
dev_langs:
- C++
helpviewer_keywords:
- LNK4254
ms.assetid: 6f41dfb3-ca21-40d3-bac7-b637e578efa4
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e17bcd03f92114c1b7cd21e63220cf6372c17bf2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-warning-lnk4254"></a>Aviso LNK4254 (Ferramentas de Vinculador)
a seção 'Seção1' (deslocamento) mesclado 'Seção2' (deslocamento) com diferentes atributos  
  
 O conteúdo de uma seção foram mesclado no outro, mas os atributos das duas seções são diferentes. Seu programa pode gerar resultados inesperados. Por exemplo, dados que você queria ser lidos somente podem agora ser em uma seção gravável.  
  
 Para resolver LNK4254, modificar ou remover a solicitação de mesclagem.  
  
 Durante o direcionamento x86 máquinas e destinos do Windows CE (ARM, MIPS, SH4 e Thumb) com o Visual C++, o. Seção de CRT é somente leitura. Se seu código depende do comportamento anterior (. Seções de CRT são somente leitura), você pode ver um comportamento inesperado.  
  
 Para obter mais informações, consulte  
  
-   [/Merge (combinar seções)](../../build/reference/merge-combine-sections.md)  
  
-   [comment (C/C++)](../../preprocessor/comment-c-cpp.md)  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera LNK4254.  
  
```  
// LNK4254.cpp  
// compile with: /W1 /link /WX  
// LNK4254 expected  
#pragma comment(linker, "/merge:.data=.text")  
int main() {}  
```