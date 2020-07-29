---
title: Protótipos de função
ms.date: 11/04/2016
helpviewer_keywords:
- function prototypes
- function return types, function prototypes
- data types [C], function return types
- functions [C], return types
- prototypes [C++], function
ms.assetid: d152f8e6-971e-432c-93ca-5a91400653c2
ms.openlocfilehash: 76e8abdaa2e2d0d8ba14209b45982b6a7f63f2e4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227849"
---
# <a name="function-prototypes"></a>Protótipos de função

Uma declaração de função precede a definição de função e especifica o nome, o tipo de retorno, a classe de armazenamento e os outros atributos de uma função. Para ser um protótipo, a declaração de função também deve estabelecer os tipos e identificadores dos argumentos da função.

## <a name="syntax"></a>Sintaxe

*declaração*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaração-especificadores* *atributo-Seq*<sub>opt</sub> *init-Declaration-List*<sub>opt</sub> **;**

/\**atributo-Seq*<sub>opt</sub> é específico da Microsoft\*/

*declaration-specifiers*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*storage-class-specifier* *declaration-specifiers*<sub>opt</sub> <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-specifier* *declaration-specifiers*<sub>opt</sub> <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-qualifier* *declaration-specifiers*<sub>opt</sub>

*init-declarator-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*init-Declarador*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*init-declarator-List*  **,**  *init-declarator*

*init-Declarador*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador* **=** *inicializador*

*Declarador*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*pointer*<sub>opt</sub> *direct-declarator*

*Declarador direto*:/ \* um Declarador de função\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;Declarador *direto***(***tipo de parâmetro-lista***)**   / \* Declarador de novo estilo      \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador direto***(***opção identificador-lista*<sub>opt</sub> **)**  / \* Declarador de estilo obsoleto    \*/

O protótipo tem o mesmo formato que a definição de função, exceto que é ele é encerrado por um ponto-e-vírgula imediatamente depois do parêntese de fechamento e, portanto, não tem corpo. Em ambos os casos, o tipo de retorno deve concordar com o tipo de retorno especificado na definição de função.

Os protótipos de função têm os seguintes usos importantes:

- Eles estabelecem o tipo de retorno para funções que retornam tipos diferentes de **`int`** . Embora as funções que retornam **`int`** valores não exijam protótipos, os protótipos são recomendados.

- Sem protótipos completos, as conversões padrão são feitas, mas nenhuma tentativa será feita para verificar o tipo ou o número de argumentos com o número de parâmetros.

- Os protótipos são usados para inicializar ponteiros para as funções antes que essas funções sejam definidas.

- A lista de parâmetros é usada para verificar a correspondência de argumentos na chamada de função com os parâmetros na definição de função.

O tipo convertido de cada parâmetro determina a interpretação dos argumentos que a chamada de função coloca na pilha. Uma incompatibilidade entre um argumento e um parâmetro pode fazer com que os argumentos na pilha sejam interpretados incorretamente. Por exemplo, em um computador de 16 bits, se um ponteiro de 16 bits for passado como um argumento e, em seguida, declarado como um **`long`** parâmetro, os primeiros 32 bits na pilha serão interpretados como um **`long`** parâmetro. Esse erro cria problemas não apenas com o **`long`** parâmetro, mas com quaisquer parâmetros que o seguem. Você pode detectar erros desse tipo declarando protótipos de função completos para todas as funções.

Um protótipo estabelece os atributos de uma função de forma que as chamadas para a função que precedem sua definição (ou ocorrem em outros arquivos de origem) possam ser verificadas quanto a incompatibilidades de tipo de argumento e de retorno. Por exemplo, se você especificar o **`static`** especificador de classe de armazenamento em um protótipo, também deverá especificar a **`static`** classe de armazenamento na definição da função.

As declarações de parâmetro completas ( `int a` ) podem ser misturadas com declaradores abstratos ( **`int`** ) na mesma declaração. Por exemplo, a declaração a seguir é aceitável:

```C
int add( int a, int );
```

O protótipo pode incluir o tipo e um identificador para cada expressão que é passada como um argumento. Porém, tais identificadores têm escopo apenas até o final da declaração. O protótipo também pode refletir o fato de que o número de argumentos é variável ou que nenhum argumento é passado. Sem essa lista, as incompatibilidades podem não ser reveladas, para que o compilador não gere mensagens de diagnóstico relacionadas a elas. Consulte [Argumentos](../c-language/arguments.md) para obter mais informações sobre verificação de tipo.

O escopo de protótipo no compilador do Microsoft C agora está em conformidade com ANSI ao compilar com a opção do compilador **/Za**. Isso significa que, se você declarar **`struct`** uma **`union`** marca ou dentro de um protótipo, a marca será inserida nesse escopo, em vez de no escopo global. Por exemplo, ao compilar com **/Za** para estar em conformidade com ANSI, você nunca pode chamar essa função sem receber um erro de incompatibilidade:

```C
void func1( struct S * );
```

Para corrigir seu código, defina ou declare o **`struct`** ou **`union`** no escopo global antes do protótipo de função:

```C
struct S;
void func1( struct S * );
```

Em **/Ze**, a marca ainda é inserida no escopo global.

## <a name="see-also"></a>Confira também

[Funções](../c-language/functions-c.md)
