---
title: Marcações recomendadas para comentários de documentação (comentários de documentação do C++)
ms.date: 11/04/2016
ms.assetid: 6548e798-5235-4a38-9482-bdc7b88f40a9
ms.openlocfilehash: adb8440dc07f8f3e193b58be6782859fbb8413e4
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824348"
---
# <a name="recommended-tags-for-documentation-comments"></a>marcações recomendadas para comentários de documentação

O compilador MSVC irá processar comentários de documentação em seu código e cria um arquivo. XDC para cada compiland e xdcmake.exe processará os arquivos. XDC para um arquivo. XML. O processamento do arquivo .xml para criar a documentação é um detalhe que precisa ser implementado no site.

As marcas são processadas em constructos, como tipos e membros de tipo.

As marcas precisam preceder imediatamente tipos ou membros.

> [!NOTE]
>  Os comentários da documentação não podem ser aplicados a um namespace ou à definição fora de linha de propriedades e eventos; os comentários da documentação precisam ser aplicados às declarações na classe.

O compilador processará qualquer marca que seja um XML válido. As seguintes marcas fornecem as funcionalidades geralmente usadas na documentação do usuário:

||||
|-|-|-|
|[\<c>](c-visual-cpp.md)|[\<code>](code-visual-cpp.md)|[\<example>](example-visual-cpp.md)|
|[\<exception>](exception-visual-cpp.md)1|[\<include>](include-visual-cpp.md)1|[\<list>](list-visual-cpp.md)|
|[\<para>](para-visual-cpp.md)|[\<param>](param-visual-cpp.md)1|[\<paramref>](paramref-visual-cpp.md)1|
|[\<permission>](permission-visual-cpp.md)1|[\<remarks>](remarks-visual-cpp.md)|[\<returns>](returns-visual-cpp.md)|
|[\<see>](see-visual-cpp.md)1|[\<seealso>](seealso-visual-cpp.md)1|[\<summary>](summary-visual-cpp.md)|
|[\<value>](value-visual-cpp.md)|||

1. O compilador verifica a sintaxe.

Na versão atual, o compilador MSVC não suporta `<paramref>`, uma marca que é compatível com outros compiladores do Visual Studio. O Visual C++ poderá dar suporte a `<paramref>` em uma versão futura.

## <a name="see-also"></a>Consulte também

[Documentação XML](xml-documentation-visual-cpp.md)