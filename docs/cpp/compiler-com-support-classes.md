---
title: Classes de suporte COM do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _com_raise_error
dev_langs:
- C++
helpviewer_keywords:
- cl.exe compiler, COM support
- COM, compiler support
ms.assetid: 6d800d9b-b902-4033-9639-740a30b06f88
caps.latest.revision: 6
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
ms.openlocfilehash: 48540910db97e7662eeaa7e8a7febf7e44df653b
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="compiler-com-support-classes"></a>Classes de suporte COM do compilador
**Seção específica da Microsoft**  
  
 As classes padrão são usadas para dar suporte a alguns dos tipos COM. As classes são definidas em comdef.h e nos arquivos de cabeçalho gerados a partir da biblioteca de tipos.  
  
|Classe|Finalidade|  
|-----------|-------------|  
|[bstr_t](../cpp/bstr-t-class.md)|Encapsula o tipo `BSTR` para fornecer operadores e métodos úteis.|  
|[com_error](../cpp/com-error-class.md)|Define o objeto de erro gerado pelo [com_raise_error](../cpp/com-raise-error.md) na maioria das falhas.|  
|[com_ptr_t](../cpp/com-ptr-t-class.md)|Encapsula os ponteiros de interface COM e automatiza as chamadas necessárias para `AddRef`, **versão**, e `QueryInterface`.|  
|[variant_t](../cpp/variant-t-class.md)|Encapsula o **VARIANT** tipo para fornecer métodos e operadores útil.|  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Suporte COM do compilador](../cpp/compiler-com-support.md)   
 [Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)   
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)
