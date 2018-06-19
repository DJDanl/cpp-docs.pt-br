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
ms.openlocfilehash: 44662f2ad8e79712b4aab17e2784a72e01ec4116
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33171843"
---
# <a name="value-type-semantics"></a>Semântica do tipo de valor
Semântica de tipo de valor foram alterados desde das extensões gerenciadas para C++ para Visual C++.  
  
 Aqui é o tipo de valor simples canônico usado nas extensões gerenciadas para especificação de C++:  
  
```  
__value struct V { int i; };  
__gc struct R { V vr; };  
```  
  
 Extensões gerenciadas, podemos pode ter quatro variações de sintaxe de um tipo de valor (onde formulários 2 e 3 são as mesmas semanticamente):  
  
```  
V v = { 0 };       // Form (1)  
V *pv = 0;         // Form (2) an implicit form of (3)  
V __gc *pvgc = 0;  // Form (3)  
__box V* pvbx = 0; // Form (4) must be local   
```  
  
## <a name="invoking-inherited-virtual-methods"></a>Chamando métodos virtuais herdados  
 `Form (1)` é o objeto de valor canônico e ele é razoavelmente bem compreendido, exceto quando alguém tenta chamar um método virtual herdado como `ToString()`. Por exemplo:  
  
```  
v.ToString(); // error!  
```  
  
 Para invocar esse método, porque ele não for substituído em `V`, o compilador deve ter acesso à tabela virtual associada da classe base. Como tipos de valor estiverem no estado de armazenamento sem o ponteiro associado à sua tabela virtual (vptr), isso exige que `v` ser Demarcado. No design da linguagem das extensões gerenciadas, conversão boxing implícita não tem suporte mas deve ser especificado explicitamente pelo programador, como em  
  
```  
__box( v )->ToString(); // Managed Extensions: note the arrow  
```  
  
 A principal motivação por trás desse projeto é pedagógico, pois: mecanismo de base deve ser visível para o programador para que ela compreendam 'custo' não fornecer uma instância em seu tipo de valor. Foram `V` para conter uma instância de `ToString`, a conversão não é necessário.  
  
 A complexidade lexical de boxing explicitamente o objeto, mas não o custo subjacente de conversão de boxing, é removida a nova sintaxe:  
  
```  
v.ToString(); // new syntax  
```  
  
 mas às custas de enganar possivelmente o designer de classe quanto o custo de não ter fornecido a uma instância explícita do `ToString` método dentro de `V`. O motivo para preferência a conversão boxing implícita é que, embora normalmente não há apenas um designer de classe, há um número ilimitado de usuários, nenhum dos quais tem a liberdade de modificar `V` para eliminar a caixa explícita possivelmente onerosa.  
  
 Os critérios pelos quais determinar se deve ou não fornecer uma substituição de instância de `ToString` dentro de um valor de classe deve ser a frequência e o local dos seus usos. Se for chamado muito raramente, obviamente há pouco benefício em sua definição. Da mesma forma, se ele é chamado em áreas não funcionais do aplicativo, adicioná-lo também concretamente não adicionará o desempenho geral do aplicativo. Como alternativa, um pode manter um identificador de acompanhamento para o valor demarcado e chamadas esse identificador não requer conversão boxing.  
  
