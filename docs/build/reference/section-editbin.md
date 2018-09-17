---
title: -SECTION (EDITBIN) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /section
dev_langs:
- C++
helpviewer_keywords:
- -SECTION editbin option
- SECTION editbin option
- alignment characters in sections
- /SECTION editbin option
ms.assetid: 4680ab4e-c984-4251-8241-93440cad7615
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3f91d467681d5a4d5bf4eaa5f042ef44b87810b3
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45701968"
---
# <a name="section-editbin"></a>/SECTION (EDITBIN)

```
/SECTION:name[=newname][,attributes][alignment]
```

## <a name="remarks"></a>Comentários

Esta opção altera os atributos de uma seção, sobrescrevendo os atributos que foram definidos quando o arquivo de objeto para a seção foi compilado ou vinculado.

Após os dois-pontos ( **:** ), especifique a *nome* da seção. Para alterar o nome da seção, execute *nome* com um sinal de igual (=) e um *newname* para a seção.

Para definir ou alterar a seção `attributes`, especifique uma vírgula (**,**) seguido por um ou mais caracteres de atributos. Para negar a um atributo, preceda seu caractere com um ponto de exclamação (!). Os seguintes caracteres especificam atributos de memória:

|Atributo|Configuração|
|---------------|-------------|
|c|código|
|d|Descartável|
|e|executável|
|i|dados inicializados|
|K|memória de virtual em cache|
|m|Remover link|
|o|informações de link|
|p|memória virtual paginável|
|r|read|
|s|shared|
|u|dados não inicializados|
|W|write|

Para controlar *alinhamento*, especifique o caractere **um** seguido por um dos caracteres a seguir para definir o tamanho de alinhamento em bytes, da seguinte maneira:

|Caractere|Tamanho de alinhamento em bytes|
|---------------|-----------------------------|
|1|1|
|2|2|
|4|4|
|8|8|
|p|16|
|t|32|
|s|64|
|x|sem alinhamento|

Especifique o `attributes` e *alinhamento* caracteres como uma cadeia de caracteres com nenhum espaço em branco. Os caracteres não diferenciam maiusculas de minúsculas.

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](../../build/reference/editbin-options.md)