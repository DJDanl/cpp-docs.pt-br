---
title: Static Const Int Linkage não é mais Literal | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- literal attribute [C++]
- constants, declaring
- integral constant expressions
ms.assetid: d2a5e3d2-ffb0-4b61-8114-bec5993a1195
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: c51853274b061ba290ff90993f45ccdf3375349b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46431288"
---
# <a name="static-const-int-linkage-is-no-longer-literal"></a>Static Const Int Linkage não é mais literal

Declaração de um membro constante de uma classe foi alterado de extensões gerenciadas para C++ para Visual C++.

Embora `static const` integrais membros ainda têm suporte, seu atributo de vinculação foi alterado. O atributo de vinculação anterior agora é executado em um membro da integral literal. Por exemplo, considere a seguinte classe de extensões gerenciadas:

```
public __gc class Constants {
public:
   static const int LOG_DEBUG = 4;
};
```

Isso gera os seguintes atributos CIL subjacentes para o campo (Observe o atributo literal):

```
.field public static literal int32
modopt([Microsoft.VisualC]Microsoft.VisualC.IsConstModifier) STANDARD_CLIENT_PRX = int32(0x00000004)
```

Embora isso ainda é compilado em nova sintaxe:

```
public ref class Constants {
public:
   static const int LOG_DEBUG = 4;
};
```

ele não emite mais o atributo literal e, portanto, não estiver exibido como uma constante em tempo de execução CLR:

```
.field public static int32 modopt([Microsoft.VisualC]Microsoft.VisualC.IsConstModifier) STANDARD_CLIENT_PRX = int32(0x00000004)
```

Para ter o mesmo atributo literal entre idioma, a declaração deve ser alterada para o com suporte recente `literal` membro de dados, como segue,

```
public ref class Constants {
public:
   literal int LOG_DEBUG = 4;
};
```

## <a name="see-also"></a>Consulte também

[Declarações de membro em uma classe ou interface (C++/CLI)](../dotnet/member-declarations-within-a-class-or-interface-cpp-cli.md)<br/>
[literal](../windows/literal-cpp-component-extensions.md)