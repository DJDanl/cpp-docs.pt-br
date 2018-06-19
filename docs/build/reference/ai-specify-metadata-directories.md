---
title: -AI (especificar diretórios de metadados) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.AdditionalUsingDirectories
- VC.Project.VCNMakeTool.AssemblySearchPath
- /AI
- VC.Project.VCCLWCECompilerTool.AdditionalUsingDirectories
dev_langs:
- C++
helpviewer_keywords:
- /AI compiler option [C++]
- AI compiler option [C++]
- -AI compiler option [C++]
ms.assetid: fb9c1846-504c-4a3b-bb39-c8696de32f6f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bde5c93c8a211bb0fc66028932a0a7d50415236d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32369426"
---
# <a name="ai-specify-metadata-directories"></a>/AI (especificar diretórios de metadados)
Especifica um diretório em que o compilador pesquisará para resolver referências de arquivo passadas para diretiva `#using`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/AIdirectory  
```  
  
## <a name="arguments"></a>Arguments  
 `directory`  
 O diretório ou o caminho para o compilador pesquisar.  
  
## <a name="remarks"></a>Comentários  
 Apenas um diretório pode ser passado para um **/AI** invocação. Especifique um **/AI** opção para cada caminho que você deseja que o compilador para pesquisar. Por exemplo, para adicionar C:\Project\Meta e C:\Common\Meta para o caminho de pesquisa de compilador `#using` diretivas, adicionar `/AI"C:\Project\Meta" /AI"C:\Common\Meta"` para a linha de comando do compilador ou adicionar cada diretório para o **adicionais #using diretórios** propriedade no Visual Studio.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  No painel de navegação, selecione **propriedades de configuração**, **C/C++**, **geral**.  
  
3.  Modificar o **adicionais #using diretórios** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalUsingDirectories%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [Diretiva #using](../../preprocessor/hash-using-directive-cpp.md)