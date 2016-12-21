---
title: "Classe directory_entry | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "filesystem/std::tr2::sys::directory_entry"
  - "FILESYSTEM/std::experimental::filesystem::v1::directory_entry::operator const std::experimental::filesystem::v1::path &"
  - "FILESYSTEM/std::experimental::filesystem::v1::directory_entry::directory_entry"
  - "std::experimental::filesystem::v1::directory_entry::directory_entry"
  - "FILESYSTEM/std::experimental::filesystem::v1::directory_entry::operator="
  - "std::experimental::filesystem::v1::directory_entry::operator="
  - "FILESYSTEM/std::experimental::filesystem::v1::directory_entry::assign"
  - "std::experimental::filesystem::v1::directory_entry::assign"
  - "FILESYSTEM/std::experimental::filesystem::v1::directory_entry::replace_filename"
  - "std::experimental::filesystem::v1::directory_entry::replace_filename"
  - "FILESYSTEM/std::experimental::filesystem::v1::directory_entry::path"
  - "std::experimental::filesystem::v1::directory_entry::path"
  - "FILESYSTEM/std::experimental::filesystem::v1::directory_entry::status"
  - "std::experimental::filesystem::v1::directory_entry::status"
  - "FILESYSTEM/std::experimental::filesystem::v1::directory_entry::symlink_status"
  - "std::experimental::filesystem::v1::directory_entry::symlink_status"
  - "FILESYSTEM/std::experimental::filesystem::v1::directory_entry::operator<"
  - "std::experimental::filesystem::v1::directory_entry::operator<"
  - "FILESYSTEM/std::experimental::filesystem::v1::directory_entry::operator=="
  - "std::experimental::filesystem::v1::directory_entry::operator=="
  - "FILESYSTEM/std::experimental::filesystem::v1::directory_entry::operator!="
  - "std::experimental::filesystem::v1::directory_entry::operator!="
  - "FILESYSTEM/std::experimental::filesystem::v1::directory_entry::operator<="
  - "std::experimental::filesystem::v1::directory_entry::operator<="
  - "FILESYSTEM/std::experimental::filesystem::v1::directory_entry::operator>"
  - "std::experimental::filesystem::v1::directory_entry::operator>"
  - "FILESYSTEM/std::experimental::filesystem::v1::directory_entry::operator>="
  - "std::experimental::filesystem::v1::directory_entry::operator>="
dev_langs: 
  - "C++"
ms.assetid: 1827c67b-4137-4548-adb0-f955f7acaf08
caps.latest.revision: 17
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe directory_entry
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Descreve um objeto que é retornado pelo `*X`, onde *X* é um [directory\_iterator](../Topic/directory_iterator%20Class.md) ou um [recursive\_directory\_iterator](../Topic/recursive_directory_iterator%20Class.md).  
  
## Sintaxe  
  
```  
class directory_entry;  
```  
  
## Comentários  
 A classe armazena um objeto do tipo [caminho de classe](../Topic/path%20Class%20\(C++%20Standard%20Template%20Library\).md).`path` pode ser um [caminho](../Topic/path%20Class%20\(C++%20Standard%20Template%20Library\).md) ou um tipo derivado de `path`. Ele também armazena dois [file\_type](../Topic/file_type%20Enumeration.md) valores; um que representa o que é conhecido sobre o status do nome do arquivo armazenado e outro que representa o conhecimento sobre o status do link simbólico do nome do arquivo.  
  
 Para obter mais informações e exemplos de código, consulte [Navegação no sistema de arquivos \(C\+\+\)](../standard-library/file-system-navigation.md).  
  
## atribuir  
  
```  
void assign(const PFX path& pval,  
    file_status stat_arg = file_status(),  
    file_status symstat_arg = file_status());  
```  
  
 A função de membro atribui pval mypath, stat para mystat e symstat para mysymstat.  
  
## directory\_entry  
  
```  
directory_entry() = default;  
directory_entry(const directory_entry&) = default;  
directory_entry(directory_entry&&) noexcept = default;  
explicit directory_entry(const PFX path& pval,  
    file_status stat_arg = file_status(),  
    file_status symstat_arg = file_status());  
```  
  
 Os construtores padrão se comportar conforme o esperado. O quarto construtor inicializa mypath para pval, mystat para stat\_arg e mysymstat para symstat\_arg.  
  
## operator\!\=  
  
```  
bool operator!=(const directory_entry& right) const noexcept;  
  
```  
  
 Retorna a função de membro\! \(\* isso \= \= direita\).  
  
## operator\=  
  
```  
directory_entry& operator=(const directory_entry&) = default;  
directory_entry& operator=(directory_entry&&) noexcept = default;  
  
```  
  
 Os operadores de atribuição de membro padrão se comportar conforme o esperado.  
  
## operator\=\=  
  
```  
bool operator==(const directory_entry& right) const noexcept;  
```  
  
 A função de membro retorna mypath \= \= right.mypath.  
  
## Operador \<  
  
```  
  
bool operator<(const directory_entry& right) const noexcept;  
  
```  
  
 A função de membro retorna mypath \< right.mypath.  
  
## Operador \<\=  
  
```  
bool operator<=(const directory_entry& right) const noexcept;  
```  
  
 Retorna a função de membro\! \(certo \< \* isso\).  
  
## Operador \>  
  
```  
bool operator>(const directory_entry& right) const noexcept;  
```  
  
 A função de membro retorna à direita \< \* isso.  
  
## Operador \>\=  
  
```  
bool operator>=(const directory_entry& right) const noexcept;  
  
```  
  
 Retorna a função de membro\! \(\* isso \< direita\).  
  
## operador const path\_type &  
  
```  
operator const path&() const; // retained  
```  
  
 O operador de membro retorna mypath.  
  
## demarcador  
  
```  
const PFX path& path() const noexcept;  
```  
  
 A função de membro retorna mypath.  
  
## replace\_filename  
  
```  
void replace_filename(const PFX path& pval,  
    file_status stat_arg = file_status(),  
    file_status symstat_arg = file_status());  
```  
  
 A função de membro substitui mypath com mypath.parent\_path\(\) \/ pval, mystat com stat\_arg e mysymstat com symstat\_arg  
  
## status  
  
```  
file_status status() const;  
file_status status(  
    error_code& ec) const noexcept;  
Otherwise, mystat = status(mypval).  
  
```  
  
 Ambas as funções de membro retornam mystat possivelmente primeiro alterada da seguinte maneira:  
  
1.  Se status\_known\(mystat\) não faça nada.  
  
2.  Caso contrário, se\! status\_known\(mysymstat\) & &\! is\_symlink\(mysymstat\) e mystat \= mysymstat.  
  
## symlink\_status  
  
```  
file_status symlink_status() const;  
file_status symlink_status(  
    error_code& ec) const noexcept;  
```  
  
 Ambas as funções de membro retornam mysymstat possivelmente primeiro alterada como segue: se status\_known\(mysymstat\) e não fazem nada. Caso contrário, mysymstat \= symlink\_status\(mypval\).  
  
## Requisitos  
 **Cabeçalho:** sistema de arquivos  
  
 **Namespace:** std::tr2::sys  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [\< filesystem \>](../Topic/%3Cfilesystem%3E.md)