---
title: Funções &lt;filesystem&gt;
ms.date: 03/27/2019
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
ms.assetid: be3cb821-4728-4d47-ab78-858fa8aa5045
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
ms.openlocfilehash: c637c4893a13df577fd6c083c8a4f2380c9c4cad
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219151"
---
# <a name="ltfilesystemgt-functions"></a>Funções &lt;filesystem&gt;

Essas funções gratuitas no [\<filesystem>](../standard-library/filesystem.md) cabeçalho modificam e consultam operações em caminhos, arquivos, symlinks, diretórios e volumes. Para obter mais informações e exemplos de código, consulte [Navegação do Sistema de Arquivos (C++)](../standard-library/file-system-navigation.md).

## <a name="absolute"></a><a name="absolute"></a>altos

```cpp
path absolute(const path& pval, const path& base = current_path());
```

A função retorna o nome de caminho absoluto correspondente a *PVal* relativo ao nome do caminho `base` :

1. Se `pval.has_root_name() && pval.has_root_directory()` a função retornar *PVal*.

1. Se `pval.has_root_name() && !pval.has_root_directory()` a função retornar `pval.root_name()`  /  `absolute(base).root_directory()`  /  `absolute(base).relative_path()`  /  `pval.relative_path()` .

1. Se `!pval.has_root_name() && pval.has_root_directory()` a função retornar `absolute(base).root_name()`  /  *PVal*.

1. Se `!pval.has_root_name() && !pval.has_root_directory()` a função retornar `absolute(base)`  /  *PVal*.

## <a name="begin"></a><a name="begin"></a>Comece

```cpp
const directory_iterator& begin(const directory_iterator& iter) noexcept;
const recursive_directory_iterator&
    begin(const recursive_directory_iterator& iter) noexcept;
```

Ambas as funções retornam *ITER*.

## <a name="canonical"></a><a name="canonical"></a>formato

```cpp
path canonical(const path& pval, const path& base = current_path());
path canonical(const path& pval, error_code& ec);
path canonical(const path& pval, const path& base, error_code& ec);
```

Todas as funções formam um nome de caminho absoluto `pabs = absolute(pval, base)` (ou `pabs = absolute(pval)` para a sobrecarga sem parâmetro base) e, em seguida, o reduzem para um formato canônico na seguinte sequência de etapas:

1. Cada componente `X` de caminho para o qual `is_symlink(X)` é **`true`** substituído por `read_symlink(X)` .

1. Cada componente `.` de caminho (ponto é o diretório atual estabelecido por componentes de caminho anteriores) é removido.

1. Cada par de componentes de caminho `X` / `..` (ponto-ponto é o diretório pai estabelecido por componentes de caminho anteriores) é removido.

Em seguida, a função retorna `pabs` .

## <a name="copy"></a><a name="copy"></a>CopiarObjeto

```cpp
void copy(const path& from, const path& to);
void copy(const path& from, const path& to, error_code& ec) noexcept;
void copy(const path& from, const path& to, copy_options opts);
void copy(const path& from, const path& to, copy_options opts, error_code& ec) noexcept;
```

Todas as funções, possivelmente, copiam ou vinculam um ou mais *to* arquivos *de a para* sob o controle de as *optas*, que é levado como `copy_options::none` para as sobrecargas sem parâmetro de nenhuma das *optas* . as *optas* devem conter no máximo um de:

- `skip_existing`, `overwrite_existing` ou `update_existing`

- `copy_symlinks` ou `skip_symlinks`

- `directories_only`, `create_symlinks` ou `create_hard_links`

As funções primeiro determinam os valores de file_status `f` para *de* e `t` para: *to*

- Se `opts & (copy_options::create_symlinks | copy_options::skip_symlinks)` , chamando`symlink_status`

- caso contrário, chamando`status`

- Caso contrário, geram um erro.

Se `!exists(f) || equivalent(f, t) || is_other(f) || is_other(t) || is_directory(f)&& is_regular_file(t)` , em seguida, eles relatam um erro (e não fazem mais nada).

