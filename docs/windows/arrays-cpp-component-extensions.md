---
title: "Arrays (C++ Component Extensions) | Microsoft Docs"
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
  - "cli::array"
  - "details::array"
  - "lang::array"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "array keyword [C++]"
  - "declaring arrays, about declaring arrays"
  - "arrays [C++], multidimensional"
  - "multidimensional arrays"
  - "arrays [C++]"
ms.assetid: 49445812-d775-4db1-a231-869598dbb955
caps.latest.revision: 34
caps.handback.revision: 34
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Arrays (C++ Component Extensions)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

`Platform::Array<T>` em [!INCLUDE[cppwrt_short](../Token/cppwrt_short_md.md)], ou a palavra\-chave de `array` em [!INCLUDE[cppcli](../build/reference/includes/cppcli_md.md)], declara uma matriz de um tipo especificado e um valor inicial.  
  
## Todas as Plataformas  
 A matriz deve ser declarado usando o modificador de alça\-à\- objeto \(^\) depois do ângulo de colchete de fechamento \(\>\) na declaração.  
  
 O número de elementos da matriz não faz parte do tipo.  Uma variável de matriz pode se referir a matrizes de tamanhos diferentes.  
  
 Ao contrário do padrão C\+\+, a subscrição não é um sinônimo para o ponteiro aritmético e não é comutativa.  
  
 Para obter mais informações sobre matrizes, consulte:  
  
-   [Covariância de matriz](../misc/array-covariance.md)  
  
-   [Como usar matrizes em C\+\+\/CLI](../dotnet/how-to-use-arrays-in-cpp-cli.md)  
  
-   [Como criar matrizes multidimensionais](../misc/how-to-create-multidimension-arrays.md)  
  
-   [Como criar matrizes de matrizes gerenciadas \(matrizes denteadas\)](../misc/how-to-create-arrays-of-managed-arrays-jagged-arrays.md)  
  
-   [Como fazer typedefs para matrizes gerenciadas](../misc/how-to-make-typedefs-for-managed-arrays.md)  
  
-   [Como usar matrizes gerenciadas como parâmetros de tipo de modelo](../misc/how-to-use-managed-arrays-as-template-type-parameters.md)  
  
-   [Variable Argument Lists \(...\) \(C\+\+\/CLI\)](../windows/variable-argument-lists-dot-dot-dot-cpp-cli.md)  
  
-   [Como classificar matrizes](../misc/how-to-sort-arrays.md)  
  
-   [Como classificar matrizes usando critérios personalizados](../misc/how-to-sort-arrays-using-custom-criteria.md)  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
 As matrizes são membros do namespace de `Platform` .  Pode ser somente as matrizes unidimensionais.  
  
 **Sintaxe**  
  
 O primeiro exemplo de sintaxe usa a palavra\-chave de agregação de `ref new` para alocar uma matriz.  O segundo exemplo a seguir declara uma matriz local.  
  
```  
  
        [qualifiers] [Platform::]Array<[qualifiers] array-type [,rank]>^ identifier = ref new [Platform::]Array< initialization-type > [{initialization-list [,...]}]  
  
[qualifiers] [Platform::]Array<[qualifiers] array-type [,rank]>^ identifier = {initialization-list [,...]}  
  
```  
  
 \[*qualifiers* opcional\]  
 Um ou mais destes especificadores da classe de armazenamento: [mutável](../cpp/mutable-data-members-cpp.md), [temporário](../cpp/volatile-cpp.md), [const](../cpp/const-cpp.md), [extern](../cpp/using-extern-to-specify-linkage.md), [estáticos](../misc/static-cpp.md).  
  
 `array-type`  
 O tipo da variável de matriz.  Os tipos válidos são classes de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] e tipos de classes fundamentais, e estruturas de referência, classes e estruturas de valor, e ponteiros nativos \(`type``*`\).  
  
 \[`rank` opcional\]  
 O número de dimensões da matriz.  Deve ser 1.  
  
 `identifier`  
 O nome da variável de matriz.  
  
 `initialization-type`  
 O tipo dos valores de inicialização a matriz.  Normalmente, `array-type` e `initialization-type` são do mesmo tipo.  Porém, os tipos podem ser diferentes se houver uma conversão de `initialization-type` a `array-type`— por exemplo, se `initialization-type` é derivado de `array-type`.  
  
 \[`initialization-list` opcional\]  
 Uma lista delimitada por vírgulas dos valores entre colchetes encaracolado de inicialização os elementos da matriz.  Por exemplo, se `rank-size-list` foi `(3)`, que declara uma matriz unidimensional de 3 elementos, `initialization list` pode ser `{1,2,3}`.  
  
 **Comentários**  
  
 Você pode detectar em tempo de compilação se um tipo é uma matriz referência\- contada com `__is_ref_array(``type``)`.  Para obter mais informações, consulte [Compiler Support for Type Traits](../windows/compiler-support-for-type-traits-cpp-component-extensions.md).  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
### Exemplos  
 O exemplo a seguir cria uma matriz unidimensional com 100 elementos.  
  
```  
// cwr_array.cpp  
// compile with: /ZW  
using namespace Platform;  
ref class MyClass {};  
int main() {  
   // one-dimensional array  
   Array<MyClass^>^ My1DArray = ref new Array<MyClass^>(100);  
   My1DArray[99] = ref new MyClass();  
}  
```  
  
