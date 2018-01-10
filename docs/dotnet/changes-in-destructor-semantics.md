---
title: "Alterações na semântica do destruidor | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- finalizers [C++]
- destructors, C++
ms.assetid: f1869944-a407-452f-b99a-04d8c209f0dc
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: c85ac0b082e8ea1dfbff007a68061e6a286390cd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="changes-in-destructor-semantics"></a>Alterações feitas na semântica do destruidor
Semântica de destruidores da classe foram alterados significativamente desde das extensões gerenciadas para C++ para Visual C++.  
  
 No Managed Extensions, um destruidor de classe era permitido dentro de uma classe de referência, mas não dentro de uma classe de valor. Isso não foi alterado na sintaxe de novo. No entanto, a semântica do destruidor classe foram alterados. Este tópico aborda os motivos que altere e discute como ela afeta a conversão de código existente do CLR. Provavelmente é a alteração de nível de programador mais importante entre as duas versões do idioma.  
  
## <a name="non-deterministic-finalization"></a>Finalização determinística  
 Antes da memória associada a um objeto é recuperada pelo coletor de lixo, associado `Finalize` método, se presente, é invocado. Você pode pensar este método como um tipo de destruidor super porque ele não está ligado ao tempo de vida de programa do objeto. Chamamos isso finalização. O tempo de apenas quando ou até mesmo se um `Finalize` método é invocado é indefinido. Este é o que significa dizer que a coleta de lixo exibirá finalização determinística.  
  
 Finalização determinística não funciona bem com o gerenciamento de memória dinâmica. Quando a memória disponível fica escassa, o coletor de lixo é ativado. Em um lixo coletado ambiente, destruidores para liberar memória são desnecessários. Finalização determinística não não funcionam bem, no entanto, quando um objeto mantiver um recurso crítico, como uma conexão de banco de dados ou um bloqueio de algum tipo. Nesse caso, estamos deve liberar esse recurso assim que possível. No mundo nativo, que é obtida usando um par de construtor/destruidor. Assim que o tempo de vida do objeto termina, quando termina o bloco local no qual ela é declarada, ou quando a pilha unravels devido a uma exceção lançada, o destruidor é executado e o recurso é liberado automaticamente. Essa abordagem funciona muito bem, e sua ausência em extensões gerenciadas muita foi perdida.  
  
 A solução fornecida pelo CLR é uma classe implementar o `Dispose` método o `IDisposable` interface. O problema aqui é que `Dispose` requer uma invocação explícita do usuário. Isso é propenso a erros. A linguagem c# fornece um formulário simples de automação na forma de um especial `using` instrução. O design das extensões gerenciadas fornecido sem suporte especial.  
  
## <a name="destructors-in-managed-extensions-for-c"></a>Destruidores nas extensões gerenciadas para C++  
 Em extensões gerenciadas, o destruidor de uma classe de referência é implementado por meio de duas etapas a seguir:  
  
1.  O destruidor fornecido pelo usuário é renomeado internamente como `Finalize`. Se a classe tiver uma classe base (Lembre-se, no modelo de objeto CLR, há suporte somente a herança única), o compilador injeta uma chamada para seu finalizador após a execução do código fornecido pelo usuário. Por exemplo, considere a seguinte hierarquia simple obtida da especificação de linguagem das extensões gerenciadas:  
  
```  
__gc class A {  
public:  
   ~A() { Console::WriteLine(S"in ~A"); }  
};  
  
__gc class B : public A {  
public:  
   ~B() { Console::WriteLine(S"in ~B");  }  
};  
```  
  
 Neste exemplo, ambos os destruidores são renomeados `Finalize`. `B`do `Finalize` tem uma chamada de `A`do `Finalize` método adicionado após a invocação de `WriteLine`. Este é o que o coletor de lixo por padrão invocará durante a finalização. Aqui está a aparência essa transformação interna:  
  
```  
// internal transformation of destructor under Managed Extensions  
__gc class A {  
public:  
   void Finalize() { Console::WriteLine(S"in ~A"); }  
};  
  
__gc class B : public A {  
public:  
   void Finalize() {   
      Console::WriteLine(S"in ~B");  
      A::Finalize();   
   }  
};  
```  
  
1.  Na segunda etapa, o compilador sintetiza um destruidor virtual. Este destruidor é o que nossos programas de usuário das extensões gerenciadas invocar diretamente ou através de um aplicativo da expressão de exclusão. Ele nunca será chamado pelo coletor de lixo.  
  
     Duas instruções são colocadas dentro este destruidor sintetizada. Um é uma chamada para `GC::SuppressFinalize` para certificar-se de que não há nenhuma mais invocações de `Finalize`. A segunda é chamada real de `Finalize`, que representa o destruidor fornecido pelo usuário para essa classe. Aqui está essa aparência:  
  
```  
__gc class A {  
public:  
   virtual ~A() {  
      System::GC::SuppressFinalize(this);  
      A::Finalize();  
   }  
};  
  
__gc class B : public A {  
public:  
   virtual ~B() {  
      System::GC::SuppressFinalize(this);  
      B::Finalize();  
   }  
};  
```  
  
 Embora essa implementação permite que o usuário chamar explicitamente a classe `Finalize` método agora, em vez de em um momento você não tem controle sobre, ele não realmente associa com o `Dispose` solução de método. Isso é alterado no Visual C++.  
  
## <a name="destructors-in-new-syntax"></a>Destruidores na nova sintaxe  
 A nova sintaxe, o destruidor é renomeado internamente como o `Dispose` método e a classe de referência é estendido automaticamente para implementar o `IDispose` interface. Isto é, em Visual C++, nosso par de classes é transformado da seguinte maneira:  
  
