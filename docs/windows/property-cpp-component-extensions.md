---
title: "property  (C++ Component Extensions) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "property_cpp"
  - "property"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "property keyword [C++]"
ms.assetid: cc79d2b2-f013-4d81-8252-eece97a18704
caps.latest.revision: 31
caps.handback.revision: 29
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# property  (C++ Component Extensions)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Declara um *propriedade*, que é uma função de membro que se comporta e acessada como um membro de dados ou um elemento de matriz.  
  
## Todos os Tempos de Execução  
 Você pode declarar um dos seguintes tipos de propriedades.  
  
 *propriedade simples*  
 Por padrão, cria um *acessador set* que atribui o valor da propriedade, um *acessador get* que recupera o valor da propriedade e um membro de dados particulares geradas pelo compilador que contém o valor da propriedade.  
  
 *bloco Property*  
 Use isto para criar get definidas pelo usuário e\/ou definir acessadores.  A propriedade é leitura\/gravação se get e acessadores set são definidas, somente leitura se apenas o acessador get é definido e somente gravação se somente o acessador set é definido.  
  
 Você deve declarar explicitamente um membro de dados para conter o valor da propriedade.  
  
 *propriedade indexada*  
 Um bloco de propriedade que você pode usar para obter e definir um valor de propriedade que é especificado por um ou mais índices.  
  
 Você pode criar uma propriedade indexada que tem o nome de uma propriedade definida pelo usuário ou um *padrão* nome da propriedade.  O nome de uma propriedade de índice padrão é o nome da classe na qual a propriedade está definida.  Para declarar uma propriedade padrão, especifique o `default` palavra\-chave em vez de um nome de propriedade.  
  
 Você deve declarar explicitamente um membro de dados para conter o valor da propriedade.  Para uma propriedade indexada, o membro de dados normalmente é uma matriz ou uma coleção.  
  
### Sintaxe  
  
```cpp  
  
property type property_name;  
  
property type property_name {  
   access-modifier type get() inheritance-modifier {property_body};  
   access-modifier void set(type value) inheritance-modifier {property_body};  
} property type property_name[index_list] {  
   access-modifier type get(index_list) inheritance-modifier {property_body};  
   access-modifier void set(index_list, value) inheritance-modifier {property_body};  
} property type default[index_list] {  
   access-modifier type get(index_list) inheritance-modifier {property_body};  
   access-modifier void set(index_list, value) inheritance-modifier {property_body};  
}  
  
```  
  
