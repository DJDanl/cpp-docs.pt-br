---
title: code_seg (__declspec)
ms.date: 11/04/2016
f1_keywords:
- code_seg_cpp
helpviewer_keywords:
- code_seg __declspec keyword
ms.assetid: ad3c1105-15d3-4e08-b7b9-e4bd9d7b6aa0
ms.openlocfilehash: 22703e92b1a127378c965ce12bcc4e5475b3e452
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80180830"
---
# <a name="code_seg-__declspec"></a>code_seg (__declspec)

**Seção específica da Microsoft**

O atributo **code_seg** declaração nomeia um segmento de texto executável no arquivo. obj no qual o código do objeto para as funções de membro de classe ou função será armazenado.

## <a name="syntax"></a>Sintaxe

```
__declspec(code_seg("segname")) declarator
```

## <a name="remarks"></a>Comentários

O atributo `__declspec(code_seg(...))` permite o posicionamento do código em segmentos nomeados distintos que podem ser paginados ou bloqueados na memória individualmente. Você pode usar esse atributo para controlar o posicionamento de modelos instanciados e do código gerado pelo compilador.

Um *segmento* é um bloco nomeado de dados em um arquivo. obj que é carregado na memória como uma unidade. Um *segmento de texto* é um segmento que contém código executável. A *seção* de termo geralmente é usada de forma intercambiável com o segmento.

O código de objeto gerado quando `declarator` é definido é colocado no segmento de texto especificado por `segname`, que é um literal de cadeia de caracteres estreito. O nome `segname` não precisa ser especificado em um pragma de [seção](../preprocessor/section.md) antes que possa ser usado em uma declaração. Por padrão, quando nenhum `code_seg` é especificado, o código do objeto é colocado em um segmento chamado .text. Um atributo **code_seg** substitui qualquer diretiva [#pragma code_seg](../preprocessor/code-seg.md) existente. Um atributo **code_seg** aplicado a uma função de membro substitui qualquer atributo **code_seg** aplicado à classe delimitadora.

Se uma entidade tiver um atributo **code_seg** , todas as declarações e definições da mesma entidade deverão ter atributos de **code_seg** idênticos. Se uma classe base tiver um atributo **code_seg** , as classes derivadas deverão ter o mesmo atributo.

Quando um atributo **code_seg** é aplicado a uma função de escopo de namespace ou a uma função de membro, o código do objeto para essa função é colocado no segmento de texto especificado. Quando esse atributo é aplicado a uma classe, todas as funções membro da classe e classes aninhadas (isso inclui funções membro especiais geradas por compilador) são colocadas no segmento especificado. Classes definidas localmente — por exemplo, classes definidas em um corpo de função membro — não herdam o atributo **code_seg** do escopo delimitador.

Quando um atributo **code_seg** é aplicado a uma classe de modelo ou função de modelo, todas as especializações implícitas do modelo são colocadas no segmento especificado. Especializações explícitas ou parciais não herdam o atributo **code_seg** do modelo primário. Você pode especificar o mesmo atributo de **code_seg** ou diferente na especialização. Um atributo **code_seg** não pode ser aplicado a uma instanciação de modelo explícita.

Por padrão, o código gerado por compilador, como uma função membro especial, é colocado no segmento .text. A diretiva `#pragma code_seg` não substitui esse padrão. Use o atributo **code_seg** na classe, modelo de classe ou modelo de função para controlar onde o código gerado pelo compilador é colocado.

As lambdas herdam atributos de **code_seg** de seu escopo delimitador. Para especificar um segmento para um lambda, aplique um atributo **code_seg** após a cláusula de declaração de parâmetro e antes de qualquer especificação mutável ou de exceção, qualquer especificação de tipo de retorno à direita e o corpo lambda. Para obter mais informações, consulte [sintaxe de expressão lambda](../cpp/lambda-expression-syntax.md). Este exemplo define uma lambda em um segmento denominado PagedMem:

```cpp
auto Sqr = [](int t) __declspec(code_seg("PagedMem")) -> int { return t*t; };
```

Tenha cuidado ao colocar funções membro específicas, especialmente funções membro virtuais, em diferentes segmentos. Se você definir uma função virtual em uma classe derivada que resida em um segmento paginado quando o método da classe base residir em um segmento não paginado, outros métodos de classe base ou o código de usuário poderão supor que invocando o método virtual não acionarão uma falha de página.

## <a name="example"></a>Exemplo

Este exemplo mostra como um atributo **code_seg** controla o posicionamento de segmento quando a especialização de modelo implícita e explícita é usada:

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

## <a name="see-also"></a>Confira também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
