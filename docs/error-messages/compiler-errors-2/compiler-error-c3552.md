---
title: Erro do compilador C3552
ms.date: 11/04/2016
f1_keywords:
- C3552
helpviewer_keywords:
- C3552
ms.assetid: 83401524-1bf1-44c0-8aca-a6eb35c4224c
ms.openlocfilehash: d2d3a60fcd4a26238cd6cf330f47b48c5b3198ad
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230825"
---
# <a name="compiler-error-c3552"></a>Erro do compilador C3552

' TypeName ': um tipo de retorno especificado tardiamente não pode conter ' auto '

Se você usar a **`auto`** palavra-chave como um espaço reservado para o tipo de retorno de uma função, deverá fornecer um tipo de retorno especificado de forma tardia. No entanto, você não pode usar outra **`auto`** palavra-chave para especificar o tipo de retorno especificado de última. Por exemplo, o fragmento de código a seguir produz o erro C3552.

`auto myFunction->auto; // C3552`
