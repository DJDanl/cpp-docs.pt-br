---
title: "code_seg (__declspec) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "code_seg_cpp"
  - "code_seg"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "palavra-chave code_seg __declspec"
ms.assetid: ad3c1105-15d3-4e08-b7b9-e4bd9d7b6aa0
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# code_seg (__declspec)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 O atributo de declaração `code_seg` nomeia um segmento de texto executável no arquivo .obj, no qual o código do objeto para a função ou funções membro da classe será armazenado.  
  
## Sintaxe  
  
```  
__declspec(code_seg("segname")) declarator  
```  
  
## Comentários  
 O atributo `__declspec(code_seg(...))` permite o posicionamento do código em segmentos nomeados distintos que podem ser paginados ou bloqueados na memória individualmente.  Você pode usar esse atributo para controlar o posicionamento de modelos instanciados e do código gerado pelo compilador.  
  
 Um *segmento* é um bloco de dados nomeado em um arquivo .obj que é carregado na memória como uma unidade.  Um *segmento de texto* é um segmento que contém código executável.  O termo *seção* muitas vezes é usado alternadamente com segmento.  
  
 O código de objeto gerado quando `declarator` é definido é colocado no segmento de texto especificado por `segname`, que é um literal de cadeia de caracteres estreito.  O nome `segname` não precisa ser especificado em um pragma de [seção](../preprocessor/section.md) para que possa ser usado em uma declaração.  Por padrão, quando nenhum `code_seg` é especificado, o código do objeto é colocado em um segmento chamado .text.  Um atributo `code_seg` substitui qualquer diretiva [\#pragma code\_seg](../preprocessor/code-seg.md) existente.  Um atributo `code_seg` aplicado a uma função membro substitui qualquer atributo `code_seg` aplicado à classe delimitadora.  
  
 Se uma entidade tiver um atributo `code_seg`, todas as declarações e definições da mesma entidade deverão ter atributos `code_seg` idênticos.  Se uma classe base tiver um atributo `code_seg`, as classes derivadas deverão ter o mesmo atributo.  
  
 Quando um atributo `code_seg` é aplicado a uma função de escopo de namespace ou a uma função membro, o código do objeto para essa função é colocado no segmento de texto especificado.  Quando esse atributo é aplicado a uma classe, todas as funções membro da classe e classes aninhadas \(isso inclui funções membro especiais geradas por compilador\) são colocadas no segmento especificado.  As classes definidas localmente \(por exemplo, classes definidas no corpo de uma função membro\) não herdam o atributo `code_seg` do escopo delimitador.  
  
 Quando um atributo `code_seg` é aplicado a uma classe de modelo ou função de modelo, todas as especializações implícitas do modelo são colocadas no segmento especificado.  As especializações explícitas ou parciais não herdam o atributo `code_seg` do modelo primário.  Você pode especificar um atributo `code_seg` igual ou diferente na especialização.  Um atributo `code_seg` não pode ser aplicado a uma instanciação explícita de modelo.  
  
 Por padrão, o código gerado por compilador, como uma função membro especial, é colocado no segmento .text.  A diretiva `#pragma code_seg` não substitui esse padrão.  Use o atributo `code_seg` na classe, no modelo de classe ou no modelo de função para controlar onde o código gerado por compilador é colocado.  
  
 As lambdas herdam atributos `code_seg` do respectivo escopo delimitador.  Para especificar um segmento para uma lambda, aplique um atributo `code_seg` depois da cláusula de declaração de parâmetro e antes de qualquer especificação mutável ou de exceção, qualquer especificação de tipo de retorno à direita e do corpo lambda.  Para obter mais informações, consulte [Sintaxe da expressão lambda](../cpp/lambda-expression-syntax.md).  Este exemplo define uma lambda em um segmento denominado PagedMem:  
  
```cpp  
auto Sqr = [](int t) __declspec(code_seg("PagedMem")) -> int { return t*t; };  
```  
  
 Tenha cuidado ao colocar funções membro específicas, especialmente funções membro virtuais, em diferentes segmentos.  Se você definir uma função virtual em uma classe derivada que resida em um segmento paginado quando o método da classe base residir em um segmento não paginado, outros métodos de classe base ou o código de usuário poderão supor que invocando o método virtual não acionarão uma falha de página.  
  
## Exemplo  
 Este exemplo mostra como um atributo `code_seg` controla o posicionamento do segmento quando a especialização de modelo implícita e explícita é usada:  
  
```  
// code_seg.cpp  
// Compile: cl /EHsc /W4 code_seg.cpp  
  
// Base template places object code in Segment_1 segment  
template<class T>  
class __declspec(code_seg("Segment_1")) Example  
{  
public:  
   virtual void VirtualMemberFunction(T /*arg*/) {}  
};  
  
// bool specialization places code in default .text segment  
template<>  
class Example<bool>   
{  
public:  
   virtual void VirtualMemberFunction(bool /*arg*/) {}  
};  
  
// int specialization places code in Segment_2 segment  
template<>  
class __declspec(code_seg("Segment_2")) Example<int>   
{  
public:  
   virtual void VirtualMemberFunction(int /*arg*/) {}  
};  
  
// Compiler warns and ignores __declspec(code_seg("Segment_3"))  
// in this explicit specialization  
__declspec(code_seg("Segment_3")) Example<short>; // C4071  
  
int main()  
{  
   // implicit double specialization uses base template's  
   // __declspec(code_seg("Segment_1")) to place object code  
   Example<double> doubleExample{};  
   doubleExample.VirtualMemberFunction(3.14L);  
  
   // bool specialization places object code in default .text segment  
   Example<bool> boolExample{};  
   boolExample.VirtualMemberFunction(true);  
  
   // int specialization uses __declspec(code_seg("Segment_2"))  
   // to place object code  
   Example<int> intExample{};  
   intExample.VirtualMemberFunction(42);  
}  
```  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [\_\_declspec](../cpp/declspec.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)