---
title: Ferramentas de vinculador LNK1301 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1301
dev_langs:
- C++
helpviewer_keywords:
- LNK1301
ms.assetid: 760da428-7182-4b25-b20a-de90d4b9a9cd
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: cfcdb90b967ce5f0e9eda8dded9b93db5bdcc268
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk1301"></a>Erro das Ferramentas de Vinculador LNK1301
Módulos LTCG clr encontrados, incompatíveis com /LTCG:parameter  
  
 Um módulo compilado com /GL e /clr foi passado para o vinculador junto com uma das otimizações guiadas por perfil /LTCG parâmetros (PGO).  
  
 Otimizações guiadas por perfil não têm suporte para módulos /clr.  
  
 Para obter mais informações, consulte:  
  
-   [/GL (otimização de programa inteiro)](../../build/reference/gl-whole-program-optimization.md)  
  
-   [/LTCG (geração de código para Link-time)](../../build/reference/ltcg-link-time-code-generation.md)  
  
-   [/CLR (common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md)  
  
-   [Otimizações guiadas por perfil](../../build/reference/profile-guided-optimizations.md)  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Não compile com /clr ou não vincular com um dos parâmetros para /LTCG PGO.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera LNK1301:  
  
```  
// LNK1301.cpp  
// compile with: /clr /GL /link /LTCG:PGI LNK1301.obj  
// LNK1301 expected  
class MyClass {  
public:  
   int i;  
};  
```