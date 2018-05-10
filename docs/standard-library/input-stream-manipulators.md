---
title: Manipuladores de Fluxo de Entrada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- input streams, manipulators
- input stream objects
ms.assetid: 0addcacb-7b7b-4d70-9775-a59abc400fb3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 30f642dc4942491bd73265e3d647d3281f97c1e7
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="input-stream-manipulators"></a>Manipuladores de Fluxo de Entrada

Vários manipuladores, como [setprecision](../standard-library/iomanip-functions.md#setprecision), são definidas para o `ios` de classe e, portanto, se aplicam a fluxos de entrada. No entanto, alguns manipuladores de fato afetam objetos de fluxo de entrada. Ente aqueles que o fazem, os mais importantes são os manipuladores base, `dec`, `oct` e `hex`, que determinam a base de conversão usada com números do fluxo de entrada.

Na extração, o manipulador `hex` habilita o processamento de vários formatos de entrada. Por exemplo, c, C, 0xc, 0xC, 0Xc e 0XC são interpretados como o inteiro decimal 12. Qualquer caractere que não estiver nos intervalos de 0-9, A-F e a-f e que não seja x e X finaliza a conversão numérica. Sendo assim, a sequência `"124n5"` é convertida no número 124 com o conjunto de bits [basic_ios::fail](../standard-library/basic-ios-class.md#fail).

## <a name="see-also"></a>Consulte também

[Fluxos de entrada](../standard-library/input-streams.md)<br/>
