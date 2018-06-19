---
title: Definições e declarações (C) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- export functions
ms.assetid: d150395a-89d4-4298-9ac4-08f84fe1261c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d44a98fee82e41252b27fa5a1605b04a15af9115
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32383479"
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