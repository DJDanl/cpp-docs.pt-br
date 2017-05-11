---
title: Classe recursive_directory_iterator | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- filesystem/std::tr2::sys::recursive_directory_iterator
dev_langs:
- C++
ms.assetid: 79a061bd-5b64-404c-97e8-749c888c2ced
caps.latest.revision: 15
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 4ecf60434799708acab4726a95380a2d3b9dbb3a
ms.openlocfilehash: 0d4325fbe8d4f336f4ca1ac6afe4ba5a96a7172d
ms.contentlocale: pt-br
ms.lasthandoff: 04/19/2017

---
# <a name="recursivedirectoryiterator-class"></a>Classe recursive_directory_iterator
descreve um iterador de entrada que sequencia pelos nomes de arquivo em um diretório, possivelmente em ordem decrescente em subdiretórios, recursivamente. Para um iterador X, a expressão *X é avaliada como um objeto da classe directory_entry que encapsula o nome de arquivo e tudo conhecido sobre seu status.  
  
 Para obter mais informações e exemplos de código, consulte [Navegação do Sistema de Arquivos (C++)](../standard-library/file-system-navigation.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class recursive_directory_iterator;  
```  
  
## <a name="remarks"></a>Comentários  
 A classe de modelo armazena:  
  
1.  um objeto do tipo stack<pair\<directory_iterator, path>>, chamado mystack aqui para fins de explicação, que representa o aninhamento de diretórios a ser sequenciado  
  
2.  um objeto do tipo directory_entry chamado myentry aqui, que representa o nome do arquivo atual na sequência de diretório  
  
3.  um objeto do tipo bool, chamado no_push aqui, que registra se o descendente recursivo em subdiretórios está desabilitado  
  
4.  um objeto do tipo directory_options, chamado myoptions aqui, que registra as opções estabelecidas na construção  
  
 Um objeto padrão construído do tipo recursive_directory_entry tem um iterador de fim de sequência em mystack.top().first e representa o iterador de fim de sequência. Por exemplo, considerando o diretório abc com entradas def (um diretório), def/ghi e jkl, o código:  
  
```  
for (recursive_directory_iterator next(path("abc")), end; next != end; ++next)  
    visit(next->path());
```  
  
 chamará visita com os argumentos `path("abc/def/ghi") and path("abc/jkl").`É possível qualificar o sequenciamento por meio de uma subárvore de diretório de duas maneiras:  
  
1.  Um diretório symlink será verificado somente se você construir um recursive_directory_iterator com um argumento directory_options cujo valor é directory_options::follow_directory_symlink.  
  
2.  Se você chamar disable_recursion_pending, então um diretório subsequente encontrado durante um incremento não será verificado recursivamente.  
  
## <a name="recursivedirectoryiteratordepth"></a>recursive_directory_iterator::depth  
  
```  
int depth() const;
```  
  
 Retorna mystack.size() - 1, portanto pval está na profundidade zero.  
  
## <a name="recursivedirectoryiteratordisablerecursionpending"></a>recursive_directory_iterator::disable_recursion_pending  
  
```  
void disable_recursion_pending();
```  
  
 A função de membro armazena true em no_push.  
  
## <a name="recursivedirectoryiteratoroperator"></a>recursive_directory_iterator::operator!=  
  
```  
bool operator!=(const recursive_directory_iterator& right) const;
```  
  
 O operador de membro retorna !(*this == right).  
  
## <a name="recursivedirectoryiteratoroperator"></a>recursive_directory_iterator::operator=  
  
```  
recursive_directory_iterator& operator=(const recursive_directory_iterator&) = default;  
recursive_directory_iterator& operator=(recursive_directory_iterator&&) noexcept = default;  
```  
  
 Os operadores de atribuição de membro usados como padrão se comportam como esperado.  
  
## <a name="recursivedirectoryiteratoroperator"></a>recursive_directory_iterator::operator==  
  
```  
bool operator==(const recursive_directory_iterator& right) const;
```  
  
 O operador de membro retornará verdadeiro somente se *this e right forem iteradores de fim de sequência ou ambos não forem iteradores de fim de sequência.  
  
## <a name="recursivedirectoryiteratoroperator"></a>recursive_directory_iterator::operator*  
  
```  
const directory_entry& operator*() const;
```  
  
 O operador de membro retorna myentry.  
  
## <a name="recursivedirectoryiteratoroperator-"></a>recursive_directory_iterator::operator->  
  
```  
const directory_entry * operator->() const;
```  
  
 Retorna &**this.  
  
## <a name="recursivedirectoryiteratoroperator"></a>recursive_directory_iterator::operator++  
  
```  
recursive_directory_iterator& operator++();

recursive_directory_iterator& operator++(int);
```  
  
 A primeira função de membro chama increment() e, em seguida, retorna *this. A segunda função de membro faz uma cópia do objeto, chama increment() e retorna a cópia.  
  
## <a name="recursivedirectoryiteratoroptions"></a>recursive_directory_iterator::options  
  
```  
directory_options options() const;
```  
  
 Retorna myoptions.  
  
## <a name="recursivedirectoryiteratorpop"></a>recursive_directory_iterator::pop  
  
```  
void pop();
```  
  
 Se depth() == 0, o objeto se torna um iterador de fim de sequência. Caso contrário, a função de membro termina a varredura do diretório atual (mais profundo) e retoma no próximo nível inferior.  
  
## <a name="recursivedirectoryiteratorrecursionpending"></a>recursive_directory_iterator::recursion_pending  
  
```  
bool recursion_pending() const;
```  
  
 Retorna !no_push.  
  
## <a name="recursivedirectoryiteratorrecursivedirectoryiterator"></a>recursive_directory_iterator::recursive_directory_iterator  
  
```  
recursive_directory_iterator() noexcept;  
explicit recursive_directory_iterator(const path& pval);

recursive_directory_iterator(const path& pval,  
    error_code& ec) noexcept;  
recursive_directory_iterator(const path& pval,  
    directory_options opts);

recursive_directory_iterator(const path& pval,  
    directory_options opts,  
    error_code& ec) noexcept;  
recursive_directory_iterator(const recursive_directory_iterator&) = default;  
recursive_directory_iterator(recursive_directory_iterator&&) noexcept = default;  
```  
  
 O primeiro construtor produz um iterador de fim de sequência. O segundo e o terceiro construtor armazenam no_push falso e directory_options::none em myoptions e tentam abrir e ler pval como um diretório. Se for bem-sucedido, eles inicializam mystack e myentry para designar o primeiro nome do arquivo não diretório na sequência aninhada; caso contrário, eles produzem um iterador de fim de sequência.  
  
 O quarto e o quinto construtores se comportam da mesma maneira que o segundo e terceiro, exceto que eles primeiro armazenam opts em myoptions. Os construtores usados como padrão se comportam como esperado.  
  
## <a name="recursivedirectoryiteratorincrement"></a>recursive_directory_iterator::increment  
  
```  
recursive_directory_iterator& increment(error_code& ec) noexcept;  
```  
  
 A função tenta avançar para o próximo nome de arquivo na sequência aninhada. Se tiver êxito, ela armazenará esse nome de arquivo em myentry; caso contrário, produzirá um iterador de fim de sequência.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<filesystem >  
  
 **Namespace:** std::tr2::sys  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<filesystem>](../standard-library/filesystem.md)   
 [Navegação no sistema de arquivos (C++)](../standard-library/file-system-navigation.md)


