---
title: Processamento de arquivos .xml | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- XML documentation, processing XML file
ms.assetid: e70fdeae-80ac-4872-ab24-771c5635cfbf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1cf6f5660e1aaeaeff4050bb80009eda7d14c3ba
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33340509"
---
# <a name="xml-file-processing"></a>Processamento de arquivo .xml
O compilador gera uma cadeia de identificação para cada constructo no seu código marcado para gerar a documentação. Para obter mais informações, confira [Marcas recomendadas para comentários da documentação](../ide/recommended-tags-for-documentation-comments-visual-cpp.md). A cadeia de identificação identifica exclusivamente o constructo. Programas que processam o arquivo .xml podem usar a cadeia de identificação para identificar o item correspondente de metadados ou de reflexão do .NET Framework ao qual a documentação se aplica.  
  
 O arquivo .xml não é uma representação hierárquica do código; é uma lista plana com uma ID gerada para cada elemento.  
  
 O compilador observa as seguintes regras quando gera as cadeias de identificação:  
  
-   Nenhum espaço em branco é colocado na cadeia de caracteres.  
  
-   A primeira parte da cadeia de identificação identifica o tipo de membro que está sendo identificado, com um único caractere seguido por dois-pontos. São usados os seguintes tipos de membro:  
  
    |Caractere|Descrição|  
    |---------------|-----------------|  
    |N|namespace<br /><br /> Não é possível adicionar comentários da documentação a um namespace, mas é possível adicionar referências cref a um namespace.|  
    |T|tipo: classe, interface, struct, enumeração, delegado|  
    |D|typedef|  
    |F|campo|  
    |P|propriedade (incluindo indexadores ou outras propriedades indexadas)|  
    |M|método (incluindo métodos especiais como construtores, operadores e assim por diante)|  
    |E|evento|  
    |!|cadeia de caracteres de erro<br /><br /> O restante da cadeia de caracteres fornece informações sobre o erro. O compilador do Visual C++ gera informações de erro para links que não podem ser resolvidos.|  
  
-   A segunda parte da cadeia de caracteres é o nome totalmente qualificado do item, iniciando na raiz do namespace. O nome do item, seus tipos delimitadores e o namespace são separados por pontos. Se o nome do próprio item tiver pontos, eles serão substituídos pelo sustenido ('#'). Supõe-se que nenhum item tenha um sinal de hash diretamente no nome. Por exemplo, o nome totalmente qualificado do construtor de `String` é "System.String.#ctor".  
  
-   Para propriedades e métodos, se houver argumentos para o método, seguirá a lista de argumentos entre parênteses. Se não houver nenhum argumento, não haverá parênteses. Os argumentos são separados por vírgulas. A codificação de cada argumento segue diretamente a maneira como ele é codificado em uma assinatura do .NET Framework:  
  
    -   Tipos base. Tipos regulares (ELEMENT_TYPE_CLASS ou ELEMENT_TYPE_VALUETYPE) são representados como o nome totalmente qualificado do tipo.  
  
    -   Tipos intrínsecos (por exemplo, ELEMENT_TYPE_I4, ELEMENT_TYPE_OBJECT, ELEMENT_TYPE_STRING, ELEMENT_TYPE_TYPEDBYREF. e ELEMENT_TYPE_VOID) são representados como o nome totalmente qualificado do tipo completo correspondente, por exemplo, **System.Int32** ou **System.TypedReference**.  
  
    -   ELEMENT_TYPE_PTR é representado como um '*' após o tipo modificado.  
  
    -   ELEMENT_TYPE_BYREF é representado como um '@' após o tipo modificado.  
  
    -   ELEMENT_TYPE_PINNED é representado como um '^' após o tipo modificado. O compilador do Visual C++ nunca gera isso.  
  
    -   ELEMENT_TYPE_CMOD_REQ é representado como um '&#124;' e o nome totalmente qualificado da classe do modificador, após o tipo modificado. O compilador do Visual C++ nunca gera isso.  
  
    -   ELEMENT_TYPE_CMOD_OPT é representado como um '!' e o nome totalmente qualificado da classe do modificador, após o tipo modificado.  
  
    -   ELEMENT_TYPE_SZARRAY é representado como "[]" após o tipo de elemento da matriz.  
  
    -   ELEMENT_TYPE_GENERICARRAY é representado como "[?]" após o tipo de elemento da matriz. O compilador do Visual C++ nunca gera isso.  
  
    -   ELEMENT_TYPE_ARRAY é representado como [*lowerbound*:`size`,*lowerbound*:`size`] em que o número de vírgulas é a classificação -1 e os limites e o tamanho inferiores de cada dimensão, se conhecidos, são representados no formato decimal. Se um limite ou tamanho inferior não for especificado, ele é simplesmente omitido. Se o limite e o tamanho inferiores de uma determinada dimensão forem omitidos, o ':' será omitido também. Por exemplo, uma matriz bidimensional com 1 como limites inferiores e tamanhos não especificados é [1:,1:].  
  
    -   ELEMENT_TYPE_FNPTR é representado como "=FUNC:`type`(*assinatura*)", em que `type` é o tipo de retorno e *assinatura* são os argumentos do método. Se não houver nenhum argumento, os parênteses serão omitidos. O compilador do Visual C++ nunca gera isso.  
  
     Os seguintes componentes de assinatura não são representados, porque nunca são usadas para diferenciar métodos sobrecarregados:  
  
    -   convenção de chamada  
  
    -   tipo de retorno  
  
    -   ELEMENT_TYPE_SENTINEL  
  
