---
title: '&lt;istream&gt;'
ms.date: 11/04/2016
f1_keywords:
- istream/std::<istream>
- <istream>
- std::<istream>
helpviewer_keywords:
- istream header
ms.assetid: efcf24e4-05d1-4719-ab0b-9e7ebe845d89
ms.openlocfilehash: 15d955aca1406183cc348395068ba042b75d7417
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88846453"
---
# <a name="ltistreamgt"></a>&lt;istream&gt;

Define o modelo de classe basic_istream, que Media extrações para iostreams e o modelo de classe basic_iostream, que Media as inserções e extrações. O cabeçalho também define um manipulador relacionado. Esse arquivo de cabeçalho geralmente é incluído para você por outro cabeçalho iostreams, dificilmente você precisará incluí-lo diretamente.

## <a name="syntax"></a>Sintaxe

```cpp
#include <istream>
```

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[iostream](../standard-library/istream-typedefs.md#iostream)|Um tipo `basic_iostream` especializado em **`char`** .|
|[IStream](../standard-library/istream-typedefs.md#istream)|Um tipo `basic_istream` especializado em **`char`** .|
|[wiostream](../standard-library/istream-typedefs.md#wiostream)|Um tipo `basic_iostream` especializado em **wchar**.|
|[wistream](../standard-library/istream-typedefs.md#wistream)|Um tipo `basic_istream` especializado em **wchar**.|

### <a name="manipulators"></a>Manipuladores

|Nome|Descrição|
|-|-|
|[Federation](../standard-library/istream-functions.md#ws)|Ignora o espaço em branco no fluxo.|
|[permuta](../standard-library/istream-functions.md#istream_swap)|Troca dois objetos de fluxo.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[>>do operador ](../standard-library/istream-operators.md#op_gt_gt)|Extrai caracteres e cadeias de caracteres do fluxo.|

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[basic_iostream](../standard-library/basic-iostream-class.md)|Uma classe de fluxo que pode fazer tanto entrada quanto saída.|
|[basic_istream](../standard-library/basic-istream-class.md)|O modelo de classe descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo com elementos do tipo `Elem` , também conhecidos como [char_type](../standard-library/basic-ios-class.md#char_type), cujas características de caractere são determinadas pela classe `Tr` , também conhecida como [traits_type](../standard-library/basic-ios-class.md#traits_type).|

## <a name="see-also"></a>Confira também

[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação de iostream](../standard-library/iostream-programming.md)\
[Convenções de iostreams](../standard-library/iostreams-conventions.md)
