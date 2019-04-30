---
title: implementation_only
ms.date: 11/04/2016
f1_keywords:
- implementation_only
helpviewer_keywords:
- implementation_only attribute
ms.assetid: d8cabc86-4425-45a0-9587-d57536980088
ms.openlocfilehash: c1435ca74ac2b5a73c308592b1affe6fca097d1b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62383941"
---
# <a name="implementationonly"></a>implementation_only
**Específico do C++**

Suprime geração do arquivo de cabeçalho .tlh (o arquivo de cabeçalho primário).

## <a name="syntax"></a>Sintaxe

```
implementation_only
```

## <a name="remarks"></a>Comentários

Esse arquivo contém todas as declarações usadas para expor o conteúdo da biblioteca de tipos. O arquivo de cabeçalho .tli, com as implementações de funções membro de wrapper, será gerado e incluído na compilação.

Quando esse atributo é especificado, o conteúdo do cabeçalho .tli está no mesmo namespace do geralmente usado no cabeçalho .tlh. Além disso, as funções membro não são declaradas como embutidas.

O **implementation_only** atributo é destinado para uso em conjunto com o [no_implementation](../preprocessor/no-implementation.md) atributo como uma maneira de manter as implementações fora do arquivo de cabeçalho pré-compilado (PCH). Uma instrução `#import` com o atributo `no_implementation` é colocada na região de origem usada para criar o PCH. O PCH resultante é usado por diversos arquivos de origem. Uma `#import` instrução com o **implementation_only** atributo é então usado fora da região de PCH. É necessário usar essa instrução somente uma vez em um dos arquivos de origem. Isso gerará todas as funções membro de wrapper necessárias, sem recompilação adicional para cada arquivo de origem.

> [!NOTE]
> O **implementation_only** atributo em uma `#import` instrução deve ser usado em conjunto com outro `#import` instrução, do mesmo tipo de biblioteca, com o `no_implementation` atributo. Caso contrário, serão gerados erros do compilador. Isso ocorre porque as definições de classe de wrapper geradas pela `#import` instrução com o `no_implementation` atributo são necessárias para compilar as implementações geradas pelo **implementation_only** atributo.

**FIM de específico de C++**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)