Caso contrário, se `is_symlink(f)` :

- Se `options & copy_options::skip_symlinks` , em seguida, não faça nada.

- Caso contrário, se `!exists(t)&& options & copy_options::copy_symlinks` , então `copy_symlink(from, to, opts)` .

- Caso contrário, relate um erro.

Caso contrário, se `is_regular_file(f)` , então:

- Se `opts & copy_options::directories_only` , em seguida, não faça nada.

- Caso contrário, se `opts & copy_options::create_symlinks` , então `create_symlink(to, from)` .

- Caso contrário, se `opts & copy_options::create_hard_links` , então `create_hard_link(to, from)` .

- Caso contrário, se `is_directory(f)` , então `copy_file(from, to`  /  `from.filename(), opts)` .

- Caso contrário, `copy_file(from, to, opts)`.

Caso contrário, se `is_directory(f) && (opts & copy_options::recursive || !opts)` , então:

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

## <a name="copy_file"></a><a name="copy_file"></a>copy_file

```cpp
bool copy_file(const path& from, const path& to);
bool copy_file(const path& from, const path& to, error_code& ec) noexcept;
bool copy_file(const path& from, const path& to, copy_options opts);
bool copy_file(const path& from, const path& to, copy_options opts, error_code& ec) noexcept;
```

Todas as funções possivelmente copiam o arquivo *de* para *para* sob o controle de as *optas*, que é levado como `copy_options::none` para as sobrecargas sem parâmetro de *optas* . as *optas* devem conter no máximo um de `skip_existing` , `overwrite_existing` ou `update_existing` .

Se `exists(to) && !(opts & (copy_options::skip_existing | copy_options::overwrite_existing | copy_options::update_existing))` , em seguida, relate como um erro de que o arquivo já existe.

Caso contrário, se `!exists(to) || opts & copy_options::overwrite_existing || opts & copy_options::update_existing&& last_write_time(to) < last_write_time(from) || !(opts & (copy_options::skip_existing | copy_options::overwrite_existing | copy_options:update_existing))` , tente copiar o conteúdo e os atributos do arquivo *de* para o arquivo *para*. Relatar um erro se a tentativa de cópia falhar.

As funções retornam **`true`** se a cópia for tentada e tiver sucesso, caso contrário **`false`** .

## <a name="copy_symlink"></a><a name="copy_symlink"></a>copy_symlink

```cpp
void copy_symlink(const path& from, const path& to);
void copy_symlink(const path& from, const path& to, error_code& ec) noexcept;
```

Se `is_directory(from)` , a função chama `create_directory_symlink(from, to)` . Caso contrário, ele chama `create_symlink(from, to)` .

## <a name="create_directories"></a><a name="create_directories"></a>create_directories

```cpp
bool create_directories(const path& pval);
bool create_directories(const path& pval, error_code& ec) noexcept;
```

Para um nome de caminho como \/ b \/ c, a função cria os diretórios a e \/ b, conforme necessário, para que possa criar o diretório a \/ b \/ c, conforme necessário. Ele retorna **`true`** somente se ele realmente cria o diretório *PVal*.

## <a name="create_directory"></a><a name="create_directory"></a>create_directory

```cpp
bool create_directory(const path& pval);

bool create_directory(const path& pval, error_code& ec) noexcept;
bool create_directory(const path& pval, const path& attr);
bool create_directory(const path& pval, const path& attr, error_code& ec) noexcept;
```

A função cria o diretório *PVal* conforme necessário. Ele retornará true somente se ele realmente criar o diretório *PVal*, caso em que ele copia as permissões do *atributo*de arquivo existente ou usa `perms::all` para as sobrecargas sem parâmetro *attr* .

## <a name="create_directory_symlink"></a><a name="create_directory_symlink"></a>create_directory_symlink

```cpp
void create_directory_symlink(const path& to, const path& link);
void create_directory_symlink(const path& to, const path& link, error_code& ec) noexcept;
```

