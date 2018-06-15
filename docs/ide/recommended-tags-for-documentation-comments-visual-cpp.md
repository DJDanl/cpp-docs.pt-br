---
title: Marcas recomendadas para comentários da documentação (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 6548e798-5235-4a38-9482-bdc7b88f40a9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1b25ad029a59c4b23bcab093b3742f16f7ca9175
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "33328614"
---
# <a name="recommended-tags-for-documentation-comments-visual-c"></a>marcações recomendadas para comentários da documentação (Visual C++)
O compilador do Visual C++ processará os comentários da documentação no código e criará um arquivo .xdc para cada compiland, e xdcmake.exe processará os arquivos .xdc em um arquivo .xml. O processamento do arquivo .xml para criar a documentação é um detalhe que precisa ser implementado no site.  
  
 As marcas são processadas em constructos, como tipos e membros de tipo.  
  
 As marcas precisam preceder imediatamente tipos ou membros.  
  
> [!NOTE]
>  Os comentários da documentação não podem ser aplicados a um namespace ou à definição fora de linha de propriedades e eventos; os comentários da documentação precisam ser aplicados às declarações na classe.  
  
 O compilador processará qualquer marca que seja um XML válido. As seguintes marcas fornecem as funcionalidades geralmente usadas na documentação do usuário:  
  
||||  
|-|-|-|  
|[\<c>](../ide/c-visual-cpp.md)|[\<code>](../ide/code-visual-cpp.md)|[\<example>](../ide/example-visual-cpp.md)|  
|[\<exception>](../ide/exception-visual-cpp.md)1|[\<include>](../ide/include-visual-cpp.md)1|[\<list>](../ide/list-visual-cpp.md)|  
|[\<para>](../ide/para-visual-cpp.md)|[\<param>](../ide/param-visual-cpp.md)1|[\<paramref>](../ide/paramref-visual-cpp.md)1|  
|[\<permission>](../ide/permission-visual-cpp.md)1|[\<remarks>](../ide/remarks-visual-cpp.md)|[\<returns>](../ide/returns-visual-cpp.md)|  
|[\<see>](../ide/see-visual-cpp.md)1|[\<seealso>](../ide/seealso-visual-cpp.md)1|[\<summary>](../ide/summary-visual-cpp.md)|  
|[\<value>](../ide/value-visual-cpp.md)|||  
  
 1. O compilador verifica a sintaxe.  
  
 Na versão atual, o compilador do Visual C++ não dá suporte a `<paramref>`, uma marcação compatível com outros compiladores do Visual Studio. O Visual C++ poderá dar suporte a `<paramref>` em uma versão futura.  
  
## <a name="see-also"></a>Consulte também  
 [Documentação XML](../ide/xml-documentation-visual-cpp.md)