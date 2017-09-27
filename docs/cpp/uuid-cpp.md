---
title: UUID (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- uuid
- uuid_cpp
dev_langs:
- C++
helpviewer_keywords:
- __declspec keyword [C++], uuid
- uuid __declspec keyword
ms.assetid: 9d004621-09bc-4a8d-871b-648f5d5102d7
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
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
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 80975b751b6e167573a038e55042b3546821c68f
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="uuid-c"></a>uuid (C++)
**Seção específica da Microsoft**  
  
 O compilador anexa o GUID a uma classe ou estrutura declarada ou definida (somente definições completas de objeto COM) com o atributo de `uuid`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
__declspec( uuid("  
ComObjectGUID  
") ) declarator  
```  
  
## <a name="remarks"></a>Comentários  
 O atributo `uuid` usa uma cadeia de caracteres como seu argumento. Essa cadeia de caracteres de nomes de um GUID no formato de registro normal com ou sem o **{}** delimitadores. Por exemplo:  
  
```  
struct __declspec(uuid("00000000-0000-0000-c000-000000000046")) IUnknown;  
struct __declspec(uuid("{00020400-0000-0000-c000-000000000046}")) IDispatch;  
```  
  
 Esse atributo poderá ser aplicado a uma redeclaração. Isso permite que os cabeçalhos de sistema fornecer as definições das interfaces como **IUnknown**e a redeclaração em algum outro cabeçalho (como COMDEF. H) para fornecer o GUID.  
  
 A palavra-chave [uuidof](../cpp/uuidof-operator.md) podem ser aplicados para recuperar a constante GUID anexado a um tipo definido pelo usuário.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [declspec](../cpp/declspec.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)
