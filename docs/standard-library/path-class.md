---
title: Classe path| Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- filesystem/std::experimental::filesystem::path
dev_langs:
- C++
ms.assetid: 8a1227ca-aeb2-4e0e-84aa-86e34e4f4fe8
caps.latest.revision: 14
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 12e342baa69a0fa9b354d1eac7890f5c38637c1b
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="path-class"></a>Classe path

A classe **path** armazena um objeto do tipo string\_type, chamado myname aqui para fins de explicação, adequada para uso como um nome de caminho. string\_type é um sinônimo de basic\_string\<value_type>, em que value\_type é um sinônimo para char em Windows ou wchar_t em Posix.

Para obter mais informações e exemplos de código, consulte [Navegação do Sistema de Arquivos (C++)](../standard-library/file-system-navigation.md).

## <a name="syntax"></a>Sintaxe

```cpp
class path;
```

## <a name="pathappend"></a>path::append

```cpp
template <class Source>
path& append(const Source& source);

template <class InIt>
path& append(InIt first, InIt last);
```

As funções de membro acrescentam a sequência especificada ao mypath, convertido e inserindo um preferred_separator conforme necessário.

## <a name="pathassign"></a>path::assign

```cpp
template <class Source>
path& assign(const Source& source);

template <class InIt>
path& assign(InIt first, InIt last);
```

As funções de membro substituem mypath com a sequência especificada, convertido conforme necessário.

## <a name="pathbegin"></a>path::begin

```cpp
iterator begin() const;
```

Retorna um path::iterator designando o primeiro elemento de caminho no nome do caminho, se existir.

## <a name="pathcstr"></a>path::c_str

```cpp
const value_type& *c_str() const noexcept;
```

Retorna um ponteiro para o primeiro caractere em mypath.

## <a name="pathclear"></a>path::clear

```cpp
void clear() noexcept;
```

A função membro executa mypath.clear()

## <a name="pathcompare"></a>path::compare

```cpp
int compare(const path& pval) const noexcept;
int compare(const string_type& str) const;
int compare(const value_type *ptr) const;
```

A primeira função retorna mypath.compare(pval.native()). A segunda função retorna mypath.compare(str). A terceira função retorna mypath.compare(ptr).

## <a name="pathconcat"></a>path::concat

```cpp
template <class Source>
path& concat(const Source& source);

template <class InIt>
path& concat(InIt first, InIt last);
```

As funções de membro acrescentam a sequência especificada ao mypath, convertido (mas não inserindo um separador) conforme necessário.

## <a name="pathconstiterator"></a>path::const_iterator

```cpp
typedef iterator const_iterator;
```

O tipo é um sinônimo do iterador.

## <a name="pathempty"></a>path::empty

```cpp
bool empty() const noexcept;
```

Retorna mypath.empty().

## <a name="pathend"></a>path::end

```cpp
iterator end() const;
```

Retorna um iterador de fim de sequência de iterador de tipo.

## <a name="pathextension"></a>path::extension

```cpp
path extension() const;
```

Retorna o sufixo de filename() X, de modo que:

Se X == path(".") &#124;&#124; X == path("..") ou se X não contiver nenhum ponto, o sufixo será vazio.

Caso contrário, o sufixo começa com (e inclui) o ponto mais à direita.

## <a name="pathfilename"></a>path::filename

```cpp
path filename() const;
```

Retorna o componente do diretório raiz do myname, especificamente `empty()  path() : *--end()`. O componente pode estar vazio.

## <a name="pathgenericstring"></a>path::generic_string

```cpp
template <class Elem,
    class Traits = char_traits<Elem>,
    class Alloc = allocator<Elem>>
  basic_string<Elem, Traits, Alloc>
    generic_string(const Alloc& al = Alloc()) const;

string generic_string() const;
```

Retorna `this->string<Elem, Traits, Alloc>(al)` com (em Windows) qualquer barra invertida convertida em barra "/".

## <a name="pathgenericu16string"></a>path::generic_u16string

```cpp
u16string generic_u16string() const;
```

Retorna u16string() com (em Windows) qualquer barra invertida convertida em barra "/".

## <a name="pathgenericu32string"></a>path::generic_u32string

```cpp
u32string generic_u32string() const;
```

Retorna u32string() com (em Windows) qualquer barra invertida convertida em barra "/".

## <a name="pathgenericu8string"></a>path::generic_u8string

```cpp
string generic_u8string() const;
```

Retorna u8string() com (em Windows) qualquer barra invertida convertida em barra "/".

## <a name="pathgenericwstring"></a>path::generic_wstring

```cpp
wstring generic_wstring() const;
```

