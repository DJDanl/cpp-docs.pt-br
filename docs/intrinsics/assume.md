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
ms.openlocfilehash: f3f847b5268605bdc5df90a8bbc6a88c78431864
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216968"
---
# <a name="__assume"></a>__assume

**Seção específica da Microsoft**

Passa uma dica para o otimizador.

## <a name="syntax"></a>Sintaxe

```C
__assume(
   expression
)
```

### <a name="parameters"></a>Parâmetros

*expressão*\
Qualquer expressão supostamente avaliada como verdadeira.

## <a name="remarks"></a>Comentários

O otimizador presume que a condição representada por `expression` é verdadeira no ponto em que a palavra-chave aparece e permanece verdadeira até que a `expression` seja modificada (por exemplo, atribuindo a uma variável). O uso seletivo de dicas passadas para o otimizador por `__assume` pode melhorar a otimização.

Se a instrução `__assume` for gravada como uma contradição (uma expressão que sempre avalia como falso), ela sempre será tratada como `__assume(0)`. Se seu código não está funcionando como esperado, verifique se a `expression` que você definiu é válida e verdadeira, conforme descrito anteriormente. Para obter mais informações sobre comportamento esperado de `__assume(0)`, consulte os comentários posteriores.

> [!WARNING]
>  Um programa não deve conter uma instrução `__assume` inválida em um caminho acessível. Se o compilador puder acessar uma instrução `__assume` inválida, o programa pode causar comportamento imprevisível e potencialmente perigoso.

`__assume` não é um intrínseco verdadeiro. Ele não precisa ser declarado como uma função e não pode ser usado em uma diretiva `#pragma intrinsic`. Embora nenhum código seja gerado, o código gerado pelo otimizador é afetado.

Use `__assume` em uma [declaração](../c-runtime-library/reference/assert-asserte-assert-expr-macros.md) somente quando Assert não for recuperável. Não use `__assume` em um assert para o qual você tem código de recuperação de erro subsequente porque o compilador pode otimizar o código de tratamento do erro.

A instrução `__assume(0)` é um caso especial. Use `__assume(0)` para indicar um caminho de código que não pode ser alcançado. O exemplo a seguir mostra como usar `__assume(0)` para indicar que o caso de padrão de uma instrução switch não pode ser alcançado. Isso mostra o uso mais comum de `__assume(0)`.

Para compatibilidade com as versões anteriores, **_assume** é um sinônimo para **__assume** , a menos que a opção de compilador [/za \(desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__assume`|x86, ARM, x64, ARM64|

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

O uso de `__assume(0)` informa ao otimizador que o caso padrão não pode ser acessado. O exemplo demonstra que o programador sabe que as entradas possíveis para `p` será 1 ou 2. Se outro valor for passado `p`, o programa se tornará inválido e causará um comportamento imprevisível.

Como resultado da instrução `__assume(0)`, o compilador não gera código para testar se `p` possui um valor que não é representado em uma instrução de caso. Para que isso funcione, a instrução `__assume(0)` deve ser a primeira no corpo do caso padrão.

Como o compilador gera código com base em `__assume`, esse código pode não ser executado corretamente se expressão dentro da instrução `__assume` for falsa em tempo de execução. Se você não tiver certeza de que a expressão sempre será verdadeira em tempo de execução, pode usar a função `assert` para proteger o código.

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

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[Palavras-chave](../cpp/keywords-cpp.md)
