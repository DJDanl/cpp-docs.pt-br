---
title: Classes e estruturas ref (C + + CX) | Microsoft Docs
ms.custom: 
ms.date: 01/22/2017
ms.technology: cpp-windows
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: language-reference
ms.assetid: 3d736b82-0bf0-48cf-bac1-cc9d110b70d1
caps.latest.revision: 
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5d8b7717c98ebd4bab8c0d3d8c20a594a3f4d58e
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="ref-classes-and-structs-ccx"></a>Classes e estruturas ref (C++/CX)
C + + suporta CX definidos pelo usuário *classes ref* e *estruturas ref*, definidas pelo usuário *valor classes* e *estruturas de valor*. Essas estruturas de dados são os contêineres principais pelos quais C + + CX oferece suporte ao sistema de tipo de tempo de execução do Windows. O conteúdo é emitido para metadados de acordo com determinadas regras específicas e isso permite que ele seja transmitido entre componentes de tempo de execução do Windows e aplicativos de plataforma Universal do Windows que são escritos em C++ ou em outras linguagens.  
  
 Uma classe ou estrutura ref apresenta estes recursos essenciais:  
  
-   Ela deve ser declarada em um namespace, no escopo do namespace, e dentro dele ela pode ter acessibilidade pública ou privada. Somente os tipos públicos são emitidos para metadados. As definições de classes públicas aninhadas não são permitidas, incluindo classes [enum](../cppcx/enums-c-cx.md) públicas aninhadas. Para obter mais informações, consulte [Namespaces e visibilidade do tipo](../cppcx/namespaces-and-type-visibility-c-cx.md).  
  
-   Ele pode conter como membros C + + CX, incluindo classes ref, classes de valor, estruturas ref, estruturas de valor ou estruturas de valor anuláveis. Também pode conter tipos escalares como float64, bool etc. Pode conter também tipos C++ padrão, como `std::vector` ou uma classe personalizada, desde que não sejam públicos. C + + CX construções podem ter `public`, `protected`, `internal`, `private`, ou `protected private` acessibilidade. Todos os membros `public` ou `protected` são emitidos para metadados. Os tipos C++ padrão devem ter acessibilidade `private`, `internal`ou `protected private` , o que os impede de serem emitidos em metadados.  
  
-   Ela pode implementar uma ou mais *classes de interface* ou *estruturas da interface*.  
  
-   Ela pode ser herdada de uma classe base, e as classes base em si têm restrições adicionais. A herança em hierarquias de classe ref pública tem mais restrições que a herança em classes ref privadas.  
  
-   Ela não pode ser declarada como genérica. Se ela tiver acessibilidade privada, pode ser um modelo.  
  
-   Seu tempo de vida é gerenciado pela contagem de referência automática.  
  