Retorna wstring() com (em Windows) qualquer barra invertida convertida em barra "/".

## <a name="pathhasextension"></a>path::has_extension

```cpp
bool has_extension() const;
```

Retorna !extension().empty().

## <a name="pathhasfilename"></a>path::has_filename

```cpp
bool has_filename() const;
```

Retorna !filename().empty().

## <a name="pathhasparentpath"></a>path::has_parent_path

```cpp
bool has_parent_path() const;
```

Retorna !parent_path().empty().

## <a name="pathhasrelativepath"></a>path::has_relative_path

```cpp
bool has_relative_path() const;
```

Retorna !relative_path().empty().

## <a name="pathhasrootdirectory"></a>path::has_root_directory

```cpp
bool has_root_directory() const;
```

Retorna !root_directory().empty().

## <a name="pathhasrootname"></a>path::has_root_name

```cpp
bool has_root_name() const;
```

Retorna !root_name().empty().

## <a name="pathhasrootpath"></a>path::has_root_path

```cpp
bool has_root_path() const;
```

Retorna !root_path().empty().

## <a name="pathhasstem"></a>path::has_stem

```cpp
bool has_stem() const;
```

Retorna !stem().empty().

## <a name="pathisabsolute"></a>path::is_absolute

```cpp
bool is_absolute() const;
```

Para Windows, a função retorna has_root_name() && has_root_directory(). Para Posix, a função retornará has_root_directory().

## <a name="pathisrelative"></a>path::is_relative

```cpp
bool is_relative() const;
```

Retorna !is_absolute().

## <a name="pathiterator"></a>path::iterator

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

A classe descreve um iterador bidirecional constante que designa os componentes do caminho do myname na sequência:

1. o nome raiz, se existir

1. o diretório raiz, se existir

1. os elementos restantes do diretório pai do caminho remanescente, se existirem, terminam com o nome do arquivo, se existir

Para pval, um objeto do tipo path:

1. path::iterator X = pval.begin() designa o primeiro elemento de caminho no nome do caminho, se existir.

1. X == pval.end() é verdadeiro quando X aponta para logo após o final da sequência de componentes.

3. *X retorna uma cadeia de caracteres que corresponde ao componente atual

1. ++X designa o próximo componente na sequência, se existir.

1. --X designa o componente anterior na sequência, se existir.

1. Alterar myname invalida todos os iteradores que designam elementos myname.

## <a name="pathmakepreferred"></a>path::make_preferred

```cpp
path& make_preferred();
```

A função membro converte cada separador em um preferred_separator conforme necessário.

## <a name="pathnative"></a>path::native

```cpp
const string_type& native() const noexcept;
```

Retorna myname.

## <a name="pathoperator"></a>path::operator=

```cpp
path& operator=(const path& right);
path& operator=(path&& right) noexcept;

template <class Source>
path& operator=(const Source& source);
```

O primeiro operador membro copia right.myname para myname. O segundo operador membro move right.myname para myname. O terceiro operador membro se comporta da mesma maneira que *this = path(source).

## <a name="pathoperator"></a>path::operator+=

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

As funções de membro se comportam da mesma maneira que as seguintes expressões correspondentes:

1. concat(right);

1. concat(path(str));

1. concat(ptr);

1. concat(string_type(1, elem));

1. concat(source);

1. concat(path(basic_string\<Elem>(1, elem)));

## <a name="pathoperator"></a>path::operator/=

```cpp
path& operator/=(const path& right);

template <class Source>
path& operator/=(const Source& source);
```

As funções de membro se comportam da mesma maneira que as seguintes expressões correspondentes:

1. append(right);

1. append(source);

## <a name="pathoperator-stringtype"></a>path::operator string_type

```cpp
operator string_type() const;
```

O operador membro retorna myname.

## <a name="pathparentpath"></a>path::parent_path

```cpp
path parent_path() const;
```

Retorna o componente de caminho pai de myname, especificamente o prefixo de myname após a remoção de filename().native() e qualquer separador de diretório imediatamente anterior. (Da mesma forma, se begin() != end(), isso representa a combinação de todos os elementos no intervalo [begin(), --end()) aplicando sucessivamente o operador/=.) O componente pode estar vazio.

## <a name="pathpath"></a>path::path

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

Todos os construtores criam myname de várias maneiras:

De path() é myname().

Para path(const path& right), é myname(right.myname).

Para path(path&& right), é myname(right.myname).

Para template\<class Source> path(const Source& source), é myname(source).

Para template\<class Source> path(const Source& source, const locale& loc), é myname(source), obtendo as facetas codecvt necessárias de loc.

Para template\<class InIt> path(InIt first, InIt last), é o myname(first, last).

