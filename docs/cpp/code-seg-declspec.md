---
title: code_seg (__declspec)
ms.date: 11/04/2016
f1_keywords:
- code_seg_cpp
helpviewer_keywords:
- code_seg __declspec keyword
ms.assetid: ad3c1105-15d3-4e08-b7b9-e4bd9d7b6aa0
ms.openlocfilehash: a0b9c6dcd7ee19af59ac39a71498fe41bfc107ea
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62216548"
---
# <a name="codeseg-declspec"></a>code_seg (__declspec)

**Seção específica da Microsoft**

O **code_seg** nomes de atributo de declaração de um segmento de texto executável no arquivo. obj, no qual o código de objeto para a função ou funções de membro de classe será armazenado.

## <a name="syntax"></a>Sintaxe

```
__declspec(code_seg("segname")) declarator
```

## <a name="remarks"></a>Comentários

O atributo `__declspec(code_seg(...))` permite o posicionamento do código em segmentos nomeados distintos que podem ser paginados ou bloqueados na memória individualmente. Você pode usar esse atributo para controlar o posicionamento de modelos instanciados e do código gerado pelo compilador.

Um *segmento* é um bloco nomeado de dados em um arquivo. obj que é carregado na memória como uma unidade. Um *segmento de texto* é um segmento que contém o código executável. O termo *seção* geralmente é usado alternadamente com segmento.

O código de objeto gerado quando `declarator` é definido é colocado no segmento de texto especificado por `segname`, que é um literal de cadeia de caracteres estreito. O nome `segname` não precisa ser especificado em um [seção](../preprocessor/section.md) pragma antes que ele pode ser usado em uma declaração. Por padrão, quando nenhum `code_seg` é especificado, o código do objeto é colocado em um segmento chamado .text. Um **code_seg** atributo substitui qualquer existente [#pragma code_seg](../preprocessor/code-seg.md) diretiva. Um **code_seg** atributo aplicado a uma função de membro substitui qualquer **code_seg** atributo aplicado à classe delimitadora.

Se uma entidade tem um **code_seg** attribute, todas as declarações e definições da mesma entidade devem ter idênticos **code_seg** atributos. Se uma classe base tem um **code_seg** atributo, derivado classes devem ter o mesmo atributo.

Quando um **code_seg** atributo é aplicado a uma função de escopo de namespace ou uma função de membro, o código de objeto para essa função é colocado no segmento de texto especificado. Quando esse atributo é aplicado a uma classe, todas as funções membro da classe e classes aninhadas (isso inclui funções membro especiais geradas por compilador) são colocadas no segmento especificado. Classes definidas localmente — por exemplo, as classes definidas no corpo de uma função de membro — não herdam a **code_seg** atributo do escopo delimitador.

Quando um **code_seg** atributo é aplicado a uma classe de modelo ou a função de modelo, todas as especializações implícitas do modelo são colocadas no segmento especificado. Especializações explícitas ou parciais não herdam a **code_seg** atributo do modelo primário. Você pode especificar o mesmo ou outro **code_seg** atributo na especialização. Um **code_seg** atributo não pode ser aplicado a uma instanciação de modelo explícitos.

Por padrão, o código gerado por compilador, como uma função membro especial, é colocado no segmento .text. A diretiva `#pragma code_seg` não substitui esse padrão. Use o **code_seg** atributo na classe, o modelo de classe ou modelo de função para controlar onde o código gerado pelo compilador é colocado.

As lambdas herdam **code_seg** atributos do respectivo escopo delimitador. Para especificar um segmento para uma lambda, aplique uma **code_seg** atributo após a cláusula de declaração de parâmetro e antes de qualquer mutável ou especificação de exceção, qualquer especificação de tipo de retorno à direita e o corpo lambda. Para obter mais informações, consulte [sintaxe de expressão Lambda](../cpp/lambda-expression-syntax.md). Este exemplo define uma lambda em um segmento denominado PagedMem:

```cpp
auto Sqr = [](int t) __declspec(code_seg("PagedMem")) -> int { return t*t; };
```

Tenha cuidado ao colocar funções membro específicas, especialmente funções membro virtuais, em diferentes segmentos. Se você definir uma função virtual em uma classe derivada que resida em um segmento paginado quando o método da classe base residir em um segmento não paginado, outros métodos de classe base ou o código de usuário poderão supor que invocando o método virtual não acionarão uma falha de página.

## <a name="example"></a>Exemplo

Este exemplo mostra como uma **code_seg** controles atributo posicionamento do segmento quando implícita e especialização de modelo explícito é usada:

```cpp
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

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)