## <a name="declaration"></a>Declaração  
 O fragmento de código a seguir declara a classe ref `Person` . Observe que o C++ padrão `std::map` tipo é usado em membros particulares e o tempo de execução do Windows`IMapView` interface é usada na interface pública. Observe também que o "^" é anexado às declarações de tipos de referências.  
  
 [!code-cpp[cx_classes#03](../cppcx/codesnippet/CPP/classesstructs/class1.h#03)]  
  
## <a name="implementation"></a>Implementação  
 Este exemplo de código mostra uma implementação da classe ref `Person` :  
  
 [!code-cpp[cx_classes#04](../cppcx/codesnippet/CPP/classesstructs/class1.cpp#04)]  
  
## <a name="usage"></a>Uso  
 O exemplo de código a seguir mostra como o código do cliente usa a classe ref `Person` .  
  
 [!code-cpp[cx_classes#05](../cppcx/codesnippet/CPP/classesstructs/class1.cpp#05)]  
  
 Você também pode usar a semântica de pilha para declarar uma variável de classe ref local. Esse tipo de objeto se comporta como uma variável com base na pilha, mesmo que a memória ainda esteja alocada dinamicamente. Uma diferença importante é que você não pode atribuir uma referência de rastreamento (%) a uma variável que é declarada com semântica de pilha; isso garante que a contagem de referência será diminuída para zero quando a função for encerrada. Este exemplo mostra uma classe ref básica `Uri`e uma função que a usa com semântica de pilha:  
  
 [!code-cpp[cx_classes#06](../cppcx/codesnippet/CPP/classesstructs/class1.cpp#06)]  
  
## <a name="memory-management"></a>Gerenciamento de memória  
 Aloque uma classe ref na memória dinâmica usando a palavra-chave `ref new` .  
  
 [!code-cpp[cx_classes#01](../cppcx/codesnippet/CPP/classesstructs/class1.h#01)]  
  
 O operador handle-to-object ^ é conhecido como um "hat" e é basicamente um ponteiro inteligente do C++. A memória para a qual aponta é destruída automaticamente quando o último hat sai do escopo ou é explicitamente definido como `nullptr`.  
  
 Por definição, uma classe ref tem semântica de referência. Quando você atribui uma variável da classe ref, é o identificador que é copiado, não o objeto. No próximo exemplo, após a atribuição, `myClass` e `myClass2` apontam para o mesmo local de memória.  
  
 [!code-cpp[cx_classes#02](../cppcx/codesnippet/CPP/classesstructs/class1.h#02)]  
  
 Quando uma classe de referência C++/CX é instanciada, sua memória é inicializada do zero antes que seu construtor seja chamado; no entanto, não é necessário inicializar do zero os membros individuais, incluindo propriedades. Se a classe C++/CX deriva de uma classe de Biblioteca em Tempo de Execução do Windows (WRL) C++, apenas a parte de classe derivada de C++/CX é inicializada do zero.  
  
### <a name="members"></a>Membros  
 Uma classe ref pode conter os membros de função `public`, `protected`e `private` ; somente os membros `public` e `protected` são emitidos nos metadados. Classes aninhadas e classes ref são permitidas, mas não podem ser `public`. Campos públicos não são permitidos; membros de dados públicos devem ser declarados como propriedades. Os membros de dados internos particulares ou protegidos podem ser campos. Por padrão, em uma classe ref, a acessibilidade de todos os membros é `private`.  
  
 Um estrutura ref é igual a uma classe ref, exceto pelo fato de seus membros terem acessibilidade `public` por padrão.  
  
 Um `public` classe ref ou estrutura ref é emitida nos metadados, mas para ser usada em outros aplicativos de plataforma Universal do Windows e os componentes de tempo de execução do Windows deve ter pelo menos um construtor público ou protegido. Uma classe ref pública que tem um construtor público também precisa ser declarada como `sealed` para evitar mais derivação por meio da ABI (interface binária de aplicativo).  
  
 Membros públicos podem não ser declarados como const porque o sistema de tipos do tempo de execução do Windows não oferece suporte a constantes. Você pode usar uma propriedade estática para declarar um membro de dados públicos com um valor constante.  
  
 Ao definir uma classe ou estrutura ref pública, o compilador aplica os atributos necessários à classe e armazena essas informações no arquivo .winmd do aplicativo. No entanto, quando você define uma classe ref pública não lacrada, aplique manualmente o `Windows::Foundation::Metadata::WebHostHidden` atributo para garantir que a classe não é visível para aplicativos de plataforma Universal do Windows que são escritos em JavaScript.  
  
 Uma classe ref pode ter tipos C++ padrão, incluindo tipos `const` , em qualquer membro `private`, `internal`ou `protected private` .  
  
 As classes ref públicas que têm parâmetros de tipo não são permitidas. Não são permitidas classes ref genéricas definidas pelo usuário. Uma classe ref privada, interna ou privada protegida pode ser um modelo.  
  
## <a name="destructors"></a>Destruidores  
 Em C + + CX, chamar `delete` em um destruidor público chama o destruidor independentemente da contagem de referência do objeto. Esse comportamento permite definir um destruidor que execute uma limpeza personalizada de recursos não RAII de uma maneira determinista. No entanto, mesmo nesse caso, o próprio objeto não é excluído da memória. A memória do objeto é liberada apenas quando a contagem de referência atinge o valor zero.  
  
 Se o destruidor de uma classe não for público, ele será chamado apenas quando a contagem de referência atingir o valor zero. Se você chamar `delete` em um objeto que tenha um destruidor privado, o compilador gerará o aviso C4493, informando que "expressão de exclusão não surte efeito porque o destruidor de \<nome do tipo > não tem acessibilidade 'pública'."  
  
 Os destruidores da classe ref só podem ser declarados como se segue:  
  
-   público e virtual (permitido em tipos lacrados ou não lacrados)  
  
-   privado protegido e não virtual (permitido somente em tipos não lacrados)  
  
-   privado e não virtual (permitido somente em tipos lacrados)  
  
 Não é permitida nenhuma outra combinação entre as características citadas acima.  Se você não declarar explicitamente um destruidor, o compilador vai gerar um destruidor virtual público, caso a classe base do tipo ou algum membro tenha um destruidor público. Caso contrário, o compilador vai gerar um destruidor não virtual privado e protegido para tipos não lacrados ou um destruidor não virtual privado para tipo lacrados.  
  
 O comportamento será indefinido se você tentar acessar membros de uma classe que já tenha executado seu destruidor; provavelmente, isso causará falha do programa. Chamar `delete t` em um tipo que não tenha um destruidor público não terá nenhum efeito. Também não terá efeito nenhum chamar `delete this` em um tipo ou em uma classe base que tenha um destruidor `private` ou `protected private` conhecido de dentro da sua hierarquia de tipos.  
  
 Quando você declara um destruidor público, o compilador gera o código de forma que a classe ref implemente `Platform::IDisposable` e o destruidor implemente o método `Dispose` . `Platform::IDisposable` é o C + + projeção CX de `Windows::Foundation::IClosable`. Nunca implemente explicitamente essas interfaces.  
  
## <a name="inheritance"></a>Herança  
 Platform::Object é a classe base universal para todas as classes ref. Todas as classes ref podem ser convertidas implicitamente em Platform::Object e substituir [Object::ToString](../cppcx/platform-object-class.md#tostring). No entanto, o modelo de herança do Windows Runtime não se destina geral modelo de herança; em C++ c++ /CX, isso significa que uma classe ref pública definida pelo usuário não pode servir como uma classe base.  
  
 Se você estiver criando um controle de usuário XAML, e o objeto participar do sistema de propriedade de dependência, poderá usar `Windows::UI::Xaml::DependencyObject` como uma classe base.  
  
 Após definir uma classe `MyBase` não lacrada que é herdada de `DependencyObject`, outras classes ref públicas ou privadas em seu componente ou aplicativo poderão ser herdadas de `MyBase`. A herança em classes ref públicas deve ser feita apenas para oferecer suporte às substituições de métodos virtuais, à identidade polimórfica e ao encapsulamento.  
  
 Não é necessário que uma classe ref privada seja derivada de uma classe não lacrada existente. Se for necessária uma hierarquia de objetos para modelar a estrutura do seu próprio programa ou para habilitar a reutilização de código, use classes ref privadas ou internas, ou melhor ainda, as classes C++ padrão. É possível expor a funcionalidade da hierarquia de objetos privados por meio de um wrapper de classe ref lacrada pública.  
  
 Uma classe ref que tem um construtor público ou protegido no C + + CX deve ser declarada como lacrada. Essa restrição significa que não há nenhuma maneira para classes que são escritos em outras linguagens, como c# ou Visual Basic para herdar de tipos que você declara em um componente de tempo de execução do Windows que está escrito em C + + CX.  
  
 Aqui estão as regras básicas de herança no C + + CX:  
  
-   As classes ref podem ser herdadas diretamente de, no máximo, uma classe ref base, mas podem implementar qualquer número de interface.  
  
-   Se uma classe tiver um construtor público, ela deverá ser declarada como lacrada para evitar derivação posterior.  
  
-   Você pode criar classes base públicas não lacradas que tenham construtores privados protegidos ou internos, desde que a classe base derive direta ou indiretamente de uma classe base não lacrada existente, como `Windows::UI::Xaml::DependencyObject`. Não há suporte para a herança de classes ref definidas pelo usuário entre os arquivos .winmd; no entanto, uma classe ref pode ser herdada de uma interface que é definida em outro arquivo .winmd. Você pode criar classes derivadas de uma classe ref base definida pelo usuário somente dentro do mesmo componente de tempo de execução do Windows ou o aplicativo de plataforma Universal do Windows.  
  
-   Para classes ref, há suporte somente para herança pública.  
  
     [!code-cpp[cx_classes#08](../cppcx/codesnippet/CPP/classesstructs/class1.h#08)]  
  
 O exemplo a seguir mostra como expor uma classe ref pública que deriva de outras classes ref em uma hierarquia de heranças.  
  
 [!code-cpp[cx_classes#09](../cppcx/codesnippet/CPP/classesstructs/class1.h#09)]  
  
## <a name="see-also"></a>Consulte também  
 [Sistema de tipos](../cppcx/type-system-c-cx.md)   
 [Classes de valor e structs](../cppcx/value-classes-and-structs-c-cx.md)   
 [Referência de linguagem do Visual C++](../cppcx/visual-c-language-reference-c-cx.md)   
 [Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)