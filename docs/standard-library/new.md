---
title: '&lt;new&gt; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- std::<new>
- <new>
- std.<new>
dev_langs:
- C++
helpviewer_keywords:
- new header
ms.assetid: 218e2a15-34e8-4ef3-9122-1e90eccf8559
caps.latest.revision: 18
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 66798adc96121837b4ac2dd238b9887d3c5b7eef
ms.openlocfilehash: e804f35db459c7fe50bb36fa8eeaf795d04cc621
ms.contentlocale: pt-br
ms.lasthandoff: 04/29/2017

---
# <a name="ltnewgt"></a>&lt;new&gt;
Define vários tipos e funções que controlam a alocação e a liberação de armazenamento no controle do programa. Ele também define componentes para relatórios de erros de gerenciamento de armazenamento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <new>  
  
```  
  
## <a name="remarks"></a>Comentários  
 Algumas das funções declaradas nesse cabeçalho são substituíveis. A implementação fornece uma versão padrão, cujo comportamento é descrito neste documento. Um programa pode, no entanto, definir uma função com a mesma assinatura para substituir a versão padrão em tempo de vinculação. A versão de substituição deve satisfazer os requisitos descritos neste documento.  
  
### <a name="objects"></a>Objetos  
  
|||  
|-|-|  
|[nothrow](../standard-library/new-functions.md#nothrow)|Fornece um objeto a ser usado como um argumento para as versões `nothrow` de **new** e **delete**.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[new_handler](../standard-library/new-typedefs.md#new_handler)|Um tipo aponta para uma função adequada para uso como um manipulador new.|  
  
### <a name="functions"></a>Funções  
  
|||  
|-|-|  
|[set_new_handler](../standard-library/new-functions.md#set_new_handler)|Instala uma função de usuário que deve ser chamada quando new falhar ao tentar alocar memória.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operador delete](../standard-library/new-operators.md#op_delete)|A função que é chamada por uma expressão delete para desalocar o armazenamento de objetos individuais.|  
|[operador delete&#91;&#93;](../standard-library/new-operators.md#op_delete_arr)|A função que é chamada por uma expressão delete para desalocar o armazenamento para uma matriz de objetos.|  
|[operador new](../standard-library/new-operators.md#op_new)|A função que é chamada por uma expressão new para alocar o armazenamento de objetos individuais.|  
|[operador new&#91;&#93;](../standard-library/new-operators.md#op_new_arr)|A função que é chamada por uma expressão new para alocar o armazenamento de uma matriz de objetos.|  
  
### <a name="classes"></a>Classes  
  
|||  
|-|-|  
|[Classe bad_alloc](../standard-library/bad-alloc-class.md)|A classe descreve uma exceção gerada para indicar que uma solicitação de alocação não teve êxito.|  
|[Classe nothrow_t](../standard-library/nothrow-t-structure.md)|A classe é usada como um parâmetro de função para o operador new para indicar que a função deve retornar um ponteiro nulo para relatar uma falha de alocação, em vez de lançar uma exceção.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)




