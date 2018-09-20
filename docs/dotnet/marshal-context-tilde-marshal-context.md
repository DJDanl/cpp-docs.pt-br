---
title: 'marshal_context:: ~ marshal_context | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- marshal_context::~marshal_context
- msclr.interop.marshal_context.~marshal_context
- marshal_context.~marshal_context
- msclr::interop::marshal_context::~marshal_context
- ~marshal_context
dev_langs:
- C++
helpviewer_keywords:
- marshal_context class [C++], operations
ms.assetid: 34c41b38-4c33-4f61-b74e-831ac46b4ab5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 49f194f153f3e4f911333e22b11ebddf7efcaa32
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46447252"
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