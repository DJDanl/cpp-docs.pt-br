---
title: Classe path| Microsoft Docs
ms.custom: ''
ms.date: 09/27/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- filesystem/std::experimental::filesystem::path
dev_langs:
- C++
ms.assetid: 8a1227ca-aeb2-4e0e-84aa-86e34e4f4fe8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7674f07c92f8a0c9d8a9070f3f99e00dfde39140
ms.sourcegitcommit: 1d9bd38cacbc783fccd3884b7b92062161c91c84
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/03/2018
ms.locfileid: "48235458"
---
# <a name="path-class"></a>Classe path

O **caminho** classe armazena um objeto do tipo `string_type`, chamado `myname` aqui para fins de explicação, adequada para uso como um nome de caminho. `string_type` é um sinônimo de `basic_string<value_type>`, onde `value_type` é um sinônimo de **wchar_t** no Windows ou **char** em POSIX.

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
|[iterator](#iterator)|Um iterador bidirecional constante que designa a `path` componentes de `myname`.|
|[string_type](#string_type)|O tipo é um sinônimo de `basic_string<value_type>`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[append](#append)|Acrescenta a sequência especificada para `mypath`, convertido e inserindo um preferred_separator conforme necessário.|
|[assign](#assign)|Substitui `mypath` com a sequência especificada, convertido conforme necessário.|
|[begin](#begin)|Retorna um `path::iterator` que designa o primeiro elemento de caminho no nome do caminho, se estiver presente.|
|[c_str](#c_str)|Retorna um ponteiro para o primeiro caractere em `mypath`.|
|[clear](#clear)|Executa `mypath.clear()`.|
|[compare](#compare)|Retorna valores de comparação.|
|[concat](#compare)|Acrescenta a sequência especificada para `mypath`, convertido (mas não inserindo um separador) conforme necessário.|
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
|[is_absolute](#is_absolute)|Para Windows, a função retorna `has_root_name() && has_root_directory()`. Para Posix, a função retorna `has_root_directory()`.|
|[is_relative](#is_relative)|Retorna `!is_absolute()`.|
|[make_preferred](#make_preferred)|Converte cada separador em um preferred_separator conforme necessário.|
|[nativo](#native)|Retorna `myname`.|
|[parent_path](#parent_path)|Retorna o pai de componente de caminho do `myname`.|
|[preferred_separator](#preferred_separator)|O objeto constante fornece o caractere preferencial para separar os componentes do caminho, dependendo do sistema operacional do host. |
|[RELATIVE_PATH](#relative_path)|Retorna o componente de caminho relativo do `myname`. |
|[remove_filename](#remove_filename)|Remove o nome do arquivo.|
|[replace_extension](#replace_extension)|Substitui a extensão de `myname`. |
|[replace_filename](#replace_filename)|RReplaces o nome do arquivo.|
|[root_directory](#root_directory)|Retorna o componente do diretório raiz do `myname`. |
|[root_name](#root_name)|Retorna o componente de nome raiz do `myname`. |
|[root_path](#root_path)|Retorna o componente de caminho raiz do `myname`.|
|[Stem](#stem)|Retorna o `stem` componente de `myname`.|
|[string](#string)|Converte a sequência armazenada em `mypath`.|
|[swap](#swap)|Executa `swap(mypath, right.mypath)`.|
|[u16string](#u16string)|Converte a sequência armazenada em `mypath` UTF-16 e a retorna armazenada em um objeto do tipo `u16string`.|
|[u32string](#u32string)|Converte a sequência armazenada em `mypath` UTF-32 e a retorna armazenada em um objeto do tipo `u32string`.|
|[u8string](#u8string)|Converte a sequência armazenada em `mypath` UTF-8 e a retorna armazenada em um objeto do tipo `u8string`.|
|[value_type](#value_type)|O tipo descreve os elementos de caminho preferidos pelo sistema operacional do host.|
|[wstring](#wstring)|Converte a sequência armazenada em `mypath` codificação preferida pelo sistema host para um `wchar_t` sequência e a retorna armazenada em um objeto do tipo `wstring`.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator=](#op_as)|Substitui os elementos do caminho com uma cópia de outro caminho.|
|[operator+=](#op_add)|Vários `concat` expressões.|
|[operator/=](#op_divide)|Vários `append` expressões.|
|[operador string_type](#op_string)|Retorna `myname`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<filesystem >

**Namespace:** std::experimental::filesystem

## <a name="append"></a> path:: append

Acrescenta a sequência especificada `mypath`, convertido e inserindo um `preferred_separator` conforme necessário.

```cpp
template <class Source>
path& append(const Source& source);

template <class InIt>
path& append(InIt first, InIt last);
```

### <a name="parameters"></a>Parâmetros

*source*<br/>
Sequência especificada.

*first*<br/>
Início da sequência especificada.

*last*<br/>
Fim da sequência especificada.

## <a name="assign"></a> path:: Assign

Substitui `mypath` com a sequência especificada, convertido conforme necessário.

```cpp
template <class Source>
path& assign(const Source& source);

template <class InIt>
path& assign(InIt first, InIt last);
```

### <a name="parameters"></a>Parâmetros

*source*<br/>
Sequência especificada.

*first*<br/>
Início da sequência especificada.

*last*<br/>
Fim da sequência especificada.

## <a name="begin"></a> path:: begin

Retorna um `path::iterator` que designa o primeiro elemento de caminho no nome do caminho, se estiver presente.

```cpp
iterator begin() const;
```

## <a name="c_str"></a> path::c_str

Retorna um ponteiro para o primeiro caractere em `mypath`.

```cpp
const value_type& *c_str() const noexcept;
```

## <a name="clear"></a> path:: Clear

Executa `mypath.clear()`.

```cpp
void clear() noexcept;
```

## <a name="compare"></a> path:: Compare

A primeira função retorna `mypath.compare(pval.native())`. A segunda função retorna `mypath.compare(str)`. A terceira função retorna `mypath.compare(ptr)`.

```cpp
int compare(const path& pval) const noexcept;
int compare(const string_type& str) const;
int compare(const value_type *ptr) const;
```

### <a name="parameters"></a>Parâmetros

*PVal*<br/>
Caminho a ser comparado.

*str*<br/>
Cadeia de caracteres a ser comparado.

*ptr*<br/>
Ponteiro para comparar.

## <a name="concat"></a> path:: concat

Acrescenta a sequência especificada para `mypath`, convertido (mas não inserindo um separador) conforme necessário.

```cpp
template <class Source>
path& concat(const Source& source);

template <class InIt>
path& concat(InIt first, InIt last);
```

### <a name="parameters"></a>Parâmetros

*source*<br/>
Sequência especificada.

*first*<br/>
Início da sequência especificada.

*last*<br/>
Fim da sequência especificada.

## <a name="const_iterator"></a> path::const_iterator

Um sinônimo de `iterator`.

```cpp
typedef iterator const_iterator;
```

## <a name="empty"></a> path:: Empty

Retorna `mypath.empty()`.

```cpp
bool empty() const noexcept;
```

## <a name="end"></a> path:: end

Retorna um iterador de fim de sequência do tipo `iterator`.

```cpp
iterator end() const;
```

## <a name="extension"></a> path:: Extension

Retorna o sufixo de `filename()`.

```cpp
path extension() const;
```

### <a name="remarks"></a>Comentários

Retorna o sufixo de `filename() X` , de modo que:

Se `X == path(".") || X == path("..")` ou se `X` não contiver nenhum ponto, o sufixo será vazio.

Caso contrário, o sufixo começa com (e inclui) o ponto mais à direita.

## <a name="filename"></a> path:: filename

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

## <a name="generic_u16string"></a> path::generic_u16string

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

## <a name="has_filename"></a> path:: has_filename

Retorna `!filename().empty()`.

```cpp
bool has_filename() const;
```

## <a name="has_parent_path"></a> path:: has_parent_path

Retorna `!parent_path().empty()`.

```cpp
bool has_parent_path() const;
```

## <a name="has_relative_path"></a> path:: has_relative_path

Retorna `!relative_path().empty()`.

```cpp
bool has_relative_path() const;
```

## <a name="has_root_directory"></a> path:: has_root_directory

Retorna `!root_directory().empty()`.

```cpp
bool has_root_directory() const;
```

## <a name="has_root_name"></a> path:: has_root_name

Retorna `!root_name().empty()`.

```cpp
bool has_root_name() const;
```

## <a name="has_root_path"></a> path:: has_root_path

Retorna `!root_path().empty()`.

```cpp
bool has_root_path() const;
```

## <a name="has_stem"></a> path::has_stem

Retorna `!stem().empty()`.

```cpp
bool has_stem() const;
```

## <a name="is_absolute"></a> path:: is_absolute

Para Windows, a função retorna `has_root_name() && has_root_directory()`. Para Posix, a função retorna `has_root_directory()`.

```cpp
bool is_absolute() const;
```

## <a name="is_relative"></a> path:: is_relative

Retorna `!is_absolute()`.

```cpp
bool is_relative() const;
```

## <a name="iterator"></a> path:: Iterator

Um iterador bidirecional constante que designa os componentes do caminho de `myname`.

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

A classe descreve um iterador bidirecional constante que designa a `path` componentes de `myname` na sequência:

1. o nome raiz, se existir

1. o diretório raiz, se existir

1. os elementos restantes do diretório do pai `path`, se presente, terminando com o nome do arquivo, se estiver presente

Para `pval` um objeto do tipo `path`:

1. `path::iterator X = pval.begin()` Designa o primeiro `path` elemento no nome do caminho, se estiver presente.

1. `X == pval.end()` é verdadeiro quando `X` pontos logo após o final da sequência de componentes.

3. `*X` Retorna uma cadeia de caracteres que corresponde ao componente atual

1. `++X` Designa o próximo componente na sequência, se estiver presente.

1. `--X` Designa o componente anterior na sequência, se estiver presente.

1. Alterando `myname` invalida todos os iteradores que designam elementos `myname`.

## <a name="make_preferred"></a> path:: make_preferred

Converte cada separador para um `preferred_separator` conforme necessário.

```cpp
path& make_preferred();
```

## <a name="native"></a> path::Native

Retorna `myname`.

```cpp
const string_type& native() const noexcept;
```

## <a name="op_as"></a> path:: Operator =

Substitui os elementos do caminho com uma cópia de outro caminho.

```cpp
path& operator=(const path& right);
path& operator=(path&& right) noexcept;

template <class Source>
path& operator=(const Source& source);
```

### <a name="parameters"></a>Parâmetros

*right*<br/>
O [caminho](../standard-library/path-class.md) que está sendo copiado para o `path`.

*source*<br/>
O caminho de origem.

### <a name="remarks"></a>Comentários

As primeira cópias de operador de membro `right.myname` para `myname`. O segundo operador membro move `right.myname` para `myname`. O terceiro operador membro se comporta da mesma como `*this = path(source)`.

## <a name="op_add"></a> path:: Operator =

Vários `concat` expressões.

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

*right*<br/>
O caminho adicionado.

*str*<br/>
A cadeia de caracteres adicionada.

*ptr*<br/>
O ponteiro adicionado.

*Elem*<br/>
Adicionado `value_type` ou `Elem`.

*source*<br/>
A origem adicionada.

### <a name="remarks"></a>Comentários

As funções de membro se comportam da mesma maneira que as seguintes expressões correspondentes:

1. `concat(right);`

1. `concat(path(str));`

1. `concat(ptr);`

1. `concat(string_type(1, elem));`

1. `concat(source);`

1. `concat(path(basic_string<Elem>(1, elem)));`

## <a name="op_divide"></a> path:: Operator =

Vários `append` expressões.

```cpp
path& operator/=(const path& right);

template <class Source>
path& operator/=(const Source& source);
```

### <a name="parameters"></a>Parâmetros

*right*<br/>
O caminho adicionado.

*source*<br/>
A origem adicionada.

### <a name="remarks"></a>Comentários

As funções de membro se comportam da mesma maneira que as seguintes expressões correspondentes:

1. `append(right);`

1. `append(source);`

## <a name="op_string"></a> path:: Operator string_type

Retorna `myname`.

```cpp
operator string_type() const;
```

## <a name="parent_path"></a> path:: parent_path

Retorna o pai de componente de caminho do `myname`.

```cpp
path parent_path() const;
```

### <a name="remarks"></a>Comentários

Retorna o pai de componente de caminho `myname`, especificamente o prefixo de `myname` após a remoção de `filename().native()` e qualquer separador de diretório imediatamente anterior. (Da mesma forma, se `begin() != end()`, é a combinação de todos os elementos no intervalo `[begin(), --end())` aplicando sucessivamente `operator/=`.) O componente pode estar vazio.

## <a name="path"></a> path:: path

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

*right*<br/>
O caminho do qual o caminho criado é uma cópia.

*source*<br/>
A origem do qual o caminho criado é uma cópia.

*Loc*<br/>
A localidade especificada.

*first*<br/>
A posição do primeiro elemento a ser copiado.

*last*<br/>
A posição do último elemento a ser copiado.

### <a name="remarks"></a>Comentários

Os construtores todos construir `myname` de várias maneiras:

Para `path()` é `myname()`.

Para `path(const path& right`) é `myname(right.myname)`.

Para `path(path&& right)` é `myname(right.myname)`.

Para `template<class Source> path(const Source& source)` é `myname(source)`.

Para `template<class Source> path(const Source& source, const locale& loc)` vale `myname(source)`, obtendo facetas codecvt necessárias de `loc`.

Para `template<class InIt> path(InIt first, InIt last)` é `myname(first, last)`.

Para `template<class InIt> path(InIt first, InIt last, const locale& loc)` vale `myname(first, last)`, obtendo facetas codecvt necessárias de `loc`.

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

## <a name="relative_path"></a> path:: RELATIVE_PATH

Retorna o componente de caminho relativo do `myname`.

```cpp
path relative_path() const;
```

### <a name="remarks"></a>Comentários

Retorna o componente de caminho relativo `myname`, especificamente o sufixo de `myname` após a remoção de `root_path().native()` e qualquer separador de diretório imediatamente posterior. O componente pode estar vazio.

## <a name="remove_filename"></a> path:: remove_filename

Remove o nome do arquivo.

```cpp
path& remove_filename();
```

## <a name="replace_extension"></a> path:: replace_extension

Substitui a extensão de `myname`.

```cpp
path& replace_extension(const path& newext = path());
```

### <a name="parameters"></a>Parâmetros

*newext*<br/>
A nova extensão.

### <a name="remarks"></a>Comentários

Primeiro remove o sufixo `extension().native()` de `myname`. Então, se `!newext.empty() && newext[0] != dot` (onde `dot` é `*path(".").c_str()`), em seguida, `dot` é anexado ao `myname`. Em seguida *newext* será acrescentado ao `myname`.

## <a name="replace_filename"></a> path:: replace_filename

Substitui o nome do arquivo.

```cpp
path& replace_filename(const path& pval);
```

### <a name="parameters"></a>Parâmetros

*PVal*<br/>
O caminho do nome de arquivo.

### <a name="remarks"></a>Comentários

A função membro executa:

```cpp
remove_filename();

*this /= pval;
return (*this);
```

## <a name="root_directory"></a> path:: root_directory

Retorna o componente do diretório raiz do `myname`.

```cpp
path root_directory() const;
```

### <a name="remarks"></a>Comentários

O componente pode estar vazio.

## <a name="root_name"></a> path:: root_name

Retorna o componente de nome raiz do `myname`.

```cpp
path root_name() const;
```

### <a name="remarks"></a>Comentários

O componente pode estar vazio.

## <a name="root_path"></a> path:: root_path

Retorna o componente de caminho raiz do `myname`.

```cpp
path root_path() const;
```

### <a name="remarks"></a>Comentários

Retorna o componente de caminho raiz do `myname`, especificamente `root_name()`  /  `root_directory`. O componente pode estar vazio.

## <a name="stem"></a> path:: Stem

Retorna o `stem` componente de `myname`.

```cpp
path stem() const;
```

### <a name="remarks"></a>Comentários

Retorna o `stem` componente `myname`, especificamente `filename().native()` com qualquer à direita `extension().native()` removido. O componente pode estar vazio.

## <a name="string"></a> path::String

Converte a sequência armazenada em `mypath`.

```cpp
template \<class Elem, class Traits = char_traits\<Elem>, class Alloc = allocator\<Elem>>
basic_string\<Elem, Traits, Alloc> string(const Alloc& al = Alloc()) const;
string string() const;
```

### <a name="remarks"></a>Comentários

A primeira função de membro (modelo) converte a sequência armazenada em `mypath` da mesma maneira que:

1. `string()` para `string<char, Traits, Alloc>()`

1. `wstring()` para `string<wchar_t, Traits, Alloc>()`

1. `u16string()` para `string<char16_t, Traits, Alloc>()`

1. `u32string()` para `string<char32_t, Traits, Alloc>()`

A segunda função membro converte a sequência armazenada em `mypath` codificação preferida pelo sistema host para um **char** sequência e a retorna armazenada em um objeto do tipo `string`.

## <a name="string_type"></a> path::STRING_TYPE

O tipo é um sinônimo de `basic_string<value_type>`.

```cpp
typedef basic_string<value_type> string_type;
```

## <a name="swap"></a> path:: swap

Executa `swap(mypath, right.mypath)`.

```cpp
void swap(path& right) noexcept;
```

## <a name="u16string"></a> path::u16string

Converte a sequência armazenada em `mypath` UTF-16 e a retorna armazenada em um objeto do tipo `u16string`.

```cpp
u16string u16string() const;
```

## <a name="u32string"></a> path::u32string

Converte a sequência armazenada em `mypath` UTF-32 e a retorna armazenada em um objeto do tipo `u32string`.

```cpp
u32string u32string() const;
```

## <a name="u8string"></a> path::u8string

Converte a sequência armazenada em `mypath` UTF-8 e a retorna armazenada em um objeto do tipo `u8string`.

```cpp
string u8string() const;
```

## <a name="value_type"></a> path::value_type

O tipo descreve o `path` elementos preferidos pelo sistema operacional do host.

```cpp
#if _WIN32_C_LIB
typedef wchar_t value_type;
#else // assume Posix
typedef char value_type;
#endif // filesystem model now defined
```

## <a name="wstring"></a> path::wstring

Converte a sequência armazenada em `mypath` codificação preferida pelo sistema host para um **wchar_t** sequência e a retorna armazenada em um objeto do tipo `wstring`.

```cpp
wstring wstring() const;
```

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
