---
title: "Representantes e eventos | Microsoft Docs"
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
helpviewer_keywords: 
  - "Palavra-chave __delegate"
  - "Palavra-chave __event [C++]"
  - "palavra-chave delegate [C++]"
  - "delegados [C++], atualizando a partir das Extensões Gerenciadas para C++"
  - "palavra-chave event [C++]"
  - "eventos [C++], atualizando a partir das Extensões Gerenciadas para C++"
ms.assetid: 3505c626-7e5f-4492-a947-0e2248f7b84a
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Representantes e eventos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A maneira como declarar e delegados eventos foi alterada de extensões gerenciadas para C\+\+ a [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)].  
  
 O sublinhado vezes não é mais necessário, conforme mostrado no exemplo a seguir.  É um código de exemplo em extensões gerenciadas:  
  
```  
__delegate void ClickEventHandler(int, double);  
__delegate void DblClickEventHandler(String*);  
  
__gc class EventSource {  
   __event ClickEventHandler* OnClick;    
   __event DblClickEventHandler* OnDblClick;    
};  
```  
  
 O mesmo código na nova sintaxe seguinte aparência:  
  
```  
delegate void ClickEventHandler( int, double );  
delegate void DblClickEventHandler( String^ );  
  
ref class EventSource {  
   event ClickEventHandler^ OnClick;   
   event DblClickEventHandler^ OnDblClick;   
};  
```  
  
 Os eventos \(e\) são delegados tipos de referência, que é claro na nova sintaxe devido ao uso de chapéu \(`^`\).  Os eventos dão suporte a uma sintaxe de declaração explícita e o formulário trivial mostrados no código anterior.  No formato explícito, o usuário especifica `add`, `raise`, e os métodos de `remove` associados ao evento. \(Somente os métodos de `add` e de `remove` são necessários; o método de `raise` é opcional.\)  
  
 Em extensões gerenciadas, se você fornecer esses métodos, você também não fornece uma declaração explícita de evento, mas você deve decidir sobre um nome para o evento que não está presente.  Cada método é especificado no formato `add_EventName`, `raise_EventName`, e `remove_EventName`, como no exemplo a seguir extraído da especificação gerenciado de extensões:  
  
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
  
 A nova sintaxe simplifica a declaração, porque a seguir demonstra tradução.  Um evento especifica os dois ou três métodos incluídos em um par de chaves e colocados imediatamente depois de declaração de evento e em seu tipo associado de delegação, como mostrado a seguir:  
  
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
  
## Consulte também  
 [Declarações de membro em uma classe ou uma interface \(C\+\+\/CLI\)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)   
 [delegado](../windows/delegate-cpp-component-extensions.md)   
 [event](../windows/event-cpp-component-extensions.md)