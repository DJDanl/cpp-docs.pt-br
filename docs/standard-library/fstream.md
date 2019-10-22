---
title: '&lt;fstream&gt;'
ms.date: 11/04/2016
f1_keywords:
- <fstream>
helpviewer_keywords:
- fstream header
ms.assetid: 660de351-0489-41df-b239-40e0cdcab46b
ms.openlocfilehash: 1f85367b9ae527c9387d085acc1496bfbbf7cc9e
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72688037"
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

|Class|Descrição|
|-|-|
|[basic_filebuf](../standard-library/basic-filebuf-class.md)|O modelo de classe descreve um buffer de fluxo que controla a transmissão de elementos do tipo `Elem`, cujas características de caractere são determinadas pela classe `Tr`, de e para uma sequência de elementos armazenados em um arquivo externo.|
|[basic_fstream](../standard-library/basic-fstream-class.md)|O modelo de classe descreve um objeto que controla a inserção e a extração de elementos e objetos codificados usando um buffer de fluxo da classe [basic_filebuf](../standard-library/basic-filebuf-class.md) \<**Elem**, **TR**>, com elementos do tipo `Elem`, cujo caractere as características são determinadas pela classe `Tr`.|
|[basic_ifstream](../standard-library/basic-ifstream-class.md)|O modelo de classe descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo da classe [basic_filebuf](../standard-library/basic-filebuf-class.md) \<**Elem**, **TR**>, com elementos do tipo `Elem`, cujas características de caracteres são determinado pela classe `Tr`.|
|[basic_ofstream](../standard-library/basic-ofstream-class.md)|O modelo de classe descreve um objeto que controla a inserção de elementos e objetos codificados em um buffer de fluxo da classe [basic_filebuf](../standard-library/basic-filebuf-class.md) \<**Elem**, **TR**>, com elementos do tipo `Elem`, cujas características de caracteres são determinadas pela classe `Tr`.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação de iostream](../standard-library/iostream-programming.md)\
[Convenções de iostreams](../standard-library/iostreams-conventions.md)
