---
title: Testes de caractere
ms.date: 11/04/2016
ms.assetid: 376ba061-bae3-427e-9569-33fa5949a199
ms.openlocfilehash: 31a90f28d710ffc1b58f9c6b3fcfd01fd8d2d00c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50523191"
---
# <a name="character-testing"></a>Testes de caractere

**ANSI 4.3.1** Os conjuntos de caracteres testados pelas funções `isalnum`, `isalpha`, `iscntrl`, `islower`, `isprint` e `isupper`

A lista a seguir descreve essas funções como são implementadas pelo compilador Microsoft C.

|Função|Testes para|
|--------------|---------------|
|`isalnum`|Caracteres 0 – 9, A–Z, a–z ASCII 48– 57, 65– 90, 97– 122|
|`isalpha`|Caracteres A–Z, a–z ASCII 65–90, 97–122|
|`iscntrl`|ASCII 0 – 31, 127|
|`islower`|Caracteres A–Z ASCII 97–122|
|`isprint`|Caracteres A–Z, a–z, 0 – 9, pontuação, espaço ASCII 32–126|
|`isupper`|Caracteres A–Z ASCII 65–90|

## <a name="see-also"></a>Consulte também

[Funções de biblioteca](../c-language/library-functions.md)