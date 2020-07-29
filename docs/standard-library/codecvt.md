---
title: '&lt;codecvt&gt;'
ms.date: 11/04/2016
f1_keywords:
- codecvt
- <codecvt>
helpviewer_keywords:
- codecvt header
ms.assetid: d44ee229-00d5-4761-9b48-0c702122789d
ms.openlocfilehash: e571c1ca8beef684a40bbf643e83aba3f205fc8e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230111"
---
# <a name="ltcodecvtgt"></a>&lt;codecvt&gt;

Define vários modelos de classe que descrevem objetos com base no modelo de classe [codecvt](../standard-library/codecvt-class.md). Esses objetos podem servir como [facetas de localidade](../standard-library/locale-class.md#facet_class) que controlam conversões entre uma sequência de valores do tipo `Elem` e uma sequência de valores do tipo **`char`** .

## <a name="syntax"></a>Sintaxe

```cpp
#include <codecvt>
```

## <a name="remarks"></a>Comentários

As facetas de localidade declaradas nesse cabeçalho são convertidas entre várias codificações de caracteres. Para caracteres largos (armazenados dentro do programa em inteiros de tamanho fixo):

- UCS-4 é Unicode (ISO 10646) codificado dentro do programa como um inteiro de 32 bits.

- UCS-2 é codificado como Unicode dentro do programa como um inteiro de 16 bits.

- UTF-16 é codificado como Unicode dentro do programa como um ou dois inteiros de 16 bits. (Observe que isso não atende a todos os requisitos de uma codificação de caracteres largos válida para o C padrão ou C++ padrão. No entanto, ela é amplamente usada dessa forma.)

Para fluxos de bytes (armazenados em um arquivo, transmitidos como uma sequência de bytes ou armazenados dentro do programa em uma matriz de **`char`** ):

- UTF-8 é codificado como Unicode dentro de um fluxo de bytes como um ou mais bytes de oito bits com uma ordem de byte determinística.

- UTF-16LE é codificado como Unicode dentro de um fluxo de bytes como UTF-16 com cada inteiro de 16 bits apresentado como dois bytes de oito bits, o byte menos significante primeiro.

- UTF-16BE é codificado como Unicode dentro de um fluxo de bytes como UTF-16 com cada inteiro de 16 bits apresentado como dois bytes de oito bits, o byte mais significante primeiro.

### <a name="enumerations"></a>Enumerações

|||
|-|-|
|[codecvt_mode](../standard-library/codecvt-enums.md#codecvt_mode)|Especifica informações de configuração para facetas de localidade.|

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[codecvt_utf8](codecvt-utf8-class.md)|Representa uma faceta de localidade convertida entre caracteres largos codificados como UCS-2 ou UCS-4 e um fluxo de bytes codificado como UTF-8.|
|[codecvt_utf8_utf16](codecvt-utf8-utf16-class.md)|Representa uma faceta de localidade convertida entre caracteres largos codificados como UTF-16 e um fluxo de bytes codificado como UTF-8.|
|[codecvt_utf16](codecvt-utf16-class.md)|Representa uma faceta de localidade convertida entre caracteres largos codificados como UCS-2 ou UCS-4 e um fluxo de bytes codificado como UTF-16LE ou UTF-16BE.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<codecvt>

**Namespace:** std

## <a name="see-also"></a>Confira também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
