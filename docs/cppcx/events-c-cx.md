---
title: Eventos (C++/CX)
ms.date: 07/15/2019
ms.assetid: 31c8e08a-00ad-40f9-8f7e-124864aaad58
ms.openlocfilehash: aab37353b1ea8d9f81a8e9a9ae489a4dd3542cc0
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70740520"
---
# <a name="events-ccx"></a>Eventos (C++/CX)

Um tipo de Windows Runtime pode declarar eventos (ou seja, publicar) e o código do cliente no mesmo componente ou em outros componentes pode assinar esses eventos associando métodos chamados *manipuladores de eventos* com o evento. Vários manipuladores de eventos podem ser associados a um único evento. Quando o objeto de publicação gera o evento, ele faz com que todos os manipuladores de eventos sejam invocados. Dessa forma, uma classe assinante poderá executar qualquer ação personalizada que seja apropriada quando o editor gerar o evento. Um evento possui um tipo delegate que especifica a assinatura que todos os manipuladores de eventos devem ter para assinar o evento.

## <a name="consuming-events-in-windows-components"></a>Consumindo eventos em componentes do Windows

Muitos componentes no Windows Runtime expõem eventos. Por exemplo, um objeto LightSensor dispara um evento ReadingChanged quando o sensor relata um novo valor de luminescência. Ao usar um objeto LightSensor em seu programa, você pode definir um método que será chamado quando o evento ReadingChanged for acionado. O método pode fazer tudo o que você deseja fazer; o único requisito é que sua assinatura deve corresponder à assinatura do delegado que é invocado. Para obter mais informações sobre como criar um manipulador de eventos de representante e assinar um evento, consulte [delegados](../cppcx/delegates-c-cx.md).

## <a name="creating-custom-events"></a>Criando eventos personalizados

### <a name="declaration"></a>Declaração

Você pode declarar um evento em uma classe ref ou uma interface, e ele pode ter acessibilidade pública, interna (pública/privada, pública protegida, protegida, privada protegida ou privada. Quando você declara um evento, internamente o compilador cria um objeto que expõe dois métodos acessadores: add e remove. Ao assinar manipuladores de eventos de registro de objetos, o objeto de evento armazena-os em uma coleção. Quando um evento é acionado, o objeto de evento invoca todos os manipuladores em sua lista, um a um. Um evento trivial, como o do exemplo a seguir, tem um repositório de backup implícito, bem como métodos acessadores `add` e `remove` implícitos. Você também pode especificar seus próprios acessadores, da mesma forma que pode especificar acessadores `get` e `set` personalizados em uma propriedade.  A classe de implementação não pode percorrer manualmente a lista de assinantes de evento em um evento trivial.

O exemplo de código a seguir mostra como declarar e disparar um evento. Observe que o evento tem um tipo delegate e é declarado com o símbolo “^”.

[!code-cpp[cx_events#01](../cppcx/codesnippet/CPP/cx_events/class1.h#01)]

### <a name="usage"></a>Uso

O exemplo a seguir mostra como uma classe assinante usa o operador `+=` para assinar o evento e fornecer um manipulador de eventos a ser invocado quando o evento for acionado. Observe que a função fornecida corresponde à assinatura do representante que é definido no lado do editor no namespace `EventTest` .

[!code-cpp[cx_events#02](../cppcx/codesnippet/CPP/eventsupportinvs/eventclientclass.h#02)]

> [!WARNING]
> Em geral, é melhor usar uma função nomeada, em vez de uma lambda, para um manipulador de eventos, a menos que você seja muito cuidadoso a fim de evitar referências circulares. Uma função nomeada captura o ponteiro "this" por referência fraca, enquanto uma lambda captura-o por referência forte e cria uma referência circular. Para obter mais informações, consulte [Referências fracas e quebra de ciclos (C++/CX)](../cppcx/weak-references-and-breaking-cycles-c-cx.md).

### <a name="custom-add-and-remove-methods"></a>Métodos add e remove personalizados

Internamente, um evento tem um método add, um método remove e um método raise. Quando o código do cliente assina um evento, o método add é chamado e o representante que é transmitido é adicionado à lista de invocação de eventos. A classe de publicação invoca o evento, o que faz com que o método raise() seja chamado e cada representante na lista seja invocado um após o outro. Um assinante pode remover a si mesmo da lista, o que faz com que o método remove do evento seja chamado. O compilador fornecerá versões padrão desses métodos se você não defini-los no código; eles são conhecidos como eventos triviais. Em muitos casos, tudo o que se precisa é de um evento trivial.

Você pode especificar métodos add, remove e raise personalizados para qualquer evento se tiver que executar lógica personalizada em resposta à adição ou remoção de assinantes. Por exemplo, se você tiver um objeto caro que seja necessário somente para relatórios de eventos, poderá adiar a criação do objeto até um cliente realmente assinar o evento.

O exemplo a seguir mostra como adicionar métodos add, remove e raise personalizados a um evento:

[!code-cpp[cx_events#03](../cppcx/codesnippet/CPP/cx_events/class1.h#03)]

## <a name="removing-an-event-handler-from-the-subscriber-side"></a>Removendo um manipulador de eventos do lado do assinante

Em alguns casos raros, talvez você queira remover um manipulador de eventos para um evento ao qual tenha assinado anteriormente. Por exemplo, você pode querer substituí-lo por outro manipulador de eventos ou pode querer excluir alguns recursos que são mantidos por ele. Para remover um manipulador, você deve armazenar o EventRegistrationToken que é retornado da operação `+=` . Em seguida, você pode usar o operador de `-=` no token para remover um manipulador de eventos.  No entanto, o manipulador original ainda pode ser invocado, mesmo depois de removido. Portanto, se você estiver pretendendo remover um manipulador de eventos, crie um sinalizador de membro e defina-o se o evento for removido e, no manipulador de eventos, verifique o sinalizador e retorne imediatamente se estiver definido. O exemplo a seguir mostra o padrão básico.

[!code-cpp[cx_events#04](../cppcx/codesnippet/CPP/eventsupportinvs/eventclientclass.h#04)]

### <a name="remarks"></a>Comentários

Vários manipuladores podem ser associados ao mesmo evento. A origem do evento é chamada sequencialmente em todos os manipuladores de evento do mesmo thread. Se um receptor de evento for bloqueado no método do manipulador de eventos, isso impedirá a origem do evento de acionar outros manipuladores de evento para esse evento.

A ordem na qual a origem do evento invoca manipuladores de evento em receptores de evento não é garantida e pode ser diferente de uma chamada para outra.

## <a name="see-also"></a>Consulte também

[Sistema de tipos](../cppcx/type-system-c-cx.md)<br/>
[Delegados](../cppcx/delegates-c-cx.md)<br/>
[Referência da linguagem C++/CX](../cppcx/visual-c-language-reference-c-cx.md)<br/>
[Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)
