---
title: Compilador aviso (nível 1) C4276
ms.date: 11/04/2016
f1_keywords:
- C4276
helpviewer_keywords:
- C4276
ms.assetid: 9d738c2d-29e5-408a-b9ff-be1a850b2238
ms.openlocfilehash: 87f13f7da12a3f7e40aaad180e2a3bc83e121771
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62207133"
---
# <a name="compiler-warning-level-1-c4276"></a>Compilador aviso (nível 1) C4276

'function': nenhum protótipo fornecido; assumido sem parâmetros

Quando você toma o endereço de uma função com o [stdcall](../../cpp/stdcall.md) convenção de chamada, você deve fornecer um protótipo para que o compilador possa criar o nome da função decorada. Uma vez que *função* não tem nenhum protótipo, o compilador, ao criar o nome decorado, assume a função não tem parâmetros.