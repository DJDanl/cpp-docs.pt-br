---
title: "Configurar um Link estático para o registrador de código (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- statically linking to ATL Registrar code
- linking [C++], to ATL Registrar code
ms.assetid: 835f5885-87a6-48fa-91e6-60988ee65538
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: b8eb77bc6f99ab6b7d8ca9d51f1a7a8549d8f0c9
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="setting-up-a-static-link-to-the-registrar-code-c-only"></a>Configurar um Link estático para o registrador de código (C++)
Os clientes do C++ podem criar um link estático para o código do registrador. Vinculação estática do analisador do registrador adiciona aproximadamente 5 mil para uma compilação de versão.  
  
 A maneira mais simples para configurar a vinculação estática pressupõe que você especificou [DECLARE_REGISTRY_RESOURCEID](reference/registry-macros.md#declare_registry_resourceid) na declaração do objeto. (Esta é a especificação do padrão usada pelo ATL)  
  
### <a name="to-create-a-static-link-using-declareregistryresourceid"></a>Para criar um link estático usando DECLARE_REGISTRY_RESOURCEID  
  
1.  Especifique [/D](../build/reference/d-preprocessor-definitions.md) `_ATL_STATIC_REGISTRY` em vez de /D**_ATL_DLL**.  
  
2.  Recompile.  
  
## <a name="see-also"></a>Consulte também  
 [Componente de registro (Registrar)](../atl/atl-registry-component-registrar.md)

