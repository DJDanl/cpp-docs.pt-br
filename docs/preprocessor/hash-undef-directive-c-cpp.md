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
ms.openlocfilehash: c98c6559e04f0e89fa4c3501f30cd88d449de306
ms.sourcegitcommit: d4c803bd3a684d7951bf88dcecf1f14af43ae411
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/10/2018
ms.locfileid: "42538570"
---
# <a name="undef-directive-cc"></a>Diretiva #undef (C/C++)
Remove (não define) um nome criado anteriormente com `#define`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#undef   
identifier  
```  
  
## <a name="remarks"></a>Comentários 

O **#undef** diretiva remove a definição atual do *identificador*. Consequentemente, ocorrências subsequentes do *identificador* são ignoradas pelo pré-processador. Para remover uma definição de macro usando **#undef**, dê apenas a macro *identificador* ; não forneça uma lista de parâmetros.  
  
Você também pode aplicar a **#undef** diretiva para um identificador que não possui nenhuma definição anterior. Isso garante que o identificador seja indefinido. Substituição de macro não é executada nas **#undef** instruções.  
  
O **#undef** diretiva geralmente é emparelhada com um `#define` diretiva para criar uma região em um programa de origem no qual um identificador tem um significado especial. Por exemplo, uma função específica do programa de origem pode usar constantes manifestas para definir os valores específicos que não afetam o restante do programa. O **#undef** diretiva também funciona com o `#if` diretiva para controlar a compilação condicional do programa de origem. Ver [o #if, #elif, #else e # #endif](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md) para obter mais informações.  
  
No exemplo a seguir, o **#undef** diretiva remove as definições de uma constante simbólica e uma macro. Somente o identificador de macro será fornecido.  
  
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
  
As macros podem ser definidas a partir da linha de comando usando o `/U` opção, seguida pelos nomes de macro a serem definidos. O efeito de emitir esse comando é equivalente a uma sequência de `#undef` *nome da macro* instruções no início do arquivo.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 
[Diretivas do pré-processador](../preprocessor/preprocessor-directives.md)