### Parâmetros  
 `type`  
 O tipo de dados do valor da propriedade e, conseqüentemente, a própria propriedade.  
  
 `property_name`  
 O nome da propriedade.  
  
 `access-modifier`  
 Um qualificador de acesso.  Qualificadores válidos são `static` e `virtual`.  
  
 Get ou acessadores set não precisam concordar sobre o `virtual` qualificador, mas eles devem concordar com o `static` qualificador.  
  
 `inheritance-modifier`  
 Um qualificador de herança.  Qualificadores válidos são `abstract` e `sealed`.  
  
 `index_list`  
 Uma lista delimitada por vírgulas de um ou mais índices.  Cada índice consiste em um tipo de índice e um identificador opcional que pode ser usado no corpo do método de propriedade.  
  
 `value`  
 O valor a ser atribuído à propriedade em uma operação definida ou recuperados em uma operação get.  
  
 `property_body`  
 O corpo do método de propriedade do acessador set ou get.  O `property_body` pode usar o `index_list` para acessar o membro de dados da propriedade subjacente, ou como parâmetros de processamento definidas pelo usuário.  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
 Para obter mais informações, consulte [Propriedades \(C \+ c\+\+ \/CX\)](http://msdn.microsoft.com/library/windows/apps/hh755807.aspx).  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## [!INCLUDE[clr_for_headings](../dotnet/includes/clr_for_headings_md.md)]  
 **Sintaxe**  
  
```  
  
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
  
 **Parâmetros**  
  
 *modificador*  
 Um modificador que pode ser usado em uma declaração de propriedade ou um método do acessador get\/set.  Os valores possíveis são `static` e `virtual`.  
  
 *tipo*  
 O tipo do valor que é representado pela propriedade.  
  
 *Property\_Name*  
 Parâmetros para o método para disparar; deve corresponder à assinatura do delegado.  
  
 *index\_list*  
 Uma lista delimitada por vírgulas de um ou mais índices, especificado colchetes \(o operador subscrito, \(\[\]\)\).  Para cada índice, especifique um tipo e, opcionalmente, um identificador que pode ser usado no corpo do método de propriedade.  
  
 **Observações**  
  
 O primeiro exemplo de sintaxe mostra uma *propriedade simples*, que declara tanto implicitamente um `set` e `get` método.  O compilador cria automaticamente um campo particular para armazenar o valor da propriedade.  
  
 O segundo exemplo de sintaxe mostra uma *bloco property*, que declara tanto explicitamente um `set` e `get` método.  
  
 O terceiro exemplo de sintaxe mostra um cliente definido *propriedade index*.  Uma propriedade de índice usa parâmetros além do valor a ser definido ou recuperado.  Você deve especificar um nome para a propriedade.  Diferentemente de uma propriedade simple, o `set` e\/ou `get` métodos de uma propriedade de índice devem ser explicitamente definidos, e você deve especificar um nome para a propriedade.  
  
 O quarto exemplo de sintaxe mostra uma *padrão* propriedade, que fornece acesso de matriz para uma instância do tipo.  A palavra\-chave `default`, serve apenas para especificar uma propriedade padrão.  O nome da propriedade padrão é o nome do tipo no qual a propriedade está definida.  
  
 O `property` palavra\-chave pode aparecer em uma classe, interface ou tipo de valor.  Uma propriedade pode ter uma função de get \(somente leitura\), uma função de conjunto \(somente gravação\) ou ambos \(leitura\-gravação\).  
  
 Um nome de propriedade não corresponde ao nome da classe gerenciada que o contém.  O tipo de retorno da função getter deve corresponder ao tipo do último parâmetro de uma função setter correspondente.  
  
 Para o código de cliente, uma propriedade tem a aparência de um membro de dados comum e pode ser gravada ou ler usando a mesma sintaxe como um membro de dados.  
  
 Get e conjunto de métodos necessário não concordar com o `virtual` modificador.  
  
 A acessibilidade de get e método de conjunto pode ser diferente.  
  
 A definição de um método de propriedade pode aparecer fora do corpo de classe, como um método comum.  
  
 O get e o método set de uma propriedade devem concordar com os **estático** modificador.  
  
 Uma propriedade é escalar se seu get e métodos set ajustarem a descrição a seguir:  
  
-   O método get não tem parâmetros e tem o tipo de retorno `T`.  
  
-   O método set tem um parâmetro do tipo `T`, e o tipo de retorno **void**.  
  
 Deve haver somente uma propriedade escalar declarada em um escopo com o mesmo identificador.  Propriedades escalares não podem ser sobrecarregadas.  
  
 Quando um membro de dados da propriedade é declarado, o compilador injeta um membro de dados — às vezes chamado de "armazenamento de backup" — na classe.  No entanto, o nome do membro de dados é de um formulário que você não pode fazer referência ao membro na fonte de como se fosse um membro de dados reais da classe recipiente.  Use ildasm.exe para exibir os metadados para o tipo e ver o nome gerado pelo compilador para armazenamento de backup da propriedade.  
  
 Acessibilidade diferente é permitida para os métodos acessadores em um bloco de propriedade.  Ou seja, o método set pode ser público e o método get pode ser particular.  No entanto, é um erro para um método do acessador ter uma acessibilidade menos restritiva do que está na declaração da propriedade.  
  
 `property` é uma palavra\-chave contextual.  Para obter mais informações, consulte [Palavras\-chave Contextuais](../windows/context-sensitive-keywords-cpp-component-extensions.md).  
  
 Para obter mais informações sobre propriedades, consulte  
  
-   [Propriedades indexadas](../misc/how-to-use-indexed-properties.md)  
  
-   [Propriedades estáticas](../misc/how-to-declare-and-use-static-properties.md)  
  
-   [Propriedades virtuais](../misc/how-to-declare-and-use-virtual-properties.md)  
  
-   [Propriedades multidimensionais](../Topic/How%20to:%20Use%20Multidimensional%20Properties.md)  
  
-   [Sobrecarregando métodos do acessador de propriedade](../misc/how-to-overload-property-accessor-methods.md)  
  
-   [Como declarar propriedades abstratas e lacradas](../misc/how-to-declare-abstract-and-sealed-properties.md)  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplos  
 O exemplo a seguir mostra a declaração e uso de um membro de dados de propriedade e um bloco property.  Ele também mostra que um acessador de propriedade pode ser definido fora de classe.  
  
```  
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
  
  **teste**  
 **21**   
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)