## [!INCLUDE[clr_for_headings](../dotnet/includes/clr_for_headings_md.md)]  
 **Sintaxe**  
  
 O primeiro exemplo de sintaxe usa a palavra\-chave de `gcnew` para alocar uma matriz.  O segundo exemplo a seguir declara uma matriz local.  
  
```  
  
        [qualifiers] [cli::]array<[qualifiers] array-type [,rank] >^ identifier = gcnew [cli::]array< initialization-type [,rank] >(rank-size-list[,...]) [{initialization-list [,...]}]  
  
[qualifiers] [cli::]array<[qualifiers] array-type [,rank] >^ identifier = {initialization-list [,...]}  
  
```  
  
 \[*qualifiers* opcional\]  
 Um ou mais destes especificadores da classe de armazenamento: [mutável](../cpp/mutable-data-members-cpp.md), [temporário](../cpp/volatile-cpp.md), [const](../cpp/const-cpp.md), [extern](../cpp/using-extern-to-specify-linkage.md), [estáticos](../misc/static-cpp.md).  
  
 `array-type`  
 O tipo da variável de matriz.  Os tipos válidos são classes de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] e os tipos de fundamentais, as classes e as estruturas de referência, as classes e as estruturas de valor, os ponteiros nativos \(`type``*`\), e a VAGEM nativo \(dados antigos planos\) tipo.  
  
 \[`rank` opcional\]  
 O número de dimensões da matriz.  O padrão é 1; o máximo é 32.  Cada dimensão da matriz é própria uma matriz.  
  
 `identifier`  
 O nome da variável de matriz.  
  
 `initialization-type`  
 O tipo dos valores de inicialização a matriz.  Normalmente, `array-type` e `initialization-type` são do mesmo tipo.  Porém, os tipos podem ser diferentes se houver uma conversão de `initialization-type` a `array-type`— por exemplo, se `initialization-type` é derivado de `array-type`.  
  
 `rank-size-list`  
 Uma lista delimitada por vírgulas do tamanho de cada dimensão na matriz.  Como alternativa, se o parâmetro de `initialization-list` for especificado, o compilador pode deduzir o tamanho de cada dimensão e `rank-size-list` poderá ser omitido.  Para obter mais informações, consulte [Como criar matrizes multidimensionais](../misc/how-to-create-multidimension-arrays.md).  
  
 \[`initialization-list` opcional\]  
 Uma lista delimitada por vírgulas dos valores entre colchetes encaracolado de inicialização os elementos da matriz.  Ou uma lista delimitada por vírgulas de itens aninhados de *initialization\-list* de inicialização os elementos em uma matriz multidimensional.  
  
 Por exemplo, se `rank-size-list` foi `(3)`, que declara uma matriz unidimensional de 3 elementos, `initialization list` pode ser `{1,2,3}`.  Se `rank-size-list` foi `(3,2,4)`, que declara uma matriz tridimensional de 3 elementos na primeira dimensão, 2 elementos no segundo, e 4 elementos no terceiro, `initialization-list` podem ser `{{1,2,3},{0,0},{-5,10,-21,99}}`.\)  
  
 **Comentários**  
  
 `array` está no namespace de [Platform, default, and cli Namespaces](../windows/platform-default-and-cli-namespaces-cpp-component-extensions.md) .  
  
 Como o padrão C\+\+, os índices de uma matriz zero são baseados, e uma matriz subscripted usando colchetes \(\[\]\).  Ao contrário do C\+\+ padrão, os índices de uma matriz multidimensional são especificados em uma lista de índices para cada dimensão em vez de um conjunto de operadores de quadrado\- colchetes \(\[\]\) para cada dimensão.  Por exemplo, *identifier*\[*index1*, *index2*\] em vez de *identifier**index1*\[\] \[\] *index2*.  
  
 Todas as matrizes gerenciados herdam de `System::Array`.  Qualquer método ou propriedade de `System::Array` podem ser aplicadas diretamente à variável de matriz.  
  
 Quando você atribui uma matriz cujo tipo de elemento é ponteiro\- a uma classe gerenciada, os elementos são 0 inicializado.  
  
 Quando você atribui uma matriz cujo tipo de elemento é um tipo de valor `V`, o construtor padrão para `V` é aplicado a cada elemento da matriz.  Para obter mais informações, consulte [Equivalentes do .NET Framework aos tipos nativos do C\+\+](../dotnet/dotnet-framework-equivalents-to-cpp-native-types-cpp-cli.md).  
  
 Em tempo de compilação, você pode detectar se um tipo é uma matriz de Common Language Runtime \(CLR\) com `__is_ref_array(``type``)`.  Para obter mais informações, consulte [Compiler Support for Type Traits](../windows/compiler-support-for-type-traits-cpp-component-extensions.md).  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplos  
 O exemplo a seguir cria uma matriz unidimensional com 100 elementos, e uma matriz tridimensional com 3 elementos na primeira dimensão, 5 elementos no segundo, terceiro e 6 elementos no.  
  
```  
// clr_array.cpp  
// compile with: /clr  
ref class MyClass {};  
int main() {  
   // one-dimensional array  
   array<MyClass ^> ^ My1DArray = gcnew array<MyClass ^>(100);  
   My1DArray[99] = gcnew MyClass();  
  
   // three-dimensional array  
   array<MyClass ^, 3> ^ My3DArray = gcnew array<MyClass ^, 3>(3, 5, 6);  
   My3DArray[0,0,0] = gcnew MyClass();  
}  
```  
  
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)