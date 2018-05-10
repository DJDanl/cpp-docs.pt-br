---
title: '#undef (C/C++) de diretiva | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- '#undef'
dev_langs:
- C++
helpviewer_keywords:
- '#undef directive'
- undef directive (#undef)
- preprocessor, directives
ms.assetid: 88900e0e-2c19-4a63-b681-f3d3133c24ca
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 16b8c937ad62ddc6738c626543dab2d4e5453bc5
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="undef-directive-cc"></a>Diretiva #undef (C/C++)
Remove (não define) um nome criado anteriormente com `#define`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#undef   
identifier  
  
```  
  
## <a name="remarks"></a>Comentários  
 O `#undef` diretiva remove a definição atual do *identificador*. Consequentemente, ocorrências subsequentes do *identificador* são ignorados pelo pré-processador. Para remover uma definição de macro usando `#undef`, dê somente a macro *identificador* ; não fornecer uma lista de parâmetros.  
  
 Você também pode aplicar a política de `#undef` a um identificador que não tem nenhuma definição anterior. Isso garante que o identificador seja indefinido. A substituição da macro não é executada nas instruções de `#undef`.  
  
 A política de `#undef` é emparelhada normalmente com uma política de `#define` para criar uma região em um programa de origem no qual um identificador tem um significado especial. Por exemplo, uma função específica do programa de origem pode usar constantes manifestas para definir os valores específicos que não afetam o restante do programa. A política de `#undef` também funciona com a política de `#if` para controlar a compilação condicional do programa de origem. Consulte [a #if, #elif, #else e # #endif](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md) para obter mais informações.  
  
 No exemplo a seguir, a política de `#undef` remove as definições de uma constante de token e de uma macro. Somente o identificador de macro será fornecido.  
  
```  
#define WIDTH 80  
#define ADD( X, Y ) ((X) + (Y))  
.  
.  
.  
#undef WIDTH  
#undef ADD  
```  
  
 **Seção específica da Microsoft**  
  
 Macros podem ser definidas a partir da linha de comando usando a opção /U, seguida dos nomes de macros a serem definidos. O efeito de emitir esse comando é equivalente a uma sequência de `#undef` *nome de macro* instruções no início do arquivo.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas do pré-processador](../preprocessor/preprocessor-directives.md)