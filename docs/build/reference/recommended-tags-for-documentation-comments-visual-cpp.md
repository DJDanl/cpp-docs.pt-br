---
title: Tags recomendadas para comentários de documentação (comentários de documentação C++)
ms.date: 11/04/2016
ms.assetid: 6548e798-5235-4a38-9482-bdc7b88f40a9
ms.openlocfilehash: 1648d0eb019a3aad25641d7f6a7edd1ba26acf7e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81336165"
---
# <a name="recommended-tags-for-documentation-comments"></a>Marcas recomendadas para comentários de documentação

O compilador MSVC processará comentários de documentação em seu código e criará um arquivo .xDC para cada compilação, e xdcmake.exe processará os arquivos .xdc para um arquivo .xml. O processamento do arquivo .xml para criar a documentação é um detalhe que precisa ser implementado no site.

As marcas são processadas em constructos, como tipos e membros de tipo.

As marcas precisam preceder imediatamente tipos ou membros.

> [!NOTE]
> Os comentários da documentação não podem ser aplicados a um namespace ou à definição fora de linha de propriedades e eventos; os comentários da documentação precisam ser aplicados às declarações na classe.

O compilador processará qualquer marca que seja um XML válido. As seguintes marcas fornecem as funcionalidades geralmente usadas na documentação do usuário:

||||
|-|-|-|
|[\<c>](c-visual-cpp.md)|[\<código>](code-visual-cpp.md)|[\<exemplo>](example-visual-cpp.md)|
|exceção>1 [ \< ](exception-visual-cpp.md)|incluem>1 [ \< ](include-visual-cpp.md)|[\<lista>](list-visual-cpp.md)|
|[\<para>](para-visual-cpp.md)|param>1 [ \< ](param-visual-cpp.md)|paramref>1 [ \< ](paramref-visual-cpp.md)|
|permissão>1 [ \< ](permission-visual-cpp.md)|[\<observações>](remarks-visual-cpp.md)|[\<retorna>](returns-visual-cpp.md)|
|ver>1 [ \< ](see-visual-cpp.md)|vejatambém>1 [ \< ](seealso-visual-cpp.md)|[\<>de resumo](summary-visual-cpp.md)|
|[\<>de valores](value-visual-cpp.md)|||

1. O compilador verifica a sintaxe.

Na versão atual, o compilador MSVC `<paramref>`não suporta , uma tag que é suportada por outros compiladores do Visual Studio. O Visual C++ poderá dar suporte a `<paramref>` em uma versão futura.

## <a name="see-also"></a>Confira também

[Documentação XML](xml-documentation-visual-cpp.md)
