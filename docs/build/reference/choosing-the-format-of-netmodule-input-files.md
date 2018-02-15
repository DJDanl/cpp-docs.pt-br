---
title: Escolher o formato de. netmodule arquivos de entrada | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 4653d1bd-300f-4083-86f5-d1a06f44e61c
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c6b83039a054e19e62cbbe87befbe08dd7997e51
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="choosing-the-format-of-netmodule-input-files"></a>Escolhendo o formato de arquivos de entrada .netmodule
Um arquivo. obj MSIL (compilado com [/clr](../../build/reference/clr-common-language-runtime-compilation.md)) também pode ser usado como um arquivo. netmodule.  arquivos. obj contêm metadados e símbolos nativo.  . netmodules só contêm metadados.  
  
 Você pode passar um arquivo. obj MSIL para qualquer outro compilador do Visual Studio por meio da opção de compilador /addmodule (mas lembre-se de que o arquivo. obj se torna parte do assembly resultante e deve ser enviado com o assembly).  Por exemplo, Visual c# e Visual Basic têm a opção de compilador /addmodule.  
  
> [!NOTE]
>  Na maioria dos casos, você precisará passar para o vinculador do arquivo. obj de compilação que criou o módulo de .net.  Passar um arquivo. dll ou. netmodule do módulo MSIL ao vinculador pode resultar em LNK1107.  
  
 arquivos. obj, junto com seus arquivos. h associado, que fazem referência a por meio de #include na fonte, permitir que os aplicativos do C++ consumir os tipos nativos no módulo, enquanto em um arquivo. netmodule, somente os tipos gerenciados podem ser consumidos por um aplicativo em C++.  Se você tentar passar um arquivo. obj para #using, informações sobre tipos nativos não estarão disponíveis. #include. h arquivo do arquivo. obj em vez disso.  
  
 Outros compiladores do Visual Studio só podem consumir tipos gerenciados de um módulo.  
  
 Use o seguinte para determinar se você precisa usar um. netmodule ou um arquivo. obj como entrada de módulo para o vinculador do Visual C++:  
  
-   Se você estiver criando com um compilador do Visual Studio que não seja do Visual C++, produzir um. netmodule e usar o. netmodule como entrada para o vinculador.  
  
-   Se você estiver usando o compilador do Visual C++ para produzir os módulos e se os módulos serão usados para criar algo diferente de uma biblioteca, use os arquivos. obj produzidos pelo compilador como entrada de módulo para o vinculador; Não use o arquivo. netmodule como entrada.  
  
-   Se seus módulos serão usados para criar uma biblioteca nativa (não gerenciada), use arquivos. obj como entrada de módulo para o vinculador e gerar um arquivo de biblioteca. lib.  
  
-   Se os seus módulos serão usados para criar uma biblioteca gerenciada e se todas as entradas de módulo para o vinculador serão verificáveis (produzido com /CLR: Safe), use arquivos. obj como entrada de módulo para o vinculador e gerar um. dll (assembly) ou arquivo de biblioteca. netmodule (módulo).  
  
-   Se os seus módulos serão usados para criar uma biblioteca gerenciada e uma ou mais entradas de módulos para o vinculador serão produzida com /clr apenas, use arquivos. obj como entrada de módulo para o vinculador e gerar um arquivo. dll (assembly).  Se você deseja expor os tipos gerenciados da biblioteca e se você também deseja aplicativos C++ para consumir os tipos nativos na biblioteca, a biblioteca consistirá os arquivos. obj para os módulos de componente de bibliotecas (você também deve enviar os arquivos. h para cada módulo para que possam ser referenciados com #include do código-fonte).  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos .netmodule como entrada do vinculador](../../build/reference/netmodule-files-as-linker-input.md)