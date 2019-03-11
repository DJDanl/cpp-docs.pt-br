---
title: Tipos fundamentais (C++/CX)
ms.date: 01/22/2017
ms.assetid: c9f82907-25f2-440b-91d6-afb8dbd46ea6
ms.openlocfilehash: 2bd5be01b868fd3086c2064edfd4ca343db425be
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57752357"
---
# <a name="fundamental-types-ccx"></a>Tipos fundamentais (C++/CX)

Além de tipos C++ padrão internos, C + + c++ /CX oferece suporte ao sistema de tipo que é definido pela arquitetura de tempo de execução do Windows, fornecendo definições de tipo para tipos de tempo de execução do Windows fundamentais que são mapeados para tipos C++ padrão... C + + c++ /CX implementa booliano, caractere e numéricos tipos fundamentais. Essas definições de tipo são definidas no namespace `default` , que nunca precisa ser especificado explicitamente. Além disso, C + + c++ /CLI CX fornece wrappers e implementações concretas para determinados tipos de tempo de execução do Windows e interfaces.

## <a name="boolean-and-character-types"></a>Tipos de caractere e booliano

A tabela a seguir lista o valor booliano interno e os tipos de caracteres, bem como seus equivalentes padrão em C++.

|Namespace|C + + / nome do CX|Definição|Nome padrão do C++|Intervalo de valores|
|---------------|-----------------------------------------------------------------------|----------------|-------------------------|---------------------|
|Plataforma|Boolean|Um valor Booliano de 8 bits.|bool|**Verdadeiro** (diferente de zero) e **falso** (zero)|
|default|char16|Um valor não numérico de 16 bits que representa um ponto de código Unicode (UTF-16).|wchar_t<br /><br /> -ou-<br /><br /> L'c'|(Especificado pelo padrão Unicode)|

## <a name="numeric-types"></a>Tipos numéricos

A tabela a seguir lista os tipos numéricos internos. Os tipos numéricos são declarados no namespace `default` e são definições de tipo para o tipo interno do C++ correspondente. Nem todos os tipos internos do C++ (longos, por exemplo) têm suporte em tempo de execução do Windows. Para consistência e clareza, é recomendável que você use C + + / nome do CX.

|C + + / nome do CX|Definição|Nome padrão do C++|Intervalo de valores|
|-----------------------------------------------------------------------|----------------|-------------------------|---------------------|
|int8|Um valor numérico com sinal de 8 bits.|signed char|-128 a 127|
|uint8|Um valor numérico sem sinal de 8 bits.|unsigned char|0 a 255|
|int16|Um inteiro de 16 bits com sinal.|short|-32.768 a 32.767|
|uint16|Um inteiro de 16 bits sem sinal.|unsigned short|0 a 65 e 535|
|int32|Um inteiro com sinal de 32 bits.|int|-2.147.483.648 a 2.147.483.647|
|uint32|Um inteiro sem sinal de 32 bits.|unsigned int|0 a 4, 294, 967 e 295|
|int64|Um inteiro com sinal de 64 bits.|long long  -or- __int64|-9,223,372,036,854, 775,808 por meio de 9.223.372.036.854.775.807|
|uint64|Um inteiro sem sinal de 64 bits.|unsigned long long  -or- unsigned __int64|0 a 18, 446, 744, 073, 709, 551 e 615|
|float32|Um número de ponto flutuante IEEE 754 de 32 bits.|float|3.4E +/- 38 (7 dígitos)|
|float64|Um número de ponto flutuante IEEE 754 de 64 bits.|double|1.7E +/- 308 (15 dígitos)|

## <a name="windows-runtime-types"></a>Tipos de tempo de execução do Windows

A tabela a seguir lista alguns tipos adicionais que são definidos pela arquitetura de tempo de execução do Windows e são criados no C + + c++ /CLI CX. Object e String são tipos de referência. Os outros são tipos de valor. Todos esses tipos são declarados no namespace `Platform` . Para obter uma lista completa, veja [Platform namespace](../cppcx/platform-namespace-c-cx.md).

|Nome|Definição|
|----------|----------------|
|Objeto|Representa qualquer tipo de tempo de execução do Windows.|
|Cadeia de Caracteres|Uma série de caracteres que representam o texto.|
|Rect|Um conjunto de quatro números de ponto flutuante que representam o local e o tamanho de um retângulo.|
|SizeT|Um par ordenado de números de ponto flutuante que especifica uma altura e largura.|
|Ponto|Um par ordenado de coordenadas x e y de ponto flutuante que define um ponto em um plano bidimensional.|
|Guid|Um valor não numérico de 128 bits que é usado como um identificador exclusivo.|
|UIntPtr|(Somente para uso interno.) Um valor sem sinal de 64 bits que é usado como um ponteiro.|
|IntPtr|(Somente para uso interno.)  Um valor com sinal de 64 bits que é usado como um ponteiro.|

## <a name="see-also"></a>Consulte também

[Sistema de tipos](../cppcx/type-system-c-cx.md)
