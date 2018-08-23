---
title: Delegados (C++ c++ /CX) | Microsoft Docs
ms.custom: ''
ms.date: 01/22/2017
ms.technology: cpp-windows
ms.topic: language-reference
ms.assetid: 3175bf1c-86d8-4eda-8d8f-c5b6753d8e38
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 050b11050cc280fc6d3aa8900487442bd723a57f
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42592767"
---
# <a name="delegates-ccx"></a>Delegados (C++/CX)
O `delegate` palavra-chave é usada para declarar um tipo de referência que é o equivalente de tempo de execução do Windows de um objeto de função em C++ padrão. Uma declaração delegate semelhante a uma assinatura de função especifica o tipo de retorno e os tipos de parâmetro que sua função envolvida deve ter. Esta é uma declaração delegate definida pelo usuário:  
  
```cpp  
     public delegate void PrimeFoundHandler(int result);  
```  
  
 Delegados são mais comumente usados em conjunto com eventos. Um evento tem um tipo delegate da mesma maneira que uma classe que pode ter um tipo de interface. O delegate representa um contrato que é cumprido pelos manipuladores de eventos. Este é um membro da classe de eventos cujo tipo é o delegate definido anteriormente:  
  
```cpp  
event PrimeFoundHandler^ primeFoundEvent;  
```  
  
 Ao declarar representantes que ficarão expostos aos clientes pela interface binária de aplicativo de tempo de execução do Windows, use [Windows::Foundation::TypedEventHandler\<TSender, TResult >](http://msdn.microsoft.com/library/windows/apps/br225997.aspx). Este representante possui proxy predefinido e binários stub que permitem seu consumo por clientes JavaScript.  
  
## <a name="consuming-delegates"></a>Consumindo delegados  
 Quando você cria um aplicativo da plataforma Universal do Windows, geralmente trabalha com um delegado como o tipo de um evento que expõe uma classe de tempo de execução do Windows. Para assinar um evento, crie uma instância do tipo do seu representante especificando uma função (ou lambda) que corresponda à assinatura do representante. Use o operador `+=` para passar o objeto do representante ao membro de evento na classe. Isso é conhecido como assinar o evento. Quando a instância da classe "dispara" o evento, sua função é chamada, juntamente com qualquer outro manipulador que tenha sido adicionado pelo seu objeto ou outros objetos.  
  
> [!TIP]
>  O Visual Studio faz grande parte do trabalho para você na criação de um manipulador de eventos. Por exemplo, se você especificar um manipulador de eventos na marcação XAML, uma dica de ferramenta será exibida. Se você escolher a dica de ferramenta, o Visual Studio criará o método de manipulador de eventos automaticamente e o associará ao evento na classe de publicação.  
  
 O exemplo a seguir mostra o padrão básico. `Windows::Foundation::TypedEventHandler` é o tipo delegado. A função do manipulador é criada usando uma função nomeada.  
  
 Em app.h:  
  
 [!code-cpp[cx_delegates#120](../cppcx/codesnippet/CPP/delegatesevents/class1.h#120)]  
  
 Em app.cpp:  
  
 [!code-cpp[cx_delegates#121](../cppcx/codesnippet/CPP/delegatesevents/class1.cpp#121)]  
  
> [!WARNING]
>  Em geral, para um manipulador de eventos, é melhor usar uma função nomeada em vez de uma lambda, a menos que você seja muito cuidadoso a fim de evitar referências circulares. Uma função nomeada captura o ponteiro "this" por referência fraca, mas uma lambda captura-o por referência forte e cria uma referência circular. Para obter mais informações, consulte [referências fracas e quebra de ciclos](../cppcx/weak-references-and-breaking-cycles-c-cx.md).  
  
 Por convenção, nomes de delegado do manipulador de eventos que são definidos no tempo de execução do Windows têm o formato * EventHandler — por exemplo, RoutedEventHandler, SizeChangedEventHandler ou SuspendingEventHandler. Também por convenção, os delegados do manipulador de eventos têm dois parâmetros e retornar void. Em um representante que não tenha parâmetros de tipo, o primeiro parâmetro é do tipo [Platform::Object Class^](../cppcx/platform-object-class.md); ele contém uma referência para o remetente, que é o objeto que disparou o evento. Você tem que converter novamente no tipo original antes de usar o argumento no método do manipulador de eventos. Em um representante do manipulador de eventos que tenha parâmetros de tipo, o primeiro parâmetro de tipo especifica o tipo de remetente e o segundo parâmetro é um identificador para uma classe ref que contém informações sobre o evento. Por convenção, essa classe é chamada \*EventArgs. Por exemplo, um delegado RoutedEventHandler tem um segundo parâmetro do tipo RoutedEventArgs^ e DragEventHander tem um segundo parâmetro do tipo DragEventArgs^.  
  
 Por convenção, os representantes que encapsularam o código que é executado quando uma operação assíncrona é concluída são denominados *CompletedHandler. Esses representantes são definidos como propriedades na classe, e não como eventos. Desse modo, não use o operador `+=` para assiná-los; você apenas atribui um objeto de representante à propriedade.  
  
> [!TIP]
>  O C++ IntelliSense não mostra a assinatura completa do representante; portanto, isso não ajuda a determinar o tipo específico do parâmetro EventArgs. Para localizar o tipo, você pode ir para **Pesquisador de Objetos** e examinar o método `Invoke` do representante,  
  
## <a name="creating-custom-delegates"></a>Criando delegados personalizados  
 Você pode definir seus próprios delegados, para definir manipuladores de eventos ou para permitir que os clientes passem funcionalidade personalizada para o seu componente de tempo de execução do Windows. Como qualquer outro tipo de tempo de execução do Windows, um delegate público não pode ser declarado como genérico.  
  
### <a name="declaration"></a>Declaração  
 A declaração de um delegado é semelhante a uma declaração da função, exceto pelo fato de um delegado ser um tipo. Em geral, você declara um representante no escopo do namespace, embora também possa aninhar uma declaração de representante em uma declaração de classe. O representante a seguir encapsula qualquer função que tenha `ContactInfo^` como entrada e retorna `Platform::String^`.  
  
 [!code-cpp[cx_delegates#111](../cppcx/codesnippet/CPP/delegatesevents/class1.h#111)]  
  
 Depois que você declarar um tipo de representante, poderá declarar membros de classe de tipo ou de métodos que usam objetos desse tipo como parâmetros. Um método ou uma função também podem retornar um tipo delegado. No exemplo a seguir, o método `ToCustomString` usa o delegado como um parâmetro de entrada. O método permite que o código de cliente forneça uma função personalizada que constrói uma cadeia de caracteres de algumas ou todas as propriedades públicas de um objeto `ContactInfo` .  
  
 [!code-cpp[Cx_delegates#112](../cppcx/codesnippet/CPP/delegatesevents/class1.h#112)]  
  
> [!NOTE]
>  Você usa o "^" símbolo quando você faz referência ao tipo delegado, exatamente como você com qualquer tempo de execução do Windows faz referência tipo.  
  
 Uma declaração de evento sempre tem um tipo delegado. Este exemplo mostra um delegado típica assinatura de tipo em tempo de execução do Windows:  
  
 [!code-cpp[cx_delegates#122](../cppcx/codesnippet/CPP/delegatesevents/class1.h#122)]  
  
 O evento `Click` na classe `Windows:: UI::Xaml::Controls::Primitives::ButtonBase` é do tipo `RoutedEventHandler`. Para obter mais informações, consulte [Events](../cppcx/events-c-cx.md).  
  
 O código de cliente primeiro constrói a instância delegada usando `ref new` e fornecendo um lambda compatível com a assinatura do delegado e define o comportamento personalizado.  
  
 [!code-cpp[Cx_delegates#113](../cppcx/codesnippet/CPP/delegatesevents/class1.cpp#113)]  
  
 Em seguida, chama a função de membro e passa o delegado. Vamos supor que `ci` seja uma instância de `ContactInfo^` e `textBlock` seja um `TextBlock^`XAML.  
  
 [!code-cpp[Cx_delegates#114](../cppcx/codesnippet/CPP/delegatesevents/class1.cpp#114)]  
  
 No exemplo a seguir, um aplicativo cliente passa um delegado personalizado para um método público em um componente de tempo de execução do Windows que executa o delegado em relação a cada item em um `Vector`:  
  
 [!code-cpp[Cx_delegates#118](../cppcx/codesnippet/CPP/clientapp/mainpage.xaml.cpp#118)]  
  
 [!code-cpp[Cx_delegates#119](../cppcx/codesnippet/CPP/delegatesevents/class1.cpp#119)]  
  
### <a name="construction"></a>Construção  
 Você pode construir um delegado de qualquer um destes objetos:  
  
-   lambda  
  
-   static function  
  
-   pointer-to-member  
  
-   std::function  
  
 O exemplo a seguir mostra como construir um delegado com base em cada um desses objetos. Você consome o delegado exatamente da mesma maneira, independentemente do tipo de objeto que é usado para construí-lo.  
  
 [!code-cpp[Cx_delegates#115](../cppcx/codesnippet/CPP/delegatesevents/class1.cpp#115)]  
  
> [!WARNING]
>  Se você usar uma lambda que captura o ponteiro "this", certifique-se de usar explicitamente o operador `-=` para cancelar explicitamente o registro do evento antes de sair da lambda. Para obter mais informações, consulte [Eventos](../cppcx/events-c-cx.md).  
  
### <a name="generic-delegates"></a>Delegados genéricos  
 Delegates genéricos em C++/CX têm restrições semelhantes às declarações de classes genéricas. Eles não podem ser declarados como públicos. Você pode declarar um delegate genérico particular ou interno e consumi-lo em C++, mas os clientes .NET ou JavaScript não podem consumi-lo, pois ele não é emitido nos metadados .winmd. Este exemplo declara um delegate genérico que só pode ser consumido por C++:  
  
 [!code-cpp[Cx_delegates#116](../cppcx/codesnippet/CPP/delegatesevents/class1.h#116)]  
  
 O exemplo a seguir declara uma instância especializada do delegate dentro de uma definição de classe:  
  
 [!code-cpp[Cx_delegates#117](../cppcx/codesnippet/CPP/delegatesevents/class1.h#117)]  
  
## <a name="delegates-and-threads"></a>Delegados e threads  
 Um delegado, assim como um objeto de função, contém o código que será executado a qualquer momento no futuro. Se o código que cria e passa o delegado e a função que aceita e executa o delegado estiver sendo executado no mesmo thread, as coisas serão relativamente simples. Se esse thread for o thread de IU, o delegado poderá manipular diretamente os objetos da interface de usuário, como controles XAML.  
  
 Se um aplicativo cliente carregar um componente de tempo de execução do Windows que é executado em um threaded apartment e fornece um delegado para esse componente, em seguida, por padrão o delegado é invocado diretamente no thread de STA. A maioria dos componentes de tempo de execução do Windows pode executar no STA ou MTA.  
  
 Se o código que executa o representante estiver sendo executado em um thread diferente, por exemplo, no contexto de um objeto concurrency::task, você será responsável pela sincronização do acesso aos dados compartilhados. Por exemplo, se o seu delegado contiver uma referência a um Vector, e um controle XAML tiver referência ao mesmo Vector, você deverá executar etapas para evitar deadlocks ou condições de corrida que podem ocorrer quando tanto o delegado quanto o controle XAML tentam acessar o Vector ao mesmo tempo. Você também deve tomar cuidado para que o delegado não tente capturar por referência variáveis locais que podem estar fora do escopo antes da invocação do delegado.  
  
 Se você quiser que o delegado criado seja chamado novamente no mesmo thread em que foi criado, por exemplo, se você passá-lo a um componente executado em um MTA apartment, e quiser que ele seja invocado no mesmo thread do criador, use a sobrecarga de construtor delegado que utiliza um segundo parâmetro `CallbackContext` . Somente use essa sobrecarga nos delegados que têm um proxy/stub registrado; nem todos os delegados que são definidos em Windows.winmd são registrados.  
  
 Se você estiver familiarizado com os manipuladores de eventos no .NET, sabe que a prática recomendada é fazer uma cópia local de um evento antes do acioná-lo. Isso evita as condições de corrida em que um manipulador de eventos pode ser removido imediatamente antes de o evento ser invocado. Não é necessário fazer isso em C++/CX porque quando os manipuladores de eventos são adicionados ou removidos uma nova lista de manipuladores é criada. Como um objeto C++ incrementa a contagem de referência na lista de manipuladores antes de chamar um evento, é garantido que todos os manipuladores serão válidos. No entanto, isso também significa que, se você remover um manipulador de eventos do thread de consumo, esse manipulador ainda poderá ser invocado se o objeto de publicação ainda estiver funcionando em sua cópia da lista, que agora estará desatualizada. O objeto de publicação não obterá a lista atualizada até a próxima vez que ele acionar o evento.  
  
## <a name="see-also"></a>Consulte também  
 [Sistema de tipos](../cppcx/type-system-c-cx.md)   
 [Referência de linguagem do Visual C++](../cppcx/visual-c-language-reference-c-cx.md)   
 [Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)