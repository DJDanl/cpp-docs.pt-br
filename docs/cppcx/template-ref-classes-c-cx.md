---
title: Classes de referência de modelo (C++/CX)
ms.date: 01/22/2017
ms.assetid: a24d5f45-8dbb-4540-958f-c76c90d8ed93
ms.openlocfilehash: 3e9c233b5227b4ad86eb632db740001bc2a3a8bd
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70740846"
---
# <a name="template-ref-classes-ccx"></a>Classes de referência de modelo (C++/CX)

Os modelos do C++ não são publicados em metadados e, portanto, não podem ter acessibilidade pública ou protegida no seu programa. Naturalmente, você pode usar modelos padrão do C++ internamente em seu programa. Além disso, você pode definir uma classe ref privada como um modelo e pode declarar explicitamente uma classe ref de modelo especializado como um membro privado em uma classe ref pública.

## <a name="authoring-ref-class-templates"></a>Criando modelos de classe ref

O exemplo a seguir mostra como declarar uma classe ref privada como um modelo, como declarar um modelo padrão do C++ e como declará-los como membros em uma classe ref pública. Observe que o modelo C++ padrão pode ser especializado por um tipo de Windows Runtime, neste caso, uma plataforma:: cadeia de caracteres ^.

[!code-cpp[cx_templates#01](../cppcx/codesnippet/CPP/templatedemo/class1.h#01)]

## <a name="see-also"></a>Consulte também

[Sistema de tipos (C++/CX)](../cppcx/type-system-c-cx.md)<br/>
[Referência da linguagem C++/CX](../cppcx/visual-c-language-reference-c-cx.md)<br/>
[Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)
