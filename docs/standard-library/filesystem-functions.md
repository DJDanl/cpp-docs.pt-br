---
title: Funções &lt;filesystem&gt; | Microsoft Docs
ms.custom: ''
ms.date: 09/10/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- FILESYSTEM/std::experimental::filesystem::absolute
- FILESYSTEM/std::experimental::filesystem::canonical
- FILESYSTEM/std::experimental::filesystem::copy
- FILESYSTEM/std::experimental::filesystem::copy_file
- FILESYSTEM/std::experimental::filesystem::copy_symlink
- FILESYSTEM/std::experimental::filesystem::create_directories
- FILESYSTEM/std::experimental::filesystem::create_directory
- FILESYSTEM/std::experimental::filesystem::create_directory_symlink
- FILESYSTEM/std::experimental::filesystem::create_hard_link
- FILESYSTEM/std::experimental::filesystem::create_symlink
- FILESYSTEM/std::experimental::filesystem::current_path
- FILESYSTEM/std::experimental::filesystem::equivalent
- FILESYSTEM/std::experimental::filesystem::exists
- FILESYSTEM/std::experimental::filesystem::file_size
- FILESYSTEM/std::experimental::filesystem::hard_link_count
- FILESYSTEM/std::experimental::filesystem::hash_value
- FILESYSTEM/std::experimental::filesystem::is_block_file
- FILESYSTEM/std::experimental::filesystem::is_character_file
- FILESYSTEM/std::experimental::filesystem::is_directory
- FILESYSTEM/std::experimental::filesystem::is_empty
- FILESYSTEM/std::experimental::filesystem::is_fifo
- FILESYSTEM/std::experimental::filesystem::is_other
- FILESYSTEM/std::experimental::filesystem::is_regular_file
- FILESYSTEM/std::experimental::filesystem::is_socket
- FILESYSTEM/std::experimental::filesystem::is_symlink
- FILESYSTEM/std::experimental::filesystem::last_write_time
- FILESYSTEM/std::experimental::filesystem::permissions
- FILESYSTEM/std::experimental::filesystem::read_symlink
- FILESYSTEM/std::experimental::filesystem::remove
- FILESYSTEM/std::experimental::filesystem::remove_all
- FILESYSTEM/std::experimental::filesystem::rename
- FILESYSTEM/std::experimental::filesystem::resize_file
- FILESYSTEM/std::experimental::filesystem::space
- FILESYSTEM/std::experimental::filesystem::status
- FILESYSTEM/std::experimental::filesystem::status_known
- FILESYSTEM/std::experimental::filesystem::swap
- FILESYSTEM/std::experimental::filesystem::symlink_status
- FILESYSTEM/std::experimental::filesystem::system_complete
- FILESYSTEM/std::experimental::filesystem::temp_directory_path
- FILESYSTEM/std::experimental::filesystem::u8path
dev_langs:
- C++
ms.assetid: be3cb821-4728-4d47-ab78-858fa8aa5045
author: corob-msft
ms.author: corob
helpviewer_keywords:
- std::experimental::filesystem::absolute
- std::experimental::filesystem::canonical
- std::experimental::filesystem::copy
- std::experimental::filesystem::copy_file
- std::experimental::filesystem::copy_symlink
- std::experimental::filesystem::create_directories
- std::experimental::filesystem::create_directory
- std::experimental::filesystem::create_directory_symlink
- std::experimental::filesystem::create_hard_link
- std::experimental::filesystem::create_symlink
- std::experimental::filesystem::current_path
- std::experimental::filesystem::equivalent
- std::experimental::filesystem::exists
- std::experimental::filesystem::file_size
- std::experimental::filesystem::hard_link_count
- std::experimental::filesystem::hash_value
- std::experimental::filesystem::is_block_file
- std::experimental::filesystem::is_character_file
- std::experimental::filesystem::is_directory
- std::experimental::filesystem::is_empty
- std::experimental::filesystem::is_fifo
- std::experimental::filesystem::is_other
- std::experimental::filesystem::is_regular_file
- std::experimental::filesystem::is_socket
- std::experimental::filesystem::is_symlink
- std::experimental::filesystem::last_write_time
- std::experimental::filesystem::permissions
- std::experimental::filesystem::read_symlink
- std::experimental::filesystem::remove
- std::experimental::filesystem::remove_all
- std::experimental::filesystem::rename
- std::experimental::filesystem::resize_file
- std::experimental::filesystem::space
- std::experimental::filesystem::status
- std::experimental::filesystem::status_known
- std::experimental::filesystem::swap
- std::experimental::filesystem::symlink_status
- std::experimental::filesystem::system_complete
- std::experimental::filesystem::temp_directory_path
- std::experimental::filesystem::u8path
ms.workload:
- cplusplus
ms.openlocfilehash: 8fcf7260b6bb10e317a3244ee11b4a92658daf45
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50063296"
---
# <a name="ltfilesystemgt-functions"></a>Funções &lt;filesystem&gt;

