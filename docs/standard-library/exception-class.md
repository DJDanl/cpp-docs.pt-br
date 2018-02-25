---
title: Classe exception | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- exception
dev_langs:
- C++
helpviewer_keywords:
- exception class
ms.assetid: 4f181f67-5888-4b50-89a6-745091ffb2fe
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 24aa11044218257b3471e2d65fe652ca32d39196
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="exception-class"></a>Classe exception
A classe atua como a classe base de todas as exceções lançadas por determinadas expressões e pela biblioteca padrão C++.  
  
## <a name="syntax"></a>Sintaxe  
```  
class exception {
   public:
   exception();
   exception(const char* const &message);
   exception(const char* const &message, int);
   exception(const exception &right);
   exception& operator=(const exception &right);
   virtual ~exception();
   virtual const char *what() const;
   };  
``` 
## <a name="remarks"></a>Comentários  
 Especificamente, essa classe base é a raiz das classes de exceção padrão definidas em [\<stdexcept>](../standard-library/stdexcept.md). O valor da cadeia de caracteres C retornado por `what` é deixado como não especificado pelo construtor padrão, mas pode ser definido por construtores para determinadas classes derivadas como uma cadeia de caracteres C definida pela implementação. Nenhuma das funções de membro lança exceções.  
  
 O parâmetro `int` permite que você especifique que a memória não deve ser alocada. O valor de `int` é ignorado.  
  
> [!NOTE]
>  Os construtores `exception(const char* const &message)` e `exception(const char* const &message, int)` são extensões da Microsoft à biblioteca padrão C++.  
  
## <a name="example"></a>Exemplo  
 Para obter exemplos de uso das classes de exceção padrão que herdam da classe `exception`, consulte uma das classes definidas em [\<stdexcept>](../standard-library/stdexcept.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<exception>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)



