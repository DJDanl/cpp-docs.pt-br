---
title: Classe directory_entry | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- filesystem/std::experimental::filesystem::directory_entry
- FILESYSTEM/std::experimental::filesystem::directory_entry::operator const std::experimental::filesystem::path &
- FILESYSTEM/std::experimental::filesystem::directory_entry::directory_entry
- FILESYSTEM/std::experimental::filesystem::directory_entry::operator=
- FILESYSTEM/std::experimental::filesystem::directory_entry::assign
- FILESYSTEM/std::experimental::filesystem::directory_entry::replace_filename
- FILESYSTEM/std::experimental::filesystem::directory_entry::path
- FILESYSTEM/std::experimental::filesystem::directory_entry::status
- FILESYSTEM/std::experimental::filesystem::directory_entry::symlink_status
- FILESYSTEM/std::experimental::filesystem::directory_entry::operator<
- FILESYSTEM/std::experimental::filesystem::directory_entry::operator==
- FILESYSTEM/std::experimental::filesystem::directory_entry::operator!=
- FILESYSTEM/std::experimental::filesystem::directory_entry::operator<=
- FILESYSTEM/std::experimental::filesystem::directory_entry::operator>
- FILESYSTEM/std::experimental::filesystem::directory_entry::operator>=
dev_langs:
- C++
ms.assetid: 1827c67b-4137-4548-adb0-f955f7acaf08
caps.latest.revision: 17
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
ms.sourcegitcommit: 66798adc96121837b4ac2dd238b9887d3c5b7eef
ms.openlocfilehash: 0bd6b73c99eccffc7661cc4b43f97ab46890c5ee
ms.contentlocale: pt-br
ms.lasthandoff: 04/29/2017

---
# <a name="directoryentry-class"></a>Classe directory_entry
Descreve um objeto que é retornado por `*X`, em que *X* é um [directory_iterator](../standard-library/directory-iterator-class.md) ou um [recursive_directory_iterator](../standard-library/recursive-directory-iterator-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class directory_entry;  
```  
  
## <a name="remarks"></a>Comentários  
 A classe armazena um objeto do tipo [path](../standard-library/path-class.md). O `path` armazenado pode ser uma instância da [Classe path](../standard-library/path-class.md) ou de um tipo derivado de `path`. Ele também armazena dois valores [file_type](../standard-library/filesystem-enumerations.md#file_type): um que representa o que é conhecido sobre o status do nome do arquivo armazenado e outro que representa o que é conhecido sobre o status do link simbólico do nome do arquivo.  
  
 Para obter mais informações e exemplos de código, consulte [Navegação do Sistema de Arquivos (C++)](../standard-library/file-system-navigation.md).  
  
## <a name="assign"></a>assign  
  
```  
void assign(const std::experimental::filesystem::path& pval,  
    file_status stat_arg = file_status(),  
    file_status symstat_arg = file_status());
```  
  
 A função de membro atribui pval a mypath, stat a mystat e symstat a mysymstat.  
  
## <a name="directoryentry"></a>directory_entry  
  
```  
directory_entry() = default;  
directory_entry(const directory_entry&) = default;  
directory_entry(directory_entry&&) noexcept = default;  
explicit directory_entry(const std::experimental::filesystem::path& pval,  
    file_status stat_arg = file_status(),  
    file_status symstat_arg = file_status());
```  
  
 Os construtores usados como padrão se comportam como esperado. O quarto construtor inicializa mypath em pval, mystat em stat_arg e mysymstat em symstat_arg.  
  
## <a name="operator"></a>operator!=  
  
```  
bool operator!=(const directory_entry& right) const noexcept;  
```  
  
 A função de membro retorna !(*this == right).  
  
## <a name="operator"></a>operator=  
  
```  
directory_entry& operator=(const directory_entry&) = default;  
directory_entry& operator=(directory_entry&&) noexcept = default;  
```  
  
 Os operadores de atribuição de membro usados como padrão se comportam como esperado.  
  
## <a name="operator"></a>operator==  
  
```  
bool operator==(const directory_entry& right) const noexcept;  
```  
  
 A função de membro retorna mypath == right.mypath.  
  
## <a name="operator"></a>operador <  
  
```  
 
bool operator<(const directory_entry& right) const noexcept;  
```  
  
 A função de membro retorna mypath < right.mypath.  
  
## <a name="operator"></a>Operador <=  
  
```  
bool operator<=(const directory_entry& right) const noexcept;  
```  
  
 A função de membro retorna !(right \< *this).  
  
## <a name="operator"></a>Operador >  
  
```  
bool operator>(const directory_entry& right) const noexcept;  
```  
  
 A função de membro retorna right \< *this.  
  
## <a name="operator"></a>Operador >=  
  
```  
bool operator>=(const directory_entry& right) const noexcept;  
```  
  
 A função de membro retorna !(*this < right).  
  
## <a name="operator-const-pathtype"></a>operator const path_type&  
  
``` 
 operator const std::experimental::filesystem::path&() const; 
```  
  
 O operador de membro retorna mypath.  
  
## <a name="path"></a>path  
  
```  
const std::experimental::filesystem::path& path() const noexcept;  
```  
  
 A função de membro retorna mypath.  
  
## <a name="replacefilename"></a>replace_filename  
  
```  
void replace_filename(
    const std::experimental::filesystem::path& pval,  
    file_status stat_arg = file_status(),  
    file_status symstat_arg = file_status());
```  
  
 A função de membro substitui mypath por mypath.parent_path() / pval, mystat por stat_arg e mysymstat por symstat_arg  
  
## <a name="status"></a>status  
  
```  
file_status status() const; 
file_status status(error_code& ec) const noexcept;  
```  
  
 Ambas as funções de membro retornam mystat, possivelmente, primeiro alterado da seguinte maneira:  
  
1.  Se for status_known(mystat), não realizará nenhuma ação.  
  
2.  Caso contrário, se for !status_known(mysymstat) && !is_symlink(mysymstat), será mystat = mysymstat.  
  
## <a name="symlinkstatus"></a>symlink_status  
  
```  
file_status symlink_status() const; 
file_status symlink_status(error_code& ec) const noexcept;  
```  
  
 Ambas as funções de membro retornam mysymstat, possivelmente, primeiro alterado da seguinte maneira: se for status_known(mysymstat), nenhuma ação. Caso contrário, mysymstat = symlink_status(mypval).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<experimental/filesystem>  
  
 **Namespace:** std::experimental::filesystem  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\<filesystem>](../standard-library/filesystem.md)


