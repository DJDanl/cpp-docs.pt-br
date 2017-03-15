---
title: '&lt;iomanip&gt; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- iomanip/std::<iomanip>
- std::<iomanip>
- <iomanip>
- std.<iomanip>
dev_langs:
- C++
helpviewer_keywords:
- iomanip header
ms.assetid: 3681c346-4763-4037-bba4-cf0dc3447974
caps.latest.revision: 21
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
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
ms.openlocfilehash: 71c6a6f3d9c8c256628f609c6a3e65f6b72df952
ms.lasthandoff: 02/25/2017

---
# <a name="ltiomanipgt"></a>&lt;iomanip&gt;
Inclua o cabeçalho padrão `<iomanip>` de `iostreams` para definir vários manipuladores que usam um único argumento cada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <iomanip>  
  
```  
  
## <a name="remarks"></a>Comentários  
 Cada um desses manipuladores retorna um tipo não especificado, chamado de **T1** a **T10**, que sobrecarrega `basic_istream`\<**Elem**, **Tr**>`::`[operator>>](../standard-library/istream-operators.md#operator_gt__gt_) e `basic_ostream`\<**Elem**, **Tr**>`::`[operator<<](../standard-library/ostream-operators.md#operator_lt__lt_).  
  
### <a name="manipulators"></a>Manipuladores  
  
|||  
|-|-|  
|[get_money](../standard-library/iomanip-functions.md#iomanip_get_money)|Obtém um valor monetário, que pode estar no formato internacional.|  
|[get_time](../standard-library/iomanip-functions.md#iomanip_get_time)|Obtém uma hora em uma estrutura de horas usando um formato especificado.|  
|[put_money](../standard-library/iomanip-functions.md#iomanip_put_money)|Fornece um valor monetário, que pode estar no formato internacional.|  
|[put_time](../standard-library/iomanip-functions.md#iomanip_put_time)|Fornece uma hora em uma estrutura de horas e uma cadeia de caracteres de formato para ser usada.|  
|[quoted](../standard-library/iomanip-functions.md#quoted)|Permite o ciclo conveniente de cadeias de caracteres, com operadores de inserção e extração.|  
|[resetiosflags](../standard-library/iomanip-functions.md#resetiosflags)|Limpa os sinalizadores especificados.|  
|[setbase](../standard-library/iomanip-functions.md#setbase)|Define a base para inteiros.|  
|[setfill](../standard-library/iomanip-functions.md#setfill)|Define o caractere que será usado para preencher espaços em uma exibição justificada à direita.|  
|[setiosflags](../standard-library/iomanip-functions.md#setiosflags)|Define os sinalizadores especificados.|  
|[setprecision](../standard-library/iomanip-functions.md#setprecision)|Define a precisão dos valores de ponto flutuante.|  
|[setw](../standard-library/iomanip-functions.md#setw)|Especifica a largura do campo de exibição.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação de iostream](../standard-library/iostream-programming.md)   
 [Convenções de iostreams](../standard-library/iostreams-conventions.md)