-   Somente para operadores de conversão, o valor retornado do método é codificado como um '~' seguido pelo tipo de retorno, conforme codificado anteriormente.  
  
-   Para tipos genéricos, o nome do tipo será seguido por um backtick e, em seguida, um número que indica o número de parâmetros de tipo genérico.  Por exemplo,  
  
    ```  
    <member name="T:MyClass`2">  
    ```  
  
     Para um tipo que é definido como `public class MyClass<T, U>`.  
  
     Para os métodos que usam tipos genéricos como parâmetros, os parâmetros de tipo genérico são especificados como números precedidos por backticks (por exemplo, \`0, \`1).  Cada número que representa uma notação de matriz com base em zero para parâmetros genéricos do tipo.  
  
## <a name="example"></a>Exemplo  
 Os exemplos a seguir mostram como as cadeias de identificação de uma classe e seus membros são geradas.  
  
```  
// xml_id_strings.cpp  
// compile with: /clr /doc /LD  
///   
namespace N {    
// "N:N"  
  
   /// <see cref="System" />  
   //  <see cref="N:System"/>  
   ref class X {      
   // "T:N.X"  
  
   protected:  
      ///   
      !X(){}     
      // "M:N.X.Finalize", destructor's representation in metadata  
  
   public:  
      ///   
      X() {}     
      // "M:N.X.#ctor"  
  
      ///   
      static X() {}     
      // "M:N.X.#cctor"  
  
      ///   
      X(int i) {}     
      // "M:N.X.#ctor(System.Int32)"  
  
      ///   
      ~X() {}     
      // "M:N.X.Dispose", Dispose function representation in metadata  
  
      ///   
      System::String^ q;     
      // "F:N.X.q"  
  
      ///   
      double PI;     
      // "F:N.X.PI"  
  
      ///   
      int f() { return 1; }     
      // "M:N.X.f"  
  
      ///   
      int bb(System::String ^ s, int % y, void * z) { return 1; }  
      // "M:N.X.bb(System.String,System.Int32@,System.Void*)"  
  
      ///   
      int gg(array<short> ^ array1, array< int, 2 >^ IntArray) { return 0; }   
      // "M:N.X.gg(System.Int16[], System.Int32[0:,0:])"  
  
      ///   
      static X^ operator+(X^ x, X^ xx) { return x; }  
     // "M:N.X.op_Addition(N.X,N.X)"  
  
      ///   
      property int prop;     
      // "M:N.X.prop"  
  
      ///   
      property int prop2 {     
      // "P:N.X.prop2"  
  
         ///   
         int get() { return 0; }  
         // M:N.X.get_prop2  
  
         ///   
         void set(int i) {}  
         // M:N.X.set_prop2(System.Int32)  
      }  
  
      ///   
      delegate void D(int i);   
      // "T:N.X.D"  
  
      ///   
      event D ^ d;   
      // "E:N.X.d"  
  
      ///   
      ref class Nested {};   
      // "T:N.X.Nested"  
  
      ///   
      static explicit operator System::Int32 (X x) { return 1; }   
      // "M:N.X.op_Explicit(N.X!System.Runtime.CompilerServices.IsByValue)~System.Int32"  
   };  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Documentação XML](../ide/xml-documentation-visual-cpp.md)