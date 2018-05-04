---
title: Configurar um Link estático para o registrador de código (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- statically linking to ATL Registrar code
- linking [C++], to ATL Registrar code
ms.assetid: 835f5885-87a6-48fa-91e6-60988ee65538
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: dca93c8f0fcae578700a9d9970977179fbd142d3
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="setting-up-a-static-link-to-the-registrar-code-c-only"></a>Configurar um Link estático para o registrador de código (C++)
Os clientes do C++ podem criar um link estático para o código do registrador. Vinculação estática do analisador do registrador adiciona aproximadamente 5 mil para uma compilação de versão.  
  
 A maneira mais simples para configurar a vinculação estática pressupõe que você especificou [DECLARE_REGISTRY_RESOURCEID](reference/registry-macros.md#declare_registry_resourceid) na declaração do objeto. (Esta é a especificação do padrão usada pelo ATL)  
  
### <a name="to-create-a-static-link-using-declareregistryresourceid"></a>Para criar um link estático usando DECLARE_REGISTRY_RESOURCEID  
  
1.  Especifique [/D](../build/reference/d-preprocessor-definitions.md) `_ATL_STATIC_REGISTRY` em vez de /D **_ATL_DLL**.  
  
2.  Recompile.  
  
## <a name="see-also"></a>Consulte também  
 [Componente de registro (Registrar)](../atl/atl-registry-component-registrar.md)

