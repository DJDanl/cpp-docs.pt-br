---
title: '&lt;typeindex&gt; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- <typeindex>
dev_langs:
- C++
ms.assetid: a9551137-f74b-4f02-af64-ff00214cea1f
caps.latest.revision: 14
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
ms.sourcegitcommit: 2d05749ba2837a3879c91886b9266de47dd2ece6
ms.openlocfilehash: 4279c10994de9247819e58a06276ef9690b39bb8
ms.lasthandoff: 02/25/2017

---
# <a name="lttypeindexgt"></a>&lt;typeindex&gt;
Inclua o cabeçalho padrão \<typeindex> para definir uma classe e a função que dê suporte a indexação dos objetos da classe [type_info](../cpp/type-info-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
#include <typeindex>  
```  
  
## <a name="remarks"></a>Comentários  
 A [estrutura hash](../standard-library/hash-structure.md) define um `hash function` adequado para mapeamentos de valor do tipo [type_index](../standard-library/type-index-class.md) para uma distribuição de valores de índice.  
  
 A classe `type_index` encapsula um ponteiro para um objeto `type_info` a fim de auxiliar na indexação.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)




