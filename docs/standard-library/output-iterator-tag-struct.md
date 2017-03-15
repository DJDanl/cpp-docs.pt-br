---
title: Struct output_iterator_tag | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- std::output_iterator_tag
- output_iterator_tag
- xutility/std::output_iterator_tag
- std.output_iterator_tag
dev_langs:
- C++
helpviewer_keywords:
- output_iterator_tag class
- output_iterator_tag struct
ms.assetid: c23a4331-b069-4fa0-9c3a-1c9be7095553
caps.latest.revision: 19
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
ms.sourcegitcommit: 2d05749ba2837a3879c91886b9266de47dd2ece6
ms.openlocfilehash: a0376983916f511bec198a4b5d7d9e7131ae25b6
ms.lasthandoff: 02/25/2017

---
# <a name="outputiteratortag-struct"></a>Struct output_iterator_tag
Uma classe que fornece um tipo de retorno para a função **iterator_category**, que representa um iterador de saída.  
  
## <a name="syntax"></a>Sintaxe  
  
struct output_iterator_tag {};  
  
## <a name="remarks"></a>Comentários  
 As classes de marca de categoria são usadas como marcas de compilação para seleção de algoritmos. A função de modelo precisa encontrar a categoria mais específica do argumento iterador para que ela possa usar o algoritmo mais eficiente em tempo de compilação. Para cada iterador do tipo `Iterator`, `iterator_traits`< `Iterator`> **::iterator_category** deve ser definido para ser a marca de categoria mais específica que descreve o comportamento do iterador.  
  
 O tipo é o mesmo que **iterator**\< **Iter**> **::iterator_category** quando **Iter** descreve um objeto que pode servir como um iterador de saída.  
  
 Essa marca não é parametrizada no `value_type` ou `difference_type` para o iterador, assim como acontece com as outras marcas de iterador, porque os iteradores de saída não tem um `value_type` ou `difference_type`.  
  
## <a name="example"></a>Exemplo  
 Consulte [iterator_traits](../standard-library/iterator-traits-struct.md) ou [random_access_iterator_tag](../standard-library/random-access-iterator-tag-struct.md) para ver um exemplo de como usar **iterator_tag**s.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<iterator>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)