A função cria um link como um symlink para o diretório *para*.

## <a name="create_hard_link"></a><a name="create_hard_link"></a>create_hard_link

```cpp
void create_hard_link(const path& to,  const path& link);
void create_hard_link(const path& to, const path& link, error_code& ec) noexcept;
```

A função cria um link como um link físico para o diretório ou arquivo *para*.

## <a name="create_symlink"></a><a name="create_symlink"></a>create_symlink

```cpp
void create_symlink(const path& to, const path& link);

void create_symlink(const path& to, const path& link, error_code& ec) noexcept;
```

A função cria um *link* como um symlink para o arquivo *para*.

## <a name="current_path"></a><a name="current_path"></a>current_path

```cpp
path current_path();
path current_path(error_code& ec);
void current_path(const path& pval);
void current_path(const path& pval, error_code& ec) noexcept;
```

As funções sem parâmetro *PVal* retornam o nome do caminho para o diretório atual. As funções restantes definem o diretório atual como *PVal*.

## <a name="end"></a><a name="end"></a>completo

```cpp
directory_iterator& end(const directory_iterator& iter) noexcept;
recursive_directory_iterator& end(const recursive_directory_iterator& iter) noexcept;
```

A primeira função retorna `directory_iterator()` e a segunda função retorna`recursive_directory_iterator()`

## <a name="equivalent"></a><a name="equivalent"></a>equivalente

```cpp
bool equivalent(const path& left, const path& right);
bool equivalent(const path& left, const path& right, error_code& ec) noexcept;
```

As funções retornam **`true`** somente se *esquerda* e *direita* escolhem a mesma entidade FileSystem.

## <a name="exists"></a><a name="exists"></a>existe

