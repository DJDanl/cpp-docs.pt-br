---
title: /SECTION (EDITBIN)
ms.date: 11/04/2016
f1_keywords:
- /section
helpviewer_keywords:
- -SECTION editbin option
- SECTION editbin option
- alignment characters in sections
- /SECTION editbin option
ms.assetid: 4680ab4e-c984-4251-8241-93440cad7615
ms.openlocfilehash: 8bcc925b34118630c872a0147b93291626b7c19b
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57822425"
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
|k|memória de virtual em cache|
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

[Opções de EDITBIN](editbin-options.md)
