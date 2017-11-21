---
title: Struct iterator | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: xutility/std::iterator
dev_langs: C++
helpviewer_keywords:
- iterator class
- iterator struct
ms.assetid: c74c8000-8b18-4829-9b71-6103c4229b74
caps.latest.revision: "18"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: abcafb8f94265d14a609481a187dcc53267718d3
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="iterator-struct"></a>Struct iterator
Um struct de base vazio usado para garantir que uma classe de iterador definida pelo usuário funcione corretamente com **iterator_trait**s.  
  
## <a name="syntax"></a>Sintaxe  
```    
struct iterator {
   typedef Category iterator_category;
   typedef Type value_type;
   typedef Distance difference_type;
   typedef Distance distance_type;
   typedef Pointer pointer;
   typedef Reference reference;
   };  
```    
## <a name="remarks"></a>Comentários  
 O struct de modelo atua como um tipo base para todos os iteradores. Ele define os tipos de membro  
  
- `iterator_category` (um sinônimo do parâmetro de modelo `Category`).  
  
- `value_type` (um sinônimo do parâmetro de modelo **Type**).  
  
- `difference_type` (um sinônimo do parâmetro de modelo `Distance`).  
  
- `distance_type` (um sinônimo do parâmetro de modelo `Distance`)  
  
- `pointer` (um sinônimo do parâmetro de modelo `Pointer`).  
  
- `reference` (um sinônimo do parâmetro de modelo `Reference`).  
  
 Observe que `value_type` não deve um tipo constante mesmo que o **ponteiro** aponte para um objeto de **Tipo** const e a referência designe um objeto de **Tipo** const.  
  
## <a name="example"></a>Exemplo  
 Consulte [iterator_traits](../standard-library/iterator-traits-struct.md) para ver um exemplo de como declarar e usar os tipos na classe base do iterador.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<iterator>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [\<iterator>](../standard-library/iterator.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)



