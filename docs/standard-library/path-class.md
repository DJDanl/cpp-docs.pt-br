---
title: Classe path
ms.date: 09/27/2018
f1_keywords:
- filesystem/std::experimental::filesystem::path
ms.assetid: 8a1227ca-aeb2-4e0e-84aa-86e34e4f4fe8
ms.openlocfilehash: 10c865aa2bc2431850c69e9dfedbef37414b2cb9
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68455093"
---
# <a name="path-class"></a>Classe path

A classe **path** armazena um objeto do tipo `string_type`, chamado `myname` aqui para fins de exposição, adequado para uso como um nome de caminho. `string_type`é um sinônimo de `basic_string<value_type>`, em `value_type` que é um sinônimo para **wchar_t** no Windows ou **Char** em POSIX.

Para obter mais informações e exemplos de código, consulte [Navegação do Sistema de Arquivos (C++)](../standard-library/file-system-navigation.md).

## <a name="syntax"></a>Sintaxe

```cpp
class path;
```

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[path](#path)|Constrói um `path`.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[const_iterator](#const_iterator)|Um sinônimo de `iterator`.|
|[iterator](#iterator)|Um iterador constante bidirecional que designa os `path` componentes do `myname`.|
|[string_type](#string_type)|O tipo é um sinônimo de `basic_string<value_type>`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[append](#append)|Acrescenta a sequência especificada a `mypath`, convertido e inserindo um preferred_separator, conforme necessário.|
|[assign](#assign)|Substitui `mypath` pela sequência especificada, convertida conforme necessário.|
|[begin](#begin)|Retorna um `path::iterator` design do primeiro elemento Path no PathName, se presente.|
|[c_str](#c_str)|Retorna um ponteiro para o primeiro caractere em `mypath`.|
|[clear](#clear)|É executado `mypath.clear()`.|
|[compare](#compare)|Retorna valores de comparação.|
|[concat](#compare)|Acrescenta a sequência especificada a `mypath`, convertido (mas não a inserção de um separador), conforme necessário.|
|[empty](#empty)|Retorna `mypath.empty()`.|
|[end](#end)|Retorna um iterador de fim de sequência do tipo `iterator`.|
|[extension](#extension)|Retorna o sufixo de `filename()`.|
|[filename](#filename)|Retorna o componente do diretório raiz do myname, especificamente `empty() path() : *--end()`. O componente pode estar vazio.|
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
|[is_absolute](#is_absolute)|Para o Windows, a função `has_root_name() && has_root_directory()`retorna. Para POSIX, a função retorna `has_root_directory()`.|
|[is_relative](#is_relative)|Retorna `!is_absolute()`.|
|[make_preferred](#make_preferred)|Converte cada separador em um preferred_separator conforme necessário.|
|[nativo](#native)|Retorna `myname`.|
|[parent_path](#parent_path)|Retorna o componente de caminho pai `myname`de.|
|[preferred_separator](#preferred_separator)|O objeto constante fornece o caractere preferencial para separar os componentes do caminho, dependendo do sistema operacional do host. |
|[relative_path](#relative_path)|Retorna o componente de caminho relativo `myname`de. |
|[remove_filename](#remove_filename)|Remove o nome do arquivo.|
|[replace_extension](#replace_extension)|Substitui a extensão de `myname`. |
|[replace_filename](#replace_filename)|RReplaces o nome do arquivo.|
|[root_directory](#root_directory)|Retorna o componente de diretório raiz `myname`de. |
|[root_name](#root_name)|Retorna o componente de nome raiz `myname`do. |
|[root_path](#root_path)|Retorna o componente de caminho raiz `myname`de.|
|[stem](#stem)|Retorna o `stem` componente do `myname`.|
|[string](#string)|Converte a sequência armazenada `mypath`em.|
|[swap](#swap)|É executado `swap(mypath, right.mypath)`.|
|[u16string](#u16string)|Converte a sequência armazenada `mypath` em UTF-16 e a retorna armazenada em um objeto do `u16string`tipo.|
|[u32string](#u32string)|Converte a sequência armazenada `mypath` em UTF-32 e a retorna armazenada em um objeto do `u32string`tipo.|
|[u8string](#u8string)|Converte a sequência armazenada `mypath` em UTF-8 e a retorna armazenada em um objeto do `u8string`tipo.|
|[value_type](#value_type)|O tipo descreve os elementos de caminho preferidos pelo sistema operacional do host.|
|[wstring](#wstring)|Converte a sequência armazenada `mypath` em na codificação preferida pelo sistema host para uma sequência e `wchar_t` a retorna armazenada em um objeto do tipo `wstring`.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator=](#op_as)|Substitui os elementos do caminho por uma cópia de outro caminho.|
|[operator+=](#op_add)|Várias `concat` expressões.|
|[operator/=](#op_divide)|Várias `append` expressões.|
|[string_type do operador](#op_string)|Retorna `myname`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<> do sistema de arquivos

**Namespace:** std::experimental::filesystem

## <a name="append"></a>caminho:: acrescentar

Acrescenta a sequência especificada a `mypath`, convertida e inserida `preferred_separator` como necessário.

```cpp
template <class Source>
path& append(const Source& source);

template <class InIt>
path& append(InIt first, InIt last);
```

### <a name="parameters"></a>Parâmetros

*original*\
Sequência especificada.

*primeiro*\
Início da sequência especificada.

*última*\
Fim da sequência especificada.

## <a name="assign"></a> path::assign

Substitui `mypath` pela sequência especificada, convertida conforme necessário.

```cpp
template <class Source>
path& assign(const Source& source);

template <class InIt>
path& assign(InIt first, InIt last);
```

### <a name="parameters"></a>Parâmetros

*original*\
Sequência especificada.

*primeiro*\
Início da sequência especificada.

*última*\
Fim da sequência especificada.

## <a name="begin"></a>caminho:: início

Retorna um `path::iterator` design do primeiro elemento Path no PathName, se presente.

```cpp
iterator begin() const;
```

## <a name="c_str"></a> path::c_str

Retorna um ponteiro para o primeiro caractere em `mypath`.

```cpp
const value_type& *c_str() const noexcept;
```

## <a name="clear"></a>caminho:: limpar

É executado `mypath.clear()`.

```cpp
void clear() noexcept;
```

## <a name="compare"></a>caminho:: comparar

A primeira função retorna `mypath.compare(pval.native())`. A segunda função retorna `mypath.compare(str)`. A terceira função retorna `mypath.compare(ptr)`.

```cpp
int compare(const path& pval) const noexcept;
int compare(const string_type& str) const;
int compare(const value_type *ptr) const;
```

### <a name="parameters"></a>Parâmetros

*pval*\
Caminho para comparar.

*Str*\
Cadeia de caracteres para comparar.

*PTR*\
Ponteiro para comparação.

## <a name="concat"></a> path::concat

Acrescenta a sequência especificada a `mypath`, convertido (mas não a inserção de um separador), conforme necessário.

```cpp
template <class Source>
path& concat(const Source& source);

template <class InIt>
path& concat(InIt first, InIt last);
```

### <a name="parameters"></a>Parâmetros

*original*\
Sequência especificada.

*primeiro*\
Início da sequência especificada.

*última*\
Fim da sequência especificada.

## <a name="const_iterator"></a> path::const_iterator

Um sinônimo de `iterator`.

```cpp
typedef iterator const_iterator;
```

## <a name="empty"></a>caminho:: vazio

Retorna `mypath.empty()`.

```cpp
bool empty() const noexcept;
```

## <a name="end"></a>caminho:: fim

Retorna um iterador de fim de sequência do tipo `iterator`.

```cpp
iterator end() const;
```

## <a name="extension"></a>caminho:: extensão

Retorna o sufixo de `filename()`.

```cpp
path extension() const;
```

### <a name="remarks"></a>Comentários

Retorna o sufixo de `filename() X` tal forma:

Se `X == path(".") || X == path("..")` ou se `X` não contiver nenhum ponto, o sufixo estará vazio.

Caso contrário, o sufixo começa com (e inclui) o ponto mais à direita.

## <a name="filename"></a>caminho:: nome de arquivo

Retorna o componente do diretório raiz do myname, especificamente `empty() path() : *--end()`. O componente pode estar vazio.

```cpp
path filename() const;
```

## <a name="generic_string"></a> path::generic_string

Retorna `this->string<Elem, Traits, Alloc>(al)` com (em Windows) qualquer barra invertida convertida em barra "/".

```cpp
template <class Elem,
    class Traits = char_traits<Elem>,
    class Alloc = allocator<Elem>>
  basic_string<Elem, Traits, Alloc>
    generic_string(const Alloc& al = Alloc()) const;

string generic_string() const;
```

## <a name="generic_u16string"></a>caminho:: generic_u16string

Retorna `u16string()` com (em Windows) qualquer barra invertida convertida em barra "/".

```cpp
u16string generic_u16string() const;
```

## <a name="generic_u32string"></a> path::generic_u32string

Retorna `u32string()` com (em Windows) qualquer barra invertida convertida em barra "/".

```cpp
u32string generic_u32string() const;
```

## <a name="generic_u8string"></a> path::generic_u8string

Retorna `u8string()` com (em Windows) qualquer barra invertida convertida em barra "/".

```cpp
string generic_u8string() const;
```

## <a name="generic_wstring"></a> path::generic_wstring

Retorna `wstring()` com (em Windows) qualquer barra invertida convertida em barra "/".

```cpp
wstring generic_wstring() const;
```

## <a name="has_extension"></a> path::has_extension

Retorna `!extension().empty()`.

```cpp
bool has_extension() const;
```

## <a name="has_filename"></a> path::has_filename

Retorna `!filename().empty()`.

```cpp
bool has_filename() const;
```

## <a name="has_parent_path"></a> path::has_parent_path

Retorna `!parent_path().empty()`.

```cpp
bool has_parent_path() const;
```

## <a name="has_relative_path"></a> path::has_relative_path

Retorna `!relative_path().empty()`.

```cpp
bool has_relative_path() const;
```

## <a name="has_root_directory"></a>caminho:: has_root_directory

Retorna `!root_directory().empty()`.

```cpp
bool has_root_directory() const;
```

## <a name="has_root_name"></a>caminho:: has_root_name

Retorna `!root_name().empty()`.

```cpp
bool has_root_name() const;
```

## <a name="has_root_path"></a> path::has_root_path

Retorna `!root_path().empty()`.

```cpp
bool has_root_path() const;
```

## <a name="has_stem"></a> path::has_stem

Retorna `!stem().empty()`.

```cpp
bool has_stem() const;
```

## <a name="is_absolute"></a> path::is_absolute

Para o Windows, a função `has_root_name() && has_root_directory()`retorna. Para POSIX, a função retorna `has_root_directory()`.

```cpp
bool is_absolute() const;
```

## <a name="is_relative"></a> path::is_relative

Retorna `!is_absolute()`.

```cpp
bool is_relative() const;
```

## <a name="iterator"></a>caminho:: iterador

Um iterador constante bidirecional que designa os componentes de caminho `myname`do.

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

A classe descreve um iterador de constante bidirecional que designa `path` os componentes `myname` do na sequência:

1. o nome raiz, se existir

1. o diretório raiz, se existir

1. os elementos de diretório restantes do pai `path`, se estiverem presentes, terminando com o nome de arquivo, se presente

Para `pval` um objeto do tipo `path`:

1. `path::iterator X = pval.begin()`designa o primeiro `path` elemento no nome do caminho, se presente.

1. `X == pval.end()`é verdadeiro quando `X` os pontos ultrapassam o final da sequência de componentes.

3. `*X`Retorna uma cadeia de caracteres que corresponde ao componente atual

1. `++X`designa o próximo componente na sequência, se presente.

1. `--X`designa o componente anterior na sequência, se presente.

1. A alteração invalida todos os iteradores que definem elementos `myname`no. `myname`

## <a name="make_preferred"></a> path::make_preferred

Converte cada separador `preferred_separator` em um conforme necessário.

```cpp
path& make_preferred();
```

## <a name="native"></a>caminho:: nativo

Retorna `myname`.

```cpp
const string_type& native() const noexcept;
```

## <a name="op_as"></a>caminho:: operador =

Substitui os elementos do caminho por uma cópia de outro caminho.

```cpp
path& operator=(const path& right);
path& operator=(path&& right) noexcept;

template <class Source>
path& operator=(const Source& source);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O [caminho](../standard-library/path-class.md) que está sendo copiado para o `path`.

*original*\
O caminho de origem.

### <a name="remarks"></a>Comentários

O primeiro operador de membro `right.myname` copia `myname`para. O segundo operador de membro `right.myname` é `myname`movido para. O terceiro operador de membro se comporta da mesma forma `*this = path(source)`que.

## <a name="op_add"></a>caminho:: operador + =

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

### <a name="parameters"></a>Parâmetros

*Certo*\
O caminho adicionado.

*Str*\
A cadeia de caracteres adicionada.

*PTR*\
O ponteiro adicionado.

*elem*\
`value_type` O ou`Elem`o.

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

## <a name="op_divide"></a>caminho:: operador/=

Várias `append` expressões.

```cpp
path& operator/=(const path& right);

template <class Source>
path& operator/=(const Source& source);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O caminho adicionado.

*original*\
A fonte adicionada.

### <a name="remarks"></a>Comentários

As funções de membro se comportam da mesma maneira que as seguintes expressões correspondentes:

1. `append(right);`

1. `append(source);`

## <a name="op_string"></a>caminho:: operador string_type

Retorna `myname`.

```cpp
operator string_type() const;
```

## <a name="parent_path"></a> path::parent_path

Retorna o componente de caminho pai `myname`de.

```cpp
path parent_path() const;
```

### <a name="remarks"></a>Comentários

Retorna o componente de caminho pai `myname`de, especificamente o prefixo `myname` de após `filename().native()` a remoção e quaisquer separadores de diretório imediatamente precedentes. (Igualmente, se `begin() != end()`for, a combinação de todos os elementos no intervalo `[begin(), --end())` é aplicada `operator/=`sucessivamente.) O componente pode estar vazio.

## <a name="path"></a> path::path

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

### <a name="parameters"></a>Parâmetros

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

Para `path()` ele é `myname()`.

Para `path(const path& right`o) é `myname(right.myname)`.

Para `path(path&& right)` ele é `myname(right.myname)`.

Para `template<class Source> path(const Source& source)` ele é `myname(source)`.

Para `template<class Source> path(const Source& source, const locale& loc)` `loc`isso, obter todas as facetas codecvt necessárias do. `myname(source)`

Para `template<class InIt> path(InIt first, InIt last)` ele é `myname(first, last)`.

Para `template<class InIt> path(InIt first, InIt last, const locale& loc)` `loc`isso, obter todas as facetas codecvt necessárias do. `myname(first, last)`

## <a name="preferred_separator"></a> path::preferred_separator

O objeto constante fornece o caractere preferencial para separar os componentes do caminho, dependendo do sistema operacional do host.

```cpp
#if _WIN32_C_LIB
static constexpr value_type preferred_separator == L'\\';
#else // assume Posix
static constexpr value_type preferred_separator == '/';
#endif // filesystem model now defined
```

### <a name="remarks"></a>Comentários

Observe que é igualmente permitido na maioria dos contextos no Windows usar L'/' em seu lugar.

## <a name="relative_path"></a> path::relative_path

Retorna o componente de caminho relativo `myname`de.

```cpp
path relative_path() const;
```

### <a name="remarks"></a>Comentários

Retorna o componente de caminho relativo `myname`de, especificamente o sufixo `myname` de após `root_path().native()` a remoção e quaisquer separadores de diretórios redundantes subsequentes imediatamente. O componente pode estar vazio.

## <a name="remove_filename"></a> path::remove_filename

Remove o nome do arquivo.

```cpp
path& remove_filename();
```

## <a name="replace_extension"></a>caminho:: replace_extension

Substitui a extensão de `myname`.

```cpp
path& replace_extension(const path& newext = path());
```

### <a name="parameters"></a>Parâmetros

*newext*\
A nova extensão.

### <a name="remarks"></a>Comentários

Primeiro, remove o `extension().native()` sufixo `myname`de. Em seguida `!newext.empty() && newext[0] != dot` , se `dot` ( `*path(".").c_str()`WHERE é) `dot` , será anexado a `myname`. Em seguida, *newext* é acrescentado `myname`a.

## <a name="replace_filename"></a>caminho:: replace_filename

Substitui o nome do arquivo.

```cpp
path& replace_filename(const path& pval);
```

### <a name="parameters"></a>Parâmetros

*pval*\
O caminho do nome de arquivo.

### <a name="remarks"></a>Comentários

A função membro executa:

```cpp
remove_filename();

*this /= pval;
return (*this);
```

## <a name="root_directory"></a>caminho:: root_directory

Retorna o componente de diretório raiz `myname`de.

```cpp
path root_directory() const;
```

### <a name="remarks"></a>Comentários

O componente pode estar vazio.

## <a name="root_name"></a>caminho:: root_name

Retorna o componente de nome raiz `myname`do.

```cpp
path root_name() const;
```

### <a name="remarks"></a>Comentários

O componente pode estar vazio.

## <a name="root_path"></a> path::root_path

Retorna o componente de caminho raiz `myname`de.

```cpp
path root_path() const;
```

### <a name="remarks"></a>Comentários

Retorna o componente de caminho raiz `myname`de, `root_name()`especificamente  / . `root_directory` O componente pode estar vazio.

## <a name="stem"></a>caminho:: tronco

Retorna o `stem` componente do `myname`.

```cpp
path stem() const;
```

### <a name="remarks"></a>Comentários

Retorna o `stem` componente do `myname` `filename().native()` ,`extension().native()` especificamente com qualquer removida à direita. O componente pode estar vazio.

## <a name="string"></a>caminho:: cadeia de caracteres

Converte a sequência armazenada `mypath`em.

```cpp
template \<class Elem, class Traits = char_traits\<Elem>, class Alloc = allocator\<Elem>>
basic_string\<Elem, Traits, Alloc> string(const Alloc& al = Alloc()) const;
string string() const;
```

### <a name="remarks"></a>Comentários

A primeira função de membro (modelo) converte a sequência armazenada `mypath` da mesma maneira que:

1. `string()`fins`string<char, Traits, Alloc>()`

1. `wstring()`fins`string<wchar_t, Traits, Alloc>()`

1. `u16string()`fins`string<char16_t, Traits, Alloc>()`

1. `u32string()`fins`string<char32_t, Traits, Alloc>()`

A segunda função de membro converte a sequência armazenada em `mypath` na codificação preferida pelo sistema host para uma sequência de **caracteres** e a retorna armazenada em um objeto do `string`tipo.

## <a name="string_type"></a>caminho:: string_type

O tipo é um sinônimo de `basic_string<value_type>`.

```cpp
typedef basic_string<value_type> string_type;
```

## <a name="swap"></a> path::swap

É executado `swap(mypath, right.mypath)`.

```cpp
void swap(path& right) noexcept;
```

## <a name="u16string"></a> path::u16string

Converte a sequência armazenada `mypath` em UTF-16 e a retorna armazenada em um objeto do `u16string`tipo.

```cpp
u16string u16string() const;
```

## <a name="u32string"></a> path::u32string

Converte a sequência armazenada `mypath` em UTF-32 e a retorna armazenada em um objeto do `u32string`tipo.

```cpp
u32string u32string() const;
```

## <a name="u8string"></a>caminho:: u8string

Converte a sequência armazenada `mypath` em UTF-8 e a retorna armazenada em um objeto do `u8string`tipo.

```cpp
string u8string() const;
```

## <a name="value_type"></a>caminho:: value_type

O tipo descreve os `path` elementos favorecedos pelo sistema operacional do host.

```cpp
#if _WIN32_C_LIB
typedef wchar_t value_type;
#else // assume Posix
typedef char value_type;
#endif // filesystem model now defined
```

## <a name="wstring"></a>caminho:: wstring

Converte a sequência armazenada `mypath` em na codificação preferida pelo sistema host para uma sequência **wchar_t** e a retorna armazenada em um objeto do tipo `wstring`.

```cpp
wstring wstring() const;
```

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
