---
title: thiscall | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- __thiscall
- __thiscall_cpp
dev_langs:
- C++
helpviewer_keywords:
- __thiscall keyword [C++]
ms.assetid: a6a22dd2-0101-4885-b33b-22f6057965df
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a55f7d288758b345dfc4f182f2153e0d39a1b349
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="thiscall"></a>__thiscall
## <a name="microsoft-specific"></a>Específico da Microsoft  
 A convenção de chamada `__thiscall` é usada em funções membro e é a convenção de chamada padrão usada por funções membro do C++ que não usam argumentos variáveis. Sob `__thiscall`, o receptor limpa a pilha, o que é impossível para funções `vararg`. Os argumentos são enviados por push na pilha da direita para a esquerda, com o ponteiro `this` passado por meio do registro de ECX, e não na pilha, na arquitetura x86.  
  
 Uma razão para usar `__thiscall` está em classes cujas funções membro usam `__clrcall` por padrão. Nesse caso, você pode usar `__thiscall` para tornar funções membro individuais a partir de código nativo.  
  
 Ao compilar com [/clr: pure](../build/reference/clr-common-language-runtime-compilation.md), todas as funções e os ponteiros de função são `__clrcall` , a menos que especificado o contrário. As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015.  
  
 Nas versões anteriores do Visual C++ 2005, a convenção de chamada thiscall não podia ser especificada explicitamente em um programa, pois `thiscall` não era uma palavra-chave.  
  
 As funções membro `vararg` usam a convenção de chamada `__cdecl`. Todos os argumentos de função são enviadas por push na pilha, com o ponteiro `this` posicionado na última pilha  
  
 Como esta convenção de chamada se aplica apenas a C++, não há nenhum esquema de decoração de nome de C.  
  
 Em ARM e [!INCLUDE[vcprx64](../assembler/inline/includes/vcprx64_md.md)] máquinas, `__thiscall` é aceita e ignorado pelo compilador.  
  
 Para funções de classe não estáticas, se a função for definida como fora da linha, o modificador da convenção de chamada não precisará ser especificado na definição fora da linha. Ou seja, para métodos de membro de classe não estática, a convenção de chamada especificada durante a declaração é assumida no ponto de definição.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Convenções de passagem e nomenclatura de argumentos](../cpp/argument-passing-and-naming-conventions.md)