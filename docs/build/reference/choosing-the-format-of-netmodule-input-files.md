---
title: Escolhendo o formato de arquivos de entrada .netmodule
ms.date: 11/04/2016
ms.assetid: 4653d1bd-300f-4083-86f5-d1a06f44e61c
ms.openlocfilehash: ed492e47c09c05fc8ce2af3e19822cc5dde47b63
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57420044"
---
# <a name="choosing-the-format-of-netmodule-input-files"></a>Escolhendo o formato de arquivos de entrada .netmodule

Um arquivo. obj MSIL (compilado com [/clr](../../build/reference/clr-common-language-runtime-compilation.md)) também pode ser usado como um arquivo. netmodule.  arquivos. obj contêm metadados e símbolos nativa.  netmodules contém apenas metadados.

Você pode passar um arquivo. obj MSIL para qualquer compilador do Visual Studio por meio da opção de compilador /addmodule (mas lembre-se de que o arquivo. obj se torna parte do assembly resultante e deve ser enviado com o assembly).  Por exemplo, Visual c# e Visual Basic têm a opção de compilador /addmodule.

> [!NOTE]
>  Na maioria dos casos, você precisará passar para o vinculador o arquivo. obj da compilação que criou o módulo do .net.  Passar um arquivo de módulo MSIL. dll ou. netmodule para o vinculador pode resultar em das LNK1107.

arquivos. obj, juntamente com seus arquivos. h associado, que fazem referência a por meio de #include no código-fonte, permitem que os aplicativos do C++ consumir os tipos nativos no módulo, enquanto em um arquivo. netmodule, somente os tipos gerenciados podem ser consumidos por um aplicativo C++.  Se você tentar passar um arquivo. obj para #using, informações sobre tipos nativos não estarão disponíveis. #include. h arquivo do arquivo. obj em vez disso.

Outros compiladores do Visual Studio só podem consumir tipos gerenciados a partir de um módulo.

Use o seguinte para determinar se é necessário usar um. netmodule ou um arquivo. obj como entrada de módulo para o vinculador do Visual C++:

- Se você estiver compilando com um compilador do Visual Studio que não seja o Visual C++, produzir um. netmodule e usar o. netmodule como entrada para o vinculador.

- Se você estiver usando o compilador do Visual C++ para produzir os módulos e se os módulos serão usados para criar algo diferente de uma biblioteca, use os arquivos. obj gerados pelo compilador como entrada de módulo para o vinculador; Não use o arquivo. netmodule como entrada.

- Se seus módulos serão usados para criar uma biblioteca nativa (não gerenciado), use arquivos. obj como entrada de módulo para o vinculador e gerar um arquivo de biblioteca. lib.

- Se seus módulos serão usados para criar uma biblioteca gerenciada, e todas as entradas do módulo para o vinculador será verificáveis (produzido com /CLR: Safe), use arquivos. obj como entrada de módulo para o vinculador e gerar um. dll (assembly) ou arquivo de biblioteca. netmodule (módulo).

- Se seus módulos serão usados para criar uma biblioteca gerenciada, e se a entrada de módulos de um ou mais para o vinculador será produzida com /clr apenas, use arquivos. obj como entrada de módulo para o vinculador e gerar um arquivo. dll (assembly).  Se você quiser expor tipos gerenciados da biblioteca e se você também deseja a aplicativos de C++ para consumir os tipos nativos na biblioteca, sua biblioteca consistirá em arquivos. obj para os módulos de componente de bibliotecas (você também desejará enviar os arquivos. h para cada módulo para que eles podem ser referenciados com #include do código-fonte).

## <a name="see-also"></a>Consulte também

[Arquivos .netmodule como entrada do vinculador](../../build/reference/netmodule-files-as-linker-input.md)
