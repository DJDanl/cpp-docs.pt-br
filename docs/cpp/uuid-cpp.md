---
title: "uuid (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "uuid"
  - "uuid_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __declspec [C++], uuid"
  - "palavra-chave uuid __declspec"
ms.assetid: 9d004621-09bc-4a8d-871b-648f5d5102d7
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# uuid (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 O compilador anexa o GUID a uma classe ou estrutura declarada ou definida \(somente definições completas de objeto COM\) com o atributo de `uuid`.  
  
## Sintaxe  
  
```  
  
__declspec( uuid("  
ComObjectGUID  
") ) declarator  
```  
  
## Comentários  
 O atributo `uuid` usa uma cadeia de caracteres como seu argumento.  Essa cadeia de caracteres nomeia um GUID no formato normal do registro com ou sem os delimitadores **{ }**.  Por exemplo:  
  
```  
struct __declspec(uuid("00000000-0000-0000-c000-000000000046")) IUnknown;  
struct __declspec(uuid("{00020400-0000-0000-c000-000000000046}")) IDispatch;  
```  
  
 Esse atributo poderá ser aplicado a uma redeclaração.  Isso permite que os cabeçalhos do sistema forneçam as definições das interfaces, como **IUnknown**, e a redeclaração em algum outro cabeçalho \(como COMDEF.H\) para fornecer o GUID.  
  
 A palavra\-chave [\_\_uuidof](../cpp/uuidof-operator.md) pode ser aplicada para recuperar o GUID da constante anexado a um tipo definido pelo usuário.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [\_\_declspec](../cpp/declspec.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)