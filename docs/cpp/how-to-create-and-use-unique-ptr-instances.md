---
title: "Como: criar e usar instâncias unique_ptr | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 9a373030-e587-452f-b9a5-c5f9d58b7673
caps.latest.revision: "16"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ae4610e7b26eecd6ef444f3c7c73e95af365ca71
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-create-and-use-uniqueptr-instances"></a>Como criar e usar instâncias unique_ptr
Um [unique_ptr](../standard-library/unique-ptr-class.md) não compartilha o ponteiro. Ele não pode ser copiado para outro `unique_ptr`, passado por valor para uma função ou usado em qualquer algoritmo de biblioteca padrão C++ que requer cópias a serem feitas. Um `unique_ptr` só pode ser movido. Isso significa que a propriedade do recurso de memória é transferida para outro `unique_ptr` e que o `unique_ptr` original não a possui mais. É recomendável que você restrinja um objeto a um proprietário, porque a propriedade múltipla adiciona complexidade à lógica do programa. Portanto, quando você precisar de um ponteiro inteligente para um objeto C++ simples, usar `unique_ptr`, e quando você cria um `unique_ptr`, use o [make_unique](../standard-library/memory-functions.md#make_unique) função auxiliar.  
  
 O diagrama a seguir ilustra a transferência de propriedade entre duas instâncias de `unique_ptr`.  
  
 ![Movendo a propriedade de uma única &#95; ptr](../cpp/media/unique_ptr.png "unique_ptr")  
  
 `unique_ptr`é definido no `<memory>` cabeçalho na biblioteca C++ padrão. É exatamente é eficiente como um ponteiro bruto e pode ser usada em contêineres de biblioteca padrão C++. A adição de `unique_ptr` instâncias aos contêineres de biblioteca padrão C++ é eficiente porque o construtor de movimento do `unique_ptr` elimina a necessidade de uma operação de cópia.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como criar instâncias de `unique_ptr` e passá-las entre as funções.  
  
 [!code-cpp[stl_smart_pointers#210](../cpp/codesnippet/CPP/how-to-create-and-use-unique-ptr-instances_1.cpp)]  
  
 Esses exemplos demonstram esta característica básica de `unique_ptr`: pode ser movido, mas não copiado. “Mover” transfere a propriedade a um novo `unique_ptr` e redefine o `unique_ptr` antigo.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como criar instâncias de `unique_ptr` e usá-las em um vetor.  
  
 [!code-cpp[stl_smart_pointers#211](../cpp/codesnippet/CPP/how-to-create-and-use-unique-ptr-instances_2.cpp)]  
  
 No intervalo do loop, observe que `unique_ptr` é passado por referência. Se você tentar passar por valor aqui, o compilador lançará um erro porque o construtor de cópia `unique_ptr` foi excluído.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como inicializar um `unique_ptr` que é membro da classe.  
  
 [!code-cpp[stl_smart_pointers#212](../cpp/codesnippet/CPP/how-to-create-and-use-unique-ptr-instances_3.cpp)]  
  
## <a name="example"></a>Exemplo  
 Você pode usar [make_unique](../standard-library/memory-functions.md#make_unique) para criar um `unique_ptr` em uma matriz, mas você não pode usar `make_unique` para inicializar os elementos da matriz.  
  
 [!code-cpp[stl_smart_pointers#213](../cpp/codesnippet/CPP/how-to-create-and-use-unique-ptr-instances_4.cpp)]  
  
 Para obter mais exemplos, consulte [make_unique](../standard-library/memory-functions.md#make_unique).  
  
## <a name="see-also"></a>Consulte também  
 [Ponteiros inteligentes](../cpp/smart-pointers-modern-cpp.md)   
 [make_unique](../standard-library/memory-functions.md#make_unique)