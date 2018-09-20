---
title: Alterações na semântica do destruidor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- finalizers [C++]
- destructors, C++
ms.assetid: f1869944-a407-452f-b99a-04d8c209f0dc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: c25045291afed1e8072867ee668716b2f396ef30
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46420017"
---
# <a name="changes-in-destructor-semantics"></a>Alterações feitas na semântica do destruidor

Semântica para os destruidores de classe alterou significativamente de extensões gerenciadas para C++ para Visual C++.

Nas extensões gerenciadas, um destruidor de classe era permitido dentro de uma classe de referência, mas não dentro de uma classe de valor. Isso não foi alterado na nova sintaxe. No entanto, a semântica do destruidor de classe foram alterados. Este tópico enfoca os motivos do que alterar e discute como ela afeta a tradução do código existente do CLR. Provavelmente é a alteração do nível do programador mais importante entre as duas versões da linguagem.

## <a name="non-deterministic-finalization"></a>Finalização determinística

Antes que a memória associada a um objeto seja recuperada pelo coletor de lixo, um associado `Finalize` método, se presente, é invocado. Você pode pensar esse método como um tipo de superdestruidor porque ele não está ligado ao tempo de vida de programa do objeto. Chamamos isso de finalização. O tempo de apenas quando ou até mesmo se um `Finalize` método é invocado é indefinido. Esse é o que queremos dizer quando dizemos que a coleta de lixo exibirá a finalização não-determinística.

Finalização determinística não funciona bem com o gerenciamento de memória dinâmica. Quando a memória disponível se torna escassa, o coletor de lixo é ativado. Em um lixo coletado ambiente, os destruidores para liberar memória são desnecessários. Finalização não-determinística não funciona bem, no entanto, quando um objeto mantiver um recurso crítico, como uma conexão de banco de dados ou um bloqueio de algum tipo. Nesse caso, podemos deve liberar esse recurso assim que possível. No mundo nativo, que é obtido usando um par de construtor/destruidor. Assim que o tempo de vida do objeto termina, quando termina o bloco local no qual ela é declarada, ou quando a pilha unravels devido a uma exceção lançada, o destruidor é executado e o recurso é liberado automaticamente. Essa abordagem funciona muito bem, e sua ausência em extensões gerenciadas foi muito sentida.

A solução fornecida pelo CLR é uma classe implementar o `Dispose` método da `IDisposable` interface. O problema aqui é que `Dispose` requer uma invocação explícita pelo usuário. Isso está sujeito a erros. A linguagem c# fornece uma forma modesta de automação na forma de um especial `using` instrução. O design de extensões gerenciadas não ofereciam nenhum suporte especial.

## <a name="destructors-in-managed-extensions-for-c"></a>Destruidores em extensões gerenciadas para C++

Nas extensões gerenciadas, o destruidor de uma classe de referência é implementado por meio de duas etapas a seguir:

1. O destruidor fornecido pelo usuário é renomeado internamente como `Finalize`. Se a classe tiver uma classe base (Lembre-se, no modelo de objeto CLR, somente a herança única é suportada), o compilador injeta uma chamada para seu finalizador após a execução do código fornecido pelo usuário. Por exemplo, considere a seguinte hierarquia simple obtida da especificação da linguagem extensões gerenciadas:

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

Neste exemplo, ambos os destruidores são renomeados `Finalize`. `B`do `Finalize` tem uma invocação de `A`do `Finalize` método adicionado após a invocação de `WriteLine`. Esse é o que o coletor de lixo por padrão invocará durante a finalização. Aqui está o que essa transformação interna pode parecer com:

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

1. Na segunda etapa, o compilador sintetiza um destruidor virtual. Esse destruidor é o que nossos programas de usuário de Managed Extensions invocar diretamente ou através de um aplicativo da expressão de exclusão. Ele nunca é chamado pelo coletor de lixo.

     Duas instruções são colocadas dentro esse destruidor sintetizado. Um é uma chamada para `GC::SuppressFinalize` para certificar-se de que não há nenhum mais invocações de `Finalize`. O segundo é a invocação real de `Finalize`, que representa o destruidor fornecido pelo usuário para essa classe. Aqui está o que isso pode parecer com:

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

Embora essa implementação permite que o usuário invocar explicitamente a classe `Finalize` método agora em vez de cada vez que você não tem controle sobre, ele realmente está ligada com a `Dispose` solução de método. Isso é alterado no Visual C++.

## <a name="destructors-in-new-syntax"></a>Destruidores na nova sintaxe

Na nova sintaxe, o destruidor foi renomeado internamente como a `Dispose` método e a classe de referência foi estendida automaticamente para implementar o `IDispose` interface. Ou seja, no Visual C++, nosso par de classes é transformado da seguinte maneira:

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

