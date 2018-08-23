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
ms.openlocfilehash: 8c1fb739d5e6206297e52fd9103cbba98c5eef01
ms.sourcegitcommit: 7f3df9ff0310a4716b8136ca20deba699ca86c6c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/21/2018
ms.locfileid: "42572244"
---
# <a name="specifiers"></a>Especificadores
Este tópico descreve o *decl-specifiers* componente (especificadores de declaração) de uma [declaração](declarations-and-definitions-cpp.md).  
  
 Os seguintes espaços reservados e palavras-chave são especificadores de declaração:  
  
 *especificador de classe de armazenamento*  
  
 *especificador de tipo*  
  
 *especificador de função*  
  
 [friend](friend-cpp.md)  
 
 [TypeDef](aliases-and-typedefs-cpp.md) `(` *extended-decl-modifier-seq* `)`  

 [declspec](declspec.md) `(` *extended-decl-modifier-seq* `)`  
  
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
>  Como um nome pode ser declarado novamente, sua interpretação está sujeita à declaração mais recente no escopo atual. Nova declaração pode afetar como nomes são interpretados pelo compilador, especialmente **typedef** nomes.  
  
## <a name="see-also"></a>Consulte também  
 [Declarações e definições](declarations-and-definitions-cpp.md)
