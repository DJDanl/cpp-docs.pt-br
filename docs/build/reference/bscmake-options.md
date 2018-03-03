---
title: "Opções de BSCMAKE | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCBscMakeTool.OutputFile
- VC.Project.VCBscMakeTool.SuppressStartupBanner
- VC.Project.VCBscMakeTool.PreserveSBR
dev_langs:
- C++
helpviewer_keywords:
- /v BSCMAKE option
- Iu BSCMAKE option
- browse information files (.bsc), content
- /Er BSCMAKE option
- NOLOGO BSCMAKE option
- /s BSCMAKE option
- /Ei BSCMAKE option
- /o BSCMAKE option
- /NOLOGO BSCMAKE option
- /Iu BSCMAKE option
- s BSCMAKE option (/s)
- /Em BSCMAKE option
- Em BSCMAKE option
- Es BSCMAKE option
- files [C++], BSCMAKE
- Er BSCMAKE option
- BSCMAKE, options for controlling files
- controlling BSCMAKE options
- El BSCMAKE option
- /El BSCMAKE option
- /Es BSCMAKE option
- Ei BSCMAKE option
ms.assetid: fa2f1e06-c684-41cf-80dd-6a554835ebd2
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 46c258a5591615bb277823ccc5261fade3c5e2af
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="bscmake-options"></a>Opções de BSCMAKE
Esta seção descreve as opções disponíveis para controlar BSCMAKE. Várias opções controlam o conteúdo do arquivo de informações de procura, excluindo ou incluindo certas informações. As opções de exclusão podem permitir BSCMAKE a execução mais rápida e podem resultar em um arquivo. bsc menor. Nomes de opção diferenciam maiusculas de minúsculas (exceto para **/Help** e **/NOLOGO**).  
  
 Somente **/NOLOGO** e **/o** estão disponíveis no ambiente de desenvolvimento do Visual Studio.  Consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md) para obter informações sobre como acessar páginas de propriedades do projeto.  
  
 /Ei ( `filename`...)  
 Exclui o conteúdo dos arquivos de inclusão especificado do arquivo de informações de procura. Para especificar vários arquivos, separe os nomes com um espaço e colocar a lista entre parênteses. Parênteses não são necessários se você especificar apenas um `filename`. Use **/Ei** juntamente com o **/Es** opção para excluir arquivos que não são excluídos pelo **/Es**.  
  
 /El  
 Exclui os símbolos locais. O padrão é incluir símbolos locais. Para obter mais informações sobre símbolos locais, consulte [criando um arquivo. SBR](../../build/reference/creating-an-dot-sbr-file.md).  
  
 /Em  
 Exclui os símbolos no corpo de macros. Use **/Em** para incluir apenas os nomes das macros no arquivo de informações de procura. O padrão é incluir os nomes de macro e o resultado de expansões de macro.  
  
 /ER ( `symbol`...)  
 Exclui os símbolos especificados do arquivo de informações de procura. Para especificar vários nomes de símbolos, separe os nomes com um espaço e colocar a lista entre parênteses. Parênteses não são necessários se você especificar apenas um `symbol`.  
  
 /Es  
 Exclui do arquivo de informações de procura todos os arquivos de inclusão especificado com um caminho absoluto ou localizado em um caminho absoluto especificado na variável de ambiente INCLUDE. (Normalmente, esses são do sistema incluem arquivos, que contêm muitas informações que talvez não seja necessário em seu arquivo de informações de navegação.) Essa opção não exclui arquivos especificados sem um caminho ou com caminhos relativos ou arquivos localizados em um caminho relativo no incluir. Você pode usar o **/Ei** juntamente com **/Es** para excluir arquivos que **/Es** não excluir. Se você deseja excluir somente alguns dos arquivos que **/Es** exclui, use **/Ei** em vez de **/Es** e lista os arquivos que você deseja excluir.  
  
 /errorreport: [Nenhum &#124; prompt &#124; fila &#124; enviar]  
 Permite que você enviar à Microsoft informações sobre erros internos no bscmake.exe.  
  
 Para obter mais informações sobre **/errorreport**, consulte [/errorReport (relatório de erros do compilador interno)](../../build/reference/errorreport-report-internal-compiler-errors.md).  
  
 /HELP  
 Exibe um resumo da sintaxe de linha de comando BSCMAKE.  
  
 /IU  
 Inclui os símbolos não referenciados. Por padrão, BSCMAKE não registra qualquer símbolos que são definidos, mas não referenciados. Se um arquivo. SBR tem sido compactado, essa opção não tem efeito para esse arquivo de entrada porque o compilador já removeu os símbolos não referenciados.  
  
 /n  
 Força uma compilação não incrementais. Use  **/n**  para forçar uma compilação completa do arquivo de informações de procura se existe ou não um arquivo. bsc e para impedir que arquivos. SBR sendo truncado. Consulte [como BSCMAKE compila um arquivo. bsc](../../build/reference/how-bscmake-builds-a-dot-bsc-file.md).  
  
 /NOLOGO  
 Suprime a mensagem de direitos autorais BSCMAKE.  
  
 /o`filename`  
 Especifica um nome para o arquivo de informações de procura. Por padrão, o BSCMAKE fornece o arquivo de informações de procura o nome base do arquivo. SBR primeiro e uma extensão. bsc.  
  
 /S ( `filename`...)  
 Informa BSCMAKE para processar o arquivo de inclusão especificado na primeira vez que ela for encontrada e excluí-lo caso contrário. Use esta opção para economizar tempo de processamento quando um arquivo (como um cabeçalho, ou. h, arquivo para um. c ou. cpp origem) está incluído em vários arquivos de origem, mas é alterado pelo diretivas de pré-processamento cada vez. Você talvez queira usar essa opção se um arquivo é alterado de maneiras que não são importantes para o arquivo de informações de procura que você está criando. Para especificar vários arquivos, separe os nomes com um espaço e colocar a lista entre parênteses. Parênteses não são necessários se você especificar apenas um `filename`. Se você deseja excluir o arquivo sempre que ele é incluído, use o **/Ei** ou **/Es** opção.  
  
 /v  
 Fornece a saída detalhada, que inclui o nome de cada arquivo. SBR processado e informações sobre o BSCMAKE completa executar.  
  
 /?  
 Exibe um resumo da sintaxe de linha de comando BSCMAKE.  
  
 A linha de comando a seguir informa BSCMAKE fazer uma compilação completa do MAIN.bsc de três arquivos. SBR. Ele também explica BSCMAKE para excluir instâncias duplicadas de TOOLBOX.h:  
  
```  
BSCMAKE /n /S toolbox.h /o main.bsc file1.sbr file2.sbr file3.sbr  
```  
  
## <a name="see-also"></a>Consulte também  
 [Referência de BSCMAKE](../../build/reference/bscmake-reference.md)