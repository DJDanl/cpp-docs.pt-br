---
title: Classe filesystem_error | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- filesystem/std::experimental::filesystem::filesystem_error
dev_langs:
- C++
ms.assetid: c53aac27-c1fa-43e4-8967-48ea8ba1f172
caps.latest.revision: 13
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
ms.openlocfilehash: 87ae0515eba774f73ee0d4283a020ce27c3fbe6f
ms.contentlocale: pt-br
ms.lasthandoff: 04/19/2017

---
# <a name="filesystemerror-class"></a>Classe filesystem_error
Uma classe base para todas as exceções geradas para relatar um estouro de baixo nível no sistema.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class filesystem_error    : public system_error;  
```  
  
## <a name="remarks"></a>Comentários  
 A classe serve como a classe base para todas as exceções geradas para relatar um erro em funções \<filesystem >. Ela armazena um objeto do tipo cadeia de caracteres, chamado mymesg aqui para fins de exposição. Ela também armazena dois objetos do tipo caminho, chamados mypval1 e mypval2.  
  
## <a name="filesystemerrorfilesystemerror"></a>filesystem_error::filesystem_error  
  
```  
filesystem_error(const string& what_arg,
    error_code ec);

filesystem_error(const string& what_arg,  
    const path& pval1,
    error_code ec);

filesystem_error(const string& what_arg,  
    const path& pval1,
    const path& pval2,
    error_code ec);
```  
  
 O primeiro construtor constrói sua mensagem de what_arg e ec. O segundo construtor também constrói sua mensagem de pval1, que armazena em mypval1. O terceiro construtor também constrói sua mensagem de pval1, que armazena em mypval1, em de pval2, que armazena em mypval2.  
  
## <a name="filesystemerrorpath1"></a>filesystem_error::path1  
  
```  
const path& path1() const noexcept;  
```  
  
 A função membro retorna mypval1  
  
## <a name="filesystemerrorpath2"></a>filesystem_error::path2  
  
```  
const path& path2() const noexcept;  
```  
  
 A função membro retorna mypval2  
  
## <a name="filesystemerrorwhat"></a>filesystem_error::what  
  
```  
const char *what() const noexcept;  
```  
  
 A função membro retorna um ponteiro para um NTBS, preferencialmente composto por runtime_error::what(), system_error::what(), mymesg, mypval1.native_string() e mypval2.native_string().  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<filesystem >  
  
 **Namespace:** std::experimental::filesystem  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Classe system_error](../standard-library/system-error-class.md)   
 [\<filesystem>](../standard-library/filesystem.md)   
 [\<exception>](../standard-library/exception.md)