## <a name="there-is-no-longer-a-value-class-default-constructor"></a>Não é mais um construtor padrão do valor de classe  
 Outra diferença com um tipo de valor entre extensões gerenciadas e a nova sintaxe é a remoção de suporte para um construtor padrão. Isso ocorre porque existem ocasiões durante a execução em que o CLR pode criar uma instância do tipo de valor sem chamar o construtor padrão associado. Ou seja, a tentativa de extensões gerenciadas para dar suporte a um construtor padrão dentro de um tipo de valor pode não na prática ser garantida. Considerando que ausência de garantia, foi era melhor remover o suporte totalmente em vez de ela ser não determinístico no seu aplicativo.  
  
 Isso não é tão ruim quanto pode parecer inicialmente. Isso ocorre porque cada objeto de um tipo de valor é zerado automaticamente (ou seja, cada tipo é inicializado para seu valor padrão). Como resultado, os membros de uma instância local nunca são indefinidos. Nesse sentido, a perda da capacidade de definir um construtor padrão trivial não é uma perda de todo - e na verdade é mais eficiente quando executada pelo CLR.  
  
 O problema é quando um usuário do Managed Extensions define um construtor padrão não trivial. Isso não tem nenhum mapeamento para a nova sintaxe. O código dentro do construtor precisará ser migrado para um método de inicialização nomeado que precisaria ser chamado explicitamente pelo usuário.  
  
 Caso contrário, não a declaração de um objeto de tipo de valor dentro a nova sintaxe é alterada. O lado disso é que tipos de valor não são satisfatórios para a disposição dos tipos nativos pelos seguintes motivos:  
  
-   Não há nenhum suporte para um destruidor dentro de um tipo de valor. Ou seja, não há nenhuma maneira de automatizar um conjunto de ações disparadas até o final do tempo de vida de um objeto.  
  
-   Uma classe nativo pode ser contida dentro de um tipo gerenciado como um ponteiro que, em seguida, é alocado no heap nativo.  
  
 Gostaríamos de encapsular uma pequena classe nativo em um tipo de valor em vez de um tipo de referência para evitar uma alocação de heap duplo: o heap nativo para manter o tipo nativo e o heap de CLR para manter o wrapper gerenciado. Quebra automática de uma classe nativa dentro de um tipo de valor permite que você evite o heap gerenciado, mas não oferece nenhuma forma para automatizar a recuperação da memória heap nativo. Tipos de referência são o tipo de gerenciado for praticável de acordo somente dentro do qual quebrar classes nativas não trivial.  
  
## <a name="interior-pointers"></a>Ponteiros internos  
 `Form (2)` e `Form (3)` acima pode abordar praticamente qualquer coisa no mundo ou a próxima (ou seja, qualquer conteúdo gerenciado ou nativo). Assim, por exemplo, todos os itens a seguir é permitidas em extensões gerenciadas:  
  
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
  
 Portanto, um `V*` pode abordar um local dentro de um bloco de local (e, portanto, pode ser pendente), no escopo global, nativo do heap (por exemplo, se o objeto que ele trata já foi excluído), dentro do heap CLR (e, portanto, serão rastreadas se deveria ser realocados durante a coleta de lixo) e dentro de um objeto de referência no heap CLR (um ponteiro interior, como isso é chamado, é também controlado).  
  
 Em extensões gerenciadas, não é possível separar os aspectos nativo de um `V*`; ou seja, ele será tratado em inclusive, que trata a possibilidade de que um objeto ou subobjeto no heap gerenciado de endereçamento.  
  
 Na nova sintaxe, um ponteiro de tipo de valor é acrescentado em dois tipos: `V*`, que é limitado a locais de heap de não CLR e o ponteiro interior, `interior_ptr<V>`, que permite, mas não requer um endereço no heap gerenciado.  
  
```  
// may not address within managed heap   
V *pv = 0;   
  
// may or may not address within managed heap  
interior_ptr<V> pvgc = nullptr;   
```  
  
 `Form (2)` e `Form (3)` das extensões gerenciadas do mapa em `interior_ptr<V>`. `Form (4)` é um identificador de rastreamento. Ele aborda o objeto inteiro tiver sido demarcado no heap gerenciado. Ele é convertido em nova sintaxe em uma `V^`,  
  
```  
V^ pvbx = nullptr; // __box V* pvbx = 0;    
```  
  
 As seguintes declarações em todos os mapas de ponteiros internos na nova sintaxe do Managed Extensions. (São tipos de valor dentro do `System` namespace.)  
  
