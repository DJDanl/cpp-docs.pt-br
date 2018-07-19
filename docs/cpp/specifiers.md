---
title: Especificadores de | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- declaration specifiers
- declarations, specifiers
- specifiers, in declarations
ms.assetid: 8b14e844-9880-4571-8779-28c8efe44633
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d437b70148fdaba4c8eb4d7aa855e7d75f6f2487
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38953739"
---
# <a name="specifiers"></a>Especificadores
Este tópico descreve o *decl-specifiers* componente (especificadores de declaração) de uma [declaração](declarations-and-definitions-cpp.md).  
  
 Os seguintes espaços reservados e palavras-chave são especificadores de declaração:  
  
 *especificador de classe de armazenamento*  
  
 *especificador de tipo*  
  
 *especificador de função*  
  
 [friend](../cpp/friend-cpp.md)  
  
 [typedef] ( [typedef](http://msdn.microsod) `(` *extended-decl-modifier-seq* `)`  
  
## <a name="remarks"></a>Comentários  
 O *decl-specifiers* parte de uma declaração é a sequência mais longa de *decl-specifiers* que pode ser utilizada para significar um nome de tipo, não incluindo o ponteiro ou modificadores de referência. O restante da declaração é a *declarador*, que inclui o nome apresentado.  
  
 A tabela a seguir lista quatro declarações e, em seguida, lista cada declaração *especificadores decl* e *declarador* componente separadamente.  
  
|Declaração|*Decl-specifiers*|`declarator`|  
|-----------------|------------------------|------------------|  
|`char *lpszAppName;`|**char**|`*lpszAppName`|  
|`typedef char * LPSTR;`|**char**|`*LPSTR`|  
|`const int func1();`|**Const int**|`func1`|  
|`volatile void *pvvObj;`|**void volátil**|`*pvvObj`|  
  
 Porque **assinados**, **unsigned**, **longo**, e **curto** implicam **int**, um  **TypeDef** nomeie a seguir um destas palavras-chave será considerado como um membro do *declarator-list,* não é do *decl-specifiers*.  
  
> [!NOTE]
>  Como um nome pode ser declarado novamente, sua interpretação está sujeita à declaração mais recente no escopo atual. A nova declaração pode afetar a forma como os nomes são interpretados pelo compilador, principalmente os nomes de `typedef`.  
  
## <a name="see-also"></a>Consulte também  
 [Declarações e definições](declarations-and-definitions-cpp.md)