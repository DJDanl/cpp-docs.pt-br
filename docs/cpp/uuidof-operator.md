---
title: Operador __uuidof
ms.date: 10/10/2018
f1_keywords:
- __LIBID_cpp
- __uuidof_cpp
- __uuidof
- _uuidof
helpviewer_keywords:
- __uuidof keyword [C++]
- __LIBID_ keyword [C++]
ms.assetid: badfe709-809b-4b66-ad48-ee35039d25c6
ms.openlocfilehash: f7564270408d14f58d1528c1f41c0afd2dbe219c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226965"
---
# <a name="__uuidof-operator"></a>Operador `__uuidof`

**Específico da Microsoft**

Recupera o GUID vinculado à expressão.

## <a name="syntax"></a>Sintaxe

> **`__uuidof (`***expressão* de**`)`**

## <a name="remarks"></a>Comentários

A *expressão* pode ser um nome de tipo, um ponteiro, uma referência ou uma matriz desse tipo, um modelo especializado nesses tipos ou uma variável desses tipos. O argumento é válido enquanto o compilador puder usá-lo para localizar o GUID vinculado.

Um caso especial desse intrínseco é quando **0** ou NULL é fornecido como o argumento. Nesse caso, o **`__uuidof`** retornará um GUID formado por zeros.

Use essa palavra-chave para extrair o GUID vinculado a:

- Um objeto pelo [`uuid`](../cpp/uuid-cpp.md) atributo estendido.

- Um bloco de biblioteca criado com o [`module`](../windows/attributes/module-cpp.md) atributo.

> [!NOTE]
> Em uma compilação de depuração, o **`__uuidof`** sempre Inicializa um objeto dinamicamente (em tempo de execução). Em uma compilação de versão, o **`__uuidof`** pode, estaticamente (no momento da compilação) inicializar um objeto.

Para compatibilidade com versões anteriores, **`_uuidof`** é um sinônimo para **`__uuidof`** a menos que a opção do compilador [ `/Za` \( desabilite extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

## <a name="example"></a>Exemplo

O código a seguir (compilado com ole32.lib) exibirá o uuid de um bloco de biblioteca criado com o atributo module:

```cpp
// expre_uuidof.cpp
// compile with: ole32.lib
#include "stdio.h"
#include "windows.h"

[emitidl];
[module(name="MyLib")];
[export]
struct stuff {
   int i;
};

int main() {
   LPOLESTR lpolestr;
   StringFromCLSID(__uuidof(MyLib), &lpolestr);
   wprintf_s(L"%s", lpolestr);
   CoTaskMemFree(lpolestr);
}
```

## <a name="comments"></a>Comentários

Nos casos em que o nome da biblioteca não está mais no escopo, você pode usar `__LIBID_` em vez de **`__uuidof`** . Por exemplo:

```cpp
StringFromCLSID(__LIBID_, &lpolestr);
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
