---
title: Especificando o modelo de Threading para um projeto (ATL) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- _ATL_FREE_THREADED macro
- _ATL_APARTMENT_THREADED macro
- ATL, multithreading
- threading [ATL], models
- _ATL_SINGLE_THREADED macro
ms.assetid: 6b571078-521c-4f3e-9f08-482aa235a822
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 78d126564a736eafed2b51c0216b458844d4567a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="specifying-the-threading-model-for-a-project-atl"></a>Especificando o modelo de threading para um projeto (ATL)
As macros a seguir estão disponíveis para especificar o modelo de threading de um projeto de ATL:  
  
|Macro|Diretrizes para usar|  
|-----------|--------------------------|  
|ATL_SINGLE_THREADED|Defina se todos os seus objetos de usam o modelo de threading único.|  
|ATL_APARTMENT_THREADED|Defina se um ou mais dos seus objetos usam apartment threading.|  
|ATL_FREE_THREADED|Defina se um ou mais dos seus objetos de threading livre ou neutro de usar. Código existente pode conter referências a macro equivalente [_ATL_MULTI_THREADED](reference/compiler-options-macros.md#_atl_multi_threaded).|  
  
 Se você não definir qualquer uma dessas macros para o seu projeto, atl_free_threaded entrará em vigor.  
  
 As macros afetam o desempenho de tempo de execução da seguinte maneira:  
  
-   Especificando a macro que corresponde aos objetos em seu projeto pode melhorar o desempenho de tempo de execução.  
  
-   Especificar um nível mais alto da macro, por exemplo, se você especificar atl_apartment_threaded quando todos os objetos são single threaded, ligeiramente prejudicará o desempenho de tempo de execução.  
  
-   Especificar um nível mais baixo de macro, por exemplo, se você especificar atl_single_threaded quando um ou mais dos seus objetos usam apartamento de threading ou o thread livre, pode fazer com que o aplicativo falhar em tempo de execução.  
  
 Consulte [opções, o Assistente de objeto ATL simples](../atl/reference/options-atl-simple-object-wizard.md) para obter uma descrição de threading de modelos disponíveis para um objeto ATL.  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../atl/active-template-library-atl-concepts.md)

