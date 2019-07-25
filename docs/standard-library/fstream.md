---
title: '&lt;fstream&gt;'
ms.date: 11/04/2016
f1_keywords:
- <fstream>
helpviewer_keywords:
- fstream header
ms.assetid: 660de351-0489-41df-b239-40e0cdcab46b
ms.openlocfilehash: ba6a4152b8d37f5b0186f9d05c6ba850e8c2e54c
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68454016"
---
# <a name="ltfstreamgt"></a>&lt;fstream&gt;

Define várias classes que dão suporte a operações de iostreams em sequências armazenadas em arquivos externos.

## <a name="syntax"></a>Sintaxe

```cpp
#include <fstream>
```

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[filebuf](../standard-library/fstream-typedefs.md#filebuf)|Um tipo `basic_filebuf` especializado em parâmetros de modelo **Char** .|
|[fstream](../standard-library/fstream-typedefs.md#fstream)|Um tipo `basic_fstream` especializado em parâmetros de modelo **Char** .|
|[ifstream](../standard-library/fstream-typedefs.md#ifstream)|Um tipo `basic_ifstream` especializado em parâmetros de modelo **Char** .|
|[ofstream](../standard-library/fstream-typedefs.md#ofstream)|Um tipo `basic_ofstream` especializado em parâmetros de modelo **Char** .|
|[wfstream](../standard-library/fstream-typedefs.md#wfstream)|Um tipo `basic_fstream` especializado em parâmetros de modelo **wchar_t** .|
|[wifstream](../standard-library/fstream-typedefs.md#wifstream)|Um tipo `basic_ifstream` especializado em parâmetros de modelo **wchar_t** .|
|[wofstream](../standard-library/fstream-typedefs.md#wofstream)|Um tipo `basic_ofstream` especializado em parâmetros de modelo **wchar_t** .|
|[wfilebuf](../standard-library/fstream-typedefs.md#wfilebuf)|Um tipo `basic_filebuf` especializado em parâmetros de modelo **wchar_t** .|

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[basic_filebuf](../standard-library/basic-filebuf-class.md)|A classe de modelo descreve um buffer de fluxo que controla a transmissão de elementos do tipo `Elem`, cujas características dos caracteres são determinadas pela classe `Tr`, para e de uma sequência de elementos armazenados em um arquivo externo.|
|[basic_fstream](../standard-library/basic-fstream-class.md)|A classe de modelo descreve um objeto que controla a inserção e a extração de elementos e objetos codificados usando um buffer de fluxo da classe [basic_filebuf](../standard-library/basic-filebuf-class.md)\<**elem**, **TR**>, com elementos do tipo `Elem`, cujos as características de caractere são determinadas pela classe `Tr`.|
|[basic_ifstream](../standard-library/basic-ifstream-class.md)|A classe de modelo descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo da classe [basic_filebuf](../standard-library/basic-filebuf-class.md)\<**elem**, **TR**> `Elem`, com elementos do tipo, cujas características de caractere são determinadas pela classe `Tr`.|
|[basic_ofstream](../standard-library/basic-ofstream-class.md)|A classe de modelo descreve um objeto que controla a inserção de elementos e objetos codificados em um buffer de fluxo da classe [basic_filebuf](../standard-library/basic-filebuf-class.md)\<**elem**, **TR**>, `Elem`com elementos do tipo, cujas características de caractere são determinadas pela classe `Tr`.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação de iostream](../standard-library/iostream-programming.md)\
[Convenções de iostreams](../standard-library/iostreams-conventions.md)
