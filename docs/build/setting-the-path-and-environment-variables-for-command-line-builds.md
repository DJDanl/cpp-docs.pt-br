---
title: Definir o caminho e as variáveis de ambiente para compilações de linha de comando | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: get-started-article
f1_keywords:
- include
- Lib
- Path
dev_langs:
- C++
helpviewer_keywords:
- environment variables [C++]
- VCVARS32.bat file
- cl.exe compiler [C++], environment variables
- LINK tool [C++], environment variables
- PATH reserved word
- INCLUDE reserved word
- LINK tool [C++], path
- LIB environment variable
- compiling source code [C++], from command line
- environment variables [C++], CL compiler
ms.assetid: 99389528-deb5-43b9-b99a-03c8773ebaf4
caps.latest.revision: 17
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 76fa1a14b4fd60f249ab015f6618e386bda7c86f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="set-the-path-and-environment-variables-for-command-line-builds"></a>Definir o caminho e as variáveis de ambiente para compilações de linha de comando

Ferramentas de linha de comando de compilação do Visual C++ exigem diversas variáveis de ambiente que são personalizados para a sua configuração de compilação e de instalação. Quando uma carga de trabalho do C++ é instalada o [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] instalador, ele cria arquivos de comando personalizado ou arquivos em lotes, definem as variáveis de ambiente necessário. O instalador usa esses arquivos de comando para criar atalhos do menu Iniciar do Windows abrir uma janela de prompt de comando do desenvolvedor. Estes atalhos definir as variáveis de ambiente para uma determinada configuração de compilação. Quando você quiser usar as ferramentas de linha de comando, você pode executar um desses atalhos, ou você pode abrir uma janela de prompt de comando simples e, em seguida, execute um dos arquivos de comando personalizado para definir o ambiente de configuração de compilação por conta própria. Para obter mais informações, consulte [compilar código C/C++ na linha de comando](building-on-the-command-line.md).  
  
As ferramentas de linha de comando do Visual C++ usam as variáveis de ambiente PATH, TMP, INCLUDE, LIB e LIBPATH e também usam outras variáveis de ambiente específicas a ferramentas instaladas, plataformas e SDKs. Até mesmo um simples [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] instalação pode definir vinte ou mais variáveis de ambiente. Como os valores dessas variáveis de ambiente são específicos para sua instalação e sua opção de configuração de compilação e podem ser alterados por atualizações de produto, é altamente recomendável que você use um atalho de prompt de comando do desenvolvedor ou uma da arquivos de comando personalizado para defini-las, em vez de defini-las no ambiente do Windows por conta própria. 

Para ver quais variáveis de ambiente são definidas por um atalho do prompt de comando de desenvolvedor, você pode usar o comando SET. Abra uma janela de prompt de comando simples e capturar a saída do comando SET de uma linha de base. Abra uma janela de prompt de comando do desenvolvedor e capturar a saída do comando SET para comparação. Uma ferramenta de comparação, como a embutido no IDE do Visual Studio pode ser útil para comparar as variáveis de ambiente e ver o que é definido pelo prompt de comando do desenvolvedor. Para obter informações sobre as variáveis de ambiente específico usado pelo compilador e vinculador, consulte [variáveis de ambiente CL](../build/reference/cl-environment-variables.md) e [variáveis de ambiente LINK](../build/reference/link-environment-variables.md).  
  
> [!NOTE]
>  Várias ferramentas de linha de comando ou opções da ferramenta podem exigir permissões de administrador. Se você tiver problemas de permissão quando você usá-los, é recomendável que você abrir a janela de prompt de comando do desenvolvedor usando o **executar como administrador** opção. No Windows 10, com o botão direito para abrir o menu de atalho para a janela de prompt de comando, em seguida, escolha **mais**, **executar como administrador**.  
  
## <a name="see-also"></a>Consulte também  

[Compilar o código C/C++ na linha de comando](../build/building-on-the-command-line.md)   
[Vinculação](../build/reference/linking.md)   
[Opções do vinculador](../build/reference/linker-options.md)   
[Compilando um programa C/C++](../build/reference/compiling-a-c-cpp-program.md)   
[Opções do Compilador](../build/reference/compiler-options.md)