---
title: Configurando um Link estático para o código do registrador (C++) | Microsoft Docs
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
ms.openlocfilehash: 3bde1d369ce5339f07ea36979ef50ddccb0d30d1
ms.sourcegitcommit: 997e6b7d336cddb388bb6e9e56527725fcaa0624
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/08/2018
ms.locfileid: "48860264"
---
# <a name="setting-up-a-static-link-to-the-registrar-code-c-only"></a>Como configurar um Link estático para o código do registrador (C++)

Clientes do C++ podem criar um link estático para o código do registrador. Vinculação estática do analisador do registrador adiciona aproximadamente 5 mil para um build de versão.

A maneira mais simples para configurar a vinculação estática pressupõe que você especificou [DECLARE_REGISTRY_RESOURCEID](reference/registry-macros.md#declare_registry_resourceid) na declaração do objeto. (Essa é a especificação do padrão usada pelo ATL.)

## <a name="to-create-a-static-link-using-declareregistryresourceid"></a>Para criar um link estático usando DECLARE_REGISTRY_RESOURCEID

1. Especificar [/D](../build/reference/d-preprocessor-definitions.md) `_ATL_STATIC_REGISTRY` em vez de /D **_ATL_DLL**.

1. Recompile.

## <a name="see-also"></a>Consulte também

[Componente de registro (Registrar)](../atl/atl-registry-component-registrar.md)
