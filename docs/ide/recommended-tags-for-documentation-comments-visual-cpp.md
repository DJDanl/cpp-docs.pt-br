---
title: "Marcas recomendadas para comentários da documentação (Visual C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 6548e798-5235-4a38-9482-bdc7b88f40a9
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5c1b0e762ec2167a988e8e18f3dce932214716c9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="recommended-tags-for-documentation-comments-visual-c"></a>marcações recomendadas para comentários da documentação (Visual C++)
O compilador do Visual C++ irá processar comentários de documentação em seu código e cria um arquivo. XDC para cada compiland e xdcmake.exe processará os arquivos. XDC para um arquivo. XML. Processando o arquivo. XML para criar documentação é um detalhe de que precisa ser implementada em seu site.  
  
 Marcas são processadas em construções, como tipos e membros de tipos.  
  
 Marcas devem preceder imediatamente tipos ou membros.  
  
> [!NOTE]
>  Comentários de documentação não podem ser aplicados a um namespace ou na fora da definição de linha para propriedades e eventos. comentários de documentação devem em declarações de classe.  
  
 O compilador processará qualquer marca que seja um XML válido. As seguintes marcas fornecem funcionalidades comumente usadas na documentação do usuário:  
  
||||  
|-|-|-|  
|[\<c>](../ide/c-visual-cpp.md)|[\<code>](../ide/code-visual-cpp.md)|[\<example>](../ide/example-visual-cpp.md)|  
|[\<exceção >](../ide/exception-visual-cpp.md)1|[\<incluir >](../ide/include-visual-cpp.md)1|[\<list>](../ide/list-visual-cpp.md)|  
|[\<para>](../ide/para-visual-cpp.md)|[\<param >](../ide/param-visual-cpp.md)1|[\<paramref >](../ide/paramref-visual-cpp.md)1|  
|[\<permissão >](../ide/permission-visual-cpp.md)1|[\<remarks>](../ide/remarks-visual-cpp.md)|[\<returns>](../ide/returns-visual-cpp.md)|  
|[\<Consulte >](../ide/see-visual-cpp.md)1|[\<seealso >](../ide/seealso-visual-cpp.md)1|[\<summary>](../ide/summary-visual-cpp.md)|  
|[\<value>](../ide/value-visual-cpp.md)|||  
  
 1. Compilador verifica a sintaxe.  
  
 Na versão atual, o compilador do Visual C++ não suporta `<paramref>`, uma marca que tem suporte por outros compiladores do Visual Studio. Visual C++ podem suportar `<paramref>` em uma versão futura.  
  
## <a name="see-also"></a>Consulte também  
 [Documentação XML](../ide/xml-documentation-visual-cpp.md)