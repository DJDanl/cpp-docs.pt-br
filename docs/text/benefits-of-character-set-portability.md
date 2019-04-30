---
title: Benefícios da portabilidade do conjunto de caracteres
ms.date: 11/04/2016
helpviewer_keywords:
- character sets [C++], benefits
- portability [C++], character sets
ms.assetid: bd60b925-1498-4e4f-897b-4c8ce66edcf7
ms.openlocfilehash: 0ca7e46cabb2d98a64a244863f8574a3e9e2a456
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62410767"
---
# <a name="benefits-of-character-set-portability"></a>Benefícios da portabilidade do conjunto de caracteres

Você pode se beneficiar do uso de recursos de portabilidade de tempo de execução MFC e C, mesmo se você não pretender atualmente internacionalizar seu aplicativo:

- Codificação de forma portátil torna seu código base flexível. Você pode posteriormente ir facilmente para Unicode ou MBCS.

- Uso de Unicode torna seus aplicativos para Windows mais eficiente. Como o Windows usa Unicode, cadeias de caracteres não-Unicode passadas de e para o sistema operacional devem ser convertidas, que resulta em sobrecarga.

## <a name="see-also"></a>Consulte também

[Unicode e MBCS](../text/unicode-and-mbcs.md)<br/>
[Suporte para Unicode](../text/support-for-unicode.md)
