---
title: __fastcall
ms.date: 12/17/2018
f1_keywords:
- __fastcall_cpp
- __fastcall
- _fastcall
helpviewer_keywords:
- __fastcall keyword [C++]
ms.assetid: bb5b9c8a-dfad-450c-9119-0ac2bc59544f
ms.openlocfilehash: 420552dd62c46ab5c2fa7e201387f258617f8453
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227472"
---
# <a name="__fastcall"></a>__fastcall

**Específico da Microsoft**

A **`__fastcall`** Convenção de chamada especifica que os argumentos para funções devem ser passados em registros, quando possível. Esta convenção de chamada se aplica somente à arquitetura x86. A lista a seguir mostra a implementação dessa convenção de chamada.

|Elemento|Implementação|
|-------------|--------------------|
|Ordem de passagem de argumentos|Os dois primeiros argumentos de DWORD ou menores encontrados na lista de argumentos da esquerda para a direita são passados em registros de ECX e de EDX; todos os outros argumentos são passados na pilha da direita para a esquerda.|
|Responsabilidade de manutenção de pilha|A função de chamada retira os argumentos da pilha.|
|Convenção de decoração de nome|O sinal de arroba ( \@ ) é prefixado para nomes; um sinal de arroba seguido pelo número de bytes (em decimal) na lista de parâmetros tem o sufixo para nomes.|
|Convenção de conversão de maiúsculas/minúsculas|Nenhuma conversão de maiúsculas/minúsculas é realizada.|

> [!NOTE]
> As versões futuras do compilador podem usar registros diferentes para armazenar parâmetros.

Usar a opção de compilador [/gr](../build/reference/gd-gr-gv-gz-calling-convention.md) faz com que cada função no módulo seja compilada como a **`__fastcall`** menos que a função seja declarada usando um atributo conflitante ou o nome da função seja `main` .

A **`__fastcall`** palavra-chave é aceita e ignorada pelos compiladores que visam arquiteturas ARM e x64; em um chip x64, por convenção, os primeiros quatro argumentos são passados em registros quando possível, e argumentos adicionais são passados na pilha. Para obter mais informações, consulte [Convenção de chamada x64](../build/x64-calling-convention.md). Em um chip ARM, até quatro argumentos inteiros e oito argumentos de ponto flutuante podem ser passados em registros, e os argumentos adicionais são passados na pilha.

Para funções de classe não estáticas, se a função for definida como fora da linha, o modificador da convenção de chamada não precisará ser especificado na definição fora da linha. Ou seja, para métodos de membro de classe não estática, a convenção de chamada especificada durante a declaração é assumida no ponto de definição. Dada esta definição de classe:

```cpp
struct CMyClass {
   void __fastcall mymethod();
};
```

isto:

```cpp
void CMyClass::mymethod() { return; }
```

equivale a isto:

```cpp
void __fastcall CMyClass::mymethod() { return; }
```

Para compatibilidade com versões anteriores, **_fastcall** é um sinônimo para **`__fastcall`** a menos que a opção do compilador [/za \( desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

## <a name="example"></a>Exemplo

No exemplo a seguir, a função `DeleteAggrWrapper` recebe argumentos passados em registros:

```cpp
// Example of the __fastcall keyword
#define FASTCALL    __fastcall

void FASTCALL DeleteAggrWrapper(void* pWrapper);
// Example of the __ fastcall keyword on function pointer
typedef BOOL (__fastcall *funcname_ptr)(void * arg1, const char * arg2, DWORD flags, ...);
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Passagem de argumentos e convenções de nomenclatura](../cpp/argument-passing-and-naming-conventions.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
