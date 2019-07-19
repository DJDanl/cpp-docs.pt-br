---
title: '&lt;cstdbool&gt;'
ms.date: 07/11/2019
f1_keywords:
- <cstdbool>
- cstdbool
helpviewer_keywords:
- cstdbool header
ms.assetid: 44ccb8b2-d808-4715-8097-58ba09ab33ed
ms.openlocfilehash: ed780e059a5e456731fd6a4f651639e282016f5e
ms.sourcegitcommit: 0867d648e0955ebad7260b5fbebfd6cd4d58f3c7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/19/2019
ms.locfileid: "68341093"
---
# <a name="ltcstdboolgt"></a>&lt;cstdbool&gt;

Inclui o cabeçalho \<de biblioteca padrão C stdbool. h > e adiciona os nomes associados `std` ao namespace.

> [!NOTE]
> Como o \<cabeçalho de >. h stdbool define macros que são palavras- C++chave no, inclusive não tem nenhum efeito. O \<cabeçalho de > stdbool. h é preterido em. C++ O \<cabeçalho de > cstdbool é preterido em c++ 17 e removido no rascunho de c++ 20 padrão.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<> cstdbool

**Namespace:** std

## <a name="remarks"></a>Comentários

A inclusão desse cabeçalho garante que os nomes declarados usando vínculo externo no cabeçalho da biblioteca padrão C sejam `std` declarados no namespace.

## <a name="see-also"></a>Consulte também

[Referência de arquivos de cabeçalho](cpp-standard-library-header-files.md)\
[C++Visão geral da biblioteca padrão](cpp-standard-library-overview.md)\
[Segurança de thread na C++ biblioteca padrão](thread-safety-in-the-cpp-standard-library.md)
