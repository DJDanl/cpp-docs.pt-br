---
title: Aviso LNK4254 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4254
dev_langs:
- C++
helpviewer_keywords:
- LNK4254
ms.assetid: 6f41dfb3-ca21-40d3-bac7-b637e578efa4
caps.latest.revision: 9
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
ms.openlocfilehash: e69e6808e17cd3694c8d075a4763d6b4689a0a76
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4254"></a>Aviso LNK4254 (Ferramentas de Vinculador)
a seção 'section1' (deslocamento) mesclados 'section2' (deslocamento) com diferentes atributos  
  
 O conteúdo de uma seção foram mesclado em outro, mas os atributos das duas seções são diferentes. Seu programa pode gerar resultados inesperados. Por exemplo, dados que você queria ser lidos somente podem ser agora em uma seção gravável.  
  
 Para resolver LNK4254, modificar ou remover a solicitação de mesclagem.  
  
 Ao direcionar x86 máquinas e destinos do Windows CE (ARM, MIPS, SH4 e Thumb) com o Visual C++, o. Seção de CRT é somente leitura. Se seu código depende do comportamento anterior (. Seções de CRT são leitura/gravação), você pode ver um comportamento inesperado.  
  
 Para obter mais informações, consulte  
  
-   [/Merge (combinar seções)](../../build/reference/merge-combine-sections.md)  
  
-   [comentário (C/C++)](../../preprocessor/comment-c-cpp.md)  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera LNK4254.  
  
```  
// LNK4254.cpp  
// compile with: /W1 /link /WX  
// LNK4254 expected  
#pragma comment(linker, "/merge:.data=.text")  
int main() {}  
```
