---
title: Representantes e eventos | Microsoft Docs
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
ms.openlocfilehash: 69e0ffcb9b9c48de152a383b4b9a3f6edbe99f42
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33108319"
---
# <a name="delegates-and-events"></a>Representantes e eventos
A maneira de declarar representantes e eventos foi alterado de extensões gerenciadas para C++ para Visual C++.  
  
 O sublinhado duplo não é mais necessário, conforme mostrado no exemplo a seguir. Aqui um código de exemplo das extensões gerenciadas:  
  
```  
__delegate void ClickEventHandler(int, double);  
__delegate void DblClickEventHandler(String*);  
  
__gc class EventSource {  
   __event ClickEventHandler* OnClick;    
   __event DblClickEventHandler* OnDblClick;    
};  
```  
  
 O mesmo código na nova sintaxe terá a seguinte aparência:  
  
```  
delegate void ClickEventHandler( int, double );  
delegate void DblClickEventHandler( String^ );  
  
ref class EventSource {  
   event ClickEventHandler^ OnClick;   
   event DblClickEventHandler^ OnDblClick;   
};  
```  
  
 Eventos (e delegados) são tipos de referência, que fica claro em nova sintaxe devido ao uso de hat (`^`).  Suporte a eventos uma sintaxe de declaração explícita e o formulário trivial mostrado no código anterior. No formulário explícito, o usuário Especifica o `add`, `raise`, e `remove` métodos associados ao evento. (Somente o `add` e `remove` métodos são necessários; o `raise` é opcional.)  
  
 Em extensões gerenciadas, se você fornecer esses métodos, você também não fornecer uma declaração explícita de evento, mas você deve escolher um nome para o evento que não está presente. Cada método é especificado no formulário `add_EventName`, `raise_EventName`, e `remove_EventName`, como no exemplo a seguir, obtido com a especificação das extensões gerenciadas:  
  
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
  
 A nova sintaxe simplifica a declaração, como a conversão a seguir demonstra. Um evento especifica dois ou três métodos entre um par de chaves e colocado imediatamente após a declaração do evento e seu tipo de delegado associado, como mostrado aqui:  
  
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
 [Declarações de membro em uma classe ou Interface (C + + CLI)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)   
 [delegado (extensões de componentes C++)](../windows/delegate-cpp-component-extensions.md)   
 [event](../windows/event-cpp-component-extensions.md)