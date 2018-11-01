---
title: marshal_context::~marshal_context
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- marshal_context::~marshal_context
- msclr.interop.marshal_context.~marshal_context
- marshal_context.~marshal_context
- msclr::interop::marshal_context::~marshal_context
- ~marshal_context
helpviewer_keywords:
- marshal_context class [C++], operations
ms.assetid: 34c41b38-4c33-4f61-b74e-831ac46b4ab5
ms.openlocfilehash: 3bf16ab2dde4047fb845cd700821d097f733a4d2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50528213"
---
# <a name="marshalcontextmarshalcontext"></a>marshal_context::~marshal_context

Destrói um objeto `marshal_context`.

## <a name="syntax"></a>Sintaxe

```
~marshal_context();
```

## <a name="remarks"></a>Comentários

Algumas conversões de dados exigem um contexto de marshaling. Ver [visão geral de Marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md) para obter mais informações sobre quais traduções exigem um contexto e qual arquivo marshaling deve ser incluído em seu aplicativo.

Excluindo um `marshal_context` objeto invalidará os dados convertidos pelo contexto. Se você quiser preservar seus dados após um `marshal_context` objeto é destruído, você deve copiar manualmente os dados a uma variável que será mantido.

## <a name="requirements"></a>Requisitos

**Arquivo de cabeçalho:** \<msclr\marshal.h >, \<msclr\marshal_windows.h >, \<msclr\marshal_cppstd.h >, ou \<msclr\marshal_atl.h >

**Namespace:** msclr::interop

## <a name="see-also"></a>Consulte também

[Visão geral de marshaling no C++](../dotnet/overview-of-marshaling-in-cpp.md)<br/>
[marshal_as](../dotnet/marshal-as.md)<br/>
[Classe marshal_context](../dotnet/marshal-context-class.md)