Quando um destruidor é invocado explicitamente em nova sintaxe, ou quando `delete` é aplicado a um identificador de acompanhamento, subjacente `Dispose` método é invocado automaticamente. Se ele é uma classe derivada, uma chamada a `Dispose` método da classe base é inserido na conclusão do método sintetizado.

Mas isso não obtém nos até a finalização determinística. Para atingir que, é necessário o suporte adicional de objetos de referência local. (Isso tem suporte análogo em extensões gerenciadas, e portanto, não é um problema de conversão.)

## <a name="declaring-a-reference-object"></a>Declarar um objeto de referência

Visual C++ oferece suporte a declaração de um objeto de uma classe de referência na pilha local ou como um membro de uma classe como se estivesse diretamente acessível. Quando combinado com a associação do destruidor com o `Dispose` método, o resultado é a invocação automatizada da semântica de finalização em tipos de referência.

Primeiro, definimos nossa classe de referência, de modo que a criação do objeto funciona como a aquisição de um recurso por meio de seu construtor de classe. Em segundo lugar, em que o destruidor da classe, lançamos o recurso adquirido quando o objeto foi criado.

```
public ref class R {
public:
   R() { /* acquire expensive resource */ }
   ~R() { /* release expensive resource */ }

   // everything else...
};
```

O objeto for declarado localmente usando o nome do tipo, mas sem o chapéu que acompanha este artigo. Todos os usos do objeto, como invocar um método, são feitos por meio do ponto de seleção de membro (`.`) em vez de seta (`->`). No final do bloco, o destruidor associado, transformado em `Dispose`, é invocado automaticamente, conforme mostrado aqui:

```
void f() {
   R r;
   r.methodCall();

   // r is automatically destructed here -
   // that is, r.Dispose() is invoked
}
```

Assim como acontece com o `using` instrução dentro do c#, isso não enfrente a restrição CLR subjacente que todos os tipos de referência deve ser alocado no heap CLR. A semântica subjacente permanece inalterada. O usuário ainda poderia ter escrito o seguinte (e esse é provavelmente a transformação interna executada pelo compilador):

```
// equivalent implementation
// except that it should be in a try/finally clause
void f() {
   R^ r = gcnew R;
   r->methodCall();

   delete r;
}
```

Na verdade, sob a nova sintaxe, os destruidores são novamente emparelhados com os construtores como uma aquisição/liberação automatizada mecanismo vinculado ao tempo de vida do objeto de um local.

## <a name="declaring-an-explicit-finalize"></a>Declarando um Finalize explícita

A nova sintaxe, como vimos, o destruidor é sintetizado no `Dispose` método. Isso significa que quando o destruidor não é invocado explicitamente, o coletor de lixo durante a finalização, não como antes encontrará um associado `Finalize` método para o objeto. Para dar suporte a destruição e finalização, apresentamos uma sintaxe especial para fornecer um finalizador. Por exemplo:

```
public ref class R {
public:
   !R() { Console::WriteLine( "I am the R::finalizer()!" ); }
};
```

O `!` prefixo é análogo ao til (`~`) que apresenta um destruidor de classe – ou seja, os dois métodos de tempo de pós-vida de têm um token prefixando o nome da classe. Se o sintetizada `Finalize` método ocorre dentro de uma classe derivada, uma invocação de classe base `Finalize` método é inserido no final. Se o destruidor for explicitamente invocado, o finalizador será suprimido. Aqui está o que a transformação pode parecer com:

```
// internal transformation under new syntax
public ref class R {
public:
   void Finalize() {
      Console::WriteLine( "I am the R::finalizer()!" );
   }
};
```

## <a name="moving-from-managed-extensions-for-c-to-visual-c-2010"></a>Movimentação de extensões gerenciadas para C++ para Visual C++ 2010

O comportamento de tempo de execução de extensões gerenciadas de programa do C++ é alterado quando ele é compilado no Visual C++ sempre que uma classe de referência contém um destruidor não trivial. O algoritmo de tradução necessária é semelhante ao seguinte:

1. Se houver um destruidor, reescreva que, para ser o finalizador da classe.

1. Se um `Dispose` método estiver presente, reescrever que no destruidor da classe.

1. Se um destruidor estiver presente, mas não há nenhum `Dispose` método, manter o destruidor ao executar o primeiro item.

Para mover seu código de extensões gerenciadas para a nova sintaxe, você poderá perder a realizar essa transformação. Se o aplicativo depende de alguma forma a execução de métodos de finalização associados, o comportamento do aplicativo será silenciosamente diferente daquele que você pretendia.

## <a name="see-also"></a>Consulte também

[Tipos gerenciados (C++ /CLI CL)](../dotnet/managed-types-cpp-cl.md)<br/>
[Destruidores e finalizadores em como: definir e consumir classes e estruturas (C + + / CLI)](../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers)