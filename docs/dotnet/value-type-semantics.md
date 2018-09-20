---
title: Semântica de tipo de valor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- interior_ptr keyword [C++]
- virtual functions, value types
- inheritance, value types
- pinning pointers
- pin_ptr keyword [C++]
- __pin keyword
ms.assetid: 7f065589-ad25-4850-baf1-985142e35e52
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 72dc6a613616d13e9ff92e8af0c39c63dfe63162
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46413790"
---
# <a name="value-type-semantics"></a>Semântica do tipo de valor

Semântica de tipo de valor alterou de extensões gerenciadas para C++ para Visual C++.

Aqui está o tipo de valor simples canônico usado em extensões gerenciadas para especificações de C++:

```
__value struct V { int i; };
__gc struct R { V vr; };
```

Nas extensões gerenciadas, podemos ter quatro variações sintáticas de um tipo de valor (onde forms 2 e 3 são iguais semanticamente):

```
V v = { 0 };       // Form (1)
V *pv = 0;         // Form (2) an implicit form of (3)
V __gc *pvgc = 0;  // Form (3)
__box V* pvbx = 0; // Form (4) must be local
```

## <a name="invoking-inherited-virtual-methods"></a>Invocar métodos virtuais herdados

`Form (1)` é o objeto de valor canônico, e ele é razoavelmente bem compreendido, exceto quando alguém tenta invocar um método virtual herdado como `ToString()`. Por exemplo:

```
v.ToString(); // error!
```

Para invocar esse método, porque ele não seja substituído em `V`, o compilador deve ter acesso à tabela virtual associada da classe base. Como tipos de valor são o armazenamento de estado sem o ponteiro associado à sua tabela virtual (vptr), isso exige que `v` ser Demarcado. No design da linguagem extensões gerenciadas, conversão boxing implícita não tem suporte, mas deve ser especificado explicitamente pelo programador, como em

```
__box( v )->ToString(); // Managed Extensions: note the arrow
```

A principal motivação por trás desse projeto é pedagógico: mecanismo de base deve estar visível para o programador para que ela compreendam 'custo' de não fornecer uma instância dentro de seu tipo de valor. Foram `V` para conter uma instância de `ToString`, a conversão boxing não seria necessária.

A complexidade léxica de conversão boxing explicitamente o objeto, mas não o custo subjacentes da conversão boxing em si, é removida na nova sintaxe:

```
v.ToString(); // new syntax
```

mas às custas de enganoso, possivelmente, o designer de classe como o custo de não ter fornecido a uma instância explícita dos `ToString` método dentro do `V`. O motivo para preferir a conversão boxing implícita é que, embora geralmente seja apenas um designer de classe, há um número ilimitado de usuários, nenhum dos quais ele tem a liberdade para modificar `V` para eliminar a caixa explícita possivelmente onerosa.

Os critérios pelos quais determinar se deve ou não fornecer uma instância de substituição de `ToString` dentro de um valor de classe deve ser a frequência e o local dos seus usos. Se for chamado muito raramente, certamente há poucas vantagens em sua definição. Da mesma forma, se ele for chamado em áreas não funcional do aplicativo, adicioná-lo também não concretamente adicionará ao desempenho geral do aplicativo. Como alternativa, um pode manter um identificador de acompanhamento para o valor demarcado e chamadas por meio desse identificador seriam exigem conversão boxing.

## <a name="there-is-no-longer-a-value-class-default-constructor"></a>Não há um construtor padrão do valor de classe

Outra diferença com um tipo de valor entre extensões gerenciadas e a nova sintaxe é a remoção do suporte para um construtor padrão. Isso ocorre porque há ocasiões durante a execução em que o CLR pode criar uma instância do tipo de valor sem invocar o construtor padrão associado. Ou seja, a tentativa de extensões gerenciadas para dar suporte a um construtor padrão dentro de um tipo de valor pode não na prática ser garantida. Dada essa ausência de garantia, ele foi percebido seja melhor descartar o suporte completamente em vez de ela ser não determinístico no seu aplicativo.

Isso não é tão ruim quanto parece inicialmente. Isso ocorre porque cada objeto de um tipo de valor é zerado automaticamente (ou seja, cada tipo é inicializado com seu valor padrão). Como resultado, os membros de uma instância local nunca são indefinidos. Nesse sentido, a perda da capacidade de definir um construtor padrão trivial realmente não é uma perda em todos os - e na verdade é mais eficiente quando executado pelo CLR.

O problema é quando um usuário de Managed Extensions define um construtor padrão não triviais. Isso não tem mapeamento para a nova sintaxe. O código dentro do construtor precisará ser migrado para um método de inicialização nomeado que, em seguida, precisa ser chamado explicitamente pelo usuário.

Caso contrário, a declaração de um objeto de tipo de valor dentro da nova sintaxe permanece inalterada. O lado disso é que tipos de valor não são satisfatórios para o encapsulamento dos tipos nativos pelos seguintes motivos:

- Não há nenhum suporte para um destruidor dentro de um tipo de valor. Ou seja, não há nenhuma maneira de automatizar um conjunto de ações disparadas no final do tempo de vida de um objeto.

- Uma classe nativa pode estar contida dentro de um tipo gerenciado como um ponteiro que, em seguida, é alocado no heap nativo.

Gostaríamos de encapsular uma pequena classe nativa em um tipo de valor em vez de um tipo de referência para evitar uma alocação de heap duplo: o heap nativo para manter o tipo nativo e o heap de CLR para manter o wrapper gerenciado. Quebra automática de uma classe nativa dentro de um tipo de valor permite que você evite o heap gerenciado, mas não oferece nenhuma forma para automatizar a recuperação da memória heap nativo. Tipos de referência são o tipo de gerenciado for praticável de acordo apenas na qual você deseja encapsular classes nativas não triviais.

## <a name="interior-pointers"></a>Ponteiros internos

`Form (2)` e `Form (3)` acima pode tratar quase qualquer coisa do mundo ou a próxima (ou seja, tudo gerenciado ou nativo). Portanto, por exemplo, todos os itens a seguir é permitidos nas extensões gerenciadas:

```
__value struct V { int i; };
__gc struct R { V vr; };

V v = { 0 };  // Form (1)
V *pv = 0;  // Form (2)
V __gc *pvgc = 0;  // Form (3)
__box V* pvbx = 0;  // Form (4)

R* r;

pv = &v;            // address a value type on the stack
pv = __nogc new V;  // address a value type on native heap
pv = pvgc;          // we are not sure what this addresses
pv = pvbx;          // address a boxed value type on managed heap
pv = &r->vr;        // an interior pointer to value type within a
                    //    reference type on the managed heap
```

Dessa forma, um `V*` pode resolver um local dentro de um bloco local (e, portanto, pode oscilar), no escopo global, nativo de heap (por exemplo, se o objeto pertinente já foi excluído), no heap CLR (e, portanto, será monitorada se deveria ser relocado durante a coleta de lixo) e no interior de um objeto de referência no heap CLR (um ponteiro interior, como isso é chamado, é também transparentemente controlado).

Nas extensões gerenciadas, não há nenhuma maneira para separar os aspectos nativos de um `V*`; ou seja, é tratado no inclusive, que lida com a possibilidade de que se trata de um objeto ou subobjeto no heap gerenciado.

Na nova sintaxe, um ponteiro de tipo de valor é decomposto em dois tipos: `V*`, que é limitado a locais de heap não CLR e o ponteiro interior, `interior_ptr<V>`, que permite, mas não exige um endereço no heap gerenciado.

```
// may not address within managed heap
V *pv = 0;

// may or may not address within managed heap
interior_ptr<V> pvgc = nullptr;
```

`Form (2)` e `Form (3)` de Managed Extensions do mapa em `interior_ptr<V>`. `Form (4)` é um identificador de acompanhamento. Ele aborda todo o objeto que tem sido demarcado no heap gerenciado. Ele é convertido na nova sintaxe em um `V^`,

```
V^ pvbx = nullptr; // __box V* pvbx = 0;
```

As declarações a seguir em todos os mapas de ponteiros internos na nova sintaxe de extensões gerenciadas. (Elas são tipos de valor dentro de `System` namespace.)

```
Int32 *pi;   // => interior_ptr<Int32> pi;
Boolean *pb; // => interior_ptr<Boolean> pb;
E *pe;       // => interior_ptr<E> pe; // Enumeration
```

Os tipos internos não são considerados tipos gerenciados, embora eles sirvam como aliases para os tipos dentro de `System` namespace. Assim, os mapeamentos a seguir pode ocorrer entre extensões gerenciadas e a nova sintaxe:

```
int * pi;     // => int* pi;
int __gc * pi2; // => interior_ptr<int> pi2;
```

Ao converter um `V*` em seu programa existente, a estratégia mais conservadora é sempre ativá-lo um `interior_ptr<V>`. Isso é como ele foi tratado em extensões gerenciadas. Na nova sintaxe, o programador tem a opção de restringir um tipo de valor para os endereços de heap não gerenciada, especificando `V*` em vez de um ponteiro interior. Se, em traduzir seu programa, você pode fazer um fechamento transitivo de todos os seus usos e certifique-se de que nenhum endereço atribuído está no heap gerenciado, em seguida, deixando-o como `V*` tudo bem.

## <a name="pinning-pointers"></a>Ponteiros de fixação

O coletor de lixo, opcionalmente, pode passar objetos que residem no heap CLR para locais diferentes no heap, geralmente durante a fase de compactação. Essa movimentação não é um problema ao acompanhamento de identificadores, referências de monitoramento e ponteiros internos que atualizar essas entidades de forma transparente. Esse movimento é um problema, no entanto, se o usuário tiver passado o endereço de um objeto no heap CLR fora do ambiente de tempo de execução. Nesse caso, o movimento volátil do objeto é pode causar uma falha de tempo de execução. Para isolar objetos como esses desde que está sendo movido, podemos deve fixá-los localmente em seu local para a extensão de seu uso fora.

Nas extensões gerenciadas, uma *ponteiro de fixação* é declarada com uma declaração de ponteiro de qualificação a `__pin` palavra-chave. Aqui está um exemplo ligeiramente modificado da especificação de Managed Extensions:

```
__gc struct H { int j; };

int main()
{
   H * h = new H;
   int __pin * k = & h -> j;

   // ...
};
```

No novo design de linguagem, um ponteiro de fixação é declarado com sintaxe semelhante ao de um ponteiro interior.

```
ref struct H
{
public:
   int j;
};

int main()
{
   H^ h = gcnew H;
   pin_ptr<int> k = &h->j;

   // ...
}
```

Um ponteiro de fixação sob a nova sintaxe é um caso especial de um ponteiro interior. As restrições originais de um ponteiro de fixação permanecem. Por exemplo, ele não pode ser usado como um parâmetro ou tipo de retorno de um método; ela pode ser declarada somente em um objeto local. Um número de restrições adicionais, no entanto, foram adicionado na nova sintaxe.

É o valor padrão de um ponteiro de fixação `nullptr`, e não `0`. Um `pin_ptr<>` não podem ser inicializados ou atribuídos `0`. Todas as atribuições `0` no código existente precisará ser alterado para `nullptr`.

Um ponteiro de fixação em extensões gerenciadas obteve permissão para um objeto inteiro, como no exemplo a seguir, obtido da especificação de Managed Extensions de endereço:

```
__gc class G {
public:
   void incr(int* pi) { pi += 1; }
};
__gc struct H { int j; };
void f( G * g ) {
   H __pin * pH = new H;
   g->incr(& pH -> j);
};
```

Na nova sintaxe, fixação de todo o objeto retornado pelo `new` expressão não é suportada. Em vez disso, o endereço do membro interior precisa ser fixado. Por exemplo,

```
ref class G {
public:
   void incr(int* pi) { *pi += 1; }
};
ref struct H { int j; };
void f( G^ g ) {
   H ^ph = gcnew H;
   Console::WriteLine(ph->j);
   pin_ptr<int> pj = &ph->j;
   g->incr(  pj );
   Console::WriteLine(ph->j);
}
```

## <a name="see-also"></a>Consulte também

[Tipos de valor e seus comportamentos (C++/CLI)](../dotnet/value-types-and-their-behaviors-cpp-cli.md)<br/>
[Classes e Structs](../windows/classes-and-structs-cpp-component-extensions.md)<br/>
[interior_ptr (C++/CLI)](../windows/interior-ptr-cpp-cli.md)<br/>
[pin_ptr (C++/CLI)](../windows/pin-ptr-cpp-cli.md)