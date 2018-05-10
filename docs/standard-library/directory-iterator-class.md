---
title: Classe directory_iterator | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- filesystem/std::experimental::filesystem::directory_iterator
- filesystem/std::experimental::filesystem::_Directory_iterator::_Directory_iterator
- filesystem/std::experimental::filesystem::directory_iterator::directory_iterator
- filesystem/std::experimental::filesystem::directory_iterator::increment
- filesystem/std::experimental::filesystem::directory_iterator::operator=
- filesystem/std::experimental::filesystem::directory_iterator::operator==
- filesystem/std::experimental::filesystem::directory_iterator::operator!=
- filesystem/std::experimental::filesystem::directory_iterator::operator*
- filesystem/std::experimental::filesystem::directory_iterator::operator-&gt;
- filesystem/std::experimental::filesystem::directory_iterator::operator++
dev_langs:
- C++
ms.assetid: dca2ecf8-3e69-4644-a83d-705061e10cc8
author: corob-msft
ms.author: corob
helpviewer_keywords:
- std::experimental::filesystem::directory_iterator
- std::experimental::filesystem::_Directory_iterator::_Directory_iterator
- std::experimental::filesystem::directory_iterator
- std::experimental::filesystem::directory_iterator::directory_iterator
- std::experimental::filesystem::directory_iterator::increment
- std::experimental::filesystem::directory_iterator::operator=
- std::experimental::filesystem::directory_iterator::operator==
- std::experimental::filesystem::directory_iterator::operator!=
- std::experimental::filesystem::directory_iterator::operator*
- std::experimental::filesystem::directory_iterator::operator-&gt;
- std::experimental::filesystem::directory_iterator::operator++
ms.workload:
- cplusplus
ms.openlocfilehash: b46e4d8fc7b59f8b4919a7e36a85f29f626aa80b
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="directoryiterator-class"></a>Classe directory_iterator

Descreve um iterador de entrada que percorre em sequência os nomes de arquivo em um diretório. Para um iterador X, a expressão *X é avaliada como um objeto da classe directory_entry que encapsula o nome de arquivo e tudo conhecido sobre seu status.

A classe armazena um objeto de caminho de tipo, chamado mydir aqui para fins de exposição, que representa o nome do diretório a ser sequenciado e um objeto do tipo directory_entry chamado myentry aqui, que representa o nome de arquivo atual na sequência do diretório. Um objeto construído padrão do tipo directory_entry tem um nome de caminho mydir vazio e representa o iterador de fim de sequência.

Por exemplo, considerando o diretório abc com as entradas def e ghi, o código:

`for (directory_iterator next(path("abc")), end; next != end; ++next)     visit(next->path());`

fará uma visita por chamada com os argumentos path("abc/def") e path("abc/ghi").

Para obter mais informações e exemplos de código, consulte [Navegação do Sistema de Arquivos (C++)](../standard-library/file-system-navigation.md).

## <a name="syntax"></a>Sintaxe

```cpp
class directory_iterator;
```

## <a name="directoryiteratordirectoryiterator"></a>directory_iterator::directory_iterator

```cpp
directory_iterator() noexcept;
explicit directory_iterator(const path& pval);

directory_iterator(const path& pval, error_code& ec) noexcept;
directory_iterator(const directory_iterator&) = default;
directory_iterator(directory_iterator&&) noexcept = default;
```

O primeiro construtor produz um iterador de fim de sequência. Os segundo e terceiro construtores armazenam pval em mydir e, em seguida, tentam abrir e ler mydir como um diretório. Se tiverem êxito, eles armazenarão o primeiro nome de arquivo no diretório em myentry; caso contrário, produzirão um iterador de fim de sequência.

Os construtores usados como padrão se comportam como esperado.

## <a name="directoryiteratorincrement"></a>directory_iterator::increment

```cpp
directory_iterator& increment(error_code& ec) noexcept;
```

A função tenta avançar para o próximo nome de arquivo no diretório. Se tiver êxito, ela armazenará esse nome de arquivo em myentry; caso contrário, produzirá um iterador de fim de sequência.

## <a name="directoryiteratoroperator"></a>directory_iterator::operator!=

```cpp
bool operator!=(const directory_iterator& right) const;
```

O operador de membro retorna !(*this == right).

## <a name="directoryiteratoroperator"></a>directory_iterator::operator=

```cpp
directory_iterator& operator=(const directory_iterator&) = default;
directory_iterator& operator=(directory_iterator&&) noexcept = default;
```

Os operadores de atribuição de membro usados como padrão se comportam como esperado.

## <a name="directoryiteratoroperator"></a>directory_iterator::operator==

```cpp
bool operator==(const directory_iterator& right) const;
```

O operador de membro retornará verdadeiro somente se *this e right forem iteradores de fim de sequência ou ambos não forem iteradores de fim de sequência.

## <a name="directoryiteratoroperator"></a>directory_iterator::operator*

```cpp
const directory_entry& operator*() const;
```

O operador de membro retorna myentry.

## <a name="directoryiteratoroperator-"></a>directory_iterator::operator->

```cpp
const directory_entry * operator->() const;
```

A função de membro retorna &**this.

## <a name="directoryiteratoroperator"></a>directory_iterator::operator++

```cpp
directory_iterator& operator++();
directory_iterator& operator++(int);
```

A primeira função de membro chama increment() e, em seguida, retorna *this. A segunda função de membro faz uma cópia do objeto, chama increment() e retorna a cópia.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<experimental/filesystem>

**Namespace:** std::experimental::filesystem

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[\<filesystem>](../standard-library/filesystem.md)<br/>
[Navegação no sistema de arquivos (C++)](../standard-library/file-system-navigation.md)<br/>
