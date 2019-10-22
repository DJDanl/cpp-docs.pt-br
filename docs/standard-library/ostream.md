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
ms.openlocfilehash: 3838e215ffac42ec6902ab6a9837f638153cf184
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689161"
---
# <a name="ltostreamgt"></a>&lt;ostream&gt;

Define o modelo de classe [basic_ostream](../standard-library/basic-ostream-class.md), que Media as inserções para o iostreams. O cabeçalho também define vários manipuladores relacionados. (Esse cabeçalho geralmente é incluído para você por outro cabeçalho iostreams. Raramente é necessário incluí-lo diretamente.)

## <a name="syntax"></a>Sintaxe

```cpp
#include <ostream>
```

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[ostream](../standard-library/ostream-typedefs.md#ostream)|Cria um tipo de `basic_ostream` que é especializado em **Char** e `char_traits` especializado em **Char**.|
|[wostream](../standard-library/ostream-typedefs.md#wostream)|Cria um tipo de `basic_ostream` que é especializado em **wchar_t** e `char_traits` especializado em **wchar_t**.|

### <a name="manipulators"></a>Manipuladores

|||
|-|-|
|[endl](../standard-library/ostream-functions.md#endl)|Termina uma linha e libera o buffer.|
|[ends](../standard-library/ostream-functions.md#ends)|Termina uma cadeia de caracteres.|
|[flush](../standard-library/ostream-functions.md#flush)|Libera o buffer.|
|[swap](../standard-library/ostream-functions.md#swap)|Troca os valores do parâmetro de objeto `basic_ostream` à esquerda por aqueles do parâmetro de objeto `basic_ostream` à direita.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator<<](../standard-library/ostream-operators.md#op_lt_lt)|Grava vários tipos no fluxo.|

### <a name="classes"></a>Classes

|Class|Descrição|
|-|-|
|[basic_ostream](../standard-library/basic-ostream-class.md)|O modelo de classe descreve um objeto que controla a inserção de elementos e objetos codificados em um buffer de fluxo.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação de iostream](../standard-library/iostream-programming.md)\
[Convenções de iostreams](../standard-library/iostreams-conventions.md)
