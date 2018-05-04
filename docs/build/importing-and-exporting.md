---
title: Importando e exportando | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- DLLs [C++], importing
- exporting DLLs [C++]
- importing DLLs [C++]
- DLLs [C++], exporting from
- __declspec(dllimport) keyword [C++]
ms.assetid: 7c44c2aa-2117-4cec-9615-a65bfd3f8f7b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9ee3ffe33dbb99f1f9b4124e2695d2e56dbe5544
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="importing-and-exporting"></a>Importando e exportando
Você pode importar símbolos públicos para um aplicativo ou exportar funções de uma DLL usando dois métodos:  
  
-   Usar um arquivo de definição (. def) do módulo ao criar a DLL  
  
-   Use as palavras-chave **__declspec(dllimport)** ou **dllexport** em uma definição de função no aplicativo principal  
  
## <a name="using-a-def-file"></a>Usando um arquivo. def  
 Um arquivo de definição de módulo (. def) é um arquivo de texto que contém uma ou mais declarações de módulo que descrevem vários atributos de uma DLL. Se você não usar **__declspec(dllimport)** ou **dllexport** para exportar as funções da DLL, a DLL requer um arquivo. def.  
  
 Você pode usar arquivos. def para [importar para um aplicativo](../build/importing-using-def-files.md) ou [exportar de uma DLL](../build/exporting-from-a-dll-using-def-files.md).  
  
## <a name="using-declspec"></a>Usando declspec  
 Usos do Visual C++ **__declspec(dllimport)** e **dllexport** para substituir o **__export** palavra-chave usado anteriormente em versões de 16 bits do Visual C++.  
  
 Você não precisa usar **__declspec(dllimport)** para seu código compilar corretamente, mas isso permite que o compilador gere código melhor. O compilador é capaz de gerar um código melhor porque ele pode determinar se existe uma função em uma DLL ou não, que permite que o compilador gerar o código que ignora um nível de erro que normalmente seriam presente em uma chamada de função que atravessou um limite DLL. No entanto, você deve usar **__declspec(dllimport)** importar variáveis usadas em uma DLL.  
  
 Na seção de exportação de arquivo. def adequado, **dllexport** não é necessária. **dllexport** foi adicionado para fornecer uma maneira fácil de exportar as funções de um arquivo .exe ou. dll sem usar um arquivo. def.  
  
 O formato de arquivo executável portátil do Win32 foi projetado para minimizar o número de páginas que deve ser tocada para corrigir importações. Para fazer isso, ele coloca todos os endereços de importação para qualquer programa no lugar de uma chamada de tabela de endereço importar. Isso permite que o carregador de modificar somente uma ou duas páginas ao acessar esses importações.  
  
## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?  
  
-   [Importar para um aplicativo](../build/importing-into-an-application-using-declspec-dllimport.md)  
  
-   [Exportação de uma DLL](../build/exporting-from-a-dll.md)  
  
## <a name="see-also"></a>Consulte também  
 [DLLs no Visual C++](../build/dlls-in-visual-cpp.md)