Essas funções livres no cabeçalho [\<filesystem>](../standard-library/filesystem.md) realizam operações de modificação e consulta em caminhos, arquivos, symlinks, diretórios e volumes. Para obter mais informações e exemplos de código, consulte [Navegação do Sistema de Arquivos (C++)](../standard-library/file-system-navigation.md).
||||
|-|-|-|
|[absolute](#absolute)|[begin](#begin)|[canonical](#canonical)|
|[copy](#copy)|[copy_file](#copy_file)|[copy_symlink](#copy_symlink)|
|[create_directories](#create_directories)|[create_directory](#create_directory)|[create_directory_symlink](#create_directory_symlink)|
|[create_hard_link](#create_hard_link)|[create_symlink](#create_symlink)|[current_path](#current_path)|
|[end](#end)|[equivalent](#equivalent)|[exists](#exists)|
|[file_size](#file_size)|[hard_link_count](#hard_link_count)|[hash_value](#hash_value)|
|[is_block_file](#is_block_file)|[is_character_file](#is_character_file)|[is_directory](#is_directory)|
|[is_empty](#is_empty)|[is_fifo](#is_fifo)|[is_other](#is_other)|
|[is_regular_file](#is_regular_file)|[is_socket](#is_socket)|[is_symlink](#is_symlink)|
|[last_write_time](#last_write_time)|[permissions](#permissions)|[read_symlink](#read_symlink)|
|[remove](#remove)|[remove_all](#remove_all)|[rename](#rename)|
|[resize_file](#resize_file)|[space](#space)|[status](#status)|
|[status_known](#status_known)|[swap](#swap)|[symlink_status](#symlink_status)|
|[system_complete](#system_complete)|[temp_directory_path](#temp_directory_path)|[u8path](#u8path)|

## <a name="absolute"></a> absoluto

```cpp
path absolute(const path& pval, const path& base = current_path());
```

A função retorna o nome de caminho absoluto correspondente *pval* em relação ao nome do caminho `base`:

1. Se `pval.has_root_name() && pval.has_root_directory()` a função retornará *pval*.

1. Se `pval.has_root_name() && !pval.has_root_directory()` a função retornará `pval.root_name()`  /  `absolute(base).root_directory()`  /  `absolute(base).relative_path()`  /  `pval.relative_path()`.

1. Se `!pval.has_root_name() && pval.has_root_directory()` a função retornará `absolute(base).root_name()`  /  *pval*.

1. Se `!pval.has_root_name() && !pval.has_root_directory()` a função retornará `absolute(base)`  /  *pval*.

## <a name="begin"></a>  begin

```cpp
const directory_iterator& begin(const directory_iterator& iter) noexcept;
const recursive_directory_iterator&
    begin(const recursive_directory_iterator& iter) noexcept;
```

Ambas as funções retornam *iter*.

## <a name="canonical"></a>  canonical

```cpp
path canonical(const path& pval, const path& base = current_path());
path canonical(const path& pval, error_code& ec);
path canonical(const path& pval, const path& base, error_code& ec);
```

Todas as funções formam um nome de caminho absoluto `pabs = absolute(pval, base)` (ou `pabs = absolute(pval)` para a sobrecarga sem parâmetro base), em seguida, reduzi-lo a uma forma canônica na seguinte sequência de etapas:

1. Cada componente de caminho `X` para o qual `is_symlink(X)` é **verdadeiro** é substituído pelo `read_symlink(X)`.

1. Cada componente de caminho `.` (o ponto é o diretório atual estabelecido pelos componentes de caminho anteriores) é removido.

1. Cada par de componentes de caminho `X` / `..` (ponto-ponto é o diretório pai estabelecido por componentes de caminho anteriores) é removido.

A função retorna `pabs`.

## <a name="copy"></a>  copy

```cpp
void copy(const path& from, const path& to);
void copy(const path& from, const path& to, error_code& ec) noexcept;
void copy(const path& from, const path& to, copy_options opts);
void copy(const path& from, const path& to, copy_options opts, error_code& ec) noexcept;
```

As funções de tudo, possivelmente, copiam ou vinculam um ou mais arquivos no *de* para *à* sob controle do *opts*, que é interpretado como `copy_options::none` para as sobrecargas com nenhum *opts* parâmetro. *opts* deve conter no máximo um de:

- `skip_existing`, `overwrite_existing` ou `update_existing`

- `copy_symlinks` ou `skip_symlinks`

- `directories_only`, `create_symlinks` ou `create_hard_links`

As funções primeiro determinam os valores de file_status `f` para *partir* e `t` para *para*:

- Se `opts & (copy_options::create_symlinks | copy_options::skip_symlinks)`, chamando `symlink_status`

- Caso contrário, chamando `status`

- Caso contrário, geram um erro.

Se `!exists(f) || equivalent(f, t) || is_other(f) || is_other(t) || is_directory(f)&& is_regular_file(t)`, em seguida, eles relate um erro (e não fizer mais nada).

Caso contrário, se `is_symlink(f)` então:

- Se `options & copy_options::skip_symlinks` , em seguida, não faça nada.

- Caso contrário, se `!exists(t)&& options & copy_options::copy_symlinks` , em seguida, `copy_symlink(from, to, opts)`.

- Caso contrário, geram um erro.

Caso contrário, se `is_regular_file(f)` então:

- Se `opts & copy_options::directories_only` , em seguida, não faça nada.

- Caso contrário, se `opts & copy_options::create_symlinks` , em seguida, `create_symlink(to, from)`.

- Caso contrário, se `opts & copy_options::create_hard_links` , em seguida, `create_hard_link(to, from)`.

- Caso contrário, se `is_directory(f)` , em seguida, `copy_file(from, to`  /  `from.filename(), opts)`.

- Caso contrário, `copy_file(from, to, opts)`.

Caso contrário, se `is_directory(f) && (opts & copy_options::recursive || !opts)` então:

```cpp
if (!exists(t))
{  // copy directory contents recursively
    create_directory(to, from, ec);

    for (directory_iterator next(from), end; ec == error_code() && next != end; ++next)
    {
        copy(next->path(), to / next->path().filename(), opts, ec);
    }
}
```

Caso contrário, não faça nada.

## <a name="copy_file"></a>  copy_file

```cpp
bool copy_file(const path& from, const path& to);
bool copy_file(const path& from, const path& to, error_code& ec) noexcept;
bool copy_file(const path& from, const path& to, copy_options opts);
bool copy_file(const path& from, const path& to, copy_options opts, error_code& ec) noexcept;
```

As funções de tudo, possivelmente, copiam o arquivo *de* para *ao* sob controle do *opts*, que é interpretado como `copy_options::none` para as sobrecargas sem *opts*  parâmetro. *opts* deve conter no máximo um dos `skip_existing`, `overwrite_existing`, ou `update_existing`.

Se `exists(to) && !(opts & (copy_options::skip_existing | copy_options::overwrite_existing | copy_options::update_existing))` , em seguida, o relatório como um erro se o arquivo já existe.

Caso contrário, se `!exists(to) || opts & copy_options::overwrite_existing || opts & copy_options::update_existing&& last_write_time(to) < last_write_time(from) || !(opts & (copy_options::skip_existing | copy_options::overwrite_existing | copy_options:update_existing))` , em seguida, tente copiar o conteúdo e os atributos do arquivo *partir* para o arquivo *para*. Relatar um erro se a tentativa de cópia falhar.

As funções retornam **verdadeira** se a tentativa de cópia for for bem-sucedida, caso contrário **falso**.

## <a name="copy_symlink "></a>  copy_symlink

```cpp
void copy_symlink(const path& from, const path& to);
void copy_symlink(const path& from, const path& to, error_code& ec) noexcept;
```

Se `is_directory(from)` as chamadas de função `create_directory_symlink(from, to)`. Caso contrário, ele chama `create_symlink(from, to)`.

## <a name="create_directories"></a>  create_directories

```cpp
bool create_directories(const path& pval);
bool create_directories(const path& pval, error_code& ec) noexcept;
```

Para um nome de caminho como a\/b\/c, a função cria os diretórios a e a\/b conforme necessário, para que possa criar o diretório a\/b\/c conforme necessário. Ele retorna **verdadeira** somente se ele realmente cria o diretório *pval*.

## <a name="create_directory"></a>  create_directory

```cpp
bool create_directory(const path& pval);

bool create_directory(const path& pval, error_code& ec) noexcept;
bool create_directory(const path& pval, const path& attr);
bool create_directory(const path& pval, const path& attr, error_code& ec) noexcept;
```

A função cria o diretório *pval* conforme necessário. Ela retorna true somente se ele realmente cria o diretório *pval*, caso em que ele copia as permissões do arquivo existente *attr*, ou usa `perms::all` para as sobrecargas sem *attr*  parâmetro.

## <a name="create_directory_symlink "></a>  create_directory_symlink

```cpp
void create_directory_symlink(const path& to, const path& link);
void create_directory_symlink(const path& to, const path& link, error_code& ec) noexcept;
```

A função cria o link como um symlink para o diretório *para*.

## <a name="create_hard_link"></a>  create_hard_link

```cpp
void create_hard_link(const path& to,  const path& link);
void create_hard_link(const path& to, const path& link, error_code& ec) noexcept;
```

A função cria o link como um link físico para o arquivo ou diretório *para*.

## <a name="create_symlink "></a>  create_symlink

```cpp
void create_symlink(const path& to,  const path& link);

void create_symlink(const path& to, const path& link, error_code& ec) noexcept;
```

A função cria *link* como um symlink para o arquivo *para*.

## <a name="current_path"></a>  current_path

```cpp
path current_path();
path current_path(error_code& ec);
void current_path(const path& pval);
void current_path(const path& pval, error_code& ec) noexcept;
```

As funções sem parâmetro *pval* retornar o nome do caminho para o diretório atual. As funções restantes definem o diretório atual como *pval*.

## <a name="end"></a>  end

```cpp
directory_iterator& end(const directory_iterator& iter) noexcept;
recursive_directory_iterator& end(const recursive_directory_iterator& iter) noexcept;
```

A primeira função retorna `directory_iterator()` e a segunda função retorna `recursive_directory_iterator()`

## <a name="equivalent"></a>  equivalent

```cpp
bool equivalent(const path& left, const path& right);
bool equivalent(const path& left, const path& right, error_code& ec) noexcept;
```

As funções retornam **verdadeira** somente se *esquerdo* e *direita* designar a mesma entidade de sistema de arquivos.

## <a name="exists"></a>  exists

```cpp
bool exists(file_status stat) noexcept;
bool exists(const path& pval);
bool exists(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `status_known && stat.type() != file_not_found`. A segunda e terceira funções retornam `exists(status(pval))`.

## <a name="file_size"></a>  file_size

```cpp
uintmax_t file_size(const path& pval);
uintmax_t file_size(const path& pval, error_code& ec) noexcept;
```

As funções retornam o tamanho em bytes do arquivo designado por *pval*, se `exists(pval) && is_regular_file(pval)` e o tamanho do arquivo pode ser determinado. Caso contrário, eles relatam um erro e retornam `uintmax_t(-1)`.

## <a name="hard_link_count"></a>  hard_link_count

```cpp
uintmax_t hard_link_count(const path& pval);
uintmax_t hard_link_count(const path& pval, error_code& ec) noexcept;
```

A função retorna o número de links físicos para *pval*, ou \-1 se ocorrer um erro.

## <a name="hash_value"></a>  hash_value

```cpp
size_t hash_value(const path& pval) noexcept;
```

A função retorna um valor de hash para `pval.native()`.

## <a name="is_block_file"></a>  is_block_file

```cpp
bool is_block_file(file_status stat) noexcept;
bool is_block_file(const path& pval);
bool is_block_file(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::block`. As funções restantes retornam `is_block_file(status(pval))`.

## <a name="is_character_file"></a>  is_character_file

```cpp
bool is_character_file(file_status stat) noexcept;
bool is_character_file(const path& pval);
bool is_character_file(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::character`. As funções restantes retornam `is_character_file(status(pval))`.

## <a name="is_directory "></a>  is_directory

```cpp
bool is_directory(file_status stat) noexcept;
bool is_directory(const path& pval);
bool is_directory(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::directory`. As funções restantes retornam `is_directory_file(status(pval))`.

## <a name="is_empty"></a>  is_empty

```cpp
bool is_empty(file_status stat) noexcept;
bool is_empty(const path& pval);
bool is_empty(const path& pval, error_code& ec) noexcept;
```

Se `is_directory(pval)` a função retornará `directory_iterator(pval) == directory_iterator()`; caso contrário, retornará `file_size(pval) == 0`.

## <a name="is_fifo"></a>  is_fifo

```cpp
bool is_fifo(file_status stat) noexcept;
bool is_fifo(const path& pval);
bool is_fifo(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::fifo`. As funções restantes retornam `is_fifo(status(pval))`.

## <a name="is_other"></a>  is_other

```cpp
bool is_other(file_status stat) noexcept;
bool is_other(const path& pval);
bool is_other(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::other`. As funções restantes retornam `is_other(status(pval))`.

## <a name="s_regular_file"></a>  is_regular_file

```cpp
bool is_regular_file(file_status stat) noexcept;
bool is_regular_file(const path& pval);
bool is_regular_file(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::regular`. As funções restantes retornam `is_regular_file(status(pval))`.

## <a name="is_socket"></a>  is_socket

```cpp
bool is_socket(file_status stat) noexcept;
bool is_socket(const path& pval);
bool is_socket(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::socket`. As funções restantes retornam `is_socket(status(pval))`.

## <a name="is_symlink"></a>  is_symlink

```cpp
bool is_symlink(file_status stat) noexcept;
bool is_symlink(const path& pval);
bool is_symlink(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::symlink`. As funções restantes retornam `is_symlink(status(pval))`.

## <a name="last_write_time"></a>  last_write_time

```cpp
file_time_type last_write_time(const path& pval);
file_time_type last_write_time(const path& pval, error_code& ec) noexcept;
void last_write_time(const path& pval, file_time_type new_time);
void last_write_time(const path& pval, file_time_type new_time, error_code& ec) noexcept;
```

As duas primeiras funções retornam a hora da última modificação de dados para *pval*, ou `file_time_type(-1)` se ocorrer um erro. As duas últimas funções definem a hora da última modificação de dados para *pval* à *new_time*.

## <a name="permissions"></a>  permissions

```cpp
void permissions(const path& pval, perms mask);
void permissions(const path& pval, perms mask, error_code& ec) noexcept;
```

As funções definem as permissões para o caminho de arquivo designado por *pval* à `mask & perms::mask` sob o controle de `perms & (perms::add_perms | perms::remove_perms)`. *máscara* deve conter no máximo um dos `perms::add_perms` e `perms::remove_perms`.

Se `mask & perms::add_perms` as funções definem as permissões como `status(pval).permissions() | mask & perms::mask`. Caso contrário, se `mask & perms::remove_perms` as funções definem as permissões como `status(pval).permissions() & ~(mask & perms::mask)`. Caso contrário, as funções definem as permissões como `mask & perms::mask`.

## <a name="read_symlink"></a>  read_symlink

```cpp
path read_symlink(const path& pval);
path read_symlink(const path& pval, error_code& ec);
```

As funções relatam um erro e retornam `path()` se `!is_symlink(pval)`. Caso contrário, as funções retornam um objeto do tipo `path` contendo o link simbólico.

## <a name="remove"></a>  remove

```cpp
bool remove(const path& pval);
bool remove(const path& pval, error_code& ec) noexcept;
```

As funções retornam **verdadeira** somente se `exists(symlink_status(pval))` e o arquivo for removido com êxito. O próprio symlink é removido e não o arquivo que ele designa.

## <a name="remove_all"></a>  remove_all

```cpp
uintmax_t remove_all(const path& pval);
uintmax_t remove_all(const path& pval, error_code& ec) noexcept;
```

Se *pval* é um diretório, as funções removem recursivamente todas as entradas de diretório e, em seguida, a entrada em si. Caso contrário, as funções chamam `remove`. Elas retornam uma contagem de todos os elementos removidos com êxito.

## <a name="rename"></a>  rename

```cpp
void rename(const path& from,  const path& to);
void rename(const path& from,  const path& to, error_code& ec) noexcept;
```

As funções renomeiam *partir* para *para*. O próprio symlink é renomeado e não o arquivo que ele designa.

## <a name="resize_file"></a>  resize_file

```cpp
void resize(const path& pval, uintmax_t size);
void resize(const path& pval, uintmax_t size, error_code& ec) noexcept;
```

As funções alteram o tamanho de um arquivo, de modo que `file_size(pval) == size`

## <a name="space"></a>  space

```cpp
space_info space(const path& pval);
space_info space(const path& pval, error_code& ec) noexcept;
```

A função retorna informações sobre o volume designado por *pval*, em uma estrutura do tipo `space_info`. A estrutura contém `uintmax_t(-1)` para qualquer valor que não pode ser determinado.

## <a name="status"></a>  status

```cpp
file_status status(const path& pval);
file_status status(const path& pval, error_code& ec) noexcept;
```

As funções retornam o status do nome do caminho, o tipo de arquivo e as permissões, associados *pval*. O próprio symlink não é testado e sim o arquivo que ele designa.

## <a name="status_known"></a>  status_known

```cpp
bool status_known(file_status stat) noexcept;
```

A função retorna `stat.type() != file_type::none`

## <a name="swap"></a>  swap

```cpp
void swap(path& left, path& right) noexcept;
```

A função troca o conteúdo do *esquerdo* e *direita*.

## <a name="symlink_status"></a>  symlink_status

```cpp
file_status symlink_status(const path& pval);
file_status symlink_status(const path& pval, erroxr_code& ec) noexcept;
```

As funções retornam o status do symlink do nome do caminho, o tipo de arquivo e as permissões, associados *pval*. As funções se comportam da mesma como `status(pval)` , exceto que o próprio symlink é testado, não o arquivo que ele designa.

## <a name="system_complete"></a>  system_complete

```cpp
path system_complete(const path& pval);
path system_complete(const path& pval, error_code& ec);
```

As funções retornam um nome de caminho absoluto que leva em conta, conforme necessário, o diretório atual associado ao seu nome de raiz. \(Para Posix, as funções retornam `absolute(pval)`.\)

## <a name="temp_directory_path"></a>  temp_directory_path

```cpp
path temp_directory_path();
path temp_directory_path(error_code& ec);
```

As funções retornam um nome de caminho para um diretório adequado para armazenar arquivos temporários.

## <a name="u8path"></a>  u8path

```cpp
template <class Source>
path u8path(const Source& source);

template <class InIt>
path u8path(InIt first, InIt last);
```

A primeira função tem o mesmo comportamento `path(source)` e a segunda função se comporta da mesma como `path(first, last)` , exceto que a origem designada em cada caso é interpretada como uma sequência de elementos char codificados como UTF-8, independentemente do sistema de arquivos.
