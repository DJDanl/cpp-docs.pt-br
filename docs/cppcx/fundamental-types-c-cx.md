---
title: Tipos fundamentais (C + + CX) | Microsoft Docs
ms.custom: 
ms.date: 01/22/2017
ms.technology: cpp-windows
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: language-reference
ms.assetid: c9f82907-25f2-440b-91d6-afb8dbd46ea6
caps.latest.revision: 
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 885b996e94c1c3a3d55e48e0f37c5690ba084cf6
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="fundamental-types-ccx"></a>Tipos fundamentais (C++/CX)
Além de tipos C++ padrão internos, C + + CX dá suporte ao sistema de tipo é definido de acordo com a arquitetura de tempo de execução do Windows fornece definições de tipo para tipos de Windows Runtime fundamentais que são mapeados para tipos C++ padrão. C + + CX implementa booliano, caractere e os tipos numéricos fundamentais. Essas definições de tipo são definidas no namespace `default` , que nunca precisa ser especificado explicitamente. Além disso, C + + CX fornece wrappers e implementações concretas para determinados tipos de tempo de execução do Windows e as interfaces.  
  
## <a name="boolean-and-character-types"></a>Tipos de caractere e booliano  
 A tabela a seguir lista o valor booliano interno e os tipos de caracteres, bem como seus equivalentes padrão em C++.  
  
|Namespace|C + + nome CX|Definição|Nome padrão do C++|Intervalo de valores|  
|---------------|-----------------------------------------------------------------------|----------------|-------------------------|---------------------|  
|Plataforma|Boolean|Um valor Booliano de 8 bits.|bool|`true` (diferente de zero) e `false` (zero)|  
|default|char16|Um valor não numérico de 16 bits que representa um ponto de código Unicode (UTF-16).|wchar_t<br /><br /> -ou-<br /><br /> L'c'|(Especificado pelo padrão Unicode)|  
  
## <a name="numeric-types"></a>Tipos numéricos  
 A tabela a seguir lista os tipos numéricos internos. Os tipos numéricos são declarados no namespace `default` e são definições de tipo para o tipo interno do C++ correspondente. Nem todos os tipos internos do C++ (longos, por exemplo) têm suporte em tempo de execução do Windows. Para obter consistência e clareza, é recomendável que você use C + + nome CX.  
  
|C + + nome CX|Definição|Nome padrão do C++|Intervalo de valores|  
|-----------------------------------------------------------------------|----------------|-------------------------|---------------------|  
|int8|Um valor numérico com sinal de 8 bits.|signed char|-128 a 127|  
|uint8|Um valor numérico sem sinal de 8 bits.|unsigned char|0 a 255|  
|int16|Um inteiro de 16 bits com sinal.|short|-32.768 a 32.767|  
|uint16|Um inteiro de 16 bits sem sinal.|unsigned short|0 a 65 e 535|  
|int32|Um inteiro com sinal de 32 bits.|int|-2.147.483.648 a 2.147.483.647|  
|uint32|Um inteiro sem sinal de 32 bits.|unsigned int|0 a 4, 294, 967 e 295|  
|int64|Um inteiro com sinal de 64 bits.|muito longa - ou - Int64|-9,223,372,036,854, 775,808 por meio de 9.223.372.036.854.775.807|  
|uint64|Um inteiro sem sinal de 64 bits.|Int64 long long - ou - não assinados não assinados|0 a 18, 446, 744, 073, 709, 551 e 615|  
|float32|Um número de ponto flutuante IEEE 754 de 32 bits.|float|3.4E +/- 38 (7 dígitos)|  
|float64|Um número de ponto flutuante IEEE 754 de 64 bits.|double|1.7E +/- 308 (15 dígitos)|  
  
## <a name="windows-runtime-types"></a>Tipos de tempo de execução do Windows  
 A tabela a seguir lista alguns tipos adicionais que são definidos pela arquitetura de tempo de execução do Windows e são incorporados C + + CX. Object e String são tipos de referência. Os outros são tipos de valor. Todos esses tipos são declarados no namespace `Platform` . Para obter uma lista completa, veja [Platform namespace](../cppcx/platform-namespace-c-cx.md).  
  
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