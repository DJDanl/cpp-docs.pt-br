---
title: '&lt;cstdalign&gt;'
ms.date: 07/11/2019
f1_keywords:
- <cstdalign>
- cstdalign
- __alignas_is_defined
- __alignof_is_defined
helpviewer_keywords:
- cstdalign header
- __alignas_is_defined
- __alignof_is_defined
ms.assetid: 9d570924-d299-4225-9a58-8c4c820f5903
ms.openlocfilehash: 603a590190c50495aa80f1b41a574149eb8f760a
ms.sourcegitcommit: 0867d648e0955ebad7260b5fbebfd6cd4d58f3c7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/19/2019
ms.locfileid: "68342835"
---
# <a name="ltcstdaligngt"></a>&lt;cstdalign&gt;

Em algumas C++ implementações de biblioteca padrão, esse cabeçalho inclui o cabeçalho \<de biblioteca padrão C stdalign. h > e adiciona os nomes `std` associados ao namespace. Como esse cabeçalho não é implementado em MSVC, \<o cabeçalho de > de cstdalign `__alignas_is_defined` define `__alignof_is_defined`as macros de compatibilidade e.

> [!NOTE]
> Como o \<cabeçalho de >. h stdalign define macros que são palavras- C++chave no, inclusive não tem nenhum efeito. O \<cabeçalho de > stdalign. h é preterido em. C++ O \<cabeçalho de > cstdalign é preterido em c++ 17 e removido no rascunho de c++ 20 padrão.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<> cstdalign

**Namespace:** std

## <a name="macros"></a>Macros

| Macro | Descrição |
| - | - |
| `__alignas_is_defined` | Uma macro de compatibilidade C que expande para a constante de inteiro 1. |
| `__alignof_is_defined` | Uma macro de compatibilidade C que expande para a constante de inteiro 1. |

## <a name="see-also"></a>Consulte também

[Referência de arquivos de cabeçalho](cpp-standard-library-header-files.md)\
[C++Visão geral da biblioteca padrão](cpp-standard-library-overview.md)\
[Segurança de thread na C++ biblioteca padrão](thread-safety-in-the-cpp-standard-library.md)
