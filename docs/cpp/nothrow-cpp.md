---
title: nothrow (C++)
ms.date: 01/03/2018
f1_keywords:
- nothrow_cpp
helpviewer_keywords:
- __declspec keyword [C++], nothrow
- nothrow __declspec keyword
ms.assetid: 0a475139-459c-4ec6-99e8-7ecd0d7f44a3
ms.openlocfilehash: 88041b374cc48ac31c8990aa7f867ba25b33e1d7
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64345876"
---
# <a name="nothrow-c"></a>nothrow (C++)

**Seção específica da Microsoft**

Um **declspec** atributo estendido que pode ser usado na declaração de funções.

## <a name="syntax"></a>Sintaxe

> *return-type* __declspec(nothrow) [*call-convention*] *function-name* ([*argument-list*])

## <a name="remarks"></a>Comentários

É recomendável que todos os novos códigos usem o [noexcept](noexcept-cpp.md) operador em vez de `__declspec(nothrow)`.

Esse atributo diz ao compilador que a função declarada, e as funções que ela chama nunca lançam uma exceção. No entanto, ele não impõe a diretiva. Em outras palavras, ele nunca faz com que [std:: Terminate](../standard-library/exception-functions.md#terminate) a ser invocado, ao contrário `noexcept`, ou no **/std: c + + 17** (Visual Studio 2017 versão 15.5 e posteriores), de modo `throw()`.

Com o modelo de tratamento de exceções síncronas, agora padrão, o compilador pode eliminar a mecânica de acompanhar o tempo de vida útil de determinados objetos desenroláveis nessa função e reduzir significativamente o tamanho do código. Dada a seguinte diretiva de pré-processador, as três declarações de função abaixo são equivalentes **/std: c + + 14** modo:

```cpp
#define WINAPI __declspec(nothrow) __stdcall

void WINAPI f1();
void __declspec(nothrow) __stdcall f2();
void __stdcall f3() throw();
```

Na **/std:c++17 + + 17** modo, `throw()` não é equivalente de outras pessoas que usam `__declspec(nothrow)` porque ele faz com que `std::terminate` a ser chamado se uma exceção é gerada a partir da função.

O `void __stdcall f3() throw();` declaração usa a sintaxe definida pelo padrão C++. No C++ 17 a `throw()` palavra-chave foi preterida.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__declspec](../cpp/declspec.md)<br/>
[noexcept](noexcept-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)