---
title: Classe path
ms.date: 09/27/2018
f1_keywords:
- filesystem/std::experimental::filesystem::path
ms.assetid: 8a1227ca-aeb2-4e0e-84aa-86e34e4f4fe8
ms.openlocfilehash: 669dfd2c8cd8576ebfb6684bab7cf63cdd51babc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372113"
---
# <a name="path-class"></a>Classe path

A classe **path** armazena `string_type`um `myname` objeto de tipo, chamado aqui para fins de exposição, adequado para uso como nome de caminho. `string_type`é um `basic_string<value_type>`sinônimo `value_type` para , onde é um sinônimo para **wchar_t** no Windows ou **char** no POSIX.

Para obter mais informações e exemplos de código, consulte [File System Navigation (C++)](../standard-library/file-system-navigation.md).

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
|[Iterador](#iterator)|Um iterador de constante bidirecional que designa os `path` componentes de `myname`.|
|[string_type](#string_type)|O tipo é um sinônimo de `basic_string<value_type>`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[append](#append)|Anexa a seqüência `mypath`especificada para, convertendo e inserindo uma preferred_separator conforme necessário.|
|[Atribuir](#assign)|Substitui-se `mypath` pela seqüência especificada, convertida conforme necessário.|
|[Começar](#begin)|Retorna `path::iterator` um designando o primeiro elemento de caminho no nome do caminho, se presente.|
|[c_str](#c_str)|Retorna um ponteiro para `mypath`o primeiro caractere em .|
|[Claro](#clear)|Executa `mypath.clear()`.|
|[Comparar](#compare)|Valores de comparação de retornos.|
|[Concat](#compare)|Anexa a seqüência `mypath`especificada para, convertida (mas não inserindo um separador) conforme necessário.|
|[Vazio](#empty)|Retorna `mypath.empty()`.|
|[end](#end)|Retorna um ativador de fim de `iterator`seqüência do tipo .|
|[Extensão](#extension)|Retorna o sufixo de `filename()`.|
|[Filename](#filename)|Retorna o componente do diretório raiz do myname, especificamente `empty() path() : *--end()`. O componente pode estar vazio.|
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
|[is_absolute](#is_absolute)|Para windows, a `has_root_name() && has_root_directory()`função retorna . Para POSIX, a `has_root_directory()`função retorna .|
|[is_relative](#is_relative)|Retorna `!is_absolute()`.|
|[make_preferred](#make_preferred)|Converte cada separador em um preferred_separator conforme necessário.|
|[native](#native)|Retorna `myname`.|
|[parent_path](#parent_path)|Retorna o componente `myname`de caminho pai de .|
|[preferred_separator](#preferred_separator)|O objeto constante fornece o caractere preferencial para separar os componentes do caminho, dependendo do sistema operacional do host. |
|[relative_path](#relative_path)|Retorna o componente `myname`de caminho relativo de . |
|[remove_filename](#remove_filename)|Remove o nome do arquivo.|
|[replace_extension](#replace_extension)|Substitui a extensão de `myname`. |
|[replace_filename](#replace_filename)|RSubstituo o nome do arquivo.|
|[root_directory](#root_directory)|Retorna o componente de `myname`diretório raiz de . |
|[root_name](#root_name)|Retorna o componente `myname`de nome raiz de . |
|[root_path](#root_path)|Retorna o componente `myname`de caminho raiz de .|
|[stem](#stem)|Retorna `stem` o `myname`componente de .|
|[cadeia de caracteres](#string)|Converte a seqüência armazenada em `mypath`.|
|[Trocar](#swap)|Executa `swap(mypath, right.mypath)`.|
|[u16string](#u16string)|Converte a seqüência armazenada em `mypath` UTF-16 e `u16string`a devolve armazenada em um objeto de tipo .|
|[u32string](#u32string)|Converte a seqüência armazenada em `mypath` UTF-32 e `u32string`a devolve armazenada em um objeto de tipo .|
|[u8string](#u8string)|Converte a seqüência armazenada em `mypath` UTF-8 e `u8string`a devolve armazenada em um objeto de tipo .|
|[Value_type](#value_type)|O tipo descreve os elementos de caminho preferidos pelo sistema operacional do host.|
|[wstring](#wstring)|Converte a seqüência armazenada na `mypath` codificação favorecida `wchar_t` pelo sistema host para uma `wstring`seqüência e a devolve armazenada em um objeto de tipo .|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador=](#op_as)|Substitui os elementos do caminho por uma cópia de outro caminho.|
|[operador+=](#op_add)|Várias `concat` expressões.|
|[operador/=](#op_divide)|Várias `append` expressões.|
|[operador string_type](#op_string)|Retorna `myname`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<> do sistema de arquivos

**Namespace:** std::experimental::filesystem

## <a name="pathappend"></a><a name="append"></a>caminho::apêndice

Anexa a seqüência `mypath`especificada para, `preferred_separator` convertida e inserindo uma conforme necessário.

```cpp
template <class Source>
path& append(const Source& source);

template <class InIt>
path& append(InIt first, InIt last);
```

### <a name="parameters"></a>Parâmetros

*Fonte*\
Seqüência especificada.

*Primeiro*\
Início da seqüência especificada.

*Última*\
Fim da seqüência especificada.

## <a name="pathassign"></a><a name="assign"></a>caminho::atribuir

Substitui-se `mypath` pela seqüência especificada, convertida conforme necessário.

```cpp
template <class Source>
path& assign(const Source& source);

template <class InIt>
path& assign(InIt first, InIt last);
```

### <a name="parameters"></a>Parâmetros

*Fonte*\
Seqüência especificada.

*Primeiro*\
Início da seqüência especificada.

*Última*\
Fim da seqüência especificada.

## <a name="pathbegin"></a><a name="begin"></a>caminho::iniciar

Retorna `path::iterator` um designando o primeiro elemento de caminho no nome do caminho, se presente.

```cpp
iterator begin() const;
```

## <a name="pathc_str"></a><a name="c_str"></a>caminho::c_str

Retorna um ponteiro para `mypath`o primeiro caractere em .

```cpp
const value_type& *c_str() const noexcept;
```

## <a name="pathclear"></a><a name="clear"></a>caminho::claro

Executa `mypath.clear()`.

```cpp
void clear() noexcept;
```

## <a name="pathcompare"></a><a name="compare"></a>caminho::comparar

A primeira função retorna `mypath.compare(pval.native())`. A segunda função retorna `mypath.compare(str)`. A terceira `mypath.compare(ptr)`função retorna .

```cpp
int compare(const path& pval) const noexcept;
int compare(const string_type& str) const;
int compare(const value_type *ptr) const;
```

### <a name="parameters"></a>Parâmetros

*Pval*\
Caminho para comparar.

*Str*\
String para comparar.

*Ptr*\
Ponteiro para comparar.

## <a name="pathconcat"></a><a name="concat"></a>caminho::concat

Anexa a seqüência `mypath`especificada para, convertida (mas não inserindo um separador) conforme necessário.

```cpp
template <class Source>
path& concat(const Source& source);

template <class InIt>
path& concat(InIt first, InIt last);
```

### <a name="parameters"></a>Parâmetros

*Fonte*\
Seqüência especificada.

*Primeiro*\
Início da seqüência especificada.

*Última*\
Fim da seqüência especificada.

## <a name="pathconst_iterator"></a><a name="const_iterator"></a>caminho::const_iterator

Um sinônimo de `iterator`.

```cpp
typedef iterator const_iterator;
```

## <a name="pathempty"></a><a name="empty"></a>caminho::vazio

Retorna `mypath.empty()`.

```cpp
bool empty() const noexcept;
```

## <a name="pathend"></a><a name="end"></a>caminho::fim

Retorna um ativador de fim de `iterator`seqüência do tipo .

```cpp
iterator end() const;
```

## <a name="pathextension"></a><a name="extension"></a>caminho::extensão

Retorna o sufixo de `filename()`.

```cpp
path extension() const;
```

### <a name="remarks"></a>Comentários

Retorna o sufixo de `filename() X` tal forma que:

Se `X == path(".") || X == path("..")` ou `X` se não contiver nenhum dote, o sufixo está vazio.

Caso contrário, o sufixo começa com (e inclui) o ponto mais à direita.

## <a name="pathfilename"></a><a name="filename"></a>path::filename

Retorna o componente do diretório raiz do myname, especificamente `empty() path() : *--end()`. O componente pode estar vazio.

```cpp
path filename() const;
```

## <a name="pathgeneric_string"></a><a name="generic_string"></a>caminho::generic_string

Retorna `this->string<Elem, Traits, Alloc>(al)` com (em Windows) qualquer barra invertida convertida em barra "/".

```cpp
template <class Elem,
    class Traits = char_traits<Elem>,
    class Alloc = allocator<Elem>>
  basic_string<Elem, Traits, Alloc>
    generic_string(const Alloc& al = Alloc()) const;

string generic_string() const;
```

## <a name="pathgeneric_u16string"></a><a name="generic_u16string"></a>caminho::generic_u16string

Retorna `u16string()` com (em Windows) qualquer barra invertida convertida em barra "/".

```cpp
u16string generic_u16string() const;
```

## <a name="pathgeneric_u32string"></a><a name="generic_u32string"></a>caminho::generic_u32string

Retorna `u32string()` com (em Windows) qualquer barra invertida convertida em barra "/".

```cpp
u32string generic_u32string() const;
```

## <a name="pathgeneric_u8string"></a><a name="generic_u8string"></a>caminho::generic_u8string

Retorna `u8string()` com (em Windows) qualquer barra invertida convertida em barra "/".

```cpp
string generic_u8string() const;
```

## <a name="pathgeneric_wstring"></a><a name="generic_wstring"></a>caminho::generic_wstring

Retorna `wstring()` com (em Windows) qualquer barra invertida convertida em barra "/".

```cpp
wstring generic_wstring() const;
```

## <a name="pathhas_extension"></a><a name="has_extension"></a>caminho::has_extension

Retorna `!extension().empty()`.

```cpp
bool has_extension() const;
```

## <a name="pathhas_filename"></a><a name="has_filename"></a>caminho::has_filename

Retorna `!filename().empty()`.

```cpp
bool has_filename() const;
```

## <a name="pathhas_parent_path"></a><a name="has_parent_path"></a>caminho::has_parent_path

Retorna `!parent_path().empty()`.

```cpp
bool has_parent_path() const;
```

## <a name="pathhas_relative_path"></a><a name="has_relative_path"></a>caminho::has_relative_path

Retorna `!relative_path().empty()`.

```cpp
bool has_relative_path() const;
```

## <a name="pathhas_root_directory"></a><a name="has_root_directory"></a>caminho::has_root_directory

Retorna `!root_directory().empty()`.

```cpp
bool has_root_directory() const;
```

## <a name="pathhas_root_name"></a><a name="has_root_name"></a>caminho::has_root_name

Retorna `!root_name().empty()`.

```cpp
bool has_root_name() const;
```

## <a name="pathhas_root_path"></a><a name="has_root_path"></a>caminho::has_root_path

Retorna `!root_path().empty()`.

```cpp
bool has_root_path() const;
```

## <a name="pathhas_stem"></a><a name="has_stem"></a>caminho::has_stem

Retorna `!stem().empty()`.

```cpp
bool has_stem() const;
```

## <a name="pathis_absolute"></a><a name="is_absolute"></a>caminho::is_absolute

Para windows, a `has_root_name() && has_root_directory()`função retorna . Para POSIX, a `has_root_directory()`função retorna .

```cpp
bool is_absolute() const;
```

## <a name="pathis_relative"></a><a name="is_relative"></a>caminho::is_relative

Retorna `!is_absolute()`.

```cpp
bool is_relative() const;
```

## <a name="pathiterator"></a><a name="iterator"></a>caminho::iterator

Um iterador de constante bidirecional que `myname`designa os componentes do caminho de .

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

A classe descreve um iterador de constante `path` bidirecional `myname` que designa os componentes da seqüência:

1. o nome raiz, se existir

1. o diretório raiz, se existir

1. os elementos restantes `path`do diretório do pai, se presente, terminando com o nome do arquivo, se presente

Para `pval` um objeto `path`de tipo:

1. `path::iterator X = pval.begin()`designa o `path` primeiro elemento no nome do caminho, se presente.

1. `X == pval.end()`é verdade `X` quando pontos logo após o fim da seqüência de componentes.

1. `*X`retorna uma seqüência que corresponde ao componente atual

1. `++X`designa o próximo componente na seqüência, se presente.

1. `--X`designa o componente anterior na seqüência, se presente.

1. Alterar `myname` invalida todos os iterizadores `myname`que designam elementos em .

## <a name="pathmake_preferred"></a><a name="make_preferred"></a>caminho::make_preferred

Converte cada separador `preferred_separator` em um conforme necessário.

```cpp
path& make_preferred();
```

## <a name="pathnative"></a><a name="native"></a>caminho::nativo

Retorna `myname`.

```cpp
const string_type& native() const noexcept;
```

## <a name="pathoperator"></a><a name="op_as"></a>caminho::operador=

Substitui os elementos do caminho por uma cópia de outro caminho.

```cpp
path& operator=(const path& right);
path& operator=(path&& right) noexcept;

template <class Source>
path& operator=(const Source& source);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O [caminho](../standard-library/path-class.md) que está `path`sendo copiado para o .

*Fonte*\
O caminho de origem.

### <a name="remarks"></a>Comentários

O primeiro operador `right.myname` `myname`membro copia para . O segundo operador `right.myname` `myname`membro passa para . O terceiro operador membro se `*this = path(source)`comporta da mesma forma que .

## <a name="pathoperator"></a><a name="op_add"></a>caminho::operador+=

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
A seqüência adicionada.

*Ptr*\
O ponteiro adicionado.

*Elem*\
O `value_type` adicionado `Elem`ou .

*Fonte*\
A fonte adicionada.

### <a name="remarks"></a>Comentários

As funções de membro se comportam da mesma maneira que as seguintes expressões correspondentes:

1. `concat(right);`

1. `concat(path(str));`

1. `concat(ptr);`

1. `concat(string_type(1, elem));`

1. `concat(source);`

1. `concat(path(basic_string<Elem>(1, elem)));`

## <a name="pathoperator"></a><a name="op_divide"></a>caminho::operador/=

Várias `append` expressões.

```cpp
path& operator/=(const path& right);

template <class Source>
path& operator/=(const Source& source);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O caminho adicionado.

*Fonte*\
A fonte adicionada.

### <a name="remarks"></a>Comentários

As funções de membro se comportam da mesma maneira que as seguintes expressões correspondentes:

1. `append(right);`

1. `append(source);`

## <a name="pathoperator-string_type"></a><a name="op_string"></a>caminho:string_type do operador

Retorna `myname`.

```cpp
operator string_type() const;
```

## <a name="pathparent_path"></a><a name="parent_path"></a>caminho::parent_path

Retorna o componente `myname`de caminho pai de .

```cpp
path parent_path() const;
```

### <a name="remarks"></a>Comentários

Retorna o componente `myname`de caminho pai `myname` de , `filename().native()` especificamente o prefixo de após a remoção e quaisquer separadores de diretório imediatamente anteriores. (Igualmente, `begin() != end()`se, é a combinação de `[begin(), --end())` todos os elementos na faixa aplicando `operator/=`sucessivamente .) O componente pode estar vazio.

## <a name="pathpath"></a><a name="path"></a>caminho::path

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

*Fonte*\
A fonte do caminho construído é ser uma cópia.

*Loc*\
O local especificado.

*Primeiro*\
A posição do primeiro elemento a ser copiado.

*Última*\
A posição do último elemento a ser copiado.

### <a name="remarks"></a>Comentários

Os construtores todos `myname` constroem de várias maneiras:

Pois `path()` é. `myname()`

Para `path(const path& right`) `myname(right.myname)`é .

Pois `path(path&& right)` é. `myname(right.myname)`

Pois `template<class Source> path(const Source& source)` é. `myname(source)`

Pois `template<class Source> path(const Source& source, const locale& loc)` é, `myname(source)`obtendo todas as facetas codecvt necessárias de `loc`.

Pois `template<class InIt> path(InIt first, InIt last)` é. `myname(first, last)`

Pois `template<class InIt> path(InIt first, InIt last, const locale& loc)` é, `myname(first, last)`obtendo todas as facetas codecvt necessárias de `loc`.

## <a name="pathpreferred_separator"></a><a name="preferred_separator"></a>caminho::preferred_separator

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

## <a name="pathrelative_path"></a><a name="relative_path"></a>caminho::relative_path

Retorna o componente `myname`de caminho relativo de .

```cpp
path relative_path() const;
```

### <a name="remarks"></a>Comentários

Retorna o componente `myname`de caminho relativo de `myname` , `root_path().native()` especificamente o sufixo de após a remoção e quaisquer separadores de diretório redundante imediatamente subseqüentes. O componente pode estar vazio.

## <a name="pathremove_filename"></a><a name="remove_filename"></a>caminho::remove_filename

Remove o nome do arquivo.

```cpp
path& remove_filename();
```

## <a name="pathreplace_extension"></a><a name="replace_extension"></a>path::replace_extension

Substitui a extensão de `myname`.

```cpp
path& replace_extension(const path& newext = path());
```

### <a name="parameters"></a>Parâmetros

*newext*\
A nova extensão.

### <a name="remarks"></a>Comentários

Primeiro remove o sufixo `extension().native()` de `myname`. Em `!newext.empty() && newext[0] != dot` seguida, `dot` `*path(".").c_str()`se `dot` (onde está), então é anexado a `myname`. Em *seguida, newext* é anexado a `myname`.

## <a name="pathreplace_filename"></a><a name="replace_filename"></a>caminho::replace_filename

Substitui o nome do arquivo.

```cpp
path& replace_filename(const path& pval);
```

### <a name="parameters"></a>Parâmetros

*Pval*\
O caminho do nome do arquivo.

### <a name="remarks"></a>Comentários

A função membro executa:

```cpp
remove_filename();

*this /= pval;
return (*this);
```

## <a name="pathroot_directory"></a><a name="root_directory"></a>caminho::root_directory

Retorna o componente de `myname`diretório raiz de .

```cpp
path root_directory() const;
```

### <a name="remarks"></a>Comentários

O componente pode estar vazio.

## <a name="pathroot_name"></a><a name="root_name"></a>caminho::root_name

Retorna o componente `myname`de nome raiz de .

```cpp
path root_name() const;
```

### <a name="remarks"></a>Comentários

O componente pode estar vazio.

## <a name="pathroot_path"></a><a name="root_path"></a>caminho::root_path

Retorna o componente `myname`de caminho raiz de .

```cpp
path root_path() const;
```

### <a name="remarks"></a>Comentários

Retorna o componente `myname`de caminho `root_name()`  /  `root_directory`raiz de , especificamente . O componente pode estar vazio.

## <a name="pathstem"></a><a name="stem"></a>caminho::haste

Retorna `stem` o `myname`componente de .

```cpp
path stem() const;
```

### <a name="remarks"></a>Comentários

Retorna `stem` o `myname`componente de `filename().native()` , especificamente com qualquer arrasto `extension().native()` removido. O componente pode estar vazio.

## <a name="pathstring"></a><a name="string"></a>caminho::string

Converte a seqüência armazenada em `mypath`.

```cpp
template \<class Elem, class Traits = char_traits\<Elem>, class Alloc = allocator\<Elem>>
basic_string\<Elem, Traits, Alloc> string(const Alloc& al = Alloc()) const;
string string() const;
```

### <a name="remarks"></a>Comentários

A primeira função de membro (modelo) `mypath` converte a seqüência armazenada da mesma forma que:

1. `string()` para `string<char, Traits, Alloc>()`

1. `wstring()` para `string<wchar_t, Traits, Alloc>()`

1. `u16string()` para `string<char16_t, Traits, Alloc>()`

1. `u32string()` para `string<char32_t, Traits, Alloc>()`

A segunda função de membro `mypath` converte a seqüência armazenada na codificação favorecida pelo sistema host `string`para uma seqüência de **char** e a devolve armazenada em um objeto de tipo .

## <a name="pathstring_type"></a><a name="string_type"></a>caminho::string_type

O tipo é um sinônimo de `basic_string<value_type>`.

```cpp
typedef basic_string<value_type> string_type;
```

## <a name="pathswap"></a><a name="swap"></a>caminho::swap

Executa `swap(mypath, right.mypath)`.

```cpp
void swap(path& right) noexcept;
```

## <a name="pathu16string"></a><a name="u16string"></a>caminho::u16string

Converte a seqüência armazenada em `mypath` UTF-16 e `u16string`a devolve armazenada em um objeto de tipo .

```cpp
u16string u16string() const;
```

## <a name="pathu32string"></a><a name="u32string"></a>caminho::u32string

Converte a seqüência armazenada em `mypath` UTF-32 e `u32string`a devolve armazenada em um objeto de tipo .

```cpp
u32string u32string() const;
```

## <a name="pathu8string"></a><a name="u8string"></a>caminho::u8string

Converte a seqüência armazenada em `mypath` UTF-8 e `u8string`a devolve armazenada em um objeto de tipo .

```cpp
string u8string() const;
```

## <a name="pathvalue_type"></a><a name="value_type"></a>caminho::value_type

O tipo descreve `path` os elementos favorecidos pelo sistema operacional host.

```cpp
#if _WIN32_C_LIB
typedef wchar_t value_type;
#else // assume POSIX
typedef char value_type;
#endif // filesystem model now defined
```

## <a name="pathwstring"></a><a name="wstring"></a>caminho::wstring

Converte a seqüência armazenada na `mypath` codificação favorecida pelo sistema host para uma **seqüência de wchar_t** e a devolve armazenada em um objeto de tipo `wstring`.

```cpp
wstring wstring() const;
```

## <a name="see-also"></a>Confira também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
