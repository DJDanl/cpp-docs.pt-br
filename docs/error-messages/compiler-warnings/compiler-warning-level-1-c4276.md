---
title: Aviso do compilador (nível 1) C4276
ms.date: 11/04/2016
f1_keywords:
- C4276
helpviewer_keywords:
- C4276
ms.assetid: 9d738c2d-29e5-408a-b9ff-be1a850b2238
ms.openlocfilehash: c1de07cd65bbc9f02a979ceebe31be4143af70ad
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80175812"
---
# <a name="compiler-warning-level-1-c4276"></a>Aviso do compilador (nível 1) C4276

' function ': nenhum protótipo fornecido; nenhum parâmetro assumido

Quando você pega o endereço de uma função com a Convenção de chamada [__stdcall](../../cpp/stdcall.md) , deve fornecer um protótipo para que o compilador possa criar o nome decorado da função. Como a *função* não tem nenhum protótipo, o compilador, ao criar o nome decorado, pressupõe que a função não tem parâmetros.
