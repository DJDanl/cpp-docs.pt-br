---
title: Erro fatal C1013
ms.date: 11/04/2016
f1_keywords:
- C1013
helpviewer_keywords:
- C1013
ms.assetid: 5514a679-efe7-4055-bdd3-5693ca0c332f
ms.openlocfilehash: 4ee0b8ce97ba5d49e2784f7cd3c74c3b930c6a21
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64344791"
---
# <a name="fatal-error-c1013"></a>Erro fatal C1013

limite do compilador: muitos parênteses abertos

Uma expressão contém muitos níveis de parênteses em uma única expressão. Simplifique a expressão ou dividi-la em várias instruções.

Antes do Visual C++ 6.0 Service Pack 3, o limite de parênteses aninhados em uma única expressão era 59. Atualmente, o limite de parênteses aninhados é 256.