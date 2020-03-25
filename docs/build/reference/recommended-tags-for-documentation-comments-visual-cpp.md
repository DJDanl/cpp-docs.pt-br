---
title: Marcas recomendadas para comentários deC++ documentação (comentários de documentação)
ms.date: 11/04/2016
ms.assetid: 6548e798-5235-4a38-9482-bdc7b88f40a9
ms.openlocfilehash: 4e0937b79012f65ba136e18ac81f014be23688f8
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80168857"
---
# <a name="recommended-tags-for-documentation-comments"></a>marcações recomendadas para comentários de documentação

O compilador MSVC processará os comentários de documentação em seu código e criará um arquivo. xdc para cada compiland, e xdcmake. exe processará os arquivos. xdc para um arquivo. xml. O processamento do arquivo .xml para criar a documentação é um detalhe que precisa ser implementado no site.

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

Na versão atual, o compilador do MSVC não oferece suporte a `<paramref>`, uma marca que é suportada por outros compiladores do Visual Studio. O Visual C++ poderá dar suporte a `<paramref>` em uma versão futura.

## <a name="see-also"></a>Confira também

[Documentação XML](xml-documentation-visual-cpp.md)