Para template\<class InIt> path(InIt first, InIt last, const locale& loc), é myname(first, last), obtendo as facetas codecvt necessárias de loc.

## <a name="pathpreferredseparator"></a>path::preferred_separator

```cpp
#if _WIN32_C_LIB
static constexpr value_type preferred_separator == L'\\';
#else // assume Posix
static constexpr value_type preferred_separator == '/';
#endif // filesystem model now defined
```

O objeto constante fornece o caractere preferencial para separar os componentes do caminho, dependendo do sistema operacional do host. Observe que é igualmente permitido na maioria dos contextos no Windows usar L'/' em seu lugar.

## <a name="pathrelativepath"></a>path::relative_path

```cpp
path relative_path() const;
```

Retorna o componente de caminho relativo de myname, especificamente o sufixo de myname após remover root_path().native() e qualquer separador de diretório imediatamente posterior. O componente pode estar vazio.

## <a name="pathremovefilename"></a>path::remove_filename

```cpp
path& remove_filename();
```

## <a name="pathreplaceextension"></a>path::replace_extension

```cpp
path& replace_extension(const path& newext = path());
```

A função membro primeiro remove o sufixo extension().native() de myname. Se !newext.empty() && newext[0] != dot (em que dot é *path(".").c_str()), dot será anexado ao myname. Em seguida, newext é anexado a myname.

## <a name="pathreplacefilename"></a>path::replace_filename

```cpp
path& replace_filename(const path& pval);
```

A função membro executa:

```cpp
remove_filename();

*this /= pval;
return (*this);
```

## <a name="pathrootdirectory"></a>path::root_directory

```cpp
path root_directory() const;
```

Retorna o componente do diretório raiz do myname. O componente pode estar vazio.

## <a name="pathrootname"></a>path::root_name

```cpp
path root_name() const;
```

Retorna o componente de nome raiz do myname. O componente pode estar vazio.

## <a name="pathrootpath"></a>path::root_path

```cpp
path root_path() const;
```

Retorna o componente de caminho raiz do myname, especificamente root_name() / root_directory. O componente pode estar vazio.

## <a name="pathstem"></a>path::stem

```cpp
path stem() const;
```

Retorna o componente de tronco de myname, especificamente filename().native() com qualquer extension().native() à direita removida. O componente pode estar vazio.

## <a name="pathstring"></a>path::string

```cpp
template \<class Elem, class Traits = char_traits\<Elem>, class Alloc = allocator\<Elem>>
basic_string\<Elem, Traits, Alloc> string(const Alloc& al = Alloc()) const;
string string() const;
```

A primeira função membro (modelo) converte a sequência armazenada em mypath da mesma maneira que:

1. string() para string\<char, Traits, Alloc>()

1. wstring() para string\<wchar_t, Traits, Alloc>()

1. u16string() para string\<char16_t, Traits, Alloc>()

1. u32string() para string\<char32_t, Traits, Alloc>()

A segunda função membro converte a sequência armazenada em mypath na codificação preferida pelo sistema de host para uma sequência de caracteres armazenada em um objeto do tipo cadeia de caracteres.

## <a name="pathstringtype"></a>path::string_type

```cpp
typedef basic_string<value_type> string_type;
```

O tipo é um sinônimo de basic_string<value_type>.

## <a name="pathswap"></a>path::swap

```cpp
void swap(path& right) noexcept;
```

Executa swap(mypath, right.mypath).

## <a name="pathu16string"></a>path::u16string

```cpp
u16string u16string() const;
```

A função membro converte a sequência armazenada em mypath em UTF-16 e a retorna armazenada em um objeto do tipo u16string.

## <a name="pathu32string"></a>path::u32string

```cpp
u32string u32string() const;
```

A função membro converte a sequência armazenada em mypath em UTF-32 e a retorna armazenada em um objeto do tipo u32string.

## <a name="pathu8string"></a>path::u8string

```cpp
string u8string() const;
```

A função membro converte a sequência armazenada em mypath em UTF-8 e a retorna armazenada em um objeto do tipo u8string.

## <a name="pathvaluetype"></a>path::value_type

```cpp
#if _WIN32_C_LIB
typedef wchar_t value_type;
#else // assume Posix
typedef char value_type;
#endif // filesystem model now defined
```

O tipo descreve os elementos de caminho preferidos pelo sistema operacional do host.

## <a name="pathwstring"></a>path::wstring

```cpp
wstring wstring() const;
```

Converte a sequência armazenada em mypath na codificação preferida pelo sistema de host para uma sequência wchar_t e a retorna armazenada em um objeto do tipo wstring.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<filesystem >

**Namespace:** std::experimental::filesystem

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
