---
title: '&lt;ostream&gt;'
ms.date: 11/04/2016
f1_keywords:
- <ostream>
- ostream/std::<ostream>
- std::<ostream>
helpviewer_keywords:
- ostream header
ms.assetid: 90c3b6fb-57cd-4ae7-99b8-8512f24a67d2
ms.openlocfilehash: 37642cbcbe57fba54f071a8fc94af53c97684a36
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228135"
---
# <a name="ltostreamgt"></a>&lt;ostream&gt;

Define o modelo de classe [basic_ostream](../standard-library/basic-ostream-class.md), que Media as inserções para o iostreams. O cabeçalho também define vários manipuladores relacionados. (Esse cabeçalho geralmente é incluído para você por outro cabeçalho iostreams. Raramente é necessário incluí-lo diretamente.)

## <a name="syntax"></a>Sintaxe

```cpp
#include <ostream>
```

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[ostream](../standard-library/ostream-typedefs.md#ostream)|Cria um tipo de `basic_ostream` que é especializado em **`char`** e `char_traits` especializado em **`char`** .|
|[wostream](../standard-library/ostream-typedefs.md#wostream)|Cria um tipo de `basic_ostream` que é especializado em **`wchar_t`** e `char_traits` especializado em **`wchar_t`** .|

### <a name="manipulators"></a>Manipuladores

|||
|-|-|
|[endl](../standard-library/ostream-functions.md#endl)|Termina uma linha e libera o buffer.|
|[lados](../standard-library/ostream-functions.md#ends)|Termina uma cadeia de caracteres.|
|[Libere](../standard-library/ostream-functions.md#flush)|Libera o buffer.|
|[permuta](../standard-library/ostream-functions.md#swap)|Troca os valores do parâmetro de objeto `basic_ostream` à esquerda por aqueles do parâmetro de objeto `basic_ostream` à direita.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[<<do operador](../standard-library/ostream-operators.md#op_lt_lt)|Grava vários tipos no fluxo.|

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[basic_ostream](../standard-library/basic-ostream-class.md)|O modelo de classe descreve um objeto que controla a inserção de elementos e objetos codificados em um buffer de fluxo.|

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação de iostream](../standard-library/iostream-programming.md)\
[Convenções de iostreams](../standard-library/iostreams-conventions.md)
