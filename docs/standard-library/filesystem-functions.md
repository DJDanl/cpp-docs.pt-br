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
ms.openlocfilehash: f1b48ed6f533d4ccb5f9ef5e6dbcbd6e5cc4f7a1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81332045"
---
# <a name="ltfilesystemgt-functions"></a>Funções &lt;filesystem&gt;

Essas funções gratuitas no [ \<sistema de arquivos>](../standard-library/filesystem.md) cabeçalho modificae e consulta as operações em caminhos, arquivos, simelos, diretórios e volumes. Para obter mais informações e exemplos de código, consulte [Navegação do Sistema de Arquivos (C++)](../standard-library/file-system-navigation.md).

## <a name="absolute"></a><a name="absolute"></a>Absoluto

```cpp
path absolute(const path& pval, const path& base = current_path());
```

A função retorna o nome de caminho absoluto `base`correspondente a *pval* em relação ao nome do caminho:

1. Se `pval.has_root_name() && pval.has_root_directory()` a função retornar *pval*.

1. Se `pval.has_root_name() && !pval.has_root_directory()` a `pval.root_name()`  /  `absolute(base).root_directory()`  /  `absolute(base).relative_path()`  /  `pval.relative_path()`função retornar .

1. Se `!pval.has_root_name() && pval.has_root_directory()` a `absolute(base).root_name()`  / função retornar *pval*.

1. Se `!pval.has_root_name() && !pval.has_root_directory()` a `absolute(base)`  / função retornar *pval*.

## <a name="begin"></a><a name="begin"></a>Começar

```cpp
const directory_iterator& begin(const directory_iterator& iter) noexcept;
const recursive_directory_iterator&
    begin(const recursive_directory_iterator& iter) noexcept;
```

Ambas as funções retornam *iter*.

## <a name="canonical"></a><a name="canonical"></a>Canônico

```cpp
path canonical(const path& pval, const path& base = current_path());
path canonical(const path& pval, error_code& ec);
path canonical(const path& pval, const path& base, error_code& ec);
```

Todas as funções formam `pabs = absolute(pval, base)` um `pabs = absolute(pval)` nome de caminho absoluto (ou para a sobrecarga sem parâmetro de base), em seguida, reduza-o a uma forma canônica na seguinte seqüência de passos:

1. Cada componente `X` de `is_symlink(X)` caminho para o `read_symlink(X)`qual é **verdadeiro** é substituído por .

1. Todos os `.` componentes de caminho (o dot é o diretório atual estabelecido pelos componentes de caminho anteriores) são removidos.

1. Todos os componentes `X` / `..` de caminho (dot-dot é o diretório pai estabelecido pelos componentes de caminho anteriores) são removidos.

A função `pabs`então retorna .

## <a name="copy"></a><a name="copy"></a>Cópia

```cpp
void copy(const path& from, const path& to);
void copy(const path& from, const path& to, error_code& ec) noexcept;
void copy(const path& from, const path& to, copy_options opts);
void copy(const path& from, const path& to, copy_options opts, error_code& ec) noexcept;
```

As funções todas possivelmente copiam ou *from* vinculam um ou mais arquivos de `copy_options::none` até *o* controle de *opts*, que é tomado como para as sobrecargas sem parâmetro *opts.* *os opts* devem conter no máximo um dos:

- `skip_existing`, `overwrite_existing` ou `update_existing`

- `copy_symlinks` ou `skip_symlinks`

- `directories_only`, `create_symlinks` ou `create_hard_links`

As funções primeiro determinam `f` os valores file_status para *partir* e `t` *para:*

- se `opts & (copy_options::create_symlinks | copy_options::skip_symlinks)`, chamando`symlink_status`

- caso contrário, chamando`status`

- Caso contrário, geram um erro.

Se, `!exists(f) || equivalent(f, t) || is_other(f) || is_other(t) || is_directory(f)&& is_regular_file(t)`em seguida, eles relatam um erro (e não fazem mais nada).

Caso contrário, `is_symlink(f)` se então:

- Se, `options & copy_options::skip_symlinks`então não fazer nada.

- Caso contrário, `!exists(t)&& options & copy_options::copy_symlinks`se, então. `copy_symlink(from, to, opts)`

- Caso contrário, informe um erro.

Caso contrário, `is_regular_file(f)`se, então:

- Se, `opts & copy_options::directories_only`então não fazer nada.

- Caso contrário, `opts & copy_options::create_symlinks`se, então. `create_symlink(to, from)`

- Caso contrário, `opts & copy_options::create_hard_links`se, então. `create_hard_link(to, from)`

- Caso contrário, `is_directory(f)`se, então. `copy_file(from, to`  /  `from.filename(), opts)`

