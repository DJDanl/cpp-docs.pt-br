---
title: Erro fatal C1189 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1189
dev_langs:
- C++
helpviewer_keywords:
- C1189
ms.assetid: 2e5c8a78-edd4-411c-b619-558a96be148a
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 6e8d3c9ff44a436688accfe267141390d23c0eb5
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="fatal-error-c1189"></a>Erro fatal C1189
\#Erro: mensagem de erro fornecido pelo usuário  
  
 C1189 é gerado pelo `#error` diretiva. O desenvolvedor que códigos de diretiva especifica o texto da mensagem de erro. Para obter mais informações, consulte [#error diretiva (C/C++)](../../preprocessor/hash-error-directive-c-cpp.md).  
  
 O exemplo a seguir gera C1189. No exemplo, o desenvolvedor emite uma mensagem de erro personalizada porque o `_WIN32` identificador não está definido:  
  
```  
// C1189.cpp  
#undef _WIN32  
#if !defined(_WIN32)  
#error _WIN32 must be defined   // C1189  
#endif  
```  
  
 Você também poderá ver esse erro se você criar um projeto de ATL usando o **/ robusto** opção de compilador MIDL. Use o **/ robusto** switch para compilar apenas [!INCLUDE[win2kfamily](../../c-runtime-library/includes/win2kfamily_md.md)] e versões posteriores do Windows. Para corrigir esse erro, use um dos procedimentos a seguir:  
  
-   Altere essa linha no arquivo dlldatax.c:  
  
```  
#define _WIN32_WINNT 0x0400   // for WinNT 4.0 or Windows 95 with DCOM  
```  
  
 para:  
  
```  
#define _WIN32_WINNT 0x0500   // for WinNT 4.0 or Windows 95 with DCOM  
```  
  
-   Use o **avançado** página de propriedades no **MIDL** pasta da página de propriedade para remover o **/ robusto** alternar e, em seguida, especifique o **/no_robust** comutador. Para obter mais informações, consulte [páginas de propriedade MIDL: avançado](../../ide/midl-property-pages-advanced.md).  
  
## <a name="see-also"></a>Consulte também  
 [Diretiva #define (C/C++)](../../preprocessor/hash-define-directive-c-cpp.md)
