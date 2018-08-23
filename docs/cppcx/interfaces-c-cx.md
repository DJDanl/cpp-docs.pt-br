---
title: Interfaces (C + + c++ /CX) | Microsoft Docs
ms.custom: ''
ms.date: 01/22/2017
ms.technology: cpp-windows
ms.topic: language-reference
ms.assetid: 11034314-d54a-426d-923b-5ab7a6b9f8ce
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d8ed06b84ec53cddac2d76488f7d1540a92c1d52
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42592546"
---
# <a name="interfaces-ccx"></a>Interfaces (C++/CX)
Embora uma classe ref possa ser herdada de, no máximo, uma classe base concreta, ela pode implementar qualquer número de classes de interface. Uma classe de interface (ou estrutura de interface) em si pode herdar (ou exigir) várias classes de interface, pode sobrecarregar suas funções de membro e pode ter parâmetros de tipo.  
  
## <a name="characteristics"></a>Características  
 Uma interface tem as seguintes características:  
  
-   Uma classe (ou estrutura) de interface deve ser declarada dentro de um namespace e pode ter acessibilidade pública ou privada. Somente as interfaces públicas são emitidas para metadados.  
  
-   Os membros da interface podem incluir propriedades, métodos e eventos.  
  
-   Todos os membros de interface são implicitamente públicos e virtuais.  
  
-   Campos e membros estáticos não são permitidos.  
  
-   Tipos que são usados como propriedades, parâmetros de método ou retornam valores só podem ser tipos de tempo de execução do Windows; Isso inclui os tipos fundamentais e os tipos de classe de enum.  
  
