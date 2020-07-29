---
title: '&lt;fstream&gt;'
ms.date: 11/04/2016
f1_keywords:
- <fstream>
helpviewer_keywords:
- fstream header
ms.assetid: 660de351-0489-41df-b239-40e0cdcab46b
ms.openlocfilehash: 46f65f746179740f2d67dd1ada2f96ab3fb6aaf6
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87203228"
---
# <a name="ltfstreamgt"></a>&lt;fstream&gt;

Define várias classes que dão suporte a operações de iostreams em sequências armazenadas em arquivos externos.

## <a name="syntax"></a>Sintaxe

```cpp
#include <fstream>
```

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[filebuf](../standard-library/fstream-typedefs.md#filebuf)|Um tipo `basic_filebuf` especializado em **`char`** parâmetros de modelo.|
|[fstream](../standard-library/fstream-typedefs.md#fstream)|Um tipo `basic_fstream` especializado em **`char`** parâmetros de modelo.|
|[ifstream](../standard-library/fstream-typedefs.md#ifstream)|Um tipo `basic_ifstream` especializado em **`char`** parâmetros de modelo.|
|[ofstream](../standard-library/fstream-typedefs.md#ofstream)|Um tipo `basic_ofstream` especializado em **`char`** parâmetros de modelo.|
|[wfstream](../standard-library/fstream-typedefs.md#wfstream)|Um tipo `basic_fstream` especializado em **`wchar_t`** parâmetros de modelo.|
|[wifstream](../standard-library/fstream-typedefs.md#wifstream)|Um tipo `basic_ifstream` especializado em **`wchar_t`** parâmetros de modelo.|
|[wofstream](../standard-library/fstream-typedefs.md#wofstream)|Um tipo `basic_ofstream` especializado em **`wchar_t`** parâmetros de modelo.|
|[wfilebuf](../standard-library/fstream-typedefs.md#wfilebuf)|Um tipo `basic_filebuf` especializado em **`wchar_t`** parâmetros de modelo.|

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[basic_filebuf](../standard-library/basic-filebuf-class.md)|O modelo de classe descreve um buffer de fluxo que controla a transmissão de elementos do tipo `Elem` , cujas características de caractere são determinadas pela classe `Tr` , de e para uma sequência de elementos armazenados em um arquivo externo.|
|[basic_fstream](../standard-library/basic-fstream-class.md)|O modelo de classe descreve um objeto que controla a inserção e a extração de elementos e objetos codificados usando um buffer de fluxo de [basic_filebuf](../standard-library/basic-filebuf-class.md)de classe \<**Elem**, **Tr**> , com elementos do tipo `Elem` , cujas características de caractere são determinadas pela classe `Tr` .|
|[basic_ifstream](../standard-library/basic-ifstream-class.md)|O modelo de classe descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo da classe [basic_filebuf](../standard-library/basic-filebuf-class.md) \<**Elem**, **Tr**> , com elementos do tipo `Elem` , cujas características de caractere são determinadas pela classe `Tr` .|
|[basic_ofstream](../standard-library/basic-ofstream-class.md)|O modelo de classe descreve um objeto que controla a inserção de elementos e objetos codificados em um buffer de fluxo da classe [basic_filebuf](../standard-library/basic-filebuf-class.md) \<**Elem**, **Tr**> , com elementos do tipo `Elem` , cujas características de caractere são determinadas pela classe `Tr` .|

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação de iostream](../standard-library/iostream-programming.md)\
[Convenções de iostreams](../standard-library/iostreams-conventions.md)
