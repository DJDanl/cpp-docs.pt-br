---
title: /SECTION (EDITBIN)
ms.date: 11/04/2016
f1_keywords:
- /section_editbin
helpviewer_keywords:
- -SECTION editbin option
- SECTION editbin option
- alignment characters in sections
- /SECTION editbin option
ms.assetid: 4680ab4e-c984-4251-8241-93440cad7615
ms.openlocfilehash: 770e1d1c1cf288a7fe68f5bd076791d43f5b8572
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79438918"
---
# <a name="section-editbin"></a>/SECTION (EDITBIN)

```
/SECTION:name[=newname][,attributes][alignment]
```

## <a name="remarks"></a>Comentários

Essa opção altera os atributos de uma seção, substituindo os atributos que foram definidos quando o arquivo de objeto da seção foi compilado ou vinculado.

Após os dois-pontos ( **:** ), especifique o *nome* da seção. Para alterar o nome da seção, siga o *nome* com um sinal de igual (=) e um *NewName* para a seção.

Para definir ou alterar o `attributes`da seção, especifique uma vírgula ( **,** ) seguida de um ou mais caracteres de atributos. Para negar um atributo, preceda seu caractere com um ponto de exclamação (!). Os seguintes caracteres especificam atributos de memória:

|Atributo|Configuração|
|---------------|-------------|
|c|código|
|d|Descartado|
|e|executável|
|{1&gt;i&lt;1}|dados inicializados|
|k|memória virtual armazenada em cache|
|m|remover link|
|o|informações de link|
|p|memória virtual paginada|
|r|read|
|s|compartilhadas|
|u|dados não inicializados|
|w|write|

Para controlar o *alinhamento*, especifique o caractere **a** seguido de um dos caracteres a seguir para definir o tamanho do alinhamento em bytes, da seguinte maneira:

|Caractere|Tamanho do alinhamento em bytes|
|---------------|-----------------------------|
|1|1|
|2|2|
|4|4|
|8|8|
|p|16|
|t|32|
|s|64|
|x|sem alinhamento|

Especifique os `attributes` e os caracteres de *alinhamento* como uma cadeia de caracteres sem espaço em branco. Os caracteres não diferenciam maiúsculas de minúsculas.

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](editbin-options.md)
