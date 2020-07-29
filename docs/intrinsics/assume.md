---
title: __assume
ms.date: 09/02/2019
f1_keywords:
- __assume
- _assume
- __assume_cpp
helpviewer_keywords:
- __assume keyword [C++]
ms.assetid: d8565123-b132-44b1-8235-5a8c8bff85a7
ms.openlocfilehash: 80acb417ed85ced8f72906848474837efe6bc9d1
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225092"
---
# <a name="__assume"></a>__assume

**Específico da Microsoft**

Passa uma dica para o otimizador.

## <a name="syntax"></a>Sintaxe

```C
__assume(
   expression
)
```

### <a name="parameters"></a>parâmetros

*expressão*\
Qualquer expressão supostamente avaliada como verdadeira.

## <a name="remarks"></a>Comentários

O otimizador presume que a condição representada por `expression` é verdadeira no ponto em que a palavra-chave aparece e permanece verdadeira até que a `expression` seja modificada (por exemplo, atribuindo a uma variável). O uso seletivo de dicas passadas para o otimizador **`__assume`** pode melhorar a otimização.

Se a **`__assume`** instrução for gravada como uma contradição (uma expressão que sempre é avaliada como false), ela será sempre tratada como `__assume(0)` . Se seu código não está funcionando como esperado, verifique se a `expression` que você definiu é válida e verdadeira, conforme descrito anteriormente. Para obter mais informações sobre comportamento esperado de `__assume(0)`, consulte os comentários posteriores.

> [!WARNING]
> Um programa não deve conter uma instrução inválida **`__assume`** em um caminho acessível. Se o compilador puder alcançar uma instrução inválida **`__assume`** , o programa poderá causar comportamento imprevisível e potencialmente perigoso.

`__assume` não é um intrínseco verdadeiro. Ele não precisa ser declarado como uma função e não pode ser usado em uma diretiva `#pragma intrinsic`. Embora nenhum código seja gerado, o código gerado pelo otimizador é afetado.

Use **`__assume`** em uma [declaração](../c-runtime-library/reference/assert-asserte-assert-expr-macros.md) somente quando Assert não for recuperável. Não use **`__assume`** em uma declaração para a qual você tenha o código de recuperação de erro subsequente porque o compilador pode otimizar o código de tratamento de erros.

A instrução `__assume(0)` é um caso especial. Use `__assume(0)` para indicar um caminho de código que não pode ser alcançado. O exemplo a seguir mostra como usar `__assume(0)` para indicar que o caso de padrão de uma instrução switch não pode ser alcançado. Isso mostra o uso mais comum de `__assume(0)`.

Para compatibilidade com versões anteriores, **`_assume`** é um sinônimo para **`__assume`** , a menos que a opção do compilador [/za \( desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

## <a name="requirements"></a>Requisitos

|Intrinsic|Arquitetura|
|---------------|------------------|
|**`__assume`**|x86, ARM, x64, ARM64|

## <a name="example"></a>Exemplo

```cpp
// compiler_intrinsics__assume.cpp
#ifdef DEBUG
# define ASSERT(e)    ( ((e) || assert(__FILE__, __LINE__) )
#else
# define ASSERT(e)    ( __assume(e) )
#endif

void func1(int i)
{
}

int main(int p)
{
   switch(p){
      case 1:
         func1(1);
         break;
      case 2:
         func1(-1);
         break;
      default:
         __assume(0);
            // This tells the optimizer that the default
            // cannot be reached. As so, it does not have to generate
            // the extra code to check that 'p' has a value
            // not represented by a case arm. This makes the switch
            // run faster.
   }
}
```

O uso de `__assume(0)` informa ao otimizador que o caso padrão não pode ser acessado.  O exemplo demonstra que o programador sabe que as entradas possíveis para `p` será 1 ou 2. Se outro valor for passado `p`, o programa se tornará inválido e causará um comportamento imprevisível.

Como resultado da instrução `__assume(0)`, o compilador não gera código para testar se `p` possui um valor que não é representado em uma instrução de caso. Para que isso funcione, a instrução `__assume(0)` deve ser a primeira no corpo do caso padrão.

Como o compilador gera código com base em **`__assume`** , esse código poderá não ser executado corretamente se a expressão dentro da **`__assume`** instrução for falsa em tempo de execução. Se você não tiver certeza de que a expressão sempre será verdadeira em tempo de execução, pode usar a função `assert` para proteger o código.

```C
#define ASSERT(e)    ( ((e) || assert(__FILE__, __LINE__)), __assume(e) )
```

Infelizmente, esse uso de `assert` impede que o compilador execute a otimização de caso padrão descrita anteriormente neste documento. Como alternativa, você pode usar uma macro separada, como a seguir.

```C
#ifdef DEBUG
# define NODEFAULT   ASSERT(0)
#else
# define NODEFAULT   __assume(0)
#endif

   default:
      NODEFAULT;
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[Palavras-chave](../cpp/keywords-cpp.md)
