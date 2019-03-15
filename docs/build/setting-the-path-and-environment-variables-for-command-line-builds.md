---
title: Defina o caminho e variáveis de ambiente para compilações de linha de comando
ms.custom: conceptual
ms.date: 11/04/2016
f1_keywords:
- include
- Lib
- Path
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
ms.openlocfilehash: fed3360294bec724af09b87e5abd7c6bb22fa285
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57811063"
---
# <a name="set-the-path-and-environment-variables-for-command-line-builds"></a>Defina o caminho e variáveis de ambiente para compilações de linha de comando

As ferramentas de linha de comando de compilação do Visual C++ requerem diversas variáveis de ambiente que são personalizadas para a sua configuração de instalação e compilação. Quando uma carga de trabalho do C++ é instalada pelo instalador do Visual Studio, ele cria arquivos de comando personalizado ou arquivos em lotes, defina as variáveis de ambiente necessárias. O instalador, em seguida, usa esses arquivos de comando para criar atalhos para o menu Iniciar do Windows abrir uma janela de prompt de comando do desenvolvedor. Esses atalhos, definido as variáveis de ambiente para uma determinada configuração de compilação. Quando você quiser usar as ferramentas de linha de comando, você pode executar um destes atalhos ou você pode abrir uma janela de prompt de comando simples e, em seguida, execute um dos arquivos de comando personalizado para definir o ambiente de configuração de build por conta própria. Para obter mais informações, consulte [usar o conjunto de ferramentas da linha de comando MSVC](building-on-the-command-line.md).

As ferramentas de linha de comando do Visual C++ usam as variáveis de ambiente PATH, TMP, INCLUDE, LIB e LIBPATH e também usam outras variáveis de ambiente específicas para suas ferramentas instaladas, plataformas e SDKs. Até mesmo uma instalação simples do Visual Studio pode definir vinte ou mais variáveis de ambiente. Como os valores dessas variáveis de ambiente são específicos para sua instalação e sua opção de configuração de compilação e podem ser alterados por atualizações do produto, é altamente recomendável que você use um atalho de prompt de comando do desenvolvedor ou um do arquivos de comando personalizadas para defini-las, em vez de defini-las no ambiente do Windows por conta própria.

Para ver quais variáveis de ambiente são definidas por um atalho de prompt de comando do desenvolvedor, você pode usar o comando SET. Abra uma janela de prompt de comando simples e capturar a saída do comando SET de uma linha de base. Abra uma janela de prompt de comando do desenvolvedor e capturar a saída do comando SET para comparação. Uma ferramenta de comparação, como no IDE do Visual Studio pode ser útil para comparar as variáveis de ambiente e ver o que é definido pelo prompt de comando do desenvolvedor. Para obter informações sobre as variáveis de ambiente específicas usadas pelo compilador e vinculador, consulte [variáveis de ambiente CL](reference/cl-environment-variables.md).

> [!NOTE]
>  Várias ferramentas de linha de comando ou opções de ferramenta podem solicitar permissão de administrador. Se você tiver problemas de permissão quando você usá-los, é recomendável que você abre a janela de prompt de comando do desenvolvedor usando o **executar como administrador** opção. No Windows 10, com o botão direito para abrir o menu de atalho para a janela de prompt de comando e, em seguida, escolha **mais**, **executar como administrador**.

## <a name="see-also"></a>Consulte também

[Usar o conjunto de ferramentas do MSVC da linha de comando](building-on-the-command-line.md)<br/>
[Referência de vinculador MSVC](reference/linking.md)<br/>
[Opções do vinculador MSVC](reference/linker-options.md)<br/>
[Referência de compilador MSVC](reference/compiling-a-c-cpp-program.md)<br/>
[Opções do compilador MSVC](reference/compiler-options.md)
