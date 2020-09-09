---
title: Como configurar um link estático para o código do Registrador (apenas C++)
description: Como vincular estaticamente o código C++ ao código do registrador ATL.
ms.date: 09/03/2020
helpviewer_keywords:
- statically linking to ATL Registrar code
- linking [C++], to ATL Registrar code
ms.assetid: 835f5885-87a6-48fa-91e6-60988ee65538
ms.openlocfilehash: f08f7d9433ae1344c7a98a5c52502d03bad21e91
ms.sourcegitcommit: 0df2b7ab4e81284c5248e4584767591dcc1950c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/09/2020
ms.locfileid: "89609154"
---
# <a name="setting-up-a-static-link-to-the-registrar-code-c-only"></a>Configurando um link estático para o código do registrador (somente C++)

Os clientes C++ podem criar um link estático para o código do registrador. A vinculação estática do analisador do registrador adiciona aproximadamente 5K a uma compilação de versão.

A maneira mais simples de configurar a vinculação estática pressupõe que você tenha especificado [`DECLARE_REGISTRY_RESOURCEID`](reference/registry-macros.md#declare_registry_resourceid) na declaração do seu objeto. (É a especificação padrão usada pelo ATL.)

## <a name="to-create-a-static-link-using-declare_registry_resourceid"></a>Para criar um link estático usando `DECLARE_REGISTRY_RESOURCEID`

1. Especifique em **`/D _ATL_STATIC_REGISTRY`** vez de **`/D _ATL_DLL`** na linha de comando CL. Para obter mais informações, consulte [`/D`](../build/reference/d-preprocessor-definitions.md).

1. Recompile.

## <a name="see-also"></a>Confira também

[Componente do registro (registrador)](../atl/atl-registry-component-registrar.md)
