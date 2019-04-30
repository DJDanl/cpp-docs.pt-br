---
title: Referências fracas e quebra de ciclos (C++/CX)
ms.date: 01/22/2017
ms.assetid: 1acb6402-05f0-4951-af94-0e9dab41c53e
ms.openlocfilehash: 19252b8684eade131394e98dc705f2f1d451f0cf
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62384888"
---
# <a name="weak-references-and-breaking-cycles-ccx"></a>Referências fracas e quebra de ciclos (C++/CX)

Em qualquer sistema de tipos que se baseie na contagem de referência, as referências aos tipos podem formar *ciclos*, isto é, um objeto se refere a um segundo objeto, o segundo objeto se refere a um terceiro objeto e assim por diante até que algum objeto final faça referência de volta ao primeiro objeto. Em um ciclo, os objetos não podem ser excluídos corretamente quando uma contagem de referência de objeto se torna zero. Para ajudá-lo a resolver esse problema, C++/CX fornece o [classe Platform:: WeakReference](../cppcx/platform-weakreference-class.md) classe. Um objeto `WeakReference` tem suporte ao método [Resolver](../cppcx/platform-weakreference-class.md#resolve) , que retorna nulo se o objeto não existir mais ou lança uma [Platform::InvalidCastException](../cppcx/platform-invalidcastexception-class.md) se o objeto estiver ativo mas não for do tipo `T`.

Um cenário em que `WeakReference` deve ser usado é quando o ponteiro `this` é capturado em uma expressão lambda que é usada para definir um manipulador de eventos. É recomendável usar métodos nomeados ao definir manipuladores de eventos, mas se desejar usar uma expressão lambda para o manipulador de eventos ou se tiver que interromper um ciclo de contagem de referência em alguma outra situação, use `WeakReference`. Veja um exemplo:

```

using namespace Platform::Details;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Controls;

Class1::Class1()
{
    // Class1 has a reference to m_Page
    m_Page = ref new Page();

    // m_Page will have a reference to this Class1
    // so create a weak reference to this
    WeakReference wr(this);
    m_Page->DoubleTapped += ref new DoubleTappedEventHandler(
        [wr](Object^ sender, DoubleTappedRoutedEventArgs^ args)
    {
       // Use the weak reference to get the object
       Class1^ c = wr.Resolve<Class1>();
       if (c != nullptr)
       {
           c->m_eventFired = true;
       }
       else
       {
           // Inform the event that this handler should be removed
           // from the subscriber list
           throw ref new DisconnectedException();
       }
    });
}

}
```

Quando um manipulador de eventos gera `DisconnectedException`, ele faz com que o evento remova o manipulador da lista de assinantes.
