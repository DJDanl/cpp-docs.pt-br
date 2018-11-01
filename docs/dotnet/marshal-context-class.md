---
title: Classe marshal_context
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- marshal_context
helpviewer_keywords:
- marshal_context class [C++]
ms.assetid: 241b0cf6-4ca4-4812-aaee-d671c11dc034
ms.openlocfilehash: 0e25aee0996b0cd16ca92566da22d377b762d7bc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50594526"
---
# <a name="marshalcontext-class"></a>Classe marshal_context

Essa classe converte dados entre ambientes nativos e gerenciados.

## <a name="syntax"></a>Sintaxe

```
class marshal_context
```

## <a name="remarks"></a>Comentários

Use o `marshal_context` classe para conversões de dados que exigem um contexto. Ver [visão geral de Marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md) para obter mais informações sobre quais conversões exigem um contexto e qual arquivo marshaling deve ser incluído. O resultado de marshaling quando você usa um contexto é válido somente até o `marshal_context` objeto é destruído. Para preservar seu resultado, você deve copiar os dados.

O mesmo `marshal_context` pode ser usado para várias conversões de dados. Reutilizar o contexto dessa maneira não afetará os resultados de marshaling de chamadas anteriores.

## <a name="requirements"></a>Requisitos

**Arquivo de cabeçalho:** \<msclr\marshal.h >, \<msclr\marshal_windows.h >, \<msclr\marshal_cppstd.h >, ou \<msclr\marshal_atl.h >

**Namespace:** msclr::interop

## <a name="see-also"></a>Consulte também

[Visão geral de marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md)<br/>
[marshal_as](../dotnet/marshal-as.md)