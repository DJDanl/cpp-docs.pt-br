---
title: Erro do compilador C3552
ms.date: 11/04/2016
f1_keywords:
- C3552
helpviewer_keywords:
- C3552
ms.assetid: 83401524-1bf1-44c0-8aca-a6eb35c4224c
ms.openlocfilehash: 567c92ddabbe2517700e4c67ef2c1ba899baada8
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80200662"
---
# <a name="compiler-error-c3552"></a>Erro do compilador C3552

' TypeName ': um tipo de retorno especificado tardiamente não pode conter ' auto '

Se você usar a palavra-chave `auto` como um espaço reservado para o tipo de retorno de uma função, deverá fornecer um tipo de retorno especificado de forma tardia. No entanto, você não pode usar outra palavra-chave `auto` para especificar o tipo de retorno de última especificação. Por exemplo, o fragmento de código a seguir produz o erro C3552.

`auto myFunction->auto; // C3552`
