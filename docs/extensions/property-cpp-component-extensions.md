---
title: property (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- property keyword [C++]
ms.assetid: cc79d2b2-f013-4d81-8252-eece97a18704
ms.openlocfilehash: fbec97a5bd30bb9bb76459ef2f7b0956ae6a264f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225131"
---
# <a name="property--ccli-and-ccx"></a>property (C++/CLI e C++/CX)

Declara uma *propriedade*, que é uma função membro que se comporta e é acessada como um membro de dados ou um elemento de matriz.

## <a name="all-runtimes"></a>Todos os Runtimes

Você pode declarar um dos seguintes tipos de propriedades.

*propriedade simples*<br/>
Por padrão, cria um *acessador set*, que atribui o valor da propriedade, um *acessador get* que recupera o valor da propriedade e um membro de dados particulares gerado pelo compilador que contém o valor da propriedade.

*bloco de propriedades*<br/>
Use isso para criar acessadores get e/ou set definidos pelo usuário. A propriedade será de leitura/gravação se os acessadores set e get forem definidos, somente leitura se apenas o acessador get for definido e somente gravação se apenas o acessador set for definido.

Você deve declarar explicitamente um membro de dados para conter o valor da propriedade.

*propriedade indexada*<br/>
Um bloco de propriedades que pode ser usado para obter e definir um valor de propriedade especificado por um ou mais índices.

Você pode criar uma propriedade indexada que tem um nome de propriedade definido pelo usuário ou um nome de propriedade *padrão*. O nome de uma propriedade de índice padrão é o nome da classe na qual a propriedade está definida. Para declarar uma propriedade padrão, especifique a **`default`** palavra-chave em vez de um nome de propriedade.

Você deve declarar explicitamente um membro de dados para conter o valor da propriedade. Para uma propriedade indexada, o membro de dados normalmente é uma matriz ou uma coleção.

### <a name="syntax"></a>Sintaxe

```cpp
property type property_name;

property type property_name {
   access-modifier type get() inheritance-modifier {property_body};
   access-modifier void set(type value) inheritance-modifier {property_body};
}

property type property_name[index_list] {
   access-modifier type get(index_list) inheritance-modifier {property_body};
   access-modifier void set(index_list, value) inheritance-modifier {property_body};
}

property type default[index_list] {
   access-modifier type get(index_list) inheritance-modifier {property_body};
   access-modifier void set(index_list, value) inheritance-modifier {property_body};
}
```

### <a name="parameters"></a>parâmetros

*tipo*<br/>
O tipo de dados do valor da propriedade e, consequentemente, a própria propriedade.

*property_name*<br/>
O nome da propriedade.

*access-modifier*<br/>
Um qualificador de acesso. Qualificadores válidos são **`static`** e **`virtual`** .

Os acessadores get ou set não precisam concordar com o **`virtual`** qualificador, mas devem concordar com o **`static`** qualificador.

*inheritance-modifier*<br/>
Um qualificador de herança. Os qualificadores válidos são **abstract** e **sealed**.

*index_list*<br/>
Uma lista delimitada por vírgula de um ou mais índices. Cada índice é composto por um tipo de índice e um identificador opcional que pode ser usado no corpo do método da propriedade.

*value*<br/>
O valor a ser atribuído à propriedade em uma operação set, ou recuperado em uma operação get.

*property_body*<br/>
O corpo do método da propriedade do acessador set ou get. *property_body* pode usar *index_list* para acessar o membro de dados da propriedade subjacente, ou como parâmetros em processamento definido pelo usuário.

## <a name="windows-runtime"></a>Windows Runtime

Saiba mais em [Propriedades (C++/CX)](../cppcx/properties-c-cx.md).

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

### <a name="syntax"></a>Sintaxe

```cpp
modifier property type property_name;

modifier property type property_name {
   modifier void set(type);
   modifier type get();
}
modifier property type property_name[index-list, value] {
   modifier void set(index-list, value);
   modifier type get(index-list);

modifier property type default[index];
}
```

### <a name="parameters"></a>parâmetros

*modifier*<br/>
Um modificador que pode ser usado na declaração de propriedade ou em um método de acessador get/set. Os valores possíveis são **`static`** e **`virtual`** .

*tipo*<br/>
O tipo do valor que é representado pela propriedade.

*property_name*<br/>
Os parâmetros para o método raise devem corresponder à assinatura do delegado.

*index_list*<br/>
Uma lista delimitada por vírgula de um ou mais índices, especificados em colchetes (o operador subscrito, ([])). Para cada índice, especifique um tipo e, opcionalmente, um identificador que pode ser usado no corpo do método da propriedade.

### <a name="remarks"></a>Comentários

O primeiro exemplo de sintaxe mostra uma *simple property* que declara implicitamente os métodos `set` e `get`. O compilador cria automaticamente um campo particular para armazenar o valor da propriedade.

O segundo exemplo de sintaxe mostra um *bloco de propriedades* que declara implicitamente os métodos `set` e `get`.

O terceiro exemplo de sintaxe mostra uma *propriedade de índice* definida pelo cliente. Uma propriedade de índice usa parâmetros, além do valor a ser definido ou recuperado. Você deve especificar um nome para a propriedade. Ao contrário de uma propriedade simples, os métodos `set` e/ou `get` de uma propriedade de índice devem ser definidos explicitamente, e você deve especificar um nome para a propriedade.

O quarto exemplo de sintaxe mostra uma propriedade *default* que fornece acesso de matriz a uma instância do tipo. A palavra-chave, **`default`** , serve apenas para especificar uma propriedade padrão. O nome da propriedade padrão é o nome do tipo no qual a propriedade está definida.

A **`property`** palavra-chave pode aparecer em uma classe, interface ou tipo de valor. Uma propriedade pode ter uma função get (somente leitura), uma função set (somente gravação) ou ambas (leitura-gravação).

O nome da propriedade pode não corresponder ao nome da classe gerenciada que a contém. O tipo de retorno da função getter deve corresponder ao tipo do último parâmetro de uma função setter correspondente.

Para o código do cliente, uma propriedade tem a aparência de um membro de dados comum, e pode ser gravada ou lida usando a mesma sintaxe que um membro de dados.

Os métodos get e Set não precisam concordar com o **`virtual`** modificador.

A acessibilidade do método get e set pode diferir.

A definição de um método de propriedade pode aparecer fora do corpo de classe, assim como um método comum.

O método Get e Set para uma propriedade deve concordar com o **`static`** modificador.

Uma propriedade será escalar se seus métodos get e set aceitarem a descrição a seguir:

- O método get não tem parâmetros e tem o tipo de retorno `T`.

- O método Set tem um parâmetro do tipo `T` e o tipo de retorno **`void`** .

Deve haver apenas uma propriedade escalar declarada em um escopo com o mesmo identificador. Propriedades escalares não podem ser sobrecarregadas.

Quando um membro de dados de propriedade é declarado, o compilador injeta um membro de dados, às vezes chamado de "repositório de backup", na classe. No entanto, o nome do membro de dados está em um formato no qual não é possível referenciar o membro na fonte, como se fosse um membro de dados real da classe recipiente. Use ildasm.exe para exibir os metadados de seu tipo e ver o nome gerado pelo compilador do repositório de backup da propriedade.

Há permissão para uma acessibilidade diferente nos métodos acessadores em um bloco de propriedades.  Ou seja, o método set pode ser público e o método get pode ser privado.  No entanto, é um erro um método acessador ter uma acessibilidade menos restritiva do que está na declaração da propriedade em si.

**`property`** é uma palavra-chave sensível ao contexto.  Saiba mais em [Palavras-chave contextuais](context-sensitive-keywords-cpp-component-extensions.md).

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo a seguir mostra a declaração e uso de um membro de dados de propriedade e um bloco de propriedade.  Também mostra que um acessador de propriedade pode ser definido fora da classe.

```cpp
// mcppv2_property.cpp
// compile with: /clr
using namespace System;
public ref class C {
   int MyInt;
public:

   // property data member
   property String ^ Simple_Property;

   // property block
   property int Property_Block {

      int get();

      void set(int value) {
         MyInt = value;
      }
   }
};

int C::Property_Block::get() {
   return MyInt;
}

int main() {
   C ^ MyC = gcnew C();
   MyC->Simple_Property = "test";
   Console::WriteLine(MyC->Simple_Property);

   MyC->Property_Block = 21;
   Console::WriteLine(MyC->Property_Block);
}
```

```Output
test

21
```

## <a name="see-also"></a>Confira também

[Extensões de componente para .NET e UWP](component-extensions-for-runtime-platforms.md)
