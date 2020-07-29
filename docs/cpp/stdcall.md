---
title: __stdcall
ms.date: 10/10/2018
f1_keywords:
- __stdcall_cpp
- __stdcall
- _stdcall
helpviewer_keywords:
- __stdcall keyword [C++]
ms.assetid: e212594b-1827-4d07-9527-7d412b300df8
ms.openlocfilehash: 85d1b29fddece741aa94364bb6edfdf3b973faaf
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213171"
---
# <a name="__stdcall"></a>__stdcall

A **`__stdcall`** Convenção de chamada é usada para chamar funções de API do Win32. O receptor limpa a pilha, portanto, o compilador faz `vararg` funções **`__cdecl`** . As funções que usam esta convenção de chamada exigem um protótipo de função. O **`__stdcall`** modificador é específico da Microsoft.

## <a name="syntax"></a>Sintaxe

> *tipo* **`__stdcall`** de retorno *Function-Name*[ **`(`** *lista de argumentos* **`)`** ]

## <a name="remarks"></a>Comentários

A lista a seguir mostra a implementação dessa convenção de chamada.

|Elemento|Implementação|
|-------------|--------------------|
|Ordem de passagem de argumentos|Da direita para a esquerda.|
|Convenção de passagem de argumentos|Por valor, a menos que um ponteiro ou um tipo de referência seja passado.|
|Responsabilidade de manutenção de pilha|A função chamada remove seus próprios argumentos da pilha.|
|Convenção de decoração de nome|Um sublinhado ( `_` ) é prefixado para o nome. O nome é seguido pelo sinal de arroba ( `@` ) seguido pelo número de bytes (em decimal) na lista de argumentos. Portanto, a função declarada como `int func( int a, double b )` está decorada da seguinte maneira: `_func@12`|
|Convenção de conversão de maiúsculas/minúsculas|Nenhum|

A opção de compilador [/gz](../build/reference/gd-gr-gv-gz-calling-convention.md) especifica **`__stdcall`** para todas as funções não declaradas explicitamente com uma Convenção de chamada diferente.

Para compatibilidade com versões anteriores, **`_stdcall`** é um sinônimo para **`__stdcall`** a menos que a opção do compilador [ `/Za` \( desabilite extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

As funções declaradas usando o **`__stdcall`** modificador retornam valores da mesma maneira que as funções declaradas usando [`__cdecl`](../cpp/cdecl.md) .

Em processadores ARM e x64, **`__stdcall`** é aceito e ignorado pelo compilador; em arquiteturas ARM e x64, por convenção, os argumentos são passados em registros quando possível, e os argumentos subsequentes são passados na pilha.

Para funções de classe não estáticas, se a função for definida como fora da linha, o modificador da convenção de chamada não precisará ser especificado na definição fora da linha. Ou seja, para métodos de membro de classe não estática, a convenção de chamada especificada durante a declaração é assumida no ponto de definição. Dada esta definição de classe,

```cpp
struct CMyClass {
   void __stdcall mymethod();
};
```

this

```cpp
void CMyClass::mymethod() { return; }
```

equivale a isso

```cpp
void __stdcall CMyClass::mymethod() { return; }
```

## <a name="example"></a>Exemplo

No exemplo a seguir, o uso de **`__stdcall`** resultados em todos os `WINAPI` tipos de função tratados como uma chamada padrão:

```cpp
// Example of the __stdcall keyword
#define WINAPI __stdcall
// Example of the __stdcall keyword on function pointer
typedef BOOL (__stdcall *funcname_ptr)(void * arg1, const char * arg2, DWORD flags, ...);
```

## <a name="see-also"></a>Confira também

[Passagem de argumentos e convenções de nomenclatura](../cpp/argument-passing-and-naming-conventions.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
