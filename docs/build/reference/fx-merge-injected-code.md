---
title: "-Fx (mesclar código injetado) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCLWCECompilerTool.ExpandAttributedSource
- /Fx
- VC.Project.VCCLCompilerTool.ExpandAttributedSource
dev_langs: C++
helpviewer_keywords:
- Fx compiler option [C++]
- -Fx compiler option [C++]
- injected code
- merging injected code
- /Fx compiler option [C++]
ms.assetid: 14f0e301-3bab-45a3-bbdf-e7ce66f20560
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d00f54a3f7842108a7a9b144fe27058996d3c58b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fx-merge-injected-code"></a>/Fx (mesclar código injetado)
Gera uma cópia de cada arquivo de origem com o código injetado mesclado com a fonte.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Fx  
```  
  
## <a name="remarks"></a>Comentários  
 Para diferenciar um arquivo de origem mesclada de um arquivo de origem original, **/Fx** adiciona uma extensão. mrg entre o nome de arquivo e extensão de arquivo. Por exemplo, um arquivo chamado MyCode.cpp que contém o código atribuído e compilados com **/Fx** cria um arquivo chamado MyCode.mrg.cpp que contém o código a seguir:  
  
```  
//+++ Start Injected Code  
[no_injected_text(true)];      // Suppress injected text, it has   
                               // already been injected  
#pragma warning(disable: 4543) // Suppress warnings about skipping   
                               // injected text  
#pragma warning(disable: 4199) // Suppress warnings from attribute   
                               // providers  
//--- End Injected Code  
```  
  
 Em um arquivo. mrg, o código que foi inserido por causa de um atributo será delimitado da seguinte maneira:  
  
```  
//+++ Start Injected Code  
...  
//--- End Injected Code  
```  
  
 O [no_injected_text](../../windows/no-injected-text.md) atributo é inserido em um arquivo. mrg, que permite a compilação do arquivo. mrg sem texto sendo reinjected.  
  
 Você deve estar ciente de que o arquivo de origem. mrg deve ser uma representação do código-fonte inserida pelo compilador. O arquivo. mrg não pode compilar ou executar exatamente como o arquivo de origem.  
  
 Macros não são expandidas no arquivo. mrg.  
  
 Se seu programa inclui um arquivo de cabeçalho que usa código injetado, **/Fx** gera um. arquivo mrg.h para esse cabeçalho. **/FX** direta não inclui arquivos que não usam código injetado.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **arquivos de saída** página de propriedades.  
  
4.  Modificar o **expandir origem atribuída** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ExpandAttributedSource%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Arquivo de saída (/ F) opções](../../build/reference/output-file-f-options.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)