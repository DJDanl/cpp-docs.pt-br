---
title: SEÇÕES (C/C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- SECTIONS
dev_langs:
- C++
helpviewer_keywords:
- SECTIONS .def file statement
ms.assetid: 7b974366-9ef5-4e57-bbcc-73a1df6f8857
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ecd8d6050df7a4d30b0a37cad28e030d1cd63cf0
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45722878"
---
# <a name="sections-cc"></a>SECTIONS (C/C++)

Apresenta uma seção de um ou mais `definitions` que são especificadores de acesso em seções no arquivo de saída do seu projeto.

```
SECTIONS
definitions
```

## <a name="remarks"></a>Comentários

Cada definição deve ficar em uma linha separada. O `SECTIONS` palavra-chave pode estar na mesma linha como a primeira definição ou em uma linha anterior. O arquivo. def pode conter um ou mais `SECTIONS` instruções.

Isso `SECTIONS` instrução define atributos para uma ou mais seções no arquivo de imagem e pode ser usada para substituir os atributos padrão para cada tipo de seção.

O formato para `definitions` é:

`.section_name specifier`

em que `.section_name` é o nome de uma seção em sua imagem de programa e `specifier` é um ou mais dos seguintes modificadores de acesso:

|Modificador|Descrição|
|--------------|-----------------|
|`EXECUTE`|A seção é executável|
|`READ`|Permite operações de leitura em dados|
|`SHARED`|Compartilha a seção entre todos os processos que carregam a imagem|
|`WRITE`|Permite operações de gravação em dados|

Separe os nomes de especificador com um espaço. Por exemplo:

```
SECTIONS
.rdata READ WRITE
```

`SECTIONS` marca o início de uma lista de seção `definitions`. Cada `definition` deve estar em uma linha separada. O `SECTIONS` palavra-chave pode ser na mesma linha que o primeiro `definition` ou em uma linha anterior. O arquivo. def pode conter um ou mais `SECTIONS` instruções. O `SEGMENTS` palavra-chave tem suporte como um sinônimo de `SECTIONS`.

Suporte para versões mais antigas do Visual C++:

```
section [CLASS 'classname'] specifier
```

O `CLASS` palavra-chave é suportada para compatibilidade, mas é ignorado.

Uma maneira equivalente para especificar atributos de seção é com o [/seção](../../build/reference/section-specify-section-attributes.md) opção.

## <a name="see-also"></a>Consulte também

[Regras para instruções de definição do módulo](../../build/reference/rules-for-module-definition-statements.md)