## <a name="declaration-and-usage"></a>Declaração e uso  
 O exemplo de código a seguir mostra como declarar uma interface. Observe que uma interface pode ser declarada como uma classe ou tipo de estrutura.  
  
 [!code-cpp[cx_interfaces#01](../cppcx/codesnippet/CPP/interfacestest/class1.h#01)]  
  
 Para implementar uma interface, uma classe ref ou estrutura ref declara e implementa métodos e propriedades virtuais. A interface e a classe ref de implementação devem usar os mesmos nomes de parâmetros de método, conforme mostrado neste exemplo:  
  
 [!code-cpp[cx_interfaces#02](../cppcx/codesnippet/CPP/interfacestest/class1.h#02)]  
  
## <a name="interface-inheritance-hierarchies"></a>Hierarquias de herança de interface  
 Uma interface pode herdar de uma ou mais interfaces. Porém, diferentemente de uma classe ou estrutura ref, uma interface não declara os membros da interface herdada. Se a interface B for herdada da interface A, e a classe ref C for herdada de B, a C deverá implementar A e B. Isso é mostrado no exemplo a seguir.  
  
 [!code-cpp[cx_interfaces#03](../cppcx/codesnippet/CPP/interfacestest/class1.h#03)]  
  
## <a name="implementing-interface-properties-and-events"></a>Implementando propriedades e eventos da interface  
 Conforme mostrado no exemplo anterior, você pode usar propriedades virtuais triviais para implementar propriedades de interface. Você também pode fornecer getters e setters personalizados na classe de implementação.  Tanto getter quanto setter devem ser públicos em uma propriedade de interface.  
  
 [!code-cpp[cx_interfaces#04](../cppcx/codesnippet/CPP/interfacestest/class1.h#04)]  
  
 Se uma interface declarar uma propriedade get-only ou set-only, a classe de implementação deverá fornecer explicitamente um getter ou setter.  
  
 [!code-cpp[cx_interfaces#05](../cppcx/codesnippet/CPP/interfacestest/class1.h#05)]  
  
 Você também pode implementar métodos add e remove personalizados para eventos na classe de implementação.  
  
## <a name="explicit-interface-implementation"></a>Implementação de interface explícita  
 Quando uma classe ref implementa várias interfaces e estas têm métodos cujos nomes e assinaturas são idênticos para o compilador, você poderá usar a sintaxe a seguir para indicar explicitamente o método de interface que um método de classe está implementando.  
  
 [!code-cpp[cx_interfaces#06](../cppcx/codesnippet/CPP/interfacestest/class1.h#06)]  
  
## <a name="generic-interfaces"></a>Interfaces genéricas  
 No C + + c++ /CX, o `generic` palavra-chave é usada para representar um tipo de tempo de execução do Windows com parâmetros. Um tipo parametrizado é emitido nos metadados e pode ser consumido pelo código que está escrito em qualquer linguagem que ofereça suporte aos parâmetros de tipo. O tempo de execução do Windows define algumas interfaces genéricas — por exemplo, [Windows::Foundation::Collections::IVector\<T >](Windows::Foundation::Collections::IVector)— mas não suporta a criação de interfaces genéricas públicas definidas pelo usuário no C + + c++ /CLI CX. No entanto, é possível criar interfaces genéricas privadas.  
  
 Aqui está como tipos de tempo de execução do Windows podem ser usados para criar uma interface genérica:  
  
-   Uma `interface class` genérica definida pelo usuário em um componente não tem permissão para ser emitida no seu arquivo de metadados do Windows; portanto, ela não pode ter acessibilidade pública e o código do cliente em outros arquivos .winmd não pode implementá-lo. Ela pode ser implementada por classes ref não públicas no mesmo componente. Uma classe ref pública pode ter um tipo de interface genérica como um membro privado.  
  
     O trecho de código a seguir mostra como declarar uma `interface class` genérica e implementá-la em uma classe ref privada, bem como a usar a classe ref como um membro privado em uma classe ref pública.  
  
     [!code-cpp[cx_interfaces#07](../cppcx/codesnippet/CPP/interfacestest/class1.h#07)]  
  
-   Uma interface genérica deve seguir as regras de interface padrão que controlam a acessibilidade, os membros, as relações *requires* , as classes base, etc.  
  
-   Uma interface genérica pode usar um ou mais parâmetros de tipos genéricos que são precedidos por `typename` ou `class`. Não há suporte para parâmetros sem tipo.  
  
-   Um parâmetro de tipo pode ser qualquer tipo de tempo de execução do Windows. Ou seja, o parâmetro de tipo pode ser um tipo de referência, um tipo de valor, uma classe de interface, um representante, um tipo fundamental ou uma classe enum pública.  
  
-   Uma *interface genérica fechada* é uma interface que herda de uma interface genérica e especifica argumentos de tipo concreto para todos os parâmetros de tipo. Ela pode ser usada em qualquer lugar em que uma interface privada não genérica possa ser usada.  
  
-   Uma *interface genérica aberta* é uma interface que tem um ou mais parâmetros de tipo para os quais nenhum tipo concreto é fornecido. Ela pode ser usada em qualquer lugar em que um tipo possa ser usado; incluindo como um argumento de tipo de outra interface genérica.  
  
-   Você pode parametrizar apenas uma interface inteira, não métodos individuais.  
  
-   Parâmetros de tipo não podem ser restritos.  
  
-   Uma interface genérica fechada tem um UUID gerado implicitamente. Um usuário não pode especificar o UUID.  
  
-   Na interface, qualquer referência à interface atual, em um parâmetro de método, valor de retorno ou propriedade, é assumido como referência à instanciação atual. Por exemplo, *IMyIntf* significa *IMyIntf\<T >*.  
  
-   Quando o tipo de um parâmetro de método é um parâmetro de tipo, a declaração desse parâmetro ou variável usa o nome do parâmetro de tipo sem nenhum ponteiro, referência nativa ou declaradores de identificador. Em outras palavras, você nunca escreve "T^".  
  
-   As classes ref no modelo devem ser privadas. Elas podem implementar interfaces genéricas e pode passar o parâmetro de modelo *T* ao argumento genérico *T*. Cada instanciação de uma classe ref de modelo é em si uma classe ref.  
  
## <a name="see-also"></a>Consulte também  
 [Sistema de tipos](../cppcx/type-system-c-cx.md)   
 [Referência de linguagem do Visual C++](../cppcx/visual-c-language-reference-c-cx.md)   
 [Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)