---
title: Classe path| Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- filesystem/std::experimental::filesystem::path
dev_langs:
- C++
ms.assetid: 8a1227ca-aeb2-4e0e-84aa-86e34e4f4fe8
caps.latest.revision: 14
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: acc0ecd4edaf1e58977dcbdeb483d497a72bc4c8
ms.openlocfilehash: b6f1fb2eacdc12857978d03ccbd98ee5da3047e5
ms.lasthandoff: 02/25/2017

---
# <a name="path-class"></a>Classe path
A classe **path** armazena um objeto do tipo string\_type, chamado myname aqui para fins de explicação, adequada para uso como um nome de caminho. string\_type é um sinônimo de basic\_string\<value_type>, em que value\_type é um sinônimo para char em Windows ou wchar_t em Posix.  
  
 Para obter mais informações e exemplos de código, consulte [Navegação do Sistema de Arquivos (C++)](../standard-library/file-system-navigation.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class path;  
```  
  
## <a name="pathappend"></a>path::append  
  
```  
template <class Source>  
path& append(const Source& source);  
   
template <class InIt>  
path& append(InIt first, InIt last);
```  
  
 As funções de membro acrescentam a sequência especificada ao mypath, convertido e inserindo um preferred_separator conforme necessário.  
  
## <a name="pathassign"></a>path::assign  
  
```  
template <class Source>  
path& assign(const Source& source);  
  
template <class InIt>  
path& assign(InIt first, InIt last);
```  
  
 As funções de membro substituem mypath com a sequência especificada, convertido conforme necessário.  
  
## <a name="pathbegin"></a>path::begin  
  
```  
iterator begin() const;
```  
  
 Retorna um path::iterator designando o primeiro elemento de caminho no nome do caminho, se existir.  
  
## <a name="pathcstr"></a>path::c_str  
  
```  
const value_type& *c_str() const noexcept;  
```  
  
 Retorna um ponteiro para o primeiro caractere em mypath.  
  
## <a name="pathclear"></a>path::clear  
  
```  
void clear() noexcept;  
```  
  
 A função membro executa mypath.clear()  
  
## <a name="pathcompare"></a>path::compare  
  
```  
int compare(const path& pval) const noexcept;  
int compare(const string_type& str) const;
int compare(const value_type *ptr) const;
```  
  
 A primeira função retorna mypath.compare(pval.native()). A segunda função retorna mypath.compare(str). A terceira função retorna mypath.compare(ptr).  
  
## <a name="pathconcat"></a>path::concat  
  
```  
template <class Source>  
path& concat(const Source& source);  
  
template <class InIt>  
path& concat(InIt first, InIt last);
```  
  
 As funções de membro acrescentam a sequência especificada ao mypath, convertido (mas não inserindo um separador) conforme necessário.  
  
## <a name="pathconstiterator"></a>path::const_iterator  
  
```  
typedef iterator const_iterator;  
```  
  
 O tipo é um sinônimo do iterador.  
  
## <a name="pathempty"></a>path::empty  
  
```  
bool empty() const noexcept;  
```  
  
 Retorna mypath.empty().  
  
## <a name="pathend"></a>path::end  
  
```  
iterator end() const;
```  
  
 Retorna um iterador de fim de sequência de iterador de tipo.  
  
## <a name="pathextension"></a>path::extension  
  
```  
path extension() const;
```  
  
 Retorna o sufixo de filename() X, de modo que:  
  
 Se X == path(".") &#124;&#124; X == path("..") ou se X não contiver nenhum ponto, o sufixo será vazio.  
  
 Caso contrário, o sufixo começa com (e inclui) o ponto mais à direita.  
  
## <a name="pathfilename"></a>path::filename  
  
```  
path filename() const;
```  
  
 Retorna o componente do diretório raiz do myname, especificamente `empty()  path() : *--end()`. O componente pode estar vazio.  
  
## <a name="pathgenericstring"></a>path::generic_string  
  
```  
template <class Elem,  
    class Traits = char_traits<Elem>,  
    class Alloc = allocator<Elem>>  
  basic_string<Elem, Traits, Alloc>  
    generic_string(const Alloc& al = Alloc()) const;
  
string generic_string() const;
```  
  
 Retorna `this->string<Elem, Traits, Alloc>(al)` com (em Windows) qualquer barra invertida convertida em barra "/".  
  
## <a name="pathgenericu16string"></a>path::generic_u16string  
  
```  
u16string generic_u16string() const;
```  
  
 Retorna u16string() com (em Windows) qualquer barra invertida convertida em barra "/".  
  
## <a name="pathgenericu32string"></a>path::generic_u32string  
  
```  
u32string generic_u32string() const;
```  
  
 Retorna u32string() com (em Windows) qualquer barra invertida convertida em barra "/".  
  
## <a name="pathgenericu8string"></a>path::generic_u8string  
  
```  
string generic_u8string() const;
```  
  
 Retorna u8string() com (em Windows) qualquer barra invertida convertida em barra "/".  
  
## <a name="pathgenericwstring"></a>path::generic_wstring  
  
```  
wstring generic_wstring() const;
```  
  
 Retorna wstring() com (em Windows) qualquer barra invertida convertida em barra "/".  
  
## <a name="pathhasextension"></a>path::has_extension  
  
```  
bool has_extension() const;
```  
  
 Retorna !extension().empty().  
  
## <a name="pathhasfilename"></a>path::has_filename  
  
```  
bool has_filename() const;
```  
  
 Retorna !filename().empty().  
  
## <a name="pathhasparentpath"></a>path::has_parent_path  
  
```  
bool has_parent_path() const;
```  
  
 Retorna !parent_path().empty().  
  
## <a name="pathhasrelativepath"></a>path::has_relative_path  
  
```  
bool has_relative_path() const;
```  
  
 Retorna !relative_path().empty().  
  
## <a name="pathhasrootdirectory"></a>path::has_root_directory  
  
```  
bool has_root_directory() const;
```  
  
 Retorna !root_directory().empty().  
  
## <a name="pathhasrootname"></a>path::has_root_name  
  
```  
bool has_root_name() const;
```  
  
 Retorna !root_name().empty().  
  
## <a name="pathhasrootpath"></a>path::has_root_path  
  
```  
bool has_root_path() const;
```  
  
 Retorna !root_path().empty().  
  
## <a name="pathhasstem"></a>path::has_stem  
  
```  
bool has_stem() const;
```  
  
 Retorna !stem().empty().  
  
## <a name="pathisabsolute"></a>path::is_absolute  
  
```  
bool is_absolute() const;
```  
  
 Para Windows, a função retorna has_root_name() && has_root_directory(). Para Posix, a função retornará has_root_directory().  
  
## <a name="pathisrelative"></a>path::is_relative  
  
```  
bool is_relative() const;
```  
  
 Retorna !is_absolute().  
  
## <a name="pathiterator"></a>path::iterator  
  
```  
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
  
1.  o nome raiz, se existir  
  
2.  o diretório raiz, se existir  
  
3.  os elementos restantes do diretório pai do caminho remanescente, se existirem, terminam com o nome do arquivo, se existir    
  
 Para pval, um objeto do tipo path:  
  
1.  path::iterator X = pval.begin() designa o primeiro elemento de caminho no nome do caminho, se existir.  
  
2.  X == pval.end() é verdadeiro quando X aponta para logo após o final da sequência de componentes.  
  
3. *X retorna uma cadeia de caracteres que corresponde ao componente atual  
  
4.  ++X designa o próximo componente na sequência, se existir.  
  
5.  --X designa o componente anterior na sequência, se existir.  
  
6.  Alterar myname invalida todos os iteradores que designam elementos myname.  
  
## <a name="pathmakepreferred"></a>path::make_preferred  
  
```  
path& make_preferred();
```  
  
 A função membro converte cada separador em um preferred_separator conforme necessário.  
  
## <a name="pathnative"></a>path::native  
  
```  
const string_type& native() const noexcept;  
```  
  
 Retorna myname.  
  
## <a name="pathoperator"></a>path::operator=  
  
```  
path& operator=(const path& right);
path& operator=(path&& right) noexcept;  
  
template <class Source>  
path& operator=(const Source& source);
```  
  
 O primeiro operador membro copia right.myname para myname. O segundo operador membro move right.myname para myname. O terceiro operador membro se comporta da mesma maneira que *this = path(source).  
  
## <a name="pathoperator"></a>path::operator+=  
  
```  
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
  
1.  concat(right);  
  
2.  concat(path(str));  
  
3.  concat(ptr);  
  
4.  concat(string_type(1, elem));  
  
5.  concat(source);  
  
6.  concat(path(basic_string\<Elem>(1, elem)));  
  
## <a name="pathoperator"></a>path::operator/=  
  
```  
path& operator/=(const path& right);  
  
template <class Source>  
path& operator/=(const Source& source);
```  
  
 As funções de membro se comportam da mesma maneira que as seguintes expressões correspondentes:  
  
1.  append(right);  
  
2.  append(source);  
  
## <a name="pathoperator-stringtype"></a>path::operator string_type  
  
```  
operator string_type() const;
```  
  
 O operador membro retorna myname.  
  
## <a name="pathparentpath"></a>path::parent_path  
  
```  
path parent_path() const;
```  
  
 Retorna o componente de caminho pai de myname, especificamente o prefixo de myname após a remoção de filename().native() e qualquer separador de diretório imediatamente anterior. (Da mesma forma, se begin() != end(), isso representa a combinação de todos os elementos no intervalo [begin(), --end()) aplicando sucessivamente o operador/=.) O componente pode estar vazio.  
  
## <a name="pathpath"></a>path::path  
  
```  
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
  
```  
#if _WIN32_C_LIB  
static constexpr value_type preferred_separator == L'\\';  
#else // assume Posix  
static constexpr value_type preferred_separator == '/';  
#endif // filesystem model now defined  
```  
  
 O objeto constante fornece o caractere preferencial para separar os componentes do caminho, dependendo do sistema operacional do host. Observe que é igualmente permitido na maioria dos contextos no Windows usar L'/' em seu lugar.  
  
## <a name="pathrelativepath"></a>path::relative_path  
  
```  
path relative_path() const;
```  
  
 Retorna o componente de caminho relativo de myname, especificamente o sufixo de myname após remover root_path().native() e qualquer separador de diretório imediatamente posterior. O componente pode estar vazio.  
  
## <a name="pathremovefilename"></a>path::remove_filename  
  
```  
path& remove_filename();
```  
  
## <a name="pathreplaceextension"></a>path::replace_extension  
  
```  
path& replace_extension(const path& newext = path());
```  
  
 A função membro primeiro remove o sufixo extension().native() de myname. Se !newext.empty() && newext[0] != dot (em que dot é *path(".").c_str()), dot será anexado ao myname. Em seguida, newext é anexado a myname.  
  
## <a name="pathreplacefilename"></a>path::replace_filename  
  
```  
path& replace_filename(const path& pval);
```  
  
 A função membro executa:  
  
```cpp  
remove_filename();

*this /= pval;  
return (*this);
```  
  
## <a name="pathrootdirectory"></a>path::root_directory  
  
```  
path root_directory() const;
```  
  
 Retorna o componente do diretório raiz do myname. O componente pode estar vazio.  
  
## <a name="pathrootname"></a>path::root_name  
  
```  
path root_name() const;
```  
  
 Retorna o componente de nome raiz do myname. O componente pode estar vazio.  
  
## <a name="pathrootpath"></a>path::root_path  
  
```  
path root_path() const;
```  
  
 Retorna o componente de caminho raiz do myname, especificamente root_name() / root_directory. O componente pode estar vazio.  
  
## <a name="pathstem"></a>path::stem  
  
```  
path stem() const;
```  
  
 Retorna o componente de tronco de myname, especificamente filename().native() com qualquer extension().native() à direita removida. O componente pode estar vazio.  
  
## <a name="pathstring"></a>path::string  
  
```  
template <class Elem, class Traits = char_traits<Elem>, class Alloc = allocator<Elem>>  
basic_string<Elem, Traits, Alloc> string(const Alloc& al = Alloc()) const; 
string string() const;
```  
  
 A primeira função membro (modelo) converte a sequência armazenada em mypath da mesma maneira que:  
  
1.  string() para string\<char, Traits, Alloc>()  
  
2.  wstring() para string\<wchar_t, Traits, Alloc>()  
  
3.  u16string() para string\<char16_t, Traits, Alloc>()  
  
4.  u32string() para string\<char32_t, Traits, Alloc>()  
  
 A segunda função membro converte a sequência armazenada em mypath na codificação preferida pelo sistema de host para uma sequência de caracteres armazenada em um objeto do tipo cadeia de caracteres.  
  
## <a name="pathstringtype"></a>path::string_type  
  
```  
typedef basic_string<value_type> string_type;  
```  
  
 O tipo é um sinônimo de basic_string<value_type>.  
  
## <a name="pathswap"></a>path::swap  
  
```  
void swap(path& right) noexcept;  
```  
  
 Executa swap(mypath, right.mypath).  
  
## <a name="pathu16string"></a>path::u16string  
  
```  
u16string u16string() const;
```  
  
 A função membro converte a sequência armazenada em mypath em UTF-16 e a retorna armazenada em um objeto do tipo u16string.  
  
## <a name="pathu32string"></a>path::u32string  
  
```  
u32string u32string() const;
```  
  
 A função membro converte a sequência armazenada em mypath em UTF-32 e a retorna armazenada em um objeto do tipo u32string.  
  
## <a name="pathu8string"></a>path::u8string  
  
```  
string u8string() const;
```  
  
 A função membro converte a sequência armazenada em mypath em UTF-8 e a retorna armazenada em um objeto do tipo u8string.  
  
## <a name="pathvaluetype"></a>path::value_type  
  
```  
#if _WIN32_C_LIB  
typedef wchar_t value_type;  
#else // assume Posix  
typedef char value_type;  
#endif // filesystem model now defined  
```  
  
 O tipo descreve os elementos de caminho preferidos pelo sistema operacional do host.  
  
## <a name="pathwstring"></a>path::wstring  
  
```  
wstring wstring() const;
```  
  
 Converte a sequência armazenada em mypath na codificação preferida pelo sistema de host para uma sequência wchar_t e a retorna armazenada em um objeto do tipo wstring.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** filesystem  
  
 **Namespace:** std::experimental::filesystem
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)