- Caso contrário, `copy_file(from, to, opts)`.

Caso contrário, `is_directory(f) && (opts & copy_options::recursive || !opts)`se, então:

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

Todas as funções possivelmente copiam o arquivo *de* para *o* controle de *opts*, que é tomado como `copy_options::none` para as sobrecargas sem parâmetro *opts.* *os opts* devem conter `skip_existing` `overwrite_existing`no `update_existing`máximo um dos , ou .

Se `exists(to) && !(opts & (copy_options::skip_existing | copy_options::overwrite_existing | copy_options::update_existing))`, então reportar como um erro que o arquivo já existe.

Caso contrário, `!exists(to) || opts & copy_options::overwrite_existing || opts & copy_options::update_existing&& last_write_time(to) < last_write_time(from) || !(opts & (copy_options::skip_existing | copy_options::overwrite_existing | copy_options:update_existing))`se , em seguida, tentar copiar o conteúdo e atributos do arquivo *de* para o arquivo *para*. Relatar um erro se a tentativa de cópia falhar.

As funções retornam **verdadeiras** se a cópia for tentada e for bem sucedida, caso **contrário, falsa**.

## <a name="copy_symlink"></a><a name="copy_symlink"></a>copy_symlink

```cpp
void copy_symlink(const path& from, const path& to);
void copy_symlink(const path& from, const path& to, error_code& ec) noexcept;
```

Se `is_directory(from)`, a `create_directory_symlink(from, to)`função chama . Caso contrário, `create_symlink(from, to)`ele chama .

## <a name="create_directories"></a><a name="create_directories"></a>create_directories

```cpp
bool create_directories(const path& pval);
bool create_directories(const path& pval, error_code& ec) noexcept;
```

Para um nome de\/\/caminho como um c b,\/a função cria diretórios a e\/\/a b conforme necessário para que ele possa criar o diretório a b c conforme necessário. Ele retorna **verdadeiro** apenas se ele realmente cria o *pval*diretório .

## <a name="create_directory"></a><a name="create_directory"></a>create_directory

```cpp
bool create_directory(const path& pval);

bool create_directory(const path& pval, error_code& ec) noexcept;
bool create_directory(const path& pval, const path& attr);
bool create_directory(const path& pval, const path& attr, error_code& ec) noexcept;
```

A função cria o *pval* do diretório conforme necessário. Ele retorna verdadeiro somente se ele realmente criar o *pval*diretório , nesse caso ele `perms::all` copia permissões do *attr*de arquivo existente , ou usa para as sobrecargas sem parâmetro *attr.*

## <a name="create_directory_symlink"></a><a name="create_directory_symlink"></a>create_directory_symlink

```cpp
void create_directory_symlink(const path& to, const path& link);
void create_directory_symlink(const path& to, const path& link, error_code& ec) noexcept;
```

A função cria link como um symlink para o diretório *para*.

## <a name="create_hard_link"></a><a name="create_hard_link"></a>create_hard_link

```cpp
void create_hard_link(const path& to,  const path& link);
void create_hard_link(const path& to, const path& link, error_code& ec) noexcept;
```

A função cria o link como um link rígido para o diretório ou arquivo *para*.

## <a name="create_symlink"></a><a name="create_symlink"></a>create_symlink

```cpp
void create_symlink(const path& to, const path& link);

void create_symlink(const path& to, const path& link, error_code& ec) noexcept;
```

A função cria *o link* como um symlink para o arquivo *para*.

## <a name="current_path"></a><a name="current_path"></a>current_path

```cpp
path current_path();
path current_path(error_code& ec);
void current_path(const path& pval);
void current_path(const path& pval, error_code& ec) noexcept;
```

As funções sem parâmetro *pval* retornam o nome do caminho para o diretório atual. As demais funções definem o diretório atual como *pval*.

## <a name="end"></a><a name="end"></a>Final

```cpp
directory_iterator& end(const directory_iterator& iter) noexcept;
recursive_directory_iterator& end(const recursive_directory_iterator& iter) noexcept;
```

A primeira `directory_iterator()` função retorna e a segunda função retorna`recursive_directory_iterator()`

## <a name="equivalent"></a><a name="equivalent"></a>Equivalente

```cpp
bool equivalent(const path& left, const path& right);
bool equivalent(const path& left, const path& right, error_code& ec) noexcept;
```

As funções retornam **verdadeiras** somente se *esquerda* e *direita* escolherem a mesma entidade do sistema de arquivos.

## <a name="exists"></a><a name="exists"></a>Existe

