---
title: Portabilidade do conjunto de benefícios de caractere | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- character sets [C++], benefits
- portability [C++], character sets
ms.assetid: bd60b925-1498-4e4f-897b-4c8ce66edcf7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 115a4524f3b11d847291015f3bee5ca10f628310
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46423436"
---
# <a name="benefits-of-character-set-portability"></a>Benefícios da portabilidade do conjunto de caracteres

Você pode se beneficiar do uso de recursos de portabilidade de tempo de execução MFC e C, mesmo se você não pretender atualmente internacionalizar seu aplicativo:

- Codificação de forma portátil torna seu código base flexível. Você pode posteriormente ir facilmente para Unicode ou MBCS.

- Uso de Unicode torna seus aplicativos para Windows mais eficiente. Como o Windows usa Unicode, cadeias de caracteres não-Unicode passadas de e para o sistema operacional devem ser convertidas, que resulta em sobrecarga.


## <a name="see-also"></a>Consulte também

[Unicode e MBCS](../text/unicode-and-mbcs.md)<br/>
[Suporte para Unicode](../text/support-for-unicode.md)