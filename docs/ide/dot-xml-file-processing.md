---
title: "Processamento de arquivo .xml | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "documentação XML, processando o arquivo XML"
ms.assetid: e70fdeae-80ac-4872-ab24-771c5635cfbf
caps.latest.revision: 15
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Processamento de arquivo .xml
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O compilador gera uma cadeia de caracteres de identificação para cada construct no seu código marcado para gerar a documentação.  Para obter mais informações, consulte [Recomendados comentários de documentação de marcas](../Topic/Recommended%20Tags%20for%20Documentation%20Comments%20\(Visual%20C++\).md).  A cadeia de caracteres de identificação identifica exclusivamente o constructo.  Programas que processam o arquivo .xml podem usar a cadeia de caracteres de identificação para identificar o item correspondente de metadados ou de reflexão do .NET Framework que a documentação se aplica.  
  
 O arquivo .xml não é uma representação hierárquica de seu código, é uma lista simples com uma identificação gerada para cada elemento.  
  
 O compilador observa as regras a seguir quando ele gera as cadeias de caracteres de identificação:  
  
-   Nenhum espaço em branco é colocado na cadeia de caracteres.  
  
-   A primeira parte da cadeia de caracteres de identificação identifica o tipo de participante que está sendo identificada, com um único caractere seguido por dois pontos.  Os seguintes tipos de membros são usados:  
  
    |Caractere.|Descrição|  
    |----------------|---------------|  
    |N|Espaço para nome<br /><br /> Você não pode adicionar comentários a um namespace, referências de documentação de cref a um namespace é possível.|  
    |T|tipo: classe, estrutura, interface, representante, enum|  
    |D|typedef|  
    |F|campo|  
    |P|propriedade \(incluindo indicadores ou outras propriedades indexadas\)|  
    |M|método \(que inclui métodos especiais como construtores, operadores, e assim por diante\)|  
    |E|evento|  
    |\!|cadeia de caracteres de erro<br /><br /> O restante da cadeia de caracteres fornece informações sobre o erro.  O compilador do Visual C\+\+ gera informações de erro para links que não podem ser resolvidos.|  
  
-   A segunda parte da cadeia de caracteres é o nome totalmente qualificado do item, começando a raiz de namespace.  O nome do item, seu tipo ou tipos incluindo, e namespace são separados em pontos.  Se o próprio nome do item tem pontos, são substituídos pelo hash sinal \(“\# "\).  Pressupõe\-se que nenhum item possui um hash sinal diretamente em seu nome.  Por exemplo, o nome totalmente qualificado do construtor de `String` seria System.String.\#ctor “”.  
  
-   Para propriedades e métodos, se houver argumentos para o método, a lista de argumentos colocados entre parênteses segue.  Se não houver nenhum argumento, nenhum parêntese estará presente  Os argumentos são separados por vírgulas.  A codificação de cada argumento segue diretamente como é codificada em uma assinatura do.NET Framework:  
  
    -   Tipos base.  Os tipos normais \(ELEMENT\_TYPE\_CLASS ou ELEMENT\_TYPE\_VALUETYPE\) são representadas como o nome de tipo totalmente qualificado.  
  
    -   O tipos intrínsecos \(por exemplo, ELEMENT\_TYPE\_I4, ELEMENT\_TYPE\_OBJECT, ELEMENT\_TYPE\_STRING, ELEMENT\_TYPE\_TYPEDBYREF.  e ELEMENT\_TYPE\_VOID\) são representadas como o nome de tipo totalmente qualificado correspondente completo, por exemplo, para **System.Int32** ou de **System.TypedReference**.  
  
    -   ELEMENT\_TYPE\_PTR é representado como “\*” seguindo o tipo alterado.  
  
    -   ELEMENT\_TYPE\_BYREF é representado como “@” após um do tipo alterado.  
  
    -   ELEMENT\_TYPE\_PINNED é representado como um “^” que segue o tipo alterado.  O compilador do Visual C\+\+ nunca gera esse.  
  
    -   ELEMENT\_TYPE\_CMOD\_REQ é representado como “&#124;” e o nome totalmente qualificado da classe modificadoras, seguindo o tipo alterado.  O compilador do Visual C\+\+ nunca gera esse.  
  
    -   ELEMENT\_TYPE\_CMOD\_OPT é representado como “\!” e o nome totalmente qualificado da classe modificadoras, seguindo o tipo alterado.  
  
    -   ELEMENT\_TYPE\_SZARRAY é representado como “\[\]” após o tipo de elemento da matriz.  
  
    -   ELEMENT\_TYPE\_GENERICARRAY é representado como “\[\]?” após o tipo de elemento da matriz.  O compilador do Visual C\+\+ nunca gera esse.  
  
    -   ELEMENT\_TYPE\_ARRAY é representado como \[*lowerbound*:`size`,*lowerbound*:`size`\] onde o número de vírgulas é a classificação \- 1, e os limites inferiores e o tamanho de cada dimensão, se conhecidos, é representado em decimal.  Se um limite inferior ou um tamanho não são especificados, é simplesmente omitidos.  Se o limite inferior e o tamanho de uma dimensão particular são omitidos, “: ” for omitido também.  Por exemplo, uma matriz dimensional 2 com 1 como os limites inferiores e tamanhos não especificado é \[1: 1:\].  
  
    -   ELEMENT\_TYPE\_FNPTR é representado como “\=FUNC:`type`\(*assinatura*\)”, onde `type` é o tipo de retorno, e *assinatura* é argumentos do método.  Se não houver nenhum argumento, os parênteses são omitidos.  O compilador do Visual C\+\+ nunca gera esse.  
  
     Os seguintes componentes da assinatura não são representados como eles são usados não diferenciando métodos sobrecarregados:  
  
    -   convenção de chamada  
  
    -   tipo de retorno  
  
    -   ELEMENT\_TYPE\_SENTINEL  
  
-   Para operadores de conversão, somente o valor de retorno do método é codificada como “~” seguido pelo tipo de retorno, como codificado anteriormente.  
  
-   Para tipos genéricos, o nome do tipo será seguido por uma marcação de volta e em seguida por um número que indica o número de parâmetros de tipo genéricos.  Por exemplo,  
  
    ```  
    <member name="T:MyClass`2">  
    ```  
  
     Para um tipo que é definido como `public class MyClass<T, U>`.  
  
     Para os métodos que usam tipos genéricos como parâmetros, os parâmetros de tipo genéricos são especificados como números precedidos com as escalas suporta \(por exemplo, '0 '1\).  Cada número que representa uma notação com base zero da matriz de parâmetros de tipo genéricos.  
  
## Exemplo  
 Os exemplos a seguir mostram como as cadeias de caracteres de identificação de uma classe e seus membros seriam gerados.  
  
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
  
## Consulte também  
 [A Documentação XML](../ide/xml-documentation-visual-cpp.md)