---
title: Especificando o modelo de threading para um projeto (ATL)
ms.date: 11/04/2016
helpviewer_keywords:
- _ATL_FREE_THREADED macro
- _ATL_APARTMENT_THREADED macro
- ATL, multithreading
- threading [ATL], models
- _ATL_SINGLE_THREADED macro
ms.assetid: 6b571078-521c-4f3e-9f08-482aa235a822
ms.openlocfilehash: 69c1c80bba0b09ce69e0b9b9b27296ef2508e60b
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57326056"
---
# <a name="specifying-the-threading-model-for-a-project-atl"></a>Especificando o modelo de threading para um projeto (ATL)

As macros a seguir estão disponíveis para especificar o modelo de threading de um projeto ATL:

|Macro|Diretrizes para usar|
|-----------|--------------------------|
|_ATL_SINGLE_THREADED|Defina se todos os seus objetos usam o modelo de threading único.|
|_ATL_APARTMENT_THREADED|Defina se um ou mais dos seus objetos usam apartamento de threading.|
|_ATL_FREE_THREADED|Defina se um ou mais dos seus objetos usam threading livre ou neutra. O código existente pode conter referências à macro equivalente [_ATL_MULTI_THREADED](reference/compiler-options-macros.md#_atl_multi_threaded).|

Se você não definir qualquer uma dessas macros para seu projeto, atl_free_threaded estará em vigor.

As macros de afetam o desempenho de tempo de execução da seguinte maneira:

- Especificando a macro que corresponde aos objetos em seu projeto pode melhorar o desempenho de tempo de execução.

- Especificar um nível mais alto da macro, por exemplo, se você especificar atl_apartment_threaded quando todos os seus objetos são single threaded, ligeiramente prejudicará o desempenho de tempo de execução.

- Especificar um nível inferior da macro, por exemplo, se você especificar atl_single_threaded quando um ou mais dos seus objetos usam apartment threading ou threading livre, pode fazer com que seu aplicativo falhe em tempo de execução.

Ver [opções, ATL Simple Object Wizard](../atl/reference/options-atl-simple-object-wizard.md) para obter uma descrição de threading de modelos disponíveis para um objeto ATL.

## <a name="see-also"></a>Consulte também

[Conceitos](../atl/active-template-library-atl-concepts.md)