```  
Int32 *pi;   // => interior_ptr<Int32> pi;  
Boolean *pb; // => interior_ptr<Boolean> pb;  
E *pe;       // => interior_ptr<E> pe; // Enumeration  
```  
  
 Os tipos internos não são considerados tipos gerenciados, embora eles servem como aliases para os tipos de dentro do `System` namespace. Portanto, os seguintes mapeamentos verdadeiras entre extensões gerenciadas e a nova sintaxe:  
  
```  
int * pi;     // => int* pi;  
int __gc * pi2; // => interior_ptr<int> pi2;  
```  
  
 Ao converter uma `V*` em seu programa existente, a estratégia mais conservadora é sempre ativá-lo um `interior_ptr<V>`. Isso é como ele foi tratado em extensões gerenciadas. A nova sintaxe, o programador tem a opção de restringir um tipo de valor a endereços de heap gerenciado não especificando `V*` em vez de um ponteiro interior. Se, em converter seu programa, você pode fazer um fechamento transitivo de todos os seus usos e certifique-se de que nenhum endereço atribuído está dentro do heap gerenciado, em seguida, deixando-o como `V*` é bom.  
  
## <a name="pinning-pointers"></a>Fixando ponteiros  
 O coletor de lixo opcionalmente pode mover objetos que residem no heap CLR para locais diferentes no heap, geralmente durante a fase de compactação. Essa movimentação não é um problema para o rastreamento dos identificadores, referências de acompanhamento e ponteiros internos que atualizar essas entidades de forma transparente. Essa movimentação é um problema, no entanto, se o usuário tiver passado o endereço de um objeto no heap CLR fora do ambiente de tempo de execução. Nesse caso, a movimentação volátil do objeto é pode causar uma falha de tempo de execução. Para isolar objetos como estes sejam movidas, podemos deve fixá-los localmente para o local para a extensão de uso externo.  
  
 Em extensões gerenciadas, um *ponteiro de fixação* é declarado qualificando uma declaração de ponteiro com o `__pin` palavra-chave. Aqui está um exemplo ligeiramente modificado da especificação das extensões gerenciadas:  
  
```  
__gc struct H { int j; };  
  
int main()   
{  
   H * h = new H;  
   int __pin * k = & h -> j;  
  
   // ...  
};  
```  
  
 No novo design de linguagem, um ponteiro de fixação foi declarado com sintaxe semelhante ao de um ponteiro interior.  
  
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
  
 Um ponteiro de fixação sob a nova sintaxe é um caso especial de um ponteiro interior. As restrições originais em um ponteiro de fixação permanecem. Por exemplo, ele não pode ser usado como um parâmetro ou tipo de retorno de um método; ele pode ser declarado apenas em um objeto local. Um número de restrições adicionais, no entanto, foram adicionado a nova sintaxe.  
  
 É o valor padrão de um ponteiro de fixação `nullptr`, não `0`. Um `pin_ptr<>` não pode ser inicializado ou atribuído `0`. Todas as atribuições de `0` no código existente precisa ser alterado para `nullptr`.  
  
 Um ponteiro de fixação em extensões gerenciadas obteve permissão para atender a um objeto inteiro, como no exemplo a seguir obtido a especificação das extensões gerenciadas:  
  
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
  
 Na sintaxe de novo, fixação de todo o objeto retornado pelo `new` não há suporte para a expressão. Em vez disso, o endereço do membro interior precisa ser fixado. Por exemplo,  
  
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
 [Tipos de valor e seus comportamentos (C + + CLI)](../dotnet/value-types-and-their-behaviors-cpp-cli.md)   
 [Classes e structs](../windows/classes-and-structs-cpp-component-extensions.md)   
 [interior_ptr (C + + CLI)](../windows/interior-ptr-cpp-cli.md)   
 [pin_ptr (C++/CLI)](../windows/pin-ptr-cpp-cli.md)