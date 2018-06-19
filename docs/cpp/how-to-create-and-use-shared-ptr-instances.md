---
title: 'Como: criar e usar instâncias shared_ptr | Microsoft Docs'
ms.custom: how-to
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 7d6ebb73-fa0d-4b0b-a528-bf05de96518e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1a2aad184a1f388df6f7a6941aa9e5f302f35b12
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32418354"
---
# <a name="how-to-create-and-use-sharedptr-instances"></a>Como criar e usar instâncias shared_ptr
O `shared_ptr` tipo é um ponteiro inteligente na biblioteca padrão C++ que se destina a cenários em que mais de um proprietário pode ter que gerenciar o tempo de vida do objeto na memória. Depois de inicializar um `shared_ptr` copiá-lo, passá-lo pelo valor em argumentos de função e atribuí-la a outro `shared_ptr` instâncias. Todas as instâncias de apontar para o mesmo objeto e compartilhe o acesso para um "bloco de controle" que aumenta e diminui a contagem de referência sempre que um novo `shared_ptr` é adicionado, sai do escopo ou é redefinido. Quando a contagem de referência chega a zero, o bloco de controle exclui o recurso de memória e em si.  
  
 A ilustração a seguir mostra vários `shared_ptr` instâncias que apontam para um local de memória.  
  
 [![Ponteiro compartilhado](../cpp/media/shared_ptr.png "shared_ptr")](assetId:///9785ad08-31d8-411a-86a9-fb9cd9684c27)  
  
## <a name="example"></a>Exemplo  
 Sempre que possível, use o [make_shared](../standard-library/memory-functions.md#make_shared) função para criar um `shared_ptr` quando o recurso de memória é criado pela primeira vez. `make_shared` é seguro de exceção. Ele usa a mesma chamada para alocar a memória para o bloco de controle e o recurso e, portanto, reduz a sobrecarga de construção. Se você não usar `make_shared`, em seguida, você deve usar uma expressão explícita de novo para criar o objeto antes de transmiti-lo para o `shared_ptr` construtor. O exemplo a seguir mostra várias maneiras de declarar e inicializar uma `shared_ptr` junto com um novo objeto.  
  
 [!code-cpp[stl_smart_pointers#1](../cpp/codesnippet/CPP/how-to-create-and-use-shared-ptr-instances_1.cpp)]  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como declarar e inicializar `shared_ptr` instâncias assumir compartilhado proprietário de um objeto que já foi alocado por outro `shared_ptr`. Suponha que `sp2` é uma inicializado `shared_ptr`.  
  
 [!code-cpp[stl_smart_pointers#2](../cpp/codesnippet/CPP/how-to-create-and-use-shared-ptr-instances_2.cpp)]  
  
## <a name="example"></a>Exemplo  
 `shared_ptr` também é útil em contêineres de biblioteca padrão C++ quando você estiver usando algoritmos que copiar elementos. Você pode encapsular os elementos em um `shared_ptr`e, em seguida, copie-o em outros contêineres com o entendimento de que a memória subjacente é válido desde que você precisa e não está mais. O exemplo a seguir mostra como usar o `replace_copy_if` algoritmo em `shared_ptr` instâncias em um objeto vector.  
  
 [!code-cpp[stl_smart_pointers#4](../cpp/codesnippet/CPP/how-to-create-and-use-shared-ptr-instances_3.cpp)]  
  
## <a name="example"></a>Exemplo  
 Você pode usar `dynamic_pointer_cast`, `static_pointer_cast`, e `const_pointer_cast` para converter um `shared_ptr`. Essas funções são semelhantes a `dynamic_cast`, `static_cast`, e `const_cast` operadores. O exemplo a seguir mostra como testar o tipo derivado de cada elemento em um vetor de `shared_ptr` de classes de base e, em seguida, copiar os elementos e exibir informações sobre eles.  
  
 [!code-cpp[stl_smart_pointers#5](../cpp/codesnippet/CPP/how-to-create-and-use-shared-ptr-instances_4.cpp)]  
  
## <a name="example"></a>Exemplo  
 Você pode passar um `shared_ptr` para outra função das seguintes maneiras:  
  
-   Passar o `shared_ptr` por valor. Isso chama o construtor de cópia, incrementa a contagem de referência e faz o receptor um proprietário. Há uma pequena quantidade de sobrecarga nesta operação, que pode ser significativo dependendo de quantos `shared_ptr` objetos estão sendo transmitidos. Use essa opção quando o contrato de código (implícito ou explícito) entre o receptor e o chamador requer que o destinatário seja um proprietário.  
  
-   Passar o `shared_ptr` por referência ou const. Nesse caso, a contagem de referência não é incrementada e o receptor pode acessar o ponteiro como o chamador não estar fora do escopo. Ou, o receptor pode optar por criar um `shared_ptr` com base na referência e, portanto, se tornar um proprietário compartilhado. Use esta opção quando o chamador não tem conhecimento sobre o receptor, ou quando você deve passar um `shared_ptr` e para evitar a operação de cópia por motivos de desempenho.  
  
-   Passe o ponteiro subjacente ou uma referência ao objeto subjacente. Isso permite que o receptor usar o objeto, mas não habilitá-lo para compartilhar a propriedade ou estender a vida útil. Se o receptor cria um `shared_ptr` de ponteiro bruto, o novo `shared_ptr` é independente do original e não controla os recursos subjacentes. Use essa opção quando o contrato entre o chamador e o receptor claramente Especifica que o chamador reterá a propriedade do `shared_ptr` tempo de vida.  
  
-   Ao decidir como passar um `shared_ptr`, determinar se o receptor deve compartilhar a propriedade do recurso subjacente. Um "proprietário" é um objeto ou função que pode manter o recurso subjacente ativos para, contanto que for necessário. Se o chamador garantir que o receptor pode estender a vida útil do ponteiro além de seu tempo de vida (da função), use a primeira opção. Se você não importa se o receptor estende o tempo de vida, passada por referência e permitem que o receptor copiá-lo ou não.  
  
-   Se você precisar conceder um acesso da função auxiliar para o ponteiro subjacente e você sabe que a função auxiliar apenas será usar o ponteiro e retornar antes da função retorna a chamada, em seguida, essa função não tem que compartilhar a propriedade do ponteiro subjacente. Ele apenas precisa acessar o ponteiro dentro do tempo de vida do chamador `shared_ptr`. Nesse caso, é seguro passar o `shared_ptr` por referência ou passe o ponteiro bruto ou uma referência para a base do objeto. Passando dessa maneira fornece um benefício de desempenho pequeno e também pode ajudar a express sua intenção de programação.  
  
-   Às vezes, por exemplo, em um `std:vector<shared_ptr<T>>`, talvez você precise passar cada `shared_ptr` a um objeto de função nomeada ou o corpo da expressão lambda. Se o lambda ou a função não está armazenando o ponteiro, em seguida, passar o `shared_ptr` por referência para evitar invocar o construtor de cópia para cada elemento.    
  
## <a name="example"></a>Exemplo  
 A exemplo a seguir mostra como `shared_ptr` sobrecargas de vários operadores de comparação para habilitar comparações do ponteiro na memória que pertence a `shared_ptr` instâncias.  
  
 [!code-cpp[stl_smart_pointers#3](../cpp/codesnippet/CPP/how-to-create-and-use-shared-ptr-instances_6.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Ponteiros inteligentes](../cpp/smart-pointers-modern-cpp.md)