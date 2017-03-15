---
title: "Como criar e usar inst&#226;ncias unique_ptr | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 9a373030-e587-452f-b9a5-c5f9d58b7673
caps.latest.revision: 16
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como criar e usar inst&#226;ncias unique_ptr
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um [unique\_ptr](../standard-library/unique-ptr-class.md) não compartilha seu ponteiro.  Não pode ser copiado para outro `unique_ptr`, passado por valor para uma função, nem usado em qualquer algoritmo STL que exija que cópias sejam feitas.  Um `unique_ptr` só pode ser movido.  Isso significa que a propriedade do recurso de memória é transferida para outro `unique_ptr` e que o `unique_ptr` original não a possui mais.  É recomendável que você restrinja um objeto a um proprietário, porque a propriedade múltipla adiciona complexidade à lógica do programa.  Portanto, quando você precisa de um ponteiro inteligente para um objeto C\+\+ simples, use `unique_ptr`, e quando você construir um `unique_ptr`, use a função auxiliar [make\_unique](../Topic/make_unique.md).  
  
 O diagrama a seguir ilustra a transferência de propriedade entre duas instâncias de `unique_ptr`.  
  
 ![Mudança de propriedade de um unique&#95;ptr](../cpp/media/unique_ptr.png "unique\_ptr")  
  
 `unique_ptr` é definido no cabeçalho `<memory>` no STL.  É exatamente tão eficiente quanto um ponteiro bruto e pode ser usado em contêineres STL.  A adição de instâncias de `unique_ptr` a contêineres STL é eficiente porque o construtor de movimentação do `unique_ptr` elimina a necessidade da operação de cópia.  
  
## Exemplo  
 O exemplo a seguir mostra como criar instâncias de `unique_ptr` e passá\-las entre as funções.  
  
 [!code-cpp[stl_smart_pointers#210](../cpp/codesnippet/CPP/how-to-create-and-use-unique-ptr-instances_1.cpp)]  
  
 Esses exemplos demonstram esta característica básica de `unique_ptr`: pode ser movido, mas não copiado. “Mover” transfere a propriedade a um novo `unique_ptr` e redefine o `unique_ptr` antigo.  
  
## Exemplo  
 O exemplo a seguir mostra como criar instâncias de `unique_ptr` e usá\-las em um vetor.  
  
 [!code-cpp[stl_smart_pointers#211](../cpp/codesnippet/CPP/how-to-create-and-use-unique-ptr-instances_2.cpp)]  
  
 No intervalo do loop, observe que `unique_ptr` é passado por referência.  Se você tentar passar por valor aqui, o compilador lançará um erro porque o construtor de cópia `unique_ptr` foi excluído.  
  
## Exemplo  
 O exemplo a seguir mostra como inicializar um `unique_ptr` que é membro da classe.  
  
 [!code-cpp[stl_smart_pointers#212](../cpp/codesnippet/CPP/how-to-create-and-use-unique-ptr-instances_3.cpp)]  
  
## Exemplo  
 Você pode usar [make\_unique](../Topic/make_unique.md) para criar um `unique_ptr` para uma matriz, mas não pode usar `make_unique` para inicializar os elementos da matriz.  
  
 [!code-cpp[stl_smart_pointers#213](../cpp/codesnippet/CPP/how-to-create-and-use-unique-ptr-instances_4.cpp)]  
  
 Para obter mais exemplos, consulte [make\_unique](../Topic/make_unique.md).  
  
## Consulte também  
 [Ponteiros inteligentes](../cpp/smart-pointers-modern-cpp.md)   
 [make\_unique](../Topic/make_unique.md)