---
title: Ferramentas de vinculador LNK1301 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1301
dev_langs:
- C++
helpviewer_keywords:
- LNK1301
ms.assetid: 760da428-7182-4b25-b20a-de90d4b9a9cd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0b4e298ad3815c741ff6c901ac39bf7838ed135d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="linker-tools-error-lnk1301"></a>Erro das Ferramentas de Vinculador LNK1301
Módulos LTCG clr encontrados, incompatíveis com /LTCG:parameter  
  
 Um módulo compilado com /GL e /clr foi passado para o vinculador junto com uma das otimizações guiadas por perfil /LTCG parâmetros (PGO).  
  
 Otimizações guiadas por perfil não têm suporte para módulos /clr.  
  
 Para obter mais informações, consulte:  
  
-   [/GL (otimização do programa completo)](../../build/reference/gl-whole-program-optimization.md)  
  
-   [/LTCG (geração de código do tempo de vinculação)](../../build/reference/ltcg-link-time-code-generation.md)  
  
-   [/clr (compilação do Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md)  
  
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