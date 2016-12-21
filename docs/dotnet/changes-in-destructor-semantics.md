---
title: "Altera&#231;&#245;es feitas na sem&#226;ntica do destruidor | Microsoft Docs"
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
  - "destruidores, C++"
  - "finalizadores [C++]"
ms.assetid: f1869944-a407-452f-b99a-04d8c209f0dc
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Altera&#231;&#245;es feitas na sem&#226;ntica do destruidor
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A semântica da classe para destruidores mudou significativamente de extensões gerenciadas para C\+\+ a [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)].  
  
 Em extensões gerenciadas, um destruidor da classe era permitido em uma classe de referência mas não em uma classe do valor.  Isso não foi alterado na nova sintaxe.  No entanto, a semântica de destruidor da classe foi alterada.  Este tópico destaca as razões dessa alteração e discute\-se como ela afeta a tradução de código existente do CLR.  É provável que a alteração mais importante do programador\- nível entre as duas versões de idioma.  
  
## Acabamento não determinístico  
 Antes que a memória seja associado a um objeto é recuperada pelo coletor de lixo, um método associado de `Finalize` , caso exista, é invocada.  Você pode pensar neste método como um tipo de super\- destruidor porque não está vinculado ao tempo de vida de programa do objeto.  Nós referimos isso como o acabamento.  O tempo de exatamente no momento em que ou até mesmo se um método de `Finalize` é invocado é indefinido.  Isso é o que nós significamos quando nós dizemos que a coleta de lixo exibe o acabamento não determinística.  
  
 Acabamento de trabalho não determinístico bem com gerenciamento de memória dinâmica.  Quando a memória disponível se torna escassa, o coletor de lixo retrocede em.  Em um ambiente coletado lixo, os destruidores para liberar a memória são desnecessários.  Acabamento o não determinísticas não funciona corretamente, no entanto, quando um objeto mantém um recurso crítica como uma conexão de base de dados ou um bloqueio de qualquer tipo.  Nesse caso, devemos liberar esse recurso o mais rápido possível.  No mundo nativo, que é obtido usando um par de construtor\/destruidor.  Assim que o tempo de vida do objeto terminar, enquanto o bloco local em que é declarado termina, ou quando a pilha desembaraça devido a uma exceção lançada, o destruidor é executado e os recursos são liberados automaticamente.  Essa abordagem funciona bem, e a ausência em extensões gerenciadas faltada foi gravemente.  
  
 A solução fornecida por CLR é para uma classe que implementa o método de `Dispose` da interface de `IDisposable` .  O problema é que `Dispose` aqui requer uma chamada explícita pelo usuário.  Isso está sujeito a erros.  A linguagem C\# fornece uma forma modesto de automação na forma de uma instrução especial de `using` .  O design gerenciado das extensões não forneceu nenhum suporte especial.  
  
## Destruidores em extensões gerenciadas para C\+\+  
 Em extensões gerenciadas, o destruidor de uma classe de referência é implementado usando as duas etapas a seguir:  
  
1.  O destruidor fornecido é renomeado internamente em `Finalize`.  Se a classe tiver uma classe base \(lembre\-se, no modelo de objeto CLR, somente a única herança é permitida\), o compilador injeta uma chamada à sua execução a seguir finalizadores de código fornecido pelo usuário.  Por exemplo, considere a seguinte hierarquia simples tomada gerenciado da especificação de linguagem DMX:  
  
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
  
 Neste exemplo, ambos os destruidores forem renomeados `Finalize`.  `B``Finalize` tem uma invocação de método de `A``Finalize` adicionado depois de invocação de `WriteLine`.  Isso é o que o coletor de lixo invocará por padrão durante o acabamento.  Eis como essa transformação interna poderia ser assim:  
  
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
  
1.  Na segunda etapa, o compilador sintetiza um destruidor virtual.  Este destruidor é o que nossos programas do usuário gerenciados DMX invocam diretamente ou por meio de um aplicativo da expressão de exclusão.  Nunca é invocado pelo coletor de lixo.  
  
     Duas instruções são colocadas dentro desse destruidor sintetizado.  Um é uma chamada a `GC::SuppressFinalize` para ter certeza de que não há mais invocação de `Finalize`.  O segundo é a invocação real de `Finalize`, que representa o destruidor fornecido para aquela classe.  Eis como isso poderia ser assim:  
  
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
  
 Quando essa implementação permitir que o usuário chama explicitamente o método de `Finalize` da classe agora vez de em vez você não tem nenhum controle sobre, não em que usam realmente com a solução do método de `Dispose` .  Isso é alterado em [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)].  
  
