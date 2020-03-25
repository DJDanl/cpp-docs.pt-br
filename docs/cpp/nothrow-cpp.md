---
title: nothrow (C++)
ms.date: 01/03/2018
f1_keywords:
- nothrow_cpp
helpviewer_keywords:
- __declspec keyword [C++], nothrow
- nothrow __declspec keyword
ms.assetid: 0a475139-459c-4ec6-99e8-7ecd0d7f44a3
ms.openlocfilehash: 8164f47190267627bdaf7c7ee2f03f22f65c8f50
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80161055"
---
# <a name="nothrow-c"></a>nothrow (C++)

**Seção específica da Microsoft**

Um **__declspec** atributo estendido que pode ser usado na declaração de funções.

## <a name="syntax"></a>Sintaxe

> *tipo de retorno* __declspec (nothrow) [*chamar-Convenção*] *nome-da-função* ([*argumento-lista*])

## <a name="remarks"></a>Comentários

É recomendável que todo o novo código use o operador [noexcept](noexcept-cpp.md) em vez de `__declspec(nothrow)`.

Esse atributo diz ao compilador que a função declarada, e as funções que ela chama nunca lançam uma exceção. No entanto, ele não impõe a diretiva. Em outras palavras, ele nunca faz com que [std:: Terminate](../standard-library/exception-functions.md#terminate) seja invocado, ao contrário de `noexcept`ou no modo **std: C++ 17** (Visual Studio 2017 versão 15,5 e posterior), `throw()`.

Com o modelo de tratamento de exceções síncronas, agora padrão, o compilador pode eliminar a mecânica de acompanhar o tempo de vida útil de determinados objetos desenroláveis nessa função e reduzir significativamente o tamanho do código. Dada a seguinte diretiva de pré-processador, as três declarações de função abaixo são equivalentes no modo **/std: c++ 14** :

```cpp
#define WINAPI __declspec(nothrow) __stdcall

void WINAPI f1();
void __declspec(nothrow) __stdcall f2();
void __stdcall f3() throw();
```

Em **/std: modo c++ 17** , `throw()` não é equivalente às outras que usam `__declspec(nothrow)` porque faz com que `std::terminate` seja invocado se uma exceção for lançada da função.

A declaração de `void __stdcall f3() throw();` usa a sintaxe definida pelo C++ padrão. Em C++ 17, a palavra-chave `throw()` foi preterida.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[__declspec](../cpp/declspec.md)<br/>
[noexcept](noexcept-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
