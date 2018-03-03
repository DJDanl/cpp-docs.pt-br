---
title: "-/FU (nome forçado #using arquivo) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCLCompilerTool.ForcedUsingFiles
- /FU
- VC.Project.VCNMakeTool.ForcedUsingAssemblies
dev_langs:
- C++
helpviewer_keywords:
- -FU compiler option [C++]
- FU compiler option [C++]
- /FU compiler option [C++]
ms.assetid: 698f8603-457f-435a-baff-5ac9243d6ca1
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 17b62859aaf0c9dc6b3313fbb726602b5b83a82c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fu-name-forced-using-file"></a>/FU (nome forçado #usando arquivo)
Uma opção de compilador que podem ser usados como uma alternativa para passar um nome de arquivo para [#using diretiva](../../preprocessor/hash-using-directive-cpp.md) no código-fonte.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/FU file  
```  
  
## <a name="arguments"></a>Arguments  
 `file`  
 Especifica o arquivo de metadados para fazer referência a esta compilação.  
  
## <a name="remarks"></a>Comentários  
 O comutador /FU leva apenas um nome de arquivo. Para especificar vários arquivos, use /FU com cada um deles.  
  
 Se você estiver usando [!INCLUDE[cppcli](../../build/reference/includes/cppcli_md.md)] e fazem referência a metadados para usar o [Friend Assemblies](../../dotnet/friend-assemblies-cpp.md) recurso, você não pode usar **/FU**. Você deve referenciar os metadados no código usando `#using`— junto com o `[as friend]` atributo. Assemblies amigáveis não são suportados em [!INCLUDE[cppwrt](../../build/reference/includes/cppwrt_md.md)] ([!INCLUDE[cppwrt_short](../../build/reference/includes/cppwrt_short_md.md)]).  
  
 Para obter informações sobre como criar um assembly ou módulo para o common language runtime (CLR), consulte [/clr (Common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md). Para obter informações sobre como compilar [!INCLUDE[cppwrt_short](../../build/reference/includes/cppwrt_short_md.md)], consulte [compilando aplicativos e bibliotecas](../../cppcx/building-apps-and-libraries-c-cx.md).  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **C/C++** pasta.  
  
3.  Selecione o **avançado** página de propriedades.  
  
4.  Modificar o **forçar #using** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ForcedUsingFiles%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Arquivo de saída (/ F) opções](../../build/reference/output-file-f-options.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)