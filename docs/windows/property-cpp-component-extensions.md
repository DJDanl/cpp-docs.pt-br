---
title: propriedade (extensões de componentes C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- property_cpp
- property
dev_langs:
- C++
helpviewer_keywords:
- property keyword [C++]
ms.assetid: cc79d2b2-f013-4d81-8252-eece97a18704
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5fbf0b3c9db19e839d6832415cfd8ed6eb9b93a2
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39604112"
---
# <a name="property--c-component-extensions"></a>propriedade (Extensões de Componentes C++)
Declara um *propriedade*, que é uma função de membro que se comporta e é acessada como um membro de dados ou um elemento de matriz.  
  
## <a name="all-runtimes"></a>Todos os Tempos de Execução  
 Você pode declarar um dos seguintes tipos de propriedades.  
  
 *propriedade simples*  
 Por padrão, cria uma *acessador set* que atribui o valor da propriedade, um *acessador get* que recupera o valor da propriedade e um membro de dados particulares geradas pelo compilador que contém o valor da propriedade.  
  
 *bloco Property*  
 Use isto para criar get definidas pelo usuário e/ou definir acessadores. A propriedade é leitura/gravação se ambos os get e acessadores set são definidas, somente leitura se somente o acessador get é definido e somente gravação se apenas o acessador set é definido.  
  
 Você deve declarar explicitamente um membro de dados para conter o valor da propriedade.  
  
 *propriedade indexada*  
 Um bloco de propriedade que você pode usar para obter e definir um valor da propriedade que é especificado por um ou mais índices.  
  
 Você pode criar uma propriedade indexada que tem um nome de uma propriedade definida pelo usuário ou um *padrão* nome da propriedade. O nome de uma propriedade de índice padrão é o nome da classe na qual a propriedade está definida. Para declarar uma propriedade padrão, especifique o **padrão** palavra-chave, em vez de um nome de propriedade.  
  
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
  
### <a name="parameters"></a>Parâmetros  
 *type*  
 O tipo de dados do valor da propriedade e, consequentemente, a própria propriedade.  
  
 *property_name*  
 O nome da propriedade.  
  
 *modificador de acesso*  
 Um qualificador de acesso. Qualificadores válidos são **estáticos** e **virtual**.  
  
 Get ou acessadores set não precisam concordar com o **virtual** qualificador, mas eles devem concordar com os **estático** qualificador.  
  
 *modificador de herança*  
 Um qualificador de herança. Qualificadores válidos são **abstrata** e **lacrado**.  
  
 *index_list*  
 Uma lista delimitada por vírgula de um ou mais índices. Cada índice consiste em um tipo de índice e um identificador opcional que pode ser usado no corpo do método de propriedade.  
  
 *value*  
 O valor a ser atribuído à propriedade em uma operação definida, ou recuperar em uma operação get.  
  
 *property_body*  
 O corpo do método de propriedade do acessador set ou get. O *property_body* pode usar o *index_list* para acessar o membro de dados da propriedade subjacente, ou como parâmetros em processamento definidas pelo usuário.  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 Para obter mais informações, consulte [propriedades (C + + c++ /CX)](http://msdn.microsoft.com/library/windows/apps/hh755807.aspx).  
  
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
  
### <a name="parameters"></a>Parâmetros  
  
 *Modificador*  
 Um modificador que pode ser usado em uma declaração de propriedade ou um método de acessador get/set. Os valores possíveis são **estáticos** e **virtual**.  
  
 *type*  
 O tipo do valor que é representado pela propriedade.  
  
 *property_name*  
 Parâmetro (s) para o método raise; deve corresponder à assinatura do delegado.  
  
 *index_list*  
 Uma lista delimitada por vírgula de um ou mais índices, especificado colchetes (o operador subscrito, ([])). Para cada índice, especifique um tipo e, opcionalmente, um identificador que pode ser usado no corpo do método de propriedade.  
  
### <a name="remarks"></a>Comentários  
  
 O primeiro exemplo de sintaxe mostra uma *propriedade simples*, que declara implicitamente tanto uma `set` e `get` método. O compilador cria automaticamente um campo particular para armazenar o valor da propriedade.  
  
 O segundo exemplo de sintaxe mostra uma *bloco property*, que declara explicitamente tanto uma `set` e `get` método.  
  
 O terceiro exemplo de sintaxe mostra um cliente definido *propriedade index*. Uma propriedade de índice usa parâmetros além do valor a ser definido ou recuperado. Você deve especificar um nome para a propriedade. Ao contrário de uma propriedade simples, o `set` e/ou `get` métodos de uma propriedade de índice devem ser definidos explicitamente, e você deve especificar um nome para a propriedade.  
  
 O exemplo de sintaxe a quarto mostra uma *padrão* propriedade, que fornece acesso de matriz a uma instância do tipo. A palavra-chave **padrão**, serve apenas para especificar uma propriedade padrão. O nome da propriedade padrão é o nome do tipo no qual a propriedade é definida.  
  
 O **propriedade** palavra-chave pode aparecer em uma classe, interface ou tipo de valor. Uma propriedade pode ter uma função get (somente leitura), uma função de conjunto (somente gravação) ou ambos (leitura-gravação).  
  
 Um nome de propriedade não pode corresponder ao nome da classe gerenciada que o contém. O tipo de retorno da função getter deve corresponder ao tipo do último parâmetro de uma função setter correspondente.  
  
 Ao código do cliente, uma propriedade tem a aparência de um membro de dados comum e pode ser gravada ou lido do, usando a mesma sintaxe como um membro de dados.  
  
 Get e conjunto de métodos não precisam concordar com os **virtual** modificador.  
  
 A acessibilidade de get e método set pode diferir.  
  
 A definição de um método de propriedade pode aparecer fora do corpo de classe, assim como um método comum.  
  
 Get e o método set para uma propriedade deverão concordar com os **estático** modificador.  
  
 Uma propriedade é escalar se seu get e métodos definidos se adaptam a descrição a seguir:  
  
-   O método get não tem parâmetros e tem o tipo de retorno `T`.  
  
-   O método set tem um parâmetro do tipo `T`e o tipo de retorno **void**.  
  
 Deve haver apenas uma propriedade escalar declarada em um escopo com o mesmo identificador. Propriedades escalares não podem ser sobrecarregadas.  
  
 Quando um membro de dados de propriedade é declarado, o compilador injeta um membro de dados — também conhecido como "armazenamento de backup" — na classe. No entanto, o nome do membro de dados é de um formulário, de modo que você não pode referenciar o membro na fonte, como se fosse um membro de dados reais da classe recipiente. Use ildasm.exe para exibir os metadados para seu tipo e ver o nome gerado pelo compilador para o repositório de backup da propriedade.  
  
 Acessibilidade diferente é permitida para os métodos acessadores em um bloco de propriedade.  Ou seja, o método set pode ser público e o método get pode ser privado.  No entanto, é um erro para um método de acessador para ter uma acessibilidade menos restritiva do que está na declaração da propriedade em si.  
  
 **propriedade** é uma palavra-chave contextual.  Para obter mais informações, consulte [contextual as palavras-chave](../windows/context-sensitive-keywords-cpp-component-extensions.md).  
  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: `/clr`  
  
### <a name="examples"></a>Exemplos  
 O exemplo a seguir mostra a declaração e uso de um membro de dados de propriedade e um bloco de propriedade.  Ele também mostra que um acessador de propriedade pode ser definido fora de classe.  
  
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
  
 **Saída**  
  
```Output  
test  
  
21  
```  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)