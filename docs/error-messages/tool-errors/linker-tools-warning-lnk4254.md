---
title: Aviso LNK4254 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4254
dev_langs:
- C++
helpviewer_keywords:
- LNK4254
ms.assetid: 6f41dfb3-ca21-40d3-bac7-b637e578efa4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: eb57882ab4269c06a53ed73fed2a9d6caf2f2c85
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-warning-lnk4254"></a>Aviso LNK4254 (Ferramentas de Vinculador)
a seção 'Seção1' (deslocamento) mesclado 'Seção2' (deslocamento) com diferentes atributos  
  
 O conteúdo de uma seção foram mesclado no outro, mas os atributos das duas seções são diferentes. Seu programa pode gerar resultados inesperados. Por exemplo, dados que você queria ser lidos somente podem agora ser em uma seção gravável.  
  
 Para resolver LNK4254, modificar ou remover a solicitação de mesclagem.  
  
 Durante o direcionamento x86 máquinas e destinos do Windows CE (ARM, MIPS, SH4 e Thumb) com o Visual C++, o. Seção de CRT é somente leitura. Se seu código depende do comportamento anterior (. Seções de CRT são somente leitura), você pode ver um comportamento inesperado.  
  
 Para obter mais informações, consulte  
  
-   [/MERGE (combinar seções)](../../build/reference/merge-combine-sections.md)  
  
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