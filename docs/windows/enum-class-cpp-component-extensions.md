---
title: classe de enum (extensões de componentes C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
ms.assetid: 8010fa8c-bad6-45b4-8214-b4db64d7ffe1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e17c5e2055ef478dc7cafd5a7b2677f47bb9e074
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="enum-class--c-component-extensions"></a>classe enum (Extensões de Componentes C++)
Declara uma enumeração no escopo do namespace, que é um tipo definido pelo usuário que consiste em um conjunto de constantes nomeadas chamado enumeradores.  
  
## <a name="all-runtimes"></a>Todos os Tempos de Execução  
 **Comentários**  
  
 C + + CX e C + + suporte CLI `public enum class` e `private enum class` que são semelhante do C++ padrão `enum class` , mas com a adição do especificador de acessibilidade. Em **/clr**, C++ 11 `enum class` tipo é permitido, mas irá gerar aviso C4472 que deve é usado para garantir que você realmente deseja o tipo de enumeração ISO e não do C + + CX e C + + tipo CLI. Para obter mais informações sobre o C++ padrão ISO `enum` palavra-chave, consulte [enumerações](../cpp/enumerations-cpp.md).  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 **Sintaxe**  
  
```  
  
      access  
      enum class  
      enumeration-identifier  
      [:underlying-type] { enumerator-list } [var];  
accessenum structenumeration-identifier[:underlying-type] { enumerator-list } [var];  
```  
  
 **Parâmetros**  
  
 *access*  
 A acessibilidade de enumeração, que pode ser `public` ou `private`.  
  
 *Identificador de enumeração*  
 O nome da enumeração.  
  
 *tipo de base*  
 (Opcional) O tipo subjacente da enumeração.  
  
 (Opcional. Somente Windows Runtime) o tipo subjacente de enumeração, que pode ser `bool`, `char`, `char16`, `int16`, `uint16`, `int`, `uint32`, `int64`, ou `uint64`.  
  
 *lista de enumerador*  
 Uma lista delimitada por vírgulas de nomes de enumerador.  
  
 O valor de cada enumerador é uma expressão de constante ou é definida implicitamente pelo compilador, ou explicitamente a notação *enumerador*`=`*expressão constante*. Por padrão, o valor do primeiro enumerador é zero se ele é definido implicitamente. O valor de cada enumerador subsequente de implicitamente definido é o valor do enumerador anterior + 1.  
  
 *var*  
 (Opcional) O nome de uma variável do tipo de enumeração.  
  
 **Comentários**  
  
 Para obter mais informações e exemplos, consulte [Enums](http://msdn.microsoft.com/%20library/windows/apps/hh755820.aspx).  
  
 Observe que o compilador emite mensagens de erro se a expressão de constante que define o valor de um enumerador não pode ser representada pelo *tipo subjacente*.  No entanto, o compilador não relata um erro para um valor que não é apropriado para o tipo subjacente. Por exemplo:  
  
-   Se *tipo subjacente* for numérico e um enumerador Especifica o valor máximo para esse tipo, o próximo enumeratoin definida implicitamente o valor não pode ser representado.  
  
-   Se *tipo subjacente* é `bool`, e mais de dois enumeradores são implicitamente definida, os enumeradores após os dois primeiros não podem ser representados.  
  
-   Se *tipo subjacente* é `char16`e o valor de enumeração varia de 0xD800 a 0xDFFF, o valor pode ser representado. No entanto, o valor logicamente incorreto, pois ela representa um Unicode metade par substituto e não devem aparecer em isolamento.  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: **/ZW**  
  
## <a name="common-language-runtime"></a>Common Language Runtime 
 **Sintaxe**  
  
```  
  
      access  
      enum class  
      name [:type] { enumerator-list } var;  
accessenum structname [:type] { enumerator-list } var;  
```  
  
 **Parâmetros**  
  
 `access`  
 A acessibilidade do enum.  Pode ser uma **pública** ou `private`.  
  
 `enumerator-list`  
 Uma lista separada por vírgulas dos identificadores (enumeradores) na enumeração.  
  
 `name`  
 O nome da enumeração.  Enumerações gerenciadas anônimas não são permitidas.  
  
 `type` (opcional)  
 O tipo subjacente do *identificadores*.  Isso pode ser qualquer tipo de escalar, como versões assinados ou não assinados de int, curto ou longo.  `bool` ou `char` também é permitido.  
  
 `var` (opcional)  
 O nome de uma variável do tipo de enumeração.  
  
 **Comentários**  
  
 **classe de enum** e **enum struct** são declarações equivalentes.  
  
 Há dois tipos de enums: gerenciado ou C + + CX e padrão.  
  
 Gerenciada ou C + + CX enum poderão ser definido da seguinte maneira  
  
```cpp  
public enum class day {sun, mon };  
```  
  
 e é semanticamente equivalente a:  
  
```cpp  
ref class day {  
public:  
   static const int sun = 0;  
   static const int mon = 1;  
};  
```  
  
 Um enum padrão pode ser definido da seguinte maneira:  
  
```cpp  
enum day2 { sun, mon };  
```  
  
 e é semanticamente equivalente a:  
  
```cpp  
static const int sun = 0;  
static const int mon = 1;  
```  
  
 Nomes de enumerador gerenciados (*identificadores*) não são injetados dentro do escopo em que a enumeração está definida; todas as referências para os enumeradores devem ser totalmente qualificadas (*nome* `::` *identificador*).  Por esse motivo, você não pode definir um enum gerenciado anônimo.  
  
 Os enumeradores de um enum padrão são altamente injetados no escopo delimitador.  Ou seja, se houver outro símbolo com o mesmo nome de um enumerador no escopo delimitador, o compilador gerará um erro.  
  
 No Visual C++ 2002 e 2003 do Visual C++, enumeradores levemente foram inseridos (visível no escopo delimitador, a menos que houve outro identificador com o mesmo nome).  
  
 Se for definido um enum de C++ padrão (sem **classe** ou `struct`), compilando com **/clr** fará com que a enumeração a ser compilado como um enum gerenciado.  A enumeração ainda tem a semântica de uma enumeração não gerenciada.  Observe que o compilador insere um atributo `Microsoft::VisualC::NativeEnumAttribute`, que reconhece o compilador do Visual C++, para identificar o propósito do programador para enum ser um enum nativo.  Outros compiladores simplesmente verá enum padrão como uma enumeração gerenciada.  
  
 Um enum nomeado e padrão compilado com /CLR. ficarão visível no assembly como um enum gerenciado e pode ser consumido por qualquer outro compilador gerenciado.   No entanto, uma enumeração padrão sem nome não será visível publicamente do assembly.  
  
 No Visual C++ 2002 e 2003 do Visual C++, um enum padrão usado como o tipo de um parâmetro de função:  
  
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
  
 seria emitir o seguinte na MSIL para a assinatura de função:  
  
```  
void f(int32);  
```  
  
 No entanto, nas versões atuais do compilador, o padrão enum é emitido como uma enumeração gerenciada com [NativeEnumAttribute] e o seguinte na MSIL para a assinatura de função:  
  
```  
void f(E)  
```  
  
 Para obter mais informações sobre as enumerações nativo, consulte [declarações de enumeração de C++](../cpp/enumerations-cpp.md).  
  
 Para obter mais informações sobre enumerações do CLR, consulte:  
  
-   [O tipo subjacente de um Enum](../dotnet/how-to-define-and-consume-enums-in-cpp-cli.md)  
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
### <a name="examples"></a>Exemplos  
 **Exemplo**  
  
 desc  
  
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
  
```Output  
no automatic conversion to int: b  
  
convert to int: 1  
  
1  
  
1  
  
```  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)