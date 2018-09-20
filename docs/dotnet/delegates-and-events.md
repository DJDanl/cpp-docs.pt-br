---
title: Delegados e eventos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- __event keyword [C++]
- delegate keyword [C++]
- delegates [C++], upgrading from Managed Extensions for C++
- __delegate keyword
- events [C++], upgrading from Managed Extensions for C++
- event keyword [C++]
ms.assetid: 3505c626-7e5f-4492-a947-0e2248f7b84a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 26b67cdce8d52cba7d02f182f0582e20d0303c33
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46373269"
---
# <a name="delegates-and-events"></a>Representantes e eventos

A maneira de declarar delegados e eventos mudou de extensões gerenciadas para C++ para Visual C++.

O sublinhado duplo não é necessária, conforme mostrado no exemplo a seguir. Aqui um código de exemplo nas extensões gerenciadas:

```
__delegate void ClickEventHandler(int, double);
__delegate void DblClickEventHandler(String*);

__gc class EventSource {
   __event ClickEventHandler* OnClick;
   __event DblClickEventHandler* OnDblClick;
};
```

O mesmo código na nova sintaxe será semelhante ao seguinte:

```
delegate void ClickEventHandler( int, double );
delegate void DblClickEventHandler( String^ );

ref class EventSource {
   event ClickEventHandler^ OnClick;
   event DblClickEventHandler^ OnDblClick;
};
```

(Representantes e eventos) são tipos de referência, que é clara na nova sintaxe devido ao uso de circunflexo (`^`).  Eventos de dar suporte a uma sintaxe de declaração explícita e o formulário trivial, mostrada no código anterior. No formulário explícito, o usuário Especifica o `add`, `raise`, e `remove` métodos associados ao evento. (Somente o `add` e `remove` métodos são necessários; o `raise` método é opcional.)

Em extensões gerenciadas, se você fornecer esses métodos, você não fornecer uma declaração de evento explícito também, mas você deve escolher um nome para o evento que não está presente. Cada método é especificado no formulário `add_EventName`, `raise_EventName`, e `remove_EventName`, como no exemplo a seguir, obtido da especificação de Managed Extensions:

```
// explicit implementations of add, remove, raise
public __delegate void f(int);
public __gc struct E {
   f* _E;
public:
   E() { _E = 0; }

   __event void add_E1(f* d) { _E += d; }

   static void Go() {
      E* pE = new E;
      pE->E1 += new f(pE, &E::handler);
      pE->E1(17);
      pE->E1 -= new f(pE, &E::handler);
      pE->E1(17);
   }

private:
   __event void raise_E1(int i) {
      if (_E)
         _E(i);
   }

protected:
   __event void remove_E1(f* d) {
      _E -= d;
   }
};
```

A nova sintaxe simplifica a declaração, como demonstra a conversão a seguir. Um evento especifica dois ou três métodos entre um par de chaves e colocado imediatamente após a declaração do evento e seu tipo de delegado associado, conforme mostrado aqui:

```
public delegate void f( int );
public ref struct E {
private:
   f^ _E; // delegates are also reference types

public:
   E() {  // note the replacement of 0 with nullptr!
      _E = nullptr;
   }

   // the new aggregate syntax of an explicit event declaration
   event f^ E1 {
   public:
      void add( f^ d ) {
         _E += d;
      }

   protected:
      void remove( f^ d ) {
         _E -= d;
      }

   private:
      void raise( int i ) {
         if ( _E )
            _E( i );
      }
   }

   static void Go() {
      E^ pE = gcnew E;
      pE->E1 += gcnew f( pE, &E::handler );
      pE->E1( 17 );
      pE->E1 -= gcnew f( pE, &E::handler );
      pE->E1( 17 );
   }
};
```

## <a name="see-also"></a>Consulte também

[Declarações de membro em uma classe ou interface (C++/CLI)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)<br/>
[delegate (Extensões de componentes do C++)](../windows/delegate-cpp-component-extensions.md)<br/>
[event](../windows/event-cpp-component-extensions.md)