---
title: Como habilitar o IntelliSense em projetos makefile | Microsoft Docs
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
ms.openlocfilehash: 1dda7b485c5aef7b6277da3141f293e16ac7523b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46433719"
---
# <a name="how-to-enable-intellisense-for-makefile-projects"></a>Como habilitar o IntelliSense para projetos de makefile

O IntelliSense não funciona corretamente no IDE de projetos makefile do Visual C++ quando algumas configurações de projeto ou opções do compilador estão definidas incorretamente. Use este procedimento para configurar os projetos makefile do Visual C++, de modo que o IntelliSense funcione quando os projetos makefile estiverem abertos no ambiente de desenvolvimento do Visual Studio.

### <a name="to-enable-intellisense-for-makefile-projects-in-the-ide"></a>Para habilitar o IntelliSense em projetos makefile no IDE

1. Abra a caixa de diálogo **Páginas de Propriedades**. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../ide/working-with-project-properties.md).

1. Expanda o nó **Propriedades de Configuração**.

1. Selecione a página de propriedades de **NMake** e, em seguida, modifique as propriedades em **IntelliSense**, conforme apropriado.

   - Defina a propriedade **Definições do Pré-processador** para definir os símbolos do pré-processador no projeto makefile. Confira [/D (Definições do Pré-processador)](../build/reference/d-preprocessor-definitions.md) para obter mais informações.

   - Defina a propriedade **Caminho de Pesquisa de Inclusão** para especificar a lista de diretórios que o compilador pesquisará para resolver as referências de arquivo passadas para as diretivas do pré-processador no projeto makefile. Confira [/I (Diretórios de Inclusão Adicionais)](../build/reference/i-additional-include-directories.md) para obter mais informações.

         For projects that are built using CL.EXE from a Command Window, set the **INCLUDE** environment variable to specify directories that the compiler will search to resolve file references that are passed to preprocessor directives in your makefile project.

   - Defina a propriedade **Inclusões Forçadas** para especificar quais arquivos de cabeçalho serão processados durante o build do projeto makefile. Confira [/FI (Nomear Arquivo de Inclusão Forçada)](../build/reference/fi-name-forced-include-file.md) para obter mais informações.

   - Defina a propriedade **Caminho de Pesquisa de Assembly** para especificar a lista de diretórios que o compilador pesquisará para resolver as referências a assemblies .NET no projeto. Confira [/AI (Especificar Diretórios de Metadados)](../build/reference/ai-specify-metadata-directories.md) para obter mais informações.

   - Defina a propriedade **Assemblies de Uso Forçado** para especificar quais assemblies .NET serão processados durante o build do projeto makefile. Confira [/FU (Nomear Arquivo #using Forçado)](../build/reference/fu-name-forced-hash-using-file.md) para obter mais informações.

   - Defina a propriedade **Opções Adicionais** para especificar as opções adicionais do compilador a serem usadas pelo IntelliSense durante a análise de arquivos do C++.

1. Clique em **OK** para fechar as páginas de propriedades.

1. Use o comando **Salvar Tudo** para salvar as configurações de projeto modificadas.

Na próxima vez que você abrir o projeto makefile no ambiente de desenvolvimento do Visual Studio, execute o comando **Limpar Solução** e, em seguida, o comando **Compilar Solução** no projeto makefile. O IntelliSense deverá funcionar corretamente no IDE.

## <a name="see-also"></a>Consulte também

[Usando o IntelliSense](/visualstudio/ide/using-intellisense)<br>
[Referência a NMAKE](../build/nmake-reference.md)<br>
[Como criar um projeto do C++ a partir do código existente](../ide/how-to-create-a-cpp-project-from-existing-code.md)