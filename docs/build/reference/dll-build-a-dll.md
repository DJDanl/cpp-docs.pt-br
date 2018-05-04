---
title: -DLL (compilar uma DLL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /dll
dev_langs:
- C++
helpviewer_keywords:
- -DLL linker option
- /DLL linker option [C++]
- exporting DLLs [C++], specifying exports
- DLLs [C++], building
- DLL linker option [C++]
ms.assetid: c7685aec-31d0-490f-9503-fb5171a23609
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1767ac9ef063ace2ee9d567dd9038519afababf8
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="dll-build-a-dll"></a>/DLL (compilar uma DLL)
```  
/DLL  
```  
  
## <a name="remarks"></a>Comentários  
 A opção /DLL cria uma DLL como o arquivo de saída principal. Uma DLL normalmente contém exportações que podem ser usadas por outro programa. Há três métodos para especificar exportações, listadas em ordem de recomendação de uso:  
  
1.  [dllexport](../../cpp/dllexport-dllimport.md) no código-fonte  
  
2.  Um [exportações](../../build/reference/exports.md) instrução em um arquivo. def  
  
3.  Um [/exportação](../../build/reference/export-exports-a-function.md) especificação em um comando LINK  
  
 Um programa pode usar mais de um método.  
  
 Outra maneira de criar uma DLL é com o **biblioteca** instrução de definição de módulo. As opções /BASE e /DLL juntos são equivalentes para o **biblioteca** instrução.  
  
 Não especifique essa opção dentro do ambiente de desenvolvimento. Essa opção é para uso somente na linha de comando. Essa opção é definida quando você cria um projeto de DLL com um Assistente de aplicativo.  
  
 Observe que se você criar sua biblioteca de importação em uma etapa preliminar, antes de criar o. dll, você deve passar o mesmo conjunto de arquivos de objeto ao criar o arquivo. dll, conforme passado ao criar a biblioteca de importação.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **propriedades de configuração** pasta.  
  
3.  Clique o **geral** página de propriedades.  
  
4.  Modificar o **tipo de configuração** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCPropertySheet.ConfigurationType%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)