---
title: "Definições e declarações (C) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- export functions
ms.assetid: d150395a-89d4-4298-9ac4-08f84fe1261c
caps.latest.revision: 8
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
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 395595bdbc6b02d39a169cca6b6d967ee3f4a578
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="definitions-and-declarations-c"></a>Definições e declarações (C)
**Seção específica da Microsoft**  
  
 A interface da DLL refere-se a todos os itens (funções e dados) que sabidamente são exportados por algum programa no sistema; ou seja, todos os itens que são declarados como **dllimport** ou `dllexport`. Todas as declarações incluídas na interface da DLL devem especificar o atributo **dllimport** ou `dllexport`. No entanto, a definição pode especificar apenas o atributo `dllexport`. Por exemplo, a definição de função a seguir gera um erro de compilador:  
  
```  
#define DllImport   __declspec( dllimport )  
#define DllExport   __declspec( dllexport )  
  
DllImport int func()    /* Error; dllimport prohibited in */  
                        /* definition. */  
{  
   return 1;  
}  
```  
  
 Este código também gera um erro:  
  
```  
#define DllImport   __declspec( dllimport )  
#define DllExport   __declspec( dllexport )  
  
DllImport int i = 10;      /* Error; this is a definition. */  
```  
  
 No entanto, esta é uma sintaxe correta:  
  
```  
#define DllImport   __declspec( dllimport )  
#define DllExport   __declspec( dllexport )  
  
DllExport int i = 10;      /* Okay: this is an export definition. */  
```  
  
 O uso de `dllexport` implica uma definição, enquanto **dllimport** implica uma declaração. Você deve usar a palavra-chave `extern` com `dllexport` para forçar uma declaração; caso contrário, uma definição é implícita.  
  
```  
#define DllImport   __declspec( dllimport )  
#define DllExport   __declspec( dllexport )  
  
extern DllImport int k;   /* These are correct and imply */  
Dllimport int j;          /* a declaration. */      
```  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Funções de importação e exportação de DLL](../c-language/dll-import-and-export-functions.md)
