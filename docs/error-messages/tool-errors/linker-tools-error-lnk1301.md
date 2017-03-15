---
title: Ferramentas de vinculador LNK1301 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1301
dev_langs:
- C++
helpviewer_keywords:
- LNK1301
ms.assetid: 760da428-7182-4b25-b20a-de90d4b9a9cd
caps.latest.revision: 6
author: corob-msft
ms.author: corob
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 3694841447a83f02821aa260cdfdceaf7bd2ec5b
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1301"></a>Erro das Ferramentas de Vinculador LNK1301
Módulos de clr /ltcg encontrados, incompatíveis com /LTCG:parameter  
  
 Um módulo compilado com /clr e /GL foi passado para o vinculador junto com uma das otimizações guiada por perfil /LTCG parâmetros (PGO).  
  
 Não há suporte para otimizações guiada por perfil para /clr módulos.  
  
 Para obter mais informações, consulte:  
  
-   [/GL (otimização de programa total)](../../build/reference/gl-whole-program-optimization.md)  
  
-   [/LTCG (geração de código para Link-time)](../../build/reference/ltcg-link-time-code-generation.md)  
  
-   [/CLR (common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md)  
  
-   [Otimizações guiadas por perfil](../../build/reference/profile-guided-optimizations.md)  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Não compilado com /clr ou não a ligação com um dos parâmetros para /LTCG PGO.  
  
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
