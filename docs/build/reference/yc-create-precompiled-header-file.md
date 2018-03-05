---
title: "-Yc (criar arquivo de cabeçalho pré-compilado) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCLCompilerTool.UsePrecompiledHeader
- /yc
- VC.Project.VCCLWCECompilerTool.PrecompiledHeaderThrough
- VC.Project.VCCLWCECompilerTool.UsePrecompiledHeader
- VC.Project.VCCLCompilerTool.PrecompiledHeaderThrough
dev_langs:
- C++
helpviewer_keywords:
- precompiled header files, creating
- PCH files, creating
- .pch files, creating
- -Yc compiler option [C++]
- /Yc compiler option [C++]
- Yc compiler option [C++]
ms.assetid: 47c2e555-b4f5-46e6-906e-ab5cf21f0678
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 865b5e0fa7039a0b60f524c2f13a367569757d92
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="yc-create-precompiled-header-file"></a>/Yc (criar arquivo de cabeçalho pré-compilado)
Instrui o compilador a criar um arquivo de cabeçalho pré-compilado (. pch) que representa o estado de compilação em um determinado ponto.  
  
## <a name="syntax"></a>Sintaxe  
  
> __/Yc__
> __/Yc__*nome de arquivo*  
  
  
## <a name="arguments"></a>Arguments  
*filename*  
 Especifica um arquivo de cabeçalho (. h). Quando esse argumento é usado, o compilador compila todo o código até e incluindo o arquivo. h.  
  
## <a name="remarks"></a>Comentários  
 Quando **/Yc** é especificado sem um argumento, o compilador compila todo o código até o fim do arquivo de origem de base, ou para o ponto no arquivo de base onde um [hdrstop](../../preprocessor/hdrstop.md) diretiva ocorre. O arquivo. pch resultante tem o mesmo nome de base como o arquivo de origem de base, a menos que você especifique um nome de arquivo diferente usando o **hdrstop** pragma ou **/Fp** opção.  
  
 O código pré-compilado é salvo em um arquivo com um nome criado a partir do nome base do arquivo especificado com o **/Yc** opção e uma extensão. pch. Você também pode usar o [/Fp (nome. O arquivo pch)](../../build/reference/fp-name-dot-pch-file.md) opção para especificar um nome para o arquivo de cabeçalho pré-compilado.  
  
 Se você usar __/Yc__*filename*, o compilador compila todo o código até e incluindo o arquivo especificado para uso posterior com o [/Yu (usar a arquivo de cabeçalho pré-compilado)](../../build/reference/yu-use-precompiled-header-file.md) opção.  
  
 Se as opções de __/Yc__*filename* e __/Yu__*filename* ocorrer na mesma linha de comando e ambos referenciam ou implicam, o mesmo nome de arquivo, __/Yc__*filename* terá precedência. Esse recurso simplifica a gravação de makefiles.  
  
 Para obter mais informações sobre cabeçalhos pré-compilados, consulte:  
  
-   [/Y (cabeçalhos pré-compilados)](../../build/reference/y-precompiled-headers.md)  
  
-   [Criando arquivos de cabeçalho pré-compilado](../../build/reference/creating-precompiled-header-files.md)  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Selecione um arquivo. cpp. O arquivo. cpp deve #include arquivo. h que contém informações de cabeçalho pré-compilado. O projeto **/Yc** configuração pode ser substituída no nível de arquivo.  
  
2.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
3.  Abra o **propriedades de configuração**, **C/C++**, **cabeçalhos pré-compilados** página de propriedades.  
  
4.  Modificar o **cabeçalho pré-compilado** propriedade.  
  
5.  Para definir o nome do arquivo, modifique o **arquivo de cabeçalho pré-compilado** propriedade.
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.PrecompiledHeaderThrough%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.UsePrecompiledHeader%2A>.  
  
## <a name="example"></a>Exemplo  
 Considere o código a seguir:  
  
```cpp  
// prog.cpp
// compile with: cl /c /Ycmyapp.h prog.cpp
#include <afxwin.h>   // Include header for class library  
#include "resource.h" // Include resource definitions  
#include "myapp.h"    // Include information specific to this app  
// ...  
```  
  
Quando esse código é compilado com o comando `CL /YcMYAPP.H PROG.CPP`, o compilador salva todos o pré-processamento para AFXWIN.h, RESOURCE.h, e MYAPP.h em um arquivo de cabeçalho pré-compilado chamado MYAPP.pch.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md) [criando arquivos de cabeçalho pré-compilado](../../build/reference/creating-precompiled-header-files.md)