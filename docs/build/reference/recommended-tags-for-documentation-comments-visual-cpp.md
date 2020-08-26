---
title: Marcas recomendadas para comentários de documentação (comentários de documentação do C++)
ms.date: 11/04/2016
ms.assetid: 6548e798-5235-4a38-9482-bdc7b88f40a9
ms.openlocfilehash: 9f41e450215e2bce02dbaf66910fc2fc1a131a99
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88836849"
---
# <a name="recommended-tags-for-documentation-comments"></a>Marcas recomendadas para comentários de documentação

O compilador MSVC processará os comentários de documentação em seu código e criará um arquivo. xdc para cada compiland, e xdcmake.exe processará os arquivos. xdc para um arquivo. xml. O processamento do arquivo .xml para criar a documentação é um detalhe que precisa ser implementado no site.

As marcas são processadas em constructos, como tipos e membros de tipo.

As marcas precisam preceder imediatamente tipos ou membros.

> [!NOTE]
> Os comentários da documentação não podem ser aplicados a um namespace ou à definição fora de linha de propriedades e eventos; os comentários da documentação precisam ser aplicados às declarações na classe.

O compilador processará qualquer marca que seja um XML válido. As seguintes marcas fornecem as funcionalidades geralmente usadas na documentação do usuário:

[`<c>`](c-visual-cpp.md)
[`<code>`](code-visual-cpp.md)
[`<example>`](example-visual-cpp.md)
[`<exception>`](exception-visual-cpp.md)<sup>1</sup> 
 1 [`<include>`](include-visual-cpp.md) <sup>1</sup> 
 [`<list>`](list-visual-cpp.md) 1 
 [`<para>`](para-visual-cpp.md) 
 [`<param>`](param-visual-cpp.md) <sup>1</sup> 
 1 [`<paramref>`](paramref-visual-cpp.md) <sup>1</sup> 
 1 [`<permission>`](permission-visual-cpp.md) <sup>1</sup> 
 [`<remarks>`](remarks-visual-cpp.md) 1 
 [`<returns>`](returns-visual-cpp.md) 
 [`<see>`](see-visual-cpp.md) <sup>1</sup> 
 1 [`<seealso>`](seealso-visual-cpp.md) <sup>1</sup>
[`<summary>`](summary-visual-cpp.md)
[`<value>`](value-visual-cpp.md)

1. O compilador verifica a sintaxe.

Na versão atual, o compilador do MSVC não oferece suporte a `<paramref>` uma marca que é suportada por outros compiladores do Visual Studio. O Visual C++ poderá dar suporte a `<paramref>` em uma versão futura.

## <a name="see-also"></a>Confira também

[Documentação XML](xml-documentation-visual-cpp.md)