```  
// internal transformation of destructor under the new syntax  
__gc class A : IDisposable {  
public:  
   void Dispose() {   
      System::GC::SuppressFinalize(this);  
      Console::WriteLine( "in ~A");  
   }  
};  
  
__gc class B : public A {  
public:  
   void Dispose() {   
      System::GC::SuppressFinalize(this);  
      Console::WriteLine( "in ~B");    
      A::Dispose();   
   }  
};  
```  
  
 Quando um destruidor é invocado explicitamente em nova sintaxe, ou quando `delete` é aplicado a um identificador de rastreamento, subjacente `Dispose` método é invocado automaticamente. Se é uma classe derivada, uma chamada do `Dispose` método da classe base é inserido na conclusão do método sintetizado.  
  
 Mas isso não nos para finalização determinística. Para alcançar que, é necessário o suporte adicional de objetos de referência local. (Isso tem suporte análogo dentro das extensões gerenciadas, e portanto não é um problema de conversão).  
  
## <a name="declaring-a-reference-object"></a>Declarando um objeto de referência  
 Visual C++ dá suporte a declaração de um objeto de uma classe de referência na pilha local ou como um membro de uma classe como se estivesse diretamente acessível. Quando combinado com a associação do destruidor com o `Dispose` método, o resultado é a invocação automatizada de semântica de finalização em tipos de referência.  
  
 Primeiro, definimos nossa classe de referência, de modo que a criação do objeto funciona como a aquisição de um recurso por meio de seu construtor de classe. Em segundo lugar, no destruidor da classe, lançamos o recurso adquirido quando o objeto foi criado.  
  
```  
public ref class R {  
public:  
   R() { /* acquire expensive resource */ }  
   ~R() { /* release expensive resource */ }  
  
   // everything else...  
};  
```  
  
 O objeto for declarado localmente usando o nome do tipo, mas sem o hat fornecido. Todos os usos do objeto, como chamar um método, são feitos por meio do ponto de seleção de membro (`.`) em vez de seta (`->`). No final do bloco, o destruidor associado, transformado em `Dispose`, é chamado automaticamente, conforme mostrado aqui:  
  
```  
void f() {  
   R r;   
   r.methodCall();  
  
   // r is automatically destructed here -  
   // that is, r.Dispose() is invoked  
}  
```  
  
 Assim como acontece com o `using` instrução em c#, isso não enfrente a restrição CLR subjacente que todos os tipos de referência deve ser alocado no heap CLR. A semântica subjacente permanece inalterada. O usuário ainda poderia ter escrito o seguinte (e isso provavelmente é a transformação interna executada pelo compilador):  
  
```  
// equivalent implementation  
// except that it should be in a try/finally clause  
void f() {  
   R^ r = gcnew R;   
   r->methodCall();  
  
   delete r;  
}  
```  
  
 Na verdade, sob a nova sintaxe, destruidores são novamente emparelhados com os construtores como uma automatizado de aquisição/liberação mecanismo ligado ao tempo de vida do objeto de um local.  
  
## <a name="declaring-an-explicit-finalize"></a>Declarando um Finalize explícita  
 A nova sintaxe, como vimos, o destruidor é sintetizado no `Dispose` método. Isso significa que quando o destruidor não for chamado explicitamente, o coletor de lixo, durante a finalização, não como antes Localize um tipo de `Finalize` método do objeto. Para dar suporte a destruição e finalização, apresentamos uma sintaxe especial para fornecer um finalizador. Por exemplo:  
  
```  
public ref class R {  
public:  
   !R() { Console::WriteLine( "I am the R::finalizer()!" ); }  
};  
```  
  
 O `!` prefixo é análogo a til (`~`) que introduz um destruidor de classe - ou seja, os dois métodos posteriores à vida útil tem um token prefixando o nome da classe. Se o sintetizada `Finalize` método ocorre dentro de uma classe derivada, uma invocação da classe base `Finalize` método é inserido no final. Se o destruidor for explicitamente invocado, o finalizador será suprimido. Aqui está o que a transformação pode parecer com:  
  
```  
// internal transformation under new syntax  
public ref class R {  
public:  
   void Finalize() {  
      Console::WriteLine( "I am the R::finalizer()!" );  
   }  
};   
```  
  
## <a name="moving-from-managed-extensions-for-c-to-visual-c-2010"></a>Movendo de extensões gerenciadas para C++ para Visual C++ 2010  
 O comportamento de tempo de execução das extensões gerenciadas para programa C++ é alterado quando ele é compilado em Visual C++, sempre que uma classe de referência contiver um destruidor não trivial. O algoritmo de tradução necessária é semelhante ao seguinte:  
  
1.  Se houver um destruidor, reescreva para o finalizador da classe.  
  
2.  Se um `Dispose` método estiver presente, reescrever que no destruidor da classe.  
  
3.  Se houver um destruidor mas não há nenhum `Dispose` método, manter o destruidor ao executar o primeiro item.  
  
 Para mover seu código de extensões gerenciadas para a nova sintaxe, você poderá perder a realizar essa transformação. Se o aplicativo depende de alguma forma, a execução de métodos de finalização associado, o comportamento do aplicativo serão silenciosamente diferentes daquele que você pretendia.  
  
## <a name="see-also"></a>Consulte também  
 [Tipos gerenciados (C + + CL)](../dotnet/managed-types-cpp-cl.md)   
 [Destruidores e finalizadores em como: definir e consumir classes e estruturas (C + + CLI)](../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers)