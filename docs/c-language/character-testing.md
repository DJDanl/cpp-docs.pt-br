---
title: Testes de caractere
ms.date: 11/04/2016
ms.assetid: 376ba061-bae3-427e-9569-33fa5949a199
ms.openlocfilehash: b02d07ca2796e5088c3021f1ae8795ea92761943
ms.sourcegitcommit: 180f63704f6ddd07a4172a93b179cf0733fd952d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2019
ms.locfileid: "70740093"
---
# <a name="character-testing"></a>Testes de caractere

**4.3.1 do ANSI** Os conjuntos de caracteres testados pelas funções `isalnum`, `isalpha`, `iscntrl`, `islower` `isprint`, e `isupper`

A lista a seguir descreve essas funções como são implementadas pelo compilador Microsoft C.

|Função|Testes para|
|--------------|---------------|
|`isalnum`|Caracteres 0 – 9, A–Z, a–z ASCII 48– 57, 65– 90, 97– 122|
|`isalpha`|Caracteres A–Z, a–z ASCII 65–90, 97–122|
|`iscntrl`|ASCII 0 – 31, 127|
|`islower`|Caracteres A–Z ASCII 97–122|
|`isprint`|Caracteres A–Z, a–z, 0 – 9, pontuação, espaço ASCII 32–126|
|`isupper`|Caracteres A–Z ASCII 65–90|

## <a name="see-also"></a>Confira também

[Funções de biblioteca](../c-language/library-functions.md)
