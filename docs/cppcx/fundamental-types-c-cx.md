---
title: Tipos fundamentais (C++/CX)
ms.date: 01/22/2017
ms.assetid: c9f82907-25f2-440b-91d6-afb8dbd46ea6
ms.openlocfilehash: 3d484d9490a0a5b2ee2e7f92381528124b47701c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230994"
---
# <a name="fundamental-types-ccx"></a>Tipos fundamentais (C++/CX)

Além dos tipos internos do C++ padrão, o C++/CX dá suporte ao sistema de tipos definido pela arquitetura de Windows Runtime fornecendo typedefs para os tipos fundamentais Windows Runtime que são mapeados para tipos C++ padrão... O C++/CX implementa os tipos Boolean, Character e numeric Fundamentals. Essas definições de tipo são definidas no namespace `default` , que nunca precisa ser especificado explicitamente. Além disso, o C++/CX fornece wrappers e implementações concretas para determinados tipos de Windows Runtime e interfaces.

## <a name="boolean-and-character-types"></a>Tipos de caractere e booliano

A tabela a seguir lista o valor booliano interno e os tipos de caracteres, bem como seus equivalentes padrão em C++.

|Namespace|Nome do C++/CX|Definição|Nome padrão do C++|Intervalo de valores|
|---------------|-----------------------------------------------------------------------|----------------|-------------------------|---------------------|
|Plataforma|Boolean|Um valor Booliano de 8 bits.|bool|**`true`**(diferente de zero) e **`false`** (zero)|
|padrão|char16|Um valor não numérico de 16 bits que representa um ponto de código Unicode (UTF-16).|wchar_t<br /><br /> -ou-<br /><br /> L'c'|(Especificado pelo padrão Unicode)|

## <a name="numeric-types"></a>Tipos numéricos

A tabela a seguir lista os tipos numéricos internos. Os tipos numéricos são declarados no namespace `default` e são definições de tipo para o tipo interno do C++ correspondente. Nem todos os tipos internos C++ (Long, por exemplo) têm suporte no Windows Runtime. Para fins de consistência e clareza, recomendamos que você use o nome C++/CX.

|Nome do C++/CX|Definição|Nome padrão do C++|Intervalo de valores|
|-----------------------------------------------------------------------|----------------|-------------------------|---------------------|
|int8|Um valor numérico com sinal de 8 bits.|signed char|-128 a 127|
|uint8|Um valor numérico sem sinal de 8 bits.|unsigned char|0 a 255|
|int16|Um inteiro com sinal de 16 bits.|short|-32.768 a 32.767|
|uint16|Um inteiro sem sinal de 16 bits.|unsigned short|0 a 65 e 535|
|int32|Um inteiro de 32 bytes com sinal.|INT|-2.147.483.648 a 2.147.483.647|
|uint32|Um inteiro não assinado de 32 bits.|unsigned int|0 a 4, 294, 967 e 295|
|int64|Um inteiro de 64 bytes com sinal.|longo tempo ou __int64|-9.223.372.036.854, 775.808 a 9.223.372.036.854.775.807|
|uint64|Um inteiro não assinado de 64 bits.|__int64 demorado longo ou não assinado|0 a 18, 446, 744, 073, 709, 551 e 615|
|float32|Um número de ponto flutuante IEEE 754 de 32 bits.|FLOAT|3.4E +/- 38 (7 dígitos)|
|float64|Um número de ponto flutuante IEEE 754 de 64 bits.|double|1.7E +/- 308 (15 dígitos)|

## <a name="windows-runtime-types"></a>Tipos de Windows Runtime

A tabela a seguir lista alguns tipos adicionais que são definidos pela arquitetura de Windows Runtime e são criados em C++/CX. Object e String são tipos de referência. Os outros são tipos de valor. Todos esses tipos são declarados no namespace `Platform` . Para obter uma lista completa, veja [Platform namespace](../cppcx/platform-namespace-c-cx.md).

|Nome|Definição|
|----------|----------------|
|Objeto|Representa qualquer tipo de Windows Runtime.|
|Cadeia de caracteres|Uma série de caracteres que representam o texto.|
|Rect|Um conjunto de quatro números de ponto flutuante que representam o local e o tamanho de um retângulo.|
|SizeT|Um par ordenado de números de ponto flutuante que especifica uma altura e largura.|
|Point|Um par ordenado de coordenadas x e y de ponto flutuante que define um ponto em um plano bidimensional.|
|Guid|Um valor não numérico de 128 bits que é usado como um identificador exclusivo.|
|UIntPtr|(Somente para uso interno.) Um valor de 64 bits sem sinal que é usado como um ponteiro.|
|IntPtr|(Somente para uso interno.)  Um valor de 64 bits assinado que é usado como um ponteiro.|

## <a name="see-also"></a>Confira também

[Sistema de tipo](../cppcx/type-system-c-cx.md)
