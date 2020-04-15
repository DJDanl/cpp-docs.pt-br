---
title: Escolhendo o formato de arquivos de entrada .netmodule
ms.date: 11/04/2016
ms.assetid: 4653d1bd-300f-4083-86f5-d1a06f44e61c
ms.openlocfilehash: b4d4b80e4b9195d184b9d97cea67bbaaa3d7d843
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320568"
---
# <a name="choosing-the-format-of-netmodule-input-files"></a>Escolhendo o formato de arquivos de entrada .netmodule

Um arquivo MSIL .obj (compilado com [/clr)](clr-common-language-runtime-compilation.md)também pode ser usado como um arquivo .netmodule.  Os arquivos .obj contêm metadados e símbolos nativos.  .netmodules contêm apenas metadados.

Você pode passar um arquivo MSIL .obj para qualquer outro compilador visual studio através da opção /addmodule compilador (mas esteja ciente de que o arquivo .obj torna-se parte do conjunto resultante e deve ser enviado com o conjunto).  Por exemplo, Visual C# e Visual Basic têm a opção compilador /addmodule.

> [!NOTE]
> Na maioria dos casos, você precisará passar para o linker o arquivo .obj a partir da compilação que criou o módulo .net.  Passar um arquivo de módulo MSIL .dll ou .netmodule para o linker pode resultar em LNK1107.

Os arquivos .obj, juntamente com seus arquivos .h associados, que você faz referência via #include na fonte, permitem que os aplicativos C++ consumam os tipos nativos no módulo, enquanto em um arquivo .netmodule, apenas os tipos gerenciados podem ser consumidos por um aplicativo C++.  Se você tentar passar um arquivo .obj para #using, informações sobre tipos nativos não estarão disponíveis; #include o arquivo .obj .h.

Outros compiladores do Visual Studio só podem consumir tipos gerenciados a partir de um módulo.

Use o seguinte para determinar se você precisa usar um .netmodule ou um arquivo .obj como entrada de módulo no linker MSVC:

- Se você estiver construindo com um compilador Visual Studio diferente do Visual C++, produza um módulo .net e use o módulo .net como entrada para o linker.

- Se você estiver usando o compilador MSVC para produzir módulos e se o módulo(s) for usado para construir algo diferente de uma biblioteca, use os arquivos .obj produzidos pelo compilador como entrada de módulo para o linker; não use o arquivo .netmodule como entrada.

- Se seus módulos forem usados para construir uma biblioteca nativa (não gerenciada), use arquivos .obj como entrada de módulo para o linker e gerar um arquivo de biblioteca .lib.

- Se seus módulos forem usados para construir uma biblioteca gerenciada e se toda a entrada do módulo no linker for verificável (produzida com /clr:safe), use arquivos .obj como entrada de módulo para o linker e gerará um arquivo de biblioteca .dll (assembly) ou .netmodule (módulo).

- Se seus módulos forem usados para construir uma biblioteca gerenciada e se um ou mais módulos de entrada no linker forem produzidos com apenas /clr, use arquivos .obj como entrada de módulo para o linker e gerará um .dll (conjunto).  Se você quiser expor tipos gerenciados da biblioteca e se você também quiser que os aplicativos C++ consumam os tipos nativos na biblioteca, sua biblioteca consistirá nos arquivos .obj para os módulos componentes bibliotecas (você também vai querer enviar os arquivos .h para cada módulo, para que eles possam ser referenciados com #include do código-fonte).

## <a name="see-also"></a>Confira também

[Arquivos .netmodule como entrada do vinculador](netmodule-files-as-linker-input.md)
