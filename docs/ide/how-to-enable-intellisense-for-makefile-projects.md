---
title: 'Como: ativar o IntelliSense para projetos Makefile | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- VC.Project.VCNMakeTool.IntelliSense
dev_langs:
- C++
helpviewer_keywords:
- Makefile projects, IntelliSense
- IntelliSense, Makefile projects
ms.assetid: 9443f453-f18f-4f12-a9a1-ef9dbf8b188f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9de79d56c6e8b6e496c0e7988ada07ed7595ea70
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="how-to-enable-intellisense-for-makefile-projects"></a>Como habilitar o IntelliSense para projetos de makefile
Falha do IntelliSense para operar no IDE para projetos makefile do Visual C++ quando determinado projeto configurações ou opções do compilador, está configurada incorretamente. Use este procedimento para configurar os projetos makefile do Visual C++, para que o IntelliSense funciona quando os projetos makefile estiverem abertos no ambiente de desenvolvimento do Visual Studio.  
  
### <a name="to-enable-intellisense-for-makefile-projects-in-the-ide"></a>Para habilitar o IntelliSense para projetos de makefile no IDE  
  
1.  Abra o **páginas de propriedade** caixa de diálogo. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../ide/working-with-project-properties.md).  
  
2.  Expanda o **propriedades de configuração** nó.  
  
3.  Selecione o **NMake** propriedade página e, em seguida, modificar propriedades em **IntelliSense** conforme apropriado.  
  
    -   Definir o **definições de pré-processador** propriedade para definir qualquer símbolo de pré-processador em seu projeto makefile. Consulte [/D (definições de pré-processador)](../build/reference/d-preprocessor-definitions.md), para obter mais informações.  
  
    -   Definir o **incluir o caminho de pesquisa** propriedade para especificar a lista de diretórios que o compilador pesquisará para resolver referências de arquivo que são passadas para as diretivas de pré-processador em seu projeto makefile. Consulte [/I (diretórios de inclusão adicionais)](../build/reference/i-additional-include-directories.md), para obter mais informações.  
  
         Para projetos que são criados usando CL. EXE em uma janela de comando, defina o **incluir** variável de ambiente para especificar diretórios pesquisará o compilador para resolver referências de arquivo que são passadas para as diretivas de pré-processador em seu projeto makefile.  
  
    -   Definir o **forçado inclui** propriedade para especificar o cabeçalho de arquivos para o processo ao compilar seu projeto makefile. Consulte [/FI (nome forçado incluir arquivo)](../build/reference/fi-name-forced-include-file.md), para obter mais informações.  
  
    -   Definir o **caminho de pesquisa de Assembly** propriedade para especificar a lista de diretórios que o compilador pesquisará para resolver referências a assemblies .NET em seu projeto. Consulte [/AI (especificar diretórios de metadados)](../build/reference/ai-specify-metadata-directories.md), para obter mais informações.  
  
    -   Definir o **Assemblies de uso forçado** propriedade para especificar quais assemblies do .NET para processar ao compilar seu projeto makefile. Consulte [/FU (nome forçado #using arquivo)](../build/reference/fu-name-forced-hash-using-file.md), para obter mais informações.  
  
    -   Definir o **opções adicionais** propriedade para especificar opções de compilador adicional a ser usado pelo Intellisense ao analisar arquivos C++.  
  
4.  Clique em **Okey** para fechar as páginas de propriedades.  
  
5.  Use o **Salvar tudo** comando para salvar as configurações de projeto modificado.  
  
 Na próxima vez que você abra seu projeto makefile no ambiente de desenvolvimento do Visual Studio, execute o **limpar solução** comando e, em seguida, o **compilar solução** comando no seu projeto makefile. IntelliSense deve funcionar corretamente no IDE.  
  
## <a name="see-also"></a>Consulte também  
 [Usando o IntelliSense](/visualstudio/ide/using-intellisense)   
 [Referência NMAKE](../build/nmake-reference.md)   
 [Como criar um projeto do C++ a partir do código existente](../ide/how-to-create-a-cpp-project-from-existing-code.md)