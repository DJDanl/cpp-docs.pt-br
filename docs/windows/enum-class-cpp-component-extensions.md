---
title: "enum class  (C++ Component Extensions) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
ms.assetid: 8010fa8c-bad6-45b4-8214-b4db64d7ffe1
caps.latest.revision: 23
caps.handback.revision: 21
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# enum class  (C++ Component Extensions)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Declara uma enumeração no escopo do namespace, que é um tipo definido pelo usuário que consiste em um conjunto de constantes nomeadas chamadas enumeradores.  
  
## Todos os Tempos de Execução  
 **Comentários**  
  
 C\+\+\/CX e C\+\+\/CLI dão suporte a `public enum class` e `private enum class` que são semelhantes ao padrão C\+\+ `enum class` mas com a adição do especificador de acessibilidade.  Em **\/clr**, o tipo de C\+\+11 `enum class` é permitido mas produzirá C4472 de aviso que deve ser usado se certificar de que você deseja realmente o tipo de enum ISO e não o tipo de C\+\+\/CX e de C\+\+\/CLI.  Para obter mais informações sobre a palavra\-chave do padrão ISO C\+\+ `enum` , consulte [Enumerações](../cpp/enumerations-cpp.md).  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
 **Sintaxe**  
  
```  
  
        access enum class enumeration-identifier [:underlying-type] { enumerator-list } [var];  
access enum struct enumeration-identifier [:underlying-type] { enumerator-list } [var];  
```  
  
 **Parâmetros**  
  
 *access*  
 A acessibilidade da enumeração, que pode ser `public` ou `private`.  
  
 *enumeration\-identifier*  
 O nome da enumeração.  
  
 *underlying\-type*  
 \(Opcional\) O tipo subjacente da enumeração.  
  
 \(Opcional.  somente [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]\) O tipo subjacente da enumeração, que pode ser `bool`, `char`, `char16`, `int16`, `uint16`, `int`, `uint32`, `int64` ou `uint64`.  
  
 *enumerator\-list*  
 Uma lista delimitada por vírgulas de nomes de enumerador.  
  
 O valor de cada enumerador é uma expressão constante que ou é definida implicitamente pelo compilador, ou explicitamente pela notação, *enumerator*`=`*constant\-expression*.  Por padrão, o valor do primeiro enumerador será zero se for definido implicitamente.  O valor de cada enumerador definido implicitamente subsequente é o valor do enumerador anterior \+ 1.  
  
 *var*  
 \(Opcional\) O nome de uma variável do tipo enumeração.  
  
 **Comentários**  
  
 Para obter mais informações, e exemplos, consulte [Enum](http://msdn.microsoft.com/%20library/windows/apps/hh755820.aspx).  
  
 Observe que o compilador emite mensagens de erro se a expressão constante que define o valor de um enumerador não pode ser representada por *underlying\-type*.  No entanto, o compilador não relata um erro para um valor que seja impróprio para o tipo subjacente.  Por exemplo:  
  
-   Se *underlying\-type* for numérico, e um enumerador especifica o valor máximo para esse tipo, o valor de enumeratoin definido implicitamente seguir não pode ser representado.  
  
-   Se *underlying\-type* é `bool`, e mais de dois enumeradores são definidos implicitamente, os enumeradores depois que os dois primeiros não podem ser representados.  
  
-   Se *underlying\-type* é `char16`, e o valor de enumeração varia de 0xD800 com 0xDFFF, o valor pode ser representado.  No entanto, o valor está logicamente incorreto porque representa metade de um par alternativo Unicode e não deve aparecer no isolamento.  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## [!INCLUDE[clr_for_headings](../dotnet/includes/clr_for_headings_md.md)]  
 **Sintaxe**  
  
```  
  
        access enum class name [:type] { enumerator-list } var;  
access enum struct name [:type] { enumerator-list } var;  
```  
  
 **Parâmetros**  
  
 `access`  
 A acessibilidade do enumerador.  Podem ser **public** ou `private`.  
  
 `enumerator-list`  
 Uma lista separada por vírgulas de identificadores \(enumeradores\) na enumeração.  
  
 `name`  
 O nome da enumeração.  As enumerações gerenciadas anônimas não são permitidas.  
  
 `type` \(opcional\)  
 O tipo subjacente dos *identificadores*.  Pode ser qualquer tipo escalar, como as versões assinados ou não assinados int, com, ou por muito tempo.  `bool` ou `char` também são permitidos.  
  
 `var` \(opcional\)  
 O nome de uma variável do tipo enumeração.  
  
 **Comentários**  
  
 **enum class** e **enum struct** são declarações equivalentes.  
  
 Há dois tipos de enum: gerenciado ou C\+\+\/CX e padrão.  
  
 Uma enum gerenciado ou de C\+\+\/CX pode ser definido da seguinte forma,  
  
```cpp  
public enum class day {sun, mon };  
```  
  
 e é equivalente semanticamente a:  
  
```cpp  
ref class day {  
public:  
   static const int sun = 0;  
   static const int mon = 1;  
};  
```  
  
 Uma enumeração padrão pode ser definida como a seguir:  
  
```cpp  
enum day2 { sun, mon };  
```  
  
 e é equivalente semanticamente a:  
  
```cpp  
static const int sun = 0;  
static const int mon = 1;  
```  
  
 Os nomes do enumerador gerenciador \(*identificadores*\) não são injetados no escopo onde a enumeração é definida; todas as referências a enumeradores devem ser totalmente qualificadas \(*nome*`::`*identificador*\).  Por esse motivo, você não pode definir uma enumeração gerenciada anônima.  
  
 Os enumeradores de uma enumeração padrão são fortemente injetados no escopo delimitador.  Isto é, se houver outro símbolo com o mesmo nome de um enumerador no escopo delimitador, o compilador gerará um erro.  
  
 No Visual C\+\+ 2002 e no Visual C\+\+ 2003, enumeradores foram injetados de forma fraca \(visíveis no escopo delimitador a menos que houvesse outro identificador com o mesmo nome\).  
  
 Se uma enum padrão do C\+\+ está definida \(sem **class** ou `struct`\), compile com **\/clr** fará a enumeração a ser criada como uma enum gerenciado.  A enumeração ainda tem a semântica de uma enumeração não gerenciada.  Observe que a, o compilador injeta um atributo, [Microsoft::VisualC::NativeEnumAttribute](assetId:///Microsoft::VisualC::NativeEnumAttribute?qualifyHint=False&autoUpgrade=True), que o compilador do Visual C\+\+ reconhece, para identificar a intenção de um programador para que o enum é uma enum nativo.  Outros compiladores simplesmente verão o enumeração padrão como uma enumeração gerenciada.  
  
 Uma enumeração nomeada padrão compilada com \/clr estará visível no assembly como uma enumeração gerenciada e pode ser consumida por qualquer outro compilador gerenciado.   No entanto, uma enumeração padrão sem nome não ficará publicamente visível a partir do assembly.  
  
 No Visual C\+\+ 2002 e no Visual C\+\+ 2003, uma enumeração padrão usada como o tipo em um parâmetro de função:  
  
```cpp  
// mcppv2_enum.cpp  
// compile with: /clr  
enum E { a, b };  
void f(E) {System::Console::WriteLine("hi");}  
  
int main() {  
   E myi = b;  
   f(myi);  
}  
```  
  
 emitiria o seguinte no MSIL para a assinatura de função:  
  
```  
void f(int32);  
```  
  
 No entanto, em versões atuais do compilador, a enumeração padrão é emitida como uma enumeração gerenciada com um \[NativeEnumAttribute\] e o seguinte no MSIL para a assinatura de função:  
  
```  
void f(E)  
```  
  
 Para obter mais informações sobre enumerações nativas, consulte [Declarações de enumeração C\+\+](../cpp/enumerations-cpp.md).  
  
 Para obter mais informações sobre enumerações CLR, consulte:  
  
-   [Tipo subjacente de um enum](../Topic/How%20to:%20Define%20and%20consume%20enums%20in%20C++-CLI.md)  
  
-   [Enumerações gerenciados e padrão](../misc/how-to-convert-between-managed-and-standard-enumerations.md)  
  
-   [Operadores e enumerações](../Topic/Operators%20and%20Enumerations.md)  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplos  
 **Exemplo**  
  
 decresc  
  
```cpp  
// mcppv2_enum_2.cpp  
// compile with: /clr  
// managed enum  
public enum class m { a, b };  
  
// standard enum  
public enum n { c, d };  
  
// unnamed, standard enum  
public enum { e, f } o;  
  
int main()   
{  
   // consume managed enum  
   m mym = m::b;  
   System::Console::WriteLine("no automatic conversion to int: {0}", mym);  
   System::Console::WriteLine("convert to int: {0}", (int)mym);  
  
   // consume standard enum  
   n myn = d;  
   System::Console::WriteLine(myn);  
  
   // consume standard, unnamed enum  
   o = f;  
   System::Console::WriteLine(o);  
}   
```  
  
 **Saída**  
  
  **nenhuma conversão automática para int: b**  
 **converter para int: 1**  
 **1**  
 **1**   
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)