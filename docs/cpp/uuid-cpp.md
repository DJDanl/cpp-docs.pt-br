---
title: UUID (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- uuid_cpp
dev_langs:
- C++
helpviewer_keywords:
- __declspec keyword [C++], uuid
- uuid __declspec keyword
ms.assetid: 9d004621-09bc-4a8d-871b-648f5d5102d7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b143def4d758307c6ce6737281bdca1097aaa8c5
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="uuid-c"></a>uuid (C++)
**Seção específica da Microsoft**  
  
 O compilador anexa o GUID a uma classe ou estrutura declarada ou definida (somente definições completas de objeto COM) com o atributo de `uuid`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
__declspec( uuid("ComObjectGUID") ) declarator  
```  
  
## <a name="remarks"></a>Comentários  
 O atributo `uuid` usa uma cadeia de caracteres como seu argumento. Essa cadeia de caracteres de nomes de um GUID no formato de registro normal com ou sem o **{}** delimitadores. Por exemplo:  
  
```  
struct __declspec(uuid("00000000-0000-0000-c000-000000000046")) IUnknown;  
struct __declspec(uuid("{00020400-0000-0000-c000-000000000046}")) IDispatch;  
```  
  
 Esse atributo poderá ser aplicado a uma redeclaração. Isso permite que os cabeçalhos de sistema fornecer as definições das interfaces como **IUnknown**e a redeclaração em algum outro cabeçalho (como \<comdef.h >) para fornecer o GUID.  
  
 A palavra-chave [uuidof](../cpp/uuidof-operator.md) podem ser aplicados para recuperar a constante GUID anexado a um tipo definido pelo usuário.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [__declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)