---
title: Como configurar um Link estático para o código do registrador (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- statically linking to ATL Registrar code
- linking [C++], to ATL Registrar code
ms.assetid: 835f5885-87a6-48fa-91e6-60988ee65538
ms.openlocfilehash: b95bd17abca3237710956f3a1bf1b1d6fa9df51e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62196658"
---
# <a name="setting-up-a-static-link-to-the-registrar-code-c-only"></a>Como configurar um Link estático para o código do registrador (C++)

Clientes do C++ podem criar um link estático para o código do registrador. Vinculação estática do analisador do registrador adiciona aproximadamente 5 mil para um build de versão.

A maneira mais simples para configurar a vinculação estática pressupõe que você especificou [DECLARE_REGISTRY_RESOURCEID](reference/registry-macros.md#declare_registry_resourceid) na declaração do objeto. (Essa é a especificação do padrão usada pelo ATL.)

## <a name="to-create-a-static-link-using-declareregistryresourceid"></a>Para criar um link estático usando DECLARE_REGISTRY_RESOURCEID

1. Especificar [/D](../build/reference/d-preprocessor-definitions.md)  **\_ATL\_estático\_registro** em vez de **/D \_ATL\_DLL**.

1. Recompile.

## <a name="see-also"></a>Consulte também

[Componente de registro (Registrar)](../atl/atl-registry-component-registrar.md)
