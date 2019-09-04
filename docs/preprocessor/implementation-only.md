---
title: atributo de importação de implementation_only
ms.date: 08/29/2019
f1_keywords:
- implementation_only
helpviewer_keywords:
- implementation_only attribute
ms.assetid: d8cabc86-4425-45a0-9587-d57536980088
ms.openlocfilehash: 08144b3c815350acfe6a856b36d2d88085d1c04d
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70218981"
---
# <a name="implementation_only-import-attribute"></a>atributo de importação de implementation_only

**C++Determinados**

Suprime a geração do `.tlh` arquivo de cabeçalho da biblioteca de tipos primário.

## <a name="syntax"></a>Sintaxe

> **#import** *biblioteca de tipos* **implementation_only**

## <a name="remarks"></a>Comentários

Esse arquivo contém todas as declarações usadas para expor o conteúdo da biblioteca de tipos. O `.tli` arquivo de cabeçalho, com as implementações das funções de membro do wrapper, será gerado e incluído na compilação.

Quando esse atributo é especificado, o conteúdo do `.tli` cabeçalho está no mesmo namespace que aquele normalmente usado `.tlh` no cabeçalho. Além disso, as funções membro não são declaradas como embutidas.

O atributo **implementation_only** é destinado ao uso em conjunto com o atributo [no_implementation](../preprocessor/no-implementation.md) como uma maneira de manter as implementações fora do arquivo de cabeçalho pré-compilado (PCH). Uma instrução `#import` com o atributo `no_implementation` é colocada na região de origem usada para criar o PCH. O PCH resultante é usado por diversos arquivos de origem. Uma `#import` instrução com o atributo **implementation_only** é usada fora da região PCH. Você precisa usar essa instrução apenas uma vez em um dos arquivos de origem. Ele gera todas as funções de membro do wrapper necessárias sem recompilação adicional para cada arquivo de origem.

> [!NOTE]
> O atributo **implementation_only** em uma `#import` instrução deve ser usado em conjunto com outra `#import` instrução, da mesma biblioteca de tipos, com o `no_implementation` atributo. Caso contrário, os erros do compilador são gerados. Isso ocorre porque as definições de classe de wrapper `#import` geradas pela `no_implementation` instrução com o atributo são necessárias para compilar as implementações geradas pelo atributo **implementation_only** .

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)\
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)
