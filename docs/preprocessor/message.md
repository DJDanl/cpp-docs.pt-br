---
title: message | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- message_CPP
- vc-pragma.message
dev_langs:
- C++
helpviewer_keywords:
- message pragma
- pragmas, message
ms.assetid: 67414f25-ed47-4079-a5dc-21d9d1a39754
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: fb998ef084f259601478ea9614a2bd8dc3da0d68
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="message"></a>mensagem
Envia uma literal de cadeia de caracteres para a saída padrão sem terminar a compilação.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#pragma message( messagestring )  
```  
  
## <a name="remarks"></a>Comentários  
 Um uso típico de **mensagem** pragma é exibir mensagens informativas em tempo de compilação.  
  
 O *messagestring* parâmetro pode ser uma macro que se expande para uma cadeia de caracteres literal, e você pode concatenar essas macros com literais de cadeia de caracteres em qualquer combinação.  
  
 Se você usar uma macro predefinida no **mensagem** pragma, a macro deve retornar uma cadeia de caracteres, caso contrário, será necessário converter a saída da macro em uma cadeia de caracteres.  
  
 O fragmento de código a seguir usa o **mensagem** pragma para exibir mensagens durante a compilação:  
  
```  
// pragma_directives_message1.cpp  
// compile with: /LD  
#if _M_IX86 >= 500  
#pragma message("_M_IX86 >= 500")  
#endif  
  
#pragma message("")  
  
#pragma message( "Compiling " __FILE__ )   
#pragma message( "Last modified on " __TIMESTAMP__ )  
  
#pragma message("")  
  
// with line number  
#define STRING2(x) #x  
#define STRING(x) STRING2(x)  
  
#pragma message (__FILE__ "[" STRING(__LINE__) "]: test")  
  
#pragma message("")  
```  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)