---
title: Classe path
ms.date: 09/27/2018
f1_keywords:
- filesystem/std::experimental::filesystem::path
ms.assetid: 8a1227ca-aeb2-4e0e-84aa-86e34e4f4fe8
ms.openlocfilehash: d7c8c739c3d235383ede0509cfa87b41200efeca
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87232996"
---
# <a name="path-class"></a>Classe path

A classe **path** armazena um objeto do tipo `string_type` , chamado `myname` aqui para fins de exposição, adequado para uso como um nome de caminho. `string_type`é um sinônimo para `basic_string<value_type>` , onde `value_type` é um sinônimo para **`wchar_t`** no Windows ou **`char`** em POSIX.

Para obter mais informações e exemplos de código, consulte [navegação do sistema de arquivos (C++)](../standard-library/file-system-navigation.md).

## <a name="syntax"></a>Sintaxe

```cpp
class path;
```

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[path](#path)|Constrói um `path`.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[const_iterator](#const_iterator)|Um sinônimo de `iterator`.|
|[repeti](#iterator)|Um iterador constante bidirecional que designa os `path` componentes do `myname` .|
|[string_type](#string_type)|O tipo é um sinônimo de `basic_string<value_type>`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[append](#append)|Acrescenta a sequência especificada a `mypath` , convertido e inserindo um preferred_separator conforme necessário.|
|[assign](#assign)|Substitui `mypath` pela sequência especificada, convertida conforme necessário.|
|[Comece](#begin)|Retorna um `path::iterator` design do primeiro elemento Path no PathName, se presente.|
|[c_str](#c_str)|Retorna um ponteiro para o primeiro caractere em `mypath` .|
|[formatação](#clear)|É executado `mypath.clear()` .|
|[comparar](#compare)|Retorna valores de comparação.|
|[concat](#compare)|Acrescenta a sequência especificada a `mypath` , convertido (mas não a inserção de um separador), conforme necessário.|
|[empty](#empty)|Retorna `mypath.empty()`.|
|[completo](#end)|Retorna um iterador de fim de sequência do tipo `iterator` .|
|[extensão](#extension)|Retorna o sufixo de `filename()` .|
|[nome do arquivo](#filename)|Retorna o componente do diretório raiz do myname, especificamente `empty() path() : *--end()`. O componente pode estar vazio.|
|[generic_string](#generic_string)|Retorna `this->string<Elem, Traits, Alloc>(al)` com (em Windows) qualquer barra invertida convertida em barra "/".|
|[generic_u16string](#generic_u16string)|Retorna `u16string()` com (em Windows) qualquer barra invertida convertida em barra "/".|
|[generic_u32string](#generic_u32string)|Retorna `u32string()` com (em Windows) qualquer barra invertida convertida em barra "/".|
|[generic_u8string](#generic_u8string)|Retorna `u8string()` com (em Windows) qualquer barra invertida convertida em barra "/".|
|[generic_wstring](#generic_wstring)|Retorna `wstring()` com (em Windows) qualquer barra invertida convertida em barra "/".|
|[has_extension](#has_extension)|Retorna `!extension().empty()`.|
|[has_filename](#has_filename)|Retorna `!filename().empty()`.|
|[has_parent_path](#has_parent_path)|Retorna `!parent_path().empty()`.|
|[has_relative_path](#has_relative_path)|Retorna `!relative_path().empty()`.|
|[has_root_directory](#has_root_directory)|Retorna `!root_directory().empty()`.|
|[has_root_name](#has_root_name)|Retorna `!root_name().empty()`.|
|[has_root_path](#has_root_path)|Retorna `!root_path().empty()`.|
|[has_stem](#has_stem)|Retorna `!stem().empty()`.|
|[is_absolute](#is_absolute)|Para o Windows, a função retorna `has_root_name() && has_root_directory()` . Para POSIX, a função retorna `has_root_directory()` .|
|[is_relative](#is_relative)|Retorna `!is_absolute()`.|
|[make_preferred](#make_preferred)|Converte cada separador em um preferred_separator conforme necessário.|
|[native](#native)|Retorna `myname`.|
|[parent_path](#parent_path)|Retorna o componente de caminho pai de `myname` .|
|[preferred_separator](#preferred_separator)|O objeto constante fornece o caractere preferencial para separar os componentes do caminho, dependendo do sistema operacional do host. |
|[relative_path](#relative_path)|Retorna o componente de caminho relativo de `myname` . |
|[remove_filename](#remove_filename)|Remove o nome do arquivo.|
|[replace_extension](#replace_extension)|Substitui a extensão de `myname` . |
|[replace_filename](#replace_filename)|RReplaces o nome do arquivo.|
|[root_directory](#root_directory)|Retorna o componente de diretório raiz de `myname` . |
|[root_name](#root_name)|Retorna o componente de nome raiz do `myname` . |
|[root_path](#root_path)|Retorna o componente de caminho raiz de `myname` .|
|[stem](#stem)|Retorna o `stem` componente do `myname` .|
|[cadeia de caracteres](#string)|Converte a sequência armazenada em `mypath` .|
|[permuta](#swap)|É executado `swap(mypath, right.mypath)` .|
|[u16string](#u16string)|Converte a sequência armazenada em `mypath` UTF-16 e a retorna armazenada em um objeto do tipo `u16string` .|
|[u32string](#u32string)|Converte a sequência armazenada em `mypath` UTF-32 e a retorna armazenada em um objeto do tipo `u32string` .|
|[u8string](#u8string)|Converte a sequência armazenada em `mypath` UTF-8 e a retorna armazenada em um objeto do tipo `u8string` .|
|[value_type](#value_type)|O tipo descreve os elementos de caminho preferidos pelo sistema operacional do host.|
|[wstring](#wstring)|Converte a sequência armazenada em na `mypath` codificação preferida pelo sistema host para uma **`wchar_t`** sequência e a retorna armazenada em um objeto do tipo `wstring` .|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador =](#op_as)|Substitui os elementos do caminho por uma cópia de outro caminho.|
|[operador + =](#op_add)|Várias `concat` expressões.|
|[operador/=](#op_divide)|Várias `append` expressões.|
|[string_type do operador](#op_string)|Retorna `myname`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<filesystem>

**Namespace:** std::experimental::filesystem

## <a name="pathappend"></a><a name="append"></a>caminho:: acrescentar

Acrescenta a sequência especificada a `mypath` , convertida e inserida `preferred_separator` como necessário.

```cpp
template <class Source>
path& append(const Source& source);

template <class InIt>
path& append(InIt first, InIt last);
```

### <a name="parameters"></a>parâmetros

*original*\
Sequência especificada.

*primeiro*\
Início da sequência especificada.

*última*\
Fim da sequência especificada.

## <a name="pathassign"></a><a name="assign"></a>caminho:: atribuir

Substitui `mypath` pela sequência especificada, convertida conforme necessário.

```cpp
template <class Source>
path& assign(const Source& source);

template <class InIt>
path& assign(InIt first, InIt last);
```

### <a name="parameters"></a>parâmetros

*original*\
Sequência especificada.

*primeiro*\
Início da sequência especificada.

*última*\
Fim da sequência especificada.

## <a name="pathbegin"></a><a name="begin"></a>caminho:: início

Retorna um `path::iterator` design do primeiro elemento Path no PathName, se presente.

```cpp
iterator begin() const;
```

## <a name="pathc_str"></a><a name="c_str"></a>caminho:: c_str

Retorna um ponteiro para o primeiro caractere em `mypath` .

```cpp
const value_type& *c_str() const noexcept;
```

## <a name="pathclear"></a><a name="clear"></a>caminho:: limpar

É executado `mypath.clear()` .

```cpp
void clear() noexcept;
```

## <a name="pathcompare"></a><a name="compare"></a>caminho:: comparar

A primeira função retorna `mypath.compare(pval.native())`. A segunda função retorna `mypath.compare(str)`. A terceira função retorna `mypath.compare(ptr)` .

```cpp
int compare(const path& pval) const noexcept;
int compare(const string_type& str) const;
int compare(const value_type *ptr) const;
```

### <a name="parameters"></a>parâmetros

*pval*\
Caminho para comparar.

*Str*\
Cadeia de caracteres para comparar.

*PTR*\
Ponteiro para comparação.

## <a name="pathconcat"></a><a name="concat"></a>caminho:: Concat

Acrescenta a sequência especificada a `mypath` , convertido (mas não a inserção de um separador), conforme necessário.

```cpp
template <class Source>
path& concat(const Source& source);

template <class InIt>
path& concat(InIt first, InIt last);
```

### <a name="parameters"></a>parâmetros

*original*\
Sequência especificada.

*primeiro*\
Início da sequência especificada.

*última*\
Fim da sequência especificada.

## <a name="pathconst_iterator"></a><a name="const_iterator"></a>caminho:: const_iterator

Um sinônimo de `iterator`.

```cpp
typedef iterator const_iterator;
```

## <a name="pathempty"></a><a name="empty"></a>caminho:: vazio

Retorna `mypath.empty()`.

```cpp
bool empty() const noexcept;
```

## <a name="pathend"></a><a name="end"></a>caminho:: fim

Retorna um iterador de fim de sequência do tipo `iterator` .

```cpp
iterator end() const;
```

## <a name="pathextension"></a><a name="extension"></a>caminho:: extensão

Retorna o sufixo de `filename()` .

```cpp
path extension() const;
```

### <a name="remarks"></a>Comentários

Retorna o sufixo de `filename() X` tal forma:

Se `X == path(".") || X == path("..")` ou se `X` não contiver nenhum ponto, o sufixo estará vazio.

Caso contrário, o sufixo começa com (e inclui) o ponto mais à direita.

## <a name="pathfilename"></a><a name="filename"></a>caminho:: nome de arquivo

Retorna o componente do diretório raiz do myname, especificamente `empty() path() : *--end()`. O componente pode estar vazio.

```cpp
path filename() const;
```

## <a name="pathgeneric_string"></a><a name="generic_string"></a>caminho:: generic_string

Retorna `this->string<Elem, Traits, Alloc>(al)` com (em Windows) qualquer barra invertida convertida em barra "/".

```cpp
template <class Elem,
    class Traits = char_traits<Elem>,
    class Alloc = allocator<Elem>>
  basic_string<Elem, Traits, Alloc>
    generic_string(const Alloc& al = Alloc()) const;

string generic_string() const;
```

## <a name="pathgeneric_u16string"></a><a name="generic_u16string"></a>caminho:: generic_u16string

Retorna `u16string()` com (em Windows) qualquer barra invertida convertida em barra "/".

```cpp
u16string generic_u16string() const;
```

## <a name="pathgeneric_u32string"></a><a name="generic_u32string"></a>caminho:: generic_u32string

Retorna `u32string()` com (em Windows) qualquer barra invertida convertida em barra "/".

```cpp
u32string generic_u32string() const;
```

## <a name="pathgeneric_u8string"></a><a name="generic_u8string"></a>caminho:: generic_u8string

Retorna `u8string()` com (em Windows) qualquer barra invertida convertida em barra "/".

```cpp
string generic_u8string() const;
```

## <a name="pathgeneric_wstring"></a><a name="generic_wstring"></a>caminho:: generic_wstring

Retorna `wstring()` com (em Windows) qualquer barra invertida convertida em barra "/".

```cpp
wstring generic_wstring() const;
```

## <a name="pathhas_extension"></a><a name="has_extension"></a>caminho:: has_extension

Retorna `!extension().empty()`.

```cpp
bool has_extension() const;
```

## <a name="pathhas_filename"></a><a name="has_filename"></a>caminho:: has_filename

Retorna `!filename().empty()`.

```cpp
bool has_filename() const;
```

## <a name="pathhas_parent_path"></a><a name="has_parent_path"></a>caminho:: has_parent_path

Retorna `!parent_path().empty()`.

```cpp
bool has_parent_path() const;
```

## <a name="pathhas_relative_path"></a><a name="has_relative_path"></a>caminho:: has_relative_path

Retorna `!relative_path().empty()`.

```cpp
bool has_relative_path() const;
```

## <a name="pathhas_root_directory"></a><a name="has_root_directory"></a>caminho:: has_root_directory

Retorna `!root_directory().empty()`.

```cpp
bool has_root_directory() const;
```

## <a name="pathhas_root_name"></a><a name="has_root_name"></a>caminho:: has_root_name

Retorna `!root_name().empty()`.

```cpp
bool has_root_name() const;
```

## <a name="pathhas_root_path"></a><a name="has_root_path"></a>caminho:: has_root_path

Retorna `!root_path().empty()`.

```cpp
bool has_root_path() const;
```

## <a name="pathhas_stem"></a><a name="has_stem"></a>caminho:: has_stem

Retorna `!stem().empty()`.

```cpp
bool has_stem() const;
```

## <a name="pathis_absolute"></a><a name="is_absolute"></a>caminho:: is_absolute

Para o Windows, a função retorna `has_root_name() && has_root_directory()` . Para POSIX, a função retorna `has_root_directory()` .

```cpp
bool is_absolute() const;
```

## <a name="pathis_relative"></a><a name="is_relative"></a>caminho:: is_relative

Retorna `!is_absolute()`.

```cpp
bool is_relative() const;
```

## <a name="pathiterator"></a><a name="iterator"></a>caminho:: iterador

Um iterador constante bidirecional que designa os componentes de caminho do `myname` .

```cpp
class iterator
   {
   // bidirectional iterator for path
   typedef bidirectional_iterator_tag iterator_category;
   typedef path_type value_type;
   typedef ptrdiff_t difference_type;
   typedef const value_type *pointer;
   typedef const value_type& reference;
   // ...
   };
```

### <a name="remarks"></a>Comentários

A classe descreve um iterador de constante bidirecional que designa os `path` componentes do `myname` na sequência:

1. o nome raiz, se existir

1. o diretório raiz, se existir

1. os elementos de diretório restantes do pai `path` , se estiverem presentes, terminando com o nome de arquivo, se presente

Para `pval` um objeto do tipo `path` :

1. `path::iterator X = pval.begin()`designa o primeiro `path` elemento no nome do caminho, se presente.

1. `X == pval.end()`é verdadeiro quando `X` os pontos ultrapassam o final da sequência de componentes.

1. `*X`Retorna uma cadeia de caracteres que corresponde ao componente atual

1. `++X`designa o próximo componente na sequência, se presente.

1. `--X`designa o componente anterior na sequência, se presente.

1. A alteração `myname` invalida todos os iteradores que definem elementos no `myname` .

## <a name="pathmake_preferred"></a><a name="make_preferred"></a>caminho:: make_preferred

Converte cada separador em um `preferred_separator` conforme necessário.

```cpp
path& make_preferred();
```

## <a name="pathnative"></a><a name="native"></a>caminho:: nativo

Retorna `myname`.

```cpp
const string_type& native() const noexcept;
```

## <a name="pathoperator"></a><a name="op_as"></a>caminho:: operador =

Substitui os elementos do caminho por uma cópia de outro caminho.

```cpp
path& operator=(const path& right);
path& operator=(path&& right) noexcept;

template <class Source>
path& operator=(const Source& source);
```

### <a name="parameters"></a>parâmetros

*Certo*\
O [caminho](../standard-library/path-class.md) que está sendo copiado para o `path` .

*original*\
O caminho de origem.

### <a name="remarks"></a>Comentários

O primeiro operador de membro copia `right.myname` para `myname` . O segundo operador de membro é movido `right.myname` para `myname` . O terceiro operador de membro se comporta da mesma forma que `*this = path(source)` .

## <a name="pathoperator"></a><a name="op_add"></a>caminho:: operador + =

Várias `concat` expressões.

```cpp
path& operator+=(const path& right);
path& operator+=(const string_type& str);
path& operator+=(const value_type *ptr);
path& operator+=(value_type elem);

template <class Source>
path& operator+=(const Source& source);

template <class Elem>
path& operator+=(Elem elem);
```

### <a name="parameters"></a>parâmetros

*Certo*\
O caminho adicionado.

*Str*\
A cadeia de caracteres adicionada.

*PTR*\
O ponteiro adicionado.

*elem*\
O `value_type` ou o `Elem` .

*original*\
A fonte adicionada.

### <a name="remarks"></a>Comentários

As funções de membro se comportam da mesma maneira que as seguintes expressões correspondentes:

1. `concat(right);`

1. `concat(path(str));`

1. `concat(ptr);`

1. `concat(string_type(1, elem));`

1. `concat(source);`

1. `concat(path(basic_string<Elem>(1, elem)));`

## <a name="pathoperator"></a><a name="op_divide"></a>caminho:: operador/=

Várias `append` expressões.

```cpp
path& operator/=(const path& right);

template <class Source>
path& operator/=(const Source& source);
```

### <a name="parameters"></a>parâmetros

*Certo*\
O caminho adicionado.

*original*\
A fonte adicionada.

### <a name="remarks"></a>Comentários

As funções de membro se comportam da mesma maneira que as seguintes expressões correspondentes:

1. `append(right);`

1. `append(source);`

## <a name="pathoperator-string_type"></a><a name="op_string"></a>operador caminho:: string_type

Retorna `myname`.

```cpp
operator string_type() const;
```

## <a name="pathparent_path"></a><a name="parent_path"></a>caminho::p arent_path

Retorna o componente de caminho pai de `myname` .

```cpp
path parent_path() const;
```

### <a name="remarks"></a>Comentários

Retorna o componente de caminho pai de `myname` , especificamente o prefixo de `myname` após a remoção `filename().native()` e quaisquer separadores de diretório imediatamente precedentes. (Igualmente, se `begin() != end()` for, a combinação de todos os elementos no intervalo é `[begin(), --end())` aplicada sucessivamente `operator/=` .) O componente pode estar vazio.

## <a name="pathpath"></a><a name="path"></a>caminho::p Ho

Constrói um `path` de várias maneiras.

```cpp
path();

path(const path& right);
path(path&& right) noexcept;

template <class Source>
path(const Source& source);

template <class Source>
path(const Source& source, const locale& loc);

template <class InIt>
path(InIt first, InIt last);

template <class InIt>
path(InIt first, InIt last, const locale& loc);
```

### <a name="parameters"></a>parâmetros

*Certo*\
O caminho do qual o caminho construído deve ser uma cópia.

*original*\
A origem da qual o caminho construído é uma cópia.

*localização*\
A localidade especificada.

*primeiro*\
A posição do primeiro elemento a ser copiado.

*última*\
A posição do último elemento a ser copiado.

### <a name="remarks"></a>Comentários

Todos os construtores são constructos `myname` de várias maneiras:

Para `path()` ele é `myname()` .

Para o `path(const path& right` ) é `myname(right.myname)` .

Para `path(path&& right)` ele é `myname(right.myname)` .

Para `template<class Source> path(const Source& source)` ele é `myname(source)` .

Para `template<class Source> path(const Source& source, const locale& loc)` isso `myname(source)` , obter todas as facetas codecvt necessárias do `loc` .

Para `template<class InIt> path(InIt first, InIt last)` ele é `myname(first, last)` .

Para `template<class InIt> path(InIt first, InIt last, const locale& loc)` isso `myname(first, last)` , obter todas as facetas codecvt necessárias do `loc` .

## <a name="pathpreferred_separator"></a><a name="preferred_separator"></a>caminho::p referred_separator

O objeto constante fornece o caractere preferencial para separar os componentes do caminho, dependendo do sistema operacional do host.

```cpp
#if _WIN32_C_LIB
static constexpr value_type preferred_separator == L'\\';
#else // assume POSIX
static constexpr value_type preferred_separator == '/';
#endif // filesystem model now defined
```

### <a name="remarks"></a>Comentários

Observe que é igualmente permitido na maioria dos contextos no Windows usar L'/' em seu lugar.

## <a name="pathrelative_path"></a><a name="relative_path"></a>caminho:: relative_path

Retorna o componente de caminho relativo de `myname` .

```cpp
path relative_path() const;
```

### <a name="remarks"></a>Comentários

Retorna o componente de caminho relativo de `myname` , especificamente o sufixo de `myname` após a remoção `root_path().native()` e quaisquer separadores de diretórios redundantes subsequentes imediatamente. O componente pode estar vazio.

## <a name="pathremove_filename"></a><a name="remove_filename"></a>caminho:: remove_filename

Remove o nome do arquivo.

```cpp
path& remove_filename();
```

## <a name="pathreplace_extension"></a><a name="replace_extension"></a>caminho:: replace_extension

Substitui a extensão de `myname` .

```cpp
path& replace_extension(const path& newext = path());
```

### <a name="parameters"></a>parâmetros

*newext*\
A nova extensão.

### <a name="remarks"></a>Comentários

Primeiro, remove o sufixo `extension().native()` de `myname` . Em seguida `!newext.empty() && newext[0] != dot` , se (Where `dot` é `*path(".").c_str()` ), `dot` será anexado a `myname` . Em seguida, *newext* é acrescentado a `myname` .

## <a name="pathreplace_filename"></a><a name="replace_filename"></a>caminho:: replace_filename

Substitui o nome do arquivo.

```cpp
path& replace_filename(const path& pval);
```

### <a name="parameters"></a>parâmetros

*pval*\
O caminho do nome de arquivo.

### <a name="remarks"></a>Comentários

A função membro executa:

```cpp
remove_filename();

*this /= pval;
return (*this);
```

## <a name="pathroot_directory"></a><a name="root_directory"></a>caminho:: root_directory

Retorna o componente de diretório raiz de `myname` .

```cpp
path root_directory() const;
```

### <a name="remarks"></a>Comentários

O componente pode estar vazio.

## <a name="pathroot_name"></a><a name="root_name"></a>caminho:: root_name

Retorna o componente de nome raiz do `myname` .

```cpp
path root_name() const;
```

### <a name="remarks"></a>Comentários

O componente pode estar vazio.

## <a name="pathroot_path"></a><a name="root_path"></a>caminho:: root_path

Retorna o componente de caminho raiz de `myname` .

```cpp
path root_path() const;
```

### <a name="remarks"></a>Comentários

Retorna o componente de caminho raiz de `myname` , especificamente `root_name()`  /  `root_directory` . O componente pode estar vazio.

## <a name="pathstem"></a><a name="stem"></a>caminho:: tronco

Retorna o `stem` componente do `myname` .

```cpp
path stem() const;
```

### <a name="remarks"></a>Comentários

Retorna o `stem` componente do `myname` , especificamente `filename().native()` com qualquer `extension().native()` removida à direita. O componente pode estar vazio.

## <a name="pathstring"></a><a name="string"></a>caminho:: cadeia de caracteres

Converte a sequência armazenada em `mypath` .

```cpp
template \<class Elem, class Traits = char_traits\<Elem>, class Alloc = allocator\<Elem>>
basic_string\<Elem, Traits, Alloc> string(const Alloc& al = Alloc()) const;
string string() const;
```

### <a name="remarks"></a>Comentários

A primeira função de membro (modelo) converte a sequência armazenada da `mypath` mesma maneira que:

1. `string()` para `string<char, Traits, Alloc>()`

1. `wstring()` para `string<wchar_t, Traits, Alloc>()`

1. `u16string()` para `string<char16_t, Traits, Alloc>()`

1. `u32string()` para `string<char32_t, Traits, Alloc>()`

A segunda função de membro converte a sequência armazenada em na `mypath` codificação preferida pelo sistema host para uma **`char`** sequência e a retorna armazenada em um objeto do tipo `string` .

## <a name="pathstring_type"></a><a name="string_type"></a>caminho:: string_type

O tipo é um sinônimo de `basic_string<value_type>`.

```cpp
typedef basic_string<value_type> string_type;
```

## <a name="pathswap"></a><a name="swap"></a>caminho:: permuta

É executado `swap(mypath, right.mypath)` .

```cpp
void swap(path& right) noexcept;
```

## <a name="pathu16string"></a><a name="u16string"></a>caminho:: u16string

Converte a sequência armazenada em `mypath` UTF-16 e a retorna armazenada em um objeto do tipo `u16string` .

```cpp
u16string u16string() const;
```

## <a name="pathu32string"></a><a name="u32string"></a>caminho:: u32string

Converte a sequência armazenada em `mypath` UTF-32 e a retorna armazenada em um objeto do tipo `u32string` .

```cpp
u32string u32string() const;
```

## <a name="pathu8string"></a><a name="u8string"></a>caminho:: u8string

Converte a sequência armazenada em `mypath` UTF-8 e a retorna armazenada em um objeto do tipo `u8string` .

```cpp
string u8string() const;
```

## <a name="pathvalue_type"></a><a name="value_type"></a>caminho:: value_type

O tipo descreve os `path` elementos favorecedos pelo sistema operacional do host.

```cpp
#if _WIN32_C_LIB
typedef wchar_t value_type;
#else // assume POSIX
typedef char value_type;
#endif // filesystem model now defined
```

## <a name="pathwstring"></a><a name="wstring"></a>caminho:: wstring

Converte a sequência armazenada em na `mypath` codificação preferida pelo sistema host para uma **`wchar_t`** sequência e a retorna armazenada em um objeto do tipo `wstring` .

```cpp
wstring wstring() const;
```

## <a name="see-also"></a>Confira também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
