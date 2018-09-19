---
title: Tipo char | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- type char
- unsigned char keyword [C]
- char keyword [C]
ms.assetid: a5da0866-e780-4793-be87-15a8426e7ea0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: eec964d9b81ee93f888bbd4152f06f6bdf51b6d0
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46053824"
---
# <a name="type-char"></a>Tipo char

O tipo `char` é usado para armazenar o valor inteiro de um membro do conjunto de caracteres representável. Esse valor inteiro é o código ASCII que corresponde ao caractere especificado.

**Seção específica da Microsoft**

Os valores de caracteres do tipo `unsigned char` têm um intervalo de 0 a 0xFF hexadecimal. Um **signed char** tem o intervalo de 0x80 a 0x7F. Esses intervalos podem ser traduzidos em de 0 a 255 decimal e -128 a +127 decimal, respectivamente. A opção do compilador /J altera o padrão de **signed** para `unsigned`.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Armazenamento de tipos básicos](../c-language/storage-of-basic-types.md)