```cpp
bool exists(file_status stat) noexcept;
bool exists(const path& pval);
bool exists(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `status_known && stat.type() != file_not_found`. A segunda e terceira `exists(status(pval))`funções retornam .

## <a name="file_size"></a><a name="file_size"></a>file_size

```cpp
uintmax_t file_size(const path& pval);
uintmax_t file_size(const path& pval, error_code& ec) noexcept;
```

As funções retornam o tamanho em bytes do `exists(pval) && is_regular_file(pval)` arquivo escolhido pelo *pval,* se e o tamanho do arquivo pode ser determinado. Caso contrário, eles relatam `uintmax_t(-1)`um erro e retornam .

## <a name="hard_link_count"></a><a name="hard_link_count"></a>hard_link_count

```cpp
uintmax_t hard_link_count(const path& pval);
uintmax_t hard_link_count(const path& pval, error_code& ec) noexcept;
```

A função retorna o número de links \-rígidos para *pval*ou 1 se ocorrer um erro.

## <a name="hash_value"></a><a name="hash_value"></a>hash_value

```cpp
size_t hash_value(const path& pval) noexcept;
```

A função retorna um `pval.native()`valor de hash para .

## <a name="is_block_file"></a><a name="is_block_file"></a>is_block_file

```cpp
bool is_block_file(file_status stat) noexcept;
bool is_block_file(const path& pval);
bool is_block_file(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::block`. As demais `is_block_file(status(pval))`funções retornam .

## <a name="is_character_file"></a><a name="is_character_file"></a>is_character_file

```cpp
bool is_character_file(file_status stat) noexcept;
bool is_character_file(const path& pval);
bool is_character_file(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::character`. As demais `is_character_file(status(pval))`funções retornam .

## <a name="is_directory"></a><a name="is_directory"></a>is_directory

```cpp
bool is_directory(file_status stat) noexcept;
bool is_directory(const path& pval);
bool is_directory(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::directory`. As demais `is_directory_file(status(pval))`funções retornam .

## <a name="is_empty"></a><a name="is_empty"></a>is_empty

```cpp
bool is_empty(file_status stat) noexcept;
bool is_empty(const path& pval);
bool is_empty(const path& pval, error_code& ec) noexcept;
```

Se `is_directory(pval)`, então `directory_iterator(pval) == directory_iterator()`a função retorna; caso contrário, `file_size(pval) == 0`ele retorna .

## <a name="is_fifo"></a><a name="is_fifo"></a>is_fifo

```cpp
bool is_fifo(file_status stat) noexcept;
bool is_fifo(const path& pval);
bool is_fifo(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::fifo`. As demais `is_fifo(status(pval))`funções retornam .

## <a name="is_other"></a><a name="is_other"></a>is_other

```cpp
bool is_other(file_status stat) noexcept;
bool is_other(const path& pval);
bool is_other(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::other`. As demais `is_other(status(pval))`funções retornam .

## <a name="is_regular_file"></a><a name="is_regular_file"></a>is_regular_file

```cpp
bool is_regular_file(file_status stat) noexcept;
bool is_regular_file(const path& pval);
bool is_regular_file(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::regular`. As demais `is_regular_file(status(pval))`funções retornam .

## <a name="is_socket"></a><a name="is_socket"></a>is_socket

```cpp
bool is_socket(file_status stat) noexcept;
bool is_socket(const path& pval);
bool is_socket(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::socket`. As demais `is_socket(status(pval))`funções retornam .

## <a name="is_symlink"></a><a name="is_symlink"></a>is_symlink

```cpp
bool is_symlink(file_status stat) noexcept;
bool is_symlink(const path& pval);
bool is_symlink(const path& pval, error_code& ec) noexcept;
```

A primeira função retorna `stat.type() == file_type::symlink`. As demais `is_symlink(status(pval))`funções retornam .

## <a name="last_write_time"></a><a name="last_write_time"></a>last_write_time

```cpp
file_time_type last_write_time(const path& pval);
file_time_type last_write_time(const path& pval, error_code& ec) noexcept;
void last_write_time(const path& pval, file_time_type new_time);
void last_write_time(const path& pval, file_time_type new_time, error_code& ec) noexcept;
```

As duas primeiras funções retornam o tempo da `file_time_type(-1)` última modificação de dados para *pval*, ou se ocorrer um erro. As duas últimas funções definem o tempo da última modificação de dados para *pval* para *new_time*.

## <a name="permissions"></a><a name="permissions"></a>Permissões

```cpp
void permissions(const path& pval, perms mask);
void permissions(const path& pval, perms mask, error_code& ec) noexcept;
```

As funções definem as permissões para o `mask & perms::mask` nome `perms & (perms::add_perms | perms::remove_perms)`de caminho escolhido pelo *pval* para controlar . *máscara* deve conter no `perms::add_perms` `perms::remove_perms`máximo um dos e .

Se `mask & perms::add_perms`, as funções definirem as permissões para `status(pval).permissions() | mask & perms::mask`. Caso contrário, `mask & perms::remove_perms`se , as funções `status(pval).permissions() & ~(mask & perms::mask)`definir as permissões para . Caso contrário, as funções definem as permissões para `mask & perms::mask`.

## <a name="proximate"></a><a name="proximate"></a>Próxima

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

As funções relatam um `path()` `!is_symlink(pval)`erro e retornam se . Caso contrário, as funções retornam um objeto do tipo `path` contendo o link simbólico.

## <a name="relative"></a><a name="relative"></a>Relativo

```cpp
path relative(const path& p, error_code& ec);
path relative(const path& p, const path& base = current_path());
path relative(const path& p, const path& base, error_code& ec);
```

## <a name="remove"></a><a name="remove"></a>Remover

```cpp
bool remove(const path& pval);
bool remove(const path& pval, error_code& ec) noexcept;
```

As funções retornam `exists(symlink_status(pval))` **verdadeiras** somente se e o arquivo for removido com sucesso. Um symlink é removido, não o arquivo que ele escolhe.

## <a name="remove_all"></a><a name="remove_all"></a>remove_all

```cpp
uintmax_t remove_all(const path& pval);
uintmax_t remove_all(const path& pval, error_code& ec) noexcept;
```

Se *pval* é um diretório, as funções removem recursivamente todas as entradas do diretório, em seguida, a entrada em si. Caso contrário, as `remove`funções chamam . Elas retornam uma contagem de todos os elementos removidos com êxito.

## <a name="rename"></a><a name="rename"></a>Renomear

```cpp
void rename(const path& from, const path& to);
void rename(const path& from, const path& to, error_code& ec) noexcept;
```

As funções renomeiam *de* *para .* Um symlink é renomeado, não o arquivo que ele escolhe.

## <a name="resize_file"></a><a name="resize_file"></a>resize_file

```cpp
void resize(const path& pval, uintmax_t size);
void resize(const path& pval, uintmax_t size, error_code& ec) noexcept;
```

As funções alteram o tamanho de um arquivo de tal forma que`file_size(pval) == size`

## <a name="space"></a><a name="space"></a>Espaço

```cpp
space_info space(const path& pval);
space_info space(const path& pval, error_code& ec) noexcept;
```

A função retorna informações sobre o volume escolhido por `space_info` *pval,* em uma estrutura do tipo . A estrutura `uintmax_t(-1)` contém qualquer valor que não possa ser determinado.

## <a name="status"></a><a name="status"></a>Status

```cpp
file_status status(const path& pval);
file_status status(const path& pval, error_code& ec) noexcept;
```

As funções retornam o status do nome do caminho, o tipo de arquivo e as permissões, associadas ao *pval*. Um symlink em si não é testado, mas o arquivo que ele escolhe.

## <a name="status_known"></a><a name="status_known"></a>status_known

```cpp
bool status_known(file_status stat) noexcept;
```

A função retorna`stat.type() != file_type::none`

## <a name="swap"></a><a name="swap"></a>Trocar

```cpp
void swap(path& left, path& right) noexcept;
```

A função troca o conteúdo da *esquerda* e da *direita.*

## <a name="symlink_status"></a><a name="symlink_status"></a>symlink_status

```cpp
file_status symlink_status(const path& pval);
file_status symlink_status(const path& pval, erroxr_code& ec) noexcept;
```

As funções retornam o status de symlink de nome de caminho, o tipo de arquivo e as permissões, associadas ao *pval*. As funções se comportam da mesma `status(pval)` forma que exceto que um simelo é testado, não o arquivo que ele escolhe.

## <a name="system_complete"></a><a name="system_complete"></a>system_complete

```cpp
path system_complete(const path& pval);
path system_complete(const path& pval, error_code& ec);
```

As funções retornam um nome de caminho absoluto que leva em conta, conforme necessário, o diretório atual associado ao seu nome de raiz. \(Para POSIX, as `absolute(pval)`funções retornam .\)

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

A primeira função se comporta `path(source)` da mesma forma e a `path(first, last)` segunda função se comporta da mesma forma que exceto que a fonte escolhida em cada caso é tomada como uma seqüência de elementos de char codificados como UTF-8, qualquer que seja o sistema de arquivos.

## <a name="weakly_canonical"></a><a name="weakly_canonical"></a>weakly_canonical

```cpp
path weakly_canonical(const path& p);
path weakly_canonical(const path& p, error_code& ec);
```