## Destruidores na nova sintaxe  
 Na nova sintaxe, o destruidor é renomeado internamente para o método de `Dispose` e a classe de referência é estendida automaticamente para implementar a interface de `IDispose` .  Ou seja, em [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)], nosso par de classes é transformado da seguinte maneira:  
  
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
  
 Quando um ou destruidor é chamado explicitamente na nova sintaxe, ou quando `delete` é aplicado a um identificador de rastreamento, o método subjacente de `Dispose` é invocado automaticamente.  Se for uma classe derivada, uma chamada de método de `Dispose` da classe base é inserido no fechamento do método sintetizado.  
  
 Mas isso não em obtém até o acabamento determinística.  Para alcançar esse, precisamos suporte adicional de objetos locais de referência. \(Isso não tem suporte análoga nas extensões gerenciadas, e assim que não é um problema de tradução.\)  
  
## Declarando um objeto de referência  
 [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)] oferece suporte à declaração de um objeto de uma classe de referência na pilha local ou como um membro de uma classe como se fosse diretamente acessíveis.  Quando combinado com a associação de destruidor com o método de `Dispose` , o resultado será a invocação automatizada de semântica de acabamento em tipos de referência.  
  
 Primeiro, é definimos nossa classe de referência de modo que a criação do objeto funciona como a aquisição de um recurso no construtor de classe.  Em segundo lugar, no destruidor da classe, é liberamos o recurso adquirido quando o objeto foi criado.  
  
```  
public ref class R {  
public:  
   R() { /* acquire expensive resource */ }  
   ~R() { /* release expensive resource */ }  
  
   // … everything else …  
};  
```  
  
 O objeto for declarado localmente usando o nome do tipo mas sem o chapéu de rastreamento.  Todos os usos do objeto, como invocar um método, foi feito pelo ponto de seleção de membro \(`.`\) em vez de seta \(`->`\).  No final do bloco, o destruidor associado, transformado em `Dispose`, é invocado automaticamente, conforme mostrado aqui:  
  
```  
void f() {  
   R r;   
   r.methodCall();  
  
   // r is automatically destructed here –  
   // that is, r.Dispose() is invoked  
}  
```  
  
 Como com a instrução de `using` no C\#, isso não provoca a restrição de CLR subjacente que todos os tipos de referência deve ser atribuídos no heap de CLR.  A semântica subjacente permanecerá inalterado.  O usuário pode ter gravado equivalente o seguinte \(e é provável que a transformação interna executada pelo compilador\):  
  
```  
// equivalent implementation  
// except that it should be in a try/finally clause  
void f() {  
   R^ r = gcnew R;   
   r->methodCall();  
  
   delete r;  
}  
```  
  
 De fato, na nova sintaxe, os destruidores emparelhados são novamente com os construtores como um mecanismo automatizado de aquisição\/versão associado ao tempo de vida de um objeto local.  
  
## Declarando um explícito finaliza  
 Na nova sintaxe, como nós, consulte o destruidor é sintetizado no método de `Dispose` .  Isso significa que quando o destruidor não será chamado explicitamente, o coletor de lixo, durante o acabamento, não como antes de localizar um método associado de `Finalize` para o objeto.  Para dar suporte à destruição e o acabamento, foi introduzida uma sintaxe especial para fornecer um finalizador.  Por exemplo:  
  
```  
public ref class R {  
public:  
   !R() { Console::WriteLine( "I am the R::finalizer()!" ); }  
};  
```  
  
 O prefixo de `!` é análogo ao til \(\)`~`que apresenta um destruidor da classe \- ou seja, ambos os métodos após o tempo de vida têm um token que prefixa o nome da classe.  Se o método sintetizado de `Finalize` ocorre em uma classe derivada, uma invocação de método de `Finalize` da classe base é inserida na extremidade.  Se o destruidor é chamado explicitamente, o finalizador será suprimido.  Eis como a transformação poderia ser assim:  
  
```  
// internal transformation under new syntax  
public ref class R {  
public:  
   void Finalize() {  
      Console::WriteLine( "I am the R::finalizer()!" );  
   }  
};   
```  
  
## Mover as extensões gerenciadas para C\+\+ a Visual C\+\+ 2010  
 O comportamento de tempo de execução de extensões gerenciadas para o programa C\+\+ é alterado quando for criado em [!INCLUDE[cpp_current_long](../Token/cpp_current_long_md.md)] sempre que uma classe de referência contém um destruidor não trivial.  O algoritmo exigido de conversão é semelhante à seguinte:  
  
1.  Se um destruidor estiver presente, a regravação que seja o finalizador da classe.  
  
2.  Se um método de `Dispose` estiver presente, a regravação do destruidor da classe.  
  
3.  Se um destruidor estiver presente mas não há nenhum método de `Dispose` , manter o destruidor ao executar o primeiro item.  
  
 Em mover seu código das extensões gerenciadas para a nova sintaxe, você pode perder executar a transformação.  Se o aplicativo dependeu de algum modo de execução de métodos associados de acabamento, o comportamento do aplicativo diferirá silenciosamente do que você pretendeu.  
  
## Consulte também  
 [Tipos gerenciados \(C\+\+\/CL\)](../dotnet/managed-types-cpp-cl.md)   
 [Destruidores e finalizadores em Visual C\+\+](../misc/destructors-and-finalizers-in-visual-cpp.md)