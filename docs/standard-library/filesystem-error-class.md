---
title: "Classe filesystem_error | Microsoft Docs"
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
  - "filesystem/std::tr2::sys::filesystem_error"
dev_langs: 
  - "C++"
ms.assetid: c53aac27-c1fa-43e4-8967-48ea8ba1f172
caps.latest.revision: 13
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe filesystem_error
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe base para todas as exceções são geradas para relatar um estouro de baixo nível do sistema.  
  
## Sintaxe  
  
```  
class filesystem_error    : public system_error;  
```  
  
## Comentários  
 A classe serve como a classe base para todas as exceções geradas para relatar um erro em \< filesystem \> funções. Ele armazena um objeto de cadeia de caracteres de tipo, chamado mymesg aqui para fins de exposição. Ele também armazena dois objetos de caminho de tipo, chamado mypval1 e mypval2.  
  
## filesystem\_error::filesystem\_error  
  
```  
filesystem_error(const string& what_arg, error_code ec);  
filesystem_error(const string& what_arg,  
    const path& pval1, error_code ec);  
filesystem_error(const string& what_arg,  
    const path& pval1, const path& pval2, error_code ec);  
```  
  
 O primeiro construtor constrói sua mensagem de what\_arg e EC. O segundo construtor constrói sua mensagem de pval1, que ele armazena em mypval1. O terceiro construtor também constrói sua mensagem de pval1, que ele armazena em mypval1, em pval2, que ele armazena em mypval2.  
  
## filesystem\_error::path1  
  
```  
const path& path1() const noexcept;  
  
```  
  
 A função de membro retorna mypval1  
  
## filesystem\_error::path2  
  
```  
const path& path2() const noexcept;  
  
```  
  
 A função de membro retorna mypval2  
  
## filesystem\_error::What  
  
```  
const char *what() const noexcept;  
```  
  
 A função de membro retorna um ponteiro para um NTBS, preferencialmente composta de runtime\_error::what\(\), system\_error::what\(\), mymesg, mypval1.native\_string\(\) e mypval2.native\_string\(\).  
  
## Requisitos  
 **Cabeçalho:** sistema de arquivos  
  
 **Namespace:** std::tr2::sys  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Classe system\_error](../standard-library/system-error-class.md)   
 [\< filesystem \>](../Topic/%3Cfilesystem%3E.md)   
 [\<exception\>](../standard-library/exception.md)