```cpp
bool exists(file_status stat) noexcept;
bool exists(const path& pval);
bool exists(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `status_known && stat.type() != file_not_found`. A segunda e terceira funções retornam `exists(status(pval))` .

## <a name="file_size"></a><a name="file_size"></a>file_size

```cpp
uintmax_t file_size(const path& pval);
uintmax_t file_size(const path& pval, error_code& ec) noexcept;
```

As funções retornam o tamanho em bytes do arquivo escolhido por *PVal*, se `exists(pval) && is_regular_file(pval)` e o tamanho do arquivo puder ser determinado. Caso contrário, eles relatarão um erro e retornarão `uintmax_t(-1)` .

## <a name="hard_link_count"></a><a name="hard_link_count"></a>hard_link_count

```cpp
uintmax_t hard_link_count(const path& pval);
uintmax_t hard_link_count(const path& pval, error_code& ec) noexcept;
```

A função retornará o número de links físicos para *PVal*, ou \- 1 se ocorrer um erro.

## <a name="hash_value"></a><a name="hash_value"></a>hash_value

```cpp
size_t hash_value(const path& pval) noexcept;
```

A função retorna um valor de hash para `pval.native()` .

## <a name="is_block_file"></a><a name="is_block_file"></a>is_block_file

```cpp
bool is_block_file(file_status stat) noexcept;
bool is_block_file(const path& pval);
bool is_block_file(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::block`. As funções restantes retornam `is_block_file(status(pval))` .

## <a name="is_character_file"></a><a name="is_character_file"></a>is_character_file

```cpp
bool is_character_file(file_status stat) noexcept;
bool is_character_file(const path& pval);
bool is_character_file(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::character`. As funções restantes retornam `is_character_file(status(pval))` .

## <a name="is_directory"></a><a name="is_directory"></a>is_directory

```cpp
bool is_directory(file_status stat) noexcept;
bool is_directory(const path& pval);
bool is_directory(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::directory`. As funções restantes retornam `is_directory_file(status(pval))` .

## <a name="is_empty"></a><a name="is_empty"></a>is_empty

```cpp
bool is_empty(file_status stat) noexcept;
bool is_empty(const path& pval);
bool is_empty(const path& pval, error_code& ec) noexcept;
```

Se `is_directory(pval)` , a função retornará `directory_iterator(pval) == directory_iterator()` ; caso contrário, retornará `file_size(pval) == 0` .

## <a name="is_fifo"></a><a name="is_fifo"></a>is_fifo

```cpp
bool is_fifo(file_status stat) noexcept;
bool is_fifo(const path& pval);
bool is_fifo(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::fifo`. As funções restantes retornam `is_fifo(status(pval))` .

## <a name="is_other"></a><a name="is_other"></a>is_other

```cpp
bool is_other(file_status stat) noexcept;
bool is_other(const path& pval);
bool is_other(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::other`. As funções restantes retornam `is_other(status(pval))` .

## <a name="is_regular_file"></a><a name="is_regular_file"></a>is_regular_file

```cpp
bool is_regular_file(file_status stat) noexcept;
bool is_regular_file(const path& pval);
bool is_regular_file(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::regular`. As funções restantes retornam `is_regular_file(status(pval))` .

## <a name="is_socket"></a><a name="is_socket"></a>is_socket

```cpp
bool is_socket(file_status stat) noexcept;
bool is_socket(const path& pval);
bool is_socket(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::socket`. As funções restantes retornam `is_socket(status(pval))` .

## <a name="is_symlink"></a><a name="is_symlink"></a>is_symlink

```cpp
bool is_symlink(file_status stat) noexcept;
bool is_symlink(const path& pval);
bool is_symlink(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::symlink`. As funções restantes retornam `is_symlink(status(pval))` .

## <a name="last_write_time"></a><a name="last_write_time"></a>last_write_time

```cpp
file_time_type last_write_time(const path& pval);
file_time_type last_write_time(const path& pval, error_code& ec) noexcept;
void last_write_time(const path& pval, file_time_type new_time);
void last_write_time(const path& pval, file_time_type new_time, error_code& ec) noexcept;
```

As duas primeiras funções retornam a hora da última modificação de dados para *PVal*, ou `file_time_type(-1)` se ocorrer um erro. As duas últimas funções definem a hora da última modificação de dados para *PVal* para *NEW_TIME*.

## <a name="permissions"></a><a name="permissions"></a>permissões

```cpp
void permissions(const path& pval, perms mask);
void permissions(const path& pval, perms mask, error_code& ec) noexcept;
```

As funções definem as permissões para o nome de caminho escolhido por *PVal* como `mask & perms::mask` sob o controle de `perms & (perms::add_perms | perms::remove_perms)` . a *máscara* deve conter no máximo um de `perms::add_perms` e `perms::remove_perms` .

Se `mask & perms::add_perms` , as funções definirão as permissões como `status(pval).permissions() | mask & perms::mask` . Caso contrário, se `mask & perms::remove_perms` as funções definirem as permissões como `status(pval).permissions() & ~(mask & perms::mask)` . Caso contrário, as funções definirão as permissões como `mask & perms::mask` .

## <a name="proximate"></a><a name="proximate"></a>proximate

```cpp
path proximate(const path& p, error_code& ec);
path proximate(const path& p, const path& base = current_path());
path proximate(const path& p, const path& base, error_code& ec);
```

## <a name="read_symlink"></a><a name="read_symlink"></a>read_symlink

```cpp
path read_symlink(const path& pval);
path read_symlink(const path& pval, error_code& ec);
```

As funções relatam um erro e retornam `path()` If `!is_symlink(pval)` . Caso contrário, as funções retornam um objeto do tipo `path` contendo o link simbólico.

## <a name="relative"></a><a name="relative"></a>acordo

```cpp
path relative(const path& p, error_code& ec);
path relative(const path& p, const path& base = current_path());
path relative(const path& p, const path& base, error_code& ec);
```

## <a name="remove"></a><a name="remove"></a>exclu

```cpp
bool remove(const path& pval);
bool remove(const path& pval, error_code& ec) noexcept;
```

As funções retornam **`true`** apenas If `exists(symlink_status(pval))` e o arquivo é removido com êxito. Um symlink é removido, não o arquivo que ele escolhe.

## <a name="remove_all"></a><a name="remove_all"></a>remove_all

```cpp
uintmax_t remove_all(const path& pval);
uintmax_t remove_all(const path& pval, error_code& ec) noexcept;
```

Se *PVal* for um diretório, as funções removerão recursivamente todas as entradas de diretório e, em seguida, a própria entrada. Caso contrário, a chamada Functions `remove` . Elas retornam uma contagem de todos os elementos removidos com êxito.

## <a name="rename"></a><a name="rename"></a>nome

```cpp
void rename(const path& from, const path& to);
void rename(const path& from, const path& to, error_code& ec) noexcept;
```

As funções são renomeadas *de* *para.* Um symlink é renomeado, não o arquivo que ele escolhe.

## <a name="resize_file"></a><a name="resize_file"></a>resize_file

```cpp
void resize(const path& pval, uintmax_t size);
void resize(const path& pval, uintmax_t size, error_code& ec) noexcept;
```

As funções alteram o tamanho de um arquivo de modo que`file_size(pval) == size`

## <a name="space"></a><a name="space"></a>disco

```cpp
space_info space(const path& pval);
space_info space(const path& pval, error_code& ec) noexcept;
```

A função retorna informações sobre o volume escolhido por *PVal*, em uma estrutura do tipo `space_info` . A estrutura contém `uintmax_t(-1)` para qualquer valor que não possa ser determinado.

## <a name="status"></a><a name="status"></a>Estado

```cpp
file_status status(const path& pval);
file_status status(const path& pval, error_code& ec) noexcept;
```

As funções retornam o status do nome de caminho, o tipo de arquivo e as permissões, associadas a *PVal*. Um symlink não é testado, mas o arquivo que ele escolhe.

## <a name="status_known"></a><a name="status_known"></a>status_known

```cpp
bool status_known(file_status stat) noexcept;
```

A função retorna`stat.type() != file_type::none`

## <a name="swap"></a><a name="swap"></a>permuta

```cpp
void swap(path& left, path& right) noexcept;
```

A função troca o conteúdo da *esquerda* e da *direita*.

## <a name="symlink_status"></a><a name="symlink_status"></a>symlink_status

```cpp
file_status symlink_status(const path& pval);
file_status symlink_status(const path& pval, error_code& ec) noexcept;
```

As funções retornam o status do nome de caminho symlink, o tipo de arquivo e as permissões, associadas a *PVal*. As funções se comportam da mesma forma `status(pval)` que uma symlink é testada, não o arquivo que ele escolhe.

## <a name="system_complete"></a><a name="system_complete"></a>system_complete

```cpp
path system_complete(const path& pval);
path system_complete(const path& pval, error_code& ec);
```

As funções retornam um nome de caminho absoluto que leva em conta, conforme necessário, o diretório atual associado ao seu nome de raiz. \(Para POSIX, as funções retornam `absolute(pval)` .\)

## <a name="temp_directory_path"></a><a name="temp_directory_path"></a>temp_directory_path

```cpp
path temp_directory_path();
path temp_directory_path(error_code& ec);
```

As funções retornam um nome de caminho para um diretório adequado para armazenar arquivos temporários.

## <a name="u8path"></a><a name="u8path"></a>u8path

```cpp
template <class Source>
path u8path(const Source& source);

template <class InIt>
path u8path(InIt first, InIt last);
```

A primeira função se comporta da mesma forma que `path(source)` e a segunda função se comporta da mesma forma `path(first, last)` que a de, exceto que a origem escolhida em cada caso é executada como uma sequência de elementos Char codificados como UTF-8, qualquer que seja o FileSystem.

## <a name="weakly_canonical"></a><a name="weakly_canonical"></a>weakly_canonical

```cpp
path weakly_canonical(const path& p);
path weakly_canonical(const path& p, error_code& ec);
```
