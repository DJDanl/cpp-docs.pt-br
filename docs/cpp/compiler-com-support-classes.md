---
title: Classes de suporte COM do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_raise_error
dev_langs:
- C++
helpviewer_keywords:
- cl.exe compiler, COM support
- COM, compiler support
ms.assetid: 6d800d9b-b902-4033-9639-740a30b06f88
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f4fe4e7c26d1b32f16d524407279e5e71534d00c
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="compiler-com-support-classes"></a>Classes de suporte COM do compilador
**Seção específica da Microsoft**  
  
 As classes padrão são usadas para dar suporte a alguns dos tipos COM. As classes são definidas no \<comdef.h > e os arquivos de cabeçalho gerados a partir da biblioteca de tipos.  
  
|Classe|Finalidade|  
|-----------|-------------|  
|[_bstr_t](../cpp/bstr-t-class.md)|Encapsula o tipo `BSTR` para fornecer operadores e métodos úteis.|  
|[_com_error](../cpp/com-error-class.md)|Define o objeto de erro gerado pelo [com_raise_error](../cpp/com-raise-error.md) na maioria das falhas.|  
|[_com_ptr_t](../cpp/com-ptr-t-class.md)|Encapsula os ponteiros de interface COM e automatiza as chamadas necessárias para `AddRef`, **versão**, e `QueryInterface`.|  
|[_variant_t](../cpp/variant-t-class.md)|Encapsula o **VARIANT** tipo para fornecer métodos e operadores útil.|  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Suporte COM do compilador](../cpp/compiler-com-support.md)   
 [Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)   
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)